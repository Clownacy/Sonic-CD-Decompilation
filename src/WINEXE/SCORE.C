#include "SCORE.H"
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include "TYPES.H"


// 0040f590
int FUN_0040f590(char character) {
  return 0;
}


// 0040f5a2
void retrieveDataFilePath(char* pPath) {
  char path[260];
  char fileName[16];
  int unknown;

  GetPrivateProfileString("Directory", "Install", "", path, 260, "SONIC.INI");
  GetPrivateProfileString("DataFile", "FileName", "", fileName, 16, "SONIC.INI");
  strcat(pPath, path);
  unknown = FUN_004115d0(pPath);
  if (pPath[unknown - 1] != '\\') {
    strcat(pPath, "\\");
  }
  else if (FUN_0040f590(pPath[unknown - 2]) != 0) {
    strcat(pPath, "\\");
  }
  strcat(pPath, fileName);

  return;
}


// 0040f686
void garbleScoreData(BYTE* pSource, BYTE* pDestination, ULONG size) {
  int i;

  srand(1361);
  for (i = 0; i < (int)size; ++i, ++pDestination, ++pSource) {
    *pDestination = abs(abs(rand()) & 0xff) ^ *pSource;
  }
}


// 0040f6e4
void garbleScoreDataDelegate(BYTE* pSource, BYTE* pDestination, ULONG size) {
  garbleScoreData(pSource, pDestination, size);
}


// 0040f703
BOOL verifyScoreDataChecksum(BYTE* pScoreData) {
  int checksum = 0;
  unsigned int i;

  for (i = 0; i < 716; ++i) {
    checksum += (char)*pScoreData++;
  }

  if (*(int*)pScoreData == checksum) {
    return TRUE;
  }
  else {
    return FALSE;
  }
}


// 0040f769
void updateScoreDataChecksum(BYTE* pScoreData) {
  int checksum = 0;
  unsigned int i;

  for (i = 0; i < 716; ++i) {
    checksum += (char)*pScoreData++;
  }

  *(int*)pScoreData = checksum;
}


// 0040f7b3
BOOL __stdcall ReadScoreData(int index, score_data* pOldScoreData, HFILE hExistingFile) {
  char path[256];
  score_data* pScoreData;
  int i;
  int oldIndex;
  HFILE hFile;

  if (pOldScoreData == 0) {
    pScoreData = &gCrntScorData;
  }
  else {
    pScoreData = pOldScoreData;
  }
  if (hExistingFile == 0) {
    retrieveDataFilePath(path);
    hFile = _lopen(path, OF_READ);
    if (hFile == -1) {
      goto error;
    }
  }
  else {
    hFile = hExistingFile;
  }
  if (_hread(hFile, &oldIndex, 4) == -1) {
    goto error;
  }

  for (i = 0; i < index; ++i) {
    if (_hread(hFile, pScoreData, 720) == -1) {
      goto error;
    }
  }

  if (_hread(hFile, pScoreData, 720) == -1) {
    goto error;
  }
  garbleScoreDataDelegate((BYTE*)pScoreData, (BYTE*)pScoreData, 720);
  if (verifyScoreDataChecksum((BYTE*)pScoreData) == 0) {
    goto error;
  }
  if (hExistingFile == 0) {
    _lclose(hFile);
  }
  if (pScoreData->saved == 0) {
    initScoreData(pScoreData, index);
  }
  return TRUE;

error:
  if (hExistingFile == 0 && hFile != -1) {
    _lclose(hFile);
  }
  initScoreData(&gCrntScorData, index);
  return FALSE;
}


// 0040f93f
void __stdcall SetScoreDate(score_data* pScoreData) {
  time_t currentTime;
  struct tm* pCalendarTime;

  if (pScoreData == 0) {
    pScoreData = &gCrntScorData;
  }
  time(&currentTime);
  pCalendarTime = localtime(&currentTime);
  pScoreData->year = pCalendarTime->tm_year + 1900;
  pScoreData->month = pCalendarTime->tm_mon + 1;
  pScoreData->date = pCalendarTime->tm_mday;
  pScoreData->hour = pCalendarTime->tm_hour;
  pScoreData->min = pCalendarTime->tm_min;
  pScoreData->sec = pCalendarTime->tm_sec;

  return;
}


// 0040f9d3
BOOL __stdcall WriteScoreData(int index, score_data* pNewScoreData, HFILE hExistingFile) {
  char path[256];
  score_data* pScoreData;
  int i;
  int readIndex;
  HFILE hFile;
  score_data readScoreData;

  if (pNewScoreData == 0) {
    pScoreData = &gCrntScorData;
  }
  else {
    pScoreData = pNewScoreData;
  }
  if (hExistingFile == 0) {
    retrieveDataFilePath(path);
    hFile = _lopen(path, OF_READWRITE);
    if (hFile == -1) {
      goto error;
    }
  }
  else {
    hFile = hExistingFile;
  }
  if (_hread(hFile, &readIndex, 4) == -1) {
    goto error;
  }
  for (i = 0; i < index; ++i) {
    if (_hread(hFile, &readScoreData, 720) == -1) {
      goto error;
    }
  }
  updateScoreDataChecksum((BYTE*)pScoreData);
  garbleScoreData((BYTE*)pScoreData, (BYTE*)&readScoreData, 720);
  if (_hwrite(hFile, (LPCCH)&readScoreData, 720) == -1) {
    goto error;
  }
  if (hExistingFile == 0) {
    _lclose(hFile);
  }
  return TRUE;

error:
  MessageBox(0, "Save Data Error!\nPlease install SONIC CD again.", "Sonic Error", MB_ICONSTOP);
  if (hExistingFile == 0 && hFile != -1) {
    _lclose(hFile);
  }
  return FALSE;
}


// 0040fb7b
HFILE __stdcall OpenScoreData(int mode) {
  char path[256];

  retrieveDataFilePath(path);
  return _lopen(path, mode);
}


// 0040fbb3
void __stdcall CloseScoreData(HFILE hFile) {
  _lclose(hFile);

  return;
}


// 0040fbcf
HFILE __stdcall CreateScoreData(void) {
  char path[256];

  retrieveDataFilePath(path);
  return _lcreat(path, 0);
}


// 0040fc03
int __stdcall ReadScoreIndx(HFILE hExistingFile) {
  char path[256];
  int index;
  HFILE hFile;

  if (hExistingFile == 0) {
    retrieveDataFilePath(path);
    hFile = _lopen(path, OF_READ);
    if (hFile == -1) {
      goto error;
    }
  }
  else {
    hFile = hExistingFile;
  }
  if (_hread(hFile, &index, 4) == -1) {
    goto error;
  }
  if (hExistingFile == 0) {
    _lclose(hFile);
  }
  gSelectIndx = index;
  return index;

error:
  if (hExistingFile == 0 && hFile != -1) {
    _lclose(hFile);
  }
  return -1;
}


BOOL __stdcall WriteScoreIndx(int index, HFILE hExistingFile) {
  char path[256];
  HFILE hFile;

  gSelectIndx = index;
  if (hExistingFile == 0) {
    retrieveDataFilePath(path);
    hFile = _lopen(path, OF_WRITE);
    if (hFile == -1) {
      goto error;
    }
  }
  else {
    hFile = hExistingFile;
  }
  if (_hwrite(hFile, (LPCCH)&gSelectIndx, 4) == -1) {
    goto error;
  }
  if (hExistingFile == 0) {
    _lclose(hFile);
  }
  return TRUE;

error:
  if (hExistingFile == 0 && hFile != -1) {
    _lclose(hFile);
  }
  return FALSE;
}


// 0040fd87
void __stdcall initScoreData(score_data* pScoreData, int index) {
  int round, zone, time;

  pScoreData->saved = 0;
  strncpy(pScoreData->player, "PLAYER_1    ", 12);
  pScoreData->player[7] = index + '1';
  pScoreData->roundNo = 0;
  pScoreData->year = 0;
  pScoreData->month = 0;
  pScoreData->date = 0;

  for (round = 0; round < 7; ++round) {
    for (zone = 0; zone < 3; ++zone) {
      for (time = 0; time < 3; ++time) {
        pScoreData->timeattack[round][zone][time].time = 18000;
        strcpy(pScoreData->timeattack[round][zone][time].name, "AAA");
      }
    }
  }

  for (round = 0; round < 7; ++round) {
    for (time = 0; time < 3; ++time) {
      pScoreData->special[round][time].time = 18000;
      strcpy(pScoreData->special[round][time].name, "AAA");
    }
  }

  pScoreData->total = 378000;
  pScoreData->clrspflg_save = 0;
  pScoreData->clrgood = 0;
  pScoreData->stagenm = 0;
  pScoreData->reserved1 = 0;
  pScoreData->reserved2 = 0;
  pScoreData->checkSum = 0;
}


// 0040ff5a
BOOL writeDefaultScoreDataFile(void) {
  HFILE hFile;
  int i;

  hFile = CreateScoreData();
  if (CreateScoreData() == -1) {
    return FALSE;
  }
  WriteScoreIndx(-1, hFile);

  for (i = 0; i < 6; ++i) {
    initScoreData(&gCrntScorData, i);
    WriteScoreData(i, &gCrntScorData, hFile);
  }

  return TRUE;
}


// 0040ffd8
BOOL readFirstScoreData(void) {
  int index;

  index = ReadScoreIndx(0);
  if (index != -1) {
    if (ReadScoreData(index, 0, 0) == FALSE) {
      index = -1;
    }
  }
  if (index == -1 || gCrntScorData.saved == 0) {
    initScoreData(&gCrntScorData, 0);
    return FALSE;
  }
  return TRUE;
}


// 0041004a
BOOL newScoreData(void) {
  int i;

  for (i = 0; i < 6; ++i) {
    if (ReadScoreData(i, 0, 0) == FALSE) {
      if (writeDefaultScoreDataFile() == FALSE) {
        initScoreData(&gCrntScorData, 0);
        SetScoreDate(&gCrntScorData);
        gCrntScorData.saved = 1;
        return TRUE;
      }
      i = 0;
    }
    if (gCrntScorData.saved == 0) {
      initScoreData(&gCrntScorData, i);
      SetScoreDate(&gCrntScorData);
      gCrntScorData.saved = 1;
      WriteScoreData(i, 0, 0);
      WriteScoreIndx(i, 0);
      break;
    }
  }

  if (i == 6) {
    return FALSE;
  }
  return TRUE;
}


// 00410130
void CALLBACK timeCallbackFunc(UINT uTimerID, UINT uMsg, ULONG dwUser, ULONG dw1, ULONG dw2) {
  ++*(ULONG*)dwUser;

  return;
}
