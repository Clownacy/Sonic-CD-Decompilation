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
#include "AWA.H"
#include "BANEIWA.H"
#include "DAID4.H"
#include "FRIEND4.H"
#include "LRBLK4.H"
#include "HARIR4.H"
#include "SW4.H"
#include "AMENBO.H"
#include "KOWASI4.H"
#include "KUZURE4.H"
#include "PLAYSUB4.H"
#include "RENKETU4.H"
#include "SCREW_A.H"
#include "TAGAMEB4.H"
#include "TEKKYU.H"
#include "TEKKYU1.H"
#include "TEKKYU4.H"
#include "TOBIRA4.H"
#include "TOBIRAS4.H"
#include "TONBO.H"
#include "UDBLK4.H"
#include "WALL1.H"
#include "WALLS.H"
#include "YAGO.H"

void(*act_tbl[80])(sprite_status*) = {
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
  &lrblk4,
  &tobiras4,
  &noact,
  &sw4,
  &tobira4,
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
  &tekkyu,
  &tekkyu1,
  &tekkyu4,
  &kuzure4,
  &clear,
  &over,
  &title,
  &noact,
  &renketu4,
  &noact,
  &noact,
  &noact,
  &noact,
  &noact,
  &noact,
  &noact,
  &noact,
  &noact,
  &baneiwa,
  &daid4,
  &noact,
  &noact,
  &noact,
  &noact,
  &noact,
  &noact,
  &kowasi4
};






























































void debugact(sprite_status* pActwk) { /* Line 180, Address: 0x1026980 */
  if (pActwk->xposi.w.h++ >= 300) /* Line 181, Address: 0x102698c */
    pActwk->xposi.w.h = 0; /* Line 182, Address: 0x10269b0 */
  if (pActwk->yposi.w.h++ >= 200) /* Line 183, Address: 0x10269b8 */
    pActwk->yposi.w.h = 0; /* Line 184, Address: 0x10269dc */

  actionsub(pActwk); /* Line 186, Address: 0x10269e4 */
} /* Line 187, Address: 0x10269f0 */




void noact(sprite_status* pActwk) { /* Line 192, Address: 0x1026a00 */
  frameout(pActwk); /* Line 193, Address: 0x1026a0c */
} /* Line 194, Address: 0x1026a18 */
