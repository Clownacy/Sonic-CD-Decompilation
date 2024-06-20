#include "..\..\TYPES.H"
#include "..\COMMON\SCORE_DATA_TYPES.H"
#include "THANKS_TYPES.H"
#include "GAME.H"
#include "BM_M.H"
#include "ETC_M.H"
#include "IO.H"
#include "SPM.H"

static PALETTEENTRY endingcol[64] = {
  {   0,   0,   0, 1 }, {   0,   0,   0, 1 }, {   0,   0,   0, 1 }, {   0,   0, 224, 1 },
  {  96,  96, 224, 1 }, { 128, 128, 224, 1 }, { 224, 224, 224, 1 }, { 160, 160, 160, 1 },
  { 128, 128, 128, 1 }, {  64,  64,  64, 1 }, {   0,   0,   0, 1 }, {   0,   0,   0, 1 },
  {   0,   0,   0, 1 }, {   0,   0,   0, 1 }, {   0,   0,   0, 1 }, { 224, 224,   0, 1 },
  {   0,   0,   0, 1 }, {   0,   0,   0, 1 }, {   0,   0,   0, 1 }, {   0,   0,   0, 1 },
  {   0,   0,   0, 1 }, {   0,   0,   0, 1 }, {   0,   0,   0, 1 }, {   0,   0,   0, 1 },
  {   0,   0,   0, 1 }, {   0,   0,   0, 1 }, {   0,   0,   0, 1 }, {   0,   0,   0, 1 },
  {   0,   0,   0, 1 }, {   0,   0,   0, 1 }, {   0,   0,   0, 1 }, {   0,   0,   0, 1 },
  {   0,   0,   0, 1 }, {   0,   0,   0, 1 }, {   0,   0,   0, 1 }, {   0,   0,   0, 1 },
  {   0,   0,   0, 1 }, {   0,   0,   0, 1 }, {   0,   0,   0, 1 }, {   0,   0,   0, 1 },
  {   0,   0,   0, 1 }, {   0,   0,   0, 1 }, {   0,   0,   0, 1 }, {   0,   0,   0, 1 },
  {   0,   0,   0, 1 }, {   0,   0,   0, 1 }, {   0,   0,   0, 1 }, {   0,   0,   0, 1 },
  {   0,   0,   0, 1 }, {   0,   0,   0, 1 }, {   0,   0,   0, 1 }, {   0,   0,   0, 1 },
  {   0,   0,   0, 1 }, {   0,   0,   0, 1 }, {   0,   0,   0, 1 }, {   0,   0,   0, 1 },
  {   0,   0,   0, 1 }, {   0,   0,   0, 1 }, {   0,   0,   0, 1 }, {   0,   0,   0, 1 },
  {   0,   0,   0, 1 }, {   0,   0,   0, 1 }, {   0,   0,   0, 1 }, {   0,   0,   0, 1 }
};
static unsigned short gEndingMesTimer;
static game_info* lpKeepWork;
extern bmp_info SprBmp[700];
score_data* lpScorData;
unsigned int* lpghWnd;
unsigned int* lphSurf;
extern int* lpFadeFlag;
extern int_union* lphscrollbuff;
extern PALETTEENTRY* lpcolorwk3;
extern PALETTEENTRY* lpcolorwk2;
extern PALETTEENTRY* lpcolorwk1;
extern PALETTEENTRY* lpcolorwk0;
void(*sCloseFile)(int);
int(*sReadFile)(int, void*, int);
int(*sOpenFile)(char*);
void(*sOutputDebugString)(char*);
void(*sPrintf)(char*, char*);
char*(*sStrcpy)(char*, char*);
int(*sRandom)();
int(*sMemCmp)(void*, void*, int);
void(*sMemCpy)(void*, void*, int);
void(*sMemSet)(void*, unsigned char, int);
void(*ChangeTileBmp)(int, int);
void(*CDPlay)(short);
void(*WaveRequest)(short);
void(*ClrSpriteDebug)();
void(*EAsprset)(short, short, unsigned short, unsigned short, unsigned short);
int(*SetGrid)(int, int, int, int, int);
extern short_union swdata2;
extern short_union swdata1;
extern short end_timer;
extern short heart_tm;
extern short posetimer;
extern short colorno2;
extern short coltimer2;
extern short colorno;
extern short coltimer;
extern unsigned short lpbs_timer[32];
extern unsigned char quit_flg;
extern PALETTEENTRY* asc_coltbl[2];
extern PALETTEENTRY* lpbs_good[32];
extern short animal_timer;
extern unsigned char animal_flg;
extern sprite_status_thanks actwk[66];
extern unsigned short* asc_maptbl[];
dlink_export ExportedFunctions = {
  &game_init,
  (void (*)())&game,
  &DLL_meminit,
  &DLL_memfree,
  (void (*)(short, short))&SWdataSet,
  0,
  0,
  0,
  0,
  0,
  0,
  0
};
int(*sGetFileSize)(int);





























void DLL_meminit(char*** pBufTbl, void** pFuncTbl) { /* Line 117, Address: 0x1001dc0 */

  SetGrid = *pFuncTbl++; /* Line 119, Address: 0x1001dcc */
  EAsprset = *pFuncTbl++; /* Line 120, Address: 0x1001de4 */
  ClrSpriteDebug = *pFuncTbl++; /* Line 121, Address: 0x1001dfc */
  WaveRequest = *pFuncTbl++; /* Line 122, Address: 0x1001e14 */
  CDPlay = *pFuncTbl++; /* Line 123, Address: 0x1001e2c */
  ++pFuncTbl; /* Line 124, Address: 0x1001e44 */
  ChangeTileBmp = *pFuncTbl++; /* Line 125, Address: 0x1001e50 */

  ++pFuncTbl; /* Line 127, Address: 0x1001e68 */
  ++pFuncTbl; /* Line 128, Address: 0x1001e74 */
  ++pFuncTbl; /* Line 129, Address: 0x1001e80 */
  ++pFuncTbl; /* Line 130, Address: 0x1001e8c */

  ++pFuncTbl; /* Line 132, Address: 0x1001e98 */
  ++pFuncTbl; /* Line 133, Address: 0x1001ea4 */
  sMemSet = *pFuncTbl++; /* Line 134, Address: 0x1001eb0 */
  sMemCpy = *pFuncTbl++; /* Line 135, Address: 0x1001ec8 */
  sMemCmp = *pFuncTbl++; /* Line 136, Address: 0x1001ee0 */
  sRandom = *pFuncTbl++; /* Line 137, Address: 0x1001ef8 */
  sStrcpy = *pFuncTbl++; /* Line 138, Address: 0x1001f10 */
  ++pFuncTbl; /* Line 139, Address: 0x1001f28 */
  ++pFuncTbl; /* Line 140, Address: 0x1001f34 */
  sPrintf = *pFuncTbl++; /* Line 141, Address: 0x1001f40 */
  sOutputDebugString = *pFuncTbl++; /* Line 142, Address: 0x1001f58 */
  sOpenFile = *pFuncTbl++; /* Line 143, Address: 0x1001f70 */
  sReadFile = *pFuncTbl++; /* Line 144, Address: 0x1001f88 */
  sCloseFile = *pFuncTbl++; /* Line 145, Address: 0x1001fa0 */



  ++pBufTbl; /* Line 149, Address: 0x1001fb8 */
  lpcolorwk0 = (PALETTEENTRY*)**pBufTbl++; /* Line 150, Address: 0x1001fc4 */
  lpcolorwk1 = (PALETTEENTRY*)**pBufTbl++; /* Line 151, Address: 0x1001fe0 */
  lpcolorwk2 = (PALETTEENTRY*)**pBufTbl++; /* Line 152, Address: 0x1001ffc */
  lpcolorwk3 = (PALETTEENTRY*)**pBufTbl++; /* Line 153, Address: 0x1002018 */
  lphscrollbuff = (int_union*)**pBufTbl++; /* Line 154, Address: 0x1002034 */
  lpFadeFlag = (int*)*pBufTbl++; /* Line 155, Address: 0x1002050 */
  lpKeepWork = (game_info*)*pBufTbl++; /* Line 156, Address: 0x1002068 */
  lphSurf = (unsigned int*)*pBufTbl++; /* Line 157, Address: 0x1002080 */
  lpghWnd = (unsigned int*)*pBufTbl++; /* Line 158, Address: 0x1002098 */
  lpScorData = (score_data*)*pBufTbl++; /* Line 159, Address: 0x10020b0 */

  lpKeepWork->pSprBmp = SprBmp; /* Line 161, Address: 0x10020c8 */


} /* Line 164, Address: 0x10020dc */








void DLL_memfree() {} /* Line 173, Address: 0x10020f0 */







void SWdataSet(ushort_union sw1, ushort_union sw2) { /* Line 181, Address: 0x1002100 */
  swdata1.w = sw1.w; /* Line 182, Address: 0x100210c */
  swdata2.w = sw2.w; /* Line 183, Address: 0x1002118 */

} /* Line 185, Address: 0x1002124 */






void game_init() { /* Line 192, Address: 0x1002130 */
  WorkRamClear(); /* Line 193, Address: 0x1002138 */

  swdata1.w = -4096; /* Line 195, Address: 0x1002140 */

  cgmwrt_a(); /* Line 197, Address: 0x100214c */
  cgmwrt_b(); /* Line 198, Address: 0x1002154 */


  EndingMesColor(); /* Line 201, Address: 0x100215c */

  coltimer = lpbs_timer[0]; /* Line 203, Address: 0x1002164 */
  colorno = 0; /* Line 204, Address: 0x1002174 */

  coltimer2 = 20; /* Line 206, Address: 0x100217c */
  colorno2 = 1; /* Line 207, Address: 0x1002188 */

  posetimer = 1536; /* Line 209, Address: 0x1002194 */
  heart_tm = 1; /* Line 210, Address: 0x10021a0 */

  end_timer = 10800; /* Line 212, Address: 0x10021ac */
} /* Line 213, Address: 0x10021b8 */






int game() { /* Line 220, Address: 0x10021d0 */


  if (EndingMes() != 0) return 0; /* Line 223, Address: 0x10021d8 */
  if (lpKeepWork->EndingMesType & 2) { /* Line 224, Address: 0x10021f4 */
    return -1; /* Line 225, Address: 0x1002210 */
  }

  mainloop(); /* Line 228, Address: 0x100221c */

  v_int(); /* Line 230, Address: 0x1002224 */

  if (quit_flg) return -1; /* Line 232, Address: 0x100222c */
  return 0; /* Line 233, Address: 0x1002248 */
} /* Line 234, Address: 0x100224c */



void cgmwrt_a() { /* Line 238, Address: 0x1002260 */
  int x, y, TileNo;
  short aMap[2048], *pMap;
  unsigned int hf;

  sMemSet(aMap, 0, sizeof(aMap)); /* Line 243, Address: 0x100227c */
  if ((hf = sOpenFile("TITLE\\THANKS\\MAP\\VA_MAP.BIN")) == -1) { /* Line 244, Address: 0x1002298 */

    sOutputDebugString("Map Load Error [va_map.bin]\n"); /* Line 246, Address: 0x10022c0 */
  } /* Line 247, Address: 0x10022d8 */
  else {

    sReadFile(hf, aMap, sizeof(aMap)); /* Line 250, Address: 0x10022e0 */
    sCloseFile(hf); /* Line 251, Address: 0x10022fc */
  }
  for (y = 0; y < 28; ++y) { /* Line 253, Address: 0x1002310 */

    pMap = &aMap[y * 64]; /* Line 255, Address: 0x100231c */
    for (x = 0; x < 40; ++x) { /* Line 256, Address: 0x100232c */

      TileNo = *pMap++; /* Line 258, Address: 0x1002338 */
      if (TileNo & 1023) TileNo += 174; /* Line 259, Address: 0x100234c */
      if ((TileNo & 1023) >= 461) TileNo = 0; /* Line 260, Address: 0x100235c */

      SetGrid(0, x, y, TileNo, 0); /* Line 262, Address: 0x1002370 */
    } /* Line 263, Address: 0x1002394 */
  } /* Line 264, Address: 0x10023a4 */
} /* Line 265, Address: 0x10023b4 */

void cgmwrt_b() { /* Line 267, Address: 0x10023e0 */
  int x, y, TileNo;
  short bMap[2048], *pMap;
  unsigned int hf;

  sMemSet(bMap, 0, sizeof(bMap)); /* Line 272, Address: 0x10023fc */
  if ((hf = sOpenFile("TITLE\\THANKS\\MAP\\VB_MAP.BIN")) == -1) { /* Line 273, Address: 0x1002418 */

    sOutputDebugString("Map Load Error [vb_map.bin]\n"); /* Line 275, Address: 0x1002440 */
  } /* Line 276, Address: 0x1002458 */
  else {

    sReadFile(hf, bMap, sizeof(bMap)); /* Line 279, Address: 0x1002460 */
    sCloseFile(hf); /* Line 280, Address: 0x100247c */
  }
  for (y = 0; y < 28; ++y) { /* Line 282, Address: 0x1002490 */

    pMap = &bMap[y * 64]; /* Line 284, Address: 0x100249c */
    for (x = 0; x < 40; ++x) { /* Line 285, Address: 0x10024ac */

      TileNo = *pMap++; /* Line 287, Address: 0x10024b8 */
      if (TileNo & 1023) TileNo -= 154; /* Line 288, Address: 0x10024cc */
      if ((TileNo & 1023) >= 329) TileNo = 0; /* Line 289, Address: 0x10024dc */
      SetGrid(1, x, y, TileNo, 0); /* Line 290, Address: 0x10024f0 */
    } /* Line 291, Address: 0x1002514 */
  } /* Line 292, Address: 0x1002524 */
} /* Line 293, Address: 0x1002534 */





void v_int() { /* Line 299, Address: 0x1002560 */
  PALETTEENTRY *lpDst, *lpSpr;
  int_union ld0;
  short i;
  short d0;

  if (animal_flg == 2) { /* Line 305, Address: 0x1002578 */

    if (--animal_timer <= 0) { /* Line 307, Address: 0x1002590 */

      animal_flg = 0; /* Line 309, Address: 0x10025bc */
    }
  }
  if (--posetimer <= 0) { /* Line 312, Address: 0x10025c4 */

    if (actwk[0].ACT_NO) { /* Line 314, Address: 0x10025f0 */

      animal_flg = 1; /* Line 316, Address: 0x1002600 */
    }
    animal_timer = 900; /* Line 318, Address: 0x100260c */
    ld0.l = random(); /* Line 319, Address: 0x1002618 */
    ld0.l &= 32767; /* Line 320, Address: 0x1002624 */
    ld0.w.l = (int)ld0.w.l % 4096; /* Line 321, Address: 0x1002630 */
    ld0.w.l += 8192; /* Line 322, Address: 0x1002664 */
    posetimer = ld0.w.l; /* Line 323, Address: 0x1002670 */
  }


  --coltimer; /* Line 327, Address: 0x100267c */
  if (coltimer <= 0) { /* Line 328, Address: 0x1002690 */

    if (colorno >= 31) { /* Line 330, Address: 0x10026a8 */

      colorno = 0; /* Line 332, Address: 0x10026c4 */
    }
    d0 = colorno; /* Line 334, Address: 0x10026cc */
    coltimer = lpbs_timer[d0]; /* Line 335, Address: 0x10026dc */
    ++colorno; /* Line 336, Address: 0x1002700 */

    lpSpr = lpbs_good[d0]; /* Line 338, Address: 0x1002714 */
    lpDst = lpcolorwk0 + 16; /* Line 339, Address: 0x1002730 */
    for (i = 0; i < 16; ++i) { /* Line 340, Address: 0x100273c */

      *lpDst++ = *lpSpr++; /* Line 342, Address: 0x1002748 */
    } /* Line 343, Address: 0x1002778 */
  }

  --coltimer2; /* Line 346, Address: 0x1002798 */
  if (coltimer2 <= 0) { /* Line 347, Address: 0x10027ac */

    if (colorno2 >= 2) { /* Line 349, Address: 0x10027c4 */

      colorno2 = 0; /* Line 351, Address: 0x10027e0 */
    }
    coltimer2 = 20; /* Line 353, Address: 0x10027e8 */
    d0 = colorno2; /* Line 354, Address: 0x10027f4 */
    ++colorno2; /* Line 355, Address: 0x1002804 */

    lpSpr = asc_coltbl[d0]; /* Line 357, Address: 0x1002818 */
    lpDst = lpcolorwk0 + 40; /* Line 358, Address: 0x1002834 */
    for (i = 0; i < 8; ++i) { /* Line 359, Address: 0x1002840 */

      *lpDst++ = *lpSpr++; /* Line 361, Address: 0x100284c */
    } /* Line 362, Address: 0x100287c */
  }


  if (--end_timer <= 0) { /* Line 366, Address: 0x100289c */

    quit_flg = 1; /* Line 368, Address: 0x10028c8 */
  }

} /* Line 371, Address: 0x10028d4 */








void PutAscii(unsigned short c, unsigned short XPos, unsigned short YPos) { /* Line 380, Address: 0x1002900 */
  int vcellno, i;
  unsigned short* pMap;

  pMap = asc_maptbl[c]; /* Line 384, Address: 0x1002920 */
  if (c == 27) { /* Line 385, Address: 0x100293c */
    vcellno = 4; /* Line 386, Address: 0x1002950 */
  } /* Line 387, Address: 0x1002954 */
  else vcellno = 3; /* Line 388, Address: 0x100295c */


  for (i = 0; i < vcellno; ++i) { /* Line 391, Address: 0x1002960 */
    SetGrid(0, XPos, YPos + i, *pMap++ + 32767 + 330, 0); /* Line 392, Address: 0x100296c */
    SetGrid(0, XPos + 1, YPos + i, *pMap++ + 32767 + 330, 0); /* Line 393, Address: 0x10029b0 */
  } /* Line 394, Address: 0x10029f8 */
} /* Line 395, Address: 0x1002a08 */


void soundset(short ReqNo) { /* Line 398, Address: 0x1002a30 */
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

  if (ReqNo == 171) return; /* Line 410, Address: 0x1002a3c */



  ReqNo -= 144; /* Line 414, Address: 0x1002a54 */
  ReqNo = (unsigned short)SeToWavTbl[ReqNo]; /* Line 415, Address: 0x1002a60 */

  WaveRequest(ReqNo); /* Line 417, Address: 0x1002a8c */
} /* Line 418, Address: 0x1002aa0 */



void EndingMesColor() { /* Line 422, Address: 0x1002ab0 */
  PALETTEENTRY *lpPeSrc, *lpPeDest;
  int i;

  lpPeSrc = endingcol; /* Line 426, Address: 0x1002ac0 */
  lpPeDest = lpcolorwk0; /* Line 427, Address: 0x1002ac8 */
  for (i = 0; i < 64; ++i) { /* Line 428, Address: 0x1002ad0 */
    *lpPeDest++ = *lpPeSrc++; /* Line 429, Address: 0x1002adc */
  } /* Line 430, Address: 0x1002b0c */
} /* Line 431, Address: 0x1002b1c */

int EndingMes() { /* Line 433, Address: 0x1002b40 */
  int i;

  ++gEndingMesTimer; /* Line 436, Address: 0x1002b4c */
  if (gEndingMesTimer > 360) { /* Line 437, Address: 0x1002b60 */
    gEndingMesTimer = 360; /* Line 438, Address: 0x1002b78 */
    return 0; /* Line 439, Address: 0x1002b84 */
  }









  if (lpKeepWork->EndingMesType & 1) { /* Line 450, Address: 0x1002b90 */
    switch (gEndingMesTimer) { /* Line 451, Address: 0x1002bac */

      case 1:
        EAsprset(224, 288, 76, 0, 0); /* Line 454, Address: 0x1002be4 */
        break; /* Line 455, Address: 0x1002c08 */

      case 180:
        EAsprset(208, 228, 77, 0, 0); /* Line 458, Address: 0x1002c10 */
        break; /* Line 459, Address: 0x1002c34 */
      case 360:
        if ((unsigned char)swdata1.b.l & 240) { /* Line 461, Address: 0x1002c3c */
          vdpinit(); /* Line 462, Address: 0x1002c58 */
        } /* Line 463, Address: 0x1002c60 */
        else {
          --gEndingMesTimer; /* Line 465, Address: 0x1002c68 */
        }
        break;
    }
  } /* Line 469, Address: 0x1002c7c */
  else if (lpKeepWork->EndingMesType & 2) { /* Line 470, Address: 0x1002c84 */
    switch (gEndingMesTimer) { /* Line 471, Address: 0x1002ca0 */

      case 1:
        EAsprset(252, 288, 75, 0, 0); /* Line 474, Address: 0x1002cd8 */
        break; /* Line 475, Address: 0x1002cfc */

      case 180:
        EAsprset(208, 228, 77, 0, 0); /* Line 478, Address: 0x1002d04 */
        break; /* Line 479, Address: 0x1002d28 */
      case 360:
        if ((unsigned char)swdata1.b.l & 240) { /* Line 481, Address: 0x1002d30 */


          for (i = 0; i < 64; ++i) { /* Line 484, Address: 0x1002d4c */
            lpcolorwk0[i].peRed = 0; /* Line 485, Address: 0x1002d58 */
            lpcolorwk0[i].peGreen = 0; /* Line 486, Address: 0x1002d6c */
            lpcolorwk0[i].peBlue = 0; /* Line 487, Address: 0x1002d80 */
          } /* Line 488, Address: 0x1002d94 */
        } /* Line 489, Address: 0x1002da4 */
        else {
          --gEndingMesTimer; /* Line 491, Address: 0x1002dac */
        }
    }
  }

  return 1; /* Line 496, Address: 0x1002dc0 */
} /* Line 497, Address: 0x1002dc4 */
