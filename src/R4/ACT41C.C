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
#include "ESCAL4.H"
#include "FRIEND4.H"
#include "HARIR4.H"
#include "PLAYSUB4.H"
#include "RENKETU4.H"
#include "SCREW_A.H"
#include "SW4.H"
#include "SWGUN4.H"
#include "TAGAMEB4.H"
#include "TEKKYU4.H"
#include "TONBO.H"
#include "UDBLK4.H"
#include "WALL1.H"
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
  &escal4,
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
  &noact,
  &wall1,
  &screw,
  &noact,
  &noact,
  &tekkyu4,
  &noact,
  &clear,
  &over,
  &title,
  &noact,
  &renketu4,
  &swgun4,
  &ring4,
  &tensu4,
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
  &noact
};

































































void debugact(sprite_status* pActwk) { /* Line 177, Address: 0x101ff70 */
  if (pActwk->xposi.w.h++ >= 300) /* Line 178, Address: 0x101ff7c */
    pActwk->xposi.w.h = 0; /* Line 179, Address: 0x101ffa0 */
  if (pActwk->yposi.w.h++ >= 200) /* Line 180, Address: 0x101ffa8 */
    pActwk->yposi.w.h = 0; /* Line 181, Address: 0x101ffcc */

  actionsub(pActwk); /* Line 183, Address: 0x101ffd4 */
} /* Line 184, Address: 0x101ffe0 */




void noact(sprite_status* pActwk) { /* Line 189, Address: 0x101fff0 */
  frameout(pActwk); /* Line 190, Address: 0x101fffc */
} /* Line 191, Address: 0x1020008 */
