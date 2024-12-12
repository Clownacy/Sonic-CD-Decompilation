#include "cmpbmp.h"
#include <stdlib.h>
#include "SDL/SDL.h"
#include "cmpbmpheader.h"
#include "cmptilemeta.h"
#include "szdd.h"
#include "util.h"
extern SDL_Surface* g_tiles[1024];
extern unsigned int g_tile_cnt;
static unsigned char* read_cmp_bmp_header(unsigned char* p_bytes, cmp_bmp_header* header);
static unsigned char* read_cmp_tile_meta(unsigned char* p_bytes, cmp_tile_meta* p_meta, unsigned long tile_cnt);
static void extract_tiles(unsigned char* p_data, unsigned long tile_cnt, cmp_tile_meta meta);
static unsigned char* read_bitmap(unsigned char* p_data, SDL_Surface** pp_surface, unsigned long width, unsigned long height, unsigned int paletteoffset, int has_transparency, int has_padding);


int load_tiles(char* p_filename) {
  unsigned char* p_bytes_start = szdd_decompress(p_filename);
  if (p_bytes_start != 0) {
    unsigned char* p_bytes = p_bytes_start;
    unsigned char* p_data;
    cmp_bmp_header header;
    cmp_tile_meta meta;

    p_bytes = read_cmp_bmp_header(p_bytes, &header);
    p_data = &p_bytes[header.data_pos];
    p_bytes = read_cmp_tile_meta(p_bytes, &meta, header.cnt);
    extract_tiles(p_data, header.cnt, meta);

    free(meta.p_dimensions);
    free(p_bytes_start);
  }
  else {
    return 1;
  }

  return 0;
}


void unload_tiles() {
  int i;

  for (i = 0; i < g_tile_cnt; ++i) {
    SDL_FreeSurface(g_tiles[i]);
  }
}


static unsigned char* read_cmp_bmp_header(unsigned char* p_bytes, cmp_bmp_header* header) {
  header->magic[0] = *p_bytes++;
  header->magic[1] = *p_bytes++;
  header->magic[2] = *p_bytes++;
  header->magic[3] = *p_bytes++;
  p_bytes = read_ulong_littleendian(p_bytes, &header->end_pos);
  p_bytes = read_ulong_littleendian(p_bytes, &header->cnt);
  p_bytes = read_ulong_littleendian(p_bytes, &header->data_pos);

  return p_bytes;
}


static unsigned char* read_cmp_tile_meta(unsigned char* p_bytes, cmp_tile_meta* p_meta, unsigned long tile_cnt) {
  int i;

  p_bytes = read_ushort_littleendian(p_bytes, &p_meta->palette_line_cnt[0]);
  p_bytes = read_ushort_littleendian(p_bytes, &p_meta->palette_line_cnt[1]);
  p_bytes = read_ushort_littleendian(p_bytes, &p_meta->palette_line_cnt[2]);
  p_bytes = read_ushort_littleendian(p_bytes, &p_meta->palette_line_cnt[3]);
  p_meta->p_dimensions = malloc(tile_cnt * sizeof(unsigned short) * 2);

  for (i = 0; i < tile_cnt; ++i) {
    p_bytes = read_ushort_littleendian(p_bytes, &p_meta->p_dimensions[i][0]);
    p_bytes = read_ushort_littleendian(p_bytes, &p_meta->p_dimensions[i][1]);
  }

  return p_bytes;
}


static void extract_tiles(unsigned char* p_data, unsigned long tile_cnt, cmp_tile_meta meta) {
  int i;
  int remaining_tile_cnt = 0;
  int palette_line = 0;
  int palette_offset = 0;

  for (i = 0; i < tile_cnt; ++i) {
    SDL_Surface* p_surface = 0;
    --remaining_tile_cnt;
    if (remaining_tile_cnt <= 0) {
      do {
        remaining_tile_cnt = meta.palette_line_cnt[palette_line];
        ++palette_line;
      }
      while (remaining_tile_cnt == 0);

      switch (palette_line) {
        case 1: palette_offset = 0x10; break;
        case 2: palette_offset = 0x20; break;
        case 3: palette_offset = 0x30; break;
        case 4: palette_offset = 0x40; break;
      }
    }

    p_data = read_bitmap(p_data, &p_surface, meta.p_dimensions[i][0], meta.p_dimensions[i][1], palette_offset, 0, 0);
    SDL_SetColorKey(p_surface, SDL_TRUE, 0);
    g_tiles[i] = p_surface;
    ++g_tile_cnt;
  }
}


static unsigned char* read_bitmap(unsigned char* p_data, SDL_Surface** pp_surface, unsigned long width, unsigned long height, unsigned int paletteoffset, int has_transparency, int has_padding) {
  SDL_Surface* p_surface;
  unsigned char* p_pixels;
  unsigned int y, x;

  p_surface = SDL_CreateRGBSurface(SDL_SWSURFACE | SDL_SRCCOLORKEY, width, height, 8, 0, 0, 0, 0);
  SDL_LockSurface(p_surface);
  p_pixels = (unsigned char*)p_surface->pixels;

  for (y = 0; y < height; ++y) {
    for (x = 0; x < width; ++x) {
      if (has_padding == 0 || width - 4 > x) {
        if (x & 1) {
          *p_pixels = (*p_data & 0x0F) + paletteoffset;
        }
        else {
          *p_pixels = ((*p_data & 0xF0) >> 4) + paletteoffset;
        }
        if (*p_pixels == paletteoffset) {
          if (has_transparency != 0) {
            *p_pixels = 0xFF;
          }
          else {
            *p_pixels = 0;
          }
        }
        ++p_pixels;
        if (x & 1) {
          ++p_data;
        }
      }
    }
  }

  SDL_UnlockSurface(p_surface);
  *pp_surface = p_surface;

  return p_data;
}
