/*
 * Sponsored License - for use in support of a program or activity
 * sponsored by MathWorks.  Not for government, commercial or other
 * non-sponsored organizational use.
 * File: multithresh.c
 *
 * MATLAB Coder version            : 3.2
 * C/C++ source code generated on  : 05-Nov-2016 16:55:10
 */

/* Include Files */
#include "rt_nonfinite.h"
#include "FindCircle.h"
#include "multithresh.h"
#include "isfinite.h"
#include "FindCircle_emxutil.h"
#include "nullAssignment.h"
#include "unique.h"
#include "sortIdx.h"
#include "sum.h"
#include "imhist.h"
#include "im2uint8.h"

/* Function Declarations */
static void checkForDegenerateInput(const float A[307200], boolean_T
  *isDegenerate, emxArray_real32_T *uniqueVals);
static void getDegenerateThresholds(const emxArray_real32_T *uniqueVals,
  emxArray_real32_T *thresh);
static void map2OriginalScale(const emxArray_real_T *thresh, float minA, float
  maxA, emxArray_real32_T *sclThresh);

/* Function Definitions */

/*
 * Arguments    : const float A[307200]
 *                boolean_T *isDegenerate
 *                emxArray_real32_T *uniqueVals
 * Return Type  : void
 */
static void checkForDegenerateInput(const float A[307200], boolean_T
  *isDegenerate, emxArray_real32_T *uniqueVals)
{
  emxArray_real32_T *b;
  static int idx[307200];
  int nFinite;
  int k;
  int nInf;
  int nNaN;
  int nb;
  int khi;
  float x;
  int exitg1;
  float absxk;
  int i3;
  int exponent;
  boolean_T p;
  emxArray_boolean_T *r2;
  emxArray_boolean_T *r3;
  emxArray_boolean_T *r4;
  emxInit_real32_T1(&b, 1);
  sortIdx(A, idx);
  nFinite = b->size[0];
  b->size[0] = 307200;
  emxEnsureCapacity((emxArray__common *)b, nFinite, (int)sizeof(float));
  for (k = 0; k < 307200; k++) {
    b->data[k] = A[idx[k] - 1];
  }

  count_nonfinites(b, &k, &nFinite, &nInf, &nNaN);
  nb = -1;
  if (k > 0) {
    nb = 0;
  }

  khi = k + nFinite;
  while (k + 1 <= khi) {
    x = b->data[k];
    do {
      exitg1 = 0;
      k++;
      if (k + 1 > khi) {
        exitg1 = 1;
      } else {
        absxk = (float)fabs(x / 2.0F);
        if ((!rtIsInfF(absxk)) && (!rtIsNaNF(absxk))) {
          if (absxk <= 1.17549435E-38F) {
            absxk = 1.4013E-45F;
          } else {
            frexp(absxk, &exponent);
            absxk = (float)ldexp(1.0, exponent - 24);
          }
        } else {
          absxk = ((real32_T)rtNaN);
        }

        if (((float)fabs(x - b->data[k]) < absxk) || (rtIsInfF(b->data[k]) &&
             rtIsInfF(x) && ((b->data[k] > 0.0F) == (x > 0.0F)))) {
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
    b->data[nb] = x;
  }

  if (nInf > 0) {
    nb++;
    b->data[nb] = b->data[khi];
  }

  k = khi + nInf;
  for (khi = 1; khi <= nNaN; khi++) {
    nb++;
    b->data[nb] = b->data[(k + khi) - 1];
  }

  nFinite = b->size[0];
  if (1 > nb + 1) {
    i3 = -1;
  } else {
    i3 = nb;
  }

  b->size[0] = i3 + 1;
  emxEnsureCapacity((emxArray__common *)b, nFinite, (int)sizeof(float));
  nFinite = uniqueVals->size[0] * uniqueVals->size[1];
  uniqueVals->size[0] = 1;
  uniqueVals->size[1] = b->size[0];
  emxEnsureCapacity((emxArray__common *)uniqueVals, nFinite, (int)sizeof(float));
  khi = b->size[0];
  for (nFinite = 0; nFinite < khi; nFinite++) {
    uniqueVals->data[uniqueVals->size[0] * nFinite] = b->data[nFinite];
  }

  emxFree_real32_T(&b);
  emxInit_boolean_T(&r2, 2);
  nFinite = r2->size[0] * r2->size[1];
  r2->size[0] = 1;
  r2->size[1] = uniqueVals->size[1];
  emxEnsureCapacity((emxArray__common *)r2, nFinite, (int)sizeof(boolean_T));
  khi = uniqueVals->size[0] * uniqueVals->size[1];
  for (nFinite = 0; nFinite < khi; nFinite++) {
    r2->data[nFinite] = rtIsInfF(uniqueVals->data[nFinite]);
  }

  emxInit_boolean_T(&r3, 2);
  nFinite = r3->size[0] * r3->size[1];
  r3->size[0] = 1;
  r3->size[1] = uniqueVals->size[1];
  emxEnsureCapacity((emxArray__common *)r3, nFinite, (int)sizeof(boolean_T));
  khi = uniqueVals->size[0] * uniqueVals->size[1];
  for (nFinite = 0; nFinite < khi; nFinite++) {
    r3->data[nFinite] = rtIsNaNF(uniqueVals->data[nFinite]);
  }

  emxInit_boolean_T(&r4, 2);
  nFinite = r4->size[0] * r4->size[1];
  r4->size[0] = 1;
  r4->size[1] = r2->size[1];
  emxEnsureCapacity((emxArray__common *)r4, nFinite, (int)sizeof(boolean_T));
  khi = r2->size[0] * r2->size[1];
  for (nFinite = 0; nFinite < khi; nFinite++) {
    r4->data[nFinite] = (r2->data[nFinite] || r3->data[nFinite]);
  }

  emxFree_boolean_T(&r3);
  emxFree_boolean_T(&r2);
  nullAssignment(uniqueVals, r4);
  *isDegenerate = (uniqueVals->size[1] <= 1);
  emxFree_boolean_T(&r4);
}

/*
 * Arguments    : const emxArray_real32_T *uniqueVals
 *                emxArray_real32_T *thresh
 * Return Type  : void
 */
static void getDegenerateThresholds(const emxArray_real32_T *uniqueVals,
  emxArray_real32_T *thresh)
{
  int i4;
  int loop_ub;
  if (uniqueVals->size[1] == 0) {
    i4 = thresh->size[0] * thresh->size[1];
    thresh->size[0] = 1;
    thresh->size[1] = 1;
    emxEnsureCapacity((emxArray__common *)thresh, i4, (int)sizeof(float));
    thresh->data[0] = 1.0F;
  } else {
    i4 = thresh->size[0] * thresh->size[1];
    thresh->size[0] = 1;
    thresh->size[1] = uniqueVals->size[1];
    emxEnsureCapacity((emxArray__common *)thresh, i4, (int)sizeof(float));
    loop_ub = uniqueVals->size[0] * uniqueVals->size[1];
    for (i4 = 0; i4 < loop_ub; i4++) {
      thresh->data[i4] = uniqueVals->data[i4];
    }
  }
}

/*
 * Arguments    : const emxArray_real_T *thresh
 *                float minA
 *                float maxA
 *                emxArray_real32_T *sclThresh
 * Return Type  : void
 */
static void map2OriginalScale(const emxArray_real_T *thresh, float minA, float
  maxA, emxArray_real32_T *sclThresh)
{
  double b;
  int i6;
  int loop_ub;
  b = (double)maxA - minA;
  i6 = sclThresh->size[0] * sclThresh->size[1];
  sclThresh->size[0] = 1;
  sclThresh->size[1] = thresh->size[1];
  emxEnsureCapacity((emxArray__common *)sclThresh, i6, (int)sizeof(float));
  loop_ub = thresh->size[0] * thresh->size[1];
  for (i6 = 0; i6 < loop_ub; i6++) {
    sclThresh->data[i6] = (float)(minA + thresh->data[i6] / 255.0 * b);
  }
}

/*
 * Arguments    : const float varargin_1[307200]
 * Return Type  : float
 */
float multithresh(const float varargin_1[307200])
{
  float thresh;
  boolean_T isvalid_maxval;
  double counts[256];
  int idx;
  float mtmp;
  int ix;
  boolean_T exitg3;
  float B;
  static float A[307200];
  double x[256];
  static boolean_T nans[307200];
  boolean_T exitg2;
  float b_A;
  double b_x[256];
  emxArray_int32_T *r1;
  boolean_T b_nans;
  double y;
  emxArray_real32_T *c_A;
  boolean_T exitg1;
  emxArray_real32_T *threshout;
  emxArray_real_T *threshRaw;
  emxArray_real32_T *uniqueVals;
  emxArray_uint8_T *d_A;
  double idxSum;
  double idxNum;
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
        b_A = (varargin_1[ix] - thresh) / B;
        b_nans = rtIsNaNF(b_A);
        if (!b_nans) {
          idx++;
        }

        A[ix] = b_A;
        nans[ix] = b_nans;
      }

      if (!(idx == 0)) {
        emxInit_int32_T(&r1, 1);
        idx = 0;
        for (ix = 0; ix < 307200; ix++) {
          if (!nans[ix]) {
            idx++;
          }
        }

        ix = r1->size[0];
        r1->size[0] = idx;
        emxEnsureCapacity((emxArray__common *)r1, ix, (int)sizeof(int));
        idx = 0;
        for (ix = 0; ix < 307200; ix++) {
          if (!nans[ix]) {
            r1->data[idx] = ix + 1;
            idx++;
          }
        }

        emxInit_real32_T1(&c_A, 1);
        ix = c_A->size[0];
        c_A->size[0] = r1->size[0];
        emxEnsureCapacity((emxArray__common *)c_A, ix, (int)sizeof(float));
        idx = r1->size[0];
        for (ix = 0; ix < idx; ix++) {
          c_A->data[ix] = A[r1->data[ix] - 1];
        }

        emxFree_int32_T(&r1);
        emxInit_uint8_T(&d_A, 1);
        im2uint8(c_A, d_A);
        imhist(d_A, counts);
        y = sum(counts);
        emxFree_real32_T(&c_A);
        emxFree_uint8_T(&d_A);
        for (ix = 0; ix < 256; ix++) {
          counts[ix] /= y;
        }

        isvalid_maxval = false;
      }
    }
  } else {
    idx = 1;
    thresh = varargin_1[0];
    if (rtIsNaNF(varargin_1[0])) {
      ix = 2;
      exitg3 = false;
      while ((!exitg3) && (ix < 307201)) {
        idx = ix;
        if (!rtIsNaNF(varargin_1[ix - 1])) {
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
    if (rtIsNaNF(varargin_1[0])) {
      ix = 2;
      exitg2 = false;
      while ((!exitg2) && (ix < 307201)) {
        idx = ix;
        if (!rtIsNaNF(varargin_1[ix - 1])) {
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
    if (rtIsNaNF(thresh)) {
      thresh = 1.0F;
    }
  } else {
    memcpy(&x[0], &counts[0], sizeof(double) << 8);
    for (idx = 0; idx < 255; idx++) {
      x[idx + 1] += x[idx];
    }

    for (ix = 0; ix < 256; ix++) {
      b_x[ix] = counts[ix] * (1.0 + (double)ix);
    }

    for (idx = 0; idx < 255; idx++) {
      b_x[idx + 1] += b_x[idx];
    }

    for (idx = 0; idx < 256; idx++) {
      y = b_x[255] * x[idx] - b_x[idx];
      counts[idx] = y * y / (x[idx] * (1.0 - x[idx]));
    }

    idx = 1;
    y = counts[0];
    if (rtIsNaN(counts[0])) {
      ix = 2;
      exitg1 = false;
      while ((!exitg1) && (ix < 257)) {
        idx = ix;
        if (!rtIsNaN(counts[ix - 1])) {
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

    isvalid_maxval = ((!rtIsInf(y)) && (!rtIsNaN(y)));
    emxInit_real32_T(&threshout, 2);
    emxInit_real_T1(&threshRaw, 2);
    emxInit_real32_T(&uniqueVals, 2);
    if (isvalid_maxval) {
      idxSum = 0.0;
      idxNum = 0.0;
      for (idx = 0; idx < 256; idx++) {
        if (counts[idx] == y) {
          idxSum += 1.0 + (double)idx;
          idxNum++;
        }
      }

      ix = threshRaw->size[0] * threshRaw->size[1];
      threshRaw->size[0] = 1;
      threshRaw->size[1] = 1;
      emxEnsureCapacity((emxArray__common *)threshRaw, ix, (int)sizeof(double));
      threshRaw->data[0] = idxSum / idxNum - 1.0;
      map2OriginalScale(threshRaw, thresh, mtmp, threshout);
    } else {
      checkForDegenerateInput(varargin_1, &b_nans, uniqueVals);
      getDegenerateThresholds(uniqueVals, threshout);
      ix = threshRaw->size[0] * threshRaw->size[1];
      threshRaw->size[0] = 1;
      threshRaw->size[1] = threshout->size[1];
      emxEnsureCapacity((emxArray__common *)threshRaw, ix, (int)sizeof(double));
      idx = threshout->size[0] * threshout->size[1];
      for (ix = 0; ix < idx; ix++) {
        threshRaw->data[ix] = threshout->data[ix];
      }

      checkForDegenerateInput(varargin_1, &b_nans, uniqueVals);
      if (b_nans) {
        getDegenerateThresholds(uniqueVals, threshout);
      } else {
        map2OriginalScale(threshRaw, thresh, mtmp, threshout);
      }
    }

    emxFree_real32_T(&uniqueVals);
    emxFree_real_T(&threshRaw);
    thresh = threshout->data[0];
    emxFree_real32_T(&threshout);
  }

  return thresh;
}

/*
 * File trailer for multithresh.c
 *
 * [EOF]
 */
