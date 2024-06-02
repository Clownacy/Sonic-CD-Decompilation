#include "..\EQU.H"
#include "TOBIRAS4.H"
#include "..\ACTION.H"
#include "..\ACTSET.H"
#include "..\RIDECHK.H"

static void act_init(sprite_status* pActwk);
static void act_sense(sprite_status* pActwk);
static void act_down(sprite_status* pActwk);
static void act_disp(sprite_status* pActwk);

static sprite_pattern pat00 =
{
  1,
  { { -64, -64, 0, 516 } }
};
static sprite_pattern pat01 =
{
  1,
  { { -16, -64, 0, 517 } }
};
static sprite_pattern pat02 =
{
  1,
  { { -16, -64, 0, 518 } }
};
sprite_pattern* pat_tobiras4[3] =
{
  &pat00,
  &pat01,
  &pat02
};
extern void(*sMemCpy)(void*, void*, int);























void tobiras4(sprite_status* pActwk) { /* Line 57, Address: 0x1025530 */
  void(*tbl[3])(sprite_status*) = /* Line 58, Address: 0x102553c */
  {
    &act_init,
    &act_sense,
    &act_down
  };

  tbl[pActwk->r_no0 / 2](pActwk); /* Line 65, Address: 0x1025560 */
} /* Line 66, Address: 0x102559c */




static void act_init(sprite_status* pActwk) { /* Line 71, Address: 0x10255b0 */
  unsigned char* p;

  p = &switchflag[pActwk->userflag.b.h]; /* Line 74, Address: 0x10255c0 */
  if (*p) /* Line 75, Address: 0x10255dc */
  {
    frameout(pActwk); /* Line 77, Address: 0x10255e8 */
    return; /* Line 78, Address: 0x10255f4 */
  }
  ((unsigned char**)pActwk)[13] = p; /* Line 80, Address: 0x10255fc */

  pActwk->r_no0 += 2; /* Line 82, Address: 0x1025604 */
  pActwk->actflg |= 4; /* Line 83, Address: 0x1025614 */
  pActwk->sproffset = 17514; /* Line 84, Address: 0x1025624 */
  pActwk->patbase = pat_tobiras4; /* Line 85, Address: 0x1025630 */
  pActwk->sprvsize = 64; /* Line 86, Address: 0x1025640 */
  pActwk->sprhsize = 64; /* Line 87, Address: 0x102564c */
  pActwk->sprpri = 3; /* Line 88, Address: 0x1025658 */
  pActwk->sprhs = 64; /* Line 89, Address: 0x1025664 */
} /* Line 90, Address: 0x1025670 */




static void act_sense(sprite_status* pActwk) { /* Line 95, Address: 0x1025690 */
  sprite_status* pNewActwk;
  unsigned char* p;
  short d5, d6;

  p = ((unsigned char**)pActwk)[13]; /* Line 100, Address: 0x10256a8 */
  if (*p == 0) /* Line 101, Address: 0x10256b0 */
  {
    hitchk(pActwk, &actwk[0]); /* Line 103, Address: 0x10256c0 */
    actionsub(pActwk); /* Line 104, Address: 0x10256d4 */
    frameout_s(pActwk); /* Line 105, Address: 0x10256e0 */
    return; /* Line 106, Address: 0x10256ec */
  }

  pActwk->r_no0 += 2; /* Line 109, Address: 0x10256f4 */
  pActwk->sprhs = 16; /* Line 110, Address: 0x1025704 */
  pActwk->sprhsize = 16; /* Line 111, Address: 0x1025710 */
  ((short*)pActwk)[23] = 128; /* Line 112, Address: 0x102571c */
  ((int*)pActwk)[12] = -65536; /* Line 113, Address: 0x1025728 */
  ++pActwk->patno; /* Line 114, Address: 0x1025734 */
  pActwk->xposi.w.h -= 48; /* Line 115, Address: 0x1025744 */

  d6 = 2; /* Line 117, Address: 0x1025754 */
  d5 = pActwk->xposi.w.h; /* Line 118, Address: 0x1025760 */
  do
  {
    if (actwkchk2(pActwk, &pNewActwk) != 0) /* Line 121, Address: 0x1025770 */
    {
      frameout(pActwk); /* Line 123, Address: 0x1025788 */
      return; /* Line 124, Address: 0x1025794 */
    }
    sMemCpy(pNewActwk, pActwk, sizeof(*pActwk)); /* Line 126, Address: 0x102579c */
    d5 += 32; /* Line 127, Address: 0x10257b8 */
    pNewActwk->xposi.w.h = d5; /* Line 128, Address: 0x10257c4 */
    if (!(d6 & 1)) /* Line 129, Address: 0x10257cc */
    {
      ((int*)pNewActwk)[12] *= -1; /* Line 131, Address: 0x10257e0 */
      ++pNewActwk->patno; /* Line 132, Address: 0x10257f0 */
    }
  } while (--d6 >= 0); /* Line 134, Address: 0x1025800 */

  act_disp(pActwk); /* Line 136, Address: 0x1025824 */
} /* Line 137, Address: 0x1025830 */




static void act_down(sprite_status* pActwk) { /* Line 142, Address: 0x1025850 */
  if (((short*)pActwk)[23] < 0) /* Line 143, Address: 0x102585c */
  {
    frameout(pActwk); /* Line 145, Address: 0x1025874 */
    return; /* Line 146, Address: 0x1025880 */
  }
  --((short*)pActwk)[23]; /* Line 148, Address: 0x1025888 */
  pActwk->yposi.l -= ((int*)pActwk)[12]; /* Line 149, Address: 0x1025898 */
  act_disp(pActwk); /* Line 150, Address: 0x10258b0 */
} /* Line 151, Address: 0x10258bc */




static void act_disp(sprite_status* pActwk) { /* Line 156, Address: 0x10258d0 */
  hitchk(pActwk, &actwk[0]); /* Line 157, Address: 0x10258dc */
  actionsub(pActwk); /* Line 158, Address: 0x10258f0 */
} /* Line 159, Address: 0x10258fc */
