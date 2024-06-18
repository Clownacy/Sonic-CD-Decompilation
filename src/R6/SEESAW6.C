#include "..\EQU.H"
#include "SEESAW6.H"
#include "..\ACTION.H"
#include "..\ACTSET.H"
#include "..\DIRCOL.H"
#include "..\PLAYSUB.H"
#include "..\RIDECHK.H"

void(*seesaw6_tbl[3])(sprite_status*) = {
  &m_init,
  &m_move,
  &m_up
};
unsigned char seesaw_pat_00[4] = { 2, 0, 1, 255 };
unsigned char seesaw_pat_01[5] = { 2, 1, 2, 3, 255 };
unsigned char seesaw_pat_02[4] = { 2, 2, 3, 255 };
unsigned char seesaw_pat_03[4] = { 2, 4, 5, 255 };
unsigned char seesaw_pat_04[6] = { 2, 4, 5, 6, 7, 255 };
unsigned char seesaw_pat_05[4] = { 2, 6, 7, 255 };
unsigned char* seesaw_pchg[6] =
{
  seesaw_pat_00,
  seesaw_pat_01,
  seesaw_pat_02,
  seesaw_pat_03,
  seesaw_pat_04,
  seesaw_pat_05
};
sprite_pattern seesawPat00 = { 1, { { -24, -24, 0, 450 } } };
sprite_pattern seesawPat01 = { 1, { { -24, -24, 0, 451 } } };
sprite_pattern seesawPat02 = { 1, { { -24, -24, 0, 452 } } };
sprite_pattern seesawPat03 = { 1, { { -24, -24, 0, 453 } } };
sprite_pattern seesawPat04 = { 1, { { -24, -24, 0, 454 } } };
sprite_pattern seesawPat05 = { 1, { { -24, -24, 0, 455 } } };
sprite_pattern seesawPat06 = { 1, { { -24, -24, 0, 456 } } };
sprite_pattern seesawPat07 = { 1, { { -24, -24, 0, 457 } } };
sprite_pattern seesawPat08 = { 1, { { -24, -8, 0, 458 } } };
sprite_pattern seesawPat09 = { 1, { { -16, -7, 0, 459 } } };
sprite_pattern* pat_seesaw6[10] = {
  &seesawPat00,
  &seesawPat01,
  &seesawPat02,
  &seesawPat03,
  &seesawPat04,
  &seesawPat05,
  &seesawPat06,
  &seesawPat07,
  &seesawPat08,
  &seesawPat09
};













void seesaw6(sprite_status* pActwk) { /* Line 64, Address: 0x101fed0 */
  if (pActwk->userflag.b.h != 0) /* Line 65, Address: 0x101fedc */
  {
    slave(pActwk); /* Line 67, Address: 0x101fef4 */
  } /* Line 68, Address: 0x101ff00 */
  else
  {

    seesaw6_tbl[pActwk->r_no0 / 2](pActwk); /* Line 72, Address: 0x101ff08 */
    actionsub(pActwk); /* Line 73, Address: 0x101ff4c */
    frameout_s(pActwk); /* Line 74, Address: 0x101ff58 */
  }
} /* Line 76, Address: 0x101ff64 */











void m_init(sprite_status* pActwk) { /* Line 88, Address: 0x101ff80 */
  sprite_status* pActfree;

  pActwk->r_no0 += 2; /* Line 91, Address: 0x101ff8c */
  pActwk->actflg |= 4; /* Line 92, Address: 0x101ff9c */
  pActwk->sprpri = 3; /* Line 93, Address: 0x101ffac */
  pActwk->sprhs = 24; /* Line 94, Address: 0x101ffb8 */
  pActwk->sprhsize = 24; /* Line 95, Address: 0x101ffc4 */
  pActwk->sprvsize = 24; /* Line 96, Address: 0x101ffd0 */
  pActwk->sproffset = 952; /* Line 97, Address: 0x101ffdc */
  pActwk->patbase = pat_seesaw6; /* Line 98, Address: 0x101ffe8 */

  if (actwkchk(&pActfree) != 0) /* Line 100, Address: 0x101fff8 */
  {
    frameout(pActwk); /* Line 102, Address: 0x102000c */
    return; /* Line 103, Address: 0x1020018 */
  }
  m_ini_s(pActwk, pActfree); /* Line 105, Address: 0x1020020 */

  ((unsigned short*)pActwk)[23] = pActfree - actwk; /* Line 107, Address: 0x1020030 */
  pActfree->xposi.w.h -= 40; /* Line 108, Address: 0x1020064 */
  pActfree->yposi.w.h -= 24; /* Line 109, Address: 0x1020074 */
  if (actwkchk(&pActfree) != 0) /* Line 110, Address: 0x1020084 */
  {
    frameout(pActwk); /* Line 112, Address: 0x1020098 */
    return; /* Line 113, Address: 0x10200a4 */
  }
  m_ini_s(pActwk, pActfree); /* Line 115, Address: 0x10200ac */

  ((unsigned short*)pActwk)[24] = pActfree - actwk; /* Line 117, Address: 0x10200bc */
  pActfree->xposi.w.h += 40; /* Line 118, Address: 0x10200f0 */
  pActfree->yposi.w.h += 24; /* Line 119, Address: 0x1020100 */
  pActfree->actflg |= 1; /* Line 120, Address: 0x1020110 */
  pActfree->cddat |= 1; /* Line 121, Address: 0x1020120 */
} /* Line 122, Address: 0x1020130 */











void m_ini_s(sprite_status* pActwk, sprite_status* pActfree) { /* Line 134, Address: 0x1020140 */
  pActfree->actno = pActwk->actno; /* Line 135, Address: 0x102014c */
  pActfree->actflg = pActwk->actflg; /* Line 136, Address: 0x102015c */
  pActfree->sprpri = pActwk->sprpri; /* Line 137, Address: 0x102016c */
  pActfree->sproffset = pActwk->sproffset; /* Line 138, Address: 0x102017c */
  pActfree->patbase = pActwk->patbase; /* Line 139, Address: 0x102018c */
  pActfree->xposi.w.h = pActwk->xposi.w.h; /* Line 140, Address: 0x102019c */
  pActfree->yposi.w.h = pActwk->yposi.w.h; /* Line 141, Address: 0x10201ac */
  pActfree->userflag.b.h = -1; /* Line 142, Address: 0x10201bc */
  pActfree->sprhs = 16; /* Line 143, Address: 0x10201c8 */
  pActfree->sprhsize = 16; /* Line 144, Address: 0x10201d4 */
  pActfree->sprvsize = 8; /* Line 145, Address: 0x10201e0 */
  pActfree->patno = 9; /* Line 146, Address: 0x10201ec */

  ((unsigned short*)pActfree)[23] = pActwk - actwk; /* Line 148, Address: 0x10201f8 */
  ((short*)pActwk)[25] = 120; /* Line 149, Address: 0x102022c */
} /* Line 150, Address: 0x1020238 */











void m_move(sprite_status* pActwk) { /* Line 162, Address: 0x1020250 */
  unsigned short wActwkNo;

  if (pActwk->yspeed.w == 0) /* Line 165, Address: 0x1020260 */
    m_stay(pActwk); /* Line 166, Address: 0x1020278 */
  else
    m_fall(pActwk); /* Line 168, Address: 0x102028c */

  wActwkNo = ((unsigned short*)pActwk)[24]; /* Line 170, Address: 0x1020298 */
  ridechk(&actwk[wActwkNo], &actwk[0]); /* Line 171, Address: 0x10202a4 */
  actionsub(&actwk[wActwkNo]); /* Line 172, Address: 0x10202d0 */

  wActwkNo = ((unsigned short*)pActwk)[23]; /* Line 174, Address: 0x10202f4 */
  if (ridechk(&actwk[wActwkNo], &actwk[0]) != 0) /* Line 175, Address: 0x1020300 */
    actwk[wActwkNo].actfree[21] = 255; /* Line 176, Address: 0x102033c */
  else
    actwk[wActwkNo].actfree[21] = 0; /* Line 178, Address: 0x1020368 */
  actionsub(&actwk[wActwkNo]); /* Line 179, Address: 0x1020388 */

  if (actwk[wActwkNo].actfree[21] == 0) /* Line 181, Address: 0x10203ac */
  {
    patchg(pActwk, seesaw_pchg); /* Line 183, Address: 0x10203d8 */
  } /* Line 184, Address: 0x10203ec */
  else
  {
    pActwk->r_no0 = 4; /* Line 187, Address: 0x10203f4 */
    ((short*)pActwk)[25] = 3; /* Line 188, Address: 0x1020400 */
    pActwk->patno = 8; /* Line 189, Address: 0x102040c */
  }
} /* Line 191, Address: 0x1020418 */















void m_stay(sprite_status* pActwk) { /* Line 207, Address: 0x1020430 */
  short iwk;

  iwk = ((short*)pActwk)[25]; /* Line 210, Address: 0x102043c */
  if (((short*)pActwk)[25] >= 0) /* Line 211, Address: 0x102044c */
  {

    --((short*)pActwk)[25]; /* Line 214, Address: 0x1020464 */
    if (((short*)pActwk)[25] < 0) /* Line 215, Address: 0x1020474 */
    {
      pActwk->yspeed.w = 256; /* Line 217, Address: 0x102048c */
    } /* Line 218, Address: 0x1020498 */
    else
    {
      if (((short*)pActwk)[25] != 60) return; /* Line 221, Address: 0x10204a0 */
    }

    ++pActwk->mstno.b.h; /* Line 224, Address: 0x10204bc */
  }
} /* Line 226, Address: 0x10204cc */











void m_fall(sprite_status* pActwk) { /* Line 238, Address: 0x10204e0 */
  sprite_status* pActSu;
  sprite_status* pActSd;
  unsigned short wYspd;
  short iD0, iD1;

  pActSu = &actwk[((unsigned short*)pActwk)[23]]; /* Line 244, Address: 0x1020500 */
  pActSd = &actwk[((unsigned short*)pActwk)[24]]; /* Line 245, Address: 0x1020524 */

  wYspd = pActwk->yspeed.b.h; /* Line 247, Address: 0x1020548 */
  pActwk->yposi.w.h += wYspd; /* Line 248, Address: 0x102055c */
  pActSu->yposi.w.h += wYspd; /* Line 249, Address: 0x1020574 */
  pActSd->yposi.w.h += wYspd; /* Line 250, Address: 0x1020588 */


  iD0 = pActSd->sprhsize; /* Line 253, Address: 0x102059c */
  if (pActSd->xposi.w.h >= pActwk->xposi.w.h) /* Line 254, Address: 0x10205ac */
    iD0 = -iD0; /* Line 255, Address: 0x10205d4 */

  iD0 += pActwk->xposi.w.h; /* Line 257, Address: 0x10205f0 */
  iD1 = emycol_d2(pActSd, iD0); /* Line 258, Address: 0x1020604 */
  if (iD1 > 0) return; /* Line 259, Address: 0x102061c */



  pActwk->yposi.w.h += iD1; /* Line 263, Address: 0x102062c */
  pActSu->yposi.w.h += iD1; /* Line 264, Address: 0x102063c */
  pActSd->yposi.w.h += iD1; /* Line 265, Address: 0x1020648 */
  pActwk->yspeed.w = 0; /* Line 266, Address: 0x1020654 */
} /* Line 267, Address: 0x102065c */











void m_up(sprite_status* pActwk) { /* Line 279, Address: 0x1020680 */
  sprite_status *pActSd, *pActSu;
  unsigned short wwk_u, wwk_d;
  pActSd = &actwk[((unsigned short*)pActwk)[24]]; /* Line 282, Address: 0x102069c */
  pActSd->yposi.w.h -= 24; /* Line 283, Address: 0x10206c0 */
  pActwk->yposi.w.h -= 12; /* Line 284, Address: 0x10206cc */
  --((short*)pActwk)[25]; /* Line 285, Address: 0x10206dc */
  if (((short*)pActwk)[25] < 0) /* Line 286, Address: 0x10206ec */
  {


    pActwk->r_no0 = 2; /* Line 290, Address: 0x1020704 */
    pActwk->yspeed.w = 0; /* Line 291, Address: 0x1020710 */
    ((short*)pActwk)[25] = 120; /* Line 292, Address: 0x1020718 */
    wwk_d = ((unsigned short*)pActwk)[24]; /* Line 293, Address: 0x1020724 */
    wwk_u = ((unsigned short*)pActwk)[23]; /* Line 294, Address: 0x1020730 */
    ((unsigned short*)pActwk)[24] = wwk_u; /* Line 295, Address: 0x102073c */
    ((unsigned short*)pActwk)[23] = wwk_d; /* Line 296, Address: 0x1020744 */
    if (pActwk->mstno.b.h > 2) pActwk->mstno.b.h = 0; /* Line 297, Address: 0x102074c */
    else pActwk->mstno.b.h = 3; /* Line 298, Address: 0x1020778 */
    pActwk->mstno.b.l = -1; /* Line 299, Address: 0x1020784 */
  }

  actionsub(pActSd); /* Line 302, Address: 0x1020790 */
  pActSu = &actwk[((unsigned short*)pActwk)[23]]; /* Line 303, Address: 0x102079c */
  actionsub(pActSu); /* Line 304, Address: 0x10207c0 */
} /* Line 305, Address: 0x10207cc */











void slave(sprite_status* pActwk) { /* Line 317, Address: 0x10207f0 */
  sprite_status* pActwk2;

  pActwk2 = &actwk[((unsigned short*)pActwk)[23]]; /* Line 320, Address: 0x1020800 */
  if (pActwk2->actno != 44) /* Line 321, Address: 0x1020824 */
    frameout(pActwk); /* Line 322, Address: 0x1020838 */
} /* Line 323, Address: 0x1020844 */
