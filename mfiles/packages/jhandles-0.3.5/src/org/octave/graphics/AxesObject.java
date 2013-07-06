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
import java.util.*;
import org.octave.Matrix;

public class AxesObject extends HandleObject
{
	public interface Scaler
	{
		public double scale(double x);
		public double[] scale(double[] x);
		public double[][] scale(double[][] x);
		public double unscale(double x);
		public boolean isLinear();
	}

	private class LinearScaler implements Scaler
	{
		public double scale(double x) { return x; }
		public double[] scale(double[] x) { return x; }
		public double[][] scale(double[][] x) { return x; }
		public double unscale(double x) { return x; }
		public boolean isLinear() { return true; }
	}

	private class LogScaler implements Scaler
	{
		public double scale(double x)
		{
			return Math.log10(x);
		}

		public double[] scale(double[] x)
		{
			double[] y = new double[x.length];
			for (int i=0; i<x.length; i++)
				y[i] = Math.log10(x[i]);
			return y;
		}

		public double[][] scale(double[][] x)
		{
			double[][] y = new double[x.length][x.length > 0 ? x[0].length : 0];
			for (int i=0; i<x.length; i++)
				for (int j=0; j<x[0].length; j++)
					y[i][j] = Math.log10(x[i][j]);
			return y;
		}
		
		public double unscale(double x)
		{
			return Math.pow(10, x);
		}

		public boolean isLinear()
		{
			return false;
		}
	}

	private String currentUnits;
	// TODO: remove
	//protected int autoMode = 0;

	LegendObject legend;
	ColorbarObject colorbar;
	BaseLineObject baseLine;

	private final int AXE_ANY_DIR = 0;
	private final int AXE_DEPTH_DIR = 1;
	private final int AXE_HORZ_DIR = 2;
	private final int AXE_VERT_DIR = 3;

	private int xstate = 3;
	private int ystate = 3;
	private int zstate = 3;

	private double xticklen;
	private double yticklen;
	private double zticklen;

	private int xPrev, yPrev, xAnchor, yAnchor;
	private boolean zoomBox = false;
	private Stack zoomStack = new Stack();
	private Rectangle boundingBox;
	protected boolean alwaysDrawBox = true;
	Scaler sx, sy, sz, linScale, logScale;
	private double[] x_minorTicks;
	private double[] y_minorTicks;
	private double[] z_minorTicks;
	private boolean x_logTickLabels;
	private boolean y_logTickLabels;
	private boolean z_logTickLabels;

	/* properties */
	RadioProperty ActivePositionProperty;
	VectorProperty Position;
	VectorProperty OuterPosition;
	RadioProperty Units;
	RadioProperty Projection;
	ColorProperty AxesColor;
	ColorProperty XColor;
	ColorProperty YColor;
	ColorProperty ZColor;
	VectorProperty XLim;
	VectorProperty YLim;
	VectorProperty ZLim;
	RadioProperty XLimMode;
	RadioProperty YLimMode;
	RadioProperty ZLimMode;
	BooleanProperty XGrid;
	BooleanProperty YGrid;
	BooleanProperty ZGrid;
	BooleanProperty XMinorGrid;
	BooleanProperty YMinorGrid;
	BooleanProperty ZMinorGrid;
	LineStyleProperty GridLineStyle;
	LineStyleProperty MinorGridLineStyle;
	VectorProperty XTick;
	VectorProperty YTick;
	VectorProperty ZTick;
	RadioProperty XTickMode;
	RadioProperty YTickMode;
	RadioProperty ZTickMode;
	StringArrayProperty XTickLabel;
	StringArrayProperty YTickLabel;
	StringArrayProperty ZTickLabel;
	RadioProperty XTickLabelMode;
	RadioProperty YTickLabelMode;
	RadioProperty ZTickLabelMode;
	BooleanProperty XMinorTick;
	BooleanProperty YMinorTick;
	BooleanProperty ZMinorTick;
	RadioProperty NextPlot;
	BooleanProperty Box;
	RadioProperty TickDir;
	RadioProperty TickDirMode;
	VectorProperty CameraTarget;
	RadioProperty CameraTargetMode;
	VectorProperty CameraPosition;
	RadioProperty CameraPositionMode;
	VectorProperty CameraUpVector;
	RadioProperty CameraUpVectorMode;
	DoubleProperty CameraViewAngle;
	RadioProperty CameraViewAngleMode;
	VectorProperty DataAspectRatio;
	RadioProperty DataAspectRatioMode;
	VectorProperty PlotBoxAspectRatio;
	RadioProperty PlotBoxAspectRatioMode;
	VectorProperty View;
	TextProperty Title;
	TextProperty XLabel;
	TextProperty YLabel;
	TextProperty ZLabel;
	VectorProperty CLim;
	RadioProperty CLimMode;
	VectorProperty ALim;
	RadioProperty ALimMode;
	RadioProperty XDir;
	RadioProperty YDir;
	RadioProperty ZDir;
	ArrayProperty x_NormRenderTransform;
	ArrayProperty x_RenderTransform;
	ArrayProperty x_ViewTransform;
	ArrayProperty x_ProjectionTransform;
	ArrayProperty x_ViewportTransform;
	RadioProperty XScale;
	RadioProperty YScale;
	RadioProperty ZScale;
	RadioProperty XAxisLocation;
	RadioProperty YAxisLocation;
	RadioProperty Layer;
	BooleanProperty Key;
	DoubleProperty LineWidth;
	ArrayProperty ColorOrder;
	RadioProperty FontAngle;
	StringProperty FontName;
	DoubleProperty FontSize;
	RadioProperty FontWeight;
	RadioProperty FontUnits;

	public AxesObject(HandleObject parent, boolean init3D)
	{
		super(parent, "axes");

		double[] angles;
		if (init3D)
			angles = new double[] { -37.5, 30.0 };
		else
			angles = new double[] { 0.0, 90.0 };

		linScale = new LinearScaler();
		logScale = new LogScaler();

		ActivePositionProperty = new RadioProperty(this, "ActivePositionProperty", new String[] {"outerposition", "position"}, "outerposition");
		Position = new VectorProperty(this, "Position", 4, new double[] {0.13,0.11,0.775,0.815});
		OuterPosition = new VectorProperty(this, "OuterPosition", 4, new double[] {0,0,1,1});
		Units = new RadioProperty(this, "Units",
			new String[] { "pixels", "normalized", "characters", "inches", "centimeters", "points" }, "normalized");
		currentUnits = "normalized";
		Projection = new RadioProperty(this, "Projection", new String[] { "orthogonal", "perspective" }, "orthogonal");
		AxesColor = new ColorProperty(this, "Color", new String[] {"none"}, Color.white);
		XColor = new ColorProperty(this, "XColor", Color.black);
		YColor = new ColorProperty(this, "YColor", Color.black);
		ZColor = new ColorProperty(this, "ZColor", Color.black);
		XLim = new VectorProperty(this, "XLim", 2, new double[] {0.0, 1.0});
		XLimMode = new RadioProperty(this, "XLimMode", new String[] {"auto", "manual"}, "auto");
		YLim = new VectorProperty(this, "YLim", 2, new double[] {0.0, 1.0});
		YLimMode = new RadioProperty(this, "YLimMode", new String[] {"auto", "manual"}, "auto");
		ZLim = new VectorProperty(this, "ZLim", 2, new double[] {-0.5, 0.5});
		ZLimMode = new RadioProperty(this, "ZLimMode", new String[] {"auto", "manual"}, "auto");
		XGrid = new BooleanProperty(this, "XGrid", false);
		YGrid = new BooleanProperty(this, "YGrid", false);
		ZGrid = new BooleanProperty(this, "ZGrid", false);
		XMinorGrid = new BooleanProperty(this, "XMinorGrid", false);
		YMinorGrid = new BooleanProperty(this, "YMinorGrid", false);
		ZMinorGrid = new BooleanProperty(this, "ZMinorGrid", false);
		GridLineStyle = new LineStyleProperty(this, "GridLineStyle", ":");
		MinorGridLineStyle = new LineStyleProperty(this, "MinorGridLineStyle", ":");
		XTick = new VectorProperty(this, "XTick", -1, new double[0]);
		YTick = new VectorProperty(this, "YTick", -1, new double[0]);
		ZTick = new VectorProperty(this, "ZTick", -1, new double[0]);
		XTickMode = new RadioProperty(this, "XTickMode", new String[] {"auto", "manual"}, "auto");
		YTickMode = new RadioProperty(this, "YTickMode", new String[] {"auto", "manual"}, "auto");
		ZTickMode = new RadioProperty(this, "ZTickMode", new String[] {"auto", "manual"}, "auto");
		XTickLabel = new StringArrayProperty(this, "XTickLabel", new String[0]);
		YTickLabel = new StringArrayProperty(this, "YTickLabel", new String[0]);
		ZTickLabel = new StringArrayProperty(this, "ZTickLabel", new String[0]);
		XTickLabelMode = new RadioProperty(this, "XTickLabelMode", new String[] {"auto", "manual"}, "auto");
		YTickLabelMode = new RadioProperty(this, "YTickLabelMode", new String[] {"auto", "manual"}, "auto");
		ZTickLabelMode = new RadioProperty(this, "ZTickLabelMode", new String[] {"auto", "manual"}, "auto");
		NextPlot = new RadioProperty(this, "NextPlot", new String[] {"replace", "add"}, "replace");
		Box = new BooleanProperty(this, "Box", (init3D ? false : true));
		TickDir = new RadioProperty(this, "TickDir", new String[] {"in", "out"}, (init3D ? "out" : "in"));
		TickDirMode = new RadioProperty(this, "TickDirMode", new String[] {"auto", "manual"}, "auto");
		CameraTarget = new VectorProperty(this, "CameraTarget", 3, new double[] {0.0,0.0,0.0});
		CameraTargetMode = new RadioProperty(this, "CameraTargetMode", new String[] {"auto", "manual"}, "auto");
		CameraPosition = new VectorProperty(this, "CameraPosition", 3, new double[] {0.0,0.0,0.0});
		CameraPositionMode = new RadioProperty(this, "CameraPositionMode", new String[] {"auto", "manual"}, "auto");
		CameraUpVector = new VectorProperty(this, "CameraUpVector", 3, new double[] {0,1,0});
		CameraUpVectorMode = new RadioProperty(this, "CameraUpVectorMode", new String[] {"auto", "manual"}, "auto");
		CameraViewAngle = new DoubleProperty(this, "CameraViewAngle", 10.0);
		CameraViewAngleMode = new RadioProperty(this, "CameraViewAngleMode", new String[] {"auto", "manual"}, "auto");
		DataAspectRatio = new VectorProperty(this, "DataAspectRatio", 3, new double[] {1,1,1});
		DataAspectRatioMode = new RadioProperty(this, "DataAspectRatioMode", new String[] {"auto", "manual"}, "auto");
		PlotBoxAspectRatio = new VectorProperty(this, "PlotBoxAspectRatio", 3, new double[] {1,1,1});
		PlotBoxAspectRatioMode = new RadioProperty(this, "PlotBoxAspectRatioMode", new String[] {"auto", "manual"}, "auto");
		View = new VectorProperty(this, "View", 2, angles);
		Title = new TextProperty(this, "Title", makeTextObject("center", "bottom"));
		XLabel = new TextProperty(this, "XLabel", makeTextObject((init3D ? "left" : "center"), "top"));
		YLabel = new TextProperty(this, "YLabel", makeTextObject((init3D ? "right" : "center"), (init3D ? "top" : "bottom")));
		ZLabel = new TextProperty(this, "ZLabel", makeTextObject((init3D ? "right" : "center"), (init3D ? "top" : "bottom")));
		CLim = new VectorProperty(this, "CLim", 2, new double[] {0, 1});
		CLimMode = new RadioProperty(this, "CLimMode", new String[] {"auto", "manual"}, "auto");
		ALim = new VectorProperty(this, "ALim", 2, new double[] {0, 1});
		ALimMode = new RadioProperty(this, "ALimMode", new String[] {"auto", "manual"}, "auto");
		XDir = new RadioProperty(this, "XDir", new String[] {"normal", "reverse"}, "normal");
		YDir = new RadioProperty(this, "YDir", new String[] {"normal", "reverse"}, "normal");
		ZDir = new RadioProperty(this, "ZDir", new String[] {"normal", "reverse"}, "normal");
		x_NormRenderTransform = new ArrayProperty(this, "x_NormRenderTransform", new String[] {"double"}, 2,
			new Matrix(new double[16], new int[] {4, 4}));
		x_RenderTransform = new ArrayProperty(this, "x_RenderTransform", new String[] {"double"}, 2,
			new Matrix(new double[16], new int[] {4, 4}));
		x_ViewTransform = new ArrayProperty(this, "x_ViewTransform", new String[] {"double"}, 2,
			new Matrix(new double[16], new int[] {4, 4}));
		x_ProjectionTransform = new ArrayProperty(this, "x_ProjectionTransform", new String[] {"double"}, 2,
			new Matrix(new double[16], new int[] {4, 4}));
		x_ViewportTransform = new ArrayProperty(this, "x_ViewportTransform", new String[] {"double"}, 2,
			new Matrix(new double[16], new int[] {4, 4}));
		XScale = new RadioProperty(this, "XScale", new String[] {"linear", "log"}, "linear");
		YScale = new RadioProperty(this, "YScale", new String[] {"linear", "log"}, "linear");
		ZScale = new RadioProperty(this, "ZScale", new String[] {"linear", "log"}, "linear");
		XMinorTick = new BooleanProperty(this, "XMinorTick", false);
		YMinorTick = new BooleanProperty(this, "YMinorTick", false);
		ZMinorTick = new BooleanProperty(this, "ZMinorTick", false);
		XAxisLocation = new RadioProperty(this, "XAxisLocation", new String[] {"bottom", "top", "zero"}, "bottom");
		YAxisLocation = new RadioProperty(this, "YAxisLocation", new String[] {"left", "right", "zero"}, "left");
		Layer = new RadioProperty(this, "Layer", new String[] {"bottom", "top"}, "bottom");
		Key = new BooleanProperty(this, "Key", false);
		Key.setVisible(false);
		LineWidth = new DoubleProperty(this, "LineWidth", 0.5);
		ColorOrder = new ArrayProperty(this, "ColorOrder", new String[] {"double"}, 2,
			new Matrix(
				new double[] {
					0,    0,  1,     0,  0.75,  0.75,  0.25,
					0,  0.5,  0,  0.75,     0,  0.75,  0.25,
					1,    0,  0,  0.75,  0.75,     0,  0.25},
				new int[] {7, 3}));
		FontAngle = new RadioProperty(this, "FontAngle", new String[] {"normal", "oblique", "italic"}, "normal");
		FontName = new StringProperty(this, "FontName", "Helvetica");
		FontSize = new DoubleProperty(this, "FontSize", 10);
		FontWeight = new RadioProperty(this, "FontWeight", new String[] {"light", "normal", "demi", "bold"}, "normal");
		FontUnits = new RadioProperty(this, "FontUnits", new String[] {"points", "normalized", "inches",
			"centimeters", "pixels"}, "points");

		updatePosition();
		autoTick();
		autoAspectRatio();
		autoCamera();

		listen(XLim);
		listen(YLim);
		listen(ZLim);
		listen(XLimMode);
		listen(YLimMode);
		listen(ZLimMode);
		listen(XTick);
		listen(YTick);
		listen(ZTick);
		listen(XTickMode);
		listen(YTickMode);
		listen(ZTickMode);
		listen(XTickLabel);
		listen(YTickLabel);
		listen(ZTickLabel);
		listen(XTickLabelMode);
		listen(YTickLabelMode);
		listen(ZTickLabelMode);
		listen(TickDir);
		listen(TickDirMode);
		listen(CLim);
		listen(CLimMode);
		listen(ALim);
		listen(ALimMode);
		listen(CameraTarget);
		listen(CameraTargetMode);
		listen(CameraPosition);
		listen(CameraPositionMode);
		listen(CameraUpVector);
		listen(CameraUpVectorMode);
		listen(CameraViewAngle);
		listen(CameraViewAngleMode);
		listen(DataAspectRatio);
		listen(DataAspectRatioMode);
		listen(PlotBoxAspectRatio);
		listen(PlotBoxAspectRatioMode);
		listen(View);
		listen(Position);
		listen(OuterPosition);
		listen(Units);
		listen(XDir);
		listen(YDir);
		listen(ZDir);
		listen(XScale);
		listen(YScale);
		listen(ZScale);

		legend = null;
		baseLine = null;
		colorbar = null;
	}

	private TextObject makeTextObject(String halign, String valign)
	{
		TextObject txtObj = new TextObject(this, "", new double[] {0,0,0});
		txtObj.HAlign.reset(halign);
		txtObj.VAlign.reset(valign);
		txtObj.HandleVisibility.reset("off");
		txtObj.XLimInclude.reset("off");
		txtObj.YLimInclude.reset("off");
		txtObj.validate();
		return txtObj;
	}

	public void reset(String mode)
	{
		deleteChildren();

		Projection.reset("orthogonal");
		AxesColor.reset(Color.white);
		XColor.reset(Color.black);
		YColor.reset(Color.black);
		ZColor.reset(Color.black);
		XLim.reset(new double[] {0, 1});
		YLim.reset(new double[] {0, 1});
		ZLim.reset(new double[] {-0.5, 0.5});
		XLimMode.reset("auto");
		YLimMode.reset("auto");
		ZLimMode.reset("auto");
		XGrid.reset(new Boolean(false));
		YGrid.reset(new Boolean(false));
		ZGrid.reset(new Boolean(false));
		XTick.reset(new double[0]);
		YTick.reset(new double[0]);
		ZTick.reset(new double[0]);
		XTickMode.reset("auto");
		YTickMode.reset("auto");
		ZTickMode.reset("auto");
		XTickLabel.reset(new String[0]);
		YTickLabel.reset(new String[0]);
		ZTickLabel.reset(new String[0]);
		XTickLabelMode.reset("auto");
		YTickLabelMode.reset("auto");
		ZTickLabelMode.reset("auto");
		TickDir.reset("in");
		TickDirMode.reset("auto");
		CameraTarget.reset(new double[] {0, 0, 0});
		CameraTargetMode.reset("auto");
		CameraPosition.reset(new double[] {0, 0, 0});
		CameraPositionMode.reset("auto");
		CameraUpVector.reset(new double[] {0, 1, 0});
		CameraUpVectorMode.reset("auto");
		CameraViewAngle.reset(new Double(10));
		CameraViewAngleMode.reset("auto");
		DataAspectRatio.reset(new double[] {1, 1, 1});
		DataAspectRatioMode.reset("auto");
		PlotBoxAspectRatio.reset(new double[] {1, 1, 1});
		PlotBoxAspectRatioMode.reset("auto");
		View.reset(new double[] {0, 90});
		Title.reset("");
		XLabel.reset("");
		YLabel.reset("");
		ZLabel.reset("");
		CLim.reset(new double[] {0, 1});
		CLimMode.reset("auto");
		ALim.reset(new double[] {0, 1});
		ALimMode.reset("auto");
		Box.reset(new Boolean(true));
		XDir.reset("normal");
		YDir.reset("normal");
		ZDir.reset("normal");
		XScale.reset("linear");
		YScale.reset("linear");
		ZScale.reset("linear");
		GridLineStyle.reset(":");
		MinorGridLineStyle.reset(":");
		XMinorTick.reset(new Boolean(false));
		YMinorTick.reset(new Boolean(false));
		ZMinorTick.reset(new Boolean(false));
		XMinorGrid.reset(new Boolean(false));
		YMinorGrid.reset(new Boolean(false));
		ZMinorGrid.reset(new Boolean(false));
		XAxisLocation.reset("bottom");
		YAxisLocation.reset("left");
		Layer.reset("bottom");
		Visible.reset(new Boolean(true));
		Key.reset(new Boolean(false));

		Title.reset(new Double(makeTextObject("center", "bottom").getHandle()));
		XLabel.reset(new Double(makeTextObject("center", "top").getHandle()));
		YLabel.reset(new Double(makeTextObject("center", "bottom").getHandle()));
		ZLabel.reset(new Double(makeTextObject("center", "bottom").getHandle()));

		updateActivePosition();
		autoTick();
		autoAspectRatio();
		autoCamera();
	}

	public void validate()
	{
		updateActivePosition();
		autoTick();
		autoAspectRatio();
		autoCamera();
		super.validate();
	}

	protected void setInternalPosition(double[] p)
	{
		autoSet(Position, p);
		autoTick();
		autoAspectRatio();
		autoCamera();
	}

	public void deleteChildren()
	{
		super.deleteChildren();
		if (legend != null)
		{
			legend.delete();
			legend = null;
		}
		if (colorbar != null)
		{
			colorbar.delete();
			colorbar = null;
		}
	}

	public void removeChild(HandleObject child)
	{
		if (child == baseLine)
			baseLine = null;
		else if (child == legend)
			legend = null;
		else if (child == colorbar)
		{
			updateActivePosition();
			colorbar = null;
		}

		super.removeChild(child);

		if (!BeingDeleted.isSet())
		{
			autoScale();
			autoScaleC();
			autoAspectRatio();
			autoCamera();
			autoLegend();
		}
	}

	public RenderCanvas getCanvas()
	{
		return ((AxesContainer)Parent.elementAt(0)).getCanvas();
	}

	public FigureObject getFigure()
	{
		return (FigureObject)getAncestor("figure");
	}

	public AxesContainer getAxesContainer()
	{
		if (Parent.size() > 0)
			return (AxesContainer)Parent.elementAt(0);
		else
			return null;
	}

	Rectangle getBoundingBox()
	{
		double[] pos = Utils.convertPosition(Position.getArray(), Units.getValue(), "pixels", getCanvas().getComponent());
		return new Rectangle((int)(pos[0]-1), (int)(pos[1]-1), (int)pos[2], (int)pos[3]);
	}

	Rectangle getOuterBoundingBox()
	{
		double[] pos = Utils.convertPosition(OuterPosition.getArray(), Units.getValue(), "pixels", getCanvas().getComponent());
		return new Rectangle((int)(pos[0]-1), (int)(pos[1]-1), (int)pos[2], (int)pos[3]);
	}

	void updatePosition()
	{
		RenderCanvas canvas = getCanvas();
		double[] p = Utils.convertPosition(OuterPosition.getArray(), Units.getValue(), "pixels", canvas.getComponent());
		FontMetrics fm = canvas.getFontMetrics(Utils.getFont(FontName, FontSize, FontUnits,
					FontAngle, FontWeight, p[3]));
		int marginH = 10+fm.stringWidth("0000")+fm.getHeight()+5+7,
			marginV = 10+2*fm.getHeight()+10+7;

		p[0] += marginH;
		p[1] += marginV;
		p[2] -= 2*marginH;
		p[3] -= 2*marginV;
		autoSet(Position, Utils.convertPosition(p, "pixels", Units.getValue(), canvas.getComponent()));
	}

	void updateOuterPosition()
	{
		RenderCanvas canvas = getCanvas();
		double[] p = Utils.convertPosition(Position.getArray(), Units.getValue(), "pixels", canvas.getComponent());
		FontMetrics fm = canvas.getFontMetrics(Utils.getFont(FontName, FontSize, FontUnits,
					FontAngle, FontWeight, p[3]));
		int marginH = 10+fm.stringWidth("0000")+fm.getHeight()+5+7,
			marginV = 10+2*fm.getHeight()+10+7;
		
		p[0] -= marginH;
		p[1] -= marginV;
		p[2] += 2*marginH;
		p[3] += 2*marginV;
		autoSet(OuterPosition, Utils.convertPosition(p, "pixels", Units.getValue(), canvas.getComponent()));
	}

	void updateActivePosition()
	{
		if (ActivePositionProperty.is("position"))
			updateOuterPosition();
		else
			updatePosition();
		autoCamera();
	}

	protected void autoLegend()
	{
		if (Key.isSet())
		{
			java.util.List names = new LinkedList();

			synchronized(Children)
			{
				Iterator it = Children.iterator();
				while (it.hasNext())
				{
					HandleObject o = (HandleObject)it.next();
					if (o.isLegendable())
					{
						if (o instanceof LineObject)
							names.add(((LineObject)o).KeyLabel.toString());
						else
							names.add("");
					}
				}
			}

			String[] nameArray = new String[names.size()];
			names.toArray(nameArray);
			makeLegend(nameArray);
		}
	}

	public LegendObject getLegend()
	{
	    return legend;
	}

	public LegendObject makeLegend(String names[])
	{
		if (names == null || names.length == 0)
		{
			if (legend != null)
			{
				legend.delete();
				legend = null;
			}
		}
		else
		{
			if (legend == null)
			{
				legend = new LegendObject(this, names);
				legend.validate();
			}
			else
				legend.buildLegend(this, names);
			if (legend.size() == 0)
			{
				legend.delete();
				legend = null;
			}
		}
		return legend;
	}

	public ColorbarObject makeColorbar(boolean mode)
	{
		if (colorbar == null && mode)
		{
			colorbar = new ColorbarObject(this);
			colorbar.validate();
		}
		else if (!mode && colorbar != null)
		{
			colorbar.delete();
			colorbar = null;
		}
		return colorbar;
	}

	public BaseLineObject getBaseLine()
	{
		if (baseLine == null)
		{
			baseLine = new BaseLineObject(this, 0);
			baseLine.LineColor.reset("k");
			baseLine.validate();
		}
		return baseLine;
	}

	public void childValidated(HandleObject child)
	{
		if (!isValid())
			return;

		autoScale();
		autoScaleC();
		autoAspectRatio();
		autoCamera();
		autoLegend();

		if (child instanceof GraphicObject)
		{
			GraphicObject go = (GraphicObject)child;
			listen(go.XLim);
			listen(go.YLim);
			listen(go.ZLim);
			listen(go.CLim);
			listen(go.Visible);

			Property p = go.getProperty("KeyLabel");
			if (p != null)
				listen(p);
		}
	}

	public void draw(Renderer r)
	{
		r.setXForm(this);
	
		double xmin = sx.scale(XLim.getArray()[0]), xmax = sx.scale(XLim.getArray()[1]);
		double ymin = sy.scale(YLim.getArray()[0]), ymax = sy.scale(YLim.getArray()[1]);
		double zmin = sz.scale(ZLim.getArray()[0]), zmax = sz.scale(ZLim.getArray()[1]);

		double xd = (XDir.is("normal") ? 1 : -1);
		double yd = (YDir.is("normal") ? 1 : -1);
		double zd = (ZDir.is("normal") ? 1 : -1);

		double[] p1 = new double[3], p2 = new double[3], xv, yv, zv;

		xstate = ystate = zstate = AXE_ANY_DIR;

		x_render.transform(xmin, (ymin+ymax)/2, (zmin+zmax)/2, p1, 0);
		x_render.transform(xmax, (ymin+ymax)/2, (zmin+zmax)/2, p2, 0);
		xv = new double[] {Math.rint(p2[0]-p1[0]), Math.rint(p2[1]-p1[1]), (p2[2]-p1[2])};
		if (xv[0] == 0 && xv[1] == 0)
			xstate = AXE_DEPTH_DIR;
		else if (xv[2] == 0)
		{
			if (xv[0] == 0)
				xstate = AXE_VERT_DIR;
			else if (xv[1] == 0)
				xstate = AXE_HORZ_DIR;
		}
		double xPlane;
		if (xv[2] == 0)
			if (xv[1] == 0)
				xPlane = (xv[0] > 0 ? xmax : xmin);
			else
				xPlane = (xv[1] < 0 ? xmax : xmin);
		else
			xPlane = (xv[2] < 0 ? xmin : xmax);
		double xPlaneN = (xPlane == xmin ? xmax : xmin);
		double fx = (xmax-xmin)/Math.sqrt(xv[0]*xv[0]+xv[1]*xv[1]);

		x_render.transform((xmin+xmax)/2, ymin, (zmin+zmax)/2, p1, 0);
		x_render.transform((xmin+xmax)/2, ymax, (zmin+zmax)/2, p2, 0);
		yv = new double[] {Math.rint(p2[0]-p1[0]), Math.rint(p2[1]-p1[1]), p2[2]-p1[2]};
		if (yv[0] == 0 && yv[1] == 0)
			ystate = AXE_DEPTH_DIR;
		else if (yv[2] == 0)
		{
			if (yv[0] == 0)
				ystate = AXE_VERT_DIR;
			else if (yv[1] == 0)
				ystate = AXE_HORZ_DIR;
		}
		double yPlane;
		if (yv[2] == 0)
			if (yv[1] == 0)
				yPlane = (yv[0] > 0 ? ymax : ymin);
			else
				yPlane = (yv[1] < 0 ? ymax : ymin);
		else
			yPlane = (yv[2] < 0 ? ymin : ymax);
		double yPlaneN = (yPlane == ymin ? ymax : ymin);
		double fy = (ymax-ymin)/Math.sqrt(yv[0]*yv[0]+yv[1]*yv[1]);

		x_render.transform((xmin+xmax)/2, (ymin+ymax)/2, zmin, p1, 0);
		x_render.transform((xmin+xmax)/2, (ymin+ymax)/2, zmax, p2, 0);
		zv = new double[] {Math.rint(p2[0]-p1[0]), Math.rint(p2[1]-p1[1]), p2[2]-p1[2]};
		if (zv[0] == 0 && zv[1] == 0)
			zstate = AXE_DEPTH_DIR;
		else if (zv[2] == 0)
		{
			if (zv[0] == 0)
				zstate = AXE_VERT_DIR;
			else if (zv[1] == 0)
				zstate = AXE_HORZ_DIR;
		}
		double zPlane;
		if (zv[2] == 0)
			if (zv[1] == 0)
				zPlane = (zv[0] > 0 ? zmin : zmax);
			else
				zPlane = (zv[1] < 0 ? zmin : zmax);
		else
			zPlane = (zv[2] < 0 ? zmin : zmax);
		double zPlaneN = (zPlane == zmin ? zmax : zmin);
		double fz = (zmax-zmin)/Math.sqrt(zv[0]*zv[0]+zv[1]*zv[1]);

		boolean mode2d = (((xstate > AXE_DEPTH_DIR ? 1 : 0) +
						   (ystate > AXE_DEPTH_DIR ? 1 : 0) +
						   (zstate > AXE_DEPTH_DIR ? 1 : 0)) == 2);
		if (TickDirMode.is("auto"))
		{
			autoMode++;
			TickDir.set(mode2d ? "in" : "out", true);
			autoMode--;
		}

		xticklen = yticklen = zticklen = 7;

		double tickdir = (TickDir.is("in") ? -1 : 1);
		double xtickoffset = (mode2d && tickdir < 0 ? 0 : Math.max(1.0, xticklen)) + 5;
		double ytickoffset = (mode2d && tickdir < 0 ? 0 : Math.max(1.0, yticklen)) + 5;
		double ztickoffset = (mode2d && tickdir < 0 ? 0 : Math.max(1.0, zticklen)) + 5;

		boolean xySym = (xd*yd*(xPlane-xPlaneN)*(yPlane-yPlaneN) > 0);
		boolean boxSet = Box.isSet();

		boolean x2Dtop = false;
		boolean y2Dright = false;
		double zpTick = zPlane;
		boolean visible = Visible.isSet();

		/* 2D mode */
		if (xstate == AXE_HORZ_DIR && ystate == AXE_VERT_DIR)
		{
			if (XAxisLocation.is("top"))
			{
				double tmp = yPlane;
				yPlane = yPlaneN;
				yPlaneN = tmp;
				x2Dtop = true;
			}
			if (YAxisLocation.is("right"))
			{
				double tmp = xPlane;
				xPlane = xPlaneN;
				xPlaneN = tmp;
				y2Dright = true;
			}
			if (Layer.is("top"))
				zpTick = zPlaneN;
		}

		// work variables
		java.util.List l1 = new LinkedList();
		java.util.List l2 = new LinkedList();

		// Axes planes

		if (!AxesColor.is("none") && visible)
		{
			r.setColor(AxesColor.getColor());

			l1.add(new Point3D(xmin, ymin, zPlane));
			l1.add(new Point3D(xmax, ymin, zPlane));
			l1.add(new Point3D(xmax, ymax, zPlane));
			l1.add(new Point3D(xmin, ymax, zPlane));

			l1.add(new Point3D(xPlane, ymin, zmin));
			l1.add(new Point3D(xPlane, ymax, zmin));
			l1.add(new Point3D(xPlane, ymax, zmax));
			l1.add(new Point3D(xPlane, ymin, zmax));

			l1.add(new Point3D(xmin, yPlane, zmin));
			l1.add(new Point3D(xmax, yPlane, zmin));
			l1.add(new Point3D(xmax, yPlane, zmax));
			l1.add(new Point3D(xmin, yPlane, zmax));

			r.drawQuads(l1, 2.5);
			l1.clear();
		}
		
		//boolean xySym = (xd*yd*(xPlane-xPlaneN)*(yPlane-yPlaneN) > 0);
		//boolean boxSet = Box.isSet();

		// Box

		r.setLineStyle("-", true);
		r.setLineWidth(LineWidth.floatValue());

		if ((boxSet || alwaysDrawBox) && visible)
		{
			// X box
			l1.add(new Point3D(xPlaneN, yPlaneN, zPlane)); l1.add(new Point3D(xPlane, yPlaneN, zPlane));
			if (Box.isSet())
			{
				l1.add(new Point3D(xPlaneN, yPlane, zPlane)); l1.add(new Point3D(xPlane, yPlane, zPlane));
				l1.add(new Point3D(xPlaneN, yPlane, zPlaneN)); l1.add(new Point3D(xPlane, yPlane, zPlaneN));
				l1.add(new Point3D(xPlaneN, yPlaneN, zPlaneN)); l1.add(new Point3D(xPlane, yPlaneN, zPlaneN));
			}
			r.setColor(XColor.getColor());
			r.drawSegments(l1);
			l1.clear();

			// Y box
			l1.add(new Point3D(xPlaneN, yPlaneN, zPlane)); l1.add(new Point3D(xPlaneN, yPlane, zPlane));
			if (Box.isSet())
			{
				l1.add(new Point3D(xPlane, yPlaneN, zPlane)); l1.add(new Point3D(xPlane, yPlane, zPlane));
				l1.add(new Point3D(xPlane, yPlaneN, zPlaneN)); l1.add(new Point3D(xPlane, yPlane, zPlaneN));
				l1.add(new Point3D(xPlaneN, yPlaneN, zPlaneN)); l1.add(new Point3D(xPlaneN, yPlane, zPlaneN));
			}
			r.setColor(YColor.getColor());
			r.drawSegments(l1);
			l1.clear();

			// Z box
			if (xySym)
			{ l1.add(new Point3D(xPlaneN, yPlane, zPlaneN)); l1.add(new Point3D(xPlaneN, yPlane, zPlane)); }
			else
			{ l1.add(new Point3D(xPlane, yPlaneN, zPlaneN)); l1.add(new Point3D(xPlane, yPlaneN, zPlane)); }
			if (Box.isSet())
			{
				l1.add(new Point3D(xPlane, yPlane, zPlaneN)); l1.add(new Point3D(xPlane, yPlane, zPlane));
				if (xySym)
				{ l1.add(new Point3D(xPlane, yPlaneN, zPlaneN)); l1.add(new Point3D(xPlane, yPlaneN, zPlane)); }
				else
				{ l1.add(new Point3D(xPlaneN, yPlane, zPlaneN)); l1.add(new Point3D(xPlaneN, yPlane, zPlane)); }
				l1.add(new Point3D(xPlaneN, yPlaneN, zPlaneN)); l1.add(new Point3D(xPlaneN, yPlaneN, zPlane));
			}
			r.setColor(ZColor.getColor());
			r.drawSegments(l1);
			l1.clear();
		}

		r.setFont(Utils.getFont(FontName, FontSize, FontUnits, FontAngle,
			FontWeight, getBoundingBox().height));

		// X Grid

		if (xstate != AXE_DEPTH_DIR && visible)
		{
			boolean doXGrid = XGrid.isSet() && !GridLineStyle.is("none");
			boolean doXMinorGrid = XMinorGrid.isSet() && !MinorGridLineStyle.is("none");
			boolean doXMinorTick = XMinorTick.isSet();
			double[] xticks = sx.scale(XTick.getArray());
			double[] xmticks = sx.scale(x_minorTicks);
			String[] xticklabels = XTickLabel.getArray();
			int wmax = 0, hmax = 0;
			boolean tickAlongZ = Double.isInfinite(fy);

			r.setColor(XColor.getColor());

			// grid lines
			if (doXGrid)
			{
				for (int i=0; i<xticks.length; i++)
				{
					l1.add(new Point3D(xticks[i], yPlaneN, zpTick));
					l1.add(new Point3D(xticks[i], yPlane, zpTick));
					if (zstate != AXE_DEPTH_DIR)
					{
						l1.add(new Point3D(xticks[i], yPlane, zPlaneN));
						l1.add(new Point3D(xticks[i], yPlane, zPlane));
					}
				}
				r.setLineStyle(GridLineStyle.getValue(), true);
				r.drawSegments(l1);
				r.setLineStyle("-", true);
				l1.clear();
			}

			// tick marks
			if (tickAlongZ)
			{
				for (int i=0; i<xticks.length; i++)
				{
					l1.add(new Point3D(xticks[i], yPlaneN, zPlane));
					l1.add(new Point3D(xticks[i], yPlaneN, zPlane+Math.signum(zPlane-zPlaneN)*fz*xticklen*tickdir));
					if (Box.isSet() && xstate != AXE_ANY_DIR)
					{
						l1.add(new Point3D(xticks[i], yPlaneN, zPlaneN));
						l1.add(new Point3D(xticks[i], yPlaneN,
							zPlaneN+Math.signum(zPlaneN-zPlane)*fz*xticklen*tickdir));
					}
					l2.add(new double[] {xticks[i], yPlaneN, zPlane+Math.signum(zPlane-zPlaneN)*fz*xtickoffset});
				}
			}
			else
			{
				for (int i=0; i<xticks.length; i++)
				{
					l1.add(new Point3D(xticks[i], yPlaneN, zpTick));
					l1.add(new Point3D(xticks[i], yPlaneN+Math.signum(yPlaneN-yPlane)*fy*xticklen*tickdir, zpTick));
					if (Box.isSet() && xstate != AXE_ANY_DIR)
					{
						l1.add(new Point3D(xticks[i], yPlane, zpTick));
						l1.add(new Point3D(xticks[i],
							yPlane+Math.signum(yPlane-yPlaneN)*fy*xticklen*tickdir, zpTick));
					}
					l2.add(new double[] {xticks[i], yPlaneN+Math.signum(yPlaneN-yPlane)*fy*xtickoffset, zPlane});
				}
			}
			r.drawSegments(l1);
			l1.clear();

			// tick texts
			for (int i=0; i<xticks.length && i<xticklabels.length; i++)
			{
				String txt = (x_logTickLabels ? "10^{"+xticklabels[i]+"}" : xticklabels[i]);
				Rectangle d = r.drawText(txt, (double[])l2.get(i),
						(xstate == AXE_HORZ_DIR ? 1 : (xySym ? 0 : 2)),
						(xstate == AXE_VERT_DIR ? 1 : (zd*zv[2] <= 0 && !x2Dtop ? 2 : 0)));
				if (d.width > wmax) wmax = d.width;
				if (d.height > hmax) hmax = d.height;
			}
			l2.clear();
			wmax += 5;

			// minor grid lines
			if (doXMinorGrid)
			{
				for (int i=0; i<x_minorTicks.length; i++)
				{
					l1.add(new Point3D(xmticks[i], yPlaneN, zpTick));
					l1.add(new Point3D(xmticks[i], yPlane, zpTick));
					if (zstate != AXE_DEPTH_DIR)
					{
						l1.add(new Point3D(xmticks[i], yPlane, zPlaneN));
						l1.add(new Point3D(xmticks[i], yPlane, zPlane));
					}
				}
				r.setLineStyle(MinorGridLineStyle.getValue(), true);
				r.drawSegments(l1);
				r.setLineStyle("-", true);
				l1.clear();
			}

			// minor tick marks
			if (doXMinorTick)
			{
				if (tickAlongZ)
				{
					for (int i=0; i<x_minorTicks.length; i++)
					{
						l1.add(new Point3D(xmticks[i], yPlaneN, zPlane));
						l1.add(new Point3D(xmticks[i], yPlaneN,
							zPlane+Math.signum(zPlane-zPlaneN)*fz*xticklen/2*tickdir));
						if (Box.isSet() && xstate != AXE_ANY_DIR)
						{
							l1.add(new Point3D(xmticks[i], yPlaneN, zPlaneN));
							l1.add(new Point3D(xmticks[i], yPlaneN,
								zPlaneN+Math.signum(zPlaneN-zPlane)*fz*xticklen/2*tickdir));
						}
					}
				}
				else
				{
					for (int i=0; i<x_minorTicks.length; i++)
					{
						l1.add(new Point3D(xmticks[i], yPlaneN, zpTick));
						l1.add(new Point3D(xmticks[i],
							yPlaneN+Math.signum(yPlaneN-yPlane)*fy*xticklen/2*tickdir, zpTick));
						if (Box.isSet() && xstate != AXE_ANY_DIR)
						{
							l1.add(new Point3D(xmticks[i], yPlane, zpTick));
							l1.add(new Point3D(xmticks[i],
								yPlane+Math.signum(yPlane-yPlaneN)*fy*xticklen/2*tickdir, zpTick));
						}
					}
				}
				r.drawSegments(l1);
				l1.clear();
			}

			// label
			if (!XLabel.isEmpty())
			{
				TextObject xLabObj = XLabel.getText();
				if (xLabObj.PositionMode.isSet())
				{
					xLabObj.HAlign.reset(xstate > AXE_DEPTH_DIR ? "center" : (xySym ? "left" : "right"));
					xLabObj.VAlign.reset(xstate == AXE_VERT_DIR ? "bottom" : (zd*zv[2] <= 0 ? "top" : "bottom"));

					double angle = 0;
					double[] p = new double[] {(xmin+xmax)/2, yPlaneN, zPlane};
					if (tickAlongZ)
						p[2] += (Math.signum(zPlane-zPlaneN)*fz*xtickoffset);
					else
						p[1] += (Math.signum(yPlaneN-yPlane)*fy*xtickoffset);
					x_render.transform(p[0], p[1], p[2], p, 0);
					switch (xstate)
					{
						case AXE_ANY_DIR:
							p[0] += (xySym ? wmax : -wmax);
							p[1] += (zd*zv[2] <= 0 ? hmax : -hmax);
							break;
						case AXE_VERT_DIR:
							p[0] -= wmax;
							angle = 90;
							break;
						case AXE_HORZ_DIR:
							p[1] += hmax;
							break;
					}
					unTransform(p[0], p[1], p[2], p, 0);
					xLabObj.Position.reset(new double[] {p[0], p[1], p[2]});
					if (xLabObj.Rotation.doubleValue() != angle)
						try { xLabObj.Rotation.set(new Double(angle)); }
						catch (PropertyException e) {}
				}
				//xLabObj.draw(r);
			}
		}

		// Y Grid

		if (ystate != AXE_DEPTH_DIR && visible)
		{
			boolean doYGrid = YGrid.isSet() && !GridLineStyle.is("none");
			boolean doYMinorGrid = YMinorGrid.isSet() && !MinorGridLineStyle.is("none");
			boolean doYMinorTick = YMinorTick.isSet();
			double[] yticks = sy.scale(YTick.getArray());
			double[] ymticks = sy.scale(y_minorTicks);
			String[] yticklabels = YTickLabel.getArray();
			int wmax = 0, hmax = 0;
			boolean tickAlongZ = Double.isInfinite(fx);
			
			r.setColor(YColor.getColor());

			// grid lines
			if (doYGrid)
			{
				for (int i=0; i<yticks.length; i++)
				{
					l1.add(new Point3D(xPlaneN, yticks[i], zpTick));
					l1.add(new Point3D(xPlane, yticks[i], zpTick));
					if (zstate != AXE_DEPTH_DIR)
					{
						l1.add(new Point3D(xPlane, yticks[i], zPlaneN));
						l1.add(new Point3D(xPlane, yticks[i], zPlane));
					}
				}
				r.setLineStyle(GridLineStyle.getValue(), true);
				r.drawSegments(l1);
				r.setLineStyle("-", true);
				l1.clear();
			}

			// tick marks
			if (tickAlongZ)
			{
				for (int i=0; i<yticks.length; i++)
				{
					l1.add(new Point3D(xPlaneN, yticks[i], zPlane));
					l1.add(new Point3D(xPlaneN, yticks[i], zPlane+Math.signum(zPlane-zPlaneN)*fz*yticklen*tickdir));
					if (Box.isSet() && ystate != AXE_ANY_DIR)
					{
						l1.add(new Point3D(xPlaneN, yticks[i], zPlaneN));
						l1.add(new Point3D(xPlaneN, yticks[i],
							zPlaneN+Math.signum(zPlaneN-zPlane)*fz*yticklen*tickdir));
					}
					l2.add(new double[] {xPlaneN, yticks[i], zPlane+Math.signum(zPlane-zPlaneN)*fz*ytickoffset});
				}
			}
			else
			{
				for (int i=0; i<yticks.length; i++)
				{
					l1.add(new Point3D(xPlaneN, yticks[i], zpTick));
					l1.add(new Point3D(xPlaneN+Math.signum(xPlaneN-xPlane)*fx*yticklen*tickdir, yticks[i], zpTick));
					if (Box.isSet() && ystate != AXE_ANY_DIR)
					{
						l1.add(new Point3D(xPlane, yticks[i], zpTick));
						l1.add(new Point3D(xPlane+Math.signum(xPlane-xPlaneN)*fx*yticklen*tickdir,
							yticks[i], zpTick));
					}
					l2.add(new double[]{xPlaneN+Math.signum(xPlaneN-xPlane)*fx*ytickoffset, yticks[i], zPlane});
				}
			}
			r.drawSegments(l1);
			l1.clear();

			// tick texts
			for (int i=0; i<yticks.length && i<yticklabels.length; i++)
			{
				String txt = (y_logTickLabels ? "10^{"+yticklabels[i]+"}" : yticklabels[i]);
				Rectangle d = r.drawText(txt, (double[])l2.get(i),
						(ystate == AXE_HORZ_DIR ? 1 : (!xySym || y2Dright ? 0 : 2)),
						(ystate == AXE_VERT_DIR ? 1 : (zd*zv[2] <= 0 ? 2 : 0)));
				if (d.width > wmax) wmax = d.width;
				if (d.height > hmax) hmax = d.height;
			}
			l2.clear();
			wmax += 5;

			// minor grid lines
			if (doYMinorGrid)
			{
				for (int i=0; i<y_minorTicks.length; i++)
				{
					l1.add(new Point3D(xPlaneN, ymticks[i], zpTick));
					l1.add(new Point3D(xPlane, ymticks[i], zpTick));
					if (zstate != AXE_DEPTH_DIR)
					{
						l1.add(new Point3D(xPlane, ymticks[i], zPlaneN));
						l1.add(new Point3D(xPlane, ymticks[i], zPlane));
					}
				}
				r.setLineStyle(MinorGridLineStyle.getValue(), true);
				r.drawSegments(l1);
				r.setLineStyle("-", true);
				l1.clear();
			}

			// minor tick marks
			if (doYMinorTick)
			{
				if (tickAlongZ)
				{
					for (int i=0; i<y_minorTicks.length; i++)
					{
						l1.add(new Point3D(xPlaneN, ymticks[i], zPlane));
						l1.add(new Point3D(xPlaneN, ymticks[i],
							zPlane+Math.signum(zPlane-zPlaneN)*fz*yticklen/2*tickdir));
						if (Box.isSet() && ystate != AXE_ANY_DIR)
						{
							l1.add(new Point3D(xPlaneN, ymticks[i], zPlaneN));
							l1.add(new Point3D(xPlaneN, ymticks[i],
								zPlaneN+Math.signum(zPlaneN-zPlane)*fz*yticklen/2*tickdir));
						}
					}
				}
				else
				{
					for (int i=0; i<y_minorTicks.length; i++)
					{
						l1.add(new Point3D(xPlaneN, ymticks[i], zpTick));
						l1.add(new Point3D(xPlaneN+Math.signum(xPlaneN-xPlane)*fx*yticklen/2*tickdir,
							ymticks[i], zpTick));
						if (Box.isSet() && ystate != AXE_ANY_DIR)
						{
							l1.add(new Point3D(xPlane, ymticks[i], zpTick));
							l1.add(new Point3D(xPlane+Math.signum(xPlane-xPlaneN)*fx*yticklen/2*tickdir,
								ymticks[i], zpTick));
						}
					}
				}
				r.drawSegments(l1);
				l1.clear();
			}

			// label
			if (!YLabel.isEmpty())
			{
				TextObject yLabObj = YLabel.getText();
				if (yLabObj.PositionMode.isSet())
				{
					yLabObj.HAlign.reset(ystate > AXE_DEPTH_DIR ? "center" : (!xySym ? "left" : "right"));
					yLabObj.VAlign.reset(ystate == AXE_VERT_DIR ? "bottom" : (zd*zv[2] <= 0 ? "top" : "bottom"));
				
					double angle = 0;
					double[] p = new double[] {xPlaneN, (ymin+ymax)/2, zPlane};
					if (tickAlongZ)
						p[2] += (Math.signum(zPlane-zPlaneN)*fz*ytickoffset);
					else
						p[0] += (Math.signum(xPlaneN-xPlane)*fx*ytickoffset);
					x_render.transform(p[0], p[1], p[2], p, 0);
					switch (ystate)
					{
						case AXE_ANY_DIR:
							p[0] += (!xySym ? wmax : -wmax);
							p[1] += (zd*zv[2] <= 0 ? hmax : -hmax);
							break;
						case AXE_VERT_DIR:
							p[0] -= wmax;
							angle = 90;
							break;
						case AXE_HORZ_DIR:
							p[1] += hmax;
							break;
					}
					unTransform(p[0], p[1], p[2], p, 0);
					yLabObj.Position.reset(new double[] {p[0], p[1], p[2]});
					if (yLabObj.Rotation.doubleValue() != angle)
						try { yLabObj.Rotation.set(new Double(angle)); }
						catch (PropertyException e) {}
				}
				//yLabObj.draw(r);
			}
		}
		
		// Z Grid

		if (zstate != AXE_DEPTH_DIR && visible)
		{
			boolean doZGrid = ZGrid.isSet() && !GridLineStyle.is("none");
			boolean doZMinorGrid = ZMinorGrid.isSet() && !MinorGridLineStyle.is("none");
			boolean doZMinorTick = ZMinorTick.isSet();
			double[] zticks = sz.scale(ZTick.getArray());
			double[] zmticks = sz.scale(z_minorTicks);
			int wmax = 0, hmax = 0;
			String[] zticklabels = ZTickLabel.getArray();

			r.setColor(ZColor.getColor());

			// grid lines
			if (doZGrid)
			{
				for (int i=0; i<zticks.length; i++)
				{
					l1.add(new Point3D(xPlaneN, yPlane, zticks[i]));
					l1.add(new Point3D(xPlane, yPlane, zticks[i]));
					l1.add(new Point3D(xPlane, yPlaneN, zticks[i]));
					l1.add(new Point3D(xPlane, yPlane, zticks[i]));
				}
				r.setLineStyle(GridLineStyle.getValue(), true);
				r.drawSegments(l1);
				r.setLineStyle("-", true);
				l1.clear();
			}

			// tick marks
			if (xySym)
			{
				if (Double.isInfinite(fy))
					for (int i=0; i<zticks.length; i++)
					{
						l1.add(new Point3D(xPlaneN, yPlane, zticks[i]));
						l1.add(new Point3D(xPlaneN+Math.signum(xPlaneN-xPlane)*fx*zticklen*tickdir,
								yPlane, zticks[i]));
						if (Box.isSet() && zstate != AXE_ANY_DIR)
						{
							l1.add(new Point3D(xPlane, yPlane, zticks[i]));
							l1.add(new Point3D(xPlane+Math.signum(xPlane-xPlaneN)*fx*zticklen*tickdir,
									yPlane, zticks[i]));
						}
						l2.add(new double[] {xPlaneN+Math.signum(xPlaneN-xPlane)*fx*ztickoffset, yPlane, zticks[i]});
					}
				else
					for (int i=0; i<zticks.length; i++)
					{
						l1.add(new Point3D(xPlaneN, yPlane, zticks[i]));
						l1.add(new Point3D(xPlaneN, yPlane+Math.signum(yPlane-yPlaneN)*fy*zticklen*tickdir,
								zticks[i]));
						l2.add(new double[] {xPlaneN, yPlane+Math.signum(yPlane-yPlaneN)*fy*ztickoffset, zticks[i]});
					}
			}
			else
			{
				if (Double.isInfinite(fx))
					for (int i=0; i<zticks.length; i++)
					{
						l1.add(new Point3D(xPlane, yPlaneN, zticks[i]));
						l1.add(new Point3D(xPlane, yPlaneN+Math.signum(yPlaneN-yPlane)*fy*zticklen*tickdir,
								zticks[i]));
						if (Box.isSet() && zstate != AXE_ANY_DIR)
						{
							l1.add(new Point3D(xPlane, yPlane, zticks[i]));
							l1.add(new Point3D(xPlane, yPlane+Math.signum(yPlane-yPlaneN)*fy*zticklen*tickdir,
									zticks[i]));
						}
						l2.add(new double[] {xPlane, yPlaneN+Math.signum(yPlaneN-yPlane)*fy*ztickoffset, zticks[i]});
					}
				else
					for (int i=0; i<zticks.length; i++)
					{
						l1.add(new Point3D(xPlane, yPlaneN, zticks[i]));
						l1.add(new Point3D(xPlane+Math.signum(xPlane-xPlaneN)*fx*zticklen*tickdir, yPlaneN,
								zticks[i]));
						l2.add(new double[] {xPlane+Math.signum(xPlane-xPlaneN)*fx*ztickoffset, yPlaneN, zticks[i]});
					}
			}
			r.drawSegments(l1);
			l1.clear();

			// tick texts
			for (int i=0; i<zticks.length && i<zticklabels.length; i++)
			{
				String txt = (z_logTickLabels ? "10^{"+zticklabels[i]+"}" : zticklabels[i]);
				Rectangle d = r.drawText(txt, (double[])l2.get(i),
						2,
						(zstate == AXE_VERT_DIR ? 1 : (zd*zv[2] < 0 ? 0 : 2)));
				if (d.width > wmax) wmax = d.width;
				if (d.height > hmax) hmax = d.height;
			}
			l2.clear();
			wmax += 5;

			// minor grid lines
			if (doZMinorGrid)
			{
				for (int i=0; i<z_minorTicks.length; i++)
				{
					l1.add(new Point3D(xPlaneN, yPlane, zmticks[i]));
					l1.add(new Point3D(xPlane, yPlane, zmticks[i]));
					l1.add(new Point3D(xPlane, yPlaneN, zmticks[i]));
					l1.add(new Point3D(xPlane, yPlane, zmticks[i]));
				}
				r.setLineStyle(MinorGridLineStyle.getValue(), true);
				r.drawSegments(l1);
				r.setLineStyle("-", true);
				l1.clear();
			}

			// minor tick marks
			if (doZMinorTick)
			{
				if (xySym)
				{
					if (Double.isInfinite(fy))
						for (int i=0; i<z_minorTicks.length; i++)
						{
							l1.add(new Point3D(xPlaneN, yPlane, zmticks[i]));
							l1.add(new Point3D(xPlaneN+Math.signum(xPlaneN-xPlane)*fx*zticklen/2*tickdir,
										yPlane, zmticks[i]));
							if (Box.isSet() && zstate != AXE_ANY_DIR)
							{
								l1.add(new Point3D(xPlane, yPlane, zmticks[i]));
								l1.add(new Point3D(xPlane+Math.signum(xPlane-xPlaneN)*fx*zticklen/2*tickdir,
											yPlane, zmticks[i]));
							}
						}
					else
						for (int i=0; i<z_minorTicks.length; i++)
						{
							l1.add(new Point3D(xPlaneN, yPlane, zmticks[i]));
							l1.add(new Point3D(xPlaneN, yPlane+Math.signum(yPlane-yPlaneN)*fy*zticklen/2*tickdir,
										zmticks[i]));
						}
				}
				else
				{
					if (Double.isInfinite(fx))
						for (int i=0; i<z_minorTicks.length; i++)
						{
							l1.add(new Point3D(xPlane, yPlaneN, zmticks[i]));
							l1.add(new Point3D(xPlane, yPlaneN+Math.signum(yPlaneN-yPlane)*fy*zticklen/2*tickdir,
										zmticks[i]));
							if (Box.isSet() && zstate != AXE_ANY_DIR)
							{
								l1.add(new Point3D(xPlane, yPlane, zmticks[i]));
								l1.add(new Point3D(xPlane, yPlane+Math.signum(yPlane-yPlaneN)*fy*zticklen/2*tickdir,
											zmticks[i]));
							}
						}
					else
						for (int i=0; i<z_minorTicks.length; i++)
						{
							l1.add(new Point3D(xPlane, yPlaneN, zmticks[i]));
							l1.add(new Point3D(xPlane+Math.signum(xPlane-xPlaneN)*fx*zticklen/2*tickdir, yPlaneN,
										zmticks[i]));
						}
				}
				r.drawSegments(l1);
				l1.clear();
			}

			// label
			if (!ZLabel.isEmpty())
			{
				TextObject zLabObj = ZLabel.getText();
				if (zLabObj.PositionMode.isSet())
				{
					boolean camAuto = CameraUpVectorMode.is("auto");

					zLabObj.HAlign.reset((zstate > AXE_DEPTH_DIR || camAuto) ? "center" : "right");
					zLabObj.VAlign.reset(zstate == AXE_VERT_DIR ? "bottom" : ((zd*zv[2] < 0 || camAuto) ? "bottom" : "top"));
				
					double angle = 0;
					double[] p;
					if (xySym)
					{
						p = new double[] {xPlaneN, yPlane, (zmin+zmax)/2};
						if (Double.isInfinite(fy))
							p[0] += (Math.signum(xPlaneN-xPlane)*fx*ztickoffset);
						else
							p[1] += (Math.signum(yPlane-yPlaneN)*fy*ztickoffset);
					}
					else
					{
						p = new double[] {xPlane, yPlaneN, (zmin+zmax)/2};
						if (Double.isInfinite(fx))
							p[1] += (Math.signum(yPlaneN-yPlane)*fy*ztickoffset);
						else
							p[0] += (Math.signum(xPlane-xPlaneN)*fx*ztickoffset);
					}
					x_render.transform(p[0], p[1], p[2], p, 0);
					switch (zstate)
					{
						case AXE_ANY_DIR:
							if (camAuto)
							{
								p[0] -= wmax;
								angle = 90;
							}
							/* TODO: what's the correct offset?
							p[0] += (!xySym ? wmax : -wmax);
							p[1] += (zd*zv[2] <= 0 ? hmax : -hmax);
							*/
							break;
						case AXE_VERT_DIR:
							p[0] -= wmax;
							angle = 90;
							break;
						case AXE_HORZ_DIR:
							p[1] += hmax;
							break;
					}
					unTransform(p[0], p[1], p[2], p, 0);
					zLabObj.Position.reset(new double[] {p[0], p[1], p[2]});
					if (zLabObj.Rotation.doubleValue() != angle)
						try { zLabObj.Rotation.set(new Double(angle)); }
						catch (PropertyException e) {}
				}
				//zLabObj.draw(r);
			}
		}

		r.setLineStyle("-", false);
		
		// Title

		if (!Title.isEmpty())
		{
			TextObject titleObj = Title.getText();
			if (titleObj.PositionMode.isSet())
			{
				// position title automatically
				Rectangle bb = getBoundingBox();
				double[] p = new double[3];
				unTransform(bb.x+bb.width/2, getCanvas().getHeight()-(bb.y+bb.height+10), (x_zmin+x_zmax)/2, p, 0);
				titleObj.Position.reset(p);
			}
			//titleObj.draw(r);
		}

		// Children

		Iterator it;

		// TODO: how to avoid clipping on the clip planes?
		r.setClipBox(xmin, xmax, ymin, ymax, zmin, zmax);
		r.setCamera(CameraPosition.getArray(), CameraTarget.getArray());

		synchronized (Children)
		{
			LinkedList objList = new LinkedList();

			// Do lights first
			it = Children.iterator();
			while (it.hasNext())
			{
				GraphicObject obj = (GraphicObject)it.next();
				if (obj.Visible.isSet())
					if (obj instanceof LightObject)
						obj.draw(r);
					else
						objList.add(obj);
			}

			// Do other objects
			it = objList.iterator();
			while (it.hasNext())
			{
				GraphicObject obj = (GraphicObject)it.next();
				if (!obj.hasProperty("Units") || ((RadioProperty)obj.getProperty("Units")).is("data"))
				{
					r.setClipping(obj.Clipping.isSet());
					obj.draw(r);
					it.remove();
				}
			}

			// Final pass
			it = objList.iterator();
			while (it.hasNext())
			{
				GraphicObject obj = (GraphicObject)it.next();
				r.setClipping(obj.Clipping.isSet());
				obj.draw(r);
			}
		}

		r.setClipping(false);
		r.end();
		
		if (zoomBox)
		{
			drawZoomBox(xPrev, yPrev);
		}
	}

	/* TODO: remove
	void autoSet(Property p, Object value)
	{
		autoMode++;
		p.set(value, true);
		autoMode--;
	}

	boolean isAutoMode()
	{
		return (autoMode > 0);
	}
	*/
	
	protected void autoScale()
	{
		autoScaleX();
		autoScaleY();
		autoScaleZ();
	}

	protected double[] getChildrenLimits(String Lim, boolean logMode, boolean isZ)
	{
		String LimInclude = Lim+"Include";
		double[] lim = (logMode ?
				new double[] { Double.POSITIVE_INFINITY, Double.MIN_VALUE } :
				new double[] { Double.POSITIVE_INFINITY, Double.NEGATIVE_INFINITY });

		for (int i=0; i<Children.size(); i++)
		{
			GraphicObject go = (GraphicObject)Children.elementAt(i);
			if (go.Visible.isSet() && ((BooleanProperty)go.getProperty(LimInclude)).isSet())
			{
				double[] _lim = ((VectorProperty)go.getProperty(Lim)).getArray();
				if (logMode)
				{
					lim[0] = Math.min(_lim[2], lim[0]);
					lim[1] = Math.max(_lim[3], lim[1]);
				}
				else
				{
					lim[0] = Math.min(_lim[0], lim[0]);
					lim[1] = Math.max(_lim[1], lim[1]);
				}
			}
		}

		if (logMode)
		{
			if (lim[0] > lim[1])
			{
				lim[0] = 1;
				lim[1] = 10;
			}
		}
		else
		{
			if (lim[0] > lim[1])
			{
				lim[0] = (isZ ? -0.5 : 0);
				lim[1] = (isZ ? 0.5 : 1);
			}
			else if (lim[0] == lim[1])
			{
				lim[0] -= 0.5;
				lim[1] += 0.5;
			}
		}

		return lim;
	}

	protected double getTickInterval(double[] lim, int nMax)
	{
		double range = (lim[1]-lim[0]);
		double power = Math.pow(10, Math.floor(Math.log10(range)));
		double ndec = range/power;
		double ntickdec = nMax/ndec;
		double tick;

		if (ntickdec > 40)
			tick = 0.05;
		else if (ntickdec > 20)
			tick = 0.1;
		else if (ntickdec > 10)
			tick = 0.2;
		else if (ntickdec > 4)
			tick = 0.5;
		else if (ntickdec > 1.5)
			tick = 1;
		else if (ntickdec > 0.5)
			tick = 2;
		else
			tick = Math.ceil(ndec);

		return (tick*power);
	}

	protected void autoAxis(VectorProperty Lim, boolean autoLim, VectorProperty Tick, boolean autoTick, RadioProperty Scale, boolean isZ)
	{
		double[] lim = (autoLim ? getChildrenLimits(Lim.getName(), Scale.is("log"), isZ) : Lim.getArray());

		if (Scale.is("linear"))
		{
			double tickVal = getTickInterval(lim, 10);

			if (autoLim)
			{
				lim[0] = Math.floor(lim[0]/tickVal) * tickVal;
				lim[1] = Math.ceil(lim[1]/tickVal) * tickVal;
				autoSet(Lim, lim);
			}

			if (autoTick)
			{
				double vmin = Math.ceil(lim[0]/tickVal) * tickVal;
				double vmax = Math.floor(lim[1]/tickVal) * tickVal;
				int nv = (int)Math.round((vmax-vmin)/tickVal+1);
				double[] tickV = new double[nv];

				for (int i=0; i<nv; i++)
					tickV[i] = vmin + i * tickVal;
				autoSet(Tick, tickV);
			}
		}
		else
		{
			if (autoLim)
			{
				lim[0] = Math.pow(10, Math.floor(Math.log10(lim[0])));
				lim[1] = Math.pow(10, Math.ceil(Math.log10(lim[1])));
				autoSet(Lim, lim);
			}

			if (autoTick)
			{
				int n1 = (int)Math.ceil(Math.log10(lim[0])),
				    n2 = (int)Math.floor(Math.log10(lim[1]));
				double[] tickV = new double[n2-n1+1];
				for (int i=0; i<tickV.length; i++)
					tickV[i] = Math.pow(10, n1+i);
				autoSet(Tick, tickV);
			}
		}
	}

	/*
	protected double[] computeAutoScale(String Lim, RadioProperty Scale, boolean isZ)
	{
			double[] lim;
			String LimInclude = Lim+"Include";

			if (Scale.is("linear"))
			{
				lim = new double[] { Double.POSITIVE_INFINITY, Double.NEGATIVE_INFINITY };
				for (int i=0; i<Children.size(); i++)
				{
					GraphicObject go = (GraphicObject)Children.elementAt(i);
					if (go.Visible.isSet() && ((BooleanProperty)go.getProperty(LimInclude)).isSet())
					{
						double[] _lim = ((VectorProperty)go.getProperty(Lim)).getArray();
						lim[0] = Math.min(_lim[0], lim[0]);
						lim[1] = Math.max(_lim[1], lim[1]);
					}
				}

				if (lim[0] > lim[1])
				{
					lim[0] = (isZ ? -0.5 : 0);
					lim[1] = (isZ ? 0.5 : 1);
				}
				else if (lim[0] == lim[1])
				{
					lim[0] -= 0.5;
					lim[1] += 0.5;
				}

				double dl = lim[1]-lim[0];
				if (dl > 10)
				{
					lim[0] = Math.floor(lim[0]);
					lim[1] = Math.ceil(lim[1]);
				}
			}
			else
			{
				lim = new double[] { Double.POSITIVE_INFINITY, Double.MIN_VALUE };
				for (int i=0; i<Children.size(); i++)
				{
					GraphicObject go = (GraphicObject)Children.elementAt(i);
					if (((BooleanProperty)go.getProperty(LimInclude)).isSet())
					{
						double[] _lim = ((VectorProperty)go.getProperty(Lim)).getArray();
						lim[0] = Math.min(_lim[2], lim[0]);
						lim[1] = Math.max(_lim[3], lim[1]);
					}
				}

				if (lim[0] > lim[1])
				{
					lim[0] = 1;
					lim[1] = 10;
				}
				lim[0] = Math.pow(10, Math.floor(Math.log10(lim[0])));
				lim[1] = Math.pow(10, Math.ceil(Math.log10(lim[1])));
			}

			return lim;
	}
	*/

	protected void autoScaleX()
	{
		/*
		if (XLimMode.is("auto") && Children.size() > 0)
		{
			double[] xlim = computeAutoScale("XLim", XScale, false);
			autoSet(XLim, xlim);
			autoTickX();
		}
		*/

		if (XLimMode.is("auto") || XTickMode.is("auto"))
		{
			autoAxis(XLim, XLimMode.is("auto"), XTick, XTickMode.is("auto"), XScale, false);
			autoMinorTickX();
			autoTickLabelX();
		}
	}

	protected void autoScaleY()
	{
		/*
		if (YLimMode.is("auto") && Children.size() > 0)
		{
			double[] ylim = computeAutoScale("YLim", YScale, false);
			autoSet(YLim, ylim);
			autoTickY();
		}
		*/

		if (YLimMode.is("auto") || YTickMode.is("auto"))
		{
			autoAxis(YLim, YLimMode.is("auto"), YTick, YTickMode.is("auto"), YScale, false);
			autoMinorTickY();
			autoTickLabelY();
		}
	}

	protected void autoScaleZ()
	{
		/*
		if (ZLimMode.is("auto") && Children.size() > 0)
		{
			double[] zlim = computeAutoScale("ZLim", ZScale, true);
			autoSet(ZLim, zlim);
			autoTickZ();
		}
		*/

		if (ZLimMode.is("auto") || ZTickMode.is("auto"))
		{
			autoAxis(ZLim, ZLimMode.is("auto"), ZTick, ZTickMode.is("auto"), ZScale, true);
			autoMinorTickZ();
			autoTickLabelZ();
		}
	}

	protected void autoScaleC()
	{
		if (CLimMode.is("auto") && Children.size() > 0)
		{
			double[] clim = { Double.POSITIVE_INFINITY, Double.NEGATIVE_INFINITY };

			for (int i=0; i<Children.size(); i++)
			{
				GraphicObject child = (GraphicObject)Children.elementAt(i);
				String mapping;

				try	{ mapping = (String)child.get("CDataMapping"); }
				catch (PropertyException e) { mapping = ""; }

				if (child.CLimInclude.isSet() && mapping.equals("scaled"))
				{
					double[] _clim = child.CLim.getArray();
					clim[0] = Math.min(clim[0], _clim[0]);
					clim[1] = Math.max(clim[1], _clim[1]);
				}
			}

			if (clim[0] > clim[1])
			{
				clim[0] = 0.0;
				clim[1] = 1.0;
			}

			autoSet(CLim, clim);
		}
	}

	protected void autoScaleA()
	{
	}

	protected void autoTick()
	{
		autoTickX();
		autoTickY();
		autoTickZ();
	}

	/*
	protected double[] computeAutoTicks(VectorProperty Lim, RadioProperty Scale)
	{
			double vmin = Lim.getArray()[0], vmax = Lim.getArray()[1];
			double[] ticks;
			if (Scale.is("linear"))
			{
				ticks = new double[5];
				for (int i=0; i<ticks.length; i++)
					ticks[i] = vmin + i * (vmax - vmin) / (ticks.length - 1);
			}
			else
			{
				int n1 = (int)Math.ceil(Math.log10(vmin)),
				    n2 = (int)Math.floor(Math.log10(vmax));
				ticks = new double[n2-n1+1];
				for (int i=0; i<ticks.length; i++)
					ticks[i] = Math.pow(10, n1+i);
			}
			return ticks;
	}
	*/

	protected double[] computeMinorTicks(VectorProperty Lim, VectorProperty Tick, RadioProperty Scale)
	{
		double[] mticks;

		if (Scale.is("linear"))
			mticks = new double[0];
		else
		{
			ArrayList tl = new ArrayList();
			double[] lim = Lim.getArray(), ticks = Tick.getArray();
			double v1 = lim[0], v2;
			for (int i=0; i<=ticks.length; i++)
			{
				v2 = (i < ticks.length ? ticks[i] : lim[1]);
				if (v1 < v2)
				{
					double b = Math.pow(10, Math.floor(Math.log10(v1)));
					if (v2 >= b*10)
					{
						double v = b*(Math.floor(v1/b)+1);
						while (v < v2)
						{
							tl.add(new Double(v));
							v += b;
							if (v >= 10*b)
								b *= 10;
						}
					}
				}
				v1 = v2;
			}
			mticks = new double[tl.size()];
			for (int i=0; i<mticks.length; i++)
				mticks[i] = ((Double)tl.get(i)).doubleValue();
		}
		return mticks;
	}

	protected void autoTickX()
	{
		/*
		if (XTickMode.is("auto"))
		{
			double[] ticks = computeAutoTicks(XLim, XScale);
			autoSet(XTick, ticks);
		}
		autoMinorTickX();
		autoTickLabelX();
		*/
		autoScaleX();
	}

	protected void autoMinorTickX()
	{
		x_minorTicks = computeMinorTicks(XLim, XTick, XScale);
	}

	protected void autoTickY()
	{
		/*
		if (YTickMode.is("auto"))
		{
			double[] ticks = computeAutoTicks(YLim, YScale);
			autoSet(YTick, ticks);
		}
		autoMinorTickY();
		autoTickLabelY();
		*/
		autoScaleY();
	}

	protected void autoMinorTickY()
	{
		y_minorTicks = computeMinorTicks(YLim, YTick, YScale);
	}

	protected void autoTickZ()
	{
		/*
		if (ZTickMode.is("auto"))
		{
			double[] ticks = computeAutoTicks(ZLim, ZScale);
			autoSet(ZTick, ticks);
		}
		autoMinorTickZ();
		autoTickLabelZ();
		*/
		autoScaleZ();
	}

	protected void autoMinorTickZ()
	{
		z_minorTicks = computeMinorTicks(ZLim, ZTick, ZScale);
	}

	protected void autoTickLabel()
	{
		autoTickLabelX();
		autoTickLabelY();
		autoTickLabelZ();
	}

	private boolean allPowerOf10(double[] ticks)
	{
		boolean result = true;
		for (int i=0; i<ticks.length && result; i++)
		{
			double n = Math.log10(ticks[i]);
			result = (result && (Math.floor(n) == n));
		}
		return result;
	}

	private boolean isInteger(double val)
	{
		return ((double)Math.floor(val) == val);
	}

	protected boolean computeAutoTickLabels(VectorProperty Tick, RadioProperty Scale, StringArrayProperty TickLabel)
	{
		boolean retval = false;
		double[] ticks = Tick.getArray();
		String[] labels = new String[ticks.length];
		if (Scale.is("linear") || !allPowerOf10(ticks))
			for (int i=0; i<ticks.length; i++)
			{
				if (isInteger(ticks[i]))
					labels[i] = Long.toString(Math.round(ticks[i]));
				else
				{
					double val = ((double)Math.round(ticks[i]*100))/100;
					labels[i] = Double.toString(val);
				}
			}
		else
		{
			for (int i=0; i<ticks.length; i++)
			{
				double v = Math.log10(ticks[i]);
				if (Math.floor(v) == v)
					labels[i] = Integer.toString((int)v);
				else
					labels[i] = Double.toString(v);
			}
			retval = true;
		}
		autoSet(TickLabel, labels);
		return retval;
	}

	protected void autoTickLabelX()
	{
		if (XTickLabelMode.is("auto"))
			x_logTickLabels = computeAutoTickLabels(XTick, XScale, XTickLabel);
	}

	protected void autoTickLabelY()
	{
		if (YTickLabelMode.is("auto"))
			y_logTickLabels = computeAutoTickLabels(YTick, YScale, YTickLabel);
	}

	protected void autoTickLabelZ()
	{
		if (ZTickLabelMode.is("auto"))
			z_logTickLabels = computeAutoTickLabels(ZTick, ZScale, ZTickLabel);
	}

	protected void autoCamera()
	{
		updateXFormMatrices();
	}

	protected void autoAspectRatio()
	{
		double dx = XLim.elementAt(1)-XLim.elementAt(0);
		double dy = YLim.elementAt(1)-YLim.elementAt(0);
		double dz = ZLim.elementAt(1)-ZLim.elementAt(0);
		
		if (DataAspectRatioMode.is("auto"))
		{
			double dmin = Math.min(Math.min(dx, dy), dz);
			autoSet(DataAspectRatio, new double[] {dx/dmin, dy/dmin, dz/dmin});
		}
		if (PlotBoxAspectRatioMode.is("auto"))
		{
			if (DataAspectRatioMode.is("auto"))
				autoSet(PlotBoxAspectRatio, new double[] {1,1,1});
			else
			{
				double[] daspect = DataAspectRatio.getArray();
				autoSet(PlotBoxAspectRatio, new double[] {
					dx/daspect[0],
					dy/daspect[1],
					dz/daspect[2]});
			}
		}
		// TODO: if plotboxaspectratiomode is "manual", limits
		// and/or dataaspectratio might be adapted
	}

	private void doZoom(int x1, int y1, int x2, int y2)
	{
		double[] pos1 = new double[3], pos2 = new double[3];

		unTransform((double)x1, (double)y1, (x_zmin+x_zmax)/2, pos1, 0);
		unTransform((double)x2, (double)y2, (x_zmin+x_zmax)/2, pos2, 0);
		zoomStack.push(XLimMode.get());
		zoomStack.push(XLim.get());
		zoomStack.push(YLimMode.get());
		zoomStack.push(YLim.get());
		autoMode++;
		XLim.set(new double[] {Math.min(pos1[0], pos2[0]), Math.max(pos1[0], pos2[0])}, true);
		XLimMode.set("manual", true);
		YLim.set(new double[] {Math.min(pos1[1], pos2[1]), Math.max(pos1[1], pos2[1])}, true);
		YLimMode.set("manual", true);
		autoMode--;
		autoTick();
		autoAspectRatio();
		autoCamera();
		getCanvas().redraw();
	}

	public void unZoom()
	{
		if (zoomStack.size() >= 4)
		{
			autoMode++;
			YLim.set(zoomStack.pop(), true);
			YLimMode.set(zoomStack.pop(), true);
			XLim.set(zoomStack.pop(), true);
			XLimMode.set(zoomStack.pop(), true);
			autoMode--;
			autoTick();
			autoAspectRatio();
			autoCamera();
			getCanvas().redraw();
		}
	}

	private void drawZoomBox(int x, int y)
	{
		getCanvas().getRenderer().drawRubberBox(new int[][] {{xAnchor, yAnchor, x, y}});
	}

	private void drawZoomBox(int x1, int y1, int x2, int y2)
	{
		getCanvas().getRenderer().drawRubberBox(new int[][]
				{{xAnchor, yAnchor, x1, y1},
				 {xAnchor, yAnchor, x2, y2}});
	}

	public void startOperation(int op, MouseEvent e)
	{
		xAnchor = xPrev = e.getX();
		yAnchor = yPrev = e.getY();

		switch (op)
		{
			case FigureObject.OP_ZOOM:
				// start zoom box only in 2D mode
				if (zstate == AXE_DEPTH_DIR && xstate == AXE_HORZ_DIR && ystate == AXE_VERT_DIR)
				{
					drawZoomBox(xPrev, yPrev);
					zoomBox = true;
				}
				break;
			case FigureObject.OP_ROTATE:
				boundingBox = getBoundingBox();
				break;
		}
	}

	public void endOperation(int op, MouseEvent e)
	{
		switch (op)
		{
			case FigureObject.OP_ZOOM:
				if (zoomBox)
				{
					drawZoomBox(xPrev, yPrev);
					zoomBox = false;
					if (xPrev != xAnchor && yPrev != yAnchor)
						doZoom(xAnchor, yAnchor, xPrev, yPrev);
				}
				break;
			case FigureObject.OP_ROTATE:
				boundingBox = null;
				break;
		}
	}

	public void cancelOperation(int op)
	{
		switch (op)
		{
			case FigureObject.OP_ZOOM:
				if (zoomBox)
				{
					drawZoomBox(xPrev, yPrev);
					zoomBox = false;
				}
				break;
			case FigureObject.OP_ROTATE:
				boundingBox = null;
				break;
		}
	}

	public void operation(int op, MouseEvent e)
	{
		switch (op)
		{
			case FigureObject.OP_ROTATE:
				double new_anglex = View.getArray()[1], new_anglez = View.getArray()[0];

				// TODO: use actual axes size
				new_anglez += (xPrev-e.getX()) * (180.0/boundingBox.width);
				new_anglex += (e.getY()-yPrev) * (180.0/boundingBox.height);

				// clipping
				if (new_anglex > 90) new_anglex = 90;
				else if (new_anglex < -90) new_anglex = -90;
				if (new_anglez > 180) new_anglez -= 360;
				else if (new_anglez < -180) new_anglez += 360;

				// snapping
				double margin = 1;
				for (int alpha = -90; alpha <= 90; alpha += 90)
					if (alpha-margin < new_anglex && new_anglex < alpha+margin)
						new_anglex = alpha;
				for (int alpha = -180; alpha <= 180; alpha += 90)
					if (alpha-margin < new_anglez && new_anglez < alpha+margin)
						if (alpha == 180)
							new_anglez = -180;
						else
							new_anglez = alpha;

				try { set(View, new double[] {new_anglez, new_anglex}); }
				catch (PropertyException ex) {}
				xPrev = e.getX();
				yPrev = e.getY();

				getCanvas().redraw();
				break;
			case FigureObject.OP_ZOOM:
				if (zoomBox)
				{
					drawZoomBox(xPrev, yPrev, e.getX(), e.getY());
					xPrev = e.getX();
					yPrev = e.getY();
				}
				break;
		}
	}

	double[] convertUnits(double[] pos, String units)
	{
		return convertUnits(pos, units, "data");
	}

	double[] convertUnits(double[] pos, String units, String toUnits)
	{
		double[] p;
		double dz = (x_zmax-x_zmin), z1 = x_zmin;

		if (units.equalsIgnoreCase("data"))
			p = (double[])pos.clone();
		else
		{
			Rectangle bb = getBoundingBox();
			double hc = getCanvas().getHeight();
			double dpi = Utils.getScreenResolution();

			if (units.equalsIgnoreCase("pixels"))
				p = (double[])pos.clone();
			else if (units.equalsIgnoreCase("normalized"))
				p = new double[] {pos[0]*bb.width, pos[1]*bb.height, dz*pos[2]};
			else if (units.equalsIgnoreCase("inches"))
				p = new double[] {pos[0]*dpi, pos[1]*dpi, pos[2]*dpi};
			else if (units.equalsIgnoreCase("centimeters"))
				p = new double[] {pos[0]*dpi/2.54, pos[1]*dpi/2.54, pos[2]*dpi/2.54};
			else if (units.equalsIgnoreCase("points"))
				p = new double[] {pos[0]*dpi/72.0, pos[1]*dpi/72.0, pos[2]*dpi/72.0};
			else
				p = new double[] {0, 0, 0};
			unTransform(bb.x+p[0], hc-(bb.y+p[1]), z1+p[2], p, 0);
		}

		if (!toUnits.equalsIgnoreCase("data"))
		{
			Rectangle bb = getBoundingBox();
			double hc = getCanvas().getHeight();
			double dpi = Utils.getScreenResolution();

			transform(p[0], p[1], p[2], p, 0);
			p[0] -= bb.x;
			p[1] = hc-bb.y-p[1];
			p[2] -= z1;
			
			if (toUnits.equalsIgnoreCase("normalized"))
			{
				p[0] /= bb.width;
				p[1] /= bb.height;
				p[2] /= dz;
			}
			else if (toUnits.equalsIgnoreCase("inches"))
			{
				p[0] /= dpi;
				p[1] /= dpi;
				p[2] /= dpi;
			}
			else if (toUnits.equalsIgnoreCase("centimeters"))
			{
				p[0] /= dpi/2.54;
				p[1] /= dpi/2.54;
				p[2] /= dpi/2.54;
			}
			else if (toUnits.equalsIgnoreCase("points"))
			{
				p[0] /= dpi/72.0;
				p[1] /= dpi/72.0;
				p[2] /= dpi/72.0;
			}
		}

		return p;
	}

	Matrix convertCData(Matrix cdata, String mapping)
	{
		double[] clim = CLim.getArray();
		double[][] cmap = getFigure().Colormap.asDoubleMatrix();
		boolean isScaled = mapping.equals("scaled");
		Matrix c;

		int ndims = cdata.getNDims();
		int[] dims = new int[ndims+1];
		for (int i=0; i<ndims; i++)
			dims[i] = cdata.getDim(i);
		dims[ndims] = 3;

		if (cdata.getClassName().equals("double"))
		{
			double[] buf = cdata.toDouble();
			int len = buf.length;
			double[] cbuf = new double[len*3];

			for (int i=0; i<len; i++)
			{
				int index = (isScaled ?
						(int)Math.round((cmap.length-1)*(buf[i]-clim[0])/(clim[1]-clim[0])) :
						(int)Math.round(buf[i]-1));
				if (index < 0) index = 0;
				else if (index >= cmap.length) index = cmap.length-1;
				cbuf[i+0*len] = cmap[index][0];
				cbuf[i+1*len] = cmap[index][1];
				cbuf[i+2*len] = cmap[index][2];
			}

			c = new Matrix(cbuf, dims);
		}
		else
			c = new Matrix();

		return c;
	}

	double[][] convertCData(double[] cdata, String mapping)
	{
		double[] clim = CLim.getArray();
		double[][] cmap = getFigure().Colormap.asDoubleMatrix();
		double[][] c = new double[cdata.length][];

		if (mapping.equals("scaled"))
			for (int i=0; i<cdata.length; i++)
			{
				int index = (int)Math.round((cmap.length-1)*(cdata[i]-clim[0])/(clim[1]-clim[0]));
				if (index < 0) index = 0;
				else if (index >= cmap.length) index = cmap.length-1;
				c[i] = cmap[index];
			}
		else
			for (int i=0; i<cdata.length; i++)
			{
				int index = (int)Math.round(cdata[i]);
				if (index < 0) index = 0;
				else if (index >= cmap.length) index = cmap.length-1;
				c[i] = cmap[index];
			}

		return c;
	}

	double[][][] convertCData(double[][] cdata, String mapping)
	{
		double[] clim = CLim.getArray();
		double[][] cmap = getFigure().Colormap.asDoubleMatrix();
		double[][][] c = new double[cdata.length][cdata[0].length][];
		boolean scaled = mapping.equals("scaled");

		if (mapping.equals("scaled"))
			for (int i=0; i<cdata.length; i++)
				for (int j=0; j<cdata[i].length; j++)
				{
					int index = (int)Math.round((cmap.length-1)*(cdata[i][j]-clim[0])/(clim[1]-clim[0]));
					if (index < 0) index = 0;
					else if (index >= cmap.length) index = cmap.length-1;
					//System.arraycopy(cmap[index], 0, c[i][j], 0, 3);
					c[i][j] = cmap[index];
				}
		else
			for (int i=0; i<cdata.length; i++)
				for (int j=0; j<cdata[i].length; j++)
				{
					int index = (int)Math.round(cdata[i][j]);
					if (index < 0) index = 0;
					else if (index >= cmap.length) index = cmap.length-1;
					c[i][j] = cmap[index];
				}
		return c;
	}

	double[][] convertCDataToIndex(double[][] cdata)
	{
		double[] clim = CLim.getArray();
		double[][] cmap = getFigure().Colormap.asDoubleMatrix();
		double[][]c = new double[cdata.length][cdata[0].length];

		for (int i=0; i<cdata.length; i++)
			for (int j=0; j<cdata[i].length; j++)
				c[i][j] = (cdata[i][j]-clim[0])/(clim[1]-clim[0]);

		return c;
	}

	public void propertyChanged(Property p) throws PropertyException
	{
		super.propertyChanged(p);
		
		RenderCanvas canvas = getCanvas();

		if (autoMode == 0)
		{
			if (p == XLim)
			{
				XLimMode.set("manual");
				autoTickX();
			}
			else if (p == YLim)
			{
				YLimMode.set("manual");
				autoTickY();
			}
			else if (p == ZLim)
			{
				ZLimMode.set("manual");
				autoTickZ();
			}
			else if (p == XLimMode)
			{
				if (XLimMode.is("auto"))
					autoScaleX();
			}
			else if (p == YLimMode)
			{
				if (YLimMode.is("auto"))
					autoScaleY();
			}
			else if (p == ZLimMode)
			{
				if (ZLimMode.is("auto"))
					autoScaleZ();
			}
			else if (p == XTick)
			{
				XTickMode.set("manual");
				autoMinorTickX();
				autoTickLabelX();
			}
			else if (p == YTick)
			{
				YTickMode.set("manual");
				autoMinorTickY();
				autoTickLabelY();
			}
			else if (p == ZTick)
			{
				ZTickMode.set("manual");
				autoMinorTickZ();
				autoTickLabelZ();
			}
			else if (p == XTickMode)
			{
				if (XTickMode.is("auto"))
					autoTickX();
			}
			else if (p == YTickMode)
			{
				if (YTickMode.is("auto"))
					autoTickY();
			}
			else if (p == ZTickMode)
			{
				if (ZTickMode.is("auto"))
					autoTickZ();
			}
			else if (p == XTickLabel)
				XTickLabelMode.set("manual");
			else if (p == YTickLabel)
				YTickLabelMode.set("manual");
			else if (p == ZTickLabel)
				ZTickLabelMode.set("manual");
			else if (p == XTickLabelMode)
			{
				if (XTickLabelMode.is("auto"))
					autoTickLabelX();
			}
			else if (p == YTickLabelMode)
			{
				if (YTickLabelMode.is("auto"))
					autoTickLabelY();
			}
			else if (p == ZTickLabelMode)
			{
				if (ZTickLabelMode.is("auto"))
					autoTickLabelZ();
			}
			else if (p == TickDir)
				TickDirMode.set("manual");
			else if (p == CLim)
				CLimMode.set("manual");
			else if (p == CLimMode)
			{
				if (CLimMode.is("auto"))
					autoScaleC();
			}
			else if (p == ALim)
				ALimMode.set("manual");
			else if (p == ALimMode)
			{
				if (ALimMode.is("auto"))
					autoScaleA();
			}
			else if (p == CameraTarget)
				CameraTargetMode.set("manual");
			else if (p == CameraTargetMode)
			{
				if (CameraTargetMode.is("auto"))
					autoCamera();
			}
			else if (p == CameraPosition)
				CameraPositionMode.set("manual");
			else if (p == CameraPositionMode)
			{
				if (CameraPositionMode.is("auto"))
					autoCamera();
			}
			else if (p == CameraUpVector)
				CameraUpVectorMode.set("manual");
			else if (p == CameraUpVectorMode)
			{
				if (CameraUpVectorMode.is("auto"))
					autoCamera();
			}
			else if (p == CameraViewAngle)
				CameraViewAngleMode.set("manual");
			else if (p == CameraViewAngleMode)
			{
				if (CameraViewAngleMode.is("auto"))
					autoCamera();
			}
			else if (p == DataAspectRatio)
			{
				DataAspectRatioMode.set("manual");
				autoAspectRatio();
				autoCamera();
			}
			else if (p == DataAspectRatioMode)
			{
				if (DataAspectRatioMode.is("auto"))
				{
					autoAspectRatio();
					autoCamera();
				}
			}
			else if (p == PlotBoxAspectRatio)
			{
				PlotBoxAspectRatioMode.set("manual");
				autoAspectRatio();
				autoCamera();
			}
			else if (p == PlotBoxAspectRatioMode)
			{
				if (PlotBoxAspectRatioMode.is("auto"))
				{
					autoAspectRatio();
					autoCamera();
				}
			}
			else if (p == OuterPosition)
			{
				updatePosition();
				ActivePositionProperty.set("outerposition");
			}
			else if (p == Position)
			{
				updateOuterPosition();
				ActivePositionProperty.set("position");
			}
		} /* autoMode == 0 */

		if (p == View)
			autoCamera();
		else if (p == Units)
		{
			OuterPosition.reset(Utils.convertPosition(OuterPosition.getArray(), currentUnits, Units.getValue(), canvas.getComponent()));
			Position.reset(Utils.convertPosition(Position.getArray(), currentUnits, Units.getValue(), canvas.getComponent()));
			currentUnits = Units.getValue();
		}
		else if (p == XScale)
		{
			autoSet(XMinorTick, new Boolean(XScale.is("log")));
			autoScaleX();
		}
		else if (p == YScale)
		{
			autoSet(YMinorTick, new Boolean(YScale.is("log")));
			autoScaleY();
		}
		else if (p == ZScale)
		{
			autoSet(ZMinorTick, new Boolean(ZScale.is("log")));
			autoScaleZ();
		}

		if (autoMode == 0 && (p == XLim || p == YLim || p == ZLim ||
			p == XLimMode || p == YLimMode || p == ZLimMode ||
			p == XDir || p == YDir || p == ZDir || p == Position || p == OuterPosition ||
			p == XScale || p == YScale || p == ZScale))
		{
			zoomStack.clear();
			autoAspectRatio();
			autoCamera();
		}

		if (p.getParent() != this)
		{
			String name = p.getName();

			if (name.equals("XLim"))
				autoScaleX();
			else if (name.equals("YLim"))
				autoScaleY();
			else if (name.equals("ZLim"))
				autoScaleZ();
			else if (name.equals("CLim"))
				autoScaleC();
			else if (name.equals("Visible"))
				autoScale();
			else if (name.equals("KeyLabel") && Key.isSet())
				autoLegend();
			autoCamera();
		}
	}

	/* Transformation computation */

	Matrix3D x_view = new Matrix3D();
	Matrix3D x_projection = new Matrix3D();
	Matrix3D x_viewport = new Matrix3D();
	Matrix3D x_normrender = new Matrix3D();
	Matrix3D x_render = new Matrix3D();
	Matrix3D x_renderInv;
	Matrix3D x_mat1 = new Matrix3D();
	Matrix3D x_mat2 = new Matrix3D();
	double x_zmin, x_zmax;

	public void updateScalers()
	{
		sx = (XScale.is("linear") ? linScale : logScale);
		sy = (YScale.is("linear") ? linScale : logScale);
		sz = (ZScale.is("linear") ? linScale : logScale);
	}

	public void unTransform(double x, double y, double z, double[] p, int offset)
	{
		x_renderInv.transform(x, y, z, p, offset);
		p[0+offset] = sx.unscale(p[0+offset]);
		p[1+offset] = sy.unscale(p[1+offset]);
		p[2+offset] = sz.unscale(p[2+offset]);
	}

	public void transform(double x, double y, double z, double[] p, int offset)
	{
		x_render.transform(sx.scale(x), sy.scale(y), sz.scale(z), p, offset);
	}

	public void updateXFormMatrices()
	{
		updateScalers();

		RenderCanvas canvas = getCanvas();
		double xd = (XDir.is("normal") ? 1 : -1);
		double yd = (YDir.is("normal") ? 1 : -1);
		double zd = (ZDir.is("normal") ? 1 : -1);

		double[] xlim = sx.scale(XLim.getArray());
		double[] ylim = sy.scale(YLim.getArray());
		double[] zlim = sz.scale(ZLim.getArray());

		double xo = xlim[xd > 0 ? 0 : 1];
		double yo = ylim[yd > 0 ? 0 : 1];
		double zo = zlim[zd > 0 ? 0 : 1];

		double[] pb = PlotBoxAspectRatio.getArray();

		boolean autocam = CameraPositionMode.is("auto") &&
				CameraTargetMode.is("auto") && CameraUpVectorMode.is("auto") &&
				CameraViewAngleMode.is("auto");
		boolean dowarp = autocam && DataAspectRatioMode.is("auto") &&
				PlotBoxAspectRatioMode.is("auto");

		Vector3D c_eye;
		Vector3D c_center;
		Vector3D c_upv;

		if (CameraTargetMode.is("auto"))
		{
			double[] p = new double[] {(xlim[0]+xlim[1])/2, (ylim[0]+ylim[1])/2, (zlim[0]+zlim[1])/2};
			c_center = new Vector3D(p);
			autoSet(CameraTarget, p);
		}
		else
			c_center = new Vector3D(CameraTarget.getArray());

		if (CameraPositionMode.is("auto"))
		{
			double az = View.getArray()[0];
			double el = View.getArray()[1];
			double d = 5*Math.sqrt(pb[0]*pb[0]+pb[1]*pb[1]+pb[2]*pb[2]);

			if (el == 90 || el == -90)
				c_eye = new Vector3D(new double[] {0, 0, d*Math.signum(el)});
			else
			{
				az *= Math.PI/180.0;
				el *= Math.PI/180.0;
				c_eye = new Vector3D(new double[] {
					d*Math.cos(el)*Math.sin(az),
					-d*Math.cos(el)*Math.cos(az),
					d*Math.sin(el)}, false);
			}
			c_eye.scale((xlim[1]-xlim[0])/(xd*pb[0]), (ylim[1]-ylim[0])/(yd*pb[1]), (zlim[1]-zlim[0])/(zd*pb[2]));
			c_eye.add(c_center);
			autoSet(CameraPosition, c_eye.getData().clone());
		}
		else
			c_eye = new Vector3D(CameraPosition.getArray());

		if (CameraUpVectorMode.is("auto"))
		{
			double az = View.getArray()[0];
			double el = View.getArray()[1];

			if (el == 90 || el == -90)
			{
				c_upv = new Vector3D(new double[] {
					-Math.sin(az*Math.PI/180.0),
					Math.cos(az*Math.PI/180.0),
					0});
				c_upv.scale((xlim[1]-xlim[0])/(/*xd**/pb[0]), (ylim[1]-ylim[0])/(/*yd**/pb[1]), 0);
			}
			else
				c_upv = new Vector3D(new double[] {0,0,1}, false);
			autoSet(CameraUpVector, c_upv.getData().clone());
		}
		else
			c_upv = new Vector3D(CameraUpVector.getArray());

		x_view.eye();
		x_projection.eye();
		x_viewport.eye();
		x_normrender.eye();
		x_render.eye();

		Matrix3D x_pre = new Matrix3D();

		x_pre.scale(pb[0], pb[1], pb[2]);
		x_pre.translate(-0.5, -0.5, -0.5);
		x_pre.scale(xd/(xlim[1]-xlim[0]), yd/(ylim[1]-ylim[0]), zd/(zlim[1]-zlim[0]));
		x_pre.translate(-xo, -yo, -zo);

		c_eye.transform(x_pre);
		c_center.transform(x_pre);
		c_upv.scale(
			pb[0]/**xd*//(xlim[1]-xlim[0]),
			pb[1]/**yd*//(ylim[1]-ylim[0]),
			pb[2]/**zd*//(zlim[1]-zlim[0]));
		c_center.sub(c_eye);

		Vector3D F = c_center;
		Vector3D f = Vector3D.normalize(F);
		Vector3D UP = Vector3D.normalize(c_upv);

		if (Math.abs(Vector3D.dot(f, UP)) > 1e-15)
		{
			double fa = 1/Math.sqrt(1-f.get(2)*f.get(2));
			UP.scale(fa, fa, fa);
		}

		Vector3D s = Vector3D.cross(f, UP);
		Vector3D u = Vector3D.cross(s, f);

		x_view.scale(1, 1, -1);
		x_view.mult(
			new double[] {
				s.get(0), u.get(0), -f.get(0), 0,
				s.get(1), u.get(1), -f.get(1), 0,
				s.get(2), u.get(2), -f.get(2), 0,
				0, 0, 0, 1});
		x_view.translate(-c_eye.get(0), -c_eye.get(1), -c_eye.get(2));
		x_view.scale(pb[0], pb[1], pb[2]);
		x_view.translate(-0.5, -0.5, -0.5);

		double[] unitCube = {
			0,0,0,1,
			1,0,0,1,
			0,1,0,1,
			0,0,1,1,
			1,1,0,1,
			1,0,1,1,
			0,1,1,1,
			1,1,1,1};
		double[] xUnitCube = new double[32];
		double xm = Double.POSITIVE_INFINITY, xM = Double.NEGATIVE_INFINITY;
		double ym = Double.POSITIVE_INFINITY, yM = Double.NEGATIVE_INFINITY;
		x_view.transform(unitCube, xUnitCube, 8, 0, 0);
		for (int i=0; i<8; i++)
		{
			if (xUnitCube[i*4] < xm) xm = xUnitCube[i*4];
			else if (xUnitCube[i*4] > xM) xM = xUnitCube[i*4];
			if (xUnitCube[i*4+1] < ym) ym = xUnitCube[i*4+1];
			else if (xUnitCube[i*4+1] > yM) yM = xUnitCube[i*4+1];
		}
		xM -= xm;
		yM -= ym;

		Rectangle bb = getBoundingBox();

		if (CameraViewAngleMode.is("auto"))
		{
			double af;
			if (dowarp)
				af = 1/Math.max(xM, yM);
			else
			{
				if (((double)bb.width)/bb.height > xM/yM)
					af = 1/yM;
				else
					af = 1/xM;
			}
			double ang = 2*(180.0/Math.PI)*Math.atan(1/(2*af*F.norm()));
			autoSet(CameraViewAngle, new Double(ang));
		}

		double pf = 1/(2*Math.tan((CameraViewAngle.doubleValue()/2)*Math.PI/180.0)*F.norm());
		x_projection.scale(pf, pf, 1);

		if (dowarp)
		{
			xM *= pf;
			yM *= pf;
			x_viewport.translate(bb.x+bb.width/2, canvas.getHeight()-(bb.y+bb.height/2)+1, 0);
			x_viewport.scale(bb.width/xM, -bb.height/yM, 1);
		}
		else
		{
			double pix = 1;
			if (autocam)
			{
				if (((double)bb.width)/bb.height > xM/yM)
					pix = bb.height;
				else
					pix = bb.width;
			}
			else
				pix = Math.min(bb.width, bb.height);
			x_viewport.translate(bb.x+bb.width/2, canvas.getHeight()-(bb.y+bb.height/2)+1, 0);
			x_viewport.scale(pix, -pix, 1);
		}

		x_normrender.mult(x_viewport);
		x_normrender.mult(x_projection);
		x_normrender.mult(x_view);

		x_normrender.transform(unitCube, xUnitCube, 8, 0, 0);
		x_zmin = Double.POSITIVE_INFINITY;
		x_zmax = Double.NEGATIVE_INFINITY;
		for (int i=0; i<8; i++)
		{
			if (xUnitCube[i*4+2] < x_zmin) x_zmin = xUnitCube[i*4+2];
			else if (xUnitCube[i*4+2] > x_zmax) x_zmax = xUnitCube[i*4+2];
		}

		//System.out.println(x_zmin);
		//System.out.println(x_zmax);

		x_render.mult(x_normrender);
		x_render.scale(xd/(xlim[1]-xlim[0]), yd/(ylim[1]-ylim[0]), zd/(zlim[1]-zlim[0]));
		x_render.translate(-xo, -yo, -zo);
		x_renderInv = x_render.inv();

		x_mat1.eye();
		x_mat1.mult(x_view);
		x_mat1.scale(xd/(xlim[1]-xlim[0]), yd/(ylim[1]-ylim[0]), zd/(zlim[1]-zlim[0]));
		x_mat1.translate(-xo, -yo, -zo);
		x_mat2.eye();
		x_mat2.mult(x_viewport);
		x_mat2.mult(x_projection);
		
		x_NormRenderTransform.reset(new Matrix(x_normrender.getData(), new int[] {4, 4}));
		x_RenderTransform.reset(new Matrix(x_render.getData(), new int[] {4, 4}));
		x_ViewTransform.reset(new Matrix(x_view.getData(), new int[] {4, 4}));
		x_ProjectionTransform.reset(new Matrix(x_projection.getData(), new int[] {4, 4}));
		x_ViewportTransform.reset(new Matrix(x_viewport.getData(), new int[] {4, 4}));
	}
}
