#ifndef DECOMPRESS_H
#define DECOMPRESS_H

typedef struct cmpHeader {
  char magic[4];
  int pEnd;
  int cnt;
  int pData;
}
cmpHeader;

int lzDecompress(cmpHeader* pHeader, char** ppAlloc, char* fileName);
void expandBitmap(char* pDest, char* pSrc, short width, short height, UCHAR param_5, int param_6, int param_7);
int FUN_0040c521(char* pSrc, short width, short height);

#endif
