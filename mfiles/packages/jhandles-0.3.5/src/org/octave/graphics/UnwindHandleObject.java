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

import java.util.HashMap;
import java.util.Map;
import java.util.Set;
import java.util.Iterator;

public class UnwindHandleObject
{
	private Map unwindMap;

	public UnwindHandleObject()
	{
		unwindMap = new HashMap();
	}

	private synchronized void swapValues()
	{
		Iterator it = unwindMap.entrySet().iterator();
		while (it.hasNext())
		{
			Map.Entry entry = (Map.Entry)it.next();
			Property p = (Property)entry.getKey();
			Object value = p.get();

			p.reset(entry.getValue());
			entry.setValue(value);
		}
	}

	public void start()
	{
		swapValues();
	}

	public void end()
	{
		swapValues();
		unwindMap.clear();
	}

	public synchronized void unwind(Property p, Object value)
	{
		unwindMap.put(p, value);
	}
}
