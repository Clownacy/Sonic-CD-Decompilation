#include "..\EQU.H"
#include "UDBLK6.H"
#include "..\ACTION.H"
#include "..\ACTSET.H"
#include "..\RIDECHK.H"

#if defined(R61B) || defined(R62B)
  #define SPRITE_UDBLK6_BASE 475
#elif defined(R63C) || defined(R63D)
  #define SPRITE_UDBLK6_BASE 448
#else
  #define SPRITE_UDBLK6_BASE 481
#endif

static sprite_pattern udblk6pat0 =
{
  1,
  { { -48, -80, 0, SPRITE_UDBLK6_BASE } }
};
sprite_pattern* udblk6pat[1] = { &udblk6pat0 };


















void udblk6(sprite_status* actionwk) { /* Line 39, Address: 0x101f850 */
  switch (actionwk->r_no0) /* Line 40, Address: 0x101f85c */
  {
    case 0:
      udblk6_init(actionwk); /* Line 43, Address: 0x101f8a8 */
    case 2:
      udblk6_chk1(actionwk); /* Line 45, Address: 0x101f8b4 */
      break; /* Line 46, Address: 0x101f8c0 */
    case 4:
      udblk6_mov1(actionwk); /* Line 48, Address: 0x101f8c8 */
      break; /* Line 49, Address: 0x101f8d4 */
    case 6:
      udblk6_chk2(actionwk); /* Line 51, Address: 0x101f8dc */
      break; /* Line 52, Address: 0x101f8e8 */
    case 8:
      udblk6_mov2(actionwk); /* Line 54, Address: 0x101f8f0 */
      break;
  }
  actionsub(actionwk); /* Line 57, Address: 0x101f8fc */
  frameout_s(actionwk); /* Line 58, Address: 0x101f908 */
} /* Line 59, Address: 0x101f914 */

void udblk6_ridechk(sprite_status* actionwk) { /* Line 61, Address: 0x101f930 */
  ride_on_chk(actionwk, &actwk[0]); /* Line 62, Address: 0x101f93c */
} /* Line 63, Address: 0x101f950 */


void udblk6_init(sprite_status* actionwk) { /* Line 66, Address: 0x101f960 */
  actionwk->r_no0 += 2; /* Line 67, Address: 0x101f968 */
  actionwk->actflg |= 4; /* Line 68, Address: 0x101f978 */
  actionwk->sprpri = 3; /* Line 69, Address: 0x101f988 */
  actionwk->sproffset = 17640; /* Line 70, Address: 0x101f994 */
  actionwk->patbase = udblk6pat; /* Line 71, Address: 0x101f9a0 */
  actionwk->sprvsize = 80; /* Line 72, Address: 0x101f9b0 */
  actionwk->sprhsize = 48; /* Line 73, Address: 0x101f9bc */
  ((short*)actionwk)[27] = actionwk->yposi.w.h; /* Line 74, Address: 0x101f9c8 */
} /* Line 75, Address: 0x101f9d8 */


void udblk6_chk1(sprite_status* actionwk) { /* Line 78, Address: 0x101f9f0 */
  short d0;

  d0 = actionwk->yposi.w.h - actwk[0].yposi.w.h; /* Line 81, Address: 0x101fa00 */
  if (d0 < 0) /* Line 82, Address: 0x101fa34 */
  {
    d0 = -d0; /* Line 84, Address: 0x101fa44 */
  }

  if (d0 < 192) /* Line 87, Address: 0x101fa60 */
  {
    d0 = actionwk->xposi.w.h - actwk[0].xposi.w.h; /* Line 89, Address: 0x101fa74 */
    if (d0 >= 0) /* Line 90, Address: 0x101faa8 */
    {
      if (d0 < 136) /* Line 92, Address: 0x101fab8 */
      {
        actionwk->actfree[18] = 0; /* Line 94, Address: 0x101facc */
        ((short*)actionwk)[31] = 0; /* Line 95, Address: 0x101fad4 */
        actionwk->r_no0 += 2; /* Line 96, Address: 0x101fadc */
      }
    }
  }

  udblk6_ridechk(actionwk); /* Line 101, Address: 0x101faec */
} /* Line 102, Address: 0x101faf8 */


void udblk6_mov1(sprite_status* actionwk) { /* Line 105, Address: 0x101fb10 */
  actionwk->actfree[18] = 0; /* Line 106, Address: 0x101fb1c */
  movecnt(actionwk); /* Line 107, Address: 0x101fb24 */
  if (actionwk->actfree[17] == 2) /* Line 108, Address: 0x101fb30 */
    actionwk->r_no0 += 2; /* Line 109, Address: 0x101fb48 */

  udblk6_ridechk(actionwk); /* Line 111, Address: 0x101fb58 */
} /* Line 112, Address: 0x101fb64 */


void udblk6_chk2(sprite_status* actionwk) { /* Line 115, Address: 0x101fb80 */
  short d0;

  d0 = actionwk->yposi.w.h - actwk[0].yposi.w.h; /* Line 118, Address: 0x101fb90 */
  if (d0 < 0) /* Line 119, Address: 0x101fbc4 */
  {
    d0 = -d0; /* Line 121, Address: 0x101fbd4 */
  }

  if (d0 < 192) /* Line 124, Address: 0x101fbf0 */
  {
    d0 = actwk[0].xposi.w.h - actionwk->xposi.w.h; /* Line 126, Address: 0x101fc04 */
    if (d0 >= 0) /* Line 127, Address: 0x101fc38 */
    {
      if (d0 >= 136) /* Line 129, Address: 0x101fc48 */
      {
        ((short*)actionwk)[31] = 0; /* Line 131, Address: 0x101fc5c */
        actionwk->r_no0 += 2; /* Line 132, Address: 0x101fc64 */
      }
    }
  }

  udblk6_ridechk(actionwk); /* Line 137, Address: 0x101fc74 */
} /* Line 138, Address: 0x101fc80 */


void udblk6_mov2(sprite_status* actionwk) { /* Line 141, Address: 0x101fca0 */
  actionwk->actfree[18] = 1; /* Line 142, Address: 0x101fcac */
  movecnt(actionwk); /* Line 143, Address: 0x101fcb8 */
  if (actionwk->actfree[17] == 2) /* Line 144, Address: 0x101fcc4 */
    actionwk->r_no0 = 2; /* Line 145, Address: 0x101fcdc */

  udblk6_ridechk(actionwk); /* Line 147, Address: 0x101fce8 */
} /* Line 148, Address: 0x101fcf4 */


void movecnt(sprite_status* actionwk) { /* Line 151, Address: 0x101fd10 */

  short mvtbl1[6] = /* Line 153, Address: 0x101fd20 */
  {
    64,  8,    0,
    64, -8,  512
  };


  short mvtbl2[6] = /* Line 160, Address: 0x101fd54 */
  {
    64, -8,    0,
    64,  8, -512
  };
  short* a2;
  short d0;



  a2 = mvtbl1; /* Line 170, Address: 0x101fd88 */
  if (actionwk->actfree[18] != 0) a2 = mvtbl2; /* Line 171, Address: 0x101fd8c */

  if (actionwk->actfree[16] == 0) /* Line 173, Address: 0x101fda4 */
  {
    d0 = actionwk->actfree[17] * 3; /* Line 175, Address: 0x101fdb8 */
    actionwk->actfree[16] = (char)a2[d0]; /* Line 176, Address: 0x101fddc */
    ((short*)actionwk)[33] = a2[d0 + 1]; /* Line 177, Address: 0x101fe04 */
    ((short*)actionwk)[26] = a2[d0 + 2]; /* Line 178, Address: 0x101fe24 */
  } /* Line 179, Address: 0x101fe44 */
  else
  {

    actionwk->yposi.l += actionwk->yspeed.w << 8; /* Line 183, Address: 0x101fe4c */
    actionwk->yspeed.w += ((short*)actionwk)[33]; /* Line 184, Address: 0x101fe70 */

    if (--actionwk->actfree[16] == 0) /* Line 186, Address: 0x101fe88 */
      ++actionwk->actfree[17]; /* Line 187, Address: 0x101fea8 */
  }
} /* Line 189, Address: 0x101feb8 */
