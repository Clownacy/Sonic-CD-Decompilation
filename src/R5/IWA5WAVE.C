#include "..\EQU.H"
#include "..\ACTION.H"
#include "..\ACTSET.H"
#include "..\ETC.H"
#include "..\RIDECHK.H"

static void a_init(sprite_status* pActwk);
static void a_move(sprite_status* pActwk);
static void com(sprite_status* pActwk);

static sprite_pattern pat00 =
{
  1,
  { { -32, -16, 0, 455 } }
};
sprite_pattern* pat_iwa5wave[1] = { &pat00 };











































void iwa5wave(sprite_status* pActwk) { /* Line 60, Address: 0x1021060 */
  if (pActwk->r_no0) a_move(pActwk); /* Line 61, Address: 0x102106c */
  else a_init(pActwk); /* Line 62, Address: 0x1021090 */
} /* Line 63, Address: 0x102109c */




static void a_init(sprite_status* pActwk) { /* Line 68, Address: 0x10210b0 */
  sprite_status* pNewActwk;
  int_union ld0;
  short d3, d4, d5, d6;

  ((short*)pActwk)[24] = pActwk->xposi.w.h; /* Line 73, Address: 0x10210cc */
  ld0.w.h = pActwk->xposi.w.h; /* Line 74, Address: 0x10210dc */
  ld0.w.l = 0; /* Line 75, Address: 0x10210e8 */
  ld0.l -= 8388608; /* Line 76, Address: 0x10210ec */
  *(int*)&pActwk->actfree[4] = ld0.l; /* Line 77, Address: 0x10210fc */
  ld0.l += 0x1000000; /* Line 78, Address: 0x102110c */
  *(int*)&pActwk->actfree[8] = ld0.l; /* Line 79, Address: 0x102111c */

  d6 = 1; /* Line 81, Address: 0x102112c */
  d5 = pActwk->xposi.w.h; /* Line 82, Address: 0x1021138 */
  d5 += 64; /* Line 83, Address: 0x1021148 */
  d4 = 128; /* Line 84, Address: 0x1021154 */
  d3 = -32768; /* Line 85, Address: 0x1021160 */
  if (pActwk->userflag.b.h) /* Line 86, Address: 0x102116c */
  {
    d3 = 0; /* Line 88, Address: 0x102117c */
  }
  pNewActwk = pActwk; /* Line 90, Address: 0x1021180 */

  pNewActwk->actflg |= 4; /* Line 92, Address: 0x1021188 */
  pNewActwk->r_no0 = 2; /* Line 93, Address: 0x1021198 */
  pNewActwk->sprpri = 3; /* Line 94, Address: 0x10211a4 */
  pNewActwk->sprhs = 32; /* Line 95, Address: 0x10211b0 */
  pNewActwk->sprhsize = 32; /* Line 96, Address: 0x10211bc */
  pNewActwk->sprvsize = 16; /* Line 97, Address: 0x10211c8 */
  pNewActwk->sproffset = 17543; /* Line 98, Address: 0x10211d4 */
  pNewActwk->patbase = pat_iwa5wave; /* Line 99, Address: 0x10211e0 */
  ((short*)pNewActwk)[29] = pActwk->yposi.w.h; /* Line 100, Address: 0x10211f0 */

  do
  {
    if (d6 != 1) /* Line 104, Address: 0x1021200 */
    {
      if (actwkchk(&pNewActwk) != 0) return; /* Line 106, Address: 0x1021214 */

      ((short*)pNewActwk)[23] = (unsigned short)(pActwk - actwk); /* Line 108, Address: 0x1021228 */
      pNewActwk->actno = pActwk->actno; /* Line 109, Address: 0x1021264 */
      *(int*)&pNewActwk->actfree[4] = *(int*)&pActwk->actfree[4]; /* Line 110, Address: 0x1021274 */
      *(int*)&pNewActwk->actfree[8] = *(int*)&pActwk->actfree[8]; /* Line 111, Address: 0x102128c */
      pNewActwk->yposi.w.h = pActwk->yposi.w.h; /* Line 112, Address: 0x10212a4 */

      pNewActwk->actflg |= 4; /* Line 114, Address: 0x10212b4 */
      pNewActwk->r_no0 = 2; /* Line 115, Address: 0x10212c4 */
      pNewActwk->sprpri = 3; /* Line 116, Address: 0x10212d0 */
      pNewActwk->sprhs = 32; /* Line 117, Address: 0x10212dc */
      pNewActwk->sprhsize = 32; /* Line 118, Address: 0x10212e8 */
      pNewActwk->sprvsize = 16; /* Line 119, Address: 0x10212f4 */
      pNewActwk->sproffset = 17543; /* Line 120, Address: 0x1021300 */
      pNewActwk->patbase = pat_iwa5wave; /* Line 121, Address: 0x102130c */
      ((short*)pNewActwk)[29] = pActwk->yposi.w.h; /* Line 122, Address: 0x102131c */
    }
    pNewActwk->xposi.w.h = d5; /* Line 124, Address: 0x102132c */
    d5 -= d4; /* Line 125, Address: 0x1021334 */
    ((short*)pNewActwk)[30] = d3; /* Line 126, Address: 0x1021340 */
  } while (d6--); /* Line 127, Address: 0x1021348 */

} /* Line 129, Address: 0x1021360 */




static void a_move(sprite_status* pActwk) { /* Line 134, Address: 0x1021380 */
  sprite_status* pMainwk;
  int_union ld0, ld1;
  int d0, d1;
  short sd0, sd1;
  unsigned char kakudo;

  d0 = pActwk->xposi.l; /* Line 141, Address: 0x102139c */
  d1 = d0; /* Line 142, Address: 0x10213a4 */
  d1 -= 32768; /* Line 143, Address: 0x10213a8 */
  if (d1 <= *(int*)&pActwk->actfree[4]) /* Line 144, Address: 0x10213ac */
  {
    d0 = *(int*)&pActwk->actfree[8]; /* Line 146, Address: 0x10213c4 */
    d1 = d0; /* Line 147, Address: 0x10213d0 */
  }
  pActwk->xposi.l = d1; /* Line 149, Address: 0x10213d4 */
  d1 -= d0; /* Line 150, Address: 0x10213dc */
  d1 >>= 8; /* Line 151, Address: 0x10213e0 */
  pActwk->xspeed.w = (unsigned short)(long int)d1; /* Line 152, Address: 0x10213e4 */


  ((short*)pActwk)[30] += 256; /* Line 155, Address: 0x1021400 */
  sd0 = ((short*)pActwk)[30]; /* Line 156, Address: 0x1021410 */
  sd0 >>= 8; /* Line 157, Address: 0x102141c */
  kakudo = (unsigned short)(sd0 & 255); /* Line 158, Address: 0x1021428 */
  sinset(kakudo, &sd0, &sd1); /* Line 159, Address: 0x1021444 */
  ld1.w.l = 0; /* Line 160, Address: 0x1021458 */
  ld1.w.h = sd1; /* Line 161, Address: 0x102145c */
  ld1.l >>= 2; /* Line 162, Address: 0x1021464 */
  ld0.l = ld1.l; /* Line 163, Address: 0x1021470 */
  ld0.l >>= 1; /* Line 164, Address: 0x1021478 */
  ld0.l += ld1.l; /* Line 165, Address: 0x1021484 */
  ld0.l += 32767 + 1; /* Line 166, Address: 0x1021494 */
  sd0 = ld0.w.h; /* Line 167, Address: 0x10214a4 */
  ld0.w.h = ld0.w.l; /* Line 168, Address: 0x10214ac */
  ld0.w.l = sd0; /* Line 169, Address: 0x10214b4 */
  ld0.w.l += ((short*)pActwk)[29]; /* Line 170, Address: 0x10214bc */
  pActwk->yposi.w.h = ld0.w.l; /* Line 171, Address: 0x10214d0 */
  if (((short*)pActwk)[23]) /* Line 172, Address: 0x10214dc */
  {
    pMainwk = &actwk[((short*)pActwk)[23]]; /* Line 174, Address: 0x10214ec */
    if (pMainwk->actno == 41) /* Line 175, Address: 0x1021514 */
    {
      com(pActwk); /* Line 177, Address: 0x1021528 */
      return; /* Line 178, Address: 0x1021534 */
    }


    frameout(pActwk); /* Line 182, Address: 0x102153c */
    return; /* Line 183, Address: 0x1021548 */
  }



  com(pActwk); /* Line 188, Address: 0x1021550 */
  frameout_s00(pActwk, ((short*)pActwk)[24]); /* Line 189, Address: 0x102155c */

} /* Line 191, Address: 0x1021570 */

static void com(sprite_status* pActwk) { /* Line 193, Address: 0x1021590 */
  unsigned char d0;

  ((short*)pActwk)[31] = pActwk->xspeed.w; /* Line 196, Address: 0x10215a0 */
  pActwk->xspeed.w = 0; /* Line 197, Address: 0x10215b0 */
  pActwk->sprvsize = 18; /* Line 198, Address: 0x10215b8 */
  if (ridechk(pActwk, &actwk[0])) d0 = 255; /* Line 199, Address: 0x10215c4 */
  else d0 = 0; /* Line 200, Address: 0x10215f0 */
  pActwk->xspeed.w = ((short*)pActwk)[31]; /* Line 201, Address: 0x10215f4 */
  pActwk->sprvsize = 16; /* Line 202, Address: 0x1021604 */
  if (d0) /* Line 203, Address: 0x1021610 */
  {
    ridechk(pActwk, &actwk[0]); /* Line 205, Address: 0x1021618 */
  }

  actionsub(pActwk); /* Line 208, Address: 0x102162c */
} /* Line 209, Address: 0x1021638 */
