#include "..\..\TYPES.H"
#include "THANKS_TYPES.H"

sprite_pattern_mappings_title s_stand1_spr00 = {
  1,
  { { 1, 0, 0, 0, 0, 0 } }
};
sprite_patterns_title s_stand1_map = {
  1,
  { { 1, &s_stand1_spr00 } }
};
sprite_pattern_mappings_title s_stand2_spr00 = {
  1,
  { { 2, 0, 0, -8, 0, 0 } }
};
sprite_patterns_title s_stand2_map = {
  1,
  { { 1, &s_stand2_spr00 } }
};
sprite_pattern_mappings_title s_wait_spr00 = {
  1,
  { { 3, 0, 0, 0, 0, 0 } }
};
sprite_pattern_mappings_title s_wait_spr01 = {
  1,
  { { 4, 0, 0, 0, 0, 0 } }
};
sprite_patterns_title s_wait_map = {
  2,
  {
    { 10, &s_wait_spr00 },
    { 10, &s_wait_spr01 }
  }
};
sprite_pattern_mappings_title s_run_spr00 = {
  1,
  { { 5, 0, 0, 16, 0, 0 } }
};
sprite_pattern_mappings_title s_run_spr01 = {
  1,
  { { 6, 0, 0, 16, 0, 0 } }
};
sprite_pattern_mappings_title s_run_spr02 = {
  1,
  { { 7, 0, 0, 16, 0, 0 } }
};
sprite_pattern_mappings_title s_run_spr03 = {
  1,
  { { 8, 0, 0, 16, 0, 0 } }
};
sprite_pattern_mappings_title s_run_spr04 = {
  1,
  { { 9, 0, 0, 16, 0, 0 } }
};
sprite_pattern_mappings_title s_run_spr05 = {
  1,
  { { 10, 0, 0, 16, 0, 0 } }
};
sprite_patterns_title s_run_map = {
  6,
  {
    { 3, &s_run_spr00 },
    { 3, &s_run_spr01 },
    { 3, &s_run_spr02 },
    { 3, &s_run_spr03 },
    { 3, &s_run_spr04 },
    { 3, &s_run_spr05 }
  }
};
sprite_pattern_mappings_title s_stop_spr00 = {
  1,
  { { 11, 0, 0, 0, 0, 0 } }
};
sprite_pattern_mappings_title s_stop_spr01 = {
  1,
  { { 12, 0, 0, 0, 0, 0 } }
};
sprite_pattern_mappings_title s_stop_spr02 = {
  1,
  { { 13, 0, 0, 0, 0, 0 } }
};
sprite_pattern_mappings_title s_stop_spr03 = {
  1,
  { { 14, 0, 0, 0, 0, 0 } }
};
sprite_patterns_title s_stop_map = {
  6,
  {
    { 5, &s_stop_spr00 },
    { 5, &s_stop_spr01 },
    { 5, &s_stop_spr02 },
    { 5, &s_stop_spr01 },
    { 5, &s_stop_spr03 },
    { 3, &s_stop_spr03 }
  }
};
sprite_pattern_mappings_title s_ball_spr00 = {
  1,
  { { 15, 0, 0, 0, 0, 0 } }
};
sprite_pattern_mappings_title s_ball_spr01 = {
  1,
  { { 16, 0, 0, 0, 0, 0 } }
};
sprite_pattern_mappings_title s_ball_spr02 = {
  1,
  { { 17, 0, 0, 0, 0, 0 } }
};
sprite_pattern_mappings_title s_ball_spr03 = {
  1,
  { { 18, 0, 0, 0, 0, 0 } }
};
sprite_pattern_mappings_title s_ball_spr04 = {
  1,
  { { 19, 0, 0, 0, 0, 0 } }
};
sprite_patterns_title s_ball_map = {
  5,
  {
    { 2, &s_ball_spr00 },
    { 2, &s_ball_spr01 },
    { 2, &s_ball_spr02 },
    { 2, &s_ball_spr03 },
    { 2, &s_ball_spr04 }
  }
};
sprite_pattern_mappings_title erun_spr00 = {
  1,
  { { 20, 0, 0, 0, 0, 0 } }
};
sprite_pattern_mappings_title erun_spr01 = {
  1,
  { { 21, 0, 0, 0, 0, 0 } }
};
sprite_pattern_mappings_title erun_spr02 = {
  1,
  { { 22, 0, 0, 0, 0, 0 } }
};
sprite_pattern_mappings_title erun_spr03 = {
  1,
  { { 23, 0, 0, 0, 0, 0 } }
};
sprite_pattern_mappings_title erun_spr04 = {
  1,
  { { 24, 0, 0, 0, 0, 0 } }
};
sprite_pattern_mappings_title erun_spr05 = {
  1,
  { { 25, 0, 0, 0, 0, 0 } }
};
sprite_patterns_title erun_map = {
  6,
  {
    { 4, &erun_spr00 },
    { 4, &erun_spr01 },
    { 4, &erun_spr02 },
    { 4, &erun_spr03 },
    { 4, &erun_spr04 },
    { 4, &erun_spr05 }
  }
};
sprite_pattern_mappings_title estand_spr00 = {
  1,
  { { 26, 0, 0, 0, 0, 0 } }
};
sprite_pattern_mappings_title estand_spr01 = {
  1,
  { { 27, 0, 0, 0, 0, 0 } }
};
sprite_pattern_mappings_title estand_spr02 = {
  1,
  { { 28, 0, 0, 0, 0, 0 } }
};
sprite_patterns_title estand_map = {
  4,
  {
    { 6, &estand_spr00 },
    { 6, &estand_spr01 },
    { 6, &estand_spr02 },
    { 6, &estand_spr01 }
  }
};
sprite_pattern_mappings_title estand2_spr00 = {
  1,
  { { 29, 0, 0, 0, 0, 0 } }
};
sprite_pattern_mappings_title estand2_spr01 = {
  1,
  { { 30, 0, 0, 0, 0, 0 } }
};
sprite_pattern_mappings_title estand2_spr02 = {
  1,
  { { 31, 0, 0, 0, 0, 0 } }
};
sprite_patterns_title estand2_map = {
  8,
  {
    { 14, &estand2_spr00 },
    { 14, &estand2_spr01 },
    { 14, &estand2_spr00 },
    { 20, &estand2_spr01 },
    { 6, &estand2_spr02 },
    { 6, &estand2_spr01 },
    { 6, &estand2_spr02 },
    { 6, &estand2_spr01 }
  }
};
sprite_pattern_mappings_title ejump_spr00 = {
  1,
  { { 32, 0, 0, 0, 0, 0 } }
};
sprite_patterns_title ejump_map = {
  1,
  { { 10, &ejump_spr00 } }
};
sprite_pattern_mappings_title ekiss_spr00 = {
  1,
  { { 33, 0, 0, 0, 0, 0 } }
};
sprite_pattern_mappings_title ekiss_spr01 = {
  1,
  { { 34, 0, 0, 0, 0, 0 } }
};
sprite_pattern_mappings_title ekiss_spr02 = {
  1,
  { { 35, 0, 0, 0, 0, 0 } }
};
sprite_patterns_title ekiss_map = {
  4,
  {
    { 10, &ekiss_spr01 },
    { 10, &ekiss_spr00 },
    { 10, &ekiss_spr02 },
    { 10, &ekiss_spr00 }
  }
};
sprite_pattern_mappings_title ecatch_spr00 = {
  1,
  { { 36, 0, 0, 0, 0, 0 } }
};
sprite_pattern_mappings_title ecatch_spr01 = {
  1,
  { { 37, 0, 0, 0, 0, 0 } }
};
sprite_patterns_title ecatch_map = {
  2,
  {
    { 10, &ecatch_spr00 },
    { 10, &ecatch_spr01 }
  }
};
sprite_pattern_mappings_title eheart_spr00 = {
  1,
  { { 38, 0, 0, 0, 0, 0 } }
};
sprite_pattern_mappings_title eheart_spr01 = {
  1,
  { { 39, 0, 0, 0, 0, 0 } }
};
sprite_pattern_mappings_title eheart_spr02 = {
  1,
  { { 40, 0, 0, 0, 0, 0 } }
};
sprite_patterns_title eheart_map = {
  4,
  {
    { 40, &eheart_spr00 },
    { 20, &eheart_spr01 },
    { 20, &eheart_spr02 },
    { 10, &eheart_spr02 }
  }
};
sprite_pattern_mappings_title m_stand_spr00 = {
  1,
  { { 41, 0, 0, 0, 0, 0 } }
};
sprite_patterns_title m_stand_map = {
  1,
  { { 2, &m_stand_spr00 } }
};
sprite_pattern_mappings_title m_era_spr00 = {
  1,
  { { 42, 0, 0, 0, 0, 0 } }
};
sprite_pattern_mappings_title m_era_spr01 = {
  1,
  { { 43, 0, 0, 0, 0, 0 } }
};
sprite_patterns_title m_era_map = {
  2,
  {
    { 40, &m_era_spr00 },
    { 20, &m_era_spr01 }
  }
};
sprite_pattern_mappings_title m_era2_spr00 = {
  1,
  { { 44, 0, 0, 0, 0, 0 } }
};
sprite_pattern_mappings_title m_era2_spr01 = {
  1,
  { { 45, 0, 0, 0, 0, 0 } }
};
sprite_patterns_title m_era2_map = {
  2,
  {
    { 20, &m_era2_spr00 },
    { 20, &m_era2_spr01 }
  }
};
sprite_pattern_mappings_title m_fly1_spr00 = {
  1,
  {
    { 46, 0, 0, 0, 0, 0 },
    { 47, 0, 4, -12, -12, 0 }
  }
};
sprite_pattern_mappings_title m_fly1_spr01 = {
  1,
  {
    { 48, 0, 0, 0, 0, 0 },
    { 49, 0, 12, -12, -8, 0 }
  }
};
sprite_patterns_title m_fly1_map = {
  2,
  {
    { 2, &m_fly1_spr00 },
    { 2, &m_fly1_spr01 }
  }
};
sprite_pattern_mappings_title m_brake_spr00 = {
  2,
  {
    { 50, 0, 0, 0, 0, 0 },
    { 51, 0, -20, 4, -16, 0 }
  }
};
sprite_pattern_mappings_title m_brake_spr01 = {
  1,
  { { 52, 0, 0, 0, 0, 0 } }
};
sprite_patterns_title m_brake_map = {
  2,
  {
    { 2, &m_brake_spr00 },
    { 2, &m_brake_spr01 }
  }
};
sprite_pattern_mappings_title m_stop_spr00 = {
  1,
  { { 53, 0, 0, 0, 0, 0 } }
};
sprite_pattern_mappings_title m_stop_spr01 = {
  1,
  { { 54, 0, 0, 0, 0, 0 } }
};
sprite_patterns_title m_stop_map = {
  2,
  {
    { 20, &m_stop_spr00 },
    { 20, &m_stop_spr01 }
  }
};
sprite_pattern_mappings_title m_furi_spr00 = {
  1,
  { { 55, 0, 0, 0, 0, 0 } }
};
sprite_pattern_mappings_title m_furi_spr01 = {
  1,
  { { 56, 0, 0, 0, 0, 0 } }
};
sprite_patterns_title m_furi_map = {
  2,
  {
    { 40, &m_furi_spr00 },
    { 40, &m_furi_spr01 }
  }
};
sprite_pattern_mappings_title m_kamae_spr00 = {
  2,
  {
    { 57, 0, 0, 0, 0, 0 },
    { 58, 0, -4, -18, -20, 0 }
  }
};
sprite_pattern_mappings_title m_kamae_spr01 = {
  2,
  {
    { 59, 0, 0, 0, 0, 0 },
    { 60, 0, 2, -16, -16 ,0 }
  }
};
sprite_patterns_title m_kamae_map = {
  2,
  {
    { 2, &m_kamae_spr00 },
    { 2, &m_kamae_spr01 }
  }
};
sprite_pattern_mappings_title flick_spr00 = {
  1,
  { { 61, 0, 0, 0, 0, 0 } }
};
sprite_pattern_mappings_title flick_spr01 = {
  1,
  { { 62, 0, 0, 0, 0, 0 } }
};
sprite_patterns_title flick_map = {
  2,
  {
    { 4, &flick_spr00 },
    { 4, &flick_spr01 }
  }
};
sprite_pattern_mappings_title hato_spr00 = {
  1,
  { { 63, 0, 0, 0, 0, 0 } }
};
sprite_pattern_mappings_title hato_spr01 = {
  1,
  { { 64, 0, 0, 0, 0, 0 } }
};
sprite_patterns_title hato_map = {
  2,
  {
    { 4, &hato_spr00 },
    { 4, &hato_spr01 }
  }
};
sprite_pattern_mappings_title inco_spr00 = {
  1,
  { { 65, 0, 0, 0, 0, 0 } }
};
sprite_pattern_mappings_title inco_spr01 = {
  1,
  { { 66, 0, 0, 0, 0, 0 } }
};
sprite_patterns_title inco_map = {
  2,
  {
    { 4, &inco_spr00 },
    { 4, &inco_spr01 }
  }
};
sprite_pattern_mappings_title pocky_spr00 = {
  1,
  { { 67, 0, 0, 0, 0, 0 } }
};
sprite_pattern_mappings_title pocky_spr01 = {
  1,
  { { 68, 0, 0, 0, 0, 0 } }
};
sprite_patterns_title pocky_map = {
  2,
  {
    { 12, &pocky_spr00 },
    { 12, &pocky_spr01 }
  }
};
sprite_pattern_mappings_title ricky_spr00 = {
  1,
  { { 69, 0, 0, 0, 0, 0 } }
};
sprite_pattern_mappings_title ricky_spr01 = {
  1,
  { { 70, 0, 0, 0, 0, 0 } }
};
sprite_patterns_title ricky_map = {
  2,
  {
    { 6, &ricky_spr00 },
    { 6, &ricky_spr01 }
  }
};
sprite_pattern_mappings_title sheep_spr00 = {
  1,
  { { 71, 0, 0, 0, 0, 0 } }
};
sprite_pattern_mappings_title sheep_spr01 = {
  1,
  { { 72, 0, 0, 0, 0, 0 } }
};
sprite_patterns_title sheep_map = {
  2,
  {
    { 6, &sheep_spr00 },
    { 6, &sheep_spr01 }
  }
};
sprite_pattern_mappings_title pecky_spr00 = {
  1,
  { { 73, 0, 0, 0, 0, 0 } }
};
sprite_pattern_mappings_title pecky_spr01 = {
  1,
  { { 74, 0, 0, 0, 0, 0 } }
};
sprite_patterns_title pecky_map = {
  2,
  {
    { 12, &pecky_spr00 },
    { 12, &pecky_spr01 }
  }
};
PALETTEENTRY lpgoodA[24] = {
  {   0,   0,   0, 1 }, {  96, 128, 224, 1 }, { 128, 160, 224, 1 }, { 160, 192, 224, 1 },
  { 192, 192, 224, 1 }, {  64,  96, 224, 1 }, {  64,  96, 224, 1 }, {  64,  96, 224, 1 },
  {  64,  96, 224, 1 }, { 192, 192, 224, 1 }, { 192, 192, 224, 1 }, { 192, 192, 224, 1 },
  { 192, 192, 224, 1 }, {  64,  96, 224, 1 }, { 240, 240, 240, 1 }, { 240, 240, 240, 1 },
  {   0,   0,   0, 1 }, {  96,  96, 192, 1 }, { 128, 128, 224, 1 }, { 192, 192, 224, 1 },
  { 224, 224, 224, 1 }, { 160,  32,  32, 1 }, { 128,   0,   0, 1 }, {  64,   0,   0, 1 }
};
PALETTEENTRY lpgoodB[24] = {
  {   0,   0,   0, 1 }, {  96,  96, 224, 1 }, { 128, 128, 224, 1 }, { 160, 160, 224, 1 },
  { 192, 160, 224, 1 }, {  64,  64, 224, 1 }, {  64,  64, 224, 1 }, {  64,  64, 224, 1 },
  {  64,  64, 224, 1 }, { 224, 160, 224, 1 }, { 192, 160, 224, 1 }, { 192, 160, 224, 1 },
  { 192, 160, 224, 1 }, {  64,  64, 224, 1 }, { 240, 240, 240, 1 }, { 240, 240, 240, 1 },
  {   0,   0,   0, 1 }, {  96,  96, 192, 1 }, { 128, 128, 224, 1 }, { 192, 192, 224, 1 },
  { 224, 224, 224, 1 }, { 160,  32,  32, 1 }, { 128,   0,   0, 1 }, {  64,   0,   0, 1 }
};
PALETTEENTRY lpgoodC[24] = {
  {   0,   0,   0, 1 }, {  96,  64, 224, 1 }, { 128,  96, 224, 1 }, { 160, 128, 224, 1 },
  { 192, 128, 224, 1 }, {  64,  32, 224, 1 }, {  64,  32, 224, 1 }, {  64,  32, 224, 1 },
  {  64,  32, 224, 1 }, { 192, 128, 224, 1 }, { 192, 128, 224, 1 }, { 192, 128, 224, 1 },
  { 192, 128, 224, 1 }, {  64,  32, 224, 1 }, { 240, 240, 240, 1 }, { 240, 240, 240, 1 },
  {   0,   0,   0, 1 }, {  96,  96, 192, 1 }, { 128, 128, 224, 1 }, { 192, 192, 224, 1 },
  { 224, 224, 224, 1 }, { 160,  32,  32, 1 }, { 128,   0,   0, 1 }, {  64,   0,   0, 1 }
};
PALETTEENTRY lpgoodD[24] = {
  {   0,   0,   0, 1 }, {  96,  32, 224, 1 }, { 128,  64, 224, 1 }, { 160,  96, 224, 1 },
  { 192,  96, 224, 1 }, {  64,   0, 224, 1 }, {  64,   0, 224, 1 }, {  64,   0, 224, 1 },
  {  64,   0, 224, 1 }, { 192,  96, 224, 1 }, { 192,  96, 224, 1 }, { 192,  96, 224, 1 },
  { 192,  96, 224, 1 }, {  64,   0, 224, 1 }, { 240, 240, 240, 1 }, { 240, 240, 240, 1 },
  {   0,   0,   0, 1 }, {  96,  96, 192, 1 }, { 128, 128, 224, 1 }, { 192, 192, 224, 1 },
  { 224, 224, 224, 1 }, { 160,  32,  32, 1 }, { 128,   0,   0, 1 }, {  64,   0,   0, 1 }
};
PALETTEENTRY lpgoodE[24] = {
  {   0,   0,   0, 1 }, {  96,  32, 192, 1 }, { 128,  64, 192, 1 }, { 160,  96, 192, 1 },
  { 192,  96, 192, 1 }, {  64,   0, 192, 1 }, {  64,   0, 192, 1 }, {  64,   0, 192, 1 },
  {   0, 160, 224, 1 }, { 192,  96, 192, 1 }, { 192,  96, 192, 1 }, { 192,  96, 192, 1 },
  {   0, 160, 224, 1 }, {  64,   0, 192, 1 }, { 240, 240, 240, 1 }, { 240, 240, 240, 1 },
  {   0,   0,   0, 1 }, {  96,  96, 192, 1 }, { 128, 128, 224, 1 }, { 192, 192, 224, 1 },
  { 224, 224, 224, 1 }, { 160,  32,  32, 1 }, { 128,   0,   0, 1 }, {  64,   0,   0, 1 }
};
PALETTEENTRY lpgoodF[24] = {
  {   0,   0,   0, 1 }, {  96,   0, 192, 1 }, { 128,  64, 192, 1 }, { 160,  64, 192, 1 },
  { 192,  64, 192, 1 }, {  64,   0, 192, 1 }, {  64,   0, 192, 1 }, {  64,   0, 192, 1 },
  {   0, 160, 224, 1 }, { 192,  64, 192, 1 }, { 192,  64, 192, 1 }, { 192,  64, 192, 1 },
  {   0, 160, 224, 1 }, {  64,   0, 192, 1 }, { 240, 240, 240, 1 }, { 240, 240, 240, 1 },
  {   0,   0,   0, 1 }, {  96,  96, 192, 1 }, { 128, 128, 224, 1 }, { 192, 192, 224, 1 },
  { 224, 224, 224, 1 }, { 160,  32,  32, 1 }, { 128,   0,   0, 1 }, {  64,   0,   0, 1 }
};
PALETTEENTRY lpgoodG[24] = {
  {   0,   0,   0, 1 }, {  96,   0, 160, 1 }, { 128,   0, 160, 1 }, { 160,   0, 160, 1 },
  { 192,   0, 160, 1 }, {  64,   0, 160, 1 }, {  64,   0, 160, 1 }, {  64,   0, 160, 1 },
  {   0, 160, 224, 1 }, { 192,  32, 160, 1 }, { 192,  32, 160, 1 }, { 192,  32, 160, 1 },
  {   0, 160, 224, 1 }, {  64,   0, 160, 1 }, { 240, 240, 240, 1 }, { 240, 240, 240, 1 },
  {   0,   0,   0, 1 }, {  96,  96, 192, 1 }, { 128, 128, 224, 1 }, { 192, 192, 224, 1 },
  { 224, 224, 224, 1 }, { 160,  32,  32, 1 }, { 128,   0,   0, 1 }, {  64,   0,   0, 1 }
};
PALETTEENTRY lpgoodH[24] = {
  {   0,   0,   0, 1 }, {  96,   0, 128, 1 }, { 128,   0, 128, 1 }, { 160,   0, 128, 1 },
  { 192,   0, 128, 1 }, {  64,   0, 128, 1 }, {  64,   0, 128, 1 }, {   0,  64, 224, 1 },
  {   0, 160, 224, 1 }, { 192,   0, 128, 1 }, { 192,   0, 128, 1 }, {   0,  96, 224, 1 },
  {   0, 160, 224, 1 }, {  64,   0, 128, 1 }, { 240, 240, 240, 1 }, { 240, 240, 240, 1 },
  {   0,   0,   0, 1 }, {  96,  96, 192, 1 }, { 128, 128, 224, 1 }, { 192, 192, 224, 1 },
  { 224, 224, 224, 1 }, { 160,  32,  32, 1 }, { 128,   0,   0, 1 }, {  64,   0,   0, 1 }
};
PALETTEENTRY lpgoodI[24] = {
  {   0,   0,   0, 1 }, {  64,   0, 128, 1 }, {  96,   0, 128, 1 }, { 128,   0, 128, 1 },
  { 160,   0, 128, 1 }, {  32,   0, 128, 1 }, {  32,   0, 128, 1 }, {   0,  64, 224, 1 },
  {   0, 160, 224, 1 }, { 160,   0, 128, 1 }, { 160,   0, 128, 1 }, {   0,  96, 224, 1 },
  {   0, 160, 224, 1 }, {  32,   0, 128, 1 }, { 240, 240, 240, 1 }, { 240, 240, 240, 1 },
  {   0,   0,   0, 1 }, {  96,  96, 192, 1 }, { 128, 128, 224, 1 }, { 192, 192, 224, 1 },
  { 224, 224, 224, 1 }, { 160,  32,  32, 1 }, { 128,   0,   0, 1 }, {  64,   0,   0, 1 }
};
PALETTEENTRY lpgoodJ[24] = {
  {   0,   0,   0, 1 }, {  32,   0, 128, 1 }, {  64,   0, 128, 1 }, {  96,   0, 128, 1 },
  { 128,   0, 128, 1 }, {   0,   0, 128, 1 }, {   0,   0, 128, 1 }, {   0,  64, 224, 1 },
  {   0, 160, 224, 1 }, { 128,   0, 128, 1 }, { 128,   0, 128, 1 }, {   0,  96, 224, 1 },
  {   0, 160, 224, 1 }, {   0,   0, 128, 1 }, { 240, 240, 240, 1 }, { 240, 240, 240, 1 },
  {   0,   0,   0, 1 }, {  64,  64, 128, 1 }, {  96,  96, 192, 1 }, { 160, 160, 192, 1 },
  { 224, 224, 224, 1 }, { 160,  32,  32, 1 }, { 128,   0,   0, 1 }, {  64,   0,   0, 1 }
};
PALETTEENTRY lpgoodK[24] = {
  {   0,   0,   0, 1 }, {   0,   0, 128, 1 }, {  32,   0, 128, 1 }, {  64,   0, 128, 1 },
  {  96,   0, 128, 1 }, {   0,   0, 128, 1 }, {   0,  64, 224, 1 }, {   0, 160, 224, 1 },
  { 224, 224, 224, 1 }, {  96,   0, 128, 1 }, {   0,  96, 224, 1 }, {   0, 160, 224, 1 },
  { 224, 224, 224, 1 }, {   0,   0, 128, 1 }, { 240, 240, 240, 1 }, { 240, 240, 240, 1 },
  {   0,   0,   0, 1 }, {  64,  64, 128, 1 }, {  96,  96, 192, 1 }, { 160, 160, 192, 1 },
  { 224, 224, 224, 1 }, { 160,  32,  32, 1 }, { 128,   0,   0, 1 }, {  64,   0,   0, 1 }
};
PALETTEENTRY lpgoodL[24] = {
  {   0,   0,   0, 1 }, {   0,   0, 128, 1 }, {   0,   0, 128, 1 }, {  32,   0, 128, 1 },
  {  64,   0, 128, 1 }, {   0,   0, 128, 1 }, {   0,  64, 224, 1 }, {   0, 160, 224, 1 },
  { 224, 224, 224, 1 }, {   0,   0, 128, 1 }, {   0,  64, 224, 1 }, {   0, 160, 224, 1 },
  { 224, 224, 224, 1 }, {   0,   0, 128, 1 }, { 240, 240, 240, 1 }, { 240, 240, 240, 1 },
  {   0,   0,   0, 1 }, {  64,  64, 128, 1 }, {  96,  96, 192, 1 }, { 160, 160, 192, 1 },
  { 224, 224, 224, 1 }, { 160,  32,  32, 1 }, { 128,   0,   0, 1 }, {  64,   0,   0, 1 }
};
PALETTEENTRY lpgoodM[24] = {
  {   0,   0,   0, 1 }, {   0,   0, 128, 1 }, {   0,   0, 128, 1 }, {   0,   0, 128, 1 },
  {  32,   0, 128, 1 }, {   0,   0, 128, 1 }, {   0,  64, 224, 1 }, {   0, 160, 224, 1 },
  { 224, 224, 224, 1 }, {   0,   0, 128, 1 }, {   0,  64, 224, 1 }, {   0, 160, 224, 1 },
  { 224, 224, 224, 1 }, {   0,   0, 128, 1 }, { 240, 240, 240, 1 }, { 240, 240, 240, 1 },
  {   0,   0,   0, 1 }, {  64,  64, 128, 1 }, {  96,  96, 192, 1 }, { 160, 160, 192, 1 },
  { 224, 224, 224, 1 }, { 160,  32,  32, 1 }, { 128,   0,   0, 1 }, {  64,   0,   0, 1 }
};
PALETTEENTRY lpgoodN[24] = {
  {   0,   0,   0, 1 }, {   0,   0,  96, 1 }, {   0,   0,  96, 1 }, {   0,   0,  96, 1 },
  {   0,   0,  96, 1 }, {   0,   0, 128, 1 }, {   0,  64, 224, 1 }, {   0, 160, 224, 1 },
  { 224, 224, 224, 1 }, {   0,   0, 128, 1 }, {   0,  64, 224, 1 }, {   0, 160, 224, 1 },
  { 224, 224, 224, 1 }, {   0,   0,  96, 1 }, { 240, 240, 240, 1 }, { 240, 240, 240, 1 },
  {   0,   0,   0, 1 }, {  64,  64, 128, 1 }, {  96,  96, 192, 1 }, { 160, 160, 192, 1 },
  { 224, 224, 224, 1 }, { 160,  32,  32, 1 }, { 128,   0,   0, 1 }, {  64,   0,   0, 1 }
};
PALETTEENTRY lpgoodO[24] = {
  {   0,   0,   0, 1 }, {   0,   0,  64, 1 }, {   0,   0,  64, 1 }, {   0,   0,  64, 1 },
  {   0,   0,  64, 1 }, {   0,   0, 128, 1 }, {   0,  64, 224, 1 }, {   0, 160, 224, 1 },
  { 224, 224, 224, 1 }, {   0,   0, 128, 1 }, {   0,  64, 224, 1 }, {   0, 160, 224, 1 },
  { 224, 224, 224, 1 }, {   0,   0,  64, 1 }, { 240, 240, 240, 1 }, { 240, 240, 240, 1 },
  {   0,   0,   0, 1 }, {  64,  64, 128, 1 }, {  96,  96, 192, 1 }, { 160, 160, 192, 1 },
  { 224, 224, 224, 1 }, { 160,  32,  32, 1 }, { 128,   0,   0, 1 }, {  64,   0,   0, 1 }
};
PALETTEENTRY lpgoodP[24] = {
  {   0,   0,   0, 1 }, {   0,   0,  32, 1 }, {   0,   0,  32, 1 }, {   0,   0,  32, 1 },
  {   0,   0,  32, 1 }, {   0,   0, 128, 1 }, {   0,  64, 224, 1 }, {   0, 160, 224, 1 },
  { 224, 224, 224, 1 }, {   0,   0, 128, 1 }, {   0,  64, 224, 1 }, {   0, 160, 224, 1 },
  { 224, 224, 224, 1 }, {   0,   0,  32, 1 }, { 240, 240, 240, 1 }, { 240, 240, 240, 1 },
  {   0,   0,   0, 1 }, {  64,  64,  64, 1 }, {  96,  96,  96, 1 }, { 160, 160, 160, 1 },
  { 224, 224, 224, 1 }, { 160,  32,  32, 1 }, { 128,   0,   0, 1 }, {  64,   0,   0, 1 }
};
PALETTEENTRY lpgoodQ[24] = {
  {   0,   0,   0, 1 }, {   0,   0,   0, 1 }, {   0,   0,   0, 1 }, {   0,   0,   0, 1 },
  {   0,   0,   0, 1 }, {   0,   0, 128, 1 }, {   0,  64, 224, 1 }, {   0, 160, 224, 1 },
  { 224, 224, 224, 1 }, {   0,   0, 128, 1 }, {   0,  64, 224, 1 }, {   0, 160, 224, 1 },
  { 224, 224, 224, 1 }, {   0,   0,   0, 1 }, { 240, 240, 240, 1 }, { 240, 240, 240, 1 },
  {   0,   0,   0, 1 }, {  64,  64,  64, 1 }, {  96,  96,  96, 1 }, { 160, 160, 160, 1 },
  { 224, 224, 224, 1 }, { 160,  32,  32, 1 }, { 128,   0,   0, 1 }, {  64,   0,   0, 1 }
};
PALETTEENTRY* lpbs_good[32] = {
  lpgoodA,
  lpgoodB,
  lpgoodC,
  lpgoodD,
  lpgoodE,
  lpgoodF,
  lpgoodG,
  lpgoodH,
  lpgoodI,
  lpgoodJ,
  lpgoodK,
  lpgoodL,
  lpgoodM,
  lpgoodN,
  lpgoodO,
  lpgoodP,
  lpgoodQ,
  lpgoodP,
  lpgoodO,
  lpgoodN,
  lpgoodM,
  lpgoodL,
  lpgoodK,
  lpgoodJ,
  lpgoodI,
  lpgoodH,
  lpgoodG,
  lpgoodF,
  lpgoodE,
  lpgoodD,
  lpgoodC,
  lpgoodB
};
PALETTEENTRY asc_col00[8] = {
  {   0,   0,   0, 1 }, {  96,  96,   0, 1 }, { 160, 160,   0, 1 }, { 224, 224,   0, 1 },
  {   0,   0,   0, 1 }, {   0,   0,   0, 1 }, {   0,   0,   0, 1 }, {   0,   0,   0, 1 }
};
PALETTEENTRY asc_col01[8] = {
  {   0,   0,   0, 1 }, {  96,  96,  96, 1 }, { 160, 160, 160, 1 }, { 224, 224, 224, 1 },
  {   0,   0,   0, 1 }, {   0,   0,   0, 1 }, {   0,   0,   0, 1 }, {   0,   0,   0, 1 }
};
PALETTEENTRY* asc_coltbl[2] = {
  asc_col00,
  asc_col01
};
unsigned short lpbs_timer[32] = {
  780, 4, 6, 8,
  120, 6, 8,
  130, 6, 8,
  140, 6, 8,
  150, 6, 8,
  780, 4, 6, 8,
  120, 6, 8,
  130, 6, 8,
  140, 6, 8,
  150, 6, 8
};
static unsigned short _A[6] = { 0, 1, 2, 3, 4, 5 };
static unsigned short _E[6] = { 6, 7, 8, 7, 9, 10 };
static unsigned short _F[6] = { 6, 7, 8, 7, 11, 12 };
static unsigned short _B[6] = { 13, 14, 8, 15, 16, 17 };
static unsigned short _C[6] = { 18, 2066, 11, 19, 20, 2068 };
static unsigned short _D[6] = { 13, 21, 11, 2059, 16, 22 };
static unsigned short _G[6] = { 18, 2066, 11, 23, 24, 25 };
static unsigned short _H[6] = { 26, 2074, 27, 2075, 11, 2059 };
static unsigned short _I[6] = { 28, 29, 30, 31, 30, 31 };
static unsigned short _J[6] = { 12, 32, 12, 33, 34, 35 };
static unsigned short _K[6] = { 26, 36, 37, 38, 11, 39 };
static unsigned short _L[6] = { 2080, 12, 2081, 12, 2081, 40 };
static unsigned short _M[6] = { 41, 42, 43, 44, 45, 46 };
static unsigned short _N[6] = { 47, 2074, 48, 49, 50, 51 };
static unsigned short _O[6] = { 18, 2066, 11, 2059, 20, 2068 };
static unsigned short _P[6] = { 2080, 52, 2081, 53, 2081, 12 };
static unsigned short _Q[8] = { 18, 2066, 11, 2059, 20, 54 };
static unsigned short _R[6] = { 13, 56, 57, 58, 11, 2059 };
static unsigned short _S[6] = { 2104, 56, 59, 60, 61, 2109 };
static unsigned short _T[6] = { 62, 63, 30, 31, 30, 31 };
static unsigned short _U[6] = { 26, 2074, 11, 2059, 20, 2068 };
static unsigned short _V[6] = { 64, 65, 66, 67, 68, 69 };
static unsigned short _W[6] = { 70, 71, 72, 73, 74, 75 };
static unsigned short _X[6] = { 76, 77, 78, 79, 80, 81 };
static unsigned short _Y[6] = { 82, 83, 84, 85, 86, 31 };
static unsigned short _Z[6] = { 87, 88, 89, 90, 91, 92 };
static unsigned short _0[6] = { 18, 2066, 11, 2059, 20, 2068 };
static unsigned short _1[6] = { 93, 29, 30, 31, 94, 31 };
static unsigned short _2[6] = { 18, 2066, 95, 96, 97, 98 };
static unsigned short _3[6] = { 18, 2066, 99, 100, 101, 2068 };
static unsigned short _4[6] = { 102, 103, 104, 105, 106, 107 };
static unsigned short _5[6] = { 6, 2135, 108, 109, 110, 2068 };
static unsigned short _6[6] = { 18, 2066, 111, 112, 20, 2068 };
static unsigned short _7[6] = { 113, 114, 115, 116, 117, 118 };
static unsigned short _8[6] = { 18, 2066, 119, 2167, 20, 2068 };
static unsigned short _9[6] = { 18, 2066, 120, 121, 110, 2068 };
static unsigned short _TEN[6] = { 12, 12, 12, 12, 12, 122 };
unsigned short* asc_maptbl[38] = {
  0,
  _0,
  _1,
  _2,
  _3,
  _4,
  _5,
  _6,
  _7,
  _8,
  _9,
  _A,
  _B,
  _C,
  _D,
  _E,
  _F,
  _G,
  _H,
  _I,
  _J,
  _K,
  _L,
  _M,
  _N,
  _O,
  _P,
  _Q,
  _R,
  _S,
  _T,
  _U,
  _V,
  _W,
  _X,
  _Y,
  _Z,
  _TEN
};
