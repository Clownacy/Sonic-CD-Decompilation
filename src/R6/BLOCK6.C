#include "..\EQU.H"
#include "BLOCK6.H"
#include "..\ACTION.H"
#include "..\ACTSET.H"
#include "..\RIDECHK.H"

static void main_init(sprite_status* blockwk);
static void main_move(sprite_status* blockwk);
static void sub(sprite_status* blockwk);
static void sub_go(sprite_status* blockwk);
static void sub_go1(sprite_status* blockwk);
static void sub_stop0(sprite_status* blockwk);
static void sub_stop01(sprite_status* blockwk);
static void sub_stop02(sprite_status* blockwk);
static void sub_back(sprite_status* blockwk);
static void sub_back1(sprite_status* blockwk);
static void sub_stop1(sprite_status* blockwk);
static void sub_stop11(sprite_status* blockwk);
static void sub_die(sprite_status* blockwk);
static unsigned char set_slave(sprite_status* blockwk);

static char dat00[4] = { 0, 0, 0, -1 };
static char dat01[4] = { 1, 1, 1, -1 };
static char dat02[4] = { 2, 2, 2, -1 };
static char dat03[4] = { 3, 3, 3, -1 };
static char* tbl00[4] = { dat00, dat01, dat02, dat03 };
static char* tbl03[4] = { dat03, dat02, dat01, dat00 };
static char tbl01_00[4] = { 0, 0, 1, -1 };
static char tbl01_01[4] = { 1, 0, 1, -1 };
static char tbl01_02[4] = { 2, 2, 1, -1 };
static char tbl01_03[4] = { 3, 3, 3, -1 };
static char* tbl01[4] = { tbl01_00, tbl01_01, tbl01_02, tbl01_03 };
static char tbl02_00[3] = { 0, 0, -1 };
static char tbl02_01[3] = { 2, 2, -1 };
static char* tbl02[4] = { tbl02_00, tbl02_01, tbl02_00, tbl02_01 };
static char tbl04_00[4] = { 1, 1, 0, -1 };
static char tbl04_01[4] = { 2, 3, 3, -1 };
static char tbl04_02[4] = { 3, 0, 3, -1 };
static char tbl04_03[4] = { 0, 1, 0, -1 };
static char* tbl04[4] = { tbl04_00, tbl04_01, tbl04_02, tbl04_03 };
static char** tbl0[5] = { tbl00, tbl01, tbl02, tbl03, tbl04 };
static sprite_pattern block =
{
  1,
  { { -16, -16, 0, 298 } }
};
sprite_pattern* pat_block6[1] = { &block };
static char stack_pointer;





void block6(sprite_status* blockwk) { /* Line 54, Address: 0x10195e0 */
  void(*main_tbl[2])(sprite_status*) = { &main_init, &main_move }; /* Line 55, Address: 0x10195ec */

  if (blockwk->userflag.b.h < 0) { sub(blockwk); return; } /* Line 57, Address: 0x1019608 */

  main_tbl[blockwk->r_no0 / 2](blockwk); /* Line 59, Address: 0x1019634 */
  hitchk(blockwk, &actwk[0]); /* Line 60, Address: 0x1019670 */
  actionsub(blockwk); /* Line 61, Address: 0x1019684 */
  frameout_s(blockwk); /* Line 62, Address: 0x1019690 */
} /* Line 63, Address: 0x101969c */



static void main_init(sprite_status* blockwk) { /* Line 67, Address: 0x10196b0 */
  blockwk->r_no0 += 2; /* Line 68, Address: 0x10196b8 */
  blockwk->actflg |= 4; /* Line 69, Address: 0x10196c8 */
  blockwk->sprpri = 1; /* Line 70, Address: 0x10196d8 */
  blockwk->sprhs = blockwk->sprhsize = blockwk->sprvsize = 16; /* Line 71, Address: 0x10196e4 */

  blockwk->patbase = pat_block6; /* Line 73, Address: 0x1019708 */
  ((unsigned short*)blockwk)[23] = blockwk - actwk; /* Line 74, Address: 0x1019718 */
  blockwk->actfree[10] = 255; /* Line 75, Address: 0x101974c */
  ((unsigned short*)blockwk)[27] = 0; /* Line 76, Address: 0x1019758 */
} /* Line 77, Address: 0x1019760 */



static void main_move(sprite_status* blockwk) { /* Line 81, Address: 0x1019770 */
  if (blockwk->actfree[10] == 0) return; /* Line 82, Address: 0x101977c */
  blockwk->actfree[10] = 0; /* Line 83, Address: 0x1019790 */
  ((char**)blockwk)[12] = tbl0[blockwk->userflag.b.h][((unsigned short*)blockwk)[27] / 2]; /* Line 84, Address: 0x1019798 */

  if ((((unsigned short*)blockwk)[27] += 2) >= 8) /* Line 86, Address: 0x10197f4 */
    ((unsigned short*)blockwk)[27] = 0; /* Line 87, Address: 0x1019818 */
  if (set_slave(blockwk) != 0) frameout(blockwk); /* Line 88, Address: 0x1019820 */
} /* Line 89, Address: 0x1019844 */













static void sub(sprite_status* blockwk) { /* Line 103, Address: 0x1019860 */
  sprite_status* parent_wk;
  void(*sub_tbl[10])(sprite_status*) = { /* Line 105, Address: 0x1019870 */
    &sub_go, &sub_go1, &sub_stop0, &sub_stop01, &sub_stop02, &sub_back, &sub_back1, &sub_stop1, &sub_stop11, &sub_die
  };

  parent_wk = &actwk[((unsigned short*)blockwk)[23]]; /* Line 109, Address: 0x10198a4 */
  if (parent_wk->actno != 42) /* Line 110, Address: 0x10198c8 */
  { frameout(blockwk); return; } /* Line 111, Address: 0x10198dc */
  if (blockwk->userflag.b.l != parent_wk->userflag.b.l) /* Line 112, Address: 0x10198f0 */
  { frameout(blockwk); return; } /* Line 113, Address: 0x1019914 */

  stack_pointer = 0; /* Line 115, Address: 0x1019928 */
  sub_tbl[blockwk->r_no0 / 2](blockwk); /* Line 116, Address: 0x1019930 */
  if (stack_pointer != 0) return; /* Line 117, Address: 0x101996c */
  hitchk(blockwk, &actwk[0]); /* Line 118, Address: 0x1019984 */
  actionsub(blockwk); /* Line 119, Address: 0x1019998 */
} /* Line 120, Address: 0x10199a4 */



static void sub_go(sprite_status* blockwk) { /* Line 124, Address: 0x10199c0 */
  char *speed_tbl, speed_data;

  blockwk->r_no0 += 2; /* Line 127, Address: 0x10199d4 */
  ((short*)blockwk)[26] = 63; /* Line 128, Address: 0x10199e4 */
  ((int*)blockwk)[15] = ((int*)blockwk)[16] = 0; /* Line 129, Address: 0x10199f0 */

  speed_tbl = ((char**)blockwk)[12] - 1; /* Line 131, Address: 0x1019a00 */
  switch (speed_data = *speed_tbl) { /* Line 132, Address: 0x1019a0c */
    case 0:
      ((int*)blockwk)[16] = -32768; /* Line 134, Address: 0x1019a54 */
      break; /* Line 135, Address: 0x1019a60 */
    case 1:
      ((int*)blockwk)[15] = 32768; /* Line 137, Address: 0x1019a68 */
      break; /* Line 138, Address: 0x1019a74 */
    case 2:
      ((int*)blockwk)[16] = 32768; /* Line 140, Address: 0x1019a7c */
      break; /* Line 141, Address: 0x1019a88 */
    case 3:
      ((int*)blockwk)[15] = -32768; /* Line 143, Address: 0x1019a90 */
      break;
  }


  if (actwk[((unsigned short*)blockwk)[23]].userflag.b.h == 2) { /* Line 148, Address: 0x1019a9c */
    if (((int*)blockwk)[16] >= 0) /* Line 149, Address: 0x1019ad8 */
      ((short*)blockwk)[28] = blockwk->yspeed.w = 1; /* Line 150, Address: 0x1019ae8 */
    else
      ((short*)blockwk)[28] = blockwk->yspeed.w = -1; /* Line 152, Address: 0x1019b0c */
  }
  sub_go1(blockwk); /* Line 154, Address: 0x1019b28 */
} /* Line 155, Address: 0x1019b34 */



static void sub_go1(sprite_status* blockwk) { /* Line 159, Address: 0x1019b50 */
  blockwk->xposi.l += ((int*)blockwk)[15]; /* Line 160, Address: 0x1019b58 */
  blockwk->yposi.l += ((int*)blockwk)[16]; /* Line 161, Address: 0x1019b70 */
  if (--((short*)blockwk)[26] < 0) blockwk->r_no0 += 2; /* Line 162, Address: 0x1019b88 */
} /* Line 163, Address: 0x1019bc0 */



static void sub_stop0(sprite_status* blockwk) { /* Line 167, Address: 0x1019bd0 */
  sprite_status* parent_wk;

  parent_wk = &actwk[((unsigned short*)blockwk)[23]]; /* Line 170, Address: 0x1019bdc */

  blockwk->r_no0 += 2; /* Line 172, Address: 0x1019c00 */
  blockwk->yspeed.w = 0; /* Line 173, Address: 0x1019c10 */
  if (parent_wk->userflag.b.h != 2) /* Line 174, Address: 0x1019c18 */
    ((short*)blockwk)[26] = 30; /* Line 175, Address: 0x1019c30 */
  else
    ((short*)blockwk)[26] = 0; /* Line 177, Address: 0x1019c44 */
} /* Line 178, Address: 0x1019c4c */



static void sub_stop01(sprite_status* blockwk) { /* Line 182, Address: 0x1019c60 */
  if (--((short*)blockwk)[26] >= 0) return; /* Line 183, Address: 0x1019c6c */
  blockwk->r_no0 += 2; /* Line 184, Address: 0x1019c94 */
  if (set_slave(blockwk) == 0) return; /* Line 185, Address: 0x1019ca4 */
  blockwk->r_no0 += 2; /* Line 186, Address: 0x1019cbc */
  actwk[((unsigned short*)blockwk)[23]].actfree[10] = 255; /* Line 187, Address: 0x1019ccc */
} /* Line 188, Address: 0x1019cf8 */



static void sub_stop02(sprite_status* blockwk) { /* Line 192, Address: 0x1019d10 */
  blockwk->actno = blockwk->actno; /* Line 193, Address: 0x1019d18 */
} /* Line 194, Address: 0x1019d28 */



static void sub_back(sprite_status* blockwk) { /* Line 198, Address: 0x1019d40 */
  blockwk->r_no0 += 2; /* Line 199, Address: 0x1019d48 */
  ((short*)blockwk)[26] = 63; /* Line 200, Address: 0x1019d58 */
  blockwk->yspeed.w = -((short*)blockwk)[28]; /* Line 201, Address: 0x1019d64 */
} /* Line 202, Address: 0x1019d88 */



static void sub_back1(sprite_status* blockwk) { /* Line 206, Address: 0x1019da0 */
  blockwk->xposi.l -= ((int*)blockwk)[15]; /* Line 207, Address: 0x1019da8 */
  blockwk->yposi.l -= ((int*)blockwk)[16]; /* Line 208, Address: 0x1019dc0 */
  if (--((short*)blockwk)[26] < 0) blockwk->r_no0 += 2; /* Line 209, Address: 0x1019dd8 */
} /* Line 210, Address: 0x1019e10 */



static void sub_stop1(sprite_status* blockwk) { /* Line 214, Address: 0x1019e20 */
  sprite_status* parent_wk;

  parent_wk = &actwk[((unsigned short*)blockwk)[23]]; /* Line 217, Address: 0x1019e2c */

  blockwk->r_no0 += 2; /* Line 219, Address: 0x1019e50 */
  blockwk->yspeed.w = 0; /* Line 220, Address: 0x1019e60 */
  if (parent_wk->userflag.b.h != 2) /* Line 221, Address: 0x1019e68 */
    ((short*)blockwk)[26] = 30; /* Line 222, Address: 0x1019e80 */
  else
    ((short*)blockwk)[26] = 0; /* Line 224, Address: 0x1019e94 */
} /* Line 225, Address: 0x1019e9c */



static void sub_stop11(sprite_status* blockwk) { /* Line 229, Address: 0x1019eb0 */
  sprite_status* parent_wk;

  if (--((short*)blockwk)[26] >= 0) return; /* Line 232, Address: 0x1019ebc */
  parent_wk = &actwk[((unsigned short*)blockwk)[29]]; /* Line 233, Address: 0x1019ee4 */
  if (parent_wk->userflag.b.h < 0) parent_wk->r_no0 += 2; /* Line 234, Address: 0x1019f08 */
  blockwk->r_no0 += 2; /* Line 235, Address: 0x1019f28 */
} /* Line 236, Address: 0x1019f38 */



static void sub_die(sprite_status* blockwk) { /* Line 240, Address: 0x1019f50 */
  if (hitchk(blockwk, &actwk[0]) != 0) ride_on_clr(blockwk, &actwk[0]); /* Line 241, Address: 0x1019f5c */
  stack_pointer = -1; /* Line 242, Address: 0x1019f94 */
  frameout(blockwk); /* Line 243, Address: 0x1019fa0 */
} /* Line 244, Address: 0x1019fac */



static unsigned char set_slave(sprite_status* blockwk) { /* Line 248, Address: 0x1019fc0 */
  char *speed_tbl, counter = 0; /* Line 249, Address: 0x1019fd4 */
  sprite_status* new_actwk;

  speed_tbl = ((char**)blockwk)[12]; /* Line 252, Address: 0x1019fd8 */
  if (speed_tbl[counter++] < 0) return 1; /* Line 253, Address: 0x1019fe0 */
  if (actwkchk(&new_actwk) != 0) return 1; /* Line 254, Address: 0x101a01c */
  new_actwk->actno = blockwk->actno; /* Line 255, Address: 0x101a03c */
  new_actwk->actflg = blockwk->actflg; /* Line 256, Address: 0x101a04c */
  new_actwk->sproffset = blockwk->sproffset; /* Line 257, Address: 0x101a05c */
  new_actwk->patbase = blockwk->patbase; /* Line 258, Address: 0x101a06c */
  new_actwk->xposi.l = blockwk->xposi.l; /* Line 259, Address: 0x101a07c */
  new_actwk->yposi.l = blockwk->yposi.l; /* Line 260, Address: 0x101a08c */
  new_actwk->xspeed.w = blockwk->xspeed.w; /* Line 261, Address: 0x101a09c */
  new_actwk->yspeed.w = blockwk->yspeed.w; /* Line 262, Address: 0x101a0ac */
  new_actwk->mspeed.w = blockwk->mspeed.w; /* Line 263, Address: 0x101a0bc */
  new_actwk->sprhsize = blockwk->sprhsize; /* Line 264, Address: 0x101a0cc */
  new_actwk->sprvsize = blockwk->sprvsize; /* Line 265, Address: 0x101a0dc */
  new_actwk->sprhs = blockwk->sprhs; /* Line 266, Address: 0x101a0ec */
  new_actwk->sprpri = (char)(blockwk->sprpri + 1); /* Line 267, Address: 0x101a0fc */
  new_actwk->patno = blockwk->patno; /* Line 268, Address: 0x101a120 */
  new_actwk->mstno.w = blockwk->mstno.w; /* Line 269, Address: 0x101a130 */
  new_actwk->patcnt = blockwk->patcnt; /* Line 270, Address: 0x101a140 */
  new_actwk->pattim = blockwk->pattim; /* Line 271, Address: 0x101a150 */
  new_actwk->pattimm = blockwk->pattimm; /* Line 272, Address: 0x101a160 */
  new_actwk->colino = blockwk->colino; /* Line 273, Address: 0x101a170 */
  new_actwk->colicnt = blockwk->colicnt; /* Line 274, Address: 0x101a180 */
  new_actwk->cddat = blockwk->cddat; /* Line 275, Address: 0x101a190 */
  new_actwk->cdsts = blockwk->cdsts; /* Line 276, Address: 0x101a1a0 */
  new_actwk->r_no0 = 0; /* Line 277, Address: 0x101a1b0 */
  new_actwk->r_no1 = blockwk->r_no1; /* Line 278, Address: 0x101a1b8 */
  new_actwk->direc.w = blockwk->direc.w; /* Line 279, Address: 0x101a1c8 */
  new_actwk->userflag.w = blockwk->userflag.w; /* Line 280, Address: 0x101a1d8 */
  ((unsigned short*)new_actwk)[23] = ((unsigned short*)blockwk)[23]; /* Line 281, Address: 0x101a1e8 */


  new_actwk->userflag.b.h = -1; /* Line 284, Address: 0x101a1f8 */
  ((unsigned short*)new_actwk)[29] = blockwk - actwk; /* Line 285, Address: 0x101a204 */
  ((char**)new_actwk)[12] = &speed_tbl[counter]; /* Line 286, Address: 0x101a238 */
  return 0; /* Line 287, Address: 0x101a24c */
} /* Line 288, Address: 0x101a250 */
