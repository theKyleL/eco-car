/*
 * Sponsored License - for use in support of a program or activity
 * sponsored by MathWorks.  Not for government, commercial or other
 * non-sponsored organizational use.
 *
 * redHSVmask1_initialize.c
 *
 * Code generation for function 'redHSVmask1_initialize'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "redHSVmask1.h"
#include "redHSVmask1_initialize.h"
#include "_coder_redHSVmask1_mex.h"
#include "redHSVmask1_data.h"

/* Function Declarations */
static void redHSVmask1_once(void);

/* Function Definitions */
static void redHSVmask1_once(void)
{
  covrtInstanceData *t0_data = NULL;
  emlrtCoverageInstance.data = t0_data;

  /* Allocate instance data */
  covrtAllocateInstanceData(&emlrtCoverageInstance);

  /* Initialize Coverage Information */
  covrtScriptInit(&emlrtCoverageInstance,
                  "C:\\Users\\Austin Musser\\Documents\\ecocaradas\\VisionProcessingSystem\\fromVideoFile\\redHSVmask1.m",
                  0U, 1U, 1U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U);

  /* Initialize Function Information */
  covrtFcnInit(&emlrtCoverageInstance, 0U, 0U, "redHSVmask1", 0, -1, 1409);

  /* Initialize Basic Block Information */
  covrtBasicBlockInit(&emlrtCoverageInstance, 0U, 0U, 634, -1, 1403);

  /* Initialize If Information */
  /* Initialize MCDC Information */
  /* Initialize For Information */
  /* Initialize While Information */
  /* Initialize Switch Information */
  /* Start callback for coverage engine */
  covrtScriptStart(&emlrtCoverageInstance, 0U);
}

void redHSVmask1_initialize(void)
{
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  mexFunctionCreateRootTLS();
  emlrtBreakCheckR2012bFlagVar = emlrtGetBreakCheckFlagAddressR2012b();
  st.tls = emlrtRootTLSGlobal;
  emlrtClearAllocCountR2012b(&st, false, 0U, 0);
  emlrtEnterRtStackR2012b(&st);
  if (emlrtFirstTimeR2012b(emlrtRootTLSGlobal)) {
    redHSVmask1_once();
  }
}

/* End of code generation (redHSVmask1_initialize.c) */
