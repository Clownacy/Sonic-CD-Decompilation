#include "..\TYPES.H"
#include "COMMON.H"
#include "SPM_EQU.H"
#include "SPS_EQU.H"
#include "GAME.H"
#include "ACT_S.H"
#include "BACT.H"
#include "COLI_S.H"
#include "ENS.H"
#include "ETC_M.H"
#include "ETC_S.H"
#include "FADEIN.H"
#include "KAITEN.H"

int time_bonus;
int ring_bonus;
unsigned char seregiflg;
unsigned char scroll_stop;
static unsigned short hscrcnt = 256;
static unsigned int PauseIcon;
game_info* lpKeepWork;
extern bmp_info SprBmp[700];
void(*sCloseFile)(int);
int(*sReadFile)(int, void*, int);
int(*sOpenFile)(char*);
void(*sPrintf)(char*, const char*, ...);
short plring_dmy;
int* lpFadeFlag;
palette_entry* lpcolorwk4;
palette_entry* lpcolorwk3;
palette_entry* lpcolorwk2;
palette_entry* lpcolorwk;
unsigned short* pmapwk;
void(*sOutputDebugString)(char*);
int(*sRandom)();
void(*sMemCpy)(void*, void*, int);
void(*sMemSet)(void*, unsigned char, int);
void(*WaveAllStop)();
void(*CDPause)(short);
void(*CDPlay)(short);
void(*WaveRequest)(short);
void(*ClrSpriteDebug)();
void(*EAsprset)(short, short, unsigned short, unsigned short, unsigned short);
int(*SetGrid)(int, int, int, int, int);
int_union vscroll;
int_union scra_h_posiw;
int_union scrb_h_posiw;
static int scoreup_setm;
ushort_union swdata2;
static short clchgcnt[4];
dlink_export ExportedFunctions = {
  &game_init,
  (void (*)())&game,
  &DLL_meminit,
  &DLL_memfree,
  (void (*)(short, short))&SWdataSet,
  &Get_vscroll,
  &Get_scra_h_posiw,
  &Get_scrb_h_posiw,
  &FadeProc,
  0,
  0,
  &Special_block_chg
};
int_union scrb_v_posiw;
int_union scra_v_posiw;
int_union hscroll;
int_union* lphscrollbuff;
int(*sGetFileSize)(int);

































































void SetUseOk(short unknown1, short unknown2, short unknown3) { /* Line 135, Address: 0x1005100 */
} /* Line 136, Address: 0x1005104 */








static palette_entry colortbl[64] = {
  {  64,  96, 224, 1 }, {   0,   0,   0, 1 }, {   0,  32, 128, 1 }, {  32,  64, 192, 1 },
  {  32,  96, 224, 1 }, {  64, 160, 224, 1 }, { 224, 224, 224, 1 }, { 160, 160, 160, 1 },
  { 128, 128, 128, 1 }, {  64,  64,  64, 1 }, { 224, 160, 128, 1 }, { 160,  96,  64, 1 },
  { 224,   0,   0, 1 }, { 128,   0,   0, 1 }, {  64,   0,   0, 1 }, { 224, 224,   0, 1 },
  {   0,   0,   0, 1 }, { 224, 224, 224, 1 }, { 128, 128, 128, 1 }, {  64,  64,  64, 1 },
  {   0,   0,   0, 1 }, { 224, 224,   0, 1 }, { 192,  32,   0, 1 }, { 224, 192, 128, 1 },
  { 192, 160,  96, 1 }, { 160, 224,   0, 1 }, {  96, 160,   0, 1 }, {  32,  96,   0, 1 },
  { 192, 224, 224, 1 }, { 128, 192, 224, 1 }, {  64, 160, 224, 1 }, {  64,  96, 224, 1 },
  {   0,   0,   0, 1 }, {   0,   0,   0, 1 }, {   0,   0,  32, 1 }, {   0,   0,  64, 1 },
  {   0,   0,  96, 1 }, {   0,   0, 160, 1 }, {   0,   0, 224, 1 }, {   0,  64, 224, 1 },
  {   0,  96, 224, 1 }, {   0, 128, 224, 1 }, {  32, 160, 224, 1 }, {  64, 192, 224, 1 },
  { 128, 224, 224, 1 }, { 192, 224, 224, 1 }, { 224, 224, 224, 1 }, {   0,   0,   0, 1 },
  {   0,   0,   0, 1 }, {   0,   0,   0, 1 }, {  64,  32, 128, 1 }, {  96,  64, 192, 1 },
  { 128,  96, 224, 1 }, { 160, 128, 224, 1 }, { 224, 224, 224, 1 }, { 128, 192, 192, 1 },
  {  96, 160, 128, 1 }, {  32,  64,  96, 1 }, {   0,   0,   0, 1 }, { 224, 224, 224, 1 },
  { 224, 224,   0, 1 }, { 128, 128,   0, 1 }, {  64,  64,   0, 1 }, {   0,   0,   0, 1 },
};
static palette_entry dispcolor[64] = {
  { 224, 224, 224, 1 }, {   0,   0,   0, 1 }, { 224, 224, 224, 1 }, { 128, 224,   0, 1 },
  {  64, 160,   0, 1 }, {  32,  96,   0, 1 }, { 224,   0,   0, 1 }, { 128,   0,   0, 1 },
  {   0,   0,   0, 1 }, {   0,   0,   0, 1 }, {  64,   0,  32, 1 }, { 224, 224,  32, 1 },
  { 128, 128,   0, 1 }, {  64,  32,   0, 1 }, {   0,   0,   0, 1 }, {   0,   0,   0, 1 },
  { 224, 224, 224, 1 }, {   0,   0,   0, 1 }, { 224, 224, 224, 1 }, {  96,  96, 224, 1 },
  {  64,  64, 224, 1 }, {  32,  32, 192, 1 }, {  64, 224, 128, 1 }, {   0, 160, 160, 1 },
  {   0,  64,  96, 1 }, { 224,  32, 224, 1 }, { 160,   0, 224, 1 }, { 128,   0, 160, 1 },
  { 224,  96,   0, 1 }, { 224,  64,   0, 1 }, { 128,   0,   0, 1 }, {   0,   0,   0, 1 },
  { 224, 224, 224, 1 }, { 160, 224, 224, 1 }, {   0, 224, 160, 1 }, {   0, 128, 192, 1 },
  {   0,   0, 224, 1 }, { 192,  96, 224, 1 }, {  32,   0, 128, 1 }, {   0,   0,   0, 1 },
  {   0,   0,   0, 1 }, {   0,   0,   0, 1 }, {   0,   0,   0, 1 }, {   0,   0,   0, 1 },
  {   0,   0,   0, 1 }, {   0,   0,   0, 1 }, {   0,   0,   0, 1 }, {   0,   0,   0, 1 },
  { 224, 224, 224, 1 }, {   0,   0,   0, 1 }, {  32,  32, 192, 1 }, {  96,  96, 224, 1 },
  { 128, 128, 224, 1 }, { 224, 224, 224, 1 }, { 128, 128, 128, 1 }, {  64,  64,  64, 1 },
  { 224, 160, 128, 1 }, { 160,  96,  64, 1 }, { 224,   0,   0, 1 }, { 128,   0,   0, 1 },
  { 192, 224, 224, 1 }, { 160, 224, 224, 1 }, { 128, 224, 224, 1 }, {  64, 224, 224, 1 },
};
static palette_entry coltbl0[32] = {
  {   0,   0,   0, 1 }, { 224, 224, 224, 1 }, { 224, 224,   0, 1 }, { 224, 128,   0, 1 },
  { 224,  32,   0, 1 }, { 160, 160, 128, 1 }, { 128, 128,  64, 1 }, {  64,  64,  32, 1 },
  {   0,   0,   0, 1 }, {   0,   0, 224, 1 }, {  96, 192, 224, 1 }, {  64, 128, 224, 1 },
  {  32,  96, 224, 1 }, {  64, 128,  32, 1 }, {  32,  96,   0, 1 }, {   0,  64,   0, 1 },
  {   0,   0,   0, 1 }, {   0,   0,  32, 1 }, {   0,   0,  64, 1 }, {   0,   0,  96, 1 },
  {   0,   0, 128, 1 }, {   0,   0, 160, 1 }, {   0,   0, 192, 1 }, {   0,   0, 224, 1 },
  {   0,   0,   0, 1 }, {   0,   0,   0, 1 }, {   0,   0,   0, 1 }, {   0,   0,   0, 1 },
  {   0,   0,   0, 1 }, {   0,   0,   0, 1 }, {   0,   0,   0, 1 }, {   0,   0,   0, 1 },
};
static palette_entry coltbl1[32] = {
  {   0,   0, 224, 1 }, { 224, 224, 224, 1 }, { 224, 224,   0, 1 }, { 224, 128,   0, 1 },
  { 224,  32,   0, 1 }, { 160, 160, 160, 1 }, {  96,  96,  96, 1 }, {  64,  64,  64, 1 },
  {   0,   0,   0, 1 }, {   0,   0,  96, 1 }, {   0,   0, 224, 1 }, {   0,  96, 224, 1 },
  {  96, 160, 224, 1 }, { 160, 192, 224, 1 }, {   0, 224,   0, 1 }, { 240, 240, 240, 1 },
  {  64,  96, 224, 1 }, { 224, 224, 224, 1 }, { 192, 224, 224, 1 }, { 160, 192, 224, 1 },
  { 128, 160, 224, 1 }, {  96, 128, 224, 1 }, {   0,  32, 224, 1 }, { 128, 128, 160, 1 },
  {   0,   0, 224, 1 }, { 160,  96,  64, 1 }, { 192, 128,  96, 1 }, { 224, 192, 128, 1 },
  { 224, 224, 160, 1 }, { 160,  64,   0, 1 }, {  96,  64,   0, 1 }, {   0,   0,   0, 1 },
};
static palette_entry coltbl2[32] = {
  {   0,   0, 224, 1 }, { 224, 224, 224, 1 }, { 224, 224,   0, 1 }, { 224, 128,   0, 1 },
  { 224,  32,   0, 1 }, { 128, 160, 160, 1 }, {  64,  96,  96, 1 }, {  32,  64,  64, 1 },
  {   0,   0,   0, 1 }, {  32, 128,   0, 1 }, {   0,   0, 224, 1 }, {  32,  64, 224, 1 },
  {  64, 128, 224, 1 }, {  64, 192, 224, 1 }, {  64, 224,   0, 1 }, {   0,  64,   0, 1 },
  {   0,   0, 224, 1 }, { 224, 224, 224, 1 }, {   0,  32, 224, 1 }, {   0,  64, 224, 1 },
  {  32,  96, 224, 1 }, {  64, 128, 224, 1 }, {   0,   0, 160, 1 }, {   0,   0, 128, 1 },
  { 192, 224, 224, 1 }, {   0,   0,  32, 1 }, {  32, 224, 224, 1 }, {  96, 160, 128, 1 },
  {  64, 128,  96, 1 }, {   0,  64,  64, 1 }, { 224,  32, 128, 1 }, { 224, 224,  64, 1 },
};
static palette_entry coltbl3[32] = {
  {   0,  32, 224, 1 }, { 224, 224, 224, 1 }, { 224, 224,   0, 1 }, { 224, 128,   0, 1 },
  { 224,  32,   0, 1 }, { 224, 192, 160, 1 }, { 160, 128,  96, 1 }, { 128,  96,  32, 1 },
  {   0,   0,   0, 1 }, {  32, 128,   0, 1 }, {   0,  32, 224, 1 }, {  32,  64, 224, 1 },
  {  64, 128, 224, 1 }, {  64, 192, 224, 1 }, {  64, 224,   0, 1 }, {   0,  64,   0, 1 },
  {   0,  32, 224, 1 }, {   0,   0,   0, 1 }, { 224, 224, 224, 1 }, { 224, 224, 128, 1 },
  { 224, 160,  64, 1 }, { 192, 128,  64, 1 }, { 128,  96,  64, 1 }, {  64,  32,  64, 1 },
  {  96, 192, 224, 1 }, {  64, 192, 192, 1 }, {  96,  96,  96, 1 }, {   0,  32,   0, 1 },
  {  32,  64,   0, 1 }, {  64, 128,   0, 1 }, {  96, 160,  32, 1 }, { 160, 160, 160, 1 },
};
static palette_entry coltbl4[32] = {
  {   0,   0,   0, 1 }, { 224, 224, 224, 1 }, { 224, 224,   0, 1 }, { 224, 128,   0, 1 },
  { 224,  32,  32, 1 }, { 128, 128, 128, 1 }, {  96,  96,  96, 1 }, {  64,  64,  64, 1 },
  {   0,   0,   0, 1 }, {   0, 224,   0, 1 }, {   0,  32, 224, 1 }, {  32,   0,   0, 1 },
  {  96,   0,   0, 1 }, { 160,   0,   0, 1 }, { 160,  96,   0, 1 }, {  96,  32,   0, 1 },
  {   0,   0,   0, 1 }, {   0,   0,   0, 1 }, { 224, 224, 224, 1 }, { 224, 224,   0, 1 },
  { 128, 192,   0, 1 }, {  64, 160,   0, 1 }, {  32,  96,   0, 1 }, {   0,  64,   0, 1 },
  {   0,   0,  64, 1 }, {   0,   0, 128, 1 }, {   0,  32, 192, 1 }, {   0,  64, 224, 1 },
  {   0, 160, 224, 1 }, { 224, 224,   0, 1 }, {   0, 224, 224, 1 }, { 224,   0,   0, 1 },
};
static palette_entry coltbl5[32] = {
  {  96,   0,  64, 1 }, { 224, 224, 224, 1 }, { 224, 224,   0, 1 }, { 224, 128,   0, 1 },
  { 224,  32,   0, 1 }, { 128, 128, 160, 1 }, {  96,  96, 128, 1 }, {  64,  64,  96, 1 },
  {   0,   0,   0, 1 }, {  32,  64,   0, 1 }, {  64, 128,   0, 1 }, { 128, 160,   0, 1 },
  {  64, 224,   0, 1 }, {   0,   0, 224, 1 }, {  64,   0,  32, 1 }, { 160, 160, 192, 1 },
  {  96,   0,  64, 1 }, { 224,  64,   0, 1 }, { 224, 128,   0, 1 }, { 224, 192,   0, 1 },
  { 160, 224,  64, 1 }, { 128, 224, 128, 1 }, {  64, 224, 192, 1 }, {  64, 160, 224, 1 },
  { 128,  96, 224, 1 }, { 160,   0, 224, 1 }, { 224,  32, 224, 1 }, { 224,   0, 160, 1 },
  { 224,   0,  96, 1 }, { 224,   0,  32, 1 }, { 192,  64, 128, 1 }, { 224, 160, 224, 1 },
};
static palette_entry coltbl6[32] = {
  {   0,  64,   0, 1 }, { 224, 224, 224, 1 }, { 224, 224,   0, 1 }, { 224, 128,   0, 1 },
  { 224,  32,   0, 1 }, {  96, 128, 128, 1 }, {  64,  96,  96, 1 }, {  32,  64,  64, 1 },
  {   0,   0,   0, 1 }, { 160, 224,   0, 1 }, {  96, 192,   0, 1 }, {  32, 128,   0, 1 },
  {   0,  96,   0, 1 }, { 128, 160, 160, 1 }, {   0,  64,  32, 1 }, {   0,  32, 192, 1 },
  {   0,  64,   0, 1 }, {   0,   0,   0, 1 }, {  32,  32,  32, 1 }, {   0, 192, 224, 1 },
  { 224, 224, 224, 1 }, { 224, 128, 224, 1 }, { 224,  64, 160, 1 }, { 160, 224,   0, 1 },
  { 224,   0,  64, 1 }, { 224, 192,  96, 1 }, {  32,  64,   0, 1 }, {  64, 128,   0, 1 },
  { 128, 160,   0, 1 }, { 224, 160,  32, 1 }, { 192, 128,   0, 1 }, { 128,  64,   0, 1 },
};
static palette_entry coltbl7[32] = {
  {   0,   0,   0, 1 }, { 224, 224, 224, 1 }, { 224, 224,   0, 1 }, { 224, 128,   0, 1 },
  { 224,  32,   0, 1 }, { 160, 160, 128, 1 }, { 128, 128,  64, 1 }, {  64,  64,  32, 1 },
  {   0,   0,   0, 1 }, {   0,   0, 224, 1 }, {  96, 192, 224, 1 }, {  64, 128, 224, 1 },
  {  32,  96, 224, 1 }, {  64, 128,  32, 1 }, {  32,  96,   0, 1 }, {   0,  64,   0, 1 },
  {   0,   0,   0, 1 }, {   0,   0,   0, 1 }, { 224, 224, 224, 1 }, { 224, 224, 160, 1 },
  { 224, 192, 128, 1 }, { 224, 160, 128, 1 }, { 192, 128, 128, 1 }, { 224,  96, 160, 1 },
  {   0,   0, 192, 1 }, { 224, 224,   0, 1 }, {  96,  96,  96, 1 }, {  64,  32,   0, 1 },
  {  96,  32,   0, 1 }, { 128,  64,  32, 1 }, {  64,  96, 224, 1 }, {   0, 224, 224, 1 },
};
static unsigned char cltbl[1008] = {
  0, 32, 64, 96, 128, 160, 192, 224, 0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 32, 64, 96, 128, 160, 192, 0, 0, 0, 0, 0, 0, 0, 32,
  0, 0, 0, 32, 64, 96, 128, 160, 0, 0, 0, 0, 0, 0, 32, 64,
  0, 0, 0, 0, 32, 64, 96, 128, 0, 0, 0, 0, 0, 32, 64, 96,
  0, 0, 0, 0, 0, 32, 64, 96, 0, 0, 0, 0, 32, 64, 96, 128,
  0, 0, 0, 0, 0, 0, 32, 64, 0, 0, 0, 32, 64, 96, 128, 160,
  0, 0, 0, 0, 0, 0, 0, 32, 0, 0, 32, 64, 96, 128, 160, 192,
  0, 0, 0, 0, 0, 0, 0, 0, 0, 32, 64, 96, 128, 160, 192, 224,
  0, 0, 0, 0, 0, 0, 0, 0, 32, 64, 96, 128, 160, 192, 224, 192,
  0, 32, 0, 0, 0, 0, 0, 0, 64, 96, 128, 160, 192, 224, 192, 160,
  0, 64, 32, 0, 0, 0, 0, 0, 96, 128, 160, 192, 224, 192, 160, 128,
  0, 96, 64, 32, 0, 0, 0, 0, 128, 160, 192, 224, 192, 160, 128, 96,
  0, 128, 96, 64, 32, 0, 0, 0, 160, 192, 224, 192, 160, 128, 96, 64,
  0, 160, 128, 96, 64, 32, 0, 0, 192, 224, 192, 160, 128, 96, 64, 32,
  0, 192, 160, 128, 96, 64, 32, 0, 224, 192, 160, 128, 96, 64, 32, 0,
  0, 224, 192, 160, 128, 96, 64, 32, 192, 160, 128, 96, 64, 32, 0, 0,
  0, 192, 224, 192, 160, 128, 96, 64, 160, 128, 96, 64, 32, 0, 0, 0,
  0, 160, 192, 224, 192, 160, 128, 96, 128, 96, 64, 32, 0, 0, 0, 0,
  0, 128, 160, 192, 224, 192, 160, 128, 96, 64, 32, 0, 0, 0, 0, 0,
  0, 96, 128, 160, 192, 224, 192, 160, 64, 32, 0, 0, 0, 0, 0, 0,
  0, 64, 96, 128, 160, 192, 224, 192, 32, 0, 0, 0, 0, 0, 0, 0,
  0, 32, 64, 96, 128, 160, 192, 224, 0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 32, 64, 96, 128, 160, 192, 0, 0, 0, 0, 0, 0, 0, 2,
  0, 0, 0, 32, 64, 96, 128, 160, 0, 0, 0, 0, 0, 0, 2, 4,
  0, 0, 0, 0, 32, 64, 96, 128, 0, 0, 0, 0, 0, 2, 4, 6,
  0, 0, 0, 0, 0, 32, 64, 96, 0, 0, 0, 0, 2, 4, 6, 8,
  0, 0, 0, 0, 0, 0, 32, 64, 0, 0, 0, 2, 4, 6, 8, 10,
  0, 0, 0, 0, 0, 0, 0, 32, 0, 0, 2, 4, 6, 8, 10, 12,
  0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 4, 6, 8, 10, 12, 14,
  0, 0, 0, 0, 0, 0, 0, 0, 2, 4, 6, 8, 10, 12, 14, 12,
  0, 2, 0, 0, 0, 0, 0, 0, 4, 6, 8, 10, 12, 14, 12, 10,
  0, 4, 2, 0, 0, 0, 0, 0, 6, 8, 10, 12, 14, 12, 10, 8,
  0, 6, 4, 2, 0, 0, 0, 0, 8, 10, 12, 14, 12, 10, 8, 6,
  0, 8, 6, 4, 2, 0, 0, 0, 10, 12, 14, 12, 10, 8, 6, 4,
  0, 10, 8, 6, 4, 2, 0, 0, 12, 14, 12, 10, 8, 6, 4, 2,
  0, 12, 10, 8, 6, 4, 2, 0, 14, 12, 10, 8, 6, 4, 2, 0,
  0, 14, 12, 10, 8, 6, 4, 2, 12, 10, 8, 6, 4, 2, 0, 0,
  0, 12, 14, 12, 10, 8, 6, 4, 10, 8, 6, 4, 2, 0, 0, 0,
  0, 10, 12, 14, 12, 10, 8, 6, 8, 6, 4, 2, 0, 0, 0, 0,
  0, 8, 10, 12, 14, 12, 10, 8, 6, 4, 2, 0, 0, 0, 0, 0,
  0, 6, 8, 10, 12, 14, 12, 10, 4, 2, 0, 0, 0, 0, 0, 0,
  0, 4, 6, 8, 10, 12, 14, 12, 2, 0, 0, 0, 0, 0, 0, 0,
  0, 2, 4, 6, 8, 10, 12, 14, 0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 2, 4, 6, 8, 10, 12, 0, 0, 0, 0, 0, 0, 0, 32,
  0, 0, 0, 2, 4, 6, 8, 10, 0, 0, 0, 0, 0, 0, 32, 64,
  0, 0, 0, 0, 2, 4, 6, 8, 0, 0, 0, 0, 0, 32, 64, 96,
  0, 0, 0, 0, 0, 2, 4, 6, 0, 0, 0, 0, 32, 64, 96, 128,
  0, 0, 0, 0, 0, 0, 2, 4, 0, 0, 0, 32, 64, 96, 128, 160,
  0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 32, 64, 96, 128, 160, 192,
  0, 0, 0, 0, 0, 0, 0, 0, 0, 32, 64, 96, 128, 160, 192, 224,
  0, 0, 0, 0, 0, 0, 0, 0, 32, 64, 96, 128, 160, 192, 224, 192,
  0, 32, 0, 0, 0, 0, 0, 0, 64, 96, 128, 160, 192, 224, 192, 160,
  0, 64, 32, 0, 0, 0, 0, 0, 96, 128, 160, 192, 224, 192, 160, 128,
  0, 96, 64, 32, 0, 0, 0, 0, 128, 160, 192, 224, 192, 160, 128, 96,
  0, 128, 96, 64, 32, 0, 0, 0, 160, 192, 224, 192, 160, 128, 96, 64,
  0, 160, 128, 96, 64, 32, 0, 0, 192, 224, 192, 160, 128, 96, 64, 32,
  0, 192, 160, 128, 96, 64, 32, 0, 224, 192, 160, 128, 96, 64, 32, 0,
  0, 224, 192, 160, 128, 96, 64, 32, 192, 160, 128, 96, 64, 32, 0, 0,
  0, 192, 224, 192, 160, 128, 96, 64, 160, 128, 96, 64, 32, 0, 0, 0,
  0, 160, 192, 224, 192, 160, 128, 96, 128, 96, 64, 32, 0, 0, 0, 0,
  0, 128, 160, 192, 224, 192, 160, 128, 96, 64, 32, 0, 0, 0, 0, 0,
  0, 96, 128, 160, 192, 224, 192, 160, 64, 32, 0, 0, 0, 0, 0, 0,
  0, 64, 96, 128, 160, 192, 224, 192, 32, 0, 0, 0, 0, 0, 0, 0,
};
static int hdatatbl4[111] = { 249856, 253952, 258048, 262144, 262144, 266240, 266240, 270336, 274432, 274432, 278528, 282624, 282624, 286720, 286720, 290816, 290816, 294912, 299008, 299008, 303104, 303104, 307200, 307200, 311296, 311296, 315392, 315392, 319488, 319488, 323584, 323584, 323584, 327680, 327680, 331776, 331776, 335872, 335872, 335872, 339968, 339968, 344064, 344064, 344064, 348160, 348160, 348160, 352256, 352256, 352256, 356352, 356352, 356352, 360448, 360448, 360448, 364544, 364544, 364544, 364544, 368640, 368640, 368640, 368640, 372736, 372736, 372736, 372736, 376832, 376832, 376832, 376832, 376832, 380928, 380928, 380928, 380928, 380928, 380928, 385024, 385024, 385024, 385024, 385024, 385024, 385024, 389120, 389120, 389120, 389120, 389120, 389120, 389120, 389120, 389120, 389120, 393216, 393216, 393216, 393216, 393216, 393216, 393216, 393216, 393216, 393216, 393216, 393216, 393216, 393216 };
static char hdatatbl5[128] = { 0, -5, -10, -15, -20, -25, -30, -35, -40, -44, -48, -52, -56, -60, -64, -67, -70, -73, -76, -78, -80, -82, -84, -86, -88, -90, -92, -93, -94, -93, -92, -90, -88, -85, -82, -80, -78, -71, -64, -56, -48, -32, -16, 0, 16, 21, 26, 30, 34, 35, 36, 37, 38, 37, 36, 34, 32, 28, 24, 20, 16, 10, 5, 0, -4, -9, -13, -18, -22, -24, -26, -28, -30, -31, -32, -33, -34, -33, -32, -31, -30, -28, -27, -25, -24, -20, -16, -12, -8, 0, 8, 15, 22, 30, 38, 47, 56, 64, 72, 80, 88, 94, 100, 106, 112, 115, 118, 120, 122, 123, 124, 125, 126, 125, 124, 122, 120, 114, 108, 102, 96, 86, 76, 66, 56, 42, 28, 14 };
static unsigned short mp01[4] = { 1, 2, 3, 4 };
static unsigned short mp02[4] = { 5, 6, 7, 8 };
static unsigned short mp03[4] = { 9, 10, 11, 12 };
static unsigned short mp04[4] = { 8201, 8202, 8203, 8204 };
static unsigned short mp05[4] = { 8205, 8206, 8207, 8208 };
static unsigned short mp06[4] = { 8209, 8210, 8211, 8212 };
static unsigned short mp07[4] = { 8213, 8214, 8215, 8216 };
static unsigned short mp08[10] = { 16409, 16410, 16411, 16412, 16413, 16414, 16414, 16414, 16415, 16416 };
static unsigned short mp09[8] = { 16423, 16424, 16425, 16426, 16415, 16427, 16428, 16414 };
static unsigned short mp10[8] = { 16417, 16418, 16419, 16413, 16420, 16421, 16422, 16416 };
static unsigned short mp11[12] = { 16423, 16411, 16525, 16526, 16527, 16528, 16529, 16414, 16530, 16531, 16532, 16533 };
static unsigned short mp14[30] = { 16413, 16534, 16535, 16536, 16537, 16538, 16539, 16540, 16541, 16542, 16543, 16544, 16545, 16546, 16547, 16416, 16548, 16549, 16550, 16551, 16552, 16553, 16554, 16555, 16556, 16557, 16558, 16556, 16559, 16553 };
static unsigned short mp21[46] = { 16444, 16445, 16446, 16447, 16448, 16449, 16450, 16451, 16452, 16453, 16454, 16455, 16384, 16384, 16384, 16456, 16457, 16458, 16459, 16460, 16461, 16462, 16463, 16464, 16465, 16466, 16467, 16468, 16469, 16470, 16471, 16472, 16473, 16474, 16475, 16476, 16384, 16384, 16477, 16478, 16479, 16480, 16481, 16482, 16483, 16484 };
static unsigned short mp22[42] = { 16485, 16486, 16487, 16488, 16489, 16462, 16463, 16384, 16384, 16444, 16445, 16490, 16491, 16492, 16493, 16494, 16495, 16448, 16449, 16444, 16445, 16496, 16497, 16498, 16499, 16500, 16483, 16484, 16384, 16384, 16464, 16465, 16501, 16502, 16503, 16504, 16505, 16506, 16468, 16469, 16464, 16465 };
static unsigned short mp23[52] = { 16507, 16508, 16458, 16459, 16490, 16509, 16384, 16384, 16490, 16509, 16510, 16511, 16448, 16449, 16512, 16513, 16384, 16384, 16453, 16454, 16455, 16384, 16514, 16384, 16514, 16514, 16515, 16516, 16479, 16480, 16501, 16517, 16384, 16384, 16501, 16517, 16518, 16519, 16468, 16469, 16520, 16521, 16384, 16384, 16473, 16474, 16475, 16476, 16522, 16523, 16524, 16524 };
bwrt_info bwrtTbl[16] = {
  { mp03, 1428, 2, 2 },
  { mp07, 1434, 2, 2 },
  { mp01, 1440, 2, 2 },
  { mp04, 1446, 2, 2 },
  { mp06, 1452, 2, 2 },
  { mp05, 1458, 2, 2 },
  { mp02, 1464, 2, 2 },
  { mp08, 1810, 5, 2 },
  { mp09, 2194, 4, 2 },
  { mp10, 2578, 4, 2 },
  { mp11, 2204, 6, 2 },
  { mp11, 2588, 6, 2 },
  { mp14, 2962, 15, 2 },
  { mp21, 914, 23, 2 },
  { mp22, 916, 21, 2 },
  { mp23, 910, 26, 2 }
};
static unsigned char stone_timer = 20;
static palette_entry stone_color_set_tbl[40] = {
  {   0,  64,   0, 1 }, { 224, 224, 224, 1 }, { 128, 224,   0, 1 }, {  64, 160,   0, 1 },
  {  32,  96,   0, 1 }, {   0,  64,   0, 1 }, { 224, 224, 224, 1 }, { 224,  96,   0, 1 },
  { 224,  64,   0, 1 }, { 128,   0,   0, 1 }, {   0,  64,   0, 1 }, { 224, 224, 224, 1 },
  { 224, 224,  32, 1 }, { 128, 128,   0, 1 }, {  64,  32,   0, 1 }, {   0,  64,   0, 1 },
  { 224, 224, 224, 1 }, {  96,  96, 224, 1 }, {  64,  64, 224, 1 }, {  32,  32, 192, 1 },
  {   0,  64,   0, 1 }, { 224, 224, 224, 1 }, {  64, 224, 128, 1 }, {   0, 160, 160, 1 },
  {   0,  64,  96, 1 }, {   0,  64,   0, 1 }, { 224, 224, 224, 1 }, { 128,   0, 224, 1 },
  {  64,   0, 128, 1 }, {  32,   0,  64, 1 }, {   0,  64,   0, 1 }, { 224, 224, 224, 1 },
  { 224,   0,   0, 1 }, { 128,   0,   0, 1 }, {  64,   0,  32, 1 }, {   0,  64,   0, 1 },
  { 224, 224, 224, 1 }, { 128, 224,   0, 1 }, {  64, 160,   0, 1 }, {  32,  96,   0, 1 },
};
static unsigned char hscrflg;
static unsigned short hscrcnt4;
static void(*hscrltbl[8])() = { &hscrl0, &hscrl1, &hscrl2, &hscrl3, &hscrl4, &hscrl5, &hscrl6, &hscrl7 };

void m2mainchk() {} /* Line 378, Address: 0x1005110 */



void m2subset() {} /* Line 382, Address: 0x1005120 */









void DLL_meminit(char*** pBufTbl, void** pFuncTbl) { /* Line 392, Address: 0x1005130 */
  unsigned int hf;
  char fn[80];



  SetGrid = *pFuncTbl++; /* Line 398, Address: 0x1005144 */
  EAsprset = *pFuncTbl++; /* Line 399, Address: 0x100515c */
  ClrSpriteDebug = *pFuncTbl++; /* Line 400, Address: 0x1005174 */
  WaveRequest = *pFuncTbl++; /* Line 401, Address: 0x100518c */
  CDPlay = *pFuncTbl++; /* Line 402, Address: 0x10051a4 */
  CDPause = *pFuncTbl++; /* Line 403, Address: 0x10051bc */
  ++pFuncTbl; /* Line 404, Address: 0x10051d4 */
  ++pFuncTbl; /* Line 405, Address: 0x10051e0 */
  ++pFuncTbl; /* Line 406, Address: 0x10051ec */
  ++pFuncTbl; /* Line 407, Address: 0x10051f8 */
  WaveAllStop = *pFuncTbl++; /* Line 408, Address: 0x1005204 */

  ++pFuncTbl; /* Line 410, Address: 0x100521c */
  ++pFuncTbl; /* Line 411, Address: 0x1005228 */
  sMemSet = *pFuncTbl++; /* Line 412, Address: 0x1005234 */
  sMemCpy = *pFuncTbl++; /* Line 413, Address: 0x100524c */
  ++pFuncTbl; /* Line 414, Address: 0x1005264 */
  sRandom = *pFuncTbl++; /* Line 415, Address: 0x1005270 */
  ++pFuncTbl; /* Line 416, Address: 0x1005288 */
  ++pFuncTbl; /* Line 417, Address: 0x1005294 */
  ++pFuncTbl; /* Line 418, Address: 0x10052a0 */
  sPrintf = *pFuncTbl++; /* Line 419, Address: 0x10052ac */
  sOutputDebugString = *pFuncTbl++; /* Line 420, Address: 0x10052c4 */
  sOpenFile = *pFuncTbl++; /* Line 421, Address: 0x10052dc */
  sReadFile = *pFuncTbl++; /* Line 422, Address: 0x10052f4 */
  sCloseFile = *pFuncTbl++; /* Line 423, Address: 0x100530c */
  ++pFuncTbl; /* Line 424, Address: 0x1005324 */





  pmapwk = (unsigned short*)**pBufTbl++; /* Line 430, Address: 0x1005330 */
  lpcolorwk = (palette_entry*)**pBufTbl++; /* Line 431, Address: 0x100534c */
  lpcolorwk2 = (palette_entry*)**pBufTbl++; /* Line 432, Address: 0x1005368 */
  lpcolorwk3 = (palette_entry*)**pBufTbl++; /* Line 433, Address: 0x1005384 */
  lpcolorwk4 = (palette_entry*)**pBufTbl++; /* Line 434, Address: 0x10053a0 */
  hdatabuf = (unsigned int*)**pBufTbl++; /* Line 435, Address: 0x10053bc */
  lpFadeFlag = (int*)*pBufTbl++; /* Line 436, Address: 0x10053d8 */
  lpKeepWork = (game_info*)*pBufTbl++; /* Line 437, Address: 0x10053f0 */

  plring_dmy = lpKeepWork->plring; /* Line 439, Address: 0x1005408 */
  stagenm = lpKeepWork->stagenm; /* Line 440, Address: 0x100541c */
  clrspflg = lpKeepWork->clrspflg_save; /* Line 441, Address: 0x1005430 */
  clrspflg_save = lpKeepWork->clrspflg_save; /* Line 442, Address: 0x1005444 */
  extra_score = lpKeepWork->extrascore; /* Line 443, Address: 0x1005458 */
  game_score = lpKeepWork->plscore; /* Line 444, Address: 0x100546c */
  pl_suu = lpKeepWork->pl_suu; /* Line 445, Address: 0x1005480 */

  spgmmode = 0; /* Line 447, Address: 0x1005494 */
  if (lpKeepWork->ta_flag) { /* Line 448, Address: 0x100549c */
    spgmmode |= 2; /* Line 449, Address: 0x10054b0 */
  }



  sPrintf(fn, "SPECIAL\\MAP\\SP%1dMAP.MAP", lpKeepWork->stagenm); /* Line 454, Address: 0x10054c4 */
  hf = sOpenFile(fn); /* Line 455, Address: 0x10054f0 */
  sReadFile(hf, sm_adr0, sizeof(sm_adr0)); /* Line 456, Address: 0x1005508 */
  sCloseFile(hf); /* Line 457, Address: 0x1005528 */

  lpKeepWork->sm_adr0 = sm_adr0; /* Line 459, Address: 0x100553c */
  lpKeepWork->pSprBmp = SprBmp; /* Line 460, Address: 0x1005550 */
  lpKeepWork->ptv_adr = (unsigned short*)tv_adr; /* Line 461, Address: 0x1005564 */

} /* Line 463, Address: 0x1005578 */



void DLL_memfree() {} /* Line 467, Address: 0x1005590 */


int Get_vscroll() {
  return vscroll.l; /* Line 471, Address: 0x10055a0 */
} /* Line 472, Address: 0x10055a8 */

int Get_scra_h_posiw() {
  return scra_h_posiw.l; /* Line 475, Address: 0x10055b0 */
} /* Line 476, Address: 0x10055b8 */

int Get_scrb_h_posiw() {
  return scrb_h_posiw.l; /* Line 479, Address: 0x10055c0 */
} /* Line 480, Address: 0x10055c8 */



int game() { /* Line 484, Address: 0x10055d0 */
  int i;

  if (lpKeepWork->SPEMode != 0 || spgmmode & 1) { /* Line 487, Address: 0x10055dc */
    SetUseOk(0, 103, 0); /* Line 488, Address: 0x1005608 */
    SetUseOk(0, 102, 0); /* Line 489, Address: 0x100561c */
  } else { /* Line 490, Address: 0x1005630 */
    SetUseOk(0, 103, 1); /* Line 491, Address: 0x1005638 */
    if (spgmmode & 2) /* Line 492, Address: 0x100564c */
      SetUseOk(0, 102, 1); /* Line 493, Address: 0x1005664 */
    else
      SetUseOk(0, 102, 0); /* Line 495, Address: 0x1005680 */
  }



  if (lpKeepWork->SPEMode != 0) { /* Line 500, Address: 0x1005694 */
    switch (lpKeepWork->SPEMode) { /* Line 501, Address: 0x10056a8 */
      case 1:
        lpKeepWork->SPEMode = 2; /* Line 503, Address: 0x10056ec */
        disp(); /* Line 504, Address: 0x10056fc */
        if (!(spgmmode & 2)) { /* Line 505, Address: 0x1005704 */
          sub_sync(107); /* Line 506, Address: 0x100571c */
        }
        return 0; /* Line 508, Address: 0x1005728 */
      case 2:
        for (i = 0; i < 3; ++i) { /* Line 510, Address: 0x1005734 */
          if (disp_main()) { /* Line 511, Address: 0x1005740 */

            lpKeepWork->extrascore = extra_score; /* Line 513, Address: 0x1005750 */
            lpKeepWork->plscore = game_score; /* Line 514, Address: 0x1005764 */
            lpKeepWork->pl_suu = pl_suu; /* Line 515, Address: 0x1005778 */
            lpKeepWork->SPEMode = 3; /* Line 516, Address: 0x100578c */
            break; /* Line 517, Address: 0x100579c */
          }
        } /* Line 519, Address: 0x10057a4 */
        game_score_disp(); /* Line 520, Address: 0x10057b4 */
        time_bonus_disp(); /* Line 521, Address: 0x10057bc */
        ring_bonus_disp(); /* Line 522, Address: 0x10057c4 */
        sonic_disp(); /* Line 523, Address: 0x10057cc */
        return 0; /* Line 524, Address: 0x10057d4 */
      case 3:
        lpKeepWork->SPEMode = 4; /* Line 526, Address: 0x10057e0 */
        CDPause(2); /* Line 527, Address: 0x10057f0 */
        return 3; /* Line 528, Address: 0x1005804 */
      case 5:
        lpKeepWork->SPEMode = 6; /* Line 530, Address: 0x1005810 */

        lpKeepWork->ta_time = (spe_time.l >> 16 & 255) * 60 * 60; /* Line 532, Address: 0x1005820 */
        lpKeepWork->ta_time += (spe_time.l >> 8 & 255) * 60; /* Line 533, Address: 0x1005854 */
        lpKeepWork->ta_time += spe_time.l & 255; /* Line 534, Address: 0x1005884 */
        CDPause(2); /* Line 535, Address: 0x10058a4 */
        return 4; /* Line 536, Address: 0x10058b8 */
      default:
        return 0; /* Line 538, Address: 0x10058c4 */
    }
  }


  if (spgmmode & 2) { /* Line 543, Address: 0x10058d0 */
    if ((swdata1.b.l & 112) == 112) { /* Line 544, Address: 0x10058e8 */

      lpKeepWork->ta_time = -1; /* Line 546, Address: 0x1005904 */
      CDPause(2); /* Line 547, Address: 0x1005914 */
      lpKeepWork->SPEMode = 6; /* Line 548, Address: 0x1005928 */
      SetUseOk(0, 102, 0); /* Line 549, Address: 0x1005938 */
      SetUseOk(0, 103, 0); /* Line 550, Address: 0x100594c */
      return 4; /* Line 551, Address: 0x1005960 */
    }
  }
  if (pause_chk()) return 0; /* Line 554, Address: 0x100596c */

  if (spgmmode & 1) { /* Line 556, Address: 0x1005988 */
    if (swdata1.b.h & 240) { /* Line 557, Address: 0x10059a0 */
      lpKeepWork->ta_time = -1; /* Line 558, Address: 0x10059b8 */
      CDPause(2); /* Line 559, Address: 0x10059c8 */
      lpKeepWork->SPEMode = 7; /* Line 560, Address: 0x10059dc */
      return 4; /* Line 561, Address: 0x10059ec */
    }
  }





  rlscrflg_save = rlscrflg; /* Line 569, Address: 0x10059f8 */
  rlscrflg = 0; /* Line 570, Address: 0x1005a08 */







  init_3dpara(); /* Line 578, Address: 0x1005a10 */
  kaiten(); /* Line 579, Address: 0x1005a18 */
  scalinit(); /* Line 580, Address: 0x1005a20 */
  action(); /* Line 581, Address: 0x1005a28 */
  if (lpKeepWork->SpecialTime == 0) /* Line 582, Address: 0x1005a30 */
    time_dec(); /* Line 583, Address: 0x1005a48 */
  if (ufochk() != 0 && spgmmode & 2) /* Line 584, Address: 0x1005a50 */
    pldeadflg = 1; /* Line 585, Address: 0x1005a78 */

  if (pldeadflg) { /* Line 587, Address: 0x1005a84 */
    clwout(); /* Line 588, Address: 0x1005a94 */
    game_over(); /* Line 589, Address: 0x1005a9c */
    if (spgmmode & 2) { /* Line 590, Address: 0x1005aa4 */
      lpKeepWork->SPEMode = 5; /* Line 591, Address: 0x1005abc */
      return 0; /* Line 592, Address: 0x1005acc */
    }
    lpKeepWork->SPEMode = 1; /* Line 594, Address: 0x1005ad8 */
    return 1; /* Line 595, Address: 0x1005ae8 */
  }

  if (gmclrflg) { /* Line 598, Address: 0x1005af4 */
    game_clear(); /* Line 599, Address: 0x1005b04 */
    clwout(); /* Line 600, Address: 0x1005b0c */
    lpKeepWork->SPEMode = 1; /* Line 601, Address: 0x1005b14 */
    return 0; /* Line 602, Address: 0x1005b24 */
  }
  hscal(); /* Line 604, Address: 0x1005b30 */
  intmode = 0; /* Line 605, Address: 0x1005b38 */
  ringno_disp(); /* Line 606, Address: 0x1005b40 */
  ufoleft_disp(); /* Line 607, Address: 0x1005b48 */
  stone_color_set(); /* Line 608, Address: 0x1005b50 */
  spetime_disp(); /* Line 609, Address: 0x1005b58 */
  color_change(); /* Line 610, Address: 0x1005b60 */

  return 0; /* Line 612, Address: 0x1005b68 */
} /* Line 613, Address: 0x1005b6c */


int ufochk() { /* Line 616, Address: 0x1005b80 */
  int i;

  for (i = 0; i < 6; ++i) { /* Line 619, Address: 0x1005b88 */
    if (actwk[i + 32].actno) return 0; /* Line 620, Address: 0x1005b94 */
  } /* Line 621, Address: 0x1005bc8 */
  return -1; /* Line 622, Address: 0x1005bd8 */
} /* Line 623, Address: 0x1005bdc */


void game_clear() { /* Line 626, Address: 0x1005bf0 */
  clrspflg |= (unsigned char)(1 << stagenm); /* Line 627, Address: 0x1005bf8 */
  lpKeepWork->clrspflg_save = clrspflg; /* Line 628, Address: 0x1005c24 */
  game_over(); /* Line 629, Address: 0x1005c38 */
} /* Line 630, Address: 0x1005c40 */


void game_over() { /* Line 633, Address: 0x1005c50 */
  unsigned char d0;





  d0 = stagenm; /* Line 640, Address: 0x1005c58 */
  do {
    ++d0; /* Line 642, Address: 0x1005c64 */
    if (d0 >= 7) { /* Line 643, Address: 0x1005c6c */
      d0 = 0; /* Line 644, Address: 0x1005c7c */
    }
    if (clrspflg == 127) return; /* Line 646, Address: 0x1005c80 */


  } while ((clrspflg & 1 << d0) != 0); /* Line 649, Address: 0x1005c98 */





} /* Line 655, Address: 0x1005cbc */












void game_init() { /* Line 668, Address: 0x1005cd0 */
  palette_entry* lpPeDest;
  int i;



  overint.l = -1; /* Line 674, Address: 0x1005ce0 */

  sMemSet(actwk, 0, sizeof(actwk)); /* Line 676, Address: 0x1005cec */


  lpPeDest = lpcolorwk; /* Line 679, Address: 0x1005d0c */
  for (i = 0; i < 64; ++i) /* Line 680, Address: 0x1005d14 */
    *lpPeDest++ = colortbl[i]; /* Line 681, Address: 0x1005d20 */

  stage_init(); /* Line 683, Address: 0x1005d68 */






  demoflg = 1; /* Line 690, Address: 0x1005d70 */
  pauseflg = 128; /* Line 691, Address: 0x1005d7c */
  overint.l = 0; /* Line 692, Address: 0x1005d88 */



  spe_time.l = 0; /* Line 696, Address: 0x1005d90 */
  ringno = 0; /* Line 697, Address: 0x1005d98 */
  ufoleft = 6; /* Line 698, Address: 0x1005da0 */



  time_stop = 0; /* Line 702, Address: 0x1005dac */

  kaiten_init(); /* Line 704, Address: 0x1005db4 */
  colli_init(); /* Line 705, Address: 0x1005dbc */

  actwk[0].actno = 1; /* Line 707, Address: 0x1005dc4 */
  actwk[1].actno = 6; /* Line 708, Address: 0x1005dd0 */
  actwk[3].actno = 10; /* Line 709, Address: 0x1005ddc */
  actwk[4].actno = 11; /* Line 710, Address: 0x1005de8 */

  ufo_initial(); /* Line 712, Address: 0x1005df4 */

  tcnt20 = 20; /* Line 714, Address: 0x1005dfc */
  rufo_getnm = 20; /* Line 715, Address: 0x1005e08 */
  game_start = 1; /* Line 716, Address: 0x1005e14 */

  if (!(spgmmode & 2)) { /* Line 718, Address: 0x1005e20 */
    spe_time.l = 100; /* Line 719, Address: 0x1005e38 */
  }

  CDPlay(32); /* Line 722, Address: 0x1005e44 */

} /* Line 724, Address: 0x1005e58 */



























void syspatchg() {} /* Line 752, Address: 0x1005e70 */



void sdfdout() { /* Line 756, Address: 0x1005e80 */
  soundset(171); /* Line 757, Address: 0x1005e88 */









} /* Line 767, Address: 0x1005e94 */













void sdfdin() {} /* Line 781, Address: 0x1005eb0 */













void disp() { /* Line 795, Address: 0x1005ec0 */
  short i;
  palette_entry *lpPeSrc, *lpPeDest;

  ring_bonus = ringno * 20; /* Line 799, Address: 0x1005ed4 */
  time_bonus = spe_time.l * 20; /* Line 800, Address: 0x1005ef4 */

  demoflg = 0; /* Line 802, Address: 0x1005f10 */
  specialflg = 0; /* Line 803, Address: 0x1005f18 */



  clrspflg_save = clrspflg; /* Line 807, Address: 0x1005f20 */

  lpPeSrc = dispcolor; /* Line 809, Address: 0x1005f30 */
  lpPeDest = lpcolorwk; /* Line 810, Address: 0x1005f38 */
  for (i = 0; i < 64; ++i) { /* Line 811, Address: 0x1005f40 */
    *lpPeDest++ = *lpPeSrc++; /* Line 812, Address: 0x1005f4c */
  } /* Line 813, Address: 0x1005f7c */

  map_init(); /* Line 815, Address: 0x1005f9c */
  clwin_init(); /* Line 816, Address: 0x1005fa4 */
  clwin(); /* Line 817, Address: 0x1005fac */
  gmtime0 = 480; /* Line 818, Address: 0x1005fb4 */
  sonicup_no = 0; /* Line 819, Address: 0x1005fc0 */

} /* Line 821, Address: 0x1005fc8 */











int disp_main() { /* Line 833, Address: 0x1005ff0 */
  if ((long int)ring_bonus != 0) { /* Line 834, Address: 0x1005ff8 */

    gsc_up20(); /* Line 836, Address: 0x1006010 */
    ring_bonus -= 20; /* Line 837, Address: 0x1006018 */
  } else { /* Line 838, Address: 0x100602c */
    if ((long int)time_bonus != 0) { /* Line 839, Address: 0x1006034 */


      time_bonus -= 20; /* Line 842, Address: 0x100604c */
      gsc_up20(); /* Line 843, Address: 0x1006060 */
    }
  }
  if (seregiflg == 0) { /* Line 846, Address: 0x1006068 */

    if ((long int)(time_bonus + ring_bonus) == 0) { /* Line 848, Address: 0x100607c */

      if (time_bonus == 0) WaveAllStop(); /* Line 850, Address: 0x10060a0 */
      seregiflg = 1; /* Line 851, Address: 0x10060c0 */

      soundset(154); /* Line 853, Address: 0x10060cc */
    }
  }

  if (--gmtime0) return 0; /* Line 857, Address: 0x10060d8 */


  gsc_up(ring_bonus + time_bonus); /* Line 860, Address: 0x1006108 */


  WaveAllStop(); /* Line 863, Address: 0x1006124 */
  soundset(200); /* Line 864, Address: 0x1006134 */
  clwout(); /* Line 865, Address: 0x1006140 */
  return 1; /* Line 866, Address: 0x1006148 */
} /* Line 867, Address: 0x100614c */













void gsc_up20() { /* Line 881, Address: 0x1006160 */

  if (++scoreup_setm % 6 == 0) /* Line 883, Address: 0x1006168 */
    key_set(189); /* Line 884, Address: 0x1006190 */
  gsc_up(20); /* Line 885, Address: 0x100619c */
} /* Line 886, Address: 0x10061a8 */

void gsc_up(int lScore) { /* Line 888, Address: 0x10061c0 */


  lScore += game_score; /* Line 891, Address: 0x10061cc */


  while (lScore > extra_score) { /* Line 894, Address: 0x10061e0 */

    extra_score += 5000; /* Line 896, Address: 0x10061e8 */
    ++pl_suu; /* Line 897, Address: 0x10061fc */
    ++sonicup_no; /* Line 898, Address: 0x1006210 */
    WaveAllStop(); /* Line 899, Address: 0x1006224 */
    sub_sync(122); /* Line 900, Address: 0x1006234 */
    if (pl_suu >= 250) /* Line 901, Address: 0x1006240 */
      pl_suu = 249; /* Line 902, Address: 0x1006258 */
  } /* Line 903, Address: 0x1006264 */

  game_score = lScore; /* Line 905, Address: 0x100627c */
  if (game_score >= 1000000U) { /* Line 906, Address: 0x1006288 */
    game_score = 999999; /* Line 907, Address: 0x10062a4 */
  }
} /* Line 909, Address: 0x10062b4 */











short pause_chk() { /* Line 921, Address: 0x10062d0 */

  if (pauseflg & 128) { /* Line 923, Address: 0x10062d8 */
    if (pauseflg & 1) { /* Line 924, Address: 0x10062f0 */

      if (swdata1.b.l & 128) { /* Line 926, Address: 0x1006308 */
        if (swdata2.w & 32896) { /* Line 927, Address: 0x1006320 */
          if (PauseIcon != 0) { /* Line 928, Address: 0x1006338 */
            pauseflg &= 254; /* Line 929, Address: 0x1006348 */
            PauseIcon = 0; /* Line 930, Address: 0x100635c */
            return 0; /* Line 931, Address: 0x1006364 */
          }
        }
        else {
          pauseflg &= 254; /* Line 935, Address: 0x1006370 */
          CDPause(1); /* Line 936, Address: 0x1006384 */
          return 0; /* Line 937, Address: 0x1006398 */
        }
      }

      return 1; /* Line 941, Address: 0x10063a4 */
    }


    if (!(spgmmode & 1)) { /* Line 945, Address: 0x10063b0 */

      if (swdata1.b.l & 128) { /* Line 947, Address: 0x10063c8 */
        if (swdata2.w & 32896) PauseIcon = 1; /* Line 948, Address: 0x10063e0 */
        pauseflg |= 1; /* Line 949, Address: 0x1006404 */
        CDPause(0); /* Line 950, Address: 0x1006418 */
        return 1; /* Line 951, Address: 0x100642c */
      }
    }
  }


  return 0; /* Line 957, Address: 0x1006438 */

} /* Line 959, Address: 0x100643c */
















void map_init() { /* Line 976, Address: 0x1006450 */
  unsigned int d5;
  int i;

  if (time_bonus != 0) { /* Line 980, Address: 0x1006460 */
    if (clrspflg_save != 127) d5 = 15; /* Line 981, Address: 0x1006470 */
    else d5 = 16; /* Line 982, Address: 0x1006494 */
  } /* Line 983, Address: 0x1006498 */
  else
    d5 = 14; /* Line 985, Address: 0x10064a0 */

  bwrtset(d5); /* Line 987, Address: 0x10064a4 */

  for (i = 0; i < 7; ++i) { /* Line 989, Address: 0x10064b0 */

    if (clrspflg_save & 1 << i) { /* Line 991, Address: 0x10064bc */
      bwrtset(i + 1); /* Line 992, Address: 0x10064dc */
    }
  } /* Line 994, Address: 0x10064e8 */
  bwrtset(134810123); /* Line 995, Address: 0x10064f8 */
  bwrtset(3085); /* Line 996, Address: 0x1006508 */

} /* Line 998, Address: 0x1006514 */






































































































void bwrtset(unsigned int tblno4) { /* Line 1101, Address: 0x1006530 */
  int i;
  int xbase, ybase, x, y;
  int tileno;
  unsigned short col, tblno;

  do {
    tblno = (long int)tblno4 & 255; /* Line 1108, Address: 0x100655c */
    if (!tblno) break; /* Line 1109, Address: 0x1006574 */
    --tblno; /* Line 1110, Address: 0x100657c */
    xbase = (bwrtTbl[tblno].vadr & 127) / 2; /* Line 1111, Address: 0x1006584 */
    ybase = bwrtTbl[tblno].vadr / 128; /* Line 1112, Address: 0x10065c4 */
    i = 0; /* Line 1113, Address: 0x1006600 */
    for (y = 0; y < bwrtTbl[tblno].ysize; ++y) { /* Line 1114, Address: 0x1006604 */
      for (x = 0; x < bwrtTbl[tblno].xsize; ++x) { /* Line 1115, Address: 0x1006610 */
        tileno = bwrtTbl[tblno].tbl[i] & 2047; /* Line 1116, Address: 0x100661c */
        col = bwrtTbl[tblno].tbl[i] & 24576; /* Line 1117, Address: 0x1006650 */
        ++i; /* Line 1118, Address: 0x100668c */
        if (col == 24576) { /* Line 1119, Address: 0x1006690 */
          tileno += 687; /* Line 1120, Address: 0x10066a0 */
        } /* Line 1121, Address: 0x10066a4 */
        else if (col == 16384) { /* Line 1122, Address: 0x10066ac */
          tileno += 458; /* Line 1123, Address: 0x10066bc */
        } /* Line 1124, Address: 0x10066c0 */
        else if (col == 8192) { /* Line 1125, Address: 0x10066c8 */
          tileno += 229; /* Line 1126, Address: 0x10066d8 */
        }
        SetGrid(0, xbase + x, ybase + y, tileno, 0); /* Line 1128, Address: 0x10066dc */
      } /* Line 1129, Address: 0x1006700 */
    } /* Line 1130, Address: 0x1006734 */




    tblno4 >>= 8; /* Line 1135, Address: 0x1006768 */
  } while (1); /* Line 1136, Address: 0x1006774 */

} /* Line 1138, Address: 0x100677c */























void stone_color_set() { /* Line 1162, Address: 0x10067b0 */
  palette_entry *lpPeSrc, *lpPeDest;
  short i;

  if (ufoleft != 0) return; /* Line 1166, Address: 0x10067c0 */
  if (stone_timer == 0) return; /* Line 1167, Address: 0x10067d4 */
  if (--stone_timer != 0) return; /* Line 1168, Address: 0x10067e8 */


  lpPeSrc = &stone_color_set_tbl[stagenm * 5 + 1]; /* Line 1171, Address: 0x100680c */
  lpPeDest = &lpcolorwk[50]; /* Line 1172, Address: 0x1006834 */
  for (i = 0; i < 4; ++i) { /* Line 1173, Address: 0x1006840 */
    *lpPeDest++ = *lpPeSrc++; /* Line 1174, Address: 0x100684c */
  } /* Line 1175, Address: 0x100687c */







  intflg |= 2; /* Line 1183, Address: 0x100689c */

} /* Line 1185, Address: 0x10068b0 */















void panel_box() {} /* Line 1201, Address: 0x10068d0 */


void colset(palette_entry* lpPeSrc) { /* Line 1204, Address: 0x10068e0 */
  palette_entry* lpPeDest;
  int i;

  lpPeDest = &lpcolorwk[16]; /* Line 1208, Address: 0x10068f0 */
  for (i = 0; i < 32; ++i) { /* Line 1209, Address: 0x10068fc */
    *lpPeDest++ = *lpPeSrc++; /* Line 1210, Address: 0x1006908 */
  } /* Line 1211, Address: 0x100693c */

} /* Line 1213, Address: 0x100694c */


void sinit0() { /* Line 1216, Address: 0x1006960 */



  panel_box(); /* Line 1220, Address: 0x1006968 */

  colset(coltbl0); /* Line 1222, Address: 0x1006970 */
} /* Line 1223, Address: 0x1006980 */

void sinit1() { /* Line 1225, Address: 0x1006990 */
  panel_box(); /* Line 1226, Address: 0x1006998 */

  colset(coltbl1); /* Line 1228, Address: 0x10069a0 */
} /* Line 1229, Address: 0x10069b0 */

void sinit2() { /* Line 1231, Address: 0x10069c0 */
  panel_box(); /* Line 1232, Address: 0x10069c8 */

  colset(coltbl2); /* Line 1234, Address: 0x10069d0 */
} /* Line 1235, Address: 0x10069e0 */

void sinit3() { /* Line 1237, Address: 0x10069f0 */
  panel_box(); /* Line 1238, Address: 0x10069f8 */

  colset(coltbl3); /* Line 1240, Address: 0x1006a00 */
} /* Line 1241, Address: 0x1006a10 */

void sinit4() { /* Line 1243, Address: 0x1006a20 */
  short i;

  panel_box(); /* Line 1246, Address: 0x1006a2c */

  colset(coltbl4); /* Line 1248, Address: 0x1006a34 */

  for (i = 0; i < 128; ++i) hdatabuf[i] = 4286578688; /* Line 1250, Address: 0x1006a44 */
} /* Line 1251, Address: 0x1006a90 */

void sinit5() { /* Line 1253, Address: 0x1006ab0 */
  panel_box(); /* Line 1254, Address: 0x1006ab8 */

  colset(coltbl5); /* Line 1256, Address: 0x1006ac0 */
} /* Line 1257, Address: 0x1006ad0 */

void sinit6() { /* Line 1259, Address: 0x1006ae0 */
  panel_box(); /* Line 1260, Address: 0x1006ae8 */

  colset(coltbl6); /* Line 1262, Address: 0x1006af0 */
} /* Line 1263, Address: 0x1006b00 */

void sinit7() { /* Line 1265, Address: 0x1006b10 */
  panel_box(); /* Line 1266, Address: 0x1006b18 */

  colset(coltbl7); /* Line 1268, Address: 0x1006b20 */
} /* Line 1269, Address: 0x1006b30 */


void stage_init() { /* Line 1272, Address: 0x1006b40 */
  void(*jptbl[8])() = { /* Line 1273, Address: 0x1006b48 */
    &sinit1, &sinit2, &sinit3, &sinit4, &sinit5, &sinit6, &sinit7
  };

  jptbl[stagenm](); /* Line 1277, Address: 0x1006b7c */
} /* Line 1278, Address: 0x1006b9c */












static unsigned char SeToWavTbl[80] = {
   0,  1,  2,  3,  4,  5,  6,  7,  8,  9,
  10, 11, 11, 12, 13, 14, 15, 16, 17, 18,
  19, 20, 20, 21, 22, 22, 23, 23, 24, 25,
  26, 27, 28, 29, 30, 31, 43, 44, 45, 46,
  47, 48, 49, 50, 51, 52, 53, 54, 55, 56,
  57, 58, 58, 59, 60, 61, 62, 63, 64, 65,
  67, 68, 69, 70, 71, 71, 72, 73, 74, 32,
  33, 34, 35, 36, 37, 38, 39, 40, 41, 42,
};


void soundset(short ReqNo) { /* Line 1303, Address: 0x1006bb0 */
  if (ReqNo == 171) return; /* Line 1304, Address: 0x1006bbc */



  ReqNo -= 144; /* Line 1308, Address: 0x1006bd4 */
  ReqNo = (unsigned short)SeToWavTbl[ReqNo]; /* Line 1309, Address: 0x1006be0 */

  WaveRequest(ReqNo); /* Line 1311, Address: 0x1006c0c */
} /* Line 1312, Address: 0x1006c20 */




void sub_sync(short ReqNo) { /* Line 1317, Address: 0x1006c30 */




  if (ReqNo >= 118 && ReqNo < 129) { /* Line 1322, Address: 0x1006c3c */
    WaveRequest(ReqNo - 43); /* Line 1323, Address: 0x1006c6c */
  } /* Line 1324, Address: 0x1006c94 */
  else if (ReqNo >= 15 && ReqNo < 35) { /* Line 1325, Address: 0x1006c9c */
    CDPlay(ReqNo - 12); /* Line 1326, Address: 0x1006ccc */
  } /* Line 1327, Address: 0x1006cf4 */
  else if (ReqNo >= 102 && ReqNo < 113) { /* Line 1328, Address: 0x1006cfc */
    CDPlay(ReqNo - 79); /* Line 1329, Address: 0x1006d2c */
  } /* Line 1330, Address: 0x1006d54 */
  else if (ReqNo == 113) { /* Line 1331, Address: 0x1006d5c */
    CDPlay(2); /* Line 1332, Address: 0x1006d74 */
  } /* Line 1333, Address: 0x1006d88 */
  else if (ReqNo >= 114 && ReqNo < 116) { /* Line 1334, Address: 0x1006d90 */
    CDPlay(ReqNo - 80); /* Line 1335, Address: 0x1006dc0 */
  } else if (ReqNo == 146) { /* Line 1336, Address: 0x1006de8 */
    WaveRequest(85); /* Line 1337, Address: 0x1006e08 */
  }
} /* Line 1339, Address: 0x1006e1c */


void key_set(short ReqNo) { /* Line 1342, Address: 0x1006e30 */
  soundset(ReqNo); /* Line 1343, Address: 0x1006e3c */
} /* Line 1344, Address: 0x1006e48 */




void SWdataSet(ushort_union sw1, ushort_union sw2) {  /* Line 1349, Address: 0x1006e60 */
  swdata1.w = sw1.w; /* Line 1350, Address: 0x1006e6c */
  swdata2.w = sw2.w; /* Line 1351, Address: 0x1006e78 */

} /* Line 1353, Address: 0x1006e84 */









void hscal_1() { /* Line 1363, Address: 0x1006e90 */
  if (!scroll_stop) { /* Line 1364, Address: 0x1006e98 */
    if (stagenm == 0) hscal1_0(); /* Line 1365, Address: 0x1006ea8 */
    else if (stagenm == 4) hscal1_4(); /* Line 1366, Address: 0x1006ecc */
    else if (stagenm == 5) hscal1_5(); /* Line 1367, Address: 0x1006ef4 */
  }
} /* Line 1369, Address: 0x1006f14 */

void hscal_2(){ /* Line 1371, Address: 0x1006f30 */
  if (!scroll_stop) { /* Line 1372, Address: 0x1006f38 */
    if (stagenm == 0) hscal2_0(); /* Line 1373, Address: 0x1006f48 */
    else if (stagenm == 4) hscal2_4(); /* Line 1374, Address: 0x1006f6c */
    else if (stagenm == 5) hscal2_5(); /* Line 1375, Address: 0x1006f94 */
  }
} /* Line 1377, Address: 0x1006fb4 */




void hscal0_0() { /* Line 1382, Address: 0x1006fd0 */
  int d0, d1;
  short *a0, *a1;
  short d3, d4, d7;

  d0 = 524288; /* Line 1387, Address: 0x1006fec */
  d1 = 0; /* Line 1388, Address: 0x1006ff4 */
  rlspd_get(&d0, &d1); /* Line 1389, Address: 0x1006ff8 */
  hsdata1 += d0; /* Line 1390, Address: 0x1007008 */
  d0 >>= 1; /* Line 1391, Address: 0x1007020 */
  hsdata0 += d0; /* Line 1392, Address: 0x100702c */



  if (!hscrflg) { /* Line 1396, Address: 0x1007044 */
    ++hscrcnt; /* Line 1397, Address: 0x1007054 */
    if (hscrcnt >= 512) { /* Line 1398, Address: 0x1007068 */
      hscrcnt = 511; /* Line 1399, Address: 0x1007080 */
      hscrflg = 1; /* Line 1400, Address: 0x100708c */
    }
  } /* Line 1402, Address: 0x1007098 */
  else {

    if ((short)--hscrcnt < 0) { /* Line 1405, Address: 0x10070a0 */
      hscrcnt = 0; /* Line 1406, Address: 0x10070d0 */
      hscrflg = 0; /* Line 1407, Address: 0x10070d8 */
    }
  }

  a0 = (short*)&hdatabuf[0]; /* Line 1411, Address: 0x10070e0 */
  a1 = (short*)hdatabuf_l; /* Line 1412, Address: 0x10070e8 */
  d0 = 65536; /* Line 1413, Address: 0x10070f0 */
  d1 = 1024; /* Line 1414, Address: 0x10070f8 */
  d3 = 0; /* Line 1415, Address: 0x1007100 */
  d4 = 0; /* Line 1416, Address: 0x1007104 */
  d7 = 23; /* Line 1417, Address: 0x1007108 */
  hscal0(a0, a1, d0, d1, d3, d4, d7); /* Line 1418, Address: 0x1007114 */
} /* Line 1419, Address: 0x1007138 */


void hscal1_0() { /* Line 1422, Address: 0x1007160 */
  int d0, d1;
  short *a0, *a1;
  short d3, d4, d7;

  a0 = (short*)&hdatabuf[24]; /* Line 1427, Address: 0x1007184 */
  a1 = (short*)hdatabuf_l; /* Line 1428, Address: 0x1007190 */
  d0 = 40960; /* Line 1429, Address: 0x1007198 */
  d1 = 1024; /* Line 1430, Address: 0x100719c */
  d3 = hsdata1 >> 16; /* Line 1431, Address: 0x10071a0 */
  d4 = 0; /* Line 1432, Address: 0x10071bc */
  d7 = 71; /* Line 1433, Address: 0x10071c0 */

  hscal0(a0, a1, d0, d1, d3, d4, d7); /* Line 1435, Address: 0x10071cc */
} /* Line 1436, Address: 0x10071f0 */

void hscal2_0() { /* Line 1438, Address: 0x1007220 */
  int d0, d1;
  short *a0, *a1;
  short d3, d4, d7;

  a0 = (short*)&hdatabuf[96]; /* Line 1443, Address: 0x1007244 */
  a1 = (short*)hdatabuf_l; /* Line 1444, Address: 0x1007250 */
  d0 = -32768; /* Line 1445, Address: 0x1007258 */
  d1 = 1024; /* Line 1446, Address: 0x100725c */
  d3 = hsdata0 >> 16; /* Line 1447, Address: 0x1007260 */
  d4 = 0; /* Line 1448, Address: 0x100727c */
  d7 = 31; /* Line 1449, Address: 0x1007280 */

  hscal0(a0, a1, d0, d1, d3, d4, d7); /* Line 1451, Address: 0x100728c */
} /* Line 1452, Address: 0x10072b0 */


void hscal0(short* a0, short* a1, int d0, int d1, short d3, short d4, short d7) { /* Line 1455, Address: 0x10072e0 */
  int_union d2;

  if (!hscrflg) { /* Line 1458, Address: 0x1007300 */

    do {
      *a0++ = d3; /* Line 1461, Address: 0x1007310 */
      *a1++ = d4; /* Line 1462, Address: 0x1007324 */
      d2.w.h = *a0; /* Line 1463, Address: 0x1007338 */
      d2.w.l = *a1; /* Line 1464, Address: 0x1007344 */
      d2.l += d0; /* Line 1465, Address: 0x1007350 */
      *a1++ = d2.w.l; /* Line 1466, Address: 0x1007360 */
      *a0++ = d2.w.h; /* Line 1467, Address: 0x1007374 */
      d0 -= d1; /* Line 1468, Address: 0x1007388 */
    } while (--d7 >= 0); /* Line 1469, Address: 0x1007398 */
  } /* Line 1470, Address: 0x10073bc */
  else {

    do {
      *a0++ = d3; /* Line 1474, Address: 0x10073c4 */
      *a1++ = d4; /* Line 1475, Address: 0x10073d8 */
      d2.w.h = *a0; /* Line 1476, Address: 0x10073ec */
      d2.w.l = *a1; /* Line 1477, Address: 0x10073f8 */
      d2.l -= d0; /* Line 1478, Address: 0x1007404 */
      *a1++ = d2.w.l; /* Line 1479, Address: 0x1007414 */
      *a0++ = d2.w.h; /* Line 1480, Address: 0x1007428 */
      d0 -= d1; /* Line 1481, Address: 0x100743c */
    } while (--d7 >= 0); /* Line 1482, Address: 0x100744c */
  }
} /* Line 1484, Address: 0x1007470 */



void hscal0_4() { /* Line 1488, Address: 0x1007480 */
  int d0, d1;
  short *a0, *a1;
  int* a2;
  short d7;

  d0 = 262144; /* Line 1494, Address: 0x1007498 */
  d1 = 0; /* Line 1495, Address: 0x10074a0 */
  rlspd_get(&d0, &d1); /* Line 1496, Address: 0x10074a4 */
  hsdata0 += d0; /* Line 1497, Address: 0x10074b4 */






  hscrflg = 0; /* Line 1504, Address: 0x10074cc */
  if (rlscrflg_save & 4) { /* Line 1505, Address: 0x10074d4 */

    hscrflg = 1; /* Line 1507, Address: 0x10074ec */
    ++hscrcnt4; /* Line 1508, Address: 0x10074f8 */
    hscrcnt4 &= 15; /* Line 1509, Address: 0x100750c */
    if (!hscrcnt4) hscrflg = 2; /* Line 1510, Address: 0x1007520 */
  }

  if (rlscrflg_save & 8) { /* Line 1513, Address: 0x100753c */

    hscrflg = 255; /* Line 1515, Address: 0x1007554 */
    --hscrcnt4; /* Line 1516, Address: 0x1007560 */
    hscrcnt4 &= 15; /* Line 1517, Address: 0x1007574 */
    if (!hscrcnt4) hscrflg = 2; /* Line 1518, Address: 0x1007588 */
  }

  a0 = (short*)&hdatabuf[0]; /* Line 1521, Address: 0x10075a4 */
  a1 = (short*)hdatabuf_l; /* Line 1522, Address: 0x10075ac */
  a2 = hdatatbl4; /* Line 1523, Address: 0x10075b4 */
  d0 = 0; /* Line 1524, Address: 0x10075bc */
  d7 = 16; /* Line 1525, Address: 0x10075c0 */

  do {
    *(int*)a0 = d0; /* Line 1528, Address: 0x10075cc */
    *(int*)a1 = d0; /* Line 1529, Address: 0x10075d4 */
    a0 += 2; /* Line 1530, Address: 0x10075dc */
    a1 += 2; /* Line 1531, Address: 0x10075e0 */
  } while (--d7 >= 0); /* Line 1532, Address: 0x10075e4 */
  d7 = 6; /* Line 1533, Address: 0x1007608 */
  hscal4(a0, a1, a2, 0, d7); /* Line 1534, Address: 0x1007614 */
} /* Line 1535, Address: 0x1007630 */

void hscal1_4() { /* Line 1537, Address: 0x1007650 */
  short *a0, *a1;
  int* a2;
  short d7;

  a0 = (short*)&hdatabuf[24]; /* Line 1542, Address: 0x1007668 */
  a1 = (short*)hdatabuf_l; /* Line 1543, Address: 0x1007674 */
  a2 = hdatatbl4; /* Line 1544, Address: 0x100767c */

  d7 = 55; /* Line 1546, Address: 0x1007684 */

  hscal4(a0, a1, a2, hsdata0 >> 16, d7); /* Line 1548, Address: 0x1007690 */
} /* Line 1549, Address: 0x10076bc */

void hscal2_4() { /* Line 1551, Address: 0x10076e0 */
  short *a0, *a1;
  int* a2;
  short d7;

  a0 = (short*)&hdatabuf[80]; /* Line 1556, Address: 0x10076f8 */
  a1 = (short*)hdatabuf_l; /* Line 1557, Address: 0x1007704 */
  a2 = hdatatbl4; /* Line 1558, Address: 0x100770c */

  d7 = 47; /* Line 1560, Address: 0x1007714 */

  hscal4(a0, a1, a2, hsdata0 >> 16, d7); /* Line 1562, Address: 0x1007720 */
} /* Line 1563, Address: 0x100774c */


void hscal4(short* a0, short* a1, int* a2, short d0, short d7) { /* Line 1566, Address: 0x1007770 */
  int_union d2;

  if (hscrflg == 2) { /* Line 1569, Address: 0x1007788 */

    do {
      *a0++ = d0; /* Line 1572, Address: 0x10077a0 */
      *a1++ = d0; /* Line 1573, Address: 0x10077b4 */
      *a0++ = -128; /* Line 1574, Address: 0x10077c8 */
      *a1++ = 0; /* Line 1575, Address: 0x10077dc */
    } while (--d7 >= 0); /* Line 1576, Address: 0x10077ec */
    return; /* Line 1577, Address: 0x1007810 */
  }
  if (hscrflg == 0) return; /* Line 1579, Address: 0x1007818 */
  if ((char)hscrflg > 0) { /* Line 1580, Address: 0x100782c */


    do {
      *a0++ = d0; /* Line 1584, Address: 0x100784c */
      *a1++ = d0; /* Line 1585, Address: 0x1007860 */
      d2.w.h = *a0; /* Line 1586, Address: 0x1007874 */
      d2.w.l = *a1; /* Line 1587, Address: 0x1007880 */
      d2.l += *a2++; /* Line 1588, Address: 0x100788c */
      *a1++ = d2.w.l; /* Line 1589, Address: 0x10078a8 */
      *a0++ = d2.w.h; /* Line 1590, Address: 0x10078bc */
    } while (--d7 >= 0); /* Line 1591, Address: 0x10078d0 */
  } /* Line 1592, Address: 0x10078f4 */
  else {


    do {
      *a0++ = d0; /* Line 1597, Address: 0x10078fc */
      *a1++ = d0; /* Line 1598, Address: 0x1007910 */
      d2.w.h = *a0; /* Line 1599, Address: 0x1007924 */
      d2.w.l = *a1; /* Line 1600, Address: 0x1007930 */
      d2.l -= *a2++; /* Line 1601, Address: 0x100793c */
      *a1++ = d2.w.l; /* Line 1602, Address: 0x1007958 */
      *a0++ = d2.w.h; /* Line 1603, Address: 0x100796c */
    } while (--d7 >= 0); /* Line 1604, Address: 0x1007980 */
  }
} /* Line 1606, Address: 0x10079a4 */




void hscal0_5() { /* Line 1611, Address: 0x10079b0 */
  int d0, d1;
  short* a0;
  char* a2;
  short d2, d7;

  d0 = 262144; /* Line 1617, Address: 0x10079c8 */
  d1 = 0; /* Line 1618, Address: 0x10079d0 */
  rlspd_get(&d0, &d1); /* Line 1619, Address: 0x10079d4 */
  hsdata0 += d0; /* Line 1620, Address: 0x10079e4 */

  a0 = (short*)&hdatabuf[0]; /* Line 1622, Address: 0x10079fc */
  a2 = hdatatbl5; /* Line 1623, Address: 0x1007a04 */
  d0 = 0; /* Line 1624, Address: 0x1007a0c */
  d2 = hscrcnt4; /* Line 1625, Address: 0x1007a10 */
  ++d2; /* Line 1626, Address: 0x1007a20 */
  d2 &= 127; /* Line 1627, Address: 0x1007a2c */
  hscrcnt4 = d2; /* Line 1628, Address: 0x1007a38 */
  d7 = 23; /* Line 1629, Address: 0x1007a40 */

  hscal5(a0, a2, 0, d2, d7); /* Line 1631, Address: 0x1007a4c */
} /* Line 1632, Address: 0x1007a68 */

void hscal1_5() { /* Line 1634, Address: 0x1007a90 */
  short* a0;
  char* a2;
  short d2, d7;

  a0 = (short*)&hdatabuf[24]; /* Line 1639, Address: 0x1007aa8 */
  a2 = hdatatbl5; /* Line 1640, Address: 0x1007ab4 */

  d2 = hscrcnt4; /* Line 1642, Address: 0x1007abc */
  d7 = 55; /* Line 1643, Address: 0x1007acc */

  hscal5(a0, a2, hsdata0 >> 16, d2, d7); /* Line 1645, Address: 0x1007ad8 */
} /* Line 1646, Address: 0x1007b04 */

void hscal2_5() { /* Line 1648, Address: 0x1007b30 */
  short* a0;
  char* a2;
  short d2, d7;

  a0 = (short*)&hdatabuf[80]; /* Line 1653, Address: 0x1007b48 */
  a2 = hdatatbl5; /* Line 1654, Address: 0x1007b54 */

  d2 = hscrcnt4; /* Line 1656, Address: 0x1007b5c */
  d7 = 47; /* Line 1657, Address: 0x1007b6c */

  hscal5(a0, a2, hsdata0 >> 16, d2, d7); /* Line 1659, Address: 0x1007b78 */
} /* Line 1660, Address: 0x1007ba4 */

void hscal5(short* a0, char* a2, short d0, short d2, short d7) { /* Line 1662, Address: 0x1007bd0 */
  short d1;

  do {
    *a0++ = d0; /* Line 1666, Address: 0x1007bec */
    d1 = a2[d2]; /* Line 1667, Address: 0x1007c00 */
    *a0++ = d1; /* Line 1668, Address: 0x1007c28 */
    ++d2; /* Line 1669, Address: 0x1007c38 */
    d2 &= 127; /* Line 1670, Address: 0x1007c44 */
  } while (--d7 >= 0); /* Line 1671, Address: 0x1007c50 */
  hscrcnt4 = d2; /* Line 1672, Address: 0x1007c74 */
} /* Line 1673, Address: 0x1007c80 */



void rlspd_get(int* d0, int* d1) { /* Line 1677, Address: 0x1007c90 */
  if (rlscrflg_save & 4) return; /* Line 1678, Address: 0x1007c9c */
  *d0 = -*d0; /* Line 1679, Address: 0x1007cb4 */
  *d1 = -*d1; /* Line 1680, Address: 0x1007cc8 */
  if (rlscrflg_save & 8) return; /* Line 1681, Address: 0x1007cdc */
  *d0 = 0; /* Line 1682, Address: 0x1007cf4 */
  *d1 = 0; /* Line 1683, Address: 0x1007cfc */
} /* Line 1684, Address: 0x1007d04 */

void hscrspd_get(int* lD0, int* lD1) { /* Line 1686, Address: 0x1007d10 */










  *lD0 = 262144; /* Line 1697, Address: 0x1007d20 */
  rlspd_get(lD0, lD1); /* Line 1698, Address: 0x1007d2c */
  hsdata2 += *lD0; /* Line 1699, Address: 0x1007d3c */
  *lD0 /= 2; /* Line 1700, Address: 0x1007d58 */
  hsdata1 += *lD0; /* Line 1701, Address: 0x1007d80 */
  *lD0 /= 2; /* Line 1702, Address: 0x1007d9c */
  hsdata0 += *lD0; /* Line 1703, Address: 0x1007dc4 */

} /* Line 1705, Address: 0x1007de0 */


void hscrl0() { /* Line 1708, Address: 0x1007df0 */
  hscal0_0(); /* Line 1709, Address: 0x1007df8 */
  hscal1_0(); /* Line 1710, Address: 0x1007e00 */
  hscal2_0(); /* Line 1711, Address: 0x1007e08 */

} /* Line 1713, Address: 0x1007e10 */

void hscrl1() { /* Line 1715, Address: 0x1007e20 */
  int lD0;
  int lD1;
  int i;












  for (i = 0; i < 3; ++i) { /* Line 1731, Address: 0x1007e2c */
    hscrspd_get(&lD0, &lD1); /* Line 1732, Address: 0x1007e38 */
    hdatabuf[0] = hsdata1; /* Line 1733, Address: 0x1007e48 */
    hdatabuf[1] = hsdata2; /* Line 1734, Address: 0x1007e5c */
  } /* Line 1735, Address: 0x1007e70 */

} /* Line 1737, Address: 0x1007e80 */

void hscrl2() { /* Line 1739, Address: 0x1007ea0 */
  int lD0;
  int lD1;
  int i;

  for (i = 0; i < 3; ++i) { /* Line 1744, Address: 0x1007eac */
    lD0 = 524288; /* Line 1745, Address: 0x1007eb8 */
    lD1 = 65536; /* Line 1746, Address: 0x1007ec0 */
    rlspd_get(&lD0, &lD1); /* Line 1747, Address: 0x1007ec8 */

    hsdata0 += lD0; /* Line 1749, Address: 0x1007ed8 */
    lD0 -= lD1; /* Line 1750, Address: 0x1007ef0 */
    hsdata1 += lD0; /* Line 1751, Address: 0x1007f00 */
    lD0 -= lD1; /* Line 1752, Address: 0x1007f18 */
    hsdata2 += lD0; /* Line 1753, Address: 0x1007f28 */
    lD0 -= lD1; /* Line 1754, Address: 0x1007f40 */
    hsdata3 += lD0; /* Line 1755, Address: 0x1007f50 */
    lD0 -= lD1; /* Line 1756, Address: 0x1007f68 */
    hsdata4 += lD0; /* Line 1757, Address: 0x1007f78 */
    lD0 -= lD1; /* Line 1758, Address: 0x1007f90 */
    hsdata5 += lD0; /* Line 1759, Address: 0x1007fa0 */


    hdatabuf[0] = hsdata4; /* Line 1762, Address: 0x1007fb8 */

    hdatabuf[1] = hsdata1; /* Line 1764, Address: 0x1007fcc */
    hdatabuf[2] = hsdata2; /* Line 1765, Address: 0x1007fe0 */
    hdatabuf[3] = hsdata3; /* Line 1766, Address: 0x1007ff4 */
    hdatabuf[4] = hsdata5; /* Line 1767, Address: 0x1008008 */
  } /* Line 1768, Address: 0x100801c */

} /* Line 1770, Address: 0x100802c */

void hscrl3() { /* Line 1772, Address: 0x1008040 */
  int lD0;
  int lD1;
  int i;


  for (i = 0; i < 3; ++i) { /* Line 1778, Address: 0x100804c */
    hscrspd_get(&lD0, &lD1); /* Line 1779, Address: 0x1008058 */
    hdatabuf[0] = hsdata1; /* Line 1780, Address: 0x1008068 */
    hdatabuf[1] = hsdata0; /* Line 1781, Address: 0x100807c */
    hdatabuf[2] = hsdata2; /* Line 1782, Address: 0x1008090 */
  } /* Line 1783, Address: 0x10080a4 */

} /* Line 1785, Address: 0x10080b4 */

void hscrl4() { /* Line 1787, Address: 0x10080d0 */
  hscal0_4(); /* Line 1788, Address: 0x10080d8 */
  hscal1_4(); /* Line 1789, Address: 0x10080e0 */
  hscal2_4(); /* Line 1790, Address: 0x10080e8 */

} /* Line 1792, Address: 0x10080f0 */

void hscrl5() { /* Line 1794, Address: 0x1008100 */
  hscal0_5(); /* Line 1795, Address: 0x1008108 */
  hscal1_5(); /* Line 1796, Address: 0x1008110 */
  hscal2_5(); /* Line 1797, Address: 0x1008118 */

} /* Line 1799, Address: 0x1008120 */

void hscrl6() { /* Line 1801, Address: 0x1008130 */
  int lD0;
  int lD1;
  int i;

  for (i = 0; i < 3; ++i) { /* Line 1806, Address: 0x100813c */
    lD0 = 524288; /* Line 1807, Address: 0x1008148 */
    lD1 = 98304; /* Line 1808, Address: 0x1008150 */
    rlspd_get(&lD0, &lD1); /* Line 1809, Address: 0x100815c */

    hsdata0 += lD0; /* Line 1811, Address: 0x100816c */
    lD0 -= lD1; /* Line 1812, Address: 0x1008184 */
    hsdata1 += lD0; /* Line 1813, Address: 0x1008194 */
    lD0 -= lD1; /* Line 1814, Address: 0x10081ac */
    hsdata2 += lD0; /* Line 1815, Address: 0x10081bc */
    lD0 -= lD1; /* Line 1816, Address: 0x10081d4 */
    hsdata3 += lD0; /* Line 1817, Address: 0x10081e4 */

    hdatabuf[0] = hsdata1; /* Line 1819, Address: 0x10081fc */
    hdatabuf[1] = hsdata3; /* Line 1820, Address: 0x1008210 */
    hdatabuf[2] = hsdata0; /* Line 1821, Address: 0x1008224 */
    hdatabuf[3] = hsdata2; /* Line 1822, Address: 0x1008238 */
  } /* Line 1823, Address: 0x100824c */

} /* Line 1825, Address: 0x100825c */



void hscrl7() {} /* Line 1829, Address: 0x1008270 */








void hscal() { /* Line 1838, Address: 0x1008280 */
  if (!scroll_stop) { /* Line 1839, Address: 0x1008288 */
    hscrltbl[stagenm](); /* Line 1840, Address: 0x1008298 */
  }

} /* Line 1843, Address: 0x10082c0 */







void colchg0() { /* Line 1851, Address: 0x10082d0 */
  unsigned short d0, d1, d5, d6, d7;
  palette_entry* lpPeDest;
  palette_entry dummy;
  int i;

  d5 = 8; /* Line 1857, Address: 0x10082f4 */
  d6 = 0; /* Line 1858, Address: 0x10082fc */
  d7 = 1000; /* Line 1859, Address: 0x1008300 */
  d0 = (short)cntplus((unsigned short*)clchgcnt, d5, d6, d7); /* Line 1860, Address: 0x1008308 */
  d0 &= 65520; /* Line 1861, Address: 0x1008334 */
  lpPeDest = &lpcolorwk[32]; /* Line 1862, Address: 0x100833c */
  for (i = 0; i < 16; ++i) { /* Line 1863, Address: 0x1008348 */
    d1 = cltbl[d0++]; /* Line 1864, Address: 0x1008354 */
    if (d1 > 16) d1 <<= 4; /* Line 1865, Address: 0x100837c */

    if (i == 0) d1 = 0; /* Line 1867, Address: 0x1008394 */
    dummy.peRed = (d1 & 15) << 4; /* Line 1868, Address: 0x10083a0 */
    dummy.peGreen = d1 & 240; /* Line 1869, Address: 0x10083b4 */
    dummy.peBlue = (d1 & 3840) >> 4; /* Line 1870, Address: 0x10083c4 */
    dummy.peFlags = 1; /* Line 1871, Address: 0x10083d8 */
    *lpPeDest++ = dummy; /* Line 1872, Address: 0x10083e0 */
  } /* Line 1873, Address: 0x100840c */
} /* Line 1874, Address: 0x100841c */


void colchg1() { /* Line 1877, Address: 0x1008450 */
  short d0;
  palette_entry* lpPeDest;
  palette_entry cltbl[8] = { /* Line 1880, Address: 0x1008460 */
    { 0, 0, 224, 1 }, { 0, 96, 224, 1 }, { 96, 160, 224, 1 }, { 160, 192, 224, 1 },
    { 0, 0, 224, 1 }, { 0, 96, 224, 1 }, { 96, 160, 224, 1 }, { 160, 192, 224, 1 }
  };
  int i;

  d0 = clchgcnt[0]++ & 3; /* Line 1886, Address: 0x1008494 */
  lpPeDest = &lpcolorwk[26]; /* Line 1887, Address: 0x10084c4 */

  for (i = 0; i < 4; ++i) { /* Line 1889, Address: 0x10084d0 */
    lpPeDest->peRed = cltbl[d0 + i].peRed; /* Line 1890, Address: 0x10084dc */
    lpPeDest->peGreen = cltbl[d0 + i].peGreen; /* Line 1891, Address: 0x10084f8 */
    lpPeDest->peBlue = cltbl[d0 + i].peBlue; /* Line 1892, Address: 0x1008514 */
  } /* Line 1893, Address: 0x1008530 */








} /* Line 1902, Address: 0x1008540 */

void colchg2() { /* Line 1904, Address: 0x1008560 */
  unsigned short d0, d5, d6, d7;
  palette_entry* lpPeDest;
  palette_entry cltbl0[24] = { /* Line 1907, Address: 0x100857c */
    {  0,   0, 224, 1 }, { 32,  64, 224, 1 }, { 64, 128, 224, 1 }, { 64, 192, 224, 1 },
    { 32,  64, 224, 1 }, {  0,   0, 224, 1 }, { 64, 192, 224, 1 }, { 64, 128, 224, 1 },
    { 64, 128, 224, 1 }, { 32,  64, 224, 1 }, { 64, 128, 224, 1 }, { 32,  64, 224, 1 },
    { 64, 192, 224, 1 }, { 64, 128, 224, 1 }, { 32,  64, 224, 1 }, {  0,   0, 224, 1 },
    { 64, 128, 224, 1 }, { 64, 192, 224, 1 }, {  0,   0, 224, 1 }, { 32,  64, 224, 1 },
    { 32,  64, 224, 1 }, { 64, 128, 224, 1 }, { 32,  64, 224, 1 }, { 64, 128, 224, 1 }
  };
  palette_entry cltbl1[6] = { /* Line 1915, Address: 0x10085b0 */
    { 0, 0, 224, 1 }, { 96, 192, 224, 1 }, {  0, 128, 224, 1 },
    { 0, 0, 224, 1 }, {  0, 128, 224, 1 }, { 96, 192, 224, 1 }
  };
  d5 = 2; /* Line 1919, Address: 0x10085e4 */
  d6 = 0; /* Line 1920, Address: 0x10085ec */
  d7 = 46; /* Line 1921, Address: 0x10085f0 */
  d0 = (short)cntplus((unsigned short*)clchgcnt, d5, d6, d7); /* Line 1922, Address: 0x10085f8 */
  d0 &= 65528; /* Line 1923, Address: 0x1008624 */
  d0 >>= 1; /* Line 1924, Address: 0x100862c */
  lpPeDest = &lpcolorwk[26]; /* Line 1925, Address: 0x1008634 */
  *lpPeDest++ = cltbl0[d0]; /* Line 1926, Address: 0x1008640 */
  *lpPeDest++ = cltbl0[d0 + 1]; /* Line 1927, Address: 0x1008678 */
  *lpPeDest++ = cltbl0[d0 + 2]; /* Line 1928, Address: 0x10086b4 */
  *lpPeDest = cltbl0[d0 + 3]; /* Line 1929, Address: 0x10086f0 */

  d5 = 1; /* Line 1931, Address: 0x1008724 */
  d6 = 0; /* Line 1932, Address: 0x100872c */
  d7 = 4; /* Line 1933, Address: 0x1008730 */
  d0 = (short)cntplus((unsigned short*)clchgcnt, d5, d6, d7); /* Line 1934, Address: 0x1008738 */
  if (d0 >> 1 != 0) return; /* Line 1935, Address: 0x1008764 */
  d5 = 2; /* Line 1936, Address: 0x1008774 */
  d6 = 0; /* Line 1937, Address: 0x100877c */
  d7 = 10; /* Line 1938, Address: 0x1008780 */
  d0 = (short)cntplus((unsigned short*)clchgcnt, d5, d6, d7); /* Line 1939, Address: 0x1008788 */
  d0 >>= 1; /* Line 1940, Address: 0x10087b4 */
  lpPeDest = &lpcolorwk[33]; /* Line 1941, Address: 0x10087bc */
  *lpPeDest = cltbl1[d0]; /* Line 1942, Address: 0x10087c8 */
} /* Line 1943, Address: 0x10087f8 */

void colchg3() { /* Line 1945, Address: 0x1008820 */
  short d0, d5, d6, d7;
  palette_entry* lpPeDest;
  palette_entry cltbl0[16] = { /* Line 1948, Address: 0x100883c */
    {  0,  32, 224, 1 }, { 32,  64, 224, 1 }, { 64, 128, 224, 1 }, { 64, 192, 224, 1 },
    { 64, 192, 224, 1 }, {  0,  32, 224, 1 }, { 32,  64, 224, 1 }, { 64, 128, 224, 1 },
    { 64, 128, 224, 1 }, { 64, 192, 224, 1 }, {  0,  32, 224, 1 }, { 32,  64, 224, 1 },
    { 32,  64, 224, 1 }, { 64, 128, 224, 1 }, { 64, 192, 224, 1 }, {  0,  32, 224, 1 }
  };
  palette_entry cltbl1[8] = { /* Line 1954, Address: 0x1008870 */
    {  96, 192, 224, 1 }, { 128, 224, 224, 1 }, { 160, 224, 224, 1 }, { 192, 224, 224, 1 },
    { 224, 224, 224, 1 }, { 192, 224, 224, 1 }, { 160, 224, 224, 1 }, { 128, 224, 224, 1 }
  };
  d0 = clchgcnt[0]; /* Line 1958, Address: 0x10088a4 */
  clchgcnt[0] += 2; /* Line 1959, Address: 0x10088b4 */
  d0 &= 24; /* Line 1960, Address: 0x10088c8 */
  d0 >>= 1; /* Line 1961, Address: 0x10088d4 */
  lpPeDest = &lpcolorwk[26]; /* Line 1962, Address: 0x10088e0 */
  *lpPeDest++ = cltbl0[d0]; /* Line 1963, Address: 0x10088ec */
  *lpPeDest++ = cltbl0[d0 + 1]; /* Line 1964, Address: 0x1008928 */
  *lpPeDest++ = cltbl0[d0 + 2]; /* Line 1965, Address: 0x1008968 */
  *lpPeDest = cltbl0[d0 + 3]; /* Line 1966, Address: 0x10089a8 */

  d5 = 1; /* Line 1968, Address: 0x10089e0 */
  d6 = 0; /* Line 1969, Address: 0x10089ec */
  d7 = 2; /* Line 1970, Address: 0x10089f0 */
  d0 = (short)cntplus((unsigned short*)clchgcnt, (unsigned short)d5, (unsigned short)d6, (unsigned short)d7); /* Line 1971, Address: 0x10089fc */
  if (d0) return; /* Line 1972, Address: 0x1008a28 */

  d0 = clchgcnt[2]; /* Line 1974, Address: 0x1008a30 */
  clchgcnt[2] += 2; /* Line 1975, Address: 0x1008a40 */
  d0 &= 14; /* Line 1976, Address: 0x1008a54 */
  d0 >>= 1; /* Line 1977, Address: 0x1008a60 */

  lpPeDest = &lpcolorwk[40]; /* Line 1979, Address: 0x1008a6c */
  *lpPeDest++ = cltbl1[d0]; /* Line 1980, Address: 0x1008a78 */
} /* Line 1981, Address: 0x1008ab4 */

void colchg4() { /* Line 1983, Address: 0x1008ae0 */
  palette_entry tbl0[7] = { /* Line 1984, Address: 0x1008afc */
    { 0,  32, 224, 1 }, { 0,  64, 224, 1 }, { 0, 96, 224, 1 }, { 0, 128, 224, 1 },
    { 0, 160, 224, 1 }, { 0, 128, 224, 1 }, { 0, 96, 224, 1 }
  };
  palette_entry tbl1[26] = { /* Line 1988, Address: 0x1008b30 */
    { 224, 224,   0, 1 }, { 192, 224,   0, 1 }, { 160, 224,   0, 1 }, { 128, 224,   0, 1 },
    {  96, 224,   0, 1 }, {  64, 224,   0, 1 }, {  32, 224,   0, 1 }, {   0, 224,  32, 1 },
    {   0, 224,  64, 1 }, {   0, 224,  96, 1 }, {   0, 224, 128, 1 }, {   0, 224, 160, 1 },
    {   0, 224, 192, 1 }, {   0, 224, 224, 1 }, {   0, 224, 192, 1 }, {   0, 224, 160, 1 },
    {   0, 224, 128, 1 }, {   0, 224,  96, 1 }, {   0, 224,  64, 1 }, {   0, 224,  32, 1 },
    {  32, 224,   0, 1 }, {  64, 224,   0, 1 }, {  96, 224,   0, 1 }, { 128, 224,   0, 1 },
    { 160, 224,   0, 1 }, { 192, 224,   0, 1 }
  };
  palette_entry tbl2[26] = { /* Line 1997, Address: 0x1008b64 */
    {   0, 224, 224, 1 }, {   0, 224, 192, 1 }, {   0, 224, 160, 1 }, {   0, 224, 128, 1 },
    {   0, 224,  96, 1 }, {   0, 224,  64, 1 }, {   0, 224,  32, 1 }, {  32, 224,   0, 1 },
    {  64, 224,   0, 1 }, {  96, 224,   0, 1 }, { 128, 224,   0, 1 }, { 160, 224,   0, 1 },
    { 192, 224,   0, 1 }, { 224, 224,   0, 1 }, { 192, 224,   0, 1 }, { 160, 224,   0, 1 },
    { 128, 224,   0, 1 }, {  96, 224,   0, 1 }, {  64, 224,   0, 1 }, {  32, 224,   0, 1 },
    {   0, 224,  32, 1 }, {   0, 224,  64, 1 }, {   0, 224,  96, 1 }, {   0, 224, 128, 1 },
    {   0, 224, 160, 1 }, {   0, 224, 192, 1 }
  };
  palette_entry tbl3[28] = { /* Line 2006, Address: 0x1008b98 */
    { 224, 0, 0, 1 }, { 192, 0, 0, 1 }, { 160, 0, 0, 1 }, { 128, 0, 0, 1 },
    { 96, 0, 0, 1 }, { 64, 0, 0, 1 }, { 32, 0, 0, 1 }, { 0, 0, 0, 1 },
    { 32, 0, 0, 1 }, { 64, 0, 0, 1 }, { 96, 0, 0, 1 }, { 128, 0, 0, 1 },
    { 160, 0, 0, 1 }, { 192, 0, 0, 1 }, { 224, 0, 0, 1 }, { 192, 0, 0, 1 },
    { 160, 0, 0, 1 }, { 128, 0, 0, 1 }, { 96, 0, 0, 1 }, { 64, 0, 0, 1 },
    { 32, 0, 0, 1 }, { 0, 0, 0, 1 }, { 32, 0, 0, 1 }, { 64, 0, 0, 1 },
    { 96, 0, 0, 1 }, { 128, 0, 0, 1 }, { 160, 0, 0, 1 }, { 192, 0, 0, 1 }
  };
  unsigned short d0, d5, d6, d7;
  palette_entry* lpPeDest;

  d5 = 2; /* Line 2018, Address: 0x1008bcc */
  d6 = 0; /* Line 2019, Address: 0x1008bd4 */
  d7 = 12; /* Line 2020, Address: 0x1008bd8 */
  d0 = (short)cntplus((unsigned short*)clchgcnt, d5, d6, d7); /* Line 2021, Address: 0x1008be0 */
  d0 >>= 1; /* Line 2022, Address: 0x1008c0c */
  lpPeDest = &lpcolorwk[26]; /* Line 2023, Address: 0x1008c14 */
  *lpPeDest = tbl0[d0]; /* Line 2024, Address: 0x1008c20 */

  d5 = 2; /* Line 2026, Address: 0x1008c50 */
  d6 = 0; /* Line 2027, Address: 0x1008c58 */
  d7 = 50; /* Line 2028, Address: 0x1008c5c */
  d0 = (short)cntplus((unsigned short*)clchgcnt, d5, d6, d7); /* Line 2029, Address: 0x1008c64 */
  d0 >>= 1; /* Line 2030, Address: 0x1008c90 */
  lpPeDest = &lpcolorwk[45]; /* Line 2031, Address: 0x1008c98 */
  *lpPeDest = tbl1[d0]; /* Line 2032, Address: 0x1008ca4 */

  d5 = 1; /* Line 2034, Address: 0x1008cd4 */
  d6 = 0; /* Line 2035, Address: 0x1008cdc */
  d7 = 51; /* Line 2036, Address: 0x1008ce0 */
  d0 = (short)cntplus((unsigned short*)clchgcnt, d5, d6, d7); /* Line 2037, Address: 0x1008ce8 */
  d0 >>= 1; /* Line 2038, Address: 0x1008d14 */
  lpPeDest = &lpcolorwk[46]; /* Line 2039, Address: 0x1008d1c */
  *lpPeDest = tbl2[d0]; /* Line 2040, Address: 0x1008d28 */

  d5 = 1; /* Line 2042, Address: 0x1008d58 */
  d6 = 0; /* Line 2043, Address: 0x1008d60 */
  d7 = 55; /* Line 2044, Address: 0x1008d64 */
  d0 = (short)(cntplus((unsigned short*)clchgcnt, d5, d6, d7) & 65534U); /* Line 2045, Address: 0x1008d6c */
  d0 >>= 1; /* Line 2046, Address: 0x1008da0 */
  lpPeDest = &lpcolorwk[47]; /* Line 2047, Address: 0x1008da8 */
  *lpPeDest = tbl3[d0]; /* Line 2048, Address: 0x1008db4 */
} /* Line 2049, Address: 0x1008de4 */

void colchg5() { /* Line 2051, Address: 0x1008e10 */
  unsigned short d0, d5, d6, d7;
  palette_entry* lpPeDest;
  short i;
  static palette_entry tbl0[26] = {
    { 224,  64,   0, 1 }, { 224, 128,   0, 1 }, { 224, 192,   0, 1 }, { 160, 224,  64, 1 },
    { 128, 224, 128, 1 }, {  64, 224, 192, 1 }, {  64, 160, 224, 1 }, { 128,  96, 224, 1 },
    { 160,   0, 224, 1 }, { 224,  32, 224, 1 }, { 224,   0, 160, 1 }, { 224,   0,  96, 1 },
    { 224,   0,  32, 1 }, { 224,  64,   0, 1 }, { 224, 128,   0, 1 }, { 224, 192,   0, 1 },
    { 160, 224,  64, 1 }, { 128, 224, 128, 1 }, {  64, 224, 192, 1 }, {  64, 160, 224, 1 },
    { 128,  96, 224, 1 }, { 160,   0, 224, 1 }, { 224,  32, 224, 1 }, { 224,   0, 160, 1 },
    { 224,   0,  96, 1 }, { 224,   0,  32, 1 }
  };
  static palette_entry tbl1[12] = {
    {  0,  0, 224, 1 }, { 64, 0, 32, 1 }, {  0, 32, 224, 1 }, { 96, 0, 64, 1 },
    { 32, 64, 224, 1 }, { 64, 0, 32, 1 }, { 64, 96, 224, 1 }, { 32, 0, 0, 1 },
    { 32, 64, 224, 1 }, {  0, 0,  0, 1 }, {  0, 32, 224, 1 }, { 32, 0, 0, 1 }
  };

  d5 = 2; /* Line 2070, Address: 0x1008e30 */
  d6 = 0; /* Line 2071, Address: 0x1008e38 */
  d7 = 24; /* Line 2072, Address: 0x1008e3c */
  d0 = (short)(cntplus((unsigned short*)clchgcnt, d5, d6, d7) & 65534U); /* Line 2073, Address: 0x1008e44 */

  d0 >>= 1; /* Line 2075, Address: 0x1008e78 */
  lpPeDest = &lpcolorwk[33]; /* Line 2076, Address: 0x1008e80 */

  for (i = 0; i < 12; ++i) { /* Line 2078, Address: 0x1008e8c */
    *lpPeDest++ = tbl0[d0++]; /* Line 2079, Address: 0x1008e98 */
  } /* Line 2080, Address: 0x1008ee0 */
  d5 = 2; /* Line 2081, Address: 0x1008f00 */
  d6 = 0; /* Line 2082, Address: 0x1008f08 */
  d7 = 22; /* Line 2083, Address: 0x1008f0c */
  d0 = (short)(cntplus((unsigned short*)clchgcnt, d5, d6, d7) & 65532U); /* Line 2084, Address: 0x1008f14 */
  d0 >>= 1; /* Line 2085, Address: 0x1008f48 */
  lpPeDest = &lpcolorwk[29]; /* Line 2086, Address: 0x1008f50 */
  *lpPeDest++ = tbl1[d0++]; /* Line 2087, Address: 0x1008f5c */
  *lpPeDest = tbl1[d0]; /* Line 2088, Address: 0x1008fa4 */
} /* Line 2089, Address: 0x1008fd8 */



void colchg6() { /* Line 2093, Address: 0x1009000 */
  palette_entry tbl[12] = { /* Line 2094, Address: 0x100901c */
    { 0, 32, 192, 1 }, { 0, 32, 192, 1 }, { 0,  64, 224, 1 }, { 0,  64, 224, 1 },
    { 0, 96, 224, 1 }, { 0, 96, 224, 1 }, { 0, 128, 224, 1 }, { 0, 128, 224, 1 },
    { 0, 96, 224, 1 }, { 0, 96, 224, 1 }, { 0,  64, 224, 1 }, { 0,  64, 224, 1 }
  };
  unsigned short d0, d5, d6, d7;
  palette_entry* lpPeDest;

  d5 = 1; /* Line 2102, Address: 0x1009050 */
  d6 = 0; /* Line 2103, Address: 0x1009058 */
  d7 = 23; /* Line 2104, Address: 0x100905c */
  d0 = (short)(cntplus((unsigned short*)clchgcnt, d5, d6, d7) & 65534U); /* Line 2105, Address: 0x1009064 */
  d0 >>= 1; /* Line 2106, Address: 0x1009098 */
  lpPeDest = &lpcolorwk[31]; /* Line 2107, Address: 0x10090a0 */
  *lpPeDest = tbl[d0]; /* Line 2108, Address: 0x10090ac */
} /* Line 2109, Address: 0x10090dc */



void colchg7() {} /* Line 2113, Address: 0x1009100 */

void color_change() { /* Line 2115, Address: 0x1009110 */
  void(*jptbl[8])() = { /* Line 2116, Address: 0x1009118 */
    &colchg0, &colchg1, &colchg2, &colchg3, &colchg4, &colchg5, &colchg6, colchg7
  };

  jptbl[stagenm](); /* Line 2120, Address: 0x100914c */
} /* Line 2121, Address: 0x100916c */
