#include "..\..\TYPES.H"
#include "..\COMMON\HMX_TYPES.H"
#include "VMDSPRT.H"
#include "..\COMMON\HMX_OEEACTL.H"

static int nMenuPosiY[5] = { 112, 128, 144, 160, 176 };
extern draw_context* s_ctx;
unsigned int hSprMenu[5][11];
extern sprite_bmp infoSprtBmp[];
extern void(*hmx_sprite_set_flags_module)(hmx_sprite*, int);
extern void(*hmx_sprite_set_bitmap_module)(hmx_sprite*, hmx_bitmap*);
extern void(*hmx_sprite_set_position_module)(hmx_sprite*, int, int);











































unsigned int CreateCharSprt(int nMenuNum, int colom, int code) { /* Line 56, Address: 0x1003500 */
  POINT point;





  if (hSprMenu[nMenuNum][colom] != 0) /* Line 63, Address: 0x1003514 */
    return 0; /* Line 64, Address: 0x1003550 */

  sprCreate((int*)&hSprMenu[nMenuNum][colom]); /* Line 66, Address: 0x100355c */


  point.x = colom * 8 + 192; /* Line 69, Address: 0x1003594 */
  point.y = nMenuPosiY[nMenuNum]; /* Line 70, Address: 0x10035a4 */




  hmx_sprite_set_position_module(s_ctx->sprites[hSprMenu[nMenuNum][colom]], point.x, point.y); /* Line 75, Address: 0x10035c0 */
  hmx_sprite_set_bitmap_module(s_ctx->sprites[hSprMenu[nMenuNum][colom]], s_ctx->spr_bitmaps[code]); /* Line 76, Address: 0x1003624 */
  hmx_sprite_set_flags_module(s_ctx->sprites[hSprMenu[nMenuNum][colom]], 0); /* Line 77, Address: 0x1003698 */
  s_ctx->spr_level[hSprMenu[nMenuNum][colom]] = 60 - infoSprtBmp[code].order; /* Line 78, Address: 0x10036f8 */
  return 1; /* Line 79, Address: 0x1003760 */
} /* Line 80, Address: 0x1003764 */




void DeleteCharSprt(int nMenuNum, int colom) { /* Line 85, Address: 0x1003780 */

  if (hSprMenu[nMenuNum][colom] != 0) /* Line 87, Address: 0x1003790 */
  {

    hmx_sprite_set_bitmap_module(s_ctx->sprites[hSprMenu[nMenuNum][colom]], 0); /* Line 90, Address: 0x10037cc */
    hmx_sprite_set_flags_module(s_ctx->sprites[hSprMenu[nMenuNum][colom]], 0); /* Line 91, Address: 0x100382c */
    s_ctx->spr_level[hSprMenu[nMenuNum][colom]] = 0; /* Line 92, Address: 0x100388c */
    sprDelete(hSprMenu[nMenuNum][colom]); /* Line 93, Address: 0x10038d4 */
    hSprMenu[nMenuNum][colom] = 0; /* Line 94, Address: 0x1003910 */
  }
} /* Line 96, Address: 0x1003944 */




void DeleteAllCharSprt() { /* Line 101, Address: 0x1003960 */
  int n, m;

  for (n = 0; n < 5; ++n) /* Line 104, Address: 0x1003970 */
  {
    for (m = 0; m < 11; ++m) /* Line 106, Address: 0x100397c */
    {
      DeleteCharSprt(n, m); /* Line 108, Address: 0x1003988 */
    } /* Line 109, Address: 0x1003998 */
  } /* Line 110, Address: 0x10039a8 */
} /* Line 111, Address: 0x10039b8 */





void StrEXIT(int kind) { /* Line 117, Address: 0x10039d0 */
  if (kind == 0) /* Line 118, Address: 0x10039dc */
  {
    DeleteCharSprt(0, 0); CreateCharSprt(0, 0, 4); DeleteCharSprt(0, 1); CreateCharSprt(0, 1, 23); DeleteCharSprt(0, 2); CreateCharSprt(0, 2, 8); DeleteCharSprt(0, 3); CreateCharSprt(0, 3, 19); /* Line 120, Address: 0x10039e8 */
  } /* Line 121, Address: 0x1003a78 */
  else
  {
    DeleteCharSprt(0, 0); CreateCharSprt(0, 0, 30); DeleteCharSprt(0, 1); CreateCharSprt(0, 1, 49); DeleteCharSprt(0, 2); CreateCharSprt(0, 2, 34); DeleteCharSprt(0, 3); CreateCharSprt(0, 3, 45); /* Line 124, Address: 0x1003a80 */
  }
} /* Line 126, Address: 0x1003b10 */





void StrOPENING(int kind) { /* Line 132, Address: 0x1003b20 */
  if (kind == 0) /* Line 133, Address: 0x1003b2c */
  {
    DeleteCharSprt(1, 0); CreateCharSprt(1, 0, 14); DeleteCharSprt(1, 1); CreateCharSprt(1, 1, 15); DeleteCharSprt(1, 2); CreateCharSprt(1, 2, 4); DeleteCharSprt(1, 3); CreateCharSprt(1, 3, 13); /* Line 135, Address: 0x1003b38 */
    DeleteCharSprt(1, 4); CreateCharSprt(1, 4, 8); DeleteCharSprt(1, 5); CreateCharSprt(1, 5, 13); DeleteCharSprt(1, 6); CreateCharSprt(1, 6, 6); /* Line 136, Address: 0x1003bc8 */
  } /* Line 137, Address: 0x1003c34 */
  else
  {
    DeleteCharSprt(1, 0); CreateCharSprt(1, 0, 40); DeleteCharSprt(1, 1); CreateCharSprt(1, 1, 41); DeleteCharSprt(1, 2); CreateCharSprt(1, 2, 30); DeleteCharSprt(1, 3); CreateCharSprt(1, 3, 39); /* Line 140, Address: 0x1003c3c */
    DeleteCharSprt(1, 4); CreateCharSprt(1, 4, 34); DeleteCharSprt(1, 5); CreateCharSprt(1, 5, 39); DeleteCharSprt(1, 6); CreateCharSprt(1, 6, 32); /* Line 141, Address: 0x1003ccc */
  }
} /* Line 143, Address: 0x1003d38 */





void StrGOODENDING(int kind) { /* Line 149, Address: 0x1003d50 */
  if (kind == 0) /* Line 150, Address: 0x1003d5c */
  {
    DeleteCharSprt(2, 0); CreateCharSprt(2, 0, 6); DeleteCharSprt(2, 1); CreateCharSprt(2, 1, 14); DeleteCharSprt(2, 2); CreateCharSprt(2, 2, 14); DeleteCharSprt(2, 3); CreateCharSprt(2, 3, 3); /* Line 152, Address: 0x1003d68 */
    DeleteCharSprt(2, 5); CreateCharSprt(2, 5, 4); DeleteCharSprt(2, 6); CreateCharSprt(2, 6, 13); DeleteCharSprt(2, 7); CreateCharSprt(2, 7, 3); /* Line 153, Address: 0x1003df8 */
    DeleteCharSprt(2, 8); CreateCharSprt(2, 8, 8); DeleteCharSprt(2, 9); CreateCharSprt(2, 9, 13); DeleteCharSprt(2, 10); CreateCharSprt(2, 10, 6); /* Line 154, Address: 0x1003e64 */
  } /* Line 155, Address: 0x1003ed0 */
  else
  {
    DeleteCharSprt(2, 0); CreateCharSprt(2, 0, 32); DeleteCharSprt(2, 1); CreateCharSprt(2, 1, 40); DeleteCharSprt(2, 2); CreateCharSprt(2, 2, 40); DeleteCharSprt(2, 3); CreateCharSprt(2, 3, 29); /* Line 158, Address: 0x1003ed8 */
    DeleteCharSprt(2, 5); CreateCharSprt(2, 5, 30); DeleteCharSprt(2, 6); CreateCharSprt(2, 6, 39); DeleteCharSprt(2, 7); CreateCharSprt(2, 7, 29); /* Line 159, Address: 0x1003f68 */
    DeleteCharSprt(2, 8); CreateCharSprt(2, 8, 34); DeleteCharSprt(2, 9); CreateCharSprt(2, 9, 39); DeleteCharSprt(2, 10); CreateCharSprt(2, 10, 32); /* Line 160, Address: 0x1003fd4 */
  }
} /* Line 162, Address: 0x1004040 */





void StrBADENDING(int kind) { /* Line 168, Address: 0x1004050 */
  if (kind == 0) /* Line 169, Address: 0x100405c */
  {
    DeleteCharSprt(3, 0); CreateCharSprt(3, 0, 1); DeleteCharSprt(3, 1); CreateCharSprt(3, 1, 0); DeleteCharSprt(3, 2); CreateCharSprt(3, 2, 3); /* Line 171, Address: 0x1004068 */
    DeleteCharSprt(3, 4); CreateCharSprt(3, 4, 4); DeleteCharSprt(3, 5); CreateCharSprt(3, 5, 13); DeleteCharSprt(3, 6); CreateCharSprt(3, 6, 3); DeleteCharSprt(3, 7); CreateCharSprt(3, 7, 8); /* Line 172, Address: 0x10040d4 */
    DeleteCharSprt(3, 8); CreateCharSprt(3, 8, 13); DeleteCharSprt(3, 9); CreateCharSprt(3, 9, 6); /* Line 173, Address: 0x1004164 */
  } /* Line 174, Address: 0x10041ac */
  else
  {
    DeleteCharSprt(3, 0); CreateCharSprt(3, 0, 27); DeleteCharSprt(3, 1); CreateCharSprt(3, 1, 26); DeleteCharSprt(3, 2); CreateCharSprt(3, 2, 29); /* Line 177, Address: 0x10041b4 */
    DeleteCharSprt(3, 4); CreateCharSprt(3, 4, 30); DeleteCharSprt(3, 5); CreateCharSprt(3, 5, 39); DeleteCharSprt(3, 6); CreateCharSprt(3, 6, 29); DeleteCharSprt(3, 7); CreateCharSprt(3, 7, 34); /* Line 178, Address: 0x1004220 */
    DeleteCharSprt(3, 8); CreateCharSprt(3, 8, 39); DeleteCharSprt(3, 9); CreateCharSprt(3, 9, 32); /* Line 179, Address: 0x10042b0 */
  }
} /* Line 181, Address: 0x10042f8 */





void StrPENCILTEST(int kind) { /* Line 187, Address: 0x1004310 */
  if (kind == 0) /* Line 188, Address: 0x100431c */
  {
    DeleteCharSprt(4, 0); CreateCharSprt(4, 0, 15); DeleteCharSprt(4, 1); CreateCharSprt(4, 1, 4); DeleteCharSprt(4, 2); CreateCharSprt(4, 2, 13); DeleteCharSprt(4, 3); CreateCharSprt(4, 3, 2); /* Line 190, Address: 0x1004328 */
    DeleteCharSprt(4, 4); CreateCharSprt(4, 4, 8); DeleteCharSprt(4, 5); CreateCharSprt(4, 5, 11); DeleteCharSprt(4, 7); CreateCharSprt(4, 7, 19); /* Line 191, Address: 0x10043b8 */
    DeleteCharSprt(4, 8); CreateCharSprt(4, 8, 4); DeleteCharSprt(4, 9); CreateCharSprt(4, 9, 18); DeleteCharSprt(4, 10); CreateCharSprt(4, 10, 19); /* Line 192, Address: 0x1004424 */
  } /* Line 193, Address: 0x1004490 */
  else
  {
    DeleteCharSprt(4, 0); CreateCharSprt(4, 0, 41); DeleteCharSprt(4, 1); CreateCharSprt(4, 1, 30); DeleteCharSprt(4, 2); CreateCharSprt(4, 2, 39); DeleteCharSprt(4, 3); CreateCharSprt(4, 3, 28); /* Line 196, Address: 0x1004498 */
    DeleteCharSprt(4, 4); CreateCharSprt(4, 4, 34); DeleteCharSprt(4, 5); CreateCharSprt(4, 5, 37); DeleteCharSprt(4, 7); CreateCharSprt(4, 7, 45); /* Line 197, Address: 0x1004528 */
    DeleteCharSprt(4, 8); CreateCharSprt(4, 8, 30); DeleteCharSprt(4, 9); CreateCharSprt(4, 9, 44); DeleteCharSprt(4, 10); CreateCharSprt(4, 10, 45); /* Line 198, Address: 0x1004594 */
  }
} /* Line 200, Address: 0x1004600 */
