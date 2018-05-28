/*
 * Sponsored License - for use in support of a program or activity
 * sponsored by MathWorks.  Not for government, commercial or other
 * non-sponsored organizational use.
 *
 * imhist.h
 *
 * Code generation for function 'imhist'
 *
 */

#ifndef IMHIST_H
#define IMHIST_H

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
extern void imhist(const emlrtStack *sp, const emxArray_uint8_T *varargin_1,
                   real_T yout[256]);

#endif

/* End of code generation (imhist.h) */
