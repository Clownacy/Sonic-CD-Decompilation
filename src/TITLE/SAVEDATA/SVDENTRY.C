#include "..\..\TYPES.H"
#include "..\COMMON\SCORE_DATA_TYPES.H"
#include "..\COMMON\ENGINE_DLL.H"
#include "..\COMMON\HMX_TYPES.H"
#include "SVDENTRY.H"
#include "..\COMMON\HMX_OEEACTL.H"
#include "..\COMMON\PALT.H"
#include "SVDDO.H"
#include "SVDSPRT.H"

static void SDWait();

hmx_environment* g_env_module;
hmx_environment* g_loader_module;
int nTimerCunt;
unsigned short nSequenceNum;
static int nWaitTime;
static unsigned short nSaveSequenceNum;
static unsigned int bWaitKeyOff;
static unsigned int bDefaultMsgFlag;
unsigned short swData1;
extern palette_entry tblPal4[];
extern palette_entry tblPal3[];
extern palette_entry tblPal2[];
extern palette_entry tblPal1[];
draw_context* s_ctx;
draw_context*(*get_draw_context_module)();
void(*WaveRequest)(short);
unsigned int(*WriteIndx)(int, unsigned int);
int(*ReadIndx)(unsigned int);
unsigned int(*CreateScore)();
unsigned int(*CloseScore)(unsigned int);
unsigned int(*OpenScore)(int);
unsigned int(*WriteScore)(int, char*, unsigned int);
unsigned int(*ReadScore)(int, char*, unsigned int);
score_data* lpCrntScorData;
palette_entry* lpColorwk;
unsigned int hSurf;
unsigned int hWnd;
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
void(*sMemSet)(void*, unsigned char, int);
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
int keybordInputTime;







































void OESetSequenceNum(unsigned short num) { /* Line 132, Address: 0x10014d0 */
  nSequenceNum = num; /* Line 133, Address: 0x10014d8 */
  nTimerCunt = -1; /* Line 134, Address: 0x10014e4 */
} /* Line 135, Address: 0x10014f0 */




void KeyWait() { /* Line 140, Address: 0x1001500 */
  nSaveSequenceNum = nSequenceNum; /* Line 141, Address: 0x1001508 */
  nWaitTime = 6; /* Line 142, Address: 0x1001518 */
  OESetSequenceNum(3); /* Line 143, Address: 0x1001524 */
} /* Line 144, Address: 0x1001530 */




void WaitKeyOff() { /* Line 149, Address: 0x1001540 */
  nSaveSequenceNum = nSequenceNum; /* Line 150, Address: 0x1001548 */
  bWaitKeyOff = 1; /* Line 151, Address: 0x1001558 */
  nWaitTime = 0; /* Line 152, Address: 0x1001564 */
  OESetSequenceNum(3); /* Line 153, Address: 0x100156c */
} /* Line 154, Address: 0x1001578 */




void Wait(int time) { /* Line 159, Address: 0x1001590 */
  nSaveSequenceNum = nSequenceNum; /* Line 160, Address: 0x100159c */
  bWaitKeyOff = 0; /* Line 161, Address: 0x10015ac */
  nWaitTime = time; /* Line 162, Address: 0x10015b4 */
  OESetSequenceNum(3); /* Line 163, Address: 0x10015c0 */
} /* Line 164, Address: 0x10015cc */




void WaitAndDfltMsg(int time) { /* Line 169, Address: 0x10015e0 */
  nSaveSequenceNum = nSequenceNum; /* Line 170, Address: 0x10015ec */
  bWaitKeyOff = 1; /* Line 171, Address: 0x10015fc */
  bDefaultMsgFlag = 1; /* Line 172, Address: 0x1001608 */
  nWaitTime = time; /* Line 173, Address: 0x1001614 */
  OESetSequenceNum(3); /* Line 174, Address: 0x1001620 */
} /* Line 175, Address: 0x100162c */




static void SDWait() { /* Line 180, Address: 0x1001640 */
  if (bWaitKeyOff == 0 && nTimerCunt > nWaitTime) /* Line 181, Address: 0x1001648 */
  {
    OESetSequenceNum(nSaveSequenceNum); /* Line 183, Address: 0x1001674 */
    if (bDefaultMsgFlag != 0) /* Line 184, Address: 0x1001684 */
    {
      DefaultMessage(); /* Line 186, Address: 0x1001694 */
      bDefaultMsgFlag = 0; /* Line 187, Address: 0x100169c */
    }
  }
  if (bWaitKeyOff != 0) /* Line 190, Address: 0x10016a4 */
  {
    if (swData1 == 0) bWaitKeyOff = 0; /* Line 192, Address: 0x10016b4 */
  }
} /* Line 194, Address: 0x10016d0 */




void DLLInit(engine_dll* lpDllIn, char*** pBufTbl, void** pFuncTbl) { /* Line 199, Address: 0x10016e0 */

  ++pFuncTbl; /* Line 201, Address: 0x10016f4 */
  ++pFuncTbl; /* Line 202, Address: 0x1001700 */
  ++pFuncTbl; /* Line 203, Address: 0x100170c */
  ++pFuncTbl; /* Line 204, Address: 0x1001718 */
  ++pFuncTbl; /* Line 205, Address: 0x1001724 */
  ++pFuncTbl; /* Line 206, Address: 0x1001730 */
  ++pFuncTbl; /* Line 207, Address: 0x100173c */
  ++pFuncTbl; /* Line 208, Address: 0x1001748 */
  ++pFuncTbl; /* Line 209, Address: 0x1001754 */
  ++pFuncTbl; /* Line 210, Address: 0x1001760 */
  ++pFuncTbl; /* Line 211, Address: 0x100176c */

  sMemAlloc = *pFuncTbl++; /* Line 213, Address: 0x1001778 */
  sMemFree = *pFuncTbl++; /* Line 214, Address: 0x1001790 */
  sMemSet = *pFuncTbl++; /* Line 215, Address: 0x10017a8 */
  sMemCpy = *pFuncTbl++; /* Line 216, Address: 0x10017c0 */
  ++pFuncTbl; /* Line 217, Address: 0x10017d8 */
  ++pFuncTbl; /* Line 218, Address: 0x10017e4 */
  ++pFuncTbl; /* Line 219, Address: 0x10017f0 */
  ++pFuncTbl; /* Line 220, Address: 0x10017fc */
  ++pFuncTbl; /* Line 221, Address: 0x1001808 */
  sPrintf = *pFuncTbl++; /* Line 222, Address: 0x1001814 */
  sOutputDebugString = *pFuncTbl++; /* Line 223, Address: 0x100182c */
  sOpenFile = *pFuncTbl++; /* Line 224, Address: 0x1001844 */
  sReadFile = *pFuncTbl++; /* Line 225, Address: 0x100185c */
  sCloseFile = *pFuncTbl++; /* Line 226, Address: 0x1001874 */
  sGetFileSize = *pFuncTbl++; /* Line 227, Address: 0x100188c */


  get_draw_context_module = *pFuncTbl++; /* Line 230, Address: 0x10018a4 */
  FlipToScreen_module = *pFuncTbl++; /* Line 231, Address: 0x10018bc */
  ld_bitmap_4to8_module = *pFuncTbl++; /* Line 232, Address: 0x10018d4 */
  ld_load_cmpfile_module = *pFuncTbl++; /* Line 233, Address: 0x10018ec */
  hmx_background_set_background_module = *pFuncTbl++; /* Line 234, Address: 0x1001904 */
  hmx_bitmap_create_module = *pFuncTbl++; /* Line 235, Address: 0x100191c */
  hmx_bitmap_release_module = *pFuncTbl++; /* Line 236, Address: 0x1001934 */
  hmx_bitmap_get_scan0_module = *pFuncTbl++; /* Line 237, Address: 0x100194c */
  hmx_bitmap_set_transparency_module = *pFuncTbl++; /* Line 238, Address: 0x1001964 */
  hmx_free_module = *pFuncTbl++; /* Line 239, Address: 0x100197c */
  hmx_grid_create_module = *pFuncTbl++; /* Line 240, Address: 0x1001994 */
  hmx_grid_release_module = *pFuncTbl++; /* Line 241, Address: 0x10019ac */
  hmx_grid_base_module = *pFuncTbl++; /* Line 242, Address: 0x10019c4 */
  hmx_grid_set_position_module = *pFuncTbl++; /* Line 243, Address: 0x10019dc */
  hmx_grid_set_view_module = *pFuncTbl++; /* Line 244, Address: 0x10019f4 */
  hmx_grid_set_tile_module = *pFuncTbl++; /* Line 245, Address: 0x1001a0c */
  hmx_grid_set_horz_offsets_module = *pFuncTbl++; /* Line 246, Address: 0x1001a24 */
  hmx_renderer_context_add_module = *pFuncTbl++; /* Line 247, Address: 0x1001a3c */
  hmx_renderer_context_clear_module = *pFuncTbl++; /* Line 248, Address: 0x1001a54 */
  hmx_renderer_context_draw_module = *pFuncTbl++; /* Line 249, Address: 0x1001a6c */
  hmx_sprite_base_module = *pFuncTbl++; /* Line 250, Address: 0x1001a84 */
  hmx_sprite_set_position_module = *pFuncTbl++; /* Line 251, Address: 0x1001a9c */
  hmx_sprite_set_bitmap_module = *pFuncTbl++; /* Line 252, Address: 0x1001ab4 */
  hmx_sprite_set_flags_module = *pFuncTbl++; /* Line 253, Address: 0x1001acc */

  hmx_ddagrid_create_module = *pFuncTbl++; /* Line 255, Address: 0x1001ae4 */
  hmx_ddagrid_release_module = *pFuncTbl++; /* Line 256, Address: 0x1001afc */
  hmx_ddagrid_set_scan_module = *pFuncTbl++; /* Line 257, Address: 0x1001b14 */
  hmx_ddagrid_set_tile_module = *pFuncTbl++; /* Line 258, Address: 0x1001b2c */

  ++pBufTbl; /* Line 260, Address: 0x1001b44 */
  ++pBufTbl; /* Line 261, Address: 0x1001b50 */
  ++pBufTbl; /* Line 262, Address: 0x1001b5c */
  ++pBufTbl; /* Line 263, Address: 0x1001b68 */
  ++pBufTbl; /* Line 264, Address: 0x1001b74 */
  ++pBufTbl; /* Line 265, Address: 0x1001b80 */
  ++pBufTbl; /* Line 266, Address: 0x1001b8c */
  ++pBufTbl; /* Line 267, Address: 0x1001b98 */
  ++pBufTbl; /* Line 268, Address: 0x1001ba4 */
  ++pBufTbl; /* Line 269, Address: 0x1001bb0 */
  ++pBufTbl; /* Line 270, Address: 0x1001bbc */

  g_env_module = (hmx_environment*)**pBufTbl++; /* Line 272, Address: 0x1001bc8 */
  g_loader_module = (hmx_environment*)**pBufTbl++; /* Line 273, Address: 0x1001be4 */



  hWnd = lpDllIn->hWnd; /* Line 277, Address: 0x1001c00 */
  hSurf = lpDllIn->hSurf; /* Line 278, Address: 0x1001c10 */
  lpColorwk = lpDllIn->lpColorwk; /* Line 279, Address: 0x1001c20 */
  lpCrntScorData = lpDllIn->lpCrntScorData; /* Line 280, Address: 0x1001c30 */
  ReadScore = lpDllIn->ReadScoreData; /* Line 281, Address: 0x1001c40 */
  WriteScore = lpDllIn->WriteScoreData; /* Line 282, Address: 0x1001c50 */
  OpenScore = lpDllIn->OpenScoreData; /* Line 283, Address: 0x1001c60 */
  CloseScore = lpDllIn->CloseScoreData; /* Line 284, Address: 0x1001c70 */
  CreateScore = lpDllIn->CreateScoreData; /* Line 285, Address: 0x1001c80 */
  ReadIndx = lpDllIn->ReadScoreIndx; /* Line 286, Address: 0x1001c90 */
  WriteIndx = lpDllIn->WriteScoreIndx; /* Line 287, Address: 0x1001ca0 */
  WaveRequest = lpDllIn->WaveRequest; /* Line 288, Address: 0x1001cb0 */

  s_ctx = get_draw_context_module(); /* Line 290, Address: 0x1001cc0 */

  OEClrset(tblPal1, 0); /* Line 292, Address: 0x1001cd8 */
  OEClrset(tblPal2, 1); /* Line 293, Address: 0x1001cec */
  OEClrset(tblPal3, 2); /* Line 294, Address: 0x1001d00 */
  OEClrset(tblPal4, 3); /* Line 295, Address: 0x1001d14 */

  OECreateEA(); /* Line 297, Address: 0x1001d28 */
  nSequenceNum = 1; /* Line 298, Address: 0x1001d30 */
  nTimerCunt = 0; /* Line 299, Address: 0x1001d3c */
} /* Line 300, Address: 0x1001d44 */




void DLLEnd() { /* Line 305, Address: 0x1001d60 */
  OEDeleteEA(); /* Line 306, Address: 0x1001d68 */
  DeleteAllCharSprt(); /* Line 307, Address: 0x1001d70 */


} /* Line 310, Address: 0x1001d78 */




void SWdataSet(ushort_union sw1, ushort_union sw2) { /* Line 315, Address: 0x1001d90 */
  swData1 = sw1.w; /* Line 316, Address: 0x1001d9c */
  swData2 = sw2.w; /* Line 317, Address: 0x1001da8 */







} /* Line 325, Address: 0x1001db4 */




int DLLMain() { /* Line 330, Address: 0x1001dc0 */
  int ret = 0; /* Line 331, Address: 0x1001dcc */

  switch (nSequenceNum) /* Line 333, Address: 0x1001dd0 */
  {
    case 1:
      SDStart(); /* Line 336, Address: 0x1001e14 */
      break; /* Line 337, Address: 0x1001e1c */

    case 2:
      SDMenu(); /* Line 340, Address: 0x1001e24 */
      break; /* Line 341, Address: 0x1001e2c */

    case 3:
      SDWait(); /* Line 344, Address: 0x1001e34 */
      break; /* Line 345, Address: 0x1001e3c */

    case 999:
      ret = SDEnd(); /* Line 348, Address: 0x1001e44 */
      break;
  }

  if (nTimerCunt == 2147483647) /* Line 352, Address: 0x1001e50 */
    nTimerCunt = 5184000; /* Line 353, Address: 0x1001e68 */
  else
    ++nTimerCunt; /* Line 355, Address: 0x1001e80 */

  SDDraw(); /* Line 357, Address: 0x1001e94 */
  UpdateSonicCursol(); /* Line 358, Address: 0x1001e9c */
  if (ret == 0) /* Line 359, Address: 0x1001ea4 */
    ret = CheckAutoEnd(); /* Line 360, Address: 0x1001eac */
  return ret; /* Line 361, Address: 0x1001eb8 */
} /* Line 362, Address: 0x1001ebc */
