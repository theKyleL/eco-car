/*
 * Sponsored License - for use in support of a program or activity
 * sponsored by MathWorks.  Not for government, commercial or other
 * non-sponsored organizational use.
 *
 * chcenters.c
 *
 * Code generation for function 'chcenters'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "FindCircle.h"
#include "chcenters.h"
#include "FindCircle_emxutil.h"
#include "error.h"
#include "sort1.h"
#include "sub2ind.h"
#include "round1.h"
#include "regionprops.h"
#include "validateattributes.h"
#include "ordfilt2.h"
#include "FindCircle_data.h"
#include "libmwippreconstruct.h"
#include "libmwimregionalmax.h"

/* Variable Definitions */
static emlrtRSInfo yd_emlrtRSI = { 12, /* lineNo */
  "toLogicalCheck",                    /* fcnName */
  "C:\\Program Files\\MATLAB\\R2016b\\toolbox\\eml\\eml\\+coder\\+internal\\toLogicalCheck.m"/* pathName */
};

static emlrtRSInfo ae_emlrtRSI = { 29, /* lineNo */
  "chcenters",                         /* fcnName */
  "C:\\Program Files\\MATLAB\\R2016b\\toolbox\\images\\images\\eml\\private\\chcenters.m"/* pathName */
};

static emlrtRSInfo be_emlrtRSI = { 34, /* lineNo */
  "chcenters",                         /* fcnName */
  "C:\\Program Files\\MATLAB\\R2016b\\toolbox\\images\\images\\eml\\private\\chcenters.m"/* pathName */
};

static emlrtRSInfo ce_emlrtRSI = { 35, /* lineNo */
  "chcenters",                         /* fcnName */
  "C:\\Program Files\\MATLAB\\R2016b\\toolbox\\images\\images\\eml\\private\\chcenters.m"/* pathName */
};

static emlrtRSInfo de_emlrtRSI = { 36, /* lineNo */
  "chcenters",                         /* fcnName */
  "C:\\Program Files\\MATLAB\\R2016b\\toolbox\\images\\images\\eml\\private\\chcenters.m"/* pathName */
};

static emlrtRSInfo ee_emlrtRSI = { 48, /* lineNo */
  "chcenters",                         /* fcnName */
  "C:\\Program Files\\MATLAB\\R2016b\\toolbox\\images\\images\\eml\\private\\chcenters.m"/* pathName */
};

static emlrtRSInfo fe_emlrtRSI = { 53, /* lineNo */
  "chcenters",                         /* fcnName */
  "C:\\Program Files\\MATLAB\\R2016b\\toolbox\\images\\images\\eml\\private\\chcenters.m"/* pathName */
};

static emlrtRSInfo ge_emlrtRSI = { 55, /* lineNo */
  "chcenters",                         /* fcnName */
  "C:\\Program Files\\MATLAB\\R2016b\\toolbox\\images\\images\\eml\\private\\chcenters.m"/* pathName */
};

static emlrtRSInfo he_emlrtRSI = { 37, /* lineNo */
  "medfilt2",                          /* fcnName */
  "C:\\Program Files\\MATLAB\\R2016b\\toolbox\\images\\images\\eml\\medfilt2.m"/* pathName */
};

static emlrtRSInfo xe_emlrtRSI = { 66, /* lineNo */
  "imhmax",                            /* fcnName */
  "C:\\Program Files\\MATLAB\\R2016b\\toolbox\\images\\images\\imhmax.m"/* pathName */
};

static emlrtRSInfo ye_emlrtRSI = { 10, /* lineNo */
  "imreconstruct",                     /* fcnName */
  "C:\\Program Files\\MATLAB\\R2016b\\toolbox\\images\\images\\eml\\imreconstruct.m"/* pathName */
};

static emlrtRSInfo af_emlrtRSI = { 14, /* lineNo */
  "imreconstruct",                     /* fcnName */
  "C:\\Program Files\\MATLAB\\R2016b\\toolbox\\images\\images\\eml\\imreconstruct.m"/* pathName */
};

static emlrtRSInfo cf_emlrtRSI = { 14, /* lineNo */
  "imregionalmax",                     /* fcnName */
  "C:\\Program Files\\MATLAB\\R2016b\\toolbox\\images\\images\\eml\\imregionalmax.m"/* pathName */
};

static emlrtRSInfo df_emlrtRSI = { 34, /* lineNo */
  "imregionalmax",                     /* fcnName */
  "C:\\Program Files\\MATLAB\\R2016b\\toolbox\\images\\images\\eml\\imregionalmax.m"/* pathName */
};

static emlrtRSInfo ef_emlrtRSI = { 36, /* lineNo */
  "imregionalmax",                     /* fcnName */
  "C:\\Program Files\\MATLAB\\R2016b\\toolbox\\images\\images\\eml\\imregionalmax.m"/* pathName */
};

static emlrtRSInfo ug_emlrtRSI = { 21, /* lineNo */
  "nullAssignment",                    /* fcnName */
  "C:\\Program Files\\MATLAB\\R2016b\\toolbox\\eml\\eml\\+coder\\+internal\\nullAssignment.m"/* pathName */
};

static emlrtRSInfo vg_emlrtRSI = { 25, /* lineNo */
  "nullAssignment",                    /* fcnName */
  "C:\\Program Files\\MATLAB\\R2016b\\toolbox\\eml\\eml\\+coder\\+internal\\nullAssignment.m"/* pathName */
};

static emlrtRSInfo bh_emlrtRSI = { 26, /* lineNo */
  "sort",                              /* fcnName */
  "C:\\Program Files\\MATLAB\\R2016b\\toolbox\\eml\\lib\\matlab\\datafun\\sort.m"/* pathName */
};

static emlrtRTEInfo fb_emlrtRTEI = { 1,/* lineNo */
  30,                                  /* colNo */
  "chcenters",                         /* fName */
  "C:\\Program Files\\MATLAB\\R2016b\\toolbox\\images\\images\\eml\\private\\chcenters.m"/* pName */
};

static emlrtRTEInfo gb_emlrtRTEI = { 36,/* lineNo */
  1,                                   /* colNo */
  "chcenters",                         /* fName */
  "C:\\Program Files\\MATLAB\\R2016b\\toolbox\\images\\images\\eml\\private\\chcenters.m"/* pName */
};

static emlrtBCInfo gc_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  42,                                  /* lineNo */
  17,                                  /* colNo */
  "",                                  /* aName */
  "chcenters",                         /* fName */
  "C:\\Program Files\\MATLAB\\R2016b\\toolbox\\images\\images\\eml\\private\\chcenters.m",/* pName */
  0                                    /* checkKind */
};

static emlrtECInfo b_emlrtECI = { -1,  /* nDims */
  42,                                  /* lineNo */
  9,                                   /* colNo */
  "chcenters",                         /* fName */
  "C:\\Program Files\\MATLAB\\R2016b\\toolbox\\images\\images\\eml\\private\\chcenters.m"/* pName */
};

static emlrtRTEInfo nc_emlrtRTEI = { 46,/* lineNo */
  15,                                  /* colNo */
  "chcenters",                         /* fName */
  "C:\\Program Files\\MATLAB\\R2016b\\toolbox\\images\\images\\eml\\private\\chcenters.m"/* pName */
};

static emlrtBCInfo hc_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  47,                                  /* lineNo */
  26,                                  /* colNo */
  "",                                  /* aName */
  "chcenters",                         /* fName */
  "C:\\Program Files\\MATLAB\\R2016b\\toolbox\\images\\images\\eml\\private\\chcenters.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo ic_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  47,                                  /* lineNo */
  51,                                  /* colNo */
  "",                                  /* aName */
  "chcenters",                         /* fName */
  "C:\\Program Files\\MATLAB\\R2016b\\toolbox\\images\\images\\eml\\private\\chcenters.m",/* pName */
  0                                    /* checkKind */
};

static emlrtRTEInfo pc_emlrtRTEI = { 79,/* lineNo */
  27,                                  /* colNo */
  "nullAssignment",                    /* fName */
  "C:\\Program Files\\MATLAB\\R2016b\\toolbox\\eml\\eml\\+coder\\+internal\\nullAssignment.m"/* pName */
};

static emlrtRTEInfo qc_emlrtRTEI = { 295,/* lineNo */
  1,                                   /* colNo */
  "nullAssignment",                    /* fName */
  "C:\\Program Files\\MATLAB\\R2016b\\toolbox\\eml\\eml\\+coder\\+internal\\nullAssignment.m"/* pName */
};

static emlrtBCInfo jc_emlrtBCI = { 1,  /* iFirst */
  307200,                              /* iLast */
  53,                                  /* lineNo */
  18,                                  /* colNo */
  "",                                  /* aName */
  "chcenters",                         /* fName */
  "C:\\Program Files\\MATLAB\\R2016b\\toolbox\\images\\images\\eml\\private\\chcenters.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo kc_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  56,                                  /* lineNo */
  27,                                  /* colNo */
  "",                                  /* aName */
  "chcenters",                         /* fName */
  "C:\\Program Files\\MATLAB\\R2016b\\toolbox\\images\\images\\eml\\private\\chcenters.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo lc_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  42,                                  /* lineNo */
  26,                                  /* colNo */
  "",                                  /* aName */
  "chcenters",                         /* fName */
  "C:\\Program Files\\MATLAB\\R2016b\\toolbox\\images\\images\\eml\\private\\chcenters.m",/* pName */
  0                                    /* checkKind */
};

/* Function Definitions */
void chcenters(FindCircleStackData *SD, const emlrtStack *sp, const creal_T
               varargin_1[307200], emxArray_real_T *centers, emxArray_real_T
               *metric)
{
  boolean_T b1;
  int32_T i16;
  int32_T nrowx;
  boolean_T flat;
  boolean_T exitg3;
  real_T imSize[2];
  boolean_T p;
  boolean_T exitg2;
  boolean_T conn[9];
  real_T connSize[2];
  emxArray_struct_T *s;
  int32_T idx;
  int32_T i17;
  emxArray_real_T *x;
  emxArray_real_T *b_x;
  int32_T iv14[2];
  int32_T iv15[2];
  int32_T b_idx;
  int32_T j;
  emxArray_real_T *b_varargin_1;
  int32_T loop_ub;
  boolean_T guard1 = false;
  emxArray_real_T *varargin_2;
  boolean_T exitg1;
  emxArray_int32_T *c_idx;
  emxArray_real_T *b_metric;
  emxArray_int32_T *b_sortIdx;
  emxArray_int32_T *iidx;
  emxArray_int32_T *c_sortIdx;
  emxArray_real_T *b_centers;
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
  b1 = false;
  i16 = centers->size[0] * centers->size[1];
  centers->size[0] = 0;
  centers->size[1] = 0;
  emxEnsureCapacity(sp, (emxArray__common *)centers, i16, (int32_T)sizeof(real_T),
                    &fb_emlrtRTEI);
  i16 = metric->size[0] * metric->size[1];
  metric->size[0] = 0;
  metric->size[1] = 0;
  emxEnsureCapacity(sp, (emxArray__common *)metric, i16, (int32_T)sizeof(real_T),
                    &fb_emlrtRTEI);
  for (nrowx = 0; nrowx < 307200; nrowx++) {
    SD->u1.f0.accumMatrixRe[nrowx] = muDoubleScalarHypot(varargin_1[nrowx].re,
      varargin_1[nrowx].im);
  }

  for (i16 = 0; i16 < 307200; i16++) {
    SD->u1.f0.bw[i16] = (SD->u1.f0.accumMatrixRe[i16] == SD->
                         u1.f0.accumMatrixRe[0]);
  }

  flat = true;
  nrowx = 0;
  exitg3 = false;
  while ((!exitg3) && (nrowx < 307200)) {
    if (!SD->u1.f0.bw[nrowx]) {
      flat = false;
      exitg3 = true;
    } else {
      nrowx++;
    }
  }

  if (!flat) {
    st.site = &ae_emlrtRSI;
    b_st.site = &he_emlrtRSI;
    ordfilt2(&b_st, SD->u1.f0.accumMatrixRe, SD->u1.f0.Hd);
    st.site = &be_emlrtRSI;
    b_st.site = &xe_emlrtRSI;
    for (i16 = 0; i16 < 307200; i16++) {
      SD->u1.f0.marker[i16] = SD->u1.f0.Hd[i16] - 0.15;
    }

    c_st.site = &ye_emlrtRSI;
    validateattributes(&c_st, SD->u1.f0.marker);
    c_st.site = &af_emlrtRSI;
    validateattributes(&c_st, SD->u1.f0.Hd);
    memcpy(&SD->u1.f0.mask[0], &SD->u1.f0.Hd[0], 307200U * sizeof(real_T));
    for (i16 = 0; i16 < 2; i16++) {
      imSize[i16] = 480.0 + 160.0 * (real_T)i16;
    }

    memcpy(&SD->u1.f0.Hd[0], &SD->u1.f0.marker[0], 307200U * sizeof(real_T));
    ippreconstruct_real64(SD->u1.f0.Hd, SD->u1.f0.mask, imSize, 2.0);
    st.site = &ce_emlrtRSI;
    b_st.site = &cf_emlrtRSI;
    p = true;
    nrowx = 0;
    exitg2 = false;
    while ((!exitg2) && (nrowx < 307200)) {
      if (!muDoubleScalarIsNaN(SD->u1.f0.Hd[nrowx])) {
        nrowx++;
      } else {
        p = false;
        exitg2 = true;
      }
    }

    if (!p) {
      emlrtErrMsgIdAndExplicitTxt(&b_st, &oc_emlrtRTEI,
        "MATLAB:imregionalmax:expectedNonNaN", 42,
        "Expected input number 1, I, to be non-NaN.");
    }

    b_st.site = &df_emlrtRSI;
    for (nrowx = 0; nrowx < 307200; nrowx++) {
      if (muDoubleScalarIsNaN(SD->u1.f0.Hd[nrowx])) {
        c_st.site = &yd_emlrtRSI;
        error(&c_st);
      }
    }

    b_st.site = &ef_emlrtRSI;
    for (i16 = 0; i16 < 2; i16++) {
      imSize[i16] = 480.0 + 160.0 * (real_T)i16;
    }

    for (i16 = 0; i16 < 9; i16++) {
      conn[i16] = true;
    }

    for (i16 = 0; i16 < 2; i16++) {
      connSize[i16] = 3.0;
    }

    emxInit_struct_T(&b_st, &s, 1, &gb_emlrtRTEI, true);
    imregionalmax_real64(SD->u1.f0.Hd, SD->u1.f0.bw, 2.0, imSize, conn, 2.0,
                         connSize);
    st.site = &de_emlrtRSI;
    regionprops(&st, SD->u1.f0.bw, SD->u1.f0.accumMatrixRe, s);
    if (!(s->size[0] == 0)) {
      i16 = centers->size[0] * centers->size[1];
      centers->size[0] = s->size[0];
      centers->size[1] = 2;
      emxEnsureCapacity(sp, (emxArray__common *)centers, i16, (int32_T)sizeof
                        (real_T), &fb_emlrtRTEI);
      for (idx = 0; idx < s->size[0]; idx++) {
        i16 = centers->size[0];
        i17 = idx + 1;
        if (!((i17 >= 1) && (i17 <= i16))) {
          emlrtDynamicBoundsCheckR2012b(i17, 1, i16, &gc_emlrtBCI, sp);
        }

        if (!b1) {
          for (i16 = 0; i16 < 2; i16++) {
            iv14[i16] = 1 + i16;
            iv15[i16] = 1 + i16;
          }

          b1 = true;
        }

        emlrtSubAssignSizeCheckR2012b(iv14, 2, iv15, 2, &b_emlrtECI, sp);
        for (i16 = 0; i16 < 2; i16++) {
          i17 = s->size[0];
          j = 1 + idx;
          if (!((j >= 1) && (j <= i17))) {
            emlrtDynamicBoundsCheckR2012b(j, 1, i17, &lc_emlrtBCI, sp);
          }

          centers->data[idx + centers->size[0] * i16] = s->data[j - 1].
            WeightedCentroid[i16];
        }
      }

      i16 = centers->size[0];
      i17 = (int32_T)((1.0 + (-1.0 - (real_T)centers->size[0])) / -1.0);
      emlrtForLoopVectorCheckR2012b(centers->size[0], -1.0, 1.0, mxDOUBLE_CLASS,
        i17, &nc_emlrtRTEI, sp);
      idx = 0;
      emxInit_real_T1(sp, &x, 2, &fb_emlrtRTEI, true);
      emxInit_real_T1(sp, &b_x, 2, &fb_emlrtRTEI, true);
      while (idx <= i17 - 1) {
        b_idx = i16 - idx;
        j = centers->size[0];
        if (!((b_idx >= 1) && (b_idx <= j))) {
          emlrtDynamicBoundsCheckR2012b(b_idx, 1, j, &hc_emlrtBCI, sp);
        }

        guard1 = false;
        if (muDoubleScalarIsNaN(centers->data[b_idx - 1])) {
          guard1 = true;
        } else {
          j = centers->size[0];
          if (!((b_idx >= 1) && (b_idx <= j))) {
            emlrtDynamicBoundsCheckR2012b(b_idx, 1, j, &ic_emlrtBCI, sp);
          }

          if (muDoubleScalarIsNaN(centers->data[(b_idx + centers->size[0]) - 1]))
          {
            guard1 = true;
          }
        }

        if (guard1) {
          st.site = &ee_emlrtRSI;
          b_st.site = &ug_emlrtRSI;
          p = true;
          if (b_idx > centers->size[0]) {
            p = false;
          }

          if (!p) {
            emlrtErrorWithMessageIdR2012b(&b_st, &pc_emlrtRTEI,
              "MATLAB:subsdeldimmismatch", 0);
          }

          b_st.site = &vg_emlrtRSI;
          j = x->size[0] * x->size[1];
          x->size[0] = centers->size[0];
          x->size[1] = centers->size[1];
          emxEnsureCapacity(&b_st, (emxArray__common *)x, j, (int32_T)sizeof
                            (real_T), &fb_emlrtRTEI);
          loop_ub = centers->size[0] * centers->size[1];
          for (j = 0; j < loop_ub; j++) {
            x->data[j] = centers->data[j];
          }

          nrowx = centers->size[0];
          for (j = 0; j < 2; j++) {
            for (loop_ub = b_idx; loop_ub < nrowx; loop_ub++) {
              x->data[(loop_ub + x->size[0] * j) - 1] = x->data[loop_ub +
                x->size[0] * j];
            }
          }

          if (!(centers->size[0] - 1 <= centers->size[0])) {
            emlrtErrorWithMessageIdR2012b(&b_st, &qc_emlrtRTEI,
              "Coder:builtins:AssertionFailed", 0);
          }

          if (1 > centers->size[0] - 1) {
            loop_ub = 0;
          } else {
            loop_ub = centers->size[0] - 1;
          }

          j = b_x->size[0] * b_x->size[1];
          b_x->size[0] = loop_ub;
          b_x->size[1] = 2;
          emxEnsureCapacity(&b_st, (emxArray__common *)b_x, j, (int32_T)sizeof
                            (real_T), &fb_emlrtRTEI);
          for (j = 0; j < 2; j++) {
            for (nrowx = 0; nrowx < loop_ub; nrowx++) {
              b_x->data[nrowx + b_x->size[0] * j] = x->data[nrowx + x->size[0] *
                j];
            }
          }

          j = x->size[0] * x->size[1];
          x->size[0] = b_x->size[0];
          x->size[1] = 2;
          emxEnsureCapacity(&b_st, (emxArray__common *)x, j, (int32_T)sizeof
                            (real_T), &fb_emlrtRTEI);
          for (j = 0; j < 2; j++) {
            loop_ub = b_x->size[0];
            for (nrowx = 0; nrowx < loop_ub; nrowx++) {
              x->data[nrowx + x->size[0] * j] = b_x->data[nrowx + b_x->size[0] *
                j];
            }
          }

          j = centers->size[0] * centers->size[1];
          centers->size[0] = x->size[0];
          centers->size[1] = 2;
          emxEnsureCapacity(sp, (emxArray__common *)centers, j, (int32_T)sizeof
                            (real_T), &fb_emlrtRTEI);
          loop_ub = x->size[0] * x->size[1];
          for (j = 0; j < loop_ub; j++) {
            centers->data[j] = x->data[j];
          }
        }

        idx++;
      }

      emxFree_real_T(&b_x);
      emxFree_real_T(&x);
      if (!(centers->size[0] == 0)) {
        emxInit_real_T(sp, &b_varargin_1, 1, &fb_emlrtRTEI, true);
        loop_ub = centers->size[0];
        i16 = b_varargin_1->size[0];
        b_varargin_1->size[0] = loop_ub;
        emxEnsureCapacity(sp, (emxArray__common *)b_varargin_1, i16, (int32_T)
                          sizeof(real_T), &fb_emlrtRTEI);
        for (i16 = 0; i16 < loop_ub; i16++) {
          b_varargin_1->data[i16] = centers->data[i16 + centers->size[0]];
        }

        emxInit_real_T(sp, &varargin_2, 1, &fb_emlrtRTEI, true);
        st.site = &fe_emlrtRSI;
        b_round(&st, b_varargin_1);
        loop_ub = centers->size[0];
        i16 = varargin_2->size[0];
        varargin_2->size[0] = loop_ub;
        emxEnsureCapacity(sp, (emxArray__common *)varargin_2, i16, (int32_T)
                          sizeof(real_T), &fb_emlrtRTEI);
        for (i16 = 0; i16 < loop_ub; i16++) {
          varargin_2->data[i16] = centers->data[i16];
        }

        st.site = &fe_emlrtRSI;
        b_round(&st, varargin_2);
        st.site = &fe_emlrtRSI;
        b_st.site = &vd_emlrtRSI;
        if (!allinrange(b_varargin_1, 480)) {
          emlrtErrorWithMessageIdR2012b(&b_st, &hc_emlrtRTEI,
            "MATLAB:sub2ind:IndexOutOfRange", 0);
        }

        imSize[0] = b_varargin_1->size[0];
        imSize[1] = 1.0;
        connSize[0] = varargin_2->size[0];
        connSize[1] = 1.0;
        p = false;
        flat = true;
        nrowx = 0;
        exitg1 = false;
        while ((!exitg1) && (nrowx < 2)) {
          if (!(imSize[nrowx] == connSize[nrowx])) {
            flat = false;
            exitg1 = true;
          } else {
            nrowx++;
          }
        }

        if (flat) {
          p = true;
        }

        if (!p) {
          emlrtErrorWithMessageIdR2012b(&b_st, &ic_emlrtRTEI,
            "MATLAB:sub2ind:SubscriptVectorSize", 0);
        }

        if (!allinrange(varargin_2, 640)) {
          emlrtErrorWithMessageIdR2012b(&b_st, &hc_emlrtRTEI,
            "MATLAB:sub2ind:IndexOutOfRange", 0);
        }

        emxInit_int32_T(&b_st, &c_idx, 1, &fb_emlrtRTEI, true);
        i16 = c_idx->size[0];
        c_idx->size[0] = b_varargin_1->size[0];
        emxEnsureCapacity(&b_st, (emxArray__common *)c_idx, i16, (int32_T)sizeof
                          (int32_T), &fb_emlrtRTEI);
        loop_ub = b_varargin_1->size[0];
        for (i16 = 0; i16 < loop_ub; i16++) {
          c_idx->data[i16] = (int32_T)b_varargin_1->data[i16] + 480 * ((int32_T)
            varargin_2->data[i16] - 1);
        }

        emxFree_real_T(&varargin_2);
        i16 = b_varargin_1->size[0];
        b_varargin_1->size[0] = c_idx->size[0];
        emxEnsureCapacity(sp, (emxArray__common *)b_varargin_1, i16, (int32_T)
                          sizeof(real_T), &fb_emlrtRTEI);
        loop_ub = c_idx->size[0];
        for (i16 = 0; i16 < loop_ub; i16++) {
          i17 = c_idx->data[i16];
          if (!((i17 >= 1) && (i17 <= 307200))) {
            emlrtDynamicBoundsCheckR2012b(i17, 1, 307200, &jc_emlrtBCI, sp);
          }

          b_varargin_1->data[i16] = SD->u1.f0.Hd[i17 - 1];
        }

        emxInit_real_T1(sp, &b_metric, 2, &fb_emlrtRTEI, true);
        st.site = &ge_emlrtRSI;
        i16 = b_metric->size[0] * b_metric->size[1];
        b_metric->size[0] = c_idx->size[0];
        b_metric->size[1] = 1;
        emxEnsureCapacity(&st, (emxArray__common *)b_metric, i16, (int32_T)
                          sizeof(real_T), &fb_emlrtRTEI);
        loop_ub = c_idx->size[0];
        emxFree_int32_T(&c_idx);
        for (i16 = 0; i16 < loop_ub; i16++) {
          b_metric->data[i16] = b_varargin_1->data[i16];
        }

        emxFree_real_T(&b_varargin_1);
        emxInit_int32_T1(&st, &b_sortIdx, 2, &fb_emlrtRTEI, true);
        emxInit_int32_T1(&st, &iidx, 2, &fb_emlrtRTEI, true);
        b_st.site = &bh_emlrtRSI;
        sort(&b_st, b_metric, iidx);
        i16 = b_sortIdx->size[0] * b_sortIdx->size[1];
        b_sortIdx->size[0] = iidx->size[0];
        b_sortIdx->size[1] = 1;
        emxEnsureCapacity(&st, (emxArray__common *)b_sortIdx, i16, (int32_T)
                          sizeof(int32_T), &fb_emlrtRTEI);
        loop_ub = iidx->size[0] * iidx->size[1];
        for (i16 = 0; i16 < loop_ub; i16++) {
          b_sortIdx->data[i16] = iidx->data[i16];
        }

        emxFree_int32_T(&iidx);
        i16 = metric->size[0] * metric->size[1];
        metric->size[0] = b_metric->size[0];
        metric->size[1] = 1;
        emxEnsureCapacity(sp, (emxArray__common *)metric, i16, (int32_T)sizeof
                          (real_T), &fb_emlrtRTEI);
        loop_ub = b_metric->size[0] * b_metric->size[1];
        for (i16 = 0; i16 < loop_ub; i16++) {
          metric->data[i16] = b_metric->data[i16];
        }

        emxFree_real_T(&b_metric);
        emxInit_int32_T1(sp, &c_sortIdx, 2, &fb_emlrtRTEI, true);
        nrowx = centers->size[0];
        i16 = c_sortIdx->size[0] * c_sortIdx->size[1];
        c_sortIdx->size[0] = b_sortIdx->size[0];
        c_sortIdx->size[1] = 1;
        emxEnsureCapacity(sp, (emxArray__common *)c_sortIdx, i16, (int32_T)
                          sizeof(int32_T), &fb_emlrtRTEI);
        loop_ub = b_sortIdx->size[0];
        for (i16 = 0; i16 < loop_ub; i16++) {
          i17 = b_sortIdx->data[i16];
          if (!((i17 >= 1) && (i17 <= nrowx))) {
            emlrtDynamicBoundsCheckR2012b(i17, 1, nrowx, &kc_emlrtBCI, sp);
          }

          c_sortIdx->data[i16] = i17;
        }

        emxInit_real_T1(sp, &b_centers, 2, &fb_emlrtRTEI, true);
        nrowx = b_sortIdx->size[0];
        i16 = b_centers->size[0] * b_centers->size[1];
        b_centers->size[0] = nrowx;
        b_centers->size[1] = 2;
        emxEnsureCapacity(sp, (emxArray__common *)b_centers, i16, (int32_T)
                          sizeof(real_T), &fb_emlrtRTEI);
        emxFree_int32_T(&b_sortIdx);
        for (i16 = 0; i16 < 2; i16++) {
          for (i17 = 0; i17 < nrowx; i17++) {
            b_centers->data[i17 + b_centers->size[0] * i16] = centers->data
              [(c_sortIdx->data[i17] + centers->size[0] * i16) - 1];
          }
        }

        emxFree_int32_T(&c_sortIdx);
        i16 = centers->size[0] * centers->size[1];
        centers->size[0] = b_centers->size[0];
        centers->size[1] = b_centers->size[1];
        emxEnsureCapacity(sp, (emxArray__common *)centers, i16, (int32_T)sizeof
                          (real_T), &fb_emlrtRTEI);
        loop_ub = b_centers->size[1];
        for (i16 = 0; i16 < loop_ub; i16++) {
          nrowx = b_centers->size[0];
          for (i17 = 0; i17 < nrowx; i17++) {
            centers->data[i17 + centers->size[0] * i16] = b_centers->data[i17 +
              b_centers->size[0] * i16];
          }
        }

        emxFree_real_T(&b_centers);
      }
    }

    emxFree_struct_T(&s);
  }

  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

/* End of code generation (chcenters.c) */
