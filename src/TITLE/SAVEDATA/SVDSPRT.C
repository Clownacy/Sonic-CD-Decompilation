#include "..\..\TYPES.H"
#include "..\COMMON\HMX_TYPES.H"
#include "SVDBMP.H"
#include "SVDSPRT.H"
#include "..\COMMON\HMX_OEEACTL.H"

static int GetMarkfontIndx(char c, int kind);
static void MovSonicCursol(POINT point);
static int isqrt(int xx);

static int SONICMOVEM_MAG = 4;
extern mark_info markTable[];
extern draw_context* s_ctx;
extern unsigned int hSprFile[6][56];
extern int PRIO_MAX;
extern sprite_bmp infoSprtBmp[];
extern void(*hmx_sprite_set_flags_module)(hmx_sprite*, int);
extern void(*hmx_sprite_set_bitmap_module)(hmx_sprite*, hmx_bitmap*);
extern void(*hmx_sprite_set_position_module)(hmx_sprite*, int, int);
extern POINT nPosiXSprFile[];
extern unsigned int hSprMes[];
extern int nPosiXSprMes[];
static int cursolPosiIndxX;
extern int nFileNumber;
extern int PLAYERCHAR_W;
static int nSonicKind;
extern unsigned int bMenuChosed;
static int nStandStartTimerCunt;
extern int nTimerCunt;
static int nSonicMode;
static POINT posiSonicCursol;
static int fSonicIncX;
static int_union posiStartYOld;
static int_union posiStartXOld;
static int fSonicIncY;
static POINT posiTarget;
static unsigned int hFxh[120];




































static int GetMarkfontIndx(char c, int kind) { /* Line 74, Address: 0x1003400 */
  int n = 0; /* Line 75, Address: 0x1003410 */

  while (markTable[n].code) /* Line 77, Address: 0x1003414 */
  {
    if (c == markTable[n].code) /* Line 79, Address: 0x100341c */
    {
      switch (kind) /* Line 81, Address: 0x1003454 */
      {
        case 0:
          return markTable[n].white88; /* Line 84, Address: 0x100348c */
        case 1:
          return markTable[n].yello88; /* Line 86, Address: 0x10034b0 */
        case 2:
          return markTable[n].yello816; /* Line 88, Address: 0x10034d4 */
        case 3:
          return markTable[n].whitex16; /* Line 90, Address: 0x10034f8 */
        default:
          return -1; /* Line 92, Address: 0x100351c */
      }
    }
    ++n; /* Line 95, Address: 0x1003528 */
  } /* Line 96, Address: 0x100352c */
  return -1; /* Line 97, Address: 0x1003550 */
} /* Line 98, Address: 0x1003554 */








unsigned int CreateCharSprt(char c, int kind, int nBlockNo, int nSprNum) { /* Line 107, Address: 0x1003570 */
  RECTL SprRect = { 0, 0, 0, 0 }; /* Line 108, Address: 0x100358c */
  unsigned int mask[4] = { 0, 0, 0, 0 }; /* Line 109, Address: 0x10035bc */
  POINT point;
  int indx;


  switch (kind) /* Line 114, Address: 0x10035ec */
  {
    case 0:
      if (c >= 48 && c < 58) indx = c - 37; /* Line 117, Address: 0x1003624 */
      else if (c >= 65 && c < 91) indx = c - 44; /* Line 118, Address: 0x1003670 */
      else
      {
        indx = GetMarkfontIndx(c, kind); /* Line 121, Address: 0x10036b8 */
        if (indx == -1) return 0; /* Line 122, Address: 0x10036cc */
      }
      break;
    case 1:
      if (c >= 48 && c < 58) indx = c - 1; /* Line 126, Address: 0x10036e4 */
      else if (c >= 65 && c < 91) indx = c - 8; /* Line 127, Address: 0x100372c */
      else
      {
        indx = GetMarkfontIndx(c, kind); /* Line 130, Address: 0x1003774 */
        if (indx == -1) return 0; /* Line 131, Address: 0x1003788 */
      }
      break;
    case 2:
      if (c >= 48 && c < 58) indx = c + 35; /* Line 135, Address: 0x10037a0 */
      else if (c >= 65 && c < 91) indx = c + 28; /* Line 136, Address: 0x10037e8 */
      else
      {
        indx = GetMarkfontIndx(c, kind); /* Line 139, Address: 0x1003830 */
        if (indx == -1) return 0; /* Line 140, Address: 0x1003844 */
      }
      break;

    case 3:
      if (c >= 48 && c < 58) indx = c + 71; /* Line 145, Address: 0x100385c */
      else if (c >= 65 && c < 91) indx = c + 64; /* Line 146, Address: 0x10038a4 */
      else
      {
        indx = GetMarkfontIndx(c, kind); /* Line 149, Address: 0x10038ec */
        if (indx == -1) return 0; /* Line 150, Address: 0x1003900 */
      }
      break;
    default:
      return 0; /* Line 154, Address: 0x1003918 */
  }
  if (nBlockNo == 1) /* Line 156, Address: 0x1003924 */
  {
    if (hSprMes[nSprNum] != 0) /* Line 158, Address: 0x1003934 */
      return 0; /* Line 159, Address: 0x1003954 */

    sprCreate((int*)&hSprMes[nSprNum]); /* Line 161, Address: 0x1003960 */


    point.x = nPosiXSprMes[nSprNum]; /* Line 164, Address: 0x100397c */
    point.y = 10; /* Line 165, Address: 0x1003998 */



    hmx_sprite_set_position_module(s_ctx->sprites[hSprMes[nSprNum]], point.x, point.y); /* Line 169, Address: 0x10039a0 */
    hmx_sprite_set_bitmap_module(s_ctx->sprites[hSprMes[nSprNum]], s_ctx->spr_bitmaps[indx]); /* Line 170, Address: 0x10039e8 */
    hmx_sprite_set_flags_module(s_ctx->sprites[hSprMes[nSprNum]], 0); /* Line 171, Address: 0x1003a3c */
    s_ctx->spr_level[hSprMes[nSprNum]] = PRIO_MAX - infoSprtBmp[indx].order; /* Line 172, Address: 0x1003a80 */
    return 1; /* Line 173, Address: 0x1003acc */
  }
  if (nBlockNo >= 2 || nBlockNo < 9) /* Line 175, Address: 0x1003ad8 */
  {

    if (hSprFile[nBlockNo - 2][nSprNum] != 0) /* Line 178, Address: 0x1003af8 */
      return 0; /* Line 179, Address: 0x1003b30 */


    sprCreate((int*)&hSprFile[nBlockNo - 2][nSprNum]); /* Line 182, Address: 0x1003b3c */


    point.x = nPosiXSprFile[nSprNum].x; /* Line 185, Address: 0x1003b70 */
    point.y = (nBlockNo - 2) * 32 + 32 + nPosiXSprFile[nSprNum].y; /* Line 186, Address: 0x1003b8c */


    hmx_sprite_set_position_module(s_ctx->sprites[hSprFile[nBlockNo - 2][nSprNum]], point.x, point.y); /* Line 189, Address: 0x1003bbc */
    hmx_sprite_set_bitmap_module(s_ctx->sprites[hSprFile[nBlockNo - 2][nSprNum]], s_ctx->spr_bitmaps[indx]); /* Line 190, Address: 0x1003c1c */
    hmx_sprite_set_flags_module(s_ctx->sprites[hSprFile[nBlockNo - 2][nSprNum]], 0); /* Line 191, Address: 0x1003c88 */
    s_ctx->spr_level[hSprFile[nBlockNo - 2][nSprNum]] = PRIO_MAX - infoSprtBmp[indx].order; /* Line 192, Address: 0x1003ce4 */
    return 1; /* Line 193, Address: 0x1003d48 */
  }
  return 0; /* Line 195, Address: 0x1003d54 */
} /* Line 196, Address: 0x1003d58 */




unsigned int CreateStringSprt(char* str, int kind, int nBlockNo, int nStartSprNum) { /* Line 201, Address: 0x1003d70 */
  int n = nStartSprNum; /* Line 202, Address: 0x1003d8c */

  while (*str) /* Line 204, Address: 0x1003d90 */
  {
    if (*str != 32) /* Line 206, Address: 0x1003d98 */
      CreateCharSprt(*str, kind, nBlockNo, n); /* Line 207, Address: 0x1003db4 */
    ++str; /* Line 208, Address: 0x1003dd0 */
    ++n; /* Line 209, Address: 0x1003ddc */
  } /* Line 210, Address: 0x1003de0 */
  return 1; /* Line 211, Address: 0x1003df0 */
} /* Line 212, Address: 0x1003df4 */




void DeleteCharSprt(int nBlockNo, int nSprNum) { /* Line 217, Address: 0x1003e10 */
  if (nBlockNo == 1) /* Line 218, Address: 0x1003e20 */
  {
    if (hSprMes[nSprNum] == 0) return; /* Line 220, Address: 0x1003e30 */


    hmx_sprite_set_bitmap_module(s_ctx->sprites[hSprMes[nSprNum]], 0); /* Line 223, Address: 0x1003e50 */
    s_ctx->spr_level[hSprMes[nSprNum]] = 0; /* Line 224, Address: 0x1003e94 */
    sprDelete(hSprMes[nSprNum]); /* Line 225, Address: 0x1003ec0 */
    hSprMes[nSprNum] = 0; /* Line 226, Address: 0x1003ee0 */

  } /* Line 228, Address: 0x1003ef8 */
  else if (nBlockNo >= 2 || nBlockNo < 9) /* Line 229, Address: 0x1003f00 */
  {

    if (hSprFile[nBlockNo - 2][nSprNum] != 0) /* Line 232, Address: 0x1003f20 */
    {

      hmx_sprite_set_bitmap_module(s_ctx->sprites[hSprFile[nBlockNo - 2][nSprNum]], 0); /* Line 235, Address: 0x1003f58 */
      s_ctx->spr_level[hSprFile[nBlockNo - 2][nSprNum]] = 0; /* Line 236, Address: 0x1003fb4 */
      sprDelete(hSprFile[nBlockNo - 2][nSprNum]); /* Line 237, Address: 0x1003ff8 */
      hSprFile[nBlockNo - 2][nSprNum] = 0; /* Line 238, Address: 0x1004030 */
    }
  }
} /* Line 241, Address: 0x1004060 */




void DeleteStringSprt(int strLength, int nBlockNo, int nStartSprNum) { /* Line 246, Address: 0x1004070 */
  int i;
  int n = nStartSprNum; /* Line 248, Address: 0x100408c */

  for (i = 0; i < strLength; ++i) /* Line 250, Address: 0x1004090 */
  {
    DeleteCharSprt(nBlockNo, n++); /* Line 252, Address: 0x100409c */
  } /* Line 253, Address: 0x10040b0 */
} /* Line 254, Address: 0x10040c4 */




void DeleteAllCharSprt(void) { /* Line 259, Address: 0x10040e0 */
  int n;

  DeleteStringSprt(27, 1, 0); /* Line 262, Address: 0x10040ec */
  for (n = 0; n < 6; ++n) /* Line 263, Address: 0x1004100 */
    DeleteStringSprt(56, n + 2, 0); /* Line 264, Address: 0x100410c */
} /* Line 265, Address: 0x1004130 */




int GetCursolPositon(void) {
  return cursolPosiIndxX; /* Line 271, Address: 0x1004150 */
} /* Line 272, Address: 0x1004158 */




void MovCursol(int x) { /* Line 277, Address: 0x1004160 */
  POINT point;

  cursolPosiIndxX = x; /* Line 280, Address: 0x100416c */
  point.x = nPosiXSprFile[0].x + PLAYERCHAR_W * x; /* Line 281, Address: 0x1004178 */
  point.y = nFileNumber * 32 + 32; /* Line 282, Address: 0x1004198 */

  hmx_sprite_set_position_module(s_ctx->sprites[*infoSprtBmp[191].lphSpr], point.x, point.y); /* Line 284, Address: 0x10041ac */
} /* Line 285, Address: 0x10041e8 */




void DispCursol(void) { /* Line 290, Address: 0x1004200 */
  OESprCreateIndx(191); /* Line 291, Address: 0x1004208 */
  MovCursol(cursolPosiIndxX); /* Line 292, Address: 0x1004214 */
} /* Line 293, Address: 0x1004224 */




void HideCursol(void) { /* Line 298, Address: 0x1004240 */
  OESprDeleteIndx(191); /* Line 299, Address: 0x1004248 */
} /* Line 300, Address: 0x1004254 */












void HideSonicCursol(void) { /* Line 313, Address: 0x1004270 */
  OESprDeleteIndx(nSonicKind); /* Line 314, Address: 0x1004278 */
} /* Line 315, Address: 0x1004288 */




void DispSonicCursol(POINT point) { /* Line 320, Address: 0x10042a0 */
  nSonicKind = 203; /* Line 321, Address: 0x10042ac */
  OESprCreateIndx(nSonicKind); /* Line 322, Address: 0x10042b8 */
  posiSonicCursol = point; /* Line 323, Address: 0x10042c8 */

  hmx_sprite_set_position_module(s_ctx->sprites[*infoSprtBmp[nSonicKind].lphSpr], posiSonicCursol.x, posiSonicCursol.y); /* Line 325, Address: 0x10042dc */

  nSonicMode = 1; /* Line 327, Address: 0x1004334 */
  nStandStartTimerCunt = nTimerCunt; /* Line 328, Address: 0x1004340 */

  if (bMenuChosed == 0) /* Line 330, Address: 0x1004350 */
  {
    hmx_sprite_set_flags_module(s_ctx->sprites[*infoSprtBmp[nSonicKind].lphSpr], 1); /* Line 332, Address: 0x1004360 */

  } /* Line 334, Address: 0x10043ac */
  else
  {
    hmx_sprite_set_flags_module(s_ctx->sprites[*infoSprtBmp[nSonicKind].lphSpr], 0); /* Line 337, Address: 0x10043b4 */

  }
} /* Line 340, Address: 0x1004400 */




static void MovSonicCursol(POINT point) { /* Line 345, Address: 0x1004410 */
  HideSonicCursol(); /* Line 346, Address: 0x100441c */
  if (nSonicKind == 203 /* Line 347, Address: 0x1004424 */
      || nSonicKind == 204
      || nSonicKind == 205)
    nSonicKind = 206; /* Line 350, Address: 0x1004460 */
  else if (nSonicKind == 208) nSonicKind = 206; /* Line 351, Address: 0x1004474 */
  else ++nSonicKind; /* Line 352, Address: 0x100449c */
  OESprCreateIndx(nSonicKind); /* Line 353, Address: 0x10044b0 */
  posiSonicCursol = point; /* Line 354, Address: 0x10044c0 */

  hmx_sprite_set_position_module(s_ctx->sprites[*infoSprtBmp[nSonicKind].lphSpr], posiSonicCursol.x, posiSonicCursol.y); /* Line 356, Address: 0x10044d4 */

  if (fSonicIncX < 0 || bMenuChosed == 0) /* Line 358, Address: 0x100452c */
  {
    hmx_sprite_set_flags_module(s_ctx->sprites[*infoSprtBmp[nSonicKind].lphSpr], 1); /* Line 360, Address: 0x100454c */

  } /* Line 362, Address: 0x1004598 */
  else
  {
    hmx_sprite_set_flags_module(s_ctx->sprites[*infoSprtBmp[nSonicKind].lphSpr], 0); /* Line 365, Address: 0x10045a0 */

  }
} /* Line 368, Address: 0x10045ec */





















void RunSonicCursol(POINT point) { /* Line 390, Address: 0x1004600 */
  int_union sx, sy;

  posiTarget = point; /* Line 393, Address: 0x100460c */
  sx.w.h = posiTarget.x - posiSonicCursol.x, sx.w.l = 0; /* Line 394, Address: 0x1004620 */
  sy.w.h = posiTarget.y - posiSonicCursol.y, sy.w.l = 0; /* Line 395, Address: 0x1004644 */
  if (sx.w.h == 0) fSonicIncX = 0; /* Line 396, Address: 0x1004668 */
  else fSonicIncX = SONICMOVEM_MAG * (sx.l / isqrt((sx.w.h * sx.w.h + sy.w.h * sy.w.h) * 65536)); /* Line 397, Address: 0x100468c */
  if (sy.w.h == 0) fSonicIncY = 0; /* Line 398, Address: 0x1004700 */
  else fSonicIncY = SONICMOVEM_MAG * (sy.l / isqrt((sx.w.h * sx.w.h + sy.w.h * sy.w.h) * 65536)); /* Line 399, Address: 0x1004724 */
  posiStartXOld.w.h = posiSonicCursol.x; /* Line 400, Address: 0x1004798 */
  posiStartYOld.w.h = posiSonicCursol.y; /* Line 401, Address: 0x10047b0 */
  nSonicMode = 2; /* Line 402, Address: 0x10047c8 */
} /* Line 403, Address: 0x10047d4 */

static int isqrt(int xx) { /* Line 405, Address: 0x10047f0 */
  int s, t;

  if (xx == 0) return 0; /* Line 408, Address: 0x1004800 */
  s = 1, t = xx; /* Line 409, Address: 0x1004818 */
  while (s < t) s <<= 1, t >>= 1; /* Line 410, Address: 0x1004820 */
label1:
  t = s; /* Line 412, Address: 0x1004844 */
  s = (s + xx / s) >> 1; /* Line 413, Address: 0x1004848 */
  if (s < t) goto label1; /* Line 414, Address: 0x1004868 */
  return t; /* Line 415, Address: 0x1004874 */
} /* Line 416, Address: 0x1004878 */



void UpdateSonicCursol(void) { /* Line 420, Address: 0x1004890 */
  if (nSonicMode == 1) /* Line 421, Address: 0x1004898 */
  {
    if (nTimerCunt % 20 != 0) return; /* Line 423, Address: 0x10048ac */

    if (nTimerCunt - nStandStartTimerCunt <= 60) return; /* Line 425, Address: 0x10048c8 */

    HideSonicCursol(); /* Line 427, Address: 0x10048e8 */
    if (nSonicKind == 203) nSonicKind = 204; /* Line 428, Address: 0x10048f0 */
    else if (nSonicKind == 204) nSonicKind = 205; /* Line 429, Address: 0x1004918 */
    else if (nSonicKind == 205) nSonicKind = 204; /* Line 430, Address: 0x1004940 */
    else nSonicKind = 203; /* Line 431, Address: 0x1004968 */
    OESprCreateIndx(nSonicKind); /* Line 432, Address: 0x1004974 */

    if (bMenuChosed == 0) /* Line 434, Address: 0x1004984 */
    {
      hmx_sprite_set_flags_module(s_ctx->sprites[*infoSprtBmp[nSonicKind].lphSpr], 1); /* Line 436, Address: 0x1004994 */

    } /* Line 438, Address: 0x10049e0 */
    else
    {
      hmx_sprite_set_flags_module(s_ctx->sprites[*infoSprtBmp[nSonicKind].lphSpr], 0); /* Line 441, Address: 0x10049e8 */

    }

    hmx_sprite_set_position_module(s_ctx->sprites[*infoSprtBmp[nSonicKind].lphSpr], posiSonicCursol.x, posiSonicCursol.y); /* Line 445, Address: 0x1004a34 */

  } /* Line 447, Address: 0x1004a8c */
  else if (nSonicMode == 2) /* Line 448, Address: 0x1004a94 */
  {




    posiStartXOld.l += fSonicIncX * 256; /* Line 454, Address: 0x1004aa8 */
    posiStartYOld.l += fSonicIncY * 256; /* Line 455, Address: 0x1004ac8 */


    posiSonicCursol.x = posiStartXOld.w.h; /* Line 458, Address: 0x1004ae8 */
    posiSonicCursol.y = posiStartYOld.w.h; /* Line 459, Address: 0x1004b00 */

    if ((fSonicIncX >= 0 && posiSonicCursol.x >= posiTarget.x) /* Line 461, Address: 0x1004b18 */
        || fSonicIncX < 0 && posiSonicCursol.x <= posiTarget.x)
      posiSonicCursol.x = posiTarget.x; /* Line 463, Address: 0x1004b70 */
    if ((fSonicIncY >= 0 && posiSonicCursol.y >= posiTarget.y) /* Line 464, Address: 0x1004b80 */
        || fSonicIncY < 0 && posiSonicCursol.y <= posiTarget.y)
      posiSonicCursol.y = posiTarget.y; /* Line 466, Address: 0x1004bd8 */
    if (posiSonicCursol.x == posiTarget.x && posiSonicCursol.y == posiTarget.y) /* Line 467, Address: 0x1004be8 */
    {
      HideSonicCursol(); /* Line 469, Address: 0x1004c18 */
      DispSonicCursol(posiSonicCursol); /* Line 470, Address: 0x1004c20 */
    } /* Line 471, Address: 0x1004c38 */
    else
      MovSonicCursol(posiSonicCursol); /* Line 473, Address: 0x1004c40 */
  }
} /* Line 475, Address: 0x1004c58 */
