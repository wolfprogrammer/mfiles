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
import javax.media.opengl.*;

public class MarkerProperty extends RadioProperty
{
	private static boolean done_warn = false;

	public class Marker
	{
		byte[] data;
		int xhot, yhot;
		int w, h;

		Marker(byte[] data, int w, int h, int xhot, int yhot)
		{
			this.data = data;
			this.w = w;
			this.h = h;
			this.xhot = xhot;
			this.yhot = yhot;
		}

		void draw(GL gl, double x, double y, double z)
		{
			gl.glRasterPos3d(x, y, z);
			gl.glPixelStorei(GL.GL_UNPACK_ALIGNMENT, 1);
			gl.glBitmap(0, 0, 0, 0, -xhot, -yhot, null, 0);
			gl.glBitmap(w, h, 0, 0, 0, 0, data, 0);
			gl.glPixelStorei(GL.GL_UNPACK_ALIGNMENT, 4);
		}
	}

	protected MarkerProperty(MarkerProperty p)
	{
		super(p);
	}

	public MarkerProperty(PropertySet parent, String name)
	{
		super(parent, name, new String[] {
			"o", "s", "x", "+", "*", "d",
			"^", ">", "<", "v", ".", "p", "h", "none"});
	}

	public MarkerProperty(PropertySet parent, String name, String marker)
	{
		this(parent, name);
		this.pvalue = marker;
	}

	public Property cloneProperty()
	{
		return new MarkerProperty(this);
	}

	public void drawMarker(Graphics g, int x, int y, double markerSize)
	{
		/* convert marker size from point size to pixel size */
		markerSize = (markerSize * Utils.getScreenResolution() / 72.0);

		int size = (int)markerSize, size2 = (int)(markerSize/2);
		int size3 = (int)(markerSize/3), size23 = (int)((markerSize*2)/3);

		switch (getValue().charAt(0))
		{
		case 'o':
			g.drawOval(x-size2, y-size2, size-1, size-1);
			break;
		case 's':
			g.drawRect(x-size2, y-size2, size-1, size-1);
			break;
		case 'x':
			g.drawLine(x-size2, y-size2, x+size2, y+size2);
			g.drawLine(x+size2, y-size2, x-size2, y+size2);
			break;
		case '+':
			g.drawLine(x-size2, y, x+size2, y);
			g.drawLine(x, y-size2, x, y+size2);
			break;
		case '*':
			g.drawLine(x-size2, y, x+size2, y);
			g.drawLine(x, y-size2, x, y+size2);
			g.drawLine(x-size3, y-size3, x+size3, y+size3);
			g.drawLine(x+size3, y-size3, x-size3, y+size3);
			break;
		case 'd':
			g.drawPolygon(
				new int[] {x-size2, x, x+size2, x},
				new int[] {y, y-size2, y, y+size2},
				4);
			break;
		case '^':
			g.drawPolygon(
				new int[] {x-size2, x, x+size2},
				new int[] {y+size3, y-size23, y+size3},
				3);
			break;
		case '>':
			g.drawPolygon(
				new int[] {x-size3, x+size23, x-size3},
				new int[] {y-size2, y, y+size2},
				3);
			break;
		case '<':
			g.drawPolygon(
				new int[] {x-size23, x+size3, x+size3},
				new int[] {y, y-size2, y+size2},
				3);
			break;
		case 'v':
			g.drawPolygon(
				new int[] {x-size2, x, x+size2},
				new int[] {y-size3, y+size23, y-size3},
				3);
			break;
		case '.':
			g.fillOval(x-1, y-1, 3, 3);
			break;
		}
	}

	public boolean isSet()
	{
		return !is("none");
	}

	public void setMarker(String s)
	{
		try { set(s); }
		catch (PropertyException e) { }
	}

	public Marker makeMarker(double markerSize, double lineWidth)
	{
		/* convert marker size from point size to pixel size */
		markerSize = (markerSize * Utils.getScreenResolution() / 72.0);

		int size = (int)Math.round(markerSize), size2 = (int)Math.round(markerSize/2);
		int size3 = (int)Math.round(markerSize/3), size23 = (int)Math.round((markerSize*2)/3);
		BufferedImage img = new BufferedImage(size, size, BufferedImage.TYPE_BYTE_BINARY);
		Graphics2D g = img.createGraphics();
		int xhot = 0, yhot = 0;

		g.setColor(Color.black);
		g.fillRect(0, 0, size, size);
		g.setColor(Color.white);
		g.setStroke(new BasicStroke((float)lineWidth));

		switch (getValue().charAt(0))
		{
		case 'o':
			xhot = yhot = size2;
			g.drawArc(0, 0, size-1, size-1, 0, 360);
			break;
		case 'h':
		case 'p':
			if (!done_warn)
			{
				System.out.println("WARNING: pentagram/hexagram markers not supported, using square instead");
				done_warn = true;
			}
		case 's':
			xhot = yhot = size2;
			g.drawRect(0, 0, size-1, size-1);
			break;
		case 'x':
			xhot = yhot = size2;
			g.drawLine(0, 0, size-1, size-1);
			g.drawLine(size-1, 0, 0, size-1);
			break;
		case '+':
			xhot = yhot = size2;
			g.drawLine(size2, 0, size2, size-1);
			g.drawLine(0, size2, size-1, size2);
			break;
		case '*':
			xhot = yhot = size2;
			g.drawLine(size2, 0, size2, size-1);
			g.drawLine(0, size2, size-1, size2);
			g.drawLine(size2-size3, size2-size3, size2+size3, size2+size3);
			g.drawLine(size2+size3, size2-size3, size2-size3, size2+size3);
			break;
		case 'd':
			xhot = yhot = size2;
			g.drawLine(size2, 0, 0, size2);
			g.drawLine(0, size2, size2, size-1);
			g.drawLine(size2, 0, size-1, size2);
			g.drawLine(size-1, size2, size2, size-1);
			break;
		case '^':
			xhot = size2; yhot = size3;
			g.drawLine(size2, 0, 0, size-1);
			g.drawLine(size2, 0, size-1, size-1);
			g.drawLine(0, size-1, size-1, size-1);
			break;
		case '>':
			xhot = size3; yhot = size2;
			g.drawPolygon(
				new int[] {0, size-1, 0},
				new int[] {0, size2, size-1},
				3);
			break;
		case '<':
			xhot = size23; yhot = size2;
			g.drawPolygon(
				new int[] {size-1, 0, size-1},
				new int[] {0, size2, size-1},
				3);
			break;
		case 'v':
			xhot = size2; yhot = size23;
			g.drawLine(0, 0, size2, size-1);
			g.drawLine(size-1, 0, size2, size-1);
			g.drawLine(0, 0, size-1, 0);
			break;
		case '.':
			xhot = yhot = size2;
			g.fillOval(size2-1, size2-1, 3, 3);
			break;
		}
		g.dispose();
		com.sun.opengl.util.ImageUtil.flipImageVertically(img);

		byte[] data = ((DataBufferByte)img.getData().getDataBuffer()).getData();

		return new Marker(data, size, size, xhot, yhot);
	}
}
