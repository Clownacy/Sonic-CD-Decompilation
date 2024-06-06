#include "..\..\TYPES.H"
#include "..\COMMON\SCORE_DATA_TYPES.H"
#include "SVDEDIT.H"
#include "..\COMMON\HMX_OEEACTL.H"
#include "SVDDO.H"
#include "SVDENTRY.H"
#include "SVDSPRT.H"

static unsigned int bEditMode;
extern unsigned short swData1;
extern int nFileNumber;
char editBuf[12];
extern void(*WaveRequest)(short);
extern void(*sPrintf)(char*, const char*, ...);
extern score_data saveData[6];
extern int nSelectFileNumber;



































int Edit() { /* Line 52, Address: 0x1000c50 */
  int posi;

  bEditMode = 1; /* Line 55, Address: 0x1000c64 */
  if (swData1 & 1024) /* Line 56, Address: 0x1000c70 */
  {
    WaveRequest(54); /* Line 58, Address: 0x1000c88 */
    posi = GetCursolPositon(); /* Line 59, Address: 0x1000c9c */
    posi = posi - 1 > 0 ? posi - 1 : 0; /* Line 60, Address: 0x1000ca8 */
    DispCursol(); /* Line 61, Address: 0x1000cc8 */
    MovCursol(posi); /* Line 62, Address: 0x1000cd0 */
    Wait(2); /* Line 63, Address: 0x1000cdc */
  } /* Line 64, Address: 0x1000ce8 */
  else if (swData1 & 2048) /* Line 65, Address: 0x1000cf0 */
  {
    WaveRequest(54); /* Line 67, Address: 0x1000d08 */
    posi = GetCursolPositon(); /* Line 68, Address: 0x1000d1c */
    posi = posi + 1 < 9 ? posi + 1 : 9; /* Line 69, Address: 0x1000d28 */
    DispCursol(); /* Line 70, Address: 0x1000d4c */
    MovCursol(posi); /* Line 71, Address: 0x1000d54 */
    Wait(2); /* Line 72, Address: 0x1000d60 */
  } /* Line 73, Address: 0x1000d6c */
  else if (swData1 & 512) /* Line 74, Address: 0x1000d74 */
  {
    WaveRequest(54); /* Line 76, Address: 0x1000d8c */
    posi = GetCursolPositon(); /* Line 77, Address: 0x1000da0 */
    if (editBuf[posi] == 32) editBuf[posi] = 90; /* Line 78, Address: 0x1000dac */
    else if (editBuf[posi] == 45) editBuf[posi] = 32; /* Line 79, Address: 0x1000dec */
    else if (editBuf[posi] == 48) editBuf[posi] = 45; /* Line 80, Address: 0x1000e2c */
    else if (editBuf[posi] == 65) editBuf[posi] = 57; /* Line 81, Address: 0x1000e6c */
    else --editBuf[posi]; /* Line 82, Address: 0x1000eac */
    DeleteCharSprt(nFileNumber + 2, posi); /* Line 83, Address: 0x1000ec4 */
    CreateCharSprt(editBuf[posi], 0, nFileNumber + 2, posi); /* Line 84, Address: 0x1000edc */
    Wait(2); /* Line 85, Address: 0x1000f08 */
  } /* Line 86, Address: 0x1000f14 */
  else if (swData1 & 256) /* Line 87, Address: 0x1000f1c */
  {
    WaveRequest(54); /* Line 89, Address: 0x1000f34 */
    posi = GetCursolPositon(); /* Line 90, Address: 0x1000f48 */
    if (editBuf[posi] == 32) editBuf[posi] = 45; /* Line 91, Address: 0x1000f54 */
    else if (editBuf[posi] == 45) editBuf[posi] = 48; /* Line 92, Address: 0x1000f94 */
    else if (editBuf[posi] == 57) editBuf[posi] = 65; /* Line 93, Address: 0x1000fd4 */
    else if (editBuf[posi] == 90) editBuf[posi] = 32; /* Line 94, Address: 0x1001014 */
    else ++editBuf[posi]; /* Line 95, Address: 0x1001054 */
    DeleteCharSprt(nFileNumber + 2, posi); /* Line 96, Address: 0x100106c */
    CreateCharSprt(editBuf[posi], 0, nFileNumber + 2, posi); /* Line 97, Address: 0x1001084 */
    Wait(2); /* Line 98, Address: 0x10010b0 */
  } /* Line 99, Address: 0x10010bc */
  else if (swData1 & 16384) /* Line 100, Address: 0x10010c4 */
  {
    bEditMode = 0; /* Line 102, Address: 0x10010dc */
    WaitKeyOff(); /* Line 103, Address: 0x10010e4 */
    return 1; /* Line 104, Address: 0x10010ec */
  }
  else if (swData1 & 4096) /* Line 106, Address: 0x10010f8 */
  {
    bEditMode = 0; /* Line 108, Address: 0x1001110 */
    WaitKeyOff(); /* Line 109, Address: 0x1001118 */
    return -1; /* Line 110, Address: 0x1001120 */
  }
  return 0; /* Line 112, Address: 0x100112c */
} /* Line 113, Address: 0x1001130 */








































void DispSaveData(int indx) { /* Line 154, Address: 0x1001150 */
  char str[256];
  int round;



  if (saveData[indx].saved != 0) /* Line 160, Address: 0x1001160 */
  {
    CreateStringSprt(saveData[indx].player, 0, indx + 2, 0); /* Line 162, Address: 0x1001190 */

    sPrintf(str, "%4u/%2u/%2u", saveData[indx].year, saveData[indx].month, saveData[indx].date); /* Line 164, Address: 0x10011d0 */

    CreateStringSprt(str, 0, indx + 2, 19); /* Line 166, Address: 0x1001270 */

    round = saveData[indx].roundNo + 1; /* Line 168, Address: 0x100128c */
    if (round > 7) round = 7; /* Line 169, Address: 0x10012b8 */
    sPrintf(str, "ROUND-%1d", round); /* Line 170, Address: 0x10012c8 */
    CreateStringSprt(str, 2, indx + 2, 12); /* Line 171, Address: 0x10012e8 */



    sPrintf(str, "%02u\"%02u\"%02u", saveData[indx].hour, saveData[indx].min, saveData[indx].sec); /* Line 175, Address: 0x1001304 */











    CreateStringSprt(str, 0, indx + 2, 30); /* Line 187, Address: 0x10013a4 */

    OESprCreateIndx(indx + 193); /* Line 189, Address: 0x10013c0 */
  } /* Line 190, Address: 0x10013d0 */
  else
  {

    CreateStringSprt("NO DATA-FILE", 0, indx + 2, 44); /* Line 194, Address: 0x10013d8 */
    OESprDeleteIndx(indx + 193); /* Line 195, Address: 0x10013f8 */
  }
} /* Line 197, Address: 0x1001408 */


























void DispAll() { /* Line 224, Address: 0x1001420 */
  int i;

  DefaultMessage(); /* Line 227, Address: 0x100142c */
  OESprCreateIndx(1); /* Line 228, Address: 0x1001434 */
  OESprCreateIndx(2); /* Line 229, Address: 0x1001440 */
  OESprCreateIndx(4); /* Line 230, Address: 0x100144c */
  OESprCreateIndx(6); /* Line 231, Address: 0x1001458 */
  OESprCreateIndx(8); /* Line 232, Address: 0x1001464 */
  for (i = 0; i < 6; ++i) /* Line 233, Address: 0x1001470 */
  {
    DispSaveData(i); /* Line 235, Address: 0x100147c */
  } /* Line 236, Address: 0x1001488 */
  UpdateSelectSonicMark(nSelectFileNumber); /* Line 237, Address: 0x100149c */

} /* Line 239, Address: 0x10014b0 */
