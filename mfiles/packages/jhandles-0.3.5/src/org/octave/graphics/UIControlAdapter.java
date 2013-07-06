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
import javax.swing.JComponent;

public class UIControlAdapter extends Panel
	implements Positionable, MouseListener
{
	private UIControl ctrl;
	private UIControlObject uiObj;
	private HandleEventSinkAdapter sink;

	public UIControlAdapter(UIControlObject obj) throws IllegalArgumentException
	{
		super(new BorderLayout());

		String style = obj.Style.toString();

		if (style.equalsIgnoreCase("pushbutton"))
			this.ctrl = new PushButtonControl(obj);
		else if (style.equalsIgnoreCase("edit"))
		{
			if ((obj.Max.doubleValue()-obj.Min.doubleValue()) <= 1.0)
				this.ctrl = new EditControl(obj);
			else
				this.ctrl = new Edit2Control(obj);
		}
		else if (style.equalsIgnoreCase("popupmenu"))
			this.ctrl = new PopupMenuControl(obj);
		else if (style.equalsIgnoreCase("text"))
			this.ctrl = new TextControl(obj);
		else if (style.equalsIgnoreCase("listbox"))
			this.ctrl = new ListBoxControl(obj);
		else if (style.equalsIgnoreCase("checkbox"))
			this.ctrl = new CheckBoxControl(obj);
		else
			throw new IllegalArgumentException("unsupported UI style `" + style + "'");
		this.uiObj = obj;
		init();
		add((JComponent)ctrl, BorderLayout.CENTER);

		sink = new HandleEventSinkAdapter() {
			public void eventOccured(HandleEvent evt) throws PropertyException
			{ propertyChanged(evt.getProperty()); }
		};
		sink.listen(obj.Position);
		sink.listen(obj.BackgroundColor);
		sink.listen(obj.ForegroundColor);
		sink.listen(obj.FontAngle);
		sink.listen(obj.FontName);
		sink.listen(obj.FontSize);
		sink.listen(obj.FontWeight);
		sink.listen(obj.TooltipString);
		sink.listen(obj.Enable);
	}

	private void init()
	{
		JComponent comp1 = ctrl.getComponent();

		comp1.setBackground(uiObj.BackgroundColor.getColor());
		comp1.setForeground(uiObj.ForegroundColor.getColor());
		double[] pos = uiObj.getPosition();
		setBounds((int)pos[0], (int)pos[1], (int)pos[2], (int)pos[3]);
		if (uiObj.TooltipString.toString().length() > 0)
			comp1.setToolTipText(uiObj.TooltipString.toString());
		comp1.setFont(Utils.getFont(uiObj.FontName, uiObj.FontSize, uiObj.FontUnits,
				uiObj.FontAngle, uiObj.FontWeight, getHeight()));
		comp1.setEnabled(!uiObj.Enable.is("off"));
		comp1.addMouseListener(this);
	}

	public void update() { if (ctrl != null) ctrl.update(); }

	public void dispose()
	{
		if (ctrl != null)
			ctrl.dispose();
		if (getParent() != null)
			getParent().remove(this);
		sink.dispose();
	}

	public Component getComponent()
	{
		return ctrl.getComponent();
	}

	public void propertyChanged(Property p) throws PropertyException
	{
		if (ctrl != null)
		{
			JComponent comp1 = ctrl.getComponent();

			if (p == uiObj.BackgroundColor)
				comp1.setBackground(uiObj.BackgroundColor.getColor());
			else if (p == uiObj.ForegroundColor)
				comp1.setForeground(uiObj.ForegroundColor.getColor());
			else if (p == uiObj.Position)
			{
				getParent().doLayout();
				getParent().validate();
				if (uiObj.FontUnits.is("normalized"))
					comp1.setFont(Utils.getFont(uiObj.FontName, uiObj.FontSize, uiObj.FontUnits,
						uiObj.FontAngle, uiObj.FontWeight, getHeight()));
			}
			else if (p == uiObj.FontAngle || p == uiObj.FontSize || p == uiObj.FontWeight || p == uiObj.FontName)
				comp1.setFont(Utils.getFont(uiObj.FontName, uiObj.FontSize, uiObj.FontUnits,
					uiObj.FontAngle, uiObj.FontWeight, getHeight()));
			else if (p == uiObj.TooltipString)
			{
				if (uiObj.TooltipString.toString().length() > 0)
					comp1.setToolTipText(uiObj.TooltipString.toString());
				else
					comp1.setToolTipText(null);
			}
			else if (p == uiObj.Enable)
				comp1.setEnabled(!uiObj.Enable.is("off"));
		}
	}

	/* Positionable interface */

	public double[] getPosition()
	{
		return uiObj.getPosition();
	}

	/* MouseListener interface */

	public void mouseClicked(MouseEvent e) {}
	
	public void mouseEntered(MouseEvent e) {}
	
	public void mouseExited(MouseEvent e) {}
	
	public void mousePressed(MouseEvent e)
	{
		boolean doCB = false;

		switch (e.getButton())
		{
			case MouseEvent.BUTTON2:
			case MouseEvent.BUTTON3:
				doCB = true;
				break;
			case MouseEvent.BUTTON1:
				doCB = !uiObj.Enable.is("on");
				break;
		}

		if (doCB)
			uiObj.doButtonDownFcn(e);
	}
	
	public void mouseReleased(MouseEvent e) {}
}
