#ifndef TILES_H
#define TILES_H

int load_tile_bitmaps(char* p_filename);
void unload_tile_bitmaps();
void SetGrid(int base, int x, int y, int block, int frip);
void blit_lo_planes(unsigned char* p_pixelbuffer, unsigned short* p_hscroll_a, unsigned short vscroll_a, unsigned short* p_hscroll_b, unsigned short vscroll_b);
void blit_hi_planes(unsigned char* p_pixelbuffer, unsigned short* p_hscroll_a, unsigned short vscroll_a, unsigned short* p_hscroll_b, unsigned short vscroll_b);

#endif
