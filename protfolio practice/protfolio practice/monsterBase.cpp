#include "stdafx.h"
#include "monsterBase.h"


monsterBase::monsterBase()
{
}


monsterBase::~monsterBase()
{
}


string monsterBase::GetMonsterName()
{
	return _monsterName;
}
int monsterBase::GetMonsterMaxHp()
{
	return _monsterMaxHp;
}
int monsterBase::GetMonsterHp()
{
	return _monsterHp;
}
int monsterBase::GetMonsterAtk()
{
	return _monsterAtk;
}
int monsterBase::GetMonsterExp()
{
	return _monsterExp;
}
int monsterBase::GetMonsterMoney()
{
	return _monsterMoney;
}
int monsterBase::GetMonsterSeed()
{
	return _monsterSeed;
}
void monsterBase::SetMonsterName(string name)
{
	_monsterName = name;
}
void monsterBase::SetMonsterMaxHp(int maxhp)
{
	_monsterMaxHp = maxhp;
}
void monsterBase::SetMonsterHp(int hp)
{
	_monsterHp = hp;
}
void monsterBase::SetMonsterAtk(int atk)
{
	_monsterAtk = atk;
}
void monsterBase::SetMonsterExp(int exp)
{
	_monsterExp = exp;
}
void monsterBase::SetMonsterMoney(int money)
{
	_monsterMoney = money;
}
void monsterBase::SetMonsterSeed(int seed)
{
	_monsterSeed = seed;
}


void monsterBase::MonsterSkill()
{
	if (_monsterName == "¿ø¼þÀÌ")
	{
		cout << "¡á¡á¡à¡à¡à¡á¡á¡á¡à¡à¡à¡á¡á¡á¡à¡à¡à¡á¡á¡á¡à¡à¡à¡á¡á¡á¡à¡à¡à¡á¡á¡á¡à¡à¡à¡á¡á" << endl;	// 1
		cout << "¡á¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡á" << endl;	// 2
		cout << "¡à"; SetColor(0, 15); cout << "¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡á¡á¡á¡á¡á¡á¡á¡¡"; SetColor(9, 15); cout << "¡à" << endl;	// 3
		cout << "¡à"; SetColor(0, 15); cout << "¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡á¡¡¡¡¡¡¡¡¡¡¡á¡¡"; SetColor(9, 15); cout << "¡à" << endl;	// 4
		cout << "¡à"; SetColor(0, 15); cout << "¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡á¡¡ÇÒÄû±â¡¡¡á¡¡"; SetColor(9, 15); cout << "¡à" << endl;	// 5
		cout << "¡á"; SetColor(0, 15); cout << "¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡á¡¡¡¡¡¡¡¡¡¡¡á¡¡"; SetColor(9, 15); cout << "¡á" << endl;	// 6
		cout << "¡á"; SetColor(0, 15); cout << "¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡á¡á¡á¡á¡á¡á¡á¡¡"; SetColor(9, 15); cout << "¡á" << endl;	// 7
		cout << "¡á¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡á" << endl;	// 8//±â¼ú
	}
	else if (_monsterName == "¹Ú¡¡Áã")
	{
		cout << "¡á¡á¡à¡à¡à¡á¡á¡á¡à¡à¡à¡á¡á¡á¡à¡à¡à¡á¡á¡á¡à¡à¡à¡á¡á¡á¡à¡à¡à¡á¡á¡á¡à¡à¡à¡á¡á" << endl;	// 1
		cout << "¡á¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡á" << endl;	// 2
		cout << "¡à"; SetColor(0, 15); cout << "¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡á¡á¡á¡á¡á¡á¡á¡¡"; SetColor(9, 15); cout << "¡à" << endl;	// 3
		cout << "¡à"; SetColor(0, 15); cout << "¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡á¡¡¡¡¡¡¡¡¡¡¡á¡¡"; SetColor(9, 15); cout << "¡à" << endl;	// 4
		cout << "¡à"; SetColor(0, 15); cout << "¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡á¡¡Èí¡¡Ç÷¡¡¡á¡¡"; SetColor(9, 15); cout << "¡à" << endl;	// 5
		cout << "¡á"; SetColor(0, 15); cout << "¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡á¡¡¡¡¡¡¡¡¡¡¡á¡¡"; SetColor(9, 15); cout << "¡á" << endl;	// 6
		cout << "¡á"; SetColor(0, 15); cout << "¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡á¡á¡á¡á¡á¡á¡á¡¡"; SetColor(9, 15); cout << "¡á" << endl;	// 7
		cout << "¡á¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡á" << endl;	// 8//±â¼ú
	}
	else if (_monsterName == "µ¶¡¡»ç")
	{
		cout << "¡á¡á¡à¡à¡à¡á¡á¡á¡à¡à¡à¡á¡á¡á¡à¡à¡à¡á¡á¡á¡à¡à¡à¡á¡á¡á¡à¡à¡à¡á¡á¡á¡à¡à¡à¡á¡á" << endl;	// 1
		cout << "¡á¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡á" << endl;	// 2
		cout << "¡à"; SetColor(0, 15); cout << "¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡á¡á¡á¡á¡á¡á¡á¡¡"; SetColor(9, 15); cout << "¡à" << endl;	// 3
		cout << "¡à"; SetColor(0, 15); cout << "¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡á¡¡¡¡¡¡¡¡¡¡¡á¡¡"; SetColor(9, 15); cout << "¡à" << endl;	// 4
		cout << "¡à"; SetColor(0, 15); cout << "¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡á¡¡¹°¡¡±â¡¡¡á¡¡"; SetColor(9, 15); cout << "¡à" << endl;	// 5
		cout << "¡á"; SetColor(0, 15); cout << "¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡á¡¡¡¡¡¡¡¡¡¡¡á¡¡"; SetColor(9, 15); cout << "¡á" << endl;	// 6
		cout << "¡á"; SetColor(0, 15); cout << "¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡á¡á¡á¡á¡á¡á¡á¡¡"; SetColor(9, 15); cout << "¡á" << endl;	// 7
		cout << "¡á¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡á" << endl;	// 8//±â¼ú
	}
	else if (_monsterName == "¸äµÅÁö")
	{
		cout << "¡á¡á¡à¡à¡à¡á¡á¡á¡à¡à¡à¡á¡á¡á¡à¡à¡à¡á¡á¡á¡à¡à¡à¡á¡á¡á¡à¡à¡à¡á¡á¡á¡à¡à¡à¡á¡á" << endl;	// 1
		cout << "¡á¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡á" << endl;	// 2
		cout << "¡à"; SetColor(0, 15); cout << "¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡á¡á¡á¡á¡á¡á¡á¡¡"; SetColor(9, 15); cout << "¡à" << endl;	// 3
		cout << "¡à"; SetColor(0, 15); cout << "¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡á¡¡¡¡¡¡¡¡¡¡¡á¡¡"; SetColor(9, 15); cout << "¡à" << endl;	// 4
		cout << "¡à"; SetColor(0, 15); cout << "¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡á¡¡µ¹¡¡Áø¡¡¡á¡¡"; SetColor(9, 15); cout << "¡à" << endl;	// 5
		cout << "¡á"; SetColor(0, 15); cout << "¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡á¡¡¡¡¡¡¡¡¡¡¡á¡¡"; SetColor(9, 15); cout << "¡á" << endl;	// 6
		cout << "¡á"; SetColor(0, 15); cout << "¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡á¡á¡á¡á¡á¡á¡á¡¡"; SetColor(9, 15); cout << "¡á" << endl;	// 7
		cout << "¡á¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡á" << endl;	// 8//±â¼ú
	}
	else if (_monsterName == "°¨¿°ÀÚ")
	{
		cout << "¡á¡á¡à¡à¡à¡á¡á¡á¡à¡à¡à¡á¡á¡á¡à¡à¡à¡á¡á¡á¡à¡à¡à¡á¡á¡á¡à¡à¡à¡á¡á¡á¡à¡à¡à¡á¡á" << endl;	// 1
		cout << "¡á¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡á" << endl;	// 2
		cout << "¡à"; SetColor(0, 15); cout << "¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡á¡á¡á¡á¡á¡á¡á¡¡"; SetColor(9, 15); cout << "¡à" << endl;	// 3
		cout << "¡à"; SetColor(0, 15); cout << "¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡á¡¡¡¡¡¡¡¡¡¡¡á¡¡"; SetColor(9, 15); cout << "¡à" << endl;	// 4
		cout << "¡à"; SetColor(0, 15); cout << "¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡á¡¡±â¡¡°ø¡¡¡á¡¡"; SetColor(9, 15); cout << "¡à" << endl;	// 5
		cout << "¡á"; SetColor(0, 15); cout << "¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡á¡¡¡¡¡¡¡¡¡¡¡á¡¡"; SetColor(9, 15); cout << "¡á" << endl;	// 6
		cout << "¡á"; SetColor(0, 15); cout << "¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡á¡á¡á¡á¡á¡á¡á¡¡"; SetColor(9, 15); cout << "¡á" << endl;	// 7
		cout << "¡á¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡á" << endl;	// 8//±â¼ú
	}
	else if (_monsterName == "È¯¡¡ÀÚ")
	{
		cout << "¡á¡á¡à¡à¡à¡á¡á¡á¡à¡à¡à¡á¡á¡á¡à¡à¡à¡á¡á¡á¡à¡à¡à¡á¡á¡á¡à¡à¡à¡á¡á¡á¡à¡à¡à¡á¡á" << endl;	// 1
		cout << "¡á¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡á" << endl;	// 2
		cout << "¡à"; SetColor(0, 15); cout << "¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡á¡á¡á¡á¡á¡á¡á¡¡"; SetColor(9, 15); cout << "¡à" << endl;	// 3
		cout << "¡à"; SetColor(0, 15); cout << "¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡á¡¡¡¡¡¡¡¡¡¡¡á¡¡"; SetColor(9, 15); cout << "¡à" << endl;	// 4
		cout << "¡à"; SetColor(0, 15); cout << "¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡á¡¡ÆÄ¡¡°ø¡¡¡á¡¡"; SetColor(9, 15); cout << "¡à" << endl;	// 5
		cout << "¡á"; SetColor(0, 15); cout << "¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡á¡¡¡¡¡¡¡¡¡¡¡á¡¡"; SetColor(9, 15); cout << "¡á" << endl;	// 6
		cout << "¡á"; SetColor(0, 15); cout << "¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡á¡á¡á¡á¡á¡á¡á¡¡"; SetColor(9, 15); cout << "¡á" << endl;	// 7
		cout << "¡á¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡á" << endl;	// 8//±â¼ú
	}
}

void monsterBase::MonsterNormal()
{
	if (_monsterName == "¿ø¼þÀÌ")
	{
		SetColor(9, 15);

		cout << "¡à"; SetColor(0, 15); cout << "¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡á¡á¡¡¡¡¡¡¡¡¡¡"; SetColor(9, 15); cout << "¡à" << endl;	// 9
		cout << "¡à"; SetColor(0, 15); cout << "¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡á¡á¡¡¡¡¡¡¡¡¡¡"; SetColor(9, 15); cout << "¡à" << endl;	// 10
		cout << "¡à"; SetColor(0, 15); cout << "¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡á¡¡¡¡¡á¡¡¡¡"; SetColor(9, 15); cout << "¡à" << endl;	// 11
		cout << "¡á"; SetColor(0, 15); cout << "¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡á¡¡¡á¡á¡¡¡¡¡¡"; SetColor(9, 15); cout << "¡á" << endl;	// 12
		cout << "¡á"; SetColor(0, 15); cout << "¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡á¡¡¡¡¡¡¡¡"; SetColor(9, 15); cout << "¡á" << endl;	// 13
		cout << "¡á"; SetColor(0, 15); cout << "¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡á¡¡¡á¡¡¡¡¡¡"; SetColor(9, 15); cout << "¡á" << endl;	// 14
	}
	else if (_monsterName == "¹Ú¡¡Áã")
	{
		SetColor(9, 15);

		cout << "¡à"; SetColor(0, 15); cout << "¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡"; SetColor(9, 15); cout << "¡à" << endl;	// 9
		cout << "¡à"; SetColor(0, 15); cout << "¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡á¡¡¡¡¡¡¡á¡¡¡¡¡¡"; SetColor(9, 15); cout << "¡à" << endl;	// 10
		cout << "¡à"; SetColor(0, 15); cout << "¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡á¡á¡á¡á¡á¡á¡á¡¡¡¡"; SetColor(9, 15); cout << "¡à" << endl;	// 11
		cout << "¡á"; SetColor(0, 15); cout << "¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡á¡¡¡á¡á¡á¡¡¡á¡¡¡¡"; SetColor(9, 15); cout << "¡á" << endl;	// 12
		cout << "¡á"; SetColor(0, 15); cout << "¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡á¡á¡á¡¡¡¡¡¡¡¡"; SetColor(9, 15); cout << "¡á" << endl;	// 13
		cout << "¡á"; SetColor(0, 15); cout << "¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡"; SetColor(9, 15); cout << "¡á" << endl;	// 14
	}
	else if (_monsterName == "µ¶¡¡»ç")
	{
		SetColor(9, 15);

		cout << "¡à¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡"; SetColor(0, 15); cout << "¡á¡á¡á¡¡¡¡¡¡¡¡¡¡¡¡"; SetColor(9, 15); cout << "¡à" << endl;	// 9
		cout << "¡à¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡"; SetColor(0, 15); cout << "¡á¡á¡á¡¡¡¡¡¡¡¡¡¡¡¡"; SetColor(9, 15); cout << "¡à" << endl;	// 10
		cout << "¡à¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡"; SetColor(0, 15); cout << "¡¡¡¡¡á¡¡¡¡¡¡¡¡¡¡¡¡"; SetColor(9, 15); cout << "¡à" << endl;	// 11
		cout << "¡á¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡"; SetColor(0, 15); cout << "¡¡¡¡¡á¡¡¡¡¡á¡¡¡¡¡¡"; SetColor(9, 15); cout << "¡á" << endl;	// 12
		cout << "¡á¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡"; SetColor(0, 15); cout << "¡¡¡¡¡á¡¡¡¡¡¡¡á¡¡¡¡"; SetColor(9, 15); cout << "¡á" << endl;	// 13
		cout << "¡á¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡"; SetColor(0, 15); cout << "¡¡¡¡¡¡¡á¡á¡á¡¡¡¡¡¡"; SetColor(9, 15); cout << "¡á" << endl;	// 14
	}
	else if (_monsterName == "¸äµÅÁö")
	{
		SetColor(9, 15);

		cout << "¡à¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡"; SetColor(9, 15); cout << "¡à" << endl;	// 9
		cout << "¡à¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡"; SetColor(9, 15); cout << "¡à" << endl;	// 10
		cout << "¡à¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡"; SetColor(0, 15); cout << "¡¡¡¡¡á¡á¡á¡á¡á¡¡¡¡¡¡"; SetColor(9, 15); cout << "¡à" << endl;	// 11
		cout << "¡á¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡"; SetColor(0, 15); cout << "¡¡¡á¡á¡á¡á¡á¡á¡¡¡¡¡¡"; SetColor(9, 15); cout << "¡á" << endl;	// 12
		cout << "¡á¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡"; SetColor(0, 15); cout << "¡á¡á¡á¡á¡á¡á¡á¡¡¡¡¡¡"; SetColor(9, 15); cout << "¡á" << endl;	// 13
		cout << "¡á¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡"; SetColor(0, 15); cout << "¡¡¡¡¡á¡¡¡¡¡á¡¡¡¡¡¡¡¡"; SetColor(9, 15); cout << "¡á" << endl;	// 14
	}
	else if (_monsterName == "°¨¿°ÀÚ")
	{
		SetColor(9, 15);


		cout << "¡à¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡"; SetColor(9, 15); cout << "¡à" << endl;	// 9
		cout << "¡à¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡"; SetColor(0, 15); cout << "¡¡¡¡¡¡¡¡¡á¡á¡¡¡¡¡¡¡¡¡¡"; SetColor(9, 15); cout << "¡à" << endl;	// 10
		cout << "¡à¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡"; SetColor(0, 15); cout << "¡¡¡¡¡¡¡¡¡á¡á¡¡¡¡¡¡¡¡¡¡"; SetColor(9, 15); cout << "¡à" << endl;	// 11
		cout << "¡á¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡"; SetColor(0, 15); cout << "¡¡¡¡¡¡¡á¡á¡á¡á¡¡¡¡¡¡¡¡"; SetColor(9, 15); cout << "¡á" << endl;	// 12
		cout << "¡á¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡"; SetColor(0, 15); cout << "¡¡¡¡¡á¡¡¡á¡á¡¡¡á¡¡¡¡¡¡"; SetColor(9, 15); cout << "¡á" << endl;	// 13
		cout << "¡á¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡"; SetColor(0, 15); cout << "¡¡¡¡¡¡¡á¡¡¡¡¡á¡¡¡¡¡¡¡¡"; SetColor(9, 15); cout << "¡á" << endl;	// 14
	}
	else if (_monsterName == "È¯¡¡ÀÚ")
	{
		SetColor(9, 15);

		cout << "¡à¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡"; SetColor(0, 15); cout << "¡¡¡¡¡¡¡¡¡¡¡á¡¡¡¡¡¡¡¡¡¡"; SetColor(9, 15); cout << "¡à" << endl;	// 9
		cout << "¡à¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡"; SetColor(0, 15); cout << "¡¡¡¡¡¡¡¡¡á¡á¡á¡¡¡¡¡¡¡¡"; SetColor(9, 15); cout << "¡à" << endl;	// 10
		cout << "¡à¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡"; SetColor(0, 15); cout << "¡¡¡¡¡¡¡¡¡á¡á¡¡¡¡¡¡¡¡¡¡"; SetColor(9, 15); cout << "¡à" << endl;	// 11
		cout << "¡á¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡"; SetColor(0, 15); cout << "¡¡¡¡¡¡¡á¡á¡á¡á¡¡¡¡¡¡¡¡"; SetColor(9, 15); cout << "¡á" << endl;	// 12
		cout << "¡á¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡"; SetColor(0, 15); cout << "¡¡¡¡¡á¡¡¡á¡á¡¡¡á¡¡¡¡¡¡"; SetColor(9, 15); cout << "¡á" << endl;	// 13
		cout << "¡á¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡"; SetColor(0, 15); cout << "¡¡¡¡¡¡¡á¡¡¡¡¡á¡¡¡¡¡¡¡¡"; SetColor(9, 15); cout << "¡á" << endl;	// 14
	}

}

void monsterBase::MonsterAtk()
{
	if (_monsterName == "¿ø¼þÀÌ")
	{
		SetColor(9, 15);

		cout << "¡à"; SetColor(0, 15); cout << "¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡á¡á¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡"; SetColor(9, 15); cout << "¡à" << endl;	// 9
		cout << "¡à"; SetColor(0, 15); cout << "¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡á¡á¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡"; SetColor(9, 15); cout << "¡à" << endl;	// 10
		cout << "¡à"; SetColor(0, 15); cout << "¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡á¡¡¡¡¡á¡¡¡¡¡¡¡¡¡¡"; SetColor(9, 15); cout << "¡à" << endl;	// 11
		cout << "¡á"; SetColor(0, 15); cout << "¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡á¡á¡¡¡á¡á¡¡¡¡¡¡¡¡¡¡¡¡"; SetColor(9, 15); cout << "¡á" << endl;	// 12
		cout << "¡á"; SetColor(0, 15); cout << "¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡á¡¡¡¡¡¡¡¡¡¡¡¡¡¡"; SetColor(9, 15); cout << "¡á" << endl;	// 13
		cout << "¡á"; SetColor(0, 15); cout << "¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡á¡¡¡á¡¡¡¡¡¡¡¡¡¡¡¡"; SetColor(9, 15); cout << "¡á" << endl;	// 14
	}
	else if (_monsterName == "¹Ú¡¡Áã")
	{
		SetColor(9, 15);

		cout << "¡à"; SetColor(0, 15); cout << "¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡"; SetColor(9, 15); cout << "¡à" << endl;	// 9
		cout << "¡à"; SetColor(0, 15); cout << "¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡á¡¡¡á¡¡¡¡¡¡¡á¡¡¡á¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡"; SetColor(9, 15); cout << "¡à" << endl;	// 10
		cout << "¡à"; SetColor(0, 15); cout << "¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡á¡á¡á¡á¡á¡á¡á¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡"; SetColor(9, 15); cout << "¡à" << endl;	// 11
		cout << "¡á"; SetColor(0, 15); cout << "¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡á¡á¡á¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡"; SetColor(9, 15); cout << "¡á" << endl;	// 12
		cout << "¡á"; SetColor(0, 15); cout << "¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡á¡¡¡á¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡"; SetColor(9, 15); cout << "¡á" << endl;	// 13
		cout << "¡á"; SetColor(0, 15); cout << "¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡á¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡"; SetColor(9, 15); cout << "¡á" << endl;	// 14
	}
	else if (_monsterName == "µ¶¡¡»ç")
	{
		SetColor(9, 15);

		cout << "¡à¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡"; SetColor(9, 15); cout << "¡à" << endl;	// 9
		cout << "¡à¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡"; SetColor(0, 15); cout << "¡¡¡á¡á¡á¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡"; SetColor(9, 15); cout << "¡à" << endl;	// 10
		cout << "¡à¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡"; SetColor(0, 15); cout << "¡á¡á¡á¡á¡á¡¡¡¡¡¡¡á¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡"; SetColor(9, 15); cout << "¡à" << endl;	// 11
		cout << "¡á¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡"; SetColor(0, 15); cout << "¡¡¡¡¡á¡á¡á¡¡¡¡¡á¡¡¡á¡¡¡á¡¡¡¡¡¡¡¡¡¡"; SetColor(9, 15); cout << "¡á" << endl;	// 12
		cout << "¡á¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡"; SetColor(0, 15); cout << "¡¡¡á¡¡¡¡¡á¡á¡á¡¡¡¡¡¡¡á¡¡¡¡¡¡¡¡¡¡¡¡"; SetColor(9, 15); cout << "¡á" << endl;	// 13
		cout << "¡á¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡"; SetColor(9, 15); cout << "¡á" << endl;	// 14
	}
	else if (_monsterName == "¸äµÅÁö")
	{
		SetColor(9, 15);

		cout << "¡à¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡"; SetColor(9, 15); cout << "¡à" << endl;	// 9
		cout << "¡à¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡"; SetColor(9, 15); cout << "¡à" << endl;	// 10
		cout << "¡à¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡"; SetColor(0, 15); cout << "¡¡¡¡¡á¡á¡á¡á¡á¡¡¡á¡¡¡á¡¡¡á¡¡¡á¡¡¡¡¡¡¡¡"; SetColor(9, 15); cout << "¡à" << endl;	// 11
		cout << "¡á¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡"; SetColor(0, 15); cout << "¡¡¡á¡á¡á¡á¡á¡á¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡"; SetColor(9, 15); cout << "¡á" << endl;	// 12
		cout << "¡á¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡"; SetColor(0, 15); cout << "¡á¡á¡á¡á¡á¡á¡á¡¡¡á¡¡¡á¡¡¡á¡¡¡á¡¡¡¡¡¡¡¡"; SetColor(9, 15); cout << "¡á" << endl;	// 13
		cout << "¡á¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡"; SetColor(0, 15); cout << "¡¡¡¡¡á¡¡¡¡¡á¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡"; SetColor(9, 15); cout << "¡á" << endl;	// 14
	}
	else if (_monsterName == "°¨¿°ÀÚ")
	{
		SetColor(9, 15);

		cout << "¡à¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡"; SetColor(0, 15); cout << "¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡"; SetColor(9, 15); cout << "¡à" << endl;	// 9
		cout << "¡à¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡"; SetColor(0, 15); cout << "¡¡¡¡¡¡¡á¡¡¡á¡¡¡¡¡á¡á¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡"; SetColor(9, 15); cout << "¡à" << endl;	// 10
		cout << "¡à¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡"; SetColor(0, 15); cout << "¡¡¡¡¡¡¡¡¡¡¡á¡á¡¡¡á¡á¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡"; SetColor(9, 15); cout << "¡à" << endl;	// 11
		cout << "¡á¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡"; SetColor(0, 15); cout << "¡¡¡á¡¡¡á¡¡¡¡¡¡¡á¡á¡á¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡"; SetColor(9, 15); cout << "¡á" << endl;	// 12
		cout << "¡á¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡"; SetColor(0, 15); cout << "¡¡¡¡¡¡¡¡¡¡¡á¡á¡¡¡á¡á¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡"; SetColor(9, 15); cout << "¡á" << endl;	// 13
		cout << "¡á¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡"; SetColor(0, 15); cout << "¡¡¡¡¡¡¡á¡¡¡á¡¡¡á¡¡¡¡¡á¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡"; SetColor(9, 15); cout << "¡á" << endl;	// 14
	}
	else if (_monsterName == "È¯¡¡ÀÚ")
	{
		SetColor(9, 15);

		cout << "¡à¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡"; SetColor(0, 15); cout << "¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡á¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡"; SetColor(9, 15); cout << "¡à" << endl;	// 9
		cout << "¡à¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡"; SetColor(0, 15); cout << "¡¡¡¡¡¡¡á¡¡¡¡¡á¡¡¡¡¡á¡á¡á¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡"; SetColor(9, 15); cout << "¡à" << endl;	// 10
		cout << "¡à¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡"; SetColor(0, 15); cout << "¡¡¡á¡¡¡¡¡¡¡¡¡¡¡á¡¡¡á¡á¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡"; SetColor(9, 15); cout << "¡à" << endl;	// 11
		cout << "¡á¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡"; SetColor(0, 15); cout << "¡¡¡¡¡¡¡¡¡á¡á¡á¡á¡á¡á¡á¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡"; SetColor(9, 15); cout << "¡á" << endl;	// 12
		cout << "¡á¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡"; SetColor(0, 15); cout << "¡¡¡á¡¡¡¡¡¡¡¡¡¡¡á¡¡¡á¡á¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡"; SetColor(9, 15); cout << "¡á" << endl;	// 13
		cout << "¡á¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡"; SetColor(0, 15); cout << "¡¡¡¡¡¡¡á¡¡¡¡¡á¡¡¡á¡¡¡¡¡á¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡"; SetColor(9, 15); cout << "¡á" << endl;	// 14
	}
}

void monsterBase::MonsterGetDmg1()
{
	if (_monsterName == "¿ø¼þÀÌ")
	{
		SetColor(9, 15);

		cout << "¡à¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡"; SetColor(14, 15); cout << "¡¡¡á¡¡¡¡¡¡¡¡¡¡"; SetColor(0, 15); cout << "¡¡¡á¡á¡¡¡¡¡¡¡¡"; SetColor(9, 15); cout << "¡à" << endl;	// 9
		cout << "¡à¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡"; SetColor(14, 15); cout << "¡¡¡á¡¡¡¡¡¡¡¡¡¡"; SetColor(0, 15); cout << "¡¡¡á¡á¡¡¡¡¡¡¡¡"; SetColor(9, 15); cout << "¡à" << endl;	// 10
		cout << "¡à¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡"; SetColor(14, 15); cout << "¡á¡á¡á¡á¡á¡á¡¡"; SetColor(0, 15); cout << "¡á¡á¡¡¡¡¡á¡¡¡¡"; SetColor(9, 15); cout << "¡à" << endl;	// 11
		cout << "¡á¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡"; SetColor(14, 15); cout << "¡¡¡á¡¡¡á¡¡¡¡¡¡"; SetColor(0, 15); cout << "¡¡¡¡¡á¡á¡¡¡¡¡¡"; SetColor(9, 15); cout << "¡á" << endl;	// 12
		cout << "¡á¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡"; SetColor(14, 15); cout << "¡¡¡á¡¡¡¡¡¡¡¡¡¡"; SetColor(0, 15); cout << "¡¡¡¡¡á¡¡¡¡¡¡¡¡"; SetColor(9, 15); cout << "¡á" << endl;	// 13
		cout << "¡á¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡"; SetColor(0, 15); cout << "¡¡¡á¡¡¡á¡¡¡¡¡¡"; SetColor(9, 15); cout << "¡á" << endl;	// 14
	}
	else if (_monsterName == "¹Ú¡¡Áã")
	{
		SetColor(9, 15);

		cout << "¡à¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡"; SetColor(0, 15); cout << "¡¡¡á¡á¡¡¡¡¡¡¡¡¡¡"; SetColor(9, 15); cout << "¡à" << endl;	// 9
		cout << "¡à¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡"; SetColor(14, 15); cout << "¡¡¡á¡¡¡¡¡¡¡¡¡¡¡¡"; SetColor(0, 15); cout << "¡á¡á¡¡¡¡¡¡¡¡¡¡¡¡"; SetColor(9, 15); cout << "¡à" << endl;	// 10
		cout << "¡à¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡"; SetColor(14, 15); cout << "¡¡¡á¡¡¡¡¡¡¡¡¡¡¡¡"; SetColor(0, 15); cout << "¡á¡á¡á¡á¡¡¡¡¡¡¡¡"; SetColor(9, 15); cout << "¡à" << endl;	// 11
		cout << "¡á¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡"; SetColor(14, 15); cout << "¡á¡á¡á¡á¡á¡á¡¡¡¡"; SetColor(0, 15); cout << "¡¡¡á¡á¡á¡¡¡á¡¡¡¡"; SetColor(9, 15); cout << "¡á" << endl;	// 12
		cout << "¡á¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡"; SetColor(14, 15); cout << "¡¡¡á¡¡¡á¡¡¡¡¡¡¡¡"; SetColor(0, 15); cout << "¡¡¡¡¡á¡á¡á¡á¡¡¡¡"; SetColor(9, 15); cout << "¡á" << endl;	// 13
		cout << "¡á¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡"; SetColor(14, 15); cout << "¡¡¡á¡¡¡¡¡¡¡¡¡¡¡¡"; SetColor(0, 15); cout << "¡¡¡¡¡¡¡á¡á¡¡¡¡¡¡"; SetColor(9, 15); cout << "¡á" << endl;	// 14
	}
	else if (_monsterName == "µ¶¡¡»ç")
	{
		SetColor(9, 15);

		cout << "¡à¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡"; SetColor(14, 15); cout << "¡¡¡á¡¡¡¡¡¡¡¡¡¡"; SetColor(0, 15); cout << "¡¡¡á¡á¡¡¡¡¡¡¡¡¡¡¡¡"; SetColor(9, 15); cout << "¡à" << endl;	// 9
		cout << "¡à¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡"; SetColor(14, 15); cout << "¡¡¡á¡¡¡¡¡¡¡¡¡¡"; SetColor(0, 15); cout << "¡á¡á¡á¡¡¡¡¡¡¡¡¡¡¡¡"; SetColor(9, 15); cout << "¡à" << endl;	// 10
		cout << "¡à¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡"; SetColor(14, 15); cout << "¡á¡á¡á¡á¡á¡á¡¡"; SetColor(0, 15); cout << "¡á¡á¡¡¡¡¡¡¡¡¡¡¡¡¡¡"; SetColor(9, 15); cout << "¡à" << endl;	// 11
		cout << "¡á¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡"; SetColor(14, 15); cout << "¡¡¡á¡¡¡á¡¡¡¡¡¡"; SetColor(0, 15); cout << "¡¡¡á¡¡¡¡¡¡¡¡¡¡¡¡¡¡"; SetColor(9, 15); cout << "¡á" << endl;	// 12
		cout << "¡á¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡"; SetColor(14, 15); cout << "¡¡¡á¡¡¡¡¡¡¡¡¡¡"; SetColor(0, 15); cout << "¡¡¡¡¡á¡á¡á¡¡¡¡¡á¡¡"; SetColor(9, 15); cout << "¡á" << endl;	// 13
		cout << "¡á¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡"; SetColor(0, 15); cout << "¡¡¡¡¡¡¡¡¡¡¡á¡á¡¡¡¡"; SetColor(9, 15); cout << "¡á" << endl;	// 14
	}
	else if (_monsterName == "¸äµÅÁö")
	{
		SetColor(9, 15);

		cout << "¡à¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡"; SetColor(14, 15); cout << "¡¡¡á¡¡¡¡¡¡¡¡¡¡"; SetColor(0, 15); cout << "¡á¡á¡á¡á¡á¡¡¡¡¡¡"; SetColor(9, 15); cout << "¡à" << endl;	// 9
		cout << "¡à¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡"; SetColor(14, 15); cout << "¡¡¡á¡¡¡¡¡¡¡¡¡¡"; SetColor(0, 15); cout << "¡á¡á¡á¡á¡á¡á¡¡¡¡"; SetColor(9, 15); cout << "¡à" << endl;	// 10
		cout << "¡à¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡"; SetColor(14, 15); cout << "¡á¡á¡á¡á¡á¡á¡¡"; SetColor(0, 15); cout << "¡¡¡á¡á¡á¡á¡á¡¡¡¡"; SetColor(9, 15); cout << "¡à" << endl;	// 11
		cout << "¡á¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡"; SetColor(14, 15); cout << "¡¡¡á¡¡¡á¡¡¡¡¡¡"; SetColor(0, 15); cout << "¡á¡¡¡á¡á¡á¡á¡¡¡¡"; SetColor(9, 15); cout << "¡á" << endl;	// 12
		cout << "¡á¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡"; SetColor(14, 15); cout << "¡¡¡á¡¡¡¡¡¡¡¡¡¡"; SetColor(0, 15); cout << "¡¡¡¡¡¡¡á¡á¡¡¡¡¡¡"; SetColor(9, 15); cout << "¡á" << endl;	// 13
		cout << "¡á¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡"; SetColor(0, 15); cout << "¡¡¡¡¡á¡¡¡¡¡¡¡¡¡¡"; SetColor(9, 15); cout << "¡á" << endl;	// 14
	}
	else if (_monsterName == "°¨¿°ÀÚ")
	{
		SetColor(9, 15);

		cout << "¡à¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡"; SetColor(14, 15); cout << "¡¡¡á¡¡¡¡¡¡¡¡¡¡"; SetColor(0, 15); cout << "¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡"; SetColor(9, 15); cout << "¡à" << endl;	// 9
		cout << "¡à¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡"; SetColor(14, 15); cout << "¡¡¡á¡¡¡¡¡¡¡¡¡¡"; SetColor(0, 15); cout << "¡¡¡¡¡¡¡á¡á¡¡¡¡¡¡¡¡"; SetColor(9, 15); cout << "¡à" << endl;	// 10
		cout << "¡à¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡"; SetColor(14, 15); cout << "¡á¡á¡á¡á¡á¡á¡¡"; SetColor(0, 15); cout << "¡¡¡¡¡¡¡á¡á¡¡¡¡¡¡¡¡"; SetColor(9, 15); cout << "¡à" << endl;	// 11
		cout << "¡á¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡"; SetColor(14, 15); cout << "¡¡¡á¡¡¡á¡¡¡¡¡¡"; SetColor(0, 15); cout << "¡¡¡á¡á¡á¡á¡á¡¡¡¡¡¡"; SetColor(9, 15); cout << "¡á" << endl;	// 12
		cout << "¡á¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡"; SetColor(14, 15); cout << "¡¡¡á¡¡¡¡¡¡¡¡¡¡"; SetColor(0, 15); cout << "¡á¡¡¡á¡á¡¡¡á¡¡¡¡¡¡"; SetColor(9, 15); cout << "¡á" << endl;	// 13
		cout << "¡á¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡"; SetColor(0, 15); cout << "¡¡¡á¡¡¡¡¡á¡¡¡¡¡¡¡¡"; SetColor(9, 15); cout << "¡á" << endl;	// 14
	}
	else if (_monsterName == "È¯¡¡ÀÚ")
	{
		SetColor(9, 15);

		cout << "¡à¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡"; SetColor(14, 15); cout << "¡¡¡¡¡á¡¡¡¡¡¡¡¡¡¡"; SetColor(0, 15); cout << "¡¡¡¡¡¡¡¡¡á¡¡¡¡¡¡¡¡"; SetColor(9, 15); cout << "¡à" << endl;	// 9
		cout << "¡à¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡"; SetColor(14, 15); cout << "¡¡¡¡¡á¡¡¡¡¡¡¡¡¡¡"; SetColor(0, 15); cout << "¡¡¡¡¡¡¡á¡á¡á¡¡¡¡¡¡"; SetColor(9, 15); cout << "¡à" << endl;	// 10
		cout << "¡à¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡"; SetColor(14, 15); cout << "¡¡¡á¡á¡á¡á¡á¡á¡¡"; SetColor(0, 15); cout << "¡¡¡¡¡¡¡á¡á¡¡¡¡¡¡¡¡"; SetColor(9, 15); cout << "¡à" << endl;	// 11
		cout << "¡á¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡"; SetColor(14, 15); cout << "¡¡¡¡¡á¡¡¡á¡¡¡¡¡¡"; SetColor(0, 15); cout << "¡á¡á¡á¡á¡á¡á¡á¡¡¡¡"; SetColor(9, 15); cout << "¡á" << endl;	// 12
		cout << "¡á¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡"; SetColor(14, 15); cout << "¡¡¡¡¡á¡¡¡¡¡¡¡¡¡¡"; SetColor(0, 15); cout << "¡¡¡¡¡á¡á¡¡¡¡¡¡¡¡¡¡"; SetColor(9, 15); cout << "¡á" << endl;	// 13
		cout << "¡á¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡"; SetColor(0, 15); cout << "¡¡¡á¡¡¡á¡¡¡¡¡¡¡¡¡¡"; SetColor(9, 15); cout << "¡á" << endl;	// 14
	}

}

void monsterBase::MonsterGetDmg2()
{
	if (_monsterName == "¿ø¼þÀÌ")
	{
		SetColor(9, 15);

		cout << "¡à¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡"; SetColor(0, 15); cout << "¡¡¡á¡á¡¡¡¡¡¡¡¡"; SetColor(9, 15); cout << "¡à" << endl;	// 9
		cout << "¡à¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡"; SetColor(12, 15); cout << "¡á¡á¡á¡¡"; SetColor(0, 15); cout << "¡¡¡á¡á¡¡¡¡¡¡¡¡"; SetColor(9, 15); cout << "¡à" << endl;	// 10
		cout << "¡à¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡"; SetColor(12, 15); cout << "¡á¡á¡á¡¡"; SetColor(0, 15); cout << "¡á¡á¡¡¡¡¡á¡¡¡¡"; SetColor(9, 15); cout << "¡à" << endl;	// 11
		cout << "¡á¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡"; SetColor(0, 15); cout << "¡¡¡¡¡¡¡á¡¡¡¡"; SetColor(12, 15); cout << "¡á¡á¡á¡¡"; SetColor(0, 15); cout << "¡¡¡¡¡á¡á¡¡¡¡¡¡"; SetColor(9, 15); cout << "¡á" << endl;	// 12
		cout << "¡á¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡"; SetColor(0, 15); cout << "¡á¡¡¡¡¡¡¡á¡¡¡¡¡¡¡¡¡¡"; SetColor(0, 15); cout << "¡¡¡¡¡á¡¡¡¡¡¡¡¡"; SetColor(9, 15); cout << "¡á" << endl;	// 13
		cout << "¡á¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡"; SetColor(0, 15); cout << "¡¡¡á¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡"; SetColor(0, 15); cout << "¡¡¡á¡¡¡á¡¡¡¡¡¡"; SetColor(9, 15); cout << "¡á" << endl;	// 14

	}
	else if (_monsterName == "¹Ú¡¡Áã")
	{
		SetColor(9, 15);

		cout << "¡à¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡"; SetColor(0, 15); cout << "¡¡¡á¡á¡¡¡¡¡¡¡¡¡¡"; SetColor(9, 15); cout << "¡à" << endl;	// 9
		cout << "¡à¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡"; SetColor(12, 15); cout << "¡á¡á¡á¡¡¡¡"; SetColor(0, 15); cout << "¡á¡á¡¡¡¡¡¡¡¡¡¡¡¡"; SetColor(9, 15); cout << "¡à" << endl;	// 10
		cout << "¡à¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡"; SetColor(12, 15); cout << "¡á¡á¡á¡¡¡¡"; SetColor(0, 15); cout << "¡á¡á¡á¡á¡¡¡¡¡¡¡¡"; SetColor(9, 15); cout << "¡à" << endl;	// 11
		cout << "¡á¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡"; SetColor(0, 15); cout << "¡¡¡¡¡á¡¡¡¡"; SetColor(12, 15); cout << "¡á¡á¡á¡¡¡¡"; SetColor(0, 15); cout << "¡¡¡á¡á¡á¡¡¡á¡¡¡¡"; SetColor(9, 15); cout << "¡á" << endl;	// 12
		cout << "¡á¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡"; SetColor(0, 15); cout << "¡á¡¡¡¡¡á¡¡¡¡¡¡¡¡¡¡¡¡"; SetColor(0, 15); cout << "¡¡¡¡¡á¡á¡á¡á¡¡¡¡"; SetColor(9, 15); cout << "¡á" << endl;	// 13
		cout << "¡á¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡"; SetColor(0, 15); cout << "¡¡¡á¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡"; SetColor(0, 15); cout << "¡¡¡¡¡¡¡á¡á¡¡¡¡¡¡"; SetColor(9, 15); cout << "¡á" << endl;	// 14
	}
	else if (_monsterName == "µ¶¡¡»ç")
	{
		SetColor(9, 15);

		cout << "¡à¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡"; SetColor(0, 15); cout << "¡¡¡á¡á¡¡¡¡¡¡¡¡¡¡¡¡"; SetColor(9, 15); cout << "¡à" << endl;	// 9
		cout << "¡à¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡"; SetColor(12, 15); cout << "¡á¡á¡á¡¡"; SetColor(0, 15); cout << "¡á¡á¡á¡¡¡¡¡¡¡¡¡¡¡¡"; SetColor(9, 15); cout << "¡à" << endl;	// 10
		cout << "¡à¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡"; SetColor(12, 15); cout << "¡á¡á¡á¡¡"; SetColor(0, 15); cout << "¡á¡á¡¡¡¡¡¡¡¡¡¡¡¡¡¡"; SetColor(9, 15); cout << "¡à" << endl;	// 11
		cout << "¡á¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡"; SetColor(0, 15); cout << "¡¡¡¡¡á¡¡¡¡"; SetColor(12, 15); cout << "¡á¡á¡á¡¡"; SetColor(0, 15); cout << "¡¡¡á¡¡¡¡¡¡¡¡¡¡¡¡¡¡"; SetColor(9, 15); cout << "¡á" << endl;	// 12
		cout << "¡á¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡"; SetColor(0, 15); cout << "¡á¡¡¡¡¡á¡¡¡¡¡¡¡¡¡¡"; SetColor(0, 15); cout << "¡¡¡¡¡á¡á¡á¡¡¡¡¡á¡¡"; SetColor(9, 15); cout << "¡á" << endl;	// 13
		cout << "¡á¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡"; SetColor(0, 15); cout << "¡¡¡á¡¡¡¡¡¡¡¡¡¡¡¡¡¡"; SetColor(0, 15); cout << "¡¡¡¡¡¡¡¡¡¡¡á¡á¡¡¡¡"; SetColor(9, 15); cout << "¡á" << endl;	// 14
	}
	else if (_monsterName == "¸äµÅÁö")
	{
		SetColor(9, 15);

		cout << "¡à¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡"; SetColor(0, 15); cout << "¡á¡á¡á¡á¡á¡¡¡¡¡¡"; SetColor(9, 15); cout << "¡à" << endl;	// 9
		cout << "¡à¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡"; SetColor(12, 15); cout << "¡á¡á¡á¡¡¡¡"; SetColor(0, 15); cout << "¡á¡á¡á¡á¡á¡á¡¡¡¡"; SetColor(9, 15); cout << "¡à" << endl;	// 10
		cout << "¡à¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡"; SetColor(12, 15); cout << "¡á¡á¡á¡¡¡¡"; SetColor(0, 15); cout << "¡¡¡á¡á¡á¡á¡á¡¡¡¡"; SetColor(9, 15); cout << "¡à" << endl;	// 11
		cout << "¡á¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡"; SetColor(0, 15); cout << "¡¡¡¡¡á¡¡¡¡"; SetColor(12, 15); cout << "¡á¡á¡á¡¡¡¡"; SetColor(0, 15); cout << "¡á¡¡¡á¡á¡á¡á¡¡¡¡"; SetColor(9, 15); cout << "¡á" << endl;	// 12
		cout << "¡á¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡"; SetColor(0, 15); cout << "¡á¡¡¡¡¡á¡¡¡¡¡¡¡¡¡¡¡¡"; SetColor(0, 15); cout << "¡¡¡¡¡¡¡á¡á¡¡¡¡¡¡"; SetColor(9, 15); cout << "¡á" << endl;	// 13
		cout << "¡á¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡"; SetColor(0, 15); cout << "¡¡¡á¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡"; SetColor(0, 15); cout << "¡¡¡¡¡á¡¡¡¡¡¡¡¡¡¡"; SetColor(9, 15); cout << "¡á" << endl;	// 14
	}
	else if (_monsterName == "°¨¿°ÀÚ")
	{
		SetColor(9, 15);

		cout << "¡à¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡"; SetColor(0, 15); cout << "¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡"; SetColor(9, 15); cout << "¡à" << endl;	// 9
		cout << "¡à¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡"; SetColor(12, 15); cout << "¡á¡á¡á¡¡"; SetColor(0, 15); cout << "¡¡¡¡¡¡¡á¡á¡¡¡¡¡¡¡¡"; SetColor(9, 15); cout << "¡à" << endl;	// 10
		cout << "¡à¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡"; SetColor(12, 15); cout << "¡á¡á¡á¡¡"; SetColor(0, 15); cout << "¡¡¡¡¡¡¡á¡á¡¡¡¡¡¡¡¡"; SetColor(9, 15); cout << "¡à" << endl;	// 11
		cout << "¡á¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡"; SetColor(0, 15); cout << "¡¡¡¡¡¡¡á¡¡¡¡"; SetColor(12, 15); cout << "¡á¡á¡á¡¡"; SetColor(0, 15); cout << "¡¡¡á¡á¡á¡á¡á¡¡¡¡¡¡"; SetColor(9, 15); cout << "¡á" << endl;	// 12
		cout << "¡á¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡"; SetColor(0, 15); cout << "¡á¡¡¡¡¡¡¡á¡¡¡¡¡¡¡¡¡¡"; SetColor(0, 15); cout << "¡á¡¡¡á¡á¡¡¡á¡¡¡¡¡¡"; SetColor(9, 15); cout << "¡á" << endl;	// 13
		cout << "¡á¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡"; SetColor(0, 15); cout << "¡¡¡á¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡"; SetColor(0, 15); cout << "¡¡¡á¡¡¡¡¡á¡¡¡¡¡¡¡¡"; SetColor(9, 15); cout << "¡á" << endl;	// 14
	}
	else if (_monsterName == "È¯¡¡ÀÚ")
	{
		SetColor(9, 15);

		cout << "¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡"; SetColor(0, 15); cout << "¡¡¡¡¡¡¡¡¡á¡¡¡¡¡¡¡¡"; SetColor(9, 15); cout << "¡à" << endl;	// 9
		cout << "¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡"; SetColor(12, 15); cout << "¡á¡á¡á¡¡"; SetColor(0, 15); cout << "¡¡¡¡¡¡¡á¡á¡á¡¡¡¡¡¡"; SetColor(9, 15); cout << "¡à" << endl;	// 10
		cout << "¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡"; SetColor(12, 15); cout << "¡á¡á¡á¡¡"; SetColor(0, 15); cout << "¡¡¡¡¡¡¡á¡á¡¡¡¡¡¡¡¡"; SetColor(9, 15); cout << "¡à" << endl;	// 11
		cout << "¡á¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡"; SetColor(0, 15); cout << "¡¡¡¡¡¡¡á¡¡¡¡"; SetColor(12, 15); cout << "¡á¡á¡á¡¡"; SetColor(0, 15); cout << "¡á¡á¡á¡á¡á¡á¡á¡¡¡¡"; SetColor(9, 15); cout << "¡á" << endl;	// 12
		cout << "¡á¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡"; SetColor(0, 15); cout << "¡á¡¡¡¡¡¡¡á¡¡¡¡¡¡¡¡¡¡"; SetColor(0, 15); cout << "¡¡¡¡¡á¡á¡¡¡¡¡¡¡¡¡¡"; SetColor(9, 15); cout << "¡á" << endl;	// 13
		cout << "¡á¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡"; SetColor(0, 15); cout << "¡¡¡á¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡"; SetColor(0, 15); cout << "¡¡¡á¡¡¡á¡¡¡¡¡¡¡¡¡¡"; SetColor(9, 15); cout << "¡á" << endl;	// 14
	}

}

void monsterBase::MonsterGetDmg3()
{
	if (_monsterName == "¿ø¼þÀÌ")
	{
		SetColor(9, 15);

		cout << "¡à¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡"; SetColor(0, 15); cout << "¡¡¡á¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡"; SetColor(0, 15); cout << "¡¡¡á¡á¡¡¡¡¡¡¡¡"; SetColor(9, 15); cout << "¡à" << endl;	// 9
		cout << "¡à¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡"; SetColor(0, 15); cout << "¡á¡¡¡¡¡¡¡á¡¡¡¡¡¡¡¡¡¡"; SetColor(0, 15); cout << "¡¡¡á¡á¡¡¡¡¡¡¡¡"; SetColor(9, 15); cout << "¡à" << endl;	// 10
		cout << "¡à¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡"; SetColor(0, 15); cout << "¡¡¡¡¡¡¡á¡¡¡¡"; SetColor(12, 15); cout << "¡á¡á¡á¡¡"; SetColor(0, 15); cout << "¡á¡á¡¡¡¡¡á¡¡¡¡"; SetColor(9, 15); cout << "¡à" << endl;	// 11
		cout << "¡á¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡"; SetColor(12, 15); cout << "¡á¡á¡á¡¡"; SetColor(0, 15); cout << "¡¡¡¡¡á¡á¡¡¡¡¡¡"; SetColor(9, 15); cout << "¡á" << endl;	// 12
		cout << "¡á¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡"; SetColor(12, 15); cout << "¡á¡á¡á¡¡"; SetColor(0, 15); cout << "¡¡¡¡¡á¡¡¡¡¡¡¡¡"; SetColor(9, 15); cout << "¡á" << endl;	// 13
		cout << "¡á¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡"; SetColor(0, 15); cout << "¡¡¡á¡¡¡á¡¡¡¡¡¡"; SetColor(9, 15); cout << "¡á" << endl;	// 14
	}
	else if (_monsterName == "¹Ú¡¡Áã")
	{
		SetColor(9, 15);

		cout << "¡à¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡"; SetColor(0, 15); cout << "¡¡¡á¡á¡¡¡¡¡¡¡¡¡¡"; SetColor(9, 15); cout << "¡à" << endl;	// 9
		cout << "¡à¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡"; SetColor(0, 15); cout << "¡¡¡á¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡"; SetColor(0, 15); cout << "¡á¡á¡¡¡¡¡¡¡¡¡¡¡¡"; SetColor(9, 15); cout << "¡à" << endl;	// 10
		cout << "¡à¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡"; SetColor(0, 15); cout << "¡á¡¡¡¡¡á¡¡¡¡¡¡¡¡¡¡¡¡"; SetColor(0, 15); cout << "¡á¡á¡á¡á¡¡¡¡¡¡¡¡"; SetColor(9, 15); cout << "¡à" << endl;	// 11
		cout << "¡á¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡"; SetColor(0, 15); cout << "¡¡¡¡¡á¡¡¡¡"; SetColor(12, 15); cout << "¡á¡á¡á¡¡¡¡"; SetColor(0, 15); cout << "¡¡¡á¡á¡á¡¡¡á¡¡¡¡"; SetColor(9, 15); cout << "¡á" << endl;	// 12
		cout << "¡á¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡"; SetColor(12, 15); cout << "¡á¡á¡á¡¡¡¡"; SetColor(0, 15); cout << "¡¡¡¡¡á¡á¡á¡á¡¡¡¡"; SetColor(9, 15); cout << "¡á" << endl;	// 13
		cout << "¡á¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡"; SetColor(12, 15); cout << "¡á¡á¡á¡¡¡¡"; SetColor(0, 15); cout << "¡¡¡¡¡¡¡á¡á¡¡¡¡¡¡"; SetColor(9, 15); cout << "¡á" << endl;	// 14
	}
	else if (_monsterName == "µ¶¡¡»ç")
	{
		SetColor(9, 15);

		cout << "¡à¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡"; SetColor(0, 15); cout << "¡¡¡á¡¡¡¡¡¡¡¡¡¡¡¡¡¡"; SetColor(0, 15); cout << "¡¡¡á¡á¡¡¡¡¡¡¡¡¡¡¡¡"; SetColor(9, 15); cout << "¡à" << endl;	// 9
		cout << "¡à¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡"; SetColor(0, 15); cout << "¡á¡¡¡¡¡á¡¡¡¡¡¡¡¡¡¡"; SetColor(0, 15); cout << "¡á¡á¡á¡¡¡¡¡¡¡¡¡¡¡¡"; SetColor(9, 15); cout << "¡à" << endl;	// 10
		cout << "¡à¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡"; SetColor(0, 15); cout << "¡¡¡¡¡á¡¡¡¡"; SetColor(12, 15); cout << "¡á¡á¡á¡¡"; SetColor(0, 15); cout << "¡á¡á¡¡¡¡¡¡¡¡¡¡¡¡¡¡"; SetColor(9, 15); cout << "¡à" << endl;	// 11
		cout << "¡á¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡"; SetColor(12, 15); cout << "¡á¡á¡á¡¡"; SetColor(0, 15); cout << "¡¡¡á¡¡¡¡¡¡¡¡¡¡¡¡¡¡"; SetColor(9, 15); cout << "¡á" << endl;	// 12
		cout << "¡á¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡"; SetColor(12, 15); cout << "¡á¡á¡á¡¡"; SetColor(0, 15); cout << "¡¡¡¡¡á¡á¡á¡¡¡¡¡á¡¡"; SetColor(9, 15); cout << "¡á" << endl;	// 13
		cout << "¡á¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡"; SetColor(0, 15); cout << "¡¡¡¡¡¡¡¡¡¡¡á¡á¡¡¡¡"; SetColor(9, 15); cout << "¡á" << endl;	// 14
	}
	else if (_monsterName == "¸äµÅÁö")
	{
		SetColor(9, 15);

		cout << "¡à¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡"; SetColor(0, 15); cout << "¡¡¡á¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡"; SetColor(0, 15); cout << "¡á¡á¡á¡á¡á¡¡¡¡¡¡"; SetColor(9, 15); cout << "¡à" << endl;	// 9
		cout << "¡à¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡"; SetColor(0, 15); cout << "¡á¡¡¡¡¡á¡¡¡¡¡¡¡¡¡¡¡¡"; SetColor(0, 15); cout << "¡á¡á¡á¡á¡á¡á¡¡¡¡"; SetColor(9, 15); cout << "¡à" << endl;	// 10
		cout << "¡à¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡"; SetColor(0, 15); cout << "¡¡¡¡¡á¡¡¡¡"; SetColor(12, 15); cout << "¡á¡á¡á¡¡¡¡"; SetColor(0, 15); cout << "¡¡¡á¡á¡á¡á¡á¡¡¡¡"; SetColor(9, 15); cout << "¡à" << endl;	// 11
		cout << "¡á¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡"; SetColor(12, 15); cout << "¡á¡á¡á¡¡¡¡"; SetColor(0, 15); cout << "¡á¡¡¡á¡á¡á¡á¡¡¡¡"; SetColor(9, 15); cout << "¡á" << endl;	// 12
		cout << "¡á¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡"; SetColor(12, 15); cout << "¡á¡á¡á¡¡¡¡"; SetColor(0, 15); cout << "¡¡¡¡¡¡¡á¡á¡¡¡¡¡¡"; SetColor(9, 15); cout << "¡á" << endl;	// 13
		cout << "¡á¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡"; SetColor(0, 15); cout << "¡¡¡¡¡á¡¡¡¡¡¡¡¡¡¡"; SetColor(9, 15); cout << "¡á" << endl;	// 14
	}
	else if (_monsterName == "°¨¿°ÀÚ")
	{
		SetColor(9, 15);

		cout << "¡à¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡"; SetColor(0, 15); cout << "¡¡¡á¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡"; SetColor(0, 15); cout << "¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡"; SetColor(9, 15); cout << "¡à" << endl;	// 9
		cout << "¡à¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡"; SetColor(0, 15); cout << "¡á¡¡¡¡¡¡¡á¡¡¡¡¡¡¡¡¡¡"; SetColor(0, 15); cout << "¡¡¡¡¡¡¡á¡á¡¡¡¡¡¡¡¡"; SetColor(9, 15); cout << "¡à" << endl;	// 10
		cout << "¡à¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡"; SetColor(0, 15); cout << "¡¡¡¡¡¡¡á¡¡¡¡"; SetColor(12, 15); cout << "¡á¡á¡á¡¡"; SetColor(0, 15); cout << "¡¡¡¡¡¡¡á¡á¡¡¡¡¡¡¡¡"; SetColor(9, 15); cout << "¡à" << endl;	// 11
		cout << "¡á¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡"; SetColor(12, 15); cout << "¡á¡á¡á¡¡"; SetColor(0, 15); cout << "¡¡¡á¡á¡á¡á¡á¡¡¡¡¡¡"; SetColor(9, 15); cout << "¡á" << endl;	// 12
		cout << "¡á¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡"; SetColor(12, 15); cout << "¡á¡á¡á¡¡"; SetColor(0, 15); cout << "¡á¡¡¡á¡á¡¡¡á¡¡¡¡¡¡"; SetColor(9, 15); cout << "¡á" << endl;	// 13
		cout << "¡á¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡"; SetColor(0, 15); cout << "¡¡¡á¡¡¡¡¡á¡¡¡¡¡¡¡¡"; SetColor(9, 15); cout << "¡á" << endl;	// 14
	}
	else if (_monsterName == "È¯¡¡ÀÚ")
	{
		SetColor(9, 15);

		cout << "¡à¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡"; SetColor(0, 15); cout << "¡¡¡á¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡"; SetColor(0, 15); cout << "¡¡¡¡¡¡¡¡¡á¡¡¡¡¡¡¡¡"; SetColor(9, 15); cout << "¡à" << endl;	// 9
		cout << "¡à¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡"; SetColor(0, 15); cout << "¡á¡¡¡¡¡¡¡á¡¡¡¡¡¡¡¡¡¡"; SetColor(0, 15); cout << "¡¡¡¡¡¡¡á¡á¡á¡¡¡¡¡¡"; SetColor(9, 15); cout << "¡à" << endl;	// 10
		cout << "¡à¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡"; SetColor(0, 15); cout << "¡¡¡¡¡¡¡á¡¡¡¡"; SetColor(12, 15); cout << "¡á¡á¡á¡¡"; SetColor(0, 15); cout << "¡¡¡¡¡¡¡á¡á¡¡¡¡¡¡¡¡"; SetColor(9, 15); cout << "¡à" << endl;	// 11
		cout << "¡á¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡"; SetColor(12, 15); cout << "¡á¡á¡á¡¡"; SetColor(0, 15); cout << "¡á¡á¡á¡á¡á¡á¡á¡¡¡¡"; SetColor(9, 15); cout << "¡á" << endl;	// 12
		cout << "¡á¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡"; SetColor(12, 15); cout << "¡á¡á¡á¡¡"; SetColor(0, 15); cout << "¡¡¡¡¡á¡á¡¡¡¡¡¡¡¡¡¡"; SetColor(9, 15); cout << "¡á" << endl;	// 13
		cout << "¡á¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡"; SetColor(0, 15); cout << "¡¡¡á¡¡¡á¡¡¡¡¡¡¡¡¡¡"; SetColor(9, 15); cout << "¡á" << endl;	// 14
	}
}

void monsterBase::MonsterGetDmg4()
{
	if (_monsterName == "¿ø¼þÀÌ")
	{
		SetColor(9, 15);

		cout << "¡à¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡"; SetColor(0, 15); cout << "¡¡¡á¡á¡¡¡¡¡¡¡¡"; SetColor(9, 15); cout << "¡à" << endl;	// 9
		cout << "¡à¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡"; SetColor(14, 15); cout << "¡¡¡¡¡á¡¡¡¡¡¡¡¡"; SetColor(0, 15); cout << "¡¡¡á¡á¡¡¡¡¡¡¡¡"; SetColor(9, 15); cout << "¡à" << endl;	// 10
		cout << "¡à¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡"; SetColor(14, 15); cout << "¡¡¡¡¡á¡á¡á¡¡¡¡"; SetColor(0, 15); cout << "¡á¡á¡¡¡¡¡á¡¡¡¡"; SetColor(9, 15); cout << "¡à" << endl;	// 11
		cout << "¡á¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡"; SetColor(14, 15); cout << "¡¡¡¡¡á¡¡¡¡¡¡¡¡"; SetColor(0, 15); cout << "¡¡¡¡¡á¡á¡¡¡¡¡¡"; SetColor(9, 15); cout << "¡á" << endl;	// 12
		cout << "¡á¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡"; SetColor(14, 15); cout << "¡¡¡á¡¡¡á¡¡¡¡¡¡"; SetColor(0, 15); cout << "¡¡¡¡¡á¡¡¡¡¡¡¡¡"; SetColor(9, 15); cout << "¡á" << endl;	// 13
		cout << "¡á¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡"; SetColor(0, 15); cout << "¡¡¡á¡¡¡á¡¡¡¡¡¡"; SetColor(9, 15); cout << "¡á" << endl;	// 14
	}
	else if (_monsterName == "¹Ú¡¡Áã")
	{
		SetColor(9, 15);

		cout << "¡à¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡"; SetColor(0, 15); cout << "¡¡¡á¡á¡¡¡¡¡¡¡¡¡¡"; SetColor(9, 15); cout << "¡à" << endl;	// 9
		cout << "¡à¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡"; SetColor(0, 15); cout << "¡á¡á¡¡¡¡¡¡¡¡¡¡¡¡"; SetColor(9, 15); cout << "¡à" << endl;	// 10
		cout << "¡à¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡"; SetColor(14, 15); cout << "¡¡¡á¡¡¡¡¡¡"; SetColor(0, 15); cout << "¡á¡á¡á¡á¡¡¡¡¡¡¡¡"; SetColor(9, 15); cout << "¡à" << endl;	// 11
		cout << "¡á¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡"; SetColor(14, 15); cout << "¡¡¡á¡á¡á¡¡"; SetColor(0, 15); cout << "¡¡¡á¡á¡á¡¡¡á¡¡¡¡"; SetColor(9, 15); cout << "¡á" << endl;	// 12
		cout << "¡á¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡"; SetColor(14, 15); cout << "¡¡¡á¡¡¡¡¡¡"; SetColor(0, 15); cout << "¡¡¡¡¡á¡á¡á¡á¡¡¡¡"; SetColor(9, 15); cout << "¡á" << endl;	// 13
		cout << "¡á¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡"; SetColor(14, 15); cout << "¡á¡¡¡á¡¡¡¡"; SetColor(0, 15); cout << "¡¡¡¡¡¡¡á¡á¡¡¡¡¡¡"; SetColor(9, 15); cout << "¡á" << endl;	// 14
	}
	else if (_monsterName == "µ¶¡¡»ç")
	{
		SetColor(9, 15);


		cout << "¡à¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡"; SetColor(0, 15); cout << "¡¡¡á¡á¡¡¡¡¡¡¡¡¡¡¡¡"; SetColor(9, 15); cout << "¡à" << endl;	// 9
		cout << "¡à¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡"; SetColor(14, 15); cout << "¡¡¡á¡¡¡¡¡¡"; SetColor(0, 15); cout << "¡á¡á¡á¡¡¡¡¡¡¡¡¡¡¡¡"; SetColor(9, 15); cout << "¡à" << endl;	// 10
		cout << "¡à¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡"; SetColor(14, 15); cout << "¡¡¡á¡á¡á¡¡"; SetColor(0, 15); cout << "¡á¡á¡¡¡¡¡¡¡¡¡¡¡¡¡¡"; SetColor(9, 15); cout << "¡à" << endl;	// 11
		cout << "¡á¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡"; SetColor(14, 15); cout << "¡¡¡á¡¡¡¡¡¡"; SetColor(0, 15); cout << "¡¡¡á¡¡¡¡¡¡¡¡¡¡¡¡¡¡"; SetColor(9, 15); cout << "¡á" << endl;	// 12
		cout << "¡á¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡"; SetColor(14, 15); cout << "¡á¡¡¡á¡¡¡¡"; SetColor(0, 15); cout << "¡¡¡¡¡á¡á¡á¡¡¡¡¡á¡¡"; SetColor(9, 15); cout << "¡á" << endl;	// 13
		cout << "¡á¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡"; SetColor(0, 15); cout << "¡¡¡¡¡¡¡¡¡¡¡á¡á¡¡¡¡"; SetColor(9, 15); cout << "¡á" << endl;	// 14
	}
	else if (_monsterName == "¸äµÅÁö")
	{
		SetColor(9, 15);

		cout << "¡à¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡"; SetColor(0, 15); cout << "¡á¡á¡á¡á¡á¡¡¡¡¡¡"; SetColor(9, 15); cout << "¡à" << endl;	// 9
		cout << "¡à¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡"; SetColor(14, 15); cout << "¡¡¡á¡¡¡¡¡¡"; SetColor(0, 15); cout << "¡á¡á¡á¡á¡á¡á¡¡¡¡"; SetColor(9, 15); cout << "¡à" << endl;	// 10
		cout << "¡à¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡"; SetColor(14, 15); cout << "¡¡¡á¡á¡á¡¡"; SetColor(0, 15); cout << "¡¡¡á¡á¡á¡á¡á¡¡¡¡"; SetColor(9, 15); cout << "¡à" << endl;	// 11
		cout << "¡á¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡"; SetColor(14, 15); cout << "¡¡¡á¡¡¡¡¡¡"; SetColor(0, 15); cout << "¡á¡¡¡á¡á¡á¡á¡¡¡¡"; SetColor(9, 15); cout << "¡á" << endl;	// 12
		cout << "¡á¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡"; SetColor(14, 15); cout << "¡á¡¡¡á¡¡¡¡"; SetColor(0, 15); cout << "¡¡¡¡¡¡¡á¡á¡¡¡¡¡¡"; SetColor(9, 15); cout << "¡á" << endl;	// 13
		cout << "¡á¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡"; SetColor(0, 15); cout << "¡¡¡¡¡á¡¡¡¡¡¡¡¡¡¡"; SetColor(9, 15); cout << "¡á" << endl;	// 14
	}
	else if (_monsterName == "°¨¿°ÀÚ")
	{
		SetColor(9, 15);

		cout << "¡à¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡"; SetColor(9, 15); cout << "¡à" << endl;	// 9
		cout << "¡à¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡"; SetColor(0, 15); cout << "¡¡¡¡¡¡¡á¡á¡¡¡¡¡¡¡¡"; SetColor(9, 15); cout << "¡à" << endl;	// 10
		cout << "¡à¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡"; SetColor(14, 15); cout << "¡¡¡¡¡á¡¡¡¡¡¡¡¡"; SetColor(0, 15); cout << "¡¡¡¡¡¡¡á¡á¡¡¡¡¡¡¡¡"; SetColor(9, 15); cout << "¡à" << endl;	// 11
		cout << "¡á¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡"; SetColor(14, 15); cout << "¡¡¡¡¡á¡á¡á¡¡¡¡"; SetColor(0, 15); cout << "¡¡¡á¡á¡á¡á¡á¡¡¡¡¡¡"; SetColor(9, 15); cout << "¡á" << endl;	// 12
		cout << "¡á¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡"; SetColor(14, 15); cout << "¡¡¡¡¡á¡¡¡¡¡¡¡¡"; SetColor(0, 15); cout << "¡á¡¡¡á¡á¡¡¡á¡¡¡¡¡¡"; SetColor(9, 15); cout << "¡á" << endl;	// 13
		cout << "¡á¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡"; SetColor(14, 15); cout << "¡¡¡á¡¡¡á¡¡¡¡¡¡"; SetColor(0, 15); cout << "¡¡¡á¡¡¡¡¡á¡¡¡¡¡¡¡¡"; SetColor(9, 15); cout << "¡á" << endl;	// 14
	}
	else if (_monsterName == "È¯¡¡ÀÚ")
	{
		SetColor(9, 15);

		cout << "¡à¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡"; SetColor(0, 15); cout << "¡¡¡¡¡¡¡¡¡á¡¡¡¡¡¡¡¡"; SetColor(9, 15); cout << "¡à" << endl;	// 9
		cout << "¡à¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡"; SetColor(0, 15); cout << "¡¡¡¡¡¡¡á¡á¡á¡¡¡¡¡¡"; SetColor(9, 15); cout << "¡à" << endl;	// 10
		cout << "¡à¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡"; SetColor(14, 15); cout << "¡¡¡¡¡á¡¡¡¡¡¡¡¡"; SetColor(0, 15); cout << "¡¡¡¡¡¡¡á¡á¡¡¡¡¡¡¡¡"; SetColor(9, 15); cout << "¡à" << endl;	// 11
		cout << "¡á¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡"; SetColor(14, 15); cout << "¡¡¡¡¡á¡á¡á¡¡¡¡"; SetColor(0, 15); cout << "¡á¡á¡á¡á¡á¡á¡á¡¡¡¡"; SetColor(9, 15); cout << "¡á" << endl;	// 12
		cout << "¡á¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡"; SetColor(14, 15); cout << "¡¡¡¡¡á¡¡¡¡¡¡¡¡"; SetColor(0, 15); cout << "¡¡¡¡¡á¡á¡¡¡¡¡¡¡¡¡¡"; SetColor(9, 15); cout << "¡á" << endl;	// 13
		cout << "¡á¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡"; SetColor(14, 15); cout << "¡¡¡á¡¡¡á¡¡¡¡¡¡"; SetColor(0, 15); cout << "¡¡¡á¡¡¡á¡¡¡¡¡¡¡¡¡¡"; SetColor(9, 15); cout << "¡á" << endl;	// 14
	}

}

void monsterBase::MonsterGetDmg5()
{
	if (_monsterName == "¿ø¼þÀÌ")
	{
		SetColor(9, 15);

		cout << "¡à¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡"; SetColor(11, 15); cout << "¡á¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡"; SetColor(0, 15); cout << "¡¡¡á¡á¡¡¡¡¡¡¡¡"; SetColor(9, 15); cout << "¡à" << endl;	// 9
		cout << "¡à¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡"; SetColor(11, 15); cout << "¡á¡¡¡¡¡á¡¡¡¡¡á¡¡¡¡"; SetColor(14, 15); cout << "¡á¡¡¡á¡¡¡¡¡¡¡¡"; SetColor(0, 15); cout << "¡¡¡á¡á¡¡¡¡¡¡¡¡"; SetColor(9, 15); cout << "¡à" << endl;	// 10
		cout << "¡à¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡"; SetColor(14, 15); cout << "¡¡¡á¡á¡á¡á¡¡¡¡"; SetColor(0, 15); cout << "¡á¡á¡¡¡¡¡á¡¡¡¡"; SetColor(9, 15); cout << "¡à" << endl;	// 11
		cout << "¡á¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡"; SetColor(11, 15); cout << "¡á¡¡¡¡¡á¡¡¡¡¡á¡¡¡¡"; SetColor(14, 15); cout << "¡á¡¡¡¡¡¡¡¡¡¡¡¡"; SetColor(0, 15); cout << "¡¡¡¡¡á¡á¡¡¡¡¡¡"; SetColor(9, 15); cout << "¡á" << endl;	// 12
		cout << "¡á¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡"; SetColor(11, 15); cout << "¡á¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡"; SetColor(0, 15); cout << "¡¡¡¡¡á¡¡¡¡¡¡¡¡"; SetColor(9, 15); cout << "¡á" << endl;	// 13
		cout << "¡á¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡"; SetColor(0, 15); cout << "¡¡¡á¡¡¡á¡¡¡¡¡¡"; SetColor(9, 15); cout << "¡á" << endl;	// 14
	}
	else if (_monsterName == "¹Ú¡¡Áã")
	{
		SetColor(9, 15);

		cout << "¡à¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡"; SetColor(0, 15); cout << "¡¡¡á¡á¡¡¡¡¡¡¡¡¡¡"; SetColor(9, 15); cout << "¡à" << endl;	// 9
		cout << "¡à¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡"; SetColor(11, 15); cout << "¡á¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡"; SetColor(0, 15); cout << "¡á¡á¡¡¡¡¡¡¡¡¡¡¡¡"; SetColor(9, 15); cout << "¡à" << endl;	// 10
		cout << "¡à¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡"; SetColor(11, 15); cout << "¡á¡¡¡¡¡á¡¡¡¡¡á¡¡¡¡"; SetColor(14, 15); cout << "¡á¡¡¡á¡¡¡¡¡¡"; SetColor(0, 15); cout << "¡á¡á¡á¡á¡¡¡¡¡¡¡¡"; SetColor(9, 15); cout << "¡à" << endl;	// 11
		cout << "¡á¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡"; SetColor(14, 15); cout << "¡¡¡á¡á¡á¡á¡¡"; SetColor(0, 15); cout << "¡¡¡á¡á¡á¡¡¡á¡¡¡¡"; SetColor(9, 15); cout << "¡á" << endl;	// 12
		cout << "¡á¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡"; SetColor(11, 15); cout << "¡á¡¡¡¡¡á¡¡¡¡¡á¡¡¡¡"; SetColor(14, 15); cout << "¡á¡¡¡¡¡¡¡¡¡¡"; SetColor(0, 15); cout << "¡¡¡¡¡á¡á¡á¡á¡¡¡¡"; SetColor(9, 15); cout << "¡á" << endl;	// 13
		cout << "¡á¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡"; SetColor(11, 15); cout << "¡á¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡"; SetColor(0, 15); cout << "¡¡¡¡¡¡¡á¡á¡¡¡¡¡¡"; SetColor(9, 15); cout << "¡á" << endl;	// 14
	}
	else if (_monsterName == "µ¶¡¡»ç")
	{
		SetColor(9, 15);

		cout << "¡à¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡"; SetColor(0, 15); cout << "¡¡¡á¡á¡¡¡¡¡¡¡¡¡¡¡¡"; SetColor(9, 15); cout << "¡à" << endl;	// 9
		cout << "¡à¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡"; SetColor(11, 15); cout << "¡á¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡"; SetColor(0, 15); cout << "¡á¡á¡á¡¡¡¡¡¡¡¡¡¡¡¡"; SetColor(9, 15); cout << "¡à" << endl;	// 10
		cout << "¡à¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡"; SetColor(11, 15); cout << "¡á¡¡¡¡¡á¡¡¡¡¡á¡¡¡¡"; SetColor(14, 15); cout << "¡á¡¡¡á¡¡¡¡¡¡"; SetColor(0, 15); cout << "¡á¡á¡¡¡¡¡¡¡¡¡¡¡¡¡¡"; SetColor(9, 15); cout << "¡à" << endl;	// 11
		cout << "¡á¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡"; SetColor(14, 15); cout << "¡¡¡á¡á¡á¡á¡¡"; SetColor(0, 15); cout << "¡¡¡á¡¡¡¡¡¡¡¡¡¡¡¡¡¡"; SetColor(9, 15); cout << "¡á" << endl;	// 12
		cout << "¡á¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡"; SetColor(11, 15); cout << "¡á¡¡¡¡¡á¡¡¡¡¡á¡¡¡¡"; SetColor(14, 15); cout << "¡á¡¡¡¡¡¡¡¡¡¡"; SetColor(0, 15); cout << "¡¡¡¡¡á¡á¡á¡¡¡¡¡á¡¡"; SetColor(9, 15); cout << "¡á" << endl;	// 13
		cout << "¡á¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡"; SetColor(11, 15); cout << "¡á¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡"; SetColor(0, 15); cout << "¡¡¡¡¡¡¡¡¡¡¡á¡á¡¡¡¡"; SetColor(9, 15); cout << "¡á" << endl;	// 14
	}
	else if (_monsterName == "¸äµÅÁö")
	{
		SetColor(9, 15);

		cout << "¡à¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡"; SetColor(11, 15); cout << "¡á¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡"; SetColor(0, 15); cout << "¡á¡á¡á¡á¡á¡¡¡¡¡¡"; SetColor(9, 15); cout << "¡à" << endl;	// 9
		cout << "¡à¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡"; SetColor(11, 15); cout << "¡á¡¡¡¡¡á¡¡¡¡¡á¡¡¡¡"; SetColor(14, 15); cout << "¡á¡¡¡á¡¡¡¡¡¡"; SetColor(0, 15); cout << "¡á¡á¡á¡á¡á¡á¡¡¡¡"; SetColor(9, 15); cout << "¡à" << endl;	// 10
		cout << "¡à¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡"; SetColor(14, 15); cout << "¡¡¡á¡á¡á¡á¡¡"; SetColor(0, 15); cout << "¡¡¡á¡á¡á¡á¡á¡¡¡¡"; SetColor(9, 15); cout << "¡à" << endl;	// 11
		cout << "¡á¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡"; SetColor(11, 15); cout << "¡á¡¡¡¡¡á¡¡¡¡¡á¡¡¡¡"; SetColor(14, 15); cout << "¡á¡¡¡¡¡¡¡¡¡¡"; SetColor(0, 15); cout << "¡á¡¡¡á¡á¡á¡á¡¡¡¡"; SetColor(9, 15); cout << "¡á" << endl;	// 12
		cout << "¡á¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡"; SetColor(11, 15); cout << "¡á¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡"; SetColor(0, 15); cout << "¡¡¡¡¡¡¡á¡á¡¡¡¡¡¡"; SetColor(9, 15); cout << "¡á" << endl;	// 13
		cout << "¡á¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡"; SetColor(0, 15); cout << "¡¡¡¡¡á¡¡¡¡¡¡¡¡¡¡"; SetColor(9, 15); cout << "¡á" << endl;	// 14
	}
	else if (_monsterName == "°¨¿°ÀÚ")
	{
		SetColor(9, 15);

		cout << "¡à¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡"; SetColor(9, 15); cout << "¡à" << endl;	// 9
		cout << "¡à¡¡¡¡¡¡¡¡¡¡¡¡"; SetColor(11, 15); cout << "¡¡¡á¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡"; SetColor(0, 15); cout << "¡¡¡¡¡¡¡á¡á¡¡¡¡¡¡¡¡"; SetColor(9, 15); cout << "¡à" << endl;	// 10
		cout << "¡à¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡"; SetColor(11, 15); cout << "¡á¡¡¡¡¡á¡¡¡¡¡á¡¡"; SetColor(14, 15); cout << "¡¡¡á¡¡¡á¡¡¡¡¡¡¡¡"; SetColor(0, 15); cout << "¡¡¡¡¡¡¡á¡á¡¡¡¡¡¡¡¡"; SetColor(9, 15); cout << "¡à" << endl;	// 11
		cout << "¡á¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡"; SetColor(14, 15); cout << "¡¡¡¡¡á¡á¡á¡á¡¡¡¡"; SetColor(0, 15); cout << "¡¡¡á¡á¡á¡á¡á¡¡¡¡¡¡"; SetColor(9, 15); cout << "¡á" << endl;	// 12
		cout << "¡á¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡"; SetColor(11, 15); cout << "¡á¡¡¡¡¡á¡¡¡¡¡á¡¡"; SetColor(14, 15); cout << "¡¡¡á¡¡¡¡¡¡¡¡¡¡¡¡"; SetColor(0, 15); cout << "¡á¡¡¡á¡á¡¡¡á¡¡¡¡¡¡"; SetColor(9, 15); cout << "¡á" << endl;	// 13
		cout << "¡á¡¡¡¡¡¡¡¡¡¡¡¡"; SetColor(11, 15); cout << "¡¡¡á¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡"; SetColor(0, 15); cout << "¡¡¡á¡¡¡¡¡á¡¡¡¡¡¡¡¡"; SetColor(9, 15); cout << "¡á" << endl;	// 14
	}
	else if (_monsterName == "È¯¡¡ÀÚ")
	{
		SetColor(9, 15);

		cout << "¡à¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡"; SetColor(0, 15); cout << "¡¡¡¡¡¡¡¡¡á¡¡¡¡¡¡¡¡"; SetColor(9, 15); cout << "¡à" << endl;	// 9
		cout << "¡à¡¡¡¡¡¡¡¡¡¡¡¡¡¡"; SetColor(11, 15); cout << "¡á¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡"; SetColor(0, 15); cout << "¡¡¡¡¡¡¡á¡á¡á¡¡¡¡¡¡"; SetColor(9, 15); cout << "¡à" << endl;	// 10
		cout << "¡à¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡"; SetColor(11, 15); cout << "¡á¡¡¡¡¡á¡¡¡¡¡á¡¡¡¡"; SetColor(14, 15); cout << "¡á¡¡¡á¡¡¡¡¡¡¡¡"; SetColor(0, 15); cout << "¡¡¡¡¡¡¡á¡á¡¡¡¡¡¡¡¡"; SetColor(9, 15); cout << "¡à" << endl;	// 11
		cout << "¡á¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡"; SetColor(14, 15); cout << "¡¡¡á¡á¡á¡á¡¡¡¡"; SetColor(0, 15); cout << "¡á¡á¡á¡á¡á¡á¡á¡¡¡¡"; SetColor(9, 15); cout << "¡á" << endl;	// 12
		cout << "¡á¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡"; SetColor(11, 15); cout << "¡á¡¡¡¡¡á¡¡¡¡¡á¡¡¡¡"; SetColor(14, 15); cout << "¡á¡¡¡¡¡¡¡¡¡¡¡¡"; SetColor(0, 15); cout << "¡¡¡¡¡á¡á¡¡¡¡¡¡¡¡¡¡"; SetColor(9, 15); cout << "¡á" << endl;	// 13
		cout << "¡á¡¡¡¡¡¡¡¡¡¡¡¡¡¡"; SetColor(11, 15); cout << "¡á¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡"; SetColor(0, 15); cout << "¡¡¡á¡¡¡á¡¡¡¡¡¡¡¡¡¡"; SetColor(9, 15); cout << "¡á" << endl;	// 14
	}

}


void monsterBase::MonsterDefeat1()
{
	if (_monsterName == "¿ø¼þÀÌ")
	{
		SetColor(9, 15);

		cout << "¡à¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡"; SetColor(0, 15); cout << "¡¡¡á¡á¡¡¡¡¡¡¡¡"; SetColor(9, 15); cout << "¡à" << endl;	// 9
		cout << "¡à¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡"; SetColor(0, 15); cout << "¡¡¡á¡á¡¡¡¡¡¡¡¡"; SetColor(9, 15); cout << "¡à" << endl;	// 10
		cout << "¡à¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡"; SetColor(0, 15); cout << "¡á¡á¡¡¡¡¡á¡¡¡¡"; SetColor(9, 15); cout << "¡à" << endl;	// 11
		cout << "¡á¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡"; SetColor(0, 15); cout << "¡¡¡¡¡á¡á¡¡¡¡¡¡"; SetColor(9, 15); cout << "¡á" << endl;	// 12
		cout << "¡á¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡"; SetColor(0, 15); cout << "¡¡¡¡¡á¡¡¡¡¡¡¡¡"; SetColor(9, 15); cout << "¡á" << endl;	// 13
		cout << "¡á¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡"; SetColor(0, 15); cout << "¡¡¡á¡¡¡á¡¡¡¡¡¡"; SetColor(9, 15); cout << "¡á" << endl;	// 14
	}
	else if (_monsterName == "¹Ú¡¡Áã")
	{
		SetColor(9, 15);

		cout << "¡à¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡"; SetColor(0, 15); cout << "¡¡¡á¡á¡¡¡¡¡¡¡¡¡¡"; SetColor(9, 15); cout << "¡à" << endl;	// 9
		cout << "¡à¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡"; SetColor(0, 15); cout << "¡á¡á¡¡¡¡¡¡¡¡¡¡¡¡"; SetColor(9, 15); cout << "¡à" << endl;	// 10
		cout << "¡à¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡"; SetColor(0, 15); cout << "¡á¡á¡á¡á¡¡¡¡¡¡¡¡"; SetColor(9, 15); cout << "¡à" << endl;	// 11
		cout << "¡á¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡"; SetColor(0, 15); cout << "¡¡¡á¡á¡á¡¡¡á¡¡¡¡"; SetColor(9, 15); cout << "¡á" << endl;	// 12
		cout << "¡á¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡"; SetColor(0, 15); cout << "¡¡¡¡¡á¡á¡á¡á¡¡¡¡"; SetColor(9, 15); cout << "¡á" << endl;	// 13
		cout << "¡á¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡"; SetColor(0, 15); cout << "¡¡¡¡¡¡¡á¡á¡¡¡¡¡¡"; SetColor(9, 15); cout << "¡á" << endl;	// 14
	}
	else if (_monsterName == "µ¶¡¡»ç")
	{
		SetColor(9, 15);

		cout << "¡à¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡"; SetColor(0, 15); cout << "¡¡¡á¡á¡¡¡¡¡¡¡¡¡¡¡¡"; SetColor(9, 15); cout << "¡à" << endl;	// 9
		cout << "¡à¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡"; SetColor(0, 15); cout << "¡á¡á¡á¡¡¡¡¡¡¡¡¡¡¡¡"; SetColor(9, 15); cout << "¡à" << endl;	// 10
		cout << "¡à¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡"; SetColor(0, 15); cout << "¡á¡á¡¡¡¡¡¡¡¡¡¡¡¡¡¡"; SetColor(9, 15); cout << "¡à" << endl;	// 11
		cout << "¡á¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡"; SetColor(0, 15); cout << "¡¡¡á¡¡¡¡¡¡¡¡¡¡¡¡¡¡"; SetColor(9, 15); cout << "¡á" << endl;	// 12
		cout << "¡á¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡"; SetColor(0, 15); cout << "¡¡¡¡¡á¡á¡á¡¡¡¡¡á¡¡"; SetColor(9, 15); cout << "¡á" << endl;	// 13
		cout << "¡á¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡"; SetColor(0, 15); cout << "¡¡¡¡¡¡¡¡¡¡¡á¡á¡¡¡¡"; SetColor(9, 15); cout << "¡á" << endl;	// 14
	}
	else if (_monsterName == "¸äµÅÁö")
	{
		SetColor(9, 15);

		cout << "¡à¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡"; SetColor(0, 15); cout << "¡á¡á¡á¡á¡á¡¡¡¡¡¡"; SetColor(9, 15); cout << "¡à" << endl;	// 9
		cout << "¡à¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡"; SetColor(0, 15); cout << "¡á¡á¡á¡á¡á¡á¡¡¡¡"; SetColor(9, 15); cout << "¡à" << endl;	// 10
		cout << "¡à¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡"; SetColor(0, 15); cout << "¡¡¡á¡á¡á¡á¡á¡¡¡¡"; SetColor(9, 15); cout << "¡à" << endl;	// 11
		cout << "¡á¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡"; SetColor(0, 15); cout << "¡á¡¡¡á¡á¡á¡á¡¡¡¡"; SetColor(9, 15); cout << "¡á" << endl;	// 12
		cout << "¡á¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡"; SetColor(0, 15); cout << "¡¡¡¡¡¡¡á¡á¡¡¡¡¡¡"; SetColor(9, 15); cout << "¡á" << endl;	// 13
		cout << "¡á¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡"; SetColor(0, 15); cout << "¡¡¡¡¡á¡¡¡¡¡¡¡¡¡¡"; SetColor(9, 15); cout << "¡á" << endl;	// 14
	}
	else if (_monsterName == "°¨¿°ÀÚ")
	{
		SetColor(9, 15);

		cout << "¡à¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡"; SetColor(9, 15); cout << "¡à" << endl;	// 9
		cout << "¡à¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡"; SetColor(0, 15); cout << "¡¡¡¡¡¡¡á¡á¡¡¡¡¡¡¡¡"; SetColor(9, 15); cout << "¡à" << endl;	// 10
		cout << "¡à¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡"; SetColor(0, 15); cout << "¡¡¡¡¡¡¡á¡á¡¡¡¡¡¡¡¡"; SetColor(9, 15); cout << "¡à" << endl;	// 11
		cout << "¡á¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡"; SetColor(0, 15); cout << "¡¡¡á¡á¡á¡á¡á¡¡¡¡¡¡"; SetColor(9, 15); cout << "¡á" << endl;	// 12
		cout << "¡á¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡"; SetColor(0, 15); cout << "¡á¡¡¡á¡á¡¡¡á¡¡¡¡¡¡"; SetColor(9, 15); cout << "¡á" << endl;	// 13
		cout << "¡á¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡"; SetColor(0, 15); cout << "¡¡¡á¡¡¡¡¡á¡¡¡¡¡¡¡¡"; SetColor(9, 15); cout << "¡á" << endl;	// 14
	}
	else if (_monsterName == "È¯¡¡ÀÚ")
	{
		SetColor(9, 15);

		cout << "¡à¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡"; SetColor(0, 15); cout << "¡¡¡¡¡¡¡¡¡á¡¡¡¡¡¡¡¡"; SetColor(9, 15); cout << "¡à" << endl;	// 9
		cout << "¡à¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡"; SetColor(0, 15); cout << "¡¡¡¡¡¡¡á¡á¡á¡¡¡¡¡¡"; SetColor(9, 15); cout << "¡à" << endl;	// 10
		cout << "¡à¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡"; SetColor(0, 15); cout << "¡¡¡¡¡¡¡á¡á¡¡¡¡¡¡¡¡"; SetColor(9, 15); cout << "¡à" << endl;	// 11
		cout << "¡á¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡"; SetColor(0, 15); cout << "¡á¡á¡á¡á¡á¡á¡á¡¡¡¡"; SetColor(9, 15); cout << "¡á" << endl;	// 12
		cout << "¡á¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡"; SetColor(0, 15); cout << "¡¡¡¡¡á¡á¡¡¡¡¡¡¡¡¡¡"; SetColor(9, 15); cout << "¡á" << endl;	// 13
		cout << "¡á¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡"; SetColor(0, 15); cout << "¡¡¡á¡¡¡á¡¡¡¡¡¡¡¡¡¡"; SetColor(9, 15); cout << "¡á" << endl;	// 14
	}
}
void monsterBase::MonsterDefeat2()
{
	SetColor(9, 15);

	cout << "¡à¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡à" << endl;	// 9
	cout << "¡à¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡à" << endl;	// 10
	cout << "¡à¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡à" << endl;	// 11
	cout << "¡á¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡á" << endl;	// 12
	cout << "¡á¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡á" << endl;	// 13
	cout << "¡á¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡á" << endl;	// 14
}
void monsterBase::MonsterGetDamaged(int dmg)
{
	_monsterHp = _monsterHp - dmg;
}

void monsterBase::SetColor(int color, int bgcolor)
{
	bgcolor &= 0xf;
	color &= 0xf;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color | (bgcolor << 4));
}