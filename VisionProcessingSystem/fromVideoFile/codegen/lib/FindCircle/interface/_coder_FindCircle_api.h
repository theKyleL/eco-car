/*
 * Sponsored License - for use in support of a program or activity
 * sponsored by MathWorks.  Not for government, commercial or other
 * non-sponsored organizational use.
 * File: _coder_FindCircle_api.h
 *
 * MATLAB Coder version            : 3.2
 * C/C++ source code generated on  : 05-Nov-2016 16:55:10
 */

#ifndef _CODER_FINDCIRCLE_API_H
#define _CODER_FINDCIRCLE_API_H

/* Include Files */
#include "tmwtypes.h"
#include "mex.h"
#include "emlrt.h"
#include <stddef.h>
#include <stdlib.h>
#include "_coder_FindCircle_api.h"

/* Type Definitions */
#ifndef struct_emxArray_real_T
#define struct_emxArray_real_T

struct emxArray_real_T
{
  real_T *data;
  int32_T *size;
  int32_T allocatedSize;
  int32_T numDimensions;
  boolean_T canFreeData;
};

#endif                                 /*struct_emxArray_real_T*/

#ifndef typedef_emxArray_real_T
#define typedef_emxArray_real_T

typedef struct emxArray_real_T emxArray_real_T;

#endif                                 /*typedef_emxArray_real_T*/

/* Variable Declarations */
extern emlrtCTX emlrtRootTLSGlobal;
extern emlrtContext emlrtContextGlobal;

/* Function Declarations */
extern void FindCircle(uint8_T frameBW[921600], emxArray_real_T *centers,
  emxArray_real_T *radii, real_T *foundCircles);
extern void FindCircle_api(const mxArray *prhs[1], const mxArray *plhs[3]);
extern void FindCircle_atexit(void);
extern void FindCircle_initialize(void);
extern void FindCircle_terminate(void);
extern void FindCircle_xil_terminate(void);

#endif

/*
 * File trailer for _coder_FindCircle_api.h
 *
 * [EOF]
 */
