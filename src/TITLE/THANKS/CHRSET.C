#include "..\..\TYPES.H"
#include "THANKS_TYPES.H"
#include "CHRSET.H"

extern unsigned char animal_flg;
extern short actset_tm[8];
extern sprite_status_thanks actwk[66];





























void sprinit() { /* Line 37, Address: 0x1001100 */
  short *a1, *a2;
  int ld0;
  short d0, d1, d5;

  short actset_tbl[16] = /* Line 42, Address: 0x1001120 */
  {
    120, 180,
    180, 300,
    240, 600,
    720, 1800,
    840, 2280,
    600, 2160,
    240, 600,
    300, 600
  };

  short manyact_tbl[16] = /* Line 54, Address: 0x1001154 */
  {
    10, 25,
    15, 20,
    10, 25,
    20, 50,
    30, 60,
    20, 60,
    40, 70,
    900, 1500
  };

  void(*sprinit_tbl[8])() = /* Line 66, Address: 0x1001188 */
  {
    &flick_set,
    &inco_set,
    &hato_set,
    &pocky_set,
    &pecky_set,
    &ricky_set,
    &sheep_set,
    &sonic_set
  };

  a2 = actset_tm; /* Line 78, Address: 0x10011bc */

  d5 = 7; /* Line 80, Address: 0x10011c4 */
  if (animal_flg == 2) /* Line 81, Address: 0x10011d0 */
  {
    --d5; /* Line 83, Address: 0x10011e8 */
  }
  do
  {
    if ((unsigned short)*a2 <= 0) /* Line 87, Address: 0x10011f4 */
    {
      --*a2; /* Line 89, Address: 0x1001208 */
      goto label1; /* Line 90, Address: 0x1001214 */
    }
    --*a2; /* Line 92, Address: 0x100121c */
    ++a2; /* Line 93, Address: 0x1001228 */
  } while (d5--); /* Line 94, Address: 0x100122c */

  return; /* Line 96, Address: 0x1001244 */


label1:
  d0 = d5; /* Line 100, Address: 0x100124c */
  d0 *= 2; /* Line 101, Address: 0x1001254 */
  if (animal_flg != 2) a1 = &actset_tbl[d0]; /* Line 102, Address: 0x1001260 */
  else a1 = &manyact_tbl[d0]; /* Line 103, Address: 0x1001294 */
  *a2 = *a1++; /* Line 104, Address: 0x10012a8 */

  ld0 = random(); /* Line 106, Address: 0x10012b8 */
  ld0 &= 65535; /* Line 107, Address: 0x10012c4 */
  d1 = *a1; /* Line 108, Address: 0x10012c8 */
  d0 = ld0 % d1; /* Line 109, Address: 0x10012d4 */
  *a2 += d0; /* Line 110, Address: 0x1001300 */

  sprinit_tbl[d5](); /* Line 112, Address: 0x100130c */
} /* Line 113, Address: 0x1001328 */




void sonic_set() {
  actwk[0].ACT_NO = 1; /* Line 119, Address: 0x1001350 */
} /* Line 120, Address: 0x100135c */




void flick_set() { /* Line 125, Address: 0x1001370 */
  sprite_status_thanks* pNewActwk;

  if (get_actwk(&pNewActwk) == 0) /* Line 128, Address: 0x1001378 */
  {
    pNewActwk->ACT_NO = 4; /* Line 130, Address: 0x1001394 */
  }
} /* Line 132, Address: 0x10013a0 */




void pocky_set() { /* Line 137, Address: 0x10013b0 */
  sprite_status_thanks* pNewActwk;

  if (get_actwk(&pNewActwk) == 0) /* Line 140, Address: 0x10013b8 */
  {
    pNewActwk->ACT_NO = 5; /* Line 142, Address: 0x10013d4 */
  }
} /* Line 144, Address: 0x10013e0 */




void pecky_set() { /* Line 149, Address: 0x10013f0 */
  sprite_status_thanks* pNewActwk;

  if (get_actwk(&pNewActwk) == 0) /* Line 152, Address: 0x10013f8 */
  {
    pNewActwk->ACT_NO = 11; /* Line 154, Address: 0x1001414 */
  }
} /* Line 156, Address: 0x1001420 */




void ricky_set() { /* Line 161, Address: 0x1001430 */
  sprite_status_thanks* pNewActwk;

  if (get_actwk(&pNewActwk) == 0) /* Line 164, Address: 0x1001438 */
  {
    pNewActwk->ACT_NO = 6; /* Line 166, Address: 0x1001454 */
  }
} /* Line 168, Address: 0x1001460 */




void inco_set() { /* Line 173, Address: 0x1001470 */
  sprite_status_thanks* pNewActwk;

  if (get_actwk(&pNewActwk) == 0) /* Line 176, Address: 0x1001478 */
  {
    pNewActwk->ACT_NO = 8; /* Line 178, Address: 0x1001494 */
  }
} /* Line 180, Address: 0x10014a0 */




void hato_set() { /* Line 185, Address: 0x10014b0 */
  sprite_status_thanks* pNewActwk;

  if (get_actwk(&pNewActwk) == 0) /* Line 188, Address: 0x10014b8 */
  {
    pNewActwk->ACT_NO = 9; /* Line 190, Address: 0x10014d4 */
  }
} /* Line 192, Address: 0x10014e0 */




void sheep_set() { /* Line 197, Address: 0x10014f0 */
  sprite_status_thanks* pNewActwk;

  if (get_actwk(&pNewActwk) == 0) /* Line 200, Address: 0x10014f8 */
  {
    pNewActwk->ACT_NO = 10; /* Line 202, Address: 0x1001514 */
  }
} /* Line 204, Address: 0x1001520 */
