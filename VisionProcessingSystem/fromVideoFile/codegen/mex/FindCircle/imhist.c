/*
 * Sponsored License - for use in support of a program or activity
 * sponsored by MathWorks.  Not for government, commercial or other
 * non-sponsored organizational use.
 *
 * imhist.c
 *
 * Code generation for function 'imhist'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "FindCircle.h"
#include "imhist.h"
#include "libmwgetnumcores.h"

/* Variable Definitions */
static emlrtRSInfo xb_emlrtRSI = { 121,/* lineNo */
  "imhist",                            /* fcnName */
  "C:\\Program Files\\MATLAB\\R2016b\\toolbox\\images\\images\\eml\\imhist.m"/* pathName */
};

static emlrtRSInfo yb_emlrtRSI = { 185,/* lineNo */
  "imhist",                            /* fcnName */
  "C:\\Program Files\\MATLAB\\R2016b\\toolbox\\images\\images\\eml\\imhist.m"/* pathName */
};

static emlrtRSInfo ac_emlrtRSI = { 154,/* lineNo */
  "imhist",                            /* fcnName */
  "C:\\Program Files\\MATLAB\\R2016b\\toolbox\\images\\images\\eml\\imhist.m"/* pathName */
};

static emlrtBCInfo bc_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  631,                                 /* lineNo */
  39,                                  /* colNo */
  "",                                  /* aName */
  "imhist",                            /* fName */
  "C:\\Program Files\\MATLAB\\R2016b\\toolbox\\images\\images\\eml\\imhist.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo cc_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  619,                                 /* lineNo */
  40,                                  /* colNo */
  "",                                  /* aName */
  "imhist",                            /* fName */
  "C:\\Program Files\\MATLAB\\R2016b\\toolbox\\images\\images\\eml\\imhist.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo dc_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  618,                                 /* lineNo */
  40,                                  /* colNo */
  "",                                  /* aName */
  "imhist",                            /* fName */
  "C:\\Program Files\\MATLAB\\R2016b\\toolbox\\images\\images\\eml\\imhist.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo ec_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  617,                                 /* lineNo */
  40,                                  /* colNo */
  "",                                  /* aName */
  "imhist",                            /* fName */
  "C:\\Program Files\\MATLAB\\R2016b\\toolbox\\images\\images\\eml\\imhist.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo fc_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  616,                                 /* lineNo */
  40,                                  /* colNo */
  "",                                  /* aName */
  "imhist",                            /* fName */
  "C:\\Program Files\\MATLAB\\R2016b\\toolbox\\images\\images\\eml\\imhist.m",/* pName */
  0                                    /* checkKind */
};

/* Function Definitions */
void imhist(const emlrtStack *sp, const emxArray_uint8_T *varargin_1, real_T
            yout[256])
{
  real_T out;
  real_T localBins1[256];
  real_T localBins2[256];
  real_T localBins3[256];
  int32_T i;
  int32_T i9;
  emlrtStack st;
  emlrtStack b_st;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &xb_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  b_st.site = &ac_emlrtRSI;
  out = 1.0;
  getnumcores(&out);
  b_st.site = &yb_emlrtRSI;
  memset(&yout[0], 0, sizeof(real_T) << 8);
  memset(&localBins1[0], 0, sizeof(real_T) << 8);
  memset(&localBins2[0], 0, sizeof(real_T) << 8);
  memset(&localBins3[0], 0, sizeof(real_T) << 8);
  for (i = 1; i + 3 <= varargin_1->size[0]; i += 4) {
    i9 = varargin_1->size[0];
    if (!((i >= 1) && (i <= i9))) {
      emlrtDynamicBoundsCheckR2012b(i, 1, i9, &fc_emlrtBCI, &b_st);
    }

    i9 = varargin_1->size[0];
    if (!((i + 1 >= 1) && (i + 1 <= i9))) {
      emlrtDynamicBoundsCheckR2012b(i + 1, 1, i9, &ec_emlrtBCI, &b_st);
    }

    i9 = varargin_1->size[0];
    if (!((i + 2 >= 1) && (i + 2 <= i9))) {
      emlrtDynamicBoundsCheckR2012b(i + 2, 1, i9, &dc_emlrtBCI, &b_st);
    }

    i9 = varargin_1->size[0];
    if (!((i + 3 >= 1) && (i + 3 <= i9))) {
      emlrtDynamicBoundsCheckR2012b(i + 3, 1, i9, &cc_emlrtBCI, &b_st);
    }

    localBins1[varargin_1->data[i - 1]]++;
    localBins2[varargin_1->data[i]]++;
    localBins3[varargin_1->data[i + 1]]++;
    yout[varargin_1->data[i + 2]]++;
  }

  while (i <= varargin_1->size[0]) {
    i9 = varargin_1->size[0];
    if (!((i >= 1) && (i <= i9))) {
      emlrtDynamicBoundsCheckR2012b(i, 1, i9, &bc_emlrtBCI, &b_st);
    }

    yout[varargin_1->data[i - 1]]++;
    i++;
  }

  for (i = 0; i < 256; i++) {
    yout[i] = ((yout[i] + localBins1[i]) + localBins2[i]) + localBins3[i];
  }
}

/* End of code generation (imhist.c) */
