/*
 * Sponsored License - for use in support of a program or activity
 * sponsored by MathWorks.  Not for government, commercial or other
 * non-sponsored organizational use.
 *
 * isfinite.c
 *
 * Code generation for function 'isfinite'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "FindCircle.h"
#include "isfinite.h"

/* Function Definitions */
boolean_T b_isfinite(real32_T x)
{
  return (!muSingleScalarIsInf(x)) && (!muSingleScalarIsNaN(x));
}

/* End of code generation (isfinite.c) */
