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

public class Vector3D
{
	private double[] v;

	public Vector3D()
	{
		v = new double[] {0, 0, 0};
	}

	public Vector3D(double[] v)
	{
		this(v, true);
	}

	public Vector3D(double[] v, boolean copy)
	{
		if (copy)
			this.v = (double[])v.clone();
		else
			this.v = v;
	}

	public Vector3D(Vector3D V)
	{
		this(V.v, true);
	}

	public void scale(double x, double y, double z)
	{
		v[0] *= x;
		v[1] *= y;
		v[2] *= z;
	}

	public void transform(Matrix3D m)
	{
		double[] dm = m.getData();
		double[] vv = new double[3];
		for (int i=0; i<3; i++)
			vv[i] = dm[i+0]*v[0]+dm[i+4]*v[1]+dm[i+8]*v[2]+dm[i+12]*1;
		v = vv;
	}

	public double get(int idx)
	{
		return v[idx];
	}

	public double[] getData()
	{
		return v;
	}

	public void normalize()
	{
		double f = 1/Math.sqrt(v[0]*v[0]+v[1]*v[1]+v[2]*v[2]);
		scale(f, f, f);
	}

	public void sub(Vector3D V)
	{
		for (int i=0; i<3; i++)
				v[i] -= V.v[i];
	}

	public void add(Vector3D V)
	{
		for (int i=0; i<3; i++)
				v[i] += V.v[i];
	}

	public double norm()
	{
		return Math.sqrt(dot(this, this));
	}

	public static double dot(Vector3D v1, Vector3D v2)
	{
		return (v1.v[0]*v2.v[0]+v1.v[1]*v2.v[1]+v1.v[2]*v2.v[2]);
	}

	public static Vector3D cross(Vector3D v1, Vector3D v2)
	{
		return new Vector3D(
			new double[] {
				v1.v[1]*v2.v[2]-v1.v[2]*v2.v[1],
			   	v1.v[2]*v2.v[0]-v1.v[0]*v2.v[2],
			   	v1.v[0]*v2.v[1]-v1.v[1]*v2.v[0]
			},
			false);
	}

	public static Vector3D normalize(Vector3D V)
	{
		Vector3D newV = new Vector3D(V);
		newV.normalize();
		return newV;
	}

	public void print(String name)
	{
		System.out.println(name);
		for (int i=0; i<3; i++)
			System.out.print(v[i] + " ");
		System.out.println("");
	}
}
