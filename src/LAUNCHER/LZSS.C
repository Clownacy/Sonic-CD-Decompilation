/**************************************************************
	LZSS.C -- A Data Compression Program
	(tab = 4 spaces)
***************************************************************
	4/6/1989 Haruhiko Okumura
	Use, distribute, and modify this program freely.
	Please send me your improved versions.
		PC-VAN		SCIENCE
		NIFTY-Serve	PAF01022
		CompuServe	74050,1022
**************************************************************/
#include "LZSS.H"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define N		 4096	/* size of ring buffer */
#define F		   16	/* upper limit for match_length */
#define THRESHOLD	2   /* encode string into position and length
						   if match_length is greater than this */

static unsigned char
		text_buf[N + F - 1];	/* ring buffer of size N,
			with extra F-1 bytes to facilitate string comparison */

void LZSS_Decode(FILE *infile, void *outbuffer, size_t outsize)	/* Just the reverse of Encode(). */
{
	int  i, j, k, r, c;
	unsigned int  flags;
	unsigned char *out = (unsigned char*)outbuffer;
	unsigned char *outend = out + outsize;
	
	for (i = 0; i < N - F; i++) text_buf[i] = ' ';
	r = N - F;  flags = 0;
	for ( ; ; ) {
		if (((flags >>= 1) & 256) == 0) {
			if ((c = fgetc(infile)) == EOF) return;
			flags = c | 0xff00;		/* uses higher byte cleverly */
		}							/* to count eight */
		if (flags & 1) {
			if ((c = fgetc(infile)) == EOF) return;
			*out++ = c;  text_buf[r++] = c;  r &= (N - 1);
			if (out == outend) return;
		} else {
			if ((i = fgetc(infile)) == EOF) return;
			if ((j = fgetc(infile)) == EOF) return;
			i |= ((j & 0xf0) << 4);  j = (j & 0x0f) + THRESHOLD;
			for (k = 0; k <= j; k++) {
				c = text_buf[(i + k) & (N - 1)];
				*out++ = c;  text_buf[r++] = c;  r &= (N - 1);
				if (out == outend) return;
			}
		}
	}
}
