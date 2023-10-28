#include "..\TYPES.H"
#include "COMMON.H"
#include "SPM_EQU.H"
#include "ETC_M.H"

static short sonic_upcnt;
static short sonic_upcnt2;
static int subtbl[8] = { 10000000, 1000000, 100000, 10000, 1000, 100, 10, 1 };
extern void(*SetGrid)(int, int, int, int, int);
extern int time_bonus;
static unsigned char nullflg;
extern int ring_bonus;
static unsigned short disp_ascii[20] = {
  503, 505, 507, 509, 510, 512, 514, 515, 516, 517,
  504, 506, 508, 504, 511, 513, 504, 506, 504, 504
};
static int chrtbl[24] = {
  32769, 32770, 32771, 32772, 32773, 32774, 32775, 32776,
  32777, 32769, 32778, 32779, 32780, 32781, 32782, 32783,
  32784, 32785, 32786, 32787, 32788, 32789,     0,     0
};








void sonic_disp() { /* Line 30, Address: 0x1003500 */
  unsigned short sonic_extend;

  if ((sonic_upcnt2 = sonic_upcnt2 + 1 & 7) == 0) { /* Line 33, Address: 0x100350c */
    sonic_upcnt = sonic_upcnt + 1 & 1; /* Line 34, Address: 0x100354c */
    if ((sonic_extend = sonicup_no) != 0) { /* Line 35, Address: 0x1003574 */
      if (--sonic_extend >= 5) sonic_extend = 4; /* Line 36, Address: 0x100358c */
      switch (sonic_extend) { /* Line 37, Address: 0x10035b0 */
        case 4:
          sonic_disp_disp(8); /* Line 39, Address: 0x10035f4 */
        case 3:
          sonic_disp_disp(6); /* Line 41, Address: 0x1003600 */
        case 2:
          sonic_disp_disp(4); /* Line 43, Address: 0x100360c */
        case 1:
          sonic_disp_disp(2); /* Line 45, Address: 0x1003618 */
        case 0:
          sonic_disp_disp(0); /* Line 47, Address: 0x1003624 */
      }
    }
  }
} /* Line 51, Address: 0x1003630 */


void sonic_disp_disp(short tbl_no) { /* Line 54, Address: 0x1003650 */
  int x;
  int y;
  static unsigned short chibi_sonic_map[2][3][2] = {
    {
      { 863, 864 },
      { 869, 870 },
      { 871, 872 }
    },
    {
      { 863, 864 },
      { 869, 870 },
      { 871, 873 }
    }
  };


  for (y = 0; y < 3; ++y) { /* Line 71, Address: 0x1003664 */
    for (x = 0; x < 2; ++x) { /* Line 72, Address: 0x1003670 */
      SetGrid(0, x + 26 + tbl_no, y + 23, chibi_sonic_map[sonic_upcnt][y][x], 0); /* Line 73, Address: 0x100367c */

    } /* Line 75, Address: 0x10036ec */
  } /* Line 76, Address: 0x10036fc */

} /* Line 78, Address: 0x100370c */























void time_bonus_disp() { /* Line 102, Address: 0x1003730 */
  nullflg = 0; /* Line 103, Address: 0x1003738 */

  cset(subtbl, 24, 20, time_bonus, 7); /* Line 105, Address: 0x1003740 */
} /* Line 106, Address: 0x1003764 */


void ring_bonus_disp() { /* Line 109, Address: 0x1003780 */
  nullflg = 0; /* Line 110, Address: 0x1003788 */

  cset(subtbl, 24, 17, ring_bonus, 7); /* Line 112, Address: 0x1003790 */
} /* Line 113, Address: 0x10037b4 */


void game_score_disp() { /* Line 116, Address: 0x10037d0 */
  nullflg = 0; /* Line 117, Address: 0x10037d8 */

  cset(subtbl, 24, 14, game_score, 7); /* Line 119, Address: 0x10037e0 */
} /* Line 120, Address: 0x1003804 */













void cset(int* subtbl, unsigned short x, unsigned short y, int disp_data, short counter) { /* Line 134, Address: 0x1003820 */
  short one_number, i;

  if ((disp_data *= 10) != 0) { /* Line 137, Address: 0x1003844 */
    for (i = 0; counter >= i; ++i) { /* Line 138, Address: 0x1003860 */
      one_number = disp_data / subtbl[i]; /* Line 139, Address: 0x100386c */

      disp_data %= subtbl[i]; /* Line 141, Address: 0x10038ac */
      if (nullflg != 0 || one_number != 0) { /* Line 142, Address: 0x10038e0 */

        nullflg = 1; /* Line 144, Address: 0x1003904 */
        SetGrid(0, x, y, disp_ascii[one_number], 0); /* Line 145, Address: 0x1003910 */
        SetGrid(0, x, y + 1, disp_ascii[one_number], 0); /* Line 146, Address: 0x1003958 */
      } /* Line 147, Address: 0x10039a8 */
      else {
        SetGrid(0, x, y, 0, 0); /* Line 149, Address: 0x10039b0 */
        SetGrid(0, x, y + 1, 0, 0); /* Line 150, Address: 0x10039dc */
      }
      ++x; /* Line 152, Address: 0x1003a0c */
    } /* Line 153, Address: 0x1003a18 */
  } /* Line 154, Address: 0x1003a44 */
  else {

    for (i = 0; i < counter; ++i) { /* Line 157, Address: 0x1003a4c */

      SetGrid(0, x, y, 0, 0); /* Line 159, Address: 0x1003a58 */
      SetGrid(0, x, y + 1, 0, 0); /* Line 160, Address: 0x1003a84 */
      ++x; /* Line 161, Address: 0x1003ab4 */
    } /* Line 162, Address: 0x1003ac0 */

    SetGrid(0, x, y, disp_ascii[0], 0); /* Line 164, Address: 0x1003aec */
    SetGrid(0, x, y + 1, disp_ascii[20], 0); /* Line 165, Address: 0x1003b20 */
  }
} /* Line 167, Address: 0x1003b58 */














unsigned short cntminus(unsigned short* work, unsigned short minus_data, unsigned short under_limit, unsigned short upper_limit) { /* Line 182, Address: 0x1003b70 */
  if ((*work -= minus_data) < under_limit) *work = upper_limit; /* Line 183, Address: 0x1003b84 */
  return *work; /* Line 184, Address: 0x1003bdc */
} /* Line 185, Address: 0x1003be4 */


unsigned short cntplus(unsigned short* work, unsigned short plus_data, unsigned short under_limit, unsigned short upper_limit) { /* Line 188, Address: 0x1003bf0 */
  if (upper_limit < (*work += plus_data)) *work = under_limit; /* Line 189, Address: 0x1003c04 */
  return *work; /* Line 190, Address: 0x1003c44 */
} /* Line 191, Address: 0x1003c4c */





void spetime_disp() { /* Line 197, Address: 0x1003c60 */
  if (!(spgmmode & 2)) { /* Line 198, Address: 0x1003c68 */

    sset(subtbl, 19, 0, spe_time.l, 2); /* Line 200, Address: 0x1003c80 */
  } /* Line 201, Address: 0x1003ca4 */
  else {
    sset(subtbl, 17, 0, spe_time.l >> 16, 1); /* Line 203, Address: 0x1003cac */
    sset(subtbl, 20, 0, spe_time.l >> 8, 1); /* Line 204, Address: 0x1003cd8 */
    sset(subtbl, 23, 0, spe_time.l * 100 / 60, 1); /* Line 205, Address: 0x1003d04 */
  }

} /* Line 208, Address: 0x1003d58 */


void ringno_disp() { /* Line 211, Address: 0x1003d70 */
  sset(subtbl, 33, 0, ringno, 2); /* Line 212, Address: 0x1003d78 */
} /* Line 213, Address: 0x1003da0 */


void ufoleft_disp() { /* Line 216, Address: 0x1003db0 */
  sset(subtbl, 7, 0, ufoleft, 1); /* Line 217, Address: 0x1003db8 */
} /* Line 218, Address: 0x1003de0 */































void sset(int* subtbl, unsigned short x, unsigned short y, int disp_data, short counter) { /* Line 250, Address: 0x1003df0 */
  short one_number, i = 0; /* Line 251, Address: 0x1003e1c */
  int disp_x, disp_y;

  disp_x = x, disp_y = y; /* Line 254, Address: 0x1003e20 */

  do {
    one_number = disp_data / subtbl[i]; /* Line 257, Address: 0x1003e48 */
    disp_data %= subtbl[i++]; /* Line 258, Address: 0x1003e88 */
    SetGrid(0, disp_x, disp_y, chrtbl[one_number], 0); /* Line 259, Address: 0x1003ecc */
    SetGrid(0, disp_x, disp_y + 1, chrtbl[one_number], 0); /* Line 260, Address: 0x1003f08 */
    ++disp_x; /* Line 261, Address: 0x1003f48 */
  } while (counter >= i); /* Line 262, Address: 0x1003f4c */
} /* Line 263, Address: 0x1003f6c */



































void rfill(unsigned int* address, unsigned int data, short size) { /* Line 299, Address: 0x1003f90 */
  for (size /= 4; size >= 0; --size) *address++ = data; /* Line 300, Address: 0x1003fa0 */
} /* Line 301, Address: 0x1003ffc */

void rcopy(unsigned int* address1, unsigned int* address2, short size) { /* Line 303, Address: 0x1004010 */
  for (size /= 4; size >= 0; --size) *address2++ = *address1++; /* Line 304, Address: 0x1004020 */
} /* Line 305, Address: 0x1004088 */
