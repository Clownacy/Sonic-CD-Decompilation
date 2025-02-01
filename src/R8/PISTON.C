#include "..\EQU.H"
#include "PISTON.H"
#include "..\ACTION.H"
#include "..\ACTSET.H"
#include "..\ETC.H"
#include "..\RIDECHK.H"

#if defined(R82)
  #define SPRITE_PISTON_BASE 317
#elif defined(R83)
  #define SPRITE_PISTON_BASE 310
#else
  #define SPRITE_PISTON_BASE 308
#endif

static void piston_init(sprite_status* pistonwk);
static void init_piston0(sprite_status* pistonwk);
static void init_piston1(sprite_status* pistonwk);
static void piston_move(sprite_status* pistonwk);

static sprite_pattern pis00 = {
  1,
  { { -32, -31, 0, SPRITE_PISTON_BASE } }
};
static sprite_pattern pis01 = {
  3,
  {
    { -32, -95, 0, SPRITE_PISTON_BASE },
    { -32, -31, 0, SPRITE_PISTON_BASE },
    { -32, 33, 0, SPRITE_PISTON_BASE }
  }
};
static sprite_pattern pis02 = {
  1,
  { { -32, -19, 0, SPRITE_PISTON_BASE + 1 } }
};
static sprite_pattern pis03 = {
  1,
  { { -16, -20, 0, 0 } }
};
sprite_pattern* pistonpat[4] = {
  &pis00,
  &pis01,
  &pis02,
  &pis03
};














void piston(sprite_status* pistonwk) { /* Line 61, Address: 0x1021ba0 */
  void(*piston_tbl[2])(sprite_status*) = { &piston_init, &piston_move }; /* Line 62, Address: 0x1021bac */
  piston_tbl[pistonwk->r_no0 / 2](pistonwk); /* Line 63, Address: 0x1021bc8 */
  actionsub(pistonwk); /* Line 64, Address: 0x1021c04 */
  frameout_s(pistonwk); /* Line 65, Address: 0x1021c10 */
} /* Line 66, Address: 0x1021c1c */



static void piston_init(sprite_status* pistonwk) { /* Line 70, Address: 0x1021c30 */
  char tbl_index;
  short cal_rad, cal_radius, sin_tmp, cos_tmp;
  int sin_data;
  void(*act_tbl[3])(sprite_status*) = { /* Line 74, Address: 0x1021c4c */
    &init_piston0,
    &init_piston1,
    &init_piston0
  };
  short rad_tbl[4] = { 0, 256, 512, 768 }; /* Line 79, Address: 0x1021c70 */

  short radius_tbl[2] = { 32, 48 }; /* Line 81, Address: 0x1021c9c */

  pistonwk->r_no0 += 2; /* Line 83, Address: 0x1021cb8 */
  pistonwk->actflg |= 4; /* Line 84, Address: 0x1021cc8 */
  pistonwk->patbase = pistonpat; /* Line 85, Address: 0x1021cd8 */

  pistonwk->sprpri = 3; /* Line 87, Address: 0x1021ce8 */
  ((short*)pistonwk)[26] = pistonwk->yposi.w.h; /* Line 88, Address: 0x1021cf4 */
  pistonwk->yspeed.w = pistonwk->xspeed.w = 0; /* Line 89, Address: 0x1021d04 */




  tbl_index = pistonwk->userflag.b.h & 48; /* Line 94, Address: 0x1021d1c */
  tbl_index >>= 4; /* Line 95, Address: 0x1021d40 */

  cal_rad = ((short*)pistonwk)[27] = rad_tbl[tbl_index]; /* Line 97, Address: 0x1021d4c */
  tbl_index = pistonwk->userflag.b.h & 64; /* Line 98, Address: 0x1021d70 */
  tbl_index >>= 6; /* Line 99, Address: 0x1021d94 */
  cal_radius = ((short*)pistonwk)[29] = radius_tbl[tbl_index]; /* Line 100, Address: 0x1021da0 */
  sinset((char)(cal_rad >> 2), &sin_tmp, &cos_tmp); /* Line 101, Address: 0x1021dc4 */
  sin_data = sin_tmp; /* Line 102, Address: 0x1021dec */
  sin_data *= cal_radius; /* Line 103, Address: 0x1021df8 */
  sin_data >>= 8; /* Line 104, Address: 0x1021e04 */
  sin_data += ((short*)pistonwk)[26]; /* Line 105, Address: 0x1021e08 */
  act_tbl[pistonwk->userflag.b.h & 3](pistonwk); /* Line 106, Address: 0x1021e1c */
} /* Line 107, Address: 0x1021e48 */





static short spd_tbl[4] = { 4, 8, 16, 32 };

static void init_piston0(sprite_status* pistonwk) { /* Line 115, Address: 0x1021e70 */
  pistonwk->patno = 0; /* Line 116, Address: 0x1021e78 */
  pistonwk->sprhsize = pistonwk->sprvsize = 32; /* Line 117, Address: 0x1021e80 */
  ((short*)pistonwk)[28] = spd_tbl[(pistonwk->userflag.b.h & 12) / 4]; /* Line 118, Address: 0x1021e98 */

} /* Line 120, Address: 0x1021ee0 */




static void init_piston1(sprite_status* pistonwk) { /* Line 125, Address: 0x1021ef0 */
  unsigned char delay_time_tbl[2] = { 60, 90 }; /* Line 126, Address: 0x1021ef8 */

  pistonwk->patno = 1; /* Line 128, Address: 0x1021f14 */
  pistonwk->sprhsize = 32; /* Line 129, Address: 0x1021f20 */
  pistonwk->sprvsize = 96; /* Line 130, Address: 0x1021f2c */
  ((short*)pistonwk)[28] = spd_tbl[(pistonwk->userflag.b.h & 4) / 4]; /* Line 131, Address: 0x1021f38 */

  pistonwk->actfree[14] = delay_time_tbl[(pistonwk->userflag.b.h & 8) / 8]; /* Line 133, Address: 0x1021f80 */

  pistonwk->actfree[20] = 0; /* Line 135, Address: 0x1021fbc */
} /* Line 136, Address: 0x1021fc4 */





static void piston_move(sprite_status* pistonwk) { /* Line 142, Address: 0x1021fd0 */
  short cal_posi, cal_rad, sin_tmp, cos_tmp;
  int stack_yposi, sin_data, cal_yposi;
  short jump_tbl[2] = { /* Line 145, Address: 0x1021ff0 */
    -4096, -2560
  };

  if (pistonwk->yspeed.w < 0) ride_on_chk(pistonwk, &actwk[0]); /* Line 149, Address: 0x102200c */
  stack_yposi = pistonwk->yposi.l; /* Line 150, Address: 0x1022038 */
  if ((pistonwk->userflag.b.h & 3) == 1) { /* Line 151, Address: 0x1022040 */

    if (pistonwk->actfree[20] & 128) { /* Line 153, Address: 0x1022060 */
      cal_posi = pistonwk->yposi.w.h; /* Line 154, Address: 0x1022078 */
      if ((char)--pistonwk->actfree[16] >= 0) goto label1; /* Line 155, Address: 0x1022088 */

      pistonwk->actfree[20] &= 127; /* Line 157, Address: 0x10220b4 */
    } /* Line 158, Address: 0x10220c4 */
    else {
      cal_posi = ((short*)pistonwk)[27]; /* Line 160, Address: 0x10220cc */
      if (cal_posi == 256 || cal_posi == 768) { /* Line 161, Address: 0x10220dc */

        pistonwk->actfree[20] |= 128; /* Line 163, Address: 0x1022104 */
        pistonwk->actfree[16] = pistonwk->actfree[14]; /* Line 164, Address: 0x1022114 */
        cal_posi = pistonwk->yposi.w.h; /* Line 165, Address: 0x1022124 */
        goto label1; /* Line 166, Address: 0x1022134 */
      }
    }
  }

  cal_rad = ((short*)pistonwk)[27] + ((short*)pistonwk)[28]; /* Line 171, Address: 0x102213c */

  cal_rad &= 1023; /* Line 173, Address: 0x1022170 */
  ((short*)pistonwk)[27] = cal_rad; /* Line 174, Address: 0x102217c */
  sinset((char)(cal_rad >> 2), &sin_tmp, &cos_tmp); /* Line 175, Address: 0x1022184 */
  sin_data = sin_tmp; /* Line 176, Address: 0x10221ac */
  sin_data *= ((short*)pistonwk)[29]; /* Line 177, Address: 0x10221b8 */
  sin_data >>= 8; /* Line 178, Address: 0x10221cc */
  sin_data += ((short*)pistonwk)[26]; /* Line 179, Address: 0x10221d0 */
  cal_posi = sin_data; /* Line 180, Address: 0x10221e4 */
label1:
  pistonwk->yposi.w.h = cal_posi; /* Line 182, Address: 0x10221f4 */
  cal_yposi = (cal_posi << 16) - stack_yposi; /* Line 183, Address: 0x10221fc */
  pistonwk->yspeed.w = cal_yposi >> 8; /* Line 184, Address: 0x102220c */
  if ((pistonwk->userflag.b.h & 3) == 1) { /* Line 185, Address: 0x1022220 */


    if (((short*)pistonwk)[27] == 528) { /* Line 188, Address: 0x1022240 */

      if (ride_on_chk(pistonwk, &actwk[0]) == 0) return; /* Line 190, Address: 0x102225c */

      actwk[0].yspeed.w = jump_tbl[((unsigned char)pistonwk->userflag.b.h & 128) >> 7]; /* Line 192, Address: 0x1022280 */
      actwk[0].cddat |= 2; /* Line 193, Address: 0x10222ac */
      actwk[0].cddat &= 247; /* Line 194, Address: 0x10222c0 */
      actwk[0].mstno.b.h = 16; /* Line 195, Address: 0x10222d4 */
      pistonwk->cddat &= 247; /* Line 196, Address: 0x10222e0 */
    }
  }
  if (pistonwk->yspeed.w >= 0) /* Line 199, Address: 0x10222f0 */
    ride_on_chk(pistonwk, &actwk[0]); /* Line 200, Address: 0x1022308 */
} /* Line 201, Address: 0x102231c */
