#include "..\EQU.H"
#include "PLAYSUB4.H"

extern sprite_pattern* markerpat[]; extern unsigned char* markerchg[]; extern sprite_pattern* bakupat[]; extern unsigned char* bakuchg[]; extern sprite_pattern* exit2pat[]; extern unsigned char* exit2chg[]; extern sprite_pattern* bariapat[]; extern unsigned char* bariachg[]; extern unsigned char awasintbl[];
static unsigned char flowchg0[4] = { 3, 0, 1, 255 }, flowchg1[6] = { 3, 2, 3, 2, 3, 252 }, flowchg2[6] = { 1, 5, 5, 4, 6, 252 }, flowchg3[4] = { 19, 6, 7, 255 };
unsigned char* flowchg[4] = { flowchg0, flowchg1, flowchg2, flowchg3 };
static sprite_pattern flo00 = { 1, { { -4, -16, 0, 264 } } };
static sprite_pattern flo01 = { 1, { { -4, -16, 0, 265 } } };
static sprite_pattern flo02 = { 1, { { -8, -16, 0, 266 } } };
static sprite_pattern flo03 = { 1, { { -8, -16, 0, 267 } } };
static sprite_pattern flo04 = { 1, { { -12, -24, 0, 268 } } };
static sprite_pattern flo05 = { 1, { { -8, -16, 0, 269 } } };
static sprite_pattern flo06 = { 1, { { -12, -48, 0, 270 } } };
static sprite_pattern flo07 = { 1, { { -12, -48, 0, 271 } } };
sprite_pattern* flow_pat[8] = { &flo00, &flo01, &flo02, &flo03, &flo04, &flo05, &flo06, &flo07 };
sprite_pattern boupat0 = { 1, { { -4, -46, 0, 423 } } }, boupat1 = { 1, { { -4, -46, 0, 424 } } };
sprite_pattern* boupat[2] = { &boupat0, &boupat1 };
sprite_pattern wavepat0 = { 1, { { -96, -8, 0, 425 } } }, wavepat1 = { 1, { { -96, -8, 0, 426 } } }, wavepat2 = { 1, { { -96, -8, 0, 427 } } }, wavepat3 = { 1, { { -96, -8, 0, 428 } } };
sprite_pattern* wavepat[8] = { &wavepat0, &wavepat0, &wavepat1, &wavepat1, &wavepat2, &wavepat2, &wavepat3, &wavepat3 };
sprite_pattern awasp0 = { 1, { { -4, -4, 0, 403 } } }, awasp1 = { 1, { { -4, -4, 0, 404 } } }, awasp2 = { 1, { { -4, -4, 0, 405 } } }, awasp3 = { 1, { { -8, -8, 0, 406 } } }, awasp4 = { 1, { { -8, -8, 0, 407 } } }, awasp5 = { 1, { { -8, -8, 0, 407 } } }, awasp6 = { 1, { { -16, -16, 0, 408 } } }, awasp7 = { 1, { { -16, -16, 0, 409 } } }, awasp8 = { 1, { { -16, -16, 0, 409 } } }, awasp9 = { 1, { { -8, -12, 0, 410 } } }, awasp10 = { 1, { { -8, -12, 0, 411 } } }, awasp11 = { 1, { { -8, -12, 0, 412 } } }, awasp12 = { 1, { { -8, -12, 0, 413 } } }, awasp13 = { 1, { { -8, -12, 0, 414 } } }, awasp14 = { 1, { { -8, -12, 0, 415 } } }, awasp15 = { 1, { { -8, -12, 0, 416 } } }, awasp16 = { 1, { { -8, -12, 0, 417 } } }, awasp17 = { 1, { { -8, -12, 0, 418 } } }, awasp18 = { 1, { { -8, -12, 0, 419 } } }, awasp19 = { 1, { { -8, -16, 0, 420 } } }, awasp20 = { 1, { { -8, -16, 0, 421 } } }, awasp21 = { 1, { { -8, -16, 0, 422 } } }, awasp22;
sprite_pattern* awapat[23] = { &awasp0, &awasp1, &awasp2, &awasp3, &awasp4, &awasp5, &awasp6, &awasp7, &awasp8, &awasp9, &awasp10, &awasp11, &awasp12, &awasp13, &awasp14, &awasp15, &awasp16, &awasp17, &awasp18, &awasp19, &awasp20, &awasp21, &awasp22 };
unsigned char plawachg0[9] = { 5, 0, 1, 2, 3, 4, 9, 13, 252 }, plawachg1[9] = { 5, 0, 1, 2, 3, 4, 12, 18, 252 }, plawachg2[9] = { 5, 0, 1, 2, 3, 4, 12, 17, 252 }, plawachg3[9] = { 5, 0, 1, 2, 3, 4, 11, 16, 252 }, plawachg4[9] = { 5, 0, 1, 2, 3, 4, 9, 15, 252 }, plawachg5[9] = { 5, 0, 1, 2, 3, 4, 10, 14, 252 }, plawachg6[5] = { 14, 0, 1, 2, 252 }, plawachg7[8] = { 7, 22, 13, 22, 13, 22, 13, 252 }, plawachg8[8] = { 7, 22, 18, 22, 18, 22, 18, 252 }, plawachg9[8] = { 7, 22, 17, 22, 17, 22, 17, 252 }, plawachg10[8] = { 7, 22, 16, 22, 16, 22, 16, 252 }, plawachg11[8] = { 7, 22, 15, 22, 15, 22, 15, 252 }, plawachg12[8] = { 7, 22, 14, 22, 14, 22, 14, 252 }, plawachg13[2] = { 14, 252 }, plawachg14[6] = { 14, 1, 2, 3, 4, 252 };
unsigned char* plawachg[16] = { plawachg0, plawachg1, plawachg2, plawachg3, plawachg4, plawachg5, plawachg6, plawachg7, plawachg8, plawachg9, plawachg10, plawachg11, plawachg12, plawachg13, plawachg14, plawachg13 };
unsigned char wavechg0[50] = { 2, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 2, 3, 2, 3, 2, 3, 2, 3, 2, 3, 2, 3, 4, 5, 4, 5, 4, 5, 4, 5, 4, 5, 4, 5, 6, 7, 6, 7, 6, 7, 6, 7, 6, 7, 6, 7, 255 };
unsigned char* wavechg[1] = { wavechg0 };




void patchg(sprite_status* patchgwk, unsigned char** pat_dat) { /* Line 30, Address: 0x101a2b0 */
  unsigned char pat_no;
  unsigned char* sprpat_adr;

  if (patchgwk->mstno.b.h != patchgwk->mstno.b.l) { /* Line 34, Address: 0x101a2c8 */
    patchgwk->mstno.b.l = patchgwk->mstno.b.h; /* Line 35, Address: 0x101a2f0 */
    patchgwk->patcnt = patchgwk->pattim = 0; /* Line 36, Address: 0x101a300 */
  }

  if ((char)--patchgwk->pattim < 0) { /* Line 39, Address: 0x101a314 */
    sprpat_adr = pat_dat[patchgwk->mstno.b.h]; /* Line 40, Address: 0x101a340 */

    pat_no = 0; /* Line 42, Address: 0x101a360 */
    while (sprpat_adr[pat_no] < 250) ++pat_no; /* Line 43, Address: 0x101a364 */
    if (sprpat_adr[pat_no] != 252) /* Line 44, Address: 0x101a390 */
      patchgwk->pattim = sprpat_adr[0] <= 0 ? 1 : sprpat_adr[0]; /* Line 45, Address: 0x101a3ac */
    else
      patchgwk->pattim = sprpat_adr[0]; /* Line 47, Address: 0x101a3e4 */

    if ((pat_no = sprpat_adr[patchgwk->patcnt + 1]) < 128) { /* Line 49, Address: 0x101a3f0 */
label1:
      patchgwk->patno = pat_no & 31; /* Line 51, Address: 0x101a41c */
      pat_no >>= 5; /* Line 52, Address: 0x101a430 */

      pat_no ^= patchgwk->cddat; /* Line 54, Address: 0x101a438 */
      pat_no &= 3; /* Line 55, Address: 0x101a448 */
      patchgwk->actflg &= 252; /* Line 56, Address: 0x101a450 */
      patchgwk->actflg |= pat_no; /* Line 57, Address: 0x101a460 */
      ++patchgwk->patcnt; /* Line 58, Address: 0x101a470 */
    } /* Line 59, Address: 0x101a480 */
    else {
      switch (pat_no) { /* Line 61, Address: 0x101a488 */
        case 255:
          patchgwk->patcnt = 0; /* Line 63, Address: 0x101a4b8 */
          pat_no = sprpat_adr[1]; /* Line 64, Address: 0x101a4c0 */
          goto label1; /* Line 65, Address: 0x101a4c8 */

        case 254:
          pat_no = sprpat_adr[patchgwk->patcnt + 2]; /* Line 68, Address: 0x101a4d0 */
          patchgwk->patcnt -= pat_no; /* Line 69, Address: 0x101a4ec */
          pat_no = sprpat_adr[patchgwk->patcnt + 1]; /* Line 70, Address: 0x101a50c */
          goto label1; /* Line 71, Address: 0x101a528 */
          
        case 253:
          patchgwk->mstno.b.h = sprpat_adr[patchgwk->patcnt + 2]; /* Line 74, Address: 0x101a530 */
          break; /* Line 75, Address: 0x101a550 */
        case 252:
          patchgwk->r_no0 += 2; /* Line 77, Address: 0x101a558 */
          break; /* Line 78, Address: 0x101a568 */
        case 251:
          patchgwk->patcnt = patchgwk->r_no1 = 0; /* Line 80, Address: 0x101a570 */
          break; /* Line 81, Address: 0x101a584 */
        case 250:
          patchgwk->r_no1 += 2; /* Line 83, Address: 0x101a58c */
          break;
      }
    }
  }
} /* Line 88, Address: 0x101a59c */



void playsave0(sprite_status* savewk) { /* Line 92, Address: 0x101a5c0 */
  plflag_s = plflag; /* Line 93, Address: 0x101a5c8 */
  plxposi_s = savewk->xposi.w.h; /* Line 94, Address: 0x101a5d8 */
  plyposi_s = savewk->yposi.w.h; /* Line 95, Address: 0x101a5e8 */
  water_flag_s = water_flag; /* Line 96, Address: 0x101a5f8 */
  scralim_down_s = scralim_down; /* Line 97, Address: 0x101a608 */
  scra_h_posit_s = scra_h_posit.w.h; /* Line 98, Address: 0x101a618 */
  scra_v_posit_s = scra_v_posit.w.h; /* Line 99, Address: 0x101a628 */
  scrb_h_posit_s = scrb_h_posit.w.h; /* Line 100, Address: 0x101a638 */
  scrb_v_posit_s = scrb_v_posit.w.h; /* Line 101, Address: 0x101a648 */
  scrc_h_posit_s = scrc_h_posit.w.h; /* Line 102, Address: 0x101a658 */
  scrc_v_posit_s = scrc_v_posit.w.h; /* Line 103, Address: 0x101a668 */
  scrz_h_posit_s = scrz_h_posit.w.h; /* Line 104, Address: 0x101a678 */
  scrz_v_posit_s = scrz_v_posit.w.h; /* Line 105, Address: 0x101a688 */
  waterposi_m_s = waterposi_m; /* Line 106, Address: 0x101a698 */
  waterflag_s = waterflag; /* Line 107, Address: 0x101a6a8 */
  if (pltime.l >= 327680) pltime_s = 327680; /* Line 108, Address: 0x101a6b8 */
  else pltime_s = pltime.l; /* Line 109, Address: 0x101a6e4 */

} /* Line 111, Address: 0x101a6f4 */













void marker(sprite_status* markerwk) { /* Line 125, Address: 0x101a700 */
  switch (markerwk->r_no0) { /* Line 126, Address: 0x101a70c */
    case 0:
      marker_init(markerwk); /* Line 128, Address: 0x101a74c */
      break; /* Line 129, Address: 0x101a758 */
    case 2:
      marker_move0(markerwk); /* Line 131, Address: 0x101a760 */
      break; /* Line 132, Address: 0x101a76c */
    case 4:
      marker_move1(markerwk); /* Line 134, Address: 0x101a774 */
      break; /* Line 135, Address: 0x101a780 */
    case 6:
      marker_move2(markerwk); /* Line 137, Address: 0x101a788 */
      break;
  }


  actionsub(markerwk); /* Line 142, Address: 0x101a794 */
  frameout_s(markerwk); /* Line 143, Address: 0x101a7a0 */
} /* Line 144, Address: 0x101a7ac */


void marker_init(sprite_status* markerwk) { /* Line 147, Address: 0x101a7c0 */
  sprite_status *new_actwk, **parent;
  unsigned short marker_yposi_m_buf;

  markerwk->r_no0 += 2; /* Line 151, Address: 0x101a7d4 */
  markerwk->patbase = markerpat; /* Line 152, Address: 0x101a7e4 */
  markerwk->sproffset = 1739; /* Line 153, Address: 0x101a7f4 */
  markerwk->actflg = 4; /* Line 154, Address: 0x101a800 */
  markerwk->sprhsize = 8; /* Line 155, Address: 0x101a80c */
  markerwk->sprvsize = 24; /* Line 156, Address: 0x101a818 */
  markerwk->sprpri = 4; /* Line 157, Address: 0x101a824 */

  if (markerno >= (unsigned char)markerwk->userflag.b.h) /* Line 159, Address: 0x101a830 */
    markerwk->actfree[4] = 1; /* Line 160, Address: 0x101a858 */
  else
    markerwk->colino = 227; /* Line 162, Address: 0x101a86c */
  if (actwkchk(&new_actwk) != 0) { frameout(markerwk); return; } /* Line 163, Address: 0x101a878 */
  new_actwk->actno = 19; /* Line 164, Address: 0x101a8a0 */
  new_actwk->r_no0 += 4; /* Line 165, Address: 0x101a8ac */
  if (markerwk->actfree[4] != 0) new_actwk->r_no0 += 2; /* Line 166, Address: 0x101a8bc */
  new_actwk->patbase = markerpat; /* Line 167, Address: 0x101a8e0 */
  new_actwk->sproffset = 1739; /* Line 168, Address: 0x101a8f0 */
  new_actwk->actflg = 4; /* Line 169, Address: 0x101a8fc */
  new_actwk->sprhsize = 8; /* Line 170, Address: 0x101a908 */
  new_actwk->sprvsize = 8; /* Line 171, Address: 0x101a914 */
  new_actwk->sprpri = 3; /* Line 172, Address: 0x101a920 */
  new_actwk->patno = 1; /* Line 173, Address: 0x101a92c */
  parent = &((sprite_status**)new_actwk)[13]; /* Line 174, Address: 0x101a938 */
  *parent = markerwk; /* Line 175, Address: 0x101a940 */
  new_actwk->xposi.w.h = markerwk->xposi.w.h; /* Line 176, Address: 0x101a948 */
  new_actwk->yposi.w.h = markerwk->yposi.w.h - 32; /* Line 177, Address: 0x101a958 */
  ((short*)new_actwk)[23] = markerwk->xposi.w.h; /* Line 178, Address: 0x101a97c */
  marker_yposi_m_buf = markerwk->yposi.w.h - 24; /* Line 179, Address: 0x101a98c */
  ((short*)new_actwk)[24] = marker_yposi_m_buf; /* Line 180, Address: 0x101a9a8 */
} /* Line 181, Address: 0x101a9b0 */


void marker_move0(sprite_status* markerwk) { /* Line 184, Address: 0x101a9d0 */


  if (markerwk->actfree[4] != 0) return; /* Line 187, Address: 0x101a9dc */







  if (markerwk->colicnt == 0) return; /* Line 195, Address: 0x101a9f0 */
  markerwk->colino = 0; /* Line 196, Address: 0x101aa04 */
  markerwk->actfree[4] = 1; /* Line 197, Address: 0x101aa0c */
  markerno = markerwk->userflag.b.h; /* Line 198, Address: 0x101aa18 */
  plflag = 1; /* Line 199, Address: 0x101aa28 */
  playsave0(markerwk); /* Line 200, Address: 0x101aa34 */
  soundset(174); /* Line 201, Address: 0x101aa40 */
} /* Line 202, Address: 0x101aa4c */


void marker_move1(sprite_status* markerwk) { /* Line 205, Address: 0x101aa60 */
  int sin_data, cos_data;
  short sin_tmp, cos_tmp;
  sprite_status **parent, *new_actwk;

  if (markerwk->actfree[4] == 0) { /* Line 210, Address: 0x101aa7c */
    parent = &((sprite_status**)markerwk)[13]; /* Line 211, Address: 0x101aa90 */
    new_actwk = *parent; /* Line 212, Address: 0x101aa98 */
    if (new_actwk->actfree[4] == 0) return; /* Line 213, Address: 0x101aa9c */
    markerwk->actfree[4] = 1; /* Line 214, Address: 0x101aaac */
  }

  markerwk->actfree[10] += 8; /* Line 217, Address: 0x101aab8 */
  sinset(markerwk->actfree[10], &sin_tmp, &cos_tmp); /* Line 218, Address: 0x101aac8 */
  sin_data = sin_tmp; /* Line 219, Address: 0x101aae0 */
  cos_data = cos_tmp; /* Line 220, Address: 0x101aaec */
  sin_data <<= 3; /* Line 221, Address: 0x101aaf8 */
  sin_data /= 256; /* Line 222, Address: 0x101aafc */
  markerwk->xposi.w.h = ((short*)markerwk)[23]; /* Line 223, Address: 0x101ab18 */
  markerwk->xposi.w.h += sin_data; /* Line 224, Address: 0x101ab28 */
  cos_data = -cos_data << 3; /* Line 225, Address: 0x101ab40 */
  cos_data /= 256; /* Line 226, Address: 0x101ab48 */
  markerwk->yposi.w.h = ((short*)markerwk)[24]; /* Line 227, Address: 0x101ab64 */
  markerwk->yposi.w.h += cos_data; /* Line 228, Address: 0x101ab74 */
  if (markerwk->actfree[10] == 0) markerwk->r_no0 += 2; /* Line 229, Address: 0x101ab8c */
} /* Line 230, Address: 0x101abb0 */


void marker_move2(sprite_status* markerwk) { /* Line 233, Address: 0x101abd0 */
  patchg(markerwk, markerchg); /* Line 234, Address: 0x101abdc */
} /* Line 235, Address: 0x101abf0 */






















































void tensuu_set(sprite_status* tensuuwk) { /* Line 290, Address: 0x101ac00 */
  if (tensuuwk->r_no1 != 0) return; /* Line 291, Address: 0x101ac0c */
  tensuu0(tensuuwk, tensuuwk->actfree[21] >> 1); /* Line 292, Address: 0x101ac20 */
} /* Line 293, Address: 0x101ac40 */


void tensuu0(sprite_status* tensuuwk, unsigned char uf_data) { /* Line 296, Address: 0x101ac50 */
  sprite_status* new_actwk;

  uf_data |= 128; /* Line 299, Address: 0x101ac60 */
  if (actwkchk(&new_actwk) != 0) return; /* Line 300, Address: 0x101ac6c */
  new_actwk->actno = 28; /* Line 301, Address: 0x101ac80 */
  new_actwk->xposi.w.h = tensuuwk->xposi.w.h; /* Line 302, Address: 0x101ac8c */
  new_actwk->yposi.w.h = tensuuwk->yposi.w.h; /* Line 303, Address: 0x101ac9c */
  new_actwk->userflag.b.h = uf_data; /* Line 304, Address: 0x101acac */
} /* Line 305, Address: 0x101acb8 */








void bakuha(sprite_status* bakuhawk) { /* Line 314, Address: 0x101acd0 */
  switch (bakuhawk->r_no0) { /* Line 315, Address: 0x101acdc */
    case 0:
      baku_init(bakuhawk); /* Line 317, Address: 0x101ad10 */
      break; /* Line 318, Address: 0x101ad1c */
    case 2:
      baku_move(bakuhawk); /* Line 320, Address: 0x101ad24 */
      break; /* Line 321, Address: 0x101ad30 */
    case 4:
      baku_die(bakuhawk); /* Line 323, Address: 0x101ad38 */
      break;
  }


} /* Line 328, Address: 0x101ad44 */


void baku_init(sprite_status* bakuhawk) { /* Line 331, Address: 0x101ad60 */
  bakuhawk->r_no0 += 2; /* Line 332, Address: 0x101ad6c */
  bakuhawk->actflg |= 4; /* Line 333, Address: 0x101ad7c */
  bakuhawk->sprpri = 1; /* Line 334, Address: 0x101ad8c */

  bakuhawk->sproffset = 1664; /* Line 336, Address: 0x101ad98 */


  bakuhawk->patbase = bakupat; /* Line 339, Address: 0x101ada4 */
  tensuu_set(bakuhawk); /* Line 340, Address: 0x101adb4 */
  bakuhawk->colino = 0; /* Line 341, Address: 0x101adc0 */
  bakuhawk->patcnt = 0; /* Line 342, Address: 0x101adc8 */
  bakuhawk->pattim = 0; /* Line 343, Address: 0x101add0 */
  bakuhawk->mstno.w = 0; /* Line 344, Address: 0x101add8 */
  if (bakuhawk->userflag.b.h != 0) bakuhawk->mstno.w = 256; /* Line 345, Address: 0x101ade0 */
  baku_move(bakuhawk); /* Line 346, Address: 0x101ae04 */
} /* Line 347, Address: 0x101ae10 */


void baku_move(sprite_status* bakuhawk) { /* Line 350, Address: 0x101ae20 */
  patchg(bakuhawk, bakuchg); /* Line 351, Address: 0x101ae2c */
  actionsub(bakuhawk); /* Line 352, Address: 0x101ae40 */
} /* Line 353, Address: 0x101ae4c */


void baku_die(sprite_status* bakuhawk) { /* Line 356, Address: 0x101ae60 */
  if (bakuhawk->r_no1 != 0) { frameout(bakuhawk); return; } /* Line 357, Address: 0x101ae6c */
  bakuhawk->actno = 31; /* Line 358, Address: 0x101ae94 */
  bakuhawk->r_no0 = 0; /* Line 359, Address: 0x101aea0 */
} /* Line 360, Address: 0x101aea8 */
















































void flower(sprite_status* flowerwk) { /* Line 409, Address: 0x101aec0 */
  switch (flowerwk->r_no0) { /* Line 410, Address: 0x101aecc */
    case 0:
      flow_init(flowerwk); /* Line 412, Address: 0x101af18 */
      break; /* Line 413, Address: 0x101af24 */
    case 2:
      flow_move0(flowerwk); /* Line 415, Address: 0x101af2c */
      break; /* Line 416, Address: 0x101af38 */
    case 4:
      flow_move1(flowerwk); /* Line 418, Address: 0x101af40 */
      break; /* Line 419, Address: 0x101af4c */
    case 6:
      flow_move2(flowerwk); /* Line 421, Address: 0x101af54 */
      break; /* Line 422, Address: 0x101af60 */
    case 8:
      flow_move3(flowerwk); /* Line 424, Address: 0x101af68 */
      break;
  }


  actionsub(flowerwk); /* Line 429, Address: 0x101af74 */
} /* Line 430, Address: 0x101af80 */



void flow_init(sprite_status* flowerwk) { /* Line 434, Address: 0x101af90 */
  unsigned char* fwcnt_adr;
  fwcnt_adr = &flagworkcnt; /* Line 436, Address: 0x101afa0 */

  flowerwk->actflg |= 4; /* Line 438, Address: 0x101afa8 */
  flowerwk->sprpri = 1; /* Line 439, Address: 0x101afb8 */
  flowerwk->sprvsize = 0; /* Line 440, Address: 0x101afc4 */

  flowerwk->sproffset = 9943; /* Line 442, Address: 0x101afcc */



  flowerwk->patbase = flow_pat; /* Line 446, Address: 0x101afd8 */
  if (flowerwk->userflag.b.h == 0) { /* Line 447, Address: 0x101afe8 */
    fwcnt_adr = flow_sub(flowerwk); /* Line 448, Address: 0x101b000 */
    flowerwk->r_no0 = 4; /* Line 449, Address: 0x101b010 */
    flowerwk->mstno.b.h = 3; /* Line 450, Address: 0x101b01c */
    if (*fwcnt_adr & 64) { flow_move1(flowerwk); return; } /* Line 451, Address: 0x101b028 */
  }
  flowerwk->mstno.w = 2; /* Line 453, Address: 0x101b050 */
  flowerwk->r_no0 = 2; /* Line 454, Address: 0x101b05c */
  flowerwk->sproffset = 1751; /* Line 455, Address: 0x101b068 */
  flow_move0(flowerwk); /* Line 456, Address: 0x101b074 */
} /* Line 457, Address: 0x101b080 */


void flow_move0(sprite_status* flowerwk) { /* Line 460, Address: 0x101b0a0 */
  short y_move = 0, flower_index = 0; /* Line 461, Address: 0x101b0b8 */
  unsigned char* fwcnt_adr;

  y_move = emycol_d(flowerwk); /* Line 464, Address: 0x101b0c0 */
  if (y_move < 0) { /* Line 465, Address: 0x101b0d4 */
    flowerwk->yposi.w.h += y_move; /* Line 466, Address: 0x101b0e4 */
    if (flowerwk->userflag.b.h == 0) { /* Line 467, Address: 0x101b0f4 */
      fwcnt_adr = flow_sub(flowerwk); /* Line 468, Address: 0x101b10c */
      flower_index = flow_sub1(flowercnt[time_flag & 127]++); /* Line 469, Address: 0x101b11c */
      flowerposi[flower_index].w.h = flowerwk->xposi.w.h; /* Line 470, Address: 0x101b154 */
      flowerposi[flower_index].w.l = flowerwk->yposi.w.h; /* Line 471, Address: 0x101b178 */
    }
    flowerwk->r_no0 = 4; /* Line 473, Address: 0x101b19c */
    flowerwk->mstno.b.h = 1; /* Line 474, Address: 0x101b1a8 */
    flowerwk->sprvsize = 48; /* Line 475, Address: 0x101b1b4 */
    flow_move1(flowerwk); /* Line 476, Address: 0x101b1c0 */
  } else { /* Line 477, Address: 0x101b1cc */
    flowerwk->yposi.w.h += 2; /* Line 478, Address: 0x101b1d4 */
    flow_move1(flowerwk); /* Line 479, Address: 0x101b1e4 */
  }

} /* Line 482, Address: 0x101b1f0 */


void flow_move1(sprite_status* flowerwk) { /* Line 485, Address: 0x101b210 */
  patchg(flowerwk, flowchg); /* Line 486, Address: 0x101b21c */
} /* Line 487, Address: 0x101b230 */


unsigned char* flow_sub(sprite_status* flowerwk) { /* Line 490, Address: 0x101b240 */
  short index;

  index = (time_flag & 127) + flowerwk->cdsts * 2; /* Line 493, Address: 0x101b24c */
  return &flagwork[index]; /* Line 494, Address: 0x101b294 */
} /* Line 495, Address: 0x101b2a8 */


short flow_sub1(unsigned char fl_counter) { /* Line 498, Address: 0x101b2c0 */
  short flower_index;

  flower_index = ((unsigned short)fl_counter & 63) + (unsigned short)(time_flag & 127) * 64; /* Line 501, Address: 0x101b2cc */


  return flower_index; /* Line 504, Address: 0x101b30c */
} /* Line 505, Address: 0x101b310 */


void flow_move2(sprite_status* flowerwk) { /* Line 508, Address: 0x101b320 */
  flowerwk->sproffset = 9943; /* Line 509, Address: 0x101b32c */

  flowerwk->mstno.b.h = 2; /* Line 511, Address: 0x101b338 */
  flow_move1(flowerwk); /* Line 512, Address: 0x101b344 */
} /* Line 513, Address: 0x101b350 */


void flow_move3(sprite_status* flowerwk) { /* Line 516, Address: 0x101b360 */
  flowerwk->mstno.b.h = 3; /* Line 517, Address: 0x101b36c */
  flowerwk->r_no0 = 4; /* Line 518, Address: 0x101b378 */
  flow_move1(flowerwk); /* Line 519, Address: 0x101b384 */
} /* Line 520, Address: 0x101b390 */






























































































































































void exit2(sprite_status* exitwk) { /* Line 679, Address: 0x101b3a0 */
  switch (exitwk->r_no0) { /* Line 680, Address: 0x101b3ac */
    case 0:
      exit2_init(exitwk); /* Line 682, Address: 0x101b3e0 */
      break; /* Line 683, Address: 0x101b3ec */
    case 2:
      exit2_move(exitwk); /* Line 685, Address: 0x101b3f4 */
      break; /* Line 686, Address: 0x101b400 */
    case 4:
      exit2_erase(exitwk); /* Line 688, Address: 0x101b408 */
      break;
  }


} /* Line 693, Address: 0x101b414 */


void exit2_init(sprite_status* exitwk) { /* Line 696, Address: 0x101b430 */
  exitwk->r_no0 += 2; /* Line 697, Address: 0x101b43c */
  exitwk->actflg = 4; /* Line 698, Address: 0x101b44c */
  exitwk->sprpri = 1; /* Line 699, Address: 0x101b458 */
  exitwk->patbase = exit2pat; /* Line 700, Address: 0x101b464 */
  exitwk->sproffset = 664; /* Line 701, Address: 0x101b474 */
  exitwk->mstno.b.h = exitwk->userflag.b.h; /* Line 702, Address: 0x101b480 */

  if (exitwk->userflag.b.h < 2) soundset(162); /* Line 704, Address: 0x101b490 */
  else soundset(161); /* Line 705, Address: 0x101b4c0 */
  exit2_move(exitwk); /* Line 706, Address: 0x101b4cc */
} /* Line 707, Address: 0x101b4d8 */


void exit2_move(sprite_status* exitwk) { /* Line 710, Address: 0x101b4f0 */
  exitwk->yposi.w.h = waterposi; /* Line 711, Address: 0x101b4fc */
  exitwk->yposi.w.h += 4; /* Line 712, Address: 0x101b50c */
  patchg(exitwk, exit2chg); /* Line 713, Address: 0x101b51c */
  actionsub(exitwk); /* Line 714, Address: 0x101b530 */
} /* Line 715, Address: 0x101b53c */


void exit2_erase(sprite_status* exitwk) { /* Line 718, Address: 0x101b550 */
  frameout(exitwk); /* Line 719, Address: 0x101b55c */
} /* Line 720, Address: 0x101b568 */









void baria(sprite_status* bariawk) { /* Line 730, Address: 0x101b580 */
  switch (bariawk->r_no0) { /* Line 731, Address: 0x101b58c */
    case 0:
      bariainit(bariawk); /* Line 733, Address: 0x101b5cc */
      break; /* Line 734, Address: 0x101b5d8 */
    case 2:
      bariamove(bariawk); /* Line 736, Address: 0x101b5e0 */
      break; /* Line 737, Address: 0x101b5ec */
    case 4:
      mutekimove(bariawk); /* Line 739, Address: 0x101b5f4 */
      break; /* Line 740, Address: 0x101b600 */
    case 6:
      backtomove(bariawk); /* Line 742, Address: 0x101b608 */
      break;
  }


} /* Line 747, Address: 0x101b614 */


void bariainit(sprite_status* bariawk) { /* Line 750, Address: 0x101b630 */
  bariawk->r_no0 += 2; /* Line 751, Address: 0x101b638 */
  bariawk->patbase = bariapat; /* Line 752, Address: 0x101b648 */
  bariawk->actflg = 4; /* Line 753, Address: 0x101b658 */
  bariawk->sprpri = 1; /* Line 754, Address: 0x101b664 */
  bariawk->sprhsize = 16; /* Line 755, Address: 0x101b670 */
  bariawk->sproffset = 1348; /* Line 756, Address: 0x101b67c */
  if (bariawk->mstno.b.h == 0) return; /* Line 757, Address: 0x101b688 */
  bariawk->r_no0 += 2; /* Line 758, Address: 0x101b6a0 */
  if (bariawk->mstno.b.h < 5) return; /* Line 759, Address: 0x101b6b0 */
  bariawk->r_no0 += 2; /* Line 760, Address: 0x101b6cc */
} /* Line 761, Address: 0x101b6dc */


void bariamove(sprite_status* bariawk) { /* Line 764, Address: 0x101b6f0 */
  if (plpower_b == 0) { frameout(bariawk); return; } /* Line 765, Address: 0x101b6fc */
  if (plpower_a != 0 || plpower_m != 0) return; /* Line 766, Address: 0x101b724 */
  bariawk->xposi.w.h = actwk[0].xposi.w.h; /* Line 767, Address: 0x101b754 */
  bariawk->yposi.w.h = actwk[0].yposi.w.h; /* Line 768, Address: 0x101b764 */
  bariawk->cddat = actwk[0].cddat; /* Line 769, Address: 0x101b774 */







  patchg(bariawk, bariachg); /* Line 777, Address: 0x101b784 */
  actionsub0(bariawk); /* Line 778, Address: 0x101b798 */
} /* Line 779, Address: 0x101b7a4 */


void mutekimove(sprite_status* bariawk) { /* Line 782, Address: 0x101b7c0 */
  if (plpower_a != 0) return; /* Line 783, Address: 0x101b7cc */
  if (plpower_m != 0) { muteki_sub(bariawk); return; } /* Line 784, Address: 0x101b7e0 */
  frameout(bariawk); /* Line 785, Address: 0x101b808 */
} /* Line 786, Address: 0x101b814 */


void backtomove(sprite_status* bariawk) { /* Line 789, Address: 0x101b830 */
  if (plpower_a != 0) { muteki_sub(bariawk); return; } /* Line 790, Address: 0x101b83c */
  frameout(bariawk); /* Line 791, Address: 0x101b864 */
} /* Line 792, Address: 0x101b870 */



void muteki_sub(sprite_status* bariawk) { /* Line 796, Address: 0x101b880 */
  ushort_union ppw_offset;
  unsigned char cal_no;








  ppw_offset.w = plposiwkadr.w; /* Line 807, Address: 0x101b890 */
  cal_no = bariawk->mstno.b.h - 1; /* Line 808, Address: 0x101b89c */
  if (cal_no >= 4) cal_no -= 4; /* Line 809, Address: 0x101b8b8 */
  cal_no = cal_no * 24 + 4; /* Line 810, Address: 0x101b8d0 */
  ppw_offset.b.l -= cal_no; /* Line 811, Address: 0x101b8ec */
  cal_no = bariawk->actfree[6]; /* Line 812, Address: 0x101b904 */
  ppw_offset.b.l -= cal_no; /* Line 813, Address: 0x101b910 */
  if ((cal_no += 4) >= 24) cal_no = 0; /* Line 814, Address: 0x101b928 */
  bariawk->actfree[6] = cal_no; /* Line 815, Address: 0x101b948 */

  bariawk->xposi.w.h = playposiwk[ppw_offset.w / 2]; /* Line 817, Address: 0x101b950 */
  bariawk->yposi.w.h = playposiwk[ppw_offset.w / 2 + 1]; /* Line 818, Address: 0x101b98c */

  bariawk->cddat = actwk[0].cddat; /* Line 820, Address: 0x101b9cc */
  patchg(bariawk, bariachg); /* Line 821, Address: 0x101b9dc */
  actionsub0(bariawk); /* Line 822, Address: 0x101b9f0 */
} /* Line 823, Address: 0x101b9fc */



void actionsub0(sprite_status* bariawk) { /* Line 827, Address: 0x101ba10 */
  if (plsubchg_flag >= 8) return; /* Line 828, Address: 0x101ba1c */

  if (bariawk->r_no0 != 0) plsubchg_flag = bariawk->r_no0 | 128; /* Line 830, Address: 0x101ba38 */
  actionsub(bariawk); /* Line 831, Address: 0x101ba68 */
} /* Line 832, Address: 0x101ba74 */




























































































































void test_act(sprite_status* testwk) { /* Line 957, Address: 0x101ba90 */
  tensuu_set(testwk); /* Line 958, Address: 0x101ba9c */
} /* Line 959, Address: 0x101baa8 */


void mizukiri(sprite_status* mizukiwk) { /* Line 962, Address: 0x101bac0 */
  exit2(mizukiwk); /* Line 963, Address: 0x101bacc */
} /* Line 964, Address: 0x101bad8 */


void futa(sprite_status* futawk) { /* Line 967, Address: 0x101baf0 */
  exit2(futawk); /* Line 968, Address: 0x101bafc */
} /* Line 969, Address: 0x101bb08 */


void exit2_set(sprite_status* testwk) { /* Line 972, Address: 0x101bb20 */
  exit2(testwk); /* Line 973, Address: 0x101bb2c */
} /* Line 974, Address: 0x101bb38 */


void plairset() { /* Line 977, Address: 0x101bb50 */
  short wD0;

  if (pl_air < 13) { /* Line 980, Address: 0x101bb5c */
    wD0 = 130; /* Line 981, Address: 0x101bb78 */
    if (stageno.w == 259) wD0 = 134; /* Line 982, Address: 0x101bb84 */

    if (plpower_m) wD0 = 135; /* Line 984, Address: 0x101bbac */

    if (bossstart) wD0 = 140; /* Line 986, Address: 0x101bbc8 */

    bgmset(wD0); /* Line 988, Address: 0x101bbe4 */
  }

  pl_air = 30; /* Line 991, Address: 0x101bbf0 */
  actwk[7].actfree[8] = 0; /* Line 992, Address: 0x101bbfc */
} /* Line 993, Address: 0x101bc04 */





















































































































































































































void plawamaster(sprite_status* pActwk) { /* Line 1207, Address: 0x101bc20 */
  if (!((unsigned short*)pActwk)[24]) { /* Line 1208, Address: 0x101bc2c */
    if (actwk[0].r_no0 >= 6) return; /* Line 1209, Address: 0x101bc3c */
    if (!(actwk[0].cddat & 64)) return; /* Line 1210, Address: 0x101bc54 */
    if (--((short*)pActwk)[30] >= 0) { /* Line 1211, Address: 0x101bc6c */
      plawamaster_jump(pActwk); /* Line 1212, Address: 0x101bc94 */
      return; /* Line 1213, Address: 0x101bca0 */
    }
    ((short*)pActwk)[30] = 59; /* Line 1215, Address: 0x101bca8 */
    ((short*)pActwk)[29] = 1; /* Line 1216, Address: 0x101bcb4 */
    pActwk->actfree[10] = random() & 1; /* Line 1217, Address: 0x101bcc0 */

    if (pl_air != 25) { /* Line 1219, Address: 0x101bcd8 */
      if (pl_air != 20) { /* Line 1220, Address: 0x101bcf4 */
        if (pl_air != 15) { /* Line 1221, Address: 0x101bd10 */
          if (pl_air < 13) { /* Line 1222, Address: 0x101bd2c */

            if (!(gametimer.b.l & 32)) soundset(223); /* Line 1224, Address: 0x101bd48 */

            if (--pActwk->actfree[8] & 128) { /* Line 1226, Address: 0x101bd70 */
              pActwk->actfree[8] = pActwk->actfree[9]; /* Line 1227, Address: 0x101bd94 */
              pActwk->actfree[12] |= 128; /* Line 1228, Address: 0x101bda4 */
            }
          }
        }
      }
    }


    if (--pl_air >= 0) { /* Line 1236, Address: 0x101bdb4 */
      plawamaster_jump0(pActwk); /* Line 1237, Address: 0x101bde0 */
      return; /* Line 1238, Address: 0x101bdec */
    }

    plairset(); /* Line 1241, Address: 0x101bdf4 */
    actwk[0].actfree[2] = 129; /* Line 1242, Address: 0x101bdfc */
    soundset(182); /* Line 1243, Address: 0x101be08 */
    pActwk->actfree[10] = 10; /* Line 1244, Address: 0x101be14 */
    ((short*)pActwk)[29] = 1; /* Line 1245, Address: 0x101be20 */
    ((short*)pActwk)[24] = 120; /* Line 1246, Address: 0x101be2c */

    jumpcolsub(); /* Line 1248, Address: 0x101be38 */
    actwk[0].mstno.b.h = 23; /* Line 1249, Address: 0x101be40 */
    actwk[0].cddat |= 2; /* Line 1250, Address: 0x101be4c */


    actwk[0].sproffset |= 32768; /* Line 1253, Address: 0x101be60 */
    actwk[0].sprpri = 0; /* Line 1254, Address: 0x101be74 */
    actwk[0].yspeed.w = 0; /* Line 1255, Address: 0x101be7c */
    actwk[0].xspeed.w = 0; /* Line 1256, Address: 0x101be84 */
    actwk[0].mspeed.w = 0; /* Line 1257, Address: 0x101be8c */
    scroll_start.b.h = 1; /* Line 1258, Address: 0x101be94 */
    return; /* Line 1259, Address: 0x101bea0 */
  }

  if (!(--((short*)pActwk)[24])) { /* Line 1262, Address: 0x101bea8 */
    actwk[0].r_no0 = 6; /* Line 1263, Address: 0x101bec8 */
    return; /* Line 1264, Address: 0x101bed4 */
  }

  speedset2(&actwk[0]); /* Line 1267, Address: 0x101bedc */
  actwk[0].yspeed.w += 16; /* Line 1268, Address: 0x101beec */
  plawamaster_jump(pActwk); /* Line 1269, Address: 0x101bf00 */
} /* Line 1270, Address: 0x101bf0c */



void plawamaster_jump0(sprite_status* pActwk) { /* Line 1274, Address: 0x101bf20 */
  plawamaster_jump2(pActwk); /* Line 1275, Address: 0x101bf2c */
} /* Line 1276, Address: 0x101bf38 */



void plawamaster_jump(sprite_status* pActwk) { /* Line 1280, Address: 0x101bf50 */
  if (!((short*)pActwk)[29]) return; /* Line 1281, Address: 0x101bf5c */
  if (--((short*)pActwk)[31] >= 0) return; /* Line 1282, Address: 0x101bf6c */
  plawamaster_jump2(pActwk); /* Line 1283, Address: 0x101bf94 */
} /* Line 1284, Address: 0x101bfa0 */



void plawamaster_jump2(sprite_status* pActwk) { /* Line 1288, Address: 0x101bfb0 */
  sprite_status* pNewactwk;
  short wD0;

  ((short*)pActwk)[31] = random() & 15; /* Line 1292, Address: 0x101bfc0 */
  if (actwkchk(&pNewactwk) == 0) { /* Line 1293, Address: 0x101bfe4 */
    pNewactwk->actno = 33; /* Line 1294, Address: 0x101bff8 */
    pNewactwk->xposi.w.h = actwk[0].xposi.w.h; /* Line 1295, Address: 0x101c004 */
    wD0 = 6; /* Line 1296, Address: 0x101c014 */
    if (actwk[0].cddat & 1) { /* Line 1297, Address: 0x101c020 */
      wD0 = -wD0; /* Line 1298, Address: 0x101c038 */
      pNewactwk->direc.b.h = 64; /* Line 1299, Address: 0x101c044 */
    }

    pNewactwk->xposi.w.h += wD0; /* Line 1302, Address: 0x101c050 */
    pNewactwk->yposi.w.h = actwk[0].yposi.w.h; /* Line 1303, Address: 0x101c060 */
    pNewactwk->userflag.b.h = 6; /* Line 1304, Address: 0x101c070 */

    if (((unsigned short*)pActwk)[24]) { /* Line 1306, Address: 0x101c07c */
      ((unsigned short*)pActwk)[31] &= 7; /* Line 1307, Address: 0x101c08c */
      pActwk; /* Line 1308, Address: 0x101c09c */
      pNewactwk->yposi.w.h = actwk[0].yposi.w.h - 12; /* Line 1309, Address: 0x101c0a0 */
      pNewactwk->direc.b.h = random() & 255; /* Line 1310, Address: 0x101c0c4 */
      if (!(gametimer.w & 3)) pNewactwk->userflag.b.h = 14; /* Line 1311, Address: 0x101c0e0 */
    } /* Line 1312, Address: 0x101c108 */
    else {

      if (pActwk->actfree[12] & 128) { /* Line 1315, Address: 0x101c110 */
        pNewactwk->sproffset = 8192; /* Line 1316, Address: 0x101c128 */
        if (!(random() & 3)) { /* Line 1317, Address: 0x101c134 */
          if (pActwk->actfree[12] & 64) goto label1; /* Line 1318, Address: 0x101c148 */
          pActwk->actfree[12] |= 64; /* Line 1319, Address: 0x101c160 */
          pNewactwk->userflag.b.h = (unsigned short)pl_air >> 1 & 255; /* Line 1320, Address: 0x101c170 */
          ((short*)pNewactwk)[30] = 28; /* Line 1321, Address: 0x101c198 */
        }

        if (!pActwk->actfree[10]) { /* Line 1324, Address: 0x101c1a4 */
          if (pActwk->actfree[12] & 64) goto label1; /* Line 1325, Address: 0x101c1b4 */
          pActwk->actfree[12] |= 64; /* Line 1326, Address: 0x101c1cc */
          pNewactwk->userflag.b.h = pl_air >> 1 & 255; /* Line 1327, Address: 0x101c1dc */
          ((short*)pNewactwk)[30] = 28; /* Line 1328, Address: 0x101c204 */
        }
      }
    }

label1:
    if (--pActwk->actfree[10] & 128) ((short*)pActwk)[29] = 0; /* Line 1334, Address: 0x101c210 */
  }


} /* Line 1338, Address: 0x101c23c */








void plawa(sprite_status* pActwk) { /* Line 1347, Address: 0x101c250 */
  void(*plawa_move_tbl[9])(sprite_status*) = { /* Line 1348, Address: 0x101c25c */
    &plawainit,
    &plawamove,
    &plawamove2,
    &plawamove3,
    &plawamove4,
    &plawamaster,
    &plawamove5,
    &plawamove3,
    &plawamove4
  };

  plawa_move_tbl[pActwk->r_no0 / 2](pActwk); /* Line 1360, Address: 0x101c288 */
} /* Line 1361, Address: 0x101c2c4 */








void plawainit(sprite_status* pActwk) { /* Line 1370, Address: 0x101c2e0 */
  pActwk->r_no0 += 2; /* Line 1371, Address: 0x101c2ec */
  pActwk->patbase = awapat; /* Line 1372, Address: 0x101c2fc */
  pActwk->sproffset |= 33930; /* Line 1373, Address: 0x101c30c */
  pActwk->actflg = 132; /* Line 1374, Address: 0x101c31c */
  pActwk->sprhsize = 16; /* Line 1375, Address: 0x101c328 */
  pActwk->sprpri = 1; /* Line 1376, Address: 0x101c334 */
  if (pActwk->userflag.b.h & 128) { /* Line 1377, Address: 0x101c340 */
    pActwk->r_no0 += 8; /* Line 1378, Address: 0x101c35c */
    pActwk->patbase = awapat; /* Line 1379, Address: 0x101c36c */
    pActwk->sproffset |= 1162; /* Line 1380, Address: 0x101c37c */
    pActwk->actfree[9] = pActwk->userflag.b.h & 127; /* Line 1381, Address: 0x101c38c */
    plawamaster(pActwk); /* Line 1382, Address: 0x101c3ac */
  } /* Line 1383, Address: 0x101c3b8 */
  else {

    pActwk->mstno.b.h = pActwk->userflag.b.h; /* Line 1386, Address: 0x101c3c0 */
    ((short*)pActwk)[26] = pActwk->xposi.w.h; /* Line 1387, Address: 0x101c3d0 */
    pActwk->yspeed.w = -136; /* Line 1388, Address: 0x101c3e0 */
    plawamove(pActwk); /* Line 1389, Address: 0x101c3ec */
  }
} /* Line 1391, Address: 0x101c3f8 */








void plawamove(sprite_status* pActwk) { /* Line 1400, Address: 0x101c410 */
  patchg(pActwk, plawachg); /* Line 1401, Address: 0x101c41c */
  plawamove2(pActwk); /* Line 1402, Address: 0x101c430 */
} /* Line 1403, Address: 0x101c43c */








void plawamove2(sprite_status* pActwk) { /* Line 1412, Address: 0x101c450 */
  if (waterposi >= pActwk->yposi.w.h) { /* Line 1413, Address: 0x101c45c */


    pActwk->r_no0 = 6; /* Line 1416, Address: 0x101c488 */
    pActwk->mstno.b.h += 7; /* Line 1417, Address: 0x101c494 */
    if (pActwk->mstno.b.h >= 16) pActwk->mstno.b.h = 15; /* Line 1418, Address: 0x101c4a4 */

    plawamove3(pActwk); /* Line 1420, Address: 0x101c4cc */
    return; /* Line 1421, Address: 0x101c4d8 */
  }


  if (watercoliflag) ((short*)pActwk)[26] += 4; /* Line 1425, Address: 0x101c4e0 */

  pActwk->xposi.w.h = (char)awasintbl[pActwk->direc.b.h++ + 1 & 127] + ((short*)pActwk)[26]; /* Line 1427, Address: 0x101c500 */

  plawasub(pActwk); /* Line 1429, Address: 0x101c56c */
  speedset2(pActwk); /* Line 1430, Address: 0x101c578 */

  if (pActwk->actflg & 128) actionsub(pActwk); /* Line 1432, Address: 0x101c584 */
  else frameout(pActwk); /* Line 1433, Address: 0x101c5b0 */
} /* Line 1434, Address: 0x101c5bc */








void plawamove3(sprite_status* pActwk) { /* Line 1443, Address: 0x101c5d0 */
  plawasub(pActwk); /* Line 1444, Address: 0x101c5dc */
  patchg(pActwk, plawachg); /* Line 1445, Address: 0x101c5e8 */
  actionsub(pActwk); /* Line 1446, Address: 0x101c5fc */
} /* Line 1447, Address: 0x101c608 */








void plawamove4(sprite_status* pActwk) { /* Line 1456, Address: 0x101c620 */
  frameout(pActwk); /* Line 1457, Address: 0x101c62c */
} /* Line 1458, Address: 0x101c638 */








void plawamove5(sprite_status* pActwk) { /* Line 1467, Address: 0x101c650 */
  if (pl_air >= 13) { /* Line 1468, Address: 0x101c65c */
    frameout(pActwk); /* Line 1469, Address: 0x101c678 */
    return; /* Line 1470, Address: 0x101c684 */
  }
  if (!(--((short*)pActwk)[30])) { /* Line 1472, Address: 0x101c68c */
    pActwk->r_no0 = 14; /* Line 1473, Address: 0x101c6ac */
    pActwk->mstno.b.h += 7; /* Line 1474, Address: 0x101c6b8 */
    if (pActwk->mstno.b.h >= 16) pActwk->mstno.b.h = 15; /* Line 1475, Address: 0x101c6c8 */

    plawamove3(pActwk); /* Line 1477, Address: 0x101c6f0 */
    return; /* Line 1478, Address: 0x101c6fc */
  }

  patchg(pActwk, plawachg); /* Line 1481, Address: 0x101c704 */
  if (pActwk->actflg & 128) actionsub(pActwk); /* Line 1482, Address: 0x101c718 */
  else frameout(pActwk); /* Line 1483, Address: 0x101c744 */
} /* Line 1484, Address: 0x101c750 */








void plawasub(sprite_status* pActwk) { /* Line 1493, Address: 0x101c760 */
  if (((short*)pActwk)[30]) { /* Line 1494, Address: 0x101c768 */
    if (!(--((short*)pActwk)[30])) { /* Line 1495, Address: 0x101c778 */
      if (pActwk->mstno.b.h < 7) { /* Line 1496, Address: 0x101c798 */
        ((short*)pActwk)[30] = 15; /* Line 1497, Address: 0x101c7b4 */
        pActwk->yspeed.w = 0; /* Line 1498, Address: 0x101c7c0 */
        pActwk->actflg = 129; /* Line 1499, Address: 0x101c7c8 */
        pActwk->xposi.w.h = pActwk->xposi.w.h - scra_h_posit.w.h + 128; /* Line 1500, Address: 0x101c7d4 */
        pActwk->yposi.w.h = pActwk->yposi.w.h - scra_v_posit.w.h + 128; /* Line 1501, Address: 0x101c80c */
        pActwk->r_no0 = 12; /* Line 1502, Address: 0x101c844 */
      }
    }
  }

} /* Line 1507, Address: 0x101c850 */









void wave(sprite_status* pActwk) { /* Line 1517, Address: 0x101c860 */
  void(*wave_move_tbl[2])(sprite_status*) = { /* Line 1518, Address: 0x101c86c */
    &wave_init,
    &wave_move
  };

  wave_move_tbl[pActwk->r_no0 / 2](pActwk); /* Line 1523, Address: 0x101c888 */
  actionsub(pActwk); /* Line 1524, Address: 0x101c8c4 */
} /* Line 1525, Address: 0x101c8d0 */








void wave_init(sprite_status* pActwk) { /* Line 1534, Address: 0x101c8e0 */
  pActwk->actflg |= 4; /* Line 1535, Address: 0x101c8ec */
  pActwk->sproffset = 33408; /* Line 1536, Address: 0x101c8fc */
  pActwk->patbase = wavepat; /* Line 1537, Address: 0x101c908 */
  pActwk->r_no0 += 2; /* Line 1538, Address: 0x101c918 */
  wave_move(pActwk); /* Line 1539, Address: 0x101c928 */
} /* Line 1540, Address: 0x101c934 */








void wave_move(sprite_status* pActwk) { /* Line 1549, Address: 0x101c950 */
  short wave_tbl[2] = { /* Line 1550, Address: 0x101c95c */
    -96, 96
  };

  if (++pActwk->actfree[0] >= 4) { /* Line 1554, Address: 0x101c978 */
    pActwk->actfree[0] = 0; /* Line 1555, Address: 0x101c99c */
  }
  pActwk->xposi.w.h = scra_h_posit.w.h + 160 + wave_tbl[pActwk->actfree[0] / 2]; /* Line 1557, Address: 0x101c9a4 */
  pActwk->yposi.w.h = waterposi + 2; /* Line 1558, Address: 0x101ca04 */
  patchg(pActwk, wavechg); /* Line 1559, Address: 0x101ca28 */
} /* Line 1560, Address: 0x101ca3c */








void bou(sprite_status* pActwk) { /* Line 1569, Address: 0x101ca50 */
  void(*bou_move_tbl[4])(sprite_status*) = { /* Line 1570, Address: 0x101ca5c */
    &bou_init,
    &bou_move0,
    &bou_move1,
    &bou_move2
  };

  bou_move_tbl[pActwk->r_no0 / 2](pActwk); /* Line 1577, Address: 0x101ca88 */
  actionsub(pActwk); /* Line 1578, Address: 0x101cac4 */
  frameout_s(pActwk); /* Line 1579, Address: 0x101cad0 */
} /* Line 1580, Address: 0x101cadc */








void bou_init(sprite_status* pActwk) { /* Line 1589, Address: 0x101caf0 */
  pActwk->actflg |= 4; /* Line 1590, Address: 0x101cafc */
  pActwk->sproffset = 17144; /* Line 1591, Address: 0x101cb0c */
  pActwk->patbase = boupat; /* Line 1592, Address: 0x101cb18 */
  pActwk->r_no0 += 2; /* Line 1593, Address: 0x101cb28 */
  bou_move0(pActwk); /* Line 1594, Address: 0x101cb38 */
} /* Line 1595, Address: 0x101cb44 */








void bou_move0(sprite_status* pActwk) { /* Line 1604, Address: 0x101cb60 */
  short wD0, wD1;

  if (bou_coli(pActwk) != 0) { /* Line 1607, Address: 0x101cb74 */
    actwk[0].actfree[2] |= 1; /* Line 1608, Address: 0x101cb88 */

    actwk[0].xposi.w.h = pActwk->xposi.w.h; /* Line 1610, Address: 0x101cb9c */

    wD1 = 0; /* Line 1612, Address: 0x101cbac */
    wD0 = 24; /* Line 1613, Address: 0x101cbb0 */

    if (actwk[0].xspeed.w < 0) { /* Line 1615, Address: 0x101cbbc */
      wD1 = 1; /* Line 1616, Address: 0x101cbd4 */
      wD0 = -wD0; /* Line 1617, Address: 0x101cbe0 */
    }

    actwk[0].cddat &= 254; /* Line 1620, Address: 0x101cbec */
    actwk[0].cddat |= wD1; /* Line 1621, Address: 0x101cc00 */
    pActwk->actflg |= wD1; /* Line 1622, Address: 0x101cc18 */
    actwk[0].xposi.w.h += wD0; /* Line 1623, Address: 0x101cc2c */
    actwk[0].mstno.b.h = 17; /* Line 1624, Address: 0x101cc40 */
    ((short*)pActwk)[23] = 180; /* Line 1625, Address: 0x101cc4c */
    if (pActwk->userflag.b.h) ((short*)pActwk)[23] = 60; /* Line 1626, Address: 0x101cc58 */



    pActwk->r_no0 += 2; /* Line 1630, Address: 0x101cc74 */
  }
} /* Line 1632, Address: 0x101cc84 */








void bou_move1(sprite_status* pActwk) { /* Line 1641, Address: 0x101cca0 */


  if (--((short*)pActwk)[23]) { /* Line 1644, Address: 0x101cca8 */

    if (!(swdata1.b.l & 112)) { /* Line 1646, Address: 0x101ccc8 */
      if (swdata1.b.h & 1) { /* Line 1647, Address: 0x101cce0 */
        if (pActwk->yposi.w.h - 24 >= --actwk[0].yposi.w.h) /* Line 1648, Address: 0x101ccf8 */
          actwk[0].yposi.w.h = pActwk->yposi.w.h - 24; /* Line 1649, Address: 0x101cd3c */
      } /* Line 1650, Address: 0x101cd60 */
      else {

        if (swdata1.b.h & 2) { /* Line 1653, Address: 0x101cd68 */
          if (pActwk->yposi.w.h + 24 < ++actwk[0].yposi.w.h) /* Line 1654, Address: 0x101cd80 */
            actwk[0].yposi.w.h = pActwk->yposi.w.h + 24; /* Line 1655, Address: 0x101cdc4 */
        }
      }
      return; /* Line 1658, Address: 0x101cde8 */
    }
  }

  actwk[0].actfree[2] &= 254; /* Line 1662, Address: 0x101cdf0 */
  pActwk->patno = 1; /* Line 1663, Address: 0x101ce04 */
  pActwk->r_no0 += 2; /* Line 1664, Address: 0x101ce10 */
} /* Line 1665, Address: 0x101ce20 */








void bou_move2(sprite_status* pActwk) { /* Line 1674, Address: 0x101ce30 */

} /* Line 1676, Address: 0x101ce34 */









int bou_coli(sprite_status* pActwk) { /* Line 1686, Address: 0x101ce40 */
  short wD0;

  if (editmode.b.h) return 0; /* Line 1689, Address: 0x101ce4c */

  wD0 = pActwk->xposi.w.h - actwk[0].xposi.w.h + 4; /* Line 1691, Address: 0x101ce68 */
  if (wD0 < 0) return 0; /* Line 1692, Address: 0x101cea0 */
  if (wD0 >= 8) return 0; /* Line 1693, Address: 0x101cebc */

  wD0 = pActwk->yposi.w.h - actwk[0].yposi.w.h + 24; /* Line 1695, Address: 0x101cedc */
  if (wD0 < 0) return 0; /* Line 1696, Address: 0x101cf14 */
  if (wD0 >= 48) return 0; /* Line 1697, Address: 0x101cf30 */

  return 1; /* Line 1699, Address: 0x101cf50 */
} /* Line 1700, Address: 0x101cf54 */
