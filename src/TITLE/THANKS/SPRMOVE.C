#include "..\..\TYPES.H"
#include "THANKS_TYPES.H"
#include "SPRMOVE.H"
#include "ACT.H"
#include "ETC_M.H"
#include "GAME.H"

static void sonicinit(sprite_status_thanks* pActwk);
static void s_runset(sprite_status_thanks* pActwk);
static void sonicrun(sprite_status_thanks* pActwk);
static short s_metalchk(sprite_status_thanks* pActwk);
static void s_turnset(sprite_status_thanks* pActwk);
static void sonicturn(sprite_status_thanks* pActwk);
static void s_standset(sprite_status_thanks* pActwk);
static void sonicstand(sprite_status_thanks* pActwk);
static void s_waitset(sprite_status_thanks* pActwk);
static void sonicwait(sprite_status_thanks* pActwk);
static void s_ballset(sprite_status_thanks* pActwk);
static void sonicball(sprite_status_thanks* pActwk);
static void sonicexit(sprite_status_thanks* pActwk);
static void sonicpit(sprite_status_thanks* pActwk);
static void sonicesc(sprite_status_thanks* pActwk);
static void emmy_exeset(sprite_status_thanks* pActwk, sprite_status_thanks* pSonic);
static void emmyinit(sprite_status_thanks* pActwk);
static void e_runinit(sprite_status_thanks* pActwk);
static void emmymove(sprite_status_thanks* pActwk);
static void e_kissset(sprite_status_thanks* pActwk);
static void emmykiss(sprite_status_thanks* pActwk);
static void e_jumpset(sprite_status_thanks* pActwk);
static void emmyjump(sprite_status_thanks* pActwk);
static void e_catchset(sprite_status_thanks* pActwk);
static void emmy_catch(sprite_status_thanks* pActwk);
static void e_turnset(sprite_status_thanks* pActwk);
static void emmyturn(sprite_status_thanks* pActwk);
static void e_standset(sprite_status_thanks* pActwk);
static void emmymoji(sprite_status_thanks* pActwk);
static void emmyexit(sprite_status_thanks* pActwk);
static void emmypose(sprite_status_thanks* pActwk);
static void emmyesc(sprite_status_thanks* pActwk);
static void metalsinit(sprite_status_thanks* pActwk);
static void m_flyset(sprite_status_thanks* pActwk);
static void metalsfly(sprite_status_thanks* pActwk);
static void m_brakeset(sprite_status_thanks* pActwk);
static void metalsbrake(sprite_status_thanks* pActwk);
static void m_stopset(sprite_status_thanks* pActwk);
static void metalsstop(sprite_status_thanks* pActwk);
static void m_standset(sprite_status_thanks* pActwk);
static void metalstand(sprite_status_thanks* pActwk);
static void m_startset(sprite_status_thanks* pActwk);
static void metalstartcttbl(sprite_status_thanks* pActwk);
static void m_eraset(sprite_status_thanks* pActwk);
static void metalsera(sprite_status_thanks* pActwk);
static void metalsexit(sprite_status_thanks* pActwk);
static void metalspit(sprite_status_thanks* pActwk);
static void metalsesc(sprite_status_thanks* pActwk);
static void heartinit(sprite_status_thanks* pActwk);
static void heartmove(sprite_status_thanks* pActwk);
static void pockyinit(sprite_status_thanks* pActwk);
static void peckyinit(sprite_status_thanks* pActwk);
static void rickyinit(sprite_status_thanks* pActwk);
static void sheepinit(sprite_status_thanks* pActwk);
static void animalmove(sprite_status_thanks* pActwk);
static void flickyinit(sprite_status_thanks* pActwk);
static void incoinit(sprite_status_thanks* pActwk);
static void hatoinit(sprite_status_thanks* pActwk);
static void birdmove(sprite_status_thanks* pActwk);
static short killchk(sprite_status_thanks* pActwk);
static void sinhmove(sprite_status_thanks* pActwk);
static void sinvmove(sprite_status_thanks* pActwk);
static void hbt_move(sprite_status_thanks* pActwk);
static short chk_sonicposi(sprite_status_thanks* pActwk, sprite_status_thanks* pA6, short* d5, short* d6);
static short myposichk(sprite_status_thanks* pActwk);
static short centerchk(sprite_status_thanks* pActwk);
static short dsplaychk(sprite_status_thanks* pActwk);
static void waitmode(sprite_status_thanks* pActwk);
static void escape_chk(sprite_status_thanks* pActwk);
static void pit_in(sprite_status_thanks* pActwk);
static void m_sndchk(sprite_status_thanks* pActwk);

extern unsigned char animal_flg;
extern sprite_patterns_title s_run_map;
extern sprite_status_thanks actwk[66];
extern sprite_patterns_title s_stop_map;
extern sprite_patterns_title s_stand1_map;
extern sprite_patterns_title s_stand2_map;
extern sprite_patterns_title s_wait_map;
extern sprite_patterns_title s_ball_map;
extern short actset_tm[8];
extern sprite_patterns_title erun_map;
extern short heart_tm;
extern sprite_patterns_title ekiss_map;
extern unsigned char poseno;
extern sprite_patterns_title ejump_map;
extern sprite_patterns_title ecatch_map;
extern sprite_patterns_title estand2_map;
extern sprite_patterns_title estand_map;
extern sprite_patterns_title m_fly1_map;
extern sprite_patterns_title m_brake_map;
extern sprite_patterns_title m_stop_map;
extern sprite_patterns_title m_stand_map;
extern sprite_patterns_title m_furi_map;
extern sprite_patterns_title m_kamae_map;
extern sprite_patterns_title m_era_map;
extern sprite_patterns_title m_era2_map;
extern sprite_patterns_title eheart_map;
extern sprite_patterns_title pocky_map;
extern sprite_patterns_title pecky_map;
extern sprite_patterns_title ricky_map;
extern sprite_patterns_title sheep_map;
extern sprite_patterns_title flick_map;
extern sprite_patterns_title inco_map;
extern sprite_patterns_title hato_map;















































void sonic_ctrl(sprite_status_thanks* pActwk) { /* Line 160, Address: 0x1003120 */
  void(*acttbl[14])(sprite_status_thanks*) = /* Line 161, Address: 0x100312c */
  {
    &sonicinit,
    &s_runset,
    &sonicrun,
    &s_turnset,
    &sonicturn,
    &s_standset,
    &sonicstand,
    &s_waitset,
    &sonicwait,
    &s_ballset,
    &sonicball,
    &sonicexit,
    &sonicpit,
    &sonicesc
  };

  if (animal_flg) /* Line 179, Address: 0x1003160 */
  {
    pActwk->SPR_FLG |= 4; /* Line 181, Address: 0x1003170 */
  }
  acttbl[pActwk->EXE_NO](pActwk); /* Line 183, Address: 0x1003180 */
  pActwk->XPOSI.w.h &= 511; /* Line 184, Address: 0x10031a4 */
} /* Line 185, Address: 0x10031b4 */




static void sonicinit(sprite_status_thanks* pActwk) { /* Line 190, Address: 0x10031d0 */
  int_union ld0;

  ld0.l = random(); /* Line 193, Address: 0x10031dc */
  ld0.w.l &= 1; /* Line 194, Address: 0x10031e8 */
  ld0.w.l = 1; /* Line 195, Address: 0x10031f4 */
  if (ld0.w.l) /* Line 196, Address: 0x10031fc */
  {
    pActwk->XPOSI.w.h = 328; /* Line 198, Address: 0x1003208 */
    pActwk->X_SPEED.l = -196608; /* Line 199, Address: 0x1003214 */
    pActwk->SPR_FLG |= 128; /* Line 200, Address: 0x1003220 */
  } /* Line 201, Address: 0x1003230 */
  else
  {
    pActwk->XPOSI.w.h = 496; /* Line 204, Address: 0x1003238 */
    pActwk->X_SPEED.l = 196608; /* Line 205, Address: 0x1003244 */
    pActwk->SPR_FLG &= 127; /* Line 206, Address: 0x1003250 */
  }
  pActwk->YPOSI.w.h = 140; /* Line 208, Address: 0x1003260 */
  pActwk->Y_SPEED.l = 0; /* Line 209, Address: 0x100326c */

  pActwk->X_OFFSET = 0; /* Line 211, Address: 0x1003274 */
  pActwk->Y_OFFSET = 0; /* Line 212, Address: 0x100327c */
  pActwk->X_ACCEL.l = 0; /* Line 213, Address: 0x1003284 */
  pActwk->Y_ACCEL.l = 0; /* Line 214, Address: 0x100328c */

  pActwk->CGBASE = 25127; /* Line 216, Address: 0x1003294 */
  pActwk->free[0] = 1; /* Line 217, Address: 0x10032a0 */
  pActwk->PAT_ADR = &s_run_map; /* Line 218, Address: 0x10032ac */
  pActwk->SPR_TIMER = s_run_map.aPatDat[0].timer; /* Line 219, Address: 0x10032bc */
  pActwk->PAT_NO = 0; /* Line 220, Address: 0x10032cc */

  ld0.l = random(); /* Line 222, Address: 0x10032d4 */
  ld0.l &= 32767; /* Line 223, Address: 0x10032e0 */
  pActwk->TM_CNT = ld0.w.l % 128; /* Line 224, Address: 0x10032ec */
  pActwk->TM_CNT += 128; /* Line 225, Address: 0x1003324 */
  pActwk->EXE_NO = 2; /* Line 226, Address: 0x1003334 */
} /* Line 227, Address: 0x1003340 */




static void s_runset(sprite_status_thanks* pActwk) { /* Line 232, Address: 0x1003350 */
  sprite_status_thanks* pMetal;
  int_union ld0;

  pActwk->XPOSI.l &= 33554431; /* Line 236, Address: 0x1003360 */
  pActwk->X_SPEED.l = 196608; /* Line 237, Address: 0x1003374 */
  if (pActwk->SPR_FLG & 128) /* Line 238, Address: 0x1003380 */
  {
    pActwk->X_SPEED.l *= -1; /* Line 240, Address: 0x1003398 */
  }
  pActwk->Y_SPEED.l = 0; /* Line 242, Address: 0x10033a8 */

  pActwk->X_OFFSET = 0; /* Line 244, Address: 0x10033b0 */
  pActwk->Y_OFFSET = 0; /* Line 245, Address: 0x10033b8 */
  pActwk->X_ACCEL.l = 0; /* Line 246, Address: 0x10033c0 */
  pActwk->Y_ACCEL.l = 0; /* Line 247, Address: 0x10033c8 */

  pActwk->PAT_ADR = &s_run_map; /* Line 249, Address: 0x10033d0 */
  pActwk->SPR_TIMER = s_run_map.aPatDat[0].timer; /* Line 250, Address: 0x10033e0 */
  pActwk->PAT_NO = 0; /* Line 251, Address: 0x10033f0 */

  ld0.l = random(); /* Line 253, Address: 0x10033f8 */
  ld0.l &= 32767; /* Line 254, Address: 0x1003404 */
  pActwk->TM_CNT = ld0.w.l % 256; /* Line 255, Address: 0x1003410 */
  pActwk->TM_CNT += 64; /* Line 256, Address: 0x1003448 */

  pMetal = &actwk[2]; /* Line 258, Address: 0x1003458 */
  pMetal->ACT_NO = 3; /* Line 259, Address: 0x1003460 */

  pActwk->EXE_NO = 2; /* Line 261, Address: 0x1003468 */
} /* Line 262, Address: 0x1003474 */




static void sonicrun(sprite_status_thanks* pActwk) { /* Line 267, Address: 0x1003490 */
  int_union ld0;

  pActwk->XPOSI.l += pActwk->X_SPEED.l; /* Line 270, Address: 0x100349c */
  pActwk->YPOSI.l += pActwk->Y_SPEED.l; /* Line 271, Address: 0x10034b4 */

  if (pActwk->SPR_FLG & 4) /* Line 273, Address: 0x10034cc */
  {
    pActwk->EXE_NO = 11; /* Line 275, Address: 0x10034e4 */
    return; /* Line 276, Address: 0x10034f0 */
  }
  if (pActwk->XPOSI.w.h >= 376) /* Line 278, Address: 0x10034f8 */
  {
    if (pActwk->XPOSI.w.h <= 392) /* Line 280, Address: 0x1003514 */
    {
      ((short*)pActwk)[31] = 128; /* Line 282, Address: 0x1003530 */
      pActwk->EXE_NO = 12; /* Line 283, Address: 0x100353c */
      return; /* Line 284, Address: 0x1003548 */
    }
  }

  ld0.l = random(); /* Line 288, Address: 0x1003550 */
  ld0.l &= 32767; /* Line 289, Address: 0x100355c */
  ld0.w.l = (int)ld0.w.l % 1536; /* Line 290, Address: 0x1003568 */









  ld0.l = random(); /* Line 300, Address: 0x100358c */
  ld0.l &= 32767; /* Line 301, Address: 0x1003598 */
  ld0.w.l = (int)ld0.w.l % 512; /* Line 302, Address: 0x10035a4 */
  if (ld0.w.l == 0) /* Line 303, Address: 0x10035d8 */
  {
    pActwk->EXE_NO = 9; /* Line 305, Address: 0x10035ec */
    return; /* Line 306, Address: 0x10035f8 */
  }

  if (s_metalchk(pActwk)) /* Line 309, Address: 0x1003600 */
  {
    pActwk->EXE_NO = 3; /* Line 311, Address: 0x1003614 */
  }
  --pActwk->TM_CNT; /* Line 313, Address: 0x1003620 */
  if (pActwk->TM_CNT <= 0) /* Line 314, Address: 0x1003630 */
  {
    if (centerchk(pActwk)) /* Line 316, Address: 0x1003648 */
    {
      pActwk->EXE_NO = 3; /* Line 318, Address: 0x100365c */
    }
  }
} /* Line 321, Address: 0x1003668 */





static short s_metalchk(sprite_status_thanks* pActwk) { /* Line 327, Address: 0x1003680 */
  sprite_status_thanks* pMetal;
  short d5;

  pMetal = &actwk[2]; /* Line 331, Address: 0x1003690 */
  if (pMetal->EXE_NO < 2) return 0; /* Line 332, Address: 0x1003698 */
  if (pMetal->EXE_NO > 4) return 0; /* Line 333, Address: 0x10036b8 */

  pActwk->XPOSI.w.h &= 511; /* Line 335, Address: 0x10036d8 */
  pMetal->XPOSI.w.h &= 511; /* Line 336, Address: 0x10036e8 */
  if (pActwk->X_SPEED.l < 0) /* Line 337, Address: 0x10036f4 */
  {
    if (pMetal->X_SPEED.l < 0) return 0; /* Line 339, Address: 0x1003704 */
  }
  else
  {
    if (pMetal->X_SPEED.l >= 0) return 0; /* Line 343, Address: 0x100371c */
  }
  d5 = pMetal->XPOSI.w.h; /* Line 345, Address: 0x1003734 */
  d5 -= pActwk->XPOSI.w.h; /* Line 346, Address: 0x1003740 */
  if (d5 < 0) /* Line 347, Address: 0x1003754 */
  {
    d5 *= -1; /* Line 349, Address: 0x1003764 */
  }
  if (d5 > 8) return 0; /* Line 351, Address: 0x1003770 */
  return -1; /* Line 352, Address: 0x1003790 */
} /* Line 353, Address: 0x1003794 */




static void s_turnset(sprite_status_thanks* pActwk) { /* Line 358, Address: 0x10037b0 */
  pActwk->XPOSI.l &= 33554431; /* Line 359, Address: 0x10037bc */
  if (pActwk->X_SPEED.l < 0) /* Line 360, Address: 0x10037d0 */
  {
    pActwk->X_OFFSET = 10240; /* Line 362, Address: 0x10037e0 */
    pActwk->SPR_FLG &= 127; /* Line 363, Address: 0x10037ec */
  } /* Line 364, Address: 0x10037fc */
  else
  {
    pActwk->X_OFFSET = -10240; /* Line 367, Address: 0x1003804 */
    pActwk->SPR_FLG |= 128; /* Line 368, Address: 0x1003810 */
  }
  pActwk->PAT_ADR = &s_stop_map; /* Line 370, Address: 0x1003820 */
  pActwk->SPR_TIMER = s_stop_map.aPatDat[0].timer; /* Line 371, Address: 0x1003830 */
  pActwk->PAT_NO = 0; /* Line 372, Address: 0x1003840 */

  if (dsplaychk(pActwk) == 0) /* Line 374, Address: 0x1003848 */
  {
    soundset(144); /* Line 376, Address: 0x1003864 */
  }
  pActwk->EXE_NO = 4; /* Line 378, Address: 0x1003870 */
} /* Line 379, Address: 0x100387c */




static void sonicturn(sprite_status_thanks* pActwk) { /* Line 384, Address: 0x1003890 */
  sprite_status_thanks* pMetal;
  short d5, d6;

  hbt_move(pActwk); /* Line 388, Address: 0x10038a0 */
  if (pActwk->PAT_NO < 5) return; /* Line 389, Address: 0x10038ac */
  pMetal = &actwk[2]; /* Line 390, Address: 0x10038c8 */
  if (pMetal->EXE_NO == 2) /* Line 391, Address: 0x10038d0 */
  {
    pActwk->EXE_NO = 1; /* Line 393, Address: 0x10038e4 */
    return; /* Line 394, Address: 0x10038f0 */
  }
  if (myposichk(pActwk)) /* Line 396, Address: 0x10038f8 */
  {
    pActwk->EXE_NO = 9; /* Line 398, Address: 0x100390c */
  } /* Line 399, Address: 0x1003918 */
  else
  {
    chk_sonicposi(pActwk, pMetal, &d5, &d6); /* Line 402, Address: 0x1003920 */
    if (d5 <= 24) /* Line 403, Address: 0x1003938 */
    {
      pActwk->EXE_NO = 9; /* Line 405, Address: 0x1003950 */
    } /* Line 406, Address: 0x100395c */
    else
    {
      pActwk->EXE_NO = 5; /* Line 409, Address: 0x1003964 */
    }
  }
} /* Line 412, Address: 0x1003970 */




static void s_standset(sprite_status_thanks* pActwk) { /* Line 417, Address: 0x1003990 */
  sprite_status_thanks* pEmmy;

  pActwk->X_SPEED.l = 0; /* Line 420, Address: 0x100399c */

  pActwk->PAT_ADR = &s_stand1_map; /* Line 422, Address: 0x10039a4 */
  pActwk->SPR_TIMER = s_stand1_map.aPatDat[0].timer; /* Line 423, Address: 0x10039b4 */
  pActwk->PAT_NO = 0; /* Line 424, Address: 0x10039c4 */

  pActwk->TM_CNT = 127; /* Line 426, Address: 0x10039cc */
  pActwk->free[3] = 0; /* Line 427, Address: 0x10039d8 */

  pEmmy = &actwk[1]; /* Line 429, Address: 0x10039e0 */
  pEmmy->ACT_NO = 2; /* Line 430, Address: 0x10039e8 */

  pActwk->EXE_NO = 6; /* Line 432, Address: 0x10039f0 */
} /* Line 433, Address: 0x10039fc */




static void sonicstand(sprite_status_thanks* pActwk) { /* Line 438, Address: 0x1003a10 */
  sprite_status_thanks* pMetal;
  sprite_status_thanks* pEmmy;
  short d5, d6;

  pMetal = &actwk[2]; /* Line 443, Address: 0x1003a24 */
  chk_sonicposi(pActwk, pMetal, &d5, &d6); /* Line 444, Address: 0x1003a2c */
  --pActwk->TM_CNT; /* Line 445, Address: 0x1003a44 */
  if (pActwk->TM_CNT >= 0) return; /* Line 446, Address: 0x1003a54 */
  if (pActwk->free[3]) /* Line 447, Address: 0x1003a6c */
  {
    pEmmy = &actwk[1]; /* Line 449, Address: 0x1003a7c */
    pEmmy->SPR_FLG &= 251; /* Line 450, Address: 0x1003a84 */
    pActwk->EXE_NO = 7; /* Line 451, Address: 0x1003a90 */
  }
  pActwk->PAT_ADR = &s_stand2_map; /* Line 453, Address: 0x1003a9c */
  pActwk->SPR_TIMER = s_stand2_map.aPatDat[0].timer; /* Line 454, Address: 0x1003aac */
  pActwk->TM_CNT = 96; /* Line 455, Address: 0x1003abc */
  pActwk->free[3] = 1; /* Line 456, Address: 0x1003ac8 */
} /* Line 457, Address: 0x1003ad4 */




static void s_waitset(sprite_status_thanks* pActwk) { /* Line 462, Address: 0x1003af0 */
  int_union ld0;

  pActwk->XPOSI.l &= 33554431; /* Line 465, Address: 0x1003afc */
  pActwk->free[3] = 0; /* Line 466, Address: 0x1003b10 */
  pActwk->PAT_ADR = &s_wait_map; /* Line 467, Address: 0x1003b18 */
  pActwk->SPR_TIMER = s_wait_map.aPatDat[0].timer; /* Line 468, Address: 0x1003b28 */
  pActwk->PAT_NO = 0; /* Line 469, Address: 0x1003b38 */

  ld0.l = random(); /* Line 471, Address: 0x1003b40 */
  ld0.l &= 32767; /* Line 472, Address: 0x1003b4c */
  pActwk->TM_CNT = ld0.w.l % 127; /* Line 473, Address: 0x1003b58 */
  pActwk->TM_CNT += 127; /* Line 474, Address: 0x1003b80 */

  pActwk->EXE_NO = 8; /* Line 476, Address: 0x1003b90 */
} /* Line 477, Address: 0x1003b9c */




static void sonicwait(sprite_status_thanks* pActwk) { /* Line 482, Address: 0x1003bb0 */
  sprite_status_thanks* pEmmy;
  sprite_status_thanks* pMetal;
  short d5, d6;

  pEmmy = &actwk[1]; /* Line 487, Address: 0x1003bc4 */
  pMetal = &actwk[2]; /* Line 488, Address: 0x1003bcc */
  pMetal->XPOSI.w.h &= 511; /* Line 489, Address: 0x1003bd4 */
  if (chk_sonicposi(pActwk, pMetal, &d5, &d6)) pActwk->SPR_FLG |= 128; /* Line 490, Address: 0x1003be0 */
  else pActwk->SPR_FLG &= 127; /* Line 491, Address: 0x1003c18 */
  pMetal->SPR_FLG &= 251; /* Line 492, Address: 0x1003c28 */
  if (d5 > 8) /* Line 493, Address: 0x1003c34 */
  {
    --pActwk->TM_CNT; /* Line 495, Address: 0x1003c4c */
    if (pActwk->TM_CNT <= 0) /* Line 496, Address: 0x1003c5c */
    {
      pActwk->EXE_NO = 9; /* Line 498, Address: 0x1003c74 */
    }
  } /* Line 500, Address: 0x1003c80 */
  else
  {
    pActwk->EXE_NO = 1; /* Line 503, Address: 0x1003c88 */
  }
} /* Line 505, Address: 0x1003c94 */




static void s_ballset(sprite_status_thanks* pActwk) { /* Line 510, Address: 0x1003cb0 */
  pActwk->XPOSI.l &= 33554431; /* Line 511, Address: 0x1003cbc */
  pActwk->X_SPEED.l = 131072; /* Line 512, Address: 0x1003cd0 */
  if (pActwk->SPR_FLG & 128) /* Line 513, Address: 0x1003cdc */
  {
    pActwk->X_SPEED.l *= -1; /* Line 515, Address: 0x1003cf4 */
  }
  pActwk->Y_SPEED.l = -393216; /* Line 517, Address: 0x1003d04 */

  pActwk->X_OFFSET = 0; /* Line 519, Address: 0x1003d10 */
  pActwk->X_ACCEL.l = 0; /* Line 520, Address: 0x1003d18 */
  pActwk->Y_OFFSET = 16384; /* Line 521, Address: 0x1003d20 */
  pActwk->Y_ACCEL.l = 0; /* Line 522, Address: 0x1003d2c */

  pActwk->PAT_ADR = &s_ball_map; /* Line 524, Address: 0x1003d34 */
  pActwk->SPR_TIMER = s_ball_map.aPatDat[0].timer; /* Line 525, Address: 0x1003d44 */
  pActwk->PAT_NO = 0; /* Line 526, Address: 0x1003d54 */

  if (dsplaychk(pActwk) == 0) /* Line 528, Address: 0x1003d5c */
  {
    soundset(146); /* Line 530, Address: 0x1003d78 */
  }
  pActwk->EXE_NO = 10; /* Line 532, Address: 0x1003d84 */
} /* Line 533, Address: 0x1003d90 */




static void sonicball(sprite_status_thanks* pActwk) { /* Line 538, Address: 0x1003da0 */
  hbt_move(pActwk); /* Line 539, Address: 0x1003dac */
  if (pActwk->YPOSI.w.h >= 140) /* Line 540, Address: 0x1003db8 */
  {
    pActwk->Y_ACCEL.l = 0; /* Line 542, Address: 0x1003dd4 */
    pActwk->EXE_NO = 1; /* Line 543, Address: 0x1003ddc */
  }
} /* Line 545, Address: 0x1003de8 */




static void sonicexit(sprite_status_thanks* pActwk) { /* Line 550, Address: 0x1003e00 */
  sprite_status_thanks* pEmmy;
  sprite_status_thanks* pMetal;

  waitmode(pActwk); /* Line 554, Address: 0x1003e14 */
  if (animal_flg == 0) return; /* Line 555, Address: 0x1003e20 */
  pEmmy = &actwk[1]; /* Line 556, Address: 0x1003e34 */
  pMetal = &actwk[2]; /* Line 557, Address: 0x1003e3c */

  if (pActwk->X_SPEED.l != 0) return; /* Line 559, Address: 0x1003e44 */

  if (pEmmy->EXE_NO) /* Line 561, Address: 0x1003e54 */
  {
    if (pEmmy->EXE_NO != 13) return; /* Line 563, Address: 0x1003e60 */
    if (pEmmy->X_SPEED.l != 0) return; /* Line 564, Address: 0x1003e74 */
  }
  if (pMetal->EXE_NO) /* Line 566, Address: 0x1003e80 */
  {
    if (pMetal->EXE_NO != 13) return; /* Line 568, Address: 0x1003e8c */
    if (pMetal->X_SPEED.l != 0) return; /* Line 569, Address: 0x1003ea0 */
  }
  pActwk->SPR_FLG &= 127; /* Line 571, Address: 0x1003eac */

  pActwk->PAT_ADR = &s_run_map; /* Line 573, Address: 0x1003ebc */
  pActwk->SPR_TIMER = s_run_map.aPatDat[0].timer; /* Line 574, Address: 0x1003ecc */
  pActwk->PAT_NO = 0; /* Line 575, Address: 0x1003edc */

  pActwk->free[1] = 0; /* Line 577, Address: 0x1003ee4 */
  pActwk->TM_CNT = 96; /* Line 578, Address: 0x1003eec */

  pActwk->EXE_NO = 13; /* Line 580, Address: 0x1003ef8 */
} /* Line 581, Address: 0x1003f04 */




static void sonicpit(sprite_status_thanks* pActwk) { /* Line 586, Address: 0x1003f20 */
  pit_in(pActwk); /* Line 587, Address: 0x1003f2c */
} /* Line 588, Address: 0x1003f38 */




static void sonicesc(sprite_status_thanks* pActwk) { /* Line 593, Address: 0x1003f50 */
  sprite_status_thanks* pEmmy;
  sprite_status_thanks* pMetal;

  pEmmy = &actwk[1]; /* Line 597, Address: 0x1003f64 */
  pMetal = &actwk[2]; /* Line 598, Address: 0x1003f6c */
  if (pActwk->free[1] == 0) /* Line 599, Address: 0x1003f74 */
  {
    --pActwk->TM_CNT; /* Line 601, Address: 0x1003f88 */
    if (pActwk->TM_CNT > 0) return; /* Line 602, Address: 0x1003f98 */
    pActwk->XPOSI.w.h = 448; /* Line 603, Address: 0x1003fb0 */

    pActwk->X_SPEED.l = 196608; /* Line 605, Address: 0x1003fbc */
    pActwk->Y_SPEED.l = 0; /* Line 606, Address: 0x1003fc8 */


    animal_flg = 2; /* Line 609, Address: 0x1003fd0 */
    actset_tm[0] = 1800; /* Line 610, Address: 0x1003fdc */
    actset_tm[1] = 0; /* Line 611, Address: 0x1003fe8 */
    actset_tm[2] = 0; /* Line 612, Address: 0x1003ff0 */
    actset_tm[3] = 0; /* Line 613, Address: 0x1003ff8 */
    actset_tm[4] = 0; /* Line 614, Address: 0x1004000 */
    actset_tm[5] = 0; /* Line 615, Address: 0x1004008 */
    actset_tm[6] = 0; /* Line 616, Address: 0x1004010 */
    actset_tm[7] = 1800; /* Line 617, Address: 0x1004018 */

    pActwk->SPR_FLG &= 251; /* Line 619, Address: 0x1004024 */
    pEmmy->SPR_FLG &= 251; /* Line 620, Address: 0x1004034 */
    pMetal->SPR_FLG &= 251; /* Line 621, Address: 0x1004040 */

    pActwk->free[1] = 1; /* Line 623, Address: 0x100404c */
  } /* Line 624, Address: 0x1004058 */
  else
  {
    escape_chk(pActwk); /* Line 627, Address: 0x1004060 */
  }
} /* Line 629, Address: 0x100406c */




void emie_ctrl(sprite_status_thanks* pActwk) { /* Line 634, Address: 0x1004090 */
  sprite_status_thanks* pSonic;
  void(*acttbl[16])(sprite_status_thanks*) = /* Line 636, Address: 0x10040a0 */
  {
    &emmyinit,
    &e_runinit,
    &emmymove,
    &e_kissset,
    &emmykiss,
    &e_jumpset,
    &emmyjump,
    &e_catchset,
    &emmy_catch,
    &e_turnset,
    &emmyturn,
    &e_standset,
    &emmymoji,
    &emmyexit,
    &emmypose,
    &emmyesc
  };

  pSonic = &actwk[0]; /* Line 656, Address: 0x10040d4 */
  if (animal_flg) /* Line 657, Address: 0x10040dc */
  {
    pActwk->SPR_FLG |= 4; /* Line 659, Address: 0x10040ec */
  }
  emmy_exeset(pActwk, pSonic); /* Line 661, Address: 0x10040fc */
  acttbl[pActwk->EXE_NO](pActwk); /* Line 662, Address: 0x100410c */
  pActwk->XPOSI.w.h &= 511; /* Line 663, Address: 0x1004130 */
} /* Line 664, Address: 0x1004140 */




static void emmy_exeset(sprite_status_thanks* pActwk, sprite_status_thanks* pSonic) { /* Line 669, Address: 0x1004160 */
  int_union ld0;
  short d5, d6;

  if (pActwk->EXE_NO != 2) return; /* Line 673, Address: 0x1004170 */

  if (pSonic->ACT_NO == 0) /* Line 675, Address: 0x1004188 */
  {
    pActwk->EXE_NO = 15; /* Line 677, Address: 0x100419c */
    return; /* Line 678, Address: 0x10041a8 */
  }
  chk_sonicposi(pActwk, pSonic, &d5, &d6); /* Line 680, Address: 0x10041b0 */
  if (d5 <= 40) /* Line 681, Address: 0x10041c8 */
  {
    if (pSonic->EXE_NO >= 5) /* Line 683, Address: 0x10041e0 */
    {
      if (pSonic->EXE_NO < 9) /* Line 685, Address: 0x10041f8 */
      {
        pActwk->EXE_NO = 5; /* Line 687, Address: 0x1004210 */
        return; /* Line 688, Address: 0x100421c */
      }
    }
  }
  ld0.l = random(); /* Line 692, Address: 0x1004224 */
  ld0.l &= 32767; /* Line 693, Address: 0x1004230 */
  ld0.w.l = (int)ld0.w.l % 256; /* Line 694, Address: 0x100423c */
  if (ld0.w.l == 0) /* Line 695, Address: 0x1004270 */
  {
    if (pActwk->XPOSI.w.h == 384) /* Line 697, Address: 0x1004284 */
    {
      pActwk->XPOSI.w.h = 394; /* Line 699, Address: 0x10042a0 */
    }
    chk_sonicposi(pActwk, pSonic, &d5, &d6); /* Line 701, Address: 0x10042ac */
    if (d5 >= 40) /* Line 702, Address: 0x10042c4 */
    {
      if (myposichk(pActwk) == 0) /* Line 704, Address: 0x10042dc */
      {
        pActwk->TM_CNT = 64; /* Line 706, Address: 0x10042f8 */
        pActwk->EXE_NO = 11; /* Line 707, Address: 0x1004304 */
        return; /* Line 708, Address: 0x1004310 */
      }
    }
  }
  ld0.w.l = 0; /* Line 712, Address: 0x1004318 */
  if (pActwk->X_SPEED.l < 0) /* Line 713, Address: 0x100431c */
  {
    ld0.w.l = 1; /* Line 715, Address: 0x100432c */
  }
  if (d6 != ld0.w.l) /* Line 717, Address: 0x1004334 */
  {
    pActwk->EXE_NO = 9; /* Line 719, Address: 0x1004354 */
  }
} /* Line 721, Address: 0x1004360 */




static void emmyinit(sprite_status_thanks* pActwk) { /* Line 726, Address: 0x1004370 */
  pActwk->XPOSI.w.h = -10; /* Line 727, Address: 0x1004378 */
  pActwk->YPOSI.w.h = 141; /* Line 728, Address: 0x1004384 */

  pActwk->X_SPEED.l = 147456; /* Line 730, Address: 0x1004390 */
  pActwk->Y_SPEED.l = 0; /* Line 731, Address: 0x10043a0 */

  pActwk->CGBASE = 967; /* Line 733, Address: 0x10043a8 */
  pActwk->free[0] = 1; /* Line 734, Address: 0x10043b4 */

  pActwk->Y_ACCEL.l = 0; /* Line 736, Address: 0x10043c0 */

  pActwk->PAT_ADR = &erun_map; /* Line 738, Address: 0x10043c8 */
  pActwk->SPR_TIMER = erun_map.aPatDat[0].timer; /* Line 739, Address: 0x10043d8 */
  pActwk->PAT_NO = 0; /* Line 740, Address: 0x10043e8 */

  pActwk->EXE_NO = 2; /* Line 742, Address: 0x10043f0 */
} /* Line 743, Address: 0x10043fc */




static void e_runinit(sprite_status_thanks* pActwk) { /* Line 748, Address: 0x1004410 */
  short d5, d6;

  pActwk->XPOSI.l &= 33554431; /* Line 751, Address: 0x100441c */
  pActwk->X_SPEED.l = 147456; /* Line 752, Address: 0x1004430 */
  pActwk->Y_SPEED.l = 0; /* Line 753, Address: 0x1004440 */

  if (chk_sonicposi(pActwk, &actwk[0], &d5, &d6)) /* Line 755, Address: 0x1004448 */
  {
    pActwk->X_SPEED.l *= -1; /* Line 757, Address: 0x100446c */
    pActwk->SPR_FLG |= 128; /* Line 758, Address: 0x100447c */
  } /* Line 759, Address: 0x100448c */
  else
  {
    pActwk->SPR_FLG &= 127; /* Line 762, Address: 0x1004494 */
  }
  pActwk->CGBASE = 967; /* Line 764, Address: 0x10044a4 */
  pActwk->X_OFFSET = 0; /* Line 765, Address: 0x10044b0 */
  pActwk->X_ACCEL.l = 0; /* Line 766, Address: 0x10044b8 */
  pActwk->Y_OFFSET = 0; /* Line 767, Address: 0x10044c0 */
  pActwk->Y_ACCEL.l = 0; /* Line 768, Address: 0x10044c8 */

  pActwk->PAT_ADR = &erun_map; /* Line 770, Address: 0x10044d0 */
  pActwk->SPR_TIMER = erun_map.aPatDat[0].timer; /* Line 771, Address: 0x10044e0 */
  pActwk->PAT_NO = 0; /* Line 772, Address: 0x10044f0 */

  pActwk->EXE_NO = 2; /* Line 774, Address: 0x10044f8 */
} /* Line 775, Address: 0x1004504 */




static void emmymove(sprite_status_thanks* pActwk) { /* Line 780, Address: 0x1004520 */
  hbt_move(pActwk); /* Line 781, Address: 0x100452c */
  while (pActwk->XPOSI.w.h == 384) /* Line 782, Address: 0x1004538 */
  {
    hbt_move(pActwk); /* Line 784, Address: 0x1004540 */
  } /* Line 785, Address: 0x100454c */
  if (pActwk->SPR_FLG & 4) /* Line 786, Address: 0x1004568 */
  {
    pActwk->EXE_NO = 13; /* Line 788, Address: 0x1004580 */
  }
} /* Line 790, Address: 0x100458c */




static void e_kissset(sprite_status_thanks* pActwk) { /* Line 795, Address: 0x10045a0 */
  sprite_status_thanks* pNewActwk;
  short d5, d6;

  pActwk->XPOSI.l &= 33554431; /* Line 799, Address: 0x10045ac */
  pActwk->YPOSI.w.h = 141; /* Line 800, Address: 0x10045c0 */

  pActwk->X_SPEED.l = 0; /* Line 802, Address: 0x10045cc */
  pActwk->Y_SPEED.l = -196608; /* Line 803, Address: 0x10045d4 */

  pActwk->X_OFFSET = 0; /* Line 805, Address: 0x10045e0 */
  pActwk->X_ACCEL.l = 0; /* Line 806, Address: 0x10045e8 */
  pActwk->Y_OFFSET = 16384; /* Line 807, Address: 0x10045f0 */
  pActwk->Y_ACCEL.l = 0; /* Line 808, Address: 0x10045fc */

  pActwk->PAT_ADR = &ekiss_map; /* Line 810, Address: 0x1004604 */
  pActwk->PAT_NO = 0; /* Line 811, Address: 0x1004614 */
  pActwk->SPR_TIMER = ekiss_map.aPatDat[0].timer; /* Line 812, Address: 0x100461c */

  if (chk_sonicposi(pActwk, &actwk[0], &d5, &d6)) pActwk->SPR_FLG |= 128; /* Line 814, Address: 0x100462c */
  else pActwk->SPR_FLG &= 127; /* Line 815, Address: 0x1004668 */
  pActwk->free[4] = 12; /* Line 816, Address: 0x1004678 */
  if (get_actwk(&pNewActwk) == 0) /* Line 817, Address: 0x1004684 */
  {
    heart_tm = 1; /* Line 819, Address: 0x10046a0 */
    pNewActwk->ACT_NO = 7; /* Line 820, Address: 0x10046ac */
  }
  pActwk->EXE_NO = 4; /* Line 822, Address: 0x10046b8 */
} /* Line 823, Address: 0x10046c4 */




static void emmykiss(sprite_status_thanks* pActwk) { /* Line 828, Address: 0x10046e0 */
  sprite_status_thanks* pSonic;
  sprite_status_thanks* pMetal;
  sprite_status_thanks* pNewActwk;

  pSonic = &actwk[0]; /* Line 833, Address: 0x10046f4 */
  pMetal = &actwk[2]; /* Line 834, Address: 0x10046fc */

  hbt_move(pActwk); /* Line 836, Address: 0x1004704 */
  if (pActwk->YPOSI.w.h >= 140) /* Line 837, Address: 0x1004710 */
  {
    pActwk->Y_ACCEL.l = 0; /* Line 839, Address: 0x100472c */
  }
  --pActwk->TM_CNT; /* Line 841, Address: 0x1004734 */
  if (pActwk->TM_CNT <= 0) /* Line 842, Address: 0x1004744 */
  {
    if (pActwk->Y_ACCEL.l == 0) /* Line 844, Address: 0x100475c */
    {
      pActwk->YPOSI.w.h = 139; /* Line 846, Address: 0x100476c */
      pActwk->EXE_NO = 1; /* Line 847, Address: 0x1004778 */

      if (poseno == 2) /* Line 849, Address: 0x1004784 */
      {
        pSonic->SPR_FLG &= 251; /* Line 851, Address: 0x100479c */
        pMetal->SPR_FLG &= 251; /* Line 852, Address: 0x10047a8 */
        poseno = 0; /* Line 853, Address: 0x10047b4 */
      }
    }
  }
  --((char*)pActwk)[62]; /* Line 857, Address: 0x10047bc */
  if (((char*)pActwk)[62] < 0) /* Line 858, Address: 0x10047cc */
  {
    if (get_actwk(&pNewActwk) == 0) /* Line 860, Address: 0x10047e4 */
    {
      pNewActwk->ACT_NO = 7; /* Line 862, Address: 0x1004800 */
      ((char*)pActwk)[62] = 16; /* Line 863, Address: 0x100480c */
    }
  }
} /* Line 866, Address: 0x1004818 */




static void e_jumpset(sprite_status_thanks* pActwk) { /* Line 871, Address: 0x1004830 */
  sprite_status_thanks* pNewActwk;
  short d5, d6;

  pActwk->XPOSI.l &= 33554431; /* Line 875, Address: 0x100483c */
  pActwk->YPOSI.w.h = 141; /* Line 876, Address: 0x1004850 */

  pActwk->X_SPEED.l = 98304; /* Line 878, Address: 0x100485c */
  pActwk->Y_SPEED.l = -196608; /* Line 879, Address: 0x100486c */

  pActwk->X_OFFSET = 0; /* Line 881, Address: 0x1004878 */
  pActwk->X_ACCEL.l = 0; /* Line 882, Address: 0x1004880 */
  pActwk->Y_OFFSET = 16384; /* Line 883, Address: 0x1004888 */
  pActwk->Y_ACCEL.l = 0; /* Line 884, Address: 0x1004894 */

  pActwk->PAT_ADR = &ejump_map; /* Line 886, Address: 0x100489c */
  pActwk->PAT_NO = 0; /* Line 887, Address: 0x10048ac */
  pActwk->SPR_TIMER = ejump_map.aPatDat[0].timer; /* Line 888, Address: 0x10048b4 */

  if (chk_sonicposi(pActwk, &actwk[0], &d5, &d6)) /* Line 890, Address: 0x10048c4 */
  {
    pActwk->X_SPEED.l *= -1; /* Line 892, Address: 0x10048e8 */
    pActwk->SPR_FLG |= 128; /* Line 893, Address: 0x10048f8 */
  } /* Line 894, Address: 0x1004908 */
  else
  {
    pActwk->SPR_FLG &= 127; /* Line 897, Address: 0x1004910 */
  }


  if (pActwk->SPR_FLG & 128) /* Line 901, Address: 0x1004920 */
  {
    if (pActwk->SPR_FLG & 128) /* Line 903, Address: 0x1004938 */
    {
      pActwk->X_SPEED.l = -65536; /* Line 905, Address: 0x1004950 */
    }
  } /* Line 907, Address: 0x100495c */
  else
  {
    if (!(pActwk->SPR_FLG & 128)) /* Line 910, Address: 0x1004964 */
    {
      pActwk->X_SPEED.l = 65536; /* Line 912, Address: 0x100497c */
    }
  }
  pActwk->TM_CNT = 20; /* Line 915, Address: 0x1004988 */
  pActwk->free[4] = 16; /* Line 916, Address: 0x1004994 */
  if (get_actwk(&pNewActwk) == 0) /* Line 917, Address: 0x10049a0 */
  {
    heart_tm = 1; /* Line 919, Address: 0x10049bc */
    pNewActwk->ACT_NO = 7; /* Line 920, Address: 0x10049c8 */
  }
  pActwk->EXE_NO = 6; /* Line 922, Address: 0x10049d4 */
} /* Line 923, Address: 0x10049e0 */




static void emmyjump(sprite_status_thanks* pActwk) { /* Line 928, Address: 0x10049f0 */
  sprite_status_thanks* pNewActwk;

  hbt_move(pActwk); /* Line 931, Address: 0x10049fc */
  if (pActwk->YPOSI.w.h >= 140) /* Line 932, Address: 0x1004a08 */
  {
    pActwk->Y_ACCEL.l = 0; /* Line 934, Address: 0x1004a24 */
  }
  --pActwk->TM_CNT; /* Line 936, Address: 0x1004a2c */
  if (pActwk->TM_CNT <= 0) /* Line 937, Address: 0x1004a3c */
  {
    if (pActwk->Y_ACCEL.l == 0) /* Line 939, Address: 0x1004a54 */
    {
      pActwk->YPOSI.w.h = 139; /* Line 941, Address: 0x1004a64 */
      pActwk->EXE_NO = 7; /* Line 942, Address: 0x1004a70 */
    }
  }
  --((char*)pActwk)[62]; /* Line 945, Address: 0x1004a7c */
  if (((char*)pActwk)[62] < 0) /* Line 946, Address: 0x1004a8c */
  {
    if (get_actwk(&pNewActwk) == 0) /* Line 948, Address: 0x1004aa4 */
    {
      pNewActwk->ACT_NO = 7; /* Line 950, Address: 0x1004ac0 */
      ((char*)pActwk)[62] = 16; /* Line 951, Address: 0x1004acc */
    }
  }
} /* Line 954, Address: 0x1004ad8 */




static void e_catchset(sprite_status_thanks* pActwk) { /* Line 959, Address: 0x1004af0 */
  sprite_status_thanks* pSonic;
  sprite_status_thanks* pNewActwk;

  pSonic = &actwk[0]; /* Line 963, Address: 0x1004b00 */

  pActwk->XPOSI.l &= 33554431; /* Line 965, Address: 0x1004b08 */
  pActwk->YPOSI.w.h = 141; /* Line 966, Address: 0x1004b1c */

  if (pActwk->SPR_FLG & 128) /* Line 968, Address: 0x1004b28 */
  {
    pActwk->SPR_FLG |= 128; /* Line 970, Address: 0x1004b40 */
    pActwk->XPOSI.l = pSonic->XPOSI.l; /* Line 971, Address: 0x1004b50 */
    pActwk->XPOSI.w.h += 16; /* Line 972, Address: 0x1004b5c */
    pActwk->X_SPEED.l *= -1; /* Line 973, Address: 0x1004b6c */
  } /* Line 974, Address: 0x1004b7c */
  else
  {
    pActwk->SPR_FLG &= 127; /* Line 977, Address: 0x1004b84 */
    pActwk->XPOSI.l = pSonic->XPOSI.l; /* Line 978, Address: 0x1004b94 */
    pActwk->XPOSI.w.h -= 16; /* Line 979, Address: 0x1004ba0 */
  }
  pActwk->X_SPEED.l = 0; /* Line 981, Address: 0x1004bb0 */
  pActwk->Y_SPEED.l = 0; /* Line 982, Address: 0x1004bb8 */

  pActwk->X_OFFSET = 0; /* Line 984, Address: 0x1004bc0 */
  pActwk->X_ACCEL.l = 0; /* Line 985, Address: 0x1004bc8 */
  pActwk->Y_OFFSET = 0; /* Line 986, Address: 0x1004bd0 */
  pActwk->Y_ACCEL.l = 0; /* Line 987, Address: 0x1004bd8 */

  pActwk->PAT_ADR = &ecatch_map; /* Line 989, Address: 0x1004be0 */
  pActwk->PAT_NO = 0; /* Line 990, Address: 0x1004bf0 */
  pActwk->SPR_TIMER = ecatch_map.aPatDat[0].timer; /* Line 991, Address: 0x1004bf8 */

  pActwk->free[0] = 0; /* Line 993, Address: 0x1004c08 */

  pActwk->free[4] = 12; /* Line 995, Address: 0x1004c10 */
  if (get_actwk(&pNewActwk) == 0) /* Line 996, Address: 0x1004c1c */
  {
    heart_tm = 1; /* Line 998, Address: 0x1004c38 */
    pNewActwk->ACT_NO = 7; /* Line 999, Address: 0x1004c44 */
  }
  pActwk->EXE_NO = 8; /* Line 1001, Address: 0x1004c50 */
} /* Line 1002, Address: 0x1004c5c */




static void emmy_catch(sprite_status_thanks* pActwk) { /* Line 1007, Address: 0x1004c70 */
  sprite_status_thanks* pSonic;
  sprite_status_thanks* pNewActwk;

  pSonic = &actwk[0]; /* Line 1011, Address: 0x1004c80 */

  if (pSonic->SPR_FLG & 128) /* Line 1013, Address: 0x1004c88 */
  {
    pActwk->SPR_FLG |= 128; /* Line 1015, Address: 0x1004c9c */
    pActwk->XPOSI.l = pSonic->XPOSI.l; /* Line 1016, Address: 0x1004cac */
    pActwk->XPOSI.w.h += 16; /* Line 1017, Address: 0x1004cb8 */
    pActwk->X_SPEED.l *= -1; /* Line 1018, Address: 0x1004cc8 */
  } /* Line 1019, Address: 0x1004cd8 */
  else
  {
    pActwk->SPR_FLG &= 127; /* Line 1022, Address: 0x1004ce0 */
    pActwk->XPOSI.l = pSonic->XPOSI.l; /* Line 1023, Address: 0x1004cf0 */
    pActwk->XPOSI.w.h -= 16; /* Line 1024, Address: 0x1004cfc */
  }

  if (pSonic->EXE_NO >= 5) /* Line 1027, Address: 0x1004d0c */
  {
    if (pSonic->EXE_NO < 9) /* Line 1029, Address: 0x1004d20 */
    {
      --((char*)pActwk)[62]; /* Line 1031, Address: 0x1004d34 */
      if (((char*)pActwk)[62] >= 0) return; /* Line 1032, Address: 0x1004d44 */



      if (get_actwk(&pNewActwk) == 0) /* Line 1036, Address: 0x1004d5c */
      {
        pNewActwk->ACT_NO = 7; /* Line 1038, Address: 0x1004d78 */
        ((char*)pActwk)[62] = 16; /* Line 1039, Address: 0x1004d84 */
        return; /* Line 1040, Address: 0x1004d90 */
      }
    }
  }
  pActwk->TM_CNT = 40; /* Line 1044, Address: 0x1004d98 */
  pActwk->EXE_NO = 3; /* Line 1045, Address: 0x1004da4 */
  pActwk->free[0] = 1; /* Line 1046, Address: 0x1004db0 */
} /* Line 1047, Address: 0x1004dbc */




static void e_turnset(sprite_status_thanks* pActwk) { /* Line 1052, Address: 0x1004dd0 */
  short d5, d6;

  pActwk->YPOSI.w.h = 141; /* Line 1055, Address: 0x1004ddc */

  pActwk->X_SPEED.l = 147456; /* Line 1057, Address: 0x1004de8 */
  pActwk->Y_SPEED.l = 0; /* Line 1058, Address: 0x1004df8 */

  pActwk->X_OFFSET = -8192; /* Line 1060, Address: 0x1004e00 */
  pActwk->X_ACCEL.l = 0; /* Line 1061, Address: 0x1004e0c */
  pActwk->Y_OFFSET = 0; /* Line 1062, Address: 0x1004e14 */
  pActwk->Y_ACCEL.l = 0; /* Line 1063, Address: 0x1004e1c */

  pActwk->PAT_ADR = &erun_map; /* Line 1065, Address: 0x1004e24 */
  pActwk->PAT_NO = 0; /* Line 1066, Address: 0x1004e34 */
  pActwk->SPR_TIMER = erun_map.aPatDat[0].timer; /* Line 1067, Address: 0x1004e3c */

  pActwk->SPR_FLG |= 128; /* Line 1069, Address: 0x1004e4c */
  if (chk_sonicposi(pActwk, &actwk[0], &d5 ,&d6) == 0) /* Line 1070, Address: 0x1004e5c */
  {
    pActwk->SPR_FLG &= 127; /* Line 1072, Address: 0x1004e88 */
    pActwk->X_OFFSET *= -1; /* Line 1073, Address: 0x1004e98 */
    pActwk->X_SPEED.l *= -1; /* Line 1074, Address: 0x1004ea8 */
  }
  pActwk->EXE_NO = 10; /* Line 1076, Address: 0x1004eb8 */
} /* Line 1077, Address: 0x1004ec4 */




static void emmyturn(sprite_status_thanks* pActwk) { /* Line 1082, Address: 0x1004ee0 */
  short d0;

  hbt_move(pActwk); /* Line 1085, Address: 0x1004ef0 */
  d0 = pActwk->X_SPEED.w.h; /* Line 1086, Address: 0x1004efc */
  d0 += pActwk->X_ACCEL.w.h; /* Line 1087, Address: 0x1004f0c */
  if (d0 == 0) /* Line 1088, Address: 0x1004f20 */
  {
    if (poseno == 2) pActwk->TM_CNT = 80; /* Line 1090, Address: 0x1004f30 */
    else pActwk->TM_CNT = 20; /* Line 1091, Address: 0x1004f5c */
    pActwk->EXE_NO = 3; /* Line 1092, Address: 0x1004f68 */
  }
} /* Line 1094, Address: 0x1004f74 */




static void e_standset(sprite_status_thanks* pActwk) { /* Line 1099, Address: 0x1004f90 */
  sprite_status_thanks* pNewActwk;
  int_union ld0;
  short d5, d6;

  pActwk->XPOSI.l &= 33554431; /* Line 1104, Address: 0x1004f9c */
  pActwk->YPOSI.w.h = 141; /* Line 1105, Address: 0x1004fb0 */
  pActwk->X_SPEED.l = 0; /* Line 1106, Address: 0x1004fbc */
  pActwk->Y_SPEED.l = 0; /* Line 1107, Address: 0x1004fc4 */

  pActwk->X_OFFSET = 0; /* Line 1109, Address: 0x1004fcc */
  pActwk->X_ACCEL.l = 0; /* Line 1110, Address: 0x1004fd4 */
  pActwk->Y_OFFSET = 0; /* Line 1111, Address: 0x1004fdc */
  pActwk->Y_ACCEL.l = 0; /* Line 1112, Address: 0x1004fe4 */

  ld0.l = random(); /* Line 1114, Address: 0x1004fec */
  ld0.l &= 32767; /* Line 1115, Address: 0x1004ff8 */
  ld0.w.l = (int)ld0.w.l % 2; /* Line 1116, Address: 0x1005004 */
  if (ld0.w.l == 0) /* Line 1117, Address: 0x1005038 */
  {
    pActwk->PAT_ADR = &estand_map; /* Line 1119, Address: 0x100504c */
    pActwk->PAT_NO = 0; /* Line 1120, Address: 0x100505c */
    pActwk->SPR_TIMER = estand_map.aPatDat[0].timer; /* Line 1121, Address: 0x1005064 */
  } /* Line 1122, Address: 0x1005074 */
  else
  {
    pActwk->PAT_ADR = &estand2_map; /* Line 1125, Address: 0x100507c */
    pActwk->PAT_NO = 0; /* Line 1126, Address: 0x100508c */
    pActwk->SPR_TIMER = estand2_map.aPatDat[0].timer; /* Line 1127, Address: 0x1005094 */
  }

  if (chk_sonicposi(pActwk, &actwk[0], &d5, &d6)) pActwk->SPR_FLG |= 128; /* Line 1130, Address: 0x10050a4 */
  else pActwk->SPR_FLG &= 127; /* Line 1131, Address: 0x10050e0 */
  pActwk->free[4] = 16; /* Line 1132, Address: 0x10050f0 */
  if (get_actwk(&pNewActwk) == 0) /* Line 1133, Address: 0x10050fc */
  {
    heart_tm = 1; /* Line 1135, Address: 0x1005118 */
    pNewActwk->ACT_NO = 7; /* Line 1136, Address: 0x1005124 */
  }
  pActwk->EXE_NO = 12; /* Line 1138, Address: 0x1005130 */
} /* Line 1139, Address: 0x100513c */




static void emmymoji(sprite_status_thanks* pActwk) { /* Line 1144, Address: 0x1005150 */
  sprite_status_thanks* pSonic;
  short d5, d6;

  pSonic = &actwk[0]; /* Line 1148, Address: 0x1005160 */

  pActwk->XPOSI.w.h &= 511; /* Line 1150, Address: 0x1005168 */
  pSonic->XPOSI.w.h &= 511; /* Line 1151, Address: 0x1005178 */
  if (chk_sonicposi(pActwk, &actwk[0], &d5, &d6)) pActwk->SPR_FLG |= 128; /* Line 1152, Address: 0x1005184 */
  else pActwk->SPR_FLG &= 127; /* Line 1153, Address: 0x10051c0 */
  --pActwk->TM_CNT; /* Line 1154, Address: 0x10051d0 */
  if (pActwk->TM_CNT <= 0) /* Line 1155, Address: 0x10051e0 */
  {
    pActwk->EXE_NO = 1; /* Line 1157, Address: 0x10051f8 */
  }
} /* Line 1159, Address: 0x1005204 */




static void emmyexit(sprite_status_thanks* pActwk) { /* Line 1164, Address: 0x1005220 */
  waitmode(pActwk); /* Line 1165, Address: 0x100522c */
  if (animal_flg == 2) /* Line 1166, Address: 0x1005238 */
  {
    pActwk->XPOSI.w.h = 448; /* Line 1168, Address: 0x1005250 */
    pActwk->X_SPEED.l = 147456; /* Line 1169, Address: 0x100525c */
    pActwk->Y_SPEED.l = 0; /* Line 1170, Address: 0x100526c */
    pActwk->SPR_FLG &= 127; /* Line 1171, Address: 0x1005274 */

    pActwk->PAT_ADR = &erun_map; /* Line 1173, Address: 0x1005284 */
    pActwk->SPR_TIMER = erun_map.aPatDat[0].timer; /* Line 1174, Address: 0x1005294 */
    pActwk->PAT_NO = 0; /* Line 1175, Address: 0x10052a4 */

    pActwk->EXE_NO = 15; /* Line 1177, Address: 0x10052ac */
  }
} /* Line 1179, Address: 0x10052b8 */




static void emmypose(sprite_status_thanks* pActwk) { /* Line 1184, Address: 0x10052d0 */
  sprite_status_thanks* pSonic;
  sprite_status_thanks* pMetal;

  pSonic = &actwk[0]; /* Line 1188, Address: 0x10052e4 */

  pActwk->XPOSI.l += pActwk->X_SPEED.l; /* Line 1190, Address: 0x10052ec */
  pActwk->YPOSI.l += pActwk->Y_SPEED.l; /* Line 1191, Address: 0x1005304 */

  if (pSonic->X_SPEED.l == 0) /* Line 1193, Address: 0x100531c */
  {
    pMetal = &actwk[2]; /* Line 1195, Address: 0x1005328 */
    if (pMetal->X_SPEED.l == 0) /* Line 1196, Address: 0x1005330 */
    {
      if (centerchk(pActwk)) /* Line 1198, Address: 0x100533c */
      {
        pActwk->EXE_NO = 9; /* Line 1200, Address: 0x1005350 */
      }
    }
  }
} /* Line 1204, Address: 0x100535c */




static void emmyesc(sprite_status_thanks* pActwk) { /* Line 1209, Address: 0x1005380 */
  escape_chk(pActwk); /* Line 1210, Address: 0x100538c */
} /* Line 1211, Address: 0x1005398 */




void metals_ctrl(sprite_status_thanks* pActwk) { /* Line 1216, Address: 0x10053b0 */
  sprite_status_thanks* pSonic;
  void(*acttbl[16])(sprite_status_thanks*) = /* Line 1218, Address: 0x10053c0 */
  {
    &metalsinit,
    &m_flyset,
    &metalsfly,
    &m_brakeset,
    &metalsbrake,
    &m_stopset,
    &metalsstop,
    &m_standset,
    &metalstand,
    &m_startset,
    &metalstartcttbl,
    &m_eraset,
    &metalsera,
    &metalsexit,
    &metalspit,
    &metalsesc
  };

  pSonic = &actwk[0]; /* Line 1238, Address: 0x10053f4 */
  if (animal_flg) /* Line 1239, Address: 0x10053fc */
  {
    pActwk->SPR_FLG |= 4; /* Line 1241, Address: 0x100540c */
  }
  acttbl[pActwk->EXE_NO](pActwk); /* Line 1243, Address: 0x100541c */
  pActwk->XPOSI.w.h &= 511; /* Line 1244, Address: 0x1005440 */
} /* Line 1245, Address: 0x1005450 */




static void metalsinit(sprite_status_thanks* pActwk) { /* Line 1250, Address: 0x1005470 */
  int_union ld0;

  pActwk->XPOSI.w.h = 336; /* Line 1253, Address: 0x100547c */
  pActwk->YPOSI.w.h = 132; /* Line 1254, Address: 0x1005488 */

  pActwk->X_SPEED.l = -237568; /* Line 1256, Address: 0x1005494 */
  pActwk->Y_SPEED.l = 0; /* Line 1257, Address: 0x10054a4 */

  pActwk->X_OFFSET = 0; /* Line 1259, Address: 0x10054ac */
  pActwk->X_ACCEL.l = 0; /* Line 1260, Address: 0x10054b4 */
  pActwk->Y_OFFSET = 0; /* Line 1261, Address: 0x10054bc */
  pActwk->Y_ACCEL.l = 0; /* Line 1262, Address: 0x10054c4 */

  pActwk->CGBASE = 25785; /* Line 1264, Address: 0x10054cc */
  pActwk->free[0] = 3; /* Line 1265, Address: 0x10054d8 */
  pActwk->SPR_FLG |= 128; /* Line 1266, Address: 0x10054e4 */

  pActwk->PAT_ADR = &m_fly1_map; /* Line 1268, Address: 0x10054f4 */
  pActwk->SPR_TIMER = m_fly1_map.aPatDat[0].timer; /* Line 1269, Address: 0x1005504 */
  pActwk->PAT_NO = 0; /* Line 1270, Address: 0x1005514 */

  ld0.l = random(); /* Line 1272, Address: 0x100551c */
  ld0.l &= 32767; /* Line 1273, Address: 0x1005528 */
  ld0.w.l = (int)ld0.w.l % 128; /* Line 1274, Address: 0x1005534 */
  pActwk->TM_CNT = ld0.w.l; /* Line 1275, Address: 0x1005568 */
  pActwk->TM_CNT += 128; /* Line 1276, Address: 0x1005574 */

  pActwk->EXE_NO = 2; /* Line 1278, Address: 0x1005584 */
} /* Line 1279, Address: 0x1005590 */




static void m_flyset(sprite_status_thanks* pActwk) { /* Line 1284, Address: 0x10055a0 */
  int_union ld0;

  pActwk->YPOSI.w.h = 132; /* Line 1287, Address: 0x10055ac */
  pActwk->X_SPEED.l = 237568; /* Line 1288, Address: 0x10055b8 */
  pActwk->Y_SPEED.l = 0; /* Line 1289, Address: 0x10055c8 */

  if (pActwk->SPR_FLG & 128) /* Line 1291, Address: 0x10055d0 */
  {
    pActwk->X_SPEED.l *= -1; /* Line 1293, Address: 0x10055e8 */
  }

  pActwk->X_OFFSET = 0; /* Line 1296, Address: 0x10055f8 */
  pActwk->X_ACCEL.l = 0; /* Line 1297, Address: 0x1005600 */
  pActwk->Y_OFFSET = 0; /* Line 1298, Address: 0x1005608 */
  pActwk->Y_ACCEL.l = 0; /* Line 1299, Address: 0x1005610 */

  pActwk->CGBASE = 25785; /* Line 1301, Address: 0x1005618 */
  pActwk->free[0] = 3; /* Line 1302, Address: 0x1005624 */

  pActwk->PAT_ADR = &m_fly1_map; /* Line 1304, Address: 0x1005630 */
  pActwk->SPR_TIMER = m_fly1_map.aPatDat[0].timer; /* Line 1305, Address: 0x1005640 */
  pActwk->PAT_NO = 0; /* Line 1306, Address: 0x1005650 */

  ld0.l = random(); /* Line 1308, Address: 0x1005658 */
  ld0.l &= 32767; /* Line 1309, Address: 0x1005664 */
  ld0.w.l = (int)ld0.w.l % 192; /* Line 1310, Address: 0x1005670 */
  pActwk->TM_CNT = ld0.w.l; /* Line 1311, Address: 0x1005694 */
  pActwk->TM_CNT += 128; /* Line 1312, Address: 0x10056a0 */

  if (dsplaychk(pActwk) == 0) /* Line 1314, Address: 0x10056b0 */
  {
    pActwk->free[2] = 1; /* Line 1316, Address: 0x10056cc */
  }
  pActwk->EXE_NO = 2; /* Line 1318, Address: 0x10056d8 */
} /* Line 1319, Address: 0x10056e4 */




static void metalsfly(sprite_status_thanks* pActwk) { /* Line 1324, Address: 0x1005700 */
  sprite_status_thanks* pSonic;
  short d5, d6;

  pSonic = &actwk[0]; /* Line 1328, Address: 0x1005710 */

  pActwk->XPOSI.l += pActwk->X_SPEED.l; /* Line 1330, Address: 0x1005718 */
  pActwk->YPOSI.l += pActwk->Y_SPEED.l; /* Line 1331, Address: 0x1005730 */

  m_sndchk(pActwk); /* Line 1333, Address: 0x1005748 */

  if (pActwk->SPR_FLG & 4) /* Line 1335, Address: 0x1005754 */
  {
    pActwk->free[2] = 0; /* Line 1337, Address: 0x100576c */
    pActwk->EXE_NO = 13; /* Line 1338, Address: 0x1005774 */
    return; /* Line 1339, Address: 0x1005780 */
  }
  if (pSonic->ACT_NO == 0) /* Line 1341, Address: 0x1005788 */
  {
    pActwk->free[2] = 0; /* Line 1343, Address: 0x1005798 */
    pActwk->EXE_NO = 15; /* Line 1344, Address: 0x10057a0 */
    return; /* Line 1345, Address: 0x10057ac */
  }
  if (pActwk->XPOSI.w.h >= 376) /* Line 1347, Address: 0x10057b4 */
  {
    if (pActwk->XPOSI.w.h <= 392) /* Line 1349, Address: 0x10057d0 */
    {
      pActwk->free[2] = 0; /* Line 1351, Address: 0x10057ec */
      ((short*)pActwk)[31] = 128; /* Line 1352, Address: 0x10057f4 */
      pActwk->EXE_NO = 14; /* Line 1353, Address: 0x1005800 */
      return; /* Line 1354, Address: 0x100580c */
    }
  }
  --pActwk->TM_CNT; /* Line 1357, Address: 0x1005814 */
  if (pActwk->TM_CNT < 0) /* Line 1358, Address: 0x1005824 */
  {
    pActwk->XPOSI.l &= 33554431; /* Line 1360, Address: 0x100583c */
    pActwk->TM_CNT = 0; /* Line 1361, Address: 0x1005850 */

    chk_sonicposi(pActwk, &actwk[0], &d5, &d6); /* Line 1363, Address: 0x1005858 */
    if (d5 < 40) return; /* Line 1364, Address: 0x1005874 */

    chk_sonicposi(pActwk, &actwk[1], &d5, &d6); /* Line 1366, Address: 0x100588c */
    if (d5 < 40) return; /* Line 1367, Address: 0x10058a8 */

    if (myposichk(pActwk)) return; /* Line 1369, Address: 0x10058c0 */
    pActwk->free[2] = 0; /* Line 1370, Address: 0x10058d4 */
    pActwk->EXE_NO = 3; /* Line 1371, Address: 0x10058dc */
  }
} /* Line 1373, Address: 0x10058e8 */




static void m_brakeset(sprite_status_thanks* pActwk) { /* Line 1378, Address: 0x1005900 */
  pActwk->YPOSI.w.h = 136; /* Line 1379, Address: 0x1005908 */

  pActwk->X_OFFSET = -14336; /* Line 1381, Address: 0x1005914 */
  if (pActwk->SPR_FLG & 128) /* Line 1382, Address: 0x1005920 */
  {
    pActwk->X_OFFSET *= -1; /* Line 1384, Address: 0x1005938 */
  }

  pActwk->X_ACCEL.l = 0; /* Line 1387, Address: 0x1005948 */
  pActwk->Y_OFFSET = 0; /* Line 1388, Address: 0x1005950 */
  pActwk->Y_ACCEL.l = 0; /* Line 1389, Address: 0x1005958 */

  pActwk->PAT_ADR = &m_brake_map; /* Line 1391, Address: 0x1005960 */
  pActwk->SPR_TIMER = m_brake_map.aPatDat[0].timer; /* Line 1392, Address: 0x1005970 */
  pActwk->PAT_NO = 0; /* Line 1393, Address: 0x1005980 */
  pActwk->EXE_NO = 4; /* Line 1394, Address: 0x1005988 */
} /* Line 1395, Address: 0x1005994 */




static void metalsbrake(sprite_status_thanks* pActwk) { /* Line 1400, Address: 0x10059a0 */
  short d0;

  hbt_move(pActwk); /* Line 1403, Address: 0x10059b0 */
  d0 = pActwk->X_SPEED.w.h; /* Line 1404, Address: 0x10059bc */
  d0 += pActwk->X_ACCEL.w.h; /* Line 1405, Address: 0x10059cc */
  if (d0 == 0) /* Line 1406, Address: 0x10059e0 */
  {
    pActwk->EXE_NO = 5; /* Line 1408, Address: 0x10059f0 */
  }
} /* Line 1410, Address: 0x10059fc */




static void m_stopset(sprite_status_thanks* pActwk) { /* Line 1415, Address: 0x1005a10 */
  pActwk->XPOSI.l &= 33554431; /* Line 1416, Address: 0x1005a18 */

  if (pActwk->XPOSI.w.h == 384) /* Line 1418, Address: 0x1005a2c */
  {
    pActwk->XPOSI.w.h = 394; /* Line 1420, Address: 0x1005a48 */
  }

  pActwk->YPOSI.w.h = 140; /* Line 1423, Address: 0x1005a54 */
  pActwk->X_SPEED.l = 0; /* Line 1424, Address: 0x1005a60 */
  pActwk->Y_SPEED.l = 0; /* Line 1425, Address: 0x1005a68 */

  pActwk->X_OFFSET = 0; /* Line 1427, Address: 0x1005a70 */
  pActwk->X_ACCEL.l = 0; /* Line 1428, Address: 0x1005a78 */
  pActwk->Y_OFFSET = 0; /* Line 1429, Address: 0x1005a80 */
  pActwk->Y_ACCEL.l = 0; /* Line 1430, Address: 0x1005a88 */

  pActwk->PAT_ADR = &m_stop_map; /* Line 1432, Address: 0x1005a90 */
  pActwk->SPR_TIMER = m_stop_map.aPatDat[0].timer; /* Line 1433, Address: 0x1005aa0 */
  pActwk->PAT_NO = 0; /* Line 1434, Address: 0x1005ab0 */

  pActwk->TM_CNT = 32; /* Line 1436, Address: 0x1005ab8 */

  pActwk->EXE_NO = 6; /* Line 1438, Address: 0x1005ac4 */
} /* Line 1439, Address: 0x1005ad0 */




static void metalsstop(sprite_status_thanks* pActwk) { /* Line 1444, Address: 0x1005ae0 */
  sprite_status_thanks* pSonic;

  pSonic = &actwk[0]; /* Line 1447, Address: 0x1005aec */

  --pActwk->TM_CNT; /* Line 1449, Address: 0x1005af4 */
  if (pActwk->TM_CNT < 0) /* Line 1450, Address: 0x1005b04 */
  {
    if (pSonic->EXE_NO == 12) goto label1; /* Line 1452, Address: 0x1005b1c */
    if (pSonic->EXE_NO < 5) goto label2; /* Line 1453, Address: 0x1005b30 */
    if (pSonic->EXE_NO >= 9) goto label2; /* Line 1454, Address: 0x1005b44 */
label1:
    pActwk->EXE_NO = 11; /* Line 1456, Address: 0x1005b58 */
    return; /* Line 1457, Address: 0x1005b64 */
label2:
    pActwk->EXE_NO = 7; /* Line 1459, Address: 0x1005b6c */
  }

} /* Line 1462, Address: 0x1005b78 */




static void m_standset(sprite_status_thanks* pActwk) { /* Line 1467, Address: 0x1005b90 */
  pActwk->XPOSI.l &= 33554431; /* Line 1468, Address: 0x1005b98 */
  pActwk->X_SPEED.l = 0; /* Line 1469, Address: 0x1005bac */
  pActwk->Y_SPEED.l = 0; /* Line 1470, Address: 0x1005bb4 */

  pActwk->X_OFFSET = 0; /* Line 1472, Address: 0x1005bbc */
  pActwk->X_ACCEL.l = 0; /* Line 1473, Address: 0x1005bc4 */
  pActwk->Y_OFFSET = 0; /* Line 1474, Address: 0x1005bcc */
  pActwk->Y_ACCEL.l = 0; /* Line 1475, Address: 0x1005bd4 */

  pActwk->PAT_ADR = &m_stand_map; /* Line 1477, Address: 0x1005bdc */
  pActwk->SPR_TIMER = m_stand_map.aPatDat[0].timer; /* Line 1478, Address: 0x1005bec */
  pActwk->PAT_NO = 0; /* Line 1479, Address: 0x1005bfc */

  pActwk->TM_CNT = 64; /* Line 1481, Address: 0x1005c04 */
  pActwk->EXE_NO = 8; /* Line 1482, Address: 0x1005c10 */
} /* Line 1483, Address: 0x1005c1c */




static void metalstand(sprite_status_thanks* pActwk) { /* Line 1488, Address: 0x1005c30 */
  short d5, d6;

  --pActwk->TM_CNT; /* Line 1491, Address: 0x1005c3c */
  if (pActwk->TM_CNT < 0) /* Line 1492, Address: 0x1005c4c */
  {
    pActwk->EXE_NO = 9; /* Line 1494, Address: 0x1005c64 */
  }
  if (chk_sonicposi(pActwk, &actwk[0], &d5, &d6)) pActwk->SPR_FLG |= 128; /* Line 1496, Address: 0x1005c70 */
  else pActwk->SPR_FLG &= 127; /* Line 1497, Address: 0x1005cac */
} /* Line 1498, Address: 0x1005cbc */




static void m_startset(sprite_status_thanks* pActwk) { /* Line 1503, Address: 0x1005cd0 */
  short d5, d6;

  pActwk->XPOSI.l &= 33554431; /* Line 1506, Address: 0x1005cdc */
  pActwk->X_SPEED.l = 0; /* Line 1507, Address: 0x1005cf0 */
  pActwk->Y_SPEED.l = 0; /* Line 1508, Address: 0x1005cf8 */

  pActwk->X_OFFSET = 0; /* Line 1510, Address: 0x1005d00 */
  pActwk->X_ACCEL.l = 0; /* Line 1511, Address: 0x1005d08 */
  pActwk->Y_OFFSET = 0; /* Line 1512, Address: 0x1005d10 */
  pActwk->Y_ACCEL.l = 0; /* Line 1513, Address: 0x1005d18 */

  if (chk_sonicposi(pActwk, &actwk[0], &d5, &d6)) pActwk->SPR_FLG |= 128; /* Line 1515, Address: 0x1005d20 */
  else pActwk->SPR_FLG &= 127; /* Line 1516, Address: 0x1005d5c */

  pActwk->PAT_ADR = &m_furi_map; /* Line 1518, Address: 0x1005d6c */
  pActwk->SPR_TIMER = m_furi_map.aPatDat[0].timer; /* Line 1519, Address: 0x1005d7c */
  pActwk->PAT_NO = 0; /* Line 1520, Address: 0x1005d8c */

  pActwk->TM_CNT = 16; /* Line 1522, Address: 0x1005d94 */

  pActwk->free[3] = 0; /* Line 1524, Address: 0x1005da0 */

  pActwk->EXE_NO = 10; /* Line 1526, Address: 0x1005da8 */
} /* Line 1527, Address: 0x1005db4 */




static void metalstartcttbl(sprite_status_thanks* pActwk) { /* Line 1532, Address: 0x1005dd0 */
  short d5, d6;

  --pActwk->TM_CNT; /* Line 1535, Address: 0x1005ddc */
  if (pActwk->TM_CNT < 0) /* Line 1536, Address: 0x1005dec */
  {
    if (pActwk->free[3] == 0) /* Line 1538, Address: 0x1005e04 */
    {
      pActwk->YPOSI.w.h = 136; /* Line 1540, Address: 0x1005e18 */
      pActwk->PAT_ADR = &m_kamae_map; /* Line 1541, Address: 0x1005e24 */
      pActwk->SPR_TIMER = m_kamae_map.aPatDat[0].timer; /* Line 1542, Address: 0x1005e34 */
      pActwk->PAT_NO = 0; /* Line 1543, Address: 0x1005e44 */

      pActwk->TM_CNT = 48; /* Line 1545, Address: 0x1005e4c */
      pActwk->free[3] = 1; /* Line 1546, Address: 0x1005e58 */
    } /* Line 1547, Address: 0x1005e64 */
    else
    {
      pActwk->EXE_NO = 1; /* Line 1550, Address: 0x1005e6c */
    }
  }
  if (chk_sonicposi(pActwk, &actwk[0], &d5, &d6)) pActwk->SPR_FLG |= 128; /* Line 1553, Address: 0x1005e78 */
  else pActwk->SPR_FLG &= 127; /* Line 1554, Address: 0x1005eb4 */
} /* Line 1555, Address: 0x1005ec4 */




static void m_eraset(sprite_status_thanks* pActwk) { /* Line 1560, Address: 0x1005ee0 */
  pActwk->XPOSI.l &= 33554431; /* Line 1561, Address: 0x1005ee8 */
  pActwk->X_SPEED.l = 0; /* Line 1562, Address: 0x1005efc */
  pActwk->Y_SPEED.l = 0; /* Line 1563, Address: 0x1005f04 */

  pActwk->X_OFFSET = 0; /* Line 1565, Address: 0x1005f0c */
  pActwk->X_ACCEL.l = 0; /* Line 1566, Address: 0x1005f14 */
  pActwk->Y_OFFSET = 0; /* Line 1567, Address: 0x1005f1c */
  pActwk->Y_ACCEL.l = 0; /* Line 1568, Address: 0x1005f24 */

  pActwk->PAT_ADR = &m_era_map; /* Line 1570, Address: 0x1005f2c */
  pActwk->SPR_TIMER = m_era_map.aPatDat[0].timer; /* Line 1571, Address: 0x1005f3c */
  pActwk->PAT_NO = 0; /* Line 1572, Address: 0x1005f4c */

  pActwk->TM_CNT = 32; /* Line 1574, Address: 0x1005f54 */

  pActwk->free[3] = 0; /* Line 1576, Address: 0x1005f60 */
  pActwk->EXE_NO = 12; /* Line 1577, Address: 0x1005f68 */
} /* Line 1578, Address: 0x1005f74 */




static void metalsera(sprite_status_thanks* pActwk) { /* Line 1583, Address: 0x1005f80 */
  --pActwk->TM_CNT; /* Line 1584, Address: 0x1005f88 */
  if (pActwk->TM_CNT < 0) /* Line 1585, Address: 0x1005f98 */
  {
    if (pActwk->free[3] == 0) /* Line 1587, Address: 0x1005fb0 */
    {
      pActwk->PAT_ADR = &m_era2_map; /* Line 1589, Address: 0x1005fc4 */
      pActwk->SPR_TIMER = m_era2_map.aPatDat[0].timer; /* Line 1590, Address: 0x1005fd4 */
      pActwk->PAT_NO = 0; /* Line 1591, Address: 0x1005fe4 */

      pActwk->TM_CNT = 128; /* Line 1593, Address: 0x1005fec */
      pActwk->free[3] = 1; /* Line 1594, Address: 0x1005ff8 */
    } /* Line 1595, Address: 0x1006004 */
    else
    {
      pActwk->EXE_NO = 9; /* Line 1598, Address: 0x100600c */
    }
  }
} /* Line 1601, Address: 0x1006018 */




static void metalsexit(sprite_status_thanks* pActwk) { /* Line 1606, Address: 0x1006030 */
  waitmode(pActwk); /* Line 1607, Address: 0x100603c */

  if (animal_flg == 2) /* Line 1609, Address: 0x1006048 */
  {
    pActwk->XPOSI.w.h = 448; /* Line 1611, Address: 0x1006060 */
    pActwk->X_SPEED.l = 237568; /* Line 1612, Address: 0x100606c */
    pActwk->Y_SPEED.l = 0; /* Line 1613, Address: 0x100607c */
    pActwk->SPR_FLG &= 127; /* Line 1614, Address: 0x1006084 */
    pActwk->PAT_ADR = &m_fly1_map; /* Line 1615, Address: 0x1006094 */
    pActwk->SPR_TIMER = m_fly1_map.aPatDat[0].timer; /* Line 1616, Address: 0x10060a4 */
    pActwk->PAT_NO = 0; /* Line 1617, Address: 0x10060b4 */
    pActwk->EXE_NO = 15; /* Line 1618, Address: 0x10060bc */
  }
} /* Line 1620, Address: 0x10060c8 */




static void metalspit(sprite_status_thanks* pActwk) { /* Line 1625, Address: 0x10060e0 */
  pit_in(pActwk); /* Line 1626, Address: 0x10060ec */
} /* Line 1627, Address: 0x10060f8 */




static void metalsesc(sprite_status_thanks* pActwk) { /* Line 1632, Address: 0x1006110 */
  escape_chk(pActwk); /* Line 1633, Address: 0x100611c */
} /* Line 1634, Address: 0x1006128 */








void heart_ctrl(sprite_status_thanks* pActwk) { /* Line 1643, Address: 0x1006140 */
  void(*acttbl[2])(sprite_status_thanks*) = /* Line 1644, Address: 0x100614c */
  {
    &heartinit,
    &heartmove
  };

  acttbl[pActwk->EXE_NO](pActwk); /* Line 1650, Address: 0x1006168 */
} /* Line 1651, Address: 0x100618c */




static void heartinit(sprite_status_thanks* pActwk) { /* Line 1656, Address: 0x10061a0 */
  sprite_status_thanks* pEmmy;

  pEmmy = &actwk[1]; /* Line 1659, Address: 0x10061ac */

  pActwk->XPOSI.w.h = pEmmy->XPOSI.w.h; /* Line 1661, Address: 0x10061b4 */
  pActwk->YPOSI.w.h = pEmmy->YPOSI.w.h; /* Line 1662, Address: 0x10061c0 */

  pActwk->X_SPEED.l = 0; /* Line 1664, Address: 0x10061cc */
  pActwk->Y_SPEED.l = -32768; /* Line 1665, Address: 0x10061d4 */

  pActwk->X_WIDE = 32; /* Line 1667, Address: 0x10061e0 */
  pActwk->Y_WIDE = 4; /* Line 1668, Address: 0x10061ec */
  pActwk->X_OFFSET = 0; /* Line 1669, Address: 0x10061f8 */
  pActwk->Y_OFFSET = 0; /* Line 1670, Address: 0x1006200 */

  pActwk->CGBASE = 967; /* Line 1672, Address: 0x1006208 */
  pActwk->free[0] = 3; /* Line 1673, Address: 0x1006214 */

  pActwk->PAT_ADR = &eheart_map; /* Line 1675, Address: 0x1006220 */
  pActwk->PAT_NO = 0; /* Line 1676, Address: 0x1006230 */

  pActwk->free[2] = 32; /* Line 1678, Address: 0x1006238 */

  pActwk->EXE_NO = 1; /* Line 1680, Address: 0x1006244 */
} /* Line 1681, Address: 0x1006250 */




static void heartmove(sprite_status_thanks* pActwk) { /* Line 1686, Address: 0x1006260 */
  sinvmove(pActwk); /* Line 1687, Address: 0x100626c */
  if (pActwk->PAT_NO >= 3) /* Line 1688, Address: 0x1006278 */
  {
    pActwk->SPR_FLG |= 16; /* Line 1690, Address: 0x1006294 */
  }
} /* Line 1692, Address: 0x10062a4 */




void pocky_ctrl(sprite_status_thanks* pActwk) { /* Line 1697, Address: 0x10062c0 */
  void(*acttbl[2])(sprite_status_thanks*) = /* Line 1698, Address: 0x10062cc */
  {
    &pockyinit,
    &animalmove
  };

  acttbl[pActwk->EXE_NO](pActwk); /* Line 1704, Address: 0x10062e8 */
} /* Line 1705, Address: 0x100630c */




static void pockyinit(sprite_status_thanks* pActwk) { /* Line 1710, Address: 0x1006320 */
  int_union ld0;

  pActwk->XPOSI.w.h = -10; /* Line 1713, Address: 0x100632c */
  pActwk->YPOSI.w.h = 144; /* Line 1714, Address: 0x1006338 */

  pActwk->X_SPEED.l = 49152; /* Line 1716, Address: 0x1006344 */
  ld0.l = random(); /* Line 1717, Address: 0x1006350 */
  ld0.l &= 32767; /* Line 1718, Address: 0x100635c */
  ld0.w.h = ld0.w.l % 512; /* Line 1719, Address: 0x1006368 */
  ld0.w.l = 0; /* Line 1720, Address: 0x100639c */
  ld0.l >>= 8; /* Line 1721, Address: 0x10063a0 */
  pActwk->X_SPEED.l += ld0.l; /* Line 1722, Address: 0x10063ac */

  pActwk->Y_SPEED.l = -229376; /* Line 1724, Address: 0x10063c0 */
  ld0.l = random(); /* Line 1725, Address: 0x10063d0 */
  ld0.l &= 32767; /* Line 1726, Address: 0x10063dc */
  ld0.w.h = ld0.w.l % 512; /* Line 1727, Address: 0x10063e8 */
  ld0.w.l = 0; /* Line 1728, Address: 0x100641c */
  ld0.l >>= 8; /* Line 1729, Address: 0x1006420 */
  pActwk->Y_SPEED.l += ld0.l; /* Line 1730, Address: 0x100642c */


  pActwk->Y_OFFSET = 14336; /* Line 1733, Address: 0x1006440 */
  pActwk->Y_ACCEL.l = 0; /* Line 1734, Address: 0x100644c */
  pActwk->CGBASE = 25989; /* Line 1735, Address: 0x1006454 */

  pActwk->free[0] = 3; /* Line 1737, Address: 0x1006460 */
  pActwk->PAT_ADR = &pocky_map; /* Line 1738, Address: 0x100646c */
  pActwk->SPR_TIMER = pocky_map.aPatDat[0].timer; /* Line 1739, Address: 0x100647c */
  pActwk->PAT_NO = 0; /* Line 1740, Address: 0x100648c */
  pActwk->EXE_NO = 1; /* Line 1741, Address: 0x1006494 */
} /* Line 1742, Address: 0x10064a0 */




void pecky_ctrl(sprite_status_thanks* pActwk) { /* Line 1747, Address: 0x10064b0 */
  void(*acttbl[2])(sprite_status_thanks*) = /* Line 1748, Address: 0x10064bc */
  {
    &peckyinit,
    &animalmove
  };

  acttbl[pActwk->EXE_NO](pActwk); /* Line 1754, Address: 0x10064d8 */
} /* Line 1755, Address: 0x10064fc */




static void peckyinit(sprite_status_thanks* pActwk) { /* Line 1760, Address: 0x1006510 */
  int_union ld0;

  pActwk->XPOSI.w.h = -10; /* Line 1763, Address: 0x100651c */
  pActwk->YPOSI.w.h = 144; /* Line 1764, Address: 0x1006528 */

  pActwk->X_SPEED.l = 49152; /* Line 1766, Address: 0x1006534 */
  ld0.l = random(); /* Line 1767, Address: 0x1006540 */
  ld0.l &= 32767; /* Line 1768, Address: 0x100654c */
  ld0.w.h = ld0.w.l % 256; /* Line 1769, Address: 0x1006558 */
  ld0.w.l = 0; /* Line 1770, Address: 0x100658c */
  ld0.l >>= 8; /* Line 1771, Address: 0x1006590 */
  pActwk->X_SPEED.l += ld0.l; /* Line 1772, Address: 0x100659c */

  pActwk->Y_SPEED.l = -229376; /* Line 1774, Address: 0x10065b0 */
  ld0.l = random(); /* Line 1775, Address: 0x10065c0 */
  ld0.l &= 32767; /* Line 1776, Address: 0x10065cc */
  ld0.w.h = ld0.w.l % 256; /* Line 1777, Address: 0x10065d8 */
  ld0.w.l = 0; /* Line 1778, Address: 0x100660c */
  ld0.l >>= 8; /* Line 1779, Address: 0x1006610 */
  pActwk->Y_SPEED.l += ld0.l; /* Line 1780, Address: 0x100661c */

  pActwk->Y_OFFSET = 14336; /* Line 1782, Address: 0x1006630 */
  pActwk->Y_ACCEL.l = 0; /* Line 1783, Address: 0x100663c */
  pActwk->CGBASE = 25989; /* Line 1784, Address: 0x1006644 */

  pActwk->free[0] = 3; /* Line 1786, Address: 0x1006650 */
  pActwk->PAT_ADR = &pecky_map; /* Line 1787, Address: 0x100665c */
  pActwk->SPR_TIMER = pecky_map.aPatDat[0].timer; /* Line 1788, Address: 0x100666c */
  pActwk->PAT_NO = 0; /* Line 1789, Address: 0x100667c */
  pActwk->EXE_NO = 1; /* Line 1790, Address: 0x1006684 */
} /* Line 1791, Address: 0x1006690 */




void ricky_ctrl(sprite_status_thanks* pActwk) { /* Line 1796, Address: 0x10066a0 */
  void(*acttbl[2])(sprite_status_thanks*) = /* Line 1797, Address: 0x10066ac */
  {
    &rickyinit,
    &animalmove
  };

  acttbl[pActwk->EXE_NO](pActwk); /* Line 1803, Address: 0x10066c8 */
} /* Line 1804, Address: 0x10066ec */




static void rickyinit(sprite_status_thanks* pActwk) { /* Line 1809, Address: 0x1006700 */
  int_union ld0;

  pActwk->XPOSI.w.h = -10; /* Line 1812, Address: 0x100670c */
  pActwk->YPOSI.w.h = 164; /* Line 1813, Address: 0x1006718 */

  pActwk->X_SPEED.l = 49152; /* Line 1815, Address: 0x1006724 */
  ld0.l = random(); /* Line 1816, Address: 0x1006730 */
  ld0.l &= 32767; /* Line 1817, Address: 0x100673c */
  ld0.w.h = ld0.w.l % 256; /* Line 1818, Address: 0x1006748 */
  ld0.w.l = 0; /* Line 1819, Address: 0x100677c */
  ld0.l >>= 8; /* Line 1820, Address: 0x1006780 */
  pActwk->X_SPEED.l += ld0.l; /* Line 1821, Address: 0x100678c */

  pActwk->Y_SPEED.l = -229376; /* Line 1823, Address: 0x10067a0 */
  ld0.l = random(); /* Line 1824, Address: 0x10067b0 */
  ld0.l &= 32767; /* Line 1825, Address: 0x10067bc */
  ld0.w.h = ld0.w.l % 256; /* Line 1826, Address: 0x10067c8 */
  ld0.w.l = 0; /* Line 1827, Address: 0x10067fc */
  ld0.l >>= 8; /* Line 1828, Address: 0x1006800 */
  pActwk->Y_SPEED.l += ld0.l; /* Line 1829, Address: 0x100680c */

  pActwk->Y_OFFSET = 14336; /* Line 1831, Address: 0x1006820 */
  pActwk->Y_ACCEL.l = 0; /* Line 1832, Address: 0x100682c */

  pActwk->CGBASE = 25989; /* Line 1834, Address: 0x1006834 */
  pActwk->free[0] = 3; /* Line 1835, Address: 0x1006840 */
  pActwk->PAT_ADR = &ricky_map; /* Line 1836, Address: 0x100684c */
  pActwk->SPR_TIMER = ricky_map.aPatDat[0].timer; /* Line 1837, Address: 0x100685c */
  pActwk->PAT_NO = 0; /* Line 1838, Address: 0x100686c */
  pActwk->EXE_NO = 1; /* Line 1839, Address: 0x1006874 */
} /* Line 1840, Address: 0x1006880 */




void sheep_ctrl(sprite_status_thanks* pActwk) { /* Line 1845, Address: 0x1006890 */
  void(*acttbl[2])(sprite_status_thanks*) = /* Line 1846, Address: 0x100689c */
  {
    &sheepinit,
    &animalmove
  };

  acttbl[pActwk->EXE_NO](pActwk); /* Line 1852, Address: 0x10068b8 */
} /* Line 1853, Address: 0x10068dc */




static void sheepinit(sprite_status_thanks* pActwk) { /* Line 1858, Address: 0x10068f0 */
  int_union ld0;

  pActwk->XPOSI.w.h = -10; /* Line 1861, Address: 0x10068fc */
  pActwk->YPOSI.w.h = 164; /* Line 1862, Address: 0x1006908 */

  pActwk->X_SPEED.l = 49152; /* Line 1864, Address: 0x1006914 */
  ld0.l = random(); /* Line 1865, Address: 0x1006920 */
  ld0.l &= 32767; /* Line 1866, Address: 0x100692c */
  ld0.w.h = ld0.w.l % 512; /* Line 1867, Address: 0x1006938 */
  ld0.w.l = 0; /* Line 1868, Address: 0x100696c */
  ld0.l >>= 8; /* Line 1869, Address: 0x1006970 */
  pActwk->X_SPEED.l += ld0.l; /* Line 1870, Address: 0x100697c */

  pActwk->Y_SPEED.l = -229376; /* Line 1872, Address: 0x1006990 */
  ld0.l = random(); /* Line 1873, Address: 0x10069a0 */
  ld0.l &= 32767; /* Line 1874, Address: 0x10069ac */
  ld0.w.h = ld0.w.l % 256; /* Line 1875, Address: 0x10069b8 */
  ld0.w.l = 0; /* Line 1876, Address: 0x10069ec */
  ld0.l >>= 8; /* Line 1877, Address: 0x10069f0 */
  pActwk->Y_SPEED.l += ld0.l; /* Line 1878, Address: 0x10069fc */

  pActwk->Y_OFFSET = 16384; /* Line 1880, Address: 0x1006a10 */
  pActwk->Y_ACCEL.l = 0; /* Line 1881, Address: 0x1006a1c */

  pActwk->CGBASE = 25989; /* Line 1883, Address: 0x1006a24 */
  pActwk->free[0] = 3; /* Line 1884, Address: 0x1006a30 */
  pActwk->PAT_ADR = &sheep_map; /* Line 1885, Address: 0x1006a3c */
  pActwk->SPR_TIMER = sheep_map.aPatDat[0].timer; /* Line 1886, Address: 0x1006a4c */
  pActwk->PAT_NO = 0; /* Line 1887, Address: 0x1006a5c */
  pActwk->EXE_NO = 1; /* Line 1888, Address: 0x1006a64 */
} /* Line 1889, Address: 0x1006a70 */




static void animalmove(sprite_status_thanks* pActwk) { /* Line 1894, Address: 0x1006a80 */
  if (killchk(pActwk)) /* Line 1895, Address: 0x1006a8c */
  {
    pActwk->SPR_FLG |= 16; /* Line 1897, Address: 0x1006aa0 */
  } /* Line 1898, Address: 0x1006ab0 */
  else
  {
    hbt_move(pActwk); /* Line 1901, Address: 0x1006ab8 */
    if (pActwk->YPOSI.w.h >= 160) /* Line 1902, Address: 0x1006ac4 */
    {
      pActwk->Y_ACCEL.l = 0; /* Line 1904, Address: 0x1006ae0 */
    }
  }
} /* Line 1907, Address: 0x1006ae8 */




void flick_ctrl(sprite_status_thanks* pActwk) { /* Line 1912, Address: 0x1006b00 */
  void(*acttbl[2])(sprite_status_thanks*) = /* Line 1913, Address: 0x1006b0c */
  {
    &flickyinit,
    &birdmove
  };

  acttbl[pActwk->EXE_NO](pActwk); /* Line 1919, Address: 0x1006b28 */
} /* Line 1920, Address: 0x1006b4c */




static void flickyinit(sprite_status_thanks* pActwk) { /* Line 1925, Address: 0x1006b60 */
  int_union ld0;

  pActwk->XPOSI.w.h = -10; /* Line 1928, Address: 0x1006b6c */
  ld0.l = random(); /* Line 1929, Address: 0x1006b78 */
  ld0.l &= 32767; /* Line 1930, Address: 0x1006b84 */
  ld0.w.l = (int)ld0.w.l % 120; /* Line 1931, Address: 0x1006b90 */
  pActwk->YPOSI.w.h = ld0.w.l; /* Line 1932, Address: 0x1006bb4 */

  pActwk->X_SPEED.l = 65536; /* Line 1934, Address: 0x1006bc0 */
  pActwk->Y_SPEED.l = 0; /* Line 1935, Address: 0x1006bcc */

  pActwk->X_WIDE = 48; /* Line 1937, Address: 0x1006bd4 */
  pActwk->Y_WIDE = 4; /* Line 1938, Address: 0x1006be0 */
  pActwk->X_OFFSET = 0; /* Line 1939, Address: 0x1006bec */
  pActwk->Y_OFFSET = 0; /* Line 1940, Address: 0x1006bf4 */

  pActwk->CGBASE = 25989; /* Line 1942, Address: 0x1006bfc */
  pActwk->free[0] = 3; /* Line 1943, Address: 0x1006c08 */

  pActwk->PAT_ADR = &flick_map; /* Line 1945, Address: 0x1006c14 */
  pActwk->SPR_TIMER = flick_map.aPatDat[0].timer; /* Line 1946, Address: 0x1006c24 */
  pActwk->PAT_NO = 0; /* Line 1947, Address: 0x1006c34 */

  pActwk->EXE_NO = 1; /* Line 1949, Address: 0x1006c3c */
} /* Line 1950, Address: 0x1006c48 */




void inco_ctrl(sprite_status_thanks* pActwk) { /* Line 1955, Address: 0x1006c60 */
  void(*acttbl[2])(sprite_status_thanks*) = /* Line 1956, Address: 0x1006c6c */
  {
    &incoinit,
    &birdmove
  };

  acttbl[pActwk->EXE_NO](pActwk); /* Line 1962, Address: 0x1006c88 */
} /* Line 1963, Address: 0x1006cac */




static void incoinit(sprite_status_thanks* pActwk) { /* Line 1968, Address: 0x1006cc0 */
  int_union ld0;

  pActwk->XPOSI.w.h = -10; /* Line 1971, Address: 0x1006ccc */
  ld0.l = random(); /* Line 1972, Address: 0x1006cd8 */
  ld0.l &= 32767; /* Line 1973, Address: 0x1006ce4 */
  ld0.w.l = (int)ld0.w.l % 120; /* Line 1974, Address: 0x1006cf0 */
  pActwk->YPOSI.w.h = ld0.w.l; /* Line 1975, Address: 0x1006d14 */

  pActwk->X_SPEED.l = 32768; /* Line 1977, Address: 0x1006d20 */
  ld0.l = random(); /* Line 1978, Address: 0x1006d2c */
  ld0.l &= 32767; /* Line 1979, Address: 0x1006d38 */
  ld0.w.h = ld0.l % 256; /* Line 1980, Address: 0x1006d44 */
  ld0.w.l = 0; /* Line 1981, Address: 0x1006d70 */
  ld0.l >>= 8; /* Line 1982, Address: 0x1006d74 */
  pActwk->X_SPEED.l += ld0.l; /* Line 1983, Address: 0x1006d80 */
  pActwk->Y_SPEED.l = 0; /* Line 1984, Address: 0x1006d94 */

  pActwk->X_WIDE = 48; /* Line 1986, Address: 0x1006d9c */
  pActwk->Y_WIDE = 4; /* Line 1987, Address: 0x1006da8 */
  pActwk->X_OFFSET = 0; /* Line 1988, Address: 0x1006db4 */
  pActwk->Y_OFFSET = 0; /* Line 1989, Address: 0x1006dbc */

  pActwk->CGBASE = 25989; /* Line 1991, Address: 0x1006dc4 */
  pActwk->free[0] = 3; /* Line 1992, Address: 0x1006dd0 */

  pActwk->PAT_ADR = &inco_map; /* Line 1994, Address: 0x1006ddc */
  pActwk->SPR_TIMER = inco_map.aPatDat[0].timer; /* Line 1995, Address: 0x1006dec */
  pActwk->PAT_NO = 0; /* Line 1996, Address: 0x1006dfc */

  pActwk->EXE_NO = 1; /* Line 1998, Address: 0x1006e04 */
} /* Line 1999, Address: 0x1006e10 */




void hato_ctrl(sprite_status_thanks* pActwk) { /* Line 2004, Address: 0x1006e20 */
  void(*acttbl[2])(sprite_status_thanks*) = /* Line 2005, Address: 0x1006e2c */
  {
    &hatoinit,
    &birdmove
  };

  acttbl[pActwk->EXE_NO](pActwk); /* Line 2011, Address: 0x1006e48 */
} /* Line 2012, Address: 0x1006e6c */




static void hatoinit(sprite_status_thanks* pActwk) { /* Line 2017, Address: 0x1006e80 */
  int_union ld0;

  pActwk->XPOSI.w.h = -10; /* Line 2020, Address: 0x1006e8c */
  ld0.l = random(); /* Line 2021, Address: 0x1006e98 */
  ld0.l &= 32767; /* Line 2022, Address: 0x1006ea4 */
  ld0.w.l = (int)ld0.w.l % 120; /* Line 2023, Address: 0x1006eb0 */
  pActwk->YPOSI.w.h = ld0.w.l; /* Line 2024, Address: 0x1006ed4 */

  pActwk->X_SPEED.l = 32768; /* Line 2026, Address: 0x1006ee0 */
  ld0.l = random(); /* Line 2027, Address: 0x1006eec */
  ld0.l &= 32767; /* Line 2028, Address: 0x1006ef8 */
  ld0.w.h = ld0.w.l % 256; /* Line 2029, Address: 0x1006f04 */
  ld0.w.l = 0; /* Line 2030, Address: 0x1006f38 */
  ld0.l >>= 8; /* Line 2031, Address: 0x1006f3c */
  pActwk->X_SPEED.l += ld0.l; /* Line 2032, Address: 0x1006f48 */
  pActwk->Y_SPEED.l = 0; /* Line 2033, Address: 0x1006f5c */

  pActwk->X_WIDE = 48; /* Line 2035, Address: 0x1006f64 */
  pActwk->Y_WIDE = 4; /* Line 2036, Address: 0x1006f70 */
  pActwk->X_OFFSET = 0; /* Line 2037, Address: 0x1006f7c */
  pActwk->Y_OFFSET = 0; /* Line 2038, Address: 0x1006f84 */

  pActwk->CGBASE = 25989; /* Line 2040, Address: 0x1006f8c */
  pActwk->free[0] = 3; /* Line 2041, Address: 0x1006f98 */

  pActwk->PAT_ADR = &hato_map; /* Line 2043, Address: 0x1006fa4 */
  pActwk->SPR_TIMER = hato_map.aPatDat[0].timer; /* Line 2044, Address: 0x1006fb4 */
  pActwk->PAT_NO = 0; /* Line 2045, Address: 0x1006fc4 */

  pActwk->EXE_NO = 1; /* Line 2047, Address: 0x1006fcc */
} /* Line 2048, Address: 0x1006fd8 */




static void birdmove(sprite_status_thanks* pActwk) { /* Line 2053, Address: 0x1006ff0 */
  if (killchk(pActwk)) /* Line 2054, Address: 0x1006ffc */
  {
    pActwk->SPR_FLG |= 16; /* Line 2056, Address: 0x1007010 */
  } /* Line 2057, Address: 0x1007020 */
  else
  {
    sinhmove(pActwk); /* Line 2060, Address: 0x1007028 */
  }
} /* Line 2062, Address: 0x1007034 */










static short killchk(sprite_status_thanks* pActwk) { /* Line 2073, Address: 0x1007050 */
  if (pActwk->XPOSI.w.h < -31) return -1; /* Line 2074, Address: 0x1007058 */
  if (pActwk->XPOSI.w.h >= 336) return -1; /* Line 2075, Address: 0x1007080 */
  if (pActwk->YPOSI.w.h < -4) return -1; /* Line 2076, Address: 0x10070a8 */
  if (pActwk->YPOSI.w.h >= 224) return -1; /* Line 2077, Address: 0x10070d0 */
  return 0; /* Line 2078, Address: 0x10070f8 */
} /* Line 2079, Address: 0x10070fc */




static void sinhmove(sprite_status_thanks* pActwk) { /* Line 2084, Address: 0x1007110 */
  int_union ld0, ld3;
  int tmp;

  pActwk->YPOSI.w.h -= pActwk->Y_OFFSET; /* Line 2088, Address: 0x1007120 */

  ld3.w.h = 0; /* Line 2090, Address: 0x1007138 */
  ld3.w.l = sign(pActwk->SIN_CNT); /* Line 2091, Address: 0x100713c */
  ld0.w.h = 0; /* Line 2092, Address: 0x1007150 */
  ld0.w.l = pActwk->Y_WIDE; /* Line 2093, Address: 0x1007154 */
  tmp = 0; /* Line 2094, Address: 0x1007160 */
  tmp = ld3.w.l * ld0.w.l; /* Line 2095, Address: 0x1007164 */
  ld3.l = tmp; /* Line 2096, Address: 0x1007180 */
  ld3.l >>= 8; /* Line 2097, Address: 0x1007184 */
  pActwk->Y_OFFSET = ld3.w.l; /* Line 2098, Address: 0x1007190 */
  pActwk->YPOSI.w.h += ld3.w.l; /* Line 2099, Address: 0x100719c */

  ld0.l = random(); /* Line 2101, Address: 0x10071b0 */
  ld0.l &= 32767; /* Line 2102, Address: 0x10071bc */
  ld0.w.l = (int)ld0.w.l % pActwk->X_WIDE; /* Line 2103, Address: 0x10071c8 */
  pActwk->SIN_CNT += ld0.w.l; /* Line 2104, Address: 0x1007204 */
  if (pActwk->SIN_CNT >= 511) /* Line 2105, Address: 0x1007218 */
  {
    pActwk->SIN_CNT -= 511; /* Line 2107, Address: 0x1007234 */
  }
  pActwk->XPOSI.l += pActwk->X_SPEED.l; /* Line 2109, Address: 0x1007244 */

  pActwk->YPOSI.l += pActwk->Y_SPEED.l; /* Line 2111, Address: 0x100725c */
} /* Line 2112, Address: 0x1007274 */




static void sinvmove(sprite_status_thanks* pActwk) { /* Line 2117, Address: 0x1007290 */
  int_union ld0, ld3;

  pActwk->XPOSI.w.h -= pActwk->X_OFFSET; /* Line 2120, Address: 0x100729c */

  ld3.l = sign(pActwk->SIN_CNT); /* Line 2122, Address: 0x10072b4 */
  ld0.l = pActwk->X_WIDE; /* Line 2123, Address: 0x10072d0 */
  ld3.l *= ld0.l; /* Line 2124, Address: 0x10072e4 */
  ld3.l >>= 8; /* Line 2125, Address: 0x10072f4 */
  pActwk->X_OFFSET = ld3.w.l; /* Line 2126, Address: 0x1007300 */
  pActwk->XPOSI.w.h += ld3.w.l; /* Line 2127, Address: 0x100730c */

  ld0.l = random(); /* Line 2129, Address: 0x1007320 */
  ld0.l &= 32767; /* Line 2130, Address: 0x100732c */
  ld0.w.l = (int)ld0.w.l % pActwk->Y_WIDE; /* Line 2131, Address: 0x1007338 */
  pActwk->SIN_CNT += ld0.w.l; /* Line 2132, Address: 0x1007374 */
  if (pActwk->SIN_CNT >= 511) /* Line 2133, Address: 0x1007388 */
  {
    pActwk->SIN_CNT -= 511; /* Line 2135, Address: 0x10073a4 */
  }
  pActwk->XPOSI.l += pActwk->X_SPEED.l; /* Line 2137, Address: 0x10073b4 */

  pActwk->YPOSI.l += pActwk->Y_SPEED.l; /* Line 2139, Address: 0x10073cc */
} /* Line 2140, Address: 0x10073e4 */




static void hbt_move(sprite_status_thanks* pActwk) { /* Line 2145, Address: 0x1007400 */
  pActwk->XPOSI.l += pActwk->X_SPEED.l + pActwk->X_ACCEL.l; /* Line 2146, Address: 0x1007408 */
  pActwk->YPOSI.l += pActwk->Y_SPEED.l + pActwk->Y_ACCEL.l; /* Line 2147, Address: 0x100742c */
  pActwk->X_ACCEL.l += pActwk->X_OFFSET; /* Line 2148, Address: 0x1007450 */
  pActwk->Y_ACCEL.l += pActwk->Y_OFFSET; /* Line 2149, Address: 0x1007470 */
} /* Line 2150, Address: 0x1007490 */






static short chk_sonicposi(sprite_status_thanks* pActwk, sprite_status_thanks* pA6, short* d5, short* d6) { /* Line 2157, Address: 0x10074a0 */
  *d5 = pA6->XPOSI.w.h; /* Line 2158, Address: 0x10074b4 */
  *d5 -= pActwk->XPOSI.w.h; /* Line 2159, Address: 0x10074c4 */
  if (*d5 < 0) /* Line 2160, Address: 0x10074e0 */
  {
    *d5 *= -1; /* Line 2162, Address: 0x10074f8 */
    *d6 = 1; /* Line 2163, Address: 0x100750c */
    return -1; /* Line 2164, Address: 0x1007518 */
  }
  else
  {
    *d6 = 0; /* Line 2168, Address: 0x1007524 */
    return 0; /* Line 2169, Address: 0x100752c */
  }
} /* Line 2171, Address: 0x1007530 */




static short myposichk(sprite_status_thanks* pActwk) { /* Line 2176, Address: 0x1007540 */
  if (pActwk->XPOSI.w.h == 384) return -1; /* Line 2177, Address: 0x1007548 */
  if(pActwk->X_SPEED.w.h >= 0) /* Line 2178, Address: 0x1007570 */
  {
    if (pActwk->XPOSI.w.h < 264) return 0; /* Line 2180, Address: 0x1007588 */
    if (pActwk->XPOSI.w.h < 304) return -1; /* Line 2181, Address: 0x10075b0 */
    if (pActwk->XPOSI.w.h < 448) return 0; /* Line 2182, Address: 0x10075d8 */
    if (pActwk->XPOSI.w.h < 496) return -1; /* Line 2183, Address: 0x1007600 */
    return 0; /* Line 2184, Address: 0x1007628 */
  }
  else
  {
    if (pActwk->XPOSI.w.h < 40) return -1; /* Line 2188, Address: 0x1007634 */
    if (pActwk->XPOSI.w.h < 304) return 0; /* Line 2189, Address: 0x100765c */
    if (pActwk->XPOSI.w.h < 352) return -1; /* Line 2190, Address: 0x1007684 */
    if (pActwk->XPOSI.w.h > 496) return -1; /* Line 2191, Address: 0x10076ac */
    return 0; /* Line 2192, Address: 0x10076d4 */
  }
} /* Line 2194, Address: 0x10076d8 */




static short centerchk(sprite_status_thanks* pActwk) { /* Line 2199, Address: 0x10076f0 */
  pActwk->XPOSI.l &= 33554431; /* Line 2200, Address: 0x10076f8 */

  if (!(pActwk->SPR_FLG & 128)) /* Line 2202, Address: 0x100770c */
  {
    if (pActwk->XPOSI.w.h < 112) return 0; /* Line 2204, Address: 0x1007724 */
    if (pActwk->XPOSI.w.h > 120) return 0; /* Line 2205, Address: 0x100774c */
    return -1; /* Line 2206, Address: 0x1007774 */
  }
  else
  {
    if (pActwk->XPOSI.w.h < 168) return 0; /* Line 2210, Address: 0x1007780 */
    if (pActwk->XPOSI.w.h > 176) return 0; /* Line 2211, Address: 0x10077a8 */
    return -1; /* Line 2212, Address: 0x10077d0 */
  }
} /* Line 2214, Address: 0x10077d4 */




static short dsplaychk(sprite_status_thanks* pActwk) { /* Line 2219, Address: 0x10077e0 */
  pActwk->XPOSI.l &= 33554431; /* Line 2220, Address: 0x10077e8 */
  if (pActwk->XPOSI.w.h <= 304) return 0; /* Line 2221, Address: 0x10077fc */
  return -1; /* Line 2222, Address: 0x1007824 */
} /* Line 2223, Address: 0x1007828 */




static void waitmode(sprite_status_thanks* pActwk) { /* Line 2228, Address: 0x1007840 */
  hbt_move(pActwk); /* Line 2229, Address: 0x100784c */
  pActwk->XPOSI.w.h &= 511; /* Line 2230, Address: 0x1007858 */
  if (pActwk->XPOSI.w.h >= 336) /* Line 2231, Address: 0x1007868 */
  {
    if (pActwk->XPOSI.w.h <= 352) /* Line 2233, Address: 0x1007884 */
    {
      pActwk->X_SPEED.l = 0; /* Line 2235, Address: 0x10078a0 */
      pActwk->Y_SPEED.l = 0; /* Line 2236, Address: 0x10078a8 */
      pActwk->X_OFFSET = 0; /* Line 2237, Address: 0x10078b0 */
      pActwk->X_ACCEL.l = 0; /* Line 2238, Address: 0x10078b8 */
      pActwk->Y_OFFSET = 0; /* Line 2239, Address: 0x10078c0 */
      pActwk->Y_ACCEL.l = 0; /* Line 2240, Address: 0x10078c8 */
    }
  }
  if (!(pActwk->SPR_FLG & 4)) /* Line 2243, Address: 0x10078d0 */
  {
    pActwk->SPR_FLG &= 251; /* Line 2245, Address: 0x10078e8 */
    pActwk->EXE_NO = 1; /* Line 2246, Address: 0x10078f8 */
  }
} /* Line 2248, Address: 0x1007904 */




static void escape_chk(sprite_status_thanks* pActwk) { /* Line 2253, Address: 0x1007920 */
  pActwk->XPOSI.w.h &= 511; /* Line 2254, Address: 0x1007928 */
  if (pActwk->X_SPEED.l >= 0) /* Line 2255, Address: 0x1007938 */
  {
    if (pActwk->XPOSI.w.h >= 304) /* Line 2257, Address: 0x1007948 */
    {
      if (pActwk->XPOSI.w.h <= 368) /* Line 2259, Address: 0x1007964 */
      {
        pActwk->SPR_FLG |= 16; /* Line 2261, Address: 0x1007980 */
        return; /* Line 2262, Address: 0x1007990 */
      }
    }
  }
  else
  {
    if (pActwk->XPOSI.w.h >= 448) /* Line 2268, Address: 0x1007998 */
    {
      if (pActwk->XPOSI.w.h <= 480) /* Line 2270, Address: 0x10079b4 */
      {
        pActwk->SPR_FLG |= 16; /* Line 2272, Address: 0x10079d0 */
        return; /* Line 2273, Address: 0x10079e0 */
      }
    }
  }
  pActwk->XPOSI.l += pActwk->X_SPEED.l; /* Line 2277, Address: 0x10079e8 */
  pActwk->YPOSI.l += pActwk->Y_SPEED.l; /* Line 2278, Address: 0x1007a00 */
} /* Line 2279, Address: 0x1007a18 */




static void pit_in(sprite_status_thanks* pActwk) { /* Line 2284, Address: 0x1007a30 */
  pActwk->XPOSI.w.h = 390; /* Line 2285, Address: 0x1007a38 */
  if (((short*)pActwk)[31] < 2) /* Line 2286, Address: 0x1007a44 */
  {
    --((short*)pActwk)[31]; /* Line 2288, Address: 0x1007a60 */
    if (pActwk->X_SPEED.l >= 0) /* Line 2289, Address: 0x1007a70 */
    {
      pActwk->XPOSI.w.h = 400; /* Line 2291, Address: 0x1007a80 */
    } /* Line 2292, Address: 0x1007a8c */
    else
    {
      pActwk->XPOSI.w.h = 368; /* Line 2295, Address: 0x1007a94 */
    }
    pActwk->EXE_NO = 2; /* Line 2297, Address: 0x1007aa0 */
  } /* Line 2298, Address: 0x1007aac */
  else
  {
    --((short*)pActwk)[31]; /* Line 2301, Address: 0x1007ab4 */
  }
} /* Line 2303, Address: 0x1007ac4 */




static void m_sndchk(sprite_status_thanks* pActwk) { /* Line 2308, Address: 0x1007ad0 */
  if (pActwk->free[2]) return; /* Line 2309, Address: 0x1007ad8 */
  if (pActwk->X_SPEED.l >= 0) /* Line 2310, Address: 0x1007ae8 */
  {
    if (pActwk->XPOSI.w.h >= 6) return; /* Line 2312, Address: 0x1007af8 */
    pActwk->free[2] = 1; /* Line 2313, Address: 0x1007b14 */
  } /* Line 2314, Address: 0x1007b20 */
  else
  {
    if (pActwk->XPOSI.w.h < 304) return; /* Line 2317, Address: 0x1007b28 */
    if (pActwk->XPOSI.w.h > 312) return; /* Line 2318, Address: 0x1007b44 */
    pActwk->free[2] = 1; /* Line 2319, Address: 0x1007b60 */
  }
} /* Line 2321, Address: 0x1007b6c */
