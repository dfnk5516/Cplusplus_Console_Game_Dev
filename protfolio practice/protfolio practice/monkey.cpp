#include "stdafx.h"
#include "monkey.h"


monkey::monkey()
{
	SetMonsterName("¿ø¼şÀÌ");
	SetMonsterMaxHp(rand() % 51 + 250);
	SetMonsterAtk(rand() % 31 + 80);
	SetMonsterMoney(rand() % 501 + 3000);
	SetMonsterExp(rand() % 251 + 2700);
	SetMonsterSeed(rand() % 101);
	SetMonsterHp(GetMonsterMaxHp());
}


monkey::~monkey()
{
}