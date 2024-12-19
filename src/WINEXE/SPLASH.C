#include <windows.h>
#include "DINO2D.H"
#include "DMIX.H"
#include "GRAPHICS.H"

/* 00425b14 */ void* DAT_00425b14;
/* 00425b18 */ int DAT_00425b18;
/* 00425b1c */ void* DAT_00425b1c;
/* 004320bc */ void* ghSurf;
/* 0043327c */ PALETTEENTRY* gpColorwk = 0;
/* 00433e48 */ RECT DAT_00433e48 = { 0, 0, 320, 224};
/* 00433e58 */ PALETTEENTRY loadingPalette[16] = {
  {  32,  32,  32, 1 },
  {   0, 224, 224, 1 },
  { 224, 224,   0, 1 },
  {  32,   0, 224, 1 },
  { 128,  96,   0, 1 },
  { 192, 160,   0, 1 },
  {   0, 224,   0, 1 },
  {   0, 128,   0, 1 },
  { 224,  32,   0, 1 },
  { 128,  32,   0, 1 },
  { 224, 224, 224, 1 },
  { 192, 160, 224, 1 },
  { 128,  64, 160, 1 },
  { 160, 224, 224, 1 },
  { 224,  32, 160, 1 },
  { 128, 224, 224, 1 }
};
/* 00433e98 */ PALETTEENTRY comming3Palette[16] = {
  {   0,   0,   0, 1 },
  {   0,  96,   0, 1 },
  {  32,  32, 192, 1 },
  {  64,  64, 224, 1 },
  {  96,  96, 224, 1 },
  { 128, 128, 224, 1 },
  { 224, 224, 224, 1 },
  { 160, 160, 160, 1 },
  { 128, 128, 128, 1 },
  {  64,  64,  64, 1 },
  { 224, 160, 128, 1 },
  { 160,  96,  64, 1 },
  { 224,   0,   0, 1 },
  { 128,   0,   0, 1 },
  {  64,   0,   0, 1 },
  { 224, 224,   0, 1 }
};


// 0040f250
int drawLoading() {
  int local_30 = 0;
  int local_2c = 0;
  int local_28 = 0;
  int local_24 = 0;
  RECT rect;
  POINT point;
  PALETTEENTRY* pColorwk;
  short i;
  rect.left = 0;
  rect.top = 0;
  rect.right = 320;
  rect.bottom = 224;
  point.x = 0;
  point.y = 0;
  makePalette();
  DAT_00425b18 = _hbmpCreate(320, 224, 0, &DAT_00425b1c);
  DAT_00425b18 = _hbmpLoad(DAT_00425b1c, point, "loading.bmp", rect);
  DAT_00425b18 = _bkgCreate(&DAT_00425b14);
  DAT_00425b18 = _bkgSetData(DAT_00425b14, DAT_00425b1c);
  DAT_00425b18 = _objSetDestination(DAT_00425b14, ghSurf);
  DAT_00425b18 = _objSetDrawOrder(DAT_00425b14, 7000);
  DAT_00425b18 = _objSetView(DAT_00425b14, DAT_00433e48);
  DAT_00425b18 = _srfDraw(ghSurf);
  pColorwk = gpColorwk;

  for (i = 0; i < 16; ++i) {
    *pColorwk = loadingPalette[i];
    ++pColorwk;
  }

  makePalette2();

  return 0;
}


// 0040f3ca
int drawComming3() {
  int local_30 = 0;
  int local_2c = 0;
  int local_28 = 0;
  int local_24 = 0;
  RECT rect;
  POINT point;
  PALETTEENTRY* pColorwk;
  short i;
  rect.left = 0;
  rect.top = 0;
  rect.right = 320;
  rect.bottom = 224;
  point.x = 0;
  point.y = 0;
  makePalette();
  DAT_00425b18 = _hbmpCreate(320, 224, 0, &DAT_00425b1c);
  DAT_00425b18 = _hbmpLoad(DAT_00425b1c, point, "comming3.bmp", rect);
  DAT_00425b18 = _bkgCreate(&DAT_00425b14);
  DAT_00425b18 = _bkgSetData(DAT_00425b14, DAT_00425b1c);
  DAT_00425b18 = _objSetDestination(DAT_00425b14, ghSurf);
  DAT_00425b18 = _objSetDrawOrder(DAT_00425b14, 7000);
  DAT_00425b18 = _objSetView(DAT_00425b14, DAT_00433e48);
  DAT_00425b18 = _srfDraw(ghSurf);
  pColorwk = gpColorwk;

  for (i = 0; i < 16; ++i) {
    *pColorwk = comming3Palette[i];
    ++pColorwk;
  }

  makePalette2();

  return 0;
}


/* 0040f544 */
void deleteSplash() {
  DAT_00425b18 = _hbmpDelete(DAT_00425b1c);
  _bkgDelete(DAT_00425b14);
}
