/*
 * Sponsored License - for use in support of a program or activity
 * sponsored by MathWorks.  Not for government, commercial or other
 * non-sponsored organizational use.
 *
 * _coder_FindCircle_mex.c
 *
 * Code generation for function '_coder_FindCircle_mex'
 *
 */

/* Include files */
#include "FindCircle.h"
#include "_coder_FindCircle_mex.h"
#include "FindCircle_terminate.h"
#include "_coder_FindCircle_api.h"
#include "FindCircle_initialize.h"
#include "FindCircle_data.h"

/* Function Declarations */
static void FindCircle_mexFunction(FindCircleStackData *SD, int32_T nlhs,
  mxArray *plhs[3], int32_T nrhs, const mxArray *prhs[1]);

/* Function Definitions */
static void FindCircle_mexFunction(FindCircleStackData *SD, int32_T nlhs,
  mxArray *plhs[3], int32_T nrhs, const mxArray *prhs[1])
{
  int32_T n;
  const mxArray *inputs[1];
  const mxArray *outputs[3];
  int32_T b_nlhs;
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  st.tls = emlrtRootTLSGlobal;

  /* Check for proper number of arguments. */
  if (nrhs != 1) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:WrongNumberOfInputs", 5, 12, 1, 4,
                        10, "FindCircle");
  }

  if (nlhs > 3) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:TooManyOutputArguments", 3, 4, 10,
                        "FindCircle");
  }

  /* Temporary copy for mex inputs. */
  for (n = 0; n < nrhs; n++) {
    inputs[n] = prhs[n];
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(&st);
    }
  }

  /* Call the function. */
  FindCircle_api(SD, inputs, outputs);

  /* Copy over outputs to the caller. */
  if (nlhs < 1) {
    b_nlhs = 1;
  } else {
    b_nlhs = nlhs;
  }

  emlrtReturnArrays(b_nlhs, plhs, outputs);

  /* Module termination. */
  FindCircle_terminate();
}

void mexFunction(int32_T nlhs, mxArray *plhs[], int32_T nrhs, const mxArray
                 *prhs[])
{
  FindCircleStackData *FindCircleStackDataGlobal = NULL;
  FindCircleStackDataGlobal = (FindCircleStackData *)mxCalloc(1, 1U * sizeof
    (FindCircleStackData));
  mexAtExit(FindCircle_atexit);

  /* Initialize the memory manager. */
  /* Module initialization. */
  FindCircle_initialize();

  /* Dispatch the entry-point. */
  FindCircle_mexFunction(FindCircleStackDataGlobal, nlhs, plhs, nrhs, prhs);
  mxFree(FindCircleStackDataGlobal);
}

emlrtCTX mexFunctionCreateRootTLS(void)
{
  emlrtCreateRootTLS(&emlrtRootTLSGlobal, &emlrtContextGlobal, NULL, 1);
  return emlrtRootTLSGlobal;
}

/* End of code generation (_coder_FindCircle_mex.c) */
