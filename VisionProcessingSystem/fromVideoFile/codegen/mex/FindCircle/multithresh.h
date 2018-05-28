/*
 * Sponsored License - for use in support of a program or activity
 * sponsored by MathWorks.  Not for government, commercial or other
 * non-sponsored organizational use.
 *
 * multithresh.h
 *
 * Code generation for function 'multithresh'
 *
 */

#ifndef MULTITHRESH_H
#define MULTITHRESH_H

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
extern real32_T multithresh(FindCircleStackData *SD, const emlrtStack *sp, const
  real32_T varargin_1[307200]);

#ifdef __WATCOMC__

#pragma aux multithresh value [8087];

#endif
#endif

/* End of code generation (multithresh.h) */
