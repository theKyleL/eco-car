/*
 * Sponsored License - for use in support of a program or activity
 * sponsored by MathWorks.  Not for government, commercial or other
 * non-sponsored organizational use.
 *
 * _coder_redHSVmask1_api.c
 *
 * Code generation for function '_coder_redHSVmask1_api'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "redHSVmask1.h"
#include "_coder_redHSVmask1_api.h"
#include "redHSVmask1_data.h"

/* Function Declarations */
static uint8_T (*b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
  const emlrtMsgIdentifier *parentId))[921600];
static uint8_T (*c_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
  const emlrtMsgIdentifier *msgId))[921600];
static uint8_T (*emlrt_marshallIn(const emlrtStack *sp, const mxArray *RGB,
  const char_T *identifier))[921600];
static const mxArray *emlrt_marshallOut(const boolean_T u[307200]);

/* Function Definitions */
static uint8_T (*b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
  const emlrtMsgIdentifier *parentId))[921600]
{
  uint8_T (*y)[921600];
  y = c_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}
  static uint8_T (*c_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
  const emlrtMsgIdentifier *msgId))[921600]
{
  uint8_T (*ret)[921600];
  static const int32_T dims[3] = { 480, 640, 3 };

  emlrtCheckBuiltInR2012b(sp, msgId, src, "uint8", false, 3U, dims);
  ret = (uint8_T (*)[921600])mxGetData(src);
  emlrtDestroyArray(&src);
  return ret;
}

static uint8_T (*emlrt_marshallIn(const emlrtStack *sp, const mxArray *RGB,
  const char_T *identifier))[921600]
{
  uint8_T (*y)[921600];
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  y = b_emlrt_marshallIn(sp, emlrtAlias(RGB), &thisId);
  emlrtDestroyArray(&RGB);
  return y;
}
  static const mxArray *emlrt_marshallOut(const boolean_T u[307200])
{
  const mxArray *y;
  const mxArray *m0;
  static const int32_T iv0[2] = { 0, 0 };

  static const int32_T iv1[2] = { 480, 640 };

  y = NULL;
  m0 = emlrtCreateLogicalArray(2, iv0);
  mxSetData((mxArray *)m0, (void *)&u[0]);
  emlrtSetDimensions((mxArray *)m0, iv1, 2);
  emlrtAssign(&y, m0);
  return y;
}

void redHSVmask1_api(redHSVmask1StackData *SD, const mxArray * const prhs[1],
                     const mxArray *plhs[1])
{
  boolean_T (*BW)[307200];
  uint8_T (*RGB)[921600];
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  st.tls = emlrtRootTLSGlobal;
  BW = (boolean_T (*)[307200])mxMalloc(sizeof(boolean_T [307200]));

  /* Marshall function inputs */
  RGB = emlrt_marshallIn(&st, emlrtAlias(prhs[0]), "RGB");

  /* Invoke the target function */
  redHSVmask1(SD, &st, *RGB, *BW);

  /* Marshall function outputs */
  plhs[0] = emlrt_marshallOut(*BW);
}

/* End of code generation (_coder_redHSVmask1_api.c) */
