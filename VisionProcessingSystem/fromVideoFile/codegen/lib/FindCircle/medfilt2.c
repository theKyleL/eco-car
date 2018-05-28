/*
 * Sponsored License - for use in support of a program or activity
 * sponsored by MathWorks.  Not for government, commercial or other
 * non-sponsored organizational use.
 * File: medfilt2.c
 *
 * MATLAB Coder version            : 3.2
 * C/C++ source code generated on  : 05-Nov-2016 16:55:10
 */

/* Include Files */
#include "rt_nonfinite.h"
#include "FindCircle.h"
#include "medfilt2.h"
#include "round1.h"
#include "FindCircle_emxutil.h"
#include "padarray.h"
#include "abs.h"
#include "FindCircle_rtwutil.h"
#include "libmwordfilt2.h"

/* Function Definitions */

/*
 * Arguments    : const double varargin_1[307200]
 *                double b[307200]
 * Return Type  : void
 */
void medfilt2(const double varargin_1[307200], double b[307200])
{
  int idx;
  int indices_data[25];
  signed char jj_data[25];
  int ii;
  int jj;
  boolean_T exitg3;
  int loop_ub;
  int rows_size[1];
  int i9;
  int cols_size[1];
  double rows_data[25];
  emxArray_real_T *r5;
  double cols_data[25];
  emxArray_real_T b_rows_data;
  double varargin_1_data[25];
  double padSize;
  emxArray_real_T b_cols_data;
  boolean_T exitg2;
  double mtmp;
  boolean_T exitg1;
  double b_padSize[2];
  emxArray_real_T *Apad;
  double startIdx[2];
  double dv1[2];
  idx = 0;
  ii = 1;
  jj = 1;
  exitg3 = false;
  while ((!exitg3) && (jj <= 5)) {
    idx++;
    indices_data[idx - 1] = ii;
    jj_data[idx - 1] = (signed char)jj;
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
    ii = 0;
  } else {
    loop_ub = idx;
    ii = idx;
  }

  rows_size[0] = loop_ub;
  for (i9 = 0; i9 < loop_ub; i9++) {
    rows_data[i9] = (double)indices_data[i9] - 3.0;
  }

  cols_size[0] = ii;
  for (i9 = 0; i9 < ii; i9++) {
    cols_data[i9] = (double)jj_data[i9] - 3.0;
  }

  emxInit_real_T(&r5, 1);
  b_rows_data.data = (double *)&rows_data;
  b_rows_data.size = (int *)&rows_size;
  b_rows_data.allocatedSize = 25;
  b_rows_data.numDimensions = 1;
  b_rows_data.canFreeData = false;
  b_abs(&b_rows_data, r5);
  idx = r5->size[0];
  loop_ub = r5->size[0];
  for (i9 = 0; i9 < loop_ub; i9++) {
    varargin_1_data[i9] = r5->data[i9];
  }

  ii = 1;
  padSize = varargin_1_data[0];
  if (idx > 1) {
    if (rtIsNaN(varargin_1_data[0])) {
      jj = 2;
      exitg2 = false;
      while ((!exitg2) && (jj <= idx)) {
        ii = jj;
        if (!rtIsNaN(varargin_1_data[jj - 1])) {
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

  b_cols_data.data = (double *)&cols_data;
  b_cols_data.size = (int *)&cols_size;
  b_cols_data.allocatedSize = 25;
  b_cols_data.numDimensions = 1;
  b_cols_data.canFreeData = false;
  b_abs(&b_cols_data, r5);
  idx = r5->size[0];
  loop_ub = r5->size[0];
  for (i9 = 0; i9 < loop_ub; i9++) {
    varargin_1_data[i9] = r5->data[i9];
  }

  emxFree_real_T(&r5);
  ii = 1;
  mtmp = varargin_1_data[0];
  if (idx > 1) {
    if (rtIsNaN(varargin_1_data[0])) {
      jj = 2;
      exitg1 = false;
      while ((!exitg1) && (jj <= idx)) {
        ii = jj;
        if (!rtIsNaN(varargin_1_data[jj - 1])) {
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

  if ((padSize >= mtmp) || rtIsNaN(mtmp)) {
  } else {
    padSize = mtmp;
  }

  for (i9 = 0; i9 < 2; i9++) {
    b_padSize[i9] = padSize;
  }

  emxInit_real_T1(&Apad, 2);
  padarray(varargin_1, b_padSize, Apad);
  ii = Apad->size[0];
  jj = cols_size[0];
  loop_ub = cols_size[0];
  for (i9 = 0; i9 < loop_ub; i9++) {
    mtmp = rt_roundd_snf(cols_data[i9] * (double)ii + rows_data[i9]);
    if (mtmp < 2.147483648E+9) {
      if (mtmp >= -2.147483648E+9) {
        idx = (int)mtmp;
      } else {
        idx = MIN_int32_T;
      }
    } else if (mtmp >= 2.147483648E+9) {
      idx = MAX_int32_T;
    } else {
      idx = 0;
    }

    indices_data[i9] = idx;
  }

  startIdx[0] = padSize;
  startIdx[1] = padSize;
  for (i9 = 0; i9 < 2; i9++) {
    b_padSize[i9] = 5.0;
  }

  for (i9 = 0; i9 < 2; i9++) {
    dv1[i9] = 480.0 + 160.0 * (double)i9;
  }

  ordfilt2_real64(&Apad->data[0], (double)Apad->size[0], startIdx,
                  &indices_data[0], (double)jj, b_padSize, 12.0, b, dv1);
  emxFree_real_T(&Apad);
}

/*
 * File trailer for medfilt2.c
 *
 * [EOF]
 */
