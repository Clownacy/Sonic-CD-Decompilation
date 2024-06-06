#ifndef TA_TYPES_H
#define TA_TYPES_H
typedef struct {
  unsigned char grid;
  unsigned char x;
  unsigned char y;
  unsigned char xs;
  unsigned char ys;
  unsigned short ofs;
  unsigned char transp;
  char* fn;
}
map_info;

typedef struct {
  map_info* info;
  int cnt;
}
map_infos;

typedef struct {
  unsigned int dwTyp;
  unsigned int dwSiz;
  unsigned int dwCnt;
  unsigned int dwOff;
}
bmp_header;

#endif
