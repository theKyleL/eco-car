/*
 * Sponsored License - for use in support of a program or activity
 * sponsored by MathWorks.  Not for government, commercial or other
 * non-sponsored organizational use.
 *
 * FindCircle_types.h
 *
 * Code generation for function 'FindCircle'
 *
 */

#ifndef FINDCIRCLE_TYPES_H
#define FINDCIRCLE_TYPES_H

/* Include files */
#include "rtwtypes.h"

/* Type Definitions */
#ifndef typedef_FindCircleStackData
#define typedef_FindCircleStackData

typedef struct {
  union
  {
    struct {
      real_T accumMatrixRe[307200];
      real_T Hd[307200];
      real_T marker[307200];
      real_T mask[307200];
      boolean_T bw[307200];
    } f0;

    struct {
      int32_T iwork[307200];
    } f1;

    struct {
      real32_T a[309444];
    } f2;

    struct {
      real32_T a[309444];
    } f3;
  } u1;

  struct {
    int32_T idx[307200];
  } f4;

  struct {
    real32_T A[307200];
    boolean_T nans[307200];
  } f5;

  struct {
    creal_T out[307200];
    real32_T A[307200];
    real32_T Gx[307200];
    real32_T Gy[307200];
    boolean_T varargin_1[921600];
    uint8_T img[307200];
    boolean_T gradientImg[307200];
  } f6;

  struct {
    creal_T accumMatrix[307200];
    real32_T gradientImg[307200];
  } f7;
} FindCircleStackData;

#endif                                 /*typedef_FindCircleStackData*/

#ifndef struct_emxArray_boolean_T_0x0
#define struct_emxArray_boolean_T_0x0

struct emxArray_boolean_T_0x0
{
  int32_T size[2];
};

#endif                                 /*struct_emxArray_boolean_T_0x0*/

#ifndef typedef_emxArray_boolean_T_0x0
#define typedef_emxArray_boolean_T_0x0

typedef struct emxArray_boolean_T_0x0 emxArray_boolean_T_0x0;

#endif                                 /*typedef_emxArray_boolean_T_0x0*/

#ifndef struct_emxArray_real_T
#define struct_emxArray_real_T

struct emxArray_real_T
{
  real_T *data;
  int32_T *size;
  int32_T allocatedSize;
  int32_T numDimensions;
  boolean_T canFreeData;
};

#endif                                 /*struct_emxArray_real_T*/

#ifndef typedef_emxArray_real_T
#define typedef_emxArray_real_T

typedef struct emxArray_real_T emxArray_real_T;

#endif                                 /*typedef_emxArray_real_T*/

#ifndef struct_emxArray_real_T_0
#define struct_emxArray_real_T_0

struct emxArray_real_T_0
{
  int32_T size[1];
};

#endif                                 /*struct_emxArray_real_T_0*/

#ifndef typedef_emxArray_real_T_0
#define typedef_emxArray_real_T_0

typedef struct emxArray_real_T_0 emxArray_real_T_0;

#endif                                 /*typedef_emxArray_real_T_0*/

#ifndef struct_emxArray_real_T_1x0
#define struct_emxArray_real_T_1x0

struct emxArray_real_T_1x0
{
  int32_T size[2];
};

#endif                                 /*struct_emxArray_real_T_1x0*/

#ifndef typedef_emxArray_real_T_1x0
#define typedef_emxArray_real_T_1x0

typedef struct emxArray_real_T_1x0 emxArray_real_T_1x0;

#endif                                 /*typedef_emxArray_real_T_1x0*/

#ifndef struct_stMMP2c8Zj6Qe4u3FQAfWOB
#define struct_stMMP2c8Zj6Qe4u3FQAfWOB

struct stMMP2c8Zj6Qe4u3FQAfWOB
{
  real_T Area;
  real_T Centroid[2];
  real_T BoundingBox[4];
  real_T MajorAxisLength;
  real_T MinorAxisLength;
  real_T Eccentricity;
  real_T Orientation;
  emxArray_boolean_T_0x0 Image;
  emxArray_boolean_T_0x0 FilledImage;
  real_T FilledArea;
  real_T EulerNumber;
  real_T Extrema[16];
  real_T EquivDiameter;
  real_T Extent;
  emxArray_real_T *PixelIdxList;
  emxArray_real_T *PixelList;
  real_T Perimeter;
  emxArray_real_T_0 PixelValues;
  real_T WeightedCentroid[2];
  real_T MeanIntensity;
  real_T MinIntensity;
  real_T MaxIntensity;
  emxArray_real_T_1x0 SubarrayIdx;
  real_T SubarrayIdxLengths[2];
};

#endif                                 /*struct_stMMP2c8Zj6Qe4u3FQAfWOB*/

#ifndef typedef_c_struct_T
#define typedef_c_struct_T

typedef struct stMMP2c8Zj6Qe4u3FQAfWOB c_struct_T;

#endif                                 /*typedef_c_struct_T*/

#ifndef struct_b_emxArray_struct_T
#define struct_b_emxArray_struct_T

struct b_emxArray_struct_T
{
  c_struct_T *data;
  int32_T *size;
  int32_T allocatedSize;
  int32_T numDimensions;
  boolean_T canFreeData;
};

#endif                                 /*struct_b_emxArray_struct_T*/

#ifndef typedef_b_emxArray_struct_T
#define typedef_b_emxArray_struct_T

typedef struct b_emxArray_struct_T b_emxArray_struct_T;

#endif                                 /*typedef_b_emxArray_struct_T*/

#ifndef typedef_b_struct_T
#define typedef_b_struct_T

typedef struct {
  real_T WeightedCentroid[2];
} b_struct_T;

#endif                                 /*typedef_b_struct_T*/

#ifndef struct_emxArray__common
#define struct_emxArray__common

struct emxArray__common
{
  void *data;
  int32_T *size;
  int32_T allocatedSize;
  int32_T numDimensions;
  boolean_T canFreeData;
};

#endif                                 /*struct_emxArray__common*/

#ifndef typedef_emxArray__common
#define typedef_emxArray__common

typedef struct emxArray__common emxArray__common;

#endif                                 /*typedef_emxArray__common*/

#ifndef struct_emxArray_boolean_T
#define struct_emxArray_boolean_T

struct emxArray_boolean_T
{
  boolean_T *data;
  int32_T *size;
  int32_T allocatedSize;
  int32_T numDimensions;
  boolean_T canFreeData;
};

#endif                                 /*struct_emxArray_boolean_T*/

#ifndef typedef_emxArray_boolean_T
#define typedef_emxArray_boolean_T

typedef struct emxArray_boolean_T emxArray_boolean_T;

#endif                                 /*typedef_emxArray_boolean_T*/

#ifndef struct_emxArray_creal_T
#define struct_emxArray_creal_T

struct emxArray_creal_T
{
  creal_T *data;
  int32_T *size;
  int32_T allocatedSize;
  int32_T numDimensions;
  boolean_T canFreeData;
};

#endif                                 /*struct_emxArray_creal_T*/

#ifndef typedef_emxArray_creal_T
#define typedef_emxArray_creal_T

typedef struct emxArray_creal_T emxArray_creal_T;

#endif                                 /*typedef_emxArray_creal_T*/

#ifndef struct_emxArray_int32_T
#define struct_emxArray_int32_T

struct emxArray_int32_T
{
  int32_T *data;
  int32_T *size;
  int32_T allocatedSize;
  int32_T numDimensions;
  boolean_T canFreeData;
};

#endif                                 /*struct_emxArray_int32_T*/

#ifndef typedef_emxArray_int32_T
#define typedef_emxArray_int32_T

typedef struct emxArray_int32_T emxArray_int32_T;

#endif                                 /*typedef_emxArray_int32_T*/

#ifndef struct_emxArray_real32_T
#define struct_emxArray_real32_T

struct emxArray_real32_T
{
  real32_T *data;
  int32_T *size;
  int32_T allocatedSize;
  int32_T numDimensions;
  boolean_T canFreeData;
};

#endif                                 /*struct_emxArray_real32_T*/

#ifndef typedef_emxArray_real32_T
#define typedef_emxArray_real32_T

typedef struct emxArray_real32_T emxArray_real32_T;

#endif                                 /*typedef_emxArray_real32_T*/

#ifndef struct_emxArray_struct_T
#define struct_emxArray_struct_T

struct emxArray_struct_T
{
  b_struct_T *data;
  int32_T *size;
  int32_T allocatedSize;
  int32_T numDimensions;
  boolean_T canFreeData;
};

#endif                                 /*struct_emxArray_struct_T*/

#ifndef typedef_emxArray_struct_T
#define typedef_emxArray_struct_T

typedef struct emxArray_struct_T emxArray_struct_T;

#endif                                 /*typedef_emxArray_struct_T*/

#ifndef struct_emxArray_uint8_T
#define struct_emxArray_uint8_T

struct emxArray_uint8_T
{
  uint8_T *data;
  int32_T *size;
  int32_T allocatedSize;
  int32_T numDimensions;
  boolean_T canFreeData;
};

#endif                                 /*struct_emxArray_uint8_T*/

#ifndef typedef_emxArray_uint8_T
#define typedef_emxArray_uint8_T

typedef struct emxArray_uint8_T emxArray_uint8_T;

#endif                                 /*typedef_emxArray_uint8_T*/
#endif

/* End of code generation (FindCircle_types.h) */
