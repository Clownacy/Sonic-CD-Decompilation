#include "..\..\TYPES.H"
#include "FADEIN.H"

static unsigned short code_tbl[3] = { 1, 5, 9 };
static unsigned short wColwk;
static int FadeCount;
extern int* lpFadeFlag;
extern palette_entry* lpcolorwk;
static palette_entry colorsave[64];
static unsigned char byMskwk;































void clwout() {
  *lpFadeFlag = 2; /* Line 43, Address: 0x1001910 */
  FadeCount = 8; /* Line 44, Address: 0x1001920 */
  wColwk = 0; /* Line 45, Address: 0x100192c */
} /* Line 46, Address: 0x1001934 */


void clwout_new() { /* Line 49, Address: 0x1001940 */
  short i;
  palette_entry* lpColwk;


  if (wColwk >= 3) { /* Line 54, Address: 0x1001950 */
    *lpFadeFlag = 0; /* Line 55, Address: 0x1001968 */
    lpColwk = lpcolorwk; /* Line 56, Address: 0x1001974 */
    for (i = 0; i < 64; ++i, ++lpColwk) { /* Line 57, Address: 0x100197c */
      lpColwk->peRed = 255; /* Line 58, Address: 0x1001988 */
      lpColwk->peGreen = 255; /* Line 59, Address: 0x1001990 */
      lpColwk->peBlue = 255; /* Line 60, Address: 0x1001998 */
    } /* Line 61, Address: 0x10019a0 */
    return; /* Line 62, Address: 0x10019c4 */
  }
  if (--FadeCount >= 0) { /* Line 64, Address: 0x10019cc */

    woutcolor(code_tbl[wColwk]); /* Line 66, Address: 0x10019e8 */
  } /* Line 67, Address: 0x1001a10 */
  else {

    FadeCount = 8; /* Line 70, Address: 0x1001a18 */
    ++wColwk; /* Line 71, Address: 0x1001a24 */
  }
} /* Line 73, Address: 0x1001a38 */











void woutcolor(unsigned short wD1) { /* Line 85, Address: 0x1001a50 */
  short i;
  palette_entry* lpColwk;


  lpColwk = lpcolorwk; /* Line 90, Address: 0x1001a60 */
  for (i = 0; i < 64; ++i, ++lpColwk) { /* Line 91, Address: 0x1001a68 */

    switch (wD1) { /* Line 93, Address: 0x1001a74 */

      case 1:
        if (lpColwk->peRed < 224) { /* Line 96, Address: 0x1001aa8 */
          lpColwk->peRed += 32; /* Line 97, Address: 0x1001abc */
        }
        break; /* Line 99, Address: 0x1001ac8 */
      case 5:
        if (lpColwk->peGreen < 224) { /* Line 101, Address: 0x1001ad0 */
          lpColwk->peGreen += 32; /* Line 102, Address: 0x1001ae4 */
        }
        break; /* Line 104, Address: 0x1001af0 */
      case 9:
        if (lpColwk->peBlue < 224) { /* Line 106, Address: 0x1001af8 */
          lpColwk->peBlue += 32; /* Line 107, Address: 0x1001b0c */
        }
        break;
    }
  } /* Line 111, Address: 0x1001b18 */

} /* Line 113, Address: 0x1001b3c */











void clwin_init() { /* Line 125, Address: 0x1001b50 */
  short i;
  palette_entry* lpColwk;
  palette_entry* lpSavewk;
  palette_entry tmp = { 224, 224, 224, 1 }; /* Line 129, Address: 0x1001b60 */

  lpColwk = lpcolorwk; /* Line 131, Address: 0x1001b74 */
  lpSavewk = colorsave; /* Line 132, Address: 0x1001b7c */
  for (i = 0; i < 64; ++i) { /* Line 133, Address: 0x1001b84 */

    *lpSavewk++ = *lpColwk; /* Line 135, Address: 0x1001b90 */
    *lpColwk++ = tmp; /* Line 136, Address: 0x1001bb8 */
  } /* Line 137, Address: 0x1001be4 */
} /* Line 138, Address: 0x1001c04 */











void clwin() {
  *lpFadeFlag = 1; /* Line 151, Address: 0x1001c20 */
  FadeCount = 8; /* Line 152, Address: 0x1001c30 */
  wColwk = 0; /* Line 153, Address: 0x1001c3c */
  byMskwk = 224; /* Line 154, Address: 0x1001c44 */
} /* Line 155, Address: 0x1001c50 */


void clwin_new() { /* Line 158, Address: 0x1001c60 */
  if (wColwk >= 3) { /* Line 159, Address: 0x1001c68 */

    *lpFadeFlag = 0; /* Line 161, Address: 0x1001c80 */
    return; /* Line 162, Address: 0x1001c8c */
  }
  if (--FadeCount >= 0) { /* Line 164, Address: 0x1001c94 */

    wincolor(byMskwk, code_tbl[wColwk]); /* Line 166, Address: 0x1001cb0 */
    byMskwk -= 32; /* Line 167, Address: 0x1001ce0 */
  } /* Line 168, Address: 0x1001cf4 */
  else {

    FadeCount = 8; /* Line 171, Address: 0x1001cfc */
    byMskwk = 224; /* Line 172, Address: 0x1001d08 */
    ++wColwk; /* Line 173, Address: 0x1001d14 */
  }
} /* Line 175, Address: 0x1001d28 */











void wincolor(unsigned char byD0, unsigned short wD1) { /* Line 187, Address: 0x1001d40 */
  short i;
  unsigned char byColwk;
  palette_entry *lpColwk, *lpSavewk;

  lpColwk = lpcolorwk; /* Line 192, Address: 0x1001d5c */
  lpSavewk = colorsave; /* Line 193, Address: 0x1001d64 */
  for (i = 0; i < 64; ++i) { /* Line 194, Address: 0x1001d6c */

    switch (wD1) { /* Line 196, Address: 0x1001d78 */

      case 1:
        byColwk = lpSavewk->peRed; /* Line 199, Address: 0x1001dac */
        if (byColwk < byD0) byColwk = byD0; /* Line 200, Address: 0x1001db4 */
        lpColwk->peRed = byColwk; /* Line 201, Address: 0x1001dd4 */
        break; /* Line 202, Address: 0x1001dd8 */
      case 5:
        byColwk = lpSavewk->peGreen; /* Line 204, Address: 0x1001de0 */
        if (byColwk < byD0) byColwk = byD0; /* Line 205, Address: 0x1001de8 */
        lpColwk->peGreen = byColwk; /* Line 206, Address: 0x1001e08 */
        break; /* Line 207, Address: 0x1001e0c */
      case 9:
        byColwk = lpSavewk->peBlue; /* Line 209, Address: 0x1001e14 */
        if (byColwk < byD0) byColwk = byD0; /* Line 210, Address: 0x1001e1c */
        lpColwk->peBlue = byColwk; /* Line 211, Address: 0x1001e3c */
        break;
    }
    ++lpSavewk; /* Line 214, Address: 0x1001e40 */
    ++lpColwk; /* Line 215, Address: 0x1001e44 */
  } /* Line 216, Address: 0x1001e48 */


} /* Line 219, Address: 0x1001e68 */












int FadeProc() { /* Line 232, Address: 0x1001e90 */
  switch (*lpFadeFlag) { /* Line 233, Address: 0x1001e98 */

    case 1:
      clwin_new(); /* Line 236, Address: 0x1001ec4 */
      break; /* Line 237, Address: 0x1001ecc */
    case 2:
      clwout_new(); /* Line 239, Address: 0x1001ed4 */
      break;
  }
  return 0; /* Line 242, Address: 0x1001edc */
} /* Line 243, Address: 0x1001ee0 */
