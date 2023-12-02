#include "..\TYPES.H"

spr_array pata00 = {
  1,
  { { -40, -48, 0, 481 } }
};
spr_array* patbase_kuzure_a[1] = { &pata00 };
unsigned char tbla00[22] = {
  4, 3, 255, 255, 0, 0, 0, 1, 2, 3,
  3, 4, 0, 5, 5, 5, 5, 6, 6, 6,
  6, 6
};
unsigned char* tbla[1] = { tbla00 };
spr_array patc00 = {
  1,
  { { -8, -8, 0, 482 } }
};
spr_array patc01 = {
  1,
  { { -8, -8, 0, 483 } }
};
spr_array patc02 = {
  1,
  { { -8, -8, 0, 484 } }
};
spr_array patc03 = {
  1,
  { { -8, -8, 0, 485 } }
};
spr_array patc04 = {
  1,
  { { -8, -8, 0, 486 } }
};
spr_array patc05 = {
  1,
  { { -8, -8, 0, 487 } }
};
spr_array patc06 = {
  1,
  { { -8, -24, 0, 488 } }
};
spr_array* patc[7] = {
  &patc00,
  &patc01,
  &patc02,
  &patc03,
  &patc04,
  &patc05,
  &patc06
};
spr_array patb00 = {
  1,
  { { -48, -32, 0, 489 } }
};
spr_array patb01 = {
  1,
  { { -32, -48, 0, 490 } }
};
spr_array* patbase_kuzure_b[2] = {
  &patb00,
  &patb00
};
unsigned char tblb00[8] = { 5, 1, 0, 0, 0, 0, 0, 0 };
unsigned char* tblb[2] = {
  tblb00,
  tblb00
};
spr_array patd00 = {
  1,
  { { -8, -32, 0, 491 } }
};
spr_array* patd[1] = { &patd00 };
