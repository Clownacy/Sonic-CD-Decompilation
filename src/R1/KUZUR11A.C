#include "..\TYPES.H"

static spr_array pata00 = {
  1,
  { { -40, -48, 0, 498 } }
};
spr_array* patbase_kuzure_a[1] = { &pata00 };
static unsigned char tbla00[22] = {
  4, 3, 255, 255, 0, 0, 0, 1, 2, 3,
  3, 4, 0, 5, 5, 5, 5, 6, 6, 6,
  6, 6
};
unsigned char* tbla[1] = { tbla00 };
static spr_array patc00 = {
  1,
  { { -8, -8, 0, 499 } }
};
static spr_array patc01 = {
  1,
  { { -8, -8, 0, 500 } }
};
static spr_array patc02 = {
  1,
  { { -8, -8, 0, 501 } }
};
static spr_array patc03 = {
  1,
  { { -8, -8, 0, 502 } }
};
static spr_array patc04 = {
  1,
  { { -8, -8, 0, 503 } }
};
static spr_array patc05 = {
  1,
  { { -8, -8, 0, 504 } }
};
static spr_array patc06 = {
  1,
  { { -8, -24, 0, 505 } }
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
static spr_array patb00 = {
  1,
  { { -48, -32, 0, 506 } }
};
static spr_array patb01 = {
  1,
  { { -32, -48, 0, 507 } }
};
static spr_array patb02 = {
  1,
  { { -48, -32, 0, 508 } }
};
static spr_array patb03 = {
  1,
  { { -16, -48, 0, 509 } }
};
static spr_array patb04 = {
  1,
  { { -16, -48, 0, 510 } }
};
spr_array* patbase_kuzure_b[6] = {
  &patb00,
  &patb00,
  &patb01,
  &patb02,
  &patb03,
  &patb04,
};
static unsigned char tblb00[8] = { 5, 1, 0, 0, 0, 0, 0, 0 };
static unsigned char tblb01[6] = { 3, 3, 1, 2, 2, 2 };
static unsigned char tblb02[6] = { 3, 3, 2, 2, 2, 2 };
static unsigned char tblb03[4] = { 1, 3, 3, 5 };
static unsigned char tblb04[4] = { 1, 3, 5, 4 };
unsigned char* tblb[6] = {
  tblb00,
  tblb00,
  tblb01,
  tblb02,
  tblb03,
  tblb04
};
static spr_array patd00 = {
  1,
  { { -8, -32, 0, 511 } }
};
static spr_array patd01 = {
  1,
  { { -8, -48, 0, 512 } }
};
static spr_array patd02 = {
  1,
  { { -8, -48, 0, 513 } }
};
static spr_array patd03 = {
  1,
  { { -8, -48, 0, 514 } }
};
static spr_array patd04 = {
  1,
  { { -8, -48, 0, 515 } }
};
static spr_array patd05 = {
  1,
  { { -8, -48, 0, 516 } }
};
spr_array* patd[6] = {
  &patd00,
  &patd01,
  &patd02,
  &patd03,
  &patd04,
  &patd05
};
