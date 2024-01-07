typedef struct ld_pack_header {
  int type;
  int size;
  int count;
  int offset;
}
ld_pack_header;

typedef struct ld_sprite_inf {
  short xoff;
  short yoff;
  short wx;
  short wy;
  short palette;
  short reserved;
}
ld_sprite_inf;

typedef struct ld_sprite_header {
  ld_pack_header header;
  ld_sprite_inf spr[1];
}
ld_sprite_header;

typedef struct ld_bitmap_inf {
  short wx;
  short wy;
}
ld_bitmap_inf;

typedef struct ld_scroll_header {
  ld_pack_header header;
  short plt[4];
  ld_bitmap_inf bmp[1];
}
ld_scroll_header;
