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
int SpriteBMPCreate();
int SpriteBMPDelete();
int SpriteCreate();
int SpriteDelete();
int BackgroundBMPCreate();
int BackgroundBMPDelete();
int BackgroundCreate();
int BackgroundDelete();
int RotateBmpTileCreate();
int RotateGridCreate();
int RotateGridSetup();
int GridBMPCreate();
int GridBMPDelete();
int FUN_004036db();
void FUN_00403773(void** param_1, void** param_2, int cnt);
int freeGrid();
int FUN_004039e8();
int FUN_00403b47();
int GridCreate();
int GridDelete();
int initGraphics(HWND hWnd);
int freeGraphics();
int FUN_00404072(char* path, tileInfo* info);
int SpecialGridSetup();
int FUN_004044ac();
int __stdcall FUN_004044ee(int param_1, int* param_2, unsigned int param_3, void* param_4);
BOOL EACreate();
int EADelete();
void FUN_004051ab();
int mapinit(short scrahposiw_h, short vscroll_h, short scrbhposiw_h, short vscroll_l);
int FUN_004054ee();
int FUN_00405c75();
int FUN_00405dbd();
int getPaletteEntryCount(HPALETTE hPalette);
int makePalette();
void makeFullScreenPalette();
void makePalette2();
void fillColorwk(UCHAR value);
int FUN_0040653a(int param_1, int param_2, char* pFileName, void* param_4, UCHAR param_5, int param_6);
void FUN_004068c4(BOOL bFullScreen);
void FUN_004069b7(int param_1, int line, char* param_3);
int GridPtnchgBMPCreate();
void __stdcall ChangeTileBmp(int TileStart, int BmpNo);
int FUN_00406cfc();
void FUN_00406d39();

#endif
