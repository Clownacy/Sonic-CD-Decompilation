#ifndef WINMAIN_H
#define WINMAIN_H

#include <windows.h>
#include "TYPES.H"

BOOL menuOrMovieLoop();
BOOL specialStageLoop();
BOOL littlePlanetLoop();
BOOL thanksLoop();
BOOL timeAttackLoop();
BOOL warpLoop();
BOOL stageLoop();
void setupTimer();
void killTimer();
ATOM registerWindowClass(HINSTANCE hInstance);
BOOL makeWindow(HINSTANCE hInstance, int nCmdShow);
void checkSubMenuItem(int subMenuPos, UINT menuItemId, BOOL bCheck);
BOOL isCpuPentium();
BOOL isComputerNec();
BOOL isCdromPresent();
BOOL isGameInUse();
void __stdcall enableSubMenuItem(int subMenuPos, UINT menuItemId, BOOL bEnable);
void modifyFramesMenuItemText(int flag);
void modifyControllerMenuItemText(USHORT controllerId);
void __stdcall toggleSoundQuality();
void retrieveHelpFilePath();
void toggleMouseCursor();
void toggleMenuBar();
void unloadGame();
void restartGame();
void changeControls();
void showGoodEndFlags();
void queryMciPlaying();
LRESULT __stdcall WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
void paintWindow(HWND hWnd);
int startGame();
int freeAllocatedMemory();
void setStage(UINT stageMenuId);
BOOL loadGameDll(LPCSTR path);
BOOL loadSpecialStage(int stageMenuId);
BOOL loadWarp();
BOOL loadThanks();
BOOL loadPlanet();
BOOL loadTimeAttack(BOOL param_1);
BOOL loadStageByMenu(UINT stageMenuId);
void toggleController();
BOOL setupJoystick();
void updateSwdata(UCHAR buttonsPressed, ushort_union* pSwdata);
void readController(int param_1);
void resetInput();
void __stdcall CDPlay(short trackNumber);
void CDPause();
void changeMusic();
void readStageString(char* str);
void log(char* msg);
void showCustomError(int id, char* pMsg);
void readRecording();
void writeRecording();
short FUN_0040c00c(HWND hWnd);
int showSonicDlg(HWND hWnd, LPCSTR resourceId, LPCSTR dialogId, LPARAM initValue);
void loadIni();
BOOL isDisplay256Colors();

#endif
