/*
 * Sponsored License - for use in support of a program or activity
 * sponsored by MathWorks.  Not for government, commercial or other
 * non-sponsored organizational use.
 * File: chaccum.c
 *
 * MATLAB Coder version            : 3.2
 * C/C++ source code generated on  : 05-Nov-2016 16:55:10
 */

/* Include Files */
#include "rt_nonfinite.h"
#include "FindCircle.h"
#include "chaccum.h"
#include "FindCircle_emxutil.h"
#include "multithresh.h"
#include "convn.h"
#include "imfilter.h"
#include "all.h"
#include "libmwrgb2gray_tbb.h"

/* Function Declarations */
static float rt_hypotf_snf(float u0, float u1);

/* Function Definitions */

/*
 * Arguments    : float u0
 *                float u1
 * Return Type  : float
 */
static float rt_hypotf_snf(float u0, float u1)
{
  float y;
  float a;
  float b;
  a = (float)fabs(u0);
  b = (float)fabs(u1);
  if (a < b) {
    a /= b;
    y = b * (float)sqrt(a * a + 1.0F);
  } else if (a > b) {
    b /= a;
    y = a * (float)sqrt(b * b + 1.0F);
  } else if (rtIsNaNF(b)) {
    y = b;
  } else {
    y = a * 1.41421354F;
  }

  return y;
}

/*
 * Arguments    : const unsigned char varargin_1[921600]
 *                creal_T accumMatrix[307200]
 *                float gradientImg[307200]
 * Return Type  : void
 */
void chaccum(const unsigned char varargin_1[921600], creal_T accumMatrix[307200],
             float gradientImg[307200])
{
  static boolean_T b_varargin_1[921600];
  int i1;
  static unsigned char A[307200];
  static float b_A[307200];
  static float fv0[309444];
  static const float fv1[9] = { -1.0F, -2.0F, -1.0F, -0.0F, -0.0F, -0.0F, 1.0F,
    2.0F, 1.0F };

  static float Gx[307200];
  static float fv2[309444];
  static const float fv3[9] = { -1.0F, -0.0F, 1.0F, -2.0F, -0.0F, 2.0F, -1.0F,
    -0.0F, 1.0F };

  int ixstart;
  float t;
  int jj;
  boolean_T exitg2;
  static float b_gradientImg[307200];
  emxArray_int32_T *ii;
  emxArray_int32_T *b_jj;
  float edgeThresh;
  int idx;
  boolean_T exitg1;
  boolean_T guard1 = false;
  emxArray_real_T *Ey;
  emxArray_real_T *Ex;
  emxArray_int32_T *ndx;
  creal_T w0[31];
  int c_varargin_1;
  static const creal_T dcv0[31] = { { -1.0,/* re */
      -1.2246467991473532E-16          /* im */
    }, { -0.95615124641749827,         /* re */
      -0.29287334118055974             /* im */
    }, { -0.8336990307590183,          /* re */
      -0.55221909249090018             /* im */
    }, { -0.64943121249867575,         /* re */
      -0.7604203444362202              /* im */
    }, { -0.42252321772467138,         /* re */
      -0.90635210072222483             /* im */
    }, { -0.17259493247790872,         /* re */
      -0.98499288793521045             /* im */
    }, { 0.081806067135590188,         /* re */
      -0.99664826663161732             /* im */
    }, { 0.32429052496520183,          /* re */
      -0.9459575336228333              /* im */
    }, { 0.5413163044171575,           /* re */
      -0.8408190403244632              /* im */
    }, { 0.72253513364778288,          /* re */
      -0.6913342032943115              /* im */
    }, { 0.86086194086240941,          /* re */
      -0.50883859796069475             /* im */
    }, { 0.9523324991276807,           /* re */
      -0.30506197912100752             /* im */
    }, { 0.99581076703864879,          /* re */
      -0.091438045965002171            /* im */
    }, { 0.99259987429192575,          /* re */
      0.12143100738960029              /* im */
    }, { 0.94600183597195175,          /* re */
      0.32416126594288897              /* im */
    }, { 0.86086194086241141,          /* re */
      0.50883859796069131              /* im */
    }, { 0.74312509122060533,          /* re */
      0.66915252282149174              /* im */
    }, { 0.5994236088602789,           /* re */
      0.80043196908976555              /* im */
    }, { 0.43670937692412126,          /* re */
      0.89960264567560366              /* im */
    }, { 0.26193771706003083,          /* re */
      0.96508477989313413              /* im */
    }, { 0.081806067135594393,         /* re */
      0.996648266631617                /* im */
    }, { -0.097452774920332663,        /* re */
      0.99524015024532                 /* im */
    }, { -0.27022547076676262,         /* re */
      0.96279706841518864              /* im */
    }, { -0.43162528684845275,         /* re */
      0.90205299830608121              /* im */
    }, { -0.57755683638145328,         /* re */
      0.8163504766636982               /* im */
    }, { -0.70474420482416189,         /* re */
      0.70946148998149272              /* im */
    }, { -0.810728382535478,           /* re */
      0.58542248825220888              /* im */
    }, { -0.89383978605837788,         /* re */
      0.44838648157489452              /* im */
    }, { -0.95315131088542715,         /* re */
      0.30249393143894937              /* im */
    }, { -0.98841689123984988,         /* re */
      0.15176313489036372              /* im */
    }, { -1.0,                         /* re */
      1.2246467991473532E-16           /* im */
    } };

  static const double dv0[31] = { 94.247779607693786, 97.389372261283583,
    100.53096491487338, 103.67255756846318, 106.81415022205297,
    109.95574287564276, 113.09733552923255, 116.23892818282235,
    119.38052083641213, 122.52211349000193, 125.66370614359172,
    128.80529879718151, 131.94689145077132, 135.0884841043611,
    138.23007675795088, 141.37166941154069, 144.51326206513048,
    147.65485471872029, 150.79644737231007, 153.93804002589985,
    157.07963267948966, 160.22122533307945, 163.36281798666926,
    166.50441064025904, 169.64600329384882, 172.78759594743863,
    175.92918860102841, 179.0707812546182, 182.212373908208, 185.35396656179779,
    188.49555921538757 };

  int i;
  emxArray_real_T *Ex_chunk;
  emxArray_real_T *Ey_chunk;
  emxArray_real_T *idxE_chunk;
  emxArray_real32_T *xc;
  emxArray_real32_T *yc;
  emxArray_creal_T *w;
  emxArray_boolean_T *inside;
  emxArray_boolean_T *rows_to_keep;
  emxArray_int32_T *xckeep;
  emxArray_int32_T *yckeep;
  emxArray_creal_T *wkeep;
  emxArray_real_T *r0;
  int idxEdge;
  static creal_T out[307200];
  for (i1 = 0; i1 < 921600; i1++) {
    b_varargin_1[i1] = (varargin_1[i1] == varargin_1[0]);
  }

  if (all(b_varargin_1)) {
    memset(&accumMatrix[0], 0, 307200U * sizeof(creal_T));
    memset(&gradientImg[0], 0, 307200U * sizeof(float));
  } else {
    rgb2gray_tbb_uint8(varargin_1, 307200.0, A);
    for (i1 = 0; i1 < 307200; i1++) {
      b_A[i1] = (float)A[i1] / 255.0F;
    }

    padImage(b_A, fv0);
    convn(fv0, fv1, Gx);
    padImage(b_A, fv2);
    convn(fv2, fv3, b_A);
    for (ixstart = 0; ixstart < 307200; ixstart++) {
      gradientImg[ixstart] = rt_hypotf_snf(Gx[ixstart], b_A[ixstart]);
    }

    ixstart = 1;
    t = gradientImg[0];
    if (rtIsNaNF(gradientImg[0])) {
      jj = 2;
      exitg2 = false;
      while ((!exitg2) && (jj < 307201)) {
        ixstart = jj;
        if (!rtIsNaNF(gradientImg[jj - 1])) {
          t = gradientImg[jj - 1];
          exitg2 = true;
        } else {
          jj++;
        }
      }
    }

    if (ixstart < 307200) {
      while (ixstart + 1 < 307201) {
        if (gradientImg[ixstart] > t) {
          t = gradientImg[ixstart];
        }

        ixstart++;
      }
    }

    for (i1 = 0; i1 < 307200; i1++) {
      b_gradientImg[i1] = gradientImg[i1] / t;
    }

    emxInit_int32_T(&ii, 1);
    emxInit_int32_T(&b_jj, 1);
    edgeThresh = multithresh(b_gradientImg);
    t *= edgeThresh;
    idx = 0;
    i1 = ii->size[0];
    ii->size[0] = 307200;
    emxEnsureCapacity((emxArray__common *)ii, i1, (int)sizeof(int));
    i1 = b_jj->size[0];
    b_jj->size[0] = 307200;
    emxEnsureCapacity((emxArray__common *)b_jj, i1, (int)sizeof(int));
    ixstart = 1;
    jj = 1;
    exitg1 = false;
    while ((!exitg1) && (jj <= 640)) {
      guard1 = false;
      if (gradientImg[(ixstart + 480 * (jj - 1)) - 1] > t) {
        idx++;
        ii->data[idx - 1] = ixstart;
        b_jj->data[idx - 1] = jj;
        if (idx >= 307200) {
          exitg1 = true;
        } else {
          guard1 = true;
        }
      } else {
        guard1 = true;
      }

      if (guard1) {
        ixstart++;
        if (ixstart > 480) {
          ixstart = 1;
          jj++;
        }
      }
    }

    i1 = ii->size[0];
    if (1 > idx) {
      ii->size[0] = 0;
    } else {
      ii->size[0] = idx;
    }

    emxEnsureCapacity((emxArray__common *)ii, i1, (int)sizeof(int));
    emxInit_real_T(&Ey, 1);
    i1 = b_jj->size[0];
    if (1 > idx) {
      b_jj->size[0] = 0;
    } else {
      b_jj->size[0] = idx;
    }

    emxEnsureCapacity((emxArray__common *)b_jj, i1, (int)sizeof(int));
    i1 = Ey->size[0];
    Ey->size[0] = ii->size[0];
    emxEnsureCapacity((emxArray__common *)Ey, i1, (int)sizeof(double));
    ixstart = ii->size[0];
    for (i1 = 0; i1 < ixstart; i1++) {
      Ey->data[i1] = ii->data[i1];
    }

    emxFree_int32_T(&ii);
    emxInit_real_T(&Ex, 1);
    i1 = Ex->size[0];
    Ex->size[0] = b_jj->size[0];
    emxEnsureCapacity((emxArray__common *)Ex, i1, (int)sizeof(double));
    ixstart = b_jj->size[0];
    for (i1 = 0; i1 < ixstart; i1++) {
      Ex->data[i1] = b_jj->data[i1];
    }

    emxFree_int32_T(&b_jj);
    emxInit_int32_T(&ndx, 1);
    i1 = ndx->size[0];
    ndx->size[0] = Ey->size[0];
    emxEnsureCapacity((emxArray__common *)ndx, i1, (int)sizeof(int));
    ixstart = Ey->size[0];
    for (i1 = 0; i1 < ixstart; i1++) {
      ndx->data[i1] = (int)Ey->data[i1] + 480 * ((int)Ex->data[i1] - 1);
    }

    for (i1 = 0; i1 < 31; i1++) {
      if (dcv0[i1].im == 0.0) {
        w0[i1].re = dcv0[i1].re / dv0[i1];
        w0[i1].im = 0.0;
      } else if (dcv0[i1].re == 0.0) {
        w0[i1].re = 0.0;
        w0[i1].im = dcv0[i1].im / dv0[i1];
      } else {
        w0[i1].re = dcv0[i1].re / dv0[i1];
        w0[i1].im = dcv0[i1].im / dv0[i1];
      }
    }

    c_varargin_1 = Ex->size[0];
    memset(&accumMatrix[0], 0, 307200U * sizeof(creal_T));
    i1 = (int)(((double)Ex->size[0] + 32257.0) / 32258.0);
    i = 0;
    emxInit_real_T(&Ex_chunk, 1);
    emxInit_real_T(&Ey_chunk, 1);
    emxInit_real_T(&idxE_chunk, 1);
    emxInit_real32_T(&xc, 2);
    emxInit_real32_T(&yc, 2);
    emxInit_creal_T1(&w, 2);
    emxInit_boolean_T(&inside, 2);
    emxInit_boolean_T1(&rows_to_keep, 1);
    emxInit_int32_T(&xckeep, 1);
    emxInit_int32_T(&yckeep, 1);
    emxInit_creal_T(&wkeep, 1);
    emxInit_real_T1(&r0, 2);
    while (i <= i1 - 1) {
      idxEdge = i * 32258;
      if (idxEdge + 32258 <= c_varargin_1) {
        ixstart = idxEdge + 32258;
      } else {
        ixstart = c_varargin_1;
      }

      if (ixstart < idxEdge + 1) {
        jj = r0->size[0] * r0->size[1];
        r0->size[0] = 1;
        r0->size[1] = 0;
        emxEnsureCapacity((emxArray__common *)r0, jj, (int)sizeof(double));
      } else {
        jj = r0->size[0] * r0->size[1];
        r0->size[0] = 1;
        r0->size[1] = ixstart - idxEdge;
        emxEnsureCapacity((emxArray__common *)r0, jj, (int)sizeof(double));
        ixstart -= idxEdge;
        for (jj = 0; jj < ixstart; jj++) {
          r0->data[r0->size[0] * jj] = (idxEdge + jj) + 1;
        }
      }

      jj = Ex_chunk->size[0];
      Ex_chunk->size[0] = r0->size[1];
      emxEnsureCapacity((emxArray__common *)Ex_chunk, jj, (int)sizeof(double));
      jj = Ey_chunk->size[0];
      Ey_chunk->size[0] = r0->size[1];
      emxEnsureCapacity((emxArray__common *)Ey_chunk, jj, (int)sizeof(double));
      jj = idxE_chunk->size[0];
      idxE_chunk->size[0] = r0->size[1];
      emxEnsureCapacity((emxArray__common *)idxE_chunk, jj, (int)sizeof(double));
      for (idx = 0; idx < r0->size[1]; idx++) {
        Ex_chunk->data[idx] = Ex->data[idxEdge];
        Ey_chunk->data[idx] = Ey->data[idxEdge];
        idxE_chunk->data[idx] = ndx->data[idxEdge];
        idxEdge++;
      }

      jj = xc->size[0] * xc->size[1];
      xc->size[0] = idxE_chunk->size[0];
      xc->size[1] = 31;
      emxEnsureCapacity((emxArray__common *)xc, jj, (int)sizeof(float));
      jj = yc->size[0] * yc->size[1];
      yc->size[0] = idxE_chunk->size[0];
      yc->size[1] = 31;
      emxEnsureCapacity((emxArray__common *)yc, jj, (int)sizeof(float));
      jj = w->size[0] * w->size[1];
      w->size[0] = idxE_chunk->size[0];
      w->size[1] = 31;
      emxEnsureCapacity((emxArray__common *)w, jj, (int)sizeof(creal_T));
      jj = inside->size[0] * inside->size[1];
      inside->size[0] = idxE_chunk->size[0];
      inside->size[1] = 31;
      emxEnsureCapacity((emxArray__common *)inside, jj, (int)sizeof(boolean_T));
      jj = rows_to_keep->size[0];
      rows_to_keep->size[0] = idxE_chunk->size[0];
      emxEnsureCapacity((emxArray__common *)rows_to_keep, jj, (int)sizeof
                        (boolean_T));
      ixstart = idxE_chunk->size[0];
      for (jj = 0; jj < ixstart; jj++) {
        rows_to_keep->data[jj] = false;
      }

      for (ixstart = 0; ixstart < 31; ixstart++) {
        for (jj = 0; jj < idxE_chunk->size[0]; jj++) {
          t = (float)Ex_chunk->data[jj] + (float)-(15.0 + 0.5 * (double)ixstart)
            * (Gx[(int)idxE_chunk->data[jj] - 1] / gradientImg[(int)
               idxE_chunk->data[jj] - 1]);
          if (t > 0.0F) {
            xc->data[jj + xc->size[0] * ixstart] = t + 0.5F;
          } else if (t < 0.0F) {
            xc->data[jj + xc->size[0] * ixstart] = t - 0.5F;
          } else {
            xc->data[jj + xc->size[0] * ixstart] = 0.0F;
          }

          t = (float)Ey_chunk->data[jj] + (float)-(15.0 + 0.5 * (double)ixstart)
            * (b_A[(int)idxE_chunk->data[jj] - 1] / gradientImg[(int)
               idxE_chunk->data[jj] - 1]);
          if (t > 0.0F) {
            yc->data[jj + yc->size[0] * ixstart] = t + 0.5F;
          } else if (t < 0.0F) {
            yc->data[jj + yc->size[0] * ixstart] = t - 0.5F;
          } else {
            yc->data[jj + yc->size[0] * ixstart] = 0.0F;
          }

          w->data[jj + w->size[0] * ixstart] = w0[ixstart];
          inside->data[jj + inside->size[0] * ixstart] = ((xc->data[jj +
            xc->size[0] * ixstart] >= 1.0F) && (xc->data[jj + xc->size[0] *
            ixstart] <= 640.0F) && (yc->data[jj + yc->size[0] * ixstart] >= 1.0F)
            && (yc->data[jj + yc->size[0] * ixstart] < 480.0F));
          if (inside->data[jj + inside->size[0] * ixstart]) {
            rows_to_keep->data[jj] = true;
          }
        }
      }

      jj = xckeep->size[0];
      xckeep->size[0] = xc->size[0] * 31;
      emxEnsureCapacity((emxArray__common *)xckeep, jj, (int)sizeof(int));
      jj = yckeep->size[0];
      yckeep->size[0] = yc->size[0] * 31;
      emxEnsureCapacity((emxArray__common *)yckeep, jj, (int)sizeof(int));
      jj = wkeep->size[0];
      wkeep->size[0] = w->size[0] * 31;
      emxEnsureCapacity((emxArray__common *)wkeep, jj, (int)sizeof(creal_T));
      idxEdge = -1;
      for (ixstart = 0; ixstart < 31; ixstart++) {
        for (jj = 0; jj < idxE_chunk->size[0]; jj++) {
          if (rows_to_keep->data[jj] && inside->data[jj + inside->size[0] *
              ixstart]) {
            idxEdge++;
            xckeep->data[idxEdge] = (int)xc->data[jj + xc->size[0] * ixstart];
            yckeep->data[idxEdge] = (int)yc->data[jj + yc->size[0] * ixstart];
            wkeep->data[idxEdge] = w->data[jj + w->size[0] * ixstart];
          }
        }
      }

      memset(&out[0], 0, 307200U * sizeof(creal_T));
      for (idx = 0; idx + 1 <= idxEdge + 1; idx++) {
        out[(yckeep->data[idx] + 480 * (xckeep->data[idx] - 1)) - 1].re +=
          wkeep->data[idx].re;
        out[(yckeep->data[idx] + 480 * (xckeep->data[idx] - 1)) - 1].im +=
          wkeep->data[idx].im;
      }

      for (jj = 0; jj < 307200; jj++) {
        accumMatrix[jj].re += out[jj].re;
        accumMatrix[jj].im += out[jj].im;
      }

      i++;
    }

    emxFree_int32_T(&ndx);
    emxFree_real_T(&Ex);
    emxFree_real_T(&Ey);
    emxFree_real_T(&r0);
    emxFree_creal_T(&wkeep);
    emxFree_int32_T(&yckeep);
    emxFree_int32_T(&xckeep);
    emxFree_boolean_T(&rows_to_keep);
    emxFree_boolean_T(&inside);
    emxFree_creal_T(&w);
    emxFree_real32_T(&yc);
    emxFree_real32_T(&xc);
    emxFree_real_T(&idxE_chunk);
    emxFree_real_T(&Ey_chunk);
    emxFree_real_T(&Ex_chunk);
  }
}

/*
 * File trailer for chaccum.c
 *
 * [EOF]
 */
