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
import org.octave.Matrix;

public class HandleObjectListProperty extends Property
{
	int maxCount;

	protected HandleObjectListProperty(HandleObjectListProperty p)
	{
		super(p);
	}

	public HandleObjectListProperty(PropertySet parent, String name)
	{
		this(parent, name, -1);
	}

	public HandleObjectListProperty(PropertySet parent, String name, int maxCount)
	{
		super(parent, name);
		this.maxCount = maxCount;
		this.pvalue = new Vector();
	}

	public Property cloneProperty()
	{
		return new HandleObjectListProperty(this);
	}

	protected Object getInternal()
	{
		return getHandleArray();
	}

	protected Object convertValue(Object value) throws PropertyException
	{
		Vector v = new Vector();

		if (value == null)
			return v;

		Class cls = value.getClass();

		if (value instanceof Number)
		{
			double h = ((Number)value).doubleValue();
			try
			{
				v.add(HandleObject.getHandleObject(h));
			}
			catch (Exception e)
			{
				throw new PropertyException("invalid handle value - " + h);
			}
		}
		else if (value instanceof HandleObject)
			v.add(value);
		else if ((cls.isArray() && cls.getComponentType().equals(Double.TYPE)) ||
			 (value instanceof Matrix && ((Matrix)value).getClassName().equals("double")))
		{
			double[] hv = (value instanceof Matrix ? ((Matrix)value).toDouble() : (double[])value);
			try
			{
				for (int i=0; i<hv.length; i++)
					v.add(HandleObject.getHandleObject(hv[i]));
			}
			catch (Exception e)
			{
				throw new PropertyException("invalid handle value");
			}
		}
		else
			throw new PropertyException("invalid property value - " + value);

		return v;
	}

	private List getVisibleObjects()
	{
		List l = new LinkedList();
		Iterator it = ((Vector)pvalue).iterator();
		boolean showAll = RootObject.getInstance().ShowHiddenHandles.isSet();
		boolean callbackMode = RootObject.getInstance().isCallbackMode();

		while (it.hasNext())
		{
			HandleObject hObj = (HandleObject)it.next();
			if (showAll || hObj.HandleVisibility.is("on") ||
					(callbackMode && hObj.HandleVisibility.is("callback")))
				l.add(hObj);
		}
		return l;
	}

	public double[] getHandleArray()
	{
		List l = getVisibleObjects();
		double[] hList = new double[l.size()];
		Iterator it = l.iterator();
		int index = 0;

		while (it.hasNext())
		{
			HandleObject hObj = (HandleObject)it.next();
			hList[index++] = hObj.getHandle();
		}
		return hList;
	}

	public void addElement(HandleObject obj)
	{
		Vector objectList = (Vector)pvalue;
		if (maxCount <= 0 || objectList.size() < maxCount)
			objectList.add(obj);
		else
			objectList.set(maxCount-1, obj);
	}

	public void removeElement(HandleObject obj)
	{
		Vector objectList = (Vector)pvalue;
		objectList.remove(obj);
	}

	public HandleObject elementAt(int index)
	{
		Vector objectList = (Vector)pvalue;
		return (HandleObject)objectList.elementAt(index);
	}

	public int size()
	{
		Vector objectList = (Vector)pvalue;
		return objectList.size();
	}

	public Iterator iterator()
	{
		Vector objectList = (Vector)pvalue;
		return objectList.iterator();
	}

	public boolean contains(HandleObject obj)
	{
		Vector objectList = (Vector)pvalue;
		return objectList.contains(obj);
	}

	public void removeAllElements()
	{
		Vector objectList = (Vector)pvalue;
		objectList.removeAllElements();
	}

	public String toString()
	{
		List objectList = getVisibleObjects();
		String buf = "[ ";
		Iterator it = objectList.iterator();

		while (it.hasNext())
		{
			HandleObject hObj = (HandleObject)it.next();
			buf += (Utils.handleToString(hObj.getHandle()) + " ");
			if (buf.length() > 64)
				return ("[ 1 x " + objectList.size() + " handle array ]");
		}
		buf += "]";

		return buf;
	}
}
