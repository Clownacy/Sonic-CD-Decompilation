#include "..\EQU.H"
#include "ACT81A.H"
#include "..\ACTION.H"
#include "..\GOAL.H"
#include "..\ITEM.H"
#include "..\PLAYER.H"
#include "..\PLAYSUB.H"
#include "..\RING.H"
#include "..\SCORE.H"
#include "..\SPRING.H"
#include "..\ZONE.H"
#include "BEAM.H"
#include "BIGBOM8.H"
#include "DAI8.H"
#include "DANGO8.H"
#include "ET8.H"
#include "FRIEND8.H"
#include "HAGURUMA.H"
#include "JETTOGE8.H"
#include "KABUTO8.H"
#include "KOMA8.H"
#include "KUZURE8.H"
#include "LEGMECA8.H"
#include "OKUSIESO.H"
#include "PIPE8.H"
#include "PISTON.H"
#include "PLAYSP8.H"
#include "SHOOT.H"
#include "SHUT.H"
#include "SW8.H"
#include "TOBIRA.H"
#include "TRAP_R82.H"

void(*act_tbl[67])(sprite_status*) = {
  &play00,
  &play00,
  &baria,
  &noact,
  &noact,
  &test_act,
  &shooter,
  &noact,
  &chibi_coli,
  &spring,
  &exit2,
  &exit2_set,
  &futa,
  &mizukiri,
  &koma8,
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
  &beam,
  &noact,
  &flower,
  &pipe8,
  &sw,
  &haguruma,
  &bigbom,
  &kabuto,
  &kuzure8,
  &legmeca,
  &noact,
  &noact,
  &tobira,
  &noact,
  &jettoge,
  &dai8,
  &dango,
  &noact,
  &noact,
  &gater8,
  &noact,
  &friend,
  &togeita,
  &piston,
  &okusieso,
  &togedair8,
  &noact,
  &noact,
  &noact,
  &clear,
  &over,
  &title,
  &shut,
  &kaiten,
  &noact,
  &noact,
  &noact,
  &noact,
  &et
};




















































































void debugact(sprite_status* pActwk) { /* Line 187, Address: 0x1021860 */
  if (pActwk->xposi.w.h++ >= 300) /* Line 188, Address: 0x102186c */
    pActwk->xposi.w.h = 0; /* Line 189, Address: 0x1021890 */
  if (pActwk->yposi.w.h++ >= 200) /* Line 190, Address: 0x1021898 */
    pActwk->yposi.w.h = 0; /* Line 191, Address: 0x10218bc */

  actionsub(pActwk); /* Line 193, Address: 0x10218c4 */
} /* Line 194, Address: 0x10218d0 */




void noact(sprite_status* pActwk) { /* Line 199, Address: 0x10218e0 */
  frameout(pActwk); /* Line 200, Address: 0x10218ec */
} /* Line 201, Address: 0x10218f8 */
