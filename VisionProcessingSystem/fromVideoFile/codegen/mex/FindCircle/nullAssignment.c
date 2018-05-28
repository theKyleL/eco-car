/*
 * Sponsored License - for use in support of a program or activity
 * sponsored by MathWorks.  Not for government, commercial or other
 * non-sponsored organizational use.
 *
 * nullAssignment.c
 *
 * Code generation for function 'nullAssignment'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "FindCircle.h"
#include "nullAssignment.h"
#include "FindCircle_emxutil.h"

/* Variable Definitions */
static emlrtRSInfo qc_emlrtRSI = { 12, /* lineNo */
  "nullAssignment",                    /* fcnName */
  "C:\\Program Files\\MATLAB\\R2016b\\toolbox\\eml\\eml\\+coder\\+internal\\nullAssignment.m"/* pathName */
};

static emlrtRSInfo rc_emlrtRSI = { 16, /* lineNo */
  "nullAssignment",                    /* fcnName */
  "C:\\Program Files\\MATLAB\\R2016b\\toolbox\\eml\\eml\\+coder\\+internal\\nullAssignment.m"/* pathName */
};

static emlrtRTEInfo wb_emlrtRTEI = { 183,/* lineNo */
  9,                                   /* colNo */
  "nullAssignment",                    /* fName */
  "C:\\Program Files\\MATLAB\\R2016b\\toolbox\\eml\\eml\\+coder\\+internal\\nullAssignment.m"/* pName */
};

static emlrtRTEInfo ed_emlrtRTEI = { 182,/* lineNo */
  9,                                   /* colNo */
  "nullAssignment",                    /* fName */
  "C:\\Program Files\\MATLAB\\R2016b\\toolbox\\eml\\eml\\+coder\\+internal\\nullAssignment.m"/* pName */
};

static emlrtRTEInfo fd_emlrtRTEI = { 83,/* lineNo */
  27,                                  /* colNo */
  "nullAssignment",                    /* fName */
  "C:\\Program Files\\MATLAB\\R2016b\\toolbox\\eml\\eml\\+coder\\+internal\\nullAssignment.m"/* pName */
};

/* Function Definitions */
void nullAssignment(const emlrtStack *sp, emxArray_real32_T *x, const
                    emxArray_boolean_T *idx)
{
  int32_T k;
  int32_T nxin;
  int32_T k0;
  int32_T nxout;
  emlrtStack st;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &qc_emlrtRSI;
  k = idx->size[1];
  while ((k >= 1) && (!idx->data[k - 1])) {
    k--;
  }

  if (!(k <= x->size[1])) {
    emlrtErrorWithMessageIdR2012b(&st, &fd_emlrtRTEI,
      "MATLAB:subsdeldimmismatch", 0);
  }

  st.site = &rc_emlrtRSI;
  nxin = x->size[1];
  k0 = 0;
  for (k = 1; k <= idx->size[1]; k++) {
    k0 += idx->data[k - 1];
  }

  nxout = x->size[1] - k0;
  k0 = -1;
  for (k = 1; k <= nxin; k++) {
    if ((k > idx->size[1]) || (!idx->data[k - 1])) {
      k0++;
      x->data[k0] = x->data[k - 1];
    }
  }

  if (!(nxout <= nxin)) {
    emlrtErrorWithMessageIdR2012b(&st, &ed_emlrtRTEI,
      "Coder:builtins:AssertionFailed", 0);
  }

  k0 = x->size[0] * x->size[1];
  if (1 > nxout) {
    x->size[1] = 0;
  } else {
    x->size[1] = nxout;
  }

  emxEnsureCapacity(&st, (emxArray__common *)x, k0, (int32_T)sizeof(real32_T),
                    &wb_emlrtRTEI);
}

/* End of code generation (nullAssignment.c) */
