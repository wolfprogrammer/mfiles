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

public class PositionLayout implements LayoutManager
{
	public PositionLayout()
	{
	}

	/* LayoutManager interface */

	public void addLayoutComponent(String name, Component comp) {}

	public void layoutContainer(Container parent)
	{
		Insets ir = parent.getInsets();
		Rectangle r = parent.getBounds();
		int nComp = parent.getComponentCount();

		for (int i=0; i<nComp; i++)
		{
			Component comp = parent.getComponent(i);

			if (comp instanceof Positionable)
			{
				/* use Position property of the object */
				double[] pos = ((Positionable)comp).getPosition();
				pos[0]--;
				pos[1] = (r.height-ir.top-ir.bottom-pos[1]-pos[3]+1);
				comp.setBounds(ir.left+(int)pos[0], ir.top+(int)pos[1], (int)pos[2], (int)pos[3]);
			}
			else if (comp instanceof RenderCanvas)
			{
				/* the render canvas takes up all the available space */
				comp.setBounds(ir.left, ir.top, r.width-ir.left-ir.right, r.height-ir.top-ir.bottom);
			}
			else
				System.out.println("Warning: skipping layout component " + comp.toString());
		}
	}

	public Dimension minimumLayoutSize(Container parent)
	{
		return new Dimension(100, 100);
	}

	public Dimension preferredLayoutSize(Container parent)
	{
		return new Dimension(500, 400);
	}

	public void removeLayoutComponent(Component comp) {}
}
