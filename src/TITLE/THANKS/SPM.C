#include "..\..\TYPES.H"
#include "THANKS_TYPES.H"
#include "SPM.H"

unsigned short comdata_s7;
unsigned short comdata_s6;
unsigned short comdata_s5;
unsigned short comdata_s4;
unsigned short comdata_s3;
unsigned short comdata_s2;
unsigned short comdata_s1;
unsigned short comdata_s0;
short_union swdata2;
short_union swdata1;
unsigned short comdata_m7;
unsigned short comdata_m6;
unsigned short comdata_m5;
unsigned short comdata_m4;
unsigned short comdata_m3;
unsigned short comdata_m2;
unsigned short comdata_m1;
unsigned short comdata_m0;
unsigned char comflag_s;
unsigned char comflag_m;
short end_timer;
short heart_tm;
short animal_timer;
unsigned char animal_flg;
unsigned char poseno;
short posetimer;
short coltimer2;
short colorno2;
extern void(*sMemSet)(void*, unsigned char, int);
short actset_tm[8];
short wkarea3;
short wkarea2;
short wkarea1;
short prg_mode;
unsigned char colorcnt;
unsigned char startcolor;
int overint;
int ranum;
short sr_save;
short gmtime1;
short gmtime0;
short intmode;
short linkdata;
short coltimer;
short colorno;
unsigned char colorflg;
unsigned char int_flg;
unsigned char push_flg;
unsigned char quit_flg;
sprite_status_thanks** priptr[4];
sprite_status_thanks* pribuf3[64];
sprite_status_thanks* pribuf2[64];
sprite_status_thanks* pribuf1[64];
sprite_status_thanks* pribuf0[64];
sprite_status_thanks actwk[66];
int ProcMode;
int DLLRetMode;
int* lpFadeFlag;
short FadeFlag;
int_union* lphscrollbuff;
palette_entry* lpcolorwk3;
palette_entry* lpcolorwk2;
palette_entry* lpcolorwk1;
palette_entry* lpcolorwk0;
bmp_info SprBmp[700];




























void WorkRamClear() { /* Line 98, Address: 0x1002e80 */
  FadeFlag = 0; /* Line 99, Address: 0x1002e88 */
  *lpFadeFlag = 0; /* Line 100, Address: 0x1002e90 */
  DLLRetMode = 0; /* Line 101, Address: 0x1002e9c */
  ProcMode = 0; /* Line 102, Address: 0x1002ea4 */

  sMemSet(actwk, 0, sizeof(actwk)); /* Line 104, Address: 0x1002eac */






  sMemSet(pribuf0, 0, sizeof(pribuf0)); /* Line 111, Address: 0x1002ecc */
  sMemSet(pribuf1, 0, sizeof(pribuf1)); /* Line 112, Address: 0x1002eec */
  sMemSet(pribuf2, 0, sizeof(pribuf2)); /* Line 113, Address: 0x1002f0c */
  sMemSet(pribuf3, 0, sizeof(pribuf3)); /* Line 114, Address: 0x1002f2c */


  priptr[0] = 0; /* Line 117, Address: 0x1002f4c */
  priptr[1] = 0; /* Line 118, Address: 0x1002f54 */
  priptr[2] = 0; /* Line 119, Address: 0x1002f5c */
  priptr[3] = 0; /* Line 120, Address: 0x1002f64 */

  quit_flg = 0; /* Line 122, Address: 0x1002f6c */
  push_flg = 0; /* Line 123, Address: 0x1002f74 */
  int_flg = 0; /* Line 124, Address: 0x1002f7c */
  colorflg = 0; /* Line 125, Address: 0x1002f84 */
  colorno = 0; /* Line 126, Address: 0x1002f8c */
  coltimer = 0; /* Line 127, Address: 0x1002f94 */

  linkdata = 0; /* Line 129, Address: 0x1002f9c */
  intmode = 0; /* Line 130, Address: 0x1002fa4 */
  gmtime0 = 0; /* Line 131, Address: 0x1002fac */
  gmtime1 = 0; /* Line 132, Address: 0x1002fb4 */
  sr_save = 0; /* Line 133, Address: 0x1002fbc */
  ranum = 0; /* Line 134, Address: 0x1002fc4 */
  overint = 0; /* Line 135, Address: 0x1002fcc */

  startcolor = 0; /* Line 137, Address: 0x1002fd4 */
  colorcnt = 0; /* Line 138, Address: 0x1002fdc */

  prg_mode = 0; /* Line 140, Address: 0x1002fe4 */

  wkarea1 = 0; /* Line 142, Address: 0x1002fec */
  wkarea2 = 0; /* Line 143, Address: 0x1002ff4 */
  wkarea3 = 0; /* Line 144, Address: 0x1002ffc */

  sMemSet(actset_tm, 0, sizeof(actset_tm)); /* Line 146, Address: 0x1003004 */

  colorno2 = 0; /* Line 148, Address: 0x1003024 */
  coltimer2 = 0; /* Line 149, Address: 0x100302c */

  posetimer = 0; /* Line 151, Address: 0x1003034 */
  poseno = 0; /* Line 152, Address: 0x100303c */
  animal_flg = 0; /* Line 153, Address: 0x1003044 */
  animal_timer = 0; /* Line 154, Address: 0x100304c */
  heart_tm = 0; /* Line 155, Address: 0x1003054 */

  end_timer = 0; /* Line 157, Address: 0x100305c */


  comflag_m = 0; /* Line 160, Address: 0x1003064 */
  comflag_s = 0; /* Line 161, Address: 0x100306c */

  comdata_m0 = 0; /* Line 163, Address: 0x1003074 */
  comdata_m1 = 0; /* Line 164, Address: 0x100307c */
  comdata_m2 = 0; /* Line 165, Address: 0x1003084 */
  comdata_m3 = 0; /* Line 166, Address: 0x100308c */
  comdata_m4 = 0; /* Line 167, Address: 0x1003094 */
  comdata_m5 = 0; /* Line 168, Address: 0x100309c */
  comdata_m6 = 0; /* Line 169, Address: 0x10030a4 */
  comdata_m7 = 0; /* Line 170, Address: 0x10030ac */
  swdata1.w = 0; /* Line 171, Address: 0x10030b4 */
  swdata2.w = 0; /* Line 172, Address: 0x10030bc */
  comdata_s0 = 0; /* Line 173, Address: 0x10030c4 */
  comdata_s1 = 0; /* Line 174, Address: 0x10030cc */
  comdata_s2 = 0; /* Line 175, Address: 0x10030d4 */
  comdata_s3 = 0; /* Line 176, Address: 0x10030dc */
  comdata_s4 = 0; /* Line 177, Address: 0x10030e4 */
  comdata_s5 = 0; /* Line 178, Address: 0x10030ec */
  comdata_s6 = 0; /* Line 179, Address: 0x10030f4 */
  comdata_s7 = 0; /* Line 180, Address: 0x10030fc */
} /* Line 181, Address: 0x1003104 */
