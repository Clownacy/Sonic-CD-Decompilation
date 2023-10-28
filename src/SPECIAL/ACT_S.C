#include "..\TYPES.H"
#include "SPS_EQU.H"
#include "ACT_S.H"
#include "ENS.H"
#include "PLS.H"

static void(*act_tbl[16])(sprite_status_sp*) = {
  &player,
  &ufo0,
  &timeufo,
  &item_ring,
  &kage,
  &plkage,
  &kemuri,
  &sibuki,
  &press,
  &title_logo,
  &title_obi,
  &explosion,
  &bara_ring,
  &time_stone,
  &tskira0,
  &tskira1
};
extern void(*EAsprset)(short, short, unsigned short, unsigned short, unsigned short);
extern void(*sMemSet)(void*, unsigned char, int);
extern bmp_info SprBmp[700];










void action() { /* Line 38, Address: 0x1000000 */
  short i;

  linkdata = 0; /* Line 41, Address: 0x100000c */
  zbuf_init(); /* Line 42, Address: 0x1000014 */

  for (i = 0; i < 14; ++i) actmain(&actwk[i + 2]); /* Line 44, Address: 0x100001c */

  actmain(&actwk[0]); /* Line 46, Address: 0x1000074 */
  actmain(&actwk[1]); /* Line 47, Address: 0x1000084 */

  for (i = 0; i < 24; ++i) actmain(&actwk[i + 16]); /* Line 49, Address: 0x1000094 */








  zbuf_patset(); /* Line 58, Address: 0x10000ec */

  for (i = 0; i < 8; ++i) actmain(&actwk[i + 40]); /* Line 60, Address: 0x10000f4 */

  for (i = linkdata; i < 80; ++i) { /* Line 62, Address: 0x100014c */
    EAsprset(0, 0, 0, i, 0); /* Line 63, Address: 0x100016c */
  } /* Line 64, Address: 0x1000190 */
} /* Line 65, Address: 0x10001b0 */



void actmain(sprite_status_sp* work) { /* Line 69, Address: 0x10001d0 */
  if (work->actno == 0) return; /* Line 70, Address: 0x10001dc */
  act_tbl[work->actno - 1](work); /* Line 71, Address: 0x10001f0 */
  if ((work->actflg & 1) == 0) return; /* Line 72, Address: 0x1000220 */
  sMemSet(work, 0, sizeof(sprite_status_sp)); /* Line 73, Address: 0x1000238 */
} /* Line 74, Address: 0x1000254 */





void zbuf_init() { /* Line 80, Address: 0x1000270 */
  short i;

  for (i = 0; i < 512; i += 8) z_buffer[i] = 0; /* Line 83, Address: 0x1000278 */
} /* Line 84, Address: 0x10002c0 */








void zbuf_set(sprite_status_sp* work, int length) { /* Line 93, Address: 0x10002d0 */
  short i = 0; /* Line 94, Address: 0x10002e0 */

  if (length >= 4096) length = 4095; /* Line 96, Address: 0x10002e4 */
  length = (length * 4 & 1008) / 2; /* Line 97, Address: 0x10002fc */


  for (i = 0; i < 7; ++i) { /* Line 100, Address: 0x1000324 */
    if (z_buffer[i] == 0) break; /* Line 101, Address: 0x1000330 */
  } /* Line 102, Address: 0x1000360 */
  z_buffer[length] = work - actwk; /* Line 103, Address: 0x1000380 */
  z_buffer[length + 1] = 0; /* Line 104, Address: 0x10003d0 */
} /* Line 105, Address: 0x10003f8 */





void zbuf_patset() { /* Line 111, Address: 0x1000410 */
  short i;

  for (i = 0; i < 512; i += 8) zpatset(i); /* Line 114, Address: 0x100041c */
} /* Line 115, Address: 0x1000454 */


void zpatset(short z_buffer_start) { /* Line 118, Address: 0x1000470 */
  short i;

  for (i = 0; i < 8; ++i) /* Line 121, Address: 0x1000480 */
    if (zpatset_call(z_buffer_start + i) != 0) break;; /* Line 122, Address: 0x100048c */
} /* Line 123, Address: 0x10004e4 */


short zpatset_call(short z_buffer_number) { /* Line 126, Address: 0x1000500 */
  unsigned short actwk_number;
  if ((actwk_number = z_buffer[z_buffer_number]) == 0) return 1; /* Line 128, Address: 0x1000510 */

  patset(&actwk[actwk_number]); /* Line 130, Address: 0x100054c */
  return 0; /* Line 131, Address: 0x1000570 */
} /* Line 132, Address: 0x1000574 */











void patinit(sprite_status_sp* work, unsigned char pattbl_number) { /* Line 144, Address: 0x1000590 */
  sprite_patterns_sp** patchg_tbl;
  sprite_patterns_sp* patchg;

  work->pattblno = pattbl_number; /* Line 148, Address: 0x10005a4 */
  work->patno = 0; /* Line 149, Address: 0x10005b0 */
  patchg_tbl = work->pattbl; /* Line 150, Address: 0x10005b8 */
  patchg = patchg_tbl[pattbl_number]; /* Line 151, Address: 0x10005c0 */
  work->pctime = work->pctime_b = patchg->timer; /* Line 152, Address: 0x10005d4 */

} /* Line 154, Address: 0x10005e8 */


void patinit1(sprite_status_sp* work, unsigned char pattbl_number) { /* Line 157, Address: 0x1000600 */
  sprite_patterns_sp** patchg_tbl;
  sprite_patterns_sp* patchg;

  work->pattblno = pattbl_number; /* Line 161, Address: 0x1000614 */
  patchg_tbl = work->pattbl; /* Line 162, Address: 0x1000620 */
  patchg = patchg_tbl[pattbl_number]; /* Line 163, Address: 0x1000628 */
  work->pctime = work->pctime_b = patchg->timer; /* Line 164, Address: 0x100063c */

} /* Line 166, Address: 0x1000650 */





void patset(sprite_status_sp* work) { /* Line 172, Address: 0x1000670 */
  sprite_patterns_sp** patchg_tbl;
  sprite_patterns_sp* patchg;
  spr_array* sprpat_adr;

  if (work->actno == 0) return; /* Line 177, Address: 0x1000688 */
  patchg_tbl = work->pattbl; /* Line 178, Address: 0x1000698 */
  patchg = patchg_tbl[work->pattblno]; /* Line 179, Address: 0x10006a0 */
  if (work->patno >= patchg->cnt) work->patno = 0; /* Line 180, Address: 0x10006b8 */
  if ((work->actflg & 2) == 0) { /* Line 181, Address: 0x10006e0 */
    if (--work->pctime < 0) { /* Line 182, Address: 0x10006f8 */
      work->pctime = patchg->timer; /* Line 183, Address: 0x1000720 */
      if (++work->patno >= patchg->cnt) work->patno = 0; /* Line 184, Address: 0x100072c */
    }
  }
  if (work->actflg & 4) return; /* Line 187, Address: 0x1000760 */
  sprpat_adr = patchg->spr[work->patno]; /* Line 188, Address: 0x1000778 */
  if (sprpat_adr->cnt == 0) return; /* Line 189, Address: 0x1000790 */




  n_patset(work, sprpat_adr); /* Line 194, Address: 0x10007a0 */

} /* Line 196, Address: 0x10007b0 */



void n_patset(sprite_status_sp* work, spr_array* sprpat_adr) { /* Line 200, Address: 0x10007d0 */
  short x_posi, y_posi, i, sx, sy;
  unsigned short rev;
  spr_info sprdat;

  if (linkdata >= 80) return; /* Line 205, Address: 0x10007f8 */

  for (i = 0; i < sprpat_adr->cnt; ++i) { /* Line 207, Address: 0x1000810 */
    sprdat = sprpat_adr->spra[i]; /* Line 208, Address: 0x100081c */

    sx = work->sx_posi.w.h * 5 / 4 - 32; /* Line 210, Address: 0x1000858 */
    sy = work->sy_posi.w.h; /* Line 211, Address: 0x100089c */

    switch (sprdat.etc & 24) { /* Line 213, Address: 0x10008ac */
      case 0:
        y_posi = sy + sprdat.yoff; /* Line 215, Address: 0x10008ec */
        x_posi = sx + sprdat.xoff; /* Line 216, Address: 0x100091c */
        rev = 0; /* Line 217, Address: 0x100094c */
        break; /* Line 218, Address: 0x1000950 */
      case 8:
        y_posi = sy + sprdat.yoff; /* Line 220, Address: 0x1000958 */
        x_posi = sx - sprdat.xoff /* Line 221, Address: 0x1000988 */
                    - SprBmp[sprdat.index].xs;
        rev = 1; /* Line 223, Address: 0x10009e8 */
        break; /* Line 224, Address: 0x10009f0 */
      case 16:
        y_posi = sy - sprdat.yoff /* Line 226, Address: 0x10009f8 */
                    - SprBmp[sprdat.index].ys;
        x_posi = sx + sprdat.xoff; /* Line 228, Address: 0x1000a58 */
        rev = 2; /* Line 229, Address: 0x1000a88 */
        break; /* Line 230, Address: 0x1000a90 */
      case 24:
        y_posi = sy - sprdat.yoff /* Line 232, Address: 0x1000a98 */
                    - SprBmp[sprdat.index].ys;
        x_posi = sx - sprdat.xoff /* Line 234, Address: 0x1000af8 */
                    - SprBmp[sprdat.index].xs;
        rev = 3; /* Line 236, Address: 0x1000b58 */
        break; /* Line 237, Address: 0x1000b60 */
      default:
        x_posi = y_posi = 0; /* Line 239, Address: 0x1000b68 */
        rev = 0; /* Line 240, Address: 0x1000b7c */
        break;
    }

    if (y_posi + SprBmp[sprdat.index].ys >= 129 /* Line 244, Address: 0x1000b80 */
        && y_posi < 384
        && x_posi + SprBmp[sprdat.index].xs >= 129
        && x_posi < 448) {
      EAsprset(x_posi, y_posi, sprdat.index, linkdata++, rev); /* Line 248, Address: 0x1000c30 */
    }



  } /* Line 253, Address: 0x1000c64 */
} /* Line 254, Address: 0x1000c90 */
