#include "DLL.H"
#include <windows.h>
#include "RESOURCE.H"
#include "TYPES.H"
#include "CDAUDIO.H"
#include "GRAPHICS.H"
#include "WAVE.H"
#include "WAVE2.H"
#include "WINMAIN.H"

typedef struct dllIn {
  unsigned int hWnd;
  unsigned int hSurf;
  PALETTEENTRY* lpColorwk;
  unsigned int* lpbFullScreen;
  unsigned int bFirstTitle;
  unsigned int* lpbVisualmode;
  score_data* lpCrntScorData;
  unsigned int selectIndx;
  unsigned short* lpSelectedStage;
  void* ReadScoreData;
  void* WriteScoreData;
  void* OpenScoreData;
  void* CloseScoreData;
  void* CreateScoreData;
  void* ReadScoreIndx;
  void* WriteScoreIndx;
  void* CDPlay;
  void* CDPause;
  void* WaveRequest;
  void* EASetBitmapBits;
  void* EASetBitmapTransparency;
  void* EACreateBitmap;
  void* EADeleteBitmap;
  void* EACreateSequencedSprite;
  void* EASetDestination;
  void* EASetDrawOrder;
  void* EASetPosition;
  void* EADeleteSprite;
  void* EASetSequencedSpriteData;
  void* EACreateFixedGrid;
  void* EACreateTile;
  void* EASetTileData;
  void* EASetFixedGridData;
  void* EASetView;
  void* EASetEffect;
  void* EADeleteFixedGrid;
  void* EADraw;
  void* EAClearEffect;
  void* EADeleteTile;
  void* EASetDestRect;
  unsigned short* lpUserKey;
}
dllIn;

/* 004259c4 */ void(*gpDLLEnd)(char***, void**);
/* 004259c8 */ void(*gpAVIResume)();
/* 004259cc */ int(__stdcall *gpDLLNotify)(WPARAM, LPARAM);
/* 004259d0 */ void(__stdcall *gpDLLInit)(dllIn*);
/* 004259d4 */ HMODULE ghGameMenuDll;
/* 004259d8 */ void(*gpDLLAVIRealize)();
/* 004259dc */ FARPROC gpDLLKeyDown;
/* 004259e0 */ BOOL gbGameDllInit;
/* 004259e4 */ void(*gpDLLChar)(WPARAM, LPARAM);
/* 004259e8 */ void(__stdcall *gpDLLPaint)(HDC);
/* 004259ec */ void(*gpAVIPause)();
/* 004259f0 */ UINT gGameMenuDllType;
/* 004259f4 */ void(*gpDLLAVISizeChange)();
/* 004259f8 */ BOOL DAT_004259f8;
/* 0042ca70 */ score_data gCrntScorData;
/* 0042cd40 */ ULONG gSelectIndx;
/* 0042cd50 */ dllIn gDllIn;
/* 0042cdf4 */ BOOL gbVisualmode;
/* 0042cdf8 */ USHORT gSelectedStage;
/* 0042cdfc */ BOOL gbFirstTitle;
/* 0042cf74 */ int(*gpDLLMain)();
/* 0042cf7c */ HWND ghWnd;
/* 0043031c */ void (__stdcall *gpSWdataSet)(ushort_union, ushort_union);
/* 004320bc */ void* ghSurf = 0;
/* 004331e0 */ BOOL gbRun = TRUE;
/* 00433220 */ USHORT gUserKey[5];
/* 004332c4 */ BOOL gbMenuOrMovieLoaded = FALSE;
/* 004332c8 */ BOOL gbMoviePlaying = FALSE;
/* 0043327c */ PALETTEENTRY* gpColorwk = 0;
/* 0043330c */ BOOL gbFullScreen = FALSE;
/* 00433c40 */ char* gOpeningDllPath;
/* 00433c60 */ char* gAviopenDllPath;
/* 00433c80 */ char* gAvigoodDllPath;
/* 00433c9c */ char* gAvibadDllPath;
/* 00433cd8 */ char* gSavedataDllPath;
/* 00433cf8 */ char* gVisualmdDllPath;
/* 00433d38 */ char* gStagetstDllPath;
/* 00433d58 */ char* gBesttimeDllPath;
/* 00433d5c */ BOOL gbFullScreenMenuItemEnabled = TRUE;


// 0040df30
BOOL switchGameMenuDll(HWND hWnd, char* path, USHORT type) {
  char buffer[128];

  if (ghGameMenuDll != 0) {
    FreeLibrary(ghGameMenuDll);
  }
  ghGameMenuDll = LoadLibrary(path);
  if ((ULONG)ghGameMenuDll < 32) {
    wsprintf(buffer, "DLL Load Error!(%u) %s", ghGameMenuDll, path);
    MessageBox(hWnd, buffer, 0, MB_ICONSTOP);
    gbRun = FALSE;
    return FALSE;
  }

  gpDLLMain = (int(*)())GetProcAddress(ghGameMenuDll, "DLLMain");
  gpDLLInit = (void(__stdcall *)(dllIn*))GetProcAddress(ghGameMenuDll, "DLLInit");
  gpDLLEnd = (void(*)(char***, void**))GetProcAddress(ghGameMenuDll, "DLLEnd");
  gpSWdataSet = (void(__stdcall *)(ushort_union, ushort_union))GetProcAddress(ghGameMenuDll, "SWdataSet");
  if (type == 2 || type == 3 || type == 4 || type == 5) {
    gpDLLPaint = (void(__stdcall *)(HDC))GetProcAddress(ghGameMenuDll, "DLLPaint");
    gpDLLAVIRealize = (void(*)())GetProcAddress(ghGameMenuDll, "DLLAVIRealize");
    gpDLLAVISizeChange = (void(*)())GetProcAddress(ghGameMenuDll, "DLLAVISizeChange");
    gpAVIPause = (void(*)())GetProcAddress(ghGameMenuDll, "AVIPause");
    gpAVIResume = (void(*)())GetProcAddress(ghGameMenuDll, "AVIResume");
  }
  if (type == 3 || type == 4) {
    gpDLLNotify = (int(__stdcall *)(WPARAM, LPARAM))GetProcAddress(ghGameMenuDll, "DLLNotify");
  }
  if (type == 6) {
    gpDLLChar = (void(*)(WPARAM, LPARAM))GetProcAddress(ghGameMenuDll, "DLLChar");
    gpDLLKeyDown = GetProcAddress(ghGameMenuDll, "DLLKeyDown");
  }
  gGameMenuDllType = type;

  return TRUE;
}


// 0040e14b
BOOL loadOpening(HWND hWnd, void* hSurf) {
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
  cdAudio_close();
  if (cdAudio_open(buffer, sizeof(buffer)) != 0) {
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


// 0040e313
void unloadOpening() {
  unloadGameMenuDll();
}


// 0040e323
BOOL loadAviOpen(HWND hWnd) {
  if (gbFullScreenMenuItemEnabled) {
    gbFullScreenMenuItemEnabled = FALSE;
    enableSubMenuItem(1, ID_OPTIONS_FULLSCREEN, gbFullScreenMenuItemEnabled);
  }
  closeWaveOut();
  if (switchGameMenuDll(hWnd, gAviopenDllPath, 2) == FALSE) {
    return FALSE;
  }
  gDllIn.hWnd = (UINT)hWnd;
  gDllIn.lpUserKey = gUserKey;
  gpDLLInit(&gDllIn);
  gbMoviePlaying = TRUE;
  gbGameDllInit = gbMoviePlaying;
  InvalidateRect(hWnd, 0, TRUE);
  UpdateWindow(hWnd);

  return TRUE;
}


// 0040e3d2
BOOL loadAviGood(HWND hWnd) {
  if (gbFullScreenMenuItemEnabled) {
    gbFullScreenMenuItemEnabled = FALSE;
    enableSubMenuItem(1, ID_OPTIONS_FULLSCREEN, gbFullScreenMenuItemEnabled);
  }
  closeWaveOut();
  if (switchGameMenuDll(hWnd, gAvigoodDllPath, 3) == FALSE) {
    return FALSE;
  }
  gDllIn.hWnd = (UINT)hWnd;
  gDllIn.lpUserKey = gUserKey;
  gpDLLInit(&gDllIn);
  gbMoviePlaying = TRUE;
  gbGameDllInit = gbMoviePlaying;
  InvalidateRect(hWnd, 0, TRUE);
  UpdateWindow(hWnd);

  return TRUE;
}


// 0040e481
BOOL loadAviBad(HWND hWnd) {
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
  gpDLLInit(&gDllIn);
  gbMoviePlaying = TRUE;
  gbGameDllInit = gbMoviePlaying;
  InvalidateRect(hWnd, 0, TRUE);
  UpdateWindow(hWnd);

  return TRUE;
}


// 0040e530
BOOL loadAvipen(HWND hWnd) {
  if (gbFullScreenMenuItemEnabled) {
    gbFullScreenMenuItemEnabled = FALSE;
    enableSubMenuItem(1, ID_OPTIONS_FULLSCREEN, gbFullScreenMenuItemEnabled);
  }
  closeWaveOut();
  if (switchGameMenuDll(hWnd, gAvibadDllPath, 5) == FALSE) {
    return FALSE;
  }
  gDllIn.hWnd = (UINT)hWnd;
  gDllIn.lpUserKey = gUserKey;
  gpDLLInit(&gDllIn);
  gbMoviePlaying = TRUE;
  gbGameDllInit = gbMoviePlaying;
  InvalidateRect(hWnd, 0, TRUE);
  UpdateWindow(hWnd);

  return TRUE;
}


// 0040e5df
void unloadAvi(HWND hWnd) {
  if (gbMoviePlaying) {
    unloadGameMenuDll();
    gbMoviePlaying = FALSE;
    InvalidateRect(hWnd, 0, TRUE);
    UpdateWindow(hWnd);
  }
  openWaveOut(hWnd);
  if (gbFullScreen) {
    FUN_004068c4(TRUE);
  }
  if (!gbFullScreenMenuItemEnabled) {
    gbFullScreenMenuItemEnabled = TRUE;
    enableSubMenuItem(1, ID_OPTIONS_FULLSCREEN, gbFullScreenMenuItemEnabled);
  }
}


// 0040e66a
void unloadAviOpen(HWND hWnd) {
  unloadAvi(hWnd);
}


// 0040e681
void unloadAviGood(HWND hWnd) {
  unloadAvi(hWnd);
}


// 0040e698
void unloadAviBad(HWND hWnd) {
  unloadAvi(hWnd);
}


// 0040e6af
void unloadAvipen(HWND hWnd) {
  unloadAvi(hWnd);
}


// 0040e6c6
void callDllPaint(HDC hDc) {
  if (gbMoviePlaying) {
    gpDLLPaint(hDc);
  }
}


// 0040e6e8
void changeMovieSize() {
  (*gpDLLAVISizeChange)();

  return;
}


// 0040e6fe
BOOL FUN_0040e6fe(WPARAM wParam, LPARAM lParam) {
  if (gbMoviePlaying) {
    if (gGameMenuDllType == 3 || gGameMenuDllType == 4) {
      (*gpDLLNotify)(wParam, lParam);
    }
    else {
      FUN_0040ec7b();
      makePalette();
    }
  }

  return TRUE;
}


// 0040e757
void realizeMovie() {
  (*gpDLLAVIRealize)();
}


// 0040e768
BOOL loadSavedata(HWND hWnd, void* hSurf) {
  fillColorwk(0);
  FUN_004051ab();
  if (!switchGameMenuDll(hWnd, gSavedataDllPath, 6)) {
    return FALSE;
  }
  gDllIn.hWnd = (UINT)hWnd;
  gDllIn.hSurf = (UINT)hSurf;
  gDllIn.lpCrntScorData = &gCrntScorData;
  gDllIn.selectIndx = gSelectIndx;
  gDllIn.lpColorwk = gpColorwk;
  gDllIn.ReadScoreData = (void*)&ReadScoreData;
  gDllIn.WriteScoreData = (void*)&WriteScoreData;
  gDllIn.OpenScoreData = (void*)&OpenScoreData;
  gDllIn.CloseScoreData = (void*)&CloseScoreData;
  gDllIn.CreateScoreData = (void*)&CreateScoreData;
  gDllIn.ReadScoreIndx = (void*)&ReadScoreIndx;
  gDllIn.WriteScoreIndx = (void*)&WriteScoreIndx;
  gDllIn.lpUserKey = gUserKey;
  gDllIn.WaveRequest = (void*)&WaveRequest;
  (*gpDLLInit)(&gDllIn);
  DAT_004259f8 = TRUE;
  gbGameDllInit = DAT_004259f8;
  makePalette();

  return TRUE;
}


// 0040e85b
void unloadSavedata() {
  if (DAT_004259f8) {
    unloadGameMenuDll();
    DAT_004259f8 = FALSE;
  }
}


// 0040e882
BOOL loadVisualmd(HWND hWnd, void* hSurf) {
  char buffer[128];

  fillColorwk(0);
  FUN_004051ab();
  if (!switchGameMenuDll(hWnd,gVisualmdDllPath, 7)) {
    return FALSE;
  }

  gDllIn.hWnd = (UINT)hWnd;
  gDllIn.hSurf = (UINT)hSurf;
  gDllIn.lpColorwk = gpColorwk;
  gDllIn.lpbVisualmode = (UINT*)&gbVisualmode;
  gDllIn.lpUserKey = gUserKey;
  gDllIn.CDPlay = (void*)&CDPlay;
  gDllIn.CDPause = (void*)&CDPause;
  (*gpDLLInit)(&gDllIn);
  gbVisualmode = TRUE;
  gbGameDllInit = gbVisualmode;
  cdAudio_close();
  if (cdAudio_open(buffer, 128) != 0) {
    MessageBox(hWnd, buffer, "CD Device Error", MB_OK);
  }
  makePalette();

  return TRUE;
}


// 0040e968
BOOL loadSoundtst(HWND hWnd, void* hSurf) {
  fillColorwk(0);
  FUN_004051ab();
  if (!switchGameMenuDll(hWnd, gVisualmdDllPath, 8)) {
    return FALSE;
  }

  gDllIn.hWnd = (UINT)hWnd;
  gDllIn.hSurf = (UINT)hSurf;
  gDllIn.lpColorwk = gpColorwk;
  gDllIn.CDPlay = (void*)&CDPlay;
  gDllIn.CDPause = (void*)&CDPause;
  gDllIn.WaveRequest = (void*)&WaveRequest;
  gDllIn.lpUserKey = gUserKey;
  (*gpDLLInit)(&gDllIn);
  gbGameDllInit = TRUE;
  makePalette();

  return TRUE;
}


// 0040ea0b
BOOL loadStagetst(HWND hWnd, void* hSurf) {
  fillColorwk(0);
  FUN_004051ab();
  if (!switchGameMenuDll(hWnd, gStagetstDllPath, 9)) {
    return FALSE;
  }

  gDllIn.hWnd = (UINT)hWnd;
  gDllIn.hSurf = (UINT)hSurf;
  gDllIn.lpColorwk = gpColorwk;
  gDllIn.lpSelectedStage = &gSelectedStage;
  gDllIn.lpUserKey = gUserKey;
  (*gpDLLInit)(&gDllIn);
  gbGameDllInit = TRUE;
  makePalette();

  return TRUE;
}


// 0040ea9a
BOOL loadBesttime(HWND hWnd, void* hSurf) {
  fillColorwk('\0');
  FUN_004051ab();
  switchGameMenuDll(hWnd, gBesttimeDllPath, 10);
  gDllIn.hWnd = (UINT)hWnd;
  gDllIn.hSurf = (UINT)hSurf;
  gDllIn.lpColorwk = gpColorwk;
  gDllIn.lpSelectedStage = &gSelectedStage;
  gDllIn.lpUserKey = gUserKey;
  (*gpDLLInit)(&gDllIn);
  gbGameDllInit = TRUE;
  makePalette();

  return TRUE;
}


// 0040eb1a
void unloadBesttime() {
  unloadGameMenuDll();
}


// 0040eb2a
void unloadVisualmd() {
  unloadGameMenuDll();
}


// 0040eb3a
void unloadSoundtst() {
  unloadGameMenuDll();
}


// 0040eb4a
void unloadStagetst() {
  unloadGameMenuDll();
}


// 0040eb5a
void callDllChar(WPARAM wParam, LPARAM lParam) {
  if (DAT_004259f8) {
    (*gpDLLChar)(wParam, lParam);
  }
}


// 0040eb80
void unloadCurrentGameMenuDll() {
  switch (gGameMenuDllType) {
    case 1:
      unloadOpening();
      break;
    case 2:
      unloadAviOpen(ghWnd);
      break;
    case 3:
      unloadAviGood(ghWnd);
      break;
    case 4:
      unloadAviBad(ghWnd);
      break;
    case 5:
      unloadAvipen(ghWnd);
      break;
    case 6:
      unloadSavedata();
      break;
    case 7:
      unloadVisualmd();
      break;
    case 8:
      unloadSoundtst();
      break;
    case 9:
      unloadStagetst();
      break;
    case 10:
      unloadBesttime();
      break;
  }

  gbMenuOrMovieLoaded = FALSE;
  gGameMenuDllType = 0;
}


// 0040ec7b
BOOL FUN_0040ec7b() {
  unloadCurrentGameMenuDll();
  if (gbVisualmode) {
    if (!loadVisualmd(ghWnd, ghSurf)) {
      return FALSE;
    }
    else if (!loadOpening(ghWnd,ghSurf)) {
      return FALSE;
    }
  }
  gbMenuOrMovieLoaded = TRUE;

  return TRUE;
}


// 0040ecf7
BOOL FUN_0040ecf7() {
  unloadCurrentGameMenuDll();
  if (gbFullScreen) {
    FUN_004068c4(FALSE);
  }
  if (!loadAviOpen(ghWnd)) {
    return FALSE;
  }
  gbMenuOrMovieLoaded = TRUE;

  return TRUE;
}


// 0040e3d2
BOOL playBadEnding() {
  unloadCurrentGameMenuDll();
  if (gbFullScreen) {
    FUN_004068c4(FALSE);
  }
  if (!loadAviGood(ghWnd)) {
    return FALSE;
  }
  gbMenuOrMovieLoaded = TRUE;

  return TRUE;
}


// 0040eda7
BOOL playGoodEnding() {
  unloadCurrentGameMenuDll();
  if (gbFullScreen) {
    FUN_004068c4(FALSE);
  }
  if (!loadAviBad(ghWnd)) {
    return FALSE;
  }
  gbMenuOrMovieLoaded = TRUE;

  return TRUE;
}


// 0040edff
BOOL playPen() {
  unloadCurrentGameMenuDll();
  if (gbFullScreen) {
    FUN_004068c4(FALSE);
  }
  if (!loadAvipen(ghWnd)) {
    return FALSE;
  }
  gbMenuOrMovieLoaded = TRUE;

  return TRUE;
}


// 0040ee57
int changeMenuState() {
  if (gbGameDllInit != 0) {
    int next = (*gpDLLMain)();

    switch (next) {
      case 1:
        unloadCurrentGameMenuDll();
        return 1;
      case 2:
        unloadCurrentGameMenuDll();
        return 2;
      case 3:
        unloadCurrentGameMenuDll();
        return 3;
      case 5:
        unloadCurrentGameMenuDll();
        return 4;
      case 7:
        unloadCurrentGameMenuDll();
        return 5;
      case 15:
        unloadCurrentGameMenuDll();
        return 6;
      case 16:
        unloadCurrentGameMenuDll();
        return 7;
      case 17:
        unloadCurrentGameMenuDll();
        if (gbVisualmode) {
          makePalette();
          loadVisualmd(ghWnd, ghSurf);
          gbMenuOrMovieLoaded = TRUE;
          return 0;
        }
        else {
          return 8;
        }
      case 4:
        unloadCurrentGameMenuDll();
        loadSavedata(ghWnd,ghSurf);
        gbMenuOrMovieLoaded = TRUE;
        return 0;
      case 8:
        FUN_0040ecf7();
        return 0;
      case 10:
        playBadEnding();
        return 0;
      case 11:
        playGoodEnding();
        return 0;
      case 12:
        playPen();
        return 0;
      case 9:
        unloadCurrentGameMenuDll();
        makePalette();
        if (gbVisualmode) {
          loadVisualmd(ghWnd, ghSurf);
        }
        else {
          loadOpening(ghWnd, ghSurf);
        }
        gbMenuOrMovieLoaded = TRUE;
        return 0;
      case 6:
        unloadCurrentGameMenuDll();
        loadVisualmd(ghWnd, ghSurf);
        gbMenuOrMovieLoaded = TRUE;
        return 0;
      case 13:
        unloadCurrentGameMenuDll();
        loadSoundtst(ghWnd, ghSurf);
        gbMenuOrMovieLoaded = TRUE;
        return 0;
      case 14:
        unloadCurrentGameMenuDll();
        loadStagetst(ghWnd, ghSurf);
        gbMenuOrMovieLoaded = TRUE;
        return 0;
      case 18:
        unloadCurrentGameMenuDll();
        gbMenuOrMovieLoaded = TRUE;
        return 9;
      case 19:
        unloadCurrentGameMenuDll();
        gbMenuOrMovieLoaded = TRUE;
        return 10;
      case 20:
        unloadCurrentGameMenuDll();
        loadBesttime(ghWnd, ghSurf);
        gbMenuOrMovieLoaded = TRUE;
        return 0;
    }
  }

  return 0;
}


// 0040f136
void pauseMovie() {
  (*gpAVIPause)();
}


// 0040f147
void resumeMovie() {
  (*gpAVIResume)();
}
