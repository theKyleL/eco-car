/*
 * Sponsored License - for use in support of a program or activity
 * sponsored by MathWorks.  Not for government, commercial or other
 * non-sponsored organizational use.
 *
 * rgb2gray.c
 *
 * Code generation for function 'rgb2gray'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "FindCircle.h"
#include "rgb2gray.h"
#include "libmwrgb2gray_tbb.h"

/* Function Definitions */
void rgb2gray(const uint8_T X[921600], uint8_T I[307200])
{
  rgb2gray_tbb_uint8(X, 307200.0, I);
}

/* End of code generation (rgb2gray.c) */
