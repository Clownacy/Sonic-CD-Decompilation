#include "..\..\TYPES.H"
#include "..\COMMON\SCORE_DATA_TYPES.H"
#include "..\COMMON\ENGINE_DLL.H"
#include "..\COMMON\HMX_TYPES.H"
#include "STGENTRY.H"
#include "..\COMMON\HMX_OEEACTL.H"
#include "..\COMMON\PALT.H"
#include "STGDO.H"
#include "STGSPRT.H"

static void STGWait();

hmx_environment* g_env_module;
hmx_environment* g_loader_module;
int nTimerCunt;
unsigned short nSequenceNum;
static int nWaitTime;
static unsigned short nSaveSequenceNum;
static unsigned int bWaitKeyOff;
unsigned short swData1;
extern PALETTEENTRY tblPal4[];
extern PALETTEENTRY tblPal3[];
extern PALETTEENTRY tblPal2[];
extern PALETTEENTRY tblPal1[];
unsigned short* lpSelectedStage;
PALETTEENTRY* lpColorwk;
unsigned int hSurf;
unsigned int hWnd;
draw_context* s_ctx;
draw_context*(*get_draw_context_module)();
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





























void OESetSequenceNum(unsigned short num) { /* Line 111, Address: 0x1000000 */
  nSequenceNum = num; /* Line 112, Address: 0x1000008 */
  nTimerCunt = -1; /* Line 113, Address: 0x1000014 */
} /* Line 114, Address: 0x1000020 */




void KeyWait() { /* Line 119, Address: 0x1000030 */
  nSaveSequenceNum = nSequenceNum; /* Line 120, Address: 0x1000038 */
  nWaitTime = 6; /* Line 121, Address: 0x1000048 */
  OESetSequenceNum(3); /* Line 122, Address: 0x1000054 */
} /* Line 123, Address: 0x1000060 */




void WaitKeyOff() { /* Line 128, Address: 0x1000070 */
  nSaveSequenceNum = nSequenceNum; /* Line 129, Address: 0x1000078 */
  bWaitKeyOff = 1; /* Line 130, Address: 0x1000088 */
  nWaitTime = 0; /* Line 131, Address: 0x1000094 */
  OESetSequenceNum(3); /* Line 132, Address: 0x100009c */
} /* Line 133, Address: 0x10000a8 */




void Wait(int time) { /* Line 138, Address: 0x10000c0 */
  nSaveSequenceNum = nSequenceNum; /* Line 139, Address: 0x10000cc */
  bWaitKeyOff = 0; /* Line 140, Address: 0x10000dc */
  nWaitTime = time; /* Line 141, Address: 0x10000e4 */
  OESetSequenceNum(3); /* Line 142, Address: 0x10000f0 */
} /* Line 143, Address: 0x10000fc */




static void STGWait() { /* Line 148, Address: 0x1000110 */
  if (bWaitKeyOff == 0 && nTimerCunt > nWaitTime) /* Line 149, Address: 0x1000118 */
  {
    OESetSequenceNum(nSaveSequenceNum); /* Line 151, Address: 0x1000144 */
  }
  if (bWaitKeyOff != 0) /* Line 153, Address: 0x1000154 */
  {
    if (swData1 == 0) bWaitKeyOff = 0; /* Line 155, Address: 0x1000164 */
  }
} /* Line 157, Address: 0x1000180 */




void DLLInit(engine_dll* lpDllIn, char*** pBufTbl, void** pFuncTbl) { /* Line 162, Address: 0x1000190 */

  ++pFuncTbl; /* Line 164, Address: 0x10001a4 */
  ++pFuncTbl; /* Line 165, Address: 0x10001b0 */
  ++pFuncTbl; /* Line 166, Address: 0x10001bc */
  ++pFuncTbl; /* Line 167, Address: 0x10001c8 */
  ++pFuncTbl; /* Line 168, Address: 0x10001d4 */
  ++pFuncTbl; /* Line 169, Address: 0x10001e0 */
  ++pFuncTbl; /* Line 170, Address: 0x10001ec */
  ++pFuncTbl; /* Line 171, Address: 0x10001f8 */
  ++pFuncTbl; /* Line 172, Address: 0x1000204 */
  ++pFuncTbl; /* Line 173, Address: 0x1000210 */
  ++pFuncTbl; /* Line 174, Address: 0x100021c */

  sMemAlloc = *pFuncTbl++; /* Line 176, Address: 0x1000228 */
  sMemFree = *pFuncTbl++; /* Line 177, Address: 0x1000240 */
  ++pFuncTbl; /* Line 178, Address: 0x1000258 */
  sMemCpy = *pFuncTbl++; /* Line 179, Address: 0x1000264 */
  ++pFuncTbl; /* Line 180, Address: 0x100027c */
  ++pFuncTbl; /* Line 181, Address: 0x1000288 */
  ++pFuncTbl; /* Line 182, Address: 0x1000294 */
  ++pFuncTbl; /* Line 183, Address: 0x10002a0 */
  ++pFuncTbl; /* Line 184, Address: 0x10002ac */
  sPrintf = *pFuncTbl++; /* Line 185, Address: 0x10002b8 */
  sOutputDebugString = *pFuncTbl++; /* Line 186, Address: 0x10002d0 */
  sOpenFile = *pFuncTbl++; /* Line 187, Address: 0x10002e8 */
  sReadFile = *pFuncTbl++; /* Line 188, Address: 0x1000300 */
  sCloseFile = *pFuncTbl++; /* Line 189, Address: 0x1000318 */
  sGetFileSize = *pFuncTbl++; /* Line 190, Address: 0x1000330 */


  get_draw_context_module = *pFuncTbl++; /* Line 193, Address: 0x1000348 */
  FlipToScreen_module = *pFuncTbl++; /* Line 194, Address: 0x1000360 */
  ld_bitmap_4to8_module = *pFuncTbl++; /* Line 195, Address: 0x1000378 */
  ld_load_cmpfile_module = *pFuncTbl++; /* Line 196, Address: 0x1000390 */
  hmx_background_set_background_module = *pFuncTbl++; /* Line 197, Address: 0x10003a8 */
  hmx_bitmap_create_module = *pFuncTbl++; /* Line 198, Address: 0x10003c0 */
  hmx_bitmap_release_module = *pFuncTbl++; /* Line 199, Address: 0x10003d8 */
  hmx_bitmap_get_scan0_module = *pFuncTbl++; /* Line 200, Address: 0x10003f0 */
  hmx_bitmap_set_transparency_module = *pFuncTbl++; /* Line 201, Address: 0x1000408 */
  hmx_free_module = *pFuncTbl++; /* Line 202, Address: 0x1000420 */
  hmx_grid_create_module = *pFuncTbl++; /* Line 203, Address: 0x1000438 */
  hmx_grid_release_module = *pFuncTbl++; /* Line 204, Address: 0x1000450 */
  hmx_grid_base_module = *pFuncTbl++; /* Line 205, Address: 0x1000468 */
  hmx_grid_set_position_module = *pFuncTbl++; /* Line 206, Address: 0x1000480 */
  hmx_grid_set_view_module = *pFuncTbl++; /* Line 207, Address: 0x1000498 */
  hmx_grid_set_tile_module = *pFuncTbl++; /* Line 208, Address: 0x10004b0 */
  hmx_grid_set_horz_offsets_module = *pFuncTbl++; /* Line 209, Address: 0x10004c8 */
  hmx_renderer_context_add_module = *pFuncTbl++; /* Line 210, Address: 0x10004e0 */
  hmx_renderer_context_clear_module = *pFuncTbl++; /* Line 211, Address: 0x10004f8 */
  hmx_renderer_context_draw_module = *pFuncTbl++; /* Line 212, Address: 0x1000510 */
  hmx_sprite_base_module = *pFuncTbl++; /* Line 213, Address: 0x1000528 */
  hmx_sprite_set_position_module = *pFuncTbl++; /* Line 214, Address: 0x1000540 */
  hmx_sprite_set_bitmap_module = *pFuncTbl++; /* Line 215, Address: 0x1000558 */
  hmx_sprite_set_flags_module = *pFuncTbl++; /* Line 216, Address: 0x1000570 */

  hmx_ddagrid_create_module = *pFuncTbl++; /* Line 218, Address: 0x1000588 */
  hmx_ddagrid_release_module = *pFuncTbl++; /* Line 219, Address: 0x10005a0 */
  hmx_ddagrid_set_scan_module = *pFuncTbl++; /* Line 220, Address: 0x10005b8 */
  hmx_ddagrid_set_tile_module = *pFuncTbl++; /* Line 221, Address: 0x10005d0 */

  ++pBufTbl; /* Line 223, Address: 0x10005e8 */
  ++pBufTbl; /* Line 224, Address: 0x10005f4 */
  ++pBufTbl; /* Line 225, Address: 0x1000600 */
  ++pBufTbl; /* Line 226, Address: 0x100060c */
  ++pBufTbl; /* Line 227, Address: 0x1000618 */
  ++pBufTbl; /* Line 228, Address: 0x1000624 */
  ++pBufTbl; /* Line 229, Address: 0x1000630 */
  ++pBufTbl; /* Line 230, Address: 0x100063c */
  ++pBufTbl; /* Line 231, Address: 0x1000648 */
  ++pBufTbl; /* Line 232, Address: 0x1000654 */
  ++pBufTbl; /* Line 233, Address: 0x1000660 */

  g_env_module = (hmx_environment*)**pBufTbl++; /* Line 235, Address: 0x100066c */
  g_loader_module = (hmx_environment*)**pBufTbl++; /* Line 236, Address: 0x1000688 */

  s_ctx = get_draw_context_module(); /* Line 238, Address: 0x10006a4 */

  hWnd = lpDllIn->hWnd; /* Line 240, Address: 0x10006bc */
  hSurf = lpDllIn->hSurf; /* Line 241, Address: 0x10006cc */
  lpColorwk = lpDllIn->lpColorwk; /* Line 242, Address: 0x10006dc */
  lpSelectedStage = lpDllIn->lpSelectedStage; /* Line 243, Address: 0x10006ec */

  OEClrset(tblPal1, 0); /* Line 245, Address: 0x10006fc */
  OEClrset(tblPal2, 1); /* Line 246, Address: 0x1000710 */
  OEClrset(tblPal3, 2); /* Line 247, Address: 0x1000724 */
  OEClrset(tblPal4, 3); /* Line 248, Address: 0x1000738 */



  OECreateEA(); /* Line 252, Address: 0x100074c */
  nSequenceNum = 1; /* Line 253, Address: 0x1000754 */
  nTimerCunt = 0; /* Line 254, Address: 0x1000760 */
} /* Line 255, Address: 0x1000768 */




void DLLEnd() { /* Line 260, Address: 0x1000780 */
  OEDeleteEA(); /* Line 261, Address: 0x1000788 */
  DeleteAllCharSprt(); /* Line 262, Address: 0x1000790 */

} /* Line 264, Address: 0x1000798 */




void SWdataSet(ushort_union sw1, ushort_union sw2) { /* Line 269, Address: 0x10007b0 */
  swData1 = sw1.w; /* Line 270, Address: 0x10007bc */
  swData2 = sw2.w; /* Line 271, Address: 0x10007c8 */


} /* Line 274, Address: 0x10007d4 */




int DLLMain() { /* Line 279, Address: 0x10007e0 */
  int ret = 0; /* Line 280, Address: 0x10007ec */

  switch (nSequenceNum) /* Line 282, Address: 0x10007f0 */
  {
    case 1:
      STGStart(); /* Line 285, Address: 0x1000840 */
      break; /* Line 286, Address: 0x1000848 */

    case 2:
      STGMenu(); /* Line 289, Address: 0x1000850 */
      break; /* Line 290, Address: 0x1000858 */

    case 3:
      STGWait(); /* Line 293, Address: 0x1000860 */
      break; /* Line 294, Address: 0x1000868 */

    case 999:
      ret = STGEnd(); /* Line 297, Address: 0x1000870 */
      break; /* Line 298, Address: 0x100087c */
    case 998:
      ret = STGEnd2(); /* Line 300, Address: 0x1000884 */
      break;
  }

  if (nTimerCunt == 0x7FFFFFFF) /* Line 304, Address: 0x1000890 */
    nTimerCunt = 5184000; /* Line 305, Address: 0x10008a8 */
  else
    ++nTimerCunt; /* Line 307, Address: 0x10008c0 */

  STGDraw(); /* Line 309, Address: 0x10008d4 */
  return ret; /* Line 310, Address: 0x10008dc */
} /* Line 311, Address: 0x10008e0 */
