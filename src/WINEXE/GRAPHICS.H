#ifndef GRAPHICS_H
#define GRAPHICS_H

#include <windows.h>

typedef struct tileInfo {
  char unknown0;
  char unknown1;
  char unknown2;
  char unknown3;
  char unknown4;
  char unknown5;
  short unknown6;
  char unknown8;
  char* pFileName;
}
tileInfo;

void __stdcall EAsprset(short x, short y, USHORT index, USHORT linkdata, USHORT reverse);
void __stdcall SetGrid(int base, int x, int y, int block, int frip);
int toInteger(char** ppNumber);
int FUN_00402136(HFILE hFile, char* pOutput, int* pNumber);
int SpriteBMPCreate(void);
int SpriteBMPDelete(void);
int SpriteCreate(void);
int SpriteDelete(void);
int BackgroundBMPCreate(void);
int BackgroundBMPDelete(void);
int BackgroundCreate(void);
int BackgroundDelete(void);
int RotateBmpTileCreate(void);
int RotateGridCreate(void);
int RotateGridSetup(void);
int GridBMPCreate(void);
int GridBMPDelete(void);
int FUN_004036db(void);
void FUN_00403773(void** param_1, void** param_2, int cnt);
int freeGrid(void);
int FUN_004039e8(void);
int FUN_00403b47(void);
int GridCreate(void);
int GridDelete(void);
int initGraphics(HWND hWnd);
int freeGraphics(void);
int FUN_00404072(char* path, tileInfo* info);
int SpecialGridSetup(void);
int FUN_004044ac(void);
int __stdcall FUN_004044ee(int param_1, int* param_2, unsigned int param_3, void* param_4);
BOOL EACreate(void);
int EADelete(void);
void FUN_004051ab(void);
int mapinit(short scrahposiw_h, short vscroll_h, short scrbhposiw_h, short vscroll_l);
int FUN_004054ee(void);
int FUN_00405c75(void);
int FUN_00405dbd(void);
int getPaletteEntryCount(HPALETTE hPalette);
int makePalette(void);
void makeFullScreenPalette(void);
void makePalette2(void);
void fillColorwk(UCHAR value);
int FUN_0040653a(int param_1, int param_2, char* pFileName, void* param_4, UCHAR param_5, int param_6);
void FUN_004068c4(BOOL bFullScreen);
void FUN_004069b7(int param_1, int line, char* param_3);
int GridPtnchgBMPCreate(void);
void __stdcall ChangeTileBmp(int TileStart, int BmpNo);
int FUN_00406cfc(void);
void FUN_00406d39(void);

#endif
