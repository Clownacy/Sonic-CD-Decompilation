#include "HMX_TYPES.H"

void EAError(void);
void srfDraw(void);
void ld_bitmap_file(char* fname, void* dst, int wx, int wy, int palet, int unknown);
void ld_bitmap_file2(char* fname, void* dst, int sx, int sy, int wx, int wy, int dx, int dy, int unk1, int unk2);
void ld_bitmap_4to8_1(void* dst, void* src, int wx, int wy, int palet, int zero_chg, int flag4);
void ld_bitmap_4to8_2(void* dst, void* src, int wx, int wy, int palet, int zero_chg, int flag4);
int ld_load_sprite2(hmx_environment* buffer, char* file, hmx_environment* env, hmx_bitmap** bitmaps, int size);
int ld_load_sprite1(hmx_environment* buffer, char* file, hmx_environment* env, hmx_bitmap** bitmaps, int size);
int ld_load_grid2(hmx_environment* buffer, char* file, hmx_environment* env, hmx_bitmap** bitmaps, int size);
int OEGridBmpCreate(void);
void OEGridBmpDelete(void);
int OESprBmpCreate(void);
void OESprBmpDelete(void);
int OESprCreate(unsigned short timing);
int OESprCreateIndx(int indx);
void OESprDelete(unsigned short timing);
void OESprDeleteIndx(int indx);
void OEAllSprDelete(void);
int OEGridDeleteAll(void);
int OECreateEA(void);
void OEDeleteEA(void);
void sprCreate(int* handle);
void sprDelete(int handle);
