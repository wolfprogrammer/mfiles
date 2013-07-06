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
import java.awt.event.*;
import javax.swing.*;
import javax.swing.border.*;
import java.util.Iterator;

public class UIPanelObject extends AxesContainer
	implements ComponentListener
{
	private class PanelWrapper extends Panel
		implements Positionable
	{
		private UIPanelObject uiPanel;

		public PanelWrapper(UIPanelObject uiPanel)
		{
			super(new BorderLayout());
			this.uiPanel = uiPanel;
		}

		public double[] getPosition()
		{
			return uiPanel.getPosition();
		}
	}

	protected JPanel panel;
	protected Panel panelWrapper;
	private String currentUnits;

	/* Properties */
	ColorProperty BackgroundColor;
	RadioProperty BorderType;
	RadioProperty FontAngle;
	StringProperty FontName;
	DoubleProperty FontSize;
	RadioProperty FontUnits;
	RadioProperty FontWeight;
	ColorProperty ForegroundColor;
	ColorProperty HighlightColor;
	VectorProperty Position;
	CallbackProperty ResizeFcn;
	ColorProperty ShadowColor;
	StringProperty Title;
	RadioProperty TitlePosition;
	RadioProperty Units;

	public UIPanelObject(HandleObject parent)
	{
		super(parent, "uipanel", newHandle());

		BackgroundColor = new ColorProperty(this, "BackgroundColor", Utils.getBackgroundColor());
		BorderType = new RadioProperty(this, "BorderType", new String[] {"none", "etchedin", "etchedout",
			"beveledin", "beveledout", "line"}, "etchedin");
		FontAngle = new RadioProperty(this, "FontAngle", new String[] {"normal", "italic", "oblique"}, "normal");
		FontName = new StringProperty(this, "FontName", "Helvetica");
		FontSize = new DoubleProperty(this, "FontSize", 8);
		FontUnits = new RadioProperty(this, "FontUnits",
			new String[] {"points", "normalized", "inches", "centimeters", "pixels"}, "points");
		FontWeight = new RadioProperty(this, "FontWeight", new String[] {"light", "normal", "demi", "bold"}, "normal");
		ForegroundColor = new ColorProperty(this, "ForegroundColor", Color.black);
		HighlightColor = new ColorProperty(this, "HighlightColor", Utils.getHighlightColor());
		Position = new VectorProperty(this, "Position", 4, new double[] {0, 0, 1, 1});
		ResizeFcn = new CallbackProperty(this, "ResizeFcn", (String)null);
		ShadowColor = new ColorProperty(this, "ShadowColor", Utils.getShadowColor());
		Title = new StringProperty(this, "Title", "");
		TitlePosition = new RadioProperty(this, "TitlePosition", new String[] {
			"lefttop", "centertop", "righttop",
			"leftbottom", "centerbottom", "rightbottom"}, "lefttop");
		Units = new RadioProperty(this, "Units", new String[] {"pixels", "normalized", "characters",
			"inches", "centimeters", "points"}, "normalized");

		listen(BackgroundColor);
		listen(FontAngle);
		listen(FontName);
		listen(FontSize);
		listen(FontUnits);
		listen(FontWeight);
		listen(ForegroundColor);
		listen(HighlightColor);
		listen(Position);
		listen(ShadowColor);
		listen(Title);
		listen(TitlePosition);
		listen(Units);
	}

	protected void deleteComponent()
	{
		if (panel != null)
		{
			panelWrapper.getParent().remove(panelWrapper);
			panel = null;
			panelWrapper = null;
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
		makePanel();
		super.validate();
	}

	private Border makeBorder()
	{
		if (BorderType.is("etchedin"))
			return BorderFactory.createEtchedBorder(HighlightColor.getColor(), ShadowColor.getColor());
		else if (BorderType.is("etchedout"))
			return BorderFactory.createEtchedBorder(EtchedBorder.RAISED, HighlightColor.getColor(), ShadowColor.getColor());
		else if (BorderType.is("beveledin"))
			return BorderFactory.createBevelBorder(BevelBorder.LOWERED, HighlightColor.getColor(), ShadowColor.getColor());
		else if (BorderType.is("beveledout"))
			return BorderFactory.createBevelBorder(BevelBorder.RAISED, HighlightColor.getColor(), ShadowColor.getColor());
		else if (BorderType.is("line"))
			return BorderFactory.createLineBorder(ShadowColor.getColor());
		else
			return BorderFactory.createEmptyBorder();
	}

	public void makePanel()
	{
		TitledBorder border = BorderFactory.createTitledBorder(
				makeBorder(),
				Title.toString());
		String tPos = TitlePosition.getValue().toLowerCase();
		
		panel = new JPanel(new PositionLayout());
		panel.setBackground(BackgroundColor.getColor());
		panelWrapper = new PanelWrapper(this);
		panelWrapper.add(panel, BorderLayout.CENTER);
		border.setTitleFont(Utils.getFont(FontName, FontSize, FontUnits, FontAngle, FontWeight, panelWrapper.getHeight()));
		border.setTitleColor(ForegroundColor.getColor());
		border.setTitlePosition(tPos.contains("bottom") ? TitledBorder.BOTTOM : TitledBorder.TOP);
		border.setTitleJustification(
				tPos.contains("left") ? TitledBorder.LEFT :
				tPos.contains("center") ? TitledBorder.CENTER :
				tPos.contains("right") ? TitledBorder.RIGHT :
				TitledBorder.LEFT);
		panel.setBorder(border);
		panel.addComponentListener(this);

		Container pContainer = (Container)getParentComponent();
		pContainer.add(panelWrapper, 0);
		pContainer.validate();
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

	public Component getComponent()
	{
		return panel;
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

		if (panel != null)
		{
			TitledBorder border = (TitledBorder)panel.getBorder();

			if (p == BackgroundColor)
				panel.setBackground(BackgroundColor.getColor());
			else if (p == FontAngle || p == FontName || p == FontSize ||
					p == FontWeight || p == FontUnits)
			{
				border.setTitleFont(Utils.getFont(FontName, FontSize, FontUnits, FontAngle, FontWeight, panelWrapper.getHeight()));
				panel.doLayout();
				panel.validate();
			}
			else if (p == ForegroundColor)
				border.setTitleColor(ForegroundColor.getColor());
			else if (p == HighlightColor || p == ShadowColor)
				border.setBorder(BorderFactory.createEtchedBorder(HighlightColor.getColor(), ShadowColor.getColor()));
			else if (p == Position)
			{
				panelWrapper.getParent().doLayout();
				panelWrapper.getParent().validate();
			}
			else if (p == Title)
			{
				border.setTitle(Title.toString());
				panel.doLayout();
				panel.validate();
			}
			else if (p == TitlePosition)
			{
				String loc = TitlePosition.getValue().toLowerCase();

				border.setTitlePosition(loc.contains("bottom") ? TitledBorder.BOTTOM : TitledBorder.TOP);
				border.setTitleJustification(
						loc.contains("left") ? TitledBorder.LEFT :
						loc.contains("center") ? TitledBorder.CENTER :
						loc.contains("right") ? TitledBorder.RIGHT :
						TitledBorder.LEFT);
				panel.doLayout();
				panel.validate();
			}
			else if (p == Units)
			{
				double[] pos = Utils.convertPosition(Position.getArray(), currentUnits, Units.getValue(), getParentComponent());
				Position.set(pos, true);
				currentUnits = Units.getValue();
			}

			panel.repaint();
		}
	}

	protected Color getBackgroundColor()
	{
		return BackgroundColor.getColor();
	}

	protected Container getEmbeddingComponent()
	{
		return panel;
	}

	/* ComponentListener interface */

	public void componentHidden(ComponentEvent e) {}
	
	public void componentMoved(ComponentEvent e) {}
	
	public void componentResized(ComponentEvent e)
	{
		ResizeFcn.execute(new Object[] {
			new Double(getHandle()),
			null});
	}
	
	public void componentShown(ComponentEvent e) {}
}
