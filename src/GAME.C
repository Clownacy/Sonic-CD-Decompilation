#include "EQU.H"
#include "GAME.H"
#include "ACTION.H"
#include "ACTSET.H"
#include "FCOL.H"
#include "IO.H"
#include "LOADER2.H"
#include "SCORE.H"

extern void sub_sync(short ReqNo);
extern void scroll();
extern void clchgctr();
extern void scrollwrt();
extern void cg_change();
extern void colorset2(int ColorNo);
extern void colorset(int ColorNo);
extern void scr_set();
extern void mapinit();
extern void mapwrt();
extern void flashin();
extern void fadein0();

short Interupt_Counter;
unsigned int PauseIcon;
extern bmp_info SprBmp[700];
void(*sMemCpy)(void*, void*, int);
unsigned int* lpghWnd;
void(*sCloseFile)(int);
int(*sReadFile)(int, void*, int);
int(*sOpenFile)(char*);
void(*sOutputDebugString)(char*);
void(*sPrintf)(char*, char*);
int(*sRandom)();
void(*sMemSet)(void*, unsigned char, int);
void(*WaveAllStop)();
void(*ChangeTileBmp)(int, int);
void(*CDPause)(short);
void(*CDPlay)(short);
void(*WaveRequest)(short);
void(*ClrSpriteDebug)();
void(*EAsprset)(short, short, unsigned short, unsigned short, unsigned short);
int(*SetGrid)(int, int, int, int);
extern unsigned char zone1scd[];
dlink_export ExportedFunctions;
int(*sGetFileSize)(int);



















































































































































void DLL_meminit(char*** pBufTbl, void** pFuncTbl) { /* Line 193, Address: 0x1017a10 */




  SetGrid = (int(*)(int, int, int, int))pFuncTbl++; /* Line 198, Address: 0x1017a20 */
  EAsprset = (void(*)(short, short, unsigned short, unsigned short, unsigned short))pFuncTbl++; /* Line 199, Address: 0x1017a38 */
  ClrSpriteDebug = (void(*)())pFuncTbl++; /* Line 200, Address: 0x1017a50 */
  WaveRequest = (void(*)(short))pFuncTbl++; /* Line 201, Address: 0x1017a68 */
  CDPlay = (void(*)(short))pFuncTbl++; /* Line 202, Address: 0x1017a80 */
  CDPause = (void(*)(short))pFuncTbl++; /* Line 203, Address: 0x1017a98 */
  ChangeTileBmp = (void(*)(int, int))pFuncTbl++; /* Line 204, Address: 0x1017ab0 */
  ++pFuncTbl; /* Line 205, Address: 0x1017ac8 */
  ++pFuncTbl; /* Line 206, Address: 0x1017ad4 */
  ++pFuncTbl; /* Line 207, Address: 0x1017ae0 */
  WaveAllStop = (void(*)())pFuncTbl++; /* Line 208, Address: 0x1017aec */

  ++pFuncTbl; /* Line 210, Address: 0x1017b04 */
  ++pFuncTbl; /* Line 211, Address: 0x1017b10 */
  sMemSet = (void(*)(void*, unsigned char, int))pFuncTbl++; /* Line 212, Address: 0x1017b1c */
  sMemCpy = (void(*)(void*, void*, int))pFuncTbl++; /* Line 213, Address: 0x1017b34 */
  ++pFuncTbl; /* Line 214, Address: 0x1017b4c */
  sRandom = (int(*)())pFuncTbl++; /* Line 215, Address: 0x1017b58 */
  ++pFuncTbl; /* Line 216, Address: 0x1017b70 */
  ++pFuncTbl; /* Line 217, Address: 0x1017b7c */
  ++pFuncTbl; /* Line 218, Address: 0x1017b88 */
  sPrintf = (void(*)(char*, char*))pFuncTbl++; /* Line 219, Address: 0x1017b94 */
  sOutputDebugString = (void(*)(char*))pFuncTbl++; /* Line 220, Address: 0x1017bac */
  sOpenFile = (int(*)(char*))pFuncTbl++; /* Line 221, Address: 0x1017bc4 */
  sReadFile = (int(*)(int, void*, int))pFuncTbl++; /* Line 222, Address: 0x1017bdc */
  sCloseFile = (void(*)(int))pFuncTbl++; /* Line 223, Address: 0x1017bf4 */
  ++pFuncTbl; /* Line 224, Address: 0x1017c0c */





























  pmapwk = (unsigned short*)*pBufTbl++; /* Line 254, Address: 0x1017c18 */
  lpcolorwk = (palette_entry*)*pBufTbl++; /* Line 255, Address: 0x1017c34 */
  lpcolorwk2 = (palette_entry*)*pBufTbl++; /* Line 256, Address: 0x1017c50 */
  lpcolorwk3 = (palette_entry*)*pBufTbl++; /* Line 257, Address: 0x1017c6c */
  lpcolorwk4 = (palette_entry*)*pBufTbl++; /* Line 258, Address: 0x1017c88 */
  lphscrollbuff = (int_union*)*pBufTbl++; /* Line 259, Address: 0x1017ca4 */
  lpFadeFlag = (int*)pBufTbl++; /* Line 260, Address: 0x1017cc0 */
  lpKeepWork = (game_info*)pBufTbl++; /* Line 261, Address: 0x1017cd8 */
  ++pBufTbl; /* Line 262, Address: 0x1017cf0 */
  lpghWnd = (unsigned int*)pBufTbl++; /* Line 263, Address: 0x1017cfc */


  plring = lpKeepWork->plring; /* Line 266, Address: 0x1017d14 */
  plscore = lpKeepWork->plscore; /* Line 267, Address: 0x1017d28 */
  stageno = lpKeepWork->stageno; /* Line 268, Address: 0x1017d3c */
  play_start = lpKeepWork->play_start; /* Line 269, Address: 0x1017d50 */
  pl_suu = lpKeepWork->pl_suu; /* Line 270, Address: 0x1017d64 */
  generate_flag = lpKeepWork->generate_flag; /* Line 271, Address: 0x1017d78 */
  time_flag = lpKeepWork->time_flag; /* Line 272, Address: 0x1017d8c */
  plflag = lpKeepWork->plflag; /* Line 273, Address: 0x1017da0 */
  clrspflg_save = lpKeepWork->clrspflg_save; /* Line 274, Address: 0x1017db4 */
  ta_flag = lpKeepWork->ta_flag; /* Line 275, Address: 0x1017dc8 */
  gf_flag = lpKeepWork->gf_flag; /* Line 276, Address: 0x1017ddc */
  projector_flag = lpKeepWork->projector_flag; /* Line 277, Address: 0x1017df0 */
  extrascore = lpKeepWork->extrascore; /* Line 278, Address: 0x1017e04 */
  emie3end = lpKeepWork->emie3end; /* Line 279, Address: 0x1017e18 */

  flagworkcnt = lpKeepWork->flagworkcnt; /* Line 281, Address: 0x1017e2c */
  flagworkcnt2 = lpKeepWork->flagworkcnt2; /* Line 282, Address: 0x1017e40 */
  sMemCpy(flagwork, lpKeepWork->flagwork, 766); /* Line 283, Address: 0x1017e54 */

  lpKeepWork->pSprBmp = SprBmp; /* Line 285, Address: 0x1017e7c */


} /* Line 288, Address: 0x1017e90 */



void DLL_memfree() {} /* Line 292, Address: 0x1017ea0 */




void Print_Msg() {} /* Line 297, Address: 0x1017eb0 */

int Get_vscroll() { /* Line 299, Address: 0x1017ec0 */

  Print_Msg(); /* Line 301, Address: 0x1017ec8 */
  return vscroll.l; /* Line 302, Address: 0x1017ed0 */
} /* Line 303, Address: 0x1017ed8 */

int Get_scra_h_posiw() {
  return scra_h_posiw.l; /* Line 306, Address: 0x1017ef0 */
} /* Line 307, Address: 0x1017ef8 */

int Get_scrb_h_posiw() {
  return scrb_h_posiw.l; /* Line 310, Address: 0x1017f00 */
} /* Line 311, Address: 0x1017f08 */


void SetDebugFlag(unsigned int NewVal) { /* Line 314, Address: 0x1017f10 */
  if (NewVal == 1) debugflag.w |= 256; /* Line 315, Address: 0x1017f18 */
  else debugflag.w &= -257; /* Line 316, Address: 0x1017f44 */

} /* Line 318, Address: 0x1017f5c */




int game() { /* Line 323, Address: 0x1017f70 */

  if (swdata1.b.l & 128) { /* Line 325, Address: 0x1017f78 */
    if (pauseflag.b.h != 0) { /* Line 326, Address: 0x1017f90 */
      if (swdata2.w & 32896) { /* Line 327, Address: 0x1017fa0 */
        if (PauseIcon) pauseflag.b.h = 0, PauseIcon = 0; /* Line 328, Address: 0x1017fb8 */
      } else pauseflag.b.h = 0; /* Line 329, Address: 0x1017fd8 */
      CDPause(1); /* Line 330, Address: 0x1017fe8 */
    } else { /* Line 331, Address: 0x1017ffc */
      if (swdata2.w & 32896) pauseflag.b.h = 1, PauseIcon = 1; /* Line 332, Address: 0x1018004 */
      else pauseflag.b.h = 1; /* Line 333, Address: 0x101803c */
      CDPause(0); /* Line 334, Address: 0x1018048 */
    }
  }




















  if (pauseflag.b.h & 1) { /* Line 357, Address: 0x101805c */
    sdfdout(); /* Line 358, Address: 0x1018074 */
  }
  if ((swdata1.b.l & 112) == 112) { /* Line 360, Address: 0x101807c */

    pauseflag.b.h = 0; /* Line 362, Address: 0x1018098 */
    markerno = 0; /* Line 363, Address: 0x10180a0 */
    demoflag.w = 0; /* Line 364, Address: 0x10180a8 */
    gameflag.w = 1; /* Line 365, Address: 0x10180b0 */
    lpKeepWork->ta_time = -1; /* Line 366, Address: 0x10180bc */
    --pl_suu; /* Line 367, Address: 0x10180cc */
    if ((char)pl_suu < 0) { /* Line 368, Address: 0x10180e0 */
      pl_suu = 0; /* Line 369, Address: 0x1018100 */
    }
    sub_sync(14); /* Line 371, Address: 0x1018108 */
    flagwkclr(); /* Line 372, Address: 0x1018114 */
    plflag = 0; /* Line 373, Address: 0x101811c */
  }

  if (pauseflag.b.h & 1) return 0; /* Line 376, Address: 0x1018124 */


  if (gameflag.w != 1) { /* Line 379, Address: 0x1018148 */
    sdfdin(); /* Line 380, Address: 0x1018164 */
    ++gametimer.w; /* Line 381, Address: 0x101816c */
    actsetchk(); /* Line 382, Address: 0x1018180 */
    action(); /* Line 383, Address: 0x1018188 */
  }
  (demo_cnt ^ 2048) < 1U; /* Line 385, Address: 0x1018190 */


  if (gameflag.w != 0) { /* Line 388, Address: 0x10181a8 */



    lpKeepWork->plring = plring; /* Line 392, Address: 0x10181b8 */
    lpKeepWork->plscore = plscore; /* Line 393, Address: 0x10181cc */
    lpKeepWork->stageno = stageno; /* Line 394, Address: 0x10181e0 */
    lpKeepWork->play_start = play_start; /* Line 395, Address: 0x10181f4 */
    lpKeepWork->pl_suu = pl_suu; /* Line 396, Address: 0x1018208 */
    lpKeepWork->generate_flag = generate_flag; /* Line 397, Address: 0x101821c */
    lpKeepWork->time_flag = time_flag; /* Line 398, Address: 0x1018230 */
    lpKeepWork->clrspflg_save = clrspflg_save; /* Line 399, Address: 0x1018244 */
    lpKeepWork->gf_flag = gf_flag; /* Line 400, Address: 0x1018258 */
    lpKeepWork->projector_flag = projector_flag; /* Line 401, Address: 0x101826c */
    lpKeepWork->special_flag = special_flag; /* Line 402, Address: 0x1018280 */
    lpKeepWork->extrascore = extrascore; /* Line 403, Address: 0x1018294 */
    lpKeepWork->plflag = plflag; /* Line 404, Address: 0x10182a8 */
    lpKeepWork->emie3end = emie3end; /* Line 405, Address: 0x10182bc */

    if (gameflag.b.h != 1) { /* Line 407, Address: 0x10182d0 */
      flagwkclr(); /* Line 408, Address: 0x10182ec */
    }
    lpKeepWork->flagworkcnt = flagworkcnt; /* Line 410, Address: 0x10182f4 */
    lpKeepWork->flagworkcnt2 = flagworkcnt2; /* Line 411, Address: 0x1018308 */
    sMemCpy(lpKeepWork->flagwork, flagwork, 766); /* Line 412, Address: 0x101831c */

    if (gameflag.w == 2) { /* Line 414, Address: 0x1018344 */

      lpKeepWork->ta_time = pltime.b.b3 * 60 + pltime.b.b2 * 60 * 60 + pltime.b.b4; /* Line 416, Address: 0x1018360 */
    } /* Line 417, Address: 0x10183c8 */
    else if (gameflag.w == 1) { /* Line 418, Address: 0x10183d0 */
      lpKeepWork->ta_time = -1; /* Line 419, Address: 0x10183ec */
    }
    return gameflag.w; /* Line 421, Address: 0x10183fc */
  }
  if (editmode.w != 0) { /* Line 423, Address: 0x1018414 */
    scroll(); /* Line 424, Address: 0x1018424 */
  } /* Line 425, Address: 0x101842c */
  else {
    if (actwk[0].r_no0 >= 6) { /* Line 427, Address: 0x1018434 */
      scralim_down = scra_v_posit.w.h; /* Line 428, Address: 0x101844c */
      scralim_n_down = scra_v_posit.w.h; /* Line 429, Address: 0x101845c */
    } /* Line 430, Address: 0x101846c */
    else {

      scroll(); /* Line 433, Address: 0x1018474 */
    }
  }


  patset(); /* Line 438, Address: 0x101847c */
  if (time_stop == 0) { /* Line 439, Address: 0x1018484 */
    clchgctr(); /* Line 440, Address: 0x1018494 */
  }

  syspatchg(); /* Line 443, Address: 0x101849c */


  scra_h_posiw = scra_h_posit; /* Line 446, Address: 0x10184a4 */
  scra_v_posiw = scra_v_posit; /* Line 447, Address: 0x10184b4 */
  scrb_h_posiw = scrb_h_posit; /* Line 448, Address: 0x10184c4 */
  scrb_v_posiw = scrb_v_posit; /* Line 449, Address: 0x10184d4 */
  scrc_h_posiw = scrc_h_posit; /* Line 450, Address: 0x10184e4 */
  scrc_v_posiw = scrc_v_posit; /* Line 451, Address: 0x10184f4 */
  scrz_h_posiw = scrz_h_posit; /* Line 452, Address: 0x1018504 */
  scrz_v_posiw = scrz_v_posit; /* Line 453, Address: 0x1018514 */
  scrflagaw = scrflaga; /* Line 454, Address: 0x1018524 */
  scrflagbw = scrflagb; /* Line 455, Address: 0x1018534 */
  scrflagcw = scrflagc; /* Line 456, Address: 0x1018544 */
  scrflagzw = scrflagz; /* Line 457, Address: 0x1018554 */
  scrollwrt(); /* Line 458, Address: 0x1018564 */
  scoreset(); /* Line 459, Address: 0x101856c */

  /*cg_change(); */ /* Line 461, Address: 0x1018574 */


  if (pauseflag.b.h == 0) { /* Line 464, Address: 0x101857c */
    bye_cnt(); /* Line 465, Address: 0x101858c */
    back_to_cnt(); /* Line 466, Address: 0x1018594 */
  }

  ++systemtimer.l; /* Line 469, Address: 0x101859c */
  return 0; /* Line 470, Address: 0x10185b0 */
} /* Line 471, Address: 0x10185b4 */



void game_init() { /* Line 475, Address: 0x10185d0 */

  ReadScrolMap(); /* Line 477, Address: 0x10185d8 */
  ReadBlockMap(); /* Line 478, Address: 0x10185e0 */


  demoflag.w = 0; /* Line 481, Address: 0x10185e8 */
  if (clrspflg_save == 127 && ta_flag == 0) { /* Line 482, Address: 0x10185f0 */
    generate_flag = 1; /* Line 483, Address: 0x101861c */
  }


  init_flag = 0; /* Line 487, Address: 0x1018628 */
  int_flg = 0; /* Line 488, Address: 0x1018630 */
  main_play = 0; /* Line 489, Address: 0x1018638 */
  pauseflag.b.h = 0; /* Line 490, Address: 0x1018640 */

  if ((play_start & 1) == 0) { /* Line 492, Address: 0x1018648 */
    play_start |= 1; /* Line 493, Address: 0x1018660 */
    start_flag = 0; /* Line 494, Address: 0x1018674 */
    markerno = 0; /* Line 495, Address: 0x101867c */
    extrascore = 5000; /* Line 496, Address: 0x1018684 */
    flagwkclr(); /* Line 497, Address: 0x1018690 */
    plflag = 0; /* Line 498, Address: 0x1018698 */
    gf_flag = 0; /* Line 499, Address: 0x10186a0 */
    plscore = 0; /* Line 500, Address: 0x10186a8 */
    pl_suu = 3; /* Line 501, Address: 0x10186b0 */
    if (ta_flag != 0) { /* Line 502, Address: 0x10186bc */
      pl_suu = 1; /* Line 503, Address: 0x10186d0 */
    }
  } /* Line 505, Address: 0x10186dc */
  else {
    play_start |= 1; /* Line 507, Address: 0x10186e4 */
  }


  da_set(); /* Line 511, Address: 0x10186f8 */



  plsubchg_flag = 0; /* Line 515, Address: 0x1018700 */
  sMemSet(flowercnt, 0, 3); /* Line 516, Address: 0x1018708 */
  sMemSet(pbuffer, 0, 2048); /* Line 517, Address: 0x1018728 */
  sMemSet(flowerposi, 0, 768); /* Line 518, Address: 0x1018748 */
  sMemSet(actwk, 0, 8704); /* Line 519, Address: 0x1018768 */
  sMemSet(flowwk, 0, 4096); /* Line 520, Address: 0x1018788 */



  intcnt.w = 0; /* Line 524, Address: 0x10187a8 */
  int_flg = 0; /* Line 525, Address: 0x10187b0 */
  linkdata = 0; /* Line 526, Address: 0x10187b8 */
  cltbladr = 0; /* Line 527, Address: 0x10187c0 */
  ranum = 0; /* Line 528, Address: 0x10187c8 */
  pauseflag.w = 0; /* Line 529, Address: 0x10187d0 */
  cgwrtcnt = 0; /* Line 530, Address: 0x10187d8 */
  cgwrttim = 0; /* Line 531, Address: 0x10187e0 */
  dmastack = 0; /* Line 532, Address: 0x10187e8 */
  waterposi = 0; /* Line 533, Address: 0x10187f0 */
  waterposi_m = 0; /* Line 534, Address: 0x10187f8 */
  watermoveposi = 0; /* Line 535, Address: 0x1018800 */
  waterspeed = 0; /* Line 536, Address: 0x1018808 */
  water_flag = 0; /* Line 537, Address: 0x1018810 */
  waterflag = 0; /* Line 538, Address: 0x1018818 */
  waterflag2 = 0; /* Line 539, Address: 0x1018820 */
  sMemSet(cgchgcnt, 0, 6); /* Line 540, Address: 0x1018828 */
  sMemSet(cgchgtim, 0, 6); /* Line 541, Address: 0x1018848 */


  scra_h_posit.l = 0; /* Line 544, Address: 0x1018868 */
  scra_v_posit.l = 0; /* Line 545, Address: 0x1018870 */
  scrb_h_posit.l = 0; /* Line 546, Address: 0x1018878 */
  scrb_v_posit.l = 0; /* Line 547, Address: 0x1018880 */
  scrc_h_posit.l = 0; /* Line 548, Address: 0x1018888 */
  scrc_v_posit.l = 0; /* Line 549, Address: 0x1018890 */
  scrz_h_posit.l = 0; /* Line 550, Address: 0x1018898 */
  scrz_v_posit.l = 0; /* Line 551, Address: 0x10188a0 */
  scralim_n_left = 0; /* Line 552, Address: 0x10188a8 */
  scralim_n_right = 0; /* Line 553, Address: 0x10188b0 */
  scralim_n_up = 0; /* Line 554, Address: 0x10188b8 */
  scralim_n_down = 0; /* Line 555, Address: 0x10188c0 */
  scralim_left = 0; /* Line 556, Address: 0x10188c8 */
  scralim_right = 0; /* Line 557, Address: 0x10188d0 */
  scralim_up = 0; /* Line 558, Address: 0x10188d8 */
  scralim_down = 0; /* Line 559, Address: 0x10188e0 */
  scrar_no = 0; /* Line 560, Address: 0x10188e8 */
  scra_h_keep = 0; /* Line 561, Address: 0x10188f0 */
  scra_v_keep = 0; /* Line 562, Address: 0x10188f8 */
  scra_hz = 0; /* Line 563, Address: 0x1018900 */
  scra_vz = 0; /* Line 564, Address: 0x1018908 */
  scra_vline = 0; /* Line 565, Address: 0x1018910 */
  scrh_flag = 0; /* Line 566, Address: 0x1018918 */
  scrv_flag = 0; /* Line 567, Address: 0x1018920 */
  zone_flag.w = 0; /* Line 568, Address: 0x1018928 */
  scroll_start.w = 0; /* Line 569, Address: 0x1018930 */
  scr_die.w = 0; /* Line 570, Address: 0x1018938 */
  scr_timer.w = 0; /* Line 571, Address: 0x1018940 */
  scra_h_count = 0; /* Line 572, Address: 0x1018948 */
  scra_v_count = 0; /* Line 573, Address: 0x1018950 */
  scrb_h_count = 0; /* Line 574, Address: 0x1018958 */
  scrb_v_count = 0; /* Line 575, Address: 0x1018960 */
  scrc_h_count = 0; /* Line 576, Address: 0x1018968 */
  scrc_v_count = 0; /* Line 577, Address: 0x1018970 */
  scrz_h_count = 0; /* Line 578, Address: 0x1018978 */
  scrz_v_count = 0; /* Line 579, Address: 0x1018980 */
  scrflaga.w = 0; /* Line 580, Address: 0x1018988 */
  scrflagb.w = 0; /* Line 581, Address: 0x1018990 */
  scrflagc.w = 0; /* Line 582, Address: 0x1018998 */
  scrflagz.w = 0; /* Line 583, Address: 0x10189a0 */
  limmoveflag = 0; /* Line 584, Address: 0x10189a8 */
  playpatno1 = 0; /* Line 585, Address: 0x10189b0 */
  kusya_flag = 0; /* Line 586, Address: 0x10189b8 */
  plmaxspdwk = 0; /* Line 587, Address: 0x10189c0 */
  pladdspdwk = 0; /* Line 588, Address: 0x10189c8 */
  plretspdwk = 0; /* Line 589, Address: 0x10189d0 */
  playpatno = 0; /* Line 590, Address: 0x10189d8 */
  playwrtflag = 0; /* Line 591, Address: 0x10189e0 */
  sMemSet(dirstk, 0, 4); /* Line 592, Address: 0x10189e8 */
  actset_rno.w = 0; /* Line 593, Address: 0x1018a08 */
  asetposi = 0; /* Line 594, Address: 0x1018a10 */
  asetadr = 0; /* Line 595, Address: 0x1018a18 */
  asetadr2 = 0; /* Line 596, Address: 0x1018a20 */
  asetadrz = 0; /* Line 597, Address: 0x1018a28 */
  asetadrz2 = 0; /* Line 598, Address: 0x1018a30 */
  byecnt0.w = 0; /* Line 599, Address: 0x1018a38 */
  byecnt1.w = 0; /* Line 600, Address: 0x1018a40 */
  time_item = 0; /* Line 601, Address: 0x1018a48 */
  backto_cnt = 0; /* Line 602, Address: 0x1018a50 */
  scr_cnt = 0; /* Line 603, Address: 0x1018a58 */
  demo_adr = 0; /* Line 604, Address: 0x1018a60 */
  demo_cnt = 0; /* Line 605, Address: 0x1018a68 */
  swbufcnt = 0; /* Line 606, Address: 0x1018a70 */
  scdadr = 0; /* Line 607, Address: 0x1018a78 */
  scra_hline = 0; /* Line 608, Address: 0x1018a80 */
  bossflag = 0; /* Line 609, Address: 0x1018a88 */
  plposiwkadr.w = 0; /* Line 610, Address: 0x1018a90 */
  bossstart = 0; /* Line 611, Address: 0x1018a98 */
  loopmapno = 0; /* Line 612, Address: 0x1018aa0 */
  loopmapno2 = 0; /* Line 613, Address: 0x1018aa8 */
  ballmapno = 0; /* Line 614, Address: 0x1018ab0 */
  ballmapno2 = 0; /* Line 615, Address: 0x1018ab8 */
  sMemSet(clchgcnt, 0, 7); /* Line 616, Address: 0x1018ac0 */
  sMemSet(clchgtim, 0, 7); /* Line 617, Address: 0x1018ae0 */
  watercoliflag = 0; /* Line 618, Address: 0x1018b00 */
  waterstop = 0; /* Line 619, Address: 0x1018b08 */
  mizuflag = 0; /* Line 620, Address: 0x1018b10 */
  sekichyuflag = 0; /* Line 621, Address: 0x1018b18 */
  plautoflag = 0; /* Line 622, Address: 0x1018b20 */
  specflag = 0; /* Line 623, Address: 0x1018b28 */
  dai2rmvflag = 0; /* Line 624, Address: 0x1018b30 */
  emyscorecnt = 0; /* Line 625, Address: 0x1018b38 */
  timebonus = 0; /* Line 626, Address: 0x1018b40 */
  ringbonus = 0; /* Line 627, Address: 0x1018b48 */
  bonus_f = 0; /* Line 628, Address: 0x1018b50 */
  edplayflag = 0; /* Line 629, Address: 0x1018b58 */
  waterdirec.w = 0; /* Line 630, Address: 0x1018b60 */
  ms_wflg = 0; /* Line 631, Address: 0x1018b68 */
  sMemSet(switchflag, 0, 32); /* Line 632, Address: 0x1018b70 */


  demo_cnt = 0; /* Line 635, Address: 0x1018b90 */


  tv_flag = 0; /* Line 638, Address: 0x1018b98 */
  editno.w = 0; /* Line 639, Address: 0x1018ba0 */
  editmode.w = 0; /* Line 640, Address: 0x1018ba8 */
  edittimer = 0; /* Line 641, Address: 0x1018bb0 */
  systemtimer.l = 0; /* Line 642, Address: 0x1018bb8 */
  time_stop = 0; /* Line 643, Address: 0x1018bc0 */
  sys_pattim = 0; /* Line 644, Address: 0x1018bc8 */
  sys_patno = 0; /* Line 645, Address: 0x1018bd0 */
  sys_pattim2 = 0; /* Line 646, Address: 0x1018bd8 */
  sys_patno2 = 0; /* Line 647, Address: 0x1018be0 */
  sys_pattim3 = 0; /* Line 648, Address: 0x1018be8 */
  sys_patno3 = 0; /* Line 649, Address: 0x1018bf0 */
  sys_pattim4 = 0; /* Line 650, Address: 0x1018bf8 */
  sys_patno4 = 0; /* Line 651, Address: 0x1018c00 */
  sys_ringtimer = 0; /* Line 652, Address: 0x1018c08 */
  editstack = 0; /* Line 653, Address: 0x1018c10 */
  editstack2 = 0; /* Line 654, Address: 0x1018c18 */
  mapcheck = 0; /* Line 655, Address: 0x1018c20 */
  scra_h_posiw.l = 0; /* Line 656, Address: 0x1018c28 */
  scra_v_posiw.l = 0; /* Line 657, Address: 0x1018c30 */
  scrb_h_posiw.l = 0; /* Line 658, Address: 0x1018c38 */
  scrb_v_posiw.l = 0; /* Line 659, Address: 0x1018c40 */
  scrc_h_posiw.l = 0; /* Line 660, Address: 0x1018c48 */
  scrc_v_posiw.l = 0; /* Line 661, Address: 0x1018c50 */
  scrz_h_posiw.l = 0; /* Line 662, Address: 0x1018c58 */
  scrz_v_posiw.l = 0; /* Line 663, Address: 0x1018c60 */
  scrflagaw.w = 0; /* Line 664, Address: 0x1018c68 */
  scrflagbw.w = 0; /* Line 665, Address: 0x1018c70 */
  scrflagcw.w = 0; /* Line 666, Address: 0x1018c78 */
  scrflagzw.w = 0; /* Line 667, Address: 0x1018c80 */
  blkno = 0; /* Line 668, Address: 0x1018c88 */
  col_y.w = 0; /* Line 669, Address: 0x1018c90 */
  col_x.w = 0; /* Line 670, Address: 0x1018c98 */
  edit_user = 0; /* Line 671, Address: 0x1018ca0 */
  sysdirec = 0; /* Line 672, Address: 0x1018ca8 */
  prio_flag = 0; /* Line 673, Address: 0x1018cb0 */
  init_flag = 0; /* Line 674, Address: 0x1018cb8 */
  boss_sound = 0; /* Line 675, Address: 0x1018cc0 */
  shut_flag = 0; /* Line 676, Address: 0x1018cc8 */
  st6clrchg = 0; /* Line 677, Address: 0x1018cd0 */
  chibi_flag = 0; /* Line 678, Address: 0x1018cd8 */
  mapwrt_cnt = 0; /* Line 679, Address: 0x1018ce0 */
  sMemSet(linework, 0, 512); /* Line 680, Address: 0x1018ce8 */

  scrinit(); /* Line 682, Address: 0x1018d08 */


  pl_air = 30; /* Line 685, Address: 0x1018d10 */

  colorset2(3); /* Line 687, Address: 0x1018d1c */
  colorset(3); /* Line 688, Address: 0x1018d28 */


  scr_set(); /* Line 691, Address: 0x1018d34 */
  scroll(); /* Line 692, Address: 0x1018d3c */
  scrflaga.w |= 4; /* Line 693, Address: 0x1018d44 */

  mapinit(); /* Line 695, Address: 0x1018d58 */
  mapwrt(); /* Line 696, Address: 0x1018d60 */

  scdcnv(); /* Line 698, Address: 0x1018d68 */
  scdset(); /* Line 699, Address: 0x1018d70 */




  play_act_set(); /* Line 704, Address: 0x1018d78 */
  actwk[2].actno = 28; /* Line 705, Address: 0x1018d80 */
  actwk[3].actno = 28; /* Line 706, Address: 0x1018d8c */
  actwk[3].userflag.b.h = 1; /* Line 707, Address: 0x1018d98 */
  actwk[5].actno = 28; /* Line 708, Address: 0x1018da4 */
  actwk[5].userflag.b.l = 1; /* Line 709, Address: 0x1018db0 */



  actwk[31].actno = 25; /* Line 713, Address: 0x1018dbc */
  actwk[31].userflag.b.h = 10; /* Line 714, Address: 0x1018dc8 */

  if ((play_start & 2) == 0) { /* Line 716, Address: 0x1018dd4 */
    play_start |= 2; /* Line 717, Address: 0x1018dec */
    actwk[4].actno = 60; /* Line 718, Address: 0x1018e00 */
    plautoflag = 1; /* Line 719, Address: 0x1018e0c */
    enecgflg = 0; /* Line 720, Address: 0x1018e18 */
  }


  swdata.w = 0; /* Line 724, Address: 0x1018e20 */
  swdata1.w = 0; /* Line 725, Address: 0x1018e28 */
  swdata2.w = 0; /* Line 726, Address: 0x1018e30 */
  byecnt0.w = 0; /* Line 727, Address: 0x1018e38 */
  byecnt1.w = 0; /* Line 728, Address: 0x1018e40 */
  enkeino = 0; /* Line 729, Address: 0x1018e48 */

  if (plflag == 0) { /* Line 731, Address: 0x1018e50 */
    plring = 0; /* Line 732, Address: 0x1018e64 */
    pltime.l = 0; /* Line 733, Address: 0x1018e6c */
    plring_f2 = 0; /* Line 734, Address: 0x1018e74 */
  }

  pltimeover_f = plpower_b = plpower_m = plpower_s = plpower_a = 0; /* Line 737, Address: 0x1018e7c */
  editmode.w = gameflag.w = gametimer.w = 0; /* Line 738, Address: 0x1018eb4 */
  plflag = 0; /* Line 739, Address: 0x1018edc */
  plscore_f = plring_f = pltime_f = pl_suu_f = 1; /* Line 740, Address: 0x1018ee4 */
  plring_f = 128; /* Line 741, Address: 0x1018f14 */

  plscore_f = 128; /* Line 743, Address: 0x1018f20 */

  swbufcnt = 0; /* Line 745, Address: 0x1018f2c */
  startcolor = 32; /* Line 746, Address: 0x1018f34 */
  colorcnt = 47; /* Line 747, Address: 0x1018f40 */

  /* cg_change(); */ /* Line 749, Address: 0x1018f4c */

  tv_flag = 1; /* Line 751, Address: 0x1018f54 */


  gmmode.b.h %= 128; /* Line 754, Address: 0x1018f60 */
  init_flag = 1; /* Line 755, Address: 0x1018f74 */


  game(); /* Line 758, Address: 0x1018f80 */
  scra_h_posiw.w.h -= 16; /* Line 759, Address: 0x1018f88 */
  mapwrt(); /* Line 760, Address: 0x1018f9c */
  scra_h_posiw.w.h += 16; /* Line 761, Address: 0x1018fa4 */

  if (time_flag & 128) { /* Line 763, Address: 0x1018fb8 */

    flashin(); /* Line 765, Address: 0x1018fd0 */
  } /* Line 766, Address: 0x1018fd8 */
  else {



    fadein0(); /* Line 771, Address: 0x1018fe0 */
  }

} /* Line 774, Address: 0x1018fe8 */




void play_act_set() {
  actwk[0].actno = 1; /* Line 780, Address: 0x1019000 */
  if (plflag != 0) { /* Line 781, Address: 0x101900c */
    *(short*)&actwk[0].actfree[6] = 120; /* Line 782, Address: 0x101901c */
  }
} /* Line 784, Address: 0x1019028 */


void flow_act_set() { /* Line 787, Address: 0x1019030 */
  int i, time, fcnt;
  act_info* pAct;

  time = time_flag % 128; /* Line 791, Address: 0x1019044 */
  fcnt = flowercnt[time]; /* Line 792, Address: 0x1019054 */
  if (fcnt != 0) { /* Line 793, Address: 0x1019068 */
    --fcnt; /* Line 794, Address: 0x1019070 */
    pAct = &actwk[20]; /* Line 795, Address: 0x1019074 */
    i = 0; /* Line 796, Address: 0x101907c */
    do {
      pAct->actno = 31; /* Line 798, Address: 0x1019080 */

      pAct->xposi.w.h = flowerposi[i + (time * 64)].w.h; /* Line 800, Address: 0x1019088 */
      pAct->yposi.w.h = flowerposi[i + (time * 64)].w.l; /* Line 801, Address: 0x10190a8 */
      --fcnt; /* Line 802, Address: 0x10190c8 */
      ++pAct; /* Line 803, Address: 0x10190cc */
      ++i; /* Line 804, Address: 0x10190d0 */
    } while (fcnt > 0); /* Line 805, Address: 0x10190d4 */
  }

} /* Line 808, Address: 0x10190dc */



void scdset() {
  scdadr = zone1scd; /* Line 813, Address: 0x1019100 */

} /* Line 815, Address: 0x1019110 */


void syspatchg() {
  if (--sys_pattim & 128) { /* Line 819, Address: 0x1019120 */
    sys_pattim = 11; /* Line 820, Address: 0x1019148 */
    sys_patno = (sys_patno + -1) % 8; /* Line 821, Address: 0x1019154 */
  }
  if (--sys_pattim2 & 128) { /* Line 823, Address: 0x1019174 */
    sys_pattim2 = 7; /* Line 824, Address: 0x101919c */
    sys_patno2 = (sys_patno2 + 1) % 4; /* Line 825, Address: 0x10191a8 */
  }
  if (--sys_pattim3 & 128) { /* Line 827, Address: 0x10191c8 */
    sys_pattim3 = 7; /* Line 828, Address: 0x10191f0 */
    if (++sys_patno3 >= 6) sys_patno3 = 0; /* Line 829, Address: 0x10191fc */
  }
  if (sys_pattim4 != 0) { /* Line 831, Address: 0x101922c */
    sys_ringtimer += sys_pattim4; /* Line 832, Address: 0x101923c */


    sys_patno4 = (sys_ringtimer >> 9) % 4; /* Line 835, Address: 0x1019264 */
    --sys_pattim4; /* Line 836, Address: 0x1019288 */
  }

} /* Line 839, Address: 0x101929c */


void back_to_cnt() {
  if (actwk[0].actfree[0] == 0) { /* Line 843, Address: 0x10192b0 */
    if (backto_cnt != 0) { /* Line 844, Address: 0x10192c0 */
      ++backto_cnt; /* Line 845, Address: 0x10192d0 */
    }
  }

} /* Line 849, Address: 0x10192e4 */




void bye_cnt() {
  if (byecnt0.w != 0) { /* Line 855, Address: 0x10192f0 */
    ++byecnt0.w; /* Line 856, Address: 0x1019300 */
  }

  if (byecnt1.w != 0) { /* Line 859, Address: 0x1019314 */
    ++byecnt1.w; /* Line 860, Address: 0x1019324 */
  }


} /* Line 864, Address: 0x1019338 */




void sdfdout() { /* Line 869, Address: 0x1019340 */
  soundset(171); /* Line 870, Address: 0x1019348 */
  if ((pauseflag.b.h | 128) == 0) { /* Line 871, Address: 0x1019354 */


    pauseflag.b.h |= 128; /* Line 874, Address: 0x101936c */
    if ((time_flag % 128) == 0) { /* Line 875, Address: 0x1019380 */

      if (plpower_m != 0 || plpower_s != 0) { /* Line 877, Address: 0x1019398 */
        sub_sync(144); /* Line 878, Address: 0x10193b8 */
        return; /* Line 879, Address: 0x10193c4 */
      }
    }

    sub_sync(213); /* Line 883, Address: 0x10193cc */
  }
} /* Line 885, Address: 0x10193d8 */


void sdfdin() { /* Line 888, Address: 0x10193f0 */
  if ((pauseflag.b.h & 128) != 0) { /* Line 889, Address: 0x10193f8 */


    pauseflag.b.h %= 128; /* Line 892, Address: 0x1019410 */
    if ((time_flag % 128) == 0) { /* Line 893, Address: 0x1019424 */

      if (plpower_m != 0 || plpower_s != 0) { /* Line 895, Address: 0x101943c */
        sub_sync(145); /* Line 896, Address: 0x101945c */
        return; /* Line 897, Address: 0x1019468 */
      }
    }

    sub_sync(214); /* Line 901, Address: 0x1019470 */
  }
} /* Line 903, Address: 0x101947c */






void da_set() { /* Line 910, Address: 0x1019490 */
  unsigned short wD0;
  static unsigned char da_tbl[7][4] = {
    { 48, 15, 17, 16 },
    { 49, 18, 20, 19 },
    { 50, 21, 23, 22 },
    { 51, 24, 26, 25 },
    { 52, 27, 29, 28 },
    { 53, 30, 32, 31 },
    { 54, 33, 102, 34 }
  };

  wD0 = time_flag % 128; /* Line 922, Address: 0x101949c */
  if (ta_flag == 0) { /* Line 923, Address: 0x10194b4 */
    if (wD0 == 2) { /* Line 924, Address: 0x10194c4 */
      wD0 += generate_flag; /* Line 925, Address: 0x10194d4 */
    }
  }

  sub_sync(da_tbl[stageno.b.h][wD0]); /* Line 929, Address: 0x10194e8 */


} /* Line 932, Address: 0x1019528 */
