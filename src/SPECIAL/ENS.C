#include "..\TYPES.H"
#include "COMMON.H"
#include "SPS_EQU.H"
#include "ENS.H"

static spr_array seexp00 = {
  1,
  { { -10, -8, 0, 127 } }
};
static spr_array seexp01 = {
  1,
  { { -20, -16, 0, 128 } }
};
static spr_array seexp02 = {
  1,
  { { -20, -16, 0, 129 } }
};
static spr_array seexp03 = {
  1,
  { { -25, -8, 0, 130 } }
};
static spr_array seexp04 = {
  1,
  { { -25, -24, 0, 131 } }
};
static spr_array stitle00 = {
  1,
  { { -90, -56, 0, 132 } }
};
static spr_array spress00 = {
  1,
  { { 0, 0, 0, 1 } }
};
static spr_array sobi00 = {
  1,
  { { -15, -112, 0, 133 } }
};
static spr_array sitem00 = {
  1,
  { { -10, -16, 0, 119 } }
};
static spr_array sitem01 = {
  1,
  { { -10, -16, 0, 120 } }
};
static spr_array sitem02 = {
  1,
  { { -10, -16, 0, 121 } }
};
static spr_array sitem03 = {
  1,
  { { -10, -16, 0, 122 } }
};
static spr_array sitem04 = {
  1,
  { { -10, -24, 0, 123 } }
};
static spr_array sitem05 = {
  1,
  { { -10, -24, 0, 124 } }
};
static spr_array sitem06 = {
  1,
  { { -5, -24, 0, 125 } }
};
static spr_array sitem07 = {
  1,
  { { -10, -24, 0, 126 } }
};
static spr_array skage00 = {
  1,
  { { -40, -8, 0, 71 } }
};
static spr_array skage01 = {
  1,
  { { -35, -8, 0, 72 } }
};
static spr_array skage02 = {
  1,
  { { -30, -4, 0, 73 } }
};
static spr_array skage03 = {
  1,
  { { -30, -4, 0, 74 } }
};
static spr_array skage04 = {
  1,
  { { -25, -4, 0, 75 } }
};
static spr_array skage05 = {
  1,
  { { -20, -4, 0, 76 } }
};
static spr_array skage06 = {
  1,
  { { -15, -4, 0, 77 } }
};
static spr_array skage07 = {
  1,
  { { -15, -4, 0, 78 } }
};
static spr_array skage08 = {
  1,
  { { -10, -4, 0, 79 } }
};
static spr_array skage09 = {
  1,
  { { -5, -4, 0, 80 } }
};
static spr_array Tufo00 = {
  1,
  { { -40, -56, 0, 81 } }
};
static spr_array Tufo01 = {
  1,
  { { -30, -48, 0, 82 } }
};
static spr_array Tufo02 = {
  1,
  { { -30, -40, 0, 83 } }
};
static spr_array Tufo03 = {
  1,
  { { -30, -40, 0, 84 } }
};
static spr_array Tufo04 = {
  1,
  { { -30, -32, 0, 85 } }
};
static spr_array Tufo05 = {
  1,
  { { -20, -32, 0, 86 } }
};
static spr_array Tufo06 = {
  1,
  { { -20, -32, 0, 87 } }
};
static spr_array Tufo07 = {
  1,
  { { -15, -24, 0, 88 } }
};
static spr_array Tufo08 = {
  1,
  { { -10, -16, 0, 89 } }
};
static spr_array Tufo09 = {
  1,
  { { -5, -8, 0, 90 } }
};
static spr_array sufo00 = {
  1,
  { { -40, -56, 0, 91 } }
};
static spr_array sufo01 = {
  1,
  { { -30, -48, 0, 92 } }
};
static spr_array sufo02 = {
  1,
  { { -30, -40, 0, 93 } }
};
static spr_array sufo03 = {
  1,
  { { -30, -40, 0, 94 } }
};
static spr_array sufo04 = {
  1,
  { { -30, -32, 0, 95 } }
};
static spr_array sufo05 = {
  1,
  { { -20, -32, 0, 96 } }
};
static spr_array sufo06 = {
  1,
  { { -20, -32, 0, 97 } }
};
static spr_array sufo07 = {
  1,
  { { -15, -24, 0, 98 } }
};
static spr_array sufo08 = {
  1,
  { { -10, -16, 0, 99 } }
};
static spr_array sufo09 = {
  1,
  { { -5, -8, 0, 100 } }
};
static spr_array sufo10 = {
  1,
  { { -40, -8, 0, 101 } }
};
static spr_array sufo11 = {
  1,
  { { -30, -48, 0, 102 } }
};
static spr_array sufo12 = {
  1,
  { { -30, -40, 0, 103 } }
};
static spr_array sufo13 = {
  1,
  { { -30, -40, 0, 104 } }
};
static spr_array sufo14 = {
  1,
  { { -30, -32, 0, 105 } }
};
static spr_array sufo15 = {
  1,
  { { -20, -32, 0, 106 } }
};
static spr_array sufo16 = {
  1,
  { { -20, -32, 0, 107 } }
};
static spr_array sufo17 = {
  1,
  { { -15, -24, 0, 108 } }
};
static spr_array sufo18 = {
  1,
  { { -10, -16, 0, 109 } }
};
static spr_array sufo19 = {
  1,
  { { -5, -8, 0, 110 } }
};
sprite_patterns_sp mpeexpTBL0 = {
  5,
  2,
  { &seexp00, &seexp01, &seexp02, &seexp03, &seexp04 }
};
sprite_patterns_sp* mpeexp[1] = { &mpeexpTBL0 };
sprite_patterns_sp mpitemTBL0 = {
  1,
  255,
  { &sitem00 }
};
sprite_patterns_sp mpitemTBL1 = {
  1,
  255,
  { &sitem01 }
};
sprite_patterns_sp mpitemTBL2 = {
  1,
  255,
  { &sitem02 }
};
sprite_patterns_sp mpitemTBL3 = {
  1,
  255,
  { &sitem03 }
};
sprite_patterns_sp mpitemTBL4 = {
  4,
  4,
  { &sitem04, &sitem05, &sitem06, &sitem07 }
};
sprite_patterns_sp* mpitem[5] = { &mpitemTBL0, &mpitemTBL1, &mpitemTBL2, &mpitemTBL3, &mpitemTBL4 };
sprite_patterns_sp mptlogoTBL0 = {
  1,
  255,
  { &stitle00 }
};
sprite_patterns_sp* mptlogo[1] = { &mptlogoTBL0 };
sprite_patterns_sp mptobiTBL0 = {
  1,
  255,
  { &sobi00 }
};
sprite_patterns_sp* mptobi[1] = { &mptobiTBL0 };
sprite_patterns_sp mppressTBL0 = {
  1,
  255,
  { &spress00 }
};
sprite_patterns_sp* mppress[1] = { &mppressTBL0 };
sprite_patterns_sp mpkageTBL0 = {
  1,
  255,
  { &skage00 }
};
sprite_patterns_sp mpkageTBL1 = {
  1,
  255,
  { &skage01 }
};
sprite_patterns_sp mpkageTBL2 = {
  1,
  255,
  { &skage02 }
};
sprite_patterns_sp mpkageTBL3 = {
  1,
  255,
  { &skage03 }
};
sprite_patterns_sp mpkageTBL4 = {
  1,
  255,
  { &skage04 }
};
sprite_patterns_sp mpkageTBL5 = {
  1,
  255,
  { &skage05 }
};
sprite_patterns_sp mpkageTBL6 = {
  1,
  255,
  { &skage06 }
};
sprite_patterns_sp mpkageTBL7 = {
  1,
  255,
  { &skage07 }
};
sprite_patterns_sp mpkageTBL8 = {
  1,
  255,
  { &skage08 }
};
sprite_patterns_sp mpkageTBL9 = {
  1,
  255,
  { &skage09 }
};
sprite_patterns_sp mpufoxTBL0 = {
  1,
  255,
  { &sufo00 }
};
sprite_patterns_sp mpufoxTBL1 = {
  1,
  255,
  { &sufo01 }
};
sprite_patterns_sp mpufoxTBL2 = {
  1,
  255,
  { &sufo02 }
};
sprite_patterns_sp mpufoxTBL3 = {
  1,
  255,
  { &sufo03 }
};
sprite_patterns_sp mpufoxTBL4 = {
  1,
  255,
  { &sufo04 }
};
sprite_patterns_sp mpufoxTBL5 = {
  1,
  255,
  { &sufo05 }
};
sprite_patterns_sp mpufoxTBL6 = {
  1,
  255,
  { &sufo06 }
};
sprite_patterns_sp mpufoxTBL7 = {
  1,
  255,
  { &sufo07 }
};
sprite_patterns_sp mpufoxTBL8 = {
  1,
  255,
  { &sufo08 }
};
sprite_patterns_sp mpufoxTBL9 = {
  1,
  255,
  { &sufo09 }
};
sprite_patterns_sp tpufoxTBL0 = {
  1,
  255,
  { &Tufo00 }
};
sprite_patterns_sp tpufoxTBL1 = {
  1,
  255,
  { &Tufo01 }
};
sprite_patterns_sp tpufoxTBL2 = {
  1,
  255,
  { &Tufo02 }
};
sprite_patterns_sp tpufoxTBL3 = {
  1,
  255,
  { &Tufo03 }
};
sprite_patterns_sp tpufoxTBL4 = {
  1,
  255,
  { &Tufo04 }
};
sprite_patterns_sp tpufoxTBL5 = {
  1,
  255,
  { &Tufo05 }
};
sprite_patterns_sp tpufoxTBL6 = {
  1,
  255,
  { &Tufo06 }
};
sprite_patterns_sp tpufoxTBL7 = {
  1,
  255,
  { &Tufo07 }
};
sprite_patterns_sp tpufoxTBL8 = {
  1,
  255,
  { &Tufo08 }
};
sprite_patterns_sp tpufoxTBL9 = {
  1,
  255,
  { &Tufo09 }
};
sprite_patterns_sp* tpufox[10] = {
  &tpufoxTBL0, &tpufoxTBL1, &tpufoxTBL2, &tpufoxTBL3, &tpufoxTBL4,
  &tpufoxTBL5, &tpufoxTBL6, &tpufoxTBL7, &tpufoxTBL8, &tpufoxTBL9
};
sprite_patterns_sp mpufoyTBL0 = {
  1,
  255,
  { &sufo10 }
};
sprite_patterns_sp mpufoyTBL1 = {
  1,
  255,
  { &sufo11 }
};
sprite_patterns_sp mpufoyTBL2 = {
  1,
  255,
  { &sufo12 }
};
sprite_patterns_sp mpufoyTBL3 = {
  1,
  255,
  { &sufo13 }
};
sprite_patterns_sp mpufoyTBL4 = {
  1,
  255,
  { &sufo14 }
};
sprite_patterns_sp mpufoyTBL5 = {
  1,
  255,
  { &sufo15 }
};
sprite_patterns_sp mpufoyTBL6 = {
  1,
  255,
  { &sufo16 }
};
sprite_patterns_sp mpufoyTBL7 = {
  1,
  255,
  { &sufo17 }
};
sprite_patterns_sp mpufoyTBL8 = {
  1,
  255,
  { &sufo18 }
};
sprite_patterns_sp mpufoyTBL9 = {
  1,
  255,
  { &sufo19 }
};
short mvtbl0_0[13] = {
  0, 0, 144, 1920, 2880, 2304, 2560, 96, 2304, 2560,
  1920, 2880, -1
};
short mvtbl0_1[18] = {
  0, 0, 144, 1536, 2176, 1920, 1664, 96, 1920, 1664,
  1408, 1920, 96, 1408, 1920, 1536, 2176, -1
};
short mvtbl0_2[18] = {
  1, 0, 144, 2688, 1408, 2304, 1280, 96, 2304, 1280,
  2432, 1664, 240, 2432, 1664, 2688, 1408, -1
};
short mvtbl0_3[13] = {
  0, 0, 240, 1920, 1152, 1408, 1280, 96, 1408, 1280,
  1920, 1152, -1
};
short mvtbl0_4[23] = {
  0, 0, 48, 2816, 2560, 2816, 2432, 144, 2816, 2432,
  2560, 2560, 96, 2560, 2560, 2688, 2816, 96, 2688, 2816,
  2816, 2560, -1
};
short mvtbl0_5[18] = {
  1, 0, 144, 2432, 2176, 2304, 2432, 96, 2304, 2432,
  2816, 2176, 240, 2816, 2176, 2432, 2176, -1
};
short mvtbl1_0[23] = {
  0, 0, 240, 2816, 1408, 2240, 1216, 240, 2240, 1216,
  2048, 1536, 240, 2048, 1536, 2560, 1728, 240, 2560, 1728,
  2816, 1408, -1
};
short mvtbl1_1[18] = {
  0, 0, 144, 1408, 1280, 1280, 1408, 240, 1280, 1408,
  1664, 1664, 240, 1664, 1664, 1408, 1280, -1
};
short mvtbl1_2[23] = {
  1, 0, 240, 1664, 1792, 1408, 1792, 300, 1408, 1792,
  1216, 2048, 300, 1216, 2048, 1664, 2048, 360, 1664, 2048,
  1664, 1792, -1
};
short mvtbl1_3[13] = {
  0, 0, 96, 1536, 2432, 1792, 2560, 48, 1792, 2560,
  1536, 2432, -1
};
short mvtbl1_4[18] = {
  0, 0, 300, 2560, 2304, 2112, 2752, 300, 2112, 2752,
  2560, 2816, 240, 2560, 2816, 2560, 2304, -1
};
short mvtbl1_5[18] = {
  1, 0, 240, 2880, 2048, 2560, 1920, 96, 2560, 1920,
  2432, 2240, 240, 2432, 2240, 2880, 2048, -1
};
short mvtbl2_0[23] = {
  0, 0, 64, 2816, 1280, 2560, 1280, 200, 2560, 1280,
  2304, 1792, 96, 2304, 1792, 2560, 1664, 160, 2560, 1664,
  2816, 1280, -1
};
short mvtbl2_1[18] = {
  0, 0, 200, 1728, 1216, 1280, 1536, 160, 1280, 1536,
  1600, 1408, 160, 1600, 1408, 1728, 1216, -1
};
short mvtbl2_2[23] = {
  1, 0, 96, 1536, 1920, 1280, 1920, 200, 1280, 1920,
  1280, 2176, 160, 1280, 2176, 1536, 2176, 160, 1536, 2176,
  1536, 1920, -1
};
short mvtbl2_3[18] = {
  0, 0, 96, 1536, 2432, 1280, 2432, 200, 1280, 2432,
  1280, 2816, 96, 1280, 2816, 1536, 2432, -1
};
short mvtbl2_4[23] = {
  0, 0, 200, 2240, 2560, 1792, 2496, 200, 1792, 2496,
  1792, 2816, 160, 1792, 2816, 2240, 2816, 160, 2240, 2816,
  2240, 2560, -1
};
short mvtbl2_5[23] = {
  1, 0, 200, 2816, 2432, 2560, 2176, 200, 2560, 2176,
  2432, 2560, 96, 2432, 2560, 2432, 2816, 240, 2432, 2816,
  2816, 2432, -1
};
short mvtbl3_0[18] = {
  0, 0, 160, 2752, 1216, 2176, 1280, 200, 2176, 1280,
  2816, 1536, 160, 2816, 1536, 2752, 1216, -1
};
short mvtbl3_1[23] = {
  0, 0, 200, 2208, 1472, 1856, 1472, 200, 1856, 1472,
  1856, 1792, 200, 1856, 1792, 2208, 1792, 200, 2208, 1792,
  2208, 1472, -1
};
short mvtbl3_2[23] = {
  1, 0, 200, 1536, 1792, 1280, 2048, 200, 1280, 2048,
  1536, 2304, 96, 1536, 2304, 1664, 2048, 96, 1664, 2048,
  1536, 1792, -1
};
short mvtbl3_3[13] = {
  0, 0, 200, 1536, 2688, 1088, 2688, 160, 1088, 2688,
  1536, 2688, -1
};
short mvtbl3_4[18] = {
  0, 0, 96, 2432, 2304, 2176, 2304, 160, 2176, 2304,
  1856, 2688, 200, 1856, 2688, 2432, 2304, -1
};
short mvtbl3_5[18] = {
  1, 0, 160, 2688, 1728, 2432, 1792, 160, 2432, 1792,
  2816, 1920, 96, 2816, 1920, 2688, 1728, -1
};
short mvtbl4_0[23] = {
  0, 0, 16, 2944, 1088, 2816, 1088, 80, 2816, 1088,
  2560, 1408, 80, 2560, 1408, 3008, 1408, 48, 3008, 1408,
  2944, 1088, -1
};
short mvtbl4_1[23] = {
  0, 0, 48, 1792, 1088, 1472, 1088, 100, 1472, 1088,
  1920, 1600, 48, 1920, 1600, 2112, 1408, 100, 2112, 1408,
  1792, 1088, -1
};
short mvtbl4_2[13] = {
  1, 0, 100, 2752, 1792, 2112, 1792, 100, 2112, 1792,
  2752, 1792, -1
};
short mvtbl4_3[28] = {
  0, 0, 48, 1472, 1920, 1344, 2176, 48, 1344, 2176,
  1280, 2368, 48, 1280, 2368, 1472, 2432, 80, 1472, 2432,
  1536, 2112, 48, 1536, 2112, 1472, 1920, -1
};
short mvtbl4_4[23] = {
  0, 0, 32, 1856, 2176, 1696, 2304, 100, 1696, 2304,
  1696, 3008, 48, 1696, 3008, 1856, 3008, 100, 1856, 3008,
  1856, 2176, -1
};
short mvtbl4_5[18] = {
  1, 0, 80, 2432, 2112, 2112, 2432, 100, 2112, 2432,
  2752, 2432, 80, 2752, 2432, 2432, 2112, -1
};
short mvtbl5_0[23] = {
  0, 0, 80, 2816, 1280, 2816, 1664, 80, 2816, 1664,
  2688, 1984, 48, 2688, 1984, 3072, 1984, 120, 3072, 1984,
  2816, 1280, -1
};
short mvtbl5_1[18] = {
  0, 0, 100, 2432, 1152, 1984, 1408, 100, 1984, 1408,
  2560, 1408, 48, 2560, 1408, 2432, 1152, -1
};
short mvtbl5_2[23] = {
  1, 0, 48, 1216, 1152, 960, 1152, 100, 960, 1152,
  960, 1536, 48, 960, 1536, 1216, 1536, 100, 1216, 1536,
  1216, 1152, -1
};
short mvtbl5_3[18] = {
  0, 0, 100, 1408, 2496, 1024, 2944, 100, 1024, 2944,
  1664, 2688, 48, 1664, 2688, 1408, 2496, -1
};
short mvtbl5_4[13] = {
  0, 0, 120, 2560, 2368, 1536, 2368, 80, 1536, 2368,
  2560, 2368, -1
};
short mvtbl5_5[18] = {
  1, 0, 100, 3072, 2176, 2688, 2176, 120, 2688, 2176,
  3072, 2944, 80, 3072, 2944, 3072, 2176, -1
};
short mvtbl6_0[33] = {
  0, 0, 32, 2560, 1792, 2816, 1536, 32, 2816, 1536,
  2560, 1792, 48, 2560, 1792, 2688, 1536, 48, 2688, 1536,
  2560, 1792, 80, 2560, 1792, 2560, 1536, 48, 2560, 1536,
  2560, 1792, -1
};
short mvtbl6_1[23] = {
  0, 0, 32, 1280, 1792, 1024, 1792, 80, 1024, 1792,
  1280, 2368, 32, 1280, 2368, 1024, 2368, 80, 1024, 2368,
  1280, 1792, -1
};
short mvtbl6_2[23] = {
  1, 0, 48, 1216, 2944, 1408, 2816, 48, 1408, 2816,
  1216, 2944, 48, 1216, 2944, 1024, 2816, 48, 1024, 2816,
  1216, 2944, -1
};
short mvtbl6_3[23] = {
  0, 0, 80, 1664, 2560, 1664, 2816, 80, 1664, 2816,
  1664, 2560, 120, 1664, 2560, 2176, 2944, 120, 2176, 2944,
  1664, 2560, -1
};
short mvtbl6_4[18] = {
  0, 0, 80, 2688, 2432, 2304, 2816, 100, 2304, 2816,
  3008, 3008, 100, 3008, 3008, 2688, 2432, -1
};
short mvtbl6_5[18] = {
  1, 0, 80, 3072, 1664, 2816, 2048, 32, 2816, 2048,
  3072, 2048, 48, 3072, 2048, 3072, 1664, -1
};
short mvtbl7_0[18] = {
  0, 0, 120, 2816, 2944, 3072, 2432, 48, 3072, 2432,
  3072, 2688, 80, 3072, 2688, 2816, 2944, -1
};
short mvtbl7_1[18] = {
  1, 0, 120, 3072, 1792, 2560, 1280, 80, 2560, 1280,
  2944, 1088, 120, 2944, 1088, 3072, 1792, -1
};
short mvtbl7_2[53] = {
  0, 0, 120, 2432, 2368, 2688, 2176, 120, 2688, 2176,
  2432, 2048, 120, 2432, 2048, 2688, 1920, 48, 2688, 1920,
  2560, 1792, 80, 2560, 1792, 2560, 1536, 80, 2560, 1536,
  2560, 1792, 48, 2560, 1792, 2688, 1920, 120, 2688, 1920,
  2432, 2048, 120, 2432, 2048, 2688, 2176, 120, 2688, 2176,
  2432, 2368, -1
};
short mvtbl7_3[23] = {
  0, 0, 80, 2048, 1792, 1664, 1920, 120, 1664, 1920,
  1792, 1280, 80, 1792, 1280, 1408, 1408, 120, 1408, 1408,
  2048, 1792, -1
};
short mvtbl7_4[23] = {
  1, 0, 80, 1664, 2944, 1024, 2688, 48, 1024, 2688,
  1024, 2176, 48, 1024, 2176, 1536, 2304, 80, 1536, 2304,
  1664, 2944, -1
};
short mvtbl7_5[13] = {
  0, 0, 80, 1536, 1152, 1024, 1536, 80, 1024, 1536,
  1536, 1152, -1
};
move_tbl mvtbl0 = {
  6,
  { mvtbl0_0, mvtbl0_1, mvtbl0_2, mvtbl0_3, mvtbl0_4, mvtbl0_5 }
};
move_tbl mvtbl1 = {
  6,
  { mvtbl1_0, mvtbl1_1, mvtbl1_2, mvtbl1_3, mvtbl1_4, mvtbl1_5 }
};
move_tbl mvtbl2 = {
  6,
  { mvtbl2_0, mvtbl2_1, mvtbl2_2, mvtbl2_3, mvtbl2_4, mvtbl2_5 }
};
move_tbl mvtbl3 = {
  6,
  { mvtbl3_0, mvtbl3_1, mvtbl3_2, mvtbl3_3, mvtbl3_4, mvtbl3_5 }
};
move_tbl mvtbl4 = {
  6,
  { mvtbl4_0, mvtbl4_1, mvtbl4_2, mvtbl4_3, mvtbl4_4, mvtbl4_5 }
};
move_tbl mvtbl5 = {
  6,
  { mvtbl5_0, mvtbl5_1, mvtbl5_2, mvtbl5_3, mvtbl5_4, mvtbl5_5 }
};
move_tbl mvtbl6 = {
  6,
  { mvtbl6_0, mvtbl6_1, mvtbl6_2, mvtbl6_3, mvtbl6_4, mvtbl6_5 }
};
move_tbl mvtbl7 = {
  6,
  { mvtbl7_0, mvtbl7_1, mvtbl7_2, mvtbl7_3, mvtbl7_4, mvtbl7_5 }
};
extern sprite_patterns_sp* mpufoy[10];
extern sprite_patterns_sp* mpufox[10];
move_tbl* mvtbl_tbl[8] = { &mvtbl0, &mvtbl1, &mvtbl2, &mvtbl3, &mvtbl4, &mvtbl5, &mvtbl6, &mvtbl7 };
short tufo_tbl[43] = {
  2, 0, 90, 2048, 2048, 1920, 2048, 90, 1920, 2048,
  2048, 2048, 90, 2048, 2048, 2048, 1920, 90, 2048, 1920,
  2048, 2048, 90, 2048, 2048, 2176, 2048, 90, 2176, 2048,
  2048, 2048, 90, 2048, 2048, 2048, 2176, 90, 2048, 2176,
  2048, 2048, -1
};
extern sprite_patterns_sp* mpkage[10];





















void bara_ring(sprite_status_sp* actionwk) { /* Line 66, Address: 0x1001500 */
  switch (actionwk->exeno) /* Line 67, Address: 0x100150c */
  {
    case 0:
      b_ring00(actionwk); /* Line 70, Address: 0x1001534 */
      break; /* Line 71, Address: 0x1001540 */
    case 1:
      b_ring01(actionwk); /* Line 73, Address: 0x1001548 */
  }

  patset(actionwk); /* Line 76, Address: 0x1001554 */
} /* Line 77, Address: 0x1001560 */

void b_ring00(sprite_status_sp* actionwk) { /* Line 79, Address: 0x1001570 */
  int d0, d1;

  actionwk->sprcolor = 59279; /* Line 82, Address: 0x1001584 */
  actionwk->pattbl = mpitem; /* Line 83, Address: 0x1001590 */
  actionwk->actfree[2] = 4; /* Line 84, Address: 0x10015a0 */
  patinit(actionwk, actionwk->actfree[2]); /* Line 85, Address: 0x10015ac */
  actionwk->sx_posi.w.h = actwk[0].sx_posi.w.h; /* Line 86, Address: 0x10015c0 */
  actionwk->sy_posi.w.h = actwk[0].sy_posi.w.h; /* Line 87, Address: 0x10015d0 */
  ++actionwk->exeno; /* Line 88, Address: 0x10015e0 */
  actionwk->actfree[0] = 45; /* Line 89, Address: 0x10015f0 */
  d0 = d1 = random(); /* Line 90, Address: 0x10015fc */
  d1 &= 258048; /* Line 91, Address: 0x100160c */
  if (pmflag & 1) d1 = -d1; /* Line 92, Address: 0x1001618 */

  pmflag ^= 1; /* Line 94, Address: 0x1001634 */
  actionwk->sx_speed.l = d1; /* Line 95, Address: 0x1001648 */
  d0 &= 15; /* Line 96, Address: 0x1001650 */
  actionwk->sy_speed.w.h = -(d0 + 10); /* Line 97, Address: 0x1001654 */


} /* Line 100, Address: 0x100166c */

void b_ring01(sprite_status_sp* actionwk) { /* Line 102, Address: 0x1001690 */
  if (--actionwk->actfree[0] == 0) actionwk->actflg |= 1; /* Line 103, Address: 0x1001698 */

  actionwk->sx_posi.l += actionwk->sx_speed.l; /* Line 105, Address: 0x10016c8 */
  actionwk->sy_posi.l += actionwk->sy_speed.l; /* Line 106, Address: 0x10016e0 */
  if (actionwk->sy_posi.w.h < 345) /* Line 107, Address: 0x10016f8 */
  {
    actionwk->sy_speed.l += 131072; /* Line 109, Address: 0x1001714 */
  } /* Line 110, Address: 0x1001728 */
  else
  {
    actionwk->sy_posi.w.h = 344; /* Line 113, Address: 0x1001730 */
    actionwk->sy_speed.l = ~actionwk->sy_speed.l; /* Line 114, Address: 0x100173c */
  }
} /* Line 116, Address: 0x1001750 */

void item_ring(sprite_status_sp* actionwk) { /* Line 118, Address: 0x1001760 */
  switch (actionwk->exeno) /* Line 119, Address: 0x100176c */
  {
    case 0:
      i_ring00(actionwk); /* Line 122, Address: 0x1001794 */
      break; /* Line 123, Address: 0x10017a0 */
    case 1:
      i_ring01(actionwk); /* Line 125, Address: 0x10017a8 */
      break;
  }
  patset(actionwk); /* Line 128, Address: 0x10017b4 */
} /* Line 129, Address: 0x10017c0 */

void i_ring00(sprite_status_sp* actionwk) { /* Line 131, Address: 0x10017d0 */
  actionwk->sprcolor = 34703; /* Line 132, Address: 0x10017dc */
  actionwk->pattbl = mpitem; /* Line 133, Address: 0x10017e8 */
  actionwk->actfree[2] = actionwk->actfree[1]; /* Line 134, Address: 0x10017f8 */
  patinit(actionwk, actionwk->actfree[2]); /* Line 135, Address: 0x1001808 */
  ++actionwk->exeno; /* Line 136, Address: 0x100181c */
  actionwk->actfree[2] = 16; /* Line 137, Address: 0x100182c */
  actionwk->sy_speed.w.h = -16; /* Line 138, Address: 0x1001838 */
  key_set(149); /* Line 139, Address: 0x1001844 */
} /* Line 140, Address: 0x1001850 */

void i_ring01(sprite_status_sp* actionwk) { /* Line 142, Address: 0x1001860 */
  if (--actionwk->actfree[0] == 0) actionwk->actflg &= 1; /* Line 143, Address: 0x1001868 */

  actionwk->sy_posi.l += actionwk->sy_speed.l; /* Line 145, Address: 0x1001898 */
  actionwk->sy_speed.l = actionwk->sy_speed.l + 2; /* Line 146, Address: 0x10018b0 */
} /* Line 147, Address: 0x10018c4 */

void timeufo(sprite_status_sp* actionwk) { /* Line 149, Address: 0x10018d0 */
  switch (actionwk->exeno) /* Line 150, Address: 0x10018dc */
  {
    case 0:
      tufo00(actionwk); /* Line 153, Address: 0x1001910 */
    case 1:
      tufo01(actionwk); /* Line 155, Address: 0x100191c */
      break; /* Line 156, Address: 0x1001928 */
    case 2:
      tufo02(actionwk); /* Line 158, Address: 0x1001930 */
      break;
  }
  actionwk->z_posi.w.h = actwk[0].z_posi.w.h; /* Line 161, Address: 0x100193c */
  actionwk->z_posi.w.h -= 320; /* Line 162, Address: 0x100194c */
  if (actionwk->actfree[20]) /* Line 163, Address: 0x100195c */
  {
    --actionwk->actfree[20]; /* Line 165, Address: 0x100196c */
    actionwk->actflg |= 4; /* Line 166, Address: 0x100197c */
  }
} /* Line 168, Address: 0x100198c */

void tufo00(sprite_status_sp* actionwk) { /* Line 170, Address: 0x10019a0 */
  actionwk->sprcolor = 33856; /* Line 171, Address: 0x10019ac */
  mvtblset(actionwk); /* Line 172, Address: 0x10019b8 */

  actionwk->pattbl = tpufox; /* Line 174, Address: 0x10019c4 */
  actionwk->z_posi.w.h = actwk[0].z_posi.w.h; /* Line 175, Address: 0x10019d4 */
  actionwk->z_posi.w.h -= 320; /* Line 176, Address: 0x10019e4 */
  ++actionwk->exeno; /* Line 177, Address: 0x10019f4 */
  actionwk->actfree[20] = 2; /* Line 178, Address: 0x1001a04 */
  key_set(188); /* Line 179, Address: 0x1001a10 */
} /* Line 180, Address: 0x1001a1c */

void tufo01(sprite_status_sp* actionwk) { /* Line 182, Address: 0x1001a30 */
  unsigned short* mcnt;
  sprite_status_sp* a1;
  unsigned char d0;

  mcnt = (unsigned short*)(actionwk->actfree + 16); /* Line 187, Address: 0x1001a48 */

  actionwk->x_posi.l += actionwk->x_speed.l; /* Line 189, Address: 0x1001a50 */
  actionwk->y_posi.l += actionwk->y_speed.l; /* Line 190, Address: 0x1001a68 */
  if (--*mcnt == 0) /* Line 191, Address: 0x1001a80 */
  {
    mvtblset(actionwk); /* Line 193, Address: 0x1001a9c */
  }

  ptset_ufo(actionwk); /* Line 196, Address: 0x1001aa8 */
  scal(actionwk); /* Line 197, Address: 0x1001ab4 */
  ufovspl(actionwk); /* Line 198, Address: 0x1001ac0 */
  if (!actionwk->colliflg) return; /* Line 199, Address: 0x1001acc */
  if (time_stop) return; /* Line 200, Address: 0x1001adc */
  actionwk->exeno = 2; /* Line 201, Address: 0x1001aec */
  a1 = &actwk[((unsigned short*)actionwk)[38]]; /* Line 202, Address: 0x1001af8 */
  a1->actflg |= 1; /* Line 203, Address: 0x1001b1c */
  ((short*)actionwk)[36] = 60; /* Line 204, Address: 0x1001b28 */
  d0 = random() & 1; /* Line 205, Address: 0x1001b34 */
  d0 = actionwk->actfree[3]; /* Line 206, Address: 0x1001b48 */
  patinit(actionwk, 0); /* Line 207, Address: 0x1001b50 */
  spe_time.l += 30; /* Line 208, Address: 0x1001b60 */
  a1 = &actwk[16]; /* Line 209, Address: 0x1001b74 */
  a1->actno = 4; /* Line 210, Address: 0x1001b7c */
  a1->actfree[1] = 3; /* Line 211, Address: 0x1001b84 */
  a1->sx_posi.w.h = actionwk->sx_posi.w.h; /* Line 212, Address: 0x1001b8c */
  a1->sy_posi.w.h = actionwk->sy_posi.w.h; /* Line 213, Address: 0x1001b98 */
} /* Line 214, Address: 0x1001ba4 */

void tufo02(sprite_status_sp* actionwk) { /* Line 216, Address: 0x1001bc0 */
  unsigned short *tim, d0;
  sprite_status_sp* a1;

  tim = (unsigned short*)(actionwk->actfree); /* Line 220, Address: 0x1001bd4 */

  actionwk->sx_posi.w.h -= 4; /* Line 222, Address: 0x1001bdc */
  if (actionwk->actfree[3] == 0) actionwk->sx_posi.w.h += 8; /* Line 223, Address: 0x1001bec */

  ++actionwk->sy_posi.w.h; /* Line 225, Address: 0x1001c10 */
  actionwk->actflg &= 251; /* Line 226, Address: 0x1001c20 */
  if (--*tim == 0) actionwk->actflg |= 1; /* Line 227, Address: 0x1001c30 */

  if (actionwk->actfree[0] & 1) /* Line 229, Address: 0x1001c5c */
  {
    if (exp_set(&a1) != 0) return; /* Line 231, Address: 0x1001c74 */
    a1->actno = 12; /* Line 232, Address: 0x1001c88 */
    a1->sx_posi.w.h = actionwk->sx_posi.w.h - 16; /* Line 233, Address: 0x1001c94 */
    a1->sy_posi.w.h = actionwk->sy_posi.w.h; /* Line 234, Address: 0x1001cb8 */
    d0 = (unsigned char)random(); /* Line 235, Address: 0x1001cc8 */
    a1->sx_posi.w.h += d0 & 31; /* Line 236, Address: 0x1001cdc */

    a1->sy_posi.w.h -= d0 & 31; /* Line 238, Address: 0x1001cfc */
  }
} /* Line 240, Address: 0x1001d1c */

void ufo0(sprite_status_sp* actionwk) { /* Line 242, Address: 0x1001d40 */

  switch (actionwk->exeno) /* Line 244, Address: 0x1001d4c */
  {

    case 0:
      ufo00(actionwk); /* Line 248, Address: 0x1001d80 */

    case 1:
      ufo01(actionwk); /* Line 251, Address: 0x1001d8c */
      break; /* Line 252, Address: 0x1001d98 */

    case 2:
      ufo02(actionwk); /* Line 255, Address: 0x1001da0 */
      break;
  }
  actionwk->z_posi.w.h = actwk[0].z_posi.w.h; /* Line 258, Address: 0x1001dac */
  actionwk->z_posi.w.h -= 320; /* Line 259, Address: 0x1001dbc */
  if (actionwk->actfree[20] != 0) /* Line 260, Address: 0x1001dcc */
  {
    --actionwk->actfree[20]; /* Line 262, Address: 0x1001ddc */
    actionwk->actflg |= 4; /* Line 263, Address: 0x1001dec */
  }

} /* Line 266, Address: 0x1001dfc */

void ufo00(sprite_status_sp* actionwk) { /* Line 268, Address: 0x1001e10 */
  actionwk->sprcolor = 58432; /* Line 269, Address: 0x1001e1c */

  mvtblset(actionwk); /* Line 271, Address: 0x1001e28 */

  actionwk->pattbl = mpufox; /* Line 273, Address: 0x1001e34 */
  if (actionwk->actfree[18] != 0) actionwk->pattbl = mpufoy; /* Line 274, Address: 0x1001e44 */

  actionwk->z_posi.w.h = actwk[0].z_posi.w.h; /* Line 276, Address: 0x1001e68 */
  actionwk->z_posi.w.h -= 320; /* Line 277, Address: 0x1001e78 */
  actionwk->actfree[2] = 0; /* Line 278, Address: 0x1001e88 */
  patinit(actionwk, actionwk->actfree[2]); /* Line 279, Address: 0x1001e90 */

  actionwk->actfree[20] = 2; /* Line 281, Address: 0x1001ea4 */
  ++actionwk->exeno; /* Line 282, Address: 0x1001eb0 */
} /* Line 283, Address: 0x1001ec0 */

void ufo01(sprite_status_sp* actionwk) { /* Line 285, Address: 0x1001ed0 */
  unsigned short* mcnt;
  sprite_status_sp* a1;

  mcnt = (unsigned short*)(actionwk->actfree + 16); /* Line 289, Address: 0x1001ee4 */
  actionwk->x_posi.l += actionwk->x_speed.l; /* Line 290, Address: 0x1001eec */
  actionwk->y_posi.l += actionwk->y_speed.l; /* Line 291, Address: 0x1001f04 */
  if (--*mcnt == 0) /* Line 292, Address: 0x1001f1c */
  {
    mvtblset(actionwk); /* Line 294, Address: 0x1001f38 */
  }

  ptset_ufo(actionwk); /* Line 297, Address: 0x1001f44 */
  scal(actionwk); /* Line 298, Address: 0x1001f50 */
  ufovspl(actionwk); /* Line 299, Address: 0x1001f5c */
  if (!actionwk->colliflg) return; /* Line 300, Address: 0x1001f68 */
  if (ufoleft < 2) time_stop = 1; /* Line 301, Address: 0x1001f78 */

  ufo_dec(); /* Line 303, Address: 0x1001f9c */
  actionwk->exeno = 2; /* Line 304, Address: 0x1001fa4 */
  a1 = &actwk[((unsigned short*)actionwk)[38]]; /* Line 305, Address: 0x1001fb0 */
  a1->actflg |= 1; /* Line 306, Address: 0x1001fd4 */
  ((short*)actionwk)[36] = 60; /* Line 307, Address: 0x1001fe0 */
  actionwk->actfree[3] = random() & 1; /* Line 308, Address: 0x1001fec */
  patinit(actionwk, 0); /* Line 309, Address: 0x1002004 */

  a1 = &actwk[16]; /* Line 311, Address: 0x1002014 */
  a1->actno = 4; /* Line 312, Address: 0x100201c */
  a1->sx_posi.w.h = actionwk->sx_posi.w.h; /* Line 313, Address: 0x1002024 */
  a1->sy_posi.w.h = actionwk->sy_posi.w.h; /* Line 314, Address: 0x1002030 */
  a1->actfree[1] = actionwk->actfree[18]; /* Line 315, Address: 0x100203c */

  switch (actionwk->actfree[18]) /* Line 317, Address: 0x1002048 */
  {
    case 0:
    case 2:
    case 3:
      rufo_getnm *= 2; /* Line 322, Address: 0x1002088 */
      ring_add(rufo_getnm >> 1 & 65535); /* Line 323, Address: 0x100209c */
      break; /* Line 324, Address: 0x10020bc */
    case 1:
      ((short*)actwk)[45] = 200; /* Line 326, Address: 0x10020c4 */
      rufo_getnm = 20; /* Line 327, Address: 0x10020d0 */
  }

} /* Line 330, Address: 0x10020dc */

void ufo02(sprite_status_sp* actionwk) { /* Line 332, Address: 0x1002100 */
  unsigned short *tim, d0;
  sprite_status_sp* a1;

  tim = (unsigned short*)(actionwk->actfree); /* Line 336, Address: 0x1002114 */

  actionwk->sx_posi.w.h -= 4; /* Line 338, Address: 0x100211c */
  if (actionwk->actfree[3] == 0) actionwk->sx_posi.w.h += 8; /* Line 339, Address: 0x100212c */

  ++actionwk->sy_posi.w.h; /* Line 341, Address: 0x1002150 */
  actionwk->actflg &= 251; /* Line 342, Address: 0x1002160 */
  if (--*tim == 0) actionwk->actflg |= 1; /* Line 343, Address: 0x1002170 */

  if (actionwk->actfree[1] & 1) return; /* Line 345, Address: 0x100219c */

  if (exp_set(&a1) != 0) return; /* Line 347, Address: 0x10021b4 */
  a1->actno = 12; /* Line 348, Address: 0x10021c8 */
  a1->sx_posi.w.h = actionwk->sx_posi.w.h - 16; /* Line 349, Address: 0x10021d4 */
  a1->sy_posi.w.h = actionwk->sy_posi.w.h; /* Line 350, Address: 0x10021f8 */
  d0 = (unsigned char)random(); /* Line 351, Address: 0x1002208 */
  a1->sx_posi.w.h += d0 & 31; /* Line 352, Address: 0x100221c */

  a1->sy_posi.w.h += d0 & 31; /* Line 354, Address: 0x100223c */
} /* Line 355, Address: 0x100225c */

void mvtblset(sprite_status_sp* actionwk) { /* Line 357, Address: 0x1002280 */
  short* a1;
  short d0, d1, d2, d3;
  short mcnt;
  int d2l, d3l;

  do {
    a1 = ((short**)actionwk)[21]; /* Line 364, Address: 0x10022a8 */

    mcnt = ((short*)actionwk)[44] = *a1++; /* Line 366, Address: 0x10022b0 */
    if (mcnt >= 0) break; /* Line 367, Address: 0x10022cc */

    ((int*)actionwk)[21] = ((int*)actionwk)[20]; /* Line 369, Address: 0x10022dc */

  } while (1); /* Line 371, Address: 0x10022ec */

  d0 = *a1++; /* Line 373, Address: 0x10022f4 */
  d1 = *a1++; /* Line 374, Address: 0x1002308 */
  actionwk->x_posi.w.h = d0; /* Line 375, Address: 0x100231c */
  actionwk->y_posi.w.h = d1; /* Line 376, Address: 0x1002324 */
  d2 = *a1++; /* Line 377, Address: 0x100232c */
  d3 = *a1++; /* Line 378, Address: 0x1002340 */
  d2 -= d0; /* Line 379, Address: 0x1002354 */
  d3 -= d1; /* Line 380, Address: 0x1002360 */
  d2l = d2; /* Line 381, Address: 0x100236c */
  d3l = d3; /* Line 382, Address: 0x1002374 */
  d2l <<= 4; /* Line 383, Address: 0x100237c */
  d3l <<= 4; /* Line 384, Address: 0x1002380 */
  d2l /= mcnt; /* Line 385, Address: 0x1002384 */
  d3l /= mcnt; /* Line 386, Address: 0x10023a0 */
  d2l <<= 12; /* Line 387, Address: 0x10023bc */
  d3l <<= 12; /* Line 388, Address: 0x10023c0 */
  actionwk->x_speed.l = d2l; /* Line 389, Address: 0x10023c4 */
  actionwk->y_speed.l = d3l; /* Line 390, Address: 0x10023cc */
  ((short**)actionwk)[21] = a1; /* Line 391, Address: 0x10023d4 */
} /* Line 392, Address: 0x10023dc */




void ufo_frout_chk(sprite_status_sp* actionwk) { /* Line 397, Address: 0x1002410 */
  short d0;

  actionwk->actflg &= 251; /* Line 400, Address: 0x100241c */
  d0 = actionwk->sx_posi.w.h; /* Line 401, Address: 0x100242c */
  if ((unsigned short)d0 >= 512) /* Line 402, Address: 0x100243c */
  {
    actionwk->actflg |= 4; /* Line 404, Address: 0x1002450 */
    return; /* Line 405, Address: 0x1002460 */
  }
  d0 = actionwk->sy_posi.w.h; /* Line 407, Address: 0x1002468 */
  if (d0 < 256) /* Line 408, Address: 0x1002478 */
  {
    actionwk->actflg |= 4; /* Line 410, Address: 0x100248c */
    return; /* Line 411, Address: 0x100249c */
  }
  if (d0 < 448) return; /* Line 413, Address: 0x10024a4 */

  actionwk->actflg |= 4; /* Line 415, Address: 0x10024b8 */
} /* Line 416, Address: 0x10024c8 */

void ptset_ufo(sprite_status_sp* actionwk) { /* Line 418, Address: 0x10024e0 */
  unsigned char tbl[81] = /* Line 419, Address: 0x100250c */
  {
    0, 1, 2, 2, 3, 3, 3, 3, 4, 4, 4, 4, 4, 4, 4, 4, 5, 5,
    5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 6, 6, 6, 6,
    6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 7, 7, 7, 7, 7, 7,
    7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 8, 8, 8, 8, 8, 8, 8, 8,
    8, 8, 8, 8, 8, 8, 8, 8, 9
  };
  sprite_status_sp* a6;
  unsigned short d0, d1, d3, d4, d5, d6;
  int d0l;
  unsigned char d1b, d2b;

  a6 = &actwk[0]; /* Line 432, Address: 0x1002538 */

  d4 = a6->x_posi.w.h; /* Line 434, Address: 0x1002540 */
  d5 = a6->y_posi.w.h; /* Line 435, Address: 0x1002548 */
  d0 = actionwk->x_posi.w.h; /* Line 436, Address: 0x1002550 */
  d1 = actionwk->y_posi.w.h; /* Line 437, Address: 0x100255c */
  angleget(d0, d1, d4, d5, &d1b, &d2b); /* Line 438, Address: 0x1002568 */
  d5 = a6->x_posi.w.h; /* Line 439, Address: 0x1002598 */
  d6 = a6->y_posi.w.h; /* Line 440, Address: 0x10025a0 */
  d3 = actionwk->x_posi.w.h; /* Line 441, Address: 0x10025a8 */
  d4 = actionwk->y_posi.w.h; /* Line 442, Address: 0x10025b4 */
  d0l = dstnsget(d1b, d2b, d3, d4, d5, d6); /* Line 443, Address: 0x10025c0 */
  zbuf_set(actionwk, d0l); /* Line 444, Address: 0x10025f4 */


  if (d0l >= 1280U) d0l = 1280; /* Line 447, Address: 0x1002604 */
  d0l >>= 4; /* Line 448, Address: 0x1002614 */
  if (d0l >= 81) d0l = 80; /* Line 449, Address: 0x1002618 */

  if (actionwk->actfree[2] == tbl[d0l]) return; /* Line 451, Address: 0x1002628 */
  actionwk->actfree[2] = tbl[d0l]; /* Line 452, Address: 0x1002648 */
  patinit1(actionwk, actionwk->actfree[2]); /* Line 453, Address: 0x1002658 */










} /* Line 464, Address: 0x100266c */















void ufo_initial() { /* Line 480, Address: 0x10026a0 */
  move_tbl* a1;
  sprite_status_sp* a2;
  char d7;
  short cnt;


  a2 = &actwk[32]; /* Line 487, Address: 0x10026b8 */
  a1 = mvtbl_tbl[stagenm]; /* Line 488, Address: 0x10026c0 */
  d7 = mvtbl_tbl[stagenm]->no; /* Line 489, Address: 0x10026e0 */
  ufoleft = d7; /* Line 490, Address: 0x100270c */

  cnt = 0; /* Line 492, Address: 0x1002714 */
  while (d7) /* Line 493, Address: 0x1002718 */
  {

    u_init(cnt++, a2++); /* Line 496, Address: 0x1002720 */
    --d7; /* Line 497, Address: 0x1002740 */
  } /* Line 498, Address: 0x100274c */
} /* Line 499, Address: 0x1002754 */

void u_init(short cnt, sprite_status_sp* a2) { /* Line 501, Address: 0x1002780 */
  sprite_status_sp* a4;
  unsigned short dummy;
  short* a1tbl;

  a1tbl = mvtbl_tbl[stagenm]->mv_tbl[cnt]; /* Line 506, Address: 0x1002798 */

  dummy = a2 - actwk; /* Line 508, Address: 0x10027d0 */
  a4 = &actwk[dummy + 8]; /* Line 509, Address: 0x1002800 */
  a2->actno = 2; /* Line 510, Address: 0x1002820 */
  a2->actfree[18] = a1tbl[0]; /* Line 511, Address: 0x100282c */
  a2->actfree[19] = a1tbl[1]; /* Line 512, Address: 0x1002844 */
  a1tbl += 2; /* Line 513, Address: 0x100285c */
  ((short**)a2)[20] = a1tbl; /* Line 514, Address: 0x1002860 */
  ((short**)a2)[21] = a1tbl; /* Line 515, Address: 0x1002868 */
  ((unsigned short*)a2)[38] = dummy + 8; /* Line 516, Address: 0x1002870 */
  a4->actno = 5; /* Line 517, Address: 0x1002884 */
  ((unsigned short*)a4)[38] = a2 - actwk; /* Line 518, Address: 0x100288c */
} /* Line 519, Address: 0x10028bc */

void tufo_initial() { /* Line 521, Address: 0x10028e0 */
  sprite_status_sp *a2, *a4;
  short *a3, dummy;

  if (spe_time.l >= 21) return; /* Line 525, Address: 0x10028f4 */
  a2 = &actwk[39]; /* Line 526, Address: 0x1002908 */
  a3 = tufo_tbl; /* Line 527, Address: 0x1002910 */
  if (a2->actno) return; /* Line 528, Address: 0x1002918 */
  dummy = (unsigned short)(a2 - actwk); /* Line 529, Address: 0x1002924 */
  a4 = &actwk[dummy + 8]; /* Line 530, Address: 0x100295c */

  a2->actno = 3; /* Line 532, Address: 0x1002980 */

  a2->actfree[18] = (char)tufo_tbl[0]; /* Line 534, Address: 0x1002988 */
  a2->actfree[19] = (char)tufo_tbl[1]; /* Line 535, Address: 0x1002998 */
  a3 += 2; /* Line 536, Address: 0x10029a8 */
  ((short**)a2)[20] = a3; /* Line 537, Address: 0x10029ac */
  ((short**)a2)[21] = a3; /* Line 538, Address: 0x10029b0 */
  ((unsigned short*)a2)[38] = (unsigned short)dummy + 8; /* Line 539, Address: 0x10029b4 */
  a4->actno = 5; /* Line 540, Address: 0x10029c8 */
  ((unsigned short*)a4)[38] = a2 - actwk; /* Line 541, Address: 0x10029d0 */
} /* Line 542, Address: 0x10029fc */

void plkage(sprite_status_sp* actionwk) { /* Line 544, Address: 0x1002a20 */
  switch (actionwk->exeno) /* Line 545, Address: 0x1002a2c */
  {
    case 0:
      plkage00(actionwk); /* Line 548, Address: 0x1002a54 */
    case 1:
      plkage01(actionwk); /* Line 550, Address: 0x1002a60 */
  }

  patset(actionwk); /* Line 553, Address: 0x1002a6c */
} /* Line 554, Address: 0x1002a78 */

void plkage00(sprite_status_sp* actionwk) { /* Line 556, Address: 0x1002a90 */
  actionwk->sprcolor = 59100; /* Line 557, Address: 0x1002a9c */
  actionwk->pattbl = mpkage; /* Line 558, Address: 0x1002aa8 */
  actionwk->actfree[2] = 5; /* Line 559, Address: 0x1002ab8 */
  patinit(actionwk, actionwk->actfree[2]); /* Line 560, Address: 0x1002ac4 */
  ++actionwk->exeno; /* Line 561, Address: 0x1002ad8 */
} /* Line 562, Address: 0x1002ae8 */

void plkage01(sprite_status_sp* actionwk) { /* Line 564, Address: 0x1002b00 */
  sprite_status_sp* a1;

  a1 = &actwk[0]; /* Line 567, Address: 0x1002b10 */
  actionwk->x_posi.w.h = a1->x_posi.w.h; /* Line 568, Address: 0x1002b18 */
  actionwk->y_posi.w.h = a1->y_posi.w.h; /* Line 569, Address: 0x1002b24 */
  actionwk->z_posi.w.h = actwk[0].z_posi.w.h; /* Line 570, Address: 0x1002b30 */
  scal(actionwk); /* Line 571, Address: 0x1002b40 */
} /* Line 572, Address: 0x1002b4c */

void kage(sprite_status_sp* actionwk) { /* Line 574, Address: 0x1002b60 */
  switch (actionwk->exeno) /* Line 575, Address: 0x1002b6c */
  {
    case 0:
      kage00(actionwk); /* Line 578, Address: 0x1002b94 */
    case 1:
      kage01(actionwk); /* Line 580, Address: 0x1002ba0 */
  }

  ufo_frout_chk(actionwk); /* Line 583, Address: 0x1002bac */
  patset(actionwk); /* Line 584, Address: 0x1002bb8 */
} /* Line 585, Address: 0x1002bc4 */

void kage00(sprite_status_sp* actionwk) { /* Line 587, Address: 0x1002be0 */
  actionwk->sprcolor = 59100; /* Line 588, Address: 0x1002bec */
  actionwk->pattbl = mpkage; /* Line 589, Address: 0x1002bf8 */
  actionwk->actfree[2] = 0; /* Line 590, Address: 0x1002c08 */
  patinit(actionwk, actionwk->actfree[2]); /* Line 591, Address: 0x1002c10 */
  ++actionwk->exeno; /* Line 592, Address: 0x1002c24 */
} /* Line 593, Address: 0x1002c34 */

void kage01(sprite_status_sp* actionwk) { /* Line 595, Address: 0x1002c50 */
  sprite_status_sp* a1;

  a1 = &actwk[((unsigned short*)actionwk)[38]]; /* Line 598, Address: 0x1002c60 */
  actionwk->x_posi.w.h = a1->x_posi.w.h; /* Line 599, Address: 0x1002c84 */
  actionwk->y_posi.w.h = a1->y_posi.w.h; /* Line 600, Address: 0x1002c90 */
  a1->actflg |= 4; /* Line 601, Address: 0x1002c9c */
  if ((actionwk->actflg & 4) == 0) /* Line 602, Address: 0x1002ca8 */
  {
    a1->actflg &= 251; /* Line 604, Address: 0x1002cc0 */
  }

  actionwk->z_posi.w.h = actwk[0].z_posi.w.h; /* Line 607, Address: 0x1002ccc */
  ptset_ufo(actionwk); /* Line 608, Address: 0x1002cdc */
  scal(actionwk); /* Line 609, Address: 0x1002ce8 */
} /* Line 610, Address: 0x1002cf4 */

void press(sprite_status_sp* actionwk) { /* Line 612, Address: 0x1002d10 */
  switch (actionwk->exeno) /* Line 613, Address: 0x1002d1c */
  {
    case 0:
      press00(actionwk); /* Line 616, Address: 0x1002d44 */
    case 1:
      press01(actionwk); /* Line 618, Address: 0x1002d50 */
  }

  patset(actionwk); /* Line 621, Address: 0x1002d5c */
} /* Line 622, Address: 0x1002d68 */

void press00(sprite_status_sp* actionwk) { /* Line 624, Address: 0x1002d80 */
  actionwk->sprcolor = 34154; /* Line 625, Address: 0x1002d8c */
  actionwk->pattbl = mppress; /* Line 626, Address: 0x1002d98 */
  actionwk->sx_posi.w.h = 212; /* Line 627, Address: 0x1002da8 */
  actionwk->sy_posi.w.h = 208; /* Line 628, Address: 0x1002db4 */
  patinit(actionwk, 0); /* Line 629, Address: 0x1002dc0 */
  ++actionwk->exeno; /* Line 630, Address: 0x1002dd0 */
} /* Line 631, Address: 0x1002de0 */

void press01(sprite_status_sp* actionwk) { /* Line 633, Address: 0x1002df0 */
  ++actionwk->actfree[0]; /* Line 634, Address: 0x1002df8 */
  actionwk->actflg |= 4; /* Line 635, Address: 0x1002e08 */
  if (actionwk->actfree[0] & 16) return; /* Line 636, Address: 0x1002e18 */
  actionwk->actflg &= 251; /* Line 637, Address: 0x1002e30 */
} /* Line 638, Address: 0x1002e40 */

void title_logo(sprite_status_sp* actionwk) { /* Line 640, Address: 0x1002e50 */
  switch (actionwk->exeno) /* Line 641, Address: 0x1002e5c */
  {
    case 0:
      tlogo00(actionwk); /* Line 644, Address: 0x1002e9c */
      break; /* Line 645, Address: 0x1002ea8 */
    case 1:
      tlogo01(actionwk); /* Line 647, Address: 0x1002eb0 */
      break; /* Line 648, Address: 0x1002ebc */
    case 2:
      tlogo02(actionwk); /* Line 650, Address: 0x1002ec4 */
      break; /* Line 651, Address: 0x1002ed0 */
    case 3:
      tlogo03(actionwk); /* Line 653, Address: 0x1002ed8 */
  }

  patset(actionwk); /* Line 656, Address: 0x1002ee4 */
} /* Line 657, Address: 0x1002ef0 */

void tlogo00(sprite_status_sp* actionwk) { /* Line 659, Address: 0x1002f00 */
  actionwk->sprcolor = 34070; /* Line 660, Address: 0x1002f0c */
  actionwk->pattbl = mptlogo; /* Line 661, Address: 0x1002f18 */
  actionwk->sx_posi.w.h = 456; /* Line 662, Address: 0x1002f28 */
  actionwk->sy_posi.w.h = 240; /* Line 663, Address: 0x1002f34 */
  patinit(actionwk, 0); /* Line 664, Address: 0x1002f40 */
  ++actionwk->exeno; /* Line 665, Address: 0x1002f50 */
} /* Line 666, Address: 0x1002f60 */

void tlogo01(sprite_status_sp* actionwk) { /* Line 668, Address: 0x1002f70 */
  actionwk->sx_posi.w.h -= 32; /* Line 669, Address: 0x1002f78 */
  if (actionwk->sx_posi.w.h >= 333) return; /* Line 670, Address: 0x1002f88 */
  actionwk->sx_posi.w.h = 332; /* Line 671, Address: 0x1002fa4 */
  ((short*)actionwk)[36] = 80; /* Line 672, Address: 0x1002fb0 */
  ++actionwk->exeno; /* Line 673, Address: 0x1002fbc */
} /* Line 674, Address: 0x1002fcc */

void tlogo02(sprite_status_sp* actionwk) { /* Line 676, Address: 0x1002fe0 */
  if (--((unsigned short*)actionwk)[36]) return; /* Line 677, Address: 0x1002fe8 */
  ++actionwk->exeno; /* Line 678, Address: 0x1003004 */
} /* Line 679, Address: 0x1003014 */

void tlogo03(sprite_status_sp* actionwk) { /* Line 681, Address: 0x1003020 */
  actionwk->sx_posi.w.h += 32; /* Line 682, Address: 0x1003028 */
  if (actionwk->sx_posi.w.h < 464) return; /* Line 683, Address: 0x1003038 */
  actionwk->actflg |= 1; /* Line 684, Address: 0x1003054 */
} /* Line 685, Address: 0x1003064 */

void title_obi(sprite_status_sp* actionwk) { /* Line 687, Address: 0x1003070 */
  switch (actionwk->exeno) /* Line 688, Address: 0x100307c */
  {
    case 0:
      tobi00(actionwk); /* Line 691, Address: 0x10030c8 */
    case 1:
      tobi01(actionwk); /* Line 693, Address: 0x10030d4 */
      break; /* Line 694, Address: 0x10030e0 */
    case 2:
      tobi02(actionwk); /* Line 696, Address: 0x10030e8 */
      break; /* Line 697, Address: 0x10030f4 */
    case 3:
      tobi03(actionwk); /* Line 699, Address: 0x10030fc */
      break; /* Line 700, Address: 0x1003108 */
    case 4:
      tobi04(actionwk); /* Line 702, Address: 0x1003110 */
  }

  patset(actionwk); /* Line 705, Address: 0x100311c */
} /* Line 706, Address: 0x1003128 */

void tobi00(sprite_status_sp* actionwk) { /* Line 708, Address: 0x1003140 */
  actionwk->sprcolor = 34070; /* Line 709, Address: 0x100314c */
  actionwk->pattbl = mptobi; /* Line 710, Address: 0x1003158 */
  actionwk->sx_posi.w.h = 248; /* Line 711, Address: 0x1003168 */
  actionwk->sy_posi.w.h = 32; /* Line 712, Address: 0x1003174 */
  patinit(actionwk, 0); /* Line 713, Address: 0x1003180 */
  ++actionwk->exeno; /* Line 714, Address: 0x1003190 */
} /* Line 715, Address: 0x10031a0 */

void tobi01(sprite_status_sp* actionwk) { /* Line 717, Address: 0x10031b0 */
  actionwk->sy_posi.w.h += 32; /* Line 718, Address: 0x10031b8 */
  if (actionwk->sy_posi.w.h < 240) return; /* Line 719, Address: 0x10031c8 */
  actionwk->sy_posi.w.h = 240; /* Line 720, Address: 0x10031e4 */
  ((short*)actionwk)[36] = 80; /* Line 721, Address: 0x10031f0 */
  ++actionwk->exeno; /* Line 722, Address: 0x10031fc */
} /* Line 723, Address: 0x100320c */

void tobi02(sprite_status_sp* actionwk) { /* Line 725, Address: 0x1003220 */
  if (--((unsigned short*)actionwk)[36] == 0) ++actionwk->exeno; /* Line 726, Address: 0x1003228 */

  if (((unsigned short*)actionwk)[36] != 50) return; /* Line 728, Address: 0x1003258 */
  actwk[0].exeno = 21; /* Line 729, Address: 0x1003270 */
} /* Line 730, Address: 0x100327c */

void tobi03(sprite_status_sp* actionwk) { /* Line 732, Address: 0x1003290 */
  actionwk->sy_posi.w.h -= 32; /* Line 733, Address: 0x1003298 */
  if (actionwk->sy_posi.w.h > 0) return; /* Line 734, Address: 0x10032a8 */
  ((short*)actionwk)[36] = 3; /* Line 735, Address: 0x10032c0 */
  actionwk->actflg |= 4; /* Line 736, Address: 0x10032cc */
  ++actionwk->exeno; /* Line 737, Address: 0x10032dc */
  actwk[0].exeno = 1; /* Line 738, Address: 0x10032ec */
} /* Line 739, Address: 0x10032f8 */

void tobi04(sprite_status_sp* actionwk) { /* Line 741, Address: 0x1003310 */
  if (--((unsigned short*)actionwk)[36]) return; /* Line 742, Address: 0x1003318 */
  actionwk->actflg |= 1; /* Line 743, Address: 0x1003334 */
  game_start = 0; /* Line 744, Address: 0x1003344 */
} /* Line 745, Address: 0x100334c */

int exp_set(sprite_status_sp** a1) { /* Line 747, Address: 0x1003360 */
  short d7;
  sprite_status_sp* pActwk;

  pActwk = &actwk[24]; /* Line 751, Address: 0x1003370 */
  d7 = 7; /* Line 752, Address: 0x1003378 */
  while (d7) /* Line 753, Address: 0x1003384 */
  {
    if (pActwk->actno == 0) /* Line 755, Address: 0x100338c */
    {
      *a1 = pActwk; /* Line 757, Address: 0x100339c */
      return 0; /* Line 758, Address: 0x10033a4 */
    }
    ++pActwk; /* Line 760, Address: 0x10033b0 */
    --d7; /* Line 761, Address: 0x10033b4 */
  } /* Line 762, Address: 0x10033c0 */
  return 1; /* Line 763, Address: 0x10033c8 */
} /* Line 764, Address: 0x10033cc */

void explosion(sprite_status_sp* actionwk) { /* Line 766, Address: 0x10033e0 */
  switch (actionwk->exeno) /* Line 767, Address: 0x10033ec */
  {
    case 0:
      eexp00(actionwk); /* Line 770, Address: 0x1003414 */
    case 1:
      eexp01(actionwk); /* Line 772, Address: 0x1003420 */
  }

  patset(actionwk); /* Line 775, Address: 0x100342c */
} /* Line 776, Address: 0x1003438 */

void eexp00(sprite_status_sp* actionwk) { /* Line 778, Address: 0x1003450 */
  actionwk->sprcolor = 34734; /* Line 779, Address: 0x100345c */
  actionwk->pattbl = mpeexp; /* Line 780, Address: 0x1003468 */
  patinit(actionwk, 0); /* Line 781, Address: 0x1003478 */
  ((short*)actionwk)[36] = 12; /* Line 782, Address: 0x1003488 */
  ++actionwk->exeno; /* Line 783, Address: 0x1003494 */
  key_set(163); /* Line 784, Address: 0x10034a4 */
} /* Line 785, Address: 0x10034b0 */

void eexp01(sprite_status_sp* actionwk) { /* Line 787, Address: 0x10034c0 */
  if (--((unsigned short*)actionwk)[36]) return; /* Line 788, Address: 0x10034c8 */
  actionwk->actflg |= 1; /* Line 789, Address: 0x10034e4 */
} /* Line 790, Address: 0x10034f4 */
