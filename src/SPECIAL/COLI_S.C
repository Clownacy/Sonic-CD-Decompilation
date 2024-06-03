#include "..\TYPES.H"
#include "COMMON.H"
#include "SPS_EQU.H"
#include "COLI_S.H"
#include "ACT_S.H"

static unsigned short sm_cnt;
extern void(*sOutputDebugString)(char*);
extern void(*sPrintf)(char*, const char*, ...);
unsigned char ctbl00[96] = { 3, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 4, 4, 4, 0, 0, 0, 4, 0, 4, 4, 4, 0, 0, 0, 0, 0, 4, 0, 4, 4, 4, 4, 4, 0, 0, 4, 0, 3, 3, 3, 3, 4, 0, 4, 0, 3, 3, 3, 3, 3, 3, 0, 0, 3, 3, 3, 3, 3, 3, 0, 3, 0, 3, 3, 4, 4, 0, 0, 0, 4, 0, 4, 0, 0, 0, 4, 4, 4, 5, 7, 7, 8, 9, 9, 9, 2, 2, 2, 6, 6, 6, 6, 3 };
unsigned char ctbl10[112] = { 3, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 0, 4, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3, 3, 3, 4, 0, 0, 3, 0, 3, 0, 3, 4, 0, 0, 3, 0, 0, 4, 4, 0, 4, 4, 0, 4, 0, 0, 0, 4, 0, 0, 4, 0, 4, 4, 0, 0, 4, 0, 4, 4, 0, 0, 3, 3, 3, 3, 0, 0, 3, 3, 0, 0, 3, 3, 0, 0, 3, 0, 3, 3, 3, 3, 5, 9, 9, 9, 9, 9, 8, 7, 7, 4, 0, 0, 3, 3, 3, 2, 2, 2, 6, 6, 6, 6, 0 };
unsigned char ctbl20[144] = { 3, 1, 1, 0, 0, 0, 0, 0, 0, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 0, 0, 0, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 4, 0, 0, 0, 4, 4, 0, 0, 0, 4, 0, 4, 0, 4, 0, 0, 0, 0, 0, 4, 0, 3, 4, 0, 0, 3, 0, 0, 0, 4, 4, 0, 0, 0, 4, 0, 0, 4, 4, 0, 0, 0, 3, 0, 0, 3, 0, 0, 4, 0, 0, 0, 3, 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3, 0, 5, 7, 7, 8, 3, 3, 3, 3, 3, 3, 3, 3, 2, 2, 2, 6, 6, 6, 6, 3, 3, 0, 3, 3, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
unsigned char ctbl30[128] = { 3, 1, 1, 0, 0, 0, 0, 0, 0, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 0, 0, 0, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 3, 0, 0, 0, 0, 4, 0, 0, 0, 4, 0, 0, 0, 4, 0, 0, 0, 4, 4, 0, 0, 4, 0, 4, 4, 0, 4, 0, 4, 4, 0, 4, 0, 4, 0, 0, 4, 4, 0, 0, 4, 0, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 5, 7, 7, 7, 8, 8, 7, 7, 9, 9, 2, 2, 2, 6, 6, 6, 6, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
unsigned char ctbl40[112] = { 3, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 4, 0, 0, 0, 0, 0, 0, 4, 4, 4, 4, 0, 0, 0, 0, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 0, 0, 4, 4, 4, 4, 4, 0, 4, 0, 0, 0, 4, 0, 4, 4, 0, 4, 3, 0, 0, 0, 4, 4, 3, 3, 3, 3, 3, 3, 3, 5, 7, 7, 7, 7, 7, 8, 0, 0, 9, 9, 9, 2, 2, 2, 6, 6, 6, 6 };
unsigned char ctbl50[96] = { 3, 1, 1, 0, 0, 0, 0, 0, 0, 0, 4, 4, 4, 4, 4, 4, 4, 4, 0, 0, 0, 0, 0, 0, 3, 0, 0, 0, 0, 0, 0, 0, 4, 4, 0, 4, 0, 0, 0, 0, 0, 4, 0, 0, 0, 4, 0, 0, 4, 4, 0, 0, 0, 4, 0, 4, 0, 0, 4, 4, 0, 3, 0, 3, 0, 3, 0, 3, 3, 3, 3, 3, 3, 3, 3, 3, 5, 7, 7, 8, 7, 7, 3, 0, 9, 9, 9, 9, 2, 2, 2, 6, 6, 6, 6, 0 };
unsigned char ctbl60[112] = { 3, 1, 1, 0, 0, 0, 0, 0, 0, 0, 4, 4, 4, 4, 4, 0, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3, 0, 0, 0, 0, 0, 0, 0, 3, 0, 3, 0, 3, 0, 4, 4, 0, 0, 0, 0, 0, 0, 4, 4, 0, 0, 4, 0, 0, 0, 0, 4, 4, 3, 3, 3, 3, 3, 0, 3, 0, 5, 7, 7, 8, 0, 0, 0, 0, 0, 0, 0, 0, 2, 2, 2, 6, 6, 6, 6, 0, 0, 0 };
unsigned char ctbl70[144] = { 3, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 4, 4, 4, 0, 0, 0, 4, 0, 4, 4, 4, 0, 0, 0, 0, 0, 4, 0, 4, 4, 4, 4, 4, 0, 0, 4, 0, 3, 3, 3, 3, 4, 0, 4, 0, 3, 3, 3, 3, 3, 3, 0, 0, 3, 3, 3, 3, 3, 3, 0, 3, 0, 3, 3, 4, 4, 0, 0, 0, 4, 0, 4, 0, 0, 0, 4, 4, 4, 5, 7, 7, 8, 9, 9, 9, 2, 2, 2, 6, 6, 6, 6, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
unsigned char* colliadr_tbl[8] = {
  ctbl00,
  ctbl10,
  ctbl20,
  ctbl30,
  ctbl40,
  ctbl50,
  ctbl60,
  ctbl70
};












void ufovspl(sprite_status_sp* pActwk) { /* Line 40, Address: 0x1000ef0 */
  sprite_status_sp* pPlaywk;
  short iD0, iD1, iD2;

  pPlaywk = &actwk[0]; /* Line 44, Address: 0x1000f08 */
  if (pPlaywk->actno == 0) return; /* Line 45, Address: 0x1000f10 */
  if (pPlaywk->colliflg != 0) return; /* Line 46, Address: 0x1000f20 */

  iD0 = pActwk->x_posi.w.h - 16; /* Line 48, Address: 0x1000f30 */
  iD1 = iD0 + 32; /* Line 49, Address: 0x1000f54 */
  iD2 = pPlaywk->x_posi.w.h - 16; /* Line 50, Address: 0x1000f70 */
  if (iD2 > iD1) return; /* Line 51, Address: 0x1000f90 */

  if (iD2 + 32 < iD0) return; /* Line 53, Address: 0x1000fac */


  iD0 = pActwk->y_posi.w.h - 12; /* Line 56, Address: 0x1000fcc */
  iD1 = iD0 + 24; /* Line 57, Address: 0x1000ff0 */
  iD2 = pPlaywk->y_posi.w.h - 16; /* Line 58, Address: 0x100100c */
  if (iD2 > iD1) return; /* Line 59, Address: 0x100102c */

  if (iD2 + 32 < iD0) return; /* Line 61, Address: 0x1001048 */


  if ((unsigned short)pPlaywk->z_posi.w.h < 528) return; /* Line 64, Address: 0x1001068 */

  if ((unsigned short)pPlaywk->z_posi.w.h >= 624) return; /* Line 66, Address: 0x1001080 */

  pPlaywk->colliflg = pActwk->actno; /* Line 68, Address: 0x1001098 */
  pActwk->colliflg = pPlaywk->actno; /* Line 69, Address: 0x10010a4 */
} /* Line 70, Address: 0x10010b0 */















void plcolli(sprite_status_sp* pActwk) { /* Line 86, Address: 0x10010d0 */
  short iD1, iD2;

  stpnmget(pActwk->x_posi.w.h, pActwk->y_posi.w.h, &iD1, &iD2); /* Line 89, Address: 0x10010dc */
  pActwk->scno_ce = colliadr[iD2]; /* Line 90, Address: 0x10010fc */










  iD1 >>= 12; /* Line 101, Address: 0x1001120 */
  iD1 &= 15; /* Line 102, Address: 0x100112c */
  pActwk->scno_sdir = iD1; /* Line 103, Address: 0x1001138 */

  stpnmget(pActwk->x_posi.w.h - 8, pActwk->y_posi.w.h - 8, &iD1, &iD2); /* Line 105, Address: 0x1001148 */



  pActwk->scno_ul = colliadr[iD2]; /* Line 109, Address: 0x1001190 */

  stpnmget(pActwk->x_posi.w.h + 8, pActwk->y_posi.w.h - 8, &iD1, &iD2); /* Line 111, Address: 0x10011b4 */



  pActwk->scno_ur = colliadr[iD2]; /* Line 115, Address: 0x10011fc */

  stpnmget(pActwk->x_posi.w.h + 8, pActwk->y_posi.w.h + 8, &iD1, &iD2); /* Line 117, Address: 0x1001220 */



  pActwk->scno_dr = colliadr[iD2]; /* Line 121, Address: 0x1001268 */

  stpnmget(pActwk->x_posi.w.h - 8, pActwk->y_posi.w.h + 8, &iD1, &iD2); /* Line 123, Address: 0x100128c */



  pActwk->scno_dl = colliadr[iD2]; /* Line 127, Address: 0x10012d4 */
} /* Line 128, Address: 0x10012f8 */













short blcolli(sprite_status_sp* pActwk) { /* Line 142, Address: 0x1001310 */
  short iD0, iD1, iD2;

  stpnmget(pActwk->x_posi.w.h, pActwk->y_posi.w.h, &iD1, &iD2); /* Line 145, Address: 0x1001320 */
  iD0 = colliadr[iD2]; /* Line 146, Address: 0x1001340 */
  return iD0; /* Line 147, Address: 0x1001368 */
} /* Line 148, Address: 0x100136c */
















void stpnmget(short iXposi, short iYposi, short* ipD1, short* ipD2) { /* Line 165, Address: 0x1001380 */
  ushort_union uwk1;
  ushort_union uwk2;
  char buf[80];
  unsigned short wD2 = iXposi >> 5; /* Line 169, Address: 0x10013a0 */
  unsigned short wD3 = iYposi >> 5; /* Line 170, Address: 0x10013b8 */

  wD2 += wD3 << 7; /* Line 172, Address: 0x10013d0 */
  if (wD2 >= 16383) { /* Line 173, Address: 0x10013e4 */


    sPrintf(buf, "stpnmget Err wD2 = %x\n", wD2); /* Line 176, Address: 0x10013f4 */
    sOutputDebugString(buf); /* Line 177, Address: 0x1001414 */
    wD2 = 16383; /* Line 178, Address: 0x1001428 */
  }
  uwk1.w = sm_adr0[wD2]; /* Line 180, Address: 0x1001430 */
  uwk2.b.h = uwk1.b.l; /* Line 181, Address: 0x100144c */
  uwk2.b.l = uwk1.b.h; /* Line 182, Address: 0x1001454 */
  *ipD2 = uwk1.w; /* Line 183, Address: 0x100145c */

  *ipD1 = *ipD2; /* Line 185, Address: 0x1001468 */
  *ipD2 &= 2047; /* Line 186, Address: 0x1001478 */
  *ipD2 = *ipD2 >> 2; /* Line 187, Address: 0x100148c */
} /* Line 188, Address: 0x10014b0 */













void colli_init() {
  colliadr = colliadr_tbl[stagenm]; /* Line 203, Address: 0x10014d0 */
} /* Line 204, Address: 0x10014f8 */
