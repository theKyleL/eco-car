/*
 * Sponsored License - for use in support of a program or activity
 * sponsored by MathWorks.  Not for government, commercial or other
 * non-sponsored organizational use.
 * File: _coder_redHSVmask1_api.h
 *
 * MATLAB Coder version            : 3.2
 * C/C++ source code generated on  : 05-Nov-2016 17:02:46
 */

#ifndef _CODER_REDHSVMASK1_API_H
#define _CODER_REDHSVMASK1_API_H

/* Include Files */
#include "tmwtypes.h"
#include "mex.h"
#include "emlrt.h"
#include <stddef.h>
#include <stdlib.h>
#include "_coder_redHSVmask1_api.h"

/* Variable Declarations */
extern emlrtCTX emlrtRootTLSGlobal;
extern emlrtContext emlrtContextGlobal;

/* Function Declarations */
extern void redHSVmask1(uint8_T RGB[921600], boolean_T BW[307200]);
extern void redHSVmask1_api(const mxArray *prhs[1], const mxArray *plhs[1]);
extern void redHSVmask1_atexit(void);
extern void redHSVmask1_initialize(void);
extern void redHSVmask1_terminate(void);
extern void redHSVmask1_xil_terminate(void);

#endif

/*
 * File trailer for _coder_redHSVmask1_api.h
 *
 * [EOF]
 */
