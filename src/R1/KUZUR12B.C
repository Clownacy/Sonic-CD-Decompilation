#include "..\TYPES.H"

sprite_pattern pata00 = {
  1,
  { { -40, -48, 0, 481 } }
};
sprite_pattern* patbase_kuzure_a[1] = { &pata00 };
unsigned char tbla00[22] = {
  4, 3, 255, 255, 0, 0, 0, 1, 2, 3,
  3, 4, 0, 5, 5, 5, 5, 6, 6, 6,
  6, 6
};
unsigned char* tbla[1] = { tbla00 };
sprite_pattern patc00 = {
  1,
  { { -8, -8, 0, 482 } }
};
sprite_pattern patc01 = {
  1,
  { { -8, -8, 0, 483 } }
};
sprite_pattern patc02 = {
  1,
  { { -8, -8, 0, 484 } }
};
sprite_pattern patc03 = {
  1,
  { { -8, -8, 0, 485 } }
};
sprite_pattern patc04 = {
  1,
  { { -8, -8, 0, 486 } }
};
sprite_pattern patc05 = {
  1,
  { { -8, -8, 0, 487 } }
};
sprite_pattern patc06 = {
  1,
  { { -8, -24, 0, 488 } }
};
sprite_pattern* patc[7] = {
  &patc00,
  &patc01,
  &patc02,
  &patc03,
  &patc04,
  &patc05,
  &patc06
};
sprite_pattern patb00 = {
  1,
  { { -64, -40, 0, 489 } }
};
sprite_pattern patb01 = {
  1,
  { { -64, -32, 0, 490 } }
};
sprite_pattern* patbase_kuzure_b[2] = {
  &patb00,
  &patb01
};
unsigned char tblb00[10] = { 7, 2, 0, 0, 0, 0, 0, 0, 0, 0 };
unsigned char tblb01[10] = { 7, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
unsigned char* tblb[2] = {
  tblb00,
  tblb01
};
sprite_pattern patd00 = {
  1,
  { { -8, -40, 0, 491 } }
};
sprite_pattern patd01 = {
  1,
  { { -8, -32, 0, 492 } }
};
sprite_pattern* patd[2] = {
  &patd00,
  &patd01
};
