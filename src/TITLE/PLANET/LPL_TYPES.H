#include "..\COMMON\SPRITE_PATTERN_TYPES.H"

typedef struct {
  unsigned short ACT_NO;
  unsigned short EXE_NO;
  int_union XPOSI;
  int_union YPOSI;
  int_union X_SPEED;
  int_union Y_SPEED;
  int_union X_ACCEL;
  int_union Y_ACCEL;
  short X_OFFSET;
  short Y_OFFSET;
  short SIN_CNT;
  short TM_CNT;
  short SPR_TIMER;
  short PAT_NO;
  short CGBASE;
  sprite_patterns_title* PAT_ADR;
  unsigned char SPR_FLG;
  unsigned char ACT_FLG;
  short END_XPOSI;
  short END_YPOSI;
  short X_WIDE;
  short Y_WIDE;
  unsigned char timer1;
  unsigned char timer2;
}
sprite_status_lpl;

typedef struct {
  short number;
  short* inipat;
}
ini_pats;

typedef struct {
  unsigned char mcntflg;
  unsigned char dummy;
  unsigned char* copy_adr;
  unsigned short copy_size;
  unsigned char* pc_adr;
  unsigned char* user_hint;
  unsigned char* user_vint;
}
mcnt_info;

typedef union {
  unsigned char* wordram;
  mcnt_info mcntwk;
}
wordram_info;

typedef struct {
  unsigned int On;
  unsigned int Press;
  unsigned int Release;
  short X1;
  short Y1;
  short X2;
  short Y2;
}
pad_status;

typedef struct {
  short x;
  short y;
  short z;
  short az;
  short sz;
  short cz;
  short xscale;
  short yscale;
}
zoom_info_lpl;

typedef struct {
  short k_sin;
  short k_cos;
  short k_rx;
  short k_ry;
  short k_s;
  short k_msx;
  short k_msy;
  short k_dx;
  short k_dy;
  short k_x_rx;
  short k_y_ry;
  int k_xt_c;
  int k_yt_c;
  short k_s2;
  short k_eyelen;
}
rotate_1;

typedef struct {
  short actno;
  unsigned char actflg;
  unsigned char ACT_NO;
  short spdcnt;
  short k_kaku;
  short x_kaku;
  int_union x_posi;
  int_union y_posi;
  int_union z_posi;
  int_union k_speed;
  int_union x_speed;
  int_union y_speed;
  int_union z_speed;
}
rotate_2;
