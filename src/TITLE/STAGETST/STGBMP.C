#include "..\..\TYPES.H"
#include "..\COMMON\HMX_TYPES.H"

char* SprCmpFileName = "TITLE\\BMP\\STAGES.CM_";
char* TileCmpFileName = "TITLE\\BMP\\sndtestt.CM_";
static unsigned int hSprBG[16];
static unsigned int hSprTitle[11];
static unsigned int hSprDummy;
sprite_bmp infoSprtBmp[64] = {
  {  8, 16, 120,  40, 35, 16, 0, 0, &hSprTitle[0] },
  {  8, 16, 128,  40, 35, 16, 0, 0, &hSprTitle[1] },
  {  8, 16, 136,  40, 35, 16, 0, 0, &hSprTitle[2] },
  {  8, 16, 144,  40, 35, 16, 0, 0, &hSprTitle[3] },
  {  8, 16, 152,  40, 35, 16, 0, 0, &hSprTitle[4] },
  {  8, 16, 168,  40, 35, 16, 0, 0, &hSprTitle[5] },
  {  8, 16, 176,  40, 35, 16, 0, 0, &hSprTitle[6] },
  {  8, 16, 184,  40, 35, 16, 0, 0, &hSprTitle[7] },
  {  8, 16, 192,  40, 35, 16, 0, 0, &hSprTitle[8] },
  {  8, 16, 200,  40, 35, 16, 0, 0, &hSprTitle[9] },
  {  8, 16, 208,  40, 35, 16, 0, 0, &hSprTitle[10] },
  {  8, 16,   0,   0, 35, 48, 0, 0, &hSprDummy },
  {  8, 16,   0,   0, 35, 48, 0, 0, &hSprDummy },
  {  8, 16,   0,   0, 35, 48, 0, 0, &hSprDummy },
  {  8, 16,   0,   0, 35, 48, 0, 0, &hSprDummy },
  {  8, 16,   0,   0, 35, 48, 0, 0, &hSprDummy },
  {  8, 16,   0,   0, 35, 48, 0, 0, &hSprDummy },
  {  8, 16,   0,   0, 35, 48, 0, 0, &hSprDummy },
  {  8, 16,   0,   0, 35, 48, 0, 0, &hSprDummy },
  {  8, 16,   0,   0, 35, 48, 0, 0, &hSprDummy },
  {  8, 16,   0,   0, 35, 48, 0, 0, &hSprDummy },
  {  8, 16,   0,   0, 35, 48, 0, 0, &hSprDummy },
  {  8, 16,   0,   0, 35, 48, 0, 0, &hSprDummy },
  {  8, 16,   0,   0, 35, 48, 0, 0, &hSprDummy },
  {  8, 16,   0,   0, 35, 48, 0, 0, &hSprDummy },
  {  8, 16,   0,   0, 35, 48, 0, 0, &hSprDummy },
  {  8, 16,   0,   0, 35, 48, 0, 0, &hSprDummy },
  {  8, 16,   0,   0, 35, 48, 0, 0, &hSprDummy },
  {  8, 16,   0,   0, 35, 48, 0, 0, &hSprDummy },
  {  8, 16,   0,   0, 35, 48, 0, 0, &hSprDummy },
  {  8, 16,   0,   0, 35, 48, 0, 0, &hSprDummy },
  {  8, 16,   0,   0, 35, 48, 0, 0, &hSprDummy },
  {  8, 16,   0,   0, 35, 48, 0, 0, &hSprDummy },
  {  8, 16,   0,   0, 35, 48, 0, 0, &hSprDummy },
  {  8, 16,   0,   0, 35, 48, 0, 0, &hSprDummy },
  {  8, 16,   0,   0, 35, 48, 0, 0, &hSprDummy },
  {  8, 16,   0,   0, 35, 48, 0, 0, &hSprDummy },
  {  8, 16,   0,   0, 35, 48, 0, 0, &hSprDummy },
  {  8, 16,   0,   0, 35, 48, 0, 0, &hSprDummy },
  {  8, 16,   0,   0, 35, 48, 0, 0, &hSprDummy },
  {  8, 16,   0,   0, 35, 48, 0, 0, &hSprDummy },
  {  8, 16,   0,   0, 35, 48, 0, 0, &hSprDummy },
  {  8, 16,   0,   0, 35, 48, 0, 0, &hSprDummy },
  {  8, 16,   0,   0, 35, 48, 0, 0, &hSprDummy },
  {  8, 16,   0,   0, 35, 48, 0, 0, &hSprDummy },
  {  8, 16,   0,   0, 35, 48, 0, 0, &hSprDummy },
  {  8, 16,   0,   0, 35, 48, 0, 0, &hSprDummy },
  {  8, 16,   0,   0, 35, 48, 0, 0, &hSprDummy },
  { 80, 56,   0, 168, 50, 64, 0, 0, &hSprBG[0] },
  { 80, 56,  80, 168, 50, 64, 0, 0, &hSprBG[1] },
  { 80, 56, 160, 168, 50, 64, 0, 0, &hSprBG[2] },
  { 80, 56, 240, 168, 50, 64, 0, 0, &hSprBG[3] },
  { 80, 56,   0, 112, 50, 64, 0, 0, &hSprBG[4] },
  { 80, 56,  80, 112, 50, 64, 0, 0, &hSprBG[5] },
  { 80, 56, 160, 112, 50, 64, 0, 0, &hSprBG[6] },
  { 80, 56, 240, 112, 50, 64, 0, 0, &hSprBG[7] },
  { 80, 56,   0,  56, 50, 64, 0, 0, &hSprBG[8] },
  { 80, 56,  80,  56, 50, 64, 0, 0, &hSprBG[9] },
  { 80, 56, 160,  56, 50, 64, 0, 0, &hSprBG[10] },
  { 80, 56, 240,  56, 50, 64, 0, 0, &hSprBG[11] },
  { 80, 56,   0,   0, 50, 64, 0, 0, &hSprBG[12] },
  { 80, 56,  80,   0, 50, 64, 0, 0, &hSprBG[13] },
  { 80, 56, 160,   0, 50, 64, 0, 0, &hSprBG[14] },
  { 80, 56, 240,   0, 50, 64, 0, 0, &hSprBG[15] }
};
static unsigned int hGridBack;
static unsigned int hTileBack[1];
static unsigned int* hBmpBack[1];
grid_bmp infoGridBmp[1] = {
  { 1, 8, 8, { 0, 0 }, 60, 16, hBmpBack, hTileBack, &hGridBack }
};
unsigned short NUM_BMP = 64;
unsigned short NUM_GRIDBMP = 1;
