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
import java.awt.image.BufferedImage;
import java.awt.geom.AffineTransform;
import java.nio.ByteBuffer;
import java.util.Iterator;

public class J2DRenderer implements Renderer
{
	private Graphics2D g;
	private boolean clipping;
	private Matrix3D xForm;
	private AxesObject.Scaler sx, sy, sz;
	private J2DRenderCanvas canvas;
	private float lineWidth;
	private float[] linePattern;
	private Rectangle clipRect;

	public J2DRenderer(J2DRenderCanvas c)
	{
		g = null;
		clipping = false;
		canvas = c;
		lineWidth = 0.0f;
		linePattern = null;
	}

	void setGraphics(Graphics g)
	{
		this.g = (Graphics2D)g;
		if (g != null)
		{
			//this.g.setRenderingHint(RenderingHints.KEY_ANTIALIASING, RenderingHints.VALUE_ANTIALIAS_ON);
			//this.g.setRenderingHint(RenderingHints.KEY_TEXT_ANTIALIASING, RenderingHints.VALUE_TEXT_ANTIALIAS_OFF);
		}
	}

	public void end()
	{
	}

	public void setClipping(boolean flag)
	{
		clipping = flag;
		if (flag && g != null)
			g.setClip(clipRect);
		else
			g.setClip(null);
	}

	public boolean hasClipping()
	{
		return clipping;
	}

	public void setClipBox(double xmin, double xmax, double ymin, double ymax, double zmin, double zmax)
	{
		double[] x = new double[] {xmin, xmin, xmin, xmin, xmax, xmax, xmax, xmax};
		double[] y = new double[] {ymin, ymin, ymax, ymax, ymin, ymin, ymax, ymax};
		double[] z = new double[] {zmin, zmax, zmin, zmax, zmin, zmax, zmin, zmax};
		double[] tx = new double[8];
		double[] ty = new double[8];
		double[] tz = new double[8];
		double _xmin, _xmax, _ymin, _ymax;

		xForm.transform(x, y, z, 8, tx, ty, tz);
		_xmin = _xmax = tx[0];
		_ymin = _ymax = ty[0];
		for (int i=1; i<8; i++)
		{
			if (tx[i] < _xmin) _xmin = tx[i];
			if (tx[i] > _xmax) _xmax = tx[i];
			if (ty[i] < _ymin) _ymin = ty[i];
			if (ty[i] > _ymax) _ymax = ty[i];
		}

		clipRect = new Rectangle((int)Math.round(_xmin)+1, (int)Math.round(_ymin)+1,
				(int)Math.round(_xmax)-(int)Math.round(_xmin)-1, (int)Math.round(_ymax)-(int)Math.round(_ymin)-1);
	}

	public void setCamera(double[] pos, double[] target)
	{
	}

	public void setColor(Color c)
	{
		if (g != null)
			g.setColor(c);
	}
	
	public void setFont(Font f)
	{
		if (g != null)
			g.setFont(f);
	}

	private void updateStroke()
	{
		if (g != null)
			if (linePattern == null)
				g.setStroke(new BasicStroke(lineWidth));
			else
				g.setStroke(new BasicStroke(lineWidth, BasicStroke.CAP_BUTT,
							BasicStroke.JOIN_BEVEL, 1.0f, linePattern, 0.0f));
	}

	public void setLineStyle(String s, boolean forceStippling)
	{
		if (s.equals("-"))
			linePattern = null;
		else if (s.equals(":"))
			linePattern = new float[] {2.0f, 4.0f};
		else if (s.equals("--"))
			linePattern = new float[] {10.0f, 5.0f};
		else if (s.equals("-."))
			linePattern = new float[] {5.0f, 5.0f, 1.0f, 5.0f};
		else
			linePattern = null;
		updateStroke();
	}

	public void setLineWidth(float w)
	{
		lineWidth = w;
		updateStroke();
	}

	public void draw(LineObject line)
	{
		if (g != null)
		{
			double[] x = sx.scale(line.XData.getArray());
			double[] y = sy.scale(line.YData.getArray());
			double[] z = sz.scale(line.ZData.getArray());
			int n = Math.min(Math.min(x.length, y.length), (z.length == 0 ? Integer.MAX_VALUE : z.length));

			double[] tx = new double[n];
			double[] ty = new double[n];
			double[] tz = new double[n];

			if (z.length == 0)
				xForm.transform(x, y, new double[n], n, tx, ty, tz);
			else
				xForm.transform(x, y, z, n, tx, ty, tz);

			int[] xp = new int[n], yp = new int[n];

			for (int i=0; i<n; i++)
			{
				xp[i] = (int)Math.round(tx[i]);
				yp[i] = (int)Math.round(ty[i]);
			}

			if (line.LineStyle.isSet())
			{
				setColor(line.LineColor.getColor());
				setLineStyle(line.LineStyle.getValue(), false);
				setLineWidth(line.LineWidth.floatValue());

				int index = 0;

				for (int i=0; i<n; i++)
				{
					if (!Utils.isNaNorInf(tx[i], ty[i], 0))
					{
						xp[index] = (int)Math.round(tx[i]);
						yp[index] = (int)Math.round(ty[i]);
						index++;
					}
					else if (index > 1)
					{
						g.drawPolyline(xp, yp, index);
						index = 0;
					}
				}

				if (index > 1)
					g.drawPolyline(xp, yp, index);
			}

			if (!line.Marker.is("none"))
			{
				setColor(line.LineColor.getColor());
				setLineStyle(line.LineStyle.getValue(), false);
				setLineWidth(line.LineWidth.floatValue());

				for (int i=0; i<n; i++)
					if (!Utils.isNaNorInf(tx[i], ty[i], 0))
						line.Marker.drawMarker(g,
							(int)Math.round(tx[i]),
							(int)Math.round(ty[i]),
							line.MarkerSize.doubleValue());
			}
		}
	}

	public void draw(LightObject light)
	{
		System.out.println("WARNING: lighting not supported under Java2D renderer");
	}

	public void draw(ByteBuffer data, int w, int h, double[] pos, int xOffset, int yOffset,
		boolean useClipping, boolean useZBuffer)
	{
	}

	public void drawBitmap(BufferedImage img, double[] pos, int xOffset, int yOffset)
	{
	}

	public void draw(PatchObject patch)
	{
	}

	public void draw(SurfaceObject surf)
	{
	}

	public void draw(ImageObject image)
	{
	}

	public void draw(TextObject text)
	{
		if (g != null)
		{
			AxesObject ax = text.getAxes();
			double[] pos = ax.convertUnits(text.Position.getArray(), text.Units.getValue());
			double[] tpos = new double[4];
			AffineTransform af = g.getTransform();
			Rectangle r = text.getExtent();

			xForm.transform(pos[0], pos[1], pos[2], tpos, 0);
			g.translate((int)Math.round(tpos[0]), (int)Math.round(tpos[1]));
			g.rotate(-text.Rotation.doubleValue()*Math.PI/180.0);
			g.setFont(Utils.getFont(text.FontName, text.FontSize, text.FontUnits,
					text.FontAngle, text.FontWeight, canvas.getHeight()));
			setColor(text.TextColor.getColor());

			int xoff = 0, yoff = 0;

			if (text.HAlign.is("right"))
				xoff = -r.width;
			else if (text.HAlign.is("center"))
				xoff = -r.width/2;
			if (text.VAlign.is("bottom"))
				yoff = -r.height;
			else if (text.VAlign.is("middle"))
				yoff = -r.height/2;
			else if (text.VAlign.is("baseline"))
				yoff = -(r.height+r.y);
			g.translate(xoff, yoff);

			text.render(g);
			g.setTransform(af);
		}
	}

	public Rectangle drawText(String txt, double[] pos, int halign, int valign)
	{
		if (g != null)
		{
			SimpleTextEngine.Content content = new SimpleTextEngine.Content(txt);
			Rectangle r = (Rectangle)content.layout(canvas, canvas.getFont()).clone();
			double[] tpos = new double[4];

			if (r.width > 0 && r.height > 0)
			{
				int xoff = 0, yoff = 0;

				switch (halign)
				{
					case 1: xoff = -r.width/2; break;
					case 2: xoff = -r.width; break;
				}
				switch (valign)
				{
					case 1: yoff = -r.height/2; break;
					case 0: yoff = -r.height; break;
				}

				xForm.transform(pos[0], pos[1], pos[2], tpos, 0);
				xoff = (int)Math.round(tpos[0])+xoff;
				yoff = (int)Math.round(tpos[1])+yoff;
				g.translate(xoff, yoff);
				content.render(g);
				g.translate(-xoff, -yoff);

				return r;
			}
		}

		return new Rectangle();
	}

	public void setXForm(AxesObject ax)
	{
		xForm = ax.x_render;
		sx = ax.sx;
		sy = ax.sy;
		sz = ax.sz;

		if (g != null)
		{
			boolean use_antialias = ax.getFigure().__Antialias__.isSet();
			if (use_antialias)
			{
				g.setRenderingHint(RenderingHints.KEY_ANTIALIASING, RenderingHints.VALUE_ANTIALIAS_ON);
				g.setRenderingHint(RenderingHints.KEY_TEXT_ANTIALIASING, RenderingHints.VALUE_TEXT_ANTIALIAS_OFF);
			}
			else
			{
				g.setRenderingHint(RenderingHints.KEY_ANTIALIASING, RenderingHints.VALUE_ANTIALIAS_OFF);
			}
		}
	}

	public void setViewport(int width, int height)
	{
	}

	public void clear(Color c)
	{
		if (g != null)
			g.clearRect(0, 0, canvas.getWidth(), canvas.getHeight());
	}

	public void drawRubberBox(int[][] b)
	{
		Graphics GC;

		if (g != null)
			GC = g;
		else
			GC = canvas.getGraphics();
		GC.setColor(Color.lightGray);
		GC.setXORMode(Color.white);
		for (int i=0; i<b.length; i++)
		{
			int x = Math.min(b[i][0], b[i][2]), y = Math.min(b[i][1], b[i][3]);
			int w = Math.abs(b[i][2]-b[i][0]), h = Math.abs(b[i][3]-b[i][1]);
			GC.drawRect(x, y, w, h);
		}
		GC.setPaintMode();

		if (g == null)
			GC.dispose();
	}
	
	/*
	private void transformPoints(java.util.List pts, int[] x, int[] y)
	{
		Iterator it = pts.iterator();
		double[] tmp = new double[4];
		int idx = 0;

		while (it.hasNext())
		{
			Point3D pt = (Point3D)it.next();
			xForm.transform(pt.x, pt.y, pt.z, tmp, 0);
			x[idx] = (int)Math.round(tmp[0]);
			y[idx] = (int)Math.round(tmp[1]);
			idx++;
		}
	}
	*/

	public void drawSegments(java.util.List pts)
	{
		if (g != null)
		{
			Iterator it = pts.iterator();
			int count = 0, x1 = 0, y1 = 0;
			double[] tmp = new double[4];

			while (it.hasNext())
			{
				Point3D pt = (Point3D)it.next();
				xForm.transform(pt.x, pt.y, pt.z, tmp, 0);
				if (count == 0)
				{
					count = 1;
					x1 = (int)Math.round(tmp[0]);
					y1 = (int)Math.round(tmp[1]);
				}
				else
				{
					count = 0;
					g.drawLine(x1, y1, (int)Math.round(tmp[0]), (int)Math.round(tmp[1]));
				}
			}
		}
	}

	public void drawQuads(java.util.List pts, double zoffset)
	{
		if (g != null)
		{
			Iterator it = pts.iterator();
			int count = 0;
			int[] x = new int[4], y = new int[4];
			double[] tmp = new double[4];

			while (it.hasNext())
			{
				Point3D pt = (Point3D)it.next();
				xForm.transform(pt.x, pt.y, pt.z, tmp, 0);
				x[count] = (int)Math.round(tmp[0]);
				y[count] = (int)Math.round(tmp[1]);
				if (++count == 4)
				{
					count = 0;
					g.fillPolygon(x, y, 4);
				}
			}
		}
	}
}
