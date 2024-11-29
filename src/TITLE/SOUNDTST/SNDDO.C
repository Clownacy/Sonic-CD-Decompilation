#include "..\..\TYPES.H"
#include "..\COMMON\HMX_TYPES.H"
#include "SNDDO.H"
#include "..\COMMON\GRID.H"
#include "..\COMMON\HMX_OEEACTL.H"
#include "..\COMMON\PALT.H"
#include "SNDENTRY.H"
#include "SNDSPRT.H"

static void UpdateMenu();

static unsigned char tblPCM[80] = {
   0,  1,  2,  3,  4,  5,  6,  7,  8,  9,
  10, 11, 11, 12, 13, 14, 15, 16, 17, 18,
  19, 20, 20, 21, 22, 22, 23, 23, 24, 25,
  26, 27, 28, 29, 30, 31, 43, 44, 45, 46,
  47, 48, 49, 50, 51, 52, 53, 54, 55, 56,
  57, 58, 58, 59, 60, 61, 62, 63, 64, 65,
  67, 68, 69, 70, 71, 71, 72, 73, 74, 32,
  33, 34, 35, 36, 37, 38, 39, 40, 41, 42
};
static unsigned char tblDA[34] = {
   0,  1,  2,  3,  4,  5,  6,  7,  8,  9,
  10, 11, 12, 13, 14, 15, 16, 17, 18, 19,
  20, 21, 22, 23, 24, 25, 26, 27, 28, 29,
  30, 31, 32, 33
};
int bKakusi;
extern unsigned short nSequenceNum;
static unsigned short nMenuKind;
static unsigned short nPCMNumberIndx;
static unsigned short nDANumberIndx;
extern void(*CDPause)(short);
extern unsigned short swData1;
extern void(*CDPlay)(short);
extern void(*WaveRequest)(short);
extern int nTimerCunt;
static unsigned int HorizInit;
PALETTEENTRY MIYAKEcolor[16] = {
  { 240, 240, 240, 1 }, {   0,   0,   0, 1 }, {   0,   0,  64, 1 }, {   0,   0, 128, 1 },
  {   0,   0, 192, 1 }, {  32,   0, 224, 1 }, {  32,  32, 224, 1 }, {  64, 192, 224, 1 },
  {   0,  64, 224, 1 }, {   0,  32, 224, 1 }, {   0,  32, 192, 1 }, {   0,  32, 160, 1 },
  {   0,  32, 128, 1 }, {   0,  32,  96, 1 }, {   0,  32,  64, 1 }, {   0,  32,  32, 1 }
};
PALETTEENTRY NISIMURAcolor[16] = {
  {   0,   0,   0, 1 }, { 224, 224, 224, 1 }, {  96,  96,  96, 1 }, { 160, 160, 160, 1 },
  {  32,  32,  32, 1 }, { 240, 240, 240, 1 }, { 240, 240, 240, 1 }, { 240, 240, 240, 1 },
  { 240, 240, 240, 1 }, {  96,  64, 160, 1 }, { 240, 240, 240, 1 }, {   0,   0, 128, 1 },
  {   0,   0,  32, 1 }, {  64,  32, 128, 1 }, { 240, 240, 240, 1 }, { 240, 240, 240, 1 }
};
PALETTEENTRY SANPEIcolor[16] = {
  {   0,   0,   0, 1 }, {  32,  32, 128, 1 }, {  64,  64, 192, 1 }, {  64,  64, 224, 1 },
  { 240, 240, 240, 1 }, { 224, 224, 192, 1 }, { 224, 224, 224, 1 }, { 160, 160, 160, 1 },
  { 128, 128, 128, 1 }, {  64,  64,  64, 1 }, { 224, 160, 128, 1 }, { 160,  96,  64, 1 },
  { 224,   0,   0, 1 }, { 128,   0,   0, 1 }, {  64,   0,   0, 1 }, { 224, 192, 160, 1 }
};
PALETTEENTRY YAMAGU1color[16] = {
  {   0,   0,   0, 1 }, {   0,   0,   0, 1 }, { 224, 224, 224, 1 }, {   0,  32,   0, 1 },
  {  32,  64,   0, 1 }, {  96, 128,  32, 1 }, {  32,  32,  32, 1 }, {  64,  64,  64, 1 },
  {  96,  96, 128, 1 }, { 128, 128, 160, 1 }, { 160, 160, 160, 1 }, { 192, 192, 192, 1 },
  { 224, 224, 128, 1 }, {  64, 128, 224, 1 }, { 128, 128,  96, 1 }, {   0,  32, 208, 1 }
};
PALETTEENTRY YAMAGU2color[16] = {
  {   0,   0,   0, 1 }, {   0,   0,   0, 1 }, {  64,  64, 128, 1 }, {  96,  96, 160, 1 },
  { 128, 160, 224, 1 }, { 160, 192, 224, 1 }, { 224, 224, 224, 1 }, { 224, 160,   0, 1 },
  { 224, 128,   0, 1 }, { 192,  96,   0, 1 }, { 224, 192, 128, 1 }, { 192, 224, 224, 1 },
  { 160,  64,   0, 1 }, {  96,   0,   0, 1 }, { 192,  32,   0, 1 }, {   0,  32, 192, 1 }
};
PALETTEENTRY HOSHINOcolor[16] = {
  {   0,   0,   0, 1 }, {   0,  96,   0, 1 }, {  32,  32, 192, 1 }, {  64,  64, 224, 1 },
  {  96,  96, 224, 1 }, { 128, 128, 224, 1 }, { 224, 224, 224, 1 }, { 160, 160, 160, 1 },
  { 128, 128, 128, 1 }, {  64,  64,  64, 1 }, { 224, 160, 128, 1 }, { 160,  96,  64, 1 },
  { 224,   0,   0, 1 }, { 128,   0,   0, 1 }, {  64,   0,   0, 1 }, { 224, 224,   0, 1 }
};
static grid_rect CG_Rect = { 0, 0, 320, 224 };
extern draw_context* s_ctx;
extern void(*hmx_sprite_set_bitmap_module)(hmx_sprite*, hmx_bitmap*);
extern void(*hmx_sprite_set_position_module)(hmx_sprite*, int, int);
extern void*(*hmx_bitmap_get_scan0_module)(hmx_bitmap*);
extern hmx_bitmap*(*hmx_bitmap_create_module)(hmx_environment*, int, int);
extern hmx_environment* g_env_module;
extern void(*hmx_bitmap_release_module)(hmx_environment*, hmx_bitmap*);
static unsigned int* hBmpBkg;
static unsigned int hBkg;
static unsigned int hmapwk;
static int ErrRet;
static char ErrBuf[250];




void SNDDraw() { /* Line 92, Address: 0x10009b0 */
  if (nSequenceNum > 1) { /* Line 93, Address: 0x10009b8 */

    srfDraw(); /* Line 95, Address: 0x10009d0 */
  }
} /* Line 97, Address: 0x10009d8 */




static void UpdateMenu() { /* Line 102, Address: 0x10009f0 */
  if (nMenuKind == 1) StrPCM(2); /* Line 103, Address: 0x10009f8 */
  else StrPCM(1); /* Line 104, Address: 0x1000a24 */
  if (nMenuKind == 2) StrDA(2); /* Line 105, Address: 0x1000a30 */
  else StrDA(1); /* Line 106, Address: 0x1000a5c */
} /* Line 107, Address: 0x1000a68 */




void SNDStart() { /* Line 112, Address: 0x1000a80 */
  int n;

  OEGridCreate(0); /* Line 115, Address: 0x1000a8c */
  for (n = 0; n < 16; ++n) { /* Line 116, Address: 0x1000a98 */

    OESprCreateIndx(n + 83); /* Line 118, Address: 0x1000aa4 */
  } /* Line 119, Address: 0x1000ab0 */
  for (n = 0; n < 9; ++n) { /* Line 120, Address: 0x1000ac4 */

    OESprCreateIndx(n); /* Line 122, Address: 0x1000ad0 */
  } /* Line 123, Address: 0x1000adc */
  nMenuKind = 1; /* Line 124, Address: 0x1000af0 */
  UpdateMenu(); /* Line 125, Address: 0x1000afc */
  StrPCMNO(tblPCM[0]); /* Line 126, Address: 0x1000b04 */
  StrDANO(tblDA[0]); /* Line 127, Address: 0x1000b18 */
  nPCMNumberIndx = nDANumberIndx = 0; /* Line 128, Address: 0x1000b2c */
  OESetSequenceNum(2); /* Line 129, Address: 0x1000b40 */
} /* Line 130, Address: 0x1000b4c */




void SNDMenu() { /* Line 135, Address: 0x1000b60 */
  unsigned short nMenuKindOld;

  if (swData1 & 2048) { /* Line 138, Address: 0x1000b74 */

    nMenuKindOld = nMenuKind; /* Line 140, Address: 0x1000b8c */
    nMenuKind = nMenuKind + 1 < 2 ? nMenuKind + 1 : 2; /* Line 141, Address: 0x1000b98 */
    if (nMenuKind == nMenuKindOld) return; /* Line 142, Address: 0x1000bdc */

    UpdateMenu(); /* Line 144, Address: 0x1000bf4 */
    KeyWait(); /* Line 145, Address: 0x1000bfc */

  } /* Line 147, Address: 0x1000c04 */
  else if (swData1 & 1024) { /* Line 148, Address: 0x1000c0c */

    nMenuKindOld = nMenuKind; /* Line 150, Address: 0x1000c24 */
    nMenuKind = nMenuKind - 1 > 1 ? nMenuKind - 1 : 1; /* Line 151, Address: 0x1000c30 */
    if (nMenuKind == nMenuKindOld) return; /* Line 152, Address: 0x1000c74 */

    UpdateMenu(); /* Line 154, Address: 0x1000c8c */
    KeyWait(); /* Line 155, Address: 0x1000c94 */

  } /* Line 157, Address: 0x1000c9c */
  else if (swData1 & 256) { /* Line 158, Address: 0x1000ca4 */

    if (nMenuKind == 1) { /* Line 160, Address: 0x1000cbc */

      if (nPCMNumberIndx == 0) nPCMNumberIndx = 79; /* Line 162, Address: 0x1000cd4 */
      else --nPCMNumberIndx; /* Line 163, Address: 0x1000cfc */

      StrPCMNO(nPCMNumberIndx); /* Line 165, Address: 0x1000d10 */
    } /* Line 166, Address: 0x1000d24 */
    else {

      if (nDANumberIndx == 0) nDANumberIndx = 33; /* Line 169, Address: 0x1000d2c */
      else --nDANumberIndx; /* Line 170, Address: 0x1000d54 */
      StrDANO(tblDA[nDANumberIndx]); /* Line 171, Address: 0x1000d68 */
    }
    KeyWait(); /* Line 173, Address: 0x1000d90 */
  } /* Line 174, Address: 0x1000d98 */
  else if (swData1 & 512) { /* Line 175, Address: 0x1000da0 */

    if (nMenuKind == 1) { /* Line 177, Address: 0x1000db8 */

      if (nPCMNumberIndx == 79) nPCMNumberIndx = 0; /* Line 179, Address: 0x1000dd0 */
      else ++nPCMNumberIndx; /* Line 180, Address: 0x1000df8 */

      StrPCMNO(nPCMNumberIndx); /* Line 182, Address: 0x1000e0c */
    } /* Line 183, Address: 0x1000e20 */
    else {

      if (nDANumberIndx == 33) nDANumberIndx = 0; /* Line 186, Address: 0x1000e28 */
      else ++nDANumberIndx; /* Line 187, Address: 0x1000e50 */
      StrDANO(tblDA[nDANumberIndx]); /* Line 188, Address: 0x1000e64 */
    }
    KeyWait(); /* Line 190, Address: 0x1000e8c */
  } /* Line 191, Address: 0x1000e94 */

  else if (swData1 & 16384) { /* Line 193, Address: 0x1000e9c */


    if (nPCMNumberIndx == 3 && nDANumberIndx == 1) { /* Line 196, Address: 0x1000eb4 */
      OEDeleteEA(); /* Line 197, Address: 0x1000ee4 */
      DeleteAllCharSprt(); /* Line 198, Address: 0x1000eec */
      MC_SONICCreate(0); /* Line 199, Address: 0x1000ef4 */
      bKakusi = 1; /* Line 200, Address: 0x1000f00 */
      CDPause(2); /* Line 201, Address: 0x1000f0c */
      CDPlay(21); /* Line 202, Address: 0x1000f20 */
      OESetSequenceNum(4); /* Line 203, Address: 0x1000f34 */
      return; /* Line 204, Address: 0x1000f40 */
    }
    if (nPCMNumberIndx == 12 && nDANumberIndx == 25) { /* Line 206, Address: 0x1000f48 */
      OEDeleteEA(); /* Line 207, Address: 0x1000f78 */
      DeleteAllCharSprt(); /* Line 208, Address: 0x1000f80 */
      MC_SONICCreate(1); /* Line 209, Address: 0x1000f88 */
      bKakusi = 1; /* Line 210, Address: 0x1000f94 */
      CDPause(2); /* Line 211, Address: 0x1000fa0 */
      CDPlay(24); /* Line 212, Address: 0x1000fb4 */
      OESetSequenceNum(4); /* Line 213, Address: 0x1000fc8 */
      return; /* Line 214, Address: 0x1000fd4 */
    }
    if (nPCMNumberIndx == 4 && nDANumberIndx == 21) { /* Line 216, Address: 0x1000fdc */
      OEDeleteEA(); /* Line 217, Address: 0x100100c */
      DeleteAllCharSprt(); /* Line 218, Address: 0x1001014 */
      MC_SONICCreate(2); /* Line 219, Address: 0x100101c */
      bKakusi = 1; /* Line 220, Address: 0x1001028 */
      CDPause(2); /* Line 221, Address: 0x1001034 */
      CDPlay(25); /* Line 222, Address: 0x1001048 */
      OESetSequenceNum(4); /* Line 223, Address: 0x100105c */
      return; /* Line 224, Address: 0x1001068 */
    }
    if (nPCMNumberIndx == 11 && nDANumberIndx == 9) { /* Line 226, Address: 0x1001070 */
      OEDeleteEA(); /* Line 227, Address: 0x10010a0 */
      DeleteAllCharSprt(); /* Line 228, Address: 0x10010a8 */
      MC_SONICCreate(3); /* Line 229, Address: 0x10010b0 */
      bKakusi = 1; /* Line 230, Address: 0x10010bc */
      CDPause(2); /* Line 231, Address: 0x10010c8 */
      CDPlay(4); /* Line 232, Address: 0x10010dc */
      OESetSequenceNum(4); /* Line 233, Address: 0x10010f0 */
      return; /* Line 234, Address: 0x10010fc */
    }

    if (nPCMNumberIndx == 7 && nDANumberIndx == 7) { /* Line 237, Address: 0x1001104 */
      CDPause(2); /* Line 238, Address: 0x1001134 */
      StrWelcome(); /* Line 239, Address: 0x1001148 */
      OESetSequenceNum(5); /* Line 240, Address: 0x1001150 */
      return; /* Line 241, Address: 0x100115c */
    }

    if (nPCMNumberIndx == 12 && nDANumberIndx == 11) { /* Line 244, Address: 0x1001164 */
      CDPause(2); /* Line 245, Address: 0x1001194 */
      CDPlay(33); /* Line 246, Address: 0x10011a8 */
      OEDeleteEA(); /* Line 247, Address: 0x10011bc */
      DeleteAllCharSprt(); /* Line 248, Address: 0x10011c4 */
      MC_SONICCreate(4); /* Line 249, Address: 0x10011cc */
      bKakusi = 2; /* Line 250, Address: 0x10011d8 */
      OESetSequenceNum(4); /* Line 251, Address: 0x10011e4 */
      return; /* Line 252, Address: 0x10011f0 */
    }

    if (nMenuKind == 1) { /* Line 255, Address: 0x10011f8 */


      WaveRequest(tblPCM[nPCMNumberIndx]); /* Line 258, Address: 0x1001210 */
    } /* Line 259, Address: 0x1001240 */
    else {

      CDPause(2); /* Line 262, Address: 0x1001248 */
      CDPlay(tblDA[nDANumberIndx]); /* Line 263, Address: 0x100125c */
    }
    WaitKeyOff(); /* Line 265, Address: 0x100128c */
  } /* Line 266, Address: 0x1001294 */

  else if (swData1 & 4096) { /* Line 268, Address: 0x100129c */

    CDPause(2); /* Line 270, Address: 0x10012b4 */
    OESetSequenceNum(999); /* Line 271, Address: 0x10012cc */
  }
} /* Line 273, Address: 0x10012dc */




int SNDEnd() { /* Line 278, Address: 0x1001300 */
  int ret = 0; /* Line 279, Address: 0x1001308 */

  if (nTimerCunt == 0) { /* Line 281, Address: 0x100130c */

    ret = 9; /* Line 283, Address: 0x100131c */
  }
  return ret; /* Line 285, Address: 0x1001320 */
} /* Line 286, Address: 0x1001324 */

int SNDEnd2() { /* Line 288, Address: 0x1001340 */
  int ret = 0; /* Line 289, Address: 0x1001348 */

  if (nTimerCunt == 0) { /* Line 291, Address: 0x100134c */

    ret = 18; /* Line 293, Address: 0x100135c */
  }
  return ret; /* Line 295, Address: 0x1001360 */
} /* Line 296, Address: 0x1001364 */

int SNDEnd3() { /* Line 298, Address: 0x1001380 */
  int ret = 0; /* Line 299, Address: 0x1001388 */

  if (nTimerCunt == 0) { /* Line 301, Address: 0x100138c */

    ret = 19; /* Line 303, Address: 0x100139c */
  }
  return ret; /* Line 305, Address: 0x10013a0 */
} /* Line 306, Address: 0x10013a4 */





















































int MC_SONICCreate(short cgno) { /* Line 360, Address: 0x10013c0 */
  unsigned int mask[4] = { 0, 0, 0, 0 }; /* Line 361, Address: 0x10013d0 */
  RECT rect = { 0, 0, 320, 224 }; /* Line 362, Address: 0x1001400 */
  RECT rect2 = { 0, 0, 160, 224 }; /* Line 363, Address: 0x1001414 */
  RECT rect3 = { 0, 0, 160, 224 }; /* Line 364, Address: 0x1001428 */

  POINT pt = { 0, 0 }; /* Line 366, Address: 0x100143c */
  POINT pt2 = { 160, 0 }; /* Line 367, Address: 0x100146c */
  hmx_bitmap* bmp;























  switch (cgno) { /* Line 392, Address: 0x1001480 */

    case 0:
      OEClrset(HOSHINOcolor, 0); /* Line 395, Address: 0x10014cc */
      break; /* Line 396, Address: 0x10014e0 */
    case 1:
      OEClrset(NISIMURAcolor, 0); /* Line 398, Address: 0x10014e8 */
      break; /* Line 399, Address: 0x10014fc */
    case 2:
      OEClrset(MIYAKEcolor, 0); /* Line 401, Address: 0x1001504 */
      break; /* Line 402, Address: 0x1001518 */
    case 3:
      OEClrset(SANPEIcolor, 0); /* Line 404, Address: 0x1001520 */
      break; /* Line 405, Address: 0x1001534 */
    case 4:
      OEClrset(YAMAGU1color, 0); /* Line 407, Address: 0x100153c */
      OEClrset(YAMAGU2color, 1); /* Line 408, Address: 0x1001550 */
      break;
  }

  bmp = hmx_bitmap_create_module(g_env_module, 320, 224); /* Line 412, Address: 0x1001564 */

  switch (cgno) { /* Line 414, Address: 0x1001588 */


    case 0:
      ld_bitmap_file("HOSHINO3.BMP", hmx_bitmap_get_scan0_module(bmp), rect.right, rect.bottom, 0, 0); /* Line 418, Address: 0x10015d4 */
      break; /* Line 419, Address: 0x100160c */

    case 1:
      ld_bitmap_file("NISIMUR3.BMP", hmx_bitmap_get_scan0_module(bmp), rect.right, rect.bottom, 0, 0); /* Line 422, Address: 0x1001614 */
      break; /* Line 423, Address: 0x100164c */

    case 2:
      ld_bitmap_file("MIYAKE3.BMP", hmx_bitmap_get_scan0_module(bmp), rect.right, rect.bottom, 0, 0); /* Line 426, Address: 0x1001654 */
      break; /* Line 427, Address: 0x100168c */

    case 3:
      ld_bitmap_file("SANPEI3.BMP", hmx_bitmap_get_scan0_module(bmp), rect.right, rect.bottom, 0, 0); /* Line 430, Address: 0x1001694 */
      break; /* Line 431, Address: 0x10016cc */



    case 4:
      ld_bitmap_file2("YAMA_L3.BMP", hmx_bitmap_get_scan0_module(bmp), 320, 224, rect2.right, rect2.bottom, 0, 0, 0, 0); /* Line 436, Address: 0x10016d4 */
      ld_bitmap_file2("YAMA_R3.BMP", hmx_bitmap_get_scan0_module(bmp), 320, 224, rect3.right, rect3.bottom, 160, 0, 0, 0); /* Line 437, Address: 0x100171c */
      break;
  }







  s_ctx->spr_bitmaps[0] = bmp; /* Line 447, Address: 0x1001764 */
  hmx_sprite_set_position_module(s_ctx->sprites[0], 0, 0); /* Line 448, Address: 0x1001770 */
  hmx_sprite_set_bitmap_module(s_ctx->sprites[0], s_ctx->spr_bitmaps[0]); /* Line 449, Address: 0x1001798 */
  s_ctx->spr_level[0] = 1; /* Line 450, Address: 0x10017c4 */

  return 0; /* Line 452, Address: 0x10017d4 */
} /* Line 453, Address: 0x10017d8 */



int MC_SONICDelete() { /* Line 457, Address: 0x10017f0 */
  hmx_bitmap_release_module(g_env_module, s_ctx->spr_bitmaps[0]); /* Line 458, Address: 0x10017f8 */
  s_ctx->spr_bitmaps[0] = 0; /* Line 459, Address: 0x100181c */
  s_ctx->spr_level[0] = 0; /* Line 460, Address: 0x1001828 */


  return 0; /* Line 463, Address: 0x1001834 */
} /* Line 464, Address: 0x1001838 */

void SNDKakusi() { /* Line 466, Address: 0x1001850 */
  if (!(swData1 & 16384)) bKakusi |= 4; /* Line 467, Address: 0x1001858 */
  if (bKakusi & 4 && (swData1 & 16384 || swData1 & 4096)) { /* Line 468, Address: 0x1001884 */
    if ((bKakusi & 3) == 2) OESetSequenceNum(7); /* Line 469, Address: 0x10018c8 */
    if ((bKakusi & 3) == 1) OESetSequenceNum(999); /* Line 470, Address: 0x10018ec */
  }

} /* Line 473, Address: 0x1001910 */

void SNDSpecialMes() { /* Line 475, Address: 0x1001920 */
  if (!(swData1 & 16384)) bKakusi |= 4; /* Line 476, Address: 0x1001928 */
  if (bKakusi & 4 && (swData1 & 16384 || swData1 & 4096)) { /* Line 477, Address: 0x1001954 */
    DeleteCharMes(); /* Line 478, Address: 0x1001998 */
    bKakusi = 0; /* Line 479, Address: 0x10019a0 */
    OESetSequenceNum(6); /* Line 480, Address: 0x10019a8 */
  }

} /* Line 483, Address: 0x10019b4 */
