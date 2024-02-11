#include "..\TYPES.H"

extern sprite_pattern* bariapat[];
extern sprite_pattern* drumr3pat[];
extern sprite_pattern* pat_et[];
extern sprite_pattern* pat_e_ga[];
extern sprite_pattern* pat_b_ga[];
extern sprite_pattern* pat_e_tentou[];
extern sprite_pattern* pat_ten_b_tentou[];
extern sprite_pattern* kamapat[];
extern sprite_pattern* bkamapat[];
extern sprite_pattern* harir3pat[];
extern sprite_pattern* frdr3pat[];
extern sprite_pattern* trapdr3pat[];

edit_info_array edit_tbl = {
  24,
  0,
  {
    { 53, 3, bariapat,          1348, 0, 0, 0, 1 },
    { 53, 3, bariapat,          1348, 1, 0, 0, 2 },
    { 40, 1, drumr3pat,          874 },
    { 40, 1, drumr3pat,          874, 0, 0, 0, 1 },
    { 40, 1, drumr3pat,          874, 0, 0, 0, 2 },
    { 40, 1, drumr3pat,          874, 0, 0, 0, 3 },
    { 40, 1, drumr3pat,          874, 0, 0, 0, 4 },
    { 40, 1, drumr3pat,          874, 0, 0, 0, 5 },
    { 40, 1, drumr3pat,          874, 0, 0, 0, 6 },
    { 40, 1, drumr3pat,          874, 0, 0, 0, 7 },
    { 40, 1, drumr3pat,          874, 0, 0, 0, 8 },
    { 40, 1, drumr3pat,          874, 0, 0, 0, 9 },
    { 40, 1, drumr3pat,          874, 0, 0, 0, 10 },
    { 40, 1, drumr3pat,          874, 0, 0, 0, 11 },
    { 55, 1, pat_et,             874 },
    { 45, 1, pat_e_ga,          9249 },
    { 45, 1, pat_b_ga,          9249, 255, 0, 0, 0 },
    { 46, 1, pat_e_tentou,      9322 },
    { 46, 1, pat_ten_b_tentou,  9322, 255, 0, 0, 0 },
    { 36, 1, kamapat,           9202 },
    { 36, 1, bkamapat,          9202, 255, 0, 0, 0 },
    { 32, 1, harir3pat,          798 },
    { 33, 1, frdr3pat,         17214, 2, 0, 0, 0 },
    { 34, 1, trapdr3pat,         846, 1, 0, 0, 0 }
  }
};
