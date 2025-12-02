#include "szdd.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "constants.h"
#include "util.h"


unsigned char* szdd_decompress(char* p_filename) {
  unsigned char* p_decompressed = 0;
  unsigned long decompressed_cnt = 0;
  unsigned char buffer[4];
  unsigned int decompressed_pos = 0;
  unsigned char dictionary[SZDD_DICTIONARY_SIZE];
  unsigned int literal_pos = SZDD_DICTIONARY_SIZE - 16;
  FILE* fp = fopen(p_filename, "rb");

  if (fp == 0) return 0;
  if (fgetc(fp) != 'S') return 0; // magic
  if (fgetc(fp) != 'Z') return 0;
  if (fgetc(fp) != 'D') return 0;
  if (fgetc(fp) != 'D') return 0;
  if (fgetc(fp) != 0x88) return 0;
  if (fgetc(fp) != 0xF0) return 0;
  if (fgetc(fp) != 0x27) return 0;
  if (fgetc(fp) != 0x33) return 0;
  if (fgetc(fp) != 'A') return 0; // mode
  fgetc(fp); // last character of filename

  fread(buffer, 1, 4, fp);
  read_ulong_littleendian(buffer, &decompressed_cnt);
  p_decompressed = malloc(decompressed_cnt);
  memset(dictionary, ' ', SZDD_DICTIONARY_SIZE);

  do {
    unsigned int control = fgetc(fp);
    if (feof(fp)) break;

    for (unsigned int bit = 1; bit & 0xFF; bit <<= 1) {
      if (control & bit) {
        p_decompressed[decompressed_pos] = dictionary[literal_pos] = fgetc(fp);
        if (feof(fp)) break;
        ++literal_pos;
        literal_pos %= SZDD_DICTIONARY_SIZE;
        ++decompressed_pos;
      }
      else {
        unsigned int match_pos = fgetc(fp);
        unsigned int match_len = fgetc(fp);
        if (feof(fp)) break;
        match_pos |= (match_len & 0xF0) << 4;
        match_len = (match_len & 0x0F) + 3;

        while (match_len-- != 0) {
          p_decompressed[decompressed_pos] = dictionary[literal_pos] = dictionary[match_pos];
          ++literal_pos;
          literal_pos %= SZDD_DICTIONARY_SIZE;
          ++match_pos;
          match_pos %= SZDD_DICTIONARY_SIZE;
          ++decompressed_pos;
        }
      }
    }
  }
  while (1);

  fclose(fp);

  return p_decompressed;
}
