/*
 * Sponsored License - for use in support of a program or activity
 * sponsored by MathWorks.  Not for government, commercial or other
 * non-sponsored organizational use.
 *
 * validateattributes.c
 *
 * Code generation for function 'validateattributes'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "FindCircle.h"
#include "validateattributes.h"
#include "FindCircle_data.h"

/* Function Definitions */
void validateattributes(const emlrtStack *sp, const real_T a[307200])
{
  boolean_T p;
  int32_T k;
  boolean_T exitg1;
  p = true;
  k = 0;
  exitg1 = false;
  while ((!exitg1) && (k < 307200)) {
    if (!muDoubleScalarIsNaN(a[k])) {
      k++;
    } else {
      p = false;
      exitg1 = true;
    }
  }

  if (!p) {
    emlrtErrMsgIdAndExplicitTxt(sp, &oc_emlrtRTEI,
      "MATLAB:imreconstruct:expectedNonNaN", 29, "Expected input to be non-NaN.");
  }
}

/* End of code generation (validateattributes.c) */
