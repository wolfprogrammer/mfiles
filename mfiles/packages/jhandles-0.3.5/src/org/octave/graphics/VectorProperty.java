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

import org.octave.Matrix;

public class VectorProperty extends Property
{
	int fixedSize;

	protected VectorProperty(VectorProperty p)
	{
		super(p);
		this.fixedSize = p.fixedSize;
	}

	public VectorProperty(PropertySet parent, String name, int size)
	{
		super(parent, name);
		this.fixedSize = size;
	}

	public VectorProperty(PropertySet parent, String name, int size, double[] data)
	{
		this(parent, name, size, new Matrix(data));
	}

	public VectorProperty(PropertySet parent, String name, int size, Matrix data)
	{
		this(parent, name, size);
		if (data.isVector())
			this.pvalue = data;
		else
		{
			System.out.println("Warning: " + name + ": assigning non-vector to vector property");
			this.pvalue = new Matrix(new double[0]);
		}
	}

	public Property cloneProperty()
	{
		return new VectorProperty(this);
	}

	protected Object convertValue(Object value) throws PropertyException
	{
		if (value instanceof Number)
			return new Matrix(new double[] {((Number)value).doubleValue()}, new int[] {1, 1});
		else if (value instanceof Matrix)
		{
			Matrix m = (Matrix)value;
			if (m.getClassName().equals("double"))
			{
				if (m.getNDims() == 1 ||
				    (m.getNDims() == 2 && (m.getDim(0) == 1 || m.getDim(1) == 1)))
				{
					if (fixedSize == -1 || fixedSize == m.toDouble().length)
						return m;
					else
						throw new PropertyException("invalid vector length - " + value.toString());
				}
				else
					throw new PropertyException("invalid vector value - " + value.toString());
			}
			else
				throw new PropertyException("invalid vector element type - " + value.toString());
		}

		try
		{
			double[] v = (value == null ?  new double[0] : (double[])value);
			if (fixedSize == -1 || fixedSize == v.length)
				return new Matrix(v);
			else
				throw new PropertyException("invalid vector length (" + v.length + ") - " + value.toString());
		}
		catch (ClassCastException e)
		{
			throw new PropertyException("invalid vector value - " + value.toString());
		}
	}

	public boolean isEmpty()
	{
		double[] v = getVector();
		return (v == null || v.length <= 0);
	}

	public double[] getVector()
	{
		return ((Matrix)pvalue).toDouble();
	}

	public double[] getArray()
	{
		return getVector();
	}

	public double elementAt(int index)
	{
		return getVector()[index];
	}

	public String toString()
	{
		return pvalue.toString();
	}
}
