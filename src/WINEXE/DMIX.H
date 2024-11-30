#ifndef DMIX_H
#define DMIX_H

#include <windows.h>

__declspec(dllimport) int __stdcall _objSetPosition(void*, POINT);
__declspec(dllimport) void __stdcall _fxSetActive(void*, int);
__declspec(dllimport) int __stdcall _objSetDestination(void*, void*);
__declspec(dllimport) int __stdcall _objApplyEffect(void*, RECT, void*, void**);
__declspec(dllimport) void __stdcall _objSetVisibility(void*, int);
__declspec(dllimport) int __stdcall _objSetDrawOrder(void*, int);
__declspec(dllimport) int __stdcall _objSetView(void*, RECT);
__declspec(dllimport) int __stdcall _objSetDestRect(void*, short, short, short, short);
__declspec(dllimport) int __stdcall _srfSetDestWindow(void*, HWND);
__declspec(dllimport) int __stdcall _srfCreate(int, int, int, void**);
__declspec(dllimport) int __stdcall _srfDelete(void*);
__declspec(dllimport) int __stdcall _objRemoveEffect(void*, void*);
__declspec(dllimport) int __stdcall _srfDraw(void*);
__declspec(dllimport) int __stdcall _devSetPalette(int, int, PALETTEENTRY*);
__declspec(dllimport) int __stdcall _devGetPalette(int, int, PALETTEENTRY*);
__declspec(dllimport) int __stdcall _objPrepare(void*);

#endif
