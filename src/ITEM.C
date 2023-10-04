#include "EQU.H"
#include "ITEM.H"
#include "ACTION.H"
#include "ACTSET.H"
#include "DIRCOL.H"
#include "PLAYSUB.H"
#include "RIDECHK.H"

extern void sub_sync(short ReqNo);
extern void soundset(short ReqNo);

unsigned char itemchg0[11] = { 1, 16, 0, 0, 8, 0, 0, 9, 0, 0, 255 };
unsigned char itemchg1[11] = { 1, 16, 1, 1, 8, 1, 1, 9, 1, 1, 255 };
unsigned char itemchg2[11] = { 1, 16, 2, 2, 8, 2, 2, 9, 2, 2, 255 };
unsigned char itemchg3[11] = { 1, 16, 3, 3, 8, 3, 3, 9, 3, 3, 255 };
unsigned char itemchg4[11] = { 1, 16, 4, 4, 8, 4, 4, 9, 4, 4, 255 };
unsigned char itemchg5[11] = { 1, 16, 5, 5, 8, 5, 5, 9, 5, 5, 255 };
unsigned char itemchg6[11] = { 1, 16, 6, 6, 8, 6, 6, 9, 6, 6, 255 };
unsigned char itemchg7[11] = { 1, 16, 7, 7, 8, 7, 7, 9, 7, 7, 255 };
unsigned char itemchg8[10] = { 1, 10, 14, 15, 14, 11, 14, 15, 14, 255 };
unsigned char itemchg9[10] = { 1, 12, 14, 15, 14, 13, 14, 15, 14, 255 };
unsigned char* itemchg[10] = { itemchg0, itemchg1, itemchg2, itemchg3, itemchg4, itemchg5, itemchg6, itemchg7, itemchg8, itemchg9 };
spr_array ite00 = {
  2,
  { { -8, -10, 0, 272 }, { -16, -16, 0, 286 } }
};
spr_array ite01 = {
  2,
  { { -8, -10, 0, 273 }, { -16, -16, 0, 286 } }
};
spr_array ite02 = {
  2,
  { { -8, -10, 0, 274 }, { -16, -16, 0, 286 } }
};
spr_array ite03 = {
  2,
  { { -8, -10, 0, 275 }, { -16, -16, 0, 286 } }
};
spr_array ite04 = {
  2,
  { { -8, -10, 0, 276 }, { -16, -16, 0, 286 } }
};
spr_array ite05 = {
  2,
  { { -8, -10, 0, 277 }, { -16, -16, 0, 286 } }
};
spr_array ite06 = {
  2,
  { { -8, -10, 0, 278 }, { -16, -16, 0, 286 } }
};
spr_array ite07 = {
  2,
  { { -8, -10, 0, 279 }, { -16, -16, 0, 286 } }
};
spr_array ite08 = {
  2,
  { { -8, -10, 0, 280 }, { -16, -16, 0, 286 } }
};
spr_array ite09 = {
  2,
  { { -8, -10, 8, 280 }, { -16, -16, 0, 286 } }
};
spr_array ite0a = {
  2,
  { { -16, -40, 0, 281 }, { -8, -24, 0, 285 } }
};
spr_array ite0b = {
  2,
  { { -16, -40, 8, 281 }, { -8, -24, 0, 285 } }
};
spr_array ite0c = {
  2,
  { { -16, -40, 0, 282 }, { -8, -24, 0, 285 } }
};
spr_array ite0d = {
  2,
  { { -16, -40, 8, 282 }, { -8, -24, 0, 285 } }
};
spr_array ite0e = {
  2,
  { { -16, -40, 8, 283 }, { -8, -24, 0, 285 } }
};
spr_array ite0f = {
  2,
  { { -4, -40, 8, 284 }, { -8, -24, 0, 285 } }
};
spr_array ite10 = {
  1, { { -16, -16, 0, 286 } }
};
spr_array ite11 = {
  1, { { -16, 0, 0, 287 } }
};
spr_array ite12 = {
  1, { { -16, -8, 0, 281 } }
};
spr_array ite13 = {
  1, { { -16, -8, 0, 282 } }
};
spr_array* itempat[20] = { &ite00, &ite01, &ite02, &ite03, &ite04, &ite05, &ite06, &ite07, &ite08, &ite09, &ite0a, &ite0b, &ite0c, &ite0d, &ite0e, &ite0f, &ite10, &ite11, &ite12, &ite13 };
spr_array cor00 = {
  1, { { -8, -16, 0, 272 } }
};
spr_array cor01 = {
  1, { { -8, -16, 0, 273 } }
};
spr_array cor02 = {
  1, { { -8, -16, 0, 274 } }
};
spr_array cor03 = {
  1, { { -8, -16, 0, 275 } }
};
spr_array cor04 = {
  1, { { -8, -16, 0, 276 } }
};
spr_array cor05 = {
  1, { { -8, -16, 0, 277 } }
};
spr_array cor06 = {
  1, { { -8, -16, 0, 278 } }
};
spr_array cor07 = {
  1, { { -8, -16, 0, 279 } }
};
spr_array cor08 = {
  1, { { -8, -16, 0, 280 } }
};
spr_array cor09 = {
  1, { { -8, -16, 8, 280 } }
};
spr_array cor0a = {
  1, { { -16, -40, 0, 281 } }
};
spr_array cor0b = {
  1, { { -16, -40, 8, 281 } }
};
spr_array cor0c = {
  1, { { -16, -40, 0, 282 } }
};
spr_array cor0d = {
  1, { { -16, -40, 8, 282 } }
};
spr_array cor0e = {
  1, { { -16, -40, 0, 283 } }
};
spr_array cor0f = {
  1, { { -4, -40, 0, 284 } }
};
spr_array* corepat[16] = { &cor00, &cor01, &cor02, &cor03, &cor04, &cor05, &cor06, &cor07, &cor08, &cor09, &cor0a, &cor0b, &cor0c, &cor0d, &cor0e, &cor0f };


















void timedisp(act_info* timewk) { /* Line 167, Address: 0x1010de0 */
  switch (timewk->r_no0) { /* Line 168, Address: 0x1010dec */
    case 0:
      td_init(timewk); /* Line 170, Address: 0x1010e14 */
      break; /* Line 171, Address: 0x1010e20 */
    case 2:
      td_move(timewk); /* Line 173, Address: 0x1010e28 */
      break;
  }


  if (time_item == 0) return; /* Line 178, Address: 0x1010e34 */
  if (backto_cnt < 90) actionsub(timewk); /* Line 179, Address: 0x1010e4c */
  else if ((gametimer.b.l & 2) == 0) actionsub(timewk); /* Line 180, Address: 0x1010e7c */
} /* Line 181, Address: 0x1010ea4 */


void td_init(act_info* timewk) { /* Line 184, Address: 0x1010ec0 */
  timewk->r_no0 += 2; /* Line 185, Address: 0x1010ecc */
  timewk->patbase = itempat; /* Line 186, Address: 0x1010edc */
  timewk->sproffset = 32768; /* Line 187, Address: 0x1010eec */
  timewk->xposi.w.h = 196; /* Line 188, Address: 0x1010ef8 */
  timewk->yposi.w.h = 338; /* Line 189, Address: 0x1010f04 */
  td_move(timewk); /* Line 190, Address: 0x1010f10 */
} /* Line 191, Address: 0x1010f1c */


void td_move(act_info* timewk) { /* Line 194, Address: 0x1010f30 */
  timewk->patno = 18; /* Line 195, Address: 0x1010f38 */
  if (time_item >= 0) timewk->patno = 19; /* Line 196, Address: 0x1010f44 */
} /* Line 197, Address: 0x1010f68 */







void t_item(act_info* t_itemwk) { /* Line 205, Address: 0x1010f80 */
  if (ta_flag != 0) { frameout(t_itemwk); return; } /* Line 206, Address: 0x1010f8c */
  if (t_itemwk->userflag.b.h == 10) { timedisp(t_itemwk); return; } /* Line 207, Address: 0x1010fb4 */
  switch (t_itemwk->r_no0) { /* Line 208, Address: 0x1010fe4 */
    case 0:
      t_item_init(t_itemwk); /* Line 210, Address: 0x1011024 */
      break; /* Line 211, Address: 0x1011030 */
    case 2:
      t_item_move0(t_itemwk); /* Line 213, Address: 0x1011038 */
      break; /* Line 214, Address: 0x1011044 */
    case 4:
      t_item_move1(t_itemwk); /* Line 216, Address: 0x101104c */
      break; /* Line 217, Address: 0x1011058 */
    case 6:
      t_item_move2(t_itemwk); /* Line 219, Address: 0x1011060 */
      break;
  }


  actionsub(t_itemwk); /* Line 224, Address: 0x101106c */
  frameout_s(t_itemwk); /* Line 225, Address: 0x1011078 */
} /* Line 226, Address: 0x1011084 */


void t_item_init(act_info* t_itemwk) { /* Line 229, Address: 0x10110a0 */
  short flag_no;

  t_itemwk->r_no0 += 2; /* Line 232, Address: 0x10110b0 */
  t_itemwk->sprvsize = 32; /* Line 233, Address: 0x10110c0 */
  t_itemwk->sprhs = 14; /* Line 234, Address: 0x10110cc */
  t_itemwk->patbase = itempat; /* Line 235, Address: 0x10110d8 */

  t_itemwk->actflg = 4; /* Line 237, Address: 0x10110e8 */
  t_itemwk->sprpri = 3; /* Line 238, Address: 0x10110f4 */
  if (stageno.b.h == 6 && t_itemwk->userflag.b.l == 0) /* Line 239, Address: 0x1011100 */
    t_itemwk->sprpri = 0, t_itemwk->sproffset = 32768; /* Line 240, Address: 0x1011134 */
  t_itemwk->sprhsize = 15; /* Line 241, Address: 0x1011148 */
  t_itemwk->mstno.b.h = t_itemwk->userflag.b.h; /* Line 242, Address: 0x1011154 */

  flag_no = flagwkadr(t_itemwk); /* Line 244, Address: 0x1011164 */
  flagwork[flag_no] %= 128; /* Line 245, Address: 0x1011178 */

  t_itemwk->patno = 10; /* Line 247, Address: 0x1011198 */
  if (t_itemwk->userflag.b.h != 8) t_itemwk->patno += 2; /* Line 248, Address: 0x10111a4 */

  if (flagwork[flag_no] & 1) { /* Line 250, Address: 0x10111d0 */
    ++t_itemwk->patno; /* Line 251, Address: 0x10111f8 */
    t_itemwk->r_no0 = 6; /* Line 252, Address: 0x1011208 */
  } else { /* Line 253, Address: 0x1011214 */
    t_itemwk->colino = 223; /* Line 254, Address: 0x101121c */
    t_item_move0(t_itemwk); /* Line 255, Address: 0x1011228 */
  }
} /* Line 257, Address: 0x1011234 */


void t_item_move0(act_info* t_itemwk) { /* Line 260, Address: 0x1011250 */
  short flag_no;









  if (t_itemwk->colicnt == 0) return; /* Line 271, Address: 0x1011260 */
  t_itemwk->colicnt = 0; /* Line 272, Address: 0x1011274 */
  if (stageno.b.h == 6) { /* Line 273, Address: 0x101127c */
    if (t_itemwk->userflag.b.l != 0) { /* Line 274, Address: 0x1011298 */

      if (prio_flag == 0) return; /* Line 276, Address: 0x10112b0 */
    } /* Line 277, Address: 0x10112c4 */
    else {
      if (prio_flag != 0) return; /* Line 279, Address: 0x10112cc */
    }
  }

  t_itemwk->actfree[0] = 0; /* Line 283, Address: 0x10112e0 */
  t_itemwk->actfree[1] = 60; /* Line 284, Address: 0x10112e8 */
  t_itemwk->r_no0 += 2; /* Line 285, Address: 0x10112f4 */
  flag_no = flagwkadr(t_itemwk); /* Line 286, Address: 0x1011304 */
  flagwork[flag_no] |= 1; /* Line 287, Address: 0x1011318 */
  if (t_itemwk->userflag.b.h != 8) { /* Line 288, Address: 0x1011338 */
    time_item = 1; /* Line 289, Address: 0x1011354 */
    sub_sync(118); /* Line 290, Address: 0x1011360 */
  } else { /* Line 291, Address: 0x101136c */
    time_item = -1; /* Line 292, Address: 0x1011374 */
    sub_sync(119); /* Line 293, Address: 0x1011380 */
  }
} /* Line 295, Address: 0x101138c */


void t_item_move1(act_info* t_itemwk) { /* Line 298, Address: 0x10113a0 */
  if (--t_itemwk->actfree[1] != 0) { /* Line 299, Address: 0x10113ac */
    patchg(t_itemwk, itemchg); /* Line 300, Address: 0x10113cc */
    return; /* Line 301, Address: 0x10113e0 */
  }
  t_itemwk->r_no0 += 2; /* Line 303, Address: 0x10113e8 */
  t_itemwk->patno = 11; /* Line 304, Address: 0x10113f8 */
  if (t_itemwk->userflag.b.h != 8) t_itemwk->patno += 2; /* Line 305, Address: 0x1011404 */
} /* Line 306, Address: 0x1011430 */


void t_item_move2(act_info* t_itemwk) { /* Line 309, Address: 0x1011440 */
  unsigned char action_no;
  action_no = t_itemwk->actno; /* Line 311, Address: 0x101144c */
} /* Line 312, Address: 0x1011458 */


short flagwkadr(act_info* t_itemwk) { /* Line 315, Address: 0x1011470 */
  short flag_no, t_flag, t_item;

  flag_no = t_itemwk->cdsts, flag_no *= 3; /* Line 318, Address: 0x1011484 */
  t_flag = time_flag; /* Line 319, Address: 0x10114a8 */
  if ((t_flag & 128) == 0) return flag_no += t_flag; /* Line 320, Address: 0x10114bc */
  t_flag &= -129; /* Line 321, Address: 0x10114e8 */
  t_item = time_item; /* Line 322, Address: 0x10114f8 */
  t_item = -t_item; /* Line 323, Address: 0x1011510 */
  t_flag += t_item; /* Line 324, Address: 0x101152c */
  if (t_flag < 0) return flag_no; /* Line 325, Address: 0x1011538 */
  if (t_flag >= 3) t_flag = 2; /* Line 326, Address: 0x1011554 */
  flag_no += t_flag; /* Line 327, Address: 0x1011574 */
  return flag_no; /* Line 328, Address: 0x1011580 */
} /* Line 329, Address: 0x1011584 */




void ride_on_chk_i(act_info* itemwk) { /* Line 334, Address: 0x10115a0 */
  if (stageno.b.h == 6) { /* Line 335, Address: 0x10115ac */
    if (prio_flag != 0) { /* Line 336, Address: 0x10115c8 */

      if (itemwk->userflag.b.l == 0) return; /* Line 338, Address: 0x10115dc */
    } /* Line 339, Address: 0x10115f4 */
    else {

      if (itemwk->userflag.b.l != 0) return; /* Line 342, Address: 0x10115fc */
    }
  }
  ride_on_chk(itemwk, &actwk[0]); /* Line 345, Address: 0x1011614 */
} /* Line 346, Address: 0x1011628 */







void item(act_info* itemwk) { /* Line 354, Address: 0x1011640 */
  if (itemwk->userflag.b.h == 0 && ta_flag != 0) { /* Line 355, Address: 0x101164c */
    frameout_s(itemwk); return; /* Line 356, Address: 0x1011678 */
  }
  if (itemwk->userflag.b.h >= 8) { t_item(itemwk); return; } /* Line 358, Address: 0x101168c */
  switch (itemwk->r_no0) { /* Line 359, Address: 0x10116bc */
    case 0:
      iteminit(itemwk); /* Line 361, Address: 0x1011708 */
      break; /* Line 362, Address: 0x1011714 */
    case 2:
      itemmove(itemwk); /* Line 364, Address: 0x101171c */
      break; /* Line 365, Address: 0x1011728 */
    case 4:
      itemget(itemwk); /* Line 367, Address: 0x1011730 */
      break; /* Line 368, Address: 0x101173c */
    case 6:
      itemmove2(itemwk); /* Line 370, Address: 0x1011744 */
      break; /* Line 371, Address: 0x1011750 */
    case 8:
      itemmove3(itemwk); /* Line 373, Address: 0x1011758 */
      break;
  }


} /* Line 378, Address: 0x1011764 */


void iteminit(act_info* itemwk) { /* Line 381, Address: 0x1011780 */
  short flag_no;

  itemwk->r_no0 += 2; /* Line 384, Address: 0x1011790 */
  itemwk->sprvsize = 14; /* Line 385, Address: 0x10117a0 */
  itemwk->sprhs = 14; /* Line 386, Address: 0x10117ac */
  itemwk->patbase = itempat; /* Line 387, Address: 0x10117b8 */

  itemwk->sprpri = 3; /* Line 389, Address: 0x10117c8 */
  if (stageno.b.h == 6 && itemwk->userflag.b.l == 0) /* Line 390, Address: 0x10117d4 */
    itemwk->sprpri = 0, itemwk->sproffset = 32768; /* Line 391, Address: 0x1011808 */
  itemwk->actflg = 4; /* Line 392, Address: 0x101181c */
  itemwk->sprhsize = 15; /* Line 393, Address: 0x1011828 */

  flag_no = flagwkadr(itemwk); /* Line 395, Address: 0x1011834 */
  flagwork[flag_no] %= 128; /* Line 396, Address: 0x1011848 */
  if (flagwork[flag_no] & 1) { /* Line 397, Address: 0x1011868 */
    itemwk->r_no0 = 8; /* Line 398, Address: 0x1011890 */
    itemwk->patno = 17; /* Line 399, Address: 0x101189c */
    return; /* Line 400, Address: 0x10118a8 */
  }
  itemwk->colino = 70; /* Line 402, Address: 0x10118b0 */
  itemwk->mstno.b.h = itemwk->userflag.b.h; /* Line 403, Address: 0x10118bc */
  if (itemwk->patno == 0) itemwk->patno = 16; /* Line 404, Address: 0x10118cc */

  itemmove(itemwk); /* Line 406, Address: 0x10118ec */
} /* Line 407, Address: 0x10118f8 */


void itemmove(act_info* itemwk) { /* Line 410, Address: 0x1011910 */
  short col_ofs;


  if (itemwk->patbase != itempat) { /* Line 414, Address: 0x1011920 */
    error_item(itemwk); return; /* Line 415, Address: 0x1011938 */
  }
  if (itemwk->actflg >= 0) { itemmove3(itemwk); return; } /* Line 417, Address: 0x101194c */
  if (itemwk->r_no1 != 0) { /* Line 418, Address: 0x1011980 */
    speedset(itemwk); /* Line 419, Address: 0x1011994 */
    if ((col_ofs = emycol_d(itemwk)) < 0) { /* Line 420, Address: 0x10119a0 */
      itemwk->yposi.w.h += col_ofs; /* Line 421, Address: 0x10119cc */
      itemwk->yspeed.w = 0; /* Line 422, Address: 0x10119dc */
      itemwk->r_no1 = 0; /* Line 423, Address: 0x10119e4 */
    }
  } /* Line 425, Address: 0x10119ec */
  else if (itemwk->actflg < 0) ride_on_chk_i(itemwk); /* Line 426, Address: 0x10119f4 */

  itemmove2(itemwk); /* Line 428, Address: 0x1011a20 */







} /* Line 436, Address: 0x1011a2c */


void itemmove2(act_info* itemwk) { /* Line 439, Address: 0x1011a40 */
  if (time_stop == 0) patchg(itemwk, itemchg); /* Line 440, Address: 0x1011a4c */
  itemmove3(itemwk); /* Line 441, Address: 0x1011a78 */
} /* Line 442, Address: 0x1011a84 */


void itemmove3(act_info* itemwk) { /* Line 445, Address: 0x1011aa0 */
  actionsub(itemwk); /* Line 446, Address: 0x1011aac */
  frameout_s(itemwk); /* Line 447, Address: 0x1011ab8 */
} /* Line 448, Address: 0x1011ac4 */


void itemget(act_info* itemwk) { /* Line 451, Address: 0x1011ae0 */
  act_info* new_actwk;
  short flag_no;



  soundset(150); /* Line 457, Address: 0x1011af0 */
  itemwk->r_no0 += 4; /* Line 458, Address: 0x1011afc */
  itemwk->colino = 0; /* Line 459, Address: 0x1011b0c */
  if (actwkchk(&new_actwk) == 0) { /* Line 460, Address: 0x1011b14 */
    new_actwk->actno = 26; /* Line 461, Address: 0x1011b28 */
    new_actwk->xposi.w.h = itemwk->xposi.w.h; /* Line 462, Address: 0x1011b34 */
    new_actwk->yposi.w.h = itemwk->yposi.w.h; /* Line 463, Address: 0x1011b44 */
    new_actwk->mstno.b.h = itemwk->mstno.b.h; /* Line 464, Address: 0x1011b54 */
    new_actwk->userflag.b.l = itemwk->userflag.b.l; /* Line 465, Address: 0x1011b64 */
  }
  if (actwkchk(&new_actwk) == 0) { /* Line 467, Address: 0x1011b74 */
    new_actwk->actno = 24; /* Line 468, Address: 0x1011b88 */
    new_actwk->xposi.w.h = itemwk->xposi.w.h; /* Line 469, Address: 0x1011b94 */
    new_actwk->yposi.w.h = itemwk->yposi.w.h; /* Line 470, Address: 0x1011ba4 */
    new_actwk->r_no1 = 1; /* Line 471, Address: 0x1011bb4 */
    new_actwk->userflag.b.h = 1; /* Line 472, Address: 0x1011bc0 */
    new_actwk->userflag.b.l = itemwk->userflag.b.l; /* Line 473, Address: 0x1011bcc */
  }
  flag_no = flagwkadr(itemwk); /* Line 475, Address: 0x1011bdc */
  flagwork[flag_no] |= 1; /* Line 476, Address: 0x1011bf0 */
  itemwk->patno = 17; /* Line 477, Address: 0x1011c10 */
  actionsub(itemwk); /* Line 478, Address: 0x1011c1c */
} /* Line 479, Address: 0x1011c28 */



void powerup_init(act_info* powerwk) { /* Line 483, Address: 0x1011c40 */
  powerwk->r_no0 = 0; /* Line 484, Address: 0x1011c48 */
  powerwk->mstno.w = 0; /* Line 485, Address: 0x1011c50 */
} /* Line 486, Address: 0x1011c58 */





void item2(act_info* itemwk) { /* Line 492, Address: 0x1011c70 */
  switch (itemwk->r_no0) { /* Line 493, Address: 0x1011c7c */
    case 0:
      item2init(itemwk); /* Line 495, Address: 0x1011cb0 */
      break; /* Line 496, Address: 0x1011cbc */
    case 2:
      item2move(itemwk); /* Line 498, Address: 0x1011cc4 */
      break; /* Line 499, Address: 0x1011cd0 */
    case 4:
      item2die(itemwk); /* Line 501, Address: 0x1011cd8 */
      break;
  }


  actionsub(itemwk); /* Line 506, Address: 0x1011ce4 */
} /* Line 507, Address: 0x1011cf0 */


void item2init(act_info* itemwk) { /* Line 510, Address: 0x1011d00 */
  itemwk->r_no0 += 2; /* Line 511, Address: 0x1011d0c */
  itemwk->sproffset = 32768; /* Line 512, Address: 0x1011d1c */

  itemwk->actflg = 4; /* Line 514, Address: 0x1011d28 */
  itemwk->sprpri = 3; /* Line 515, Address: 0x1011d34 */
  itemwk->sprhsize = 8; /* Line 516, Address: 0x1011d40 */
  itemwk->yspeed.w = -768; /* Line 517, Address: 0x1011d4c */
  itemwk->patno = itemwk->mstno.b.h; /* Line 518, Address: 0x1011d58 */
  itemwk->patbase = corepat; /* Line 519, Address: 0x1011d68 */
  item2move(itemwk); /* Line 520, Address: 0x1011d78 */
} /* Line 521, Address: 0x1011d84 */


void item2move(act_info* itemwk) { /* Line 524, Address: 0x1011da0 */
  if (itemwk->yspeed.w < 0) { /* Line 525, Address: 0x1011dac */
    speedset2(itemwk); /* Line 526, Address: 0x1011dc4 */
    itemwk->yspeed.w += 24; /* Line 527, Address: 0x1011dd0 */
    return; /* Line 528, Address: 0x1011de0 */
  }
  itemwk->r_no0 += 2; /* Line 530, Address: 0x1011de8 */
  itemwk->pattim = 29; /* Line 531, Address: 0x1011df8 */
  switch (itemwk->mstno.b.h) { /* Line 532, Address: 0x1011e04 */
    case 0:
      ++pl_suu, ++pl_suu_f; /* Line 534, Address: 0x1011e3c */
      sub_sync(122); /* Line 535, Address: 0x1011e64 */
      break; /* Line 536, Address: 0x1011e70 */
    case 1:
      plring += 10; /* Line 538, Address: 0x1011e78 */
      plring_f |= 1; /* Line 539, Address: 0x1011e8c */
      if ((plring >= 100 && (plring_f2 & 2) == 0) || (plring >= 200 && (plring_f2 & 4) == 0)) { /* Line 540, Address: 0x1011ea0 */

        if (plring < 200) plring_f2 |= 2; /* Line 542, Address: 0x1011f08 */
        else plring_f2 |= 4; /* Line 543, Address: 0x1011f40 */
        ++pl_suu, ++pl_suu_f; /* Line 544, Address: 0x1011f54 */
        sub_sync(122); /* Line 545, Address: 0x1011f7c */
      } else { /* Line 546, Address: 0x1011f88 */
        soundset(149); /* Line 547, Address: 0x1011f90 */
      }
      break; /* Line 549, Address: 0x1011f9c */
    case 2:
      plpower_b = 1; /* Line 551, Address: 0x1011fa4 */
      powerup_init(&actwk[6]); /* Line 552, Address: 0x1011fb0 */
      actwk[6].actno = 3; /* Line 553, Address: 0x1011fc0 */
      soundset(151); /* Line 554, Address: 0x1011fcc */
      break; /* Line 555, Address: 0x1011fd8 */
    case 3:
      plpower_m = 1; /* Line 557, Address: 0x1011fe0 */
      *(short*)&actwk[0].actfree[8] = 1320; /* Line 558, Address: 0x1011fec */
      powerup_init(&actwk[8]); /* Line 559, Address: 0x1011ff8 */
      actwk[8].actno = 3; /* Line 560, Address: 0x1012008 */
      actwk[8].mstno.b.h = 1; /* Line 561, Address: 0x1012014 */
      powerup_init(&actwk[9]); /* Line 562, Address: 0x1012020 */
      actwk[9].actno = 3; /* Line 563, Address: 0x1012030 */
      actwk[9].mstno.b.h = 2; /* Line 564, Address: 0x101203c */
      powerup_init(&actwk[10]); /* Line 565, Address: 0x1012048 */
      actwk[10].actno = 3; /* Line 566, Address: 0x1012058 */
      actwk[10].mstno.b.h = 3, actwk[10].r_no0 = 0; /* Line 567, Address: 0x1012064 */
      powerup_init(&actwk[11]); /* Line 568, Address: 0x1012078 */
      actwk[11].actno = 3; /* Line 569, Address: 0x1012088 */
      actwk[11].mstno.b.h = 4, actwk[11].r_no0 = 0; /* Line 570, Address: 0x1012094 */
      if (time_flag == 0) { /* Line 571, Address: 0x10120a8 */
        sub_sync(130); /* Line 572, Address: 0x10120bc */
      }
      sub_sync(109); /* Line 574, Address: 0x10120c8 */
      break; /* Line 575, Address: 0x10120d4 */
    case 4:
      plpower_s = 1; /* Line 577, Address: 0x10120dc */
      *(short*)&actwk[0].actfree[10] = 1320; /* Line 578, Address: 0x10120e8 */
      plmaxspdwk = 3072; /* Line 579, Address: 0x10120f4 */
      pladdspdwk = 24; /* Line 580, Address: 0x1012100 */
      plretspdwk = 128; /* Line 581, Address: 0x101210c */
      if (time_flag == 0) { /* Line 582, Address: 0x1012118 */
        sub_sync(130); /* Line 583, Address: 0x101212c */
      }
      sub_sync(108); /* Line 585, Address: 0x1012138 */
      break; /* Line 586, Address: 0x1012144 */
    case 5:
      time_stop = 300; /* Line 588, Address: 0x101214c */
      break; /* Line 589, Address: 0x1012158 */
    case 6:
      soundset(157); /* Line 591, Address: 0x1012160 */
      conbine_flag = 1; /* Line 592, Address: 0x101216c */
      break; /* Line 593, Address: 0x1012178 */
    default:
      plpower_b = 1; /* Line 595, Address: 0x1012180 */
      powerup_init(&actwk[6]); /* Line 596, Address: 0x101218c */
      actwk[6].actno = 3; /* Line 597, Address: 0x101219c */
      plpower_m = 1; /* Line 598, Address: 0x10121a8 */
      *(short*)&actwk[0].actfree[8] = 1320; /* Line 599, Address: 0x10121b4 */
      powerup_init(&actwk[8]); /* Line 600, Address: 0x10121c0 */
      actwk[8].actno = 3; /* Line 601, Address: 0x10121d0 */
      actwk[8].mstno.b.h = 1; /* Line 602, Address: 0x10121dc */
      powerup_init(&actwk[9]); /* Line 603, Address: 0x10121e8 */
      actwk[9].actno = 3; /* Line 604, Address: 0x10121f8 */
      actwk[9].mstno.b.h = 2; /* Line 605, Address: 0x1012204 */
      powerup_init(&actwk[10]); /* Line 606, Address: 0x1012210 */
      actwk[10].actno = 3; /* Line 607, Address: 0x1012220 */
      actwk[10].mstno.b.h = 3; /* Line 608, Address: 0x101222c */
      powerup_init(&actwk[11]); /* Line 609, Address: 0x1012238 */
      actwk[11].actno = 3; /* Line 610, Address: 0x1012248 */
      actwk[11].mstno.b.h = 4; /* Line 611, Address: 0x1012254 */
      plpower_s = 1; /* Line 612, Address: 0x1012260 */
      *(short*)&actwk[0].actfree[10] = 1320; /* Line 613, Address: 0x101226c */
      plmaxspdwk = 3072; /* Line 614, Address: 0x1012278 */
      pladdspdwk = 24; /* Line 615, Address: 0x1012284 */
      plretspdwk = 128; /* Line 616, Address: 0x1012290 */
      break;
  }
} /* Line 619, Address: 0x101229c */


void item2die(act_info* itemwk) { /* Line 622, Address: 0x10122b0 */
  if (--itemwk->pattim == 255) frameout(itemwk); /* Line 623, Address: 0x10122bc */
} /* Line 624, Address: 0x10122ec */


void error_item(act_info* itemwk) { /* Line 627, Address: 0x1012300 */






  ((int)itemwk->patbase ^ (int)corepat) < 1U; /* Line 634, Address: 0x1012308 */





  itemwk->patbase = itempat; /* Line 640, Address: 0x1012320 */
} /* Line 641, Address: 0x1012330 */
