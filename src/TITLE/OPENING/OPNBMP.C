#include "..\..\TYPES.H"
#include "..\COMMON\HMX_TYPES.H"

char* SprCmpFileName = "TITLE\\BMP\\OPENINGS.CM_";
char* TileCmpFileName = "TITLE\\BMP\\OPENINGT.CM_";
static unsigned int hSpr[34];
static unsigned int hGrid[10];
static unsigned int* hBmpBack[1];
static unsigned int hTileBack[1];
static unsigned int hGridBack;
static unsigned int* hBmpMizu[320];
static unsigned int hTileMizu[320];
static unsigned int hGridMizu;
static unsigned int* hBmpKumo[512];
static unsigned int hTileKumo[512];
static unsigned int hGridKumo;
unsigned short NUM_BMP = 34;
unsigned short NUM_GRIDBMP = 3;
sprite_bmp infoSprtBmp[34] = {
  { 160,  72, {   0,  88 }, 42, 16, 0,  7, &hSpr[0] },
  { 160,  72, { 160,  88 }, 42, 16, 0,  7, &hSpr[1] },
  { 230,  80, {  45, 127 }, 34, 32, 0,  7, &hSpr[2] },
  { 152,   8, {  36, 208 }, 33, 32, 0,  7, &hSpr[3] },
  { 130,  76, {  30,  32 }, 38, 48, 0,  7, &hSpr[4] },
  { 130,  76, { 160,  32 }, 39, 48, 0,  7, &hSpr[5] },
  { 130,  76, {  30, 108 }, 38, 48, 0,  7, &hSpr[6] },
  { 130,  76, { 160, 108 }, 39, 48, 0,  7, &hSpr[7] },
  {  30,  64, { 161,  58 }, 10, 64, 0,  8, &hSpr[8] },
  {  40,  64, { 161,  58 }, 10, 64, 0,  9, &hSpr[9] },
  {  50,  64, { 161,  58 }, 10, 64, 0, 10, &hSpr[10] },
  {  60,  64, { 161,  58 }, 10, 64, 0, 11, &hSpr[11] },
  {  60,  48, { 113,  40 },  3, 64, 0, 12, &hSpr[12] },
  {  30,  24, { 154,  80 }, 11, 64, 0, 12, &hSpr[13] },
  { 120, 104, { 240, -32 }, 46, 64, 0,  7, &hSpr[14] },
  { 160,  88, {   0,   0 }, 45, 16, 0,  0, &hSpr[15] },
  { 160,  88, { 160,   0 }, 45, 16, 0,  0, &hSpr[16] },
  {  16,   8, { 243, 131 }, 21, 32, 0,  7, &hSpr[17] },
  {  96,  32, { 112,  96 }, 10, 16, 0,  1, &hSpr[18] },
  {  90, 112, { 114,  24 }, 36, 64, 0,  2, &hSpr[19] },
  { 100, 120, { 114,  24 }, 36, 64, 0,  3, &hSpr[19] },
  {  90, 120, { 114,  16 }, 36, 64, 0,  4, &hSpr[19] },
  { 100, 120, { 114,  16 }, 36, 64, 0,  5, &hSpr[19] },
  { 100, 120, { 113,  16 }, 36, 64, 0,  7, &hSpr[19] },
  { 100,  16, { 110, 180 }, 20, 32, 0, 13, &hSpr[20] },
  {  90,  16, { 115, 180 }, 20, 32, 0, 14, &hSpr[20] },
  {  80,  16, { 120, 180 }, 20, 32, 0, 15, &hSpr[20] },
  { 110,  16, { 107, 180 }, 20, 32, 0, 16, &hSpr[20] },
  { 110,  16, { 105, 180 }, 20, 32, 0, 17, &hSpr[20] },
  { 100,  16, { 110, 180 }, 20, 32, 0, 18, &hSpr[20] },
  { 110,  16, { 109, 180 }, 20, 32, 0, 19, &hSpr[20] },
  {  40,  16, { 145, 180 }, 20, 32, 0, 20, &hSpr[20] },
  {  16,   8, {  90, 181 }, 21, 32, 0, 21, &hSpr[21] },
  {  16,   8, { 210, 181 }, 21, 32, 0, 22, &hSpr[22] }
};
grid_bmp infoGridBmp[3] = {
  {   1, 8, 8, { 0,   0 }, 53, 32, hBmpBack, hTileBack, &hGridBack },
  { 320, 8, 8, { 0, 160 }, 52, 16, hBmpMizu, hTileMizu, &hGridMizu },
  { 512, 8, 8, { 0,   0 }, 45, 16, hBmpKumo, hTileKumo, &hGridKumo }
};
