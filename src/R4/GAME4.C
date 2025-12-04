#include "..\EQU.H"
#include "GAME4.H"
#include "..\ACTION.H"
#include "..\ACTSET.H"
#include "..\ETC.H"
#include "..\FCOL.H"
#include "..\IO.H"
#include "..\LOADER2.H"
#include "..\SCORE.H"
#include "COL4A.H"
#include "DEV41A.H"

extern void scr_set(void);
extern void scroll(void);
extern void scrollwrt(void);
extern void mapwrt(void);
extern void mapinit(void);

static void back_to_cnt(void);
static void bye_cnt(void);

static short Interupt_Counter;
static unsigned int PauseIcon;
extern bmp_info SprBmp[700];
void(*sMemCpy)(void*, void*, int);
unsigned int* lpghWnd;
void(*sCloseFile)(int);
int(*sReadFile)(int, void*, int);
int(*sOpenFile)(char*);
void(*sOutputDebugString)(char*);
void(*sPrintf)(char*, char*);
int(*sRandom)(void);
void(*sMemSet)(void*, unsigned char, int);
void(*WaveAllStop)(void);
void(*ChangeTileBmp)(int, int);
void(*CDPause)(short);
void(*CDPlay)(short);
void(*WaveRequest)(short);
void(*ClrSpriteDebug)(void);
void(*EAsprset)(short, short, unsigned short, unsigned short, unsigned short);
int(*SetGrid)(int, int, int, int);
extern unsigned char zone1scd[1000];
extern short_union watercolitbl[];
dlink_export ExportedFunctions = {
  &game_init,
  (void (*)(void))&game,
  &DLL_meminit,
  &DLL_memfree,
  (void (*)(short, short))&SWdataSet,
  &Get_vscroll,
  &Get_scra_h_posiw,
  &Get_scrb_h_posiw,
  &FadeProc,
  &SetDebugFlag,
  &GetRoundStr,
  0
};
int(*sGetFileSize)(int);













































































void DLL_meminit(char*** pBufTbl, void** pFuncTbl) { /* Line 136, Address: 0x1017bf0 */


  SetGrid = *pFuncTbl++; /* Line 139, Address: 0x1017c00 */
  EAsprset = *pFuncTbl++; /* Line 140, Address: 0x1017c18 */
  ClrSpriteDebug = *pFuncTbl++; /* Line 141, Address: 0x1017c30 */
  WaveRequest = *pFuncTbl++; /* Line 142, Address: 0x1017c48 */
  CDPlay = *pFuncTbl++; /* Line 143, Address: 0x1017c60 */
  CDPause = *pFuncTbl++; /* Line 144, Address: 0x1017c78 */
  ChangeTileBmp = *pFuncTbl++; /* Line 145, Address: 0x1017c90 */
  ++pFuncTbl; /* Line 146, Address: 0x1017ca8 */
  ++pFuncTbl; /* Line 147, Address: 0x1017cb4 */
  ++pFuncTbl; /* Line 148, Address: 0x1017cc0 */
  WaveAllStop = *pFuncTbl++; /* Line 149, Address: 0x1017ccc */

  ++pFuncTbl; /* Line 151, Address: 0x1017ce4 */
  ++pFuncTbl; /* Line 152, Address: 0x1017cf0 */
  sMemSet = *pFuncTbl++; /* Line 153, Address: 0x1017cfc */
  sMemCpy = *pFuncTbl++; /* Line 154, Address: 0x1017d14 */
  ++pFuncTbl; /* Line 155, Address: 0x1017d2c */
  sRandom = *pFuncTbl++; /* Line 156, Address: 0x1017d38 */
  ++pFuncTbl; /* Line 157, Address: 0x1017d50 */
  ++pFuncTbl; /* Line 158, Address: 0x1017d5c */
  ++pFuncTbl; /* Line 159, Address: 0x1017d68 */
  sPrintf = *pFuncTbl++; /* Line 160, Address: 0x1017d74 */
  sOutputDebugString = *pFuncTbl++; /* Line 161, Address: 0x1017d8c */
  sOpenFile = *pFuncTbl++; /* Line 162, Address: 0x1017da4 */
  sReadFile = *pFuncTbl++; /* Line 163, Address: 0x1017dbc */
  sCloseFile = *pFuncTbl++; /* Line 164, Address: 0x1017dd4 */
  ++pFuncTbl; /* Line 165, Address: 0x1017dec */




  pmapwk = (unsigned short*)**pBufTbl++; /* Line 170, Address: 0x1017df8 */
  lpcolorwk = (PALETTEENTRY*)**pBufTbl++; /* Line 171, Address: 0x1017e14 */
  lpcolorwk2 = (PALETTEENTRY*)**pBufTbl++; /* Line 172, Address: 0x1017e30 */
  lpcolorwk3 = (PALETTEENTRY*)**pBufTbl++; /* Line 173, Address: 0x1017e4c */
  lpcolorwk4 = (PALETTEENTRY*)**pBufTbl++; /* Line 174, Address: 0x1017e68 */
  lphscrollbuff = (int_union*)**pBufTbl++; /* Line 175, Address: 0x1017e84 */
  lpFadeFlag = (int*)*pBufTbl++; /* Line 176, Address: 0x1017ea0 */
  lpKeepWork = (game_info*)*pBufTbl++; /* Line 177, Address: 0x1017eb8 */
  ++pBufTbl; /* Line 178, Address: 0x1017ed0 */
  lpghWnd = (unsigned int*)*pBufTbl++; /* Line 179, Address: 0x1017edc */

  plring = lpKeepWork->plring; /* Line 181, Address: 0x1017ef4 */
  plscore = lpKeepWork->plscore; /* Line 182, Address: 0x1017f08 */
  stageno.w = lpKeepWork->stageno.w; /* Line 183, Address: 0x1017f1c */
  play_start = lpKeepWork->play_start; /* Line 184, Address: 0x1017f30 */
  pl_suu = lpKeepWork->pl_suu; /* Line 185, Address: 0x1017f44 */
  generate_flag = lpKeepWork->generate_flag; /* Line 186, Address: 0x1017f58 */
  time_flag = lpKeepWork->time_flag; /* Line 187, Address: 0x1017f6c */
  plflag = lpKeepWork->plflag; /* Line 188, Address: 0x1017f80 */
  clrspflg_save = lpKeepWork->clrspflg_save; /* Line 189, Address: 0x1017f94 */
  ta_flag = lpKeepWork->ta_flag; /* Line 190, Address: 0x1017fa8 */
  gf_flag = lpKeepWork->gf_flag; /* Line 191, Address: 0x1017fbc */
  projector_flag = lpKeepWork->projector_flag; /* Line 192, Address: 0x1017fd0 */
  extrascore = lpKeepWork->extrascore; /* Line 193, Address: 0x1017fe4 */
  emie3end = lpKeepWork->emie3end; /* Line 194, Address: 0x1017ff8 */

  flagworkcnt = lpKeepWork->flagworkcnt; /* Line 196, Address: 0x101800c */
  flagworkcnt2 = lpKeepWork->flagworkcnt2; /* Line 197, Address: 0x1018020 */
  sMemCpy(flagwork, lpKeepWork->flagwork, sizeof(flagwork)); /* Line 198, Address: 0x1018034 */

  lpKeepWork->pSprBmp = SprBmp; /* Line 200, Address: 0x101805c */


} /* Line 203, Address: 0x1018070 */



void DLL_memfree(void) {} /* Line 207, Address: 0x1018080 */


int Get_vscroll(void) {
  return vscroll.l; /* Line 211, Address: 0x1018090 */
} /* Line 212, Address: 0x1018098 */

int Get_scra_h_posiw(void) {
  return scra_h_posiw.l; /* Line 215, Address: 0x10180a0 */
} /* Line 216, Address: 0x10180a8 */

int Get_scrb_h_posiw(void) {
  return scrb_h_posiw.l; /* Line 219, Address: 0x10180b0 */
} /* Line 220, Address: 0x10180b8 */


void SetDebugFlag(unsigned int NewVal) { /* Line 223, Address: 0x10180c0 */
  if (NewVal == 1) debugflag.w |= 256; /* Line 224, Address: 0x10180c8 */
  else debugflag.w &= -257; /* Line 225, Address: 0x10180f4 */

} /* Line 227, Address: 0x101810c */




int game(void) { /* Line 232, Address: 0x1018120 */
  if (swdata1.b.l & 128) { /* Line 233, Address: 0x1018128 */
    if (pauseflag.b.h) { /* Line 234, Address: 0x1018140 */
      if (swdata2.w & 32896) { /* Line 235, Address: 0x1018150 */
        if (PauseIcon != 0) pauseflag.b.h = 0, PauseIcon = 0; /* Line 236, Address: 0x1018168 */
      } else pauseflag.b.h = 0; /* Line 237, Address: 0x1018188 */
      CDPause(1); /* Line 238, Address: 0x1018198 */
    } else { /* Line 239, Address: 0x10181ac */
      if (swdata2.w & 32896) pauseflag.b.h = 1, PauseIcon = 1; /* Line 240, Address: 0x10181b4 */
      else pauseflag.b.h = 1; /* Line 241, Address: 0x10181ec */
      CDPause(0); /* Line 242, Address: 0x10181f8 */
    }
  }












  if (pauseflag.b.h & 1) { /* Line 257, Address: 0x101820c */
    sdfdout(); /* Line 258, Address: 0x1018224 */
  }
  if ((swdata1.b.l & 112) == 112) { /* Line 260, Address: 0x101822c */

    pauseflag.b.h = 0; /* Line 262, Address: 0x1018248 */
    markerno = 0; /* Line 263, Address: 0x1018250 */
    demoflag.w = 0; /* Line 264, Address: 0x1018258 */
    gameflag.w = 1; /* Line 265, Address: 0x1018260 */
    lpKeepWork->ta_time = -1; /* Line 266, Address: 0x101826c */
    --pl_suu; /* Line 267, Address: 0x101827c */
    if ((char)pl_suu < 0) { /* Line 268, Address: 0x1018290 */
      pl_suu = 0; /* Line 269, Address: 0x10182b0 */
    }
    sub_sync(14); /* Line 271, Address: 0x10182b8 */
    flagwkclr(); /* Line 272, Address: 0x10182c4 */
    plflag = 0; /* Line 273, Address: 0x10182cc */
  }

  if (pauseflag.b.h & 1) return 0; /* Line 276, Address: 0x10182d4 */


  if (gameflag.w != 1) { /* Line 279, Address: 0x10182f8 */
    sdfdin(); /* Line 280, Address: 0x1018314 */
    ++gametimer.w; /* Line 281, Address: 0x101831c */
    actsetchk(); /* Line 282, Address: 0x1018330 */
    action(); /* Line 283, Address: 0x1018338 */
  }
  ((unsigned int)demo_cnt ^ 2048) < 1; /* Line 285, Address: 0x1018340 */


  if (gameflag.w) { /* Line 288, Address: 0x1018358 */



    lpKeepWork->plring = plring; /* Line 292, Address: 0x1018368 */
    lpKeepWork->plscore = plscore; /* Line 293, Address: 0x101837c */
    lpKeepWork->stageno.w = stageno.w; /* Line 294, Address: 0x1018390 */
    lpKeepWork->play_start = play_start; /* Line 295, Address: 0x10183a4 */
    lpKeepWork->pl_suu = pl_suu; /* Line 296, Address: 0x10183b8 */
    lpKeepWork->generate_flag = generate_flag; /* Line 297, Address: 0x10183cc */
    lpKeepWork->time_flag = time_flag; /* Line 298, Address: 0x10183e0 */
    lpKeepWork->clrspflg_save = clrspflg_save; /* Line 299, Address: 0x10183f4 */
    lpKeepWork->gf_flag = gf_flag; /* Line 300, Address: 0x1018408 */
    lpKeepWork->projector_flag = projector_flag; /* Line 301, Address: 0x101841c */
    lpKeepWork->special_flag = special_flag; /* Line 302, Address: 0x1018430 */
    lpKeepWork->extrascore = extrascore; /* Line 303, Address: 0x1018444 */
    lpKeepWork->plflag = plflag; /* Line 304, Address: 0x1018458 */
    lpKeepWork->emie3end = emie3end; /* Line 305, Address: 0x101846c */

    if (gameflag.b.h != 1) { /* Line 307, Address: 0x1018480 */
      flagwkclr(); /* Line 308, Address: 0x101849c */
    }
    lpKeepWork->flagworkcnt = flagworkcnt; /* Line 310, Address: 0x10184a4 */
    lpKeepWork->flagworkcnt2 = flagworkcnt2; /* Line 311, Address: 0x10184b8 */
    sMemCpy(lpKeepWork->flagwork , flagwork, sizeof(flagwork)); /* Line 312, Address: 0x10184cc */

    if (gameflag.w == 2) { /* Line 314, Address: 0x10184f4 */

      lpKeepWork->ta_time = (unsigned long int)(unsigned int)pltime.b.b3 * 60 + (unsigned long int)(unsigned int)pltime.b.b2 * 60 * 60 + (unsigned long int)(unsigned int)pltime.b.b4; /* Line 316, Address: 0x1018510 */
    } /* Line 317, Address: 0x1018598 */
    else if (gameflag.w == 1) { /* Line 318, Address: 0x10185a0 */
      lpKeepWork->ta_time = -1; /* Line 319, Address: 0x10185bc */
    }
    return gameflag.w; /* Line 321, Address: 0x10185cc */
  }
  if (editmode.w) { /* Line 323, Address: 0x10185e4 */
    scroll(); /* Line 324, Address: 0x10185f4 */
  } /* Line 325, Address: 0x10185fc */
  else {
    if (actwk[0].r_no0 >= 6) { /* Line 327, Address: 0x1018604 */
      scralim_down = scra_v_posit.w.h; /* Line 328, Address: 0x101861c */
      scralim_n_down = scra_v_posit.w.h; /* Line 329, Address: 0x101862c */
    } /* Line 330, Address: 0x101863c */
    else {

      scroll(); /* Line 333, Address: 0x1018644 */
    }
  }


  watercoli(); /* Line 338, Address: 0x101864c */
  patset(); /* Line 339, Address: 0x1018654 */
  if (!time_stop) { /* Line 340, Address: 0x101865c */
    clchgctr(); /* Line 341, Address: 0x101866c */
  }

  syspatchg(); /* Line 344, Address: 0x1018674 */


  watercnt(); /* Line 347, Address: 0x101867c */
#if defined(CG_CHANGE)
  if (!time_stop) {
    cg_change();
  }
#endif

  scra_h_posiw.l = scra_h_posit.l; /* Line 354, Address: 0x1018684 */
  scra_v_posiw.l = scra_v_posit.l; /* Line 355, Address: 0x1018694 */
  scrb_h_posiw.l = scrb_h_posit.l; /* Line 356, Address: 0x10186a4 */
  scrb_v_posiw.l = scrb_v_posit.l; /* Line 357, Address: 0x10186b4 */
  scrc_h_posiw.l = scrc_h_posit.l; /* Line 358, Address: 0x10186c4 */
  scrc_v_posiw.l = scrc_v_posit.l; /* Line 359, Address: 0x10186d4 */
  scrz_h_posiw.l = scrz_h_posit.l; /* Line 360, Address: 0x10186e4 */
  scrz_v_posiw.l = scrz_v_posit.l; /* Line 361, Address: 0x10186f4 */
  scrflagaw.w = scrflaga.w; /* Line 362, Address: 0x1018704 */
  scrflagbw.w = scrflagb.w; /* Line 363, Address: 0x1018714 */
  scrflagcw.w = scrflagc.w; /* Line 364, Address: 0x1018724 */
  scrflagzw.w = scrflagz.w; /* Line 365, Address: 0x1018734 */
  scrollwrt(); /* Line 366, Address: 0x1018744 */
  scoreset(); /* Line 367, Address: 0x101874c */

  if (!pauseflag.b.h) { /* Line 369, Address: 0x1018754 */
    bye_cnt(); /* Line 370, Address: 0x1018764 */
    back_to_cnt(); /* Line 371, Address: 0x101876c */
  }

  ++systemtimer.l; /* Line 374, Address: 0x1018774 */
  return 0; /* Line 375, Address: 0x1018788 */
} /* Line 376, Address: 0x101878c */



void game_init(void) { /* Line 380, Address: 0x10187a0 */

  unsigned short waterpositbl[12] = { /* Line 382, Address: 0x10187a8 */
     768,  640,  464,
    4095, 1456, 1328,
    1296, 4095, 1168,
    1168, 1168, 4095
  };


  ReadScrolMap(); /* Line 390, Address: 0x10187dc */
  ReadBlockMap(); /* Line 391, Address: 0x10187e4 */

  actset_rno.w = 0; /* Line 393, Address: 0x10187ec */
  demoflag.w = 0; /* Line 394, Address: 0x10187f4 */
  if (clrspflg_save == 127 && ta_flag == 0) { /* Line 395, Address: 0x10187fc */
    generate_flag = 1; /* Line 396, Address: 0x1018828 */
  }


  init_flag = 0; /* Line 400, Address: 0x1018834 */
  int_flg = 0; /* Line 401, Address: 0x101883c */
  main_play = 0; /* Line 402, Address: 0x1018844 */
  pauseflag.b.h = 0; /* Line 403, Address: 0x101884c */

  if (!(play_start & 1)) { /* Line 405, Address: 0x1018854 */
    play_start |= 1; /* Line 406, Address: 0x101886c */
    start_flag = 0; /* Line 407, Address: 0x1018880 */
    markerno = 0; /* Line 408, Address: 0x1018888 */
    extrascore = 5000; /* Line 409, Address: 0x1018890 */
    flagwkclr(); /* Line 410, Address: 0x101889c */
    plflag = 0; /* Line 411, Address: 0x10188a4 */
    gf_flag = 0; /* Line 412, Address: 0x10188ac */
    plscore = 0; /* Line 413, Address: 0x10188b4 */
    pl_suu = 3; /* Line 414, Address: 0x10188bc */
    if (ta_flag != 0) { /* Line 415, Address: 0x10188c8 */
      pl_suu = 1; /* Line 416, Address: 0x10188dc */
    }
  } /* Line 418, Address: 0x10188e8 */
  else {
    play_start |= 1; /* Line 420, Address: 0x10188f0 */
  }


  da_set(); /* Line 424, Address: 0x1018904 */



  plsubchg_flag = 0; /* Line 428, Address: 0x101890c */
  sMemSet(flowercnt, 0, sizeof(flowercnt)); /* Line 429, Address: 0x1018914 */
  sMemSet(pbuffer, 0, sizeof(pbuffer)); /* Line 430, Address: 0x1018934 */
  sMemSet(flowerposi, 0, sizeof(flowerposi)); /* Line 431, Address: 0x1018954 */
  sMemSet(actwk, 0, sizeof(actwk)); /* Line 432, Address: 0x1018974 */
  sMemSet(flowwk, 0, sizeof(flowwk)); /* Line 433, Address: 0x1018994 */



  intcnt.w = 0; /* Line 437, Address: 0x10189b4 */
  int_flg = 0; /* Line 438, Address: 0x10189bc */
  linkdata = 0; /* Line 439, Address: 0x10189c4 */
  cltbladr = 0; /* Line 440, Address: 0x10189cc */
  ranum = 0; /* Line 441, Address: 0x10189d4 */
  pauseflag.w = 0; /* Line 442, Address: 0x10189dc */
  cgwrtcnt = 0; /* Line 443, Address: 0x10189e4 */
  cgwrttim = 0; /* Line 444, Address: 0x10189ec */
  dmastack = 0; /* Line 445, Address: 0x10189f4 */
  waterposi = 0; /* Line 446, Address: 0x10189fc */
  waterposi_m = 0; /* Line 447, Address: 0x1018a04 */
  watermoveposi = 0; /* Line 448, Address: 0x1018a0c */
  waterspeed = 0; /* Line 449, Address: 0x1018a14 */
  water_flag = 0; /* Line 450, Address: 0x1018a1c */
  waterflag = 0; /* Line 451, Address: 0x1018a24 */
  waterflag2 = 0; /* Line 452, Address: 0x1018a2c */
  sMemSet(cgchgcnt, 0, sizeof(cgchgcnt)); /* Line 453, Address: 0x1018a34 */
  sMemSet(cgchgtim, 0, sizeof(cgchgtim)); /* Line 454, Address: 0x1018a54 */


  scra_h_posit.l = 0; /* Line 457, Address: 0x1018a74 */
  scra_v_posit.l = 0; /* Line 458, Address: 0x1018a7c */
  scrb_h_posit.l = 0; /* Line 459, Address: 0x1018a84 */
  scrb_v_posit.l = 0; /* Line 460, Address: 0x1018a8c */
  scrc_h_posit.l = 0; /* Line 461, Address: 0x1018a94 */
  scrc_v_posit.l = 0; /* Line 462, Address: 0x1018a9c */
  scrz_h_posit.l = 0; /* Line 463, Address: 0x1018aa4 */
  scrz_v_posit.l = 0; /* Line 464, Address: 0x1018aac */
  scralim_n_left = 0; /* Line 465, Address: 0x1018ab4 */
  scralim_n_right = 0; /* Line 466, Address: 0x1018abc */
  scralim_n_up = 0; /* Line 467, Address: 0x1018ac4 */
  scralim_n_down = 0; /* Line 468, Address: 0x1018acc */
  scralim_left = 0; /* Line 469, Address: 0x1018ad4 */
  scralim_right = 0; /* Line 470, Address: 0x1018adc */
  scralim_up = 0; /* Line 471, Address: 0x1018ae4 */
  scralim_down = 0; /* Line 472, Address: 0x1018aec */
  scrar_no = 0; /* Line 473, Address: 0x1018af4 */
  scra_h_keep = 0; /* Line 474, Address: 0x1018afc */
  scra_v_keep = 0; /* Line 475, Address: 0x1018b04 */
  scra_hz = 0; /* Line 476, Address: 0x1018b0c */
  scra_vz = 0; /* Line 477, Address: 0x1018b14 */
  scra_vline = 0; /* Line 478, Address: 0x1018b1c */
  scrh_flag = 0; /* Line 479, Address: 0x1018b24 */
  scrv_flag = 0; /* Line 480, Address: 0x1018b2c */
  zone_flag.w = 0; /* Line 481, Address: 0x1018b34 */
  scroll_start.w = 0; /* Line 482, Address: 0x1018b3c */
  scr_die.w = 0; /* Line 483, Address: 0x1018b44 */
  scr_timer.w = 0; /* Line 484, Address: 0x1018b4c */
  scra_h_count = 0; /* Line 485, Address: 0x1018b54 */
  scra_v_count = 0; /* Line 486, Address: 0x1018b5c */
  scrb_h_count = 0; /* Line 487, Address: 0x1018b64 */
  scrb_v_count = 0; /* Line 488, Address: 0x1018b6c */
  scrc_h_count = 0; /* Line 489, Address: 0x1018b74 */
  scrc_v_count = 0; /* Line 490, Address: 0x1018b7c */
  scrz_h_count = 0; /* Line 491, Address: 0x1018b84 */
  scrz_v_count = 0; /* Line 492, Address: 0x1018b8c */
  scrflaga.w = 0; /* Line 493, Address: 0x1018b94 */
  scrflagb.w = 0; /* Line 494, Address: 0x1018b9c */
  scrflagc.w = 0; /* Line 495, Address: 0x1018ba4 */
  scrflagz.w = 0; /* Line 496, Address: 0x1018bac */
  limmoveflag = 0; /* Line 497, Address: 0x1018bb4 */
  playpatno1 = 0; /* Line 498, Address: 0x1018bbc */
  kusya_flag = 0; /* Line 499, Address: 0x1018bc4 */
  plmaxspdwk = 0; /* Line 500, Address: 0x1018bcc */
  pladdspdwk = 0; /* Line 501, Address: 0x1018bd4 */
  plretspdwk = 0; /* Line 502, Address: 0x1018bdc */
  playpatno = 0; /* Line 503, Address: 0x1018be4 */
  playwrtflag = 0; /* Line 504, Address: 0x1018bec */
  sMemSet(dirstk, 0, sizeof(dirstk)); /* Line 505, Address: 0x1018bf4 */
  actset_rno.w = 0; /* Line 506, Address: 0x1018c14 */
  asetposi = 0; /* Line 507, Address: 0x1018c1c */
  asetadr = 0; /* Line 508, Address: 0x1018c24 */
  asetadr2 = 0; /* Line 509, Address: 0x1018c2c */
  asetadrz = 0; /* Line 510, Address: 0x1018c34 */
  asetadrz2 = 0; /* Line 511, Address: 0x1018c3c */
  byecnt0.w = 0; /* Line 512, Address: 0x1018c44 */
  byecnt1.w = 0; /* Line 513, Address: 0x1018c4c */
  time_item = 0; /* Line 514, Address: 0x1018c54 */
  backto_cnt = 0; /* Line 515, Address: 0x1018c5c */
  scr_cnt = 0; /* Line 516, Address: 0x1018c64 */
  demo_adr = 0; /* Line 517, Address: 0x1018c6c */
  demo_cnt = 0; /* Line 518, Address: 0x1018c74 */
  swbufcnt = 0; /* Line 519, Address: 0x1018c7c */
  scdadr = 0; /* Line 520, Address: 0x1018c84 */
  scra_hline = 0; /* Line 521, Address: 0x1018c8c */
  bossflag = 0; /* Line 522, Address: 0x1018c94 */
  plposiwkadr.w = 0; /* Line 523, Address: 0x1018c9c */
  bossstart = 0; /* Line 524, Address: 0x1018ca4 */
  loopmapno = 0; /* Line 525, Address: 0x1018cac */
  loopmapno2 = 0; /* Line 526, Address: 0x1018cb4 */
  ballmapno = 0; /* Line 527, Address: 0x1018cbc */
  ballmapno2 = 0; /* Line 528, Address: 0x1018cc4 */
  sMemSet(clchgcnt, 0, sizeof(clchgcnt)); /* Line 529, Address: 0x1018ccc */
  sMemSet(clchgtim, 0, sizeof(clchgtim)); /* Line 530, Address: 0x1018cec */
  watercoliflag = 0; /* Line 531, Address: 0x1018d0c */
  waterstop = 0; /* Line 532, Address: 0x1018d14 */
  mizuflag = 0; /* Line 533, Address: 0x1018d1c */
  sekichyuflag = 0; /* Line 534, Address: 0x1018d24 */
  plautoflag = 0; /* Line 535, Address: 0x1018d2c */
  specflag = 0; /* Line 536, Address: 0x1018d34 */
  dai2rmvflag = 0; /* Line 537, Address: 0x1018d3c */
  emyscorecnt = 0; /* Line 538, Address: 0x1018d44 */
  timebonus = 0; /* Line 539, Address: 0x1018d4c */
  ringbonus = 0; /* Line 540, Address: 0x1018d54 */
  bonus_f = 0; /* Line 541, Address: 0x1018d5c */
  edplayflag = 0; /* Line 542, Address: 0x1018d64 */
  waterdirec.w = 0; /* Line 543, Address: 0x1018d6c */
  ms_wflg = 0; /* Line 544, Address: 0x1018d74 */
  sMemSet(switchflag, 0, sizeof(switchflag)); /* Line 545, Address: 0x1018d7c */


  demo_cnt = 0; /* Line 548, Address: 0x1018d9c */


  tv_flag = 0; /* Line 551, Address: 0x1018da4 */
  editno.w = 0; /* Line 552, Address: 0x1018dac */
  editmode.w = 0; /* Line 553, Address: 0x1018db4 */
  edittimer = 0; /* Line 554, Address: 0x1018dbc */
  systemtimer.l = 0; /* Line 555, Address: 0x1018dc4 */
  time_stop = 0; /* Line 556, Address: 0x1018dcc */
  sys_pattim = 0; /* Line 557, Address: 0x1018dd4 */
  sys_patno = 0; /* Line 558, Address: 0x1018ddc */
  sys_pattim2 = 0; /* Line 559, Address: 0x1018de4 */
  sys_patno2 = 0; /* Line 560, Address: 0x1018dec */
  sys_pattim3 = 0; /* Line 561, Address: 0x1018df4 */
  sys_patno3 = 0; /* Line 562, Address: 0x1018dfc */
  sys_pattim4 = 0; /* Line 563, Address: 0x1018e04 */
  sys_patno4 = 0; /* Line 564, Address: 0x1018e0c */
  sys_ringtimer = 0; /* Line 565, Address: 0x1018e14 */
  editstack = 0; /* Line 566, Address: 0x1018e1c */
  editstack2 = 0; /* Line 567, Address: 0x1018e24 */
  mapcheck = 0; /* Line 568, Address: 0x1018e2c */
  scra_h_posiw.l = 0; /* Line 569, Address: 0x1018e34 */
  scra_v_posiw.l = 0; /* Line 570, Address: 0x1018e3c */
  scrb_h_posiw.l = 0; /* Line 571, Address: 0x1018e44 */
  scrb_v_posiw.l = 0; /* Line 572, Address: 0x1018e4c */
  scrc_h_posiw.l = 0; /* Line 573, Address: 0x1018e54 */
  scrc_v_posiw.l = 0; /* Line 574, Address: 0x1018e5c */
  scrz_h_posiw.l = 0; /* Line 575, Address: 0x1018e64 */
  scrz_v_posiw.l = 0; /* Line 576, Address: 0x1018e6c */
  scrflagaw.w = 0; /* Line 577, Address: 0x1018e74 */
  scrflagbw.w = 0; /* Line 578, Address: 0x1018e7c */
  scrflagcw.w = 0; /* Line 579, Address: 0x1018e84 */
  scrflagzw.w = 0; /* Line 580, Address: 0x1018e8c */
  blkno = 0; /* Line 581, Address: 0x1018e94 */
  col_y.w = 0; /* Line 582, Address: 0x1018e9c */
  col_x.w = 0; /* Line 583, Address: 0x1018ea4 */
  edit_user = 0; /* Line 584, Address: 0x1018eac */
  sysdirec = 0; /* Line 585, Address: 0x1018eb4 */
  prio_flag = 0; /* Line 586, Address: 0x1018ebc */
  init_flag = 0; /* Line 587, Address: 0x1018ec4 */
  boss_sound = 0; /* Line 588, Address: 0x1018ecc */
  shut_flag = 0; /* Line 589, Address: 0x1018ed4 */
  st6clrchg = 0; /* Line 590, Address: 0x1018edc */
  chibi_flag = 0; /* Line 591, Address: 0x1018ee4 */
  mapwrt_cnt = 0; /* Line 592, Address: 0x1018eec */
  sMemSet(linework, 0, sizeof(linework)); /* Line 593, Address: 0x1018ef4 */

  scrinit(); /* Line 595, Address: 0x1018f14 */


  if (stageno.b.h == 2) { /* Line 598, Address: 0x1018f1c */


    waterposi = waterpositbl[(time_flag & 127) + stageno.b.l * 4]; /* Line 601, Address: 0x1018f38 */
    waterposi_m = waterpositbl[(time_flag & 127) + stageno.b.l * 4]; /* Line 602, Address: 0x1018f74 */
    watermoveposi = waterpositbl[(time_flag & 127) + stageno.b.l * 4]; /* Line 603, Address: 0x1018fb0 */

    water_flag = 0; /* Line 605, Address: 0x1018fec */
    waterflag = 0; /* Line 606, Address: 0x1018ff4 */
    waterspeed = 1; /* Line 607, Address: 0x1018ffc */

    watercnt(); /* Line 609, Address: 0x1019008 */
  }


  pl_air = 30; /* Line 613, Address: 0x1019010 */

  colorset2(3); /* Line 615, Address: 0x101901c */
  colorset(3); /* Line 616, Address: 0x1019028 */


  scr_set(); /* Line 619, Address: 0x1019034 */
  scroll(); /* Line 620, Address: 0x101903c */
  scrflaga.b.h |= 4; /* Line 621, Address: 0x1019044 */
  mapinit(); /* Line 622, Address: 0x1019058 */
  mapwrt(); /* Line 623, Address: 0x1019060 */

  scdcnv(); /* Line 625, Address: 0x1019068 */
  scdset(); /* Line 626, Address: 0x1019070 */




  play_act_set(); /* Line 631, Address: 0x1019078 */
  actwk[2].actno = 28; /* Line 632, Address: 0x1019080 */
  actwk[3].actno = 28; /* Line 633, Address: 0x101908c */
  actwk[3].userflag.b.h = 1; /* Line 634, Address: 0x1019098 */
  actwk[5].actno = 28; /* Line 635, Address: 0x10190a4 */
  actwk[5].userflag.b.l = 1; /* Line 636, Address: 0x10190b0 */



  actwk[31].actno = 25; /* Line 640, Address: 0x10190bc */
  actwk[31].userflag.b.h = 10; /* Line 641, Address: 0x10190c8 */
  if (!(play_start & 2)) { /* Line 642, Address: 0x10190d4 */
    play_start |= 2; /* Line 643, Address: 0x10190ec */
    actwk[4].actno = 60; /* Line 644, Address: 0x1019100 */
    plautoflag = 1; /* Line 645, Address: 0x101910c */
    enecgflg = 0; /* Line 646, Address: 0x1019118 */
  }

  actwk[32].actno = 4; /* Line 649, Address: 0x1019120 */
  swdata.w = 0; /* Line 650, Address: 0x101912c */
  swdata1.w = 0; /* Line 651, Address: 0x1019134 */
  swdata2.w = 0; /* Line 652, Address: 0x101913c */
  byecnt0.w = 0; /* Line 653, Address: 0x1019144 */
  byecnt1.w = 0; /* Line 654, Address: 0x101914c */


  if (plflag == 0) { /* Line 657, Address: 0x1019154 */
    plring = 0; /* Line 658, Address: 0x1019168 */
    pltime.l = 0; /* Line 659, Address: 0x1019170 */
    plring_f2 = 0; /* Line 660, Address: 0x1019178 */
  }

  pltimeover_f = plpower_b = plpower_m = plpower_s = plpower_a = 0; /* Line 663, Address: 0x1019180 */
  editmode.w = gameflag.w = gametimer.w = 0; /* Line 664, Address: 0x10191b8 */
  plflag = 0; /* Line 665, Address: 0x10191e0 */
  plscore_f = plring_f = pltime_f = pl_suu_f = 1; /* Line 666, Address: 0x10191e8 */
  plring_f = 128; /* Line 667, Address: 0x1019218 */

  plscore_f = 128; /* Line 669, Address: 0x1019224 */

  swbufcnt = 0; /* Line 671, Address: 0x1019230 */
  startcolor = 32; /* Line 672, Address: 0x1019238 */
  colorcnt = 47; /* Line 673, Address: 0x1019244 */
#if defined(CG_CHANGE)
  cg_change();
#endif
  tv_flag = 1; /* Line 677, Address: 0x1019250 */


  if (stageno.b.h == 2) colorset3(0); /* Line 680, Address: 0x101925c */
  gmmode.b.h &= 127; /* Line 681, Address: 0x1019284 */
  init_flag = 1; /* Line 682, Address: 0x1019298 */


  game(); /* Line 685, Address: 0x10192a4 */
  scra_h_posiw.w.h -= 16; /* Line 686, Address: 0x10192ac */
  mapwrt(); /* Line 687, Address: 0x10192c0 */
  scra_h_posiw.w.h += 16; /* Line 688, Address: 0x10192c8 */

  if (time_flag & 128) { /* Line 690, Address: 0x10192dc */

    flashin(); /* Line 692, Address: 0x10192f4 */
  } /* Line 693, Address: 0x10192fc */
  else {



    fadein0(); /* Line 698, Address: 0x1019304 */
  }

} /* Line 701, Address: 0x101930c */




void play_act_set(void) {
  actwk[0].actno = 1; /* Line 707, Address: 0x1019320 */
  if (plflag) { /* Line 708, Address: 0x101932c */
    ((short*)&actwk[0])[26] = 120; /* Line 709, Address: 0x101933c */
  }
} /* Line 711, Address: 0x1019348 */

























void flow_act_set(void) {} /* Line 737, Address: 0x1019350 */


void scdset(void) {
  scdadr = zone1scd; /* Line 741, Address: 0x1019360 */

} /* Line 743, Address: 0x1019370 */


void syspatchg(void) {
  if (--sys_pattim & 128) { /* Line 747, Address: 0x1019380 */
    sys_pattim = 11; /* Line 748, Address: 0x10193a8 */
    sys_patno = sys_patno - 1 & 7; /* Line 749, Address: 0x10193b4 */
  }
  if (--sys_pattim2 & 128) { /* Line 751, Address: 0x10193d4 */
    sys_pattim2 = 7; /* Line 752, Address: 0x10193fc */
    sys_patno2 = sys_patno2 + 1 & 3; /* Line 753, Address: 0x1019408 */
  }
  if (--sys_pattim3 & 128) { /* Line 755, Address: 0x1019428 */
    sys_pattim3 = 7; /* Line 756, Address: 0x1019450 */
    if (++sys_patno3 >= 6) sys_patno3 = 0; /* Line 757, Address: 0x101945c */
  }
  if (sys_pattim4) { /* Line 759, Address: 0x101948c */
    sys_ringtimer += (unsigned short)sys_pattim4; /* Line 760, Address: 0x101949c */


    sys_patno4 = sys_ringtimer >> 9 & 3; /* Line 763, Address: 0x10194c4 */
    --sys_pattim4; /* Line 764, Address: 0x10194e8 */
  }

} /* Line 767, Address: 0x10194fc */


static void back_to_cnt(void) {
  if (!actwk[0].actfree[0]) { /* Line 771, Address: 0x1019510 */
    if (backto_cnt) { /* Line 772, Address: 0x1019520 */
      ++backto_cnt; /* Line 773, Address: 0x1019530 */
    }
  }

} /* Line 777, Address: 0x1019544 */




static void bye_cnt(void) {
  if (byecnt0.w) { /* Line 783, Address: 0x1019550 */
    ++byecnt0.w; /* Line 784, Address: 0x1019560 */
  }

  if (byecnt1.w) { /* Line 787, Address: 0x1019574 */
    ++byecnt1.w; /* Line 788, Address: 0x1019584 */
  }


} /* Line 792, Address: 0x1019598 */




void sdfdout(void) { /* Line 797, Address: 0x10195a0 */
  soundset(171); /* Line 798, Address: 0x10195a8 */
  if (!(pauseflag.b.h | 128)) { /* Line 799, Address: 0x10195b4 */


    pauseflag.b.h |= 128; /* Line 802, Address: 0x10195cc */
    if (!(time_flag & 127)) { /* Line 803, Address: 0x10195e0 */

      if (plpower_m || plpower_s) { /* Line 805, Address: 0x10195f8 */
        sub_sync(144); /* Line 806, Address: 0x1019618 */
        return; /* Line 807, Address: 0x1019624 */
      }
    }

    sub_sync(213); /* Line 811, Address: 0x101962c */
  }
} /* Line 813, Address: 0x1019638 */


void sdfdin(void) { /* Line 816, Address: 0x1019650 */
  if (pauseflag.b.h & 128) { /* Line 817, Address: 0x1019658 */


    pauseflag.b.h &= 127; /* Line 820, Address: 0x1019670 */
    if (!(time_flag & 127)) { /* Line 821, Address: 0x1019684 */

      if (plpower_m || plpower_s) { /* Line 823, Address: 0x101969c */
        sub_sync(145); /* Line 824, Address: 0x10196bc */
        return; /* Line 825, Address: 0x10196c8 */
      }
    }

    sub_sync(214); /* Line 829, Address: 0x10196d0 */
  }
} /* Line 831, Address: 0x10196dc */






void da_set(void) { /* Line 838, Address: 0x10196f0 */
  unsigned short wD0;
  static unsigned char da_tbl[7][4] = {
    {  48,  15,  17,  16 },
    {  49,  18,  20,  19 },
    {  50,  21,  23,  22 },
    {  51,  24,  26,  25 },
    {  52,  27,  29,  28 },
    {  53,  30,  32,  31 },
    {  54,  33, 102,  34 }
  };

  wD0 = time_flag & 127; /* Line 850, Address: 0x10196fc */
  if (!ta_flag) { /* Line 851, Address: 0x1019714 */
    if (wD0 == 2) { /* Line 852, Address: 0x1019724 */
      wD0 += generate_flag; /* Line 853, Address: 0x1019734 */
    }
  }

  sub_sync((unsigned short)da_tbl[stageno.b.h][wD0]); /* Line 857, Address: 0x1019748 */


} /* Line 860, Address: 0x1019788 */






void water1chk(void) { /* Line 867, Address: 0x10197a0 */
  short wD1;

  if (!(time_flag & 127)) return; /* Line 870, Address: 0x10197a8 */

  if ((time_flag & 127) == 1) { /* Line 872, Address: 0x10197c0 */
    wD1 = 640; /* Line 873, Address: 0x10197dc */
    if ((unsigned short)actwk[0].xposi.w.h >= 1504) wD1 = 608; /* Line 874, Address: 0x10197e8 */
  } /* Line 875, Address: 0x1019810 */
  else {

    wD1 = 464; /* Line 878, Address: 0x1019818 */
    if (actwk[0].xposi.w.h >= 2336) { /* Line 879, Address: 0x1019824 */
      wD1 = 272; /* Line 880, Address: 0x1019840 */
      if (actwk[0].xposi.w.h >= 6528) { /* Line 881, Address: 0x101984c */
        wD1 = 576; /* Line 882, Address: 0x1019868 */
        waterspeed = 3; /* Line 883, Address: 0x1019874 */
      }
    }
  }

  watermoveposi = wD1; /* Line 888, Address: 0x1019880 */
} /* Line 889, Address: 0x1019888 */



void water2chk(void) { /* Line 893, Address: 0x10198a0 */
  short wD1;

  wD1 = scra_v_posit.w.h + 232; /* Line 896, Address: 0x10198a8 */

  if (actwk[0].xposi.w.h < 512) { /* Line 898, Address: 0x10198cc */
    waterposi_m = wD1; /* Line 899, Address: 0x10198e8 */
    watermoveposi = wD1; /* Line 900, Address: 0x10198f0 */
    return; /* Line 901, Address: 0x10198f8 */
  }
  if (actwk[0].yposi.w.h >= 1536) { /* Line 903, Address: 0x1019900 */
    if (actwk[0].yposi.w.h < 1728) { /* Line 904, Address: 0x101991c */
      if (actwk[0].xposi.w.h < 672) { /* Line 905, Address: 0x1019938 */
        waterposi_m = wD1; /* Line 906, Address: 0x1019954 */
        watermoveposi = wD1; /* Line 907, Address: 0x101995c */
        return; /* Line 908, Address: 0x1019964 */
      }
    }
  }

  if (!(time_flag & 127)) { /* Line 913, Address: 0x101996c */
    wD1 = 1456; /* Line 914, Address: 0x1019984 */
    waterposi_m = wD1; /* Line 915, Address: 0x1019990 */
    watermoveposi = wD1; /* Line 916, Address: 0x1019998 */
    return; /* Line 917, Address: 0x10199a0 */
  }

  if ((time_flag & 127) == 1) { /* Line 920, Address: 0x10199a8 */
    wD1 = 1328; /* Line 921, Address: 0x10199c4 */
    if (actwk[0].xposi.w.h >= 3072) { /* Line 922, Address: 0x10199d0 */
      wD1 = 1920; /* Line 923, Address: 0x10199ec */
      if (actwk[0].xposi.w.h >= 3520) { /* Line 924, Address: 0x10199f8 */
        wD1 = 1280; /* Line 925, Address: 0x1019a14 */
        if (actwk[0].xposi.w.h < 4992) { /* Line 926, Address: 0x1019a20 */
          if (actwk[0].yposi.w.h >= 1024) return; /* Line 927, Address: 0x1019a3c */
          wD1 = 960; /* Line 928, Address: 0x1019a58 */
          if (actwk[0].xposi.w.h < 4352) return; /* Line 929, Address: 0x1019a64 */
        }
      }
    }
  } /* Line 933, Address: 0x1019a80 */
  else {

    wD1 = 1296; /* Line 936, Address: 0x1019a88 */
    if (actwk[0].xposi.w.h >= 1024) { /* Line 937, Address: 0x1019a94 */
      wD1 = 912; /* Line 938, Address: 0x1019ab0 */
      if (actwk[0].xposi.w.h >= 5632) { /* Line 939, Address: 0x1019abc */
        wD1 = 1040; /* Line 940, Address: 0x1019ad8 */
        if (actwk[0].xposi.w.h >= 6400) wD1 = 1280; /* Line 941, Address: 0x1019ae4 */
      }
    }
  }

  watermoveposi = wD1; /* Line 946, Address: 0x1019b0c */
} /* Line 947, Address: 0x1019b14 */



void water3chk(void) { /* Line 951, Address: 0x1019b30 */
  short wD1;

  wD1 = scra_v_posit.w.h + 232; /* Line 954, Address: 0x1019b38 */
  if (actwk[0].xposi.w.h < 1984) waterposi_m = wD1; /* Line 955, Address: 0x1019b5c */
  else {

    wD1 = 1168; /* Line 958, Address: 0x1019b88 */
    if (actwk[0].xposi.w.h >= 2800) { /* Line 959, Address: 0x1019b94 */
      waterspeed = 2; /* Line 960, Address: 0x1019bb0 */
      wD1 = 1472; /* Line 961, Address: 0x1019bbc */
    }
  }

  watermoveposi = wD1; /* Line 965, Address: 0x1019bc8 */
} /* Line 966, Address: 0x1019bd0 */



void watercntsub(void) { /* Line 970, Address: 0x1019be0 */
  unsigned short wD1;

  void(*watertbl[3])(void) = { /* Line 973, Address: 0x1019bec */
    &water1chk,
    &water2chk,
    &water3chk
  };

  watertbl[stageno.b.l](); /* Line 979, Address: 0x1019c10 */

  wD1 = waterspeed; /* Line 981, Address: 0x1019c34 */
  if (watermoveposi != waterposi_m) { /* Line 982, Address: 0x1019c44 */
    if (watermoveposi < waterposi_m) wD1 *= -1; /* Line 983, Address: 0x1019c6c */

    waterposi_m += wD1; /* Line 985, Address: 0x1019ca4 */
  }

} /* Line 988, Address: 0x1019cc0 */



void watercnt(void) { /* Line 992, Address: 0x1019ce0 */
  short wD0, wD1;

  if (!pauseflag.b.h) { /* Line 995, Address: 0x1019ce8 */
    if (actwk[0].r_no0 < 6) watercntsub(); /* Line 996, Address: 0x1019cf8 */

    waterflag = 0; /* Line 998, Address: 0x1019d18 */
    sysdirec += 2; /* Line 999, Address: 0x1019d20 */
    sinset(sysdirec, &wD0, &wD1); /* Line 1000, Address: 0x1019d34 */
    waterposi = (short)(char)((unsigned short)wD0 >> 6) + waterposi_m; /* Line 1001, Address: 0x1019d4c */

    wD0 = waterposi - scra_v_posit.w.h; /* Line 1003, Address: 0x1019d98 */
    if ((unsigned short)waterposi < (unsigned short)scra_v_posit.w.h) { /* Line 1004, Address: 0x1019dc8 */
      if (wD0 < 0) { /* Line 1005, Address: 0x1019df4 */
        hintposi.b.l = -33; /* Line 1006, Address: 0x1019e08 */
        waterflag = 1; /* Line 1007, Address: 0x1019e14 */
      }
    }

    if ((unsigned short)wD0 >= 223) wD0 = 223; /* Line 1011, Address: 0x1019e20 */

    hintposi.b.l = (unsigned char)wD0; /* Line 1013, Address: 0x1019e40 */
  }

  lpKeepWork->hintposi.w = hintposi.w; /* Line 1016, Address: 0x1019e58 */
  lpKeepWork->waterflag = waterflag; /* Line 1017, Address: 0x1019e6c */
} /* Line 1018, Address: 0x1019e80 */



void watercoli(void) { /* Line 1022, Address: 0x1019e90 */
  int i;

  if (actwk[0].mstno.b.h == 43) return; /* Line 1025, Address: 0x1019e98 */

  if (actwk[0].actfree[2] & 1) return; /* Line 1027, Address: 0x1019eb4 */

  if (!actwk[0].actno) return; /* Line 1029, Address: 0x1019ecc */

  if (editmode.w) return; /* Line 1031, Address: 0x1019edc */

  if (stageno.b.l >= 2) return; /* Line 1033, Address: 0x1019eec */



  for (i = 0; watercolitbl[i].w >= 0; i += 7) { /* Line 1037, Address: 0x1019f08 */
    if (actwk[0].xposi.w.h < watercolitbl[i].w) continue; /* Line 1038, Address: 0x1019f14 */
    if (actwk[0].xposi.w.h >= watercolitbl[i + 2].w) continue; /* Line 1039, Address: 0x1019f4c */
    if (actwk[0].yposi.w.h < watercolitbl[i + 1].w) continue; /* Line 1040, Address: 0x1019f88 */
    if (actwk[0].yposi.w.h >= watercolitbl[i + 3].w) continue; /* Line 1041, Address: 0x1019fc4 */

    if (((char*)&watercolitbl[i + 6])[1] == 1) { /* Line 1043, Address: 0x101a000 */
      if (!(switchflag[((char*)&watercolitbl[i + 6])[0]] & 64)) return; /* Line 1044, Address: 0x101a02c */
    }

    if (actwk[0].r_no0 >= 4) { /* Line 1047, Address: 0x101a06c */
      watercoliflag = 0; /* Line 1048, Address: 0x101a084 */
      return; /* Line 1049, Address: 0x101a08c */
    }
    watercoliflag = 1; /* Line 1051, Address: 0x101a094 */
    actwk[0].actfree[18] = 0; /* Line 1052, Address: 0x101a0a0 */
    actwk[0].xspeed.w = watercolitbl[i + 4].w; /* Line 1053, Address: 0x101a0a8 */
    actwk[0].yspeed.w = watercolitbl[i + 5].w; /* Line 1054, Address: 0x101a0c8 */
    actwk[0].mstno.b.h = 15; /* Line 1055, Address: 0x101a0e8 */
    actwk[0].cddat |= 2; /* Line 1056, Address: 0x101a0f4 */

    if (((char*)&watercolitbl[i + 6])[1] == 2) { /* Line 1058, Address: 0x101a108 */
      if (switchflag[((char*)&watercolitbl[i + 6])[0]] & 32) { /* Line 1059, Address: 0x101a134 */
        actwk[0].xspeed.w *= -1; /* Line 1060, Address: 0x101a174 */
        actwk[0].yspeed.w *= -1; /* Line 1061, Address: 0x101a188 */
      }
    }

    if (swdata.b.h & 1) --actwk[0].yposi.w.h; /* Line 1065, Address: 0x101a19c */

    if (swdata.b.h & 2) ++actwk[0].yposi.w.h; /* Line 1067, Address: 0x101a1c8 */

    if (swdata.b.h & 4) --actwk[0].xposi.w.h; /* Line 1069, Address: 0x101a1f4 */

    if (swdata.b.h & 8) ++actwk[0].xposi.w.h; /* Line 1071, Address: 0x101a220 */

    return; /* Line 1073, Address: 0x101a24c */




  } /* Line 1078, Address: 0x101a254 */

  if (!watercoliflag) return; /* Line 1080, Address: 0x101a27c */

  actwk[0].mstno.b.h = 0; /* Line 1082, Address: 0x101a28c */

  watercoliflag = 0; /* Line 1084, Address: 0x101a294 */
} /* Line 1085, Address: 0x101a29c */
