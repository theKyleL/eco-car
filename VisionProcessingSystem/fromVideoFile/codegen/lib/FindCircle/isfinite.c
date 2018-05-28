/*
 * Sponsored License - for use in support of a program or activity
 * sponsored by MathWorks.  Not for government, commercial or other
 * non-sponsored organizational use.
 * File: isfinite.c
 *
 * MATLAB Coder version            : 3.2
 * C/C++ source code generated on  : 05-Nov-2016 16:55:10
 */

/* Include Files */
#include "rt_nonfinite.h"
#include "FindCircle.h"
#include "isfinite.h"

/* Function Definitions */

/*
 * Arguments    : float x
 * Return Type  : boolean_T
 */
boolean_T b_isfinite(float x)
{
  return (!rtIsInfF(x)) && (!rtIsNaNF(x));
}

/*
 * File trailer for isfinite.c
 *
 * [EOF]
 */
