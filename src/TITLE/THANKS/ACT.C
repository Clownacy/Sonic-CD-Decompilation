#include "..\..\TYPES.H"
#include "THANKS_TYPES.H"
#include "ACT.H"
#include "SPRMOVE.H"

void actloop(short id);
void priact(sprite_status_thanks* pActwk, short ActNo);
void dummy(sprite_status_thanks* pActwk);
void pattern_chg(sprite_status_thanks* pActwk, sprite_patterns_title* pPatTbl);

static void(*act_tbl[31])(sprite_status_thanks*) = {
  &sonic_ctrl,
  &emie_ctrl,
  &metals_ctrl,
  &flick_ctrl,
  &pocky_ctrl,
  &ricky_ctrl,
  &heart_ctrl,
  &inco_ctrl,
  &hato_ctrl,
  &sheep_ctrl,
  &pecky_ctrl,
  &dummy, &dummy,
  &dummy, &dummy,
  &dummy, &dummy,
  &dummy, &dummy,
  &dummy, &dummy,
  &dummy, &dummy,
  &dummy, &dummy,
  &dummy, &dummy,
  &dummy, &dummy,
  &dummy, &dummy
};
extern sprite_status_thanks actwk[66];
extern sprite_status_thanks** priptr[4];
extern sprite_status_thanks* pribuf0[64];
extern sprite_status_thanks* pribuf3[64];
extern sprite_status_thanks* pribuf2[64];
extern sprite_status_thanks* pribuf1[64];
extern void(*EAsprset)(short, short, unsigned short, unsigned short, unsigned short);
static unsigned short LinkData;
extern void(*sMemSet)(void*, unsigned char, int);







































short get_actwk(sprite_status_thanks** pNewActwk) { /* Line 82, Address: 0x1000000 */
  sprite_status_thanks* pActwk;
  short i;

  for (i = 0; i < 61; ++i) /* Line 86, Address: 0x1000010 */
  {
    pActwk = &actwk[i + 3]; /* Line 88, Address: 0x100001c */
    if (pActwk->ACT_NO == 0) /* Line 89, Address: 0x1000040 */
    {
      *pNewActwk = pActwk; /* Line 91, Address: 0x1000050 */
      return 0; /* Line 92, Address: 0x1000058 */
    }
  } /* Line 94, Address: 0x1000064 */
  return -1; /* Line 95, Address: 0x1000084 */
} /* Line 96, Address: 0x1000088 */





short chk_actwk() { /* Line 102, Address: 0x10000a0 */
  sprite_status_thanks* pActwk;
  short i;

  for (i = 0; i < 61; ++i) /* Line 106, Address: 0x10000ac */
  {
    pActwk = &actwk[i]; /* Line 108, Address: 0x10000b8 */
    if (pActwk->ACT_NO == 0) /* Line 109, Address: 0x10000d8 */
    {
      return 0; /* Line 111, Address: 0x10000e8 */
    }
  } /* Line 113, Address: 0x10000f4 */
  return -1; /* Line 114, Address: 0x1000114 */
} /* Line 115, Address: 0x1000118 */




void priset() { /* Line 120, Address: 0x1000130 */
  sprite_status_thanks*** a1;
  sprite_status_thanks*** a2;
  sprite_status_thanks** a3;
  sprite_status_thanks* pActwk;
  short i;

  a1 = priptr; /* Line 127, Address: 0x1000148 */
  priptr[0] = pribuf0; /* Line 128, Address: 0x1000150 */
  priptr[1] = pribuf1; /* Line 129, Address: 0x1000160 */
  priptr[2] = pribuf2; /* Line 130, Address: 0x1000170 */
  priptr[3] = pribuf3; /* Line 131, Address: 0x1000180 */

  pribuf0[0] = 0; /* Line 133, Address: 0x1000190 */
  pribuf0[1] = 0; /* Line 134, Address: 0x1000198 */
  pribuf0[2] = 0; /* Line 135, Address: 0x10001a0 */
  pribuf0[3] = 0; /* Line 136, Address: 0x10001a8 */

  for (i = 0; i < 64; ++i) /* Line 138, Address: 0x10001b0 */
  {
    pActwk = &actwk[i]; /* Line 140, Address: 0x10001bc */
    if (pActwk->ACT_NO) /* Line 141, Address: 0x10001dc */
    {
      a2 = &priptr[pActwk->free[0]]; /* Line 143, Address: 0x10001e8 */
      a3 = *a2; /* Line 144, Address: 0x1000200 */
      *a3++ = pActwk; /* Line 145, Address: 0x1000204 */
      *a3 = 0; /* Line 146, Address: 0x1000210 */
      *a2 = a3; /* Line 147, Address: 0x1000214 */
    }
  } /* Line 149, Address: 0x1000218 */
} /* Line 150, Address: 0x1000238 */




void action() { /* Line 155, Address: 0x1000260 */
  short i;

  actloop(0); /* Line 158, Address: 0x100026c */
  priset(); /* Line 159, Address: 0x1000278 */
  spr_set(); /* Line 160, Address: 0x1000280 */
  for (i = LinkData; i < 80; ++i) EAsprset(0, 0, 0, i, 0); /* Line 161, Address: 0x1000288 */
} /* Line 162, Address: 0x10002e4 */




static void actloop(short id) { /* Line 167, Address: 0x1000300 */
  sprite_status_thanks* pActwk;
  short i;

  for (i = 0; i < 64; ++i) /* Line 171, Address: 0x1000314 */
  {
    pActwk = &actwk[id++]; /* Line 173, Address: 0x1000320 */
    if (pActwk->ACT_NO) /* Line 174, Address: 0x100034c */
    {
      priact(pActwk, pActwk->ACT_NO); /* Line 176, Address: 0x1000358 */
    }
  } /* Line 178, Address: 0x1000370 */
} /* Line 179, Address: 0x1000390 */




static void priact(sprite_status_thanks* pActwk, short ActNo) { /* Line 184, Address: 0x10003b0 */
  act_tbl[ActNo - 1](pActwk); /* Line 185, Address: 0x10003c0 */
  if (pActwk->SPR_FLG & 16) /* Line 186, Address: 0x10003f0 */
  {
    sMemSet(pActwk, 0, sizeof(*pActwk)); /* Line 188, Address: 0x1000408 */
  }
} /* Line 190, Address: 0x1000424 */




static void dummy(sprite_status_thanks* pActwk) { /* Line 195, Address: 0x1000440 */
  pActwk->ACT_NO = 0; /* Line 196, Address: 0x1000448 */
} /* Line 197, Address: 0x1000450 */




void spr_set() { /* Line 202, Address: 0x1000460 */
  sprite_status_thanks* pActwk;
  sprite_status_thanks** pPribuf;
  sprite_patterns_title* pPatTbl;
  sprite_pattern_mapping_title* pMapDat;
  short pri, i, j;
  short xpos, ypos;
  unsigned short RevFlg;

  LinkData = 0; /* Line 211, Address: 0x100048c */
  priptr[0] = pribuf0; /* Line 212, Address: 0x1000494 */
  priptr[1] = pribuf1; /* Line 213, Address: 0x10004a4 */
  priptr[2] = pribuf2; /* Line 214, Address: 0x10004b4 */
  priptr[3] = pribuf3; /* Line 215, Address: 0x10004c4 */

  for (pri = 0; pri < 4; ++pri) /* Line 217, Address: 0x10004d4 */
  {
    pPribuf = priptr[pri]; /* Line 219, Address: 0x10004e0 */
    for (i = 0; i < 64; ++i) /* Line 220, Address: 0x10004fc */
    {
      if (*pPribuf == 0) break; /* Line 222, Address: 0x1000508 */
      pActwk = *pPribuf++; /* Line 223, Address: 0x1000514 */
      if (pActwk->ACT_NO == 0) break; /* Line 224, Address: 0x1000520 */

      pPatTbl = pActwk->PAT_ADR; /* Line 226, Address: 0x1000530 */
      pattern_chg(pActwk, pPatTbl); /* Line 227, Address: 0x1000534 */

      j = pPatTbl->aPatDat[pActwk->PAT_NO].paMapTbl->mapnum; /* Line 229, Address: 0x1000544 */
      pMapDat = pPatTbl->aPatDat[pActwk->PAT_NO].paMapTbl->aMapDat; /* Line 230, Address: 0x1000568 */

      for ( ; j > 0; --j, ++pMapDat) /* Line 232, Address: 0x1000584 */
      {
        RevFlg = 0; /* Line 234, Address: 0x100058c */
        xpos = pActwk->XPOSI.w.h; /* Line 235, Address: 0x1000590 */
        if (pActwk->SPR_FLG & 128) /* Line 236, Address: 0x100059c */
        {
          xpos -= pMapDat->hrevoffs; /* Line 238, Address: 0x10005b0 */
          RevFlg |= 1; /* Line 239, Address: 0x10005c0 */
        } /* Line 240, Address: 0x10005c8 */
        else
        {
          xpos -= pMapDat->hoffs; /* Line 243, Address: 0x10005d0 */
        }
        xpos += 128; /* Line 245, Address: 0x10005e0 */
        ypos = pActwk->YPOSI.w.h; /* Line 246, Address: 0x10005ec */
        if (pActwk->SPR_FLG & 64) /* Line 247, Address: 0x10005f8 */
        {
          ypos -= pMapDat->vrevoffs; /* Line 249, Address: 0x100060c */
          RevFlg |= 2; /* Line 250, Address: 0x100061c */
        } /* Line 251, Address: 0x1000624 */
        else
        {
          ypos -= pMapDat->voffs; /* Line 254, Address: 0x100062c */
        }
        ypos += 128; /* Line 256, Address: 0x100063c */
        RevFlg ^= pMapDat->etc; /* Line 257, Address: 0x1000648 */
        if (pActwk->SPR_FLG & 32) /* Line 258, Address: 0x1000658 */
        {
          RevFlg |= 32768; /* Line 260, Address: 0x100066c */
        }
        EAsprset(xpos, ypos, pMapDat->index, LinkData, RevFlg); /* Line 262, Address: 0x1000674 */
        if (++LinkData >= 80) break; /* Line 263, Address: 0x10006a0 */
      } /* Line 264, Address: 0x10006c8 */
    } /* Line 265, Address: 0x10006e8 */
  } /* Line 266, Address: 0x100070c */
} /* Line 267, Address: 0x100072c */




static void pattern_chg(sprite_status_thanks* pActwk, sprite_patterns_title* pPatTbl) { /* Line 272, Address: 0x1000760 */
  short d0;

  --pActwk->SPR_TIMER; /* Line 275, Address: 0x1000770 */
  if (pActwk->SPR_TIMER <= 0) /* Line 276, Address: 0x1000780 */
  {
    d0 = pActwk->PAT_NO; /* Line 278, Address: 0x1000798 */
    ++d0; /* Line 279, Address: 0x10007a8 */
    if ((unsigned short)d0 >= (unsigned short)pPatTbl->patnum) /* Line 280, Address: 0x10007b4 */
    {
      d0 = 0; /* Line 282, Address: 0x10007d8 */
    }
    pActwk->PAT_NO = d0; /* Line 284, Address: 0x10007dc */
    pActwk->SPR_TIMER = pPatTbl->aPatDat[d0].timer; /* Line 285, Address: 0x10007e4 */
  }
} /* Line 287, Address: 0x1000804 */




void clrwork(sprite_status_thanks* pActwk) { /* Line 292, Address: 0x1000820 */
  sMemSet(pActwk, 0, sizeof(*pActwk)); /* Line 293, Address: 0x100082c */
} /* Line 294, Address: 0x1000848 */




void action_all_clr() { /* Line 299, Address: 0x1000860 */
  short i;

  for (i = 0; i < 64; ++i) /* Line 302, Address: 0x100086c */
  {
    sMemSet(&actwk[i], 0, sizeof(actwk[i])); /* Line 304, Address: 0x1000878 */
  } /* Line 305, Address: 0x10008b0 */
} /* Line 306, Address: 0x10008d0 */
