/*
 * Sponsored License - for use in support of a program or activity
 * sponsored by MathWorks.  Not for government, commercial or other
 * non-sponsored organizational use.
 * File: imhist.c
 *
 * MATLAB Coder version            : 3.2
 * C/C++ source code generated on  : 05-Nov-2016 16:55:10
 */

/* Include Files */
#include "rt_nonfinite.h"
#include "FindCircle.h"
#include "imhist.h"
#include "libmwgetnumcores.h"

/* Function Definitions */

/*
 * Arguments    : const emxArray_uint8_T *varargin_1
 *                double yout[256]
 * Return Type  : void
 */
void imhist(const emxArray_uint8_T *varargin_1, double yout[256])
{
  double out;
  double localBins1[256];
  double localBins2[256];
  double localBins3[256];
  int i;
  out = 1.0;
  getnumcores(&out);
  memset(&yout[0], 0, sizeof(double) << 8);
  memset(&localBins1[0], 0, sizeof(double) << 8);
  memset(&localBins2[0], 0, sizeof(double) << 8);
  memset(&localBins3[0], 0, sizeof(double) << 8);
  for (i = 0; i + 4 <= varargin_1->size[0]; i += 4) {
    localBins1[varargin_1->data[i]]++;
    localBins2[varargin_1->data[i + 1]]++;
    localBins3[varargin_1->data[i + 2]]++;
    yout[varargin_1->data[i + 3]]++;
  }

  while (i + 1 <= varargin_1->size[0]) {
    yout[varargin_1->data[i]]++;
    i++;
  }

  for (i = 0; i < 256; i++) {
    yout[i] = ((yout[i] + localBins1[i]) + localBins2[i]) + localBins3[i];
  }
}

/*
 * File trailer for imhist.c
 *
 * [EOF]
 */
