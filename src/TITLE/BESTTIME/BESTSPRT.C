#include "..\..\TYPES.H"
#include "..\COMMON\HMX_TYPES.H"

void DeleteCharSprt(int y, int colom);
unsigned int CreateCharSprt(int colom, int y, char code);
unsigned int CreateCharSprt2(int colom, int y, char code);

int menu_y[11] = { 7, 31, 55, 79, 103, 127, 151, 175, 199, 0, 0 };
unsigned int hSprMenu[11][28];
extern draw_context* s_ctx;
extern void(*hmx_sprite_set_flags_module)(hmx_sprite*, int);
extern void(*hmx_sprite_set_bitmap_module)(hmx_sprite*, hmx_bitmap*);
extern void(*hmx_sprite_set_position_module)(hmx_sprite*, int, int);
extern int ScrollCount;
extern sprite_bmp infoSprtBmp[];







































static void DeleteCharSprt(int y, int colom) { /* Line 55, Address: 0x1000e40 */
  if (hSprMenu[y][colom] != 0) /* Line 56, Address: 0x1000e50 */
  {
    hmx_sprite_set_bitmap_module(s_ctx->sprites[hSprMenu[y][colom]], 0); /* Line 58, Address: 0x1000e84 */
    hmx_sprite_set_flags_module(s_ctx->sprites[hSprMenu[y][colom]], 0); /* Line 59, Address: 0x1000edc */
    s_ctx->spr_level[hSprMenu[y][colom]] = 0; /* Line 60, Address: 0x1000f34 */
    sprDelete(hSprMenu[y][colom]); /* Line 61, Address: 0x1000f74 */
    hSprMenu[y][colom] = 0; /* Line 62, Address: 0x1000fa8 */
  }
} /* Line 64, Address: 0x1000fd4 */




static unsigned int CreateCharSprt(int colom, int y, char code) { /* Line 69, Address: 0x1000ff0 */
  int indx;
  POINT point;


  if (hSprMenu[y][colom] != 0) /* Line 74, Address: 0x1001008 */
  {
    DeleteCharSprt(y, colom); /* Line 76, Address: 0x100103c */
  }
  if (code == 32) indx = 89; /* Line 78, Address: 0x100104c */
  else if (code == 44) indx = 90; /* Line 79, Address: 0x1001070 */
  else if (code == 46) indx = 91; /* Line 80, Address: 0x1001094 */
  else if (code == 45) indx = 72; /* Line 81, Address: 0x10010b8 */
  else if (code < 65) indx = code - 48; /* Line 82, Address: 0x10010dc */
  else indx = code - 55; /* Line 83, Address: 0x100110c */

  sprCreate(&hSprMenu[y][colom]); /* Line 85, Address: 0x100111c */


  s_ctx->spr_level[hSprMenu[y][colom]] = 60 - infoSprtBmp[indx].order; /* Line 88, Address: 0x100114c */
  point.x = colom * 8 + 56; /* Line 89, Address: 0x10011a8 */

  point.y = ScrollCount * 8 + menu_y[y]; /* Line 91, Address: 0x10011b8 */

  hmx_sprite_set_position_module(s_ctx->sprites[hSprMenu[y][colom]], point.x, point.y); /* Line 93, Address: 0x10011e4 */

  hmx_sprite_set_bitmap_module(s_ctx->sprites[hSprMenu[y][colom]], s_ctx->spr_bitmaps[indx]); /* Line 95, Address: 0x1001240 */
  hmx_sprite_set_flags_module(s_ctx->sprites[hSprMenu[y][colom]], 0); /* Line 96, Address: 0x10012a8 */

  return 1; /* Line 98, Address: 0x1001300 */
} /* Line 99, Address: 0x1001304 */



static unsigned int CreateCharSprt2(int colom, int y, char code) { /* Line 103, Address: 0x1001320 */
  int indx;
  POINT point;


  if (hSprMenu[y][colom] != 0) /* Line 108, Address: 0x1001338 */
  {
    DeleteCharSprt(y, colom); /* Line 110, Address: 0x100136c */
  }
  if (code == 32) indx = 89; /* Line 112, Address: 0x100137c */
  else if (code == 44) indx = 90; /* Line 113, Address: 0x10013a0 */
  else if (code == 46) indx = 91; /* Line 114, Address: 0x10013c4 */
  else if (code == 45) indx = 72; /* Line 115, Address: 0x10013e8 */
  else if (code < 65) indx = code - 12; /* Line 116, Address: 0x100140c */
  else indx = code - 19; /* Line 117, Address: 0x100143c */

  sprCreate(&hSprMenu[y][colom]); /* Line 119, Address: 0x100144c */


  s_ctx->spr_level[hSprMenu[y][colom]] = 60 - infoSprtBmp[indx].order; /* Line 122, Address: 0x100147c */
  point.x = colom * 8 + 56; /* Line 123, Address: 0x10014d8 */

  point.y = ScrollCount * 8 + menu_y[y]; /* Line 125, Address: 0x10014e8 */

  hmx_sprite_set_position_module(s_ctx->sprites[hSprMenu[y][colom]], point.x, point.y); /* Line 127, Address: 0x1001514 */

  hmx_sprite_set_bitmap_module(s_ctx->sprites[hSprMenu[y][colom]], s_ctx->spr_bitmaps[indx]); /* Line 129, Address: 0x1001570 */
  hmx_sprite_set_flags_module(s_ctx->sprites[hSprMenu[y][colom]], 0); /* Line 130, Address: 0x10015d8 */
  return 1; /* Line 131, Address: 0x1001630 */
} /* Line 132, Address: 0x1001634 */




void DeleteAllCharSprt() { /* Line 137, Address: 0x1001650 */
  int m, n;

  for (n = 0; n < 11; ++n) /* Line 140, Address: 0x1001660 */
    for (m = 0; m < 28; ++m) /* Line 141, Address: 0x100166c */
    {
      DeleteCharSprt(n, m); /* Line 143, Address: 0x1001678 */
    } /* Line 144, Address: 0x1001688 */
} /* Line 145, Address: 0x10016a8 */




void StrMenu(int y, char* lpStr) { /* Line 150, Address: 0x10016c0 */
  int n = 0; /* Line 151, Address: 0x10016d4 */

  while (*lpStr) /* Line 153, Address: 0x10016d8 */
  {
    CreateCharSprt(n, y, *lpStr); /* Line 155, Address: 0x10016e0 */
    ++n; /* Line 156, Address: 0x10016f8 */
    ++lpStr; /* Line 157, Address: 0x10016fc */
  } /* Line 158, Address: 0x1001708 */
} /* Line 159, Address: 0x1001718 */

void StrMenu2(int y, char* lpStr) { /* Line 161, Address: 0x1001730 */
  int n = 0; /* Line 162, Address: 0x1001744 */

  while (*lpStr) /* Line 164, Address: 0x1001748 */
  {
    CreateCharSprt2(n, y, *lpStr); /* Line 166, Address: 0x1001750 */
    ++n; /* Line 167, Address: 0x1001768 */
    ++lpStr; /* Line 168, Address: 0x100176c */
  } /* Line 169, Address: 0x1001778 */
} /* Line 170, Address: 0x1001788 */
