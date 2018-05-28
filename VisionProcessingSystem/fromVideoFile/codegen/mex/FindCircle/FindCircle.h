/*
 * Sponsored License - for use in support of a program or activity
 * sponsored by MathWorks.  Not for government, commercial or other
 * non-sponsored organizational use.
 *
 * FindCircle.h
 *
 * Code generation for function 'FindCircle'
 *
 */

#ifndef FINDCIRCLE_H
#define FINDCIRCLE_H

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
extern void FindCircle(FindCircleStackData *SD, const emlrtStack *sp, const
  uint8_T frameBW[921600], emxArray_real_T *centers, emxArray_real_T *radii,
  real_T *foundCircles);

#endif

/* End of code generation (FindCircle.h) */
