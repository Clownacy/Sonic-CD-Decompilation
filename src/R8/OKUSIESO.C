#include "..\EQU.H"
#include "OKUSIESO.H"
#include "..\ACTION.H"
#include "..\ACTSET.H"
#include "..\RIDECHK.H"

#if defined(R82)
  #define SPRITE_OKUSIESO_BASE 411
#else
  #define SPRITE_OKUSIESO_BASE 414
#endif

static void okusieso_init(sprite_status* pActwk);
static void okusieso_move(sprite_status* pActwk);
static void ball_move(sprite_status* pActwk);
static void dai_move(sprite_status* pActwk);

static sprite_pattern spr_sieso_00 =
{
  2,
  { {
    { -40, -56, 0, SPRITE_OKUSIESO_BASE },
    { -32, -24, 0, SPRITE_OKUSIESO_BASE + 9 }
  } }
};
static sprite_pattern spr_sieso_01 =
{
  2,
  { {
    { -24, -24, 0, SPRITE_OKUSIESO_BASE + 10 },
    { -40, -40, 0, SPRITE_OKUSIESO_BASE + 1 }
  } }
};
static sprite_pattern spr_sieso_02 =
{
  1,
  { { -24, -24, 0, SPRITE_OKUSIESO_BASE + 2 } }
};
static sprite_pattern spr_sieso_03 =
{
  1,
  { { -40, -32, 0, SPRITE_OKUSIESO_BASE + 3 } }
};
static sprite_pattern spr_sieso_04 =
{
  1,
  { { -40, -40, 0, SPRITE_OKUSIESO_BASE + 4 } }
};
static sprite_pattern spr_ball_00 =
{
  1,
  { { -16, -16, 0, SPRITE_OKUSIESO_BASE + 5 } }
};
static sprite_pattern spr_ball_01 =
{
  1,
  { { -24, -24, 0, SPRITE_OKUSIESO_BASE + 6 } }
};
static sprite_pattern spr_ball_02 =
{
  1,
  { { -32, -32, 0, SPRITE_OKUSIESO_BASE + 7 } }
};
static sprite_pattern spr_dai_00 =
{
  1,
  { { -40, -12, 0, SPRITE_OKUSIESO_BASE + 8 } }
};
sprite_pattern* okusiesopat[9] =
{
  &spr_sieso_00,
  &spr_sieso_01,
  &spr_sieso_02,
  &spr_sieso_03,
  &spr_sieso_04,
  &spr_ball_00,
  &spr_ball_01,
  &spr_ball_02,
  &spr_dai_00
};






































































void okusieso(sprite_status* pActwk) { /* Line 151, Address: 0x101d2b0 */
  short wD0, wD1;
  static void(*okusieso_tbl[2])(sprite_status*) =
  {
    &okusieso_init,
    &okusieso_move
  };

  okusieso_tbl[pActwk->r_no0 / 2](pActwk); /* Line 159, Address: 0x101d2c4 */
  actionsub(pActwk); /* Line 160, Address: 0x101d308 */
  wD0 = pActwk->xposi.w.h & -128; /* Line 161, Address: 0x101d314 */
  wD1 = scra_h_posit.w.h - 128 & -128; /* Line 162, Address: 0x101d33c */
  if ((unsigned short)(wD0 - wD1) > 640) /* Line 163, Address: 0x101d368 */
    frameout(pActwk); /* Line 164, Address: 0x101d390 */
} /* Line 165, Address: 0x101d39c */



static void okusieso_init(sprite_status* pActwk) { /* Line 169, Address: 0x101d3c0 */
  sprite_status* subActwk;

  pActwk->r_no0 += 2; /* Line 172, Address: 0x101d3cc */
  pActwk->actflg |= 4; /* Line 173, Address: 0x101d3dc */
  pActwk->patbase = okusiesopat; /* Line 174, Address: 0x101d3ec */
  pActwk->sproffset = 928; /* Line 175, Address: 0x101d3fc */
  pActwk->sprpri = 5; /* Line 176, Address: 0x101d408 */
  pActwk->patno = 0; /* Line 177, Address: 0x101d414 */
  pActwk->sprhsize = 40; /* Line 178, Address: 0x101d41c */
  pActwk->sprvsize = 56; /* Line 179, Address: 0x101d428 */
  pActwk->actfree[6] = 1; /* Line 180, Address: 0x101d434 */
  pActwk->actfree[20] = 0; /* Line 181, Address: 0x101d440 */


  if (actwkchk2(pActwk, &subActwk) == 0) /* Line 184, Address: 0x101d448 */
  {
    subActwk->r_no0 = 2; /* Line 186, Address: 0x101d460 */
    subActwk->actflg |= 4; /* Line 187, Address: 0x101d46c */
    subActwk->patbase = pActwk->patbase; /* Line 188, Address: 0x101d47c */
    subActwk->sproffset = 17312; /* Line 189, Address: 0x101d48c */
    subActwk->sprpri = 6; /* Line 190, Address: 0x101d498 */
    subActwk->patno = 5; /* Line 191, Address: 0x101d4a4 */
    subActwk->sprhsize = 16; /* Line 192, Address: 0x101d4b0 */
    subActwk->sprvsize = 16; /* Line 193, Address: 0x101d4bc */
    subActwk->yspeed.w = 0; /* Line 194, Address: 0x101d4c8 */
    subActwk->actfree[20] = 0; /* Line 195, Address: 0x101d4d0 */
    subActwk->actno = pActwk->actno; /* Line 196, Address: 0x101d4d8 */
    subActwk->actfree[20] |= 1; /* Line 197, Address: 0x101d4e8 */
    subActwk->xposi.l = pActwk->xposi.l; /* Line 198, Address: 0x101d4f8 */
    subActwk->yposi.l = pActwk->yposi.l; /* Line 199, Address: 0x101d508 */
    ((short*)subActwk)[29] = pActwk->yposi.w.h; /* Line 200, Address: 0x101d518 */
    ((short*)subActwk)[27] = (unsigned short)(unsigned char)(pActwk - actwk); /* Line 201, Address: 0x101d528 */
  } /* Line 202, Address: 0x101d568 */
  else
    return; /* Line 204, Address: 0x101d570 */

  if (actwkchk2(pActwk, &subActwk) == 0) /* Line 206, Address: 0x101d578 */
  {
    subActwk->r_no0 = 2; /* Line 208, Address: 0x101d590 */
    subActwk->actflg |= 4; /* Line 209, Address: 0x101d59c */
    subActwk->patbase = okusiesopat; /* Line 210, Address: 0x101d5ac */
    subActwk->sproffset = 928; /* Line 211, Address: 0x101d5bc */
    subActwk->sprpri = 3; /* Line 212, Address: 0x101d5c8 */
    subActwk->patno = 8; /* Line 213, Address: 0x101d5d4 */
    subActwk->sprhsize = 40; /* Line 214, Address: 0x101d5e0 */
    subActwk->sprvsize = 12; /* Line 215, Address: 0x101d5ec */
    subActwk->yspeed.w = 0; /* Line 216, Address: 0x101d5f8 */
    subActwk->actfree[20] = 0; /* Line 217, Address: 0x101d600 */
    subActwk->actno = pActwk->actno; /* Line 218, Address: 0x101d608 */
    subActwk->actfree[20] |= 2; /* Line 219, Address: 0x101d618 */
    subActwk->xposi.l = pActwk->xposi.l; /* Line 220, Address: 0x101d628 */
    subActwk->yposi.l = pActwk->yposi.l; /* Line 221, Address: 0x101d638 */
    ((short*)subActwk)[29] = pActwk->yposi.w.h; /* Line 222, Address: 0x101d648 */
    subActwk->yposi.w.h = (unsigned short)subActwk->yposi.w.h + 65492; /* Line 223, Address: 0x101d658 */
    ((short*)subActwk)[27] = (unsigned short)(unsigned char)(pActwk - actwk); /* Line 224, Address: 0x101d680 */
  }
} /* Line 226, Address: 0x101d6c0 */



static void okusieso_move(sprite_status* pActwk) { /* Line 230, Address: 0x101d6d0 */
  short wD1;
  unsigned char patno_tbl[4] = /* Line 232, Address: 0x101d6e0 */
  {
    3, 2, 1, 2
  };

  if (pActwk->actfree[20] & 8) return; /* Line 237, Address: 0x101d70c */

  if (pActwk->actfree[20] & 1) /* Line 239, Address: 0x101d724 */
  {
    ball_move(pActwk); /* Line 241, Address: 0x101d73c */
    return; /* Line 242, Address: 0x101d748 */
  }
  if (pActwk->actfree[20] & 2) /* Line 244, Address: 0x101d750 */
  {
    dai_move(pActwk); /* Line 246, Address: 0x101d768 */
    return; /* Line 247, Address: 0x101d774 */
  }
  if (!(pActwk->actfree[20] & 16)) return; /* Line 249, Address: 0x101d77c */



  if (time_stop) return; /* Line 253, Address: 0x101d794 */

  pActwk->yspeed.w = 0; /* Line 255, Address: 0x101d7a4 */
  if (!(pActwk->actfree[20] & 64)) /* Line 256, Address: 0x101d7ac */
  {
    --((char*)pActwk)[52]; /* Line 258, Address: 0x101d7c4 */
    if (((char*)pActwk)[52] < 0) /* Line 259, Address: 0x101d7d4 */
    {
      ((char*)pActwk)[53] = 5; /* Line 261, Address: 0x101d7ec */
      pActwk->actfree[20] |= 64; /* Line 262, Address: 0x101d7f8 */
      ++pActwk->patno; /* Line 263, Address: 0x101d808 */
    }
    return; /* Line 265, Address: 0x101d818 */
  }

  if (!(pActwk->actfree[20] & 32)) /* Line 268, Address: 0x101d820 */
  {
    --((char*)pActwk)[53]; /* Line 270, Address: 0x101d838 */
    if (((char*)pActwk)[53] >= 0) return; /* Line 271, Address: 0x101d848 */

    ++pActwk->patno; /* Line 273, Address: 0x101d860 */
    ((char*)pActwk)[53] = 5; /* Line 274, Address: 0x101d870 */
    if (pActwk->patno < 4) return; /* Line 275, Address: 0x101d87c */

    pActwk->actfree[20] |= 32; /* Line 277, Address: 0x101d894 */
    ((char*)pActwk)[52] = 0; /* Line 278, Address: 0x101d8a4 */
    ((char*)pActwk)[53] = 10; /* Line 279, Address: 0x101d8ac */


    return; /* Line 282, Address: 0x101d8b8 */
  }


  if (pActwk->actfree[20] & 4) /* Line 286, Address: 0x101d8c0 */
  {

    if (pActwk->patno != 4) /* Line 289, Address: 0x101d8d8 */
    {
      ++pActwk->patno; /* Line 291, Address: 0x101d8f0 */
      ((char*)pActwk)[53] = 10; /* Line 292, Address: 0x101d900 */
    }
    return; /* Line 294, Address: 0x101d90c */
  }
  --((char*)pActwk)[53]; /* Line 296, Address: 0x101d914 */
  if (((char*)pActwk)[53] < 0) /* Line 297, Address: 0x101d924 */
  {
    ++((char*)pActwk)[52]; /* Line 299, Address: 0x101d93c */
    wD1 = ((char*)pActwk)[52]; /* Line 300, Address: 0x101d94c */
    if (wD1 == 4) /* Line 301, Address: 0x101d964 */
    {
      ((char*)pActwk)[52] = 0; /* Line 303, Address: 0x101d978 */
      wD1 = 0; /* Line 304, Address: 0x101d980 */
    }

    pActwk->patno = patno_tbl[wD1]; /* Line 307, Address: 0x101d984 */
    ((char*)pActwk)[53] = 10; /* Line 308, Address: 0x101d99c */
  }
} /* Line 310, Address: 0x101d9a8 */








static void ball_move(sprite_status* pActwk) { /* Line 319, Address: 0x101d9c0 */
  short subact;
  short wD1;
  int lD0;

  if (time_stop) goto label1; /* Line 324, Address: 0x101d9d4 */

  subact = ((short*)pActwk)[27]; /* Line 326, Address: 0x101d9e4 */
  if (!(actwk[subact].actfree[20] & 16)) goto label1; /* Line 327, Address: 0x101d9f4 */

  if (!(pActwk->actfree[20] & 64)) /* Line 329, Address: 0x101da28 */
  {
    pActwk->yspeed.w = -12288; /* Line 331, Address: 0x101da40 */
    pActwk->actfree[20] |= 64; /* Line 332, Address: 0x101da4c */
    goto label1; /* Line 333, Address: 0x101da5c */
  }

  pActwk->yspeed.w += 256; /* Line 336, Address: 0x101da64 */
  if (pActwk->yspeed.w >= 0) /* Line 337, Address: 0x101da74 */
  {
    wD1 = pActwk->yposi.w.h - ((short*)pActwk)[29]; /* Line 339, Address: 0x101da8c */
    if ((unsigned short)wD1 <= 8) /* Line 340, Address: 0x101dac0 */
    {
      pActwk->yposi.w.h = ((short*)pActwk)[29] + 4; /* Line 342, Address: 0x101dad4 */
      subact = ((short*)pActwk)[27]; /* Line 343, Address: 0x101daf8 */
      actwk[subact].actfree[20] |= 8; /* Line 344, Address: 0x101db08 */
      pActwk->actfree[20] |= 8; /* Line 345, Address: 0x101db34 */
      actwk[subact].patno = 4; /* Line 346, Address: 0x101db44 */
      pActwk->yspeed.w = 0; /* Line 347, Address: 0x101db6c */
      goto label1; /* Line 348, Address: 0x101db74 */
    }
  }

  if (pActwk->yspeed.w == 0) /* Line 352, Address: 0x101db7c */
  {
    ++pActwk->patno; /* Line 354, Address: 0x101db94 */
    pActwk->colino = 164; /* Line 355, Address: 0x101dba4 */
    pActwk->sprpri = 4; /* Line 356, Address: 0x101dbb0 */
    goto label1; /* Line 357, Address: 0x101dbbc */
  }

  if (pActwk->yspeed.w == 57344) /* Line 360, Address: 0x101dbc4 */
    ++pActwk->patno; /* Line 361, Address: 0x101dbe0 */

label1:
  lD0 = pActwk->yspeed.w; /* Line 364, Address: 0x101dbf0 */
  lD0 <<= 6; /* Line 365, Address: 0x101dc00 */
  pActwk->yposi.l += lD0; /* Line 366, Address: 0x101dc04 */

} /* Line 368, Address: 0x101dc14 */




static void dai_move(sprite_status* pActwk) { /* Line 373, Address: 0x101dc30 */
  short subact;
  short wD1;
  unsigned char speed_tbl[5] = /* Line 376, Address: 0x101dc44 */
  {
    0, 8, 16, 8, 0
  };
  short ofs_tbl[5] = /* Line 380, Address: 0x101dc70 */
  {
    -44, -28, -12, 12, 28
  };

  if (time_stop) return; /* Line 385, Address: 0x101dc9c */

  subact = ((short*)pActwk)[27]; /* Line 387, Address: 0x101dcac */
  if (!(actwk[subact].actfree[20] & 16)) /* Line 388, Address: 0x101dcbc */
  {
    if (ride_on_chk(pActwk, &actwk[0])) /* Line 390, Address: 0x101dcf0 */
    {

      subact = ((short*)pActwk)[27]; /* Line 393, Address: 0x101dd0c */
      actwk[subact].actfree[20] |= 16; /* Line 394, Address: 0x101dd1c */
    }
  } /* Line 396, Address: 0x101dd48 */
  else
  {

    subact = ((short*)pActwk)[27]; /* Line 400, Address: 0x101dd50 */
    actwk[subact].actfree[20] |= 16; /* Line 401, Address: 0x101dd60 */
  }

  subact = ((short*)pActwk)[27]; /* Line 404, Address: 0x101dd8c */
  wD1 = actwk[subact].patno; /* Line 405, Address: 0x101dd9c */
  pActwk->yposi.w.h = ((short*)pActwk)[29] + ofs_tbl[wD1]; /* Line 406, Address: 0x101ddcc */

  subact = ((short*)pActwk)[27]; /* Line 408, Address: 0x101de0c */
  wD1 = actwk[subact].patno; /* Line 409, Address: 0x101de1c */
  wD1 = speed_tbl[wD1]; /* Line 410, Address: 0x101de4c */
  wD1 = (unsigned short)wD1 << 8; /* Line 411, Address: 0x101de68 */
  pActwk->yspeed.w = wD1; /* Line 412, Address: 0x101de84 */

  actwk[subact].actfree[20] &= 251; /* Line 414, Address: 0x101de8c */
  if (ride_on_chk(pActwk, &actwk[0])) /* Line 415, Address: 0x101deb8 */
    actwk[subact].actfree[20] |= 4; /* Line 416, Address: 0x101ded4 */
} /* Line 417, Address: 0x101df00 */
