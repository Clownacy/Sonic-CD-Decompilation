#include <windows.h>

typedef struct pcmHeader {
  char descriptor[4];
  ULONG byteCnt;
  ULONG chunkCnt;
  ULONG dataOffset;
}
pcmHeader;

typedef struct waveInfo {
  BOOL busy;
  HWAVEOUT hWaveout;
  WAVEHDR waveHdr;
  HWND hWnd;
  int unknown44;
  int arraySize;
  int reqArray[1];
}
waveInfo;

/* 0042ce00 */ int gWaveDeviceCnt1;
/* 0042ce04 */ BYTE* gpPcmChunkStart;
/* 0042ce08 */ UINT* gpPcmChunkIndex;
/* 0042ce0c */ int gWaveDeviceCnt2;
/* 0042ce10 */ BYTE* gpPcmData;
/* 0042ce14 */ int gPcmDataChunkCnt;
/* 0042ce20 */ waveInfo gWaveInfos[6];
/* 00433318 */ BOOL gbBetterSoundQuality = FALSE;


// 0040d4f0
void* allocAndLockMemory(UINT flags, ULONG bytes) {
  HGLOBAL hGlobal = GlobalAlloc(flags & 65535, bytes);
  if (hGlobal == 0) {
    return 0;
  }
  else {
    return GlobalLock(hGlobal);
  }
}


// 0040d539
void freeLockedMemory(void* pLockedMemory) {
  HGLOBAL hMemory;
  if (pLockedMemory != 0) {
    hMemory = GlobalHandle(pLockedMemory);
    GlobalUnlock(hMemory);
    GlobalFree(hMemory);
  }
}


// 0040d572
int openWaveOut(HWND hWnd) {
  waveInfo* pWaveInfo;
  WAVEFORMATEX waveFormat;
  int i;
  pWaveInfo = gWaveInfos;
  waveFormat.wFormatTag = 1;
  waveFormat.nChannels = 1;
  if (gbBetterSoundQuality) {
    waveFormat.nSamplesPerSec = 22050;
    waveFormat.wBitsPerSample = 16;
  }
  else {
    waveFormat.nSamplesPerSec = 11025;
    waveFormat.wBitsPerSample = 8;
  }
  waveFormat.nBlockAlign = waveFormat.nChannels * waveFormat.wBitsPerSample / 8;
  waveFormat.nAvgBytesPerSec = waveFormat.nSamplesPerSec * waveFormat.nBlockAlign;

  for (i = 0; i < 6; ++i) {
    pWaveInfo[i].hWaveout = 0;
  }

  for (i = 0; i < 6; ++i, ++pWaveInfo) {
    pWaveInfo->busy = FALSE;
    pWaveInfo->unknown44 = -1;
    waveFormat.cbSize = waveOutOpen(&pWaveInfo->hWaveout, WAVE_MAPPER, &waveFormat, (DWORD)hWnd, 0, CALLBACK_WINDOW);
    if (waveFormat.cbSize != 0) break;
  }

  gWaveDeviceCnt1 = i;
  if (gWaveDeviceCnt1 != 6) {
    gWaveDeviceCnt2 = i;
  }
  else {
    gWaveDeviceCnt2 = 6;
  }
  if (gWaveDeviceCnt2 < 1) {
    return -1;
  }
  else {
    return 0;
  }
}


// 0040d6d3
void closeWaveOut() {
  waveInfo *pWaveInfo;
  int i;
  MMRESULT result;
  pWaveInfo = gWaveInfos;
  for (i = 0; i < gWaveDeviceCnt1; ++i, ++pWaveInfo) {
    if (pWaveInfo->hWaveout != 0) {
      result = waveOutClose(pWaveInfo->hWaveout);
      pWaveInfo->hWaveout = 0;
    }
  }
}


// 0040d735
int chkPcmFile(pcmHeader* pHeader, BYTE** ppPcmData, char* path) {
  HFILE hFile;
  ULONG byteCnt;
  hFile = _lopen(path, OF_READ);
  if (hFile == -1) {
    return 1;
  }
  if (_hread(hFile, pHeader, sizeof(*pHeader)) != sizeof(*pHeader)) {
    _lclose(hFile);
    return 1;
  }
  byteCnt = pHeader->byteCnt - sizeof(*pHeader);
  *ppPcmData = (BYTE*)allocAndLockMemory(GMEM_ZEROINIT, byteCnt);
  if (*ppPcmData == 0) {
    _lclose(hFile);
    return 2;
  }
  if (_hread(hFile, *ppPcmData, byteCnt) != byteCnt) {
    _lclose(hFile);
    return 1;
  }
  _lclose(hFile);

  return 0;
}


// 0040d814
int loadPcmFile(char* path) {
  int ret;
  pcmHeader header;
  ULONG start;
  int i;
  BYTE* pPcmData;
  gWaveDeviceCnt1 = waveOutGetNumDevs();
  gpPcmData = 0;
  gPcmDataChunkCnt = 0;
  memset(gWaveInfos, 0, sizeof(gWaveInfos));
  ret = chkPcmFile(&header, &gpPcmData, path);
  if (ret == 0) {
    gpPcmChunkIndex = (UINT*)allocAndLockMemory(GMEM_ZEROINIT, header.chunkCnt * 4);
    if (gpPcmChunkIndex == 0) {
      return -1;
    }
    gPcmDataChunkCnt = header.chunkCnt;
    gpPcmChunkStart = &gpPcmData[header.dataOffset - sizeof(header)];
    pPcmData = gpPcmData;
    start = 0;

    for (i = 0; i < gPcmDataChunkCnt; ++i) {
      gpPcmChunkIndex[i] = start;
      start += ((ULONG*)(pPcmData))[i];
    }
  }

  return ret;
}


// 0040d912
void freeWaveMemory() {
  if (gpPcmData != 0) {
    freeLockedMemory(gpPcmData);
    gpPcmData = 0;
  }
  if (gpPcmChunkIndex != 0) {
    freeLockedMemory(gpPcmChunkIndex);
    gpPcmChunkIndex = 0;
  }
}


// 0040d967
int getPcmDataChunkCount() {
  return gPcmDataChunkCnt;
}


// 0040d97c
BYTE* getPcmChunkInfo(int ReqNo, ULONG* pChunkSize) {
  *pChunkSize = ((ULONG*)gpPcmData)[ReqNo];
  return &gpPcmChunkStart[gpPcmChunkIndex[ReqNo]];
}


// 0040d9af
int playWaveRequest(HWND hWnd, waveInfo *pWaveInfo, int ReqNo) {
  ULONG chunkSize;
  int i;
  int counter;
  pWaveInfo->hWnd = hWnd;
  pWaveInfo->waveHdr.lpData = (LPSTR)getPcmChunkInfo(ReqNo, &chunkSize);
  pWaveInfo->waveHdr.dwBufferLength = chunkSize;
  pWaveInfo->waveHdr.dwFlags = 0;
  pWaveInfo->waveHdr.dwLoops = 0;
  pWaveInfo->waveHdr.dwUser = (DWORD)pWaveInfo;
  if (waveOutPrepareHeader(pWaveInfo->hWaveout, &pWaveInfo->waveHdr, sizeof(pWaveInfo->waveHdr)) != MMSYSERR_NOERROR) {
    return 2;
  }
  if (waveOutWrite(pWaveInfo->hWaveout, &pWaveInfo->waveHdr, sizeof(pWaveInfo->waveHdr)) != MMSYSERR_NOERROR) {
    waveOutUnprepareHeader(pWaveInfo->hWaveout, &pWaveInfo->waveHdr, sizeof(pWaveInfo->waveHdr));
    return 3;
  }

  for (i = 0, counter = i; i < gWaveDeviceCnt1; ++i) {
    if (gWaveInfos[i].busy) {
      ++counter;
    }
  }

  pWaveInfo->unknown44 = counter;
  pWaveInfo->busy = TRUE;

  return 0;
}


// 0040dac4
int FUN_0040dac4(int waveInfoIndex, int ReqNo, HWND hWnd, BOOL bUnknown) {
  waveInfo* pWaveInfo;
  if (gpPcmData == 0) {
    return -1;
  }
  if (ReqNo >= gPcmDataChunkCnt) {
    return -2;
  }
  pWaveInfo = &gWaveInfos[waveInfoIndex];
  if (pWaveInfo->busy) {
    if (!bUnknown) {
      return -3;
    }
    if (pWaveInfo->arraySize < 1) {
      pWaveInfo->reqArray[pWaveInfo->arraySize] = ReqNo;
      ++pWaveInfo->arraySize;
      waveOutReset(pWaveInfo->hWaveout);
      return 0;
    }
    else {
      return -4;
    }
  }

  return playWaveRequest(hWnd, pWaveInfo, ReqNo);
}


// 0040db94
int waveStop(int index) {
  if (gpPcmData == 0) {
    return -1;
  }
  if (gWaveInfos[index].busy) {
    gWaveInfos[index].arraySize = 0;
    waveOutReset(gWaveInfos[index].hWaveout);
  }

  return 0;
}


// 0040dc02
void WaveAllStop() {
  int i;
  for (i = 0; i < gWaveDeviceCnt2; ++i) {
    waveStop(i);
  }
}


// 0040dc3e
int wavePause(int waveIndex) {
  if (gpPcmData == 0) {
    return -1;
  }
  if (gWaveInfos[waveIndex].busy) {
    if (waveOutPause(gWaveInfos[waveIndex].hWaveout) == MMSYSERR_INVALHANDLE) {
      return 1;
    }
  }

  return 0;
}


// 0040dcaa
int waveRestart(int waveIndex) {
  if (gpPcmData == 0) {
    return -1;
  }
  if (gWaveInfos[waveIndex].busy) {
    if (waveOutRestart(gWaveInfos[waveIndex].hWaveout) == MMSYSERR_INVALHANDLE) {
      return 1;
    }
  }

  return 0;
}


// 0040dd16
int FUN_0040dd16(HWAVEOUT hWaveout, LPWAVEHDR pWaveHdr) {
  waveInfo *pWaveInfo;
  int i;
  int ReqNo;
  pWaveInfo = (waveInfo*)pWaveHdr->dwUser;
  waveOutUnprepareHeader(hWaveout, pWaveHdr, sizeof(*pWaveHdr));

  for (i = 0; i < gWaveDeviceCnt1; ++i) {
    if (pWaveInfo->unknown44 <= gWaveInfos[i].unknown44) {
      --gWaveInfos[i].unknown44;
    }
  }

  pWaveInfo->unknown44 = -1;
  pWaveInfo->busy = FALSE;
  if (pWaveInfo->arraySize != 0) {
    ReqNo = pWaveInfo->reqArray[--pWaveInfo->arraySize];
    return playWaveRequest(pWaveInfo->hWnd, pWaveInfo, ReqNo);
  }

  return 0;
}


// 0040dde6
int getFreeWaveInfoIndex() {
  int i;
  for (i = 0; i < gWaveDeviceCnt1; ++i) {
    if (gWaveInfos[i].busy == FALSE) break;
  }
  if (i == gWaveDeviceCnt1) {
    return -1;
  }
  else {
    return i;
  }
}


// 0040de58
int collectWaveInfoUnknown44(int* array) {
  int i;
  for (i = 0; i < gWaveDeviceCnt1; ++i) {
    array[i] = gWaveInfos[i].unknown44;
  }
  return i;
}


// 0040deaa
int areWaveInfosFree() {
  int i;
  for (i = 0; i < gWaveDeviceCnt1; ++i) {
    if (gWaveInfos[i].arraySize > 0) {
      return -1;
    }
    if (gWaveInfos[i].busy) {
      return -1;
    }
  }

  return 0;
}
