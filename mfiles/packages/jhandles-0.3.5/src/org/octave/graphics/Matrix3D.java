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

public class Matrix3D
{
	private double[] data;

	public Matrix3D()
	{
			this.data = new double[] {1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1};
	}

	public Matrix3D(double[] data)
	{
			this.data = (double[])data.clone();
	}

	public void translate(double x, double y, double z)
	{
			data[12] += data[0]*x+data[4]*y+data[8]*z;
			data[13] += data[1]*x+data[5]*y+data[9]*z;
			data[14] += data[2]*x+data[6]*y+data[10]*z;
			data[15] += data[3]*x+data[7]*y+data[11]*z;
	}

	public void scale(double sx, double sy, double sz)
	{
			data[0] *= sx; data[1] *= sx; data[2] *= sx; data[3] *= sx;
			data[4] *= sy; data[5] *= sy; data[6] *= sy; data[7] *= sy;
			data[8] *= sz; data[9] *= sz; data[10] *= sz; data[11] *= sz;
	}

	public void rotate(double a, int ax)
	{
			/* not really needed actually */
	}

	public void mult(double[] m)
	{
		double[] dd = new double[16];
		transform(m, dd, 4, 0, 0);
		data = dd;
	}

	public void mult(Matrix3D m)
	{
		mult(m.data);
	}

	public void eye()
	{
			data = new double[] {1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1};
	}

	public void transform(double[] in, double[] out, int n, int offi, int offo)
	{
			for (int i=0; i<n; i++, offi+=4, offo+=4)
			{
					for (int k=0; k<4; k++)
					{
							out[offo+k] =
								data[k+0]*in[offi+0]+
								data[k+4]*in[offi+1]+
								data[k+8]*in[offi+2]+
								data[k+12]*in[offi+3];
					}
			}
	}

	public void transform(double[][] in, double[][] out, int n, int offi, int offo)
	{
			for (int i=0; i<n; i++)
			{
					for (int k=0; k<4; k++)
					{
							out[offo+i][k] =
								data[k+0]*in[offi+i][0]+
								data[k+4]*in[offi+i][1]+
								data[k+8]*in[offi+i][2]+
								data[k+12]*in[offi+i][3];
					}
			}
	}

	public void transform(double x, double y, double z, double[] out, int offo)
	{
		for (int k=0; k<3; k++)
		{
			out[offo+k] =
				data[k+0]*x+
				data[k+4]*y+
				data[k+8]*z+
				data[k+12]*1;
		}
	}

	public void transform(double[] x, double[] y, double[] z, int n, double[] tx, double[] ty, double[] tz)
	{
		double a;

		for (int i=0; i<n; i++)
		{
			a     = data[3]*x[i]+data[7]*y[i]+data[11]*z[i]+data[15];
			tx[i] = (data[0]*x[i]+data[4]*y[i]+data[8] *z[i]+data[12])/a;
			ty[i] = (data[1]*x[i]+data[5]*y[i]+data[9] *z[i]+data[13])/a;
			tz[i] = (data[2]*x[i]+data[6]*y[i]+data[10]*z[i]+data[14])/a;
		}
	}

	public double[] getData()
	{
		return data;
	}

	public Matrix3D inv()
	{
		Matrix3D ret = new Matrix3D();
		double[] d1 = (double[])data.clone();
		double[] d2 = ret.data;

		int i, j, k, swap;
		double p;

		for (i=0; i<4; i++)
		{
			swap = i;
			for (j=i+1; j<4; j++)
				if (Math.abs(d1[j+i*4]) > Math.abs(d1[i+i*4]))
					swap = j;

			if (swap != i)
				for (k=0; k<4; k++)
				{
					p = d1[i+k*4];
					d1[i+k*4] = d1[swap+k*4];
					d1[swap+k*4] = p;

					p = d2[i+k*4];
					d2[i+k*4] = d2[swap+k*4];
					d2[swap+k*4] = p;
				}

			if (d1[i+i*4] == 0)
			{
				System.out.println("WARNING: singular matrix, cannot invert");
				break;
			}

			p = d1[i+i*4];
			for (k=0; k<4; k++)
			{
				d1[i+k*4] /= p;
				d2[i+k*4] /= p;
			}
			for (j=0; j<4; j++)
				if (i != j)
				{
					p = d1[j+i*4];
					for (k=0; k<4; k++)
					{
						d1[j+k*4] -= (d1[i+k*4]*p);
						d2[j+k*4] -= (d2[i+k*4]*p);
					}
				}
		}

		return ret;
	}

        public void print(String name)
        {
          System.out.println(name);
          for (int i=0; i<4; i++)
          {
            for (int j=0; j<4; j++)
              System.out.print(data[j*4+i] + " ");
            System.out.println("");
          }
        }
}
