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

import java.util.EventObject;

public class HandleEvent extends EventObject
{
	private String name;

	public HandleEvent(Object source, String name)
	{
		super(source);
		this.name = name;
	}

	public String getName()
	{
		return name;
	}

	public HandleObject getHandleObject()
	{
		Object obj = getSource();
		if (obj instanceof HandleObject)
			return (HandleObject)obj;
		else if (obj instanceof Property)
		{
			obj = ((Property)obj).getParent();
			if (obj instanceof HandleObject)
				return (HandleObject)obj;
		}
		return null;
	}

	public Property getProperty()
	{
		Object obj = getSource();
		if (obj instanceof Property)
			return (Property)obj;
		return null;
	}
}
