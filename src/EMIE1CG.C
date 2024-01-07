#include "TYPES.H"

static sprite_pattern pat0 = {
  1,
  { { -16, -24, 0, 448 } }
};
static sprite_pattern pat1 = {
  1,
  { { -12, -24, 0, 449 } }
};
static sprite_pattern pat2 = {
  1,
  { { -16, -24, 0, 450 } }
};
static sprite_pattern pat3 = {
  1,
  { { -12, -24, 0, 451 } }
};
static sprite_pattern pat4 = {
  1,
  { { -12, -24, 0, 452 } }
};
static sprite_pattern pat5 = {
  1,
  { { -12, -24, 0, 453 } }
};
static sprite_pattern pat6 = {
  1,
  { { -16, -24, 0, 454 } }
};
static sprite_pattern pat7 = {
  1,
  { { -16, -24, 0, 455 } }
};
static sprite_pattern pat8 = {
  1,
  { { -8, -8, 0, 456 } }
};
static sprite_pattern pat9 = {
  1,
  { { -8, -8, 0, 457 } }
};
static sprite_pattern patA = {
  1,
  { { -8, -8, 0, 458 } }
};
static sprite_pattern patB = {
  1,
  { { -12, -24, 0, 459 } }
};
static sprite_pattern patC = {
  1,
  { { -12, -24, 0, 460 } }
};
static sprite_pattern patD = {
  1,
  { { -12, -24, 0, 461 } }
};
static sprite_pattern patE = {
  1,
  { { -16, -20, 0, 462 } }
};
static sprite_pattern patF = {
  1,
  { { -12, -24, 0, 463 } }
};
static sprite_pattern pat10 = {
  1,
  { { -16, -20, 0, 464 } }
};
sprite_pattern* emie1pat[17] = {
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
  &pat10
};
static char moji_pchg[9] = { 3, 11, 4, 11, 5, 11, 4, 11, -1 };
static char run_pchg[9] = { 0, 3, 1, 2, 2, 3, 1, 2, -1 };
static char kiss_pchg[3] = { 14, 9, -1 };
static char stnd2_pchg[5] = { 11, 19, 12, 19, -1 };
static char moji2_pchg[5] = { 6, 9, 7, 9, -1 };
static char kyoro_pchg[9] = { 11, 29, 12, 29, 11, 29, 12, 49, -1 };
char* em_pchg[6] = { stnd2_pchg, moji_pchg, run_pchg, kiss_pchg, moji2_pchg, kyoro_pchg };
