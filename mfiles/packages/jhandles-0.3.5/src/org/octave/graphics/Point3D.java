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

public class Point3D
{
	public double x, y, z;

	public Point3D(double x, double y, double z)
	{
		this.x = x;
		this.y = y;
		this.z = z;
	}

	public Point3D(double[] pt)
	{
		this(pt[0], pt[1], pt[2]);
	}

	public void add(Point3D pt)
	{
		x += pt.x;
		y += pt.y;
		z += pt.z;
	}

	public void add(double[] p)
	{
		x += p[0];
		y += p[1];
		if (p.length > 2)
			z += p[2];
	}

	public void add(double _x, double _y, double _z)
	{
		x += _x;
		y += _y;
		z += _z;
	}

	public void sub(Point3D p)
	{
		x -= p.x;
		y -= p.y;
		z -= p.z;
	}

	public void sub(double[] p)
	{
		x -= p[0];
		y -= p[1];
		if (p.length > 2)
			z -= p[2];
	}

	public double norm()
	{
		return Math.sqrt(x*x+y*y+z*z);
	}

	public double dot(Point3D p)
	{
		return (x*p.x+y*p.y+z*p.z);
	}

	public double dot(double[] p)
	{
		return (x*p[0]+y*p[1]+(p.length > 2 ? z*p[2] : 0));
	}

	public void scale(double s)
	{
		x /= s;
		y /= s;
		z /= s;
	}

	public void normalize()
	{
		scale(1/norm());
	}
}
