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
import java.nio.ByteBuffer;

public interface Renderer
{
	public static final int LS_SOLID = 0;
	public static final int LS_DOTTED = 1;
	public static final int LS_DASHED = 2;
	public static final int LS_DASHDOT = 3;
	public static final int LS_NONE = 4;

	public interface CachedData
	{
		public void dispose();
	}

	public void setClipping(boolean flag);

	public boolean hasClipping();

	public void setClipBox(double xmin, double xmax, double ymin, double ymax, double zmin, double zmax);

	public void setCamera(double[] pos, double[] target);

	public void setColor(Color c);

	public void setLineStyle(String s, boolean forceStippling);

	public void setLineWidth(float w);

	public void setFont(Font f);

	public void end();

	public void draw(LineObject line);

	public void draw(LightObject light);
	
	public void draw(ByteBuffer data, int w, int h, double[] pos, int xOffset, int yOffset,
		boolean useClipping, boolean useZBuffer);

	public void drawBitmap(BufferedImage img, double[] pos, int xOffset, int yOffset);

	/*
	public void drawText(String txt, double[] pos, int halign, int valign, float angle, float margin,
		boolean offsetmargin, float linewidth, Color linecolor, String linepattern, Color fillcolor,
		boolean useZBuffer);
		*/

	public Rectangle drawText(String txt, double[] pos, int halign, int valign);
	
	public void draw(PatchObject patch);

	public void draw(SurfaceObject surf);

	public void draw(ImageObject image);

	public void draw(TextObject text);

	public void setXForm(AxesObject ax);

	public void setViewport(int width, int height);

	public void clear(Color c);

	public void drawRubberBox(int[][] b);

	public void drawSegments(java.util.List pts);
	
	public void drawQuads(java.util.List pts, double zoffset);
}
