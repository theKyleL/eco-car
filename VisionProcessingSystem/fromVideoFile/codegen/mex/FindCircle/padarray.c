/*
 * Sponsored License - for use in support of a program or activity
 * sponsored by MathWorks.  Not for government, commercial or other
 * non-sponsored organizational use.
 *
 * padarray.c
 *
 * Code generation for function 'padarray'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "FindCircle.h"
#include "padarray.h"
#include "FindCircle_emxutil.h"
#include "FindCircle_data.h"

/* Variable Definitions */
static emlrtRSInfo se_emlrtRSI = { 20, /* lineNo */
  "padarray",                          /* fcnName */
  "C:\\Program Files\\MATLAB\\R2016b\\toolbox\\images\\images\\eml\\padarray.m"/* pathName */
};

static emlrtRSInfo te_emlrtRSI = { 72, /* lineNo */
  "padarray",                          /* fcnName */
  "C:\\Program Files\\MATLAB\\R2016b\\toolbox\\images\\images\\eml\\padarray.m"/* pathName */
};

static emlrtRTEInfo jb_emlrtRTEI = { 1,/* lineNo */
  14,                                  /* colNo */
  "padarray",                          /* fName */
  "C:\\Program Files\\MATLAB\\R2016b\\toolbox\\images\\images\\eml\\padarray.m"/* pName */
};

static emlrtRTEInfo tc_emlrtRTEI = { 138,/* lineNo */
  28,                                  /* colNo */
  "validateattributes",                /* fName */
  "C:\\Program Files\\MATLAB\\R2016b\\toolbox\\eml\\lib\\matlab\\lang\\validateattributes.m"/* pName */
};

static emlrtBCInfo mc_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  424,                                 /* lineNo */
  19,                                  /* colNo */
  "",                                  /* aName */
  "padarray",                          /* fName */
  "C:\\Program Files\\MATLAB\\R2016b\\toolbox\\images\\images\\eml\\padarray.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo nc_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  424,                                 /* lineNo */
  58,                                  /* colNo */
  "",                                  /* aName */
  "padarray",                          /* fName */
  "C:\\Program Files\\MATLAB\\R2016b\\toolbox\\images\\images\\eml\\padarray.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo oc_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  401,                                 /* lineNo */
  19,                                  /* colNo */
  "",                                  /* aName */
  "padarray",                          /* fName */
  "C:\\Program Files\\MATLAB\\R2016b\\toolbox\\images\\images\\eml\\padarray.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo pc_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  401,                                 /* lineNo */
  21,                                  /* colNo */
  "",                                  /* aName */
  "padarray",                          /* fName */
  "C:\\Program Files\\MATLAB\\R2016b\\toolbox\\images\\images\\eml\\padarray.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo qc_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  394,                                 /* lineNo */
  21,                                  /* colNo */
  "",                                  /* aName */
  "padarray",                          /* fName */
  "C:\\Program Files\\MATLAB\\R2016b\\toolbox\\images\\images\\eml\\padarray.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo rc_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  387,                                 /* lineNo */
  19,                                  /* colNo */
  "",                                  /* aName */
  "padarray",                          /* fName */
  "C:\\Program Files\\MATLAB\\R2016b\\toolbox\\images\\images\\eml\\padarray.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo sc_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  387,                                 /* lineNo */
  21,                                  /* colNo */
  "",                                  /* aName */
  "padarray",                          /* fName */
  "C:\\Program Files\\MATLAB\\R2016b\\toolbox\\images\\images\\eml\\padarray.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo tc_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  380,                                 /* lineNo */
  19,                                  /* colNo */
  "",                                  /* aName */
  "padarray",                          /* fName */
  "C:\\Program Files\\MATLAB\\R2016b\\toolbox\\images\\images\\eml\\padarray.m",/* pName */
  0                                    /* checkKind */
};

/* Function Definitions */
void padarray(const emlrtStack *sp, const real_T varargin_1[307200], const
              real_T varargin_2[2], emxArray_real_T *b)
{
  boolean_T p;
  int32_T k;
  boolean_T exitg2;
  boolean_T exitg1;
  boolean_T b_p;
  real_T dv2[2];
  int32_T i19;
  int32_T j;
  int32_T i;
  int32_T i20;
  emlrtStack st;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &se_emlrtRSI;
  p = true;
  k = 0;
  exitg2 = false;
  while ((!exitg2) && (k < 2)) {
    if (!muDoubleScalarIsNaN(varargin_2[k])) {
      k++;
    } else {
      p = false;
      exitg2 = true;
    }
  }

  if (!p) {
    emlrtErrMsgIdAndExplicitTxt(&st, &oc_emlrtRTEI,
      "MATLAB:padarray:expectedNonNaN", 48,
      "Expected input number 2, PADSIZE, to be non-NaN.");
  }

  p = true;
  k = 0;
  exitg1 = false;
  while ((!exitg1) && (k < 2)) {
    if ((!muDoubleScalarIsInf(varargin_2[k])) && (!muDoubleScalarIsNaN
         (varargin_2[k])) && (muDoubleScalarFloor(varargin_2[k]) == varargin_2[k]))
    {
      b_p = true;
    } else {
      b_p = false;
    }

    if (b_p) {
      k++;
    } else {
      p = false;
      exitg1 = true;
    }
  }

  if (!p) {
    emlrtErrMsgIdAndExplicitTxt(&st, &tc_emlrtRTEI,
      "MATLAB:padarray:expectedInteger", 55,
      "Expected input number 2, PADSIZE, to be integer-valued.");
  }

  st.site = &te_emlrtRSI;
  for (i19 = 0; i19 < 2; i19++) {
    dv2[i19] = (480.0 + 160.0 * (real_T)i19) + 2.0 * varargin_2[i19];
  }

  i19 = b->size[0] * b->size[1];
  b->size[0] = (int32_T)dv2[0];
  b->size[1] = (int32_T)dv2[1];
  emxEnsureCapacity(&st, (emxArray__common *)b, i19, (int32_T)sizeof(real_T),
                    &jb_emlrtRTEI);
  for (j = 0; j < (int32_T)varargin_2[1]; j++) {
    i19 = b->size[0];
    for (i = 0; i < i19; i++) {
      i20 = b->size[0];
      if (!((i + 1 >= 1) && (i + 1 <= i20))) {
        emlrtDynamicBoundsCheckR2012b(i + 1, 1, i20, &tc_emlrtBCI, &st);
      }

      b->data[i + b->size[0] * j] = 0.0;
    }
  }

  k = b->size[1];
  for (j = (int32_T)varargin_2[1] + 641; j <= k; j++) {
    i19 = b->size[0];
    for (i = 0; i < i19; i++) {
      i20 = b->size[0];
      if (!((i + 1 >= 1) && (i + 1 <= i20))) {
        emlrtDynamicBoundsCheckR2012b(i + 1, 1, i20, &rc_emlrtBCI, &st);
      }

      i20 = b->size[1];
      if (!((j >= 1) && (j <= i20))) {
        emlrtDynamicBoundsCheckR2012b(j, 1, i20, &sc_emlrtBCI, &st);
      }

      b->data[i + b->size[0] * (j - 1)] = 0.0;
    }
  }

  for (j = 0; j < 640; j++) {
    for (i = 0; i < (int32_T)varargin_2[0]; i++) {
      i19 = b->size[1];
      i20 = (j + (int32_T)varargin_2[1]) + 1;
      if (!((i20 >= 1) && (i20 <= i19))) {
        emlrtDynamicBoundsCheckR2012b(i20, 1, i19, &qc_emlrtBCI, &st);
      }

      b->data[i + b->size[0] * (i20 - 1)] = 0.0;
    }
  }

  for (j = 0; j < 640; j++) {
    k = b->size[0];
    for (i = (int32_T)varargin_2[0] + 481; i <= k; i++) {
      i19 = b->size[0];
      if (!((i >= 1) && (i <= i19))) {
        emlrtDynamicBoundsCheckR2012b(i, 1, i19, &oc_emlrtBCI, &st);
      }

      i19 = b->size[1];
      i20 = (j + (int32_T)varargin_2[1]) + 1;
      if (!((i20 >= 1) && (i20 <= i19))) {
        emlrtDynamicBoundsCheckR2012b(i20, 1, i19, &pc_emlrtBCI, &st);
      }

      b->data[(i + b->size[0] * (i20 - 1)) - 1] = 0.0;
    }
  }

  for (j = 0; j < 640; j++) {
    for (i = 0; i < 480; i++) {
      i19 = b->size[0];
      i20 = (i + (int32_T)varargin_2[0]) + 1;
      if (!((i20 >= 1) && (i20 <= i19))) {
        emlrtDynamicBoundsCheckR2012b(i20, 1, i19, &mc_emlrtBCI, &st);
      }

      i19 = b->size[1];
      k = (j + (int32_T)varargin_2[1]) + 1;
      if (!((k >= 1) && (k <= i19))) {
        emlrtDynamicBoundsCheckR2012b(k, 1, i19, &nc_emlrtBCI, &st);
      }

      b->data[(i20 + b->size[0] * (k - 1)) - 1] = varargin_1[i + 480 * j];
    }
  }
}

/* End of code generation (padarray.c) */
