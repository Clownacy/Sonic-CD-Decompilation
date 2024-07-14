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
#include "..\R3\BOBIN.H"
#include "BOSS_8.H"
#include "DAI8.H"
#include "EMIE8.H"
#include "FRIEND8.H"
#include "HAGURUMA.H"
#include "HOTA8C.H"
#include "JETTOGE8.H"
#include "KABUTO8.H"
#include "KOMA8.H"
#include "KONBEA83.H"
#include "KUZURE8.H"
#include "NOKOGIRI.H"
#include "PISTON.H"
#include "PLAYSP8.H"
#include "SHUT.H"
#include "SW8.H"
#include "TOBIRA.H"
#include "TRAP_R83.H"

void(*act_tbl[67])(sprite_status*) = {
  &play00,
  &play00,
  &baria,
  &noact,
  &noact,
  &test_act,
  &noact,
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
  &bobin,
  &noact,
  &flower,
  &noact,
  &sw,
  &haguruma,
  &noact,
  &kabuto,
  &kuzure8,
  &noact,
  &nokogiri,
  &noact,
  &tobira,
  &konbea,
  &jettoge,
  &dai8,
  &noact,
  &noact,
  &noact,
  &noact,
  &noact,
  &friend,
  &togeita,
  &piston,
  &noact,
  &togedair8,
  &noact,
  &noact,
  &hotaru8,
  &clear,
  &over,
  &title,
  &shut,
  &kaiten,
  &egg8,
  &egg8hane,
  &egg8meca,
  &egg8hibana,
  &emie8
};




























































void debugact(sprite_status* pActwk) { /* Line 161, Address: 0x1025fd0 */
  if (pActwk->xposi.w.h++ >= 300) /* Line 162, Address: 0x1025fdc */
    pActwk->xposi.w.h = 0; /* Line 163, Address: 0x1026000 */
  if (pActwk->yposi.w.h++ >= 200) /* Line 164, Address: 0x1026008 */
    pActwk->yposi.w.h = 0; /* Line 165, Address: 0x102602c */

  actionsub(pActwk); /* Line 167, Address: 0x1026034 */
} /* Line 168, Address: 0x1026040 */




void noact(sprite_status* pActwk) { /* Line 173, Address: 0x1026050 */
  frameout(pActwk); /* Line 174, Address: 0x102605c */
} /* Line 175, Address: 0x1026068 */
