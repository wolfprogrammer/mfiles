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
import org.octave.Matrix;
import javax.swing.*;

public class CheckBoxControl
	extends JCheckBox
	implements UIControl, ActionListener
{
	private UIControlObject uiObj;
	private HandleEventSinkAdapter sink;

	public CheckBoxControl(UIControlObject obj)
	{
		super();
		addActionListener(this);
		uiObj = obj;

		setText(obj.UIString.toString());

		sink = new HandleEventSinkAdapter() {
			public void eventOccured(HandleEvent evt) throws PropertyException
			{ propertyChanged(evt.getProperty()); }
		};
		sink.listen(obj.UIString);
		sink.listen(obj.Value);
	}

	public void propertyChanged(Property p) throws PropertyException
	{
		if (p == uiObj.UIString)
			setText(uiObj.UIString.toString());
		else if (p == uiObj.Value)
		{
			double v = uiObj.Value.getArray()[0];
			setSelected(v == uiObj.Max.doubleValue());
		}
	}

	/* UIControl interface */

	public void update()
	{
		uiObj.Value.reset(isSelected() ? uiObj.Max.get() : uiObj.Min.get());
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
	}
}
