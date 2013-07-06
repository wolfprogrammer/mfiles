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
import org.octave.Matrix;

public class LineObject extends GraphicObject
{
	/* properties */
	VectorProperty XData;
	VectorProperty YData;
	VectorProperty ZData;
	ColorProperty LineColor;
	LineStyleProperty LineStyle;
	DoubleProperty LineWidth;
	StringProperty KeyLabel;
	MarkerProperty Marker;
	DoubleProperty MarkerSize;
	ColorProperty MarkerEdgeColor;
	ColorProperty MarkerFaceColor;

	public LineObject(HandleObject parent)
	{
		super(parent, "line");

		XData = new VectorProperty(this, "XData", -1);
		YData = new VectorProperty(this, "YData", -1);
		ZData = new VectorProperty(this, "ZData", -1);
		LineColor = new ColorProperty(this, "Color");
		LineStyle = new LineStyleProperty(this, "LineStyle");
		LineWidth = new DoubleProperty(this, "LineWidth");
		KeyLabel = new StringProperty(this, "KeyLabel", "");
		Marker = new MarkerProperty(this, "Marker");
		MarkerSize = new DoubleProperty(this, "MarkerSize");
		MarkerEdgeColor = new ColorProperty(this, "MarkerEdgeColor", new String[] {"none", "auto"});
		MarkerFaceColor = new ColorProperty(this, "MarkerFaceColor", new String[] {"none", "auto"});

		if (ZData.getArray().length > 0)
			ZLimInclude.reset("on");
		LegendInclude.reset("on");

		listen(XData);
		listen(YData);
		listen(ZData);
	}

	public void validate()
	{
		ZLimInclude.reset(ZData.isEmpty() ? "off" : "on");
		updateMinMax();
		super.validate();
	}

	private void updateMinMax()
	{
		double xmin, xmax, ymin, ymax, zmin, zmax;
		double xmin2, xmax2, ymin2, ymax2, zmin2, zmax2;
		double[] xdata = XData.getArray();
		double[] ydata = YData.getArray();
		double[] zdata = ZData.getArray();
		boolean hasZ = (zdata.length > 0);
		int n = Math.min(Math.min(xdata.length, ydata.length), (hasZ ? zdata.length : Integer.MAX_VALUE));

		if (n == 0)
			return;

		xmin = ymin = xmin2 = ymin2 = Double.POSITIVE_INFINITY;
		xmax = ymax = Double.NEGATIVE_INFINITY;
		xmax2 = ymax2 = Double.MIN_VALUE;
		zmin = (hasZ ? Double.POSITIVE_INFINITY : -0.5);
		zmax = (hasZ ? Double.NEGATIVE_INFINITY : 0.5);
		zmin2 = (hasZ ? Double.POSITIVE_INFINITY : 0.1);
		zmax2 = (hasZ ? Double.MIN_VALUE : 1);

		for (int i=0; i<n; i++)
		{
			if (!Utils.isNaNorInf(xdata[i]))
			{
				if (xdata[i] < xmin) xmin = xdata[i];
				if (xdata[i] > xmax) xmax = xdata[i];
				if (xdata[i] > 0)
				{
					if (xdata[i] < xmin2) xmin2 = xdata[i];
					if (xdata[i] > xmax2) xmax2 = xdata[i];
				}
			}
			if (!Utils.isNaNorInf(ydata[i]))
			{
				if (ydata[i] < ymin) ymin = ydata[i];
				if (ydata[i] > ymax) ymax = ydata[i];
				if (ydata[i] > 0)
				{
					if (ydata[i] < ymin2) ymin2 = ydata[i];
					if (ydata[i] > ymax2) ymax2 = ydata[i];
				}
			}
			if (hasZ && !Utils.isNaNorInf(zdata[i]))
			{
				if (zdata[i] < zmin) zmin = zdata[i];
				if (zdata[i] > zmax) zmax = zdata[i];
				if (zdata[i] > 0)
				{
					if (zdata[i] < zmin2) zmin2 = zdata[i];
					if (zdata[i] > zmax2) zmax2 = zdata[i];
				}
			}
		}

		XLim.set(new double[] {xmin, xmax, xmin2, xmax2}, true);
		YLim.set(new double[] {ymin, ymax, ymin2, ymax2}, true);
		if (hasZ)
			ZLim.set(new double[] {zmin, zmax, zmin2, zmax2}, true);
	}

	public void draw(Renderer r)
	{
		r.draw(this);
	}

	public void propertyChanged(Property p) throws PropertyException
	{
		super.propertyChanged(p);

		if (p == ZData)
			ZLimInclude.reset((ZData.isEmpty() ? "off" : "on"));

		if (p == XData || p == YData || p == ZData)
			updateMinMax();
	}
}
