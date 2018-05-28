/*
 * Sponsored License - for use in support of a program or activity
 * sponsored by MathWorks.  Not for government, commercial or other
 * non-sponsored organizational use.
 *
 * unique.c
 *
 * Code generation for function 'unique'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "FindCircle.h"
#include "unique.h"

/* Function Definitions */
void count_nonfinites(const emxArray_real32_T *b, int32_T *nMInf, int32_T
                      *nFinite, int32_T *nPInf, int32_T *nNaN)
{
  int32_T k;
  k = 0;
  while ((k + 1 <= 307200) && muSingleScalarIsInf(b->data[k]) && (b->data[k] <
          0.0F)) {
    k++;
  }

  *nMInf = k;
  k = 307200;
  while ((k >= 1) && muSingleScalarIsNaN(b->data[k - 1])) {
    k--;
  }

  *nNaN = 307200 - k;
  while ((k >= 1) && muSingleScalarIsInf(b->data[k - 1]) && (b->data[k - 1] >
          0.0F)) {
    k--;
  }

  *nPInf = 307200 - (k + *nNaN);
  *nFinite = k - *nMInf;
}

/* End of code generation (unique.c) */
