#include "..\COMMON\ENGINE_DLL.H"

void OESetSequenceNum(unsigned short num);
void KeyWait();
void WaitKeyOff();
void Wait(int time);
void DLLInit(engine_dll* lpDllIn, char*** pBufTbl, void** pFuncTbl);
void DLLEnd();
void SWdataSet(ushort_union sw1, ushort_union sw2);
int DLLMain();
