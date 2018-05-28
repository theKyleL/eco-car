/*
 * Sponsored License - for use in support of a program or activity
 * sponsored by MathWorks.  Not for government, commercial or other
 * non-sponsored organizational use.
 * File: FindCircle_initialize.c
 *
 * MATLAB Coder version            : 3.2
 * C/C++ source code generated on  : 05-Nov-2016 16:55:10
 */

/* Include Files */
#include "rt_nonfinite.h"
#include "FindCircle.h"
#include "FindCircle_initialize.h"
#include "FindCircle_data.h"

/* Function Definitions */

/*
 * Arguments    : void
 * Return Type  : void
 */
void FindCircle_initialize(void)
{
  rt_InitInfAndNaN(8U);
  omp_init_nest_lock(&emlrtNestLockGlobal);
}

/*
 * File trailer for FindCircle_initialize.c
 *
 * [EOF]
 */
