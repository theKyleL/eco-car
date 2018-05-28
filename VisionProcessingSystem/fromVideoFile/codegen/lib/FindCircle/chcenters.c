/*
 * Sponsored License - for use in support of a program or activity
 * sponsored by MathWorks.  Not for government, commercial or other
 * non-sponsored organizational use.
 * File: chcenters.c
 *
 * MATLAB Coder version            : 3.2
 * C/C++ source code generated on  : 05-Nov-2016 16:55:10
 */

/* Include Files */
#include "rt_nonfinite.h"
#include "FindCircle.h"
#include "chcenters.h"
#include "FindCircle_emxutil.h"
#include "sort1.h"
#include "round1.h"
#include "regionprops.h"
#include "medfilt2.h"
#include "libmwippreconstruct.h"
#include "libmwimregionalmax.h"

/* Function Declarations */
static double rt_hypotd_snf(double u0, double u1);

/* Function Definitions */

/*
 * Arguments    : double u0
 *                double u1
 * Return Type  : double
 */
static double rt_hypotd_snf(double u0, double u1)
{
  double y;
  double a;
  double b;
  a = fabs(u0);
  b = fabs(u1);
  if (a < b) {
    a /= b;
    y = b * sqrt(a * a + 1.0);
  } else if (a > b) {
    b /= a;
    y = a * sqrt(b * b + 1.0);
  } else if (rtIsNaN(b)) {
    y = b;
  } else {
    y = a * 1.4142135623730951;
  }

  return y;
}

/*
 * Arguments    : const creal_T varargin_1[307200]
 *                emxArray_real_T *centers
 *                emxArray_real_T *metric
 * Return Type  : void
 */
void chcenters(const creal_T varargin_1[307200], emxArray_real_T *centers,
               emxArray_real_T *metric)
{
  int i7;
  static double accumMatrixRe[307200];
  int k;
  static boolean_T bw[307200];
  boolean_T flat;
  boolean_T exitg1;
  static double Hd[307200];
  static double mask[307200];
  double imSize[2];
  boolean_T conn[9];
  double connSize[2];
  emxArray_struct_T *s;
  int idx;
  int i8;
  emxArray_real_T *x;
  emxArray_real_T *b_x;
  int b_idx;
  int i;
  emxArray_real_T *b_varargin_1;
  int loop_ub;
  emxArray_real_T *varargin_2;
  emxArray_int32_T *c_idx;
  emxArray_real_T *b_metric;
  emxArray_int32_T *b_sortIdx;
  emxArray_int32_T *iidx;
  emxArray_real_T *b_centers;
  i7 = centers->size[0] * centers->size[1];
  centers->size[0] = 0;
  centers->size[1] = 0;
  emxEnsureCapacity((emxArray__common *)centers, i7, (int)sizeof(double));
  i7 = metric->size[0] * metric->size[1];
  metric->size[0] = 0;
  metric->size[1] = 0;
  emxEnsureCapacity((emxArray__common *)metric, i7, (int)sizeof(double));
  for (k = 0; k < 307200; k++) {
    accumMatrixRe[k] = rt_hypotd_snf(varargin_1[k].re, varargin_1[k].im);
  }

  for (i7 = 0; i7 < 307200; i7++) {
    bw[i7] = (accumMatrixRe[i7] == accumMatrixRe[0]);
  }

  flat = true;
  k = 0;
  exitg1 = false;
  while ((!exitg1) && (k < 307200)) {
    if (!bw[k]) {
      flat = false;
      exitg1 = true;
    } else {
      k++;
    }
  }

  if (!flat) {
    medfilt2(accumMatrixRe, Hd);
    memcpy(&mask[0], &Hd[0], 307200U * sizeof(double));
    for (i7 = 0; i7 < 2; i7++) {
      imSize[i7] = 480.0 + 160.0 * (double)i7;
    }

    for (i7 = 0; i7 < 307200; i7++) {
      Hd[i7] -= 0.15;
    }

    ippreconstruct_real64(Hd, mask, imSize, 2.0);
    for (i7 = 0; i7 < 2; i7++) {
      imSize[i7] = 480.0 + 160.0 * (double)i7;
    }

    for (i7 = 0; i7 < 9; i7++) {
      conn[i7] = true;
    }

    for (i7 = 0; i7 < 2; i7++) {
      connSize[i7] = 3.0;
    }

    emxInit_struct_T(&s, 1);
    imregionalmax_real64(Hd, bw, 2.0, imSize, conn, 2.0, connSize);
    regionprops(bw, accumMatrixRe, s);
    if (!(s->size[0] == 0)) {
      i7 = centers->size[0] * centers->size[1];
      centers->size[0] = s->size[0];
      centers->size[1] = 2;
      emxEnsureCapacity((emxArray__common *)centers, i7, (int)sizeof(double));
      for (idx = 0; idx < s->size[0]; idx++) {
        for (i7 = 0; i7 < 2; i7++) {
          centers->data[idx + centers->size[0] * i7] = s->data[idx].
            WeightedCentroid[i7];
        }
      }

      i7 = centers->size[0];
      i8 = (int)((1.0 + (-1.0 - (double)centers->size[0])) / -1.0);
      idx = 0;
      emxInit_real_T1(&x, 2);
      emxInit_real_T1(&b_x, 2);
      while (idx <= i8 - 1) {
        b_idx = i7 - idx;
        if (rtIsNaN(centers->data[b_idx - 1]) || rtIsNaN(centers->data[(b_idx +
              centers->size[0]) - 1])) {
          i = x->size[0] * x->size[1];
          x->size[0] = centers->size[0];
          x->size[1] = centers->size[1];
          emxEnsureCapacity((emxArray__common *)x, i, (int)sizeof(double));
          loop_ub = centers->size[0] * centers->size[1];
          for (i = 0; i < loop_ub; i++) {
            x->data[i] = centers->data[i];
          }

          for (k = 0; k < 2; k++) {
            for (i = b_idx; i < centers->size[0]; i++) {
              x->data[(i + x->size[0] * k) - 1] = x->data[i + x->size[0] * k];
            }
          }

          if (1 > centers->size[0] - 1) {
            loop_ub = 0;
          } else {
            loop_ub = centers->size[0] - 1;
          }

          i = b_x->size[0] * b_x->size[1];
          b_x->size[0] = loop_ub;
          b_x->size[1] = 2;
          emxEnsureCapacity((emxArray__common *)b_x, i, (int)sizeof(double));
          for (i = 0; i < 2; i++) {
            for (k = 0; k < loop_ub; k++) {
              b_x->data[k + b_x->size[0] * i] = x->data[k + x->size[0] * i];
            }
          }

          i = x->size[0] * x->size[1];
          x->size[0] = b_x->size[0];
          x->size[1] = 2;
          emxEnsureCapacity((emxArray__common *)x, i, (int)sizeof(double));
          for (i = 0; i < 2; i++) {
            loop_ub = b_x->size[0];
            for (k = 0; k < loop_ub; k++) {
              x->data[k + x->size[0] * i] = b_x->data[k + b_x->size[0] * i];
            }
          }

          i = centers->size[0] * centers->size[1];
          centers->size[0] = x->size[0];
          centers->size[1] = 2;
          emxEnsureCapacity((emxArray__common *)centers, i, (int)sizeof(double));
          loop_ub = x->size[0] * x->size[1];
          for (i = 0; i < loop_ub; i++) {
            centers->data[i] = x->data[i];
          }
        }

        idx++;
      }

      emxFree_real_T(&b_x);
      emxFree_real_T(&x);
      if (!(centers->size[0] == 0)) {
        emxInit_real_T(&b_varargin_1, 1);
        loop_ub = centers->size[0];
        i7 = b_varargin_1->size[0];
        b_varargin_1->size[0] = loop_ub;
        emxEnsureCapacity((emxArray__common *)b_varargin_1, i7, (int)sizeof
                          (double));
        for (i7 = 0; i7 < loop_ub; i7++) {
          b_varargin_1->data[i7] = centers->data[i7 + centers->size[0]];
        }

        emxInit_real_T(&varargin_2, 1);
        b_round(b_varargin_1);
        loop_ub = centers->size[0];
        i7 = varargin_2->size[0];
        varargin_2->size[0] = loop_ub;
        emxEnsureCapacity((emxArray__common *)varargin_2, i7, (int)sizeof(double));
        for (i7 = 0; i7 < loop_ub; i7++) {
          varargin_2->data[i7] = centers->data[i7];
        }

        emxInit_int32_T(&c_idx, 1);
        b_round(varargin_2);
        i7 = c_idx->size[0];
        c_idx->size[0] = b_varargin_1->size[0];
        emxEnsureCapacity((emxArray__common *)c_idx, i7, (int)sizeof(int));
        loop_ub = b_varargin_1->size[0];
        for (i7 = 0; i7 < loop_ub; i7++) {
          c_idx->data[i7] = (int)b_varargin_1->data[i7] + 480 * ((int)
            varargin_2->data[i7] - 1);
        }

        emxFree_real_T(&varargin_2);
        i7 = b_varargin_1->size[0];
        b_varargin_1->size[0] = c_idx->size[0];
        emxEnsureCapacity((emxArray__common *)b_varargin_1, i7, (int)sizeof
                          (double));
        loop_ub = c_idx->size[0];
        for (i7 = 0; i7 < loop_ub; i7++) {
          b_varargin_1->data[i7] = Hd[c_idx->data[i7] - 1];
        }

        emxInit_real_T1(&b_metric, 2);
        i7 = b_metric->size[0] * b_metric->size[1];
        b_metric->size[0] = c_idx->size[0];
        b_metric->size[1] = 1;
        emxEnsureCapacity((emxArray__common *)b_metric, i7, (int)sizeof(double));
        loop_ub = c_idx->size[0];
        emxFree_int32_T(&c_idx);
        for (i7 = 0; i7 < loop_ub; i7++) {
          b_metric->data[i7] = b_varargin_1->data[i7];
        }

        emxFree_real_T(&b_varargin_1);
        emxInit_int32_T1(&b_sortIdx, 2);
        emxInit_int32_T1(&iidx, 2);
        sort(b_metric, iidx);
        i7 = b_sortIdx->size[0] * b_sortIdx->size[1];
        b_sortIdx->size[0] = iidx->size[0];
        b_sortIdx->size[1] = 1;
        emxEnsureCapacity((emxArray__common *)b_sortIdx, i7, (int)sizeof(int));
        loop_ub = iidx->size[0] * iidx->size[1];
        for (i7 = 0; i7 < loop_ub; i7++) {
          b_sortIdx->data[i7] = iidx->data[i7];
        }

        emxFree_int32_T(&iidx);
        i7 = metric->size[0] * metric->size[1];
        metric->size[0] = b_metric->size[0];
        metric->size[1] = 1;
        emxEnsureCapacity((emxArray__common *)metric, i7, (int)sizeof(double));
        loop_ub = b_metric->size[0] * b_metric->size[1];
        for (i7 = 0; i7 < loop_ub; i7++) {
          metric->data[i7] = b_metric->data[i7];
        }

        emxFree_real_T(&b_metric);
        emxInit_real_T1(&b_centers, 2);
        k = b_sortIdx->size[0];
        i7 = b_centers->size[0] * b_centers->size[1];
        b_centers->size[0] = k;
        b_centers->size[1] = 2;
        emxEnsureCapacity((emxArray__common *)b_centers, i7, (int)sizeof(double));
        for (i7 = 0; i7 < 2; i7++) {
          for (i8 = 0; i8 < k; i8++) {
            b_centers->data[i8 + b_centers->size[0] * i7] = centers->data
              [(b_sortIdx->data[i8] + centers->size[0] * i7) - 1];
          }
        }

        emxFree_int32_T(&b_sortIdx);
        i7 = centers->size[0] * centers->size[1];
        centers->size[0] = b_centers->size[0];
        centers->size[1] = b_centers->size[1];
        emxEnsureCapacity((emxArray__common *)centers, i7, (int)sizeof(double));
        loop_ub = b_centers->size[1];
        for (i7 = 0; i7 < loop_ub; i7++) {
          k = b_centers->size[0];
          for (i8 = 0; i8 < k; i8++) {
            centers->data[i8 + centers->size[0] * i7] = b_centers->data[i8 +
              b_centers->size[0] * i7];
          }
        }

        emxFree_real_T(&b_centers);
      }
    }

    emxFree_struct_T(&s);
  }
}

/*
 * File trailer for chcenters.c
 *
 * [EOF]
 */
