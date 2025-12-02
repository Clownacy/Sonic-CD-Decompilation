#include "..\EQU.H"
#include "PLAYSP8.H"
#include "..\ACTION.H"
#include "..\ACTSET.H"
#include "..\FCOL.H"
#include "..\RIDECHK.H"

static void chibi_init(sprite_status* smallwk);
static void chibi_move(sprite_status* smallwk);
static unsigned char playsp_chk(short block_no);

static sprite_pattern chb00 = {
  1,
  { { -16, -20, 0, 0 } }
};
sprite_pattern* chibipat[1] = { &chb00 };


void chibi_coli(sprite_status* smallwk) { /* Line 19, Address: 0x1026080 */
  void(*tbl[2])(sprite_status*) = { &chibi_init, &chibi_move }; /* Line 20, Address: 0x102608c */

  tbl[smallwk->r_no0 / 2](smallwk); /* Line 22, Address: 0x10260a8 */
  actionsub(smallwk); /* Line 23, Address: 0x10260e4 */
  frameout_s(smallwk); /* Line 24, Address: 0x10260f0 */
} /* Line 25, Address: 0x10260fc */



static void chibi_init(sprite_status* smallwk) { /* Line 29, Address: 0x1026110 */
  smallwk->r_no0 += 2; /* Line 30, Address: 0x102611c */
  smallwk->actflg |= 4; /* Line 31, Address: 0x102612c */
  smallwk->patbase = chibipat; /* Line 32, Address: 0x102613c */
  smallwk->sprhs = smallwk->sprhsize = smallwk->sprvsize = 16; /* Line 33, Address: 0x102614c */
  chibi_move(smallwk); /* Line 34, Address: 0x1026170 */
} /* Line 35, Address: 0x102617c */


static void chibi_move(sprite_status* smallwk) { /* Line 38, Address: 0x1026190 */
  hitchk(smallwk, &actwk[0]); /* Line 39, Address: 0x102619c */
} /* Line 40, Address: 0x10261b0 */



void playsp(void) { /* Line 44, Address: 0x10261c0 */
  short block_no, block_tmp, x_add;

  if (stageno.b.l == 2) return; /* Line 47, Address: 0x10261d4 */

  block_tmp = scramapad(&actwk[0], actwk[0].xposi.w.h - (short)actwk[0].sprhs, actwk[0].yposi.w.h + (short)actwk[0].sprvsize + 2); /* Line 49, Address: 0x10261f0 */


  block_no = block_tmp & 2047; /* Line 52, Address: 0x102626c */
  if (!playsp_chk(block_no)) { /* Line 53, Address: 0x1026288 */
    block_tmp = scramapad(&actwk[0], actwk[0].xposi.w.h + (short)actwk[0].sprhs, actwk[0].yposi.w.h + (short)actwk[0].sprvsize + 2); /* Line 54, Address: 0x102629c */


    block_no = block_tmp & 2047; /* Line 57, Address: 0x1026318 */
    if (playsp_chk(block_no) == 0) return; /* Line 58, Address: 0x1026334 */
  }
  if (!(block_tmp & 2048)) x_add = 1; /* Line 60, Address: 0x102634c */
  else x_add = -1; /* Line 61, Address: 0x1026374 */
  if (block_no == 276) x_add = -x_add; /* Line 62, Address: 0x1026380 */
  actwk[0].xposi.w.h += x_add; /* Line 63, Address: 0x10263b0 */
} /* Line 64, Address: 0x10263c4 */


static unsigned char playsp_chk(short block_no) { /* Line 67, Address: 0x10263e0 */
  short i = 0; /* Line 68, Address: 0x10263ec */
  short belt[7] = { 270, 271, 272, 273, 274, 275, 276 }; /* Line 69, Address: 0x10263f0 */

  for ( ; i < 7; ++i) if (block_no == belt[i]) return 1; /* Line 71, Address: 0x102641c */
  return 0; /* Line 72, Address: 0x1026480 */


} /* Line 75, Address: 0x1026484 */
