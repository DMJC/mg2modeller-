// Copyright (C) (1999) (Greg Waltz) <finklesk@op.net>   
//       
// This program is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation; either version 2 of the License, or
// (at your option) any later version.
// 
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of 
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the   
// GNU General Public License for more details.
// 
// You should have received a copy of the GNU General Public License
// along with this program; if not, write to the Free Software
// Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.  

#include "../include/math3d.h"

/*********************************************************************/
/********************	Vector Operations    *************************/
/*********************************************************************/

class Vector3D {
	private:
		
	public:
		void Vector3D_New( float *v, float x, float y, float z);
		float Vector3D_Length( float *v, Vector3D);
		void Vector3D_Normal(float *v);
		void Vector3D_Cross( float *v1, float *v2, float *out);
		float Vector3D_Dot( float *v1, float *v2);
		void Vector3D_Sub( float *v1, float *v2, float *out);
		void Vector3D_Add( float *v1, float *v2, float *out);
		void Vector3D_Copy( float *v, float *out);
		void Vector3D_Scale( float *v, float scale);
};

class Quaternion {
	private:
	public:
};

void Vector3D::Vector3D_New( float *v, float x, float y, float z)
{
 v[0] = x;
 v[1] = y;
 v[2] = z;
}


// get vector length

float Vector3D::Vector3D_Length( float *v, Vector3D)
{

 return sqrt( v[0]*v[0] + v[1]*v[1] + v[2]*v[2] );

}// end VectorLength()


/////// set vector to length 1

void Vector3D::Vector3D_Normal(float *v)
{
 float d;

 d = sqrt(v[0]*v[0] + v[1]*v[1] + v[2]*v[2]);

 if( d==0.0){ printf("error: zero length\n");
                return; }
 v[0]/=d; v[1]/=d; v[2]/=d;
}// end Normalize()


void Vector3D::Vector3D_Cross( float *v1, float *v2, float *out)
{

 out[0] = v1[1]*v2[2] - v1[2]*v2[1];
 out[1] = v1[2]*v2[0] - v1[0]*v2[2];
 out[2] = v1[0]*v2[1] - v1[1]*v2[0];

}// end Vector3D_Cross()


float Vector3D::Vector3D_Dot( float *v1, float *v2)
{
 return v1[0]*v2[0] + v1[1]*v2[1] + v1[2]*v2[2];
}


void Vector3D::Vector3D_Sub( float *v1, float *v2, float *out)
{
 out[0] = v1[0] - v2[0];
 out[1] = v1[1] - v2[1];
 out[2] = v1[2] - v2[2];

}// end Vector3D_Sub()

void Vector3D::Vector3D_Add( float *v1, float *v2, float *out)
{
 out[0] = v1[0] + v2[0];
 out[1] = v1[1] + v2[1];
 out[2] = v1[2] + v2[2];
}

void Vector3D::Vector3D_Copy( float *v, float *out)
{
 out[0] = v[0];
 out[1] = v[1];
 out[2] = v[2];

}// end Vector3D_Copy()


void Vector3D::Vector3D_Scale( float *v, float scale)
{
 v[0] *= scale;
 v[1] *= scale;
 v[2] *= scale;

}// end Vector3D_Scale()


/*********************************************************************/
/*******************   Quaternion  Operations     ********************/
/*********************************************************************/

/*
void QuatNew( float *axis, float phi, float *quat)
{
 float phi2 = phi/2.0;

 Vector3D::Vector3D_Normal( axis);
 Vector3D::Vector3D_Copy( axis, quat );
 Vector3D::Vector3D_Scale(quat, sin(phi2) );
 quat[3] = cos(phi2);
}
*/


void QuatNormal( float *q)
{
 float m;

 m = q[0]*q[0] + q[1]*q[1] + q[2]*q[2] + q[3]*q[3];

 q[0] /= m;
 q[1] /= m;
 q[2] /= m;
 q[3] /= m;
}

/*
void QuatAdd( float *q1, float *q2, float *out)
{
 float t1[4], t2[4], t3[4], tf[4];

 Vector3D::Vector3D_Copy( q1, t1);
 Vector3D::Vector3D_Scale( t1, q2[3]);

 Vector3D::Vector3D_Copy( q2, t2);
 Vector3D::Vector3D_Scale(t2, q1[3]);

 Vector3D::Vector3D_Cross(q2, q1, t3);
 Vector3D::Vector3D_Add(t1,t2,tf);
 Vector3D::Vector3D_Add(t3,tf,tf);
 tf[3] = q1[3]*q2[3] - Vector3D_Dot(q1,q2);

 out[0] = tf[0];
 out[1] = tf[1];
 out[2] = tf[2];
 out[3] = tf[3];

 QuatNormal(out);

}
*/


/*********************************************************************/
/********************	Matrix Operations    *************************/
/*********************************************************************/

/* some of the matrix operators are cheats. they use opengl to do the */
/* work. someday, when other features are less pressing, i will replace */
/* the opengl code here. i want to do it for the sake of learning this */
/* stuff better */



void IdentityMatrix( float *a )
{
memset((void*)a, 0, sizeof(float)*16 );

a[0] = a[5] = a[10] = a[15] = 1.0;

}// end IdentityMatrix()


/*
 * MultMatrices:  multiplies two 4x4 matrices in the order a*b and puts
 *   the result in the matrix out. it is safe to have either a or b as
 *   the output matrix.
 */

void MultMatrices( float *a, float *b, float *out )
{
  float r[16];

  r[0] = a[0]*b[0] + a[4]*b[1] + a[8]*b[2] + a[12]*b[3];
  r[4] = a[0]*b[4] + a[4]*b[5] + a[8]*b[6] + a[12]*b[7];
  r[8] = a[0]*b[8] + a[4]*b[9] + a[8]*b[10] + a[12]*b[11];
  r[12] = a[0]*b[12] + a[4]*b[13] + a[8]*b[14] + a[12]*b[15];

  r[1] = a[1]*b[0] + a[5]*b[1] + a[9]*b[2] + a[13]*b[3];
  r[5] = a[1]*b[4] + a[5]*b[5] + a[9]*b[6] + a[13]*b[7];
  r[9] = a[1]*b[8] + a[5]*b[9] + a[9]*b[10] + a[13]*b[11];
  r[13] = a[1]*b[12] + a[5]*b[13] + a[9]*b[14] + a[13]*b[15];

  r[2] = a[2]*b[0] + a[6]*b[1] + a[10]*b[2] + a[14]*b[3];
  r[6] = a[2]*b[4] + a[6]*b[5] + a[10]*b[6] + a[14]*b[7];
  r[10] = a[2]*b[8] + a[6]*b[9] + a[10]*b[10] + a[14]*b[11];
  r[14] = a[2]*b[12] + a[6]*b[13] + a[10]*b[14] + a[14]*b[15];

  r[3] = a[3]*b[0] + a[7]*b[1] + a[11]*b[2] + a[15]*b[3];
  r[7] = a[3]*b[4] + a[7]*b[5] + a[11]*b[6] + a[15]*b[7];
  r[11] = a[3]*b[8] + a[7]*b[9] + a[11]*b[10] + a[15]*b[11];
  r[15] = a[3]*b[12] + a[7]*b[13] + a[11]*b[14] + a[15]*b[15];

  memcpy( out, r, sizeof(float)*16);

}// end MultMatrices()


// multiplies a vertex by a 4x4 matrix. out is the transformed vertex.
// vertex is 3 elements. assuming w component of 1.0

void MultVertexByMatrix( float *a, float *vert)
{
 float out[3];
 float w;

 out[0] = (a[0]*vert[0] + a[4]*vert[1] + a[8]*vert[2] + a[12]);
 out[1] = (a[1]*vert[0] + a[5]*vert[1] + a[9]*vert[2] + a[13]);
 out[2] = (a[2]*vert[0] + a[6]*vert[1] + a[10]*vert[2] + a[14]);
 w = 	 (a[3]*vert[0] + a[7]*vert[1] + a[11]*vert[2] + a[15]);

 vert[0] = out[0]/w;
 vert[1] = out[1]/w;
 vert[2] = out[2]/w;

}// end MultVertexByMatrix()


/*
 * the following function works with 3x3 matrices and 3 element vectors
 * for 3x3 rotation/shearing matrices.
 *
 * arguments:
 *	*a: pointer to a 3x3 matrix.
 *	*vert: pointer to a 3 element vertex.
 */

void MultVertexByMatrix3x3( float *a, float *vert)
{
 float out[3];

 out[0] = (a[0]*vert[0] + a[4]*vert[1] + a[8]*vert[2]);
 out[1] = (a[1]*vert[0] + a[5]*vert[1] + a[9]*vert[2]);
 out[2] = (a[2]*vert[0] + a[6]*vert[1] + a[10]*vert[2]);

 vert[0] = out[0];
 vert[1] = out[1];
 vert[2] = out[2];

}// end MultVertexByMatrix()



/*
 * TranslateMatrx: translate the given matrix
 *
 * arguments:
 *	x, y, z: x, y, and z factors
 *	trans_mat: matrix to be translated.
 */

void TranslateMatrix( float x, float y, float z, float *trans_mat)
{
/* row one */

trans_mat[0] += x*trans_mat[3];
trans_mat[4] += x*trans_mat[7];
trans_mat[8] += x*trans_mat[11];
trans_mat[12] += x*trans_mat[15];

/* row two */

trans_mat[1] += y*trans_mat[3];
trans_mat[5] += y*trans_mat[7];
trans_mat[9] += y*trans_mat[11];
trans_mat[13] += y*trans_mat[15];

/* row three */

trans_mat[2] += z*trans_mat[3];
trans_mat[6] += z*trans_mat[7];
trans_mat[10] += z*trans_mat[11];
trans_mat[14] += z*trans_mat[15];

}// TranslateMatrix()

/*
 * ScaleMatrix: scale the matrix
 *
 * arguments:
 *	x: x scaling factor
 *	y: y scaling factor
 *	z: z "
 *	scale_mat: the matrix to be scaled.
 */

void ScaleMatrix( float x, float y, float z, float *scale_mat )
{
scale_mat[0] *= x;
scale_mat[4] *= x;
scale_mat[8] *= x;
scale_mat[12] *= x;

scale_mat[1] *= y;
scale_mat[5] *= y;
scale_mat[9] *= y;
scale_mat[13] *= y;

scale_mat[2] *= z;
scale_mat[6] *= z;
scale_mat[10] *= z;
scale_mat[14] *= z;

}// end ScaleMatrix()



void PrintMatrix( float *m)
{
printf("%f %f %f %f\n", m[0], m[4], m[8], m[12]);
printf("%f %f %f %f\n", m[1], m[5], m[9], m[13]);
printf("%f %f %f %f\n", m[2], m[6], m[10], m[14]);
printf("%f %f %f %f\n\n", m[3], m[7], m[11], m[15]);
  
}


void RotateMatrix( float x, float y, float z, float *rotmat )
{
glMatrixMode(GL_MODELVIEW);

glLoadMatrixf(rotmat);
glRotatef(y, 0.0, 1.0, 0.0);
glRotatef(x, 1.0, 0.0, 0.0);
glRotatef(z, 0.0, 0.0, 1.0);

glGetFloatv(GL_MODELVIEW_MATRIX, rotmat);

}// end RotateMatrix()


///////// inverse for views

void InverseRotation( float *rotmat, float *out)
{
float temp[16];
float t[16];

memmove( temp, rotmat, sizeof(float)*16 );

/* invert the matrix */
t[0] = temp[0];
t[1] = temp[4];
t[2] = temp[8];
t[3] = temp[12];

t[4] = temp[1];
t[5] = temp[5];
t[6] = temp[9];
t[7] = temp[13];

t[8] = temp[2];
t[9] = temp[6];
t[10] = temp[10];
t[11] = temp[14];

t[12] = temp[3];
t[13] = temp[7];
t[14] = temp[11];
t[15] = temp[15];

memmove( out, t, sizeof(float)*16 );


}// end InverseRotateMatrix()


/////////////////// get inverse of a 4x4 matrix //////////////////

/* the InvertMatrix function was taken from matrix.c in Mesa-3.0 */
/* since Mesa is GNU software also, only the relevant info is below */

/* InvertMatrix()
 * From Mesa 3-D graphics library
 * Version:  3.0
 * Copyright (C) 1995-1998  Brian Paul
 *
 * Revision 3.5  1998/05/07 00:12:57  brianp
 * new invert_matrix() function from Jacques Leroy
 *
 */

int InvertMatrix( const float *m, float *out )
{
/* NB. OpenGL Matrices are COLUMN major. */
#define SWAP_ROWS(a, b) { float *_tmp = a; (a)=(b); (b)=_tmp; }
#define MAT(m,r,c) (m)[(c)*4+(r)]
 
 float wtmp[4][8];
 float m0, m1, m2, m3, s;
 float *r0, *r1, *r2, *r3;

 r0 = wtmp[0], r1 = wtmp[1], r2 = wtmp[2], r3 = wtmp[3];

 r0[0] = MAT(m,0,0), r0[1] = MAT(m,0,1),
 r0[2] = MAT(m,0,2), r0[3] = MAT(m,0,3),
 r0[4] = 1.0, r0[5] = r0[6] = r0[7] = 0.0,
      
 r1[0] = MAT(m,1,0), r1[1] = MAT(m,1,1),
 r1[2] = MAT(m,1,2), r1[3] = MAT(m,1,3),
 r1[5] = 1.0, r1[4] = r1[6] = r1[7] = 0.0,
      
 r2[0] = MAT(m,2,0), r2[1] = MAT(m,2,1),
 r2[2] = MAT(m,2,2), r2[3] = MAT(m,2,3),
 r2[6] = 1.0, r2[4] = r2[5] = r2[7] = 0.0,

 r3[0] = MAT(m,3,0), r3[1] = MAT(m,3,1),
 r3[2] = MAT(m,3,2), r3[3] = MAT(m,3,3),
 r3[7] = 1.0, r3[4] = r3[5] = r3[6] = 0.0;
 
 /* choose pivot - or die */
 if (fabs(r3[0])>fabs(r2[0])) SWAP_ROWS(r3, r2);
 if (fabs(r2[0])>fabs(r1[0])) SWAP_ROWS(r2, r1);
 if (fabs(r1[0])>fabs(r0[0])) SWAP_ROWS(r1, r0);
 if (0.0 == r0[0])  return GL_FALSE;
   
 /* eliminate first variable     */
 m1 = r1[0]/r0[0]; m2 = r2[0]/r0[0]; m3 = r3[0]/r0[0];
 s = r0[1]; r1[1] -= m1 * s; r2[1] -= m2 * s; r3[1] -= m3 * s;
 s = r0[2]; r1[2] -= m1 * s; r2[2] -= m2 * s; r3[2] -= m3 * s;   
 s = r0[3]; r1[3] -= m1 * s; r2[3] -= m2 * s; r3[3] -= m3 * s;
 s = r0[4];
 if (s != 0.0) { r1[4] -= m1 * s; r2[4] -= m2 * s; r3[4] -= m3 * s; }
 s = r0[5];
 if (s != 0.0) { r1[5] -= m1 * s; r2[5] -= m2 * s; r3[5] -= m3 * s; }
 s = r0[6];
 if (s != 0.0) { r1[6] -= m1 * s; r2[6] -= m2 * s; r3[6] -= m3 * s; }
 s = r0[7];
 if (s != 0.0) { r1[7] -= m1 * s; r2[7] -= m2 * s; r3[7] -= m3 * s; }
 
 /* choose pivot - or die */
 if (fabs(r3[1])>fabs(r2[1])) SWAP_ROWS(r3, r2);
 if (fabs(r2[1])>fabs(r1[1])) SWAP_ROWS(r2, r1);
 if (0.0 == r1[1])  return GL_FALSE;
 
 /* eliminate second variable */
 m2 = r2[1]/r1[1]; m3 = r3[1]/r1[1];
 r2[2] -= m2 * r1[2]; r3[2] -= m3 * r1[2];
 r2[3] -= m2 * r1[3]; r3[3] -= m3 * r1[3];
 s = r1[4]; if (0.0 != s) { r2[4] -= m2 * s; r3[4] -= m3 * s; }
 s = r1[5]; if (0.0 != s) { r2[5] -= m2 * s; r3[5] -= m3 * s; }
 s = r1[6]; if (0.0 != s) { r2[6] -= m2 * s; r3[6] -= m3 * s; }
 s = r1[7]; if (0.0 != s) { r2[7] -= m2 * s; r3[7] -= m3 * s; }

 /* choose pivot - or die */
 if (fabs(r3[2])>fabs(r2[2])) SWAP_ROWS(r3, r2);
 if (0.0 == r2[2])  return GL_FALSE;
 
 /* eliminate third variable */
 m3 = r3[2]/r2[2];
 r3[3] -= m3 * r2[3], r3[4] -= m3 * r2[4],
 r3[5] -= m3 * r2[5], r3[6] -= m3 * r2[6],
 r3[7] -= m3 * r2[7];
 
 /* last check */
 if (0.0 == r3[3]) return GL_FALSE;
 
 s = 1.0/r3[3];              /* now back substitute row 3 */
 r3[4] *= s; r3[5] *= s; r3[6] *= s; r3[7] *= s;
 
 m2 = r2[3];                 /* now back substitute row 2 */
 s  = 1.0/r2[2];
 r2[4] = s * (r2[4] - r3[4] * m2), r2[5] = s * (r2[5] - r3[5] * m2), 
 r2[6] = s * (r2[6] - r3[6] * m2), r2[7] = s * (r2[7] - r3[7] * m2);
 m1 = r1[3];
 r1[4] -= r3[4] * m1, r1[5] -= r3[5] * m1,
 r1[6] -= r3[6] * m1, r1[7] -= r3[7] * m1;
 m0 = r0[3];
 r0[4] -= r3[4] * m0, r0[5] -= r3[5] * m0,
 r0[6] -= r3[6] * m0, r0[7] -= r3[7] * m0;
 
 m1 = r1[2];                 /* now back substitute row 1 */
 s  = 1.0/r1[1];
 r1[4] = s * (r1[4] - r2[4] * m1), r1[5] = s * (r1[5] - r2[5] * m1),
 r1[6] = s * (r1[6] - r2[6] * m1), r1[7] = s * (r1[7] - r2[7] * m1);
 m0 = r0[2];
 r0[4] -= r2[4] * m0, r0[5] -= r2[5] * m0,
 r0[6] -= r2[6] * m0, r0[7] -= r2[7] * m0;
 
 m0 = r0[1];                 /* now back substitute row 0 */
 s  = 1.0/r0[0];
 r0[4] = s * (r0[4] - r1[4] * m0), r0[5] = s * (r0[5] - r1[5] * m0),
 r0[6] = s * (r0[6] - r1[6] * m0), r0[7] = s * (r0[7] - r1[7] * m0);
 
 MAT(out,0,0) = r0[4]; MAT(out,0,1) = r0[5],
 MAT(out,0,2) = r0[6]; MAT(out,0,3) = r0[7],
 MAT(out,1,0) = r1[4]; MAT(out,1,1) = r1[5],
 MAT(out,1,2) = r1[6]; MAT(out,1,3) = r1[7],
 MAT(out,2,0) = r2[4]; MAT(out,2,1) = r2[5],
 MAT(out,2,2) = r2[6]; MAT(out,2,3) = r2[7],
 MAT(out,3,0) = r3[4]; MAT(out,3,1) = r3[5],
 MAT(out,3,2) = r3[6]; MAT(out,3,3) = r3[7];
 
return true;
 
#undef MAT
#undef SWAP_ROWS

}// end InvertMatrix()


/*********************************************************************

The following function sort of works. i tested it by getting the inverse
of the inverse of a matrix to see if it was nearly the same. well, it
works for the first inverse, but two of the elements come out wierd on the
second inverse. here's the output:

original
5.000000 9.000000 45.000000 2.000000
0.000000 87.000000 37.000000 -76.000000
4.000000 1.000000 82.000000 8.000000
56.000000 2.000000 1.000000 0.000000

inverse
-0.005842 0.000153 0.002915 0.018171
0.173717 -0.005205 -0.092876 -0.008876
-0.020272 0.001834 0.022490 0.000204
0.188991 -0.018223 -0.095369 -0.010062

inverse of inverse
5.625000 8.979764 45.010639 1.999999
-44.000000 87.456467 36.658310 -75.999992
7.500000 0.919057 82.042549 7.999999
56.000000 2.000004 1.000018 -0.000010


this function might be faster than the above since this one accesses the
matrix directly, rather than using that macro (MAT) which adds extra
multiplications. i just don't feel like debugging this right now :P
*/
void InvertMatrix( float *in, float *i )
{
float temp, a[16];

memmove( a, in, sizeof(float)*16 );

IdentityMatrix( i );

//make first element of a = 1.0

i[0] = 1.0/a[0];

a[4] /= a[0];
a[8] /= a[0];
a[12] /= a[0];
a[0] = 1.0;



// subtract row one from row 2

i[1] = -a[1]*i[0];

a[5] -= a[1]*a[4];  
a[9] -= a[1]*a[8];
a[13] -= a[1]*a[12];
a[1] = 0.0;

// subtract row 1 from row 3

i[2] = -a[2]*i[0];

a[6] -= a[2]*a[4];
a[10] -= a[2]*a[8]; 
a[14] -= a[2]*a[12];
a[2] = 0.0;

// subtract row 1 from row 4

i[3] = -a[3]*i[0];

a[7] -= a[3]*a[4];
a[11] -= a[3]*a[8];
a[15] -= a[3]*a[12];
a[3] = 0.0;

// NOW a[1,1] is 1 and a[x<1,1] is 0

// NEXT: make a[2,2] = 1 and the rest of the column 0

i[1] /= a[5];
i[5] /= a[5];

a[9] /= a[5];
a[13] /= a[5];
a[5] = 1.0;

// subtract row 2 from row 1

i[0] -= a[4]*i[1];
i[4] -= a[4]*i[5];
i[8] -= a[4]*i[9];
i[12] -= a[4]*i[13];

a[8] -= a[4]*a[9];  
a[12] -= a[4]*a[13];
a[4] = 0.0;


// subtract row 2 from row 3

i[2] -= a[6]*i[1];
i[6] -= a[6]*i[5];  
i[10] -= a[6]*i[9]; 
i[14] -= a[6]*i[13];

a[10] -= a[6]*a[9];
a[14] -= a[6]*a[13];
a[6] = 0.0;

// subtract row 2 from row 4

i[3] -= a[7]*i[1];
i[7] -= a[7]*i[5];
i[11] -= a[7]*i[9];
i[15] -= a[7]*i[13];

a[11] -= a[7]*a[9];
a[15] -= a[7]*a[13];
a[7] = 0.0;

//NEXT: set a[3,3] to 1 and the rest of the column to 0

i[2] /= a[10];
i[6] /= a[10];
i[10] /= a[10];   
i[14] /= a[10];

a[14] /= a[10];     
a[10] = 1.0;

// subtract row 3 from row 1

i[0] -= a[8]*i[2];
i[4] -= a[8]*i[6];
i[8] -= a[8]*i[10];
i[12] -= a[8]*i[14];

a[12] -= a[8]*a[14];
a[8] = 0.0;

// subtract row 3 from row 2

i[1] -= a[9]*i[2];
i[5] -= a[9]*i[6];
i[9] -= a[9]*i[10];
i[13] -= a[9]*i[14];

a[13] -= a[9]*a[14];
a[9] = 0.0;


// subtract row 3 from row 4

i[3] -= a[11]*i[2];
i[7] -= a[11]*i[6];
i[11] -= a[11]*i[10];
i[15] -= a[11]*i[14];

a[15] -= a[11]*a[14];
a[11] = 0.0;   

// NEXT: set a[4,4] to 1 and the rest of the column to 0

i[3] /= a[15];
i[7] /= a[15];
i[11] /= a[15];
i[15] /= a[15];   

a[15] = 1.0;

// subtract row 4 from row 1

i[0] -= a[12]*i[3];
i[4] -= a[12]*i[7];
i[8] -= a[12]*i[11];
i[12] -= a[12]*i[15];

a[12] = 0.0;

// subtract row 4 from row 2

i[1] -= a[13]*i[3]; 
i[5] -= a[13]*i[7];
i[9] -= a[13]*i[11];
i[13] -= a[13]*i[15];
a[13] = 0.0;

// subtract row 4 from row 3

i[2] -= a[14]*i[3];  
i[6] -= a[14]*i[7];
i[10] -= a[14]*i[11];
i[14] -= a[14]*i[15];

a[14] = 0.0;

} // end InvertMatrix()
/*
**********************************************************/


/*********************************************************************/
/*****************      General Functions      ***********************/
/*********************************************************************/


/*
 * ResetAxes: sets mg2_axes to original coordinate system.
 *
 */

/*
void ResetAxes( object_axes *axes)
{
  axes->x[0] = 1;
  axes->x[1] = axes->x[2] = 0;

  axes->y[1] = 1;
  axes->y[0] = axes->y[2] = 0;

  axes->z[2] = 1;
  axes->z[0] = axes->z[1] = 0;

}


void CopyAxes( object_axes *src, object_axes *dest)
{
  dest->x[0] = src->x[0];
  dest->x[1] = src->x[1];
  dest->x[2] = src->x[2];

  dest->y[0] = src->y[0];
  dest->y[1] = src->y[1];
  dest->y[2] = src->y[2];

  dest->z[0] = src->z[0];
  dest->z[1] = src->z[1];
  dest->z[2] = src->z[2];
}
*/