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

import java.awt.*;
import java.awt.event.*;
import javax.swing.*;

public class TextControl
	extends JLabel
	implements UIControl
{
	private UIControlObject uiObj;
	private HandleEventSinkAdapter sink;

	public TextControl(UIControlObject obj)
	{
		super();
		uiObj = obj;

		setText(stringToHTML(obj.UIString.toString()));
		setVerticalAlignment(SwingConstants.TOP);
		setHorizontalAlignment(getAlignment());
		setOpaque(true);

		sink = new HandleEventSinkAdapter() {
			public void eventOccured(HandleEvent evt) throws PropertyException
			{ propertyChanged(evt.getProperty()); }
		};
		sink.listen(obj.UIString);
		sink.listen(obj.HorizontalAlignment);
	}

	private String stringToHTML(String s)
	{
		if (s.indexOf('\n') < 0)
			return s;
		else
		{
			String[] lines = s.split("\\n");
			String result = "";

			for (int i=0; i<lines.length; i++)
				result += ("<p align=\"" + uiObj.HorizontalAlignment.getValue() +  "\">" + lines[i] + "</p>");
			return ("<html>" + result + "</html>");
		}
	}

	private int getAlignment()
	{
		if (uiObj.HorizontalAlignment.is("left"))
			return SwingConstants.LEFT;
		else if (uiObj.HorizontalAlignment.is("center"))
			return SwingConstants.CENTER;
		else if (uiObj.HorizontalAlignment.is("right"))
			return SwingConstants.RIGHT;
		return SwingConstants.LEFT;
	}

	public void propertyChanged(Property p) throws PropertyException
	{
		if (p == uiObj.HorizontalAlignment)
		{
			setHorizontalAlignment(getAlignment());
			setText(stringToHTML(uiObj.UIString.toString()));
		}
		else if (p == uiObj.UIString)
			setText(stringToHTML(uiObj.UIString.toString()));
	}

	/* UIControl interface */

	public void update()
	{
	}
	
	public JComponent getComponent()
	{
		return this;
	}

	public void dispose()
	{
		sink.dispose();
	}
}
