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

public class LineStyleProperty extends RadioProperty
{
	protected LineStyleProperty(LineStyleProperty p)
	{
		super(p);
	}

	public LineStyleProperty(PropertySet parent, String name)
	{
		super(parent, name, new String[] {"-", ":", "--", "-.", "none", ""});
	}

	public LineStyleProperty(PropertySet parent, String name, String style)
	{
		this(parent, name);
		this.pvalue = style;
	}

	public Property cloneProperty()
	{
		return new LineStyleProperty(this);
	}
	
	public Stroke getStroke(float width)
	{
		String ls = getValue();
		if (ls.equals(":"))
			return new BasicStroke(width, BasicStroke.CAP_BUTT, BasicStroke.JOIN_BEVEL, 1.0f,
					new float[] {2.0f, 3.0f}, 0.0f);
		else if (ls.equals("-"))
			return new BasicStroke(width);
		else if (ls.equals("--"))
			return new BasicStroke(width, BasicStroke.CAP_BUTT, BasicStroke.JOIN_BEVEL, 1.0f,
					new float[] {10.0f, 5.0f}, 0.0f);
		else if (ls.equals("-."))
			return new BasicStroke(width, BasicStroke.CAP_BUTT, BasicStroke.JOIN_BEVEL, 1.0f,
					new float[] {5.0f, 5.0f, 1.0f, 5.0f}, 0.0f);
		else
			return null;
	}

	public void setStyle(String s)
	{
		try { set(s); }
		catch (PropertyException e) { }
	}

	public int getStyle()
	{
		String ls = getValue();
		if (ls.equals("-"))
			return Renderer.LS_SOLID;
		else if (ls.equals(":"))
			return Renderer.LS_DOTTED;
		else if (ls.equals("--"))
			return Renderer.LS_DASHED;
		else if (ls.equals("-."))
			return Renderer.LS_DASHDOT;
		return Renderer.LS_NONE;
	}

	public boolean isSet()
	{
		return !(is("none") || is(""));
	}

	public String toPostScript()
	{
		if (is(":"))
			return "[0 3 1 3 1 3 1 3 1 0] 0 setdash";
		else if (is("-"))
			return "[] 0 setdash";
		else if (is("--"))
			return "[11 5] 0 setdash";
		else if (is("-."))
			return "[4 5 1 6] 0 setdash";
		else
			return "[0 16] 0 setdash";
	}
}
