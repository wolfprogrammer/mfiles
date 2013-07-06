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
import org.octave.Matrix;

public class ColorbarObject extends AxesObject
{
	private AxesObject axes;
	private Dimension size;
	private boolean vertical;

	/* Properties */
	RadioProperty Location;

	public ColorbarObject(AxesObject axes)
	{
		super(axes.getFigure(), false);
		alwaysDrawBox = false;

		Location = new RadioProperty(this, "Location",
			new String[] {
				"North", "South", "East", "West",
				"NorthOutside", "SouthOutside", "EastOutside", "WestOutside"},
			"EastOutside");

		ActivePositionProperty.reset("position");
		XLimMode.reset("manual");
		YLimMode.reset("manual");
		ZLimMode.reset("manual");
		XLim.reset(new double[] {0, 1});
		YLim.reset(new double[] {0, 1});
		ZLim.reset(new double[] {-0.5, 0.5});
		//XTickMode.reset("manual");
		//YTickMode.reset("manual");
		ZTickMode.reset("manual");
		//XTick.reset(null);
		//YTick.reset(null);
		ZTick.reset(null);
		XTickLabelMode.reset("manual");
		YTickLabelMode.reset("manual");
		ZTickLabelMode.reset("manual");
		XTickLabel.reset(null);
		YTickLabel.reset(null);
		ZTickLabel.reset(null);
		Tag.reset("colorbar");
		Layer.reset("top");

		listen(axes.Position);
		listen(axes.OuterPosition);
		listen(axes.CLim);
		listen(getFigure().Colormap);
		listen(Location);
		
		buildColorbar(axes);
	}

	public void delete()
	{
		super.delete();
		axes.removeChild(this);
	}

	public void buildColorbar(AxesObject axes)
	{
		doClear();
		this.axes = axes;

		RenderCanvas canvas = getCanvas();
		double[] clim = axes.CLim.getArray();
		String loc = Location.getValue().toLowerCase();
		
		vertical = (loc.contains("west") || loc.contains("east"));

		int nc = axes.getFigure().Colormap.getDim(0);
		double[] cdata = new double[nc];
		for (int i=0; i<nc; i++)
			cdata[i] = i+1;

		ImageObject img = new ImageObject(this);
		double px = (clim[1]-clim[0])/nc;
		double low = clim[0]+px/2, high = clim[1]-px/2;

		if (vertical)
		{
			img.CData.set(new Matrix(cdata, new int[] {nc, 1}), true);
			img.XData.set(new double[] {1, 1}, true);
			img.YData.set(new double[] {low, high}, true);
			YAxisLocation.set(loc.contains("west") ? "left" : "right", true);
			XLim.reset(new double[] {0.5, 1.5});
			YLim.reset(clim);
			XTick.reset(null);
			XTickMode.reset("manual");
			XTickLabel.reset(null);
			XTickLabelMode.reset("manual");
			YTickMode.reset("auto");
			YTickLabelMode.reset("auto");
		}
		else
		{
			img.CData.set(new Matrix(cdata, new int[] {1, nc}), true);
			img.XData.set(new double[] {low, high}, true);
			img.YData.set(new double[] {1, 1}, true);
			XAxisLocation.set(loc.contains("south") ? "bottom" : "top", true);
			XLim.set(clim, true);
			YLim.set(new double[] {0.5, 1.5}, true);
			XTickMode.reset("auto");
			XTickLabelMode.reset("auto");
			YTick.reset(null);
			YTickMode.reset("manual");
			YTickLabel.reset(null);
			YTickLabelMode.reset("manual");
		}
		img.CDataMapping.set("direct", true);
		img.validate();

		Position.reset(new double[] {0, 0, 40.0/canvas.getWidth(), 40.0/canvas.getHeight()});
		autoTickX();
		autoTickY();
	}

	private void doClear()
	{
		while (Children.size() > 0)
			Children.elementAt(0).delete();
	}

	private void doLocate()
	{
		RenderCanvas canvas = getCanvas();
		double[] aPos = Utils.convertPosition(axes.Position.getArray(), axes.Units.getValue(), "pixels", canvas.getComponent());
		double[] aOPos = Utils.convertPosition(axes.OuterPosition.getArray(), axes.Units.getValue(), "pixels", canvas.getComponent());
		double[] pos = Utils.convertPosition(Position.getArray(), Units.getValue(), "pixels", canvas.getComponent());
		boolean outerActive = axes.ActivePositionProperty.is("outerposition");
		int margin = 40;

		String loc = Location.getValue().toLowerCase();
		int hPos = (loc.contains("west") ? 1 : loc.contains("east") ? 2 : 0);
		int vPos = (loc.contains("south") ? 1 : loc.contains("north") ? 2 : 0);
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
			if (hPos != 0)
			{
				switch (hPos)
				{
					case 1: /* west */
						if (outerActive)
						{
							double offset = margin+pos[2];
							aPos[0] += offset;
							aPos[2] -= offset;
						}
						pos[0] = aPos[0]-margin-pos[2];
						break;
					case 2: /* east */
						if (outerActive)
							aPos[2] -= (margin+pos[2]);
						pos[0] = aPos[0]+aPos[2]+margin;
						break;
				}
				pos[1] = aPos[1];
				pos[3] = aPos[3];
			}
			else
			{
				switch (vPos)
				{
					case 1: /* south */
						if (outerActive)
						{
							double offset = margin+pos[3];
							aPos[1] += offset;
							aPos[3] -= offset;
						}
						pos[1] = aPos[1]-margin-pos[3];
						break;
					case 2: /* north */
						if (outerActive)
							aPos[3] -= (margin+pos[3]);
						pos[1] = aPos[1]+aPos[3]+margin;
						break;
				}
				pos[0] = aPos[0];
				pos[2] = aPos[2];
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
		pos[2] = 40.0;
		pos[3] = 40.0;
		Position.set(Utils.convertPosition(pos, "pixels", Units.getValue(), canvas.getComponent()), true);
		doLocate();
	}

	private void updateImageFromColormap(Matrix m)
	{
		ImageObject img = (ImageObject)Children.elementAt(0);
		int nc = m.getDim(0);
		double[] cdata = new double[nc];
		double[] clim = axes.CLim.getArray();
		double px = (clim[1]-clim[0])/nc;

		for (int i=0; i<nc; i++)
			cdata[i] = i+1;
		if (vertical)
		{
			img.CData.set(new Matrix(cdata, new int[] {nc, 1}), true);
			img.YData.set(new double[] {clim[0]+px/2, clim[1]-px/2}, true);
		}
		else
		{
			img.CData.set(new Matrix(cdata, new int[] {1, nc}), true);
			img.XData.set(new double[] {clim[0]+px/2, clim[1]-px/2}, true);
		}
	}

	public void propertyChanged(Property p) throws PropertyException
	{
		super.propertyChanged(p);

		if (!isAutoMode() && !axes.isAutoMode() && (p == axes.Position || p == axes.OuterPosition))
			doLocate();
		else if (p == Location || p == axes.CLim)
		{
			autoMode++;
			axes.updateActivePosition();
			autoMode--;
			buildColorbar(axes);
			doLocate();
		}
		else if (p.getName().equalsIgnoreCase("colormap"))
			updateImageFromColormap(getFigure().Colormap.getMatrix());
	}
}
