#include "..\EQU.H"
#include "DAID4.H"
#include "..\ACTION.H"
#include "..\ACTSET.H"
#include "..\LOADER2.H"
#include "..\RIDECHK.H"

static void a_ini(sprite_status* pActwk);
static void a_born(sprite_status* pActwk);
static void a_off(sprite_status* pActwk);
static void a_off1(sprite_status* pActwk);
static void a_on(sprite_status* pActwk);
static void a_on1(sprite_status* pActwk);

static sprite_pattern pat0 =
{
  2,
  {
    { -32, -32, 0, 501 },
    { -32, 16, 0, 503 }
  }
};
static sprite_pattern pat1 =
{
  2,
  {
    { -32, -34, 0, 502 },
    { -32, 14, 0, 504 }
  }
};
sprite_pattern* pat_daid4[2] =
{
  &pat0,
  &pat1
};










































void daid4(sprite_status* pActwk) { /* Line 78, Address: 0x102adb0 */
  void(*tbl[6])(sprite_status*) = /* Line 79, Address: 0x102adbc */
  {
    &a_ini,
    &a_born,
    &a_off,
    &a_off1,
    &a_on,
    &a_on1
  };

  tbl[pActwk->r_no0 / 2](pActwk); /* Line 89, Address: 0x102adf0 */
} /* Line 90, Address: 0x102ae2c */




static void a_ini(sprite_status* pActwk) { /* Line 95, Address: 0x102ae40 */
  pActwk->r_no0 += 2; /* Line 96, Address: 0x102ae48 */
  pActwk->actflg |= 4; /* Line 97, Address: 0x102ae58 */
  pActwk->sprpri = 3; /* Line 98, Address: 0x102ae68 */
  pActwk->sprhs = 32; /* Line 99, Address: 0x102ae74 */
  pActwk->sprhsize = 32; /* Line 100, Address: 0x102ae80 */
  pActwk->sproffset = 17168; /* Line 101, Address: 0x102ae8c */
  pActwk->patbase = pat_daid4; /* Line 102, Address: 0x102ae98 */
  ((short*)pActwk)[23] = pActwk->yposi.w.h; /* Line 103, Address: 0x102aea8 */
  pActwk->sprvsize = 33; /* Line 104, Address: 0x102aeb8 */
} /* Line 105, Address: 0x102aec4 */




static void a_born(sprite_status* pActwk) { /* Line 110, Address: 0x102aed0 */
  short d0;

  d0 = actwk[0].yposi.w.h; /* Line 113, Address: 0x102aee0 */
  d0 -= 224; /* Line 114, Address: 0x102aef0 */
  if (d0 > ((short*)pActwk)[23]) /* Line 115, Address: 0x102aefc */
  {
    pActwk->r_no0 += 2; /* Line 117, Address: 0x102af20 */
    pActwk->yposi.w.h = d0; /* Line 118, Address: 0x102af30 */
  }
  frameout_s(pActwk); /* Line 120, Address: 0x102af38 */
} /* Line 121, Address: 0x102af44 */




static void a_off(sprite_status* pActwk) { /* Line 126, Address: 0x102af60 */
  pActwk->r_no0 += 2; /* Line 127, Address: 0x102af6c */
  pActwk->sprvsize = 33; /* Line 128, Address: 0x102af7c */
  pActwk->patno &= 254; /* Line 129, Address: 0x102af88 */
  ((int*)pActwk)[12] = 0; /* Line 130, Address: 0x102af98 */
  pActwk->yspeed.w = 0; /* Line 131, Address: 0x102afa0 */

  a_off1(pActwk); /* Line 133, Address: 0x102afa8 */
} /* Line 134, Address: 0x102afb4 */




static void a_off1(sprite_status* pActwk) { /* Line 139, Address: 0x102afd0 */
  short d0;

  pActwk->yposi.l += ((int*)pActwk)[12]; /* Line 142, Address: 0x102afe0 */
  ((int*)pActwk)[12] += 1024; /* Line 143, Address: 0x102aff8 */
  if ((long int)((int*)pActwk)[12] > 65536) /* Line 144, Address: 0x102b008 */
  {
    ((int*)pActwk)[12] = 65536; /* Line 146, Address: 0x102b02c */
  }
  if (!(pActwk->actflg & 128)) /* Line 148, Address: 0x102b038 */
  {
    d0 = pActwk->yposi.w.h; /* Line 150, Address: 0x102b050 */
    d0 -= actwk[0].yposi.w.h; /* Line 151, Address: 0x102b060 */
    if (d0 < 0) /* Line 152, Address: 0x102b074 */
    {
      d0 *= -1; /* Line 154, Address: 0x102b084 */
    }
    if (d0 > 224) /* Line 156, Address: 0x102b090 */
    {
      pActwk->r_no0 = 2; /* Line 158, Address: 0x102b0a4 */
      goto label1; /* Line 159, Address: 0x102b0b0 */
    }
  }
  if (ridechk(pActwk, &actwk[0])) /* Line 162, Address: 0x102b0b8 */
  {
    pActwk->r_no0 = 8; /* Line 164, Address: 0x102b0d4 */
    ride_on_clr(pActwk, &actwk[0]); /* Line 165, Address: 0x102b0e0 */
    pActwk->sprvsize = 31; /* Line 166, Address: 0x102b0f4 */
    pActwk->yposi.w.h += 2; /* Line 167, Address: 0x102b100 */
    actwk[0].yposi.w.h += 4; /* Line 168, Address: 0x102b110 */
    soundset(191); /* Line 169, Address: 0x102b124 */
  }
label1:
  actionsub(pActwk); /* Line 172, Address: 0x102b130 */
  frameout_s(pActwk); /* Line 173, Address: 0x102b13c */
} /* Line 174, Address: 0x102b148 */




static void a_on(sprite_status* pActwk) { /* Line 179, Address: 0x102b160 */
  pActwk->r_no0 += 2; /* Line 180, Address: 0x102b16c */
  pActwk->patno |= 1; /* Line 181, Address: 0x102b17c */
  pActwk->sprvsize = 31; /* Line 182, Address: 0x102b18c */
  pActwk->yspeed.w = -512; /* Line 183, Address: 0x102b198 */

  a_on1(pActwk); /* Line 185, Address: 0x102b1a4 */
} /* Line 186, Address: 0x102b1b0 */




static void a_on1(sprite_status* pActwk) { /* Line 191, Address: 0x102b1c0 */
  short d0;

  d0 = pActwk->yposi.w.h; /* Line 194, Address: 0x102b1d0 */
  if (d0 <= ((short*)pActwk)[23]) /* Line 195, Address: 0x102b1e0 */
  {
    pActwk->r_no0 = 2; /* Line 197, Address: 0x102b204 */
  } else /* Line 198, Address: 0x102b210 */
  {
    if (ridechk(pActwk, &actwk[0]) == 0) /* Line 200, Address: 0x102b218 */
    {
      pActwk->r_no0 = 4; /* Line 202, Address: 0x102b23c */
      pActwk->yposi.w.h -= 2; /* Line 203, Address: 0x102b248 */
      actwk[0].yposi.w.h -= 4; /* Line 204, Address: 0x102b258 */
    }
  }
  actionsub(pActwk); /* Line 207, Address: 0x102b26c */
  pActwk->yposi.l -= 131072; /* Line 208, Address: 0x102b278 */
  frameout_s(pActwk); /* Line 209, Address: 0x102b28c */
} /* Line 210, Address: 0x102b298 */
