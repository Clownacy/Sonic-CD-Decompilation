#include "..\TYPES.H"
#include "SPS_EQU.H"

static unsigned short stage_table_damage[8] = { 364, 428, 492, 460, 432, 364, 420, 364 };
static unsigned short stage_table_hane[8] = { 352, 416, 480, 448, 420, 352, 408, 352 };
extern game_info* lpKeepWork;






























void Special_block_chg(unsigned short* hane1, unsigned short* hane2, unsigned short* dmg1, unsigned short* dmg2) { /* Line 37, Address: 0x1000cc0 */

  if (++hane_cnt >= 3) hane_cnt = 0; /* Line 39, Address: 0x1000cd4 */
  *hane1 = stage_table_hane[lpKeepWork->stagenm] / 4 - 1; /* Line 40, Address: 0x1000d0c */
  *hane2 = hane_cnt + stage_table_hane[lpKeepWork->stagenm] / 4 - 1; /* Line 41, Address: 0x1000d5c */

  ++chg_timer; /* Line 43, Address: 0x1000dc0 */
  if (chg_timer & 1) { /* Line 44, Address: 0x1000dd4 */

    if (++damage_cnt >= 4) damage_cnt = 0; /* Line 46, Address: 0x1000df0 */
  }

  *dmg1 = stage_table_damage[lpKeepWork->stagenm] / 4 - 1; /* Line 49, Address: 0x1000e28 */
  *dmg2 = damage_cnt + stage_table_damage[lpKeepWork->stagenm] / 4 - 1; /* Line 50, Address: 0x1000e78 */


} /* Line 53, Address: 0x1000edc */
