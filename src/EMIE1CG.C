spr_array pat0 = {
  .cnt = 1,
  .spra = { { -16, -24, 0, 448 } }
};
spr_array pat1 = {
  .cnt = 1,
  .spra = { { -12, -24, 0, 449 } }
};
spr_array pat2 = {
  .cnt = 1,
  .spra = { { -16, -24, 0, 450 } }
};
spr_array pat3 = {
  .cnt = 1,
  .spra = { { -12, -24, 0, 451 } }
};
spr_array pat4 = {
  .cnt = 1,
  .spra = { { -12, -24, 0, 452 } }
};
spr_array pat5 = {
  .cnt = 1,
  .spra = { { -12, -24, 0, 453 } }
};
spr_array pat6 = {
  .cnt = 1,
  .spra = { { -16, -24, 0, 454 } }
};
spr_array pat7 = {
  .cnt = 1,
  .spra = { { -16, -24, 0, 455 } }
};
spr_array pat8 = {
  .cnt = 1,
  .spra = { { -8, -8, 0, 456 } }
};
spr_array pat9 = {
  .cnt = 1,
  .spra = { { -8, -8, 0, 457 } }
};
spr_array patA = {
  .cnt = 1,
  .spra = { { -8, -8, 0, 458 } }
};
spr_array patB = {
  .cnt = 1,
  .spra = { { -12, -24, 0, 459 } }
};
spr_array patC = {
  .cnt = 1,
  .spra = { { -12, -24, 0, 460 } }
};
spr_array patD = {
  .cnt = 1,
  .spra = { { -12, -24, 0, 461 } }
};
spr_array patE = {
  .cnt = 1,
  .spra = { { -16, -20, 0, 462 } }
};
spr_array patF = {
  .cnt = 1,
  .spra = { { -12, -24, 0, 463 } }
};
spr_array pat10 = {
  .cnt = 1,
  .spra = { { -16, -20, 0, 464 } }
};
spr_array* emie1pat[17] = {
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
char moji_pchg[9] = { 3, 11, 4, 11, 5, 11, 4, 11, -1 };
char run_pchg[9] = { 0, 3, 1, 2, 2, 3, 1, 2, -1 };
char kiss_pchg[3] = { 14, 9, -1 };
char stnd2_pchg[5] = { 11, 19, 12, 19, -1 };
char moji2_pchg[5] = { 6, 9, 7, 9, -1 };
char kyoro_pchg[9] = { 11, 29, 12, 29, 11, 29, 12, 49, -1 };
char* em_pchg[6] = { stnd2_pchg, moji_pchg, run_pchg, kiss_pchg, moji2_pchg, kyoro_pchg };
