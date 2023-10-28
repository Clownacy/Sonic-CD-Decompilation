#include "..\TYPES.H"
#include "COMMON.H"
#include "SPM_EQU.H"
#include "FADEIN.H"

static unsigned short code_tbl[3] = { 1, 5, 9 };
static unsigned short wColwk;
static int FadeCount;
extern int* lpFadeFlag;
extern palette_entry* lpcolorwk;
static unsigned char byMskwk;




























void clwout() {
  clfflg = 1; /* Line 41, Address: 0x1004b60 */
  *lpFadeFlag = 2; /* Line 42, Address: 0x1004b6c */
  FadeCount = 8; /* Line 43, Address: 0x1004b7c */
  wColwk = 0; /* Line 44, Address: 0x1004b88 */
} /* Line 45, Address: 0x1004b90 */


void clwout_new() { /* Line 48, Address: 0x1004ba0 */
  if (wColwk >= 3) /* Line 49, Address: 0x1004ba8 */
  {
    *lpFadeFlag = 0; /* Line 51, Address: 0x1004bc0 */
    return; /* Line 52, Address: 0x1004bcc */
  }
  if (--FadeCount >= 0) /* Line 54, Address: 0x1004bd4 */
  {
    woutcolor(code_tbl[wColwk]); /* Line 56, Address: 0x1004bf0 */
  } /* Line 57, Address: 0x1004c18 */
  else
  {
    FadeCount = 8; /* Line 60, Address: 0x1004c20 */
    ++wColwk; /* Line 61, Address: 0x1004c2c */
  }
} /* Line 63, Address: 0x1004c40 */











void woutcolor(unsigned short wD1) { /* Line 75, Address: 0x1004c50 */
  short i;
  palette_entry* lpColwk;


  lpColwk = lpcolorwk; /* Line 80, Address: 0x1004c60 */
  for (i = 0; i < 64; ++i, ++lpColwk) /* Line 81, Address: 0x1004c68 */
  {
    switch (wD1) /* Line 83, Address: 0x1004c74 */
    {
      case 1:
        if (lpColwk->peRed < 224) /* Line 86, Address: 0x1004ca8 */
          lpColwk->peRed += 32; /* Line 87, Address: 0x1004cbc */

        break; /* Line 89, Address: 0x1004cc8 */
      case 5:
        if (lpColwk->peGreen < 224) /* Line 91, Address: 0x1004cd0 */
          lpColwk->peGreen += 32; /* Line 92, Address: 0x1004ce4 */

        break; /* Line 94, Address: 0x1004cf0 */
      case 9:
        if (lpColwk->peBlue < 224) /* Line 96, Address: 0x1004cf8 */
          lpColwk->peBlue += 32; /* Line 97, Address: 0x1004d0c */

        break;
    }
  } /* Line 101, Address: 0x1004d18 */

} /* Line 103, Address: 0x1004d3c */











void clwin_init() { /* Line 115, Address: 0x1004d50 */
  short i;
  palette_entry* lpColwk;
  palette_entry* lpSavewk;
  palette_entry tmp = { 224, 224, 224, 1 }; /* Line 119, Address: 0x1004d60 */

  lpColwk = lpcolorwk; /* Line 121, Address: 0x1004d74 */
  lpSavewk = colorsave; /* Line 122, Address: 0x1004d7c */
  for (i = 0; i < 64; ++i) /* Line 123, Address: 0x1004d84 */
  {
    *lpSavewk++ = *lpColwk; /* Line 125, Address: 0x1004d90 */
    *lpColwk++ = tmp; /* Line 126, Address: 0x1004db8 */
  } /* Line 127, Address: 0x1004de4 */
} /* Line 128, Address: 0x1004e04 */











void clwin() {
  *lpFadeFlag = 1; /* Line 141, Address: 0x1004e20 */
  FadeCount = 8; /* Line 142, Address: 0x1004e30 */
  wColwk = 0; /* Line 143, Address: 0x1004e3c */
  byMskwk = 224; /* Line 144, Address: 0x1004e44 */
} /* Line 145, Address: 0x1004e50 */


void clwin_new() { /* Line 148, Address: 0x1004e60 */
  if (wColwk >= 3) /* Line 149, Address: 0x1004e68 */
  {
    *lpFadeFlag = 0; /* Line 151, Address: 0x1004e80 */
    return; /* Line 152, Address: 0x1004e8c */
  }
  if (--FadeCount >= 0) /* Line 154, Address: 0x1004e94 */
  {
    wincolor(byMskwk, code_tbl[wColwk]); /* Line 156, Address: 0x1004eb0 */
    byMskwk -= 32; /* Line 157, Address: 0x1004ee0 */
  } /* Line 158, Address: 0x1004ef4 */
  else
  {
    FadeCount = 8; /* Line 161, Address: 0x1004efc */
    byMskwk = 224; /* Line 162, Address: 0x1004f08 */
    ++wColwk; /* Line 163, Address: 0x1004f14 */
  }
} /* Line 165, Address: 0x1004f28 */











void wincolor(unsigned char byD0, unsigned short wD1) { /* Line 177, Address: 0x1004f40 */
  short i;
  unsigned char byColwk;
  palette_entry *lpColwk, *lpSavewk;

  lpColwk = lpcolorwk; /* Line 182, Address: 0x1004f5c */
  lpSavewk = colorsave; /* Line 183, Address: 0x1004f64 */
  for (i = 0; i < 64; ++i) /* Line 184, Address: 0x1004f6c */
  {
    switch (wD1) /* Line 186, Address: 0x1004f78 */
    {
      case 1:
        byColwk = lpSavewk->peRed; /* Line 189, Address: 0x1004fac */
        if (byColwk < byD0) byColwk = byD0; /* Line 190, Address: 0x1004fb4 */
        lpColwk->peRed = byColwk; /* Line 191, Address: 0x1004fd4 */
        break; /* Line 192, Address: 0x1004fd8 */
      case 5:
        byColwk = lpSavewk->peGreen; /* Line 194, Address: 0x1004fe0 */
        if (byColwk < byD0) byColwk = byD0; /* Line 195, Address: 0x1004fe8 */
        lpColwk->peGreen = byColwk; /* Line 196, Address: 0x1005008 */
        break; /* Line 197, Address: 0x100500c */
      case 9:
        byColwk = lpSavewk->peBlue; /* Line 199, Address: 0x1005014 */
        if (byColwk < byD0) byColwk = byD0; /* Line 200, Address: 0x100501c */
        lpColwk->peBlue = byColwk; /* Line 201, Address: 0x100503c */
    }

    ++lpSavewk; /* Line 204, Address: 0x1005040 */
    ++lpColwk; /* Line 205, Address: 0x1005044 */
  } /* Line 206, Address: 0x1005048 */
  intflg |= 2; /* Line 207, Address: 0x1005068 */

} /* Line 209, Address: 0x100507c */












int FadeProc() { /* Line 222, Address: 0x10050a0 */
  switch (*lpFadeFlag) /* Line 223, Address: 0x10050a8 */
  {
    case 1:
      clwin_new(); /* Line 226, Address: 0x10050d4 */
      break; /* Line 227, Address: 0x10050dc */
    case 2:
      clwout_new(); /* Line 229, Address: 0x10050e4 */
      break;
  }
  return 0; /* Line 232, Address: 0x10050ec */
} /* Line 233, Address: 0x10050f0 */
