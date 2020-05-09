#include "stdafx.h"
#include "wildboar.h"


wildboar::wildboar()
{
	SetMonsterName("¸äµÅÁö");
	SetMonsterMaxHp(rand() % 51 + 380);
	SetMonsterAtk(rand() % 31 + 180);
	SetMonsterMoney(rand() % 501 + 3500);
	SetMonsterExp(rand() % 351 + 3700);
	SetMonsterSeed(rand() % 95);
	SetMonsterHp(GetMonsterMaxHp());
}


wildboar::~wildboar()
{
}