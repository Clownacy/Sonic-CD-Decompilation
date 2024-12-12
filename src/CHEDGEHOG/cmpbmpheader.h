#ifndef CMPBMPHEADER_H
#define CMPBMPHEADER_H

typedef struct cmp_bmp_header {
  char magic[4];
  unsigned long end_pos;
  unsigned long cnt;
  unsigned long data_pos;
}
cmp_bmp_header;

#endif
