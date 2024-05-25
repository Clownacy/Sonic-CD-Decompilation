#include "..\EQU.H"
#include "ACT51A.H"
#include "..\ACTION.H"
#include "..\GOAL.H"
#include "..\ITEM.H"
#include "..\PLAYER.H"
#include "..\PLAYSUB.H"
#include "..\RING.H"
#include "..\SCORE.H"
#include "..\SPRING.H"
#include "..\ZONE.H"
#include "BELTSW5.H"
#include "BURANKO5.H"
#include "DAI_RD5.H"
#include "DENDEN.H"
#include "ET5.H"
#include "FRIEND5.H"
#include "HARI5F.H"
#include "HARIR5.H"
#include "HASHI5.H"
#include "HASIRA5.H"
#include "IWA5.H"
#include "IWA5ROLL.H"
#include "IWA5WAVE.H"
#include "KEMUSI.H"
#include "KOWASI5.H"
#include "KUMO.H"
#include "KUZURE5.H"
#include "MOVIE5.H"
#include "SASORI.H"
#include "SHOOT5.H"

void(*act_tbl[60])(sprite_status*) = {
  &play00,
  &play00,
  &baria,
  &noact,
  &noact,
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
  &noact,
  &flower,
  &denden,
  &sasori,
  &kemusi,
  &kumo,
  &iwa5,
  &hari5f,
  &harir5,
  &iwa5roll,
  &kuzure5,
  &iwa5wave,
  &buranko5,
  &hasira5,
  &movie,
  &friend,
  &et,
  &hashi5,
  &dair5,
  &beltsw5,
  &kowasi,
  &noact,
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





















































void debugact(sprite_status* pActwk) { /* Line 148, Address: 0x1016860 */
  if (pActwk->xposi.w.h++ >= 300) /* Line 149, Address: 0x101686c */
    pActwk->xposi.w.h = 0;/* Line 150, Address: 0x1016890 */
  if (pActwk->yposi.w.h++ >= 200) /* Line 151, Address: 0x1016898 */
    pActwk->yposi.w.h = 0;/* Line 152, Address: 0x10168bc */

  actionsub(pActwk);/* Line 154, Address: 0x10168c4 */
}/* Line 155, Address: 0x10168d0 */




void noact(sprite_status* pActwk) { /* Line 160, Address: 0x10168e0 */
  frameout(pActwk); /* Line 161, Address: 0x10168ec */
} /* Line 162, Address: 0x10168f8 */
