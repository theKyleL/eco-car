/*
 * Sponsored License - for use in support of a program or activity
 * sponsored by MathWorks.  Not for government, commercial or other
 * non-sponsored organizational use.
 * File: unique.h
 *
 * MATLAB Coder version            : 3.2
 * C/C++ source code generated on  : 05-Nov-2016 16:55:10
 */

#ifndef UNIQUE_H
#define UNIQUE_H

/* Include Files */
#include <math.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include "rt_defines.h"
#include "rt_nonfinite.h"
#include "rtwtypes.h"
#include "omp.h"
#include "FindCircle_types.h"

/* Function Declarations */
extern void count_nonfinites(const emxArray_real32_T *b, int *nMInf, int
  *nFinite, int *nPInf, int *nNaN);

#endif

/*
 * File trailer for unique.h
 *
 * [EOF]
 */
