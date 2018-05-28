/*
 * Sponsored License - for use in support of a program or activity
 * sponsored by MathWorks.  Not for government, commercial or other
 * non-sponsored organizational use.
 * File: im2uint8.c
 *
 * MATLAB Coder version            : 3.2
 * C/C++ source code generated on  : 05-Nov-2016 16:55:10
 */

/* Include Files */
#include "rt_nonfinite.h"
#include "FindCircle.h"
#include "im2uint8.h"
#include "FindCircle_emxutil.h"
#include "libmwgrayto8.h"

/* Function Definitions */

/*
 * Arguments    : const emxArray_real32_T *img
 *                emxArray_uint8_T *u
 * Return Type  : void
 */
void im2uint8(const emxArray_real32_T *img, emxArray_uint8_T *u)
{
  int i2;
  i2 = u->size[0];
  u->size[0] = img->size[0];
  emxEnsureCapacity((emxArray__common *)u, i2, (int)sizeof(unsigned char));
  grayto8_real32(&img->data[0], &u->data[0], (double)img->size[0]);
}

/*
 * File trailer for im2uint8.c
 *
 * [EOF]
 */
