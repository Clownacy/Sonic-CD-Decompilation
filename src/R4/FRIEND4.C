#include "..\EQU.H"
#include "FRIEND4.H"
#include "..\ACTION.H"
#include "..\ACTSET.H"
#include "..\ETC.H"
#include "..\SUICIDE.H"
#include "PLAYSUB4.H"

#if defined(R41A)
  #define SPRITE_FRIEND4_BASE 494
#elif defined(R41B)
  #define SPRITE_FRIEND4_BASE 455
#elif defined(R41C)
  #define SPRITE_FRIEND4_BASE 472
#elif defined(R41D)
  #define SPRITE_FRIEND4_BASE 462
#elif defined(R42A)
  #define SPRITE_FRIEND4_BASE 500
#elif defined(R42B)
  #define SPRITE_FRIEND4_BASE 453
#elif defined(R42C) || defined(R42D)
  #define SPRITE_FRIEND4_BASE 457
#else
  #define SPRITE_FRIEND4_BASE 435
#endif

static void m_init(sprite_status* pActwk);
static void m0move(sprite_status* pActwk);
static void m1move(sprite_status* pActwk);

static unsigned char pchg0[30] = {
  0, 0, 0, 2, 0, 0, 2, 1, 1, 2,
  1, 1, 2, 0, 0, 2, 2, 0, 0, 2,
  2, 1, 1, 2, 2, 1, 1, 2, 2, 255
};
static unsigned char pchg1[4] = { 19, 0, 1, 255 };
static unsigned char* pchg[2] = {
  pchg0,
  pchg1
};
static sprite_pattern spr_friend4_00 = {
  1,
  { { -8, -12, 0, SPRITE_FRIEND4_BASE } }
};
static sprite_pattern spr_friend4_01 = {
  1,
  { { -8, -12, 0, SPRITE_FRIEND4_BASE + 1 } }
};
static sprite_pattern spr_friend4_10 = {
  1,
  { { -8, -12, 0, SPRITE_FRIEND4_BASE + 2 } }
};
static sprite_pattern spr_friend4_11 = {
  1,
  { { -8, -12, 0, SPRITE_FRIEND4_BASE + 3 } }
};
static sprite_pattern spr_friend4_99 = {
  0,
  { { -8, -12, 0, SPRITE_FRIEND4_BASE + 3 } }
};
sprite_pattern* pat_friend0[3] = {
  &spr_friend4_00,
  &spr_friend4_01,
  &spr_friend4_99
};
sprite_pattern* pat_friend1[3] = {
  &spr_friend4_10,
  &spr_friend4_11,
  &spr_friend4_99
};
static unsigned short tbl0sproffset[11] = {
  1104, 1104, 1104, 0,
  1104, 1104, 1104, 0,
     0,    0, 1104
};












































































void friend4(sprite_status* pActwk) { /* Line 152, Address: 0x101e780 */
  if (!friend_suicide(pActwk)) { /* Line 153, Address: 0x101e78c */
    if ((char)pActwk->r_no0 < 0) { /* Line 154, Address: 0x101e7a0 */
      m0move(pActwk); return; /* Line 155, Address: 0x101e7c0 */
    }

    if (pActwk->r_no0 != 0) { /* Line 158, Address: 0x101e7d4 */
      m1move(pActwk); return; /* Line 159, Address: 0x101e7e8 */
    }
    m_init(pActwk); /* Line 161, Address: 0x101e7fc */
  }
} /* Line 163, Address: 0x101e808 */



static void m_init(sprite_status* pActwk) { /* Line 167, Address: 0x101e820 */
  short_union temp;

  pActwk->actflg |= 4; /* Line 170, Address: 0x101e828 */
  pActwk->sprpri = 5; /* Line 171, Address: 0x101e838 */
  pActwk->sprhs = 8; /* Line 172, Address: 0x101e844 */
  pActwk->sprhsize = 8; /* Line 173, Address: 0x101e850 */
  pActwk->sprvsize = 12; /* Line 174, Address: 0x101e85c */

  temp.w = 0; /* Line 176, Address: 0x101e868 */
  temp.b.l = stageno.b.l; /* Line 177, Address: 0x101e86c */
  temp.w <<= 2; /* Line 178, Address: 0x101e878 */
  temp.b.l = temp.b.l + (char)time_flag; /* Line 179, Address: 0x101e884 */
  temp.w <<= 1; /* Line 180, Address: 0x101e8b8 */
  pActwk->sproffset = tbl0sproffset[temp.w]; /* Line 181, Address: 0x101e8c4 */
  if (pActwk->userflag.b.h & 1) { /* Line 182, Address: 0x101e8ec */
    pActwk->sproffset += 8192; /* Line 183, Address: 0x101e908 */
  }

  pActwk->patbase = pat_friend0; /* Line 186, Address: 0x101e918 */
  if (pActwk->userflag.b.h & 1) /* Line 187, Address: 0x101e928 */
    pActwk->patbase = pat_friend1; /* Line 188, Address: 0x101e944 */
  ((short*)pActwk)[25] = pActwk->yposi.w.h; /* Line 189, Address: 0x101e954 */
  if (pActwk->userflag.b.h < 0) { /* Line 190, Address: 0x101e964 */

    pActwk->r_no0 -= 2; /* Line 192, Address: 0x101e97c */
    pActwk->actflg ^= 1; /* Line 193, Address: 0x101e98c */
    pActwk->cddat ^= 1; /* Line 194, Address: 0x101e99c */
    ((short*)pActwk)[30] = pActwk->xposi.w.h; /* Line 195, Address: 0x101e9ac */
    ((int*)pActwk)[14] = 512; /* Line 196, Address: 0x101e9bc */
    if (pActwk->userflag.b.h & 1) { /* Line 197, Address: 0x101e9c8 */

      pActwk->actflg ^= 1; /* Line 199, Address: 0x101e9e4 */
      pActwk->cddat ^= 1; /* Line 200, Address: 0x101e9f4 */
      ((int*)pActwk)[14] *= -1; /* Line 201, Address: 0x101ea04 */
      ((int*)pActwk)[13] = 12288; /* Line 202, Address: 0x101ea14 */
    }
  } /* Line 204, Address: 0x101ea20 */
  else {


    pActwk->r_no0 += 2; /* Line 208, Address: 0x101ea28 */
    pActwk->mstno.b.h = 1; /* Line 209, Address: 0x101ea38 */
    *(int*)&pActwk->actfree[0] = 65536; /* Line 210, Address: 0x101ea44 */
    ((int*)pActwk)[14] = 256; /* Line 211, Address: 0x101ea54 */
  }
} /* Line 213, Address: 0x101ea60 */



static void m0move(sprite_status* pActwk) { /* Line 217, Address: 0x101ea70 */
  sprite_status* tempact;
  unsigned short sin, cos;
  int sinl, cosl;

  tempact = &actwk[((short*)pActwk)[33]]; /* Line 222, Address: 0x101ea88 */
  if (tempact->actno != 82) { /* Line 223, Address: 0x101eab0 */

    frameout(pActwk); /* Line 225, Address: 0x101eac4 */
    return; /* Line 226, Address: 0x101ead0 */
  }
  if (((char*)tempact)[67]) { /* Line 228, Address: 0x101ead8 */

    frameout(pActwk); /* Line 230, Address: 0x101eae4 */
    return; /* Line 231, Address: 0x101eaf0 */
  }

  sinset(((char*)pActwk)[53], (short*)&sin, (short*)&cos); /* Line 234, Address: 0x101eaf8 */
  cosl = 0, sinl = 0; /* Line 235, Address: 0x101eb14 */
  cosl = cos; /* Line 236, Address: 0x101eb1c */
  sinl = sin; /* Line 237, Address: 0x101eb24 */
  cosl = (unsigned int)cosl >> 16 & 65535 | cosl << 16 & -65536; /* Line 238, Address: 0x101eb2c */
  sinl = (unsigned int)sinl >> 16 & 65535 | sinl << 16 & -65536; /* Line 239, Address: 0x101eb44 */
  cosl >>= 3; /* Line 240, Address: 0x101eb5c */
  sinl >>= 4; /* Line 241, Address: 0x101eb60 */
  cosl = cosl + 32768; /* Line 242, Address: 0x101eb64 */
  sinl = sinl + 32768; /* Line 243, Address: 0x101eb6c */
  cosl = (unsigned int)cosl >> 16 & 65535 | cosl << 16 & -65536; /* Line 244, Address: 0x101eb74 */
  sinl = (unsigned int)sinl >> 16 & 65535 | sinl << 16 & -65536; /* Line 245, Address: 0x101eb8c */
  pActwk->xposi.w.h = ((short*)pActwk)[30] + (short)(cosl & 65535); /* Line 246, Address: 0x101eba4 */
  pActwk->yposi.w.h = ((short*)pActwk)[25] + (short)(sinl & 65535); /* Line 247, Address: 0x101ebdc */

  ((int*)pActwk)[13] += ((int*)pActwk)[14]; /* Line 249, Address: 0x101ec14 */
  if (!(((int*)pActwk)[13] & 32767)) { /* Line 250, Address: 0x101ec2c */

    pActwk->actflg ^= 1; /* Line 252, Address: 0x101ec40 */
    pActwk->cddat ^= 1; /* Line 253, Address: 0x101ec50 */
    if (pActwk->sprpri != 5) { /* Line 254, Address: 0x101ec60 */


      pActwk->sprpri = 5; /* Line 257, Address: 0x101ec78 */
    } /* Line 258, Address: 0x101ec84 */
    else {


      pActwk->sprpri = 3; /* Line 262, Address: 0x101ec8c */
    }
  }

  patchg(pActwk, pchg); /* Line 266, Address: 0x101ec98 */
  actionsub(pActwk); /* Line 267, Address: 0x101ecac */
} /* Line 268, Address: 0x101ecb8 */



static void m1move(sprite_status* pActwk) { /* Line 272, Address: 0x101ece0 */
  unsigned short sin, cos;
  int sinl;

  pActwk->xposi.l += *(int*)&pActwk->actfree[0]; /* Line 276, Address: 0x101ecf0 */

  sinset(((char*)pActwk)[53], (short*)&sin, (short*)&cos); /* Line 278, Address: 0x101ed0c */
  sinl = 0; /* Line 279, Address: 0x101ed28 */
  sinl = sin; /* Line 280, Address: 0x101ed2c */
  sinl = (unsigned int)sinl >> 16 & 65535 | sinl << 16 & -65536; /* Line 281, Address: 0x101ed34 */
  sinl >>= 3; /* Line 282, Address: 0x101ed4c */
  sinl = sinl + 32768; /* Line 283, Address: 0x101ed50 */
  sinl = (unsigned int)sinl >> 16 & 65535 | sinl << 16 & -65536; /* Line 284, Address: 0x101ed58 */
  pActwk->yposi.w.h = ((short*)pActwk)[25] + (short)(sinl & 65535); /* Line 285, Address: 0x101ed70 */

  ((int*)pActwk)[13] += ((int*)pActwk)[14]; /* Line 287, Address: 0x101eda8 */
  if (((int*)pActwk)[13] < 0) { /* Line 288, Address: 0x101edc0 */


    ((int*)pActwk)[14] *= -1; /* Line 291, Address: 0x101edd0 */
    *(int*)&pActwk->actfree[0] *= -1; /* Line 292, Address: 0x101ede0 */
    pActwk->actflg ^= 1; /* Line 293, Address: 0x101edf8 */
    pActwk->cddat ^= 1; /* Line 294, Address: 0x101ee08 */
  } /* Line 295, Address: 0x101ee18 */
  else {

    if (((int*)pActwk)[13] >= 65536) { /* Line 298, Address: 0x101ee20 */


      ((int*)pActwk)[14] *= -1; /* Line 301, Address: 0x101ee38 */
      *(int*)&pActwk->actfree[0] *= -1; /* Line 302, Address: 0x101ee48 */
      pActwk->actflg ^= 1; /* Line 303, Address: 0x101ee60 */
      pActwk->cddat ^= 1; /* Line 304, Address: 0x101ee70 */
    }
  }

  patchg(pActwk, pchg); /* Line 308, Address: 0x101ee80 */
  actionsub(pActwk); /* Line 309, Address: 0x101ee94 */
  frameout_s(pActwk); /* Line 310, Address: 0x101eea0 */
} /* Line 311, Address: 0x101eeac */
