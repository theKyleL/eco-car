/*
 * Sponsored License - for use in support of a program or activity
 * sponsored by MathWorks.  Not for government, commercial or other
 * non-sponsored organizational use.
 * File: abs.c
 *
 * MATLAB Coder version            : 3.2
 * C/C++ source code generated on  : 05-Nov-2016 16:55:10
 */

/* Include Files */
#include "rt_nonfinite.h"
#include "FindCircle.h"
#include "abs.h"
#include "FindCircle_emxutil.h"

/* Function Definitions */

/*
 * Arguments    : const emxArray_real_T *x
 *                emxArray_real_T *y
 * Return Type  : void
 */
void b_abs(const emxArray_real_T *x, emxArray_real_T *y)
{
  int x_idx_0;
  int i5;
  x_idx_0 = x->size[0];
  i5 = y->size[0];
  y->size[0] = x_idx_0;
  emxEnsureCapacity((emxArray__common *)y, i5, (int)sizeof(double));
  for (x_idx_0 = 0; x_idx_0 + 1 <= x->size[0]; x_idx_0++) {
    y->data[x_idx_0] = fabs(x->data[x_idx_0]);
  }
}

/*
 * File trailer for abs.c
 *
 * [EOF]
 */
