#include <windows.h>
#include "TYPES.H"

BOOL __stdcall ReadScoreData(int index, score_data* pOldScoreData, HFILE hExistingFile);
void __stdcall SetScoreDate(score_data* pScoreData);
BOOL __stdcall WriteScoreData(int index, score_data* pNewScoreData, HFILE hExistingFile);
void __stdcall OpenScoreData(int mode);
void __stdcall CloseScoreData(HFILE hFile);
HFILE __stdcall CreateScoreData();
int __stdcall ReadScoreIndx(HFILE hExistingFile);
BOOL __stdcall WriteScoreIndx(int index, HFILE hExistingFile);
void __stdcall initScoreData(score_data* pScoreData, int index);
void CALLBACK timeCallbackFunc(UINT uTimerID, UINT uMsg, ULONG dwUser, ULONG dw1, ULONG dw2);
BOOL readFirstScoreData();
BOOL newScoreData();
