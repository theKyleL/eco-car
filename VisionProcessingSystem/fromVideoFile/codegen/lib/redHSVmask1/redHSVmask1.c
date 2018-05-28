/*
 * Sponsored License - for use in support of a program or activity
 * sponsored by MathWorks.  Not for government, commercial or other
 * non-sponsored organizational use.
 * File: redHSVmask1.c
 *
 * MATLAB Coder version            : 3.2
 * C/C++ source code generated on  : 05-Nov-2016 17:02:46
 */

/* Include Files */
#include "rt_nonfinite.h"
#include "redHSVmask1.h"
#include "libmwrgb2hsv_tbb.h"

/* Function Definitions */

/*
 * createMask  Threshold RGB image using auto-generated code from colorThresholder app.
 *   [BW,MASKEDRGBIMAGE] = createMask(RGB) thresholds image RGB using
 *   auto-generated code from the colorThresholder App. The colorspace and
 *   minimum/maximum values for each channel of the colorspace were set in the
 *   App and result in a binary mask BW and a composite image maskedRGBImage,
 *   which shows the original RGB image values under the mask BW.
 * Arguments    : const unsigned char RGB[921600]
 *                boolean_T BW[307200]
 * Return Type  : void
 */
void redHSVmask1(const unsigned char RGB[921600], boolean_T BW[307200])
{
  static double I[921600];
  int i0;
  int i1;

  /*  Auto-generated by colorThresholder app on 03-Nov-2016 */
  /* ------------------------------------------------------ */
  /*  Convert RGB image to chosen color space */
  rgb2hsv_tbb_uint8(RGB, 307200.0, I);

  /*  Define thresholds for channel 1 based on histogram settings */
  /*  Define thresholds for channel 2 based on histogram settings */
  /*  Define thresholds for channel 3 based on histogram settings */
  /*  Create mask based on chosen histogram thresholds */
  for (i0 = 0; i0 < 640; i0++) {
    for (i1 = 0; i1 < 480; i1++) {
      BW[i1 + 480 * i0] = (((I[i1 + 480 * i0] >= 0.951) || (I[i1 + 480 * i0] <=
        0.049)) && (I[307200 + (i1 + 480 * i0)] >= 0.451) && (I[307200 + (i1 +
        480 * i0)] <= 1.0) && (I[614400 + (i1 + 480 * i0)] >= 0.0) && (I[614400
        + (i1 + 480 * i0)] <= 1.0));
    }
  }

  /*  Initialize output masked image based on input image. */
  /*  Set background pixels where BW is false to zero. */
}

/*
 * File trailer for redHSVmask1.c
 *
 * [EOF]
 */
