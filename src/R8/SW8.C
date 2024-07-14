#include "..\EQU.H"
#include "SW8.H"
#include "..\ACTION.H"
#include "..\ACTSET.H"
#include "..\LOADER2.H"
#include "..\RIDECHK.H"

static void act_init(sprite_status* swwk);
static void act_move(sprite_status* swwk);

static sprite_pattern sw00 = {
  2,
  {
    { -16, -8, 0, 308 },
    { 0, -8, 8, 308 }
  }
};
static sprite_pattern sw01 = {
  2,
  {
    { -16, -4, 0, 309 },
    { 0, -4, 8, 309 }
  }
};
sprite_pattern* pat_sw[2] = {
  &sw00,
  &sw01
};










void sw(sprite_status* swwk) { /* Line 39, Address: 0x1025820 */
  if (swwk->r_no0 == 0) act_init(swwk); /* Line 40, Address: 0x102582c */
  else act_move(swwk); /* Line 41, Address: 0x1025854 */
} /* Line 42, Address: 0x1025860 */



static void act_init(sprite_status* swwk) { /* Line 46, Address: 0x1025870 */
  swwk->r_no0 += 2; /* Line 47, Address: 0x1025878 */
  swwk->actflg |= 4; /* Line 48, Address: 0x1025888 */
  swwk->sprpri = 1; /* Line 49, Address: 0x1025898 */
  swwk->sprhs = swwk->sprhsize = 16; /* Line 50, Address: 0x10258a4 */

  swwk->patbase = pat_sw; /* Line 52, Address: 0x10258bc */
  swwk->sprvsize = 8; /* Line 53, Address: 0x10258cc */

  ((short*)swwk)[32] = swwk->userflag.b.h; /* Line 55, Address: 0x10258d8 */
} /* Line 56, Address: 0x10258f0 */




static void act_move(sprite_status* swwk) { /* Line 61, Address: 0x1025900 */
  short switch_adr;

  swwk->actfree[20] = swwk->actfree[21]; /* Line 64, Address: 0x1025910 */
  switch_adr = ((short*)swwk)[32]; /* Line 65, Address: 0x1025920 */
  if (hitchk(swwk, &actwk[0]) && actwk[0].yposi.w.h <= swwk->yposi.w.h) { /* Line 66, Address: 0x1025930 */
    swwk->actfree[21] = 255; /* Line 67, Address: 0x1025978 */
    switchflag[switch_adr] |= 192; /* Line 68, Address: 0x1025984 */
  } else { /* Line 69, Address: 0x10259a4 */
    swwk->actfree[21] = 0; /* Line 70, Address: 0x10259ac */
    switchflag[switch_adr] &= 127; /* Line 71, Address: 0x10259b4 */
  }


  if (swwk->actfree[20] == 0 && swwk->actfree[21] == 255) { /* Line 75, Address: 0x10259d4 */

    if ((char)swwk->actflg < 0) soundset(191); /* Line 77, Address: 0x1025a00 */

    switchflag[switch_adr] ^= 32; /* Line 79, Address: 0x1025a2c */
    actwk[0].yposi.w.h += 8; /* Line 80, Address: 0x1025a4c */
    swwk->yposi.w.h += 4; /* Line 81, Address: 0x1025a60 */
    ++swwk->patno; /* Line 82, Address: 0x1025a70 */
    swwk->sprvsize -= 4; /* Line 83, Address: 0x1025a80 */
  }

  if (swwk->actfree[20] == 255 && swwk->actfree[21] == 0) { /* Line 86, Address: 0x1025a90 */

    actwk[0].yposi.w.h -= 12; /* Line 88, Address: 0x1025abc */
    swwk->yposi.w.h -= 4; /* Line 89, Address: 0x1025ad0 */
    --swwk->patno; /* Line 90, Address: 0x1025ae0 */
    swwk->sprvsize += 4; /* Line 91, Address: 0x1025af0 */
  }

  actionsub(swwk); /* Line 94, Address: 0x1025b00 */
  frameout_s(swwk); /* Line 95, Address: 0x1025b0c */
} /* Line 96, Address: 0x1025b18 */
