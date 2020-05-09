#pragma once
#include <time.h>
#include <string>
#include <iostream>
#include <Windows.h>

using namespace std;

class monsterBase
{
private:
	string _monsterName = "";
	int _monsterMaxHp = 0;
	int _monsterHp = 0;
	int _monsterAtk = 0;
	int _monsterExp = 0;
	int _monsterMoney = 0;
	int _monsterSeed = 0;

public:
	monsterBase();
	~monsterBase();

	string GetMonsterName();
	int GetMonsterMaxHp();
	int GetMonsterHp();
	int GetMonsterAtk();
	int GetMonsterExp();
	int GetMonsterMoney();
	int GetMonsterSeed();

	void SetMonsterName(string name);
	void SetMonsterMaxHp(int maxhp);
	void SetMonsterHp(int hp);
	void SetMonsterAtk(int atk);
	void SetMonsterExp(int exp);
	void SetMonsterMoney(int money);
	void SetMonsterSeed(int seed);

	void monsterBase::MonsterSkill();
	void monsterBase::MonsterNormal();
	void monsterBase::MonsterAtk();
	void monsterBase::MonsterGetDmg1();
	void monsterBase::MonsterGetDmg2();
	void monsterBase::MonsterGetDmg3();
	void monsterBase::MonsterGetDmg4();
	void monsterBase::MonsterGetDmg5();
	void monsterBase::MonsterDefeat1();
	void monsterBase::MonsterDefeat2();

	void monsterBase::MonsterGetDamaged(int dmg);

	void monsterBase::SetColor(int color, int bgcolor);

};

