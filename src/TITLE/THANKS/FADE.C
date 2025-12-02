#include "..\..\TYPES.H"
#include "FADE.H"
#include "GAME.H"

static void fadein1(void);
static void fadein2(PALETTEENTRY* lpPeDest, PALETTEENTRY* lpPeSrc);
static int fadeout_new(void);
static void fadeout1(void);
static void fadeout2(PALETTEENTRY* lpPeDest);

extern unsigned char colorcnt;
extern unsigned char startcolor;
extern int* lpFadeFlag;
extern short FadeFlag;
int FadeCount;
extern PALETTEENTRY* lpcolorwk0;
extern unsigned char int_flg;
extern PALETTEENTRY* lpcolorwk1;
extern PALETTEENTRY* lpcolorwk3;




















void fadein(void) { /* Line 40, Address: 0x1001770 */
  startcolor = 0; /* Line 41, Address: 0x1001778 */
  colorcnt = 63; /* Line 42, Address: 0x1001780 */
  fadein0(); /* Line 43, Address: 0x100178c */
} /* Line 44, Address: 0x1001794 */


void fadein0(void) { /* Line 47, Address: 0x10017b0 */
  PALETTEENTRY* lpPe;
  int i;

  lpPe = &lpcolorwk0[startcolor / 2]; /* Line 51, Address: 0x10017bc */

  for (i = 0; colorcnt >= i; ++i) { /* Line 53, Address: 0x10017f0 */
    lpPe->peRed = 0; /* Line 54, Address: 0x10017fc */
    lpPe->peGreen = 0; /* Line 55, Address: 0x1001800 */
    lpPe->peBlue = 0; /* Line 56, Address: 0x1001804 */
    lpPe->peFlags = 1; /* Line 57, Address: 0x1001808 */
    ++lpPe; /* Line 58, Address: 0x1001810 */
  } /* Line 59, Address: 0x1001814 */
  FadeCount = 0; /* Line 60, Address: 0x1001830 */
  FadeFlag = 1; /* Line 61, Address: 0x1001838 */
  *lpFadeFlag = 1; /* Line 62, Address: 0x1001844 */

} /* Line 64, Address: 0x1001854 */



int fadein0_new(void) { /* Line 68, Address: 0x1001870 */

  int_flg = 10; /* Line 70, Address: 0x1001878 */

  fadein1(); /* Line 72, Address: 0x1001884 */


  if (++FadeCount > 21) { /* Line 75, Address: 0x100188c */
    FadeCount = 0; /* Line 76, Address: 0x10018ac */
    return 1; /* Line 77, Address: 0x10018b4 */
  }
  return 0; /* Line 79, Address: 0x10018c0 */
} /* Line 80, Address: 0x10018c4 */



static void fadein1(void) { /* Line 84, Address: 0x10018e0 */
  PALETTEENTRY *lpPe, *lpPe2;
  int i;

  lpPe = &lpcolorwk0[startcolor / 2]; /* Line 88, Address: 0x10018f4 */
  lpPe2 = &lpcolorwk1[startcolor / 2]; /* Line 89, Address: 0x1001928 */

  for (i = 0; colorcnt >= i; ++i) { /* Line 91, Address: 0x100195c */
    fadein2(lpPe, lpPe2); /* Line 92, Address: 0x1001968 */
    ++lpPe; /* Line 93, Address: 0x1001978 */
    ++lpPe2; /* Line 94, Address: 0x100197c */
  } /* Line 95, Address: 0x1001980 */










} /* Line 106, Address: 0x100199c */



static void fadein2(PALETTEENTRY* lpPeDest, PALETTEENTRY* lpPeSrc) { /* Line 110, Address: 0x10019c0 */
  if (lpPeSrc->peBlue != lpPeDest->peBlue /* Line 111, Address: 0x10019cc */
      || lpPeSrc->peGreen != lpPeDest->peGreen
      || lpPeSrc->peRed != lpPeDest->peRed) {
    if (lpPeSrc->peBlue > lpPeDest->peBlue) { /* Line 114, Address: 0x1001a2c */
      lpPeDest->peBlue += 32; /* Line 115, Address: 0x1001a50 */
    } /* Line 116, Address: 0x1001a60 */
    else if (lpPeSrc->peGreen > lpPeDest->peGreen) { /* Line 117, Address: 0x1001a68 */
      lpPeDest->peGreen += 32; /* Line 118, Address: 0x1001a8c */
    } /* Line 119, Address: 0x1001a9c */
    else if (lpPeSrc->peRed > lpPeDest->peRed) { /* Line 120, Address: 0x1001aa4 */
      lpPeDest->peRed += 32; /* Line 121, Address: 0x1001ac8 */
    }
  }

} /* Line 125, Address: 0x1001adc */




void fadeout(void) {
  startcolor = 0; /* Line 131, Address: 0x1001af0 */
  colorcnt = 63; /* Line 132, Address: 0x1001af8 */

  FadeCount = 0; /* Line 134, Address: 0x1001b04 */
  FadeFlag = 2; /* Line 135, Address: 0x1001b0c */
  *lpFadeFlag = 2; /* Line 136, Address: 0x1001b18 */

} /* Line 138, Address: 0x1001b28 */



static int fadeout_new(void) { /* Line 142, Address: 0x1001b30 */

  int_flg = 10; /* Line 144, Address: 0x1001b38 */

  fadeout1(); /* Line 146, Address: 0x1001b44 */


  if (++FadeCount > 21) { /* Line 149, Address: 0x1001b4c */
    FadeCount = 0; /* Line 150, Address: 0x1001b6c */
    return 1; /* Line 151, Address: 0x1001b74 */
  }
  return 0; /* Line 153, Address: 0x1001b80 */
} /* Line 154, Address: 0x1001b84 */


static void fadeout1(void) { /* Line 157, Address: 0x1001ba0 */
  PALETTEENTRY* lpPe;
  int i;

  lpPe = &lpcolorwk0[startcolor / 2]; /* Line 161, Address: 0x1001bb0 */

  for (i = 0; colorcnt >= i; ++i) { /* Line 163, Address: 0x1001be4 */
    fadeout2(lpPe); /* Line 164, Address: 0x1001bf0 */
    ++lpPe; /* Line 165, Address: 0x1001bfc */
  } /* Line 166, Address: 0x1001c00 */
  lpPe = &lpcolorwk3[startcolor / 2]; /* Line 167, Address: 0x1001c1c */

  for (i = 0; colorcnt >= i; ++i) { /* Line 169, Address: 0x1001c50 */
    fadeout2(lpPe); /* Line 170, Address: 0x1001c5c */
    ++lpPe; /* Line 171, Address: 0x1001c68 */
  } /* Line 172, Address: 0x1001c6c */


} /* Line 175, Address: 0x1001c88 */


static void fadeout2(PALETTEENTRY* lpPeDest) { /* Line 178, Address: 0x1001ca0 */
  if (lpPeDest->peRed) { /* Line 179, Address: 0x1001ca8 */
    lpPeDest->peRed -= 32; /* Line 180, Address: 0x1001cb8 */
  } /* Line 181, Address: 0x1001ccc */
  else if (lpPeDest->peGreen) { /* Line 182, Address: 0x1001cd4 */
    lpPeDest->peGreen -= 32; /* Line 183, Address: 0x1001ce4 */
  } /* Line 184, Address: 0x1001cf4 */
  else if (lpPeDest->peBlue) { /* Line 185, Address: 0x1001cfc */
    lpPeDest->peBlue -= 32; /* Line 186, Address: 0x1001d0c */
  }

} /* Line 189, Address: 0x1001d1c */





int FadeProc(void) { /* Line 195, Address: 0x1001d30 */
  int ret;

  switch (*lpFadeFlag) { /* Line 198, Address: 0x1001d3c */
    case 1:
      ret = fadein0_new(); /* Line 200, Address: 0x1001d68 */
      break; /* Line 201, Address: 0x1001d74 */

    case 2:
      ret = fadeout_new(); /* Line 204, Address: 0x1001d7c */
      break; /* Line 205, Address: 0x1001d88 */









    default:
      ret = 1; /* Line 216, Address: 0x1001d90 */
      break;
  }

  v_int(); /* Line 220, Address: 0x1001d94 */

  return ret; /* Line 222, Address: 0x1001d9c */
} /* Line 223, Address: 0x1001da0 */
