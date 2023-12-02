#include "..\EQU.H"
#include "ACT11A.H"
#include "..\DAI_RD1.H"
#include "..\ENEMY.H"
#include "..\GOAL.H"
#include "..\ITEM.H"
#include "..\PLAYER.H"
#include "..\PLAYSUB.H"
#include "..\RING.H"
#include "..\SCORE.H"
#include "..\SPRING.H"
#include "..\ZONE.H"
#include "BOSS_1.H"
#include "FRIEND1.H"
#include "SIKAKE.H"

void(*act_tbl[64])(act_info*) = {
  &play00,
  &play00,
  &baria,
  &noact,
  &noact,
  &test_act,
  &noact,
  &noact,
  &noact,
  &spring,
  &exit2,
  &exit2_set,
  &futa,
  &mizukiri,
  &koma,
  &ring,
  &flyring,
  &noact,
  &noact,
  &bigring,
  &gene,
  &mosugu,
  &goal,
  &bakuha,
  &item,
  &item2,
  &iwa,
  &score,
  &noact,
  &noact,
  &flower,
  &noact,
  &dodai,
  &ene_kamemusi,
  &ene_tama,
  &friend,
  &noact,
  &hariyama,
  &noact,
  &tobita1,
  &noact,
  &egg1,
  &egg1body,
  &egg1leg1,
  &egg1leg2,
  &egg1leg3,
  &egg1arm1,
  &egg1arm2,
  &egg1arm3,
  &egg1arm4,
  &noact,
  &ball,
  &noact,
  &noact,
  &noact,
  &noact,
  &noact,
  &clear,
  &over,
  &title,
  &ene_ka,
  &ene_chou,
  &ene_ari,
  &ene_tagame_a,
};




















































































void debugact(act_info* pActwk) { /* Line 167, Address: 0x10231f0 */
  if (pActwk->xposi.w.h++ >= 300) /* Line 168, Address: 0x10231fc */
    pActwk->xposi.w.h = 0; /* Line 169, Address: 0x1023220 */
  if (pActwk->yposi.w.h++ >= 200) /* Line 170, Address: 0x1023228 */
    pActwk->yposi.w.h = 0; /* Line 171, Address: 0x102324c */

  actionsub(pActwk); /* Line 173, Address: 0x1023254 */
} /* Line 174, Address: 0x1023260 */




void noact(act_info* pActwk) { /* Line 179, Address: 0x1023270 */
  frameout(pActwk); /* Line 180, Address: 0x102327c */
} /* Line 181, Address: 0x1023288 */
