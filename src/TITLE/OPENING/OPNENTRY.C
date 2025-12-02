#include "..\..\TYPES.H"
#include "..\COMMON\SCORE_DATA_TYPES.H"
#include "..\COMMON\ENGINE_DLL.H"
#include "..\COMMON\HMX_TYPES.H"
#include "OPNENTRY.H"
#include "..\COMMON\HMX_OEEACTL.H"
#include "..\COMMON\PALT.H"
#include "OPNDO.H"

hmx_environment* g_env_module;
hmx_environment* g_loader_module;
int nTimerCunt;
unsigned short nSequenceNum;
extern PALETTEENTRY tblPal4[];
extern PALETTEENTRY tblPal3[];
extern PALETTEENTRY tblPal2[];
extern PALETTEENTRY tblPal1[];
draw_context* s_ctx;
draw_context*(*get_draw_context_module)(void);
unsigned short* lpUserKey;
unsigned int bFirstTitle;
unsigned int(*WriteIndx)(int, unsigned int);
int(*ReadIndx)(unsigned int);
unsigned int(*CreateScore)(void);
unsigned int(*CloseScore)(unsigned int);
unsigned int(*OpenScore)(int);
unsigned int(*WriteScore)(int, char*, unsigned int);
unsigned int(*ReadScore)(int, char*, unsigned int);
void(*WaveRequest)(short);
void(*CDPause)(void);
void(*CDPlay)(short);
unsigned int selectIndx;
void(*sMemCpy)(void*, void*, int);
score_data crntScorData;
unsigned int* lpbFullScreen;
PALETTEENTRY* lpColorwk;
unsigned int hSurf;
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
void(*FlipToScreen_module)(void);
int(*sGetFileSize)(int);
void(*sCloseFile)(int);
int(*sReadFile)(int, void*, int);
int(*sOpenFile)(char*);
void(*sOutputDebugString)(char*);
void(*sPrintf)(char*, char*);
void(*sMemFree)(void*);
void*(*sMemAlloc)(int);
unsigned short swData2;
unsigned short swData1;
dlink_export ExportedFunctions = {
  (void (*)(void))&DLLInit,
  (void (*)(void))&DLLMain,
  (void (*)(char***, void**))&DLLEnd,
  (void (*)(void))&SWdataSet,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0
};
unsigned int hWnd;
























































void OESetSequenceNum(unsigned short num) { /* Line 146, Address: 0x1002aa0 */
  nSequenceNum = num; /* Line 147, Address: 0x1002aa8 */
  nTimerCunt = -1; /* Line 148, Address: 0x1002ab4 */
} /* Line 149, Address: 0x1002ac0 */




void DLLInit(engine_dll* lpDllIn, char*** pBufTbl, void** pFuncTbl) { /* Line 154, Address: 0x1002ad0 */






  ++pFuncTbl; /* Line 161, Address: 0x1002ae4 */
  ++pFuncTbl; /* Line 162, Address: 0x1002af0 */
  ++pFuncTbl; /* Line 163, Address: 0x1002afc */
  ++pFuncTbl; /* Line 164, Address: 0x1002b08 */
  ++pFuncTbl; /* Line 165, Address: 0x1002b14 */
  ++pFuncTbl; /* Line 166, Address: 0x1002b20 */
  ++pFuncTbl; /* Line 167, Address: 0x1002b2c */
  ++pFuncTbl; /* Line 168, Address: 0x1002b38 */
  ++pFuncTbl; /* Line 169, Address: 0x1002b44 */
  ++pFuncTbl; /* Line 170, Address: 0x1002b50 */
  ++pFuncTbl; /* Line 171, Address: 0x1002b5c */

  sMemAlloc = *pFuncTbl++; /* Line 173, Address: 0x1002b68 */
  sMemFree = *pFuncTbl++; /* Line 174, Address: 0x1002b80 */
  ++pFuncTbl; /* Line 175, Address: 0x1002b98 */
  sMemCpy = *pFuncTbl++; /* Line 176, Address: 0x1002ba4 */
  ++pFuncTbl; /* Line 177, Address: 0x1002bbc */
  ++pFuncTbl; /* Line 178, Address: 0x1002bc8 */
  ++pFuncTbl; /* Line 179, Address: 0x1002bd4 */
  ++pFuncTbl; /* Line 180, Address: 0x1002be0 */
  ++pFuncTbl; /* Line 181, Address: 0x1002bec */
  sPrintf = *pFuncTbl++; /* Line 182, Address: 0x1002bf8 */
  sOutputDebugString = *pFuncTbl++; /* Line 183, Address: 0x1002c10 */
  sOpenFile = *pFuncTbl++; /* Line 184, Address: 0x1002c28 */
  sReadFile = *pFuncTbl++; /* Line 185, Address: 0x1002c40 */
  sCloseFile = *pFuncTbl++; /* Line 186, Address: 0x1002c58 */
  sGetFileSize = *pFuncTbl++; /* Line 187, Address: 0x1002c70 */


  get_draw_context_module = *pFuncTbl++; /* Line 190, Address: 0x1002c88 */
  FlipToScreen_module = *pFuncTbl++; /* Line 191, Address: 0x1002ca0 */
  ld_bitmap_4to8_module = *pFuncTbl++; /* Line 192, Address: 0x1002cb8 */
  ld_load_cmpfile_module = *pFuncTbl++; /* Line 193, Address: 0x1002cd0 */
  hmx_background_set_background_module = *pFuncTbl++; /* Line 194, Address: 0x1002ce8 */
  hmx_bitmap_create_module = *pFuncTbl++; /* Line 195, Address: 0x1002d00 */
  hmx_bitmap_release_module = *pFuncTbl++; /* Line 196, Address: 0x1002d18 */
  hmx_bitmap_get_scan0_module = *pFuncTbl++; /* Line 197, Address: 0x1002d30 */
  hmx_bitmap_set_transparency_module = *pFuncTbl++; /* Line 198, Address: 0x1002d48 */
  hmx_free_module = *pFuncTbl++; /* Line 199, Address: 0x1002d60 */
  hmx_grid_create_module = *pFuncTbl++; /* Line 200, Address: 0x1002d78 */
  hmx_grid_release_module = *pFuncTbl++; /* Line 201, Address: 0x1002d90 */
  hmx_grid_base_module = *pFuncTbl++; /* Line 202, Address: 0x1002da8 */
  hmx_grid_set_position_module = *pFuncTbl++; /* Line 203, Address: 0x1002dc0 */
  hmx_grid_set_view_module = *pFuncTbl++; /* Line 204, Address: 0x1002dd8 */
  hmx_grid_set_tile_module = *pFuncTbl++; /* Line 205, Address: 0x1002df0 */
  hmx_grid_set_horz_offsets_module = *pFuncTbl++; /* Line 206, Address: 0x1002e08 */
  hmx_renderer_context_add_module = *pFuncTbl++; /* Line 207, Address: 0x1002e20 */
  hmx_renderer_context_clear_module = *pFuncTbl++; /* Line 208, Address: 0x1002e38 */
  hmx_renderer_context_draw_module = *pFuncTbl++; /* Line 209, Address: 0x1002e50 */
  hmx_sprite_base_module = *pFuncTbl++; /* Line 210, Address: 0x1002e68 */
  hmx_sprite_set_position_module = *pFuncTbl++; /* Line 211, Address: 0x1002e80 */
  hmx_sprite_set_bitmap_module = *pFuncTbl++; /* Line 212, Address: 0x1002e98 */
  hmx_sprite_set_flags_module = *pFuncTbl++; /* Line 213, Address: 0x1002eb0 */

  hmx_ddagrid_create_module = *pFuncTbl++; /* Line 215, Address: 0x1002ec8 */
  hmx_ddagrid_release_module = *pFuncTbl++; /* Line 216, Address: 0x1002ee0 */
  hmx_ddagrid_set_scan_module = *pFuncTbl++; /* Line 217, Address: 0x1002ef8 */
  hmx_ddagrid_set_tile_module = *pFuncTbl++; /* Line 218, Address: 0x1002f10 */

  ++pBufTbl; /* Line 220, Address: 0x1002f28 */
  ++pBufTbl; /* Line 221, Address: 0x1002f34 */
  ++pBufTbl; /* Line 222, Address: 0x1002f40 */
  ++pBufTbl; /* Line 223, Address: 0x1002f4c */
  ++pBufTbl; /* Line 224, Address: 0x1002f58 */
  ++pBufTbl; /* Line 225, Address: 0x1002f64 */
  ++pBufTbl; /* Line 226, Address: 0x1002f70 */
  ++pBufTbl; /* Line 227, Address: 0x1002f7c */
  ++pBufTbl; /* Line 228, Address: 0x1002f88 */
  ++pBufTbl; /* Line 229, Address: 0x1002f94 */
  ++pBufTbl; /* Line 230, Address: 0x1002fa0 */

  g_env_module = (hmx_environment*)**pBufTbl++; /* Line 232, Address: 0x1002fac */
  g_loader_module = (hmx_environment*)**pBufTbl++; /* Line 233, Address: 0x1002fc8 */



  hSurf = lpDllIn->hSurf; /* Line 237, Address: 0x1002fe4 */
  lpColorwk = lpDllIn->lpColorwk; /* Line 238, Address: 0x1002ff4 */
  lpbFullScreen = lpDllIn->lpbFullScreen; /* Line 239, Address: 0x1003004 */

  sMemCpy(&crntScorData, lpDllIn->lpCrntScorData, sizeof(crntScorData)); /* Line 241, Address: 0x1003014 */
  selectIndx = lpDllIn->selectIndx; /* Line 242, Address: 0x1003038 */

  CDPlay = lpDllIn->CDPlay; /* Line 244, Address: 0x1003048 */
  CDPause = lpDllIn->CDPause; /* Line 245, Address: 0x1003058 */
  WaveRequest = lpDllIn->WaveRequest; /* Line 246, Address: 0x1003068 */

  ReadScore = lpDllIn->ReadScoreData; /* Line 248, Address: 0x1003078 */
  WriteScore = lpDllIn->WriteScoreData; /* Line 249, Address: 0x1003088 */
  OpenScore = lpDllIn->OpenScoreData; /* Line 250, Address: 0x1003098 */
  CloseScore = lpDllIn->CloseScoreData; /* Line 251, Address: 0x10030a8 */
  CreateScore = lpDllIn->CreateScoreData; /* Line 252, Address: 0x10030b8 */
  ReadIndx = lpDllIn->ReadScoreIndx; /* Line 253, Address: 0x10030c8 */
  WriteIndx = lpDllIn->WriteScoreIndx; /* Line 254, Address: 0x10030d8 */
  bFirstTitle = lpDllIn->bFirstTitle; /* Line 255, Address: 0x10030e8 */
  lpUserKey = lpDllIn->lpUserKey; /* Line 256, Address: 0x10030f8 */

  s_ctx = get_draw_context_module(); /* Line 258, Address: 0x1003108 */

  OEClrset(tblPal1, 0); /* Line 260, Address: 0x1003120 */
  OEClrset(tblPal2, 1); /* Line 261, Address: 0x1003134 */
  OEClrset(tblPal3, 2); /* Line 262, Address: 0x1003148 */
  OEClrset(tblPal4, 3); /* Line 263, Address: 0x100315c */

  OECreateEA(); /* Line 265, Address: 0x1003170 */
  nSequenceNum = 1; /* Line 266, Address: 0x1003178 */
  nTimerCunt = 0; /* Line 267, Address: 0x1003184 */
} /* Line 268, Address: 0x100318c */




void DLLEnd(void) { /* Line 273, Address: 0x10031a0 */
  OEDeleteEA(); /* Line 274, Address: 0x10031a8 */


} /* Line 277, Address: 0x10031b0 */






void SWdataSet(ushort_union sw1, ushort_union sw2) { /* Line 284, Address: 0x10031c0 */
  swData1 = sw1.w; /* Line 285, Address: 0x10031cc */
  swData2 = sw2.w; /* Line 286, Address: 0x10031d8 */









} /* Line 296, Address: 0x10031e4 */









int DLLMain(void) { /* Line 306, Address: 0x10031f0 */
  int ret = 0; /* Line 307, Address: 0x10031fc */

  switch (nSequenceNum) { /* Line 309, Address: 0x1003200 */

    case 1:
      OEOpenSta(); /* Line 312, Address: 0x1003280 */
      break; /* Line 313, Address: 0x1003288 */

    case 2:
      OESegaLogo(); /* Line 316, Address: 0x1003290 */
      break; /* Line 317, Address: 0x1003298 */

    case 3:
      OEDark(); /* Line 320, Address: 0x10032a0 */
      break; /* Line 321, Address: 0x10032a8 */

    case 5:
      OESonic(); /* Line 324, Address: 0x10032b0 */
      break; /* Line 325, Address: 0x10032b8 */

    case 6:
      OETitleSta(); /* Line 328, Address: 0x10032c0 */
      break; /* Line 329, Address: 0x10032c8 */

    case 7:
      OETitle(); /* Line 332, Address: 0x10032d0 */
      break; /* Line 333, Address: 0x10032d8 */

    case 8:
      OEFadeOut(); /* Line 336, Address: 0x10032e0 */
      break; /* Line 337, Address: 0x10032e8 */

    case 9:
      OEFadeIn(); /* Line 340, Address: 0x10032f0 */
      break; /* Line 341, Address: 0x10032f8 */

    case 999:
      ret = OEEnd(); /* Line 344, Address: 0x1003300 */
      break;
  }
  if (nTimerCunt == 0x7FFFFFFF) /* Line 347, Address: 0x100330c */
    nTimerCunt = 5184000; /* Line 348, Address: 0x1003324 */
  else
    ++nTimerCunt; /* Line 350, Address: 0x100333c */

  OEDraw(); /* Line 352, Address: 0x1003350 */

  return ret; /* Line 354, Address: 0x1003358 */
} /* Line 355, Address: 0x100335c */
