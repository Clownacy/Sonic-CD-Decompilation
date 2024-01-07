#include "..\..\TYPES.H"
#include "..\COMMON\HMX_TYPES.H"
#include "..\COMMON\GRID.H"

extern void(*hmx_grid_set_view_module)(hmx_grid*, int, int, int, int);
extern draw_context* s_ctx;
extern grid_bmp infoGridBmp[];
extern void(*hmx_grid_set_position_module)(hmx_grid*, int, int);
extern void(*hmx_grid_set_tile_module)(hmx_grid*, int, int, hmx_bitmap*, int);
extern hmx_grid*(*hmx_grid_create_module)(hmx_environment*, int, int, int, int);
extern hmx_environment* g_env_module;
extern unsigned short IDX_GDBMP_BACK;
extern void(*hmx_grid_release_module)(hmx_environment*, hmx_grid*);















int OEGridCreate(unsigned short indx) { /* Line 29, Address: 0x10020d0 */
  tile_location loc;
  grid_rect rectwh;
  unsigned short x;
  unsigned short y;



  if (indx == IDX_GDBMP_BACK) /* Line 37, Address: 0x10020e4 */
  {


    s_ctx->grids[indx] = hmx_grid_create_module(g_env_module, 8, 8, 40, 28); /* Line 41, Address: 0x1002100 */
    *infoGridBmp[indx].lphGrid = (unsigned int)s_ctx->grids[indx]; /* Line 42, Address: 0x1002144 */




    for (y = 0; y < 28; ++y) /* Line 47, Address: 0x1002188 */
    {
      loc.nTile = y; /* Line 49, Address: 0x1002194 */
      for (x = 0; x < 40; ++x) /* Line 50, Address: 0x1002198 */
      {
        loc.mTile = x; /* Line 52, Address: 0x10021a4 */

        hmx_grid_set_tile_module(s_ctx->grids[indx], x, y, (hmx_bitmap*)*infoGridBmp[indx].lphBmp, 0); /* Line 54, Address: 0x10021a8 */
      } /* Line 55, Address: 0x1002208 */
    } /* Line 56, Address: 0x1002220 */


    hmx_grid_set_position_module(s_ctx->grids[indx], infoGridBmp[indx].point.x, infoGridBmp[indx].point.y); /* Line 59, Address: 0x1002238 */

    rectwh.x = 0; /* Line 61, Address: 0x10022ac */
    rectwh.y = 0; /* Line 62, Address: 0x10022b0 */
    rectwh.dx = infoGridBmp[indx].w * 40; /* Line 63, Address: 0x10022b4 */
    rectwh.dy = infoGridBmp[indx].h * 28; /* Line 64, Address: 0x10022ec */

    hmx_grid_set_view_module(s_ctx->grids[indx], rectwh.x, rectwh.y, rectwh.dx, rectwh.dy); /* Line 66, Address: 0x1002324 */
  }
  return 0; /* Line 68, Address: 0x1002360 */
} /* Line 69, Address: 0x1002364 */



void OEGridDelete(unsigned short indx) { /* Line 73, Address: 0x1002380 */
  if (*infoGridBmp[indx].lphGrid != 0) /* Line 74, Address: 0x100238c */
  {
  
    hmx_grid_release_module(g_env_module, s_ctx->grids[indx]); /* Line 77, Address: 0x10023bc */
    s_ctx->grids[indx] = 0; /* Line 78, Address: 0x10023f0 */
    *infoGridBmp[indx].lphGrid = 0; /* Line 79, Address: 0x100240c */
  }


  if (indx == IDX_GDBMP_BACK) /* Line 83, Address: 0x1002434 */
  {
    if (*infoGridBmp[indx].lphTile != 0) /* Line 85, Address: 0x1002450 */
    {

      *infoGridBmp[indx].lphTile = 0; /* Line 88, Address: 0x1002480 */
    }
  }
} /* Line 91, Address: 0x10024a8 */



void OEAllGridDelete() { /* Line 95, Address: 0x10024c0 */
  OEGridDelete(IDX_GDBMP_BACK); /* Line 96, Address: 0x10024c8 */










} /* Line 107, Address: 0x10024d8 */
