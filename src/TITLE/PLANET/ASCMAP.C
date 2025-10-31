#include "..\..\TYPES.H"
#include "LPL_TYPES.H"

sprite_pattern_mappings_title fspr00 = {
  1,
  { { 19, 0, 8, -8, 8, -8 } }
};
sprite_pattern_mappings_title fspr01 = {
  1,
  { { 20, 0, 8, -8, 8, -8 } }
};
sprite_patterns_title flicky_tbl = {
  2,
  {
    { 3, &fspr00 },
    { 3, &fspr01 }
  }
};
sprite_patterns_title flicky_tbl1 = {
  2,
  {
    { 8, &fspr00 },
    { 8, &fspr01 }
  }
};
sprite_patterns_title flicky_tbl2 = {
  2,
  {
    { 1, &fspr00 },
    { 1, &fspr01 }
  }
};
sprite_patterns_title flicky_tbl3 = {
  1,
  { { 0, &fspr00 } }
};
sprite_pattern_mappings_title star_spr00 = {
  1,
  { { 26, 0, 12, -12, 12, -12 } }
};
sprite_pattern_mappings_title star_spr01 = {
  1,
  { { 27, 0, 12, -12, 12, -12 } }
};
sprite_pattern_mappings_title star_spr02 = {
  1,
  { { 28, 0, 12, -12, 12, -12 } }
};
sprite_pattern_mappings_title star_spr03 = {
  1,
  { { 29, 0, 4, -4, 12, -12 } }
};
sprite_pattern_mappings_title star_spr04 = {
  1,
  { { 30, 0, 12, -12, 12, -12 } }
};
sprite_pattern_mappings_title star_spr05 = {
  1,
  { { 31, 0, 12, -12, 12, -12 } }
};
sprite_patterns_title star_tbl = {
  6,
  {
    { 1, &star_spr00 },
    { 2, &star_spr01 },
    { 3, &star_spr02 },
    { 4, &star_spr03 },
    { 3, &star_spr04 },
    { 2, &star_spr05 }
  }
};
sprite_pattern_mappings_title ufo_spr00 = {
  1,
  { { 41, 0, 12, -12, 12, -12 } }
};
sprite_pattern_mappings_title ufo_spr01 = {
  1,
  { { 42, 0, 12, -12, 12, -12 } }
};
sprite_pattern_mappings_title ufo_spr02 = {
  1,
  { { 43, 0, 12, -12, 12, -12 } }
};
sprite_patterns_title ufo_tbl = {
  4,
  {
    { 9, &ufo_spr00 },
    { 9, &ufo_spr01 },
    { 9, &ufo_spr00 },
    { 9, &ufo_spr02 }
  }
};
sprite_patterns_title ufo_tbl1 = {
  1,
  { { 0, &ufo_spr01 } }
};
sprite_patterns_title ufo_tbl2 = {
  1,
  { { 0, &ufo_spr02 } }
};
sprite_pattern_mappings_title eggm_spr00 = {
  1,
  { { 1, 0, 20, 28, 20, 20 } }
};
sprite_pattern_mappings_title eggm_spr01 = {
  2,
  {
    { 2, 0, 20, 28, 20, 20 },
    { 3, 0, -9, 37, -3, -3 }
  }
};
sprite_pattern_mappings_title eggm_spr02 = {
  2,
  {
    { 4, 0, 20, 28, 20, 20 },
    { 5, 0, -9, 37, -3, -3 }
  }
};
sprite_pattern_mappings_title eggm_spr03 = {
  2,
  {
    { 6, 0, 20, 28, 20, 20 },
    { 7, 0, -9, 37, -3, -3 }
  }
};
sprite_pattern_mappings_title eggm_spr04 = {
  2,
  {
    { 8, 0, 20, 28, 20, 20 },
    { 9, 0, -9, 37, -3, -3 }
  }
};
sprite_patterns_title eggm_tbl = {
  8,
  {
    { 1, &eggm_spr01},
    { 1, &eggm_spr00},
    { 1, &eggm_spr02},
    { 1, &eggm_spr00},
    { 1, &eggm_spr03},
    { 1, &eggm_spr00},
    { 1, &eggm_spr04},
    { 1, &eggm_spr00}
  }
};
sprite_pattern_mappings_title eggm2_spr00 = {
  1,
  { { 10, 0, 20, 28, 20, 20 } }
};
sprite_pattern_mappings_title eggm2_spr01 = {
  2,
  {
    { 11, 0, 20, 28, 20, 20 },
    { 12, 0, -9, 37, -3, -3 }
  }
};
sprite_pattern_mappings_title eggm2_spr02 = {
  2,
  {
    { 13, 0, 20, 28, 20, 20 },
    { 14, 0, -9, 37, -3, -3 }
  }
};
sprite_pattern_mappings_title eggm2_spr03 = {
  2,
  {
    { 15, 0, 20, 28, 20, 20 },
    { 16, 0, -9, 37, -3, -3 }
  }
};
sprite_pattern_mappings_title eggm2_spr04 = {
  2,
  {
    { 17, 0, 20, 28, 20, 20 },
    { 18, 0, -9, 37, -3, -3 }
  }
};
sprite_patterns_title eggm_tbl2 = {
  8,
  {
    { 1, &eggm2_spr01 },
    { 1, &eggm2_spr00 },
    { 1, &eggm2_spr02 },
    { 1, &eggm2_spr00 },
    { 1, &eggm2_spr03 },
    { 1, &eggm2_spr00 },
    { 1, &eggm2_spr04 },
    { 1, &eggm2_spr00 }
  }
};
sprite_pattern_mappings_title msnc_spr00 = {
  2,
  {
    { 21, 0, 16, 16, 24, -8 },
    { 22, 0, 28, -5, 12, -12 }
  }
};
sprite_pattern_mappings_title msnc_spr01 = {
  2,
  {
    { 23, 0, 16, 16, 24, -8 },
    { 24, 0, 28, -5, 12, -12 }
  }
};
sprite_pattern_mappings_title msnc_spr02 = {
  1,
  { { 25, 0, 16, 16, 24, -8 } }
};
sprite_patterns_title msnc_tbl = {
  3,
  {
    { 1, &msnc_spr00 },
    { 1, &msnc_spr01 },
    { 2, &msnc_spr02 }
  }
};
sprite_patterns_title msnc_tbl2 = {
  3,
  {
    { 1, &msnc_spr00 },
    { 1, &msnc_spr01 },
    { 1, &msnc_spr02 }
  }
};
sprite_pattern_mappings_title tails_spr00 = {
  1,
  { { 32, 0, -20, 28, 16, 6 } }
};
sprite_pattern_mappings_title tails_spr01 = {
  1,
  { { 33, 0, -20, 28, 16, 6 } }
};
sprite_pattern_mappings_title tails_spr02 = {
  1,
  { { 34, 0, -20, 28, 16, 6 } }
};
sprite_patterns_title tails_tbl = {
  3,
  {
    { 1, &tails_spr00 },
    { 1, &tails_spr01 },
    { 1, &tails_spr02 }
  }
};
sprite_pattern_mappings_title tails_up_spr00 = {
  1,
  { { 35, 0, -20, 28, 16, 6 } }
};
sprite_pattern_mappings_title tails_up_spr01 = {
  1,
  { { 36, 0, -20, 28, 16, 6 } }
};
sprite_pattern_mappings_title tails_up_spr02 = {
  1,
  { { 37, 0, -20, 28, 16, 6 } }
};
sprite_patterns_title tails_up_tbl = {
  3,
  {
    { 1, &tails_up_spr00 },
    { 1, &tails_up_spr01 },
    { 1, &tails_up_spr02 }
  }
};
sprite_pattern_mappings_title tails_down_spr00 = {
  1,
  { { 38, 0, -20, 28, 16, 6 } }
};
sprite_pattern_mappings_title tails_down_spr01 = {
  1,
  { { 39, 0, -20, 28, 16, 6 } }
};
sprite_pattern_mappings_title tails_down_spr02 = {
  1,
  { { 40, 0, -20, 28, 16, 6 } }
};
sprite_patterns_title tails_down_tbl = {
  3,
  {
    { 1, &tails_down_spr00 },
    { 1, &tails_down_spr01 },
    { 1, &tails_down_spr02 }
  }
};
short ascii_xposi_tbl[78] = {
  0, 111,
  0, 92,
  1, 92,
  2, 92,
  0, 107,
  0, 88,
  1, 88,
  2, 88,
  0, 114,
  0, 96,
  1, 96,
  2, 96,
  0, 107,
  0, 88,
  1, 88,
  2, 88,
  0, 106,
  0, 87,
  1, 87,
  2, 87,
  0, 100,
  0, 81,
  1, 81,
  2, 81,
  0, 105,
  0, 83,
  1, 83,
  2, 83,
  0, 122,
  0, 114,
  0, 128,
  0, 124,
  0, 148,
  0, 123,
  0, 130,
  0, 143,
  0, 119,
  0, 75,
  0, 44
};
sprite_pattern_mappings_title sprmapBOSS = {
  1,
  { { 44, 0, 0, 0, 0, 0 } }
};
sprite_patterns_title spr_BOSS = {
  1,
  { { 1, &sprmapBOSS } }
};
sprite_pattern_mappings_title sprmapCC = {
  1,
  { { 45, 0, 0, 0, 0, 0 } }
};
sprite_patterns_title spr_CC = {
  1,
  { { 1, &sprmapCC } }
};
sprite_pattern_mappings_title sprmapCCB = {
  2,
  {
    { 46, 0, 0, 0, 0, 0 },
    { 47, 0, -128, 0, 0, 0 }
  }
};
sprite_patterns_title spr_CCB = {
  1,
  { { 1, &sprmapCCB } }
};
sprite_pattern_mappings_title sprmapCCG = {
  2,
  {
    { 48, 0, 0, 0, 0, 0 },
    { 49, 0, -128, 0, 0, 0 }
  }
};
sprite_patterns_title spr_CCG = {
  1,
  { { 1, &sprmapCCG } }
};
sprite_pattern_mappings_title sprmapCCP = {
  1,
  { { 50, 0, 0, 0, 0, 0 } }
};
sprite_patterns_title spr_CCP = {
  1,
  { { 1, &sprmapCCP } }
};
sprite_pattern_mappings_title sprmapFINAL = {
  1,
  { { 53, 0, 0, 0, 0, 0 } }
};
sprite_patterns_title spr_FINAL = {
  1,
  { { 1, &sprmapFINAL } }
};
sprite_pattern_mappings_title sprmapGAMEOVER = {
  1,
  { { 54, 0, 0, 0, 0, 0 } }
};
sprite_patterns_title spr_GAMEOVER = {
  1,
  { { 1, &sprmapGAMEOVER } }
};
sprite_pattern_mappings_title sprmapINV = {
  1,
  { { 55, 0, 0, 0, 0, 0 } }
};
sprite_patterns_title spr_INV = {
  1,
  { { 1, &sprmapINV } }
};
sprite_pattern_mappings_title sprmapLITTLE = {
  1,
  { { 56, 0, 0, 0, 0, 0 } }
};
sprite_patterns_title spr_LITTLE = {
  1,
  { { 1, &sprmapLITTLE } }
};
sprite_pattern_mappings_title sprmapMM = {
  1,
  { { 57, 0, 0, 0, 0, 0 } }
};
sprite_patterns_title spr_MM = {
  1,
  { { 1, &sprmapMM } }
};
sprite_pattern_mappings_title sprmapMMB = {
  2,
  {
    { 58, 0, 0, 0, 0, 0 },
    { 59, 0, -128, 0, 0, 0 }
  }
};
sprite_patterns_title spr_MMB = {
  1,
  { { 1, &sprmapMMB } }
};
sprite_pattern_mappings_title sprmapMMG = {
  2,
  {
    { 60, 0, 0, 0, 0, 0 },
    { 61, 0, -128, 0, 0, 0 }
  }
};
sprite_patterns_title spr_MMG = {
  1,
  { { 1, &sprmapMMG  } }
};
sprite_pattern_mappings_title sprmapMMP = {
  1,
  { { 62, 0, 0, 0, 0, 0 } }
};
sprite_patterns_title spr_MMP = {
  1,
  { { 1, &sprmapMMP } }
};
sprite_pattern_mappings_title sprmapPP = {
  1,
  { { 63, 0, 0, 0, 0, 0 } }
};
sprite_patterns_title spr_PP = {
  1,
  { { 1, &sprmapPP } }
};
sprite_pattern_mappings_title sprmapPPB = {
  2,
  {
    { 64, 0, 0, 0, 0, 0 },
    { 65, 0, -128, 0, 0, 0 }
  }
};
sprite_patterns_title spr_PPB = {
  1,
  { { 1, &sprmapPPB } }
};
sprite_pattern_mappings_title sprmapPPG = {
  2,
  {
    { 66, 0, 0, 0, 0, 0 },
    { 67, 0, -128, 0, 0, 0 }
  }
};
sprite_patterns_title spr_PPG = {
  1,
  { { 1, &sprmapPPG } }
};
sprite_pattern_mappings_title sprmapPPP = {
  1,
  { { 68, 0, 0, 0, 0, 0 } }
};
sprite_patterns_title spr_PPP = {
  1,
  { { 1, &sprmapPPP } }
};
sprite_pattern_mappings_title sprmapQQ = {
  1,
  { { 69, 0, 0, 0, 0, 0 } }
};
sprite_patterns_title spr_QQ = {
  1,
  { { 1, &sprmapQQ } }
};
sprite_pattern_mappings_title sprmapQQB = {
  2,
  {
    { 70, 0, 0, 0, 0, 0 },
    { 71, 0, -128, 0, 0, 0 }
  }
};
sprite_patterns_title spr_QQB = {
  1,
  { { 1, &sprmapQQB } }
};
sprite_pattern_mappings_title sprmapQQG = {
  2,
  {
    { 72, 0, 0, 0, 0, 0 },
    { 73, 0, -128, 0, 0, 0 }
  }
};
sprite_patterns_title spr_QQG = {
  1,
  { { 1, &sprmapQQG } }
};
sprite_pattern_mappings_title sprmapQQP = {
  1,
  { { 74, 0, 0, 0, 0, 0 } }
};
sprite_patterns_title spr_QQP = {
  1,
  { { 1, &sprmapQQP } }
};
sprite_pattern_mappings_title sprmapSPECIAL = {
  1,
  { { 75, 0, 0, 0, 0, 0 } }
};
sprite_patterns_title spr_SPECIAL = {
  1,
  { { 1, &sprmapSPECIAL } }
};
sprite_pattern_mappings_title sprmapSPEED = {
  1,
  { { 76, 0, 0, 0, 0, 0 } }
};
sprite_patterns_title spr_SPEED = {
  1,
  { { 1, &sprmapSPEED } }
};
sprite_pattern_mappings_title sprmapSS = {
  1,
  { { 77, 0, 0, 0, 0, 0 } }
};
sprite_patterns_title spr_SS = {
  1,
  { { 1, &sprmapSS } }
};
sprite_pattern_mappings_title sprmapSSB = {
  2,
  {
    { 78, 0, 0, 0, 0, 0 },
    { 79, 0, -128, 0, 0, 0 }
  }
};
sprite_patterns_title spr_SSB = {
  1,
  { { 1, &sprmapSSB } }
};
sprite_pattern_mappings_title sprmapSSG = {
  2,
  {
    { 80, 0, 0, 0, 0, 0 },
    { 81, 0, -128, 0, 0, 0 }
  }
};
sprite_patterns_title spr_SSG = {
  1,
  { { 1, &sprmapSSG } }
};
sprite_pattern_mappings_title sprmapSSP = {
  1,
  { { 82, 0, 0, 0, 0, 0 } }
};
sprite_patterns_title spr_SSP = {
  1,
  { { 1, &sprmapSSP } }
};
sprite_pattern_mappings_title sprmapTITLE = {
  1,
  { { 83, 0, 0, 0, 0, 0 } }
};
sprite_patterns_title spr_TITLE = {
  1,
  { { 1, &sprmapTITLE } }
};
sprite_pattern_mappings_title sprmapTT = {
  1,
  { { 84, 0, 0, 0, 0, 0 } }
};
sprite_patterns_title spr_TT = {
  1,
  { { 1, &sprmapTT } }
};
sprite_pattern_mappings_title sprmapTTB = {
  2,
  {
    { 85, 0, 0, 0, 0, 0 },
    { 86, 0, -128, 0, 0, 0 }
  }
};
sprite_patterns_title spr_TTB = {
  1,
  { { 1, &sprmapTTB } }
};
sprite_pattern_mappings_title sprmapTTG = {
  2,
  {
    { 87, 0, 0, 0, 0, 0 },
    { 88, 0, -128, 0, 0, 0 }
  }
};
sprite_patterns_title spr_TTG = {
  1,
  { { 1, &sprmapTTG } }
};
sprite_pattern_mappings_title sprmapTTP = {
  1,
  { { 89, 0, 0, 0, 0, 0 } }
};
sprite_patterns_title spr_TTP = {
  1,
  { { 1, &sprmapTTP } }
};
sprite_pattern_mappings_title sprmapWW = {
  1,
  { { 90, 0, 0, 0, 0, 0 } }
};
sprite_patterns_title spr_WW = {
  1,
  { { 1, &sprmapWW } }
};
sprite_pattern_mappings_title sprmapWWB = {
  2,
  {
    { 91, 0, 0, 0, 0, 0 },
    { 92, 0, -128, 0, 0, 0 }
  }
};
sprite_patterns_title spr_WWB = {
  1,
  { { 1, &sprmapWWB } }
};
sprite_pattern_mappings_title sprmapWWG = {
  2,
  {
    { 93, 0, 0, 0, 0, 0 },
    { 94, 0, -128, 0, 0, 0 }
  }
};
sprite_patterns_title spr_WWG = {
  1,
  { { 1, &sprmapWWG } }
};
sprite_pattern_mappings_title sprmapWWP = {
  1,
  { { 95, 0, 0, 0, 0, 0 } }
};
sprite_patterns_title spr_WWP = {
  1,
  { { 1, &sprmapWWP } }
};
sprite_pattern_mappings_title sprmapZONE = {
  1,
  { { 98, 0, 0, 0, 0, 0 } }
};
sprite_patterns_title spr_ZONE = {
  1,
  { { 1, &sprmapZONE } }
};
sprite_pattern_mappings_title sprmapYOUCAN = {
  2,
  {
    { 96, 0, 0, 0, 0, 0 },
    { 97, 0, -128, 0, 0, 0 }
  }
};
sprite_patterns_title spr_YOUCAN = {
  1,
  { { 1, &sprmapYOUCAN } }
};
sprite_pattern_mappings_title sprmapCOSMIC = {
  2,
  {
    { 51, 0, 0, 0, 0, 0 },
    { 52, 0, -128, 0, 0, 0 }
  }
};
sprite_patterns_title spr_COSMIC = {
  1,
  { { 1, &sprmapCOSMIC } }
};
sprite_patterns_title* asciispr_tbl[39] = {
  &spr_PP,
  &spr_PPP,
  &spr_PPG,
  &spr_PPB,
  &spr_CC,
  &spr_CCP,
  &spr_CCG,
  &spr_CCB,
  &spr_TT,
  &spr_TTP,
  &spr_TTG,
  &spr_TTB,
  &spr_QQ,
  &spr_QQP,
  &spr_QQG,
  &spr_QQB,
  &spr_WW,
  &spr_WWP,
  &spr_WWG,
  &spr_WWB,
  &spr_SS,
  &spr_SSP,
  &spr_SSG,
  &spr_SSB,
  &spr_MM,
  &spr_MMP,
  &spr_MMG,
  &spr_MMB,
  &spr_FINAL,
  &spr_LITTLE,
  &spr_GAMEOVER,
  &spr_ZONE,
  &spr_BOSS,
  &spr_INV,
  &spr_SPEED,
  &spr_TITLE,
  &spr_SPECIAL,
  &spr_YOUCAN,
  &spr_COSMIC
};
