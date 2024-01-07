#include "..\..\TYPES.H"
#include "..\COMMON\HMX_TYPES.H"

char* SprCmpFileName = "TITLE\\BMP\\BESTTIME.CM_";
char* TileCmpFileName = "TITLE\\BMP\\sndtestt.CM_";
sprite_bmp infoSprtBmp[100];
unsigned short NUM_BMP = 100;
grid_bmp infoGridBmp[1] = {
  { 1, 8, 8, { 0, 0 }, 60, 16, 0, 0, 0 }
};
unsigned short NUM_GRIDBMP = 1;
static unsigned int hGridBack;
static unsigned int hTileBack[1];
static unsigned int* hBmpBack[1];
static unsigned int hSprBG[24];
static unsigned int hSprTitle[22];
static unsigned int hSprDummy;
