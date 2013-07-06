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

public class GroupObject extends GraphicObject
{
	public GroupObject(HandleObject parent)
	{
		super(parent, "hggroup");
	}

	private void updateLimits()
	{
		synchronized (Children)
		{
			double xmin, xmax, ymin, ymax, zmin, zmax, cmin, cmax, amin, amax;
			double xmin2, xmax2, ymin2, ymax2, zmin2, zmax2;
			Iterator it = Children.iterator();
			double[] lim;

			xmin = ymin = zmin = cmin = amin = Double.POSITIVE_INFINITY;
			xmax = ymax = zmax = cmax = amax = Double.NEGATIVE_INFINITY;
			xmin2 = ymin2 = zmin2 = Double.POSITIVE_INFINITY;
			xmax2 = ymax2 = zmax2 = Double.MIN_VALUE;
			while (it.hasNext())
			{
				GraphicObject obj = (GraphicObject)it.next();
				lim = obj.XLim.getArray();
				xmin = Math.min(lim[0], xmin);
				xmax = Math.max(lim[1], xmax);
				xmin2 = Math.min(lim[2], xmin2);
				xmax2 = Math.max(lim[3], xmax2);
				lim = obj.YLim.getArray();
				ymin = Math.min(lim[0], ymin);
				ymax = Math.max(lim[1], ymax);
				ymin2 = Math.min(lim[2], ymin2);
				ymax2 = Math.max(lim[3], ymax2);
				lim = obj.ZLim.getArray();
				zmin = Math.min(lim[0], zmin);
				zmax = Math.max(lim[1], zmax);
				zmin2 = Math.min(lim[2], zmin2);
				zmax2 = Math.max(lim[3], zmax2);
				lim = obj.CLim.getArray();
				cmin = Math.min(lim[0], cmin);
				cmax = Math.max(lim[1], cmax);
				lim = obj.ALim.getArray();
				amin = Math.min(lim[0], amin);
				amax = Math.max(lim[1], amax);
			}

			XLim.set(new double[] {xmin, xmax, xmin2, xmax2}, true);
			YLim.set(new double[] {ymin, ymax, ymin2, ymax2}, true);
			ZLim.set(new double[] {zmin, zmax, zmin2, zmax2}, true);
			CLim.set(new double[] {cmin, cmax}, true);
			ALim.set(new double[] {amin, amax}, true);
		}
	}

	public void childValidated(HandleObject child)
	{
		super.childValidated(child);
		updateLimits();
		if (child instanceof GraphicObject)
		{
			GraphicObject g = (GraphicObject)child;
			listen(g.XLim);
			listen(g.YLim);
			listen(g.ZLim);
			listen(g.CLim);
			listen(g.ALim);
		}
	}

	public void removeChild(HandleObject child)
	{
		super.removeChild(child);
		updateLimits();
	}

	public void draw(Renderer r)
	{
		synchronized (Children)
		{
			Iterator it = Children.iterator();
			while (it.hasNext())
			{
				GraphicObject obj = (GraphicObject)it.next();
				obj.draw(r);
			}
		}
	}

	public void validate()
	{
		synchronized (Children)
		{
			Iterator it = Children.iterator();
			while (it.hasNext())
				((HandleObject)it.next()).validate();
			super.validate();
		}
	}

	public void propertyChanged(Property p) throws PropertyException
	{
		super.propertyChanged(p);
		
		String name = p.getName().toLowerCase();
		if (name.equals("xlim") || name.equals("ylim") || name.equals("zlim") ||
			name.equals("clim") || name.equals("alim"))
		{
			updateLimits();
		}
	}
}
