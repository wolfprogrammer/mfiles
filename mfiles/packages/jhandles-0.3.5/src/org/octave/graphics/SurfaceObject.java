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
import org.octave.Matrix;

public class SurfaceObject extends GraphicObject
{
	private boolean callListValid;

	/* Properties */
	ArrayProperty XData;
	ArrayProperty YData;
	ArrayProperty ZData;
	ArrayProperty CData;
	RadioProperty CDataMapping;
	ColorProperty EdgeColor;
	ColorProperty FaceColor;
	DoubleProperty AmbientStrength;
	DoubleProperty DiffuseStrength;
	DoubleProperty SpecularStrength;
	DoubleProperty SpecularExponent;
	RadioProperty EdgeLighting;
	RadioProperty FaceLighting;
	DoubleRadioProperty FaceAlpha;
	DoubleRadioProperty EdgeAlpha;
	ArrayProperty VertexNormals;
	ArrayProperty AlphaData;
	RadioProperty AlphaDataMapping;
	MarkerProperty Marker;
	ColorProperty MarkerEdgeColor;
	ColorProperty MarkerFaceColor;
	DoubleProperty MarkerSize;
	LineStyleProperty LineStyle;
	DoubleProperty LineWidth;

	public SurfaceObject(HandleObject parent, Matrix xdata, Matrix ydata, Matrix zdata)
	{
		super(parent, "surface");
		callListValid = false;

		XData = new ArrayProperty(this, "XData", new String[] {"double"}, 2, xdata);
		YData = new ArrayProperty(this, "YData", new String[] {"double"}, 2, ydata);
		ZData = new ArrayProperty(this, "ZData", new String[] {"double"}, 2, zdata);
		CData = new ArrayProperty(this, "CData", new String[] {"double", "byte"}, -1, zdata);
		CDataMapping = new RadioProperty(this, "CDataMapping", new String[] {"direct", "scaled"}, "scaled");
		EdgeColor = new ColorProperty(this, "EdgeColor", new String[] {"none", "flat", "interp"}, Color.black);
		FaceColor = new ColorProperty(this, "FaceColor", new String[] {"none", "flat", "interp", "texturemap"}, "flat");
		AmbientStrength = new DoubleProperty(this, "AmbientStrength", 0.3);
		DiffuseStrength = new DoubleProperty(this, "DiffuseStrength", 0.6);
		SpecularStrength = new DoubleProperty(this, "SpecularStrength", 0.9);
		SpecularExponent = new DoubleProperty(this, "SpecularExponent", 10);
		EdgeLighting = new RadioProperty(this, "EdgeLighting", new String[] {"none", "flat", "gouraud", "phong"}, "none");
		FaceLighting = new RadioProperty(this, "FaceLighting", new String[] {"none", "flat", "gouraud", "phong"}, "none");
		FaceAlpha = new DoubleRadioProperty(this, "FaceAlpha", new String[] {"flat", "interp"}, 1.0);
		EdgeAlpha = new DoubleRadioProperty(this, "EdgeAlpha", new String[] {"flat", "interp"}, 1.0);
		VertexNormals = new ArrayProperty(this, "VertexNormals", new String[] {"double"}, 3, null);
		AlphaData = new ArrayProperty(this, "AlphaData", new String[] {"double", "byte"}, 2, null);
		AlphaDataMapping = new RadioProperty(this, "AlphaDataMapping", new String[] {"none", "scaled", "direct"}, "scaled");
		Marker = new MarkerProperty(this, "Marker", "none");
		MarkerSize = new DoubleProperty(this, "MarkerSize", 7.0);
		MarkerEdgeColor = new ColorProperty(this, "MarkerEdgeColor", new String[] {"none", "auto", "flat"}, "auto");
		MarkerFaceColor = new ColorProperty(this, "MarkerFaceColor", new String[] {"none", "auto", "flat"}, "none");
		LineStyle = new LineStyleProperty(this, "LineStyle", "-");
		LineWidth = new DoubleProperty(this, "LineWidth", 0.5);

		ZLimInclude.reset(new Boolean(true));
		CLimInclude.reset(new Boolean(true));
		ALimInclude.reset(new Boolean(true));

		listen(XData);
		listen(YData);
		listen(ZData);
		listen(CData);
		listen(getAxes().getFigure().Colormap);
	}

	public void validate()
	{
		updateMinMax();
		updateColorMinMax();
		VertexNormals.reset(computeNormals());
		super.validate();
	}

	private void updateMinMax()
	{
		double xmin, xmax, ymin, ymax, zmin, zmax;
		double xmin2, xmax2, ymin2, ymax2, zmin2, zmax2;

		double[][] x = XData.asDoubleMatrix();
		double[][] y = YData.asDoubleMatrix();
		double[][] z = ZData.asDoubleMatrix();

		int m = Math.min(Math.min(x.length, y.length), z.length);
		int n = (m > 0 ? Math.min(Math.min(x[0].length, y[0].length), z[0].length) : 0);

		xmin = ymin = zmin = Double.POSITIVE_INFINITY;
		xmax = ymax = zmax = Double.NEGATIVE_INFINITY;
		xmin2 = ymin2 = zmin2 = Double.POSITIVE_INFINITY;
		xmax2 = ymax2 = zmax2 = Double.MIN_VALUE;

		for (int i=0; i<m; i++)
			for (int j=0; j<n; j++)
			{
				if (x[i][j] < xmin) xmin = x[i][j];
				if (x[i][j] > xmax) xmax = x[i][j];
				if (x[i][j] > 0)
				{
					if (x[i][j] < xmin2) xmin2 = x[i][j];
					if (x[i][j] > xmax2) xmax2 = x[i][j];
				}
				if (y[i][j] < ymin) ymin = y[i][j];
				if (y[i][j] > ymax) ymax = y[i][j];
				if (y[i][j] > 0)
				{
					if (y[i][j] < ymin2) ymin2 = y[i][j];
					if (y[i][j] > ymax2) ymax2 = y[i][j];
				}
				if (z[i][j] < zmin) zmin = z[i][j];
				if (z[i][j] > zmax) zmax = z[i][j];
				if (z[i][j] > 0)
				{
					if (z[i][j] < zmin2) zmin2 = z[i][j];
					if (z[i][j] > zmax2) zmax2 = z[i][j];
				}
			}

		XLim.set(new double[] {xmin, xmax, xmin2, xmax2}, true);
		YLim.set(new double[] {ymin, ymax, ymin2, ymax2}, true);
		ZLim.set(new double[] {zmin, zmax, zmin2, zmax2}, true);
	}

	private void updateColorMinMax()
	{
		Matrix m = CData.getMatrix();
		CLim.set(new double[] {m.minValue(), m.maxValue()}, true);
	}

	Matrix computeNormals()
	{
		double[][] x = XData.asDoubleMatrix();
		double[][] y = YData.asDoubleMatrix();
		double[][] z = ZData.asDoubleMatrix();
		int p = z.length;
		int q = (z.length > 0 ? z[0].length : 0);
		double[][][] n = new double[p][q][3];

		// TODO: normal computation at boundaries
		for (int i=1; i<p-1; i++)
		{
			for (int j=1; j<q-1; j++)
			{
				n[i][j][0] = n[i][j][1] = n[i][j][2] = 0;
				Utils.crossProduct(
					x[i][j+1]-x[i][j], y[i][j+1]-y[i][j], z[i][j+1]-z[i][j],
					x[i+1][j]-x[i][j], y[i+1][j]-y[i][j], z[i+1][j]-z[i][j],
					n[i][j]);
				Utils.crossProduct(
					x[i-1][j]-x[i][j], y[i-1][j]-y[i][j], z[i-1][j]-z[i][j],
					x[i][j+1]-x[i][j], y[i][j+1]-y[i][j], z[i][j+1]-z[i][j],
					n[i][j]);
				Utils.crossProduct(
					x[i][j-1]-x[i][j], y[i][j-1]-y[i][j], z[i][j-1]-z[i][j],
					x[i-1][j]-x[i][j], y[i-1][j]-y[i][j], z[i-1][j]-z[i][j],
					n[i][j]);
				Utils.crossProduct(
					x[i+1][j]-x[i][j], y[i+1][j]-y[i][j], z[i+1][j]-z[i][j],
					x[i][j-1]-x[i][j], y[i][j-1]-y[i][j], z[i][j-1]-z[i][j],
					n[i][j]);
				n[i][j][0] /= 4;
				n[i][j][1] /= 4;
				n[i][j][2] /= 4;

				double d = Math.sqrt(n[i][j][0]*n[i][j][0]+n[i][j][1]*n[i][j][1]+n[i][j][2]*n[i][j][2]);

				n[i][j][0] /= d;
				n[i][j][1] /= d;
				n[i][j][2] /= d;
			}
		}

		return new Matrix(n);
	}

	double[][][] getCData()
	{
		if (CData.getNDims() == 2)
			return getAxes().convertCData(CData.asDoubleMatrix(), CDataMapping.getValue());
		else
			return CData.asDoubleMatrix3();
	}

	double[][] getAlphaData()
	{
		if (AlphaData.getNDims() != 2)
			return null;

		if (AlphaData.getClassName().equals("double"))
		{
			double[][] aa = AlphaData.asDoubleMatrix();

			if (AlphaDataMapping.is("none"))
				return aa;
			else if (AlphaDataMapping.is("scaled"))
			{
				double[][] res = new double[aa.length][aa[0].length];
				double[] amap = getAxes().getFigure().Alphamap.getArray();
				double[] alim = getAxes().ALim.getArray();

				for (int i=0; i<res.length; i++)
					for (int j=0; j<res[i].length; j++)
					{
						int s = (int)Math.round((amap.length-1)*(aa[i][j]-alim[0])/(alim[1]-alim[0]));
						s = Math.min(Math.max(0, s), amap.length-1);
						res[i][j] = amap[s];
					}
				return res;
			}
			else if (AlphaDataMapping.is("direct"))
			{
				double[][] res = new double[aa.length][aa[0].length];
				double[] amap = getAxes().getFigure().Alphamap.getArray();
				
				for (int i=0; i<res.length; i++)
					for (int j=0; j<res[i].length; j++)
					{
						int s = (int)Math.round(aa[i][j])-1;
						s = Math.min(Math.max(0, s), amap.length-1);
						res[i][j] = amap[s];
					}
				return res;
			}
		}

		return null;
	}

	public void draw(Renderer r)
	{
		r.draw(this);
	}

	public void propertyChanged(Property p) throws PropertyException
	{
		super.propertyChanged(p);

		if (p == XData || p == YData || p == ZData)
		{
			VertexNormals.reset(null);
			updateMinMax();
		}
		else if (p == CData)
			updateColorMinMax();
		else if (p.getName().equalsIgnoreCase("colormap"))
			setCachedData(null);
	}
}
