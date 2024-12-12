#ifndef UTIL_H
#define UTIL_H

unsigned char* read_ulong_littleendian(unsigned char* p_bytes, unsigned long* value);
unsigned char* read_ushort_littleendian(unsigned char* p_bytes, unsigned short* value);

#endif
