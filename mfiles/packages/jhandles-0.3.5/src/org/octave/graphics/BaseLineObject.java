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

public class BaseLineObject extends LineObject
{
	/* Properties */
	DoubleProperty BaseValue;
	RadioProperty Orientation;

	public BaseLineObject(HandleObject parent, double value)
	{
		super(parent);

		BaseValue = new DoubleProperty(this, "BaseValue", value);
		Orientation = new RadioProperty(this, "Orientation", new String[] {"X", "Y"}, "X");
		XLimInclude.reset(new Boolean(false));
		YData.reset(new double[] {value, value});

		Orientation.setVisible(false);

		listen(BaseValue);
		listen(Orientation);
		listen(getAxes().XLim);
		listen(getAxes().YLim);
	}

	public double getXMin()
	{
		return Double.POSITIVE_INFINITY;
	}

	public double getXMax()
	{
		return Double.NEGATIVE_INFINITY;
	}

	public void draw(Renderer r)
	{
		super.draw(r);
	}

	public boolean isLegendable()
	{
		return false;
	}

	public void updateLine()
	{
		double b = BaseValue.doubleValue();
		if (Orientation.is("X"))
		{
			XData.set(getAxes().XLim.getArray().clone(), true);
			YData.set(new double[] {b, b}, true);
		}
		else
		{
			XData.set(new double[] {b, b}, true);
			YData.set(getAxes().YLim.getArray().clone(), true);
		}
	}

	public void propertyChanged(Property p) throws PropertyException
	{
		super.propertyChanged(p);

		if (p == BaseValue)
			updateLine();
		else if (p == Orientation)
		{
			boolean isX = Orientation.is("X");
			XLimInclude.set(new Boolean(!isX));
			YLimInclude.set(new Boolean(isX));
			updateLine();
		}

		if (p.getParent() == getAxes())
		{
			String name = p.getName();
			if ((name.equals("XLim") && Orientation.is("X")) ||
				(name.equals("YLim") && Orientation.is("Y")))
				updateLine();
		}
	}
}
