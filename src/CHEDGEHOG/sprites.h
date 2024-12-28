#ifndef SPRITES_H
#define SPRITES_H

int load_sprite_bitmaps(char* p_filename, unsigned char (*p_sprbmp)[3]);
void unload_sprite_bitmaps();
void EAsprset(short x, short y, unsigned short index, unsigned short linkdata, unsigned short reverse);
void blit_sprites_lo(unsigned char* p_pixelbuffer);
void blit_sprites_hi(unsigned char* p_pixelbuffer);

#endif
