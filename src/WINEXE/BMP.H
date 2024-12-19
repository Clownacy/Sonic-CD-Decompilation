#ifndef BMP_H
#define BMP_H

int extractTiles(void*** ppBmpHandles, int* pBmpCnt, char* fileName);
int extractRotatingTiles(void*** ppBmpHandles, int* pBmpCnt, char* fileName);
int FUN_0040cd8a(void** ppBmpHandles, short width, short height);
void freeSingleBmpHandle(void** ppBmpHandles);
int freeBmpHandles(void** ppBmpHandles, int cnt);
int extractSprites(void*** ppBmpHandles, int* pBmpCnt, char* fileName);
int freeBmpHandlesDupe(void**ppBmpHandles, int cnt);

#endif
