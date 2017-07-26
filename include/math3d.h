#ifndef MATH3D_H
#define MATH3D_H
#include <cmath>
#include <cstring>
#include "object.h"
#include "geometry.h"
/************************************************************************/
/***********       Functions available from math3d.c       **************/
/************************************************************************/
void VectorNew( float *v, float x, float y, float z);
void VectorNormal(float *v);
void VectorCross( float *v1, float *v2, float *out);
void VectorSub( float *v1, float *v2, float *out);
void VectorAdd( float *v1, float *v2, float *out);
void VectorCopy( float *v, float *out);
void VectorScale( float *v, float scale);
void QuatNew( float *axis, float phi, float *quat);
void QuatNormal( float *q);
void QuatAdd( float *q1, float *q2, float *out);
void IdentityMatrix( float *a );
void MultMatrices( float *a, float *b, float *out );
void MultVertexByMatrix( float *a, float *vert);
void MultVertexByMatrix3x3( float *a, float *vert);
void TranslateMatrix( float x, float y, float z, float *trans_mat);
void ScaleMatrix( float x, float y, float z, float *scale_mat );
void PrintMatrix( float *m);
void RotateMatrix( float x, float y, float z, float *rotmat );
void InverseRotation( float *rotmat, float *out);
void InvertMatrix( float *in, float *i );
void ResetAxes( object_axes *axes);
void CopyAxes( object_axes *src, object_axes *dest);

#endif
