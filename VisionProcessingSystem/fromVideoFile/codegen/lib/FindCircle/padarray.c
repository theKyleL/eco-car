/*
 * Sponsored License - for use in support of a program or activity
 * sponsored by MathWorks.  Not for government, commercial or other
 * non-sponsored organizational use.
 * File: padarray.c
 *
 * MATLAB Coder version            : 3.2
 * C/C++ source code generated on  : 05-Nov-2016 16:55:10
 */

/* Include Files */
#include "rt_nonfinite.h"
#include "FindCircle.h"
#include "padarray.h"
#include "FindCircle_emxutil.h"

/* Function Definitions */

/*
 * Arguments    : const double varargin_1[307200]
 *                const double varargin_2[2]
 *                emxArray_real_T *b
 * Return Type  : void
 */
void padarray(const double varargin_1[307200], const double varargin_2[2],
              emxArray_real_T *b)
{
  double dv2[2];
  int i10;
  int j;
  int i;
  int i11;
  for (i10 = 0; i10 < 2; i10++) {
    dv2[i10] = (480.0 + 160.0 * (double)i10) + 2.0 * varargin_2[i10];
  }

  i10 = b->size[0] * b->size[1];
  b->size[0] = (int)dv2[0];
  b->size[1] = (int)dv2[1];
  emxEnsureCapacity((emxArray__common *)b, i10, (int)sizeof(double));
  for (j = 0; j < (int)varargin_2[1]; j++) {
    i10 = b->size[0];
    for (i = 0; i < i10; i++) {
      b->data[i + b->size[0] * j] = 0.0;
    }
  }

  i10 = b->size[1];
  for (j = (int)varargin_2[1] + 640; j + 1 <= i10; j++) {
    i11 = b->size[0];
    for (i = 0; i < i11; i++) {
      b->data[i + b->size[0] * j] = 0.0;
    }
  }

  for (j = 0; j < 640; j++) {
    for (i = 0; i < (int)varargin_2[0]; i++) {
      b->data[i + b->size[0] * (j + (int)varargin_2[1])] = 0.0;
    }
  }

  for (j = 0; j < 640; j++) {
    i10 = b->size[0];
    for (i = (int)varargin_2[0] + 480; i + 1 <= i10; i++) {
      b->data[i + b->size[0] * (j + (int)varargin_2[1])] = 0.0;
    }
  }

  for (j = 0; j < 640; j++) {
    for (i = 0; i < 480; i++) {
      b->data[(i + (int)varargin_2[0]) + b->size[0] * (j + (int)varargin_2[1])] =
        varargin_1[i + 480 * j];
    }
  }
}

/*
 * File trailer for padarray.c
 *
 * [EOF]
 */
