/*
 * Sponsored License - for use in support of a program or activity
 * sponsored by MathWorks.  Not for government, commercial or other
 * non-sponsored organizational use.
 *
 * abs.c
 *
 * Code generation for function 'abs'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "FindCircle.h"
#include "abs.h"
#include "FindCircle_emxutil.h"

/* Variable Definitions */
static emlrtRSInfo vc_emlrtRSI = { 16, /* lineNo */
  "abs",                               /* fcnName */
  "C:\\Program Files\\MATLAB\\R2016b\\toolbox\\eml\\lib\\matlab\\elfun\\abs.m"/* pathName */
};

static emlrtRTEInfo y_emlrtRTEI = { 1, /* lineNo */
  14,                                  /* colNo */
  "abs",                               /* fName */
  "C:\\Program Files\\MATLAB\\R2016b\\toolbox\\eml\\lib\\matlab\\elfun\\abs.m"/* pName */
};

/* Function Definitions */
void b_abs(const emlrtStack *sp, const emxArray_real_T *x, emxArray_real_T *y)
{
  int32_T x_idx_0;
  int32_T i13;
  emlrtStack st;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &vc_emlrtRSI;
  x_idx_0 = x->size[0];
  i13 = y->size[0];
  y->size[0] = x_idx_0;
  emxEnsureCapacity(&st, (emxArray__common *)y, i13, (int32_T)sizeof(real_T),
                    &y_emlrtRTEI);
  for (x_idx_0 = 0; x_idx_0 + 1 <= x->size[0]; x_idx_0++) {
    y->data[x_idx_0] = muDoubleScalarAbs(x->data[x_idx_0]);
  }
}

/* End of code generation (abs.c) */
