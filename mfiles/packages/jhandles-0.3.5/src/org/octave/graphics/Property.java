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

import java.awt.Color;
import java.util.LinkedList;
import java.util.Iterator;

/**Abstract root class for any kind of property*/
public abstract class Property implements HandleEventSource
{
	private String name;
	private HandleEventSourceHelper eventSource = new HandleEventSourceHelper(this, new String[] {"PropertyChanged"});
	private boolean lockNotify = true;
	private boolean readOnly = false;
	private boolean visible = true;
	private PropertySet parent;
	protected Object pvalue;

	private boolean setFlag = false;

	protected Property(Property p)
	{
		this.name = p.name;
		this.parent = null; /* do not copy parent */
		this.visible = p.visible;
		this.readOnly = p.readOnly;
		this.pvalue = p.pvalue;
	}

	protected Property(PropertySet parent, String name)
	{
		this.name = name;
		this.parent = parent;
		if (parent != null)
		{
			parent.addProperty(this);
			if (parent instanceof HandleObject &&
					!name.equalsIgnoreCase("parent") && !name.equalsIgnoreCase("type"))
				initDefault();
		}
	}

	protected void initDefault()
	{
		HandleObject parent = (HandleObject)getParent();
		String defname = "default" + parent.getType() + name;
		Property p = parent.getDefaultProperty(defname);

		if (p != null)
			pvalue = p.pvalue;
	}

	public abstract Property cloneProperty();

	public PropertySet getParent()
	{
		return parent;
	}

	public String getName()
	{
		return name;
	}

	public boolean isReadOnly()
	{
		return readOnly;
	}

	public void setReadOnly(boolean flag)
	{
		readOnly = flag;
	}

	public boolean isVisible()
	{
		return visible;
	}

	public void setVisible(boolean flag)
	{
		visible = flag;
	}

	protected Object getInternal()
	{
		return pvalue;
	}

	protected void setInternal(Object value) throws PropertyException
	{
		pvalue = value;
	}

	public Object get()
	{
		/* TODO: needed?
		if (!lockNotify)
		{
			Iterator it = listenerList.iterator();
			while (it.hasNext())
				((PropertyListener)it.next()).propertyGetting(this);
		}
		*/
		return getInternal();
	}

	public void set(Object value) throws PropertyException
	{
		if (readOnly)
			throw new PropertyException("read-only property - " + getName());

		value = convertValue(value);
		if (isEqual(value))
		{
			//System.out.println(getName() + ": identical value, not setting - " + value.toString());
			return;
		}

		if (setFlag)
		{
			System.out.println("WARNING: " + getName() + ".set (" + ((HandleObject)getParent()).getHandle() + "): recursive behavior detected, not setting");
			Thread.dumpStack();
			return;
		}

		setFlag = true;
		try
		{
			/* TODO: needed?
			if (!lockNotify)
			{
				Iterator it = listenerList.iterator();
				while (it.hasNext())
					((PropertyListener)it.next()).propertySetting(this, value);
			}
			*/
			setInternal(value);
			if (!lockNotify)
			{
				eventSource.fireEvent("PropertyChanged");
			}
			setFlag = false;
		}
		catch (Exception e)
		{
			setFlag = false;
			if (e instanceof PropertyException)
				throw (PropertyException)e;
			else
				throw new PropertyException(e);
		}
	}

	public void reset(Object value)
	{
		boolean oldLockNotify = lockNotify;

		lockNotify = true;
		try { set(value); }
		catch (PropertyException e)
		{
			System.err.println("WARNING: exception during property reset: " + e);
		}
		lockNotify = oldLockNotify;
	}

	public void set(Object value, boolean warn_on_exception)
	{
		try { set(value); }
		catch (PropertyException e)
		{
			if (warn_on_exception)
			{
				System.out.println("WARNING: " + getName() + ".set: exception occured");
				e.printStackTrace();
			}
		}
	}

	public void lock()
	{
		lockNotify = true;
	}

	public void unLock()
	{
		lockNotify = false;
	}

	public boolean isSameValue(Object value)
	{
		try
		{
			value = convertValue(value);
			return isEqual(value);
		}
		catch (PropertyException e)
		{
			return false;
		}
	}

	protected boolean isEqual(Object value)
	{
		/*Object v = getInternal();*/
		Object v = pvalue;
		return (value == null ? v == null : value.equals(v));
	}

	protected Object convertValue(Object value) throws PropertyException
	{
		return value;
	}

	public void delete()
	{
		eventSource.delete();
	}

	public static Property createProperty(PropertySet parent, String name, String type) throws PropertyException
	{
		if (type.equals("double"))
			return new DoubleProperty(parent, name);
		else if (type.equals("string"))
			return new StringProperty(parent, name);
		return null;
	}

	public static Property createProperty(PropertySet parent, String name, String type, Object arg) throws PropertyException
	{
		if (type.equals("radio"))
		{
			String[] values = ((String)arg).split("|");
			return new RadioProperty(parent, name, values, "");
		}
		else
		{
			Property p = createProperty(parent, name, type);
			if (p != null)
				p.set(arg);
			return p;
		}
	}

	/* HandleEventSource interface */

	public void addHandleEventSink(String name, HandleEventSink sink)
	{
		eventSource.addHandleEventSink(name, sink);
	}

	public void removeHandleEventSink(HandleEventSink sink)
	{
		eventSource.removeHandleEventSink(sink);
	}

	public boolean hasHandleEvent(String name)
	{
		return eventSource.hasHandleEvent(name);
	}
}
