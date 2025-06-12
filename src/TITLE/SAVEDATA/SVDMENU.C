#include "..\..\TYPES.H"
#include "..\COMMON\SCORE_DATA_TYPES.H"
#include "..\COMMON\HMX_TYPES.H"
#include "SVDMENU.H"
#include "..\..\IMPFUNCS.H"
#include "SVDDO.H"
#include "SVDEDIT.H"
#include "SVDENTRY.H"
#include "SVDSPRT.H"

extern sprite_bmp infoSprtBmp[];
extern unsigned short nMenuKind;
unsigned int bMenuChosed;
extern unsigned short swData1;
unsigned int bFileChosed;
int nSelectFileNumber;
extern int nFileNumber;
extern score_data saveData[6];
static int nSrcFileNumber;
unsigned int bDestFileChosed;
extern char editBuf[];
extern int nTimerCunt;





































unsigned int SDFileSelect(int* pFileNumber) { /* Line 60, Address: 0x10024f0 */
  int oldNumber;
  POINT point;

  if (swData1 & 512) { /* Line 64, Address: 0x1002508 */

    oldNumber = *pFileNumber; /* Line 66, Address: 0x1002520 */
    *pFileNumber = *pFileNumber + 1 < 5 ? *pFileNumber + 1 : 5; /* Line 67, Address: 0x1002528 */
    if (oldNumber != *pFileNumber) { /* Line 68, Address: 0x1002560 */

      WaveRequest(9); /* Line 70, Address: 0x1002570 */
      UpdateFileSelect(*pFileNumber); /* Line 71, Address: 0x1002584 */
      point.x = infoSprtBmp[*pFileNumber + 193].point.x - 16; /* Line 72, Address: 0x1002598 */
      point.y = infoSprtBmp[*pFileNumber + 193].point.y; /* Line 73, Address: 0x10025c0 */
      RunSonicCursol(point); /* Line 74, Address: 0x10025e4 */
      KeyWait(); /* Line 75, Address: 0x10025f0 */
    }
  } /* Line 77, Address: 0x10025f8 */
  else if (swData1 & 256) { /* Line 78, Address: 0x1002600 */

    oldNumber = *pFileNumber; /* Line 80, Address: 0x1002618 */
    *pFileNumber = *pFileNumber - 1 > 0 ? *pFileNumber - 1 : 0; /* Line 81, Address: 0x1002620 */
    if (oldNumber != *pFileNumber) { /* Line 82, Address: 0x1002654 */

      WaveRequest(9); /* Line 84, Address: 0x1002664 */
      UpdateFileSelect(*pFileNumber); /* Line 85, Address: 0x1002678 */
      point.x = infoSprtBmp[*pFileNumber + 193].point.x - 16; /* Line 86, Address: 0x100268c */
      point.y = infoSprtBmp[*pFileNumber + 193].point.y; /* Line 87, Address: 0x10026b4 */
      RunSonicCursol(point); /* Line 88, Address: 0x10026d8 */
      KeyWait(); /* Line 89, Address: 0x10026e4 */
    }
  } /* Line 91, Address: 0x10026ec */
  else if (swData1 & 16384) { /* Line 92, Address: 0x10026f4 */

    return 1; /* Line 94, Address: 0x100270c */
  }
  else if (swData1 & 4096) { /* Line 96, Address: 0x1002718 */

    WaveRequest(25); /* Line 98, Address: 0x1002730 */
    bMenuChosed = 0; /* Line 99, Address: 0x1002744 */
    DeleteFileSelect(); /* Line 100, Address: 0x100274c */
    DefaultMessage(); /* Line 101, Address: 0x1002754 */
    point.x = infoSprtBmp[(nMenuKind - 1) * 2].point.x /* Line 102, Address: 0x100275c */
            + infoSprtBmp[(nMenuKind - 1) * 2].w;
    point.y = infoSprtBmp[(nMenuKind - 1) * 2].point.y - 8; /* Line 104, Address: 0x10027b8 */
    RunSonicCursol(point); /* Line 105, Address: 0x10027e8 */
  }
  return 0; /* Line 107, Address: 0x10027f4 */
} /* Line 108, Address: 0x10027f8 */




void SDMenuSelect() { /* Line 113, Address: 0x1002820 */
  POINT point;
  static unsigned int yesNoDialogOn;

  if (bFileChosed == 0) { /* Line 117, Address: 0x1002828 */

    bFileChosed = SDFileSelect(&nFileNumber); /* Line 119, Address: 0x1002838 */
    yesNoDialogOn = 0; /* Line 120, Address: 0x1002850 */
    if (bFileChosed == 0) return; /* Line 121, Address: 0x1002858 */



    if (saveData[nFileNumber].saved != 0) { /* Line 125, Address: 0x1002868 */
      UpdateMessage("CONTINUE WITH THIS FILE?"); /* Line 126, Address: 0x100289c */
      yesNoDialogOn = 1; /* Line 127, Address: 0x10028ac */
      WaitKeyOff(); /* Line 128, Address: 0x10028b8 */
      WaveRequest(26); /* Line 129, Address: 0x10028c0 */
      return; /* Line 130, Address: 0x10028d4 */
    }
    bFileChosed = 0; /* Line 132, Address: 0x10028dc */
    WaitKeyOff(); /* Line 133, Address: 0x10028e4 */
    WaveRequest(30); /* Line 134, Address: 0x10028ec */










  } /* Line 145, Address: 0x1002900 */
  else if (yesNoDialogOn != 0) { /* Line 146, Address: 0x1002908 */

    if (swData1 & 16384) { /* Line 148, Address: 0x1002918 */

      WaveRequest(5); /* Line 150, Address: 0x1002930 */
      nSelectFileNumber = nFileNumber; /* Line 151, Address: 0x1002944 */
      bMenuChosed = bFileChosed = 0; /* Line 152, Address: 0x1002954 */
      DefaultMessage(); /* Line 153, Address: 0x1002964 */
      UpdateSelectSonicMark(nSelectFileNumber); /* Line 154, Address: 0x100296c */
      DeleteFileSelect(); /* Line 155, Address: 0x1002980 */
      point.x = infoSprtBmp[0].point.x /* Line 156, Address: 0x1002988 */
              + infoSprtBmp[0].w;
      point.y = infoSprtBmp[0].point.y - 8; /* Line 158, Address: 0x10029a4 */
      RunSonicCursol(point); /* Line 159, Address: 0x10029b4 */
      WaitKeyOff(); /* Line 160, Address: 0x10029c0 */
    } /* Line 161, Address: 0x10029c8 */
    else if (swData1 & 4096) { /* Line 162, Address: 0x10029d0 */

      WaveRequest(25); /* Line 164, Address: 0x10029e8 */
      bFileChosed = 0; /* Line 165, Address: 0x10029fc */
      UpdateMessage("SELECT FILE TO USE IN GAME."); /* Line 166, Address: 0x1002a04 */
      WaitKeyOff(); /* Line 167, Address: 0x1002a14 */
    }
  }
} /* Line 170, Address: 0x1002a1c */




void SDMenuCopy() { /* Line 175, Address: 0x1002a30 */
  POINT point;
  static unsigned int yesNoDialogOn;

  if (bFileChosed == 0) { /* Line 179, Address: 0x1002a38 */

    bFileChosed = SDFileSelect(&nFileNumber); /* Line 181, Address: 0x1002a48 */
    bDestFileChosed = 0; /* Line 182, Address: 0x1002a60 */
    yesNoDialogOn = 0; /* Line 183, Address: 0x1002a68 */
    if (bFileChosed == 0) return; /* Line 184, Address: 0x1002a70 */

    if (saveData[nFileNumber].saved != 0) { /* Line 186, Address: 0x1002a80 */

      WaveRequest(26); /* Line 188, Address: 0x1002ab4 */
      UpdateMessage("SELECT FILE TO COPY TO."); /* Line 189, Address: 0x1002ac8 */
      nSrcFileNumber = nFileNumber; /* Line 190, Address: 0x1002ad8 */
    } /* Line 191, Address: 0x1002ae8 */
    else {
      WaveRequest(30); /* Line 193, Address: 0x1002af0 */
      bFileChosed = 0; /* Line 194, Address: 0x1002b04 */
    }
    WaitKeyOff(); /* Line 196, Address: 0x1002b0c */

  } /* Line 198, Address: 0x1002b14 */
  else if (bDestFileChosed == 0) { /* Line 199, Address: 0x1002b1c */

    bDestFileChosed = SDFileSelect(&nFileNumber); /* Line 201, Address: 0x1002b2c */
    if (bDestFileChosed == 0) return; /* Line 202, Address: 0x1002b44 */

    if (nFileNumber == nSrcFileNumber) { /* Line 204, Address: 0x1002b54 */

      WaveRequest(30); /* Line 206, Address: 0x1002b6c */
      bDestFileChosed = 0; /* Line 207, Address: 0x1002b80 */
    } /* Line 208, Address: 0x1002b88 */
    else {

      WaveRequest(26); /* Line 211, Address: 0x1002b90 */
      if (saveData[nFileNumber].saved != 0) /* Line 212, Address: 0x1002ba4 */
        UpdateMessage("OK TO OVERWRITE FILE?"); /* Line 213, Address: 0x1002bd8 */
      else
        UpdateMessage("OK TO COPY?"); /* Line 215, Address: 0x1002bf0 */
      yesNoDialogOn = 1; /* Line 216, Address: 0x1002c00 */
      WaitKeyOff(); /* Line 217, Address: 0x1002c0c */
    }
  } /* Line 219, Address: 0x1002c14 */
  else if (yesNoDialogOn != 0) { /* Line 220, Address: 0x1002c1c */

    if (swData1 & 16384) { /* Line 222, Address: 0x1002c2c */

      WaveRequest(5); /* Line 224, Address: 0x1002c44 */
      sMemCpy(&saveData[nFileNumber], &saveData[nSrcFileNumber], sizeof(saveData[nSrcFileNumber])); /* Line 225, Address: 0x1002c58 */

      bMenuChosed = 0; /* Line 227, Address: 0x1002cbc */
      UpdateFileView(nFileNumber); /* Line 228, Address: 0x1002cc4 */
      UpdateMessage("COPY COMPLETED."); /* Line 229, Address: 0x1002cd8 */
      DeleteFileSelect(); /* Line 230, Address: 0x1002ce8 */
      point.x = infoSprtBmp[2].point.x /* Line 231, Address: 0x1002cf0 */
              + infoSprtBmp[2].w;
      point.y = infoSprtBmp[2].point.y - 8; /* Line 233, Address: 0x1002d0c */
      RunSonicCursol(point); /* Line 234, Address: 0x1002d1c */
      WaitAndDfltMsg(60); /* Line 235, Address: 0x1002d28 */
    } /* Line 236, Address: 0x1002d34 */
    else if (swData1 & 4096) { /* Line 237, Address: 0x1002d3c */

      WaveRequest(25); /* Line 239, Address: 0x1002d54 */
      bFileChosed = 0; /* Line 240, Address: 0x1002d68 */
      UpdateMessage("SELECT FILE TO COPY FROM."); /* Line 241, Address: 0x1002d70 */
      WaitKeyOff(); /* Line 242, Address: 0x1002d80 */
    }
  }
} /* Line 245, Address: 0x1002d88 */





void SDMenuRename() { /* Line 251, Address: 0x1002da0 */
  int ret;
  POINT point;
  static unsigned int editMode;
  static unsigned int cursolOn;

  if (bFileChosed == 0) { /* Line 257, Address: 0x1002dac */

    bFileChosed = SDFileSelect(&nFileNumber); /* Line 259, Address: 0x1002dbc */
    editMode = 0; /* Line 260, Address: 0x1002dd4 */
    if (bFileChosed == 0) return; /* Line 261, Address: 0x1002ddc */

    if (saveData[nFileNumber].saved != 0) { /* Line 263, Address: 0x1002dec */

      WaveRequest(26); /* Line 265, Address: 0x1002e20 */
      editMode = 1; /* Line 266, Address: 0x1002e34 */

      sMemCpy(editBuf, saveData[nFileNumber].player, sizeof(((score_data*)0)->player)); /* Line 268, Address: 0x1002e40 */
      DispCursol(); /* Line 269, Address: 0x1002e88 */
      MovCursol(0); /* Line 270, Address: 0x1002e90 */
    } /* Line 271, Address: 0x1002e9c */
    else {
      WaveRequest(30); /* Line 273, Address: 0x1002ea4 */
      bFileChosed = 0; /* Line 274, Address: 0x1002eb8 */
    }
    WaitKeyOff(); /* Line 276, Address: 0x1002ec0 */

  } /* Line 278, Address: 0x1002ec8 */
  else if (editMode != 0) { /* Line 279, Address: 0x1002ed0 */

    if (nTimerCunt % 10 == 0) { /* Line 281, Address: 0x1002ee0 */

      cursolOn = cursolOn == 0; /* Line 283, Address: 0x1002efc */
      if (cursolOn != 0) DispCursol(); /* Line 284, Address: 0x1002f14 */
      else HideCursol(); /* Line 285, Address: 0x1002f34 */
    }
    ret = Edit(); /* Line 287, Address: 0x1002f3c */

    if (ret == 1 || ret == -1) { /* Line 289, Address: 0x1002f48 */

      WaveRequest(5); /* Line 291, Address: 0x1002f60 */
      sMemCpy(saveData[nFileNumber].player, editBuf, sizeof(((score_data*)0)->player)); /* Line 292, Address: 0x1002f74 */
      bMenuChosed = bFileChosed = editMode = 0; /* Line 293, Address: 0x1002fbc */
      DefaultMessage(); /* Line 294, Address: 0x1002fd4 */
      DeleteFileSelect(); /* Line 295, Address: 0x1002fdc */
      HideCursol(); /* Line 296, Address: 0x1002fe4 */
      point.x = infoSprtBmp[4].point.x /* Line 297, Address: 0x1002fec */
              + infoSprtBmp[4].w;
      point.y = infoSprtBmp[4].point.y - 8; /* Line 299, Address: 0x1003008 */
      RunSonicCursol(point); /* Line 300, Address: 0x1003018 */
    }
  }




















} /* Line 323, Address: 0x1003024 */




void SDMenuDelete() { /* Line 328, Address: 0x1003040 */
  POINT point;
  int i;
  static unsigned int yesNoDialogOn;

  if (bFileChosed == 0) { /* Line 333, Address: 0x100304c */

    bFileChosed = SDFileSelect(&nFileNumber); /* Line 335, Address: 0x100305c */
    yesNoDialogOn = 0; /* Line 336, Address: 0x1003074 */
    if (bFileChosed == 0) return; /* Line 337, Address: 0x100307c */

    if (saveData[nFileNumber].saved != 0) { /* Line 339, Address: 0x100308c */

      WaveRequest(26); /* Line 341, Address: 0x10030c0 */
      UpdateMessage("OK TO DELETE?"); /* Line 342, Address: 0x10030d4 */
      yesNoDialogOn = 1; /* Line 343, Address: 0x10030e4 */
    } /* Line 344, Address: 0x10030f0 */
    else {
      WaveRequest(30); /* Line 346, Address: 0x10030f8 */
      bFileChosed = 0; /* Line 347, Address: 0x100310c */
    }
    WaitKeyOff(); /* Line 349, Address: 0x1003114 */

  } /* Line 351, Address: 0x100311c */
  else if (yesNoDialogOn != 0) { /* Line 352, Address: 0x1003124 */

    if (swData1 & 16384) { /* Line 354, Address: 0x1003134 */

      WaveRequest(5); /* Line 356, Address: 0x100314c */
      sMemSet(&saveData[nFileNumber], 0, sizeof(saveData[nFileNumber])); /* Line 357, Address: 0x1003160 */
      bMenuChosed = 0; /* Line 358, Address: 0x10031a0 */

      if (nSelectFileNumber == nFileNumber) { /* Line 360, Address: 0x10031a8 */

        for (i = 0; i < 6; ++i) { /* Line 362, Address: 0x10031c0 */
          if (saveData[i].saved != 0) break; /* Line 363, Address: 0x10031cc */

        } /* Line 365, Address: 0x10031f8 */
        if (i == 6) { /* Line 366, Address: 0x1003208 */

          nSelectFileNumber = 0; /* Line 368, Address: 0x1003214 */
        } /* Line 369, Address: 0x100321c */
        else {
          nSelectFileNumber = i; /* Line 371, Address: 0x1003224 */
        }
        UpdateSelectSonicMark(nSelectFileNumber); /* Line 373, Address: 0x100322c */
      }


      UpdateFileView(nFileNumber); /* Line 377, Address: 0x1003240 */

      UpdateMessage("FILE DELETED."); /* Line 379, Address: 0x1003254 */
      DeleteFileSelect(); /* Line 380, Address: 0x1003264 */
      point.x = infoSprtBmp[6].point.x /* Line 381, Address: 0x100326c */
              + infoSprtBmp[6].w;
      point.y = infoSprtBmp[6].point.y - 8; /* Line 383, Address: 0x1003288 */
      RunSonicCursol(point); /* Line 384, Address: 0x1003298 */
      WaitAndDfltMsg(60); /* Line 385, Address: 0x10032a4 */
    } /* Line 386, Address: 0x10032b0 */
    else if (swData1 & 4096) { /* Line 387, Address: 0x10032b8 */

      WaveRequest(25); /* Line 389, Address: 0x10032d0 */
      bFileChosed = 0; /* Line 390, Address: 0x10032e4 */
      UpdateMessage("SELECT FILE TO DELETE."); /* Line 391, Address: 0x10032ec */
      WaitKeyOff(); /* Line 392, Address: 0x10032fc */
    }
  }
} /* Line 395, Address: 0x1003304 */




void SDMenuExit() { /* Line 400, Address: 0x1003320 */
  OESetSequenceNum(999); /* Line 401, Address: 0x1003328 */
} /* Line 402, Address: 0x1003334 */
