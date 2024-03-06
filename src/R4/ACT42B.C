#include "..\EQU.H"
#include "ACT41A.H"
#include "..\GOAL.H"
#include "..\ITEM.H"
#include "..\PLAYER.H"
#include "..\RING.H"
#include "..\SCORE.H"
#include "..\SPRING.H"
#include "..\ZONE.H"
#include "AMENBO.H"
#include "AWA.H"
#include "ET4.H"
#include "FRIEND4.H"
#include "HARIR4.H"
#include "KUZURE4.H"
#include "MOVIE4.H"
#include "PLAYSUB4.H"
#include "RBLK4.H"
#include "SCREW_A.H"
#include "SW4.H"
#include "TAGAMEB4.H"
#include "TONBO.H"
#include "UDBLK4.H"
#include "WALL1.H"
#include "WALLS.H"
#include "YAGO.H"

void(*act_tbl[82])(sprite_status*) = {
  &play00,
  &play00,
  &baria,
  &wave,
  &bou,
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
  &awa,
  &plawa,
  &harir4,
  &udblk4,
  &noact,
  &noact,
  &noact,
  &sw4,
  &noact,
  &noact,
  &noact,
  &tonbo,
  &amenbo,
  &tagameb,
  &yago,
  &friend4,
  &noact,
  &noact,
  &noact,
  &walls,
  &wall1,
  &screw,
  &noact,
  &noact,
  &noact,
  &kuzure4,
  &clear,
  &over,
  &title,
  &rblk4,
  &noact,
  &noact,
  &noact,
  &noact,
  &noact,
  &noact,
  &noact,
  &noact,
  &noact,
  &noact,
  &noact,
  &noact,
  &noact,
  &noact,
  &noact,
  &noact,
  &noact,
  &noact,
  &noact,
  &et,
  &movie4
};

































































void debugact(sprite_status* pActwk) { /* Line 177, Address: 0x1008ef0 */
  if (pActwk->xposi.w.h++ >= 300) /* Line 178, Address: 0x1008efc */
    pActwk->xposi.w.h = 0; /* Line 179, Address: 0x1008f20 */
  if (pActwk->yposi.w.h++ >= 200) /* Line 180, Address: 0x1008f28 */
    pActwk->yposi.w.h = 0; /* Line 181, Address: 0x1008f4c */

  actionsub(pActwk); /* Line 183, Address: 0x1008f54 */
} /* Line 184, Address: 0x1008f60 */




void noact(sprite_status* pActwk) { /* Line 189, Address: 0x1008f70 */
  frameout(pActwk); /* Line 190, Address: 0x1008f7c */
} /* Line 191, Address: 0x1008f88 */
