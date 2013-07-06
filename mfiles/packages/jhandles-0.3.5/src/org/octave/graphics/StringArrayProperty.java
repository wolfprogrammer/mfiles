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

public class StringArrayProperty extends Property
{
	protected StringArrayProperty(StringArrayProperty p)
	{
		super(p);
		this.pvalue = getArray().clone();
	}

	public StringArrayProperty(PropertySet parent, String name)
	{
		super(parent, name);
	}

	public StringArrayProperty(PropertySet parent, String name, String[] value)
	{
		this(parent, name);
		this.pvalue = value;
	}

	public Property cloneProperty()
	{
		return new StringArrayProperty(this);
	}

	protected Object convertValue(Object value) throws PropertyException
	{
		if (value instanceof String)
			return ((String)value).split("|");
		else
		{
			try
			{
				String[] v = (value == null ? new String[0] : (String[])value);
				return v;
			}
			catch (ClassCastException e)
			{
				throw new PropertyException("invalid character array value - " + value.toString());
			}
		}
	}

	public String[] getArray()
	{
		return (String[])pvalue;
	}

	public String toString()
	{
		String[] array = getArray();
		String buf = "[ ";
		for (int i=0; i<array.length; i++)
		{
			buf += (array[i] + " ");
			if (buf.length() > 64)
				return ("[ 1 x " + array.length + " character array ]");
		}
		buf += "]";
		return buf;
	}
}
