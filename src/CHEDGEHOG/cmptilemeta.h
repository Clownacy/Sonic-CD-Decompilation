#ifndef CMPTILEMETA_H
#define CMPTILEMETA_H

typedef struct cmp_tile_meta {
  unsigned short palette_line_cnt[4];
  unsigned short (*p_dimensions)[2];
}
cmp_tile_meta;

#endif
