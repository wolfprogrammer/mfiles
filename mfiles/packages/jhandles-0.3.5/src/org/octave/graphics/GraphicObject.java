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

public abstract class GraphicObject extends HandleObject
{
	protected int glID;

	private static int glIDCounter = 1;

	/* properties */
	VectorProperty XLim;
	VectorProperty YLim;
	VectorProperty ZLim;
	VectorProperty CLim;
	VectorProperty ALim;
	BooleanProperty XLimInclude;
	BooleanProperty YLimInclude;
	BooleanProperty ZLimInclude;
	BooleanProperty CLimInclude;
	BooleanProperty ALimInclude;
	BooleanProperty LegendInclude;

	public GraphicObject(HandleObject parent, String type)
	{
		super(parent, type);

		glID = glIDCounter++;

		double[] d1 = new double[] {Double.POSITIVE_INFINITY, Double.NEGATIVE_INFINITY,
			Double.POSITIVE_INFINITY, Double.MIN_VALUE};
		double[] d2 = new double[] {Double.POSITIVE_INFINITY, Double.NEGATIVE_INFINITY};

		XLim = new VectorProperty(this, "XLim", 4, d1);
		YLim = new VectorProperty(this, "YLim", 4, d1);
		ZLim = new VectorProperty(this, "ZLim", 4, d1);
		CLim = new VectorProperty(this, "CLim", 2, d2);
		ALim = new VectorProperty(this, "ALim", 2, d2);
		XLimInclude = new BooleanProperty(this, "XLimInclude", true);
		YLimInclude = new BooleanProperty(this, "YLimInclude", true);
		ZLimInclude = new BooleanProperty(this, "ZLimInclude", false);
		CLimInclude = new BooleanProperty(this, "CLimInclude", false);
		ALimInclude = new BooleanProperty(this, "ALimInclude", false);
		LegendInclude = new BooleanProperty(this, "LegendInclude", false);

		XLim.setVisible(false);
		YLim.setVisible(false);
		ZLim.setVisible(false);
		CLim.setVisible(false);
		ALim.setVisible(false);
		XLimInclude.setVisible(false);
		YLimInclude.setVisible(false);
		ZLimInclude.setVisible(false);
		CLimInclude.setVisible(false);
		ALimInclude.setVisible(false);
		LegendInclude.setVisible(false);
	}

	public AxesObject getAxes()
	{
		HandleObject obj = Parent.elementAt(0);
		if (obj instanceof AxesObject)
			return (AxesObject)obj;
		else
			return ((GraphicObject)obj).getAxes();
	}

	public void set(Property p, Object value) throws PropertyException
	{
		super.set(p, value);

		FigureObject fig = (FigureObject)getAncestor("figure");
		fig.__Dirty__.reset("on");
	}

	public boolean isLegendable()
	{
		return LegendInclude.isSet();
	}

	public abstract void draw(Renderer r);
}
