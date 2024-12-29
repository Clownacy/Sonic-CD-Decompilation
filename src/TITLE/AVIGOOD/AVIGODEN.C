#include "..\..\TYPES.H"
#include "..\COMMON\SCORE_DATA_TYPES.H"
#include "..\COMMON\ENGINE_DLL.H"
#include "..\COMMON\HMX_TYPES.H"
#include "AVIGODEN.H"
#include "AVIGODDO.H"

hmx_environment* g_env_module;
hmx_environment* g_loader_module;
int nTimerCunt;
unsigned short nSequenceNum;
unsigned int* lpbFullScreen;
unsigned int hWnd;
PALETTEENTRY* lpColorwk;
draw_context* s_ctx;
draw_context*(*get_draw_context_module)();
int(*sMovieStat)();
int(*sMovieStop)();
int(*sMoviePlay)(int);
void(*hmx_ddagrid_set_tile_module)(hmx_ddagrid*, int, int, hmx_bitmap*, int);
void(*hmx_ddagrid_set_scan_module)(hmx_ddagrid*, int, int, int, int, int);
void(*hmx_ddagrid_release_module)(hmx_environment*, hmx_ddagrid*);
hmx_ddagrid*(*hmx_ddagrid_create_module)(hmx_environment*, int, int, int, int, int, int);
void(*hmx_sprite_set_flags_module)(hmx_sprite*, int);
void(*hmx_sprite_set_bitmap_module)(hmx_sprite*, hmx_bitmap*);
void(*hmx_sprite_set_position_module)(hmx_sprite*, int, int);
hmx_renderer_base*(*hmx_sprite_base_module)(hmx_sprite*);
void(*hmx_renderer_context_draw_module)(hmx_renderer_context*, hmx_surface*);
void(*hmx_renderer_context_clear_module)(hmx_renderer_context*);
void(*hmx_renderer_context_add_module)(hmx_renderer_context*, int, hmx_renderer_base*);
void(*hmx_grid_set_horz_offsets_module)(hmx_grid*, int*);
void(*hmx_grid_set_tile_module)(hmx_grid*, int, int, hmx_bitmap*, int);
void(*hmx_grid_set_view_module)(hmx_grid*, int, int, int, int);
void(*hmx_grid_set_position_module)(hmx_grid*, int, int);
hmx_renderer_base*(*hmx_grid_base_module)(hmx_grid*);
void(*hmx_grid_release_module)(hmx_environment*, hmx_grid*);
hmx_grid*(*hmx_grid_create_module)(hmx_environment*, int, int, int, int);
void(*hmx_free_module)(hmx_environment*, void*);
void(*hmx_bitmap_set_transparency_module)(hmx_bitmap*, int);
void*(*hmx_bitmap_get_scan0_module)(hmx_bitmap*);
void(*hmx_bitmap_release_module)(hmx_environment*, hmx_bitmap*);
hmx_bitmap*(*hmx_bitmap_create_module)(hmx_environment*, int, int);
void(*hmx_background_set_background_module)(hmx_background*, int);
void*(*ld_load_cmpfile_module)(hmx_environment*, char*);
void(*ld_bitmap_4to8_module)(void*, void*, int, int, int, int, int);
void(*FlipToScreen_module)();
int(*sGetFileSize)(int);
void(*sCloseFile)(int);
int(*sReadFile)(int, void*, int);
int(*sOpenFile)(char*);
void(*sOutputDebugString)(char*);
void(*sPrintf)(char*, const char*, ...);
void(*sMemCpy)(void*, void*, int);
void(*sMemFree)(void*);
void*(*sMemAlloc)(int);
unsigned short swData2;
unsigned short swData1;
dlink_export ExportedFunctions = {
  (void (*)())&DLLInit,
  (void (*)())&DLLMain,
  (void (*)(char***, void**))&DLLEnd,
  (void (*)())&SWdataSet,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0
};
unsigned int(*WriteIndx)(int, unsigned int);
int(*ReadIndx)(unsigned int);
unsigned int(*CreateScore)();
unsigned int(*CloseScore)(unsigned int);
unsigned int(*OpenScore)(int);
unsigned int(*WriteScore)(int, char*, unsigned int);
unsigned int(*ReadScore)(int, char*, unsigned int);
void(*WaveRequest)(short);
void(*CDPause)();
void(*CDPlay)(short);































void OESetSequenceNum(unsigned short num) { /* Line 113, Address: 0x1000220 */
  nSequenceNum = num; /* Line 114, Address: 0x1000228 */
  nTimerCunt = -1; /* Line 115, Address: 0x1000234 */
} /* Line 116, Address: 0x1000240 */




void DLLInit(engine_dll* lpDllIn, char*** pBufTbl, void** pFuncTbl) { /* Line 121, Address: 0x1000250 */



  ++pFuncTbl; /* Line 125, Address: 0x1000264 */
  ++pFuncTbl; /* Line 126, Address: 0x1000270 */
  ++pFuncTbl; /* Line 127, Address: 0x100027c */
  ++pFuncTbl; /* Line 128, Address: 0x1000288 */
  ++pFuncTbl; /* Line 129, Address: 0x1000294 */
  ++pFuncTbl; /* Line 130, Address: 0x10002a0 */
  ++pFuncTbl; /* Line 131, Address: 0x10002ac */
  ++pFuncTbl; /* Line 132, Address: 0x10002b8 */
  ++pFuncTbl; /* Line 133, Address: 0x10002c4 */
  ++pFuncTbl; /* Line 134, Address: 0x10002d0 */
  ++pFuncTbl; /* Line 135, Address: 0x10002dc */

  sMemAlloc = *pFuncTbl++; /* Line 137, Address: 0x10002e8 */
  sMemFree = *pFuncTbl++; /* Line 138, Address: 0x1000300 */
  ++pFuncTbl; /* Line 139, Address: 0x1000318 */
  sMemCpy = *pFuncTbl++; /* Line 140, Address: 0x1000324 */
  ++pFuncTbl; /* Line 141, Address: 0x100033c */
  ++pFuncTbl; /* Line 142, Address: 0x1000348 */
  ++pFuncTbl; /* Line 143, Address: 0x1000354 */
  ++pFuncTbl; /* Line 144, Address: 0x1000360 */
  ++pFuncTbl; /* Line 145, Address: 0x100036c */
  sPrintf = *pFuncTbl++; /* Line 146, Address: 0x1000378 */
  sOutputDebugString = *pFuncTbl++; /* Line 147, Address: 0x1000390 */
  sOpenFile = *pFuncTbl++; /* Line 148, Address: 0x10003a8 */
  sReadFile = *pFuncTbl++; /* Line 149, Address: 0x10003c0 */
  sCloseFile = *pFuncTbl++; /* Line 150, Address: 0x10003d8 */
  sGetFileSize = *pFuncTbl++; /* Line 151, Address: 0x10003f0 */


  get_draw_context_module = *pFuncTbl++; /* Line 154, Address: 0x1000408 */
  FlipToScreen_module = *pFuncTbl++; /* Line 155, Address: 0x1000420 */
  ld_bitmap_4to8_module = *pFuncTbl++; /* Line 156, Address: 0x1000438 */
  ld_load_cmpfile_module = *pFuncTbl++; /* Line 157, Address: 0x1000450 */
  hmx_background_set_background_module = *pFuncTbl++; /* Line 158, Address: 0x1000468 */
  hmx_bitmap_create_module = *pFuncTbl++; /* Line 159, Address: 0x1000480 */
  hmx_bitmap_release_module = *pFuncTbl++; /* Line 160, Address: 0x1000498 */
  hmx_bitmap_get_scan0_module = *pFuncTbl++; /* Line 161, Address: 0x10004b0 */
  hmx_bitmap_set_transparency_module = *pFuncTbl++; /* Line 162, Address: 0x10004c8 */
  hmx_free_module = *pFuncTbl++; /* Line 163, Address: 0x10004e0 */
  hmx_grid_create_module = *pFuncTbl++; /* Line 164, Address: 0x10004f8 */
  hmx_grid_release_module = *pFuncTbl++; /* Line 165, Address: 0x1000510 */
  hmx_grid_base_module = *pFuncTbl++; /* Line 166, Address: 0x1000528 */
  hmx_grid_set_position_module = *pFuncTbl++; /* Line 167, Address: 0x1000540 */
  hmx_grid_set_view_module = *pFuncTbl++; /* Line 168, Address: 0x1000558 */
  hmx_grid_set_tile_module = *pFuncTbl++; /* Line 169, Address: 0x1000570 */
  hmx_grid_set_horz_offsets_module = *pFuncTbl++; /* Line 170, Address: 0x1000588 */
  hmx_renderer_context_add_module = *pFuncTbl++; /* Line 171, Address: 0x10005a0 */
  hmx_renderer_context_clear_module = *pFuncTbl++; /* Line 172, Address: 0x10005b8 */
  hmx_renderer_context_draw_module = *pFuncTbl++; /* Line 173, Address: 0x10005d0 */
  hmx_sprite_base_module = *pFuncTbl++; /* Line 174, Address: 0x10005e8 */
  hmx_sprite_set_position_module = *pFuncTbl++; /* Line 175, Address: 0x1000600 */
  hmx_sprite_set_bitmap_module = *pFuncTbl++; /* Line 176, Address: 0x1000618 */
  hmx_sprite_set_flags_module = *pFuncTbl++; /* Line 177, Address: 0x1000630 */

  hmx_ddagrid_create_module = *pFuncTbl++; /* Line 179, Address: 0x1000648 */
  hmx_ddagrid_release_module = *pFuncTbl++; /* Line 180, Address: 0x1000660 */
  hmx_ddagrid_set_scan_module = *pFuncTbl++; /* Line 181, Address: 0x1000678 */
  hmx_ddagrid_set_tile_module = *pFuncTbl++; /* Line 182, Address: 0x1000690 */

  ++pFuncTbl; /* Line 184, Address: 0x10006a8 */
  sMoviePlay = *pFuncTbl++; /* Line 185, Address: 0x10006b4 */
  sMovieStop = *pFuncTbl++; /* Line 186, Address: 0x10006cc */
  sMovieStat = *pFuncTbl++; /* Line 187, Address: 0x10006e4 */

  ++pBufTbl; /* Line 189, Address: 0x10006fc */
  ++pBufTbl; /* Line 190, Address: 0x1000708 */
  ++pBufTbl; /* Line 191, Address: 0x1000714 */
  ++pBufTbl; /* Line 192, Address: 0x1000720 */
  ++pBufTbl; /* Line 193, Address: 0x100072c */
  ++pBufTbl; /* Line 194, Address: 0x1000738 */
  ++pBufTbl; /* Line 195, Address: 0x1000744 */
  ++pBufTbl; /* Line 196, Address: 0x1000750 */
  ++pBufTbl; /* Line 197, Address: 0x100075c */
  ++pBufTbl; /* Line 198, Address: 0x1000768 */
  ++pBufTbl; /* Line 199, Address: 0x1000774 */

  g_env_module = (hmx_environment*)**pBufTbl++; /* Line 201, Address: 0x1000780 */
  g_loader_module = (hmx_environment*)**pBufTbl++; /* Line 202, Address: 0x100079c */

  s_ctx = get_draw_context_module(); /* Line 204, Address: 0x10007b8 */

  lpColorwk = lpDllIn->lpColorwk; /* Line 206, Address: 0x10007d0 */

  hWnd = lpDllIn->hWnd; /* Line 208, Address: 0x10007e0 */
  lpbFullScreen = lpDllIn->lpbFullScreen; /* Line 209, Address: 0x10007f0 */
  ReadDIB(); /* Line 210, Address: 0x1000800 */
  nSequenceNum = 1; /* Line 211, Address: 0x1000808 */
  nTimerCunt = 0; /* Line 212, Address: 0x1000814 */
} /* Line 213, Address: 0x100081c */




void DLLEnd() { /* Line 218, Address: 0x1000830 */
  FreeDIB(); /* Line 219, Address: 0x1000838 */
  AVIEnd(); /* Line 220, Address: 0x1000840 */

} /* Line 222, Address: 0x1000848 */






void SWdataSet(ushort_union sw1, ushort_union sw2) { /* Line 229, Address: 0x1000860 */
  swData1 = sw1.w; /* Line 230, Address: 0x100086c */
  swData2 = sw2.w; /* Line 231, Address: 0x1000878 */

} /* Line 233, Address: 0x1000884 */








int DLLMain() { /* Line 242, Address: 0x1000890 */
  int ret = 0; /* Line 243, Address: 0x100089c */

  switch (nSequenceNum) { /* Line 245, Address: 0x10008a0 */

    case 1:
      AVIOpeningMove(); /* Line 248, Address: 0x10008d8 */
      break; /* Line 249, Address: 0x10008e0 */
    case 2:
      AVIEndWait(); /* Line 251, Address: 0x10008e8 */
      break; /* Line 252, Address: 0x10008f0 */
    case 3:
      ret = AVIEndKeyWait(); /* Line 254, Address: 0x10008f8 */
  }


  if (nTimerCunt == 0x7FFFFFFF) /* Line 258, Address: 0x1000904 */
    nTimerCunt = 5184000; /* Line 259, Address: 0x100091c */
  else
    ++nTimerCunt; /* Line 261, Address: 0x1000934 */

  return ret; /* Line 263, Address: 0x1000948 */
} /* Line 264, Address: 0x100094c */
