#include "..\EQU.H"
#include "WARP.H"
#include "..\IO.H"

static unsigned short clchg_cnt[2] = { 65535, 0 };
static palette_entry colortbl[32] = {
  {   0,   0,   0, 1 }, {   0, 224,   0, 1 }, {  32,  32, 192, 1 }, {  64,  64, 224, 1 },
  {  96,  96, 224, 1 }, { 128, 128, 224, 1 }, { 224, 224, 224, 1 }, { 160, 160, 160, 1 },
  { 128, 128, 128, 1 }, {  64,  64,  64, 1 }, { 224, 160, 128, 1 }, { 160,  96,  64, 1 },
  { 224,   0,   0, 1 }, { 128,   0,   0, 1 }, {  64,   0,   0, 1 }, {   0,   0,   0, 1 },
  {   0,   0,   0, 1 }, {   0, 224,   0, 1 }, {  32, 224,  32, 1 }, {  64, 224,  64, 1 },
  {  96, 224,  96, 1 }, { 128, 224, 128, 1 }, { 160, 224, 160, 1 }, { 192, 224, 192, 1 },
  { 224, 224, 224, 1 }, { 192, 224, 192, 1 }, { 160, 224, 160, 1 }, { 128, 224, 128, 1 },
  {  96, 224,  96, 1 }, {  64, 224,  64, 1 }, {  32, 224,  32, 1 }, {   0,   0,   0, 1 }
};
static palette_entry clchg_tbl[28] = {
  {   0, 224,   0 ,1 }, {  32, 224,  32, 1 }, {  64, 224,  64, 1 }, {  96, 224,  96, 1 },
  { 128, 224, 128, 1 }, { 160, 224, 160, 1 }, { 192, 224, 192, 1 }, { 224, 224, 224, 1 },
  { 192, 224, 192, 1 }, { 160, 224, 160, 1 }, { 128, 224, 128, 1 }, {  96, 224,  96, 1 },
  {  64, 224,  64, 1 }, {  32, 224,  32, 1 }, {   0, 224,   0, 1 }, {  32, 224,  32, 1 },
  {  64, 224,  64, 1 }, {  96, 224,  96, 1 }, { 128, 224, 128, 1 }, { 160, 224, 160, 1 },
  { 192, 224, 192, 1 }, { 224, 224, 224, 1 }, { 192, 224, 192, 1 }, { 160, 224, 160, 1 },
  { 128, 224, 128, 1 }, {  96, 224,  96, 1 }, {  64, 224,  64, 1 }, {  32, 224,  32, 1 }
};
void(*act_tbl[2])(sprite_status*) = { &sonic_act, &atom };
extern bmp_info SprBmp[700];
void(*sCloseFile)(int);
int(*sReadFile)(int, void*, int);
int(*sOpenFile)(char*);
void(*sOutputDebugString)(char*);
void(*sPrintf)(char*, const char*, ...);
int(*sRandom)();
void(*sMemCpy)(void*, void*, int);
void(*sMemSet)(void*, unsigned char, int);
void(*ChangeTileBmp)(int, int);
void(*CDPlay)(short);
void(*WaveRequest)(short);
void(*ClrSpriteDebug)();
void(*EAsprset)(short, short, unsigned short, unsigned short, unsigned short);
int(*SetGrid)(int, int, int, int);
static unsigned short gmtime0;
static unsigned short setcnt;
static unsigned short gmtime1;
static spr_array snc0 = { 1, { { -16, -24, 0, 0 } } };
static spr_array snc1 = { 1, { { -16, -24, 0, 1 } } };
static spr_array snc2 = { 1, { { -16, -24, 0, 2 } } };
static spr_array snc3 = { 1, { { -16, -24, 0, 3 } } };
static spr_array snc4 = { 1, { { -16, -24, 0, 4 } } };
static spr_array* ptsonic[5] = { &snc0, &snc1, &snc2, &snc3, &snc4 };
static spr_array atm0 = { 1, { { -16, -16, 0, 5 } } };
static spr_array atm1 = { 1, { { -16, -16, 0, 6 } } };
static spr_array atm2 = { 1, { { -24, -24, 0, 7 } } };
static spr_array atm3 = { 1, { { -16, -16, 0, 8 } } };
static spr_array atm4 = { 1, { { -16, -24, 0, 9 } } };
static spr_array* spr_atom[5] = { &atm0, &atm1, &atm2, &atm3, &atm4 };
static unsigned short code_tbl[3] = { 1, 5, 9 };
static unsigned short wColwk;
static int FadeCount;
static unsigned char clfflg;
static palette_entry colorsave[64];
static unsigned char byMskwk;
static unsigned char SeToWavTbl[80] = {
   0,  1,  2,  3,  4,  5,  6,  7,  8,  9,
  10, 11, 11, 12, 13, 14, 15, 16, 17, 18,
  19, 20, 20, 21, 22, 22, 23, 23, 24, 25,
  26, 27, 28, 29, 30, 31, 43, 44, 45, 46,
  47, 48, 49, 50, 51, 52, 53, 54, 55, 56,
  57, 58, 58, 59, 60, 61, 62, 63, 64, 65,
  67, 68, 69, 70, 71, 71, 72, 73, 74, 32,
  33, 34, 35, 36, 37, 38, 39, 40, 41, 42
};
dlink_export ExportedFunctions = {
  &game_init,
  (void (*))&game,
  &DLL_meminit,
  &DLL_memfree,
  (void (*)(short, short))&SWdataSet,
  &Get_vscroll,
  &Get_scra_h_posiw,
  &Get_scrb_h_posiw,
  &FadeProc,
  &SetDebugFlag,
  0,
  0
};
int(*sGetFileSize)(int);







void DLL_meminit(char*** pBufTbl, void** pFuncTbl) { /* Line 94, Address: 0x1000000 */


  SetGrid = *pFuncTbl++; /* Line 97, Address: 0x100000c */
  EAsprset = *pFuncTbl++;  /* Line 98, Address: 0x1000024 */
  ClrSpriteDebug = *pFuncTbl++; /* Line 99, Address: 0x100003c */
  WaveRequest = *pFuncTbl++; /* Line 100, Address: 0x1000054 */
  CDPlay = *pFuncTbl++; /* Line 101, Address: 0x100006c */
  ++pFuncTbl; /* Line 102, Address: 0x1000084 */
  ChangeTileBmp = *pFuncTbl++; /* Line 103, Address: 0x1000090 */
  ++pFuncTbl; /* Line 104, Address: 0x10000a8 */
  ++pFuncTbl; /* Line 105, Address: 0x10000b4 */
  ++pFuncTbl; /* Line 106, Address: 0x10000c0 */
  ++pFuncTbl; /* Line 107, Address: 0x10000cc */

  ++pFuncTbl; /* Line 109, Address: 0x10000d8 */
  ++pFuncTbl; /* Line 110, Address: 0x10000e4 */
  sMemSet = *pFuncTbl++; /* Line 111, Address: 0x10000f0 */
  sMemCpy = *pFuncTbl++; /* Line 112, Address: 0x1000108 */
  ++pFuncTbl; /* Line 113, Address: 0x1000120 */
  sRandom = *pFuncTbl++; /* Line 114, Address: 0x100012c */
  ++pFuncTbl; /* Line 115, Address: 0x1000144 */
  ++pFuncTbl; /* Line 116, Address: 0x1000150 */
  ++pFuncTbl; /* Line 117, Address: 0x100015c */
  sPrintf = *pFuncTbl++; /* Line 118, Address: 0x1000168 */
  sOutputDebugString = *pFuncTbl++; /* Line 119, Address: 0x1000180 */
  sOpenFile = *pFuncTbl++; /* Line 120, Address: 0x1000198 */
  sReadFile = *pFuncTbl++; /* Line 121, Address: 0x10001b0 */
  sCloseFile = *pFuncTbl++; /* Line 122, Address: 0x10001c8 */



  pmapwk = (unsigned short*)**pBufTbl++; /* Line 126, Address: 0x10001e0 */
  lpcolorwk = (palette_entry*)**pBufTbl++; /* Line 127, Address: 0x10001fc */
  lpcolorwk2 = (palette_entry*)**pBufTbl++; /* Line 128, Address: 0x1000218 */
  lpcolorwk3 = (palette_entry*)**pBufTbl++; /* Line 129, Address: 0x1000234 */
  lpcolorwk4 = (palette_entry*)**pBufTbl++; /* Line 130, Address: 0x1000250 */
  lphscrollbuff = (int_union*)**pBufTbl++; /* Line 131, Address: 0x100026c */
  lpFadeFlag = (int*)*pBufTbl++; /* Line 132, Address: 0x1000288 */
  lpKeepWork = (game_info*)*pBufTbl++; /* Line 133, Address: 0x10002a0 */

  lpKeepWork->pSprBmp = SprBmp; /* Line 135, Address: 0x10002b8 */


} /* Line 138, Address: 0x10002cc */



void DLL_memfree() {} /* Line 142, Address: 0x10002e0 */


int Get_vscroll() {
  return vscroll.l; /* Line 146, Address: 0x10002f0 */
} /* Line 147, Address: 0x10002f8 */

int Get_scra_h_posiw() {
  return scra_h_posiw.l; /* Line 150, Address: 0x1000300 */
} /* Line 151, Address: 0x1000308 */

int Get_scrb_h_posiw() {
  return scrb_h_posiw.l; /* Line 154, Address: 0x1000310 */
} /* Line 155, Address: 0x1000318 */


void SetDebugFlag(unsigned int NewVal) { /* Line 158, Address: 0x1000320 */
  if (NewVal == 1) debugflag.w |= 256; /* Line 159, Address: 0x1000328 */
  else debugflag.w &= -257; /* Line 160, Address: 0x1000354 */

} /* Line 162, Address: 0x100036c */







void game_init() { /* Line 170, Address: 0x1000380 */
  int i;

  sMemSet(actwk, 0, sizeof(actwk)); /* Line 173, Address: 0x100038c */

  scra_h_posit.l = 0; /* Line 175, Address: 0x10003ac */
  scra_v_posit.l = 0; /* Line 176, Address: 0x10003b4 */
  scrb_h_posit.l = 0; /* Line 177, Address: 0x10003bc */
  scrb_v_posit.l = 0; /* Line 178, Address: 0x10003c4 */
  scrc_h_posit.l = 0; /* Line 179, Address: 0x10003cc */
  scrc_v_posit.l = 0; /* Line 180, Address: 0x10003d4 */
  scrz_h_posit.l = 0; /* Line 181, Address: 0x10003dc */
  scrz_v_posit.l = 0; /* Line 182, Address: 0x10003e4 */

  for (i = 0; i < 32; ++i) { /* Line 184, Address: 0x10003ec */
    lpcolorwk[i] = colortbl[i]; /* Line 185, Address: 0x10003f8 */
  } /* Line 186, Address: 0x1000438 */
  soundset(216); /* Line 187, Address: 0x1000448 */
  clwin_init(); /* Line 188, Address: 0x1000454 */
  gmtime0 = 420; /* Line 189, Address: 0x100045c */
  clwin(); /* Line 190, Address: 0x1000468 */

} /* Line 192, Address: 0x1000470 */



sprite_status* atomwk_search() { /* Line 196, Address: 0x1000490 */
  int i;


  for (i = 4; i < 32; ++i) { /* Line 200, Address: 0x1000498 */
    if (!actwk[i].actno) return &actwk[i]; /* Line 201, Address: 0x10004a4 */
  } /* Line 202, Address: 0x10004e8 */
  return &actwk[4]; /* Line 203, Address: 0x10004f8 */
} /* Line 204, Address: 0x1000500 */



int game() { /* Line 208, Address: 0x1000510 */
  sprite_status* pActwk;
  unsigned short wD0;

  if (!gmtime0) /* Line 212, Address: 0x1000520 */
    return 1; /* Line 213, Address: 0x1000530 */

  clchg(); /* Line 215, Address: 0x100053c */
  wD0 = gmtime1 & 3; /* Line 216, Address: 0x1000544 */
  if (!wD0) { /* Line 217, Address: 0x100055c */
    wD0 = setcnt++; /* Line 218, Address: 0x1000564 */
    setcnt &= 3; /* Line 219, Address: 0x100057c */
    actwk[wD0].actno = 1; /* Line 220, Address: 0x1000590 */
  }

  wD0 = gmtime1 & 3; /* Line 223, Address: 0x10005b4 */
  if (!wD0) { /* Line 224, Address: 0x10005cc */
    pActwk = atomwk_search(); /* Line 225, Address: 0x10005d4 */
    pActwk->actno = 2; /* Line 226, Address: 0x10005e0 */
  }

  action(); /* Line 229, Address: 0x10005e8 */
  patset(); /* Line 230, Address: 0x10005f0 */

  --gmtime0; /* Line 232, Address: 0x10005f8 */
  ++gmtime1; /* Line 233, Address: 0x100060c */
  vscroll.w.h -= 4; /* Line 234, Address: 0x1000620 */

  if (!gmtime0 || swdata.b.l & 128) { /* Line 236, Address: 0x1000634 */
    gmtime0 = 0; /* Line 237, Address: 0x100065c */
    clwout(); /* Line 238, Address: 0x1000664 */
  }
  return 0; /* Line 240, Address: 0x100066c */
} /* Line 241, Address: 0x1000670 */

























void sonic0(sprite_status* pActwk) { /* Line 267, Address: 0x1000690 */
  pActwk->sproffset = 32768; /* Line 268, Address: 0x1000698 */
  pActwk->patbase = ptsonic; /* Line 269, Address: 0x10006a4 */
  pActwk->xposi.w.h = 288; /* Line 270, Address: 0x10006b4 */
  pActwk->yposi.w.h = 416; /* Line 271, Address: 0x10006c0 */
  ++pActwk->r_no0; /* Line 272, Address: 0x10006cc */
} /* Line 273, Address: 0x10006dc */

void sonic1(sprite_status* pActwk) { /* Line 275, Address: 0x10006f0 */
  pActwk->yposi.w.h -= 8; /* Line 276, Address: 0x10006f8 */
  if (pActwk->yposi.w.h == 248) { /* Line 277, Address: 0x1000708 */
    ++pActwk->r_no0; /* Line 278, Address: 0x1000724 */
    pActwk->actfree[8] = 240; /* Line 279, Address: 0x1000734 */
  }

} /* Line 282, Address: 0x1000740 */

void sonic2(sprite_status* pActwk) { /* Line 284, Address: 0x1000750 */
  --pActwk->actfree[8]; /* Line 285, Address: 0x1000758 */
  if (pActwk->actfree[8] == 0) { /* Line 286, Address: 0x1000768 */
    ++pActwk->r_no0; /* Line 287, Address: 0x100077c */
  }

} /* Line 290, Address: 0x100078c */

void sonic3(sprite_status* pActwk) { /* Line 292, Address: 0x10007a0 */
  pActwk->yposi.w.h -= 8; /* Line 293, Address: 0x10007a8 */
  if (pActwk->yposi.w.h == 96) { /* Line 294, Address: 0x10007b8 */
    ++pActwk->r_no0; /* Line 295, Address: 0x10007d4 */
  }

} /* Line 298, Address: 0x10007e4 */

void sonic_act(sprite_status* pActwk) { /* Line 300, Address: 0x10007f0 */
  if (gmtime1 & 1) { /* Line 301, Address: 0x10007fc */
    ++pActwk->patno; /* Line 302, Address: 0x1000814 */
    if (pActwk->patno >= 5) pActwk->patno = 0; /* Line 303, Address: 0x1000824 */
  }
  pActwk->patno = actwk[0].patno; /* Line 305, Address: 0x1000844 */


  switch (pActwk->r_no0) { /* Line 308, Address: 0x1000854 */
    case 0:
      sonic0(pActwk); /* Line 310, Address: 0x1000894 */
      break; /* Line 311, Address: 0x10008a0 */
    case 1:
      sonic1(pActwk); /* Line 313, Address: 0x10008a8 */
      break; /* Line 314, Address: 0x10008b4 */
    case 2:
      sonic2(pActwk); /* Line 316, Address: 0x10008bc */
      break; /* Line 317, Address: 0x10008c8 */
    case 3:
      sonic3(pActwk); /* Line 319, Address: 0x10008d0 */
  }





  actionsub(pActwk); /* Line 326, Address: 0x10008dc */

} /* Line 328, Address: 0x10008e8 */
























void atom1(sprite_status* pActwk) { /* Line 353, Address: 0x1000900 */
  int lD0;

  lD0 = *(int*)&pActwk->actfree[0]; /* Line 356, Address: 0x1000910 */
  pActwk->xposi.l += lD0; /* Line 357, Address: 0x100091c */

  lD0 = *(int*)&pActwk->actfree[4]; /* Line 359, Address: 0x100092c */
  pActwk->yposi.l += lD0; /* Line 360, Address: 0x1000938 */

  --pActwk->actfree[8]; /* Line 362, Address: 0x1000948 */
  if (pActwk->actfree[8]) { /* Line 363, Address: 0x1000958 */
    actionsub(pActwk); /* Line 364, Address: 0x1000968 */
  } /* Line 365, Address: 0x1000974 */
  else {
    frameout(pActwk); /* Line 367, Address: 0x100097c */
  }

} /* Line 370, Address: 0x1000988 */


void atom0(sprite_status* pActwk) { /* Line 373, Address: 0x10009a0 */
  int_union lD0, lD1;
  pActwk->sproffset = 32768; /* Line 375, Address: 0x10009ac */
  pActwk->patbase = spr_atom; /* Line 376, Address: 0x10009b8 */
  ++pActwk->r_no0; /* Line 377, Address: 0x10009c8 */


  lD0.l = lD1.l = sRandom(); /* Line 380, Address: 0x10009d8 */
  lD0.l = ((lD0.l << 46) >> 46); /* Line 381, Address: 0x10009f0 */
  *(int*)&pActwk->actfree[4] = lD0.l; /* Line 382, Address: 0x1000a00 */
  lD1.w.l &= 31; /* Line 383, Address: 0x1000a10 */
  pActwk->xposi.w.h = actwk[0].xposi.w.h - 16 + lD1.w.l; /* Line 384, Address: 0x1000a1c */
  pActwk->yposi.w.h = actwk[0].yposi.w.h - 24; /* Line 385, Address: 0x1000a50 */
  pActwk->actfree[8] = 45; /* Line 386, Address: 0x1000a74 */
  atom1(pActwk); /* Line 387, Address: 0x1000a80 */
} /* Line 388, Address: 0x1000a8c */


void atom(sprite_status* pActwk) { /* Line 391, Address: 0x1000aa0 */
  if (gmtime1 & 1) { /* Line 392, Address: 0x1000aac */
    ++pActwk->patno; /* Line 393, Address: 0x1000ac4 */
    if (pActwk->patno >= 5) pActwk->patno = 0; /* Line 394, Address: 0x1000ad4 */
  }
  switch (pActwk->r_no0) { /* Line 396, Address: 0x1000af4 */
    case 0:
      atom0(pActwk); /* Line 398, Address: 0x1000b1c */
      break; /* Line 399, Address: 0x1000b28 */
    case 1:
      atom1(pActwk); /* Line 401, Address: 0x1000b30 */
  }



} /* Line 406, Address: 0x1000b3c */



void clchg() { /* Line 410, Address: 0x1000b50 */
  unsigned short wD0;
  int i;

  ++clchg_cnt[0]; /* Line 414, Address: 0x1000b5c */
  if ((clchg_cnt[0] & 1) == 0) { /* Line 415, Address: 0x1000b70 */


    wD0 = clchg_cnt[1]; /* Line 418, Address: 0x1000b88 */
    ++clchg_cnt[1]; /* Line 419, Address: 0x1000b94 */
    if (clchg_cnt[1] >= 14) { /* Line 420, Address: 0x1000ba8 */
      clchg_cnt[1] = 0; /* Line 421, Address: 0x1000bc0 */
    }
    for (i = 17; i < 31; ++i) { /* Line 423, Address: 0x1000bc8 */
      lpcolorwk[i] = clchg_tbl[wD0++]; /* Line 424, Address: 0x1000bd4 */
    } /* Line 425, Address: 0x1000c24 */
  }
} /* Line 427, Address: 0x1000c34 */





























void clwout() {
  clfflg = 1; /* Line 458, Address: 0x1000c50 */
  *lpFadeFlag = 2; /* Line 459, Address: 0x1000c5c */
  FadeCount = 8; /* Line 460, Address: 0x1000c6c */
  wColwk = 0; /* Line 461, Address: 0x1000c78 */
} /* Line 462, Address: 0x1000c80 */


void clwout_new() { /* Line 465, Address: 0x1000c90 */
  if (wColwk >= 3) { /* Line 466, Address: 0x1000c98 */

    *lpFadeFlag = 0; /* Line 468, Address: 0x1000cb0 */
    return; /* Line 469, Address: 0x1000cbc */
  }
  if (--FadeCount >= 0) { /* Line 471, Address: 0x1000cc4 */

    woutcolor(code_tbl[wColwk]); /* Line 473, Address: 0x1000ce0 */
    return; /* Line 474, Address: 0x1000d08 */
  }

  FadeCount = 8; /* Line 477, Address: 0x1000d10 */
  ++wColwk; /* Line 478, Address: 0x1000d1c */

} /* Line 480, Address: 0x1000d30 */











void woutcolor(unsigned short wD1) { /* Line 492, Address: 0x1000d40 */
  short i;
  palette_entry* lpColwk;


  lpColwk = lpcolorwk; /* Line 497, Address: 0x1000d50 */
  for (i = 0; i < 64; ++i, ++lpColwk) { /* Line 498, Address: 0x1000d58 */

    switch (wD1) { /* Line 500, Address: 0x1000d64 */

      case 1:
        if (lpColwk->peRed < 224) { /* Line 503, Address: 0x1000d98 */
          lpColwk->peRed += 32; /* Line 504, Address: 0x1000dac */
        }
        break; /* Line 506, Address: 0x1000db8 */
      case 5:
        if (lpColwk->peGreen < 224) { /* Line 508, Address: 0x1000dc0 */
          lpColwk->peGreen += 32; /* Line 509, Address: 0x1000dd4 */
        }
        break; /* Line 511, Address: 0x1000de0 */
      case 9:
        if (lpColwk->peBlue < 224) { /* Line 513, Address: 0x1000de8 */
          lpColwk->peBlue += 32; /* Line 514, Address: 0x1000dfc */
        }
        break;
    }
  } /* Line 518, Address: 0x1000e08 */

} /* Line 520, Address: 0x1000e2c */











void clwin_init() { /* Line 532, Address: 0x1000e40 */
  short i;
  palette_entry* lpColwk;
  palette_entry* lpSavewk;
  palette_entry tmp = { 224, 224, 224, 1 }; /* Line 536, Address: 0x1000e50 */

  lpColwk = lpcolorwk; /* Line 538, Address: 0x1000e64 */
  lpSavewk = colorsave; /* Line 539, Address: 0x1000e6c */
  for (i = 0; i < 64; ++i) { /* Line 540, Address: 0x1000e74 */

    *lpSavewk++ = *lpColwk; /* Line 542, Address: 0x1000e80 */
    *lpSavewk++ = tmp; /* Line 543, Address: 0x1000ea8 */
  } /* Line 544, Address: 0x1000ed4 */
} /* Line 545, Address: 0x1000ef4 */











void clwin() {
  *lpFadeFlag = 1; /* Line 558, Address: 0x1000f10 */
  FadeCount = 8; /* Line 559, Address: 0x1000f20 */
  wColwk = 0; /* Line 560, Address: 0x1000f2c */
  byMskwk = 224; /* Line 561, Address: 0x1000f34 */
} /* Line 562, Address: 0x1000f40 */


void clwin_new() { /* Line 565, Address: 0x1000f50 */
  if (wColwk >= 3) { /* Line 566, Address: 0x1000f58 */

    *lpFadeFlag = 0; /* Line 568, Address: 0x1000f70 */
    return; /* Line 569, Address: 0x1000f7c */
  }
  if (--FadeCount >= 0) { /* Line 571, Address: 0x1000f84 */

    wincolor(byMskwk, code_tbl[wColwk]); /* Line 573, Address: 0x1000fa0 */
    byMskwk -= 32; /* Line 574, Address: 0x1000fd0 */
    return; /* Line 575, Address: 0x1000fe4 */
  }

  FadeCount = 8; /* Line 578, Address: 0x1000fec */
  byMskwk = 224; /* Line 579, Address: 0x1000ff8 */
  ++wColwk; /* Line 580, Address: 0x1001004 */

} /* Line 582, Address: 0x1001018 */











void wincolor(unsigned char byD0, unsigned short wD1) { /* Line 594, Address: 0x1001030 */
  short i;
  unsigned char byColwk;
  palette_entry *lpColwk, *lpSavewk;

  lpColwk = lpcolorwk; /* Line 599, Address: 0x100104c */
  lpSavewk = colorsave; /* Line 600, Address: 0x1001054 */
  for (i = 0; i < 64; ++i) { /* Line 601, Address: 0x100105c */

    switch (wD1) { /* Line 603, Address: 0x1001068 */

      case 1:
        byColwk = lpSavewk->peRed; /* Line 606, Address: 0x100109c */
        if (byColwk < byD0) byColwk = byD0; /* Line 607, Address: 0x10010a4 */
        lpColwk->peRed = byColwk; /* Line 608, Address: 0x10010c4 */
        break; /* Line 609, Address: 0x10010c8 */
      case 5:
        byColwk = lpSavewk->peGreen; /* Line 611, Address: 0x10010d0 */
        if (byColwk < byD0) byColwk = byD0; /* Line 612, Address: 0x10010d8 */
        lpColwk->peGreen = byColwk; /* Line 613, Address: 0x10010f8 */
        break; /* Line 614, Address: 0x10010fc */
      case 9:
        byColwk = lpSavewk->peBlue; /* Line 616, Address: 0x1001104 */
        if (byColwk < byD0) byColwk = byD0; /* Line 617, Address: 0x100110c */
        lpColwk->peBlue = byColwk; /* Line 618, Address: 0x100112c */
        break;
    }
    ++lpSavewk; /* Line 621, Address: 0x1001130 */
    ++lpColwk; /* Line 622, Address: 0x1001134 */
  } /* Line 623, Address: 0x1001138 */


} /* Line 626, Address: 0x1001158 */












int FadeProc() { /* Line 639, Address: 0x1001180 */
  switch (*lpFadeFlag) { /* Line 640, Address: 0x1001188 */

    case 1:
      clwin_new(); /* Line 643, Address: 0x10011b4 */
      break; /* Line 644, Address: 0x10011bc */
    case 2:
      clwout_new(); /* Line 646, Address: 0x10011c4 */
      break;
  }
  return 0; /* Line 649, Address: 0x10011cc */
} /* Line 650, Address: 0x10011d0 */














void soundset(short ReqNo) { /* Line 665, Address: 0x10011e0 */
  if (ReqNo == 171) return; /* Line 666, Address: 0x10011ec */



  ReqNo -= 144; /* Line 670, Address: 0x1001204 */
  ReqNo = SeToWavTbl[ReqNo]; /* Line 671, Address: 0x1001210 */

  WaveRequest(ReqNo); /* Line 673, Address: 0x100123c */
} /* Line 674, Address: 0x1001250 */
