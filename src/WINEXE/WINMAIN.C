#include "WINMAIN.H"
#include <windows.h>
#include "RESOURCE.H"
#include "TYPES.H"
#include "CDAUDIO.H"
#include "DLL.H"
#include "GRAPHICS.H"
#include "SPLASH.H"
#include "WAVE.H"
#include "WAVE2.H"
extern void* ghSurf;
extern MCIDEVICEID gMciDeviceId;
extern HPALETTE ghPalette;

/* 00425400 */ HMODULE ghSonicDlg;
/* 00425423 */ char DAT_00425423;
/* 00425428 */ char DAT_00425428;
/* 0042542d */ char DAT_0042542d;
/* 0042542e */ char DAT_0042542e;
/* 0042542f */ char DAT_0042542f;
/* 00425430 */ char DAT_00425430;
/* 00425508 */ void(__stdcall *gpDLLmeminit)(char***, void**);
/* 00425510 */ char gHelpFilePath[80];
/* 00425560 */ void(*gpGameinit)();
/* 00425568 */ JOYCAPS gJoyCapsInfo;
/* 004256fc */ short gStageGameFuncRet;
/* 00425704 */ ULONG gJoystickInput4;
/* 00425708 */ ULONG gJoystickInput1;
/* 0042570c */ BOOL DAT_0042570c;
/* 00425710 */ ULONG gJoystickInput2;
/* 00425714 */ ULONG gJoystickInput3;
/* 00425718 */ USHORT gUserKeyTemp[5];
/* 00425724 */ int(*gpFadeProc)();
/* 0042572c */ UCHAR DAT_0042572c;
/* 004258c4 */ int(*gpGame)();
/* 0042591c */ int(*gpGetscrbhposiw)();
/* 00425928 */ JOYINFOEX gJoyInfo;
/* 0042595c */ int(*gpGetvscroll)();
/* 00425960 */ void(__stdcall *gpSetDebugFlag)(unsigned int);
/* 00425964 */ int(*gpGetscrahposiw)();
/* 00425968 */ void(*gpDLLmemfree)();
/* 0042ca70 */ score_data gCrntScorData;
/* 0042cdf4 */ BOOL gbVisualmode;
/* 0042cdf8 */ USHORT gSelectedStage;
/* 0042cdfc */ BOOL gbFirstTitle;
/* 0042cf70 */ void (__stdcall *gpSpecialblockchg)(unsigned short*, unsigned short*, unsigned short*, unsigned short*);
/* 0042cf78 */ ushort_union gSwdata1;
/* 0042cf7a */ ushort_union gSwdata2;
/* 0042cf7c */ HWND ghWnd;
/* 0042cf80 */ char* gpCmdLine;
/* 0042cf90 */ UCHAR gRecordingBuffer[0x3000];
/* 0042ffa0 */ game_info gKeepWork;
/* 0043031c */ void (__stdcall *gpSWdataSet)(ushort_union, ushort_union);
/* 00430320 */ HINSTANCE ghInstance;
/* 00430324 */ void (__stdcall *gpGetRoundStr)(unsigned short, unsigned char, char*);
/* 004331d0 */ BOOL gbHelpOpen = FALSE;
/* 004331dc */ BOOL gbWaveOpen = FALSE;
/* 004331e0 */ BOOL gbRun = TRUE;
/* 004331e8 */ void* gpDLLmeminitFuncs[12] = {
  &SetGrid,
  &EAsprset,
  0,
  &WaveRequest,
  &CDPlay,
  &CDPause,
  &ChangeTileBmp,
  &ReadScoreIndx,
  &WriteScoreData,
  &SetScoreDate,
  &WaveAllStop,
  &enableSubMenuItem
};
/* 00433218 */ HDC ghDc = 0;
/* 0043321c */ HMODULE ghGameStageDll = 0;
/* 00433220 */ USHORT gUserKey[5] = { VK_LEFT, VK_RIGHT, VK_UP, VK_DOWN, VK_SPACE };
/* 0043322c */ int gUsedMenuId = 0;
/* 00433230 */ char gIdrMenu1[10] = "IDR_MENU1";
/* 0043323c */ char gIdrMenu2[10] = "IDR_MENU2";
/* 00433248 */ char* gMenus[2] = { gIdrMenu1, gIdrMenu2 };
/* 00433250 */ BOOL gbNecComputer = FALSE;
/* 00433254 */ UCHAR gbRecordPlayFlag;
/* 00433258 */ UCHAR DAT_00433258;
/* 0043325c */ short gRecordingBufferReadWriteCnt = 0;
/* 00433260 */ short gRecordingBufferLogicalEntryCnt = 0;
/* 00433264 */ HGLOBAL ghMapwkMemory = 0;
/* 00433268 */ USHORT* gpMapwk = 0;
/* 0043326c */ HGLOBAL ghColorwkMemory = 0;
/* 00433270 */ HGLOBAL ghColorwk2Memory = 0;
/* 00433274 */ HGLOBAL ghColorwk3Memory = 0;
/* 00433278 */ HGLOBAL ghColorwk4Memory = 0;
/* 0043327c */ PALETTEENTRY* gpColorwk = 0;
/* 00433280 */ PALETTEENTRY* gpColorwk2 = 0;
/* 00433284 */ PALETTEENTRY* gpColorwk3 = 0;
/* 00433288 */ PALETTEENTRY* gpColorwk4 = 0;
/* 0043328c */ HGLOBAL ghHscrollbuffMemory = 0;
/* 00433290 */ int_union* gpHscrollbuff = 0;
/* 00433294 */ ULONG gFadeFlag = 0;
/* 00433298 */ MMRESULT gTimeSetEventResult = 0;
/* 0043329c */ long gDemoId = 0;
/* 004332a0 */ BOOL gbEACreated = FALSE;
/* 004332a4 */ BOOL gbGameDllLoaded = FALSE;
/* 004332ac */ long gFpsFlag1 = 2;
/* 004332b0 */ int DAT_004332b0 = 0;
/* 004332b4 */ BOOL DAT_004332b4;
/* 004332b8 */ long gFpsFlag2 = 2;
/* 004332bc */ int DAT_004332bc = 0;
/* 004332c0 */ long gCurrentCdAudioTrack = 1;
/* 004332c4 */ BOOL gbMenuOrMovieLoaded = FALSE;
/* 004332c8 */ BOOL gbMoviePlaying = FALSE;
/* 004332cc */ BOOL DAT_004332cc = FALSE;
/* 004332d0 */ BOOL gbSpecialStageLoaded = FALSE;
/* 004332d4 */ BOOL gbWarpLoaded = FALSE;
/* 004332d8 */ BOOL gbLittlePlanetLoaded = FALSE;
/* 004332dc */ BOOL gbThanksLoaded = FALSE;
/* 004332e0 */ BOOL gbTimeAttackLoaded = FALSE;
/* 004332e4 */ BOOL gbMenuBarVisible = TRUE;
/* 004332e8 */ BOOL gbUsedStageSelect = FALSE;
/* 004332ec */ BOOL gbGamePaused = FALSE;
/* 004332f0 */ BOOL gbRequireCdrom = TRUE;
/* 004332f4 */ BOOL gbCdAudioOpenSuccess = FALSE;
/* 004332f8 */ ULONG gUnknownCdAudioCountdown = 0;
/* 004332fc */ BOOL gbSpriteLoadingEnabled = TRUE;
/* 00433304 */ BOOL gbDebugFlag = FALSE;
/* 00433308 */ UINT gControllerId = 2;
/* 0043330c */ BOOL gbFullScreen = FALSE;
/* 00433310 */ BOOL DAT_00433310 = FALSE;
/* 00433318 */ BOOL gbBetterSoundQuality = FALSE;
/* 0043331c */ BOOL gbCanPauseOrRestart = FALSE;
/* 00433320 */ BOOL gbRestartStage = FALSE;
/* 00433324 */ BOOL DAT_00433324 = FALSE;
/* 00433328 */ int gEndingMovieFlag = 0;
/* 0043332c */ BOOL DAT_0043332c = FALSE;
/* 00433330 */ BOOL DAT_00433330 = FALSE;
/* 00433334 */ BOOL DAT_00433334 = FALSE;
/* 00433338 */ void* gGameMemory[11] = {
  gpMapwk,
  gpColorwk,
  gpColorwk2,
  gpColorwk3,
  gpColorwk4,
  gpHscrollbuff,
  &gFadeFlag,
  &gKeepWork,
  &ghSurf,
  &ghWnd,
  &gCrntScorData
};
/* 00433364 */ int gTimerTickCnt = 0;
/* 00433368 */ BOOL gbGoSpecial = FALSE;


// 00407060
BOOL menuOrMovieLoop() {
  uint_union local_8;
  if (++DAT_004332bc >= gFpsFlag2) {
    DAT_004332bc = 0;
    DAT_004332b4 = TRUE;
  }
  readController(FALSE);
  if (gbMoviePlaying == FALSE) {
    makePalette2();
  }

  switch (changeMenuState()) {
    case 1: // New Game
      if (FUN_0041004a() == 0) {
        gbMenuOrMovieLoaded = loadOpening(ghWnd, ghSurf);
      }
      else {
        gKeepWork.play_start = 0;
        gKeepWork.plflag = 0;
        gKeepWork.clrspflg_save = 0;
        gKeepWork.stagenm = 0;
        gKeepWork.emie3end = 0;
        if (loadStageByMenu(ID_STAGE_R11A) == 0) {
          return FALSE;
        }
      }
      break;
    case 2: // Continue
      ReadScoreData(ReadScoreIndx(0), 0, 0);
      gKeepWork.play_start = 0;
      gKeepWork.plflag = 0;
      gKeepWork.clrspflg_save = gCrntScorData.clrspflg_save;
      gKeepWork.stagenm = gCrntScorData.stagenm;
      gKeepWork.emie3end = 0;
      if (gCrntScorData.roundNo < 7) {
        local_8.w.l = gCrntScorData.roundNo * 10 + 400;
      }
      else {
        local_8.w.l = ID_STAGE_R81A;
      }
      if (loadStageByMenu(local_8.w.l) == 0) {
        return FALSE;
      }
      break;
    case 3:
      if (!loadTimeAttack(TRUE)) {
        return FALSE;
      }
      break;
    case 4:
      if (!loadPlanet()) {
        return FALSE;
      }
      break;
    case 5:
      if (gDemoId == 0) {
        CDPause();
        FUN_0040ecf7();
      }
      else {
        gKeepWork.demoflag.w = -1;
        gbRecordPlayFlag = TRUE;
        gRecordingBufferReadWriteCnt = 0;
        gKeepWork.play_start = 0;
        switch (gDemoId) {
          case 1:
            if (loadStageByMenu(ID_STAGE_R11A) == 0) {
              return FALSE;
            }
            break;
          case 2:
            if (!loadSpecialStage(ID_STAGE_SPECIAL_R1)) {
              return FALSE;
            }
            break;
          case 3:
            gKeepWork.play_start = 2;
            if (loadStageByMenu(ID_STAGE_R43C) == 0) {
              return FALSE;
            }
            break;
          case 4:
            if (!loadSpecialStage(ID_STAGE_SPECIAL_R6)) {
              return FALSE;
            }
            break;
          case 5:
            gKeepWork.play_start = 2;
            if (loadStageByMenu(ID_STAGE_R82A) == 0) {
              return FALSE;
            }
            break;
        }
        readRecording();
      }
      ++gDemoId;
      if (gDemoId > 5) {
        gDemoId = 0;
      }
      break;
    case 6:
      gKeepWork.plflag = 0;
      gKeepWork.clrspflg_save = 0;
      gKeepWork.stagenm = 0;
      if (loadStageByMenu(gSelectedStage) == 0) {
        return FALSE;
      }
      gbUsedStageSelect = TRUE;
      break;
    case 7:
      makePalette();
      unloadCurrentGameMenuDll();
      if (gbFullScreen == TRUE) {
        gKeepWork.EndingMesType = 1;
      }
      else {
        gKeepWork.EndingMesType = 129;
      }
      if (!loadThanks()) {
        return FALSE;
      }
      break;
    case 8:
      makePalette();
      if (gbFullScreen == TRUE) {
        gKeepWork.EndingMesType = 2;
      }
      else {
        gKeepWork.EndingMesType = 130;
      }
      if (!loadThanks()) {
        return FALSE;
      }
      break;
    case 9:
      gKeepWork.ta_flag = 1;
      if (!loadSpecialStage(477)) {
        return FALSE;
      }
      break;
    case 10:
      if (gbDebugFlag == FALSE) {
        gbDebugFlag = TRUE;
      }
      else {
        gbDebugFlag = FALSE;
      }
      checkSubMenuItem(4, ID_FUNC_DEBUGFLAG, gbDebugFlag);
      gbMenuOrMovieLoaded = loadOpening(ghWnd, ghSurf);
      break;
    default:
      break;
  }

  return TRUE;
}


// 004074de
BOOL specialStageLoop() {
  HCURSOR hCursor;
  if (gFadeFlag != 0) {
    ++DAT_004332b0;
    if (DAT_004332b0 >= 3) {
      DAT_004332b0 = 0;
      (*gpFadeProc)();
      makePalette2();
    }
  }
  else {
    if (++DAT_004332bc >= gFpsFlag2) {
      DAT_004332bc = 0;
      DAT_004332b4 = TRUE;
    }
    ++DAT_004332b0;
    if (DAT_004332b0 >= 3) {
      DAT_004332b0 = 0;
      readController(TRUE);
      if (gbRecordPlayFlag == FALSE && gKeepWork.demoflag.w == -1) {
        gKeepWork.demoflag.w = 0;
        restartGame();
        return TRUE;
      }
      if (gKeepWork.SPEMode != 0 && gKeepWork.stagenm == 7) {
        unloadGame();
        gbSpecialStageLoaded = FALSE;
        gKeepWork.ta_flag = 0;
        gbMenuOrMovieLoaded = loadOpening(ghWnd, ghSurf);
        return TRUE;
      }
      if (gKeepWork.SPEMode == 1) {
        CDPause();
        EADelete();
        if (!EACreate()) {
          showCustomError(2, 0);
          gbEACreated = FALSE;
          return FALSE;
        }
      }
      else if (gKeepWork.SPEMode == 2);
      else if (gKeepWork.SPEMode == 4 || gKeepWork.SPEMode == 6) {
        unloadGame();
        gbSpecialStageLoaded = FALSE;
        hCursor = SetCursor(LoadCursor(0, IDC_WAIT));
        if (gKeepWork.ta_flag != 0) {
          if (!loadTimeAttack(FALSE)) {
            return FALSE;
          }
        }
        else {
          ++gKeepWork.stagenm;
          if (gKeepWork.stagenm > 6) {
            gKeepWork.stagenm = 0;
          }
          gCrntScorData.clrspflg_save = gKeepWork.clrspflg_save;
          gCrntScorData.stagenm = gKeepWork.stagenm;
          if (loadStageByMenu(0) == 0) {
            return FALSE;
          }
        }
        SetCursor(hCursor);
        return TRUE;
      }
      (*gpGame)();
      FUN_004054ee();
    }
  }

  return TRUE;
}


// 0040773d
BOOL littlePlanetLoop() {
  if (gFadeFlag != 0) {
    if ((*gpFadeProc)() != 0) {
      gFadeFlag = 0;
    }
    makePalette2();
  }
  else if (gbEACreated == TRUE) {
    if (++DAT_004332bc >= gFpsFlag2) {
      DAT_004332bc = 0;
      DAT_004332b4 = TRUE;
    }
    readController(FALSE);
    if (DAT_004332b0 + 1 < gFpsFlag1) {
      gKeepWork.GamePass = 1;
    }
    else {
      gKeepWork.GamePass = 0;
    }
    if ((*gpGame)() != 0) {
      unloadGame();
      gbLittlePlanetLoaded = FALSE;
      gbMenuOrMovieLoaded = loadOpening(ghWnd, ghSurf);
      return TRUE;
    }
    if (++DAT_004332b0 >= gFpsFlag1) {
      DAT_004332b0 = 0;
      FUN_00405c75();
    }
  }

  return TRUE;
}


// 00407854
BOOL thanksLoop() {
  if (gFadeFlag != 0) {
    if ((*gpFadeProc)() != 0) {
      gFadeFlag = 0;
    }
    makePalette2();
  }
  else if (gbEACreated == TRUE) {
    if (++DAT_004332bc >= gFpsFlag2) {
      DAT_004332bc = 0;
      DAT_004332b4 = 1;
    }
    readController(FALSE);
    if (DAT_004332b0 + 1 < gFpsFlag1) {
      gKeepWork.GamePass = 1;
    }
    else {
      gKeepWork.GamePass = 0;
    }
    if ((*gpGame)() != 0) {
      unloadGame();
      gbThanksLoaded = FALSE;
      if (gbVisualmode) {
        FUN_0040ec7b();
      }
      else {
        gbMenuOrMovieLoaded = loadOpening(ghWnd, ghSurf);
      }
      return TRUE;
    }
    if (++DAT_004332b0 >= gFpsFlag1) {
      DAT_004332b0 = 0;
      FUN_00405dbd();
    }
  }

  return TRUE;
}


BOOL timeAttackLoop() {
  int local_c;
  HCURSOR hCursor;
  if (gFadeFlag != 0) {
    if ((*gpFadeProc)() != 0) {
      gFadeFlag = 0;
    }
    makePalette2();
  }
  else {
    if (++DAT_004332bc >= gFpsFlag2) {
      DAT_004332bc = 0;
      DAT_004332b4 = TRUE;
    }
    readController(FALSE);
    local_c = (*gpGame)();
    makePalette2();
    if (local_c != 0) {
      makePalette2();
      gbTimeAttackLoaded = FALSE;
      if (local_c == -1) {
        gKeepWork.ta_flag = 0;
        gbMenuOrMovieLoaded = loadOpening(ghWnd, ghSurf);
      }
      else {
        gKeepWork.play_start = 0;
        gKeepWork.ta_flag = 1;
        hCursor = SetCursor(LoadCursor(0, IDC_WAIT));
        if (local_c >= ID_STAGE_R11A && local_c <= ID_STAGE_R83D) {
          if (loadStageByMenu(local_c) == 0) {
            return FALSE;
          }
        }
        else {
          if (!loadSpecialStage(local_c)) {
            return FALSE;
          }
        }
        SetCursor(hCursor);
      }
    }
  }

  return TRUE;
}


// 00407ad8
BOOL warpLoop() {
  int_union vscroll;
  int_union scrahposiw;
  int_union scrbhposiw;
  if (gFadeFlag != 0) {
    if ((*gpFadeProc)() != 0) {
      gFadeFlag = 0;
    }
    makePalette2();
  }
  else if (gbEACreated == TRUE) {
    if (++DAT_004332bc >= gFpsFlag2) {
      DAT_004332bc = 0;
      DAT_004332b4 = TRUE;
    }
    if (DAT_004332b0 + 1 < gFpsFlag1) {
      gKeepWork.GamePass = 1;
    }
    else {
      gKeepWork.GamePass = 0;
    }
    if ((*gpGame)() != 0) {
      gbWarpLoaded = FALSE;
      if (loadStageByMenu(0) == 0) {
        return FALSE;
      }
      return TRUE;
    }
    makePalette2();
    vscroll.l = (*gpGetvscroll)();
    scrahposiw.l = (*gpGetscrahposiw)();
    scrbhposiw.l = (*gpGetscrbhposiw)();
    if (++DAT_004332b0 >= gFpsFlag1) {
      DAT_004332b0 = 0;
      // movswl instead of mov
      mapinit(scrahposiw.w.h, vscroll.w.h, scrbhposiw.w.h, vscroll.w.l);
      makePalette2();
    }
  }

  return TRUE;
}


// 00407c1b
BOOL stageLoop() {
  HCURSOR hCursor;
  int_union vscroll;
  int_union scrahposiw;
  int_union scrbhposiw;
  if (gFadeFlag != 0) {
    if ((*gpFadeProc)() != 0) {
      gFadeFlag = 0;
    }
    makePalette2();
  }
  else if (gbEACreated == TRUE) {
    if (++DAT_004332bc >= gFpsFlag2) {
      DAT_004332bc = 0;
      DAT_004332b4 = TRUE;
    }
    readController(TRUE);
    if (gbRecordPlayFlag == 0 && gKeepWork.demoflag.w == -1) {
      gKeepWork.demoflag.w = 0;
      restartGame();
      return TRUE;
    }
    if (DAT_004332b0 + 1 < gFpsFlag1) {
      gKeepWork.GamePass = 1;
    }
    else {
      gKeepWork.GamePass = 0;
    }
    gStageGameFuncRet = (*gpGame)();
    if (gStageGameFuncRet != 0 || gbRecordPlayFlag != 0 || gKeepWork.demoflag.w != 0) {
      gbCanPauseOrRestart = FALSE;
    }
    else {
      gbCanPauseOrRestart = TRUE;
    }
    enableSubMenuItem(0, ID_PAUSEGAME, gbCanPauseOrRestart);
    enableSubMenuItem(0, ID_RESTARTSTAGE, gbCanPauseOrRestart);
    if (gbGoSpecial) {
      gbGoSpecial = FALSE;
      gKeepWork.special_flag = 1;
      gStageGameFuncRet = 2;
      gKeepWork.play_start = 1;
      goto L1F5;
    }
    if (gStageGameFuncRet != 0) {
      DAT_004332cc = FALSE;
      if (gbUsedStageSelect) {
        gbUsedStageSelect = FALSE;
        unloadGame();
        gbMenuOrMovieLoaded = FALSE;
        gbMenuOrMovieLoaded = loadOpening(ghWnd, ghSurf);
        return TRUE;
      }
      else if (gStageGameFuncRet & 2) {
L1F5:
        DAT_004332cc = FALSE;
        hCursor = SetCursor(LoadCursor(0, IDC_WAIT));
        gKeepWork.plflag = 0;
        gKeepWork.projector_flag = 0;
        if (gKeepWork.ta_flag != 0) {
          if (!loadTimeAttack(FALSE)) {
            return 0;
          }
        }
        else if (gKeepWork.special_flag != 0) {
          if (!loadSpecialStage(0)) {
            return 0;
          }
        }
        else {
          if (gKeepWork.stageno.b.l == 0) {
            if (DAT_0042570c == TRUE) {
              gCrntScorData.clrgood |= 1 << gKeepWork.stageno.b.h - 1;
            }
            gCrntScorData.roundNo = gKeepWork.stageno.b.h;
            SetScoreDate(0);
          }
          if (gKeepWork.stageno.w == 0x0700) {
            unloadGame();
            if (gKeepWork.clrspflg_save == 127 || gCrntScorData.clrgood == 127) {
              gEndingMovieFlag = 1;
            }
            else {
              gEndingMovieFlag = 2;
            }
            ReadScoreData(ReadScoreIndx(0), 0, 0);
            gCrntScorData.roundNo = 7;
            WriteScoreData(ReadScoreIndx(0), 0, 0);
          }
          else {
            WriteScoreData(ReadScoreIndx(0), 0, 0);
            if (loadStageByMenu(0) == 0) {
              return 0;
            }
          }
        }
        SetCursor(hCursor);
      }
      else if (gStageGameFuncRet & 1) {
        if (gKeepWork.ta_flag != 0) {
          if (!loadTimeAttack(FALSE)) {
            return 0;
          }
        }
        else if (gKeepWork.pl_suu != 0) {
          CDPause();
          (*gpGameinit)();
          FUN_004051ab();
        }
        else {
          hCursor = SetCursor(LoadCursor(0, IDC_WAIT));
          unloadGame();
          gbMenuOrMovieLoaded = loadOpening(ghWnd, ghSurf);
          SetCursor(hCursor);
        }
      }
      else if (gStageGameFuncRet & 0x100) {
        hCursor = SetCursor(LoadCursor(0, IDC_WAIT));
        if (!loadWarp()) {
          return 0;
        }
        gKeepWork.plflag = 2;
        SetCursor(hCursor);
        gKeepWork.time_flag |= 0x80;
      }
    }
    else {
      vscroll.l = (*gpGetvscroll)();
      scrahposiw.l = (*gpGetscrahposiw)();
      scrbhposiw.l = (*gpGetscrbhposiw)();
      if (++DAT_004332b0 >= gFpsFlag1) {
        DAT_004332b0 = 0;
        // movsx instead of mov
        mapinit(scrahposiw.w.h, vscroll.w.h, scrbhposiw.w.h, vscroll.w.l);
        makePalette2();
      }
    }
  }

  return TRUE;
}


void CALLBACK timeCallbackFunc(UINT uTimerID, UINT uMsg, ULONG dwUser, ULONG dw1, ULONG dw2);

// 00408107
void setupTimer() {
  gTimeSetEventResult = timeSetEvent(16, 1, timeCallbackFunc, (DWORD)&gTimerTickCnt, TIME_PERIODIC);
  if (gTimeSetEventResult == 0) {
    log("failed on timeSetEvent\n\r");
    timeEndPeriod(1);
  }
  gTimerTickCnt = 0;

  return;
}


// 0040815e
void killTimer() {
  if (gTimeSetEventResult != 0) {
    timeKillEvent(gTimeSetEventResult);
    timeEndPeriod(1);
    gTimeSetEventResult = 0;
  }

  return;
}


// 00408199
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
  MSG msg;
  if (isGameInUse()) {
    MessageBox(ghWnd, "SONIC CD is already in use.", "SONIC CD Error", MB_ICONSTOP);
    return 0;
  }
  if (hPrevInstance == 0) {
    if (registerWindowClass(hInstance) == 0) {
      return 0;
    }
    gpCmdLine = lpCmdLine;
  }
  if (makeWindow(hInstance, nCmdShow) == FALSE) {
    return 0;
  }
  if (startGame() != 0) {
    freeAllocatedMemory();
    return 0;
  }
  if (timeBeginPeriod(1) == TIMERR_NOCANDO) {
    MessageBox(ghWnd, "Can't handle the timer resolution", "timeBeginPeriod()", MB_OK);
  }
  setupTimer();
  setupJoystick();
  gControllerId = 2;
  modifyControllerMenuItemText(gControllerId);

  while (1) {
    if (PeekMessage(&msg, 0, 0, 0, PM_REMOVE)) {
      if (msg.message == WM_QUIT) break;
      TranslateMessage(&msg);
      DispatchMessage(&msg);
    }
    else if (gbRun == TRUE && !IsIconic(ghWnd)){
      if (DAT_00433324) {
        toggleSoundQuality();
      }
      else if (gEndingMovieFlag != 0) {
        if (areWaveInfosFree() == 0) {
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
        if (gUnknownCdAudioCountdown != 0 && --gUnknownCdAudioCountdown == 0 && gCurrentCdAudioTrack != -1) {
          changeMusic();
        }
        gTimerTickCnt--;
        if (gTimerTickCnt > 10) {
          gTimerTickCnt = 0;
        }
        if (gbLittlePlanetLoaded) {
          gbRun = littlePlanetLoop();
        }
        else if (gbThanksLoaded) {
          gbRun = thanksLoop();
        }
        else if (gbWarpLoaded) {
          gbRun = warpLoop();
        }
        else if (gbMenuOrMovieLoaded) {
          gbRun = menuOrMovieLoop();
        }
        else if (gbSpecialStageLoaded) {
          gbRun = specialStageLoop();
        }
        else if (gbTimeAttackLoaded) {
          gbRun = timeAttackLoop();
        }
        else {
          gbRun = stageLoop();
        }
      }
      if (!gbRun) {
        DestroyWindow(ghWnd);
      }
    }
  }

  killTimer();
  unloadGame();

  return msg.wParam;
}


// 00408488
ATOM registerWindowClass(HINSTANCE hInstance) {
  WNDCLASS wndClass;
  loadIni();
  wndClass.style = CS_HREDRAW | CS_VREDRAW;
  wndClass.lpfnWndProc = WndProc;
  wndClass.cbClsExtra = 0;
  wndClass.cbWndExtra = 0;
  wndClass.hInstance = hInstance;
  wndClass.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(101));
  wndClass.hCursor = LoadCursor(0, IDC_ARROW);
  wndClass.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);
  wndClass.lpszMenuName = gMenus[gUsedMenuId];
  wndClass.lpszClassName = "SONICCDClass";
  LoadAccelerators(hInstance, "IDR_ACCELERATOR1");
  // missing and 0xFFFF
  return RegisterClass(&wndClass);
}


// 00408520
BOOL makeWindow(HINSTANCE hInstance, int nCmdShow) {
  int style;
  BOOL bMenu;
  RECT rect;
  USHORT key;
  int width;
  int height;
  RECT desktopRect;
  int desktopWidth;
  int desktopHeight;
  HWND hWnd;
  ghInstance = hInstance;
  style = WS_CAPTION | WS_SYSMENU;
  bMenu = TRUE;
  rect.top = 0;
  rect.left = 0;
  rect.bottom = 224;
  rect.right = 319;
  AdjustWindowRect(&rect, style, bMenu);
  key = GetProfileInt("windows", "BorderWidth", -1);
  if (rect.top < 0) {
    rect.bottom = rect.top * -1 + rect.bottom;
    rect.top = 0;
  }
  if (rect.left < 0) {
    rect.right = rect.left * -1 + rect.right;
    rect.left = 0;
  }
  width = (rect.right - rect.left) + 1;
  height = (rect.bottom - rect.top) + 1;
  GetWindowRect(GetDesktopWindow(), &desktopRect);
  desktopWidth = desktopRect.right - desktopRect.left + 1;
  desktopHeight = desktopRect.bottom - desktopRect.top + 1;
  rect.top = (desktopHeight - height) / 2;
  rect.left = (desktopWidth - width) / 2;
  rect.bottom = height + rect.top - 1;
  rect.right = width + rect.left - 1;
  hWnd = CreateWindowEx(0, "SONICCDClass", "SONIC CD", WS_MINIMIZEBOX | WS_SYSMENU | WS_CAPTION, rect.left, rect.top, rect.right - rect.left + 1, rect.bottom - rect.top + 1, 0, 0, hInstance, 0);
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
  hMenu = GetSubMenu(GetMenu(ghWnd), subMenuPos);
  if (bCheck == TRUE) {
    flags = MF_CHECKED;
  }
  else {
    flags = MF_UNCHECKED;
  }
  CheckMenuItem(hMenu, menuItemId, flags);

  return;
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
  if (GetDriveType("a:") != DRIVE_REMOVABLE) {
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
  char* path = "d:\\soniccd.chk";
  char drive[3];
  uint_union result;
  drive[0] = GetPrivateProfileInt("Directory", "CD", 3, "sonic.ini") + 97;
  drive[1] = ':';
  drive[2] = '\0';
  result.w.l = GetDriveType(drive);
  if (result.w.l != DRIVE_CDROM) {
    MessageBox(0, "CD drive is not found.", "Sonic Error", MB_ICONSTOP);
    return FALSE;
  }
  path[0] = drive[0];
  result.w.l = _lopen(path, OF_READ);
  if (result.w.l == (USHORT)HFILE_ERROR) {
    MessageBox(0, "CD check file is not found.", "Sonic Error", MB_ICONSTOP);
    return FALSE;
  }
  _lclose(result.l);
  return TRUE;
}



// 0040886e
BOOL isGameInUse() {
  if (FindWindow(0, "SONIC CD")) {
    return TRUE;
  }

  return FALSE;
}


// 0040889f
void __stdcall enableSubMenuItem(int subMenuPos, UINT menuItemId, BOOL bEnable) {
  HMENU hMenu;
  UINT flags;
  hMenu = GetSubMenu(GetMenu(ghWnd), subMenuPos);
  if (bEnable == TRUE) {
    flags = MF_ENABLED;
  }
  else {
    flags = MF_GRAYED | MF_DISABLED;
  }
  EnableMenuItem(hMenu, menuItemId, flags);

  return;
}


// 004088fd
void modifyFramesMenuItemText(int flag) {
  HMENU hMenu;
  char buffer[128];
  hMenu = GetSubMenu(GetMenu(ghWnd), 1);
  if (flag == 1) {
    LoadString(ghInstance, IDS_FASTSONIC, buffer, 128);
    ModifyMenu(hMenu, 207, 0, 207, buffer);
  }
  else {
    LoadString(ghInstance, IDS_SMOOTHSONIC, buffer, 128);
    ModifyMenu(hMenu, 207, 0, 207, buffer);
  }
}


// 004089a6
void modifyControllerMenuItemText(USHORT controllerId) {
  HMENU hMenu;
  char buffer[128];
  hMenu = GetSubMenu(GetMenu(ghWnd), 1);
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
void __stdcall toggleSoundQuality() {
  short trackNumber;
  HMENU hMenu;
  char str[128];
  HCURSOR hCursor;
  int result;
  if (gbMoviePlaying) return;
  if (areWaveInfosFree() != 0) {
    DAT_00433324 = TRUE;
    return;
  }
  DAT_00433324 = FALSE;
  if (gbCdAudioOpenSuccess == TRUE && gCurrentCdAudioTrack > 0) {
    trackNumber = gCurrentCdAudioTrack + 1;
    CDPause();
  }
  else {
    trackNumber = 0;
  }
  gbBetterSoundQuality = !gbBetterSoundQuality;
  hMenu = GetSubMenu(GetMenu(ghWnd), 1);
  if (gbBetterSoundQuality) {
    LoadString(ghInstance, IDS_GOODSOUNDQUALITY, str, sizeof(str));
    ModifyMenu(hMenu, ID_BETTERSOUNDQUALITY, MF_BYCOMMAND | MF_STRING, ID_BETTERSOUNDQUALITY, str);
  }
  else {
    LoadString(ghInstance, IDS_BETTERSOUNDQUALITY, str, sizeof(str));
    ModifyMenu(hMenu, ID_BETTERSOUNDQUALITY, MF_BYCOMMAND |MF_STRING, ID_BETTERSOUNDQUALITY, str);
  }
  closeWaveOut();
  freeWaveMemory();
  hCursor = SetCursor(LoadCursor(0, IDC_WAIT));
  if (gbBetterSoundQuality) {
    lstrcpy(str, "pcm.cmp");
  }
  else {
    lstrcpy(str, "pcm8.cmp");
  }
  result = loadPcmFile(str);
  if (result != 0) {
    showCustomError(result, str);
    gbWaveOpen = FALSE;
  }
  else {
    openWaveOut(ghWnd);
    gbWaveOpen = TRUE;
  }
  if (trackNumber != 0) {
    CDPlay(trackNumber);
  }
  SetCursor(hCursor);
}


// 00408c6c
void retrieveHelpFilePath() {
  if (GetPrivateProfileString("Directory", "Install", "", gHelpFilePath, sizeof(gHelpFilePath), "sonic.ini") != 0) {
    strcat(gHelpFilePath, "\\");
    strcat(gHelpFilePath, "sonic.hlp");
  }
  else {
    strcat(gHelpFilePath, "sonic.hlp");
  }
}


// 00408cdb
void toggleMouseCursor() {
  POINT point;
  if (gbMoviePlaying == FALSE) {
    if (ghSurf != 0) {
      if (gbFullScreen == FALSE) {
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
        ++point.x;
      }
      SetCursorPos(point.x, point.y);
    }
  }
}


// 00408d86
void toggleMenuBar() {
  DWORD style;
  RECT rect1;
  RECT rect2;
  style = WS_CAPTION | WS_SYSMENU;
  if (!gbMenuBarVisible) {
    gbMenuBarVisible = TRUE;
  }
  else {
    gbMenuBarVisible = FALSE;
  }
  if (!gbFullScreen) {
    GetWindowRect(ghWnd, &rect1);
    rect2.left = 0;
    rect2.right = 320;
    rect2.top = 0;
    rect2.bottom = 224;
    if (gbMenuBarVisible) {
      SetMenu(ghWnd, LoadMenu(ghInstance, gMenus[gUsedMenuId]));
      DrawMenuBar(ghWnd);
      AdjustWindowRect(&rect2, style, TRUE);
      ++rect2.bottom;
    }
    else {
      DestroyMenu(GetMenu(ghWnd));
      DrawMenuBar(ghWnd);
      AdjustWindowRect(&rect2, style, FALSE);
    }
    MoveWindow(ghWnd, rect1.left, rect1.top, rect2.right - rect2.left, rect2.bottom - rect2.top, TRUE);
  }

  return;
}


// 00408ea9
void unloadGame() {
  CDPause();
  unloadCurrentGameMenuDll();
  if (gbGameDllLoaded == TRUE) {
    gbGameDllLoaded = FALSE;
    (*gpDLLmemfree)();
    FreeLibrary(ghGameStageDll);
  }
  if (gbEACreated == TRUE) {
    EADelete();
    gbEACreated = FALSE;
  }
  resetInput();

  return;
}


// 00408f0d
void restartGame() {
  CDPause();
  unloadGame();
  gbMoviePlaying = FALSE;
  DAT_004332cc = FALSE;
  gbSpecialStageLoaded = FALSE;
  gbWarpLoaded = FALSE;
  gbLittlePlanetLoaded = FALSE;
  gbThanksLoaded = FALSE;
  gbTimeAttackLoaded = FALSE;
  gbUsedStageSelect = FALSE;
  gbVisualmode = FALSE;
  gbGamePaused = FALSE;
  gbDebugFlag = FALSE;
  gKeepWork.ta_flag = 0;
  gKeepWork.bRestart = 0;
  gKeepWork.demoflag.w = 0;
  gbRecordPlayFlag = FALSE;
  gbMenuOrMovieLoaded = FALSE;
  gbMenuOrMovieLoaded = loadOpening(ghWnd, ghSurf);
  gbCanPauseOrRestart = FALSE;
  gbRestartStage = FALSE;
  enableSubMenuItem(0, ID_PAUSEGAME, FALSE);
  enableSubMenuItem(0, ID_RESTARTSTAGE, FALSE);

  return;
}


// 00409000
void changeControls() {
  gUserKeyTemp[0] = gUserKey[0];
  gUserKeyTemp[1] = gUserKey[1];
  gUserKeyTemp[2] = gUserKey[2];
  gUserKeyTemp[3] = gUserKey[3];
  gUserKeyTemp[4] = gUserKey[4];
  showSonicDlg(ghWnd, "SONICDLG_KEYS", "KeySettingDialog", (LPARAM)gUserKeyTemp);
  gUserKey[0] = gUserKeyTemp[0];
  gUserKey[1] = gUserKeyTemp[1];
  gUserKey[2] = gUserKeyTemp[2];
  gUserKey[3] = gUserKeyTemp[3];
  gUserKey[4] = gUserKeyTemp[4];

  return;
}


// 004090a5
void showGoodEndFlags() {
  char bigBuffer[256];
  int i;
  ULONG bitFlag;
  char smallBuffer[80];
  lstrcpy(bigBuffer, "Clear Special ");

  for (i = 0, bitFlag = 1; i < 7; ++i, bitFlag <<= 1) {
    if (gKeepWork.clrspflg_save & bitFlag) {
      wsprintf(smallBuffer, "%d ", i + 1);
    }
    else {
      lstrcpy(smallBuffer, "_ ");
    }
    lstrcat(bigBuffer, smallBuffer);
    ;
  }

  lstrcat(bigBuffer, "\n\rClear Good Future");

  for (i = 0, bitFlag = 1; i < 7; ++i, bitFlag <<= 1) {
    if (gCrntScorData.clrgood & bitFlag) {
      wsprintf(smallBuffer, "%d ", i + 1);
    }
    else {
      lstrcpy(smallBuffer, "_ ");
    }
    lstrcat(bigBuffer, smallBuffer);
  }

  lstrcat(bigBuffer, "\n\r");
  wsprintf(smallBuffer, "Next Special:%d\n\r", gKeepWork.stagenm + 1);
  lstrcat(bigBuffer, smallBuffer);
  MessageBox(ghWnd, bigBuffer, "GOOD END flags", MB_OK);
}


// 00409221
void queryMciPlaying() {
  ULONG mciMode;
  if (IsIconic(ghWnd)) {
    cdAudio_getMciMode(&mciMode);
    if (mciMode == MCI_MODE_PLAY) {
      OutputDebugString("Now Playing\n\r");
    }
  }
}


// 00409267
LRESULT __stdcall WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam) {
  HCURSOR hCursor;
  char buffer[128];
  void(__stdcall *pInitKeySettings)(HWND, USHORT*);
  int result;
  ULONG mciMode;
  queryMciPlaying();

  switch (msg) {
    case WM_KEYDOWN:
    case WM_SYSKEYDOWN:
      if (lParam & 0x20000000) {
        if (wParam == VK_F2) {
          gbRestartStage = TRUE;
          return 0;
        }
        else if (wParam == VK_F4) {
          if (gbFullScreen) {
            toggleMouseCursor();
          }
          DestroyWindow(hWnd);
          return 0;
        }
        else if (gbFullScreen) {
          return 0;
        }
        return DefWindowProc(hWnd, msg, wParam, lParam);
      }
      if (wParam == VK_F1) {
        if (!gbFullScreen) {
          gbHelpOpen = TRUE;
          WinHelp(ghWnd, gHelpFilePath, HELP_INDEX, 0);
        }
      }
      else if (wParam == VK_F4) {
        if (!gbMoviePlaying && !gbNecComputer) {
          toggleMouseCursor();
        }
      }
      else if (wParam == VK_F3) {
        gbGamePaused = TRUE;
      }
      else if (wParam == VK_F5) {
        if (gbFullScreen == FALSE) {
          toggleMenuBar();
        }
      }
      else if (wParam == VK_F6) {
        if (gFpsFlag1 == 1) {
          gFpsFlag1 = 2;
        }
        else {
          gFpsFlag1 = 1;
        }
        modifyFramesMenuItemText(gFpsFlag1);
      }
      else if (wParam == VK_F7) {
        if (!gbFullScreen) {
          changeControls();
        }
      }
      else if (wParam == VK_F8) {
        toggleController();
      }
      else if (wParam == VK_F9);
      break;
    case WM_SYSCHAR:
      if ((wParam == 'R' || wParam == VK_F3) && lParam & 0x20000000) {
        gKeepWork.bRestart = 1;
        if (!gbTimeAttackLoaded) {
          restartGame();
        }
        return 0;
      }
      return DefWindowProc(hWnd, msg, wParam, lParam);
    case WM_CHAR:
      if (gbMenuOrMovieLoaded) {
        FUN_0040eb5a(wParam, lParam);
        return 0;
      }
      else {
        return DefWindowProc(hWnd, msg, wParam, lParam);
      }
    case WM_SIZE:
      if (wParam == 1) {
        DAT_0043332c = TRUE;
        cdAudio_getMciMode(&mciMode);
        if (mciMode == MCI_MODE_PLAY) {
          cdAudio_stop();
          DAT_00433330 = TRUE;
        }
        if (gbMoviePlaying) {
          pauseMovie();
          DAT_00433334 = TRUE;
        }
      }
      if (wParam == 0) {
        if (DAT_00433330) {
          cdAudio_playIfStopped();
          DAT_00433330 = FALSE;
        }
        DAT_0043332c = FALSE;
        if (gbMoviePlaying) {
          resumeMovie();
        }
      }
      break;
    case WM_CREATE:
      ghDc = GetDC(ghWnd);
      hCursor = SetCursor(LoadCursor(0, IDC_WAIT));
      GetPrivateProfileString("Directory", "Type", "MINIMAL", buffer, sizeof(buffer), "SONIC.INI");
      if (buffer[0] == 'F') {
        GetPrivateProfileString("Secret", "Super", "OFF", buffer, sizeof(buffer), "SONIC.INI");
        if (!isCdromPresent() && gbRequireCdrom && buffer[0] != 'J') {
          return -1;
        }
      }
      if (!isDisplay256Colors()) {
        return -1;
      }
      GetPrivateProfileString("Secret", "Super", "OFF", buffer, sizeof(buffer), "SONIC.INI");
      if (buffer[0] != 'J') {
        int versionInfo = GetVersion();
        // xor instead of and
        versionInfo = HIBYTE(LOWORD(versionInfo)) + (LOBYTE(LOWORD(versionInfo)) << 8);
        if (versionInfo < 0x35F) {
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
      pInitKeySettings = (void(__stdcall *)(HWND, USHORT*))GetProcAddress(ghSonicDlg, "InitKeySettings");
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
      SetCursor(hCursor);
      if (cdAudio_open(buffer, sizeof(buffer)) != 0) {
        gbCdAudioOpenSuccess = FALSE;
        MessageBox(hWnd, buffer, "CD Device Error", MB_OK);
      }
      else {
        gbCdAudioOpenSuccess = TRUE;
      }
      BringWindowToTop(ghWnd);
      break;
    case WM_PAINT:
      paintWindow(hWnd);
      return 0;
    case WM_DESTROY:
      if (gbFullScreen) {
        toggleMouseCursor();
      }
      if (gbHelpOpen) {
        gbHelpOpen = FALSE;
        WinHelp(ghWnd, gHelpFilePath, HELP_QUIT, 0);
      }
      if (gbBetterSoundQuality) {
        WritePrivateProfileString("SOUND", "QUALITY", "BETTER", "SONIC.INI");
      }
      else {
        WritePrivateProfileString("SOUND", "QUALITY", "GOOD  ", "SONIC.INI");
      }
      WaveAllStop();
      CDPause();
      unloadGame();
      if (gbWaveOpen) {
        closeWaveOut();
        freeWaveMemory();
      }
      cdAudio_close();
      FUN_0040c00c(hWnd);
      ReleaseDC(ghWnd, ghDc);
      freeAllocatedMemory();
      freeGraphics();
      PostQuitMessage(0);
      break;
    case WM_ACTIVATE:
      if ((wParam == 1 || wParam == 2) && !gbFullScreen) {
        if (gbMoviePlaying) {
          realizeMovie();
        }
        else {
          makePalette();
        }
        return 0;
      }
      if (wParam == 0 && gbFullScreen == TRUE) {
        if (gbMoviePlaying) {
          if (!gbFullScreen) {
            gbFullScreen = TRUE;
          }
          else {
            gbFullScreen = FALSE;
          }
          return 0;
        }
        else {
          toggleMouseCursor();
          return 0;
        }
      }
      return DefWindowProc(hWnd, msg, wParam, lParam);
    case MM_MCINOTIFY:
      wsprintf(buffer, "w=%04x l=%08lx CD=%x\n\r", wParam, lParam, gMciDeviceId);
      log(buffer);
      if ((LOWORD(lParam)) == gMciDeviceId) {
        result = cdAudio_playIfNotStopped(hWnd);
        if (result != 0) {
          gbCdAudioOpenSuccess = FALSE;
        }
        return 0;
      }
      else if (gbMoviePlaying) {
        if (DAT_00433334) {
          DAT_00433334 = FALSE;
          return 0;
        }
        if (DAT_00433310) {
          changeMovieSize();
          DAT_00433310 = FALSE;
        }
        else {
          gbRun = FUN_0040e6fe(wParam, lParam);
        }
        return 0;
      }
      return DefWindowProcA(hWnd, msg, wParam, lParam);
    case MM_WOM_DONE:
      FUN_0040dd16((HWAVEOUT)wParam,(LPWAVEHDR)lParam);
      break;
    case MM_WOM_OPEN:
    case MM_WOM_CLOSE:
      break;
    case WM_SYSCOMMAND:
      if (wParam == SC_SCREENSAVE) {
        return 1;
      }
      else if (wParam == SC_MONITORPOWER) {
        return 1;
      }
      else if (wParam == SC_KEYMENU && gbFullScreen) {
        return 0;
      }
      else {
        return DefWindowProcA(hWnd, msg, wParam, lParam);
      }
    case WM_POWER:
      if (wParam == 3 && GetActiveWindow() == hWnd && gbFullScreen) {
        makePalette();
        return 0;
      }
      if (wParam == 1) {
        return -1;
      }
      break;
    case WM_COMMAND:
      if (wParam >= ID_STAGE_R11A && wParam <= ID_STAGE_R83D) {
        gKeepWork.play_start = 0;
        hCursor = SetCursor(LoadCursor(0, IDC_WAIT));
        loadStageByMenu(wParam);
        SetCursor(hCursor);
        return 0;
      }
      if (wParam >= ID_STAGE_SPECIAL_R1 && wParam <= ID_STAGE_SPECIAL_R8) { /* Special Stage */
        gKeepWork.play_start = 0;
        hCursor = SetCursor(LoadCursor(0, IDC_WAIT));
        loadSpecialStage(wParam);
        SetCursor(hCursor);
        return 0;
      }

      switch (wParam) {
        case ID_RESTARTGAME:
          gKeepWork.bRestart = 1;
          if (!gbTimeAttackLoaded) {
            restartGame();
          }
          break;
        case ID_RESTARTSTAGE:
          gbRestartStage = TRUE;
          break;
        case ID_PAUSEGAME:
          gbGamePaused = TRUE;
          break;
        case ID_EXITGAME:
          DestroyWindow(hWnd);
          break;
        case ID_OPTIONS_FULLSCREEN:
          if (!gbNecComputer) {
            toggleMouseCursor();
          }
          break;
        case ID_OPTIONS_MENUBAR:
          toggleMenuBar();
          break;
        case ID_OPTIONS_SMOOTHSONIC:
        case 207:
          if (gFpsFlag1 == 1) {
            gFpsFlag1 = 2;
          }
          else {
            gFpsFlag1 = 1;
          }
          modifyFramesMenuItemText(gFpsFlag1);
          break;
        case ID_OPTIONS_CHANGECONTROLS:
          changeControls();
          break;
        case ID_OPTIONS_USEKEYBOARD:
          toggleController();
          break;
        case ID_BETTERSOUNDQUALITY:
          toggleSoundQuality();
          break;
        case ID_HELP_CONTENTS:
          gbHelpOpen = TRUE;
          WinHelp(ghWnd, gHelpFilePath, HELP_CONTENTS, 0);
          break;
        case ID_HELP_HOWTOPLAY:
          gbHelpOpen = TRUE;
          WinHelp(ghWnd, gHelpFilePath, HELP_CONTEXT, 2);
          break;
        case ID_HELP_CONTROLS:
          gbHelpOpen = TRUE;
          WinHelp(ghWnd, gHelpFilePath, HELP_CONTEXT, 3);
          break;
        case ID_HELP_HISTORY:
          gbHelpOpen = TRUE;
          WinHelp(ghWnd, gHelpFilePath, HELP_CONTEXT, 4);
          break;
        case ID_HELP_HOTLINE:
          gbHelpOpen = TRUE;
          WinHelp(ghWnd, gHelpFilePath, HELP_CONTEXT, 5);
          break;
        case ID_HELP_HOWTOUSE:
          gbHelpOpen = TRUE;
          WinHelp(ghWnd, gHelpFilePath, HELP_HELPONHELP, 0);
          break;
        case ID_HELP_ABOUT:
          showSonicDlg(hWnd, "SONICDLG_ABOUT", "AboutDialog", 0);
          break;
        case ID_FUNC_DEBUGFLAG:
          if (!gbDebugFlag) {
            gbDebugFlag = TRUE;
          }
          else {
            gbDebugFlag = FALSE;
          }
          checkSubMenuItem(4, wParam, gbDebugFlag);
          if (gpSetDebugFlag != 0) {
            (*gpSetDebugFlag)(gbDebugFlag);
          }
          break;
        case ID_FUNC_TIMER:
          break;
        case ID_FUNC_TIMERINIT:
          break;
        case ID_FUNC_AVE300FRAME:
          break;
        case ID_FUNC_GOODEND:
          showGoodEndFlags();
          break;
        case ID_FUNC_FLAGS:
          wsprintf(buffer, "generate_flag=%02x \n\rtime_flag=%02x", gKeepWork.generate_flag, gKeepWork.time_flag);
          MessageBox(hWnd, buffer, "Flags", MB_OK);
          break;
        case ID_FUNC_SPECIALDEBUG:
          if (gKeepWork.SpecialTime == 0) {
            gKeepWork.SpecialTime = 1;
          }
          else {
            gKeepWork.SpecialTime = 0;
          }
          checkSubMenuItem(4, wParam, gKeepWork.SpecialTime);
          break;
        case ID_FUNC_GOSPECIAL:
          gbGoSpecial = TRUE;
          break;
        case ID_FUNC_MAPINIT:
          if (gbEACreated == TRUE && gbGameDllLoaded == TRUE) {
            int_union vscroll, scrahposiw, scrbhposiw;

            CDPause();
            (*gpGameinit)();
            vscroll.l = (*gpGetvscroll)();
            scrahposiw.l = (*gpGetscrahposiw)();
            scrbhposiw.l = (*gpGetscrbhposiw)();
            // movsx instead of mov
            mapinit(scrahposiw.w.h, vscroll.w.h, scrbhposiw.w.h, vscroll.w.l);
          }
          break;
        case ID_FUNC_CDRESET:
          cdAudio_close();
          if (cdAudio_open(buffer, 128) != 0) {
            gbCdAudioOpenSuccess = FALSE;
            MessageBox(hWnd, buffer, "CD Device Error", MB_OK);
          }
          else {
            gbCdAudioOpenSuccess = TRUE;
          }
          break;
        case ID_FUNC_MMTIMER:
          if (gTimeSetEventResult != 0) {
            killTimer();
            checkSubMenuItem(4, wParam, FALSE);
          }
          else {
            setupTimer();
            checkSubMenuItem(4, wParam, TRUE);
          }
          break;
        case ID_FUNC_SPRITECMP:
          if (!gbSpriteLoadingEnabled) {
            gbSpriteLoadingEnabled = TRUE;
          }
          else {
            gbSpriteLoadingEnabled = FALSE;
          }
          checkSubMenuItem(4, wParam, gbSpriteLoadingEnabled);
          break;
        case ID_FUNC_TIMEWARP:
          if (gKeepWork.TimeWarp == 0) {
            gKeepWork.TimeWarp = 1;
          }
          else {
            gKeepWork.TimeWarp = 0;
          }
          checkSubMenuItem(4, wParam,gKeepWork.TimeWarp);
          break;
        case ID_FUNC_SNDMEMFREE:
          closeWaveOut();
          freeWaveMemory();
          break;
        case ID_FUNC_FRAME_60:
          gFpsFlag1 = 1;
          gFpsFlag2 = 1;
          break;
        case ID_FUNC_FRAME_30:
          gFpsFlag1 = 2;
          gFpsFlag2 = 2;
          break;
        case ID_FUNC_RECSTART:
          DAT_00433258 = 0xFF;
          gRecordingBufferReadWriteCnt = 0;
          break;
        case ID_FUNC_RECEND:
          DAT_00433258 = 0;
          gRecordingBuffer[gRecordingBufferReadWriteCnt] = 0xFFFF;
          gRecordingBufferLogicalEntryCnt = gRecordingBufferReadWriteCnt;
          gRecordingBufferReadWriteCnt = 0;
          break;
        case ID_FUNC_RECPLAY:
          gbRecordPlayFlag = 1;
          break;
        case ID_FUNC_RECREAD:
          readRecording();
          break;
        case ID_FUNC_RECWRITE:
          writeRecording();
          break;
        case ID_FUNC_DEMO_AVI:
        case ID_FUNC_DEMO_11A:
        case ID_FUNC_DEMO_SPE1:
        case ID_FUNC_DEMO_43C:
        case ID_FUNC_DEMO_SPE5:
        case ID_FUNC_DEMO_82A:
          gDemoId = wParam - 521;
          break;
        case ID_FUNC_WAVECLOSE:
          closeWaveOut();
          break;
        case ID_FUNC_WAVEOPEN:
          openWaveOut(ghWnd);
          break;
        default:
          break;
      }
    default:
      return DefWindowProc(hWnd, msg, wParam, lParam);
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
    log("AVIPAINT END \n\r");
  }
  EndPaint(hWnd,&paintInfo);
}


// 0040a635
int startGame() {
  HCURSOR hCursor;
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
  initGraphics(ghWnd);
  memset(&gKeepWork, 0, 892);
  hCursor = SetCursor(LoadCursor(0, IDC_WAIT));
  gKeepWork.ta_flag = 0;
  gKeepWork.TimeWarp = 1;
  gKeepWork.SpecialTime = 0;
  checkSubMenuItem(4, ID_FUNC_TIMEWARP, gKeepWork.TimeWarp);
  gKeepWork.play_start = 0;
  gbSpriteLoadingEnabled = TRUE;
  checkSubMenuItem(4, ID_FUNC_SPRITECMP, gbSpriteLoadingEnabled);
  gbFirstTitle = TRUE;
  gbMenuOrMovieLoaded = loadOpening(ghWnd, ghSurf);
  gbFirstTitle = FALSE;
  SetCursor(hCursor);
  loadIni();
  hMenu = GetSubMenu(GetMenu(ghWnd), 1);
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


// 0040ab3a
void setStage(UINT stageMenuId) {
  int round;
  int level;
  int zone;
  int i;
  if (stageMenuId != 0) {
    round = (stageMenuId - 400) / 10;
    level = (stageMenuId - 400) % 10;
    zone = level / 4;
    gKeepWork.stageno.b.h = round;
    gKeepWork.stageno.b.l = zone;
    if (level >= 8) {
      gKeepWork.time_flag = 2;
    }
    else if (level % 4 >= 2) {
      gKeepWork.time_flag = 2;
    }
    else if (level % 4 == 1) {
      gKeepWork.time_flag = 0;
    }
    else {
      gKeepWork.time_flag = 1;
    }
    gKeepWork.generate_flag = 0;
    gKeepWork.gf_flag = 0;
    if (level == 8 || level % 4 == 2) {
      gKeepWork.generate_flag = 1;
    }
    else if (level == 9 || level % 4 == 3) {
      gKeepWork.generate_flag = 0;
    }
  }
  else {
    round = gKeepWork.stageno.b.h;
    zone = gKeepWork.stageno.b.l;
    if (gKeepWork.time_flag & 0x80) {
      gKeepWork.time_flag &= 0x7F;
    }
    else if (zone == 0) {
      gKeepWork.generate_flag = 0;
      gKeepWork.gf_flag = 0;
      gKeepWork.projector_flag = 0;
    }
    stageMenuId = 400 + (round * 5 * 2 + zone * 4);
    if (zone == 2) {
      if (gKeepWork.generate_flag == 0) {
        ++stageMenuId;
      }
    }
    else if (gKeepWork.time_flag == 0) {
      ++stageMenuId;
    }
    else if (gKeepWork.time_flag == 2) {
      if (gKeepWork.generate_flag != 0) {
        stageMenuId += 2;
      }
      else {
        stageMenuId += 3;
      }
    }

    for (i = 400; i <= 469; ++i) {
      checkSubMenuItem(3, i, FALSE);
    }

    checkSubMenuItem(3, stageMenuId, TRUE);
  }

  return;
}


// 0040ad7d
BOOL loadGameDll(LPCSTR path) {
  char buffer[80];
  memset(gpHscrollbuff, 0, 1024);
  ghGameStageDll = LoadLibrary(path);
  if ((ULONG)ghGameStageDll < 32) {
    wsprintf(buffer, "DLL Load Error! (%x) %s", ghGameStageDll, buffer);
    MessageBox(ghWnd, buffer, 0, MB_SYSTEMMODAL);
    return FALSE;
  }
  gpGameinit = (void(*)())GetProcAddress(ghGameStageDll, "game_init");
  gpGame = (int(*)())GetProcAddress(ghGameStageDll, "game");
  gpDLLmeminit = (void(__stdcall *)(char***, void**))GetProcAddress(ghGameStageDll, "DLL_meminit");
  gpDLLmemfree = (void(*)())GetProcAddress(ghGameStageDll, "DLL_memfree");
  gpSWdataSet = (void(__stdcall *)(ushort_union, ushort_union))GetProcAddress(ghGameStageDll, "SWdataSet");
  gpGetvscroll = (int(*)())GetProcAddress(ghGameStageDll, "Get_vscroll");
  gpGetscrahposiw = (int(*)())GetProcAddress(ghGameStageDll, "Get_scra_h_posiw");
  gpGetscrbhposiw = (int(*)())GetProcAddress(ghGameStageDll, "Get_scrb_h_posiw");
  gpFadeProc = (int(*)())GetProcAddress(ghGameStageDll, "FadeProc");
  gpSetDebugFlag = (void(__stdcall *)(unsigned int))GetProcAddress(ghGameStageDll, "SetDebugFlag");
  gpGetRoundStr = (void(__stdcall *)(unsigned short, unsigned char, char*))GetProcAddress(ghGameStageDll, "GetRoundStr");
  gpSpecialblockchg = (void(__stdcall *)(unsigned short*, unsigned short*, unsigned short*, unsigned short*))GetProcAddress(ghGameStageDll, "Special_block_chg");
  gpDLLmeminit((char***)gGameMemory, gpDLLmeminitFuncs);
  gbGameDllLoaded = TRUE;
  if (gpSetDebugFlag != 0) {
    gpSetDebugFlag(gbDebugFlag);
  }

  return TRUE;
}


// 0040af3b
BOOL loadSpecialStage(int stageMenuId) {
  int i;
  if (stageMenuId != 0) {
    gKeepWork.stagenm = stageMenuId - 470;
  }
  else {
    for (i = 0; i < 7; ++i) {
      if (!(gKeepWork.clrspflg_save & 1 << gKeepWork.stagenm)) break;
      ++gKeepWork.stagenm;
      if (gKeepWork.stagenm > 6) {
        gKeepWork.stagenm = 0;
      }
    }
  }
  gKeepWork.SPEMode = 0;
  unloadGame();
  gbSpecialStageLoaded = TRUE;
  drawLoading();
  deleteSplash();
  if (!loadGameDll("SPECIAL\\SPECIAL.DLL")) {
    return FALSE;
  }
  gFadeFlag = 0;
  if (EACreate() == TRUE) {
    gbEACreated = TRUE;
  }
  else {
    showCustomError(2, 0);
    EADelete();
    return FALSE;
  }
  makePalette();
  if (!gbEACreated || !gbGameDllLoaded) {
    return FALSE;
  }
  (*gpGameinit)();
  (*gpGame)();
  FUN_004054ee();
  return TRUE;
}


// 0040b081
BOOL loadWarp() {
  int_union vscroll;
  int_union scrahposiw;
  int_union scrbhposiw;
  unloadGame();
  gbWarpLoaded = TRUE;
  if (!loadGameDll("WARP\\WARP.DLL")) {
    return FALSE;
  }
  gFadeFlag = 0;
  if (EACreate() == TRUE) {
    gbEACreated = TRUE;
  }
  else {
    showCustomError(2, 0);
    EADelete();
    return FALSE;
  }
  makePalette();
  if (gbEACreated == TRUE && gbGameDllLoaded == TRUE) {
    (*gpGameinit)();
    vscroll.l = (*gpGetvscroll)();
    scrahposiw.l = (*gpGetscrahposiw)();
    scrbhposiw.l = (*gpGetscrbhposiw)();
    mapinit(scrahposiw.w.h, vscroll.w.h, scrbhposiw.w.h, vscroll.w.l);
    makePalette2();
  }

  return TRUE;
}


// 0040b160
BOOL loadThanks() {
  if (!loadGameDll("TITLE\\THANKS\\THANKS.DLL")) {
    return FALSE;
  }
  gFadeFlag = 0;
  gbThanksLoaded = TRUE;
  if (EACreate() == TRUE) {
    gbEACreated = TRUE;
  }
  else {
    showCustomError(2, 0);
    EADelete();
    return FALSE;
  }
  if (!gbEACreated || !gbGameDllLoaded) {
    return FALSE;
  }
  (*gpGameinit)();
  (*gpGame)();
  makePalette();

  return TRUE;
}


// 0040b20c
BOOL loadPlanet() {
  FUN_004051ab();
  fillColorwk(0);
  makePalette2();
  unloadGame();
  if (!loadGameDll("TITLE\\PLANET\\PLANET.DLL")) {
    return FALSE;
  }
  gFadeFlag = 0;
  gbLittlePlanetLoaded = TRUE;
  if (EACreate() == TRUE) {
    gbEACreated = TRUE;
  }
  else {
    showCustomError(2, 0);
    EADelete();
    return FALSE;
  }
  if (!gbEACreated || !gbGameDllLoaded) {
    return FALSE;
  }
  log("game_init\n\r");
  (*gpGameinit)();
  log("game\n\r");
  (*gpGame)();
  log("make palett\n\r");
  makePalette();
  log("ok\n\r");

  return TRUE;
}


// 0040b305
BOOL loadTimeAttack(BOOL param_1) {
  unloadGame();
  gbTimeAttackLoaded = TRUE;
  if (!loadGameDll("TITLE\\TA\\TA.DLL")) {
    return FALSE;
  }
  gFadeFlag = 0;
  gKeepWork.ta_flag = 1;
  makePalette();
  if (param_1 == TRUE) {
    gKeepWork.ta_time = -2;
  }
  (*gpGameinit)();
  (*gpGame)();
  makePalette();
  return TRUE;
}


// 0040b380
BOOL loadStageByMenu(UINT stageMenuId) {
  char stageId[3];
  char path[80];
  int_union vscroll;
  int_union scrahposiw;
  int_union scrbhposiw;
  unloadGame();
  gbUsedStageSelect = FALSE;
  DAT_004332cc = TRUE;
  drawLoading();
  deleteSplash();
  setStage(stageMenuId);
  readStageString(stageId);
  wsprintf(path, "R%c\\%3s\\DLL%3s.DLL", stageId[0], stageId, stageId);
  if (stageId[1] == '3' && stageId[2] == 'C') {
    DAT_0042570c = TRUE;
  }
  else {
    DAT_0042570c = FALSE;
  }
  if (!loadGameDll(path)) {
    return FALSE;
  }
  gFadeFlag = 0;
  if (EACreate() == TRUE) {
    gbEACreated = TRUE;
  }
  else {
    showCustomError(2, 0);
    EADelete();
    return FALSE;
  }
  fillColorwk(0);
  makePalette2();
  if (gbEACreated == TRUE && gbGameDllLoaded == TRUE) {
    (*gpGameinit)();
    vscroll.l = (*gpGetvscroll)();
    scrahposiw.l = (*gpGetscrahposiw)();
    scrbhposiw.l = (*gpGetscrbhposiw)();
    mapinit(scrahposiw.w.h, vscroll.w.h, scrbhposiw.w.h, vscroll.w.l);
  }
  makePalette();

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

  return;
}


// 0040b54f
BOOL setupJoystick() {
  if (joyGetNumDevs() == 0) {
    return FALSE;
  }
  if (joyGetDevCaps(0, &gJoyCapsInfo, sizeof(gJoyCapsInfo)) == MMSYSERR_NODRIVER) {
    return FALSE;
  }
  gJoystickInput1 = 0x5556;
  gJoystickInput2 = 0xAAAA;
  gJoystickInput3 = 0x5556;
  gJoystickInput4 = 0xAAAA;

  return TRUE;
}


// 0040b5c3
void updateSwdata(UCHAR buttonsPressed, ushort_union* pSwdata) {
  UCHAR buttonsDown = pSwdata->b.h;
  buttonsDown ^= buttonsPressed;
  pSwdata->b.h = buttonsPressed;
  buttonsDown &= buttonsPressed;
  pSwdata->b.l = buttonsDown;
  if (DAT_00433258 != 0) {
    if (gRecordingBufferReadWriteCnt == 0x1800) {
      DAT_00433258 = 0;
      ((USHORT*)gRecordingBuffer)[gRecordingBufferReadWriteCnt] = 0xFFFF;
      gRecordingBufferLogicalEntryCnt = gRecordingBufferReadWriteCnt;
      gRecordingBufferReadWriteCnt = 0;
    }
    else {
      gRecordingBuffer[gRecordingBufferReadWriteCnt * 2] = pSwdata->b.h;
      gRecordingBuffer[gRecordingBufferReadWriteCnt * 2 + 1] = pSwdata->b.l;
      ++gRecordingBufferReadWriteCnt;
    }
  }
  if (gbRecordPlayFlag) {
    // xor instead of and
    if (((USHORT*)gRecordingBuffer)[gRecordingBufferReadWriteCnt] == 0xFFFF) {
      gbRecordPlayFlag = FALSE;
      gRecordingBufferReadWriteCnt = 0;
    }
    else {
      pSwdata->b.l = gRecordingBuffer[gRecordingBufferReadWriteCnt * 2 + 1];
      pSwdata->b.h = gRecordingBuffer[gRecordingBufferReadWriteCnt * 2];
      ++gRecordingBufferReadWriteCnt;
      if (buttonsPressed & 0x50) {
        gbRecordPlayFlag = FALSE;
        gRecordingBufferReadWriteCnt = 0;
        gKeepWork.demoflag.w = -1;
      }
    }
  }
}


// 0040b71d
void readController(int param_1) {
  UCHAR swdata1 = 0;
  UCHAR swdata2 = 0;
  UCHAR zero;
  DAT_00425423 = 0;
  if (gControllerId & 4) {
    if (DAT_004332b4) {
      zero = FUN_0040f570();
      if (zero & 0x40) {
        swdata1 |=  0x40;
      }
      if (zero & 0x10) {
        swdata1 |=  0x10;
      }
      if (zero & 4) {
        swdata1 |=  4;
      }
      if (zero & 8) {
        swdata1 |=  8;
      }
      if (zero & 1) {
        swdata1 |=  1;
      }
      if (zero & 2) {
        swdata1 |=  2;
      }
    }
    else {
      swdata1 = DAT_0042572c;
    }
  }
  else if (gControllerId & 1) {
    if (DAT_004332b4) {
      gJoyInfo.dwSize = sizeof(gJoyInfo);
      gJoyInfo.dwFlags = JOY_RETURNALL;
      joyGetPosEx(0, &gJoyInfo);
      if (gJoyInfo.dwButtons & 1) {
        swdata1 |=  0x40;
      }
      if (gJoyInfo.dwButtons & 2) {
        swdata1 |=  0x10;
      }
      if (gJoyInfo.dwXpos < gJoystickInput1) {
        swdata1 |= 0x04;
      }
      if (gJoystickInput2 < gJoyInfo.dwXpos) {
        swdata1 |= 0x08;
      }
      if (gJoyInfo.dwYpos < gJoystickInput3) {
        swdata1 |= 0x01;
      }
      if (gJoystickInput4 < gJoyInfo.dwYpos) {
        swdata1 |= 0x02;
      }
      DAT_0042572c = swdata1;
    }
    else {
      swdata1 = DAT_0042572c;
    }
  }
  else if (gControllerId & 2) {
    if (DAT_004332b4) {
      DAT_0042542d = GetKeyState(gUserKey[0]);
      DAT_0042542f = GetKeyState(gUserKey[1]);
      DAT_0042542e = GetKeyState(gUserKey[2]);
      DAT_00425430 = GetKeyState(gUserKey[3]);
      DAT_00425428 = GetKeyState(gUserKey[4]);
      if (DAT_004332cc != 0) {
        DAT_00425423 = GetKeyState(VK_ESCAPE);
      }
      if (DAT_0042542f & 0x80) {
        swdata1 |= 0x08;
      }
      else if (DAT_0042542d & 0x80) {
        swdata1 |= 0x04;
      }
      else if (DAT_00425430 & 0x80) {
        swdata1 |= 0x02;
      }
      else if (DAT_0042542e & 0x80) {
        swdata1 |= 0x01;
      }
      if (DAT_00425428 & 0x80) {
        swdata1 |= 0x40;
      }
      if (DAT_00425423 & 0x80) {
        swdata1 |= 0x10;
      }
      DAT_0042572c = swdata1;
    }
    else {
      swdata1 = DAT_0042572c;
    }
  }
  swdata2 = swdata1;
  DAT_004332b4 = FALSE;
  if (param_1 != 0 && gbGamePaused) {
    if (!gbRecordPlayFlag) {
      gbGamePaused = FALSE;
      swdata1 |= 0x80;
    }
  }
  if (gbRestartStage) {
    swdata1 = 0x70;
  }
  gbRestartStage = FALSE;
  // extra xor
  updateSwdata(swdata1, &gSwdata1);
  // extra xor
  updateSwdata(swdata2, &gSwdata2);
  (*gpSWdataSet)(gSwdata1, gSwdata2);
}


// 0040badc
void resetInput() {
  DAT_0042542f = 0;
  DAT_0042542d = 0;
  DAT_00425430 = 0;
  DAT_0042542e = 0;
  DAT_00425428 = 0;
  DAT_00425423 = 0;
  gSwdata1.w = 0;
  gSwdata2.w = 0;
}


// 0040bb23
void __stdcall CDPlay(short trackNumber) {
  gCurrentCdAudioTrack = trackNumber + -1;
  if (gUnknownCdAudioCountdown == 0) {
    cdAudio_stop();
    gUnknownCdAudioCountdown = 60;
  }
}


// 0040bb5b
void CDPause() {
  gCurrentCdAudioTrack = -1;
  cdAudio_stop();
  gUnknownCdAudioCountdown = 60;

  return;
}


// 0040bb84
void changeMusic() {
  BOOL unknown;
  MCIERROR err;
  char errMsg[128];
  if (gbCdAudioOpenSuccess == TRUE) {
    if (gCurrentCdAudioTrack == 1 || gCurrentCdAudioTrack == 27 || gCurrentCdAudioTrack == 30 || gCurrentCdAudioTrack == 29 || gCurrentCdAudioTrack == 28) {
      unknown = FALSE;
    }
    else {
      unknown = TRUE;
    }
    err = cdAudio_switchTrack(gCurrentCdAudioTrack, unknown, ghWnd);
    if (err != 0) {
      mciGetErrorString(err, errMsg, sizeof(errMsg));
      log(errMsg);
    }
  }

  return;
}


// 0040bc4e
void readStageString(char* str) {
  UCHAR round;
  UCHAR zone;
  round = gKeepWork.stageno.b.h + 1;
  if (round > 1) {
    ++round;
  }
  zone = gKeepWork.stageno.b.l + 1;
  *str = round + 48;
  ++str;
  *str = zone + 48;
  ++str;
  // extra xor
  switch (gKeepWork.time_flag & 0x7F) {
    case 0:
      *str = 'B';
      ++str;
      break;
    case 1:
      *str = 'A';
      ++str;
      break;
    case 2:
      if (gKeepWork.generate_flag != 0) {
        *str = 'C';
        ++str;
      }
      else {
        *str = 'D';
        ++str;
      }
    default:
      break;
  }
  *str = 0;
  ++str;

  return;
}


// 0040bd30
void log(char* msg) {
  return;
}


// 0040bd40
void showCustomError(int id, char* pMsg) {
  char buffer[80];
  switch (id) {
    case 2:
      MessageBox(ghWnd, "Memory Allocate Error.", 0, MB_SYSTEMMODAL);
      break;
    case 1:
      wsprintf(buffer, "File Can't Open %s", pMsg);
      MessageBox(ghWnd, buffer, 0, MB_SYSTEMMODAL);
      break;
    case 3:
      wsprintf(buffer, "Falal Error %x", pMsg);
      MessageBox(ghWnd, buffer, 0, MB_SYSTEMMODAL);
      break;
    default:
      MessageBox(ghWnd, pMsg, 0,MB_SYSTEMMODAL);
      break;
  }

  return;
}


// 0040be23
void readRecording() {
  char fileName[80];
  char buffer[80];
  HFILE hFile;
  if (gbSpecialStageLoaded == TRUE) {
    wsprintf(fileName, "special%1c.BIN", gKeepWork.stagenm + 49);
  }
  else {
    readStageString(buffer);
    wsprintf(fileName, "KEY%3s.BIN", buffer);
  }
  hFile = _lopen(fileName, OF_READ);
  if (hFile == -1) {
    log("Key Data Open Error\n");
  }
  else {
    gRecordingBufferReadWriteCnt = _lread(hFile, gRecordingBuffer, 0x3000);
    if (gRecordingBufferReadWriteCnt == -1) {
      log("Key Data Read Error\n");
    }
    else {
      gRecordingBufferLogicalEntryCnt = gRecordingBufferReadWriteCnt / 2;
      ((USHORT*)gRecordingBuffer)[gRecordingBufferLogicalEntryCnt * 2] = 0xFFFF;
      gRecordingBufferReadWriteCnt = 0;
      _lclose(hFile);
    }
  }
}


// 0040bf2c
void writeRecording() {
  char path[80];
  char buffer[80];
  OFSTRUCT ofStruct;
  HFILE hFile;
  if (gbSpecialStageLoaded == TRUE) {
    wsprintf(path, "special%1c.BIN", gKeepWork.stagenm + 49);
  }
  else {
    readStageString(buffer);
    wsprintf(path, "KEY%3s.BIN", buffer);
  }
  hFile = OpenFile(path, &ofStruct, 4096);
  if (hFile == -1) {
    wsprintf(path, "Key Data write Error\n");
    log(path);
  }
  else {
    gRecordingBufferReadWriteCnt = _lwrite(hFile, (LPCSTR)gRecordingBuffer, gRecordingBufferLogicalEntryCnt * 2);
    _lclose(hFile);
  }
}


// 0040c00c
short FUN_0040c00c(HWND hWnd) {
  return 0;
}


// 0040c01f
int showSonicDlg(HWND hWnd, LPCSTR resourceId, LPCSTR dialogId, LPARAM initValue) {
  HMODULE hModule;
  DLGPROC dlgProc;
  char errMsg[80];
  int result;
  SetErrorMode(SEM_NOOPENFILEERRORBOX);
  hModule = LoadLibrary("SONICDLG.DLL");
  if ((long)hModule <= 32) {
    MessageBox(0, "Can't load SONICDLG.DLL", "Sonic Error", MB_ICONSTOP);
    return -1;
  }
  dlgProc = (DLGPROC)GetProcAddress(hModule, dialogId);
  if (dlgProc == 0) {
    wsprintf(errMsg, "Can't GetProcAddress() for SONICDLG.DLL:%s()", dialogId);
    MessageBox(0, errMsg, "Sonic Error", MB_ICONSTOP);
    return -1;
  }
  result = DialogBoxParam(hModule, resourceId, hWnd, dlgProc, initValue);
  if (result == -1) {
    wsprintf(errMsg, "DialogBoxParam(...) %s", resourceId);
    MessageBox(0, errMsg, "Error", MB_ICONSTOP);
    return -1;
  }
  FreeLibrary(hModule);

  return result;
}


// 0040c128
void loadIni() {
  char buffer[256];
  if (GetPrivateProfileString("Secret", "User", "", buffer, sizeof(buffer), "SONIC.INI") == 0) return;
  if (lstrcmp(buffer, "Debugger") == 0) {
    gUsedMenuId = 1;
    gbRequireCdrom = FALSE;
    gKeepWork.User = 2;
  }
  else if (lstrcmp(buffer, "Fujiwara") == 0) {
    gKeepWork.User = 1;
  }
  else if (lstrcmp(buffer, "Satoh") == 0) {
    gUsedMenuId = 1;
    gbRequireCdrom = FALSE;
    gKeepWork.User = 128;
  }

  return;
}


// 0040c206
BOOL isDisplay256Colors() {
  if (GetDeviceCaps(ghDc, RASTERCAPS) & RC_PALETTE) {
    if (GetDeviceCaps(ghDc, SIZEPALETTE) == 256) {
      return TRUE;
    }
  }
  MessageBox(0, "Your computer display setting must be 256 color to play Sonic the Hedgehog CD.", "Sonic Error", MB_ICONSTOP);

  return FALSE;
}
