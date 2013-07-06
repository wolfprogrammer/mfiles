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
import javax.media.opengl.*;

public class GL2PS
{
	static
	{
		System.load(System.getProperty("octave.jhandles.path") + java.io.File.separator +
			System.mapLibraryName("gl2ps_java"));
	}

	final static int GL2PS_MAJOR_VERSION = 1;
	final static int GL2PS_MINOR_VERSION = 3;
	final static int GL2PS_PATCH_VERSION = 2;
	final static String GL2PS_EXTRA_VERSION = "";
	final static double GL2PS_VERSION =
		(GL2PS_MAJOR_VERSION +
		 0.01 * GL2PS_MINOR_VERSION +
		 0.0001 * GL2PS_PATCH_VERSION);
	final static String GL2PS_COPYRIGHT = "(C) 1999-2006 Christophe Geuzaine (geuz@geuz.org)";
	final static int GL2PS_PS = 0;
	final static int GL2PS_EPS = 1;
	final static int GL2PS_TEX = 2;
	final static int GL2PS_PDF = 3;
	final static int GL2PS_SVG = 4;
	final static int GL2PS_PGF = 5;
	final static int GL2PS_NO_SORT = 1;
	final static int GL2PS_SIMPLE_SORT = 2;
	final static int GL2PS_BSP_SORT = 3;
	final static int GL2PS_SUCCESS = 0;
	final static int GL2PS_INFO = 1;
	final static int GL2PS_WARNING = 2;
	final static int GL2PS_ERROR = 3;
	final static int GL2PS_NO_FEEDBACK = 4;
	final static int GL2PS_OVERFLOW = 5;
	final static int GL2PS_UNINITIALIZED = 6;
	final static int GL2PS_NONE = 0;
	final static int GL2PS_DRAW_BACKGROUND = (1<<0);
	final static int GL2PS_SIMPLE_LINE_OFFSET = (1<<1);
	final static int GL2PS_SILENT = (1<<2);
	final static int GL2PS_BEST_ROOT = (1<<3);
	final static int GL2PS_OCCLUSION_CULL = (1<<4);
	final static int GL2PS_NO_TEXT = (1<<5);
	final static int GL2PS_LANDSCAPE = (1<<6);
	final static int GL2PS_NO_PS3_SHADING = (1<<7);
	final static int GL2PS_NO_PIXMAP = (1<<8);
	final static int GL2PS_USE_CURRENT_VIEWPORT = (1<<9);
	final static int GL2PS_COMPRESS = (1<<10);
	final static int GL2PS_NO_BLENDING = (1<<11);
	final static int GL2PS_TIGHT_BOUNDING_BOX = (1<<12);
	final static int GL2PS_POLYGON_OFFSET_FILL = 1;
	final static int GL2PS_POLYGON_BOUNDARY = 2;
	final static int GL2PS_LINE_STIPPLE = 3;
	final static int GL2PS_BLEND = 4;
	final static int GL2PS_TEXT_C = 1;
	final static int GL2PS_TEXT_CL = 2;
	final static int GL2PS_TEXT_CR = 3;
	final static int GL2PS_TEXT_B = 4;
	final static int GL2PS_TEXT_BL = 5;
	final static int GL2PS_TEXT_BR = 6;
	final static int GL2PS_TEXT_T = 7;
	final static int GL2PS_TEXT_TL = 8;
	final static int GL2PS_TEXT_TR = 9;
	final static int GL2PS_TEXT_L = 10;
	final static int GL2PS_TEXT_LL = 11;
	final static int GL2PS_TEXT_LR = 12;

	public static native int gl2psBeginPage(
		String title, String producer,
		int[] viewport,
		int format, int sort, int options,
		int colormode, int colorsize,
		Object[] colortable,
		int nr, int ng, int nb,
		int buffersize, String outputname,
		String filename);
	public static native int gl2psEndPage();
	public static native int gl2psText(String string, String fontname, int fontsize);
	public static native int gl2psTextOpt(String string, String fontname,
		int fontsize, int align, float angle, float margin,
		boolean offsetmargin, float linewidth, float[] linecolor,
		short linepattern, int linefactor, float[] fillcolor);
	public static native int gl2psEnable(int mode);
	public static native int gl2psDisable(int mode);
	public static native int gl2psBeginViewport(int[] viewport);
	public static native int gl2psEndViewport();
	public static native int gl2psLineWidth(float w);
	public static native int gl2psSpecial(int format, String str, int moveTo);

	public static GLRenderer.MarkerDrawer getMarkerDrawer(GL gl)
	{
		return new GL2PSMarkerDrawer(gl);
	}

	private static class GL2PSMarkerDrawer implements GLRenderer.MarkerDrawer
	{
		String mFormat;
		boolean dotStyle;
		boolean canFill;
		GL gl;

		public GL2PSMarkerDrawer(GL gl)
		{
			this.gl = gl;
			this.dotStyle = false;
		}
		
		public void begin(MarkerProperty m, DoubleProperty ms, float lw)
		{
			mFormat = makeMarkerPSString(m, ms, lw);
			dotStyle = m.is(".");
			canFill = (m.is("s") || m.is("o") || m.is("<") || m.is(">") || m.is("v") || m.is("^") ||
				   m.is("p") || m.is("h") || m.is("d"));
		}
		
		public void end()
		{
		}
		
		public void draw(double x, double y, double z, double[] lc, double[] fc)
		{
			String str = ("gsave\n" + mFormat);

			if (dotStyle)
			{
				fc = lc;
				lc = null;
			}
			else if (!canFill)
				fc = null;

			if (fc != null)
				str += (fc[0] + " " + fc[1] + " " + fc[2] + " C gsave fill grestore\n");
			if (lc != null)
				str += (lc[0] + " " + lc[1] + " " + lc[2] + " C stroke\n");
			str += "grestore\n";

			gl.glRasterPos3d(x, y, z);
			gl2psSpecial(GL2PS_PS, str, 1);
		}
	}
	
	public static String makeMarkerPSString(MarkerProperty p, DoubleProperty s, float lw)
	{
		String str;
		double sz2 = s.doubleValue()/2, sz = s.doubleValue();

		str = (lw + " W [] 0 setdash\n");
		switch (p.getValue().charAt(0))
		{
			case 's':
				str += ((-sz2) + " " + (-sz2) + " rmoveto SP newpath RP\n");
				str += ((-sz) + " 0 0 " + sz + " " + sz + " 0 3 {rlineto} repeat closepath\n");
				break;
			case 'o':
				str += ("currentpoint newpath " + sz2 + " 0 360 arc\n");
				break;
			case 'x':
				str += ((-sz2) + " " + (-sz2) + " rmoveto SP newpath RP\n");
				str += (sz + " " + sz + " rlineto\n0 " + (-sz) + " rmoveto " + (-sz) + " " + sz + " rlineto\n");
				break;
			case '+':
				str += ((-sz2) + " 0 rmoveto SP newpath RP\n");
				str += (sz + " 0 rlineto " + (-sz2) + " " + (-sz2) + " rmoveto\n");
				str += ("0 " + sz + " rlineto\n");
				break;
			case '<':
				str += ((-2*sz/3) + " 0 rmoveto SP newpath RP\n");
				str += (sz + " " + sz2 + " rlineto 0 " + (-sz) + " rlineto closepath\n");
				break;
			case '>':
				str += ((2*sz/3) + " 0 rmoveto SP newpath RP\n");
				str += ((-sz) + " " + sz2 + " rlineto 0 " + (-sz) + " rlineto closepath\n");
				break;
			case '^':
				str += ("0 " + (2*sz/3) + " rmoveto SP newpath RP\n");
				str += ((-sz2) + " " + (-sz) + " rlineto " + sz + " 0 rlineto closepath\n");
				break;
			case 'v':
				str += ("0 " + (-2*sz/3) + " rmoveto SP newpath RP\n");
				str += ((-sz2) + " " + sz + " rlineto " + sz + " 0 rlineto closepath\n");
				break;
			case 'd':
				str += ((-sz2) + " 0 rmoveto SP newpath RP\n");
				str += ((-sz2) + " " + (-sz2) + " "+  sz2 + " " + (-sz2) + " " + sz2 + " " + sz2 + " 3 {rlineto} repeat closepath\n");
				break;
			case '*':
				str += ("0 " + (-sz2) + " rmoveto SP newpath RP\n");
				str += ("0 " + sz + " rlineto\n");
				str += ((-sz2) + " " + (-sz2) + " rmoveto " + sz + " 0 rlineto\n");
				str += ((-sz/6) + " " + (-sz/3) + " rmoveto " + (-2*sz/3) + " " + (2*sz/3) + " rlineto\n");
				str += ((2*sz/3) + " 0 rmoveto " + (-2*sz/3) + " " + (-2*sz/3) + " rlineto\n");
				break;
			case '.':
				str += ("currentpoint newpath 1 0 360 arc\n");
				break;
			case 'p':
				double[][] pts = Utils.getPentagramPoints();
				double pr = (sz/2+1), px = pr*pts[0][0], py = pr*pts[0][1];
				str += (px + " " + py + " rmoveto SP newpath RP\n");
				for (int i=1; i<pts.length; i++)
				{
					double x1 = pr*pts[i][0], y1 = pr*pts[i][1];
					str += ((x1-px) + " " + (y1-py) + " rlineto\n");
					px = x1;
					py = y1;
				}
				str += "closepath\n";
				break;
			case 'h':
				double[][] hpts = Utils.getHexagramPoints();
				double hr = (sz/2+1), hx = hr*hpts[0][0], hy = hr*hpts[0][1];
				str += (hx + " " + hy + " rmoveto SP newpath RP\n");
				for (int i=1; i<hpts.length; i++)
				{
					double x1 = hr*hpts[i][0], y1 = hr*hpts[i][1];
					str += ((x1-hx) + " " + (y1-hy) + " rlineto\n");
					hx = x1;
					hy = y1;
				}
				str += "closepath\n";
				break;
		}

		return str;
	}	
}
