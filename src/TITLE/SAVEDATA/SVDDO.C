#include "..\..\TYPES.H"
#include "..\COMMON\SCORE_DATA_TYPES.H"
#include "..\COMMON\HMX_TYPES.H"
#include "SVDDO.H"

void UpdateMenu(unsigned short nMenuKind, unsigned short nMenuKindOld);

extern unsigned short nSequenceNum;
extern sprite_bmp infoSprtBmp[];
unsigned short nMenuKind;
extern void(*hmx_sprite_set_position_module)(hmx_sprite*, int, int);
extern draw_context* s_ctx;
extern score_data saveData[6];
int nFileNumber;
extern int nSelectFileNumber;
extern void(*WaveRequest)(short);
extern unsigned int bDestFileChosed;
extern unsigned int bFileChosed;
extern unsigned int bMenuChosed;
extern unsigned short swData1;
extern int nTimerCunt;
extern int keybordInputTime;
extern unsigned short swData2;





















































void SDDraw() { /* Line 77, Address: 0x1000000 */
  if (nSequenceNum >= 2) { /* Line 78, Address: 0x1000008 */

    srfDraw(); /* Line 80, Address: 0x1000020 */
  }
} /* Line 82, Address: 0x1000028 */




void SDStart() { /* Line 87, Address: 0x1000040 */
  int n;
  POINT point;


  for (n = 0; n < 4; ++n) { /* Line 92, Address: 0x100004c */

    OESprCreateIndx(n + 199); /* Line 94, Address: 0x1000058 */
  } /* Line 95, Address: 0x1000064 */
  ReadDataFile(); /* Line 96, Address: 0x1000078 */
  DispAll(); /* Line 97, Address: 0x1000080 */
  nMenuKind = 1; /* Line 98, Address: 0x1000088 */
  OESetSequenceNum(2); /* Line 99, Address: 0x1000094 */
  point.x = infoSprtBmp[0].point.x + infoSprtBmp[0].w; /* Line 100, Address: 0x10000a0 */
  point.y = infoSprtBmp[0].point.y - 8; /* Line 101, Address: 0x10000bc */
  DispSonicCursol(point); /* Line 102, Address: 0x10000cc */
} /* Line 103, Address: 0x10000d8 */




static void UpdateMenu(unsigned short nMenuKind, unsigned short nMenuKindOld) { /* Line 108, Address: 0x10000f0 */
  if (nMenuKind == nMenuKindOld) return; /* Line 109, Address: 0x1000100 */

  OESprDeleteIndx((nMenuKindOld - 1) * 2 + 1); /* Line 111, Address: 0x1000118 */
  OESprCreateIndx((nMenuKindOld - 1) * 2); /* Line 112, Address: 0x1000134 */
  OESprDeleteIndx((nMenuKind - 1) * 2); /* Line 113, Address: 0x100014c */
  OESprCreateIndx((nMenuKind - 1) * 2 + 1); /* Line 114, Address: 0x1000164 */
} /* Line 115, Address: 0x1000180 */




void DeleteFileSelect() { /* Line 120, Address: 0x1000190 */

  OESprDeleteIndx(192); /* Line 122, Address: 0x1000198 */
} /* Line 123, Address: 0x10001a4 */




void UpdateFileSelect(unsigned short nNewNumber) { /* Line 128, Address: 0x10001c0 */
  POINT point;

  DeleteFileSelect(); /* Line 131, Address: 0x10001cc */











  OESprCreateIndx(192); /* Line 143, Address: 0x10001d4 */
  point.x = infoSprtBmp[192].point.x; /* Line 144, Address: 0x10001e0 */
  point.y = infoSprtBmp[192].point.y + nNewNumber * 32; /* Line 145, Address: 0x10001ec */

  hmx_sprite_set_position_module(s_ctx->sprites[*infoSprtBmp[192].lphSpr], point.x, point.y); /* Line 147, Address: 0x1000208 */
} /* Line 148, Address: 0x1000244 */




void UpdateSelectSonicMark(unsigned short nNewNumber) { /* Line 153, Address: 0x1000260 */
  POINT point;

  if (saveData[nNewNumber].saved == 0) { /* Line 156, Address: 0x100026c */
    if (*infoSprtBmp[10].lphSpr != 0) { /* Line 157, Address: 0x10002a0 */
      OESprDeleteIndx(10); /* Line 158, Address: 0x10002b4 */
    }
    return; /* Line 160, Address: 0x10002c0 */
  }
  if (*infoSprtBmp[10].lphSpr == 0) /* Line 162, Address: 0x10002c8 */
    OESprCreateIndx(10); /* Line 163, Address: 0x10002dc */
  point.x = infoSprtBmp[10].point.x; /* Line 164, Address: 0x10002e8 */
  point.y = infoSprtBmp[10].point.y + nNewNumber * 32; /* Line 165, Address: 0x10002f4 */

  hmx_sprite_set_position_module(s_ctx->sprites[*infoSprtBmp[10].lphSpr], point.x, point.y); /* Line 167, Address: 0x1000310 */
} /* Line 168, Address: 0x100034c */




void UpdateFileView(unsigned short nFileNumber) { /* Line 173, Address: 0x1000360 */
  DeleteStringSprt(56, nFileNumber + 2, 0); /* Line 174, Address: 0x100036c */
  DispSaveData(nFileNumber); /* Line 175, Address: 0x1000388 */
} /* Line 176, Address: 0x1000398 */




void UpdateMessage(char* msg) { /* Line 181, Address: 0x10003b0 */
  DeleteStringSprt(27, 1, 0); /* Line 182, Address: 0x10003bc */
  CreateStringSprt(msg, 2, 1, 0); /* Line 183, Address: 0x10003d0 */
} /* Line 184, Address: 0x10003e8 */




void DefaultMessage() { /* Line 189, Address: 0x1000400 */
  UpdateMessage("SONIC CD DATA-FILES"); /* Line 190, Address: 0x1000408 */
} /* Line 191, Address: 0x1000418 */



unsigned int ChkSaveFile() { /* Line 195, Address: 0x1000430 */
  int i;
  for (i = 0; i < 6; ++i) { /* Line 197, Address: 0x1000438 */
    if (saveData[i].saved != 0) /* Line 198, Address: 0x1000444 */
      return 1; /* Line 199, Address: 0x1000470 */
  } /* Line 200, Address: 0x100047c */
  return 0; /* Line 201, Address: 0x100048c */
} /* Line 202, Address: 0x1000490 */



void SDMenu() { /* Line 206, Address: 0x10004a0 */
  unsigned short nMenuKindOld;
  POINT point;

  if (bMenuChosed == 0) { /* Line 210, Address: 0x10004b4 */

    if (swData1 & 512) { /* Line 212, Address: 0x10004c4 */

      nMenuKindOld = nMenuKind; /* Line 214, Address: 0x10004dc */
      nMenuKind = nMenuKind + 1 < 5 ? nMenuKind + 1 : 5; /* Line 215, Address: 0x10004e8 */
      if (nMenuKind == nMenuKindOld) return; /* Line 216, Address: 0x100052c */

      WaveRequest(9); /* Line 218, Address: 0x1000544 */
      UpdateMenu(nMenuKind, nMenuKindOld); /* Line 219, Address: 0x1000558 */
      point.x = infoSprtBmp[(nMenuKind - 1) * 2].point.x /* Line 220, Address: 0x100056c */
              + infoSprtBmp[(nMenuKind - 1) * 2].w;
      point.y = infoSprtBmp[(nMenuKind - 1) * 2].point.y - 8; /* Line 222, Address: 0x10005c8 */
      RunSonicCursol(point); /* Line 223, Address: 0x10005f8 */
      KeyWait(); /* Line 224, Address: 0x1000604 */

    } /* Line 226, Address: 0x100060c */
    else if (swData1 & 256) { /* Line 227, Address: 0x1000614 */

      nMenuKindOld = nMenuKind; /* Line 229, Address: 0x100062c */
      nMenuKind = nMenuKind - 1 >= 2 ? nMenuKind - 1 : 1; /* Line 230, Address: 0x1000638 */
      if (nMenuKind == nMenuKindOld) return; /* Line 231, Address: 0x100067c */

      WaveRequest(9); /* Line 233, Address: 0x1000694 */
      UpdateMenu(nMenuKind, nMenuKindOld); /* Line 234, Address: 0x10006a8 */
      point.x = infoSprtBmp[(nMenuKind - 1) * 2].point.x /* Line 235, Address: 0x10006bc */
              + infoSprtBmp[(nMenuKind - 1) * 2].w;
      point.y = infoSprtBmp[(nMenuKind - 1) * 2].point.y - 8; /* Line 237, Address: 0x1000718 */
      RunSonicCursol(point); /* Line 238, Address: 0x1000748 */
      KeyWait(); /* Line 239, Address: 0x1000754 */

    } /* Line 241, Address: 0x100075c */
    else if (swData1 & 16384) { /* Line 242, Address: 0x1000764 */


      if (ChkSaveFile() == 0) { /* Line 245, Address: 0x100077c */
        if (nMenuKind != 5) { /* Line 246, Address: 0x100078c */

          WaveRequest(30); /* Line 248, Address: 0x10007a4 */
          KeyWait(); /* Line 249, Address: 0x10007b8 */
          return; /* Line 250, Address: 0x10007c0 */
        }
      }
      bMenuChosed = 1; /* Line 253, Address: 0x10007c8 */
      bFileChosed = 0; /* Line 254, Address: 0x10007d4 */
      bDestFileChosed = 0; /* Line 255, Address: 0x10007dc */
      nFileNumber = nSelectFileNumber; /* Line 256, Address: 0x10007e4 */
      switch (nMenuKind) { /* Line 257, Address: 0x10007f4 */

        case 1:
          WaveRequest(26); /* Line 260, Address: 0x1000844 */
          UpdateMessage("SELECT FILE TO USE IN GAME."); /* Line 261, Address: 0x1000858 */
          UpdateFileSelect(nSelectFileNumber); /* Line 262, Address: 0x1000868 */
          point.x = infoSprtBmp[nFileNumber + 193].point.x - 16; /* Line 263, Address: 0x100087c */
          point.y = infoSprtBmp[nFileNumber + 193].point.y; /* Line 264, Address: 0x10008a4 */
          RunSonicCursol(point); /* Line 265, Address: 0x10008c8 */
          break; /* Line 266, Address: 0x10008d4 */
        case 2:
          WaveRequest(26); /* Line 268, Address: 0x10008dc */
          UpdateMessage("SELECT FILE TO COPY FROM."); /* Line 269, Address: 0x10008f0 */
          UpdateFileSelect(nSelectFileNumber); /* Line 270, Address: 0x1000900 */
          point.x = infoSprtBmp[nFileNumber + 193].point.x - 16; /* Line 271, Address: 0x1000914 */
          point.y = infoSprtBmp[nFileNumber + 193].point.y; /* Line 272, Address: 0x100093c */
          RunSonicCursol(point); /* Line 273, Address: 0x1000960 */
          break; /* Line 274, Address: 0x100096c */
        case 3:
          WaveRequest(26); /* Line 276, Address: 0x1000974 */
          UpdateMessage("SELECT FILE TO RENAME."); /* Line 277, Address: 0x1000988 */
          UpdateFileSelect(nSelectFileNumber); /* Line 278, Address: 0x1000998 */
          point.x = infoSprtBmp[nFileNumber + 193].point.x - 16; /* Line 279, Address: 0x10009ac */
          point.y = infoSprtBmp[nFileNumber + 193].point.y; /* Line 280, Address: 0x10009d4 */
          RunSonicCursol(point); /* Line 281, Address: 0x10009f8 */
          break; /* Line 282, Address: 0x1000a04 */
        case 4:
          WaveRequest(26); /* Line 284, Address: 0x1000a0c */
          UpdateMessage("SELECT FILE TO DELETE."); /* Line 285, Address: 0x1000a20 */
          UpdateFileSelect(nSelectFileNumber); /* Line 286, Address: 0x1000a30 */
          point.x = infoSprtBmp[nFileNumber + 193].point.x - 16; /* Line 287, Address: 0x1000a44 */
          point.y = infoSprtBmp[nFileNumber + 193].point.y; /* Line 288, Address: 0x1000a6c */
          RunSonicCursol(point); /* Line 289, Address: 0x1000a90 */
          break;
        case 5:
          break;
      }
      WaitKeyOff(); /* Line 294, Address: 0x1000a9c */
    }
  } /* Line 296, Address: 0x1000aa4 */
  else {

    switch (nMenuKind) { /* Line 299, Address: 0x1000aac */

      case 1:
        SDMenuSelect(); /* Line 302, Address: 0x1000afc */
        break; /* Line 303, Address: 0x1000b04 */
      case 2:
        SDMenuCopy(); /* Line 305, Address: 0x1000b0c */
        break; /* Line 306, Address: 0x1000b14 */
      case 3:
        SDMenuRename(); /* Line 308, Address: 0x1000b1c */
        break; /* Line 309, Address: 0x1000b24 */
      case 4:
        SDMenuDelete(); /* Line 311, Address: 0x1000b2c */
        break; /* Line 312, Address: 0x1000b34 */
      case 5:
        SDMenuExit(); /* Line 314, Address: 0x1000b3c */
        break;
    }
  }

} /* Line 319, Address: 0x1000b44 */




int SDEnd() { /* Line 324, Address: 0x1000b60 */
  int ret = 0; /* Line 325, Address: 0x1000b6c */

  if (nTimerCunt == 0) { /* Line 327, Address: 0x1000b70 */

    WriteDataFile(); /* Line 329, Address: 0x1000b80 */
    ret = 9; /* Line 330, Address: 0x1000b88 */
  }

  return ret; /* Line 333, Address: 0x1000b8c */
} /* Line 334, Address: 0x1000b90 */




int CheckAutoEnd() { /* Line 339, Address: 0x1000bb0 */
  static int inputKeyTime;
  int ret = 0; /* Line 341, Address: 0x1000bb8 */

  if (swData1 != 0 || swData2 != 0) /* Line 343, Address: 0x1000bbc */
    inputKeyTime = nTimerCunt; /* Line 344, Address: 0x1000bdc */
  if (nTimerCunt - keybordInputTime >= 36001 /* Line 345, Address: 0x1000bec */
      && nTimerCunt -inputKeyTime >= 36001) {


    ret = 4; /* Line 349, Address: 0x1000c34 */
  }
  return ret; /* Line 351, Address: 0x1000c38 */
} /* Line 352, Address: 0x1000c3c */
