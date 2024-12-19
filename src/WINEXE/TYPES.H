#ifndef TYPES_H
#define TYPES_H

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
  unsigned int time;
  char name[4];
}
time_data;

typedef struct {
  unsigned int saved;
  char player[12];
  unsigned int roundNo;
  unsigned short year;
  unsigned short month;
  unsigned short date;
  unsigned short hour;
  unsigned short min;
  unsigned short sec;
  time_data timeattack[7][3][3];
  time_data special[7][3];
  unsigned int total;
  unsigned char clrspflg_save;
  unsigned char clrgood;
  unsigned char stagenm;
  unsigned char reserved1;
  unsigned char reserved2;
  unsigned int checkSum;
}
score_data;

#endif
