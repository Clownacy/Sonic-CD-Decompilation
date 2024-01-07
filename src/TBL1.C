#include "TYPES.H"

static unsigned char bariachg0[8] = { 1, 1, 0, 2, 0, 3, 0, 255 };
static unsigned char bariachg1[6] = { 5, 4, 5, 6, 7, 255 };
static unsigned char bariachg2[26] = {
  0,
  4, 4, 0, 4, 4, 0,
  5, 5, 0, 5, 5, 0,
  6, 6, 0, 6, 6, 0,
  7, 7, 0, 7, 7, 0,
  255
};
static unsigned char bariachg3[26] = {
  0,
  4, 4, 0, 4, 0, 0,
  5, 5, 0, 5, 0, 0,
  6, 6, 0, 6, 0, 0,
  7, 7, 0, 7, 0, 0,
  255
};
static unsigned char bariachg4[26] = {
  0,
  4, 0, 0, 4, 0, 0,
  5, 0, 0, 5, 0, 0,
  6, 0, 0, 6, 0, 0,
  7, 0, 0, 7, 0, 0,
  255
};
static unsigned char bariachg5[12] = {
   0,
   8,  9, 10, 11, 12,
  11, 10,  9,  8,  0,
  255
};
static unsigned char bariachg6[57] = {
   0,
   8,  8,  0,  8,  8,  0,
   9,  9,  0,  9,  9,  0,
  10, 10,  0, 10, 10,  0,
  11, 11,  0, 11, 11,  0,
  12, 12,  0, 12, 12,  0,
  11, 11,  0, 11, 11,  0,
  10, 10,  0, 10, 10,  0,
   9,  9,  0,  9,  9,  0,
   8,  8,  0,  8,  8,  0,
   0,
  255
};
static unsigned char bariachg7[57] = {
   0,
   8,  8,  0,  8,  0,  0,
   9,  9,  0,  9,  0,  0,
  10, 10,  0, 10,  0,  0,
  11, 11,  0, 11,  0,  0,
  12, 12,  0, 12,  0,  0,
  11, 11,  0, 11,  0,  0,
  10, 10,  0, 10,  0,  0,
   9,  9,  0,  9,  0,  0,
   8,  8,  0,  8,  0,  0,
   0,
  255
};
static unsigned char bariachg8[57] = {
   0,
   8,  0,  0,  8,  0,  0,
   9,  0,  0,  9,  0,  0,
  10,  0,  0, 10,  0,  0,
  11,  0,  0, 11,  0,  0,
  12,  0,  0, 12,  0,  0,
  11,  0,  0, 11,  0,  0,
  10,  0,  0, 10,  0,  0,
   9,  0,  0,  9,  0,  0,
   8,  0,  0,  8,  0,  0,
   0,
  255
};
unsigned char* bariachg[9] = {
  bariachg0,
  bariachg1,
  bariachg2,
  bariachg3,
  bariachg4,
  bariachg5,
  bariachg6,
  bariachg7,
  bariachg8
};
static sprite_pattern bar00 = {
  1,
  { { -24, -24, 0, 0 } }
};
static sprite_pattern bar01 = {
  1,
  { { -24, -24, 0, 213 } }
};
static sprite_pattern bar02 = {
  1,
  { { -24, -24, 0, 214 } }
};
static sprite_pattern bar03 = {
  1,
  { { -24, -24, 0, 215 } }
};
static sprite_pattern bar04 = {
  2,
  {
    { -24, -24,  0, 216 },
    {   0, -24, 24, 216 }
  }
};
static sprite_pattern bar05 = {
  2,
  {
    {   0, -24,  8, 216 },
    { -24, -24, 16, 216 }
  }
};
static sprite_pattern bar06 = {
  2,
  {
    { -24, -24,  0, 217 },
    { -24, -24, 24, 217 }
  }
};
static sprite_pattern bar07 = {
  2,
  {
    {   0, -24,  8, 217 },
    { -24, -24, 16, 217 }
  }
};
static sprite_pattern bar08 = {
  1,
  { { -16, -16, 0, 218 } }
};
static sprite_pattern bar09 = {
  1,
  { { -16, -16, 0, 219 } }
};
static sprite_pattern bar0a = {
  1,
  { { -24, -24, 0, 220 } }
};
static sprite_pattern bar0b = {
  1,
  { { -16, -16, 0, 221 } }
};
static sprite_pattern bar0c = {
  1,
  { { -16, -12, 0, 222 } }
};
sprite_pattern* bariapat[13] = {
  &bar00,
  &bar01,
  &bar02,
  &bar03,
  &bar04,
  &bar05,
  &bar06,
  &bar07,
  &bar08,
  &bar09,
  &bar0a,
  &bar0b,
  &bar0c
};
static unsigned char exit2chg0[7] = { 3, 0, 4, 3, 1, 2, 252 };
static unsigned char exit2chg1[5] = { 3, 0, 1, 2, 252 };
static unsigned char exit2chg2[5] = { 3, 6, 0, 5, 252 };
unsigned char* exit2chg[3] = {
  exit2chg0,
  exit2chg1,
  exit2chg2
};
static sprite_pattern exi00 = {
  1,
  { { -16, -32, 0, 223 } }
};
static sprite_pattern exi01 = {
  1,
  { { -16, -32, 0, 224 } }
};
static sprite_pattern exi02 = {
  1,
  { { -16, -32, 0, 225 } }
};
static sprite_pattern exi03 = {
  1,
  { { -16, -48, 0, 226 } }
};
static sprite_pattern exi04 = {
  1,
  { { -16, -64, 0, 227 } }
};
static sprite_pattern exi05 = {
  1,
  { { -16, -32, 0, 228 } }
};
static sprite_pattern exi06 = {
  1,
  { { -16, -32, 0, 228 } }
};
sprite_pattern* exit2pat[7] = {
  &exi00,
  &exi01,
  &exi02,
  &exi03,
  &exi04,
  &exi05,
  &exi06
};
static unsigned char futachg0[12] = {
  0,
  0, 0, 1, 1, 1,
  1, 1, 1, 1, 1,
  252
};
unsigned char* futachg[1] = { futachg0 };
static sprite_pattern fut00 = {
  1,
  { { -24, -8, 0, 231 } }
};
static sprite_pattern fut01 = {
  1,
  { { -28, -48, 0, 230 } }
};
sprite_pattern* futapat[2] = {
  &fut00,
  &fut01
};
static unsigned char mizukichg0[5] = { 3, 0, 1, 2, 252 };
unsigned char* mizukichg[1] = { mizukichg0 };
static sprite_pattern miz00 = {
  1,
  { { -16, -16, 0, 232 } }
};
static sprite_pattern miz01 = {
  1,
  { { -12, -12, 0, 233 } }
};
static sprite_pattern miz02 = {
  1,
  { { -8, -8, 0, 234 } }
};
sprite_pattern* mizukipat[3] = {
  &miz00,
  &miz01,
  &miz02
};
static unsigned char baku_chg0[7] = { 3, 0, 5, 6, 3, 4, 252 };
static unsigned char baku_chg1[7] = { 3, 0, 1, 2, 3, 4, 252 };
unsigned char* bakuchg[2] = {
  baku_chg0, baku_chg1
};
static sprite_pattern bak00 = {
  1,
  { { -16, -8, 0, 235 } }
};
static sprite_pattern bak01 = {
  1,
  { { -16, -16, 0, 236 } }
};
static sprite_pattern bak02 = {
  1,
  { { -16, -16, 0, 237 } }
};
static sprite_pattern bak03 = {
  1,
  { { -24, -24, 0, 238 } }
};
static sprite_pattern bak04 = {
  1,
  { { -24, -24, 0, 239 } }
};
static sprite_pattern bak05 = {
  1,
  { { -16, -16, 0, 240 } }
};
static sprite_pattern bak06 = {
  1,
  { { -16, -16, 0, 241 } }
};
sprite_pattern* bakupat[7] = {
  &bak00,
  &bak01,
  &bak02,
  &bak03,
  &bak04,
  &bak05,
  &bak06
};
static unsigned char mkchg[4] = { 3, 2, 3, 255 };
unsigned char* markerchg[1] = { mkchg };
static sprite_pattern pat00 = {
  1,
  { { -8, -24, 0, 242 } }
};
static sprite_pattern pat01 = {
  1,
  { { -8, -8, 0, 243 } }
};
static sprite_pattern pat02 = {
  1,
  { { -8, -8, 0, 244 } }
};
static sprite_pattern pat03 = {
  1,
  { { -8, -8, 0, 245 } }
};
sprite_pattern* markerpat[4] = {
  &pat00,
  &pat01,
  &pat02,
  &pat03
};
static unsigned char bringchg0[6] = { 7, 0, 1, 2, 3, 255 };
static sprite_pattern big00 = {
  1,
  { { -32, -32, 0, 232 } }
};
static sprite_pattern big01 = {
  1,
  { { -24, -32, 0, 233 } }
};
static sprite_pattern big02 = {
  1,
  { { -12, -32, 0, 234 } }
};
static sprite_pattern big03 = {
  1,
  { { -24, -32, 8, 235 } }
};
sprite_pattern* bigringpat[4] = {
  &big00,
  &big01,
  &big02,
  &big03
};
static unsigned char goalchg0[11] = {
  1,
  0, 1, 2, 4, 3,
  3, 1, 2, 4,
  255 };
static sprite_pattern goa00 = {
  2,
  {
    { -24, -44, 0, 258 },
    { -16, -12, 0, 262 }
  }
};
static sprite_pattern goa01 = {
  2,
  {
    { -16, -44, 0, 259 },
    { -16, -12, 0, 262 }
  }
};
static sprite_pattern goa02 = {
  2,
  {
    { -4, -44, 0, 260 },
    { -16, -12, 0, 262 }
  }
};
static sprite_pattern goa03 = {
  2,
  {
    { -24, -44, 0, 261 },
    { -16, -12, 0, 262 }
  }
};
static sprite_pattern goa04 = {
  2,
  {
    { -16, -44, 8, 259 },
    { -16, -12, 0, 262 }
  }
};
static sprite_pattern goa05 = {
  1,
  { { -20, -28, 0, 263 } }
};
