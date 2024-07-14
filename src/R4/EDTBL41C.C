#include "..\TYPES.H"

sprite_pattern* harir4pat[];
sprite_pattern* renketu4pat[];
sprite_pattern* pat_tekkyu4[];
sprite_pattern* pat_screw0[];
sprite_pattern* pat_screw1[];
sprite_pattern* awapat[];
sprite_pattern* springpat[];
sprite_pattern* spring90pat[];
sprite_pattern* pat_wall1[];
sprite_pattern* pat_tonbo_e[];
sprite_pattern* pat_tonbo_b[];
sprite_pattern* pat_amenbo_e[];
sprite_pattern* pat_amenbo_b[];
sprite_pattern* pat_tagameb_e[];
sprite_pattern* pat_tagameb_b[];
sprite_pattern* pat_yago_e[];
sprite_pattern* pat_yago_b[];
sprite_pattern* pat_friend0[];
sprite_pattern* pat_friend1[];
sprite_pattern* itempat[];
sprite_pattern* boupat[];

edit_data edit_tbl = {
  25,
  0,
  {
    { 34, 1, harir4pat,       928 },
    { 62, 1, renketu4pat,   17216 },
    { 56, 1, pat_tekkyu4,     880 },
    { 53, 1, pat_screw0,    17280, 128, 0, 0, 0 },
    { 53, 1, pat_screw0,    17280, 129, 3, 0, 0 },
    { 53, 1, pat_screw1,    17280, 130, 0, 0, 0 },
    { 53, 1, pat_screw1,    17280, 131, 3, 0, 0 },
    { 32, 4, awapat,        33930, 130, 0, 0, 0 },
    { 10, 1, springpat,      1312 },
    { 10, 1, springpat,      1312, 0, 2, 0, 0 },
    { 10, 1, spring90pat,    1312, 4, 0, 0, 0 },
    { 10, 1, spring90pat,    1312, 4, 1, 0, 0 },
    { 52, 1, pat_wall1,     17514 },
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
    {  5, 4, boupat,          760 }
  }
};
