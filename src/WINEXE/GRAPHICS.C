#include "GRAPHICS.H"
#include <windows.h>
#include "DINO2D.H"
#include "DMIX.H"
#include "TYPES.H"
#include "BMP.H"
#include "WINMAIN.H"

typedef struct genericArray {
  void* pArray;
  int cnt;
}
genericArray;

typedef struct specData {
  unsigned char width;
  unsigned char height;
  unsigned char pos;
}
specData;

/* 00415000 */ char DAT_00415000[256];
/* 00415100 */ RECT DAT_00415100[8];
/* 00415180 */ void* gpBackground;
/* 00415184 */ unsigned int DAT_00415184;
/* 00415188 */ void* DAT_00415188[80];
/* 004152c8 */ void* DAT_004152c8;
/* 004152cc */ void* DAT_004152cc;
/* 004152d0 */ void* DAT_004152d0[80];
/* 00415410 */ ULONG gSurfFuncRet;
/* 00415418 */ void* DAT_00415418[1640];
/* 00416db8 */ void* DAT_00416db8[1640];
/* 00418758 */ void* DAT_00418758[1640];
/* 0041a100 */ void* gSprites[80];
/* 0041a240 */ void* gpScreenBmp;
/* 0041a244 */ int_union* gpHscroll;
/* 0041a248 */ USHORT gSprites_idx[80];
/* 0041a2e8 */ UCHAR gSprites_rev[80];
/* 0041a338 */ void** gpBmpArray;
/* 0041a340 */ void* DAT_0041a340[3712];
/* 0041dd40 */ int DAT_0041dd40;
/* 0041dd44 */ RECT* DAT_0041dd44;
/* 0041dd48 */ int_union DAT_0041dd48;
/* 0041dd50 */ void** DAT_0041dd50;
/* 0041dd54 */ int DAT_0041dd54;
/* 0041dd60 */ void** DAT_0041dd60;
/* 0041dd64 */ int_union DAT_0041dd64;
/* 0041dd6c */ int DAT_0041dd6c;
/* 0041dd80 */ void* DAT_0041dd80[3712];
/* 0041a0f8 */ int_union DAT_0041a0f8;
/* 0041dd5c */ void* DAT_0041dd5c;
/* 0041dd68 */ void** DAT_0041dd68;
/* 0041dd70 */ RECT gGridRect;
/* 00421780 */ POINT gSprites_pos[80];
/* 00421a00 */ void* DAT_00421a00[3712];
/* 0042cf70 */ void (__stdcall *gpSpecialblockchg)(unsigned short*, unsigned short*, unsigned short*, unsigned short*);
/* 0042cf7c */ HWND ghWnd;
/* 0042ffa0 */ game_info gKeepWork;
/* 00430324 */ void (__stdcall *gpGetRoundStr)(unsigned short, unsigned char, char*);
/* 00430328 */ HPALETTE ghPalette;
/* 0043032c */ void* gpGrid;
/* 00430330 */ void* DAT_00430330[8];
/* 00430350 */ void* DAT_00430350[8];
/* 004320b8 */ BOOL DAT_004320b8 = FALSE;
/* 004320bc */ void* ghSurf = 0;
/* 004320c0 */ RECT* DAT_004320c0 = 0;
/* 004320c4 */ BOOL DAT_004320c4 = FALSE;
/* 004320c8 */ specData DAT_004320c8[8][8] = {
  {
    { 40,  2,  1 },
    { 64, 10,  2 },
    { 64,  4, 12 },
    { 64, 16,  0 },
    { 64, 12, 16 },
    {  0,  0,  0 },
    {  0,  0,  0 },
    {  0,  0,  0 }
  },
  {
    { 40,  2,  1 },
    { 64, 16,  0 },
    { 64, 16,  0 },
    { 40, 12, 16 },
    {  0,  0,  0 },
    {  0,  0,  0 },
    {  0,  0,  0 },
    {  0,  0,  0 }
  },
  {
    { 40,  2,  1 },
    { 64, 16,  0 },
    { 64,  6,  0 },
    { 64,  3,  6 },
    { 64,  1,  9 },
    { 64,  4, 10 },
    { 64,  2, 14 },
    { 40, 12, 16 }
  },
  {
    { 40,  2,  1 },
    { 64,  5, 11 },
    { 64, 16,  0 },
    { 64, 11,  0 },
    {  0,  0,  0 },
    {  0,  0,  0 },
    {  0,  0,  0 },
    {  0,  0,  0 }
  },
  {
    { 40,  2,  1 },
    { 64, 14,  2 },
    { 40, 12, 16 },
    { 64, 16,  0 },
    {  0,  0,  0 },
    {  0,  0,  0 },
    {  0,  0,  0 },
    {  0,  0,  0 }
  },
  {
    { 40,  2,  1 },
    { 64, 14,  2 },
    { 40, 12, 16 },
    { 64, 16,  0 },
    {  0,  0,  0 },
    {  0,  0,  0 },
    {  0,  0,  0 },
    {  0,  0,  0 }
  },
  {
    { 40,  2,  1 },
    { 64,  6, 10 },
    { 64, 14,  0 },
    { 64,  2, 14 },
    { 64, 10,  0 },
    { 40, 12, 16 },
    {  0,  0,  0 },
    {  0,  0,  0 }
  },
  {
    { 40,  2,  1 },
    { 40, 16,  0 },
    { 40, 12, 16 },
    {  0,  0,  0 },
    {  0,  0,  0 },
    {  0,  0,  0 },
    {  0,  0,  0 },
    {  0,  0,  0 }
  }
};
/* 00432188 */ USHORT DAT_00432188[3] = { 2000, 5000, 6000 };
/* 00432190 */ USHORT DAT_00432190[8] = { 6000, 6001, 6002, 6003, 6004, 6005, 6006, 6007 };
/* 004321a0 */ char DAT_004321a0[9] = "s1b0.bin";
/* 004321ac */ char DAT_004321ac[9] = "s1b0.bin";
/* 004321b8 */ char DAT_004321b8[9] = "s1b1.bin";
/* 004321c4 */ char DAT_004321c4[9] = "s1b1.bin";
/* 004321d0 */ char DAT_004321d0[9] = "s1a0.bin";
/* 004321dc */ char DAT_004321dc[9] = "s1a1.bin";
/* 004321e8 */ tileInfo DAT_004321e8[6] = {
  { 3, 0, 0, 32, 16, 0, 203, 0, DAT_004321a0 },
  { 3, 32, 0, 32, 16, 0, 203, 0, DAT_004321ac },
  { 4, 0, 0, 32, 12, 0, 35, 0, DAT_004321b8 },
  { 4, 32, 0, 32, 12, 0, 35, 0, DAT_004321c4 },
  { 1, 0, 0, 64, 10, 0, 40, 1, DAT_004321d0 },
  { 2, 0, 0, 64, 4, 0, 40, 1, DAT_004321dc }
};
/* 00432248 */ char DAT_00432248[12] = "mpb1_a0.bin";
/* 00432254 */ char DAT_00432254[12] = "mpb1_a1.bin";
/* 00432260 */ char DAT_00432260[12] = "mpb1_b0.bin";
/* 0043226c */ char DAT_0043226c[12] = "mpb1_b1.bin";
/* 00432278 */ char DAT_00432278[12] = "mpb1_b2.bin";
/* 00432284 */ char DAT_00432284[12] = "mpb1_b2.bin";
/* 00432290 */ tileInfo DAT_00432290[6] = {
  { 1, 0, 0, 32, 16, 0, 35, 0, DAT_00432248 },
  { 1, 32, 0, 32, 16, 0, 35, 0, DAT_00432254 },
  { 2, 0, 0, 32, 16, 0, 35, 1, DAT_00432260 },
  { 2, 32, 0, 32, 16, 0, 35, 1, DAT_0043226c },
  { 3, 0, 0, 32, 12, 0, 35, 0, DAT_00432278 },
  { 3, 8, 0, 32, 12, 0, 35, 0, DAT_00432284 }
};
/* 004322f0 */ char DAT_004322f0[12] = "mpb2_a0.bin";
/* 004322fc */ char DAT_004322fc[12] = "mpb2_a1.bin";
/* 00432308 */ char DAT_00432308[13] = "mpb2_b00.bin";
/* 00432318 */ char DAT_00432318[13] = "mpb2_b20.bin";
/* 00432328 */ char DAT_00432328[13] = "mpb2_b01.bin";
/* 00432338 */ char DAT_00432338[13] = "mpb2_b21.bin";
/* 00432348 */ char DAT_00432348[13] = "mpb2_b02.bin";
/* 00432358 */ char DAT_00432358[13] = "mpb2_b22.bin";
/* 00432368 */ char DAT_00432368[13] = "mpb2_b03.bin";
/* 00432378 */ char DAT_00432378[13] = "mpb2_b23.bin";
/* 00432388 */ char DAT_00432388[12] = "mpb2_b1.bin";
/* 00432394 */ char DAT_00432394[12] = "mpb2_b1.bin";
/* 004323a0 */ char DAT_004323a0[12] = "mpb2_b4.bin";
/* 004323ac */ char DAT_004323ac[12] = "mpb2_b4.bin";
/* 004323b8 */ tileInfo DAT_004323b8[14] = {
  { 1, 0, 0, 32, 16, 0, 34, 1, DAT_004322f0 },
  { 1, 32, 0, 32, 16, 0, 34, 1, DAT_004322fc },
  { 2, 0, 0, 32, 6, 0, 34, 1, DAT_00432308 },
  { 2, 32, 0, 32, 6, 0, 34, 1, DAT_00432318 },
  { 3, 0, 0, 32, 3, 0, 34, 1, DAT_00432328 },
  { 3, 32, 0, 32, 3, 0, 34, 1, DAT_00432338 },
  { 4, 0, 0, 32, 1, 0, 34, 1, DAT_00432348 },
  { 4, 32, 0, 32, 1, 0, 34, 1, DAT_00432358 },
  { 5, 0, 0, 32, 4, 0, 34, 1, DAT_00432368 },
  { 5, 32, 0, 32, 4, 0, 34, 1, DAT_00432378 },
  { 6, 0, 0, 32, 2, 0, 34, 1, DAT_00432388 },
  { 6, 32, 0, 32, 2, 0, 34, 1, DAT_00432394 },
  { 7, 0, 0, 32, 12, 0, 41, 1, DAT_004323a0 },
  { 7, 8, 0, 32, 12, 0, 41, 1, DAT_004323ac }
};
/* 00432498 */ char DAT_00432498[12] = "mpb3_b1.bin";
/* 004324a4 */ char DAT_004324a4[12] = "mpb3_b3.bin";
/* 004324b0 */ char DAT_004324b0[12] = "mpb3_a0.bin";
/* 004324bc */ char DAT_004324bc[12] = "mpb3_a1.bin";
/* 004324c8 */ char DAT_004324c8[12] = "mpb3_b0.bin";
/* 004324d4 */ char DAT_004324d4[12] = "mpb3_b2.bin";
/* 004324e0 */ tileInfo DAT_004324e0[6] = {
  { 1, 0, 0, 32, 5, 0, 35, 1, DAT_00432498 },
  { 1, 32, 0, 32, 5, 0, 35, 1, DAT_004324a4 },
  { 2, 0, 0, 32, 16, 0, 35, 1, DAT_004324b0 },
  { 2, 32, 0, 32, 16, 0, 35, 1, DAT_004324bc },
  { 3, 0, 0, 32, 11, 0, 35, 1, DAT_004324c8 },
  { 3, 32, 0, 32, 11, 0, 35, 1, DAT_004324d4 }
};
/* 00432540 */ char DAT_00432540[12] = "mpb4_a0.bin";
/* 0043254c */ char DAT_0043254c[12] = "mpb4_a1.bin";
/* 00432558 */ char DAT_00432558[12] = "mpb4_b0.bin";
/* 00432564 */ char DAT_00432564[12] = "mpb4_b1.bin";
/* 00432570 */ char DAT_00432570[12] = "mpb4_b2.bin";
/* 0043257c */ char DAT_0043257c[12] = "mpb4_b2.bin";
/* 00432588 */ tileInfo DAT_00432588[6] = {
  { 1, 0, 0, 32, 14, 0, 172, 1, DAT_00432540 },
  { 1, 32, 0, 32, 14, 0, 172, 1, DAT_0043254c },
  { 3, 0, 0, 32, 16, 0, -97, 1, DAT_00432558 },
  { 3, 32, 0, 32, 16, 0, -97, 1, DAT_00432564 },
  { 2, 0, 0, 32, 12, 0, 35, 0, DAT_00432570 },
  { 2, 8, 0, 32, 12, 0, 35, 0, DAT_0043257c }
};
/* 004325e8 */ char DAT_004325e8[12] = "sp6_a01.bin";
/* 004325f4 */ char DAT_004325f4[12] = "sp6_a02.bin";
/* 00432600 */ char DAT_00432600[11] = "sp6_b0.bin";
/* 0043260c */ char DAT_0043260c[11] = "sp6_b0.bin";
/* 00432618 */ char DAT_00432618[12] = "sp6_000.bin";
/* 00432624 */ char DAT_00432624[12] = "sp6_000.bin";
/* 00432630 */ tileInfo DAT_00432630[6] = {
  { 1, 0, 0, 32, 14, 0, 35, 1, DAT_004325e8 },
  { 1, 32, 0, 32, 14, 0, 35, 1, DAT_004325f4 },
  { 3, 0, 0, 32, 16, 0, 55, 1, DAT_00432600 },
  { 3, 32, 0, 32, 16, 0, 55, 1, DAT_0043260c },
  { 2, 0, 0, 32, 12, 0, 52, 0, DAT_00432618 },
  { 2, 8, 0, 32, 12, 0, 52, 0, DAT_00432624 }
};
/* 00432690 */ char DAT_00432690[12] = "mpb6b2l.bin";
/* 0043269c */ char DAT_0043269c[12] = "mpb6b2r.bin";
/* 004326a8 */ char DAT_004326a8[12] = "mpb6a1r.bin";
/* 004326b4 */ char DAT_004326b4[12] = "mpb6a1l.bin";
/* 004326c0 */ char DAT_004326c0[12] = "mpb6a2r.bin";
/* 004326cc */ char DAT_004326cc[12] = "mpb6a2l.bin";
/* 004326d8 */ char DAT_004326d8[12] = "mpb6b1l.bin";
/* 004326e4 */ char DAT_004326e4[12] = "mpb6b1r.bin";
/* 004326f0 */ char DAT_004326f0[12] = "mpb6_b8.bin";
/* 004326fc */ char DAT_004326fc[12] = "mpb6_b8.bin";
/* 00432708 */ tileInfo DAT_00432708[10] = {
  { 1, 0, 0, 32, 6, 0, 35, 1, DAT_00432690 },
  { 1, 32, 0, 32, 6, 0, 35, 1, DAT_0043269c },
  { 2, 0, 0, 32, 14, 0, 35, 1, DAT_004326a8 },
  { 2, 32, 0, 32, 14, 0, 35, 1, DAT_004326b4 },
  { 3, 0, 0, 32, 2, 0, 35, 1, DAT_004326c0 },
  { 3, 32, 0, 32, 2, 0, 35, 1, DAT_004326cc },
  { 4, 0, 0, 32, 10, 0, 35, 1, DAT_004326d8 },
  { 4, 32, 0, 32, 10, 0, 35, 1, DAT_004326e4 },
  { 5, 0, 0, 32, 12, 0, 471, 0, DAT_004326f0 },
  { 5, 8, 0, 32, 12, 0, 471, 0, DAT_004326fc }
};
/* 004327a8 */ char DAT_004327a8[8] = "egg.bin";
/* 004327b0 */ char DAT_004327b0[12] = "mpb7_b1.bin";
/* 004327bc */ char DAT_004327bc[12] = "mpb7_b1.bin";
/* 004327c8 */ tileInfo DAT_004327c8[3] = {
  { 1, 0, 0, 40, 16, 0, 41, 0, DAT_004327a8 },
  { 2, 0, 0, 32, 12, 0, 35, 0, DAT_004327b0 },
  { 2, 8, 0, 32, 12, 0, 35, 0, DAT_004327bc }
};
/* 004327f8 */ char DAT_004327f8[11] = "panel1.bin";
/* 00432804 */ char DAT_00432804[11] = "panel2.bin";
/* 00432810 */ tileInfo DAT_00432810[2] = {
  { 0, 0, 0, 40, 2, 0, 0, 0, DAT_004327f8 },
  { 0, 0, 0, 40, 2, 0, 0, 0, DAT_00432804 }
};
/* 00432830 */ char DAT_00432830[12] = "clrback.bin";
/* 00432840 */ tileInfo DAT_00432840[1] = {
  { 1, 0, 0, 40, 28, 0, 687, 1, DAT_00432830 }
};
/* 00432850 */ char DAT_00432850[11] = "cgwarp.bin";
/* 0043285c */ char DAT_0043285c[11] = "cgwarp.bin";
/* 00432868 */ tileInfo DAT_00432868[2] = {
  { 1, 0, 0, 40, 28, 0, 0, 1, DAT_00432850 },
  { 1, 0, 28, 40, 4, 0, 0, 1, DAT_0043285c }
};
/* 00432888 */ genericArray DAT_00432888[8] = {
  { DAT_004321e8, 6 },
  { DAT_00432290, 6 },
  { DAT_004323b8, 14 },
  { DAT_004324e0, 6 },
  { DAT_00432588, 6 },
  { DAT_00432630, 6 },
  { DAT_00432708, 10 },
  { DAT_004327c8, 3 }
};
/* 004328c8 */ genericArray DAT_004328c8 = { DAT_00432840, 1 };
/* 004328d0 */ RECT gBackgroundRect = { 0, 0, 320, 224 };
/* 004328e8 */ void* DAT_004328e8[2] = {
  (void*)&FUN_004044ee,
  (void*)&gKeepWork
};
/* 004328f0 */ POINT gCursorPos;
/* 004328f8 */ unsigned short DAT_004328f8[8] = { 0, 0x0B00, 0x8000, 0xFF30, 0xFF30, 0, 0xBF30, 0 };
/* 00432c24 */ char DAT_00432c24[17] = "SPECIAL\\BMP\\FIX\\";
/* 00432c38 */ char DAT_00432c38[6] = "WARP\\";
/* 0043327c */ PALETTEENTRY* gpColorwk = 0;
/* 00433284 */ PALETTEENTRY* gpColorwk3 = 0;
/* 00433290 */ int_union* gpHscrollbuff = 0;
/* 004332d0 */ BOOL gbSpecialStageLoaded = FALSE;
/* 004332d4 */ BOOL gbWarpLoaded = FALSE;
/* 004332d8 */ BOOL gbLittlePlanetLoaded = FALSE;
/* 004332dc */ BOOL gbThanksLoaded = FALSE;
/* 004332fc */ BOOL gbSpriteLoadingEnabled = TRUE;
/* 00433300 */ BOOL DAT_00433300 = TRUE;
/* 0043330c */ BOOL gbFullScreen = FALSE;


// 00401880
void __stdcall EAsprset(short x, short y, USHORT index, USHORT linkdata, USHORT reverse) {
  // index: missing and 0xFFFF
  if (index == 0) {
    _objSetVisibility(gSprites[linkdata], 0);
    gSprites_rev[linkdata] = 0;
    gSprites_idx[linkdata] = index;
    return;
  }
  // order, index: missing and 0xFFFF
  if (index >= DAT_0041dd64.w.l) {
    log("Sprite Bitmap Error");
    return;
  }
  _objSetVisibility(gSprites[linkdata], 1);
  // sprites_idx: xor instead of and
  if (gSprites_idx[linkdata] != index) {
    _sprDelete(gSprites[linkdata]);
    gSprites[linkdata] = 0;
    _sprCreate(&gSprites[linkdata]);
    gSurfFuncRet = _objApplyEffect(gSprites[linkdata], FX_HORIZ_FLIP, 0, &DAT_00415188[linkdata]);
    gSurfFuncRet = _objApplyEffect(gSprites[linkdata], FX_VERT_FLIP, 0, &DAT_004152d0[linkdata]);
    _objSetDestination(gSprites[linkdata], ghSurf);
    _sprSetData(gSprites[linkdata], DAT_0041dd50[index]);
    gSprites_rev[linkdata] = 0xFF;
  }
  gSprites_idx[linkdata] = index;

  switch (reverse & 3) {
    case 0:
      _fxSetActive(DAT_00415188[linkdata], 0);
      _fxSetActive(DAT_004152d0[linkdata], 0);
      break;
    case 1:
      _fxSetActive(DAT_00415188[linkdata], 1);
      _fxSetActive(DAT_004152d0[linkdata], 0);
      break;
    case 2:
      _fxSetActive(DAT_00415188[linkdata], 0);
      _fxSetActive(DAT_004152d0[linkdata], 1);
      break;
    case 3:
      _fxSetActive(DAT_00415188[linkdata], 1);
      _fxSetActive(DAT_004152d0[linkdata], 1);
      break;
    default:
      log("REV = default");
      break;
  }

  gSprites_rev[linkdata] = reverse & 3;
  // reverse: missing and 0xFFFF
  if (reverse & 0x8000) {
    gSurfFuncRet = _objSetDrawOrder(gSprites[linkdata], linkdata * 10 + 1000);
  }
  else {
    gSurfFuncRet = _objSetDrawOrder(gSprites[linkdata], linkdata * 10 + 3000);
  }
  gSprites_pos[linkdata].x = x - 128;
  gSprites_pos[linkdata].y = y - 128;
}


// 00401c49
void __stdcall SetGrid(int base, int x, int y, int block, int frip) {
  myPoint point;
  int index;
  if (gbSpecialStageLoaded) {
    point.x = x;
    point.y = y;
    if (block & 0x7FF) {
      if (_grdSetData(DAT_00430330[0], point, DAT_0041a340[(block & 0x7FF) * 4])) {
        wsprintf(DAT_00415000, "%d %d %x\n", point.x, point.y, block);
        log(DAT_00415000);
      }
    }
    else {
      gSurfFuncRet = _grdClearData(DAT_00430330[0], point);
    }
    return;
  }

  if (gbLittlePlanetLoaded == TRUE && base < 0) {
    point.x = x;
    point.y = y;
    index = block & 0x7FF;
    if (index != 0) {
      index = (((index / 4) - 1) * 8);
      switch (block & 0xE000) {
        case 0:
          break;
        case 0x8000:
          ++index;
          break;
        case 0xC000:
          index += 2;
          break;
        case 0x4000:
          index += 3;
          break;
        case 0x6000:
          index += 4;
          break;
        case 0xA000:
          index += 6;
          break;
        case 0xE000:
          index += 5;
          break;
        case 0x2000:
          index += 7;
          break;
      }
      gSurfFuncRet = _grdSetData(gpGrid, point, DAT_00418758[index]);
    }
    else {
      gSurfFuncRet = _grdClearData(gpGrid, point);
    }
    return;
  }

  point.x = x;
  point.y = y;
  index = block & 0x7FF;
  frip = (frip ^ block) & 0x1800;
  if (frip == 0) {
    index *= 4;
  }
  else if (frip == 0x1800) {
    index = index * 4 + 3;
  }
  else if (frip & 0x1000) {
    index = index * 4 + 2;
  }
  else {
    index = index * 4 + 1;
  }
  if (index == 0) {
    if (base != 0) {
      gSurfFuncRet = _grdClearData(DAT_00430330[2], point);
    }
    else {
      gSurfFuncRet = _grdClearData(DAT_00430330[0], point);
      gSurfFuncRet = _grdClearData(DAT_00430330[1], point);
    }
  }
  else if (base != 0) {
    gSurfFuncRet = _grdSetData(DAT_00430330[2], point , DAT_0041a340[index]);
  }
  else if (block & 0x8000) {
    gSurfFuncRet = _grdSetData(DAT_00430330[0], point, DAT_0041a340[index]);
    gSurfFuncRet = _grdClearData(DAT_00430330[1], point);
  }
  else {
    gSurfFuncRet = _grdClearData(DAT_00430330[0], point);
    gSurfFuncRet = _grdSetData(DAT_00430330[1], point, DAT_0041a340[index]);
  }
}


// 00401fe8
int toInteger(char** ppNumber) {
  int number = 0;
  int base = 10;
  char* pDigit = *ppNumber;

  do {
    if (*pDigit >= '0' && *pDigit <= '9') {
      number *= base;
      number += *pDigit - '0';
    }
    else if (*pDigit >= 'a' && *pDigit <= 'f') {
      number *= base;
      number += *pDigit - ('a' - 10);
    }
    else if (*pDigit >= 'A' && *pDigit <= 'F') {
      number *= base;
      number += *pDigit - ('A' - 10);
    }
    else if (*pDigit == 0) {
      *ppNumber = 0;
      return -1;
    }
    else if (*pDigit == ',') {
      ++pDigit;
      break;
    }
    else if (*pDigit == 'x' || *pDigit == 'X') {
      base = 16;
    }
    ++pDigit;
  }
  while (1);

  *ppNumber = pDigit;
  return number;
}


// 00402136
int FUN_00402136(HFILE hFile, char* pOutput, int* pNumber) {
  char buffer[256];
  int i;
  char* pBuffer;
  char* pOutputDigit;

  do {
    for (i = 0; ; ++i) {
      if (_lread(hFile, &buffer[i], 1) != 1) {
        if (i != 0) {
          buffer[i] = 0;
          break;
        }
        else {
          return -1;
        }
      }
      if (buffer[i] == '\n') {
        buffer[i] = 0;
        break;
      }
    }

    pBuffer = buffer;

    do {
      if (*pBuffer == '/') break;
      if (*pBuffer == '0') break;
      if (*pBuffer == 0) break;
      ++pBuffer;
    }
    while (1);

    if (*pBuffer == '0') {
      ++pBuffer;
      break;
    }
  }
  while (1);

  *pNumber = toInteger(&pBuffer);
  if (pBuffer == 0) {
    return -1;
  }

  do {
    if (*pBuffer != ',' && *pBuffer != ' ' && *pBuffer != '\t') break;
    else if (*pBuffer == 0) {
      _lclose(hFile);
      return -1;
    }
    ++pBuffer;
  }
  while (1);

  pOutputDigit = pOutput;

  do {
    if (*pBuffer == ',' || *pBuffer == ' ' || *pBuffer == '\t' || *pBuffer == 0 || *pBuffer == '\r' || *pBuffer == '\n') {
      *pOutputDigit = 0;
      break;
    }
    else {
      *pOutputDigit = *pBuffer;
      ++pBuffer;
      ++pOutputDigit;
    }
  }
  while (1);

  return 0;
}


// 00402341
int SpriteBMPCreate() {
  int local_c = 0;
  int local_8 = 0;
  int local_70 = 0;
  int local_6c = 0;
  int local_68 = 0;
  int local_64 = 0;
  int local_ac = 0;
  int local_a8 = 0;
  int local_a4 = 0;
  int local_a0 = 0;
  int local_cc;
  int err;
  char fileName[80];
  char msg[80];
  HFILE hFile;
  int i;
  int local_124;
  HFILE hFile2;
  char local_c4[14];
  char local_98[40];
  int local_9c;
  int local_b0;
  if (gbSpecialStageLoaded && gKeepWork.SPEMode != 0) {
    return 0;
  }
  if (gbSpriteLoadingEnabled) {
    if (gbWarpLoaded) {
      lstrcpy(fileName, "WARP\\SCMPWARP.CM_");
    }
    else if (gbSpecialStageLoaded) {
      lstrcpy(fileName, "SPECIAL\\SCMPSPE.CM_");
    }
    else if (gbLittlePlanetLoaded) {
      lstrcpy(fileName, "TITLE\\PLANET\\CG\\SCMPLP.CM_");
    }
    else if (gbThanksLoaded) {
      lstrcpy(fileName, "TITLE\\THANKS\\CG\\SCMPTH.CM_");
    }
    else {
      (*gpGetRoundStr)(gKeepWork.stageno.w, gKeepWork.time_flag, msg);
      wsprintf(fileName, "R%c\\%3s\\SCMP%3s.CM_", msg[0], msg, msg);
    }
    wsprintf(msg, "Read Tile CMP BMP: %s\n", fileName);
    log(msg);
    err = extractSprites(&DAT_0041dd50, &local_cc, fileName);
    if (err != 0) {
      wsprintf(msg, "Cmp Spr Load Error 0x%lx\n", err);
      log(msg);
      return err;
    }
    DAT_0041dd64.l = local_cc;
  }
  else {
    DAT_0041dd50 = (void**)GlobalLock(GlobalAlloc(GMEM_ZEROINIT, 2800));
    if (DAT_0041dd50 == 0) {
      return -1;
    }
    if (gbWarpLoaded) {
      lstrcpy(fileName, "WARP\\SCMPWARP.TXT");
    }
    else if (gbSpecialStageLoaded) {
      lstrcpy(fileName, "SPECIAL\\SCMPSPE.TXT");
    }
    else if (gbLittlePlanetLoaded) {
      lstrcpy(fileName, "TITLE\\PLANET\\CG\\SCMPLP.TXT");
    }
    else if (gbThanksLoaded) {
      lstrcpy(fileName, "TITLE\\THANKS\\CG\\SCMPTH.TXT");
    }
    else {
      (*gpGetRoundStr)(gKeepWork.stageno.w, gKeepWork.time_flag, msg);
      wsprintf(fileName, "R%c\\%3s\\SCMP%3s.TXT", msg[0], msg, msg);
    }
    hFile = _lopen(fileName, OF_READ);
    if (hFile == -1) {
      wsprintf(msg, "Can't Open %s\n", fileName);
      log(msg);
      return -1;
    }

    for (i = 0; i < 700; ++i) {
      if (FUN_00402136(hFile, fileName, &local_124) != 0) {
        log("File End\n");
        _lclose(hFile);
        DAT_0041dd64.l = i;
        return 0;
      }
      if (gbWarpLoaded) {
        lstrcpy(msg, fileName);
        lstrcpy(fileName, "WARP\\");
        lstrcat(fileName, msg);
      }
      else if (gbLittlePlanetLoaded) {
        wsprintf(fileName, "%s%s", "TITLE", &fileName[5]);
      }
      else if (gbThanksLoaded) {
        wsprintf(fileName, "%s%s", "TITLE", &fileName[5]);
      }
      else if (!gbSpecialStageLoaded) {
        lstrcpy(msg, &fileName[6]);
        lstrcpy(fileName, msg);
      }
      hFile2 = _lopen(fileName, OF_READ);
      if (hFile2 == -1) {
        wsprintf(msg, "Read Error %d %s\n", i, fileName);
        log(msg);
        return -1;
      }
      else {
        if (_lread(hFile2, local_c4, 14) == -1) {
          err = -1;
        }
        if (_lread(hFile2, local_98, 40) == -1) {
          err = -1;
        }
        _lclose(hFile2);
        local_9c = ((int*)local_98)[1];
        local_b0 = ((int*)local_98)[2];
        ((UCHAR*)gKeepWork.pSprBmp)[i * 3] = local_9c;
        ((UCHAR*)gKeepWork.pSprBmp)[i * 3 + 1] = local_b0;
        gSurfFuncRet = _hbmpCreate(local_9c, local_b0, 0, &DAT_0041dd50[i]);
        if (FUN_0040653a(local_9c, local_b0, fileName, DAT_0041dd50[i], local_124, 1) != 0) {
          _lclose(hFile);
          wsprintf(msg, "Read Error %d %s\n", i, fileName);
          log(msg);
          DAT_0041dd64.l = i + 1;
          return -1;
        }
      }
      wsprintf(msg, "Load Bmp %d %s\n", i, fileName);
      log(msg);
    }

    _lclose(hFile);
  }

  for (i = 0; i < DAT_0041dd64.l; ++i) {
    _hbmpPrepare(DAT_0041dd50[i], 2, 1);
  }

  return 0;
}


// 004029f3
int SpriteBMPDelete() {
  if (DAT_0041dd50 != 0) {
    freeBmpHandlesDupe(DAT_0041dd50, DAT_0041dd64.l);
    DAT_0041dd64.l = 0;
    DAT_0041dd50 = 0;
  }

  return 0;
}


// 00402a3a
int SpriteCreate() {
  int local_c = 0;
  int local_8 = 0;
  int local_1c = 0;
  int local_18 = 0;
  int local_14 = 0;
  int local_10 = 0;
  int local_2c = 0;
  int local_28 = 0;
  int local_24 = 0;
  int local_20 = 0;
  int i;
  for (i = 0; i < 80; ++i) {
    gSurfFuncRet = _sprCreate(&gSprites[i]);
    gSurfFuncRet = _objSetDestination(gSprites[i], ghSurf);
    gSurfFuncRet = _objSetDrawOrder(gSprites[i], i * 10 + 3000);
    gSprites_pos[i].x = 0;
    gSprites_pos[i].y = 0;
    gSurfFuncRet = _objSetPosition(gSprites[i], gSprites_pos[i]);
    _objSetVisibility(gSprites[i], 0);
    gSprites_rev[i] = 0;
    gSprites_idx[i] = 0xFF;
  }

  return 0;
}


// 00402b76
int SpriteDelete() {
  int i;

  for (i = 0; i < 80; ++i) {
    if (gSprites[i] != 0) {
      _sprDelete(gSprites[i]);
      gSprites[i] = 0;
    }
    gSprites[i] = 0;
    gSprites_rev[i] = 0;
    gSprites_idx[i] = 0xFF;
  }

  return 0;
}


// 00402bfe
int BackgroundBMPCreate() {
  int local_34 = 0;
  int local_30 = 0;
  int local_2c = 0;
  int local_28 = 0;
  int local_24 = 0;
  int local_20 = 0;
  RECT local_18 = { 0, 0, 320, 224 };
  char* local_1c;
  int* local_3c;
  int* local_8;
  int dummy;
  int i;
  gSurfFuncRet = _hbmpCreate(320, 224, 0, &gpScreenBmp);
  _hbmpGetLockedBuffer(gpScreenBmp, (void**)&local_1c, &local_3c);
  local_8 = (int*)local_1c;

  for (i = 0; i < 0x4600; ++i) {
    if ((gbSpecialStageLoaded && gKeepWork.SPEMode != 0) || gbWarpLoaded) {
      *local_8 = 0x10101010;
      ++local_8;
    }
    else {
      *local_8 = 0x30303030;
      ++local_8;
    }
  }

  _hbmpReleaseBuffer(gpScreenBmp);
  _hbmpPrepare(gpScreenBmp, 1, 0);

  return 0;
}


// 00402d12
int BackgroundBMPDelete() {
  if (gpScreenBmp != 0) {
    gSurfFuncRet = _hbmpDelete(gpScreenBmp);
    gpScreenBmp = 0;
  }

  return 0;
}


// 00402d4c
int BackgroundCreate() {
  gSurfFuncRet = _bkgCreate(&gpBackground);
  gSurfFuncRet = _bkgSetData(gpBackground, gpScreenBmp);
  gSurfFuncRet = _objSetDestination(gpBackground, ghSurf);
  gSurfFuncRet = _objSetDrawOrder(gpBackground, 7000);
  gSurfFuncRet = _objSetView(gpBackground, gBackgroundRect);

  return 0;
}


// 00402ddb
int BackgroundDelete() {
  if (gpBackground != 0) {
    gSurfFuncRet = _bkgDelete(gpBackground);
    gpBackground = 0;
  }
  return 0;
}


// 00402e15
int RotateBmpTileCreate() {
  char buffer[80];
  int local_ac;
  int err;
  char msg[80];
  if (gbSpecialStageLoaded) {
    wsprintf(buffer, "SPECIAL\\CG\\SP%1dCG32.CM_", gKeepWork.stagenm + 1);
  }
  else {
    lstrcpy(buffer, "TITLE\\PLANET\\CG\\PLANET.CM_");
  }
  err = extractRotatingTiles(&DAT_0041dd68, &local_ac, buffer);
  if (err != 0) {
    wsprintf(msg, "Cmp Load Error 0x%lx\n", err);
    log(msg);
    return err;
  }
  DAT_0041dd48.l = local_ac;

  return 0;
}


// 00402ec9
int RotateGridCreate() {
  int i;
  POINT point;
  point.x = 0;
  point.y = 128;

  for (i = 0; i < DAT_0041dd48.l * 8; ++i) {
    gSurfFuncRet = _tleCreate(&DAT_00418758[i]);
    gSurfFuncRet = _tleSetData(DAT_00418758[i], DAT_0041dd68[i / 4]);
    gSurfFuncRet = _objApplyEffect(DAT_00418758[i], FX_HORIZ_FLIP, 0, &DAT_00415418[i]);
    gSurfFuncRet = _objApplyEffect(DAT_00418758[i], FX_VERT_FLIP, 0, &DAT_00416db8[i]);
    if (i % 4 == 1) {
      _fxSetActive(DAT_00415418[i], 1);
      _fxSetActive(DAT_00416db8[i], 0);
    }
    else if (i % 4 == 2) {
      _fxSetActive(DAT_00415418[i], 0);
      _fxSetActive(DAT_00416db8[i], 1);
    }
    else if (i % 4 == 3) {
      _fxSetActive(DAT_00415418[i], 1);
      _fxSetActive(DAT_00416db8[i], 1);
    }
    else {
      _fxSetActive(DAT_00415418[i], 0);
      _fxSetActive(DAT_00416db8[i], 0);
    }
  }

  gSurfFuncRet = _grdCreate(gGridRect.right / 32, gGridRect.bottom / 32, 32, 32, &gpGrid);
  gSurfFuncRet = _objSetDrawOrder(gpGrid, 4000);
  gSurfFuncRet = _objSetPosition(gpGrid, point);
  gSurfFuncRet = _objSetView(gpGrid, gGridRect);
  if (gbSpecialStageLoaded) {
    gGridRect.top = 128;
  }
  else if (gbLittlePlanetLoaded) {
     gGridRect.top = 24;
  }
  gSurfFuncRet = _objSetDestRect(gpGrid, gGridRect.left, gGridRect.top, gGridRect.right, gGridRect.bottom);
  gGridRect.top = 0;
  gSurfFuncRet = _objSetDestination(gpGrid, ghSurf);

  return 0;
}


// 004031b7
int RotateGridSetup() {
  unsigned short* pSm_adr0 = gKeepWork.sm_adr0;
  int y;
  myPoint local_8;
  int x;
  uint_union local_c;
  uint_union local_1c;
  int i;

  pSm_adr0 = gKeepWork.sm_adr0;
  for (y = 0; y < gGridRect.bottom / 32; ++y) {
    local_8.y = y;

    for (x = 0; x < gGridRect.right / 32; ++x) {
      local_8.x = x;
      // pSm_adr0: movswl instead of mov
      local_c.w.l = (*pSm_adr0 & 0x7FF) / 4;
      // pSm_adr0: movswl instead of mov
      local_1c.w.l = (*pSm_adr0 & 0xE000);
      ++pSm_adr0;
      // order
      if (local_c.w.l > DAT_0041dd48.w.l) {
        local_c.w.l = 0;
      }
      // local_c.w.l: missing and 0xFFFF
      if (local_c.w.l != 0) {
        // shl instead of lea
        local_c.w.l *= 8;

        switch (local_1c.w.l) {
          case 0:
            break;
          case 0x8000:
            local_c.w.l += 1;
            break;
          case 0xC000:
            local_c.w.l += 2;
            break;
          case 0x4000:
            local_c.w.l += 3;
            break;
          case 0x6000:
            local_c.w.l += 4;
            break;
          case 0xA000:
            local_c.w.l += 6;
            break;
          case 0xE000:
            local_c.w.l += 5;
            break;
          case 0x2000:
            local_c.w.l += 7;
            break;
        }

        gSurfFuncRet = _grdSetData(gpGrid, local_8, DAT_00418758[local_c.l & 0xFFFF]);
      }
      else {
        gSurfFuncRet = _grdClearData(gpGrid, local_8);
      }
    }
  }

  DAT_004320c0 = (RECT*)GlobalLock(GlobalAlloc(GMEM_ZEROINIT, 3584));

  for (i = 0; i < 224; ++i) {
    DAT_004320c0[i].left = 0;
    DAT_004320c0[i].top = i * 65536;
    DAT_004320c0[i].right = 65536;
    DAT_004320c0[i].bottom = 0;
  }

  DAT_0041dd40 = 0;
  DAT_0041dd44 = DAT_004320c0;
  gSurfFuncRet = _objApplyEffect(gpGrid, FX_SMORPH, &DAT_0041dd40, &DAT_004152c8);

  return 0;
}


// 004034d1
int GridBMPCreate() {
  char fileName[80];
  char buffer[80];
  int local_b0;
  int err;
  int i;
  if (gbWarpLoaded) {
    lstrcpy(fileName, "WARP\\TCMPWARP.CM_");
  }
  else if (gbSpecialStageLoaded) {
    if (gKeepWork.SPEMode == 0) {
      wsprintf(fileName, "SPECIAL\\BMP\\FIX\\TCMPS%1d.CM_", gKeepWork.stagenm + 1);
    }
    else {
      lstrcpy(fileName, "SPECIAL\\BMP\\FIX\\SCLEAR.CM_");
    }
  }
  else if (gbLittlePlanetLoaded) {
    lstrcpy(fileName, "TITLE\\PLANET\\CG\\LPBS.CM_");
  }
  else if (gbThanksLoaded) {
    lstrcpy(fileName, "TITLE\\THANKS\\CG\\SCR_A.CM_");
  }
  else {
    (*gpGetRoundStr)(gKeepWork.stageno.w, gKeepWork.time_flag, buffer);
    wsprintf(fileName, "R%c\\%3s\\TCMP%3s.CM_", buffer[0], buffer, buffer);
  }
  wsprintfA(buffer, "Read Tile CMP BMP: %s\n", fileName);
  log(buffer);
  err = extractTiles(&DAT_0041dd60, &local_b0, fileName);
  if (err != 0) {
    wsprintf(buffer, "Cmp Load Error 0x%lx\n", err);
    log(buffer);
    return err;
  }
  DAT_0041a0f8.l = local_b0;
  // order in condition doesn't want to match
  for (i = 0; i < DAT_0041a0f8.l; ++i) {
    _hbmpPrepare(DAT_0041dd60[i], 3, 1);
  }

  return 0;
}


// 0040369e
int GridBMPDelete() {
  if (DAT_0041dd60 != 0) {
    freeBmpHandles(DAT_0041dd60, DAT_0041a0f8.l);
    DAT_0041dd60 = 0;
  }

  return 0;
}


// 004036db
int FUN_004036db() {
  int i;

  for (i = 0; i < 1640; ++i) {
    if (DAT_00418758[i] != 0) {
      gSurfFuncRet = _tleDelete(DAT_00418758[i]);
      DAT_00418758[i] = 0;
    }
  }

  if (DAT_0041dd68 != 0) {
    freeBmpHandles(DAT_0041dd68, DAT_0041dd48.l * 2);
    DAT_0041dd68 = 0;
  }

  return 0;
}


// 00403773
void FUN_00403773(void** param_1, void** param_2, int cnt) {
  int i;

  for (i = 0; i < cnt * 4; ++i) {
    gSurfFuncRet = _tleCreate(&param_1[i]);
    gSurfFuncRet = _tleSetData(param_1[i], param_2[i / 4]);
  }

  for (i = 0; i < cnt * 4; ++i) {
    gSurfFuncRet = _objApplyEffect(param_1[i], FX_HORIZ_FLIP, 0, &DAT_0041dd80[i]);
    gSurfFuncRet = _objApplyEffect(param_1[i], FX_VERT_FLIP, 0, &DAT_00421a00[i]);
    if (i % 4 == 1) {
      _fxSetActive(DAT_0041dd80[i], 1);
      _fxSetActive(DAT_00421a00[i], 0);
    }
    else if (i % 4 == 2) {
      _fxSetActive(DAT_0041dd80[i], 0);
      _fxSetActive(DAT_00421a00[i], 1);
    }
    else if (i % 4 == 3) {
      _fxSetActive(DAT_0041dd80[i], 1);
      _fxSetActive(DAT_00421a00[i], 1);
    }
    else {
      _fxSetActive(DAT_0041dd80[i], 0);
      _fxSetActive(DAT_00421a00[i], 0);
    }
  }

  return;
}


// 00403964
int freeGrid() {
  if (gpGrid != 0);
  if (DAT_004320c0 != 0) {
    GlobalUnlock(GlobalHandle(DAT_004320c0));
    GlobalFree(GlobalHandle(DAT_004320c0));
    DAT_004320c0 = 0;
  }
  if (gpGrid != 0) {
    gSurfFuncRet = _grdDelete(gpGrid);
    gpGrid = 0;
  }

  return 0;
}


// 004039e8
int FUN_004039e8() {
  int i;
  POINT point;
  FUN_00403773(DAT_0041a340, DAT_0041dd60, DAT_0041a0f8.l);

  for (i = 0; i < 8; ++i) {
    if (DAT_00415100[i].right != 0) {
      gSurfFuncRet = _grdCreate(DAT_00415100[i].right / 8, DAT_00415100[i].bottom / 8, 8, 8, &DAT_00430330[i]);
      gSurfFuncRet = _objSetDestination(DAT_00430330[i], ghSurf);
      // xor instead of and
      gSurfFuncRet = _objSetDrawOrder(DAT_00430330[i], DAT_00432190[i]);
      point.x = 0;
      point.y = DAT_004320c8[gKeepWork.stagenm][i].pos * 8;
      // xor instead of and, lea instead of shl
      gSurfFuncRet = _objSetPosition(DAT_00430330[i], point);
      gSurfFuncRet = _objSetView(DAT_00430330[i], DAT_00415100[i]);
    }
  }

  return 0;
}


// 00403b47
int FUN_00403b47() {
  POINT point;
  int i;
  FUN_00403773(DAT_0041a340, DAT_0041dd60, DAT_0041a0f8.l);
  point.x = 0;
  point.y = 0;
  for (i = 0; i < 3; ++i) {
    gSurfFuncRet = _grdCreate(DAT_00415100[i].right / 8, DAT_00415100[i].bottom / 8, 8, 8, &DAT_00430330[i]);
    gSurfFuncRet = _objSetDestination(DAT_00430330[i], ghSurf);
    // xor instead of and
    gSurfFuncRet = _objSetDrawOrder(DAT_00430330[i], DAT_00432188[i]);
    gSurfFuncRet = _objSetPosition(DAT_00430330[i], point);
    gSurfFuncRet = _objSetView(DAT_00430330[i], DAT_00415100[i]);
  }

  return 0;
}


// 00403c78
int GridCreate() {
  if (gbSpecialStageLoaded && gKeepWork.SPEMode == 0) {
    return FUN_004039e8();
  }
  else {
    return FUN_00403b47();
  }
}


// 00403cb6
int GridDelete() {
  int i;

  for (i = 0; i < 8; ++i) {
    if (DAT_00430330[i] != 0) {
      gSurfFuncRet = _grdDelete(DAT_00430330[i]);
      DAT_00430330[i] = 0;
    }
  }

  for (i = 0; i < 3712; ++i) {
    if (DAT_0041a340[i] != 0) {
      gSurfFuncRet = _tleDelete(DAT_0041a340[i]);
      DAT_0041a340[i] = 0;
    }
  }

  return 0;
}


// 00403d74
int initGraphics(HWND hWnd) {
  int local_2c = 0;
  int local_28 = 0;
  int local_24 = 0;
  int local_20 = 0;
  POINT point;
  RECT rect;
  int i;
  point.x = 0;
  point.y = 0;
  rect.left = 0;
  rect.top = 0;
  rect.right = 320;
  rect.bottom = 224;
  gpBackground = 0;
  gpScreenBmp = 0;
  DAT_0041dd6c = 0;
  DAT_0041dd50 = 0;
  DAT_0041dd60 = 0;
  DAT_0041dd68 = 0;
  gpBmpArray = 0;

  for (i = 0; i < 80; ++i) {
    gSprites[i] = 0;
  }

  for (i = 0; i < 8; ++i) {
    DAT_00430330[i] = 0;
  }

  gpGrid = 0;

  for (i = 0; i < 3712; ++i) {
    DAT_0041a340[i] = 0;
  }

  for (i = 0; i < 1640; ++i) {
    DAT_00418758[i] = 0;
  }

  DAT_0041a0f8.l = 0;
  DAT_00415184 = 0;
  DAT_0041dd48.l = 0;
  DAT_0041dd64.l = 0;
  if(gpHscroll == 0) {
    gpHscroll = (int_union*)GlobalLock(GlobalAlloc(GHND, 1024));
  }
  if (gpHscroll != 0) {
    for (i = 0; i < 256; ++i) {
      gpHscroll[i].l = 0;
    }
  }
  gSurfFuncRet = _srfCreate(328, 224, 0, &ghSurf);
  gSurfFuncRet = _srfSetDestWindow(ghSurf, hWnd);
  gSurfFuncRet = _objSetPosition(ghSurf, point);
  gSurfFuncRet = _objSetView(ghSurf, rect);
  gSurfFuncRet = _objApplyEffect(ghSurf, FX_RENDER_CALLBACK, DAT_004328e8[0], &DAT_004152cc);

  return 0;
}


// 00403ffb
int freeGraphics() {
  if (ghSurf != 0) {
    gSurfFuncRet = _srfDelete(ghSurf);
    ghSurf = 0;
  }
  if (gpHscroll != 0) {
    GlobalUnlock(GlobalHandle(gpHscroll));
    GlobalFree(GlobalHandle(gpHscroll));
    gpHscroll = 0;
  }

  return 0;
}


// 00404072
int FUN_00404072(char* path, tileInfo* info) {
  char* buffer;
  char fileName[80];
  HFILE hFile;
  char errMsg[80];
  char* pBuffer;
  int y;
  myPoint local_10;
  int x;
  myPoint local_14;
  myPoint local_c;
  buffer = (char*)GlobalLock(GlobalAlloc(GPTR, 4096));
  lstrcpy(fileName, path);
  lstrcat(fileName, info->pFileName);
  hFile = _lopen(fileName, OF_READ);
  if (hFile == -1) {
    wsprintf(errMsg, "Read Error %s\n", fileName);
    log(errMsg);
    GlobalUnlock(GlobalHandle(buffer));
    GlobalFree(GlobalHandle(buffer));
    return -1;
  }
  // movsbl
  _lread(hFile, buffer, (info->unknown3) * (info->unknown4) * 2);
  _lclose(hFile);
  pBuffer = buffer;

  // movsbl
  for (y = 0; y < (info->unknown4 & 0xFF); ++y) {
    local_10.y = (info->unknown2) + y;

    for (x = 0; x < (info->unknown3); ++x) {
      local_10.x = (info->unknown1) + x;
      local_14.x = *pBuffer & 0x1800;
      local_c.x = *pBuffer & 0x7FF;
      // testl
      if (local_c.x) {
        local_c.x = (info->unknown6) + local_c.x;
        // order
        if ((USHORT)DAT_0041a0f8.w.l <= local_c.x) {
          wsprintf(errMsg, "Out of Tile Data x%d y%d %s %0x\n", x, y, info->pFileName, local_c.x);
          log(errMsg);
        }
        // testl
        else if (local_14.x == 0) {
          local_c.x = local_c.x * 4;
        }
        else if (local_14.x == 0x1800) {
          local_c.x = local_c.x * 4 + 3;
        }
        // testb
        else if (local_14.x & 0x1000) {
          local_c.x = local_c.x * 4 + 2;
        }
        else {
          local_c.x = local_c.x * 4 + 1;
        }
        // extra xor, missing and
        gSurfFuncRet = _grdSetData(DAT_00430330[info->unknown0], local_10, DAT_0041a340[local_c.x]);
      }
      else if (info->unknown8) {
        // extra xor, missing and
        gSurfFuncRet = _grdClearData(DAT_00430330[info->unknown1], local_10);
      }
      else {
        // extra xor, missing and
        gSurfFuncRet = _grdSetData(DAT_00430330[info->unknown0], local_10, DAT_0041a340[info->unknown6 * 4]);
      }
      pBuffer += 2;
    }
  }

  GlobalUnlock(GlobalHandle(buffer));
  GlobalFree(GlobalHandle(buffer));

  return 0;
}


// 004043d1
int SpecialGridSetup() {
  char* pPath = DAT_00432c24;
  tileInfo* pInfo;
  int cnt;
  int i;
  if (gKeepWork.SPEMode) {
    pInfo = (tileInfo*)DAT_004328c8.pArray;
    cnt = DAT_004328c8.cnt;
  }
  else {
    if (gKeepWork.ta_flag) {
      FUN_00404072(pPath, DAT_00432810);
    }
    else {
      FUN_00404072(pPath, DAT_00432810 + 1);
    }
    pInfo = (tileInfo*)DAT_00432888[gKeepWork.stagenm].pArray;
    cnt = DAT_00432888[gKeepWork.stagenm].cnt;
  }

  // order in condition doesn't want to match
  for (i = 0; i < cnt; ++i) {
    if (FUN_00404072(pPath, pInfo) != 0) break;
    ++pInfo;
  }

  return 0;
}


// 004044ac
int FUN_004044ac() {
  char* pPath = DAT_00432c38;
  FUN_00404072(pPath, &DAT_00432868[0]);
  FUN_00404072(pPath, &DAT_00432868[1]);

  return 0;
}


// 004044ee
// render callback, so parameters are unknown
int __stdcall FUN_004044ee(int param_1, int* param_2, unsigned int param_3, void* param_4) {
  int* local_8;
  uint_union local_18;
  uint_union local_14;
  uint_union i;
  int* local_c;
  if (DAT_004320c4 == FALSE) {
    return 0;
  }
  local_8 = param_2;
  local_18.w.l = ((USHORT*)param_4)[39];
  if (((UCHAR*)param_4)[80] != 0) {
    local_14.w.l = 0;
  }
  else if (local_18.w.l >= 223) {
    return 0;
  }
  else {
    local_14.w.l = local_18.w.l;
  }
  OutputDebugString("Render Go\n");

  for (i.w.l = local_14.w.l; i.w.l < 224; ++i.w.l) {
    // this line is incorrect
    local_c = &local_8[param_3 / 4 * i.w.l];
    *local_c += 0x40404040;
    ++local_c;
    *local_c += 0x40404040;
    ++local_c;
    *local_c += 0x40404040;
    ++local_c;
    *local_c += 0x40404040;
    ++local_c;
    *local_c += 0x40404040;
    ++local_c;
    *local_c += 0x40404040;
    ++local_c;
    *local_c += 0x40404040;
    ++local_c;
    *local_c += 0x40404040;
    ++local_c;
    *local_c += 0x40404040;
    ++local_c;
    *local_c += 0x40404040;
    ++local_c;
    *local_c += 0x40404040;
    ++local_c;
    *local_c += 0x40404040;
    ++local_c;
    *local_c += 0x40404040;
    ++local_c;
    *local_c += 0x40404040;
    ++local_c;
    *local_c += 0x40404040;
    ++local_c;
    *local_c += 0x40404040;
    ++local_c;
    *local_c += 0x40404040;
    ++local_c;
    *local_c += 0x40404040;
    ++local_c;
    *local_c += 0x40404040;
    ++local_c;
    *local_c += 0x40404040;
    ++local_c;
    *local_c += 0x40404040;
    ++local_c;
    *local_c += 0x40404040;
    ++local_c;
    *local_c += 0x40404040;
    ++local_c;
    *local_c += 0x40404040;
    ++local_c;
    *local_c += 0x40404040;
    ++local_c;
    *local_c += 0x40404040;
    ++local_c;
    *local_c += 0x40404040;
    ++local_c;
    *local_c += 0x40404040;
    ++local_c;
    *local_c += 0x40404040;
    ++local_c;
    *local_c += 0x40404040;
    ++local_c;
    *local_c += 0x40404040;
    ++local_c;
    *local_c += 0x40404040;
    ++local_c;
    *local_c += 0x40404040;
    ++local_c;
    *local_c += 0x40404040;
    ++local_c;
    *local_c += 0x40404040;
    ++local_c;
    *local_c += 0x40404040;
    ++local_c;
    *local_c += 0x40404040;
    ++local_c;
    *local_c += 0x40404040;
    ++local_c;
    *local_c += 0x40404040;
    ++local_c;
    *local_c += 0x40404040;
    ++local_c;
    *local_c += 0x40404040;
    ++local_c;
    *local_c += 0x40404040;
    ++local_c;
    *local_c += 0x40404040;
    ++local_c;
    *local_c += 0x40404040;
    ++local_c;
    *local_c += 0x40404040;
    ++local_c;
    *local_c += 0x40404040;
    ++local_c;
    *local_c += 0x40404040;
    ++local_c;
    *local_c += 0x40404040;
    ++local_c;
    *local_c += 0x40404040;
    ++local_c;
    *local_c += 0x40404040;
    ++local_c;
    *local_c += 0x40404040;
    ++local_c;
    *local_c += 0x40404040;
    ++local_c;
    *local_c += 0x40404040;
    ++local_c;
    *local_c += 0x40404040;
    ++local_c;
    *local_c += 0x40404040;
    ++local_c;
    *local_c += 0x40404040;
    ++local_c;
    *local_c += 0x40404040;
    ++local_c;
    *local_c += 0x40404040;
    ++local_c;
    *local_c += 0x40404040;
    ++local_c;
    *local_c += 0x40404040;
    ++local_c;
    *local_c += 0x40404040;
    ++local_c;
    *local_c += 0x40404040;
    ++local_c;
    *local_c += 0x40404040;
    ++local_c;
    *local_c += 0x40404040;
    ++local_c;
    *local_c += 0x40404040;
    ++local_c;
    *local_c += 0x40404040;
    ++local_c;
    *local_c += 0x40404040;
    ++local_c;
    *local_c += 0x40404040;
    ++local_c;
    *local_c += 0x40404040;
    ++local_c;
    *local_c += 0x40404040;
    ++local_c;
    *local_c += 0x40404040;
    ++local_c;
    *local_c += 0x40404040;
    ++local_c;
    *local_c += 0x40404040;
    ++local_c;
    *local_c += 0x40404040;
    ++local_c;
    *local_c += 0x40404040;
    ++local_c;
    *local_c += 0x40404040;
    ++local_c;
    *local_c += 0x40404040;
    ++local_c;
    *local_c += 0x40404040;
    ++local_c;
    *local_c += 0x40404040;
    ++local_c;
    *local_c += 0x40404040;
    ++local_c;
    *local_c += 0x40404040;
    ++local_c;
    *local_c += 0x40404040;
    ++local_c;
  }

  return 0;
}


// 004049eb
BOOL EACreate() {
  int i;
  unsigned int byteCnt;
  char msg[80];

  for (i = 0; i < 8; ++i) {
    DAT_00415100[i].left = 0;
    DAT_00415100[i].top = 0;
    DAT_00415100[i].right = 512;
    DAT_00415100[i].bottom = 256;
  }

  if (gbSpecialStageLoaded && gKeepWork.SPEMode == 0) {
    for (i = 0; i < 8; ++i) {
      // xor instead of and, lea instead of shl
      DAT_00415100[i].right = DAT_004320c8[gKeepWork.stagenm][i].width * 8;
      // xor instead of and, lea instead of shl
      DAT_00415100[i].bottom = DAT_004320c8[gKeepWork.stagenm][i].height * 8;
    }
  }
  if (gpHscroll != 0) {
    for (i = 0; i < 256; ++i) {
      gpHscroll[i].l = 0;
    }
  }
  if (gbLittlePlanetLoaded) {
    gGridRect.left = 0;
    gGridRect.top = 0;
    gGridRect.right = 320;
    gGridRect.bottom = 256;
    if (RotateBmpTileCreate() != 0) {
      return 0;
    }
    log("Rotate Bmp/Tile  Create\n");
    if (RotateGridCreate() != 0) {
      return 0;
    }
    log("Rotate Grid      Create\n");
    if (SpriteBMPCreate() != 0) {
      return 0;
    }
    log("Sprite     BMP Create\n");
    if (GridBMPCreate() != 0) {
      return 0;
    }
    log("Grid       BMP Create\n");
    if (SpriteCreate() != 0) {
      return 0;
    }
    log("Sprite         Create\n");
    if (GridCreate() != 0) {
      return 0;
    }
    log("Grid           Create\n");
    if (RotateGridSetup() != 0) {
      return 0;
    }
    log("Rotate Grid      Setup\n");
    log("Create EA End.\n");
  }
  else if (gbThanksLoaded) {
    if (SpriteBMPCreate() != 0) {
      return 0;
    }
    log("Sprite     BMP Create\n");
    if (GridBMPCreate() != 0) {
       return 0;
    }
    log("Grid       BMP Create\n");
    if (SpriteCreate() != 0) {
      return 0;
    }
    log("Sprite         Create\n");
    if (GridCreate() != 0) {
      return 0;
    }
    log("Grid           Create\n");
  }
  else if (gbSpecialStageLoaded) {
    gGridRect.left = 0;
    gGridRect.top = 0;
    gGridRect.right = 4096;
    gGridRect.bottom = 4096;
    if (BackgroundBMPCreate() != 0) {
      return 0;
    }
    log("Background BMP Create\n");
    if (SpriteBMPCreate() != 0) {
      return 0;
    }
    log("Sprite     BMP Create\n");
    if (GridBMPCreate() != 0) {
      return 0;
    }
    log("Grid       BMP Create\n");
    if (BackgroundCreate() != 0) {
      return 0;
    }
    log("Background     Create\n");
    if (SpriteCreate() != 0) {
      return 0;
    }
    log("Sprite         Create\n");
    if (GridCreate() != 0) {
      return 0;
    }
    log("Grid           Create\n");
    if (SpecialGridSetup() != 0) {
      return 0;
    }
    log("Special Grid   Setup\n");
    if (gKeepWork.SPEMode == 0) {
      if (RotateBmpTileCreate() != 0) {
        return 0;
      }
      log("Rotate Bmp/Tile  Create\n");
      if (RotateGridCreate() != 0) {
        return 0;
      }
      log("Rotate Grid      Create\n");
      if (RotateGridSetup() != 0) {
        return 0;
      }
      log("Rotate Grid      Setup\n");
    }
    log("Create EA End.\n");
  }
  else {
    if (BackgroundBMPCreate() != 0) {
      return 0;
    }
    log("Background BMP Create\n");
    if (SpriteBMPCreate() != 0) {
      return 0;
    }
    log("Sprite     BMP Create\n");
    if (GridBMPCreate() != 0) {
      return 0;
    }
    log("Grid       BMP Create\n");
    if (gbWarpLoaded == 0) {
      if (GridPtnchgBMPCreate() != 0) {
        return 0;
      }
      log("GridPtnchg BMP Create\n");
    }
    if (BackgroundCreate() != 0) {
      return 0;
    }
    log("Background     Create\n");
    if (SpriteCreate() != 0) {
      return 0;
    }
    log("Sprite         Create\n");
    if (GridCreate() != 0) {
      return 0;
    }
    log("Grid           Create\n");
    if (gbWarpLoaded) {
      FUN_004044ac();
    }
    log("Create EA End.\n");
  }

  byteCnt = 0;

  for (i = 0; i < DAT_0041dd64.l; ++i) {
    // xor instead of and
    byteCnt += ((UCHAR*)gKeepWork.pSprBmp)[i * 3 + 1] * ((UCHAR*)gKeepWork.pSprBmp)[i * 3];
  }

  wsprintfA(msg, "Sprite %d BMP : %ld K Byte \n", DAT_0041dd64.l, byteCnt / 1024);
  log(msg);
  byteCnt = DAT_0041a0f8.l * 64;
  wsprintf(msg, "Grid   %d Tile: %ld K Byte \n", DAT_0041a0f8, byteCnt / 1024);
  log(msg);
  if (gbSpecialStageLoaded || gbLittlePlanetLoaded) {
    byteCnt = DAT_0041dd48.l * 1024;
    wsprintf(msg, "RotateGrid   %d Stamp: %ld K Byte \n", DAT_0041dd48.l, byteCnt / 1024);
    log(msg);
  }
  if (gKeepWork.stageno.b.h == 2 && !gbSpecialStageLoaded && !gbLittlePlanetLoaded && !gbThanksLoaded && !gbWarpLoaded) {
    OutputDebugString("Render Set\n");
    DAT_004320c4 = TRUE;
  }

  return TRUE;
}


// 00405106
int EADelete() {
  if (DAT_004320c4) {
    DAT_004320c4 = FALSE;
  }
  FUN_004036db();
  freeGrid();
  if (DAT_004320b8 == TRUE) {
    DAT_004320b8 = FALSE;
    if (DAT_00430330[DAT_0041dd54] != 0) {
      gSurfFuncRet = _objRemoveEffect(DAT_00430330[DAT_0041dd54], DAT_00430350[DAT_0041dd54]);
    }
  }
  BackgroundBMPDelete();
  BackgroundDelete();
  SpriteBMPDelete();
  SpriteDelete();
  GridDelete();
  GridBMPDelete();
  FUN_00406cfc();

  return 0;
}


// 004051ab
void FUN_004051ab() {
  if (gpBackground == 0) {
    BackgroundBMPCreate();
    BackgroundCreate();
    gSurfFuncRet = _srfDraw(ghSurf);
    BackgroundBMPDelete();
    BackgroundDelete();
  }
}


// 004051e8
int mapinit(short scrahposiw_h, short vscroll_h, short scrbhposiw_h, short vscroll_l) {
  uint_union i;
  unsigned short posi;
  int effect;
  int_union* pHscrollbuff;
  for (i.w.l = 0; i.w.l < 80; ++i.w.l) {
    gSurfFuncRet = _objSetPosition(gSprites[i.w.l], gSprites_pos[i.w.l]);
  }

  posi = scrahposiw_h & 0x1FF;
  DAT_00415100[1].left = posi;
  DAT_00415100[1].left = posi;
  posi = vscroll_h & 0xFF;
  DAT_00415100[0].top = posi;
  DAT_00415100[1].top = posi;
  posi = scrbhposiw_h & 0x1FF;
  DAT_00415100[2].left = 0;
  posi = vscroll_l & 0xFF;
  DAT_00415100[2].top = posi;

  for (i.w.l = 0; i.w.l < 3; ++i.w.l) {
    gSurfFuncRet = _objSetView(DAT_00430330[i.w.l], DAT_00415100[i.w.l]);
  }

  gSurfFuncRet = _objSetView(gpBackground, gBackgroundRect);
  if (DAT_00433300 == TRUE) {
    if (DAT_004320b8 == TRUE) {
      effect = _objRemoveEffect(DAT_00430330[DAT_0041dd54], DAT_00430350[DAT_0041dd54]);
      if (effect != 0) {
        wsprintf(DAT_00415000, "clr effect %d\n", effect);
        log(DAT_00415000);
      }
    }
    pHscrollbuff = gpHscrollbuff;

    for (i.w.l = 0; i.w.l < 256; ++i.w.l) {
      gpHscroll[i.w.l].l = pHscrollbuff->w.l * -1 & 0x1FF;
      ++pHscrollbuff;
    }

    DAT_004320b8 = TRUE;
    DAT_0041dd54 = 2;
    effect = _objApplyEffect(DAT_00430330[DAT_0041dd54], FX_HORIZ_SHEAR, gpHscroll, &DAT_00430350[DAT_0041dd54]);
    if (effect != 0) {
      wsprintf(DAT_00415000, "set effect %d\n", effect);
      log(DAT_00415000);
    }
  }
  else if (DAT_004320b8 == TRUE) {
    gSurfFuncRet = _objRemoveEffect(DAT_00430330[DAT_0041dd54], DAT_00430350[DAT_0041dd54]);
    DAT_004320b8 = FALSE;
  }
  gSurfFuncRet = _srfDraw(ghSurf);

  return 0;
}


// 004054ee
int FUN_004054ee() {
  uint_union i;
  short* ptv_adr;
  int_union* pHscrollbuff;
  int effect;
  char msg[80];
  uint_union hane1;
  uint_union hane2;
  uint_union dmg1;
  uint_union dmg2;
  makePalette2();

  for (i.w.l = 0; i.w.l < 80; ++i.w.l) {
    gSurfFuncRet = _objSetPosition(gSprites[i.w.l], gSprites_pos[i.w.l]);
  }

  ptv_adr = (short*)gKeepWork.ptv_adr;

  if (DAT_004320c0 != 0) {
    for (i.w.l = 0; i.w.l < 192; ++i.w.l) {
      DAT_004320c0[i.w.l].left = *ptv_adr * 8192;
      DAT_004320c0[i.w.l].top = *++ptv_adr * 8192;
      DAT_004320c0[i.w.l].right = *++ptv_adr / 5 * 128;
      DAT_004320c0[i.w.l].bottom = *++ptv_adr / 5 * 128;
      ++ptv_adr;
    }
  }
  pHscrollbuff = gpHscrollbuff;
  if (gKeepWork.SPEMode == 0) {
    switch (gKeepWork.stagenm) {
      case 0:
      case 4:
      case 5:
        if (gKeepWork.stagenm == 0) {
          DAT_00415100[1].left = gpHscrollbuff[32].w.l * -1 & 0x1FF;
          DAT_00415100[2].left = gpHscrollbuff[96].w.l * -1 & 0x1FF;
        }
        else {
          DAT_00415100[1].left = gpHscrollbuff[32].w.l * -1 & 0x1FF;
        }
        if (DAT_00433300 == TRUE) {
          if (DAT_004320b8 == TRUE) {
            effect = _objRemoveEffect(DAT_00430330[DAT_0041dd54], DAT_00430350[DAT_0041dd54]);
            if (effect != 0) {
              wsprintf(msg, "clr effect %d\n", effect);
              log(msg);
            }
          }
          DAT_004320b8 = TRUE;
          DAT_0041dd54 = 3;
          if (gKeepWork.stagenm == 4) {
            for (i.w.l = 0; i.w.l < 128; ++i.w.l) {
              gpHscroll[i.w.l].l = (short)(pHscrollbuff->w.h + 32) * -1 & 0x1FF;
              ++pHscrollbuff;
            }
          }
          else {
            for (i.w.l = 0; i.w.l < 128; ++i.w.l) {
              gpHscroll[i.w.l].l = pHscrollbuff->w.h * -1 & 0x1FF;
              ++pHscrollbuff;
            }
          }
          effect = _objApplyEffect(DAT_00430330[DAT_0041dd54], FX_HORIZ_SHEAR, gpHscroll, &DAT_00430350[DAT_0041dd54]);
          if (effect != 0) {
            wsprintf(msg, "set effect %d\n", effect);
            log(msg);
          }
        }
        else if (DAT_004320b8 == TRUE) {
          gSurfFuncRet = _objRemoveEffect(DAT_00430330[DAT_0041dd54], DAT_00430350[DAT_0041dd54]);
          DAT_004320b8 = FALSE;
        }
        break;
      case 1:
        DAT_00415100[1].left = (gpHscrollbuff[0].w.h * -1 & 0xFFFF) % DAT_00415100[1].right;
        DAT_00415100[2].left = (gpHscrollbuff[1].w.h * -1 & 0xFFFF) % DAT_00415100[2].right;
        break;
      case 2:
        DAT_00415100[1].left = (gpHscrollbuff[0].w.h * -1 & 0xFFFF) % DAT_00415100[1].right;
        DAT_00415100[2].left = 0;
        DAT_00415100[3].left = (gpHscrollbuff[1].w.h * -1 & 0xFFFF) % DAT_00415100[3].right;
        DAT_00415100[4].left = (gpHscrollbuff[2].w.h * -1 & 0xFFFF) % DAT_00415100[4].right;
        DAT_00415100[5].left = (gpHscrollbuff[3].w.h * -1 & 0xFFFF) % DAT_00415100[5].right;
        DAT_00415100[6].left = (gpHscrollbuff[4].w.h * -1 & 0xFFFF) % DAT_00415100[6].right;
        break;
      case 3:
        DAT_00415100[1].left = (gpHscrollbuff[2].w.h * -1 & 0xFFFF) % DAT_00415100[1].right;
        DAT_00415100[2].left = (gpHscrollbuff[0].w.h * -1 & 0xFFFF) % DAT_00415100[2].right;
        DAT_00415100[3].left = (gpHscrollbuff[1].w.h * -1 & 0xFFFF) % DAT_00415100[3].right;
        break;
      case 6:
        DAT_00415100[3].left = (gpHscrollbuff[0].w.h * -1 & 0xFFFF) % DAT_00415100[3].right;
        DAT_00415100[4].left = (gpHscrollbuff[1].w.h * -1 & 0xFFFF) % DAT_00415100[4].right;
        DAT_00415100[1].left = (gpHscrollbuff[2].w.h * -1 & 0xFFFF) % DAT_00415100[1].right;
        DAT_00415100[2].left = (gpHscrollbuff[3].w.h * -1 & 0xFFFF) % DAT_00415100[2].right;
        break;
      default:
        break;
    }
  }

  for (i.w.l = 0; i.w.l < 8; ++i.w.l) {
    if (DAT_00430330[i.w.l] != 0) {
      gSurfFuncRet = _objSetView(DAT_00430330[i.w.l], DAT_00415100[i.w.l]);
    }
  }

  if (gpGrid != 0) {
    (*gpSpecialblockchg)(&hane1.w.l, &hane2.w.l, &dmg1.w.l, &dmg2.w.l);
    hane1.w.l *= 8;
    hane2.w.l *= 2;
    dmg1.w.l *= 8;
    dmg2.w.l *= 2;

    for (i.w.l = 0; i.w.l < 8; ++i.w.l) {
      if (i.w.l == 4) {
        ++hane2.w.l;
        ++dmg2.w.l;
      }
      gSurfFuncRet = _tleSetData(DAT_00418758[hane1.w.l], DAT_0041dd68[hane2.w.l]);
      gSurfFuncRet = _tleSetData(DAT_00418758[dmg1.w.l], DAT_0041dd68[dmg2.w.l]);
      ++hane1.w.l;
      ++dmg1.w.l;
    }
  }
  gSurfFuncRet = _srfDraw(ghSurf);

  return 0;
}


// 00405c75
int FUN_00405c75() {
  uint_union i;
  short* ptv_adr;
  makePalette2();

  for (i.w.l = 0; i.w.l < 80; ++i.w.l) {
    gSurfFuncRet = _objSetPosition(gSprites[i.w.l], gSprites_pos[i.w.l]);
  }

  ptv_adr = (short*)gKeepWork.ptv_adr;

  if (DAT_004320c0 != 0) {
    for (i.w.l = 0; i.w.l < 224; ++i.w.l) {
      DAT_004320c0[i.w.l].left = *ptv_adr * 8192;
      DAT_004320c0[i.w.l].top = *++ptv_adr * 8192;
      DAT_004320c0[i.w.l].right = *++ptv_adr * 32;
      DAT_004320c0[i.w.l].bottom = *++ptv_adr * 32;
      ++ptv_adr;
    }
  }
  gSurfFuncRet = _srfDraw(ghSurf);

  return 0;
}


// 00405dbd
int FUN_00405dbd() {
  uint_union i;
  makePalette2();

  for (i.w.l = 0; i.w.l < 80; ++i.w.l) {
    gSurfFuncRet = _objSetPosition(gSprites[i.w.l], gSprites_pos[i.w.l]);
  }

  gSurfFuncRet = _srfDraw(ghSurf);

  return 0;
}


// 00405e3e
int getPaletteEntryCount(HPALETTE hPalette) {
  int entryCnt;
  if (hPalette == 0) {
    return 0;
  }
  GetObject(hPalette, sizeof(entryCnt), &entryCnt);
  return entryCnt;
}


// 00405e75
int makePalette() {
  int err = 0;
  HDC hDc;
  int caps;
  int size;
  LOGPALETTE* pLogPalette;
  PALETTEENTRY* lpPe;
  int i;
  HDC hDc2;
  if (gbFullScreen) {
    return 0;
  }
  if (ghPalette != 0) {
    DeleteObject(ghPalette);
  }
  hDc = GetDC(0);
  caps = GetDeviceCaps(hDc, RASTERCAPS);
  if (0) {
    ReleaseDC(0, hDc);
    MessageBox(0, "RC_PALETTE not set in device Caps (not in 256 color mode?)", "Palette", MB_OK);
    return -1;
  }
  size = GetDeviceCaps(hDc, SIZEPALETTE);
  if (size != 256) {
    ReleaseDC(0, hDc);
    MessageBox(0, "GetDeviceCaps reports, must be 256", "Palette", MB_OK);
    return -1;
  }
  ReleaseDC(0, hDc);
  pLogPalette = (LOGPALETTE*)GlobalLock(GlobalAlloc(GHND, 544));
  if (pLogPalette == 0) {
    MessageBox(0, "Could not allocate memory for logical palette", "Palette", MB_OK);
    return -1;
  }
  pLogPalette->palVersion = 0x300;
  pLogPalette->palNumEntries = 134;
  lpPe = pLogPalette->palPalEntry;

  for (i = 0; i < 134; ++i) {
    lpPe->peRed = 0;
    lpPe->peGreen = 0;
    lpPe->peBlue = 0;
    lpPe->peFlags = 1;
    ++lpPe;
  }

  if (err == 0) {
    for (i = 0; i < 2; ++i) {
      ghPalette = CreatePalette(pLogPalette);
      if (ghPalette == 0) {
        MessageBox(0, "CreatePalette failed", "Palette", MB_OK);
      }
      hDc2 = GetDC(ghWnd);
      SelectPalette(hDc2, ghPalette, FALSE);
      RealizePalette(hDc2);
      SelectPalette(hDc2, ghPalette, FALSE);
      ReleaseDC(ghWnd, hDc2);
      if (i == 0) {
        DeleteObject(ghPalette);
      }
    }
  }

  GlobalUnlock(GlobalHandle(pLogPalette));
  GlobalFree(GlobalHandle(pLogPalette));
}


// 004060c8
void makeFullScreenPalette() {
  PALETTEENTRY palette[256];
  int i;
  _devGetPalette(256, 0, palette);
  if (gKeepWork.stageno.b.h == 2) {
    for (i = 0; i < 64; ++i) {
      palette[16 + i].peRed = gpColorwk[i].peBlue;
      palette[16 + i].peGreen = gpColorwk[i].peGreen;
      palette[16 + i].peBlue = gpColorwk[i].peRed;
    }

    for (i = 0; i < 64; ++i) {
      palette[80 + i].peRed = gpColorwk3[i].peBlue;
      palette[80 + i].peGreen = gpColorwk3[i].peGreen;
      palette[80 + i].peBlue = gpColorwk3[i].peRed;
    }
    _devSetPalette(256, 0, palette);
  }
  else {
    for (i = 0; i < 64; ++i) {
      palette[16 + i].peRed = gpColorwk[i].peBlue;
      palette[16 + i].peGreen = gpColorwk[i].peGreen;
      palette[16 + i].peBlue = gpColorwk[i].peRed;
    }
    _devSetPalette(256, 0, palette);
  }

  return;
}


// 00406255
void makePalette2() {
  LOGPALETTE* pLogPalette;
  PALETTEENTRY *lpPe;
  short i;
  HDC hDc;
  if (gbFullScreen == TRUE) {
    makeFullScreenPalette();
    return;
  }
  pLogPalette = (LOGPALETTE*)GlobalLock(GlobalAlloc(GHND, 544));
  if (pLogPalette == 0) {
    MessageBox(0, "Could not allocate memory for logical palette", "Palette", MB_OK);
    return;
  }
  pLogPalette->palVersion = 768;
  pLogPalette->palNumEntries = 134;
  lpPe = pLogPalette->palPalEntry;

  for (i = 0; i < 6; ++i) {
    lpPe->peRed = 0;
    lpPe->peGreen = 0;
    lpPe->peBlue = 0;
    lpPe->peFlags = 1;
    ++lpPe;
  }

  for (i = 6; i < 70; ++i) {
    lpPe->peRed = gpColorwk[i - 6].peRed;
    lpPe->peGreen = gpColorwk[i - 6].peGreen;
    lpPe->peBlue = gpColorwk[i - 6].peBlue;
    lpPe->peFlags = 1;
    ++lpPe;
  }

  if (gKeepWork.stageno.b.h == 2) {
    for (i = 70; i < 134; ++i) {
      lpPe->peRed = gpColorwk3[i - 70].peRed;
      lpPe->peGreen = gpColorwk3[i - 70].peGreen;
      lpPe->peBlue = gpColorwk3[i - 70].peBlue;
      lpPe->peFlags = 1;
      ++lpPe;
    }
  }
  else {
    for (i = 70; i < 134; ++i) {
      lpPe->peRed = gpColorwk[i - 70].peRed;
      lpPe->peGreen = gpColorwk[i - 70].peGreen;
      lpPe->peBlue = gpColorwk[i - 70].peBlue;
      lpPe->peFlags = 1;
      ++lpPe;
    }
  }
  AnimatePalette(ghPalette, 0, 134, pLogPalette->palPalEntry);
  GlobalUnlock(GlobalHandle(pLogPalette));
  GlobalFree(GlobalHandle(pLogPalette));
  hDc = GetDC(ghWnd);
  SelectPalette(hDc, ghPalette, FALSE);
  RealizePalette(hDc);
}


// 004064d5
void fillColorwk(UCHAR value) {
  int i;

  for (i = 0; i < 64; ++i) {
    gpColorwk[i].peBlue = value;
    gpColorwk[i].peGreen = value;
    gpColorwk[i].peRed = value;
  }

  makePalette2();

  return;
}


// 0040653a
int FUN_0040653a(int param_1, int param_2, char* pFileName, void* param_4, UCHAR param_5, int param_6) {
  int local_414 = 0;
  int local_410 = 0;
  int local_42c = 0;
  int local_428 = 0;
  int local_424 = 0;
  int local_420 = 0;
  int local_46c = 0;
  int ret = 0;
  BOOL local_40c = FALSE;
  char buffer[14];
  char buffer2[40];
  char buffer3[1024];
  HGLOBAL local_408;
  char* local_430;
  char* local_434;
  int* local_468;
  int i;
  int j;
  int local_418;
  int dummy;
  HFILE hFile = _lopen(pFileName, OF_READ);
  if (hFile == -1) {
    return -1;
  }
  if (_lread(hFile, buffer, 14) == -1) {
    ret = -1;
  }
  if (_lread(hFile, buffer2, 40) == -1) {
    ret = -1;
  }
  if (_lread(hFile, buffer3, 64) == -1) {
    ret = -1;
  }
  param_1 = ((int*)buffer2)[1];
  param_2 = ((int*)buffer2)[2];
  if (param_1 & 4) {
    param_1 += 4;
    local_40c = TRUE;
  }
  // order of multiplication
  local_408 = GlobalAlloc(GMEM_MOVEABLE, (unsigned int)(param_1 * param_2) >> 1);
  if (local_408 == 0) {
    _lclose(hFile);
    return -1;
  }
  local_430 = (char*)GlobalLock(local_408);
  _hbmpGetLockedBuffer(param_4, (void**)&local_434, &local_468);
  if (_lread(hFile, local_430, param_2 / 2 * param_1) != -1) {
    for (i = param_2 - 1; i >= 0; --i) {
      for (j = 0; j < param_1; ++j) {
        if (local_46c & 1) {
          // movsbl
          local_418 = local_430[param_1 / 2 * i + j / 2] & 0x0F;
        }
        else {
          // movsbl
          local_418 = (local_430[param_1 / 2 * i + j / 2] & 0xF0) >> 4;
        }
        if (!local_40c || param_1 - 4 > j) {
          if (local_418 != 0) {
            local_434[local_46c] = param_5 + local_418;
          }
          else if (param_6 != 0) {
            local_434[local_46c] = 0xFF;
          }
          else {
            local_434[local_46c] = 0;
          }
          ++local_46c;
        }
      }
    }

    if (local_40c) {
      param_1 -= 4;
    }
    local_424 = param_1;
    local_420 = param_2;
    gSurfFuncRet = _hbmpReleaseBuffer(param_4);
  }
  else {
    ret = -1;
  }
  GlobalUnlock(local_408);
  GlobalFree(local_408);
  _lclose(hFile);

  return ret;
}


// 004068c4
void FUN_004068c4(BOOL bFullScreen) {
  RECT rect;
  if (bFullScreen == TRUE) {
    _objApplyEffect(ghSurf, FX_MODEX_DISPLAY, 0, &DAT_0041dd5c);
    _fxSetActive(DAT_0041dd5c, 1);
    GetCursorPos(&gCursorPos);
    GetWindowRect(ghWnd, &rect);
    SetCursorPos((rect.right + rect.left) / 2, (rect.top + rect.bottom) / 2);
    ClipCursor(&rect);
    ShowCursor(FALSE);
    _objPrepare(ghSurf);
    makePalette2();
  }
  else {
    _objRemoveEffect(ghSurf, DAT_0041dd5c);
    makePalette();
    ClipCursor(0);
    ShowCursor(TRUE);
    SetCursorPos(gCursorPos.x, gCursorPos.y);
    makePalette();
  }

  return;
}


// 004069b7
void FUN_004069b7(int param_1, int line, char* param_3) {
  char errMsg[20];
  if (param_1 == -1) {
    wsprintf(errMsg, "EA_FAILED");
  }
  else if (param_1 == -2) {
    wsprintf(errMsg, "EA_OUT_OF_MEMORY");
  }
  else if (param_1 == -3) {
    wsprintf(errMsg, "EA_BAD_POINTER");
  }
  else if (param_1 == -4) {
    wsprintf(errMsg, "EA_OUT_OF_RANGE");
  }
  else if (param_1 == -5) {
    wsprintf(errMsg, "EA_INVALID_SIZE");
  }
  else if (param_1 == -6) {
    wsprintf(errMsg, "EA_BAD_TYPE");
  }
  wsprintf(DAT_00415000, "\nError:\n%s on line %d\n\n%ld = %s\n", errMsg, line, param_1, param_3);
  MessageBox(0, DAT_00415000, "EA Sample Error", MB_ICONWARNING | MB_TASKMODAL);
}


// 00406ac0
int GridPtnchgBMPCreate() {
  int stage;
  char buffer[80];
  char path[80];
  int tile;
  int err;
  if (gbSpecialStageLoaded) {
    return 0;
  }
  stage = gKeepWork.stageno.b.l * 4;
  if (gKeepWork.time_flag == 0) {
    ++stage;
  }
  else if (gKeepWork.time_flag == 2) {
    stage += 2;
    if (gKeepWork.generate_flag == 0) {
      ++stage;
    }
  }
  // xor instead of and
  if ((0x8000 >> stage & DAT_004328f8[gKeepWork.stageno.b.h]) == 0) {
    return 0;
  }
  (*gpGetRoundStr)(gKeepWork.stageno.w, gKeepWork.time_flag, buffer);
  wsprintf(path, "R%c\\%3s\\TCHG%3s.CM_", buffer[0], buffer, buffer);
  wsprintf(buffer, "Read Tile Pattern Change CMP BMP: %s\n", path);
  log(buffer);
  err = extractTiles(&gpBmpArray, &tile, path);
  if (err != 0) {
    wsprintf(buffer, "Cmp Load Error 0x%lx\n", err);
    log(buffer);
    return err;
  }
  DAT_00415184 = tile;
  wsprintf(buffer, "%X Tile\n", tile);
  log(buffer);

  return 0;
}


// 00406c58
void __stdcall ChangeTileBmp(int TileStart, int BmpNo) {
  gSurfFuncRet = _tleSetData(DAT_0041a340[TileStart * 4], gpBmpArray[BmpNo]);
  gSurfFuncRet = _tleSetData(DAT_0041a340[TileStart * 4 + 1], gpBmpArray[BmpNo]);
  gSurfFuncRet = _tleSetData(DAT_0041a340[TileStart * 4 + 2], gpBmpArray[BmpNo]);
  gSurfFuncRet = _tleSetData(DAT_0041a340[TileStart * 4 + 3], gpBmpArray[BmpNo]);
}


// 00406cfc
int FUN_00406cfc() {
  if (gpBmpArray != 0) {
    freeBmpHandles(gpBmpArray, DAT_00415184);
    gpBmpArray = 0;
  }

  return 0;
}


// 00406d39
void FUN_00406d39() {
  int entryCnt;
  HGLOBAL hMemory;
  PALETTEENTRY* lpPe;
  int i;
  HDC hDc;
  HPALETTE hPalette;
  ResizePalette(ghPalette, 134);
  if (gbFullScreen == TRUE) {
    makeFullScreenPalette();
    return;
  }
  if (ghPalette == 0) {
    return;
  }
  entryCnt = getPaletteEntryCount(ghPalette);
  if (entryCnt == 0) {
    return;
  }
  hMemory = GlobalAlloc(GHND, entryCnt * 4);
  if (hMemory == 0) {
    return;
  }
  lpPe = (PALETTEENTRY*)GlobalLock(hMemory);
  if (gKeepWork.stageno.b.h == 2) {
    for (i = 0; i < 64; ++i) {
      lpPe[6 + i].peBlue = gpColorwk[i].peBlue;
      lpPe[6 + i].peGreen = gpColorwk[i].peGreen;
      lpPe[6 + i].peRed = gpColorwk[i].peRed;
      lpPe[6 + i].peFlags = gpColorwk[i].peFlags;
    }
    for (i = 0; i < 64; ++i) {
      lpPe[70 + i].peBlue = gpColorwk3[i].peBlue;
      lpPe[70 + i].peGreen = gpColorwk3[i].peGreen;
      lpPe[70 + i].peRed = gpColorwk3[i].peRed;
      lpPe[70 + i].peFlags = gpColorwk3[i].peFlags;
    }
  }
  else {
    for (i = 0; i < 64; ++i) {
      lpPe[6 + i].peBlue = gpColorwk[i].peBlue;
      lpPe[6 + i].peGreen = gpColorwk[i].peGreen;
      lpPe[6 + i].peRed = gpColorwk[i].peRed;
      lpPe[6 + i].peFlags = gpColorwk[i].peFlags;
    }
    for (i = 0; i < 64; ++i) {
      lpPe[70 + i].peBlue = gpColorwk[i].peBlue;
      lpPe[70 + i].peGreen = gpColorwk[i].peGreen;
      lpPe[70 + i].peRed = gpColorwk[i].peRed;
      lpPe[70 + i].peFlags = gpColorwk[i].peFlags;
    }
  }
  hDc = GetDC(ghWnd);
  hPalette = SelectPalette(hDc, ghPalette, FALSE);
  AnimatePalette(ghPalette, 0, 140, lpPe);
  ReleaseDC(ghWnd, hDc);
  GlobalUnlock(hMemory);
  GlobalFree(hMemory);
  ResizePalette(ghPalette, 128);

  return;
}
