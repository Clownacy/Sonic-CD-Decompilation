#include "..\EQU.H"
#include "ACT11A.H"
#include "..\ACTION.H"
#include "..\BLOCK.H"
#include "..\DAI_K.H"
#include "..\DAI_RD1.H"
#include "..\EMIE1.H"
#include "..\ENEMY.H"
#include "..\ET1.H"
#include "..\GOAL.H"
#include "..\ITEM.H"
#include "..\PLAYER.H"
#include "..\PLAYSUB.H"
#include "..\RING.H"
#include "..\SCORE.H"
#include "..\SPRING.H"
#include "..\TAKI.H"
#include "..\TREE.H"
#include "..\ZONE.H"
#include "FRIEND1.H"
#include "KOWASI1.H"
#include "KUZURE.H"
#include "MOVIE1.H"
#include "SHOOT1.H"
#include "SIKAKE.H"

void(*act_tbl[64])(act_info*) = {
  &play00,
  &play00,
  &baria,
  &taki,
  &jisin,
  &noact,
  &shooter,
  &jisin_set,
  &dai_k,
  &spring,
  &exit2,
  &exit2_set,
  &futa,
  &mizukiri,
  &koma,
  &ring,
  &flyring,
  &block,
  &marker,
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
  &kuzureru_tikei,
  &dodai,
  &ene_kamemusi,
  (void(*)(act_info*))&ene_tama,
  &friend,
  &noact,
  &hariyama,
  &noact,
  &tobita1,
  &noact,
  &kasoku,
  &noact,
  &hoshi,
  &et,
  &movie1,
  &emie1,
  &heart1,
  &ana,
  &noact,
  &kage,
  &ball,
  &vfuta,
  &kowasi,
  &noact,
  &noact,
  &noact,
  &clear,
  &over,
  &title,
  &ene_ka,
  &ene_chou,
  &ene_ari,
  &ene_tagame_a
};


























































void debugact(act_info* pAct) { /* Line 151, Address: 0x1021440 */
  if (pAct->xposi.w.h++ >= 300) pAct->xposi.w.h = 0; /* Line 152, Address: 0x102144c */
  if (pAct->yposi.w.h++ >= 200) pAct->yposi.w.h = 0; /* Line 153, Address: 0x1021478 */

  actionsub(pAct); /* Line 155, Address: 0x10214a4 */
} /* Line 156, Address: 0x10214b0 */




void noact(act_info* pAct) { /* Line 161, Address: 0x10214c0 */
  frameout(pAct); /* Line 162, Address: 0x10214cc */
} /* Line 163, Address: 0x10214d8 */
