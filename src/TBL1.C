unsigned char bariachg0[8] = { 1, 1, 0, 2, 0, 3, 0, -1 };
unsigned char bariachg1[6] = { 5, 4, 5, 6, 7, -1 };
unsigned char bariachg2[26] = {
   0,  4,  4,
   0,  4,  4,
   0,  5,  5,
   0,  5,  5,
   0,  6,  6,
   0,  6,  6,
   0,  7,  7,
   0,  7,  7,
   0, -1
};
unsigned char bariachg3[26] = {
   0,  4,  4,  0,  4,  0,
   0,  5,  5,  0,  5,  0,
   0,  6,  6,  0,  6,  0,
   0,  7,  7,  0,  7,  0,
   0, -1
};
unsigned char bariachg4[26] = {
   0,  4,  0,  0,  4,  0,
   0,  5,  0,  0,  5,  0,
   0,  6,  0,  0,  6,  0,
   0,  7,  0,  0,  7,  0,
   0, -1
};
unsigned char bariachg5[12] = {
   0,  8,  9, 10, 11, 12,
   11, 10, 9,  8,  0, -1
};
unsigned char bariachg6[57] = {
   0,  8,  8,  0,  8,  8,
   0,  9,  9,  0,  9,  9,
   0, 10, 10,  0, 10, 10,
   0, 11, 11,  0, 11, 11,
   0, 12, 12,  0, 12, 12,
   0, 11, 11,  0, 11, 11,
   0, 10, 10,  0, 10, 10,
   0,  9,  9,  0,  9,  9,
   0,  8,  8,  0,  8,  8,
   0,  0, -1
};
unsigned char bariachg7[57] = {
   0,  8,  8,  0,  8,  0,
   0,  9,  9,  0,  9,  0,
   0, 10, 10,  0, 10,  0,
   0, 11, 11,  0, 11,  0,
   0, 12, 12,  0, 12,  0,
   0, 11, 11,  0, 11,  0,
   0, 10, 10,  0, 10,  0,
   0,  9,  9,  0,  9,  0,
   0,  8,  8,  0,  8,  0,
   0,  0, -1
};
unsigned char bariachg8[57] = {
   0,  8,  0,  0,  8,  0,
   0,  9,  0,  0,  9,  0,
   0, 10,  0,  0, 10,  0,
   0, 11,  0,  0, 11,  0,
   0, 12,  0,  0, 12,  0,
   0, 11,  0,  0, 11,  0,
   0, 10,  0,  0, 10,  0,
   0,  9,  0,  0,  9,  0,
   0,  8,  0,  0,  8,  0,
   0,  0, -1
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
spr_array bar00 = {
  .cnt = 1,
  .spra = {
    { -24, -24, 0, 0 }
  }
};
spr_array bar01 = {
  .cnt = 1,
  .spra = {
    { -24, -24, 0, 213 }
  }
};
spr_array bar02 = {
  .cnt = 1,
  .spra = {
    { -24, -24, 0, 214 }
  }
};
spr_array bar03 = {
  .cnt = 1,
  .spra = {
    { -24, -24, 0, 215 }
  }
};
spr_array bar04 = {
  .cnt = 2,
  .spra = {
    { -24, -24,  0, 216 },
    {   0, -24, 24, 216 }
  }
};
spr_array bar05 = {
  .cnt = 2,
  .spra = {
    {   0, -24,  8, 216 },
    { -24, -24, 16, 216 }
  }
};
spr_array bar06 = {
  .cnt = 2,
  .spra = {
    { -24, -24,  0, 217 },
    { -24, -24, 24, 217 }
  }
};
spr_array bar07 = {
  .cnt = 2,
  .spra = {
    {   0, -24,  8, 217 },
    { -24, -24, 16, 217 }
  }
};
spr_array bar08 = {
  .cnt = 1,
  .spra = {
    { -16, -16, 0, 218 }
  }
};
spr_array bar09 = {
  .cnt = 1,
  .spra = {
    { -16, -16, 0, 219 }
  }
};
spr_array bar0a = {
  .cnt = 1,
  .spra = {
    { -24, -24, 0, 220 }
  }
};
spr_array bar0b = {
  .cnt = 1,
  .spra = {
    { -16, -16, 0, 221 }
  }
};
spr_array bar0c = {
  .cnt = 1,
  .spra = {
    { -16, -12, 0, 222 }
  }
};
spr_array* bariapat[13] = {
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
unsigned char exit2chg0[7] = { 3, 0, 4, 3, 1, 2, -4 };
unsigned char exit2chg1[5] = { 3, 0, 1, 2, -4 };
unsigned char exit2chg2[5] = { 3, 6, 0, 5, -4 };
unsigned char* exit2chg[3] = {
  exit2chg0,
  exit2chg1,
  exit2chg2
};
spr_array exi00 = {
  .cnt = 1,
  .spra = {
    { -16, -32, 0, 223 }
  }
};
spr_array exi01 = {
  .cnt = 1,
  .spra = {
    { -16, -32, 0, 224 }
  }
};
spr_array exi02 = {
  .cnt = 1,
  .spra = {
    { -16, -32, 0, 225 }
  }
};
spr_array exi03 = {
  .cnt = 1,
  .spra = {
    { -16, -48, 0, 226 }
  }
};
spr_array exi04 = {
  .cnt = 1,
  .spra = {
    { -16, -64, 0, 227 }
  }
};
spr_array exi05 = {
  .cnt = 1,
  .spra = {
    { -16, -32, 0, 228 }
  }
};
spr_array exi06 = {
  .cnt = 1,
  .spra = {
    { -16, -32, 0, 228 }
  }
};
spr_array* exit2pat[7] = {
  &exi00,
  &exi01,
  &exi02,
  &exi03,
  &exi04,
  &exi05,
  &exi06
};
unsigned char futachg0[12] = {
   0,  0,  0,  1,
   1,  1,  1,  1,
   1,  1,  1, -4
};
unsigned char* futachg[1] = { futachg0 };
spr_array fut00 = {
  .cnt = 1,
  .spra = {
    { -24, -8, 0, 231 }
  }
};
spr_array fut01 = {
  .cnt = 1,
  .spra = {
    { -28, -48, 0, 230 }
  }
};
spr_array* futapat[2] = {
  &fut00,
  &fut01
};
unsigned char mizukichg0[5] = { 3, 0, 1, 2, -4 };
unsigned char* mizukichg[1] = { mizukichg0 };
spr_array miz00 = {
  .cnt = 1,
  .spra = {
    { -16, -16, 0, 232 }
  }
};
spr_array miz01 = {
  .cnt = 1,
  .spra = {
    { -12, -12, 0, 233 }
  }
};
spr_array miz02 = {
  .cnt = 1,
  .spra = {
    { -8, -8, 0, 234 }
  }
};
spr_array* mizukipat[3] = {
  &miz00,
  &miz01,
  &miz02
};
unsigned char baku_chg0[7] = { 3, 0, 5, 6, 3, 4, -4 };
unsigned char baku_chg1[7] = { 3, 0, 1, 2, 3, 4, -4 };
unsigned char* bakuchg[2] = {
  baku_chg0, baku_chg1
};
spr_array bak00 = {
  .cnt = 1,
  .spra = {
    { -16, -8, 0, 235 }
  }
};
spr_array bak01 = {
  .cnt = 1,
  .spra = {
    { -16, -16, 0, 236 }
  }
};
spr_array bak02 = {
  .cnt = 1,
  .spra = {
    { -16, -16, 0, 237 }
  }
};
spr_array bak03 = {
  .cnt = 1,
  .spra = {
    { -24, -24, 0, 238 }
  }
};
spr_array bak04 = {
  .cnt = 1,
  .spra = {
    { -24, -24, 0, 239 }
  }
};
spr_array bak05 = {
  .cnt = 1,
  .spra = {
    { -16, -16, 0, 240 }
  }
};
spr_array bak06 = {
  .cnt = 1,
  .spra = {
    { -16, -16, 0, 241 }
  }
};
spr_array* bakupat[7] = {
  &bak00,
  &bak01,
  &bak02,
  &bak03,
  &bak04,
  &bak05,
  &bak06
};
unsigned char mkchg[4] = { 3, 2, 3, -1 };
unsigned char* markerchg[1] = { mkchg };
spr_array pat00 = {
  .cnt = 1,
  .spra = {
    { -8, -24, 0, 242 }
  }
};
spr_array pat01 = {
  .cnt = 1,
  .spra = {
    { -8, -8, 0, 243 }
  }
};
spr_array pat02 = {
  .cnt = 1,
  .spra = {
    { -8, -8, 0, 244 }
  }
};
spr_array pat03 = {
  .cnt = 1,
  .spra = {
    { -8, -8, 0, 245 }
  }
};
spr_array* markerpat[4] = {
  &pat00,
  &pat01,
  &pat02,
  &pat03
};
unsigned char bringchg0[6] = { 7, 0, 1, 2, 3, -1 };
spr_array big00 = {
  .cnt = 1,
  .spra = {
    { -32, -32, 0, 232 }
  }
};
spr_array big01 = {
  .cnt = 1,
  .spra = {
    { -24, -32, 0, 233 }
  }
};
spr_array big02 = {
  .cnt = 1,
  .spra = {
    { -12, -32, 0, 234 }
  }
};
spr_array big03 = {
  .cnt = 1,
  .spra = {
    { -24, -32, 8, 235 }
  }
};
spr_array* bigringpat[4] = {
  &big00,
  &big01,
  &big02,
  &big03
};
unsigned char goalchg0[11] = { 1, 0, 1, 2, 4, 3, 3, 1, 2, 4, -1 };
spr_array goa00 = {
  .cnt = 2,
  .spra = {
    { -24, -44, 0, 258 },
    { -16, -12, 0, 262 }
  }
};
spr_array goa01 = {
  .cnt = 2,
  .spra = {
    { -16, -44, 0, 259 },
    { -16, -12, 0, 262 }
  }
};
spr_array goa02 = {
  .cnt = 2,
  .spra = {
    { -4, -44, 0, 260 },
    { -16, -12, 0, 262 }
  }
};
spr_array goa03 = {
  .cnt = 2,
  .spra = {
    { -24, -44, 0, 261 },
    { -16, -12, 0, 262 }
  }
};
spr_array goa04 = {
  .cnt = 2,
  .spra = {
    { -16, -44, 8, 259 },
    { -16, -12, 0, 262 }
  }
};
spr_array goa05 = {
  .cnt = 1,
  .spra = {
    { -20, -28, 0, 263 }
  }
};
