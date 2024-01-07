#include "..\..\TYPES.H"
#include "..\COMMON\SCORE_DATA_TYPES.H"
#include "SVDFILE.H"

extern unsigned int(*ReadScore)(int, char*, unsigned int);
score_data saveData[6];
extern unsigned int(*CloseScore)(unsigned int);
extern int nSelectFileNumber;
extern int(*ReadIndx)(unsigned int);
extern unsigned int(*OpenScore)(int);
extern void(*sMemCpy)(void*, void*, int);
extern score_data* lpCrntScorData;
extern unsigned int(*WriteScore)(int, char*, unsigned int);
extern unsigned int(*WriteIndx)(int, unsigned int);


















void ReadDataFile() { /* Line 33, Address: 0x1001ed0 */
  int n;
  int indx;
  unsigned int hFile;

  hFile = OpenScore(0); /* Line 38, Address: 0x1001ee4 */


  indx = ReadIndx(hFile); /* Line 41, Address: 0x1001efc */
  if (indx < 0 || indx >= 6) /* Line 42, Address: 0x1001f14 */
    return; /* Line 43, Address: 0x1001f28 */
  nSelectFileNumber = indx; /* Line 44, Address: 0x1001f30 */
  CloseScore(hFile); /* Line 45, Address: 0x1001f38 */
  for (n = 0; n < 6; ++n) /* Line 46, Address: 0x1001f4c */
  {
    ReadScore(n, (char*)&saveData[n], 0); /* Line 48, Address: 0x1001f58 */
  } /* Line 49, Address: 0x1001f90 */

} /* Line 51, Address: 0x1001fa0 */




void WriteDataFile() { /* Line 56, Address: 0x1001fc0 */
  int n;
  unsigned int hFile;

  hFile = OpenScore(1); /* Line 60, Address: 0x1001fd0 */






  WriteIndx(nSelectFileNumber, hFile); /* Line 67, Address: 0x1001fe8 */
  CloseScore(hFile); /* Line 68, Address: 0x1002004 */
  for (n = 0; n < 6; ++n) /* Line 69, Address: 0x1002018 */
  {
    WriteScore(n, (char*)&saveData[n], 0); /* Line 71, Address: 0x1002024 */
  } /* Line 72, Address: 0x100205c */

  sMemCpy(lpCrntScorData, &saveData[nSelectFileNumber], sizeof(saveData[nSelectFileNumber])); /* Line 74, Address: 0x100206c */
} /* Line 75, Address: 0x10020b0 */
