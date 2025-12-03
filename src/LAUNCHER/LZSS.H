#ifndef LZSS_H
#define LZSS_H

#include <stdio.h>

void LZSS_Decode(FILE *infile, void *outbuffer, size_t outsize);

#endif /* LZSS_H */
