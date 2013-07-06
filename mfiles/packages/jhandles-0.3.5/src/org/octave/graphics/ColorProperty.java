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

import java.awt.Color;
import java.text.DecimalFormat;
import java.util.*;
import org.octave.Matrix;

public class ColorProperty extends Property
{
	private Set valueSet;

	protected ColorProperty(ColorProperty p)
	{
		super(p);
		if (p.valueSet != null)
			this.valueSet = Collections.synchronizedSet(new HashSet(p.valueSet));
	}

	public ColorProperty(PropertySet parent, String name)
	{
		super(parent, name);
	}

	public ColorProperty(PropertySet parent, String name, String[] values)
	{
		this(parent, name);
		if (values != null)
		{
			this.valueSet = Collections.synchronizedSet(new HashSet());
			for (int i=0; i<values.length; i++)
				this.valueSet.add(values[i]);
		}
		else
			this.valueSet = null;
	}

	public ColorProperty(PropertySet parent, String name, Color color)
	{
		this(parent, name);
		this.pvalue = color;
	}

	public ColorProperty(PropertySet parent, String name, String[] values, Object color)
	{
		this(parent, name, values);
		this.pvalue = color;
	}

	public Property cloneProperty()
	{
		return new ColorProperty(this);
	}

	protected Object convertValue(Object value) throws PropertyException
	{
		Object c = null;

		if (value == null)
			c = null;
		else if (value instanceof Color)
			c = value;
		else if (value instanceof String)
		{
			c = decodeColor((String)value);
			if (c == null)
			{
				if (valueSet.contains((String)value))
					c = value;
				else
					throw new PropertyException("invalid color name - " + value.toString());
			}
		}
		else if (value instanceof Matrix)
		{
			Matrix m = (Matrix)value;
			if (m.isVector() && m.getClassName().equals("double") && m.getLength() == 3)
			{
				double[] cv = m.toDouble();
				c = new Color((float)cv[0], (float)cv[1], (float)cv[2]);
			}
			else
				throw new PropertyException("invalid color value - " + value.toString());
		}
		else
		{
			try
			{
				double[] cv = (double[])value;
				if (cv.length == 3)
					c = new Color((float)cv[0], (float)cv[1], (float)cv[2]);
			}
			catch (ClassCastException e) { }
			if (c == null)
				throw new PropertyException("invalid color value - " + value.toString());
		}
		
		return c;
	}

	protected Object getInternal()
	{
		return (isSet() ? getArray() : pvalue);
	}

	public Color getColor()
	{
		return (isSet() ? (Color)pvalue : null);
	}

	public boolean isSet()
	{
		return (pvalue instanceof Color);
	}

	public boolean is(String s)
	{
		return (!isSet() && pvalue != null && ((String)pvalue).equalsIgnoreCase(s));
	}

	public double[] getArray()
	{
		if (isSet())
		{
			Color c = getColor();
			return new double[] {c.getRed()/255.0, c.getGreen()/255.0, c.getBlue()/255.0};
		}
		else
			return null;
	}

	private Color decodeColor(String name)
	{
		if (name.length() == 1)
			switch (name.charAt(0))
			{
			case 'r': return Color.red;
			case 'c': return Color.cyan;
			case 'y': return Color.yellow;
			case 'g': return Color.green;
			case 'm': return Color.magenta;
			case 'k': return Color.black;
			case 'b': return Color.blue;
			case 'w': return Color.white;
			}
		else
		{
			name = name.toLowerCase();
			if ("white".startsWith(name))
				return Color.white;
			else if ("red".startsWith(name))
				return Color.red;
			else if ("yellow".startsWith(name))
				return Color.yellow;
			else if ("blue".startsWith(name))
				return Color.blue;
			else if ("magenta".startsWith(name))
				return Color.magenta;
			else if ("green".startsWith(name))
				return Color.green;
			else if ("cyan".startsWith(name))
				return Color.cyan;
		}

		return null;
	}

	public String toString()
	{
		if (isSet())
		{
			DecimalFormat fmt = new DecimalFormat("0.0000 ");
			Color c = (Color)pvalue;
			return (
				"[ " +
				fmt.format(c.getRed()/255.0) +
				fmt.format(c.getGreen()/255.0) +
				fmt.format(c.getBlue()/255.0) +
				"]");
		}
		else if (pvalue != null)
			return pvalue.toString();
		else
			return "<not set>";
	}
}
