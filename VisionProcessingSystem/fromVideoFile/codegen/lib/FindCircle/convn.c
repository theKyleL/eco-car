/*
 * Sponsored License - for use in support of a program or activity
 * sponsored by MathWorks.  Not for government, commercial or other
 * non-sponsored organizational use.
 * File: convn.c
 *
 * MATLAB Coder version            : 3.2
 * C/C++ source code generated on  : 05-Nov-2016 16:55:10
 */

/* Include Files */
#include "rt_nonfinite.h"
#include "FindCircle.h"
#include "convn.h"

/* Function Definitions */

/*
 * Arguments    : const float A[309444]
 *                const float B[9]
 *                float C[307200]
 * Return Type  : void
 */
void convn(const float A[309444], const float B[9], float C[307200])
{
  int j;
  int k;
  int b_j;
  int iC;
  int c;
  int iB;
  int i;
  int firstRowA;
  int a_length;
  int cidx;
  int r;
  memset(&C[0], 0, 307200U * sizeof(float));
  for (j = 0; j < 3; j++) {
    if (j < 2) {
      k = 2 - j;
    } else {
      k = 0;
    }

    while (k <= 641 - j) {
      if (j + k > 2) {
        b_j = (j + k) - 2;
      } else {
        b_j = 0;
      }

      iC = b_j * 480;
      c = k * 482;
      iB = j * 3;
      for (i = 0; i < 3; i++) {
        if (i < 2) {
          firstRowA = 2 - i;
        } else {
          firstRowA = 0;
        }

        a_length = 482 - (i + firstRowA);
        firstRowA += c;
        cidx = iC;
        for (r = 1; r <= a_length; r++) {
          C[cidx] += B[iB] * A[firstRowA];
          firstRowA++;
          cidx++;
        }

        iB++;
        if (i >= 2) {
          iC++;
        }
      }

      k++;
    }
  }
}

/*
 * File trailer for convn.c
 *
 * [EOF]
 */
