#pragma once
#include "stdafx.h"
#include <iostream>
#include <time.h>
#include <windows.h>
#include <conio.h>
#include <chrono>
#include <future>
#include <string>
#include <vector>
#include <stdio.h>
#include <MMsystem.h>
#include "monkey.h"
#include "bat.h"
#include "snake.h"
#include "human1.h"
#include "human2.h"
#include "wildboar.h"
#pragma comment(lib,"Winmm.lib")

#include "herb.h"
#include "potion.h"

using namespace std;

class mainGame
{
private:
	enum ASCII
	{
		UP = 72,
		DOWN = 80,
		LEFT = 75,
		RIGHT = 77,
		ENTER = 13,
		SPACE = 32,
		ESC = 27
	};
	enum effectsounds
	{
		Ebirds = 1,
		Ewaterfall,
		Econversation,
		Edooropen,
		Eenvelope,
		EtempleEnter,
		Esleep,
		Estatuson,
		Estatusoff,
		Edog,
		Evictory,
		Emonkey,
		Ebat,
		Esnake,
		Ewildboar,
		Eskill1,
		Eskill2,
		Eskill3,
		Eskill4,
		Ebattleenter,
		Erun,
		Emove,
		Ecrazy,
		Ecancle,
		Echicken,
		Escream,
		Ehuman1,
		Ehuman2,
		Eblade,
		Eerror,
		Eheal
	};

	char _key = '0';
	int _start = 0;
	int _homecheck = 0;
	int _iahcheck = 0;
	int _upgradecheck = 0;
	int _tempPlace = 0; // temple enter place
	int _statuscheck = 0;
	int _drugtype = 0; // 1. herb 2. potion
	int _sleepcheck = 0;
	int _templecheck = 0;
	int _seocheck = 0;
	int seo = 0;
	int _khancheck = 0;
	int khan = 0;
	int _fieldcheck = 0;
	int _farmcheck = 0;
	int _seed1 = 0; // complete check number
	int _seedcheck = 0;
	int _safe = 0;
	int _worldcheck = 0;
	int _village1check = 0;
	int _village2check = 0;
	int _storecheck = 0;
	int _doggy = 0;
	int _inncheck = 0;
	bool b_villageEvent = false;
	bool b_houseEvent = false;
	bool b_housecheck = false;
	///////////////////////////////////////////// mainSwitch
	bool b_game = false;
	bool b_main = false;
	///////////////////////////////////////////// autoscreen
	bool b_iahScreen = false;
	bool b_seoScreen = false;
	bool b_khanScreen = false;
	///////////////////////////////////////////// mainMusic
	bool b_startMusic = false;
	bool b_iahMusic = false;
	bool b_homeMusic = false;
	bool b_templeMusic = false;
	bool b_fieldMusic = false;
	bool b_battleMusic = false;
	bool b_worldmapMusic = false;
	bool b_villageMusic = false;
	bool b_villagebattleMusic = false;
	///////////////////////////////////////////// effectSound
	int _effect = 0;
	///////////////////////////////////////////// seed switch
	bool b_seed1 = false;
	///////////////////////////////////////////// character
	string _characterJob = "";
	string _character1stSkill = "";
	string _character2ndSkill = "";
	int _characterMaxHp = 0;
	int _characterHp = 0;
	int _characterMaxMp = 0;
	int _characterMp = 0;
	int _characterMaxExp = 0;
	int _characterExp = 0;
	int _characterMoney = 0;
	int _1stSkillDmg = 0;
	int _2ndSkillDmg = 0;
	int _2ndSkillNeedMp = 0;
	///////////////////////////////////////////// character item
	herb* hb = new herb;
	potion* po = new potion;
	int _characterSeed = 0;
	///////////////////////////////////////////// battle switch
	int _skillcheck = 0;
	int _monster1statecheck = 0;
	int _monster2statecheck = 0;
	int _charactercheck = 0;
	int _battlecheck = 0;
	int _skillTemp = 0;
	
	monkey* _monkey1;
	monkey* _monkey2;
	bat* _bat1;
	bat* _bat2;
	snake* _snake1;
	snake* _snake2;
	wildboar* _wildboar1;
	wildboar* _wildboar2;
	human1* _human1;
	human2* _human2;

	

public:
	mainGame();
	~mainGame();

	void mainGame::Initialization();
	void mainGame::Game();
	void mainGame::SetColor(int color, int bgcolor);
	void mainGame::gotoxy(short x, short y);
	void mainGame::BootScreen();
	void mainGame::BootScreen1();
	void mainGame::BootScreen2();
	void mainGame::AutoScreen();
	void mainGame::StartScreen();
	void mainGame::HomeTempleScreen();
	void mainGame::HomeSleepScreen();
	void mainGame::HomeFieldScreen();
	void mainGame::HomeFieldScreen2();
	void mainGame::HomeEmptyScreen();
	void mainGame::HomeEmptyScreen2();
	void mainGame::Music();
	void mainGame::EffectSound();
	void mainGame::StartChoice();
	bool mainGame::GetGame();
	bool mainGame::GetStart();
	void mainGame::StartEvent();
	void mainGame::StartEvent1();
	void mainGame::StartEvent2();
	void mainGame::HomeEventError1();
	void mainGame::HomeEventError2();
	void mainGame::HomeEvent();
	void mainGame::HomeEventScreen();
	void mainGame::HomeEventChoice();
	void mainGame::IahEvent();
	void mainGame::IahChoice();
	void mainGame::IahScreen();
	void mainGame::IahScreen1();
	void mainGame::IahJobCheck();
	void mainGame::Home();
	void mainGame::HomeChoice();
	void mainGame::SleepChoiceScreen();
	void mainGame::HomeSleepChoice();
	void mainGame::UpgradeChoiceScreen();
	void mainGame::HomeUpgradeChoice();
	void mainGame::SleepEvent();
	void mainGame::Conversation();
	void mainGame::Move();
	void mainGame::Move2();
	void mainGame::Status();
	void mainGame::StatusScreen();
	void mainGame::StatusChoice();
	void mainGame::StatusScreen1();
	void mainGame::StatusScreen2();
	void mainGame::StatusScreen3();
	void mainGame::StatusScreen4();
	void mainGame::TempleEvent();
	void mainGame::TempleScreen();
	void mainGame::TempleChoice();
	void mainGame::SeoScreen();
	void mainGame::Seo2ndScreen();
	void mainGame::Seo3rdScreen();
	void mainGame::SeoChoice();
	void mainGame::KhanScreen();
	void mainGame::Khan2ndScreen();
	void mainGame::Khan3rdScreen();
	void mainGame::KhanChoice();
	void mainGame::FieldEventScreen();
	void mainGame::FieldScreen();
	void mainGame::FieldChoice();
	void mainGame::FarmScreen();
	void mainGame::FarmChoice();
	void mainGame::SeedScreen();
	void mainGame::SeedChoice();
	void mainGame::Seed1();
	void mainGame::CharacterScreen();
	void mainGame::FieldBattle();
	void mainGame::FieldBattleEnter();
	void mainGame::FieldBattleInit();
	void mainGame::BattleInitialization(monsterBase* _mob1);
	void mainGame::SkillScreen(monsterBase* _mob1, monsterBase* _mob2);
	void mainGame::BattleScreen(monsterBase* _mob1, monsterBase* _mob2);
	void mainGame::Monster1Screen(monsterBase* _mob1);
	void mainGame::Monster2Screen(monsterBase* _mob2);
	void mainGame::BattleChoiceScreen(monsterBase* _mob1, monsterBase* _mob2);
	void mainGame::BattleChoice(monsterBase* _mob1, monsterBase* _mob2);
	void mainGame::Monster1Blink(monsterBase* _mob1);
	void mainGame::Monster2Blink(monsterBase* _mob2);
	void mainGame::MonsterAttack(monsterBase* _mob1, monsterBase* _mob2);
	void mainGame::GameOver();
	void mainGame::GameOverScreen();
	void mainGame::WorldMapScreen();
	void mainGame::WorldMapChoice();
	void mainGame::FieldWorldMapEnterScreen();
	void mainGame::Village1Screen();
	void mainGame::Village1Choice();
	void mainGame::Village2Screen();
	void mainGame::Village2Choice();
	void mainGame::StoreTopScreen();
	void mainGame::StoreChoiceScreen();
	void mainGame::StoreChoice();
	void mainGame::TombEvent();
	void mainGame::DogEvent();
	void mainGame::InnChoiceScreen();
	void mainGame::InnChoice();
	void mainGame::VillageUpgradeChoice();
	void mainGame::VillageEvent();
	void mainGame::HouseEvent();
	void mainGame::HouseEventScreen();
	void mainGame::HouseEventChoice();
	void mainGame::HouseEvent2();
	void mainGame::HouseScreen();
	void mainGame::VillageBattle1Screen();
	void mainGame::VillageBattle2Screen();
	void mainGame::VillageBattle3Screen();
	void mainGame::VillageBattle4Screen();
	void mainGame::VillageBattle1Init();
	void mainGame::HouseEvent3();
	void mainGame::VillageBattle5Screen();
	void mainGame::VillageBattle6Screen();
	void mainGame::VillageBattle7Screen();
	void mainGame::VillageBattle2Init();
};

