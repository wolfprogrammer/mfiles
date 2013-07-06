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

public class ImageObject extends GraphicObject
{
	/* Properties */
	VectorProperty XData;
	VectorProperty YData;
	ArrayProperty CData;
	RadioProperty CDataMapping;

	public ImageObject(HandleObject parent)
	{
		super(parent, "image");

		CData = new ArrayProperty(this, "CData", new String[] {"double", "byte"}, -1, null);
		XData = new VectorProperty(this, "XData", 2, new double[] {1, 1});
		YData = new VectorProperty(this, "YData", 2, new double[] {1, 1});
		CDataMapping = new RadioProperty(this, "CDataMapping", new String[] {"scaled", "direct"}, "direct");

		CLimInclude.reset(new Boolean(true));

		listen(CData);
		listen(XData);
		listen(YData);
		listen(CDataMapping);
		listen(getAxes().getFigure().Colormap);

		//updateMinMax();
	}

	private void updateMinMax()
	{
		double[] x = XData.getArray(), y = YData.getArray();
		int h = CData.getDim(0), w = CData.getDim(1);
		double px = (w > 1 ? (x[1]-x[0])/(w-1) : 1), py = (h > 1 ? (y[1]-y[0])/(h-1) : 1);
		double xmin, xmax, ymin, ymax, xmin2, xmax2, ymin2, ymax2;

		xmin = xmin2 = x[0]-px/2; xmax = xmax2 = (w > 1 ? x[1]+px/2 : x[0]+px/2);
		ymin = ymin2 = y[0]-py/2; ymax = ymax2 = (h > 1 ? y[1]+py/2 : y[0]+px/2);
		if (xmax2 <= 0)
		{
			xmin2 = Double.POSITIVE_INFINITY;
			xmax2 = Double.MIN_VALUE;
		}
		else if (xmin2 <= 0)
		{
			double k = Math.ceil(0.5-x[0]/px);
			xmin2 = x[0]+(k-0.5)*px;
		}
		if (ymax2 <= 0)
		{
			ymin2 = Double.POSITIVE_INFINITY;
			ymax2 = Double.MIN_VALUE;
		}
		else if (ymin2 <= 0)
		{
			double k = Math.ceil(0.5-y[0]/py);
			ymin2 = y[0]+(k-0.5)*py;
		}

		XLim.set(new double[] {xmin, xmax, xmin2, xmax2}, true);
		YLim.set(new double[] {ymin, ymax, ymin2, ymax2}, true);

		if (CData.getNDims() == 2 && CDataMapping.is("scaled"))
			CLim.set(new double[] {
					CData.getMatrix().minValue(),
					CData.getMatrix().maxValue()},
				 true);
		else
			CLim.set(new double[] {Double.POSITIVE_INFINITY, Double.NEGATIVE_INFINITY}, true);
	}

	public void validate()
	{
		updateMinMax();
		super.validate();
	}

	public void draw(Renderer r)
	{
		r.draw(this);
	}

	public void propertyChanged(Property p) throws PropertyException
	{
		super.propertyChanged(p);

		/* invalidate cached data */
		if (p == CData || p == CDataMapping || p.getName().equals("Colormap"))
			setCachedData(null);

		/* update limits */
		if (p == XData || p == YData || p == CData || p == CDataMapping)
			updateMinMax();
	}
}
