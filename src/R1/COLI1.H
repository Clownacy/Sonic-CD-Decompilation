short pcol(sprite_status* pActwk);
short CollitblDataXchk(sprite_status* pActwk, sprite_status* pColliAct, short iXposi, short iYposi, short iD5);
short CollitblDataYchk(sprite_status* pActwk, sprite_status* pColliAct, short iXposi, short iYposi, short iColiNo, short iD5);
short ColliHitChk(sprite_status* pActwk, sprite_status* pColliAct, short iXposi, short iChkPosi, short iD5);
short pcolitem(sprite_status* pActwk, sprite_status* pColliAct);
short pcolnomal(sprite_status* pActwk, sprite_status* pColliAct);
short pcolplay2(sprite_status* pActwk, sprite_status* pColliAct);
short pcolplay(sprite_status* pActwk, sprite_status* pColliAct);
short pcole(sprite_status* pActwk, sprite_status* pColliAct);
void playdamagechk(sprite_status* pActwk, sprite_status* pColliAct);
short playdamageset(sprite_status* pActwk, sprite_status* pColliAct);
short playdieset(sprite_status* pActwk);
short pcolspecial(sprite_status* pActwk, sprite_status* pColliAct, short iXposi, short iChkPosi, short iD5);
short eggman_chk(sprite_status* pActwk, sprite_status* pColliAct);
short yago(sprite_status* pActwk, sprite_status* pColliAct, short iXposi, short iChkPosi, short iD5);
short main_attack(sprite_status* pActwk, sprite_status* pColliAct);
