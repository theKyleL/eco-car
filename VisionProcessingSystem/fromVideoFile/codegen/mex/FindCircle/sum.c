/*
 * Sponsored License - for use in support of a program or activity
 * sponsored by MathWorks.  Not for government, commercial or other
 * non-sponsored organizational use.
 *
 * sum.c
 *
 * Code generation for function 'sum'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "FindCircle.h"
#include "sum.h"
#include "eml_int_forloop_overflow_check.h"
#include "FindCircle_data.h"

/* Variable Definitions */
static emlrtRTEInfo ad_emlrtRTEI = { 20,/* lineNo */
  15,                                  /* colNo */
  "sumprod",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2016b\\toolbox\\eml\\lib\\matlab\\datafun\\private\\sumprod.m"/* pName */
};

static emlrtRTEInfo bd_emlrtRTEI = { 48,/* lineNo */
  9,                                   /* colNo */
  "sumprod",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2016b\\toolbox\\eml\\lib\\matlab\\datafun\\private\\sumprod.m"/* pName */
};

/* Function Definitions */
real_T b_sum(const emlrtStack *sp, const emxArray_real_T *x)
{
  real_T y;
  boolean_T overflow;
  boolean_T p;
  int32_T k;
  int32_T exitg1;
  int32_T i26;
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &yf_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  if ((x->size[0] == 1) || (x->size[0] != 1)) {
    overflow = true;
  } else {
    overflow = false;
  }

  if (!overflow) {
    emlrtErrorWithMessageIdR2012b(&st, &ad_emlrtRTEI,
      "Coder:toolbox:autoDimIncompatibility", 0);
  }

  overflow = false;
  p = false;
  k = 0;
  do {
    exitg1 = 0;
    if (k < 2) {
      if (k + 1 <= 1) {
        i26 = x->size[0];
      } else {
        i26 = 1;
      }

      if (i26 != 0) {
        exitg1 = 1;
      } else {
        k++;
      }
    } else {
      p = true;
      exitg1 = 1;
    }
  } while (exitg1 == 0);

  if (p) {
    overflow = true;
  }

  if (overflow) {
    emlrtErrorWithMessageIdR2012b(&st, &bd_emlrtRTEI,
      "Coder:toolbox:UnsupportedSpecialEmpty", 0);
  }

  b_st.site = &ag_emlrtRSI;
  if (x->size[0] == 0) {
    y = 0.0;
  } else {
    y = x->data[0];
    c_st.site = &bg_emlrtRSI;
    overflow = ((!(2 > x->size[0])) && (x->size[0] > 2147483646));
    if (overflow) {
      d_st.site = &w_emlrtRSI;
      check_forloop_overflow_error(&d_st);
    }

    for (k = 2; k <= x->size[0]; k++) {
      y += x->data[k - 1];
    }
  }

  return y;
}

real_T sum(const real_T x[256])
{
  real_T y;
  int32_T k;
  y = x[0];
  for (k = 0; k < 255; k++) {
    y += x[k + 1];
  }

  return y;
}

/* End of code generation (sum.c) */
