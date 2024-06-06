#include "..\..\TYPES.H"
#include "..\COMMON\SCORE_DATA_TYPES.H"
#include "..\COMMON\HMX_TYPES.H"
#include "OPNDO.H"
#include "..\COMMON\GRID.H"
#include "..\COMMON\PALT.H"
#include "..\COMMON\HMX_OEEACTL.H"
#include "OPNENTRY.H"

static void OEUpdateHand();
static void OEUpdateMayu();
static void OEUpdatePlanet();
static void OEUpdateMizu();
static void OEUpdateKumo();
static void GetEnabeMenu(unsigned int* menuTable);
static int GetNextMenu(unsigned int* menuTable, int kind, unsigned int bNext);
static void OEUpdateMsg();

typedef struct {
  unsigned short wrap;
  void* pSmorphArray;
}
smorph;

typedef struct {
  int StartX;
  int StartY;
  int DeltaX;
  int DeltaY;
}
smorph_data;

typedef struct {
  int time;
  POINT point;
}
time_point;

typedef struct {
  int time;
  unsigned short timingPatNo;
}
time_pat;

static time_point ptPlnt[8] = {
  {  16, { 240, -33 } },
  {  32, { 240, -34 } },
  {  48, { 240, -35 } },
  {  84, { 240, -34 } },
  { 100, { 240, -33 } },
  { 116, { 240, -32 } },
  { 128, { 240, -32 } },
  {  -1, {   0,   0 } }
};
static time_pat timeHand[16] = {
  {       0, 11 },
  { 1179648,  0 },
  {      10, 19 },
  {  589824,  0 },
  {      20,  8 },
  { 1376256,  0 },
  {       8, 22 },
  {  589824,  0 },
  {      23, 10 },
  { 1572864,  0 },
  {      11, 25 },
  {  720896,  0 },
  {      26, 10 },
  { 1769472,  0 },
  {       9, 18 },
  {  524288,  0 }
};
static int timeMayu[2] = { 18, 20 };
static int posiLeftArrow[3] = { 90, 88, 86 };
static int posiRightArrow[3] = { 210, 212, 214 };
static unsigned int bDrawDisable;
extern unsigned short nSequenceNum;
extern int nTimerCunt;
extern void(*hmx_sprite_set_position_module)(hmx_sprite*, int, int);
extern draw_context* s_ctx;
extern sprite_bmp infoSprtBmp[];
extern void(*hmx_grid_set_horz_offsets_module)(hmx_grid*, int*);
extern grid_bmp infoGridBmp[];
extern void(*hmx_ddagrid_set_scan_module)(hmx_ddagrid*, int, int, int, int, int);
extern score_data crntScorData;
extern unsigned int(*ReadScore)(int, char*, unsigned int);
extern unsigned int selectIndx;
extern int(*ReadIndx)(unsigned int);
extern unsigned short swData1;
static unsigned short nMenuKind;
static int nFadoSeqNum;
static int nFadoValu;
static int nFadoTime;
extern void(*WaveRequest)(short);
extern palette_entry tblPal2[];
extern palette_entry tblPal2a[];
static unsigned int bFadePaletDisable[4];
static palette_entry workPalet[4][16];
extern void(*sMemCpy)(void*, void*, int);
extern palette_entry tblPal4[];
extern palette_entry tblPal3[];
extern palette_entry tblPal1[];
extern unsigned int bFirstTitle;
extern palette_entry tblPal1a[];
extern void(*CDPlay)(short);
extern void(*CDPause)(short);
static unsigned int testSpr;
static unsigned int* testBmp;
unsigned int hFx1;
unsigned int hFx0;
static char KeyState[256];




































































void OEDraw() { /* Line 180, Address: 0x1000000 */
  if (nSequenceNum > 1 && bDrawDisable == 0) { /* Line 181, Address: 0x1000008 */

    srfDraw(); /* Line 183, Address: 0x1000030 */
  }
} /* Line 185, Address: 0x1000038 */




static void OEUpdateHand() { /* Line 190, Address: 0x1000050 */
  static int num;

  if (nTimerCunt == 0) { /* Line 193, Address: 0x1000058 */

    num = 0; /* Line 195, Address: 0x1000068 */
  }
  if (nTimerCunt == timeHand[num].time && num < 16U) { /* Line 197, Address: 0x1000070 */

    if (num != 0) /* Line 199, Address: 0x10000b0 */
      OESprCreate(timeHand[num].timingPatNo); /* Line 200, Address: 0x10000c0 */
    ++num; /* Line 201, Address: 0x10000e4 */
  } /* Line 202, Address: 0x10000f8 */
  else if (num != 0) /* Line 203, Address: 0x1000100 */
    OESprCreate(timeHand[num - 1].timingPatNo); /* Line 204, Address: 0x1000110 */
  else {
    OESprCreate(timeHand[num].timingPatNo); /* Line 206, Address: 0x1000140 */
  }
} /* Line 208, Address: 0x1000164 */




static void OEUpdateMayu() { /* Line 213, Address: 0x1000180 */
  static int num;

  if (nTimerCunt == 0) { /* Line 216, Address: 0x1000188 */

    num = 0; /* Line 218, Address: 0x1000198 */
  }
  if (nTimerCunt == timeMayu[num] && num < 2U) { /* Line 220, Address: 0x10001a0 */

    if (num % 2 == 0) /* Line 222, Address: 0x10001e0 */
      OESprCreate(12); /* Line 223, Address: 0x100020c */
    ++num; /* Line 224, Address: 0x1000218 */
  } /* Line 225, Address: 0x100022c */
  else if (num % 2 == 0 && num < 2U) { /* Line 226, Address: 0x1000234 */
    OESprCreate(12); /* Line 227, Address: 0x1000274 */
  }
} /* Line 229, Address: 0x1000280 */




static void OEUpdatePlanet() { /* Line 234, Address: 0x1000290 */
  static int num;
  static int staTime;

  if (*infoSprtBmp[14].lphSpr != 0) { /* Line 238, Address: 0x1000298 */

    if (nTimerCunt == 0) { /* Line 240, Address: 0x10002ac */

      num = 0; /* Line 242, Address: 0x10002bc */
      staTime = 0; /* Line 243, Address: 0x10002c4 */
    }

    hmx_sprite_set_position_module(s_ctx->sprites[14], ptPlnt[num].point.x, ptPlnt[num].point.y); /* Line 246, Address: 0x10002cc */
    if (ptPlnt[num].time == nTimerCunt - staTime) { /* Line 247, Address: 0x1000334 */

      if ((unsigned int)++num > 7) /* Line 249, Address: 0x1000374 */
      {
        num = 0; /* Line 251, Address: 0x1000394 */
      }
    } /* Line 253, Address: 0x100039c */
    else if (ptPlnt[num].time == -1) { /* Line 254, Address: 0x10003a4 */

      num = 0; /* Line 256, Address: 0x10003d4 */
      staTime = nTimerCunt; /* Line 257, Address: 0x10003dc */

      hmx_sprite_set_position_module(s_ctx->sprites[14], ptPlnt[num].point.x, ptPlnt[num].point.y); /* Line 259, Address: 0x10003ec */
    }
  }
} /* Line 262, Address: 0x1000454 */



static void OEUpdateMizu() { /* Line 266, Address: 0x1000470 */
  int inc;
  int i;
  static int nHorizShearArray[64], fHorizShearArray[64];

  if (nTimerCunt == 0) { /* Line 271, Address: 0x1000480 */

    for (i = 0; i < 64; ++i) { /* Line 273, Address: 0x1000490 */

      fHorizShearArray[i] = 0; /* Line 275, Address: 0x100049c */
      nHorizShearArray[i] = 0; /* Line 276, Address: 0x10004b0 */
    } /* Line 277, Address: 0x10004c4 */

    hmx_grid_set_horz_offsets_module(s_ctx->grids[1], nHorizShearArray); /* Line 279, Address: 0x10004d4 */
  }

  if (*infoGridBmp[1].lphGrid != 0) { /* Line 282, Address: 0x10004f8 */

    if (nTimerCunt % 2 == 0) { /* Line 284, Address: 0x100050c */

      for (i = 0; i < 64; ++i) { /* Line 286, Address: 0x1000538 */

        inc = i * 10 + 40; /* Line 288, Address: 0x1000544 */
        fHorizShearArray[i] += inc; /* Line 289, Address: 0x1000554 */
        if (fHorizShearArray[i] > 32000) /* Line 290, Address: 0x1000570 */
          fHorizShearArray[i] -= 32000; /* Line 291, Address: 0x1000590 */
        nHorizShearArray[i] = -(fHorizShearArray[i] / 100); /* Line 292, Address: 0x10005ac */
      } /* Line 293, Address: 0x10005f0 */
      hmx_grid_set_horz_offsets_module(s_ctx->grids[1], nHorizShearArray); /* Line 294, Address: 0x1000600 */
    }
  }
} /* Line 297, Address: 0x1000624 */








static void OEUpdateKumo() { /* Line 306, Address: 0x1000640 */
  int i;
  static unsigned short incY;
  static smorph_data RotateMorphValues[128];
  static unsigned char offsetY[92] = {
      0,   1,   2,   3,   4,   5,   6,   7,   8,   9,  10,  11,  12,  13,  14,  15,  16,  17,  18,  19,
     20,  21,  22,  23,  24,  25,  26,  27,  28,  29,  30,  31,  32,  33,  34,  35,  36,  37,  38,  39,
     40,  41,  42,  43,  44,  45,  46,  47,  48,  49,  50,  52,  54,  56,  58,  60,  62,  64,  66,  68,
     70,  72,  74,  76,  78,  80,  84,  88,  92,  96, 100, 104, 108, 112, 116, 120, 124, 128, 132, 136,
    142, 148, 154, 160, 170, 180, 190, 200, 210, 220, 236, 255
  };
  static smorph RotateMorph;



  if (nTimerCunt == 0) { /* Line 321, Address: 0x100064c */

    for (i = 0; i < 92; ++i) { /* Line 323, Address: 0x100065c */

      RotateMorphValues[i].StartX = (i * -64000 / 92 + 32767 + 31233) * 65; /* Line 325, Address: 0x1000668 */
      RotateMorphValues[i].StartY = i * 65536; /* Line 326, Address: 0x10006b8 */
      RotateMorphValues[i].DeltaX = (i * 400 / 92 + 400) * 65; /* Line 327, Address: 0x10006d0 */
      RotateMorphValues[i].DeltaY = 0; /* Line 328, Address: 0x100071c */
    } /* Line 329, Address: 0x1000730 */
    for (i = 92; i < 128; ++i) { /* Line 330, Address: 0x1000740 */

      RotateMorphValues[i].StartX = 65536; /* Line 332, Address: 0x100074c */
      RotateMorphValues[i].StartY = 65536; /* Line 333, Address: 0x1000764 */
      RotateMorphValues[i].DeltaX = 0; /* Line 334, Address: 0x100077c */
      RotateMorphValues[i].DeltaY = 0; /* Line 335, Address: 0x1000790 */
    } /* Line 336, Address: 0x10007a4 */
    RotateMorph.wrap = 0; /* Line 337, Address: 0x10007b4 */
    RotateMorph.pSmorphArray = RotateMorphValues; /* Line 338, Address: 0x10007bc */

    incY = 0; /* Line 340, Address: 0x10007cc */
  }
  for (i = 0; i < 92; ++i) { /* Line 342, Address: 0x10007d4 */

    RotateMorphValues[i].StartY = (offsetY[i] + incY) % 128 * 65536; /* Line 344, Address: 0x10007e0 */
    hmx_ddagrid_set_scan_module((hmx_ddagrid*)s_ctx->grids[2], i, RotateMorphValues[i].StartX, RotateMorphValues[i].DeltaX, RotateMorphValues[i].StartY, RotateMorphValues[i].DeltaY); /* Line 345, Address: 0x1000838 */
  } /* Line 346, Address: 0x10008a8 */
  if (++incY >= 128) incY = 0; /* Line 347, Address: 0x10008b8 */
} /* Line 348, Address: 0x10008e8 */




static void GetEnabeMenu(unsigned int* menuTable) { /* Line 353, Address: 0x1000900 */
  score_data dummyData;
  unsigned int bDataExist;

  if (ReadScore(selectIndx, (char*)&dummyData, 0) == 0) { /* Line 357, Address: 0x1000910 */

    bDataExist = 0; /* Line 359, Address: 0x1000938 */
  } /* Line 360, Address: 0x100093c */
  else {
    bDataExist = 1; /* Line 362, Address: 0x1000944 */
    selectIndx = ReadIndx(0); /* Line 363, Address: 0x1000948 */
    ReadScore(selectIndx, (char*)&crntScorData, 0); /* Line 364, Address: 0x1000964 */
  }







  menuTable[0] = 1; /* Line 373, Address: 0x1000988 */

  menuTable[6] = 1; /* Line 375, Address: 0x1000994 */

  if (bDataExist != 0) /* Line 377, Address: 0x10009a0 */
    if (ChkNewSlot() == 0) /* Line 378, Address: 0x10009a8 */
      menuTable[0] = 0; /* Line 379, Address: 0x10009b8 */




  if (crntScorData.saved == 1) /* Line 384, Address: 0x10009c0 */
    menuTable[1] = 1; /* Line 385, Address: 0x10009d4 */
  else
    menuTable[1] = 0; /* Line 387, Address: 0x10009e8 */




  if (bDataExist != 0) /* Line 392, Address: 0x10009f0 */
    menuTable[3] = 1; /* Line 393, Address: 0x10009f8 */
  else
    menuTable[3] = 0; /* Line 395, Address: 0x1000a0c */


  if (crntScorData.roundNo != 0) /* Line 398, Address: 0x1000a14 */
    menuTable[2] = 1; /* Line 399, Address: 0x1000a24 */
  else
    menuTable[2] = 0; /* Line 401, Address: 0x1000a38 */

  if (crntScorData.roundNo >= 7 && crntScorData.total < 134734) /* Line 403, Address: 0x1000a40 */
    menuTable[4] = 1; /* Line 404, Address: 0x1000a70 */
  else
    menuTable[4] = 0; /* Line 406, Address: 0x1000a84 */

  if (crntScorData.roundNo >= 7 && crntScorData.total < 92767) /* Line 408, Address: 0x1000a8c */
    menuTable[5] = 1; /* Line 409, Address: 0x1000abc */
  else
    menuTable[5] = 0; /* Line 411, Address: 0x1000ad0 */
} /* Line 412, Address: 0x1000ad8 */




static int GetNextMenu(unsigned int* menuTable, int kind, unsigned int bNext) { /* Line 417, Address: 0x1000af0 */
  int indx;
  int n;

  if (kind == -1) { /* Line 421, Address: 0x1000b08 */

    if (menuTable[1] != 0) /* Line 423, Address: 0x1000b18 */
      return 1; /* Line 424, Address: 0x1000b28 */
    else
      return 0; /* Line 426, Address: 0x1000b34 */
  }


  indx = kind; /* Line 430, Address: 0x1000b40 */

  if (bNext != 0) { /* Line 432, Address: 0x1000b44 */

    for (n = 0; n < 7; ++n) { /* Line 434, Address: 0x1000b50 */

      ++indx; /* Line 436, Address: 0x1000b5c */
      if (indx > 6) indx = 0; /* Line 437, Address: 0x1000b60 */
      if (menuTable[indx] != 0) return indx; /* Line 438, Address: 0x1000b70 */
    } /* Line 439, Address: 0x1000b94 */
  } /* Line 440, Address: 0x1000ba4 */
  else {

    for (n = 0; n < 7; ++n) { /* Line 443, Address: 0x1000bac */

      --indx; /* Line 445, Address: 0x1000bb8 */
      if (indx < 0) indx = 6; /* Line 446, Address: 0x1000bbc */
      if (menuTable[indx] != 0) return indx; /* Line 447, Address: 0x1000bc8 */
    } /* Line 448, Address: 0x1000bec */
  }





















} /* Line 471, Address: 0x1000bfc */


unsigned int ChkNewSlot() { /* Line 474, Address: 0x1000c10 */
  int i;
  score_data dummyData;

  for (i = 0; i < 6; ++i) { /* Line 478, Address: 0x1000c1c */
    if (ReadScore(i, (char*)&dummyData, 0) == 0) break; /* Line 479, Address: 0x1000c28 */

    if (dummyData.saved == 0) break; /* Line 481, Address: 0x1000c4c */

  } /* Line 483, Address: 0x1000c58 */
  if (i == 6) { /* Line 484, Address: 0x1000c68 */

    return 0; /* Line 486, Address: 0x1000c74 */
  }
  return 1; /* Line 488, Address: 0x1000c80 */
} /* Line 489, Address: 0x1000c84 */














static void OEUpdateMsg() { /* Line 504, Address: 0x1000ca0 */
  POINT arrowPoint;
  unsigned int kPosi;
  unsigned int lPosi;
  unsigned int rPosi;
  static POINT point;
  static int kind;
  static int nSeqNo;
  static unsigned int RArrow, LArrow;
  static int nSeqNoNext;
  static int timeOld;
  static unsigned int menuEnable[7];
  static int arrowKind;
  static unsigned int bDelete;
  static int testCheckMode;

  rPosi = lPosi = kPosi = 0; /* Line 520, Address: 0x1000cb8 */

  if (nTimerCunt == 0) { /* Line 522, Address: 0x1000cc4 */

    kind = 24; /* Line 524, Address: 0x1000cd4 */
    bDelete = 0; /* Line 525, Address: 0x1000ce0 */
    timeOld = 0; /* Line 526, Address: 0x1000ce8 */
    arrowKind = 0; /* Line 527, Address: 0x1000cf0 */
    testCheckMode = 1; /* Line 528, Address: 0x1000cf8 */
    GetEnabeMenu(menuEnable); /* Line 529, Address: 0x1000d04 */
    nSeqNo = 1; /* Line 530, Address: 0x1000d18 */
  }
  if (nTimerCunt - timeOld == 900) { /* Line 532, Address: 0x1000d24 */


    nMenuKind = 7; /* Line 535, Address: 0x1000d44 */
    nFadoTime = 21; /* Line 536, Address: 0x1000d50 */
    nFadoValu = 32; /* Line 537, Address: 0x1000d5c */
    nFadoSeqNum = 999; /* Line 538, Address: 0x1000d68 */
    OESetSequenceNum(8); /* Line 539, Address: 0x1000d74 */
  }


  if (nSeqNo == 1) { /* Line 543, Address: 0x1000d80 */

    if (testCheckMode != 0) { /* Line 545, Address: 0x1000d94 */









      if (swData1 & 24320) { /* Line 555, Address: 0x1000da4 */

        switch (testCheckMode) { /* Line 557, Address: 0x1000dbc */

          case 1:   if (swData1 & 512) ++testCheckMode; /* Line 559, Address: 0x1000e8c */
                    else if (swData1 & 256) testCheckMode = 12; /* Line 560, Address: 0x1000ec0 */
                    else if (swData1 & 2048) testCheckMode = 20; /* Line 561, Address: 0x1000eec */
                    else testCheckMode = 0; /* Line 562, Address: 0x1000f18 */
                    break; /* Line 563, Address: 0x1000f20 */
          case 2:   if (swData1 & 512) ++testCheckMode; /* Line 564, Address: 0x1000f28 */
                    else testCheckMode = 0; /* Line 565, Address: 0x1000f5c */
                    break; /* Line 566, Address: 0x1000f64 */
          case 3:   if (swData1 & 512) ++testCheckMode; /* Line 567, Address: 0x1000f6c */
                    else testCheckMode = 0; /* Line 568, Address: 0x1000fa0 */
                    break; /* Line 569, Address: 0x1000fa8 */
          case 4:   if (swData1 & 1024) ++testCheckMode; /* Line 570, Address: 0x1000fb0 */
                    else testCheckMode = 0; /* Line 571, Address: 0x1000fe4 */
                    break; /* Line 572, Address: 0x1000fec */
          case 5:   if (swData1 & 2048) ++testCheckMode; /* Line 573, Address: 0x1000ff4 */
                    else testCheckMode = 0; /* Line 574, Address: 0x1001028 */
                    break; /* Line 575, Address: 0x1001030 */
          case 6:   if (swData1 & 16384) { /* Line 576, Address: 0x1001038 */

                      nMenuKind = 8; /* Line 578, Address: 0x1001050 */
                      nFadoTime = 21; /* Line 579, Address: 0x100105c */
                      nFadoValu = 32; /* Line 580, Address: 0x1001068 */
                      nFadoSeqNum = 999; /* Line 581, Address: 0x1001074 */
                      OESetSequenceNum(8); /* Line 582, Address: 0x1001080 */
                    } /* Line 583, Address: 0x100108c */
                    else testCheckMode = 0; /* Line 584, Address: 0x1001094 */
                    break; /* Line 585, Address: 0x100109c */
          case 12:  if (swData1 & 512) ++testCheckMode; /* Line 586, Address: 0x10010a4 */
                    else testCheckMode = 0; /* Line 587, Address: 0x10010d8 */
                    break; /* Line 588, Address: 0x10010e0 */
          case 13:  if (swData1 & 512) ++testCheckMode; /* Line 589, Address: 0x10010e8 */
                    else testCheckMode = 0; /* Line 590, Address: 0x100111c */
                    break; /* Line 591, Address: 0x1001124 */
          case 14:  if (swData1 & 1024) ++testCheckMode; /* Line 592, Address: 0x100112c */
                    else testCheckMode = 0; /* Line 593, Address: 0x1001160 */
                    break; /* Line 594, Address: 0x1001168 */
          case 15:  if (swData1 & 2048) ++testCheckMode; /* Line 595, Address: 0x1001170 */
                    else testCheckMode = 0; /* Line 596, Address: 0x10011a4 */
                    break; /* Line 597, Address: 0x10011ac */
          case 16:  if (swData1 & 16384) { /* Line 598, Address: 0x10011b4 */

                      nMenuKind = 9; /* Line 600, Address: 0x10011cc */
                      nFadoTime = 21; /* Line 601, Address: 0x10011d8 */
                      nFadoValu = 32; /* Line 602, Address: 0x10011e4 */
                      nFadoSeqNum = 999; /* Line 603, Address: 0x10011f0 */
                      OESetSequenceNum(8); /* Line 604, Address: 0x10011fc */
                    } /* Line 605, Address: 0x100120c */
                    else testCheckMode = 0; /* Line 606, Address: 0x1001214 */
                    break; /* Line 607, Address: 0x100121c */


          case 20:  if (swData1 & 2048) ++testCheckMode; /* Line 610, Address: 0x1001224 */
                    else testCheckMode = 0; /* Line 611, Address: 0x1001258 */
                    break; /* Line 612, Address: 0x1001260 */
          case 21:  if (swData1 & 256) ++testCheckMode; /* Line 613, Address: 0x1001268 */
                    else testCheckMode = 0; /* Line 614, Address: 0x100129c */
                    break; /* Line 615, Address: 0x10012a4 */
          case 22:  if (swData1 & 256) ++testCheckMode; /* Line 616, Address: 0x10012ac */
                    else testCheckMode = 0; /* Line 617, Address: 0x10012e0 */
                    break; /* Line 618, Address: 0x10012e8 */
          case 23:  if (swData1 & 512) ++testCheckMode; /* Line 619, Address: 0x10012f0 */
                    else testCheckMode = 0; /* Line 620, Address: 0x1001324 */
                    break; /* Line 621, Address: 0x100132c */
          case 24:  if (swData1 & 16384) { /* Line 622, Address: 0x1001334 */

                      nMenuKind = 10; /* Line 624, Address: 0x100134c */
                      nFadoTime = 21; /* Line 625, Address: 0x1001358 */
                      nFadoValu = 32; /* Line 626, Address: 0x1001364 */
                      nFadoSeqNum = 999; /* Line 627, Address: 0x1001370 */
                      OESetSequenceNum(8); /* Line 628, Address: 0x100137c */
                    } /* Line 629, Address: 0x100138c */
                    else testCheckMode = 0; /* Line 630, Address: 0x1001394 */
                    break;
        }


        timeOld = nTimerCunt; /* Line 635, Address: 0x100139c */
        nSeqNoNext = 1; /* Line 636, Address: 0x10013ac */
        nSeqNo = 7; /* Line 637, Address: 0x10013b8 */
      }
    }
    if (nTimerCunt % 20 == 0) { /* Line 640, Address: 0x10013c4 */

      bDelete = bDelete ? 0 : 1; /* Line 642, Address: 0x10013e0 */
    }


    if (bDelete == 0) OESprCreateIndx(kind); /* Line 646, Address: 0x1001408 */


    if (swData1 & 53248) { /* Line 649, Address: 0x100142c */

      point = infoSprtBmp[kind].point; /* Line 651, Address: 0x1001444 */
      if (bDelete == 0) /* Line 652, Address: 0x1001478 */
        OESprCreateIndx(kind); /* Line 653, Address: 0x1001488 */
      OEClrset(tblPal2a, 1); /* Line 654, Address: 0x100149c */
      nSeqNo = 2; /* Line 655, Address: 0x10014b4 */
    }
  } /* Line 657, Address: 0x10014c0 */
  else if (nSeqNo == 2) { /* Line 658, Address: 0x10014c8 */

    RArrow = LArrow = 0; /* Line 660, Address: 0x10014dc */
    OEClrset(tblPal2a, 1); /* Line 661, Address: 0x10014ec */
    point.x += 32; /* Line 662, Address: 0x1001504 */
    if (point.x >= 320) { /* Line 663, Address: 0x1001518 */

      if (kind == 24) { /* Line 665, Address: 0x100152c */

        kind = GetNextMenu(menuEnable, -1, 0) + 25; /* Line 667, Address: 0x1001540 */
      } /* Line 668, Address: 0x1001564 */
      else
        kind = GetNextMenu(menuEnable, kind - 25, 0) + 25; /* Line 670, Address: 0x100156c */
      point = infoSprtBmp[kind].point; /* Line 671, Address: 0x1001598 */
      point.x = -infoSprtBmp[kind].w; /* Line 672, Address: 0x10015cc */
      OEClrset(tblPal2a, 1); /* Line 673, Address: 0x10015f8 */
      nSeqNo = 3; /* Line 674, Address: 0x100160c */
    }
    kPosi = 1; /* Line 676, Address: 0x1001618 */
  } /* Line 677, Address: 0x100161c */
  else if (nSeqNo == 3) { /* Line 678, Address: 0x1001624 */

    OEClrset(tblPal2a, 1); /* Line 680, Address: 0x1001638 */
    point.x += 32; /* Line 681, Address: 0x100164c */
    if (point.x >= infoSprtBmp[kind].point.x) { /* Line 682, Address: 0x1001660 */

      if (GetNextMenu(menuEnable, kind - 25, 0) + 25 < kind) LArrow = 1; /* Line 684, Address: 0x1001690 */
      if (GetNextMenu(menuEnable, kind - 25, 1) + 25 < kind) RArrow = 1; /* Line 685, Address: 0x10016d4 */
      point = infoSprtBmp[kind].point; /* Line 686, Address: 0x1001718 */
      OEClrset(tblPal2, 1); /* Line 687, Address: 0x100174c */
      nSeqNo = 6; /* Line 688, Address: 0x1001768 */
      timeOld = nTimerCunt; /* Line 689, Address: 0x1001774 */
    }
    kPosi = 1; /* Line 691, Address: 0x1001784 */
  } /* Line 692, Address: 0x100178c */
  else if (nSeqNo == 4) { /* Line 693, Address: 0x1001794 */

    RArrow = LArrow = 0; /* Line 695, Address: 0x10017a8 */
    OEClrset(tblPal2a, 1); /* Line 696, Address: 0x10017b8 */
    point.x -= 32; /* Line 697, Address: 0x10017d0 */
    if (point.x < -infoSprtBmp[kind].w) { /* Line 698, Address: 0x10017e4 */

      kind = GetNextMenu(menuEnable, kind - 25, 1) + 25; /* Line 700, Address: 0x100181c */
      point = infoSprtBmp[kind].point; /* Line 701, Address: 0x1001850 */
      point.x = 320; /* Line 702, Address: 0x1001884 */
      OEClrset(tblPal2a, 1); /* Line 703, Address: 0x1001890 */
      nSeqNo = 5; /* Line 704, Address: 0x10018a8 */
    }
    kPosi = 1; /* Line 706, Address: 0x10018b4 */
  } /* Line 707, Address: 0x10018bc */
  else if (nSeqNo == 5) { /* Line 708, Address: 0x10018c4 */

    OEClrset(tblPal2a, 1); /* Line 710, Address: 0x10018d8 */
    point.x -= 32; /* Line 711, Address: 0x10018f0 */
    if (point.x < infoSprtBmp[kind].point.x) { /* Line 712, Address: 0x1001904 */

      if (GetNextMenu(menuEnable, kind - 25, 0) + 25 < kind) LArrow = 1; /* Line 714, Address: 0x1001934 */
      if (GetNextMenu(menuEnable, kind - 25, 1) + 25 < kind) RArrow = 1; /* Line 715, Address: 0x100197c */
      point = infoSprtBmp[kind].point; /* Line 716, Address: 0x10019c0 */
      OEClrset(tblPal2, 1); /* Line 717, Address: 0x10019f4 */
      nSeqNo = 6; /* Line 718, Address: 0x1001a0c */
      timeOld = nTimerCunt; /* Line 719, Address: 0x1001a18 */
    }
    kPosi = 1; /* Line 721, Address: 0x1001a28 */
  } /* Line 722, Address: 0x1001a30 */
  else if (nSeqNo == 6) { /* Line 723, Address: 0x1001a38 */

    if ((nTimerCunt - timeOld) % 16 == 0) { /* Line 725, Address: 0x1001a4c */

      if (*infoSprtBmp[32].lphSpr != 0) { /* Line 727, Address: 0x1001a84 */

        arrowPoint.x = posiLeftArrow[arrowKind]; /* Line 729, Address: 0x1001a98 */
        arrowPoint.y = infoSprtBmp[32].point.y; /* Line 730, Address: 0x1001ab8 */
        lPosi = 1; /* Line 731, Address: 0x1001ac4 */
      }
      if (*infoSprtBmp[33].lphSpr != 0) { /* Line 733, Address: 0x1001acc */

        arrowPoint.x = posiRightArrow[arrowKind]; /* Line 735, Address: 0x1001ae0 */
        arrowPoint.y = infoSprtBmp[33].point.y; /* Line 736, Address: 0x1001b00 */
        rPosi = 1; /* Line 737, Address: 0x1001b0c */
      }
      if (++arrowKind > 2) arrowKind = 0; /* Line 739, Address: 0x1001b14 */
    }

    if (swData1 & 20480) { /* Line 742, Address: 0x1001b3c */

      if (kind - 25 == 0) { /* Line 744, Address: 0x1001b54 */
        if (ChkNewSlot() == 0) { /* Line 745, Address: 0x1001b68 */
          WaveRequest(28); /* Line 746, Address: 0x1001b7c */
          return; /* Line 747, Address: 0x1001b94 */
        }
      }

      nFadoTime = 21; /* Line 751, Address: 0x1001b9c */
      nFadoValu = 32; /* Line 752, Address: 0x1001ba8 */
      nFadoSeqNum = 999; /* Line 753, Address: 0x1001bb4 */
      OESetSequenceNum(8); /* Line 754, Address: 0x1001bc0 */
      nMenuKind = kind - 25; /* Line 755, Address: 0x1001bcc */
    } /* Line 756, Address: 0x1001be4 */
    else if (swData1 & 1024 && GetNextMenu(menuEnable, kind - 25, 0) + 25 < kind) { /* Line 757, Address: 0x1001bec */


      timeOld = nTimerCunt; /* Line 760, Address: 0x1001c40 */
      nSeqNo = 7; /* Line 761, Address: 0x1001c50 */
      nSeqNoNext = 2; /* Line 762, Address: 0x1001c5c */
    } /* Line 763, Address: 0x1001c68 */
    else if (swData1 & 2048 && GetNextMenu(menuEnable, kind - 25, 1) + 25 > kind) { /* Line 764, Address: 0x1001c70 */


      timeOld = nTimerCunt; /* Line 767, Address: 0x1001cc0 */
      nSeqNo = 7; /* Line 768, Address: 0x1001cd0 */
      nSeqNoNext = 4; /* Line 769, Address: 0x1001cdc */
    }
  } /* Line 771, Address: 0x1001ce8 */
  else if (nSeqNo == 7) { /* Line 772, Address: 0x1001cf0 */

    if (nTimerCunt - timeOld > 6) { /* Line 774, Address: 0x1001d04 */

      nSeqNo = nSeqNoNext; /* Line 776, Address: 0x1001d24 */
    }
  }
  if (LArrow != 0) OESprCreateIndx(32); /* Line 779, Address: 0x1001d34 */
  if (RArrow != 0) OESprCreateIndx(33); /* Line 780, Address: 0x1001d54 */
  if (nSeqNo != 1) OESprCreateIndx(kind); /* Line 781, Address: 0x1001d70 */



  if (kPosi != 0) hmx_sprite_set_position_module(s_ctx->sprites[*infoSprtBmp[kind].lphSpr], point.x, point.y); /* Line 785, Address: 0x1001d98 */
  if (lPosi != 0) hmx_sprite_set_position_module(s_ctx->sprites[*infoSprtBmp[32].lphSpr], arrowPoint.x, arrowPoint.y); /* Line 786, Address: 0x1001df8 */
  if (rPosi != 0) hmx_sprite_set_position_module(s_ctx->sprites[*infoSprtBmp[33].lphSpr], arrowPoint.x, arrowPoint.y); /* Line 787, Address: 0x1001e48 */
} /* Line 788, Address: 0x1001e90 */




void OETitleSta() { /* Line 793, Address: 0x1001eb0 */
  OEAllSprDelete(); /* Line 794, Address: 0x1001eb8 */
  if (nTimerCunt == 0) { /* Line 795, Address: 0x1001ec0 */

    OEGridCreate(1); /* Line 797, Address: 0x1001ed0 */
    bDrawDisable = 1; /* Line 798, Address: 0x1001edc */
    nFadoTime = 21; /* Line 799, Address: 0x1001ee8 */
    nFadoValu = 32; /* Line 800, Address: 0x1001ef4 */
    nFadoSeqNum = 7; /* Line 801, Address: 0x1001f00 */
    bFadePaletDisable[3] = 1; /* Line 802, Address: 0x1001f0c */
    OESetSequenceNum(9); /* Line 803, Address: 0x1001f18 */
  }
  OESprCreate(7); /* Line 805, Address: 0x1001f24 */
  OESprCreate(11); /* Line 806, Address: 0x1001f30 */
} /* Line 807, Address: 0x1001f3c */




void OETitle() { /* Line 812, Address: 0x1001f50 */
  OEAllSprDelete(); /* Line 813, Address: 0x1001f58 */
  OESprCreate(7); /* Line 814, Address: 0x1001f60 */
  if (nTimerCunt == 0) { /* Line 815, Address: 0x1001f6c */

    OEGridCreate(2); /* Line 817, Address: 0x1001f7c */
  }
  OEUpdateHand(); /* Line 819, Address: 0x1001f88 */
  OEUpdateMayu(); /* Line 820, Address: 0x1001f90 */
  OEUpdatePlanet(); /* Line 821, Address: 0x1001f98 */
  OEUpdateMizu(); /* Line 822, Address: 0x1001fa0 */
  OEUpdateKumo(); /* Line 823, Address: 0x1001fa8 */
  OEUpdateMsg(); /* Line 824, Address: 0x1001fb0 */
} /* Line 825, Address: 0x1001fb8 */





void OEFadeOut() { /* Line 831, Address: 0x1001fd0 */
  int i, j;
  static int colorNum;

  if (nTimerCunt == 0) { /* Line 835, Address: 0x1001fe0 */

    sMemCpy(workPalet[0], tblPal1, sizeof(workPalet[0])); /* Line 837, Address: 0x1001ff0 */
    sMemCpy(workPalet[1], tblPal2, sizeof(workPalet[1])); /* Line 838, Address: 0x1002014 */
    sMemCpy(workPalet[2], tblPal3, sizeof(workPalet[2])); /* Line 839, Address: 0x1002038 */
    sMemCpy(workPalet[3], tblPal4, sizeof(workPalet[3])); /* Line 840, Address: 0x100205c */
    colorNum = 0; /* Line 841, Address: 0x1002080 */
  } /* Line 842, Address: 0x1002088 */
  else if (nTimerCunt == nFadoTime) { /* Line 843, Address: 0x1002090 */

    bFadePaletDisable[0] = bFadePaletDisable[1] = bFadePaletDisable[2] = bFadePaletDisable[3] = 0; /* Line 845, Address: 0x10020a8 */
    OESetSequenceNum(nFadoSeqNum); /* Line 846, Address: 0x10020c8 */
  } /* Line 847, Address: 0x10020dc */
  else {

    for (i = 0; i < 4; ++i) { /* Line 850, Address: 0x10020e4 */

      for (j = 0; j < 16; ++j) { /* Line 852, Address: 0x10020f0 */

        if (workPalet[i][j].peRed > nFadoValu) workPalet[i][j].peRed -= nFadoValu; /* Line 854, Address: 0x10020fc */
        else workPalet[i][j].peRed = 0; /* Line 855, Address: 0x1002168 */
        if (workPalet[i][j].peRed == 0) { /* Line 856, Address: 0x1002184 */

          if (workPalet[i][j].peGreen > nFadoValu) workPalet[i][j].peGreen -= nFadoValu; /* Line 858, Address: 0x10021ac */
          else workPalet[i][j].peGreen = 0; /* Line 859, Address: 0x1002218 */
          if (workPalet[i][j].peGreen == 0) { /* Line 860, Address: 0x1002234 */

            if (workPalet[i][j].peBlue > nFadoValu) workPalet[i][j].peBlue -= nFadoValu; /* Line 862, Address: 0x100225c */
            else workPalet[i][j].peBlue = 0; /* Line 863, Address: 0x10022c8 */
          }
        }
      } /* Line 866, Address: 0x10022e4 */
      if (bFadePaletDisable[i] == 0) OEClrset(workPalet[i], i); /* Line 867, Address: 0x10022f4 */
    } /* Line 868, Address: 0x100232c */
  }

















} /* Line 887, Address: 0x100233c */





void OEFadeIn() { /* Line 893, Address: 0x1002360 */
  int n, j;
  palette_entry* lpPal;

  OEAllSprDelete(); /* Line 897, Address: 0x1002380 */
  if (nFadoSeqNum == 7) { /* Line 898, Address: 0x1002388 */
    OESprCreate(7); /* Line 899, Address: 0x100239c */
    OESprCreate(11); /* Line 900, Address: 0x10023a8 */
  }

  if (nTimerCunt == nFadoTime) { /* Line 903, Address: 0x10023b4 */

    OEClrset(tblPal1, 0); /* Line 905, Address: 0x10023cc */
    OEClrset(tblPal2, 1); /* Line 906, Address: 0x10023e0 */
    OEClrset(tblPal3, 2); /* Line 907, Address: 0x10023f4 */
    OEClrset(tblPal4, 3); /* Line 908, Address: 0x1002408 */
    bFadePaletDisable[0] = bFadePaletDisable[1] = bFadePaletDisable[2] = bFadePaletDisable[3] = 0; /* Line 909, Address: 0x100241c */
    OESetSequenceNum(nFadoSeqNum); /* Line 910, Address: 0x100243c */
  } /* Line 911, Address: 0x1002450 */
  else {

    bDrawDisable = 0; /* Line 914, Address: 0x1002458 */
    if (nFadoValu * nTimerCunt < 256) { /* Line 915, Address: 0x1002460 */

      for (n = 0; n < 4; ++n) { /* Line 917, Address: 0x1002480 */

        switch (n) { /* Line 919, Address: 0x100248c */

          case 0: lpPal = tblPal1; break; /* Line 921, Address: 0x10024c0 */
          case 1: lpPal = tblPal2; break; /* Line 922, Address: 0x10024d0 */
          case 2: lpPal = tblPal3; break; /* Line 923, Address: 0x10024e0 */
          case 3: lpPal = tblPal4; break; /* Line 924, Address: 0x10024f0 */
        }
        for (j = 0; j < 16; ++j) { /* Line 926, Address: 0x10024f8 */

          workPalet[n][j].peRed = lpPal[j].peRed > 224 - nFadoValu * nTimerCunt ? lpPal[j].peRed : 224 - nFadoValu * nTimerCunt; /* Line 928, Address: 0x1002504 */
          workPalet[n][j].peGreen = lpPal[j].peGreen > 224 - nFadoValu * nTimerCunt ? lpPal[j].peGreen : 224 - nFadoValu * nTimerCunt; /* Line 929, Address: 0x1002590 */
          workPalet[n][j].peBlue = lpPal[j].peBlue > 224 - nFadoValu * nTimerCunt ? lpPal[j].peBlue : 224 - nFadoValu * nTimerCunt; /* Line 930, Address: 0x100261c */
          workPalet[n][j].peFlags = lpPal[j].peFlags; /* Line 931, Address: 0x10026a8 */
        } /* Line 932, Address: 0x10026d0 */
        if (bFadePaletDisable[n] == 0) OEClrset(workPalet[n], n); /* Line 933, Address: 0x10026e0 */
      } /* Line 934, Address: 0x1002718 */
    }
  }
} /* Line 937, Address: 0x1002728 */




void OEOpenSta() { /* Line 942, Address: 0x1002750 */
  if (nTimerCunt == 0) { /* Line 943, Address: 0x1002758 */

    OEGridCreate(0); /* Line 945, Address: 0x1002768 */
    if (bFirstTitle != 0) OESetSequenceNum(2); /* Line 946, Address: 0x1002774 */
    else OESetSequenceNum(5); /* Line 947, Address: 0x1002798 */
  }
} /* Line 949, Address: 0x10027a4 */







void OESegaLogo() { /* Line 957, Address: 0x10027c0 */
  OEAllSprDelete(); /* Line 958, Address: 0x10027c8 */
  if (nTimerCunt == 0) { /* Line 959, Address: 0x10027d0 */

    OEClrset(tblPal1a, 0); /* Line 961, Address: 0x10027e0 */
  } /* Line 962, Address: 0x10027f4 */
  else if (nTimerCunt == 90) { /* Line 963, Address: 0x10027fc */

    OESprDelete(1); /* Line 965, Address: 0x1002810 */
    OESetSequenceNum(3); /* Line 966, Address: 0x100281c */
    OEClrset(tblPal1, 0); /* Line 967, Address: 0x1002828 */
  } /* Line 968, Address: 0x100283c */
  else OESprCreate(1); /* Line 969, Address: 0x1002844 */

} /* Line 971, Address: 0x1002850 */




void OEDark() { /* Line 976, Address: 0x1002860 */
  if (nTimerCunt == 30) { /* Line 977, Address: 0x1002868 */

    OESetSequenceNum(5); /* Line 979, Address: 0x100287c */
  }
} /* Line 981, Address: 0x1002888 */





void OESonic() { /* Line 987, Address: 0x10028a0 */
  OEAllSprDelete(); /* Line 988, Address: 0x10028a8 */
  if (nTimerCunt == 0) { /* Line 989, Address: 0x10028b0 */
    CDPlay(26); /* Line 990, Address: 0x10028c0 */
  } /* Line 991, Address: 0x10028d4 */
  else if (nTimerCunt < 30) { /* Line 992, Address: 0x10028dc */

    OESprCreate(2); /* Line 994, Address: 0x10028f0 */
  } /* Line 995, Address: 0x10028fc */
  else if (nTimerCunt < 32) { /* Line 996, Address: 0x1002904 */

    OESprCreate(3); /* Line 998, Address: 0x1002918 */
  } /* Line 999, Address: 0x1002924 */
  else if (nTimerCunt < 35) { /* Line 1000, Address: 0x100292c */

    OESprCreate(4); /* Line 1002, Address: 0x1002940 */
  } /* Line 1003, Address: 0x100294c */
  else if (nTimerCunt < 38) { /* Line 1004, Address: 0x1002954 */

    OESprCreate(5); /* Line 1006, Address: 0x1002968 */
  } /* Line 1007, Address: 0x1002974 */
  else {

    OESetSequenceNum(6); /* Line 1010, Address: 0x100297c */
  }
} /* Line 1012, Address: 0x1002988 */




int OEEnd() { /* Line 1017, Address: 0x10029a0 */
  int ret = 0; /* Line 1018, Address: 0x10029ac */

  if (nTimerCunt == 0) { /* Line 1020, Address: 0x10029b0 */

    CDPause(2); /* Line 1022, Address: 0x10029c0 */
    switch (nMenuKind) { /* Line 1023, Address: 0x10029d4 */

      case 0:
        ret = 1; /* Line 1026, Address: 0x1002a08 */
        break; /* Line 1027, Address: 0x1002a0c */
      case 1:
        ret = 2; /* Line 1029, Address: 0x1002a14 */
        break; /* Line 1030, Address: 0x1002a18 */
      case 2:
        ret = 3; /* Line 1032, Address: 0x1002a20 */
        break; /* Line 1033, Address: 0x1002a24 */
      case 3:
        ret = 4; /* Line 1035, Address: 0x1002a2c */
        break; /* Line 1036, Address: 0x1002a30 */
      case 4:
        ret = 5; /* Line 1038, Address: 0x1002a38 */
        break; /* Line 1039, Address: 0x1002a3c */
      case 5:
        ret = 6; /* Line 1041, Address: 0x1002a44 */
        break; /* Line 1042, Address: 0x1002a48 */
      case 7:
        ret = 7; /* Line 1044, Address: 0x1002a50 */
        break; /* Line 1045, Address: 0x1002a54 */
      case 8:
        ret = 13; /* Line 1047, Address: 0x1002a5c */
        break; /* Line 1048, Address: 0x1002a60 */
      case 9:
        ret = 14; /* Line 1050, Address: 0x1002a68 */
        break; /* Line 1051, Address: 0x1002a6c */
      case 10:
        ret = 20; /* Line 1053, Address: 0x1002a74 */
        break; /* Line 1054, Address: 0x1002a78 */

      case 6:
        ret = 21; /* Line 1057, Address: 0x1002a80 */
        break;
    }
  }

  return ret; /* Line 1062, Address: 0x1002a84 */
} /* Line 1063, Address: 0x1002a88 */
