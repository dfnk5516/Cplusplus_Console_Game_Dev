#include "stdafx.h"
#include "human1.h"


human1::human1()
{
	SetMonsterName("°¨¿°ÀÚ");
	SetMonsterMaxHp(rand() % 51 + 600);
	SetMonsterAtk(rand() % 31 + 350);
	SetMonsterMoney(rand() % 501 + 5800);
	SetMonsterExp(rand() % 51 + 5500);
	SetMonsterSeed(rand() % 85);
	SetMonsterHp(GetMonsterMaxHp());
}


human1::~human1()
{
}
