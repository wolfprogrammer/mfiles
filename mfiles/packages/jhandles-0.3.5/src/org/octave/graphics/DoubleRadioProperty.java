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

import java.text.DecimalFormat;
import java.util.*;

public class DoubleRadioProperty extends Property
{
	private Set valueSet;

	protected DoubleRadioProperty(DoubleRadioProperty p)
	{
		super(p);
		this.valueSet = p.valueSet;
	}

	public DoubleRadioProperty(PropertySet parent, String name, String[] values)
	{
		super(parent, name);
		this.valueSet = Collections.synchronizedSet(new HashSet());
		for (int i=0; i<values.length; i++)
			this.valueSet.add(values[i]);
	}

	public DoubleRadioProperty(PropertySet parent, String name, String[] values, double value)
	{
		this(parent, name, values, new Double(value));
	}

	public DoubleRadioProperty(PropertySet parent, String name, String[] values, Object value)
	{
		this(parent, name, values);
		this.pvalue = value;
	}

	public Property cloneProperty()
	{
		return new DoubleRadioProperty(this);
	}

	protected Object convertValue(Object val) throws PropertyException
	{
		if (val instanceof Number)
			return new Double(((Number)val).doubleValue());
		else if (val instanceof String && valueSet.contains(val))
			return val;
		else
			throw new PropertyException("invalid property value - " + val.toString());
	}

	public double doubleValue()
	{
		return (pvalue instanceof Double ? ((Double)pvalue).doubleValue() : 1.0);
	}

	public float floatValue()
	{
		return (float)doubleValue();
	}

	public int intValue()
	{
		return (int)Math.round(doubleValue());
	}

	public boolean isDouble()
	{
		return (pvalue instanceof Double);
	}

	public boolean is(String val)
	{
		return (pvalue instanceof String && ((String)pvalue).equalsIgnoreCase(val));
	}

	public String toString()
	{
		if (pvalue instanceof Double)
		{
			DecimalFormat fmt = new DecimalFormat("0.0000");
			return fmt.format(((Double)pvalue).doubleValue());
		}
		else
			return (String)pvalue;
	}
}
