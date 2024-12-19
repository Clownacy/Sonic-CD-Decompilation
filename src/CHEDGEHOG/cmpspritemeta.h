#ifndef CMPSPRITEMETA_H
#define CMPSPRITE

typedef struct cmp_sprite_meta {
  unsigned short x;
  unsigned short y;
  unsigned short width;
  unsigned short height;
  unsigned short palette_offset;
  unsigned short unknown;
}
cmp_sprite_meta;

#endif
