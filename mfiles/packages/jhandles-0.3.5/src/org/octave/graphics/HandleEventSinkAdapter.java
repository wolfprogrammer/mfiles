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

public class HandleEventSinkAdapter implements HandleEventSink
{
	protected Set sourceSet = new HashSet();

	public HandleEventSinkAdapter()
	{
	}

	public void listen(Property p)
	{
		listen(p, "PropertyChanged");
	}

	public void listen(HandleEventSource source, String name)
	{
		source.addHandleEventSink(name, this);
		sourceSet.add(source);
	}

	public void dispose()
	{
		Iterator it = sourceSet.iterator();
		while (it.hasNext())
			((HandleEventSource)it.next()).removeHandleEventSink(this);
	}

	/* HandleEventSink interface */

	public void eventOccured(HandleEvent evt) throws PropertyException
	{
	}

	public void sourceDeleted(Object source)
	{
		sourceSet.remove(source);
	}

	public boolean executeOnce()
	{
		return false;
	}
}
