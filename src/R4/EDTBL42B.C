#include "..\TYPES.H"

extern sprite_pattern* pat_movie[];
extern sprite_pattern* boupat[];
extern sprite_pattern* pat_et[];
extern sprite_pattern* harir4pat[];
extern sprite_pattern* udblk4pat1[];
extern sprite_pattern* udblk4pat3[];
extern sprite_pattern* udblk4pat4[];
extern sprite_pattern* udblk4pat5[];
extern sprite_pattern* udblk4pat6[];
extern sprite_pattern* udblk4pat7[];
extern sprite_pattern* udblk4pat8[];
extern sprite_pattern* udblk4pat9[];
extern sprite_pattern* udblk4patA[];
extern sprite_pattern* lrblk4pat1[];
extern sprite_pattern* lrblk4pat2[];
extern sprite_pattern* lrblk4pat3[];
extern sprite_pattern* lrblk4pat5[];
extern sprite_pattern* lrblk4pat6[];
extern sprite_pattern* lrblk4pat8[];
extern sprite_pattern* pat_walls[];
extern sprite_pattern* rblk4pat[];
extern sprite_pattern* pat_kuzure_a[];
extern sprite_pattern* pat_sw[];
extern sprite_pattern* pat_screw0[];
extern sprite_pattern* pat_screw1[];
extern sprite_pattern* awapat[];
extern sprite_pattern* springpat[];
extern sprite_pattern* spring90pat[];
extern sprite_pattern* pat_tonbo_e[];
extern sprite_pattern* pat_tonbo_b[];
extern sprite_pattern* pat_amenbo_e[];
extern sprite_pattern* pat_amenbo_b[];
extern sprite_pattern* pat_tagameb_e[];
extern sprite_pattern* pat_tagameb_b[];
extern sprite_pattern* pat_yago_e[];
extern sprite_pattern* pat_yago_b[];
extern sprite_pattern* pat_friend0[];
extern sprite_pattern* pat_friend1[];
extern sprite_pattern* itempat[];

edit_info_array edit_tbl = {
  62,
  0,
  {
    { 82, 3, pat_movie,       944 },
    {  5, 1, boupat,          760 },
    { 81, 1, pat_et,         1104 },
    { 34, 1, harir4pat,       928 },
    { 35, 1, udblk4pat1,    17514, 1, 0, 0, 0 },
    { 35, 1, udblk4pat3,    17514, 3, 0, 0, 0 },
    { 35, 1, udblk4pat4,    17514, 4, 0, 0, 0 },
    { 35, 1, udblk4pat5,    17514, 5, 0, 0, 0 },
    { 35, 1, udblk4pat6,    17514, 6, 0, 0, 0 },
    { 35, 1, udblk4pat7,    17514, 7, 0, 0, 0 },
    { 35, 1, udblk4pat8,    17514, 8, 0, 0, 0 },
    { 35, 1, udblk4pat9,    17514, 9, 0, 0, 0 },
    { 35, 1, udblk4patA,    17514, 10, 0, 0, 0 },
    { 35, 1, udblk4patA,    17514, 10, 0, 0, 0 },
    { 36, 1, lrblk4pat1,    17514, 1, 0, 0, 0 },
    { 36, 1, lrblk4pat2,    17514, 2, 0, 0, 0 },
    { 36, 1, lrblk4pat3,    17514, 3, 0, 0, 0 },
    { 36, 1, lrblk4pat3,    17514, 3, 0, 0, 0 },
    { 36, 1, lrblk4pat5,    17514, 5, 0, 0, 0 },
    { 36, 1, lrblk4pat6,    17514, 6, 0, 0, 0 },
    { 36, 1, lrblk4pat6,    17514, 6, 0, 0, 0 },
    { 36, 1, lrblk4pat8,    17514, 8, 0, 0, 0 },
    { 51, 1, pat_walls,     17514 },
    { 51, 1, pat_walls,     17514, 1, 0, 0, 0 },
    { 51, 1, pat_walls,     17514, 2, 0, 0, 0 },
    { 51, 1, pat_walls,     17514, 3, 0, 0, 0 },
    { 51, 1, pat_walls,     17514, 4, 0, 0, 0 },
    { 51, 1, pat_walls,     17514, 5, 0, 0, 0 },
    { 51, 1, pat_walls,     17514, 6, 0, 0, 0 },
    { 51, 1, pat_walls,     17514, 7, 0, 0, 0 },
    { 51, 1, pat_walls,     17514, 8, 0, 0, 0 },
    { 61, 1, rblk4pat,      17152 },
    { 61, 1, rblk4pat,      17152, 1, 0, 0, 1 },
    { 61, 1, rblk4pat,      17152, 2, 0, 0, 2 },
    { 61, 1, rblk4pat,      17152, 3, 0, 0, 3 },
    { 57, 1, pat_kuzure_a,  17252 },
    { 39, 1, pat_sw,         1290 },
    { 53, 1, pat_screw0,    17280, 128, 0, 0, 0 },
    { 53, 1, pat_screw0,    17280, 129, 3, 0, 0 },
    { 53, 1, pat_screw1,    17280, 130, 0, 0, 0 },
    { 53, 1, pat_screw1,    17280, 131, 3, 0, 0 },
    { 32, 4, awapat,        33930, 130, 0, 0, 0 },
    { 10, 1, springpat,      1312 },
    { 10, 1, springpat,      1312, 0, 2, 0, 0 },
    { 10, 1, spring90pat,    1312, 4, 0, 0, 0 },
    { 10, 1, spring90pat,    1312, 4, 1, 0, 0 },
    { 43, 1, pat_tonbo_e,    9238 },
    { 43, 1, pat_tonbo_b,    9238, 1, 0, 0, 0 },
    { 44, 1, pat_amenbo_e,   9136 },
    { 44, 1, pat_amenbo_b,   9136, 1, 0, 0, 0 },
    { 45, 1, pat_tagameb_e,  9168 },
    { 45, 1, pat_tagameb_b,  9168, 1, 0, 0, 0 },
    { 46, 1, pat_yago_e,     9200 },
    { 46, 1, pat_yago_b,     9200, 1, 0, 0, 0 },
    { 47, 1, pat_friend0,    9296 },
    { 47, 1, pat_friend1,    9296, 1, 0, 0, 1 },
    { 25, 4, itempat,        1448 },
    { 57, 3, pat_kuzure_a,  17252 },
    { 57, 3, pat_kuzure_a,  17252, 1, 0, 0, 1 },
    { 57, 3, pat_kuzure_a,  17252, 2, 0, 0, 2 },
    { 57, 3, pat_kuzure_a,  17252, 3, 0, 0, 3 },
    { 57, 3, pat_kuzure_a,  17252, 4, 0, 0, 4 }
  }
};
