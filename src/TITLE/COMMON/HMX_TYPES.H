typedef struct hmx_environment hmx_environment;
typedef struct hmx_sprite hmx_sprite;
typedef struct hmx_grid hmx_grid;
typedef struct hmx_bitmap hmx_bitmap;
typedef struct hmx_ddagrid hmx_ddagrid;
typedef struct hmx_renderer_base hmx_renderer_base;
typedef struct hmx_renderer_context hmx_renderer_context;
typedef struct hmx_surface hmx_surface;
typedef struct hmx_background hmx_background;

typedef struct draw_context {
  hmx_surface* screen;
  hmx_renderer_context* context;
  hmx_background* background;
  hmx_sprite** sprites;
  int spr_bitmap_count;
  hmx_bitmap* spr_bitmaps[1000];
  int spr_level[1000];
  hmx_grid* grids[3];
  int grd_bitmap_count;
  hmx_bitmap* grd_bitmaps[2048];
  int grd_change_count;
  hmx_bitmap* grd_changes[2048];
  hmx_grid* sp_grids[8];
  hmx_ddagrid* rot_grid;
  int rot_bitmap_count;
  hmx_bitmap* rot_bitmaps[512];
}
draw_context;

typedef struct {
  unsigned short totalNum;
  unsigned short w;
  unsigned short h;
  POINT point;
  int order;
  unsigned char palOff;
  unsigned int** lphBmp;
  unsigned int* lphTile;
  unsigned int* lphGrid;
}
grid_bmp;

typedef struct {
  unsigned short w;
  unsigned short h;
  POINT point;
  int order;
  unsigned char palOff;
  unsigned int* hBmp;
  unsigned short timing;
  unsigned int* lphSpr;
}
sprite_bmp;

typedef struct _POINTL {
  int x;
  int y;
}
POINTL;

typedef struct _RECT {
  int left;
  int top;
  int right;
  int bottom;
}
RECT;

typedef struct _RECTL {
  int left;
  int top;
  int right;
  int bottom;
}
RECTL;

typedef struct {
  int x;
  int y;
  int dx;
  int dy;
}
grid_rect;

typedef struct {
  unsigned short mTile;
  unsigned short nTile;
}
tile_location;
