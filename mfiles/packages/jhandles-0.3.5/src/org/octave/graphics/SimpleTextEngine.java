/*
 * jhandles 
 *
 * Copyright (C) 2007 Michael Goffioul 
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; If not, see <http://www.gnu.org/licenses/>. 
 *
 */

package org.octave.graphics;

import java.awt.*;
import java.awt.image.*;
import java.util.*;

class SimpleTextEngine
{
	static class SimpleFactory
	{
		private String buffer;
		private LinkedList list;
		private int anchor = 0, current = 0;
		private StringBuilder builder;

		SimpleFactory(String txt, LinkedList lst)
		{
			buffer = txt;
			list = lst;
			builder = new StringBuilder();
		}

		int matchBrace(int start)
		{
			int depth = 0;
			while (start < buffer.length())
			{
				switch (buffer.charAt(start))
				{
				case '{': depth++; break;
				case '}': depth--; if (depth == 0) return start; break;
				default: break;
				}
				start++;
			}
			return -1;
		}

		String getArgument(int start)
		{
			if (start >= buffer.length())
				return null;
			if (buffer.charAt(start) == '{')
			{
				int pos = matchBrace(start);
				if (pos < 0)
					return null;
				else
				{
					anchor = pos+1;
					return buffer.substring(start+1, pos);
				}
			}
			else
			{
				anchor = start+1;
				return buffer.substring(start, start+1);
			}
		}

		String getParameter(int start, char startChar, char endChar)
		{
			if (start >= buffer.length() || buffer.charAt(start) != startChar)
				return null;

			int pos = buffer.indexOf(endChar, start);
			if (pos == -1)
				return null;
			else
			{
				anchor = pos+1;
				return buffer.substring(start+1, pos);
			}
		}

		String getTeXCommand(int start)
		{
			int end = start;
			while (end < buffer.length())
			{
				char c = buffer.charAt(end);
				if (!Character.isLetterOrDigit(c))
					break;
				end++;
			}
			anchor = end;
			return buffer.substring(start, end);
		}

		void flush()
		{
			if (/*current > anchor &&*/ builder.length() > 0)
			{
				list.add(new Element(builder.toString()));
				anchor = current;
				builder.setLength(0);
			}
		}

		void parse()
		{
			String arg;

			current = anchor;
			while (current < buffer.length())
			{
				switch (buffer.charAt(current))
				{
				case '^':
				case '_':
					flush();
					arg = getArgument(current+1);
					if (arg != null)
					{
						if (buffer.charAt(current) == '_')
							list.add(new SubscriptElement(arg));
						else if (buffer.charAt(current) == '^')
							list.add(new SuperscriptElement(arg));
						current = anchor;

						if (list.size() > 1)
						{
							Element e1 = (Element)list.get(list.size()-2);
							Element e2 = (Element)list.get(list.size()-1);
							if ((e1 instanceof SubscriptElement && e2 instanceof SuperscriptElement) ||
							    (e2 instanceof SubscriptElement && e1 instanceof SuperscriptElement))
							{
								list.remove(list.size()-2);
								list.remove(list.size()-1);
								list.add(new ScriptElement(e1, e2));
							}
						}
					}
					else
						current++;
					break;
				case '{':
					flush();
					arg = getArgument(current);
					if (arg != null)
						list.add(new LineElement(arg, false));
					else
						System.err.println("WARNING: unmatched brace '{'");
					current = anchor;
					break;
				case '\\':
					if (current+1 < buffer.length())
						switch (buffer.charAt(current+1))
						{
							case '\\':
							case '{':
							case '}':
							case '_':
							case '^':
								builder.append(buffer.charAt(current+1));
								current = anchor = current+2;
								break;
							default:
								flush();
								arg = getTeXCommand(current+1);
								if (arg != null && arg.length() > 0)
								{
									if (TeXElement.isSymbol(arg))
										list.add(new TeXElement(arg));
									else if (arg.startsWith("it") || arg.startsWith("sl"))
									{
										list.add(new TeXFontSwitchCommand(Font.ITALIC));
										anchor = current+3;
									}
									else if (arg.startsWith("bf"))
									{
										list.add(new TeXFontSwitchCommand(Font.BOLD));
										anchor = current+3;
									}
									else if (arg.startsWith("rm"))
									{
										list.add(new TeXFontSwitchCommand(Font.PLAIN));
										anchor = current+3;
									}
									else if (arg.equals("color"))
									{
										String mode = getParameter(anchor, '[', ']');
										String color = getParameter(anchor, '{', '}');
										list.add(new TeXFontColorCommand(mode, color));
									}
									else if (arg.equals("fontsize"))
									{
										String sz = getParameter(anchor, '{', '}');
										list.add(new TeXFontSizeCommand(sz));
									}
									else if (arg.equals("fontname"))
									{
										String name = getParameter(anchor, '{', '}');
										list.add(new TeXFontNameCommand(name));
									}
								}
								else
									System.err.println("WARNING: unable to interpret TeX command: " + buffer.substring(current));
								current = anchor;
								break;
						}
					else
						System.err.println("WARNING: unable to interpret TeX command: " + buffer.substring(current));
					break;
				default:
					builder.append(buffer.charAt(current++));
					break;
				}
			}

			flush();
		}

	}

	interface TextRenderer
	{
		void render(Element e);
		void render(LineElement e);
		void render(SubscriptElement e);
		void render(SuperscriptElement e);
		void render(ScriptElement e);
		void render(TeXElement e);
		void render(TeXFontCommand e);
		void render(Content e);
	}

	static class PSTextRenderer implements TextRenderer
	{
		private StringBuffer buf;
		private LinkedList stateList;
		private float f;

		private class PSState
		{
			String fontName;
			float fontSize;
			int fontStyle;
			Color fontColor;
			float yOffset;

			PSState(String fontName, float fontSize, int fontStyle, Color fontColor, float yOffset)
			{
				this.fontName = fontName;
				this.fontSize = fontSize;
				this.fontStyle = fontStyle;
				this.fontColor = fontColor;
				this.yOffset = yOffset;
			}
		}

		PSTextRenderer(StringBuffer buffer, String fname, float fsize, int fstyle, Color fcolor)
		{
			buf = buffer;
			stateList = new LinkedList();
			f = 72.0f / Utils.getScreenResolution();
			pushState(fname, fsize, fstyle, fcolor, 0);
		}

		private PSState currentState()
		{
			return (PSState)stateList.get(0);
		}

		private void pushState(String fontName, float fontSize, int fontStyle, Color fontColor, float yOffset)
		{
			stateList.add(0, new PSState(fontName, fontSize, fontStyle, fontColor, yOffset));
		}

		private void pushState()
		{
			PSState st = currentState();
			pushState(st.fontName, st.fontSize, st.fontStyle, st.fontColor, st.yOffset);
		}

		private void popState()
		{
			stateList.remove(0);
		}

		private String fontModifier(int style)
		{
			if ((style & Font.ITALIC) != 0 && (style & Font.BOLD) != 0)
				return "-BoldOblique";
			else if ((style & Font.ITALIC) != 0)
				return "-Oblique";
			else if ((style & Font.BOLD) != 0)
				return "-Bold";
			else return "";
		}

		private String quote(String s)
		{
			return s.replaceAll("([()])", "\\\\$1");
		}

		private float round(float d)
		{
			return Math.round(d*100)/100.0f;
		}

		private String colorCmd(Color c)
		{
			float[] cv = c.getRGBColorComponents(null);
			return (cv[0] + " " + cv[1] + " " + cv[2] + " C");
		}

		public void render(Content e)
		{
			buf.append(colorCmd(currentState().fontColor) + "\n");
			for (int i=0; i<e.lines.length; i++)
			{
				if (i > 0)
					buf.append("0 " + round(f*(e.lines[i-1].rect.y-(e.lines[i].rect.height+e.lines[i].rect.y))) + " rmoveto\n");
				buf.append("[");
				e.lines[i].render(this);
				buf.append("] " + (e.align == 0 ? "LLshow" : (e.align == 1 ? "LCshow" : "LRshow")) + "\n");
			}
		}

		public void render(LineElement e)
		{
			Iterator it = e.iterator();
			Color c = currentState().fontColor;

			pushState();
			while (it.hasNext())
			{
				Element elem = (Element)it.next();
				elem.render(this);
			}
			if (!currentState().fontColor.equals(c))
				buf.append("{" + colorCmd(c) + "}\n");
			popState();
		}

		public void render(Element e)
		{
			PSState st = currentState();
			buf.append("[/" + st.fontName + fontModifier(st.fontStyle) + " " + round(st.fontSize) +
					" " + round(st.yOffset) + " (" + quote(e.text) + ")]\n");
		}

		public void render(SubscriptElement e)
		{
			PSState st = currentState();
			pushState(st.fontName, st.fontSize-2, st.fontStyle,
				st.fontColor, st.yOffset-f*(e.rect.height+e.rect.y));
			this.render((LineElement)e);
			popState();
		}

		public void render(SuperscriptElement e)
		{
			PSState st = currentState();
			pushState(st.fontName, st.fontSize-2, st.fontStyle,
				st.fontColor, st.yOffset+st.fontSize/2.0f);
			this.render((LineElement)e);
			popState();
		}

		public void render(ScriptElement e)
		{
			buf.append("{[");
			e.elems[0].render(this);
			e.elems[1].render(this);
			buf.append("] PTshow}\n");
		}

		public void render(TeXElement e)
		{
			int code = TeXElement.getSymbolCode(e.symbol, 1);
			PSState st = currentState();

			if (code > 0)
			{
				String hx = Integer.toHexString(code&0xFF);
				if (hx.length() == 1)
					hx = "0" + hx;
				buf.append("[/Symbol" + fontModifier(st.fontStyle) + " " + round(st.fontSize) +
						" " + round(st.yOffset) + " <" + hx + ">]\n");
			}
		}

		public void render(TeXFontCommand e)
		{
			if (e instanceof TeXFontColorCommand)
			{
				Color c = ((TeXFontColorCommand)e).newColor;
				buf.append("{" + colorCmd(c) + "}\n");
				currentState().fontColor = c;
			}
			else if (e instanceof TeXFontSwitchCommand)
				currentState().fontStyle = ((TeXFontSwitchCommand)e).newStyle;
			else if (e instanceof TeXFontSizeCommand)
				currentState().fontSize = ((TeXFontSizeCommand)e).newSize;
			else if (e instanceof TeXFontNameCommand)
				currentState().fontName = ((TeXFontNameCommand)e).newName;
		}
	}

	static class Layouter
	{
		public RenderCanvas canvas;
		public Font font;

		Layouter(RenderCanvas canvas, Font font)
		{
			this.canvas = canvas;
			this.font = font;
		}

		FontMetrics getFontMetrics(Font f)
		{
			return canvas.getFontMetrics(f);
		}

		FontMetrics getFontMetrics()
		{
			return getFontMetrics(font);
		}
	}

	static class Element
	{
		String text;
		Rectangle rect;
		
		Element(String txt)
		{
			text = txt;
			rect = new Rectangle();
		}

		void render(Graphics2D g)
		{
			g.drawString(text, 0, 0);
		}

		Rectangle layout(RenderCanvas comp, Font font)
		{
			return layout(new Layouter(comp, font));
		}

		Rectangle layout(Layouter l)
		{
			FontMetrics fm = l.getFontMetrics();
			rect = new Rectangle(0, -fm.getMaxDescent(), fm.stringWidth(text), fm.getMaxDescent()+fm.getMaxAscent());
			return rect;
		}

		void render(TextRenderer r) { r.render(this); }
	}

	static class LineElement extends Element
	{
		private LinkedList elements = new LinkedList();
		private boolean toplevel;

		LineElement(String txt)
		{
			this(txt, true);
		}

		LineElement(String txt, boolean toplevel)
		{
			super(txt);
			this.toplevel = toplevel;

			SimpleFactory f = new SimpleFactory(txt, elements);
			f.parse();
		}

		Rectangle layout(Layouter l)
		{
			Iterator it = elements.iterator();
			FontMetrics fm = l.getFontMetrics();
			Font currentFont = l.font;

			rect = new Rectangle(0, -fm.getMaxDescent(), 0, fm.getMaxAscent()+fm.getMaxDescent());
			while (it.hasNext())
			{
				Element e = (Element)it.next();
				Rectangle eRect = e.layout(l);
				eRect.x = rect.width;
				rect = rect.union(eRect);
			}
			l.font = currentFont;
			return rect;
		}

		void render(Graphics2D g)
		{
			Iterator it = elements.iterator();
			int xoffset = 0, yoffset = (toplevel ? (rect.height + rect.y) : 0);
			Font currentFont = g.getFont();
			Color currentColor = g.getColor();

			g.translate(0, yoffset);
			while (it.hasNext())
			{
				Element e = (Element)it.next();
				e.render(g);
				g.translate(e.rect.width, 0);
				xoffset += e.rect.width;
			}
			g.translate(-xoffset, -yoffset);
			g.setColor(currentColor);
			g.setFont(currentFont);
		}

		void add(Element e)
		{
			elements.add(e);
		}

		Iterator iterator()
		{
			return elements.iterator();
		}
		
		void render(TextRenderer r) { r.render(this); }
	}

	static class SubscriptElement extends LineElement
	{
		SubscriptElement(String txt)
		{
			super(txt);
		}

		Font getSubscriptFont(Font f)
		{
			return new Font(f.getFamily(), f.getStyle(), f.getSize()-2);
		}

		Rectangle layout(Layouter l)
		{
			Font currentFont = l.font;

			l.font = getSubscriptFont(currentFont);
			super.layout(l);
			l.font = currentFont;
			rect.y -= (rect.height+rect.y)/2;

			return rect;
		}

		void render(Graphics2D g)
		{
			Font currentFont = g.getFont();
			Font subscriptFont = getSubscriptFont(currentFont);

			g.setFont(subscriptFont);
			super.render(g);
			g.setFont(currentFont);
		}
		
		void render(TextRenderer r) { r.render(this); }
	}

	static class SuperscriptElement extends LineElement
	{
		SuperscriptElement(String txt)
		{
			super(txt);
		}

		Font getSuperscriptFont(Font f)
		{
			return new Font(f.getFamily(), f.getStyle(), f.getSize()-2);
		}

		Rectangle layout(Layouter l)
		{
			Font currentFont = l.font;

			l.font = getSuperscriptFont(currentFont);
			super.layout(l);
			FontMetrics fm = l.getFontMetrics();
			rect.y += fm.getMaxAscent()/2;
			l.font = currentFont;

			return rect;
		}

		void render(Graphics2D g)
		{
			Font currentFont = g.getFont();
			FontMetrics fm = g.getFontMetrics();
			int ascent = fm.getMaxAscent();
			Font subscriptFont = getSuperscriptFont(currentFont);

			g.setFont(subscriptFont);
			g.translate(0, -(rect.height+rect.y)-ascent/2);
			super.render(g);
			g.translate(0, (rect.height+rect.y)+ascent/2);
			g.setFont(currentFont);
		}
		
		void render(TextRenderer r) { r.render(this); }
	}

	static class ScriptElement extends Element
	{
		Element[] elems = new Element[2];

		ScriptElement(Element e1, Element e2)
		{
			super("");
			elems[0] = e1;
			elems[1] = e2;
		}

		Rectangle layout(Layouter l)
		{
			rect = elems[0].layout(l);
			rect = rect.union(elems[1].layout(l));
			return rect;
		}

		void render(Graphics2D g)
		{
			elems[0].render(g);
			elems[1].render(g);
		}
		
		void render(TextRenderer r) { r.render(this); }
	}

	static abstract class TeXFontCommand extends Element
	{
		TeXFontCommand()
		{
			super("");
		}

		Font newFont(Font f) { return f; }
		Color newColor(Color c) { return c; }

		Rectangle layout(Layouter l)
		{
			l.font = newFont(l.font);
			rect = new Rectangle(0, 0, 0, 0);
			return rect;
		}

		void render(Graphics2D g)
		{
			// Font
			Font f = g.getFont();
			g.setFont(newFont(f));
			// Color
			Color c = g.getColor();
			g.setColor(newColor(c));
		}
		
		void render(TextRenderer r) { r.render(this); }
	}

	static class TeXFontSwitchCommand extends TeXFontCommand
	{
		int newStyle;

		TeXFontSwitchCommand(int newStyle)
		{
			this.newStyle = newStyle;
		}

		Font newFont(Font f)
		{
			return new Font(f.getFamily(), newStyle, f.getSize());
		}
	}

	static class TeXFontSizeCommand extends TeXFontCommand
	{
		int newSize;

		TeXFontSizeCommand(String sz)
		{
			try { this.newSize = Integer.parseInt(sz); }
			catch (NumberFormatException e)
			{
				System.err.println("WARNING: invalid font size: " + sz);
				newSize = -1;
			}
		}

		Font newFont(Font f)
		{
			return (newSize == -1 ? f : new Font(f.getFamily(), f.getStyle(), newSize));
		}
	}

	static class TeXFontColorCommand extends TeXFontCommand
	{
		Color newColor = Color.black;

		TeXFontColorCommand(String mode, String color)
		{
			if (color != null)
			{
				if (mode == null || !mode.equals("rgb"))
				{
					if (color.equals("red")) newColor = Color.red;
					else if (color.equals("yellow")) newColor = Color.yellow;
					else if (color.equals("magenta")) newColor = Color.magenta;
					else if (color.equals("black")) newColor = Color.black;
					else if (color.equals("blue")) newColor = Color.blue;
					else if (color.equals("green")) newColor = Color.green;
					else if (color.equals("white")) newColor = Color.white;
					else if (color.equals("cyan")) newColor = Color.cyan;
					else
						System.err.println("WARNING: invalid color name: " + color);
				}
				else
				{
					String[] c = color.trim().split("\\s+");
					if (c.length == 3)
					{
						try
						{
							newColor = new Color(Float.parseFloat(c[0]), Float.parseFloat(c[1]), Float.parseFloat(c[2]));
						}
						catch (NumberFormatException e)
						{
							System.err.println("WARNING: invalid color specification: " + color);
						}
					}
					else
						System.err.println("WARNING: invalid color specification: " + color);
				}
			}
		}

		Color newColor(Color c)
		{
			return newColor;
		}
	}

	static class TeXFontNameCommand extends TeXFontCommand
	{
		String newName;

		TeXFontNameCommand(String name)
		{
			newName = name;
		}

		Font newFont(Font f)
		{
			return new Font(newName, f.getStyle(), f.getSize());
		}
	}

	static class TeXElement extends Element
	{
		private static String[] symbol_names = {
			"alpha",
			"beta",
			"gamma",
			"delta",
			"epsilon",
			"zeta",
			"eta",
			"theta",
			"vartheta",
			"iota",
			"kappa",
			"lambda",
			"mu",
			"nu",
			"xi",
			"pi",
			"rho",
			"sigma",
			"varsigma",
			"tau",
			"equiv",
			"Im",
			"otimes",
			"cap",
			"supset",
			"int",
			"rfloor",
			"lfloor",
			"perp",
			"wedge",
			"rceil",
			"vee",
			"langle",

			"upsilon",
			"phi",
			"chi",
			"psi",
			"omega",
			"Gamma",
			"Delta",
			"Theta",
			"Lambda",
			"Xi",
			"Pi",
			"Sigma",
			"Upsilon",
			"Phi",
			"Psi",
			"Omega",
			"forall",
			"exists",
			"ni",
			"cong",
			"approx",
			"Re",
			"oplus",
			"cup",
			"subseteq",
			"in",
			"lceil",
			"cdot",
			"neg",
			"times",
			"surd",
			"varpi",
			"rangle",

			"leq",
			"infty",
			"clubsuit",
			"diamondsuit",
			"heartsuit",
			"spadesuit",
			"leftrightarrow",
			"leftarrow",
			"uparrow",
			"rightarrow",
			"downarrow",
			"circ",
			"pm",
			"geq",
			"propto",
			"partial",
			"bullet",
			"div",
			"neq",
			"aleph",
			"wp",
			"oslash",
			"supseteq",
			"subset",
			"o",
			"nabla",
			"ldots",
			"prime",
			"0",
			"mid",
			"copyright",

			null
		};
		private static int[][] symbol_codes = {
			{ 0x03B1, 0xF061 },		// alpha
			{ 0x03B2, 0xF062 },		// beta
			{ 0x03B3, 0xF067 },		// gamma
			{ 0x03B4, 0xF064 },		// delta
			{ 0x03B5, 0xF065 },		// epsilon
			{ 0x03B6, 0xF07A },		// zeta
			{ 0x03B7, 0xF068 },		// eta
			{ 0x03B8, 0xF071 },		// theta
			{ 0x03D1, 0xF04A },		// vartheta
			{ 0x03B9, 0xF069 },		// iota
			{ 0x03BA, 0xF06B },		// kappa
			{ 0x03BB, 0xF06C },		// lambda
			{ 0x03BC, 0xF06D },		// mu
			{ 0x03BD, 0xF06E },		// nu
			{ 0x03BE, 0xF078 },		// xi
			{ 0x03C0, 0xF070 },		// pi
			{ 0x03C1, 0xF072 },		// rho
			{ 0x03C3, 0xF073 },		// sigma
			{ 0x03C2, 0xF056 },		// varsigma
			{ 0x03C4, 0xF074 },		// tau
			{ 0x2261, 0xF0BA },		// equiv
			{ 0x2111, 0xF0C1 },		// Im
			{ 0x2297, 0xF0C4 },		// otimes
			{ 0x2229, 0xF0C7 },		// cap
			{ 0x2283, 0xF0C9 },		// supset
			{ 0x222B, 0xF0F2 },		// int
			{ 0x230B, 0xF0FB },		// rfloor
			{ 0x230A, 0xF0EB },		// lfloor
			{ 0x22A5, 0xF05E },		// perp
			{ 0x2227, 0xF0D9 },		// wedge
			{ 0x2309, 0xF0F9 },		// rceil
			{ 0x2228, 0xF0DA },		// vee
			{ 0x2220, 0xF0E1 },		// langle

			{ 0x03C5, 0xF075 },		// upsilon
			{ 0x03C6, 0xF066 },		// phi
			{ 0x03C7, 0xF063 },		// chi
			{ 0x03C8, 0xF079 },		// psi
			{ 0x03C9, 0xF077 },		// omega
			{ 0x0393, 0xF047 },		// Gamma
			{ 0x0394, 0xF044 },		// Delta
			{ 0x0398, 0xF051 },		// Theta
			{ 0x039B, 0xF04C },		// Lambda
			{ 0x039E, 0xF058 },		// Xi
			{ 0x03A0, 0xF050 },		// Pi
			{ 0x03A3, 0xF053 },		// Sigma
			{ 0x03D2, 0xF055 },		// Upsilon
			{ 0x03A6, 0xF046 },		// Phi
			{ 0x03A8, 0xF059 },		// Psi
			{ 0x03A9, 0xF057 },		// Omega
			{ 0x2200, 0xF022 },		// forall
			{ 0x2203, 0xF024 },		// exists
			{ 0x220B, 0xF027 },		// ni
			{ 0x2245, 0xF040 },		// cong
			{ 0x2248, 0xF0BB },		// approx
			{ 0x211C, 0xF0C2 },		// Re
			{ 0x2295, 0xF0C5 },		// oplus
			{ 0x222A, 0xF0C8 },		// cup
			{ 0x2286, 0xF0CD },		// subseteq
			{ 0x2208, 0xF0CE },		// in
			{ 0x2308, 0xF0E9 },		// lceil
			{ 0x22C5, 0xF0D7 },		// cdot
			{ 0x00AC, 0xF0D8 },		// neg
			{ 0x00D7, 0xF0B4 },		// times
			{ 0x221A, 0xF0D6 },		// surd
			{ 0x03D6, 0xF076 },		// varpi
			{ 0x232A, 0xF0F1 },		// rangle

			{ 0x2264, 0xF0A3 },		// leq
			{ 0x221E, 0xF0A5 },		// infty
			{ 0x2663, 0xF0A7 },		// clubsuit
			{ 0x2666, 0xF0A8 },		// diamondsuit
			{ 0x2665, 0xF0A9 },		// heartsuit
			{ 0x2660, 0xF0AA },		// spadesuit
			{ 0x2194, 0xF0AB },		// leftrightarrow
			{ 0x2190, 0xF0AC },		// leftarrow
			{ 0x2191, 0xF0AD },		// uparrow
			{ 0x2192, 0xF0AE },		// rightarrow
			{ 0x2193, 0xF0AF },		// downarrow
			{ 0x25CB, 0xF0B0 },		// circ
			{ 0x00B1, 0xF0B1 },		// pm
			{ 0x2265, 0xF0B3 },		// geq
			{ 0x221D, 0xF0B5 },		// propto
			{ 0x2202, 0xF0B6 },		// partial
			{ 0x2022, 0xF0B7 },		// bullet
			{ 0x00F7, 0xF0B8 },		// div
			{ 0x2260, 0xF0B9 },		// neq
			{ 0x2135, 0xF0C0 },		// aleph
			{ 0x2118, 0xF0C3 },		// wp
			{ 0x2298, 0xF0C6 },		// oslash
			{ 0x2287, 0xF0CA },		// supseteq
			{ 0x2282, 0xF0CC },		// subset
			{ 0x03BF, 0xF0B0 },		// o
			{ 0x2207, 0xF0D1 },		// nabla
			{ 0x2026, 0xF0BC },		// ldots
			{ 0x2032, 0xF0A2 },		// prime
			{ 0x2205, 0xF0C6 },		// 0
			{ 0x2223, 0xF0BD },		// mid
			{ 0x00A9, 0xF0E3 },		// copyright

			{ 0, 0 }
		};
		private static Map symbol_map;
		private static boolean use_symbol_font = System.getProperty("os.name").startsWith("Windows");

		String symbol;

		TeXElement(String txt)
		{
			super(convertString(txt, (use_symbol_font ? 1 : 0)));
			this.symbol = txt;
		}

		Rectangle layout(Layouter l)
		{
			if (use_symbol_font)
			{
				Font currentFont = l.font;
				l.font = getSymbolFont(currentFont);
				super.layout(l);
				l.font = currentFont;
				return rect;
			}
			else
				return super.layout(l);
		}

		void render(Graphics2D g)
		{
			if (use_symbol_font)
			{
				Font currentFont = g.getFont();
				g.setFont(getSymbolFont(currentFont));
				super.render(g);
				g.setFont(currentFont);
			}
			else
				super.render(g);
		}
		
		void render(TextRenderer r) { r.render(this); }

		static Font getSymbolFont(Font f)
		{
			return new Font("Symbol", f.getStyle(), f.getSize());
		}

		static String convertString(String s, int idx)
		{
			int c = getSymbolCode(s, idx);
			if (c >= 0)
				return new String(new int[] {c}, 0, 1);
			return "";
		}

		static String convertString(String s)
		{
			return convertString(s, 0);
		}

		static int getSymbolCode(String s, int idx)
		{
			if (symbol_map == null)
			{
				symbol_map = new HashMap();
				for (int i=0; i<symbol_names.length; i++)
					if (symbol_names[i] != null && symbol_codes[i][0] != 0)
						symbol_map.put(symbol_names[i], symbol_codes[i]);
			}
			int[] c = (int[])symbol_map.get(s);
			if (c != null && idx >= 0 && idx < c.length)
				return c[idx];
			return -1;
		}

		static int getSymbolCode(String s)
		{
			return getSymbolCode(s, 0);
		}

		static boolean isSymbol(String s)
		{
			return (getSymbolCode(s) >= 0);
		}
	}

	static class Content extends Element
	{
		LineElement[] lines;
		int align;

		Content(String txt)
		{
			super(txt);
			String[] txtLines = txt.split("\n", -1);
			lines = new LineElement[txtLines.length];
			for (int i=0; i<txtLines.length; i++)
			{
				lines[i] = new LineElement(txtLines[i]);
			}
		}

		Rectangle layout(Layouter l)
		{
			int w = 0, h = 0;
			Rectangle r;

			for (int i=0; i<lines.length; i++)
			{
				r = lines[i].layout(l);
				if (r.width > w)
					w = r.width;
				h += r.height;
			}
			rect = new Rectangle(0, -(h-lines[0].rect.height-lines[0].rect.y), w, h);
			return rect;
		}

		void render(Graphics2D g)
		{
			int xoffset = 0, yoffset = 0;

			for (int i=0; i<lines.length; i++)
			{
				int dx = rect.width-lines[i].rect.width;
				xoffset = (align == 0 ? 0 : (align == 1 ? dx/2 : dx));
				g.translate(xoffset, 0);
				lines[i].render(g);
				g.translate(-xoffset, lines[i].rect.height);
				yoffset += lines[i].rect.height;
			}
			g.translate(0, -yoffset);
		}
		
		void render(TextRenderer r) { r.render(this); }
	}

	public static Rectangle drawAsImage(RenderCanvas comp, Font f, String txt, double[] pos, int halign, int valign)
	{
		// create internal image
		int margin = 0;
		Content content = new Content(txt);
		Rectangle r = (Rectangle)content.layout(comp, f).clone();

		if (r.width <=0 || r.height <= 0)
			return new Rectangle();

		r.width += 2*margin;
		r.height += 2*margin;
		BufferedImage img = new BufferedImage(r.width, r.height, BufferedImage.TYPE_BYTE_BINARY);

		// draw string
		Graphics g = img.getGraphics();
		g.setFont(f);
		g.translate(margin, margin);
		content.render((Graphics2D)g);
		g.dispose();
		com.sun.opengl.util.ImageUtil.flipImageVertically(img);

		// compute offsets
		int xoff, yoff;
		switch (halign)
		{
		default:
		case 0: xoff = 0; break;
		case 1: xoff = -r.width/2; break;
		case 2: xoff = -r.width; break;
		}
		switch (valign)
		{
		default:
		case 0: yoff = 0; break;
		case 1: yoff = -r.height/2; break;
		case 2: yoff = -r.height; break;
		}

		// render to canvas
		comp.getRenderer().drawBitmap(img, pos, xoff, yoff);

		// return value
		return r;
	}
}
