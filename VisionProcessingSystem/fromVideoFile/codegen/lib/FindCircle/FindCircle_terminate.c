/*
 * Sponsored License - for use in support of a program or activity
 * sponsored by MathWorks.  Not for government, commercial or other
 * non-sponsored organizational use.
 * File: FindCircle_terminate.c
 *
 * MATLAB Coder version            : 3.2
 * C/C++ source code generated on  : 05-Nov-2016 16:55:10
 */

/* Include Files */
#include "rt_nonfinite.h"
#include "FindCircle.h"
#include "FindCircle_terminate.h"
#include "FindCircle_data.h"

/* Function Definitions */

/*
 * Arguments    : void
 * Return Type  : void
 */
void FindCircle_terminate(void)
{
  omp_destroy_nest_lock(&emlrtNestLockGlobal);
}

/*
 * File trailer for FindCircle_terminate.c
 *
 * [EOF]
 */
