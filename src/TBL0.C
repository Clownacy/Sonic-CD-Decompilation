#include "TYPES.H"

unsigned char genechg0[39] = {
   1,
   0,  0,  0,  0,  0,  0,  0,
   0,  0,  0,  0,  0,  0,  0,
   0,  0,  0,  0,  0,  0,  0,
   0,  0,  0,  0,  0,  0,  0,
   0,  0,  1,  0,  0,  1,  0,  0,  1,
   255
};
unsigned char genechg1[8] = { 2, 3, 4, 5, 6, 7, 8, 255 };
unsigned char* genechg[2] = {
  genechg0,
  genechg1
};
spr_array genepat0 = {
  1,
  { { -32, -32, 0, 393 } }
};
spr_array genepat1 = {
  1,
  { { -32, -32, 0, 394 } }
};
spr_array genepat2 = {
  1,
  { { -32, 8, 0, 395 } }
};
spr_array genepat3 = {
  1,
  { { -16, -16, 0, 396 } }
};
spr_array genepat4 = {
  1,
  { { -16, -16, 0, 397 } }
};
spr_array genepat5 = {
  1,
  { { -16, -16, 0, 398 } }
};
spr_array genepat6 = {
  1,
  { { -16, -16, 0, 399 } }
};
spr_array genepat7 = {
  1,
  { { -16, -16, 0, 400 } }
};
spr_array genepat8 = {
  1,
  { { -16, -16, 0, 401 } }
};
spr_array* genepat[9] = {
  &genepat0,
  &genepat1,
  &genepat2,
  &genepat3,
  &genepat4,
  &genepat5,
  &genepat6,
  &genepat7,
  &genepat8
};
unsigned char bringchg0[6] = { 7, 0, 1, 2, 3, 255 };
unsigned char* bringchg[1] = { bringchg0 };
spr_array bringpat0 = {
  1,
  { { -32, -32, 0, 246 } }
};
spr_array bringpat1 = {
  1,
  { { -24, -32, 0, 247 } }
};
spr_array bringpat2 = {
  1,
  { { -12, -32, 0, 248 } }
};
spr_array bringpat3 = {
  1,
  { { -24, -32, 0, 247 } }
};
spr_array* bringpat[4] = {
  &bringpat0,
  &bringpat1,
  &bringpat2,
  &bringpat3
};
unsigned char bring2chg0[10] = {
  2,
  0, 1, 2, 3, 4, 5, 6, 7,
  252
};
unsigned char* bring2chg[1] = { bring2chg0 };
spr_array bring2pat0 = {
  1,
  { { -32, -32, 0, 250 } }
};
spr_array bring2pat1 = {
  1,
  { { -32, -32, 0, 251 } }
};
spr_array bring2pat2 = {
  1,
  { { -32, -32, 0, 252 } }
};
spr_array bring2pat3 = {
  1,
  { { -32, -32, 0, 253 } }
};
spr_array bring2pat4 = {
  1,
  { { -32, -32, 0, 254 } }
};
spr_array bring2pat5 = {
  1,
  { { -32, -26, 0, 255 } }
};
spr_array bring2pat6 = {
  1,
  { { -32, -32, 0, 256 } }
};
spr_array bring2pat7 = {
  1,
  { { -32, -32, 0, 257 } }
};
spr_array* bring2pat[8] = {
  &bring2pat0,
  &bring2pat1,
  &bring2pat2,
  &bring2pat3,
  &bring2pat4,
  &bring2pat5,
  &bring2pat6,
  &bring2pat7
};
unsigned char goalchg0[11] = {
  1,
  0, 1, 2, 4, 3,
  3, 1, 2, 4,
  255
};
unsigned char* goalchg[1] = { goalchg0 };
spr_array goalsp0 = {
  1,
  { { -24, -44, 0, 258 } }
};
spr_array goalsp1 = {
  1,
  { { -16, -44, 0, 259 } }
};
spr_array goalsp2 = {
  1,
  { { -16, -44, 0, 260 } }
};
spr_array goalsp3 = {
  1,
  { { -24, -44, 0, 261 } }
};
spr_array goalsp4 = {
  1,
  { { -16, -44, 0, 262 } }
};
spr_array goalsp5 = {
  1,
  { { -20, -28, 0, 263 } }
};
spr_array* goalpat[6] = {
  &goalsp0,
  &goalsp1,
  &goalsp2,
  &goalsp3,
  &goalsp4,
  &goalsp5
};
unsigned char awasintbl[256] = {
  0, 0, 0, 0, 0, 0,
  1, 1, 1, 1, 1,
  2, 2, 2, 2, 2, 2, 2,
  3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3,
  2, 2, 2, 2, 2, 2, 2,
  1, 1, 1, 1, 1,
  0, 0, 0, 0, 0, 0,
  255, 255, 255, 255, 255,
  254, 254, 254, 254, 254,
  253, 253, 253, 253, 253, 253, 253,
  252, 252, 252, 252, 252, 252, 252, 252, 252, 252, 252, 252, 252, 252, 252, 252, 252, 252, 252, 252, 252, 252, 252, 252, 252, 252, 252, 252, 252,
  253, 253, 253, 253, 253, 253, 253,
  254, 254, 254, 254, 254,
  255, 255, 255, 255, 255,
  0, 0, 0, 0, 0, 0,
  1, 1, 1, 1, 1,
  2, 2, 2, 2, 2, 2, 2,
  3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3,
  2, 2, 2, 2, 2, 2, 2,
  1, 1, 1, 1, 1,
  0, 0, 0, 0, 0, 0,
  255, 255, 255, 255, 255,
  254, 254, 254, 254, 254,
  253, 253, 253, 253, 253, 253, 253,
  252, 252, 252, 252, 252, 252, 252, 252, 252, 252, 252, 252, 252, 252, 252, 252, 252, 252, 252, 252, 252, 252, 252, 252, 252, 252, 252, 252, 252,
  253, 253, 253, 253, 253, 253, 253,
  254, 254, 254, 254, 254,
  255, 255, 255, 255, 255
};
