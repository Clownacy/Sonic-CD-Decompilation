#ifndef WINMAIN_H
#define WINMAIN_H

#include <windows.h>
#include "TYPES.H"

BOOL menuOrMovieLoop(void);
BOOL specialStageLoop(void);
BOOL littlePlanetLoop(void);
BOOL thanksLoop(void);
BOOL timeAttackLoop(void);
BOOL warpLoop(void);
BOOL stageLoop(void);
void setupTimer(void);
void killTimer(void);
ATOM registerWindowClass(HINSTANCE hInstance);
BOOL makeWindow(HINSTANCE hInstance, int nCmdShow);
void checkSubMenuItem(int subMenuPos, UINT menuItemId, BOOL bCheck);
BOOL isCpuPentium(void);
BOOL isComputerNec(void);
BOOL isCdromPresent(void);
BOOL isGameInUse(void);
void __stdcall enableSubMenuItem(int subMenuPos, UINT menuItemId, BOOL bEnable);
void modifyFramesMenuItemText(int flag);
void modifyControllerMenuItemText(USHORT controllerId);
void __stdcall toggleSoundQuality(void);
void retrieveHelpFilePath(void);
void toggleMouseCursor(void);
void toggleMenuBar(void);
void unloadGame(void);
void restartGame(void);
void changeControls(void);
void showGoodEndFlags(void);
void queryMciPlaying(void);
LRESULT __stdcall WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
void paintWindow(HWND hWnd);
int startGame(void);
int freeAllocatedMemory(void);
void setStage(UINT stageMenuId);
BOOL loadGameDll(LPCSTR path);
BOOL loadSpecialStage(int stageMenuId);
BOOL loadWarp(void);
BOOL loadThanks(void);
BOOL loadPlanet(void);
BOOL loadTimeAttack(BOOL param_1);
BOOL loadStageByMenu(UINT stageMenuId);
void toggleController(void);
BOOL setupJoystick(void);
void updateSwdata(UCHAR buttonsPressed, ushort_union* pSwdata);
void readController(int param_1);
void resetInput(void);
void __stdcall CDPlay(short trackNumber);
void CDPause(void);
void changeMusic(void);
void readStageString(char* str);
void log(char* msg);
void showCustomError(int id, char* pMsg);
void readRecording(void);
void writeRecording(void);
short FUN_0040c00c(HWND hWnd);
int showSonicDlg(HWND hWnd, LPCSTR resourceId, LPCSTR dialogId, LPARAM initValue);
void loadIni(void);
BOOL isDisplay256Colors(void);

#endif
