#include "..\..\TYPES.H"
#include "STGITEM.H"
#include "STGDO.H"
#include "..\COMMON\GRID.H"
#include "..\COMMON\HMX_OEEACTL.H"
#include "STGENTRY.H"
#include "STGSPRT.H"

static void UpdateMenu(void);

extern unsigned short nSequenceNum;
extern stgitem menuTbl[];
static int nMenuIndx;
extern unsigned short swData1;
extern int MENUITEMMAX;
extern unsigned short* lpSelectedStage;
extern int nTimerCunt;




























void STGDraw(void) { /* Line 46, Address: 0x1000900 */
  if (nSequenceNum > 1) /* Line 47, Address: 0x1000908 */
  {
    srfDraw(); /* Line 49, Address: 0x1000920 */
  }
} /* Line 51, Address: 0x1000928 */




static void UpdateMenu(void) { /* Line 56, Address: 0x1000940 */
  StrMenu(menuTbl[nMenuIndx].str); /* Line 57, Address: 0x1000948 */
} /* Line 58, Address: 0x100096c */




void STGStart(void) { /* Line 63, Address: 0x1000980 */
  int n;

  OEGridCreate(0); /* Line 66, Address: 0x100098c */
  for (n = 0; n < 16; ++n) /* Line 67, Address: 0x1000998 */
  {
    OESprCreateIndx(n + 48); /* Line 69, Address: 0x10009a4 */
  } /* Line 70, Address: 0x10009b0 */
  for (n = 0; n < 11; ++n) /* Line 71, Address: 0x10009c4 */
  {
    OESprCreateIndx(n); /* Line 73, Address: 0x10009d0 */
  } /* Line 74, Address: 0x10009dc */
  nMenuIndx = 0; /* Line 75, Address: 0x10009f0 */
  UpdateMenu(); /* Line 76, Address: 0x10009f8 */
  OESetSequenceNum(2); /* Line 77, Address: 0x1000a00 */
} /* Line 78, Address: 0x1000a0c */




void STGMenu(void) { /* Line 83, Address: 0x1000a20 */
  if (swData1 & 256) /* Line 84, Address: 0x1000a28 */
  {
    if (nMenuIndx == 0) nMenuIndx = MENUITEMMAX - 1; /* Line 86, Address: 0x1000a40 */
    else --nMenuIndx; /* Line 87, Address: 0x1000a6c */
    UpdateMenu(); /* Line 88, Address: 0x1000a80 */
    KeyWait(); /* Line 89, Address: 0x1000a88 */
  } /* Line 90, Address: 0x1000a90 */
  else if (swData1 & 512) /* Line 91, Address: 0x1000a98 */
  {
    if (nMenuIndx == MENUITEMMAX - 1) nMenuIndx = 0; /* Line 93, Address: 0x1000ab0 */
    else ++nMenuIndx; /* Line 94, Address: 0x1000adc */
    UpdateMenu(); /* Line 95, Address: 0x1000af0 */
    KeyWait(); /* Line 96, Address: 0x1000af8 */
  } /* Line 97, Address: 0x1000b00 */

  else if (swData1 & 16384) /* Line 99, Address: 0x1000b08 */
  {
    OESetSequenceNum(999); /* Line 101, Address: 0x1000b20 */
  }

  if (swData1 & 4096) /* Line 104, Address: 0x1000b2c */
  {
    OESetSequenceNum(998); /* Line 106, Address: 0x1000b44 */
  }
} /* Line 108, Address: 0x1000b50 */




int STGEnd(void) { /* Line 113, Address: 0x1000b60 */
  int ret = 0; /* Line 114, Address: 0x1000b68 */

  if (nTimerCunt == 0) /* Line 116, Address: 0x1000b6c */
  {
    *lpSelectedStage = menuTbl[nMenuIndx].retcode; /* Line 118, Address: 0x1000b7c */
    ret = 15; /* Line 119, Address: 0x1000ba8 */
  }
  return ret; /* Line 121, Address: 0x1000bac */
} /* Line 122, Address: 0x1000bb0 */

int STGEnd2(void) { /* Line 124, Address: 0x1000bc0 */
  int ret = 0; /* Line 125, Address: 0x1000bc8 */

  if (nTimerCunt == 0) /* Line 127, Address: 0x1000bcc */
  {
    ret = 9; /* Line 129, Address: 0x1000bdc */
  }
  return ret; /* Line 131, Address: 0x1000be0 */
} /* Line 132, Address: 0x1000be4 */
