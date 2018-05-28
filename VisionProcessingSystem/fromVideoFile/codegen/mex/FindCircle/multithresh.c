/*
 * Sponsored License - for use in support of a program or activity
 * sponsored by MathWorks.  Not for government, commercial or other
 * non-sponsored organizational use.
 *
 * multithresh.c
 *
 * Code generation for function 'multithresh'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "FindCircle.h"
#include "multithresh.h"
#include "FindCircle_emxutil.h"
#include "sortIdx.h"
#include "eml_int_forloop_overflow_check.h"
#include "nullAssignment.h"
#include "indexShapeCheck.h"
#include "unique.h"
#include "isfinite.h"
#include "warning.h"
#include "sum.h"
#include "imhist.h"
#include "im2uint8.h"
#include "FindCircle_data.h"

/* Variable Definitions */
static emlrtRSInfo hb_emlrtRSI = { 24, /* lineNo */
  "multithresh",                       /* fcnName */
  "C:\\Program Files\\MATLAB\\R2016b\\toolbox\\images\\images\\eml\\multithresh.m"/* pathName */
};

static emlrtRSInfo ib_emlrtRSI = { 28, /* lineNo */
  "multithresh",                       /* fcnName */
  "C:\\Program Files\\MATLAB\\R2016b\\toolbox\\images\\images\\eml\\multithresh.m"/* pathName */
};

static emlrtRSInfo jb_emlrtRSI = { 44, /* lineNo */
  "multithresh",                       /* fcnName */
  "C:\\Program Files\\MATLAB\\R2016b\\toolbox\\images\\images\\eml\\multithresh.m"/* pathName */
};

static emlrtRSInfo kb_emlrtRSI = { 73, /* lineNo */
  "multithresh",                       /* fcnName */
  "C:\\Program Files\\MATLAB\\R2016b\\toolbox\\images\\images\\eml\\multithresh.m"/* pathName */
};

static emlrtRSInfo lb_emlrtRSI = { 75, /* lineNo */
  "multithresh",                       /* fcnName */
  "C:\\Program Files\\MATLAB\\R2016b\\toolbox\\images\\images\\eml\\multithresh.m"/* pathName */
};

static emlrtRSInfo mb_emlrtRSI = { 77, /* lineNo */
  "multithresh",                       /* fcnName */
  "C:\\Program Files\\MATLAB\\R2016b\\toolbox\\images\\images\\eml\\multithresh.m"/* pathName */
};

static emlrtRSInfo nb_emlrtRSI = { 79, /* lineNo */
  "multithresh",                       /* fcnName */
  "C:\\Program Files\\MATLAB\\R2016b\\toolbox\\images\\images\\eml\\multithresh.m"/* pathName */
};

static emlrtRSInfo ob_emlrtRSI = { 121,/* lineNo */
  "multithresh",                       /* fcnName */
  "C:\\Program Files\\MATLAB\\R2016b\\toolbox\\images\\images\\eml\\multithresh.m"/* pathName */
};

static emlrtRSInfo pb_emlrtRSI = { 123,/* lineNo */
  "multithresh",                       /* fcnName */
  "C:\\Program Files\\MATLAB\\R2016b\\toolbox\\images\\images\\eml\\multithresh.m"/* pathName */
};

static emlrtRSInfo qb_emlrtRSI = { 124,/* lineNo */
  "multithresh",                       /* fcnName */
  "C:\\Program Files\\MATLAB\\R2016b\\toolbox\\images\\images\\eml\\multithresh.m"/* pathName */
};

static emlrtRSInfo rb_emlrtRSI = { 127,/* lineNo */
  "multithresh",                       /* fcnName */
  "C:\\Program Files\\MATLAB\\R2016b\\toolbox\\images\\images\\eml\\multithresh.m"/* pathName */
};

static emlrtRSInfo sb_emlrtRSI = { 212,/* lineNo */
  "multithresh",                       /* fcnName */
  "C:\\Program Files\\MATLAB\\R2016b\\toolbox\\images\\images\\eml\\multithresh.m"/* pathName */
};

static emlrtRSInfo tb_emlrtRSI = { 213,/* lineNo */
  "multithresh",                       /* fcnName */
  "C:\\Program Files\\MATLAB\\R2016b\\toolbox\\images\\images\\eml\\multithresh.m"/* pathName */
};

static emlrtRSInfo fc_emlrtRSI = { 340,/* lineNo */
  "multithresh",                       /* fcnName */
  "C:\\Program Files\\MATLAB\\R2016b\\toolbox\\images\\images\\eml\\multithresh.m"/* pathName */
};

static emlrtRSInfo gc_emlrtRSI = { 345,/* lineNo */
  "multithresh",                       /* fcnName */
  "C:\\Program Files\\MATLAB\\R2016b\\toolbox\\images\\images\\eml\\multithresh.m"/* pathName */
};

static emlrtRSInfo hc_emlrtRSI = { 44, /* lineNo */
  "unique",                            /* fcnName */
  "C:\\Program Files\\MATLAB\\R2016b\\toolbox\\eml\\lib\\matlab\\ops\\unique.m"/* pathName */
};

static emlrtRSInfo ic_emlrtRSI = { 226,/* lineNo */
  "unique",                            /* fcnName */
  "C:\\Program Files\\MATLAB\\R2016b\\toolbox\\eml\\lib\\matlab\\ops\\unique.m"/* pathName */
};

static emlrtRSInfo jc_emlrtRSI = { 220,/* lineNo */
  "unique",                            /* fcnName */
  "C:\\Program Files\\MATLAB\\R2016b\\toolbox\\eml\\lib\\matlab\\ops\\unique.m"/* pathName */
};

static emlrtRSInfo kc_emlrtRSI = { 212,/* lineNo */
  "unique",                            /* fcnName */
  "C:\\Program Files\\MATLAB\\R2016b\\toolbox\\eml\\lib\\matlab\\ops\\unique.m"/* pathName */
};

static emlrtRSInfo lc_emlrtRSI = { 201,/* lineNo */
  "unique",                            /* fcnName */
  "C:\\Program Files\\MATLAB\\R2016b\\toolbox\\eml\\lib\\matlab\\ops\\unique.m"/* pathName */
};

static emlrtRSInfo mc_emlrtRSI = { 188,/* lineNo */
  "unique",                            /* fcnName */
  "C:\\Program Files\\MATLAB\\R2016b\\toolbox\\eml\\lib\\matlab\\ops\\unique.m"/* pathName */
};

static emlrtRSInfo nc_emlrtRSI = { 163,/* lineNo */
  "unique",                            /* fcnName */
  "C:\\Program Files\\MATLAB\\R2016b\\toolbox\\eml\\lib\\matlab\\ops\\unique.m"/* pathName */
};

static emlrtRSInfo oc_emlrtRSI = { 152,/* lineNo */
  "unique",                            /* fcnName */
  "C:\\Program Files\\MATLAB\\R2016b\\toolbox\\eml\\lib\\matlab\\ops\\unique.m"/* pathName */
};

static emlrtRTEInfo q_emlrtRTEI = { 1, /* lineNo */
  29,                                  /* colNo */
  "multithresh",                       /* fName */
  "C:\\Program Files\\MATLAB\\R2016b\\toolbox\\images\\images\\eml\\multithresh.m"/* pName */
};

static emlrtRTEInfo r_emlrtRTEI = { 15,/* lineNo */
  5,                                   /* colNo */
  "multithresh",                       /* fName */
  "C:\\Program Files\\MATLAB\\R2016b\\toolbox\\images\\images\\eml\\multithresh.m"/* pName */
};

static emlrtRTEInfo s_emlrtRTEI = { 66,/* lineNo */
  17,                                  /* colNo */
  "multithresh",                       /* fName */
  "C:\\Program Files\\MATLAB\\R2016b\\toolbox\\images\\images\\eml\\multithresh.m"/* pName */
};

static emlrtRTEInfo t_emlrtRTEI = { 163,/* lineNo */
  43,                                  /* colNo */
  "multithresh",                       /* fName */
  "C:\\Program Files\\MATLAB\\R2016b\\toolbox\\images\\images\\eml\\multithresh.m"/* pName */
};

static emlrtRTEInfo v_emlrtRTEI = { 338,/* lineNo */
  39,                                  /* colNo */
  "multithresh",                       /* fName */
  "C:\\Program Files\\MATLAB\\R2016b\\toolbox\\images\\images\\eml\\multithresh.m"/* pName */
};

static emlrtRTEInfo w_emlrtRTEI = { 220,/* lineNo */
  1,                                   /* colNo */
  "unique",                            /* fName */
  "C:\\Program Files\\MATLAB\\R2016b\\toolbox\\eml\\lib\\matlab\\ops\\unique.m"/* pName */
};

static emlrtRTEInfo x_emlrtRTEI = { 377,/* lineNo */
  19,                                  /* colNo */
  "multithresh",                       /* fName */
  "C:\\Program Files\\MATLAB\\R2016b\\toolbox\\images\\images\\eml\\multithresh.m"/* pName */
};

static emlrtRTEInfo bb_emlrtRTEI = { 329,/* lineNo */
  22,                                  /* colNo */
  "multithresh",                       /* fName */
  "C:\\Program Files\\MATLAB\\R2016b\\toolbox\\images\\images\\eml\\multithresh.m"/* pName */
};

static emlrtBCInfo ac_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  139,                                 /* lineNo */
  17,                                  /* colNo */
  "",                                  /* aName */
  "multithresh",                       /* fName */
  "C:\\Program Files\\MATLAB\\R2016b\\toolbox\\images\\images\\eml\\multithresh.m",/* pName */
  0                                    /* checkKind */
};

static emlrtECInfo emlrtECI = { 2,     /* nDims */
  345,                                 /* lineNo */
  12,                                  /* colNo */
  "multithresh",                       /* fName */
  "C:\\Program Files\\MATLAB\\R2016b\\toolbox\\images\\images\\eml\\multithresh.m"/* pName */
};

/* Function Declarations */
static void checkForDegenerateInput(FindCircleStackData *SD, const emlrtStack
  *sp, const real32_T A[307200], boolean_T *isDegenerate, emxArray_real32_T
  *uniqueVals);
static void getDegenerateThresholds(const emlrtStack *sp, const
  emxArray_real32_T *uniqueVals, emxArray_real32_T *thresh);
static void map2OriginalScale(const emlrtStack *sp, const emxArray_real_T
  *thresh, real32_T minA, real32_T maxA, emxArray_real32_T *sclThresh);

/* Function Definitions */
static void checkForDegenerateInput(FindCircleStackData *SD, const emlrtStack
  *sp, const real32_T A[307200], boolean_T *isDegenerate, emxArray_real32_T
  *uniqueVals)
{
  emxArray_real32_T *b;
  int32_T khi;
  int32_T k;
  int32_T k0;
  int32_T nInf;
  int32_T nNaN;
  int32_T nb;
  real32_T x;
  int32_T exitg1;
  real32_T absxk;
  int32_T exponent;
  boolean_T p;
  int32_T iv5[2];
  emxArray_boolean_T *r2;
  emxArray_boolean_T *r3;
  int32_T iv6[2];
  int32_T iv7[2];
  emxArray_boolean_T *r4;
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b(sp);
  emxInit_real32_T1(sp, &b, 1, &v_emlrtRTEI, true);
  st.site = &fc_emlrtRSI;
  b_st.site = &hc_emlrtRSI;
  c_st.site = &oc_emlrtRSI;
  sortIdx(SD, A, SD->f4.idx);
  khi = b->size[0];
  b->size[0] = 307200;
  emxEnsureCapacity(&b_st, (emxArray__common *)b, khi, (int32_T)sizeof(real32_T),
                    &v_emlrtRTEI);
  for (k = 0; k < 307200; k++) {
    b->data[k] = A[SD->f4.idx[k] - 1];
  }

  count_nonfinites(b, &k, &k0, &nInf, &nNaN);
  nb = 0;
  if (k > 0) {
    nb = 1;
    c_st.site = &nc_emlrtRSI;
    if (k > 2147483646) {
      d_st.site = &w_emlrtRSI;
      check_forloop_overflow_error(&d_st);
    }
  }

  khi = k + k0;
  while (k + 1 <= khi) {
    x = b->data[k];
    k0 = k;
    do {
      exitg1 = 0;
      k++;
      if (k + 1 > khi) {
        exitg1 = 1;
      } else {
        absxk = muSingleScalarAbs(x / 2.0F);
        if ((!muSingleScalarIsInf(absxk)) && (!muSingleScalarIsNaN(absxk))) {
          if (absxk <= 1.17549435E-38F) {
            absxk = 1.4013E-45F;
          } else {
            frexp(absxk, &exponent);
            absxk = (real32_T)ldexp(1.0, exponent - 24);
          }
        } else {
          absxk = ((real32_T)rtNaN);
        }

        if ((muSingleScalarAbs(x - b->data[k]) < absxk) || (muSingleScalarIsInf
             (b->data[k]) && muSingleScalarIsInf(x) && ((b->data[k] > 0.0F) ==
              (x > 0.0F)))) {
          p = true;
        } else {
          p = false;
        }

        if (!p) {
          exitg1 = 1;
        }
      }
    } while (exitg1 == 0);

    nb++;
    b->data[nb - 1] = x;
    c_st.site = &mc_emlrtRSI;
    if ((!(k0 + 1 > k)) && (k > 2147483646)) {
      d_st.site = &w_emlrtRSI;
      check_forloop_overflow_error(&d_st);
    }
  }

  if (nInf > 0) {
    nb++;
    b->data[nb - 1] = b->data[khi];
    c_st.site = &lc_emlrtRSI;
    if (nInf > 2147483646) {
      d_st.site = &w_emlrtRSI;
      check_forloop_overflow_error(&d_st);
    }
  }

  k = khi + nInf;
  c_st.site = &kc_emlrtRSI;
  if ((!(1 > nNaN)) && (nNaN > 2147483646)) {
    d_st.site = &w_emlrtRSI;
    check_forloop_overflow_error(&d_st);
  }

  for (k0 = 1; k0 <= nNaN; k0++) {
    nb++;
    b->data[nb - 1] = b->data[(k + k0) - 1];
  }

  if (1 > nb) {
    khi = 0;
  } else {
    khi = nb;
  }

  iv5[0] = 1;
  iv5[1] = khi;
  c_st.site = &jc_emlrtRSI;
  indexShapeCheck(&c_st, 307200, iv5);
  k0 = b->size[0];
  b->size[0] = khi;
  emxEnsureCapacity(&b_st, (emxArray__common *)b, k0, (int32_T)sizeof(real32_T),
                    &w_emlrtRTEI);
  c_st.site = &ic_emlrtRSI;
  if ((!(1 > nb)) && (nb > 2147483646)) {
    d_st.site = &w_emlrtRSI;
    check_forloop_overflow_error(&d_st);
  }

  khi = uniqueVals->size[0] * uniqueVals->size[1];
  uniqueVals->size[0] = 1;
  uniqueVals->size[1] = b->size[0];
  emxEnsureCapacity(sp, (emxArray__common *)uniqueVals, khi, (int32_T)sizeof
                    (real32_T), &v_emlrtRTEI);
  k0 = b->size[0];
  for (khi = 0; khi < k0; khi++) {
    uniqueVals->data[uniqueVals->size[0] * khi] = b->data[khi];
  }

  emxFree_real32_T(&b);
  emxInit_boolean_T(sp, &r2, 2, &v_emlrtRTEI, true);
  khi = r2->size[0] * r2->size[1];
  r2->size[0] = 1;
  r2->size[1] = uniqueVals->size[1];
  emxEnsureCapacity(sp, (emxArray__common *)r2, khi, (int32_T)sizeof(boolean_T),
                    &v_emlrtRTEI);
  k0 = uniqueVals->size[0] * uniqueVals->size[1];
  for (khi = 0; khi < k0; khi++) {
    r2->data[khi] = muSingleScalarIsInf(uniqueVals->data[khi]);
  }

  emxInit_boolean_T(sp, &r3, 2, &v_emlrtRTEI, true);
  khi = r3->size[0] * r3->size[1];
  r3->size[0] = 1;
  r3->size[1] = uniqueVals->size[1];
  emxEnsureCapacity(sp, (emxArray__common *)r3, khi, (int32_T)sizeof(boolean_T),
                    &v_emlrtRTEI);
  k0 = uniqueVals->size[0] * uniqueVals->size[1];
  for (khi = 0; khi < k0; khi++) {
    r3->data[khi] = muSingleScalarIsNaN(uniqueVals->data[khi]);
  }

  for (khi = 0; khi < 2; khi++) {
    iv6[khi] = r2->size[khi];
  }

  for (khi = 0; khi < 2; khi++) {
    iv7[khi] = r3->size[khi];
  }

  emxInit_boolean_T(sp, &r4, 2, &v_emlrtRTEI, true);
  if ((iv6[0] != iv7[0]) || (iv6[1] != iv7[1])) {
    emlrtSizeEqCheckNDR2012b(&iv6[0], &iv7[0], &emlrtECI, sp);
  }

  khi = r4->size[0] * r4->size[1];
  r4->size[0] = 1;
  r4->size[1] = r2->size[1];
  emxEnsureCapacity(sp, (emxArray__common *)r4, khi, (int32_T)sizeof(boolean_T),
                    &v_emlrtRTEI);
  k0 = r2->size[0] * r2->size[1];
  for (khi = 0; khi < k0; khi++) {
    r4->data[khi] = (r2->data[khi] || r3->data[khi]);
  }

  emxFree_boolean_T(&r3);
  emxFree_boolean_T(&r2);
  st.site = &gc_emlrtRSI;
  nullAssignment(&st, uniqueVals, r4);
  *isDegenerate = (uniqueVals->size[1] <= 1);
  emxFree_boolean_T(&r4);
  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

static void getDegenerateThresholds(const emlrtStack *sp, const
  emxArray_real32_T *uniqueVals, emxArray_real32_T *thresh)
{
  int32_T i12;
  int32_T loop_ub;
  if (uniqueVals->size[1] == 0) {
    i12 = thresh->size[0] * thresh->size[1];
    thresh->size[0] = 1;
    thresh->size[1] = 1;
    emxEnsureCapacity(sp, (emxArray__common *)thresh, i12, (int32_T)sizeof
                      (real32_T), &x_emlrtRTEI);
    thresh->data[0] = 1.0F;
  } else {
    i12 = thresh->size[0] * thresh->size[1];
    thresh->size[0] = 1;
    thresh->size[1] = uniqueVals->size[1];
    emxEnsureCapacity(sp, (emxArray__common *)thresh, i12, (int32_T)sizeof
                      (real32_T), &x_emlrtRTEI);
    loop_ub = uniqueVals->size[0] * uniqueVals->size[1];
    for (i12 = 0; i12 < loop_ub; i12++) {
      thresh->data[i12] = uniqueVals->data[i12];
    }
  }
}

static void map2OriginalScale(const emlrtStack *sp, const emxArray_real_T
  *thresh, real32_T minA, real32_T maxA, emxArray_real32_T *sclThresh)
{
  real_T b;
  int32_T i15;
  int32_T loop_ub;
  b = (real_T)maxA - minA;
  i15 = sclThresh->size[0] * sclThresh->size[1];
  sclThresh->size[0] = 1;
  sclThresh->size[1] = thresh->size[1];
  emxEnsureCapacity(sp, (emxArray__common *)sclThresh, i15, (int32_T)sizeof
                    (real32_T), &bb_emlrtRTEI);
  loop_ub = thresh->size[0] * thresh->size[1];
  for (i15 = 0; i15 < loop_ub; i15++) {
    sclThresh->data[i15] = (real32_T)(minA + thresh->data[i15] / 255.0 * b);
  }
}

real32_T multithresh(FindCircleStackData *SD, const emlrtStack *sp, const
                     real32_T varargin_1[307200])
{
  real32_T thresh;
  boolean_T isvalid_maxval;
  real_T counts[256];
  int32_T idx;
  real32_T mtmp;
  int32_T ix;
  boolean_T exitg3;
  real32_T B;
  real_T x[256];
  boolean_T exitg2;
  real32_T A;
  emxArray_int32_T *r1;
  boolean_T nans;
  real_T b_x[256];
  real_T y;
  emxArray_real32_T *b_A;
  emxArray_uint8_T *c_A;
  boolean_T exitg1;
  emxArray_real32_T *threshout;
  emxArray_real_T *threshRaw;
  emxArray_real32_T *uniqueVals;
  real_T idxSum;
  real_T idxNum;
  emlrtStack st;
  emlrtStack b_st;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b(sp);
  st.site = &hb_emlrtRSI;
  isvalid_maxval = true;
  idx = 1;
  while ((idx <= 307200) && (!b_isfinite(varargin_1[idx - 1]))) {
    idx++;
  }

  if (idx <= 307200) {
    thresh = varargin_1[idx - 1];
    mtmp = varargin_1[idx - 1];
    while (idx + 1 < 307201) {
      if ((varargin_1[idx] < thresh) && b_isfinite(varargin_1[idx])) {
        thresh = varargin_1[idx];
      } else {
        if ((varargin_1[idx] > mtmp) && b_isfinite(varargin_1[idx])) {
          mtmp = varargin_1[idx];
        }
      }

      idx++;
    }

    if (!(thresh == mtmp)) {
      B = mtmp - thresh;
      idx = 0;
      for (ix = 0; ix < 307200; ix++) {
        A = (varargin_1[ix] - thresh) / B;
        nans = muSingleScalarIsNaN(A);
        if (!nans) {
          idx++;
        }

        SD->f5.A[ix] = A;
        SD->f5.nans[ix] = nans;
      }

      if (!(idx == 0)) {
        emxInit_int32_T(&st, &r1, 1, &q_emlrtRTEI, true);
        idx = 0;
        for (ix = 0; ix < 307200; ix++) {
          if (!SD->f5.nans[ix]) {
            idx++;
          }
        }

        ix = r1->size[0];
        r1->size[0] = idx;
        emxEnsureCapacity(&st, (emxArray__common *)r1, ix, (int32_T)sizeof
                          (int32_T), &q_emlrtRTEI);
        idx = 0;
        for (ix = 0; ix < 307200; ix++) {
          if (!SD->f5.nans[ix]) {
            r1->data[idx] = ix + 1;
            idx++;
          }
        }

        emxInit_real32_T1(&st, &b_A, 1, &q_emlrtRTEI, true);
        ix = b_A->size[0];
        b_A->size[0] = r1->size[0];
        emxEnsureCapacity(&st, (emxArray__common *)b_A, ix, (int32_T)sizeof
                          (real32_T), &q_emlrtRTEI);
        idx = r1->size[0];
        for (ix = 0; ix < idx; ix++) {
          b_A->data[ix] = SD->f5.A[r1->data[ix] - 1];
        }

        emxFree_int32_T(&r1);
        emxInit_uint8_T(&st, &c_A, 1, &t_emlrtRTEI, true);
        b_st.site = &sb_emlrtRSI;
        im2uint8(&b_st, b_A, c_A);
        b_st.site = &tb_emlrtRSI;
        imhist(&b_st, c_A, counts);
        y = sum(counts);
        emxFree_real32_T(&b_A);
        emxFree_uint8_T(&c_A);
        for (ix = 0; ix < 256; ix++) {
          counts[ix] /= y;
        }

        isvalid_maxval = false;
      }
    }
  } else {
    idx = 1;
    thresh = varargin_1[0];
    if (muSingleScalarIsNaN(varargin_1[0])) {
      ix = 2;
      exitg3 = false;
      while ((!exitg3) && (ix < 307201)) {
        idx = ix;
        if (!muSingleScalarIsNaN(varargin_1[ix - 1])) {
          thresh = varargin_1[ix - 1];
          exitg3 = true;
        } else {
          ix++;
        }
      }
    }

    if (idx < 307200) {
      while (idx + 1 < 307201) {
        if (varargin_1[idx] < thresh) {
          thresh = varargin_1[idx];
        }

        idx++;
      }
    }

    idx = 1;
    mtmp = varargin_1[0];
    if (muSingleScalarIsNaN(varargin_1[0])) {
      ix = 2;
      exitg2 = false;
      while ((!exitg2) && (ix < 307201)) {
        idx = ix;
        if (!muSingleScalarIsNaN(varargin_1[ix - 1])) {
          mtmp = varargin_1[ix - 1];
          exitg2 = true;
        } else {
          ix++;
        }
      }
    }

    if (idx < 307200) {
      while (idx + 1 < 307201) {
        if (varargin_1[idx] > mtmp) {
          mtmp = varargin_1[idx];
        }

        idx++;
      }
    }
  }

  if (isvalid_maxval) {
    st.site = &ib_emlrtRSI;
    warning(&st);
    if (muSingleScalarIsNaN(thresh)) {
      thresh = 1.0F;
    }
  } else {
    memcpy(&x[0], &counts[0], sizeof(real_T) << 8);
    for (idx = 0; idx < 255; idx++) {
      x[idx + 1] += x[idx];
    }

    for (ix = 0; ix < 256; ix++) {
      b_x[ix] = counts[ix] * (1.0 + (real_T)ix);
    }

    for (idx = 0; idx < 255; idx++) {
      b_x[idx + 1] += b_x[idx];
    }

    st.site = &jb_emlrtRSI;
    y = b_x[255];
    for (ix = 0; ix < 256; ix++) {
      b_x[ix] = y * x[ix] - b_x[ix];
    }

    for (idx = 0; idx < 256; idx++) {
      counts[idx] = b_x[idx] * b_x[idx];
    }

    for (ix = 0; ix < 256; ix++) {
      counts[ix] /= x[ix] * (1.0 - x[ix]);
    }

    idx = 1;
    y = counts[0];
    if (muDoubleScalarIsNaN(counts[0])) {
      ix = 2;
      exitg1 = false;
      while ((!exitg1) && (ix < 257)) {
        idx = ix;
        if (!muDoubleScalarIsNaN(counts[ix - 1])) {
          y = counts[ix - 1];
          exitg1 = true;
        } else {
          ix++;
        }
      }
    }

    if (idx < 256) {
      while (idx + 1 < 257) {
        if (counts[idx] > y) {
          y = counts[idx];
        }

        idx++;
      }
    }

    isvalid_maxval = ((!muDoubleScalarIsInf(y)) && (!muDoubleScalarIsNaN(y)));
    emxInit_real32_T(sp, &threshout, 2, &r_emlrtRTEI, true);
    emxInit_real_T1(sp, &threshRaw, 2, &s_emlrtRTEI, true);
    emxInit_real32_T(sp, &uniqueVals, 2, &q_emlrtRTEI, true);
    if (isvalid_maxval) {
      idxSum = 0.0;
      idxNum = 0.0;
      for (idx = 0; idx < 256; idx++) {
        if (counts[idx] == y) {
          idxSum += 1.0 + (real_T)idx;
          idxNum++;
        }
      }

      ix = threshRaw->size[0] * threshRaw->size[1];
      threshRaw->size[0] = 1;
      threshRaw->size[1] = 1;
      emxEnsureCapacity(sp, (emxArray__common *)threshRaw, ix, (int32_T)sizeof
                        (real_T), &q_emlrtRTEI);
      threshRaw->data[0] = idxSum / idxNum - 1.0;
      map2OriginalScale(sp, threshRaw, thresh, mtmp, threshout);
    } else {
      st.site = &kb_emlrtRSI;
      checkForDegenerateInput(SD, &st, varargin_1, &nans, uniqueVals);
      if (nans) {
        st.site = &lb_emlrtRSI;
        warning(&st);
      } else {
        st.site = &mb_emlrtRSI;
        b_warning(&st);
      }

      st.site = &nb_emlrtRSI;
      getDegenerateThresholds(&st, uniqueVals, threshout);
      ix = threshRaw->size[0] * threshRaw->size[1];
      threshRaw->size[0] = 1;
      threshRaw->size[1] = threshout->size[1];
      emxEnsureCapacity(sp, (emxArray__common *)threshRaw, ix, (int32_T)sizeof
                        (real_T), &q_emlrtRTEI);
      idx = threshout->size[0] * threshout->size[1];
      for (ix = 0; ix < idx; ix++) {
        threshRaw->data[ix] = threshout->data[ix];
      }

      st.site = &ob_emlrtRSI;
      checkForDegenerateInput(SD, &st, varargin_1, &nans, uniqueVals);
      if (nans) {
        st.site = &pb_emlrtRSI;
        warning(&st);
        st.site = &qb_emlrtRSI;
        getDegenerateThresholds(&st, uniqueVals, threshout);
      } else {
        st.site = &rb_emlrtRSI;
        b_warning(&st);
        map2OriginalScale(sp, threshRaw, thresh, mtmp, threshout);
      }
    }

    emxFree_real32_T(&uniqueVals);
    emxFree_real_T(&threshRaw);
    ix = threshout->size[1];
    if (!(1 <= ix)) {
      emlrtDynamicBoundsCheckR2012b(1, 1, ix, &ac_emlrtBCI, sp);
    }

    thresh = threshout->data[0];
    emxFree_real32_T(&threshout);
  }

  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
  return thresh;
}

/* End of code generation (multithresh.c) */
