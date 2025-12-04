#include "..\EQU.H"
#include "ACT31A.H"
#include "..\ACTION.H"
#include "..\BLOCK.H"
#include "..\GOAL.H"
#include "..\ITEM.H"
#include "..\PLAYER.H"
#include "..\PLAYSUB.H"
#include "..\RING.H"
#include "..\SCORE.H"
#include "..\SPRING.H"
#include "..\ZONE.H"
#include "BANPA.H"
#include "BOBIN.H"
#include "BOBINB.H"
#include "BOSS_3.H"
#include "ET3.H"
#include "FRIEND3.H"
#include "GA3.H"
#include "GATE.H"
#include "KAMA.H"
#include "MIRACLE.H"
#include "MOVIE3.H"
#include "POCKET.H"
#include "SIKAKE33.H"
#include "TENTOU.H"
#include "TOGEBL3A.H"
#include "TRAP_R3.H"

void(*act_tbl[63])(sprite_status*) = {
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
  &koma,
  &ring,
  &flyring,
  &block,
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
  &frip,
  &flower,
  &harir3,
  &frdr3,
  &trapdr3,
  &for3,
  &ene_kama,
  &tama_kama,
  &getdair3,
  &gandair3,
  &drumr3,
  &bobinbreak,
  &banpa,
  &miracle,
  &togeball,
  &ga,
  &tentou,
  &pocket,
  &egg3dai_s,
  &egg3dai_l,
  &egg3haguruma,
  &egg3,
  &noact,
  &ball,
  &sikake33,
  &et,
  &movie,
  &friend,
  &clear,
  &over,
  &title,
  &egg3cannon,
  &punchbom,
  &gate
};






























































































































void noact(sprite_status* pAct) { /* Line 221, Address: 0x1024a70 */
  frameout(pAct); /* Line 222, Address: 0x1024a7c */
} /* Line 223, Address: 0x1024a88 */
