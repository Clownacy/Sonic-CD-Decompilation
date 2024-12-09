#ifndef WAVE_H
#define WAVE_H

#include <windows.h>

int openWaveOut(HWND hWnd);
void closeWaveOut();
int loadPcmFile(char* path);
void freeWaveMemory();
void WaveAllStop();
int FUN_0040dd16(HWAVEOUT hWaveout, LPWAVEHDR pWaveHdr);
int areWaveInfosFree();

#endif
