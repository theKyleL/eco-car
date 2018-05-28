/*
 * Sponsored License - for use in support of a program or activity
 * sponsored by MathWorks.  Not for government, commercial or other
 * non-sponsored organizational use.
 *
 * bwconncomp.c
 *
 * Code generation for function 'bwconncomp'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "FindCircle.h"
#include "bwconncomp.h"
#include "FindCircle_emxutil.h"
#include "eml_int_forloop_overflow_check.h"
#include "FindCircle_data.h"

/* Variable Definitions */
static emlrtRSInfo lf_emlrtRSI = { 9,  /* lineNo */
  "bwconncomp",                        /* fcnName */
  "C:\\Program Files\\MATLAB\\R2016b\\toolbox\\images\\images\\eml\\bwconncomp.m"/* pathName */
};

static emlrtRSInfo mf_emlrtRSI = { 30, /* lineNo */
  "bwconncomp",                        /* fcnName */
  "C:\\Program Files\\MATLAB\\R2016b\\toolbox\\images\\images\\eml\\bwconncomp.m"/* pathName */
};

static emlrtRSInfo nf_emlrtRSI = { 43, /* lineNo */
  "bwconncomp",                        /* fcnName */
  "C:\\Program Files\\MATLAB\\R2016b\\toolbox\\images\\images\\eml\\bwconncomp.m"/* pathName */
};

static emlrtRSInfo of_emlrtRSI = { 55, /* lineNo */
  "bwconncomp",                        /* fcnName */
  "C:\\Program Files\\MATLAB\\R2016b\\toolbox\\images\\images\\eml\\bwconncomp.m"/* pathName */
};

static emlrtRSInfo pf_emlrtRSI = { 56, /* lineNo */
  "bwconncomp",                        /* fcnName */
  "C:\\Program Files\\MATLAB\\R2016b\\toolbox\\images\\images\\eml\\bwconncomp.m"/* pathName */
};

static emlrtRSInfo qf_emlrtRSI = { 57, /* lineNo */
  "bwconncomp",                        /* fcnName */
  "C:\\Program Files\\MATLAB\\R2016b\\toolbox\\images\\images\\eml\\bwconncomp.m"/* pathName */
};

static emlrtRSInfo rf_emlrtRSI = { 65, /* lineNo */
  "bwconncomp",                        /* fcnName */
  "C:\\Program Files\\MATLAB\\R2016b\\toolbox\\images\\images\\eml\\bwconncomp.m"/* pathName */
};

static emlrtRSInfo sf_emlrtRSI = { 33, /* lineNo */
  "intermediateLabelRuns",             /* fcnName */
  "C:\\Program Files\\MATLAB\\R2016b\\toolbox\\images\\images\\+images\\+internal\\+coder\\intermediateLabelRuns.m"/* pathName */
};

static emlrtRSInfo tf_emlrtRSI = { 51, /* lineNo */
  "intermediateLabelRuns",             /* fcnName */
  "C:\\Program Files\\MATLAB\\R2016b\\toolbox\\images\\images\\+images\\+internal\\+coder\\intermediateLabelRuns.m"/* pathName */
};

static emlrtRSInfo uf_emlrtRSI = { 114,/* lineNo */
  "intermediateLabelRuns",             /* fcnName */
  "C:\\Program Files\\MATLAB\\R2016b\\toolbox\\images\\images\\+images\\+internal\\+coder\\intermediateLabelRuns.m"/* pathName */
};

static emlrtRSInfo vf_emlrtRSI = { 149,/* lineNo */
  "intermediateLabelRuns",             /* fcnName */
  "C:\\Program Files\\MATLAB\\R2016b\\toolbox\\images\\images\\+images\\+internal\\+coder\\intermediateLabelRuns.m"/* pathName */
};

static emlrtRSInfo wf_emlrtRSI = { 150,/* lineNo */
  "intermediateLabelRuns",             /* fcnName */
  "C:\\Program Files\\MATLAB\\R2016b\\toolbox\\images\\images\\+images\\+internal\\+coder\\intermediateLabelRuns.m"/* pathName */
};

static emlrtRSInfo xf_emlrtRSI = { 152,/* lineNo */
  "intermediateLabelRuns",             /* fcnName */
  "C:\\Program Files\\MATLAB\\R2016b\\toolbox\\images\\images\\+images\\+internal\\+coder\\intermediateLabelRuns.m"/* pathName */
};

static emlrtRTEInfo ob_emlrtRTEI = { 1,/* lineNo */
  15,                                  /* colNo */
  "bwconncomp",                        /* fName */
  "C:\\Program Files\\MATLAB\\R2016b\\toolbox\\images\\images\\eml\\bwconncomp.m"/* pName */
};

static emlrtRTEInfo pb_emlrtRTEI = { 25,/* lineNo */
  1,                                   /* colNo */
  "bwconncomp",                        /* fName */
  "C:\\Program Files\\MATLAB\\R2016b\\toolbox\\images\\images\\eml\\bwconncomp.m"/* pName */
};

static emlrtRTEInfo qb_emlrtRTEI = { 41,/* lineNo */
  1,                                   /* colNo */
  "bwconncomp",                        /* fName */
  "C:\\Program Files\\MATLAB\\R2016b\\toolbox\\images\\images\\eml\\bwconncomp.m"/* pName */
};

static emlrtRTEInfo rb_emlrtRTEI = { 55,/* lineNo */
  1,                                   /* colNo */
  "bwconncomp",                        /* fName */
  "C:\\Program Files\\MATLAB\\R2016b\\toolbox\\images\\images\\eml\\bwconncomp.m"/* pName */
};

static emlrtRTEInfo sb_emlrtRTEI = { 56,/* lineNo */
  1,                                   /* colNo */
  "bwconncomp",                        /* fName */
  "C:\\Program Files\\MATLAB\\R2016b\\toolbox\\images\\images\\eml\\bwconncomp.m"/* pName */
};

static emlrtBCInfo md_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  66,                                  /* lineNo */
  54,                                  /* colNo */
  "",                                  /* aName */
  "bwconncomp",                        /* fName */
  "C:\\Program Files\\MATLAB\\R2016b\\toolbox\\images\\images\\eml\\bwconncomp.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo nd_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  65,                                  /* lineNo */
  34,                                  /* colNo */
  "",                                  /* aName */
  "bwconncomp",                        /* fName */
  "C:\\Program Files\\MATLAB\\R2016b\\toolbox\\images\\images\\eml\\bwconncomp.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo od_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  65,                                  /* lineNo */
  22,                                  /* colNo */
  "",                                  /* aName */
  "bwconncomp",                        /* fName */
  "C:\\Program Files\\MATLAB\\R2016b\\toolbox\\images\\images\\eml\\bwconncomp.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo pd_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  59,                                  /* lineNo */
  73,                                  /* colNo */
  "",                                  /* aName */
  "bwconncomp",                        /* fName */
  "C:\\Program Files\\MATLAB\\R2016b\\toolbox\\images\\images\\eml\\bwconncomp.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo emlrtDCI = { 55,    /* lineNo */
  37,                                  /* colNo */
  "bwconncomp",                        /* fName */
  "C:\\Program Files\\MATLAB\\R2016b\\toolbox\\images\\images\\eml\\bwconncomp.m",/* pName */
  1                                    /* checkKind */
};

static emlrtDCInfo b_emlrtDCI = { 55,  /* lineNo */
  37,                                  /* colNo */
  "bwconncomp",                        /* fName */
  "C:\\Program Files\\MATLAB\\R2016b\\toolbox\\images\\images\\eml\\bwconncomp.m",/* pName */
  4                                    /* checkKind */
};

static emlrtBCInfo qd_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  45,                                  /* lineNo */
  35,                                  /* colNo */
  "",                                  /* aName */
  "bwconncomp",                        /* fName */
  "C:\\Program Files\\MATLAB\\R2016b\\toolbox\\images\\images\\eml\\bwconncomp.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c_emlrtDCI = { 48,  /* lineNo */
  33,                                  /* colNo */
  "intermediateLabelRuns",             /* fName */
  "C:\\Program Files\\MATLAB\\R2016b\\toolbox\\images\\images\\+images\\+internal\\+coder\\intermediateLabelRuns.m",/* pName */
  4                                    /* checkKind */
};

static emlrtBCInfo rd_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  75,                                  /* lineNo */
  9,                                   /* colNo */
  "",                                  /* aName */
  "intermediateLabelRuns",             /* fName */
  "C:\\Program Files\\MATLAB\\R2016b\\toolbox\\images\\images\\+images\\+internal\\+coder\\intermediateLabelRuns.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo sd_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  81,                                  /* lineNo */
  13,                                  /* colNo */
  "",                                  /* aName */
  "intermediateLabelRuns",             /* fName */
  "C:\\Program Files\\MATLAB\\R2016b\\toolbox\\images\\images\\+images\\+internal\\+coder\\intermediateLabelRuns.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo td_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  86,                                  /* lineNo */
  25,                                  /* colNo */
  "",                                  /* aName */
  "intermediateLabelRuns",             /* fName */
  "C:\\Program Files\\MATLAB\\R2016b\\toolbox\\images\\images\\+images\\+internal\\+coder\\intermediateLabelRuns.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo ud_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  80,                                  /* lineNo */
  25,                                  /* colNo */
  "",                                  /* aName */
  "intermediateLabelRuns",             /* fName */
  "C:\\Program Files\\MATLAB\\R2016b\\toolbox\\images\\images\\+images\\+internal\\+coder\\intermediateLabelRuns.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo vd_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  130,                                 /* lineNo */
  9,                                   /* colNo */
  "",                                  /* aName */
  "intermediateLabelRuns",             /* fName */
  "C:\\Program Files\\MATLAB\\R2016b\\toolbox\\images\\images\\+images\\+internal\\+coder\\intermediateLabelRuns.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo wd_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  134,                                 /* lineNo */
  9,                                   /* colNo */
  "",                                  /* aName */
  "intermediateLabelRuns",             /* fName */
  "C:\\Program Files\\MATLAB\\R2016b\\toolbox\\images\\images\\+images\\+internal\\+coder\\intermediateLabelRuns.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo xd_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  95,                                  /* lineNo */
  18,                                  /* colNo */
  "",                                  /* aName */
  "intermediateLabelRuns",             /* fName */
  "C:\\Program Files\\MATLAB\\R2016b\\toolbox\\images\\images\\+images\\+internal\\+coder\\intermediateLabelRuns.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo yd_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  95,                                  /* lineNo */
  32,                                  /* colNo */
  "",                                  /* aName */
  "intermediateLabelRuns",             /* fName */
  "C:\\Program Files\\MATLAB\\R2016b\\toolbox\\images\\images\\+images\\+internal\\+coder\\intermediateLabelRuns.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo ae_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  95,                                  /* lineNo */
  57,                                  /* colNo */
  "",                                  /* aName */
  "intermediateLabelRuns",             /* fName */
  "C:\\Program Files\\MATLAB\\R2016b\\toolbox\\images\\images\\+images\\+internal\\+coder\\intermediateLabelRuns.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo be_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  95,                                  /* lineNo */
  73,                                  /* colNo */
  "",                                  /* aName */
  "intermediateLabelRuns",             /* fName */
  "C:\\Program Files\\MATLAB\\R2016b\\toolbox\\images\\images\\+images\\+internal\\+coder\\intermediateLabelRuns.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo ce_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  99,                                  /* lineNo */
  21,                                  /* colNo */
  "",                                  /* aName */
  "intermediateLabelRuns",             /* fName */
  "C:\\Program Files\\MATLAB\\R2016b\\toolbox\\images\\images\\+images\\+internal\\+coder\\intermediateLabelRuns.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo de_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  108,                                 /* lineNo */
  25,                                  /* colNo */
  "",                                  /* aName */
  "intermediateLabelRuns",             /* fName */
  "C:\\Program Files\\MATLAB\\R2016b\\toolbox\\images\\images\\+images\\+internal\\+coder\\intermediateLabelRuns.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo ee_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  108,                                 /* lineNo */
  47,                                  /* colNo */
  "",                                  /* aName */
  "intermediateLabelRuns",             /* fName */
  "C:\\Program Files\\MATLAB\\R2016b\\toolbox\\images\\images\\+images\\+internal\\+coder\\intermediateLabelRuns.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo fe_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  179,                                 /* lineNo */
  10,                                  /* colNo */
  "",                                  /* aName */
  "intermediateLabelRuns",             /* fName */
  "C:\\Program Files\\MATLAB\\R2016b\\toolbox\\images\\images\\+images\\+internal\\+coder\\intermediateLabelRuns.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo ge_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  180,                                 /* lineNo */
  17,                                  /* colNo */
  "",                                  /* aName */
  "intermediateLabelRuns",             /* fName */
  "C:\\Program Files\\MATLAB\\R2016b\\toolbox\\images\\images\\+images\\+internal\\+coder\\intermediateLabelRuns.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo he_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  180,                                 /* lineNo */
  24,                                  /* colNo */
  "",                                  /* aName */
  "intermediateLabelRuns",             /* fName */
  "C:\\Program Files\\MATLAB\\R2016b\\toolbox\\images\\images\\+images\\+internal\\+coder\\intermediateLabelRuns.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo ie_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  180,                                 /* lineNo */
  5,                                   /* colNo */
  "",                                  /* aName */
  "intermediateLabelRuns",             /* fName */
  "C:\\Program Files\\MATLAB\\R2016b\\toolbox\\images\\images\\+images\\+internal\\+coder\\intermediateLabelRuns.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo je_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  181,                                 /* lineNo */
  16,                                  /* colNo */
  "",                                  /* aName */
  "intermediateLabelRuns",             /* fName */
  "C:\\Program Files\\MATLAB\\R2016b\\toolbox\\images\\images\\+images\\+internal\\+coder\\intermediateLabelRuns.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo ke_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  168,                                 /* lineNo */
  5,                                   /* colNo */
  "",                                  /* aName */
  "intermediateLabelRuns",             /* fName */
  "C:\\Program Files\\MATLAB\\R2016b\\toolbox\\images\\images\\+images\\+internal\\+coder\\intermediateLabelRuns.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo le_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  169,                                 /* lineNo */
  5,                                   /* colNo */
  "",                                  /* aName */
  "intermediateLabelRuns",             /* fName */
  "C:\\Program Files\\MATLAB\\R2016b\\toolbox\\images\\images\\+images\\+internal\\+coder\\intermediateLabelRuns.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo me_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  165,                                 /* lineNo */
  5,                                   /* colNo */
  "",                                  /* aName */
  "intermediateLabelRuns",             /* fName */
  "C:\\Program Files\\MATLAB\\R2016b\\toolbox\\images\\images\\+images\\+internal\\+coder\\intermediateLabelRuns.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo ne_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  166,                                 /* lineNo */
  5,                                   /* colNo */
  "",                                  /* aName */
  "intermediateLabelRuns",             /* fName */
  "C:\\Program Files\\MATLAB\\R2016b\\toolbox\\images\\images\\+images\\+internal\\+coder\\intermediateLabelRuns.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo oe_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  103,                                 /* lineNo */
  42,                                  /* colNo */
  "",                                  /* aName */
  "intermediateLabelRuns",             /* fName */
  "C:\\Program Files\\MATLAB\\R2016b\\toolbox\\images\\images\\+images\\+internal\\+coder\\intermediateLabelRuns.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo pe_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  103,                                 /* lineNo */
  21,                                  /* colNo */
  "",                                  /* aName */
  "intermediateLabelRuns",             /* fName */
  "C:\\Program Files\\MATLAB\\R2016b\\toolbox\\images\\images\\+images\\+internal\\+coder\\intermediateLabelRuns.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo qe_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  236,                                 /* lineNo */
  13,                                  /* colNo */
  "",                                  /* aName */
  "intermediateLabelRuns",             /* fName */
  "C:\\Program Files\\MATLAB\\R2016b\\toolbox\\images\\images\\+images\\+internal\\+coder\\intermediateLabelRuns.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo re_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  237,                                 /* lineNo */
  13,                                  /* colNo */
  "",                                  /* aName */
  "intermediateLabelRuns",             /* fName */
  "C:\\Program Files\\MATLAB\\R2016b\\toolbox\\images\\images\\+images\\+internal\\+coder\\intermediateLabelRuns.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo se_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  241,                                 /* lineNo */
  13,                                  /* colNo */
  "",                                  /* aName */
  "intermediateLabelRuns",             /* fName */
  "C:\\Program Files\\MATLAB\\R2016b\\toolbox\\images\\images\\+images\\+internal\\+coder\\intermediateLabelRuns.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo d_emlrtDCI = { 41,  /* lineNo */
  23,                                  /* colNo */
  "bwconncomp",                        /* fName */
  "C:\\Program Files\\MATLAB\\R2016b\\toolbox\\images\\images\\eml\\bwconncomp.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo te_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  62,                                  /* lineNo */
  35,                                  /* colNo */
  "",                                  /* aName */
  "bwconncomp",                        /* fName */
  "C:\\Program Files\\MATLAB\\R2016b\\toolbox\\images\\images\\eml\\bwconncomp.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo ue_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  66,                                  /* lineNo */
  13,                                  /* colNo */
  "",                                  /* aName */
  "bwconncomp",                        /* fName */
  "C:\\Program Files\\MATLAB\\R2016b\\toolbox\\images\\images\\eml\\bwconncomp.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo ve_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  67,                                  /* lineNo */
  26,                                  /* colNo */
  "",                                  /* aName */
  "bwconncomp",                        /* fName */
  "C:\\Program Files\\MATLAB\\R2016b\\toolbox\\images\\images\\eml\\bwconncomp.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo we_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  48,                                  /* lineNo */
  46,                                  /* colNo */
  "",                                  /* aName */
  "bwconncomp",                        /* fName */
  "C:\\Program Files\\MATLAB\\R2016b\\toolbox\\images\\images\\eml\\bwconncomp.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo xe_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  48,                                  /* lineNo */
  55,                                  /* colNo */
  "",                                  /* aName */
  "bwconncomp",                        /* fName */
  "C:\\Program Files\\MATLAB\\R2016b\\toolbox\\images\\images\\eml\\bwconncomp.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo ye_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  48,                                  /* lineNo */
  67,                                  /* colNo */
  "",                                  /* aName */
  "bwconncomp",                        /* fName */
  "C:\\Program Files\\MATLAB\\R2016b\\toolbox\\images\\images\\eml\\bwconncomp.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo af_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  48,                                  /* lineNo */
  23,                                  /* colNo */
  "",                                  /* aName */
  "bwconncomp",                        /* fName */
  "C:\\Program Files\\MATLAB\\R2016b\\toolbox\\images\\images\\eml\\bwconncomp.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo bf_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  32,                                  /* lineNo */
  9,                                   /* colNo */
  "",                                  /* aName */
  "bwconncomp",                        /* fName */
  "C:\\Program Files\\MATLAB\\R2016b\\toolbox\\images\\images\\eml\\bwconncomp.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo cf_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  34,                                  /* lineNo */
  9,                                   /* colNo */
  "",                                  /* aName */
  "bwconncomp",                        /* fName */
  "C:\\Program Files\\MATLAB\\R2016b\\toolbox\\images\\images\\eml\\bwconncomp.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo df_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  38,                                  /* lineNo */
  27,                                  /* colNo */
  "",                                  /* aName */
  "bwconncomp",                        /* fName */
  "C:\\Program Files\\MATLAB\\R2016b\\toolbox\\images\\images\\eml\\bwconncomp.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo ef_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  38,                                  /* lineNo */
  44,                                  /* colNo */
  "",                                  /* aName */
  "bwconncomp",                        /* fName */
  "C:\\Program Files\\MATLAB\\R2016b\\toolbox\\images\\images\\eml\\bwconncomp.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo ff_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  38,                                  /* lineNo */
  5,                                   /* colNo */
  "",                                  /* aName */
  "bwconncomp",                        /* fName */
  "C:\\Program Files\\MATLAB\\R2016b\\toolbox\\images\\images\\eml\\bwconncomp.m",/* pName */
  0                                    /* checkKind */
};

/* Function Definitions */
void bwconncomp(const emlrtStack *sp, const boolean_T varargin_1[307200], real_T
                *CC_Connectivity, real_T CC_ImageSize[2], real_T *CC_NumObjects,
                emxArray_real_T *CC_RegionIndices, emxArray_int32_T
                *CC_RegionLengths)
{
  int32_T numRuns;
  int32_T nextLabel;
  int32_T firstRunOnPreviousColumn;
  emxArray_int32_T *regionLengths;
  emxArray_int32_T *startRow;
  emxArray_int32_T *endRow;
  int32_T k;
  emxArray_int32_T *startCol;
  int32_T i23;
  int32_T runCounter;
  emxArray_int32_T *labelsRenumbered;
  int32_T currentColumn;
  real_T numComponents;
  int32_T lastRunOnPreviousColumn;
  int32_T firstRunOnThisColumn;
  int32_T i24;
  int32_T p;
  real_T y;
  boolean_T overflow;
  emxArray_real_T *pixelIdxList;
  emxArray_int32_T *x;
  int32_T parent_k;
  emxArray_int32_T *idxCount;
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  e_st.prev = &d_st;
  e_st.tls = d_st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b(sp);
  st.site = &lf_emlrtRSI;
  b_st.site = &sf_emlrtRSI;
  numRuns = 0;
  for (nextLabel = 0; nextLabel < 640; nextLabel++) {
    firstRunOnPreviousColumn = nextLabel * 480;
    if (varargin_1[firstRunOnPreviousColumn]) {
      numRuns++;
    }

    for (k = 0; k < 479; k++) {
      runCounter = (firstRunOnPreviousColumn + k) + 2;
      if (varargin_1[runCounter - 1] && (!varargin_1[runCounter - 2])) {
        numRuns++;
      }
    }
  }

  emxInit_int32_T(&st, &regionLengths, 1, &qb_emlrtRTEI, true);
  emxInit_int32_T(&st, &startRow, 1, &ob_emlrtRTEI, true);
  emxInit_int32_T(&st, &endRow, 1, &ob_emlrtRTEI, true);
  emxInit_int32_T(&st, &startCol, 1, &ob_emlrtRTEI, true);
  if (numRuns == 0) {
    i23 = startRow->size[0];
    startRow->size[0] = 0;
    emxEnsureCapacity(&st, (emxArray__common *)startRow, i23, (int32_T)sizeof
                      (int32_T), &ob_emlrtRTEI);
    i23 = endRow->size[0];
    endRow->size[0] = 0;
    emxEnsureCapacity(&st, (emxArray__common *)endRow, i23, (int32_T)sizeof
                      (int32_T), &ob_emlrtRTEI);
    i23 = startCol->size[0];
    startCol->size[0] = 0;
    emxEnsureCapacity(&st, (emxArray__common *)startCol, i23, (int32_T)sizeof
                      (int32_T), &ob_emlrtRTEI);
    i23 = regionLengths->size[0];
    regionLengths->size[0] = 0;
    emxEnsureCapacity(&st, (emxArray__common *)regionLengths, i23, (int32_T)
                      sizeof(int32_T), &ob_emlrtRTEI);
  } else {
    i23 = startRow->size[0];
    if (!(numRuns >= 0)) {
      emlrtNonNegativeCheckR2012b(numRuns, &c_emlrtDCI, &st);
    }

    startRow->size[0] = numRuns;
    emxEnsureCapacity(&st, (emxArray__common *)startRow, i23, (int32_T)sizeof
                      (int32_T), &ob_emlrtRTEI);
    i23 = endRow->size[0];
    endRow->size[0] = numRuns;
    emxEnsureCapacity(&st, (emxArray__common *)endRow, i23, (int32_T)sizeof
                      (int32_T), &ob_emlrtRTEI);
    i23 = startCol->size[0];
    startCol->size[0] = numRuns;
    emxEnsureCapacity(&st, (emxArray__common *)startCol, i23, (int32_T)sizeof
                      (int32_T), &ob_emlrtRTEI);
    b_st.site = &tf_emlrtRSI;
    runCounter = 1;
    for (nextLabel = 0; nextLabel < 640; nextLabel++) {
      firstRunOnPreviousColumn = nextLabel * 480 - 1;
      currentColumn = 1;
      while (currentColumn <= 480) {
        while ((currentColumn <= 480) && (!varargin_1[currentColumn +
                firstRunOnPreviousColumn])) {
          currentColumn++;
        }

        if ((currentColumn <= 480) && varargin_1[currentColumn +
            firstRunOnPreviousColumn]) {
          i23 = startCol->size[0];
          if (!((runCounter >= 1) && (runCounter <= i23))) {
            emlrtDynamicBoundsCheckR2012b(runCounter, 1, i23, &qe_emlrtBCI,
              &b_st);
          }

          startCol->data[runCounter - 1] = nextLabel + 1;
          i23 = startRow->size[0];
          if (!((runCounter >= 1) && (runCounter <= i23))) {
            emlrtDynamicBoundsCheckR2012b(runCounter, 1, i23, &re_emlrtBCI,
              &b_st);
          }

          startRow->data[runCounter - 1] = currentColumn;
          while ((currentColumn <= 480) && varargin_1[currentColumn +
                 firstRunOnPreviousColumn]) {
            currentColumn++;
          }

          i23 = endRow->size[0];
          if (!((runCounter >= 1) && (runCounter <= i23))) {
            emlrtDynamicBoundsCheckR2012b(runCounter, 1, i23, &se_emlrtBCI,
              &b_st);
          }

          endRow->data[runCounter - 1] = currentColumn - 1;
          runCounter++;
        }
      }
    }

    i23 = regionLengths->size[0];
    regionLengths->size[0] = numRuns;
    emxEnsureCapacity(&st, (emxArray__common *)regionLengths, i23, (int32_T)
                      sizeof(int32_T), &ob_emlrtRTEI);
    for (i23 = 0; i23 < numRuns; i23++) {
      regionLengths->data[i23] = 0;
    }

    k = 1;
    currentColumn = 1;
    nextLabel = 1;
    firstRunOnPreviousColumn = -1;
    lastRunOnPreviousColumn = -1;
    firstRunOnThisColumn = 1;
    while (k <= numRuns) {
      i23 = startCol->size[0];
      if (!((k >= 1) && (k <= i23))) {
        emlrtDynamicBoundsCheckR2012b(k, 1, i23, &rd_emlrtBCI, &st);
      }

      if (startCol->data[k - 1] == currentColumn + 1) {
        firstRunOnPreviousColumn = firstRunOnThisColumn;
        firstRunOnThisColumn = k;
        lastRunOnPreviousColumn = k - 1;
        i23 = startCol->size[0];
        if (!((k >= 1) && (k <= i23))) {
          emlrtDynamicBoundsCheckR2012b(k, 1, i23, &ud_emlrtBCI, &st);
        }

        currentColumn = startCol->data[k - 1];
      } else {
        i23 = startCol->size[0];
        if (!((k >= 1) && (k <= i23))) {
          emlrtDynamicBoundsCheckR2012b(k, 1, i23, &sd_emlrtBCI, &st);
        }

        if (startCol->data[k - 1] > currentColumn + 1) {
          firstRunOnPreviousColumn = -1;
          lastRunOnPreviousColumn = -1;
          firstRunOnThisColumn = k;
          i23 = startCol->size[0];
          if (!((k >= 1) && (k <= i23))) {
            emlrtDynamicBoundsCheckR2012b(k, 1, i23, &td_emlrtBCI, &st);
          }

          currentColumn = startCol->data[k - 1];
        }
      }

      if (firstRunOnPreviousColumn >= 0) {
        for (p = firstRunOnPreviousColumn; p <= lastRunOnPreviousColumn; p++) {
          i23 = endRow->size[0];
          if (!((k >= 1) && (k <= i23))) {
            emlrtDynamicBoundsCheckR2012b(k, 1, i23, &xd_emlrtBCI, &st);
          }

          i23 = startRow->size[0];
          if (!((p >= 1) && (p <= i23))) {
            emlrtDynamicBoundsCheckR2012b(p, 1, i23, &yd_emlrtBCI, &st);
          }

          if (endRow->data[k - 1] >= startRow->data[p - 1] - 1) {
            i23 = startRow->size[0];
            if (!((k >= 1) && (k <= i23))) {
              emlrtDynamicBoundsCheckR2012b(k, 1, i23, &ae_emlrtBCI, &st);
            }

            i23 = endRow->size[0];
            if (!((p >= 1) && (p <= i23))) {
              emlrtDynamicBoundsCheckR2012b(p, 1, i23, &be_emlrtBCI, &st);
            }

            if (startRow->data[k - 1] <= endRow->data[p - 1] + 1) {
              i23 = regionLengths->size[0];
              if (!((k >= 1) && (k <= i23))) {
                emlrtDynamicBoundsCheckR2012b(k, 1, i23, &ce_emlrtBCI, &st);
              }

              if (regionLengths->data[k - 1] == 0) {
                i23 = regionLengths->size[0];
                if (!((p >= 1) && (p <= i23))) {
                  emlrtDynamicBoundsCheckR2012b(p, 1, i23, &oe_emlrtBCI, &st);
                }

                i23 = regionLengths->size[0];
                if (!((k >= 1) && (k <= i23))) {
                  emlrtDynamicBoundsCheckR2012b(k, 1, i23, &pe_emlrtBCI, &st);
                }

                regionLengths->data[k - 1] = regionLengths->data[p - 1];
                nextLabel++;
              } else {
                i23 = regionLengths->size[0];
                if (!((k >= 1) && (k <= i23))) {
                  emlrtDynamicBoundsCheckR2012b(k, 1, i23, &de_emlrtBCI, &st);
                }

                i23 = regionLengths->size[0];
                if (!((p >= 1) && (p <= i23))) {
                  emlrtDynamicBoundsCheckR2012b(p, 1, i23, &ee_emlrtBCI, &st);
                }

                if (regionLengths->data[k - 1] != regionLengths->data[p - 1]) {
                  b_st.site = &uf_emlrtRSI;
                  c_st.site = &vf_emlrtRSI;
                  i23 = regionLengths->size[0];
                  if (!((k >= 1) && (k <= i23))) {
                    emlrtDynamicBoundsCheckR2012b(k, 1, i23, &fe_emlrtBCI, &c_st);
                  }

                  if (k != regionLengths->data[k - 1]) {
                    i23 = regionLengths->size[0];
                    i24 = regionLengths->size[0];
                    if (!((k >= 1) && (k <= i24))) {
                      emlrtDynamicBoundsCheckR2012b(k, 1, i24, &he_emlrtBCI,
                        &c_st);
                    }

                    i24 = regionLengths->data[k - 1];
                    if (!((i24 >= 1) && (i24 <= i23))) {
                      emlrtDynamicBoundsCheckR2012b(i24, 1, i23, &ge_emlrtBCI,
                        &c_st);
                    }

                    i23 = regionLengths->size[0];
                    if (!((k >= 1) && (k <= i23))) {
                      emlrtDynamicBoundsCheckR2012b(k, 1, i23, &ie_emlrtBCI,
                        &c_st);
                    }

                    regionLengths->data[k - 1] = regionLengths->data[i24 - 1];
                    i23 = regionLengths->size[0];
                    if (!((k >= 1) && (k <= i23))) {
                      emlrtDynamicBoundsCheckR2012b(k, 1, i23, &je_emlrtBCI,
                        &c_st);
                    }

                    parent_k = regionLengths->data[k - 1];
                  } else {
                    parent_k = k;
                  }

                  c_st.site = &wf_emlrtRSI;
                  i23 = regionLengths->size[0];
                  if (!((p >= 1) && (p <= i23))) {
                    emlrtDynamicBoundsCheckR2012b(p, 1, i23, &fe_emlrtBCI, &c_st);
                  }

                  if (p != regionLengths->data[p - 1]) {
                    i23 = regionLengths->size[0];
                    i24 = regionLengths->size[0];
                    if (!((p >= 1) && (p <= i24))) {
                      emlrtDynamicBoundsCheckR2012b(p, 1, i24, &he_emlrtBCI,
                        &c_st);
                    }

                    i24 = regionLengths->data[p - 1];
                    if (!((i24 >= 1) && (i24 <= i23))) {
                      emlrtDynamicBoundsCheckR2012b(i24, 1, i23, &ge_emlrtBCI,
                        &c_st);
                    }

                    i23 = regionLengths->size[0];
                    if (!((p >= 1) && (p <= i23))) {
                      emlrtDynamicBoundsCheckR2012b(p, 1, i23, &ie_emlrtBCI,
                        &c_st);
                    }

                    regionLengths->data[p - 1] = regionLengths->data[i24 - 1];
                    i23 = regionLengths->size[0];
                    if (!((p >= 1) && (p <= i23))) {
                      emlrtDynamicBoundsCheckR2012b(p, 1, i23, &je_emlrtBCI,
                        &c_st);
                    }

                    runCounter = regionLengths->data[p - 1];
                  } else {
                    runCounter = p;
                  }

                  if (parent_k != runCounter) {
                    c_st.site = &xf_emlrtRSI;
                    if (runCounter < parent_k) {
                      i23 = regionLengths->size[0];
                      if (!((parent_k >= 1) && (parent_k <= i23))) {
                        emlrtDynamicBoundsCheckR2012b(parent_k, 1, i23,
                          &me_emlrtBCI, &c_st);
                      }

                      regionLengths->data[parent_k - 1] = runCounter;
                      i23 = regionLengths->size[0];
                      if (!((k >= 1) && (k <= i23))) {
                        emlrtDynamicBoundsCheckR2012b(k, 1, i23, &ne_emlrtBCI,
                          &c_st);
                      }

                      regionLengths->data[k - 1] = runCounter;
                    } else {
                      i23 = regionLengths->size[0];
                      if (!((runCounter >= 1) && (runCounter <= i23))) {
                        emlrtDynamicBoundsCheckR2012b(runCounter, 1, i23,
                          &ke_emlrtBCI, &c_st);
                      }

                      regionLengths->data[runCounter - 1] = parent_k;
                      i23 = regionLengths->size[0];
                      if (!((p >= 1) && (p <= i23))) {
                        emlrtDynamicBoundsCheckR2012b(p, 1, i23, &le_emlrtBCI,
                          &c_st);
                      }

                      regionLengths->data[p - 1] = parent_k;
                    }
                  }
                }
              }
            }
          }
        }
      }

      i23 = regionLengths->size[0];
      if (!((k >= 1) && (k <= i23))) {
        emlrtDynamicBoundsCheckR2012b(k, 1, i23, &vd_emlrtBCI, &st);
      }

      if (regionLengths->data[k - 1] == 0) {
        i23 = regionLengths->size[0];
        if (!((k >= 1) && (k <= i23))) {
          emlrtDynamicBoundsCheckR2012b(k, 1, i23, &wd_emlrtBCI, &st);
        }

        regionLengths->data[k - 1] = nextLabel;
        nextLabel++;
      }

      k++;
    }
  }

  if (numRuns == 0) {
    *CC_Connectivity = 8.0;
    for (i23 = 0; i23 < 2; i23++) {
      CC_ImageSize[i23] = 480.0 + 160.0 * (real_T)i23;
    }

    *CC_NumObjects = 0.0;
    i23 = CC_RegionIndices->size[0];
    CC_RegionIndices->size[0] = 0;
    emxEnsureCapacity(sp, (emxArray__common *)CC_RegionIndices, i23, (int32_T)
                      sizeof(real_T), &ob_emlrtRTEI);
    i23 = CC_RegionLengths->size[0];
    CC_RegionLengths->size[0] = 1;
    emxEnsureCapacity(sp, (emxArray__common *)CC_RegionLengths, i23, (int32_T)
                      sizeof(int32_T), &ob_emlrtRTEI);
    CC_RegionLengths->data[0] = 0;
  } else {
    emxInit_int32_T(sp, &labelsRenumbered, 1, &pb_emlrtRTEI, true);
    i23 = labelsRenumbered->size[0];
    labelsRenumbered->size[0] = regionLengths->size[0];
    emxEnsureCapacity(sp, (emxArray__common *)labelsRenumbered, i23, (int32_T)
                      sizeof(int32_T), &ob_emlrtRTEI);
    numComponents = 0.0;
    st.site = &mf_emlrtRSI;
    for (k = 1; k <= numRuns; k++) {
      i23 = regionLengths->size[0];
      if (!(k <= i23)) {
        emlrtDynamicBoundsCheckR2012b(k, 1, i23, &bf_emlrtBCI, sp);
      }

      if (regionLengths->data[k - 1] == k) {
        numComponents++;
        i23 = labelsRenumbered->size[0];
        if (!(k <= i23)) {
          emlrtDynamicBoundsCheckR2012b(k, 1, i23, &cf_emlrtBCI, sp);
        }

        labelsRenumbered->data[k - 1] = (int32_T)numComponents;
      }

      i23 = labelsRenumbered->size[0];
      i24 = regionLengths->size[0];
      if (!(k <= i24)) {
        emlrtDynamicBoundsCheckR2012b(k, 1, i24, &ef_emlrtBCI, sp);
      }

      i24 = regionLengths->data[k - 1];
      if (!((i24 >= 1) && (i24 <= i23))) {
        emlrtDynamicBoundsCheckR2012b(i24, 1, i23, &df_emlrtBCI, sp);
      }

      i23 = labelsRenumbered->size[0];
      if (!(k <= i23)) {
        emlrtDynamicBoundsCheckR2012b(k, 1, i23, &ff_emlrtBCI, sp);
      }

      labelsRenumbered->data[k - 1] = labelsRenumbered->data[i24 - 1];
    }

    i23 = regionLengths->size[0];
    if (numComponents != (int32_T)numComponents) {
      emlrtIntegerCheckR2012b(numComponents, &d_emlrtDCI, sp);
    }

    regionLengths->size[0] = (int32_T)numComponents;
    emxEnsureCapacity(sp, (emxArray__common *)regionLengths, i23, (int32_T)
                      sizeof(int32_T), &ob_emlrtRTEI);
    if (numComponents != (int32_T)numComponents) {
      emlrtIntegerCheckR2012b(numComponents, &d_emlrtDCI, sp);
    }

    runCounter = (int32_T)numComponents;
    for (i23 = 0; i23 < runCounter; i23++) {
      regionLengths->data[i23] = 0;
    }

    st.site = &nf_emlrtRSI;
    for (k = 1; k <= numRuns; k++) {
      i23 = labelsRenumbered->size[0];
      if (!(k <= i23)) {
        emlrtDynamicBoundsCheckR2012b(k, 1, i23, &qd_emlrtBCI, sp);
      }

      if (labelsRenumbered->data[k - 1] > 0) {
        i23 = regionLengths->size[0];
        i24 = labelsRenumbered->data[k - 1];
        if (!((i24 >= 1) && (i24 <= i23))) {
          emlrtDynamicBoundsCheckR2012b(i24, 1, i23, &we_emlrtBCI, sp);
        }

        i23 = endRow->size[0];
        if (!(k <= i23)) {
          emlrtDynamicBoundsCheckR2012b(k, 1, i23, &xe_emlrtBCI, sp);
        }

        i23 = startRow->size[0];
        if (!(k <= i23)) {
          emlrtDynamicBoundsCheckR2012b(k, 1, i23, &ye_emlrtBCI, sp);
        }

        i23 = regionLengths->size[0];
        runCounter = labelsRenumbered->data[k - 1];
        if (!((runCounter >= 1) && (runCounter <= i23))) {
          emlrtDynamicBoundsCheckR2012b(runCounter, 1, i23, &af_emlrtBCI, sp);
        }

        regionLengths->data[runCounter - 1] = ((regionLengths->data[i24 - 1] +
          endRow->data[k - 1]) - startRow->data[k - 1]) + 1;
      }
    }

    st.site = &of_emlrtRSI;
    b_st.site = &yf_emlrtRSI;
    c_st.site = &ag_emlrtRSI;
    if (regionLengths->size[0] == 0) {
      y = 0.0;
    } else {
      y = regionLengths->data[0];
      d_st.site = &bg_emlrtRSI;
      overflow = ((!(2 > regionLengths->size[0])) && (regionLengths->size[0] >
        2147483646));
      if (overflow) {
        e_st.site = &w_emlrtRSI;
        check_forloop_overflow_error(&e_st);
      }

      for (k = 2; k <= regionLengths->size[0]; k++) {
        y += (real_T)regionLengths->data[k - 1];
      }
    }

    emxInit_real_T(&c_st, &pixelIdxList, 1, &rb_emlrtRTEI, true);
    if (!(y >= 0.0)) {
      emlrtNonNegativeCheckR2012b(y, &b_emlrtDCI, sp);
    }

    if (y != (int32_T)y) {
      emlrtIntegerCheckR2012b(y, &emlrtDCI, sp);
    }

    i23 = pixelIdxList->size[0];
    pixelIdxList->size[0] = (int32_T)y;
    emxEnsureCapacity(sp, (emxArray__common *)pixelIdxList, i23, (int32_T)sizeof
                      (real_T), &ob_emlrtRTEI);
    st.site = &pf_emlrtRSI;
    b_st.site = &cg_emlrtRSI;
    currentColumn = 2;
    if (regionLengths->size[0] != 1) {
      currentColumn = 1;
    }

    emxInit_int32_T(&b_st, &x, 1, &ob_emlrtRTEI, true);
    c_st.site = &dg_emlrtRSI;
    i23 = x->size[0];
    x->size[0] = regionLengths->size[0];
    emxEnsureCapacity(&c_st, (emxArray__common *)x, i23, (int32_T)sizeof(int32_T),
                      &ob_emlrtRTEI);
    runCounter = regionLengths->size[0];
    for (i23 = 0; i23 < runCounter; i23++) {
      x->data[i23] = regionLengths->data[i23];
    }

    if (currentColumn <= 1) {
      i23 = regionLengths->size[0];
    } else {
      i23 = 1;
    }

    if ((!(regionLengths->size[0] == 0)) && (i23 > 1)) {
      d_st.site = &eg_emlrtRSI;
      nextLabel = 1;
      k = 1;
      while (k <= currentColumn - 1) {
        nextLabel *= regionLengths->size[0];
        k = 2;
      }

      d_st.site = &fg_emlrtRSI;
      if ((!(1 > nextLabel)) && (nextLabel > 2147483646)) {
        e_st.site = &w_emlrtRSI;
        check_forloop_overflow_error(&e_st);
      }

      for (runCounter = 0; runCounter + 1 <= nextLabel; runCounter++) {
        d_st.site = &gg_emlrtRSI;
        for (k = 1; k < i23; k++) {
          x->data[runCounter + k * nextLabel] += x->data[runCounter + (k - 1) *
            nextLabel];
        }
      }
    }

    emxInit_int32_T(&c_st, &idxCount, 1, &sb_emlrtRTEI, true);
    i23 = idxCount->size[0];
    idxCount->size[0] = 1 + x->size[0];
    emxEnsureCapacity(sp, (emxArray__common *)idxCount, i23, (int32_T)sizeof
                      (int32_T), &ob_emlrtRTEI);
    idxCount->data[0] = 0;
    runCounter = x->size[0];
    for (i23 = 0; i23 < runCounter; i23++) {
      idxCount->data[i23 + 1] = x->data[i23];
    }

    emxFree_int32_T(&x);
    st.site = &qf_emlrtRSI;
    for (k = 1; k <= numRuns; k++) {
      i23 = startCol->size[0];
      if (!(k <= i23)) {
        emlrtDynamicBoundsCheckR2012b(k, 1, i23, &pd_emlrtBCI, sp);
      }

      runCounter = (startCol->data[k - 1] - 1) * 480;
      i23 = labelsRenumbered->size[0];
      if (!(k <= i23)) {
        emlrtDynamicBoundsCheckR2012b(k, 1, i23, &te_emlrtBCI, sp);
      }

      currentColumn = labelsRenumbered->data[k - 1];
      if (labelsRenumbered->data[k - 1] > 0) {
        i23 = startRow->size[0];
        if (!(k <= i23)) {
          emlrtDynamicBoundsCheckR2012b(k, 1, i23, &od_emlrtBCI, sp);
        }

        i23 = endRow->size[0];
        if (!(k <= i23)) {
          emlrtDynamicBoundsCheckR2012b(k, 1, i23, &nd_emlrtBCI, sp);
        }

        st.site = &rf_emlrtRSI;
        for (nextLabel = startRow->data[k - 1]; nextLabel <= endRow->data[k - 1];
             nextLabel++) {
          i23 = idxCount->size[0];
          if (!((currentColumn >= 1) && (currentColumn <= i23))) {
            emlrtDynamicBoundsCheckR2012b(currentColumn, 1, i23, &md_emlrtBCI,
              sp);
          }

          i23 = idxCount->size[0];
          if (!((currentColumn >= 1) && (currentColumn <= i23))) {
            emlrtDynamicBoundsCheckR2012b(currentColumn, 1, i23, &ue_emlrtBCI,
              sp);
          }

          idxCount->data[currentColumn - 1]++;
          i23 = pixelIdxList->size[0];
          i24 = idxCount->size[0];
          if (!((currentColumn >= 1) && (currentColumn <= i24))) {
            emlrtDynamicBoundsCheckR2012b(currentColumn, 1, i24, &ve_emlrtBCI,
              sp);
          }

          i24 = idxCount->data[currentColumn - 1];
          if (!((i24 >= 1) && (i24 <= i23))) {
            emlrtDynamicBoundsCheckR2012b(i24, 1, i23, &ve_emlrtBCI, sp);
          }

          pixelIdxList->data[i24 - 1] = nextLabel + runCounter;
        }
      }
    }

    emxFree_int32_T(&idxCount);
    emxFree_int32_T(&labelsRenumbered);
    *CC_Connectivity = 8.0;
    for (i23 = 0; i23 < 2; i23++) {
      CC_ImageSize[i23] = 480.0 + 160.0 * (real_T)i23;
    }

    *CC_NumObjects = numComponents;
    i23 = CC_RegionIndices->size[0];
    CC_RegionIndices->size[0] = pixelIdxList->size[0];
    emxEnsureCapacity(sp, (emxArray__common *)CC_RegionIndices, i23, (int32_T)
                      sizeof(real_T), &ob_emlrtRTEI);
    runCounter = pixelIdxList->size[0];
    for (i23 = 0; i23 < runCounter; i23++) {
      CC_RegionIndices->data[i23] = pixelIdxList->data[i23];
    }

    emxFree_real_T(&pixelIdxList);
    i23 = CC_RegionLengths->size[0];
    CC_RegionLengths->size[0] = regionLengths->size[0];
    emxEnsureCapacity(sp, (emxArray__common *)CC_RegionLengths, i23, (int32_T)
                      sizeof(int32_T), &ob_emlrtRTEI);
    runCounter = regionLengths->size[0];
    for (i23 = 0; i23 < runCounter; i23++) {
      CC_RegionLengths->data[i23] = regionLengths->data[i23];
    }
  }

  emxFree_int32_T(&startCol);
  emxFree_int32_T(&endRow);
  emxFree_int32_T(&startRow);
  emxFree_int32_T(&regionLengths);
  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

/* End of code generation (bwconncomp.c) */
