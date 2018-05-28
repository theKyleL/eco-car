/*
 * Sponsored License - for use in support of a program or activity
 * sponsored by MathWorks.  Not for government, commercial or other
 * non-sponsored organizational use.
 *
 * chcenters.h
 *
 * Code generation for function 'chcenters'
 *
 */

#ifndef CHCENTERS_H
#define CHCENTERS_H

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
extern void chcenters(FindCircleStackData *SD, const emlrtStack *sp, const
                      creal_T varargin_1[307200], emxArray_real_T *centers,
                      emxArray_real_T *metric);

#endif

/* End of code generation (chcenters.h) */
