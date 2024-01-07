#include "VMDDO.H"

void UpdateMenu();

extern unsigned short nSequenceNum;
unsigned short nMenuKind;
extern unsigned short swData1;
extern unsigned int* lpbVisualmode;
extern int nTimerCunt;




































void VMDDraw() { /* Line 46, Address: 0x1000000 */
  if (nSequenceNum >= 2) /* Line 47, Address: 0x1000008 */
  {
    srfDraw(); /* Line 49, Address: 0x1000020 */
  }

} /* Line 52, Address: 0x1000028 */




static void UpdateMenu() { /* Line 57, Address: 0x1000040 */
  if (nMenuKind == 1) StrEXIT(1); /* Line 58, Address: 0x1000048 */
  else StrEXIT(0); /* Line 59, Address: 0x1000074 */
  if (nMenuKind == 2) StrOPENING(1); /* Line 60, Address: 0x1000080 */
  else StrOPENING(0); /* Line 61, Address: 0x10000ac */
  if (nMenuKind == 3) StrGOODENDING(1); /* Line 62, Address: 0x10000b8 */
  else StrGOODENDING(0); /* Line 63, Address: 0x10000e4 */
  if (nMenuKind == 4) StrBADENDING(1); /* Line 64, Address: 0x10000f0 */
  else StrBADENDING(0); /* Line 65, Address: 0x100011c */
  if (nMenuKind == 5) StrPENCILTEST(1); /* Line 66, Address: 0x1000128 */
  else StrPENCILTEST(0); /* Line 67, Address: 0x1000154 */
} /* Line 68, Address: 0x1000160 */




void VMDStart() { /* Line 73, Address: 0x1000170 */
  int n;

  OEGridCreate(0); /* Line 76, Address: 0x100017c */
  for (n = 0; n < 16; ++n) /* Line 77, Address: 0x1000188 */
  {
    OESprCreateIndx(n + 52); /* Line 79, Address: 0x1000194 */
  } /* Line 80, Address: 0x10001a0 */
  nMenuKind = 1; /* Line 81, Address: 0x10001b4 */
  UpdateMenu(); /* Line 82, Address: 0x10001c0 */
  OESetSequenceNum(2); /* Line 83, Address: 0x10001c8 */
} /* Line 84, Address: 0x10001d4 */




void VMDMenu() { /* Line 89, Address: 0x10001f0 */
  unsigned short nMenuKindOld;

  if (swData1 & 512) /* Line 92, Address: 0x1000204 */
  {
    nMenuKindOld = nMenuKind; /* Line 94, Address: 0x100021c */
    nMenuKind = nMenuKind + 1 < 5 ? nMenuKind + 1 : 5; /* Line 95, Address: 0x1000228 */
    if (nMenuKind == nMenuKindOld) return; /* Line 96, Address: 0x100026c */

    UpdateMenu(); /* Line 98, Address: 0x1000284 */
    KeyWait(); /* Line 99, Address: 0x100028c */

  } /* Line 101, Address: 0x1000294 */
  else if (swData1 & 256) /* Line 102, Address: 0x100029c */
  {
    nMenuKindOld = nMenuKind; /* Line 104, Address: 0x10002b4 */
    nMenuKind = nMenuKind - 1 >= 2 ? nMenuKind - 1 : 1; /* Line 105, Address: 0x10002c0 */
    if (nMenuKind == nMenuKindOld) return; /* Line 106, Address: 0x1000304 */

    UpdateMenu(); /* Line 108, Address: 0x100031c */
    KeyWait(); /* Line 109, Address: 0x1000324 */

  } /* Line 111, Address: 0x100032c */
  else if (!(swData1 & 16384) && swData1 & 4096) /* Line 112, Address: 0x1000334 */
  {
    OESetSequenceNum(999); /* Line 114, Address: 0x1000364 */
  }

} /* Line 117, Address: 0x1000370 */




int VMDEnd() { /* Line 122, Address: 0x1000390 */
  int ret = 0; /* Line 123, Address: 0x1000398 */

  if (nTimerCunt == 0) /* Line 125, Address: 0x100039c */
  {
    switch (nMenuKind) /* Line 127, Address: 0x10003ac */
    {
      case 1:
        ret = 9; /* Line 130, Address: 0x10003fc */
        *lpbVisualmode = 0; /* Line 131, Address: 0x1000400 */
        break; /* Line 132, Address: 0x100040c */
      case 2: ret = 8; break; /* Line 133, Address: 0x1000414 */
      case 3: ret = 10; break; /* Line 134, Address: 0x1000420 */
      case 4: ret = 11; break; /* Line 135, Address: 0x100042c */
      case 5: ret = 12; break; /* Line 136, Address: 0x1000438 */
    }
  }
  return ret; /* Line 139, Address: 0x100043c */
} /* Line 140, Address: 0x1000440 */
