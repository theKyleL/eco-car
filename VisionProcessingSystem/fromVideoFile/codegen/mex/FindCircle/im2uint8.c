/*
 * Sponsored License - for use in support of a program or activity
 * sponsored by MathWorks.  Not for government, commercial or other
 * non-sponsored organizational use.
 *
 * im2uint8.c
 *
 * Code generation for function 'im2uint8'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "FindCircle.h"
#include "im2uint8.h"
#include "FindCircle_emxutil.h"
#include "libmwgrayto8.h"

/* Variable Definitions */
static emlrtRSInfo ub_emlrtRSI = { 39, /* lineNo */
  "im2uint8",                          /* fcnName */
  "C:\\Program Files\\MATLAB\\R2016b\\toolbox\\images\\images\\eml\\im2uint8.m"/* pathName */
};

static emlrtRSInfo vb_emlrtRSI = { 95, /* lineNo */
  "im2uint8",                          /* fcnName */
  "C:\\Program Files\\MATLAB\\R2016b\\toolbox\\images\\images\\eml\\im2uint8.m"/* pathName */
};

static emlrtRTEInfo u_emlrtRTEI = { 1, /* lineNo */
  14,                                  /* colNo */
  "im2uint8",                          /* fName */
  "C:\\Program Files\\MATLAB\\R2016b\\toolbox\\images\\images\\eml\\im2uint8.m"/* pName */
};

/* Function Definitions */
void im2uint8(const emlrtStack *sp, const emxArray_real32_T *img,
              emxArray_uint8_T *u)
{
  int32_T i8;
  emlrtStack st;
  emlrtStack b_st;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &ub_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  b_st.site = &vb_emlrtRSI;
  i8 = u->size[0];
  u->size[0] = img->size[0];
  emxEnsureCapacity(&b_st, (emxArray__common *)u, i8, (int32_T)sizeof(uint8_T),
                    &u_emlrtRTEI);
  grayto8_real32(&img->data[0], &u->data[0], (real_T)img->size[0]);
}

/* End of code generation (im2uint8.c) */
