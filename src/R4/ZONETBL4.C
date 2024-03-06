#include "..\TYPES.H"

unsigned short title_tbl[32] = {
   304,  552,  360,  346,  256,  568,  376,  602,
   256,  576,  384,  602,  256,  584,  392,  602,
   288,  560,  368,  858,  320,  584,  392, 1114,
   256,  464,  272, 1882,  256,  464,  272, 2138
};
static sprite_pattern titlepat0 = {
  1,
  { { -16, -112, 0, 339 } }
};
static sprite_pattern titlepat1 = {
  1,
  { { -24, -8, 0, 340 } }
};
static sprite_pattern titlepat2 = {
  1,
  { { -4, -24, 0, 341 } }
};
static sprite_pattern titlepat3 = {
  1,
  { { -80, -8, 0, 342 } }
};
static sprite_pattern titlepat4 = {
  1,
  { { -24, -24, 0, 343 } }
};
static sprite_pattern titlepat5 = {
  1,
  { { -24, -24, 0, 344 } }
};
static sprite_pattern titlepat6 = {
  1,
  { { -24, -24, 0, 345 } }
};
static sprite_pattern titlepat7 = {
  1,
  { { 0, -56, 0, 346 } }
};
static sprite_pattern titlepat8 = {
  1,
  { { 0, 0, 0, 347 } }
};
sprite_pattern* title_pat[9] = {
  &titlepat0,
  &titlepat1,
  &titlepat2,
  &titlepat3,
  &titlepat4,
  &titlepat5,
  &titlepat6,
  &titlepat7,
  &titlepat8
};
