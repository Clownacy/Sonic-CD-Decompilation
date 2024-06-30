#include "..\EQU.H"
#include "ACT71A.H"
#include "..\ACTION.H"
#include "..\GOAL.H"
#include "..\ITEM.H"
#include "..\RING.H"
#include "..\PLAYER.H"
#include "..\PLAYSUB.H"
#include "..\SCORE.H"
#include "..\SPRING.H"
#include "..\ZONE.H"
#include "BRANKO7.H"
#include "CHGBAN.H"
#include "CHGWALL7.H"
#include "DANGO7.H"
#include "ET7.H"
#include "FRIEND7.H"
#include "HOTARU7.H"
#include "KABASIRA.H"
#include "KANABUN.H"
#include "MOVIE7.H"
#include "SLIGHT7.H"
#include "TEKKYU7.H"
#include "TEKKYU7J.H"
#include "WALL7.H"

void(*act_tbl[60])(sprite_status*) = {
  &play00,
  &play00,
  &baria,
  &ami,
  &noact,
  &test_act,
  &noact,
  &gun7,
  &hibana,
  &spring,
  &exit2,
  &exit2_set,
  &futa,
  &mizukiri,
  &koma,
  &ring,
  &flyring,
  &noact,
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
  &chgban,
  &spring_r,
  &flower,
  &branko7,
  &kanabun,
  &kabasira,
  &hotaru7,
  &wall7,
  &tekkyu7,
  &tekkyu7j,
  &movie,
  &friend,
  &et,
  &dango,
  &ball,
  &noact,
  &noact,
  &noact,
  &noact,
  &noact,
  &noact,
  &noact,
  &noact,
  &noact,
  &chgwall7,
  &noact,
  &noact,
  &slight7,
  &noact,
  &clear,
  &over,
  &title
};






















































void debugact(sprite_status* pActwk) { /* Line 143, Address: 0x101a320 */
  if (pActwk->xposi.w.h++ >= 300) /* Line 144, Address: 0x101a32c */
    pActwk->xposi.w.h = 0; /* Line 145, Address: 0x101a350 */
  if (pActwk->yposi.w.h++ >= 200) /* Line 146, Address: 0x101a358 */
    pActwk->yposi.w.h = 0; /* Line 147, Address: 0x101a37c */

  actionsub(pActwk); /* Line 149, Address: 0x101a384 */
} /* Line 150, Address: 0x101a390 */




void noact(sprite_status* pActwk) { /* Line 155, Address: 0x101a3a0 */
  frameout(pActwk); /* Line 156, Address: 0x101a3ac */
} /* Line 157, Address: 0x101a3b8 */
