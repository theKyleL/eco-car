/*
 * Sponsored License - for use in support of a program or activity
 * sponsored by MathWorks.  Not for government, commercial or other
 * non-sponsored organizational use.
 *
 * convn.c
 *
 * Code generation for function 'convn'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "FindCircle.h"
#include "convn.h"
#include "xaxpy.h"

/* Function Definitions */
void b_convn(const real32_T A[309444], const real32_T B[9], real32_T C[307200])
{
  int32_T j;
  int32_T k;
  int32_T b_j;
  int32_T iC;
  int32_T c;
  int32_T iB;
  int32_T i;
  int32_T firstRowA;
  memset(&C[0], 0, 307200U * sizeof(real32_T));
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

      iC = b_j * 480 + 1;
      c = k * 482;
      iB = j * 3;
      for (i = 0; i < 3; i++) {
        if (i < 2) {
          firstRowA = 2 - i;
        } else {
          firstRowA = 0;
        }

        xaxpy(482 - (i + firstRowA), B[iB], A, (c + firstRowA) + 1, C, iC);
        iB++;
        if (i >= 2) {
          iC++;
        }
      }

      k++;
    }
  }
}

void convn(const real32_T A[309444], real32_T C[307200])
{
  int32_T j;
  int32_T k;
  int32_T b_j;
  int32_T iC;
  int32_T c;
  int32_T iB;
  int32_T i;
  int32_T firstRowA;
  static const int8_T iv1[9] = { -1, -2, -1, 0, 0, 0, 1, 2, 1 };

  memset(&C[0], 0, 307200U * sizeof(real32_T));
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

      iC = b_j * 480 + 1;
      c = k * 482;
      iB = j * 3;
      for (i = 0; i < 3; i++) {
        if (i < 2) {
          firstRowA = 2 - i;
        } else {
          firstRowA = 0;
        }

        xaxpy(482 - (i + firstRowA), iv1[iB], A, (c + firstRowA) + 1, C, iC);
        iB++;
        if (i >= 2) {
          iC++;
        }
      }

      k++;
    }
  }
}

/* End of code generation (convn.c) */
