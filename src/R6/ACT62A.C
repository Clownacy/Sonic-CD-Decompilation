#include "..\EQU.H"
#include "ACT61A.H"
#include "..\ACTION.H"
#include "..\GOAL.H"
#include "..\ITEM.H"
#include "..\PLAYER6.H"
#include "..\PLAYSUB.H"
#include "..\RING.H"
#include "..\SCORE.H"
#include "..\SPRING.H"
#include "..\ZONE.H"
#include "BATTA.H"
#include "BEEM6.H"
#include "BLOCK6.H"
#include "DAIR6.H"
#include "EGG6.H"
#include "ET6.H"
#include "FRIEND6.H"
#include "HACHI6.H"
#include "KDAI6.H"
#include "MINOMUSI.H"
#include "MOVIE6.H"
#include "PISTON6.H"
#include "SEESAW6.H"
#include "SEMI.H"
#include "SHOOT6.H"
#include "SW6.H"
#include "TOBIDAI6.H"
#include "TOBIRA6.H"
#include "TOGEBL6A.H"
#include "TRAP_R6.H"
#include "UDBLK6.H"

void(*act_tbl[60])(sprite_status*) = {
  &play00,
  &play00,
  &baria,
  &catapalt,
  &gas,
  &test_act,
  &shooter,
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
  &ball,
  &flower,
  &piston6,
  &beem6,
  &dair6,
  &tobidai6,
  &sw6,
  &tobira6,
  &udblk6,
  &optbr6,
  &kdai6,
  &friend,
  &block6,
  &eggz6,
  &seesaw6,
  &togeball,
  &et,
  &movie,
  &batta,
  &hachi6,
  &semi,
  &minomusi,
  &noact,
  &noact,
  &noact,
  &noact,
  &noact,
  &noact,
  &clear,
  &over,
  &title
};
















































void noact(sprite_status* pAct) { /* Line 144, Address: 0x102b690 */
  frameout(pAct); /* Line 145, Address: 0x102b69c */
} /* Line 146, Address: 0x102b6a8 */
