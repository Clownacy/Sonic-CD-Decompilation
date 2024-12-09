#ifndef DLL_H
#define DLL_H

#include <windows.h>

BOOL switchGameMenuDll(HWND hWnd, char* path, USHORT type);
BOOL loadOpening(HWND hWnd, void* hSurf);
void unloadGameMenuDll();
void unloadOpening();
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
void changeMovieSize();
BOOL FUN_0040e6fe(WPARAM wParam, LPARAM lParam);
void realizeMovie();
BOOL loadSavedata(HWND hWnd, void* hSurf);
void unloadSavedata();
BOOL loadVisualmd(HWND hWnd, void* hSurf);
BOOL loadSoundtst(HWND hWnd, void* hSurf);
BOOL loadStagetst(HWND hWnd, void* hSurf);
BOOL loadBesttime(HWND hWnd, void* hSurf);
void unloadBesttime();
void unloadVisualmd();
void unloadSoundtst();
void unloadStagetst();
void callDllChar(WPARAM wParam, LPARAM lParam);
void unloadCurrentGameMenuDll();
BOOL FUN_0040ec7b();
BOOL FUN_0040ecf7();
BOOL playBadEnding();
BOOL playGoodEnding();
BOOL playPen();
int changeGameState();
void pauseMovie();
void resumeMovie();

#endif
