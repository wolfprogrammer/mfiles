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
import java.util.*;
import javax.swing.UIManager;
import org.octave.Matrix;

public class RootObject extends HandleObject
{
	private static RootObject instance = null;
	private boolean callbackMode = false;
	private LinkedList callbackObject = new LinkedList();
	private int callbackModeCount = 0;

	/* properties */
	HandleObjectListProperty CallbackObject;
	HandleObjectListProperty CurrentFigure;
	ArrayProperty MonitorPositions;
	BooleanProperty ShowHiddenHandles;

	private RootObject()
	{
		super(null, 0, "root");

		Dimension d = Utils.getScreenSize();

		CallbackObject = new HandleObjectListProperty(this, "CallbackObject", 1);
		CurrentFigure = new HandleObjectListProperty(this, "CurrentFigure", 1);
		MonitorPositions = new ArrayProperty(this, "MonitorPositions",
				new Matrix(new double[] {1, 1, d.width, d.height}));
		ShowHiddenHandles = new BooleanProperty(this, "ShowHiddenHandles", false);

		listen(CurrentFigure);
	}

	public static RootObject getInstance()
	{
		if (instance == null)
		{
			instance = new RootObject();
			instance.validate();
		}
		return instance;
	}

	public FigureObject createNewFigure()
	{
		return createNewFigure(getUnusedFigureNumber());
	}

	public FigureObject createNewFigure(int fignum)
	{
		if (fignum > 0)
		{
			if (isHandle(fignum))
			{
				try { return (FigureObject)getHandleObject(fignum);}
				catch (Exception e) { return null; }
			}
			else
				return new FigureObject(fignum);
		}
		return null;
	}

	public void removeChild(HandleObject child)
	{
		if (CurrentFigure.size() > 0 && CurrentFigure.elementAt(0) == child)
			CurrentFigure.removeAllElements();
		super.removeChild(child);
		if (CurrentFigure.size() == 0 && Children.size() > 0)
			CurrentFigure.addElement(Children.elementAt(0));
	}

	public FigureObject findFigure(int fignum)
	{
		Iterator it = Children.iterator();
		while (it.hasNext())
		{
			FigureObject fig = (FigureObject)it.next();
			if (fig.getHandle() == fignum)
				return fig;
		}
		return null;
	}

	public int getUnusedFigureNumber()
	{
		for (int i=1; i<999; i++)
			if (!isHandle(i))
				return i;
		return -1;
	}

	public double[][] defaultColorMap()
	{
		double[][] cmap = new double[64][3];
		double dx = 0.0625;
		int index = 0;

		for (double cval=0.5+dx; cval<=1.0; cval+=dx, index++)
			cmap[index][2] = cval;
		for (double cval=dx; cval<=1.0; cval+=dx, index++)
		{
			cmap[index][1] = cval;
			cmap[index][2] = 1.0;
		}
		for (double cval=dx; cval<=1.0; cval+=dx, index++)
		{
			cmap[index][0] = cval;
			cmap[index][1] = 1.0;
			cmap[index][2] = 1.0-cval;
		}
		for (double cval=dx; cval<=1.0; cval+=dx, index++)
		{
			cmap[index][0] = 1.0;
			cmap[index][1] = 1.0-cval;
		}
		for (double cval=dx; cval<=0.5; cval+=dx, index++)
			cmap[index][0] = 1.0-cval;

		return cmap;
	}

	public void propertyChanged(Property p) throws PropertyException
	{
		super.propertyChanged(p);

		if (p == CurrentFigure)
		{
			if (CurrentFigure.size() > 0)
				if (CurrentFigure.elementAt(0) == this)
					CurrentFigure.removeAllElements();
				else
					((FigureObject)CurrentFigure.elementAt(0)).activate();
		}
	}

	public boolean isCallbackMode()
	{
		return (CallbackObject.size() > 0);
	}
}
