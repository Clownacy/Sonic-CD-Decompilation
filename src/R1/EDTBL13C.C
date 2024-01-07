#include "..\TYPES.H"

extern sprite_pattern* iwapat[];
extern sprite_pattern* springpat[];
extern sprite_pattern* spring90pat[];
extern sprite_pattern* pat_friend0[];
extern sprite_pattern* pat_friend1[];
extern sprite_pattern* itempat[];
extern sprite_pattern* egg1_pat[];
extern sprite_pattern* bariapat[];

edit_info_array edit_tbl = {
  24,
  0,
  {
    { 27, 1, iwapat,      1278, 0, 0, 1, 0 },
    { 10, 1, springpat,   1312 },
    { 10, 1, springpat,   1312, 0, 2, 0, 0 },
    { 10, 1, spring90pat, 1312, 4, 0, 0, 0 },
    { 10, 1, spring90pat, 1312, 4, 1, 0, 0 },
    { 10, 1, springpat,   9504, 2, 0, 0, 0 },
    { 10, 1, springpat,   9504, 2, 2, 0, 0 },
    { 10, 1, spring90pat, 9504, 6, 0, 0, 0 },
    { 10, 1, spring90pat, 9504, 6, 1, 0, 0 },
    { 36, 3, pat_friend0,  975 },
    { 36, 3, pat_friend1,  975, 1, 0, 0, 3 },
    { 25, 4, itempat,     1448 },
    { 25, 4, itempat,     1448, 1, 0, 0, 1 },
    { 25, 4, itempat,     1448, 2, 0, 0, 2 },
    { 25, 4, itempat,     1448, 3, 0, 0, 3 },
    { 25, 4, itempat,     1448, 4, 0, 0, 4 },
    { 25, 4, itempat,     1448, 5, 0, 0, 5 },
    { 25, 4, itempat,     1448, 6, 0, 0, 6 },
    { 25, 4, itempat,     1448, 7, 0, 0, 7 },
    { 25, 4, itempat,     1448, 8, 0, 0, 10 },
    { 25, 4, itempat,     1448, 9, 0, 0, 12 },
    { 42, 3, egg1_pat,    1036 },
    { 52, 3, bariapat,    1348, 0, 0, 0, 1 },
    { 52, 3, bariapat,    1348, 1, 0, 0, 2 }
  }
};
