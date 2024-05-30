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
#include "ET3.H"
#include "FRIEND3.H"
#include "GA3.H"
#include "KAMA.H"
#include "MECASNC.H"
#include "MIRACLE.H"
#include "MOVIE3.H"
#include "POCKET.H"
#include "TENTOU.H"
#include "TOGEBL3A.H"
#include "TRAP_R3.H"

void(*act_tbl[60])(sprite_status*) = {
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
  &hari3x,
  &mecasnc3,
  &emie3,
  &heart3,
  &msnc3fire,
  &ball,
  &noact,
  &et,
  &movie,
  &friend,
  &clear,
  &over,
  &title
};































































































































void noact(sprite_status* pAct) { /* Line 217, Address: 0x10298c0 */
  frameout(pAct); /* Line 218, Address: 0x10298cc */
} /* Line 219, Address: 0x10298d8 */
