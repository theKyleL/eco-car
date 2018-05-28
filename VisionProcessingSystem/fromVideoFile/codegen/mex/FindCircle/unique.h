/*
 * Sponsored License - for use in support of a program or activity
 * sponsored by MathWorks.  Not for government, commercial or other
 * non-sponsored organizational use.
 *
 * unique.h
 *
 * Code generation for function 'unique'
 *
 */

#ifndef UNIQUE_H
#define UNIQUE_H

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
extern void count_nonfinites(const emxArray_real32_T *b, int32_T *nMInf, int32_T
  *nFinite, int32_T *nPInf, int32_T *nNaN);

#endif

/* End of code generation (unique.h) */
