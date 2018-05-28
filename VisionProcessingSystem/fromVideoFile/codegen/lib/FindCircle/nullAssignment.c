/*
 * Sponsored License - for use in support of a program or activity
 * sponsored by MathWorks.  Not for government, commercial or other
 * non-sponsored organizational use.
 * File: nullAssignment.c
 *
 * MATLAB Coder version            : 3.2
 * C/C++ source code generated on  : 05-Nov-2016 16:55:10
 */

/* Include Files */
#include "rt_nonfinite.h"
#include "FindCircle.h"
#include "nullAssignment.h"
#include "FindCircle_emxutil.h"

/* Function Definitions */

/*
 * Arguments    : emxArray_real32_T *x
 *                const emxArray_boolean_T *idx
 * Return Type  : void
 */
void nullAssignment(emxArray_real32_T *x, const emxArray_boolean_T *idx)
{
  int nxin;
  int k0;
  int k;
  int nxout;
  nxin = x->size[1];
  k0 = 0;
  for (k = 1; k <= idx->size[1]; k++) {
    k0 += idx->data[k - 1];
  }

  nxout = x->size[1] - k0;
  k0 = -1;
  for (k = 1; k <= nxin; k++) {
    if ((k > idx->size[1]) || (!idx->data[k - 1])) {
      k0++;
      x->data[k0] = x->data[k - 1];
    }
  }

  k0 = x->size[0] * x->size[1];
  if (1 > nxout) {
    x->size[1] = 0;
  } else {
    x->size[1] = nxout;
  }

  emxEnsureCapacity((emxArray__common *)x, k0, (int)sizeof(float));
}

/*
 * File trailer for nullAssignment.c
 *
 * [EOF]
 */
