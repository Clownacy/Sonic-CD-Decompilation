#include "..\TYPES.H"

extern sprite_pattern* kaitenban_pat[];
extern sprite_pattern* harir3pat[];
extern sprite_pattern* bobinpat[];
extern sprite_pattern* banpa_pat[];
extern sprite_pattern* frippat[];
extern sprite_pattern* springpat[];
extern sprite_pattern* itempat[];

edit_info_array edit_tbl = {
  8,
  0,
  {
    { 54, 1, kaitenban_pat, 17470, 254, 0, 0, 0 },
    { 32, 1, harir3pat,      1020 },
    { 29, 1, bobinpat,       1066 },
    { 42, 1, banpa_pat,     17507 },
    { 30, 1, frippat,        1181 },
    { 30, 1, frippat,        1181, 0, 1, 0, 0 },
    { 10, 1, springpat,      1312 },
    { 25, 4, itempat,        1448 }
  }
};
