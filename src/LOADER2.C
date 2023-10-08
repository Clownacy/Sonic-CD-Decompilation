#include "EQU.H"
#include "LOADER2.H"

static unsigned int SE_DashReq;
extern void(*sOutputDebugString)(char*);
extern void(*sPrintf)(char*, const char*, ...);
extern void(*sCloseFile)(int);
extern int(*sReadFile)(int, void*, int);
extern int(*sOpenFile)(char*);
extern void(*sMemSet)(void*, unsigned char, int);
static unsigned char SeToWavTbl[80] = {
   0,  1,  2,  3,  4,  5,  6,  7,
   8,  9, 10, 11, 11, 12, 13, 14,
  15, 16, 17, 18, 19, 20, 20, 21,
  22, 22, 23, 23, 24, 25, 26, 27,
  28, 29, 30, 31, 43, 44, 45, 46,
  47, 48, 49, 50, 51, 52, 53, 54,
  55, 56, 57, 58, 58, 59, 60, 61,
  62, 63, 64, 65, 67, 68, 69, 70,
  71, 71, 72, 73, 74, 32, 33, 34,
  35, 36, 37, 38, 39, 40, 41, 42
};
extern void(*WaveRequest)(short);
extern void(*CDPlay)(short);








void GetRoundStr(unsigned short StageNo, unsigned char Time_Flag, char* buf) { /* Line 33, Address: 0x10136b0 */
  unsigned char stage, round;

  round = (char)(StageNo >> 8) + 1; /* Line 36, Address: 0x10136c8 */
  if (round >= 2) ++round; /* Line 37, Address: 0x10136e0 */
  stage = (char)StageNo + 1; /* Line 38, Address: 0x10136f8 */

  *buf++ = round + 48; /* Line 40, Address: 0x1013710 */
  *buf++ = stage + 48; /* Line 41, Address: 0x1013734 */
  switch (Time_Flag & 127) { /* Line 42, Address: 0x1013758 */
    case 0:
      *buf++ = 66; /* Line 44, Address: 0x101378c */
      break; /* Line 45, Address: 0x10137a0 */
    case 1:
      *buf++ = 65; /* Line 47, Address: 0x10137a8 */
      break; /* Line 48, Address: 0x10137bc */
    case 2:
      if (generate_flag) *buf++ = 67; /* Line 50, Address: 0x10137c4 */
      else *buf++ = 68; /* Line 51, Address: 0x10137f0 */
  }

  *buf++ = 0; /* Line 54, Address: 0x1013804 */

} /* Line 56, Address: 0x1013814 */


void ReadBlockMap() { /* Line 59, Address: 0x1013830 */
  int hf;
  char buf[80];
  char fn[80];

  GetRoundStr(stageno.w, time_flag, buf); /* Line 64, Address: 0x101383c */



  sPrintf(fn, "R%c\\%3s\\T%3s.MAP", buf[0], buf, buf); /* Line 68, Address: 0x101385c */






  sMemSet(blockwk, 0, 8192); /* Line 75, Address: 0x101388c */
  hf = sOpenFile(fn); /* Line 76, Address: 0x10138ac */
  if (hf == -1) { /* Line 77, Address: 0x10138c4 */

    sPrintf(buf, "Block Map Read Error:%s\n", fn); /* Line 79, Address: 0x10138d0 */
    sOutputDebugString(buf); /* Line 80, Address: 0x10138f0 */

  } /* Line 82, Address: 0x1013904 */
  else {
    sReadFile(hf, blockwk, 8192); /* Line 84, Address: 0x101390c */
    sCloseFile(hf); /* Line 85, Address: 0x101392c */

    sPrintf(buf, "Block Map Read:%s\n", fn); /* Line 87, Address: 0x1013940 */
    sOutputDebugString(buf); /* Line 88, Address: 0x1013960 */

  }
} /* Line 91, Address: 0x1013974 */



void ReadScrolMap() { /* Line 95, Address: 0x1013990 */
  int hf;
  unsigned short* p;
  int i;
  char buf[80];
  char fn[80];


  GetRoundStr(stageno.w, time_flag, buf); /* Line 103, Address: 0x10139a4 */



  sPrintf(fn, "R%c\\%3s\\MAP%3s.BIN", buf[0], buf, buf); /* Line 107, Address: 0x10139c4 */






  p = pmapwk; /* Line 114, Address: 0x10139f4 */
  for (i = 0; i < 128; ++i) { /* Line 115, Address: 0x10139fc */
    sMemSet(pmapwk, 0, 512); /* Line 116, Address: 0x1013a08 */
    p += 256; /* Line 117, Address: 0x1013a28 */
  } /* Line 118, Address: 0x1013a2c */

  hf = sOpenFile(fn); /* Line 120, Address: 0x1013a3c */
  if (hf == -1) { /* Line 121, Address: 0x1013a54 */

    sPrintf(buf, "Scroll Map Read Error:%s\n", fn); /* Line 123, Address: 0x1013a60 */
    sOutputDebugString(buf); /* Line 124, Address: 0x1013a80 */

  } /* Line 126, Address: 0x1013a94 */
  else {
    p = pmapwk; /* Line 128, Address: 0x1013a9c */
    for (i = 0; i < 128; ++i) { /* Line 129, Address: 0x1013aa4 */


      if (sReadFile(hf, p, 512) == -1) break; /* Line 132, Address: 0x1013ab0 */


      p += 256; /* Line 135, Address: 0x1013ad8 */
    } /* Line 136, Address: 0x1013adc */
    sCloseFile(hf); /* Line 137, Address: 0x1013aec */

    sPrintf(buf, "Scroll Map Read:%s\n", fn); /* Line 139, Address: 0x1013b00 */
    sOutputDebugString(buf); /* Line 140, Address: 0x1013b20 */

  }
} /* Line 143, Address: 0x1013b34 */



















void soundset(short ReqNo) { /* Line 163, Address: 0x1013b50 */
  if (ReqNo == 171) return; /* Line 164, Address: 0x1013b5c */



  ReqNo -= 144; /* Line 168, Address: 0x1013b74 */
  ReqNo = (unsigned short)SeToWavTbl[ReqNo]; /* Line 169, Address: 0x1013b80 */

  WaveRequest(ReqNo); /* Line 171, Address: 0x1013bac */
} /* Line 172, Address: 0x1013bc0 */




void sub_sync(short ReqNo) { /* Line 177, Address: 0x1013bd0 */
  if (ReqNo == 103) { /* Line 178, Address: 0x1013bdc */
    boss_sound = 1; /* Line 179, Address: 0x1013bf4 */
  }

  if (ReqNo >= 118 && ReqNo < 129) { /* Line 182, Address: 0x1013c00 */
    WaveRequest(ReqNo + -43); /* Line 183, Address: 0x1013c30 */
    return; /* Line 184, Address: 0x1013c58 */
  }
  if ((ReqNo >= 15 && ReqNo < 35) || (ReqNo >= 48 && ReqNo < 55)) { /* Line 186, Address: 0x1013c60 */
    CDPlay(ReqNo + -12); /* Line 187, Address: 0x1013cc0 */
  } /* Line 188, Address: 0x1013ce8 */
  else if (ReqNo >= 102 && ReqNo < 113) { /* Line 189, Address: 0x1013cf0 */
    CDPlay(ReqNo + -79); /* Line 190, Address: 0x1013d20 */
  } /* Line 191, Address: 0x1013d48 */
  else if (ReqNo == 113) { /* Line 192, Address: 0x1013d50 */
    CDPlay(2); /* Line 193, Address: 0x1013d68 */
  } /* Line 194, Address: 0x1013d7c */
  else if (ReqNo >= 114 && ReqNo < 116) { /* Line 195, Address: 0x1013d84 */
    CDPlay(ReqNo + -80); /* Line 196, Address: 0x1013db4 */
  } else if (ReqNo == 146) { /* Line 197, Address: 0x1013ddc */
    WaveRequest(85); /* Line 198, Address: 0x1013dfc */
  }
} /* Line 200, Address: 0x1013e10 */
