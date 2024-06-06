#include "..\..\TYPES.H"
#include "..\COMMON\HMX_TYPES.H"
#include "STGSPRT.H"
#include "..\COMMON\HMX_OEEACTL.H"

static void DeleteCharSprt(int colom);
static unsigned int CreateCharSprt(int colom, char code);

unsigned int hSprMenu[12];
extern draw_context* s_ctx;
extern void(*hmx_sprite_set_flags_module)(hmx_sprite*, int);
extern void(*hmx_sprite_set_bitmap_module)(hmx_sprite*, hmx_bitmap*);
extern void(*hmx_sprite_set_position_module)(hmx_sprite*, int, int);
extern sprite_bmp infoSprtBmp[];
























static void DeleteCharSprt(int colom) { /* Line 39, Address: 0x1000cf0 */
  if (hSprMenu[colom] != 0) /* Line 40, Address: 0x1000cfc */
  {
    sprDelete(hSprMenu[colom]); /* Line 42, Address: 0x1000d1c */
    s_ctx->spr_level[hSprMenu[colom]] = 0; /* Line 43, Address: 0x1000d3c */
    hSprMenu[colom] = 0; /* Line 44, Address: 0x1000d68 */
  }
} /* Line 46, Address: 0x1000d80 */




static unsigned int CreateCharSprt(int colom, char code) { /* Line 51, Address: 0x1000d90 */
  RECTL SprRect = { 0, 0, 0, 0 }; /* Line 52, Address: 0x1000da4 */
  unsigned int mask[4] = { 0, 0, 0, 0 }; /* Line 53, Address: 0x1000dd4 */
  int indx;
  POINT point;


  if (hSprMenu[colom] != 0) /* Line 58, Address: 0x1000e04 */
  {
    DeleteCharSprt(colom); /* Line 60, Address: 0x1000e24 */
  }
  if (code == 45) indx = 47; /* Line 62, Address: 0x1000e30 */
  else if (code < 65) indx = code - 37; /* Line 63, Address: 0x1000e54 */
  else indx = code - 44; /* Line 64, Address: 0x1000e84 */

  sprCreate((int*)&hSprMenu[colom]); /* Line 66, Address: 0x1000e94 */



  s_ctx->spr_level[hSprMenu[colom]] = infoSprtBmp[indx].order; /* Line 70, Address: 0x1000eb0 */
  point.x = colom * 8 + 120; /* Line 71, Address: 0x1000ef0 */
  point.y = 80; /* Line 72, Address: 0x1000f00 */

  hmx_sprite_set_position_module(s_ctx->sprites[hSprMenu[colom]], point.x, point.y); /* Line 74, Address: 0x1000f08 */

  hmx_sprite_set_bitmap_module(s_ctx->sprites[hSprMenu[colom]], s_ctx->spr_bitmaps[indx]); /* Line 76, Address: 0x1000f50 */
  hmx_sprite_set_flags_module(s_ctx->sprites[hSprMenu[colom]], 0); /* Line 77, Address: 0x1000fa4 */
  return 1; /* Line 78, Address: 0x1000fe8 */
} /* Line 79, Address: 0x1000fec */




void DeleteAllCharSprt() { /* Line 84, Address: 0x1001000 */
  int m;

  for (m = 0; m < 12; ++m) /* Line 87, Address: 0x100100c */
  {
    DeleteCharSprt(m); /* Line 89, Address: 0x1001018 */
  } /* Line 90, Address: 0x1001024 */
} /* Line 91, Address: 0x1001038 */




void StrMenu(char* lpStr) { /* Line 96, Address: 0x1001050 */
  int n = 0; /* Line 97, Address: 0x1001060 */

  while (*lpStr) /* Line 99, Address: 0x1001064 */
  {
    CreateCharSprt(n, *lpStr); /* Line 101, Address: 0x100106c */
    ++n; /* Line 102, Address: 0x1001080 */
    ++lpStr; /* Line 103, Address: 0x1001084 */
  } /* Line 104, Address: 0x1001090 */
} /* Line 105, Address: 0x10010a0 */
