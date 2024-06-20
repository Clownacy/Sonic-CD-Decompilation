#include "..\..\TYPES.H"
#include "LPL_TYPES.H"
#include "SPM_EQU.H"
#include "LPLMAIN.H"
#include "ACTM.H"
#include "ASCIISET.H"
#include "FLASH.H"
#include "KAITEN.H"
#include "PLS.H"

static void ram_clear();
static void cgdata_unlze();
static void kaiten_req();
static void m2copy();
static void cgchange_chk();
static void lp_makeup();
static int init_dsp();
static void end_proc();
static void prg_init();
static void patchg_init();
static void prgend_chk();
static void cgdata_change();
static void SubCpuMain();
static void cgmwrt_a();
static void cgmwrt_b();
static void cd_call();

static char* ScrAMapFileName[3] =
{
  "TITLE\\PLANET\\MAP\\LP.MAP",
  "TITLE\\PLANET\\MAP\\LPG.MAP",
  "TITLE\\PLANET\\MAP\\LPB.MAP"
};
void(*sCloseFile)(int);
int(*sReadFile)(int, void*, int);
static game_info* lpKeepWork;
int(*sOpenFile)(char*);
void*(*sMemAlloc)(int);
static int InitMode;
static int MakeupMode;
pad_status*(*sPeriPadGet)(unsigned int);
void(*sOutputDebugString)(char*);
void(*sPrintf)(char*, char*);
int(*sRandom)();
void(*sMemCpy)(void*, void*, int);
void(*sMemSet)(void*, unsigned char, int);
void(*sMemFree)(void*);
void(*WaveAllStop)();
void(*ChangeTileBmp)(int, int);
void(*CDPlay)(short);
void(*WaveRequest)(short);
void(*ClrSpriteDebug)();
void(*EAsprset)(short, short, unsigned short, unsigned short, unsigned short);
int(*SetGrid)(int, int, int, int, int);
static char ScrBMapFileName[26] = "TITLE\\PLANET\\MAP\\LPBS.MAP";
static unsigned int bGameInit = 1;
extern PALETTEENTRY init_col[];
static short ScrBMap[704];
extern short* funka_map_tbl[];
extern short funka_timetbl[];
extern PALETTEENTRY ascii_col[];
extern PALETTEENTRY sprite_col1[];
extern PALETTEENTRY** lp_coltbl[];
extern short lpbs_timer[];
extern PALETTEENTRY* sprite_color[];
static short DATable[39] =
{
   3, 36,  4,  5,  6, 37,  7,  8,  9, 38,
  10, 11, 12, 39, 13, 14, 15, 40, 16, 17,
  18, 41, 19, 20, 21, 42, 22, 23, 25, 33,
  31, 28, 24, 30, 29, 26, 32, 34, 35
};
dlink_export ExportedFunctions =
{
  &game_init,
  (void (*)())&game,
  &DLL_meminit,
  &DLL_memfree,
  (void (*)(short, short))&SWdataSet,
  0,
  0,
  0,
  &FadeProc,
  0,
  0,
  0
};
int(*sGetFileSize)(int);
static unsigned int hSmAdr;
static unsigned int hWordRAM;























































































void DLL_meminit(char*** pBufTbl, void** pFuncTbl) { /* Line 178, Address: 0x1004f60 */
  int x, y;
  unsigned int hf;
  short s;
  short* pSmap;

  SetGrid = *pFuncTbl++; /* Line 184, Address: 0x1004f80 */
  EAsprset = *pFuncTbl++; /* Line 185, Address: 0x1004f98 */
  ClrSpriteDebug = *pFuncTbl++; /* Line 186, Address: 0x1004fb0 */
  WaveRequest = *pFuncTbl++; /* Line 187, Address: 0x1004fc8 */
  CDPlay = *pFuncTbl++; /* Line 188, Address: 0x1004fe0 */
  ++pFuncTbl; /* Line 189, Address: 0x1004ff8 */
  ChangeTileBmp = *pFuncTbl++; /* Line 190, Address: 0x1005004 */
  ++pFuncTbl; /* Line 191, Address: 0x100501c */
  ++pFuncTbl; /* Line 192, Address: 0x1005028 */
  ++pFuncTbl; /* Line 193, Address: 0x1005034 */
  WaveAllStop = *pFuncTbl++; /* Line 194, Address: 0x1005040 */

  sMemAlloc = *pFuncTbl++; /* Line 196, Address: 0x1005058 */
  sMemFree = *pFuncTbl++; /* Line 197, Address: 0x1005070 */
  sMemSet = *pFuncTbl++; /* Line 198, Address: 0x1005088 */
  sMemCpy = *pFuncTbl++; /* Line 199, Address: 0x10050a0 */
  ++pFuncTbl; /* Line 200, Address: 0x10050b8 */
  sRandom = *pFuncTbl++; /* Line 201, Address: 0x10050c4 */
  ++pFuncTbl; /* Line 202, Address: 0x10050dc */
  ++pFuncTbl; /* Line 203, Address: 0x10050e8 */
  ++pFuncTbl; /* Line 204, Address: 0x10050f4 */
  sPrintf = *pFuncTbl++; /* Line 205, Address: 0x1005100 */
  sOutputDebugString = *pFuncTbl++; /* Line 206, Address: 0x1005118 */
  sOpenFile = *pFuncTbl++; /* Line 207, Address: 0x1005130 */
  sReadFile = *pFuncTbl++; /* Line 208, Address: 0x1005148 */
  sCloseFile = *pFuncTbl++; /* Line 209, Address: 0x1005160 */
  ++pFuncTbl; /* Line 210, Address: 0x1005178 */

  ++pFuncTbl; /* Line 212, Address: 0x1005184 */
  ++pFuncTbl; /* Line 213, Address: 0x1005190 */
  ++pFuncTbl; /* Line 214, Address: 0x100519c */
  ++pFuncTbl; /* Line 215, Address: 0x10051a8 */
  ++pFuncTbl; /* Line 216, Address: 0x10051b4 */
  ++pFuncTbl; /* Line 217, Address: 0x10051c0 */
  ++pFuncTbl; /* Line 218, Address: 0x10051cc */
  ++pFuncTbl; /* Line 219, Address: 0x10051d8 */
  ++pFuncTbl; /* Line 220, Address: 0x10051e4 */
  ++pFuncTbl; /* Line 221, Address: 0x10051f0 */
  ++pFuncTbl; /* Line 222, Address: 0x10051fc */
  ++pFuncTbl; /* Line 223, Address: 0x1005208 */
  ++pFuncTbl; /* Line 224, Address: 0x1005214 */
  ++pFuncTbl; /* Line 225, Address: 0x1005220 */
  ++pFuncTbl; /* Line 226, Address: 0x100522c */
  ++pFuncTbl; /* Line 227, Address: 0x1005238 */
  ++pFuncTbl; /* Line 228, Address: 0x1005244 */
  ++pFuncTbl; /* Line 229, Address: 0x1005250 */
  ++pFuncTbl; /* Line 230, Address: 0x100525c */
  ++pFuncTbl; /* Line 231, Address: 0x1005268 */
  ++pFuncTbl; /* Line 232, Address: 0x1005274 */
  ++pFuncTbl; /* Line 233, Address: 0x1005280 */
  ++pFuncTbl; /* Line 234, Address: 0x100528c */
  ++pFuncTbl; /* Line 235, Address: 0x1005298 */
  ++pFuncTbl; /* Line 236, Address: 0x10052a4 */
  ++pFuncTbl; /* Line 237, Address: 0x10052b0 */
  ++pFuncTbl; /* Line 238, Address: 0x10052bc */
  ++pFuncTbl; /* Line 239, Address: 0x10052c8 */

  sPeriPadGet = *pFuncTbl++; /* Line 241, Address: 0x10052d4 */


  ++pBufTbl; /* Line 244, Address: 0x10052ec */
  lpcolorwk0 = (PALETTEENTRY*)**pBufTbl++; /* Line 245, Address: 0x10052f8 */
  lpcolorwk1 = (PALETTEENTRY*)**pBufTbl++; /* Line 246, Address: 0x1005314 */
  lpcolorwk2 = (PALETTEENTRY*)**pBufTbl++; /* Line 247, Address: 0x1005330 */
  lpcolorwk3 = (PALETTEENTRY*)**pBufTbl++; /* Line 248, Address: 0x100534c */
  lphscrollbuff = (int_union*)**pBufTbl++; /* Line 249, Address: 0x1005368 */
  lpFadeFlag = (int*)*pBufTbl++; /* Line 250, Address: 0x1005384 */
  lpKeepWork = (game_info*)*pBufTbl++; /* Line 251, Address: 0x100539c */

  lpKeepWork->pSprBmp = SprBmp; /* Line 253, Address: 0x10053b4 */
  lpKeepWork->ptv_adr = (unsigned short*)tv_adr; /* Line 254, Address: 0x10053c8 */

  MakeupMode = 0; /* Line 256, Address: 0x10053dc */
  InitMode = 0; /* Line 257, Address: 0x10053e4 */


  wordram.wordram = sMemAlloc(262144); /* Line 260, Address: 0x10053ec */


  lpKeepWork->sm_adr0 = sMemAlloc(32768); /* Line 263, Address: 0x1005408 */

  if ((hf = sOpenFile(ScrAMapFileName[0])) != -1) /* Line 265, Address: 0x1005428 */
  {
    pSmap = (short*)lpKeepWork->sm_adr0; /* Line 267, Address: 0x1005450 */
    for (y = 0; y < 7; ++y) /* Line 268, Address: 0x100545c */
    {
      for (x = 0; x < 8; ++x) /* Line 270, Address: 0x1005468 */
      {
        if (sReadFile(hf, &s, sizeof(s)) != 2) /* Line 272, Address: 0x1005474 */
        {
          sCloseFile(hf); /* Line 274, Address: 0x100549c */
          return; /* Line 275, Address: 0x10054b0 */
        }
        *pSmap++ = s; /* Line 277, Address: 0x10054b8 */
      } /* Line 278, Address: 0x10054c8 */
      while (x < 10) *pSmap++ = 0, ++x; /* Line 279, Address: 0x10054d8 */
    } /* Line 280, Address: 0x10054fc */
    sCloseFile(hf); /* Line 281, Address: 0x100550c */
  }

} /* Line 284, Address: 0x1005520 */






void DLL_memfree() { /* Line 291, Address: 0x1005540 */




  sMemFree(wordram.wordram); /* Line 296, Address: 0x1005548 */
  sMemFree(lpKeepWork->sm_adr0); /* Line 297, Address: 0x1005560 */

} /* Line 299, Address: 0x100557c */







void SWdataSet(ushort_union sw1, ushort_union sw2) { /* Line 307, Address: 0x1005590 */
  swdata1.w = sw1.w; /* Line 308, Address: 0x100559c */
  swdata2.w = sw2.w; /* Line 309, Address: 0x10055a8 */

} /* Line 311, Address: 0x10055b4 */








void game_init() { /* Line 320, Address: 0x10055c0 */
  PALETTEENTRY *lpSrc, *lpDst;
  int i;
  unsigned int ProcEnd;
  unsigned int hf;

  sMemSet(ScrBMap, 0, sizeof(ScrBMap)); /* Line 326, Address: 0x10055dc */
  if ((hf = sOpenFile(ScrBMapFileName)) != -1) /* Line 327, Address: 0x10055fc */
  {
    (sReadFile(hf, ScrBMap, sizeof(ScrBMap)) ^ sizeof(ScrBMap)) > 0; /* Line 329, Address: 0x1005624 */


    sCloseFile(hf); /* Line 332, Address: 0x100564c */
  }





  ProcEnd = 0; /* Line 339, Address: 0x1005660 */
  do
  {
    switch (InitMode) /* Line 342, Address: 0x1005664 */
    {



      case 0:
        WorkRamClear(); /* Line 348, Address: 0x1005694 */

        comdata_m0 = 0; /* Line 350, Address: 0x100569c */
        comdata_m1 = 0; /* Line 351, Address: 0x10056a4 */
        comdata_m2 = 0; /* Line 352, Address: 0x10056ac */
        comdata_m3 = 0; /* Line 353, Address: 0x10056b4 */
        comdata_m4 = 0; /* Line 354, Address: 0x10056bc */
        comdata_m5 = 0; /* Line 355, Address: 0x10056c4 */
        comdata_m6 = 0; /* Line 356, Address: 0x10056cc */
        comdata_m7 = 0; /* Line 357, Address: 0x10056d4 */
        swdata1.w = 32768; /* Line 358, Address: 0x10056dc */
        main_lpcnt = 1; /* Line 359, Address: 0x10056e8 */




        comdata_s0 = 0; /* Line 364, Address: 0x10056f4 */
        comdata_s1 = 0; /* Line 365, Address: 0x10056fc */
        comdata_s2 = 0; /* Line 366, Address: 0x1005704 */
        comdata_s3 = 0; /* Line 367, Address: 0x100570c */
        comdata_s4 = 0; /* Line 368, Address: 0x1005714 */
        comdata_s5 = 0; /* Line 369, Address: 0x100571c */
        comdata_s6 = 0; /* Line 370, Address: 0x1005724 */
        comdata_s7 = 0; /* Line 371, Address: 0x100572c */
        comflag_s &= 3; /* Line 372, Address: 0x1005734 */
        ram_clear(); /* Line 373, Address: 0x1005748 */
        kaiten_init(); /* Line 374, Address: 0x1005750 */
        cgdata_unlze(); /* Line 375, Address: 0x1005758 */




        patchg_init(); /* Line 380, Address: 0x1005760 */

        cgmwrt_a(); /* Line 382, Address: 0x1005768 */
        cgmwrt_b(); /* Line 383, Address: 0x1005770 */

        flash_flg = 1; /* Line 385, Address: 0x1005778 */
      case 1:
      case 2:
      case 3:
      case 4:
        if (init_dsp() == 0) break; /* Line 390, Address: 0x1005784 */
        comflag_m = 0; /* Line 391, Address: 0x1005794 */
        ProcEnd = 1; /* Line 392, Address: 0x100579c */

        break; /* Line 394, Address: 0x10057a0 */

      case 5:
        prg_init(); /* Line 397, Address: 0x10057a8 */
        lpSrc = init_col; /* Line 398, Address: 0x10057b0 */
        lpDst = lpcolorwk1; /* Line 399, Address: 0x10057b8 */
        for (i = 0; i < 64; ++i) *lpDst++ = *lpSrc++; /* Line 400, Address: 0x10057c0 */
        fadein(); /* Line 401, Address: 0x100580c */

      default:
        ProcEnd = 1; /* Line 404, Address: 0x1005814 */
    }

    v_int(); /* Line 407, Address: 0x1005818 */
  } while (ProcEnd == 0); /* Line 408, Address: 0x1005820 */
  CDPlay(33); /* Line 409, Address: 0x1005828 */
  bGameInit = 0; /* Line 410, Address: 0x100583c */

} /* Line 412, Address: 0x1005844 */






int game() { /* Line 419, Address: 0x1005870 */
  int RetMode;

  RetMode = 0; /* Line 422, Address: 0x100587c */
  switch (ProcMode) /* Line 423, Address: 0x1005880 */
  {
    case 0:
      if (main_lpcnt < 0) /* Line 426, Address: 0x10058b0 */
      {
        main_lpcnt = 1; /* Line 428, Address: 0x10058c8 */
        intmode = 0; /* Line 429, Address: 0x10058d4 */
      }
      kaiten_req(); /* Line 431, Address: 0x10058dc */
      sprascii(); /* Line 432, Address: 0x10058e4 */
      action(); /* Line 433, Address: 0x10058ec */
      SubCpuMain(); /* Line 434, Address: 0x10058f4 */
      ++ProcMode; /* Line 435, Address: 0x10058fc */
      break; /* Line 436, Address: 0x1005910 */

    case 1:
      ++intmode; /* Line 439, Address: 0x1005918 */
      sprascii(); /* Line 440, Address: 0x100592c */
      action(); /* Line 441, Address: 0x1005934 */
      ++ProcMode; /* Line 442, Address: 0x100593c */
      break; /* Line 443, Address: 0x1005950 */

    case 2:
      set_asciicg(); /* Line 446, Address: 0x1005958 */
      m2copy(); /* Line 447, Address: 0x1005960 */
      cgchange_chk(); /* Line 448, Address: 0x1005968 */
      if (comflag_s & 32) /* Line 449, Address: 0x1005970 */
      {
        MakeupMode = 0; /* Line 451, Address: 0x1005988 */
        lp_makeup(); /* Line 452, Address: 0x1005990 */
      } /* Line 453, Address: 0x1005998 */
      else
      {
        ++ProcMode; /* Line 456, Address: 0x10059a0 */
      }
      ++ProcMode; /* Line 458, Address: 0x10059b4 */
      break; /* Line 459, Address: 0x10059c8 */

    case 3:
      lp_makeup(); /* Line 462, Address: 0x10059d0 */
      if (!(comflag_m & 32)) /* Line 463, Address: 0x10059d8 */
      {
        comflag_s &= 223; /* Line 465, Address: 0x10059f0 */
        comflag_s |= 16; /* Line 466, Address: 0x1005a04 */
      }
      if (MakeupMode < 0) ++ProcMode; /* Line 468, Address: 0x1005a18 */
      break; /* Line 469, Address: 0x1005a3c */

    case 4:
      if (comflag_s & 64) /* Line 472, Address: 0x1005a44 */
      {
        prgend_chk(); /* Line 474, Address: 0x1005a5c */
        ++ProcMode; /* Line 475, Address: 0x1005a64 */
      } /* Line 476, Address: 0x1005a78 */
      else
      {
        --main_lpcnt; /* Line 479, Address: 0x1005a80 */
        ++intmode; /* Line 480, Address: 0x1005a94 */
        ProcMode = 0; /* Line 481, Address: 0x1005aa8 */
      }
      break; /* Line 483, Address: 0x1005ab0 */

    case 5:
      comflag_m = 0; /* Line 486, Address: 0x1005ab8 */
      comflag_s = 0; /* Line 487, Address: 0x1005ac0 */
      RetMode = -1; /* Line 488, Address: 0x1005ac8 */
      break;
  }

  v_int(); /* Line 492, Address: 0x1005acc */
  return RetMode; /* Line 493, Address: 0x1005ad4 */
} /* Line 494, Address: 0x1005ad8 */




static void ram_clear() {} /* Line 499, Address: 0x1005af0 */



static void cgdata_unlze() {} /* Line 503, Address: 0x1005b00 */



static void kaiten_req() {} /* Line 507, Address: 0x1005b10 */



static void m2copy() {} /* Line 511, Address: 0x1005b20 */

static void cgchange_chk() { /* Line 513, Address: 0x1005b30 */
  short fPatnoWk, *pMaptbl, *pWkadr, wk, funka_off;
  int i, j;

  switch (lplanet_no) /* Line 517, Address: 0x1005b54 */
  {
    case 0:
    case 1:
      funka_off = 620; /* Line 521, Address: 0x1005b8c */
      break; /* Line 522, Address: 0x1005b98 */

    case 2:
      funka_off = 720; /* Line 525, Address: 0x1005ba0 */
      break; /* Line 526, Address: 0x1005bac */

    default:
      return; /* Line 529, Address: 0x1005bb4 */
  }
  if (funka_pctimer == 0) /* Line 531, Address: 0x1005bbc */
  {
    if (funka_patno >= 12) funka_patno = 0; /* Line 533, Address: 0x1005bd4 */
    fPatnoWk = funka_patno; /* Line 534, Address: 0x1005bf8 */
    funka_pctimer = funka_timetbl[fPatnoWk]; /* Line 535, Address: 0x1005c08 */
    ++funka_patno; /* Line 536, Address: 0x1005c2c */
    pMaptbl = funka_map_tbl[fPatnoWk]; /* Line 537, Address: 0x1005c40 */
    pWkadr = (short*)lpKeepWork->sm_adr0 + 6; /* Line 538, Address: 0x1005c5c */
    for (i = 0; i < 2; ++i) /* Line 539, Address: 0x1005c6c */
    {
      for (j = 0; j < 2; ++j) /* Line 541, Address: 0x1005c78 */
      {
        if ((wk = *pMaptbl++) != 0) wk += funka_off; /* Line 543, Address: 0x1005c84 */
        *pWkadr++ = wk; /* Line 544, Address: 0x1005cb4 */
        SetGrid(-1, j + 6, i, wk, 0); /* Line 545, Address: 0x1005cc0 */
      } /* Line 546, Address: 0x1005ce8 */
      pWkadr += 126; /* Line 547, Address: 0x1005cf8 */
    } /* Line 548, Address: 0x1005cfc */
  }

} /* Line 551, Address: 0x1005d0c */

static void lp_makeup() { /* Line 553, Address: 0x1005d40 */
  switch (MakeupMode) /* Line 554, Address: 0x1005d48 */
  {
    case 0:
      flashout(); /* Line 557, Address: 0x1005d78 */
      ++MakeupMode; /* Line 558, Address: 0x1005d80 */
      break; /* Line 559, Address: 0x1005d94 */

    case 1:
      sMemSet(actwk, 0, 960); /* Line 562, Address: 0x1005d9c */
      prg_init(); /* Line 563, Address: 0x1005dbc */
      comflag_m &= 223; /* Line 564, Address: 0x1005dc4 */
      kaiten_req(); /* Line 565, Address: 0x1005dd8 */
      m2copy(); /* Line 566, Address: 0x1005de0 */
      SubCpuMain(); /* Line 567, Address: 0x1005de8 */
      if (comflag_s & 64) /* Line 568, Address: 0x1005df0 */
      {
        MakeupMode = -1; /* Line 570, Address: 0x1005e08 */
      } /* Line 571, Address: 0x1005e14 */
      else
        ++MakeupMode; /* Line 573, Address: 0x1005e1c */
      break; /* Line 574, Address: 0x1005e30 */

    case 2:
      intmode = 0; /* Line 577, Address: 0x1005e38 */
      kaiten_req(); /* Line 578, Address: 0x1005e40 */
      m2copy(); /* Line 579, Address: 0x1005e48 */
      SubCpuMain(); /* Line 580, Address: 0x1005e50 */
      if (comflag_s & 64) /* Line 581, Address: 0x1005e58 */
      {
        MakeupMode = -1; /* Line 583, Address: 0x1005e70 */
      } /* Line 584, Address: 0x1005e7c */
      else
        ++MakeupMode; /* Line 586, Address: 0x1005e84 */
      break; /* Line 587, Address: 0x1005e98 */

    case 3:
      intmode = 1; /* Line 590, Address: 0x1005ea0 */
      if (comflag_s & 64) /* Line 591, Address: 0x1005eac */
      {
        MakeupMode = -1; /* Line 593, Address: 0x1005ec4 */
      } /* Line 594, Address: 0x1005ed0 */
      else
        ++MakeupMode; /* Line 596, Address: 0x1005ed8 */
      break; /* Line 597, Address: 0x1005eec */

    case 4:
      intmode = 2; /* Line 600, Address: 0x1005ef4 */
      kaiten_req(); /* Line 601, Address: 0x1005f00 */
      m2copy(); /* Line 602, Address: 0x1005f08 */
      SubCpuMain(); /* Line 603, Address: 0x1005f10 */
      if (comflag_s & 64) /* Line 604, Address: 0x1005f18 */
      {
        MakeupMode = -1; /* Line 606, Address: 0x1005f30 */
      } /* Line 607, Address: 0x1005f3c */
      else
        ++MakeupMode; /* Line 609, Address: 0x1005f44 */
      break; /* Line 610, Address: 0x1005f58 */

    case 5:
      intmode = 3; /* Line 613, Address: 0x1005f60 */
      if (comflag_s & 64) /* Line 614, Address: 0x1005f6c */
      {
        MakeupMode = -1; /* Line 616, Address: 0x1005f84 */
      } /* Line 617, Address: 0x1005f90 */
      else
        ++MakeupMode; /* Line 619, Address: 0x1005f98 */
      break; /* Line 620, Address: 0x1005fac */

    case 6:
      music_selflg &= 254; /* Line 623, Address: 0x1005fb4 */
      actset_flg = 0; /* Line 624, Address: 0x1005fc8 */
      flashin(); /* Line 625, Address: 0x1005fd0 */
      ++MakeupMode; /* Line 626, Address: 0x1005fd8 */
      break; /* Line 627, Address: 0x1005fec */

    case 7:
      main_lpcnt = 0; /* Line 630, Address: 0x1005ff4 */
      intmode = -1; /* Line 631, Address: 0x1005ffc */
      MakeupMode = -1; /* Line 632, Address: 0x1006008 */
      break; /* Line 633, Address: 0x1006014 */

    default:
      MakeupMode = -1; /* Line 636, Address: 0x100601c */
  }


} /* Line 640, Address: 0x1006028 */

static int init_dsp() { /* Line 642, Address: 0x1006040 */
  switch (InitMode) /* Line 643, Address: 0x1006048 */
  {
    case 0:
      kaiten_req(); /* Line 646, Address: 0x1006090 */
      m2copy(); /* Line 647, Address: 0x1006098 */
      SubCpuMain(); /* Line 648, Address: 0x10060a0 */
      cgchange_chk(); /* Line 649, Address: 0x10060a8 */
      ++InitMode; /* Line 650, Address: 0x10060b0 */
      break; /* Line 651, Address: 0x10060c4 */

    case 1:
      intmode = 1; /* Line 654, Address: 0x10060cc */
      if (comflag_s & 64) end_proc(); /* Line 655, Address: 0x10060d8 */
      ++InitMode; /* Line 656, Address: 0x10060f8 */
      break; /* Line 657, Address: 0x100610c */

    case 2:
      kaiten_req(); /* Line 660, Address: 0x1006114 */
      m2copy(); /* Line 661, Address: 0x100611c */
      SubCpuMain(); /* Line 662, Address: 0x1006124 */
      cgchange_chk(); /* Line 663, Address: 0x100612c */
    case 3:
      ++intmode; /* Line 665, Address: 0x1006134 */
      ++InitMode; /* Line 666, Address: 0x1006148 */
      break; /* Line 667, Address: 0x100615c */

    case 4:
      if (comflag_s & 64) end_proc(); /* Line 670, Address: 0x1006164 */
      else ++InitMode; /* Line 671, Address: 0x100618c */
  }

  return 0; /* Line 674, Address: 0x10061a0 */
} /* Line 675, Address: 0x10061a4 */

static void end_proc() { /* Line 677, Address: 0x10061c0 */
  flash_flg = 1; /* Line 678, Address: 0x10061c8 */
  fadeout(); /* Line 679, Address: 0x10061d4 */
} /* Line 680, Address: 0x10061dc */

static void prg_init() { /* Line 682, Address: 0x10061f0 */
  PALETTEENTRY *lpPlCol, *lpBkgCol, *lpDst;
  int i;

  lpPlCol = *lp_coltbl[lplanet_no * 2]; /* Line 686, Address: 0x1006208 */
  lpBkgCol = *lp_coltbl[lplanet_no * 2 + 1]; /* Line 687, Address: 0x1006234 */
  lpDst = lpcolorwk1; /* Line 688, Address: 0x1006264 */
  for (i = 0; i < 16; ++i) *lpDst++ = *lpBkgCol++; /* Line 689, Address: 0x100626c */
  for (i = 0; i < 16; ++i) *lpDst++ = *lpPlCol++; /* Line 690, Address: 0x10062b8 */
  lpPlCol = sprite_col1; /* Line 691, Address: 0x1006304 */
  for (i = 0; i < 16; ++i) *lpDst++ = *lpPlCol++; /* Line 692, Address: 0x100630c */
  lpPlCol = ascii_col; /* Line 693, Address: 0x1006358 */
  for (i = 0; i < 16; ++i) *lpDst++ = *lpPlCol++; /* Line 694, Address: 0x1006360 */
  patchg_init(); /* Line 695, Address: 0x10063ac */
} /* Line 696, Address: 0x10063b4 */

static void patchg_init() { /* Line 698, Address: 0x10063e0 */
  short *pMapwk, *pMapadr, funka_off;
  int i, wk;

  colorno = 0; /* Line 702, Address: 0x10063fc */
  coltimer = lpbs_timer[0]; /* Line 703, Address: 0x1006404 */
  funka_patno = 0; /* Line 704, Address: 0x1006414 */


  funka_pctimer = 0; /* Line 707, Address: 0x100641c */
  pMapwk = funka_map_tbl[0]; /* Line 708, Address: 0x1006424 */
  pMapadr = (short*)lpKeepWork->sm_adr0 + 6; /* Line 709, Address: 0x100642c */
  switch (lplanet_no) /* Line 710, Address: 0x100643c */
  {
    case 0:
    case 1:
      funka_off = 620; /* Line 714, Address: 0x1006474 */
      break; /* Line 715, Address: 0x1006480 */

    case 2:
      funka_off = 720; /* Line 718, Address: 0x1006488 */
      break; /* Line 719, Address: 0x1006494 */

    default:
      funka_off = 0; /* Line 722, Address: 0x100649c */
  }
  for (i = 0; i < 2; ++i) /* Line 724, Address: 0x10064a0 */
  {
    wk = funka_off + *pMapwk++; /* Line 726, Address: 0x10064ac */
    *pMapadr++ = wk; /* Line 727, Address: 0x10064cc */
    SetGrid(-1, 6, i, wk, 0); /* Line 728, Address: 0x10064e0 */
    wk = funka_off + *pMapwk++; /* Line 729, Address: 0x1006504 */
    *pMapadr++ = wk; /* Line 730, Address: 0x1006524 */
    SetGrid(-1, 7, i, wk, 0); /* Line 731, Address: 0x1006538 */
    pMapadr += 127; /* Line 732, Address: 0x100655c */
  } /* Line 733, Address: 0x1006560 */
  spr_coltimer = 5; /* Line 734, Address: 0x1006570 */
  spr_colno = 0; /* Line 735, Address: 0x100657c */
} /* Line 736, Address: 0x1006584 */

static void prgend_chk() { /* Line 738, Address: 0x10065b0 */
  flash_flg = 1; /* Line 739, Address: 0x10065b8 */
  fadeout(); /* Line 740, Address: 0x10065c4 */


} /* Line 743, Address: 0x10065cc */

static void cgdata_change() { /* Line 745, Address: 0x10065e0 */
  unsigned short *pA0, *pA1, *pA2, *pSmap, s, offs;
  int i, j, x, y;
  unsigned int hf;

  if (comdata_m5 != 3) /* Line 750, Address: 0x100660c */
  {

    if ((hf = sOpenFile(ScrAMapFileName[comdata_m5])) != -1) /* Line 753, Address: 0x1006624 */
    {
      switch (comdata_m5) /* Line 755, Address: 0x1006664 */
      {
        case 0:
          offs = 0; /* Line 758, Address: 0x1006698 */
          break; /* Line 759, Address: 0x100669c */

        case 1:
          offs = 200; /* Line 762, Address: 0x10066a4 */
          break; /* Line 763, Address: 0x10066ac */

        case 2:
          offs = 416; /* Line 766, Address: 0x10066b4 */
          break; /* Line 767, Address: 0x10066bc */

        default:
          offs = 0; /* Line 770, Address: 0x10066c4 */
          break;
      }
      pSmap = lpKeepWork->sm_adr0; /* Line 773, Address: 0x10066c8 */
      for (y = 0; y < 7; ++y) /* Line 774, Address: 0x10066d4 */
      {
        for (x = 0; x < 8; ++x) /* Line 776, Address: 0x10066e0 */
        {
          if (sReadFile(hf, &s, sizeof(s)) != sizeof(s)) /* Line 778, Address: 0x10066ec */
          {
            sCloseFile(hf); /* Line 780, Address: 0x1006714 */
            return; /* Line 781, Address: 0x1006728 */
          }
          if (s != 0) s += offs; /* Line 783, Address: 0x1006730 */
          *pSmap++ = s; /* Line 784, Address: 0x100674c */
        } /* Line 785, Address: 0x100675c */
        while (x < 10) *pSmap++ = 0, ++x; /* Line 786, Address: 0x100676c */
      } /* Line 787, Address: 0x1006790 */
      sCloseFile(hf); /* Line 788, Address: 0x10067a0 */
    }

    switch (lplanet_no) /* Line 791, Address: 0x10067b4 */
    {
      case 0:
      case 1:
        offs = 620; /* Line 795, Address: 0x10067ec */
        break; /* Line 796, Address: 0x10067f4 */

      case 2:
        offs = 720; /* Line 799, Address: 0x10067fc */
        break; /* Line 800, Address: 0x1006804 */

      default:
        offs = 0; /* Line 803, Address: 0x100680c */
    }
    pA0 = (unsigned short*)funka_map_tbl[0]; /* Line 805, Address: 0x1006810 */
    pA2 = lpKeepWork->sm_adr0 + 6; /* Line 806, Address: 0x100681c */
    for (i = 1; i >= 0; --i) /* Line 807, Address: 0x100682c */
    {
      pA1 = pA2; /* Line 809, Address: 0x1006838 */
      for (j = 1; j >= 0; --j) /* Line 810, Address: 0x100683c */
      {
        s = *pA0++; /* Line 812, Address: 0x1006848 */
        if (s != 0) s += offs; /* Line 813, Address: 0x100685c */
        *pA1++ = s; /* Line 814, Address: 0x1006878 */
      } /* Line 815, Address: 0x1006888 */
      pA2 += 128; /* Line 816, Address: 0x1006894 */
    } /* Line 817, Address: 0x1006898 */
    pSmap = lpKeepWork->sm_adr0; /* Line 818, Address: 0x10068a4 */
    for (y = 0; y < 7; ++y) /* Line 819, Address: 0x10068b0 */
    {
      for (x = 0; x < 10; ++x) /* Line 821, Address: 0x10068bc */
      {
        SetGrid(-1, x, y, *pSmap, 0); /* Line 823, Address: 0x10068c8 */
        ++pSmap; /* Line 824, Address: 0x10068f0 */
      } /* Line 825, Address: 0x10068f4 */
    } /* Line 826, Address: 0x1006904 */
  }

} /* Line 829, Address: 0x1006914 */

static void SubCpuMain() { /* Line 831, Address: 0x1006950 */
  if (bGameInit == 0) player(); /* Line 832, Address: 0x1006958 */

  if (comflag_s & 16) /* Line 834, Address: 0x1006970 */
  {
    cd_call(); /* Line 836, Address: 0x1006988 */
    cgdata_change(); /* Line 837, Address: 0x1006990 */
    comflag_s &= 239; /* Line 838, Address: 0x1006998 */
  }
  kaiten0(); /* Line 840, Address: 0x10069ac */
  comflag_s &= 223; /* Line 841, Address: 0x10069b4 */
  if (comflag_m & 32) comflag_s |= 32; /* Line 842, Address: 0x10069c8 */
  else comflag_s &= 223; /* Line 843, Address: 0x10069fc */

} /* Line 845, Address: 0x1006a10 */

void v_int() { /* Line 847, Address: 0x1006a20 */
  PALETTEENTRY *lpPlanet, *lpBkg, *lpDst, *lpSpr;
  int i;

  switch (intmode) /* Line 851, Address: 0x1006a38 */
  {
    case 0:



    case 1:



    case 2:



    case 3:



    default:
      if (flash_flg == 0) /* Line 870, Address: 0x1006a74 */
      {
        if (--coltimer == 0) /* Line 872, Address: 0x1006a88 */
        {
          if (colorno >= 31) colorno = 0; /* Line 874, Address: 0x1006aac */
          coltimer = lpbs_timer[colorno]; /* Line 875, Address: 0x1006ad0 */
          lpPlanet = lp_coltbl[lplanet_no * 2][colorno]; /* Line 876, Address: 0x1006afc */
          lpBkg = lp_coltbl[lplanet_no * 2 + 1][colorno]; /* Line 877, Address: 0x1006b40 */
          ++colorno; /* Line 878, Address: 0x1006b88 */
          lpDst = lpcolorwk0; /* Line 879, Address: 0x1006b9c */
          for (i = 0; i < 16; ++i) *lpDst++ = *lpBkg++; /* Line 880, Address: 0x1006ba4 */
          for (i = 0; i < 16; ++i) *lpDst++ = *lpPlanet++; /* Line 881, Address: 0x1006bf0 */
        }
        if (--spr_coltimer <= 0) /* Line 883, Address: 0x1006c3c */
        {
          lpSpr = sprite_color[spr_colno / 2]; /* Line 885, Address: 0x1006c68 */
          lpDst = lpcolorwk0 + 32; /* Line 886, Address: 0x1006ca4 */
          for (i = 0; i < 16; ++i) *lpDst++ = *lpSpr++; /* Line 887, Address: 0x1006cb0 */
          if (spr_colno == 0) spr_colno = 2; /* Line 888, Address: 0x1006cfc */
          else spr_colno = 0; /* Line 889, Address: 0x1006d28 */
          spr_coltimer = 5; /* Line 890, Address: 0x1006d30 */
        }
      }
  }
  if (funka_pctimer > 0) --funka_pctimer; /* Line 894, Address: 0x1006d3c */
  if (gmtime0 != 0) --gmtime0; /* Line 895, Address: 0x1006d68 */
  ++gmtime1; /* Line 896, Address: 0x1006d94 */
} /* Line 897, Address: 0x1006da8 */

static void cgmwrt_a() { /* Line 899, Address: 0x1006dd0 */
  int x, y;

  for (y = 0; y < 3; ++y) /* Line 902, Address: 0x1006de0 */
  {
    for (x = 0; x < 40; ++x) /* Line 904, Address: 0x1006dec */
    {
      SetGrid(0, x, y, 32818, 0); /* Line 906, Address: 0x1006df8 */
    } /* Line 907, Address: 0x1006e1c */
  } /* Line 908, Address: 0x1006e2c */
  for (y += 22; y < 28; ++y) /* Line 909, Address: 0x1006e3c */
  {
    for (x = 0; x < 40; ++x) /* Line 911, Address: 0x1006e48 */
    {
      SetGrid(0, x, y, 32818, 0); /* Line 913, Address: 0x1006e54 */
    } /* Line 914, Address: 0x1006e78 */
  } /* Line 915, Address: 0x1006e88 */

} /* Line 917, Address: 0x1006e98 */

static void cgmwrt_b() { /* Line 919, Address: 0x1006eb0 */
  short* pA1;
  int x, y, i;

  for (y = 0; y < 3; ++y) /* Line 923, Address: 0x1006ec8 */
  {
    for (x = 0; x < 40; ++x) /* Line 925, Address: 0x1006ed4 */
    {
      SetGrid(1, x, y, 49, 0); /* Line 927, Address: 0x1006ee0 */
    } /* Line 928, Address: 0x1006f04 */
  } /* Line 929, Address: 0x1006f14 */
  pA1 = ScrBMap; /* Line 930, Address: 0x1006f24 */
  for ( ; y < 25; ++y) /* Line 931, Address: 0x1006f2c */
  {
    for (x = 0; x < 32; ++x) /* Line 933, Address: 0x1006f34 */
    {
      SetGrid(0, x, y, *pA1, 0); /* Line 935, Address: 0x1006f40 */
      ++pA1; /* Line 936, Address: 0x1006f6c */
    } /* Line 937, Address: 0x1006f70 */
    pA1 -= 11; /* Line 938, Address: 0x1006f80 */
    for (i = 1; i <= 8; ++i) /* Line 939, Address: 0x1006f84 */
    {
      SetGrid(0, x, y, pA1[i], 0); /* Line 941, Address: 0x1006f90 */
      ++x; /* Line 942, Address: 0x1006fc4 */
    } /* Line 943, Address: 0x1006fc8 */
    pA1 += 11; /* Line 944, Address: 0x1006fd8 */
  } /* Line 945, Address: 0x1006fdc */
  for ( ; y < 28; ++y) /* Line 946, Address: 0x1006fec */
  {
    for (x = 0; x < 40; ++x) /* Line 948, Address: 0x1006ff4 */
    {
      SetGrid(1, x, y, 49, 0); /* Line 950, Address: 0x1007000 */
    } /* Line 951, Address: 0x1007024 */
  } /* Line 952, Address: 0x1007034 */

} /* Line 954, Address: 0x1007044 */











































static void cd_call() { /* Line 998, Address: 0x1007070 */
  CDPlay(DATable[comdata_m4]); /* Line 999, Address: 0x1007078 */
} /* Line 1000, Address: 0x10070a8 */
