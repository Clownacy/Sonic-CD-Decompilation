#include "sprites.h"
#include <stdlib.h>
#include <string.h>
#include "cmp.h"
#include "cmpheader.h"
#include "cmpspritemeta.h"
#include "constants.h"
#include "extractedbitmap.h"
#include "spriteinfo.h"
#include "szdd.h"
static void blit_sprite(unsigned char* p_pixelbuffer, extracted_bitmap bitmap, int x, int y, int h_dir, int v_dir);

static unsigned char* g_sprite_bitmap_data = 0;
static extracted_bitmap g_sprite_bitmaps[SPRITE_BITMAPS_MAX] = { 0 };
static sprite_info g_sprites[SPRITES_MAX] = { 0 };
static int g_sprite_cnt = 0;


int load_sprite_bitmaps(char* p_filename, unsigned char (*p_sprbmp)[3]) {
  int ret = 0;
  unsigned char* p_bytes_start = szdd_decompress(p_filename);

  if (p_bytes_start == 0) {
    ret = 1;
  }
  else {
    unsigned char* p_bytes = p_bytes_start;
    cmp_header header;
    cmp_sprite_meta* p_meta;
    unsigned long bitmap_data_size = 0;
    int i;

    p_bytes = read_cmp_header(p_bytes, &header);
    p_bytes = read_cmp_sprite_meta(p_bytes, &p_meta, header.cnt);

    for (i = 0; i < header.cnt; ++i) {
      bitmap_data_size += p_meta[i].width * p_meta[i].height;
    }

    g_sprite_bitmap_data = malloc(bitmap_data_size);
    if (g_sprite_bitmap_data == 0) {
      ret = 2;
    }
    else {
      extract_sprites(g_sprite_bitmap_data, g_sprite_bitmaps, p_bytes, header.cnt, p_meta);

      for (i = 0; i < header.cnt; ++i) {
        p_sprbmp[i][0] = p_meta[i].width;
        p_sprbmp[i][1] = p_meta[i].height;
      }
    }

    free(p_meta);
    free(p_bytes_start);
  }

  return ret;
}


void unload_sprite_bitmaps() {
  if (g_sprite_bitmap_data != 0) {
    free(g_sprite_bitmap_data);
    g_sprite_bitmap_data = 0;
  }
  memset(g_sprite_bitmaps, 0, sizeof(g_sprite_bitmaps));
}


void EAsprset(short x, short y, unsigned short index, unsigned short linkdata, unsigned short reverse) {
  if (index == 0) {
    g_sprites[linkdata].index = 0;
  }
  else {
    g_sprites[linkdata].x = x - 128;
    g_sprites[linkdata].y = y - 128;
    g_sprites[linkdata].index = index;
    g_sprites[linkdata].reverse = reverse;
  }

  g_sprite_cnt = linkdata;
}


void blit_sprites(unsigned char* p_pixelbuffer) {
  int i;

  for (i = g_sprite_cnt - 1; i >= 0; --i) {
    sprite_info info = g_sprites[i];

    if (info.index != 0) {
      extracted_bitmap bitmap = g_sprite_bitmaps[info.index];

      switch (g_sprites[i].reverse & FLIP_MASK) {
        case NOFLIP: blit_sprite(p_pixelbuffer, bitmap, info.x, info.y, 1, 1); break;
        case HFLIP: blit_sprite(p_pixelbuffer, bitmap, info.x, info.y, -1, 1); break;
        case VFLIP: blit_sprite(p_pixelbuffer, bitmap, info.x, info.y, 1, -1); break;
        case HVFLIP: blit_sprite(p_pixelbuffer, bitmap, info.x, info.y, -1, -1); break;
      }
    }
  }
}


static void blit_sprite(unsigned char* p_pixelbuffer, extracted_bitmap bitmap, int x, int y, int h_dir, int v_dir) {
  int x_end = x + bitmap.width;
  int y_end = y + bitmap.height;
  int x_skip = 0;

  if (x >= SCREEN_WIDTH) return;
  if (x_end <= 0) return;
  if (y >= SCREEN_HEIGHT) return;
  if (y_end <= 0) return;

  if (x < 0) {
    x_skip = -x * h_dir;
    x = 0;
  }
  if (x_end > SCREEN_WIDTH) {
    x_end = SCREEN_WIDTH;
  }
  if (y < 0) {
    bitmap.p_data += -y * bitmap.width;
    y = 0;
  }
  if (y_end > SCREEN_HEIGHT) {
    y_end = SCREEN_HEIGHT;
  }

  p_pixelbuffer += y * SCREEN_WIDTH;
  if (h_dir == -1) {
    // Move to the last pixel of the line.
    bitmap.p_data += bitmap.width - 1;
  }
  if (v_dir == -1) {
    // Move to the last line.
    bitmap.p_data += bitmap.width * (bitmap.height - 1);
  }

  do {
    unsigned char* p_pixelbuffer_copy = p_pixelbuffer + x;
    unsigned char* p_bitmap_data_copy = bitmap.p_data + x_skip;
    int i;

    for (i = x; i < x_end; ++i) {
      if (*p_bitmap_data_copy != SPRITE_TRANSPARENT_COLOR) {
        *p_pixelbuffer_copy = *p_bitmap_data_copy;
      }
      ++p_pixelbuffer_copy;
      p_bitmap_data_copy += h_dir;
    }

    p_pixelbuffer += SCREEN_WIDTH;
    bitmap.p_data += bitmap.width * v_dir;
    ++y;
  }
  while (y < y_end);
}
