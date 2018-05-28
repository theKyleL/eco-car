/*
 * Sponsored License - for use in support of a program or activity
 * sponsored by MathWorks.  Not for government, commercial or other
 * non-sponsored organizational use.
 *
 * xaxpy.c
 *
 * Code generation for function 'xaxpy'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "FindCircle.h"
#include "xaxpy.h"
#include "blas.h"

/* Function Definitions */
void xaxpy(int32_T n, real32_T a, const real32_T x[309444], int32_T ix0,
           real32_T y[307200], int32_T iy0)
{
  ptrdiff_t n_t;
  ptrdiff_t incx_t;
  ptrdiff_t incy_t;
  n_t = (ptrdiff_t)n;
  incx_t = (ptrdiff_t)1;
  incy_t = (ptrdiff_t)1;
  saxpy(&n_t, &a, &x[ix0 - 1], &incx_t, &y[iy0 - 1], &incy_t);
}

/* End of code generation (xaxpy.c) */
