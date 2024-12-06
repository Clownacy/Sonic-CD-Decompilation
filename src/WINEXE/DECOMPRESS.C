#include <windows.h>

// 0040c270
int lzDecompress(char* buffer, char** ppAlloc, char* fileName) {
  char path[128];
  OFSTRUCT ofStruct;
  int hFile;
  int hFile2;
  char* pAlloc;
  int i;
  char bytes[4];
  if (GetPrivateProfileString("Directory", "Play", "", path, sizeof(path), "sonic.ini")) {
    strcat(path, "\\");
    strcat(path, fileName);
  }
  else {
    strcat(path, fileName);
  }
  hFile = LZOpenFile(path, &ofStruct, OF_SHARE_DENY_NONE | OF_PROMPT);
  if (hFile == -1) {
    return 1;
  }
  hFile2 = LZInit(hFile);
  if (hFile2 < 0) {
    return -1;
  }
  if (LZRead(hFile2, buffer, 16) != 16) {
    LZClose(hFile2);
    return 1;
  }
  *ppAlloc = (char*)GlobalLock(GlobalAlloc(GPTR, ((UINT*)buffer)[1] - 16));
  if (*ppAlloc == 0) {
    LZClose(hFile2);
    return 2;
  }
  pAlloc = *ppAlloc;

  for (i = 0; i < ((UINT*)buffer)[1] - 16; ++i) {
    if (LZRead(hFile2, bytes, 1) != 1) {
      LZClose(hFile2);
      return 1;
    }
    *pAlloc = bytes[0];
    ++pAlloc;
  }

  LZClose(hFile2);

  return 0;
}


// 0040c428
void expandBitmap(UCHAR* pDest, UCHAR* pSrc, short width, short height, UCHAR param_5, int param_6, int param_7) {
  UCHAR* pCurrentDest = pDest;
  UCHAR* pCurrentSrc = pSrc;
  int y;
  int x;

  for (y = 0; y < height; ++y) {
    for (x = 0; x < width; ++x) {
      if (param_7 == 0 || width - 4 > x) {
        if (x & 1) {
          *pCurrentDest = (*pCurrentSrc & 0x0F) + param_5;
        }
        else {
          *pCurrentDest = ((*pCurrentSrc & 0xF0) >> 4) + param_5;
        }
        if (*pCurrentDest == param_5) {
          if (param_6 != 0) {
            *pCurrentDest = 0xFF;
          }
          else {
            *pCurrentDest = 0;
          }
        }
        ++pCurrentDest;
        if (x & 1) {
          ++pCurrentSrc;
        }
      }
    }
  }

  return;
}


// 0040c521
int FUN_0040c521(char* pSrc, short width, short height) {
  char* pAlloc = (char*)GlobalLock(GlobalAlloc(GPTR, height * width));
  char* pCurrentAlloc;
  char* pCurrentSrc;
  int i;
  int y;
  int x;
  if (pAlloc == 0) {
    return 2;
  }
  pCurrentAlloc = pAlloc;
  pCurrentSrc = pSrc;

  for (i = 0; i < height * width; ++i) {
    *pCurrentAlloc = *pCurrentSrc;
    ++pCurrentSrc;
    ++pCurrentAlloc;
  }

  pCurrentAlloc = pSrc;

  for (y = 0; y < height; ++y) {
    pCurrentSrc = &pAlloc[(height - 1) * width + y];

    for (x = 0; x < width; ++x) {
      *pCurrentAlloc = *pCurrentSrc;
      ++pCurrentAlloc;
      pCurrentSrc -= height;
    }
  }

  GlobalUnlock(GlobalHandle(pAlloc));
  GlobalFree(GlobalHandle(pAlloc));

  return 0;
}
