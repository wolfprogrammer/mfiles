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

import org.octave.OctaveReference;
import org.octave.Octave;

public class OctaveCallback extends Callback
{
	OctaveReference ref;
	String cmd;

	public OctaveCallback(OctaveReference ref)
	{
		this.ref = ref;
		this.cmd = null;
	}

	public OctaveCallback(String cmd)
	{
		this.ref = null;
		this.cmd = cmd;
	}

	public void execute(HandleObject parent, Object[] args)
	{
		if (ref == null && (cmd == null || cmd.length() == 0))
		{
			fireCallbackExecuted();
			return;
		}

		unwind(RootObject.getInstance().CallbackObject, parent);

		final RootObject root = RootObject.getInstance();
		final Object[] theArgs = args;
		final HandleObject theParent = parent;
		final UnwindHandleObject theUnwinder = unwinder;

		Octave.invokeLater(new Runnable() {
			public void run()
			{
				try
				{
					if (theUnwinder != null)
						theUnwinder.start();
					if (ref != null)
						Octave.doInvoke(ref.getID(), theArgs);
					else if (cmd != null && cmd.length() > 0)
						Octave.doEvalString(cmd);
				}
				catch (Exception e)
				{
					System.err.println("Exception occured during callback execution: " + e.toString());
					e.printStackTrace();
				}
				finally
				{
					if (theUnwinder != null)
						theUnwinder.end();
				}
				fireCallbackExecuted();
			}
		});
		unwinder = null;
	}

	public Object get()
	{
		if (ref != null)
			return ref;
		else
			return cmd;
	}

	public String toString()
	{
		if (ref != null)
			return ref.toString();
		else
			return cmd;
	}
}
