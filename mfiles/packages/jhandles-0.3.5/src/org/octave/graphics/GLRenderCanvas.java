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
import java.util.*;
import java.nio.*;
import javax.media.opengl.*;
import javax.media.opengl.glu.*;

public class GLRenderCanvas extends GLCanvas
	implements GLEventListener, RenderCanvas
{
	private GLRenderer r;
	private java.util.List rListeners;
	private String gl2psFileName = null;
	private boolean reshapeDone = false;

	public GLRenderCanvas()
	{
		r = null;
		rListeners = new LinkedList();

		addGLEventListener(this);
	}

	/* GLEventListener interface */

	public void display(GLAutoDrawable d)
	{
		if (gl2psFileName != null)
		{
			int result;

			result = GL2PS.gl2psBeginPage("Title", "JHandles", null, GL2PS.GL2PS_EPS, GL2PS.GL2PS_BSP_SORT,
				/*GL2PS.GL2PS_SILENT|*/GL2PS.GL2PS_BEST_ROOT|GL2PS.GL2PS_USE_CURRENT_VIEWPORT/*|GL2PS.GL2PS_OCCLUSION_CULL*/,
				GL.GL_RGBA, 0, null, 0, 0, 0, 1024*1024,
				gl2psFileName, "");
			r.setGL2PS(true);
			System.out.println("gl2psBeginPage: " + result);
		}

		Iterator it = rListeners.iterator();
		while (it.hasNext())
			((RenderEventListener)it.next()).display(this);

		if (gl2psFileName != null)
		{
			int result = GL2PS.gl2psEndPage();
			r.setGL2PS(false);
			System.out.println("gl2psEndPage: " + result);
		}
	}

	public void init(GLAutoDrawable d)
	{
		GL gl = d.getGL();

		r = new GLRenderer(d);
		gl.glEnable(GL.GL_DEPTH_TEST);
		gl.glDepthFunc(GL.GL_LEQUAL);
		gl.glBlendFunc(GL.GL_SRC_ALPHA, GL.GL_ONE_MINUS_SRC_ALPHA);
		gl.glEnable(GL.GL_NORMALIZE);
		//gl.glFrontFace(GL.GL_CW);
		//gl.glCullFace(GL.GL_BACK);
		//gl.glEnable(GL.GL_CULL_FACE);
	}

	public void reshape(GLAutoDrawable d, int x, int y, int width, int height)
	{
		r.setViewport(width, height);

		Iterator it = rListeners.iterator();
		while (it.hasNext())
			((RenderEventListener)it.next()).reshape(this, x, y, width, height);
		
		if (reshapeDone && !Threading.isSingleThreaded())
		{
			GL gl = d.getGL();
			gl.glClear(GL.GL_COLOR_BUFFER_BIT | GL.GL_DEPTH_BUFFER_BIT);
			d.swapBuffers();
		}
		reshapeDone = true;
	}

	public void displayChanged(GLAutoDrawable d, boolean deviceChanged, boolean modeChanged) {}

	/* RenderCanvas interface */

	public Renderer getRenderer()
	{
		return r;
	}

	public Component getComponent()
	{
		return this;
	}

	public void redraw()
	{
		display();
		//repaint();
	}

	public void addRenderEventListener(RenderEventListener l)
	{
		rListeners.add(l);
	}
	
	public void removeRenderEventListener(RenderEventListener l)
	{
		rListeners.remove(l);
	}

	public BufferedImage toImage()
	{
		display();
		getContext().makeCurrent();

		GL gl = getGL();
		ByteBuffer buf = ByteBuffer.allocate(getWidth()*getHeight()*3);
		gl.glReadBuffer(GL.GL_FRONT);
		gl.glReadPixels(0, 0, getWidth(), getHeight(), GL.GL_RGB, GL.GL_UNSIGNED_BYTE, buf);
		gl.glReadBuffer(GL.GL_BACK);

		BufferedImage img = new BufferedImage(getWidth(), getHeight(), BufferedImage.TYPE_3BYTE_BGR);
		img.getRaster().setDataElements(0, 0, getWidth(), getHeight(), buf.array());
		com.sun.opengl.util.ImageUtil.flipImageVertically(img);

		getContext().release();

		return img;
	}

	public void toPostScript(String filename)
	{
		gl2psFileName = filename;
		display();
		gl2psFileName = null;
	}
}
