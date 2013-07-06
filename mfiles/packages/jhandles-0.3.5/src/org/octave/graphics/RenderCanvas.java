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
import java.awt.image.*;
import java.awt.event.*;

public interface RenderCanvas
{
	public interface Container
	{
		public RenderCanvas getCanvas();
	}

	public void addRenderEventListener(RenderEventListener l);
	public void removeRenderEventListener(RenderEventListener l);
	public void addMouseListener(MouseListener l);
	public void removeMouseListener(MouseListener l);
	public void addMouseMotionListener(MouseMotionListener l);
	public void removeMouseMotionListener(MouseMotionListener l);

	public void redraw();
	public int getWidth();
	public int getHeight();
	public int getX();
	public int getY();
	public Renderer getRenderer();
	public Component getComponent();
	public BufferedImage toImage();
	public void toPostScript(String filename);

	public Font getFont();
	public FontMetrics getFontMetrics(Font fnt);
}
