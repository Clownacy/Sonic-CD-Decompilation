#include "..\EQU.H"
#include "TRAP_R6.H"
#include "..\ACTION.H"
#include "..\ACTSET.H"
#include "..\LOADER2.H"
#include "..\RIDECHK.H"

void(*optbr6_tbl[5])(sprite_status*) =
{
  &optbr6_init,
  &optbr6_chk1,
  &optbr6_mov1,
  &optbr6_chk2,
  &optbr6_mov2
};
sprite_pattern opat0 =
{
  1,
  { { -4, -32, 0, 311 } }
};
sprite_pattern opat1 =
{
  1,
  { { -4, -32, 0, 312 } }
};
sprite_pattern opat2 =
{
  1,
  { { -4, -32, 0, 313 } }
};
sprite_pattern* optbr6pat[4] =
{
  &opat0,
  &opat1,
  &opat2,
  &opat2
};








































void optbr6(sprite_status* pActwk) { /* Line 78, Address: 0x1017690 */
  optbr6_tbl[pActwk->r_no0 / 2](pActwk); /* Line 79, Address: 0x101769c */
  actionsub(pActwk); /* Line 80, Address: 0x10176e0 */
  frameout_s(pActwk); /* Line 81, Address: 0x10176ec */
} /* Line 82, Address: 0x10176f8 */



void optbr6_ridechk(sprite_status* pActwk) { /* Line 86, Address: 0x1017710 */
  if (pActwk->patno != 0) return; /* Line 87, Address: 0x101771c */

  ride_on_chk(pActwk, &actwk[0]); /* Line 89, Address: 0x1017730 */
} /* Line 90, Address: 0x1017744 */











void optbr6_init(sprite_status* pActwk) { /* Line 102, Address: 0x1017760 */
  pActwk->r_no0 += 2; /* Line 103, Address: 0x101776c */
  pActwk->actflg |= 4; /* Line 104, Address: 0x101777c */
  pActwk->sprpri = 3; /* Line 105, Address: 0x101778c */
  pActwk->sproffset = 17424; /* Line 106, Address: 0x1017798 */
  pActwk->patbase = optbr6pat; /* Line 107, Address: 0x10177a4 */
  pActwk->sprhsize = 4; /* Line 108, Address: 0x10177b4 */
  pActwk->sprvsize = 32; /* Line 109, Address: 0x10177c0 */

  if (pActwk->userflag.b.h != 0) /* Line 111, Address: 0x10177cc */
  {
    pActwk->actflg |= 1; /* Line 113, Address: 0x10177e4 */
    pActwk->cddat |= 1; /* Line 114, Address: 0x10177f4 */
  }

  optbr6_chk1(pActwk); /* Line 117, Address: 0x1017804 */
} /* Line 118, Address: 0x1017810 */











void optbr6_chk1(sprite_status* pActwk) { /* Line 130, Address: 0x1017820 */
  short iD0, iD1;

  iD0 = pActwk->yposi.w.h - actwk[0].yposi.w.h; /* Line 133, Address: 0x1017834 */
  if (iD0 < 0) /* Line 134, Address: 0x1017868 */
    iD0 = -iD0; /* Line 135, Address: 0x1017878 */

  if (iD0 >= 64) goto label1; /* Line 137, Address: 0x1017894 */

  if (pActwk->userflag.b.h != 0) /* Line 139, Address: 0x10178a8 */
  {

    iD1 = pActwk->xposi.w.h; /* Line 142, Address: 0x10178c0 */
    iD0 = actwk[0].xposi.w.h; /* Line 143, Address: 0x10178d0 */
  } /* Line 144, Address: 0x10178e0 */
  else
  {

    iD0 = pActwk->xposi.w.h; /* Line 148, Address: 0x10178e8 */
    iD1 = actwk[0].xposi.w.h; /* Line 149, Address: 0x10178f8 */
  }

  iD0 -= iD1; /* Line 152, Address: 0x1017908 */
  if (iD0 < 0) goto label1; /* Line 153, Address: 0x1017914 */
  if (iD0 >= 64) goto label1; /* Line 154, Address: 0x1017924 */

  ((short*)pActwk)[31] = 0; /* Line 156, Address: 0x1017938 */
  pActwk->r_no0 += 2; /* Line 157, Address: 0x1017940 */
  if (pActwk->actflg & 128) /* Line 158, Address: 0x1017950 */
    soundset(164); /* Line 159, Address: 0x1017968 */
label1:
  optbr6_ridechk(pActwk); /* Line 161, Address: 0x1017974 */
} /* Line 162, Address: 0x1017980 */











void optbr6_mov1(sprite_status* pActwk) { /* Line 174, Address: 0x10179a0 */
  pActwk->actfree[18] = 0; /* Line 175, Address: 0x10179ac */
  tobira_cnt(pActwk); /* Line 176, Address: 0x10179b4 */
  if (pActwk->patno == 3) /* Line 177, Address: 0x10179c0 */
    pActwk->r_no0 += 2; /* Line 178, Address: 0x10179d8 */
  optbr6_ridechk(pActwk); /* Line 179, Address: 0x10179e8 */
} /* Line 180, Address: 0x10179f4 */











void optbr6_chk2(sprite_status* pActwk) { /* Line 192, Address: 0x1017a10 */
  short iD0, iD1;

  iD0 = pActwk->yposi.w.h - actwk[0].yposi.w.h; /* Line 195, Address: 0x1017a24 */
  if (iD0 < 0) /* Line 196, Address: 0x1017a58 */
    iD0 = -iD0; /* Line 197, Address: 0x1017a68 */

  if (iD0 >= 64) goto label1; /* Line 199, Address: 0x1017a84 */

  if (pActwk->userflag.b.h != 0) /* Line 201, Address: 0x1017a98 */
  {

    iD1 = actwk[0].xposi.w.h; /* Line 204, Address: 0x1017ab0 */
    iD0 = pActwk->xposi.w.h; /* Line 205, Address: 0x1017ac0 */
  } /* Line 206, Address: 0x1017ad0 */
  else
  {

    iD0 = actwk[0].xposi.w.h; /* Line 210, Address: 0x1017ad8 */
    iD1 = pActwk->xposi.w.h; /* Line 211, Address: 0x1017ae8 */
  }

  iD0 -= iD1; /* Line 214, Address: 0x1017af8 */
  if (iD0 < 0) goto label1; /* Line 215, Address: 0x1017b04 */
  if (iD0 < 64) goto label1; /* Line 216, Address: 0x1017b14 */

  ((short*)pActwk)[31] = 0; /* Line 218, Address: 0x1017b28 */
  pActwk->r_no0 += 2; /* Line 219, Address: 0x1017b30 */
  soundset(164); /* Line 220, Address: 0x1017b40 */
label1:
  optbr6_ridechk(pActwk); /* Line 222, Address: 0x1017b4c */
} /* Line 223, Address: 0x1017b58 */











void optbr6_mov2(sprite_status* pActwk) { /* Line 235, Address: 0x1017b70 */
  pActwk->actfree[18] = 1; /* Line 236, Address: 0x1017b7c */
  tobira_cnt(pActwk); /* Line 237, Address: 0x1017b88 */
  if (pActwk->patno == 0) /* Line 238, Address: 0x1017b94 */
    pActwk->r_no0 = 2; /* Line 239, Address: 0x1017ba8 */

  optbr6_ridechk(pActwk); /* Line 241, Address: 0x1017bb4 */
} /* Line 242, Address: 0x1017bc0 */











void tobira_cnt(sprite_status* pActwk) { /* Line 254, Address: 0x1017bd0 */
  pActwk->actfree[16] += 64; /* Line 255, Address: 0x1017bd8 */
  if (((char*)pActwk)[62] >= 0) return; /* Line 256, Address: 0x1017be8 */

  if (pActwk->actfree[18] == 0) /* Line 258, Address: 0x1017c00 */
    ++pActwk->patno; /* Line 259, Address: 0x1017c14 */
  else
  {
    if (pActwk->patno > 0) /* Line 262, Address: 0x1017c2c */
      --pActwk->patno; /* Line 263, Address: 0x1017c40 */
  }
} /* Line 265, Address: 0x1017c50 */
