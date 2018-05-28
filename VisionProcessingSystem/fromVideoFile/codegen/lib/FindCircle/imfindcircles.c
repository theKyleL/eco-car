/*
 * Sponsored License - for use in support of a program or activity
 * sponsored by MathWorks.  Not for government, commercial or other
 * non-sponsored organizational use.
 * File: imfindcircles.c
 *
 * MATLAB Coder version            : 3.2
 * C/C++ source code generated on  : 05-Nov-2016 16:55:10
 */

/* Include Files */
#include "rt_nonfinite.h"
#include "FindCircle.h"
#include "imfindcircles.h"
#include "FindCircle_emxutil.h"
#include "round1.h"
#include "chcenters.h"
#include "chaccum.h"

/* Function Declarations */
static double rt_atan2d_snf(double u0, double u1);

/* Function Definitions */

/*
 * Arguments    : double u0
 *                double u1
 * Return Type  : double
 */
static double rt_atan2d_snf(double u0, double u1)
{
  double y;
  int b_u0;
  int b_u1;
  if (rtIsNaN(u0) || rtIsNaN(u1)) {
    y = rtNaN;
  } else if (rtIsInf(u0) && rtIsInf(u1)) {
    if (u0 > 0.0) {
      b_u0 = 1;
    } else {
      b_u0 = -1;
    }

    if (u1 > 0.0) {
      b_u1 = 1;
    } else {
      b_u1 = -1;
    }

    y = atan2(b_u0, b_u1);
  } else if (u1 == 0.0) {
    if (u0 > 0.0) {
      y = RT_PI / 2.0;
    } else if (u0 < 0.0) {
      y = -(RT_PI / 2.0);
    } else {
      y = 0.0;
    }
  } else {
    y = atan2(u0, u1);
  }

  return y;
}

/*
 * Arguments    : const unsigned char varargin_1[921600]
 *                emxArray_real_T *centers
 *                emxArray_real_T *r_estimated
 * Return Type  : void
 */
void imfindcircles(const unsigned char varargin_1[921600], emxArray_real_T
                   *centers, emxArray_real_T *r_estimated)
{
  int i0;
  static creal_T accumMatrix[307200];
  static float gradientImg[307200];
  boolean_T y;
  int k;
  boolean_T exitg2;
  emxArray_real_T *b_centers;
  boolean_T b0;
  emxArray_real_T *metric;
  emxArray_boolean_T *x;
  emxArray_int32_T *ii;
  int nx;
  int idx;
  boolean_T exitg1;
  boolean_T guard1 = false;
  emxArray_real_T *idx2Keep;
  emxArray_real_T *cenPhase;
  emxArray_real_T *varargin_2;
  emxArray_creal_T *b_x;
  i0 = centers->size[0] * centers->size[1];
  centers->size[0] = 0;
  centers->size[1] = 0;
  emxEnsureCapacity((emxArray__common *)centers, i0, (int)sizeof(double));
  i0 = r_estimated->size[0] * r_estimated->size[1];
  r_estimated->size[0] = 0;
  r_estimated->size[1] = 0;
  emxEnsureCapacity((emxArray__common *)r_estimated, i0, (int)sizeof(double));
  chaccum(varargin_1, accumMatrix, gradientImg);
  y = false;
  k = 0;
  exitg2 = false;
  while ((!exitg2) && (k < 307200)) {
    if (((accumMatrix[k].re == 0.0) && (accumMatrix[k].im == 0.0)) || (rtIsNaN
         (accumMatrix[k].re) || rtIsNaN(accumMatrix[k].im))) {
      b0 = true;
    } else {
      b0 = false;
    }

    if (!b0) {
      y = true;
      exitg2 = true;
    } else {
      k++;
    }
  }

  if (y) {
    emxInit_real_T1(&b_centers, 2);
    emxInit_real_T1(&metric, 2);
    chcenters(accumMatrix, b_centers, metric);
    i0 = centers->size[0] * centers->size[1];
    centers->size[0] = b_centers->size[0];
    centers->size[1] = b_centers->size[1];
    emxEnsureCapacity((emxArray__common *)centers, i0, (int)sizeof(double));
    k = b_centers->size[0] * b_centers->size[1];
    for (i0 = 0; i0 < k; i0++) {
      centers->data[i0] = b_centers->data[i0];
    }

    if (!((b_centers->size[0] == 0) || (b_centers->size[1] == 0))) {
      emxInit_boolean_T(&x, 2);
      i0 = x->size[0] * x->size[1];
      x->size[0] = metric->size[0];
      x->size[1] = metric->size[1];
      emxEnsureCapacity((emxArray__common *)x, i0, (int)sizeof(boolean_T));
      k = metric->size[0] * metric->size[1];
      for (i0 = 0; i0 < k; i0++) {
        x->data[i0] = (metric->data[i0] >= 0.15000000000000002);
      }

      emxInit_int32_T(&ii, 1);
      nx = x->size[0] * x->size[1];
      idx = 0;
      i0 = ii->size[0];
      ii->size[0] = nx;
      emxEnsureCapacity((emxArray__common *)ii, i0, (int)sizeof(int));
      k = 1;
      exitg1 = false;
      while ((!exitg1) && (k <= nx)) {
        guard1 = false;
        if (x->data[k - 1]) {
          idx++;
          ii->data[idx - 1] = k;
          if (idx >= nx) {
            exitg1 = true;
          } else {
            guard1 = true;
          }
        } else {
          guard1 = true;
        }

        if (guard1) {
          k++;
        }
      }

      emxFree_boolean_T(&x);
      if (nx == 1) {
        if (idx == 0) {
          i0 = ii->size[0];
          ii->size[0] = 0;
          emxEnsureCapacity((emxArray__common *)ii, i0, (int)sizeof(int));
        }
      } else {
        i0 = ii->size[0];
        if (1 > idx) {
          ii->size[0] = 0;
        } else {
          ii->size[0] = idx;
        }

        emxEnsureCapacity((emxArray__common *)ii, i0, (int)sizeof(int));
      }

      emxInit_real_T(&idx2Keep, 1);
      i0 = idx2Keep->size[0];
      idx2Keep->size[0] = ii->size[0];
      emxEnsureCapacity((emxArray__common *)idx2Keep, i0, (int)sizeof(double));
      k = ii->size[0];
      for (i0 = 0; i0 < k; i0++) {
        idx2Keep->data[i0] = ii->data[i0];
      }

      k = b_centers->size[1];
      i0 = centers->size[0] * centers->size[1];
      centers->size[0] = idx2Keep->size[0];
      centers->size[1] = k;
      emxEnsureCapacity((emxArray__common *)centers, i0, (int)sizeof(double));
      for (i0 = 0; i0 < k; i0++) {
        nx = idx2Keep->size[0];
        for (idx = 0; idx < nx; idx++) {
          centers->data[idx + centers->size[0] * i0] = b_centers->data[((int)
            idx2Keep->data[idx] + b_centers->size[0] * i0) - 1];
        }
      }

      if (idx2Keep->size[0] == 0) {
        i0 = centers->size[0] * centers->size[1];
        centers->size[0] = 0;
        centers->size[1] = 0;
        emxEnsureCapacity((emxArray__common *)centers, i0, (int)sizeof(double));
      } else {
        emxInit_real_T(&cenPhase, 1);
        k = idx2Keep->size[0];
        i0 = cenPhase->size[0];
        cenPhase->size[0] = k;
        emxEnsureCapacity((emxArray__common *)cenPhase, i0, (int)sizeof(double));
        for (i0 = 0; i0 < k; i0++) {
          cenPhase->data[i0] = centers->data[i0 + centers->size[0]];
        }

        emxInit_real_T(&varargin_2, 1);
        b_round(cenPhase);
        k = idx2Keep->size[0];
        i0 = varargin_2->size[0];
        varargin_2->size[0] = k;
        emxEnsureCapacity((emxArray__common *)varargin_2, i0, (int)sizeof(double));
        for (i0 = 0; i0 < k; i0++) {
          varargin_2->data[i0] = centers->data[i0];
        }

        b_round(varargin_2);
        i0 = ii->size[0];
        ii->size[0] = cenPhase->size[0];
        emxEnsureCapacity((emxArray__common *)ii, i0, (int)sizeof(int));
        k = cenPhase->size[0];
        for (i0 = 0; i0 < k; i0++) {
          ii->data[i0] = (int)cenPhase->data[i0] + 480 * ((int)varargin_2->
            data[i0] - 1);
        }

        emxFree_real_T(&varargin_2);
        emxInit_creal_T(&b_x, 1);
        i0 = b_x->size[0];
        b_x->size[0] = ii->size[0];
        emxEnsureCapacity((emxArray__common *)b_x, i0, (int)sizeof(creal_T));
        k = ii->size[0];
        for (i0 = 0; i0 < k; i0++) {
          b_x->data[i0] = accumMatrix[ii->data[i0] - 1];
        }

        k = ii->size[0];
        i0 = cenPhase->size[0];
        cenPhase->size[0] = k;
        emxEnsureCapacity((emxArray__common *)cenPhase, i0, (int)sizeof(double));
        for (k = 0; k + 1 <= ii->size[0]; k++) {
          cenPhase->data[k] = rt_atan2d_snf(b_x->data[k].im, b_x->data[k].re);
        }

        emxFree_creal_T(&b_x);
        i0 = cenPhase->size[0];
        emxEnsureCapacity((emxArray__common *)cenPhase, i0, (int)sizeof(double));
        k = cenPhase->size[0];
        for (i0 = 0; i0 < k; i0++) {
          cenPhase->data[i0] = (cenPhase->data[i0] + 3.1415926535897931) /
            6.2831853071795862 * 0.6931471805599454 + 2.70805020110221;
        }

        i0 = idx2Keep->size[0];
        idx2Keep->size[0] = cenPhase->size[0];
        emxEnsureCapacity((emxArray__common *)idx2Keep, i0, (int)sizeof(double));
        k = cenPhase->size[0];
        for (i0 = 0; i0 < k; i0++) {
          idx2Keep->data[i0] = cenPhase->data[i0];
        }

        for (k = 0; k + 1 <= cenPhase->size[0]; k++) {
          idx2Keep->data[k] = exp(idx2Keep->data[k]);
        }

        emxFree_real_T(&cenPhase);
        i0 = r_estimated->size[0] * r_estimated->size[1];
        r_estimated->size[0] = idx2Keep->size[0];
        r_estimated->size[1] = 1;
        emxEnsureCapacity((emxArray__common *)r_estimated, i0, (int)sizeof
                          (double));
        k = idx2Keep->size[0];
        for (i0 = 0; i0 < k; i0++) {
          r_estimated->data[i0] = idx2Keep->data[i0];
        }
      }

      emxFree_int32_T(&ii);
      emxFree_real_T(&idx2Keep);
    }

    emxFree_real_T(&metric);
    emxFree_real_T(&b_centers);
  }
}

/*
 * File trailer for imfindcircles.c
 *
 * [EOF]
 */
