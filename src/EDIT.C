#include "EQU.H"
#include "EDIT.H"
#include "ACTION.H"
#include "ACTSET.H"
#include "FCOL.H"

static int CKeyTogle;
extern spr_array* sncpat[];
extern edit_info_array edit_tbl;

















void edit(sprite_status* pActwk) { /* Line 27, Address: 0x100edd0 */
  edit_info_array* pEdit_tbl;
  sprite_status* pActwk2;
  int CKey;
  int edit_spd = 524288; /* Line 31, Address: 0x100ee00 */
  int speed;
  short xposi;
  short yposi;
  short sprvs;
  short index;
  char en;




  if (editmode.b.h == 0) return; /* Line 42, Address: 0x100ee04 */

  if (swdata1.b.h & 15) /* Line 44, Address: 0x100ee1c */
  {
    edit_spd += 8192; /* Line 46, Address: 0x100ee34 */
    if (524289 <= edit_spd) edit_spd = 524288; /* Line 47, Address: 0x100ee38 */
  } /* Line 48, Address: 0x100ee50 */
  else
  {
    edit_spd = 16384; /* Line 51, Address: 0x100ee58 */
  }
  speed = edit_spd; /* Line 53, Address: 0x100ee5c */
  if (swdata1.b.h & 1) pActwk->yposi.l -= speed; /* Line 54, Address: 0x100ee60 */
  if (swdata1.b.h & 2) pActwk->yposi.l += speed; /* Line 55, Address: 0x100ee88 */
  if (swdata1.b.h & 4) pActwk->xposi.l -= speed; /* Line 56, Address: 0x100eeb0 */
  if (swdata1.b.h & 8) pActwk->xposi.l += speed; /* Line 57, Address: 0x100eed8 */
  yposi = pActwk->yposi.w.h; /* Line 58, Address: 0x100ef00 */
  sprvs = pActwk->sprvsize; /* Line 59, Address: 0x100ef10 */
  yposi += sprvs; /* Line 60, Address: 0x100ef24 */
  xposi = pActwk->xposi.w.h; /* Line 61, Address: 0x100ef30 */
  blkno = scramapad(pActwk, xposi, yposi); /* Line 62, Address: 0x100ef40 */

  pEdit_tbl = &edit_tbl; /* Line 64, Address: 0x100ef5c */

  if (swdata1.b.l & 16) /* Line 66, Address: 0x100ef64 */
  {
    editmode.b.h = 0; /* Line 68, Address: 0x100ef7c */
    pActwk->patbase = sncpat; /* Line 69, Address: 0x100ef84 */
    pActwk->sproffset = 1920; /* Line 70, Address: 0x100ef94 */
    pActwk->sprpri = 2; /* Line 71, Address: 0x100efa0 */
    pActwk->patno = 0; /* Line 72, Address: 0x100efac */
    pActwk->actflg = 4; /* Line 73, Address: 0x100efb4 */
    actionsub(pActwk); /* Line 74, Address: 0x100efc0 */
    return; /* Line 75, Address: 0x100efcc */
  }

  if (swdata1.b.l & 64) /* Line 78, Address: 0x100efd4 */
  {
    en = editno.b.h + 1; /* Line 80, Address: 0x100efec */
    if (en < pEdit_tbl->num) en = 0; /* Line 81, Address: 0x100f010 */
    editno.b.h = en; /* Line 82, Address: 0x100f034 */
  }








  index = editno.b.h; /* Line 92, Address: 0x100f03c */

  pActwk->patbase = pEdit_tbl->dat[index].patbase; /* Line 94, Address: 0x100f054 */
  pActwk->sproffset = pEdit_tbl->dat[index].offset; /* Line 95, Address: 0x100f070 */
  pActwk->sprpri = pEdit_tbl->dat[index].sprpri; /* Line 96, Address: 0x100f08c */
  pActwk->patno = pEdit_tbl->dat[index].patno; /* Line 97, Address: 0x100f0a8 */
  edit_user = pEdit_tbl->dat[index].userflag_l; /* Line 98, Address: 0x100f0c4 */
  pActwk->actflg = pEdit_tbl->dat[index].rludrv | 4; /* Line 99, Address: 0x100f0e0 */
  pActwk->mstno.b.h = 0; /* Line 100, Address: 0x100f108 */

  CKey = 0; /* Line 102, Address: 0x100f110 */
  if (CKey & 128) /* Line 103, Address: 0x100f114 */
  {  /* Unreachable code. */
    CKey &= 1; /* Line 105, Address: 0x100f120 */
    if (CKeyTogle != CKey) { /* Line 106, Address: 0x100f124 */
      if (actwkchk(&pActwk2) == 0) /* Line 107, Address: 0x100f134 */
      {
        index = editno.b.h; /* Line 109, Address: 0x100f148 */
        pActwk2->actno = pEdit_tbl->dat[index].actno; /* Line 110, Address: 0x100f160 */
        pActwk2->userflag.b.h = pEdit_tbl->dat[index].userflag_h; /* Line 111, Address: 0x100f17c */
        pActwk2->userflag.b.l = pEdit_tbl->dat[index].userflag_l; /* Line 112, Address: 0x100f198 */
        pActwk2->patno = pEdit_tbl->dat[index].patno; /* Line 113, Address: 0x100f1b4 */
        pActwk2->xposi.w.h = pActwk->xposi.w.h; /* Line 114, Address: 0x100f1d0 */
        pActwk2->yposi.w.h = pActwk->yposi.w.h; /* Line 115, Address: 0x100f1e0 */
        pActwk2->actflg = pActwk->actflg & 3; /* Line 116, Address: 0x100f1f0 */
        pActwk2->cddat = pActwk->actflg & 3; /* Line 117, Address: 0x100f20c */
      }
    }
  }
  CKeyTogle = CKey & 1; /* Line 121, Address: 0x100f228 */
  actionsub(pActwk); /* Line 122, Address: 0x100f234 */
} /* Line 123, Address: 0x100f240 */
