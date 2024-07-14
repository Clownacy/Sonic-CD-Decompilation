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
#include "DAI8.H"
#include "ET8.H"
#include "FRIEND8.H"
#include "HACHI8.H"
#include "HAGURUMA.H"
#include "KABUTO8.H"
#include "KOMA8.H"
#include "KONBEA.H"
#include "KUZURE8.H"
#include "NOKOGIRI.H"
#include "OKUSIESO.H"
#include "PISTON.H"
#include "PROPERA8.H"
#include "SCARAB.H"
#include "SW8.H"
#include "TOBIRA.H"
#include "TRAP_R81.H"

void(*act_tbl[67])(sprite_status*) = {
  &play00,
  &play00,
  &baria,
  &noact,
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
  &noact,
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
  &propera,
  &tobira,
  &konbea,
  &noact,
  &dai8,
  &noact,
  &hachi8,
  &scarab,
  &noact,
  &noact,
  &friend,
  &noact,
  &piston,
  &okusieso,
  &togedair8,
  &anar8,
  &futagor8,
  &noact,
  &clear,
  &over,
  &title,
  &noact,
  &noact,
  &noact,
  &noact,
  &noact,
  &noact,
  &et
};




























































void debugact(sprite_status* pActwk) { /* Line 159, Address: 0x101acd0 */
  if (pActwk->xposi.w.h++ >= 300) /* Line 160, Address: 0x101acdc */
    pActwk->xposi.w.h = 0; /* Line 161, Address: 0x101ad00 */
  if (pActwk->yposi.w.h++ >= 200) /* Line 162, Address: 0x101ad08 */
    pActwk->yposi.w.h = 0; /* Line 163, Address: 0x101ad2c */

  actionsub(pActwk); /* Line 165, Address: 0x101ad34 */
} /* Line 166, Address: 0x101ad40 */




void noact(sprite_status* pActwk) { /* Line 171, Address: 0x101ad50 */
  frameout(pActwk); /* Line 172, Address: 0x101ad5c */
} /* Line 173, Address: 0x101ad68 */
