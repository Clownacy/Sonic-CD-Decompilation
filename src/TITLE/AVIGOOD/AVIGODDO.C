#include "..\..\TYPES.H"
#include "AVIGODDO.H"
#include "AVIGODEN.H"

#if defined(AVIBAD)
static char* fileName[2] = {
  "TITLE\\BMP\\BADAVI\\MES1.BMP",
  "TITLE\\BMP\\GOODAVI\\MES2.BMP"
};
static POINT bmpSize[2] = {
  { 72, 16 },
  { 160, 24 }
};
static POINT bmpPosi[2] = {
  { 124, 168 },
  { 80, 100 }
};
#endif

#if defined(AVIGOOD)
static char* fileName[2] = {
  "TITLE\\BMP\\GOODAVI\\MES1.BMP",
  "TITLE\\BMP\\GOODAVI\\MES2.BMP"
};
static POINT bmpSize[2] = {
  { 128, 16 },
  { 160, 24 }
};
static POINT bmpPosi[2] = {
  { 96, 168 },
  { 80, 100 }
};
#endif

extern int(*sMovieStat)(void);
extern int(*sMoviePlay)(int);
extern int nTimerCunt;
int nPlayFileNum;
extern int(*sMovieStop)(void);
static int nDispBMPFileNum;
extern unsigned int* lpbFullScreen;
extern unsigned short swData1;
static int hBmp[2];












































void AVIOpeningMove(void) { /* Line 88, Address: 0x1000000 */
  int stat;

  if (nTimerCunt == 0) { /* Line 91, Address: 0x100000c */

#if defined(AVIBAD)
    sMoviePlay(2); /* Line 94 */
#elif defined(AVIGOOD)
    sMoviePlay(4); /* Line 96, Address: 0x100001c */
#endif
  } else { /* Line 98, Address: 0x1000030 */
    stat = sMovieStat(); /* Line 99, Address: 0x1000038 */
    if (stat == 3) { /* Line 100, Address: 0x100004c */
      PlayNextAVI(); /* Line 101, Address: 0x1000058 */
    }
  }


} /* Line 106, Address: 0x1000060 */




void PlayNextAVI(void) { /* Line 111, Address: 0x1000080 */


  ++nPlayFileNum; /* Line 114, Address: 0x1000088 */
  sMovieStop(); /* Line 115, Address: 0x100009c */
  if (nPlayFileNum < 2) { /* Line 116, Address: 0x10000ac */

#if defined(AVIBAD)
    sMoviePlay(3); /* Line 119 */
#elif defined(AVIGOOD)
    sMoviePlay(5); /* Line 121, Address: 0x10000c0 */
#endif
  } /* Line 123, Address: 0x10000d4 */
  else {

    OESetSequenceNum(2); /* Line 126, Address: 0x10000dc */
  }
} /* Line 128, Address: 0x10000e8 */




void AVIEnd(void) { /* Line 133, Address: 0x1000100 */
  sMovieStop(); /* Line 134, Address: 0x1000108 */
} /* Line 135, Address: 0x1000118 */




void AVIEndWait(void) { /* Line 140, Address: 0x1000130 */

  if (*lpbFullScreen != 0) { /* Line 142, Address: 0x1000138 */
    OESetSequenceNum(3); /* Line 143, Address: 0x100014c */
  } /* Line 144, Address: 0x1000158 */
  else if (nTimerCunt > 120) { /* Line 145, Address: 0x1000160 */


    OESetSequenceNum(3); /* Line 148, Address: 0x1000174 */
    nDispBMPFileNum = 1; /* Line 149, Address: 0x1000180 */
  }
} /* Line 151, Address: 0x100018c */








int AVIEndKeyWait(void) { /* Line 160, Address: 0x10001a0 */
  int ret = 0; /* Line 161, Address: 0x10001a8 */


  if ((swData1 & 240) || *lpbFullScreen == 1 ) { /* Line 164, Address: 0x10001ac */

#if defined(AVIBAD)
    ret = 17;
#elif defined(AVIGOOD)
    ret = 16; /* Line 169, Address: 0x10001dc */
#endif
  }
  return ret; /* Line 172, Address: 0x10001e0 */
} /* Line 173, Address: 0x10001e4 */






























































































































































void ReadDIB(void) {} /* Line 332, Address: 0x1000200 */












void FreeDIB(void) {} /* Line 345, Address: 0x1000210 */
