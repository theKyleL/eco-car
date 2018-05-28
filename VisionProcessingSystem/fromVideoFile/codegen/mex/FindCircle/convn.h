/*
 * Sponsored License - for use in support of a program or activity
 * sponsored by MathWorks.  Not for government, commercial or other
 * non-sponsored organizational use.
 *
 * convn.h
 *
 * Code generation for function 'convn'
 *
 */

#ifndef CONVN_H
#define CONVN_H

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
extern void b_convn(const real32_T A[309444], const real32_T B[9], real32_T C
                    [307200]);
extern void convn(const real32_T A[309444], real32_T C[307200]);

#endif

/* End of code generation (convn.h) */
