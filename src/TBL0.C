#include "TYPES.H"

#if defined (R31) || defined (R32)
  #define SPRITE_GENE_BASE 409
#elif defined (R33)
  #define SPRITE_GENE_BASE 413
#elif defined (R6)
  #define SPRITE_GENE_BASE 408
#elif defined (R81)
  #define SPRITE_GENE_BASE 393
#elif defined (R82)
  #define SPRITE_GENE_BASE 402
#elif defined (R83)
  #define SPRITE_GENE_BASE 395
#else
  #define SPRITE_GENE_BASE 299
#endif

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
sprite_pattern genepat0 = {
  1,
  { { -32, -32, 0, SPRITE_GENE_BASE } }
};
sprite_pattern genepat1 = {
  1,
  { { -32, -32, 0, SPRITE_GENE_BASE + 1 } }
};
sprite_pattern genepat2 = {
  1,
  { { -32, 8, 0, SPRITE_GENE_BASE + 2 } }
};
sprite_pattern genepat3 = {
  1,
  { { -16, -16, 0, SPRITE_GENE_BASE + 3 } }
};
sprite_pattern genepat4 = {
  1,
  { { -16, -16, 0, SPRITE_GENE_BASE + 4 } }
};
sprite_pattern genepat5 = {
  1,
  { { -16, -16, 0, SPRITE_GENE_BASE + 5 } }
};
sprite_pattern genepat6 = {
  1,
  { { -16, -16, 0, SPRITE_GENE_BASE + 6 } }
};
sprite_pattern genepat7 = {
  1,
  { { -16, -16, 0, SPRITE_GENE_BASE + 7 } }
};
sprite_pattern genepat8 = {
  1,
  { { -16, -16, 0, SPRITE_GENE_BASE + 8 } }
};
sprite_pattern* genepat[9] = {
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
sprite_pattern bringpat0 = {
  1,
  { { -32, -32, 0, 246 } }
};
sprite_pattern bringpat1 = {
  1,
  { { -24, -32, 0, 247 } }
};
sprite_pattern bringpat2 = {
  1,
  { { -12, -32, 0, 248 } }
};
sprite_pattern bringpat3 = {
  1,
  { { -24, -32, 0, 247 } }
};
sprite_pattern* bringpat[4] = {
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
sprite_pattern bring2pat0 = {
  1,
  { { -32, -32, 0, 250 } }
};
sprite_pattern bring2pat1 = {
  1,
  { { -32, -32, 0, 251 } }
};
sprite_pattern bring2pat2 = {
  1,
  { { -32, -32, 0, 252 } }
};
sprite_pattern bring2pat3 = {
  1,
  { { -32, -32, 0, 253 } }
};
sprite_pattern bring2pat4 = {
  1,
  { { -32, -32, 0, 254 } }
};
sprite_pattern bring2pat5 = {
  1,
  { { -32, -26, 0, 255 } }
};
sprite_pattern bring2pat6 = {
  1,
  { { -32, -32, 0, 256 } }
};
sprite_pattern bring2pat7 = {
  1,
  { { -32, -32, 0, 257 } }
};
sprite_pattern* bring2pat[8] = {
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
sprite_pattern goalsp0 = {
  1,
  { { -24, -44, 0, 258 } }
};
sprite_pattern goalsp1 = {
  1,
  { { -16, -44, 0, 259 } }
};
sprite_pattern goalsp2 = {
  1,
  { { -16, -44, 0, 260 } }
};
sprite_pattern goalsp3 = {
  1,
  { { -24, -44, 0, 261 } }
};
sprite_pattern goalsp4 = {
  1,
  { { -16, -44, 0, 262 } }
};
sprite_pattern goalsp5 = {
  1,
  { { -20, -28, 0, 263 } }
};
sprite_pattern* goalpat[6] = {
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
