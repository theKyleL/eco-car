/*
 * Sponsored License - for use in support of a program or activity
 * sponsored by MathWorks.  Not for government, commercial or other
 * non-sponsored organizational use.
 *
 * mergesort.c
 *
 * Code generation for function 'mergesort'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "FindCircle.h"
#include "mergesort.h"

/* Function Definitions */
void b_mergesort(FindCircleStackData *SD, int32_T idx[307200], const real32_T x
                 [307200])
{
  int32_T k;
  int32_T i;
  boolean_T p;
  int32_T i2;
  int32_T j;
  int32_T pEnd;
  int32_T b_p;
  int32_T q;
  int32_T qEnd;
  int32_T kEnd;
  for (k = 0; k <= 307199; k += 2) {
    if ((x[k] <= x[k + 1]) || muSingleScalarIsNaN(x[k + 1])) {
      p = true;
    } else {
      p = false;
    }

    if (p) {
      idx[k] = k + 1;
      idx[k + 1] = k + 2;
    } else {
      idx[k] = k + 2;
      idx[k + 1] = k + 1;
    }
  }

  i = 2;
  while (i < 307200) {
    i2 = i << 1;
    j = 1;
    for (pEnd = 1 + i; pEnd < 307201; pEnd = qEnd + i) {
      b_p = j;
      q = pEnd - 1;
      qEnd = j + i2;
      if (qEnd > 307201) {
        qEnd = 307201;
      }

      k = 0;
      kEnd = qEnd - j;
      while (k + 1 <= kEnd) {
        if ((x[idx[b_p - 1] - 1] <= x[idx[q] - 1]) || muSingleScalarIsNaN
            (x[idx[q] - 1])) {
          p = true;
        } else {
          p = false;
        }

        if (p) {
          SD->u1.f1.iwork[k] = idx[b_p - 1];
          b_p++;
          if (b_p == pEnd) {
            while (q + 1 < qEnd) {
              k++;
              SD->u1.f1.iwork[k] = idx[q];
              q++;
            }
          }
        } else {
          SD->u1.f1.iwork[k] = idx[q];
          q++;
          if (q + 1 == qEnd) {
            while (b_p < pEnd) {
              k++;
              SD->u1.f1.iwork[k] = idx[b_p - 1];
              b_p++;
            }
          }
        }

        k++;
      }

      for (k = 0; k + 1 <= kEnd; k++) {
        idx[(j + k) - 1] = SD->u1.f1.iwork[k];
      }

      j = qEnd;
    }

    i = i2;
  }
}

/* End of code generation (mergesort.c) */
