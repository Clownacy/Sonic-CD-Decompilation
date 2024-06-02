#include "..\EQU.H"
#include "ACT41A.H"
#include "..\ACTION.H"
#include "..\GOAL.H"
#include "..\ITEM.H"
#include "..\PLAYER.H"
#include "..\RING.H"
#include "..\SCORE.H"
#include "..\SPRING.H"
#include "..\ZONE.H"
#include "AMENBO.H"
#include "AWA.H"
#include "BRUNKO4.H"
#include "ESCAL4.H"
#include "ET4.H"
#include "FRIEND4.H"
#include "FUNSUI4.H"
#include "HARID4.H"
#include "HARIR4.H"
#include "KUZURE4.H"
#include "PLAYSUB4.H"
#include "SCREW_A.H"
#include "SW4.H"
#include "SWBLK4.H"
#include "TAGAMEB4.H"
#include "TEKKYU.H"
#include "TOBIRA4.H"
#include "TONBO.H"
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
  &noact,
  &noact,
  &noact,
  &escal4,
  &sw4,
  &tobira4,
  &brunko4,
  &funsui4,
  &tonbo,
  &amenbo,
  &tagameb,
  &yago,
  &friend4,
  &swblkr4,
  &switchr4,
  &harid4,
  &walls,
  &wall1,
  &screw,
  &tekkyu,
  &noact,
  &noact,
  &kuzure4,
  &clear,
  &over,
  &title,
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
  &noact,
  &et,
  &noact
};
































































void debugact(sprite_status* pActwk) { /* Line 181, Address: 0x1015670 */
  if (pActwk->xposi.w.h++ >= 300) /* Line 182, Address: 0x101567c */
    pActwk->xposi.w.h = 0; /* Line 183, Address: 0x10156a0 */
  if (pActwk->yposi.w.h++ >= 200) /* Line 184, Address: 0x10156a8 */
    pActwk->yposi.w.h = 0; /* Line 185, Address: 0x10156cc */

  actionsub(pActwk); /* Line 187, Address: 0x10156d4 */
} /* Line 188, Address: 0x10156e0 */




void noact(sprite_status* pActwk) { /* Line 193, Address: 0x10156f0 */
  frameout(pActwk); /* Line 194, Address: 0x10156fc */
} /* Line 195, Address: 0x1015708 */
