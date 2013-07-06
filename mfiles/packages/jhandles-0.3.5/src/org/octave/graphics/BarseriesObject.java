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

import java.util.*;
import java.awt.*;
import org.octave.Matrix;

public class BarseriesObject extends GroupObject
{
	/* Properties */
	DoubleProperty BarWidth;
	RadioProperty BarLayout;
	VectorProperty XData;
	VectorProperty YData;
	DoubleProperty BaseValue;
	HandleObjectListProperty BaseLine;
	ColorProperty EdgeColor;
	ColorProperty FaceColor;
	HandleObjectListProperty BarGroup;
	BooleanProperty Horizontal;

	public BarseriesObject(HandleObject parent, double[] x, double[] y)
	{
		this(parent, x, y, false);
	}

	public BarseriesObject(HandleObject parent, double[] x, double[] y, boolean horizontal)
	{
		super(parent);

		PatchObject patch = new PatchObject(this);
		BaseLineObject base = getAxes().getBaseLine();
		try { base.Orientation.set(horizontal ? "Y" : "X"); }
		catch (PropertyException e) {}

		BarWidth = new DoubleProperty(this, "BarWidth", 0.8);
		BarLayout = new RadioProperty(this, "BarLayout", new String[] {"grouped", "stacked"}, "grouped");
		XData = new VectorProperty(this, "XData", -1, x);
		YData = new VectorProperty(this, "YData", -1, y);
		BaseLine = new HandleObjectListProperty(this, "BaseLine", -1);
		BaseLine.addElement(base);
		BaseValue = new DoubleProperty(this, "BaseValue", base.BaseValue.doubleValue());
		EdgeColor = new ColorProperty(this, "EdgeColor", new String[] {"none"}, Color.black);
		FaceColor = new ColorProperty(this, "FaceColor", new String[] {"none", "flat"}, "flat");
		BarGroup = new HandleObjectListProperty(this, "BarGroup", -1);
		Horizontal = new BooleanProperty(this, "Horizontal", horizontal);

		RadioProperty mapping = new RadioProperty(this, "CDataMapping", new String[] {"direct", "scaled"}, "scaled");

		BarGroup.setVisible(false);
		mapping.setVisible(false);
		Horizontal.setVisible(false);
		
		patch.EdgeColor.reset(EdgeColor.get());
		patch.FaceColor.reset(FaceColor.get());

		CLimInclude.reset(new Boolean(true));

		listen(BaseValue);
		listen(base.BaseValue);
		listen(BarWidth);
		listen(BarLayout);
		listen(EdgeColor);
		listen(FaceColor);
		listen(Horizontal);
	}

	public void validate()
	{
		super.validate();
		doLayout(false);
	}

	public void delete()
	{
		BarGroup.removeElement(this);
		Iterator it = BarGroup.iterator();
		while (it.hasNext())
			((BarseriesObject)it.next()).BarGroup.removeElement(this);
		if (BarGroup.size() > 0)
			updateBars();
		super.delete();
	}

	private PatchObject getPatch()
	{
		return (PatchObject)Children.elementAt(0);
	}

	public void updateBars()
	{
		doLayout(false);
	}

	private void doLayout(boolean doValidate)
	{
		if (BarGroup.size() == 0)
			return;

		double B = BaseValue.doubleValue();
		int n = BarGroup.size();
		double[] x = XData.getArray();
		double w = (x.length > 1 ? Double.POSITIVE_INFINITY : 1);
		boolean horizontal = Horizontal.isSet();
		
		for (int i=1; i<x.length; i++)
			w = Math.min(w, x[i]-x[i-1]);

		if (BarLayout.is("stacked"))
		{
			double bw = w*BarWidth.doubleValue();
			double[] bv = new double[x.length];

			Arrays.fill(bv, B);
			for (int i=0; i<n; i++)
			{
				BarseriesObject bar = (BarseriesObject)BarGroup.elementAt(i);
				PatchObject patch = bar.getPatch();

				double[][] v = new double[x.length*4][];
				double[][] f = new double[x.length][];
				double[] y = bar.YData.getArray();
				double[] fvc = new double[x.length*4];

				for (int k=0; k<x.length; k++)
				{
					f[k] = new double[] {4*k+1, 4*k+2, 4*k+3, 4*k+4};
					if (horizontal)
					{
						v[4*k]   = new double[] {bv[k], x[k]-bw/2, 0};
						v[4*k+1] = new double[] {bv[k], x[k]+bw/2, 0};
						v[4*k+2] = new double[] {bv[k]+y[k], x[k]+bw/2, 0};
						v[4*k+3] = new double[] {bv[k]+y[k], x[k]-bw/2, 0};
					}
					else
					{
						v[4*k]   = new double[] {x[k]-bw/2, bv[k], 0};
						v[4*k+1] = new double[] {x[k]+bw/2, bv[k], 0};
						v[4*k+2] = new double[] {x[k]+bw/2, bv[k]+y[k], 0};
						v[4*k+3] = new double[] {x[k]-bw/2, bv[k]+y[k], 0};
					}
					fvc[4*k]   = i+1;
					fvc[4*k+1] = i+1;
					fvc[4*k+2] = i+1;
					fvc[4*k+3] = i+1;
					bv[k] += y[k];
				}

				patch.Vertices.set(null, true); /* just in case, to avoid computing normals in PatchObject */
				patch.Faces.set(new Matrix(f), true);
				patch.Vertices.set(new Matrix(v), true);
				patch.FaceVertexCData.set(new Matrix(fvc, new int[] {fvc.length, 1}), true);
				/* TODO: needed?
				if (doValidate)
					patch.validate();
				*/
				bar.XLim.set(patch.XLim.get(), true);
				bar.YLim.set(patch.YLim.get(), true);
				bar.ZLim.set(patch.ZLim.get(), true);
				bar.CLim.set(patch.CLim.get(), true);
			}
		}
		else if (BarLayout.is("grouped"))
		{
			double gw, bw;

			if (n == 1)
				gw = bw = w*BarWidth.doubleValue();
			else
			{
				gw = 0.8*w;
				bw = (gw/n)*BarWidth.doubleValue();
			}

			for (int i=0; i<n; i++)
			{
				BarseriesObject bar = (BarseriesObject)BarGroup.elementAt(i);
				PatchObject patch = bar.getPatch();
				double bo = (n == 1 ? 0 : -gw/2+(gw/n)*(i+0.5));

				double[][] v = new double[x.length*4][];
				double[][] f = new double[x.length][];
				double[] y = bar.YData.getArray();
				double[] fvc = new double[x.length*4];

				for (int k=0; k<x.length; k++)
				{
					f[k] = new double[] {4*k+1, 4*k+2, 4*k+3, 4*k+4};
					if (horizontal)
					{
						v[4*k]   = new double[] {B, x[k]+bo-bw/2, 0};
						v[4*k+1] = new double[] {B, x[k]+bo+bw/2, 0};
						v[4*k+2] = new double[] {y[k], x[k]+bo+bw/2, 0};
						v[4*k+3] = new double[] {y[k], x[k]+bo-bw/2, 0};
					}
					else
					{
						v[4*k]   = new double[] {x[k]+bo-bw/2, B, 0};
						v[4*k+1] = new double[] {x[k]+bo+bw/2, B, 0};
						v[4*k+2] = new double[] {x[k]+bo+bw/2, y[k], 0};
						v[4*k+3] = new double[] {x[k]+bo-bw/2, y[k], 0};
					}
					fvc[4*k]   = i+1;
					fvc[4*k+1] = i+1;
					fvc[4*k+2] = i+1;
					fvc[4*k+3] = i+1;
				}

				patch.Vertices.set(null, true); /* just in case, to avoid computing normals in PatchObject */
				patch.Faces.set(new Matrix(f), true);
				patch.Vertices.set(new Matrix(v), true);
				patch.FaceVertexCData.set(new Matrix(fvc, new int[] {fvc.length, 1}), true);
				/* TODO: needed?
				if (doValidate)
					patch.validate();
				*/
				bar.XLim.set(patch.XLim.get(), true);
				bar.YLim.set(patch.YLim.get(), true);
				bar.ZLim.set(patch.ZLim.get(), true);
				bar.CLim.set(patch.CLim.get(), true);
			}
		}
	}

	private BaseLineObject getBaseLine()
	{
		return (BaseLineObject)BaseLine.elementAt(0);
	}

	public void propertyChanged(Property p) throws PropertyException
	{
		super.propertyChanged(p);

		if (p == BaseValue)
			getBaseLine().BaseValue.set(p.get());
		else if (p.getName().equals("BaseValue"))
		{
			Iterator it = BarGroup.iterator();
			while (it.hasNext())
				((BarseriesObject)it.next()).BaseValue.reset(p.get());
			updateBars();
		}
		else if (p == BarWidth)
		{
			Iterator it = BarGroup.iterator();
			while (it.hasNext())
				((BarseriesObject)it.next()).BarWidth.reset(p.get());
			updateBars();
		}
		else if (p == BarLayout)
		{
			Iterator it = BarGroup.iterator();
			while (it.hasNext())
				((BarseriesObject)it.next()).BarLayout.reset(p.get());
			updateBars();
		}
		else if (p == Horizontal)
		{
			Iterator it = BarGroup.iterator();
			while (it.hasNext())
				((BarseriesObject)it.next()).Horizontal.reset(p.get());
			updateBars();
			getBaseLine().Orientation.set(Horizontal.isSet() ? "Y" : "X");
		}
		else if (p == EdgeColor)
			getPatch().EdgeColor.reset(p.get());
		else if (p == FaceColor)
			getPatch().FaceColor.reset(p.get());
	}
}
