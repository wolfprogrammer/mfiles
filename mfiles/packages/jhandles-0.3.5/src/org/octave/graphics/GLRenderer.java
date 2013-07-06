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
import java.awt.Dimension;
import java.awt.Rectangle;
import java.awt.Font;
import java.awt.image.*;
import javax.media.opengl.*;
import javax.media.opengl.glu.*;
import java.nio.ByteBuffer;
import java.util.*;
import java.nio.*;
import org.octave.Matrix;

public class GLRenderer implements Renderer
{
	private int maxLight;
	private GLAutoDrawable d;
	private GL gl;
	private GLU glu;

	private double xmin, xmax;
	private double ymin, ymax;
	private double zmin, zmax;

	private Point3D cameraPos;
	private Point3D cameraDir;
	private TreeMap alphaPrimitives;
	private GLUtessellator tess = null;
	private int lightSideMode = GL.GL_FRONT_AND_BACK;
	private AxesObject.Scaler sx, sy, sz;
	private float po = 1.0f;
	private boolean isGL2PS = false;
	private boolean isFirst = false;
	private Matrix3D xForm;
	private double xZ1, xZ2;
	private Font font;

	public interface MarkerDrawer
	{
		public void begin(MarkerProperty m, DoubleProperty ms, float lw);
		public void end();
		public void draw(double x, double y, double z, double[] lc, double[] fc);
	}

	private class GLMarkerDrawer implements MarkerDrawer
	{
		private int ID, ID2;
		private boolean hasClip;
		private double[] tmp = new double[4];

		public GLMarkerDrawer()
		{
		}

		public void begin(MarkerProperty m, DoubleProperty ms, float lw)
		{
			gl.glMatrixMode(GL.GL_PROJECTION);
			gl.glPushMatrix();
			gl.glLoadIdentity();
			gl.glOrtho(0, d.getWidth(), d.getHeight(), 0, xZ1, xZ2);
			gl.glMatrixMode(GL.GL_MODELVIEW);
			gl.glPushMatrix();

			hasClip = hasClipping();
			setClipping(false);
			setLineWidth(lw);
		
			ID = makeMarkerList(m, ms, false);
			ID2 = makeMarkerList(m, ms, true);
		}

		public void end()
		{
			gl.glDeleteLists(ID, 1);
			gl.glDeleteLists(ID2, 1);

			gl.glMatrixMode(GL.GL_MODELVIEW);
			gl.glPopMatrix();
			gl.glMatrixMode(GL.GL_PROJECTION);
			gl.glPopMatrix();
			setClipping(hasClip);
			setLineWidth(0.5f);
		}

		public void draw(double x, double y, double z, double[] lc, double[] fc)
		{
			xForm.transform(x, y, z, tmp, 0);
			gl.glLoadIdentity();
			gl.glTranslated(tmp[0], tmp[1], -tmp[2]);
			if (fc != null)
			{
				gl.glColor3d(fc[0], fc[1], fc[2]);
				setPolygonOffset(true);
				gl.glCallList(ID2);
				setPolygonOffset(false);
			}
			if (lc != null)
			{
				gl.glColor3d(lc[0], lc[1], lc[2]);
				gl.glCallList(ID);
			}
		}
	}

	public MarkerDrawer getMarkerDrawer()
	{
		if (isGL2PS)
			return GL2PS.getMarkerDrawer(gl);
		else
			return new GLMarkerDrawer();
	}

	public GLRenderer(GLAutoDrawable d)
	{
		this.d = d;
		this.gl = d.getGL();
		this.maxLight = 0;
		this.alphaPrimitives = new TreeMap();
		this.glu = new GLU();
	}

	public GL getGL()
	{
		return gl;
	}

	public void setGL2PS(boolean flag)
	{
		isGL2PS = flag;
	}

	public void end()
	{
		if (this.alphaPrimitives.size() > 0)
		{
			gl.glEnable(GL.GL_BLEND);
			Iterator it = this.alphaPrimitives.entrySet().iterator();
			while (it.hasNext())
			{
				List l = (List)((Map.Entry)it.next()).getValue();
				Iterator lit = l.iterator();
				while (lit.hasNext())
					((Runnable)lit.next()).run();
			}
			this.alphaPrimitives.clear();
			gl.glDisable(GL.GL_BLEND);
		}
		this.maxLight = 0;

		// turn off all lights
		for (int i=0; i<8; i++)
			gl.glDisable(GL.GL_LIGHT0+i);
		gl.glDisable(GL.GL_LIGHTING);

		// turn off clipping
		setClipping(false);
	}

	public void setClipping(boolean flag)
	{
		if (gl.glIsEnabled(GL.GL_CLIP_PLANE0) != flag)
		{
			if (flag)
				for (int i=0; i<6; i++)
					gl.glEnable(GL.GL_CLIP_PLANE0+i);
			else
				for (int i=0; i<6; i++)
					gl.glDisable(GL.GL_CLIP_PLANE0+i);
		}
	}

	public boolean hasClipping()
	{
		return gl.glIsEnabled(GL.GL_CLIP_PLANE0);
	}
	
	public void setClipBox(double xmin, double xmax, double ymin, double ymax, double zmin, double zmax)
	{
		xmin = xmin-0.001*(xmax-xmin); xmax = xmax+0.001*(xmax-xmin);
		ymin = ymin-0.001*(ymax-ymin); ymax = ymax+0.001*(ymax-ymin);
		zmin = zmin-0.001*(zmax-zmin); zmax = zmax+0.001*(zmax-zmin);

		gl.glClipPlane(GL.GL_CLIP_PLANE0, new double[] { -1, 0, 0, xmax }, 0);
		gl.glClipPlane(GL.GL_CLIP_PLANE1, new double[] { 1, 0, 0, -xmin }, 0);
		gl.glClipPlane(GL.GL_CLIP_PLANE2, new double[] { 0, -1, 0, ymax }, 0);
		gl.glClipPlane(GL.GL_CLIP_PLANE3, new double[] { 0, 1, 0, -ymin }, 0);
		gl.glClipPlane(GL.GL_CLIP_PLANE4, new double[] { 0, 0, -1, zmax }, 0);
		gl.glClipPlane(GL.GL_CLIP_PLANE5, new double[] { 0, 0, 1, -zmin }, 0);

		this.xmin = xmin; this.xmax = xmax;
		this.ymin = ymin; this.ymax = ymax;
		this.zmin = zmin; this.zmax = zmax;
	}

	public boolean isClipped(double x, double y, double z)
	{
		return (x < xmin || x > xmax || y < ymin || y > ymax || z < zmin || z > zmax);
	}

	public int clipCode(double x, double y, double z)
	{
		return (
			(x < xmin ? 1 : 0)      |
			(x > xmax ? 1 : 0) << 1 |
			(y < ymin ? 1 : 0) << 2 |
			(y > ymax ? 1 : 0) << 3 |
			(z < zmin ? 1 : 0) << 4 |
			(z > zmax ? 1 : 0) << 5 |
			(isNaNorInf(x, y, z) ? 0 : 1) << 6
		);
	}

	public boolean isNaNorInf(double x, double y, double z)
	{
		return (Double.isNaN(x) || Double.isNaN(y) || Double.isNaN(z) ||
				Double.isInfinite(x) || Double.isInfinite(y) || Double.isInfinite(z));
	}

	public void setCamera(double[] pos, double[] target)
	{
		cameraPos = new Point3D(pos[0], pos[1], pos[2]);
		cameraDir = new Point3D(target[0]-pos[0], target[1]-pos[1], target[2]-pos[2]);
		cameraDir.normalize();
	}

	public void addAlphaPrimitive(double d, Runnable r)
	{
		Double dbl = new Double(d);
		if (alphaPrimitives.containsKey(dbl))
			((List)alphaPrimitives.get(dbl)).add(r);
		else
		{
			List l = new LinkedList();
			l.add(r);
			alphaPrimitives.put(dbl, l);
		}
	}

	private GLUtessellator getTess(boolean fill)
	{
		if (tess == null)
		{
			tess = glu.gluNewTess();
		}
		//glu.gluTessProperty(tess, GLU.GLU_TESS_WINDING_RULE, GLU.GLU_TESS_WINDING_NONZERO);
		glu.gluTessProperty(tess, GLU.GLU_TESS_BOUNDARY_ONLY, (fill ? GL.GL_FALSE : GL.GL_TRUE));
		return tess;
	}

	public void draw(LineObject line)
	{
		double[] x = sx.scale(line.XData.getArray());
		double[] y = sy.scale(line.YData.getArray());
		double[] z = sz.scale(line.ZData.getArray());
		int n = Math.min(Math.min(x.length, y.length), (z.length == 0 ? Integer.MAX_VALUE : z.length));
		int[] clip = new int[n];
		int clipMask = (line.Clipping.isSet() ? 0x7F : 0x40);

		if (z.length == 0)
		{
			double zmid = (zmin+zmax)/2;
			for (int i=0; i<n; i++)
				clip[i] = (clipCode(x[i], y[i], zmid) & clipMask);
		}
		else
			for (int i=0; i<n; i++)
				clip[i] = (clipCode(x[i], y[i], z[i]) & clipMask);

		if (line.LineStyle.isSet())
		{
			setColor(line.LineColor.getColor());
			setLineStyle(line.LineStyle.getValue(), false);
			setLineWidth(line.LineWidth.floatValue());
			
			if (z.length == 0)
			{
				boolean flag = false;
				for (int i=1; i<n; i++)
				{
					if ((clip[i-1] & clip[i]) == 64)
					{
						if (!flag)
						{
							flag = true;
							gl.glBegin(GL.GL_LINE_STRIP);
							gl.glVertex2d(x[i-1], y[i-1]);
						}
						gl.glVertex2d(x[i], y[i]);
					}
					else if (flag)
					{
						gl.glEnd();
						flag = false;
					}
				}
				if (flag)
					gl.glEnd();
			}
			else
			{
				boolean flag = false;
				for (int i=1; i<n; i++)
				{
					if ((clip[i-1] & clip[i]) == 64)
					{
						if (!flag)
						{
							flag = true;
							gl.glBegin(GL.GL_LINE_STRIP);
							gl.glVertex3d(x[i-1], y[i-1], z[i-1]);
						}
						gl.glVertex3d(x[i], y[i], z[i]);
					}
					else if (flag)
					{
						gl.glEnd();
						flag = false;
					}
				}
				if (flag)
					gl.glEnd();
			}

			setLineWidth(0.5f);
			setLineStyle("-", false);
		}

		if (line.Marker.isSet() && false)
		{
			MarkerProperty.Marker m = line.Marker.makeMarker(line.MarkerSize.doubleValue(), line.LineWidth.doubleValue()); 
			int w = m.w, h = m.h, xhot = m.xhot, yhot = m.yhot;
			byte[] data = m.data;

			gl.glPixelStorei(GL.GL_UNPACK_ALIGNMENT, 1);
			setColor(line.LineColor.getColor());
			if (z.length == 0)
			{
				for (int i=0; i<n; i++)
				{
					if (clip[i] == 64)
					{
						gl.glRasterPos2d(x[i], y[i]);
						gl.glBitmap(0, 0, 0, 0, -xhot, -yhot, null, 0);
						gl.glBitmap(w, h, 0, 0, 0, 0, data, 0);
					}
				}
			}
			else
			{
				for (int i=0; i<n; i++)
				{
					if (clip[i] == 64)
					{
						gl.glRasterPos3d(x[i], y[i], z[i]);
						gl.glBitmap(0, 0, 0, 0, -xhot, -yhot, null, 0);
						gl.glBitmap(w, h, 0, 0, 0, 0, data, 0);
					}
				}
			}
			gl.glPixelStorei(GL.GL_UNPACK_ALIGNMENT, 4);
		}
		else if (line.Marker.isSet() && !(line.MarkerEdgeColor.is("none") && line.MarkerFaceColor.is("none")))
		{
			Color lc = null, fc = null;

			if (line.MarkerEdgeColor.isSet())
				lc = line.MarkerEdgeColor.getColor();
			else if (line.MarkerEdgeColor.is("auto"))
				lc = line.LineColor.getColor();
			if (line.MarkerFaceColor.isSet())
				fc = line.MarkerFaceColor.getColor();
			else if (line.MarkerFaceColor.is("auto"))
				fc = line.LineColor.getColor();

			drawMarkers(line.Marker, line.MarkerSize, new double[][] { x, y, z },
					clip, n, lc, line.LineWidth.floatValue(), fc);
		}
	}

	public void drawMarkers(MarkerProperty m, DoubleProperty ms, double[][] data, int[] clip, int n, Color lc, float lw, Color fc)
	{
		MarkerDrawer md = getMarkerDrawer();
		double[] x = data[0];
		double[] y = data[1];
		double[] z = (data.length > 2 ? data[2] : new double[0]);
		boolean use_clip = (clip != null && clip.length == x.length), use_z = (z.length > 0);
		double[] lcv = (lc != null ? new double[] {lc.getRed()/255.0, lc.getGreen()/255.0, lc.getBlue()/255.0} : null);
		double[] fcv = (fc != null ? new double[] {fc.getRed()/255.0, fc.getGreen()/255.0, fc.getBlue()/255.0} : null);

		md.begin(m, ms, lw);
		for (int i=0; i<n; i++)
		{
			if (!use_clip || clip[i] == 64)
				md.draw(x[i], y[i], (use_z ? z[i] : 0.0), lcv, fcv);
		}
		md.end();
	}

	public int makeMarkerList(MarkerProperty p, DoubleProperty s, boolean filled)
	{
		int ID = gl.glGenLists(1);
		double sz = s.doubleValue() * Utils.getScreenResolution() / 72.0;

		gl.glNewList(ID, GL.GL_COMPILE);
		switch (p.getValue().charAt(0))
		{
			case 's':
				gl.glBegin((filled ? GL.GL_POLYGON : GL.GL_LINE_LOOP));
				gl.glVertex2d(-sz/2, -sz/2);
				gl.glVertex2d(-sz/2,  sz/2);
				gl.glVertex2d( sz/2,  sz/2);
				gl.glVertex2d( sz/2, -sz/2);
				gl.glEnd();
				break;
			case 'o':
				double ang_step = Math.PI / 5;
				gl.glBegin((filled ? GL.GL_POLYGON : GL.GL_LINE_LOOP));
				for (double ang = 0; ang < (2*Math.PI); ang += ang_step)
					gl.glVertex2d(sz*Math.cos(ang)/2, sz*Math.sin(ang)/2);
				gl.glEnd();
				break;
			case '+':
				if (!filled)
				{
					gl.glBegin(GL.GL_LINES);
					gl.glVertex2d(0,    -sz/2);
					gl.glVertex2d(0,     sz/2);
					gl.glVertex2d(-sz/2,    0);
					gl.glVertex2d( sz/2,    0);
					gl.glEnd();
				}
				break;
			case 'x':
				if (!filled)
				{
					gl.glBegin(GL.GL_LINES);
					gl.glVertex2d(-sz/2, -sz/2);
					gl.glVertex2d( sz/2,  sz/2);
					gl.glVertex2d( sz/2, -sz/2);
					gl.glVertex2d(-sz/2,  sz/2);
					gl.glEnd();
				}
				break;
			case '<':
				gl.glBegin((filled ? GL.GL_POLYGON : GL.GL_LINE_LOOP));
				gl.glVertex2d(-2*sz/3, 0);
				gl.glVertex2d(sz/3,    sz/2);
				gl.glVertex2d(sz/3,   -sz/2);
				gl.glEnd();
				break;
			case '>':
				gl.glBegin((filled ? GL.GL_POLYGON : GL.GL_LINE_LOOP));
				gl.glVertex2d(2*sz/3, 0);
				gl.glVertex2d(-sz/3,  sz/2);
				gl.glVertex2d(-sz/3, -sz/2);
				gl.glEnd();
				break;
			case 'v':
				gl.glBegin((filled ? GL.GL_POLYGON : GL.GL_LINE_LOOP));
				gl.glVertex2d( 0,     2*sz/3);
				gl.glVertex2d( sz/2, -sz/3);
				gl.glVertex2d(-sz/2, -sz/3);
				gl.glEnd();
				break;
			case '^':
				gl.glBegin((filled ? GL.GL_POLYGON : GL.GL_LINE_LOOP));
				gl.glVertex2d( 0,   -2*sz/3);
				gl.glVertex2d( sz/2, sz/3);
				gl.glVertex2d(-sz/2, sz/3);
				gl.glEnd();
				break;
			case 'd':
				gl.glBegin((filled ? GL.GL_POLYGON : GL.GL_LINE_LOOP));
				gl.glVertex2d(-sz/2, 0);
				gl.glVertex2d( 0,    sz/2);
				gl.glVertex2d( sz/2, 0);
				gl.glVertex2d( 0,   -sz/2);
				gl.glEnd();
				break;
			case '*':
				if (!filled)
				{
					gl.glBegin(GL.GL_LINES);
					gl.glVertex2d( sz/2, 0);
					gl.glVertex2d(-sz/2, 0);
					gl.glVertex2d(0,  sz/2);
					gl.glVertex2d(0, -sz/2);
					gl.glVertex2d(-sz/3,  sz/3);
					gl.glVertex2d( sz/3, -sz/3);
					gl.glVertex2d( sz/3,  sz/3);
					gl.glVertex2d(-sz/3, -sz/3);
					gl.glEnd();
				}
				break;
			case '.':
				if (!filled)
				{
					gl.glPointSize(3.0f);
					gl.glBegin(GL.GL_POINTS);
					gl.glVertex2i(0, 0);
					gl.glEnd();
				}
				break;
			case 'p':
				double[][] ppts = Utils.getPentagramPoints();
				double pr = (sz/2+1);
				gl.glBegin((filled ? GL.GL_TRIANGLE_FAN : GL.GL_LINE_LOOP));
				if (filled)
					gl.glVertex2i(0, 0);
				for (int i=0; i<ppts.length; i++)
					gl.glVertex2d(pr*ppts[i][0], -pr*ppts[i][1]);
				if (filled)
					gl.glVertex2d(pr*ppts[0][0], -pr*ppts[0][1]);
				gl.glEnd();
				break;
			case 'h':
				double[][] hpts = Utils.getHexagramPoints();
				double hr = (sz/2+1);
				gl.glBegin((filled ? GL.GL_TRIANGLE_FAN : GL.GL_LINE_LOOP));
				if (filled)
					gl.glVertex2i(0, 0);
				for (int i=0; i<hpts.length; i++)
					gl.glVertex2d(hr*hpts[i][0], -hr*hpts[i][1]);
				if (filled)
					gl.glVertex2d(hr*hpts[0][0], -hr*hpts[0][1]);
				gl.glEnd();
				break;
		}
		gl.glEndList();

		return ID;
	}

	public void draw(LightObject light)
	{
		Color c = light.LightColor.getColor();
		double[] pos = light.Position.getArray();
		boolean isLocal = light.Style.is("local");
		float[] cp = new float[] {c.getRed()/255.0f, c.getGreen()/255.0f, c.getBlue()/255.0f, 1.0f};

		gl.glLightfv(GL.GL_LIGHT0+maxLight, GL.GL_DIFFUSE, cp, 0);
		gl.glLightfv(GL.GL_LIGHT0+maxLight, GL.GL_SPECULAR, cp, 0);
		gl.glLightfv(GL.GL_LIGHT0+maxLight, GL.GL_AMBIENT, new float[] {1,1,1,1}, 0);
		gl.glLightfv(GL.GL_LIGHT0+maxLight, GL.GL_POSITION,
			new float[] {(float)pos[0], (float)pos[1], (float)pos[2], (isLocal ? 1.0f : 0.0f)}, 0);
		gl.glEnable(GL.GL_LIGHT0+maxLight);
		maxLight++;
	}

	public void draw(ByteBuffer data, int w, int h, double[] pos,
		int xOffset, int yOffset, boolean useClipping, boolean useZBuffer)
	{
		boolean hasClip = hasClipping();

		if (hasClip != useClipping)
			setClipping(useClipping);
		if (!useZBuffer)
			gl.glDisable(GL.GL_DEPTH_TEST);
		gl.glEnable(GL.GL_BLEND);
		gl.glBlendFunc(GL.GL_SRC_ALPHA, GL.GL_ONE_MINUS_SRC_ALPHA);
		gl.glEnable(GL.GL_ALPHA_TEST);
		gl.glAlphaFunc(GL.GL_GREATER, 0.0f);
		gl.glRasterPos3d(sx.scale(pos[0]), sy.scale(pos[1]), sz.scale(pos[2]));
		gl.glBitmap(0, 0, 0, 0, -xOffset, -yOffset, null, 0);
		gl.glDrawPixels(w, h, GL.GL_ABGR_EXT, GL.GL_UNSIGNED_BYTE, data);
		gl.glDisable(GL.GL_ALPHA_TEST);
		gl.glDisable(GL.GL_BLEND);
		if (!useZBuffer)
			gl.glEnable(GL.GL_DEPTH_TEST);
		if (hasClip != useClipping)
			setClipping(!useClipping);
	}

	public void drawBitmap(BufferedImage img, double[] pos, int xOffset, int yOffset)
	{
		byte[] data = ((DataBufferByte)img.getData().getDataBuffer()).getData();
		gl.glRasterPos3d(pos[0], pos[1], pos[2]);
		gl.glPixelStorei(GL.GL_UNPACK_ALIGNMENT, 1);
		gl.glBitmap(0, 0, 0, 0, xOffset, yOffset, null, 0);
		gl.glBitmap(img.getWidth(), img.getHeight(), 0, 0, 0, 0, data, 0);
		gl.glPixelStorei(GL.GL_UNPACK_ALIGNMENT, 4);
	}

	/*
	private void drawGL2PSText(String txt, double[] pos, int halign, int valign, float angle, float margin,
			boolean offsetmargin, float linewidth, Color linecolor, String linepattern, Color fillcolor,
			boolean useZBuffer)
	{
		if (isGL2PS)
		{
			int mode = GL2PS.GL2PS_TEXT_C, factor = 1;
			short pattern = (short)0xFFFF;
			float[] lc = null, fc = null;

			switch (valign)
			{
				case 0:
					switch (halign)
					{
						case 0: mode = GL2PS.GL2PS_TEXT_BL; break;
						case 1: mode = GL2PS.GL2PS_TEXT_B; break;
						case 2: mode = GL2PS.GL2PS_TEXT_BR; break;
					}
					break;
				case 1:
					switch (halign)
					{
						case 0: mode = GL2PS.GL2PS_TEXT_CL; break;
						case 1: mode = GL2PS.GL2PS_TEXT_C; break;
						case 2: mode = GL2PS.GL2PS_TEXT_CR; break;
					}
					break;
				case 2:
					switch (halign)
					{
						case 0: mode = GL2PS.GL2PS_TEXT_TL; break;
						case 1: mode = GL2PS.GL2PS_TEXT_T; break;
						case 2: mode = GL2PS.GL2PS_TEXT_TR; break;
					}
					break;
				case 3:
					switch (halign)
					{
						case 0: mode = GL2PS.GL2PS_TEXT_LL; break;
						case 1: mode = GL2PS.GL2PS_TEXT_L; break;
						case 2: mode = GL2PS.GL2PS_TEXT_LR; break;
					}
					break;
			}

			if (linecolor != null)
				lc = new float[] {(float)linecolor.getRed()/255.0F, (float)linecolor.getGreen()/255.0F,
					(float)linecolor.getBlue()/255.0F, 1.0F};
			if (fillcolor != null)
				fc = new float[] {(float)fillcolor.getRed()/255.0F, (float)fillcolor.getGreen()/255.0F,
					(float)fillcolor.getBlue()/255.0F, 1.0F};

			if (linepattern.equals("-")) pattern = (short)0xFFFF;
			else if (linepattern.equals(":")) pattern = (short)0x8888;
			else if (linepattern.equals("--")) pattern = (short)0x0FFF;
			else if (linepattern.equals("-.")) pattern = (short)0x020F;
			else
			{
				linewidth = 0;
				fc = null;
			}

			gl.glRasterPos3d(pos[0], pos[1], pos[2]);
			if (!useZBuffer)
				gl.glDisable(GL.GL_DEPTH_TEST);
			GL2PS.gl2psTextOpt(txt, "Helvetica", 12, mode, angle, margin, offsetmargin,
					linewidth, lc, pattern, factor, fc);
			if (!useZBuffer)
				gl.glEnable(GL.GL_DEPTH_TEST);
		}
	}
	*/

	public Rectangle drawText(String txt, double[] pos, int halign, int valign)
	{
		Rectangle dim = SimpleTextEngine.drawAsImage((RenderCanvas)d, font, txt, pos, halign, valign);
		if (isGL2PS)
		{
			/*
			int margin = 0;
			drawGL2PSText(txt, pos, halign, valign, 0, margin, true,
					0, null, "-", null, true);
					*/

			float f = 72.0f / Utils.getScreenResolution();
			StringBuffer buf = new StringBuffer();
			SimpleTextEngine.Content content = new SimpleTextEngine.Content(txt);
			SimpleTextEngine.PSTextRenderer ps = new SimpleTextEngine.PSTextRenderer(buf,
					font.getName(), Math.round(f*font.getSize()), font.getStyle(), Color.black);

			buf.append("gsave\n");
			gl.glRasterPos3d(pos[0], pos[1], pos[2]);
			switch (valign)
			{
				case 1: buf.append("0 -" + (f*((dim.height/2+dim.y))) + " rmoveto\n"); break;
				case 2: buf.append("0 -" + (f*dim.height) + " rmoveto\n"); break;
			}
			content.align = halign;
			content.render(ps);
			buf.append("grestore\n");
			GL2PS.gl2psSpecial(GL2PS.GL2PS_PS, buf.toString(), 1);
		}
		return dim;
	}

	private class VertexData
	{
		double[] coords;
		double[] color;
		double alpha;
		double[] normal;
		float ambient;
		float diffuse;
		float specular;
		float specularExp;

		VertexData(double[] coords, double[] color, double alpha,
			double[] normal, float ambient, float diffuse, float specular, float specularExp)
		{
			this.coords = coords;
			this.color = color;
			this.alpha = alpha;
			this.normal = normal;
			this.ambient = ambient;
			this.diffuse = diffuse;
			this.specular = specular;
			this.specularExp = specularExp;
		}
	}

	private class PatchTessellator extends GLUtessellatorCallbackAdapter
	{
		private int colorMode; // 0: uni,  1: flat, 2: interp
		private int lightMode; // 0: none, 1: flat, 2: gouraud
		private boolean firstVertex;
		private GL gl;
		private VertexData v0;
		private boolean fill;
		private int index;

		public PatchTessellator(GL gl, int colorMode, int lightMode)
		{
			this(gl, colorMode, lightMode, 0);
		}

		public PatchTessellator(GL gl, int colorMode, int lightMode, int index)
		{
			this.gl = gl;
			this.colorMode = colorMode;
			this.lightMode = lightMode;
			this.index = index;
		}

		public void beginData(int mode, Object pData)
		{
			firstVertex = true;
			v0 = (VertexData)pData;
			if (colorMode == 2 || lightMode == 2)
				gl.glShadeModel(GL.GL_SMOOTH);
			else
				gl.glShadeModel(GL.GL_FLAT);
			if (mode != GL.GL_LINE_LOOP)
			{
				gl.glPolygonOffset(po+index, po+index);
				setPolygonOffset(true);
				fill = true;
			}
			else
				fill = false;
			gl.glBegin(mode);
		}

		public void end()
		{
			gl.glEnd();
			setPolygonOffset(false);
		}

		public void vertex(Object vData)
		{
			VertexData v = (VertexData)vData;
			if (colorMode > 0 && (firstVertex || colorMode == 2 || !fill))
			{
				double[] color = ((colorMode == 2 || !fill) ? v.color : v0.color);
				gl.glColor3d(color[0], color[1], color[2]);
				if (lightMode > 0)
				{
					gl.glMaterialfv(lightSideMode, GL.GL_AMBIENT,
						new float[] {v.ambient*(float)color[0], v.ambient*(float)color[1], v.ambient*(float)color[2], 1}, 0);
					gl.glMaterialfv(lightSideMode, GL.GL_DIFFUSE,
						new float[] {v.diffuse*(float)color[0], v.diffuse*(float)color[1], v.diffuse*(float)color[2], 1}, 0);
				}
			}
			if (lightMode > 0 && (firstVertex || lightMode == 2))
				gl.glNormal3d(v.normal[0], v.normal[1], v.normal[2]);
			if (v.coords.length > 2)
				gl.glVertex3d(v.coords[0], v.coords[1], v.coords[2]);
			else
				gl.glVertex2d(v.coords[0], v.coords[1]);
			firstVertex = false;
		}

		public void combine(double[] coords, Object[] d, float[] w, Object[] outData)
		{
			VertexData v0 = (VertexData)d[0], v1 = (VertexData)d[1], v2 = (VertexData)d[2], v3 = (VertexData)d[3];
			/*
			System.out.println(v0);
			System.out.println(v1);
			System.out.println(v2);
			System.out.println(v3);
			*/
			if (v0 == null || v1 == null || v2 == null || v3 == null)
				return;
			outData[0] = new VertexData(
				coords,
				(v0.color != null && v1.color != null && v2.color != null && v3.color != null ?
					new double[] {
						w[0]*v0.color[0]+w[1]*v1.color[0]+w[2]*v2.color[0]+w[3]*v3.color[0],
						w[0]*v0.color[1]+w[1]*v1.color[1]+w[2]*v2.color[1]+w[3]*v3.color[1],
						w[0]*v0.color[2]+w[1]*v1.color[2]+w[2]*v2.color[2]+w[3]*v3.color[2]} :
					null),
				w[0]*v0.alpha+w[1]*v1.alpha+w[2]*v2.alpha+w[3]*v3.alpha,
				new double[] {
					w[0]*v0.normal[0]+w[1]*v1.normal[0]+w[2]*v2.normal[0]+w[3]*v3.normal[0],
					w[0]*v0.normal[1]+w[1]*v1.normal[1]+w[2]*v2.normal[1]+w[3]*v3.normal[1],
					w[0]*v0.normal[2]+w[1]*v1.normal[2]+w[2]*v2.normal[2]+w[3]*v3.normal[2]},
				v0.ambient, v0.diffuse, v0.specular, v0.specularExp);
		}
	}
	
	private class PatchTessellatorAlpha extends GLUtessellatorCallbackAdapter
	{
		private int colorMode; // 0: uni,  1: flat, 2: interp
		private int lightMode; // 0: none, 1: flat, 2: gouraud
		private int alphaMode; // 0: uni,  1: flat, 2: interp
		private boolean firstVertex;
		private GLRenderer r;
		private VertexData v0;
		private VertexData[] v;
		private int vCounter;
		private boolean fill;
		private double[] globalColor;
		private double globalAlpha;
		private String lineStyle;
		private float lineWidth;

		PatchTessellatorAlpha(GLRenderer r, int colorMode, int lightMode, int alphaMode,
			double[] globalColor, double globalAlpha, String lineStyle, float lineWidth)
		{
			this.r = r;
			this.colorMode = colorMode;
			this.lightMode = lightMode;
			this.alphaMode = alphaMode;
			this.v = new VertexData[3];
			this.globalColor = globalColor;
			this.globalAlpha = globalAlpha;
			this.lineStyle = lineStyle;
			this.lineWidth = lineWidth;
		}

		public void beginData(int mode, Object pData)
		{
			vCounter = 0;
			v0 = (VertexData)pData;
			fill = (mode != GL.GL_LINE_LOOP);
		}

		public void end()
		{
			if (!fill)
			{
				v[1] = v0;
				addLinePrimitive();
			}
		}

		private void addLinePrimitive()
		{
			Point3D p = new Point3D(0, 0, 0);
			final VertexData[] v = (VertexData[])this.v.clone();
			final VertexData v0 = (VertexData)this.v0;

			p.add(v[0].coords);
			p.add(v[1].coords);
			p.scale(1/2.0);
			p.sub(r.cameraPos);

			r.addAlphaPrimitive(
				-p.dot(r.cameraDir),
				new Runnable() {
					public void run()
					{
						if (lightMode > 0)
						{
							gl.glMaterialfv(lightSideMode, GL.GL_SPECULAR,
								new float[] {v0.specular, v0.specular, v0.specular, 1}, 0);
							gl.glMaterialf(lightSideMode, GL.GL_SHININESS, v0.specularExp);
							gl.glEnable(GL.GL_LIGHTING);
						}
						if (colorMode < 2 && alphaMode < 2)
						{
							double[] color = (colorMode == 0 ? globalColor : v[1].color);
							double alpha = (alphaMode == 0 ? globalAlpha : v[1].alpha);
							gl.glColor4d(color[0], color[1], color[2], alpha);
							if (lightMode > 0)
							{
								gl.glMaterialfv(lightSideMode, GL.GL_AMBIENT,
									new float[] {v0.ambient*(float)color[0], v0.ambient*(float)color[1],
										v0.ambient*(float)color[2], 1}, 0);
								gl.glMaterialfv(lightSideMode, GL.GL_DIFFUSE,
									new float[] {v0.diffuse*(float)color[0], v0.diffuse*(float)color[1],
										v0.diffuse*(float)color[2], (float)alpha}, 0);
							}
						}
						if (lightMode == 1)
							gl.glNormal3d(v[1].normal[0], v[1].normal[1], v[1].normal[2]);
						if (colorMode == 2 || lightMode == 2 || alphaMode == 2)
							gl.glShadeModel(GL.GL_SMOOTH);
						else
							gl.glShadeModel(GL.GL_FLAT);
						setLineStyle(lineStyle, false);
						setLineWidth(lineWidth);
						gl.glBegin(GL.GL_LINES);
						for (int i=0; i<2; i++)
						{
							if (colorMode == 2 || alphaMode == 2)
							{
								double[] color = (colorMode == 2 ? v[i].color : (colorMode == 1 ? v[1].color : globalColor));
								double alpha = (alphaMode == 2 ? v[i].alpha : (alphaMode == 1 ? v[1].alpha : globalAlpha));
								gl.glColor4d(color[0], color[1], color[2], alpha);
								if (lightMode > 0)
								{
									gl.glMaterialfv(lightSideMode, GL.GL_AMBIENT,
										new float[] {v0.ambient*(float)color[0], v0.ambient*(float)color[1],
											v0.ambient*(float)color[2], 1}, 0);
									gl.glMaterialfv(lightSideMode, GL.GL_DIFFUSE,
										new float[] {v0.diffuse*(float)color[0], v0.diffuse*(float)color[1],
											v0.diffuse*(float)color[2], (float)alpha}, 0);
								}
							}
							if (lightMode == 2)
								gl.glNormal3d(v[i].normal[0], v[i].normal[1], v[i].normal[2]);
							if (v[i].coords.length > 2)
								gl.glVertex3d(v[i].coords[0], v[i].coords[1], v[i].coords[2]);
							else
								gl.glVertex2d(v[i].coords[0], v[i].coords[1]);
						}
						gl.glEnd();
						setLineStyle("-", false);
						setLineWidth(0.5F);
						if (lightMode > 0)
							gl.glDisable(GL.GL_LIGHTING);
					}
				});
		}

		public void vertex(Object vData)
		{
			if (fill)
			{
				v[vCounter%3] = (VertexData)vData;
				vCounter++;

				if ((vCounter%3) == 0)
				{
					Point3D p = new Point3D(0, 0, 0);
					final VertexData[] v = (VertexData[])this.v.clone();
					final VertexData v0 = (VertexData)this.v0;

					for (int i=0; i<3; i++)
						p.add(v[i].coords);
					p.scale(1/3.0);
					p.sub(r.cameraPos);

					r.addAlphaPrimitive(
							-p.dot(r.cameraDir),
							new Runnable() {
								public void run()
								{
									if (lightMode > 0)
									{
										gl.glMaterialfv(lightSideMode, GL.GL_SPECULAR,
											new float[] {v0.specular, v0.specular, v0.specular, 1}, 0);
										gl.glMaterialf(lightSideMode, GL.GL_SHININESS, v0.specularExp);
										gl.glEnable(GL.GL_LIGHTING);
									}
									if (colorMode < 2 && alphaMode < 2)
									{
										double[] color = (colorMode == 0 ? globalColor : v0.color);
										double alpha = (alphaMode == 0 ? globalAlpha : v0.alpha);
										gl.glColor4d(color[0], color[1], color[2], alpha);
										if (lightMode > 0)
										{
											gl.glMaterialfv(lightSideMode, GL.GL_AMBIENT,
												new float[] {v0.ambient*(float)color[0], v0.ambient*(float)color[1],
													v0.ambient*(float)color[2], 1}, 0);
											gl.glMaterialfv(lightSideMode, GL.GL_DIFFUSE,
													new float[] {v0.diffuse*(float)color[0], v0.diffuse*(float)color[1],
														v0.diffuse*(float)color[2], (float)alpha}, 0);
										}
									}
									if (lightMode == 1)
										gl.glNormal3d(v0.normal[0], v0.normal[1], v0.normal[2]);
									if (colorMode == 2 || lightMode == 2 || alphaMode == 2)
										gl.glShadeModel(GL.GL_SMOOTH);
									else
										gl.glShadeModel(GL.GL_FLAT);
									gl.glPolygonOffset(po, po);
									setPolygonOffset(true);
									gl.glBegin(GL.GL_TRIANGLES);
									for (int i=0; i<3; i++)
									{
										if (colorMode == 2 || alphaMode == 2)
										{
											double[] color = (colorMode == 2 ? v[i].color : (colorMode == 1 ? v0.color : globalColor));
											double alpha = (alphaMode == 2 ? v[i].alpha : (alphaMode == 1 ? v0.alpha : globalAlpha));
											gl.glColor4d(color[0], color[1], color[2], alpha);
											if (lightMode > 0)
											{
												gl.glMaterialfv(lightSideMode, GL.GL_AMBIENT,
														new float[] {v0.ambient*(float)color[0], v0.ambient*(float)color[1],
															v0.ambient*(float)color[2], 1}, 0);
												gl.glMaterialfv(lightSideMode, GL.GL_DIFFUSE,
														new float[] {v0.diffuse*(float)color[0], v0.diffuse*(float)color[1],
															v0.diffuse*(float)color[2], (float)alpha}, 0);
											}
										}
										if (lightMode == 2)
											gl.glNormal3d(v[i].normal[0], v[i].normal[1], v[i].normal[2]);
										if (v[i].coords.length > 2)
											gl.glVertex3d(v[i].coords[0], v[i].coords[1], v[i].coords[2]);
										else
											gl.glVertex2d(v[i].coords[0], v[i].coords[1]);
									}
									gl.glEnd();
									setPolygonOffset(false);
									if (lightMode > 0)
										gl.glDisable(GL.GL_LIGHTING);
								}
							});
				}
			}
			else
			{
				v[vCounter] = (VertexData)vData;
				if (vCounter == 0)
				{
					v0 = v[vCounter];
					vCounter++;
				}
				else
				{
					addLinePrimitive();
					v[0] = v[1];
				}
			}
		}
		
		public void combine(double[] coords, Object[] d, float[] w, Object[] outData)
		{
			VertexData v0 = (VertexData)d[0], v1 = (VertexData)d[1], v2 = (VertexData)d[2], v3 = (VertexData)d[3];
			if (v0 == null || v1 == null || v2 == null || v3 == null)
				return;
			outData[0] = new VertexData(
				coords,
				(v0.color != null && v1.color != null && v2.color != null && v3.color != null ?
					new double[] {
						w[0]*v0.color[0]+w[1]*v1.color[0]+w[2]*v2.color[0]+w[3]*v3.color[0],
						w[0]*v0.color[1]+w[1]*v1.color[1]+w[2]*v2.color[1]+w[3]*v3.color[1],
						w[0]*v0.color[2]+w[1]*v1.color[2]+w[2]*v2.color[2]+w[3]*v3.color[2]} :
					null),
				w[0]*v0.alpha+w[1]*v1.alpha+w[2]*v2.alpha+w[3]*v3.alpha,
				new double[] {
					w[0]*v0.normal[0]+w[1]*v1.normal[0]+w[2]*v2.normal[0]+w[3]*v3.normal[0],
					w[0]*v0.normal[1]+w[1]*v1.normal[1]+w[2]*v2.normal[1]+w[3]*v3.normal[1],
					w[0]*v0.normal[2]+w[1]*v1.normal[2]+w[2]*v2.normal[2]+w[3]*v3.normal[2]},
				v0.ambient, v0.diffuse, v0.specular, v0.specularExp);
		}
	}

	/* scale 3D points */
	private double[][] scale(double[][] pts)
	{
		boolean has_z = (pts.length > 0 && pts[0].length > 2);

		if (sx.isLinear() && sy.isLinear() && (!has_z || sz.isLinear()))
			return pts;

		double[][] out = new double[pts.length][(has_z ? 3 : 2)];
		for (int i=0; i<pts.length; i++)
		{
			out[i][0] = sx.scale(pts[i][0]);
			out[i][1] = sy.scale(pts[i][1]);
			if (has_z)
				out[i][2] = sz.scale(pts[i][2]);
		}
		return out;
	}

	public void draw(PatchObject patch)
	{
		double[][] f = patch.Faces.asDoubleMatrix();
		double[][] v = scale(patch.Vertices.asDoubleMatrix());
		double[][] c = null;
		double[][] n = patch.VertexNormals.asDoubleMatrix();
		double[] a = null;
		int[] faceCount = patch.getFaceCount();

		boolean has_z = (v.length > 0 && v[0].length > 2);

		boolean hasFaceColor = false;
		boolean hasFaceAlpha = false;
		int faceColorMode = (patch.FaceColor.isSet() ? 0 : (patch.FaceColor.is("flat") ? 1 : 2));
		int faceLightMode = (patch.FaceLighting.is("none") ? 0 : (patch.FaceLighting.is("flat") ? 1 : 2));
		int faceAlphaMode = (patch.FaceAlpha.isDouble() ? 0 : (patch.FaceAlpha.is("flat") ? 1 : 2));
		int edgeColorMode = (patch.EdgeColor.isSet() ? 0 : (patch.EdgeColor.is("flat") ? 1 : 2));
		int edgeLightMode = (patch.EdgeLighting.is("none") ? 0 : (patch.EdgeLighting.is("flat") ? 1 : 2));
		int edgeAlphaMode = (patch.EdgeAlpha.isDouble() ? 0 : (patch.EdgeAlpha.is("flat") ? 1 : 2));

		double[] fcolor = patch.FaceColor.getArray();
		double[] ecolor = patch.EdgeColor.getArray();

		float as = patch.AmbientStrength.floatValue();
		float ds = patch.DiffuseStrength.floatValue();
		float ss = patch.SpecularStrength.floatValue();
		float se = patch.SpecularExponent.floatValue();

		boolean[] clip = new boolean[v.length];
		if (has_z)
			for (int i=0; i<v.length; i++)
				clip[i] = isNaNorInf(v[i][0], v[i][1], v[i][2]);
		else
			for (int i=0; i<v.length; i++)
				clip[i] = isNaNorInf(v[i][0], v[i][1], 0);
		boolean[] clipF = new boolean[f.length];
		for (int i=0; i<f.length; i++)
		{
			clipF[i] = false;
			for (int j=0; j<faceCount[i] && !clipF[i]; j++)
				clipF[i] = (clipF[i] || clip[(int)f[i][j]-1]);
		}

		if (!patch.FaceColor.isSet() || !patch.EdgeColor.isSet())
		{
			c = patch.getCData();
			hasFaceColor = (c != null && c.length == f.length);
		}

		if (faceAlphaMode > 0 || edgeAlphaMode > 0)
		{
			a = patch.getAlphaData();
			hasFaceAlpha = (a != null && a.length == f.length);
		}

		VertexData[][] vData = new VertexData[f.length][];
		for (int i=0; i<f.length; i++)
		{
			vData[i] = new VertexData[faceCount[i]];
			for (int j=0; j<faceCount[i]; j++)
			{
				int k = (int)f[i][j]-1;
				vData[i][j] = new VertexData(
					v[k],
					(c == null ? null : (hasFaceColor ? c[i] : c[k])),
					(a == null ? 1.0 : (hasFaceAlpha ? a[i] : a[k])),
					n[k],
					as, ds, ss, se);
			}
		}

		if (faceLightMode > 0 || edgeLightMode > 0)
		{
			gl.glMaterialfv(lightSideMode, GL.GL_SPECULAR,
				new float[] {ss, ss, ss, 1}, 0);
			gl.glMaterialf(lightSideMode, GL.GL_SHININESS, se);
		}

		if (!patch.FaceColor.is("none"))
		{
			if (patch.FaceAlpha.isDouble() && patch.FaceAlpha.doubleValue() == 1)
			{
				if (faceColorMode == 0)
				{
					gl.glColor3d(fcolor[0], fcolor[1], fcolor[2]);
					if (faceLightMode > 0)
					{
						gl.glMaterialfv(lightSideMode, GL.GL_AMBIENT,
							new float[] {as*(float)fcolor[0], as*(float)fcolor[1], as*(float)fcolor[2], 1}, 0); 
						gl.glMaterialfv(lightSideMode, GL.GL_DIFFUSE,
							new float[] {ds*(float)fcolor[0], ds*(float)fcolor[1], ds*(float)fcolor[2], 1}, 0); 
					}
				}

				if (faceLightMode > 0)
					gl.glEnable(GL.GL_LIGHTING);

				GLUtessellator tess = getTess(true);
				GLUtessellatorCallback cb = new PatchTessellator(gl, faceColorMode, faceLightMode,
					patch.__Index__.intValue());
				double[] vv = new double[3];
						
				glu.gluTessCallback(tess, GLU.GLU_TESS_BEGIN_DATA,  cb);
				glu.gluTessCallback(tess, GLU.GLU_TESS_END,  cb);
				glu.gluTessCallback(tess, GLU.GLU_TESS_COMBINE,  cb);
				glu.gluTessCallback(tess, GLU.GLU_TESS_VERTEX,  cb);
				glu.gluTessCallback(tess, GLU.GLU_TESS_EDGE_FLAG,  null);
						
				for (int i=0; i<f.length; i++)
				{
					if (clipF[i])
						continue;

					glu.gluTessBeginPolygon(tess, vData[i][0]);
					glu.gluTessBeginContour(tess);
					for (int j=0; j<faceCount[i]; j++)
					{
						int index = (int)f[i][j]-1;
						vv[0] = v[index][0];
						vv[1] = v[index][1];
						if (has_z)
							vv[2] = v[index][2];
						glu.gluTessVertex(tess, vv, 0, vData[i][j]);
					}
					glu.gluTessEndContour(tess);
					glu.gluTessEndPolygon(tess);
				}

				if (faceLightMode > 0)
					gl.glDisable(GL.GL_LIGHTING);
			}
			else
			{
				GLUtessellator tess = getTess(true);
				GLUtessellatorCallback cb = new PatchTessellatorAlpha(this, faceColorMode, faceLightMode, faceAlphaMode,
								fcolor, (faceAlphaMode == 0 ? patch.FaceAlpha.doubleValue() : 1.0), "-", 0.5F);
				double[] vv = new double[3];
				
				glu.gluTessCallback(tess, GLU.GLU_TESS_BEGIN_DATA,  cb);
				glu.gluTessCallback(tess, GLU.GLU_TESS_END,  cb);
				glu.gluTessCallback(tess, GLU.GLU_TESS_COMBINE,  cb);
				glu.gluTessCallback(tess, GLU.GLU_TESS_VERTEX,  cb);
				glu.gluTessCallback(tess, GLU.GLU_TESS_EDGE_FLAG,  cb);
						
				for (int i=0; i<f.length; i++)
				{
					if (clipF[i])
						continue;

					glu.gluTessBeginPolygon(tess, vData[i][0]);
					glu.gluTessBeginContour(tess);
					for (int j=0; j<faceCount[i]; j++)
					{
						int index = (int)f[i][j]-1;
						vv[0] = v[index][0];
						vv[1] = v[index][1];
						if (has_z)
							vv[2] = v[index][2];
						glu.gluTessVertex(tess, vv, 0, vData[i][j]);
					}
					glu.gluTessEndContour(tess);
					glu.gluTessEndPolygon(tess);
				}
			}
		}
		
		if (!patch.EdgeColor.is("none"))
		{
			if (patch.EdgeAlpha.isDouble() && patch.EdgeAlpha.doubleValue() == 1)
			{
				if (edgeColorMode == 0)
				{
					gl.glColor3d(ecolor[0], ecolor[1], ecolor[2]);
					if (edgeLightMode > 0)
					{
						gl.glMaterialfv(lightSideMode, GL.GL_AMBIENT,
							new float[] {as*(float)ecolor[0], as*(float)ecolor[1], as*(float)ecolor[2], 1}, 0); 
						gl.glMaterialfv(lightSideMode, GL.GL_DIFFUSE,
							new float[] {ds*(float)ecolor[0], ds*(float)ecolor[1], ds*(float)ecolor[2], 1}, 0); 
					}
				}

				if (edgeLightMode > 0)
					gl.glEnable(GL.GL_LIGHTING);

				setLineStyle(patch.LineStyle.getValue(), false);
				setLineWidth(patch.LineWidth.floatValue());

				GLUtessellator tess = getTess(false);
				GLUtessellatorCallback cb = new PatchTessellator(gl, edgeColorMode, edgeLightMode);
				double[] vv = new double[3];
						
				glu.gluTessCallback(tess, GLU.GLU_TESS_BEGIN_DATA,  cb);
				glu.gluTessCallback(tess, GLU.GLU_TESS_END,  cb);
				glu.gluTessCallback(tess, GLU.GLU_TESS_COMBINE,  cb);
				glu.gluTessCallback(tess, GLU.GLU_TESS_VERTEX,  cb);
				glu.gluTessCallback(tess, GLU.GLU_TESS_EDGE_FLAG,  null);
						
				for (int i=0; i<f.length; i++)
				{
					if (clipF[i])
						continue;

					glu.gluTessBeginPolygon(tess, vData[i][0]);
					glu.gluTessBeginContour(tess);
					for (int j=0; j<faceCount[i]; j++)
					{
						int index = (int)f[i][j]-1;
						vv[0] = v[index][0];
						vv[1] = v[index][1];
						if (has_z)
							vv[2] = v[index][2];
						glu.gluTessVertex(tess, vv, 0, vData[i][j]);
					}
					glu.gluTessEndContour(tess);
					glu.gluTessEndPolygon(tess);
				}

				setLineStyle("-", false);
				setLineWidth(0.5F);

				if (edgeLightMode > 0)
					gl.glDisable(GL.GL_LIGHTING);
			}
			else
			{
				GLUtessellator tess = getTess(false);
				GLUtessellatorCallback cb = new PatchTessellatorAlpha(this, edgeColorMode, edgeLightMode, edgeAlphaMode,
								ecolor, (edgeAlphaMode == 0 ? patch.EdgeAlpha.doubleValue() : 1.0),
								patch.LineStyle.getValue(), patch.LineWidth.floatValue());
				double[] vv = new double[3];
				
				glu.gluTessCallback(tess, GLU.GLU_TESS_BEGIN_DATA,  cb);
				glu.gluTessCallback(tess, GLU.GLU_TESS_END,  cb);
				glu.gluTessCallback(tess, GLU.GLU_TESS_COMBINE,  cb);
				glu.gluTessCallback(tess, GLU.GLU_TESS_VERTEX,  cb);
				glu.gluTessCallback(tess, GLU.GLU_TESS_EDGE_FLAG,  null);

				for (int i=0; i<f.length; i++)
				{
					if (clipF[i])
						continue;

					glu.gluTessBeginPolygon(tess, vData[i][0]);
					glu.gluTessBeginContour(tess);
					for (int j=0; j<faceCount[i]; j++)
					{
						int index = (int)f[i][j]-1;
						vv[0] = v[index][0];
						vv[1] = v[index][1];
						if (has_z)
							vv[2] = v[index][2];
						glu.gluTessVertex(tess, vv, 0, vData[i][j]);
					}
					glu.gluTessEndContour(tess);
					glu.gluTessEndPolygon(tess);
				}
			}
		}

		if (patch.Marker.isSet() && !(patch.MarkerEdgeColor.is("none") && patch.MarkerFaceColor.is("none")))
		{
			MarkerDrawer md = getMarkerDrawer();
			
			boolean doEdge = !patch.MarkerEdgeColor.is("none");
			boolean doFace = !patch.MarkerFaceColor.is("none");

			double[] mecolor = patch.MarkerEdgeColor.getArray();
			double[] mfcolor = patch.MarkerFaceColor.getArray();
			if (mecolor == null && patch.MarkerEdgeColor.is("auto"))
			{
				mecolor = patch.EdgeColor.getArray();
				doEdge = !patch.EdgeColor.is("none");
			}
			if (mfcolor == null && patch.MarkerFaceColor.is("auto"))
			{
				mfcolor = patch.FaceColor.getArray();
				doFace = !patch.FaceColor.is("none");
			}

			if ((mecolor == null || mfcolor == null) && c == null)
				c = patch.getCData();

			md.begin(patch.Marker, patch.MarkerSize, patch.LineWidth.floatValue());
			for (int i=0; i<v.length; i++)
			{
				if (clip[i])
					continue;

				double[] lc = (doEdge ? (mecolor == null ? c[i] : mecolor) : null);
				double[] fc = (doFace ? (mfcolor == null ? c[i] : mfcolor) : null);

				md.draw(v[i][0], v[i][1], (has_z ? v[i][2] : 0.0), lc, fc);
			}
			md.end();
		}

	}

	public void draw(SurfaceObject surf)
	{
		double[][] x = sx.scale(surf.XData.asDoubleMatrix());
		double[][] y = sy.scale(surf.YData.asDoubleMatrix());
		double[][] z = sz.scale(surf.ZData.asDoubleMatrix());
		double[][][] c = null;
		double[][][] n = surf.VertexNormals.asDoubleMatrix3();
		double[][] a = null;
		
		final int faceColorMode = 
			(surf.FaceColor.isSet() ? 0 :
			 (surf.FaceColor.is("flat") ? 1 :
			  (surf.FaceColor.is("interp") ? 2 : 
			   (surf.FaceColor.is("texturemap") ? 3 : -1))));
		final int faceLightMode = (surf.FaceLighting.is("none") ? 0 : (surf.FaceLighting.is("flat") ? 1 : 2));
		final int faceAlphaMode = (surf.FaceAlpha.isDouble() ? 0 : (surf.FaceAlpha.is("flat") ? 1 : 2));
		final int edgeColorMode = (surf.EdgeColor.isSet() ? 0 : (surf.EdgeColor.is("flat") ? 1 : (surf.EdgeColor.is("interp") ? 2 : -1)));
		final int edgeLightMode = (surf.EdgeLighting.is("none") ? 0 : (surf.EdgeLighting.is("flat") ? 1 : 2));
		final int edgeAlphaMode = (surf.EdgeAlpha.isDouble() ? 0 : (surf.EdgeAlpha.is("flat") ? 1 : 2));

		final double[] fcolor = (faceColorMode == 3 ? new double[] {1, 1, 1} : surf.FaceColor.getArray());
		final double[] ecolor = surf.EdgeColor.getArray();

		final float as = surf.AmbientStrength.floatValue();
		final float ds = surf.DiffuseStrength.floatValue();
		final float ss = surf.SpecularStrength.floatValue();
		final float se = surf.SpecularExponent.floatValue();

		boolean[][] clip = new boolean[z.length][z.length > 0 ? z[0].length : 0];
		for (int i=0; i<z.length; i++)
			for (int j=0; j<z[0].length; j++)
				clip[i][j] = isNaNorInf(x[i][j], y[i][j], z[i][j]);

		if ((faceColorMode > 0 && faceColorMode < 3) || edgeColorMode > 0)
		{
			c = surf.getCData();
		}

		if (faceAlphaMode > 0 || edgeAlphaMode > 0)
		{
			a = surf.getAlphaData();
		}

		if (faceLightMode > 0 || edgeLightMode > 0)
		{
			gl.glMaterialfv(lightSideMode, GL.GL_SPECULAR,
				new float[] {ss, ss, ss, 1}, 0);
			gl.glMaterialf(lightSideMode, GL.GL_SHININESS, se);
		}

		TextureData d = null;
		if (faceColorMode == 3)
		{
			d = (TextureData)surf.getCachedData();
			if (d == null)
			{
				d = makeTextureFromCData(surf.CData, surf.CDataMapping, surf.getAxes());
				if (d == null)
					return;
				else
					surf.setCachedData(d);
			}
			gl.glBindTexture(GL.GL_TEXTURE_2D, d.texID);
		}

		if (!surf.FaceColor.is("none"))
		{
			if (surf.FaceAlpha.isDouble() && surf.FaceAlpha.doubleValue() == 1)
			{
				if (faceColorMode == 0 || faceColorMode == 3)
				{
					gl.glColor3d(fcolor[0], fcolor[1], fcolor[2]);
					if (faceLightMode > 0)
					{
						gl.glMaterialfv(lightSideMode, GL.GL_AMBIENT,
							new float[] {as*(float)fcolor[0], as*(float)fcolor[1], as*(float)fcolor[2], 1}, 0); 
						gl.glMaterialfv(lightSideMode, GL.GL_DIFFUSE,
							new float[] {ds*(float)fcolor[0], ds*(float)fcolor[1], ds*(float)fcolor[2], 1}, 0); 
					}
				}

				if (faceLightMode > 0)
					gl.glEnable(GL.GL_LIGHTING);
				gl.glShadeModel((faceColorMode == 2 || faceLightMode == 2) ? GL.GL_SMOOTH : GL.GL_FLAT);
				gl.glPolygonOffset(po, po);
				setPolygonOffset(true);
				if (d != null)
					gl.glEnable(GL.GL_TEXTURE_2D);

				for (int i=1; i<x.length; i++)
					for (int j=1; j<x[i].length; j++)
					{
						if (clip[i-1][j-1] || clip[i-1][j] || clip[i][j-1] || clip[i][j])
							continue;

						gl.glBegin(GL.GL_QUADS);

						// Vertex 1
						if (faceColorMode == 3)
							gl.glTexCoord2d((j-1)*d.tCoordX/(z[i].length-1), (i-1)*d.tCoordY/(z.length-1));
						else if (faceColorMode > 0)
						{
							double[] C = c[i-1][j-1];
							gl.glColor3d(C[0], C[1], C[2]);
							if (faceLightMode > 0)
							{
								gl.glMaterialfv(lightSideMode, GL.GL_AMBIENT,
										new float[] {as*(float)C[0], as*(float)C[1], as*(float)C[2], 1}, 0);
								gl.glMaterialfv(lightSideMode, GL.GL_DIFFUSE,
										new float[] {ds*(float)C[0], ds*(float)C[1], ds*(float)C[2], 1}, 0);
							}
						}
						if (faceLightMode > 0)
							gl.glNormal3d(n[i-1][j-1][0], n[i-1][j-1][1], n[i-1][j-1][2]);
						gl.glVertex3d(x[i-1][j-1], y[i-1][j-1], z[i-1][j-1]);

						// Vertex 2
						if (faceColorMode == 3)
							gl.glTexCoord2d((j-1)*d.tCoordX/(z[i].length-1), i*d.tCoordY/(z.length-1));
						else if (faceColorMode == 2)
						{
							double[] C = c[i][j-1];
							gl.glColor3d(C[0], C[1], C[2]);
							if (faceLightMode > 0)
							{
								gl.glMaterialfv(lightSideMode, GL.GL_AMBIENT,
										new float[] {as*(float)C[0], as*(float)C[1], as*(float)C[2], 1}, 0);
								gl.glMaterialfv(lightSideMode, GL.GL_DIFFUSE,
										new float[] {ds*(float)C[0], ds*(float)C[1], ds*(float)C[2], 1}, 0);
							}
						}
						if (faceLightMode == 2)
							gl.glNormal3d(n[i][j-1][0], n[i][j-1][1], n[i][j-1][2]);
						gl.glVertex3d(x[i][j-1], y[i][j-1], z[i][j-1]);

						// Vertex 3
						if (faceColorMode == 3)
							gl.glTexCoord2d(j*d.tCoordX/(z[i].length-1), i*d.tCoordY/(z.length-1));
						else if (faceColorMode == 2)
						{
							double[] C = c[i][j];
							gl.glColor3d(C[0], C[1], C[2]);
							if (faceLightMode > 0)
							{
								gl.glMaterialfv(lightSideMode, GL.GL_AMBIENT,
										new float[] {as*(float)C[0], as*(float)C[1], as*(float)C[2], 1}, 0);
								gl.glMaterialfv(lightSideMode, GL.GL_DIFFUSE,
										new float[] {ds*(float)C[0], ds*(float)C[1], ds*(float)C[2], 1}, 0);
							}
						}
						if (faceLightMode == 2)
							gl.glNormal3d(n[i][j][0], n[i][j][1], n[i][j][2]);
						gl.glVertex3d(x[i][j], y[i][j], z[i][j]);

						// Vertex 4
						if (faceColorMode == 3)
							gl.glTexCoord2d(j*d.tCoordX/(z[i].length-1), (i-1)*d.tCoordY/(z.length-1));
						else if (faceColorMode == 2)
						{
							double[] C = c[i-1][j];
							gl.glColor3d(C[0], C[1], C[2]);
							if (faceLightMode > 0)
							{
								gl.glMaterialfv(lightSideMode, GL.GL_AMBIENT,
										new float[] {as*(float)C[0], as*(float)C[1], as*(float)C[2], 1}, 0);
								gl.glMaterialfv(lightSideMode, GL.GL_DIFFUSE,
										new float[] {ds*(float)C[0], ds*(float)C[1], ds*(float)C[2], 1}, 0);
							}
						}
						if (faceLightMode == 2)
							gl.glNormal3d(n[i-1][j][0], n[i-1][j][1], n[i-1][j][2]);
						gl.glVertex3d(x[i-1][j], y[i-1][j], z[i-1][j]);

						gl.glEnd();
					}

				setPolygonOffset(false);
				if (d != null)
					gl.glDisable(GL.GL_TEXTURE_2D);

				if (faceLightMode > 0)
					gl.glDisable(GL.GL_LIGHTING);
			}
			else
			{
				final double falpha = surf.FaceAlpha.doubleValue();

				for (int i=1; i<x.length; i++)
					for (int j=1; j<x[i].length; j++)
					{
						if (clip[i-1][j-1] || clip[i-1][j] || clip[i][j-1] || clip[i][j])
							continue;

						final double[] xx = new double[] {x[i-1][j-1], x[i][j-1], x[i][j], x[i-1][j]};
						final double[] yy = new double[] {y[i-1][j-1], y[i][j-1], y[i][j], y[i-1][j]};
						final double[] zz = new double[] {z[i-1][j-1], z[i][j-1], z[i][j], z[i-1][j]};
						final double[][] nn = new double[][] {n[i-1][j-1], n[i][j-1], n[i][j], n[i-1][j]};
						final double[][] cc = (c != null ? new double[][] {c[i-1][j-1], c[i][j-1], c[i][j], c[i-1][j]} : null);
						final double[] aa = (a != null ? new double[] {a[i-1][j-1], a[i][j-1], a[i][j], a[i-1][j]} : null);

						Point3D center = new Point3D(
							(xx[0]+xx[1]+xx[2]+xx[3])/4,
							(yy[0]+yy[1]+yy[2]+yy[3])/4,
							(zz[0]+zz[1]+zz[2]+zz[3])/4);
						center.sub(cameraPos);

						addAlphaPrimitive(
							-center.dot(cameraDir),
							new Runnable() {
								public void run()
								{
									if (faceLightMode > 0)
									{
										gl.glMaterialfv(lightSideMode, GL.GL_SPECULAR,
											new float[] {ss, ss, ss, 1}, 0);
										gl.glMaterialf(lightSideMode, GL.GL_SHININESS, se);
										gl.glEnable(GL.GL_LIGHTING);
									}
									if (faceColorMode < 2 && faceAlphaMode < 2)
									{
										double[] C = (faceColorMode == 0 ? fcolor : cc[0]);
										double a = (faceAlphaMode == 0 ? falpha : aa[0]);
										gl.glColor4d(C[0], C[1], C[2], a);
										if (faceLightMode > 0)
										{
											gl.glMaterialfv(lightSideMode, GL.GL_AMBIENT,
												new float[] {as*(float)C[0], as*(float)C[1], as*(float)C[2], 1}, 0);
											gl.glMaterialfv(lightSideMode, GL.GL_DIFFUSE,
												new float[] {ds*(float)C[0], ds*(float)C[1], ds*(float)C[2], (float)a}, 0);
										}
									}
									if (faceLightMode == 1)
										gl.glNormal3d(nn[0][0], nn[0][1], nn[0][2]);
									if (faceColorMode == 2 || faceLightMode == 2 || faceAlphaMode == 2)
										gl.glShadeModel(GL.GL_SMOOTH);
									else
										gl.glShadeModel(GL.GL_FLAT);
									gl.glPolygonOffset(po, po);
									setPolygonOffset(true);
									gl.glBegin(GL.GL_QUADS);
									for (int i=0; i<4; i++)
									{
										if (faceColorMode == 2 || faceAlphaMode == 2)
										{
											double[] C = (faceColorMode == 2 ? cc[i] : (faceColorMode == 1 ? cc[0] : fcolor));
											double a = (faceAlphaMode == 2 ? aa[i] : (faceAlphaMode == 1 ? aa[0] : falpha));
											gl.glColor4d(C[0], C[1], C[2], a);
											if (faceLightMode > 0)
											{
												gl.glMaterialfv(lightSideMode, GL.GL_AMBIENT,
													new float[] {as*(float)C[0], as*(float)C[1], as*(float)C[2], 1}, 0);
												gl.glMaterialfv(lightSideMode, GL.GL_DIFFUSE,
													new float[] {ds*(float)C[0], ds*(float)C[1], ds*(float)C[2], (float)a}, 0);
											}
										}
										if (faceLightMode == 2)
											gl.glNormal3d(nn[i][0], nn[i][1], nn[i][2]);
										gl.glVertex3d(xx[i], yy[i], zz[i]);
									}
									gl.glEnd();
									setPolygonOffset(false);
									if (faceLightMode > 0)
										gl.glDisable(GL.GL_LIGHTING);
								}
							});
					}
			}
		}

		if (!surf.EdgeColor.is("none"))
		{
			if (surf.EdgeAlpha.isDouble() && surf.EdgeAlpha.doubleValue() == 1)
			{
				if (edgeColorMode == 0)
				{
					gl.glColor3d(ecolor[0], ecolor[1], ecolor[2]);
					if (edgeLightMode > 0)
					{
						gl.glMaterialfv(lightSideMode, GL.GL_AMBIENT,
							new float[] {as*(float)ecolor[0], as*(float)ecolor[1], as*(float)ecolor[2], 1}, 0); 
						gl.glMaterialfv(lightSideMode, GL.GL_DIFFUSE,
							new float[] {ds*(float)ecolor[0], ds*(float)ecolor[1], ds*(float)ecolor[2], 1}, 0); 
					}
				}

				if (edgeLightMode > 0)
					gl.glEnable(GL.GL_LIGHTING);
				gl.glShadeModel((edgeColorMode == 2 || edgeLightMode == 2) ? GL.GL_SMOOTH : GL.GL_FLAT);
				
				setLineStyle(surf.LineStyle.getValue(), false);
				setLineWidth(surf.LineWidth.floatValue());

				for (int i=0; i<x.length; i++)
				{
					for (int j=1; j<x[i].length; j++)
					{
						if (clip[i][j-1] || clip[i][j])
							continue;

						gl.glBegin(GL.GL_LINES);

						// Vertex 1
						if (edgeColorMode > 0)
						{
							double[] C = c[i][j-1];
							gl.glColor3d(C[0], C[1], C[2]);
							if (edgeLightMode > 0)
							{
								gl.glMaterialfv(lightSideMode, GL.GL_AMBIENT,
										new float[] {as*(float)C[0], as*(float)C[1], as*(float)C[2], 1}, 0);
								gl.glMaterialfv(lightSideMode, GL.GL_DIFFUSE,
										new float[] {ds*(float)C[0], ds*(float)C[1], ds*(float)C[2], 1}, 0);
							}
						}
						if (edgeLightMode > 0)
							gl.glNormal3d(n[i][j-1][0], n[i][j-1][1], n[i][j-1][2]);
						gl.glVertex3d(x[i][j-1], y[i][j-1], z[i][j-1]);

						// Vertex 2
						if (edgeColorMode == 2)
						{
							double[] C = c[i][j];
							gl.glColor3d(C[0], C[1], C[2]);
							if (edgeLightMode > 0)
							{
								gl.glMaterialfv(lightSideMode, GL.GL_AMBIENT,
										new float[] {as*(float)C[0], as*(float)C[1], as*(float)C[2], 1}, 0);
								gl.glMaterialfv(lightSideMode, GL.GL_DIFFUSE,
										new float[] {ds*(float)C[0], ds*(float)C[1], ds*(float)C[2], 1}, 0);
							}
						}
						if (edgeLightMode == 2)
							gl.glNormal3d(n[i][j][0], n[i][j][1], n[i][j][2]);
						gl.glVertex3d(x[i][j], y[i][j], z[i][j]);

						gl.glEnd();
					}
				}
				
				for (int j=0; j<y[0].length; j++)
				{
					for (int i=1; i<y.length; i++)
					{
						if (clip[i-1][j] || clip[i][j])
							continue;

						gl.glBegin(GL.GL_LINES);

						// Vertex 1
						if (edgeColorMode > 0)
						{
							double[] C = c[i-1][j];
							gl.glColor3d(C[0], C[1], C[2]);
							if (edgeLightMode > 0)
							{
								gl.glMaterialfv(lightSideMode, GL.GL_AMBIENT,
										new float[] {as*(float)C[0], as*(float)C[1], as*(float)C[2], 1}, 0);
								gl.glMaterialfv(lightSideMode, GL.GL_DIFFUSE,
										new float[] {ds*(float)C[0], ds*(float)C[1], ds*(float)C[2], 1}, 0);
							}
						}
						if (edgeLightMode > 0)
							gl.glNormal3d(n[i-1][j][0], n[i-1][j][1], n[i-1][j][2]);
						gl.glVertex3d(x[i-1][j], y[i-1][j], z[i-1][j]);

						// Vertex 2
						if (edgeColorMode == 2)
						{
							double[] C = c[i][j];
							gl.glColor3d(C[0], C[1], C[2]);
							if (edgeLightMode > 0)
							{
								gl.glMaterialfv(lightSideMode, GL.GL_AMBIENT,
										new float[] {as*(float)C[0], as*(float)C[1], as*(float)C[2], 1}, 0);
								gl.glMaterialfv(lightSideMode, GL.GL_DIFFUSE,
										new float[] {ds*(float)C[0], ds*(float)C[1], ds*(float)C[2], 1}, 0);
							}
						}
						if (edgeLightMode == 2)
							gl.glNormal3d(n[i][j][0], n[i][j][1], n[i][j][2]);
						gl.glVertex3d(x[i][j], y[i][j], z[i][j]);

						gl.glEnd();
					}
				}
				
				setLineStyle("-", false);
				setLineWidth(0.5f);

				if (edgeLightMode > 0)
					gl.glDisable(GL.GL_LIGHTING);
			}
			else
			{
				final double ealpha = surf.EdgeAlpha.doubleValue();
				final String lineStyle = surf.LineStyle.getValue();
				final float lineWidth = surf.LineWidth.floatValue();

				for (int i=0; i<x.length; i++)
				{
					for (int j=1; j<x[i].length; j++)
					{
						if (clip[i][j-1] || clip[i][j])
							continue;

						final double[] xx = new double[] {x[i][j-1], x[i][j]};
						final double[] yy = new double[] {y[i][j-1], y[i][j]};
						final double[] zz = new double[] {z[i][j-1], z[i][j]};
						final double[][] nn = new double[][] {n[i][j-1], n[i][j]};
						final double[][] cc = (c != null ? new double[][] {c[i][j-1], c[i][j]} : null);
						final double[] aa = (a != null ? new double[] {a[i][j-1], a[i][j]} : null);

						Point3D center = new Point3D(
							(xx[0]+xx[1])/2,
							(yy[0]+yy[1])/2,
							(zz[0]+zz[1])/2);
						center.sub(cameraPos);

						addAlphaPrimitive(
							-center.dot(cameraDir),
							new Runnable() {
								public void run()
								{
									if (edgeLightMode > 0)
									{
										gl.glMaterialfv(lightSideMode, GL.GL_SPECULAR,
											new float[] {ss, ss, ss, 1}, 0);
										gl.glMaterialf(lightSideMode, GL.GL_SHININESS, se);
										gl.glEnable(GL.GL_LIGHTING);
									}
									if (edgeColorMode < 2 && edgeAlphaMode < 2)
									{
										double[] C = (edgeColorMode == 0 ? ecolor : cc[0]);
										double a = (edgeAlphaMode == 0 ? ealpha : aa[0]);
										gl.glColor4d(C[0], C[1], C[2], a);
										if (edgeLightMode > 0)
										{
											gl.glMaterialfv(lightSideMode, GL.GL_AMBIENT,
												new float[] {as*(float)C[0], as*(float)C[1], as*(float)C[2], 1}, 0);
											gl.glMaterialfv(lightSideMode, GL.GL_DIFFUSE,
												new float[] {ds*(float)C[0], ds*(float)C[1], ds*(float)C[2], (float)a}, 0);
										}
									}
									if (edgeLightMode == 1)
										gl.glNormal3d(nn[0][0], nn[0][1], nn[0][2]);
									if (edgeColorMode == 2 || edgeLightMode == 2 || edgeAlphaMode == 2)
										gl.glShadeModel(GL.GL_SMOOTH);
									else
										gl.glShadeModel(GL.GL_FLAT);
									setLineStyle(lineStyle, false);
									setLineWidth(lineWidth);
									gl.glBegin(GL.GL_LINES);
									for (int i=0; i<2; i++)
									{
										if (edgeColorMode == 2 || edgeAlphaMode == 2)
										{
											double[] C = (edgeColorMode == 2 ? cc[i] : (edgeColorMode == 1 ? cc[0] : ecolor));
											double a = (edgeAlphaMode == 2 ? aa[i] : (edgeAlphaMode == 1 ? aa[0] : ealpha));
											gl.glColor4d(C[0], C[1], C[2], a);
											if (edgeLightMode > 0)
											{
												gl.glMaterialfv(lightSideMode, GL.GL_AMBIENT,
													new float[] {as*(float)C[0], as*(float)C[1], as*(float)C[2], 1}, 0);
												gl.glMaterialfv(lightSideMode, GL.GL_DIFFUSE,
													new float[] {ds*(float)C[0], ds*(float)C[1], ds*(float)C[2], (float)a}, 0);
											}
										}
										if (edgeLightMode == 2)
											gl.glNormal3d(nn[i][0], nn[i][1], nn[i][2]);
										gl.glVertex3d(xx[i], yy[i], zz[i]);
									}
									gl.glEnd();
									setLineStyle("-", false);
									setLineWidth(0.5f);
									if (edgeLightMode > 0)
										gl.glDisable(GL.GL_LIGHTING);
								}
							});
					}
				}
				
				for (int j=0; j<y[0].length; j++)
				{
					for (int i=1; i<y.length; i++)
					{
						if (clip[i-1][j] || clip[i][j])
							continue;

						final double[] xx = new double[] {x[i-1][j], x[i][j]};
						final double[] yy = new double[] {y[i-1][j], y[i][j]};
						final double[] zz = new double[] {z[i-1][j], z[i][j]};
						final double[][] nn = new double[][] {n[i-1][j], n[i][j]};
						final double[][] cc = (c != null ? new double[][] {c[i-1][j], c[i][j]} : null);
						final double[] aa = (a != null ? new double[] {a[i-1][j], a[i][j]} : null);

						Point3D center = new Point3D(
							(xx[0]+xx[1])/2,
							(yy[0]+yy[1])/2,
							(zz[0]+zz[1])/2);
						center.sub(cameraPos);

						addAlphaPrimitive(
							-center.dot(cameraDir),
							new Runnable() {
								public void run()
								{
									if (edgeLightMode > 0)
									{
										gl.glMaterialfv(lightSideMode, GL.GL_SPECULAR,
											new float[] {ss, ss, ss, 1}, 0);
										gl.glMaterialf(lightSideMode, GL.GL_SHININESS, se);
										gl.glEnable(GL.GL_LIGHTING);
									}
									if (edgeColorMode < 2 && edgeAlphaMode < 2)
									{
										double[] C = (edgeColorMode == 0 ? ecolor : cc[0]);
										double a = (edgeAlphaMode == 0 ? ealpha : aa[0]);
										gl.glColor4d(C[0], C[1], C[2], a);
										if (edgeLightMode > 0)
										{
											gl.glMaterialfv(lightSideMode, GL.GL_AMBIENT,
												new float[] {as*(float)C[0], as*(float)C[1], as*(float)C[2], 1}, 0);
											gl.glMaterialfv(lightSideMode, GL.GL_DIFFUSE,
												new float[] {ds*(float)C[0], ds*(float)C[1], ds*(float)C[2], (float)a}, 0);
										}
									}
									if (edgeLightMode == 1)
										gl.glNormal3d(nn[0][0], nn[0][1], nn[0][2]);
									if (edgeColorMode == 2 || edgeLightMode == 2 || edgeAlphaMode == 2)
										gl.glShadeModel(GL.GL_SMOOTH);
									else
										gl.glShadeModel(GL.GL_FLAT);
									setLineStyle(lineStyle, false);
									setLineWidth(lineWidth);
									gl.glBegin(GL.GL_LINES);
									for (int i=0; i<2; i++)
									{
										if (edgeColorMode == 2 || edgeAlphaMode == 2)
										{
											double[] C = (edgeColorMode == 2 ? cc[i] : (edgeColorMode == 1 ? cc[0] : ecolor));
											double a = (edgeAlphaMode == 2 ? aa[i] : (edgeAlphaMode == 1 ? aa[0] : ealpha));
											gl.glColor4d(C[0], C[1], C[2], a);
											if (edgeLightMode > 0)
											{
												gl.glMaterialfv(lightSideMode, GL.GL_AMBIENT,
													new float[] {as*(float)C[0], as*(float)C[1], as*(float)C[2], 1}, 0);
												gl.glMaterialfv(lightSideMode, GL.GL_DIFFUSE,
													new float[] {ds*(float)C[0], ds*(float)C[1], ds*(float)C[2], (float)a}, 0);
											}
										}
										if (edgeLightMode == 2)
											gl.glNormal3d(nn[i][0], nn[i][1], nn[i][2]);
										gl.glVertex3d(xx[i], yy[i], zz[i]);
									}
									gl.glEnd();
									setLineStyle("-", false);
									setLineWidth(0.5f);
									if (edgeLightMode > 0)
										gl.glDisable(GL.GL_LIGHTING);
								}
							});
					}
				}
			}
		}

		if (surf.Marker.isSet() && !(surf.MarkerEdgeColor.is("none") && surf.MarkerFaceColor.is("none")))
		{
			MarkerDrawer md = getMarkerDrawer();
			
			boolean doEdge = !surf.MarkerEdgeColor.is("none");
			boolean doFace = !surf.MarkerFaceColor.is("none");

			double[] mecolor = surf.MarkerEdgeColor.getArray();
			double[] mfcolor = surf.MarkerFaceColor.getArray();
			if (mecolor == null && surf.MarkerEdgeColor.is("auto"))
			{
				mecolor = surf.EdgeColor.getArray();
				doEdge = !surf.EdgeColor.is("none");
			}
			if (mfcolor == null && surf.MarkerFaceColor.is("auto"))
			{
				mfcolor = surf.FaceColor.getArray();
				doFace = !surf.FaceColor.is("none");
			}

			if ((mecolor == null || mfcolor == null) && c == null)
				c = surf.getCData();

			md.begin(surf.Marker, surf.MarkerSize, surf.LineWidth.floatValue());
			for (int i=0; i<x.length; i++)
			{
				for (int j=0; j<x[i].length; j++)
				{
					if (clip[i][j])
						continue;

					double[] lc = (doEdge ? (mecolor == null ? c[i][j] : mecolor) : null);
					double[] fc = (doFace ? (mfcolor == null ? c[i][j] : mfcolor) : null);

					md.draw(x[i][j], y[i][j], z[i][j], lc, fc);
				}
			}
			md.end();
		}
	}

	private int nextPowerOf2(int n)
	{
		int m = 1;
		while (m < n)
			m *= 2;
		return m;
	}

	private Buffer makeTexture2D(byte[] data, int _m, int _n, int[] dims)
	{
		int m = nextPowerOf2(_m);
		int n = nextPowerOf2(_n);
		ByteBuffer buf = ByteBuffer.allocate(m*n*4);

		for (int i=0; i<_m; i++)
		{
			buf.position(i*n*4);
			for (int j=0; j<_n; j++)
			{
				buf.put(data[i+j*_m+0*_m*_n]);
				buf.put(data[i+j*_m+1*_m*_n]);
				buf.put(data[i+j*_m+2*_m*_n]);
				buf.put((byte)-127);
			}
		}

		dims[0] = m;
		dims[1] = n;
		buf.rewind();

		return buf;
	}

	private Buffer makeTexture2D(double[] data, int _m, int _n, int[] dims)
	{
		int m = nextPowerOf2(_m);
		int n = nextPowerOf2(_n);
		FloatBuffer buf = FloatBuffer.allocate(m*n*4);

		for (int i=0; i<_m; i++)
		{
			buf.position(i*n*4);
			for (int j=0; j<_n; j++)
			{
				buf.put((float)data[i+j*_m+0*_m*_n]);
				buf.put((float)data[i+j*_m+1*_m*_n]);
				buf.put((float)data[i+j*_m+2*_m*_n]);
				buf.put(1.0f);
			}
		}
		dims[0] = m;
		dims[1] = n;
		buf.rewind();

		return buf;
	}

	public class TextureData implements Renderer.CachedData
	{
		int texID;
		int texW, texH;
		int w, h;
		double tCoordX, tCoordY;
		GLContext context;

		public TextureData(int ID, int texW, int texH, int w, int h)
		{
			this.texID = ID;
			this.texW = texW;
			this.texH = texH;
			this.w = w;
			this.h = h;
			this.context = GLContext.getCurrent();
			this.tCoordX = ((double)w)/texW;
			this.tCoordY = ((double)h)/texH;
		}

		public void dispose()
		{
			boolean isCurrent = (GLContext.getCurrent() == context);

			if (!isCurrent)
				context.makeCurrent();
			context.getGL().glDeleteTextures(1, new int[] {texID}, 0);
			if (!isCurrent)
				context.release();
		}
	}

	public TextureData makeTextureFromCData(ArrayProperty CData, RadioProperty CDataMapping, AxesObject axes)
	{
		Buffer texData = null;
		int[] texDims = new int[2];
		int m = CData.getDim(0), n = CData.getDim(1);
		int format = GL.GL_UNSIGNED_BYTE;

		if (CData.getNDims() == 3)
		{
			if (CData.isType("byte"))
			{
				texData = makeTexture2D(CData.getMatrix().toByte(), m, n, texDims);
				format = GL.GL_UNSIGNED_BYTE;
			}
			else if (CData.isType("double"))
			{
				texData = makeTexture2D(CData.getMatrix().toDouble(), m, n, texDims);
				format = GL.GL_FLOAT;
			}
			else
			{
				System.out.println("Warning: unsupported data type for texture generation `" + CData.getClassName() + "'");
				return null;
			}
		}
		else
		{
			Matrix c = axes.convertCData(CData.getMatrix(), CDataMapping.getValue());
			texData = makeTexture2D(c.toDouble(), m, n, texDims);
			format = GL.GL_FLOAT;
		}

		int[] t = new int[1];
		gl.glGenTextures(1, t, 0);
		gl.glBindTexture(GL.GL_TEXTURE_2D, t[0]);
		gl.glTexImage2D(GL.GL_TEXTURE_2D, 0, 4,
				texDims[1], texDims[0], 0, GL.GL_RGBA, format, texData);
		gl.glTexParameteri(GL.GL_TEXTURE_2D, GL.GL_TEXTURE_MIN_FILTER, GL.GL_NEAREST);
		gl.glTexParameteri(GL.GL_TEXTURE_2D, GL.GL_TEXTURE_MAG_FILTER, GL.GL_NEAREST);
		//gl.glTexParameteri(GL.GL_TEXTURE_2D, GL.GL_TEXTURE_WRAP_S, GL.GL_CLAMP_TO_EDGE);
		//gl.glTexParameteri(GL.GL_TEXTURE_2D, GL.GL_TEXTURE_WRAP_T, GL.GL_CLAMP_TO_EDGE);
		
		return new TextureData(t[0], texDims[1], texDims[0], n, m);
	}

	public void draw(ImageObject image)
	{
		double[] x = image.XData.getArray();
		double[] y = image.YData.getArray();
		TextureData d = (TextureData)image.getCachedData();

		if (d == null)
		{
			d = makeTextureFromCData(image.CData, image.CDataMapping, image.getAxes());
			if (d == null)
				return;
			else
				image.setCachedData(d);
		}
		gl.glBindTexture(GL.GL_TEXTURE_2D, d.texID);

		double tx = d.tCoordX;
		double ty = d.tCoordY;
		double px = (d.w > 1 ? (x[1]-x[0])/(d.w-1) : 1);
		double py = (d.h > 1 ? (y[1]-y[0])/(d.h-1) : 1);
		double x1 = sx.scale(x[0]-px/2), x2 = sx.scale((d.w > 1 ? x[1]+px/2 : x[0]+px/2));
		double y1 = sy.scale(y[0]-py/2), y2 = sy.scale((d.h > 1 ? y[1]+py/2 : y[0]+py/2));

		if (!isNaNorInf(x1, y1, 0) && !isNaNorInf(x2, y2, 0))
		{
			gl.glEnable(GL.GL_TEXTURE_2D);
			gl.glColor3d(1, 1, 1);
			gl.glBegin(GL.GL_QUADS);
			gl.glTexCoord2d(0, 0); gl.glVertex3d(x1, y1, (zmin+zmax)/2);
			gl.glTexCoord2d(tx, 0); gl.glVertex3d(x2, y1, (zmin+zmax)/2);
			gl.glTexCoord2d(tx, ty); gl.glVertex3d(x2, y2, (zmin+zmax)/2);
			gl.glTexCoord2d(0, ty); gl.glVertex3d(x1, y2, (zmin+zmax)/2);
			gl.glEnd();
			gl.glDisable(GL.GL_TEXTURE_2D);
		}
	}

	public void draw(TextObject text)
	{
		text.drawAsImage(this);
		if (isGL2PS)
		{
			double[] pos = text.getAxes().convertUnits(text.Position.getArray(), text.Units.getValue());
			/*
			int halign = (text.HAlign.is("left") ? 0 : (text.HAlign.is("center") ? 1 : 2));
			int valign = (text.VAlign.is("bottom") ? 0 : (text.VAlign.is("top") ? 2 :
						(text.VAlign.is("baseline") ? 3 : 1)));

			setColor(text.TextColor.getColor());
			drawGL2PSText(text.TextString.toString(), pos, halign, valign, text.Rotation.floatValue(),
					text.Margin.floatValue(), false, text.LineWidth.floatValue(), text.EdgeColor.getColor(),
					text.LineStyle.getValue(), text.BackgroundColor.getColor(), text.Units.is("data"));
					*/
			gl.glRasterPos3d(sx.scale(pos[0]), sy.scale(pos[1]), sz.scale(pos[2]));
			if (!text.Units.is("data"))
				gl.glDisable(GL.GL_DEPTH_TEST);
			GL2PS.gl2psSpecial(GL2PS.GL2PS_PS, text.toPostScript(), 1);
			if (!text.Units.is("data"))
				gl.glEnable(GL.GL_DEPTH_TEST);
		}
	}

	public void setXForm(AxesObject ax)
	{
		double zmin = ax.x_zmin, zmax = ax.x_zmax;

		if (isGL2PS)
		{
			if (!isFirst)
				GL2PS.gl2psEndViewport();
			isFirst = false;

			int[] viewport = new int[4];

			gl.glGetIntegerv(GL.GL_VIEWPORT, viewport, 0);
			GL2PS.gl2psBeginViewport(viewport);
		}

		xForm = ax.x_render;
		xZ1 = zmin-(zmax-zmin)/2;
		xZ2 = zmax+(zmax-zmin)/2;

		gl.glMatrixMode(GL.GL_MODELVIEW);
		gl.glLoadIdentity();
		gl.glScaled(1, 1, -1);
		gl.glMultMatrixd(ax.x_mat1.getData(), 0);
		gl.glMatrixMode(GL.GL_PROJECTION);
		gl.glLoadIdentity();
		gl.glOrtho(0, d.getWidth(), d.getHeight(), 0, xZ1, xZ2);
		gl.glMultMatrixd(ax.x_mat2.getData(), 0);
		gl.glMatrixMode(GL.GL_MODELVIEW);

		/* assumption: we start a new axes object, reset depth buffer such
		 * that previous drawing are always overdrawn (to implement layering)
		 */
		gl.glClear(GL.GL_DEPTH_BUFFER_BIT);

		sx = ax.sx;
		sy = ax.sy;
		sz = ax.sz;
	}

	public void setViewport(int width, int height)
	{
		gl.glViewport(0, 0, width, height);
	}

	public void clear(Color c)
	{
		if (isGL2PS)
			isFirst = true;

		gl.glClearColor(c.getRed()/255.0f, c.getGreen()/255.0f, c.getBlue()/255.0f, 1.0f);
		gl.glClear(GL.GL_COLOR_BUFFER_BIT | GL.GL_DEPTH_BUFFER_BIT);
	}

	public void drawRubberBox(int[][] b)
	{
		boolean isCurrent = (d.getContext() == GLContext.getCurrent());

		/* Initialize GL context */
		if (!isCurrent)
			d.getContext().makeCurrent();
		gl.glPushAttrib(GL.GL_COLOR_BUFFER_BIT | GL.GL_DEPTH_BUFFER_BIT);
		if (!isCurrent)
			gl.glDrawBuffer(GL.GL_FRONT);
		gl.glEnable(GL.GL_COLOR_LOGIC_OP);
		gl.glLogicOp(GL.GL_XOR);
		gl.glDisable(GL.GL_DEPTH_TEST);
		gl.glMatrixMode(GL.GL_MODELVIEW);
		gl.glLoadIdentity();
		gl.glMatrixMode(GL.GL_PROJECTION);
		gl.glLoadIdentity();
		gl.glOrtho(0, d.getWidth(), d.getHeight(), 0, 1, -1);
		gl.glColor3d(0.3, 0.3, 0.3);

		/* Draw rubber box */
		for (int i=0; i<b.length; i++)
		{
			gl.glBegin(GL.GL_LINE_LOOP);
			gl.glVertex3d(b[i][0], b[i][1], 0);
			gl.glVertex3d(b[i][2], b[i][1], 0);
			gl.glVertex3d(b[i][2], b[i][3], 0);
			gl.glVertex3d(b[i][0], b[i][3], 0);
			gl.glEnd();
		}

		/* Restore GL context */
		gl.glFlush();
		gl.glPopAttrib();
		if (!isCurrent)
			d.getContext().release();
	}

	public void drawSegments(List pts)
	{
		Iterator it = pts.iterator();
		
		gl.glBegin(GL.GL_LINES);
		while (it.hasNext())
		{
			Point3D p = (Point3D)it.next();
			gl.glVertex3d(p.x, p.y, p.z);
		}
		gl.glEnd();
	}

	public void setColor(Color c)
	{
		gl.glColor3d(c.getRed()/255.0, c.getGreen()/255.0, c.getBlue()/255.0);
	}

	public void setLineStyle(String ls, boolean forceStippling)
	{
		boolean solid = false;

		if (ls.equals(":"))
			gl.glLineStipple(1, (short)0x8888);
		else if (ls.equals("-"))
		{
			gl.glLineStipple(1, (short)0xFFFF);
			solid = true;
		}
		else if (ls.equals("--"))
			gl.glLineStipple(1, (short)0x0FFF);
		else if (ls.equals("-."))
			gl.glLineStipple(1, (short)0x020F);
		else
			gl.glLineStipple(1, (short)0x0000);

		if (solid && !forceStippling)
		{
			gl.glDisable(GL.GL_LINE_STIPPLE);
			if (isGL2PS)
				GL2PS.gl2psDisable(GL2PS.GL2PS_LINE_STIPPLE);
		}
		else
		{
			gl.glEnable(GL.GL_LINE_STIPPLE);
			if (isGL2PS)
				GL2PS.gl2psEnable(GL2PS.GL2PS_LINE_STIPPLE);
		}
	}

	public void setLineWidth(float w)
	{
		gl.glLineWidth(w);
		if (isGL2PS)
			GL2PS.gl2psLineWidth(w);
	}

	public void setFont(Font f)
	{
		font = f;
	}

	private void setPolygonOffset(boolean flag)
	{
		if (flag)
		{
			gl.glEnable(GL.GL_POLYGON_OFFSET_FILL);
			if (isGL2PS)
				GL2PS.gl2psEnable(GL2PS.GL2PS_POLYGON_OFFSET_FILL);
		}
		else
		{
			gl.glDisable(GL.GL_POLYGON_OFFSET_FILL);
			if (isGL2PS)
				GL2PS.gl2psDisable(GL2PS.GL2PS_POLYGON_OFFSET_FILL);
		}
	}

	public void drawQuads(List pts, double zoffset)
	{
		Iterator it = pts.iterator();

		if (zoffset > 0)
		{
			gl.glPolygonOffset((float)zoffset, (float)zoffset);
			setPolygonOffset(true);
		}

		gl.glBegin(GL.GL_QUADS);
		while (it.hasNext())
		{
			Point3D p = (Point3D)it.next();
			gl.glVertex3d(p.x, p.y, p.z);
		}
		gl.glEnd();

		if (zoffset > 0)
			setPolygonOffset(false);
	}
}
