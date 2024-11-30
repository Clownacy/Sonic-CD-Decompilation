#ifndef DINO2D_H
#define DINO2D_H

typedef struct myPoint {
  unsigned short x;
  unsigned short y;
}
myPoint;

__declspec(dllimport) int __stdcall _sprCreate(void**);
__declspec(dllimport) void __stdcall _sprDelete(void*);
__declspec(dllimport) int __stdcall _grdSetData(void*, myPoint, void*);
__declspec(dllimport) int __stdcall _grdClearData(void*, myPoint);
__declspec(dllimport) void __stdcall _hbmpPrepare(void*, int, int);
__declspec(dllimport) int __stdcall _hbmpCreate(int, int, int, void**);
__declspec(dllimport) int __stdcall _hbmpReleaseBuffer(void*);
__declspec(dllimport) int __stdcall _hbmpGetLockedBuffer(void*, char**, int**);
__declspec(dllimport) int __stdcall _hbmpDelete(void*);
__declspec(dllimport) int __stdcall _bkgSetData(void*, void*);
__declspec(dllimport) int __stdcall _bkgCreate(void**);
__declspec(dllimport) int __stdcall _bkgDelete(void*);
__declspec(dllimport) int __stdcall _grdCreate(int, int, int, int, void*);
__declspec(dllimport) int __stdcall _tleSetData(void*, void*);
__declspec(dllimport) int __stdcall _tleCreate(void**);
__declspec(dllimport) void __stdcall _sprSetData(void*, void*);
__declspec(dllimport) int __stdcall _tleDelete(void*);
__declspec(dllimport) int __stdcall _grdDelete(void*);
__declspec(dllimport) RECT FX_RENDER_CALLBACK;
__declspec(dllimport) RECT FX_HORIZ_SHEAR;
__declspec(dllimport) RECT FX_MODEX_DISPLAY;
__declspec(dllimport) RECT FX_SMORPH;
__declspec(dllimport) RECT FX_VERT_FLIP;
__declspec(dllimport) RECT FX_HORIZ_FLIP;

#endif
