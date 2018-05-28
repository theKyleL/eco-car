/*
 * Sponsored License - for use in support of a program or activity
 * sponsored by MathWorks.  Not for government, commercial or other
 * non-sponsored organizational use.
 * File: sort1.c
 *
 * MATLAB Coder version            : 3.2
 * C/C++ source code generated on  : 05-Nov-2016 16:55:10
 */

/* Include Files */
#include "rt_nonfinite.h"
#include "FindCircle.h"
#include "sort1.h"
#include "FindCircle_emxutil.h"
#include "sortIdx.h"

/* Function Definitions */

/*
 * Arguments    : emxArray_real_T *x
 *                emxArray_int32_T *idx
 * Return Type  : void
 */
void sort(emxArray_real_T *x, emxArray_int32_T *idx)
{
  emxArray_int32_T *iwork;
  emxArray_real_T *xwork;
  emxArray_int32_T *b_idx;
  emxArray_real_T *b_x;
  emxArray_int32_T *b_iwork;
  emxArray_real_T *b_xwork;
  int iv0[2];
  int k;
  int loop_ub;
  int i;
  int b;
  double x4[4];
  int idx4[4];
  int preSortLevel;
  int nNaNs;
  int ib;
  int b_k;
  int wOffset;
  signed char perm[4];
  int i4;
  int nNonNaN;
  int nBlocks;
  int c_iwork[256];
  double c_xwork[256];
  int bLen;
  int bLen2;
  int nPairs;
  int exitg1;
  emxInit_int32_T(&iwork, 1);
  emxInit_real_T(&xwork, 1);
  emxInit_int32_T(&b_idx, 1);
  emxInit_real_T(&b_x, 1);
  emxInit_int32_T(&b_iwork, 1);
  emxInit_real_T(&b_xwork, 1);
  for (k = 0; k < 2; k++) {
    iv0[k] = x->size[k];
  }

  k = idx->size[0] * idx->size[1];
  idx->size[0] = iv0[0];
  idx->size[1] = 1;
  emxEnsureCapacity((emxArray__common *)idx, k, (int)sizeof(int));
  loop_ub = iv0[0];
  for (k = 0; k < loop_ub; k++) {
    idx->data[k] = 0;
  }

#pragma omp parallel \
 num_threads(omp_get_max_threads()) \
 private(xwork,iwork,b_xwork,b_iwork,b_idx,b_x,i,b,preSortLevel,nNaNs,ib,b_k,wOffset,i4,nNonNaN,nBlocks,bLen,bLen2,nPairs,exitg1) \
 firstprivate(x4,idx4,perm,c_iwork,c_xwork)

  {
    emxInit_real_T(&xwork, 1);
    emxInit_int32_T(&iwork, 1);
    emxInit_real_T(&b_xwork, 1);
    emxInit_int32_T(&b_iwork, 1);
    emxInit_int32_T(&b_idx, 1);
    emxInit_real_T(&b_x, 1);

#pragma omp for nowait

    for (k = 1; k < 2; k++) {
      i = x->size[0];
      b = b_x->size[0];
      b_x->size[0] = i;
      emxEnsureCapacity((emxArray__common *)b_x, b, (int)sizeof(double));
      for (b = 0; b < i; b++) {
        b_x->data[b] = x->data[b];
      }

      i = idx->size[0];
      b = b_idx->size[0];
      b_idx->size[0] = i;
      emxEnsureCapacity((emxArray__common *)b_idx, b, (int)sizeof(int));
      for (b = 0; b < i; b++) {
        b_idx->data[b] = idx->data[b];
      }

      b = x->size[0];
      for (i = 0; i < 4; i++) {
        x4[i] = 0.0;
        idx4[i] = 0;
      }

      preSortLevel = idx->size[0];
      i = b_iwork->size[0];
      b_iwork->size[0] = preSortLevel;
      emxEnsureCapacity((emxArray__common *)b_iwork, i, (int)sizeof(int));
      i = b_iwork->size[0];
      preSortLevel = b_iwork->size[0];
      b_iwork->size[0] = i;
      emxEnsureCapacity((emxArray__common *)b_iwork, preSortLevel, (int)sizeof
                        (int));
      for (preSortLevel = 0; preSortLevel < i; preSortLevel++) {
        b_iwork->data[preSortLevel] = 0;
      }

      preSortLevel = x->size[0];
      i = b_xwork->size[0];
      b_xwork->size[0] = preSortLevel;
      emxEnsureCapacity((emxArray__common *)b_xwork, i, (int)sizeof(double));
      i = b_xwork->size[0];
      preSortLevel = b_xwork->size[0];
      b_xwork->size[0] = i;
      emxEnsureCapacity((emxArray__common *)b_xwork, preSortLevel, (int)sizeof
                        (double));
      for (preSortLevel = 0; preSortLevel < i; preSortLevel++) {
        b_xwork->data[preSortLevel] = 0.0;
      }

      nNaNs = 0;
      ib = 0;
      for (b_k = 0; b_k + 1 <= b; b_k++) {
        if (rtIsNaN(b_x->data[b_k])) {
          b_idx->data[(b - nNaNs) - 1] = b_k + 1;
          b_xwork->data[(b - nNaNs) - 1] = b_x->data[b_k];
          nNaNs++;
        } else {
          ib++;
          idx4[ib - 1] = b_k + 1;
          x4[ib - 1] = b_x->data[b_k];
          if (ib == 4) {
            i = b_k - nNaNs;
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
                perm[0] = (signed char)preSortLevel;
                perm[1] = (signed char)ib;
                perm[2] = (signed char)wOffset;
                perm[3] = (signed char)i4;
              } else if (x4[ib - 1] >= x4[i4 - 1]) {
                perm[0] = (signed char)preSortLevel;
                perm[1] = (signed char)wOffset;
                perm[2] = (signed char)ib;
                perm[3] = (signed char)i4;
              } else {
                perm[0] = (signed char)preSortLevel;
                perm[1] = (signed char)wOffset;
                perm[2] = (signed char)i4;
                perm[3] = (signed char)ib;
              }
            } else if (x4[preSortLevel - 1] >= x4[i4 - 1]) {
              if (x4[ib - 1] >= x4[i4 - 1]) {
                perm[0] = (signed char)wOffset;
                perm[1] = (signed char)preSortLevel;
                perm[2] = (signed char)ib;
                perm[3] = (signed char)i4;
              } else {
                perm[0] = (signed char)wOffset;
                perm[1] = (signed char)preSortLevel;
                perm[2] = (signed char)i4;
                perm[3] = (signed char)ib;
              }
            } else {
              perm[0] = (signed char)wOffset;
              perm[1] = (signed char)i4;
              perm[2] = (signed char)preSortLevel;
              perm[3] = (signed char)ib;
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

        for (b_k = 1; b_k <= ib; b_k++) {
          b_idx->data[(wOffset - ib) + b_k] = idx4[perm[b_k - 1] - 1];
          b_x->data[(wOffset - ib) + b_k] = x4[perm[b_k - 1] - 1];
        }
      }

      i = nNaNs >> 1;
      for (b_k = 1; b_k <= i; b_k++) {
        preSortLevel = b_idx->data[wOffset + b_k];
        b_idx->data[wOffset + b_k] = b_idx->data[b - b_k];
        b_idx->data[b - b_k] = preSortLevel;
        b_x->data[wOffset + b_k] = b_xwork->data[b - b_k];
        b_x->data[b - b_k] = b_xwork->data[wOffset + b_k];
      }

      if ((nNaNs & 1) != 0) {
        b_x->data[(wOffset + i) + 1] = b_xwork->data[(wOffset + i) + 1];
      }

      b = iwork->size[0];
      iwork->size[0] = b_iwork->size[0];
      emxEnsureCapacity((emxArray__common *)iwork, b, (int)sizeof(int));
      i = b_iwork->size[0];
      for (b = 0; b < i; b++) {
        iwork->data[b] = b_iwork->data[b];
      }

      b = xwork->size[0];
      xwork->size[0] = b_xwork->size[0];
      emxEnsureCapacity((emxArray__common *)xwork, b, (int)sizeof(double));
      i = b_xwork->size[0];
      for (b = 0; b < i; b++) {
        xwork->data[b] = b_xwork->data[b];
      }

      b = x->size[0];
      nNonNaN = b - nNaNs;
      preSortLevel = 2;
      if (nNonNaN > 1) {
        b = x->size[0];
        if (b >= 256) {
          nBlocks = nNonNaN >> 8;
          if (nBlocks > 0) {
            for (wOffset = 1; wOffset <= nBlocks; wOffset++) {
              i4 = ((wOffset - 1) << 8) - 1;
              for (b = 0; b < 6; b++) {
                bLen = 1 << (b + 2);
                bLen2 = bLen << 1;
                nPairs = 256 >> (b + 3);
                for (b_k = 1; b_k <= nPairs; b_k++) {
                  preSortLevel = i4 + (b_k - 1) * bLen2;
                  for (i = 1; i <= bLen2; i++) {
                    c_iwork[i - 1] = b_idx->data[preSortLevel + i];
                    c_xwork[i - 1] = b_x->data[preSortLevel + i];
                  }

                  ib = 0;
                  i = bLen;
                  do {
                    exitg1 = 0;
                    preSortLevel++;
                    if (c_xwork[ib] >= c_xwork[i]) {
                      b_idx->data[preSortLevel] = c_iwork[ib];
                      b_x->data[preSortLevel] = c_xwork[ib];
                      if (ib + 1 < bLen) {
                        ib++;
                      } else {
                        exitg1 = 1;
                      }
                    } else {
                      b_idx->data[preSortLevel] = c_iwork[i];
                      b_x->data[preSortLevel] = c_xwork[i];
                      if (i + 1 < bLen2) {
                        i++;
                      } else {
                        i = preSortLevel - ib;
                        while (ib + 1 <= bLen) {
                          b_idx->data[(i + ib) + 1] = c_iwork[ib];
                          b_x->data[(i + ib) + 1] = c_xwork[ib];
                          ib++;
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
              merge_block(b_idx, b_x, i, preSortLevel, 2, iwork, xwork);
            }

            preSortLevel = 8;
          }
        }

        merge_block(b_idx, b_x, 0, nNonNaN, preSortLevel, iwork, xwork);
      }

      if ((nNaNs > 0) && (nNonNaN > 0)) {
        for (b_k = 0; b_k + 1 <= nNaNs; b_k++) {
          xwork->data[b_k] = b_x->data[nNonNaN + b_k];
          iwork->data[b_k] = b_idx->data[nNonNaN + b_k];
        }

        for (b_k = nNonNaN - 1; b_k + 1 > 0; b_k--) {
          b_x->data[nNaNs + b_k] = b_x->data[b_k];
          b_idx->data[nNaNs + b_k] = b_idx->data[b_k];
        }

        for (b_k = 0; b_k + 1 <= nNaNs; b_k++) {
          b_x->data[b_k] = xwork->data[b_k];
          b_idx->data[b_k] = iwork->data[b_k];
        }
      }

      i = b_idx->size[0];
      for (b = 0; b < i; b++) {
        idx->data[b] = b_idx->data[b];
      }

      i = b_x->size[0];
      for (b = 0; b < i; b++) {
        x->data[b] = b_x->data[b];
      }
    }

    emxFree_real_T(&b_x);
    emxFree_int32_T(&b_idx);
    emxFree_int32_T(&b_iwork);
    emxFree_real_T(&b_xwork);
    emxFree_int32_T(&iwork);
    emxFree_real_T(&xwork);
  }

  emxFree_real_T(&b_xwork);
  emxFree_int32_T(&b_iwork);
  emxFree_real_T(&b_x);
  emxFree_int32_T(&b_idx);
  emxFree_real_T(&xwork);
  emxFree_int32_T(&iwork);
}

/*
 * File trailer for sort1.c
 *
 * [EOF]
 */
