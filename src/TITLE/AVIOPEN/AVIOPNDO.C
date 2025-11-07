#include "AVIOPNDO.H"

#if defined(AVIOPEN)
static char szAVIFile[18] = "title\\avi\\opn.avi";
#endif
#if defined(AVIPEN)
static char szAVIFile[21] = "title\\avi\\pencil.avi";
#endif
static unsigned int bAVIStart;
extern int(*sMoviePlay)(int);
extern int nTimerCunt;
extern int(*sMovieStop)(void);
static unsigned int hWndMovie;
extern unsigned short wMCIDeviceID;



























































void ReadDIB(char* fileName) { /* Line 74, Address: 0x1000000 */










} /* Line 85, Address: 0x1000004 */












void FreeDIB(void) {} /* Line 98, Address: 0x1000010 */



















void AVIOpeningMove(void) { /* Line 118, Address: 0x1000020 */
  if (nTimerCunt == 0) { /* Line 119, Address: 0x1000028 */

#if defined(AVIOPEN)
    sMoviePlay(0); /* Line 122 */
#elif defined(AVIPEN)
    sMoviePlay(1); /* Line 124, Address: 0x1000038 */
#endif






    bAVIStart = 1; /* Line 132, Address: 0x100004c */
  }




} /* Line 138, Address: 0x1000058 */




void AVIEnd(void) { /* Line 143, Address: 0x1000070 */
  sMovieStop(); /* Line 144, Address: 0x1000078 */


  bAVIStart = 0; /* Line 147, Address: 0x1000088 */
} /* Line 148, Address: 0x1000090 */




void AVIPaint(unsigned int hdc) { /* Line 153, Address: 0x10000a0 */









} /* Line 163, Address: 0x10000a4 */
