#include "..\..\TYPES.H"
#include "..\COMMON\HMX_TYPES.H"
#include "..\COMMON\GRID.H"

extern void(*hmx_ddagrid_set_tile_module)(hmx_ddagrid*, int, int, hmx_bitmap*, int);
extern grid_bmp infoGridBmp[];
extern draw_context* s_ctx;
extern hmx_ddagrid*(*hmx_ddagrid_create_module)(hmx_environment*, int, int, int, int, int, int);
extern hmx_environment* g_env_module;
extern void(*hmx_grid_set_view_module)(hmx_grid*, int, int, int, int);
extern void(*hmx_grid_set_tile_module)(hmx_grid*, int, int, hmx_bitmap*, int);
extern hmx_grid*(*hmx_grid_create_module)(hmx_environment*, int, int, int, int);
extern void(*hmx_grid_set_position_module)(hmx_grid*, int, int);
extern void(*hmx_grid_release_module)(hmx_environment*, hmx_grid*);





















int OEGridCreate(unsigned short indx) { /* Line 36, Address: 0x1003370 */
  tile_location loc;
  grid_rect rectwh;
  unsigned short x;
  unsigned short y;

  if (indx == 0) /* Line 42, Address: 0x100338c */
  {


    s_ctx->grids[indx] = hmx_grid_create_module(g_env_module, 8, 8, 40, 28); /* Line 46, Address: 0x100339c */
    *infoGridBmp[indx].lphGrid = (unsigned int)s_ctx->grids[indx]; /* Line 47, Address: 0x10033e0 */





    for (y = 0; y < 28; ++y) /* Line 53, Address: 0x1003424 */
    {
      loc.nTile = y; /* Line 55, Address: 0x1003430 */
      for (x = 0; x < 40; ++x) /* Line 56, Address: 0x1003434 */
      {
        loc.mTile = x; /* Line 58, Address: 0x1003440 */

        hmx_grid_set_tile_module(s_ctx->grids[indx], x, y, (hmx_bitmap*)*infoGridBmp[indx].lphBmp, 0); /* Line 60, Address: 0x1003444 */
      } /* Line 61, Address: 0x10034a4 */
    } /* Line 62, Address: 0x10034bc */


    hmx_grid_set_position_module(s_ctx->grids[indx], infoGridBmp[indx].point.x, infoGridBmp[indx].point.y); /* Line 65, Address: 0x10034d8 */

    rectwh.x = 0; /* Line 67, Address: 0x100354c */
    rectwh.y = 0; /* Line 68, Address: 0x1003550 */
    rectwh.dx = infoGridBmp[indx].w * 40; /* Line 69, Address: 0x1003554 */
    rectwh.dy = infoGridBmp[indx].h * 28; /* Line 70, Address: 0x100358c */

    hmx_grid_set_view_module(s_ctx->grids[indx], rectwh.x, rectwh.y, rectwh.dx, rectwh.dy); /* Line 72, Address: 0x10035c4 */
  } /* Line 73, Address: 0x1003600 */
  else if (indx == 1) /* Line 74, Address: 0x1003608 */
  {
    int tileh[320];
    int i;
    s_ctx->grids[indx] = hmx_grid_create_module(g_env_module, 8, 8, 80, 8); /* Line 78, Address: 0x100361c */
    *infoGridBmp[indx].lphGrid = (unsigned int)s_ctx->grids[indx]; /* Line 79, Address: 0x1003660 */

    for (y = 0, i = 0; y < 8; y++) /* Line 81, Address: 0x10036a4 */
    {
      for (x = 0; x < 40; ++x) /* Line 83, Address: 0x10036b4 */
      {



        tileh[i++] = x + y * 40; /* Line 88, Address: 0x10036c0 */
      } /* Line 89, Address: 0x10036ec */
    } /* Line 90, Address: 0x1003704 */
    for (y = 0; y < 8; ++y) /* Line 91, Address: 0x100371c */
    {
      loc.nTile = y; /* Line 93, Address: 0x1003728 */
      for (x = 0; x < 80; ++x) /* Line 94, Address: 0x100372c */
      {
        loc.mTile = x; /* Line 96, Address: 0x1003738 */
        hmx_grid_set_tile_module(s_ctx->grids[indx], x, y, (hmx_bitmap*)infoGridBmp[indx].lphBmp[tileh[x % 40 + (7 - y) * 40]], 0); /* Line 97, Address: 0x100373c */

      } /* Line 99, Address: 0x10037dc */
    } /* Line 100, Address: 0x10037f4 */



    rectwh.x = 0; /* Line 104, Address: 0x100380c */
    rectwh.y = 0; /* Line 105, Address: 0x1003810 */
    rectwh.dx = infoGridBmp[indx].w * 41; /* Line 106, Address: 0x1003814 */
    rectwh.dy = infoGridBmp[indx].h * 8; /* Line 107, Address: 0x1003850 */

    hmx_grid_set_view_module(s_ctx->grids[indx], rectwh.x, infoGridBmp[indx].point.y, rectwh.dx, rectwh.dy); /* Line 109, Address: 0x1003880 */
  } /* Line 110, Address: 0x10038dc */
  else if (indx == 2) /* Line 111, Address: 0x10038e4 */
  {
    int tileh[512];
    int i;

    s_ctx->grids[indx] = (hmx_grid*)hmx_ddagrid_create_module(g_env_module, 3, 3, 6, 4, 320, 92); /* Line 116, Address: 0x10038f8 */
    *infoGridBmp[indx].lphGrid = (unsigned int)s_ctx->grids[indx]; /* Line 117, Address: 0x1003944 */
    for (y = 0, i = 0; y < 16; ++y) /* Line 118, Address: 0x1003988 */
    {
      for (x = 0; x < 32; ++x) /* Line 120, Address: 0x1003998 */
      {


        tileh[i++] = x + y * 32; /* Line 124, Address: 0x10039a4 */
      } /* Line 125, Address: 0x10039c8 */
    } /* Line 126, Address: 0x10039e0 */
    for (y = 0; y < 16; ++y) /* Line 127, Address: 0x10039f8 */
    {
      for (x = 0; x < 32; ++x) /* Line 129, Address: 0x1003a04 */
      {

        hmx_ddagrid_set_tile_module((hmx_ddagrid*)s_ctx->grids[indx], x, y, (hmx_bitmap*)infoGridBmp[indx].lphBmp[tileh[x + (15 - y) * 32]], 0); /* Line 132, Address: 0x1003a10 */
      } /* Line 133, Address: 0x1003aa4 */
      for ( ; x < 40; ++x) /* Line 134, Address: 0x1003abc */
      {

        hmx_ddagrid_set_tile_module((hmx_ddagrid*)s_ctx->grids[indx], x, y, (hmx_bitmap*)infoGridBmp[indx].lphBmp[tileh[x + (15 - y) * 32 - 32]], 0); /* Line 137, Address: 0x1003ac4 */
      } /* Line 138, Address: 0x1003b5c */
    } /* Line 139, Address: 0x1003b74 */
  }







  return 0; /* Line 148, Address: 0x1003b8c */
} /* Line 149, Address: 0x1003b90 */



void OEGridDelete(unsigned short indx) { /* Line 153, Address: 0x1003bb0 */
  unsigned short x, y;

  if (*infoGridBmp[indx].lphGrid != 0) /* Line 156, Address: 0x1003bc4 */
  {
    if (indx != 1) /* Line 158, Address: 0x1003bf4 */
    {




      (unsigned int)(indx ^ 2) < 1; /* Line 164, Address: 0x1003c08 */
    }



    hmx_grid_release_module(g_env_module, s_ctx->grids[indx]); /* Line 169, Address: 0x1003c18 */
    *infoGridBmp[indx].lphGrid = 0; /* Line 170, Address: 0x1003c4c */
    s_ctx->grids[indx] = 0; /* Line 171, Address: 0x1003c74 */
  }


  if (indx == 0) /* Line 175, Address: 0x1003c90 */
  {
    if (*infoGridBmp[indx].lphTile != 0) /* Line 177, Address: 0x1003ca0 */
    {

      *infoGridBmp[indx].lphTile = 0; /* Line 180, Address: 0x1003cd0 */
    }
  } /* Line 182, Address: 0x1003cf8 */
  else if (indx == 1) /* Line 183, Address: 0x1003d00 */
  {
    for (y = 0; y < 8; ++y) /* Line 185, Address: 0x1003d14 */
    {
      for (x = 0; x < 40; ++x) /* Line 187, Address: 0x1003d20 */
      {
        if (infoGridBmp[indx].lphTile[x + y * 40] != 0) /* Line 189, Address: 0x1003d2c */
        {

          infoGridBmp[indx].lphTile[x + y * 40] = 0; /* Line 192, Address: 0x1003d7c */
        }
      } /* Line 194, Address: 0x1003dc4 */
    } /* Line 195, Address: 0x1003ddc */
  } /* Line 196, Address: 0x1003df4 */
  else if (indx == 2) /* Line 197, Address: 0x1003dfc */
  {
    for (y = 0; y < 16; ++y) /* Line 199, Address: 0x1003e10 */
    {
      for (x = 0; x < 32; ++x) /* Line 201, Address: 0x1003e1c */
      {
        if (infoGridBmp[indx].lphTile[x + y * 32] != 0) /* Line 203, Address: 0x1003e28 */
        {

          infoGridBmp[indx].lphTile[x + y * 32] = 0; /* Line 206, Address: 0x1003e70 */
        }
      } /* Line 208, Address: 0x1003eb0 */
    } /* Line 209, Address: 0x1003ec8 */
  }
} /* Line 211, Address: 0x1003ee0 */



void OEAllGridDelete(void) { /* Line 215, Address: 0x1003f00 */

  OEGridDelete(0); /* Line 217, Address: 0x1003f08 */
  OEGridDelete(1); /* Line 218, Address: 0x1003f14 */
  OEGridDelete(2); /* Line 219, Address: 0x1003f20 */
} /* Line 220, Address: 0x1003f2c */
