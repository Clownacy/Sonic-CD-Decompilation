#ifndef CMPBMP_H
#define CMPBMP_H

#include "cmpheader.h"
#include "cmpspritemeta.h"
#include "cmptilemeta.h"
#include "extractedbitmap.h"

unsigned char* read_cmp_header(unsigned char* p_bytes, cmp_header* header);
unsigned char* read_cmp_sprite_meta(unsigned char* p_bytes, cmp_sprite_meta** pp_meta, unsigned long sprite_cnt);
unsigned char* read_cmp_tile_meta(unsigned char* p_bytes, cmp_tile_meta* p_meta, unsigned long tile_cnt);
void extract_sprites(unsigned char* p_output, extracted_bitmap* p_extracted, unsigned char* p_input, unsigned long cnt, cmp_sprite_meta* p_meta);
void extract_tiles(unsigned char* p_output, extracted_bitmap* p_extracted, unsigned char* p_input, unsigned long cnt, cmp_tile_meta meta);

#endif
