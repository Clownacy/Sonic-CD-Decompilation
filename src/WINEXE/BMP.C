#include <windows.h>
#include "DECOMPRESS.H"
#include "DINO2D.H"
#include "TYPES.H"

typedef struct sprMeta {
  short x;
  short y;
  short width;
  short height;
  short paletteOffset;
  short magic;
}
sprMeta;

extern void showCustomError(int id, char* pMsg);
extern game_info gKeepWork;


// 0040c650
int extractTiles(void** ppBmpHandles, int* pBmpCnt, char* fileName) {
  int local_5c = 0;
  int local_58 = 0;
  int local_54 = 0;
  int local_50 = 0;
  int local_14 = 0;
  int local_10 = 0;
  int local_4c = 0;
  int local_48 = 0;
  int width = 0;
  int height = 0;
  UCHAR paletteOffset = 0;
  int paletteLine = 0;
  short remainingTileCnt = 0;
  cmpHeader header;
  char* pExtracted;
  int err;
  void** pBmpHandles;
  short* pCntPerPalette;
  short (*pDimensions)[2];
  char* pBmpData;
  char* pBmpBuffer;
  int i;
  int* local_6c;
  int local_1c;
  *ppBmpHandles = 0;
  *pBmpCnt = 0;
  err = lzDecompress(&header, &pExtracted, fileName);
  if (err != 0) {
    showCustomError(err, fileName);
    return err;
  }
  pBmpHandles = (void**)GlobalLock(GlobalAlloc(GPTR, header.cnt * 4));
  if (pBmpHandles == 0) {
    GlobalUnlock(GlobalHandle(pExtracted));
    GlobalFree(GlobalHandle(pExtracted));
    showCustomError(2, 0);
    return 2;
  }
  pCntPerPalette = (short*)pExtracted;
  pDimensions = (short(*)[2])(pExtracted + 8);
  pBmpData = &pExtracted[header.pData - sizeof(header)];
  pBmpBuffer = 0;
  err = 0;

  for (i = 0; i < header.cnt; ++i) {
    --remainingTileCnt;
    if (remainingTileCnt <= 0) {
      do {
        remainingTileCnt = pCntPerPalette[paletteLine];
        ++paletteLine;
      }
      while (remainingTileCnt == 0);

      switch (paletteLine) {
        case 1:
          paletteOffset = 0x10;
          break;
        case 2:
          paletteOffset = 0x20;
          break;
        case 3:
          paletteOffset = 0x30;
          break;
        case 4:
          paletteOffset = 0x40;
          break;
      }
    }
    err = _hbmpCreate(pDimensions[i][0], pDimensions[i][1], 0, &pBmpHandles[i]);
    if (err != 0) break;
    _hbmpGetLockedBuffer(pBmpHandles[i], (void**)&pBmpBuffer, &local_6c);
    expandBitmap(pBmpBuffer, pBmpData, pDimensions[i][0], pDimensions[i][1], paletteOffset, 0, 0);
    width = pDimensions[i][0];
    height = pDimensions[i][1];
    local_1c = width;
    err = _hbmpReleaseBuffer(pBmpHandles[i]);
    if (err != 0) break;
    err = _hbmpSetTransparencyColor(pBmpHandles[i], 0);
    if (err != 0) break;
    pBmpBuffer = 0;
    pBmpData += pDimensions[i][1] * pDimensions[i][0] / 2;
  }

  GlobalUnlock(GlobalHandle(pExtracted));
  GlobalFree(GlobalHandle(pExtracted));
  if (err != 0) {
    GlobalUnlock(GlobalHandle(pBmpHandles));
    GlobalFree(GlobalHandle(pBmpHandles));
    showCustomError(3, err);
  }
  else {
    *pBmpCnt = header.cnt;
    *ppBmpHandles = pBmpHandles;
  }

  return err;
}



// 0040c9b6
int extractRotatingTiles(void** ppBmpHandles, int* pBmpCnt, char* fileName) {
  int local_5c = 0;
  int local_58 = 0;
  int local_54 = 0;
  int local_50 = 0;
  int local_14 = 0;
  int local_10 = 0;
  int local_4c = 0;
  int local_48 = 0;
  int width = 0;
  int height = 0;
  UCHAR paletteOffset = 0;
  int paletteLine = 0;
  short remainingTileCnt = 0;
  cmpHeader header;
  char* pExtracted;
  int err;
  void** pBmpHandles;
  short* pCntPerPalette;
  short (*pDimensions)[2];
  char* pBmpData;
  char* pBmpBuffer;
  int i;
  int j;
  int* local_6c;
  int local_1c;
  *ppBmpHandles = 0;
  *pBmpCnt = 0;
  err = lzDecompress(&header, &pExtracted, fileName);
  if (err != 0) {
    showCustomError(err, fileName);
    return err;
  }
  pBmpHandles = (void**)GlobalLock(GlobalAlloc(GPTR, header.cnt * 8));
  if (pBmpHandles == 0) {
    GlobalUnlock(GlobalHandle(pExtracted));
    GlobalFree(GlobalHandle(pExtracted));
    showCustomError(2, 0);
    return 2;
  }
  pCntPerPalette = (short*)pExtracted;
  pDimensions = (short(*)[2])(pExtracted + 8);
  pBmpData = &pExtracted[header.pData - sizeof(header)];
  pBmpBuffer = 0;
  err = 0;

  for (i = 0; i < header.cnt; ++i) {
    --remainingTileCnt;
    if (remainingTileCnt <= 0) {
      do {
        remainingTileCnt = pCntPerPalette[paletteLine];
        ++paletteLine;
      }
      while (remainingTileCnt == 0);

      switch (paletteLine) {
        case 1:
          paletteOffset = 0x10;
          break;
        case 2:
          paletteOffset = 0x20;
          break;
        case 3:
          paletteOffset = 0x30;
          break;
        case 4:
          paletteOffset = 0x40;
          break;
      }
    }

    for (j = 0; i < 2; ++i) {
      err = _hbmpCreate(pDimensions[i][0], pDimensions[i][1], 0, &pBmpHandles[j + i * 2]);
      if (err != 0) break;
      _hbmpGetLockedBuffer(pBmpHandles[j + i * 2], (void**)&pBmpBuffer, &local_6c);
      expandBitmap(pBmpBuffer, pBmpData, pDimensions[i][0], pDimensions[i][1], paletteOffset, 0, 0);
      if (j == 1) {
        FUN_0040c521(pBmpBuffer, pDimensions[i][0], pDimensions[i][1]);
      }
      width = pDimensions[i][0];
      height = pDimensions[i][1];
      local_1c = width;
      err = _hbmpReleaseBuffer(pBmpHandles[j + i * 2]);
      if (err != 0) break;
      err = _hbmpSetTransparencyColor(pBmpHandles[j + i * 2], 0);
      if (err != 0) break;
    }

    if (err != 0) break;
    pBmpBuffer = 0;
    pBmpData += pDimensions[i][1] * pDimensions[i][0] / 2;
  }

  GlobalUnlock(GlobalHandle(pExtracted));
  GlobalFree(GlobalHandle(pExtracted));
  if (err != 0) {
    GlobalUnlock(GlobalHandle(pBmpHandles));
    GlobalFree(GlobalHandle(pBmpHandles));
    showCustomError(3, err);
  }
  else {
    *pBmpCnt = header.cnt;
    *ppBmpHandles = pBmpHandles;
  }

  return err;
}


// 0040cd8a
int FUN_0040cd8a(void** ppBmpHandles, short width, short height) {
  int local_30 = 0;
  int local_2c = 0;
  int local_28 = 0;
  int local_24 = 0;
  int local_c = 0;
  int local_8 = 0;
  int local_20 = 0;
  int local_1c = 0;
  int local_18 = 0;
  int local_14 = 0;
  void** pBmpHandles;
  int err;
  char* pBmpBuffer;
  int* local_3c;
  int i;
  *ppBmpHandles = 0;
  pBmpHandles = (void**)GlobalLock(GlobalAlloc(GPTR, 4));
  if (pBmpHandles == 0) {
    showCustomError(2, 0);
    return 2;
  }

  do {
    err = _hbmpCreate(width, height, 0, pBmpHandles);
    if (err != 0) break;
    _hbmpGetLockedBuffer(pBmpHandles[0], (void**)&pBmpBuffer, &local_3c);

    for (i = 0; i < height * width; ++i) {
      pBmpBuffer[i] = 0x30;
    }

    local_18 = width;
    local_14 = height;
    err = _hbmpReleaseBuffer(pBmpHandles[0]);
    if (err != 0) break;
    err = _hbmpSetTransparencyColor(pBmpHandles[0], 0);
    if (err != 0) break;
    break;
  }
  while (1);

  if (err != 0) {
    GlobalUnlock(GlobalHandle(pBmpHandles));
    GlobalFree(GlobalHandle(pBmpHandles));
    showCustomError(3, err);
  }
  else {
    *ppBmpHandles = pBmpHandles;
  }

  return err;
}


// 0040cf2e
void freeSingleBmpHandle(void** ppBmpHandles) {
  if (*ppBmpHandles != 0) {
    _hbmpDelete(*ppBmpHandles);
  }
  GlobalUnlock(GlobalHandle(ppBmpHandles));
  GlobalFree(GlobalHandle(ppBmpHandles));

  return;
}


// 0040cf78
int freeBmpHandles(void** ppBmpHandles, int cnt) {
  int ret = 0;
  int i;

  for (i = 0; i < cnt; ++i) {
    if (ppBmpHandles[i] != 0) {
      _hbmpDelete(ppBmpHandles[i]);
    }
  }

  GlobalUnlock(GlobalHandle(ppBmpHandles));
  GlobalFree(GlobalHandle(ppBmpHandles));

  return ret;
}


// 0040cff7
int extractSprites(void** ppBmpHandles, int* pBmpCnt, char* fileName) {
  int local_54 = 0;
  int local_50 = 0;
  int local_4c = 0;
  int local_48 = 0;
  int local_c = 0;
  int local_8 = 0;
  int local_44 = 0;
  int local_40 = 0;
  int width = 0;
  int height = 0;
  void* pBmpHandle;
  int err;
  cmpHeader header;
  char* pExtracted;
  void** pBmpHandles;
  sprMeta* pMeta;
  char* pBmpData;
  int i;
  BOOL hasPadding;
  char* pBmpBuffer;
  int* local_60;
  int local_18;
  err = _sprCreate(&pBmpHandle);
  if (err != 0) {
    showCustomError(3, err);
    return err;
  }
  err = lzDecompress(&header, &pExtracted, fileName);
  if (err != 0) {
    _sprDelete(pBmpHandle);
    showCustomError(err, fileName);
    return err;
  }
  pBmpHandles = (void**)GlobalLock(GlobalAlloc(GPTR, header.cnt * 4));
  if (pBmpHandles == 0) {
    GlobalUnlock(GlobalHandle(pExtracted));
    GlobalFree(GlobalHandle(pExtracted));
    showCustomError(2, 0);
    return 2;
  }
  pMeta = (sprMeta*)pExtracted;
  pBmpData = &pExtracted[header.pData - sizeof(header)];

  for (i = 0; i < header.cnt; ++i) {
    err = _hbmpCreate(pMeta[i].width, pMeta[i].height, 0, &pBmpHandles[i]);
    if (err != 0) break;
    err = _hbmpSetTransparencyColor(*pBmpHandles, 0xFF);
    if (err != 0) break;
    hasPadding = FALSE;
    if (pMeta[i].width & 4) {
      pMeta[i].width += 4;
      hasPadding = TRUE;
    }
    _hbmpGetLockedBuffer(pBmpHandles[i], (void**)&pBmpBuffer, &local_60);
    if (pBmpBuffer == 0) {
      GlobalUnlock(GlobalHandle(pExtracted));
      GlobalFree(GlobalHandle(pExtracted));
      GlobalUnlock(GlobalHandle(pBmpHandles));
      GlobalFree(GlobalHandle(pBmpHandles));
      showCustomError(2, 0);
      return 2;
    }
    expandBitmap(pBmpBuffer, pBmpData, pMeta[i].width, pMeta[i].height, pMeta[i].paletteOffset, 1, hasPadding);
    pBmpData += pMeta[i].width * pMeta[i].height / 2;
    if (hasPadding) {
      pMeta[i].width -= 4;
    }
    width = pMeta[i].width;
    height = pMeta[i].height;
    ((UCHAR*)gKeepWork.pSprBmp)[i * 3] = pMeta[i].width;
    ((UCHAR*)gKeepWork.pSprBmp)[i * 3 + 1] = pMeta[i].height;
    local_18 = (width + 3) / 4 * 4;
    err = _hbmpReleaseBuffer(pBmpHandles[i]);
    if (err != 0) break;
    err = _hbmpSetTransparencyColor(pBmpHandles[i], 0xFF);
    if (err != 0) break;
    err = _sprSetData(pBmpHandle, pBmpHandles[i]);
    if (err != 0) break;
  }

  GlobalUnlock(GlobalHandle(pExtracted));
  GlobalFree(GlobalHandle(pExtracted));
  if (err != 0) {
    GlobalUnlock(GlobalHandle(pBmpHandles));
    GlobalFree(GlobalHandle(pBmpHandles));
    showCustomError(3, err);
  }
  else {
    *pBmpCnt = header.cnt;
    *ppBmpHandles = pBmpHandles;
  }
  _sprDelete(pBmpHandle);
  return err;
}


// 0040d46c
int freeBmpHandlesDupe(void**ppBmpHandles, int cnt) {
  int ret = 0;
  int i;

  for (i = 0; i < cnt; ++i) {
    if (ppBmpHandles[i] != 0) {
      _hbmpDelete(ppBmpHandles[i]);
    }
  }

  GlobalUnlock(GlobalHandle(ppBmpHandles));
  GlobalFree(GlobalHandle(ppBmpHandles));

  return ret;
}
