#include "..\TYPES.H"

extern sprite_pattern* pat_kuzure_a[];
extern sprite_pattern* koma8pat[];
extern sprite_pattern* pat_et[];

edit_data edit_tbl = {
  10,
  0,
  {
    { 37, 3, pat_kuzure_a, 17624, 1, 0, 0, 0 },
    { 37, 3, pat_kuzure_a, 17624, 2, 0, 0, 1 },
    { 37, 3, pat_kuzure_a, 17624, 3, 0, 0, 2 },
    { 37, 3, pat_kuzure_a, 17624, 4, 0, 0, 3 },
    { 37, 3, pat_kuzure_a, 17624, 5, 0, 0, 4 },
    { 37, 3, pat_kuzure_a, 17624, 6, 0, 0, 5 },
    { 37, 3, pat_kuzure_a, 17624, 7, 0, 0, 6 },
    { 37, 3, pat_kuzure_a, 17624, 8, 0, 0, 7 },
    { 15, 4, koma8pat,      1258 },
    { 67, 1, pat_et,         768 }
  }
};
