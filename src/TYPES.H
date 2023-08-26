typedef struct {
  char l;
  char h;
}
short_chars;

typedef union {
  short w;
  short_chars b;
}
short_union;

typedef struct {
  short l;
  short h;
}
int_shorts;

typedef struct {
  char b4;
  char b3;
  char b2;
  char b1;
}
int_chars;

typedef union {
  int l;
  int_shorts w;
  int_chars b;
}
int_union;

typedef struct {
  unsigned char l;
  unsigned char h;
}
ushort_uchars;

typedef union {
  unsigned short w;
  ushort_uchars b;
}
ushort_union;

typedef struct {
  unsigned short l;
  unsigned short h;
}
uint_ushorts;

typedef struct {
  unsigned char b4;
  unsigned char b3;
  unsigned char b2;
  unsigned char b1;
}
uint_uchars;

typedef union {
  unsigned int l;
  uint_ushorts w;
  uint_uchars b;
}
uint_union;

typedef struct {
  char xoff;
  char yoff;
  unsigned char etc;
  unsigned short index;
}
spr_info;

typedef struct {
  unsigned char cnt;
  union {
    spr_info spra[20];
    spr_info spr[];
  };
}
spr_array;

typedef struct {
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
}
game_info;

typedef struct {
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
}
act_info;

typedef struct {
  int cnt;
  act_info* pActwk[63];
}
act_info_array;

typedef struct {
  unsigned short x;
  unsigned short y;
  unsigned char a;
  unsigned char b;
  unsigned char c;
  unsigned char d;
}
aset_info;

typedef struct {
  unsigned short x;
  unsigned short y;
  unsigned char a;
  unsigned char b;
}
asetz_info;

typedef struct {
  unsigned char xs;
  unsigned char ys;
  unsigned char ofs;
}
bmp_info;

struct brankodata {
  short angle;
  short accel;
  short area1;
  short area2;
};

typedef struct dlink_export {
  void(*game_init)();
  void(*game)();
  void(*dll_meminit)(char***, void**);
  void(*dll_memfree)();
  void(*SWdataSet)(short, short);
  int(*Get_vscroll)();
  int(*Get_scra_h_posiw)();
  int(*Get_scrb_h_posiw)();
  int(*FadeProc)();
  void(*SetDebugFlag)(unsigned int);
  void(*GetRoundStr)(unsigned short, unsigned char, char*);
  void(*Special_block_chg)(unsigned short*, unsigned short*, unsigned short*, unsigned short*);
}
dlink_export;

typedef struct {
  unsigned char actno;
  unsigned char sprpri;
  spr_array** patbase;
  unsigned short offset;
  unsigned char userflag_h;
  unsigned char rludrv;
  unsigned char userflag_l;
  unsigned char patno;
}
edit_info;

typedef struct {
  char num;
  char dummy;
  edit_info dat[];
}
edit_info_array;

typedef struct {
  unsigned char* CGdata;
  unsigned char* Blkdata;
  unsigned char* Mapdata;
  unsigned char iniCGno1;
  unsigned char stCGno1;
  unsigned char iniCGno2;
  unsigned char stCGno2;
  unsigned char colorno1;
  unsigned char colorno2;
  unsigned char soundNo;
}
map_info;

typedef struct tagPALETTEENTRY {
  unsigned char peRed;
  unsigned char peGreen;
  unsigned char peBlue;
  unsigned char peFlags;
}
palette_entry;

typedef struct {
  palette_entry* PeSrc;
  short offset;
  short cnt;
}
palette_part;

typedef struct tagPOINT {
  int x;
  int y;
}
point;
