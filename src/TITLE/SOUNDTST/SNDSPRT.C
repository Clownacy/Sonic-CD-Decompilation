#include "..\..\TYPES.H"
#include "..\COMMON\HMX_TYPES.H"
#include "SNDSPRT.H"
#include "..\COMMON\HMX_OEEACTL.H"

static void DeleteCharSprt(int nMenuNum, int colom);
static unsigned int CreateCharSprt(int nMenuNum, int colom, char code, int color);

static int nMenuPosiX[2] = { 44, 208 };
unsigned int hSprMenu[3][10];
extern void(*hmx_sprite_set_flags_module)(hmx_sprite*, int);
extern draw_context* s_ctx;
extern void(*hmx_sprite_set_bitmap_module)(hmx_sprite*, hmx_bitmap*);
extern void(*hmx_sprite_set_position_module)(hmx_sprite*, int, int);
extern sprite_bmp infoSprtBmp[];
extern void(*sPrintf)(char*, const char*, ...);
unsigned int hMesMenu;




























static void DeleteCharSprt(int nMenuNum, int colom) { /* Line 46, Address: 0x1001ac0 */
  if (hSprMenu[nMenuNum][colom] != 0) /* Line 47, Address: 0x1001ad0 */
  {
    sprDelete(hSprMenu[nMenuNum][colom]); /* Line 49, Address: 0x1001b04 */
    s_ctx->spr_level[hSprMenu[nMenuNum][colom]] = 0; /* Line 50, Address: 0x1001b38 */
    hmx_sprite_set_bitmap_module(s_ctx->sprites[hSprMenu[nMenuNum][colom]], 0); /* Line 51, Address: 0x1001b78 */
    hmx_sprite_set_flags_module(s_ctx->sprites[hSprMenu[nMenuNum][colom]], 0); /* Line 52, Address: 0x1001bd0 */
    hSprMenu[nMenuNum][colom] = 0; /* Line 53, Address: 0x1001c28 */
  }
} /* Line 55, Address: 0x1001c54 */




static unsigned int CreateCharSprt(int nMenuNum, int colom, char code, int color) { /* Line 60, Address: 0x1001c70 */
  RECTL SprRect = { 0, 0, 0, 0 }; /* Line 61, Address: 0x1001c8c */
  unsigned int mask[4] = { 0, 0, 0, 0 }; /* Line 62, Address: 0x1001cbc */
  int indx;
  POINT point;


  if (hSprMenu[nMenuNum][colom] != 0) /* Line 67, Address: 0x1001cec */
  {
    DeleteCharSprt(nMenuNum, colom); /* Line 69, Address: 0x1001d20 */
  }
  if (color == 1) /* Line 71, Address: 0x1001d30 */
  {
    if (code == 46) indx = 82; /* Line 73, Address: 0x1001d40 */
    else if (code < 65) indx = code - 3; /* Line 74, Address: 0x1001d64 */
    else indx = code - 10; /* Line 75, Address: 0x1001d94 */
  } /* Line 76, Address: 0x1001da4 */
  else
  {
    if (code == 46) indx = 81; /* Line 79, Address: 0x1001dac */
    else if (code < 65) indx = code - 39; /* Line 80, Address: 0x1001dd0 */
    else indx = code - 46; /* Line 81, Address: 0x1001e00 */
  }

  sprCreate((int*)&hSprMenu[nMenuNum][colom]); /* Line 84, Address: 0x1001e10 */


  s_ctx->spr_level[hSprMenu[nMenuNum][colom]] = infoSprtBmp[indx].order; /* Line 87, Address: 0x1001e40 */
  point.x = nMenuPosiX[nMenuNum] + colom * 8; /* Line 88, Address: 0x1001e94 */
  point.y = 80; /* Line 89, Address: 0x1001ebc */
  hmx_sprite_set_position_module(s_ctx->sprites[hSprMenu[nMenuNum][colom]], point.x, point.y); /* Line 90, Address: 0x1001ec4 */


  hmx_sprite_set_bitmap_module(s_ctx->sprites[hSprMenu[nMenuNum][colom]], s_ctx->spr_bitmaps[indx]); /* Line 93, Address: 0x1001f20 */
  hmx_sprite_set_flags_module(s_ctx->sprites[hSprMenu[nMenuNum][colom]], 0); /* Line 94, Address: 0x1001f88 */
  return 1; /* Line 95, Address: 0x1001fe0 */
} /* Line 96, Address: 0x1001fe4 */




void DeleteAllCharSprt(void) { /* Line 101, Address: 0x1002000 */
  int n, m;

  for (n = 0; n < 3; ++n) /* Line 104, Address: 0x1002010 */
  {
    for (m = 0; m < 10; ++m) /* Line 106, Address: 0x100201c */
    {
      DeleteCharSprt(n, m); /* Line 108, Address: 0x1002028 */
    } /* Line 109, Address: 0x1002038 */
  } /* Line 110, Address: 0x1002048 */
} /* Line 111, Address: 0x1002058 */




void StrPCM(int color) { /* Line 116, Address: 0x1002070 */
  CreateCharSprt(0, 0, 80, color); /* Line 117, Address: 0x100207c */
  CreateCharSprt(0, 1, 67, color); /* Line 118, Address: 0x1002094 */
  CreateCharSprt(0, 2, 77, color); /* Line 119, Address: 0x10020ac */
  CreateCharSprt(0, 4, 78, color); /* Line 120, Address: 0x10020c4 */
  CreateCharSprt(0, 5, 79, color); /* Line 121, Address: 0x10020dc */
  CreateCharSprt(0, 6, 46, color); /* Line 122, Address: 0x10020f4 */
} /* Line 123, Address: 0x100210c */




void StrDA(int color) { /* Line 128, Address: 0x1002120 */
  CreateCharSprt(1, 0, 68, color); /* Line 129, Address: 0x100212c */
  CreateCharSprt(1, 1, 65, color); /* Line 130, Address: 0x1002144 */
  CreateCharSprt(1, 3, 78, color); /* Line 131, Address: 0x100215c */
  CreateCharSprt(1, 4, 79, color); /* Line 132, Address: 0x1002174 */
  CreateCharSprt(1, 5, 46, color); /* Line 133, Address: 0x100218c */
} /* Line 134, Address: 0x10021a4 */




void StrPCMNO(int number) { /* Line 139, Address: 0x10021c0 */
  char buf[12];

  sPrintf(buf, "%02d", number); /* Line 142, Address: 0x10021cc */
  CreateCharSprt(0, 7, buf[0], 1); /* Line 143, Address: 0x10021ec */
  CreateCharSprt(0, 8, buf[1], 1); /* Line 144, Address: 0x1002204 */
} /* Line 145, Address: 0x100221c */




void StrDANO(int number) { /* Line 150, Address: 0x1002230 */
  char buf[12];

  sPrintf(buf, "%02d", number); /* Line 153, Address: 0x100223c */
  CreateCharSprt(1, 6, buf[0], 1); /* Line 154, Address: 0x100225c */
  CreateCharSprt(1, 7, buf[1], 1); /* Line 155, Address: 0x1002274 */
} /* Line 156, Address: 0x100228c */




void StrWelcome(void) { /* Line 161, Address: 0x10022a0 */
  int indx;
  POINT point;


  indx = 99; /* Line 166, Address: 0x10022ac */

  sprCreate((int*)&hMesMenu); /* Line 168, Address: 0x10022b0 */



  s_ctx->spr_level[hMesMenu] = infoSprtBmp[indx].order; /* Line 172, Address: 0x10022c0 */
  point.x = nMenuPosiX[0] - 8; /* Line 173, Address: 0x10022f0 */
  point.y = 160; /* Line 174, Address: 0x1002300 */

  hmx_sprite_set_position_module(s_ctx->sprites[hMesMenu], point.x, point.y); /* Line 176, Address: 0x1002308 */

  hmx_sprite_set_bitmap_module(s_ctx->sprites[hMesMenu], s_ctx->spr_bitmaps[indx]); /* Line 178, Address: 0x1002340 */
  hmx_sprite_set_flags_module(s_ctx->sprites[hMesMenu], 0); /* Line 179, Address: 0x1002384 */
} /* Line 180, Address: 0x10023b8 */



void DeleteCharMes(void) { /* Line 184, Address: 0x10023d0 */
  if (hMesMenu != 0) /* Line 185, Address: 0x10023d8 */
  {
    sprDelete(hMesMenu); /* Line 187, Address: 0x10023e8 */
    hmx_sprite_set_bitmap_module(s_ctx->sprites[hMesMenu], 0); /* Line 188, Address: 0x10023f8 */
    hmx_sprite_set_flags_module(s_ctx->sprites[hMesMenu], 0); /* Line 189, Address: 0x100242c */
    s_ctx->spr_level[hMesMenu] = 0; /* Line 190, Address: 0x1002460 */
    hMesMenu = 0; /* Line 191, Address: 0x100247c */
  }
} /* Line 193, Address: 0x1002484 */
