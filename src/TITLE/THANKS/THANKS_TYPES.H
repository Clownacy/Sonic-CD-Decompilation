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
  unsigned char free[8];
}
sprite_status_thanks;

typedef struct {
  short pts;
  char name[4];
}
high_score_entry;
