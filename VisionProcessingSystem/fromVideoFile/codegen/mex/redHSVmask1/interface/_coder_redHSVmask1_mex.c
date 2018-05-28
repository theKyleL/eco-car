/*
 * Sponsored License - for use in support of a program or activity
 * sponsored by MathWorks.  Not for government, commercial or other
 * non-sponsored organizational use.
 *
 * _coder_redHSVmask1_mex.c
 *
 * Code generation for function '_coder_redHSVmask1_mex'
 *
 */

/* Include files */
#include "redHSVmask1.h"
#include "_coder_redHSVmask1_mex.h"
#include "redHSVmask1_terminate.h"
#include "_coder_redHSVmask1_api.h"
#include "redHSVmask1_initialize.h"
#include "redHSVmask1_data.h"

/* Function Declarations */
static void redHSVmask1_mexFunction(redHSVmask1StackData *SD, int32_T nlhs,
  mxArray *plhs[1], int32_T nrhs, const mxArray *prhs[1]);

/* Function Definitions */
static void redHSVmask1_mexFunction(redHSVmask1StackData *SD, int32_T nlhs,
  mxArray *plhs[1], int32_T nrhs, const mxArray *prhs[1])
{
  int32_T n;
  const mxArray *inputs[1];
  const mxArray *outputs[1];
  int32_T b_nlhs;
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  st.tls = emlrtRootTLSGlobal;

  /* Check for proper number of arguments. */
  if (nrhs != 1) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:WrongNumberOfInputs", 5, 12, 1, 4,
                        11, "redHSVmask1");
  }

  if (nlhs > 1) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:TooManyOutputArguments", 3, 4, 11,
                        "redHSVmask1");
  }

  /* Temporary copy for mex inputs. */
  for (n = 0; n < nrhs; n++) {
    inputs[n] = prhs[n];
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(&st);
    }
  }

  /* Call the function. */
  redHSVmask1_api(SD, inputs, outputs);

  /* Copy over outputs to the caller. */
  if (nlhs < 1) {
    b_nlhs = 1;
  } else {
    b_nlhs = nlhs;
  }

  emlrtReturnArrays(b_nlhs, plhs, outputs);

  /* Module termination. */
  redHSVmask1_terminate();
}

void mexFunction(int32_T nlhs, mxArray *plhs[], int32_T nrhs, const mxArray
                 *prhs[])
{
  redHSVmask1StackData *redHSVmask1StackDataGlobal = NULL;
  redHSVmask1StackDataGlobal = (redHSVmask1StackData *)mxCalloc(1, 1U * sizeof
    (redHSVmask1StackData));
  mexAtExit(redHSVmask1_atexit);

  /* Initialize the memory manager. */
  /* Module initialization. */
  redHSVmask1_initialize();

  /* Dispatch the entry-point. */
  redHSVmask1_mexFunction(redHSVmask1StackDataGlobal, nlhs, plhs, nrhs, prhs);
  mxFree(redHSVmask1StackDataGlobal);
}

emlrtCTX mexFunctionCreateRootTLS(void)
{
  emlrtCreateRootTLS(&emlrtRootTLSGlobal, &emlrtContextGlobal, NULL, 1);
  return emlrtRootTLSGlobal;
}

/* End of code generation (_coder_redHSVmask1_mex.c) */
