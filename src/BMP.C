#ifndef BMP_C
#define BMP_C

typedef struct Bmp;

struct Bmp
{
  unsigned char xs;
  unsigned char ys;
  unsigned char ofs;
};

Bmp SprBmp[700];

#endif
