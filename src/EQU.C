typedef struct spr_array;
typedef struct tagPALETTEENTRY;
typedef struct act_info;
typedef struct game_info;
typedef struct aset_info;
typedef struct asetz_info;
typedef struct act_info_array;
typedef union int_union;
typedef struct int_shorts;
typedef struct int_chars;
typedef union short_union;
typedef struct short_chars;
typedef union uint_union;
typedef struct uint_ushorts;
typedef struct uint_uchars;
typedef union ushort_union;
typedef struct ushort_uchars;
typedef struct spr_info;

struct spr_array
{
  unsigned char cnt;
  union
  {
    spr_info spra[20];
    spr_info spr[0];
  };
};

struct tagPALETTEENTRY
{
  unsigned char peRed;
  unsigned char peGreen;
  unsigned char peBlue;
  unsigned char peFlags;
};

struct act_info
{
  unsigned char actno;
  unsigned char actflg;
  unsigned short sproffset;
  spr_array** patbase;
  int_union xposi;
  int_union yposi;
  short_union xspeed;
  short_union yspeed;
  short_union mspeed;
  unsigned char sprhsize;
  unsigned char sprvsize;
  unsigned char sprhs;
  unsigned char sprpri;
  unsigned char patno;
  short_union mstno;
  unsigned char patcnt;
  unsigned char pattim;
  unsigned char pattimm;
  unsigned char colino;
  unsigned char colicnt;
  unsigned char cddat;
  unsigned char cdsts;
  unsigned char r_no0;
  unsigned char r_no1;
  short_union direc;
  short_union userflag;
  unsigned char dummy[2];
  unsigned char actfree[22];
};

struct game_info
{
  short plring;
  int plscore;
  short_union stageno;
  unsigned int TimeWarp;
  void* pSprBmp;
  unsigned int GamePass;
  unsigned char play_start;
  unsigned char pl_suu;
  unsigned char generate_flag;
  unsigned char time_flag;
  unsigned char special_flag;
  int pltime_sb;
  short plxposi_sb;
  short plyposi_sb;
  short scralim_down_sb;
  short scra_h_posit_sb;
  short scra_v_posit_sb;
  short scrb_h_posit_sb;
  short scrb_v_posit_sb;
  short scrc_h_posit_sb;
  short scrc_v_posit_sb;
  short scrz_h_posit_sb;
  short scrz_v_posit_sb;
  short waterposi_m_sb;
  short plmspd_sb;
  short plxspd_sb;
  short plyspd_sb;
  unsigned char plflag_sb;
  unsigned char cddat_sb;
  unsigned char water_flag_sb;
  unsigned char waterflag_sb;
  unsigned char chibi_sb;
  unsigned char prio_sb;
  short plring_s;
  unsigned char plring_f2_s;
  unsigned char plflag;
  short_union demoflag;
  short_union hintposi;
  unsigned char waterflag;
  unsigned short* ptv_adr;
  unsigned short* sm_adr0;
  int SPEMode;
  unsigned char stagenm;
  unsigned char clrspflg_save;
  unsigned char ta_flag;
  unsigned char gf_flag;
  unsigned char projector_flag;
  unsigned char flagworkcnt;
  unsigned char flagworkcnt2;
  unsigned char flagwork[766];
  unsigned int ta_time;
  unsigned char ta_Menu1;
  unsigned char ta_Round;
  unsigned char ta_Zone;
  unsigned char EndingMesType;
  int extrascore;
  unsigned char emie3end;
  unsigned char SpecialTime;
  unsigned char bRestart;
  unsigned char User;
  unsigned short wReserved1;
  unsigned short wReserved2;
};

struct aset_info
{
  unsigned short x;
  unsigned short y;
  unsigned char a;
  unsigned char b;
  unsigned char c;
  unsigned char d;
};

struct asetz_info
{
  unsigned short x;
  unsigned short y;
  unsigned char a;
  unsigned char b;
};

struct act_info_array
{
  int cnt;
  act_info* pActwk[63];
};

union int_union
{
  int l;
  int_shorts w;
  int_chars b;
};

struct int_shorts
{
  short l;
  short h;
};

struct int_chars
{
  char b4;
  char b3;
  char b2;
  char b1;
};

union short_union
{
  short w;
  short_chars b;
};

struct short_chars
{
  char l;
  char h;
};

union uint_union
{
  unsigned int l;
  uint_ushorts w;
  uint_uchars b;
};

struct uint_ushorts
{
  unsigned short l;
  unsigned short h;
};

struct uint_uchars
{
  unsigned char b4;
  unsigned char b3;
  unsigned char b2;
  unsigned char b1;
};

union ushort_union
{
  unsigned short w;
  ushort_uchars b;
};

struct ushort_uchars
{
  unsigned char l;
  unsigned char h;
};

struct spr_info
{
  char xoff;
  char yoff;
  unsigned char etc;
  unsigned short index;
};

unsigned char ta_flag;
unsigned char clrspflg_save;
unsigned char flagworkcnt;
unsigned char flagworkcnt2;
unsigned char play_status;
unsigned char pl_suu;
unsigned char main_play;
short pl_air;
unsigned char pltimeover_f;
unsigned char plring_f2;
unsigned char pl_suu_f;
unsigned char plring_f;
unsigned char pltime_f;
unsigned char plscore_f;
short plring;
int plscore;
unsigned char play_start;
unsigned char start_flag;
unsigned char plpower_b;
unsigned char plpower_m;
unsigned char plpower_s;
unsigned char plpower_a;
unsigned char plflag;
unsigned char plflag_s;
short plxposi_s;
short plyposi_s;
short plring_s;
int pltime_s;
unsigned char time_flag;
short scralim_down_s;
short scra_h_posit_s;
short scra_v_posit_s;
short scrb_h_posit_s;
short scrb_v_posit_s;
short scrc_h_posit_s;
short scrc_v_posit_s;
short scrz_h_posit_s;
short scrz_v_posit_s;
short waterposi_m_s;
unsigned char water_flag_s;
unsigned char waterflag_s;
unsigned char plring_f2_s;
unsigned char generate_flag;
unsigned char plsubchg_flag;
unsigned char enkeino;
unsigned char projector_flag;
unsigned char special_flag;
unsigned char conbine_flag;
unsigned char enecgflg;
unsigned char enecgpnt;
unsigned char emie3end;
int extrascore;
short demono;
short enddemono;
unsigned char mdstatus;
unsigned int resetflg;
unsigned char markerno;
unsigned char colrevflag;
unsigned char gf_flag;
unsigned char chibi_s;
unsigned char prio_s;
unsigned char tv_flag;
short edittimer;
short time_stop;
unsigned char sys_pattim;
unsigned char sys_patno;
unsigned char sys_pattim2;
unsigned char sys_patno2;
unsigned char sys_pattim3;
unsigned char sys_patno3;
unsigned char sys_pattim4;
unsigned char sys_patno4;
short sys_ringtimer;
short editstack;
short editstack2;
short mapcheck;
short blkno;
unsigned char edit_user;
unsigned char sysdirec;
unsigned char prio_flag;
unsigned char init_flag;
unsigned char boss_sound;
unsigned char shut_flag;
unsigned char st6clrchg;
unsigned char chibi_flag;
unsigned char mapwrt_cnt;
unsigned int sbufadr;
int stacksave;
short sprpage;
short waittimer;
unsigned char startcolor;
unsigned char colorcnt;
unsigned char int_flg;
unsigned char linkdata;
int cltbladr;
int ranum;
short cgwrtcnt;
short cgwrttim;
int dmastack;
short waterposi;
short waterposi_m;
short watermoveposi;
unsigned char waterspeed;
unsigned char water_flag;
unsigned char waterflag;
unsigned char waterflag2;
unsigned short bitdevadr;
short bitdevcnt;
short bitdevcnt2;
unsigned short hintflag;
short scralim_n_left;
short scralim_n_right;
short scralim_n_up;
short scralim_n_down;
short scralim_left;
short scralim_right;
short scralim_up;
short scralim_down;
short scrar_no;
short scra_h_keep;
short scra_v_keep;
short scra_hz;
short scra_vz;
short scra_vline;
unsigned char scrh_flag;
unsigned char scrv_flag;
unsigned char scra_h_count;
unsigned char scra_v_count;
unsigned char scrb_h_count;
unsigned char scrb_v_count;
unsigned char scrc_h_count;
unsigned char scrc_v_count;
unsigned char scrz_h_count;
unsigned char scrz_v_count;
unsigned char limmoveflag;
unsigned char playpatno1;
unsigned char kusya_flag;
short plmaxspdwk;
short pladdspdwk;
short plretspdwk;
unsigned char playpatno;
unsigned char playwrtflag;
short asetposi;
char time_item;
short backto_cnt;
unsigned char scr_cnt;
unsigned int demo_adr;
short demo_cnt;
short swbufcnt;
short scra_hline;
unsigned char bossflag;
unsigned char bossstart;
unsigned char loopmapno;
unsigned char loopmapno2;
unsigned char ballmapno;
unsigned char ballmapno2;
unsigned char watercoliflag;
unsigned char waterstop;
unsigned char mizuflag;
unsigned char sekichyuflag;
unsigned char plautoflag;
unsigned char specflag;
unsigned char dai2rmvflag;
short emyscorecnt;
short timebonus;
short ringbonus;
unsigned char bonus_f;
unsigned char edplayflag;
unsigned char ms_wflg;
game_info* lpKeepWork;
int* lpFadeFlag;
tagPALETTEENTRY* lpcolorwk4;
tagPALETTEENTRY* lpcolorwk3;
tagPALETTEENTRY* lpcolorwk2;
tagPALETTEENTRY* lpcolorwk;
unsigned char switchflag[32];
short_union waterdirec;
unsigned char clchgtim[7];
unsigned char clchgcnt[7];
ushort_union plposiwkadr;
unsigned char* scdadr;
short_union byecnt1;
short_union byecnt0;
asetz_info* asetadrz2;
asetz_info* asetadrz;
aset_info* asetadr2;
aset_info* asetadr;
short_union actset_rno;
char dirstk[4];
ushort_union scrflagz;
ushort_union scrflagc;
ushort_union scrflagb;
ushort_union scrflaga;
short_union scr_timer;
ushort_union scr_die;
short_union scroll_start;
ushort_union zone_flag;
int_union scrz_v_posit;
int_union scrz_h_posit;
int_union scrc_v_posit;
int_union scrc_h_posit;
int_union scrb_v_posit;
int_union scrb_h_posit;
int_union scra_v_posit;
int_union scra_h_posit;
unsigned int divdevwk[24];
unsigned char cgchgtim[6];
unsigned char cgchgcnt[6];
ushort_union pauseflag;
short_union intcnt;
short_union hintposi;
int_union hscroll;
int_union vscroll;
ushort_union swdata2;
ushort_union swdata1;
ushort_union swdata;
short_union gmmode;
act_info actwk[128];
int_union* lphscrollbuff;
short playposiwk[128];
act_info_array pbuffer[8];
short hscrollwork[256];
unsigned char flowwk[4096];
unsigned short blockwk[4][1024];
unsigned short* pmapwk;
int linework[128];
short_union col_x;
short_union col_y;
ushort_union scrflagzw;
ushort_union scrflagcw;
ushort_union scrflagbw;
ushort_union scrflagaw;
int_union scrz_v_posiw;
int_union scrz_h_posiw;
int_union scrc_v_posiw;
int_union scrc_h_posiw;
int_union scrb_v_posiw;
int_union scrb_h_posiw;
int_union scra_v_posiw;
int_union scra_h_posiw;
int_union systemtimer;
short_union editmode;
short_union editno;
unsigned char flowercnt[3];
int_union flowerposi[192];
short_union debugflag;
short_union demoflag;
uint_union debugwork;
int_union pltime;
short_union stageno;
short_union gametimer;
short_union gameflag;
unsigned char flagwork[766];
