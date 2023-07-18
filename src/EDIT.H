typedef struct edit_array;
typedef struct edit_info;

struct edit_array {
  char num;
  char dummy;
  edit_info dat[0];
};

struct edit_info {
  unsigned char actno;
  unsigned char sprpri;
  spr_array** patbase;
  unsigned short offset;
  unsigned char userflag_h;
  unsigned char rludrv;
  unsigned char userflag_l;
  unsigned char patno;
};

void edit(act_info* pActwk);
