/*
 * Sponsored License - for use in support of a program or activity
 * sponsored by MathWorks.  Not for government, commercial or other
 * non-sponsored organizational use.
 *
 * chaccum.h
 *
 * Code generation for function 'chaccum'
 *
 */

#ifndef CHACCUM_H
#define CHACCUM_H

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
extern void chaccum(FindCircleStackData *SD, const emlrtStack *sp, const uint8_T
                    varargin_1[921600], creal_T accumMatrix[307200], real32_T
                    gradientImg[307200]);

#endif

/* End of code generation (chaccum.h) */
