#include "..\EQU.H"
#include "ACT71A.H"
#include "..\ACTION.H"
#include "..\GOAL.H"
#include "..\ITEM.H"
#include "..\PLAYER.H"
#include "..\PLAYSUB.H"
#include "..\RING.H"
#include "..\SCORE.H"
#include "..\SPRING.H"
#include "..\ZONE.H"
#include "BOSS_7.H"
#include "BRANKO7.H"
#include "CHGBAN.H"
#include "CHGWALL7.H"
#include "EMIE7.H"
#include "FRIEND7.H"
#include "GAITOU73.H"
#include "HARI73.H"
#include "MOVIE7.H"
#include "TEKKYU7.H"
#include "TEKKYU7J.H"
#include "WALL7.H"
#include "WALL73.H"

void(*act_tbl[60])(sprite_status*) = {
  &play00,
  &play00,
  &baria,
  &ami,
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
  &branko7,
  &noact,
  &noact,
  &noact,
  &wall7,
  &tekkyu7,
  &tekkyu7j,
  &movie,
  &friend,
  &noact,
  &noact,
  &wall73,
  &egg7,
  &egg7jet,
  &egg7beam,
  &msnc,
  &msnc_ele,
  &msnc_bara,
  &hari73,
  &emie7,
  &heart7,
  &chgwall7,
  &gaitou73,
  &hahen73,
  &noact,
  &noact,
  &clear,
  &over,
  &title
};























































void debugact(sprite_status* pActwk) { /* Line 143, Address: 0x1021eb0 */
  if (pActwk->xposi.w.h++ >= 300) /* Line 144, Address: 0x1021ebc */
    pActwk->xposi.w.h = 0; /* Line 145, Address: 0x1021ee0 */
  if (pActwk->yposi.w.h++ >= 200) /* Line 146, Address: 0x1021ee8 */
    pActwk->yposi.w.h = 0; /* Line 147, Address: 0x1021f0c */

  actionsub(pActwk); /* Line 149, Address: 0x1021f14 */
} /* Line 150, Address: 0x1021f20 */




void noact(sprite_status* pActwk) { /* Line 155, Address: 0x1021f30 */
  frameout(pActwk); /* Line 156, Address: 0x1021f3c */
} /* Line 157, Address: 0x1021f48 */
