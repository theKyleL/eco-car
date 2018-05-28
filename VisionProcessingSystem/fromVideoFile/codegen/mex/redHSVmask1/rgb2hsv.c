/*
 * Sponsored License - for use in support of a program or activity
 * sponsored by MathWorks.  Not for government, commercial or other
 * non-sponsored organizational use.
 *
 * rgb2hsv.c
 *
 * Code generation for function 'rgb2hsv'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "redHSVmask1.h"
#include "rgb2hsv.h"
#include "libmwrgb2hsv_tbb.h"

/* Function Definitions */
void rgb2hsv(const uint8_T X[921600], real_T hsv[921600])
{
  rgb2hsv_tbb_uint8(X, 307200.0, hsv);
}

/* End of code generation (rgb2hsv.c) */
