#ifndef IO_H
#define IO_H

#include <stdio.h>

unsigned long ReadUnsignedLE(FILE *file, unsigned int total_bytes);
unsigned long ReadUnsignedBE(FILE *file, unsigned int total_bytes);
unsigned long ReadU32LE(FILE *file);
unsigned long ReadU16LE(FILE *file);
unsigned long ReadU32BE(FILE *file);
unsigned long ReadU16BE(FILE *file);
signed long ReadSigned(unsigned long unsigned_value, unsigned int total_bytes);
signed long ReadSignedLE(FILE *file, unsigned int total_bytes);
signed long ReadS32LE(FILE *file);
signed long ReadS16LE(FILE *file);
signed long ReadSignedBE(FILE *file, unsigned int total_bytes);
signed long ReadS32BE(FILE *file);
signed long ReadS16BE(FILE *file);

#endif /* IO_H */
