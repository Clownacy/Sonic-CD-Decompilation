#include "..\TYPES.H"

extern sprite_pattern* pat_friend0[];
extern sprite_pattern* pat_friend1[];
extern sprite_pattern* pat_tonbo_e[];
extern sprite_pattern* pat_tonbo_b[];
extern sprite_pattern* pat_wall1[];
extern sprite_pattern* awapat[];
extern sprite_pattern* springpat[];
extern sprite_pattern* spring90pat[];
extern sprite_pattern* itempat[];

edit_info_array edit_tbl = {
  11,
  0,
  {
    { 47, 1, pat_friend0,  9296 },
    { 47, 1, pat_friend1,  9296, 1, 0, 0, 1 },
    { 43, 1, pat_tonbo_e,  9238 },
    { 43, 1, pat_tonbo_b,  9238, 1, 0, 0, 0 },
    { 52, 1, pat_wall1,   17514 },
    { 32, 4, awapat,      33930, 130, 0, 0, 0 },
    { 10, 1, springpat,    1312 },
    { 10, 1, springpat,    1312, 0, 2, 0, 0 },
    { 10, 1, spring90pat,  1312, 4, 0, 0, 0 },
    { 10, 1, spring90pat,  1312, 4, 1, 0, 0 },
    { 25, 4, itempat,      1448 }
  }
};
