#include "..\EQU.H"
#include "GAME5.H"
#include "..\ACTION.H"
#include "..\ACTSET.H"
#include "..\FCOL.H"
#include "..\IO.H"
#include "..\LOADER2.H"
#include "..\SCORE.H"
#include "COL5A.H"
#include "SCR51A.H"

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










































































void DLL_meminit(char*** pBufTbl, void** pFuncTbl) { /* Line 125, Address: 0x1017e10 */


  SetGrid = *pFuncTbl++; /* Line 128, Address: 0x1017e20 */
  EAsprset = *pFuncTbl++; /* Line 129, Address: 0x1017e38 */
  ClrSpriteDebug = *pFuncTbl++; /* Line 130, Address: 0x1017e50 */
  WaveRequest = *pFuncTbl++; /* Line 131, Address: 0x1017e68 */
  CDPlay = *pFuncTbl++; /* Line 132, Address: 0x1017e80 */
  CDPause = *pFuncTbl++; /* Line 133, Address: 0x1017e98 */
  ChangeTileBmp = *pFuncTbl++; /* Line 134, Address: 0x1017eb0 */
  ++pFuncTbl; /* Line 135, Address: 0x1017ec8 */
  ++pFuncTbl; /* Line 136, Address: 0x1017ed4 */
  ++pFuncTbl; /* Line 137, Address: 0x1017ee0 */
  WaveAllStop = *pFuncTbl++; /* Line 138, Address: 0x1017eec */

  ++pFuncTbl; /* Line 140, Address: 0x1017f04 */
  ++pFuncTbl; /* Line 141, Address: 0x1017f10 */
  sMemSet = *pFuncTbl++; /* Line 142, Address: 0x1017f1c */
  sMemCpy = *pFuncTbl++; /* Line 143, Address: 0x1017f34 */
  ++pFuncTbl; /* Line 144, Address: 0x1017f4c */
  sRandom = *pFuncTbl++; /* Line 145, Address: 0x1017f58 */
  ++pFuncTbl; /* Line 146, Address: 0x1017f70 */
  ++pFuncTbl; /* Line 147, Address: 0x1017f7c */
  ++pFuncTbl; /* Line 148, Address: 0x1017f88 */
  sPrintf = *pFuncTbl++; /* Line 149, Address: 0x1017f94 */
  sOutputDebugString = *pFuncTbl++; /* Line 150, Address: 0x1017fac */
  sOpenFile = *pFuncTbl++; /* Line 151, Address: 0x1017fc4 */
  sReadFile = *pFuncTbl++; /* Line 152, Address: 0x1017fdc */
  sCloseFile = *pFuncTbl++; /* Line 153, Address: 0x1017ff4 */
  ++pFuncTbl; /* Line 154, Address: 0x101800c */





  pmapwk = (unsigned short*)**pBufTbl++; /* Line 160, Address: 0x1018018 */
  lpcolorwk = (PALETTEENTRY*)**pBufTbl++; /* Line 161, Address: 0x1018034 */
  lpcolorwk2 = (PALETTEENTRY*)**pBufTbl++; /* Line 162, Address: 0x1018050 */
  lpcolorwk3 = (PALETTEENTRY*)**pBufTbl++; /* Line 163, Address: 0x101806c */
  lpcolorwk4 = (PALETTEENTRY*)**pBufTbl++; /* Line 164, Address: 0x1018088 */
  lphscrollbuff = (int_union*)**pBufTbl++; /* Line 165, Address: 0x10180a4 */
  lpFadeFlag = (int*)*pBufTbl++; /* Line 166, Address: 0x10180c0 */
  lpKeepWork = (game_info*)*pBufTbl++; /* Line 167, Address: 0x10180d8 */
  ++pBufTbl; /* Line 168, Address: 0x10180f0 */
  lpghWnd = (unsigned int*)*pBufTbl++; /* Line 169, Address: 0x10180fc */

  plring = lpKeepWork->plring; /* Line 171, Address: 0x1018114 */
  plscore = lpKeepWork->plscore; /* Line 172, Address: 0x1018128 */
  stageno.w = lpKeepWork->stageno.w; /* Line 173, Address: 0x101813c */
  play_start = lpKeepWork->play_start; /* Line 174, Address: 0x1018150 */
  pl_suu = lpKeepWork->pl_suu; /* Line 175, Address: 0x1018164 */
  generate_flag = lpKeepWork->generate_flag; /* Line 176, Address: 0x1018178 */
  time_flag = lpKeepWork->time_flag; /* Line 177, Address: 0x101818c */
  plflag = lpKeepWork->plflag; /* Line 178, Address: 0x10181a0 */
  clrspflg_save = lpKeepWork->clrspflg_save; /* Line 179, Address: 0x10181b4 */
  ta_flag = lpKeepWork->ta_flag; /* Line 180, Address: 0x10181c8 */
  gf_flag = lpKeepWork->gf_flag; /* Line 181, Address: 0x10181dc */
  projector_flag = lpKeepWork->projector_flag; /* Line 182, Address: 0x10181f0 */
  extrascore = lpKeepWork->extrascore; /* Line 183, Address: 0x1018204 */
  emie3end = lpKeepWork->emie3end; /* Line 184, Address: 0x1018218 */

  flagworkcnt = lpKeepWork->flagworkcnt; /* Line 186, Address: 0x101822c */
  flagworkcnt2 = lpKeepWork->flagworkcnt2; /* Line 187, Address: 0x1018240 */
  sMemCpy(flagwork, lpKeepWork->flagwork, sizeof(flagwork)); /* Line 188, Address: 0x1018254 */

  lpKeepWork->pSprBmp = SprBmp; /* Line 190, Address: 0x101827c */


} /* Line 193, Address: 0x1018290 */



void DLL_memfree(void) {} /* Line 197, Address: 0x10182a0 */


int Get_vscroll(void) {
  return vscroll.l; /* Line 201, Address: 0x10182b0 */
} /* Line 202, Address: 0x10182b8 */

int Get_scra_h_posiw(void) {
  return scra_h_posiw.l; /* Line 205, Address: 0x10182c0 */
} /* Line 206, Address: 0x10182c8 */

int Get_scrb_h_posiw(void) {
  return scrb_h_posiw.l; /* Line 209, Address: 0x10182d0 */
} /* Line 210, Address: 0x10182d8 */


void SetDebugFlag(unsigned int NewVal) { /* Line 213, Address: 0x10182e0 */
  if (NewVal == 1) debugflag.w |= 256; /* Line 214, Address: 0x10182e8 */
  else debugflag.w &= -257; /* Line 215, Address: 0x1018314 */

} /* Line 217, Address: 0x101832c */




int game(void) { /* Line 222, Address: 0x1018340 */
  if (swdata1.b.l & 128) { /* Line 223, Address: 0x1018348 */
    if (pauseflag.b.h) { /* Line 224, Address: 0x1018360 */
      if (swdata2.w & 32896) { /* Line 225, Address: 0x1018370 */
        if (PauseIcon != 0) pauseflag.b.h = 0, PauseIcon = 0; /* Line 226, Address: 0x1018388 */
      } else pauseflag.b.h = 0; /* Line 227, Address: 0x10183a8 */
      CDPause(1); /* Line 228, Address: 0x10183b8 */
    } else { /* Line 229, Address: 0x10183cc */
      if (swdata2.w & 32896) pauseflag.b.h = 1, PauseIcon = 1; /* Line 230, Address: 0x10183d4 */
      else pauseflag.b.h = 1; /* Line 231, Address: 0x101840c */
      CDPause(0); /* Line 232, Address: 0x1018418 */
    }
  }












  if (pauseflag.b.h & 1) { /* Line 247, Address: 0x101842c */
    sdfdout(); /* Line 248, Address: 0x1018444 */
  }
  if ((swdata1.b.l & 112) == 112) { /* Line 250, Address: 0x101844c */

    pauseflag.b.h = 0; /* Line 252, Address: 0x1018468 */
    markerno = 0; /* Line 253, Address: 0x1018470 */
    demoflag.w = 0; /* Line 254, Address: 0x1018478 */
    gameflag.w = 1; /* Line 255, Address: 0x1018480 */
    lpKeepWork->ta_time = -1; /* Line 256, Address: 0x101848c */
    --pl_suu; /* Line 257, Address: 0x101849c */
    if ((char)pl_suu < 0) { /* Line 258, Address: 0x10184b0 */
      pl_suu = 0; /* Line 259, Address: 0x10184d0 */
    }
    sub_sync(14); /* Line 261, Address: 0x10184d8 */
    flagwkclr(); /* Line 262, Address: 0x10184e4 */
    plflag = 0; /* Line 263, Address: 0x10184ec */
  }

  if (pauseflag.b.h & 1) return 0; /* Line 266, Address: 0x10184f4 */


  if (gameflag.w != 1) { /* Line 269, Address: 0x1018518 */
    sdfdin(); /* Line 270, Address: 0x1018534 */
    ++gametimer.w; /* Line 271, Address: 0x101853c */
    actsetchk(); /* Line 272, Address: 0x1018550 */
    action(); /* Line 273, Address: 0x1018558 */
  }
  if (demo_cnt == 2048) { /* Line 275, Address: 0x1018560 */

    enkeino = 0; /* Line 277, Address: 0x101857c */
  }
  if (gameflag.w) { /* Line 279, Address: 0x1018584 */



    lpKeepWork->plring = plring; /* Line 283, Address: 0x1018594 */
    lpKeepWork->plscore = plscore; /* Line 284, Address: 0x10185a8 */
    lpKeepWork->stageno.w = stageno.w; /* Line 285, Address: 0x10185bc */
    lpKeepWork->play_start = play_start; /* Line 286, Address: 0x10185d0 */
    lpKeepWork->pl_suu = pl_suu; /* Line 287, Address: 0x10185e4 */
    lpKeepWork->generate_flag = generate_flag; /* Line 288, Address: 0x10185f8 */
    lpKeepWork->time_flag = time_flag; /* Line 289, Address: 0x101860c */
    lpKeepWork->clrspflg_save = clrspflg_save; /* Line 290, Address: 0x1018620 */
    lpKeepWork->gf_flag = gf_flag; /* Line 291, Address: 0x1018634 */
    lpKeepWork->projector_flag = projector_flag; /* Line 292, Address: 0x1018648 */
    lpKeepWork->special_flag = special_flag; /* Line 293, Address: 0x101865c */
    lpKeepWork->extrascore = extrascore; /* Line 294, Address: 0x1018670 */
    lpKeepWork->plflag = plflag; /* Line 295, Address: 0x1018684 */
    lpKeepWork->emie3end = emie3end; /* Line 296, Address: 0x1018698 */

    if (gameflag.b.h != 1) { /* Line 298, Address: 0x10186ac */
      flagwkclr(); /* Line 299, Address: 0x10186c8 */
    }
    lpKeepWork->flagworkcnt = flagworkcnt; /* Line 301, Address: 0x10186d0 */
    lpKeepWork->flagworkcnt2 = flagworkcnt2; /* Line 302, Address: 0x10186e4 */
    sMemCpy(lpKeepWork->flagwork , flagwork, sizeof(flagwork)); /* Line 303, Address: 0x10186f8 */

    if (gameflag.w == 2) { /* Line 305, Address: 0x1018720 */

      lpKeepWork->ta_time = (unsigned long int)(unsigned int)pltime.b.b3 * 60 + (unsigned long int)(unsigned int)pltime.b.b2 * 60 * 60 + (unsigned long int)(unsigned int)pltime.b.b4; /* Line 307, Address: 0x101873c */
    } /* Line 308, Address: 0x10187c4 */
    else if (gameflag.w == 1) { /* Line 309, Address: 0x10187cc */
      lpKeepWork->ta_time = -1; /* Line 310, Address: 0x10187e8 */
    }


    return gameflag.w; /* Line 314, Address: 0x10187f8 */
  }
  if (editmode.w) { /* Line 316, Address: 0x1018810 */
    scroll(); /* Line 317, Address: 0x1018820 */
  } /* Line 318, Address: 0x1018828 */
  else {
    if (actwk[0].r_no0 >= 6) { /* Line 320, Address: 0x1018830 */
      scralim_down = scra_v_posit.w.h; /* Line 321, Address: 0x1018848 */
      scralim_n_down = scra_v_posit.w.h; /* Line 322, Address: 0x1018858 */
    } /* Line 323, Address: 0x1018868 */
    else {

      scroll(); /* Line 326, Address: 0x1018870 */
    }
  }


  patset(); /* Line 331, Address: 0x1018878 */

  clchgctr(); /* Line 333, Address: 0x1018880 */


  syspatchg(); /* Line 336, Address: 0x1018888 */


  scra_h_posiw.l = scra_h_posit.l; /* Line 339, Address: 0x1018890 */
  scra_v_posiw.l = scra_v_posit.l; /* Line 340, Address: 0x10188a0 */
  scrb_h_posiw.l = scrb_h_posit.l; /* Line 341, Address: 0x10188b0 */
  scrb_v_posiw.l = scrb_v_posit.l; /* Line 342, Address: 0x10188c0 */
  scrc_h_posiw.l = scrc_h_posit.l; /* Line 343, Address: 0x10188d0 */
  scrc_v_posiw.l = scrc_v_posit.l; /* Line 344, Address: 0x10188e0 */
  scrz_h_posiw.l = scrz_h_posit.l; /* Line 345, Address: 0x10188f0 */
  scrz_v_posiw.l = scrz_v_posit.l; /* Line 346, Address: 0x1018900 */
  scrflagaw.w = scrflaga.w; /* Line 347, Address: 0x1018910 */
  scrflagbw.w = scrflagb.w; /* Line 348, Address: 0x1018920 */
  scrflagcw.w = scrflagc.w; /* Line 349, Address: 0x1018930 */
  scrflagzw.w = scrflagz.w; /* Line 350, Address: 0x1018940 */


  if (mapwrt_cnt & 1) { /* Line 353, Address: 0x1018950 */
    mapwrt_cnt &= 254; /* Line 354, Address: 0x1018968 */
    mapwrtb(); /* Line 355, Address: 0x101897c */
  } /* Line 356, Address: 0x1018984 */
  else enkeichg(); /* Line 357, Address: 0x101898c */

  scrollwrt(); /* Line 359, Address: 0x1018994 */
  scoreset(); /* Line 360, Address: 0x101899c */

  if (!pauseflag.b.h) { /* Line 362, Address: 0x10189a4 */
    bye_cnt(); /* Line 363, Address: 0x10189b4 */
    back_to_cnt(); /* Line 364, Address: 0x10189bc */
  }

  ++systemtimer.l; /* Line 367, Address: 0x10189c4 */
  return 0; /* Line 368, Address: 0x10189d8 */
} /* Line 369, Address: 0x10189dc */



void game_init(void) { /* Line 373, Address: 0x10189f0 */

  ReadScrolMap(); /* Line 375, Address: 0x10189f8 */
  ReadBlockMap(); /* Line 376, Address: 0x1018a00 */

  actset_rno.w = 0; /* Line 378, Address: 0x1018a08 */
  demoflag.w = 0; /* Line 379, Address: 0x1018a10 */
  if (clrspflg_save == 127 && ta_flag == 0) { /* Line 380, Address: 0x1018a18 */
    generate_flag = 1; /* Line 381, Address: 0x1018a44 */
  }


  init_flag = 0; /* Line 385, Address: 0x1018a50 */
  int_flg = 0; /* Line 386, Address: 0x1018a58 */
  main_play = 0; /* Line 387, Address: 0x1018a60 */
  pauseflag.w = 0; /* Line 388, Address: 0x1018a68 */

  if (!(play_start & 1)) { /* Line 390, Address: 0x1018a70 */
    play_start |= 1; /* Line 391, Address: 0x1018a88 */
    start_flag = 0; /* Line 392, Address: 0x1018a9c */
    markerno = 0; /* Line 393, Address: 0x1018aa4 */
    extrascore = 5000; /* Line 394, Address: 0x1018aac */
    flagwkclr(); /* Line 395, Address: 0x1018ab8 */
    plflag = 0; /* Line 396, Address: 0x1018ac0 */
    gf_flag = 0; /* Line 397, Address: 0x1018ac8 */
    plscore = 0; /* Line 398, Address: 0x1018ad0 */
    pl_suu = 3; /* Line 399, Address: 0x1018ad8 */
    if (ta_flag != 0) { /* Line 400, Address: 0x1018ae4 */
      pl_suu = 1; /* Line 401, Address: 0x1018af8 */
    }
  } /* Line 403, Address: 0x1018b04 */
  else {
    play_start |= 1; /* Line 405, Address: 0x1018b0c */
  }


  da_set(); /* Line 409, Address: 0x1018b20 */



  plsubchg_flag = 0; /* Line 413, Address: 0x1018b28 */
  sMemSet(flowercnt, 0, sizeof(flowercnt)); /* Line 414, Address: 0x1018b30 */
  sMemSet(pbuffer, 0, sizeof(pbuffer)); /* Line 415, Address: 0x1018b50 */
  sMemSet(flowerposi, 0, sizeof(flowerposi)); /* Line 416, Address: 0x1018b70 */
  sMemSet(actwk, 0, sizeof(actwk)); /* Line 417, Address: 0x1018b90 */
  sMemSet(flowwk, 0, sizeof(flowwk)); /* Line 418, Address: 0x1018bb0 */



  intcnt.w = 0; /* Line 422, Address: 0x1018bd0 */
  int_flg = 0; /* Line 423, Address: 0x1018bd8 */
  linkdata = 0; /* Line 424, Address: 0x1018be0 */
  cltbladr = 0; /* Line 425, Address: 0x1018be8 */
  ranum = 0; /* Line 426, Address: 0x1018bf0 */
  pauseflag.w = 0; /* Line 427, Address: 0x1018bf8 */
  cgwrtcnt = 0; /* Line 428, Address: 0x1018c00 */
  cgwrttim = 0; /* Line 429, Address: 0x1018c08 */
  dmastack = 0; /* Line 430, Address: 0x1018c10 */
  waterposi = 0; /* Line 431, Address: 0x1018c18 */
  waterposi_m = 0; /* Line 432, Address: 0x1018c20 */
  watermoveposi = 0; /* Line 433, Address: 0x1018c28 */
  waterspeed = 0; /* Line 434, Address: 0x1018c30 */
  water_flag = 0; /* Line 435, Address: 0x1018c38 */
  waterflag = 0; /* Line 436, Address: 0x1018c40 */
  waterflag2 = 0; /* Line 437, Address: 0x1018c48 */
  sMemSet(cgchgcnt, 0, sizeof(cgchgcnt)); /* Line 438, Address: 0x1018c50 */
  sMemSet(cgchgtim, 0, sizeof(cgchgtim)); /* Line 439, Address: 0x1018c70 */


  scra_h_posit.l = 0; /* Line 442, Address: 0x1018c90 */
  scra_v_posit.l = 0; /* Line 443, Address: 0x1018c98 */
  scrb_h_posit.l = 0; /* Line 444, Address: 0x1018ca0 */
  scrb_v_posit.l = 0; /* Line 445, Address: 0x1018ca8 */
  scrc_h_posit.l = 0; /* Line 446, Address: 0x1018cb0 */
  scrc_v_posit.l = 0; /* Line 447, Address: 0x1018cb8 */
  scrz_h_posit.l = 0; /* Line 448, Address: 0x1018cc0 */
  scrz_v_posit.l = 0; /* Line 449, Address: 0x1018cc8 */
  scralim_n_left = 0; /* Line 450, Address: 0x1018cd0 */
  scralim_n_right = 0; /* Line 451, Address: 0x1018cd8 */
  scralim_n_up = 0; /* Line 452, Address: 0x1018ce0 */
  scralim_n_down = 0; /* Line 453, Address: 0x1018ce8 */
  scralim_left = 0; /* Line 454, Address: 0x1018cf0 */
  scralim_right = 0; /* Line 455, Address: 0x1018cf8 */
  scralim_up = 0; /* Line 456, Address: 0x1018d00 */
  scralim_down = 0; /* Line 457, Address: 0x1018d08 */
  scrar_no = 0; /* Line 458, Address: 0x1018d10 */
  scra_h_keep = 0; /* Line 459, Address: 0x1018d18 */
  scra_v_keep = 0; /* Line 460, Address: 0x1018d20 */
  scra_hz = 0; /* Line 461, Address: 0x1018d28 */
  scra_vz = 0; /* Line 462, Address: 0x1018d30 */
  scra_vline = 0; /* Line 463, Address: 0x1018d38 */
  scrh_flag = 0; /* Line 464, Address: 0x1018d40 */
  scrv_flag = 0; /* Line 465, Address: 0x1018d48 */
  zone_flag.w = 0; /* Line 466, Address: 0x1018d50 */
  scroll_start.w = 0; /* Line 467, Address: 0x1018d58 */
  scr_die.w = 0; /* Line 468, Address: 0x1018d60 */
  scr_timer.w = 0; /* Line 469, Address: 0x1018d68 */
  scra_h_count = 0; /* Line 470, Address: 0x1018d70 */
  scra_v_count = 0; /* Line 471, Address: 0x1018d78 */
  scrb_h_count = 0; /* Line 472, Address: 0x1018d80 */
  scrb_v_count = 0; /* Line 473, Address: 0x1018d88 */
  scrc_h_count = 0; /* Line 474, Address: 0x1018d90 */
  scrc_v_count = 0; /* Line 475, Address: 0x1018d98 */
  scrz_h_count = 0; /* Line 476, Address: 0x1018da0 */
  scrz_v_count = 0; /* Line 477, Address: 0x1018da8 */
  scrflaga.w = 0; /* Line 478, Address: 0x1018db0 */
  scrflagb.w = 0; /* Line 479, Address: 0x1018db8 */
  scrflagc.w = 0; /* Line 480, Address: 0x1018dc0 */
  scrflagz.w = 0; /* Line 481, Address: 0x1018dc8 */
  limmoveflag = 0; /* Line 482, Address: 0x1018dd0 */
  playpatno1 = 0; /* Line 483, Address: 0x1018dd8 */
  kusya_flag = 0; /* Line 484, Address: 0x1018de0 */
  plmaxspdwk = 0; /* Line 485, Address: 0x1018de8 */
  pladdspdwk = 0; /* Line 486, Address: 0x1018df0 */
  plretspdwk = 0; /* Line 487, Address: 0x1018df8 */
  playpatno = 0; /* Line 488, Address: 0x1018e00 */
  playwrtflag = 0; /* Line 489, Address: 0x1018e08 */
  sMemSet(dirstk, 0, sizeof(dirstk)); /* Line 490, Address: 0x1018e10 */
  actset_rno.w = 0; /* Line 491, Address: 0x1018e30 */
  asetposi = 0; /* Line 492, Address: 0x1018e38 */
  asetadr = 0; /* Line 493, Address: 0x1018e40 */
  asetadr2 = 0; /* Line 494, Address: 0x1018e48 */
  asetadrz = 0; /* Line 495, Address: 0x1018e50 */
  asetadrz2 = 0; /* Line 496, Address: 0x1018e58 */
  byecnt0.w = 0; /* Line 497, Address: 0x1018e60 */
  byecnt1.w = 0; /* Line 498, Address: 0x1018e68 */
  time_item = 0; /* Line 499, Address: 0x1018e70 */
  backto_cnt = 0; /* Line 500, Address: 0x1018e78 */
  scr_cnt = 0; /* Line 501, Address: 0x1018e80 */
  demo_adr = 0; /* Line 502, Address: 0x1018e88 */
  demo_cnt = 0; /* Line 503, Address: 0x1018e90 */
  swbufcnt = 0; /* Line 504, Address: 0x1018e98 */
  scdadr = 0; /* Line 505, Address: 0x1018ea0 */
  scra_hline = 0; /* Line 506, Address: 0x1018ea8 */
  bossflag = 0; /* Line 507, Address: 0x1018eb0 */
  plposiwkadr.w = 0; /* Line 508, Address: 0x1018eb8 */
  bossstart = 0; /* Line 509, Address: 0x1018ec0 */
  loopmapno = 0; /* Line 510, Address: 0x1018ec8 */
  loopmapno2 = 0; /* Line 511, Address: 0x1018ed0 */
  ballmapno = 0; /* Line 512, Address: 0x1018ed8 */
  ballmapno2 = 0; /* Line 513, Address: 0x1018ee0 */
  sMemSet(clchgcnt, 0, sizeof(clchgcnt)); /* Line 514, Address: 0x1018ee8 */
  sMemSet(clchgtim, 0, sizeof(clchgtim)); /* Line 515, Address: 0x1018f08 */
  watercoliflag = 0; /* Line 516, Address: 0x1018f28 */
  waterstop = 0; /* Line 517, Address: 0x1018f30 */
  mizuflag = 0; /* Line 518, Address: 0x1018f38 */
  sekichyuflag = 0; /* Line 519, Address: 0x1018f40 */
  plautoflag = 0; /* Line 520, Address: 0x1018f48 */
  specflag = 0; /* Line 521, Address: 0x1018f50 */
  dai2rmvflag = 0; /* Line 522, Address: 0x1018f58 */
  emyscorecnt = 0; /* Line 523, Address: 0x1018f60 */
  timebonus = 0; /* Line 524, Address: 0x1018f68 */
  ringbonus = 0; /* Line 525, Address: 0x1018f70 */
  bonus_f = 0; /* Line 526, Address: 0x1018f78 */
  edplayflag = 0; /* Line 527, Address: 0x1018f80 */
  waterdirec.w = 0; /* Line 528, Address: 0x1018f88 */
  ms_wflg = 0; /* Line 529, Address: 0x1018f90 */
  sMemSet(switchflag, 0, sizeof(switchflag)); /* Line 530, Address: 0x1018f98 */


  demo_cnt = 0; /* Line 533, Address: 0x1018fb8 */


  tv_flag = 0; /* Line 536, Address: 0x1018fc0 */
  editno.w = 0; /* Line 537, Address: 0x1018fc8 */
  editmode.w = 0; /* Line 538, Address: 0x1018fd0 */
  edittimer = 0; /* Line 539, Address: 0x1018fd8 */
  systemtimer.l = 0; /* Line 540, Address: 0x1018fe0 */
  time_stop = 0; /* Line 541, Address: 0x1018fe8 */
  sys_pattim = 0; /* Line 542, Address: 0x1018ff0 */
  sys_patno = 0; /* Line 543, Address: 0x1018ff8 */
  sys_pattim2 = 0; /* Line 544, Address: 0x1019000 */
  sys_patno2 = 0; /* Line 545, Address: 0x1019008 */
  sys_pattim3 = 0; /* Line 546, Address: 0x1019010 */
  sys_patno3 = 0; /* Line 547, Address: 0x1019018 */
  sys_pattim4 = 0; /* Line 548, Address: 0x1019020 */
  sys_patno4 = 0; /* Line 549, Address: 0x1019028 */
  sys_ringtimer = 0; /* Line 550, Address: 0x1019030 */
  editstack = 0; /* Line 551, Address: 0x1019038 */
  editstack2 = 0; /* Line 552, Address: 0x1019040 */
  mapcheck = 0; /* Line 553, Address: 0x1019048 */
  scra_h_posiw.l = 0; /* Line 554, Address: 0x1019050 */
  scra_v_posiw.l = 0; /* Line 555, Address: 0x1019058 */
  scrb_h_posiw.l = 0; /* Line 556, Address: 0x1019060 */
  scrb_v_posiw.l = 0; /* Line 557, Address: 0x1019068 */
  scrc_h_posiw.l = 0; /* Line 558, Address: 0x1019070 */
  scrc_v_posiw.l = 0; /* Line 559, Address: 0x1019078 */
  scrz_h_posiw.l = 0; /* Line 560, Address: 0x1019080 */
  scrz_v_posiw.l = 0; /* Line 561, Address: 0x1019088 */
  scrflagaw.w = 0; /* Line 562, Address: 0x1019090 */
  scrflagbw.w = 0; /* Line 563, Address: 0x1019098 */
  scrflagcw.w = 0; /* Line 564, Address: 0x10190a0 */
  scrflagzw.w = 0; /* Line 565, Address: 0x10190a8 */
  blkno = 0; /* Line 566, Address: 0x10190b0 */
  col_y.w = 0; /* Line 567, Address: 0x10190b8 */
  col_x.w = 0; /* Line 568, Address: 0x10190c0 */
  edit_user = 0; /* Line 569, Address: 0x10190c8 */
  sysdirec = 0; /* Line 570, Address: 0x10190d0 */
  prio_flag = 0; /* Line 571, Address: 0x10190d8 */
  init_flag = 0; /* Line 572, Address: 0x10190e0 */
  boss_sound = 0; /* Line 573, Address: 0x10190e8 */
  shut_flag = 0; /* Line 574, Address: 0x10190f0 */
  st6clrchg = 0; /* Line 575, Address: 0x10190f8 */
  chibi_flag = 0; /* Line 576, Address: 0x1019100 */
  mapwrt_cnt = 0; /* Line 577, Address: 0x1019108 */
  sMemSet(linework, 0, sizeof(linework)); /* Line 578, Address: 0x1019110 */

  scrinit(); /* Line 580, Address: 0x1019130 */


  pl_air = 30; /* Line 583, Address: 0x1019138 */




  scr_set(); /* Line 588, Address: 0x1019144 */
  scroll(); /* Line 589, Address: 0x101914c */
  scrflaga.b.h |= 4; /* Line 590, Address: 0x1019154 */
  mapinit(); /* Line 591, Address: 0x1019168 */
  mapwrt(); /* Line 592, Address: 0x1019170 */

  scdcnv(); /* Line 594, Address: 0x1019178 */
  scdset(); /* Line 595, Address: 0x1019180 */




  play_act_set(); /* Line 600, Address: 0x1019188 */
  actwk[2].actno = 28; /* Line 601, Address: 0x1019190 */
  actwk[3].actno = 28; /* Line 602, Address: 0x101919c */
  actwk[3].userflag.b.h = 1; /* Line 603, Address: 0x10191a8 */
  actwk[5].actno = 28; /* Line 604, Address: 0x10191b4 */
  actwk[5].userflag.b.l = 1; /* Line 605, Address: 0x10191c0 */



  actwk[31].actno = 25; /* Line 609, Address: 0x10191cc */
  actwk[31].userflag.b.h = 10; /* Line 610, Address: 0x10191d8 */
  if (!(play_start & 2)) { /* Line 611, Address: 0x10191e4 */
    play_start |= 2; /* Line 612, Address: 0x10191fc */
    actwk[4].actno = 60; /* Line 613, Address: 0x1019210 */
    plautoflag = 1; /* Line 614, Address: 0x101921c */
    enecgflg = 0; /* Line 615, Address: 0x1019228 */
  }

  actwk[32].actno = 4; /* Line 618, Address: 0x1019230 */
  swdata.w = 0; /* Line 619, Address: 0x101923c */
  swdata1.w = 0; /* Line 620, Address: 0x1019244 */
  swdata2.w = 0; /* Line 621, Address: 0x101924c */
  byecnt0.w = 0; /* Line 622, Address: 0x1019254 */
  byecnt1.w = 0; /* Line 623, Address: 0x101925c */


  if (plflag == 0) { /* Line 626, Address: 0x1019264 */
    plring = 0; /* Line 627, Address: 0x1019278 */
    pltime.l = 0; /* Line 628, Address: 0x1019280 */
    plring_f2 = 0; /* Line 629, Address: 0x1019288 */
  }

  pltimeover_f = plpower_b = plpower_m = plpower_s = plpower_a = 0; /* Line 632, Address: 0x1019290 */
  editmode.w = gameflag.w = gametimer.w = 0; /* Line 633, Address: 0x10192c8 */
  plflag = 0; /* Line 634, Address: 0x10192f0 */
  plscore_f = plring_f = pltime_f = pl_suu_f = 1; /* Line 635, Address: 0x10192f8 */
  plring_f = 128; /* Line 636, Address: 0x1019328 */

  plscore_f = 128; /* Line 638, Address: 0x1019334 */

  swbufcnt = 0; /* Line 640, Address: 0x1019340 */
  startcolor = 32; /* Line 641, Address: 0x1019348 */
  colorcnt = 47; /* Line 642, Address: 0x1019354 */

  scrflaga.b.h = 0; /* Line 644, Address: 0x1019360 */
  enkeichg(); /* Line 645, Address: 0x1019368 */

  colorset2(3); /* Line 647, Address: 0x1019370 */
  colorset(3); /* Line 648, Address: 0x101937c */

  if (enkeino == 1) { /* Line 650, Address: 0x1019388 */
    colorset2(5); /* Line 651, Address: 0x10193a0 */
    colorset(5); /* Line 652, Address: 0x10193ac */
  }

  mapwrt_cnt = 0; /* Line 655, Address: 0x10193b8 */
  mapwrtb(); /* Line 656, Address: 0x10193c0 */
  tv_flag = 1; /* Line 657, Address: 0x10193c8 */


  gmmode.b.h &= 127; /* Line 660, Address: 0x10193d4 */
  init_flag = 1; /* Line 661, Address: 0x10193e8 */


  game(); /* Line 664, Address: 0x10193f4 */
  scra_h_posiw.w.h -= 16; /* Line 665, Address: 0x10193fc */
  mapwrt(); /* Line 666, Address: 0x1019410 */
  scra_h_posiw.w.h += 16; /* Line 667, Address: 0x1019418 */

  if (time_flag & 128) { /* Line 669, Address: 0x101942c */

    flashin(); /* Line 671, Address: 0x1019444 */
  } /* Line 672, Address: 0x101944c */
  else {



    fadein0(); /* Line 677, Address: 0x1019454 */
  }

} /* Line 680, Address: 0x101945c */




void play_act_set(void) {
  actwk[0].actno = 1; /* Line 686, Address: 0x1019470 */
  if (plflag) { /* Line 687, Address: 0x101947c */
    ((short*)&actwk[0])[26] = 120; /* Line 688, Address: 0x101948c */
  }
} /* Line 690, Address: 0x1019498 */


void flow_act_set(void) { /* Line 693, Address: 0x10194a0 */
  int i, time, fcnt;
  sprite_status* pAct;

  time = time_flag & 127; /* Line 697, Address: 0x10194b4 */
  fcnt = flowercnt[time]; /* Line 698, Address: 0x10194c4 */
  if (fcnt != 0) { /* Line 699, Address: 0x10194d8 */
    --fcnt; /* Line 700, Address: 0x10194e0 */
    pAct = &actwk[32]; /* Line 701, Address: 0x10194e4 */
    i = 0; /* Line 702, Address: 0x10194ec */
    do {
      pAct->actno = 31; /* Line 704, Address: 0x10194f0 */

      pAct->xposi.w.h = flowerposi[i + (time * 64)].w.h; /* Line 706, Address: 0x10194f8 */
      pAct->yposi.w.h = flowerposi[i + (time * 64)].w.l; /* Line 707, Address: 0x1019518 */
      --fcnt; /* Line 708, Address: 0x1019538 */
      ++pAct; /* Line 709, Address: 0x101953c */
      ++i; /* Line 710, Address: 0x1019540 */
    } while (fcnt > 0); /* Line 711, Address: 0x1019544 */
  }

} /* Line 714, Address: 0x101954c */


void scdset(void) {
  scdadr = zone1scd; /* Line 718, Address: 0x1019570 */

} /* Line 720, Address: 0x1019580 */






void syspatchg(void) {
  if (--sys_pattim2 & 128) { /* Line 728, Address: 0x1019590 */
    sys_pattim2 = 7; /* Line 729, Address: 0x10195b8 */
    sys_patno2 = (sys_patno2 + 1) & 3; /* Line 730, Address: 0x10195c4 */
  }




  if (sys_pattim4) { /* Line 736, Address: 0x10195e4 */
    sys_ringtimer += (unsigned short)sys_pattim4; /* Line 737, Address: 0x10195f4 */


    sys_patno4 = (sys_ringtimer >> 9) & 3; /* Line 740, Address: 0x101961c */
    --sys_pattim4; /* Line 741, Address: 0x1019640 */
  }

} /* Line 744, Address: 0x1019654 */


static void back_to_cnt(void) {
  if (!actwk[0].actfree[0]) { /* Line 748, Address: 0x1019660 */
    if (backto_cnt) { /* Line 749, Address: 0x1019670 */
      ++backto_cnt; /* Line 750, Address: 0x1019680 */
    }
  }

} /* Line 754, Address: 0x1019694 */




static void bye_cnt(void) {
  if (byecnt0.w) { /* Line 760, Address: 0x10196a0 */
    ++byecnt0.w; /* Line 761, Address: 0x10196b0 */
  }

  if (byecnt1.w) { /* Line 764, Address: 0x10196c4 */
    ++byecnt1.w; /* Line 765, Address: 0x10196d4 */
  }


} /* Line 769, Address: 0x10196e8 */




void sdfdout(void) { /* Line 774, Address: 0x10196f0 */
  soundset(171); /* Line 775, Address: 0x10196f8 */
  if (!(pauseflag.b.h | 128)) { /* Line 776, Address: 0x1019704 */


    pauseflag.b.h |= 128; /* Line 779, Address: 0x101971c */
    if (!(time_flag & 127)) { /* Line 780, Address: 0x1019730 */

      if (plpower_m || plpower_s) { /* Line 782, Address: 0x1019748 */
        sub_sync(144); /* Line 783, Address: 0x1019768 */
        return; /* Line 784, Address: 0x1019774 */
      }
    }

    sub_sync(213); /* Line 788, Address: 0x101977c */
  }
} /* Line 790, Address: 0x1019788 */


void sdfdin(void) { /* Line 793, Address: 0x10197a0 */
  if (pauseflag.b.h & 128) { /* Line 794, Address: 0x10197a8 */


    pauseflag.b.h &= 127; /* Line 797, Address: 0x10197c0 */
    if (!(time_flag & 127)) { /* Line 798, Address: 0x10197d4 */

      if (plpower_m || plpower_s) { /* Line 800, Address: 0x10197ec */
        sub_sync(145); /* Line 801, Address: 0x101980c */
        return; /* Line 802, Address: 0x1019818 */
      }
    }

    sub_sync(214); /* Line 806, Address: 0x1019820 */
  }
} /* Line 808, Address: 0x101982c */






void da_set(void) { /* Line 815, Address: 0x1019840 */
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

  wD0 = time_flag & 127; /* Line 827, Address: 0x101984c */
  if (!ta_flag) { /* Line 828, Address: 0x1019864 */
    if (wD0 == 2) { /* Line 829, Address: 0x1019874 */
      wD0 += generate_flag; /* Line 830, Address: 0x1019884 */
    }
  }

  sub_sync((unsigned short)da_tbl[stageno.b.h][wD0]); /* Line 834, Address: 0x1019898 */


} /* Line 837, Address: 0x10198d8 */
