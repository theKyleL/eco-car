/*
 * Sponsored License - for use in support of a program or activity
 * sponsored by MathWorks.  Not for government, commercial or other
 * non-sponsored organizational use.
 *
 * find.c
 *
 * Code generation for function 'find'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "FindCircle.h"
#include "find.h"
#include "FindCircle_emxutil.h"
#include "indexShapeCheck.h"
#include "FindCircle_data.h"

/* Variable Definitions */
static emlrtRTEInfo cb_emlrtRTEI = { 50,/* lineNo */
  20,                                  /* colNo */
  "find",                              /* fName */
  "C:\\Program Files\\MATLAB\\R2016b\\toolbox\\eml\\lib\\matlab\\elmat\\find.m"/* pName */
};

static emlrtRTEInfo db_emlrtRTEI = { 186,/* lineNo */
  13,                                  /* colNo */
  "find",                              /* fName */
  "C:\\Program Files\\MATLAB\\R2016b\\toolbox\\eml\\lib\\matlab\\elmat\\find.m"/* pName */
};

static emlrtRTEInfo eb_emlrtRTEI = { 187,/* lineNo */
  13,                                  /* colNo */
  "find",                              /* fName */
  "C:\\Program Files\\MATLAB\\R2016b\\toolbox\\eml\\lib\\matlab\\elmat\\find.m"/* pName */
};

/* Function Definitions */
void eml_find(const emlrtStack *sp, const boolean_T x[307200], emxArray_int32_T *
              i, emxArray_int32_T *j)
{
  int32_T idx;
  int32_T ii;
  int32_T jj;
  boolean_T exitg1;
  boolean_T guard1 = false;
  int32_T iv11[2];
  int32_T iv12[2];
  int32_T iv13[2];
  emlrtStack st;
  st.prev = sp;
  st.tls = sp->tls;
  idx = 0;
  ii = i->size[0];
  i->size[0] = 307200;
  emxEnsureCapacity(sp, (emxArray__common *)i, ii, (int32_T)sizeof(int32_T),
                    &cb_emlrtRTEI);
  ii = j->size[0];
  j->size[0] = 307200;
  emxEnsureCapacity(sp, (emxArray__common *)j, ii, (int32_T)sizeof(int32_T),
                    &cb_emlrtRTEI);
  ii = 1;
  jj = 1;
  exitg1 = false;
  while ((!exitg1) && (jj <= 640)) {
    guard1 = false;
    if (x[(ii + 480 * (jj - 1)) - 1]) {
      idx++;
      i->data[idx - 1] = ii;
      j->data[idx - 1] = jj;
      if (idx >= 307200) {
        exitg1 = true;
      } else {
        guard1 = true;
      }
    } else {
      guard1 = true;
    }

    if (guard1) {
      ii++;
      if (ii > 480) {
        ii = 1;
        jj++;
      }
    }
  }

  if (1 > idx) {
    ii = 0;
  } else {
    ii = idx;
  }

  iv11[0] = 1;
  iv11[1] = ii;
  st.site = &ud_emlrtRSI;
  indexShapeCheck(&st, 307200, iv11);
  jj = i->size[0];
  i->size[0] = ii;
  emxEnsureCapacity(sp, (emxArray__common *)i, jj, (int32_T)sizeof(int32_T),
                    &db_emlrtRTEI);
  if (1 > idx) {
    ii = 0;
  } else {
    ii = idx;
  }

  iv12[0] = 1;
  iv12[1] = ii;
  st.site = &td_emlrtRSI;
  indexShapeCheck(&st, 307200, iv12);
  jj = j->size[0];
  j->size[0] = ii;
  emxEnsureCapacity(sp, (emxArray__common *)j, jj, (int32_T)sizeof(int32_T),
                    &eb_emlrtRTEI);
  iv13[0] = 1;
  if (1 > idx) {
    iv13[1] = 0;
  } else {
    iv13[1] = idx;
  }

  st.site = &sd_emlrtRSI;
  indexShapeCheck(&st, 307200, iv13);
}

/* End of code generation (find.c) */
