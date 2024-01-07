#include "..\..\TYPES.H"
#include "..\COMMON\SCORE_DATA_TYPES.H"
#include "..\COMMON\ENGINE_DLL.H"
#include "..\COMMON\HMX_TYPES.H"
#include "AVIOPNEN.H"

hmx_environment* g_env_module;
hmx_environment* g_loader_module;
#if defined(AVIOPEN)
char fileName[26] = "title\\bmp\\opnavi\\opwp.bmp";
#endif
#if defined(AVIPEN)
char fileName[27] = "title\\bmp\\opnavi\\penbg.bmp";
#endif
int nTimerCunt;
unsigned short nSequenceNum;
unsigned short wMCIDeviceID[1];
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
  &DLLInit,
  (void (*))&DLLMain,
  &DLLEnd,
  &SWdataSet,
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
unsigned int* lpbFullScreen;
unsigned int hWnd;

































void OESetSequenceNum(unsigned short num) { /* Line 115, Address: 0x10000b0 */
  nSequenceNum = num; /* Line 116, Address: 0x10000b8 */
  nTimerCunt = -1; /* Line 117, Address: 0x10000c4 */
} /* Line 118, Address: 0x10000d0 */




void DLLInit(engine_dll* lpDllIn, char*** pBufTbl, void** pFuncTbl) { /* Line 123, Address: 0x10000e0 */
  int n;


  ++pFuncTbl; /* Line 127, Address: 0x10000f4 */
  ++pFuncTbl; /* Line 128, Address: 0x1000100 */
  ++pFuncTbl; /* Line 129, Address: 0x100010c */
  ++pFuncTbl; /* Line 130, Address: 0x1000118 */
  ++pFuncTbl; /* Line 131, Address: 0x1000124 */
  ++pFuncTbl; /* Line 132, Address: 0x1000130 */
  ++pFuncTbl; /* Line 133, Address: 0x100013c */
  ++pFuncTbl; /* Line 134, Address: 0x1000148 */
  ++pFuncTbl; /* Line 135, Address: 0x1000154 */
  ++pFuncTbl; /* Line 136, Address: 0x1000160 */
  ++pFuncTbl; /* Line 137, Address: 0x100016c */

  sMemAlloc = *pFuncTbl++; /* Line 139, Address: 0x1000178 */
  sMemFree = *pFuncTbl++; /* Line 140, Address: 0x1000190 */
  ++pFuncTbl; /* Line 141, Address: 0x10001a8 */
  sMemCpy = *pFuncTbl++; /* Line 142, Address: 0x10001b4 */
  ++pFuncTbl; /* Line 143, Address: 0x10001cc */
  ++pFuncTbl; /* Line 144, Address: 0x10001d8 */
  ++pFuncTbl; /* Line 145, Address: 0x10001e4 */
  ++pFuncTbl; /* Line 146, Address: 0x10001f0 */
  ++pFuncTbl; /* Line 147, Address: 0x10001fc */
  sPrintf = *pFuncTbl++; /* Line 148, Address: 0x1000208 */
  sOutputDebugString = *pFuncTbl++; /* Line 149, Address: 0x1000220 */
  sOpenFile = *pFuncTbl++; /* Line 150, Address: 0x1000238 */
  sReadFile = *pFuncTbl++; /* Line 151, Address: 0x1000250 */
  sCloseFile = *pFuncTbl++; /* Line 152, Address: 0x1000268 */
  sGetFileSize = *pFuncTbl++; /* Line 153, Address: 0x1000280 */


  get_draw_context_module = *pFuncTbl++; /* Line 156, Address: 0x1000298 */
  FlipToScreen_module = *pFuncTbl++; /* Line 157, Address: 0x10002b0 */
  ld_bitmap_4to8_module = *pFuncTbl++; /* Line 158, Address: 0x10002c8 */
  ld_load_cmpfile_module = *pFuncTbl++; /* Line 159, Address: 0x10002e0 */
  hmx_background_set_background_module = *pFuncTbl++; /* Line 160, Address: 0x10002f8 */
  hmx_bitmap_create_module = *pFuncTbl++; /* Line 161, Address: 0x1000310 */
  hmx_bitmap_release_module = *pFuncTbl++; /* Line 162, Address: 0x1000328 */
  hmx_bitmap_get_scan0_module = *pFuncTbl++; /* Line 163, Address: 0x1000340 */
  hmx_bitmap_set_transparency_module = *pFuncTbl++; /* Line 164, Address: 0x1000358 */
  hmx_free_module = *pFuncTbl++; /* Line 165, Address: 0x1000370 */
  hmx_grid_create_module = *pFuncTbl++; /* Line 166, Address: 0x1000388 */
  hmx_grid_release_module = *pFuncTbl++; /* Line 167, Address: 0x10003a0 */
  hmx_grid_base_module = *pFuncTbl++; /* Line 168, Address: 0x10003b8 */
  hmx_grid_set_position_module = *pFuncTbl++; /* Line 169, Address: 0x10003d0 */
  hmx_grid_set_view_module = *pFuncTbl++; /* Line 170, Address: 0x10003e8 */
  hmx_grid_set_tile_module = *pFuncTbl++; /* Line 171, Address: 0x1000400 */
  hmx_grid_set_horz_offsets_module = *pFuncTbl++; /* Line 172, Address: 0x1000418 */
  hmx_renderer_context_add_module = *pFuncTbl++; /* Line 173, Address: 0x1000430 */
  hmx_renderer_context_clear_module = *pFuncTbl++; /* Line 174, Address: 0x1000448 */
  hmx_renderer_context_draw_module = *pFuncTbl++; /* Line 175, Address: 0x1000460 */
  hmx_sprite_base_module = *pFuncTbl++; /* Line 176, Address: 0x1000478 */
  hmx_sprite_set_position_module = *pFuncTbl++; /* Line 177, Address: 0x1000490 */
  hmx_sprite_set_bitmap_module = *pFuncTbl++; /* Line 178, Address: 0x10004a8 */
  hmx_sprite_set_flags_module = *pFuncTbl++; /* Line 179, Address: 0x10004c0 */

  hmx_ddagrid_create_module = *pFuncTbl++; /* Line 181, Address: 0x10004d8 */
  hmx_ddagrid_release_module = *pFuncTbl++; /* Line 182, Address: 0x10004f0 */
  hmx_ddagrid_set_scan_module = *pFuncTbl++; /* Line 183, Address: 0x1000508 */
  hmx_ddagrid_set_tile_module = *pFuncTbl++; /* Line 184, Address: 0x1000520 */

  ++pFuncTbl; /* Line 186, Address: 0x1000538 */
  sMoviePlay = *pFuncTbl++; /* Line 187, Address: 0x1000544 */
  sMovieStop = *pFuncTbl++; /* Line 188, Address: 0x100055c */
  sMovieStat = *pFuncTbl++; /* Line 189, Address: 0x1000574 */

  ++pBufTbl; /* Line 191, Address: 0x100058c */
  ++pBufTbl; /* Line 192, Address: 0x1000598 */
  ++pBufTbl; /* Line 193, Address: 0x10005a4 */
  ++pBufTbl; /* Line 194, Address: 0x10005b0 */
  ++pBufTbl; /* Line 195, Address: 0x10005bc */
  ++pBufTbl; /* Line 196, Address: 0x10005c8 */
  ++pBufTbl; /* Line 197, Address: 0x10005d4 */
  ++pBufTbl; /* Line 198, Address: 0x10005e0 */
  ++pBufTbl; /* Line 199, Address: 0x10005ec */
  ++pBufTbl; /* Line 200, Address: 0x10005f8 */
  ++pBufTbl; /* Line 201, Address: 0x1000604 */

  g_env_module = (hmx_environment*)**pBufTbl++; /* Line 203, Address: 0x1000610 */
  g_loader_module = (hmx_environment*)**pBufTbl++; /* Line 204, Address: 0x100062c */

  s_ctx = get_draw_context_module(); /* Line 206, Address: 0x1000648 */




  ReadDIB(fileName); /* Line 211, Address: 0x1000660 */
  nSequenceNum = 1; /* Line 212, Address: 0x1000670 */
  nTimerCunt = 0; /* Line 213, Address: 0x100067c */

  for (n = 0; n <= 0; ++n) { /* Line 215, Address: 0x1000684 */
    wMCIDeviceID[n] = 65535; /* Line 216, Address: 0x1000690 */
  } /* Line 217, Address: 0x10006a8 */
} /* Line 218, Address: 0x10006b4 */




void DLLEnd() { /* Line 223, Address: 0x10006d0 */
  FreeDIB(); /* Line 224, Address: 0x10006d8 */
  AVIEnd(); /* Line 225, Address: 0x10006e0 */

} /* Line 227, Address: 0x10006e8 */




void DLLPaint(unsigned int hdc) { /* Line 232, Address: 0x1000700 */
  AVIPaint(hdc); /* Line 233, Address: 0x100070c */
} /* Line 234, Address: 0x1000718 */



int DLLNotify() { /* Line 238, Address: 0x1000730 */




  return 0; /* Line 243, Address: 0x1000734 */
} /* Line 244, Address: 0x1000738 */




void DLLAVISizeChange() {} /* Line 249, Address: 0x1000750 */





void DLLAVIRealize() {} /* Line 255, Address: 0x1000760 */





























void AVIPause() {} /* Line 285, Address: 0x1000770 */













void AVIResume() {} /* Line 299, Address: 0x1000780 */




void SWdataSet(ushort_union sw1, ushort_union sw2) { /* Line 304, Address: 0x1000790 */
  swData1 = sw1.w; /* Line 305, Address: 0x100079c */
  swData2 = sw2.w; /* Line 306, Address: 0x10007a8 */

} /* Line 308, Address: 0x10007b4 */







int DLLMain() { /* Line 316, Address: 0x10007c0 */
  int ret = 0; /* Line 317, Address: 0x10007cc */

  if (nSequenceNum == 1) { /* Line 319, Address: 0x10007d0 */


    AVIOpeningMove(); /* Line 322, Address: 0x10007f0 */
  }

  if (nTimerCunt == 2147483647) /* Line 325, Address: 0x10007f8 */
    nTimerCunt = 5184000; /* Line 326, Address: 0x1000810 */
  else
    ++nTimerCunt; /* Line 328, Address: 0x1000828 */

#if defined(AVIOPEN)
  if (swData1 & 240) { /* Line 331, Address: 0x100083c */
    ret = 9; /* Line 332, Address: 0x1000854 */
  }
#endif

  return ret; /* Line 336, Address: 0x1000858 */
} /* Line 337, Address: 0x100085C */
