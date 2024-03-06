#include "..\EQU.H"
#include "ACT41A.H"
#include "..\GOAL.H"
#include "..\ITEM.H"
#include "..\PLAYER.H"
#include "..\RING.H"
#include "..\SCORE.H"
#include "..\SPRING.H"
#include "..\ZONE.H"
#include "AWA.H"
#include "BOSS_4.H"
#include "BOSS_4_2.H"
#include "FRIEND4.H"
#include "PLAYSUB4.H"
#include "RENKETU4.H"
#include "TONBO.H"
#include "WALL1.H"
#include "WALL4.H"

void(*act_tbl[80])(sprite_status*) = {
  &play00,
  &play00,
  &baria,
  &wave,
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
  &awa,
  &plawa,
  &noact,
  &noact,
  &noact,
  &noact,
  &noact,
  &noact,
  &noact,
  &noact,
  &noact,
  &tonbo,
  &noact,
  &noact,
  &noact,
  &friend4,
  &noact,
  &noact,
  &noact,
  &noact,
  &wall1,
  &noact,
  &noact,
  &noact,
  &noact,
  &noact,
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
  &wall4,
  &noact,
  &noact,
  &egg4air,
  &egg4airhead,
  &egg4,
  &egg4meca,
  &egg4tama,
  &egg4awa,
  &noact
};
































































void debugact(sprite_status* pActwk) { /* Line 166, Address: 0x101f630 */
  if (pActwk->xposi.w.h++ >= 300) /* Line 167, Address: 0x101f63c */
    pActwk->xposi.w.h = 0; /* Line 168, Address: 0x101f660 */
  if (pActwk->yposi.w.h++ >= 200) /* Line 169, Address: 0x101f668 */
    pActwk->yposi.w.h = 0; /* Line 170, Address: 0x101f68c */

  actionsub(pActwk); /* Line 172, Address: 0x101f694 */
} /* Line 173, Address: 0x101f6a0 */




void noact(sprite_status* pActwk) { /* Line 178, Address: 0x101f6b0 */
  frameout(pActwk); /* Line 179, Address: 0x101f6bc */
} /* Line 180, Address: 0x101f6c8 */
