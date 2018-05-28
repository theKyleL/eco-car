/*
 * Sponsored License - for use in support of a program or activity
 * sponsored by MathWorks.  Not for government, commercial or other
 * non-sponsored organizational use.
 *
 * chaccum.c
 *
 * Code generation for function 'chaccum'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "FindCircle.h"
#include "chaccum.h"
#include "rgb2gray.h"
#include "FindCircle_emxutil.h"
#include "imfilter.h"
#include "multithresh.h"
#include "sub2ind.h"
#include "find.h"
#include "all.h"
#include "FindCircle_data.h"

/* Variable Definitions */
static emlrtRSInfo f_emlrtRSI = { 24,  /* lineNo */
  "chaccum",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2016b\\toolbox\\images\\images\\eml\\private\\chaccum.m"/* pathName */
};

static emlrtRSInfo g_emlrtRSI = { 28,  /* lineNo */
  "chaccum",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2016b\\toolbox\\images\\images\\eml\\private\\chaccum.m"/* pathName */
};

static emlrtRSInfo h_emlrtRSI = { 31,  /* lineNo */
  "chaccum",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2016b\\toolbox\\images\\images\\eml\\private\\chaccum.m"/* pathName */
};

static emlrtRSInfo i_emlrtRSI = { 32,  /* lineNo */
  "chaccum",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2016b\\toolbox\\images\\images\\eml\\private\\chaccum.m"/* pathName */
};

static emlrtRSInfo j_emlrtRSI = { 76,  /* lineNo */
  "chaccum",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2016b\\toolbox\\images\\images\\eml\\private\\chaccum.m"/* pathName */
};

static emlrtRSInfo k_emlrtRSI = { 136, /* lineNo */
  "chaccum",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2016b\\toolbox\\images\\images\\eml\\private\\chaccum.m"/* pathName */
};

static emlrtRSInfo l_emlrtRSI = { 204, /* lineNo */
  "chaccum",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2016b\\toolbox\\images\\images\\eml\\private\\chaccum.m"/* pathName */
};

static emlrtRSInfo n_emlrtRSI = { 174, /* lineNo */
  "chaccum",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2016b\\toolbox\\images\\images\\eml\\private\\chaccum.m"/* pathName */
};

static emlrtRSInfo o_emlrtRSI = { 175, /* lineNo */
  "chaccum",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2016b\\toolbox\\images\\images\\eml\\private\\chaccum.m"/* pathName */
};

static emlrtRSInfo fb_emlrtRSI = { 190,/* lineNo */
  "chaccum",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2016b\\toolbox\\images\\images\\eml\\private\\chaccum.m"/* pathName */
};

static emlrtRSInfo gb_emlrtRSI = { 195,/* lineNo */
  "chaccum",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2016b\\toolbox\\images\\images\\eml\\private\\chaccum.m"/* pathName */
};

static emlrtRSInfo wd_emlrtRSI = { 25, /* lineNo */
  "colon",                             /* fcnName */
  "C:\\Program Files\\MATLAB\\R2016b\\toolbox\\eml\\lib\\matlab\\ops\\colon.m"/* pathName */
};

static emlrtRSInfo xd_emlrtRSI = { 161,/* lineNo */
  "chaccum",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2016b\\toolbox\\images\\images\\eml\\private\\chaccum.m"/* pathName */
};

static emlrtRTEInfo e_emlrtRTEI = { 1, /* lineNo */
  39,                                  /* colNo */
  "chaccum",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2016b\\toolbox\\images\\images\\eml\\private\\chaccum.m"/* pName */
};

static emlrtRTEInfo f_emlrtRTEI = { 77,/* lineNo */
  5,                                   /* colNo */
  "chaccum",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2016b\\toolbox\\images\\images\\eml\\private\\chaccum.m"/* pName */
};

static emlrtRTEInfo g_emlrtRTEI = { 78,/* lineNo */
  5,                                   /* colNo */
  "chaccum",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2016b\\toolbox\\images\\images\\eml\\private\\chaccum.m"/* pName */
};

static emlrtRTEInfo h_emlrtRTEI = { 79,/* lineNo */
  5,                                   /* colNo */
  "chaccum",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2016b\\toolbox\\images\\images\\eml\\private\\chaccum.m"/* pName */
};

static emlrtRTEInfo i_emlrtRTEI = { 91,/* lineNo */
  5,                                   /* colNo */
  "chaccum",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2016b\\toolbox\\images\\images\\eml\\private\\chaccum.m"/* pName */
};

static emlrtRTEInfo j_emlrtRTEI = { 92,/* lineNo */
  5,                                   /* colNo */
  "chaccum",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2016b\\toolbox\\images\\images\\eml\\private\\chaccum.m"/* pName */
};

static emlrtRTEInfo k_emlrtRTEI = { 94,/* lineNo */
  5,                                   /* colNo */
  "chaccum",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2016b\\toolbox\\images\\images\\eml\\private\\chaccum.m"/* pName */
};

static emlrtRTEInfo l_emlrtRTEI = { 95,/* lineNo */
  5,                                   /* colNo */
  "chaccum",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2016b\\toolbox\\images\\images\\eml\\private\\chaccum.m"/* pName */
};

static emlrtRTEInfo m_emlrtRTEI = { 98,/* lineNo */
  5,                                   /* colNo */
  "chaccum",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2016b\\toolbox\\images\\images\\eml\\private\\chaccum.m"/* pName */
};

static emlrtRTEInfo n_emlrtRTEI = { 120,/* lineNo */
  5,                                   /* colNo */
  "chaccum",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2016b\\toolbox\\images\\images\\eml\\private\\chaccum.m"/* pName */
};

static emlrtRTEInfo o_emlrtRTEI = { 121,/* lineNo */
  5,                                   /* colNo */
  "chaccum",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2016b\\toolbox\\images\\images\\eml\\private\\chaccum.m"/* pName */
};

static emlrtRTEInfo p_emlrtRTEI = { 122,/* lineNo */
  5,                                   /* colNo */
  "chaccum",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2016b\\toolbox\\images\\images\\eml\\private\\chaccum.m"/* pName */
};

static emlrtRTEInfo jc_emlrtRTEI = { 75,/* lineNo */
  9,                                   /* colNo */
  "chaccum",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2016b\\toolbox\\images\\images\\eml\\private\\chaccum.m"/* pName */
};

static emlrtBCInfo f_emlrtBCI = { 1,   /* iFirst */
  307200,                              /* iLast */
  102,                                 /* lineNo */
  74,                                  /* colNo */
  "",                                  /* aName */
  "chaccum",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2016b\\toolbox\\images\\images\\eml\\private\\chaccum.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo g_emlrtBCI = { 1,   /* iFirst */
  307200,                              /* iLast */
  102,                                 /* lineNo */
  95,                                  /* colNo */
  "",                                  /* aName */
  "chaccum",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2016b\\toolbox\\images\\images\\eml\\private\\chaccum.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo h_emlrtBCI = { 1,   /* iFirst */
  307200,                              /* iLast */
  103,                                 /* lineNo */
  74,                                  /* colNo */
  "",                                  /* aName */
  "chaccum",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2016b\\toolbox\\images\\images\\eml\\private\\chaccum.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo i_emlrtBCI = { 1,   /* iFirst */
  307200,                              /* iLast */
  103,                                 /* lineNo */
  95,                                  /* colNo */
  "",                                  /* aName */
  "chaccum",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2016b\\toolbox\\images\\images\\eml\\private\\chaccum.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo j_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  105,                                 /* lineNo */
  38,                                  /* colNo */
  "",                                  /* aName */
  "chaccum",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2016b\\toolbox\\images\\images\\eml\\private\\chaccum.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo k_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  105,                                 /* lineNo */
  61,                                  /* colNo */
  "",                                  /* aName */
  "chaccum",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2016b\\toolbox\\images\\images\\eml\\private\\chaccum.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo l_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  105,                                 /* lineNo */
  84,                                  /* colNo */
  "",                                  /* aName */
  "chaccum",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2016b\\toolbox\\images\\images\\eml\\private\\chaccum.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo m_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  105,                                 /* lineNo */
  107,                                 /* colNo */
  "",                                  /* aName */
  "chaccum",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2016b\\toolbox\\images\\images\\eml\\private\\chaccum.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo n_emlrtBCI = { 1,   /* iFirst */
  480,                                 /* iLast */
  162,                                 /* lineNo */
  32,                                  /* colNo */
  "",                                  /* aName */
  "chaccum",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2016b\\toolbox\\images\\images\\eml\\private\\chaccum.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo o_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  162,                                 /* lineNo */
  32,                                  /* colNo */
  "",                                  /* aName */
  "chaccum",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2016b\\toolbox\\images\\images\\eml\\private\\chaccum.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo p_emlrtBCI = { 1,   /* iFirst */
  640,                                 /* iLast */
  162,                                 /* lineNo */
  40,                                  /* colNo */
  "",                                  /* aName */
  "chaccum",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2016b\\toolbox\\images\\images\\eml\\private\\chaccum.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo q_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  162,                                 /* lineNo */
  40,                                  /* colNo */
  "",                                  /* aName */
  "chaccum",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2016b\\toolbox\\images\\images\\eml\\private\\chaccum.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo r_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  162,                                 /* lineNo */
  51,                                  /* colNo */
  "",                                  /* aName */
  "chaccum",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2016b\\toolbox\\images\\images\\eml\\private\\chaccum.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo s_emlrtBCI = { 1,   /* iFirst */
  480,                                 /* iLast */
  162,                                 /* lineNo */
  9,                                   /* colNo */
  "",                                  /* aName */
  "chaccum",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2016b\\toolbox\\images\\images\\eml\\private\\chaccum.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo t_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  162,                                 /* lineNo */
  9,                                   /* colNo */
  "",                                  /* aName */
  "chaccum",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2016b\\toolbox\\images\\images\\eml\\private\\chaccum.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo u_emlrtBCI = { 1,   /* iFirst */
  640,                                 /* iLast */
  162,                                 /* lineNo */
  17,                                  /* colNo */
  "",                                  /* aName */
  "chaccum",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2016b\\toolbox\\images\\images\\eml\\private\\chaccum.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo v_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  162,                                 /* lineNo */
  17,                                  /* colNo */
  "",                                  /* aName */
  "chaccum",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2016b\\toolbox\\images\\images\\eml\\private\\chaccum.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo w_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  127,                                 /* lineNo */
  16,                                  /* colNo */
  "",                                  /* aName */
  "chaccum",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2016b\\toolbox\\images\\images\\eml\\private\\chaccum.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo x_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  127,                                 /* lineNo */
  45,                                  /* colNo */
  "",                                  /* aName */
  "chaccum",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2016b\\toolbox\\images\\images\\eml\\private\\chaccum.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo y_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  129,                                 /* lineNo */
  64,                                  /* colNo */
  "",                                  /* aName */
  "chaccum",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2016b\\toolbox\\images\\images\\eml\\private\\chaccum.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo ab_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  129,                                 /* lineNo */
  24,                                  /* colNo */
  "",                                  /* aName */
  "chaccum",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2016b\\toolbox\\images\\images\\eml\\private\\chaccum.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo bb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  130,                                 /* lineNo */
  64,                                  /* colNo */
  "",                                  /* aName */
  "chaccum",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2016b\\toolbox\\images\\images\\eml\\private\\chaccum.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo cb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  130,                                 /* lineNo */
  24,                                  /* colNo */
  "",                                  /* aName */
  "chaccum",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2016b\\toolbox\\images\\images\\eml\\private\\chaccum.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo db_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  131,                                 /* lineNo */
  38,                                  /* colNo */
  "",                                  /* aName */
  "chaccum",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2016b\\toolbox\\images\\images\\eml\\private\\chaccum.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo eb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  131,                                 /* lineNo */
  23,                                  /* colNo */
  "",                                  /* aName */
  "chaccum",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2016b\\toolbox\\images\\images\\eml\\private\\chaccum.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo fb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  102,                                 /* lineNo */
  77,                                  /* colNo */
  "",                                  /* aName */
  "chaccum",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2016b\\toolbox\\images\\images\\eml\\private\\chaccum.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo gb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  102,                                 /* lineNo */
  107,                                 /* colNo */
  "",                                  /* aName */
  "chaccum",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2016b\\toolbox\\images\\images\\eml\\private\\chaccum.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo hb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  102,                                 /* lineNo */
  43,                                  /* colNo */
  "",                                  /* aName */
  "chaccum",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2016b\\toolbox\\images\\images\\eml\\private\\chaccum.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo ib_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  102,                                 /* lineNo */
  16,                                  /* colNo */
  "",                                  /* aName */
  "chaccum",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2016b\\toolbox\\images\\images\\eml\\private\\chaccum.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo jb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  103,                                 /* lineNo */
  77,                                  /* colNo */
  "",                                  /* aName */
  "chaccum",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2016b\\toolbox\\images\\images\\eml\\private\\chaccum.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo kb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  103,                                 /* lineNo */
  107,                                 /* colNo */
  "",                                  /* aName */
  "chaccum",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2016b\\toolbox\\images\\images\\eml\\private\\chaccum.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo lb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  103,                                 /* lineNo */
  43,                                  /* colNo */
  "",                                  /* aName */
  "chaccum",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2016b\\toolbox\\images\\images\\eml\\private\\chaccum.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo mb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  103,                                 /* lineNo */
  16,                                  /* colNo */
  "",                                  /* aName */
  "chaccum",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2016b\\toolbox\\images\\images\\eml\\private\\chaccum.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo nb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  104,                                 /* lineNo */
  15,                                  /* colNo */
  "",                                  /* aName */
  "chaccum",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2016b\\toolbox\\images\\images\\eml\\private\\chaccum.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo ob_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  105,                                 /* lineNo */
  20,                                  /* colNo */
  "",                                  /* aName */
  "chaccum",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2016b\\toolbox\\images\\images\\eml\\private\\chaccum.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo pb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  108,                                 /* lineNo */
  23,                                  /* colNo */
  "",                                  /* aName */
  "chaccum",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2016b\\toolbox\\images\\images\\eml\\private\\chaccum.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo qb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  109,                                 /* lineNo */
  17,                                  /* colNo */
  "",                                  /* aName */
  "chaccum",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2016b\\toolbox\\images\\images\\eml\\private\\chaccum.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo rb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  83,                                  /* lineNo */
  25,                                  /* colNo */
  "",                                  /* aName */
  "chaccum",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2016b\\toolbox\\images\\images\\eml\\private\\chaccum.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo sb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  83,                                  /* lineNo */
  9,                                   /* colNo */
  "",                                  /* aName */
  "chaccum",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2016b\\toolbox\\images\\images\\eml\\private\\chaccum.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo tb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  84,                                  /* lineNo */
  25,                                  /* colNo */
  "",                                  /* aName */
  "chaccum",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2016b\\toolbox\\images\\images\\eml\\private\\chaccum.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo ub_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  84,                                  /* lineNo */
  9,                                   /* colNo */
  "",                                  /* aName */
  "chaccum",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2016b\\toolbox\\images\\images\\eml\\private\\chaccum.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo vb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  85,                                  /* lineNo */
  27,                                  /* colNo */
  "",                                  /* aName */
  "chaccum",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2016b\\toolbox\\images\\images\\eml\\private\\chaccum.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo wb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  85,                                  /* lineNo */
  9,                                   /* colNo */
  "",                                  /* aName */
  "chaccum",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2016b\\toolbox\\images\\images\\eml\\private\\chaccum.m",/* pName */
  0                                    /* checkKind */
};

/* Function Definitions */
void chaccum(FindCircleStackData *SD, const emlrtStack *sp, const uint8_T
             varargin_1[921600], creal_T accumMatrix[307200], real32_T
             gradientImg[307200])
{
  int32_T i2;
  int32_T ixstart;
  real32_T t;
  int32_T idxEdge;
  boolean_T exitg2;
  real32_T edgeThresh;
  emxArray_real_T *Ey;
  emxArray_int32_T *ii;
  emxArray_int32_T *jj;
  emxArray_real_T *Ex;
  int32_T b_varargin_1[2];
  int32_T varargin_2[2];
  boolean_T p;
  boolean_T b_p;
  boolean_T exitg1;
  emxArray_int32_T *ndx;
  creal_T w0[31];
  static const creal_T dcv0[31] = { { -1.0,/* re */
      -1.2246467991473532E-16          /* im */
    }, { -0.95615124641749827,         /* re */
      -0.29287334118055974             /* im */
    }, { -0.8336990307590183,          /* re */
      -0.55221909249090018             /* im */
    }, { -0.64943121249867575,         /* re */
      -0.7604203444362202              /* im */
    }, { -0.42252321772467138,         /* re */
      -0.90635210072222483             /* im */
    }, { -0.17259493247790872,         /* re */
      -0.98499288793521045             /* im */
    }, { 0.081806067135590188,         /* re */
      -0.99664826663161732             /* im */
    }, { 0.32429052496520183,          /* re */
      -0.9459575336228333              /* im */
    }, { 0.5413163044171575,           /* re */
      -0.8408190403244632              /* im */
    }, { 0.72253513364778288,          /* re */
      -0.6913342032943115              /* im */
    }, { 0.86086194086240941,          /* re */
      -0.50883859796069475             /* im */
    }, { 0.9523324991276807,           /* re */
      -0.30506197912100752             /* im */
    }, { 0.99581076703864879,          /* re */
      -0.091438045965002171            /* im */
    }, { 0.99259987429192575,          /* re */
      0.12143100738960029              /* im */
    }, { 0.94600183597195175,          /* re */
      0.32416126594288897              /* im */
    }, { 0.86086194086241141,          /* re */
      0.50883859796069131              /* im */
    }, { 0.74312509122060533,          /* re */
      0.66915252282149174              /* im */
    }, { 0.5994236088602789,           /* re */
      0.80043196908976555              /* im */
    }, { 0.43670937692412126,          /* re */
      0.89960264567560366              /* im */
    }, { 0.26193771706003083,          /* re */
      0.96508477989313413              /* im */
    }, { 0.081806067135594393,         /* re */
      0.996648266631617                /* im */
    }, { -0.097452774920332663,        /* re */
      0.99524015024532                 /* im */
    }, { -0.27022547076676262,         /* re */
      0.96279706841518864              /* im */
    }, { -0.43162528684845275,         /* re */
      0.90205299830608121              /* im */
    }, { -0.57755683638145328,         /* re */
      0.8163504766636982               /* im */
    }, { -0.70474420482416189,         /* re */
      0.70946148998149272              /* im */
    }, { -0.810728382535478,           /* re */
      0.58542248825220888              /* im */
    }, { -0.89383978605837788,         /* re */
      0.44838648157489452              /* im */
    }, { -0.95315131088542715,         /* re */
      0.30249393143894937              /* im */
    }, { -0.98841689123984988,         /* re */
      0.15176313489036372              /* im */
    }, { -1.0,                         /* re */
      1.2246467991473532E-16           /* im */
    } };

  static const real_T dv0[31] = { 94.247779607693786, 97.389372261283583,
    100.53096491487338, 103.67255756846318, 106.81415022205297,
    109.95574287564276, 113.09733552923255, 116.23892818282235,
    119.38052083641213, 122.52211349000193, 125.66370614359172,
    128.80529879718151, 131.94689145077132, 135.0884841043611,
    138.23007675795088, 141.37166941154069, 144.51326206513048,
    147.65485471872029, 150.79644737231007, 153.93804002589985,
    157.07963267948966, 160.22122533307945, 163.36281798666926,
    166.50441064025904, 169.64600329384882, 172.78759594743863,
    175.92918860102841, 179.0707812546182, 182.212373908208, 185.35396656179779,
    188.49555921538757 };

  int32_T i;
  emxArray_real_T *Ex_chunk;
  emxArray_real_T *Ey_chunk;
  emxArray_real_T *idxE_chunk;
  emxArray_real32_T *xc;
  emxArray_real32_T *yc;
  emxArray_creal_T *w;
  emxArray_boolean_T *inside;
  emxArray_boolean_T *rows_to_keep;
  emxArray_int32_T *xckeep;
  emxArray_int32_T *yckeep;
  emxArray_creal_T *wkeep;
  emxArray_real_T *r0;
  int32_T i3;
  int32_T idx;
  int32_T i4;
  int32_T idxkeep;
  int32_T i5;
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b(sp);
  for (i2 = 0; i2 < 921600; i2++) {
    SD->f6.varargin_1[i2] = (varargin_1[i2] == varargin_1[0]);
  }

  if (all(SD->f6.varargin_1)) {
    memset(&accumMatrix[0], 0, 307200U * sizeof(creal_T));
    memset(&gradientImg[0], 0, 307200U * sizeof(real32_T));
  } else {
    st.site = &f_emlrtRSI;
    b_st.site = &l_emlrtRSI;
    rgb2gray(varargin_1, SD->f6.img);
    for (i2 = 0; i2 < 307200; i2++) {
      SD->f6.A[i2] = (real32_T)SD->f6.img[i2] / 255.0F;
    }

    st.site = &g_emlrtRSI;
    b_st.site = &n_emlrtRSI;
    imfilter(SD, &b_st, SD->f6.A, SD->f6.Gx);
    b_st.site = &o_emlrtRSI;
    b_imfilter(SD, &b_st, SD->f6.A, SD->f6.Gy);
    for (ixstart = 0; ixstart < 307200; ixstart++) {
      gradientImg[ixstart] = muSingleScalarHypot(SD->f6.Gx[ixstart], SD->
        f6.Gy[ixstart]);
    }

    st.site = &h_emlrtRSI;
    ixstart = 1;
    t = gradientImg[0];
    if (muSingleScalarIsNaN(gradientImg[0])) {
      idxEdge = 2;
      exitg2 = false;
      while ((!exitg2) && (idxEdge < 307201)) {
        ixstart = idxEdge;
        if (!muSingleScalarIsNaN(gradientImg[idxEdge - 1])) {
          t = gradientImg[idxEdge - 1];
          exitg2 = true;
        } else {
          idxEdge++;
        }
      }
    }

    if (ixstart < 307200) {
      while (ixstart + 1 < 307201) {
        if (gradientImg[ixstart] > t) {
          t = gradientImg[ixstart];
        }

        ixstart++;
      }
    }

    for (i2 = 0; i2 < 307200; i2++) {
      SD->f6.A[i2] = gradientImg[i2] / t;
    }

    b_st.site = &fb_emlrtRSI;
    edgeThresh = multithresh(SD, &b_st, SD->f6.A);
    t *= edgeThresh;
    b_st.site = &gb_emlrtRSI;
    for (i2 = 0; i2 < 307200; i2++) {
      SD->f6.gradientImg[i2] = (gradientImg[i2] > t);
    }

    emxInit_real_T(&b_st, &Ey, 1, &e_emlrtRTEI, true);
    emxInit_int32_T(&b_st, &ii, 1, &e_emlrtRTEI, true);
    emxInit_int32_T(&b_st, &jj, 1, &e_emlrtRTEI, true);
    c_st.site = &rd_emlrtRSI;
    eml_find(&c_st, SD->f6.gradientImg, ii, jj);
    i2 = Ey->size[0];
    Ey->size[0] = ii->size[0];
    emxEnsureCapacity(&b_st, (emxArray__common *)Ey, i2, (int32_T)sizeof(real_T),
                      &e_emlrtRTEI);
    ixstart = ii->size[0];
    for (i2 = 0; i2 < ixstart; i2++) {
      Ey->data[i2] = ii->data[i2];
    }

    emxFree_int32_T(&ii);
    emxInit_real_T(&b_st, &Ex, 1, &e_emlrtRTEI, true);
    i2 = Ex->size[0];
    Ex->size[0] = jj->size[0];
    emxEnsureCapacity(&b_st, (emxArray__common *)Ex, i2, (int32_T)sizeof(real_T),
                      &e_emlrtRTEI);
    ixstart = jj->size[0];
    for (i2 = 0; i2 < ixstart; i2++) {
      Ex->data[i2] = jj->data[i2];
    }

    emxFree_int32_T(&jj);
    st.site = &i_emlrtRSI;
    b_st.site = &vd_emlrtRSI;
    if (!allinrange(Ey, 480)) {
      emlrtErrorWithMessageIdR2012b(&b_st, &hc_emlrtRTEI,
        "MATLAB:sub2ind:IndexOutOfRange", 0);
    }

    b_varargin_1[0] = Ey->size[0];
    b_varargin_1[1] = 1;
    varargin_2[0] = Ex->size[0];
    varargin_2[1] = 1;
    p = false;
    b_p = true;
    ixstart = 0;
    exitg1 = false;
    while ((!exitg1) && (ixstart < 2)) {
      if (!(b_varargin_1[ixstart] == varargin_2[ixstart])) {
        b_p = false;
        exitg1 = true;
      } else {
        ixstart++;
      }
    }

    if (b_p) {
      p = true;
    }

    if (!p) {
      emlrtErrorWithMessageIdR2012b(&b_st, &ic_emlrtRTEI,
        "MATLAB:sub2ind:SubscriptVectorSize", 0);
    }

    if (!allinrange(Ex, 640)) {
      emlrtErrorWithMessageIdR2012b(&b_st, &hc_emlrtRTEI,
        "MATLAB:sub2ind:IndexOutOfRange", 0);
    }

    emxInit_int32_T(&b_st, &ndx, 1, &e_emlrtRTEI, true);
    i2 = ndx->size[0];
    ndx->size[0] = Ey->size[0];
    emxEnsureCapacity(&st, (emxArray__common *)ndx, i2, (int32_T)sizeof(int32_T),
                      &e_emlrtRTEI);
    ixstart = Ey->size[0];
    for (i2 = 0; i2 < ixstart; i2++) {
      ndx->data[i2] = (int32_T)Ey->data[i2] + 480 * ((int32_T)Ex->data[i2] - 1);
    }

    for (i2 = 0; i2 < 31; i2++) {
      if (dcv0[i2].im == 0.0) {
        w0[i2].re = dcv0[i2].re / dv0[i2];
        w0[i2].im = 0.0;
      } else if (dcv0[i2].re == 0.0) {
        w0[i2].re = 0.0;
        w0[i2].im = dcv0[i2].im / dv0[i2];
      } else {
        w0[i2].re = dcv0[i2].re / dv0[i2];
        w0[i2].im = dcv0[i2].im / dv0[i2];
      }
    }

    memset(&accumMatrix[0], 0, 307200U * sizeof(creal_T));
    i2 = (int32_T)(((real_T)Ex->size[0] + 32257.0) / 32258.0);
    emlrtForLoopVectorCheckR2012b(1.0, 32258.0, Ex->size[0], mxDOUBLE_CLASS, i2,
      &jc_emlrtRTEI, sp);
    i = 0;
    emxInit_real_T(sp, &Ex_chunk, 1, &f_emlrtRTEI, true);
    emxInit_real_T(sp, &Ey_chunk, 1, &g_emlrtRTEI, true);
    emxInit_real_T(sp, &idxE_chunk, 1, &h_emlrtRTEI, true);
    emxInit_real32_T(sp, &xc, 2, &i_emlrtRTEI, true);
    emxInit_real32_T(sp, &yc, 2, &j_emlrtRTEI, true);
    emxInit_creal_T1(sp, &w, 2, &k_emlrtRTEI, true);
    emxInit_boolean_T(sp, &inside, 2, &l_emlrtRTEI, true);
    emxInit_boolean_T1(sp, &rows_to_keep, 1, &m_emlrtRTEI, true);
    emxInit_int32_T(sp, &xckeep, 1, &n_emlrtRTEI, true);
    emxInit_int32_T(sp, &yckeep, 1, &o_emlrtRTEI, true);
    emxInit_creal_T(sp, &wkeep, 1, &p_emlrtRTEI, true);
    emxInit_real_T1(sp, &r0, 2, &e_emlrtRTEI, true);
    while (i <= i2 - 1) {
      idxEdge = 1 + i * 32258;
      ixstart = (int32_T)muDoubleScalarMin(((real_T)idxEdge + 32258.0) - 1.0,
        Ex->size[0]);
      st.site = &j_emlrtRSI;
      b_st.site = &wd_emlrtRSI;
      if (ixstart < idxEdge) {
        i3 = r0->size[0] * r0->size[1];
        r0->size[0] = 1;
        r0->size[1] = 0;
        emxEnsureCapacity(&b_st, (emxArray__common *)r0, i3, (int32_T)sizeof
                          (real_T), &e_emlrtRTEI);
      } else {
        i3 = r0->size[0] * r0->size[1];
        r0->size[0] = 1;
        r0->size[1] = (ixstart - idxEdge) + 1;
        emxEnsureCapacity(&b_st, (emxArray__common *)r0, i3, (int32_T)sizeof
                          (real_T), &e_emlrtRTEI);
        ixstart -= idxEdge;
        for (i3 = 0; i3 <= ixstart; i3++) {
          r0->data[r0->size[0] * i3] = idxEdge + i3;
        }
      }

      i3 = Ex_chunk->size[0];
      Ex_chunk->size[0] = r0->size[1];
      emxEnsureCapacity(sp, (emxArray__common *)Ex_chunk, i3, (int32_T)sizeof
                        (real_T), &e_emlrtRTEI);
      i3 = Ey_chunk->size[0];
      Ey_chunk->size[0] = r0->size[1];
      emxEnsureCapacity(sp, (emxArray__common *)Ey_chunk, i3, (int32_T)sizeof
                        (real_T), &e_emlrtRTEI);
      i3 = idxE_chunk->size[0];
      idxE_chunk->size[0] = r0->size[1];
      emxEnsureCapacity(sp, (emxArray__common *)idxE_chunk, i3, (int32_T)sizeof
                        (real_T), &e_emlrtRTEI);
      for (idx = 1; idx - 1 < r0->size[1]; idx++) {
        i3 = Ex->size[0];
        if (!((idxEdge >= 1) && (idxEdge <= i3))) {
          emlrtDynamicBoundsCheckR2012b(idxEdge, 1, i3, &rb_emlrtBCI, sp);
        }

        i3 = Ex_chunk->size[0];
        if (!((idx >= 1) && (idx <= i3))) {
          emlrtDynamicBoundsCheckR2012b(idx, 1, i3, &sb_emlrtBCI, sp);
        }

        Ex_chunk->data[idx - 1] = Ex->data[idxEdge - 1];
        i3 = Ey->size[0];
        if (!((idxEdge >= 1) && (idxEdge <= i3))) {
          emlrtDynamicBoundsCheckR2012b(idxEdge, 1, i3, &tb_emlrtBCI, sp);
        }

        i3 = Ey_chunk->size[0];
        if (!((idx >= 1) && (idx <= i3))) {
          emlrtDynamicBoundsCheckR2012b(idx, 1, i3, &ub_emlrtBCI, sp);
        }

        Ey_chunk->data[idx - 1] = Ey->data[idxEdge - 1];
        i3 = ndx->size[0];
        if (!((idxEdge >= 1) && (idxEdge <= i3))) {
          emlrtDynamicBoundsCheckR2012b(idxEdge, 1, i3, &vb_emlrtBCI, sp);
        }

        i3 = idxE_chunk->size[0];
        if (!((idx >= 1) && (idx <= i3))) {
          emlrtDynamicBoundsCheckR2012b(idx, 1, i3, &wb_emlrtBCI, sp);
        }

        idxE_chunk->data[idx - 1] = ndx->data[idxEdge - 1];
        idxEdge++;
      }

      i3 = xc->size[0] * xc->size[1];
      xc->size[0] = idxE_chunk->size[0];
      xc->size[1] = 31;
      emxEnsureCapacity(sp, (emxArray__common *)xc, i3, (int32_T)sizeof(real32_T),
                        &e_emlrtRTEI);
      i3 = yc->size[0] * yc->size[1];
      yc->size[0] = idxE_chunk->size[0];
      yc->size[1] = 31;
      emxEnsureCapacity(sp, (emxArray__common *)yc, i3, (int32_T)sizeof(real32_T),
                        &e_emlrtRTEI);
      i3 = w->size[0] * w->size[1];
      w->size[0] = idxE_chunk->size[0];
      w->size[1] = 31;
      emxEnsureCapacity(sp, (emxArray__common *)w, i3, (int32_T)sizeof(creal_T),
                        &e_emlrtRTEI);
      i3 = inside->size[0] * inside->size[1];
      inside->size[0] = idxE_chunk->size[0];
      inside->size[1] = 31;
      emxEnsureCapacity(sp, (emxArray__common *)inside, i3, (int32_T)sizeof
                        (boolean_T), &e_emlrtRTEI);
      i3 = rows_to_keep->size[0];
      rows_to_keep->size[0] = idxE_chunk->size[0];
      emxEnsureCapacity(sp, (emxArray__common *)rows_to_keep, i3, (int32_T)
                        sizeof(boolean_T), &e_emlrtRTEI);
      ixstart = idxE_chunk->size[0];
      for (i3 = 0; i3 < ixstart; i3++) {
        rows_to_keep->data[i3] = false;
      }

      for (ixstart = 0; ixstart < 31; ixstart++) {
        for (idxEdge = 0; idxEdge < idxE_chunk->size[0]; idxEdge++) {
          i3 = idxE_chunk->size[0];
          i4 = 1 + idxEdge;
          if (!((i4 >= 1) && (i4 <= i3))) {
            emlrtDynamicBoundsCheckR2012b(i4, 1, i3, &fb_emlrtBCI, sp);
          }

          i3 = (int32_T)idxE_chunk->data[i4 - 1];
          if (!((i3 >= 1) && (i3 <= 307200))) {
            emlrtDynamicBoundsCheckR2012b(i3, 1, 307200, &f_emlrtBCI, sp);
          }

          i3 = idxE_chunk->size[0];
          i4 = 1 + idxEdge;
          if (!((i4 >= 1) && (i4 <= i3))) {
            emlrtDynamicBoundsCheckR2012b(i4, 1, i3, &gb_emlrtBCI, sp);
          }

          i3 = (int32_T)idxE_chunk->data[i4 - 1];
          if (!((i3 >= 1) && (i3 <= 307200))) {
            emlrtDynamicBoundsCheckR2012b(i3, 1, 307200, &g_emlrtBCI, sp);
          }

          i3 = Ex_chunk->size[0];
          i4 = 1 + idxEdge;
          if (!((i4 >= 1) && (i4 <= i3))) {
            emlrtDynamicBoundsCheckR2012b(i4, 1, i3, &hb_emlrtBCI, sp);
          }

          t = (real32_T)Ex_chunk->data[i4 - 1] + (real32_T)-(15.0 + 0.5 *
            (real_T)ixstart) * (SD->f6.Gx[(int32_T)idxE_chunk->data[idxEdge] - 1]
                                / gradientImg[(int32_T)idxE_chunk->data[idxEdge]
                                - 1]);
          i3 = xc->size[0];
          i4 = 1 + idxEdge;
          if (!((i4 >= 1) && (i4 <= i3))) {
            emlrtDynamicBoundsCheckR2012b(i4, 1, i3, &ib_emlrtBCI, sp);
          }

          if (t > 0.0F) {
            xc->data[(i4 + xc->size[0] * ixstart) - 1] = t + 0.5F;
          } else if (t < 0.0F) {
            xc->data[(i4 + xc->size[0] * ixstart) - 1] = t - 0.5F;
          } else {
            xc->data[(i4 + xc->size[0] * ixstart) - 1] = 0.0F;
          }

          i3 = idxE_chunk->size[0];
          i4 = 1 + idxEdge;
          if (!((i4 >= 1) && (i4 <= i3))) {
            emlrtDynamicBoundsCheckR2012b(i4, 1, i3, &jb_emlrtBCI, sp);
          }

          i3 = (int32_T)idxE_chunk->data[i4 - 1];
          if (!((i3 >= 1) && (i3 <= 307200))) {
            emlrtDynamicBoundsCheckR2012b(i3, 1, 307200, &h_emlrtBCI, sp);
          }

          i3 = idxE_chunk->size[0];
          i4 = 1 + idxEdge;
          if (!((i4 >= 1) && (i4 <= i3))) {
            emlrtDynamicBoundsCheckR2012b(i4, 1, i3, &kb_emlrtBCI, sp);
          }

          i3 = (int32_T)idxE_chunk->data[i4 - 1];
          if (!((i3 >= 1) && (i3 <= 307200))) {
            emlrtDynamicBoundsCheckR2012b(i3, 1, 307200, &i_emlrtBCI, sp);
          }

          i3 = Ey_chunk->size[0];
          i4 = 1 + idxEdge;
          if (!((i4 >= 1) && (i4 <= i3))) {
            emlrtDynamicBoundsCheckR2012b(i4, 1, i3, &lb_emlrtBCI, sp);
          }

          t = (real32_T)Ey_chunk->data[i4 - 1] + (real32_T)-(15.0 + 0.5 *
            (real_T)ixstart) * (SD->f6.Gy[(int32_T)idxE_chunk->data[idxEdge] - 1]
                                / gradientImg[(int32_T)idxE_chunk->data[idxEdge]
                                - 1]);
          i3 = yc->size[0];
          i4 = 1 + idxEdge;
          if (!((i4 >= 1) && (i4 <= i3))) {
            emlrtDynamicBoundsCheckR2012b(i4, 1, i3, &mb_emlrtBCI, sp);
          }

          if (t > 0.0F) {
            yc->data[(i4 + yc->size[0] * ixstart) - 1] = t + 0.5F;
          } else if (t < 0.0F) {
            yc->data[(i4 + yc->size[0] * ixstart) - 1] = t - 0.5F;
          } else {
            yc->data[(i4 + yc->size[0] * ixstart) - 1] = 0.0F;
          }

          i3 = w->size[0];
          i4 = 1 + idxEdge;
          if (!((i4 >= 1) && (i4 <= i3))) {
            emlrtDynamicBoundsCheckR2012b(i4, 1, i3, &nb_emlrtBCI, sp);
          }

          w->data[(i4 + w->size[0] * ixstart) - 1].re = w0[ixstart].re;
          i3 = w->size[0];
          i4 = 1 + idxEdge;
          if (!((i4 >= 1) && (i4 <= i3))) {
            emlrtDynamicBoundsCheckR2012b(i4, 1, i3, &nb_emlrtBCI, sp);
          }

          w->data[(i4 + w->size[0] * ixstart) - 1].im = w0[ixstart].im;
          i3 = xc->size[0];
          i4 = idxEdge + 1;
          if (!((i4 >= 1) && (i4 <= i3))) {
            emlrtDynamicBoundsCheckR2012b(i4, 1, i3, &j_emlrtBCI, sp);
          }

          i3 = xc->size[0];
          i4 = idxEdge + 1;
          if (!((i4 >= 1) && (i4 <= i3))) {
            emlrtDynamicBoundsCheckR2012b(i4, 1, i3, &k_emlrtBCI, sp);
          }

          i3 = yc->size[0];
          i4 = idxEdge + 1;
          if (!((i4 >= 1) && (i4 <= i3))) {
            emlrtDynamicBoundsCheckR2012b(i4, 1, i3, &l_emlrtBCI, sp);
          }

          i3 = yc->size[0];
          i4 = idxEdge + 1;
          if (!((i4 >= 1) && (i4 <= i3))) {
            emlrtDynamicBoundsCheckR2012b(i4, 1, i3, &m_emlrtBCI, sp);
          }

          i3 = inside->size[0];
          i4 = 1 + idxEdge;
          if (!((i4 >= 1) && (i4 <= i3))) {
            emlrtDynamicBoundsCheckR2012b(i4, 1, i3, &ob_emlrtBCI, sp);
          }

          inside->data[(i4 + inside->size[0] * ixstart) - 1] = ((xc->
            data[idxEdge + xc->size[0] * ixstart] >= 1.0F) && (xc->data[idxEdge
            + xc->size[0] * ixstart] <= 640.0F) && (yc->data[idxEdge + yc->size
            [0] * ixstart] >= 1.0F) && (yc->data[idxEdge + yc->size[0] * ixstart]
            < 480.0F));
          i3 = inside->size[0];
          i4 = 1 + idxEdge;
          if (!((i4 >= 1) && (i4 <= i3))) {
            emlrtDynamicBoundsCheckR2012b(i4, 1, i3, &pb_emlrtBCI, sp);
          }

          if (inside->data[(i4 + inside->size[0] * ixstart) - 1]) {
            i3 = rows_to_keep->size[0];
            i4 = 1 + idxEdge;
            if (!((i4 >= 1) && (i4 <= i3))) {
              emlrtDynamicBoundsCheckR2012b(i4, 1, i3, &qb_emlrtBCI, sp);
            }

            rows_to_keep->data[i4 - 1] = true;
          }
        }
      }

      i3 = xckeep->size[0];
      xckeep->size[0] = xc->size[0] * 31;
      emxEnsureCapacity(sp, (emxArray__common *)xckeep, i3, (int32_T)sizeof
                        (int32_T), &e_emlrtRTEI);
      i3 = yckeep->size[0];
      yckeep->size[0] = yc->size[0] * 31;
      emxEnsureCapacity(sp, (emxArray__common *)yckeep, i3, (int32_T)sizeof
                        (int32_T), &e_emlrtRTEI);
      i3 = wkeep->size[0];
      wkeep->size[0] = w->size[0] * 31;
      emxEnsureCapacity(sp, (emxArray__common *)wkeep, i3, (int32_T)sizeof
                        (creal_T), &e_emlrtRTEI);
      idxkeep = 0;
      for (ixstart = 0; ixstart < 31; ixstart++) {
        for (idxEdge = 1; idxEdge - 1 < idxE_chunk->size[0]; idxEdge++) {
          i3 = rows_to_keep->size[0];
          if (!((idxEdge >= 1) && (idxEdge <= i3))) {
            emlrtDynamicBoundsCheckR2012b(idxEdge, 1, i3, &w_emlrtBCI, sp);
          }

          if (rows_to_keep->data[idxEdge - 1]) {
            i3 = inside->size[0];
            if (!((idxEdge >= 1) && (idxEdge <= i3))) {
              emlrtDynamicBoundsCheckR2012b(idxEdge, 1, i3, &x_emlrtBCI, sp);
            }

            if (inside->data[(idxEdge + inside->size[0] * ixstart) - 1]) {
              idxkeep++;
              i3 = xc->size[0];
              if (!((idxEdge >= 1) && (idxEdge <= i3))) {
                emlrtDynamicBoundsCheckR2012b(idxEdge, 1, i3, &y_emlrtBCI, sp);
              }

              i3 = xckeep->size[0];
              if (!((idxkeep >= 1) && (idxkeep <= i3))) {
                emlrtDynamicBoundsCheckR2012b(idxkeep, 1, i3, &ab_emlrtBCI, sp);
              }

              xckeep->data[idxkeep - 1] = (int32_T)xc->data[(idxEdge + xc->size
                [0] * ixstart) - 1];
              i3 = yc->size[0];
              if (!((idxEdge >= 1) && (idxEdge <= i3))) {
                emlrtDynamicBoundsCheckR2012b(idxEdge, 1, i3, &bb_emlrtBCI, sp);
              }

              i3 = yckeep->size[0];
              if (!((idxkeep >= 1) && (idxkeep <= i3))) {
                emlrtDynamicBoundsCheckR2012b(idxkeep, 1, i3, &cb_emlrtBCI, sp);
              }

              yckeep->data[idxkeep - 1] = (int32_T)yc->data[(idxEdge + yc->size
                [0] * ixstart) - 1];
              i3 = wkeep->size[0];
              if (!((idxkeep >= 1) && (idxkeep <= i3))) {
                emlrtDynamicBoundsCheckR2012b(idxkeep, 1, i3, &eb_emlrtBCI, sp);
              }

              i3 = w->size[0];
              if (!((idxEdge >= 1) && (idxEdge <= i3))) {
                emlrtDynamicBoundsCheckR2012b(idxEdge, 1, i3, &db_emlrtBCI, sp);
              }

              wkeep->data[idxkeep - 1].re = w->data[(idxEdge + w->size[0] *
                ixstart) - 1].re;
              i3 = w->size[0];
              if (!((idxEdge >= 1) && (idxEdge <= i3))) {
                emlrtDynamicBoundsCheckR2012b(idxEdge, 1, i3, &db_emlrtBCI, sp);
              }

              i3 = wkeep->size[0];
              if (!((idxkeep >= 1) && (idxkeep <= i3))) {
                emlrtDynamicBoundsCheckR2012b(idxkeep, 1, i3, &eb_emlrtBCI, sp);
              }

              wkeep->data[idxkeep - 1].im = w->data[(idxEdge + w->size[0] *
                ixstart) - 1].im;
            }
          }
        }
      }

      st.site = &k_emlrtRSI;
      memset(&SD->f6.out[0], 0, 307200U * sizeof(creal_T));
      b_st.site = &xd_emlrtRSI;
      for (idx = 1; idx <= idxkeep; idx++) {
        i3 = yckeep->size[0];
        if (!((idx >= 1) && (idx <= i3))) {
          emlrtDynamicBoundsCheckR2012b(idx, 1, i3, &t_emlrtBCI, &st);
        }

        i3 = yckeep->data[idx - 1];
        if (!((i3 >= 1) && (i3 <= 480))) {
          emlrtDynamicBoundsCheckR2012b(i3, 1, 480, &s_emlrtBCI, &st);
        }

        i4 = xckeep->size[0];
        if (!((idx >= 1) && (idx <= i4))) {
          emlrtDynamicBoundsCheckR2012b(idx, 1, i4, &v_emlrtBCI, &st);
        }

        i4 = xckeep->data[idx - 1];
        if (!((i4 >= 1) && (i4 <= 640))) {
          emlrtDynamicBoundsCheckR2012b(i4, 1, 640, &u_emlrtBCI, &st);
        }

        ixstart = yckeep->size[0];
        if (!((idx >= 1) && (idx <= ixstart))) {
          emlrtDynamicBoundsCheckR2012b(idx, 1, ixstart, &o_emlrtBCI, &st);
        }

        ixstart = yckeep->data[idx - 1];
        if (!((ixstart >= 1) && (ixstart <= 480))) {
          emlrtDynamicBoundsCheckR2012b(ixstart, 1, 480, &n_emlrtBCI, &st);
        }

        idxEdge = xckeep->size[0];
        if (!((idx >= 1) && (idx <= idxEdge))) {
          emlrtDynamicBoundsCheckR2012b(idx, 1, idxEdge, &q_emlrtBCI, &st);
        }

        idxEdge = xckeep->data[idx - 1];
        if (!((idxEdge >= 1) && (idxEdge <= 640))) {
          emlrtDynamicBoundsCheckR2012b(idxEdge, 1, 640, &p_emlrtBCI, &st);
        }

        i5 = wkeep->size[0];
        if (!((idx >= 1) && (idx <= i5))) {
          emlrtDynamicBoundsCheckR2012b(idx, 1, i5, &r_emlrtBCI, &st);
        }

        SD->f6.out[(i3 + 480 * (i4 - 1)) - 1].re = SD->f6.out[(ixstart + 480 *
          (idxEdge - 1)) - 1].re + wkeep->data[idx - 1].re;
        i3 = yckeep->size[0];
        if (!((idx >= 1) && (idx <= i3))) {
          emlrtDynamicBoundsCheckR2012b(idx, 1, i3, &o_emlrtBCI, &st);
        }

        i3 = yckeep->data[idx - 1];
        if (!((i3 >= 1) && (i3 <= 480))) {
          emlrtDynamicBoundsCheckR2012b(i3, 1, 480, &n_emlrtBCI, &st);
        }

        i4 = xckeep->size[0];
        if (!((idx >= 1) && (idx <= i4))) {
          emlrtDynamicBoundsCheckR2012b(idx, 1, i4, &q_emlrtBCI, &st);
        }

        i4 = xckeep->data[idx - 1];
        if (!((i4 >= 1) && (i4 <= 640))) {
          emlrtDynamicBoundsCheckR2012b(i4, 1, 640, &p_emlrtBCI, &st);
        }

        ixstart = wkeep->size[0];
        if (!((idx >= 1) && (idx <= ixstart))) {
          emlrtDynamicBoundsCheckR2012b(idx, 1, ixstart, &r_emlrtBCI, &st);
        }

        ixstart = yckeep->size[0];
        if (!((idx >= 1) && (idx <= ixstart))) {
          emlrtDynamicBoundsCheckR2012b(idx, 1, ixstart, &t_emlrtBCI, &st);
        }

        ixstart = yckeep->data[idx - 1];
        if (!((ixstart >= 1) && (ixstart <= 480))) {
          emlrtDynamicBoundsCheckR2012b(ixstart, 1, 480, &s_emlrtBCI, &st);
        }

        idxEdge = xckeep->size[0];
        if (!((idx >= 1) && (idx <= idxEdge))) {
          emlrtDynamicBoundsCheckR2012b(idx, 1, idxEdge, &v_emlrtBCI, &st);
        }

        idxEdge = xckeep->data[idx - 1];
        if (!((idxEdge >= 1) && (idxEdge <= 640))) {
          emlrtDynamicBoundsCheckR2012b(idxEdge, 1, 640, &u_emlrtBCI, &st);
        }

        SD->f6.out[(ixstart + 480 * (idxEdge - 1)) - 1].im = SD->f6.out[(i3 +
          480 * (i4 - 1)) - 1].im + wkeep->data[idx - 1].im;
      }

      for (i3 = 0; i3 < 307200; i3++) {
        accumMatrix[i3].re += SD->f6.out[i3].re;
        accumMatrix[i3].im += SD->f6.out[i3].im;
      }

      i++;
    }

    emxFree_int32_T(&ndx);
    emxFree_real_T(&Ex);
    emxFree_real_T(&Ey);
    emxFree_real_T(&r0);
    emxFree_creal_T(&wkeep);
    emxFree_int32_T(&yckeep);
    emxFree_int32_T(&xckeep);
    emxFree_boolean_T(&rows_to_keep);
    emxFree_boolean_T(&inside);
    emxFree_creal_T(&w);
    emxFree_real32_T(&yc);
    emxFree_real32_T(&xc);
    emxFree_real_T(&idxE_chunk);
    emxFree_real_T(&Ey_chunk);
    emxFree_real_T(&Ex_chunk);
  }

  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

/* End of code generation (chaccum.c) */
