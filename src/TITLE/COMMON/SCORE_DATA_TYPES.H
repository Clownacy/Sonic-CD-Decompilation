#ifndef SCORE_DATA_TYPES_H
#define SCORE_DATA_TYPES_H

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
