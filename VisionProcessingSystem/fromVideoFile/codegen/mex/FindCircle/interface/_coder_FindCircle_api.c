/*
 * Sponsored License - for use in support of a program or activity
 * sponsored by MathWorks.  Not for government, commercial or other
 * non-sponsored organizational use.
 *
 * _coder_FindCircle_api.c
 *
 * Code generation for function '_coder_FindCircle_api'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "FindCircle.h"
#include "_coder_FindCircle_api.h"
#include "FindCircle_emxutil.h"
#include "warning.h"
#include "FindCircle_mexutil.h"
#include "FindCircle_data.h"

/* Variable Definitions */
static emlrtRTEInfo vb_emlrtRTEI = { 1,/* lineNo */
  1,                                   /* colNo */
  "_coder_FindCircle_api",             /* fName */
  ""                                   /* pName */
};

/* Function Declarations */
static uint8_T (*b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
  const emlrtMsgIdentifier *parentId))[921600];
static const mxArray *b_emlrt_marshallOut(const emxArray_real_T *u);
static uint8_T (*c_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
  const emlrtMsgIdentifier *msgId))[921600];
static const mxArray *c_emlrt_marshallOut(const emxArray_real_T *u);
static uint8_T (*emlrt_marshallIn(const emlrtStack *sp, const mxArray *frameBW,
  const char_T *identifier))[921600];

/* Function Definitions */
static uint8_T (*b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
  const emlrtMsgIdentifier *parentId))[921600]
{
  uint8_T (*y)[921600];
  y = c_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}
  static const mxArray *b_emlrt_marshallOut(const emxArray_real_T *u)
{
  const mxArray *y;
  const mxArray *m3;
  static const int32_T iv19[2] = { 0, 0 };

  y = NULL;
  m3 = emlrtCreateNumericArray(2, iv19, mxDOUBLE_CLASS, mxREAL);
  mxSetData((mxArray *)m3, (void *)&u->data[0]);
  emlrtSetDimensions((mxArray *)m3, u->size, 2);
  emlrtAssign(&y, m3);
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
  static const mxArray *c_emlrt_marshallOut(const emxArray_real_T *u)
{
  const mxArray *y;
  const mxArray *m4;
  static const int32_T iv20[2] = { 0, 0 };

  y = NULL;
  m4 = emlrtCreateNumericArray(2, iv20, mxDOUBLE_CLASS, mxREAL);
  mxSetData((mxArray *)m4, (void *)&u->data[0]);
  emlrtSetDimensions((mxArray *)m4, u->size, 2);
  emlrtAssign(&y, m4);
  return y;
}

static uint8_T (*emlrt_marshallIn(const emlrtStack *sp, const mxArray *frameBW,
  const char_T *identifier))[921600]
{
  uint8_T (*y)[921600];
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  y = b_emlrt_marshallIn(sp, emlrtAlias(frameBW), &thisId);
  emlrtDestroyArray(&frameBW);
  return y;
}
  void FindCircle_api(FindCircleStackData *SD, const mxArray * const prhs[1],
                      const mxArray *plhs[3])
{
  emxArray_real_T *centers;
  emxArray_real_T *radii;
  uint8_T (*frameBW)[921600];
  real_T foundCircles;
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  st.tls = emlrtRootTLSGlobal;
  emlrtHeapReferenceStackEnterFcnR2012b(&st);
  emxInit_real_T1(&st, &centers, 2, &vb_emlrtRTEI, true);
  emxInit_real_T1(&st, &radii, 2, &vb_emlrtRTEI, true);

  /* Marshall function inputs */
  frameBW = emlrt_marshallIn(&st, emlrtAlias(prhs[0]), "frameBW");

  /* Invoke the target function */
  FindCircle(SD, &st, *frameBW, centers, radii, &foundCircles);

  /* Marshall function outputs */
  plhs[0] = b_emlrt_marshallOut(centers);
  plhs[1] = c_emlrt_marshallOut(radii);
  plhs[2] = emlrt_marshallOut(foundCircles);
  radii->canFreeData = false;
  emxFree_real_T(&radii);
  centers->canFreeData = false;
  emxFree_real_T(&centers);
  emlrtHeapReferenceStackLeaveFcnR2012b(&st);
}

/* End of code generation (_coder_FindCircle_api.c) */
