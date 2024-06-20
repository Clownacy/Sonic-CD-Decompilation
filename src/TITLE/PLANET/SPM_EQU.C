#include "..\..\TYPES.H"
#include "LPL_TYPES.H"

unsigned short comdata_s7;
unsigned short comdata_s6;
unsigned short comdata_s5;
unsigned short comdata_s4;
unsigned short comdata_s3;
unsigned short comdata_s2;
unsigned short comdata_s1;
unsigned short comdata_s0;
ushort_union swdata2;
ushort_union swdata1;
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
unsigned char cgchg_end;
unsigned char cgchg_timer;
unsigned char flash_flg;
unsigned char colorcnt;
unsigned char startcolor;
short lplanet_no;
short flash_timer;
int overint;
int ranum;
short sr_save;
short gmtime1;
short gmtime0;
short intmode;
short linkdata;
unsigned char colorflg;
unsigned char int_flg;
unsigned char push_flg;
unsigned char actset_wk;
unsigned char actset_flg;
extern void(*sMemSet)(void*, unsigned char, int);
short actset_tm[6] =
{
  -31312, 256,
  -31168, 256,
  -29568, 256
};
short spr_colno;
short spr_coltimer;
short main_lpcnt;
short funka_patno;
short funka_pctimer;
short colorno;
unsigned short coltimer;
sprite_status_lpl actwk[18];
int ProcMode;
int DLLRetMode;
int* lpFadeFlag;
short tv_adr[896];
wordram_info wordram;
int_union* lphscrollbuff;
PALETTEENTRY* lpcolorwk3;
PALETTEENTRY* lpcolorwk2;
PALETTEENTRY* lpcolorwk1;
PALETTEENTRY* lpcolorwk0;
short_union stageno;
unsigned char music_selflg;
unsigned char m2save[22528];
bmp_info SprBmp[700];

















void WorkRamClear() { /* Line 89, Address: 0x1008d10 */
  *lpFadeFlag = 0; /* Line 90, Address: 0x1008d18 */
  DLLRetMode = 0; /* Line 91, Address: 0x1008d24 */
  ProcMode = 0; /* Line 92, Address: 0x1008d2c */

  sMemSet(actwk, 0, sizeof(actwk)); /* Line 94, Address: 0x1008d34 */

  coltimer = 0; /* Line 96, Address: 0x1008d54 */
  colorno = 0; /* Line 97, Address: 0x1008d5c */
  funka_pctimer = 0; /* Line 98, Address: 0x1008d64 */
  funka_patno = 0; /* Line 99, Address: 0x1008d6c */
  main_lpcnt = 0; /* Line 100, Address: 0x1008d74 */
  spr_coltimer = 0; /* Line 101, Address: 0x1008d7c */
  spr_colno = 0; /* Line 102, Address: 0x1008d84 */



  sMemSet(actset_tm, 0, 6); /* Line 106, Address: 0x1008d8c */
  actset_flg = 0; /* Line 107, Address: 0x1008dac */
  actset_wk = 0; /* Line 108, Address: 0x1008db4 */
  push_flg = 0; /* Line 109, Address: 0x1008dbc */
  int_flg = 0; /* Line 110, Address: 0x1008dc4 */
  colorflg = 0; /* Line 111, Address: 0x1008dcc */

  linkdata = 0; /* Line 113, Address: 0x1008dd4 */
  intmode = 0; /* Line 114, Address: 0x1008ddc */
  gmtime0 = 0; /* Line 115, Address: 0x1008de4 */
  gmtime1 = 0; /* Line 116, Address: 0x1008dec */
  sr_save = 0; /* Line 117, Address: 0x1008df4 */

  ranum = 0; /* Line 119, Address: 0x1008dfc */
  overint = 0; /* Line 120, Address: 0x1008e04 */

  flash_timer = 0; /* Line 122, Address: 0x1008e0c */
  lplanet_no = 0; /* Line 123, Address: 0x1008e14 */
  startcolor = 0; /* Line 124, Address: 0x1008e1c */
  colorcnt = 0; /* Line 125, Address: 0x1008e24 */
  flash_flg = 0; /* Line 126, Address: 0x1008e2c */
  cgchg_timer = 0; /* Line 127, Address: 0x1008e34 */
  cgchg_end = 0; /* Line 128, Address: 0x1008e3c */


  comflag_m = 0; /* Line 131, Address: 0x1008e44 */
  comflag_s = 0; /* Line 132, Address: 0x1008e4c */

  comdata_m0 = 0; /* Line 134, Address: 0x1008e54 */
  comdata_m1 = 0; /* Line 135, Address: 0x1008e5c */
  comdata_m2 = 0; /* Line 136, Address: 0x1008e64 */
  comdata_m3 = 0; /* Line 137, Address: 0x1008e6c */
  comdata_m4 = 0; /* Line 138, Address: 0x1008e74 */
  comdata_m5 = 0; /* Line 139, Address: 0x1008e7c */
  comdata_m6 = 0; /* Line 140, Address: 0x1008e84 */
  comdata_m7 = 0; /* Line 141, Address: 0x1008e8c */
  swdata1.w = 0; /* Line 142, Address: 0x1008e94 */
  swdata2.w = 0; /* Line 143, Address: 0x1008e9c */
  comdata_s0 = 0; /* Line 144, Address: 0x1008ea4 */
  comdata_s1 = 0; /* Line 145, Address: 0x1008eac */
  comdata_s2 = 0; /* Line 146, Address: 0x1008eb4 */
  comdata_s3 = 0; /* Line 147, Address: 0x1008ebc */
  comdata_s4 = 0; /* Line 148, Address: 0x1008ec4 */
  comdata_s5 = 0; /* Line 149, Address: 0x1008ecc */
  comdata_s6 = 0; /* Line 150, Address: 0x1008ed4 */
  comdata_s7 = 0; /* Line 151, Address: 0x1008edc */
} /* Line 152, Address: 0x1008ee4 */
