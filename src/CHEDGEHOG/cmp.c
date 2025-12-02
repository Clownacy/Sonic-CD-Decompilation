#include "cmp.h"
#include <stdlib.h>
#include "cmpheader.h"
#include "cmpspritemeta.h"
#include "cmptilemeta.h"
#include "extractedbitmap.h"
#include "util.h"
static unsigned char* read_bitmap(unsigned char* p_output, unsigned char* p_input, unsigned short width, unsigned short height, unsigned int palette_offset, int has_transparency, int has_padding);


unsigned char* read_cmp_header(unsigned char* p_bytes, cmp_header* header) {
  header->magic[0] = *p_bytes++;
  header->magic[1] = *p_bytes++;
  header->magic[2] = *p_bytes++;
  header->magic[3] = *p_bytes++;
  p_bytes = read_ulong_littleendian(p_bytes, &header->end_pos);
  p_bytes = read_ulong_littleendian(p_bytes, &header->cnt);
  p_bytes = read_ulong_littleendian(p_bytes, &header->data_pos);

  return p_bytes;
}


unsigned char* read_cmp_sprite_meta(unsigned char* p_bytes, cmp_sprite_meta** pp_meta, unsigned long sprite_cnt) {
  int i;
  cmp_sprite_meta* p_meta = malloc(sprite_cnt * sizeof(cmp_sprite_meta));

  for (i = 0; i < sprite_cnt; ++i) {
    p_bytes = read_ushort_littleendian(p_bytes, &p_meta[i].x);
    p_bytes = read_ushort_littleendian(p_bytes, &p_meta[i].y);
    p_bytes = read_ushort_littleendian(p_bytes, &p_meta[i].width);
    p_bytes = read_ushort_littleendian(p_bytes, &p_meta[i].height);
    p_bytes = read_ushort_littleendian(p_bytes, &p_meta[i].palette_offset);
    p_bytes = read_ushort_littleendian(p_bytes, &p_meta[i].unknown);
  }

  *pp_meta = p_meta;

  return p_bytes;
}


unsigned char* read_cmp_tile_meta(unsigned char* p_bytes, cmp_tile_meta* p_meta, unsigned long tile_cnt) {
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


void extract_sprites(unsigned char* p_output, extracted_bitmap* p_extracted, unsigned char* p_input, unsigned long cnt, cmp_sprite_meta* p_meta) {
  int i;

  for (i = 0; i < cnt; ++i) {
    int has_padding = 0;
    if (p_meta[i].width & 4) {
      has_padding = 1;
    }
    p_input = read_bitmap(p_output, p_input, p_meta[i].width, p_meta[i].height, p_meta[i].palette_offset, 1, has_padding);
    p_extracted[i].p_data = p_output;
    p_extracted[i].width = p_meta[i].width;
    p_extracted[i].height = p_meta[i].height;
    p_output += p_meta[i].width * p_meta[i].height;
  }
}


void extract_tiles(unsigned char* p_output, extracted_bitmap* p_extracted, unsigned char* p_input, unsigned long cnt, cmp_tile_meta meta) {
  int i;
  int remaining_tile_cnt = 0;
  int palette_line = 0;
  int palette_offset = 0;

  for (i = 0; i < cnt; ++i) {
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

    p_input = read_bitmap(p_output, p_input, meta.p_dimensions[i][0], meta.p_dimensions[i][1], palette_offset, 0, 0);
    p_extracted[i].p_data = p_output;
    p_extracted[i].width = meta.p_dimensions[i][0];
    p_extracted[i].height = meta.p_dimensions[i][1];
    p_output += meta.p_dimensions[i][0] * meta.p_dimensions[i][1];
  }
}


static unsigned char* read_bitmap(unsigned char* p_output, unsigned char* p_input, unsigned short width, unsigned short height, unsigned int palette_offset, int has_transparency, int has_padding) {
  unsigned int y, x;

  if (has_padding != 0) {
    width += 4;
  }

  for (y = 0; y < height; ++y) {
    for (x = 0; x < width; ++x) {
      if (has_padding == 0 || width - 4 > x) {
        if (x & 1) {
          *p_output = (*p_input & 0x0F) + palette_offset;
        }
        else {
          *p_output = ((*p_input & 0xF0) >> 4) + palette_offset;
        }
        if (*p_output == palette_offset) {
          if (has_transparency != 0) {
            *p_output = 0xFF;
          }
          else {
            *p_output = 0;
          }
        }
        ++p_output;
      }
      if (x & 1) {
        ++p_input;
      }
    }
  }

  return p_input;
}
