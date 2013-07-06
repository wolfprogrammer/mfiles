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

public abstract class AxesContainer extends HandleObject
	implements RenderEventListener, MouseListener, MouseMotionListener,
			   RenderCanvas.Container
{
	protected RenderCanvas canvas = null;

	private AxesObject mouseAxes = null;
	private int mouseOp = OP_NONE;

	public static final int OP_NONE = 0;
	public static final int OP_ZOOM = 1;
	public static final int OP_ROTATE = 2;

	// Constructor

	public AxesContainer(HandleObject parent, String type, double handle)
	{
		super(parent, handle, type);
	}

	// Methods
	
	protected abstract Color getBackgroundColor();
	protected abstract Container getEmbeddingComponent();

	protected Point getMouseLocation(MouseEvent e)
	{
		Point pt = new Point(e.getPoint());
		if (e.getSource() == canvas)
			pt.translate(canvas.getX(), canvas.getY());
		return pt;
	}

	public HandleObject getObjectForPoint(Point pt, int margin)
	{
		synchronized (Children)
		{
			Iterator it = Children.iterator();
			Insets insets = getEmbeddingComponent().getInsets();

			while (it.hasNext())
			{
				HandleObject hObj = (HandleObject)it.next();
				if (!hObj.isValid())
					continue;
				if (hObj instanceof UIControlObject)
				{
					Rectangle r = ((UIControlObject)hObj).getBounds();
					r.setRect(r.x-margin, r.y-margin, r.width+2*margin, r.height+2*margin);
					if (r.contains(pt))
						return hObj;
				}
				else if (hObj instanceof AxesObject)
				{
					Rectangle r = ((AxesObject)hObj).getBoundingBox();
					if (r.contains(pt.x-canvas.getX(), canvas.getHeight()-pt.y+canvas.getY()))
						return hObj;
				}
			}
		}
		return null;
	}

	public AxesObject getAxesForPoint(Point pt)
	{
		HandleObject obj = getObjectForPoint(pt, 0);
		if (obj instanceof AxesObject)
			return (AxesObject)obj;
		return null;
	}

	public static void redrawRecursive(HandleObject obj)
	{
		if (obj instanceof RenderCanvas.Container)
			((RenderCanvas.Container)obj).getCanvas().redraw();

		synchronized (obj.Children)
		{
			Iterator it = obj.Children.iterator();
			while (it.hasNext())
				redrawRecursive((HandleObject)it.next());
		}
	}

	public void redraw()
	{
		redrawRecursive(this);
	}

	private int getDefaultMouseOp()
	{
		FigureObject fig = (FigureObject)getAncestor("figure");
		return fig.getMouseOp();
	}

	public boolean hasMouseOperation()
	{
		return (mouseOp != OP_NONE && mouseAxes != null);
	}

	public void cancelMouseOperation()
	{
		if (hasMouseOperation())
		{
			mouseAxes.cancelOperation(mouseOp);
			mouseAxes = null;
			mouseOp = OP_NONE;
		}
	}

	private void createCanvas()
	{
		if (canvas != null)
			return;

		RadioProperty rp = ((FigureObject)getAncestor("figure")).Renderer;

		if (rp.is("OpenGL"))
			canvas = new GLRenderCanvas();
		else if (rp.is("Java2D"))
			canvas = new J2DRenderCanvas();

		canvas.getComponent().setVisible(false);
		canvas.addMouseListener(this);
		canvas.addMouseMotionListener(this);
		canvas.addRenderEventListener(this);
		getEmbeddingComponent().add(canvas.getComponent());
		getEmbeddingComponent().validate();
		canvas.getComponent().setVisible(true);
	}

	protected void updateCanvas()
	{
		if (canvas != null)
		{
			canvas.removeMouseListener(this);
			canvas.removeMouseMotionListener(this);
			canvas.removeRenderEventListener(this);
			getEmbeddingComponent().remove(canvas.getComponent());
			getEmbeddingComponent().validate();
			canvas = null;
		}
		createCanvas();
	}

	// RenderEventListener interface

	public void reshape(RenderCanvas c, int x, int y, int width, int height)
	{
		synchronized (Children)
		{
			Iterator it = Children.iterator();
			while (it.hasNext())
			{
				HandleObject hObj = (HandleObject)it.next();
				if (hObj instanceof AxesObject && hObj.isValid())
					((AxesObject)hObj).updateActivePosition();
			}
		}
	}

	public void display(RenderCanvas c)
	{
		Renderer r = c.getRenderer();

		// clear background
		r.clear(getBackgroundColor());
		// iterate over axes objects
		synchronized (Children)
		{
			Iterator it = Children.iterator();
			while (it.hasNext())
			{
				HandleObject hObj = (HandleObject)it.next();
				if (hObj instanceof AxesObject && hObj.isValid())
					((AxesObject)hObj).draw(r);
			}
		}
	}

	// MouseListener interface

	public void mouseClicked(MouseEvent e)
	{
		if (e.getButton() == MouseEvent.BUTTON3 && mouseOp == OP_NONE && getDefaultMouseOp() == OP_ZOOM)
		{
			AxesObject ax = getAxesForPoint(getMouseLocation(e));
			if (ax != null)
				ax.unZoom();
		}
	}
	
	public void mouseEntered(MouseEvent e) {}

	public void mouseExited(MouseEvent e) {}
	
	public void mousePressed(MouseEvent e)
	{
		if (mouseOp == OP_NONE)
		{
			// Only do something if no operation pending
			Point pt = getMouseLocation(e);
			AxesObject ax = getAxesForPoint(pt);
			HandleObject hObj = getObjectForPoint(pt, 5);

			if (hObj != null)
			{
				boolean doCB = false;

				if (hObj instanceof AxesObject)
				{
					if (getDefaultMouseOp() == OP_NONE)
						doCB = true;
					else if (e.getButton() == MouseEvent.BUTTON1)
					{
						mouseAxes = (AxesObject)hObj;
						mouseOp = getDefaultMouseOp();
						mouseAxes.startOperation(mouseOp, e);
					}
				}
				else
					doCB = true;

				if (doCB)
					hObj.doButtonDownFcn(e);
			}
			else
				doButtonDownFcn(e);
		}
	}
	
	public void mouseReleased(MouseEvent e)
	{
		if (mouseOp != OP_NONE)
		{
			if (e.getButton() == MouseEvent.BUTTON1)
			{
				if (mouseAxes != null)
					mouseAxes.endOperation(mouseOp, e);
				mouseAxes = null;
				mouseOp = OP_NONE;
			}
		}
	}

	// MouseMotionListener interface
	
	public void mouseMoved(MouseEvent e) {}

	public void mouseDragged(MouseEvent e)
	{
		if (mouseAxes != null && mouseOp != OP_NONE)
			mouseAxes.operation(mouseOp, e);
	}

	/* RenderCanvas.Container interface */

	public RenderCanvas getCanvas()
	{
		if (canvas == null)
			createCanvas();

		return canvas;
	}
}
