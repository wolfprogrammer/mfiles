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

import org.octave.Matrix;
import java.awt.*;

public class UIControlObject extends HandleObject
{
	private UIControlAdapter ctrl;
	private String currentUnits;
	private boolean flag = false;

	/* Properties */
	ColorProperty BackgroundColor;
	CallbackProperty Callback;
	RadioProperty Enable;
	VectorProperty Extent;
	RadioProperty FontAngle;
	StringProperty FontName;
	DoubleProperty FontSize;
	RadioProperty FontUnits;
	RadioProperty FontWeight;
	ColorProperty ForegroundColor;
	RadioProperty HorizontalAlignment;
	DoubleProperty ListboxTop;
	DoubleProperty Min;
	DoubleProperty Max;
	VectorProperty Position;
	VectorProperty SliderStep;
	StringProperty UIString;
	RadioProperty Style;
	StringProperty TooltipString;
	RadioProperty Units;
	VectorProperty Value;

	public UIControlObject(HandleObject parent)
	{
		super(parent, "uicontrol");

		BackgroundColor = new ColorProperty(this, "BackgroundColor");
		Callback = new CallbackProperty(this, "Callback", (String)null);
		Enable = new RadioProperty(this, "Enable", new String[] {"on", "inactive", "off"});
		Extent = new VectorProperty(this, "Extent", 4, new double[] {0, 0, 0, 0});
		FontAngle = new RadioProperty(this, "FontAngle", new String[] {"normal", "italic", "oblique"});
		FontName = new StringProperty(this, "FontName");
		FontSize = new DoubleProperty(this, "FontSize");
		FontUnits = new RadioProperty(this, "FontUnits",
			new String[] {"points", "normalized", "inches", "centimeters", "pixels"});
		FontWeight = new RadioProperty(this, "FontWeight", new String[] {"light", "normal", "demi", "bold"});
		ForegroundColor = new ColorProperty(this, "ForegroundColor");
		HorizontalAlignment = new RadioProperty(this, "HorizontalAlignment", new String[] {"left", "center", "right"});
		ListboxTop = new DoubleProperty(this, "ListboxTop", 1);
		Min = new DoubleProperty(this, "Min");
		Max = new DoubleProperty(this, "Max");
		Position = new VectorProperty(this, "Position", 4);
		UIString = new StringProperty(this, "String");
		SliderStep = new VectorProperty(this, "SliderStep", 2);
		Style = new RadioProperty(this, "Style", new String[] {
			  "pushbutton",
			  "togglebutton",
			  "radiobutton",
			  "checkbox",
			  "edit",
			  "text",
			  "slider",
			  "frame",
			  "listbox",
			  "popupmenu"});
		TooltipString = new StringProperty(this, "TooltipString");
		Units = new RadioProperty(this, "Units", new String[] {"pixels", "normalized", "characters", "inches",
			"centimeters", "points"});
		Value = new VectorProperty(this, "Value", -1, new double[] {0});

		listen(FontUnits);
		listen(Style);
		listen(Units);
	}

	protected void deleteComponent()
	{
		if (ctrl != null)
		{
			ctrl.dispose();
			ctrl = null;
		}
	}

	public void delete()
	{
		super.delete();
		deleteComponent();
	}

	public void validate()
	{
		deleteComponent();
		currentUnits = Units.getValue();
		ctrl = makeControl();
		super.validate();
	}

	public UIControlAdapter makeControl()
	{
		deleteComponent();

		try { ctrl = new UIControlAdapter(this); }
		catch (Exception e)
		{
			System.out.println("Warning: unable to create UI control");
			e.printStackTrace();
			return null;
		}

		Container pContainer = (Container)getParentComponent();

		pContainer.add(ctrl, 0);
		pContainer.validate();

		return ctrl;
	}

	public double[] getPosition()
	{
		Component pComp = getParentComponent();
		if (pComp != null)
			return Utils.convertPosition(Position.getArray(), Units.getValue(), "pixels", pComp);
		else
		{
			System.out.println("Warning: cannot compute position of parentless controls");
			return new double[] {0, 0, 0, 0};
		}
	}

	public Rectangle getBounds()
	{
		return (ctrl != null ? ctrl.getBounds() : new Rectangle());
	}

	public Component getComponent()
	{
		if (ctrl != null)
			return ctrl.getComponent();
		else
			return null;
	}

	public Component getParentComponent()
	{
		if (Parent.size() > 0)
		{
			HandleObject obj = Parent.elementAt(0);
			return obj.getComponent();
		}
		else
			return null;
	}

	public void propertyChanged(Property p) throws PropertyException
	{
		super.propertyChanged(p);

		if (p == Style)
		{
		}
		else if (ctrl != null)
		{
			if (p == Units)
			{
				double[] pos = Utils.convertPosition(Position.getArray(), currentUnits, Units.getValue(), getParentComponent());
				Position.set(pos, true);
				currentUnits = Units.getValue();
			}
			else if (p == FontUnits)
			{
			}
			
		}
	}

	public Object get(Property p)
	{
		if (ctrl != null)
			ctrl.update();

		if (p == UIString && (Style.is("listbox") || Style.is("popupmenu")))
			return UIString.toString().split("\\|");
		else
			return super.get(p);
	}

	public void set(Property p, Object value) throws PropertyException
	{
		if (ctrl != null)
			ctrl.update();

		if (p == UIString && value != null)
		{
			try
			{
				String[] items = (String[])value;
				if (Style.is("listbox") || Style.is("popupmenu"))
					value = Utils.join(items, "|");
				else if (Style.is("text") || (Style.is("edit") && (Max.doubleValue()-Min.doubleValue()) > 1))
					value = Utils.join(items, "\n");
				else
					value = (items.length > 0 ? items[0] : "");
			}
			catch (ClassCastException e) {}
		}
		super.set(p, value);
	}

	/* UIControlListener interface */

	public void controlActivated(UIControlEvent event)
	{
		if (isValid() && Enable.is("on"))
		{
			//System.out.println("Control activated");
			Callback.execute(new Object[] {
				new Double(getHandle()),
				event});
		}
	}
}
