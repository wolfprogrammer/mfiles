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
import javax.swing.text.Document;
import javax.swing.event.DocumentEvent;
import javax.swing.event.DocumentListener;

public class EditControl
	extends JTextField
	implements UIControl, ActionListener,
		   DocumentListener, FocusListener
{
	UIControlObject uiObj;
	HandleEventSinkAdapter sink;

	private boolean contentChanged = false;

	public EditControl(UIControlObject obj)
	{
		super();
		addActionListener(this);
		addFocusListener(this);
		getDocument().addDocumentListener(this);
		uiObj = obj;

		setAlignment();
		setText(obj.UIString.toString());

		sink = new HandleEventSinkAdapter() {
			public void eventOccured(HandleEvent evt) throws PropertyException
			{ propertyChanged(evt.getProperty()); }
		};
		sink.listen(obj.UIString);
		sink.listen(obj.HorizontalAlignment);
	}

	public void setAlignment()
	{
		setHorizontalAlignment(
			uiObj.HorizontalAlignment.is("center") ? JTextField.CENTER :
			uiObj.HorizontalAlignment.is("left") ? JTextField.LEFT :
			uiObj.HorizontalAlignment.is("right") ? JTextField.RIGHT :
			JTextField.LEFT);
	}

	public void propertyChanged(Property p) throws PropertyException
	{
		if (p == uiObj.UIString)
			setText(uiObj.UIString.toString());
		else if (p == uiObj.HorizontalAlignment)
			setAlignment();
	}

	/* UIControl interface */

	public void update()
	{
		uiObj.UIString.reset(getText());
	}

	public JComponent getComponent()
	{
		return this;
	}

	public void dispose()
	{
		sink.dispose();
	}

	/* ActionListener interface */

	public void actionPerformed(ActionEvent event)
	{
		uiObj.controlActivated(new UIControlEvent(this));
		contentChanged = false;
	}

	/* DocumentListener interface */

	public void changedUpdate(DocumentEvent e) {}

	public void insertUpdate(DocumentEvent e)
	{
		contentChanged = true;
	}

	public void removeUpdate(DocumentEvent e)
	{
		contentChanged = true;
	}

	/* FocusListener interface */

	public void focusGained(FocusEvent e)
	{
		contentChanged = false;
	}

	public void focusLost(FocusEvent e)
	{
		if (contentChanged)
		{
			uiObj.controlActivated(new UIControlEvent(this));
			contentChanged = false;
		}
	}
}
