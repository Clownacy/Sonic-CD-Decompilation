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
#include "BOSS_5.H"
#include "DAI_RD5.H"
#include "KUZURE5.H"
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
  &egg5hibana,
  &egg5hari,
  &egg5belt,
  &egg5bakuha,
  &noact,
  &noact,
  &noact,
  &noact,
  &kuzure5,
  &noact,
  &noact,
  &noact,
  &noact,
  &noact,
  &noact,
  &noact,
  &dair5,
  &noact,
  &egg5,
  &egg5meca1,
  &egg5meca2,
  &egg5meca3,
  &egg5pipe,
  &egg5catch,
  &egg5bomb,
  &egg5bomb2,
  &clear,
  &over,
  &title
};































































void debugact(sprite_status* pActwk) { /* Line 142, Address: 0x101b890 */
  if (pActwk->xposi.w.h++ >= 300) /* Line 143, Address: 0x101b89c */
    pActwk->xposi.w.h = 0; /* Line 144, Address: 0x101b8c0 */
  if (pActwk->yposi.w.h++ >= 200) /* Line 145, Address: 0x101b8c8 */
    pActwk->yposi.w.h = 0; /* Line 146, Address: 0x101b8ec */

  actionsub(pActwk); /* Line 148, Address: 0x101b8f4 */
} /* Line 149, Address: 0x101b900 */




void noact(sprite_status* pActwk) { /* Line 154, Address: 0x101b910 */
  frameout(pActwk); /* Line 155, Address: 0x101b91c */
} /* Line 156, Address: 0x101b928 */
