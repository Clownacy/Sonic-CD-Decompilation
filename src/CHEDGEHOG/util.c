#include "util.h"


unsigned char* read_ulong_littleendian(unsigned char* p_bytes, unsigned long* p_value) {
  *p_value = *p_bytes++;
  *p_value += *p_bytes++ << 8;
  *p_value += *p_bytes++ << 16;
  *p_value += *p_bytes++ << 24;

  return p_bytes;
}

unsigned char* read_ushort_littleendian(unsigned char* p_bytes, unsigned short* p_value) {
  *p_value = *p_bytes++;
  *p_value += *p_bytes++ << 8;

  return p_bytes;
}
