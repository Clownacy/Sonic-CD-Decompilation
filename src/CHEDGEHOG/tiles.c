#include "tiles.h"
#include <stdlib.h>
#include <string.h>
#include "cmpbmp.h"
#include "cmpbmpheader.h"
#include "cmptilemeta.h"
#include "constants.h"
#include "extractedbitmap.h"
#include "szdd.h"
static void blit_plane(unsigned char* p_pixelbuffer, unsigned short(*p_plane)[STAGE_PLANE_WIDTH / TILE_LENGTH], unsigned short* p_hscroll, unsigned short vscroll);
static void add_flip_tile_bitmaps();
static void add_hflip_tile_bitmaps(unsigned char* p_hflip_data, extracted_bitmap* p_hflip_bitmaps, unsigned char* p_data, extracted_bitmap* p_bitmaps);
static void add_vflip_tile_bitmaps(unsigned char* p_vflip_data, extracted_bitmap* p_vflip_bitmaps, unsigned char* p_data, extracted_bitmap* p_bitmaps);
static void add_hvflip_tile_bitmaps(unsigned char* p_hvflip_data, extracted_bitmap* p_hvflip_bitmaps, unsigned char* p_data, extracted_bitmap* p_bitmaps);

static unsigned char* g_tile_bitmap_data = 0;
static extracted_bitmap g_tile_bitmaps[TILE_BITMAPS_MAX] = { 0 };
static unsigned short g_plane_a_lo[STAGE_PLANE_HEIGHT / TILE_LENGTH][STAGE_PLANE_WIDTH / TILE_LENGTH] = { 0 };
static unsigned short g_plane_a_hi[STAGE_PLANE_HEIGHT / TILE_LENGTH][STAGE_PLANE_WIDTH / TILE_LENGTH] = { 0 };
static unsigned short g_plane_b[STAGE_PLANE_HEIGHT / TILE_LENGTH][STAGE_PLANE_WIDTH / TILE_LENGTH] = { 0 };
static unsigned long g_tile_cnt = 0;


int load_tile_bitmaps(char* p_filename) {
  int ret = 0;
  unsigned char* p_bytes_start = szdd_decompress(p_filename);

  if (p_bytes_start == 0) {
    ret = 1;
  }
  else {
    unsigned char* p_bytes = p_bytes_start;
    cmp_bmp_header header;
    cmp_tile_meta meta;
    unsigned long bitmap_data_size = 0;
    int i;

    p_bytes = read_cmp_bmp_header(p_bytes, &header);
    p_bytes = read_cmp_tile_meta(p_bytes, &meta, header.cnt);

    for (i = 0; i < header.cnt; ++i) {
      bitmap_data_size += meta.p_dimensions[i][0] * meta.p_dimensions[i][1];
    }

    g_tile_bitmap_data = malloc(bitmap_data_size * 4);
    if (g_tile_bitmap_data == 0) {
      ret = 2;
    }
    else {
      extract_tiles(g_tile_bitmap_data, g_tile_bitmaps, p_bytes, header.cnt, meta);
      g_tile_cnt = header.cnt;
      add_flip_tile_bitmaps(bitmap_data_size);
    }

    free(meta.p_dimensions);
    free(p_bytes_start);
  }

  return ret;
}


static void add_flip_tile_bitmaps(unsigned long bitmap_data_size) {
  unsigned char* p_data = &g_tile_bitmap_data[NOFLIP * bitmap_data_size];
  unsigned char* p_hflip_data = &g_tile_bitmap_data[HFLIP * bitmap_data_size];
  unsigned char* p_vflip_data = &g_tile_bitmap_data[VFLIP * bitmap_data_size];
  unsigned char* p_hvflip_data = &g_tile_bitmap_data[HVFLIP * bitmap_data_size];
  extracted_bitmap* p_bitmaps = &g_tile_bitmaps[NOFLIP * g_tile_cnt];
  extracted_bitmap* p_hflip_bitmaps = &g_tile_bitmaps[HFLIP * g_tile_cnt];
  extracted_bitmap* p_vflip_bitmaps = &g_tile_bitmaps[VFLIP * g_tile_cnt];
  extracted_bitmap* p_hvflip_bitmaps = &g_tile_bitmaps[HVFLIP * g_tile_cnt];

  add_hflip_tile_bitmaps(p_hflip_data, p_hflip_bitmaps, p_data, p_bitmaps);
  add_vflip_tile_bitmaps(p_vflip_data, p_vflip_bitmaps, p_data, p_bitmaps);
  add_hvflip_tile_bitmaps(p_hvflip_data, p_hvflip_bitmaps, p_data, p_bitmaps);
}


static void add_hflip_tile_bitmaps(unsigned char* p_hflip_data, extracted_bitmap* p_hflip_bitmaps, unsigned char* p_data, extracted_bitmap* p_bitmaps) {
  unsigned long i;
  int y, x;

  /* Move to the last pixel of the first line. */
  p_data += TILE_LENGTH - 1;

  for (i = 0; i < g_tile_cnt; ++i) {
    p_hflip_bitmaps->p_data = p_hflip_data;
    p_hflip_bitmaps->width = p_bitmaps->width;
    p_hflip_bitmaps->height = p_bitmaps->height;

    for (y = 0; y < TILE_LENGTH; ++y) {
      for (x = 0; x < TILE_LENGTH; ++x) {
        *p_hflip_data++ = *p_data--;
      }

      /* We're now at the last pixel of the previous line. */
      /* Move to the last pixel of the next line. */
      p_data += TILE_LENGTH * 2;
    }

    ++p_hflip_bitmaps;
    ++p_bitmaps;
  }
}


static void add_vflip_tile_bitmaps(unsigned char* p_vflip_data, extracted_bitmap* p_vflip_bitmaps, unsigned char* p_data, extracted_bitmap* p_bitmaps) {
  unsigned long i;
  int y, x;

  /* Move to the first pixel of the last line. */
  p_data += TILE_LENGTH * (TILE_LENGTH - 1);

  for (i = 0; i < g_tile_cnt; ++i) {
    p_vflip_bitmaps->p_data = p_vflip_data;
    p_vflip_bitmaps->width = p_bitmaps->width;
    p_vflip_bitmaps->height = p_bitmaps->height;

    for (y = 0; y < TILE_LENGTH; ++y) {
      for (x = 0; x < TILE_LENGTH; ++x) {
        *p_vflip_data++ = *p_data++;
      }

      /* We're now at the first pixel of the next line. */
      /* Move to the first pixel of the previous line. */
      p_data -= TILE_LENGTH * 2;
    }

    ++p_vflip_bitmaps;
    ++p_bitmaps;

    /* We're now at the first pixel of the previous tile's last line. */
    /* Move to the first pixel of the next tile's last line. */
    p_data += TILE_LENGTH * TILE_LENGTH * 2;
  }
}


static void add_hvflip_tile_bitmaps(unsigned char* p_hvflip_data, extracted_bitmap* p_hvflip_bitmaps, unsigned char* p_data, extracted_bitmap* p_bitmaps) {
  unsigned long i;
  int y, x;

  /* Move to the last pixel of the last line. */
  p_data += TILE_LENGTH * TILE_LENGTH - 1;

  for (i = 0; i < g_tile_cnt; ++i) {
    p_hvflip_bitmaps->p_data = p_hvflip_data;
    p_hvflip_bitmaps->width = p_bitmaps->width;
    p_hvflip_bitmaps->height = p_bitmaps->height;

    for (y = 0; y < TILE_LENGTH; ++y) {
      for (x = 0; x < TILE_LENGTH; ++x) {
        *p_hvflip_data++ = *p_data--;
      }
    }

    ++p_hvflip_bitmaps;
    ++p_bitmaps;

    /* We're now at the last pixel of the previous tile's last line. */
    /* Move to the last pixel of the next tile's last line. */
    p_data += TILE_LENGTH * TILE_LENGTH * 2;
  }
}


void unload_tile_bitmaps() {
  if (g_tile_bitmap_data != 0) {
    free(g_tile_bitmap_data);
    g_tile_bitmap_data = 0;
  }
  memset(g_tile_bitmaps, 0, sizeof(g_tile_bitmaps));
}


void SetGrid(int base, int x, int y, int block, int frip) {
  unsigned short index = (unsigned int)block & 0x7FF;
  unsigned short flip = (((unsigned int)frip ^ (unsigned int)block) >> 11) & FLIP_MASK;

  if (index == 0) {
    if (base != 0) {
      g_plane_b[y][x] = 0;
    }
    else {
      g_plane_a_hi[y][x] = 0;
      g_plane_a_lo[y][x] = 0;
    }
  }
  else {
    index += flip * g_tile_cnt;
    if (base != 0) {
      g_plane_b[y][x] = index;
    }
    else if (block & 0x8000) {
      g_plane_a_hi[y][x] = index;
      g_plane_a_lo[y][x] = 0;
    }
    else {
      g_plane_a_hi[y][x] = 0;
      g_plane_a_lo[y][x] = index;
    }
  }
}


void blit_planes(unsigned char* p_pixelbuffer, unsigned short* p_hscroll_a, unsigned short vscroll_a, unsigned short* p_hscroll_b, unsigned short vscroll_b) {
  blit_plane(p_pixelbuffer, g_plane_b, p_hscroll_b, vscroll_b);
  blit_plane(p_pixelbuffer, g_plane_a_lo, p_hscroll_a, vscroll_a);
  blit_plane(p_pixelbuffer, g_plane_a_hi, p_hscroll_a, vscroll_a);
}


static void blit_plane(unsigned char* p_pixelbuffer, unsigned short(*p_plane)[STAGE_PLANE_WIDTH / TILE_LENGTH], unsigned short* p_hscroll, unsigned short vscroll) {
  unsigned int y = vscroll;
  unsigned int h_pixel_cnts[SCREEN_WIDTH / TILE_LENGTH + 2] = { 0 };
  unsigned int v, i;

  for (i = 0; i < SCREEN_WIDTH / TILE_LENGTH; ++i) {
    h_pixel_cnts[i] = TILE_LENGTH;
  }

  for (v = 0; v < SCREEN_HEIGHT; ++v) {
    unsigned int x = p_hscroll[v];
    unsigned int left_overhang = x % TILE_LENGTH;
    unsigned int tile_y = (y & STAGE_PLANE_HEIGHT - 1) / TILE_LENGTH;
    unsigned int row_offset = y % TILE_LENGTH * TILE_LENGTH;
    unsigned int* p_h_pixel_cnt = h_pixel_cnts;

    h_pixel_cnts[0] = TILE_LENGTH - left_overhang;
    h_pixel_cnts[SCREEN_WIDTH / TILE_LENGTH] = left_overhang;

    do {
      unsigned int tile_x = (x & STAGE_PLANE_WIDTH - 1) / TILE_LENGTH;
      unsigned short tile = p_plane[tile_y][tile_x];

      if (tile != 0) {
        unsigned int column_offset = TILE_LENGTH - *p_h_pixel_cnt;
        unsigned char* p_pixelbuffer_copy = p_pixelbuffer;
        unsigned char* p_pixels = &g_tile_bitmaps[tile].p_data[row_offset + column_offset];

        for (i = 0; i < *p_h_pixel_cnt; ++i) {
          if (*p_pixels != 0) {
            *p_pixelbuffer_copy = *p_pixels;
          }
          ++p_pixelbuffer_copy;
          ++p_pixels;
        }
      }
      p_pixelbuffer += *p_h_pixel_cnt;
      x += *p_h_pixel_cnt;
    }
    while (*++p_h_pixel_cnt != 0);

    ++y;
  }
}
