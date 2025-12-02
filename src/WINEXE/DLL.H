#ifndef DLL_H
#define DLL_H

#include <windows.h>

BOOL switchGameMenuDll(HWND hWnd, char* path, USHORT type);
BOOL loadOpening(HWND hWnd, void* hSurf);
void unloadGameMenuDll(void);
void unloadOpening(void);
BOOL loadAviOpen(HWND hWnd);
BOOL loadAviGood(HWND hWnd);
BOOL loadAviBad(HWND hWnd);
BOOL loadAvipen(HWND hWnd);
void unloadAvi(HWND hWnd);
void unloadAviOpen(HWND hWnd);
void unloadAviGood(HWND hWnd);
void unloadAviBad(HWND hWnd);
void unloadAvipen(HWND hWnd);
void callDllPaint(HDC hDc);
void changeMovieSize(void);
BOOL FUN_0040e6fe(WPARAM wParam, LPARAM lParam);
void realizeMovie(void);
BOOL loadSavedata(HWND hWnd, void* hSurf);
void unloadSavedata(void);
BOOL loadVisualmd(HWND hWnd, void* hSurf);
BOOL loadSoundtst(HWND hWnd, void* hSurf);
BOOL loadStagetst(HWND hWnd, void* hSurf);
BOOL loadBesttime(HWND hWnd, void* hSurf);
void unloadBesttime(void);
void unloadVisualmd(void);
void unloadSoundtst(void);
void unloadStagetst(void);
void callDllChar(WPARAM wParam, LPARAM lParam);
void unloadCurrentGameMenuDll(void);
BOOL FUN_0040ec7b(void);
BOOL FUN_0040ecf7(void);
BOOL playBadEnding(void);
BOOL playGoodEnding(void);
BOOL playPen(void);
int changeMenuState(void);
void pauseMovie(void);
void resumeMovie(void);

#endif
