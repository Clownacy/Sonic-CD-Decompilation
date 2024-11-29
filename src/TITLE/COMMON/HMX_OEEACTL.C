#include "..\..\TYPES.H"
#include "HMX_TYPES.H"
#include "LD_TYPES.H"
#include "HMX_OEEACTL.H"

extern void(*FlipToScreen_module)();
extern void(*hmx_renderer_context_draw_module)(hmx_renderer_context*, hmx_surface*);
extern draw_context* s_ctx;
extern void(*hmx_renderer_context_add_module)(hmx_renderer_context*, int, hmx_renderer_base*);
extern hmx_renderer_base*(*hmx_sprite_base_module)(hmx_sprite*);
extern hmx_renderer_base*(*hmx_grid_base_module)(hmx_grid*);
extern void(*hmx_renderer_context_clear_module)(hmx_renderer_context*);
extern void(*sMemFree)(void*);
extern void(*sCloseFile)(int);
extern int(*sReadFile)(int, void*, int);
extern void*(*sMemAlloc)(int);
extern int(*sGetFileSize)(int);
extern int(*sOpenFile)(char*);
extern void(*hmx_free_module)(hmx_environment*, void*);
extern void(*hmx_bitmap_set_transparency_module)(hmx_bitmap*, int);
extern void*(*hmx_bitmap_get_scan0_module)(hmx_bitmap*);
extern sprite_bmp infoSprtBmp[];
extern hmx_bitmap*(*hmx_bitmap_create_module)(hmx_environment*, int, int);
extern void*(*ld_load_cmpfile_module)(hmx_environment*, char*);
extern unsigned short NUM_GRIDBMP;
extern grid_bmp infoGridBmp[];
extern void(*ld_bitmap_4to8_module)(void*, void*, int, int, int, int, int);
extern hmx_environment* g_env_module;
extern char* TileCmpFileName;
extern hmx_environment* g_loader_module;
extern void(*hmx_bitmap_release_module)(hmx_environment*, hmx_bitmap*);
extern unsigned short NUM_BMP;
extern char* SprCmpFileName;
extern void(*hmx_sprite_set_flags_module)(hmx_sprite*, int);
extern void(*hmx_sprite_set_bitmap_module)(hmx_sprite*, hmx_bitmap*);
extern void(*hmx_sprite_set_position_module)(hmx_sprite*, int, int);
extern void(*hmx_grid_release_module)(hmx_environment*, hmx_grid*);
static int sprIdx[512];
extern hmx_grid*(*hmx_grid_create_module)(hmx_environment*, int, int, int, int);
static char ErrBuf[250];
int ErrRet;
#if defined(SAVEDATA)
extern int PRIO_MAX;
#else
  #define PRIO_MAX 60
#endif























void EAError(int ret, int line, char* str) { /* Line 70, Address: 0x10010e0 */



















} /* Line 90, Address: 0x10010e4 */


void srfDraw() { /* Line 93, Address: 0x10010f0 */
  int i;
  if (s_ctx->context != 0) { /* Line 95, Address: 0x10010fc */

    hmx_renderer_context_clear_module(s_ctx->context); /* Line 97, Address: 0x1001110 */


#if defined(OPENING)
    for (i = 0; i < 3; ++i) { /* Line 101, Address: 0x1003f8c */







      if (*infoGridBmp[i].lphGrid != 0) /* Line 109, Address: 0x1003f98 */
        hmx_renderer_context_add_module(s_ctx->context, PRIO_MAX - infoGridBmp[i].order, hmx_grid_base_module(s_ctx->grids[i])); /* Line 110, Address: 0x1003fc0 */
    } /* Line 111, Address: 0x1004028 */
#else
    if (s_ctx->grids[0] != 0) { /* Line 113, Address: 0x100112c */
      hmx_renderer_context_add_module(s_ctx->context, 0, hmx_grid_base_module(s_ctx->grids[0])); /* Line 114, Address: 0x1001140 */
    }
#endif

    for (i = 255; i >= 0; --i) { /* Line 118, Address: 0x1001180 */
      if (s_ctx->spr_level[i] != 0) { /* Line 119, Address: 0x100118c */
        hmx_renderer_context_add_module(s_ctx->context, s_ctx->spr_level[i], hmx_sprite_base_module(s_ctx->sprites[i])); /* Line 120, Address: 0x10011a8 */
      }









    } /* Line 131, Address: 0x1001204 */


    hmx_renderer_context_draw_module(s_ctx->context, s_ctx->screen); /* Line 134, Address: 0x1001210 */
  }
  FlipToScreen_module(); /* Line 136, Address: 0x1001238 */
} /* Line 137, Address: 0x1001248 */








void ld_bitmap_file(char* fname, void* dst, int wx, int wy, int palet, int unknown) { /* Line 146, Address: 0x1001260 */
  int fp;
  int fsize;
  void* fbuf = 0; /* Line 149, Address: 0x10012a0 */
  unsigned int offset;
  int iWidth, iHeight, iLength, y, x;
  unsigned char *src, *pDst = dst; /* Line 152, Address: 0x10012a4 */

  fp = sOpenFile(fname); /* Line 154, Address: 0x10012a8 */
  if (fp != -1) { /* Line 155, Address: 0x10012c0 */
    fsize = sGetFileSize(fp); /* Line 156, Address: 0x10012cc */
    if (fsize != -1) { /* Line 157, Address: 0x10012e4 */
      fbuf = sMemAlloc(fsize); /* Line 158, Address: 0x10012f4 */
      if (sReadFile(fp, fbuf, fsize) != -1) { /* Line 159, Address: 0x100130c */



        src = fbuf; /* Line 163, Address: 0x1001334 */
        offset = src[10] + (src[11] << 8) + (src[12] << 16) + (src[13] << 24); /* Line 164, Address: 0x1001338 */
        iWidth = src[18] + (src[19] << 8) + (src[20] << 16) + (src[21] << 24); /* Line 165, Address: 0x1001370 */
        iHeight = src[22] + (src[23] << 8) + (src[24] << 16) + (src[25] << 24); /* Line 166, Address: 0x10013a8 */
        if (iWidth % 4 == 0) /* Line 167, Address: 0x10013e4 */
          iLength = iWidth; /* Line 168, Address: 0x1001408 */
        else
          iLength = iWidth + (4 - iWidth % 4); /* Line 170, Address: 0x1001414 */
        for (y = wy; y > 0; --y) { /* Line 171, Address: 0x100143c */
          for (x = 0; x < wx; ++x) { /* Line 172, Address: 0x1001448 */
            if (x < wx - 1) { /* Line 173, Address: 0x1001454 */
              if (palet != 0) { /* Line 174, Address: 0x1001468 */
                if (src[offset + x + (y - 1) * iLength] != 0) /* Line 175, Address: 0x1001474 */
                  *pDst = palet + src[offset + x + (y - 1) * iLength]; /* Line 176, Address: 0x1001498 */
                else
                  *pDst = 0; /* Line 178, Address: 0x10014cc */
              } /* Line 179, Address: 0x10014d0 */
              else *pDst = src[offset + x + (y - 1) * iLength]; /* Line 180, Address: 0x10014d8 */

              if (*pDst == 0) /* Line 182, Address: 0x10014f4 */
                *pDst = 255; /* Line 183, Address: 0x1001504 */
            } /* Line 184, Address: 0x100150c */
            else *pDst = 255; /* Line 185, Address: 0x1001514 */
            ++pDst; /* Line 186, Address: 0x100151c */
          } /* Line 187, Address: 0x1001520 */
        } /* Line 188, Address: 0x1001534 */
      }
    }
    sCloseFile(fp); /* Line 191, Address: 0x1001540 */
  }
  if (fbuf != 0) { /* Line 193, Address: 0x1001554 */
    sMemFree(fbuf); /* Line 194, Address: 0x100155c */
  }
} /* Line 196, Address: 0x1001570 */












void ld_bitmap_file2(char* fname, void* dst, int sx, int sy, int wx, int wy, int dx, int dy, int unk1, int unk2) { /* Line 209, Address: 0x10015b0 */
  unsigned char* pDst;
  int fp;
  void* fbuf = 0; /* Line 212, Address: 0x10015f4 */
  unsigned char* src;
  int i, fsize, x, y, iWidth, iHeight, iLength;
  unsigned int offset;
  pDst = dst; /* Line 216, Address: 0x10015f8 */

  if (dx != 0) { /* Line 218, Address: 0x10015fc */
    for (i = 0; i < dx; ++pDst, ++i) { /* Line 219, Address: 0x1001608 */
    } /* Line 220, Address: 0x1001614 */
  }

  fp = sOpenFile(fname); /* Line 223, Address: 0x1001630 */
  if (fp != -1) { /* Line 224, Address: 0x1001648 */
    fsize = sGetFileSize(fp); /* Line 225, Address: 0x1001654 */
    if (fsize != -1) { /* Line 226, Address: 0x100166c */
      fbuf = sMemAlloc(fsize); /* Line 227, Address: 0x1001678 */
      if (sReadFile(fp, fbuf, fsize) != -1) { /* Line 228, Address: 0x1001690 */



        src = fbuf; /* Line 232, Address: 0x10016b8 */
        offset = src[10] + (src[11] << 8) + (src[12] << 16) + (src[13] << 24); /* Line 233, Address: 0x10016bc */
        iWidth = src[18] + (src[19] << 8) + (src[20] << 16) + (src[21] << 24); /* Line 234, Address: 0x10016f8 */
        iHeight = src[22] + (src[23] << 8) + (src[24] << 16) + (src[25] << 24); /* Line 235, Address: 0x1001730 */
        if (iWidth % 4 == 0) /* Line 236, Address: 0x100176c */
          iLength = iWidth; /* Line 237, Address: 0x1001790 */
        else
          iLength = iWidth + (4 - iWidth % 4); /* Line 239, Address: 0x100179c */
        for (y = wy; y > 0; --y) { /* Line 240, Address: 0x10017c8 */
          for (x = 0; x < wx; ++x) { /* Line 241, Address: 0x10017d4 */
            *pDst = src[offset + x + (y - 1) * iLength]; /* Line 242, Address: 0x10017e0 */
            if (*pDst == 0) /* Line 243, Address: 0x1001804 */
              *pDst = 255; /* Line 244, Address: 0x1001814 */
            ++pDst; /* Line 245, Address: 0x100181c */
          } /* Line 246, Address: 0x1001820 */
          if (dx != 0) { /* Line 247, Address: 0x1001834 */
            for (i = 0; i < dx; ++pDst, ++i) { /* Line 248, Address: 0x1001840 */
            } /* Line 249, Address: 0x100184c */
          } else if (iWidth != sx) { /* Line 250, Address: 0x1001868 */
            for (i = 0; i < sx - iWidth; ++pDst, ++i) { /* Line 251, Address: 0x100187c */
            } /* Line 252, Address: 0x1001888 */
          }
        } /* Line 254, Address: 0x10018a4 */
      }
    }
    sCloseFile(fp); /* Line 257, Address: 0x10018b0 */
  }
  if (fbuf != 0) { /* Line 259, Address: 0x10018c4 */
    sMemFree(fbuf); /* Line 260, Address: 0x10018cc */
  }
} /* Line 262, Address: 0x10018e0 */









void ld_bitmap_4to8_1(void* dst, void* src, int wx, int wy, int palet, int zero_chg, int flag4) { /* Line 272, Address: 0x1001920 */
  unsigned char *pDst, *pSrc;
  int x, y;

  pDst = dst; /* Line 276, Address: 0x1001950 */
  pSrc = src; /* Line 277, Address: 0x1001954 */

  for (y = 0; y < wy; ++y) { /* Line 279, Address: 0x1001958 */
    for (x = 0; x < wx; ++x) { /* Line 280, Address: 0x1001964 */
      if (flag4 == 0 || x < wx - 4) { /* Line 281, Address: 0x1001970 */
        if (x & 1) *pDst = (*pSrc & 15) + palet; /* Line 282, Address: 0x1001990 */
        else *pDst = ((*pSrc & 240) >> 4) + palet; /* Line 283, Address: 0x10019c0 */
        if (*pDst == palet) { /* Line 284, Address: 0x10019e0 */
          if (zero_chg != 0) { /* Line 285, Address: 0x10019f4 */
            *pDst = 255; /* Line 286, Address: 0x1001a00 */
          } /* Line 287, Address: 0x1001a08 */
          else *pDst = 0; /* Line 288, Address: 0x1001a10 */
        }

        ++pDst; /* Line 291, Address: 0x1001a14 */
      }
      if (x & 1) ++pSrc; /* Line 293, Address: 0x1001a18 */
    } /* Line 294, Address: 0x1001a28 */
  } /* Line 295, Address: 0x1001a3c */
} /* Line 296, Address: 0x1001a50 */









void ld_bitmap_4to8_2(void* dst, void* src, int wx, int wy, int palet, int zero_chg, int flag4) { /* Line 306, Address: 0x1001a70 */
  unsigned char *pDst, *pSrc;
  int x, y;

  pDst = dst; /* Line 310, Address: 0x1001aa0 */
  pSrc = src; /* Line 311, Address: 0x1001aa4 */

  for (y = 0; y < wy; ++y) { /* Line 313, Address: 0x1001aa8 */
    for (x = 0; x < wx; ++x) { /* Line 314, Address: 0x1001ab4 */
      if (flag4 == 0 || x < wx - 4) { /* Line 315, Address: 0x1001ac0 */
        if (x < wx - 1) { /* Line 316, Address: 0x1001ae0 */
          if (x & 1) *pDst = (*pSrc & 15) + palet; /* Line 317, Address: 0x1001af4 */
          else *pDst = ((*pSrc & 240) >> 4) + palet; /* Line 318, Address: 0x1001b24 */
        } /* Line 319, Address: 0x1001b44 */
        else *pDst = palet; /* Line 320, Address: 0x1001b4c */

        if (*pDst == palet) { /* Line 322, Address: 0x1001b58 */
          if (zero_chg != 0) { /* Line 323, Address: 0x1001b6c */
            *pDst = 255; /* Line 324, Address: 0x1001b78 */
          } /* Line 325, Address: 0x1001b80 */
          else *pDst = 0; /* Line 326, Address: 0x1001b88 */
        }

        ++pDst; /* Line 329, Address: 0x1001b8c */
      }
      if (x & 1) ++pSrc; /* Line 331, Address: 0x1001b90 */
    } /* Line 332, Address: 0x1001ba0 */
  } /* Line 333, Address: 0x1001bb4 */
} /* Line 334, Address: 0x1001bc8 */







int ld_load_sprite2(hmx_environment* buffer, char* file, hmx_environment* env, hmx_bitmap** bitmaps, int size) { /* Line 342, Address: 0x1001bf0 */
  int count = -1, read_count; /* Line 343, Address: 0x1001c30 */
  unsigned char* pixbuf;
  void* expbuf = 0; /* Line 345, Address: 0x1001c38 */
  ld_sprite_header* header;
  int i;
  hmx_bitmap* bmp;
  ld_sprite_inf* s;
  int wx, wy;
  int flag4;

  for (i = 0; i < size; ++i) { /* Line 353, Address: 0x1001c3c */
    bitmaps[i] = 0; /* Line 354, Address: 0x1001c48 */
  } /* Line 355, Address: 0x1001c58 */

  expbuf = ld_load_cmpfile_module(buffer, file); /* Line 357, Address: 0x1001c6c */
  if (expbuf != 0) { /* Line 358, Address: 0x1001c88 */



    header = expbuf; /* Line 362, Address: 0x1001c90 */
    read_count = header->header.count; /* Line 363, Address: 0x1001c94 */
    if (size < read_count) { /* Line 364, Address: 0x1001c98 */
      read_count = size; /* Line 365, Address: 0x1001ca8 */
    }

    pixbuf = (unsigned char*)expbuf + header->header.offset; /* Line 368, Address: 0x1001cac */


    ++read_count; /* Line 371, Address: 0x1001cb8 */
    for (i = 0; i < read_count; ++i) { /* Line 372, Address: 0x1001cbc */




      flag4 = 0; /* Line 377, Address: 0x1001cc8 */

      if (i > 31) /* Line 379, Address: 0x1001ccc */
        s = &header->spr[i - 1]; /* Line 380, Address: 0x1001cd8 */
      else
        s = &header->spr[i]; /* Line 382, Address: 0x1001cf8 */

      wx = s->wx; /* Line 384, Address: 0x1001d0c */
      wy = s->wy; /* Line 385, Address: 0x1001d18 */








      if (i == 3) /* Line 394, Address: 0x1001d24 */
        bmp = hmx_bitmap_create_module(env, 248, 8); /* Line 395, Address: 0x1001d30 */
      else if (i == 31) { /* Line 396, Address: 0x1001d58 */
        bmp = hmx_bitmap_create_module(env, 40, 16); /* Line 397, Address: 0x1001d64 */
        wx = wy = 0; /* Line 398, Address: 0x1001d84 */
      } else { /* Line 399, Address: 0x1001d8c */
        wx = (infoSprtBmp[i].w + 7) / 8 * 8; /* Line 400, Address: 0x1001d94 */
        wy = infoSprtBmp[i].h; /* Line 401, Address: 0x1001dcc */
        bmp = hmx_bitmap_create_module(env, wx, wy); /* Line 402, Address: 0x1001de4 */
      }

      if (wx & 4) { /* Line 405, Address: 0x1001e04 */
        wx += 4; /* Line 406, Address: 0x1001e10 */
        flag4 = 1; /* Line 407, Address: 0x1001e14 */
      }

      if (i != 24 && i != 3 && i != 31) /* Line 410, Address: 0x1001e18 */
        ld_bitmap_4to8_1(hmx_bitmap_get_scan0_module(bmp), pixbuf, wx, wy, infoSprtBmp[i].palOff, 1, flag4); /* Line 411, Address: 0x1001e3c */
      else if (i == 24) /* Line 412, Address: 0x1001e90 */
        ld_bitmap_4to8_2(hmx_bitmap_get_scan0_module(bmp), pixbuf, wx, wy, infoSprtBmp[i].palOff, 1, flag4); /* Line 413, Address: 0x1001e9c */
      else if (i == 31) /* Line 414, Address: 0x1001ef0 */
        ld_bitmap_file("TITLE\\OPENING\\EXIT.BMP" , hmx_bitmap_get_scan0_module(bmp), 40, 16, infoSprtBmp[i].palOff, 1); /* Line 415, Address: 0x1001efc */
      else



        ld_bitmap_file("TITLE\\OPENING\\1996SEGA.BMP", hmx_bitmap_get_scan0_module(bmp), 248, 8, 0, 1); /* Line 420, Address: 0x1001f50 */




      pixbuf += wx * wy / 2; /* Line 425, Address: 0x1001f88 */

      if (flag4 != 0) { /* Line 427, Address: 0x1001fb0 */
        wx -= 4; /* Line 428, Address: 0x1001fb8 */
      }

      hmx_bitmap_set_transparency_module(bmp, 255); /* Line 431, Address: 0x1001fbc */

      bitmaps[i] = bmp; /* Line 433, Address: 0x1001fd4 */
    } /* Line 434, Address: 0x1001fe4 */














































    count = read_count; /* Line 481, Address: 0x1001ff4 */
  }


  if (expbuf != 0) { /* Line 485, Address: 0x1001ff8 */
    hmx_free_module(buffer, expbuf); /* Line 486, Address: 0x1002000 */
  }

  return count; /* Line 489, Address: 0x1002018 */
} /* Line 490, Address: 0x100201c */







int ld_load_sprite1(hmx_environment* buffer, char* file, hmx_environment* env, hmx_bitmap** bitmaps, int size) { /* Line 498, Address: 0x1002050 */
  int count = -1; /* Line 499, Address: 0x1002090 */

  void* expbuf = 0; /* Line 501, Address: 0x1002098 */
  ld_sprite_header* header;
  int read_count;
  unsigned char* pixbuf;
  int i;
  ld_sprite_inf* s;
  int flag4, wx, wy;
  hmx_bitmap* bmp;
  for (i = 0; i < size; ++i) { /* Line 509, Address: 0x100209c */
    bitmaps[i] = 0; /* Line 510, Address: 0x10020a8 */
  } /* Line 511, Address: 0x10020b8 */

  expbuf = ld_load_cmpfile_module(buffer, file); /* Line 513, Address: 0x10020cc */
  if (expbuf != 0) { /* Line 514, Address: 0x10020e8 */



    header = expbuf; /* Line 518, Address: 0x10020f0 */
    read_count = header->header.count; /* Line 519, Address: 0x10020f4 */
    if (size < read_count) { /* Line 520, Address: 0x10020f8 */
      read_count = size; /* Line 521, Address: 0x1002108 */
    }

    pixbuf = (unsigned char*)expbuf + header->header.offset; /* Line 524, Address: 0x100210c */

    for (i = 0; i < read_count; ++i) { /* Line 526, Address: 0x1002118 */
      s = &header->spr[i]; /* Line 527, Address: 0x1002124 */

      flag4 = 0; /* Line 529, Address: 0x1002138 */
      wx = s->wx; /* Line 530, Address: 0x100213c */
      wy = s->wy; /* Line 531, Address: 0x1002148 */



      wx = (s->wx + 7) / 8 * 8; /* Line 535, Address: 0x1002154 */
      bmp = hmx_bitmap_create_module(env, wx, wy); /* Line 536, Address: 0x1002180 */

      if (wx & 4) { /* Line 538, Address: 0x10021a0 */
        wx += 4; /* Line 539, Address: 0x10021ac */
        flag4 = 1; /* Line 540, Address: 0x10021b0 */
      }

      ld_bitmap_4to8_1(hmx_bitmap_get_scan0_module(bmp), pixbuf, wx, wy, infoSprtBmp[i].palOff, 1, flag4); /* Line 543, Address: 0x10021b4 */

      pixbuf += wx * wy / 2; /* Line 545, Address: 0x1002200 */

      if (flag4 != 0) { /* Line 547, Address: 0x1002228 */
        wx -= 4; /* Line 548, Address: 0x1002230 */
      }

      hmx_bitmap_set_transparency_module(bmp, 255); /* Line 551, Address: 0x1002234 */

      bitmaps[i] = bmp; /* Line 553, Address: 0x100224c */
    } /* Line 554, Address: 0x100225c */

    count = read_count; /* Line 556, Address: 0x100226c */
  }


  if (expbuf != 0) { /* Line 560, Address: 0x1002270 */
    hmx_free_module(buffer, expbuf); /* Line 561, Address: 0x1002278 */
  }

  return count; /* Line 564, Address: 0x1002290 */
} /* Line 565, Address: 0x1002294 */












































































































int ld_load_grid2(hmx_environment* buffer, char* file, hmx_environment* env, hmx_bitmap** bitmaps, int size) { /* Line 674, Address: 0x10022d0 */
  int count = -1; /* Line 675, Address: 0x1002310 */

  void* expbuf = 0; /* Line 677, Address: 0x1002318 */
  ld_scroll_header* header;
  int read_count;
  unsigned char* pixbuf;
  int i, n, palet, paletcnt, palet_offs;
  int wx, wy;
  hmx_bitmap* bmp;

  palet = 0; /* Line 685, Address: 0x100231c */
  paletcnt = 0; /* Line 686, Address: 0x1002320 */
  palet_offs = 0; /* Line 687, Address: 0x1002324 */

  for (i = 0; i < size; ++i) { /* Line 689, Address: 0x1002328 */
    bitmaps[i] = 0; /* Line 690, Address: 0x1002334 */
  } /* Line 691, Address: 0x1002344 */

  expbuf = ld_load_cmpfile_module(buffer, file); /* Line 693, Address: 0x1002358 */
  if (expbuf != 0) { /* Line 694, Address: 0x1002374 */



    header = expbuf; /* Line 698, Address: 0x100237c */
    read_count = header->header.count; /* Line 699, Address: 0x1002380 */
    if (size < read_count) { /* Line 700, Address: 0x1002384 */
      read_count = size; /* Line 701, Address: 0x1002394 */
    }

    pixbuf = (unsigned char*)expbuf + header->header.offset; /* Line 704, Address: 0x1002398 */

    for (i = 0; i < NUM_GRIDBMP; ++i) { /* Line 706, Address: 0x10023a0 */

      palet_offs = infoGridBmp[i].palOff; /* Line 708, Address: 0x10023ac */
      for (n = 0; n < infoGridBmp[i].totalNum; ++n) { /* Line 709, Address: 0x10023d0 */

        wx = (infoGridBmp[i].w + 7) / 8 * 8; /* Line 711, Address: 0x10023dc */
        wy = infoGridBmp[i].h; /* Line 712, Address: 0x100241c */
        bmp = hmx_bitmap_create_module(env, wx, wy); /* Line 713, Address: 0x100243c */

        ld_bitmap_4to8_module(hmx_bitmap_get_scan0_module(bmp), pixbuf, wx, wy, palet_offs, 0, 0); /* Line 715, Address: 0x100245c */








        pixbuf += wx * wy / 2; /* Line 724, Address: 0x100249c */

        hmx_bitmap_set_transparency_module(bmp, 0); /* Line 726, Address: 0x10024bc */

        bitmaps[i] = bmp; /* Line 728, Address: 0x10024d4 */

        infoGridBmp[i].lphBmp[n] = (unsigned int*)bitmaps[i]; /* Line 730, Address: 0x10024e4 */
      } /* Line 731, Address: 0x100251c */
    } /* Line 732, Address: 0x100254c */

    count = read_count; /* Line 734, Address: 0x1002568 */
  }


  if (expbuf != 0) { /* Line 738, Address: 0x100256c */
    hmx_free_module(buffer, expbuf); /* Line 739, Address: 0x1002574 */
  }

  return count; /* Line 742, Address: 0x100258c */
} /* Line 743, Address: 0x1002590 */




int OEGridBmpCreate() { /* Line 748, Address: 0x10025d0 */
  int i, count;

  s_ctx->grd_bitmap_count = 0; /* Line 751, Address: 0x10025e0 */
  for (i = 0; i < 2048; ++i) { /* Line 752, Address: 0x10025ec */
    s_ctx->grd_bitmaps[i] = 0; /* Line 753, Address: 0x10025f8 */
  } /* Line 754, Address: 0x100260c */

  count = ld_load_grid2(g_loader_module, TileCmpFileName, g_env_module, s_ctx->grd_bitmaps, 2048); /* Line 756, Address: 0x100261c */





  if (count <= 0) { /* Line 762, Address: 0x1002650 */
    return -1; /* Line 763, Address: 0x1002658 */
  }

  s_ctx->grd_bitmap_count = count; /* Line 766, Address: 0x1002664 */

  return 0; /* Line 768, Address: 0x1002670 */
} /* Line 769, Address: 0x1002674 */




void OEGridBmpDelete() { /* Line 774, Address: 0x1002690 */
  int i, n;

  for (i = 0; i < NUM_GRIDBMP; ++i) { /* Line 777, Address: 0x10026a0 */

    for (n = 0; n < infoGridBmp[i].totalNum; ++n) { /* Line 779, Address: 0x10026ac */

      if (infoGridBmp[i].lphBmp[n] != 0) { /* Line 781, Address: 0x10026b8 */

        hmx_bitmap_release_module(g_env_module, (hmx_bitmap*)infoGridBmp[i].lphBmp[n]); /* Line 783, Address: 0x10026e8 */
        infoGridBmp[i].lphBmp[n] = 0; /* Line 784, Address: 0x1002728 */
      }
    } /* Line 786, Address: 0x1002750 */
  } /* Line 787, Address: 0x1002780 */
  s_ctx->grd_bitmap_count = 0; /* Line 788, Address: 0x100279c */
  for (i = 0; i < 2048; ++i) /* Line 789, Address: 0x10027a8 */
    s_ctx->grd_bitmaps[i] = 0; /* Line 790, Address: 0x10027b4 */















} /* Line 806, Address: 0x10027d8 */




int OESprBmpCreate() { /* Line 811, Address: 0x10027f0 */
  int i;
  int count;

  s_ctx->spr_bitmap_count = 0; /* Line 815, Address: 0x1002800 */
  for (i = 0; i < 1000; ++i) { /* Line 816, Address: 0x100280c */
    s_ctx->spr_bitmaps[i] = 0; /* Line 817, Address: 0x1002818 */
    s_ctx->spr_level[i] = 0; /* Line 818, Address: 0x100282c */
  } /* Line 819, Address: 0x1002840 */

#if defined(OPENING)
  count = ld_load_sprite2(g_loader_module, SprCmpFileName, g_env_module, s_ctx->spr_bitmaps, 1000); /* Line 822, Address: 0x1005710 */
#endif




#if !defined(OPENING)
  count = ld_load_sprite1(g_loader_module, SprCmpFileName, g_env_module, s_ctx->spr_bitmaps, 1000); /* Line 829, Address: 0x1002850 */
#endif





  if (count <= 0) { /* Line 836, Address: 0x1002884 */
    return -1; /* Line 837, Address: 0x100288c */
  }

  s_ctx->spr_bitmap_count = count; /* Line 840, Address: 0x1002898 */
  for (i = 0; i < NUM_BMP; ++i) { /* Line 841, Address: 0x10028a4 */
    infoSprtBmp[i].hBmp = (unsigned int*)s_ctx->spr_bitmaps[i]; /* Line 842, Address: 0x10028b0 */
  } /* Line 843, Address: 0x10028d8 */

  return 0; /* Line 845, Address: 0x10028f4 */
} /* Line 846, Address: 0x10028f8 */




void OESprBmpDelete() { /* Line 851, Address: 0x1002910 */
  int i;

  s_ctx->spr_bitmap_count = 0; /* Line 854, Address: 0x100291c */
  for (i = 0; i < 1000; ++i) { /* Line 855, Address: 0x1002928 */
    hmx_bitmap_release_module(g_env_module, s_ctx->spr_bitmaps[i]); /* Line 856, Address: 0x1002934 */
    s_ctx->spr_bitmaps[i] = 0; /* Line 857, Address: 0x1002960 */
    s_ctx->spr_level[i] = 0; /* Line 858, Address: 0x1002974 */
  } /* Line 859, Address: 0x1002988 */
} /* Line 860, Address: 0x1002998 */




int OESprCreate(unsigned short timing) { /* Line 865, Address: 0x10029b0 */
  int i;

  for (i = 0; i < NUM_BMP; ++i) { /* Line 868, Address: 0x10029c0 */

    if (timing != infoSprtBmp[i].timing) continue; /* Line 870, Address: 0x10029cc */

    if (*infoSprtBmp[i].lphSpr != 0) continue; /* Line 872, Address: 0x10029f4 */

    sprCreate((int*)infoSprtBmp[i].lphSpr); /* Line 874, Address: 0x1002a14 */
    hmx_sprite_set_position_module(s_ctx->sprites[*infoSprtBmp[i].lphSpr], infoSprtBmp[i].point.x, infoSprtBmp[i].point.y); /* Line 875, Address: 0x1002a30 */
    hmx_sprite_set_bitmap_module(s_ctx->sprites[*infoSprtBmp[i].lphSpr], s_ctx->spr_bitmaps[i]); /* Line 876, Address: 0x1002a98 */
    hmx_sprite_set_flags_module(s_ctx->sprites[*infoSprtBmp[i].lphSpr], 0); /* Line 877, Address: 0x1002aec */
    s_ctx->spr_level[*infoSprtBmp[i].lphSpr] = PRIO_MAX - infoSprtBmp[i].order; /* Line 878, Address: 0x1002b30 */
  } /* Line 879, Address: 0x1002b78 */

  return 0; /* Line 881, Address: 0x1002b94 */


















} /* Line 900, Address: 0x1002b98 */




int OESprCreateIndx(int indx) { /* Line 905, Address: 0x1002bb0 */

  if (*infoSprtBmp[indx].lphSpr != 0) /* Line 907, Address: 0x1002bbc */
    return 0; /* Line 908, Address: 0x1002be0 */
  sprCreate((int*)infoSprtBmp[indx].lphSpr); /* Line 909, Address: 0x1002bec */
  hmx_sprite_set_position_module(s_ctx->sprites[*infoSprtBmp[indx].lphSpr], infoSprtBmp[indx].point.x, infoSprtBmp[indx].point.y); /* Line 910, Address: 0x1002c0c */
  hmx_sprite_set_bitmap_module(s_ctx->sprites[*infoSprtBmp[indx].lphSpr], s_ctx->spr_bitmaps[indx]); /* Line 911, Address: 0x1002c80 */
  hmx_sprite_set_flags_module(s_ctx->sprites[*infoSprtBmp[indx].lphSpr], 0); /* Line 912, Address: 0x1002cdc */
  s_ctx->spr_level[*infoSprtBmp[indx].lphSpr] = PRIO_MAX - infoSprtBmp[indx].order; /* Line 913, Address: 0x1002d24 */
  return 0; /* Line 914, Address: 0x1002d74 */












} /* Line 927, Address: 0x1002d78 */




void OESprDelete(unsigned short timing) { /* Line 932, Address: 0x1002d90 */
  int i;

  for (i = 0; i < NUM_BMP; ++i) { /* Line 935, Address: 0x1002da0 */

    if (timing != infoSprtBmp[i].timing) continue; /* Line 937, Address: 0x1002dac */

    if (*infoSprtBmp[i].lphSpr == 0) continue; /* Line 939, Address: 0x1002dd4 */

    hmx_sprite_set_bitmap_module(s_ctx->sprites[*infoSprtBmp[i].lphSpr], 0); /* Line 941, Address: 0x1002df4 */
    hmx_sprite_set_flags_module(s_ctx->sprites[*infoSprtBmp[i].lphSpr], 0); /* Line 942, Address: 0x1002e38 */
    s_ctx->spr_level[*infoSprtBmp[i].lphSpr] = 0; /* Line 943, Address: 0x1002e7c */
    sprDelete(*infoSprtBmp[i].lphSpr); /* Line 944, Address: 0x1002ea8 */
    *infoSprtBmp[i].lphSpr = 0; /* Line 945, Address: 0x1002ec8 */

  } /* Line 947, Address: 0x1002ee0 */














} /* Line 962, Address: 0x1002efc */




void OESprDeleteIndx(int indx) { /* Line 967, Address: 0x1002f10 */


#if !defined(OPENING)
  if (*infoSprtBmp[indx].lphSpr == 0) return; /* Line 971, Address: 0x1002f1c */

  hmx_sprite_set_bitmap_module(s_ctx->sprites[*infoSprtBmp[indx].lphSpr], 0); /* Line 973, Address: 0x1002f40 */
  hmx_sprite_set_flags_module(s_ctx->sprites[*infoSprtBmp[indx].lphSpr], 0); /* Line 974, Address: 0x1002f88 */
  s_ctx->spr_level[*infoSprtBmp[indx].lphSpr] = 0; /* Line 975, Address: 0x1002fd0 */
  sprDelete(*infoSprtBmp[indx].lphSpr); /* Line 976, Address: 0x1003000 */
  *infoSprtBmp[indx].lphSpr = 0; /* Line 977, Address: 0x1003024 */
#endif











} /* Line 990, Address: 0x1003040 */




void OEAllSprDelete() { /* Line 995, Address: 0x1003050 */
  int i;

  for (i = 0; i < NUM_BMP; ++i) { /* Line 998, Address: 0x100305c */

    if (*infoSprtBmp[i].lphSpr == 0) continue; /* Line 1000, Address: 0x1003068 */

    hmx_sprite_set_bitmap_module(s_ctx->sprites[*infoSprtBmp[i].lphSpr], 0); /* Line 1002, Address: 0x1003088 */
    hmx_sprite_set_flags_module(s_ctx->sprites[*infoSprtBmp[i].lphSpr], 0); /* Line 1003, Address: 0x10030cc */
    s_ctx->spr_level[*infoSprtBmp[i].lphSpr] = 0; /* Line 1004, Address: 0x1003110 */
    sprDelete(*infoSprtBmp[i].lphSpr); /* Line 1005, Address: 0x100313c */
    *infoSprtBmp[i].lphSpr = 0; /* Line 1006, Address: 0x100315c */

  } /* Line 1008, Address: 0x1003174 */
} /* Line 1009, Address: 0x1003190 */


int OEGridDeleteAll() { /* Line 1012, Address: 0x10031b0 */
  int i;
  for (i = 0; i < 3; ++i) { /* Line 1014, Address: 0x10031bc */
    hmx_grid_release_module(g_env_module, s_ctx->grids[i]); /* Line 1015, Address: 0x10031c8 */
    s_ctx->grids[i] = 0; /* Line 1016, Address: 0x10031f4 */
  } /* Line 1017, Address: 0x1003208 */

  return 0; /* Line 1019, Address: 0x1003218 */
} /* Line 1020, Address: 0x100321c */




int OECreateEA() { /* Line 1025, Address: 0x1003230 */
  int i;
  for (i = 0; i < 512; ++i) /* Line 1027, Address: 0x100323c */
    sprIdx[i] = 0; /* Line 1028, Address: 0x1003248 */
  OEGridDeleteAll(); /* Line 1029, Address: 0x100326c */
  if (OESprBmpCreate() != 0) return 0; /* Line 1030, Address: 0x1003274 */
  if (OEGridBmpCreate() != 0) return 0; /* Line 1031, Address: 0x1003290 */


  return 1; /* Line 1034, Address: 0x10032ac */
} /* Line 1035, Address: 0x10032b0 */




void OEDeleteEA() { /* Line 1040, Address: 0x10032d0 */
  int i;
  OESprBmpDelete(); /* Line 1042, Address: 0x10032dc */
  OEAllSprDelete(); /* Line 1043, Address: 0x10032e4 */
  OEGridBmpDelete(); /* Line 1044, Address: 0x10032ec */
  OEAllGridDelete(); /* Line 1045, Address: 0x10032f4 */
  for (i = 0; i < 3; ++i) { /* Line 1046, Address: 0x10032fc */
    s_ctx->grids[i] = hmx_grid_create_module(g_env_module, 8, 8, 64, 32); /* Line 1047, Address: 0x1003308 */



  } /* Line 1051, Address: 0x1003344 */

  s_ctx->grd_bitmap_count = 0; /* Line 1053, Address: 0x1003354 */

} /* Line 1055, Address: 0x1003360 */


void sprCreate(int* handle) { /* Line 1058, Address: 0x1003380 */
  int i;
  for (i = 1; i < 512; ++i) { /* Line 1060, Address: 0x100338c */
    if (sprIdx[i] == 0) { /* Line 1061, Address: 0x1003398 */
      sprIdx[i] = 1; /* Line 1062, Address: 0x10033b4 */
      *handle = i; /* Line 1063, Address: 0x10033cc */







      return; /* Line 1071, Address: 0x10033d4 */
    }
  } /* Line 1073, Address: 0x10033dc */
} /* Line 1074, Address: 0x10033ec */


void sprDelete(int handle) { /* Line 1077, Address: 0x1003400 */







  if (sprIdx[handle] == 1) /* Line 1085, Address: 0x1003408 */
    sprIdx[handle] = 0; /* Line 1086, Address: 0x100342c */
} /* Line 1087, Address: 0x1003444 */
