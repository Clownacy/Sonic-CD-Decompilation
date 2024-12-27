#ifndef CMPHEADER_H
#define CMPHEADER_H

typedef struct cmp_header {
  char magic[4];
  unsigned long end_pos;
  unsigned long cnt;
  unsigned long data_pos;
}
cmp_header;

#endif
