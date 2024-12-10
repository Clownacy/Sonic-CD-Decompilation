#include "WAVE.H"

/* 00425a00 */ int gWaveInfoUnknown44Array[6];
/* 0042ce0c */ int gWaveDeviceCnt2;
/* 0042cf7c */ HWND ghWnd;
/* 004331d8 */ int DAT_004331d8 = 0;
/* 004331dc */ BOOL gbWaveOpen = FALSE;


void __stdcall WaveRequest(short ReqNo) {
  int index;
  int cnt;
  int i;
  if (!gbWaveOpen) return;
  index = getFreeWaveInfoIndex();
  if (index >= 0) {
    DAT_004331d8 = index;
    FUN_0040dac4(DAT_004331d8, ReqNo, ghWnd, FALSE);
  }
  else {
    cnt = collectWaveInfoUnknown44(gWaveInfoUnknown44Array);

    for (i = 0; i < cnt; ++i) {
      if (gWaveInfoUnknown44Array[i] >= 0 && gWaveInfoUnknown44Array[i] < gWaveDeviceCnt2) {
        DAT_004331d8 = gWaveInfoUnknown44Array[i];
        FUN_0040dac4(DAT_004331d8, ReqNo, ghWnd, TRUE);
        break;
      }
    }
  }
}
