#include "..\EQU.H"
#include "EGG6.H"
#include "..\ACTION.H"
#include "..\ACTSET.H"
#include "..\LOADER2.H"
#include "..\PLAYSUB.H"
#include "..\RIDECHK.H"

static void act_init(sprite_status* eggwk);
static void act_check(sprite_status* eggwk);
static void act_make0(sprite_status* eggwk);
static void act_wait(sprite_status* eggwk);
static void act_make1(sprite_status* eggwk);
static void bomb_init(sprite_status* bombwk);
static void bomb_fall(sprite_status* bombwk);
static void bomb_die(sprite_status* bombwk);

static sprite_pattern egg00 = {
  1,
  { { -20, -28, 0, 299 } }
};
static sprite_pattern pat00 = {
  1,
  { { -16, -20, 0, 0 } }
};
sprite_pattern* pat_egg6[2] = {
  &egg00,
  &pat00
};
static char tbl0[28] = { 1, 0, 0, 5, -18, -10, 10, -10, 10, 15, 0, -10, 20, -10, -10, 25, 13, -10, 30, -10, 20, 35, 13, -10, 40, -10, 10, -1 };
static char tbl1[21] = { -24, -64, -8, 64, 8, 0, 24, -128, 40, -128, 56, 64, 72, 64, 88, -128, 104, 64, 120, -64, -1 };
static unsigned char stack_pointer;
static unsigned char pchg_bomb00[4] = { 1, 0, 1, 255 };
static unsigned char* pchg_bomb[1] = { pchg_bomb00 };
static sprite_pattern bomb0 = {
  1,
  { { -8, -8, 0, 300 } }
};
static sprite_pattern bomb1 = {
  1,
  { { -8, -8, 0, 301 } }
};
sprite_pattern* pat_bomb[2] = { &bomb0, &bomb1 };



void eggz6(sprite_status* eggwk) { /* Line 47, Address: 0x101a7a0 */
  void(*act_tbl[5])(sprite_status*) = { &act_init, &act_check, &act_make0, &act_wait, &act_make1 }; /* Line 48, Address: 0x101a7ac */


  if (eggwk->userflag.b.h != 0) { bomb(eggwk); return; } /* Line 51, Address: 0x101a7d8 */

  stack_pointer = 0; /* Line 53, Address: 0x101a804 */
  act_tbl[eggwk->r_no0 / 2](eggwk); /* Line 54, Address: 0x101a80c */
  if (stack_pointer != 0) return; /* Line 55, Address: 0x101a848 */
  actionsub(eggwk); /* Line 56, Address: 0x101a85c */
  if (eggwk->r_no0 <= 2) frameout_s(eggwk); /* Line 57, Address: 0x101a868 */
} /* Line 58, Address: 0x101a88c */



static void act_init(sprite_status* eggwk) { /* Line 62, Address: 0x101a8a0 */
  if (generate_flag != 0) { stack_pointer = 1; frameout(eggwk); return; } /* Line 63, Address: 0x101a8ac */


  eggwk->r_no0 += 2; /* Line 66, Address: 0x101a8e0 */
  eggwk->actflg |= 4; /* Line 67, Address: 0x101a8f0 */
  eggwk->sprpri = 3; /* Line 68, Address: 0x101a900 */
  eggwk->sprhs = eggwk->sprhsize = 20; /* Line 69, Address: 0x101a90c */
  eggwk->sprvsize = 28; /* Line 70, Address: 0x101a924 */

  eggwk->patbase = pat_egg6; /* Line 72, Address: 0x101a930 */
  eggwk->colino = 248; /* Line 73, Address: 0x101a940 */
  ((char**)eggwk)[12] = tbl0; /* Line 74, Address: 0x101a94c */
} /* Line 75, Address: 0x101a95c */



static void act_check(sprite_status* eggwk) { /* Line 79, Address: 0x101a970 */
  if (eggwk->colicnt != 0) { /* Line 80, Address: 0x101a97c */
    eggwk->colino = eggwk->colicnt = 0; /* Line 81, Address: 0x101a990 */
    eggwk->r_no0 += 2; /* Line 82, Address: 0x101a9a4 */
    if (hitchk(eggwk, &actwk[0])) ride_on_clr(eggwk, &actwk[0]); /* Line 83, Address: 0x101a9b4 */
  } /* Line 84, Address: 0x101a9e4 */
  else hitchk(eggwk, &actwk[0]); /* Line 85, Address: 0x101a9ec */
} /* Line 86, Address: 0x101aa00 */



static void act_make0(sprite_status* eggwk) { /* Line 90, Address: 0x101aa10 */
  char *tbl_address, tbl_data;
  short position_data_x, position_data_y;
  sprite_status* new_actwk;

  tbl_address = ((char**)eggwk)[12]; /* Line 95, Address: 0x101aa2c */
  if ((tbl_data = *tbl_address++) < 0) { /* Line 96, Address: 0x101aa34 */
    eggwk->r_no0 += 2; /* Line 97, Address: 0x101aa58 */
    eggwk->patno = 1; /* Line 98, Address: 0x101aa68 */
    eggwk->actfree[21] = 60; /* Line 99, Address: 0x101aa74 */
    return; /* Line 100, Address: 0x101aa80 */
  }
  if (tbl_data != ++eggwk->actfree[21]) return; /* Line 102, Address: 0x101aa88 */
  position_data_x = *tbl_address++; /* Line 103, Address: 0x101aab0 */
  position_data_y = *tbl_address++; /* Line 104, Address: 0x101aacc */
  ((char**)eggwk)[12] = tbl_address; /* Line 105, Address: 0x101aae8 */
  if (actwkchk(&new_actwk) != 0) return; /* Line 106, Address: 0x101aaf0 */
  new_actwk->actno = 24; /* Line 107, Address: 0x101ab04 */
  new_actwk->r_no1 = 1; /* Line 108, Address: 0x101ab10 */
  new_actwk->xposi.w.h = eggwk->xposi.w.h + position_data_x; /* Line 109, Address: 0x101ab1c */
  new_actwk->yposi.w.h = eggwk->yposi.w.h + position_data_y; /* Line 110, Address: 0x101ab48 */
  soundset(158); /* Line 111, Address: 0x101ab74 */
} /* Line 112, Address: 0x101ab80 */



static void act_wait(sprite_status* eggwk) { /* Line 116, Address: 0x101aba0 */
  if (--eggwk->actfree[21] == 0) eggwk->r_no0 += 2; /* Line 117, Address: 0x101aba8 */
} /* Line 118, Address: 0x101abd8 */



static void act_make1(sprite_status* eggwk) { /* Line 122, Address: 0x101abf0 */
  char* tbl_address;
  short data_x, data_y;
  sprite_status* new_actwk;

  tbl_address = tbl1; /* Line 127, Address: 0x101ac08 */
  while ((data_x = *tbl_address++) != -1) { /* Line 128, Address: 0x101ac10 */
    data_y = *tbl_address++; /* Line 129, Address: 0x101ac18 */
    if (actwkchk(&new_actwk) != 0) { frameout(eggwk); return; } /* Line 130, Address: 0x101ac34 */
    new_actwk->actno = eggwk->actno; /* Line 131, Address: 0x101ac5c */
    new_actwk->userflag.b.h = -1; /* Line 132, Address: 0x101ac6c */
    new_actwk->xposi.w.h = eggwk->xposi.w.h + data_x; /* Line 133, Address: 0x101ac78 */
    new_actwk->yposi.w.h = eggwk->yposi.w.h + data_y - 160; /* Line 134, Address: 0x101aca4 */
    ((short*)new_actwk)[25] = eggwk->yposi.w.h + 38; /* Line 135, Address: 0x101acd4 */

  }; /* Line 137, Address: 0x101acf8 */
  frameout(eggwk); /* Line 138, Address: 0x101ad30 */
} /* Line 139, Address: 0x101ad3c */









void bomb(sprite_status* bombwk) { /* Line 149, Address: 0x101ad60 */
  void(*bomb_tbl[3])(sprite_status*) = { &bomb_init, &bomb_fall, &bomb_die }; /* Line 150, Address: 0x101ad6c */

  bomb_tbl[bombwk->r_no0 / 2](bombwk); /* Line 152, Address: 0x101ad90 */
  actionsub(bombwk); /* Line 153, Address: 0x101adcc */
} /* Line 154, Address: 0x101add8 */



static void bomb_init(sprite_status* bombwk) { /* Line 158, Address: 0x101adf0 */
  bombwk->r_no0 += 2; /* Line 159, Address: 0x101adf8 */
  bombwk->actflg |= 4; /* Line 160, Address: 0x101ae08 */
  bombwk->sprpri = 3; /* Line 161, Address: 0x101ae18 */
  bombwk->sprvsize = bombwk->sprhs = bombwk->sprhsize = 6; /* Line 162, Address: 0x101ae24 */

  bombwk->patbase = pat_bomb; /* Line 164, Address: 0x101ae48 */
  bombwk->colino = 183; /* Line 165, Address: 0x101ae58 */
  *(int*)&bombwk->actfree[0] = 0; /* Line 166, Address: 0x101ae64 */
} /* Line 167, Address: 0x101ae70 */



static void bomb_fall(sprite_status* bombwk) { /* Line 171, Address: 0x101ae80 */
  bombwk->yposi.l += *(int*)&bombwk->actfree[0]; /* Line 172, Address: 0x101ae8c */
  *(int*)&bombwk->actfree[0] += 1024; /* Line 173, Address: 0x101aea8 */
  if (bombwk->yposi.w.h >= ((short*)bombwk)[25]) /* Line 174, Address: 0x101aec0 */
    bombwk->r_no0 += 2; /* Line 175, Address: 0x101aeec */
  patchg(bombwk, pchg_bomb); /* Line 176, Address: 0x101aefc */
} /* Line 177, Address: 0x101af10 */



static void bomb_die(sprite_status* bombwk) { /* Line 181, Address: 0x101af20 */
  bombwk->actno = 24; /* Line 182, Address: 0x101af2c */
  bombwk->r_no0 = 0; /* Line 183, Address: 0x101af38 */
  bombwk->r_no1 = 1; /* Line 184, Address: 0x101af40 */
  soundset(158); /* Line 185, Address: 0x101af4c */
} /* Line 186, Address: 0x101af58 */
