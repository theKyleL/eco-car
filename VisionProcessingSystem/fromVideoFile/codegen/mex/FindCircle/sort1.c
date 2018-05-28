/*
 * Sponsored License - for use in support of a program or activity
 * sponsored by MathWorks.  Not for government, commercial or other
 * non-sponsored organizational use.
 *
 * sort1.c
 *
 * Code generation for function 'sort1'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "FindCircle.h"
#include "sort1.h"
#include "FindCircle_emxutil.h"
#include "eml_int_forloop_overflow_check.h"
#include "sortIdx.h"
#include "FindCircle_data.h"

/* Variable Definitions */
static emlrtRSInfo ad_emlrtRSI = { 247,/* lineNo */
  "sortIdx",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2016b\\toolbox\\eml\\eml\\+coder\\+internal\\sortIdx.m"/* pathName */
};

static emlrtRSInfo bd_emlrtRSI = { 255,/* lineNo */
  "sortIdx",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2016b\\toolbox\\eml\\eml\\+coder\\+internal\\sortIdx.m"/* pathName */
};

static emlrtRSInfo cd_emlrtRSI = { 256,/* lineNo */
  "sortIdx",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2016b\\toolbox\\eml\\eml\\+coder\\+internal\\sortIdx.m"/* pathName */
};

static emlrtRSInfo dd_emlrtRSI = { 264,/* lineNo */
  "sortIdx",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2016b\\toolbox\\eml\\eml\\+coder\\+internal\\sortIdx.m"/* pathName */
};

static emlrtRSInfo ed_emlrtRSI = { 272,/* lineNo */
  "sortIdx",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2016b\\toolbox\\eml\\eml\\+coder\\+internal\\sortIdx.m"/* pathName */
};

static emlrtRSInfo fd_emlrtRSI = { 329,/* lineNo */
  "sortIdx",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2016b\\toolbox\\eml\\eml\\+coder\\+internal\\sortIdx.m"/* pathName */
};

static emlrtRSInfo gd_emlrtRSI = { 357,/* lineNo */
  "sortIdx",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2016b\\toolbox\\eml\\eml\\+coder\\+internal\\sortIdx.m"/* pathName */
};

static emlrtRSInfo hd_emlrtRSI = { 364,/* lineNo */
  "sortIdx",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2016b\\toolbox\\eml\\eml\\+coder\\+internal\\sortIdx.m"/* pathName */
};

static emlrtRSInfo id_emlrtRSI = { 524,/* lineNo */
  "sortIdx",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2016b\\toolbox\\eml\\eml\\+coder\\+internal\\sortIdx.m"/* pathName */
};

static emlrtRSInfo jd_emlrtRSI = { 526,/* lineNo */
  "sortIdx",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2016b\\toolbox\\eml\\eml\\+coder\\+internal\\sortIdx.m"/* pathName */
};

static emlrtRSInfo kd_emlrtRSI = { 554,/* lineNo */
  "sortIdx",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2016b\\toolbox\\eml\\eml\\+coder\\+internal\\sortIdx.m"/* pathName */
};

static emlrtRSInfo ch_emlrtRSI = { 66, /* lineNo */
  "sort",                              /* fcnName */
  "C:\\Program Files\\MATLAB\\R2016b\\toolbox\\eml\\eml\\+coder\\+internal\\sort.m"/* pathName */
};

static emlrtRSInfo dh_emlrtRSI = { 64, /* lineNo */
  "sortIdx",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2016b\\toolbox\\eml\\eml\\+coder\\+internal\\sortIdx.m"/* pathName */
};

static emlrtRSInfo eh_emlrtRSI = { 65, /* lineNo */
  "sortIdx",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2016b\\toolbox\\eml\\eml\\+coder\\+internal\\sortIdx.m"/* pathName */
};

static emlrtRSInfo fh_emlrtRSI = { 277,/* lineNo */
  "sortIdx",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2016b\\toolbox\\eml\\eml\\+coder\\+internal\\sortIdx.m"/* pathName */
};

static emlrtRSInfo gh_emlrtRSI = { 291,/* lineNo */
  "sortIdx",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2016b\\toolbox\\eml\\eml\\+coder\\+internal\\sortIdx.m"/* pathName */
};

static emlrtRSInfo hh_emlrtRSI = { 300,/* lineNo */
  "sortIdx",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2016b\\toolbox\\eml\\eml\\+coder\\+internal\\sortIdx.m"/* pathName */
};

static emlrtRTEInfo ab_emlrtRTEI = { 1,/* lineNo */
  20,                                  /* colNo */
  "sort",                              /* fName */
  "C:\\Program Files\\MATLAB\\R2016b\\toolbox\\eml\\eml\\+coder\\+internal\\sort.m"/* pName */
};

static emlrtRTEInfo xb_emlrtRTEI = { 322,/* lineNo */
  9,                                   /* colNo */
  "sortIdx",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2016b\\toolbox\\eml\\eml\\+coder\\+internal\\sortIdx.m"/* pName */
};

static emlrtRTEInfo yb_emlrtRTEI = { 324,/* lineNo */
  9,                                   /* colNo */
  "sortIdx",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2016b\\toolbox\\eml\\eml\\+coder\\+internal\\sortIdx.m"/* pName */
};

static emlrtRTEInfo ac_emlrtRTEI = { 247,/* lineNo */
  14,                                  /* colNo */
  "sortIdx",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2016b\\toolbox\\eml\\eml\\+coder\\+internal\\sortIdx.m"/* pName */
};

static emlrtRTEInfo bc_emlrtRTEI = { 247,/* lineNo */
  20,                                  /* colNo */
  "sortIdx",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2016b\\toolbox\\eml\\eml\\+coder\\+internal\\sortIdx.m"/* pName */
};

/* Function Definitions */
void sort(const emlrtStack *sp, emxArray_real_T *x, emxArray_int32_T *idx)
{
  int32_T iv21[2];
  int32_T offset;
  int32_T i;
  emxArray_real_T *b_x;
  emxArray_int32_T *b_idx;
  real_T x4[4];
  int32_T idx4[4];
  emxArray_int32_T *iwork;
  int32_T preSortLevel;
  emxArray_real_T *xwork;
  int32_T nNaNs;
  int32_T ib;
  boolean_T overflow;
  int32_T k;
  int32_T wOffset;
  int8_T perm[4];
  int32_T i4;
  int32_T nNonNaN;
  int32_T nBlocks;
  int32_T b_iwork[256];
  real_T b_xwork[256];
  int32_T b;
  int32_T bLen;
  int32_T bLen2;
  int32_T nPairs;
  int32_T exitg1;
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
  st.site = &ch_emlrtRSI;
  for (offset = 0; offset < 2; offset++) {
    iv21[offset] = x->size[offset];
  }

  offset = idx->size[0] * idx->size[1];
  idx->size[0] = iv21[0];
  idx->size[1] = 1;
  emxEnsureCapacity(&st, (emxArray__common *)idx, offset, (int32_T)sizeof
                    (int32_T), &ab_emlrtRTEI);
  i = iv21[0];
  for (offset = 0; offset < i; offset++) {
    idx->data[offset] = 0;
  }

  emxInit_real_T(&st, &b_x, 1, &ab_emlrtRTEI, true);
  b_st.site = &dh_emlrtRSI;
  b_st.site = &eh_emlrtRSI;
  c_st.site = &ad_emlrtRSI;
  i = x->size[0];
  offset = b_x->size[0];
  b_x->size[0] = i;
  emxEnsureCapacity(&c_st, (emxArray__common *)b_x, offset, (int32_T)sizeof
                    (real_T), &ab_emlrtRTEI);
  for (offset = 0; offset < i; offset++) {
    b_x->data[offset] = x->data[offset];
  }

  emxInit_int32_T(&c_st, &b_idx, 1, &ab_emlrtRTEI, true);
  i = idx->size[0];
  offset = b_idx->size[0];
  b_idx->size[0] = i;
  emxEnsureCapacity(&c_st, (emxArray__common *)b_idx, offset, (int32_T)sizeof
                    (int32_T), &ab_emlrtRTEI);
  for (offset = 0; offset < i; offset++) {
    b_idx->data[offset] = idx->data[offset];
  }

  offset = x->size[0];
  for (i = 0; i < 4; i++) {
    x4[i] = 0.0;
    idx4[i] = 0;
  }

  emxInit_int32_T(&c_st, &iwork, 1, &ac_emlrtRTEI, true);
  preSortLevel = idx->size[0];
  i = iwork->size[0];
  iwork->size[0] = preSortLevel;
  emxEnsureCapacity(&c_st, (emxArray__common *)iwork, i, (int32_T)sizeof(int32_T),
                    &xb_emlrtRTEI);
  i = iwork->size[0];
  preSortLevel = iwork->size[0];
  iwork->size[0] = i;
  emxEnsureCapacity(&c_st, (emxArray__common *)iwork, preSortLevel, (int32_T)
                    sizeof(int32_T), &ab_emlrtRTEI);
  for (preSortLevel = 0; preSortLevel < i; preSortLevel++) {
    iwork->data[preSortLevel] = 0;
  }

  emxInit_real_T(&c_st, &xwork, 1, &bc_emlrtRTEI, true);
  preSortLevel = x->size[0];
  i = xwork->size[0];
  xwork->size[0] = preSortLevel;
  emxEnsureCapacity(&c_st, (emxArray__common *)xwork, i, (int32_T)sizeof(real_T),
                    &yb_emlrtRTEI);
  i = xwork->size[0];
  preSortLevel = xwork->size[0];
  xwork->size[0] = i;
  emxEnsureCapacity(&c_st, (emxArray__common *)xwork, preSortLevel, (int32_T)
                    sizeof(real_T), &ab_emlrtRTEI);
  for (preSortLevel = 0; preSortLevel < i; preSortLevel++) {
    xwork->data[preSortLevel] = 0.0;
  }

  nNaNs = 0;
  ib = 0;
  d_st.site = &fd_emlrtRSI;
  preSortLevel = x->size[0];
  if (1 > preSortLevel) {
    overflow = false;
  } else {
    preSortLevel = x->size[0];
    overflow = (preSortLevel > 2147483646);
  }

  if (overflow) {
    e_st.site = &w_emlrtRSI;
    check_forloop_overflow_error(&e_st);
  }

  for (k = 0; k + 1 <= offset; k++) {
    if (muDoubleScalarIsNaN(b_x->data[k])) {
      b_idx->data[(offset - nNaNs) - 1] = k + 1;
      xwork->data[(offset - nNaNs) - 1] = b_x->data[k];
      nNaNs++;
    } else {
      ib++;
      idx4[ib - 1] = k + 1;
      x4[ib - 1] = b_x->data[k];
      if (ib == 4) {
        i = k - nNaNs;
        if (x4[0] >= x4[1]) {
          preSortLevel = 1;
          ib = 2;
        } else {
          preSortLevel = 2;
          ib = 1;
        }

        if (x4[2] >= x4[3]) {
          wOffset = 3;
          i4 = 4;
        } else {
          wOffset = 4;
          i4 = 3;
        }

        if (x4[preSortLevel - 1] >= x4[wOffset - 1]) {
          if (x4[ib - 1] >= x4[wOffset - 1]) {
            perm[0] = (int8_T)preSortLevel;
            perm[1] = (int8_T)ib;
            perm[2] = (int8_T)wOffset;
            perm[3] = (int8_T)i4;
          } else if (x4[ib - 1] >= x4[i4 - 1]) {
            perm[0] = (int8_T)preSortLevel;
            perm[1] = (int8_T)wOffset;
            perm[2] = (int8_T)ib;
            perm[3] = (int8_T)i4;
          } else {
            perm[0] = (int8_T)preSortLevel;
            perm[1] = (int8_T)wOffset;
            perm[2] = (int8_T)i4;
            perm[3] = (int8_T)ib;
          }
        } else if (x4[preSortLevel - 1] >= x4[i4 - 1]) {
          if (x4[ib - 1] >= x4[i4 - 1]) {
            perm[0] = (int8_T)wOffset;
            perm[1] = (int8_T)preSortLevel;
            perm[2] = (int8_T)ib;
            perm[3] = (int8_T)i4;
          } else {
            perm[0] = (int8_T)wOffset;
            perm[1] = (int8_T)preSortLevel;
            perm[2] = (int8_T)i4;
            perm[3] = (int8_T)ib;
          }
        } else {
          perm[0] = (int8_T)wOffset;
          perm[1] = (int8_T)i4;
          perm[2] = (int8_T)preSortLevel;
          perm[3] = (int8_T)ib;
        }

        b_idx->data[i - 3] = idx4[perm[0] - 1];
        b_idx->data[i - 2] = idx4[perm[1] - 1];
        b_idx->data[i - 1] = idx4[perm[2] - 1];
        b_idx->data[i] = idx4[perm[3] - 1];
        b_x->data[i - 3] = x4[perm[0] - 1];
        b_x->data[i - 2] = x4[perm[1] - 1];
        b_x->data[i - 1] = x4[perm[2] - 1];
        b_x->data[i] = x4[perm[3] - 1];
        ib = 0;
      }
    }
  }

  preSortLevel = x->size[0] - 1;
  wOffset = preSortLevel - nNaNs;
  if (ib > 0) {
    for (i = 0; i < 4; i++) {
      perm[i] = 0;
    }

    if (ib == 1) {
      perm[0] = 1;
    } else if (ib == 2) {
      if (x4[0] >= x4[1]) {
        perm[0] = 1;
        perm[1] = 2;
      } else {
        perm[0] = 2;
        perm[1] = 1;
      }
    } else if (x4[0] >= x4[1]) {
      if (x4[1] >= x4[2]) {
        perm[0] = 1;
        perm[1] = 2;
        perm[2] = 3;
      } else if (x4[0] >= x4[2]) {
        perm[0] = 1;
        perm[1] = 3;
        perm[2] = 2;
      } else {
        perm[0] = 3;
        perm[1] = 1;
        perm[2] = 2;
      }
    } else if (x4[0] >= x4[2]) {
      perm[0] = 2;
      perm[1] = 1;
      perm[2] = 3;
    } else if (x4[1] >= x4[2]) {
      perm[0] = 2;
      perm[1] = 3;
      perm[2] = 1;
    } else {
      perm[0] = 3;
      perm[1] = 2;
      perm[2] = 1;
    }

    d_st.site = &gd_emlrtRSI;
    if (ib > 2147483646) {
      e_st.site = &w_emlrtRSI;
      check_forloop_overflow_error(&e_st);
    }

    for (k = 1; k <= ib; k++) {
      b_idx->data[(wOffset - ib) + k] = idx4[perm[k - 1] - 1];
      b_x->data[(wOffset - ib) + k] = x4[perm[k - 1] - 1];
    }
  }

  i = (nNaNs >> 1) + 1;
  d_st.site = &hd_emlrtRSI;
  for (k = 1; k < i; k++) {
    preSortLevel = b_idx->data[wOffset + k];
    b_idx->data[wOffset + k] = b_idx->data[offset - k];
    b_idx->data[offset - k] = preSortLevel;
    b_x->data[wOffset + k] = xwork->data[offset - k];
    b_x->data[offset - k] = xwork->data[wOffset + k];
  }

  if ((nNaNs & 1) != 0) {
    b_x->data[wOffset + i] = xwork->data[wOffset + i];
  }

  offset = x->size[0];
  nNonNaN = offset - nNaNs;
  preSortLevel = 2;
  if (nNonNaN > 1) {
    offset = x->size[0];
    if (offset >= 256) {
      nBlocks = nNonNaN >> 8;
      if (nBlocks > 0) {
        c_st.site = &bd_emlrtRSI;
        for (i4 = 1; i4 <= nBlocks; i4++) {
          c_st.site = &cd_emlrtRSI;
          offset = (i4 - 1) << 8;
          for (b = 0; b < 6; b++) {
            bLen = 1 << (b + 2);
            bLen2 = bLen << 1;
            nPairs = 256 >> (b + 3);
            d_st.site = &id_emlrtRSI;
            for (k = 1; k <= nPairs; k++) {
              preSortLevel = offset + (k - 1) * bLen2;
              d_st.site = &jd_emlrtRSI;
              for (i = 0; i + 1 <= bLen2; i++) {
                b_iwork[i] = b_idx->data[preSortLevel + i];
                b_xwork[i] = b_x->data[preSortLevel + i];
              }

              wOffset = 0;
              ib = bLen;
              i = preSortLevel - 1;
              do {
                exitg1 = 0;
                i++;
                if (b_xwork[wOffset] >= b_xwork[ib]) {
                  b_idx->data[i] = b_iwork[wOffset];
                  b_x->data[i] = b_xwork[wOffset];
                  if (wOffset + 1 < bLen) {
                    wOffset++;
                  } else {
                    exitg1 = 1;
                  }
                } else {
                  b_idx->data[i] = b_iwork[ib];
                  b_x->data[i] = b_xwork[ib];
                  if (ib + 1 < bLen2) {
                    ib++;
                  } else {
                    i = (i - wOffset) + 1;
                    d_st.site = &kd_emlrtRSI;
                    while (wOffset + 1 <= bLen) {
                      b_idx->data[i + wOffset] = b_iwork[wOffset];
                      b_x->data[i + wOffset] = b_xwork[wOffset];
                      wOffset++;
                    }

                    exitg1 = 1;
                  }
                }
              } while (exitg1 == 0);
            }
          }
        }

        i = nBlocks << 8;
        preSortLevel = nNonNaN - i;
        if (preSortLevel > 0) {
          c_st.site = &dd_emlrtRSI;
          merge_block(&c_st, b_idx, b_x, i, preSortLevel, 2, iwork, xwork);
        }

        preSortLevel = 8;
      }
    }

    c_st.site = &ed_emlrtRSI;
    merge_block(&c_st, b_idx, b_x, 0, nNonNaN, preSortLevel, iwork, xwork);
  }

  if ((nNaNs > 0) && (nNonNaN > 0)) {
    c_st.site = &fh_emlrtRSI;
    d_st.site = &gh_emlrtRSI;
    if (nNaNs > 2147483646) {
      e_st.site = &w_emlrtRSI;
      check_forloop_overflow_error(&e_st);
    }

    for (k = 0; k + 1 <= nNaNs; k++) {
      xwork->data[k] = b_x->data[nNonNaN + k];
      iwork->data[k] = b_idx->data[nNonNaN + k];
    }

    for (k = nNonNaN - 1; k + 1 > 0; k--) {
      b_x->data[nNaNs + k] = b_x->data[k];
      b_idx->data[nNaNs + k] = b_idx->data[k];
    }

    d_st.site = &hh_emlrtRSI;
    for (k = 0; k + 1 <= nNaNs; k++) {
      b_x->data[k] = xwork->data[k];
      b_idx->data[k] = iwork->data[k];
    }
  }

  emxFree_real_T(&xwork);
  emxFree_int32_T(&iwork);
  i = b_idx->size[0];
  for (offset = 0; offset < i; offset++) {
    idx->data[offset] = b_idx->data[offset];
  }

  emxFree_int32_T(&b_idx);
  i = b_x->size[0];
  for (offset = 0; offset < i; offset++) {
    x->data[offset] = b_x->data[offset];
  }

  emxFree_real_T(&b_x);
  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

/* End of code generation (sort1.c) */
