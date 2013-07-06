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

import org.octave.*;

public class OctaveSink
{
	private OctaveReference ref;
	private HandleEventSinkAdapter sink;
	private HandleObject parent;

	public OctaveSink(OctaveReference ref, HandleObject h, String[] pnames, HandleObject hp)
	{
		this.ref = ref;
		this.sink = new HandleEventSinkAdapter() {
			public void eventOccured(HandleEvent evt) throws PropertyException
			{
				if (OctaveSink.this.parent == null || !evt.getName().equals("ObjectDeleted") ||
						evt.getHandleObject() != OctaveSink.this.parent)
					OctaveSink.this.doInvoke(evt);
			}
			public void sourceDeleted(Object source)
			{
				super.sourceDeleted(source);
				if (source == OctaveSink.this.parent)
					OctaveSink.this.dispose();
			}
		};
		this.parent = (hp != null && hp != h ? hp : null);

		for (int i=0; i<pnames.length; i++)
		{
			Property p = h.getProperty(pnames[i]);
			if (p != null)
				this.sink.listen(p);
			else if (h.hasHandleEvent(pnames[i]))
				this.sink.listen(h, pnames[i]);
			else
				System.out.println("WARNING: `" + pnames[i] + "' is not a valid property name of " + h.Type.toString());
		}

		if (this.parent != null)
			this.sink.listen(this.parent, "ObjectDeleted");
	}

	public void doInvoke(HandleEvent evt)
	{
		HandleObject h = evt.getHandleObject();
		if (h != null)
			ref.invokeAndWait(new Object[] {new Double(h.getHandle()), null});
		else
			ref.invokeAndWait(new Object[] {null, evt});
	}

	public void dispose()
	{
		sink.dispose();
	}
}
