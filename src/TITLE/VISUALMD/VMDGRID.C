#include "..\..\TYPES.H"
#include "..\COMMON\HMX_TYPES.H"
#include "..\COMMON\GRID.H"

extern void(*hmx_grid_set_view_module)(hmx_grid*, int, int, int, int);
extern draw_context* s_ctx;
extern grid_bmp infoGridBmp[];
extern void(*hmx_grid_set_tile_module)(hmx_grid*, int, int, hmx_bitmap*, int);
extern hmx_grid*(*hmx_grid_create_module)(hmx_environment*, int, int, int, int);
extern hmx_environment* g_env_module;
extern void(*hmx_grid_release_module)(hmx_environment*, hmx_grid*);



















int OEGridCreate(unsigned short indx) { /* Line 31, Address: 0x1000d50 */
  tile_location loc;
  grid_rect rectwh;
  unsigned short x;
  unsigned short y;



  if (indx == 0) /* Line 39, Address: 0x1000d64 */
  {


    s_ctx->grids[indx] = hmx_grid_create_module(g_env_module, 8, 8, 40, 28); /* Line 43, Address: 0x1000d74 */
    *infoGridBmp[indx].lphGrid = (unsigned int)s_ctx->grids[indx]; /* Line 44, Address: 0x1000db8 */




    for (y = 0; y < 28; ++y) /* Line 49, Address: 0x1000dfc */
    {
      loc.nTile = y; /* Line 51, Address: 0x1000e08 */
      for (x = 0; x < 40; ++x) /* Line 52, Address: 0x1000e0c */
      {
        loc.mTile = x; /* Line 54, Address: 0x1000e18 */

        hmx_grid_set_tile_module(s_ctx->grids[indx], x, y, (hmx_bitmap*)*infoGridBmp[indx].lphBmp, 0); /* Line 56, Address: 0x1000e1c */
      } /* Line 57, Address: 0x1000e7c */
    } /* Line 58, Address: 0x1000e94 */




    rectwh.x = 0; /* Line 63, Address: 0x1000eac */
    rectwh.y = 0; /* Line 64, Address: 0x1000eb0 */
    rectwh.dx = infoGridBmp[indx].w * 40; /* Line 65, Address: 0x1000eb4 */
    rectwh.dy = infoGridBmp[indx].h * 28; /* Line 66, Address: 0x1000eec */

    hmx_grid_set_view_module(s_ctx->grids[indx], rectwh.x, rectwh.y, rectwh.dx, rectwh.dy); /* Line 68, Address: 0x1000f24 */
  }
  return 0; /* Line 70, Address: 0x1000f60 */
} /* Line 71, Address: 0x1000f64 */



void OEGridDelete(unsigned short indx) { /* Line 75, Address: 0x1000f80 */
  if (*infoGridBmp[indx].lphGrid != 0) /* Line 76, Address: 0x1000f8c */
  {

    hmx_grid_release_module(g_env_module, s_ctx->grids[indx]); /* Line 79, Address: 0x1000fbc */
    s_ctx->grids[indx] = 0; /* Line 80, Address: 0x1000ff0 */
    *infoGridBmp[indx].lphGrid = 0; /* Line 81, Address: 0x100100c */
  }


  if (indx == 0) /* Line 85, Address: 0x1001034 */
  {
    if (*infoGridBmp[indx].lphTile != 0) /* Line 87, Address: 0x1001044 */
    {

      *infoGridBmp[indx].lphTile = 0; /* Line 90, Address: 0x1001074 */
    }
  }
} /* Line 93, Address: 0x100109c */



void OEAllGridDelete(void) { /* Line 97, Address: 0x10010b0 */
  OEGridDelete(0); /* Line 98, Address: 0x10010b8 */
} /* Line 99, Address: 0x10010c4 */
