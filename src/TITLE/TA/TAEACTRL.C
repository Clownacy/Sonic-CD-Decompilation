#include "..\..\TYPES.H"
#include "..\COMMON\SCORE_DATA_TYPES.H"
#include "..\COMMON\HMX_TYPES.H"
#include "..\COMMON\LD_TYPES.H"
#include "TA_TYPES.H"
#include "TAEACTRL.H"
#include "..\..\IMPFUNCS.H"
#include "TACOLOR.H"

static int TileCnt;
static int SprBmpCnt;
static grid_rect BkgRect = { 0, 0, 320, 224 };
static grid_rect GridRectPic = { 0, 0, 128, 144 };
static POINT ptSprLocPic[2];
static unsigned char TAGridSize[8][3];
static map_info MapInfo1[3] = {
  { 1, 18, 0, 22, 28,   0, 0, "TIME_BGC.BIN" },
  { 3,  0, 0, 18, 28,  93, 0, "TIME_BGL.BIN" },
  { 3, 40, 0, 18, 28, 140, 0, "TIME_BGR.BIN" }
};
static map_infos MapInfoTbl[1] = {
  { MapInfo1, 3 }
};
static unsigned short MapZoneMenuNormal[13] = { 108, 109, 110, 111, 112, 108, 115, 109, 110, 112, 108, 113, 114 };
static unsigned short MapZoneMenuSP[13] = { 108, 108, 108, 113, 114, 108, 109, 110, 111, 112, 108, 108, 108 };
static unsigned short MapZoneMenuSpace = 108;
static unsigned short MapRoundSpace[2][1] = {
  { 6 },
  { 11 }
};
static unsigned short MapExitSpace[2][1] = {
  { 108 },
  { 11 }
};
static unsigned short MapRound[2][8][2][18] = {
  {
    {
      { 108, 108, 109, 108, 108, 110, 108, 108, 111, 108, 108, 112, 108, 108, 108, 108, 108, 108 },
      {  11,  11,  11,  11,  11,  11,  11,  11,  11,  11,  11,  11,  11,  11,  11,  11,  11,  11 }
    },
    {
      {   1,   2,   3,   4,   5,   6,   6,   6,   6,   6,   6,   6,   6,   6,   6,   6,   6,   6 },
      {   7,   8,   9,  10,  11,  11,  11,  11,  11,  11,  11,  11,  11,  11,  11,  11,  11,  11 }
    },
    {
      {  12,  13,  14,  15,  16,   6,   6,   6,   6,   6,   6,   6,   6,   6,   6,   6,   6,   6 },
      {  17,  18,  19,  20,  11,  11,  11,  11,  11,  11,  11,  11,  11,  11,  11,  11,  11,  11 }
    },
    {
      {  21,  22,  23,   6,   6,   6,   6,   6,   6,   6,   6,   6,   6,   6,   6,   6,   6,   6 },
      {  24,  25,  26,  27,  28,  11,  11,  11,  11,  11,  11,  11,  11,  11,  11,  11,  11,  11 }
    },
    {
      {  29,  30,  31,  32,   6,   6,   6,   6,   6,   6,   6,   6,   6,   6,   6,   6,   6,   6 },
      {  33,  34,  35,  36,  37,  38,  11,  11,  11,  11,  11,  11,  11,  11,  11,  11,  11,  11 }
    },
    {
      {  39,  40,  41,  42,   6,   6,   6,   6,   6,   6,   6,   6,   6,   6,   6,   6,   6,   6 },
      {  33,  43,  44,  45,  46,  47,  48,  11,  11,  11,  11,  11,  11,  11,  11,  11,  11,  11 }
    },
    {
      {  49,  50,  51,  52,  53,   6,   6,   6,   6,   6,   6,   6,   6,   6,   6,   6,   6,   6 },
      {  54,  55,  56,  57,  58,  59,  11,  11,  11,  11,  11,  11,  11,  11,  11,  11,  11,  11 }
    },
    {
      {  60,  61,  62,  63,  64,   6,   6,   6,   6,   6,   6,   6,   6,   6,   6,   6,   6,   6 },
      {  33,  65,  66,  67,  68,  69,  11,  11,  11,  11,  11,  11,  11,  11,  11,  11,  11,  11 }
    }
  },
  {
    {
      { 108, 108, 108, 108, 108, 108, 109, 108, 108, 110, 108, 108, 111, 108, 108, 112, 108, 108 },
      {  11,  11,  11,  11,  11,  11,  11,  11,  11,  11,  11,  11,  11,  11,  11,  11,  11,  11 }
    },
    {
      {   6,   6,   6,   6,   6,   6,   6,   6,   6,   6,   6,  70,  71,  72,  73,  74,  75,  76 },
      {  11,  11,  11,  11,  11,  11,  11,  11,  11,  11,  11,  77,  78,  79,  80,  81,  82,  83 }
    },
    {
      {   6,   6,   6,   6,   6,   6,   6,   6,   6,   6,   6,  70,  71,  72,  73,  74,  84,  85 },
      {  11,  11,  11,  11,  11,  11,  11,  11,  11,  11,  11,  77,  78,  79,  80,  81,  86,  87 }
    },
    {
      {   6,   6,   6,   6,   6,   6,   6,   6,   6,   6,   6,  70,  71,  72,  73,  74,  88,  89 },
      {  11,  11,  11,  11,  11,  11,  11,  11,  11,  11,  11,  77,  78,  79,  80,  81,  90,  91 }
    },
    {
      {   6,   6,   6,   6,   6,   6,   6,   6,   6,   6,   6,  70,  71,  72,  73,  74,  92,  93 },
      {  11,  11,  11,  11,  11,  11,  11,  11,  11,  11,  11,  77,  78,  79,  80,  81,  94,  95 }
    },
    {
      {   6,   6,   6,   6,   6,   6,   6,   6,   6,   6,   6,  70,  71,  72,  73,  74,  96,  97 },
      {  11,  11,  11,  11,  11,  11,  11,  11,  11,  11,  11,  77,  78,  79,  80,  81,  98,  99 }
    },
    {
      {   6,   6,   6,   6,   6,   6,   6,   6,   6,   6,   6,  70,  71,  72,  73,  74, 100, 101 },
      {  11,  11,  11,  11,  11,  11,  11,  11,  11,  11,  11,  77,  78,  79,  80,  81, 102, 103 }
    },
    {
      {   6,   6,   6,   6,   6,   6,   6,   6,   6,   6,   6,  70,  71,  72,  73,  74, 104, 105 },
      {  11,  11,  11,  11,  11,  11,  11,  11,  11,  11,  11,  77,  78,  79,  80,  81, 106, 107 }
    }
  }
};
static unsigned short MapRec[32][18] = {
  {  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  2, 3, 4 },
  {  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  5, 6, 4 },
  {  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  2, 3, 4 },
  {  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  8, 6, 4 },
  {  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9, 10, 3, 4 },
  { 11, 11, 11, 12, 13, 14, 12, 15, 16, 17, 18, 19, 11, 11, 11, 20, 6, 4 },
  { 11, 11, 11, 21, 22, 23, 24, 25, 26, 27, 28, 29, 11, 11, 11, 30, 3, 4 },
  { 11, 11, 11, 11, 11, 31, 32, 32, 33, 34, 11, 11, 11, 11, 11, 20, 6, 4 },
  { 11, 11, 11, 11, 11, 35, 36, 37, 38, 39, 11, 11, 11, 11, 11, 30, 3, 4 },
  { 11, 11, 11, 11, 11, 40, 41, 41, 42, 11, 11, 11, 11, 11, 11, 20, 6, 4 },
  { 11, 11, 11, 11, 11, 43, 44, 45, 46, 11, 11, 11, 11, 11, 11, 30, 3, 4 },
  { 47, 47, 47, 47, 47, 47, 47, 47, 47, 47, 47, 47, 47, 47, 47, 48, 6, 4 },
  {  1,  1,  1,  1, 49, 50, 51, 52, 49, 53, 54,  1,  1,  1,  1,  2, 3, 4 },
  {  1,  1,  1,  1, 55, 56, 57, 58, 55, 59, 60,  1,  1,  1,  1,  5, 6, 4 },
  {  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  2, 3, 4 },
  { 61, 62, 63,  1,  1, 64,  1,  1, 65,  1,  1,  1,  1,  1,  1,  5, 6, 4 },
  { 66, 67, 68,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  2, 3, 4 },
  {  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  5, 6, 4 },
  { 69, 70, 71,  1,  1, 64,  1,  1, 65,  1,  1,  1,  1,  1,  1,  2, 3, 4 },
  { 72, 73, 74,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  5, 6, 4 },
  {  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  2, 3, 4 },
  { 69, 75, 71,  1,  1, 64,  1,  1, 65,  1,  1,  1,  1,  1,  1,  5, 6, 4 },
  { 76, 77, 74,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  2, 3, 4 },
  {  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  5, 6, 4 },
  {  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  2, 3, 4 },
  {  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  5, 6, 4 },
  {  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  2, 3, 4 },
  {  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  5, 6, 4 },
  {  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  2, 3, 4 },
  {  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  5, 6, 4 },
  {  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  2, 3, 4 },
  {  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  5, 6, 4 }
};
static unsigned short MapRecSP[32][18] = {
  { 4, 232, 233,  1,  1,  1,  1,   1,   1,   1,   1,   1,   1,   1,  1,  1,  1,  1 },
  { 4, 234, 235,  1,  1,  1,  1,   1,   1,   1,   1,   1,   1,   1,  1,  1,  1,  1 },
  { 4, 232, 233,  1,  1,  1,  1,   1,   1,   1,   1,   1,   1,   1,  1,  1,  1,  1 },
  { 4, 234, 236,  7,  7,  7,  7,   7,   7,   7,   7,   7,   7,   7,  7,  7,  7,  7 },
  { 4, 232, 237,  9,  9,  9,  9,   9,   9,   9,   9,   9,   9,   9,  9,  9,  9,  9 },
  { 4, 234, 238, 11, 11, 11, 11, 239, 240, 241, 242, 243,  98, 110, 11, 11, 11, 11 },
  { 4, 232, 244, 11, 11, 11, 11, 245, 246, 247, 248, 249, 104, 114, 11, 11, 11, 11 },
  { 4, 234, 238, 11, 11, 11, 11, 250, 251, 147,  41, 252, 253,  11, 11, 11, 11, 11 },
  { 4, 232, 244, 11, 11, 11, 11, 254, 255, 151, 160, 256, 257,  11, 11, 11, 11, 11 },
  { 4, 234, 238, 11, 11, 11, 11,  11,  40,  41,  41,  42,  11,  11, 11, 11, 11, 11 },
  { 4, 232, 244, 11, 11, 11, 11,  11,  43,  44,  45,  46,  11,  11, 11, 11, 11, 11 },
  { 4, 234, 258, 47, 47, 47, 47,  47,  47,  47,  47,  47,  47,  47, 47, 47, 47, 47 },
  { 4, 232, 233,  1,  1,  1,  1,  49,  50,  51,  52,  49,  53,  54,  1,  1,  1,  1 },
  { 4, 234, 235,  1,  1,  1,  1,  55,  56,  57,  58,  55,  59,  60,  1,  1,  1,  1 },
  { 4, 232, 233,  1,  1,  1,  1,   1,   1,   1,   1,   1,   1,   1,  1,  1,  1,  1 },
  { 4, 234, 235, 61, 62, 63,  1,   1,  64,   1,   1,  65,   1,   1,  1,  1,  1,  1 },
  { 4, 232, 233, 66, 67, 68,  1,   1,   1,   1,   1,   1,   1,   1,  1,  1,  1,  1 },
  { 4, 234, 235,  1,  1,  1,  1,   1,   1,   1,   1,   1,   1,   1,  1,  1,  1,  1 },
  { 4, 232, 233, 69, 70, 71,  1,   1,  64,   1,   1,  65,   1,   1,  1,  1,  1,  1 },
  { 4, 234, 235, 72, 73, 74,  1,   1,   1,   1,   1,   1,   1,   1,  1,  1,  1,  1 },
  { 4, 232, 233,  1,  1,  1,  1,   1,   1,   1,   1,   1,   1,   1,  1,  1,  1,  1 },
  { 4, 234, 235, 69, 75, 71,  1,   1,  64,   1,   1,  65,   1,   1,  1,  1,  1,  1 },
  { 4, 232, 233, 76, 77, 74,  1,   1,   1,   1,   1,   1,   1,   1,  1,  1,  1,  1 },
  { 4, 234, 235,  1,  1,  1,  1,   1,   1,   1,   1,   1,   1,   1,  1,  1,  1,  1 },
  { 4, 232, 233,  1,  1,  1,  1,   1,   1,   1,   1,   1,   1,   1,  1,  1,  1,  1 },
  { 4, 234, 235,  1,  1,  1,  1,   1,   1,   1,   1,   1,   1,   1,  1,  1,  1,  1 },
  { 4, 232, 233,  1,  1,  1,  1,   1,   1,   1,   1,   1,   1,   1,  1,  1,  1,  1 },
  { 4, 234, 235,  1,  1,  1,  1,   1,   1,   1,   1,   1,   1,   1,  1,  1,  1,  1 },
  { 4, 232, 233,  1,  1,  1,  1,   1,   1,   1,   1,   1,   1,   1,  1,  1,  1,  1 },
  { 4, 234, 235,  1,  1,  1,  1,   1,   1,   1,   1,   1,   1,   1,  1,  1,  1,  1 },
  { 4, 232, 233,  1,  1,  1,  1,   1,   1,   1,   1,   1,   1,   1,  1,  1,  1,  1 },
  { 4, 234, 235,  1,  1,  1,  1,   1,   1,   1,   1,   1,   1,   1,  1,  1,  1,  1 }
};
static unsigned short MapRecRound[7][4][18] = {
  {
    { 11, 11,  11,  12,  13,  14,  12,  15,  16,  17,  18,  19,  11, 11, 11, 20, 6, 4 },
    { 11, 11,  11,  21,  22,  23,  24,  25,  26,  27,  28,  29,  11, 11, 11, 30, 3, 4 },
    { 11, 11,  11,  11,  11,  31,  32,  32,  33,  34,  11,  11,  11, 11, 11, 20, 6, 4 },
    { 11, 11,  11,  11,  11,  35,  36,  37,  38,  39,  11,  11,  11, 11, 11, 30, 3, 4 }
  },
  {
    { 11, 11,  11,  78,  79,  80,  81,  82,  83,  84,  85,  86,  11, 11, 11, 20, 6, 4 },
    { 11, 11,  11,  87,  88,  89,  90,  91,  92,  93,  25,  94,  11, 11, 11, 30, 3, 4 },
    { 11, 11,  11,  11,  95,  96,  97,  98,  41,  99, 100,  11,  11, 11, 11, 20, 6, 4 },
    { 11, 11,  11,  11, 101, 102, 103, 104,  44, 105, 106,  11,  11, 11, 11, 30, 3, 4 }
  },
  {
    { 11, 11,  11,  11,  11, 107, 108, 109,  98, 110,  11,  11,  11, 11, 11, 20, 6, 4 },
    { 11, 11,  11,  11,  11, 111, 112, 113, 104, 114,  11,  11,  11, 11, 11, 30, 3, 4 },
    { 11, 11,  11, 115, 116, 117, 118, 119, 120, 121, 122, 123,  11, 11, 11, 20, 6, 4 },
    { 11, 11,  11,  11, 124, 125,  38, 126, 127, 128, 129,  11,  11, 11, 11, 30, 3, 4 }
  },
  {
    { 11, 11,  11,  11, 130, 131,  85, 132, 133, 134, 135,  11,  11, 11, 11, 20, 6, 4 },
    { 11, 11,  11,  11, 136, 137, 138, 139, 140, 141, 142,  11,  11, 11, 11, 30, 3, 4 },
    { 11, 11,  11, 130, 131,  85, 143, 144,  17, 145, 146, 147,  11, 11, 11, 20, 6, 4 },
    { 11, 11,  11, 136, 137, 138,  23, 148,  27, 149, 150, 151,  11, 11, 11, 30, 3, 4 }
  },
  {
    { 11, 11,  11,  11, 154,  80,  41, 155, 156, 157, 110,  11,  11, 11, 11, 20, 6, 4 },
    { 11, 11,  11,  11, 158, 159, 160, 161, 162, 163, 164,  11,  11, 11, 11, 30, 3, 4 },
    { 11, 11,  95,  33, 119, 165, 166, 167, 168, 169,  84, 170, 110, 11, 11, 20, 6, 4 },
    { 11, 11, 101, 171, 172, 173, 174, 175, 176, 177,  93, 178, 179, 11, 11, 30, 3, 4 }
  },
  {
    { 11, 11,  11, 180, 181, 182, 132, 183, 184,  82, 185, 186,  11, 11, 11, 20, 6, 4 },
    { 11, 11,  11, 187, 188, 189, 139, 190, 191, 192, 193,  94,  11, 11, 11, 30, 3, 4 },
    { 11, 11,  11, 180, 194, 195, 196, 169, 197,  33, 198, 199,  11, 11, 11, 20, 6, 4 },
    { 11, 11,  11, 187, 138, 200, 201, 202, 203, 204, 205, 206,  11, 11, 11, 30, 3, 4 }
  },
  {
    { 11, 11,  11, 207, 208, 209, 210, 211, 212, 213,  85, 214,  11, 11, 11, 20, 6, 4 },
    { 11, 11,  11, 215, 216, 217, 218, 219, 220, 221,  89, 222,  11, 11, 11, 30, 3, 4 },
    { 11, 11,  11, 207, 208,  31, 119, 223, 224, 196, 225, 226,  11, 11, 11, 20, 6, 4 },
    { 11, 11,  11, 215, 216, 219, 172, 227, 228, 229, 230, 231,  11, 11, 11, 30, 3, 4 }
  }
};
static char ErrBuf[250];
extern void(*FlipToScreen_module)();
extern void(*hmx_renderer_context_draw_module)(hmx_renderer_context*, hmx_surface*);
extern draw_context* s_ctx;
extern void(*hmx_renderer_context_add_module)(hmx_renderer_context*, int, hmx_renderer_base*);
extern hmx_renderer_base*(*hmx_sprite_base_module)(hmx_sprite*);
extern hmx_renderer_base*(*hmx_grid_base_module)(hmx_grid*);
static unsigned int hGrid[8];
extern void(*hmx_renderer_context_clear_module)(hmx_renderer_context*);
extern void(*hmx_free_module)(hmx_environment*, void*);
extern void(*hmx_bitmap_set_transparency_module)(hmx_bitmap*, int);
extern void(*ld_bitmap_4to8_module)(void*, void*, int, int, int, int, int);
extern void*(*hmx_bitmap_get_scan0_module)(hmx_bitmap*);
extern hmx_bitmap*(*hmx_bitmap_create_module)(hmx_environment*, int, int);
extern void*(*ld_load_cmpfile_module)(hmx_environment*, char*);
hmx_environment* g_env_module;
hmx_environment* g_loader_module;
extern void(*hmx_grid_set_view_module)(hmx_grid*, int, int, int, int);
static grid_rect GridRect[8];
extern void(*hmx_grid_set_position_module)(hmx_grid*, int, int);
extern hmx_grid*(*hmx_grid_create_module)(hmx_environment*, int, int, int, int);
extern void(*hmx_grid_release_module)(hmx_environment*, hmx_grid*);
extern void(*hmx_grid_set_tile_module)(hmx_grid*, int, int, hmx_bitmap*, int);
extern void(*hmx_background_set_background_module)(hmx_background*, int);
static char* lpPicBits4[2][8];
extern void(*hmx_sprite_set_bitmap_module)(hmx_sprite*, hmx_bitmap*);
extern void(*hmx_sprite_set_position_module)(hmx_sprite*, int, int);
static char* lpPicBits8;
extern int gMenuRound;
extern int gMenu1;
extern int gNewMenu2;
extern int gMenuZone;
extern int gMenu2;
static unsigned int* hBmpPic[2];
static unsigned int* hBmpBkg;
static unsigned int* hGridBmp[768];
static unsigned int hBkg;
static unsigned int hSprPic[2];
static unsigned int hTile[768];
extern void(*hmx_bitmap_release_module)(hmx_environment*, hmx_bitmap*);
extern score_data* lpScoreData;
extern int gRankY;
extern int gRankX;
extern unsigned int gTimer;
extern int gMove;
extern int gNewRankX;
extern int gNewMenuZone;
int gZure;
extern int gNewMenuRound;
extern int gNewMenu1;
static int ErrRet;











































































































































































































































void EAError(int ret, int line, char* str) { /* Line 503, Address: 0x10021a0 */
  char tmpstr[20];

  if (ret == 1) /* Line 506, Address: 0x10021b4 */
    sPrintf(tmpstr, "EA_FAILED"); /* Line 507, Address: 0x10021c4 */
  else if (ret == 2) /* Line 508, Address: 0x10021e8 */
    sPrintf(tmpstr, "EA_OUT_OF_MEMORY"); /* Line 509, Address: 0x10021f8 */
  else if (ret == 3) /* Line 510, Address: 0x100221c */
    sPrintf(tmpstr, "EA_BAD_POINTER"); /* Line 511, Address: 0x100222c */
  else if (ret == 4) /* Line 512, Address: 0x1002250 */
    sPrintf(tmpstr, "EA_OUT_OF_RANGE"); /* Line 513, Address: 0x1002260 */
  else if (ret == 5) /* Line 514, Address: 0x1002284 */
    sPrintf(tmpstr, "EA_INVALID_SIZE"); /* Line 515, Address: 0x1002294 */
  else if (ret == 6) /* Line 516, Address: 0x10022b8 */
    sPrintf(tmpstr, "EA_BAD_TYPE"); /* Line 517, Address: 0x10022c8 */

  sPrintf(ErrBuf, "\nError:\n%s on line %d\n\n%ld = %s\n", tmpstr, line, ret, str); /* Line 519, Address: 0x10022e4 */

  sOutputDebugString(ErrBuf); /* Line 521, Address: 0x1002314 */
} /* Line 522, Address: 0x100232c */


void srfDraw() { /* Line 525, Address: 0x1002340 */
  if (s_ctx->context != 0) { /* Line 526, Address: 0x100234c */
    int i;

    hmx_renderer_context_clear_module(s_ctx->context); /* Line 529, Address: 0x1002360 */


    for (i = 0; i < 8; ++i) { /* Line 532, Address: 0x100237c */
      if (hGrid[i] != 0) /* Line 533, Address: 0x1002388 */
        hmx_renderer_context_add_module(s_ctx->context, 8 - i, hmx_grid_base_module(s_ctx->grids[i])); /* Line 534, Address: 0x10023a4 */
    } /* Line 535, Address: 0x10023f0 */

    for (i = 255; i >= 0; --i) { /* Line 537, Address: 0x1002400 */
      if (s_ctx->spr_level[i] != 0) /* Line 538, Address: 0x100240c */
        hmx_renderer_context_add_module(s_ctx->context, s_ctx->spr_level[i], hmx_sprite_base_module(s_ctx->sprites[i])); /* Line 539, Address: 0x1002428 */










    } /* Line 550, Address: 0x1002484 */

    hmx_renderer_context_draw_module(s_ctx->context, s_ctx->screen); /* Line 552, Address: 0x1002490 */
  }
  FlipToScreen_module(); /* Line 554, Address: 0x10024b8 */
} /* Line 555, Address: 0x10024c8 */







int ld_load_grid_module(hmx_environment* buffer, char* file, hmx_environment* env, hmx_bitmap** bitmaps, int size) { /* Line 563, Address: 0x10024e0 */
  int count = -1; /* Line 564, Address: 0x1002520 */

  void* expbuf = 0; /* Line 566, Address: 0x1002528 */
  ld_scroll_header* header;
  int read_count;
  unsigned char* pixbuf;
  int i, palet, paletcnt, palet_offs;
  ld_bitmap_inf* s;
  int wx, wy;
  hmx_bitmap* bmp;
  palet = 0; /* Line 574, Address: 0x100252c */
  paletcnt = 0; /* Line 575, Address: 0x1002530 */
  palet_offs = 0; /* Line 576, Address: 0x1002534 */

  for (i = 0; i < size; ++i) { /* Line 578, Address: 0x1002538 */
    bitmaps[i] = 0; /* Line 579, Address: 0x1002544 */
  } /* Line 580, Address: 0x1002554 */

  expbuf = ld_load_cmpfile_module(buffer, file); /* Line 582, Address: 0x1002568 */
  if (expbuf != 0) { /* Line 583, Address: 0x1002584 */



    header = expbuf; /* Line 587, Address: 0x100258c */
    read_count = header->header.count; /* Line 588, Address: 0x1002590 */
    if (size < read_count) { /* Line 589, Address: 0x1002594 */
      read_count = size; /* Line 590, Address: 0x10025a4 */
    }

    pixbuf = (unsigned char*)expbuf + header->header.offset; /* Line 593, Address: 0x10025a8 */

    for (i = 0; i < read_count; ++i) { /* Line 595, Address: 0x10025b4 */
      s = &header->bmp[i]; /* Line 596, Address: 0x10025c0 */
      wx = s->wx; /* Line 597, Address: 0x10025d0 */
      wy = s->wy; /* Line 598, Address: 0x10025e0 */

      bmp = hmx_bitmap_create_module(env, wx, wy); /* Line 600, Address: 0x10025f0 */

      if (--paletcnt <= 0) { /* Line 602, Address: 0x1002610 */
        do {
          paletcnt = header->plt[palet++]; /* Line 604, Address: 0x100261c */
        } while (paletcnt == 0); /* Line 605, Address: 0x100263c */
        switch (palet) { /* Line 606, Address: 0x1002644 */
          case 1: palet_offs = 16; break; /* Line 607, Address: 0x1002680 */
          case 2: palet_offs = 32; break; /* Line 608, Address: 0x100268c */
          case 3: palet_offs = 48; break; /* Line 609, Address: 0x1002698 */
          case 4: palet_offs = 64; break; /* Line 610, Address: 0x10026a4 */
        }
      }

      ld_bitmap_4to8_module(hmx_bitmap_get_scan0_module(bmp), pixbuf, wx, wy, palet_offs, 0, 0); /* Line 614, Address: 0x10026a8 */















      pixbuf += wx * wy / 2; /* Line 630, Address: 0x10026e8 */

      hmx_bitmap_set_transparency_module(bmp, 0); /* Line 632, Address: 0x1002710 */

      bitmaps[i] = bmp; /* Line 634, Address: 0x1002728 */
    } /* Line 635, Address: 0x1002738 */

    count = read_count; /* Line 637, Address: 0x1002748 */
  }


  if (expbuf != 0) { /* Line 641, Address: 0x100274c */
    hmx_free_module(buffer, expbuf); /* Line 642, Address: 0x1002754 */
  }

  return count; /* Line 645, Address: 0x100276c */
} /* Line 646, Address: 0x1002770 */


int TAGridBmpCreate() { /* Line 649, Address: 0x10027b0 */
  int i, count;

  s_ctx->grd_bitmap_count = 0; /* Line 652, Address: 0x10027c0 */
  for (i = 0; i < 2048; ++i) { /* Line 653, Address: 0x10027cc */
    s_ctx->grd_bitmaps[i] = 0; /* Line 654, Address: 0x10027d8 */
  } /* Line 655, Address: 0x10027ec */

  count = ld_load_grid_module(g_loader_module, "TITLE\\BMP\\TCMPTA.CM_", g_env_module, s_ctx->grd_bitmaps, 2048); /* Line 657, Address: 0x10027fc */





  if (count <= 0) { /* Line 663, Address: 0x1002830 */
    return -1; /* Line 664, Address: 0x1002838 */
  }

  s_ctx->grd_bitmap_count = count; /* Line 667, Address: 0x1002844 */
  TileCnt = count; /* Line 668, Address: 0x1002850 */






  return 0; /* Line 675, Address: 0x1002858 */
} /* Line 676, Address: 0x100285c */


int TAGridCreate() { /* Line 679, Address: 0x1002880 */
  POINT pt;
  int i;


  for (i = 0; i < 3; ++i) { /* Line 684, Address: 0x100288c */
    hmx_grid_release_module(g_env_module, s_ctx->grids[i]); /* Line 685, Address: 0x1002898 */
    s_ctx->grids[i] = 0; /* Line 686, Address: 0x10028c4 */
  } /* Line 687, Address: 0x10028d8 */
  for (i = 0; i < 8; ++i) { /* Line 688, Address: 0x10028e8 */
    if (GridRect[i].dx != 0) { /* Line 689, Address: 0x10028f4 */
      s_ctx->grids[i] = hmx_grid_create_module(g_env_module, 8, 8, (unsigned short)(GridRect[i].dx / 8), (unsigned short)(GridRect[i].dy / 8)); /* Line 690, Address: 0x1002910 */
      hGrid[i] = (unsigned int)s_ctx->grids[i]; /* Line 691, Address: 0x10029ac */

      pt.x = 0; /* Line 693, Address: 0x10029d4 */
      pt.y = TAGridSize[i][2] * 8; /* Line 694, Address: 0x10029d8 */
      hmx_grid_set_position_module(s_ctx->grids[i], pt.x, pt.y); /* Line 695, Address: 0x10029fc */
      hmx_grid_set_view_module(s_ctx->grids[i], GridRect[i].x, GridRect[i].y, GridRect[i].dx, GridRect[i].dy); /* Line 696, Address: 0x1002a28 */
    }

  } /* Line 699, Address: 0x1002a9c */
  return 0; /* Line 700, Address: 0x1002aac */
} /* Line 701, Address: 0x1002ab0 */




int GridInitSub(char* path, map_info* pInfo) { /* Line 706, Address: 0x1002ad0 */
  unsigned short* lpReadWk;
  unsigned int hf;
  char fn[80];
  char buf[80];
  unsigned short* wp1;
  unsigned short tileno;
  int x, y;
  tile_location loc;
  int grid;

  lpReadWk = sMemAlloc(4096); /* Line 717, Address: 0x1002afc */

  sPrintf(fn, "%s%s", path, pInfo->fn); /* Line 719, Address: 0x1002b14 */

  if ((hf = sOpenFile(fn)) == -1) { /* Line 721, Address: 0x1002b3c */
    sPrintf(buf, "Read Error %s\n", fn); /* Line 722, Address: 0x1002b60 */
    sOutputDebugString(buf); /* Line 723, Address: 0x1002b80 */
    sMemFree(lpReadWk); /* Line 724, Address: 0x1002b94 */
    return -1; /* Line 725, Address: 0x1002ba8 */
  }
  sReadFile(hf, lpReadWk, pInfo->xs * pInfo->ys * 2); /* Line 727, Address: 0x1002bb4 */
  sCloseFile(hf); /* Line 728, Address: 0x1002bec */


  wp1 = lpReadWk; /* Line 731, Address: 0x1002c00 */
  grid = 1; /* Line 732, Address: 0x1002c04 */
  for (y = 0; y < pInfo->ys; ++y) { /* Line 733, Address: 0x1002c08 */
    if (pInfo->grid == 3) { /* Line 734, Address: 0x1002c14 */
      if (y < 3 || y > 23) grid = 1; /* Line 735, Address: 0x1002c2c */
      else grid = 3; /* Line 736, Address: 0x1002c50 */
    }
    loc.nTile = y + pInfo->y; /* Line 738, Address: 0x1002c54 */
    for (x = 0; x < pInfo->xs; ++x) { /* Line 739, Address: 0x1002c6c */
      loc.mTile = x + pInfo->x; /* Line 740, Address: 0x1002c78 */
      tileno = *wp1 & 2047; /* Line 741, Address: 0x1002c90 */
      if (tileno) { /* Line 742, Address: 0x1002ca4 */
        tileno += pInfo->ofs; /* Line 743, Address: 0x1002cac */
        if (tileno >= (unsigned short)TileCnt) { /* Line 744, Address: 0x1002cbc */
          sPrintf(buf, "Out of Tile Data x%d y%d %s %0x\n", x, y, pInfo->fn, tileno); /* Line 745, Address: 0x1002cdc */
          sOutputDebugString(buf); /* Line 746, Address: 0x1002d0c */
        } /* Line 747, Address: 0x1002d20 */
        else {
          hmx_grid_set_tile_module(s_ctx->grids[grid], loc.mTile, loc.nTile, s_ctx->grd_bitmaps[tileno], 0); /* Line 749, Address: 0x1002d28 */
        }
      } /* Line 751, Address: 0x1002d78 */
      else {
        if (pInfo->transp) { /* Line 753, Address: 0x1002d80 */
          hmx_grid_set_tile_module(s_ctx->grids[grid], loc.mTile, loc.nTile, 0, 0); /* Line 754, Address: 0x1002d90 */
        } /* Line 755, Address: 0x1002dcc */
        else {
          hmx_grid_set_tile_module(s_ctx->grids[grid], loc.mTile, loc.nTile, s_ctx->grd_bitmaps[pInfo->ofs], 0); /* Line 757, Address: 0x1002dd4 */
        }
      }
      ++wp1; /* Line 760, Address: 0x1002e2c */
    } /* Line 761, Address: 0x1002e30 */
  } /* Line 762, Address: 0x1002e4c */
  sMemFree(lpReadWk); /* Line 763, Address: 0x1002e68 */
  return 0; /* Line 764, Address: 0x1002e7c */

} /* Line 766, Address: 0x1002e80 */



int TAGridInit() { /* Line 770, Address: 0x1002eb0 */
  int i, cntInfo;
  map_info* pInfo;
  char* Path = "TITLE\\BMP\\TA\\BG\\"; /* Line 773, Address: 0x1002ec8 */

  pInfo = MapInfoTbl->info; /* Line 775, Address: 0x1002ed0 */
  cntInfo = MapInfoTbl->cnt; /* Line 776, Address: 0x1002ed8 */

  for (i = 0; i < cntInfo; ++i) { /* Line 778, Address: 0x1002ee0 */
    if (GridInitSub(Path, pInfo) != 0) break; /* Line 779, Address: 0x1002eec */


    ++pInfo; /* Line 782, Address: 0x1002f04 */
  } /* Line 783, Address: 0x1002f08 */
  return 0; /* Line 784, Address: 0x1002f18 */
} /* Line 785, Address: 0x1002f1c */





int BkgBmpCreate_TA() {
  return 0; /* Line 792, Address: 0x1002f40 */
} /* Line 793, Address: 0x1002f44 */


int BkgBmpDelete_TA() {
  return 0; /* Line 797, Address: 0x1002f50 */
} /* Line 798, Address: 0x1002f54 */


int BkgCreate_TA() { /* Line 801, Address: 0x1002f60 */
  hmx_background_set_background_module(s_ctx->background, 16); /* Line 802, Address: 0x1002f68 */
  return 0; /* Line 803, Address: 0x1002f88 */
} /* Line 804, Address: 0x1002f8c */


int BkgDelete_TA() {
  return 0; /* Line 808, Address: 0x1002fa0 */
} /* Line 809, Address: 0x1002fa4 */


int LoadPicBmp() { /* Line 812, Address: 0x1002fb0 */
  int i;
  int mode, round;
  bmp_header* hdr;
  unsigned char* p;
  char* lp1;
  void* expbuf;

  expbuf = 0; /* Line 820, Address: 0x1002fd4 */



  expbuf = ld_load_cmpfile_module(g_loader_module, "TITLE\\BMP\\SCMPTA.CM_"); /* Line 824, Address: 0x1002fd8 */
  if (expbuf != 0) { /* Line 825, Address: 0x1002ffc */
    hdr = expbuf; /* Line 826, Address: 0x1003004 */
    p = (unsigned char*)expbuf + hdr->dwOff; /* Line 827, Address: 0x1003008 */

    for (mode = 0; mode < 2; ++mode) { /* Line 829, Address: 0x1003010 */
      for (round = 0; round < 8; ++round) { /* Line 830, Address: 0x100301c */
        if (mode != 1 || round != 0) { /* Line 831, Address: 0x1003028 */
          lp1 = lpPicBits4[mode][round]; /* Line 832, Address: 0x100303c */
          for (i = 0; i < 9216; ++i) { /* Line 833, Address: 0x1003058 */
            *lp1 = *p; /* Line 834, Address: 0x1003064 */
            ++lp1; /* Line 835, Address: 0x100306c */
            ++p; /* Line 836, Address: 0x1003070 */
          } /* Line 837, Address: 0x1003074 */
        }
      } /* Line 839, Address: 0x1003084 */
    } /* Line 840, Address: 0x1003094 */

    hmx_free_module(g_loader_module, expbuf); /* Line 842, Address: 0x10030a4 */
  }
  return 0; /* Line 844, Address: 0x10030c0 */
} /* Line 845, Address: 0x10030c4 */





unsigned int CreatePic() { /* Line 851, Address: 0x10030f0 */
  unsigned int mask[4] = { 0, 0, 0, 0 }; /* Line 852, Address: 0x1003100 */
  POINTL pt = { 0, 0 }; /* Line 853, Address: 0x1003130 */
  int i;
  int j;

  for (i = 0; i < 2; ++i) { /* Line 857, Address: 0x1003160 */
    for (j = 0; j < 8; ++j) { /* Line 858, Address: 0x100316c */
      if (i == 1 && j == 0) { /* Line 859, Address: 0x1003178 */
        lpPicBits4[i][j] = lpPicBits4[0][0]; /* Line 860, Address: 0x100318c */
      } /* Line 861, Address: 0x10031b0 */
      else {
        lpPicBits4[i][j] = sMemAlloc(9216); /* Line 863, Address: 0x10031b8 */
        if (lpPicBits4[i][j] == 0) { /* Line 864, Address: 0x10031e8 */
          return 0; /* Line 865, Address: 0x100320c */
        }
      }
    } /* Line 868, Address: 0x1003218 */
  } /* Line 869, Address: 0x1003228 */
  lpPicBits8 = sMemAlloc(18432); /* Line 870, Address: 0x1003238 */
  if (lpPicBits8 == 0) { /* Line 871, Address: 0x1003254 */
    return 0; /* Line 872, Address: 0x1003264 */
  }

  if (LoadPicBmp() != 0) return 0; /* Line 875, Address: 0x1003270 */

  for (i = 0; i < 2; ++i) { /* Line 877, Address: 0x100328c */
    for (j = 0; j < 8; ++j) { /* Line 878, Address: 0x1003298 */
      if (i == 1) j == 0; /* Line 879, Address: 0x10032a4 */
























    } /* Line 904, Address: 0x10032b8 */
  } /* Line 905, Address: 0x10032c8 */

  for (i = 0; i < 2; ++i) { /* Line 907, Address: 0x10032d8 */
    s_ctx->spr_bitmaps[i] = hmx_bitmap_create_module(g_loader_module, 128, 72); /* Line 908, Address: 0x10032e4 */
    hmx_sprite_set_position_module(s_ctx->sprites[i], ptSprLocPic[i].x, ptSprLocPic[i].y); /* Line 909, Address: 0x1003318 */
    hmx_sprite_set_bitmap_module(s_ctx->sprites[i], s_ctx->spr_bitmaps[i]); /* Line 910, Address: 0x1003368 */
    s_ctx->spr_level[i] = i + 10; /* Line 911, Address: 0x10033a4 */
  } /* Line 912, Address: 0x10033bc */
  return 1; /* Line 913, Address: 0x10033cc */
} /* Line 914, Address: 0x10033d0 */



void SetPic(int mode, int round, int zurasi) { /* Line 918, Address: 0x10033f0 */
  int x, y;
  char* lp4;
  char* lp8;
  RECTL rect = { 0, 0, 128, 72 }; /* Line 922, Address: 0x1003420 */
  POINTL pt = { 0, 0 }; /* Line 923, Address: 0x1003434 */
  unsigned char buf[8];
  unsigned char buf2[8];
  int i;
  int j;
  unsigned char* cg;



  lp4 = lpPicBits4[mode][round]; /* Line 932, Address: 0x1003464 */
  lp8 = lpPicBits8; /* Line 933, Address: 0x1003488 */

  for (y = 0; y < 144; ++y) { /* Line 935, Address: 0x1003490 */
    for (x = 0; x < 16; ++x) { /* Line 936, Address: 0x100349c */
      for (i = 0; i < 4; ++i) { /* Line 937, Address: 0x10034a8 */

        buf[i * 2] = ((unsigned char)(*lp4 & 240) >> 4) + 48; /* Line 939, Address: 0x10034b4 */
        buf[i * 2 + 1] = ((unsigned char)*lp4 & 15) + 48; /* Line 940, Address: 0x10034e4 */
        ++lp4; /* Line 941, Address: 0x100350c */
      } /* Line 942, Address: 0x1003510 */
      for (i = 0; i < 4; ++i) { /* Line 943, Address: 0x1003520 */
        j = i - zurasi; /* Line 944, Address: 0x100352c */
        if (j < 0) j += 4; /* Line 945, Address: 0x1003534 */
        buf2[i] = buf[j]; /* Line 946, Address: 0x1003540 */
      } /* Line 947, Address: 0x1003550 */
      for (i = 4; i < 8; ++i) { /* Line 948, Address: 0x1003560 */
        j = i + zurasi; /* Line 949, Address: 0x100356c */
        if (j > 7) j -= 4; /* Line 950, Address: 0x1003574 */
        buf2[i] = buf[j]; /* Line 951, Address: 0x1003584 */
      } /* Line 952, Address: 0x1003594 */
      for (i = 0; i < 8; ++i) { /* Line 953, Address: 0x10035a4 */
        *lp8 = buf2[i]; /* Line 954, Address: 0x10035b0 */
        ++lp8; /* Line 955, Address: 0x10035bc */
      } /* Line 956, Address: 0x10035c0 */
    } /* Line 957, Address: 0x10035d0 */
  } /* Line 958, Address: 0x10035e0 */
  cg = hmx_bitmap_get_scan0_module(s_ctx->spr_bitmaps[0]); /* Line 959, Address: 0x10035f0 */
  for (i = 0; i < 9216; ++i) /* Line 960, Address: 0x1003610 */
    cg[i] = ((unsigned char*)lpPicBits8 + 9216)[i]; /* Line 961, Address: 0x100361c */
  cg = hmx_bitmap_get_scan0_module(s_ctx->spr_bitmaps[1]); /* Line 962, Address: 0x1003644 */
  for (i = 0; i < 9216; ++i) /* Line 963, Address: 0x1003664 */
    cg[i] = ((unsigned char*)lpPicBits8)[i]; /* Line 964, Address: 0x1003670 */

} /* Line 966, Address: 0x1003698 */



unsigned int TA_EACreate() { /* Line 970, Address: 0x10036d0 */
  int i;
  int j;

  for (i = 0; i < 768; ++i) hTile[i] = 0; /* Line 974, Address: 0x10036e0 */
  for (i = 0; i < 2; ++i) hSprPic[i] = 0; /* Line 975, Address: 0x1003710 */
  hBkg = 0; /* Line 976, Address: 0x1003740 */
  for (i = 0; i < 8; ++i) hGrid[i] = 0; /* Line 977, Address: 0x1003748 */
  for (i = 0; i < 768; ++i) hGridBmp[i] = 0; /* Line 978, Address: 0x1003778 */
  hBmpBkg = 0; /* Line 979, Address: 0x10037a8 */
  for (i = 0; i < 2; ++i) hBmpPic[i] = 0; /* Line 980, Address: 0x10037b0 */
  for (i = 0; i < 2; ++i) /* Line 981, Address: 0x10037e0 */
    for (j = 0; j < 8; ++j) lpPicBits4[i][j] = 0; /* Line 982, Address: 0x10037ec */
  lpPicBits8 = 0; /* Line 983, Address: 0x1003834 */

  for (i = 0; i < 8; ++i) { /* Line 985, Address: 0x100383c */
    GridRect[i].x = 0; /* Line 986, Address: 0x1003848 */
    GridRect[i].y = 0; /* Line 987, Address: 0x100385c */
    GridRect[i].dx = TAGridSize[i][0] * 8; /* Line 988, Address: 0x1003870 */
    GridRect[i].dy = TAGridSize[i][1] * 8; /* Line 989, Address: 0x10038a4 */
  } /* Line 990, Address: 0x10038d8 */


  BkgBmpCreate_TA(); /* Line 993, Address: 0x10038e8 */
  BkgCreate_TA(); /* Line 994, Address: 0x10038f0 */
  TAGridBmpCreate(); /* Line 995, Address: 0x10038f8 */
  TAGridCreate(); /* Line 996, Address: 0x1003900 */
  TAGridInit(); /* Line 997, Address: 0x1003908 */

  if (gMenu1 == 0) { /* Line 999, Address: 0x1003910 */

    GridRect[1].x = GridRect[0].x = GridRect[2].x = GridRect[3].x = 144; /* Line 1001, Address: 0x1003920 */
  }

  for (i = 0; i <= 1; ++i) { /* Line 1004, Address: 0x1003944 */
    for (j = 0; j <= 7; ++j) { /* Line 1005, Address: 0x1003950 */
      PrintRoundName(i, j, 1, 3); /* Line 1006, Address: 0x100395c */
    } /* Line 1007, Address: 0x1003974 */
    PrintTotalTime(i, 1); /* Line 1008, Address: 0x1003984 */
  } /* Line 1009, Address: 0x1003994 */
  if (gMenu2 != 0) { /* Line 1010, Address: 0x10039a4 */

    PrintZoneSelect(gMenu1, gMenuRound, gMenuZone); /* Line 1012, Address: 0x10039b4 */
    PrintMenu2(gMenu1, gNewMenu2, 1); /* Line 1013, Address: 0x10039d4 */
    if (gMenu1 == 0) { /* Line 1014, Address: 0x10039f0 */
      GridRect[2].x = 0; /* Line 1015, Address: 0x1003a00 */
    } /* Line 1016, Address: 0x1003a08 */
    else {
      GridRect[2].x = 144; /* Line 1018, Address: 0x1003a10 */
    }
  }

  CreatePic(); /* Line 1022, Address: 0x1003a1c */
  SetPic(gMenu1, gMenuRound, 0); /* Line 1023, Address: 0x1003a24 */
  TAPicColorSet(gMenu1, gMenuRound); /* Line 1024, Address: 0x1003a40 */
  return 1; /* Line 1025, Address: 0x1003a58 */
} /* Line 1026, Address: 0x1003a5c */








void DeleteEA() { /* Line 1035, Address: 0x1003a80 */
  int i, j;

  BkgBmpDelete_TA(); /* Line 1038, Address: 0x1003a90 */
  BkgDelete_TA(); /* Line 1039, Address: 0x1003a98 */

  lpPicBits4[4][0] = 0; /* Line 1041, Address: 0x1003aa0 */
  for (i = 0; i < 2; ++i) { /* Line 1042, Address: 0x1003aa8 */
    for (j = 0; j < 8; ++j) { /* Line 1043, Address: 0x1003ab4 */
      if (lpPicBits4[i][j] != 0) { /* Line 1044, Address: 0x1003ac0 */
        sMemFree(lpPicBits4[i][j]); /* Line 1045, Address: 0x1003ae4 */
      }
    } /* Line 1047, Address: 0x1003b10 */
  } /* Line 1048, Address: 0x1003b20 */
  if (lpPicBits8 != 0) sMemFree(lpPicBits8); /* Line 1049, Address: 0x1003b30 */

  for (i = 0; i < 2; ++i) { /* Line 1051, Address: 0x1003b58 */
    hBmpPic[i]; /* Line 1052, Address: 0x1003b64 */


  } /* Line 1055, Address: 0x1003b74 */

  for (i = 0; i < 2; ++i) { /* Line 1057, Address: 0x1003b84 */

    hmx_sprite_set_bitmap_module(s_ctx->sprites[i], 0); /* Line 1059, Address: 0x1003b90 */
    hmx_bitmap_release_module(g_env_module, s_ctx->spr_bitmaps[i]); /* Line 1060, Address: 0x1003bbc */
    s_ctx->spr_bitmaps[i] = 0; /* Line 1061, Address: 0x1003be8 */
    s_ctx->spr_level[i] = 0; /* Line 1062, Address: 0x1003bfc */


  } /* Line 1065, Address: 0x1003c10 */
  for (i = 0; i < TileCnt; ++i) { /* Line 1066, Address: 0x1003c20 */
    hGridBmp[i]; /* Line 1067, Address: 0x1003c2c */


    hTile[i]; /* Line 1070, Address: 0x1003c3c */


  } /* Line 1073, Address: 0x1003c4c */
  for (i = 0; i < 8; ++i) { /* Line 1074, Address: 0x1003c64 */
    if (hGrid[i] != 0) { /* Line 1075, Address: 0x1003c70 */
      hmx_grid_release_module(g_env_module, s_ctx->grids[i]); /* Line 1076, Address: 0x1003c8c */
      s_ctx->grids[i] = 0; /* Line 1077, Address: 0x1003cb8 */

    }
  } /* Line 1080, Address: 0x1003ccc */

  for (i = 0; i < 2048; ++i) { /* Line 1082, Address: 0x1003cdc */
    hmx_bitmap_release_module(g_env_module, s_ctx->grd_bitmaps[i]); /* Line 1083, Address: 0x1003ce8 */
    s_ctx->grd_bitmaps[i] = 0; /* Line 1084, Address: 0x1003d14 */
  } /* Line 1085, Address: 0x1003d28 */
  for (i = 0; i < 3; ++i) { /* Line 1086, Address: 0x1003d38 */
    s_ctx->grids[i] = hmx_grid_create_module(g_env_module, 8, 8, 64, 32); /* Line 1087, Address: 0x1003d44 */



  } /* Line 1091, Address: 0x1003d80 */

  s_ctx->grd_bitmap_count = 0; /* Line 1093, Address: 0x1003d90 */

} /* Line 1095, Address: 0x1003d9c */


void DrawTA() { /* Line 1098, Address: 0x1003dc0 */
  int i;

  GridRect[1].x = GridRect[3].x; /* Line 1101, Address: 0x1003dcc */
  GridRect[0].x = GridRect[2].x; /* Line 1102, Address: 0x1003ddc */
  GridRect[0].y = GridRect[2].y; /* Line 1103, Address: 0x1003dec */

  for (i = 0; i < 2; ++i) { /* Line 1105, Address: 0x1003dfc */
    ptSprLocPic[i].x = 168 - GridRect[3].x; /* Line 1106, Address: 0x1003e08 */
    ptSprLocPic[i].y = GridRect[3].y + 24; /* Line 1107, Address: 0x1003e2c */
    if (i == 0) ptSprLocPic[i].y += 72; /* Line 1108, Address: 0x1003e4c */
    hmx_sprite_set_position_module(s_ctx->sprites[i], ptSprLocPic[i].x, ptSprLocPic[i].y); /* Line 1109, Address: 0x1003e70 */
  } /* Line 1110, Address: 0x1003ec0 */


  for (i = 0; i < 8; ++i) { /* Line 1113, Address: 0x1003ed0 */
    if (hGrid[i] != 0) { /* Line 1114, Address: 0x1003edc */

      if (i == 2) /* Line 1116, Address: 0x1003ef8 */
        hmx_grid_set_view_module(s_ctx->grids[i], -GridRect[i].x, -GridRect[i].y, GridRect[i].dx, GridRect[i].dy + 320); /* Line 1117, Address: 0x1003f04 */
      else
        hmx_grid_set_view_module(s_ctx->grids[i], -GridRect[i].x, -GridRect[i].y, GridRect[i].dx, GridRect[i].dy); /* Line 1119, Address: 0x1003f8c */
    }
  } /* Line 1121, Address: 0x1004008 */
  srfDraw(); /* Line 1122, Address: 0x1004018 */

} /* Line 1124, Address: 0x1004020 */




unsigned short GetLFont(char c) { /* Line 1129, Address: 0x1004040 */
  if (c == 39) { /* Line 1130, Address: 0x1004048 */
    return 527; /* Line 1131, Address: 0x1004060 */
  }
  if (c == 32) { /* Line 1133, Address: 0x100406c */
    return 529; /* Line 1134, Address: 0x1004084 */
  }
  if (c == 34) { /* Line 1136, Address: 0x1004090 */
    return 525; /* Line 1137, Address: 0x10040a8 */
  }
  if (c >= 48 && c < 58) { /* Line 1139, Address: 0x10040b4 */
    return (unsigned short)(c - 48) * 2 + 453; /* Line 1140, Address: 0x10040e4 */
  }
  if (c >= 65 && c < 91) { /* Line 1142, Address: 0x1004110 */
    return ((unsigned short)(c - 65) + 10) * 2 + 453; /* Line 1143, Address: 0x1004140 */
  }
  return 0; /* Line 1145, Address: 0x1004170 */
} /* Line 1146, Address: 0x1004174 */

unsigned short GetSFont(char c) { /* Line 1148, Address: 0x1004180 */
  if (c == 39) { /* Line 1149, Address: 0x1004188 */
    return 698; /* Line 1150, Address: 0x10041a0 */
  }
  if (c == 34) { /* Line 1152, Address: 0x10041ac */
    return 696; /* Line 1153, Address: 0x10041c4 */
  }
  if (c == 32) { /* Line 1155, Address: 0x10041d0 */
    return 700; /* Line 1156, Address: 0x10041e8 */
  }
  if (c >= 48 && c < 58) { /* Line 1158, Address: 0x10041f4 */
    return (unsigned short)(c - 48) * 2 + 676; /* Line 1159, Address: 0x1004224 */
  }
  return 0; /* Line 1161, Address: 0x1004250 */
} /* Line 1162, Address: 0x1004254 */

void TimeToAsc8(unsigned int Time, char* p) { /* Line 1164, Address: 0x1004260 */
  unsigned short min, sec, msec;

  min = Time / 3600; /* Line 1167, Address: 0x1004278 */
  if (min > 99) { /* Line 1168, Address: 0x100429c */
    min = 99; /* Line 1169, Address: 0x10042ac */
    sec = 99; /* Line 1170, Address: 0x10042b4 */
    msec = 99; /* Line 1171, Address: 0x10042bc */
  } /* Line 1172, Address: 0x10042c4 */
  else {
    sec = Time % 3600 / 60; /* Line 1174, Address: 0x10042cc */
    msec = Time % 60 * 100 / 60; /* Line 1175, Address: 0x10042fc */
  }
  p[0] = min / 10 + 48; /* Line 1177, Address: 0x1004340 */
  p[1] = min % 10 + 48; /* Line 1178, Address: 0x1004370 */
  p[2] = 39; /* Line 1179, Address: 0x1004394 */
  p[3] = sec / 10 + 48; /* Line 1180, Address: 0x10043a0 */
  p[4] = sec % 10 + 48; /* Line 1181, Address: 0x10043d0 */
  p[5] = 34; /* Line 1182, Address: 0x10043f4 */
  p[6] = msec / 10 + 48; /* Line 1183, Address: 0x1004400 */
  p[7] = msec % 10 + 48; /* Line 1184, Address: 0x1004430 */


} /* Line 1187, Address: 0x1004454 */

void TimeToAsc9(unsigned int Time, char* p) { /* Line 1189, Address: 0x1004470 */
  unsigned short min, sec, msec;

  min = Time / 3600; /* Line 1192, Address: 0x1004488 */
  if (min > 999) { /* Line 1193, Address: 0x10044ac */
    min = 999; /* Line 1194, Address: 0x10044bc */
    sec = 99; /* Line 1195, Address: 0x10044c4 */
    msec = 99; /* Line 1196, Address: 0x10044cc */
  } /* Line 1197, Address: 0x10044d4 */
  else {
    sec = Time % 3600 / 60; /* Line 1199, Address: 0x10044dc */
    msec = Time % 60 * 100 / 60; /* Line 1200, Address: 0x100450c */
  }
  p[0] = min / 100 + 48; /* Line 1202, Address: 0x1004550 */
  p[1] = min % 100 / 10 + 48; /* Line 1203, Address: 0x1004580 */
  p[2] = min % 10 + 48; /* Line 1204, Address: 0x10045bc */
  p[3] = 39; /* Line 1205, Address: 0x10045e0 */
  p[4] = sec / 10 + 48; /* Line 1206, Address: 0x10045ec */
  p[5] = sec % 10 + 48; /* Line 1207, Address: 0x100461c */
  p[6] = 34; /* Line 1208, Address: 0x1004640 */
  p[7] = msec / 10 + 48; /* Line 1209, Address: 0x100464c */
  p[8] = msec % 10 + 48; /* Line 1210, Address: 0x100467c */


} /* Line 1213, Address: 0x10046a0 */


void PrintTotalTime(int mode, unsigned int b) { /* Line 1216, Address: 0x10046c0 */
  int i, j;
  char buf[9];
  unsigned int Time = 0; /* Line 1219, Address: 0x10046e0 */
  tile_location loc;
  unsigned short fontno;

  if (mode == 0) { /* Line 1223, Address: 0x10046e4 */
    for (i = 0; i < 7; ++i) { /* Line 1224, Address: 0x10046f0 */
      for (j = 0; j < 3; ++j) { /* Line 1225, Address: 0x10046fc */
        Time += lpScoreData->timeattack[i][j][0].time; /* Line 1226, Address: 0x1004708 */
      } /* Line 1227, Address: 0x1004738 */
    } /* Line 1228, Address: 0x1004748 */
  } /* Line 1229, Address: 0x1004758 */
  else {
    for (i = 0; i < 7; ++i) { /* Line 1231, Address: 0x1004760 */
      Time += lpScoreData->special[i][0].time; /* Line 1232, Address: 0x100476c */
    } /* Line 1233, Address: 0x100478c */
  }


  TimeToAsc9(Time, buf); /* Line 1237, Address: 0x100479c */

  if (mode == 0) { /* Line 1239, Address: 0x10047ac */
    loc.mTile = 46; /* Line 1240, Address: 0x10047b8 */
  } /* Line 1241, Address: 0x10047c0 */
  else {
    loc.mTile = 8; /* Line 1243, Address: 0x10047c8 */
  }
  for (i = 0; i < 9; ++i) { /* Line 1245, Address: 0x10047d0 */
    if (b != 0) { /* Line 1246, Address: 0x10047dc */
      fontno = GetLFont(buf[i]); /* Line 1247, Address: 0x10047e8 */
    } /* Line 1248, Address: 0x10047fc */
    else {
      fontno = GetLFont(32); /* Line 1250, Address: 0x1004804 */
    }
    loc.nTile = 21; /* Line 1252, Address: 0x1004814 */
    hmx_grid_set_tile_module((hmx_grid*)s_ctx->grd_bitmap_count, loc.mTile, loc.nTile, s_ctx->grd_bitmaps[fontno++], 0); /* Line 1253, Address: 0x100481c */
    loc.nTile = 22; /* Line 1254, Address: 0x1004870 */
    hmx_grid_set_tile_module((hmx_grid*)s_ctx->grd_bitmap_count, loc.mTile, loc.nTile, s_ctx->grd_bitmaps[fontno], 0); /* Line 1255, Address: 0x1004878 */
    ++loc.mTile; /* Line 1256, Address: 0x10048c0 */
  } /* Line 1257, Address: 0x10048cc */

} /* Line 1259, Address: 0x10048dc */



void PrintRoundName(int mode, int round, unsigned int b, int grid) { /* Line 1263, Address: 0x1004900 */
  unsigned short MapBuf[2][18];
  int x, y;
  int i;
  tile_location loc;
  unsigned int Time = 0; /* Line 1268, Address: 0x100492c */
  char buf[8];
  unsigned short fontno;

  if (mode == 0) { /* Line 1272, Address: 0x1004930 */
    for (i = 0; i < 3; ++i) { /* Line 1273, Address: 0x100493c */
      Time += lpScoreData->timeattack[round - 1][i][0].time; /* Line 1274, Address: 0x1004948 */
    } /* Line 1275, Address: 0x1004980 */
  } /* Line 1276, Address: 0x1004990 */
  else {
    Time = lpScoreData->special[round - 1][0].time; /* Line 1278, Address: 0x1004998 */
  }
  if (b != 0) { /* Line 1280, Address: 0x10049bc */
    for (y = 0; y < 2; ++y) { /* Line 1281, Address: 0x10049c8 */
      for (x = 0; x < 18; ++x) { /* Line 1282, Address: 0x10049d4 */
        MapBuf[y][x] = MapRound[mode][round][y][x] + 531; /* Line 1283, Address: 0x10049e0 */
      } /* Line 1284, Address: 0x1004a54 */
    } /* Line 1285, Address: 0x1004a64 */
    if (round == 0) goto label1; /* Line 1286, Address: 0x1004a74 */
    if (mode == 0) x = 7; /* Line 1287, Address: 0x1004a80 */
    else x = 3; /* Line 1288, Address: 0x1004a98 */


    TimeToAsc8(Time, buf); /* Line 1291, Address: 0x1004a9c */



    for (i = 0; i < 8; ++i) { /* Line 1295, Address: 0x1004aac */
      fontno = GetSFont(buf[i]); /* Line 1296, Address: 0x1004ab8 */
      MapBuf[0][x] = fontno++; /* Line 1297, Address: 0x1004acc */
      MapBuf[1][x++] = fontno; /* Line 1298, Address: 0x1004ae4 */
    } /* Line 1299, Address: 0x1004af8 */

  } /* Line 1301, Address: 0x1004b08 */
  else {
    for (y = 0; y < 2; ++y) { /* Line 1303, Address: 0x1004b10 */
      for (x = 0; x < 18; ++x) { /* Line 1304, Address: 0x1004b1c */
        if (round != 0) /* Line 1305, Address: 0x1004b28 */
          MapBuf[y][x] = MapRoundSpace[y][0] + 531; /* Line 1306, Address: 0x1004b34 */
        else
          MapBuf[y][x] = MapExitSpace[y][0] + 531; /* Line 1308, Address: 0x1004b78 */
      } /* Line 1309, Address: 0x1004bb4 */
    } /* Line 1310, Address: 0x1004bc4 */
  }
label1:
  for (y = 0; y < 2; ++y) { /* Line 1313, Address: 0x1004bd4 */
    loc.nTile = round * 2 + y + 3; /* Line 1314, Address: 0x1004be0 */
    for (x = 0; x < 18; ++x) { /* Line 1315, Address: 0x1004bf8 */
      loc.mTile = (unsigned int)x; /* Line 1316, Address: 0x1004c04 */
      if (mode == 0) { /* Line 1317, Address: 0x1004c0c */
        loc.mTile += 40; /* Line 1318, Address: 0x1004c18 */
      }
      if (grid == 2 && b == 0) { /* Line 1320, Address: 0x1004c24 */
        hmx_grid_set_tile_module(s_ctx->grids[grid], loc.mTile, loc.nTile, 0, 0); /* Line 1321, Address: 0x1004c40 */
      } /* Line 1322, Address: 0x1004c80 */
      else {
        hmx_grid_set_tile_module(s_ctx->grids[grid], loc.mTile, loc.nTile, s_ctx->grd_bitmaps[MapBuf[y][x]], 0); /* Line 1324, Address: 0x1004c88 */
      }
    } /* Line 1326, Address: 0x1004cf8 */
  } /* Line 1327, Address: 0x1004d08 */

} /* Line 1329, Address: 0x1004d18 */


void PrintZoneNo(int mode, int zone) { /* Line 1332, Address: 0x1004d40 */
  tile_location loc;
  unsigned short tileno;

  loc.nTile = 9; /* Line 1336, Address: 0x1004d54 */
  if (mode == 0) loc.mTile = 31; /* Line 1337, Address: 0x1004d5c */
  else loc.mTile = 30; /* Line 1338, Address: 0x1004d78 */
  tileno = GetLFont(zone + 49); /* Line 1339, Address: 0x1004d80 */
  tileno = zone * 2 + 446; /* Line 1340, Address: 0x1004d9c */
  hmx_grid_set_tile_module(s_ctx->grids[2], loc.mTile, loc.nTile, s_ctx->grd_bitmaps[tileno++], 0); /* Line 1341, Address: 0x1004db0 */
  ++loc.nTile; /* Line 1342, Address: 0x1004e04 */
  hmx_grid_set_tile_module(s_ctx->grids[2], loc.mTile, loc.nTile, s_ctx->grd_bitmaps[tileno], 0); /* Line 1343, Address: 0x1004e10 */

} /* Line 1345, Address: 0x1004e58 */


void PrintZoneSelect(int mode, int round, int zone) { /* Line 1348, Address: 0x1004e70 */
  int x, y;
  tile_location loc;
  unsigned short tileno;

  for (y = 0; y < 32; ++y) { /* Line 1353, Address: 0x1004e90 */
    loc.nTile = (unsigned int)y; /* Line 1354, Address: 0x1004e9c */
    for (x = 0; x < 18; ++x) { /* Line 1355, Address: 0x1004ea4 */
      if (mode == 0) { /* Line 1356, Address: 0x1004eb0 */
        loc.mTile = x + 22; /* Line 1357, Address: 0x1004ebc */
        if (y >= 5 && y < 9) { /* Line 1358, Address: 0x1004ec8 */
          tileno = MapRecRound[round - 1][y - 5][x] + 187; /* Line 1359, Address: 0x1004ee0 */
        } /* Line 1360, Address: 0x1004f30 */
        else {
          tileno = MapRec[y][x] + 187; /* Line 1362, Address: 0x1004f38 */
        }
      } /* Line 1364, Address: 0x1004f6c */
      else {
        loc.mTile = x + 18; /* Line 1366, Address: 0x1004f74 */
        tileno = MapRecSP[y][x] + 187; /* Line 1367, Address: 0x1004f80 */
      }
      hmx_grid_set_tile_module(s_ctx->grids[2], loc.mTile, loc.nTile, s_ctx->grd_bitmaps[tileno], 0); /* Line 1369, Address: 0x1004fb4 */
    } /* Line 1370, Address: 0x1004ffc */
  } /* Line 1371, Address: 0x100500c */
  if (mode == 0) PrintZoneNo(mode, zone); /* Line 1372, Address: 0x100501c */

  PrintZoneRecordAll(mode, round, zone); /* Line 1374, Address: 0x1005038 */

} /* Line 1376, Address: 0x100504c */


void PrintZoneRecord(int mode, int round, int zone, int rank) { /* Line 1379, Address: 0x1005070 */
  int x, y;
  int i;
  tile_location loc;
  unsigned int Time;
  char buf[12];
  unsigned short fontno;
  unsigned short MapBuf[2][12];

  --round; /* Line 1388, Address: 0x100509c */


  if (mode == 0) { /* Line 1391, Address: 0x10050a8 */
    Time = lpScoreData->timeattack[round][zone][rank].time; /* Line 1392, Address: 0x10050b4 */
    buf[8] = 32; /* Line 1393, Address: 0x10050f4 */
    buf[9] = lpScoreData->timeattack[round][zone][rank].name[0]; /* Line 1394, Address: 0x10050fc */
    buf[10] = lpScoreData->timeattack[round][zone][rank].name[1]; /* Line 1395, Address: 0x1005140 */
    buf[11] = lpScoreData->timeattack[round][zone][rank].name[2]; /* Line 1396, Address: 0x1005184 */
  } /* Line 1397, Address: 0x10051c8 */
  else {
    Time = lpScoreData->special[round][rank].time; /* Line 1399, Address: 0x10051d0 */
    buf[8] = 32; /* Line 1400, Address: 0x10051fc */
    buf[9] = lpScoreData->special[round][rank].name[0]; /* Line 1401, Address: 0x1005204 */
    buf[10] = lpScoreData->special[round][rank].name[1]; /* Line 1402, Address: 0x1005234 */
    buf[11] = lpScoreData->special[round][rank].name[2]; /* Line 1403, Address: 0x1005264 */
  }

  TimeToAsc8(Time, buf); /* Line 1406, Address: 0x1005294 */




  for (i = 0; i < 12; ++i) { /* Line 1411, Address: 0x10052a4 */
    fontno = GetLFont(buf[i]); /* Line 1412, Address: 0x10052b0 */
    MapBuf[0][i] = fontno++; /* Line 1413, Address: 0x10052c4 */
    MapBuf[1][i] = fontno; /* Line 1414, Address: 0x10052dc */
  } /* Line 1415, Address: 0x10052e8 */

  for (y = 0; y < 2; ++y) { /* Line 1417, Address: 0x10052f8 */
    loc.nTile = y + rank * 3 + 15; /* Line 1418, Address: 0x1005304 */
    for (x = 0; x < 12; ++x) { /* Line 1419, Address: 0x1005320 */
      loc.mTile = (unsigned int)x; /* Line 1420, Address: 0x100532c */
      if (mode == 0) loc.mTile = x + 25; /* Line 1421, Address: 0x1005334 */
      else loc.mTile = x + 24; /* Line 1422, Address: 0x1005354 */
      hmx_grid_set_tile_module(s_ctx->grids[2], loc.mTile, loc.nTile, s_ctx->grd_bitmaps[MapBuf[y][x]], 0); /* Line 1423, Address: 0x1005360 */
    } /* Line 1424, Address: 0x10053c4 */
  } /* Line 1425, Address: 0x10053d4 */

} /* Line 1427, Address: 0x10053e4 */


void PrintZoneRecordAll(int mode, int round, int zone) { /* Line 1430, Address: 0x1005410 */
  int i;

  for (i = 0; i < 3; ++i) { /* Line 1433, Address: 0x1005428 */
    PrintZoneRecord(mode, round, zone, i); /* Line 1434, Address: 0x1005434 */
  } /* Line 1435, Address: 0x100544c */

} /* Line 1437, Address: 0x100545c */



void PrintMenu2(int mode, int cur, unsigned int b) { /* Line 1441, Address: 0x1005470 */
  int x;
  int i;
  int j;
  int k;
  tile_location loc;
  unsigned short MapBuf[13];
  unsigned short* pw;



  if (mode == 0) pw = MapZoneMenuNormal; /* Line 1452, Address: 0x1005498 */
  else pw = MapZoneMenuSP; /* Line 1453, Address: 0x10054b4 */
  for (i = 0; i < 13; ++i) MapBuf[i] = *pw++ + 531; /* Line 1454, Address: 0x10054bc */

  if (b == 0) { /* Line 1456, Address: 0x10054fc */
    if (mode == 0) { /* Line 1457, Address: 0x1005508 */
      switch (cur) { /* Line 1458, Address: 0x1005514 */
        case 1:
          j = 1, k = 4; break; /* Line 1460, Address: 0x1005544 */
        case 2:
          j = 6, k = 9; break; /* Line 1462, Address: 0x1005554 */
        case 3:
        default:
          j = 11, k = 12; break; /* Line 1465, Address: 0x1005564 */
      }
    } /* Line 1467, Address: 0x100556c */
    else {
      switch (cur) { /* Line 1469, Address: 0x1005574 */
        case 3:
          j = 3, k = 4; break; /* Line 1471, Address: 0x1005598 */
        case 1:
        default:
          j = 6, k = 9; break; /* Line 1474, Address: 0x10055a8 */
      }
    }
    for (i = j; k >= i; ++i) MapBuf[i] = MapZoneMenuSpace + 531; /* Line 1477, Address: 0x10055b0 */
  }

  loc.nTile = 3; /* Line 1480, Address: 0x10055ec */
  for (x = 0; x < 13; ++x) { /* Line 1481, Address: 0x10055f4 */
    loc.mTile = (unsigned int)x; /* Line 1482, Address: 0x1005600 */
    if (mode == 0) loc.mTile = x + 22; /* Line 1483, Address: 0x1005608 */
    else loc.mTile = x + 22; /* Line 1484, Address: 0x1005628 */
    hmx_grid_set_tile_module(s_ctx->grids[2], loc.mTile, loc.nTile, s_ctx->grd_bitmaps[MapBuf[x]], 0); /* Line 1485, Address: 0x1005634 */
  } /* Line 1486, Address: 0x1005688 */

} /* Line 1488, Address: 0x1005698 */



void PrintRank(int mode, int rank, unsigned int b) { /* Line 1492, Address: 0x10056c0 */
  int x, y;
  tile_location loc;

  for (y = 0; y < 2; ++y) { /* Line 1496, Address: 0x10056dc */
    loc.nTile = y + rank * 3 + 15; /* Line 1497, Address: 0x10056e8 */
    for (x = 0; x < 3; ++x) { /* Line 1498, Address: 0x1005704 */
      if (mode == 0) loc.mTile = x + 22; /* Line 1499, Address: 0x1005710 */
      else loc.mTile = x + 21; /* Line 1500, Address: 0x1005730 */
      if (b != 0) { /* Line 1501, Address: 0x100573c */
        hmx_grid_set_tile_module(s_ctx->grids[0], loc.mTile, loc.nTile, s_ctx->grd_bitmaps[188], 0); /* Line 1502, Address: 0x1005748 */
      } /* Line 1503, Address: 0x1005784 */
      else {
        hmx_grid_set_tile_module(s_ctx->grids[0], loc.mTile, loc.nTile, 0, 0); /* Line 1505, Address: 0x100578c */
      }
    } /* Line 1507, Address: 0x10057c0 */
  } /* Line 1508, Address: 0x10057d0 */

} /* Line 1510, Address: 0x10057e0 */



void PrintRankName(int mode, int ranky, int rankx, char c, unsigned int b) { /* Line 1514, Address: 0x1005800 */
  tile_location loc;
  unsigned short fontno;

  fontno = GetLFont(c); /* Line 1518, Address: 0x1005820 */

  loc.nTile = ranky * 3 + 15; /* Line 1520, Address: 0x1005830 */
  if (mode == 0) loc.mTile = rankx + 34; /* Line 1521, Address: 0x1005848 */
  else loc.mTile = rankx + 33; /* Line 1522, Address: 0x100586c */
  if (b != 0) { /* Line 1523, Address: 0x100587c */
    hmx_grid_set_tile_module(s_ctx->grids[2], loc.mTile, loc.nTile, s_ctx->grd_bitmaps[fontno++], 0); /* Line 1524, Address: 0x1005888 */
    ++loc.nTile; /* Line 1525, Address: 0x10058dc */
    hmx_grid_set_tile_module(s_ctx->grids[2], loc.mTile, loc.nTile, s_ctx->grd_bitmaps[fontno], 0); /* Line 1526, Address: 0x10058e8 */
  } /* Line 1527, Address: 0x1005930 */
  else {
    hmx_grid_set_tile_module(s_ctx->grids[2], loc.mTile, loc.nTile, s_ctx->grd_bitmaps[188], 0); /* Line 1529, Address: 0x1005938 */
    ++loc.nTile; /* Line 1530, Address: 0x1005974 */
    hmx_grid_set_tile_module(s_ctx->grids[2], loc.mTile, loc.nTile, s_ctx->grd_bitmaps[188], 0); /* Line 1531, Address: 0x1005980 */
  }

} /* Line 1534, Address: 0x10059bc */




void Tenmetu() { /* Line 1539, Address: 0x10059d0 */
  char c;

  if (gTimer % 30 == 0) { /* Line 1542, Address: 0x10059dc */
    if (gMenu2 == 5) { /* Line 1543, Address: 0x10059f8 */

      if (gMenu1 == 0) { /* Line 1545, Address: 0x1005a0c */
        c = lpScoreData->timeattack[gMenuRound - 1][gMenuZone][gRankY].name[gRankX]; /* Line 1546, Address: 0x1005a1c */
      } /* Line 1547, Address: 0x1005a80 */
      else {
        c = lpScoreData->special[gMenuRound - 1][gRankY].name[gRankX]; /* Line 1549, Address: 0x1005a88 */
      }
      PrintRankName(gMenu1, gRankY, gRankX, c, 0); /* Line 1551, Address: 0x1005ad4 */
    } /* Line 1552, Address: 0x1005afc */
    else if (gMenu2 == 4) { /* Line 1553, Address: 0x1005b04 */

      PrintRank(gMenu1, gRankY, 0); /* Line 1555, Address: 0x1005b18 */
    } /* Line 1556, Address: 0x1005b34 */
    else if (gMenu2 == 0) { /* Line 1557, Address: 0x1005b3c */

      PrintRoundName(gMenu1, gMenuRound, 0, 3); /* Line 1559, Address: 0x1005b4c */
    } /* Line 1560, Address: 0x1005b6c */
    else {
      PrintMenu2(gMenu1, gMenu2, 0); /* Line 1562, Address: 0x1005b74 */
    }
  } /* Line 1564, Address: 0x1005b90 */
  else if (gTimer % 30 == 10) { /* Line 1565, Address: 0x1005b98 */
    if (gMenu2 == 5) { /* Line 1566, Address: 0x1005bb8 */

      if (gMenu1 == 0) { /* Line 1568, Address: 0x1005bcc */
        c = lpScoreData->timeattack[gMenuRound - 1][gMenuZone][gRankY].name[gRankX]; /* Line 1569, Address: 0x1005bdc */
      } /* Line 1570, Address: 0x1005c40 */
      else {
        c = lpScoreData->special[gMenuRound - 1][gRankY].name[gRankX]; /* Line 1572, Address: 0x1005c48 */
      }
      PrintRankName(gMenu1, gRankY, gRankX, c, 1); /* Line 1574, Address: 0x1005c94 */
    } /* Line 1575, Address: 0x1005cbc */
    else if (gMenu2 == 4) { /* Line 1576, Address: 0x1005cc4 */

      PrintRank(gMenu1, gRankY, 1); /* Line 1578, Address: 0x1005cd8 */
    } /* Line 1579, Address: 0x1005cf4 */
    else if (gMenu2 == 0) { /* Line 1580, Address: 0x1005cfc */

      PrintRoundName(gMenu1, gMenuRound, 1, 3); /* Line 1582, Address: 0x1005d0c */
    } /* Line 1583, Address: 0x1005d2c */
    else {
      PrintMenu2(gMenu1, gMenu2, 1); /* Line 1585, Address: 0x1005d34 */
    }
  }

} /* Line 1589, Address: 0x1005d50 */








int TAMove() { /* Line 1598, Address: 0x1005d70 */
  char c;

  switch (gMove & -32769) { /* Line 1601, Address: 0x1005d7c */

    case 6:
      if (!(gMove & 32768)) { /* Line 1604, Address: 0x1005db8 */
        gMove |= 32768; /* Line 1605, Address: 0x1005dcc */
        PrintRoundName(gMenu1, gMenuRound, 1, 3); /* Line 1606, Address: 0x1005de0 */

        TAPicColorSet(gNewMenu1, gMenuRound); /* Line 1608, Address: 0x1005e00 */
        gZure = 7; /* Line 1609, Address: 0x1005e18 */
        SetPic(gNewMenu1, gMenuRound, gZure / 2); /* Line 1610, Address: 0x1005e24 */
      } /* Line 1611, Address: 0x1005e5c */
      else {
        if (gZure != 0) { /* Line 1613, Address: 0x1005e64 */
          --gZure; /* Line 1614, Address: 0x1005e74 */
          SetPic(gNewMenu1, gMenuRound, gZure / 2); /* Line 1615, Address: 0x1005e88 */
        }
      }
      GridRect[3].x += 8; /* Line 1618, Address: 0x1005ec4 */
      GridRect[2].x = GridRect[3].x; /* Line 1619, Address: 0x1005ed8 */
      if (GridRect[3].x == 144) { /* Line 1620, Address: 0x1005ee8 */
        gMenu1 = gNewMenu1; /* Line 1621, Address: 0x1005efc */
        gMove = 0; /* Line 1622, Address: 0x1005f0c */
      }
      break; /* Line 1624, Address: 0x1005f14 */

    case 5:
      if (!(gMove & 32768)) { /* Line 1627, Address: 0x1005f1c */
        gMove |= 32768; /* Line 1628, Address: 0x1005f30 */
        PrintRoundName(gMenu1, gMenuRound, 1, 3); /* Line 1629, Address: 0x1005f44 */

        TAPicColorSet(gNewMenu1, gMenuRound); /* Line 1631, Address: 0x1005f64 */
        gZure = 7; /* Line 1632, Address: 0x1005f7c */
        SetPic(gNewMenu1, gMenuRound, gZure / 2); /* Line 1633, Address: 0x1005f88 */
      } /* Line 1634, Address: 0x1005fc8 */
      else {
        if (gZure != 0) { /* Line 1636, Address: 0x1005fd0 */
          --gZure; /* Line 1637, Address: 0x1005fe0 */
          SetPic(gNewMenu1, gMenuRound, gZure / 2); /* Line 1638, Address: 0x1005ff4 */
        }
      }
      GridRect[3].x -= 8; /* Line 1641, Address: 0x1006038 */
      GridRect[2].x = GridRect[3].x; /* Line 1642, Address: 0x100604c */
      if (GridRect[3].x == 0) { /* Line 1643, Address: 0x100605c */
        gMenu1 = gNewMenu1; /* Line 1644, Address: 0x100606c */
        gMove = 0; /* Line 1645, Address: 0x100607c */
      }
      break; /* Line 1647, Address: 0x1006084 */

    case 7:
      if (!(gMove & 32768)) { /* Line 1650, Address: 0x100608c */
        gMove |= 32768; /* Line 1651, Address: 0x10060a0 */
        gZure = 7; /* Line 1652, Address: 0x10060b4 */
        TAPicColorSet(gMenu1, gNewMenuRound); /* Line 1653, Address: 0x10060c0 */
        PrintRoundName(gMenu1, gMenuRound, 1, 3); /* Line 1654, Address: 0x10060d8 */
        gMenuRound = gNewMenuRound; /* Line 1655, Address: 0x10060f8 */
      } /* Line 1656, Address: 0x1006108 */
      else {
        --gZure; /* Line 1658, Address: 0x1006110 */
      }
      SetPic(gMenu1, gNewMenuRound, gZure / 2); /* Line 1660, Address: 0x1006124 */
      if (gZure == 0) { /* Line 1661, Address: 0x100615c */
        gMove = 0; /* Line 1662, Address: 0x100616c */
      }
      break; /* Line 1664, Address: 0x1006174 */

    case 1:
      if (!(gMove & 32768)) { /* Line 1667, Address: 0x100617c */
        gMove |= 32768; /* Line 1668, Address: 0x1006190 */

        PrintRoundName(gMenu1, gMenuRound, 1, 2); /* Line 1670, Address: 0x10061a4 */
        PrintZoneSelect(gMenu1, gMenuRound, gNewMenuZone); /* Line 1671, Address: 0x10061c4 */
        PrintMenu2(gMenu1, gNewMenu2, 1); /* Line 1672, Address: 0x10061e4 */
      }
      GridRect[2].x -= 8; /* Line 1674, Address: 0x1006200 */
      if (GridRect[2].x < 0) GridRect[2].x += 512; /* Line 1675, Address: 0x1006214 */
      if (GridRect[2].x == 0) { /* Line 1676, Address: 0x1006238 */
        gMenu2 = gNewMenu2; /* Line 1677, Address: 0x1006248 */
        gMove = 0; /* Line 1678, Address: 0x1006258 */
      }
      break; /* Line 1680, Address: 0x1006260 */

    case 2:
      if (!(gMove & 32768)) { /* Line 1683, Address: 0x1006268 */
        gMove |= 32768; /* Line 1684, Address: 0x100627c */

        PrintRoundName(gMenu1, gMenuRound, 1, 2); /* Line 1686, Address: 0x1006290 */
        PrintZoneSelect(gMenu1, gMenuRound, gNewMenuZone); /* Line 1687, Address: 0x10062b0 */
        PrintMenu2(gMenu1, gNewMenu2, 1); /* Line 1688, Address: 0x10062d0 */
      }
      GridRect[2].x += 8; /* Line 1690, Address: 0x10062ec */
      if (GridRect[2].x == 144) { /* Line 1691, Address: 0x1006300 */
        gMenu2 = gNewMenu2; /* Line 1692, Address: 0x1006314 */
        gMove = 0; /* Line 1693, Address: 0x1006324 */
      }
      break; /* Line 1695, Address: 0x100632c */

    case 3:
      GridRect[2].x += 8; /* Line 1698, Address: 0x1006334 */
      if (GridRect[2].x == 144) { /* Line 1699, Address: 0x1006348 */

        PrintRoundName(gMenu1, gMenuRound, 0, 2); /* Line 1701, Address: 0x100635c */
        gMenu2 = gNewMenu2; /* Line 1702, Address: 0x100637c */
        gMove = 0; /* Line 1703, Address: 0x100638c */
      }
      break; /* Line 1705, Address: 0x1006394 */

    case 4:
      GridRect[2].x -= 8; /* Line 1708, Address: 0x100639c */
      if (GridRect[2].x == 0) { /* Line 1709, Address: 0x10063b0 */

        PrintRoundName(gMenu1, gMenuRound, 0, 2); /* Line 1711, Address: 0x10063c0 */
        gMenu2 = gNewMenu2; /* Line 1712, Address: 0x10063e0 */
        gMove = 0; /* Line 1713, Address: 0x10063f0 */
      }
      break; /* Line 1715, Address: 0x10063f8 */

    case 8:
      GridRect[2].y -= 8; /* Line 1718, Address: 0x1006400 */
      if (GridRect[2].y < 0) GridRect[2].y += 256; /* Line 1719, Address: 0x1006414 */
      if (GridRect[2].y == 128) { /* Line 1720, Address: 0x1006438 */
        PrintZoneNo(gMenu1, gNewMenuZone); /* Line 1721, Address: 0x100644c */
      } /* Line 1722, Address: 0x1006464 */
      else if (GridRect[2].y == 184) { /* Line 1723, Address: 0x100646c */
        PrintZoneRecord(gMenu1, gMenuRound, gNewMenuZone, 0); /* Line 1724, Address: 0x1006480 */
      } /* Line 1725, Address: 0x10064a4 */
      else if (GridRect[2].y == 208) { /* Line 1726, Address: 0x10064ac */
        PrintZoneRecord(gMenu1, gMenuRound, gNewMenuZone, 1); /* Line 1727, Address: 0x10064c0 */
      } /* Line 1728, Address: 0x10064e4 */
      else if (GridRect[2].y == 232) { /* Line 1729, Address: 0x10064ec */
        PrintZoneRecord(gMenu1, gMenuRound, gNewMenuZone, 2); /* Line 1730, Address: 0x1006500 */
      } /* Line 1731, Address: 0x1006524 */
      else if (GridRect[2].y == 0) { /* Line 1732, Address: 0x100652c */
        gMenuZone = gNewMenuZone; /* Line 1733, Address: 0x100653c */
        gMove = 0; /* Line 1734, Address: 0x100654c */
      }
      break; /* Line 1736, Address: 0x1006554 */

    case 9:
      GridRect[2].y += 8; /* Line 1739, Address: 0x100655c */
      if (GridRect[2].y >= 256) GridRect[2].y -= 256; /* Line 1740, Address: 0x1006570 */
      if (GridRect[2].y == 64) { /* Line 1741, Address: 0x1006598 */
        PrintZoneNo(gMenu1, gNewMenuZone); /* Line 1742, Address: 0x10065ac */
      } /* Line 1743, Address: 0x10065c4 */
      else if (GridRect[2].y == 128) { /* Line 1744, Address: 0x10065cc */
        PrintZoneRecord(gMenu1, gMenuRound, gNewMenuZone, 0); /* Line 1745, Address: 0x10065e0 */
      } /* Line 1746, Address: 0x1006604 */
      else if (GridRect[2].y == 152) { /* Line 1747, Address: 0x100660c */
        PrintZoneRecord(gMenu1, gMenuRound, gNewMenuZone, 1); /* Line 1748, Address: 0x1006620 */
      } /* Line 1749, Address: 0x1006644 */
      else if (GridRect[2].y == 176) { /* Line 1750, Address: 0x100664c */
        PrintZoneRecord(gMenu1, gMenuRound, gNewMenuZone, 2); /* Line 1751, Address: 0x1006660 */
      } /* Line 1752, Address: 0x1006698 */
      else if (GridRect[2].y == 0) { /* Line 1753, Address: 0x10066a0 */
        gMenuZone = gNewMenuZone; /* Line 1754, Address: 0x10066b0 */
        gMove = 0; /* Line 1755, Address: 0x10066c0 */
      }
      break; /* Line 1757, Address: 0x10066c8 */
    case 10:
      PrintMenu2(gMenu1, gMenu2, 1); /* Line 1759, Address: 0x10066d0 */
      PrintMenu2(gMenu1, gNewMenu2, 0); /* Line 1760, Address: 0x10066f0 */
      gMenu2 = gNewMenu2; /* Line 1761, Address: 0x1006714 */
      gMove = 0; /* Line 1762, Address: 0x1006724 */
      break; /* Line 1763, Address: 0x100672c */
    case 11:
      PrintRank(gMenu1, gRankY, 0); /* Line 1765, Address: 0x1006734 */
      gMenu2 = gNewMenu2; /* Line 1766, Address: 0x1006750 */
      gMove = 0; /* Line 1767, Address: 0x1006760 */
      break; /* Line 1768, Address: 0x1006768 */
    case 12:
      if (gMenu1 == 0) { /* Line 1770, Address: 0x1006770 */
        c = lpScoreData->timeattack[gMenuRound - 1][gMenuZone][gRankY].name[gRankX]; /* Line 1771, Address: 0x1006780 */
      } /* Line 1772, Address: 0x10067e4 */
      else {
        c = lpScoreData->special[gMenuRound - 1][gRankY].name[gRankX]; /* Line 1774, Address: 0x10067ec */
      }
      if (gNewMenu2 == 3) { /* Line 1776, Address: 0x100683c */

        gMenu2 = gNewMenu2; /* Line 1778, Address: 0x1006850 */
        PrintRankName(gMenu1, gRankY, gRankX, c, 1); /* Line 1779, Address: 0x1006860 */
      } /* Line 1780, Address: 0x1006894 */
      else {
        if (gNewRankX == gRankX) { /* Line 1782, Address: 0x100689c */

          PrintRankName(gMenu1, gRankY, gRankX, c, 1); /* Line 1784, Address: 0x10068b4 */
        } /* Line 1785, Address: 0x10068e0 */
        else {

          PrintRankName(gMenu1, gRankY, gRankX, c, 1); /* Line 1788, Address: 0x10068e8 */
          gRankX = gNewRankX; /* Line 1789, Address: 0x100691c */
        }
      }
      gMove = 0; /* Line 1792, Address: 0x100692c */
      break; /* Line 1793, Address: 0x1006934 */
    default:
      gMove = 0; /* Line 1795, Address: 0x100693c */
      break;
  }
  return -1; /* Line 1798, Address: 0x1006944 */
} /* Line 1799, Address: 0x1006948 */
