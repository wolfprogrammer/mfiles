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
import java.awt.image.*;
import java.nio.*;
import java.util.*;
import javax.swing.*;
import javax.swing.event.*;
import org.octave.Matrix;

public class FigureObject extends AxesContainer
	implements WindowListener, ComponentListener, ActionListener
{
	private class FigurePanel extends Panel
	{
		FigurePanel()
		{
			super();
		}

		public void paint(Graphics g)
		{
			super.paint(g);
		}

		public void update(Graphics g)
		{
			paint(g);
		}
	}

	private Frame frame;
	private Panel tbPanel;
	private Panel axPanel;

	private int defaultMouseOp = OP_NONE;
	private String currentUnits;

	/* properties */
	VectorProperty              Alphamap;
	CallbackProperty            CloseRequestFcn;
	ColorProperty               /* Color */ FigColor;
	ArrayProperty               Colormap;
	HandleObjectListProperty    CurrentAxes;
	BooleanProperty             IntegerHandle;
	CallbackProperty            KeyPressFcn;
	StringProperty              Name;
	RadioProperty               NextPlot;
	BooleanProperty             NumberTitle;
	RadioProperty               PaperOrientation;
	VectorProperty              Position;
	RadioProperty               Renderer;
	RadioProperty               RendererMode;
	BooleanProperty             Resize;
	CallbackProperty            ResizeFcn;
	RadioProperty               SelectionType;
	RadioProperty               Toolbar;
	RadioProperty               Units;

	BooleanProperty __Dirty__;
	BooleanProperty __Antialias__;

	/* toolbar */
	JToolBar figureTB;
	JToggleButton editBtn;
	JToggleButton zoomBtn;
	JToggleButton rotateBtn;

	// Constructor

	public FigureObject(int fignum)
	{
		super(RootObject.getInstance(), "figure", fignum);

		CurrentAxes = new HandleObjectListProperty(this, "CurrentAxes", 1);
		Name = new StringProperty(this, "Name", "");
		NumberTitle = new BooleanProperty(this, "NumberTitle", true);
		NextPlot = new RadioProperty(this, "NextPlot", new String[] {"new", "add", "replace", "replacechildren"}, "add");
		FigColor = new ColorProperty(this, "Color", Utils.getBackgroundColor());
		Colormap = new ArrayProperty(this, "Colormap", new String[] {"double"}, 2,
			new Matrix(RootObject.getInstance().defaultColorMap()));
		ResizeFcn = new CallbackProperty(this, "ResizeFcn", (String)null);
		CloseRequestFcn = new CallbackProperty(this, "CloseRequestFcn", "closereq");
		double[] amap = new double[64];
		for (int i=0; i<amap.length; i++)
			amap[i] = ((double)i)/(amap.length-1);
		Alphamap = new VectorProperty(this, "Alphamap", -1, amap);
		PaperOrientation = new RadioProperty(this, "PaperOrientation", new String[] {"portrait", "landscape"}, "portrait");
		IntegerHandle = new BooleanProperty(this, "IntegerHandle", true);
		Units = new RadioProperty(this, "Units", new String[] {"pixels", "normalized", "inches", "centimeters",
			"points", "characters"}, "pixels");
		currentUnits = Units.getValue();
		Dimension d = Utils.getScreenSize();
		Position = new VectorProperty(this, "Position", 4, new double[] {10, d.height-500, 600, 430});
		Renderer = new RadioProperty(this, "Renderer", new String[] {"OpenGL", "Java2D"}, "OpenGL");
		RendererMode = new RadioProperty(this, "RendererMode", new String[] {"auto", "manual"}, "auto");
		Toolbar = new RadioProperty(this, "Toolbar", new String[] {"none", "auto", "figure"}, "auto");
		SelectionType = new RadioProperty(this, "SelectionType", new String[] {"normal", "extend", "alt", "open"}, "normal");
		KeyPressFcn = new CallbackProperty(this, "KeyPressFcn", (String)null);
		__Dirty__ = new BooleanProperty(this, "__Dirty__", false);
		__Dirty__.setVisible(false);
		Resize = new BooleanProperty(this, "Resize", true);
		__Antialias__ = new BooleanProperty(this, "__Antialias__", true);
		__Antialias__.setVisible(false);

		listen(Name);
		listen(NumberTitle);
		listen(IntegerHandle);
		listen(Position);
		listen(Units);
		listen(Toolbar);
		listen(Resize);
		listen(Renderer);
		listen(RendererMode);
		listen(Visible);
	}

	// Methods
	
	private void createFigure()
	{
		// setup window frame
		frame = new Frame();
		frame.setBackground(FigColor.getColor());
		frame.addWindowListener(this);
		frame.addComponentListener(this);
		frame.setResizable(Resize.isSet());

		// setup toolbar panel
		tbPanel = new Panel(new GridLayout(1, 1));
		frame.add(tbPanel, BorderLayout.NORTH);

		// dummy toolbar
		figureTB = new JToolBar();
		figureTB.setRollover(true);
		figureTB.setFloatable(false);
		editBtn = new JToggleButton(Utils.loadIcon("edit"));
		editBtn.setActionCommand("edit");
		editBtn.setEnabled(false);
		editBtn.setToolTipText("Edit plot");
		editBtn.addActionListener(this);
		zoomBtn = new JToggleButton(Utils.loadIcon("zoom-original"));
		zoomBtn.setActionCommand("zoom");
		zoomBtn.setToolTipText("Zoom");
		zoomBtn.addActionListener(this);
		rotateBtn = new JToggleButton(Utils.loadIcon("view-refresh"));
		rotateBtn.setActionCommand("rotate");
		rotateBtn.setToolTipText("3D rotation");
		rotateBtn.addActionListener(this);
		figureTB.add(editBtn);
		figureTB.add(zoomBtn);
		figureTB.add(rotateBtn);

		updateToolbars();

		// setup axes panel
		axPanel = new Panel(new PositionLayout());
		frame.add(axPanel, BorderLayout.CENTER);

		// setup RenderCanvas
		axPanel.add(getCanvas().getComponent());

		updateTitle();
		if (Visible.isSet())
			frame.setVisible(true);
		updateFramePosition();
		if (!Visible.isSet())
		{
			frame.layout();
			axPanel.layout();
		}
	}
	
	private void updateHandle()
	{
		double handle = getHandle();
		if (IntegerHandle.isSet() && handle < 0)
			setHandle(RootObject.getInstance().getUnusedFigureNumber());
		else if (!IntegerHandle.isSet() && handle > 0)
			setHandle(newHandle());
	}
	
	public void validate()
	{
		updateHandle();
		createFigure();
		super.validate();
		activate();
	}

	public void removeChild(HandleObject child)
	{
		if (CurrentAxes.size() > 0 && child == CurrentAxes.elementAt(0))
			CurrentAxes.removeAllElements();
		super.removeChild(child);
	}
	
	private void updatePosition()
	{
		Dimension d = Utils.getScreenSize();
		Point pt = axPanel.getLocationOnScreen();
		double[] pos = new double[] {pt.getX()+1, d.height-pt.getY()-axPanel.getHeight()+1,
			axPanel.getWidth(), axPanel.getHeight()};
		autoSet(Position, Utils.convertPosition(pos, "pixels", Units.getValue(), null));
	}

	private void updateFramePosition()
	{
		double[] pos = Utils.convertPosition(Position.getVector(), Units.getValue(), "pixels", null);
		Dimension d = Utils.getScreenSize();
		Insets insets = frame.getInsets();
		pos[0]--;
		pos[1] = d.height-pos[1]-pos[3]+1;
		frame.setBounds((int)pos[0]-insets.left, (int)pos[1]-insets.top-tbPanel.getHeight(),
				(int)pos[2]+insets.left+insets.right, (int)pos[3]+insets.top+insets.bottom+tbPanel.getHeight());
	}

	private void updateTitle()
	{
		String title = (NumberTitle.isSet() ? "Figure " + getHandle() : ""), name = Name.toString();
		if (name.length() > 0)
		{
			if (title.length() > 0)
				title += ": " + name;
			else
				title = name;
		}
		frame.setTitle(title);
	}

	public void updateToolbars()
	{
		if (Toolbar.is("none"))
			tbPanel.remove(figureTB);
		else
			tbPanel.add(figureTB);
		frame.validate();
	}
	
	public void delete()
	{
		if (frame != null && frame.isVisible())
			frame.setVisible(false);
		super.delete();
		//frame.dispose();
		//frame.setVisible(false);
		if (frame != null)
			EventQueue.invokeLater(new Runnable() { public void run() { frame.dispose(); } });
	}

	public void activate()
	{
		frame.toFront();
	}

	public void print(String format, String filename) throws java.io.IOException
	{
		Color fcolor = FigColor.getColor();
		FigColor.reset(Color.white);
		try
		{
			if (format .equals("postscript"))
			{
				canvas.toPostScript(filename);
			}
			else
			{
				BufferedImage img = canvas.toImage();
				javax.imageio.ImageIO.write(img, format, new java.io.File(filename));
			}
		}
		finally
		{
			FigColor.reset(fcolor);
			canvas.redraw();
		}
	}

	private Buffer makeColormapTextureData()
	{
		double[][] cmap = Colormap.asDoubleMatrix();
		float[] buf = new float[cmap.length*4];

		for (int i=0; i<cmap.length; i++)
		{
			buf[4*i]   = (float)cmap[i][0];
			buf[4*i+1] = (float)cmap[i][1];
			buf[4*i+2] = (float)cmap[i][2];
			buf[4*i+3] = 1;
		}

		return FloatBuffer.wrap(buf);
	}

	private String getBestRenderer()
	{
		return "OpenGL";
	}
	
	public void propertyChanged(Property p) throws PropertyException
	{
		super.propertyChanged(p);

		if (p == Name || p == NumberTitle)
			updateTitle();
		else if (p == IntegerHandle)
		{
			updateHandle();
			updateTitle();
		}
		else if (p == Visible)
		{
			frame.setVisible(Visible.isSet());
			updateFramePosition();
		}
		else if (p == Position && !isAutoMode())
		{
			updateFramePosition();
		}
		else if (p == Units)
		{
			updatePosition();
			currentUnits = Units.getValue();
		}
		else if (p == Toolbar)
			updateToolbars();
		else if (p == Resize)
			frame.setResizable(Resize.isSet());
		else if (p == Renderer && !isAutoMode())
		{
			autoSet(RendererMode, "manual");
			updateCanvas();
		}
		else if (p == RendererMode && !isAutoMode())
		{
			if (RendererMode.is("auto"))
			{
				String r = getBestRenderer();
				if (!Renderer.is(r))
				{
					autoSet(Renderer, getBestRenderer());
					updateCanvas();
				}
			}
		}
	}

	public Component getComponent()
	{
		return axPanel;
	}

	public Object get(Property p)
	{
		if (p == Position)
			updatePosition();
		return super.get(p);
	}

	private int commandToOp(String cmd)
	{
		if (cmd.equals("edit")) return OP_NONE;
		else if (cmd.equals("zoom")) return OP_ZOOM;
		else if (cmd.equals("rotate")) return OP_ROTATE;
		else return OP_NONE;
	}

	public int getMouseOp()
	{
		return defaultMouseOp;
	}

	protected Color getBackgroundColor()
	{
		return FigColor.getColor();
	}

	protected Container getEmbeddingComponent()
	{
		return axPanel;
	}

	// WindowListener interface
	
	public void windowClosing(WindowEvent e)
	{
		//this.delete();
		CloseRequestFcn.execute(new Object[] {
			new Double(getHandle()),
			null});
	}

	public void windowActivated(WindowEvent e)
	{
		RootObject.getInstance().CurrentFigure.addElement(this);
	}

	public void windowDeactivated(WindowEvent e)
	{
		cancelMouseOperation();
	}

	public void windowClosed(WindowEvent e){}

	public void windowIconified(WindowEvent e){}

	public void windowDeiconified(WindowEvent e){}

	public void windowOpened(WindowEvent e){}

	/* ComponentListener interface */

	public void componentHidden(ComponentEvent e) {}
	
	public void componentMoved(ComponentEvent e) {}

	public void componentResized(ComponentEvent e)
	{
		//System.out.println("resized");
		ResizeFcn.execute(new Object[] {
			new Double(getHandle()),
			null});
	}
	
	public void componentShown(ComponentEvent e) {}

	/* ChangeListener interface */

	public void actionPerformed(ActionEvent e)
	{
		//System.out.println("action");
		if (e.getSource() == editBtn || e.getSource() == zoomBtn || e.getSource() == rotateBtn)
		{
			if (e.getSource() != editBtn)
				editBtn.setSelected(false);
			if (e.getSource() != zoomBtn)
				zoomBtn.setSelected(false);
			if (e.getSource() != rotateBtn)
				rotateBtn.setSelected(false);
			if (((JToggleButton)e.getSource()).isSelected())
				defaultMouseOp = commandToOp(e.getActionCommand());
			else
				defaultMouseOp = OP_NONE;
		}
	}
}
