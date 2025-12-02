#include "..\COMMON\ENGINE_DLL.H"

void OESetSequenceNum(unsigned short num);
void KeyWait(void);
void WaitKeyOff(void);
void Wait(int time);
void WaitAndDfltMsg(int time);
void DLLInit(engine_dll* lpDllIn, char*** pBufTbl, void** pFuncTbl);
void DLLEnd(void);
void SWdataSet(ushort_union sw1, ushort_union sw2);
int DLLMain(void);
