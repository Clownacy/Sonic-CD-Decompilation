#include <windows.h>
#include <string.h>
#include "RESOURCE.H"
#include "TYPES.H"

/* These declarations are only here to shut the compiler up.
   I have no idea what the real declarations are. */
void* FX_MODEX_DISPLAY[4];
void _devGetPalette(UINT, UINT, UCHAR*);
void _devSetPalette(UINT, UINT, UCHAR*);
void _objApplyEffect(LPVOID, void*, void*, void*, void*, UINT, void*);
void _fxSetActive(void*, UINT);
void _objPrepare(LPVOID);
void _objRemoveEffect(LPVOID, void*);
ULONG _srfDelete(LPVOID);

void decodeMciError(MCIERROR error, LPSTR buffer, ULONG bufferSize);
MCIERROR createCdAudioTrackIndex();
MCIERROR openCdAudio(LPSTR buffer,ULONG bufferSize);
void closeCdAudio();
MCIERROR getMciMode(ULONG* mciMode);
int setMciPlayParams(int trackId);
MCIERROR FUN_0040157a();
MCIERROR switchCdAudioTrack(long trackId, BOOL bUnknown, HWND hWnd);
MCIERROR FUN_00401671();
MCIERROR stopCdAudio();
int makeSurface(HWND hWnd);
BOOL freeSurface();
HGLOBAL makePalette();
void makeFullScreenPalette();
void makePalette2();
void fillColorwk(UCHAR value);
void FUN_004068c4(BOOL unknown);
void setupTimer();
void killTimer();
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow);
ULONG registerWindowClass(HINSTANCE hInstance);
BOOL makeWindow(HINSTANCE hInstance,int nCmdShow);
void checkSubMenuItem(int subMenuPos, UINT menuItemId, BOOL bCheck);
BOOL isCpuPentium();
BOOL isComputerNec();
BOOL isCdromPresent();
BOOL isGameInUse();
void enableSubMenuItem(int subMenuPos, UINT menuItemId, BOOL bEnable);
void modifyControllerMenuItemText(short controllerId);
void toggleSoundQuality();
void retrieveHelpFilePath();
void FUN_00408cdb();
void FUN_00408ea9();
void queryMciPlaying();
LRESULT CALLBACK WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
void paintWindow(HWND hWnd);
int startGame();
int freeAllocatedMemory();
BOOL loadGameStageDll(LPCSTR path);
void toggleController();
BOOL setupJoystick();
void CDPlay(short trackNumber);
void CDPause();
void FUN_0040bb84();
void emptyFunction();
void showCustomError(int id, LPCSTR message);
USHORT emptyFunction2();
void loadIni();
BOOL isDisplay256Colors();
void freeLockedMemory(LPCVOID pLockedMemory);
LPVOID allocAndLockMemory(UINT flags, ULONG bytes);
int openWaveOut(HWND hWnd);
void closeWaveOut();
int chkPcmFile(PcmHeader* pHeader, BYTE** ppPcmData, LPCSTR path);
int loadPcmFile(const LPSTR pcmFile);
void freeWaveMemory();
BYTE* getPcmChunkStart(int ReqNo, ULONG* pSize);
int playWaveRequest(HWND hWnd, WaveInfo *pWaveInfo,int ReqNo);
int FUN_0040dac4(int waveInfoIndex, int ReqNo, HWND hWnd, BOOL bUnknown);
int waveStop(int index);
void WaveAllStop();
int getFreeWaveInfoIndex();
int collectWaveInfoUnknown11(int* array);
int checkWaveInfos();
BOOL switchGameMenuDll(HWND hWnd, LPCSTR path, USHORT type);
BOOL loadOpening(HWND hWnd, LPVOID hSurf);
void unloadGameMenuDll();
BOOL loadAvigood(HWND hWnd);
BOOL loadAvibad(HWND hWnd);
void callDllPaint(HDC hDc);
void realizeMovie();
BOOL playBadEnding();
BOOL playGoodEnding();
void pauseMovie();
void resumeMovie();
void WaveRequest(short ReqNo);
int stubbedFunction();
void retrieveDataFilePath(LPSTR pPath);
void copyScoreData(BYTE* pSource, BYTE* pDestination, ULONG size);
void copyScoreDataDelegate(BYTE* pSource, BYTE* pDestination, ULONG size);
BOOL verifyScoreDataChecksum(BYTE* pScoreData);
void updateScoreDataChecksum(BYTE* pScoreData);
BOOL ReadScoreData(ULONG index, score_data *pOldScoreData, HFILE hOtherFile);
BOOL WriteScoreData(int index, score_data* pNewScoreData, HFILE hOtherFile);
void OpenScoreData(int mode);
void CloseScoreData(HFILE path);
void CreateScoreData();
int ReadScoreIndx(HFILE hOtherFile);
BOOL WriteScoreIndx(ULONG index, HFILE hOtherFile);
void initScoreData(score_data* pScoreData, ULONG index);
BOOL initCurrentScoreData();
void CALLBACK timeCallbackFunc(UINT uTimerID, UINT uMsg, DWORD_PTR dwUser, DWORD_PTR dw1, DWORD_PTR dw2);

ULONG gSurfFuncRet;
int_union* gpHscroll;
void* DAT_0041dd5c;
HMODULE ghSonicDlg;
void(*gpDLLmeminit)(char***, void**);
char helpFilePath[80];
FARPROC gpGameinit;
JOYCAPS gJoyCapsInfo;
ULONG gJoystickInput4;
ULONG gJoystickInput1;
ULONG gJoystickInput2;
ULONG gJoystickInput3;
USHORT gUserKeyTemp[5];
FARPROC gpFadeProc;
FARPROC gpGame;
FARPROC gpGetscrbhposiw;
FARPROC gpGetvscroll;
void(*gpSetDebugFlag)(unsigned int);
FARPROC gpGetscrahposiw;
FARPROC gpDLLmemfree;
FARPROC gpDLLEnd;
FARPROC gpAVIResume;
FARPROC gpDLLNotify;
void(*gpDLLInit)(DllIn*);
HMODULE ghGameMenuDll;
FARPROC gpDLLAVIRealize;
FARPROC gpDLLKeyDown;
BOOL gbGameDllInit;
FARPROC gpDLLChar;
void(*gpDLLPaint)(HDC);
FARPROC gpAVIPause;
ULONG gGameDllType;
FARPROC gpDLLAVISizeChange;
int gWaveInfoUnknown11Array[6];
score_data gCrntScorData;
ULONG gSelectIndx;
DllIn gDllIn;
BOOL gbVisualmode;
USHORT gSelectedStage;
BOOL gbFirstTitle;
ULONG gWaveDeviceCnt1;
BYTE* gpPcmChunkStart;
ULONG* gpPcmChunkIndex;
ULONG gWaveDeviceCnt2;
BYTE* gpPcmData;
ULONG gPcmDataChunkCnt;
WaveInfo gWaveInfos[6];
FARPROC gpSpecialblockchg;
FARPROC gpDLLMain;
HWND ghWnd;
LPSTR gpCmdLine;
game_info gKeepWork;
FARPROC gpSWdataSet;
HINSTANCE ghInstance;
FARPROC gpGetRoundStr;
HPALETTE ghPalette;
ULONG DAT_00430370;
HGLOBAL ghCdAudioTrackListMemory;
DWORD gMciPlayFlags;
ULONG gCdAudioTrackCnt;
MCI_PLAY_PARMS gMciPlayParams;
MCIDEVICEID gMciDeviceId;
LPVOID ghSurf = 0;
POINT gCursorPos = { 0, 0 };
ULONG DAT_004331d8 = 0;
BOOL gbHelpOpen = FALSE;
BOOL gbWaveOpen = FALSE;
BOOL gbQuit = TRUE;
void* gpDLLmeminitFuncs[12] = { // 004331e8
  &SetGrid,
  &EAsprset,
  0, /* ClrSpriteDebug */
  &WaveRequest,
  &CDPlay,
  &CDPause,
  &ChangeTileBmp,
  &ReadScoreIndx,
  &WriteScoreData,
  &OpenScoreData,
  &WaveAllStop,
  &enableSubMenuItem
};
HDC ghDc = 0;
HMODULE ghGameStageDll;
USHORT gUserKey[5] = {
  VK_LEFT,
  VK_RIGHT,
  VK_UP,
  VK_DOWN,
  VK_SPACE
};
int gUsedMenuId = 0;
LPCSTR gIdrMenu1 = "IDR_MENU1";
LPCSTR gIdrMenu2 = "IDR_MENU2";
LPCSTR gMenus[2] = {
  gIdrMenu1,
  gIdrMenu2
};
BOOL gbNecComputer = FALSE;
HGLOBAL ghMapwkMemory = 0;
USHORT* gpMapwk = 0;
HGLOBAL ghColorwkMemory = 0;
HGLOBAL ghColorwk2Memory = 0;
HGLOBAL ghColorwk3Memory = 0;
HGLOBAL ghColorwk4Memory;
PALETTEENTRY* gpColorwk = 0;
PALETTEENTRY* gpColorwk2 = 0;
PALETTEENTRY* gpColorwk3 = 0;
PALETTEENTRY* gpColorwk4 = 0;
HGLOBAL ghHscrollbuffMemory;
int_union* gpHscrollbuff;
ULONG gFadeFlag;
MMRESULT gTimeSetEventResult = 0;
BOOL DAT_004332a0 = FALSE;
BOOL gbGameStageDllLoaded = FALSE;
long gCurrentCdAudioTrackId = 1;
BOOL DAT_004332c4 = FALSE;
BOOL gbMoviePlaying = FALSE;
BOOL DAT_004332d0 = FALSE;
BOOL DAT_004332d4 = FALSE;
BOOL DAT_004332d8 = FALSE;
BOOL DAT_004332dc = FALSE;
BOOL DAT_004332e0 = FALSE;
BOOL gbRequireCdrom = TRUE;
BOOL gbCdAudioOpenSuccess = FALSE;
ULONG gUnknownCdAudioCountdown = 0;
BOOL gbSpriteLoadingEnabled = TRUE;
ULONG gDebugFlag = 0;
ULONG gControllerId = 2;
BOOL gbFullScreen = FALSE;
BOOL gbBetterSoundQuality = FALSE;
BOOL DAT_00433324 = FALSE;
ULONG gEndingMovieFlag = 0;
BOOL DAT_0043332c = FALSE;
BOOL DAT_00433330 = FALSE;
BOOL DAT_00433334 = FALSE;
void* gGameMemory[11] = { // 00433338
  &gpMapwk,
  &gpColorwk,
  &gpColorwk2,
  &gpColorwk3,
  &gpColorwk4,
  &gpHscrollbuff,
  &gFadeFlag,
  &gKeepWork,
  &ghSurf,
  &ghWnd,
  &gCrntScorData
};
ULONG gTimerTickCnt = 0;
LPCSTR gOpeningDllPath = "TITLE\\OPENING\\OPENING.DLL";
LPCSTR gAviopenDllPath = "TITLE\\AVIOPEN\\AVIOPEN.DLL";
LPCSTR gAvigoodDllPath = "TITLE\\AVIGOOD\\AVIGOOD.DLL";
LPCSTR gAvibadDllPath = "TITLE\\AVIGOOD\\AVIBAD.DLL";
LPCSTR gAvipenDllPath = "TITLE\\AVIPEN\\AVIPEN.DLL";
LPCSTR gSavedataDllPath = "TITLE\\SAVEDATA\\SAVEDATA.DLL";
LPCSTR gVisualmdDllPath = "TITLE\\VISUALMD\\VISUALMD.DLL";
LPCSTR gSoundtstDllPath = "TITLE\\SOUNDTST\\SOUNDTST.DLL";
LPCSTR gStagetstDllPath = "TITLE\\STAGETST\\STAGETST.DLL";
LPCSTR gBesttimeDllPath = "TITLE\\BESTTIME\\BESTTIME.DLL";
BOOL gbFullScreenMenuItemEnabled = TRUE;


// 00401000
void decodeMciError(MCIERROR error, LPSTR buffer, ULONG bufferSize) {
  if (error == 0) return;

  switch (error) {
    case 4294967295:
      strncpy(buffer, "Not Enough Memory!!", bufferSize);
      break;
    case 4294967294:
      strncpy(buffer, "Track None!!", bufferSize);
      break;
    case 4294967293:
      strncpy(buffer, "Illegal Track no!!", bufferSize);
      break;
    default:
      mciGetErrorString(error, buffer, bufferSize);
      break;
  }
}


// 0040109d
MCIERROR createCdAudioTrackIndex() {
  MCIERROR error;
  MCI_STATUS_PARMS mciStatusParams;
  ULONG mediaLength;
  ULONG* pTrackList;
  int i;

  mciStatusParams.dwCallback = 0;
  mciStatusParams.dwItem = MCI_STATUS_NUMBER_OF_TRACKS;
  error = mciSendCommand(gMciDeviceId, MCI_STATUS, MCI_STATUS_ITEM, (DWORD)&mciStatusParams);
  if (error != 0) {
    return error;
  }

  gCdAudioTrackCnt = mciStatusParams.dwReturn;
  if (mciStatusParams.dwReturn == 0) {
    error = 4294967294;
    return error;
  }

  mciStatusParams.dwCallback = 0;
  mciStatusParams.dwItem = MCI_STATUS_LENGTH;
  error = mciSendCommand(gMciDeviceId, MCI_STATUS, MCI_STATUS_ITEM, (DWORD)&mciStatusParams);
  mediaLength = mciStatusParams.dwReturn;
  if (error != 0) {
    return error;
  }

  ghCdAudioTrackListMemory = GlobalAlloc(GMEM_MOVEABLE | GMEM_DDESHARE, gCdAudioTrackCnt * 4 + 4);
  if (ghCdAudioTrackListMemory == 0) {
    error = 4294967295;
    return error;
  }

  pTrackList = (ULONG*)GlobalLock(ghCdAudioTrackListMemory);
  for (i = 0; i < gCdAudioTrackCnt; ++i) {
    mciStatusParams.dwCallback = 0;
    mciStatusParams.dwItem = MCI_STATUS_POSITION;
    mciStatusParams.dwTrack = i + 1;
    error = mciSendCommandA(gMciDeviceId, MCI_STATUS, MCI_STATUS_ITEM | MCI_TRACK, (DWORD)&mciStatusParams);
    if (error != 0) break;
    pTrackList[i] = mciStatusParams.dwReturn;
  }
  GlobalUnlock(ghCdAudioTrackListMemory);
  if (gCdAudioTrackCnt == i) {
    pTrackList[i] = pTrackList[0] + mediaLength;
    error = 0;
  }

  return error;
}


// 0040123d
MCIERROR openCdAudio(LPSTR buffer, ULONG bufferSize) {
  MCIERROR error = 0;
  MCI_OPEN_PARMS mciOpenParams;
  MCI_STATUS_PARMS mciStatusParams;
  MCI_SET_PARMS mciSetParams;
  char buffer2[128];
  char drive[3];
  LPSTR pDrive;
  int result;

  DAT_00430370 = 0;
  mciOpenParams.dwCallback = 0;
  mciOpenParams.lpstrDeviceType = "cdaudio";

  GetPrivateProfileString("Directory", "Type", "FULL", buffer2, sizeof(buffer2), "sonic.ini");
  if (buffer2[0] == 'M') {
    GetPrivateProfileString("Directory", "Play", "D:\\GAME", buffer2, sizeof(buffer2), "sonic.ini");
    drive[0] = buffer2[0];
    drive[1] = ':';
    drive[2] = '\0';
    mciOpenParams.lpstrElementName = drive;
    error = mciSendCommand(0, MCI_OPEN, MCI_OPEN_SHAREABLE | MCI_OPEN_ELEMENT | MCI_OPEN_TYPE, (DWORD)&mciOpenParams);
  }
  else {
    result = GetPrivateProfileInt("Directory", "CD", 3, "sonic.ini");
    drive[0] = (char)result + 97;
    drive[1] = ':';
    drive[2] = '\0';
    mciOpenParams.lpstrElementName = drive;
    error = mciSendCommand(0, MCI_OPEN, MCI_OPEN_SHAREABLE | MCI_OPEN_ELEMENT | MCI_OPEN_TYPE, (DWORD)&mciOpenParams);
  }
  if (error != 0) {
    mciGetErrorString(error, buffer, bufferSize);
    return error;
  }

  gMciDeviceId = mciOpenParams.wDeviceID;
  mciStatusParams.dwCallback = 0;
  mciStatusParams.dwItem = MCI_STATUS_TIME_FORMAT;
  error = mciSendCommand(mciOpenParams.wDeviceID, MCI_STATUS, MCI_STATUS_ITEM, (DWORD)&mciStatusParams);
  if (error != 0) {
    mciGetErrorString(error, buffer, bufferSize);
    return error;
  }

  if (mciStatusParams.dwReturn != MCI_FORMAT_MSF) {
    mciSetParams.dwCallback = 0;
    mciSetParams.dwTimeFormat = MCI_FORMAT_MSF;
    error = mciSendCommand(gMciDeviceId, MCI_SET, MCI_WAIT | MCI_TO, (DWORD)&mciSetParams);
    if (error != 0) {
      mciGetErrorString(error, buffer, bufferSize);
      return error;
    }
  }
  error = createCdAudioTrackIndex();
  decodeMciError(error, buffer, bufferSize);

  return error;
}


// 00401440
void closeCdAudio() {
  if (ghCdAudioTrackListMemory != 0) {
    GlobalFree(ghCdAudioTrackListMemory);
  }

  mciSendCommand(gMciDeviceId, MCI_CLOSE, MCI_WAIT, 0);
}


// 0040148e
MCIERROR getMciMode(ULONG* mciMode) {
  MCIERROR error;
  MCI_STATUS_PARMS mciStatusParams;

  mciStatusParams.dwCallback = 0;
  mciStatusParams.dwItem = 4;
  error = mciSendCommand(gMciDeviceId, MCI_STATUS, MCI_STATUS_ITEM, (DWORD)&mciStatusParams);
  if (error == 0) {
    *mciMode = mciStatusParams.dwReturn;
  }

  return error;
}


// 004014e1
int setMciPlayParams(int trackId) {
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
MCIERROR FUN_0040157a() {
  return mciSendCommand(gMciDeviceId, MCI_PLAY, gMciPlayFlags & -5, (DWORD)&gMciPlayParams);
}


// 004015b2
MCIERROR switchCdAudioTrack(long trackId, BOOL bUnknown, HWND hWnd) {
  MCIERROR error;
  char buffer[128];

  error = setMciPlayParams(trackId);
  if (error == 0) {
    DAT_00430370 = 0;
    gMciPlayParams.dwCallback = (DWORD)hWnd;
    mciSendCommand(gMciDeviceId, MCI_STOP, MCI_WAIT, 0);
    error = mciSendCommand(gMciDeviceId, MCI_PLAY, gMciPlayFlags, (DWORD)&gMciPlayParams);
    if (error != 0) {
      mciGetErrorStringA(error, buffer, 128);
      MessageBox(0, buffer, "CD Error", MB_ICONSTOP);
    }
    if (bUnknown) {
      DAT_00430370 |= 1;
    }
  }

  return error;
}


// 00401671
MCIERROR FUN_00401671() {
  MCIERROR error = 0;

  if (DAT_00430370 & 2) {
    error = FUN_0040157a();
    DAT_00430370 &= -3;
  }

  return error;
}


// 004016aa
MCIERROR stopCdAudio() {
  ULONG mciMode;
  MCIERROR error;

  error = getMciMode(&mciMode);
  if (error != 0) {
    return error;
  }

  if (mciMode == MCI_MODE_PLAY) {;
    error = mciSendCommand(gMciDeviceId, MCI_STOP, 0, 0);
    DAT_00430370 |= 2;
  }

  return error;
}


// 00403d74
int makeSurface(HWND hWnd) {
  // TODO: uses undocumented DMIX.DLL calls
}


// 00403ffb
BOOL freeSurface() {
  if (ghSurf != 0) {
    gSurfFuncRet = _srfDelete(ghSurf);
    ghSurf = 0;
  }
  if (gpHscroll != 0) {
    GlobalUnlock(GlobalHandle(gpHscroll));
    GlobalFree(GlobalHandle(gpHscroll));
    gpHscroll = 0;
  }

  return 0;
}


// 00405e75
HGLOBAL makePalette() {
  HGLOBAL hMemory;
  HDC hDc;
  LOGPALETTE* pLogPalette;
  PALETTEENTRY* lpPe;
  int i;

  if (gbFullScreen) {
    return 0;
  }

  if (ghPalette != 0) {
    DeleteObject(ghPalette);
  }

  hDc = GetDC(0);
  GetDeviceCaps(hDc, RASTERCAPS);

  if (false) {
    /* unreachable code */
    ReleaseDC(0, hDc);
    MessageBox(0, "RC_PALETTE not set in device Caps (not in 256 color mode?)", "Palette", MB_OK);
    return (HGLOBAL)-1;
  }

  if (GetDeviceCaps(hDc, SIZEPALETTE) != 256) {
    ReleaseDC(0, hDc);
    MessageBox(0, "GetDeviceCaps reports, must be 256", "Palette", MB_OK);
    return (HGLOBAL)-1;
  }

  ReleaseDC(0, hDc);
  hMemory = GlobalAlloc(GHND, 544);
  pLogPalette = (LOGPALETTE*)GlobalLock(hMemory);
  if (pLogPalette == 0) {
    MessageBox(0, "Could not allocate memory for logical palette", "Palette", MB_OK);
    return (HGLOBAL)-1;
  }

  pLogPalette->palVersion = 768;
  pLogPalette->palNumEntries = 134;
  lpPe = pLogPalette->palPalEntry;

  for (i = 0; i < 134; ++i) {
    lpPe->peRed = 0;
    lpPe->peGreen = 0;
    lpPe->peBlue = 0;
    lpPe->peFlags = 1;
    ++lpPe;
  }

  for (i = 0; i < 2; ++i) {
    ghPalette = CreatePalette(pLogPalette);
    if (ghPalette == 0) {
      MessageBox(0, "CreatePalette failed", "Palette", MB_OK);
    }
    hDc = GetDC(ghWnd);
    SelectPalette(hDc, ghPalette, FALSE);
    RealizePalette(hDc);
    SelectPalette(hDc, ghPalette, FALSE);
    ReleaseDC(ghWnd, hDc);
    if (i == 0) {
      DeleteObject(ghPalette);
    }
  }
  hMemory = GlobalHandle(pLogPalette);
  GlobalUnlock(hMemory);
  hMemory = GlobalHandle(pLogPalette);
  hMemory = GlobalFree(hMemory);

  return hMemory;
}


// 004060c8
void makeFullScreenPalette() {
  UCHAR unknownBuffer[64];
  int i;
  PALETTEENTRY paletteEntries[240];

  _devGetPalette(256, 0, unknownBuffer);
  if (gKeepWork.stageno.b.h == 2) {
    for (i = 0; i < 64; ++i) {
      paletteEntries[i].peRed = gpColorwk[i].peBlue;
      paletteEntries[i].peGreen = gpColorwk[i].peGreen;
      paletteEntries[i].peBlue = gpColorwk[i].peRed;
    }
    for (i = 0; i < 64; ++i) {
      paletteEntries[i + 64].peRed = gpColorwk3[i].peBlue;
      paletteEntries[i + 64].peGreen = gpColorwk3[i].peGreen;
      paletteEntries[i + 64].peBlue = gpColorwk3[i].peRed;
    }
    _devSetPalette(256, 0, unknownBuffer);
  }
  else {
    for (i = 0; i < 64; ++i) {
      paletteEntries[i].peRed = gpColorwk[i].peBlue;
      paletteEntries[i].peGreen = gpColorwk[i].peGreen;
      paletteEntries[i].peBlue = gpColorwk[i].peRed;
    }
    _devSetPalette(256, 0, unknownBuffer);
  }
}


// 00406255
void makePalette2() {
  LOGPALETTE* pLogPalette;
  PALETTEENTRY *lpPe;
  int i;
  HDC hDc;

  if (gbFullScreen) {
    makeFullScreenPalette();
    return;
  }

  pLogPalette = (LOGPALETTE*)GlobalLock(GlobalAlloc(GHND, 544));
  if (pLogPalette == 0) {
    MessageBox(0, "Could not allocate memory for logical palette", "Palette", MB_OK);
    return;
  }

  pLogPalette->palVersion = 768;
  pLogPalette->palNumEntries = 134;
  lpPe = pLogPalette->palPalEntry;

  for (i = 0; i < 6; ++i) {
    lpPe->peRed = 0;
    lpPe->peGreen = 0;
    lpPe->peBlue = 0;
    lpPe->peFlags = 1;
    ++lpPe;
  }

  for (i = 6; i < 70; ++i) {
    lpPe->peRed = gpColorwk[i - 6].peRed;
    lpPe->peGreen = gpColorwk[i - 6].peGreen;
    lpPe->peBlue = gpColorwk[i - 6].peBlue;
    lpPe->peFlags = 1;
  }

  if (gKeepWork.stageno.b.h == 2) {
    for (i = 70; i < 134; ++i) {
      lpPe->peRed = gpColorwk3[i - 70].peRed;
      lpPe->peGreen = gpColorwk3[i - 70].peGreen;
      lpPe->peBlue = gpColorwk3[i - 70].peBlue;
      lpPe->peFlags = 1;
    }
  }
  else {
    lpPe->peRed = gpColorwk[i - 70].peRed;
    lpPe->peGreen = gpColorwk[i - 70].peGreen;
    lpPe->peBlue = gpColorwk[i - 70].peBlue;
    lpPe->peFlags = 1;
  }

  AnimatePalette(ghPalette, 0, 134, pLogPalette->palPalEntry);
  GlobalUnlock(GlobalHandle(pLogPalette));
  GlobalFree(GlobalHandle(pLogPalette));

  hDc = GetDC(ghWnd);
  SelectPalette(hDc, ghPalette, FALSE);
  RealizePalette(hDc);
}


// 004064d5
void fillColorwk(UCHAR value) {
  int i;

  for (i = 0; i < 64; ++i) {
    gpColorwk[i].peBlue = value;
    gpColorwk[i].peGreen = value;
    gpColorwk[i].peRed = value;
  }

  makePalette2();
}


// 004068c4
void FUN_004068c4(BOOL bFullScreen) {
  RECT rect;

  if (bFullScreen) {
    _objApplyEffect(ghSurf, FX_MODEX_DISPLAY[0], FX_MODEX_DISPLAY[1], FX_MODEX_DISPLAY[2], FX_MODEX_DISPLAY[3], 0, DAT_0041dd5c);
    _fxSetActive(DAT_0041dd5c, 1);
    GetCursorPos(&gCursorPos);
    GetWindowRect(ghWnd, &rect);
    SetCursorPos((rect.right + rect.left) / 2, (rect.top + rect.bottom) / 2);
    ClipCursor(&rect);
    ShowCursor(FALSE);
    _objPrepare(ghSurf);
    makePalette2();
  }
  else {
    _objRemoveEffect(ghSurf, DAT_0041dd5c);
    makePalette();
    ClipCursor(0);
    ShowCursor(TRUE);
    SetCursorPos(gCursorPos.x, gCursorPos.y);
    makePalette();
  }
}


// 00408107
void setupTimer() {
  gTimeSetEventResult = timeSetEvent(16, 1, timeCallbackFunc, (DWORD)&gTimerTickCnt, TIME_PERIODIC);
  if (gTimeSetEventResult == 0) {
    emptyFunction();
    timeEndPeriod(1);
  }
  gTimerTickCnt = 0;
}


// 0040815e
void killTimer() {
  if (gTimeSetEventResult != 0) {
    timeKillEvent(gTimeSetEventResult);
    timeEndPeriod(1);
    gTimeSetEventResult = 0;
  }
}


// 00408199
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
  BOOL bInUse;
  MSG msg;

  bInUse = isGameInUse();
  if (bInUse) {
    MessageBox(ghWnd, "SONIC CD is already in use.", "SONIC CD Error", MB_ICONSTOP);
    msg.wParam = 0;
    goto end;
  }
  if (hPrevInstance == 0) {
    if (registerWindowClass(hInstance) == 0) {
      msg.wParam = 0;
      goto end;
    }
    gpCmdLine = lpCmdLine;
  }
  if (makeWindow(hInstance, nCmdShow) == FALSE) {
    msg.wParam = 0;
    goto end;
  }
  if (startGame() != 0) {
    freeAllocatedMemory();
    msg.wParam = 0;
    goto end;
  }
  if (timeBeginPeriod(1) == TIMERR_NOCANDO) {
    MessageBox(ghWnd, "Can't handle the timer resolution", "timeBeginPeriod()", MB_OK);
  }
  setupTimer();
  setupJoystick();
  gControllerId = 2;
  modifyControllerMenuItemText(2);

  while (true) {
    if (PeekMessage(&msg, 0, 0, 0, PM_REMOVE)) {
      if (msg.message == WM_QUIT) break;
      TranslateMessage(&msg);
      DispatchMessage(&msg);
    }
    else {
      if (!gbQuit) continue;
      if (IsIconic(ghWnd)) continue;
      if (DAT_00433324) {
        toggleSoundQuality();
      }
      else if (gEndingMovieFlag != 0) {
        if (checkWaveInfos() == 0) {
          if (gEndingMovieFlag == 1) {
            playBadEnding();
          }
          else {
            playGoodEnding();
          }
          gEndingMovieFlag = 0;
        }
      }
      else if (gTimerTickCnt != 0 || gTimeSetEventResult == 0) {
        if (gUnknownCdAudioCountdown != 0 && --gUnknownCdAudioCountdown == 0 && gCurrentCdAudioTrackId != -1) {
          FUN_0040bb84();
        }
        gTimerTickCnt--;
        if (gTimerTickCnt > 10) {
          gTimerTickCnt = 0;
        }
        if (DAT_004332d8 != 0) {
          gbQuit = FUN_0040773d();
        }
        else if (DAT_004332dc) {
          gbQuit = FUN_00407854();
        }
        else if (DAT_004332d4) {
          gbQuit = FUN_00407ad8();
        }
        else if (DAT_004332c4) {
          gbQuit = FUN_00407060();
        }
        else if (DAT_004332d0) {
          gbQuit = FUN_004074de();
        }
        else if (DAT_004332e0) {
          gbQuit = FUN_00407982();
        }
        else {
          gbQuit = FUN_00407c1b();
        }
      }
      if (gbQuit == 0) {
        DestroyWindow(ghWnd);
      }
    }
  }

  killTimer();
  FUN_00408ea9();

end:
  return msg.wParam;
}


// 00408488
ULONG registerWindowClass(HINSTANCE hInstance) {
  WNDCLASS wndClass;

  loadIni();

  wndClass.style = CS_HREDRAW | CS_VREDRAW;
  wndClass.lpfnWndProc = WndProc;
  wndClass.cbClsExtra = 0;
  wndClass.cbWndExtra = 0;
  wndClass.hInstance = hInstance;
  wndClass.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(101));
  wndClass.hCursor = LoadCursor(0,IDC_ARROW);
  wndClass.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);
  wndClass.lpszMenuName = gMenus[gUsedMenuId];
  wndClass.lpszClassName = "SONICCDClass";
  LoadAccelerators(hInstance, "IDR_ACCELERATOR1");

  return RegisterClass(&wndClass);
}


// 00408520
BOOL makeWindow(HINSTANCE hInstance,int nCmdShow) {
  HWND hWnd;
  RECT rect, desktopRect;
  int width, height;

  ghInstance = hInstance;
  rect.top = 0;
  rect.left = 0;
  rect.bottom = 224;
  rect.right = 319;
  AdjustWindowRect(&rect, WS_CAPTION | WS_SYSMENU, TRUE);
  GetProfileInt("windows", "BorderWidth", -1);
  if (rect.top < 0) {
    rect.bottom = rect.bottom - rect.top;
    rect.top = 0;
  }
  if (rect.left < 0) {
    rect.right = rect.right - rect.left;
    rect.left = 0;
  }
  width = (rect.right - rect.left) + 1;
  height = (rect.bottom - rect.top) + 1;
  GetWindowRect(GetDesktopWindow(), &desktopRect);
  rect.top = (((desktopRect.bottom - desktopRect.top) + 1) - height) / 2;
  rect.left = (((desktopRect.right - desktopRect.left) + 1) - width) / 2;
  rect.bottom = rect.top + height - 1;
  rect.right = rect.left + width - 1;

  hWnd = CreateWindowEx(0, "SONICCDClass", "SONIC CD", WS_CAPTION | WS_SYSMENU | WS_GROUP, rect.left, rect.top, width, height, 0, 0, hInstance, 0);
  if (hWnd == 0) {
    return FALSE;
  }
  ghWnd = hWnd;
  ShowWindow(hWnd, nCmdShow);
  UpdateWindow(hWnd);
  return TRUE;
}


// 004086a8
void checkSubMenuItem(int subMenuPos, UINT menuItemId, BOOL bCheck) {
  HMENU hMenu;
  ULONG flags;

  hMenu = GetMenu(ghWnd);
  hMenu = GetSubMenu(hMenu, subMenuPos);
  if (bCheck) {
    flags = MF_CHECKED;
  }
  else {
    flags = MF_UNCHECKED;
  }
  CheckMenuItem(hMenu, menuItemId, flags);
}


// 00408704
BOOL isCpuPentium() {
  return TRUE;
}


// 00408719
BOOL isComputerNec() {
  BOOL ret = FALSE;
  UINT result;
  char buffer[80];

  result = GetDriveType("a:");
  if (result != DRIVE_REMOVABLE) {
    ret = TRUE;
  }

  GetPrivateProfileString("boot.description", "system.drv", "", buffer, sizeof(buffer), "system.drv");
  if (buffer[0] == 'N' && buffer[1] == 'E' && buffer[2] == 'C') {
    ret = TRUE;
  }

  return ret;
}


// 0040879f
BOOL isCdromPresent() {
  UINT result;
  char drive[3];
  LPSTR chkFilePath = "d:\\soniccd.chk";
  HFILE hFile;

  result = GetPrivateProfileInt("Directory", "CD", 3, "sonic.ini");
  drive[0] = (char)result + 97;
  drive[1] = ':';
  drive[2] = '\0';
  result = GetDriveType(drive);
  if (result != DRIVE_CDROM) {
    MessageBox(0, "CD drive is not found.", "Sonic Error", MB_ICONSTOP);
    return FALSE;
  }

  chkFilePath[0] = drive[0];
  hFile = _lopen(chkFilePath, OF_READ);
  if (hFile == HFILE_ERROR) {
    MessageBox(0, "CD check file is not found.", "Sonic Error", MB_ICONSTOP);
    return FALSE;
  }

  _lclose(hFile);
  return TRUE;
}


// 0040886e
BOOL isGameInUse() {
  BOOL bRet;
  HWND hWnd;

  hWnd = FindWindow(0, "SONIC CD");
  if (hWnd) {
    bRet = TRUE;
  }
  else {
    bRet = FALSE;
  }

  return bRet;
}


// 0040889f
void enableSubMenuItem(int subMenuPos, UINT menuItemId, BOOL bEnable) {
  HMENU hMenu;
  UINT flags;

  hMenu = GetMenu(ghWnd);
  hMenu = GetSubMenu(hMenu, subMenuPos);
  if (bEnable) {
    flags = MF_ENABLED;
  }
  else {
    flags = MF_GRAYED | MF_DISABLED;
  }
  EnableMenuItem(hMenu, menuItemId, flags);
}


// 004089a6
void modifyControllerMenuItemText(short controllerId) {
  int nPos = 1;
  HMENU hMenu;
  char buffer[128];

  hMenu = GetMenu(ghWnd);
  hMenu = GetSubMenu(hMenu, nPos);
  if (controllerId == 1) {
    LoadString(ghInstance, IDS_USEKEYBOARD, buffer, sizeof(buffer));
    ModifyMenu(hMenu, ID_OPTIONS_USEKEYBOARD, MF_BYCOMMAND | MF_STRING, ID_OPTIONS_USEKEYBOARD, buffer);
  }
  else {
    LoadString(ghInstance, IDS_USEJOYSTICK, buffer, sizeof(buffer));
    ModifyMenu(hMenu, ID_OPTIONS_USEKEYBOARD, MF_BYCOMMAND | MF_STRING, ID_OPTIONS_USEKEYBOARD, buffer);
  }
}


// 00408a56
void toggleSoundQuality() {
  short trackNumber;
  HMENU hMenu;
  char buffer[128];
  HCURSOR hCursor, hPrevCursor;
  int result;

  if (gbMoviePlaying) return;

  if (checkWaveInfos() != 0) {
    DAT_00433324 = TRUE;
    return;
  }

  DAT_00433324 = FALSE;
  if (gbCdAudioOpenSuccess && gCurrentCdAudioTrackId > 0) {
    trackNumber = gCurrentCdAudioTrackId + 1;
    CDPause();
  }
  else {
    trackNumber = 0;
  }
  gbBetterSoundQuality = !gbBetterSoundQuality;
  hMenu = GetMenu(ghWnd);
  hMenu = GetSubMenu(hMenu, 1);
  if (gbBetterSoundQuality) {
    LoadString(ghInstance, IDS_GOODSOUNDQUALITY, buffer, sizeof(buffer));
    ModifyMenu(hMenu, ID_BETTERSOUNDQUALITY, MF_BYCOMMAND | MF_STRING, ID_BETTERSOUNDQUALITY, buffer);
  }
  else {
    LoadString(ghInstance, IDS_BETTERSOUNDQUALITY, buffer, sizeof(buffer));
    ModifyMenu(hMenu, ID_BETTERSOUNDQUALITY, MF_BYCOMMAND |MF_STRING, ID_BETTERSOUNDQUALITY, buffer);
  }
  closeWaveOut();
  freeWaveMemory();
  hCursor = LoadCursor(0, IDC_WAIT);
  hPrevCursor = SetCursor(hCursor);
  if (gbBetterSoundQuality) {
    lstrcpy(buffer, "pcm.cmp");
  }
  else {
    lstrcpy(buffer, "pcm8.cmp");
  }
  result = loadPcmFile(buffer);
  if (result != 0) {
    showCustomError(result, buffer);
    gbWaveOpen = FALSE;
  }
  else {
    openWaveOut(ghWnd);
    gbWaveOpen = TRUE;
  }
  if (trackNumber != 0) {
    CDPlay(trackNumber);
  }
  SetCursor(hPrevCursor);
}


// 00408c6c
void retrieveHelpFilePath() {
  if (GetPrivateProfileString("Directory", "Install", "", helpFilePath, sizeof(helpFilePath), "sonic.ini") == 0) {
    strcat(helpFilePath, "sonic.hlp");
  }
  else {
    strcat(helpFilePath, "\\");
    strcat(helpFilePath, "sonic.hlp");
  }
}


// 00408cdb
void FUN_00408cdb() {
  POINT point;

  if (gbMoviePlaying) return;

  if (ghSurf != 0) {
    if (!gbFullScreen == 0) {
      gbFullScreen = TRUE;
    }
    else {
      gbFullScreen = FALSE;
    }
    FUN_004068c4(gbFullScreen);
  }

  if (gbFullScreen) {
    ShowCursor(FALSE);
  }
  else {
    ShowCursor(TRUE);
    GetCursorPos(&point);
    if (point.x != 0) {
      --point.x;
    }
    else {
      point.x = 1;
    }
    SetCursorPos(point.x, point.y);
  }
}


// 00408ea9
void FUN_00408ea9() {
  CDPause();
  FUN_0040eb80();
  if (gbGameStageDllLoaded) {
    gbGameStageDllLoaded = TRUE;
    (*gpDLLmemfree)();
    FreeLibrary(ghGameStageDll);
  }
  if (DAT_004332a0 == 1) {
    FUN_00405106();
    DAT_004332a0 = 0;
  }
  FUN_0040badc();
}


// 00409221
void queryMciPlaying() {
  ULONG mciMode;

  if (IsIconic(ghWnd)) {
    getMciMode(&mciMode);
    if (mciMode == MCI_MODE_PLAY) {
      OutputDebugString("Now Playing\n\r");
    }
  }
}


// 00409267
LRESULT CALLBACK WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam) {
  HCURSOR hCursor, hPrevCursor;
  char buffer[128];
  void(*pInitKeySettings)(HWND, USHORT*);
  int result;
  ULONG mciMode;

  queryMciPlaying();
  if (msg < 16) {
    if (msg == WM_PAINT) {

    }

    switch (msg) {
      case WM_PAINT:
        paintWindow(hWnd); // 00409900
        return 0;
      case WM_CREATE: // 00409577
        ghDc = GetDC(ghWnd);
        hCursor = LoadCursor(0, IDC_WAIT);
        hPrevCursor = SetCursor(hCursor);
        GetPrivateProfileString("Directory", "Type", "MINIMAL", buffer, sizeof(buffer), "SONIC.INI");
        if (buffer[0] == 'F') {
          GetPrivateProfileString("Secret", "Super", "OFF", buffer, sizeof(buffer), "SONIC.INI");
          if (isCdromPresent() == FALSE && gbRequireCdrom && buffer[0] != 'J') {
            return -1;
          }
        }
        if (isDisplay256Colors() == FALSE) {
          return -1;
        }
        GetPrivateProfileString("Secret", "Super", "OFF", buffer, sizeof(buffer), "SONIC.INI");
        if (buffer[0] != 'J') {
          DWORD versionInfo = GetVersion();
          if ((versionInfo >> 8 & 255) + (versionInfo & 255) * 255 < 863) {
            MessageBox(0, "You must have a Windows® 95\n inside your system to run Sonic the Hedgehog CD.", "Sonic Error", MB_ICONSTOP);
            return -1;
          }
          if (isCpuPentium() == FALSE) {
            MessageBox(0, "You must have a Pentium® Processer (or better)\ninside your system to run Sonic the Hedgehog CD.", "Sonic Error", MB_ICONSTOP);
            return -1;
          }
          SetFocus(ghWnd);
        }
        gbNecComputer = isComputerNec();
        retrieveHelpFilePath();
        GetPrivateProfileString("SOUND", "QUALITY", "GOOD  ", buffer, sizeof(buffer), "SONIC.INI");
        if (buffer[0] == 'B') {
          gbBetterSoundQuality = TRUE;
        }
        else {
          gbBetterSoundQuality = FALSE;
        }
        if (gbBetterSoundQuality) {
          result = loadPcmFile("pcm8.cmp");
        }
        else {
          result = loadPcmFile("pcm8.cmp");
        }
        if (result == 0) {
          result = openWaveOut(hWnd);
          gbWaveOpen = TRUE;
        }
        SetErrorMode(SEM_NOOPENFILEERRORBOX);
        ghSonicDlg = LoadLibrary("SONICDLG.DLL");
        if ((int)ghSonicDlg <= 32) {
          MessageBox(0, "Can't load SONICDLG.DLL", "Sonic Error", MB_ICONSTOP);
          return -1;
        }
        pInitKeySettings = (void(*)(HWND, USHORT*))GetProcAddress(ghSonicDlg, "InitKeySettings");
        if (pInitKeySettings == 0) {
          MessageBox(0, "Can't GetProcAddress() for SONICDLG.DLL:\t\t\t\t\tInitKeySettings()", "Sonic Error", MB_ICONSTOP);
          return -1;
        }
        (*pInitKeySettings)(hWnd, gUserKeyTemp);
        FreeLibrary(ghSonicDlg);
        gUserKey[0] = gUserKeyTemp[0];
        gUserKey[1] = gUserKeyTemp[1];
        gUserKey[2] = gUserKeyTemp[2];
        gUserKey[3] = gUserKeyTemp[3];
        gUserKey[4] = gUserKeyTemp[4];
        gKeepWork.TimeWarp = 0;
        initCurrentScoreData();
        SetCursor(hPrevCursor);
        if (openCdAudio(buffer, sizeof(buffer)) != 0) {
          gbCdAudioOpenSuccess = FALSE;
          MessageBox(hWnd, buffer, "CD Device Error", MB_OK);
        }
        else {
          gbCdAudioOpenSuccess = TRUE;
        }
        BringWindowToTop(ghWnd);
        break;
      case WM_DESTROY: // 00409913
        if (gbFullScreen) {
          FUN_00408cdb();
        }
        if (gbHelpOpen) {
          gbHelpOpen = FALSE;
          WinHelp(ghWnd, helpFilePath, HELP_QUIT, 0);
        }
        if (gbBetterSoundQuality) {
          WritePrivateProfileString("SOUND", "QUALITY", "BETTER", "SONIC.INI");
        }
        else {
          WritePrivateProfileString("SOUND", "QUALITY", "GOOD  ", "SONIC.INI");
        }
        WaveAllStop();
        CDPause();
        FUN_00408ea9();
        if (gbWaveOpen) {
          closeWaveOut();
          freeWaveMemory();
        }
        closeCdAudio();
        emptyFunction2();
        ReleaseDC(ghWnd, ghDc);
        freeAllocatedMemory();
        freeSurface();
        PostQuitMessage(0);
        break;
      case WM_SIZE: // 004094d8
        if (wParam == 1) {
          DAT_0043332c = TRUE;
          getMciMode(&mciMode);
          if (mciMode == MCI_MODE_PLAY) {
            stopCdAudio();
            DAT_00433330 = TRUE;
          }
          if (gbMoviePlaying) {
            pauseMovie();
            DAT_00433334 = TRUE;
          }
        }
        if (wParam == 0) {
          if (DAT_00433330) {
            FUN_00401671();
            DAT_00433330 = FALSE;
          }
          DAT_0043332c = FALSE;
          if (gbMoviePlaying) {
            resumeMovie();
          }
        }
        break;
      case WM_ACTIVATE: // 004099f7
        if ((wParam == 1 || wParam == 2) && !gbFullScreen) {
          if (gbMoviePlaying) {
            realizeMovie();
          }
          else {
            makePalette();
          }
          break;
        }
        if (wParam == 0 && gbFullScreen) {
          if (gbMoviePlaying) {
            gbFullScreen = FALSE;
          }
          else {
            FUN_00408cdb();
          }
          break;
        }
        return DefWindowProcA(hWnd, msg, wParam, lParam);
    }
  }

  return 0;
}


// 0040a5e2
void paintWindow(HWND hWnd) {
  HDC hDc;
  PAINTSTRUCT paintInfo;

  hDc = BeginPaint(hWnd, &paintInfo);
  if (gbMoviePlaying) {
    callDllPaint(hDc);
    emptyFunction();
  }
  EndPaint(hWnd,&paintInfo);
}


// 0040a635
int startGame() {
  HCURSOR hCursor, hPrevCursor;
  HMENU hMenu;
  char buffer[128];

  ghMapwkMemory = GlobalAlloc(GHND, 65536);
  if (ghMapwkMemory == 0) {
    return -1;
  }

  gpMapwk = (USHORT*)GlobalLock(ghMapwkMemory);
  if (gpMapwk == 0) {
    return -1;
  }

  ghColorwkMemory = GlobalAlloc(GHND, 256);
  if (ghColorwkMemory == 0) {
    return -1;
  }

  ghColorwk2Memory = GlobalAlloc(GHND, 256);
  if (ghColorwk2Memory == 0) {
    return -1;
  }

  ghColorwk3Memory = GlobalAlloc(GHND, 256);
  if (ghColorwk3Memory == 0) {
    return -1;
  }

  ghColorwk4Memory = GlobalAlloc(GHND, 256);
  if (ghColorwk4Memory == 0) {
    return -1;
  }

  gpColorwk = (PALETTEENTRY*)GlobalLock(ghColorwkMemory);
  if (gpColorwk == 0) {
    return -1;
  }

  gpColorwk2 = (PALETTEENTRY*)GlobalLock(ghColorwk2Memory);
  if (gpColorwk2 == 0) {
    return -1;
  }

  gpColorwk3 = (PALETTEENTRY*)GlobalLock(ghColorwk3Memory);
  if (gpColorwk3 == 0) {
    return -1;
  }

  gpColorwk4 = (PALETTEENTRY*)GlobalLock(ghColorwk4Memory);
  if (gpColorwk4 == 0) {
    return -1;
  }

  ghHscrollbuffMemory = GlobalAlloc(GHND, 1024);
  if (ghHscrollbuffMemory == 0) {
    return -1;
  }

  gpHscrollbuff = (int_union*)GlobalLock(ghHscrollbuffMemory);
  if (gpHscrollbuff == 0) {
    return -1;
  }

  makePalette();
  makeSurface(ghWnd);
  memset(&gKeepWork, 0, 892);

  hCursor = LoadCursor(0, IDC_WAIT);
  hPrevCursor = SetCursor(hCursor);
  gKeepWork.ta_flag = 0;
  gKeepWork.TimeWarp = 1;
  gKeepWork.SpecialTime = 0;
  checkSubMenuItem(4, ID_FUNC_TIMEWARP, gKeepWork.TimeWarp);
  gKeepWork.play_start = 0;
  gbSpriteLoadingEnabled = TRUE;
  checkSubMenuItem(4, ID_FUNC_SPRITECMP, gbSpriteLoadingEnabled);
  gbFirstTitle = TRUE;
  DAT_004332c4 = loadOpening(ghWnd, ghSurf);
  gbFirstTitle = FALSE;
  SetCursor(hPrevCursor);
  loadIni();
  hMenu = GetMenu(ghWnd);
  hMenu = GetSubMenu(hMenu, 1);
  if (gbBetterSoundQuality) {
    LoadString(ghInstance, IDS_GOODSOUNDQUALITY, buffer, sizeof(buffer));
    ModifyMenu(hMenu, ID_BETTERSOUNDQUALITY, MF_BYCOMMAND | MF_STRING, ID_BETTERSOUNDQUALITY, buffer);
  }
  else {
    LoadString(ghInstance, IDS_BETTERSOUNDQUALITY, buffer, sizeof(buffer));
    ModifyMenu(hMenu, ID_BETTERSOUNDQUALITY, MF_BYCOMMAND | MF_STRING, ID_BETTERSOUNDQUALITY, buffer);
  }
  BringWindowToTop(ghWnd);
  SetActiveWindow(ghWnd);
  SetFocus(ghWnd);
  enableSubMenuItem(1, ID_OPTIONS_FULLSCREEN, !gbNecComputer);

  return 0;
}


// 0040a9e3
int freeAllocatedMemory() {
  if (ghHscrollbuffMemory != 0) {
    GlobalUnlock(ghHscrollbuffMemory);
  }
  if (ghHscrollbuffMemory != 0) {
    GlobalFree(ghHscrollbuffMemory);
  }
  if (ghColorwkMemory != 0) {
    GlobalUnlock(ghColorwkMemory);
  }
  if (ghColorwk2Memory != 0) {
    GlobalUnlock(ghColorwk2Memory);
  }
  if (ghColorwk3Memory != 0) {
    GlobalUnlock(ghColorwk3Memory);
  }
  if (ghColorwk4Memory != 0) {
    GlobalUnlock(ghColorwk4Memory);
  }
  if (ghColorwkMemory != 0) {
    GlobalFree(ghColorwkMemory);
  }
  if (ghColorwk2Memory != 0) {
    GlobalFree(ghColorwk2Memory);
  }
  if (ghColorwk3Memory != 0) {
    GlobalFree(ghColorwk3Memory);
  }
  if (ghColorwk4Memory != 0) {
    GlobalFree(ghColorwk4Memory);
  }
  if (ghPalette != 0) {
    DeleteObject(ghPalette);
  }
  if (ghMapwkMemory != 0) {
    GlobalUnlock(ghMapwkMemory);
  }
  if (ghMapwkMemory != 0) {
    GlobalFree(ghMapwkMemory);
  }

  return 0;
}


// 0040ad7d
BOOL loadGameStageDll(LPCSTR path) {
  char buffer[80];

  memset(gpHscrollbuff, 0, 1024);
  ghGameStageDll = LoadLibrary(path);
  if ((ULONG)ghGameStageDll < 32) {
    wsprintf(buffer, "DLL Load Error! (%x) %s", ghGameStageDll, buffer);
    MessageBox(ghWnd, buffer, "", MB_SYSTEMMODAL);
    return FALSE;
  }

  gpGameinit = GetProcAddress(ghGameStageDll, "game_init");
  gpGame = GetProcAddress(ghGameStageDll, "game");
  gpDLLmeminit = (void(*)(char***, void**))GetProcAddress(ghGameStageDll, "DLL_meminit");
  gpDLLmemfree = GetProcAddress(ghGameStageDll, "DLL_memfree");
  gpSWdataSet = GetProcAddress(ghGameStageDll, "SWdataSet");
  gpGetvscroll = GetProcAddress(ghGameStageDll, "Get_vscroll");
  gpGetscrahposiw = GetProcAddress(ghGameStageDll, "Get_scra_h_posiw");
  gpGetscrbhposiw = GetProcAddress(ghGameStageDll, "Get_scrb_h_posiw");
  gpFadeProc = GetProcAddress(ghGameStageDll, "FadeProc");
  gpSetDebugFlag = (void(*)(unsigned int))GetProcAddress(ghGameStageDll, "SetDebugFlag");
  gpGetRoundStr = GetProcAddress(ghGameStageDll, "GetRoundStr");
  gpSpecialblockchg = GetProcAddress(ghGameStageDll, "Special_block_chg");
  gpDLLmeminit((char***)gGameMemory, gpDLLmeminitFuncs);
  gbGameStageDllLoaded = TRUE;
  if (gpSetDebugFlag != 0) {
    gpSetDebugFlag(gDebugFlag);
  }

  return TRUE;
}


// 0040b4ef
void toggleController() {
  if (setupJoystick() == FALSE) {
    gControllerId = 2;
  }
  else if (gControllerId == 1) {
    gControllerId = 2;
  }
  else {
    gControllerId = 1;
  }
  modifyControllerMenuItemText(gControllerId);
}


// 0040b54f
BOOL setupJoystick() {
  if (joyGetNumDevs() == 0) {
    return FALSE;
  }
  if (joyGetDevCapsA(0, &gJoyCapsInfo, sizeof(gJoyCapsInfo)) == MMSYSERR_NODRIVER) {
    return FALSE;
  }

  gJoystickInput1 = 21846;
  gJoystickInput2 = 43690;
  gJoystickInput3 = 21846;
  gJoystickInput4 = 43690;

  return TRUE;
}


// 0040bb23
void CDPlay(short trackNumber) {
  gCurrentCdAudioTrackId = trackNumber + -1;
  if (gUnknownCdAudioCountdown == 0) {
    stopCdAudio();
    gUnknownCdAudioCountdown = 60;
  }
}


// 0040bb5b
void CDPause() {
  gCurrentCdAudioTrackId = -1;
  stopCdAudio();
  gUnknownCdAudioCountdown = 60;
}


// 0040bb84
void FUN_0040bb84() {
  BOOL unknown;
  MCIERROR error;
  char buffer[128];

  if (!gbCdAudioOpenSuccess);

  switch (gCurrentCdAudioTrackId) {
    case 1:
    case 27:
    case 30:
    case 29:
    case 28:
      unknown = FALSE;
      break;
    default:
      unknown = TRUE;
      break;
  }

  error = switchCdAudioTrack(gCurrentCdAudioTrackId, unknown, ghWnd);
  if (error != 0) {
    mciGetErrorStringA(error, buffer, 128);
    emptyFunction();
  }
}


// 0040bd30
void emptyFunction() {
  // empty
}


// 0040bd40
void showCustomError(int id, LPCSTR message) {
  char buffer[80];

  switch (id) {
    case 1:
      wsprintf(buffer, "File Can't Open %s", message);
      MessageBox(ghWnd, buffer, 0, MB_SYSTEMMODAL);
      break;
    case 2:
      MessageBox(ghWnd, "Memory Allocate Error.", 0, MB_SYSTEMMODAL);
      break;
    case 3:
      wsprintf(buffer, "Falal Error %x", message);
    default:
      MessageBox(ghWnd, message, 0,MB_SYSTEMMODAL);
      break;
  }
}


// 0040c00c
USHORT emptyFunction2() {
  // empty
}


// 0040c128
void loadIni() {
  char buffer[256];

  if (GetPrivateProfileString("Secret", "User", "", buffer, sizeof(buffer), "SONIC.INI")) {
    if (strcmp(buffer, "Debugger") == 0) {
      gUsedMenuId = 1;
      gbRequireCdrom = FALSE;
      gKeepWork.User = 2;
    }
    else if (strcmp(buffer, "Fujiwara") == 0) {
      gKeepWork.User = 1;
    }
    else if (strcmp(buffer, "Satoh") == 0) {
      gUsedMenuId = 1;
      gbRequireCdrom = FALSE;
      gKeepWork.User = 128;
    }
  }
}


// 0040c206
BOOL isDisplay256Colors() {
  int result;

  result = GetDeviceCaps(ghDc, RASTERCAPS);
  if (result & RC_PALETTE) {
    result = GetDeviceCaps(ghDc, SIZEPALETTE);
    if (result == 256) {
      return TRUE;
    }
  }

  MessageBox(0, "Your computer display setting must be 256 color to play Sonic the Hedgehog CD.", "Sonic Error", MB_ICONSTOP);
  return FALSE;
}


// 0040d4f0
LPVOID allocAndLockMemory(UINT flags, ULONG bytes) {
  HGLOBAL hGlobal;

  hGlobal = GlobalAlloc(flags & 65535, bytes);
  if (hGlobal == 0) {
    return 0;
  }

  return GlobalLock(hGlobal);
}


// 0040d539
void freeLockedMemory(LPCVOID pLockedMemory) {
  HGLOBAL hMemory;

  if (pLockedMemory != 0) {
    hMemory = GlobalHandle(pLockedMemory);
    GlobalUnlock(hMemory);
    GlobalFree(hMemory);
  }
}


// 0040d572
int openWaveOut(HWND hWnd) {
  WaveInfo* pWaveInfo;
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
    gWaveInfos[i].hWaveout = 0;
  }
  for (i = 0; i < 6; ++i, ++pWaveInfo) {
    pWaveInfo->busy = FALSE;
    pWaveInfo->unknown11 = -1;
    if (waveOutOpen(&pWaveInfo->hWaveout, WAVE_MAPPER, &waveFormat, (DWORD)hWnd, 0, CALLBACK_WINDOW) != MMSYSERR_NOERROR) break;
  }
  gWaveDeviceCnt1 = i;
  if (i != 6) {
    gWaveDeviceCnt2 = i;
  }
  else {
    gWaveDeviceCnt2 = 6;
  }
  if (gWaveDeviceCnt2 < 1) {
    return -1;
  }

  return 0;
}


// 0040d6d3
void closeWaveOut() {
  WaveInfo *pWaveInfo;
  int i;

  pWaveInfo = gWaveInfos;
  for (i = 0; i < gWaveDeviceCnt1; ++i, ++pWaveInfo) {
    if (pWaveInfo->hWaveout != 0) {
      waveOutClose(pWaveInfo->hWaveout);
      pWaveInfo->hWaveout = 0;
    }
  }
}


// 0040d735
int chkPcmFile(PcmHeader* pHeader, BYTE** ppPcmData, LPCSTR path) {
  HFILE hFile;
  int result;
  ULONG byteCnt;

  hFile = _lopen(path, OF_READ);
  if (hFile == -1) {
    return 1;
  }

  result = _hread(hFile, pHeader, sizeof(*pHeader));
  if (result != sizeof(*pHeader)) {
    _lclose(hFile);
    return 1;
  }

  byteCnt = pHeader->byteCnt - sizeof(*pHeader);
  *ppPcmData = (BYTE*)allocAndLockMemory(GMEM_ZEROINIT, byteCnt);
  if (*ppPcmData == 0) {
    _lclose(hFile);
    return 2;
  }

  result = _hread(hFile, *ppPcmData, byteCnt);
  if (result != byteCnt) {
    _lclose(hFile);
    return 1;
  }

  _lclose(hFile);
  return 0;
}


// 0040d814
int loadPcmFile(const LPSTR path) {
  int ret;
  PcmHeader header;
  ULONG start;
  int i;

  gWaveDeviceCnt1 = waveOutGetNumDevs();
  gpPcmData = 0;
  gPcmDataChunkCnt = 0;
  memset(gWaveInfos, 0, sizeof(gWaveInfos));
  ret = chkPcmFile(&header, &gpPcmData, path);
  if (ret == 0) {
    gpPcmChunkIndex = (ULONG*)allocAndLockMemory(GMEM_ZEROINIT, header.chunkCnt * 4);
    if (gpPcmChunkIndex == 0) {
      ret = -1;
    }
    else {
      gPcmDataChunkCnt = header.chunkCnt;
      gpPcmChunkStart = &gpPcmData[header.dataOffset - sizeof(header)];
      start = 0;
      for (i = 0; i < gPcmDataChunkCnt; ++i) {
        gpPcmChunkIndex[i] = start;
        start += ((ULONG*)(gpPcmData))[i];
      }
    }
  }

  return ret;
}


// 0040d912
void freeWaveMemory() {
  if (gpPcmData != 0) {
    freeLockedMemory((LPCVOID)gpPcmData);
    gpPcmData = 0;
  }
  if (gpPcmChunkIndex != 0) {
    freeLockedMemory(gpPcmChunkIndex);
    gpPcmChunkIndex = 0;
  }
}


// 0040d97c
BYTE* getPcmChunkStart(int ReqNo, ULONG* pChunkSize) {
  *pChunkSize = ((ULONG*)gpPcmData)[ReqNo];
  return &gpPcmChunkStart[gpPcmChunkIndex[ReqNo]];
}


// 0040d9af
int playWaveRequest(HWND hWnd, WaveInfo *pWaveInfo,int ReqNo) {
  ULONG chunkSize;
  int i, counter;

  pWaveInfo->hWnd = hWnd;
  pWaveInfo->waveHdr.lpData = (LPSTR)getPcmChunkStart(ReqNo, &chunkSize);
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

  for (i = 0; i < gWaveDeviceCnt1; ++i) {
    if (gWaveInfos[i].busy == TRUE) {
      ++counter;
    }
  }
  pWaveInfo->unknown11 = counter;
  pWaveInfo->busy = TRUE;

  return 0;
}


// 0040dac4
int FUN_0040dac4(int waveInfoIndex, int ReqNo, HWND hWnd, BOOL bUnknown) {
  if (gpPcmData == 0) {
    return -1;
  }
  if (ReqNo >= gPcmDataChunkCnt) {
    return -2;
  }
  if (gWaveInfos[waveInfoIndex].busy == FALSE) {
    return playWaveRequest(hWnd, &gWaveInfos[waveInfoIndex], ReqNo);
  }
  if (!bUnknown) {
    return -3;
  }
  if (gWaveInfos[waveInfoIndex].unknownCounter < 1) {
    gWaveInfos[waveInfoIndex].unknown13[gWaveInfos[waveInfoIndex].unknownCounter] = ReqNo;
    ++gWaveInfos[waveInfoIndex].unknownCounter;
    waveOutReset(gWaveInfos[waveInfoIndex].hWaveout);
    return 0;
  }
  else {
    return -4;
  }

  /* unreachable code */
  return playWaveRequest(hWnd, &gWaveInfos[0], ReqNo);
}


// 0040db94
int waveStop(int index) {
  if (gpPcmData == 0) {
    return -1;
  }

  if (gWaveInfos[index].busy == TRUE) {
    gWaveInfos[index].unknownCounter = 0;
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


// 0040dde6
int getFreeWaveInfoIndex() {
  int i;

  for (i = 0; i < gWaveDeviceCnt1; ++i) {
    if (gWaveInfos[i].busy == FALSE) break;
  }
  if (i == gWaveDeviceCnt1) {
    return -1;
    return -1; /* unreachable */
  }

  return i;
}


// 0040de58
int collectWaveInfoUnknown11(int* array) {
  int i;

  for (i = 0; i < gWaveDeviceCnt1; ++i) {
    array[i] = gWaveInfos[i].unknown11;
  }
  return i;
}


// 0040deaa
int checkWaveInfos() {
  int i;

  for (i = 0; i < gWaveDeviceCnt1; ++i) {
    if (gWaveInfos[i].unknownCounter > 0) {
      return -1;
    }
    if (gWaveInfos[i].busy == TRUE) {
      return -1;
    }
  }
}


// 0040df30
BOOL switchGameMenuDll(HWND hWnd, LPCSTR path, USHORT type) {
  char buffer[128];

  if (ghGameMenuDll != 0) {
    FreeLibrary(ghGameMenuDll);
  }
  ghGameMenuDll = LoadLibrary(path);
  if ((ULONG)ghGameMenuDll < 32) {
    wsprintf(buffer, "DLL Load Error!(%u) %s", ghGameMenuDll, path);
    MessageBox(hWnd, buffer, 0, MB_ICONSTOP);
    gbQuit = FALSE;
    return FALSE;
  }

  gpDLLMain = GetProcAddress(ghGameMenuDll, "DLLMain");
  gpDLLInit = (void(*)(DllIn*))GetProcAddress(ghGameMenuDll, "DLLInit");
  gpDLLEnd = GetProcAddress(ghGameMenuDll, "DLLEnd");
  gpSWdataSet = GetProcAddress(ghGameMenuDll, "SWdataSet");
  if (type == 2 || type == 3 || type == 4 || type == 5) {
    gpDLLPaint = (void(*)(HDC))GetProcAddress(ghGameMenuDll, "DLLPaint");
    gpDLLAVIRealize = GetProcAddress(ghGameMenuDll, "DLLAVIRealize");
    gpDLLAVISizeChange = GetProcAddress(ghGameMenuDll, "DLLAVISizeChange");
    gpAVIPause = GetProcAddress(ghGameMenuDll, "AVIPause");
    gpAVIResume = GetProcAddress(ghGameMenuDll, "AVIResume");
  }
  if (type == 3 || type == 4) {
    gpDLLNotify = GetProcAddress(ghGameMenuDll, "DLLNotify");
  }
  if (type == 6) {
    gpDLLChar = GetProcAddress(ghGameMenuDll, "DLLChar");
    gpDLLKeyDown = GetProcAddress(ghGameMenuDll, "DLLKeyDown");
  }
  gGameDllType = type;

  return TRUE;
}


// 0040e14b
BOOL loadOpening(HWND hWnd, LPVOID hSurf) {
  char buffer[128];

  if (!gbFullScreenMenuItemEnabled) {
    gbFullScreenMenuItemEnabled = TRUE;
    enableSubMenuItem(1, ID_OPTIONS_FULLSCREEN, gbFullScreenMenuItemEnabled);
  }
  fillColorwk(0);
  FUN_004051ab();
  if (switchGameMenuDll(hWnd, gOpeningDllPath, 1) == FALSE) {
    MessageBox(0, "DLL Load Error", "Sonic Error", MB_ICONSTOP);
    return FALSE;
  }

  gDllIn.hWnd = (UINT)hWnd;
  gDllIn.hSurf = (UINT)hSurf;
  gDllIn.lpCrntScorData = &gCrntScorData;
  gDllIn.selectIndx = gSelectIndx;
  gDllIn.lpColorwk = gpColorwk;
  gDllIn.lpbFullScreen = (UINT*)&gbFullScreen;
  gDllIn.bFirstTitle = gbFirstTitle;
  gDllIn.CDPlay = (void*)&CDPlay;
  gDllIn.CDPause = (void*)&CDPause;
  gDllIn.ReadScoreData = (void*)&ReadScoreData;
  gDllIn.WriteScoreData = (void*)&WriteScoreData;
  gDllIn.OpenScoreData = (void*)&OpenScoreData;
  gDllIn.CloseScoreData = (void*)&CloseScoreData;
  gDllIn.CreateScoreData = (void*)&CreateScoreData;
  gDllIn.ReadScoreIndx = (void*)&ReadScoreIndx;
  gDllIn.WriteScoreIndx = (void*)&WriteScoreIndx;
  gDllIn.lpUserKey = gUserKey;
  gpDLLInit(&gDllIn);
  makePalette();
  gbGameDllInit = TRUE;
  closeCdAudio();
  if (openCdAudio(buffer, sizeof(buffer)) != 0) {
    MessageBox(hWnd, buffer, "CD Device Error", MB_OK);
  }

  return TRUE;
}


// 0040e2c8
void unloadGameMenuDll() {
  if (gbGameDllInit) {
    (*gpDLLEnd)();
    if (ghGameMenuDll != 0) {
      FreeLibrary(ghGameMenuDll);
      ghGameMenuDll = 0;
    }
    gbGameDllInit = FALSE;
  }
}


// 0040e3d2
BOOL loadAvigood(HWND hWnd) {
  if (gbFullScreenMenuItemEnabled) {
    gbFullScreenMenuItemEnabled = FALSE;
    enableSubMenuItem(1, ID_OPTIONS_FULLSCREEN, gbFullScreenMenuItemEnabled);
  }

  closeWaveOut();
  if (switchGameMenuDll(hWnd,gAvigoodDllPath, 3) == FALSE) {
    return FALSE;
  }

  gDllIn.hWnd = (UINT)hWnd;
  gDllIn.lpUserKey = gUserKey;
  (*gpDLLInit)(&gDllIn);
  gbMoviePlaying = TRUE;
  gbGameDllInit = TRUE;
  InvalidateRect(hWnd, 0, TRUE);
  UpdateWindow(hWnd);

  return TRUE;
}


// 0040e481
BOOL loadAvibad(HWND hWnd) {
  if (gbFullScreenMenuItemEnabled) {
    gbFullScreenMenuItemEnabled = FALSE;
    enableSubMenuItem(1, ID_OPTIONS_FULLSCREEN, gbFullScreenMenuItemEnabled);
  }

  closeWaveOut();
  if (switchGameMenuDll(hWnd, gAvibadDllPath, 4) == FALSE) {
    return FALSE;
  }

  gDllIn.hWnd = (UINT)hWnd;
  gDllIn.lpUserKey = gUserKey;
  (*gpDLLInit)(&gDllIn);
  gbMoviePlaying = TRUE;
  gbGameDllInit = TRUE;
  InvalidateRect(hWnd, 0, TRUE);
  UpdateWindow(hWnd);

  return TRUE;
}


// 0040e6c6
void callDllPaint(HDC hDc) {
  if (gbMoviePlaying) {
    gpDLLPaint(hDc);
  }
}


// 0040e757
void realizeMovie() {
  (*gpDLLAVIRealize)();
}


// 0040ed4f
BOOL playBadEnding() {
  FUN_0040eb80();
  if (gbFullScreen) {
    FUN_004068c4(0);
  }
  if (loadAvigood(ghWnd) == FALSE) {
    return FALSE;
  }
  DAT_004332c4 = TRUE;

  return TRUE;
}


// 0040eda7
BOOL playGoodEnding() {
  FUN_0040eb80();
  if (gbFullScreen) {
    FUN_004068c4(0);
  }
  if (loadAvibad(ghWnd) == FALSE) {
    return FALSE;
  }
  DAT_004332c4 = TRUE;

  return TRUE;
}


// 0040f136
void pauseMovie() {
  (*gpAVIPause)();
}


// 0040f147
void resumeMovie() {
  (*gpAVIResume)();
}


// 0040f160
void WaveRequest(short ReqNo) {
  int waveInfoIndex, waveInfoUnknown11Cnt, i;

  if (gbWaveOpen) {
    waveInfoIndex = getFreeWaveInfoIndex();
    if (waveInfoIndex >= 0) {
      DAT_004331d8 = waveInfoIndex;
      FUN_0040dac4(waveInfoIndex, ReqNo, ghWnd, FALSE);
    }
    else {
      waveInfoUnknown11Cnt = collectWaveInfoUnknown11(gWaveInfoUnknown11Array);
      for (i = 0; i < waveInfoUnknown11Cnt; ++i) {
        if (gWaveInfoUnknown11Array[i] >= 0 && gWaveInfoUnknown11Array[i] < gWaveDeviceCnt2) {
          DAT_004331d8 = gWaveInfoUnknown11Array[i];
          FUN_0040dac4(DAT_004331d8, ReqNo, ghWnd, TRUE);
          break;
        }
      }
    }
  }
}


// 0040f590
int stubbedFunction() {
  return 0;
}


// 0040f5a2
void retrieveDataFilePath(LPSTR pPath) {
  char pathBuffer[260];
  char fileNameBuffer[16];
  int unknown;

  GetPrivateProfileString("Directory", "Install", "", pathBuffer, 260, "SONIC.INI");
  GetPrivateProfileString("DataFile", "FileName", "", fileNameBuffer, 16, "SONIC.INI");
  strcat(pPath, pathBuffer);
  unknown = FUN_004115d0(pPath);
  if (pPath[unknown - 1] != '\\') {
    strcat(pPath, pathBuffer);
  }
  else if (stubbedFunction() != 0) {
    strcat(pPath, "\\");
  }
  strcat(pPath, fileNameBuffer);
}


// 0040f686
void copyScoreData(BYTE* pSource, BYTE* pDestination, ULONG size) {
  int i;
  ULONG unknownValue1;
  BYTE unknownValue2;

  FUN_0041161d(1363);
  for (i = 0; i < size; ++i, ++pDestination, ++pSource) {
    unknownValue1 = FUN_0041162a();
    unknownValue2 = (BYTE)(unknownValue1 >> 31);
    *pDestination = (((BYTE)unknownValue1 ^ unknownValue2) - unknownValue2 ^ unknownValue2) - unknownValue2 ^ *pSource;
  }
}


// 0040f6e4
void copyScoreDataDelegate(BYTE* pSource, BYTE* pDestination, ULONG size) {
  copyScoreData(pSource, pDestination, size);
}


// 0040f703
BOOL verifyScoreDataChecksum(BYTE* pScoreData) {
  ULONG checksum;
  int i;

  checksum = 0;
  for (i = 0; i < 716; ++i) {
    checksum += *pScoreData;
    ++pScoreData;
  }

  if (*(ULONG*)pScoreData == checksum) {
    return TRUE;
  }

  return FALSE;
}


// 0040f769
void updateScoreDataChecksum(BYTE* pScoreData) {
  ULONG checksum;
  int i;

  checksum = 0;
  for (i = 0; i < 716; ++i) {
    checksum += *pScoreData;
    ++pScoreData;
  }

  *(ULONG*)pScoreData = checksum;
}


// 0040f7b3
BOOL ReadScoreData(ULONG index, score_data *pOldScoreData, HFILE hOtherFile) {
  score_data* pScoreData;
  char path[256];
  HFILE hFile;
  ULONG oldIndex;
  int i;

  if (pOldScoreData == 0) {
    pScoreData = &gCrntScorData;
  }
  else {
    pScoreData = pOldScoreData;
  }

  if (hOtherFile == 0) {
    retrieveDataFilePath(path);
    hFile = _lopen(path, OF_READ);
    if (hFile == -1) goto error;
  }
  else {
    hFile = hOtherFile;
  }

  if (_hread(hFile, &oldIndex, sizeof(oldIndex)) != -1) {
    for (i = 0; i < index; ++i) {
      if (_hread(hFile, pScoreData, 720) != -1) goto error;
    }
    if (_hread(hFile, pScoreData, 720) != -1) {
      copyScoreDataDelegate((BYTE*)pScoreData, (BYTE*)pScoreData, 720);
      if (verifyScoreDataChecksum((BYTE*)pScoreData) == TRUE) {
        if (hOtherFile == 0) {
          _lclose(hFile);
        }
        if (pScoreData->saved == 0) {
          initScoreData(pScoreData, index);
        }
        return TRUE;
      }
    }
  }

error:
  if (hOtherFile == 0 && hFile != -1) {
    _lclose(hFile);
  }
  initScoreData(&gCrntScorData, index);
}


// 0040f9d3
BOOL WriteScoreData(int index, score_data* pNewScoreData, HFILE hOtherFile) {
  score_data* pScoreData;
  char path[256];
  HFILE hFile;
  ULONG readIndex;
  int i;
  score_data readScoreData;

  if (pNewScoreData == 0) {
    pScoreData = &gCrntScorData;
  }
  else {
    pScoreData = pNewScoreData;
  }

  if (hOtherFile == 0) {
    retrieveDataFilePath(path);
    hFile = _lopen(path, OF_READWRITE);
    if (hFile == -1) goto error;
  }
  else {
    hFile = hOtherFile;
  }

  if (_hread(hFile, &readIndex, sizeof(readIndex)) != -1) {
    for (i = 0; i < index; ++i) {
      if (_hread(hFile, (LPVOID)&readScoreData, 720) == -1) goto error;
    }
    updateScoreDataChecksum((BYTE*)pScoreData);
    copyScoreData((BYTE*)pScoreData, (BYTE*)&readScoreData, 720);
    if (_hwrite(hFile, (LPCSTR)&readScoreData, 720) != -1) {
      if (hOtherFile == 0) {
        _lclose(hFile);
      }
      return TRUE;
    }
  }

error:
  MessageBox(0, "Save Data Error!\nPlease install SONIC CD again.", "Sonic Error", MB_ICONSTOP);
  if (hOtherFile == 0 && hFile != -1) {
    _lclose(hFile);
  }

  return FALSE;
}


// 0040fb7b
void OpenScoreData(int mode) {
  char path[256];

  retrieveDataFilePath(path);
  _lopen(path, mode);
}


// 0040fbb3
void CloseScoreData(HFILE path) {
  _lclose(path);
}


// 0040fbcf
void CreateScoreData() {
  char path[256];

  retrieveDataFilePath(path);
  _lcreat(path, 0);
}


// 0040fc03
int ReadScoreIndx(HFILE hOtherFile) {
  char path[256];
  HFILE hFile;
  ULONG index;

  if (hOtherFile == 0) {
    retrieveDataFilePath(path);
    hFile = _lopen(path, OF_READ);
    if (hFile == -1) goto error;
  }
  else {
    hFile = hOtherFile;
  }

  if (_hread(hFile, &index, sizeof(index)) != -1) {
    if (hOtherFile == 0) {
      _lclose(hFile);
    }
    gSelectIndx = index;
    return index;
  }

error:
  if (hOtherFile == 0 && hFile != -1) {
    _lclose(hFile);
  }

  return -1;
}


// 0040fcc5
BOOL WriteScoreIndx(ULONG index, HFILE hOtherFile) {
  char path[256];
  HFILE hFile;

  gSelectIndx = index;
  if (hOtherFile == 0) {
    retrieveDataFilePath(path);
    hFile = _lopen(path, OF_WRITE);
    if (hFile == -1) goto error;
  }
  else {
    hFile = hOtherFile;
  }

  if (_hwrite(hFile, (LPSTR)&gSelectIndx, sizeof(gSelectIndx)) != -1) {
    if (hOtherFile == 0) {
      _lclose(hFile);
    }
    return TRUE;
  }

error:
  if (hOtherFile == 0 && hFile != -1) {
    _lclose(hFile);
  }

  return FALSE;
}


// 0040fd87
void initScoreData(score_data* pScoreData, ULONG index) {
  int round, zone, time;

  pScoreData->saved = 0;
  strncpy(pScoreData->player, "PLAYER_1    ", sizeof(pScoreData->player));
  pScoreData->player[7] = (char)index + 49;
  pScoreData->roundNo = 0;
  pScoreData->year = 0;
  pScoreData->month = 0;
  pScoreData->date = 0;

  for (round = 0; round < 7; ++round) {
    for (zone = 0; zone < 3; ++zone) {
      for (time = 0; time < 3; ++time) {
        pScoreData->timeattack[round][zone][time].time = 18000;
        strcat(pScoreData->timeattack[round][zone][time].name, "AAA");
      }
    }
  }

  for (round = 0; round < 7; ++round) {
    for (time = 0; time < 3; ++time) {
      pScoreData->special[round][time].time = 18000;
      strcat(pScoreData->special[round][time].name, "AAA");
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


// 0040ffd8
BOOL initCurrentScoreData() {
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


// 00410130
void CALLBACK timeCallbackFunc(UINT uTimerID, UINT uMsg, DWORD_PTR dwUser, DWORD_PTR dw1, DWORD_PTR dw2) {
  ++(*(ULONG*)dwUser);
}
