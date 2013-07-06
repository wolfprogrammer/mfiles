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

public class StringProperty extends Property
{
	protected StringProperty(StringProperty p)
	{
		super(p);
	}

	public StringProperty(PropertySet parent, String name)
	{
		super(parent, name);
	}

	public StringProperty(PropertySet parent, String name, String value)
	{
		this(parent, name);
		this.pvalue = value;
	}

	public Property cloneProperty()
	{
		return new StringProperty(this);
	}

	public String toString()
	{
		return pvalue.toString();
	}

	protected Object convertValue(Object value) throws PropertyException
	{
		if (value == null)
			return "";
		else if (value instanceof String)
			return value;
		else
			throw new PropertyException("invalid property value - " + value);
	}
}
