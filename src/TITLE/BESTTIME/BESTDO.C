#include "..\..\TYPES.H"
#include "BESTITEM.H"
#include "..\COMMON\GRID.H"
#include "..\COMMON\HMX_OEEACTL.H"
#include "BESENTRY.H"
#include "BESTSPRT.H"

static void UpdateMenu();
static int STGMenuMaxCheck(int index);

extern unsigned short nSequenceNum;
extern bestitem menuTbl[];
static int nMenuIndx;
extern int MENUITEMMAX;
int ScrollCount;
extern void(*CDPlay)(short);
extern unsigned short swData1;
extern void(*CDPause)(short);
extern int nTimerCunt;




























void STGDraw() { /* Line 48, Address: 0x1000900 */
  if (nSequenceNum > 1) /* Line 49, Address: 0x1000908 */
  {
    srfDraw(); /* Line 51, Address: 0x1000920 */
  }
} /* Line 53, Address: 0x1000928 */




static void UpdateMenu() { /* Line 58, Address: 0x1000940 */
  int i, index;

  for (i = 0; i < 9; ++i) /* Line 61, Address: 0x1000950 */
  {
    index = STGMenuMaxCheck(nMenuIndx + i); /* Line 63, Address: 0x100095c */
    if (menuTbl[index].color != 0) /* Line 64, Address: 0x1000974 */
      StrMenu(i, menuTbl[index].str); /* Line 65, Address: 0x1000990 */
    else
      StrMenu2(i, menuTbl[index].str); /* Line 67, Address: 0x10009b8 */
  } /* Line 68, Address: 0x10009d8 */
} /* Line 69, Address: 0x10009e8 */

static int STGMenuMaxCheck(int index) { /* Line 71, Address: 0x1000a00 */
  if (index >= MENUITEMMAX) return index - MENUITEMMAX; /* Line 72, Address: 0x1000a08 */
  return index; /* Line 73, Address: 0x1000a38 */
} /* Line 74, Address: 0x1000a3c */




void STGStart() { /* Line 79, Address: 0x1000a50 */
  int n;

  CDPlay(29); /* Line 82, Address: 0x1000a5c */
  OEGridCreate(0); /* Line 83, Address: 0x1000a70 */
  for (n = 0; n < 16; ++n) /* Line 84, Address: 0x1000a7c */
  {
    OESprCreateIndx(n + 73); /* Line 86, Address: 0x1000a88 */
  } /* Line 87, Address: 0x1000a94 */
  for (n = 0; n < 8; ++n) /* Line 88, Address: 0x1000aa8 */
  {
    OESprCreateIndx(n + 92); /* Line 90, Address: 0x1000ab4 */
  } /* Line 91, Address: 0x1000ac0 */






  OESprCreateIndx(89); /* Line 98, Address: 0x1000ad4 */
  OESprCreateIndx(90); /* Line 99, Address: 0x1000ae0 */
  OESprCreateIndx(91); /* Line 100, Address: 0x1000aec */
  nMenuIndx = 0; /* Line 101, Address: 0x1000af8 */
  ScrollCount = 0; /* Line 102, Address: 0x1000b00 */
  UpdateMenu(); /* Line 103, Address: 0x1000b08 */
  OESetSequenceNum(2); /* Line 104, Address: 0x1000b10 */

} /* Line 106, Address: 0x1000b1c */




void STGMenu() { /* Line 111, Address: 0x1000b30 */
  if (swData1 & 256) /* Line 112, Address: 0x1000b38 */
  {
    if (nMenuIndx > 0 || (nMenuIndx == 0 && ScrollCount < 0)) /* Line 114, Address: 0x1000b50 */
    {
      ++ScrollCount; /* Line 116, Address: 0x1000b80 */
      if (ScrollCount == 3) /* Line 117, Address: 0x1000b94 */
      {
        ScrollCount = 0; /* Line 119, Address: 0x1000ba8 */

        if (nMenuIndx != 0) /* Line 121, Address: 0x1000bb0 */
          --nMenuIndx; /* Line 122, Address: 0x1000bc0 */
      }
      UpdateMenu(); /* Line 124, Address: 0x1000bd4 */
      KeyWait(); /* Line 125, Address: 0x1000bdc */
    }
  } else /* Line 127, Address: 0x1000be4 */
  {
    if (swData1 & 512) /* Line 129, Address: 0x1000bec */
    {
      if (nMenuIndx <= MENUITEMMAX - 11 /* Line 131, Address: 0x1000c04 */
          || (nMenuIndx == MENUITEMMAX - 10 && ScrollCount >= -1))
      {
        --ScrollCount; /* Line 134, Address: 0x1000c54 */
        if (ScrollCount == -3) /* Line 135, Address: 0x1000c68 */
        {
          ScrollCount = 0; /* Line 137, Address: 0x1000c7c */

          if (nMenuIndx != MENUITEMMAX - 1) /* Line 139, Address: 0x1000c84 */
            ++nMenuIndx; /* Line 140, Address: 0x1000ca0 */
        }
        UpdateMenu(); /* Line 142, Address: 0x1000cb4 */
        KeyWait(); /* Line 143, Address: 0x1000cbc */
      }
    }
  }
  if (swData1 & 4096) /* Line 147, Address: 0x1000cc4 */
  {
    OESetSequenceNum(998); /* Line 149, Address: 0x1000cdc */
  }
} /* Line 151, Address: 0x1000ce8 */

















int STGEnd2() { /* Line 169, Address: 0x1000d00 */
  int ret = 0; /* Line 170, Address: 0x1000d0c */

  if (nTimerCunt == 0) /* Line 172, Address: 0x1000d10 */
  {
    ret = 9; /* Line 174, Address: 0x1000d20 */
    CDPause(2); /* Line 175, Address: 0x1000d24 */
  }
  return ret; /* Line 177, Address: 0x1000d38 */
} /* Line 178, Address: 0x1000d3c */
