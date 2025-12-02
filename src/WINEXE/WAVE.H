#ifndef WAVE_H
#define WAVE_H

#include <windows.h>

int openWaveOut(HWND hWnd);
void closeWaveOut(void);
int loadPcmFile(char* path);
void freeWaveMemory(void);
int FUN_0040dac4(int waveInfoIndex, int ReqNo, HWND hWnd, BOOL bUnknown);
void WaveAllStop(void);
int FUN_0040dd16(HWAVEOUT hWaveout, LPWAVEHDR pWaveHdr);
int getFreeWaveInfoIndex(void);
int collectWaveInfoUnknown44(int* array);
int areWaveInfosFree(void);

#endif
