#include "..\..\TYPES.H"
#include "LPL_TYPES.H"
#include "SPM_EQU.H"
#include "FLASH.H"
#include "LPLMAIN.H"

static void fadein1(void);
static void fadein2(PALETTEENTRY* lpPeDest, PALETTEENTRY* lpPeSrc);
static int fadeout_new(void);
static void fadeout1(void);
static void fadeout2(PALETTEENTRY* lpPeDest);
static int flashin_new(void);
static void flashin1(void);
static void flashin2(PALETTEENTRY* lpPeDest, PALETTEENTRY* lpPeSrc);
static int flashout_new(void);
static void flashout1(void);
static void flashout2(PALETTEENTRY* lpPeDest);

static int FadeCount;


























void fadein(void) { /* Line 46, Address: 0x10039f0 */
  startcolor = 0; /* Line 47, Address: 0x10039f8 */
  colorcnt = 63; /* Line 48, Address: 0x1003a00 */
  fadein0(); /* Line 49, Address: 0x1003a0c */
} /* Line 50, Address: 0x1003a14 */


void fadein0(void) { /* Line 53, Address: 0x1003a30 */
  PALETTEENTRY* lpPe;
  int i;

  lpPe = &lpcolorwk0[startcolor / 2]; /* Line 57, Address: 0x1003a3c */

  for (i = 0; colorcnt >= i; ++i) { /* Line 59, Address: 0x1003a70 */
    lpPe->peRed = 0; /* Line 60, Address: 0x1003a7c */
    lpPe->peGreen = 0; /* Line 61, Address: 0x1003a80 */
    lpPe->peBlue = 0; /* Line 62, Address: 0x1003a84 */
    lpPe->peFlags = 1; /* Line 63, Address: 0x1003a88 */
    ++lpPe; /* Line 64, Address: 0x1003a90 */
  } /* Line 65, Address: 0x1003a94 */
  FadeCount = 0; /* Line 66, Address: 0x1003ab0 */
  *lpFadeFlag = 1; /* Line 67, Address: 0x1003ab8 */

} /* Line 69, Address: 0x1003ac8 */



int fadein0_new(void) { /* Line 73, Address: 0x1003ae0 */

  int_flg = 10; /* Line 75, Address: 0x1003ae8 */

  fadein1(); /* Line 77, Address: 0x1003af4 */


  if (++FadeCount > 21) { /* Line 80, Address: 0x1003afc */
    FadeCount = 0; /* Line 81, Address: 0x1003b1c */
    return 1; /* Line 82, Address: 0x1003b24 */
  }
  return 0; /* Line 84, Address: 0x1003b30 */
} /* Line 85, Address: 0x1003b34 */



static void fadein1(void) { /* Line 89, Address: 0x1003b50 */
  PALETTEENTRY *lpPe, *lpPe2;
  int i;

  lpPe = &lpcolorwk0[startcolor / 2]; /* Line 93, Address: 0x1003b64 */
  lpPe2 = &lpcolorwk1[startcolor / 2]; /* Line 94, Address: 0x1003b98 */

  for (i = 0; colorcnt >= i; ++i) { /* Line 96, Address: 0x1003bcc */
    fadein2(lpPe, lpPe2); /* Line 97, Address: 0x1003bd8 */
    ++lpPe; /* Line 98, Address: 0x1003be8 */
    ++lpPe2; /* Line 99, Address: 0x1003bec */
  } /* Line 100, Address: 0x1003bf0 */










} /* Line 111, Address: 0x1003c0c */



static void fadein2(PALETTEENTRY* lpPeDest, PALETTEENTRY* lpPeSrc) { /* Line 115, Address: 0x1003c30 */
  if (lpPeSrc->peBlue != lpPeDest->peBlue /* Line 116, Address: 0x1003c3c */
      || lpPeSrc->peGreen != lpPeDest->peGreen
      || lpPeSrc->peRed != lpPeDest->peRed) {
    if (lpPeSrc->peBlue > lpPeDest->peBlue) { /* Line 119, Address: 0x1003c9c */
      lpPeDest->peBlue += 32; /* Line 120, Address: 0x1003cc0 */
    } /* Line 121, Address: 0x1003cd0 */
    else if (lpPeSrc->peGreen > lpPeDest->peGreen) { /* Line 122, Address: 0x1003cd8 */
      lpPeDest->peGreen += 32; /* Line 123, Address: 0x1003cfc */
    } /* Line 124, Address: 0x1003d0c */
    else if (lpPeSrc->peRed > lpPeDest->peRed) { /* Line 125, Address: 0x1003d14 */
      lpPeDest->peRed += 32; /* Line 126, Address: 0x1003d38 */
    }
  }

} /* Line 130, Address: 0x1003d4c */


void fadeout(void) {
  startcolor = 0; /* Line 134, Address: 0x1003d60 */
  colorcnt = 63; /* Line 135, Address: 0x1003d68 */

  FadeCount = 0; /* Line 137, Address: 0x1003d74 */
  *lpFadeFlag = 2; /* Line 138, Address: 0x1003d7c */

} /* Line 140, Address: 0x1003d8c */



static int fadeout_new(void) { /* Line 144, Address: 0x1003da0 */

  int_flg = 10; /* Line 146, Address: 0x1003da8 */

  fadeout1(); /* Line 148, Address: 0x1003db4 */


  if (++FadeCount > 21) { /* Line 151, Address: 0x1003dbc */
    FadeCount = 0; /* Line 152, Address: 0x1003ddc */
    return 1; /* Line 153, Address: 0x1003de4 */
  }
  return 0; /* Line 155, Address: 0x1003df0 */
} /* Line 156, Address: 0x1003df4 */


static void fadeout1(void) { /* Line 159, Address: 0x1003e10 */
  PALETTEENTRY* lpPe;
  int i;

  lpPe = &lpcolorwk0[startcolor / 2]; /* Line 163, Address: 0x1003e20 */

  for (i = 0; colorcnt >= i; ++i) { /* Line 165, Address: 0x1003e54 */
    fadeout2(lpPe); /* Line 166, Address: 0x1003e60 */
    ++lpPe; /* Line 167, Address: 0x1003e6c */
  } /* Line 168, Address: 0x1003e70 */
  lpPe = &lpcolorwk3[startcolor / 2]; /* Line 169, Address: 0x1003e8c */

  for (i = 0; colorcnt >= i; ++i) { /* Line 171, Address: 0x1003ec0 */
    fadeout2(lpPe); /* Line 172, Address: 0x1003ecc */
    ++lpPe; /* Line 173, Address: 0x1003ed8 */
  } /* Line 174, Address: 0x1003edc */


} /* Line 177, Address: 0x1003ef8 */


static void fadeout2(PALETTEENTRY* lpPeDest) { /* Line 180, Address: 0x1003f10 */
  if (lpPeDest->peRed) { /* Line 181, Address: 0x1003f18 */
    lpPeDest->peRed -= 32; /* Line 182, Address: 0x1003f28 */
  } /* Line 183, Address: 0x1003f3c */
  else if (lpPeDest->peGreen) { /* Line 184, Address: 0x1003f44 */
    lpPeDest->peGreen -= 32; /* Line 185, Address: 0x1003f54 */
  } /* Line 186, Address: 0x1003f64 */
  else if (lpPeDest->peBlue) { /* Line 187, Address: 0x1003f6c */
    lpPeDest->peBlue -= 32; /* Line 188, Address: 0x1003f7c */
  }

} /* Line 191, Address: 0x1003f8c */




void flashin(void) { /* Line 196, Address: 0x1003fa0 */
  PALETTEENTRY* lpPe;
  int i;

  startcolor = 0; /* Line 200, Address: 0x1003fac */
  colorcnt = 63; /* Line 201, Address: 0x1003fb4 */

  lpPe = &lpcolorwk0[startcolor / 2]; /* Line 203, Address: 0x1003fc0 */

  for (i = 0; colorcnt >= i; ++i) { /* Line 205, Address: 0x1003ff4 */
    lpPe->peRed = 224; /* Line 206, Address: 0x1004000 */
    lpPe->peGreen = 224; /* Line 207, Address: 0x1004008 */
    lpPe->peBlue = 224; /* Line 208, Address: 0x1004010 */
    lpPe->peFlags = 1; /* Line 209, Address: 0x1004018 */
    ++lpPe; /* Line 210, Address: 0x1004020 */
  } /* Line 211, Address: 0x1004024 */
  FadeCount = 0; /* Line 212, Address: 0x1004040 */
  *lpFadeFlag = 3; /* Line 213, Address: 0x1004048 */

} /* Line 215, Address: 0x1004058 */

static int flashin_new(void) { /* Line 217, Address: 0x1004070 */

  int_flg = 10; /* Line 219, Address: 0x1004078 */

  flashin1(); /* Line 221, Address: 0x1004084 */


  if (++FadeCount > 21) { /* Line 224, Address: 0x100408c */
    FadeCount = 0; /* Line 225, Address: 0x10040ac */
    return 1; /* Line 226, Address: 0x10040b4 */
  }
  return 0; /* Line 228, Address: 0x10040c0 */
} /* Line 229, Address: 0x10040c4 */

static void flashin1(void) { /* Line 231, Address: 0x10040e0 */
  PALETTEENTRY *lpPe, *lpPe2;
  int i;

  lpPe = &lpcolorwk0[startcolor / 2]; /* Line 235, Address: 0x10040f4 */
  lpPe2 = &lpcolorwk1[startcolor / 2]; /* Line 236, Address: 0x1004128 */

  for (i = 0; colorcnt >= i; ++i) { /* Line 238, Address: 0x100415c */
    flashin2(lpPe, lpPe2); /* Line 239, Address: 0x1004168 */
    ++lpPe; /* Line 240, Address: 0x1004178 */
    ++lpPe2; /* Line 241, Address: 0x100417c */
  } /* Line 242, Address: 0x1004180 */










} /* Line 253, Address: 0x100419c */



static void flashin2(PALETTEENTRY* lpPeDest, PALETTEENTRY* lpPeSrc) { /* Line 257, Address: 0x10041c0 */
  if (lpPeSrc->peBlue != lpPeDest->peBlue /* Line 258, Address: 0x10041cc */
      || lpPeSrc->peGreen != lpPeDest->peGreen
      || lpPeSrc->peRed != lpPeDest->peRed) {
    if (lpPeSrc->peBlue < lpPeDest->peBlue) { /* Line 261, Address: 0x100422c */
      lpPeDest->peBlue -= 32; /* Line 262, Address: 0x1004250 */
    } /* Line 263, Address: 0x1004260 */
    else if (lpPeSrc->peGreen < lpPeDest->peGreen) { /* Line 264, Address: 0x1004268 */
      lpPeDest->peGreen -= 32; /* Line 265, Address: 0x100428c */
    } /* Line 266, Address: 0x100429c */
    else if (lpPeSrc->peRed < lpPeDest->peRed) { /* Line 267, Address: 0x10042a4 */
      lpPeDest->peRed -= 32; /* Line 268, Address: 0x10042c8 */
    }
  }

} /* Line 272, Address: 0x10042dc */


void flashout(void) {
  startcolor = 0; /* Line 276, Address: 0x10042f0 */
  colorcnt = 63; /* Line 277, Address: 0x10042f8 */

  FadeCount = 0; /* Line 279, Address: 0x1004304 */
  *lpFadeFlag = 4; /* Line 280, Address: 0x100430c */

} /* Line 282, Address: 0x100431c */

static int flashout_new(void) { /* Line 284, Address: 0x1004330 */

  int_flg = 10; /* Line 286, Address: 0x1004338 */

  flashout1(); /* Line 288, Address: 0x1004344 */


  if (++FadeCount > 21) { /* Line 291, Address: 0x100434c */
    FadeCount = 0; /* Line 292, Address: 0x100436c */
    return 1; /* Line 293, Address: 0x1004374 */
  }
  return 0; /* Line 295, Address: 0x1004380 */
} /* Line 296, Address: 0x1004384 */


static void flashout1(void) { /* Line 299, Address: 0x10043a0 */
  PALETTEENTRY* lpPe;
  int i;

  lpPe = &lpcolorwk0[startcolor / 2]; /* Line 303, Address: 0x10043b0 */

  for (i = 0; colorcnt >= i; ++i) { /* Line 305, Address: 0x10043e4 */
    flashout2(lpPe); /* Line 306, Address: 0x10043f0 */
    ++lpPe; /* Line 307, Address: 0x10043fc */
  } /* Line 308, Address: 0x1004400 */
  lpPe = &lpcolorwk3[startcolor / 2]; /* Line 309, Address: 0x100441c */

  for (i = 0; colorcnt >= i; ++i) { /* Line 311, Address: 0x1004450 */
    flashout2(lpPe); /* Line 312, Address: 0x100445c */
    ++lpPe; /* Line 313, Address: 0x1004468 */
  } /* Line 314, Address: 0x100446c */


} /* Line 317, Address: 0x1004488 */


static void flashout2(PALETTEENTRY* lpPeDest) { /* Line 320, Address: 0x10044a0 */
  if (lpPeDest->peRed != 224) { /* Line 321, Address: 0x10044a8 */
    lpPeDest->peRed += 32; /* Line 322, Address: 0x10044c0 */
  } /* Line 323, Address: 0x10044d4 */
  else if (lpPeDest->peGreen != 224) { /* Line 324, Address: 0x10044dc */
    lpPeDest->peGreen += 32; /* Line 325, Address: 0x10044f4 */
  } /* Line 326, Address: 0x1004504 */
  else if (lpPeDest->peBlue != 224) { /* Line 327, Address: 0x100450c */
    lpPeDest->peBlue += 32; /* Line 328, Address: 0x1004524 */
  }


} /* Line 332, Address: 0x1004534 */


int FadeProc(void) { /* Line 335, Address: 0x1004540 */
  int ret;

  switch (*lpFadeFlag) { /* Line 338, Address: 0x100454c */
    case 1:
      ret = fadein0_new(); /* Line 340, Address: 0x1004590 */
      break; /* Line 341, Address: 0x100459c */

    case 2:
      ret = fadeout_new(); /* Line 344, Address: 0x10045a4 */
      break; /* Line 345, Address: 0x10045b0 */

    case 3:
      ret = flashin_new(); /* Line 348, Address: 0x10045b8 */
      break; /* Line 349, Address: 0x10045c4 */

    case 4:
      ret = flashout_new(); /* Line 352, Address: 0x10045cc */
      break; /* Line 353, Address: 0x10045d8 */

    default:
      ret = 1; /* Line 356, Address: 0x10045e0 */
  }


  v_int(); /* Line 360, Address: 0x10045e4 */
  if (ret != 0) flash_flg = 0; /* Line 361, Address: 0x10045ec */
  return ret; /* Line 362, Address: 0x10045fc */
} /* Line 363, Address: 0x1004600 */
