/*
 * Sponsored License - for use in support of a program or activity
 * sponsored by MathWorks.  Not for government, commercial or other
 * non-sponsored organizational use.
 *
 * imfilter.h
 *
 * Code generation for function 'imfilter'
 *
 */

#ifndef IMFILTER_H
#define IMFILTER_H

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
extern void b_imfilter(FindCircleStackData *SD, const emlrtStack *sp, const
  real32_T varargin_1[307200], real32_T b[307200]);
extern void imfilter(FindCircleStackData *SD, const emlrtStack *sp, const
                     real32_T varargin_1[307200], real32_T b[307200]);

#endif

/* End of code generation (imfilter.h) */
