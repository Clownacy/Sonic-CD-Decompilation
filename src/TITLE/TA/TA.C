#include "..\..\TYPES.H"
#include "..\COMMON\SCORE_DATA_TYPES.H"
#include "..\COMMON\HMX_TYPES.H"
#include "TA.H"
#include "FADEIN.H"
#include "TACOLOR.H"
#include "TAEACTRL.H"

int gMove;
int gRankY;
int gRankX;
static int bExit;
extern hmx_environment* g_env_module;
extern hmx_environment* g_loader_module;
ushort_union swdata2;
ushort_union swdata1;
score_data* lpScoreData;
static unsigned short KeyRepTimer;
int gNewMenu2;
int gMenu2;
int gMenu1;
int gMenuZone;
int gMenuRound;
static int gRet;
int gNewMenuZone;
int gNewRankX;
unsigned int(*WriteScoreData2)(int, char*, unsigned int);
void(*SetScoreDate2)(score_data*);
int(*ReadScoreIndx2)(unsigned int);
int gNewMenuRound;
int gNewMenu1;
game_info* lpKeepWork;
unsigned int gTimer;
void(*CDPause)(short);
void(*CDPlay)(short);
char*(*sStrncpy)(char*, char*, int);
int(*sStrncmp)(char*, char*, int);
draw_context* s_ctx;
draw_context*(*get_draw_context_module)();
int* lpFadeFlag;
int_union* lphscrollbuff;
palette_entry* lpcolorwk4;
palette_entry* lpcolorwk3;
palette_entry* lpcolorwk2;
palette_entry* lpcolorwk;
unsigned short* pmapwk;
void(*hmx_sprite_set_bitmap_module)(hmx_sprite*, hmx_bitmap*);
void(*hmx_sprite_set_position_module)(hmx_sprite*, int, int);
hmx_renderer_base*(*hmx_sprite_base_module)(hmx_sprite*);
void(*hmx_renderer_context_draw_module)(hmx_renderer_context*, hmx_surface*);
void(*hmx_renderer_context_clear_module)(hmx_renderer_context*);
void(*hmx_renderer_context_add_module)(hmx_renderer_context*, int, hmx_renderer_base*);
void(*hmx_grid_set_tile_module)(hmx_grid*, int, int, hmx_bitmap*, int);
void(*hmx_grid_set_view_module)(hmx_grid*, int, int, int, int);
void(*hmx_grid_set_position_module)(hmx_grid*, int, int);
hmx_renderer_base*(*hmx_grid_base_module)(hmx_grid*);
void(*hmx_grid_release_module)(hmx_environment*, hmx_grid*);
hmx_grid*(*hmx_grid_create_module)(hmx_environment*, int, int, int, int);
void(*hmx_free_module)(hmx_environment*, void*);
void(*hmx_bitmap_set_transparency_module)(hmx_bitmap*, int);
void*(*hmx_bitmap_get_scan0_module)(hmx_bitmap*);
void(*hmx_bitmap_release_module)(hmx_environment*, hmx_bitmap*);
hmx_bitmap*(*hmx_bitmap_create_module)(hmx_environment*, int, int);
void(*hmx_background_set_background_module)(hmx_background*, int);
void*(*ld_load_cmpfile_module)(hmx_environment*, char*);
void(*ld_bitmap_4to8_module)(void*, void*, int, int, int, int, int);
void(*FlipToScreen_module)();
void(*sCloseFile)(int);
int(*sReadFile)(int, void*, int);
int(*sOpenFile)(char*);
void(*sOutputDebugString)(char*);
void(*sPrintf)(char*, const char*, ...);
void(*sMemFree)(void*);
void*(*sMemAlloc)(int);
dlink_export ExportedFunctions = {
  &game_init,
  (void (*)())&game,
  &DLL_meminit,
  &DLL_memfree,
  (void (*)(short, short))&SWdataSet,
  0,
  0,
  0,
  FadeProc,
  0,
  0,
  0
};
unsigned int ghWnd;
unsigned int hSurf;























































void SWdataSet(ushort_union sw1, ushort_union sw2) { /* Line 146, Address: 0x1000000 */
  swdata1.w = sw1.w; /* Line 147, Address: 0x100000c */
  swdata2.w = sw2.w; /* Line 148, Address: 0x1000018 */

} /* Line 150, Address: 0x1000024 */






unsigned int SpecialPlayChk() {
  if (lpScoreData->total < 109269 && lpScoreData->roundNo >= 7) { /* Line 158, Address: 0x1000030 */

    return 1; /* Line 160, Address: 0x1000068 */
  }
  return 0; /* Line 162, Address: 0x1000074 */

} /* Line 164, Address: 0x1000078 */


int GetPlayRound() { /* Line 167, Address: 0x1000080 */
  int ret;

  ret = 1; /* Line 170, Address: 0x1000088 */

  if (lpScoreData->roundNo != 0) { /* Line 172, Address: 0x100008c */
    ret = lpScoreData->roundNo; /* Line 173, Address: 0x10000a0 */
    if (ret > 7) ret = 7; /* Line 174, Address: 0x10000b0 */
  }



  return ret; /* Line 179, Address: 0x10000c0 */
} /* Line 180, Address: 0x10000c4 */















int game() { /* Line 196, Address: 0x10000e0 */
  char c;
  int index;

  ++gTimer; /* Line 200, Address: 0x10000f4 */
  if (lpKeepWork->bRestart) { /* Line 201, Address: 0x1000108 */
    lpKeepWork->bRestart = 0; /* Line 202, Address: 0x100011c */
    bExit = 1; /* Line 203, Address: 0x1000128 */
    gRet = -1; /* Line 204, Address: 0x1000134 */
  }
  if (bExit != 0) { /* Line 206, Address: 0x1000140 */

    DeleteEA(); /* Line 208, Address: 0x1000150 */



    CDPause(2); /* Line 212, Address: 0x1000158 */
    return gRet; /* Line 213, Address: 0x100016c */
  }
  if (gMenu1 == 1 && gMenuRound == 6 && gMove == 0) { /* Line 215, Address: 0x100017c */
    if (gTimer % 4 == 0) { /* Line 216, Address: 0x10001b4 */
      TAColorChgSP6(); /* Line 217, Address: 0x10001cc */
    }
  }



  if (gMove == 0) { /* Line 223, Address: 0x10001d4 */

    if (gMenu2 == 0) { /* Line 225, Address: 0x10001e4 */

      if (swdata1.b.l & 64) { /* Line 227, Address: 0x10001f4 */
        if (gMenuRound == 0) { /* Line 228, Address: 0x100020c */

          bExit = 1; /* Line 230, Address: 0x100021c */
          gRet = -1; /* Line 231, Address: 0x1000228 */
          clwout(); /* Line 232, Address: 0x1000234 */
          return 0; /* Line 233, Address: 0x100023c */
        }


        if (gMenu1 == 0) { /* Line 237, Address: 0x1000248 */
          gNewMenu2 = 2; /* Line 238, Address: 0x1000258 */
          gMove = 1; /* Line 239, Address: 0x1000264 */
        } /* Line 240, Address: 0x1000270 */
        else {
          gNewMenu2 = 1; /* Line 242, Address: 0x1000278 */
          gMove = 2; /* Line 243, Address: 0x1000284 */
        }
        gNewMenuZone = gMenuZone = 0; /* Line 245, Address: 0x1000290 */

      } /* Line 247, Address: 0x10002a0 */
      else if (swdata1.b.h & 4) { /* Line 248, Address: 0x10002a8 */
        if (gMenu1 == 0 && SpecialPlayChk() == 1) { /* Line 249, Address: 0x10002c0 */

          gMove = 5; /* Line 251, Address: 0x10002e4 */
          gNewMenu1 = 1; /* Line 252, Address: 0x10002f0 */
        }
      } /* Line 254, Address: 0x10002fc */
      else if (swdata1.b.h & 8) { /* Line 255, Address: 0x1000304 */
        if (gMenu1 == 1) { /* Line 256, Address: 0x100031c */

          gMove = 6; /* Line 258, Address: 0x1000330 */
          gNewMenu1 = 0; /* Line 259, Address: 0x100033c */
        }
      } /* Line 261, Address: 0x1000344 */
      else if (swdata1.b.h & 1) { /* Line 262, Address: 0x100034c */

        gMove = 7; /* Line 264, Address: 0x1000364 */
        gNewMenuRound = gMenuRound - 1; /* Line 265, Address: 0x1000370 */
        if (gNewMenuRound < 0) gNewMenuRound = GetPlayRound(); /* Line 266, Address: 0x1000384 */
      } /* Line 267, Address: 0x10003a4 */
      else if (swdata1.b.h & 2) { /* Line 268, Address: 0x10003ac */

        gMove = 7; /* Line 270, Address: 0x10003c4 */
        gNewMenuRound = gMenuRound + 1; /* Line 271, Address: 0x10003d0 */
        if (gNewMenuRound > GetPlayRound()) gNewMenuRound = 0; /* Line 272, Address: 0x10003e4 */
      }
    } /* Line 274, Address: 0x1000408 */

    else if (gMenu2 == 4) { /* Line 276, Address: 0x1000410 */

      if (swdata1.b.l) { /* Line 278, Address: 0x1000424 */
        gNewMenu2 = 5; /* Line 279, Address: 0x1000434 */
        gMove = 11; /* Line 280, Address: 0x1000440 */
      }
    } /* Line 282, Address: 0x100044c */

    else if (gMenu2 == 5) { /* Line 284, Address: 0x1000454 */

      if (swdata1.b.h & 64) { /* Line 286, Address: 0x1000468 */
        if (gRankX == 2) { /* Line 287, Address: 0x1000480 */
          gNewMenu2 = 3; /* Line 288, Address: 0x1000494 */
          gMove = 12; /* Line 289, Address: 0x10004a0 */

          index = ReadScoreIndx2(0); /* Line 291, Address: 0x10004ac */
          if (index != -1) { /* Line 292, Address: 0x10004c4 */
            SetScoreDate2(0); /* Line 293, Address: 0x10004d0 */
            WriteScoreData2(index, 0, 0); /* Line 294, Address: 0x10004e4 */
          }
        } /* Line 296, Address: 0x1000500 */
        else {

          swdata1.b.l |= 8; /* Line 299, Address: 0x1000508 */
        }
      }
      if (gMove == 0 && swdata1.b.l & 4) { /* Line 302, Address: 0x100051c */
        if (gRankX != 0) { /* Line 303, Address: 0x1000544 */
          gNewRankX = gRankX - 1; /* Line 304, Address: 0x1000554 */
          gMove = 12; /* Line 305, Address: 0x1000568 */
        }
      } /* Line 307, Address: 0x1000574 */
      else if (gMove == 0 && swdata1.b.l & 8) { /* Line 308, Address: 0x100057c */
        if (gRankX < 2) { /* Line 309, Address: 0x10005a4 */
          gNewRankX = gRankX + 1; /* Line 310, Address: 0x10005b8 */
          gMove = 12; /* Line 311, Address: 0x10005cc */
        }
      } /* Line 313, Address: 0x10005d8 */
      else if (gMove == 0) { /* Line 314, Address: 0x10005e0 */
        if (swdata1.b.h & 3) { /* Line 315, Address: 0x10005f0 */
          ++KeyRepTimer; /* Line 316, Address: 0x1000608 */
        } /* Line 317, Address: 0x100061c */
        else if (swdata1.b.l & 3) { /* Line 318, Address: 0x1000624 */
          KeyRepTimer = 15; /* Line 319, Address: 0x100063c */
        }

        if (KeyRepTimer > 15) { /* Line 322, Address: 0x1000648 */
          KeyRepTimer = 0; /* Line 323, Address: 0x1000660 */
          if (gMenu1 == 0) { /* Line 324, Address: 0x1000668 */
            c = lpScoreData->timeattack[gMenuRound - 1][gMenuZone][gRankY].name[gRankX]; /* Line 325, Address: 0x1000678 */
          } /* Line 326, Address: 0x10006dc */
          else {
            c = lpScoreData->special[gMenuRound - 1][gRankY].name[gRankX]; /* Line 328, Address: 0x10006e4 */
          }
          if (swdata1.b.h & 2) ++c; /* Line 330, Address: 0x1000730 */
          else --c; /* Line 331, Address: 0x100075c */


          if (c < 48) c = 90; /* Line 334, Address: 0x1000768 */
          else if (c > 90) c = 48; /* Line 335, Address: 0x1000790 */
          else if (c == 58) c = 65; /* Line 336, Address: 0x10007b8 */
          else if (c == 64) c = 57; /* Line 337, Address: 0x10007e0 */

          if (gMenu1 == 0) { /* Line 339, Address: 0x1000800 */
            lpScoreData->timeattack[gMenuRound - 1][gMenuZone][gRankY].name[gRankX] = c; /* Line 340, Address: 0x1000810 */
          } /* Line 341, Address: 0x100086c */
          else {
            lpScoreData->special[gMenuRound - 1][gRankY].name[gRankX] = c; /* Line 343, Address: 0x1000874 */
          }
          gMove = 12; /* Line 345, Address: 0x10008b8 */
        }
      }
    } /* Line 348, Address: 0x10008c4 */
    else {


      if (gMenu2 == 2) { /* Line 352, Address: 0x10008cc */
        if (swdata1.b.h & 1) { /* Line 353, Address: 0x10008e0 */
          if (gMenu1 == 0) { /* Line 354, Address: 0x10008f8 */

            gMove = 8; /* Line 356, Address: 0x1000908 */
            if (--gNewMenuZone < 0) { /* Line 357, Address: 0x1000914 */
              gNewMenuZone = 2; /* Line 358, Address: 0x1000930 */
            }
          }
        } /* Line 361, Address: 0x100093c */
        else if ((swdata1.b.h & 2) || swdata1.b.h & 64) { /* Line 362, Address: 0x1000944 */

          if (gMenu1 == 0) { /* Line 364, Address: 0x1000974 */

            gMove = 9; /* Line 366, Address: 0x1000984 */
            if (++gNewMenuZone > 2) { /* Line 367, Address: 0x1000990 */
              gNewMenuZone = 0; /* Line 368, Address: 0x10009b0 */
            }
          }
        }
      } /* Line 372, Address: 0x10009b8 */
      else if (swdata1.b.l & 64) { /* Line 373, Address: 0x10009c0 */
        if (gMenu2 == 1) { /* Line 374, Address: 0x10009d8 */

          if (gMenu1 == 0) gMove = 3; /* Line 376, Address: 0x10009ec */
          else gMove = 4; /* Line 377, Address: 0x1000a10 */
          gNewMenu2 = gMenu2 = 0; /* Line 378, Address: 0x1000a1c */
        } /* Line 379, Address: 0x1000a2c */
        else if (gMenu2 == 3) { /* Line 380, Address: 0x1000a34 */

          if (gMenu1 == 0) { /* Line 382, Address: 0x1000a48 */

            gRet = (gMenuRound - 1) * 10 + gMenuZone * 4 + 400; /* Line 384, Address: 0x1000a58 */
            if (gMenuZone == 2) { /* Line 385, Address: 0x1000a8c */
              ++gRet; /* Line 386, Address: 0x1000aa0 */
            }
          } /* Line 388, Address: 0x1000ab4 */
          else {
            gRet = gMenuRound + 469; /* Line 390, Address: 0x1000abc */
          }
          bExit = 1; /* Line 392, Address: 0x1000ad0 */
          lpKeepWork->ta_Menu1 = gMenu1; /* Line 393, Address: 0x1000adc */
          lpKeepWork->ta_Round = gMenuRound; /* Line 394, Address: 0x1000af4 */
          lpKeepWork->ta_Zone = gMenuZone; /* Line 395, Address: 0x1000b0c */
          clwout(); /* Line 396, Address: 0x1000b24 */
          return 0; /* Line 397, Address: 0x1000b2c */
        }
      }
      if (gMove == 0) { /* Line 400, Address: 0x1000b38 */
        if (swdata1.b.l & 4) { /* Line 401, Address: 0x1000b48 */
          if (gMenu1 == 0) { /* Line 402, Address: 0x1000b60 */
            if (gMenu2 == 2) gNewMenu2 = 1; /* Line 403, Address: 0x1000b70 */
            else if (gMenu2 == 3) gNewMenu2 = 2; /* Line 404, Address: 0x1000b98 */
          } /* Line 405, Address: 0x1000bb8 */
          else {
            if (gMenu2 == 1) gNewMenu2 = 3; /* Line 407, Address: 0x1000bc0 */
          }
          gMove = 10; /* Line 409, Address: 0x1000be0 */
        } /* Line 410, Address: 0x1000bec */
        else if (swdata1.b.l & 8) { /* Line 411, Address: 0x1000bf4 */
          if (gMenu1 == 0) { /* Line 412, Address: 0x1000c0c */
            if (gMenu2 == 1) gNewMenu2 = 2; /* Line 413, Address: 0x1000c1c */
            else if (gMenu2 == 2) gNewMenu2 = 3; /* Line 414, Address: 0x1000c44 */
          } /* Line 415, Address: 0x1000c64 */
          else {
            if (gNewMenu2 == 3) gNewMenu2 = 1; /* Line 417, Address: 0x1000c6c */
          }
          gMove = 10; /* Line 419, Address: 0x1000c8c */
        }
      }
    }
  }

  if (gMove != 0) { /* Line 425, Address: 0x1000c98 */
    TAMove(); /* Line 426, Address: 0x1000ca8 */
  } /* Line 427, Address: 0x1000cb4 */
  else {
    Tenmetu(); /* Line 429, Address: 0x1000cbc */
  }

  DrawTA(); /* Line 432, Address: 0x1000cc4 */
  return 0; /* Line 433, Address: 0x1000ccc */
} /* Line 434, Address: 0x1000cd0 */







void game_init() { /* Line 442, Address: 0x1000cf0 */
  int i, j, k, l;
  int round;
  int zone;
  unsigned int Time;

  s_ctx = get_draw_context_module(); /* Line 448, Address: 0x1000d14 */



















  if (lpKeepWork->ta_time == -2) { /* Line 468, Address: 0x1000d2c */

    gMenu1 = gNewMenu1 = 0; /* Line 470, Address: 0x1000d44 */
    gMenu2 = gNewMenu2 = 0; /* Line 471, Address: 0x1000d54 */
    gMenuRound = gNewMenuRound = 1; /* Line 472, Address: 0x1000d64 */
    gMenuZone = gNewMenuZone = 0; /* Line 473, Address: 0x1000d78 */
  } /* Line 474, Address: 0x1000d88 */
  else {

    gMenu1 = gNewMenu1 = (unsigned short)lpKeepWork->ta_Menu1; /* Line 477, Address: 0x1000d90 */
    gMenu2 = gNewMenu2 = 3; /* Line 478, Address: 0x1000db4 */
    gMenuRound = gNewMenuRound = (unsigned short)lpKeepWork->ta_Round; /* Line 479, Address: 0x1000dc8 */
    gMenuZone = gNewMenuZone = (unsigned short)lpKeepWork->ta_Zone; /* Line 480, Address: 0x1000dec */

    if (lpKeepWork->ta_time != -1) { /* Line 482, Address: 0x1000e10 */




      round = gMenuRound - 1; /* Line 487, Address: 0x1000e28 */
      zone = gMenuZone; /* Line 488, Address: 0x1000e34 */
      for (i = 0; i < 3; ++i) { /* Line 489, Address: 0x1000e3c */
        if (gMenu1 == 0) { /* Line 490, Address: 0x1000e48 */
          if (lpScoreData->timeattack[round][zone][i].time >= lpKeepWork->ta_time) break; /* Line 491, Address: 0x1000e58 */


        } /* Line 494, Address: 0x1000ea4 */
        else {
          if (lpScoreData->special[round][i].time >= lpKeepWork->ta_time) break; /* Line 496, Address: 0x1000eac */


        }
      } /* Line 500, Address: 0x1000ee8 */
      if (i != 3) { /* Line 501, Address: 0x1000ef8 */

        gRankY = i; /* Line 503, Address: 0x1000f04 */
        gNewRankX = gRankX = 0; /* Line 504, Address: 0x1000f0c */
        gMenu2 = gNewMenu2 = 4; /* Line 505, Address: 0x1000f1c */
        for (j = 2; j > i; --j) { /* Line 506, Address: 0x1000f30 */

          if (gMenu1 == 0) { /* Line 508, Address: 0x1000f3c */
            lpScoreData->timeattack[round][zone][j].time = lpScoreData->timeattack[round][zone][j - 1].time; /* Line 509, Address: 0x1000f4c */
            sStrncpy(lpScoreData->timeattack[round][zone][j].name, lpScoreData->timeattack[round][zone][j - 1].name, 3); /* Line 510, Address: 0x1000fb8 */
          } /* Line 511, Address: 0x1001038 */
          else {
            lpScoreData->special[round][j].time = lpScoreData->special[round][j - 1].time; /* Line 513, Address: 0x1001040 */
            sStrncpy(lpScoreData->special[round][j].name, lpScoreData->special[round][j - 1].name, 3); /* Line 514, Address: 0x100108c */
          }
        } /* Line 516, Address: 0x10010ec */

        if (gMenu1 == 0) { /* Line 518, Address: 0x10010fc */
          lpScoreData->timeattack[round][zone][i].time = lpKeepWork->ta_time; /* Line 519, Address: 0x100110c */
          if (sStrncmp(lpScoreData->timeattack[round][zone][i].name, "AAA", 3) == 0) { /* Line 520, Address: 0x100114c */
            sStrncpy(lpScoreData->timeattack[round][zone][i].name, "YOU", 3); /* Line 521, Address: 0x10011a4 */
          }

          Time = 0; /* Line 524, Address: 0x10011f4 */
          for (k = 0; k < 7; ++k) { /* Line 525, Address: 0x10011f8 */
            for (l = 0; l < 3; ++l) /* Line 526, Address: 0x1001204 */
              Time += lpScoreData->timeattack[k][l][0].time; /* Line 527, Address: 0x1001210 */
          } /* Line 528, Address: 0x1001250 */
          lpScoreData->total = Time; /* Line 529, Address: 0x1001260 */
          Time < 108001; /* Line 530, Address: 0x100126c */



        } /* Line 534, Address: 0x1001278 */
        else {
          lpScoreData->special[round][i].time = lpKeepWork->ta_time; /* Line 536, Address: 0x1001280 */
          if (sStrncmp(lpScoreData->special[round][i].name, "AAA", 3) == 0) { /* Line 537, Address: 0x10012b0 */
            sStrncpy(lpScoreData->special[round][i].name, "YOU", 3); /* Line 538, Address: 0x10012f8 */
          }
        }
      }
    }
  }

  TAColorSet(0); /* Line 545, Address: 0x1001338 */
  TA_EACreate(); /* Line 546, Address: 0x1001344 */
  clwin_init(); /* Line 547, Address: 0x100134c */
  clwin(); /* Line 548, Address: 0x1001354 */
  CDPlay(33); /* Line 549, Address: 0x100135c */
} /* Line 550, Address: 0x1001370 */








void DLL_meminit(char*** pBufTbl, void** pFuncTbl) { /* Line 559, Address: 0x10013a0 */


  ++pFuncTbl; /* Line 562, Address: 0x10013ac */
  ++pFuncTbl; /* Line 563, Address: 0x10013b8 */
  ++pFuncTbl; /* Line 564, Address: 0x10013c4 */
  ++pFuncTbl; /* Line 565, Address: 0x10013d0 */
  CDPlay = *pFuncTbl++; /* Line 566, Address: 0x10013dc */
  CDPause = *pFuncTbl++; /* Line 567, Address: 0x10013f4 */
  ++pFuncTbl; /* Line 568, Address: 0x100140c */
  ReadScoreIndx2 = *pFuncTbl++; /* Line 569, Address: 0x1001418 */
  WriteScoreData2 = *pFuncTbl++; /* Line 570, Address: 0x1001430 */
  SetScoreDate2 = *pFuncTbl++; /* Line 571, Address: 0x1001448 */
  ++pFuncTbl; /* Line 572, Address: 0x1001460 */

  sMemAlloc = *pFuncTbl++; /* Line 574, Address: 0x100146c */
  sMemFree = *pFuncTbl++; /* Line 575, Address: 0x1001484 */
  ++pFuncTbl; /* Line 576, Address: 0x100149c */
  ++pFuncTbl; /* Line 577, Address: 0x10014a8 */
  ++pFuncTbl; /* Line 578, Address: 0x10014b4 */
  ++pFuncTbl; /* Line 579, Address: 0x10014c0 */
  ++pFuncTbl; /* Line 580, Address: 0x10014cc */
  sStrncpy = *pFuncTbl++; /* Line 581, Address: 0x10014d8 */
  sStrncmp = *pFuncTbl++; /* Line 582, Address: 0x10014f0 */
  sPrintf = *pFuncTbl++; /* Line 583, Address: 0x1001508 */
  sOutputDebugString = *pFuncTbl++; /* Line 584, Address: 0x1001520 */
  sOpenFile = *pFuncTbl++; /* Line 585, Address: 0x1001538 */
  sReadFile = *pFuncTbl++; /* Line 586, Address: 0x1001550 */
  sCloseFile = *pFuncTbl++; /* Line 587, Address: 0x1001568 */
  ++pFuncTbl; /* Line 588, Address: 0x1001580 */

  get_draw_context_module = *pFuncTbl++; /* Line 590, Address: 0x100158c */
  FlipToScreen_module = *pFuncTbl++; /* Line 591, Address: 0x10015a4 */
  ld_bitmap_4to8_module = *pFuncTbl++; /* Line 592, Address: 0x10015bc */
  ld_load_cmpfile_module = *pFuncTbl++; /* Line 593, Address: 0x10015d4 */
  hmx_background_set_background_module = *pFuncTbl++; /* Line 594, Address: 0x10015ec */
  hmx_bitmap_create_module = *pFuncTbl++; /* Line 595, Address: 0x1001604 */
  hmx_bitmap_release_module = *pFuncTbl++; /* Line 596, Address: 0x100161c */
  hmx_bitmap_get_scan0_module = *pFuncTbl++; /* Line 597, Address: 0x1001634 */
  hmx_bitmap_set_transparency_module = *pFuncTbl++; /* Line 598, Address: 0x100164c */
  hmx_free_module = *pFuncTbl++; /* Line 599, Address: 0x1001664 */
  hmx_grid_create_module = *pFuncTbl++; /* Line 600, Address: 0x100167c */
  hmx_grid_release_module = *pFuncTbl++; /* Line 601, Address: 0x1001694 */
  hmx_grid_base_module = *pFuncTbl++; /* Line 602, Address: 0x10016ac */
  hmx_grid_set_position_module = *pFuncTbl++; /* Line 603, Address: 0x10016c4 */
  hmx_grid_set_view_module = *pFuncTbl++; /* Line 604, Address: 0x10016dc */
  hmx_grid_set_tile_module = *pFuncTbl++; /* Line 605, Address: 0x10016f4 */
  ++pFuncTbl; /* Line 606, Address: 0x100170c */
  hmx_renderer_context_add_module = *pFuncTbl++; /* Line 607, Address: 0x1001718 */
  hmx_renderer_context_clear_module = *pFuncTbl++; /* Line 608, Address: 0x1001730 */
  hmx_renderer_context_draw_module = *pFuncTbl++; /* Line 609, Address: 0x1001748 */
  hmx_sprite_base_module = *pFuncTbl++; /* Line 610, Address: 0x1001760 */
  hmx_sprite_set_position_module = *pFuncTbl++; /* Line 611, Address: 0x1001778 */
  hmx_sprite_set_bitmap_module = *pFuncTbl++; /* Line 612, Address: 0x1001790 */


  pmapwk = (unsigned short*)**pBufTbl++; /* Line 615, Address: 0x10017a8 */
  lpcolorwk = (palette_entry*)**pBufTbl++; /* Line 616, Address: 0x10017c4 */
  lpcolorwk2 = (palette_entry*)**pBufTbl++; /* Line 617, Address: 0x10017e0 */
  lpcolorwk3 = (palette_entry*)**pBufTbl++; /* Line 618, Address: 0x10017fc */
  lpcolorwk4 = (palette_entry*)**pBufTbl++; /* Line 619, Address: 0x1001818 */
  lphscrollbuff = (int_union*)**pBufTbl++; /* Line 620, Address: 0x1001834 */
  lpFadeFlag = (int*)*pBufTbl++; /* Line 621, Address: 0x1001850 */
  lpKeepWork = (game_info*)*pBufTbl++; /* Line 622, Address: 0x1001868 */




  ++pBufTbl; /* Line 627, Address: 0x1001880 */
  ++pBufTbl; /* Line 628, Address: 0x100188c */

  lpScoreData = (score_data*)*pBufTbl++; /* Line 630, Address: 0x1001898 */

  g_env_module = (hmx_environment*)**pBufTbl++; /* Line 632, Address: 0x10018b0 */
  g_loader_module = (hmx_environment*)**pBufTbl++; /* Line 633, Address: 0x10018cc */




} /* Line 638, Address: 0x10018e8 */







void DLL_memfree() {} /* Line 646, Address: 0x1001900 */
