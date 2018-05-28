/*
 * Sponsored License - for use in support of a program or activity
 * sponsored by MathWorks.  Not for government, commercial or other
 * non-sponsored organizational use.
 *
 * FindCircle.c
 *
 * Code generation for function 'FindCircle'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "FindCircle.h"
#include "imfindcircles.h"
#include "FindCircle_data.h"

/* Variable Definitions */
static emlrtRSInfo emlrtRSI = { 4,     /* lineNo */
  "FindCircle",                        /* fcnName */
  "C:\\Users\\Austin Musser\\Documents\\ecocaradas\\VisionProcessingSystem\\fromVideoFile\\FindCircle.m"/* pathName */
};

/* Function Definitions */
void FindCircle(FindCircleStackData *SD, const emlrtStack *sp, const uint8_T
                frameBW[921600], emxArray_real_T *centers, emxArray_real_T
                *radii, real_T *foundCircles)
{
  boolean_T x[2];
  int32_T k;
  boolean_T y;
  boolean_T exitg1;
  emlrtStack st;
  st.prev = sp;
  st.tls = sp->tls;
  covrtLogFcn(&emlrtCoverageInstance, 0U, 0U);
  covrtLogBasicBlock(&emlrtCoverageInstance, 0U, 0U);
  st.site = &emlrtRSI;
  imfindcircles(SD, &st, frameBW, centers, radii);
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

  if (covrtLogIf(&emlrtCoverageInstance, 0U, 0U, 0, y)) {
    covrtLogBasicBlock(&emlrtCoverageInstance, 0U, 1U);
    *foundCircles = 1.0;
  } else {
    covrtLogBasicBlock(&emlrtCoverageInstance, 0U, 2U);
    *foundCircles = 0.0;
  }
}

/* End of code generation (FindCircle.c) */
