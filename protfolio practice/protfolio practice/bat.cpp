#include "stdafx.h"
#include "bat.h"


bat::bat()
{
	SetMonsterName("¹Ú¡¡Áã");
	SetMonsterMaxHp(rand() % 51 + 300);
	SetMonsterAtk(rand() % 31 + 120);
	SetMonsterMoney(rand() % 501 + 3200);
	SetMonsterExp(rand() % 251 + 2950);
	SetMonsterSeed(rand() % 98);
	SetMonsterHp(GetMonsterMaxHp());
}


bat::~bat()
{
}