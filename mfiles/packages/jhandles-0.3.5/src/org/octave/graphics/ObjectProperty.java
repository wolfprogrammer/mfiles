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

public class ObjectProperty extends Property
{
	protected ObjectProperty(ObjectProperty p)
	{
		super(p);
	}

	public ObjectProperty(PropertySet parent, String name)
	{
		super(parent, name);
	}

	public ObjectProperty(PropertySet parent, String name, Object value)
	{
		this(parent, name);
		this.pvalue = value;
	}

	public Property cloneProperty()
	{
		return new ObjectProperty(this);
	}

	public String toString()
	{
		if (pvalue != null)
			return pvalue.toString();
		else
			return "";
	}

	public Object getObject()
	{
		return pvalue;
	}
}
