#include "stdafx.h"
#include "snake.h"


snake::snake()
{
	SetMonsterName("µ¶¡¡»ç");
	SetMonsterMaxHp(rand() % 51 + 320);
	SetMonsterAtk(rand() % 31 + 150);
	SetMonsterMoney(rand() % 501 + 3500);
	SetMonsterExp(rand() % 351 + 3300);
	SetMonsterSeed(rand() % 95);
	SetMonsterHp(GetMonsterMaxHp());
}


snake::~snake()
{
}