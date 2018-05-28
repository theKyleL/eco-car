/*
 * Sponsored License - for use in support of a program or activity
 * sponsored by MathWorks.  Not for government, commercial or other
 * non-sponsored organizational use.
 *
 * imfindcircles.h
 *
 * Code generation for function 'imfindcircles'
 *
 */

#ifndef IMFINDCIRCLES_H
#define IMFINDCIRCLES_H

/* Include files */
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mwmathutil.h"
#include "tmwtypes.h"
#include "mex.h"
#include "emlrt.h"
#include "covrt.h"
#include "rtwtypes.h"
#include "FindCircle_types.h"

/* Function Declarations */
extern void imfindcircles(FindCircleStackData *SD, const emlrtStack *sp, const
  uint8_T varargin_1[921600], emxArray_real_T *centers, emxArray_real_T
  *r_estimated);

#endif

/* End of code generation (imfindcircles.h) */
