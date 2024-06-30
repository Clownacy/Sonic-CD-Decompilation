#include "..\TYPES.H"

static sprite_pattern pat0 = {
  1,
  { { -16, -24, 0, 421 } }
};
static sprite_pattern pat1 = {
  1,
  { { -12, -24, 0, 422 } }
};
static sprite_pattern pat2 = {
  1,
  { { -16, -24, 0, 423 } }
};
static sprite_pattern pat3 = {
  1,
  { { -12, -23, 0, 424 } }
};
static sprite_pattern pat4 = {
  1,
  { { -12, -23, 0, 425 } }
};
static sprite_pattern pat5 = {
  1,
  { { -12, -23, 0, 426 } }
};
static sprite_pattern pat6 = {
  1,
  { { -16, -24, 0, 427 } }
};
static sprite_pattern pat7 = {
  1,
  { { -16, -24, 0, 428 } }
};
static sprite_pattern pat8 = {
  1,
  { { -8, -8, 0, 429 } }
};
static sprite_pattern pat9 = {
  1,
  { { -8, -8, 0, 430 } }
};
static sprite_pattern patA = {
  1,
  { { -8, -8, 0, 431 } }
};
static sprite_pattern patB = {
  1,
  { { -12, -20, 0, 432 } }
};
static sprite_pattern patC = {
  1,
  { { -21, -20, 0, 433 } }
};
static sprite_pattern patD = {
  1,
  { { -12, -24, 0, 434 } }
};
static sprite_pattern patE = {
  1,
  { { -16, -20, 0, 435 } }
};
static sprite_pattern patF = {
  1,
  { { -12, -24, 0, 436 } }
};
static sprite_pattern pat10 = {
  1,
  { { -16, -20, 0, 437 } }
};
static sprite_pattern pat11 = {
  1,
  { { -12, -20, 0, 438 } }
};
static sprite_pattern pat12 = {
  1,
  { { -12, -20, 0, 439 } }
};
static sprite_pattern pat13 = {
  1,
  { { -12, -20, 0, 440 } }
};
sprite_pattern* emie7pat[20] = {
  &pat0,
  &pat1,
  &pat2,
  &pat3,
  &pat4,
  &pat5,
  &pat6,
  &pat7,
  &pat8,
  &pat9,
  &patA,
  &patB,
  &patC,
  &patD,
  &patE,
  &patF,
  &pat10,
  &pat11,
  &pat12,
  &pat13
};
static char moji_pchg[9] = { 3, 11, 4, 11, 5, 11, 4, 11, -1 };
static char run_pchg[9] = { 0, 3, 1, 2, 2, 3, 1, 2, -1 };
static char kiss_pchg[3] = { 14, 9, -1 };
static char stnd2_pchg[5] = { 11, 19, 12, 19, -1 };
static char moji2_pchg[5] = { 6, 9, 7, 9, -1 };
static char kyoro_pchg[9] = { 11, 19, 12, 19, 11, 19, 12, 19, -1 };
static char help_pchg[9] = { 17, 7, 18, 7, 17, 7, 19, 7, -1 };
char* em_pchg[7] = {
  stnd2_pchg,
  moji_pchg,
  run_pchg,
  kiss_pchg,
  moji2_pchg,
  kyoro_pchg,
  help_pchg
};
