#ifndef ENGINE_DLL_H
#define ENGINE_DLL_H

#include "SCORE_DATA_TYPES.H"

typedef struct {
  unsigned int hWnd;
  unsigned int hSurf;
  palette_entry* lpColorwk;
  unsigned int* lpbFullScreen;
  unsigned int bFirstTitle;
  unsigned int* lpbVisualmode;
  score_data* lpCrntScorData;
  unsigned int selectIndx;
  unsigned short* lpSelectedStage;
  void* ReadScoreData;
  void* WriteScoreData;
  void* OpenScoreData;
  void* CloseScoreData;
  void* CreateScoreData;
  void* ReadScoreIndx;
  void* WriteScoreIndx;
  void* CDPlay;
  void* CDPause;
  void* WaveRequest;
  void* EASetBitmapBits;
  void* EASetBitmapTransparency;
  void* EACreateBitmap;
  void* EADeleteBitmap;
  void* EACreateSequencedSprite;
  void* EASetDestination;
  void* EASetDrawOrder;
  void* EASetPosition;
  void* EADeleteSprite;
  void* EASetSequencedSpriteData;
  void* EACreateFixedGrid;
  void* EACreateTile;
  void* EASetTileData;
  void* EASetFixedGridData;
  void* EASetView;
  void* EASetEffect;
  void* EADeleteFixedGrid;
  void* EADraw;
  void* EAClearEffect;
  void* EADeleteTile;
  void* EASetDestRect;
  unsigned short* lpUserKey;
}
engine_dll;

#endif
