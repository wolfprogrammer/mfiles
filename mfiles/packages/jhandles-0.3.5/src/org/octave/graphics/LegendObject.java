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

import java.util.*;
import java.awt.*;

public class LegendObject extends AxesObject
{
	private class LegendItem
	{
		String name;
		TextObject text;
		LineObject line;
		LineObject marker;
		PatchObject patch;
	}

	private LegendItem makeItemFromLine(HandleObject line, String name)
	{
		LegendItem item = new LegendItem();
		item.name = name;

		try
		{
			item.text = new TextObject(this, name, new double[] {0, 0, 0});
			item.text.VAlign.reset("middle");
			item.text.TextColor.reset(TextColor.get());
			item.text.FontName.reset(this.get("FontName"));
			item.text.FontSize.reset(this.get("FontSize"));
			item.text.FontUnits.reset(this.get("FontUnits"));
			item.text.FontWeight.reset(this.get("FontWeight"));
			item.text.FontAngle.reset(this.get("FontAngle"));
			item.text.validate();

			item.line = new LineObject(this);
			item.line.LineColor.reset(line.get("Color"));
			item.line.LineStyle.reset(line.get("LineStyle"));
			item.line.LineWidth.reset(line.get("LineWidth"));
			item.line.validate();

			item.marker = new LineObject(this);
			item.marker.LineColor.reset(line.get("Color"));
			item.marker.LineStyle.reset("none");
			item.marker.Marker.reset(line.get("Marker"));
			item.marker.MarkerEdgeColor.reset(line.get("MarkerEdgeColor"));
			item.marker.MarkerFaceColor.reset(line.get("MarkerFaceColor"));
			item.marker.validate();
		}
		catch (PropertyException e) {}

		return item;
	}

	private LegendItem[] items;
	private AxesObject axes;
	private Dimension size;

	/* Properties */
	RadioProperty Location;
	ColorProperty EdgeColor;
	ColorProperty TextColor;
	StringArrayProperty String;
	RadioProperty Orientation;

	public LegendObject(AxesObject axes, String[] names)
	{
		super(axes.Parent.elementAt(0), false);
		alwaysDrawBox = false;

		Location = new RadioProperty(this, "Location",
			new String[] {
				"North", "South", "East", "West",
				"NorthEast", "NorthWest", "SouthEast", "SouthWest",
				"NorthOutside", "SouthOutside", "EastOutside", "WestOutside",
				"NorthEastOutside", "NorthWestOutside", "SouthEastOutside", "SouthWestOutside",
				 "Best", "BestOutside", "none"},
			"NorthEast");
		EdgeColor = new ColorProperty(this, "EdgeColor", new String[] {"none"}, Color.black);
		TextColor = new ColorProperty(this, "TextColor", new String[] {"none"}, Color.black);
		String = new StringArrayProperty(this, "String", new String[0]);
		Orientation = new RadioProperty(this, "Orientation", new String[] {"vertical", "horizontal"}, "vertical");

		ActivePositionProperty.reset("position");
		XLimMode.reset("manual");
		YLimMode.reset("manual");
		ZLimMode.reset("manual");
		XLim.reset(new double[] {0, 1});
		YLim.reset(new double[] {0, 1});
		ZLim.reset(new double[] {-0.5, 0.5});
		XTickMode.reset("manual");
		YTickMode.reset("manual");
		ZTickMode.reset("manual");
		XTick.reset(null);
		YTick.reset(null);
		ZTick.reset(null);
		XTickLabelMode.reset("manual");
		YTickLabelMode.reset("manual");
		ZTickLabelMode.reset("manual");
		XTickLabel.reset(null);
		YTickLabel.reset(null);
		ZTickLabel.reset(null);
		XColor.reset(EdgeColor.get());
		YColor.reset(EdgeColor.get());
		ZColor.reset(EdgeColor.get());
		Tag.reset("legend");
		FontName.reset(axes.FontName.toString());
		FontSize.reset(new Double(axes.FontSize.doubleValue()));
		FontUnits.reset(axes.FontUnits.getValue());
		FontWeight.reset(axes.FontWeight.getValue());
		FontAngle.reset(axes.FontAngle.getValue());

		listen(axes.Position);
		listen(axes.OuterPosition);
		listen(Location);
		listen(Orientation);
		listen(EdgeColor);
		listen(TextColor);
		listen(String);
		
		buildLegend(axes, names);
	}

	public void buildLegend(AxesObject axes, String[] names)
	{
		doClear();
		this.axes = axes;

		LinkedList tmp = new LinkedList();
		Iterator it = axes.Children.iterator();
		int index = 0;

		while (it.hasNext())
		{
			HandleObject obj = (HandleObject)it.next();

			if (!obj.isLegendable())
				continue;

			if (index < names.length)
				tmp.add(makeItemFromLine(obj, names[index++]));
			else
			{
				index++;
				tmp.add(makeItemFromLine(obj, "data"+index));
			}
		}

		if (index < names.length)
			System.out.println("WARNING: ignoring extra legend entries");

		items = (LegendItem[])tmp.toArray(new LegendItem[tmp.size()]);
		doLayout();
		doLocate();
		
		String[] used_names = new String[items.length];
		for (int i=0; i<items.length; i++)
			used_names[i] = items[i].name;
		String.reset(used_names);
	}

	public int size()
	{
		return (items != null ? items.length : 0);
	}

	private void doClear()
	{
		while (Children.size() > 0)
			Children.elementAt(0).delete();
	}

	private void doLayout()
	{
		RenderCanvas canvas = getCanvas();
		FontMetrics fm = canvas.getFontMetrics(canvas.getFont());
		int lineWidth = 30, margin = 5;
		int maxWidth = 0, maxHeight = fm.getHeight()+margin;

		int totalWidth = 0, totalHeight = 0;

		if (Orientation.is("vertical"))
		{
			for (int i=0; i<items.length; i++)
			{
				Rectangle r = items[i].text.getExtent();
				maxWidth = Math.max(r.width, maxWidth);
				maxHeight = Math.max(r.height+margin, maxHeight);
			}

			totalWidth = (maxWidth+3*margin+lineWidth);
			totalHeight = items.length*maxHeight;

			double xt = 1-((double)(maxWidth+margin))/totalWidth;
			double x1 = ((double)margin)/totalWidth, x2 = ((double)(margin+lineWidth))/totalWidth;

			for (int i=0; i<items.length; i++)
			{
				double ypos = 1-(i+0.5)/items.length;
				if (items[i].patch != null)
				{
				}
				else
				{
					items[i].text.Position.reset(new double[] {xt, ypos, 0});
					items[i].line.XData.reset(new double[] {x1, x2});
					items[i].line.YData.reset(new double[] {ypos, ypos});
					items[i].marker.XData.reset(new double[] {(x1+x2)/2});
					items[i].marker.YData.reset(new double[] {ypos});
				}
			}
		}
		else
		{
			int[] w = new int[items.length];

			for (int i=0; i<items.length; i++)
			{
				Rectangle r = items[i].text.getExtent();
				w[i] = totalWidth;
				totalWidth += (r.width+lineWidth+3*margin);
				totalHeight = Math.max(r.height+margin, totalHeight);
			}

			double y = 0.5;
			double x1 = ((double)margin)/totalWidth, x2 = ((double)(margin+lineWidth))/totalWidth;
			double xt = ((double)(2*margin+lineWidth))/totalWidth;
			
			for (int i=0; i<items.length; i++)
			{
				double xpos = ((double)w[i])/totalWidth;
				if (items[i].patch != null)
				{
				}
				else
				{
					items[i].text.Position.reset(new double[] {xpos+xt, y, 0});
					items[i].line.XData.reset(new double[] {xpos+x1, xpos+x2});
					items[i].line.YData.reset(new double[] {y, y});
					items[i].marker.XData.reset(new double[] {xpos+(x1+x2)/2});
					items[i].marker.YData.reset(new double[] {y});
				}
			}
		}

		Position.set(new double[] {0, 0, ((double)totalWidth)/canvas.getWidth(), ((double)totalHeight)/canvas.getHeight()}, true);
		size = new Dimension(totalWidth, totalHeight);
	}

	private void doLocate()
	{
		if (Location.is("none"))
			return;

		RenderCanvas canvas = getCanvas();
		double[] aPos = Utils.convertPosition(axes.Position.getArray(), axes.Units.getValue(), "pixels", canvas.getComponent());
		double[] aOPos = Utils.convertPosition(axes.OuterPosition.getArray(), axes.Units.getValue(), "pixels", canvas.getComponent());
		double[] pos = Utils.convertPosition(Position.getArray(), Units.getValue(), "pixels", canvas.getComponent());
		boolean outerActive = axes.ActivePositionProperty.is("outerposition");
		int margin = 10;

		String loc = Location.getValue().toLowerCase();
		int hPos = (loc.contains("west") ? 0 : loc.contains("east") ? 2 : 1);
		int vPos = (loc.contains("south") ? 0 : loc.contains("north") ? 2 : 1);
		boolean outside = loc.contains("outside");

		if (!outside)
		{
			switch (vPos)
			{
				case 0: /* south */
					pos[1] = aPos[1]+margin;
					break;
				case 1: /* middle */
					pos[1] = aPos[1]+(aPos[3]-pos[3])/2;
					break;
				case 2: /* north */
					pos[1] = aPos[1]+aPos[3]-margin-pos[3];
					break;
			}
			switch (hPos)
			{
				case 0: /* west */
					pos[0] = aPos[0]+margin;
					break;
				case 1: /* center */
					pos[0] = aPos[0]+(aPos[2]-pos[2])/2;
					break;
				case 2: /* east */
					pos[0] = aPos[0]+aPos[2]-margin-pos[2];
					break;
			}
		}
		else
		{
			switch (hPos)
			{
				case 0: /* west */
					if (outerActive)
					{
						double offset = margin+pos[2];
						aPos[0] += offset;
						aPos[2] -= offset;
					}
					pos[0] = aPos[0]-margin-pos[2];
					break;
				case 1: /* center */
					pos[0] = aPos[0]+(aPos[2]-pos[2])/2;
					break;
				case 2: /* east */
					if (outerActive)
						aPos[2] -= (margin+pos[2]);
					pos[0] = aPos[0]+aPos[2]+margin;
					break;
			}
			switch (vPos)
			{
				case 0: /* south */
					if (hPos == 1)
					{
						if (outerActive)
						{
							double offset = margin+pos[3];
							aPos[1] += offset;
							aPos[3] -= offset;
						}
						pos[1] = aPos[1]-margin-pos[3];
					}
					else
						pos[1] = aPos[1];
					break;
				case 1: /* middle */
					pos[1] = aPos[1]+(aPos[3]-pos[3])/2;
					break;
				case 2: /* north */
					if (hPos == 1)
					{
						if (outerActive)
							aPos[3] -= (margin+pos[3]);
						pos[1] = aPos[1]+aPos[3]+margin;
					}
					else
						pos[1] = aPos[1]+aPos[3]-pos[3];
					break;
			}
		}

		Position.set(Utils.convertPosition(pos, "pixels", Units.getValue(), canvas.getComponent()), true);
		autoMode++;
		axes.setInternalPosition(Utils.convertPosition(aPos, "pixels", axes.Units.getValue(), canvas.getComponent()));
		autoMode--;
	}

	void updateActivePosition()
	{
		RenderCanvas canvas = getCanvas();
		double[] pos = Utils.convertPosition(Position.getArray(), Units.getValue(), "pixels", canvas.getComponent());
		pos[2] = size.width;
		pos[3] = size.height;
		Position.set(Utils.convertPosition(pos, "pixels", Units.getValue(), canvas.getComponent()), true);
		doLocate();
	}

	public void propertyChanged(Property p) throws PropertyException
	{
		super.propertyChanged(p);

		if (p == EdgeColor)
		{
			Object c = EdgeColor.get();
			XColor.set(c);
			YColor.set(c);
			ZColor.set(c);
		}
		else if (p == TextColor)
		{
			for (int i=0; i<items.length; i++)
				items[i].text.set("Color", TextColor.get());
		}
		else if (p == String)
		{
			String[] s = String.getArray();
			for (int i=0; i<items.length; i++)
				if (i < s.length)
					items[i].text.set("String", s[i]);
				else
					items[i].text.set("String", "");
			doLayout();
			doLocate();

			String[] used_names = new String[Math.min(s.length, items.length)];
			System.arraycopy(s, 0, used_names, 0, used_names.length);
			String.set(used_names);
		}
		else if (!isAutoMode() && (p == axes.Position || p == axes.OuterPosition))
			doLocate();
		else if (p == Location)
		{
			autoMode++;
			axes.updateActivePosition();
			autoMode--;
			doLocate();
		}
		else if (p == Orientation)
		{
			doLayout();
			doLocate();
		}
	}
}
