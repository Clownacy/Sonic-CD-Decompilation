#include "..\EQU.H"
#include "PLAYSP7.H"
#include "..\ACTSET.H"
#include "..\FCOL.H"

short playsp_tbla[7] = { 10, 190, 334, 335, 344, 345, -1 };
short playsp_tblb[11] = { 10, 190, 334, 335, 344, 345, 154, 155, 164, 165, -1 };
short playsp_tblc[6] = { 618, 517, 527, 571, 581, -1 };
short playsp_tbld[7] = { 10, 210, 354, 355, 364, 365, -1 };
short* playsp_tbl[4] =
{
  playsp_tblb,
  playsp_tbla,
  playsp_tbld,
  playsp_tblc
};























void playsp() { /* Line 40, Address: 0x101e000 */
  int i;
  short wD0, wD1, wD2, wD3;
  short* pPlaysptbl;
  sprite_status* pNewactwk;

  if (gametimer.b.l & 3) return; /* Line 46, Address: 0x101e020 */

  wD0 = actwk[0].xspeed.w; /* Line 48, Address: 0x101e03c */
  if (wD0 < 0) wD0 *= -1; /* Line 49, Address: 0x101e04c */

  if (wD0 < 2560) return; /* Line 51, Address: 0x101e068 */

  wD2 = actwk[0].yposi.w.h + 8; /* Line 53, Address: 0x101e07c */
  wD3 = actwk[0].xposi.w.h; /* Line 54, Address: 0x101e0a0 */
  wD0 = scramapad(&actwk[0], wD3, wD2) & 2047; /* Line 55, Address: 0x101e0b0 */
  wD1 = time_flag & 127; /* Line 56, Address: 0x101e0e4 */
  if (wD1 == 2) /* Line 57, Address: 0x101e104 */
    wD1 += generate_flag; /* Line 58, Address: 0x101e118 */

  pPlaysptbl = playsp_tbl[wD1]; /* Line 60, Address: 0x101e130 */

  i = 0; /* Line 62, Address: 0x101e14c */
  do
  {
    wD1 = pPlaysptbl[i++]; /* Line 65, Address: 0x101e150 */
    if (wD1 < 0) return; /* Line 66, Address: 0x101e16c */
  } while (wD0 != wD1); /* Line 67, Address: 0x101e17c */

  if (actwkchk(&pNewactwk) == 0) /* Line 69, Address: 0x101e194 */
  {
    pNewactwk->actno = 9; /* Line 71, Address: 0x101e1a8 */
    pNewactwk->xposi.w.h = actwk[0].xposi.w.h; /* Line 72, Address: 0x101e1b4 */
    pNewactwk->yposi.w.h = actwk[0].yposi.w.h; /* Line 73, Address: 0x101e1c4 */
    pNewactwk->yposi.w.h += (char)actwk[0].sprvsize; /* Line 74, Address: 0x101e1d4 */
    if (actwk[0].xspeed.w < 0) /* Line 75, Address: 0x101e1fc */
      pNewactwk->cddat |= 1; /* Line 76, Address: 0x101e214 */
  }
} /* Line 78, Address: 0x101e224 */
