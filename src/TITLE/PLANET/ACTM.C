#include "..\..\TYPES.H"
#include "LPL_TYPES.H"
#include "SPM_EQU.H"
#include "ACTM.H"
#include "CHAMOV.H"
#include "ASCIISET.H"

void actloop(sprite_status_lpl* pActwk);
void priact(sprite_status_lpl* pActwk, int ActNo);
void dummy(sprite_status_lpl* pActwk);
void pattern_chg(sprite_status_lpl* pActwk, sprite_patterns_title* pPatTbl);

static void(*act_tbl[31])(sprite_status_lpl*) =
{
  &flicky_ctrl,
  &star_ctrl,
  &eggm_ctrl,
  &ufo_ctrl,
  &msnc_ctrl,
  &tails_ctrl,
  &ascii_sprite,
  &dummy, &dummy,
  &dummy, &dummy,
  &dummy, &dummy,
  &dummy, &dummy,
  &dummy, &dummy,
  &dummy, &dummy,
  &dummy, &dummy,
  &dummy, &dummy,
  &dummy, &dummy,
  &dummy, &dummy,
  &dummy, &dummy,
  &dummy, &dummy
};
extern void(*EAsprset)(short, short, unsigned short, unsigned short, unsigned short);
static unsigned short LinkData;
extern void(*sMemSet)(void*, unsigned char, int);








int get_actwk(sprite_status_lpl** ppFreeAct) { /* Line 46, Address: 0x1000000 */
  int i;
  sprite_status_lpl* pChkAct;

  i = 15; /* Line 50, Address: 0x1000010 */
  pChkAct = actwk; /* Line 51, Address: 0x1000014 */
  do
  {
    if (pChkAct->ACT_NO == 0) /* Line 54, Address: 0x100001c */
    {
      *ppFreeAct = pChkAct; /* Line 56, Address: 0x100002c */
      return 0; /* Line 57, Address: 0x1000034 */
    }
    ++pChkAct; /* Line 59, Address: 0x1000040 */
  } while (--i >= 0); /* Line 60, Address: 0x1000044 */
  return -1; /* Line 61, Address: 0x1000050 */
} /* Line 62, Address: 0x1000054 */






int chk_actwk() { /* Line 69, Address: 0x1000070 */
  int i;
  sprite_status_lpl* pChkAct;

  i = 15; /* Line 73, Address: 0x100007c */
  pChkAct = actwk; /* Line 74, Address: 0x1000080 */
  do
  {
    if (pChkAct->ACT_NO != 0) return -1; /* Line 77, Address: 0x1000088 */
    ++pChkAct; /* Line 78, Address: 0x10000a4 */
  } while (--i >= 0); /* Line 79, Address: 0x10000a8 */
  return 0; /* Line 80, Address: 0x10000b4 */
} /* Line 81, Address: 0x10000b8 */














































void action() { /* Line 128, Address: 0x10000d0 */
  unsigned short i;

  sprinit(); /* Line 131, Address: 0x10000dc */

  actloop(actwk); /* Line 133, Address: 0x10000e4 */

  spr_set(); /* Line 135, Address: 0x10000f4 */
  for (i = LinkData; i < 80; ++i) EAsprset(0, 0, 0, i, 0); /* Line 136, Address: 0x10000fc */

} /* Line 138, Address: 0x100014c */

static void actloop(sprite_status_lpl* pActwk) { /* Line 140, Address: 0x1000160 */
  int i, ActNo;

  i = 15; /* Line 143, Address: 0x1000174 */
  do
  {
    if (ActNo = pActwk->ACT_NO, ActNo != 0) priact(pActwk, ActNo); /* Line 146, Address: 0x1000178 */
    ++pActwk; /* Line 147, Address: 0x100019c */
  } while (--i >= 0); /* Line 148, Address: 0x10001a8 */

} /* Line 150, Address: 0x10001b4 */

static void priact(sprite_status_lpl* pActwk, int ActNo) { /* Line 152, Address: 0x10001d0 */
  act_tbl[ActNo - 1](pActwk); /* Line 153, Address: 0x10001e0 */
  if (pActwk->SPR_FLG & 16) sMemSet(pActwk, 0, sizeof(*pActwk)); /* Line 154, Address: 0x1000208 */

} /* Line 156, Address: 0x100023c */

static void dummy(sprite_status_lpl* pActwk) { /* Line 158, Address: 0x1000250 */
  actset_flg ^= pActwk->ACT_FLG; /* Line 159, Address: 0x1000258 */
  pActwk->SPR_FLG |= 16; /* Line 160, Address: 0x1000274 */

} /* Line 162, Address: 0x1000284 */







void spr_set() { /* Line 170, Address: 0x1000290 */
  int i, j;
  sprite_status_lpl* pActwk;
  sprite_patterns_title* pPatTbl;
  sprite_pattern_mapping_title* pMapDat;
  short xpos, ypos;
  unsigned short RevFlg;

  pActwk = actwk; /* Line 178, Address: 0x10002b8 */
  LinkData = 0; /* Line 179, Address: 0x10002c0 */
  for (i = 15; i >= 0 && LinkData < 80; --i, ++pActwk) /* Line 180, Address: 0x10002c8 */
  {
    if (pActwk->ACT_NO == 0) continue; /* Line 182, Address: 0x10002d4 */
    if (pPatTbl = pActwk->PAT_ADR, pPatTbl == 0) continue; /* Line 183, Address: 0x10002e4 */
    pattern_chg(pActwk, pPatTbl); /* Line 184, Address: 0x10002f0 */
    j = pPatTbl->aPatDat[pActwk->PAT_NO].paMapTbl->mapnum; /* Line 185, Address: 0x1000300 */
    pMapDat = pPatTbl->aPatDat[pActwk->PAT_NO].paMapTbl->aMapDat; /* Line 186, Address: 0x1000324 */
    for (--j; j >= 0; --j, ++pMapDat) /* Line 187, Address: 0x1000340 */
    {
      RevFlg = 0; /* Line 189, Address: 0x100034c */
      xpos = pActwk->XPOSI.w.h; /* Line 190, Address: 0x1000350 */
      if (pActwk->SPR_FLG & 128) /* Line 191, Address: 0x100035c */
      {
        RevFlg |= 1; /* Line 193, Address: 0x1000370 */
        xpos -= pMapDat->hrevoffs; /* Line 194, Address: 0x1000378 */
      } /* Line 195, Address: 0x1000388 */
      else
      {
        xpos -= pMapDat->hoffs; /* Line 198, Address: 0x1000390 */
      }
      ypos = pActwk->YPOSI.w.h; /* Line 200, Address: 0x10003a0 */
      if (pActwk->SPR_FLG & 64) /* Line 201, Address: 0x10003ac */
      {
        RevFlg |= 2; /* Line 203, Address: 0x10003c0 */
        ypos -= pMapDat->vrevoffs; /* Line 204, Address: 0x10003c8 */
      } /* Line 205, Address: 0x10003d8 */
      else
      {
        ypos -= pMapDat->voffs; /* Line 208, Address: 0x10003e0 */
      }
      RevFlg ^= pMapDat->etc; /* Line 210, Address: 0x10003f0 */
      if (pActwk->SPR_FLG & 32) RevFlg |= 32768; /* Line 211, Address: 0x1000400 */
      EAsprset(xpos + 128, ypos + 128, pMapDat->index, LinkData, RevFlg); /* Line 212, Address: 0x100041c */
      if (++LinkData >= 80) break; /* Line 213, Address: 0x1000468 */
    } /* Line 214, Address: 0x1000490 */
  } /* Line 215, Address: 0x10004a0 */
} /* Line 216, Address: 0x10004c8 */







static void pattern_chg(sprite_status_lpl* pActwk, sprite_patterns_title* pPatTbl) { /* Line 224, Address: 0x1000500 */
  short PatNoWk;

  if (--pActwk->SPR_TIMER < 0) /* Line 227, Address: 0x1000510 */
  {
    if ((PatNoWk = pActwk->PAT_NO + 1) >= pPatTbl->patnum) PatNoWk = 0; /* Line 229, Address: 0x1000538 */
    pActwk->PAT_NO = PatNoWk; /* Line 230, Address: 0x100058c */
    pActwk->SPR_TIMER = pPatTbl->aPatDat[PatNoWk].timer; /* Line 231, Address: 0x1000594 */
  }

} /* Line 234, Address: 0x10005b4 */
