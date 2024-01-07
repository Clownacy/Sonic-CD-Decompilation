#include "..\EQU.H"
#include "ACT11A.H"
#include "..\ACTION.H"
#include "..\BLOCK.H"
#include "..\BRANKO1.H"
#include "..\DAI_K.H"
#include "..\DAI_RD1.H"
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
#include "..\ZONE.H"
#include "FRIEND1.H"
#include "KOWASI1.H"
#include "KUZURE.H"
#include "MOVIE1.H"
#include "SHOOT1.H"
#include "SIKAKE.H"

void(*act_tbl[64])(sprite_status*) = {
  &play00,
  &play00,
  &baria,
  &taki,
  &jisin,
  &test_act,
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
  &ene_tama,
  &friend,
  &noact,
  &hariyama,
  &noact,
  &tobita1,
  &branko1,
  &noact,
  &noact,
  &noact,
  &et,
  &movie1,
  &noact,
  &noact,
  &noact,
  &eda,
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










































































void debugact(sprite_status* pActwk) { /* Line 166, Address: 0x1023ed0 */
  if (pActwk->xposi.w.h++ >= 300) /* Line 167, Address: 0x1023edc */
    pActwk->xposi.w.h = 0; /* Line 168, Address: 0x1023f00 */
  if (pActwk->yposi.w.h++ >= 200) /* Line 169, Address: 0x1023f08 */
    pActwk->yposi.w.h = 0; /* Line 170, Address: 0x1023f2c */

  actionsub(pActwk); /* Line 172, Address: 0x1023f34 */
} /* Line 173, Address: 0x1023f40 */




void noact(sprite_status* pActwk) { /* Line 178, Address: 0x1023f50 */
  frameout(pActwk); /* Line 179, Address: 0x1023f5c */
} /* Line 180, Address: 0x1023f68 */
