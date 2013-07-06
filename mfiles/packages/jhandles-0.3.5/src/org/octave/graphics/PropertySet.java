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

public class PropertySet extends TreeMap
{
	public PropertySet()
	{
		super();
	}

	public void addProperty(Property p)
	{
		put(p.getName().toLowerCase(), p);
	}

	public Property getProperty(String name)
	{
		return (Property)get((Object)name.toLowerCase());
	}

	public boolean hasProperty(String name)
	{
		return containsKey(name.toLowerCase());
	}

	public Object get(String name) throws PropertyException
	{
		Property p = getProperty(name);
		if (p != null)
			return get(p);
		throw new PropertyException("property not found - " + name);
	}

	public Object get(Property p)
	{
		return p.get();
	}

	public void set(String name, Object value) throws PropertyException
	{
		Property p = getProperty(name);
		if (p != null)
			set(p, value);
		else
			throw new PropertyException("property not found - " + name);
	}

	public void set(Property p, Object value) throws PropertyException
	{
		p.set(value);
	}

	/* TODO: remove me
	public void update(String name, Object value) throws PropertyException
	{
		Property p = getProperty(name);
		if (p != null)
			p.update(value);
		else
			throw new PropertyException("property not found - " + name);
	}
	*/

	public void show()
	{
		Iterator it = values().iterator();
		while (it.hasNext())
		{
			Property p = (Property)it.next();
			if (p.isVisible())
			{
				get(p); /* force any getter to execute */
				System.out.println("  " + p.getName() + " = " + p);
			}
		}
	}

	public void validate()
	{
		Iterator it = values().iterator();
		while (it.hasNext())
		{
			Property p = (Property)it.next();
			p.unLock();
		}
	}

	public String[] getNames()
	{
		List names = new ArrayList();
		Iterator it = values().iterator();
		while (it.hasNext())
		{
			Property p = (Property)it.next();
			if (p.isVisible())
				names.add(p.getName());
		}
		return (String[])names.toArray(new String[names.size()]);
	}

	public void delete()
	{
		Iterator it = values().iterator();
		while (it.hasNext())
			((Property)it.next()).delete();
	}
}
