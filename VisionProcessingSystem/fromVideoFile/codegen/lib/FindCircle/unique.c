/*
 * Sponsored License - for use in support of a program or activity
 * sponsored by MathWorks.  Not for government, commercial or other
 * non-sponsored organizational use.
 * File: unique.c
 *
 * MATLAB Coder version            : 3.2
 * C/C++ source code generated on  : 05-Nov-2016 16:55:10
 */

/* Include Files */
#include "rt_nonfinite.h"
#include "FindCircle.h"
#include "unique.h"

/* Function Definitions */

/*
 * Arguments    : const emxArray_real32_T *b
 *                int *nMInf
 *                int *nFinite
 *                int *nPInf
 *                int *nNaN
 * Return Type  : void
 */
void count_nonfinites(const emxArray_real32_T *b, int *nMInf, int *nFinite, int *
                      nPInf, int *nNaN)
{
  int k;
  k = 0;
  while ((k + 1 <= 307200) && rtIsInfF(b->data[k]) && (b->data[k] < 0.0F)) {
    k++;
  }

  *nMInf = k;
  k = 307200;
  while ((k >= 1) && rtIsNaNF(b->data[k - 1])) {
    k--;
  }

  *nNaN = 307200 - k;
  while ((k >= 1) && rtIsInfF(b->data[k - 1]) && (b->data[k - 1] > 0.0F)) {
    k--;
  }

  *nPInf = 307200 - (k + *nNaN);
  *nFinite = k - *nMInf;
}

/*
 * File trailer for unique.c
 *
 * [EOF]
 */
