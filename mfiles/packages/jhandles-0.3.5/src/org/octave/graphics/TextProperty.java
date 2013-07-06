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

public class TextProperty extends Property
{
	protected TextProperty(TextProperty p)
	{
		super(p);
	}

	public TextProperty(PropertySet parent, String name, TextObject obj)
	{
		super(parent, name);
		pvalue = obj;
	}

	public Property cloneProperty()
	{
		return new TextProperty(this);
	}

	public Object getInternal()
	{
		return new Double(((TextObject)pvalue).getHandle());
	}

	protected Object convertValue(Object value) throws PropertyException
	{
		if (value instanceof String)
			return value;
		else if (value instanceof Double)
		{
			double h = ((Double)value).doubleValue();
			if (HandleObject.isHandle(h))
			{
				try
				{
					HandleObject obj = HandleObject.getHandleObject(h);
					if (obj instanceof TextObject)
						return obj;
					else
						throw new PropertyException("invalid text object - " + obj.toString());
				}
				catch (Exception e)
				{
					if (e instanceof PropertyException)
						throw (PropertyException)e;
					else
						throw new PropertyException("unexpected error - " + e.toString());
				}
			}
			else
				throw new PropertyException("invalid handle - " + value.toString());
		}
		else
			throw new PropertyException("invalid property value - " + value.toString());
	}

	public void setInternal(Object value) throws PropertyException
	{
		if (value instanceof String)
			((TextObject)pvalue).set("String", value);
		else if (value instanceof TextObject)
			pvalue = value;
	}

	public TextObject getText()
	{
		return (TextObject)pvalue;
	}

	public String toString()
	{
		return ("[ " + Utils.handleToString(getText().getHandle()) + " ]");
		//return txtObject.TextString.toString();
	}

	public boolean isEmpty()
	{
		return (getText().TextString.toString() == "");
	}

	protected boolean isEqual(Object value)
	{
		if (value instanceof String)
			return ((TextObject)pvalue).TextString.isEqual(value);
		else
			return (pvalue == value);
	}
}
