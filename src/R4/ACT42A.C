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
#include "HARIR4.H"
#include "KUZURE4.H"
#include "LRBLK4.H"
#include "OSUMIZU.H"
#include "PLAYSUB4.H"
#include "SCREW_A.H"
#include "SW4.H"
#include "TAGAMEB4.H"
#include "TEKKYU.H"
#include "TEKKYU1.H"
#include "TEKKYU4.H"
#include "TOBIRA4.H"
#include "TOBIRAS4.H"
#include "TONBO.H"
#include "UKIDAI.H"
#include "WALL1.H"
#include "WALL42.H"
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
  &lrblk4,
  &tobiras4,
  &escal4,
  &sw4,
  &tobira4,
  &brunko4,
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
  &osumizu,
  &noact,
  &ukidai,
  &wall42,
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
































































void debugact(sprite_status* pActwk) { /* Line 185, Address: 0x102d100 */
  if (pActwk->xposi.w.h++ >= 300) /* Line 186, Address: 0x102d10c */
    pActwk->xposi.w.h = 0; /* Line 187, Address: 0x102d130 */
  if (pActwk->yposi.w.h++ >= 200) /* Line 188, Address: 0x102d138 */
    pActwk->yposi.w.h = 0; /* Line 189, Address: 0x102d15c */

  actionsub(pActwk); /* Line 191, Address: 0x102d164 */
} /* Line 192, Address: 0x102d170 */




void noact(sprite_status* pActwk) { /* Line 197, Address: 0x102d180 */
  frameout(pActwk); /* Line 198, Address: 0x102d18c */
} /* Line 199, Address: 0x102d198 */
