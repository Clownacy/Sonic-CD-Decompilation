#include "..\..\TYPES.H"
#include "..\COMMON\SCORE_DATA_TYPES.H"
#include "THANKS_TYPES.H"
#include "BM_M.H"
#include "..\..\IMPFUNCS.H"
#include "ACT.H"
#include "CHRSET.H"
#include "GAME.H"

extern short prg_mode;
extern short actset_tm[8];
high_score_entry score[84];
char GreatestPlayer[4];
extern score_data* lpScorData;
extern unsigned char quit_flg;
extern short_union swdata1;

































void mainloop() { /* Line 50, Address: 0x10008f0 */
  void(*prg_tbl[2])() = /* Line 51, Address: 0x10008f8 */
  {
    &get_tmdata,
    &get_keydata
  };

  prg_tbl[prg_mode](); /* Line 57, Address: 0x1000914 */
} /* Line 58, Address: 0x1000938 */




void get_tmdata() { /* Line 63, Address: 0x1000950 */
  get_usrname(); /* Line 64, Address: 0x1000958 */
  dsp_usrname(); /* Line 65, Address: 0x1000960 */

  actset_tm[0] = 600; /* Line 67, Address: 0x1000968 */
  actset_tm[1] = 0; /* Line 68, Address: 0x1000974 */
  actset_tm[2] = 0; /* Line 69, Address: 0x100097c */
  actset_tm[3] = 0; /* Line 70, Address: 0x1000984 */
  actset_tm[4] = 0; /* Line 71, Address: 0x100098c */
  actset_tm[5] = 0; /* Line 72, Address: 0x1000994 */
  actset_tm[6] = 0; /* Line 73, Address: 0x100099c */
  actset_tm[7] = 600; /* Line 74, Address: 0x10009a4 */

  prg_mode = 1; /* Line 76, Address: 0x10009b0 */
} /* Line 77, Address: 0x10009bc */




void get_keydata() { /* Line 82, Address: 0x10009d0 */
  player(); /* Line 83, Address: 0x10009d8 */
  sprinit(); /* Line 84, Address: 0x10009e0 */
  action(); /* Line 85, Address: 0x10009e8 */
} /* Line 86, Address: 0x10009f0 */




void get_usrname() { /* Line 91, Address: 0x1000a00 */
  short round, zone;
  short i, gp;

  sMemSet(score, 0, sizeof(score)); /* Line 95, Address: 0x1000a18 */

  for (round = 0; round < 7; ++round) /* Line 97, Address: 0x1000a38 */
  {
    for (zone = 0; zone < 3; ++zone) /* Line 99, Address: 0x1000a44 */
    {
      pointcnt(lpScorData->timeattack[round][zone][0].name, 3); /* Line 101, Address: 0x1000a50 */
      pointcnt(lpScorData->timeattack[round][zone][1].name, 2); /* Line 102, Address: 0x1000a98 */
      pointcnt(lpScorData->timeattack[round][zone][2].name, 1); /* Line 103, Address: 0x1000ae0 */
    } /* Line 104, Address: 0x1000b28 */
  } /* Line 105, Address: 0x1000b48 */
  for (round = 0; round < 7; ++round) /* Line 106, Address: 0x1000b68 */
  {
    pointcnt(lpScorData->special[round][0].name, 3); /* Line 108, Address: 0x1000b74 */
    pointcnt(lpScorData->special[round][1].name, 2); /* Line 109, Address: 0x1000ba4 */
    pointcnt(lpScorData->special[round][2].name, 1); /* Line 110, Address: 0x1000bd4 */
  } /* Line 111, Address: 0x1000c04 */


  gp = 0; /* Line 114, Address: 0x1000c24 */
  for (i = 0; i < 84; ++i) /* Line 115, Address: 0x1000c28 */
  {
    if (score[i].pts == 0) break; /* Line 117, Address: 0x1000c34 */
    if (score[i].pts >= score[gp].pts) /* Line 118, Address: 0x1000c68 */
    {
      gp = i; /* Line 120, Address: 0x1000ccc */
    }
  } /* Line 122, Address: 0x1000cd4 */
  sStrcpy(GreatestPlayer, score[gp].name); /* Line 123, Address: 0x1000cf4 */
} /* Line 124, Address: 0x1000d30 */




void pointcnt(char* name, short pts) { /* Line 129, Address: 0x1000d50 */
  short i;

  for (i = 0; i < 84; ++i) /* Line 132, Address: 0x1000d64 */
  {
    if (score[i].pts) /* Line 134, Address: 0x1000d70 */
    {
      if (sMemCmp(score[i].name, name, 3) != 0) continue; /* Line 136, Address: 0x1000d9c */

      score[i].pts += pts; /* Line 138, Address: 0x1000de0 */
      break; /* Line 139, Address: 0x1000e10 */
    }



    score[i].pts = pts; /* Line 144, Address: 0x1000e18 */
    sMemCpy(score[i].name, name, sizeof(score[i].name) - 1); /* Line 145, Address: 0x1000e40 */
    score[i].name[3] = 0; /* Line 146, Address: 0x1000e7c */
    break; /* Line 147, Address: 0x1000ea0 */

  } /* Line 149, Address: 0x1000ea8 */
} /* Line 150, Address: 0x1000ec8 */







int isdigit(int c) { /* Line 158, Address: 0x1000ee0 */
  if (c >= 48 && c < 58) /* Line 159, Address: 0x1000ee8 */
    return 1; /* Line 160, Address: 0x1000f08 */
  else
    return 0; /* Line 162, Address: 0x1000f14 */
} /* Line 163, Address: 0x1000f18 */


int isupper(int c) { /* Line 166, Address: 0x1000f30 */
  if (c >= 65 && c < 91) /* Line 167, Address: 0x1000f38 */
    return 1; /* Line 168, Address: 0x1000f58 */
  else
    return 0; /* Line 170, Address: 0x1000f64 */
} /* Line 171, Address: 0x1000f68 */


void dsp_usrname() { /* Line 174, Address: 0x1000f80 */
  short i;
  unsigned short c;

  for (i = 0; i < 3; ++i) /* Line 178, Address: 0x1000f90 */
  {
    if (isdigit(GreatestPlayer[i]) != 0) // goto 1000  /* Line 180, Address: 0x1000f9c */
    {
      c = GreatestPlayer[i] - 47; /* Line 182, Address: 0x1000fcc */
    } /* Line 183, Address: 0x1000ff8 */
    else if (isupper(GreatestPlayer[i]) != 0) // goto 1080 /* Line 184, Address: 0x1001000 */
    {
      c = GreatestPlayer[i] - 54; /* Line 186, Address: 0x1001030 */
    }
    else
    {
      continue;
    }
    PutAscii(c, i * 2 + 17, 12); /* Line 192, Address: 0x100105c */
  } /* Line 193, Address: 0x1001080 */
} /* Line 194, Address: 0x10010a0 */




void player() {
  if ((unsigned char)swdata1.b.l & 240) quit_flg = 1; /* Line 200, Address: 0x10010c0 */
  else quit_flg = 0; /* Line 201, Address: 0x10010f0 */
} /* Line 202, Address: 0x10010f8 */
