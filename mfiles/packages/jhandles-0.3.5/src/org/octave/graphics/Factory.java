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
import javax.swing.UIManager;
import org.octave.Matrix;

public class Factory extends PropertySet
{
	static
	{
		try
		{
			UIManager.setLookAndFeel(UIManager.getSystemLookAndFeelClassName());
		}
		catch (Exception e)
		{
			System.out.println("Warning: unable to initialize Swing look and feel");
		}
	}

	private static Factory self = new Factory();

	private Factory()
	{
		initLineProperties();
		initUIControlProperties();
	}

	private void initLineProperties()
	{
		// BeingDeleted
		new RadioProperty(this, "DefaultLineBusyAction", new String[] {"cancel", "queue"}, "queue");
		new CallbackProperty(this, "DefaultLineButtonDownFcn", (String)null);
		// Children
		new BooleanProperty(this, "DefaultLineClipping", true);
		new ColorProperty(this, "DefaultLineColor", Color.black);
		new CallbackProperty(this, "DefaultLineCreateFcn", (String)null);
		new CallbackProperty(this, "DefaultLineDeleteFcn", (String)null);
		new RadioProperty(this, "DefaultLineEraseMode", new String[] {"normal", "none", "xor", "background"}, "normal");
		new RadioProperty(this, "DefaultLineHandleVisibility", new String[] {"on", "callback", "off"}, "on");
		new BooleanProperty(this, "DefaultLineHitTest", true);
		new BooleanProperty(this, "DefaultLineInterruptible", true);
		new LineStyleProperty(this, "DefaultLineLineStyle", "-");
		new DoubleProperty(this, "DefaultLineLineWidth", 0.5);
		new MarkerProperty(this, "DefaultLineMarker", "none");
		new ColorProperty(this, "DefaultLineMarkerEdgeColor", new String[] {"none", "auto"}, "auto");
		new ColorProperty(this, "DefaultLineMarkerFaceColor", new String[] {"none", "auto"}, "none");
		new DoubleProperty(this, "DefaultLineMarkerSize", 6);
		// Parent
		// Selected
		new BooleanProperty(this, "DefaultLineSelectionHighlight", true);
		new StringProperty(this, "DefaultLineTag", "");
		// Type
		// UIContextMenu
		new ObjectProperty(this, "DefaultLineUserData", null);
		new BooleanProperty(this, "DefaultLineVisible", true);
		new VectorProperty(this, "DefaultLineXData", -1, new double[] {0, 1});
		new VectorProperty(this, "DefaultLineYData", -1, new double[] {0, 1});
		new VectorProperty(this, "DefaultLineZData", -1, new Matrix());
	}

	private void initUIControlProperties()
	{
		// BeingDeleted
		new ColorProperty(this, "DefaultUIControlBackgroundColor", (Color)Utils.getBackgroundColor());
		new RadioProperty(this, "DefaultUIControlBusyAction", new String[] {"cancel", "queue"}, "queue");
		new CallbackProperty(this, "DefaultUIControlButtonDownFcn", (String)null);
		// Callback
		new ArrayProperty(this, "DefaultUIControlCData", new String[] {"double"}, 3, new Matrix());
		// Children
		new BooleanProperty(this, "DefaultUIControlClipping", true);
		new CallbackProperty(this, "DefaultUIControlCreateFcn", (String)null);
		new CallbackProperty(this, "DefaultUIControlDeleteFcn", (String)null);
		new RadioProperty(this, "DefaultUIControlEnable", new String[] {"on", "inactive", "off"}, "on");
		// Extent
		new RadioProperty(this, "DefaultUIControlFontAngle", new String[] {"normal", "italic", "oblique"}, "normal");
		new StringProperty(this, "DefaultUIControlFontName", "Helvetica");
		new DoubleProperty(this, "DefaultUIControlFontSize", 8);
		new RadioProperty(this, "DefaultUIControlFontUnits",
			new String[] {"points", "normalized", "inches", "centimeters", "pixels"}, "points");
		new RadioProperty(this, "DefaultUIControlFontWeight", new String[] {"light", "normal", "demi", "bold"}, "normal");
		new ColorProperty(this, "DefaultUIControlForegroundColor", Color.black);
		new RadioProperty(this, "DefaultUIControlHandleVisibility", new String[] {"on", "callback", "off"}, "on");
		new BooleanProperty(this, "DefaultUIControlHitTest", true);
		new RadioProperty(this, "DefaultUIControlHorizontalAlignment", new String[] {"left", "center", "right"}, "center");
		new BooleanProperty(this, "DefaultUIControlInterruptible", true);
		new CallbackProperty(this, "DefaultUIControlKeyPressFcn", (String)null);
		// ListboxTop
		new DoubleProperty(this, "DefaultUIControlMax", 1.0);
		new DoubleProperty(this, "DefaultUIControlMin", 0.0);
		// Parent
		new VectorProperty(this, "DefaultUIControlPosition", 4, new double[] {10, 10, 80, 24});
		// Selected
		new BooleanProperty(this, "DefaultUIControlSelectionHighlight", true);
		new VectorProperty(this, "DefaultUIControlSliderStep", 2, new double[] {0.01, 0.10});
		new StringProperty(this, "DefaultUIControlString", "");
		new RadioProperty(this, "DefaultUIControlStyle", new String[] {"pushbutton", "togglebutton", "radiobutton",
			"checkbox", "text", "edit", "slider", "frame", "listbox", "popupmenu"}, "pushbutton");
		new StringProperty(this, "DefaultUIControlTag", "");
		new StringProperty(this, "DefaultUIControlTooltipString", "");
		new RadioProperty(this, "DefaultUIControlUnits",
			new String[] {"pixels", "normalized", "inches", "centimeters", "points", "characters"}, "pixels");
		new ObjectProperty(this, "DefaultUIControlUserData", null);
		new BooleanProperty(this, "DefaultUIControlVisible", true);
	}

	public static Property getDefaultProperty(String name)
	{
		return self.getProperty(name);
	}
}
