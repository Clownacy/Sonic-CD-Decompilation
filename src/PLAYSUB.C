#include "EQU.H"
#include "PLAYSUB.H"
#include "ACTION.H"
#include "ACTSET.H"
#include "DIRCOL.H"
#include "DUMMY.H"
#include "ETC.H"
#include "RIDECHK.H"

extern void soundset(short ReqNo);
extern spr_array* markerpat[]; extern unsigned char* markerchg[]; extern spr_array* bariapat[]; extern unsigned char* bariachg[]; extern spr_array* bakupat[]; extern unsigned char* bakuchg[];
unsigned char flowchg0[4] = { 3, 0, 1, 255 }, flowchg1[6] = { 3, 2, 3, 2, 3, 252 }, flowchg2[6] = { 1, 5, 5, 4, 6, 252 }, flowchg3[4] = { 19, 6, 7, 255 }, *flowchg[4] = { flowchg0, flowchg1, flowchg2, flowchg3 };
spr_array flo00 = { 1, { { -4, -16, 0, 264 } } };
spr_array flo01 = { 1, { { -4, -16, 0, 265 } } };
spr_array flo02 = { 1, { { -8, -16, 0, 266 } } };
spr_array flo03 = { 1, { { -8, -16, 0, 267 } } };
spr_array flo04 = { 1, { { -12, -24, 0, 268 } } };
spr_array flo05 = { 1, { { -8, -16, 0, 269 } } };
spr_array flo06 = { 1, { { -12, -48, 0, 270 } } };
spr_array flo07 = { 1, { { -12, -48, 0, 271 } } };
spr_array* flow_pat[8] = { &flo00, &flo01, &flo02, &flo03, &flo04, &flo05, &flo06, &flo07 };
extern spr_array* mizukipat[]; extern unsigned char* mizukichg[]; extern spr_array* futapat[]; extern unsigned char* futachg[]; extern spr_array* exit2pat[]; extern unsigned char* exit2chg[];

void patchg(act_info* patchgwk, unsigned char** pat_dat) { /* Line 24, Address: 0x10150d0 */
  unsigned char pat_no;
  unsigned char* sprpat_adr;
  short search_end;

  if (patchgwk->mstno.b.h != patchgwk->mstno.b.l) { /* Line 29, Address: 0x10150f0 */
    patchgwk->mstno.b.l = patchgwk->mstno.b.h; /* Line 30, Address: 0x1015118 */
    patchgwk->patcnt = patchgwk->pattim = 0; /* Line 31, Address: 0x1015128 */
  }

  if ((char)--patchgwk->pattim >= 0) return; /* Line 34, Address: 0x101513c */
  sprpat_adr = pat_dat[patchgwk->mstno.b.h]; /* Line 35, Address: 0x1015168 */

  search_end = 0; /* Line 37, Address: 0x1015188 */
  while (sprpat_adr[search_end++] < 250); /* Line 38, Address: 0x101518c */
  patchgwk->pattim = sprpat_adr[search_end - 1] != 252 && *sprpat_adr <= 0 ? 1 : *sprpat_adr; /* Line 39, Address: 0x10151bc */



  if ((pat_no = sprpat_adr[patchgwk->patcnt + 1]) < 128) { /* Line 43, Address: 0x1015220 */
label1:
    patchgwk->patno = pat_no & 31; /* Line 45, Address: 0x101524c */
    pat_no >>= 5; /* Line 46, Address: 0x1015260 */

    pat_no ^= patchgwk->cddat; /* Line 48, Address: 0x1015268 */
    pat_no &= 3; /* Line 49, Address: 0x1015278 */
    patchgwk->actflg &= -4; /* Line 50, Address: 0x1015280 */
    patchgwk->actflg |= pat_no; /* Line 51, Address: 0x1015290 */
    ++patchgwk->patcnt; /* Line 52, Address: 0x10152a0 */
  } /* Line 53, Address: 0x10152b0 */
  else {
    switch (pat_no) { /* Line 55, Address: 0x10152b8 */
      case 255:
        patchgwk->patcnt = 0; /* Line 57, Address: 0x10152e8 */
        pat_no = sprpat_adr[1]; /* Line 58, Address: 0x10152f0 */
        goto label1; /* Line 59, Address: 0x10152f8 */

      case 254:
        pat_no = sprpat_adr[patchgwk->patcnt + 2]; /* Line 62, Address: 0x1015300 */
        patchgwk->patcnt -= pat_no; /* Line 63, Address: 0x101531c */
        pat_no = sprpat_adr[patchgwk->patcnt + 1]; /* Line 64, Address: 0x101533c */
        goto label1; /* Line 65, Address: 0x1015358 */

      case 253:
        patchgwk->mstno.b.h = sprpat_adr[patchgwk->patcnt + 2]; /* Line 68, Address: 0x1015360 */
        break; /* Line 69, Address: 0x1015380 */
      case 252:
        patchgwk->r_no0 += 2; /* Line 71, Address: 0x1015388 */
        break; /* Line 72, Address: 0x1015398 */
      case 251:
        patchgwk->patcnt = patchgwk->r_no1 = 0; /* Line 74, Address: 0x10153a0 */
        break; /* Line 75, Address: 0x10153b4 */
      case 250:
        patchgwk->r_no1 += 2; /* Line 77, Address: 0x10153bc */
        break;
    }
  }

} /* Line 82, Address: 0x10153cc */



void playsave0(act_info* savewk) { /* Line 86, Address: 0x10153f0 */
  plflag_s = plflag; /* Line 87, Address: 0x10153f8 */
  plxposi_s = savewk->xposi.w.h; /* Line 88, Address: 0x1015408 */
  plyposi_s = savewk->yposi.w.h; /* Line 89, Address: 0x1015418 */
  water_flag_s = water_flag; /* Line 90, Address: 0x1015428 */
  scralim_down_s = scralim_down; /* Line 91, Address: 0x1015438 */
  scra_h_posit_s = scra_h_posit.w.h; /* Line 92, Address: 0x1015448 */
  scra_v_posit_s = scra_v_posit.w.h; /* Line 93, Address: 0x1015458 */
  scrb_h_posit_s = scrb_h_posit.w.h; /* Line 94, Address: 0x1015468 */
  scrb_v_posit_s = scrb_v_posit.w.h; /* Line 95, Address: 0x1015478 */
  scrc_h_posit_s = scrc_h_posit.w.h; /* Line 96, Address: 0x1015488 */
  scrc_v_posit_s = scrc_v_posit.w.h; /* Line 97, Address: 0x1015498 */
  scrz_h_posit_s = scrz_h_posit.w.h; /* Line 98, Address: 0x10154a8 */
  scrz_v_posit_s = scrz_v_posit.w.h; /* Line 99, Address: 0x10154b8 */
  waterposi_m_s = waterposi_m; /* Line 100, Address: 0x10154c8 */
  waterflag_s = waterflag; /* Line 101, Address: 0x10154d8 */
  if (pltime.l >= 327680) pltime_s = 327680; /* Line 102, Address: 0x10154e8 */
  else pltime_s = pltime.l; /* Line 103, Address: 0x1015514 */
  chibi_s = chibi_flag; /* Line 104, Address: 0x1015524 */
} /* Line 105, Address: 0x1015534 */













void marker(act_info* markerwk) { /* Line 119, Address: 0x1015540 */
  switch (markerwk->r_no0) { /* Line 120, Address: 0x101554c */
    case 0:
      marker_init(markerwk); /* Line 122, Address: 0x101558c */
      break; /* Line 123, Address: 0x1015598 */
    case 2:
      marker_move0(markerwk); /* Line 125, Address: 0x10155a0 */
      break; /* Line 126, Address: 0x10155ac */
    case 4:
      marker_move1(markerwk); /* Line 128, Address: 0x10155b4 */
      break; /* Line 129, Address: 0x10155c0 */
    case 6:
      marker_move2(markerwk); /* Line 131, Address: 0x10155c8 */
      break;
  }


  actionsub(markerwk); /* Line 136, Address: 0x10155d4 */
  frameout_s(markerwk); /* Line 137, Address: 0x10155e0 */
} /* Line 138, Address: 0x10155ec */


void marker_init(act_info* markerwk) { /* Line 141, Address: 0x1015600 */
  act_info *new_actwk, **parent;
  unsigned short marker_yposi_m_buf;

  markerwk->r_no0 += 2; /* Line 145, Address: 0x1015614 */
  markerwk->patbase = markerpat; /* Line 146, Address: 0x1015624 */
  markerwk->sproffset = 1739; /* Line 147, Address: 0x1015634 */
  markerwk->actflg = 4; /* Line 148, Address: 0x1015640 */
  markerwk->sprhsize = 8; /* Line 149, Address: 0x101564c */
  markerwk->sprvsize = 24; /* Line 150, Address: 0x1015658 */
  markerwk->sprpri = 4; /* Line 151, Address: 0x1015664 */

  if (markerno >= (unsigned char)markerwk->userflag.b.h) /* Line 153, Address: 0x1015670 */
    markerwk->actfree[4] = 1; /* Line 154, Address: 0x1015698 */
  else
    markerwk->colino = 227; /* Line 156, Address: 0x10156ac */
  if (actwkchk(&new_actwk) != 0) { frameout(markerwk); return; } /* Line 157, Address: 0x10156b8 */
  new_actwk->actno = 19; /* Line 158, Address: 0x10156e0 */
  new_actwk->r_no0 += 4; /* Line 159, Address: 0x10156ec */
  if (markerwk->actfree[4] != 0) new_actwk->r_no0 += 2; /* Line 160, Address: 0x10156fc */
  new_actwk->patbase = markerpat; /* Line 161, Address: 0x1015720 */
  new_actwk->sproffset = 1739; /* Line 162, Address: 0x1015730 */
  new_actwk->actflg = 4; /* Line 163, Address: 0x101573c */
  new_actwk->sprhsize = 8; /* Line 164, Address: 0x1015748 */
  new_actwk->sprvsize = 8; /* Line 165, Address: 0x1015754 */
  new_actwk->sprpri = 3; /* Line 166, Address: 0x1015760 */
  new_actwk->patno = 1; /* Line 167, Address: 0x101576c */
  parent = (act_info**)&new_actwk->actfree[6]; /* Line 168, Address: 0x1015778 */
  *parent = markerwk; /* Line 169, Address: 0x1015780 */
  new_actwk->xposi.w.h = markerwk->xposi.w.h; /* Line 170, Address: 0x1015788 */
  new_actwk->yposi.w.h = markerwk->yposi.w.h + -32; /* Line 171, Address: 0x1015798 */
  ((short*)new_actwk)[23] = markerwk->xposi.w.h; /* Line 172, Address: 0x10157bc */
  marker_yposi_m_buf = markerwk->yposi.w.h + -24; /* Line 173, Address: 0x10157cc */
  ((short*)new_actwk)[24] = marker_yposi_m_buf; /* Line 174, Address: 0x10157e8 */
} /* Line 175, Address: 0x10157f0 */


void marker_move0(act_info* markerwk) { /* Line 178, Address: 0x1015810 */
  if (markerwk->actfree[4] != 0) return; /* Line 181, Address: 0x101581c */









  if (markerwk->colicnt == 0) return; /* Line 189, Address: 0x1015830 */
  markerwk->colino = 0; /* Line 190, Address: 0x1015844 */
  markerwk->actfree[4] = 1; /* Line 191, Address: 0x101584c */
  markerno = markerwk->userflag.b.h; /* Line 192, Address: 0x1015858 */
  plflag = 1; /* Line 193, Address: 0x1015868 */
  playsave0(&actwk[0]); /* Line 194, Address: 0x1015874 */
  soundset(174); /* Line 195, Address: 0x1015884 */
} /* Line 196, Address: 0x1015890 */


void marker_move1(act_info* markerwk) { /* Line 199, Address: 0x10158a0 */
  int sin_data, cos_data;
  short sin_tmp, cos_tmp;
  act_info **parent, *new_actwk;

  if (markerwk->actfree[4] == 0) { /* Line 204, Address: 0x10158bc */
    parent = (act_info**)&markerwk->actfree[6]; /* Line 205, Address: 0x10158d0 */
    new_actwk = *parent; /* Line 206, Address: 0x10158d8 */
    if (new_actwk->actfree[4] == 0) return; /* Line 207, Address: 0x10158dc */
    markerwk->actfree[4] = 1; /* Line 208, Address: 0x10158ec */
  }

  markerwk->actfree[10] += 8; /* Line 211, Address: 0x10158f8 */
  sinset(markerwk->actfree[10], &sin_tmp, &cos_tmp); /* Line 212, Address: 0x1015908 */
  sin_data = sin_tmp; /* Line 213, Address: 0x1015920 */
  cos_data = cos_tmp; /* Line 214, Address: 0x101592c */
  sin_data *= 8; /* Line 215, Address: 0x1015938 */
  sin_data /= 256; /* Line 216, Address: 0x101593c */
  markerwk->xposi.w.h = ((short*)markerwk)[23]; /* Line 217, Address: 0x1015958 */
  markerwk->xposi.w.h += sin_data; /* Line 218, Address: 0x1015968 */
  cos_data = -cos_data * 8; /* Line 219, Address: 0x1015980 */
  cos_data /= 256; /* Line 220, Address: 0x1015988 */
  markerwk->yposi.w.h = ((short*)markerwk)[24]; /* Line 221, Address: 0x10159a4 */
  markerwk->yposi.w.h += cos_data; /* Line 222, Address: 0x10159b4 */
  if (markerwk->actfree[10] == 0) markerwk->r_no0 += 2; /* Line 223, Address: 0x10159cc */
} /* Line 224, Address: 0x10159f0 */


void marker_move2(act_info* markerwk) { /* Line 227, Address: 0x1015a10 */
  patchg(markerwk, markerchg); /* Line 228, Address: 0x1015a1c */
} /* Line 229, Address: 0x1015a30 */






void plairset() {} /* Line 236, Address: 0x1015a40 */



void test_act(act_info* testwk) { /* Line 240, Address: 0x1015a50 */
  switch (testwk->r_no0) { /* Line 241, Address: 0x1015a5c */
    case 0:
      test_init(testwk); /* Line 243, Address: 0x1015a84 */
      break; /* Line 244, Address: 0x1015a90 */
    case 2:
      test_move(testwk); /* Line 246, Address: 0x1015a98 */
      break;
  }


} /* Line 251, Address: 0x1015aa4 */



void test_init(act_info* testwk) { /* Line 255, Address: 0x1015ac0 */
  if (testwk->cddat & 128) { frameout(testwk); return; } /* Line 256, Address: 0x1015acc */
  testwk->r_no0 += 2; /* Line 257, Address: 0x1015af8 */
  testwk->actflg = 4; /* Line 258, Address: 0x1015b08 */
  testwk->sprpri = 1; /* Line 259, Address: 0x1015b14 */
  testwk->patbase = bariapat; /* Line 260, Address: 0x1015b20 */
  testwk->sproffset = 1345; /* Line 261, Address: 0x1015b30 */
  testwk->actfree[6] = testwk->xposi.b.b1; /* Line 262, Address: 0x1015b3c */
  testwk->actfree[7] = testwk->xposi.b.b2; /* Line 263, Address: 0x1015b4c */
  testwk->colino = 6; /* Line 264, Address: 0x1015b5c */
  test_move(testwk); /* Line 265, Address: 0x1015b68 */
} /* Line 266, Address: 0x1015b74 */


void test_move(act_info* testwk) { /* Line 269, Address: 0x1015b90 */
  unsigned short cal0, cal1;

  cal0 = ((unsigned short*)testwk)[26] & 65408; /* Line 272, Address: 0x1015ba4 */
  cal1 = (unsigned short)(scra_h_posit.w.h + -128) & 65408; /* Line 273, Address: 0x1015bbc */
  if ((cal0 - cal1) >= 641) { frameout(testwk); return; } /* Line 274, Address: 0x1015be4 */

  patchg(testwk, bariachg); /* Line 276, Address: 0x1015c10 */
  actionsub(testwk); /* Line 277, Address: 0x1015c24 */
} /* Line 278, Address: 0x1015c30 */



void tensuu_set(act_info* tensuuwk) { /* Line 282, Address: 0x1015c50 */
  unsigned char score_tmp;

  if (tensuuwk->r_no1 != 0) return; /* Line 285, Address: 0x1015c60 */
  score_tmp = ((unsigned short*)tensuuwk)[33]; /* Line 286, Address: 0x1015c74 */
  tensuu0(tensuuwk, score_tmp / 2); /* Line 287, Address: 0x1015c84 */
} /* Line 288, Address: 0x1015cb0 */


void tensuu0(act_info* tensuuwk, unsigned char uf_data) { /* Line 291, Address: 0x1015cd0 */
  act_info* new_actwk;

  uf_data |= 128; /* Line 294, Address: 0x1015ce0 */
  if (actwkchk(&new_actwk) != 0) return; /* Line 295, Address: 0x1015cec */
  new_actwk->actno = 28; /* Line 296, Address: 0x1015d00 */
  new_actwk->xposi.w.h = tensuuwk->xposi.w.h; /* Line 297, Address: 0x1015d0c */
  new_actwk->yposi.w.h = tensuuwk->yposi.w.h; /* Line 298, Address: 0x1015d1c */
  new_actwk->userflag.b.h = uf_data; /* Line 299, Address: 0x1015d2c */
} /* Line 300, Address: 0x1015d38 */








void bakuha(act_info* bakuhawk) { /* Line 309, Address: 0x1015d50 */
  switch (bakuhawk->r_no0) { /* Line 310, Address: 0x1015d5c */
    case 0:
      baku_init(bakuhawk); /* Line 312, Address: 0x1015d90 */
      break; /* Line 313, Address: 0x1015d9c */
    case 2:
      baku_move(bakuhawk); /* Line 315, Address: 0x1015da4 */
      break; /* Line 316, Address: 0x1015db0 */
    case 4:
      baku_die(bakuhawk); /* Line 318, Address: 0x1015db8 */
      break;
  }


} /* Line 323, Address: 0x1015dc4 */


void baku_init(act_info* bakuhawk) { /* Line 326, Address: 0x1015de0 */
  bakuhawk->r_no0 += 2; /* Line 327, Address: 0x1015dec */
  bakuhawk->actflg |= 4; /* Line 328, Address: 0x1015dfc */
  bakuhawk->sprpri = 1; /* Line 329, Address: 0x1015e0c */
  bakuhawk->sproffset = 34432; /* Line 330, Address: 0x1015e18 */
  if (bakuhawk->userflag.b.l != 0) bakuhawk->sproffset &= 32767; /* Line 331, Address: 0x1015e24 */

  bakuhawk->patbase = bakupat; /* Line 333, Address: 0x1015e4c */
  tensuu_set(bakuhawk); /* Line 334, Address: 0x1015e5c */
  bakuhawk->colino = 0; /* Line 335, Address: 0x1015e68 */
  bakuhawk->patcnt = 0; /* Line 336, Address: 0x1015e70 */
  bakuhawk->pattim = 0; /* Line 337, Address: 0x1015e78 */
  bakuhawk->mstno.w = 0; /* Line 338, Address: 0x1015e80 */
  if (bakuhawk->userflag.b.h != 0) bakuhawk->mstno.w = 256; /* Line 339, Address: 0x1015e88 */
  baku_move(bakuhawk); /* Line 340, Address: 0x1015eac */
} /* Line 341, Address: 0x1015eb8 */

void baku_move(act_info* bakuhawk) { /* Line 344, Address: 0x1015ed0 */
  patchg(bakuhawk, bakuchg); /* Line 345, Address: 0x1015edc */
  actionsub(bakuhawk); /* Line 346, Address: 0x1015ef0 */
} /* Line 347, Address: 0x1015efc */



void baku_die(act_info* bakuhawk) { /* Line 350, Address: 0x1015f10 */
  if (bakuhawk->r_no1 != 0) { frameout(bakuhawk); return; } /* Line 351, Address: 0x1015f1c */
  bakuhawk->actno = 31; /* Line 352, Address: 0x1015f44 */
  bakuhawk->r_no0 = 0; /* Line 353, Address: 0x1015f50 */
} /* Line 354, Address: 0x1015f58 */
















































void flower(act_info* flowerwk) { /* Line 403, Address: 0x1015f70 */
  switch (flowerwk->r_no0) { /* Line 404, Address: 0x1015f7c */
    case 0:
      flow_init(flowerwk); /* Line 406, Address: 0x1015fc8 */
      break; /* Line 407, Address: 0x1015fd4 */
    case 2:
      flow_move0(flowerwk); /* Line 409, Address: 0x1015fdc */
      break; /* Line 410, Address: 0x1015fe8 */
    case 4:
      flow_move1(flowerwk); /* Line 412, Address: 0x1015ff0 */
      break; /* Line 413, Address: 0x1015ffc */
    case 6:
      flow_move2(flowerwk); /* Line 415, Address: 0x1016004 */
      break; /* Line 416, Address: 0x1016010 */
    case 8:
      flow_move3(flowerwk); /* Line 418, Address: 0x1016018 */
      break;
  }


  actionsub(flowerwk); /* Line 423, Address: 0x1016024 */
} /* Line 424, Address: 0x1016030 */



void flow_init(act_info* flowerwk) { /* Line 428, Address: 0x1016040 */
  unsigned char* fwcnt_adr;
  fwcnt_adr = &flagworkcnt; /* Line 430, Address: 0x1016050 */

  flowerwk->actflg |= 4; /* Line 432, Address: 0x1016058 */
  flowerwk->sprpri = 1; /* Line 433, Address: 0x1016068 */
  flowerwk->sprvsize = 0; /* Line 434, Address: 0x1016074 */
  flowerwk->sproffset = 42711; /* Line 435, Address: 0x101607c */

  if (flowerwk->userflag.b.l != 0) flowerwk->sproffset &= 32767; /* Line 437, Address: 0x1016088 */

  flowerwk->patbase = flow_pat; /* Line 439, Address: 0x10160b0 */
  if (flowerwk->userflag.b.h == 0) { /* Line 440, Address: 0x10160c0 */
    fwcnt_adr = flow_sub(flowerwk); /* Line 441, Address: 0x10160d8 */
    flowerwk->r_no0 = 4; /* Line 442, Address: 0x10160e8 */
    flowerwk->mstno.b.h = 3; /* Line 443, Address: 0x10160f4 */
    if (*fwcnt_adr & 64) { flow_move1(flowerwk); return; } /* Line 444, Address: 0x1016100 */
  }
  flowerwk->mstno.w = 2; /* Line 446, Address: 0x1016128 */
  flowerwk->r_no0 = 2; /* Line 447, Address: 0x1016134 */
  flowerwk->sproffset = 1751; /* Line 448, Address: 0x1016140 */
  flow_move0(flowerwk); /* Line 449, Address: 0x101614c */
} /* Line 450, Address: 0x1016158 */


void flow_move0(act_info* flowerwk) { /* Line 453, Address: 0x1016170 */
 short y_move = 0, flower_index = 0; /* Line 454, Address: 0x1016188 */
 unsigned char* fwcnt_adr;

  y_move = emycol_d(flowerwk); /* Line 457, Address: 0x1016190 */
  if (y_move < 0) { /* Line 458, Address: 0x10161a4 */
    flowerwk->yposi.w.h += y_move; /* Line 459, Address: 0x10161b4 */
    if (flowerwk->userflag.b.h == 0) { /* Line 460, Address: 0x10161c4 */
      fwcnt_adr = flow_sub(flowerwk); /* Line 461, Address: 0x10161dc */
      flower_index = flow_sub1(flowercnt[time_flag & 127]++); /* Line 462, Address: 0x10161ec */
      flowerposi[flower_index].w.h = flowerwk->xposi.w.h; /* Line 463, Address: 0x1016224 */
      flowerposi[flower_index].w.l = flowerwk->yposi.w.h; /* Line 464, Address: 0x1016248 */
    }
    flowerwk->r_no0 = 4; /* Line 466, Address: 0x101626c */
    flowerwk->mstno.b.h = 1; /* Line 467, Address: 0x1016278 */
    flowerwk->sprvsize = 48; /* Line 468, Address: 0x1016284 */
    flow_move1(flowerwk); /* Line 469, Address: 0x1016290 */
  } else { /* Line 470, Address: 0x101629c */
    flowerwk->yposi.w.h += 2; /* Line 471, Address: 0x10162a4 */
    flow_move1(flowerwk); /* Line 472, Address: 0x10162b4 */
  }

} /* Line 475, Address: 0x10162c0 */


void flow_move1(act_info* flowerwk) { /* Line 478, Address: 0x10162e0 */
  patchg(flowerwk, flowchg); /* Line 479, Address: 0x10162ec */
} /* Line 480, Address: 0x1016300 */


unsigned char* flow_sub(act_info* flowerwk) { /* Line 483, Address: 0x1016310 */
  short index;

  index = (short)(time_flag & 127) + flowerwk->cdsts * 3; /* Line 486, Address: 0x101631c */
  return &flagwork[index]; /* Line 487, Address: 0x1016364 */
} /* Line 488, Address: 0x1016378 */


short flow_sub1(unsigned char fl_counter) { /* Line 491, Address: 0x1016390 */
  short flower_index;

  flower_index = (unsigned short)(time_flag & 127) * 64 + ((unsigned short)fl_counter & 63); /* Line 494, Address: 0x101639c */


  return flower_index; /* Line 497, Address: 0x10163dc */
} /* Line 498, Address: 0x10163e0 */


void flow_move2(act_info* flowerwk) { /* Line 501, Address: 0x10163f0 */
  flowerwk->sproffset = 9943; /* Line 502, Address: 0x10163fc */

  flowerwk->mstno.b.h = 2; /* Line 504, Address: 0x1016408 */
  flow_move1(flowerwk); /* Line 505, Address: 0x1016414 */
} /* Line 506, Address: 0x1016420 */


void flow_move3(act_info* flowerwk) { /* Line 509, Address: 0x1016430 */
  flowerwk->mstno.b.h = 3; /* Line 510, Address: 0x101643c */
  flowerwk->r_no0 = 4; /* Line 511, Address: 0x1016448 */
  flow_move1(flowerwk); /* Line 512, Address: 0x1016454 */
} /* Line 513, Address: 0x1016460 */







void mizukiri(act_info* mizukiwk) { /* Line 521, Address: 0x1016470 */
  switch (mizukiwk->r_no0) { /* Line 522, Address: 0x101647c */
    case 0:
      mizuki_init(mizukiwk); /* Line 524, Address: 0x10164b0 */
      break; /* Line 525, Address: 0x10164bc */
    case 2:
      mizuki_move(mizukiwk); /* Line 527, Address: 0x10164c4 */
      break; /* Line 528, Address: 0x10164d0 */
    case 4:
      mizuki_move2(mizukiwk); /* Line 530, Address: 0x10164d8 */
      break;
  }


} /* Line 535, Address: 0x10164e4 */


void mizuki_init(act_info* mizukiwk) { /* Line 538, Address: 0x1016500 */
  mizukiwk->r_no0 += 2; /* Line 539, Address: 0x101650c */
  mizukiwk->actflg |= 4; /* Line 540, Address: 0x101651c */
  mizukiwk->patbase = mizukipat; /* Line 541, Address: 0x101652c */
  mizukiwk->sproffset = 996; /* Line 542, Address: 0x101653c */
  if (time_flag == 0) mizukiwk->sproffset = 926; /* Line 543, Address: 0x1016548 */
  mizukiwk->sprpri = 1; /* Line 544, Address: 0x1016568 */
  mizuki_move(mizukiwk); /* Line 545, Address: 0x1016574 */
} /* Line 546, Address: 0x1016580 */


void mizuki_move(act_info* mizukiwk) { /* Line 549, Address: 0x1016590 */
  patchg(mizukiwk, mizukichg); /* Line 550, Address: 0x101659c */
  actionsub(mizukiwk); /* Line 551, Address: 0x10165b0 */
} /* Line 552, Address: 0x10165bc */


void mizuki_move2(act_info* mizukiwk) { /* Line 555, Address: 0x10165d0 */
  frameout(mizukiwk); /* Line 556, Address: 0x10165dc */
} /* Line 557, Address: 0x10165e8 */







void futa(act_info* futawk) { /* Line 565, Address: 0x1016600 */
  switch (futawk->r_no0) { /* Line 566, Address: 0x101660c */
    case 0:
      futa_init(futawk); /* Line 568, Address: 0x101664c */
      break; /* Line 569, Address: 0x1016658 */
    case 2:
      futa_move(futawk); /* Line 571, Address: 0x1016660 */
      break; /* Line 572, Address: 0x101666c */
    case 4:
      futa_move2(futawk); /* Line 574, Address: 0x1016674 */
      break; /* Line 575, Address: 0x1016680 */
    case 6:
      futa_move3(futawk); /* Line 577, Address: 0x1016688 */
      break;
  }


  actionsub(futawk); /* Line 582, Address: 0x1016694 */
  frameout_s(futawk); /* Line 583, Address: 0x10166a0 */
} /* Line 584, Address: 0x10166ac */


void ride_on_chk_f(act_info* futawk, act_info* sonicwk) { /* Line 587, Address: 0x10166c0 */
  act_info* new_actwk;

  if (sonicwk->yspeed.w >= 0) /* Line 590, Address: 0x10166d0 */
    { ridechk(futawk, &actwk[0]); return; } /* Line 591, Address: 0x10166e8 */
  if (col_chk(futawk, sonicwk) == 0) /* Line 592, Address: 0x1016704 */
    { ridechk(futawk, &actwk[0]); return; } /* Line 593, Address: 0x1016724 */
  futawk->r_no0 = 4; /* Line 594, Address: 0x1016740 */
  if (futawk->userflag.b.h != 0) return; /* Line 595, Address: 0x101674c */
  if (actwkchk(&new_actwk) != 0) return; /* Line 596, Address: 0x1016764 */
  new_actwk->actno = 11; /* Line 597, Address: 0x1016778 */
  new_actwk->xposi.w.h = futawk->xposi.w.h; /* Line 598, Address: 0x1016784 */
  new_actwk->yposi.w.h = futawk->yposi.w.h + -4; /* Line 599, Address: 0x1016794 */
  soundset(164); /* Line 600, Address: 0x10167b8 */
} /* Line 601, Address: 0x10167c4 */



void futa_init(act_info* futawk) { /* Line 605, Address: 0x10167e0 */
  futawk->r_no0 += 2; /* Line 606, Address: 0x10167ec */
  futawk->patbase = futapat; /* Line 607, Address: 0x10167fc */
  futawk->sproffset = 32768; /* Line 608, Address: 0x101680c */
  futawk->sprpri = 1; /* Line 609, Address: 0x1016818 */
  futawk->actflg |= 4; /* Line 610, Address: 0x1016824 */
  futawk->sprhsize = 44; /* Line 611, Address: 0x1016834 */
  if (futawk->userflag.b.h == 2) futawk->sprhsize = 24; /* Line 612, Address: 0x1016840 */
  futawk->sprvsize = 8; /* Line 613, Address: 0x1016868 */
  pa_set(futawk, 12); /* Line 614, Address: 0x1016874 */
  futa_move(futawk); /* Line 615, Address: 0x1016884 */
} /* Line 616, Address: 0x1016890 */


void futa_move(act_info* futawk) { /* Line 619, Address: 0x10168a0 */
  ride_on_chk_f(futawk, &actwk[0]); /* Line 620, Address: 0x10168ac */
  ride_on_chk_f(futawk, &actwk[1]); /* Line 621, Address: 0x10168c0 */
} /* Line 622, Address: 0x10168d4 */


void futa_move2(act_info* futawk) { /* Line 625, Address: 0x10168f0 */
  patchg(futawk, futachg); /* Line 626, Address: 0x10168fc */
} /* Line 627, Address: 0x1016910 */


void futa_move3(act_info* futawk) { /* Line 630, Address: 0x1016920 */
  futawk->mstno.b.l = 1; /* Line 631, Address: 0x1016928 */
  futawk->patno = 0; /* Line 632, Address: 0x1016934 */
  futawk->r_no0 -= 4; /* Line 633, Address: 0x101693c */
} /* Line 634, Address: 0x101694c */






void exit2_set(act_info* testwk) { /* Line 641, Address: 0x1016960 */
  char a;

  a = col_chk(testwk, &actwk[0]); /* Line 644, Address: 0x1016970 */
} /* Line 645, Address: 0x101698c */







char col_chk(act_info* thingwk, act_info* sonicwk) { /* Line 653, Address: 0x10169a0 */
  short cal_posi;

  cal_posi = thingwk->sprhsize + (sonicwk->xposi.w.h - thingwk->xposi.w.h); /* Line 656, Address: 0x10169b0 */
  if (cal_posi < 0) return 0; /* Line 657, Address: 0x10169fc */
  if (cal_posi >= (thingwk->sprhsize * 2)) return 0; /* Line 658, Address: 0x1016a18 */
  cal_posi = thingwk->sprvsize + (sonicwk->yposi.w.h - thingwk->yposi.w.h); /* Line 659, Address: 0x1016a48 */
  if (cal_posi < 0) return 0; /* Line 660, Address: 0x1016a94 */
  if (cal_posi >= (thingwk->sprvsize * 2)) return 0; /* Line 661, Address: 0x1016ab0 */
  return 1; /* Line 662, Address: 0x1016ae0 */
} /* Line 663, Address: 0x1016ae4 */







void exit2(act_info* exitwk) { /* Line 671, Address: 0x1016b00 */
  switch (exitwk->r_no0) { /* Line 672, Address: 0x1016b0c */
    case 0:
      exit2_init(exitwk); /* Line 674, Address: 0x1016b40 */
      break; /* Line 675, Address: 0x1016b4c */
    case 2:
      exit2_move(exitwk); /* Line 677, Address: 0x1016b54 */
      break; /* Line 678, Address: 0x1016b60 */
    case 4:
      exit2_erase(exitwk); /* Line 680, Address: 0x1016b68 */
      break;
  }


} /* Line 685, Address: 0x1016b74 */


void exit2_init(act_info* exitwk) { /* Line 688, Address: 0x1016b90 */
  exitwk->r_no0 += 2; /* Line 689, Address: 0x1016b9c */
  exitwk->actflg = 4; /* Line 690, Address: 0x1016bac */
  exitwk->sprpri = 1; /* Line 691, Address: 0x1016bb8 */
  exitwk->patbase = exit2pat; /* Line 692, Address: 0x1016bc4 */
  exitwk->mstno.b.h = exitwk->userflag.b.h; /* Line 693, Address: 0x1016bd4 */
  pa_set(exitwk, 13); /* Line 694, Address: 0x1016be4 */
  if (exitwk->userflag.b.h < 2) soundset(162); /* Line 695, Address: 0x1016bf4 */
  else soundset(161); /* Line 696, Address: 0x1016c24 */
  exit2_move(exitwk); /* Line 697, Address: 0x1016c30 */
} /* Line 698, Address: 0x1016c3c */


void exit2_move(act_info* exitwk) { /* Line 701, Address: 0x1016c50 */
  patchg(exitwk, exit2chg); /* Line 702, Address: 0x1016c5c */
  actionsub(exitwk); /* Line 703, Address: 0x1016c70 */
} /* Line 704, Address: 0x1016c7c */


void exit2_erase(act_info* exitwk) { /* Line 707, Address: 0x1016c90 */
  frameout(exitwk); /* Line 708, Address: 0x1016c9c */
} /* Line 709, Address: 0x1016ca8 */









void baria(act_info* bariawk) { /* Line 719, Address: 0x1016cc0 */
  switch (bariawk->r_no0) { /* Line 720, Address: 0x1016ccc */
    case 0:
      bariainit(bariawk); /* Line 722, Address: 0x1016d0c */
      break; /* Line 723, Address: 0x1016d18 */
    case 2:
      bariamove(bariawk); /* Line 725, Address: 0x1016d20 */
      break; /* Line 726, Address: 0x1016d2c */
    case 4:
      mutekimove(bariawk); /* Line 728, Address: 0x1016d34 */
      break; /* Line 729, Address: 0x1016d40 */
    case 6:
      backtomove(bariawk); /* Line 731, Address: 0x1016d48 */
      break;
  }


  if (actwk[0].sproffset & 32768) bariawk->sproffset |= 32768; /* Line 736, Address: 0x1016d54 */
  else bariawk->sproffset &= 32767; /* Line 737, Address: 0x1016d84 */
  if (stageno.b.h == 6) bariawk->sproffset |= 32768; /* Line 738, Address: 0x1016d94 */
} /* Line 739, Address: 0x1016dc0 */


void bariainit(act_info* bariawk) { /* Line 742, Address: 0x1016dd0 */
  bariawk->r_no0 += 2; /* Line 743, Address: 0x1016dd8 */
  bariawk->patbase = bariapat; /* Line 744, Address: 0x1016de8 */
  bariawk->actflg = 4; /* Line 745, Address: 0x1016df8 */
  bariawk->sprpri = 1; /* Line 746, Address: 0x1016e04 */
  bariawk->sprhsize = 16; /* Line 747, Address: 0x1016e10 */
  bariawk->sproffset = 1348; /* Line 748, Address: 0x1016e1c */
  if (bariawk->mstno.b.h == 0) return; /* Line 749, Address: 0x1016e28 */
  bariawk->r_no0 += 2; /* Line 750, Address: 0x1016e40 */
  if (bariawk->mstno.b.h < 5) return; /* Line 751, Address: 0x1016e50 */
  bariawk->r_no0 += 2; /* Line 752, Address: 0x1016e6c */
} /* Line 753, Address: 0x1016e7c */


void bariamove(act_info* bariawk) { /* Line 756, Address: 0x1016e90 */
  if (plpower_b == 0) { frameout(bariawk); return; } /* Line 757, Address: 0x1016e9c */
  if (plpower_a != 0 || plpower_m != 0) return; /* Line 758, Address: 0x1016ec4 */
  bariawk->xposi.w.h = actwk[0].xposi.w.h; /* Line 759, Address: 0x1016ef4 */
  bariawk->yposi.w.h = actwk[0].yposi.w.h; /* Line 760, Address: 0x1016f04 */
  bariawk->cddat = actwk[0].cddat; /* Line 761, Address: 0x1016f14 */
  if (stageno.b.h == 6) { /* Line 762, Address: 0x1016f24 */
    bariawk->sproffset |= 128; /* Line 763, Address: 0x1016f40 */
    if (prio_flag != 0) /* Line 764, Address: 0x1016f50 */
      bariawk->sproffset &= 127; /* Line 765, Address: 0x1016f64 */
  }
  patchg(bariawk, bariachg); /* Line 767, Address: 0x1016f74 */
  actionsub0(bariawk); /* Line 768, Address: 0x1016f88 */
} /* Line 769, Address: 0x1016f94 */


void mutekimove(act_info* bariawk) { /* Line 772, Address: 0x1016fb0 */
  if (plpower_a != 0) return; /* Line 773, Address: 0x1016fbc */
  if (plpower_m != 0) muteki_sub(bariawk); /* Line 774, Address: 0x1016fd0 */
  else frameout(bariawk); /* Line 775, Address: 0x1016ff8 */
} /* Line 776, Address: 0x1017004 */


void backtomove(act_info* bariawk) { /* Line 779, Address: 0x1017020 */
  if (plpower_a != 0) muteki_sub(bariawk); /* Line 780, Address: 0x101702c */
  else frameout(bariawk); /* Line 781, Address: 0x1017054 */
} /* Line 782, Address: 0x1017060 */



void muteki_sub(act_info* bariawk) { /* Line 786, Address: 0x1017070 */
  short_union ppw_offset;
  unsigned char cal_no;

  if (stageno.b.h == 6) { /* Line 790, Address: 0x1017080 */
    bariawk->sproffset |= 128; /* Line 791, Address: 0x101709c */
    if (prio_flag != 0) /* Line 792, Address: 0x10170ac */
      bariawk->sproffset &= 127; /* Line 793, Address: 0x10170c0 */
  }

  ppw_offset.w = plposiwkadr.w; /* Line 796, Address: 0x10170d0 */
  cal_no = bariawk->mstno.b.h + -1; /* Line 797, Address: 0x10170dc */
  if (cal_no >= 4) cal_no -= 4; /* Line 798, Address: 0x10170f8 */
  cal_no = cal_no * 24 + 4; /* Line 799, Address: 0x1017110 */
  ppw_offset.b.l -= cal_no; /* Line 800, Address: 0x101712c */
  cal_no = bariawk->actfree[6]; /* Line 801, Address: 0x1017144 */
  ppw_offset.b.l -= cal_no; /* Line 802, Address: 0x1017150 */
  if ((cal_no += 4) >= 24) cal_no = 0; /* Line 803, Address: 0x1017168 */
  bariawk->actfree[6] = cal_no; /* Line 804, Address: 0x1017188 */

  bariawk->xposi.w.h = playposiwk[ppw_offset.w / 2]; /* Line 806, Address: 0x1017190 */
  bariawk->yposi.w.h = playposiwk[ppw_offset.w / 2 + 1]; /* Line 807, Address: 0x10171cc */

  bariawk->cddat = actwk[0].cddat; /* Line 809, Address: 0x101720c */
  patchg(bariawk, bariachg); /* Line 810, Address: 0x101721c */
  actionsub0(bariawk); /* Line 811, Address: 0x1017230 */
} /* Line 812, Address: 0x101723c */



void actionsub0(act_info* bariawk) { /* Line 816, Address: 0x1017250 */
  if ((plsubchg_flag & 15) >= 8) return; /* Line 817, Address: 0x101725c */

  if (bariawk->r_no0 != 0) plsubchg_flag = bariawk->r_no0 | 128; /* Line 819, Address: 0x1017278 */
  actionsub(bariawk); /* Line 820, Address: 0x10172a8 */
} /* Line 821, Address: 0x10172b4 */













void ball(act_info* ballwk) { /* Line 835, Address: 0x10172d0 */
  switch (ballwk->r_no0) { /* Line 836, Address: 0x10172dc */
    case 0:
      ball_init(ballwk); /* Line 838, Address: 0x1017304 */
      break; /* Line 839, Address: 0x1017310 */
    case 2:
      ball_move(ballwk); /* Line 841, Address: 0x1017318 */
      break;
  }




  frameout_s(ballwk); /* Line 848, Address: 0x1017324 */
} /* Line 849, Address: 0x1017330 */



void ball_init(act_info* ballwk) { /* Line 853, Address: 0x1017340 */
  ballwk->r_no0 += 2; /* Line 854, Address: 0x101734c */
  ballwk->actflg |= 4; /* Line 855, Address: 0x101735c */
  ballwk->sproffset = 1348; /* Line 856, Address: 0x101736c */
  ballwk->patbase = bariapat; /* Line 857, Address: 0x1017378 */
  ballwk->patno = ballwk->userflag.b.h + 1; /* Line 858, Address: 0x1017388 */
  ball_move(ballwk); /* Line 859, Address: 0x10173a8 */
} /* Line 860, Address: 0x10173b4 */


void ball_move(act_info* ballwk) { /* Line 863, Address: 0x10173d0 */
  short cal_speed0, cal_speed1;

  if (actwk[0].mstno.b.h == 43) return; /* Line 866, Address: 0x10173e4 */
  if (actwk[0].r_no0 >= 6) return; /* Line 867, Address: 0x1017400 */
  if (ball_coli(ballwk) == 0) return; /* Line 868, Address: 0x1017418 */

  if (ballwk->userflag.b.h == 0) { /* Line 870, Address: 0x1017430 */
    if ((cal_speed0 = actwk[0].xspeed.w) < 0) cal_speed0 = -cal_speed0; /* Line 871, Address: 0x1017448 */
    cal_speed1 = 2560; /* Line 872, Address: 0x1017484 */
    if (stageno.b.h == 5) cal_speed1 = 3328; /* Line 873, Address: 0x1017490 */
    if (cal_speed0 < cal_speed1) cal_speed0 = cal_speed1; /* Line 874, Address: 0x10174b8 */
    if (actwk[0].xspeed.w < 0) cal_speed0 = -cal_speed0; /* Line 875, Address: 0x10174dc */
    actwk[0].xspeed.w = actwk[0].mspeed.w = cal_speed0; /* Line 876, Address: 0x1017510 */
    if (((unsigned char)actwk[0].direc.b.h + 32 & 192) == 128) /* Line 877, Address: 0x1017520 */
      actwk[0].mspeed.w = -actwk[0].mspeed.w; /* Line 878, Address: 0x1017544 */
    goto label1; /* Line 879, Address: 0x1017568 */
  } else if (ballwk->userflag.b.h >= 2) { ball_rd7(ballwk); return; } /* Line 880, Address: 0x1017570 */
  if ((cal_speed0 = actwk[0].yspeed.w) < 0) cal_speed0 = -cal_speed0; /* Line 881, Address: 0x10175a0 */
  if (cal_speed0 < 3328) cal_speed0 = 3328; /* Line 882, Address: 0x10175dc */
  if (actwk[0].yspeed.w < 0) cal_speed0 = -cal_speed0; /* Line 883, Address: 0x10175fc */
  actwk[0].yspeed.w = actwk[0].mspeed.w = cal_speed0; /* Line 884, Address: 0x1017630 */
  actwk[0].cddat |= 2; /* Line 885, Address: 0x1017640 */
label1:
  ball_ball(); /* Line 887, Address: 0x1017654 */
} /* Line 888, Address: 0x101765c */


void ball_ball() {
  if (actwk[0].cddat & 4) return; /* Line 892, Address: 0x1017680 */
  actwk[0].cddat |= 4; /* Line 893, Address: 0x1017698 */
  actwk[0].sprvsize = 14; /* Line 894, Address: 0x10176ac */
  actwk[0].sprhs = 7; /* Line 895, Address: 0x10176b8 */
  actwk[0].yposi.w.h += 5; /* Line 896, Address: 0x10176c4 */
  actwk[0].mstno.b.h = 2; /* Line 897, Address: 0x10176d8 */

} /* Line 899, Address: 0x10176e4 */


void ball_rd7(act_info* ballwk) { /* Line 902, Address: 0x10176f0 */
  short cal_speed0;

  if (ballwk->userflag.b.h != 4) { /* Line 905, Address: 0x1017700 */
    if (ballwk->userflag.b.h == 2) { /* Line 906, Address: 0x101771c */
      if (actwk[0].yspeed.w >= 0) { ball_ball(); return; } /* Line 907, Address: 0x1017738 */
    }
    else
      if (actwk[0].yspeed.w < 0) { ball_ball(); return; } /* Line 910, Address: 0x1017760 */
    cal_speed0 = 3328; /* Line 911, Address: 0x1017788 */
    if ((swdata1.b.h & 8) == 0) { /* Line 912, Address: 0x1017794 */
      if ((swdata1.b.h & 4) == 0) { ball_ball(); return; } /* Line 913, Address: 0x10177ac */
      else cal_speed0 = -cal_speed0; /* Line 914, Address: 0x10177d4 */
    }
    if (ballwk->userflag.b.h != 2) actwk[0].cddat |= 2; /* Line 916, Address: 0x10177f0 */
    actwk[0].xspeed.w = actwk[0].mspeed.w = cal_speed0; /* Line 917, Address: 0x1017820 */
    ball_ball(); /* Line 918, Address: 0x1017830 */
  } else { /* Line 919, Address: 0x1017838 */
    if (actwk[0].xspeed.w < 0) { ball_ball(); return; } /* Line 920, Address: 0x1017840 */
    if ((swdata1.b.h & 1) == 0) { ball_ball(); return; } /* Line 921, Address: 0x1017868 */
    actwk[0].yspeed.w = actwk[0].mspeed.w = -2560; /* Line 922, Address: 0x1017890 */
    actwk[0].cddat |= 2; /* Line 923, Address: 0x10178ac */
    ball_ball(); /* Line 924, Address: 0x10178c0 */
  }
} /* Line 926, Address: 0x10178c8 */


unsigned char ball_coli(act_info* ballwk) { /* Line 929, Address: 0x10178e0 */
  short cal_posi;

  if (editmode.b.h != 0) return 0; /* Line 932, Address: 0x10178ec */
  cal_posi = actwk[0].xposi.w.h - ballwk->xposi.w.h + 40; /* Line 933, Address: 0x1017910 */
  if (cal_posi < 0) return 0; /* Line 934, Address: 0x1017948 */
  if (cal_posi >= 80) return 0; /* Line 935, Address: 0x1017964 */
  cal_posi = actwk[0].yposi.w.h - ballwk->yposi.w.h + 40; /* Line 936, Address: 0x1017984 */
  if (cal_posi < 0) return 0; /* Line 937, Address: 0x10179bc */
  if (cal_posi >= 80) return 0; /* Line 938, Address: 0x10179d8 */
  return 1; /* Line 939, Address: 0x10179f8 */
} /* Line 940, Address: 0x10179fc */
