/*
 * Sponsored License - for use in support of a program or activity
 * sponsored by MathWorks.  Not for government, commercial or other
 * non-sponsored organizational use.
 *
 * regionprops.c
 *
 * Code generation for function 'regionprops'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "FindCircle.h"
#include "regionprops.h"
#include "FindCircle_emxutil.h"
#include "eml_int_forloop_overflow_check.h"
#include "sum.h"
#include "assertValidSizeArg.h"
#include "bwconncomp.h"
#include "FindCircle_data.h"

/* Type Definitions */
#ifndef typedef_struct_T
#define typedef_struct_T

typedef struct {
  boolean_T Area;
  boolean_T Centroid;
  boolean_T BoundingBox;
  boolean_T MajorAxisLength;
  boolean_T MinorAxisLength;
  boolean_T Eccentricity;
  boolean_T Orientation;
  boolean_T Image;
  boolean_T FilledImage;
  boolean_T FilledArea;
  boolean_T EulerNumber;
  boolean_T Extrema;
  boolean_T EquivDiameter;
  boolean_T Extent;
  boolean_T PixelIdxList;
  boolean_T PixelList;
  boolean_T Perimeter;
  boolean_T PixelValues;
  boolean_T WeightedCentroid;
  boolean_T MeanIntensity;
  boolean_T MinIntensity;
  boolean_T MaxIntensity;
  boolean_T SubarrayIdx;
} struct_T;

#endif                                 /*typedef_struct_T*/

/* Variable Definitions */
static emlrtRSInfo ff_emlrtRSI = { 32, /* lineNo */
  "regionprops",                       /* fcnName */
  "C:\\Program Files\\MATLAB\\R2016b\\toolbox\\images\\images\\eml\\regionprops.m"/* pathName */
};

static emlrtRSInfo gf_emlrtRSI = { 69, /* lineNo */
  "regionprops",                       /* fcnName */
  "C:\\Program Files\\MATLAB\\R2016b\\toolbox\\images\\images\\eml\\regionprops.m"/* pathName */
};

static emlrtRSInfo hf_emlrtRSI = { 71, /* lineNo */
  "regionprops",                       /* fcnName */
  "C:\\Program Files\\MATLAB\\R2016b\\toolbox\\images\\images\\eml\\regionprops.m"/* pathName */
};

static emlrtRSInfo if_emlrtRSI = { 74, /* lineNo */
  "regionprops",                       /* fcnName */
  "C:\\Program Files\\MATLAB\\R2016b\\toolbox\\images\\images\\eml\\regionprops.m"/* pathName */
};

static emlrtRSInfo jf_emlrtRSI = { 164,/* lineNo */
  "regionprops",                       /* fcnName */
  "C:\\Program Files\\MATLAB\\R2016b\\toolbox\\images\\images\\eml\\regionprops.m"/* pathName */
};

static emlrtRSInfo kf_emlrtRSI = { 189,/* lineNo */
  "regionprops",                       /* fcnName */
  "C:\\Program Files\\MATLAB\\R2016b\\toolbox\\images\\images\\eml\\regionprops.m"/* pathName */
};

static emlrtRSInfo hg_emlrtRSI = { 1173,/* lineNo */
  "regionprops",                       /* fcnName */
  "C:\\Program Files\\MATLAB\\R2016b\\toolbox\\images\\images\\eml\\regionprops.m"/* pathName */
};

static emlrtRSInfo ig_emlrtRSI = { 1338,/* lineNo */
  "regionprops",                       /* fcnName */
  "C:\\Program Files\\MATLAB\\R2016b\\toolbox\\images\\images\\eml\\regionprops.m"/* pathName */
};

static emlrtRSInfo jg_emlrtRSI = { 18, /* lineNo */
  "repmat",                            /* fcnName */
  "C:\\Program Files\\MATLAB\\R2016b\\toolbox\\eml\\lib\\matlab\\elmat\\repmat.m"/* pathName */
};

static emlrtRSInfo kg_emlrtRSI = { 1693,/* lineNo */
  "regionprops",                       /* fcnName */
  "C:\\Program Files\\MATLAB\\R2016b\\toolbox\\images\\images\\eml\\regionprops.m"/* pathName */
};

static emlrtRSInfo lg_emlrtRSI = { 242,/* lineNo */
  "regionprops",                       /* fcnName */
  "C:\\Program Files\\MATLAB\\R2016b\\toolbox\\images\\images\\eml\\regionprops.m"/* pathName */
};

static emlrtRSInfo mg_emlrtRSI = { 1043,/* lineNo */
  "regionprops",                       /* fcnName */
  "C:\\Program Files\\MATLAB\\R2016b\\toolbox\\images\\images\\eml\\regionprops.m"/* pathName */
};

static emlrtRSInfo ng_emlrtRSI = { 1034,/* lineNo */
  "regionprops",                       /* fcnName */
  "C:\\Program Files\\MATLAB\\R2016b\\toolbox\\images\\images\\eml\\regionprops.m"/* pathName */
};

static emlrtRSInfo og_emlrtRSI = { 1029,/* lineNo */
  "regionprops",                       /* fcnName */
  "C:\\Program Files\\MATLAB\\R2016b\\toolbox\\images\\images\\eml\\regionprops.m"/* pathName */
};

static emlrtRSInfo pg_emlrtRSI = { 676,/* lineNo */
  "regionprops",                       /* fcnName */
  "C:\\Program Files\\MATLAB\\R2016b\\toolbox\\images\\images\\eml\\regionprops.m"/* pathName */
};

static emlrtRSInfo qg_emlrtRSI = { 674,/* lineNo */
  "regionprops",                       /* fcnName */
  "C:\\Program Files\\MATLAB\\R2016b\\toolbox\\images\\images\\eml\\regionprops.m"/* pathName */
};

static emlrtRSInfo rg_emlrtRSI = { 19, /* lineNo */
  "ind2sub",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2016b\\toolbox\\eml\\lib\\matlab\\elmat\\ind2sub.m"/* pathName */
};

static emlrtRSInfo sg_emlrtRSI = { 20, /* lineNo */
  "cat",                               /* fcnName */
  "C:\\Program Files\\MATLAB\\R2016b\\toolbox\\eml\\eml\\+coder\\+internal\\cat.m"/* pathName */
};

static emlrtRSInfo tg_emlrtRSI = { 100,/* lineNo */
  "cat",                               /* fcnName */
  "C:\\Program Files\\MATLAB\\R2016b\\toolbox\\eml\\eml\\+coder\\+internal\\cat.m"/* pathName */
};

static emlrtRTEInfo kb_emlrtRTEI = { 1,/* lineNo */
  23,                                  /* colNo */
  "regionprops",                       /* fName */
  "C:\\Program Files\\MATLAB\\R2016b\\toolbox\\images\\images\\eml\\regionprops.m"/* pName */
};

static emlrtRTEInfo lb_emlrtRTEI = { 226,/* lineNo */
  9,                                   /* colNo */
  "regionprops",                       /* fName */
  "C:\\Program Files\\MATLAB\\R2016b\\toolbox\\images\\images\\eml\\regionprops.m"/* pName */
};

static emlrtRTEInfo mb_emlrtRTEI = { 1033,/* lineNo */
  9,                                   /* colNo */
  "regionprops",                       /* fName */
  "C:\\Program Files\\MATLAB\\R2016b\\toolbox\\images\\images\\eml\\regionprops.m"/* pName */
};

static emlrtRTEInfo nb_emlrtRTEI = { 30,/* lineNo */
  1,                                   /* colNo */
  "ind2sub",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2016b\\toolbox\\eml\\lib\\matlab\\elmat\\ind2sub.m"/* pName */
};

static emlrtRTEInfo tb_emlrtRTEI = { 1570,/* lineNo */
  42,                                  /* colNo */
  "regionprops",                       /* fName */
  "C:\\Program Files\\MATLAB\\R2016b\\toolbox\\images\\images\\eml\\regionprops.m"/* pName */
};

static emlrtRTEInfo ub_emlrtRTEI = { 1581,/* lineNo */
  5,                                   /* colNo */
  "regionprops",                       /* fName */
  "C:\\Program Files\\MATLAB\\R2016b\\toolbox\\images\\images\\eml\\regionprops.m"/* pName */
};

static emlrtRTEInfo uc_emlrtRTEI = { 1161,/* lineNo */
  5,                                   /* colNo */
  "regionprops",                       /* fName */
  "C:\\Program Files\\MATLAB\\R2016b\\toolbox\\images\\images\\eml\\regionprops.m"/* pName */
};

static emlrtBCInfo uc_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  244,                                 /* lineNo */
  47,                                  /* colNo */
  "",                                  /* aName */
  "regionprops",                       /* fName */
  "C:\\Program Files\\MATLAB\\R2016b\\toolbox\\images\\images\\eml\\regionprops.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo vc_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  244,                                 /* lineNo */
  61,                                  /* colNo */
  "",                                  /* aName */
  "regionprops",                       /* fName */
  "C:\\Program Files\\MATLAB\\R2016b\\toolbox\\images\\images\\eml\\regionprops.m",/* pName */
  0                                    /* checkKind */
};

static emlrtECInfo d_emlrtECI = { -1,  /* nDims */
  1043,                                /* lineNo */
  21,                                  /* colNo */
  "regionprops",                       /* fName */
  "C:\\Program Files\\MATLAB\\R2016b\\toolbox\\images\\images\\eml\\regionprops.m"/* pName */
};

static emlrtBCInfo wc_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  1043,                                /* lineNo */
  21,                                  /* colNo */
  "",                                  /* aName */
  "regionprops",                       /* fName */
  "C:\\Program Files\\MATLAB\\R2016b\\toolbox\\images\\images\\eml\\regionprops.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo xc_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  1035,                                /* lineNo */
  24,                                  /* colNo */
  "",                                  /* aName */
  "regionprops",                       /* fName */
  "C:\\Program Files\\MATLAB\\R2016b\\toolbox\\images\\images\\eml\\regionprops.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo yc_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  674,                                 /* lineNo */
  41,                                  /* colNo */
  "",                                  /* aName */
  "regionprops",                       /* fName */
  "C:\\Program Files\\MATLAB\\R2016b\\toolbox\\images\\images\\eml\\regionprops.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo ad_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  673,                                 /* lineNo */
  21,                                  /* colNo */
  "",                                  /* aName */
  "regionprops",                       /* fName */
  "C:\\Program Files\\MATLAB\\R2016b\\toolbox\\images\\images\\eml\\regionprops.m",/* pName */
  0                                    /* checkKind */
};

static emlrtRTEInfo vc_emlrtRTEI = { 38,/* lineNo */
  15,                                  /* colNo */
  "ind2sub",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2016b\\toolbox\\eml\\lib\\matlab\\elmat\\ind2sub.m"/* pName */
};

static emlrtRTEInfo wc_emlrtRTEI = { 281,/* lineNo */
  27,                                  /* colNo */
  "cat",                               /* fName */
  "C:\\Program Files\\MATLAB\\R2016b\\toolbox\\eml\\eml\\+coder\\+internal\\cat.m"/* pName */
};

static emlrtBCInfo bd_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  1749,                                /* lineNo */
  50,                                  /* colNo */
  "",                                  /* aName */
  "regionprops",                       /* fName */
  "C:\\Program Files\\MATLAB\\R2016b\\toolbox\\images\\images\\eml\\regionprops.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo cd_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  1749,                                /* lineNo */
  9,                                   /* colNo */
  "",                                  /* aName */
  "regionprops",                       /* fName */
  "C:\\Program Files\\MATLAB\\R2016b\\toolbox\\images\\images\\eml\\regionprops.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo dd_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  1750,                                /* lineNo */
  28,                                  /* colNo */
  "",                                  /* aName */
  "regionprops",                       /* fName */
  "C:\\Program Files\\MATLAB\\R2016b\\toolbox\\images\\images\\eml\\regionprops.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo ed_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  1751,                                /* lineNo */
  45,                                  /* colNo */
  "",                                  /* aName */
  "regionprops",                       /* fName */
  "C:\\Program Files\\MATLAB\\R2016b\\toolbox\\images\\images\\eml\\regionprops.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo fd_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  1751,                                /* lineNo */
  13,                                  /* colNo */
  "",                                  /* aName */
  "regionprops",                       /* fName */
  "C:\\Program Files\\MATLAB\\R2016b\\toolbox\\images\\images\\eml\\regionprops.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo gd_emlrtBCI = { 1,  /* iFirst */
  307200,                              /* iLast */
  1033,                                /* lineNo */
  21,                                  /* colNo */
  "",                                  /* aName */
  "regionprops",                       /* fName */
  "C:\\Program Files\\MATLAB\\R2016b\\toolbox\\images\\images\\eml\\regionprops.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo hd_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  1047,                                /* lineNo */
  9,                                   /* colNo */
  "",                                  /* aName */
  "regionprops",                       /* fName */
  "C:\\Program Files\\MATLAB\\R2016b\\toolbox\\images\\images\\eml\\regionprops.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo id_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  678,                                 /* lineNo */
  13,                                  /* colNo */
  "",                                  /* aName */
  "regionprops",                       /* fName */
  "C:\\Program Files\\MATLAB\\R2016b\\toolbox\\images\\images\\eml\\regionprops.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo jd_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  676,                                 /* lineNo */
  13,                                  /* colNo */
  "",                                  /* aName */
  "regionprops",                       /* fName */
  "C:\\Program Files\\MATLAB\\R2016b\\toolbox\\images\\images\\eml\\regionprops.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo kd_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  244,                                 /* lineNo */
  9,                                   /* colNo */
  "",                                  /* aName */
  "regionprops",                       /* fName */
  "C:\\Program Files\\MATLAB\\R2016b\\toolbox\\images\\images\\eml\\regionprops.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo ld_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  1033,                                /* lineNo */
  23,                                  /* colNo */
  "",                                  /* aName */
  "regionprops",                       /* fName */
  "C:\\Program Files\\MATLAB\\R2016b\\toolbox\\images\\images\\eml\\regionprops.m",/* pName */
  0                                    /* checkKind */
};

/* Function Declarations */
static void initializeStatsStruct(const emlrtStack *sp, real_T numObjs,
  b_emxArray_struct_T *stats, struct_T *statsAlreadyComputed);

/* Function Definitions */
static void initializeStatsStruct(const emlrtStack *sp, real_T numObjs,
  b_emxArray_struct_T *stats, struct_T *statsAlreadyComputed)
{
  c_struct_T statsOneObj;
  int32_T i25;
  int32_T loop_ub;
  emlrtStack st;
  emlrtStack b_st;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b(sp);
  emxInitStruct_struct_T(sp, &statsOneObj, &ub_emlrtRTEI, true);
  statsAlreadyComputed->Area = false;
  statsOneObj.Area = 0.0;
  statsAlreadyComputed->Centroid = false;
  for (i25 = 0; i25 < 2; i25++) {
    statsOneObj.Centroid[i25] = 0.0;
  }

  statsAlreadyComputed->BoundingBox = false;
  for (i25 = 0; i25 < 4; i25++) {
    statsOneObj.BoundingBox[i25] = 0.0;
  }

  statsAlreadyComputed->MajorAxisLength = false;
  statsOneObj.MajorAxisLength = 0.0;
  statsAlreadyComputed->MinorAxisLength = false;
  statsOneObj.MinorAxisLength = 0.0;
  statsAlreadyComputed->Eccentricity = false;
  statsOneObj.Eccentricity = 0.0;
  statsAlreadyComputed->Orientation = false;
  statsOneObj.Orientation = 0.0;
  statsAlreadyComputed->Image = false;
  statsOneObj.Image.size[0] = 0;
  statsOneObj.Image.size[1] = 0;
  statsAlreadyComputed->FilledImage = false;
  statsOneObj.FilledImage.size[0] = 0;
  statsOneObj.FilledImage.size[1] = 0;
  statsAlreadyComputed->FilledArea = false;
  statsOneObj.FilledArea = 0.0;
  statsAlreadyComputed->EulerNumber = false;
  statsOneObj.EulerNumber = 0.0;
  statsAlreadyComputed->Extrema = false;
  memset(&statsOneObj.Extrema[0], 0, sizeof(real_T) << 4);
  statsAlreadyComputed->EquivDiameter = false;
  statsOneObj.EquivDiameter = 0.0;
  statsAlreadyComputed->Extent = false;
  statsOneObj.Extent = 0.0;
  statsAlreadyComputed->PixelIdxList = false;
  i25 = statsOneObj.PixelIdxList->size[0];
  statsOneObj.PixelIdxList->size[0] = 0;
  emxEnsureCapacity(sp, (emxArray__common *)statsOneObj.PixelIdxList, i25,
                    (int32_T)sizeof(real_T), &tb_emlrtRTEI);
  statsAlreadyComputed->PixelList = false;
  i25 = statsOneObj.PixelList->size[0] * statsOneObj.PixelList->size[1];
  statsOneObj.PixelList->size[0] = 0;
  statsOneObj.PixelList->size[1] = 2;
  emxEnsureCapacity(sp, (emxArray__common *)statsOneObj.PixelList, i25, (int32_T)
                    sizeof(real_T), &tb_emlrtRTEI);
  statsAlreadyComputed->Perimeter = false;
  statsOneObj.Perimeter = 0.0;
  statsAlreadyComputed->PixelValues = false;
  statsOneObj.PixelValues.size[0] = 0;
  statsAlreadyComputed->WeightedCentroid = false;
  for (i25 = 0; i25 < 2; i25++) {
    statsOneObj.WeightedCentroid[i25] = 0.0;
  }

  statsAlreadyComputed->MeanIntensity = false;
  statsOneObj.MeanIntensity = 0.0;
  statsAlreadyComputed->MinIntensity = false;
  statsOneObj.MinIntensity = 0.0;
  statsAlreadyComputed->MaxIntensity = false;
  statsOneObj.MaxIntensity = 0.0;
  statsAlreadyComputed->SubarrayIdx = false;
  statsOneObj.SubarrayIdx.size[0] = 1;
  statsOneObj.SubarrayIdx.size[1] = 0;
  for (i25 = 0; i25 < 2; i25++) {
    statsOneObj.SubarrayIdxLengths[i25] = 0.0;
  }

  st.site = &kg_emlrtRSI;
  b_st.site = &jg_emlrtRSI;
  assertValidSizeArg(&b_st, numObjs);
  i25 = stats->size[0];
  stats->size[0] = (int32_T)numObjs;
  emxEnsureCapacity_struct_T(&st, stats, i25, &tb_emlrtRTEI);
  loop_ub = (int32_T)numObjs;
  for (i25 = 0; i25 < loop_ub; i25++) {
    emxCopyStruct_struct_T(&st, &stats->data[i25], &statsOneObj, &tb_emlrtRTEI);
  }

  emxFreeStruct_struct_T(&statsOneObj);
  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

void regionprops(const emlrtStack *sp, const boolean_T varargin_1[307200], const
                 real_T varargin_2[307200], emxArray_struct_T *outstats)
{
  emxArray_real_T *CC_RegionIndices;
  emxArray_int32_T *CC_RegionLengths;
  real_T sumIntensity;
  real_T wc[2];
  real_T CC_NumObjects;
  boolean_T p;
  boolean_T b_p;
  int32_T k;
  boolean_T exitg2;
  b_struct_T statsOneObj;
  int32_T i21;
  b_emxArray_struct_T *stats;
  b_emxArray_struct_T *b_stats;
  struct_T statsAlreadyComputed;
  int32_T loop_ub;
  emxArray_int32_T *idxCount;
  emxArray_int32_T *idx;
  int32_T dim;
  emxArray_real_T *Intensity;
  emxArray_int32_T *j;
  int32_T vstride;
  int32_T i22;
  emxArray_real_T *c_stats;
  int32_T exitg1;
  real_T A;
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack f_st;
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
  f_st.prev = &e_st;
  f_st.tls = e_st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b(sp);
  emxInit_real_T(sp, &CC_RegionIndices, 1, &kb_emlrtRTEI, true);
  emxInit_int32_T(sp, &CC_RegionLengths, 1, &kb_emlrtRTEI, true);
  st.site = &ff_emlrtRSI;
  bwconncomp(&st, varargin_1, &sumIntensity, wc, &CC_NumObjects,
             CC_RegionIndices, CC_RegionLengths);
  st.site = &gf_emlrtRSI;
  p = false;
  b_p = true;
  k = 0;
  exitg2 = false;
  while ((!exitg2) && (k < 2)) {
    if (!(wc[k] == 480.0 + 160.0 * (real_T)k)) {
      b_p = false;
      exitg2 = true;
    } else {
      k++;
    }
  }

  if (b_p) {
    p = true;
  }

  if (!p) {
    emlrtErrorWithMessageIdR2012b(&st, &uc_emlrtRTEI,
      "images:regionprops:sizeMismatch", 0);
  }

  b_st.site = &hg_emlrtRSI;
  for (i21 = 0; i21 < 2; i21++) {
    statsOneObj.WeightedCentroid[i21] = 0.0;
  }

  c_st.site = &ig_emlrtRSI;
  d_st.site = &jg_emlrtRSI;
  assertValidSizeArg(&d_st, CC_NumObjects);
  emxInit_struct_T1(&c_st, &stats, 1, &kb_emlrtRTEI, true);
  emxInit_struct_T1(&c_st, &b_stats, 1, &kb_emlrtRTEI, true);
  st.site = &hf_emlrtRSI;
  initializeStatsStruct(&st, CC_NumObjects, b_stats, &statsAlreadyComputed);
  st.site = &if_emlrtRSI;
  i21 = stats->size[0];
  stats->size[0] = b_stats->size[0];
  emxEnsureCapacity_struct_T(&st, stats, i21, &kb_emlrtRTEI);
  loop_ub = b_stats->size[0];
  for (i21 = 0; i21 < loop_ub; i21++) {
    emxCopyStruct_struct_T(&st, &stats->data[i21], &b_stats->data[i21],
      &kb_emlrtRTEI);
  }

  emxInit_int32_T(&st, &idxCount, 1, &lb_emlrtRTEI, true);
  emxInit_int32_T(&st, &idx, 1, &nb_emlrtRTEI, true);
  if (CC_NumObjects != 0.0) {
    b_st.site = &lg_emlrtRSI;
    c_st.site = &cg_emlrtRSI;
    dim = 2;
    if (CC_RegionLengths->size[0] != 1) {
      dim = 1;
    }

    d_st.site = &dg_emlrtRSI;
    i21 = idx->size[0];
    idx->size[0] = CC_RegionLengths->size[0];
    emxEnsureCapacity(&d_st, (emxArray__common *)idx, i21, (int32_T)sizeof
                      (int32_T), &kb_emlrtRTEI);
    loop_ub = CC_RegionLengths->size[0];
    for (i21 = 0; i21 < loop_ub; i21++) {
      idx->data[i21] = CC_RegionLengths->data[i21];
    }

    if (dim <= 1) {
      i21 = CC_RegionLengths->size[0];
    } else {
      i21 = 1;
    }

    if ((!(CC_RegionLengths->size[0] == 0)) && (i21 > 1)) {
      e_st.site = &eg_emlrtRSI;
      vstride = 1;
      k = 1;
      while (k <= dim - 1) {
        vstride *= CC_RegionLengths->size[0];
        k = 2;
      }

      e_st.site = &fg_emlrtRSI;
      if ((!(1 > vstride)) && (vstride > 2147483646)) {
        f_st.site = &w_emlrtRSI;
        check_forloop_overflow_error(&f_st);
      }

      for (dim = 0; dim + 1 <= vstride; dim++) {
        e_st.site = &gg_emlrtRSI;
        for (k = 1; k < i21; k++) {
          idx->data[dim + k * vstride] += idx->data[dim + (k - 1) * vstride];
        }
      }
    }

    i21 = idxCount->size[0];
    idxCount->size[0] = 1 + idx->size[0];
    emxEnsureCapacity(&st, (emxArray__common *)idxCount, i21, (int32_T)sizeof
                      (int32_T), &kb_emlrtRTEI);
    idxCount->data[0] = 0;
    loop_ub = idx->size[0];
    for (i21 = 0; i21 < loop_ub; i21++) {
      idxCount->data[i21 + 1] = idx->data[i21];
    }

    for (k = 0; k < b_stats->size[0]; k++) {
      i21 = idxCount->size[0];
      i22 = k + 1;
      if (!((i22 >= 1) && (i22 <= i21))) {
        emlrtDynamicBoundsCheckR2012b(i22, 1, i21, &uc_emlrtBCI, &st);
      }

      i21 = idxCount->size[0];
      i22 = (int32_T)((1.0 + (real_T)k) + 1.0);
      if (!((i22 >= 1) && (i22 <= i21))) {
        emlrtDynamicBoundsCheckR2012b(i22, 1, i21, &vc_emlrtBCI, &st);
      }

      if (idxCount->data[k] + 1 > idxCount->data[(int32_T)((1.0 + (real_T)k) +
           1.0) - 1]) {
        i21 = 0;
        dim = 0;
      } else {
        i21 = CC_RegionIndices->size[0];
        i22 = idxCount->data[k] + 1;
        if (!((i22 >= 1) && (i22 <= i21))) {
          emlrtDynamicBoundsCheckR2012b(i22, 1, i21, &uc_emlrtBCI, &st);
        }

        i21 = i22 - 1;
        i22 = CC_RegionIndices->size[0];
        dim = idxCount->data[(int32_T)((1.0 + (real_T)k) + 1.0) - 1];
        if (!((dim >= 1) && (dim <= i22))) {
          emlrtDynamicBoundsCheckR2012b(dim, 1, i22, &uc_emlrtBCI, &st);
        }
      }

      vstride = stats->size[0];
      i22 = 1 + k;
      if (!((i22 >= 1) && (i22 <= vstride))) {
        emlrtDynamicBoundsCheckR2012b(i22, 1, vstride, &kd_emlrtBCI, &st);
      }

      i22 = stats->data[k].PixelIdxList->size[0];
      stats->data[k].PixelIdxList->size[0] = dim - i21;
      emxEnsureCapacity(&st, (emxArray__common *)stats->data[k].PixelIdxList,
                        i22, (int32_T)sizeof(real_T), &kb_emlrtRTEI);
      loop_ub = dim - i21;
      for (i22 = 0; i22 < loop_ub; i22++) {
        dim = 1 + k;
        if (!((dim >= 1) && (dim <= vstride))) {
          emlrtDynamicBoundsCheckR2012b(dim, 1, vstride, &kd_emlrtBCI, &st);
        }

        stats->data[dim - 1].PixelIdxList->data[i22] = CC_RegionIndices->
          data[i21 + i22];
      }
    }
  }

  emxFree_int32_T(&CC_RegionLengths);
  emxFree_real_T(&CC_RegionIndices);
  st.site = &jf_emlrtRSI;
  b_st.site = &og_emlrtRSI;
  i21 = b_stats->size[0];
  b_stats->size[0] = stats->size[0];
  emxEnsureCapacity_struct_T(&b_st, b_stats, i21, &kb_emlrtRTEI);
  loop_ub = stats->size[0];
  for (i21 = 0; i21 < loop_ub; i21++) {
    emxCopyStruct_struct_T(&b_st, &b_stats->data[i21], &stats->data[i21],
      &kb_emlrtRTEI);
  }

  k = 1;
  emxInit_real_T(&b_st, &Intensity, 1, &mb_emlrtRTEI, true);
  emxInit_int32_T(&b_st, &j, 1, &kb_emlrtRTEI, true);
  while (k - 1 <= stats->size[0] - 1) {
    i21 = b_stats->size[0];
    i22 = (k - 1) + 1;
    if (!((i22 >= 1) && (i22 <= i21))) {
      emlrtDynamicBoundsCheckR2012b(i22, 1, i21, &ad_emlrtBCI, &b_st);
    }

    if (!(b_stats->data[k - 1].PixelIdxList->size[0] == 0)) {
      c_st.site = &qg_emlrtRSI;
      i21 = b_stats->size[0];
      i22 = (k - 1) + 1;
      if (!((i22 >= 1) && (i22 <= i21))) {
        emlrtDynamicBoundsCheckR2012b(i22, 1, i21, &yc_emlrtBCI, &c_st);
      }

      d_st.site = &rg_emlrtRSI;
      i21 = idx->size[0];
      idx->size[0] = b_stats->data[k - 1].PixelIdxList->size[0];
      emxEnsureCapacity(&d_st, (emxArray__common *)idx, i21, (int32_T)sizeof
                        (int32_T), &kb_emlrtRTEI);
      loop_ub = b_stats->data[k - 1].PixelIdxList->size[0];
      for (i21 = 0; i21 < loop_ub; i21++) {
        idx->data[i21] = (int32_T)b_stats->data[k - 1].PixelIdxList->data[i21];
      }

      dim = 0;
      do {
        exitg1 = 0;
        if (dim <= idx->size[0] - 1) {
          p = (idx->data[dim] >= 1);
          if (!p) {
            p = false;
            exitg1 = 1;
          } else {
            dim++;
          }
        } else {
          p = true;
          exitg1 = 1;
        }
      } while (exitg1 == 0);

      if (!p) {
        emlrtErrorWithMessageIdR2012b(&d_st, &vc_emlrtRTEI,
          "Coder:MATLAB:ind2sub_IndexOutOfRange", 0);
      }

      i21 = idx->size[0];
      emxEnsureCapacity(&d_st, (emxArray__common *)idx, i21, (int32_T)sizeof
                        (int32_T), &kb_emlrtRTEI);
      loop_ub = idx->size[0];
      for (i21 = 0; i21 < loop_ub; i21++) {
        idx->data[i21]--;
      }

      i21 = idxCount->size[0];
      idxCount->size[0] = idx->size[0];
      emxEnsureCapacity(&d_st, (emxArray__common *)idxCount, i21, (int32_T)
                        sizeof(int32_T), &kb_emlrtRTEI);
      loop_ub = idx->size[0];
      for (i21 = 0; i21 < loop_ub; i21++) {
        idxCount->data[i21] = idx->data[i21] / 480;
      }

      i21 = idx->size[0];
      emxEnsureCapacity(&d_st, (emxArray__common *)idx, i21, (int32_T)sizeof
                        (int32_T), &kb_emlrtRTEI);
      loop_ub = idx->size[0];
      for (i21 = 0; i21 < loop_ub; i21++) {
        idx->data[i21] -= idxCount->data[i21] * 480;
      }

      i21 = Intensity->size[0];
      Intensity->size[0] = idx->size[0];
      emxEnsureCapacity(&c_st, (emxArray__common *)Intensity, i21, (int32_T)
                        sizeof(real_T), &kb_emlrtRTEI);
      loop_ub = idx->size[0];
      for (i21 = 0; i21 < loop_ub; i21++) {
        Intensity->data[i21] = idx->data[i21] + 1;
      }

      i21 = j->size[0];
      j->size[0] = idxCount->size[0];
      emxEnsureCapacity(&c_st, (emxArray__common *)j, i21, (int32_T)sizeof
                        (int32_T), &kb_emlrtRTEI);
      loop_ub = idxCount->size[0];
      for (i21 = 0; i21 < loop_ub; i21++) {
        j->data[i21] = idxCount->data[i21] + 1;
      }

      c_st.site = &pg_emlrtRSI;
      d_st.site = &sg_emlrtRSI;
      e_st.site = &tg_emlrtRSI;
      p = true;
      if (j->size[0] != Intensity->size[0]) {
        p = false;
      }

      if (!p) {
        emlrtErrorWithMessageIdR2012b(&e_st, &wc_emlrtRTEI,
          "MATLAB:catenate:matrixDimensionMismatch", 0);
      }

      vstride = b_stats->size[0];
      if (!((k >= 1) && (k <= vstride))) {
        emlrtDynamicBoundsCheckR2012b(k, 1, vstride, &jd_emlrtBCI, &d_st);
      }

      i21 = b_stats->data[k - 1].PixelList->size[0] * b_stats->data[k - 1].
        PixelList->size[1];
      b_stats->data[k - 1].PixelList->size[0] = j->size[0];
      if (!((k >= 1) && (k <= vstride))) {
        emlrtDynamicBoundsCheckR2012b(k, 1, vstride, &jd_emlrtBCI, &d_st);
      }

      b_stats->data[k - 1].PixelList->size[1] = 2;
      emxEnsureCapacity(&d_st, (emxArray__common *)b_stats->data[k - 1].
                        PixelList, i21, (int32_T)sizeof(real_T), &kb_emlrtRTEI);
      loop_ub = j->size[0];
      for (i21 = 0; i21 < loop_ub; i21++) {
        if (!((k >= 1) && (k <= vstride))) {
          emlrtDynamicBoundsCheckR2012b(k, 1, vstride, &jd_emlrtBCI, &d_st);
          emlrtDynamicBoundsCheckR2012b(k, 1, vstride, &jd_emlrtBCI, &d_st);
        }

        b_stats->data[k - 1].PixelList->data[i21] = j->data[i21];
      }

      loop_ub = Intensity->size[0];
      for (i21 = 0; i21 < loop_ub; i21++) {
        if (!((k >= 1) && (k <= vstride))) {
          emlrtDynamicBoundsCheckR2012b(k, 1, vstride, &jd_emlrtBCI, &d_st);
          emlrtDynamicBoundsCheckR2012b(k, 1, vstride, &jd_emlrtBCI, &d_st);
        }

        b_stats->data[k - 1].PixelList->data[i21 + b_stats->data[k - 1].
          PixelList->size[0]] = Intensity->data[i21];
      }
    } else {
      i21 = b_stats->size[0];
      if (!((k >= 1) && (k <= i21))) {
        emlrtDynamicBoundsCheckR2012b(k, 1, i21, &id_emlrtBCI, &b_st);
      }

      i21 = k - 1;
      i22 = b_stats->data[i21].PixelList->size[0] * b_stats->data[i21].
        PixelList->size[1];
      b_stats->data[i21].PixelList->size[0] = 0;
      i21 = b_stats->size[0];
      if (!((k >= 1) && (k <= i21))) {
        emlrtDynamicBoundsCheckR2012b(k, 1, i21, &id_emlrtBCI, &b_st);
      }

      i21 = k - 1;
      b_stats->data[i21].PixelList->size[1] = 2;
      emxEnsureCapacity(&b_st, (emxArray__common *)b_stats->data[i21].PixelList,
                        i22, (int32_T)sizeof(real_T), &kb_emlrtRTEI);
      vstride = b_stats->size[0];
      if (!((k >= 1) && (k <= vstride))) {
        emlrtDynamicBoundsCheckR2012b(k, 1, vstride, &id_emlrtBCI, &b_st);
      }

      vstride = b_stats->size[0];
      if (!((k >= 1) && (k <= vstride))) {
        emlrtDynamicBoundsCheckR2012b(k, 1, vstride, &id_emlrtBCI, &b_st);
      }
    }

    k++;
  }

  emxFree_int32_T(&idx);
  emxFree_int32_T(&j);
  emxFree_int32_T(&idxCount);
  i21 = stats->size[0];
  stats->size[0] = b_stats->size[0];
  emxEnsureCapacity_struct_T(&st, stats, i21, &kb_emlrtRTEI);
  loop_ub = b_stats->size[0];
  for (i21 = 0; i21 < loop_ub; i21++) {
    emxCopyStruct_struct_T(&st, &stats->data[i21], &b_stats->data[i21],
      &kb_emlrtRTEI);
  }

  k = 0;
  emxInit_real_T(&st, &c_stats, 1, &kb_emlrtRTEI, true);
  while (k <= b_stats->size[0] - 1) {
    i21 = Intensity->size[0];
    i22 = stats->size[0];
    dim = 1 + k;
    if (!((dim >= 1) && (dim <= i22))) {
      emlrtDynamicBoundsCheckR2012b(dim, 1, i22, &ld_emlrtBCI, &st);
    }

    Intensity->size[0] = stats->data[dim - 1].PixelIdxList->size[0];
    emxEnsureCapacity(&st, (emxArray__common *)Intensity, i21, (int32_T)sizeof
                      (real_T), &kb_emlrtRTEI);
    i21 = stats->size[0];
    i22 = 1 + k;
    if (!((i22 >= 1) && (i22 <= i21))) {
      emlrtDynamicBoundsCheckR2012b(i22, 1, i21, &ld_emlrtBCI, &st);
    }

    loop_ub = stats->data[i22 - 1].PixelIdxList->size[0];
    for (i21 = 0; i21 < loop_ub; i21++) {
      i22 = stats->size[0];
      dim = 1 + k;
      if (!((dim >= 1) && (dim <= i22))) {
        emlrtDynamicBoundsCheckR2012b(dim, 1, i22, &ld_emlrtBCI, &st);
      }

      i22 = (int32_T)stats->data[dim - 1].PixelIdxList->data[i21];
      if (!((i22 >= 1) && (i22 <= 307200))) {
        emlrtDynamicBoundsCheckR2012b(i22, 1, 307200, &gd_emlrtBCI, &st);
      }

      Intensity->data[i21] = varargin_2[i22 - 1];
    }

    b_st.site = &ng_emlrtRSI;
    sumIntensity = b_sum(&b_st, Intensity);
    i21 = stats->size[0];
    i22 = k + 1;
    if (!((i22 >= 1) && (i22 <= i21))) {
      emlrtDynamicBoundsCheckR2012b(i22, 1, i21, &xc_emlrtBCI, &st);
    }

    for (vstride = 0; vstride < 2; vstride++) {
      i21 = stats->size[0];
      i22 = k + 1;
      if (!((i22 >= 1) && (i22 <= i21))) {
        emlrtDynamicBoundsCheckR2012b(i22, 1, i21, &wc_emlrtBCI, &st);
      }

      i21 = stats->data[k].PixelList->size[0];
      dim = stats->data[k].PixelIdxList->size[0];
      if (i21 != dim) {
        emlrtSizeEqCheck1DR2012b(i21, dim, &d_emlrtECI, &st);
      }

      loop_ub = stats->data[k].PixelList->size[0];
      i21 = c_stats->size[0];
      c_stats->size[0] = loop_ub;
      emxEnsureCapacity(&st, (emxArray__common *)c_stats, i21, (int32_T)sizeof
                        (real_T), &kb_emlrtRTEI);
      for (i21 = 0; i21 < loop_ub; i21++) {
        c_stats->data[i21] = stats->data[k].PixelList->data[i21 + stats->data[k]
          .PixelList->size[0] * vstride] * Intensity->data[i21];
      }

      b_st.site = &mg_emlrtRSI;
      A = b_sum(&b_st, c_stats);
      wc[vstride] = A / sumIntensity;
    }

    vstride = stats->size[0];
    for (i21 = 0; i21 < 2; i21++) {
      i22 = 1 + k;
      if (!((i22 >= 1) && (i22 <= vstride))) {
        emlrtDynamicBoundsCheckR2012b(i22, 1, vstride, &hd_emlrtBCI, &st);
      }

      stats->data[i22 - 1].WeightedCentroid[i21] = wc[i21];
    }

    k++;
  }

  emxFree_real_T(&c_stats);
  emxFree_real_T(&Intensity);
  emxFree_struct_T1(&b_stats);
  st.site = &kf_emlrtRSI;
  i21 = outstats->size[0];
  outstats->size[0] = (int32_T)CC_NumObjects;
  emxEnsureCapacity(&st, (emxArray__common *)outstats, i21, (int32_T)sizeof
                    (b_struct_T), &kb_emlrtRTEI);
  loop_ub = (int32_T)CC_NumObjects;
  for (i21 = 0; i21 < loop_ub; i21++) {
    outstats->data[i21] = statsOneObj;
  }

  for (k = 0; k < stats->size[0]; k++) {
    i21 = stats->size[0];
    i22 = k + 1;
    if (!((i22 >= 1) && (i22 <= i21))) {
      emlrtDynamicBoundsCheckR2012b(i22, 1, i21, &bd_emlrtBCI, &st);
    }

    i21 = outstats->size[0];
    if (!((k + 1 >= 1) && (k + 1 <= i21))) {
      emlrtDynamicBoundsCheckR2012b(k + 1, 1, i21, &cd_emlrtBCI, &st);
    }

    i21 = outstats->size[0];
    i22 = k + 1;
    if (!((i22 >= 1) && (i22 <= i21))) {
      emlrtDynamicBoundsCheckR2012b(i22, 1, i21, &dd_emlrtBCI, &st);
    }

    for (dim = 0; dim < 2; dim++) {
      i21 = stats->size[0];
      if (!((k + 1 >= 1) && (k + 1 <= i21))) {
        emlrtDynamicBoundsCheckR2012b(k + 1, 1, i21, &ed_emlrtBCI, &st);
      }

      i21 = outstats->size[0];
      if (!((k + 1 >= 1) && (k + 1 <= i21))) {
        emlrtDynamicBoundsCheckR2012b(k + 1, 1, i21, &fd_emlrtBCI, &st);
      }

      outstats->data[k].WeightedCentroid[dim] = stats->data[k]
        .WeightedCentroid[dim];
    }
  }

  emxFree_struct_T1(&stats);
  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

/* End of code generation (regionprops.c) */
