#include "..\TYPES.H"

spr_array pata00 = {
  1,
  { { -40, -48, 0, 481 } }
};
spr_array pata01 = {
  1,
  { { -32, -40, 0, 482 } }
};
spr_array* patbase_kuzure_a[2] = {
  &pata00,
  &pata01
};
unsigned char tbla00[22] = {
  4, 3, 255, 255, 0, 0, 0, 1, 2, 3,
  3, 4, 0, 5, 5, 5, 5, 6, 6, 6,
  6, 6
};
unsigned char tbla01[14] = {
  3, 2, 1, 2, 3, 3, 5, 5, 5, 5,
  6, 6, 6, 6
};
unsigned char* tbla[2] = {
  tbla00,
  tbla01
};
spr_array patc00 = {
  1,
  { { -8, -8, 0, 483 } }
};
spr_array patc01 = {
  1,
  { { -8, -8, 0, 484 } }
};
spr_array patc02 = {
  1,
  { { -8, -8, 0, 485 } }
};
spr_array patc03 = {
  1,
  { { -8, -8, 0, 486 } }
};
spr_array patc04 = {
  1,
  { { -8, -8, 0, 487 } }
};
spr_array patc05 = {
  1,
  { { -8, -8, 0, 488 } }
};
spr_array patc06 = {
  1,
  { { -8, -24, 0, 489 } }
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
  { { -48, -32, 0, 490 } }
};
spr_array patb01 = {
  1,
  { { -72, -48, 0, 491 } }
};
spr_array patb02 = {
  1,
  { { -40, -40, 0, 492 } }
};
spr_array patb03 = {
  1,
  { { -40, -40, 0, 493 } }
};
spr_array patb04 = {
  1,
  { { -80, -48, 0, 494 } }
};
spr_array* patbase_kuzure_b[6] = {
  &patb00,
  &patb00,
  &patb01,
  &patb02,
  &patb03,
  &patb04
};
unsigned char tblb00[8] = { 5, 1, 0, 0, 0, 0, 0, 0 };
unsigned char tblb01[11] = { 8, 3, 1, 3, 3, 3, 3, 3, 3, 3, 2 };
unsigned char tblb02[7] = { 4, 2, 4, 6, 6, 6, 6 };
unsigned char tblb03[7] = { 4, 2, 6, 6, 6, 6, 5 };
unsigned char tblb04[12] = { 9, 3, 1, 3, 3, 3, 3, 3, 3, 3, 3, 2 };
unsigned char* tblb[6] = {
  tblb00,
  tblb00,
  tblb01,
  tblb02,
  tblb03,
  tblb04
};
spr_array patd00 = {
  1,
  { { -8, -32, 0, 495 } }
};
spr_array patd01 = {
  1,
  { { -8, -48, 0, 496 } }
};
spr_array patd02 = {
  1,
  { { -8, -48, 0, 497 } }
};
spr_array patd03 = {
  1,
  { { -8, -48, 0, 498 } }
};
spr_array patd04 = {
  1,
  { { -8, -40, 0, 499 } }
};
spr_array patd05 = {
  1,
  { { -8, -40, 0, 500 } }
};
spr_array patd06 = {
  1,
  { { -8, -40, 0, 501 } }
};
spr_array* patd[7] = {
  &patd00,
  &patd01,
  &patd02,
  &patd03,
  &patd04,
  &patd05,
  &patd06
};
