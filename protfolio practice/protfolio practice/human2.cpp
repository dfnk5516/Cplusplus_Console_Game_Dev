#include "stdafx.h"
#include "human2.h"


human2::human2()
{
	SetMonsterName("È¯¡¡ÀÚ");
	SetMonsterMaxHp(rand() % 51 + 570);
	SetMonsterAtk(rand() % 31 + 330);
	SetMonsterMoney(rand() % 501 + 5600);
	SetMonsterExp(rand() % 51 + 5300);
	SetMonsterSeed(rand() % 88);
	SetMonsterHp(GetMonsterMaxHp());
}


human2::~human2()
{
}
