/*
 * Sponsored License - for use in support of a program or activity
 * sponsored by MathWorks.  Not for government, commercial or other
 * non-sponsored organizational use.
 *
 * ordfilt2.c
 *
 * Code generation for function 'ordfilt2'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "FindCircle.h"
#include "ordfilt2.h"
#include "toLogicalCheck.h"
#include "FindCircle_emxutil.h"
#include "padarray.h"
#include "abs.h"
#include "indexShapeCheck.h"
#include "FindCircle_data.h"
#include "libmwordfilt2.h"

/* Variable Definitions */
static emlrtRSInfo ie_emlrtRSI = { 25, /* lineNo */
  "ordfilt2",                          /* fcnName */
  "C:\\Program Files\\MATLAB\\R2016b\\toolbox\\images\\images\\eml\\ordfilt2.m"/* pathName */
};

static emlrtRSInfo je_emlrtRSI = { 83, /* lineNo */
  "ordfilt2",                          /* fcnName */
  "C:\\Program Files\\MATLAB\\R2016b\\toolbox\\images\\images\\eml\\ordfilt2.m"/* pathName */
};

static emlrtRSInfo ke_emlrtRSI = { 99, /* lineNo */
  "ordfilt2",                          /* fcnName */
  "C:\\Program Files\\MATLAB\\R2016b\\toolbox\\images\\images\\eml\\ordfilt2.m"/* pathName */
};

static emlrtRSInfo le_emlrtRSI = { 102,/* lineNo */
  "ordfilt2",                          /* fcnName */
  "C:\\Program Files\\MATLAB\\R2016b\\toolbox\\images\\images\\eml\\ordfilt2.m"/* pathName */
};

static emlrtRSInfo me_emlrtRSI = { 116,/* lineNo */
  "ordfilt2",                          /* fcnName */
  "C:\\Program Files\\MATLAB\\R2016b\\toolbox\\images\\images\\eml\\ordfilt2.m"/* pathName */
};

static emlrtRSInfo ne_emlrtRSI = { 13, /* lineNo */
  "max",                               /* fcnName */
  "C:\\Program Files\\MATLAB\\R2016b\\toolbox\\eml\\lib\\matlab\\datafun\\max.m"/* pathName */
};

static emlrtRSInfo oe_emlrtRSI = { 19, /* lineNo */
  "minOrMax",                          /* fcnName */
  "C:\\Program Files\\MATLAB\\R2016b\\toolbox\\eml\\eml\\+coder\\+internal\\minOrMax.m"/* pathName */
};

static emlrtRSInfo we_emlrtRSI = { 140,/* lineNo */
  "ordfilt2",                          /* fcnName */
  "C:\\Program Files\\MATLAB\\R2016b\\toolbox\\images\\images\\eml\\ordfilt2.m"/* pathName */
};

static emlrtRTEInfo hb_emlrtRTEI = { 1,/* lineNo */
  14,                                  /* colNo */
  "ordfilt2",                          /* fName */
  "C:\\Program Files\\MATLAB\\R2016b\\toolbox\\images\\images\\eml\\ordfilt2.m"/* pName */
};

static emlrtRTEInfo ib_emlrtRTEI = { 102,/* lineNo */
  5,                                   /* colNo */
  "ordfilt2",                          /* fName */
  "C:\\Program Files\\MATLAB\\R2016b\\toolbox\\images\\images\\eml\\ordfilt2.m"/* pName */
};

static emlrtRTEInfo rc_emlrtRTEI = { 121,/* lineNo */
  27,                                  /* colNo */
  "minOrMax",                          /* fName */
  "C:\\Program Files\\MATLAB\\R2016b\\toolbox\\eml\\eml\\+coder\\+internal\\minOrMax.m"/* pName */
};

static emlrtRTEInfo sc_emlrtRTEI = { 39,/* lineNo */
  27,                                  /* colNo */
  "minOrMax",                          /* fName */
  "C:\\Program Files\\MATLAB\\R2016b\\toolbox\\eml\\eml\\+coder\\+internal\\minOrMax.m"/* pName */
};

static emlrtECInfo c_emlrtECI = { -1,  /* nDims */
  114,                                 /* lineNo */
  25,                                  /* colNo */
  "ordfilt2",                          /* fName */
  "C:\\Program Files\\MATLAB\\R2016b\\toolbox\\images\\images\\eml\\ordfilt2.m"/* pName */
};

/* Function Definitions */
void ordfilt2(const emlrtStack *sp, const real_T varargin_1[307200], real_T B
              [307200])
{
  int32_T idx;
  int32_T indices_data[25];
  int8_T jj_data[25];
  int32_T ii;
  int32_T jj;
  boolean_T exitg3;
  int32_T loop_ub;
  int32_T iv16[2];
  int32_T iv17[2];
  int32_T iv18[2];
  int32_T rows_size[1];
  int32_T i18;
  int32_T cols_size[1];
  real_T rows_data[25];
  emxArray_real_T *r5;
  real_T cols_data[25];
  emxArray_real_T b_rows_data;
  real_T varargin_1_data[25];
  boolean_T b2;
  real_T padSize;
  boolean_T exitg2;
  emxArray_real_T b_cols_data;
  real_T mtmp;
  boolean_T exitg1;
  real_T b_padSize[2];
  emxArray_real_T *Apad;
  emxArray_real_T *y;
  real_T startIdx[2];
  real_T dv1[2];
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b(sp);
  st.site = &ie_emlrtRSI;
  toLogicalCheck();
  st.site = &je_emlrtRSI;
  b_st.site = &rd_emlrtRSI;
  idx = 0;
  ii = 1;
  jj = 1;
  exitg3 = false;
  while ((!exitg3) && (jj <= 5)) {
    idx++;
    indices_data[idx - 1] = ii;
    jj_data[idx - 1] = (int8_T)jj;
    if (idx >= 25) {
      exitg3 = true;
    } else {
      ii++;
      if (ii > 5) {
        ii = 1;
        jj++;
      }
    }
  }

  if (1 > idx) {
    loop_ub = 0;
  } else {
    loop_ub = idx;
  }

  iv16[0] = 1;
  iv16[1] = loop_ub;
  c_st.site = &ud_emlrtRSI;
  indexShapeCheck(&c_st, 25, iv16);
  if (1 > idx) {
    ii = 0;
  } else {
    ii = idx;
  }

  iv17[0] = 1;
  iv17[1] = ii;
  c_st.site = &td_emlrtRSI;
  indexShapeCheck(&c_st, 25, iv17);
  iv18[0] = 1;
  if (1 > idx) {
    iv18[1] = 0;
  } else {
    iv18[1] = idx;
  }

  c_st.site = &sd_emlrtRSI;
  indexShapeCheck(&c_st, 25, iv18);
  rows_size[0] = loop_ub;
  for (i18 = 0; i18 < loop_ub; i18++) {
    rows_data[i18] = (real_T)indices_data[i18] - 3.0;
  }

  cols_size[0] = ii;
  for (i18 = 0; i18 < ii; i18++) {
    cols_data[i18] = (real_T)jj_data[i18] - 3.0;
  }

  emxInit_real_T(sp, &r5, 1, &hb_emlrtRTEI, true);
  st.site = &ke_emlrtRSI;
  b_rows_data.data = (real_T *)&rows_data;
  b_rows_data.size = (int32_T *)&rows_size;
  b_rows_data.allocatedSize = 25;
  b_rows_data.numDimensions = 1;
  b_rows_data.canFreeData = false;
  b_st.site = &ke_emlrtRSI;
  b_abs(&b_st, &b_rows_data, r5);
  idx = r5->size[0];
  loop_ub = r5->size[0];
  for (i18 = 0; i18 < loop_ub; i18++) {
    varargin_1_data[i18] = r5->data[i18];
  }

  b_st.site = &ne_emlrtRSI;
  c_st.site = &oe_emlrtRSI;
  if ((idx == 1) || (idx != 1)) {
    b2 = true;
  } else {
    b2 = false;
  }

  if (!b2) {
    emlrtErrorWithMessageIdR2012b(&c_st, &sc_emlrtRTEI,
      "Coder:toolbox:autoDimIncompatibility", 0);
  }

  if (!(idx > 0)) {
    emlrtErrorWithMessageIdR2012b(&c_st, &rc_emlrtRTEI,
      "Coder:toolbox:eml_min_or_max_varDimZero", 0);
  }

  ii = 1;
  padSize = varargin_1_data[0];
  if (idx > 1) {
    if (muDoubleScalarIsNaN(varargin_1_data[0])) {
      jj = 2;
      exitg2 = false;
      while ((!exitg2) && (jj <= idx)) {
        ii = jj;
        if (!muDoubleScalarIsNaN(varargin_1_data[jj - 1])) {
          padSize = varargin_1_data[jj - 1];
          exitg2 = true;
        } else {
          jj++;
        }
      }
    }

    if (ii < idx) {
      while (ii + 1 <= idx) {
        if (varargin_1_data[ii] > padSize) {
          padSize = varargin_1_data[ii];
        }

        ii++;
      }
    }
  }

  st.site = &ke_emlrtRSI;
  b_cols_data.data = (real_T *)&cols_data;
  b_cols_data.size = (int32_T *)&cols_size;
  b_cols_data.allocatedSize = 25;
  b_cols_data.numDimensions = 1;
  b_cols_data.canFreeData = false;
  b_st.site = &ke_emlrtRSI;
  b_abs(&b_st, &b_cols_data, r5);
  idx = r5->size[0];
  loop_ub = r5->size[0];
  for (i18 = 0; i18 < loop_ub; i18++) {
    varargin_1_data[i18] = r5->data[i18];
  }

  emxFree_real_T(&r5);
  b_st.site = &ne_emlrtRSI;
  c_st.site = &oe_emlrtRSI;
  if ((idx == 1) || (idx != 1)) {
    b2 = true;
  } else {
    b2 = false;
  }

  if (!b2) {
    emlrtErrorWithMessageIdR2012b(&c_st, &sc_emlrtRTEI,
      "Coder:toolbox:autoDimIncompatibility", 0);
  }

  if (!(idx > 0)) {
    emlrtErrorWithMessageIdR2012b(&c_st, &rc_emlrtRTEI,
      "Coder:toolbox:eml_min_or_max_varDimZero", 0);
  }

  ii = 1;
  mtmp = varargin_1_data[0];
  if (idx > 1) {
    if (muDoubleScalarIsNaN(varargin_1_data[0])) {
      jj = 2;
      exitg1 = false;
      while ((!exitg1) && (jj <= idx)) {
        ii = jj;
        if (!muDoubleScalarIsNaN(varargin_1_data[jj - 1])) {
          mtmp = varargin_1_data[jj - 1];
          exitg1 = true;
        } else {
          jj++;
        }
      }
    }

    if (ii < idx) {
      while (ii + 1 <= idx) {
        if (varargin_1_data[ii] > mtmp) {
          mtmp = varargin_1_data[ii];
        }

        ii++;
      }
    }
  }

  padSize = muDoubleScalarMax(padSize, mtmp);
  for (i18 = 0; i18 < 2; i18++) {
    b_padSize[i18] = padSize;
  }

  emxInit_real_T1(sp, &Apad, 2, &ib_emlrtRTEI, true);
  emxInit_real_T(sp, &y, 1, &hb_emlrtRTEI, true);
  st.site = &le_emlrtRSI;
  padarray(&st, varargin_1, b_padSize, Apad);
  ii = Apad->size[0];
  i18 = y->size[0];
  y->size[0] = cols_size[0];
  emxEnsureCapacity(sp, (emxArray__common *)y, i18, (int32_T)sizeof(real_T),
                    &hb_emlrtRTEI);
  loop_ub = cols_size[0];
  for (i18 = 0; i18 < loop_ub; i18++) {
    y->data[i18] = cols_data[i18] * (real_T)ii;
  }

  i18 = y->size[0];
  if (i18 != rows_size[0]) {
    emlrtSizeEqCheck1DR2012b(i18, rows_size[0], &c_emlrtECI, sp);
  }

  ii = y->size[0];
  loop_ub = y->size[0];
  for (i18 = 0; i18 < loop_ub; i18++) {
    mtmp = muDoubleScalarRound(y->data[i18] + rows_data[i18]);
    if (mtmp < 2.147483648E+9) {
      if (mtmp >= -2.147483648E+9) {
        jj = (int32_T)mtmp;
      } else {
        jj = MIN_int32_T;
      }
    } else if (mtmp >= 2.147483648E+9) {
      jj = MAX_int32_T;
    } else {
      jj = 0;
    }

    indices_data[i18] = jj;
  }

  emxFree_real_T(&y);
  startIdx[0] = padSize;
  startIdx[1] = padSize;
  st.site = &me_emlrtRSI;
  b_st.site = &we_emlrtRSI;
  for (i18 = 0; i18 < 2; i18++) {
    b_padSize[i18] = 5.0;
  }

  for (i18 = 0; i18 < 2; i18++) {
    dv1[i18] = 480.0 + 160.0 * (real_T)i18;
  }

  ordfilt2_real64(&Apad->data[0], (real_T)Apad->size[0], startIdx,
                  &indices_data[0], (real_T)ii, b_padSize, 12.0, B, dv1);
  emxFree_real_T(&Apad);
  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

/* End of code generation (ordfilt2.c) */
