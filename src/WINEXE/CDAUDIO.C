#include <windows.h>
#include <string.h>

/* 00430370 */ ULONG DAT_00430370;
/* 00430374 */ HGLOBAL ghCdAudioTrackListMemory;
/* 00430378 */ DWORD gMciPlayFlags;
/* 0043037c */ ULONG gCdAudioTrackCnt;
/* 00430380 */ MCI_PLAY_PARMS gMciPlayParams;
/* 0043038c */ MCIDEVICEID gMciDeviceId;


// 00401000
void cdAudio_readMciErrorString(MCIERROR err, LPSTR errMsg, ULONG msgSize) {
  if (err == 0) {
    return;
  }
  else if (err == -1) {
    strncpy(errMsg, "Not Enough Memory!!", msgSize);
  }
  else if (err == -2) {
    strncpy(errMsg, "Track None!!", msgSize);
  }
  else if (err == -3) {
    strncpy(errMsg, "Illegal Track no!!", msgSize);
  }
  else {
    mciGetErrorString(err, errMsg, msgSize);
  }
}


// 0040109d
MCIERROR cdAudio_createTrackIndex(void) {
  MCIERROR err;
  MCI_STATUS_PARMS params;
  ULONG mediaLength;
  ULONG* pTrackList;
  int i;

  params.dwCallback = 0;
  params.dwItem = MCI_STATUS_NUMBER_OF_TRACKS;
  err = mciSendCommand(gMciDeviceId, MCI_STATUS, MCI_STATUS_ITEM, (DWORD)&params);
  if (err != 0) {
    return err;
  }

  gCdAudioTrackCnt = params.dwReturn;
  if (gCdAudioTrackCnt == 0) {
    return -2;
  }

  params.dwCallback = 0;
  params.dwItem = MCI_STATUS_LENGTH;
  err = mciSendCommand(gMciDeviceId, MCI_STATUS, MCI_STATUS_ITEM, (DWORD)&params);
  if (err != 0) {
    return err;
  }

  mediaLength = params.dwReturn;
  ghCdAudioTrackListMemory = GlobalAlloc(GMEM_MOVEABLE | GMEM_DDESHARE, (gCdAudioTrackCnt + 1) * 4);
  if (ghCdAudioTrackListMemory == 0) {
    return -1;
  }

  pTrackList = (ULONG*)GlobalLock(ghCdAudioTrackListMemory);

  for (i = 0; i < gCdAudioTrackCnt; ++i) {
    params.dwCallback = 0;
    params.dwItem = MCI_STATUS_POSITION;
    params.dwTrack = i + 1;
    err = mciSendCommand(gMciDeviceId, MCI_STATUS, MCI_STATUS_ITEM | MCI_TRACK, (DWORD)&params);
    if (err != 0) break;

    pTrackList[i] = params.dwReturn;
  }

  GlobalUnlock(ghCdAudioTrackListMemory);

  if (gCdAudioTrackCnt == i) {
    pTrackList[i] = pTrackList[0] + mediaLength;
    return 0;
  } else {
    return err;
  }
}


// 0040123d
MCIERROR cdAudio_open(LPSTR errMsg, ULONG msgSize) {
  MCI_OPEN_PARMS openParams;
  MCI_STATUS_PARMS statusParams;
  MCI_SET_PARMS setParams;
  char str[128];
  char drive[3];
  MCIERROR err = 0;

  DAT_00430370 = 0;
  openParams.dwCallback = 0;
  openParams.lpstrDeviceType = "cdaudio";

  GetPrivateProfileString("Directory", "Type", "FULL", str, sizeof(str), "sonic.ini");
  if (str[0] == 'M') {
    GetPrivateProfileString("Directory", "Play", "D:\\GAME", str, sizeof(str), "sonic.ini");
    drive[0] = str[0];
    drive[1] = ':';
    drive[2] = '\0';
    openParams.lpstrElementName = drive;
    err = mciSendCommand(0, MCI_OPEN, MCI_OPEN_SHAREABLE | MCI_OPEN_ELEMENT | MCI_OPEN_TYPE, (DWORD)&openParams);
  }
  else {
    drive[0] = GetPrivateProfileInt("Directory", "CD", 3, "sonic.ini") + 97;
    drive[1] = ':';
    drive[2] = '\0';
    openParams.lpstrElementName = drive;
    err = mciSendCommand(0, MCI_OPEN, MCI_OPEN_SHAREABLE | MCI_OPEN_ELEMENT | MCI_OPEN_TYPE, (DWORD)&openParams);
  }
  if (err != 0) {
    mciGetErrorString(err, errMsg, msgSize);
    return err;
  }

  gMciDeviceId = openParams.wDeviceID;
  statusParams.dwCallback = 0;
  statusParams.dwItem = MCI_STATUS_TIME_FORMAT;
  err = mciSendCommand(gMciDeviceId, MCI_STATUS, MCI_STATUS_ITEM, (DWORD)&statusParams);
  if (err != 0) {
    mciGetErrorString(err, errMsg, msgSize);
    return err;
  }

  if (statusParams.dwReturn != MCI_FORMAT_MSF) {
    setParams.dwCallback = 0;
    setParams.dwTimeFormat = MCI_FORMAT_MSF;
    err = mciSendCommand(gMciDeviceId, MCI_SET, MCI_WAIT | MCI_TO, (DWORD)&setParams);
    if (err != 0) {
      mciGetErrorString(err, errMsg, msgSize);
      return err;
    }
  }
  err = cdAudio_createTrackIndex();
  cdAudio_readMciErrorString(err, errMsg, msgSize);

  return err;
}


// 00401440
void cdAudio_close(void) {
  if (ghCdAudioTrackListMemory != 0) {
    GlobalFree(ghCdAudioTrackListMemory);
  }

  mciSendCommand(gMciDeviceId, MCI_CLOSE, MCI_WAIT, 0);
}


// 00401479
UINT cdAudio_getTrackCnt(void) {
  return gCdAudioTrackCnt;
}


// 0040148e
MCIERROR cdAudio_getMciMode(ULONG* mciMode) {
  MCIERROR err;
  MCI_STATUS_PARMS params;

  params.dwCallback = 0;
  params.dwItem = 4;
  err = mciSendCommand(gMciDeviceId, MCI_STATUS, MCI_STATUS_ITEM, (DWORD)&params);
  if (err == 0) {
    *mciMode = params.dwReturn;
  }

  return err;
}


// 004014e1
int cdAudio_setMciPlayParams(int trackId) {
  ULONG* pTrackList;

  if (trackId < 0 || gCdAudioTrackCnt <= trackId) {
    return -3;
  }

  pTrackList = (ULONG*)GlobalLock(ghCdAudioTrackListMemory);
  gMciPlayParams.dwFrom = pTrackList[trackId];
  gMciPlayParams.dwTo = pTrackList[trackId + 1];
  GlobalUnlock(ghCdAudioTrackListMemory);
  if (trackId + 1 == gCdAudioTrackCnt) {
    gMciPlayFlags = MCI_NOTIFY | MCI_FROM;
  }
  else {
    gMciPlayFlags = MCI_NOTIFY | MCI_FROM | MCI_TO;
  }

  return 0;
}


// 0040157a
MCIERROR cdAudio_play(void) {
  MCIERROR err = mciSendCommand(gMciDeviceId, MCI_PLAY, gMciPlayFlags & -5, (DWORD)&gMciPlayParams);
  return err;
}


// 004015b2
MCIERROR cdAudio_switchTrack(long trackId, BOOL bUnknown, HWND hWnd) {
  MCIERROR err;
  char errMsg[128];

  err = cdAudio_setMciPlayParams(trackId);
  if (err == 0) {
    DAT_00430370 = 0;
    gMciPlayParams.dwCallback = (DWORD)hWnd;
    mciSendCommand(gMciDeviceId, MCI_STOP, MCI_WAIT, 0);
    err = mciSendCommand(gMciDeviceId, MCI_PLAY, gMciPlayFlags, (DWORD)&gMciPlayParams);
    if (err != 0) {
      mciGetErrorString(err, errMsg, 128);
      MessageBox(0, errMsg, "CD Error", MB_ICONSTOP);
    }
    if (bUnknown) {
      DAT_00430370 |= 1;
    }
  }

  return err;
}


// 00401671
MCIERROR cdAudio_playIfStopped(void) {
  MCIERROR err = 0;

  if (DAT_00430370 & 2) {
    err = cdAudio_play();
    DAT_00430370 &= -3;
  }

  return err;
}


// 004016aa
MCIERROR cdAudio_stop(void) {
  ULONG mode;
  MCIERROR err;

  err = cdAudio_getMciMode(&mode);
  if (err != 0) {
    return err;
  }

  if (mode == MCI_MODE_PLAY) {;
    err = mciSendCommand(gMciDeviceId, MCI_STOP, 0, 0);
    if (err == 0) {
      DAT_00430370 |= 2;
    }
  }

  return err;
}


// 00401717
MCIERROR cdAudio_getCurrentTrackInfo(DWORD* trackId, DWORD* position) {
  MCIERROR err;
  MCI_STATUS_PARMS params;
  params.dwItem = MCI_STATUS_CURRENT_TRACK;
  err = mciSendCommand(gMciDeviceId, MCI_STATUS, MCI_STATUS_ITEM, (DWORD)&params);
  if (err != 0) {
    return err;
  }

  *trackId = params.dwReturn;
  params.dwItem = MCI_STATUS_POSITION;
  err = mciSendCommand(gMciDeviceId, MCI_STATUS, MCI_STATUS_ITEM, (DWORD)&params);
  *position = params.dwReturn;

  return err;
}


// 00401797
MCIERROR cdAudio_seekTrack(int* pTrackId) {
  MCIERROR err = cdAudio_setMciPlayParams(*pTrackId);
  MCI_SEEK_PARMS params;
  ULONG* pList;
  if (err != 0) {
    return err;
  }

  pList = (ULONG*)GlobalLock(ghCdAudioTrackListMemory);
  params.dwCallback = 0;
  params.dwTo = pList[*pTrackId];
  GlobalUnlock(ghCdAudioTrackListMemory);
  err = mciSendCommand(gMciDeviceId, MCI_SEEK, MCI_WAIT | MCI_TO, (DWORD)&params);

  return err;
}


// 0040181a
MCIERROR cdAudio_playIfNotStopped(HWND hWnd) {
  if (DAT_00430370 & 2) {
    return 0;
  }
  else if (DAT_00430370 & 1) {
    return mciSendCommand(gMciDeviceId, MCI_PLAY, gMciPlayFlags, (DWORD)&gMciPlayParams);
  }
  else {
    return 0;
  }
}
