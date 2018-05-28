/*
 * Sponsored License - for use in support of a program or activity
 * sponsored by MathWorks.  Not for government, commercial or other
 * non-sponsored organizational use.
 * File: FindCircle.c
 *
 * MATLAB Coder version            : 3.2
 * C/C++ source code generated on  : 05-Nov-2016 16:55:10
 */

/* Include Files */
#include "rt_nonfinite.h"
#include "FindCircle.h"
#include "imfindcircles.h"

/* Function Definitions */

/*
 * Arguments    : const unsigned char frameBW[921600]
 *                emxArray_real_T *centers
 *                emxArray_real_T *radii
 *                double *foundCircles
 * Return Type  : void
 */
void FindCircle(const unsigned char frameBW[921600], emxArray_real_T *centers,
                emxArray_real_T *radii, double *foundCircles)
{
  boolean_T x[2];
  int k;
  boolean_T y;
  boolean_T exitg1;
  imfindcircles(frameBW, centers, radii);
  for (k = 0; k < 2; k++) {
    x[k] = (centers->size[k] > 0);
  }

  y = true;
  k = 1;
  exitg1 = false;
  while ((!exitg1) && (k < 3)) {
    if (!x[k - 1]) {
      y = false;
      exitg1 = true;
    } else {
      k++;
    }
  }

  *foundCircles = y;
}

/*
 * File trailer for FindCircle.c
 *
 * [EOF]
 */
