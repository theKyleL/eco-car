/*
 * Sponsored License - for use in support of a program or activity
 * sponsored by MathWorks.  Not for government, commercial or other
 * non-sponsored organizational use.
 *
 * imfindcircles.c
 *
 * Code generation for function 'imfindcircles'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "FindCircle.h"
#include "imfindcircles.h"
#include "FindCircle_emxutil.h"
#include "eml_int_forloop_overflow_check.h"
#include "chaccum.h"
#include "chcenters.h"
#include "sub2ind.h"
#include "round1.h"
#include "all.h"
#include "indexShapeCheck.h"
#include "FindCircle_data.h"

/* Variable Definitions */
static emlrtRSInfo b_emlrtRSI = { 28,  /* lineNo */
  "imfindcircles",                     /* fcnName */
  "C:\\Program Files\\MATLAB\\R2016b\\toolbox\\images\\images\\eml\\imfindcircles.m"/* pathName */
};

static emlrtRSInfo c_emlrtRSI = { 38,  /* lineNo */
  "imfindcircles",                     /* fcnName */
  "C:\\Program Files\\MATLAB\\R2016b\\toolbox\\images\\images\\eml\\imfindcircles.m"/* pathName */
};

static emlrtRSInfo d_emlrtRSI = { 46,  /* lineNo */
  "imfindcircles",                     /* fcnName */
  "C:\\Program Files\\MATLAB\\R2016b\\toolbox\\images\\images\\eml\\imfindcircles.m"/* pathName */
};

static emlrtRSInfo e_emlrtRSI = { 64,  /* lineNo */
  "imfindcircles",                     /* fcnName */
  "C:\\Program Files\\MATLAB\\R2016b\\toolbox\\images\\images\\eml\\imfindcircles.m"/* pathName */
};

static emlrtRSInfo wc_emlrtRSI = { 67, /* lineNo */
  "applyScalarFunction",               /* fcnName */
  "C:\\Program Files\\MATLAB\\R2016b\\toolbox\\eml\\eml\\+coder\\+internal\\applyScalarFunction.m"/* pathName */
};

static emlrtRSInfo ih_emlrtRSI = { 44, /* lineNo */
  "find",                              /* fcnName */
  "C:\\Program Files\\MATLAB\\R2016b\\toolbox\\eml\\lib\\matlab\\elmat\\find.m"/* pathName */
};

static emlrtRSInfo jh_emlrtRSI = { 253,/* lineNo */
  "find",                              /* fcnName */
  "C:\\Program Files\\MATLAB\\R2016b\\toolbox\\eml\\lib\\matlab\\elmat\\find.m"/* pathName */
};

static emlrtRSInfo kh_emlrtRSI = { 234,/* lineNo */
  "find",                              /* fcnName */
  "C:\\Program Files\\MATLAB\\R2016b\\toolbox\\eml\\lib\\matlab\\elmat\\find.m"/* pathName */
};

static emlrtRSInfo lh_emlrtRSI = { 6,  /* lineNo */
  "chradiiphcode",                     /* fcnName */
  "C:\\Program Files\\MATLAB\\R2016b\\toolbox\\images\\images\\eml\\private\\chradiiphcode.m"/* pathName */
};

static emlrtRSInfo mh_emlrtRSI = { 14, /* lineNo */
  "chradiiphcode",                     /* fcnName */
  "C:\\Program Files\\MATLAB\\R2016b\\toolbox\\images\\images\\eml\\private\\chradiiphcode.m"/* pathName */
};

static emlrtRSInfo nh_emlrtRSI = { 16, /* lineNo */
  "chradiiphcode",                     /* fcnName */
  "C:\\Program Files\\MATLAB\\R2016b\\toolbox\\images\\images\\eml\\private\\chradiiphcode.m"/* pathName */
};

static emlrtRSInfo oh_emlrtRSI = { 32, /* lineNo */
  "chradiiphcode",                     /* fcnName */
  "C:\\Program Files\\MATLAB\\R2016b\\toolbox\\images\\images\\eml\\private\\chradiiphcode.m"/* pathName */
};

static emlrtRSInfo ph_emlrtRSI = { 35, /* lineNo */
  "chradiiphcode",                     /* fcnName */
  "C:\\Program Files\\MATLAB\\R2016b\\toolbox\\images\\images\\eml\\private\\chradiiphcode.m"/* pathName */
};

static emlrtRSInfo qh_emlrtRSI = { 44, /* lineNo */
  "chradiiphcode",                     /* fcnName */
  "C:\\Program Files\\MATLAB\\R2016b\\toolbox\\images\\images\\eml\\private\\chradiiphcode.m"/* pathName */
};

static emlrtRSInfo rh_emlrtRSI = { 72, /* lineNo */
  "chradiiphcode",                     /* fcnName */
  "C:\\Program Files\\MATLAB\\R2016b\\toolbox\\images\\images\\eml\\private\\chradiiphcode.m"/* pathName */
};

static emlrtRSInfo sh_emlrtRSI = { 73, /* lineNo */
  "chradiiphcode",                     /* fcnName */
  "C:\\Program Files\\MATLAB\\R2016b\\toolbox\\images\\images\\eml\\private\\chradiiphcode.m"/* pathName */
};

static emlrtRSInfo uh_emlrtRSI = { 9,  /* lineNo */
  "angle",                             /* fcnName */
  "C:\\Program Files\\MATLAB\\R2016b\\toolbox\\eml\\lib\\matlab\\elfun\\angle.m"/* pathName */
};

static emlrtRSInfo vh_emlrtRSI = { 9,  /* lineNo */
  "exp",                               /* fcnName */
  "C:\\Program Files\\MATLAB\\R2016b\\toolbox\\eml\\lib\\matlab\\elfun\\exp.m"/* pathName */
};

static emlrtRTEInfo emlrtRTEI = { 1,   /* lineNo */
  43,                                  /* colNo */
  "imfindcircles",                     /* fName */
  "C:\\Program Files\\MATLAB\\R2016b\\toolbox\\images\\images\\eml\\imfindcircles.m"/* pName */
};

static emlrtRTEInfo b_emlrtRTEI = { 253,/* lineNo */
  13,                                  /* colNo */
  "find",                              /* fName */
  "C:\\Program Files\\MATLAB\\R2016b\\toolbox\\eml\\lib\\matlab\\elmat\\find.m"/* pName */
};

static emlrtRTEInfo c_emlrtRTEI = { 46,/* lineNo */
  1,                                   /* colNo */
  "imfindcircles",                     /* fName */
  "C:\\Program Files\\MATLAB\\R2016b\\toolbox\\images\\images\\eml\\imfindcircles.m"/* pName */
};

static emlrtRTEInfo d_emlrtRTEI = { 36,/* lineNo */
  6,                                   /* colNo */
  "find",                              /* fName */
  "C:\\Program Files\\MATLAB\\R2016b\\toolbox\\eml\\lib\\matlab\\elmat\\find.m"/* pName */
};

static emlrtRTEInfo cc_emlrtRTEI = { 243,/* lineNo */
  9,                                   /* colNo */
  "find",                              /* fName */
  "C:\\Program Files\\MATLAB\\R2016b\\toolbox\\eml\\lib\\matlab\\elmat\\find.m"/* pName */
};

static emlrtBCInfo emlrtBCI = { -1,    /* iFirst */
  -1,                                  /* iLast */
  14,                                  /* lineNo */
  72,                                  /* colNo */
  "",                                  /* aName */
  "chradiiphcode",                     /* fName */
  "C:\\Program Files\\MATLAB\\R2016b\\toolbox\\images\\images\\eml\\private\\chradiiphcode.m",/* pName */
  0                                    /* checkKind */
};

static emlrtRTEInfo dc_emlrtRTEI = { 152,/* lineNo */
  28,                                  /* colNo */
  "validateattributes",                /* fName */
  "C:\\Program Files\\MATLAB\\R2016b\\toolbox\\eml\\lib\\matlab\\lang\\validateattributes.m"/* pName */
};

static emlrtRTEInfo ec_emlrtRTEI = { 122,/* lineNo */
  28,                                  /* colNo */
  "validateattributes",                /* fName */
  "C:\\Program Files\\MATLAB\\R2016b\\toolbox\\eml\\lib\\matlab\\lang\\validateattributes.m"/* pName */
};

static emlrtRTEInfo fc_emlrtRTEI = { 240,/* lineNo */
  28,                                  /* colNo */
  "validateattributes",                /* fName */
  "C:\\Program Files\\MATLAB\\R2016b\\toolbox\\eml\\lib\\matlab\\lang\\validateattributes.m"/* pName */
};

static emlrtBCInfo b_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  73,                                  /* lineNo */
  19,                                  /* colNo */
  "",                                  /* aName */
  "chradiiphcode",                     /* fName */
  "C:\\Program Files\\MATLAB\\R2016b\\toolbox\\images\\images\\eml\\private\\chradiiphcode.m",/* pName */
  0                                    /* checkKind */
};

static emlrtRTEInfo gc_emlrtRTEI = { 72,/* lineNo */
  1,                                   /* colNo */
  "chradiiphcode",                     /* fName */
  "C:\\Program Files\\MATLAB\\R2016b\\toolbox\\images\\images\\eml\\private\\chradiiphcode.m"/* pName */
};

static emlrtBCInfo c_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  47,                                  /* lineNo */
  19,                                  /* colNo */
  "",                                  /* aName */
  "imfindcircles",                     /* fName */
  "C:\\Program Files\\MATLAB\\R2016b\\toolbox\\images\\images\\eml\\imfindcircles.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo d_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  48,                                  /* lineNo */
  17,                                  /* colNo */
  "",                                  /* aName */
  "imfindcircles",                     /* fName */
  "C:\\Program Files\\MATLAB\\R2016b\\toolbox\\images\\images\\eml\\imfindcircles.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo e_emlrtBCI = { 1,   /* iFirst */
  307200,                              /* iLast */
  14,                                  /* lineNo */
  18,                                  /* colNo */
  "",                                  /* aName */
  "chradiiphcode",                     /* fName */
  "C:\\Program Files\\MATLAB\\R2016b\\toolbox\\images\\images\\eml\\private\\chradiiphcode.m",/* pName */
  0                                    /* checkKind */
};

/* Function Definitions */
void imfindcircles(FindCircleStackData *SD, const emlrtStack *sp, const uint8_T
                   varargin_1[921600], emxArray_real_T *centers, emxArray_real_T
                   *r_estimated)
{
  int32_T i0;
  boolean_T overflow;
  int32_T nx;
  boolean_T exitg4;
  emxArray_real_T *b_centers;
  boolean_T p;
  emxArray_real_T *metric;
  int32_T loop_ub;
  emxArray_boolean_T *x;
  emxArray_int32_T *ii;
  int32_T idx;
  int32_T n;
  boolean_T exitg3;
  boolean_T guard1 = false;
  int32_T iv0[2];
  emxArray_real_T *idx2Keep;
  int32_T i1;
  boolean_T exitg2;
  emxArray_boolean_T *c_centers;
  emxArray_boolean_T *d_centers;
  boolean_T b_guard1 = false;
  emxArray_real_T *b_varargin_1;
  emxArray_real_T *varargin_2;
  int32_T c_varargin_1[2];
  int32_T b_varargin_2[2];
  boolean_T exitg1;
  emxArray_creal_T *b_x;
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  e_st.prev = &d_st;
  e_st.tls = d_st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b(sp);
  i0 = centers->size[0] * centers->size[1];
  centers->size[0] = 0;
  centers->size[1] = 0;
  emxEnsureCapacity(sp, (emxArray__common *)centers, i0, (int32_T)sizeof(real_T),
                    &emlrtRTEI);
  i0 = r_estimated->size[0] * r_estimated->size[1];
  r_estimated->size[0] = 0;
  r_estimated->size[1] = 0;
  emxEnsureCapacity(sp, (emxArray__common *)r_estimated, i0, (int32_T)sizeof
                    (real_T), &emlrtRTEI);
  st.site = &b_emlrtRSI;
  chaccum(SD, &st, varargin_1, SD->f7.accumMatrix, SD->f7.gradientImg);
  overflow = false;
  nx = 0;
  exitg4 = false;
  while ((!exitg4) && (nx < 307200)) {
    if (((SD->f7.accumMatrix[nx].re == 0.0) && (SD->f7.accumMatrix[nx].im == 0.0))
        || (muDoubleScalarIsNaN(SD->f7.accumMatrix[nx].re) ||
            muDoubleScalarIsNaN(SD->f7.accumMatrix[nx].im))) {
      p = true;
    } else {
      p = false;
    }

    if (!p) {
      overflow = true;
      exitg4 = true;
    } else {
      nx++;
    }
  }

  if (overflow) {
    emxInit_real_T1(sp, &b_centers, 2, &emlrtRTEI, true);
    emxInit_real_T1(sp, &metric, 2, &emlrtRTEI, true);
    st.site = &c_emlrtRSI;
    chcenters(SD, &st, SD->f7.accumMatrix, b_centers, metric);
    i0 = centers->size[0] * centers->size[1];
    centers->size[0] = b_centers->size[0];
    centers->size[1] = b_centers->size[1];
    emxEnsureCapacity(sp, (emxArray__common *)centers, i0, (int32_T)sizeof
                      (real_T), &emlrtRTEI);
    loop_ub = b_centers->size[0] * b_centers->size[1];
    for (i0 = 0; i0 < loop_ub; i0++) {
      centers->data[i0] = b_centers->data[i0];
    }

    if (!((b_centers->size[0] == 0) || (b_centers->size[1] == 0))) {
      emxInit_boolean_T(sp, &x, 2, &emlrtRTEI, true);
      st.site = &d_emlrtRSI;
      i0 = x->size[0] * x->size[1];
      x->size[0] = metric->size[0];
      x->size[1] = metric->size[1];
      emxEnsureCapacity(&st, (emxArray__common *)x, i0, (int32_T)sizeof
                        (boolean_T), &emlrtRTEI);
      loop_ub = metric->size[0] * metric->size[1];
      for (i0 = 0; i0 < loop_ub; i0++) {
        x->data[i0] = (metric->data[i0] >= 0.15000000000000002);
      }

      emxInit_int32_T(&st, &ii, 1, &d_emlrtRTEI, true);
      b_st.site = &ih_emlrtRSI;
      nx = x->size[0] * x->size[1];
      idx = 0;
      i0 = ii->size[0];
      ii->size[0] = nx;
      emxEnsureCapacity(&b_st, (emxArray__common *)ii, i0, (int32_T)sizeof
                        (int32_T), &emlrtRTEI);
      c_st.site = &kh_emlrtRSI;
      if ((!(1 > nx)) && (nx > 2147483646)) {
        d_st.site = &w_emlrtRSI;
        check_forloop_overflow_error(&d_st);
      }

      n = 1;
      exitg3 = false;
      while ((!exitg3) && (n <= nx)) {
        guard1 = false;
        if (x->data[n - 1]) {
          idx++;
          ii->data[idx - 1] = n;
          if (idx >= nx) {
            exitg3 = true;
          } else {
            guard1 = true;
          }
        } else {
          guard1 = true;
        }

        if (guard1) {
          n++;
        }
      }

      emxFree_boolean_T(&x);
      if (!(idx <= nx)) {
        emlrtErrorWithMessageIdR2012b(&b_st, &cc_emlrtRTEI,
          "Coder:builtins:AssertionFailed", 0);
      }

      if (nx == 1) {
        if (idx == 0) {
          i0 = ii->size[0];
          ii->size[0] = 0;
          emxEnsureCapacity(&b_st, (emxArray__common *)ii, i0, (int32_T)sizeof
                            (int32_T), &emlrtRTEI);
        }
      } else {
        if (1 > idx) {
          i0 = 0;
        } else {
          i0 = idx;
        }

        iv0[0] = 1;
        iv0[1] = i0;
        c_st.site = &jh_emlrtRSI;
        indexShapeCheck(&c_st, ii->size[0], iv0);
        i1 = ii->size[0];
        ii->size[0] = i0;
        emxEnsureCapacity(&b_st, (emxArray__common *)ii, i1, (int32_T)sizeof
                          (int32_T), &b_emlrtRTEI);
      }

      emxInit_real_T(&b_st, &idx2Keep, 1, &c_emlrtRTEI, true);
      i0 = idx2Keep->size[0];
      idx2Keep->size[0] = ii->size[0];
      emxEnsureCapacity(&st, (emxArray__common *)idx2Keep, i0, (int32_T)sizeof
                        (real_T), &emlrtRTEI);
      loop_ub = ii->size[0];
      for (i0 = 0; i0 < loop_ub; i0++) {
        idx2Keep->data[i0] = ii->data[i0];
      }

      n = b_centers->size[0];
      loop_ub = b_centers->size[1];
      i0 = centers->size[0] * centers->size[1];
      centers->size[0] = idx2Keep->size[0];
      centers->size[1] = loop_ub;
      emxEnsureCapacity(sp, (emxArray__common *)centers, i0, (int32_T)sizeof
                        (real_T), &emlrtRTEI);
      for (i0 = 0; i0 < loop_ub; i0++) {
        nx = idx2Keep->size[0];
        for (i1 = 0; i1 < nx; i1++) {
          idx = (int32_T)idx2Keep->data[i1];
          if (!((idx >= 1) && (idx <= n))) {
            emlrtDynamicBoundsCheckR2012b(idx, 1, n, &c_emlrtBCI, sp);
          }

          centers->data[i1 + centers->size[0] * i0] = b_centers->data[(idx +
            b_centers->size[0] * i0) - 1];
        }
      }

      n = metric->size[0];
      loop_ub = idx2Keep->size[0];
      for (i0 = 0; i0 < loop_ub; i0++) {
        i1 = (int32_T)idx2Keep->data[i0];
        if (!((i1 >= 1) && (i1 <= n))) {
          emlrtDynamicBoundsCheckR2012b(i1, 1, n, &d_emlrtBCI, sp);
        }
      }

      if (idx2Keep->size[0] == 0) {
        i0 = centers->size[0] * centers->size[1];
        centers->size[0] = 0;
        centers->size[1] = 0;
        emxEnsureCapacity(sp, (emxArray__common *)centers, i0, (int32_T)sizeof
                          (real_T), &emlrtRTEI);
      } else {
        st.site = &e_emlrtRSI;
        b_st.site = &lh_emlrtRSI;
        c_st.site = &oh_emlrtRSI;
        d_st.site = &qh_emlrtRSI;
        overflow = true;
        i0 = b_centers->size[1];
        i0 *= idx2Keep->size[0];
        nx = 0;
        exitg2 = false;
        while ((!exitg2) && (nx <= i0 - 1)) {
          if (!(centers->data[nx] <= 0.0)) {
            nx++;
          } else {
            overflow = false;
            exitg2 = true;
          }
        }

        if (!overflow) {
          emlrtErrMsgIdAndExplicitTxt(&d_st, &dc_emlrtRTEI,
            "MATLAB:chradiiphcode:expectedPositive", 49,
            "Expected input number 1, centers, to be positive.");
        }

        if (idx2Keep->size[0] == 0) {
          emlrtErrMsgIdAndExplicitTxt(&d_st, &ec_emlrtRTEI,
            "MATLAB:chradiiphcode:expectedNonempty", 49,
            "Expected input number 1, centers, to be nonempty.");
        }

        i0 = b_centers->size[1];
        if (i0 != 2) {
          emlrtErrMsgIdAndExplicitTxt(&d_st, &fc_emlrtRTEI,
            "MATLAB:chradiiphcode:incorrectNumcols", 83,
            "Expected input number 1, centers, to be an array with number of columns equal to 2.");
        }

        emxInit_boolean_T1(&d_st, &c_centers, 1, &emlrtRTEI, true);
        c_st.site = &ph_emlrtRSI;
        loop_ub = idx2Keep->size[0];
        i0 = c_centers->size[0];
        c_centers->size[0] = loop_ub;
        emxEnsureCapacity(&c_st, (emxArray__common *)c_centers, i0, (int32_T)
                          sizeof(boolean_T), &emlrtRTEI);
        for (i0 = 0; i0 < loop_ub; i0++) {
          c_centers->data[i0] = (centers->data[i0] <= 640.0);
        }

        emxInit_boolean_T1(&c_st, &d_centers, 1, &emlrtRTEI, true);
        b_guard1 = false;
        d_st.site = &rh_emlrtRSI;
        if (b_all(&d_st, c_centers)) {
          i0 = b_centers->size[1];
          if (!(2 <= i0)) {
            emlrtDynamicBoundsCheckR2012b(2, 1, i0, &b_emlrtBCI, &c_st);
          }

          loop_ub = idx2Keep->size[0];
          i0 = d_centers->size[0];
          d_centers->size[0] = loop_ub;
          emxEnsureCapacity(&c_st, (emxArray__common *)d_centers, i0, (int32_T)
                            sizeof(boolean_T), &emlrtRTEI);
          for (i0 = 0; i0 < loop_ub; i0++) {
            d_centers->data[i0] = (centers->data[i0 + centers->size[0]] <= 480.0);
          }

          d_st.site = &sh_emlrtRSI;
          if (b_all(&d_st, d_centers)) {
            p = true;
          } else {
            b_guard1 = true;
          }
        } else {
          b_guard1 = true;
        }

        if (b_guard1) {
          p = false;
        }

        emxFree_boolean_T(&c_centers);
        emxFree_boolean_T(&d_centers);
        if (!p) {
          emlrtErrorWithMessageIdR2012b(&c_st, &gc_emlrtRTEI,
            "images:imfindcircles:outOfBoundCenters", 0);
        }

        emxInit_real_T(&c_st, &b_varargin_1, 1, &emlrtRTEI, true);
        i0 = b_centers->size[1];
        if (!(2 <= i0)) {
          emlrtDynamicBoundsCheckR2012b(2, 1, i0, &emlrtBCI, &st);
        }

        loop_ub = idx2Keep->size[0];
        i0 = b_varargin_1->size[0];
        b_varargin_1->size[0] = loop_ub;
        emxEnsureCapacity(&st, (emxArray__common *)b_varargin_1, i0, (int32_T)
                          sizeof(real_T), &emlrtRTEI);
        for (i0 = 0; i0 < loop_ub; i0++) {
          b_varargin_1->data[i0] = centers->data[i0 + centers->size[0]];
        }

        emxInit_real_T(&st, &varargin_2, 1, &emlrtRTEI, true);
        b_st.site = &mh_emlrtRSI;
        b_round(&b_st, b_varargin_1);
        loop_ub = idx2Keep->size[0];
        i0 = varargin_2->size[0];
        varargin_2->size[0] = loop_ub;
        emxEnsureCapacity(&st, (emxArray__common *)varargin_2, i0, (int32_T)
                          sizeof(real_T), &emlrtRTEI);
        for (i0 = 0; i0 < loop_ub; i0++) {
          varargin_2->data[i0] = centers->data[i0];
        }

        b_st.site = &mh_emlrtRSI;
        b_round(&b_st, varargin_2);
        b_st.site = &mh_emlrtRSI;
        c_st.site = &vd_emlrtRSI;
        if (!allinrange(b_varargin_1, 480)) {
          emlrtErrorWithMessageIdR2012b(&c_st, &hc_emlrtRTEI,
            "MATLAB:sub2ind:IndexOutOfRange", 0);
        }

        c_varargin_1[0] = b_varargin_1->size[0];
        c_varargin_1[1] = 1;
        b_varargin_2[0] = varargin_2->size[0];
        b_varargin_2[1] = 1;
        overflow = false;
        p = true;
        nx = 0;
        exitg1 = false;
        while ((!exitg1) && (nx < 2)) {
          if (!(c_varargin_1[nx] == b_varargin_2[nx])) {
            p = false;
            exitg1 = true;
          } else {
            nx++;
          }
        }

        if (p) {
          overflow = true;
        }

        if (!overflow) {
          emlrtErrorWithMessageIdR2012b(&c_st, &ic_emlrtRTEI,
            "MATLAB:sub2ind:SubscriptVectorSize", 0);
        }

        if (!allinrange(varargin_2, 640)) {
          emlrtErrorWithMessageIdR2012b(&c_st, &hc_emlrtRTEI,
            "MATLAB:sub2ind:IndexOutOfRange", 0);
        }

        i0 = ii->size[0];
        ii->size[0] = b_varargin_1->size[0];
        emxEnsureCapacity(&c_st, (emxArray__common *)ii, i0, (int32_T)sizeof
                          (int32_T), &emlrtRTEI);
        loop_ub = b_varargin_1->size[0];
        for (i0 = 0; i0 < loop_ub; i0++) {
          ii->data[i0] = (int32_T)b_varargin_1->data[i0] + 480 * ((int32_T)
            varargin_2->data[i0] - 1);
        }

        emxFree_real_T(&varargin_2);
        emxInit_creal_T(&c_st, &b_x, 1, &emlrtRTEI, true);
        b_st.site = &mh_emlrtRSI;
        i0 = b_x->size[0];
        b_x->size[0] = ii->size[0];
        emxEnsureCapacity(&b_st, (emxArray__common *)b_x, i0, (int32_T)sizeof
                          (creal_T), &emlrtRTEI);
        loop_ub = ii->size[0];
        for (i0 = 0; i0 < loop_ub; i0++) {
          i1 = ii->data[i0];
          if (!((i1 >= 1) && (i1 <= 307200))) {
            emlrtDynamicBoundsCheckR2012b(i1, 1, 307200, &e_emlrtBCI, &b_st);
          }

          b_x->data[i0].re = SD->f7.accumMatrix[i1 - 1].re;
          i1 = ii->data[i0];
          if (!((i1 >= 1) && (i1 <= 307200))) {
            emlrtDynamicBoundsCheckR2012b(i1, 1, 307200, &e_emlrtBCI, &b_st);
          }

          b_x->data[i0].im = SD->f7.accumMatrix[i1 - 1].im;
        }

        c_st.site = &uh_emlrtRSI;
        n = ii->size[0];
        i0 = idx2Keep->size[0];
        idx2Keep->size[0] = n;
        emxEnsureCapacity(&c_st, (emxArray__common *)idx2Keep, i0, (int32_T)
                          sizeof(real_T), &emlrtRTEI);
        n = ii->size[0];
        d_st.site = &wc_emlrtRSI;
        overflow = ((!(1 > ii->size[0])) && (ii->size[0] > 2147483646));
        if (overflow) {
          e_st.site = &w_emlrtRSI;
          check_forloop_overflow_error(&e_st);
        }

        for (nx = 0; nx + 1 <= n; nx++) {
          idx2Keep->data[nx] = muDoubleScalarAtan2(b_x->data[nx].im, b_x->
            data[nx].re);
        }

        emxFree_creal_T(&b_x);
        b_st.site = &nh_emlrtRSI;
        i0 = idx2Keep->size[0];
        emxEnsureCapacity(&b_st, (emxArray__common *)idx2Keep, i0, (int32_T)
                          sizeof(real_T), &emlrtRTEI);
        loop_ub = idx2Keep->size[0];
        for (i0 = 0; i0 < loop_ub; i0++) {
          idx2Keep->data[i0] = (idx2Keep->data[i0] + 3.1415926535897931) /
            6.2831853071795862 * 0.6931471805599454 + 2.70805020110221;
        }

        c_st.site = &vh_emlrtRSI;
        i0 = b_varargin_1->size[0];
        b_varargin_1->size[0] = idx2Keep->size[0];
        emxEnsureCapacity(&c_st, (emxArray__common *)b_varargin_1, i0, (int32_T)
                          sizeof(real_T), &emlrtRTEI);
        loop_ub = idx2Keep->size[0];
        for (i0 = 0; i0 < loop_ub; i0++) {
          b_varargin_1->data[i0] = idx2Keep->data[i0];
        }

        d_st.site = &ah_emlrtRSI;
        overflow = ((!(1 > idx2Keep->size[0])) && (idx2Keep->size[0] >
          2147483646));
        if (overflow) {
          e_st.site = &w_emlrtRSI;
          check_forloop_overflow_error(&e_st);
        }

        for (nx = 0; nx + 1 <= idx2Keep->size[0]; nx++) {
          b_varargin_1->data[nx] = muDoubleScalarExp(b_varargin_1->data[nx]);
        }

        i0 = r_estimated->size[0] * r_estimated->size[1];
        r_estimated->size[0] = b_varargin_1->size[0];
        r_estimated->size[1] = 1;
        emxEnsureCapacity(sp, (emxArray__common *)r_estimated, i0, (int32_T)
                          sizeof(real_T), &emlrtRTEI);
        loop_ub = b_varargin_1->size[0];
        for (i0 = 0; i0 < loop_ub; i0++) {
          r_estimated->data[i0] = b_varargin_1->data[i0];
        }

        emxFree_real_T(&b_varargin_1);
      }

      emxFree_int32_T(&ii);
      emxFree_real_T(&idx2Keep);
    }

    emxFree_real_T(&metric);
    emxFree_real_T(&b_centers);
  }

  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

/* End of code generation (imfindcircles.c) */
