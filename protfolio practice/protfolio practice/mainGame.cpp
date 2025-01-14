#include "stdafx.h"
#include "mainGame.h"

using namespace std;


mainGame::mainGame()
{
	Initialization();
	BootScreen();
	b_main = true;

	hb->SetHpUp(_characterMaxHp * 0.35);
	po->SetHpUp(_characterMaxHp * 0.47);
	hb->SetHowMany(5);
	po->SetHowMany(5);
	_characterJob = "평민";
	_1stSkillDmg = _characterMaxHp * 0.05;
	_2ndSkillDmg = _characterMaxMp * 0.75;
	_2ndSkillNeedMp = _characterMaxMp * 0.35;
}


mainGame::~mainGame()
{
}


//////////////////////////////////////////////////////////////////////////////////////////////////// Game
void mainGame::Game()
{
	StartChoice();
	b_main = false;
	if (_start == 0)
	{
		b_main = false;
		b_game = false;
		return;
	}
	else
	{
		StartEvent();
		StartEvent1();
		StartEvent2();
		HomeEvent();
		IahEvent();
	}
}
//////////////////////////////////////////////////////////////////////////////////////////////////// Game
void mainGame::Initialization()
{
	system("TITLE 환세전설");
	SetColor(0, 15);

	srand(time(NULL));

	system("mode con: cols=75 lines=38");

	b_game = true;

	_characterMaxHp = 3500;
	_characterHp = _characterMaxHp;
	_characterMaxMp = 1250;
	_characterMp = _characterMaxMp;
	_characterMaxExp = 50000;
	_characterExp = 0; //
	_characterMoney = 200000; //
}
void mainGame::SetColor(int color, int bgcolor)
{
	bgcolor &= 0xf;
	color &= 0xf;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color | (bgcolor << 4));
}
void mainGame::gotoxy(short x, short y)
{
	HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD position = { x, y };

	SetConsoleCursorPosition(hStdout, position);
}
/////////////////////////////////////////////
void mainGame::BootScreen()
{
	SetColor(0, 0);
	BootScreen2();
	Sleep(500);

	SetColor(0, 15);
	BootScreen2();
	Sleep(1500);

	SetColor(3, 7);
	BootScreen2();
	Sleep(1000);

	SetColor(3, 7);
	BootScreen1();
	Sleep(1100);

	SetColor(3, 8);
	BootScreen1();
	Sleep(1200);

	SetColor(9, 8);
	BootScreen1();

	while (true)
	{
		_key = '0';
		_key = _getch();

		if (_key == (char)ENTER || _key == (char)SPACE)
		{
			_key = '0';

			SetColor(3, 8);
			BootScreen1();
			Sleep(1300);

			SetColor(3, 7);
			BootScreen1();
			Sleep(1200);

			SetColor(3, 7);
			BootScreen2();
			Sleep(1100);

			SetColor(0, 15);
			BootScreen2();
			Sleep(950);

			SetColor(0, 0);
			BootScreen2();
			Sleep(1500);

			break;
		}
	}
}
void mainGame::BootScreen1()
{
	gotoxy(0, 0);


	cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　" << endl;	// 37
	cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　" << endl;	// 1
	cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　" << endl;	// 2
	cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　" << endl;	// 3
	cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　" << endl;	// 4
	cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　" << endl;	// 5
	cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　" << endl;	// 6
	cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　" << endl;	// 7
	cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　" << endl;	// 8
	cout << "　　■　　　■　■　■■■　■■■　■■■　　■■■　■■■　■■■　　　" << endl;	// 9
	cout << "　　■　　　■　■　■　　　■　■　■　■　　■　　　■　　　■　■　　　" << endl;	// 10
	cout << "　　■■■　■　■　■■■　■■■　■　■　　■■■　■■■　■■■　　　" << endl;	// 11
	cout << "　　■　■　■　■　　　■　■　■　■　■　　　　■　■　■　■　■　　　" << endl;	// 12
	cout << "　　■■■　■■■　■■■　■　■　■　■　　■■■　■■■　■　■　　　" << endl;	// 13
	cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　" << endl;	// 14
	cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　" << endl;	// 15
	cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　" << endl;	// 16
	cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　" << endl;	// 17
	cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　" << endl;	// 36
	cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　" << endl;	// 18
	cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　" << endl;	// 19
	cout << "　　　　　　　　　　　　　　　　　　　■　　■　■　■　■　　■　　■　　" << endl;	// 20
	cout << "　　　　　　　　　　　　　　　　　　■■■　■　■■■■■　■■■　■　　" << endl;	// 21
	cout << "　　　　　　　　　　　　　　　　　　　■　　■　■　■　■　　■　　■　　" << endl;	// 22
	cout << "　　　　　　　　　　　　　　　　　　■　■　■　■■■■■　■　■　■■　" << endl;	// 23
	cout << "　　　　　　　　　　　　　　　　　　　■　　■　　　　■　　　　　　■　　" << endl;	// 24
	cout << "　　　　　　　　　　　　　　　　　　■■■■■　　　■　■　　　■　　　　" << endl;	// 25
	cout << "　　　　　　　　　　　　　　　　　　　　　　■　　　　■　　　　■■■　　" << endl;	// 26
	cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　" << endl;	// 27
	cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　" << endl;	// 28
	cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　" << endl;	// 29
	cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　" << endl;	// 30
	cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　" << endl;	// 31
	cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　" << endl;	// 32
	cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　" << endl;	// 33
	cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　" << endl;	// 34
	cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　" << endl;	// 35



}
void mainGame::BootScreen2()
{
	gotoxy(0, 0);

	cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　" << endl;	// 1
	cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　" << endl;	// 2
	cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　" << endl;	// 3
	cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　" << endl;	// 4
	cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　" << endl;	// 5
	cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　" << endl;	// 6
	cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　" << endl;	// 7
	cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　" << endl;	// 8
	cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　" << endl;	// 9
	cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　" << endl;	// 10
	cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　" << endl;	// 11
	cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　" << endl;	// 12
	cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　" << endl;	// 13
	cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　" << endl;	// 14
	cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　" << endl;	// 15
	cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　" << endl;	// 16
	cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　" << endl;	// 17
	cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　" << endl;	// 18
	cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　" << endl;	// 19
	cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　" << endl;	// 20
	cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　" << endl;	// 21
	cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　" << endl;	// 22
	cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　" << endl;	// 23
	cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　" << endl;	// 24
	cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　" << endl;	// 25
	cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　" << endl;	// 26
	cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　" << endl;	// 27
	cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　" << endl;	// 28
	cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　" << endl;	// 29
	cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　" << endl;	// 30
	cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　" << endl;	// 31
	cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　" << endl;	// 32
	cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　" << endl;	// 33
	cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　" << endl;	// 34
	cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　" << endl;	// 35
	cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　" << endl;	// 36
	cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　" << endl;	// 37
}
/////////////////////////////////////////////
void mainGame::AutoScreen()
{
	while (b_game == true)
	{
		while (b_main == true)
		{
			StartScreen();
		}
		while (b_iahScreen == true)
		{
			IahScreen();
		}
		while (b_seoScreen == true)
		{
			SeoScreen();
		}
		while (b_khanScreen == true)
		{
			KhanScreen();
		}
	}
}
void mainGame::Music()
{
	while (b_game == true)
	{
		while (b_main == true)
		{
			auto start = chrono::high_resolution_clock::now();
			PlaySound(TEXT("main.wav"), NULL, SND_ASYNC);

			for (int i = 0; i < 30; i++)
			{
				if (b_main == false)
				{
					PlaySound(NULL, NULL, 0);
					break;
				}
				this_thread::sleep_until(start + (i + 1)*std::chrono::milliseconds(985));
			}

		}
		while (b_startMusic == true)
		{
			auto start = chrono::high_resolution_clock::now();
			PlaySound(TEXT("start.wav"), NULL, SND_ASYNC);

			for (int i = 0; i < 325; i++)
			{
				if (b_startMusic == false)
				{
					PlaySound(NULL, NULL, 0);
					break;
				}
				this_thread::sleep_until(start + (i + 1)*std::chrono::milliseconds(1000));
			}
		}
		while (b_iahMusic == true)
		{
			auto start = chrono::high_resolution_clock::now();
			PlaySound(TEXT("iah.wav"), NULL, SND_ASYNC);

			for (int i = 0; i < 284; i++)
			{
				if (b_iahMusic == false)
				{
					PlaySound(NULL, NULL, 0);
					break;
				}
				this_thread::sleep_until(start + (i + 1)*std::chrono::milliseconds(1000));
			}
		}
		while (b_homeMusic == true)
		{
			auto start = chrono::high_resolution_clock::now();
			PlaySound(TEXT("home.wav"), NULL, SND_ASYNC);

			for (int i = 0; i < 216; i++)
			{
				if (b_homeMusic == false)
				{
					PlaySound(NULL, NULL, 0);
					break;
				}
				this_thread::sleep_until(start + (i + 1)*std::chrono::milliseconds(1000));
			}
		}
		while (b_templeMusic == true)
		{
			auto start = chrono::high_resolution_clock::now();
			PlaySound(TEXT("temple.wav"), NULL, SND_ASYNC);

			for (int i = 0; i < 156; i++)
			{
				if (b_templeMusic == false)
				{
					PlaySound(NULL, NULL, 0);
					break;
				}
				this_thread::sleep_until(start + (i + 1)*std::chrono::milliseconds(1000));
			}
		}
		while (b_fieldMusic == true)
		{
			auto start = chrono::high_resolution_clock::now();
			PlaySound(TEXT("field.wav"), NULL, SND_ASYNC);

			for (int i = 0; i < 334; i++)
			{
				if (b_fieldMusic == false)
				{
					PlaySound(NULL, NULL, 0);
					break;
				}
				this_thread::sleep_until(start + (i + 1)*std::chrono::milliseconds(1000));
			}
		}
		while (b_battleMusic == true)
		{
			auto start = chrono::high_resolution_clock::now();
			PlaySound(TEXT("battle.wav"), NULL, SND_ASYNC);

			for (int i = 0; i < 69; i++)
			{
				if (b_battleMusic == false)
				{
					PlaySound(NULL, NULL, 0);
					break;
				}
				this_thread::sleep_until(start + (i + 1)*std::chrono::milliseconds(1000));
			}
		}
		while (b_worldmapMusic == true)
		{
			auto start = chrono::high_resolution_clock::now();
			PlaySound(TEXT("worldmap.wav"), NULL, SND_ASYNC);

			for (int i = 0; i < 137; i++)
			{
				if (b_worldmapMusic == false)
				{
					PlaySound(NULL, NULL, 0);
					break;
				}
				this_thread::sleep_until(start + (i + 1)*std::chrono::milliseconds(1000));
			}
		}
		while (b_villageMusic == true)
		{
			auto start = chrono::high_resolution_clock::now();
			PlaySound(TEXT("village.wav"), NULL, SND_ASYNC);

			for (int i = 0; i < 180; i++)
			{
				if (b_villageMusic == false)
				{
					PlaySound(NULL, NULL, 0);
					break;
				}
				this_thread::sleep_until(start + (i + 1)*std::chrono::milliseconds(1000));
			}
		}
		while (b_villagebattleMusic == true)
		{
			auto start = chrono::high_resolution_clock::now();
			PlaySound(TEXT("villagebattle.wav"), NULL, SND_ASYNC);

			for (int i = 0; i < 302; i++)
			{
				if (b_villagebattleMusic == false)
				{
					PlaySound(NULL, NULL, 0);
					break;
				}
				this_thread::sleep_until(start + (i + 1)*std::chrono::milliseconds(1000));
			}
		}
	}
}
void mainGame::EffectSound()
{
	int monkey = 0;
	int skill2 = 0;
	int chicken = 0;

	while (b_game == true)
	{
		switch (_effect)
		{
		case 1:
		{
			mciSendString(TEXT("play birds.WAV"), NULL, 0, NULL);
			_effect = 0;
		}
		break;
		case 2:
		{
			mciSendString(TEXT("play waterfall.WAV"), NULL, 0, NULL);
			_effect = 0;
		}
		break;
		case 3:
		{
			mciSendString(TEXT("play conversation.WAV"), NULL, 0, NULL);
			_effect = 0;
		}
		break;
		case 4:
		{
			mciSendString(TEXT("play dooropen.WAV"), NULL, 0, NULL);
			_effect = 0;
		}
		break;
		case 5:
		{
			mciSendString(TEXT("play envelope.WAV"), NULL, 0, NULL);
			_effect = 0;
		}
		break;
		case 6:
		{
			mciSendString(TEXT("play templeEnter.WAV"), NULL, 0, NULL);
			_effect = 0;
		}
		break;
		case 7:
		{
			mciSendString(TEXT("play sleep.WAV"), NULL, 0, NULL);
			_effect = 0;
		}
		break;
		case 8:
		{
			mciSendString(TEXT("play statuson.WAV"), NULL, 0, NULL);
			_effect = 0;
		}
		break;
		case 9:
		{
			mciSendString(TEXT("play statusoff.WAV"), NULL, 0, NULL);
			_effect = 0;
		}
		break;
		case 10:
		{
			if (_doggy % 2 == 0)
			{
				mciSendString(TEXT("play doggy1.WAV"), NULL, 0, NULL);
			}
			else if (_doggy % 2 == 1)
			{
				mciSendString(TEXT("play doggy2.WAV"), NULL, 0, NULL);
			}
			_effect = 0;
		}
		break;
		case 11:
		{
			mciSendString(TEXT("play victory.WAV"), NULL, 0, NULL);
			_effect = 0;
		}
		break;
		case 12:
		{
			if (monkey == 0)
			{
				mciSendString(TEXT("play monkey1.WAV"), NULL, 0, NULL);
				monkey = 1;
			}
			else if (monkey == 1)
			{
				mciSendString(TEXT("play monkey2.WAV"), NULL, 0, NULL);
				monkey = 0;
			}
			_effect = 0;
		}
		break;
		case 13:
		{
			mciSendString(TEXT("play bat.WAV"), NULL, 0, NULL);
			_effect = 0;
		}
		break;
		case 14:
		{
			mciSendString(TEXT("play snake.WAV"), NULL, 0, NULL);
			_effect = 0;
		}
		break;
		case 15:
		{
			mciSendString(TEXT("play wildboar.WAV"), NULL, 0, NULL);
			_effect = 0;
		}
		break;
		case 16:
		{
			mciSendString(TEXT("play skill1.WAV"), NULL, 0, NULL);
			_effect = 0;
		}
		break;
		case 17:
		{
			if (skill2 == 0)
			{
				mciSendString(TEXT("play skill2-1.WAV"), NULL, 0, NULL);
				skill2 = 1;
			}
			else if (skill2 == 1)
			{
				mciSendString(TEXT("play skill2-2.WAV"), NULL, 0, NULL);
				skill2 = 0;
			}
			_effect = 0;
		}
		break;
		case 18:
		{
			mciSendString(TEXT("play skill3.WAV"), NULL, 0, NULL);
			_effect = 0;
		}
		break;
		case 19:
		{
			mciSendString(TEXT("play skill4.WAV"), NULL, 0, NULL);
			_effect = 0;
		}
		break;
		case 20:
		{
			mciSendString(TEXT("play battleenter.WAV"), NULL, 0, NULL);
			_effect = 0;
		}
		break;
		case 21:
		{
			mciSendString(TEXT("play run.WAV"), NULL, 0, NULL);
			_effect = 0;
		}
		break;
		case 22:
		{
			mciSendString(TEXT("play move.WAV"), NULL, 0, NULL);
			_effect = 0;
		}
		break;
		case 23:
		{
			mciSendString(TEXT("play crazy.WAV"), NULL, 0, NULL);
			_effect = 0;
		}
		break;
		case 24:
		{
			mciSendString(TEXT("play cancle.WAV"), NULL, 0, NULL);
			_effect = 0;
		}
		break;
		case 25:
		{
			auto start = chrono::high_resolution_clock::now();

			if (chicken == 0)
			{
				Sleep(1000);
				mciSendString(TEXT("play chicken1.WAV"), NULL, 0, NULL);
				chicken = 1;
			}
			else if (chicken == 1)
			{
				Sleep(1000);
				mciSendString(TEXT("play chicken2.WAV"), NULL, 0, NULL);
				chicken = 2;
			}
			else
			{
				Sleep(1000);
				mciSendString(TEXT("play chicken3.WAV"), NULL, 0, NULL);
				chicken = 0;
			}

			for (int i = 0; i < 4; i++)
			{
				if (_effect != Echicken)
				{
					break;
				}
				this_thread::sleep_until(start + (i + 1)*std::chrono::milliseconds(1000));
			}
		}
		break;
		case 26:
		{
			mciSendString(TEXT("play scream.WAV"), NULL, 0, NULL);
			_effect = 0;
		}
		break;
		case 27:
		{
			mciSendString(TEXT("play human1.WAV"), NULL, 0, NULL);
			_effect = 0;
		}
		break;
		case 28:
		{
			mciSendString(TEXT("play human2.WAV"), NULL, 0, NULL);
			_effect = 0;
		}
		break;
		case 29:
		{
			mciSendString(TEXT("play blade.WAV"), NULL, 0, NULL);
			_effect = 0;
		}
		break;
		case 30:
		{
			mciSendString(TEXT("play itemerror.WAV"), NULL, 0, NULL);
			_effect = 0;
		}
		break;
		case 31:
		{
			mciSendString(TEXT("play heal.WAV"), NULL, 0, NULL);
			_effect = 0;
		}
		break;
		}

	}
}

void mainGame::Seed1()
{
	while (b_game == true)
	{
		if (b_seed1 == true)
		{
			for (int i = 0; i < 180; ++i)
			{
				this_thread::sleep_for(std::chrono::seconds(1));
			}
			_seed1 = 1;
			b_seed1 = false;
		}
	}
}
/////////////////////////////////////////////
void mainGame::StartScreen()
{
	for (int i = 0; i >= 0; i++)
	{
		if (b_main == false)
		{
			break;
		}
		if (i % 2 == 0)
		{
			gotoxy(0, 0);

			SetColor(9, 15);

			cout << "■■□□□■■■□□□■■■□□□■■■□□□■■■□□□■■■□□□■■" << endl;
			cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
			cout << "□　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　□" << endl;
			cout << "□　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　□" << endl;
			cout << "□　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　□" << endl;
			cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
			cout << "■"; SetColor(0, 15); cout << "　　　　　■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　"; SetColor(9, 15); cout << "■" << endl;
			cout << "■"; SetColor(0, 15); cout << "　　　　■■■　　　　　　　　　　　　　　　　　　　　　　　　　　　　"; SetColor(9, 15); cout << "■" << endl;
			cout << "□"; SetColor(0, 15); cout << "　　　　　■　　■　　　　■　　■■　　　　　　　　　　　　　　　　　"; SetColor(9, 15); cout << "□" << endl;
			cout << "□"; SetColor(0, 15); cout << "　　　　■　■　■　　　　■　■■■　　　　　　　　　　　　　　　　　"; SetColor(9, 15); cout << "□" << endl;
			cout << "□"; SetColor(0, 15); cout << "　　　　　■　　■■　　■　■　■■　　　　　　　　　　　　　　　　　"; SetColor(9, 15); cout << "□" << endl;
			cout << "■"; SetColor(0, 15); cout << "　　　　■■■　■　　　　　　　■■　　　　　　　　　　　　　　　　　"; SetColor(9, 15); cout << "■" << endl;
			cout << "■"; SetColor(0, 15); cout << "　　　　　　■　　　　　　　　　　　　　　　　　■　　■　　■　　　　"; SetColor(9, 15); cout << "■" << endl;
			cout << "■"; SetColor(0, 15); cout << "　　　　　　■■■　　　　　　　　　　　■■■　■　　■　■■　　　　"; SetColor(9, 15); cout << "■" << endl;
			cout << "□"; SetColor(0, 15); cout << "　　　　　　　　　　　　　　　　　　　　　■　■■　■　■　■　　　　"; SetColor(9, 15); cout << "□" << endl;
			cout << "□"; SetColor(0, 15); cout << "　　　　　　　　　　　　　　　　　　　　■　■　■　　　■■■　　　　"; SetColor(9, 15); cout << "□" << endl;
			cout << "□"; SetColor(0, 15); cout << "　　　　　　　　　　　　　　　　　　　　　　　　■　　　　　■　　　　"; SetColor(9, 15); cout << "□" << endl;
			cout << "■"; SetColor(0, 15); cout << "　　　　　　　　　　　　　　　　　　　　　　■　　　　　■■■　　　　"; SetColor(9, 15); cout << "■" << endl;
			cout << "■"; SetColor(0, 15); cout << "　　　　　　　　　　　　　　　　　　　　　　■　　　　　■　　　　　　"; SetColor(9, 15); cout << "■" << endl;
			cout << "■"; SetColor(0, 15); cout << "　　　　　　　　　　　　　　　　　　　　　　■■■　　　■■■　　　　"; SetColor(9, 15); cout << "■" << endl;
			cout << "□　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　□" << endl;
			cout << "□　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　□" << endl;
			cout << "□　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　□" << endl;


			if (_start == 0)
			{
				cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　"; SetColor(9, 15); cout << "■" << endl;
				cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　"; SetColor(9, 15); cout << "■" << endl;
				cout << "■"; SetColor(0, 15); cout << "　　　　　　　　　　　　　　　　　　　　　　　　　"; SetColor(14, 15); cout << "■■■■■■■　　　"; SetColor(9, 15); cout << "■" << endl;
				cout << "□"; SetColor(0, 15); cout << "　　　　　　　　　　　　　　　　　　　　　　　　　"; SetColor(14, 15); cout << "■　　　　　"; SetColor(14, 15); cout << "■　　　"; SetColor(9, 15); cout << "□" << endl;
				cout << "□"; SetColor(0, 15); cout << "　　　　　　　　　　　　　　　　　　시　작　　　　"; SetColor(14, 15); cout << "■　"; SetColor(0, 15); cout << "나가기　"; SetColor(14, 15); cout << "■　　　"; SetColor(9, 15); cout << "□" << endl;
				cout << "□"; SetColor(0, 15); cout << "　　　　　　　　　　　　　　　　　　　　　　　　　"; SetColor(14, 15); cout << "■　　　　　"; SetColor(14, 15); cout << "■　　　"; SetColor(9, 15); cout << "□" << endl;
				cout << "■"; SetColor(0, 15); cout << "　　　　　　　　　　　　　　　　　　　　　　　　　"; SetColor(14, 15); cout << "■■■■■■■　　　"; SetColor(9, 15); cout << "■" << endl;
				cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　"; SetColor(9, 15); cout << "■" << endl;
				cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　"; SetColor(9, 15); cout << "■" << endl;
				cout << "□　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　"; SetColor(9, 15); cout << "□" << endl;
				cout << "□　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　"; SetColor(9, 15); cout << "□" << endl;
				cout << "□　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　"; SetColor(9, 15); cout << "□" << endl;
				cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　"; SetColor(9, 15); cout << "■" << endl;
				cout << "■■□□□■■■□□□■■■□□□■■■□□□■■■□□□■■■□□□■■" << endl;

			}
			else if (_start == 1)
			{

				cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　"; SetColor(9, 15); cout << "■" << endl;
				cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　"; SetColor(9, 15); cout << "■" << endl;
				cout << "■"; SetColor(0, 15); cout << "　　　　　　　　　　　　　　　　"; SetColor(14, 15); cout << "■■■■■■■　　　　　　　　　　　　"; SetColor(9, 15); cout << "■" << endl;
				cout << "□"; SetColor(0, 15); cout << "　　　　　　　　　　　　　　　　"; SetColor(14, 15); cout << "■　　　　　■　　　　　　　　　　　　"; SetColor(9, 15); cout << "□" << endl;
				cout << "□"; SetColor(0, 15); cout << "　　　　　　　　　　　　　　　　"; SetColor(14, 15); cout << "■"; SetColor(0, 15); cout << "　시　작　"; SetColor(14, 15); cout << "■　　　　"; SetColor(0, 15); cout << "나가기　　　　　"; SetColor(9, 15); cout << "□" << endl;
				cout << "□"; SetColor(0, 15); cout << "　　　　　　　　　　　　　　　　"; SetColor(14, 15); cout << "■　　　　　■　　　　　　　　　　　　"; SetColor(9, 15); cout << "□" << endl;
				cout << "■"; SetColor(0, 15); cout << "　　　　　　　　　　　　　　　　"; SetColor(14, 15); cout << "■■■■■■■　　　　　　　　　　　　"; SetColor(9, 15); cout << "■" << endl;
				cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　"; SetColor(9, 15); cout << "■" << endl;
				cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　"; SetColor(9, 15); cout << "■" << endl;
				cout << "□　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　"; SetColor(9, 15); cout << "□" << endl;
				cout << "□　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　"; SetColor(9, 15); cout << "□" << endl;
				cout << "□　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　"; SetColor(9, 15); cout << "□" << endl;
				cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
				cout << "■■□□□■■■□□□■■■□□□■■■□□□■■■□□□■■■□□□■■" << endl;

			}
		}
		else
		{
			gotoxy(0, 0);

			SetColor(12, 15);

			cout << "■■□□□■■■□□□■■■□□□■■■□□□■■■□□□■■■□□□■■" << endl;
			cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
			cout << "□　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　□" << endl;
			cout << "□　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　□" << endl;
			cout << "□　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　□" << endl;
			cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
			cout << "■"; SetColor(0, 15); cout << "　　　　　■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　"; SetColor(12, 15); cout << "■" << endl;
			cout << "■"; SetColor(0, 15); cout << "　　　　■■■　　　　　　　　　　　　　　　　　　　　　　　　　　　　"; SetColor(12, 15); cout << "■" << endl;
			cout << "□"; SetColor(0, 15); cout << "　　　　　■　　■　　　　■　　■■　　　　　　　　　　　　　　　　　"; SetColor(12, 15); cout << "□" << endl;
			cout << "□"; SetColor(0, 15); cout << "　　　　■　■　■　　　　■　■■■　　　　　　　　　　　　　　　　　"; SetColor(12, 15); cout << "□" << endl;
			cout << "□"; SetColor(0, 15); cout << "　　　　　■　　■■　　■　■　■■　　　　　　　　　　　　　　　　　"; SetColor(12, 15); cout << "□" << endl;
			cout << "■"; SetColor(0, 15); cout << "　　　　■■■　■　　　　　　　■■　　　　　　　　　　　　　　　　　"; SetColor(12, 15); cout << "■" << endl;
			cout << "■"; SetColor(0, 15); cout << "　　　　　　■　　　　　　　　　　　　　　　　　■　　■　　■　　　　"; SetColor(12, 15); cout << "■" << endl;
			cout << "■"; SetColor(0, 15); cout << "　　　　　　■■■　　　　　　　　　　　■■■　■　　■　■■　　　　"; SetColor(12, 15); cout << "■" << endl;
			cout << "□"; SetColor(0, 15); cout << "　　　　　　　　　　　　　　　　　　　　　■　■■　■　■　■　　　　"; SetColor(12, 15); cout << "□" << endl;
			cout << "□"; SetColor(0, 15); cout << "　　　　　　　　　　　　　　　　　　　　■　■　■　　　■■■　　　　"; SetColor(12, 15); cout << "□" << endl;
			cout << "□"; SetColor(0, 15); cout << "　　　　　　　　　　　　　　　　　　　　　　　　■　　　　　■　　　　"; SetColor(12, 15); cout << "□" << endl;
			cout << "■"; SetColor(0, 15); cout << "　　　　　　　　　　　　　　　　　　　　　　■　　　　　■■■　　　　"; SetColor(12, 15); cout << "■" << endl;
			cout << "■"; SetColor(0, 15); cout << "　　　　　　　　　　　　　　　　　　　　　　■　　　　　■　　　　　　"; SetColor(12, 15); cout << "■" << endl;
			cout << "■"; SetColor(0, 15); cout << "　　　　　　　　　　　　　　　　　　　　　　■■■　　　■■■　　　　"; SetColor(12, 15); cout << "■" << endl;
			cout << "□　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　□" << endl;
			cout << "□　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　□" << endl;
			cout << "□　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　□" << endl;

			if (_start == 0)
			{
				cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　"; SetColor(12, 15); cout << "■" << endl;
				cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　"; SetColor(12, 15); cout << "■" << endl;
				cout << "■"; SetColor(0, 15); cout << "　　　　　　　　　　　　　　　　　　　　　　　　　"; SetColor(14, 15); cout << "■■■■■■■　　　"; SetColor(12, 15); cout << "■" << endl;
				cout << "□"; SetColor(0, 15); cout << "　　　　　　　　　　　　　　　　　　　　　　　　　"; SetColor(14, 15); cout << "■　　　　　■　　　"; SetColor(12, 15); cout << "□" << endl;
				cout << "□"; SetColor(0, 15); cout << "　　　　　　　　　　　　　　　　　　시　작　　　　"; SetColor(14, 15); cout << "■　"; SetColor(0, 15); cout << "나가기　"; SetColor(14, 15); cout << "■　　　"; SetColor(12, 15); cout << "□" << endl;
				cout << "□"; SetColor(0, 15); cout << "　　　　　　　　　　　　　　　　　　　　　　　　　"; SetColor(14, 15); cout << "■　　　　　■　　　"; SetColor(12, 15); cout << "□" << endl;
				cout << "■"; SetColor(0, 15); cout << "　　　　　　　　　　　　　　　　　　　　　　　　　"; SetColor(14, 15); cout << "■■■■■■■　　　"; SetColor(12, 15); cout << "■" << endl;
				cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　"; SetColor(12, 15); cout << "■" << endl;
				cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　"; SetColor(12, 15); cout << "■" << endl;
				cout << "□　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　"; SetColor(12, 15); cout << "□" << endl;
				cout << "□　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　"; SetColor(12, 15); cout << "□" << endl;
				cout << "□　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　"; SetColor(12, 15); cout << "□" << endl;
				cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　"; SetColor(12, 15); cout << "■" << endl;
				cout << "■■□□□■■■□□□■■■□□□■■■□□□■■■□□□■■■□□□■■" << endl;
			}
			else if (_start == 1)
			{
				cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　"; SetColor(12, 15); cout << "■" << endl;
				cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　"; SetColor(12, 15); cout << "■" << endl;
				cout << "■"; SetColor(0, 15); cout << "　　　　　　　　　　　　　　　　"; SetColor(14, 15); cout << "■■■■■■■　　　　　　　　　　　　"; SetColor(12, 15); cout << "■" << endl;
				cout << "□"; SetColor(0, 15); cout << "　　　　　　　　　　　　　　　　"; SetColor(14, 15); cout << "■　　　　　■　　　　　　　　　　　　"; SetColor(12, 15); cout << "□" << endl;
				cout << "□"; SetColor(0, 15); cout << "　　　　　　　　　　　　　　　"; SetColor(14, 15); cout << "　■　"; SetColor(0, 15); cout << "시　작　"; SetColor(14, 15); cout << "■　　　　"; SetColor(0, 15); cout << "나가기　　　　　"; SetColor(12, 15); cout << "□" << endl;
				cout << "□"; SetColor(0, 15); cout << "　　　　　　　　　　　　　　　　"; SetColor(14, 15); cout << "■　　　　　■　　　　　　　　　　　　"; SetColor(12, 15); cout << "□" << endl;
				cout << "■"; SetColor(0, 15); cout << "　　　　　　　　　　　　　　　　"; SetColor(14, 15); cout << "■■■■■■■　　　　　　　　　　　　"; SetColor(12, 15); cout << "■" << endl;
				cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　"; SetColor(12, 15); cout << "■" << endl;
				cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　"; SetColor(12, 15); cout << "■" << endl;
				cout << "□　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　"; SetColor(12, 15); cout << "□" << endl;
				cout << "□　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　"; SetColor(12, 15); cout << "□" << endl;
				cout << "□　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　"; SetColor(12, 15); cout << "□" << endl;
				cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　"; SetColor(12, 15); cout << "■" << endl;
				cout << "■■□□□■■■□□□■■■□□□■■■□□□■■■□□□■■■□□□■■" << endl;
			}
		}
		std::this_thread::sleep_for(std::chrono::milliseconds(800));
	}

}
void mainGame::StartChoice()
{
	while (true)
	{
		_key = '0';
		_key = _getch();

		if (_key == (char)LEFT || _key == 'a' || _key == 'A')
		{
			_start = 1;
		}
		else if (_key == (char)RIGHT || _key == 'd' || _key == 'D')
		{
			_start = 0;
		}
		else if (_key == (char)ENTER || _key == (char)SPACE)
		{
			break;
		}
	}
}
/////////////////////////////////////////////
bool mainGame::GetGame()
{
	return b_game;
}
bool mainGame::GetStart()
{
	return b_main;
}
/////////////////////////////////////////////
void mainGame::Conversation()
{
	_effect = Econversation;

	while (true)
	{
		_key = '0';
		_key = _getch();

		if (_key == (char)ENTER || _key == (char)SPACE)
		{
			_key = '0';
			break;
		}
	}
}
/////////////////////////////////////////////
void mainGame::StartEvent()
{
	gotoxy(0, 0);
	SetColor(0, 0);
	BootScreen2();
	Sleep(600);
	SetColor(8, 8);
	BootScreen2();
	Sleep(600);
	SetColor(7, 7);
	BootScreen2();
	Sleep(600);
	SetColor(15, 15);
	BootScreen2();
	Sleep(600);

	gotoxy(0, 0);
	SetColor(8, 15);
	cout << "■■■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■■■■■\n"
		<< "■■■■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■■■■\n"
		<< "■■■■■　　　　　　　　　　　　　　　　　　　　　　　　　　　　■■■■\n"
		<< "■■■■■■■■■■■■■■■■■■■■■■■■■■■■　　　　　■■■■\n"
		<< "■■■■■■■■■■■■■■■■■■■■■■■■■■■■　　　　　■■■■\n"
		<< "■■■■■■■■■■■■■■■■■■■■■■■■■■■■　　　　　■■■■\n"
		<< "■■■■■■■■　　　　　　　　　　　　　　　　　　　　　　　　　■■■■\n"
		<< "■■■■■■　　　　　　　　　　　　　　　　　　　　　　　　　　■■■■■\n"
		<< "■■■■■　　　　　　　　　　　　　　　　　　　　　　　　　　　■■■■■\n"
		<< "■■■■　　　　　　　　　　　　　　　　　　　　　　　　　　■■■■■■■\n"
		<< "■■■　　　　　　■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n"
		<< "■■■　　　　　■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n"
		<< "■■■　　　　　■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n"
		<< "■■■　　　　　　　■■■■■■■■■■■■■■■■■■■■■■■■■■■\n"
		<< "■■■■　　　　　　　　■■■■■■■■■■■■■■■■■■■■■■■■■\n"
		<< "■■■■■　　　　　　　　　　■■■■■■■■■■■■■■■■■■■■■■\n"
		<< "■■■■■■■　　　　　　　　　　　　　■■■■■■■■■■■■■■■■■\n"
		<< "■■■■■■■■■　　　　　　　　　　　　　　　　　　　　　　　■■■■■\n"
		<< "■■■■■■■■■■■■　　　　　　　　　　　　　　　　　　　　　■■■■\n"
		<< "■■■■■■■■■■■■■■■　　　　　　　　　　　　　　　　　　　■■■\n"
		<< "■■■■■■■■■■■■■■■■■■■■　　　　　　　　　　　　　　　■■\n"
		<< "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■　　　　　■■\n"
		<< "■■■■■■■　　　　　　　　　　　　　　　　　　　　　　　　　　　　■■\n"
		<< "■■■■■■　　　　　　　　　　　　　　　　　　　　　　　　　　　　■■■\n"
		<< "■■■■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■■■■\n"
		<< "■■■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■■■■■\n"
		<< "■■■　　　　　　■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n"
		<< "■■■　　　　　■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n"
		<< "■■■　　　　　　■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n"
		<< "■■■■　　　　　　■■■■■■■■■■■■■■■■■■■■■■■■■■■\n"
		<< "■■■■■　　　　　　■■■■■■■■■■■■■■■■■■■■■■■■■■\n"
		<< "■■■■■■　　　　　　■■■■■■■■■■■■■■■■■■■■■■■■■\n"
		<< "■■■■■■■　　　　　　■■■■■■■■■■■■■■■■■■■■■■■■\n"
		<< "■■■■■■■■　　　　　　■■■■■■■■■■■■■■■■■■■■■■■\n"
		<< "■■■■■■■■■　　　　　　■■■■■■■■■■■■■■■■■■■■■■\n"
		<< "■■■■■■■■■■　　　　　　■■■■■■■■■■■■■■■■■■■■■\n"
		<< "■■■■■■■■■■■　　　　　　■■■■■■■■■■■■■■■■■■■■\n";

	Sleep(1000);

	gotoxy(0, 0);
	SetColor(0, 15);
	cout << "■■■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■■■■■\n"
		<< "■■■■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■■■■\n"
		<< "■■■■■　　　　　　　　　　　　　　　　　　　　　　　　　　　　■■■■\n"
		<< "■■■■■■■■■■■■■■■■■■■■■■■■■■■■　　　　　■■■■\n"
		<< "■■■■■■■■■■■■■■■■■■■■■■■■■■■■　　　　　■■■■\n"
		<< "■■■■■■■■■■■■■■■■■■■■■■■■■■■■　　　　　■■■■\n"
		<< "■■■■■■■■　　　　　　　　　　　　　　　　　　　　　　　　　■■■■\n"
		<< "■■■■■■　　　　　　　　　　　　　　　　　　　　　　　　　　■■■■■\n"
		<< "■■■■■　　　　　　　　　　　　　　　　　　　　　　　　　　　■■■■■\n"
		<< "■■■■　　　　　　　　　　　　　　　　　　　　　　　　　　■■■■■■■\n"
		<< "■■■　　　　　　■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n"
		<< "■■■　　　　　■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n"
		<< "■■■　　　　　■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n"
		<< "■■■　　　　　　　■■■■■■■■■■■■■■■■■■■■■■■■■■■\n"
		<< "■■■■　　　　　　　　■■■■■■■■■■■■■■■■■■■■■■■■■\n"
		<< "■■■■■　　　　　　　　　　■■■■■■■■■■■■■■■■■■■■■■\n"
		<< "■■■■■■■　　　　　　　　　　　　　■■■■■■■■■■■■■■■■■\n"
		<< "■■■■■■■■■　　　　　　　　　　　　　　　　　　　　　　　■■■■■\n"
		<< "■■■■■■■■■■■■　　　　　　　　　　　　　　　　　　　　　■■■■\n"
		<< "■■■■■■■■■■■■■■■　　　　　　　　　　　　　　　　　　　■■■\n"
		<< "■■■■■■■■■■■■■■■■■■■■　　　　　　　　　　　　　　　■■\n"
		<< "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■　　　　　■■\n"
		<< "■■■■■■■　　　　　　　　　　　　　　　　　　　　　　　　　　　　■■\n"
		<< "■■■■■■　　　　　　　　　　　　　　　　　　　　　　　　　　　　■■■\n"
		<< "■■■■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■■■■\n"
		<< "■■■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■■■■■\n"
		<< "■■■　　　　　　■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n"
		<< "■■■　　　　　■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n"
		<< "■■■　　　　　　■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n"
		<< "■■■■　　　　　　■■■■■■■■■■■■■■■■■■■■■■■■■■■\n"
		<< "■■■■■　　　　　　■■■■■■■■■■■■■■■■■■■■■■■■■■\n"
		<< "■■■■■■　　　　　　■■■■■■■■■■■■■■■■■■■■■■■■■\n"
		<< "■■■■■■■　　　　　　■■■■■■■■■■■■■■■■■■■■■■■■\n"
		<< "■■■■■■■■　　　　　　■■■■■■■■■■■■■■■■■■■■■■■\n"
		<< "■■■■■■■■■　　　　　　■■■■■■■■■■■■■■■■■■■■■■\n"
		<< "■■■■■■■■■■　　　　　　■■■■■■■■■■■■■■■■■■■■■\n"
		<< "■■■■■■■■■■■　　　　　　■■■■■■■■■■■■■■■■■■■■\n";

	Sleep(1000);
	_effect = Ebirds;
	Sleep(2300);
	b_startMusic = true;

	vector<string> startScreen;
	startScreen.push_back("■■■■■■■■■■■　　　　　　■■■■■■■■■■■■■■■■■■■■");
	startScreen.push_back("■■■■■■■■■■　　　　　　■■■■■■■■■■■■■■■■■■■■■");
	startScreen.push_back("■■■■■■■■■　　　　　　■■■■■■■■■■■■■■■■■■■■■■");
	startScreen.push_back("■■■■■■■■　　　　　　■■■■■■■■■■■■■■■■■■■■■■■");
	startScreen.push_back("■■■■■■■　　　　　　■■■■■■■■■■■■■■■■■■■■■■■■");
	startScreen.push_back("■■■■■■　　　　　　■■■■■■■■■■■■■■■■■■■■■■■■■");
	startScreen.push_back("■■■■■　　　　　　■■■■■■■■■■■■■■■■■■■■■■■■■■");
	startScreen.push_back("■■■■　　　　　　■■■■■■■■■■■■■■■■■■■■■■■■■■■");
	startScreen.push_back("■■■　　　　　　■■■■■■■■■■■■■■■■■■■■■■■■■■■■");
	startScreen.push_back("■■■　　　　　■■■■■■■■■■■■■■■■■■■■■■■■■■■■■");
	startScreen.push_back("■■■　　　　　　■■■■■■■■■■■■■■■■■■■■■■■■■■■■");
	startScreen.push_back("■■■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■■■■■");
	startScreen.push_back("■■■■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■■■■");
	startScreen.push_back("■■■■■■　　　　　　　　　　　　　　　　　　　　　　　　　　　　■■■");
	startScreen.push_back("■■■■■■■　　　　　　　　　　　　　　　　　　　　　　　　　　　　■■");
	startScreen.push_back("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■　　　　　■■");
	startScreen.push_back("■■■■■■■■■■■■■■■■■■■■　　　　　　　　　　　　　　　■■");
	startScreen.push_back("■■■■■■■■■■■■■■■　　　　　　　　　　　　　　　　　　　■■■");
	startScreen.push_back("■■■■■■■■■■■■　　　　　　　　　　　　　　　　　　　　　■■■■");
	startScreen.push_back("■■■■■■■■■　　　　　　　　　　　　　　　　　　　　　　　■■■■■");
	startScreen.push_back("■■■■■■■　　　　　　　　　　　　　■■■■■■■■■■■■■■■■■");
	startScreen.push_back("■■■■■　　　　　　　　　　■■■■■■■■■■■■■■■■■■■■■■");
	startScreen.push_back("■■■■　　　　　　　　■■■■■■■■■■■■■■■■■■■■■■■■■");
	startScreen.push_back("■■■　　　　　　　■■■■■■■■■■■■■■■■■■■■■■■■■■■");
	startScreen.push_back("■■■　　　　　■■■■■■■■■■■■■■■■■■■■■■■■■■■■■");
	startScreen.push_back("■■■　　　　　■■■■■■■■■■■■■■■■■■■■■■■■■■■■■");
	startScreen.push_back("■■■　　　　　　■■■■■■■■■■■■■■■■■■■■■■■■■■■■");
	startScreen.push_back("■■■■　　　　　　　　　　　　　　　　　　　　　　　　　　■■■■■■■");
	startScreen.push_back("■■■■■　　　　　　　　　　　　　　　　　　　　　　　　　　　■■■■■");
	startScreen.push_back("■■■■■■　　　　　　　　　　　　　　　　　　　　　　　　　　■■■■■");
	startScreen.push_back("■■■■■■■■　　　　　　　　　　　　　　　　　　　　　　　　　■■■■");
	startScreen.push_back("■■■■■■■■■■■■■■■■■■■■■■■■■■■■　　　　　■■■■");
	startScreen.push_back("■■■■■■■■■■■■■■■■■■■■■■■■■■■■　　　　　■■■■");
	startScreen.push_back("■■■■■■■■■■■■■■■■■■■■■■■■■■■■　　　　　■■■■");
	startScreen.push_back("■■■■■　　　　　　　　　　　　　　　　　　　　　　　　　　　　■■■■");
	startScreen.push_back("■■■■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■■■■");
	startScreen.push_back("■■■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■■■■■");
	startScreen.push_back("■■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■■■■■■");
	startScreen.push_back("■■　　　　　■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■");
	startScreen.push_back("■■　　　　■■■■■■■■■■■■■■■■■■　　　　　　　　■■■■■");
	startScreen.push_back("■■　　　　■■　　　　　　　　　　　　　　　　　　　　　　　　　　　■■");
	startScreen.push_back("■■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■");
	startScreen.push_back("■■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■");
	startScreen.push_back("■■　　　　　　　　　　　　　　　　　　　　　　　　■■■■■　　　　　■");
	startScreen.push_back("■■■　　　　　　　■■■■■■■■■■■■■■■■■■■■■■　　　　■");
	startScreen.push_back("■■■■　　　　　■■■■■■■■■■■■■■■■■■■■■■■　　　　■");
	startScreen.push_back("■■■■■■■■■■■■■■■■■■■■■■■■■■■　　　　　　　　　■");
	startScreen.push_back("■■■■■■■■■■■■■■■■■■■■■■■　　　　　　　　　　　　　■");
	startScreen.push_back("■■■■■■■■■■■■■■■■■■■　　　　　　　　　　　　　　　　　■");
	startScreen.push_back("■■■■■■■■　　　　　　　　　　　　　　　　　　　　　　　　　　　　■");
	startScreen.push_back("■■■■■■■　　　　　　　　　　　　　　　　　　　　　　　　　　　　■■");
	startScreen.push_back("■■■■■■　　　　　　　　　　　　　　　　　　　　　■■■■■■■■■■");

	Sleep(200);

	vector<string>::iterator iter;
	iter = startScreen.begin();


	for (iter; (iter + 36) != startScreen.end(); ++iter)
	{
		gotoxy(0, 0);

		cout << *(iter + 36) << "\n" << *(iter + 35) << "\n" << *(iter + 34)
			<< "\n" << *(iter + 33) << "\n" << *(iter + 32) << "\n" << *(iter + 31)
			<< "\n" << *(iter + 30) << "\n" << *(iter + 29) << "\n" << *(iter + 28)
			<< "\n" << *(iter + 27) << "\n" << *(iter + 26) << "\n" << *(iter + 25)
			<< "\n" << *(iter + 24) << "\n" << *(iter + 23) << "\n" << *(iter + 22)
			<< "\n" << *(iter + 21) << "\n" << *(iter + 20) << "\n" << *(iter + 19)
			<< "\n" << *(iter + 18) << "\n" << *(iter + 17) << "\n" << *(iter + 16)
			<< "\n" << *(iter + 15) << "\n" << *(iter + 14) << "\n" << *(iter + 13)
			<< "\n" << *(iter + 12) << "\n" << *(iter + 11) << "\n" << *(iter + 10)
			<< "\n" << *(iter + 9) << "\n" << *(iter + 8) << "\n" << *(iter + 7)
			<< "\n" << *(iter + 6) << "\n" << *(iter + 5) << "\n" << *(iter + 4)
			<< "\n" << *(iter + 3) << "\n" << *(iter + 2) << "\n" << *(iter + 1)
			<< "\n" << *iter << endl;

		if (iter == startScreen.begin() + 14)
		{
			_effect = Ebirds;
		}

		Sleep(800);
	}


	startScreen.clear();
	startScreen.push_back("■■■■■■■■■■■■■■■■■■■■　　　　　　　　　　　　　　　■■");
	startScreen.push_back("■■■■■■■■■■■■■■■　　　　　　　　　　　　　　　　　　　■■■");
	startScreen.push_back("■■■■■■■■■■■■　　　　　　　　　　　　　　　　　　　　　■■■■");
	startScreen.push_back("■■■■■■■■■　　　　　　　　　　　　　　　　　　　　　　　■■■■■");
	startScreen.push_back("■■■■■■■　　　　　　　　　　　　　■■■■■■■■■■■■■■■■■");
	startScreen.push_back("■■■■■　　　　　　　　　　■■■■■■■■■■■■■■■■■■■■■■");
	startScreen.push_back("■■■■　　　　　　　　■■■■■■■■■■■■■■■■■■■■■■■■■");
	startScreen.push_back("■■■　　　　　　　■■■■■■■■■■■■■■■■■■■■■■■■■■■");
	startScreen.push_back("■■■　　　　　■■■■■■■■■■■■■■■■■■■■■■■■■■■■■");
	startScreen.push_back("■■■　　　　　■■■■■■■■■■■■■■■■■■■■■■■■■■■■■");
	startScreen.push_back("■■■　　　　　　■■■■■■■■■■■■■■■■■■■■■■■■■■■■");
	startScreen.push_back("■■■■　　　　　　　　　　　　　　　　　　　　　　　　　　■■■■■■■");
	startScreen.push_back("■■■■■　　　　　　　　　　　　　　　　　　　　　　　　　　　■■■■■");
	startScreen.push_back("■■■■■■　　　　　　　　　　　　　　　　　　　　　　　　　　■■■■■");
	startScreen.push_back("■■■■■■■■　　　　　　　　　　　　　　　　　　　　　　　　　■■■■");
	startScreen.push_back("■■■■■■■■■■■■■■■■■■■■■■■■■■■■　　　　　■■■■");
	startScreen.push_back("■■■■■■■■■■■■■■■■■■■■■■■■■■■■　　　　　■■■■");
	startScreen.push_back("■■■■■■■■■■■■■■■■■■■■■■■■■■■■　　　　　■■■■");
	startScreen.push_back("■■■■■　　　　　　　　　　　　　　　　　　　　　　　　　　　　■■■■");
	startScreen.push_back("■■■■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■■■■");
	startScreen.push_back("■■■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■■■■■");
	startScreen.push_back("■■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■■■■■■");
	startScreen.push_back("■■　　　　　■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■");
	startScreen.push_back("■■　　　　■■■■■■■■■■■■■■■■■■　　　　　　　　■■■■■");
	startScreen.push_back("■■　　　　■■　　　　　　　　　　　　　　　　　　　　　　　　　　　■■");
	startScreen.push_back("■■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■");
	startScreen.push_back("■■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■");
	startScreen.push_back("■■　　　　　　　　　　　　　　　　　　　　　　　　■■■■■　　　　　■");
	startScreen.push_back("■■■　　　　　　　■■■■■■■■■■■■■■■■■■■■■■　　　　■");
	startScreen.push_back("■■■■　　　　　■■■■■■■■■■■■■■■■■■■■■■■　　　　■");
	startScreen.push_back("■■■■　　　　　■■■■■■■■■■■■■■■■■■■■■■■　　　　■");
	startScreen.push_back("■■■■■■■■■■■■■■■■■■■■■■■■■■■　　　　　　　　　■");
	startScreen.push_back("■■■■■■■■■■■■■■■■■■■■■■■　　　　　　　　　　　　　■");
	startScreen.push_back("■■■■■■■■■■■■■■■■■■■　　　　　　　　　　　　　　　　　■");
	startScreen.push_back("■■■■■■■■　　　　　　　　　　　　　　　　　　　　　　　　　　　　■");
	startScreen.push_back("■■■■■■■　　　　　　　　　　　　　　　　　　　　　　　　　　　　■■");
	startScreen.push_back("■■■■■■　　　　　　　　　　　　　　　　　　　　　■■■■■■■■■■");
	startScreen.push_back("■■■■■　　　　　　　　　　　　　　　　　■■■■■■□□□□□□□□□");
	startScreen.push_back("■■■■　　　　　　■■■■■■■■■■■■■□□□□□□□□□□□□□□");
	startScreen.push_back("■■■　　　　　　■■□□□□□□□□□□□□□□□□□□□□□□□□□□");
	startScreen.push_back("■■　　　　　　■■□□□□□□□□□□□□□□□□□□□□□□□□□□□");
	startScreen.push_back("■■　　　　　■■■□□□□□□□□□□□□□□□□□□□□□□□□□□□");
	startScreen.push_back("■■　　　　　■■■□□□□□□□□□□□□□□□□□□□□□□□□□□□");
	startScreen.push_back("■■　　　　　■■■□□□□□□□□□□□□□□□□□□□□□□□□□□□");
	startScreen.push_back("■■■　　　　　■■■■■■■■■■■■■■■■■■■■■■■□□□□■■");
	startScreen.push_back("■■■　　　　　　■■■■■■■■■■■■■■■■■■■■■■□□□□■■");
	startScreen.push_back("■■■■　　　　　　　■■■■■■■■■■■■■■■■■■■■□□□□■■");
	startScreen.push_back("■■■■　　　　　　　　　　　　　　　　　　　　　　　■■■■□□□□■■");
	startScreen.push_back("■■■■■　　　　　　　　　　　　　　　　　　　　　　　■■■□□□□■■");
	startScreen.push_back("■■■■■■■　　　　　　　　　　　　　　　　　　　　　　■■□□□□■■");
	startScreen.push_back("■■■■■■■■　　　　　　　　　　　　　　　　　　　　　■■□□□□■■");
	startScreen.push_back("■■■■■■■■■■■■■■■■■■■■■■■■　　　　　■■□□□□■■");
	startScreen.push_back("■■■■■　　　　　　　　　　　　　　　　　　　　　　　　■■□□□□■■");
	startScreen.push_back("■■■■　　　　　　　　　　　　　　　　　　　　　　　　　■■□□□□■■");
	startScreen.push_back("■■■　　　　　　　　　　　　　　　　　　　　　　　　　■■■□□□□■■");
	startScreen.push_back("■■　　　　　　　　　　　　　　　　　　　　　　　　　■■■■□□□□■■");
	startScreen.push_back("■　　　　　　■■■■■■■■■■■■■■■■■■■■■■■■□□□□■■");
	startScreen.push_back("■　　　　　■■■■■■■■■■■■■■■■■■■■■■■■■□□□□■■");
	startScreen.push_back("■　　　　　■■■■■■■■■■■■■■■■■■■■■■■■■□□□□■■");
	startScreen.push_back("■　　　　　■■■■■■■■■■■■■■■■■■■■■■■■■□□□□■■");
	startScreen.push_back("■　　　　　　■■■■■■■■■■■■■■■■■■■■■■■■□□□□■■");
	startScreen.push_back("■　　　　　　　　　　　　　　　　　　　　　　　■■■■■■■□□□□■■");
	startScreen.push_back("■■　　　　　　　　　　　　　　　　　　　　　　　■■■■■■□□□□■■");
	startScreen.push_back("■■■　　　　　　　　　　　　　　　　　　　　　　　■■■■■□□□□■■");
	startScreen.push_back("■■■■　　　　　　　　　　　　　　　　　　　　　　　■■■■□□□□■■");
	startScreen.push_back("■■■■■■■■■■■■■■■■■■■■■　　　　　　■■■■□□□□■■");
	startScreen.push_back("■■■■■■■■■■■■■■■■■■■■　　　　　　　■■■■□□□□■■");
	startScreen.push_back("■■■■■■■　　　　　　　　　　　　　　　　　　■■■■■□□□□□□□");
	startScreen.push_back("■■■■■■　　　　　　　　　　　　　　　　　　　■■■■□□□□□□□□");
	startScreen.push_back("■■■■■　　　　　　　　　　　　　　　　　　■■■■■■□□□□□□□□");
	startScreen.push_back("■■■■　　　　　　　■■■■■■■■■■■■■■■■■■□□□□□□□□");
	startScreen.push_back("■■■　　　　　　　■■■■■□■■■□■■■■■■■■■□□□□□□□□");
	startScreen.push_back("■■■　　　　　　■■■■□□□□□□□□■■■■■■■■■□□□□□□□");
	startScreen.push_back("■■■　　　　　　■■■■■□□□□□□□■■■■■■■■■■□□□□□□");
	startScreen.push_back("■■■　　　　　　■■■■■■□□□□□□■■■■■■■■■■□□□□□□");
	startScreen.push_back("■■■　　　　　　　■■■■■■■■■■■■■■■■■■■■■■■■■■■");
	startScreen.push_back("■■■　　　　　　　　　　　　　　　　　　　　　　　　　　■■■■■■■■");
	startScreen.push_back("■■■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■■■■");
	startScreen.push_back("■■■■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■■■");
	startScreen.push_back("■■■■■■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■■");
	startScreen.push_back("■■■■■■■■　　　　　　　　　　　　　　　　　　　　　　　　　　　■■");
	startScreen.push_back("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■　　　　　■■");
	startScreen.push_back("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■　　　　　　■■");
	startScreen.push_back("■■■■■■■■■■■■■■■■■■■■■■■■■■■■　　　　　　■■■");
	startScreen.push_back("■■■■■■■■■■■■■■■■■■■■■■■■■■■　　　　　　　■■■");
	startScreen.push_back("■■■■■■■■■■■■■■■■■■■■■■■■■■　　　　　　　■■■■");
	startScreen.push_back("■■■■■■　　　　　　　　　　　　　　　　　　　　　　　　　　■■■■■");
	startScreen.push_back("■■■■■　　　　　　　　　　　　　　　　　　　　　　　　　　■■■■■■");
	startScreen.push_back("■■■■　　　　　　　　　　　　　　　　　　　　　　　　　　■■■■■■■");
	startScreen.push_back("■■■■　　　　　　　　　　　　　　　　　　　　　　　　　■■■■■■■■");
	startScreen.push_back("■■■　　　　　　　■■■■■■■■■■■■■■■■■■■■■■■■■■■");
	startScreen.push_back("■■　　　　　　　■■■■■■■■■■■■■■■■■■■■■■■■■■■■");
	startScreen.push_back("■　　　　　　　■■■■■■■■■■■■■■■■■■■■■■■■■■■■■");
	startScreen.push_back("■　　　　　　　■■■■■■■■■■■■■■■■■■■■■■■■■■■■■");
	startScreen.push_back("■　　　　　　　　■■■■■■■■■■■■■■■■■■■■■■■■■■■■");
	startScreen.push_back("■■　　　　　　　　■■■■■■■■■■■■■■■■■■■■■■■■■■■");
	startScreen.push_back("■■■　　　　　　　　■■■■■■■■■■■■■■■■■■■■■■■■■■");
	startScreen.push_back("■■■■　　　　　　　　　　　　　　　　　　　　　　　　　■■■■■■■■");
	startScreen.push_back("■■■■■　　　　　　　　　　　　　　　　　　　　　　　　　■■■■■■■");
	startScreen.push_back("■■■■■■　　　　　　　　　　　　　　　　　　　　　　　　　■■■■■■");
	startScreen.push_back("■■■■■■■　　　　　　　　　　　　　　　　　　　　　　　　　■■■■■");
	startScreen.push_back("■■■■■■■■■■■■■■■■■■■■■■■■■■　　　　　　■■■■■");
	startScreen.push_back("■■■■■■　　　　　　　　　　　　　　　　　　　　　　　　　　■■■■■");
	startScreen.push_back("■■■■■■　　　　　　　　　　　　　　　　　　　　　　　　　■■■■■■");
	startScreen.push_back("■■■■■　　　　　　　　　　　　　　　　　　　　　　　　　■■■■■■■");
	startScreen.push_back("■■■■　　　　　　　　　　　　　　　　　　　　　　　　　■■■■■■■■");
	startScreen.push_back("■■■■　　　　　　　■■■■■■■■■■■■■■■■■■■■■■■■■■");
	startScreen.push_back("■■■■　　　　　　■■■■■■■■■■■■■■■■■■■■■■■■■■■");
	startScreen.push_back("■■■■　　　　　　　　　　　　　　　　　　　　　　　　　　　　■■■■■");
	startScreen.push_back("■■■■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■■■■");
	startScreen.push_back("■■■■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■■■■");
	startScreen.push_back("■■■■■　　　　　　　　　　　　　　　　　　　　　　　　　　　　■■■■");
	startScreen.push_back("■■■■■■■■■■■■■■■■■■■■■■■■■■■　　　　　　■■■■");
	startScreen.push_back("■■■■■■■■■■■■■■■■■■■■■■■■■■　　　　　　　■■■■");
	startScreen.push_back("　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■■■■■");
	startScreen.push_back("　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■■■■■■");
	startScreen.push_back("　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■■■■■■■");
	startScreen.push_back("　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■■■■■■■");
	startScreen.push_back("　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■■■■■■■■");
	startScreen.push_back("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■");
	startScreen.push_back("■■■■■■■■■■　■　■　■■■■■■■■■■■■■■■■■■■■■■");
	startScreen.push_back("■■■■■■■■■■　■■■　■■■■■■■■■■■■■■■■■■■■■■");
	startScreen.push_back("■■■■■■■■■■　　　　　■■■■■■■■■■■■■■■■■■■■■■");
	startScreen.push_back("■■■■■■■■■■　　　　　■■■■■■■■■■■■■■■■■■■■■■");
	startScreen.push_back("■■■■■■■■■■　　　　　■■■■■■■■■■■■■■■■■■■■■■");
	startScreen.push_back("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■");
	startScreen.push_back("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■");

	_effect = Ewaterfall;

	iter = startScreen.begin();
	for (iter; (iter + 36) != startScreen.end(); ++iter)
	{
		gotoxy(0, 0);

		cout << *(iter + 36) << "\n" << *(iter + 35) << "\n" << *(iter + 34)
			<< "\n" << *(iter + 33) << "\n" << *(iter + 32) << "\n" << *(iter + 31)
			<< "\n" << *(iter + 30) << "\n" << *(iter + 29) << "\n" << *(iter + 28)
			<< "\n" << *(iter + 27) << "\n" << *(iter + 26) << "\n" << *(iter + 25)
			<< "\n" << *(iter + 24) << "\n" << *(iter + 23) << "\n" << *(iter + 22)
			<< "\n" << *(iter + 21) << "\n" << *(iter + 20) << "\n" << *(iter + 19)
			<< "\n" << *(iter + 18) << "\n" << *(iter + 17) << "\n" << *(iter + 16)
			<< "\n" << *(iter + 15) << "\n" << *(iter + 14) << "\n" << *(iter + 13)
			<< "\n" << *(iter + 12) << "\n" << *(iter + 11) << "\n" << *(iter + 10)
			<< "\n" << *(iter + 9) << "\n" << *(iter + 8) << "\n" << *(iter + 7)
			<< "\n" << *(iter + 6) << "\n" << *(iter + 5) << "\n" << *(iter + 4)
			<< "\n" << *(iter + 3) << "\n" << *(iter + 2) << "\n" << *(iter + 1)
			<< "\n" << *iter << endl;

		Sleep(800);
	}





}
void mainGame::StartEvent1()
{
	gotoxy(0, 0);
	SetColor(0, 15);

	cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;
	cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;
	cout << "■■■■■■■■■■　　　　　■■■■■■■■■■■■■■■■■■■■■■" << endl;
	cout << "■■■■■■■■■■　　　　　■■■■■■■■■■■■■■■■■■■■■■" << endl;
	cout << "■■■■■■■■■■　　　　　■■■■■■■■■■■■■■■■■■■■■■" << endl;
	cout << "■■■■■■■■■■　■■■　■■■■■■■■■■■■■■■■■■■■■■" << endl;
	cout << "■■■■■■■■■■　■　■　■■■■■■■■■■■■■■■■■■■■■■" << endl;
	cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;
	cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■■■■■■■■" << endl;
	cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■■■■■■■" << endl;
	cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■■■■■■■" << endl;
	cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■■■■■■" << endl;
	cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■■■■■" << endl;
	cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■　　　　　　　■■■■" << endl;
	cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■　　　　　　■■■■" << endl;
	cout << "■■■■■　　　　　　　　　　　　　　　　　　　　　　　　　　　　■■■■" << endl;
	cout << "■■■■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■■■■" << endl;
	cout << "■■■■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■■■■" << endl;
	cout << "■■■■　　　　　　　　　　　　　　　　　　　　　　　　　　　　■■■■■" << endl;
	cout << "■■■■　　　　　　■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;
	cout << "■■■■　　　　　　　■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;
	cout << "■■■■　　　　　　　　　　　　　　　　　　　　　　　　　■■■■■■■■" << endl;
	cout << "■■■■■　　　　　　　　　　　　　　　　　　　　　　　　　■■■■■■■" << endl;
	cout << "■■■■■■　　　　　　　　　　　　　　　　　　　　　　　　　■■■■■■" << endl;
	cout << "■■■■■■　　　　　　　　　　　　　　　　　　　　　　　　　　■■■■■" << endl;
	cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■　　　　　　■■■■■" << endl;
	cout << "■■■■■■■　　　　　　　　　　　　　　　　　　　　　　　　　■■■■■" << endl;
	cout << "■■■■■■　　　　　　　　　　　　　　　　　　　　　　　　　■■■■■■" << endl;
	cout << "■■■■■　　　　　　　　　　　　　　　　　　　　　　　　　■■■■■■■" << endl;
	cout << "■■■■　　　　　　　　　　　　　　　　　　　　　　　　　■■■■■■■■" << endl;
	cout << "■■■　　　　　　　　■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;
	cout << "■■　　　　　　　　■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;
	cout << "■　　　　　　　　■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;
	cout << "■　　　　　　　■■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;
	cout << "■　　　　　　　■■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;
	cout << "■■　　　　　　　■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;
	cout << "■■■　　　　　　　■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;

	Sleep(2000);


	gotoxy(0, 0);
	SetColor(0, 15);

	cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;
	cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;
	cout << "■■■■■■■■■■　　　　　■■■■■■■■■■■■■■■■■■■■■■" << endl;
	cout << "■■■■■■■■■■　　　　　■■■■■■■■■■■■■■■■■■■■■■" << endl;
	cout << "■■■■■■■■■■　　　　　■■■■■■■■■■■■■■■■■■■■■■" << endl;
	cout << "■■■■■■■■■■　■■■　■■■■■■■■■■■■■■■■■■■■■■" << endl;
	cout << "■■■■■■■■■■　■　■　■■■■■■■■■■■■■■■■■■■■■■" << endl;
	cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;
	cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■■■■■■■■" << endl;
	cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■■■■■■■" << endl;
	cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■■■■■■■" << endl;
	cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■■■■■■" << endl;
	cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■■■■■" << endl;
	cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■　　　　　　　■■■■" << endl;
	cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■　　　　　　■■■■" << endl;
	cout << "■■■■■　　　　　　　　　　　　　　　　　　　　　　　　　　　　■■■■" << endl;
	cout << "■■■■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■■■■" << endl;
	cout << "■■■■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■■■■" << endl;
	cout << "■■■■　　　　　　　　　　　　　　　　　　　　　　　　　　　　■■■■■" << endl;
	cout << "■■■■　　　　　　■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;
	cout << "■■■■　　　　　　　■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;
	cout << "■■■■　　　　　　　　　　　　　　　　　　　　　　　　　■■■■■■■■" << endl;
	cout << "■■■■■　　　　　　　　　　　　　　　　　　　　　　　　　■■■■■■■" << endl;
	cout << "■■■■■■　　　　　　　　　　　　　　　　　　　　　　　　　■■■■■■" << endl;
	cout << "■■■■■■　　　　　　　　　　　　　　　　　　　　　　　　　　■■■■■" << endl;
	cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■　　　　　　■■■■■" << endl;
	cout << "■■■■■■■　　　　　　　　　　　　　　　　　　　　　　　　　■■■■■" << endl;
	cout << "■■■■■■　　　　　　　　　　　　　　　　　　　　　　　　　■■■■■■" << endl;
	cout << "■■■■■　　　　　　　　　　　　　　　　　　　　　　　　　■■■■■■■" << endl;
	cout << "■■■■　　　　　　　　　　　　　　　　　　　　　　　　　■■■■■■■■" << endl;
	cout << "■■■　　　　　　　　■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;
	cout << "■■　　　　　　　　■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;
	cout << "■　　　　　　　　■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;
	cout << "■　　　"; SetColor(12, 15); cout << "　■　"; SetColor(0, 15); cout << "　■■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;
	cout << "■　　　"; SetColor(12, 15); cout << "■■■"; SetColor(0, 15); cout << "　■■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;
	cout << "■■　　"; SetColor(12, 15); cout << "　■　"; SetColor(0, 15); cout << "　　■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;
	cout << "■■■　"; SetColor(12, 15); cout << "■　■"; SetColor(0, 15); cout << "　　　■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;

	Sleep(1200);

	gotoxy(0, 0);
	SetColor(0, 15);

	cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;
	cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;
	cout << "■■■■■■■■■■　　　　　■■■■■■■■■■■■■■■■■■■■■■" << endl;
	cout << "■■■■■■■■■■　　　　　■■■■■■■■■■■■■■■■■■■■■■" << endl;
	cout << "■■■■■■■■■■　　　　　■■■■■■■■■■■■■■■■■■■■■■" << endl;
	cout << "■■■■■■■■■■　■■■　■■■■■■■■■■■■■■■■■■■■■■" << endl;
	cout << "■■■■■■■■■■　■　■　■■■■■■■■■■■■■■■■■■■■■■" << endl;
	cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;
	cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■■■■■■■■" << endl;
	cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■■■■■■■" << endl;
	cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■■■■■■■" << endl;
	cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■■■■■■" << endl;
	cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■■■■■" << endl;
	cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■　　　　　　　■■■■" << endl;
	cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■　　　　　　■■■■" << endl;
	cout << "■■■■■　　　　　　　　　　　　　　　　　　　　　　　　　　　　■■■■" << endl;
	cout << "■■■■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■■■■" << endl;
	cout << "■■■■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■■■■" << endl;
	cout << "■■■■　　　　　　　　　　　　　　　　　　　　　　　　　　　　■■■■■" << endl;
	cout << "■■■■　　　　　　■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;
	cout << "■■■■　　　　　　　■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;
	cout << "■■■■　　　　　　　　　　　　　　　　　　　　　　　　　■■■■■■■■" << endl;
	cout << "■■■■■　　　　　　　　　　　　　　　　　　　　　　　　　■■■■■■■" << endl;
	cout << "■■■■■■　　　　　　　　　　　　　　　　　　　　　　　　　■■■■■■" << endl;
	cout << "■■■■■■　　　　　　　　　　　　　　　　　　　　　　　　　　■■■■■" << endl;
	cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■　　　　　　■■■■■" << endl;
	cout << "■■■■■■■　　　　　　　　　　　　　　　　　　　"; SetColor(12, 15); cout << "　■　"; SetColor(0, 15); cout << "　　　■■■■■" << endl;
	cout << "■■■■■■　　　　　　　　　　　　　　　　　　　　"; SetColor(12, 15); cout << "■■■"; SetColor(0, 15); cout << "　　■■■■■■" << endl;
	cout << "■■■■■　　　　　　　　　　　　　　　　　　　　　"; SetColor(12, 15); cout << "　■　"; SetColor(0, 15); cout << "　■■■■■■■" << endl;
	cout << "■■■■　　　　　　　　　　　　　　　　　　　　　　"; SetColor(12, 15); cout << "■　■"; SetColor(0, 15); cout << "■■■■■■■■" << endl;
	cout << "■■■　　　　　　　　■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;
	cout << "■■　　　　　　　　■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;
	cout << "■　　　　　　　　■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;
	cout << "■　　　　　　　■■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;
	cout << "■　　　　　　　■■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;
	cout << "■■　　　　　　　■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;
	cout << "■■■　　　　　　　■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;

	Sleep(1200);

	gotoxy(0, 0);
	SetColor(0, 15);

	cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;
	cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;
	cout << "■■■■■■■■■■　　　　　■■■■■■■■■■■■■■■■■■■■■■" << endl;
	cout << "■■■■■■■■■■　　　　　■■■■■■■■■■■■■■■■■■■■■■" << endl;
	cout << "■■■■■■■■■■　　　　　■■■■■■■■■■■■■■■■■■■■■■" << endl;
	cout << "■■■■■■■■■■　■■■　■■■■■■■■■■■■■■■■■■■■■■" << endl;
	cout << "■■■■■■■■■■　■　■　■■■■■■■■■■■■■■■■■■■■■■" << endl;
	cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;
	cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■■■■■■■■" << endl;
	cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■■■■■■■" << endl;
	cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■■■■■■■" << endl;
	cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■■■■■■" << endl;
	cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■■■■■" << endl;
	cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■　　　　　　　■■■■" << endl;
	cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■　　　　　　■■■■" << endl;
	cout << "■■■■■　　　　　　　　　　　　　　　　　　　　　　　　　　　　■■■■" << endl;
	cout << "■■■■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■■■■" << endl;
	cout << "■■■■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■■■■" << endl;
	cout << "■■■■　　　　　　　　　　　　　　　　　　　　　　　　　　　　■■■■■" << endl;
	cout << "■■■■　　　　　　■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;
	cout << "■■■■　　　　　　　■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;
	cout << "■■■■　　　"; SetColor(12, 15); cout << "　■　"; SetColor(0, 15); cout << "　　　　　　　　　　　　　　　　　　　■■■■■■■■" << endl;
	cout << "■■■■■　　"; SetColor(12, 15); cout << "■■■"; SetColor(0, 15); cout << "　　　　　　　　　　　　　　　　　　　　■■■■■■■" << endl;
	cout << "■■■■■■　"; SetColor(12, 15); cout << "　■　"; SetColor(0, 15); cout << "　　　　　　　　　　　　　　　　　　　　　■■■■■■" << endl;
	cout << "■■■■■■　"; SetColor(12, 15); cout << "■　■"; SetColor(0, 15); cout << "　　　　　　　　　　　　　　　　　　　　　　■■■■■" << endl;
	cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■　　　　　　■■■■■" << endl;
	cout << "■■■■■■■　　　　　　　　　　　　　　　　　　　　　　　　　■■■■■" << endl;
	cout << "■■■■■■　　　　　　　　　　　　　　　　　　　　　　　　　■■■■■■" << endl;
	cout << "■■■■■　　　　　　　　　　　　　　　　　　　　　　　　　■■■■■■■" << endl;
	cout << "■■■■　　　　　　　　　　　　　　　　　　　　　　　　　■■■■■■■■" << endl;
	cout << "■■■　　　　　　　　■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;
	cout << "■■　　　　　　　　■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;
	cout << "■　　　　　　　　■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;
	cout << "■　　　　　　　■■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;
	cout << "■　　　　　　　■■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;
	cout << "■■　　　　　　　■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;
	cout << "■■■　　　　　　　■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;

	Sleep(1200);

	gotoxy(0, 0);
	SetColor(0, 15);

	cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;
	cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;
	cout << "■■■■■■■■■■　　　　　■■■■■■■■■■■■■■■■■■■■■■" << endl;
	cout << "■■■■■■■■■■　　　　　■■■■■■■■■■■■■■■■■■■■■■" << endl;
	cout << "■■■■■■■■■■　　　　　■■■■■■■■■■■■■■■■■■■■■■" << endl;
	cout << "■■■■■■■■■■　■■■　■■■■■■■■■■■■■■■■■■■■■■" << endl;
	cout << "■■■■■■■■■■　■　■　■■■■■■■■■■■■■■■■■■■■■■" << endl;
	cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;
	cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■■■■■■■■" << endl;
	cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■■■■■■■" << endl;
	cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■■■■■■■" << endl;
	cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■■■■■■" << endl;
	cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　"; SetColor(12, 15); cout << "　■　"; SetColor(0, 15); cout << "　　■■■■■" << endl;
	cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■　"; SetColor(12, 15); cout << "■■■"; SetColor(0, 15); cout << "　　　■■■■" << endl;
	cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■"; SetColor(12, 15); cout << "　■　"; SetColor(0, 15); cout << "　　　■■■■" << endl;
	cout << "■■■■■　　　　　　　　　　　　　　　　　　　　　　"; SetColor(12, 15); cout << "■　■"; SetColor(0, 15); cout << "　　　■■■■" << endl;
	cout << "■■■■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■■■■" << endl;
	cout << "■■■■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■■■■" << endl;
	cout << "■■■■　　　　　　　　　　　　　　　　　　　　　　　　　　　　■■■■■" << endl;
	cout << "■■■■　　　　　　■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;
	cout << "■■■■　　　　　　　■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;
	cout << "■■■■　　　　　　　　　　　　　　　　　　　　　　　　　■■■■■■■■" << endl;
	cout << "■■■■■　　　　　　　　　　　　　　　　　　　　　　　　　■■■■■■■" << endl;
	cout << "■■■■■■　　　　　　　　　　　　　　　　　　　　　　　　　■■■■■■" << endl;
	cout << "■■■■■■　　　　　　　　　　　　　　　　　　　　　　　　　　■■■■■" << endl;
	cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■　　　　　　■■■■■" << endl;
	cout << "■■■■■■■　　　　　　　　　　　　　　　　　　　　　　　　　■■■■■" << endl;
	cout << "■■■■■■　　　　　　　　　　　　　　　　　　　　　　　　　■■■■■■" << endl;
	cout << "■■■■■　　　　　　　　　　　　　　　　　　　　　　　　　■■■■■■■" << endl;
	cout << "■■■■　　　　　　　　　　　　　　　　　　　　　　　　　■■■■■■■■" << endl;
	cout << "■■■　　　　　　　　■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;
	cout << "■■　　　　　　　　■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;
	cout << "■　　　　　　　　■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;
	cout << "■　　　　　　　■■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;
	cout << "■　　　　　　　■■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;
	cout << "■■　　　　　　　■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;
	cout << "■■■　　　　　　　■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;


	Sleep(1200);

	gotoxy(0, 0);
	SetColor(0, 15);

	cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;
	cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;
	cout << "■■■■■■■■■■　　　　　■■■■■■■■■■■■■■■■■■■■■■" << endl;
	cout << "■■■■■■■■■■　　　　　■■■■■■■■■■■■■■■■■■■■■■" << endl;
	cout << "■■■■■■■■■■　　　　　■■■■■■■■■■■■■■■■■■■■■■" << endl;
	cout << "■■■■■■■■■■　■■■　■■■■■■■■■■■■■■■■■■■■■■" << endl;
	cout << "■■■■■■■■■■　■　■　■■■■■■■■■■■■■■■■■■■■■■" << endl;
	cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;
	cout << "　　　　　　　　　　　"; SetColor(12, 15); cout << "　■　"; SetColor(0, 15); cout << "　　　　　　　　　　　　　　　■■■■■■■■" << endl;
	cout << "　　　　　　　　　　　"; SetColor(12, 15); cout << "■■■"; SetColor(0, 15); cout << "　　　　　　　　　　　　　　　　■■■■■■■" << endl;
	cout << "　　　　　　　　　　　"; SetColor(12, 15); cout << "　■　"; SetColor(0, 15); cout << "　　　　　　　　　　　　　　　　■■■■■■■" << endl;
	cout << "　　　　　　　　　　　"; SetColor(12, 15); cout << "■　■"; SetColor(0, 15); cout << "　　　　　　　　　　　　　　　　　■■■■■■" << endl;
	cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■■■■■" << endl;
	cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■　　　　　　　■■■■" << endl;
	cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■　　　　　　■■■■" << endl;
	cout << "■■■■■　　　　　　　　　　　　　　　　　　　　　　　　　　　　■■■■" << endl;
	cout << "■■■■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■■■■" << endl;
	cout << "■■■■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■■■■" << endl;
	cout << "■■■■　　　　　　　　　　　　　　　　　　　　　　　　　　　　■■■■■" << endl;
	cout << "■■■■　　　　　　■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;
	cout << "■■■■　　　　　　　■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;
	cout << "■■■■　　　　　　　　　　　　　　　　　　　　　　　　　■■■■■■■■" << endl;
	cout << "■■■■■　　　　　　　　　　　　　　　　　　　　　　　　　■■■■■■■" << endl;
	cout << "■■■■■■　　　　　　　　　　　　　　　　　　　　　　　　　■■■■■■" << endl;
	cout << "■■■■■■　　　　　　　　　　　　　　　　　　　　　　　　　　■■■■■" << endl;
	cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■　　　　　　■■■■■" << endl;
	cout << "■■■■■■■　　　　　　　　　　　　　　　　　　　　　　　　　■■■■■" << endl;
	cout << "■■■■■■　　　　　　　　　　　　　　　　　　　　　　　　　■■■■■■" << endl;
	cout << "■■■■■　　　　　　　　　　　　　　　　　　　　　　　　　■■■■■■■" << endl;
	cout << "■■■■　　　　　　　　　　　　　　　　　　　　　　　　　■■■■■■■■" << endl;
	cout << "■■■　　　　　　　　■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;
	cout << "■■　　　　　　　　■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;
	cout << "■　　　　　　　　■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;
	cout << "■　　　　　　　■■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;
	cout << "■　　　　　　　■■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;
	cout << "■■　　　　　　　■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;
	cout << "■■■　　　　　　　■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;

	Sleep(1200);


	gotoxy(0, 0);
	SetColor(0, 15);

	cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;
	cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;
	cout << "■■■■■■■■■■　　　　　■■■■■■■■■■■■■■■■■■■■■■" << endl;
	cout << "■■■■■■■■■■　　　　　■■■■■■■■■■■■■■■■■■■■■■" << endl;
	cout << "■■■■■■■■■■　　　　　■■■■■■■■■■■■■■■■■■■■■■" << endl;
	cout << "■■■■■■■■■■　■■■　■■■■■■■■■■■■■■■■■■■■■■" << endl;
	cout << "■■■■■■■■■■　■　■　■■■■■■■■■■■■■■■■■■■■■■" << endl;
	cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;
	cout << "　　　　　　　　　　　"; SetColor(12, 15); cout << "　■　"; SetColor(0, 15); cout << "　　　　　　　　　　　　　　　■■■■■■■■" << endl;
	cout << "　　　　　　　　　　　"; SetColor(12, 15); cout << "■■■"; SetColor(0, 15); cout << "　　　　　　　　　　　　　　　　■■■■■■■" << endl;
	cout << "　　　　　　　　　　　"; SetColor(12, 15); cout << "　■　"; SetColor(0, 15); cout << "　　　　　　　　　　　　　　　　■■■■■■■" << endl;
	cout << "　　　　　　　　　　　"; SetColor(12, 15); cout << "■　■"; SetColor(0, 15); cout << "　　　　　　　　　　　　　　　　　■■■■■■" << endl;
	cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■■■■■" << endl;
	cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■　　　　　　　■■■■" << endl;
	cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■　　　　　　■■■■" << endl;
	cout << "■■■■■　　　　　　　　　　　　　　　　　　　　　　　　　　　　■■■■" << endl;
	cout << "■■■■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■■■■" << endl;
	cout << "■■■■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■■■■" << endl;
	cout << "■■■■　　　　　　　　　　　　　　　　　　　　　　　　　　　　■■■■■" << endl;
	cout << "■■■■　　　　　　■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;
	cout << "■■■■　　　　　　　■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;
	cout << "■■■■　　　　　　　　　　　　　　　　　　　　　　　　　■■■■■■■■" << endl;
	cout << "■■■■■　　　　　　　　　　　　　　　　　　　　　　　　　■■■■■■■" << endl;
	cout << "■■■■■■　　　　　　　　　　　　　　　　　　　　　　　　　■■■■■■" << endl;
	cout << "■■■■■■　　　　　　　　　　　　　　　　　　　　　　　　　　■■■■■" << endl;
	cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■　　　　　　■■■■■" << endl;

	SetColor(13, 15);

	cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;
	cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
	cout << "■"; SetColor(0, 15); cout << "　　[집배원]　　　　　　　　　　　　　　　　　　　　　　　　　　　　　"; SetColor(13, 15); cout << "■" << endl;
	cout << "■"; SetColor(0, 15); cout << "　　아타호님 계십니까? 우편 왔습니다~ 　　　　　　　　　　　　　　　　"; SetColor(13, 15); cout << "■" << endl;
	cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
	cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
	cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
	cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
	cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
	cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
	cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;

	Conversation();


	gotoxy(0, 0);
	SetColor(0, 15);

	cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;
	cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;
	cout << "■■■■■■■■■■　　　　　■■■■■■■■■■■■■■■■■■■■■■" << endl;
	cout << "■■■■■■■■■■　　　　　■■■■■■■■■■■■■■■■■■■■■■" << endl;
	cout << "■■■■■■■■■■　　　　　■■■■■■■■■■■■■■■■■■■■■■" << endl;
	cout << "■■■■■■■■■■　■■■　■■■■■■■■■■■■■■■■■■■■■■" << endl;
	cout << "■■■■■■■■■■　■　■　■■■■■■■■■■■■■■■■■■■■■■" << endl;
	cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;
	cout << "　　　　　　　　　　　"; SetColor(12, 15); cout << "　■　"; SetColor(0, 15); cout << "　　　　　　　　　　　　　　　■■■■■■■■" << endl;
	cout << "　　　　　　　　　　　"; SetColor(12, 15); cout << "■■■"; SetColor(0, 15); cout << "　　　　　　　　　　　　　　　　■■■■■■■" << endl;
	cout << "　　　　　　　　　　　"; SetColor(12, 15); cout << "　■　"; SetColor(0, 15); cout << "　　　　　　　　　　　　　　　　■■■■■■■" << endl;
	cout << "　　　　　　　　　　　"; SetColor(12, 15); cout << "■　■"; SetColor(0, 15); cout << "　　　　　　　　　　　　　　　　　■■■■■■" << endl;
	cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■■■■■" << endl;
	cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■　　　　　　　■■■■" << endl;
	cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■　　　　　　■■■■" << endl;
	cout << "■■■■■　　　　　　　　　　　　　　　　　　　　　　　　　　　　■■■■" << endl;
	cout << "■■■■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■■■■" << endl;
	cout << "■■■■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■■■■" << endl;
	cout << "■■■■　　　　　　　　　　　　　　　　　　　　　　　　　　　　■■■■■" << endl;
	cout << "■■■■　　　　　　■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;
	cout << "■■■■　　　　　　　■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;
	cout << "■■■■　　　　　　　　　　　　　　　　　　　　　　　　　■■■■■■■■" << endl;
	cout << "■■■■■　　　　　　　　　　　　　　　　　　　　　　　　　■■■■■■■" << endl;
	cout << "■■■■■■　　　　　　　　　　　　　　　　　　　　　　　　　■■■■■■" << endl;
	cout << "■■■■■■　　　　　　　　　　　　　　　　　　　　　　　　　　■■■■■" << endl;
	cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■　　　　　　■■■■■" << endl;
	cout << "■■■■■■■　　　　　　　　　　　　　　　　　　　　　　　　　■■■■■" << endl;
	cout << "■■■■■■　　　　　　　　　　　　　　　　　　　　　　　　　■■■■■■" << endl;
	cout << "■■■■■　　　　　　　　　　　　　　　　　　　　　　　　　■■■■■■■" << endl;
	cout << "■■■■　　　　　　　　　　　　　　　　　　　　　　　　　■■■■■■■■" << endl;
	cout << "■■■　　　　　　　　■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;
	cout << "■■　　　　　　　　■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;
	cout << "■　　　　　　　　■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;
	cout << "■　　　　　　　■■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;
	cout << "■　　　　　　　■■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;
	cout << "■■　　　　　　　■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;
	cout << "■■■　　　　　　　■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;

	Sleep(1500);



	gotoxy(0, 0);
	SetColor(0, 15);

	cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;
	cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;
	cout << "■■■■■■■■■■　　　　　■■■■■■■■■■■■■■■■■■■■■■" << endl;
	cout << "■■■■■■■■■■　　　　　■■■■■■■■■■■■■■■■■■■■■■" << endl;
	cout << "■■■■■■■■■■　　　　　■■■■■■■■■■■■■■■■■■■■■■" << endl;
	cout << "■■■■■■■■■■　■■■　■■■■■■■■■■■■■■■■■■■■■■" << endl;
	cout << "■■■■■■■■■■　■　■　■■■■■■■■■■■■■■■■■■■■■■" << endl;
	cout << "■■■■■■■■■■■■　■■■■■■■■■■■■■■■■■■■■■■■■" << endl;
	cout << "　　　　　　　　　　　　　"; SetColor(12, 15); cout << "　■　"; SetColor(0, 15); cout << "　　　　　　　　　　　　　■■■■■■■■" << endl;
	cout << "　　　　　　　　　　　　　"; SetColor(12, 15); cout << "■■■"; SetColor(0, 15); cout << "　　　　　　　　　　　　　　■■■■■■■" << endl;
	cout << "　　　　　　　　　　　　　"; SetColor(12, 15); cout << "　■　"; SetColor(0, 15); cout << "　　　　　　　　　　　　　　■■■■■■■" << endl;
	cout << "　　　　　　　　　　　　　"; SetColor(12, 15); cout << "■　■"; SetColor(0, 15); cout << "　　　　　　　　　　　　　　　■■■■■■" << endl;
	cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■■■■■" << endl;
	cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■　　　　　　　■■■■" << endl;
	cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■　　　　　　■■■■" << endl;
	cout << "■■■■■　　　　　　　　　　　　　　　　　　　　　　　　　　　　■■■■" << endl;
	cout << "■■■■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■■■■" << endl;
	cout << "■■■■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■■■■" << endl;
	cout << "■■■■　　　　　　　　　　　　　　　　　　　　　　　　　　　　■■■■■" << endl;
	cout << "■■■■　　　　　　■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;
	cout << "■■■■　　　　　　　■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;
	cout << "■■■■　　　　　　　　　　　　　　　　　　　　　　　　　■■■■■■■■" << endl;
	cout << "■■■■■　　　　　　　　　　　　　　　　　　　　　　　　　■■■■■■■" << endl;
	cout << "■■■■■■　　　　　　　　　　　　　　　　　　　　　　　　　■■■■■■" << endl;
	cout << "■■■■■■　　　　　　　　　　　　　　　　　　　　　　　　　　■■■■■" << endl;
	cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■　　　　　　■■■■■" << endl;
	cout << "■■■■■■■　　　　　　　　　　　　　　　　　　　　　　　　　■■■■■" << endl;
	cout << "■■■■■■　　　　　　　　　　　　　　　　　　　　　　　　　■■■■■■" << endl;
	cout << "■■■■■　　　　　　　　　　　　　　　　　　　　　　　　　■■■■■■■" << endl;
	cout << "■■■■　　　　　　　　　　　　　　　　　　　　　　　　　■■■■■■■■" << endl;
	cout << "■■■　　　　　　　　■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;
	cout << "■■　　　　　　　　■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;
	cout << "■　　　　　　　　■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;
	cout << "■　　　　　　　■■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;
	cout << "■　　　　　　　■■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;
	cout << "■■　　　　　　　■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;
	cout << "■■■　　　　　　　■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;


	_effect = Edooropen;

	Sleep(1500);

	gotoxy(0, 0);
	SetColor(0, 15);

	cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;
	cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;
	cout << "■■■■■■■■■■　　　　　■■■■■■■■■■■■■■■■■■■■■■" << endl;
	cout << "■■■■■■■■■■　　　　　■■■■■■■■■■■■■■■■■■■■■■" << endl;
	cout << "■■■■■■■■■■　　　　　■■■■■■■■■■■■■■■■■■■■■■" << endl;
	cout << "■■■■■■■■■■　■■■　■■■■■■■■■■■■■■■■■■■■■■" << endl;
	cout << "■■■■■■■■■■　■　■　■■■■■■■■■■■■■■■■■■■■■■" << endl;
	cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;
	cout << "　　　　　　　　　　　"; SetColor(14, 15); cout << "　■　　"; SetColor(12, 15); cout << "　■　"; SetColor(0, 15); cout << "　　　　　　　　　　　■■■■■■■■" << endl;
	cout << "　　　　　　　　　　　"; SetColor(14, 15); cout << "■■■　"; SetColor(12, 15); cout << "■■■"; SetColor(0, 15); cout << "　　　　　　　　　　　　■■■■■■■" << endl;
	cout << "　　　　　　　　　　　"; SetColor(14, 15); cout << "　■　　"; SetColor(12, 15); cout << "　■　"; SetColor(0, 15); cout << "　　　　　　　　　　　　■■■■■■■" << endl;
	cout << "　　　　　　　　　　　"; SetColor(14, 15); cout << "■　■　"; SetColor(12, 15); cout << "■　■"; SetColor(0, 15); cout << "　　　　　　　　　　　　　■■■■■■" << endl;
	cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■■■■■" << endl;
	cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■　　　　　　　■■■■" << endl;
	cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■　　　　　　■■■■" << endl;
	cout << "■■■■■　　　　　　　　　　　　　　　　　　　　　　　　　　　　■■■■" << endl;
	cout << "■■■■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■■■■" << endl;
	cout << "■■■■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■■■■" << endl;
	cout << "■■■■　　　　　　　　　　　　　　　　　　　　　　　　　　　　■■■■■" << endl;
	cout << "■■■■　　　　　　■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;
	cout << "■■■■　　　　　　　■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;
	cout << "■■■■　　　　　　　　　　　　　　　　　　　　　　　　　■■■■■■■■" << endl;
	cout << "■■■■■　　　　　　　　　　　　　　　　　　　　　　　　　■■■■■■■" << endl;
	cout << "■■■■■■　　　　　　　　　　　　　　　　　　　　　　　　　■■■■■■" << endl;
	cout << "■■■■■■　　　　　　　　　　　　　　　　　　　　　　　　　　■■■■■" << endl;
	cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■　　　　　　■■■■■" << endl;
	cout << "■■■■■■■　　　　　　　　　　　　　　　　　　　　　　　　　■■■■■" << endl;
	cout << "■■■■■■　　　　　　　　　　　　　　　　　　　　　　　　　■■■■■■" << endl;
	cout << "■■■■■　　　　　　　　　　　　　　　　　　　　　　　　　■■■■■■■" << endl;
	cout << "■■■■　　　　　　　　　　　　　　　　　　　　　　　　　■■■■■■■■" << endl;
	cout << "■■■　　　　　　　　■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;
	cout << "■■　　　　　　　　■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;
	cout << "■　　　　　　　　■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;
	cout << "■　　　　　　　■■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;
	cout << "■　　　　　　　■■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;
	cout << "■■　　　　　　　■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;
	cout << "■■■　　　　　　　■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;

	Sleep(1500);

	gotoxy(0, 0);
	SetColor(0, 15);

	cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;
	cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;
	cout << "■■■■■■■■■■　　　　　■■■■■■■■■■■■■■■■■■■■■■" << endl;
	cout << "■■■■■■■■■■　　　　　■■■■■■■■■■■■■■■■■■■■■■" << endl;
	cout << "■■■■■■■■■■　　　　　■■■■■■■■■■■■■■■■■■■■■■" << endl;
	cout << "■■■■■■■■■■　■■■　■■■■■■■■■■■■■■■■■■■■■■" << endl;
	cout << "■■■■■■■■■■　■　■　■■■■■■■■■■■■■■■■■■■■■■" << endl;
	cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;
	cout << "　　　　　　　　　　　"; SetColor(14, 15); cout << "　■　　"; SetColor(12, 15); cout << "　■　"; SetColor(0, 15); cout << "　　　　　　　　　　　■■■■■■■■" << endl;
	cout << "　　　　　　　　　　　"; SetColor(14, 15); cout << "■■■　"; SetColor(12, 15); cout << "■■■"; SetColor(0, 15); cout << "　　　　　　　　　　　　■■■■■■■" << endl;
	cout << "　　　　　　　　　　　"; SetColor(14, 15); cout << "　■　　"; SetColor(12, 15); cout << "　■　"; SetColor(0, 15); cout << "　　　　　　　　　　　　■■■■■■■" << endl;
	cout << "　　　　　　　　　　　"; SetColor(14, 15); cout << "■　■　"; SetColor(12, 15); cout << "■　■"; SetColor(0, 15); cout << "　　　　　　　　　　　　　■■■■■■" << endl;
	cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■■■■■" << endl;
	cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■　　　　　　　■■■■" << endl;
	cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■　　　　　　■■■■" << endl;
	cout << "■■■■■　　　　　　　　　　　　　　　　　　　　　　　　　　　　■■■■" << endl;
	cout << "■■■■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■■■■" << endl;
	cout << "■■■■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■■■■" << endl;
	cout << "■■■■　　　　　　　　　　　　　　　　　　　　　　　　　　　　■■■■■" << endl;
	cout << "■■■■　　　　　　■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;
	cout << "■■■■　　　　　　　■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;
	cout << "■■■■　　　　　　　　　　　　　　　　　　　　　　　　　■■■■■■■■" << endl;
	cout << "■■■■■　　　　　　　　　　　　　　　　　　　　　　　　　■■■■■■■" << endl;
	cout << "■■■■■■　　　　　　　　　　　　　　　　　　　　　　　　　■■■■■■" << endl;
	cout << "■■■■■■　　　　　　　　　　　　　　　　　　　　　　　　　　■■■■■" << endl;
	cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■　　　　　　■■■■■" << endl;

	SetColor(13, 15);

	cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;
	cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
	cout << "■"; SetColor(0, 15); cout << "　　[아타호]　　　　　　　　　　　　　　　　　　　　　　　　　　　　　"; SetColor(13, 15); cout << "■" << endl;
	cout << "■"; SetColor(0, 15); cout << "　　집배원 양반 아니신가!　　　　　　　　　 　　　　　　　　　　　　　"; SetColor(13, 15); cout << "■" << endl;
	cout << "■"; SetColor(0, 15); cout << "　　무슨 일로 오신건가　　　　　　　　　　　　　　　　　　　　　　　　"; SetColor(13, 15); cout << "■" << endl;
	cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
	cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
	cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
	cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
	cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
	cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;

	Conversation();


	gotoxy(0, 0);
	SetColor(0, 15);

	cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;
	cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;
	cout << "■■■■■■■■■■　　　　　■■■■■■■■■■■■■■■■■■■■■■" << endl;
	cout << "■■■■■■■■■■　　　　　■■■■■■■■■■■■■■■■■■■■■■" << endl;
	cout << "■■■■■■■■■■　　　　　■■■■■■■■■■■■■■■■■■■■■■" << endl;
	cout << "■■■■■■■■■■　■■■　■■■■■■■■■■■■■■■■■■■■■■" << endl;
	cout << "■■■■■■■■■■　■　■　■■■■■■■■■■■■■■■■■■■■■■" << endl;
	cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;
	cout << "　　　　　　　　　　　"; SetColor(14, 15); cout << "　■　　"; SetColor(12, 15); cout << "　■　"; SetColor(0, 15); cout << "　　　　　　　　　　　■■■■■■■■" << endl;
	cout << "　　　　　　　　　　　"; SetColor(14, 15); cout << "■■■　"; SetColor(12, 15); cout << "■■■"; SetColor(0, 15); cout << "　　　　　　　　　　　　■■■■■■■" << endl;
	cout << "　　　　　　　　　　　"; SetColor(14, 15); cout << "　■　　"; SetColor(12, 15); cout << "　■　"; SetColor(0, 15); cout << "　　　　　　　　　　　　■■■■■■■" << endl;
	cout << "　　　　　　　　　　　"; SetColor(14, 15); cout << "■　■　"; SetColor(12, 15); cout << "■　■"; SetColor(0, 15); cout << "　　　　　　　　　　　　　■■■■■■" << endl;
	cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■■■■■" << endl;
	cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■　　　　　　　■■■■" << endl;
	cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■　　　　　　■■■■" << endl;
	cout << "■■■■■　　　　　　　　　　　　　　　　　　　　　　　　　　　　■■■■" << endl;
	cout << "■■■■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■■■■" << endl;
	cout << "■■■■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■■■■" << endl;
	cout << "■■■■　　　　　　　　　　　　　　　　　　　　　　　　　　　　■■■■■" << endl;
	cout << "■■■■　　　　　　■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;
	cout << "■■■■　　　　　　　■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;
	cout << "■■■■　　　　　　　　　　　　　　　　　　　　　　　　　■■■■■■■■" << endl;
	cout << "■■■■■　　　　　　　　　　　　　　　　　　　　　　　　　■■■■■■■" << endl;
	cout << "■■■■■■　　　　　　　　　　　　　　　　　　　　　　　　　■■■■■■" << endl;
	cout << "■■■■■■　　　　　　　　　　　　　　　　　　　　　　　　　　■■■■■" << endl;
	cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■　　　　　　■■■■■" << endl;
	cout << "■■■■■■■　　　　　　　　　　　　　　　　　　　　　　　　　■■■■■" << endl;
	cout << "■■■■■■　　　　　　　　　　　　　　　　　　　　　　　　　■■■■■■" << endl;
	cout << "■■■■■　　　　　　　　　　　　　　　　　　　　　　　　　■■■■■■■" << endl;
	cout << "■■■■　　　　　　　　　　　　　　　　　　　　　　　　　■■■■■■■■" << endl;
	cout << "■■■　　　　　　　　■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;
	cout << "■■　　　　　　　　■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;
	cout << "■　　　　　　　　■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;
	cout << "■　　　　　　　■■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;
	cout << "■　　　　　　　■■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;
	cout << "■■　　　　　　　■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;
	cout << "■■■　　　　　　　■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;

	Sleep(1200);


	gotoxy(0, 0);
	SetColor(0, 15);

	cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;
	cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;
	cout << "■■■■■■■■■■　　　　　■■■■■■■■■■■■■■■■■■■■■■" << endl;
	cout << "■■■■■■■■■■　　　　　■■■■■■■■■■■■■■■■■■■■■■" << endl;
	cout << "■■■■■■■■■■　　　　　■■■■■■■■■■■■■■■■■■■■■■" << endl;
	cout << "■■■■■■■■■■　■■■　■■■■■■■■■■■■■■■■■■■■■■" << endl;
	cout << "■■■■■■■■■■　■　■　■■■■■■■■■■■■■■■■■■■■■■" << endl;
	cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;
	cout << "　　　　　　　　　　　"; SetColor(14, 15); cout << "　■　　"; SetColor(12, 15); cout << "　■　"; SetColor(0, 15); cout << "　　　　　　　　　　　■■■■■■■■" << endl;
	cout << "　　　　　　　　　　　"; SetColor(14, 15); cout << "■■■　"; SetColor(12, 15); cout << "■■■"; SetColor(0, 15); cout << "　　　　　　　　　　　　■■■■■■■" << endl;
	cout << "　　　　　　　　　　　"; SetColor(14, 15); cout << "　■　　"; SetColor(12, 15); cout << "　■　"; SetColor(0, 15); cout << "　　　　　　　　　　　　■■■■■■■" << endl;
	cout << "　　　　　　　　　　　"; SetColor(14, 15); cout << "■　■　"; SetColor(12, 15); cout << "■　■"; SetColor(0, 15); cout << "　　　　　　　　　　　　　■■■■■■" << endl;
	cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■■■■■" << endl;
	cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■　　　　　　　■■■■" << endl;
	cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■　　　　　　■■■■" << endl;
	cout << "■■■■■　　　　　　　　　　　　　　　　　　　　　　　　　　　　■■■■" << endl;
	cout << "■■■■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■■■■" << endl;
	cout << "■■■■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■■■■" << endl;
	cout << "■■■■　　　　　　　　　　　　　　　　　　　　　　　　　　　　■■■■■" << endl;
	cout << "■■■■　　　　　　■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;
	cout << "■■■■　　　　　　　■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;
	cout << "■■■■　　　　　　　　　　　　　　　　　　　　　　　　　■■■■■■■■" << endl;
	cout << "■■■■■　　　　　　　　　　　　　　　　　　　　　　　　　■■■■■■■" << endl;
	cout << "■■■■■■　　　　　　　　　　　　　　　　　　　　　　　　　■■■■■■" << endl;
	cout << "■■■■■■　　　　　　　　　　　　　　　　　　　　　　　　　　■■■■■" << endl;
	cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■　　　　　　■■■■■" << endl;

	SetColor(13, 15);

	cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;
	cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
	cout << "■"; SetColor(0, 15); cout << "　　[집배원]　　　　　　　　　　　　　　　　　　　　　　　　　　　　　"; SetColor(13, 15); cout << "■" << endl;
	cout << "■"; SetColor(0, 15); cout << "　　아타호님 앞으로 편지가 와서 배달 왔습니다.　　　　　　　　　　　　"; SetColor(13, 15); cout << "■" << endl;
	cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
	cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
	cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
	cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
	cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
	cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
	cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;

	Conversation();

	gotoxy(0, 0);
	SetColor(0, 15);

	cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;
	cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;
	cout << "■■■■■■■■■■　　　　　■■■■■■■■■■■■■■■■■■■■■■" << endl;
	cout << "■■■■■■■■■■　　　　　■■■■■■■■■■■■■■■■■■■■■■" << endl;
	cout << "■■■■■■■■■■　　　　　■■■■■■■■■■■■■■■■■■■■■■" << endl;
	cout << "■■■■■■■■■■　■■■　■■■■■■■■■■■■■■■■■■■■■■" << endl;
	cout << "■■■■■■■■■■　■　■　■■■■■■■■■■■■■■■■■■■■■■" << endl;
	cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;
	cout << "　　　　　　　　　　　"; SetColor(14, 15); cout << "　■　　"; SetColor(12, 15); cout << "　■　"; SetColor(0, 15); cout << "　　　　　　　　　　　■■■■■■■■" << endl;
	cout << "　　　　　　　　　　　"; SetColor(14, 15); cout << "■■■　"; SetColor(12, 15); cout << "■■■"; SetColor(0, 15); cout << "　　　　　　　　　　　　■■■■■■■" << endl;
	cout << "　　　　　　　　　　　"; SetColor(14, 15); cout << "　■　　"; SetColor(12, 15); cout << "　■　"; SetColor(0, 15); cout << "　　　　　　　　　　　　■■■■■■■" << endl;
	cout << "　　　　　　　　　　　"; SetColor(14, 15); cout << "■　■　"; SetColor(12, 15); cout << "■　■"; SetColor(0, 15); cout << "　　　　　　　　　　　　　■■■■■■" << endl;
	cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■■■■■" << endl;
	cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■　　　　　　　■■■■" << endl;
	cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■　　　　　　■■■■" << endl;
	cout << "■■■■■　　　　　　　　　　　　　　　　　　　　　　　　　　　　■■■■" << endl;
	cout << "■■■■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■■■■" << endl;
	cout << "■■■■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■■■■" << endl;
	cout << "■■■■　　　　　　　　　　　　　　　　　　　　　　　　　　　　■■■■■" << endl;
	cout << "■■■■　　　　　　■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;
	cout << "■■■■　　　　　　　■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;
	cout << "■■■■　　　　　　　　　　　　　　　　　　　　　　　　　■■■■■■■■" << endl;
	cout << "■■■■■　　　　　　　　　　　　　　　　　　　　　　　　　■■■■■■■" << endl;
	cout << "■■■■■■　　　　　　　　　　　　　　　　　　　　　　　　　■■■■■■" << endl;
	cout << "■■■■■■　　　　　　　　　　　　　　　　　　　　　　　　　　■■■■■" << endl;
	cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■　　　　　　■■■■■" << endl;
	cout << "■■■■■■■　　　　　　　　　　　　　　　　　　　　　　　　　■■■■■" << endl;
	cout << "■■■■■■　　　　　　　　　　　　　　　　　　　　　　　　　■■■■■■" << endl;
	cout << "■■■■■　　　　　　　　　　　　　　　　　　　　　　　　　■■■■■■■" << endl;
	cout << "■■■■　　　　　　　　　　　　　　　　　　　　　　　　　■■■■■■■■" << endl;
	cout << "■■■　　　　　　　　■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;
	cout << "■■　　　　　　　　■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;
	cout << "■　　　　　　　　■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;
	cout << "■　　　　　　　■■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;
	cout << "■　　　　　　　■■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;
	cout << "■■　　　　　　　■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;
	cout << "■■■　　　　　　　■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;

	Sleep(1200);


	gotoxy(0, 0);
	SetColor(0, 15);

	cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;
	cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;
	cout << "■■■■■■■■■■　　　　　■■■■■■■■■■■■■■■■■■■■■■" << endl;
	cout << "■■■■■■■■■■　　　　　■■■■■■■■■■■■■■■■■■■■■■" << endl;
	cout << "■■■■■■■■■■　　　　　■■■■■■■■■■■■■■■■■■■■■■" << endl;
	cout << "■■■■■■■■■■　■■■　■■■■■■■■■■■■■■■■■■■■■■" << endl;
	cout << "■■■■■■■■■■　■　■　■■■■■■■■■■■■■■■■■■■■■■" << endl;
	cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;
	cout << "　　　　　　　　　　　"; SetColor(14, 15); cout << "　■　　"; SetColor(12, 15); cout << "　■　"; SetColor(0, 15); cout << "　　　　　　　　　　　■■■■■■■■" << endl;
	cout << "　　　　　　　　　　　"; SetColor(14, 15); cout << "■■■　"; SetColor(12, 15); cout << "■■■"; SetColor(0, 15); cout << "　　　　　　　　　　　　■■■■■■■" << endl;
	cout << "　　　　　　　　　　　"; SetColor(14, 15); cout << "　■　　"; SetColor(12, 15); cout << "　■　"; SetColor(0, 15); cout << "　　　　　　　　　　　　■■■■■■■" << endl;
	cout << "　　　　　　　　　　　"; SetColor(14, 15); cout << "■　■　"; SetColor(12, 15); cout << "■　■"; SetColor(0, 15); cout << "　　　　　　　　　　　　　■■■■■■" << endl;
	cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■■■■■" << endl;
	cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■　　　　　　　■■■■" << endl;
	cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■　　　　　　■■■■" << endl;
	cout << "■■■■■　　　　　　　　　　　　　　　　　　　　　　　　　　　　■■■■" << endl;
	cout << "■■■■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■■■■" << endl;
	cout << "■■■■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■■■■" << endl;
	cout << "■■■■　　　　　　　　　　　　　　　　　　　　　　　　　　　　■■■■■" << endl;
	cout << "■■■■　　　　　　■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;
	cout << "■■■■　　　　　　　■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;
	cout << "■■■■　　　　　　　　　　　　　　　　　　　　　　　　　■■■■■■■■" << endl;
	cout << "■■■■■　　　　　　　　　　　　　　　　　　　　　　　　　■■■■■■■" << endl;
	cout << "■■■■■■　　　　　　　　　　　　　　　　　　　　　　　　　■■■■■■" << endl;
	cout << "■■■■■■　　　　　　　　　　　　　　　　　　　　　　　　　　■■■■■" << endl;
	cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■　　　　　　■■■■■" << endl;

	SetColor(13, 15);

	cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;
	cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
	cout << "■"; SetColor(0, 15); cout << "　　[아타호]　　　　　　　　　　　　　　　　　　　　　　　　　　　　　"; SetColor(13, 15); cout << "■" << endl;
	cout << "■"; SetColor(0, 15); cout << "　　오 올라오느라 힘들었을텐데 참 고마우이.　　　 　　　　　　　　　　"; SetColor(13, 15); cout << "■" << endl;
	cout << "■"; SetColor(0, 15); cout << "　　내 마을에 갈일이 생기면 한잔 사도록 하겠네 조심히 가시게. 　　　　"; SetColor(13, 15); cout << "■" << endl;
	cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
	cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
	cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
	cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
	cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
	cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;

	Conversation();

	gotoxy(0, 0);
	SetColor(0, 15);

	cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;
	cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;
	cout << "■■■■■■■■■■　　　　　■■■■■■■■■■■■■■■■■■■■■■" << endl;
	cout << "■■■■■■■■■■　　　　　■■■■■■■■■■■■■■■■■■■■■■" << endl;
	cout << "■■■■■■■■■■　　　　　■■■■■■■■■■■■■■■■■■■■■■" << endl;
	cout << "■■■■■■■■■■　■■■　■■■■■■■■■■■■■■■■■■■■■■" << endl;
	cout << "■■■■■■■■■■　■　■　■■■■■■■■■■■■■■■■■■■■■■" << endl;
	cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;
	cout << "　　　　　　　　　　　"; SetColor(14, 15); cout << "　■　　"; SetColor(12, 15); cout << "　■　"; SetColor(0, 15); cout << "　　　　　　　　　　　■■■■■■■■" << endl;
	cout << "　　　　　　　　　　　"; SetColor(14, 15); cout << "■■■　"; SetColor(12, 15); cout << "■■■"; SetColor(0, 15); cout << "　　　　　　　　　　　　■■■■■■■" << endl;
	cout << "　　　　　　　　　　　"; SetColor(14, 15); cout << "　■　　"; SetColor(12, 15); cout << "　■　"; SetColor(0, 15); cout << "　　　　　　　　　　　　■■■■■■■" << endl;
	cout << "　　　　　　　　　　　"; SetColor(14, 15); cout << "■　■　"; SetColor(12, 15); cout << "■　■"; SetColor(0, 15); cout << "　　　　　　　　　　　　　■■■■■■" << endl;
	cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■■■■■" << endl;
	cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■　　　　　　　■■■■" << endl;
	cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■　　　　　　■■■■" << endl;
	cout << "■■■■■　　　　　　　　　　　　　　　　　　　　　　　　　　　　■■■■" << endl;
	cout << "■■■■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■■■■" << endl;
	cout << "■■■■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■■■■" << endl;
	cout << "■■■■　　　　　　　　　　　　　　　　　　　　　　　　　　　　■■■■■" << endl;
	cout << "■■■■　　　　　　■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;
	cout << "■■■■　　　　　　　■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;
	cout << "■■■■　　　　　　　　　　　　　　　　　　　　　　　　　■■■■■■■■" << endl;
	cout << "■■■■■　　　　　　　　　　　　　　　　　　　　　　　　　■■■■■■■" << endl;
	cout << "■■■■■■　　　　　　　　　　　　　　　　　　　　　　　　　■■■■■■" << endl;
	cout << "■■■■■■　　　　　　　　　　　　　　　　　　　　　　　　　　■■■■■" << endl;
	cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■　　　　　　■■■■■" << endl;
	cout << "■■■■■■■　　　　　　　　　　　　　　　　　　　　　　　　　■■■■■" << endl;
	cout << "■■■■■■　　　　　　　　　　　　　　　　　　　　　　　　　■■■■■■" << endl;
	cout << "■■■■■　　　　　　　　　　　　　　　　　　　　　　　　　■■■■■■■" << endl;
	cout << "■■■■　　　　　　　　　　　　　　　　　　　　　　　　　■■■■■■■■" << endl;
	cout << "■■■　　　　　　　　■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;
	cout << "■■　　　　　　　　■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;
	cout << "■　　　　　　　　■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;
	cout << "■　　　　　　　■■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;
	cout << "■　　　　　　　■■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;
	cout << "■■　　　　　　　■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;
	cout << "■■■　　　　　　　■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;

	Sleep(1200);

	gotoxy(0, 0);
	SetColor(0, 15);

	cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;
	cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;
	cout << "■■■■■■■■■■　　　　　■■■■■■■■■■■■■■■■■■■■■■" << endl;
	cout << "■■■■■■■■■■　　　　　■■■■■■■■■■■■■■■■■■■■■■" << endl;
	cout << "■■■■■■■■■■　　　　　■■■■■■■■■■■■■■■■■■■■■■" << endl;
	cout << "■■■■■■■■■■　■■■　■■■■■■■■■■■■■■■■■■■■■■" << endl;
	cout << "■■■■■■■■■■　■　■　■■■■■■■■■■■■■■■■■■■■■■" << endl;
	cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;
	cout << "　　　　　　　　　　　"; SetColor(14, 15); cout << "　■　　"; SetColor(12, 15); cout << "　■　"; SetColor(0, 15); cout << "　　　　　　　　　　　■■■■■■■■" << endl;
	cout << "　　　　　　　　　　　"; SetColor(14, 15); cout << "■■■　"; SetColor(12, 15); cout << "■■■"; SetColor(0, 15); cout << "　　　　　　　　　　　　■■■■■■■" << endl;
	cout << "　　　　　　　　　　　"; SetColor(14, 15); cout << "　■　　"; SetColor(12, 15); cout << "　■　"; SetColor(0, 15); cout << "　　　　　　　　　　　　■■■■■■■" << endl;
	cout << "　　　　　　　　　　　"; SetColor(14, 15); cout << "■　■　"; SetColor(12, 15); cout << "■　■"; SetColor(0, 15); cout << "　　　　　　　　　　　　　■■■■■■" << endl;
	cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■■■■■" << endl;
	cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■　　　　　　　■■■■" << endl;
	cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■　　　　　　■■■■" << endl;
	cout << "■■■■■　　　　　　　　　　　　　　　　　　　　　　　　　　　　■■■■" << endl;
	cout << "■■■■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■■■■" << endl;
	cout << "■■■■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■■■■" << endl;
	cout << "■■■■　　　　　　　　　　　　　　　　　　　　　　　　　　　　■■■■■" << endl;
	cout << "■■■■　　　　　　■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;
	cout << "■■■■　　　　　　　■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;
	cout << "■■■■　　　　　　　　　　　　　　　　　　　　　　　　　■■■■■■■■" << endl;
	cout << "■■■■■　　　　　　　　　　　　　　　　　　　　　　　　　■■■■■■■" << endl;
	cout << "■■■■■■　　　　　　　　　　　　　　　　　　　　　　　　　■■■■■■" << endl;
	cout << "■■■■■■　　　　　　　　　　　　　　　　　　　　　　　　　　■■■■■" << endl;
	cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■　　　　　　■■■■■" << endl;

	SetColor(13, 15);

	cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;
	cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
	cout << "■"; SetColor(0, 15); cout << "　　[집배원]　　　　　　　　　　　　　　　　　　　　　　　　　　　　　"; SetColor(13, 15); cout << "■" << endl;
	cout << "■"; SetColor(0, 15); cout << "　　ㅎㅎ 아닙니다. 당연히 해야할 제 일인걸요.  　 　　　　　　　　　　"; SetColor(13, 15); cout << "■" << endl;
	cout << "■"; SetColor(0, 15); cout << "　　그럼 다음에 또 뵙겠습니다!! 　　　　　　　　　　　　　　　　　　　"; SetColor(13, 15); cout << "■" << endl;
	cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
	cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
	cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
	cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
	cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
	cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;


	Conversation();

	gotoxy(0, 0);
	SetColor(0, 15);

	cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;
	cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;
	cout << "■■■■■■■■■■　　　　　■■■■■■■■■■■■■■■■■■■■■■" << endl;
	cout << "■■■■■■■■■■　　　　　■■■■■■■■■■■■■■■■■■■■■■" << endl;
	cout << "■■■■■■■■■■　　　　　■■■■■■■■■■■■■■■■■■■■■■" << endl;
	cout << "■■■■■■■■■■　■■■　■■■■■■■■■■■■■■■■■■■■■■" << endl;
	cout << "■■■■■■■■■■　■　■　■■■■■■■■■■■■■■■■■■■■■■" << endl;
	cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;
	cout << "　　　　　　　　　　　"; SetColor(14, 15); cout << "　■　　"; SetColor(12, 15); cout << "　■　"; SetColor(0, 15); cout << "　　　　　　　　　　　■■■■■■■■" << endl;
	cout << "　　　　　　　　　　　"; SetColor(14, 15); cout << "■■■　"; SetColor(12, 15); cout << "■■■"; SetColor(0, 15); cout << "　　　　　　　　　　　　■■■■■■■" << endl;
	cout << "　　　　　　　　　　　"; SetColor(14, 15); cout << "　■　　"; SetColor(12, 15); cout << "　■　"; SetColor(0, 15); cout << "　　　　　　　　　　　　■■■■■■■" << endl;
	cout << "　　　　　　　　　　　"; SetColor(14, 15); cout << "■　■　"; SetColor(12, 15); cout << "■　■"; SetColor(0, 15); cout << "　　　　　　　　　　　　　■■■■■■" << endl;
	cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■■■■■" << endl;
	cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■　　　　　　　■■■■" << endl;
	cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■　　　　　　■■■■" << endl;
	cout << "■■■■■　　　　　　　　　　　　　　　　　　　　　　　　　　　　■■■■" << endl;
	cout << "■■■■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■■■■" << endl;
	cout << "■■■■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■■■■" << endl;
	cout << "■■■■　　　　　　　　　　　　　　　　　　　　　　　　　　　　■■■■■" << endl;
	cout << "■■■■　　　　　　■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;
	cout << "■■■■　　　　　　　■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;
	cout << "■■■■　　　　　　　　　　　　　　　　　　　　　　　　　■■■■■■■■" << endl;
	cout << "■■■■■　　　　　　　　　　　　　　　　　　　　　　　　　■■■■■■■" << endl;
	cout << "■■■■■■　　　　　　　　　　　　　　　　　　　　　　　　　■■■■■■" << endl;
	cout << "■■■■■■　　　　　　　　　　　　　　　　　　　　　　　　　　■■■■■" << endl;
	cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■　　　　　　■■■■■" << endl;
	cout << "■■■■■■■　　　　　　　　　　　　　　　　　　　　　　　　　■■■■■" << endl;
	cout << "■■■■■■　　　　　　　　　　　　　　　　　　　　　　　　　■■■■■■" << endl;
	cout << "■■■■■　　　　　　　　　　　　　　　　　　　　　　　　　■■■■■■■" << endl;
	cout << "■■■■　　　　　　　　　　　　　　　　　　　　　　　　　■■■■■■■■" << endl;
	cout << "■■■　　　　　　　　■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;
	cout << "■■　　　　　　　　■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;
	cout << "■　　　　　　　　■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;
	cout << "■　　　　　　　■■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;
	cout << "■　　　　　　　■■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;
	cout << "■■　　　　　　　■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;
	cout << "■■■　　　　　　　■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;

	Sleep(1200);

	gotoxy(0, 0);
	SetColor(0, 15);

	cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;
	cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;
	cout << "■■■■■■■■■■　　　　　■■■■■■■■■■■■■■■■■■■■■■" << endl;
	cout << "■■■■■■■■■■　　　　　■■■■■■■■■■■■■■■■■■■■■■" << endl;
	cout << "■■■■■■■■■■　　　　　■■■■■■■■■■■■■■■■■■■■■■" << endl;
	cout << "■■■■■■■■■■　■■■　■■■■■■■■■■■■■■■■■■■■■■" << endl;
	cout << "■■■■■■■■■■　■　■　■■■■■■■■■■■■■■■■■■■■■■" << endl;
	cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;
	cout << "　　　　　　　　　　　"; SetColor(14, 15); cout << "　■　"; SetColor(0, 15); cout << "　　　　　　　　　　　　　　　■■■■■■■■" << endl;
	cout << "　　　　　　　　　　　"; SetColor(14, 15); cout << "■■■"; SetColor(0, 15); cout << "　　　　　　　　　　　　　　　　■■■■■■■" << endl;
	cout << "　　　　　　　　　　　"; SetColor(14, 15); cout << "　■　"; SetColor(0, 15); cout << "　　　　　　　　　　　　　　　　■■■■■■■" << endl;
	cout << "　　　　　　　　　　　"; SetColor(14, 15); cout << "■　■"; SetColor(0, 15); cout << "　　　　　　　　　　　　　　　　　■■■■■■" << endl;
	cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■■■■■" << endl;
	cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■　　　　　　　■■■■" << endl;
	cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■　"; SetColor(12, 15); cout << "　■　"; SetColor(0, 15); cout << "　　■■■■" << endl;
	cout << "■■■■■　　　　　　　　　　　　　　　　　　　　　　　"; SetColor(12, 15); cout << "■■■"; SetColor(0, 15); cout << "　　■■■■" << endl;
	cout << "■■■■　　　　　　　　　　　　　　　　　　　　　　　　"; SetColor(12, 15); cout << "　■　"; SetColor(0, 15); cout << "　　■■■■" << endl;
	cout << "■■■■　　　　　　　　　　　　　　　　　　　　　　　　"; SetColor(12, 15); cout << "■　■"; SetColor(0, 15); cout << "　　■■■■" << endl;
	cout << "■■■■　　　　　　　　　　　　　　　　　　　　　　　　　　　　■■■■■" << endl;
	cout << "■■■■　　　　　　■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;
	cout << "■■■■　　　　　　　■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;
	cout << "■■■■　　　　　　　　　　　　　　　　　　　　　　　　　■■■■■■■■" << endl;
	cout << "■■■■■　　　　　　　　　　　　　　　　　　　　　　　　　■■■■■■■" << endl;
	cout << "■■■■■■　　　　　　　　　　　　　　　　　　　　　　　　　■■■■■■" << endl;
	cout << "■■■■■■　　　　　　　　　　　　　　　　　　　　　　　　　　■■■■■" << endl;
	cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■　　　　　　■■■■■" << endl;
	cout << "■■■■■■■　　　　　　　　　　　　　　　　　　　　　　　　　■■■■■" << endl;
	cout << "■■■■■■　　　　　　　　　　　　　　　　　　　　　　　　　■■■■■■" << endl;
	cout << "■■■■■　　　　　　　　　　　　　　　　　　　　　　　　　■■■■■■■" << endl;
	cout << "■■■■　　　　　　　　　　　　　　　　　　　　　　　　　■■■■■■■■" << endl;
	cout << "■■■　　　　　　　　■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;
	cout << "■■　　　　　　　　■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;
	cout << "■　　　　　　　　■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;
	cout << "■　　　　　　　■■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;
	cout << "■　　　　　　　■■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;
	cout << "■■　　　　　　　■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;
	cout << "■■■　　　　　　　■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;

	Sleep(1200);

	gotoxy(0, 0);
	SetColor(0, 15);

	cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;
	cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;
	cout << "■■■■■■■■■■　　　　　■■■■■■■■■■■■■■■■■■■■■■" << endl;
	cout << "■■■■■■■■■■　　　　　■■■■■■■■■■■■■■■■■■■■■■" << endl;
	cout << "■■■■■■■■■■　　　　　■■■■■■■■■■■■■■■■■■■■■■" << endl;
	cout << "■■■■■■■■■■　■■■　■■■■■■■■■■■■■■■■■■■■■■" << endl;
	cout << "■■■■■■■■■■　■　■　■■■■■■■■■■■■■■■■■■■■■■" << endl;
	cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;
	cout << "　　　　　　　　　　　"; SetColor(14, 15); cout << "　■　"; SetColor(0, 15); cout << "　　　　　　　　　　　　　　　■■■■■■■■" << endl;
	cout << "　　　　　　　　　　　"; SetColor(14, 15); cout << "■■■"; SetColor(0, 15); cout << "　　　　　　　　　　　　　　　　■■■■■■■" << endl;
	cout << "　　　　　　　　　　　"; SetColor(14, 15); cout << "　■　"; SetColor(0, 15); cout << "　　　　　　　　　　　　　　　　■■■■■■■" << endl;
	cout << "　　　　　　　　　　　"; SetColor(14, 15); cout << "■　■"; SetColor(0, 15); cout << "　　　　　　　　　　　　　　　　　■■■■■■" << endl;
	cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■■■■■" << endl;
	cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■　　　　　　　■■■■" << endl;
	cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■　　　　　　■■■■" << endl;
	cout << "■■■■■　　　　　　　　　　　　　　　　　　　　　　　　　　　　■■■■" << endl;
	cout << "■■■■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■■■■" << endl;
	cout << "■■■■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■■■■" << endl;
	cout << "■■■■　　　　　　　　　　　　　　　　　　　　　　　　　　　　■■■■■" << endl;
	cout << "■■■■　　　　　　■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;
	cout << "■■■■　　"; SetColor(12, 15); cout << "　■　"; SetColor(0, 15); cout << "　　■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;
	cout << "■■■■　　"; SetColor(12, 15); cout << "■■■"; SetColor(0, 15); cout << "　　　　　　　　　　　　　　　　　　　　■■■■■■■■" << endl;
	cout << "■■■■■　"; SetColor(12, 15); cout << "　■　"; SetColor(0, 15); cout << "　　　　　　　　　　　　　　　　　　　　　■■■■■■■" << endl;
	cout << "■■■■■■"; SetColor(12, 15); cout << "■　■"; SetColor(0, 15); cout << "　　　　　　　　　　　　　　　　　　　　　　■■■■■■" << endl;
	cout << "■■■■■■　　　　　　　　　　　　　　　　　　　　　　　　　　■■■■■" << endl;
	cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■　　　　　　■■■■■" << endl;
	cout << "■■■■■■■　　　　　　　　　　　　　　　　　　　　　　　　　■■■■■" << endl;
	cout << "■■■■■■　　　　　　　　　　　　　　　　　　　　　　　　　■■■■■■" << endl;
	cout << "■■■■■　　　　　　　　　　　　　　　　　　　　　　　　　■■■■■■■" << endl;
	cout << "■■■■　　　　　　　　　　　　　　　　　　　　　　　　　■■■■■■■■" << endl;
	cout << "■■■　　　　　　　　■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;
	cout << "■■　　　　　　　　■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;
	cout << "■　　　　　　　　■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;
	cout << "■　　　　　　　■■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;
	cout << "■　　　　　　　■■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;
	cout << "■■　　　　　　　■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;
	cout << "■■■　　　　　　　■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;

	Sleep(1200);

	gotoxy(0, 0);
	SetColor(0, 15);

	cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;
	cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;
	cout << "■■■■■■■■■■　　　　　■■■■■■■■■■■■■■■■■■■■■■" << endl;
	cout << "■■■■■■■■■■　　　　　■■■■■■■■■■■■■■■■■■■■■■" << endl;
	cout << "■■■■■■■■■■　　　　　■■■■■■■■■■■■■■■■■■■■■■" << endl;
	cout << "■■■■■■■■■■　■■■　■■■■■■■■■■■■■■■■■■■■■■" << endl;
	cout << "■■■■■■■■■■　■　■　■■■■■■■■■■■■■■■■■■■■■■" << endl;
	cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;
	cout << "　　　　　　　　　　　"; SetColor(14, 15); cout << "　■　"; SetColor(0, 15); cout << "　　　　　　　　　　　　　　　■■■■■■■■" << endl;
	cout << "　　　　　　　　　　　"; SetColor(14, 15); cout << "■■■"; SetColor(0, 15); cout << "　　　　　　　　　　　　　　　　■■■■■■■" << endl;
	cout << "　　　　　　　　　　　"; SetColor(14, 15); cout << "　■　"; SetColor(0, 15); cout << "　　　　　　　　　　　　　　　　■■■■■■■" << endl;
	cout << "　　　　　　　　　　　"; SetColor(14, 15); cout << "■　■"; SetColor(0, 15); cout << "　　　　　　　　　　　　　　　　　■■■■■■" << endl;
	cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■■■■■" << endl;
	cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■　　　　　　　■■■■" << endl;
	cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■　　　　　　■■■■" << endl;
	cout << "■■■■■　　　　　　　　　　　　　　　　　　　　　　　　　　　　■■■■" << endl;
	cout << "■■■■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■■■■" << endl;
	cout << "■■■■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■■■■" << endl;
	cout << "■■■■　　　　　　　　　　　　　　　　　　　　　　　　　　　　■■■■■" << endl;
	cout << "■■■■　　　　　　■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;
	cout << "■■■■　　　　　　　■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;
	cout << "■■■■　　　　　　　　　　　　　　　　　　　　　　　　　■■■■■■■■" << endl;
	cout << "■■■■■　　　　　　　　　　　　　　　　　　　　　　　　　■■■■■■■" << endl;
	cout << "■■■■■■　　　　　　　　　　　　　　　　　　　　　　　　　■■■■■■" << endl;
	cout << "■■■■■■　　　　　　　　　　　　　　　　　　　　　　　　　　■■■■■" << endl;
	cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■"; SetColor(12, 15); cout << "　■　"; SetColor(0, 15); cout << "　　　■■■■■" << endl;
	cout << "■■■■■■■　　　　　　　　　　　　　　　　　　　"; SetColor(12, 15); cout << "■■■"; SetColor(0, 15); cout << "　　　■■■■■" << endl;
	cout << "■■■■■■　　　　　　　　　　　　　　　　　　　　"; SetColor(12, 15); cout << "　■　"; SetColor(0, 15); cout << "　　■■■■■■" << endl;
	cout << "■■■■■　　　　　　　　　　　　　　　　　　　　　"; SetColor(12, 15); cout << "■　■"; SetColor(0, 15); cout << "　■■■■■■■" << endl;
	cout << "■■■■　　　　　　　　　　　　　　　　　　　　　　　　　■■■■■■■■" << endl;
	cout << "■■■　　　　　　　　■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;
	cout << "■■　　　　　　　　■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;
	cout << "■　　　　　　　　■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;
	cout << "■　　　　　　　■■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;
	cout << "■　　　　　　　■■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;
	cout << "■■　　　　　　　■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;
	cout << "■■■　　　　　　　■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;

	Sleep(1200);

	gotoxy(0, 0);
	SetColor(0, 15);

	cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;
	cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;
	cout << "■■■■■■■■■■　　　　　■■■■■■■■■■■■■■■■■■■■■■" << endl;
	cout << "■■■■■■■■■■　　　　　■■■■■■■■■■■■■■■■■■■■■■" << endl;
	cout << "■■■■■■■■■■　　　　　■■■■■■■■■■■■■■■■■■■■■■" << endl;
	cout << "■■■■■■■■■■　■■■　■■■■■■■■■■■■■■■■■■■■■■" << endl;
	cout << "■■■■■■■■■■　■　■　■■■■■■■■■■■■■■■■■■■■■■" << endl;
	cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;
	cout << "　　　　　　　　　　　"; SetColor(14, 15); cout << "　■　"; SetColor(0, 15); cout << "　　　　　　　　　　　　　　　■■■■■■■■" << endl;
	cout << "　　　　　　　　　　　"; SetColor(14, 15); cout << "■■■"; SetColor(0, 15); cout << "　　　　　　　　　　　　　　　　■■■■■■■" << endl;
	cout << "　　　　　　　　　　　"; SetColor(14, 15); cout << "　■　"; SetColor(0, 15); cout << "　　　　　　　　　　　　　　　　■■■■■■■" << endl;
	cout << "　　　　　　　　　　　"; SetColor(14, 15); cout << "■　■"; SetColor(0, 15); cout << "　　　　　　　　　　　　　　　　　■■■■■■" << endl;
	cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■■■■■" << endl;
	cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■　　　　　　　■■■■" << endl;
	cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■　　　　　　■■■■" << endl;
	cout << "■■■■■　　　　　　　　　　　　　　　　　　　　　　　　　　　　■■■■" << endl;
	cout << "■■■■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■■■■" << endl;
	cout << "■■■■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■■■■" << endl;
	cout << "■■■■　　　　　　　　　　　　　　　　　　　　　　　　　　　　■■■■■" << endl;
	cout << "■■■■　　　　　　■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;
	cout << "■■■■　　　　　　　■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;
	cout << "■■■■　　　　　　　　　　　　　　　　　　　　　　　　　■■■■■■■■" << endl;
	cout << "■■■■■　　　　　　　　　　　　　　　　　　　　　　　　　■■■■■■■" << endl;
	cout << "■■■■■■　　　　　　　　　　　　　　　　　　　　　　　　　■■■■■■" << endl;
	cout << "■■■■■■　　　　　　　　　　　　　　　　　　　　　　　　　　■■■■■" << endl;
	cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■　　　　　　■■■■■" << endl;
	cout << "■■■■■■■　　　　　　　　　　　　　　　　　　　　　　　　　■■■■■" << endl;
	cout << "■■■■■■　　　　　　　　　　　　　　　　　　　　　　　　　■■■■■■" << endl;
	cout << "■■■■■　　　　　　　　　　　　　　　　　　　　　　　　　■■■■■■■" << endl;
	cout << "■■■■　　　　　　　　　　　　　　　　　　　　　　　　　■■■■■■■■" << endl;
	cout << "■■■　　　　　　　　■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;
	cout << "■■　　　　　　　　■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;
	cout << "■　　　　　　　　■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;
	cout << "■　　　"; SetColor(12, 15); cout << "　■　"; SetColor(0, 15); cout << "　■■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;
	cout << "■　　　"; SetColor(12, 15); cout << "■■■"; SetColor(0, 15); cout << "　■■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;
	cout << "■■　　"; SetColor(12, 15); cout << "　■　"; SetColor(0, 15); cout << "　　■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;
	cout << "■■■　"; SetColor(12, 15); cout << "■　■"; SetColor(0, 15); cout << "　　　■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;

	Sleep(1200);

	gotoxy(0, 0);
	SetColor(0, 15);

	cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;
	cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;
	cout << "■■■■■■■■■■　　　　　■■■■■■■■■■■■■■■■■■■■■■" << endl;
	cout << "■■■■■■■■■■　　　　　■■■■■■■■■■■■■■■■■■■■■■" << endl;
	cout << "■■■■■■■■■■　　　　　■■■■■■■■■■■■■■■■■■■■■■" << endl;
	cout << "■■■■■■■■■■　■■■　■■■■■■■■■■■■■■■■■■■■■■" << endl;
	cout << "■■■■■■■■■■　■　■　■■■■■■■■■■■■■■■■■■■■■■" << endl;
	cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;
	cout << "　　　　　　　　　　　"; SetColor(14, 15); cout << "　■　"; SetColor(0, 15); cout << "　　　　　　　　　　　　　　　■■■■■■■■" << endl;
	cout << "　　　　　　　　　　　"; SetColor(14, 15); cout << "■■■"; SetColor(0, 15); cout << "　　　　　　　　　　　　　　　　■■■■■■■" << endl;
	cout << "　　　　　　　　　　　"; SetColor(14, 15); cout << "　■　"; SetColor(0, 15); cout << "　　　　　　　　　　　　　　　　■■■■■■■" << endl;
	cout << "　　　　　　　　　　　"; SetColor(14, 15); cout << "■　■"; SetColor(0, 15); cout << "　　　　　　　　　　　　　　　　　■■■■■■" << endl;
	cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■■■■■" << endl;
	cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■　　　　　　　■■■■" << endl;
	cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■　　　　　　■■■■" << endl;
	cout << "■■■■■　　　　　　　　　　　　　　　　　　　　　　　　　　　　■■■■" << endl;
	cout << "■■■■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■■■■" << endl;
	cout << "■■■■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■■■■" << endl;
	cout << "■■■■　　　　　　　　　　　　　　　　　　　　　　　　　　　　■■■■■" << endl;
	cout << "■■■■　　　　　　■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;
	cout << "■■■■　　　　　　　■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;
	cout << "■■■■　　　　　　　　　　　　　　　　　　　　　　　　　■■■■■■■■" << endl;
	cout << "■■■■■　　　　　　　　　　　　　　　　　　　　　　　　　■■■■■■■" << endl;
	cout << "■■■■■■　　　　　　　　　　　　　　　　　　　　　　　　　■■■■■■" << endl;
	cout << "■■■■■■　　　　　　　　　　　　　　　　　　　　　　　　　　■■■■■" << endl;
	cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■　　　　　　■■■■■" << endl;
	cout << "■■■■■■■　　　　　　　　　　　　　　　　　　　　　　　　　■■■■■" << endl;
	cout << "■■■■■■　　　　　　　　　　　　　　　　　　　　　　　　　■■■■■■" << endl;
	cout << "■■■■■　　　　　　　　　　　　　　　　　　　　　　　　　■■■■■■■" << endl;
	cout << "■■■■　　　　　　　　　　　　　　　　　　　　　　　　　■■■■■■■■" << endl;
	cout << "■■■　　　　　　　　■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;
	cout << "■■　　　　　　　　■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;
	cout << "■　　　　　　　　■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;
	cout << "■　　　　　　　■■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;
	cout << "■　　　　　　　■■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;
	cout << "■■　　　　　　　■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;
	cout << "■■■　　　　　　　■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;

	Sleep(1500);

	gotoxy(0, 0);
	SetColor(0, 15);

	cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;
	cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;
	cout << "■■■■■■■■■■　　　　　■■■■■■■■■■■■■■■■■■■■■■" << endl;
	cout << "■■■■■■■■■■　　　　　■■■■■■■■■■■■■■■■■■■■■■" << endl;
	cout << "■■■■■■■■■■　　　　　■■■■■■■■■■■■■■■■■■■■■■" << endl;
	cout << "■■■■■■■■■■　■■■　■■■■■■■■■■■■■■■■■■■■■■" << endl;
	cout << "■■■■■■■■■■　■　■　■■■■■■■■■■■■■■■■■■■■■■" << endl;
	cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;
	cout << "　　　　　　　　　　　"; SetColor(14, 15); cout << "　■　"; SetColor(0, 15); cout << "　　　　　　　　　　　　　　　■■■■■■■■" << endl;
	cout << "　　　　　　　　　　　"; SetColor(14, 15); cout << "■■■"; SetColor(0, 15); cout << "　　　　　　　　　　　　　　　　■■■■■■■" << endl;
	cout << "　　　　　　　　　　　"; SetColor(14, 15); cout << "　■　"; SetColor(0, 15); cout << "　　　　　　　　　　　　　　　　■■■■■■■" << endl;
	cout << "　　　　　　　　　　　"; SetColor(14, 15); cout << "■　■"; SetColor(0, 15); cout << "　　　　　　　　　　　　　　　　　■■■■■■" << endl;
	cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■■■■■" << endl;
	cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■　　　　　　　■■■■" << endl;
	cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■　　　　　　■■■■" << endl;
	cout << "■■■■■　　　　　　　　　　　　　　　　　　　　　　　　　　　　■■■■" << endl;
	cout << "■■■■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■■■■" << endl;
	cout << "■■■■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■■■■" << endl;
	cout << "■■■■　　　　　　　　　　　　　　　　　　　　　　　　　　　　■■■■■" << endl;
	cout << "■■■■　　　　　　■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;
	cout << "■■■■　　　　　　　■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;
	cout << "■■■■　　　　　　　　　　　　　　　　　　　　　　　　　■■■■■■■■" << endl;
	cout << "■■■■■　　　　　　　　　　　　　　　　　　　　　　　　　■■■■■■■" << endl;
	cout << "■■■■■■　　　　　　　　　　　　　　　　　　　　　　　　　■■■■■■" << endl;
	cout << "■■■■■■　　　　　　　　　　　　　　　　　　　　　　　　　　■■■■■" << endl;
	cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■　　　　　　■■■■■" << endl;

	SetColor(13, 15);

	cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;
	cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
	cout << "■"; SetColor(0, 15); cout << "　　[아타호]　　　　　　　　　　　　　　　　　　　　　　　　　　　　　"; SetColor(13, 15); cout << "■" << endl;
	cout << "■"; SetColor(0, 15); cout << "　　허허 나에게 편지라니 대체 누가 보낸거지?   　 　　　　　　　　　　"; SetColor(13, 15); cout << "■" << endl;
	cout << "■"; SetColor(0, 15); cout << "　　일단 들어가서 확인하자　　　　　　　　　　　　　　　　　　　　　　"; SetColor(13, 15); cout << "■" << endl;
	cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
	cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
	cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
	cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
	cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
	cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;

	Conversation();

	gotoxy(0, 0);
	SetColor(0, 15);

	cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;
	cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;
	cout << "■■■■■■■■■■　　　　　■■■■■■■■■■■■■■■■■■■■■■" << endl;
	cout << "■■■■■■■■■■　　　　　■■■■■■■■■■■■■■■■■■■■■■" << endl;
	cout << "■■■■■■■■■■　　　　　■■■■■■■■■■■■■■■■■■■■■■" << endl;
	cout << "■■■■■■■■■■　■■■　■■■■■■■■■■■■■■■■■■■■■■" << endl;
	cout << "■■■■■■■■■■　■　■　■■■■■■■■■■■■■■■■■■■■■■" << endl;
	cout << "■■■■■■■■■■■■　■■■■■■■■■■■■■■■■■■■■■■■■" << endl;
	cout << "　　　　　　　　　　　"; SetColor(14, 15); cout << "　■　"; SetColor(0, 15); cout << "　　　　　　　　　　　　　　　■■■■■■■■" << endl;
	cout << "　　　　　　　　　　　"; SetColor(14, 15); cout << "■■■"; SetColor(0, 15); cout << "　　　　　　　　　　　　　　　　■■■■■■■" << endl;
	cout << "　　　　　　　　　　　"; SetColor(14, 15); cout << "　■　"; SetColor(0, 15); cout << "　　　　　　　　　　　　　　　　■■■■■■■" << endl;
	cout << "　　　　　　　　　　　"; SetColor(14, 15); cout << "■　■"; SetColor(0, 15); cout << "　　　　　　　　　　　　　　　　　■■■■■■" << endl;
	cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■■■■■" << endl;
	cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■　　　　　　　■■■■" << endl;
	cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■　　　　　　■■■■" << endl;
	cout << "■■■■■　　　　　　　　　　　　　　　　　　　　　　　　　　　　■■■■" << endl;
	cout << "■■■■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■■■■" << endl;
	cout << "■■■■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■■■■" << endl;
	cout << "■■■■　　　　　　　　　　　　　　　　　　　　　　　　　　　　■■■■■" << endl;
	cout << "■■■■　　　　　　■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;
	cout << "■■■■　　　　　　　■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;
	cout << "■■■■　　　　　　　　　　　　　　　　　　　　　　　　　■■■■■■■■" << endl;
	cout << "■■■■■　　　　　　　　　　　　　　　　　　　　　　　　　■■■■■■■" << endl;
	cout << "■■■■■■　　　　　　　　　　　　　　　　　　　　　　　　　■■■■■■" << endl;
	cout << "■■■■■■　　　　　　　　　　　　　　　　　　　　　　　　　　■■■■■" << endl;
	cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■　　　　　　■■■■■" << endl;
	cout << "■■■■■■■　　　　　　　　　　　　　　　　　　　　　　　　　■■■■■" << endl;
	cout << "■■■■■■　　　　　　　　　　　　　　　　　　　　　　　　　■■■■■■" << endl;
	cout << "■■■■■　　　　　　　　　　　　　　　　　　　　　　　　　■■■■■■■" << endl;
	cout << "■■■■　　　　　　　　　　　　　　　　　　　　　　　　　■■■■■■■■" << endl;
	cout << "■■■　　　　　　　　■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;
	cout << "■■　　　　　　　　■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;
	cout << "■　　　　　　　　■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;
	cout << "■　　　　　　　■■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;
	cout << "■　　　　　　　■■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;
	cout << "■■　　　　　　　■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;
	cout << "■■■　　　　　　　■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;


	_effect = Edooropen;

	Sleep(800);
}
void mainGame::StartEvent2()
{
	Move();

	gotoxy(0, 0);
	SetColor(0, 15);

	cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;	// 1
	cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;	// 2
	cout << "■■■■■■■■■■■■■■■　　　　　　　■■■■■■■■■■■■■■■" << endl;	// 3
	cout << "■■■■■■■■■■■■■■■　　　　　　　■■■■■■■■■■■■■■■" << endl;	// 4
	cout << "■■■■■■■■■■■■■■■　　□□□　　■■■■■■■■■■■■■■■" << endl;	// 5
	cout << "■■■■■■■■■■■■■■■　　□□□　　■■■■■■■■■■■■■■■" << endl;	// 6
	cout << "■■■■■■■■■■■■■■■　　□□□　　■■■■■■■■■■■■■■■" << endl;	// 7
	cout << "■■■■■■■■■■■■■■■　　　　　　　■■■■■■■■■■■■■■■" << endl;	// 8
	cout << "■■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■■" << endl;	// 9
	cout << "■■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■■" << endl;	// 10
	cout << "■■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■■" << endl;	// 11
	cout << "■■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■■" << endl;	// 12
	cout << "■■　　■■■■■■■■■■■　　　　　　　　　　　　　　　　　　　　■■" << endl;	// 13
	cout << "■■　　■　　　　　　　　　■　　　　　　　　　　　　　　　　　　　　■■" << endl;	// 14
	cout << "■■　　■■■■　　　　　　■　　　　　　　　　　　　　　　　　　　　■■" << endl;	// 15
	cout << "■■　　■■　■　　　　　　■　　　　　　　　　　　　　　　　　　　　■■" << endl;	// 16
	cout << "■■　　■■　■　　　　　　■　　　　　　　　　　　　　　　　　　　　■■" << endl;	// 17
	cout << "■■　　■■■■　　　　　　■　　　　　　　　　　　　　　　　　　　　■■" << endl;	// 18
	cout << "■■　　■　　　　　　　　　■　　　　　　　　　　　　　　　　　　　　■■" << endl;	// 19
	cout << "■■　　■■■■■■■■■■■　　　　　　　　　　　　　　　　　　　　■■" << endl;	// 20
	cout << "■■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■■" << endl;	// 21
	cout << "■■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■■" << endl;	// 22
	cout << "■■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■■" << endl;	// 23
	cout << "■■■■■■■■■■■■■■■■　　　■■■■■■■■■■■■■■■■■■" << endl;	// 24
	cout << "■■■■■■■■■■■■■■■■　　　■■■■■■■■■■■■■■■■■■" << endl;	// 25
	cout << "■■■■■■■■■■■■■■■■　　　■■■■■■■■■■■■■■■■■■" << endl;	// 26
	cout << "■■■■■■■■■■■■■■■■　　　■■■■■■■■■■■■■■■■■■" << endl;	// 27
	cout << "■■■■■■■■■■■■■■■■　　　■■■■■■■■■■■■■■■■■■" << endl;	// 28
	cout << "■■■■■■■■■■■■■■■　　　　■■■■■■■■■■■■■■■■■■" << endl;	// 29
	cout << "■■■■■■■■■■■■■■■　　　■■■■■■■■■■■■■■■■■■■" << endl;	// 30
	cout << "■■■■■■■■■■■■■■■　　　■■■■■■■■■■■■■■■■■■■" << endl;	// 31
	cout << "■■■■■■■■■■■■■■■"; SetColor(14, 15); cout << "　■　"; SetColor(0, 15); cout << "■■■■■■■■■■■■■■■■■■■" << endl;	// 32
	cout << "■■■■■■■■■■■■■■■"; SetColor(14, 15); cout << "■■■"; SetColor(0, 15); cout << "■■■■■■■■■■■■■■■■■■■" << endl;	// 33
	cout << "■■■■■■■■■■■■■■■"; SetColor(14, 15); cout << "　■　"; SetColor(0, 15); cout << "■■■■■■■■■■■■■■■■■■■" << endl;	// 34
	cout << "■■■■■■■■■■■■■■■"; SetColor(14, 15); cout << "■　■"; SetColor(0, 15); cout << "■■■■■■■■■■■■■■■■■■■" << endl;	// 35
	cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;	// 36
	cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;	// 37

	Sleep(1200);

	gotoxy(0, 0);
	SetColor(0, 15);

	cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;	// 1
	cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;	// 2
	cout << "■■■■■■■■■■■■■■■　　　　　　　■■■■■■■■■■■■■■■" << endl;	// 3
	cout << "■■■■■■■■■■■■■■■　　　　　　　■■■■■■■■■■■■■■■" << endl;	// 4
	cout << "■■■■■■■■■■■■■■■　　□□□　　■■■■■■■■■■■■■■■" << endl;	// 5
	cout << "■■■■■■■■■■■■■■■　　□□□　　■■■■■■■■■■■■■■■" << endl;	// 6
	cout << "■■■■■■■■■■■■■■■　　□□□　　■■■■■■■■■■■■■■■" << endl;	// 7
	cout << "■■■■■■■■■■■■■■■　　　　　　　■■■■■■■■■■■■■■■" << endl;	// 8
	cout << "■■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■■" << endl;	// 9
	cout << "■■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■■" << endl;	// 10
	cout << "■■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■■" << endl;	// 11
	cout << "■■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■■" << endl;	// 12
	cout << "■■　　■■■■■■■■■■■　　　　　　　　　　　　　　　　　　　　■■" << endl;	// 13
	cout << "■■　　■　　　　　　　　　■　　　　　　　　　　　　　　　　　　　　■■" << endl;	// 14
	cout << "■■　　■■■■　　　　　　■　　　　　　　　　　　　　　　　　　　　■■" << endl;	// 15
	cout << "■■　　■■　■　　　　　　■　　　　　　　　　　　　　　　　　　　　■■" << endl;	// 16
	cout << "■■　　■■　■　　　　　　■　　　　　　　　　　　　　　　　　　　　■■" << endl;	// 17
	cout << "■■　　■■■■　　　　　　■　　　　　　　　　　　　　　　　　　　　■■" << endl;	// 18
	cout << "■■　　■　　　　　　　　　■　　　　　　　　　　　　　　　　　　　　■■" << endl;	// 19
	cout << "■■　　■■■■■■■■■■■　　　　　　　　　　　　　　　　　　　　■■" << endl;	// 20
	cout << "■■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■■" << endl;	// 21
	cout << "■■　　　　　　　　　　　　　　"; SetColor(14, 15); cout << "　■　"; SetColor(0, 15); cout << "　　　　　　　　　　　　　　　　■■" << endl;	// 22
	cout << "■■　　　　　　　　　　　　　　"; SetColor(14, 15); cout << "■■■"; SetColor(0, 15); cout << "　　　　　　　　　　　　　　　　■■" << endl;	// 23
	cout << "■■■■■■■■■■■■■■■■"; SetColor(14, 15); cout << "　■　"; SetColor(0, 15); cout << "■■■■■■■■■■■■■■■■■■" << endl;	// 24
	cout << "■■■■■■■■■■■■■■■■"; SetColor(14, 15); cout << "■　■"; SetColor(0, 15); cout << "■■■■■■■■■■■■■■■■■■" << endl;	// 25
	cout << "■■■■■■■■■■■■■■■■　　　■■■■■■■■■■■■■■■■■■" << endl;	// 26
	cout << "■■■■■■■■■■■■■■■■　　　■■■■■■■■■■■■■■■■■■" << endl;	// 27
	cout << "■■■■■■■■■■■■■■■■　　　■■■■■■■■■■■■■■■■■■" << endl;	// 28
	cout << "■■■■■■■■■■■■■■■　　　　■■■■■■■■■■■■■■■■■■" << endl;	// 29
	cout << "■■■■■■■■■■■■■■■　　　■■■■■■■■■■■■■■■■■■■" << endl;	// 30
	cout << "■■■■■■■■■■■■■■■　　　■■■■■■■■■■■■■■■■■■■" << endl;	// 31
	cout << "■■■■■■■■■■■■■■■　　　■■■■■■■■■■■■■■■■■■■" << endl;	// 32
	cout << "■■■■■■■■■■■■■■■　　　■■■■■■■■■■■■■■■■■■■" << endl;	// 33
	cout << "■■■■■■■■■■■■■■■　　　■■■■■■■■■■■■■■■■■■■" << endl;	// 34
	cout << "■■■■■■■■■■■■■■■　　　■■■■■■■■■■■■■■■■■■■" << endl;	// 35
	cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;	// 36
	cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;	// 37

	Sleep(1200);

	gotoxy(0, 0);
	SetColor(0, 15);

	cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;	// 1
	cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;	// 2
	cout << "■■■■■■■■■■■■■■■　　　　　　　■■■■■■■■■■■■■■■" << endl;	// 3
	cout << "■■■■■■■■■■■■■■■　　　　　　　■■■■■■■■■■■■■■■" << endl;	// 4
	cout << "■■■■■■■■■■■■■■■　　□□□　　■■■■■■■■■■■■■■■" << endl;	// 5
	cout << "■■■■■■■■■■■■■■■　　□□□　　■■■■■■■■■■■■■■■" << endl;	// 6
	cout << "■■■■■■■■■■■■■■■　　□□□　　■■■■■■■■■■■■■■■" << endl;	// 7
	cout << "■■■■■■■■■■■■■■■　　　　　　　■■■■■■■■■■■■■■■" << endl;	// 8
	cout << "■■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■■" << endl;	// 9
	cout << "■■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■■" << endl;	// 10
	cout << "■■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■■" << endl;	// 11
	cout << "■■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■■" << endl;	// 12
	cout << "■■　　■■■■■■■■■■■　　　　　　　　　　　　　　　　　　　　■■" << endl;	// 13
	cout << "■■　　■　　　　　　　　　■　　　　　　　　　　　　　　　　　　　　■■" << endl;	// 14
	cout << "■■　　■■■■　"; SetColor(14, 15); cout << "　■　　　"; SetColor(0, 15); cout << "■　　　　　　　　　　　　　　　　　　　　■■" << endl;	// 15
	cout << "■■　　■■　■　"; SetColor(14, 15); cout << "■■■　　"; SetColor(0, 15); cout << "■　　　　　　　　　　　　　　　　　　　　■■" << endl;	// 16
	cout << "■■　　■■　■　"; SetColor(14, 15); cout << "　■　　　"; SetColor(0, 15); cout << "■　　　　　　　　　　　　　　　　　　　　■■" << endl;	// 17
	cout << "■■　　■■■■　"; SetColor(14, 15); cout << "■　■　　"; SetColor(0, 15); cout << "■　　　　　　　　　　　　　　　　　　　　■■" << endl;	// 18
	cout << "■■　　■　　　　　　　　　■　　　　　　　　　　　　　　　　　　　　■■" << endl;	// 19
	cout << "■■　　■■■■■■■■■■■　　　　　　　　　　　　　　　　　　　　■■" << endl;	// 20
	cout << "■■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■■" << endl;	// 21
	cout << "■■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■■" << endl;	// 22
	cout << "■■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■■" << endl;	// 23
	cout << "■■■■■■■■■■■■■■■■　　　■■■■■■■■■■■■■■■■■■" << endl;	// 24
	cout << "■■■■■■■■■■■■■■■■　　　■■■■■■■■■■■■■■■■■■" << endl;	// 25
	cout << "■■■■■■■■■■■■■■■■　　　■■■■■■■■■■■■■■■■■■" << endl;	// 26
	cout << "■■■■■■■■■■■■■■■■　　　■■■■■■■■■■■■■■■■■■" << endl;	// 27
	cout << "■■■■■■■■■■■■■■■■　　　■■■■■■■■■■■■■■■■■■" << endl;	// 28
	cout << "■■■■■■■■■■■■■■■　　　　■■■■■■■■■■■■■■■■■■" << endl;	// 29
	cout << "■■■■■■■■■■■■■■■　　　■■■■■■■■■■■■■■■■■■■" << endl;	// 30
	cout << "■■■■■■■■■■■■■■■　　　■■■■■■■■■■■■■■■■■■■" << endl;	// 31
	cout << "■■■■■■■■■■■■■■■　　　■■■■■■■■■■■■■■■■■■■" << endl;	// 32
	cout << "■■■■■■■■■■■■■■■　　　■■■■■■■■■■■■■■■■■■■" << endl;	// 33
	cout << "■■■■■■■■■■■■■■■　　　■■■■■■■■■■■■■■■■■■■" << endl;	// 34
	cout << "■■■■■■■■■■■■■■■　　　■■■■■■■■■■■■■■■■■■■" << endl;	// 35
	cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;	// 36
	cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;	// 37


	Sleep(1200);

	gotoxy(0, 0);
	SetColor(0, 15);

	cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;	// 1
	cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;	// 2
	cout << "■■■■■■■■■■■■■■■　　　　　　　■■■■■■■■■■■■■■■" << endl;	// 3
	cout << "■■■■■■■■■■■■■■■　　　　　　　■■■■■■■■■■■■■■■" << endl;	// 4
	cout << "■■■■■■■■■■■■■■■　　□□□　　■■■■■■■■■■■■■■■" << endl;	// 5
	cout << "■■■■■■■■■■■■■■■　　□□□　　■■■■■■■■■■■■■■■" << endl;	// 6
	cout << "■■■■■■■■■■■■■■■　　□□□　　■■■■■■■■■■■■■■■" << endl;	// 7
	cout << "■■■■■■■■■■■■■■■　　　　　　　■■■■■■■■■■■■■■■" << endl;	// 8
	cout << "■■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■■" << endl;	// 9
	cout << "■■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■■" << endl;	// 10
	cout << "■■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■■" << endl;	// 11
	cout << "■■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■■" << endl;	// 12
	cout << "■■　　■■■■■■■■■■■　　　　　　　　　　　　　　　　　　　　■■" << endl;	// 13
	cout << "■■　　■　　　　　　　　　■　　　　　　　　　　　　　　　　　　　　■■" << endl;	// 14
	cout << "■■　　■■■■　"; SetColor(14, 15); cout << "　■　　　"; SetColor(0, 15); cout << "■　　　　　　　　　　　　　　　　　　　　■■" << endl;	// 15
	cout << "■■　　■■　■　"; SetColor(14, 15); cout << "■■■　　"; SetColor(0, 15); cout << "■　　　　　　　　　　　　　　　　　　　　■■" << endl;	// 16
	cout << "■■　　■■　■　"; SetColor(14, 15); cout << "　■　　　"; SetColor(0, 15); cout << "■　　　　　　　　　　　　　　　　　　　　■■" << endl;	// 17
	cout << "■■　　■■■■　"; SetColor(14, 15); cout << "■■■　　"; SetColor(0, 15); cout << "■　　　　　　　　　　　　　　　　　　　　■■" << endl;	// 18
	cout << "■■　　■　　　　　　　　　■　　　　　　　　　　　　　　　　　　　　■■" << endl;	// 19
	cout << "■■　　■■■■■■■■■■■　　　　　　　　　　　　　　　　　　　　■■" << endl;	// 20
	cout << "■■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■■" << endl;	// 21
	cout << "■■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■■" << endl;	// 22
	cout << "■■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■■" << endl;	// 23
	cout << "■■■■■■■■■■■■■■■■　　　■■■■■■■■■■■■■■■■■■" << endl;	// 24
	cout << "■■■■■■■■■■■■■■■■　　　■■■■■■■■■■■■■■■■■■" << endl;	// 25
	cout << "■■■■■■■■■■■■■■■■　　　■■■■■■■■■■■■■■■■■■" << endl;	// 26
	cout << "■■■■■■■■■■■■■■■■　　　■■■■■■■■■■■■■■■■■■" << endl;	// 27
	cout << "■■■■■■■■■■■■■■■■　　　■■■■■■■■■■■■■■■■■■" << endl;	// 28
	cout << "■■■■■■■■■■■■■■■　　　　■■■■■■■■■■■■■■■■■■" << endl;	// 29
	cout << "■■■■■■■■■■■■■■■　　　■■■■■■■■■■■■■■■■■■■" << endl;	// 30
	cout << "■■■■■■■■■■■■■■■　　　■■■■■■■■■■■■■■■■■■■" << endl;	// 31
	cout << "■■■■■■■■■■■■■■■　　　■■■■■■■■■■■■■■■■■■■" << endl;	// 32
	cout << "■■■■■■■■■■■■■■■　　　■■■■■■■■■■■■■■■■■■■" << endl;	// 33
	cout << "■■■■■■■■■■■■■■■　　　■■■■■■■■■■■■■■■■■■■" << endl;	// 34
	cout << "■■■■■■■■■■■■■■■　　　■■■■■■■■■■■■■■■■■■■" << endl;	// 35
	cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;	// 36
	cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;	// 37

	Sleep(1500);

	gotoxy(0, 0);
	SetColor(0, 15);

	cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;	// 1
	cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;	// 2
	cout << "■■■■■■■■■■■■■■■　　　　　　　■■■■■■■■■■■■■■■" << endl;	// 3
	cout << "■■■■■■■■■■■■■■■　　　　　　　■■■■■■■■■■■■■■■" << endl;	// 4
	cout << "■■■■■■■■■■■■■■■　　□□□　　■■■■■■■■■■■■■■■" << endl;	// 5
	cout << "■■■■■■■■■■■■■■■　　□□□　　■■■■■■■■■■■■■■■" << endl;	// 6
	cout << "■■■■■■■■■■■■■■■　　□□□　　■■■■■■■■■■■■■■■" << endl;	// 7
	cout << "■■■■■■■■■■■■■■■　　　　　　　■■■■■■■■■■■■■■■" << endl;	// 8
	cout << "■■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■■" << endl;	// 9
	cout << "■■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■■" << endl;	// 10
	cout << "■■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■■" << endl;	// 11
	cout << "■■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■■" << endl;	// 12
	cout << "■■　　■■■■■■■■■■■　　　　　　　　　　　　　　　　　　　　■■" << endl;	// 13
	cout << "■■　　■　　　　　　　　　■　　　　　　　　　　　　　　　　　　　　■■" << endl;	// 14
	cout << "■■　　■■■■　"; SetColor(14, 15); cout << "　■　　　"; SetColor(0, 15); cout << "■　　　　　　　　　　　　　　　　　　　　■■" << endl;	// 15
	cout << "■■　　■■　■　"; SetColor(14, 15); cout << "■■■　　"; SetColor(0, 15); cout << "■　　　　　　　　　　　　　　　　　　　　■■" << endl;	// 16
	cout << "■■　　■■　■　"; SetColor(14, 15); cout << "　■　　　"; SetColor(0, 15); cout << "■　　　　　　　　　　　　　　　　　　　　■■" << endl;	// 17
	cout << "■■　　■■■■　"; SetColor(14, 15); cout << "■■■　　"; SetColor(0, 15); cout << "■　　　　　　　　　　　　　　　　　　　　■■" << endl;	// 18
	cout << "■■　　■　　　　　　　　　■　　　　　　　　　　　　　　　　　　　　■■" << endl;	// 19
	cout << "■■　　■■■■■■■■■■■　　　　　　　　　　　　　　　　　　　　■■" << endl;	// 20
	cout << "■■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■■" << endl;	// 21
	cout << "■■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■■" << endl;	// 22
	cout << "■■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■■" << endl;	// 23
	cout << "■■■■■■■■■■■■■■■■　　　■■■■■■■■■■■■■■■■■■" << endl;	// 24
	cout << "■■■■■■■■■■■■■■■■　　　■■■■■■■■■■■■■■■■■■" << endl;	// 25
	cout << "■■■■■■■■■■■■■■■■　　　■■■■■■■■■■■■■■■■■■" << endl;	// 26

	SetColor(13, 15);

	cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;
	cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
	cout << "■"; SetColor(0, 15); cout << "　　[아타호]　　　　　　　　　　　　　　　　　　　　　　　　　　　　　"; SetColor(13, 15); cout << "■" << endl;
	cout << "■"; SetColor(0, 15); cout << "　　아니 이제보니 내 오랜 벗 호연한테서 온거로군!!　　　 　　　　　　 "; SetColor(13, 15); cout << "■" << endl;
	cout << "■"; SetColor(0, 15); cout << "　　어디 한번 확인해볼까　　　　　　　　　　　　　　　　　　　  　　　"; SetColor(13, 15); cout << "■" << endl;
	cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
	cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
	cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
	cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
	cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
	cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;

	Conversation();

	gotoxy(0, 0);
	SetColor(0, 15);

	cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;	// 1
	cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;	// 2
	cout << "■■■■■■■■■■■■■■■　　　　　　　■■■■■■■■■■■■■■■" << endl;	// 3
	cout << "■■■■■■■■■■■■■■■　　　　　　　■■■■■■■■■■■■■■■" << endl;	// 4
	cout << "■■■■■■■■■■■■■■■　　□□□　　■■■■■■■■■■■■■■■" << endl;	// 5
	cout << "■■■■■■■■■■■■■■■　　□□□　　■■■■■■■■■■■■■■■" << endl;	// 6
	cout << "■■■■■■■■■■■■■■■　　□□□　　■■■■■■■■■■■■■■■" << endl;	// 7
	cout << "■■■■■■■■■■■■■■■　　　　　　　■■■■■■■■■■■■■■■" << endl;	// 8
	cout << "■■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■■" << endl;	// 9
	cout << "■■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■■" << endl;	// 10
	cout << "■■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■■" << endl;	// 11
	cout << "■■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■■" << endl;	// 12
	cout << "■■　　■■■■■■■■■■■　　　　　　　　　　　　　　　　　　　　■■" << endl;	// 13
	cout << "■■　　■　　　　　　　　　■　　　　　　　　　　　　　　　　　　　　■■" << endl;	// 14
	cout << "■■　　■■■■　"; SetColor(14, 15); cout << "　■　　　"; SetColor(0, 15); cout << "■　　　　　　　　　　　　　　　　　　　　■■" << endl;	// 15
	cout << "■■　　■■　■　"; SetColor(14, 15); cout << "■■■　　"; SetColor(0, 15); cout << "■　　　　　　　　　　　　　　　　　　　　■■" << endl;	// 16
	cout << "■■　　■■　■　"; SetColor(14, 15); cout << "　■　　　"; SetColor(0, 15); cout << "■　　　　　　　　　　　　　　　　　　　　■■" << endl;	// 17
	cout << "■■　　■■■■　"; SetColor(14, 15); cout << "■■■　　"; SetColor(0, 15); cout << "■　　　　　　　　　　　　　　　　　　　　■■" << endl;	// 18
	cout << "■■　　■　　　　　　　　　■　　　　　　　　　　　　　　　　　　　　■■" << endl;	// 19
	cout << "■■　　■■■■■■■■■■■　　　　　　　　　　　　　　　　　　　　■■" << endl;	// 20
	cout << "■■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■■" << endl;	// 21
	cout << "■■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■■" << endl;	// 22
	cout << "■■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■■" << endl;	// 23
	cout << "■■■■■■■■■■■■■■■■　　　■■■■■■■■■■■■■■■■■■" << endl;	// 24
	cout << "■■■■■■■■■■■■■■■■　　　■■■■■■■■■■■■■■■■■■" << endl;	// 25
	cout << "■■■■■■■■■■■■■■■■　　　■■■■■■■■■■■■■■■■■■" << endl;	// 26
	cout << "■■■■■■■■■■■■■■■■　　　■■■■■■■■■■■■■■■■■■" << endl;	// 27
	cout << "■■■■■■■■■■■■■■■■　　　■■■■■■■■■■■■■■■■■■" << endl;	// 28
	cout << "■■■■■■■■■■■■■■■　　　　■■■■■■■■■■■■■■■■■■" << endl;	// 29
	cout << "■■■■■■■■■■■■■■■　　　■■■■■■■■■■■■■■■■■■■" << endl;	// 30
	cout << "■■■■■■■■■■■■■■■　　　■■■■■■■■■■■■■■■■■■■" << endl;	// 31
	cout << "■■■■■■■■■■■■■■■　　　■■■■■■■■■■■■■■■■■■■" << endl;	// 32
	cout << "■■■■■■■■■■■■■■■　　　■■■■■■■■■■■■■■■■■■■" << endl;	// 33
	cout << "■■■■■■■■■■■■■■■　　　■■■■■■■■■■■■■■■■■■■" << endl;	// 34
	cout << "■■■■■■■■■■■■■■■　　　■■■■■■■■■■■■■■■■■■■" << endl;	// 35
	cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;	// 36
	cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;	// 37

	Sleep(1300);

	_effect = Eenvelope;

	Sleep(2200);
	gotoxy(0, 0);
	SetColor(0, 15);

	cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;	// 1
	cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;	// 2
	cout << "■■■■■■■■■■■■■■■　　　　　　　■■■■■■■■■■■■■■■" << endl;	// 3
	cout << "■■■■■■■■■■■■■■■　　　　　　　■■■■■■■■■■■■■■■" << endl;	// 4
	cout << "■■■■■■■■■■■■■■■　　□□□　　■■■■■■■■■■■■■■■" << endl;	// 5
	cout << "■■■■■■■■■■■■■■■　　□□□　　■■■■■■■■■■■■■■■" << endl;	// 6
	cout << "■■■■■■■■■■■■■■■　　□□□　　■■■■■■■■■■■■■■■" << endl;	// 7
	cout << "■■■■■■■■■■■■■■■　　　　　　　■■■■■■■■■■■■■■■" << endl;	// 8
	cout << "■■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■■" << endl;	// 9
	cout << "■■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■■" << endl;	// 10
	cout << "■■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■■" << endl;	// 11
	cout << "■■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■■" << endl;	// 12
	cout << "■■　　■■■■■■■■■■■　　　　　　　　　　　　　　　　　　　　■■" << endl;	// 13
	cout << "■■　　■　　　　　　　　　■　　　　　　　　　　　　　　　　　　　　■■" << endl;	// 14
	cout << "■■　　■■■■　"; SetColor(14, 15); cout << "　■　　　"; SetColor(0, 15); cout << "■　　　　　　　　　　　　　　　　　　　　■■" << endl;	// 15
	cout << "■■　　■■　■　"; SetColor(14, 15); cout << "■■■　　"; SetColor(0, 15); cout << "■　　　　　　　　　　　　　　　　　　　　■■" << endl;	// 16
	cout << "■■　　■■　■　"; SetColor(14, 15); cout << "　■　　　"; SetColor(0, 15); cout << "■　　　　　　　　　　　　　　　　　　　　■■" << endl;	// 17
	cout << "■■　　■■■■　"; SetColor(14, 15); cout << "■■■　　"; SetColor(0, 15); cout << "■　　　　　　　　　　　　　　　　　　　　■■" << endl;	// 18
	cout << "■■　　■　　　　　　　　　■　　　　　　　　　　　　　　　　　　　　■■" << endl;	// 19
	cout << "■■　　■■■■■■■■■■■　　　　　　　　　　　　　　　　　　　　■■" << endl;	// 20
	cout << "■■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■■" << endl;	// 21
	cout << "■■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■■" << endl;	// 22
	cout << "■■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■■" << endl;	// 23
	cout << "■■■■■■■■■■■■■■■■　　　■■■■■■■■■■■■■■■■■■" << endl;	// 24
	cout << "■■■■■■■■■■■■■■■■　　　■■■■■■■■■■■■■■■■■■" << endl;	// 25
	cout << "■■■■■■■■■■■■■■■■　　　■■■■■■■■■■■■■■■■■■" << endl;	// 26

	SetColor(13, 15);

	cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;
	cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
	cout << "■"; SetColor(0, 15); cout << "　　[호연]　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　"; SetColor(13, 15); cout << "■" << endl;
	cout << "■"; SetColor(0, 15); cout << "　　아타호 잘 지내는가. 자네를 못본지도 벌써 일년이 넘었군. 　　　　　"; SetColor(13, 15); cout << "■" << endl;
	cout << "■"; SetColor(0, 15); cout << "　　여태껏 소식없다가 한다는 말이 이래서 부끄럽네만 최근 마을 등지에서"; SetColor(13, 15); cout << "■" << endl;
	cout << "■"; SetColor(0, 15); cout << "　　괴현상이 일어나기에 신의 가호를 받고있는 자네의 도움이 절실하네.. "; SetColor(13, 15); cout << "■" << endl;
	cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
	cout << "■"; SetColor(0, 15); cout << "　　부탁이니 부디 이 편지를 읽는다면 가까운 시일내로 마을로 와주게나　"; SetColor(13, 15); cout << "■" << endl;
	cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
	cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
	cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;

	Conversation();

	gotoxy(0, 0);
	SetColor(0, 15);

	cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;	// 1
	cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;	// 2
	cout << "■■■■■■■■■■■■■■■　　　　　　　■■■■■■■■■■■■■■■" << endl;	// 3
	cout << "■■■■■■■■■■■■■■■　　　　　　　■■■■■■■■■■■■■■■" << endl;	// 4
	cout << "■■■■■■■■■■■■■■■　　□□□　　■■■■■■■■■■■■■■■" << endl;	// 5
	cout << "■■■■■■■■■■■■■■■　　□□□　　■■■■■■■■■■■■■■■" << endl;	// 6
	cout << "■■■■■■■■■■■■■■■　　□□□　　■■■■■■■■■■■■■■■" << endl;	// 7
	cout << "■■■■■■■■■■■■■■■　　　　　　　■■■■■■■■■■■■■■■" << endl;	// 8
	cout << "■■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■■" << endl;	// 9
	cout << "■■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■■" << endl;	// 10
	cout << "■■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■■" << endl;	// 11
	cout << "■■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■■" << endl;	// 12
	cout << "■■　　■■■■■■■■■■■　　　　　　　　　　　　　　　　　　　　■■" << endl;	// 13
	cout << "■■　　■　　　　　　　　　■　　　　　　　　　　　　　　　　　　　　■■" << endl;	// 14
	cout << "■■　　■■■■　"; SetColor(14, 15); cout << "　■　　　"; SetColor(0, 15); cout << "■　　　　　　　　　　　　　　　　　　　　■■" << endl;	// 15
	cout << "■■　　■■　■　"; SetColor(14, 15); cout << "■■■　　"; SetColor(0, 15); cout << "■　　　　　　　　　　　　　　　　　　　　■■" << endl;	// 16
	cout << "■■　　■■　■　"; SetColor(14, 15); cout << "　■　　　"; SetColor(0, 15); cout << "■　　　　　　　　　　　　　　　　　　　　■■" << endl;	// 17
	cout << "■■　　■■■■　"; SetColor(14, 15); cout << "■■■　　"; SetColor(0, 15); cout << "■　　　　　　　　　　　　　　　　　　　　■■" << endl;	// 18
	cout << "■■　　■　　　　　　　　　■　　　　　　　　　　　　　　　　　　　　■■" << endl;	// 19
	cout << "■■　　■■■■■■■■■■■　　　　　　　　　　　　　　　　　　　　■■" << endl;	// 20
	cout << "■■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■■" << endl;	// 21
	cout << "■■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■■" << endl;	// 22
	cout << "■■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■■" << endl;	// 23
	cout << "■■■■■■■■■■■■■■■■　　　■■■■■■■■■■■■■■■■■■" << endl;	// 24
	cout << "■■■■■■■■■■■■■■■■　　　■■■■■■■■■■■■■■■■■■" << endl;	// 25
	cout << "■■■■■■■■■■■■■■■■　　　■■■■■■■■■■■■■■■■■■" << endl;	// 26
	cout << "■■■■■■■■■■■■■■■■　　　■■■■■■■■■■■■■■■■■■" << endl;	// 27
	cout << "■■■■■■■■■■■■■■■■　　　■■■■■■■■■■■■■■■■■■" << endl;	// 28
	cout << "■■■■■■■■■■■■■■■　　　　■■■■■■■■■■■■■■■■■■" << endl;	// 29
	cout << "■■■■■■■■■■■■■■■　　　■■■■■■■■■■■■■■■■■■■" << endl;	// 30
	cout << "■■■■■■■■■■■■■■■　　　■■■■■■■■■■■■■■■■■■■" << endl;	// 31
	cout << "■■■■■■■■■■■■■■■　　　■■■■■■■■■■■■■■■■■■■" << endl;	// 32
	cout << "■■■■■■■■■■■■■■■　　　■■■■■■■■■■■■■■■■■■■" << endl;	// 33
	cout << "■■■■■■■■■■■■■■■　　　■■■■■■■■■■■■■■■■■■■" << endl;	// 34
	cout << "■■■■■■■■■■■■■■■　　　■■■■■■■■■■■■■■■■■■■" << endl;	// 35
	cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;	// 36
	cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;	// 37

	Sleep(1200);
	gotoxy(0, 0);
	SetColor(0, 15);

	cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;	// 1
	cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;	// 2
	cout << "■■■■■■■■■■■■■■■　　　　　　　■■■■■■■■■■■■■■■" << endl;	// 3
	cout << "■■■■■■■■■■■■■■■　　　　　　　■■■■■■■■■■■■■■■" << endl;	// 4
	cout << "■■■■■■■■■■■■■■■　　□□□　　■■■■■■■■■■■■■■■" << endl;	// 5
	cout << "■■■■■■■■■■■■■■■　　□□□　　■■■■■■■■■■■■■■■" << endl;	// 6
	cout << "■■■■■■■■■■■■■■■　　□□□　　■■■■■■■■■■■■■■■" << endl;	// 7
	cout << "■■■■■■■■■■■■■■■　　　　　　　■■■■■■■■■■■■■■■" << endl;	// 8
	cout << "■■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■■" << endl;	// 9
	cout << "■■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■■" << endl;	// 10
	cout << "■■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■■" << endl;	// 11
	cout << "■■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■■" << endl;	// 12
	cout << "■■　　■■■■■■■■■■■　　　　　　　　　　　　　　　　　　　　■■" << endl;	// 13
	cout << "■■　　■　　　　　　　　　■　　　　　　　　　　　　　　　　　　　　■■" << endl;	// 14
	cout << "■■　　■■■■　"; SetColor(14, 15); cout << "　■　　　"; SetColor(0, 15); cout << "■　　　　　　　　　　　　　　　　　　　　■■" << endl;	// 15
	cout << "■■　　■■　■　"; SetColor(14, 15); cout << "■■■　　"; SetColor(0, 15); cout << "■　　　　　　　　　　　　　　　　　　　　■■" << endl;	// 16
	cout << "■■　　■■　■　"; SetColor(14, 15); cout << "　■　　　"; SetColor(0, 15); cout << "■　　　　　　　　　　　　　　　　　　　　■■" << endl;	// 17
	cout << "■■　　■■■■　"; SetColor(14, 15); cout << "■■■　　"; SetColor(0, 15); cout << "■　　　　　　　　　　　　　　　　　　　　■■" << endl;	// 18
	cout << "■■　　■　　　　　　　　　■　　　　　　　　　　　　　　　　　　　　■■" << endl;	// 19
	cout << "■■　　■■■■■■■■■■■　　　　　　　　　　　　　　　　　　　　■■" << endl;	// 20
	cout << "■■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■■" << endl;	// 21
	cout << "■■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■■" << endl;	// 22
	cout << "■■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■■" << endl;	// 23
	cout << "■■■■■■■■■■■■■■■■　　　■■■■■■■■■■■■■■■■■■" << endl;	// 24
	cout << "■■■■■■■■■■■■■■■■　　　■■■■■■■■■■■■■■■■■■" << endl;	// 25
	cout << "■■■■■■■■■■■■■■■■　　　■■■■■■■■■■■■■■■■■■" << endl;	// 26

	SetColor(13, 15);

	cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;
	cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
	cout << "■"; SetColor(0, 15); cout << "　　[아타호]　　　　　　　　　　　　　　　　　　　　　　　　　　　　　"; SetColor(13, 15); cout << "■" << endl;
	cout << "■"; SetColor(0, 15); cout << "　　허허 괴현상이라니 대체 무슨일이 생기고 있는것인지..　　　　　　　 "; SetColor(13, 15); cout << "■" << endl;
	cout << "■"; SetColor(0, 15); cout << "　　친구의 부탁이니 당연히 도우러 가야겠지　　　　　　　　　　  　　　"; SetColor(13, 15); cout << "■" << endl;
	cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
	cout << "■"; SetColor(0, 15); cout << "　　출발하기전에 이아님에게 조언을 받고 가야겠군　　　　　　　　　　　"; SetColor(13, 15); cout << "■" << endl;
	cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
	cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
	cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
	cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;

	Conversation();

	gotoxy(0, 0);
	SetColor(0, 15);

	cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;	// 1
	cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;	// 2
	cout << "■■■■■■■■■■■■■■■　　　　　　　■■■■■■■■■■■■■■■" << endl;	// 3
	cout << "■■■■■■■■■■■■■■■　　　　　　　■■■■■■■■■■■■■■■" << endl;	// 4
	cout << "■■■■■■■■■■■■■■■　　□□□　　■■■■■■■■■■■■■■■" << endl;	// 5
	cout << "■■■■■■■■■■■■■■■　　□□□　　■■■■■■■■■■■■■■■" << endl;	// 6
	cout << "■■■■■■■■■■■■■■■　　□□□　　■■■■■■■■■■■■■■■" << endl;	// 7
	cout << "■■■■■■■■■■■■■■■　　　　　　　■■■■■■■■■■■■■■■" << endl;	// 8
	cout << "■■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■■" << endl;	// 9
	cout << "■■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■■" << endl;	// 10
	cout << "■■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■■" << endl;	// 11
	cout << "■■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■■" << endl;	// 12
	cout << "■■　　■■■■■■■■■■■　　　　　　　　　　　　　　　　　　　　■■" << endl;	// 13
	cout << "■■　　■　　　　　　　　　■　　　　　　　　　　　　　　　　　　　　■■" << endl;	// 14
	cout << "■■　　■■■■　"; SetColor(14, 15); cout << "　■　　　"; SetColor(0, 15); cout << "■　　　　　　　　　　　　　　　　　　　　■■" << endl;	// 15
	cout << "■■　　■■　■　"; SetColor(14, 15); cout << "■■■　　"; SetColor(0, 15); cout << "■　　　　　　　　　　　　　　　　　　　　■■" << endl;	// 16
	cout << "■■　　■■　■　"; SetColor(14, 15); cout << "　■　　　"; SetColor(0, 15); cout << "■　　　　　　　　　　　　　　　　　　　　■■" << endl;	// 17
	cout << "■■　　■■■■　"; SetColor(14, 15); cout << "■■■　　"; SetColor(0, 15); cout << "■　　　　　　　　　　　　　　　　　　　　■■" << endl;	// 18
	cout << "■■　　■　　　　　　　　　■　　　　　　　　　　　　　　　　　　　　■■" << endl;	// 19
	cout << "■■　　■■■■■■■■■■■　　　　　　　　　　　　　　　　　　　　■■" << endl;	// 20
	cout << "■■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■■" << endl;	// 21
	cout << "■■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■■" << endl;	// 22
	cout << "■■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■■" << endl;	// 23
	cout << "■■■■■■■■■■■■■■■■　　　■■■■■■■■■■■■■■■■■■" << endl;	// 24
	cout << "■■■■■■■■■■■■■■■■　　　■■■■■■■■■■■■■■■■■■" << endl;	// 25
	cout << "■■■■■■■■■■■■■■■■　　　■■■■■■■■■■■■■■■■■■" << endl;	// 26
	cout << "■■■■■■■■■■■■■■■■　　　■■■■■■■■■■■■■■■■■■" << endl;	// 27
	cout << "■■■■■■■■■■■■■■■■　　　■■■■■■■■■■■■■■■■■■" << endl;	// 28
	cout << "■■■■■■■■■■■■■■■　　　　■■■■■■■■■■■■■■■■■■" << endl;	// 29
	cout << "■■■■■■■■■■■■■■■　　　■■■■■■■■■■■■■■■■■■■" << endl;	// 30
	cout << "■■■■■■■■■■■■■■■　　　■■■■■■■■■■■■■■■■■■■" << endl;	// 31
	cout << "■■■■■■■■■■■■■■■　　　■■■■■■■■■■■■■■■■■■■" << endl;	// 32
	cout << "■■■■■■■■■■■■■■■　　　■■■■■■■■■■■■■■■■■■■" << endl;	// 33
	cout << "■■■■■■■■■■■■■■■　　　■■■■■■■■■■■■■■■■■■■" << endl;	// 34
	cout << "■■■■■■■■■■■■■■■　　　■■■■■■■■■■■■■■■■■■■" << endl;	// 35
	cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;	// 36
	cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;	// 37

	Sleep(1200);

	gotoxy(0, 0);
	SetColor(0, 15);

	cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;	// 1
	cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;	// 2
	cout << "■■■■■■■■■■■■■■■　　　　　　　■■■■■■■■■■■■■■■" << endl;	// 3
	cout << "■■■■■■■■■■■■■■■　　　　　　　■■■■■■■■■■■■■■■" << endl;	// 4
	cout << "■■■■■■■■■■■■■■■　　□□□　　■■■■■■■■■■■■■■■" << endl;	// 5
	cout << "■■■■■■■■■■■■■■■　　□□□　　■■■■■■■■■■■■■■■" << endl;	// 6
	cout << "■■■■■■■■■■■■■■■　　□□□　　■■■■■■■■■■■■■■■" << endl;	// 7
	cout << "■■■■■■■■■■■■■■■　　　　　　　■■■■■■■■■■■■■■■" << endl;	// 8
	cout << "■■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■■" << endl;	// 9
	cout << "■■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■■" << endl;	// 10
	cout << "■■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■■" << endl;	// 11
	cout << "■■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■■" << endl;	// 12
	cout << "■■　　■■■■■■■■■■■　　　　　　　　　　　　　　　　　　　　■■" << endl;	// 13
	cout << "■■　　■　　　　　　　　　■　　　　　　　　　　　　　　　　　　　　■■" << endl;	// 14
	cout << "■■　　■■■■　"; SetColor(14, 15); cout << "　■　　　"; SetColor(0, 15); cout << "■　　　　　　　　　　　　　　　　　　　　■■" << endl;	// 15
	cout << "■■　　■■　■　"; SetColor(14, 15); cout << "■■■　　"; SetColor(0, 15); cout << "■　　　　　　　　　　　　　　　　　　　　■■" << endl;	// 16
	cout << "■■　　■■　■　"; SetColor(14, 15); cout << "　■　　　"; SetColor(0, 15); cout << "■　　　　　　　　　　　　　　　　　　　　■■" << endl;	// 17
	cout << "■■　　■■■■　"; SetColor(14, 15); cout << "■　■　　"; SetColor(0, 15); cout << "■　　　　　　　　　　　　　　　　　　　　■■" << endl;	// 18
	cout << "■■　　■　　　　　　　　　■　　　　　　　　　　　　　　　　　　　　■■" << endl;	// 19
	cout << "■■　　■■■■■■■■■■■　　　　　　　　　　　　　　　　　　　　■■" << endl;	// 20
	cout << "■■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■■" << endl;	// 21
	cout << "■■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■■" << endl;	// 22
	cout << "■■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■■" << endl;	// 23
	cout << "■■■■■■■■■■■■■■■■　　　■■■■■■■■■■■■■■■■■■" << endl;	// 24
	cout << "■■■■■■■■■■■■■■■■　　　■■■■■■■■■■■■■■■■■■" << endl;	// 25
	cout << "■■■■■■■■■■■■■■■■　　　■■■■■■■■■■■■■■■■■■" << endl;	// 26
	cout << "■■■■■■■■■■■■■■■■　　　■■■■■■■■■■■■■■■■■■" << endl;	// 27
	cout << "■■■■■■■■■■■■■■■■　　　■■■■■■■■■■■■■■■■■■" << endl;	// 28
	cout << "■■■■■■■■■■■■■■■　　　　■■■■■■■■■■■■■■■■■■" << endl;	// 29
	cout << "■■■■■■■■■■■■■■■　　　■■■■■■■■■■■■■■■■■■■" << endl;	// 30
	cout << "■■■■■■■■■■■■■■■　　　■■■■■■■■■■■■■■■■■■■" << endl;	// 31
	cout << "■■■■■■■■■■■■■■■　　　■■■■■■■■■■■■■■■■■■■" << endl;	// 32
	cout << "■■■■■■■■■■■■■■■　　　■■■■■■■■■■■■■■■■■■■" << endl;	// 33
	cout << "■■■■■■■■■■■■■■■　　　■■■■■■■■■■■■■■■■■■■" << endl;	// 34
	cout << "■■■■■■■■■■■■■■■　　　■■■■■■■■■■■■■■■■■■■" << endl;	// 35
	cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;	// 36
	cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;	// 37

	Sleep(1200);


	gotoxy(0, 0);
	SetColor(0, 15);

	cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;	// 1
	cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;	// 2
	cout << "■■■■■■■■■■■■■■■　　　　　　　■■■■■■■■■■■■■■■" << endl;	// 3
	cout << "■■■■■■■■■■■■■■■　　　　　　　■■■■■■■■■■■■■■■" << endl;	// 4
	cout << "■■■■■■■■■■■■■■■　　□□□　　■■■■■■■■■■■■■■■" << endl;	// 5
	cout << "■■■■■■■■■■■■■■■　　□□□　　■■■■■■■■■■■■■■■" << endl;	// 6
	cout << "■■■■■■■■■■■■■■■　　□□□　　■■■■■■■■■■■■■■■" << endl;	// 7
	cout << "■■■■■■■■■■■■■■■　　　　　　　■■■■■■■■■■■■■■■" << endl;	// 8
	cout << "■■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■■" << endl;	// 9
	cout << "■■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■■" << endl;	// 10
	cout << "■■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■■" << endl;	// 11
	cout << "■■　　　　　　　　　　　　　"; SetColor(14, 15); cout << "　■　"; SetColor(0, 15); cout << "　　　　　　　　　　　　　　　　　■■" << endl;	// 12
	cout << "■■　　■■■■■■■■■■■"; SetColor(14, 15); cout << "■■■"; SetColor(0, 15); cout << "　　　　　　　　　　　　　　　　　■■" << endl;	// 13
	cout << "■■　　■　　　　　　　　　■"; SetColor(14, 15); cout << "　■　"; SetColor(0, 15); cout << "　　　　　　　　　　　　　　　　　■■" << endl;	// 14
	cout << "■■　　■■■■　　　　　　■"; SetColor(14, 15); cout << "■　■"; SetColor(0, 15); cout << "　　　　　　　　　　　　　　　　　■■" << endl;	// 15
	cout << "■■　　■■　■　　　　　　■　　　　　　　　　　　　　　　　　　　　■■" << endl;	// 16
	cout << "■■　　■■　■　　　　　　■　　　　　　　　　　　　　　　　　　　　■■" << endl;	// 17
	cout << "■■　　■■■■　　　　　　■　　　　　　　　　　　　　　　　　　　　■■" << endl;	// 18
	cout << "■■　　■　　　　　　　　　■　　　　　　　　　　　　　　　　　　　　■■" << endl;	// 19
	cout << "■■　　■■■■■■■■■■■　　　　　　　　　　　　　　　　　　　　■■" << endl;	// 20
	cout << "■■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■■" << endl;	// 21
	cout << "■■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■■" << endl;	// 22
	cout << "■■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■■" << endl;	// 23
	cout << "■■■■■■■■■■■■■■■■　　　■■■■■■■■■■■■■■■■■■" << endl;	// 24
	cout << "■■■■■■■■■■■■■■■■　　　■■■■■■■■■■■■■■■■■■" << endl;	// 25
	cout << "■■■■■■■■■■■■■■■■　　　■■■■■■■■■■■■■■■■■■" << endl;	// 26
	cout << "■■■■■■■■■■■■■■■■　　　■■■■■■■■■■■■■■■■■■" << endl;	// 27
	cout << "■■■■■■■■■■■■■■■■　　　■■■■■■■■■■■■■■■■■■" << endl;	// 28
	cout << "■■■■■■■■■■■■■■■　　　　■■■■■■■■■■■■■■■■■■" << endl;	// 29
	cout << "■■■■■■■■■■■■■■■　　　■■■■■■■■■■■■■■■■■■■" << endl;	// 30
	cout << "■■■■■■■■■■■■■■■　　　■■■■■■■■■■■■■■■■■■■" << endl;	// 31
	cout << "■■■■■■■■■■■■■■■　　　■■■■■■■■■■■■■■■■■■■" << endl;	// 32
	cout << "■■■■■■■■■■■■■■■　　　■■■■■■■■■■■■■■■■■■■" << endl;	// 33
	cout << "■■■■■■■■■■■■■■■　　　■■■■■■■■■■■■■■■■■■■" << endl;	// 34
	cout << "■■■■■■■■■■■■■■■　　　■■■■■■■■■■■■■■■■■■■" << endl;	// 35
	cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;	// 36
	cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;	// 37

	Sleep(1200);

	gotoxy(0, 0);
	SetColor(0, 15);

	cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;	// 1
	cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;	// 2
	cout << "■■■■■■■■■■■■■■■　　　　　　　■■■■■■■■■■■■■■■" << endl;	// 3
	cout << "■■■■■■■■■■■■■■■　　　　　　　■■■■■■■■■■■■■■■" << endl;	// 4
	cout << "■■■■■■■■■■■■■■■　　□□□　　■■■■■■■■■■■■■■■" << endl;	// 5
	cout << "■■■■■■■■■■■■■■■　　□□□　　■■■■■■■■■■■■■■■" << endl;	// 6
	cout << "■■■■■■■■■■■■■■■　　□"; SetColor(14, 15); cout << "■"; SetColor(0, 15); cout << "□　　■■■■■■■■■■■■■■■" << endl;	// 7
	cout << "■■■■■■■■■■■■■■■　　"; SetColor(14, 15); cout << "■■■"; SetColor(0, 15); cout << "　　■■■■■■■■■■■■■■■" << endl;	// 8
	cout << "■■　　　　　　　　　　　　　　　　"; SetColor(14, 15); cout << "■"; SetColor(0, 15); cout << "　　　　　　　　　　　　　　　　■■" << endl;	// 9
	cout << "■■　　　　　　　　　　　　　　　"; SetColor(14, 15); cout << "■　■"; SetColor(0, 15); cout << "　　　　　　　　　　　　　　　■■" << endl;	// 10
	cout << "■■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■■" << endl;	// 11
	cout << "■■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■■" << endl;	// 12
	cout << "■■　　■■■■■■■■■■■　　　　　　　　　　　　　　　　　　　　■■" << endl;	// 13
	cout << "■■　　■　　　　　　　　　■　　　　　　　　　　　　　　　　　　　　■■" << endl;	// 14
	cout << "■■　　■■■■　　　　　　■　　　　　　　　　　　　　　　　　　　　■■" << endl;	// 15
	cout << "■■　　■■　■　　　　　　■　　　　　　　　　　　　　　　　　　　　■■" << endl;	// 16
	cout << "■■　　■■　■　　　　　　■　　　　　　　　　　　　　　　　　　　　■■" << endl;	// 17
	cout << "■■　　■■■■　　　　　　■　　　　　　　　　　　　　　　　　　　　■■" << endl;	// 18
	cout << "■■　　■　　　　　　　　　■　　　　　　　　　　　　　　　　　　　　■■" << endl;	// 19
	cout << "■■　　■■■■■■■■■■■　　　　　　　　　　　　　　　　　　　　■■" << endl;	// 20
	cout << "■■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■■" << endl;	// 21
	cout << "■■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■■" << endl;	// 22
	cout << "■■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■■" << endl;	// 23
	cout << "■■■■■■■■■■■■■■■■　　　■■■■■■■■■■■■■■■■■■" << endl;	// 24
	cout << "■■■■■■■■■■■■■■■■　　　■■■■■■■■■■■■■■■■■■" << endl;	// 25
	cout << "■■■■■■■■■■■■■■■■　　　■■■■■■■■■■■■■■■■■■" << endl;	// 26
	cout << "■■■■■■■■■■■■■■■■　　　■■■■■■■■■■■■■■■■■■" << endl;	// 27
	cout << "■■■■■■■■■■■■■■■■　　　■■■■■■■■■■■■■■■■■■" << endl;	// 28
	cout << "■■■■■■■■■■■■■■■　　　　■■■■■■■■■■■■■■■■■■" << endl;	// 29
	cout << "■■■■■■■■■■■■■■■　　　■■■■■■■■■■■■■■■■■■■" << endl;	// 30
	cout << "■■■■■■■■■■■■■■■　　　■■■■■■■■■■■■■■■■■■■" << endl;	// 31
	cout << "■■■■■■■■■■■■■■■　　　■■■■■■■■■■■■■■■■■■■" << endl;	// 32
	cout << "■■■■■■■■■■■■■■■　　　■■■■■■■■■■■■■■■■■■■" << endl;	// 33
	cout << "■■■■■■■■■■■■■■■　　　■■■■■■■■■■■■■■■■■■■" << endl;	// 34
	cout << "■■■■■■■■■■■■■■■　　　■■■■■■■■■■■■■■■■■■■" << endl;	// 35
	cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;	// 36
	cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;	// 37

	Sleep(1200);
}
/////////////////////////////////////////////
void mainGame::HomeEvent()
{
	_homecheck = 3;
	HomeTempleScreen();
	HomeEventChoice();
}
void mainGame::HomeTempleScreen()
{
	gotoxy(0, 0);
	SetColor(9, 15);

	cout << "■■□□□■■■□□□■■■□□□■■■□□□■■■□□□■■■□□□■■" << endl;	// 1
	cout << "■"; SetColor(0, 15); cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■"; SetColor(9, 15); cout << "■" << endl;	// 2
	cout << "□"; SetColor(0, 15); cout << "■■■■■■■■■■■■■■　　　　　　　■■■■■■■■■■■■■■"; SetColor(9, 15); cout << "□" << endl;	// 3
	cout << "□"; SetColor(0, 15); cout << "■■■■■■■■■■■■■■　　　　　　　■■■■■■■■■■■■■■"; SetColor(9, 15); cout << "□" << endl;	// 4
	cout << "□"; SetColor(0, 15); cout << "■■■■■■■■■■■■■■　　□□□　　■■■■■■■■■■■■■■"; SetColor(9, 15); cout << "□" << endl;	// 5
	cout << "■"; SetColor(0, 15); cout << "■■■■■■■■■■■■■■　　□□□　　■■■■■■■■■■■■■■"; SetColor(9, 15); cout << "■" << endl;	// 6
	cout << "■"; SetColor(0, 15); cout << "■■■■■■■■■■■■■■　　□"; SetColor(14, 15); cout << "■"; SetColor(0, 15); cout << "□　　■■■■■■■■■■■■■■"; SetColor(9, 15); cout << "■" << endl;	// 7
	cout << "■"; SetColor(0, 15); cout << "■■■■■■■■■■■■■■　　"; SetColor(14, 15); cout << "■■■"; SetColor(0, 15); cout << "　　■■■■■■■■■■■■■■"; SetColor(9, 15); cout << "■" << endl;	// 8
	cout << "□"; SetColor(0, 15); cout << "■　　　　　　　　　　　　　　　　"; SetColor(14, 15); cout << "■"; SetColor(0, 15); cout << "　　　　　　　　　　　　　　　　■"; SetColor(9, 15); cout << "□" << endl;	// 9
	cout << "□"; SetColor(0, 15); cout << "■　　　　　　　　　　　　　　　"; SetColor(14, 15); cout << "■　■"; SetColor(0, 15); cout << "　　　　　　　　　　　　　　　■"; SetColor(9, 15); cout << "□" << endl;	// 10
	cout << "□"; SetColor(0, 15); cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■"; SetColor(9, 15); cout << "□" << endl;	// 11
	cout << "■"; SetColor(0, 15); cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■"; SetColor(9, 15); cout << "■" << endl;	// 12
	cout << "■"; SetColor(0, 15); cout << "■　　■■■■■■■■■■■　　　　　　　　　　　　　　　　　　　　■"; SetColor(9, 15); cout << "■" << endl;	// 13
	cout << "■"; SetColor(0, 15); cout << "■　　■　　　　　　　　　■　　　　　　　　　　　　　　　　　　　　■"; SetColor(9, 15); cout << "■" << endl;	// 14
	cout << "□"; SetColor(0, 15); cout << "■　　■■■■　　　　　　■　　　　　　　　　　　　　　　　　　　　■"; SetColor(9, 15); cout << "□" << endl;	// 15
	cout << "□"; SetColor(0, 15); cout << "■　　■■　■　　　　　　■　　　　　　　　　　　　　　　　　　　　■"; SetColor(9, 15); cout << "□" << endl;	// 16
	cout << "□"; SetColor(0, 15); cout << "■　　■■　■　　　　　　■　　　　　　　　　　　　　　　　　　　　■"; SetColor(9, 15); cout << "□" << endl;	// 17
	cout << "■"; SetColor(0, 15); cout << "■　　■■■■　　　　　　■　　　　　　　　　　　　　　　　　　　　■"; SetColor(9, 15); cout << "■" << endl;	// 18
	cout << "■"; SetColor(0, 15); cout << "■　　■　　　　　　　　　■　　　　　　　　　　　　　　　　　　　　■"; SetColor(9, 15); cout << "■" << endl;	// 19
	cout << "■"; SetColor(0, 15); cout << "■　　■■■■■■■■■■■　　　　　　　　　　　　　　　　　　　　■"; SetColor(9, 15); cout << "■" << endl;	// 20
	cout << "□"; SetColor(0, 15); cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■"; SetColor(9, 15); cout << "□" << endl;	// 21
	cout << "□"; SetColor(0, 15); cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■"; SetColor(9, 15); cout << "□" << endl;	// 22
	cout << "□"; SetColor(0, 15); cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■"; SetColor(9, 15); cout << "□" << endl;	// 23
	cout << "■"; SetColor(0, 15); cout << "■■■■■■■■■■■■■■■　　　■■■■■■■■■■■■■■■■■"; SetColor(9, 15); cout << "■" << endl;	// 24
	cout << "■"; SetColor(0, 15); cout << "■■■■■■■■■■■■■■■　　　■■■■■■■■■■■■■■■■■"; SetColor(9, 15); cout << "■" << endl;	// 25
	cout << "■"; SetColor(0, 15); cout << "■■■■■■■■■■■■■■■　　　■■■■■■■■■■■■■■■■■"; SetColor(9, 15); cout << "■" << endl;	// 26
	cout << "□"; SetColor(0, 15); cout << "■■■■■■■■■■■■■■■　　　■■■■■■■■■■■■■■■■■"; SetColor(9, 15); cout << "□" << endl;	// 27
	cout << "□"; SetColor(0, 15); cout << "■■■■■■■■■■■■■■■　　　■■■■■■■■■■■■■■■■■"; SetColor(9, 15); cout << "□" << endl;	// 28
	cout << "□"; SetColor(0, 15); cout << "■■■■■■■■■■■■■■　　　　■■■■■■■■■■■■■■■■■"; SetColor(9, 15); cout << "□" << endl;	// 29
	cout << "■"; SetColor(0, 15); cout << "■■■■■■■■■■■■■■　　　■■■■■■■■■■■■■■■■■■"; SetColor(9, 15); cout << "■" << endl;	// 30
	cout << "■"; SetColor(0, 15); cout << "■■■■■■■■■■■■■■　　　■■■■■■■■■■■　　　　　■■"; SetColor(9, 15); cout << "■" << endl;	// 31
	cout << "■"; SetColor(0, 15); cout << "■■■■■■■■■■■■■■　　　■■■■■■■■■■■　　　　　■■"; SetColor(9, 15); cout << "■" << endl;	// 32
	cout << "□"; SetColor(0, 15); cout << "■■■■■■■■■■■■■■　　　■■■■■■■■■■■　제　단　■■"; SetColor(9, 15); cout << "□" << endl;	// 33
	cout << "□"; SetColor(0, 15); cout << "■■■■■■■■■■■■■■　　　■■■■■■■■■■■　　　　　■■"; SetColor(9, 15); cout << "□" << endl;	// 34
	cout << "□"; SetColor(0, 15); cout << "■■■■■■■■■■■■■■　　　■■■■■■■■■■■　　　　　■■"; SetColor(9, 15); cout << "□" << endl;	// 35
	cout << "■"; SetColor(0, 15); cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■"; SetColor(9, 15); cout << "■" << endl;	// 36
	cout << "■■□□□■■■□□□■■■□□□■■■□□□■■■□□□■■■□□□■■" << endl;	// 37
}
void mainGame::HomeSleepScreen()
{
	gotoxy(0, 0);
	SetColor(9, 15);

	cout << "■■□□□■■■□□□■■■□□□■■■□□□■■■□□□■■■□□□■■" << endl;	// 1
	cout << "■"; SetColor(0, 15); cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■"; SetColor(9, 15); cout << "■" << endl;	// 2
	cout << "□"; SetColor(0, 15); cout << "■■■■■■■■■■■■■■　　　　　　　■■■■■■■■■■■■■■"; SetColor(9, 15); cout << "□" << endl;	// 3
	cout << "□"; SetColor(0, 15); cout << "■■■■■■■■■■■■■■　　　　　　　■■■■■■■■■■■■■■"; SetColor(9, 15); cout << "□" << endl;	// 4
	cout << "□"; SetColor(0, 15); cout << "■■■■■■■■■■■■■■　　□□□　　■■■■■■■■■■■■■■"; SetColor(9, 15); cout << "□" << endl;	// 5
	cout << "■"; SetColor(0, 15); cout << "■■■■■■■■■■■■■■　　□□□　　■■■■■■■■■■■■■■"; SetColor(9, 15); cout << "■" << endl;	// 6
	cout << "■"; SetColor(0, 15); cout << "■■■■■■■■■■■■■■　　□□□　　■■■■■■■■■■■■■■"; SetColor(9, 15); cout << "■" << endl;	// 7
	cout << "■"; SetColor(0, 15); cout << "■■■■■■■■■■■■■■　　　　　　　■■■■■■■■■■■■■■"; SetColor(9, 15); cout << "■" << endl;	// 8
	cout << "□"; SetColor(0, 15); cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■"; SetColor(9, 15); cout << "□" << endl;	// 9
	cout << "□"; SetColor(0, 15); cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■"; SetColor(9, 15); cout << "□" << endl;	// 10
	cout << "□"; SetColor(0, 15); cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■"; SetColor(9, 15); cout << "□" << endl;	// 11
	cout << "■"; SetColor(0, 15); cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■"; SetColor(9, 15); cout << "■" << endl;	// 12
	cout << "■"; SetColor(0, 15); cout << "■　　■■■■■■■■■■■　　　　　　　　　　　　　　　　　　　　■"; SetColor(9, 15); cout << "■" << endl;	// 13
	cout << "■"; SetColor(0, 15); cout << "■　　■　　　　　　　　　■　　　　　　　　　　　　　　　　　　　　■"; SetColor(9, 15); cout << "■" << endl;	// 14
	cout << "□"; SetColor(0, 15); cout << "■　　■■■"; SetColor(14, 15); cout << "■　■"; SetColor(0, 15); cout << "　　　　■　　　　　　　　　　　　　　　　　　　　■"; SetColor(9, 15); cout << "□" << endl;	// 15
	cout << "□"; SetColor(0, 15); cout << "■　　■■"; SetColor(14, 15); cout << "■■■"; SetColor(0, 15); cout << "　　　　　■　　　　　　　　　　　　　　　　　　　　■"; SetColor(9, 15); cout << "□" << endl;	// 16
	cout << "□"; SetColor(0, 15); cout << "■　　■■　"; SetColor(14, 15); cout << "■　■"; SetColor(0, 15); cout << "　　　　■　　　　　　　　　　　　　　　　　　　　■"; SetColor(9, 15); cout << "□" << endl;	// 17
	cout << "■"; SetColor(0, 15); cout << "■　　■■■■　　　　　　■　　　　　　　　　　　　　　　　　　　　■"; SetColor(9, 15); cout << "■" << endl;	// 18
	cout << "■"; SetColor(0, 15); cout << "■　　■　　　　　　　　　■　　　　　　　　　　　　　　　　　　　　■"; SetColor(9, 15); cout << "■" << endl;	// 19
	cout << "■"; SetColor(0, 15); cout << "■　　■■■■■■■■■■■　　　　　　　　　　　　　　　　　　　　■"; SetColor(9, 15); cout << "■" << endl;	// 20
	cout << "□"; SetColor(0, 15); cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■"; SetColor(9, 15); cout << "□" << endl;	// 21
	cout << "□"; SetColor(0, 15); cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■"; SetColor(9, 15); cout << "□" << endl;	// 22
	cout << "□"; SetColor(0, 15); cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■"; SetColor(9, 15); cout << "□" << endl;	// 23
	cout << "■"; SetColor(0, 15); cout << "■■■■■■■■■■■■■■■　　　■■■■■■■■■■■■■■■■■"; SetColor(9, 15); cout << "■" << endl;	// 24
	cout << "■"; SetColor(0, 15); cout << "■■■■■■■■■■■■■■■　　　■■■■■■■■■■■■■■■■■"; SetColor(9, 15); cout << "■" << endl;	// 25
	cout << "■"; SetColor(0, 15); cout << "■■■■■■■■■■■■■■■　　　■■■■■■■■■■■■■■■■■"; SetColor(9, 15); cout << "■" << endl;	// 26
	cout << "□"; SetColor(0, 15); cout << "■■■■■■■■■■■■■■■　　　■■■■■■■■■■■■■■■■■"; SetColor(9, 15); cout << "□" << endl;	// 27
	cout << "□"; SetColor(0, 15); cout << "■■■■■■■■■■■■■■■　　　■■■■■■■■■■■■■■■■■"; SetColor(9, 15); cout << "□" << endl;	// 28
	cout << "□"; SetColor(0, 15); cout << "■■■■■■■■■■■■■■　　　　■■■■■■■■■■■■■■■■■"; SetColor(9, 15); cout << "□" << endl;	// 29
	cout << "■"; SetColor(0, 15); cout << "■■■■■■■■■■■■■■　　　■■■■■■■■■■■■■■■■■■"; SetColor(9, 15); cout << "■" << endl;	// 30
	cout << "■"; SetColor(0, 15); cout << "■■■■■■■■■■■■■■　　　■■■■■■■■■■■　　　　　■■"; SetColor(9, 15); cout << "■" << endl;	// 31
	cout << "■"; SetColor(0, 15); cout << "■■■■■■■■■■■■■■　　　■■■■■■■■■■■　　　　　■■"; SetColor(9, 15); cout << "■" << endl;	// 32
	cout << "□"; SetColor(0, 15); cout << "■■■■■■■■■■■■■■　　　■■■■■■■■■■■　　잠　　■■"; SetColor(9, 15); cout << "□" << endl;	// 33
	cout << "□"; SetColor(0, 15); cout << "■■■■■■■■■■■■■■　　　■■■■■■■■■■■　　　　　■■"; SetColor(9, 15); cout << "□" << endl;	// 34
	cout << "□"; SetColor(0, 15); cout << "■■■■■■■■■■■■■■　　　■■■■■■■■■■■　　　　　■■"; SetColor(9, 15); cout << "□" << endl;	// 35
	cout << "■"; SetColor(0, 15); cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■"; SetColor(9, 15); cout << "■" << endl;	// 36
	cout << "■■□□□■■■□□□■■■□□□■■■□□□■■■□□□■■■□□□■■" << endl;	// 37
}
void mainGame::HomeFieldScreen()
{
	gotoxy(0, 0);
	SetColor(9, 15);

	cout << "■■□□□■■■□□□■■■□□□■■■□□□■■■□□□■■■□□□■■" << endl;	// 1
	cout << "■"; SetColor(0, 15); cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■"; SetColor(9, 15); cout << "■" << endl;	// 2
	cout << "□"; SetColor(0, 15); cout << "■■■■■■■■■■■■■■　　　　　　　■■■■■■■■■■■■■■"; SetColor(9, 15); cout << "□" << endl;	// 3
	cout << "□"; SetColor(0, 15); cout << "■■■■■■■■■■■■■■　　　　　　　■■■■■■■■■■■■■■"; SetColor(9, 15); cout << "□" << endl;	// 4
	cout << "□"; SetColor(0, 15); cout << "■■■■■■■■■■■■■■　　□□□　　■■■■■■■■■■■■■■"; SetColor(9, 15); cout << "□" << endl;	// 5
	cout << "■"; SetColor(0, 15); cout << "■■■■■■■■■■■■■■　　□□□　　■■■■■■■■■■■■■■"; SetColor(9, 15); cout << "■" << endl;	// 6
	cout << "■"; SetColor(0, 15); cout << "■■■■■■■■■■■■■■　　□□□　　■■■■■■■■■■■■■■"; SetColor(9, 15); cout << "■" << endl;	// 7
	cout << "■"; SetColor(0, 15); cout << "■■■■■■■■■■■■■■　　　　　　　■■■■■■■■■■■■■■"; SetColor(9, 15); cout << "■" << endl;	// 8
	cout << "□"; SetColor(0, 15); cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■"; SetColor(9, 15); cout << "□" << endl;	// 9
	cout << "□"; SetColor(0, 15); cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■"; SetColor(9, 15); cout << "□" << endl;	// 10
	cout << "□"; SetColor(0, 15); cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■"; SetColor(9, 15); cout << "□" << endl;	// 11
	cout << "■"; SetColor(0, 15); cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■"; SetColor(9, 15); cout << "■" << endl;	// 12
	cout << "■"; SetColor(0, 15); cout << "■　　■■■■■■■■■■■　　　　　　　　　　　　　　　　　　　　■"; SetColor(9, 15); cout << "■" << endl;	// 13
	cout << "■"; SetColor(0, 15); cout << "■　　■　　　　　　　　　■　　　　　　　　　　　　　　　　　　　　■"; SetColor(9, 15); cout << "■" << endl;	// 14
	cout << "□"; SetColor(0, 15); cout << "■　　■■■■　　　　　　■　　　　　　　　　　　　　　　　　　　　■"; SetColor(9, 15); cout << "□" << endl;	// 15
	cout << "□"; SetColor(0, 15); cout << "■　　■■　■　　　　　　■　　　　　　　　　　　　　　　　　　　　■"; SetColor(9, 15); cout << "□" << endl;	// 16
	cout << "□"; SetColor(0, 15); cout << "■　　■■　■　　　　　　■　　　　　　　　　　　　　　　　　　　　■"; SetColor(9, 15); cout << "□" << endl;	// 17
	cout << "■"; SetColor(0, 15); cout << "■　　■■■■　　　　　　■　　　　　　　　　　　　　　　　　　　　■"; SetColor(9, 15); cout << "■" << endl;	// 18
	cout << "■"; SetColor(0, 15); cout << "■　　■　　　　　　　　　■　　　　　　　　　　　　　　　　　　　　■"; SetColor(9, 15); cout << "■" << endl;	// 19
	cout << "■"; SetColor(0, 15); cout << "■　　■■■■■■■■■■■　　　　　　　　　　　　　　　　　　　　■"; SetColor(9, 15); cout << "■" << endl;	// 20
	cout << "□"; SetColor(0, 15); cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■"; SetColor(9, 15); cout << "□" << endl;	// 21
	cout << "□"; SetColor(0, 15); cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■"; SetColor(9, 15); cout << "□" << endl;	// 22
	cout << "□"; SetColor(0, 15); cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■"; SetColor(9, 15); cout << "□" << endl;	// 23
	cout << "■"; SetColor(0, 15); cout << "■■■■■■■■■■■■■■■　　　■■■■■■■■■■■■■■■■■"; SetColor(9, 15); cout << "■" << endl;	// 24
	cout << "■"; SetColor(0, 15); cout << "■■■■■■■■■■■■■■■　　　■■■■■■■■■■■■■■■■■"; SetColor(9, 15); cout << "■" << endl;	// 25
	cout << "■"; SetColor(0, 15); cout << "■■■■■■■■■■■■■■■　　　■■■■■■■■■■■■■■■■■"; SetColor(9, 15); cout << "■" << endl;	// 26
	cout << "□"; SetColor(0, 15); cout << "■■■■■■■■■■■■■■■　　　■■■■■■■■■■■■■■■■■"; SetColor(9, 15); cout << "□" << endl;	// 27
	cout << "□"; SetColor(0, 15); cout << "■■■■■■■■■■■■■■■　　　■■■■■■■■■■■■■■■■■"; SetColor(9, 15); cout << "□" << endl;	// 28
	cout << "□"; SetColor(0, 15); cout << "■■■■■■■■■■■■■■　　　　■■■■■■■■■■■■■■■■■"; SetColor(9, 15); cout << "□" << endl;	// 29
	cout << "■"; SetColor(0, 15); cout << "■■■■■■■■■■■■■■　　　■■■■■■■■■■■■■■■■■■"; SetColor(9, 15); cout << "■" << endl;	// 30
	cout << "■"; SetColor(0, 15); cout << "■■■■■■■■■■■■■■　　　■■■■■■■■■■■　　　　　■■"; SetColor(9, 15); cout << "■" << endl;	// 31
	cout << "■"; SetColor(0, 15); cout << "■■■■■■■■■■■■■■"; SetColor(14, 15); cout << "　■　"; SetColor(0, 15); cout << "■■■■■■■■■■■　　　　　■■"; SetColor(9, 15); cout << "■" << endl;	// 32
	cout << "□"; SetColor(0, 15); cout << "■■■■■■■■■■■■■■"; SetColor(14, 15); cout << "■■■"; SetColor(0, 15); cout << "■■■■■■■■■■■　밖으로　■■"; SetColor(9, 15); cout << "□" << endl;	// 33
	cout << "□"; SetColor(0, 15); cout << "■■■■■■■■■■■■■■"; SetColor(14, 15); cout << "　■　"; SetColor(0, 15); cout << "■■■■■■■■■■■　　　　　■■"; SetColor(9, 15); cout << "□" << endl;	// 34
	cout << "□"; SetColor(0, 15); cout << "■■■■■■■■■■■■■■"; SetColor(14, 15); cout << "■　■"; SetColor(0, 15); cout << "■■■■■■■■■■■　　　　　■■"; SetColor(9, 15); cout << "□" << endl;	// 35
	cout << "■"; SetColor(0, 15); cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■"; SetColor(9, 15); cout << "■" << endl;	// 36
	cout << "■■□□□■■■□□□■■■□□□■■■□□□■■■□□□■■■□□□■■" << endl;	// 37
}
void mainGame::HomeFieldScreen2()
{
	gotoxy(0, 0);
	SetColor(9, 15);

	cout << "■■□□□■■■□□□■■■□□□■■■□□□■■■□□□■■■□□□■■" << endl;	// 1
	cout << "■"; SetColor(0, 15); cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■"; SetColor(9, 15); cout << "■" << endl;	// 2
	cout << "□"; SetColor(0, 15); cout << "■■■■■■■■■■■■■■　　　　　　　■■■■■■■■■■■■■■"; SetColor(9, 15); cout << "□" << endl;	// 3
	cout << "□"; SetColor(0, 15); cout << "■■■■■■■■■■■■■■　　　　　　　■■■■■■■■■■■■■■"; SetColor(9, 15); cout << "□" << endl;	// 4
	cout << "□"; SetColor(0, 15); cout << "■■■■■■■■■■■■■■　　□□□　　■■■■■■■■■■■■■■"; SetColor(9, 15); cout << "□" << endl;	// 5
	cout << "■"; SetColor(0, 15); cout << "■■■■■■■■■■■■■■　　□□□　　■■■■■■■■■■■■■■"; SetColor(9, 15); cout << "■" << endl;	// 6
	cout << "■"; SetColor(0, 15); cout << "■■■■■■■■■■■■■■　　□□□　　■■■■■■■■■■■■■■"; SetColor(9, 15); cout << "■" << endl;	// 7
	cout << "■"; SetColor(0, 15); cout << "■■■■■■■■■■■■■■　　　　　　　■■■■■■■■■■■■■■"; SetColor(9, 15); cout << "■" << endl;	// 8
	cout << "□"; SetColor(0, 15); cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■"; SetColor(9, 15); cout << "□" << endl;	// 9
	cout << "□"; SetColor(0, 15); cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■"; SetColor(9, 15); cout << "□" << endl;	// 10
	cout << "□"; SetColor(0, 15); cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■"; SetColor(9, 15); cout << "□" << endl;	// 11
	cout << "■"; SetColor(0, 15); cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■"; SetColor(9, 15); cout << "■" << endl;	// 12
	cout << "■"; SetColor(0, 15); cout << "■　　■■■■■■■■■■■　　　　　　　　　　　　　　　　　　　　■"; SetColor(9, 15); cout << "■" << endl;	// 13
	cout << "■"; SetColor(0, 15); cout << "■　　■　　　　　　　　　■　　　　　　　　　　　　　　　　　　　　■"; SetColor(9, 15); cout << "■" << endl;	// 14
	cout << "□"; SetColor(0, 15); cout << "■　　■■■■　　　　　　■　　　　　　　　　　　　　　　　　　　　■"; SetColor(9, 15); cout << "□" << endl;	// 15
	cout << "□"; SetColor(0, 15); cout << "■　　■■　■　　　　　　■　　　　　　　　　　　　　　　　　　　　■"; SetColor(9, 15); cout << "□" << endl;	// 16
	cout << "□"; SetColor(0, 15); cout << "■　　■■　■　　　　　　■　　　　　　　　　　　　　　　　　　　　■"; SetColor(9, 15); cout << "□" << endl;	// 17
	cout << "■"; SetColor(0, 15); cout << "■　　■■■■　　　　　　■　　　　　　　　　　　　　　　　　　　　■"; SetColor(9, 15); cout << "■" << endl;	// 18
	cout << "■"; SetColor(0, 15); cout << "■　　■　　　　　　　　　■　　　　　　　　　　　　　　　　　　　　■"; SetColor(9, 15); cout << "■" << endl;	// 19
	cout << "■"; SetColor(0, 15); cout << "■　　■■■■■■■■■■■　　　　　　　　　　　　　　　　　　　　■"; SetColor(9, 15); cout << "■" << endl;	// 20
	cout << "□"; SetColor(0, 15); cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■"; SetColor(9, 15); cout << "□" << endl;	// 21
	cout << "□"; SetColor(0, 15); cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■"; SetColor(9, 15); cout << "□" << endl;	// 22
	cout << "□"; SetColor(0, 15); cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■"; SetColor(9, 15); cout << "□" << endl;	// 23
	cout << "■"; SetColor(0, 15); cout << "■■■■■■■■■■■■■■■　　　■■■■■■■■■■■■■■■■■"; SetColor(9, 15); cout << "■" << endl;	// 24
	cout << "■"; SetColor(0, 15); cout << "■■■■■■■■■■■■■■■　　　■■■■■■■■■■■■■■■■■"; SetColor(9, 15); cout << "■" << endl;	// 25
	cout << "■"; SetColor(0, 15); cout << "■■■■■■■■■■■■■■■　　　■■■■■■■■■■■■■■■■■"; SetColor(9, 15); cout << "■" << endl;	// 26
	cout << "□"; SetColor(0, 15); cout << "■■■■■■■■■■■■■■■　　　■■■■■■■■■■■■■■■■■"; SetColor(9, 15); cout << "□" << endl;	// 27
	cout << "□"; SetColor(0, 15); cout << "■■■■■■■■■■■■■■■　　　■■■■■■■■■■■■■■■■■"; SetColor(9, 15); cout << "□" << endl;	// 28
	cout << "□"; SetColor(0, 15); cout << "■■■■■■■■■■■■■■　　　　■■■■■■■■■■■■■■■■■"; SetColor(9, 15); cout << "□" << endl;	// 29
	cout << "■"; SetColor(0, 15); cout << "■■■■■■■■■■■■■■　　　■■■■■■■■■■■■■■■■■■"; SetColor(9, 15); cout << "■" << endl;	// 30
	cout << "■"; SetColor(0, 15); cout << "■■■■■■■■■■■■■■　　　■■■■■■■■■■■　　　　　■■"; SetColor(9, 15); cout << "■" << endl;	// 31
	cout << "■"; SetColor(0, 15); cout << "■■■■■■■■■■■■■■"; SetColor(14, 15); cout << "　■　"; SetColor(0, 15); cout << "■■■■■■■■■■■　　　　　■■"; SetColor(9, 15); cout << "■" << endl;	// 32
	cout << "□"; SetColor(0, 15); cout << "■■■■■■■■■■■■■■"; SetColor(14, 15); cout << "■■■"; SetColor(0, 15); cout << "■■■■■■■■■■■　밖으로　■■"; SetColor(9, 15); cout << "□" << endl;	// 33
	cout << "□"; SetColor(0, 15); cout << "■■■■■■■■■■■■■■"; SetColor(14, 15); cout << "　■　"; SetColor(0, 15); cout << "■■■■■■■■■■■　　　　　■■"; SetColor(9, 15); cout << "□" << endl;	// 34
	cout << "□"; SetColor(0, 15); cout << "■■■■■■■■■■■■■■"; SetColor(14, 15); cout << "■　■"; SetColor(0, 15); cout << "■■■■■■■■■■■　　　　　■■"; SetColor(9, 15); cout << "□" << endl;	// 35
	cout << "■"; SetColor(0, 15); cout << "■■■■■■■■■■■■■■　　　■■■■■■■■■■■■■■■■■■"; SetColor(9, 15); cout << "■" << endl;	// 36
	cout << "■■□□□■■■□□□■■■□□□■■■□□□■■■□□□■■■□□□■■" << endl;	// 37
}
void mainGame::HomeEmptyScreen()
{
	gotoxy(0, 0);
	SetColor(9, 15);

	cout << "■■□□□■■■□□□■■■□□□■■■□□□■■■□□□■■■□□□■■" << endl;	// 1
	cout << "■"; SetColor(0, 15); cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■"; SetColor(9, 15); cout << "■" << endl;	// 2
	cout << "□"; SetColor(0, 15); cout << "■■■■■■■■■■■■■■　　　　　　　■■■■■■■■■■■■■■"; SetColor(9, 15); cout << "□" << endl;	// 3
	cout << "□"; SetColor(0, 15); cout << "■■■■■■■■■■■■■■　　　　　　　■■■■■■■■■■■■■■"; SetColor(9, 15); cout << "□" << endl;	// 4
	cout << "□"; SetColor(0, 15); cout << "■■■■■■■■■■■■■■　　□□□　　■■■■■■■■■■■■■■"; SetColor(9, 15); cout << "□" << endl;	// 5
	cout << "■"; SetColor(0, 15); cout << "■■■■■■■■■■■■■■　　□□□　　■■■■■■■■■■■■■■"; SetColor(9, 15); cout << "■" << endl;	// 6
	cout << "■"; SetColor(0, 15); cout << "■■■■■■■■■■■■■■　　□□□　　■■■■■■■■■■■■■■"; SetColor(9, 15); cout << "■" << endl;	// 7
	cout << "■"; SetColor(0, 15); cout << "■■■■■■■■■■■■■■　　　　　　　■■■■■■■■■■■■■■"; SetColor(9, 15); cout << "■" << endl;	// 8
	cout << "□"; SetColor(0, 15); cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■"; SetColor(9, 15); cout << "□" << endl;	// 9
	cout << "□"; SetColor(0, 15); cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■"; SetColor(9, 15); cout << "□" << endl;	// 10
	cout << "□"; SetColor(0, 15); cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■"; SetColor(9, 15); cout << "□" << endl;	// 11
	cout << "■"; SetColor(0, 15); cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■"; SetColor(9, 15); cout << "■" << endl;	// 12
	cout << "■"; SetColor(0, 15); cout << "■　　■■■■■■■■■■■　　　　　　　　　　　　　　　　　　　　■"; SetColor(9, 15); cout << "■" << endl;	// 13
	cout << "■"; SetColor(0, 15); cout << "■　　■　　　　　　　　　■　　　　　　　　　　　　　　　　　　　　■"; SetColor(9, 15); cout << "■" << endl;	// 14
	cout << "□"; SetColor(0, 15); cout << "■　　■■■■　　　　　　■　　　　　　　　　　　　　　　　　　　　■"; SetColor(9, 15); cout << "□" << endl;	// 15
	cout << "□"; SetColor(0, 15); cout << "■　　■■　■　　　　　　■　　　　　　　　　　　　　　　　　　　　■"; SetColor(9, 15); cout << "□" << endl;	// 16
	cout << "□"; SetColor(0, 15); cout << "■　　■■　■　　　　　　■　　　　　　　　　　　　　　　　　　　　■"; SetColor(9, 15); cout << "□" << endl;	// 17
	cout << "■"; SetColor(0, 15); cout << "■　　■■■■　　　　　　■　　　　　　　　　　　　　　　　　　　　■"; SetColor(9, 15); cout << "■" << endl;	// 18
	cout << "■"; SetColor(0, 15); cout << "■　　■　　　　　　　　　■　　　　　　　　　　　　　　　　　　　　■"; SetColor(9, 15); cout << "■" << endl;	// 19
	cout << "■"; SetColor(0, 15); cout << "■　　■■■■■■■■■■■　　　　　　　　　　　　　　　　　　　　■"; SetColor(9, 15); cout << "■" << endl;	// 20
	cout << "□"; SetColor(0, 15); cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■"; SetColor(9, 15); cout << "□" << endl;	// 21
	cout << "□"; SetColor(0, 15); cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■"; SetColor(9, 15); cout << "□" << endl;	// 22
	cout << "□"; SetColor(0, 15); cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■"; SetColor(9, 15); cout << "□" << endl;	// 23
	cout << "■"; SetColor(0, 15); cout << "■■■■■■■■■■■■■■■　　　■■■■■■■■■■■■■■■■■"; SetColor(9, 15); cout << "■" << endl;	// 24
	cout << "■"; SetColor(0, 15); cout << "■■■■■■■■■■■■■■■　　　■■■■■■■■■■■■■■■■■"; SetColor(9, 15); cout << "■" << endl;	// 25
	cout << "■"; SetColor(0, 15); cout << "■■■■■■■■■■■■■■■　　　■■■■■■■■■■■■■■■■■"; SetColor(9, 15); cout << "■" << endl;	// 26
	cout << "□"; SetColor(0, 15); cout << "■■■■■■■■■■■■■■■　　　■■■■■■■■■■■■■■■■■"; SetColor(9, 15); cout << "□" << endl;	// 27
	cout << "□"; SetColor(0, 15); cout << "■■■■■■■■■■■■■■■　　　■■■■■■■■■■■■■■■■■"; SetColor(9, 15); cout << "□" << endl;	// 28
	cout << "□"; SetColor(0, 15); cout << "■■■■■■■■■■■■■■　　　　■■■■■■■■■■■■■■■■■"; SetColor(9, 15); cout << "□" << endl;	// 29
	cout << "■"; SetColor(0, 15); cout << "■■■■■■■■■■■■■■　　　■■■■■■■■■■■■■■■■■■"; SetColor(9, 15); cout << "■" << endl;	// 30
	cout << "■"; SetColor(0, 15); cout << "■■■■■■■■■■■■■■　　　■■■■■■■■■■■　　　　　■■"; SetColor(9, 15); cout << "■" << endl;	// 31
	cout << "■"; SetColor(0, 15); cout << "■■■■■■■■■■■■■■　　　■■■■■■■■■■■　　　　　■■"; SetColor(9, 15); cout << "■" << endl;	// 32
	cout << "□"; SetColor(0, 15); cout << "■■■■■■■■■■■■■■　　　■■■■■■■■■■■　　집　　■■"; SetColor(9, 15); cout << "□" << endl;	// 33
	cout << "□"; SetColor(0, 15); cout << "■■■■■■■■■■■■■■　　　■■■■■■■■■■■　　　　　■■"; SetColor(9, 15); cout << "□" << endl;	// 34
	cout << "□"; SetColor(0, 15); cout << "■■■■■■■■■■■■■■　　　■■■■■■■■■■■　　　　　■■"; SetColor(9, 15); cout << "□" << endl;	// 35
	cout << "■"; SetColor(0, 15); cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■"; SetColor(9, 15); cout << "■" << endl;	// 36
	cout << "■■□□□■■■□□□■■■□□□■■■□□□■■■□□□■■■□□□■■" << endl;	// 37
}
void mainGame::HomeEmptyScreen2()
{
	gotoxy(0, 0);
	SetColor(9, 15);

	cout << "■■□□□■■■□□□■■■□□□■■■□□□■■■□□□■■■□□□■■" << endl;	// 1
	cout << "■"; SetColor(0, 15); cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■"; SetColor(9, 15); cout << "■" << endl;	// 2
	cout << "□"; SetColor(0, 15); cout << "■■■■■■■■■■■■■■　　　　　　　■■■■■■■■■■■■■■"; SetColor(9, 15); cout << "□" << endl;	// 3
	cout << "□"; SetColor(0, 15); cout << "■■■■■■■■■■■■■■　　　　　　　■■■■■■■■■■■■■■"; SetColor(9, 15); cout << "□" << endl;	// 4
	cout << "□"; SetColor(0, 15); cout << "■■■■■■■■■■■■■■　　□□□　　■■■■■■■■■■■■■■"; SetColor(9, 15); cout << "□" << endl;	// 5
	cout << "■"; SetColor(0, 15); cout << "■■■■■■■■■■■■■■　　□□□　　■■■■■■■■■■■■■■"; SetColor(9, 15); cout << "■" << endl;	// 6
	cout << "■"; SetColor(0, 15); cout << "■■■■■■■■■■■■■■　　□□□　　■■■■■■■■■■■■■■"; SetColor(9, 15); cout << "■" << endl;	// 7
	cout << "■"; SetColor(0, 15); cout << "■■■■■■■■■■■■■■　　　　　　　■■■■■■■■■■■■■■"; SetColor(9, 15); cout << "■" << endl;	// 8
	cout << "□"; SetColor(0, 15); cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■"; SetColor(9, 15); cout << "□" << endl;	// 9
	cout << "□"; SetColor(0, 15); cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■"; SetColor(9, 15); cout << "□" << endl;	// 10
	cout << "□"; SetColor(0, 15); cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■"; SetColor(9, 15); cout << "□" << endl;	// 11
	cout << "■"; SetColor(0, 15); cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■"; SetColor(9, 15); cout << "■" << endl;	// 12
	cout << "■"; SetColor(0, 15); cout << "■　　■■■■■■■■■■■　　　　　　　　　　　　　　　　　　　　■"; SetColor(9, 15); cout << "■" << endl;	// 13
	cout << "■"; SetColor(0, 15); cout << "■　　■　　　　　　　　　■　　　　　　　　　　　　　　　　　　　　■"; SetColor(9, 15); cout << "■" << endl;	// 14
	cout << "□"; SetColor(0, 15); cout << "■　　■■■■　　　　　　■　　　　　　　　　　　　　　　　　　　　■"; SetColor(9, 15); cout << "□" << endl;	// 15
	cout << "□"; SetColor(0, 15); cout << "■　　■■　■　　　　　　■　　　　　　　　　　　　　　　　　　　　■"; SetColor(9, 15); cout << "□" << endl;	// 16
	cout << "□"; SetColor(0, 15); cout << "■　　■■　■　　　　　　■　　　　　　　　　　　　　　　　　　　　■"; SetColor(9, 15); cout << "□" << endl;	// 17
	cout << "■"; SetColor(0, 15); cout << "■　　■■■■　　　　　　■　　　　　　　　　　　　　　　　　　　　■"; SetColor(9, 15); cout << "■" << endl;	// 18
	cout << "■"; SetColor(0, 15); cout << "■　　■　　　　　　　　　■　　　　　　　　　　　　　　　　　　　　■"; SetColor(9, 15); cout << "■" << endl;	// 19
	cout << "■"; SetColor(0, 15); cout << "■　　■■■■■■■■■■■　　　　　　　　　　　　　　　　　　　　■"; SetColor(9, 15); cout << "■" << endl;	// 20
	cout << "□"; SetColor(0, 15); cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■"; SetColor(9, 15); cout << "□" << endl;	// 21
	cout << "□"; SetColor(0, 15); cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■"; SetColor(9, 15); cout << "□" << endl;	// 22
	cout << "□"; SetColor(0, 15); cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■"; SetColor(9, 15); cout << "□" << endl;	// 23
	cout << "■"; SetColor(0, 15); cout << "■■■■■■■■■■■■■■■　　　■■■■■■■■■■■■■■■■■"; SetColor(9, 15); cout << "■" << endl;	// 24
	cout << "■"; SetColor(0, 15); cout << "■■■■■■■■■■■■■■■　　　■■■■■■■■■■■■■■■■■"; SetColor(9, 15); cout << "■" << endl;	// 25
	cout << "■"; SetColor(0, 15); cout << "■■■■■■■■■■■■■■■　　　■■■■■■■■■■■■■■■■■"; SetColor(9, 15); cout << "■" << endl;	// 26
	cout << "□"; SetColor(0, 15); cout << "■■■■■■■■■■■■■■■　　　■■■■■■■■■■■■■■■■■"; SetColor(9, 15); cout << "□" << endl;	// 27
	cout << "□"; SetColor(0, 15); cout << "■■■■■■■■■■■■■■■　　　■■■■■■■■■■■■■■■■■"; SetColor(9, 15); cout << "□" << endl;	// 28
	cout << "□"; SetColor(0, 15); cout << "■■■■■■■■■■■■■■　　　　■■■■■■■■■■■■■■■■■"; SetColor(9, 15); cout << "□" << endl;	// 29
	cout << "■"; SetColor(0, 15); cout << "■■■■■■■■■■■■■■　　　■■■■■■■■■■■■■■■■■■"; SetColor(9, 15); cout << "■" << endl;	// 30
	cout << "■"; SetColor(0, 15); cout << "■■■■■■■■■■■■■■　　　■■■■■■■■■■■　　　　　■■"; SetColor(9, 15); cout << "■" << endl;	// 31
	cout << "■"; SetColor(0, 15); cout << "■■■■■■■■■■■■■■　　　■■■■■■■■■■■　　　　　■■"; SetColor(9, 15); cout << "■" << endl;	// 32
	cout << "□"; SetColor(0, 15); cout << "■■■■■■■■■■■■■■　　　■■■■■■■■■■■　　집　　■■"; SetColor(9, 15); cout << "□" << endl;	// 33
	cout << "□"; SetColor(0, 15); cout << "■■■■■■■■■■■■■■　　　■■■■■■■■■■■　　　　　■■"; SetColor(9, 15); cout << "□" << endl;	// 34
	cout << "□"; SetColor(0, 15); cout << "■■■■■■■■■■■■■■　　　■■■■■■■■■■■　　　　　■■"; SetColor(9, 15); cout << "□" << endl;	// 35
	cout << "■"; SetColor(0, 15); cout << "■■■■■■■■■■■■■■　　　■■■■■■■■■■■■■■■■■■"; SetColor(9, 15); cout << "■" << endl;	// 36
	cout << "■■□□□■■■□□□■■■□□□■■■□□□■■■□□□■■■□□□■■" << endl;	// 37
}
void mainGame::HomeEventChoice()
{
	_key = '0';
	_key = _getch();

	if (_key == (char)LEFT)
	{
		switch (_homecheck)
		{
		case 1:
		case 3:
		{
			_homecheck = 2;
			HomeSleepScreen();
			HomeEventChoice();
		}
		break;
		default:
		{
			HomeEventChoice();
		}
		break;
		}
	}
	else if (_key == (char)RIGHT)
	{
		if (_homecheck == 2)
		{
			_homecheck = 3;
			HomeTempleScreen();
			HomeEventChoice();
		}
		else
		{
			HomeEventChoice();
		}
	}
	else if (_key == (char)UP)
	{
		if (_homecheck == 1 || _homecheck == 2)
		{
			_homecheck = 3;
			HomeTempleScreen();
			HomeEventChoice();
		}
		else
		{
			HomeEventChoice();
		}
	}
	else if (_key == (char)DOWN)
	{
		switch (_homecheck)
		{
		case 2:
		case 3:
		{
			_homecheck = 1;
			HomeFieldScreen();
			HomeEventChoice();
		}
		break;
		default:
		{
			HomeEventChoice();
		}
		break;
		}
	}
	else if (_key == (char)ESC)
	{
		_statuscheck = 1;
		Status();
	}
	else if (_key == (char)ENTER || _key == (char)SPACE)
	{
		if (_homecheck == 1)
		{
			HomeEventError1();
			Conversation();
			HomeFieldScreen();
			HomeEventChoice();
		}
		else if (_homecheck == 2)
		{
			HomeEventError2();
			Conversation();
			HomeSleepScreen();
			HomeEventChoice();
		}
		else if (_homecheck == 3)
		{
			HomeEventScreen();
			Conversation();
			_homecheck = 0;
			_tempPlace = 1; // 1 = home

			_effect = EtempleEnter; // effectsound
			Move(); // black screen 1000ms
			b_startMusic = false; // mainmusic off
			b_homeMusic = false; // mainmusic off
			Sleep(500);
		}
	}
	else
	{
		HomeEventChoice();
	}
}
/////////////////////////////////////////////
void mainGame::HomeEventError1()
{
	gotoxy(0, 0);
	SetColor(9, 15);

	cout << "■■□□□■■■□□□■■■□□□■■■□□□■■■□□□■■■□□□■■" << endl;	// 1
	cout << "■"; SetColor(0, 15); cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■"; SetColor(9, 15); cout << "■" << endl;	// 2
	cout << "□"; SetColor(0, 15); cout << "■■■■■■■■■■■■■■　　　　　　　■■■■■■■■■■■■■■"; SetColor(9, 15); cout << "□" << endl;	// 3
	cout << "□"; SetColor(0, 15); cout << "■■■■■■■■■■■■■■　　　　　　　■■■■■■■■■■■■■■"; SetColor(9, 15); cout << "□" << endl;	// 4
	cout << "□"; SetColor(0, 15); cout << "■■■■■■■■■■■■■■　　□□□　　■■■■■■■■■■■■■■"; SetColor(9, 15); cout << "□" << endl;	// 5
	cout << "■"; SetColor(0, 15); cout << "■■■■■■■■■■■■■■　　□□□　　■■■■■■■■■■■■■■"; SetColor(9, 15); cout << "■" << endl;	// 6
	cout << "■"; SetColor(0, 15); cout << "■■■■■■■■■■■■■■　　□□□　　■■■■■■■■■■■■■■"; SetColor(9, 15); cout << "■" << endl;	// 7
	cout << "■"; SetColor(0, 15); cout << "■■■■■■■■■■■■■■　　　　　　　■■■■■■■■■■■■■■"; SetColor(9, 15); cout << "■" << endl;	// 8
	cout << "□"; SetColor(0, 15); cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■"; SetColor(9, 15); cout << "□" << endl;	// 9
	cout << "□"; SetColor(0, 15); cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■"; SetColor(9, 15); cout << "□" << endl;	// 10
	cout << "□"; SetColor(0, 15); cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■"; SetColor(9, 15); cout << "□" << endl;	// 11
	cout << "■"; SetColor(0, 15); cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■"; SetColor(9, 15); cout << "■" << endl;	// 12
	cout << "■"; SetColor(0, 15); cout << "■　　■■■■■■■■■■■　　　　　　　　　　　　　　　　　　　　■"; SetColor(9, 15); cout << "■" << endl;	// 13
	cout << "■"; SetColor(0, 15); cout << "■　　■　　　　　　　　　■　　　　　　　　　　　　　　　　　　　　■"; SetColor(9, 15); cout << "■" << endl;	// 14
	cout << "□"; SetColor(0, 15); cout << "■　　■■■■　　　　　　■　　　　　　　　　　　　　　　　　　　　■"; SetColor(9, 15); cout << "□" << endl;	// 15
	cout << "□"; SetColor(0, 15); cout << "■　　■■　■　　　　　　■　　　　　　　　　　　　　　　　　　　　■"; SetColor(9, 15); cout << "□" << endl;	// 16
	cout << "□"; SetColor(0, 15); cout << "■　　■■　■　　　　　　■　　　　　　　　　　　　　　　　　　　　■"; SetColor(9, 15); cout << "□" << endl;	// 17
	cout << "■"; SetColor(0, 15); cout << "■　　■■■■　　　　　　■　　　　　　　　　　　　　　　　　　　　■"; SetColor(9, 15); cout << "■" << endl;	// 18
	cout << "■"; SetColor(0, 15); cout << "■　　■　　　　　　　　　■　　　　　　　　　　　　　　　　　　　　■"; SetColor(9, 15); cout << "■" << endl;	// 19
	cout << "■"; SetColor(0, 15); cout << "■　　■■■■■■■■■■■　　　　　　　　　　　　　　　　　　　　■"; SetColor(9, 15); cout << "■" << endl;	// 20
	cout << "□"; SetColor(0, 15); cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■"; SetColor(9, 15); cout << "□" << endl;	// 21
	cout << "□"; SetColor(0, 15); cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■"; SetColor(9, 15); cout << "□" << endl;	// 22
	cout << "□"; SetColor(0, 15); cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■"; SetColor(9, 15); cout << "□" << endl;	// 23
	cout << "■"; SetColor(0, 15); cout << "■■■■■■■■■■■■■■■　　　■■■■■■■■■■■■■■■■■"; SetColor(9, 15); cout << "■" << endl;	// 24
	cout << "■"; SetColor(0, 15); cout << "■■■■■■■■■■■■■■■　　　■■■■■■■■■■■■■■■■■"; SetColor(9, 15); cout << "■" << endl;	// 25
	cout << "■"; SetColor(0, 15); cout << "■■■■■■■■■■■■■■■　　　■■■■■■■■■■■■■■■■■"; SetColor(9, 15); cout << "■" << endl;	// 26

	SetColor(13, 15);

	cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;
	cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
	cout << "■"; SetColor(0, 15); cout << "　　[아타호]　　　　　　　　　　　　　　　　　　　　　　　　　　　　　"; SetColor(13, 15); cout << "■" << endl;
	cout << "■"; SetColor(0, 15); cout << "　　내 정신 좀 봐라 치매가 오려는건가　　 　　　　　　　　 　　　　　 "; SetColor(13, 15); cout << "■" << endl;
	cout << "■"; SetColor(0, 15); cout << "　　어서 이아님을 뵈러 가자　　　　　　　 　　　　　　　　　　  　　　"; SetColor(13, 15); cout << "■" << endl;
	cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
	cout << "■"; SetColor(0, 15); cout << "　　(이아 여신은 제단을 통해 만날 수 있다) 　 　　　　　　　　　　　　"; SetColor(13, 15); cout << "■" << endl;
	cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
	cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
	cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
	cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;
}
void mainGame::HomeEventError2()
{
	gotoxy(0, 0);
	SetColor(9, 15);

	cout << "■■□□□■■■□□□■■■□□□■■■□□□■■■□□□■■■□□□■■" << endl;	// 1
	cout << "■"; SetColor(0, 15); cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■"; SetColor(9, 15); cout << "■" << endl;	// 2
	cout << "□"; SetColor(0, 15); cout << "■■■■■■■■■■■■■■　　　　　　　■■■■■■■■■■■■■■"; SetColor(9, 15); cout << "□" << endl;	// 3
	cout << "□"; SetColor(0, 15); cout << "■■■■■■■■■■■■■■　　　　　　　■■■■■■■■■■■■■■"; SetColor(9, 15); cout << "□" << endl;	// 4
	cout << "□"; SetColor(0, 15); cout << "■■■■■■■■■■■■■■　　□□□　　■■■■■■■■■■■■■■"; SetColor(9, 15); cout << "□" << endl;	// 5
	cout << "■"; SetColor(0, 15); cout << "■■■■■■■■■■■■■■　　□□□　　■■■■■■■■■■■■■■"; SetColor(9, 15); cout << "■" << endl;	// 6
	cout << "■"; SetColor(0, 15); cout << "■■■■■■■■■■■■■■　　□□□　　■■■■■■■■■■■■■■"; SetColor(9, 15); cout << "■" << endl;	// 7
	cout << "■"; SetColor(0, 15); cout << "■■■■■■■■■■■■■■　　　　　　　■■■■■■■■■■■■■■"; SetColor(9, 15); cout << "■" << endl;	// 8
	cout << "□"; SetColor(0, 15); cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■"; SetColor(9, 15); cout << "□" << endl;	// 9
	cout << "□"; SetColor(0, 15); cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■"; SetColor(9, 15); cout << "□" << endl;	// 10
	cout << "□"; SetColor(0, 15); cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■"; SetColor(9, 15); cout << "□" << endl;	// 11
	cout << "■"; SetColor(0, 15); cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■"; SetColor(9, 15); cout << "■" << endl;	// 12
	cout << "■"; SetColor(0, 15); cout << "■　　■■■■■■■■■■■　　　　　　　　　　　　　　　　　　　　■"; SetColor(9, 15); cout << "■" << endl;	// 13
	cout << "■"; SetColor(0, 15); cout << "■　　■　　　　　　　　　■　　　　　　　　　　　　　　　　　　　　■"; SetColor(9, 15); cout << "■" << endl;	// 14
	cout << "□"; SetColor(0, 15); cout << "■　　■■■"; SetColor(14, 15); cout << "■　■"; SetColor(0, 15); cout << "　　　　■　　　　　　　　　　　　　　　　　　　　■"; SetColor(9, 15); cout << "□" << endl;	// 15
	cout << "□"; SetColor(0, 15); cout << "■　　■■"; SetColor(14, 15); cout << "■■■"; SetColor(0, 15); cout << "　　　　　■　　　　　　　　　　　　　　　　　　　　■"; SetColor(9, 15); cout << "□" << endl;	// 16
	cout << "□"; SetColor(0, 15); cout << "■　　■■　"; SetColor(14, 15); cout << "■　■"; SetColor(0, 15); cout << "　　　　■　　　　　　　　　　　　　　　　　　　　■"; SetColor(9, 15); cout << "□" << endl;	// 17
	cout << "■"; SetColor(0, 15); cout << "■　　■■■■　　　　　　■　　　　　　　　　　　　　　　　　　　　■"; SetColor(9, 15); cout << "■" << endl;	// 18
	cout << "■"; SetColor(0, 15); cout << "■　　■　　　　　　　　　■　　　　　　　　　　　　　　　　　　　　■"; SetColor(9, 15); cout << "■" << endl;	// 19
	cout << "■"; SetColor(0, 15); cout << "■　　■■■■■■■■■■■　　　　　　　　　　　　　　　　　　　　■"; SetColor(9, 15); cout << "■" << endl;	// 20
	cout << "□"; SetColor(0, 15); cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■"; SetColor(9, 15); cout << "□" << endl;	// 21
	cout << "□"; SetColor(0, 15); cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■"; SetColor(9, 15); cout << "□" << endl;	// 22
	cout << "□"; SetColor(0, 15); cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■"; SetColor(9, 15); cout << "□" << endl;	// 23
	cout << "■"; SetColor(0, 15); cout << "■■■■■■■■■■■■■■■　　　■■■■■■■■■■■■■■■■■"; SetColor(9, 15); cout << "■" << endl;	// 24
	cout << "■"; SetColor(0, 15); cout << "■■■■■■■■■■■■■■■　　　■■■■■■■■■■■■■■■■■"; SetColor(9, 15); cout << "■" << endl;	// 25
	cout << "■"; SetColor(0, 15); cout << "■■■■■■■■■■■■■■■　　　■■■■■■■■■■■■■■■■■"; SetColor(9, 15); cout << "■" << endl;	// 26

	SetColor(13, 15);

	cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;
	cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
	cout << "■"; SetColor(0, 15); cout << "　　[아타호]　　　　　　　　　　　　　　　　　　　　　　　　　　　　　"; SetColor(13, 15); cout << "■" << endl;
	cout << "■"; SetColor(0, 15); cout << "　　한가롭게 자고나 있을때가 아니지 참　　　　　　　　　　 　　　　　 "; SetColor(13, 15); cout << "■" << endl;
	cout << "■"; SetColor(0, 15); cout << "　　어서 이아님을 뵈러 가자　　　　　　　 　　　　　　　　　　  　　　"; SetColor(13, 15); cout << "■" << endl;
	cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
	cout << "■"; SetColor(0, 15); cout << "　　(이아 여신은 제단을 통해 만날 수 있다)  　　　　　　　　　　　　　"; SetColor(13, 15); cout << "■" << endl;
	cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
	cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
	cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
	cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;

}
void mainGame::HomeEventScreen()
{
	gotoxy(0, 0);
	SetColor(9, 15);

	cout << "■■□□□■■■□□□■■■□□□■■■□□□■■■□□□■■■□□□■■" << endl;	// 1
	cout << "■"; SetColor(0, 15); cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■"; SetColor(9, 15); cout << "■" << endl;	// 2
	cout << "□"; SetColor(0, 15); cout << "■■■■■■■■■■■■■■　　　　　　　■■■■■■■■■■■■■■"; SetColor(9, 15); cout << "□" << endl;	// 3
	cout << "□"; SetColor(0, 15); cout << "■■■■■■■■■■■■■■　　　　　　　■■■■■■■■■■■■■■"; SetColor(9, 15); cout << "□" << endl;	// 4
	cout << "□"; SetColor(0, 15); cout << "■■■■■■■■■■■■■■　　□□□　　■■■■■■■■■■■■■■"; SetColor(9, 15); cout << "□" << endl;	// 5
	cout << "■"; SetColor(0, 15); cout << "■■■■■■■■■■■■■■　　□□□　　■■■■■■■■■■■■■■"; SetColor(9, 15); cout << "■" << endl;	// 6
	cout << "■"; SetColor(0, 15); cout << "■■■■■■■■■■■■■■　　□"; SetColor(14, 15); cout << "■"; SetColor(0, 15); cout << "□　　■■■■■■■■■■■■■■"; SetColor(9, 15); cout << "■" << endl;	// 7
	cout << "■"; SetColor(0, 15); cout << "■■■■■■■■■■■■■■　　"; SetColor(14, 15); cout << "■■■"; SetColor(0, 15); cout << "　　■■■■■■■■■■■■■■"; SetColor(9, 15); cout << "■" << endl;	// 8
	cout << "□"; SetColor(0, 15); cout << "■　　　　　　　　　　　　　　　　"; SetColor(14, 15); cout << "■"; SetColor(0, 15); cout << "　　　　　　　　　　　　　　　　■"; SetColor(9, 15); cout << "□" << endl;	// 9
	cout << "□"; SetColor(0, 15); cout << "■　　　　　　　　　　　　　　　"; SetColor(14, 15); cout << "■　■"; SetColor(0, 15); cout << "　　　　　　　　　　　　　　　■"; SetColor(9, 15); cout << "□" << endl;	// 10
	cout << "□"; SetColor(0, 15); cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■"; SetColor(9, 15); cout << "□" << endl;	// 11
	cout << "■"; SetColor(0, 15); cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■"; SetColor(9, 15); cout << "■" << endl;	// 12
	cout << "■"; SetColor(0, 15); cout << "■　　■■■■■■■■■■■　　　　　　　　　　　　　　　　　　　　■"; SetColor(9, 15); cout << "■" << endl;	// 13
	cout << "■"; SetColor(0, 15); cout << "■　　■　　　　　　　　　■　　　　　　　　　　　　　　　　　　　　■"; SetColor(9, 15); cout << "■" << endl;	// 14
	cout << "□"; SetColor(0, 15); cout << "■　　■■■■　　　　　　■　　　　　　　　　　　　　　　　　　　　■"; SetColor(9, 15); cout << "□" << endl;	// 15
	cout << "□"; SetColor(0, 15); cout << "■　　■■　■　　　　　　■　　　　　　　　　　　　　　　　　　　　■"; SetColor(9, 15); cout << "□" << endl;	// 16
	cout << "□"; SetColor(0, 15); cout << "■　　■■　■　　　　　　■　　　　　　　　　　　　　　　　　　　　■"; SetColor(9, 15); cout << "□" << endl;	// 17
	cout << "■"; SetColor(0, 15); cout << "■　　■■■■　　　　　　■　　　　　　　　　　　　　　　　　　　　■"; SetColor(9, 15); cout << "■" << endl;	// 18
	cout << "■"; SetColor(0, 15); cout << "■　　■　　　　　　　　　■　　　　　　　　　　　　　　　　　　　　■"; SetColor(9, 15); cout << "■" << endl;	// 19
	cout << "■"; SetColor(0, 15); cout << "■　　■■■■■■■■■■■　　　　　　　　　　　　　　　　　　　　■"; SetColor(9, 15); cout << "■" << endl;	// 20
	cout << "□"; SetColor(0, 15); cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■"; SetColor(9, 15); cout << "□" << endl;	// 21
	cout << "□"; SetColor(0, 15); cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■"; SetColor(9, 15); cout << "□" << endl;	// 22
	cout << "□"; SetColor(0, 15); cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■"; SetColor(9, 15); cout << "□" << endl;	// 23
	cout << "■"; SetColor(0, 15); cout << "■■■■■■■■■■■■■■■　　　■■■■■■■■■■■■■■■■■"; SetColor(9, 15); cout << "■" << endl;	// 24
	cout << "■"; SetColor(0, 15); cout << "■■■■■■■■■■■■■■■　　　■■■■■■■■■■■■■■■■■"; SetColor(9, 15); cout << "■" << endl;	// 25
	cout << "■"; SetColor(0, 15); cout << "■■■■■■■■■■■■■■■　　　■■■■■■■■■■■■■■■■■"; SetColor(9, 15); cout << "■" << endl;	// 26

	SetColor(13, 15);

	cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;
	cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
	cout << "■"; SetColor(0, 15); cout << "　　[아타호]　　　　　　　　　　　　　　　　　　　　　　　　　　　　　"; SetColor(13, 15); cout << "■" << endl;
	cout << "■"; SetColor(0, 15); cout << "　　이아님을 뵙는 것도 오랜만이군　　　　 　　　　　　　　 　　　　　 "; SetColor(13, 15); cout << "■" << endl;
	cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
	cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
	cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
	cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
	cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
	cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
	cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;

}
/////////////////////////////////////////////
void mainGame::IahEvent()
{
	_iahcheck = 1;
	b_iahScreen = true;
	b_iahMusic = true;
	Sleep(1500);
	_effect = EtempleEnter;
	Sleep(600);
	if (_tempPlace == 1)
	{
		_iahcheck = 2;
	}
	else if (_tempPlace == 2)
	{
		_iahcheck = 15;
	}
	IahChoice();
}
void mainGame::IahJobCheck()
{
	if (_characterJob == "평민")
	{
		_iahcheck = 4;
	}
	else
	{
		_iahcheck = 8;
	}
}


void mainGame::IahScreen()
{
	for (int i = 0; i >= 0; i++)
	{
		if (b_iahScreen == false)
		{
			break;
		}

		gotoxy(0, 0);
		SetColor(9, 15);

		if (i % 2 == 0)
		{
			cout << "■■□□□■■■□□□■■■□□□■■■□□□■■■□□□■■■□□□■■" << endl;	// 1
			cout << "■"; SetColor(0, 15); cout << "　　■　　　　■　　■　　　　　　　　　　■　■■　　　　　　　　　　"; SetColor(9, 15); cout << "■" << endl;	// 2
			cout << "□"; SetColor(0, 15); cout << "　　■　　　　■　■　　　　　　　　　　　■　■■　　　　　　　　　　"; SetColor(9, 15); cout << "□" << endl;	// 3
			cout << "□"; SetColor(0, 15); cout << "　　■　　　　■■　　■■　　　　　　　　■　■■　　　　　　　　　　"; SetColor(9, 15); cout << "□" << endl;	// 4
			cout << "□"; SetColor(0, 15); cout << "　　■　　　　■　　■　　■　　　　　　　■　■■■■"; SetColor(10, 15); cout << "□"; SetColor(0, 15); cout << "■■■■■■■"; SetColor(9, 15); cout << "□" << endl;	// 5
			cout << "■"; SetColor(0, 15); cout << "　　■　　　■　　　■■■■　　　　　　　■■■　　"; SetColor(10, 15); cout << "□□□"; SetColor(0, 15); cout << "　　　　　　"; SetColor(9, 15); cout << "■" << endl;	// 6
			cout << "■"; SetColor(0, 15); cout << "　　■　　■　　　　■　■■　　　　　　■　　　　　"; SetColor(10, 15); cout << "□□□"; SetColor(0, 15); cout << "　　　　　　"; SetColor(9, 15); cout << "■" << endl;	// 7
			cout << "■"; SetColor(0, 15); cout << "　　■　■　　　　　■　■■　　　　　■　　　　　　　"; SetColor(10, 15); cout << "□"; SetColor(0, 15); cout << "　　　　　　　"; SetColor(9, 15); cout << "■" << endl;	// 8
			cout << "□"; SetColor(0, 15); cout << "　　■■　　　　　　■　■■　　　　■　　　　　　　"; SetColor(10, 15); cout << "□□□"; SetColor(0, 15); cout << "　　　　　　"; SetColor(9, 15); cout << "□" << endl;	// 9
			cout << "□"; SetColor(0, 15); cout << "　　■　　　　　　　■　■■　　　■　　　　　　　"; SetColor(10, 15); cout << "□　□　□"; SetColor(0, 15); cout << "　　　　　"; SetColor(9, 15); cout << "□" << endl;	// 10
			cout << "□"; SetColor(0, 15); cout << "　■　　　　　　　　■　■■　　■　　　　　　　　　"; SetColor(10, 15); cout << "□□□"; SetColor(0, 15); cout << "　　　　　　"; SetColor(9, 15); cout << "□" << endl;	// 11
			cout << "■"; SetColor(0, 15); cout << "■　　　　　　　　　■　■■　■　　　　　　　　　"; SetColor(10, 15); cout << "□□□□□"; SetColor(0, 15); cout << "　　　　　"; SetColor(9, 15); cout << "■" << endl;	// 12
			cout << "■"; SetColor(0, 15); cout << "　　　　　　　　　　■　■■■　　　　　　　　　　"; SetColor(10, 15); cout << "□□□□□"; SetColor(0, 15); cout << "　　　　　"; SetColor(9, 15); cout << "■" << endl;	// 13
			cout << "■"; SetColor(0, 15); cout << "　　　　　　　　　　■　■■　　　　　　　　　　　　　　　　　　　　　"; SetColor(9, 15); cout << "■" << endl;	// 14
			cout << "□"; SetColor(0, 15); cout << "　　　　　　　　　　■　■■　　　　　　　　　　　　　　　　　　　　　"; SetColor(9, 15); cout << "□" << endl;	// 15
			cout << "□"; SetColor(0, 15); cout << "　　　　　　　　　　■　■■　　　　　　　　　　　　　　　　　　　　　"; SetColor(9, 15); cout << "□" << endl;	// 16
			cout << "□"; SetColor(0, 15); cout << "　　　　　　　　　　■　■■　　　　　　　　　　　　　　　　　　　　　"; SetColor(9, 15); cout << "□" << endl;	// 17
			cout << "■"; SetColor(0, 15); cout << "　　　　　　　　　　■■■■■■■■■■■■■■■■■■■■■■■■■"; SetColor(9, 15); cout << "■" << endl;	// 18

			IahScreen1();
		}
		else
		{
			cout << "■■□□□■■■□□□■■■□□□■■■□□□■■■□□□■■■□□□■■" << endl;	// 1
			cout << "■"; SetColor(0, 15); cout << "　　■　　　　■　　■　　　　　　　　　　■　■■　　　　　　　　　　"; SetColor(9, 15); cout << "■" << endl;	// 2
			cout << "□"; SetColor(0, 15); cout << "　　■　　　　■　■　　　　　　　　　　　■　■■　　　　　　　　　　"; SetColor(9, 15); cout << "□" << endl;	// 3
			cout << "□"; SetColor(0, 15); cout << "　　■　　　　■■　　■■　　　　　　　　■　■■　　　　　　　　　　"; SetColor(9, 15); cout << "□" << endl;	// 4
			cout << "□"; SetColor(0, 15); cout << "　　■　　　　■　　■　　■　　　　　　　■　■■■■"; SetColor(10, 15); cout << "■"; SetColor(0, 15); cout << "■■■■■■■"; SetColor(9, 15); cout << "□" << endl;	// 5
			cout << "■"; SetColor(0, 15); cout << "　　■　　　■　　　■■■■　　　　　　　■■■　　"; SetColor(10, 15); cout << "■■■"; SetColor(0, 15); cout << "　　　　　　"; SetColor(9, 15); cout << "■" << endl;	// 6
			cout << "■"; SetColor(0, 15); cout << "　　■　　■　　　　■　■■　　　　　　■　　　　　"; SetColor(10, 15); cout << "■■■"; SetColor(0, 15); cout << "　　　　　　"; SetColor(9, 15); cout << "■" << endl;	// 7
			cout << "■"; SetColor(0, 15); cout << "　　■　■　　　　　■　■■　　　　　■　　　　　　　"; SetColor(10, 15); cout << "■"; SetColor(0, 15); cout << "　　　　　　　"; SetColor(9, 15); cout << "■" << endl;	// 8
			cout << "□"; SetColor(0, 15); cout << "　　■■　　　　　　■　■■　　　　■　　　　　　　"; SetColor(10, 15); cout << "■■■"; SetColor(0, 15); cout << "　　　　　　"; SetColor(9, 15); cout << "□" << endl;	// 9
			cout << "□"; SetColor(0, 15); cout << "　　■　　　　　　　■　■■　　　■　　　　　　　"; SetColor(10, 15); cout << "■　■　■"; SetColor(0, 15); cout << "　　　　　"; SetColor(9, 15); cout << "□" << endl;	// 10
			cout << "□"; SetColor(0, 15); cout << "　■　　　　　　　　■　■■　　■　　　　　　　　　"; SetColor(10, 15); cout << "■■■"; SetColor(0, 15); cout << "　　　　　　"; SetColor(9, 15); cout << "□" << endl;	// 11
			cout << "■"; SetColor(0, 15); cout << "■　　　　　　　　　■　■■　■　　　　　　　　　"; SetColor(10, 15); cout << "■■■■■"; SetColor(0, 15); cout << "　　　　　"; SetColor(9, 15); cout << "■" << endl;	// 12
			cout << "■"; SetColor(0, 15); cout << "　　　　　　　　　　■　■■■　　　　　　　　　　"; SetColor(10, 15); cout << "■■■■■"; SetColor(0, 15); cout << "　　　　　"; SetColor(9, 15); cout << "■" << endl;	// 13
			cout << "■"; SetColor(0, 15); cout << "　　　　　　　　　　■　■■　　　　　　　　　　　　　　　　　　　　　"; SetColor(9, 15); cout << "■" << endl;	// 14
			cout << "□"; SetColor(0, 15); cout << "　　　　　　　　　　■　■■　　　　　　　　　　　　　　　　　　　　　"; SetColor(9, 15); cout << "□" << endl;	// 15
			cout << "□"; SetColor(0, 15); cout << "　　　　　　　　　　■　■■　　　　　　　　　　　　　　　　　　　　　"; SetColor(9, 15); cout << "□" << endl;	// 16
			cout << "□"; SetColor(0, 15); cout << "　　　　　　　　　　■　■■　　　　　　　　　　　　　　　　　　　　　"; SetColor(9, 15); cout << "□" << endl;	// 17
			cout << "■"; SetColor(0, 15); cout << "　　　　　　　　　　■■■■■■■■■■■■■■■■■■■■■■■■■"; SetColor(9, 15); cout << "■" << endl;	// 18

			IahScreen1();
		}
		std::this_thread::sleep_for(std::chrono::milliseconds(800));
	}
}
void mainGame::IahScreen1()
{
	switch (_iahcheck)
	{
	case 1:
	{
		cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;	// 19
		cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;	// 20
		cout << "□　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　□" << endl;	// 21
		cout << "□　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　□" << endl;	// 22
		cout << "□　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　□" << endl;	// 23
		cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;	// 24
		cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;	// 25
		cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;	// 26
		cout << "□　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　□" << endl;	// 27
		cout << "□　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　□" << endl;	// 28
		cout << "□"; SetColor(0, 15); cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　■■■■■■■　"; SetColor(9, 15); cout << "□" << endl;	// 29
		cout << "■"; SetColor(0, 15); cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　■　　　　　■　"; SetColor(9, 15); cout << "■" << endl;	// 30
		cout << "■"; SetColor(0, 15); cout << "　□□□　　　　　　　　　　　　　　　　　　　　　　　■　빛　의　■　"; SetColor(9, 15); cout << "■" << endl;	// 31
		cout << "■"; SetColor(0, 15); cout << "　□□□　　　　　　　　　　　　　　　　　　　　　　　■　　　　　■　"; SetColor(9, 15); cout << "■" << endl;	// 32
		cout << "□"; SetColor(0, 15); cout << "　□□□　　　　　　　　　　　　　　　　　　　　　　　■　정　원　■　"; SetColor(9, 15); cout << "□" << endl;	// 33
		cout << "□"; SetColor(0, 15); cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　■　　　　　■　"; SetColor(9, 15); cout << "□" << endl;	// 34
		cout << "□"; SetColor(0, 15); cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　■■■■■■■　"; SetColor(9, 15); cout << "□" << endl;	// 35
		cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;	// 36
		cout << "■■□□□■■■□□□■■■□□□■■■□□□■■■□□□■■■□□□■■" << endl;	// 37
	}
	break;

	case 2:
	{
		cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;	// 19
		cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;	// 20
		cout << "□　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　□" << endl;	// 21
		cout << "□　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　□" << endl;	// 22
		cout << "□　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　□" << endl;	// 23
		cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;	// 24
		cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;	// 25
		cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;	// 26
		cout << "□　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　□" << endl;	// 27
		cout << "□　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　□" << endl;	// 28
		cout << "□"; SetColor(0, 15); cout << "　　　　　"; SetColor(14, 15); cout << "　　　　　　　　　　　　　　　　　　　　　　"; SetColor(0, 15); cout << "■■■■■■■　"; SetColor(9, 15); cout << "□" << endl;	// 29
		cout << "■"; SetColor(0, 15); cout << "　　　　　"; SetColor(14, 15); cout << "　■　　　　　　　　　　　　　　　　　　　　"; SetColor(0, 15); cout << "■　　　　　■　"; SetColor(9, 15); cout << "■" << endl;	// 30
		cout << "■"; SetColor(0, 15); cout << "　□□□　"; SetColor(14, 15); cout << "■■■　　　　　　　　　　　　　　　　　　　"; SetColor(0, 15); cout << "■　인간계　■　"; SetColor(9, 15); cout << "■" << endl;	// 31
		cout << "■"; SetColor(0, 15); cout << "　□□□　"; SetColor(14, 15); cout << "　■　　　　　　　　　　　　　　　　　　　　"; SetColor(0, 15); cout << "■　　　　　■　"; SetColor(9, 15); cout << "■" << endl;	// 32
		cout << "□"; SetColor(0, 15); cout << "　□□□　"; SetColor(14, 15); cout << "■　■　　　　　　　　　　　　　　　　　　　"; SetColor(0, 15); cout << "■　 (집) 　■　"; SetColor(9, 15); cout << "□" << endl;	// 33
		cout << "□"; SetColor(0, 15); cout << "　　　　　"; SetColor(14, 15); cout << "　　　　　　　　　　　　　　　　　　　　　　"; SetColor(0, 15); cout << "■　　　　　■　"; SetColor(9, 15); cout << "□" << endl;	// 34
		cout << "□"; SetColor(0, 15); cout << "　　　　　"; SetColor(14, 15); cout << "　　　　　　　　　　　　　　　　　　　　　　"; SetColor(0, 15); cout << "■■■■■■■　"; SetColor(9, 15); cout << "□" << endl;	// 35
		cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;	// 36
		cout << "■■□□□■■■□□□■■■□□□■■■□□□■■■□□□■■■□□□■■" << endl;	// 37
	}
	break;

	case 3:
	{
		cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;	// 19
		cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;	// 20
		cout << "□"; SetColor(14, 15); cout << "　　　　　　　　　　　　　　　　　　　　■　　　　　　　　　　　　　　"; SetColor(9, 15); cout << "□" << endl;	// 21
		cout << "□"; SetColor(14, 15); cout << "　　　　　　　　　　　　　　　　　　　■■■　　　　　　　　　　　　　"; SetColor(9, 15); cout << "□" << endl;	// 22
		cout << "□"; SetColor(14, 15); cout << "　　　　　　　　　　　　　　　　　　　　■　　　　　　　　　　　　　　"; SetColor(9, 15); cout << "□" << endl;	// 23
		cout << "■"; SetColor(14, 15); cout << "　　　　　　　　　　　　　　　　　　　■　■　　　　　　　　　　　　　"; SetColor(9, 15); cout << "■" << endl;	// 24
		cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;	// 25
		cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;	// 26
		cout << "□　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　□" << endl;	// 27
		cout << "□　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　□" << endl;	// 28
		cout << "□"; SetColor(0, 15); cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　■■■■■■■　"; SetColor(9, 15); cout << "□" << endl;	// 29
		cout << "■"; SetColor(0, 15); cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　■　　　　　■　"; SetColor(9, 15); cout << "■" << endl;	// 30
		cout << "■"; SetColor(0, 15); cout << "　□□□　　　　　　　　　　　　　　　　　　　　　　　■　　　　　■　"; SetColor(9, 15); cout << "■" << endl;	// 31
		cout << "■"; SetColor(0, 15); cout << "　□□□　　　　　　　　　　　　　　　　　　　　　　　■　이　아　■　"; SetColor(9, 15); cout << "■" << endl;	// 32
		cout << "□"; SetColor(0, 15); cout << "　□□□　　　　　　　　　　　　　　　　　　　　　　　■　　　　　■　"; SetColor(9, 15); cout << "□" << endl;	// 33
		cout << "□"; SetColor(0, 15); cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　■　　　　　■　"; SetColor(9, 15); cout << "□" << endl;	// 34
		cout << "□"; SetColor(0, 15); cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　■■■■■■■　"; SetColor(9, 15); cout << "□" << endl;	// 35
		cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;	// 36
		cout << "■■□□□■■■□□□■■■□□□■■■□□□■■■□□□■■■□□□■■" << endl;	// 37

	}
	break;

	case 4:
	{
		cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;	// 19
		cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;	// 20
		cout << "□"; SetColor(14, 15); cout << "　　　　　　　　　　　　　　　　　　　　■　　　　　　　　　　　　　　"; SetColor(9, 15); cout << "□" << endl;	// 21
		cout << "□"; SetColor(14, 15); cout << "　　　　　　　　　　　　　　　　　　　■■■　　　　　　　　　　　　　"; SetColor(9, 15); cout << "□" << endl;	// 22
		cout << "□"; SetColor(14, 15); cout << "　　　　　　　　　　　　　　　　　　　　■　　　　　　　　　　　　　　"; SetColor(9, 15); cout << "□" << endl;	// 23
		cout << "■"; SetColor(14, 15); cout << "　　　　　　　　　　　　　　　　　　　■　■　　　　　　　　　　　　　"; SetColor(9, 15); cout << "■" << endl;	// 24
		cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;	// 25
		cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;	// 26


		SetColor(13, 15);
		cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;
		cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
		cout << "■"; SetColor(0, 15); cout << "　　[이 아] 　　　　　　　　　　　　　　　　　　　　　　　　　　　　　"; SetColor(13, 15); cout << "■" << endl;
		cout << "■"; SetColor(0, 15); cout << "　　아타호 어서오세요. 기다리고 있었습니다.　　　　　　　　　　　　　 "; SetColor(13, 15); cout << "■" << endl;
		cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
		cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
		cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
		cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
		cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
		cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
		cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;
	}
	break;

	case 5:
	{
		cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;	// 19
		cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;	// 20
		cout << "□"; SetColor(14, 15); cout << "　　　　　　　　　　　　　　　　　　　　■　　　　　　　　　　　　　　"; SetColor(9, 15); cout << "□" << endl;	// 21
		cout << "□"; SetColor(14, 15); cout << "　　　　　　　　　　　　　　　　　　　■■■　　　　　　　　　　　　　"; SetColor(9, 15); cout << "□" << endl;	// 22
		cout << "□"; SetColor(14, 15); cout << "　　　　　　　　　　　　　　　　　　　　■　　　　　　　　　　　　　　"; SetColor(9, 15); cout << "□" << endl;	// 23
		cout << "■"; SetColor(14, 15); cout << "　　　　　　　　　　　　　　　　　　　■　■　　　　　　　　　　　　　"; SetColor(9, 15); cout << "■" << endl;	// 24
		cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;	// 25
		cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;	// 26

		SetColor(13, 15);
		cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;
		cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
		cout << "■"; SetColor(0, 15); cout << "　　[아타호]　　　　　　　　　　　　　　　　　　　　　　　　　　　　　"; SetColor(13, 15); cout << "■" << endl;
		cout << "■"; SetColor(0, 15); cout << "　　이아님을 뵙습니다.　　　　　　　　　　　　　　　　　　　　　　　　"; SetColor(13, 15); cout << "■" << endl;
		cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
		cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
		cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
		cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
		cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
		cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
		cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;
	}
	break;

	case 6:
	{
		cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;	// 19
		cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;	// 20
		cout << "□"; SetColor(14, 15); cout << "　　　　　　　　　　　　　　　　　　　　■　　　　　　　　　　　　　　"; SetColor(9, 15); cout << "□" << endl;	// 21
		cout << "□"; SetColor(14, 15); cout << "　　　　　　　　　　　　　　　　　　　■■■　　　　　　　　　　　　　"; SetColor(9, 15); cout << "□" << endl;	// 22
		cout << "□"; SetColor(14, 15); cout << "　　　　　　　　　　　　　　　　　　　　■　　　　　　　　　　　　　　"; SetColor(9, 15); cout << "□" << endl;	// 23
		cout << "■"; SetColor(14, 15); cout << "　　　　　　　　　　　　　　　　　　　■　■　　　　　　　　　　　　　"; SetColor(9, 15); cout << "■" << endl;	// 24
		cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;	// 25
		cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;	// 26


		SetColor(13, 15);
		cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;
		cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
		cout << "■"; SetColor(0, 15); cout << "　　[이 아] 　　　　　　　　　　　　　　　　　　　　　　　　　　　　　"; SetColor(13, 15); cout << "■" << endl;
		cout << "■"; SetColor(0, 15); cout << "　　최근 일어나는 괴현상 때문에 온것일테죠.　　　　　　　　　　　　 　"; SetColor(13, 15); cout << "■" << endl;
		cout << "■"; SetColor(0, 15); cout << "　　이는 악의 화신 뮤레칸을 추종하는 세력들이 벌이는 짓일터,　　　　　"; SetColor(13, 15); cout << "■" << endl;
		cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
		cout << "■"; SetColor(0, 15); cout << "　　그들을 반드시 막아야합니다. 　　　　　　　　　　　　　　　　　　　"; SetColor(13, 15); cout << "■" << endl;
		cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
		cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
		cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
		cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;
	}
	break;

	case 7:
	{
		cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;	// 19
		cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;	// 20
		cout << "□"; SetColor(14, 15); cout << "　　　　　　　　　　　　　　　　　　　　■　　　　　　　　　　　　　　"; SetColor(9, 15); cout << "□" << endl;	// 21
		cout << "□"; SetColor(14, 15); cout << "　　　　　　　　　　　　　　　　　　　■■■　　　　　　　　　　　　　"; SetColor(9, 15); cout << "□" << endl;	// 22
		cout << "□"; SetColor(14, 15); cout << "　　　　　　　　　　　　　　　　　　　　■　　　　　　　　　　　　　　"; SetColor(9, 15); cout << "□" << endl;	// 23
		cout << "■"; SetColor(14, 15); cout << "　　　　　　　　　　　　　　　　　　　■　■　　　　　　　　　　　　　"; SetColor(9, 15); cout << "■" << endl;	// 24
		cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;	// 25
		cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;	// 26


		SetColor(13, 15);
		cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;
		cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
		cout << "■"; SetColor(0, 15); cout << "　　[이 아] 　　　　　　　　　　　　　　　　　　　　　　　　　　　　　"; SetColor(13, 15); cout << "■" << endl;
		cout << "■"; SetColor(0, 15); cout << "　　당신도 알다시피 저희 신들은 인간계에 간섭을 못하는 몸. 　　　　 　"; SetColor(13, 15); cout << "■" << endl;
		cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
		cout << "■"; SetColor(0, 15); cout << "　　매번 죄송하지만 이번에도 부탁드립니다 아타호.　　　　　　　 　　　"; SetColor(13, 15); cout << "■" << endl;
		cout << "■"; SetColor(0, 15); cout << "　　미약하지만 당신에게 도움이 될 힘을 드리겠습니다.　　　　　　　　　"; SetColor(13, 15); cout << "■" << endl;
		cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
		cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
		cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
		cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;
	}
	break;
	case 8:
	{
		cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;	// 19
		cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;	// 20
		cout << "□"; SetColor(14, 15); cout << "　　　　　　　　　　　　　　　　　　　　■　　　　　　　　　　　　　　"; SetColor(9, 15); cout << "□" << endl;	// 21
		cout << "□"; SetColor(14, 15); cout << "　　　　　　　　　　　　　　　　　　　■■■　　　　　　　　　　　　　"; SetColor(9, 15); cout << "□" << endl;	// 22
		cout << "□"; SetColor(14, 15); cout << "　　　　　　　　　　　　　　　　　　　　■　　　　　　　　　　　　　　"; SetColor(9, 15); cout << "□" << endl;	// 23
		cout << "■"; SetColor(14, 15); cout << "　　　　　　　　　　　　　　　　　　　■　■　　　　　　　　　　　　　"; SetColor(9, 15); cout << "■" << endl;	// 24
		cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;	// 25
		cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;	// 26


		SetColor(13, 15);
		cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;
		cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
		cout << "■"; SetColor(0, 15); cout << "　　[이 아] 　　　　　　　　　　　　　　　　　　　　　　　　　　　　　"; SetColor(13, 15); cout << "■" << endl;
		cout << "■"; SetColor(0, 15); cout << "　　두가지 직업 중 하나를 선택하면 거기에 알맞는 힘을 드리겠습니다. 　"; SetColor(13, 15); cout << "■" << endl;
		cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
		cout << "■"; SetColor(0, 15); cout << "　　▶　권법가　　　　　　　　　　　　　　　　　　　　　　　　　　　　"; SetColor(13, 15); cout << "■" << endl;
		cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
		cout << "■"; SetColor(0, 15); cout << "　　　　검　사　　　　　　　　　　　　　　　　　　　　　　　　　　　　"; SetColor(13, 15); cout << "■" << endl;
		cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
		cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
		cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;
	}
	break;

	case 9:
	{
		cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;	// 19
		cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;	// 20
		cout << "□"; SetColor(14, 15); cout << "　　　　　　　　　　　　　　　　　　　　■　　　　　　　　　　　　　　"; SetColor(9, 15); cout << "□" << endl;	// 21
		cout << "□"; SetColor(14, 15); cout << "　　　　　　　　　　　　　　　　　　　■■■　　　　　　　　　　　　　"; SetColor(9, 15); cout << "□" << endl;	// 22
		cout << "□"; SetColor(14, 15); cout << "　　　　　　　　　　　　　　　　　　　　■　　　　　　　　　　　　　　"; SetColor(9, 15); cout << "□" << endl;	// 23
		cout << "■"; SetColor(14, 15); cout << "　　　　　　　　　　　　　　　　　　　■　■　　　　　　　　　　　　　"; SetColor(9, 15); cout << "■" << endl;	// 24
		cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;	// 25
		cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;	// 26


		SetColor(13, 15);
		cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;
		cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
		cout << "■"; SetColor(0, 15); cout << "　　[이 아] 　　　　　　　　　　　　　　　　　　　　　　　　　　　　　"; SetColor(13, 15); cout << "■" << endl;
		cout << "■"; SetColor(0, 15); cout << "　　선택한 직업이 권법가가 맞으십니까?　　　　　　　　　　　　　　　　"; SetColor(13, 15); cout << "■" << endl;
		cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
		cout << "■"; SetColor(0, 15); cout << "　　▶　네　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　"; SetColor(13, 15); cout << "■" << endl;
		cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
		cout << "■"; SetColor(0, 15); cout << "　　　　아니오　　　　　　　　　　　　　　　　　　　　　　　　　　　　"; SetColor(13, 15); cout << "■" << endl;
		cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
		cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
		cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;
	}
	break;

	case 10:
	{
		cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;	// 19
		cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;	// 20
		cout << "□"; SetColor(14, 15); cout << "　　　　　　　　　　　　　　　　　　　　■　　　　　　　　　　　　　　"; SetColor(9, 15); cout << "□" << endl;	// 21
		cout << "□"; SetColor(14, 15); cout << "　　　　　　　　　　　　　　　　　　　■■■　　　　　　　　　　　　　"; SetColor(9, 15); cout << "□" << endl;	// 22
		cout << "□"; SetColor(14, 15); cout << "　　　　　　　　　　　　　　　　　　　　■　　　　　　　　　　　　　　"; SetColor(9, 15); cout << "□" << endl;	// 23
		cout << "■"; SetColor(14, 15); cout << "　　　　　　　　　　　　　　　　　　　■　■　　　　　　　　　　　　　"; SetColor(9, 15); cout << "■" << endl;	// 24
		cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;	// 25
		cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;	// 26


		SetColor(13, 15);
		cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;
		cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
		cout << "■"; SetColor(0, 15); cout << "　　[이 아] 　　　　　　　　　　　　　　　　　　　　　　　　　　　　　"; SetColor(13, 15); cout << "■" << endl;
		cout << "■"; SetColor(0, 15); cout << "　　선택한 직업이 권법가가 맞으십니까?　　　　　　　　　　　　　　　　"; SetColor(13, 15); cout << "■" << endl;
		cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
		cout << "■"; SetColor(0, 15); cout << "　　　　네　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　"; SetColor(13, 15); cout << "■" << endl;
		cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
		cout << "■"; SetColor(0, 15); cout << "　　▶　아니오　　　　　　　　　　　　　　　　　　　　　　　　　　　　"; SetColor(13, 15); cout << "■" << endl;
		cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
		cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
		cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;
	}
	break;

	case 11:
	{
		cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;	// 19
		cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;	// 20
		cout << "□"; SetColor(14, 15); cout << "　　　　　　　　　　　　　　　　　　　　■　　　　　　　　　　　　　　"; SetColor(9, 15); cout << "□" << endl;	// 21
		cout << "□"; SetColor(14, 15); cout << "　　　　　　　　　　　　　　　　　　　■■■　　　　　　　　　　　　　"; SetColor(9, 15); cout << "□" << endl;	// 22
		cout << "□"; SetColor(14, 15); cout << "　　　　　　　　　　　　　　　　　　　　■　　　　　　　　　　　　　　"; SetColor(9, 15); cout << "□" << endl;	// 23
		cout << "■"; SetColor(14, 15); cout << "　　　　　　　　　　　　　　　　　　　■　■　　　　　　　　　　　　　"; SetColor(9, 15); cout << "■" << endl;	// 24
		cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;	// 25
		cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;	// 26


		SetColor(13, 15);
		cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;
		cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
		cout << "■"; SetColor(0, 15); cout << "　　[이 아] 　　　　　　　　　　　　　　　　　　　　　　　　　　　　　"; SetColor(13, 15); cout << "■" << endl;
		cout << "■"; SetColor(0, 15); cout << "　　두가지 직업 중 하나를 선택하면 거기에 알맞는 힘을 드리겠습니다. 　"; SetColor(13, 15); cout << "■" << endl;
		cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
		cout << "■"; SetColor(0, 15); cout << "　　　　권법가　　　　　　　　　　　　　　　　　　　　　　　　　　　　"; SetColor(13, 15); cout << "■" << endl;
		cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
		cout << "■"; SetColor(0, 15); cout << "　　▶　검　사　　　　　　　　　　　　　　　　　　　　　　　　　　　　"; SetColor(13, 15); cout << "■" << endl;
		cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
		cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
		cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;
	}
	break;

	case 12:
	{
		cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;	// 19
		cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;	// 20
		cout << "□"; SetColor(14, 15); cout << "　　　　　　　　　　　　　　　　　　　　■　　　　　　　　　　　　　　"; SetColor(9, 15); cout << "□" << endl;	// 21
		cout << "□"; SetColor(14, 15); cout << "　　　　　　　　　　　　　　　　　　　■■■　　　　　　　　　　　　　"; SetColor(9, 15); cout << "□" << endl;	// 22
		cout << "□"; SetColor(14, 15); cout << "　　　　　　　　　　　　　　　　　　　　■　　　　　　　　　　　　　　"; SetColor(9, 15); cout << "□" << endl;	// 23
		cout << "■"; SetColor(14, 15); cout << "　　　　　　　　　　　　　　　　　　　■　■　　　　　　　　　　　　　"; SetColor(9, 15); cout << "■" << endl;	// 24
		cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;	// 25
		cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;	// 26


		SetColor(13, 15);
		cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;
		cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
		cout << "■"; SetColor(0, 15); cout << "　　[이 아] 　　　　　　　　　　　　　　　　　　　　　　　　　　　　　"; SetColor(13, 15); cout << "■" << endl;
		cout << "■"; SetColor(0, 15); cout << "　　선택한 직업이 검사가 맞으십니까?　　　　　　　　　　　　　　　　　"; SetColor(13, 15); cout << "■" << endl;
		cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
		cout << "■"; SetColor(0, 15); cout << "　　▶　네　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　"; SetColor(13, 15); cout << "■" << endl;
		cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
		cout << "■"; SetColor(0, 15); cout << "　　　　아니오　　　　　　　　　　　　　　　　　　　　　　　　　　　　"; SetColor(13, 15); cout << "■" << endl;
		cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
		cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
		cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;
	}
	break;

	case 13:
	{
		cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;	// 19
		cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;	// 20
		cout << "□"; SetColor(14, 15); cout << "　　　　　　　　　　　　　　　　　　　　■　　　　　　　　　　　　　　"; SetColor(9, 15); cout << "□" << endl;	// 21
		cout << "□"; SetColor(14, 15); cout << "　　　　　　　　　　　　　　　　　　　■■■　　　　　　　　　　　　　"; SetColor(9, 15); cout << "□" << endl;	// 22
		cout << "□"; SetColor(14, 15); cout << "　　　　　　　　　　　　　　　　　　　　■　　　　　　　　　　　　　　"; SetColor(9, 15); cout << "□" << endl;	// 23
		cout << "■"; SetColor(14, 15); cout << "　　　　　　　　　　　　　　　　　　　■　■　　　　　　　　　　　　　"; SetColor(9, 15); cout << "■" << endl;	// 24
		cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;	// 25
		cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;	// 26


		SetColor(13, 15);
		cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;
		cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
		cout << "■"; SetColor(0, 15); cout << "　　[이 아] 　　　　　　　　　　　　　　　　　　　　　　　　　　　　　"; SetColor(13, 15); cout << "■" << endl;
		cout << "■"; SetColor(0, 15); cout << "　　선택한 직업이 검사가 맞으십니까?　　　　　　　　　　　　　　　　　"; SetColor(13, 15); cout << "■" << endl;
		cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
		cout << "■"; SetColor(0, 15); cout << "　　　　네　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　"; SetColor(13, 15); cout << "■" << endl;
		cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
		cout << "■"; SetColor(0, 15); cout << "　　▶　아니오　　　　　　　　　　　　　　　　　　　　　　　　　　　　"; SetColor(13, 15); cout << "■" << endl;
		cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
		cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
		cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;
	}
	break;

	case 14:
	{
		cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;	// 19
		cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;	// 20
		cout << "□"; SetColor(14, 15); cout << "　　　　　　　　　　　　　　　　　　　　■　　　　　　　　　　　　　　"; SetColor(9, 15); cout << "□" << endl;	// 21
		cout << "□"; SetColor(14, 15); cout << "　　　　　　　　　　　　　　　　　　　■■■　　　　　　　　　　　　　"; SetColor(9, 15); cout << "□" << endl;	// 22
		cout << "□"; SetColor(14, 15); cout << "　　　　　　　　　　　　　　　　　　　　■　　　　　　　　　　　　　　"; SetColor(9, 15); cout << "□" << endl;	// 23
		cout << "■"; SetColor(14, 15); cout << "　　　　　　　　　　　　　　　　　　　■　■　　　　　　　　　　　　　"; SetColor(9, 15); cout << "■" << endl;	// 24
		cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;	// 25
		cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;	// 26


		SetColor(13, 15);
		cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;
		cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
		cout << "■"; SetColor(0, 15); cout << "　　[이 아] 　　　　　　　　　　　　　　　　　　　　　　　　　　　　　"; SetColor(13, 15); cout << "■" << endl;
		cout << "■"; SetColor(0, 15); cout << "　　직업은 언제든 다시 바꿀 수 있으니 저를 찾아오시기 바랍니다. 　　　"; SetColor(13, 15); cout << "■" << endl;
		cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
		cout << "■"; SetColor(0, 15); cout << "　　다른 신들도 그대를 도울 것입니다.　　　　　　　　　　　　　　　　 "; SetColor(13, 15); cout << "■" << endl;
		cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
		cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
		cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
		cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
		cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;
	}
	break;

	case 15:
	{
		cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;	// 19
		cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;	// 20
		cout << "□　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　□" << endl;	// 21
		cout << "□　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　□" << endl;	// 22
		cout << "□　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　□" << endl;	// 23
		cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;	// 24
		cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;	// 25
		cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;	// 26
		cout << "□　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　□" << endl;	// 27
		cout << "□　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　□" << endl;	// 28
		cout << "□"; SetColor(0, 15); cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　■■■■■■■　"; SetColor(9, 15); cout << "□" << endl;	// 29
		cout << "■"; SetColor(0, 15); cout << "　　　　　"; SetColor(14, 15); cout << "　■　"; SetColor(0, 15); cout << "　　　　　　　　　　　　　　　　　　　■　　　　　■　"; SetColor(9, 15); cout << "■" << endl;	// 30
		cout << "■"; SetColor(0, 15); cout << "　□□□　"; SetColor(14, 15); cout << "■■■"; SetColor(0, 15); cout << "　　　　　　　　　　　　　　　　　　　■　인간계　■　"; SetColor(9, 15); cout << "■" << endl;	// 31
		cout << "■"; SetColor(0, 15); cout << "　□□□　"; SetColor(14, 15); cout << "　■　"; SetColor(0, 15); cout << "　　　　　　　　　　　　　　　　　　　■　　　　　■　"; SetColor(9, 15); cout << "■" << endl;	// 32
		cout << "□"; SetColor(0, 15); cout << "　□□□　"; SetColor(14, 15); cout << "■　■"; SetColor(0, 15); cout << "　　　　　　　　　　　　　　　　　　　■　(마을)　■　"; SetColor(9, 15); cout << "□" << endl;	// 33
		cout << "□"; SetColor(0, 15); cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　■　　　　　■　"; SetColor(9, 15); cout << "□" << endl;	// 34
		cout << "□"; SetColor(0, 15); cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　■■■■■■■　"; SetColor(9, 15); cout << "□" << endl;	// 35
		cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;	// 36
		cout << "■■□□□■■■□□□■■■□□□■■■□□□■■■□□□■■■□□□■■" << endl;	// 37
	}
	break;

	case 16:
	{
		cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;	// 19
		cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;	// 20
		cout << "□"; SetColor(14, 15); cout << "　　　　　　　　　　　　　　　　　　　　■　　　　　　　　　　　　　　"; SetColor(9, 15); cout << "□" << endl;	// 21
		cout << "□"; SetColor(14, 15); cout << "　　　　　　　　　　　　　　　　　　　■■■　　　　　　　　　　　　　"; SetColor(9, 15); cout << "□" << endl;	// 22
		cout << "□"; SetColor(14, 15); cout << "　　　　　　　　　　　　　　　　　　　　■　　　　　　　　　　　　　　"; SetColor(9, 15); cout << "□" << endl;	// 23
		cout << "■"; SetColor(14, 15); cout << "　　　　　　　　　　　　　　　　　　　■　■　　　　　　　　　　　　　"; SetColor(9, 15); cout << "■" << endl;	// 24
		cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;	// 25
		cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;	// 26


		SetColor(13, 15);
		cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;
		cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
		cout << "■"; SetColor(0, 15); cout << "　　[이 아] 　　　　　　　　　　　　　　　　　　　　　　　　　　　　　"; SetColor(13, 15); cout << "■" << endl;
		cout << "■"; SetColor(0, 15); cout << "　　기를 주로 다루는 권법가는 체력기반 스킬이 약한대신 기력을 이용하는"; SetColor(13, 15); cout << "■" << endl;
		cout << "■"; SetColor(0, 15); cout << "　　스킬에 있어서는 단언 독보적입니다.　　　　　　　　　　　　　　　　"; SetColor(13, 15); cout << "■" << endl;
		cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
		cout << "■"; SetColor(0, 15); cout << "　　하지만 기력이 무한정한것이 아니기에 최대 기력이 낮다면 체력기반 　"; SetColor(13, 15); cout << "■" << endl;
		cout << "■"; SetColor(0, 15); cout << "　　스킬을 써야될 경우도 많으니 주의하세요. 　　　　　　　　　　　　　"; SetColor(13, 15); cout << "■" << endl;
		cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
		cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
		cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;
	}
	break;

	case 17:
	{
		cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;	// 19
		cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;	// 20
		cout << "□"; SetColor(14, 15); cout << "　　　　　　　　　　　　　　　　　　　　■　　　　　　　　　　　　　　"; SetColor(9, 15); cout << "□" << endl;	// 21
		cout << "□"; SetColor(14, 15); cout << "　　　　　　　　　　　　　　　　　　　■■■　　　　　　　　　　　　　"; SetColor(9, 15); cout << "□" << endl;	// 22
		cout << "□"; SetColor(14, 15); cout << "　　　　　　　　　　　　　　　　　　　　■　　　　　　　　　　　　　　"; SetColor(9, 15); cout << "□" << endl;	// 23
		cout << "■"; SetColor(14, 15); cout << "　　　　　　　　　　　　　　　　　　　■　■　　　　　　　　　　　　　"; SetColor(9, 15); cout << "■" << endl;	// 24
		cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;	// 25
		cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;	// 26


		SetColor(13, 15);
		cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;
		cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
		cout << "■"; SetColor(0, 15); cout << "　　[이 아] 　　　　　　　　　　　　　　　　　　　　　　　　　　　　　"; SetColor(13, 15); cout << "■" << endl;
		cout << "■"; SetColor(0, 15); cout << "　　무를 추구하는 검사는 오로지 신체를 단련하여 체력기반 스킬을　　　 "; SetColor(13, 15); cout << "■" << endl;
		cout << "■"; SetColor(0, 15); cout << "　　극도로 강하게 만든 자들을 말합니다.　　　　　　　　　　　　　　　 "; SetColor(13, 15); cout << "■" << endl;
		cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
		cout << "■"; SetColor(0, 15); cout << "　　기력을 사용하는 스킬은 기를 다루는 권법가에 비해 한계가 존재하지만"; SetColor(13, 15); cout << "■" << endl;
		cout << "■"; SetColor(0, 15); cout << "　　소모하는 것 없이 강한 체력기반 스킬을 사용한다는 점에서 　　　　　"; SetColor(13, 15); cout << "■" << endl;
		cout << "■"; SetColor(0, 15); cout << "　　검사들은 전장에서 빛을 발할겁니다.　　　　　　　　　　　　　　　　"; SetColor(13, 15); cout << "■" << endl;
		cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
		cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;
	}
	break;

	}
}
void mainGame::IahChoice()
{
	_key = '0';
	_key = _getch();

	if (_key == (char)RIGHT)
	{
		if (_iahcheck == 2)
		{
			_iahcheck = 3;
			IahChoice();
		}
		else if (_iahcheck == 15)
		{
			_iahcheck = 3;
			IahChoice();
		}
		else
		{
			IahChoice();
		}
	}
	else if (_key == (char)LEFT)
	{
		if (_iahcheck == 3 && _tempPlace == 1)
		{
			_iahcheck = 2;
			IahChoice();
		}
		else if (_iahcheck == 3 && _tempPlace == 2)
		{
			_iahcheck = 15;
			IahChoice();
		}
		else
		{
			IahChoice();
		}
	}
	else if (_key == (char)UP)
	{
		if (_iahcheck == 2)
		{
			_iahcheck = 3;
			IahChoice();
		}
		else if (_iahcheck == 11)
		{
			_iahcheck = 8;
			IahChoice();
		}
		else if (_iahcheck == 10)
		{
			_iahcheck = 9;
			IahChoice();
		}
		else if (_iahcheck == 13)
		{
			_iahcheck = 12;
			IahChoice();
		}
		else if (_iahcheck == 15)
		{
			_iahcheck = 3;
			IahChoice();
		}
		else
		{
			IahChoice();
		}
	}
	else if (_key == (char)DOWN)
	{
		if (_iahcheck == 3 && _tempPlace == 1)
		{
			_iahcheck = 2;
			IahChoice();
		}
		else if (_iahcheck == 3 && _tempPlace == 2)
		{
			_iahcheck = 15;
			IahChoice();
		}
		else if (_iahcheck == 8)
		{
			_iahcheck = 11;
			IahChoice();
		}
		else if (_iahcheck == 9)
		{
			_iahcheck = 10;
			IahChoice();
		}
		else if (_iahcheck == 12)
		{
			_iahcheck = 13;
			IahChoice();
		}
		else
		{
			IahChoice();
		}
	}
	else if (_key == (char)ENTER || _key == (char)SPACE)
	{
		switch (_iahcheck)
		{
		case 2: // iah to home
		{
			_key = '0';
			_iahcheck = 1;
			_effect = EtempleEnter; // effectsound on
			Sleep(1000);
			b_iahMusic = false; // mainmusic  off
			b_iahScreen = false; // screen off
			Sleep(1000);
			Move();
			_tempPlace = 0;
			_iahcheck = 0;

			HomeEmptyScreen();
			b_homeMusic = true;
			_effect = EtempleEnter;
			Sleep(1500);
			if (_characterJob == "평민")
			{
				HomeEvent();
				IahEvent();
			}
			else
			{
				Home();
			}
		}
		break;
		case 3:
		{
			_effect = Econversation;
			IahJobCheck();
			IahChoice();
		}
		break;
		case 4:
		{
			_effect = Econversation;
			_iahcheck = 5;
			IahChoice();
		}
		break;
		case 5:
		{
			_effect = Econversation;
			_iahcheck = 6;
			IahChoice();
		}
		break;
		case 6:
		{
			_effect = Econversation;
			_iahcheck = 7;
			IahChoice();
		}
		break;
		case 7:
		{
			_effect = Econversation;
			_iahcheck = 16;
			IahChoice();
		}
		break;
		case 8:
		{
			_effect = Econversation;
			_iahcheck = 9;
			IahChoice();
		}
		break;
		case 9:
		{
			_effect = Econversation;
			_characterJob = "권법가";
			_character1stSkill = "비상각";
			_character2ndSkill = "폭전축";
			_1stSkillDmg = _characterMaxHp * 0.05;
			_2ndSkillDmg = _characterMaxMp * 0.75;
			_2ndSkillNeedMp = _characterMaxMp * 0.35;

			_iahcheck = 14;
			IahChoice();
		}
		break;
		case 10:
		{
			_effect = Econversation;
			_iahcheck = 14;
			IahChoice();
		}
		break;
		case 11:
		{
			_effect = Econversation;
			_iahcheck = 12;
			IahChoice();
		}
		break;
		case 12:
		{
			_effect = Econversation;
			_characterJob = "검사";
			_character1stSkill = "대타격";
			_character2ndSkill = "쾌진격";
			_1stSkillDmg = _characterMaxHp * 0.08;
			_2ndSkillDmg = _characterMaxMp * 0.4;
			_2ndSkillNeedMp = _characterMaxMp * 0.5;

			_iahcheck = 14;
			IahChoice();
		}
		break;
		case 13:
		{
			_effect = Econversation;
			_iahcheck = 14;
			IahChoice();
		}
		break;
		case 14:
		{
			_iahcheck = 3;
			IahChoice();
		}
		break;
		case 15: // iah to village
		{
			_iahcheck = 1;
			_effect = EtempleEnter; // effectsound on
			Sleep(1000);
			b_iahMusic = false; // mainmusic  off
			b_iahScreen = false; // screen off
			Sleep(1000);
			Move();
			_tempPlace = 0;
			_iahcheck = 0;

			_village2check = 9;
			b_villageMusic = true;
			_effect = EtempleEnter;
			Village2Screen();
			Sleep(1000);

			_village2check = 5;
			Village2Screen();
			Village2Choice();
		}
		break;
		case 16:
		{
			_effect = Econversation;
			_iahcheck = 17;
			IahChoice();
		}
		break;
		case 17:
		{
			_effect = Econversation;
			_iahcheck = 8;
			IahChoice();
		}
		break;
		}
	}
	else if (_key == (char)ESC)
	{
		if (_iahcheck < 4)
		{
			b_iahScreen = false;
			Sleep(1000);
			_statuscheck = 1;
			Status();
		}
		else
		{
			IahChoice();
		}
	}
	else
	{
		IahChoice();
	}
}


void mainGame::Status()
{
	gotoxy(0, 0);
	SetColor(8, 8);
	BootScreen2();

	_effect = Estatuson;
	StatusScreen();
	StatusChoice();
}
void mainGame::StatusScreen()
{
	if (_statuscheck == 1)
	{
		StatusScreen1();
	}
	else if (_statuscheck == 2)
	{
		StatusScreen2();
	}
	else if (_statuscheck == 3)
	{
		StatusScreen3();
	}
	else if (_statuscheck == 4)
	{
		StatusScreen4();
	}
}
void mainGame::StatusChoice()
{
	_key = '0';
	_key = _getch();

	if (_key == (char)ENTER || _key == (char)SPACE)
	{
		if (_statuscheck == 1)
		{
			if (hb->GetHowMany() > 0)
			{
				_statuscheck = 3;
				_drugtype = 1;
				StatusScreen();
				StatusChoice();
			}
			else
			{
				StatusChoice();
			}
		}
		else if (_statuscheck == 2)
		{
			if (po->GetHowMany() > 0)
			{
				_statuscheck = 3;
				_drugtype = 2;
				StatusScreen();
				StatusChoice();
			}
			else
			{
				StatusChoice();
			}
		}
		else if (_statuscheck == 3)
		{
			if (_drugtype == 1)
			{
				_characterHp = _characterHp + hb->GetHpUp();
				_effect = Eheal;
				if (_characterHp > _characterMaxHp)
				{
					_characterHp = _characterMaxHp;
				}
				hb->SetHowMany(hb->GetHowMany() - 1);
				_statuscheck = 1;
			}
			else if (_drugtype == 2)
			{
				_characterHp = _characterHp + po->GetHpUp();
				_effect = Eheal;
				if (_characterHp > _characterMaxHp)
				{
					_characterHp = _characterMaxHp;
				}
				po->SetHowMany(po->GetHowMany() - 1);
				_statuscheck = 2;
			}
			_drugtype = 0;
			StatusScreen();
			StatusChoice();
		}
		else if (_statuscheck == 4)
		{
			if (_drugtype == 1)
			{
				_statuscheck = 1;
			}
			else if (_drugtype == 2)
			{
				_statuscheck = 2;
			}
			_drugtype = 0;
			StatusScreen();
			StatusChoice();
		}
	}
	else if (_key == (char)UP)
	{
		if (_statuscheck == 2)
		{
			_statuscheck = 1;
			StatusScreen();
			StatusChoice();
		}
		else if (_statuscheck == 4)
		{
			_statuscheck = 3;
			StatusScreen();
			StatusChoice();
		}
		else
		{
			StatusChoice();
		}
	}
	else if (_key == (char)DOWN)
	{
		if (_statuscheck == 1)
		{
			_statuscheck = 2;
			StatusScreen();
			StatusChoice();
		}
		else if (_statuscheck == 3)
		{
			_statuscheck = 4;
			StatusScreen();
			StatusChoice();
		}
		else
		{
			StatusChoice();
		}
	}
	else if (_key == (char)ESC)
	{
		_effect = Estatusoff;

		_statuscheck = 0;
		_drugtype = 0;

		if (_homecheck > 0)
		{
			switch (_homecheck)
			{
			case 1:
			{
				HomeFieldScreen();
				if (_characterJob == "평민")
				{
					HomeEventChoice();
				}
				else
				{
					HomeChoice();
				}
			}
			break;
			case 2:
			{
				HomeSleepScreen();
				if (_characterJob == "평민")
				{
					HomeEventChoice();
				}
				else
				{
					HomeChoice();
				}
			}
			break;
			case 3:
			{
				HomeTempleScreen();
				if (_characterJob == "평민")
				{
					HomeEventChoice();
				}
				else
				{
					HomeChoice();
				}
			}
			break;
			}
		}
		else if (_iahcheck > 0)
		{
			b_iahScreen = true;
			IahChoice();
		}
		else if (_seocheck > 0)
		{
			b_seoScreen = true;
			SeoChoice();
		}
		else if (_khancheck > 0)
		{
			b_khanScreen = true;
			KhanChoice();
		}
		else if (_templecheck > 0)
		{
			TempleScreen();
			TempleChoice();
		}
		else if (_fieldcheck > 0)
		{
			FieldScreen();
			FieldChoice();
		}
		else if (_farmcheck > 0)
		{
			FarmScreen();
			FarmChoice();
		}
		else if (_village1check > 0)
		{
			Village1Screen();
			Village1Choice();
		}
		else if (_village2check > 0)
		{
			Village2Screen();
			Village2Choice();
		}
	}
	else
	{
		StatusChoice();
	}
}

void mainGame::StatusScreen1()
{
	gotoxy(0, 0);
	SetColor(0, 8);

	cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　" << endl;	// 1
	cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　" << endl;	// 2
	cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　" << endl;	// 3
	cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　" << endl;	// 4
	cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　" << endl;	// 5
	cout << "　　　　아타호　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　" << endl;	// 6
	cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　" << endl;	// 7
	cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　" << endl;	// 8
	cout << "　　　　직업 : " << _characterJob << endl;	// 9
	cout << "　　　　　　　　　　　　　　　　　　　　▶　약　초　: " << hb->GetHowMany() << " 개　　" << endl;	// 10
	cout << "　　　　체력 : " << _characterHp << " / " << _characterMaxHp << endl;	// 11
	cout << "　　　　　　　　　　　　　　　　　　　　　　Hp포션　: " << po->GetHowMany() << " 개　　" << endl;	// 12
	cout << "　　　　기력 : " << _characterMp << " / " << _characterMaxMp << endl;	// 13
	cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　" << endl;	// 14
	cout << "　　　경험치 : " << _characterExp << " / " << _characterMaxExp << endl;	// 15
	cout << "　　　　　　　　　　　　　　　　　　　　　　약초씨　: " << _characterSeed << " 개　　　" << endl;	// 16
	cout << "　　　　금전 : " << _characterMoney << " 원　　　" << endl;	// 17
	cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　" << endl;	// 18
	cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　" << endl;	// 19
	cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　" << endl;	// 20
	cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　" << endl;	// 21
	cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■　　■　　　" << endl;	// 22
	cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■■■■■■　　" << endl;	// 23
	cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■■■■■■　　" << endl;	// 24
	cout << "　　　　　　　　　　　　　　　　　　　　　　■　　　■　　　■■■■　　　" << endl;	// 25
	cout << "　　　　　　　　　　　　　　　　　　　　　■　■　■　■　　　■■　　　　" << endl;	// 26
	cout << "　　　　　　　　　　　　　　　　　　　　　■　■　■　■　　　　　　　　　" << endl;	// 27
	cout << "　　　　　　　　　　　　　　　　　　　　　■■■■■■■　　　　　　　　　" << endl;	// 28
	cout << "　　　　　　　　　　　　　　　　　　　　■　　　　　　　■　　　　　　　　" << endl;	// 29
	cout << "　　　　　　　　　　　　　　　　　　　　■　■　　　■　■　　　　　　　　" << endl;	// 30
	cout << "　　　　　　　　　　　　　　　　　　　　■■　■　■　■■　　　　　　　　" << endl;	// 31
	cout << "　　　　　　　　　　　　　　　　　　　　■　　　　　　　■　　　　　　　　" << endl;	// 32
	cout << "　　　　　　　　　　　　　　　　　　　　■　　　　　　　■　　　　　　　　" << endl;	// 33
	cout << "　　　　　　　　　　　　　　　　　　　　■　　　　　　　■　　　　　　　　" << endl;	// 34
	cout << "　　　　　　　　　　　　　　　　　　　　■■■■■■■■■　　　　　　　　" << endl;	// 35
	cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　" << endl;	// 36
	cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　" << endl;	// 37
}

void mainGame::StatusScreen2()
{
	gotoxy(0, 0);
	SetColor(0, 8);

	cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　" << endl;	// 1
	cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　" << endl;	// 2
	cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　" << endl;	// 3
	cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　" << endl;	// 4
	cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　" << endl;	// 5
	cout << "　　　　아타호　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　" << endl;	// 6
	cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　" << endl;	// 7
	cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　" << endl;	// 8
	cout << "　　　　직업 : " << _characterJob << endl;	// 9
	cout << "　　　　　　　　　　　　　　　　　　　　　　약　초　: " << hb->GetHowMany() << " 개　　　" << endl;	// 10
	cout << "　　　　체력 : " << _characterHp << " / " << _characterMaxHp << endl;	// 11
	cout << "　　　　　　　　　　　　　　　　　　　　▶　Hp포션　: " << po->GetHowMany() << " 개　　　" << endl;	// 12
	cout << "　　　　기력 : " << _characterMp << " / " << _characterMaxMp << endl;	// 13
	cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　" << endl;	// 14
	cout << "　　　경험치 : " << _characterExp << " / " << _characterMaxExp << endl;	// 15
	cout << "　　　　　　　　　　　　　　　　　　　　　　약초씨　: " << _characterSeed << " 개　　　" << endl;	// 16
	cout << "　　　　금전 : " << _characterMoney << " 원　　　" << endl;	// 17
	cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　" << endl;	// 18
	cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　" << endl;	// 19
	cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　" << endl;	// 20
	cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　" << endl;	// 21
	cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■　　■　　　" << endl;	// 22
	cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■■■■■■　　" << endl;	// 23
	cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■■■■■■　　" << endl;	// 24
	cout << "　　　　　　　　　　　　　　　　　　　　　　■　　　■　　　■■■■　　　" << endl;	// 25
	cout << "　　　　　　　　　　　　　　　　　　　　　■　■　■　■　　　■■　　　　" << endl;	// 26
	cout << "　　　　　　　　　　　　　　　　　　　　　■　■　■　■　　　　　　　　　" << endl;	// 27
	cout << "　　　　　　　　　　　　　　　　　　　　　■■■■■■■　　　　　　　　　" << endl;	// 28
	cout << "　　　　　　　　　　　　　　　　　　　　■　　　　　　　■　　　　　　　　" << endl;	// 29
	cout << "　　　　　　　　　　　　　　　　　　　　■　■　　　■　■　　　　　　　　" << endl;	// 30
	cout << "　　　　　　　　　　　　　　　　　　　　■■　■　■　■■　　　　　　　　" << endl;	// 31
	cout << "　　　　　　　　　　　　　　　　　　　　■　　　　　　　■　　　　　　　　" << endl;	// 32
	cout << "　　　　　　　　　　　　　　　　　　　　■　　　　　　　■　　　　　　　　" << endl;	// 33
	cout << "　　　　　　　　　　　　　　　　　　　　■　　　　　　　■　　　　　　　　" << endl;	// 34
	cout << "　　　　　　　　　　　　　　　　　　　　■■■■■■■■■　　　　　　　　" << endl;	// 35
	cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　" << endl;	// 36
	cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　" << endl;	// 37
}

void mainGame::StatusScreen3()
{
	gotoxy(0, 0);
	SetColor(0, 8);

	cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　" << endl;	// 1
	cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　" << endl;	// 2
	cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　" << endl;	// 3
	cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　" << endl;	// 4
	cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　" << endl;	// 5
	cout << "　　　　아타호　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　" << endl;	// 6
	cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　" << endl;	// 7
	cout << "　　　　　　　　　　　　　　　　　　　　사용하시겠습니까?　　　　　　　　 " << endl;	// 8
	cout << "　　　　직업 : " << _characterJob << endl;	// 9
	cout << "　　　　　　　　　　　　　　　　　　　　▶　네　　　　　　　　　　　　　　" << endl;	// 10
	cout << "　　　　체력 : " << _characterHp << " / " << _characterMaxHp << endl;	// 11
	cout << "　　　　　　　　　　　　　　　　　　　　　　아니오　　　　　　　　　　　　" << endl;	// 12
	cout << "　　　　기력 : " << _characterMp << " / " << _characterMaxMp << endl;	// 13
	cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　" << endl;	// 14
	cout << "　　　경험치 : " << _characterExp << " / " << _characterMaxExp << endl;	// 15
	cout << "　　　　　　　　　　　　　　　　　　　　　　약초씨　: " << _characterSeed << " 개" << endl;	// 16
	cout << "　　　　금전 : " << _characterMoney << " 원" << endl;	// 17
	cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　" << endl;	// 18
	cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　" << endl;	// 19
	cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　" << endl;	// 20
	cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　" << endl;	// 21
	cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■　　■　　　" << endl;	// 22
	cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■■■■■■　　" << endl;	// 23
	cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■■■■■■　　" << endl;	// 24
	cout << "　　　　　　　　　　　　　　　　　　　　　　■　　　■　　　■■■■　　　" << endl;	// 25
	cout << "　　　　　　　　　　　　　　　　　　　　　■　■　■　■　　　■■　　　　" << endl;	// 26
	cout << "　　　　　　　　　　　　　　　　　　　　　■　■　■　■　　　　　　　　　" << endl;	// 27
	cout << "　　　　　　　　　　　　　　　　　　　　　■■■■■■■　　　　　　　　　" << endl;	// 28
	cout << "　　　　　　　　　　　　　　　　　　　　■　　　　　　　■　　　　　　　　" << endl;	// 29
	cout << "　　　　　　　　　　　　　　　　　　　　■　■　　　■　■　　　　　　　　" << endl;	// 30
	cout << "　　　　　　　　　　　　　　　　　　　　■■　■　■　■■　　　　　　　　" << endl;	// 31
	cout << "　　　　　　　　　　　　　　　　　　　　■　　　　　　　■　　　　　　　　" << endl;	// 32
	cout << "　　　　　　　　　　　　　　　　　　　　■　　　　　　　■　　　　　　　　" << endl;	// 33
	cout << "　　　　　　　　　　　　　　　　　　　　■　　　　　　　■　　　　　　　　" << endl;	// 34
	cout << "　　　　　　　　　　　　　　　　　　　　■■■■■■■■■　　　　　　　　" << endl;	// 35
	cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　" << endl;	// 36
	cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　" << endl;	// 37
}

void mainGame::StatusScreen4()
{
	gotoxy(0, 0);
	SetColor(0, 8);

	cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　" << endl;	// 1
	cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　" << endl;	// 2
	cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　" << endl;	// 3
	cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　" << endl;	// 4
	cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　" << endl;	// 5
	cout << "　　　　아타호　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　" << endl;	// 6
	cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　" << endl;	// 7
	cout << "　　　　　　　　　　　　　　　　　　　　사용하시겠습니까?　　　　　　　　 " << endl;	// 8
	cout << "　　　　직업 : " << _characterJob << endl;	// 9
	cout << "　　　　　　　　　　　　　　　　　　　　　　네　　　　　　　　　　　　　　" << endl;	// 10
	cout << "　　　　체력 : " << _characterHp << " / " << _characterMaxHp << endl;	// 11
	cout << "　　　　　　　　　　　　　　　　　　　　▶　아니오　　　　　　　　　　　　" << endl;	// 12
	cout << "　　　　기력 : " << _characterMp << " / " << _characterMaxMp << endl;	// 13
	cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　" << endl;	// 14
	cout << "　　　경험치 : " << _characterExp << " / " << _characterMaxExp << endl;	// 15
	cout << "　　　　　　　　　　　　　　　　　　　　　　약초씨　: " << _characterSeed << " 개" << endl;	// 16
	cout << "　　　　금전 : " << _characterMoney << " 원" << endl;	// 17
	cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　" << endl;	// 18
	cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　" << endl;	// 19
	cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　" << endl;	// 20
	cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　" << endl;	// 21
	cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■　　■　　　" << endl;	// 22
	cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■■■■■■　　" << endl;	// 23
	cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■■■■■■　　" << endl;	// 24
	cout << "　　　　　　　　　　　　　　　　　　　　　　■　　　■　　　■■■■　　　" << endl;	// 25
	cout << "　　　　　　　　　　　　　　　　　　　　　■　■　■　■　　　■■　　　　" << endl;	// 26
	cout << "　　　　　　　　　　　　　　　　　　　　　■　■　■　■　　　　　　　　　" << endl;	// 27
	cout << "　　　　　　　　　　　　　　　　　　　　　■■■■■■■　　　　　　　　　" << endl;	// 28
	cout << "　　　　　　　　　　　　　　　　　　　　■　　　　　　　■　　　　　　　　" << endl;	// 29
	cout << "　　　　　　　　　　　　　　　　　　　　■　■　　　■　■　　　　　　　　" << endl;	// 30
	cout << "　　　　　　　　　　　　　　　　　　　　■■　■　■　■■　　　　　　　　" << endl;	// 31
	cout << "　　　　　　　　　　　　　　　　　　　　■　　　　　　　■　　　　　　　　" << endl;	// 32
	cout << "　　　　　　　　　　　　　　　　　　　　■　　　　　　　■　　　　　　　　" << endl;	// 33
	cout << "　　　　　　　　　　　　　　　　　　　　■　　　　　　　■　　　　　　　　" << endl;	// 34
	cout << "　　　　　　　　　　　　　　　　　　　　■■■■■■■■■　　　　　　　　" << endl;	// 35
	cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　" << endl;	// 36
	cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　" << endl;	// 37
}

void mainGame::Move()
{
	SetColor(0, 0);
	BootScreen2();
	Sleep(1500);
}
void mainGame::Move2()
{
	SetColor(0, 0);
	BootScreen2();
	Sleep(500);
}
/////////////////////////////////////////////
void mainGame::Home()
{
	_homecheck = 3;
	HomeTempleScreen();
	HomeChoice();
}
void mainGame::HomeChoice()
{
	_key = '0';
	_key = _getch();

	if (_key == (char)LEFT)
	{
		switch (_homecheck)
		{
		case 1:
		case 3:
		{
			_homecheck = 2;
			HomeSleepScreen();
			HomeChoice();
		}
		break;
		default:
		{
			HomeChoice();
		}
		break;
		}
	}
	else if (_key == (char)RIGHT)
	{
		if (_homecheck == 2)
		{
			_homecheck = 3;
			HomeTempleScreen();
			HomeChoice();
		}
		else
		{
			HomeChoice();
		}
	}
	else if (_key == (char)UP)
	{
		if (_homecheck == 1 || _homecheck == 2)
		{
			_homecheck = 3;
			HomeTempleScreen();
			HomeChoice();
		}
		else
		{
			HomeChoice();
		}
	}
	else if (_key == (char)DOWN)
	{
		switch (_homecheck)
		{
		case 2:
		case 3:
		{
			_homecheck = 1;
			HomeFieldScreen();
			HomeChoice();
		}
		break;
		default:
		{
			HomeChoice();
		}
		break;
		}
	}
	else if (_key == (char)ESC)
	{
		_statuscheck = 1;
		Status();
	}
	else if (_key == (char)ENTER || _key == (char)SPACE)
	{
		if (_homecheck == 1)
		{
			_effect = Edooropen;
			HomeFieldScreen2();
			Sleep(800);
			HomeEmptyScreen2();
			Sleep(800);
			b_homeMusic = false;
			Move();
			_homecheck = 0;
			b_fieldMusic = true;
			_fieldcheck = 1;
			FieldScreen();
			FieldChoice();
		}
		else if (_homecheck == 2)
		{
			_effect = Econversation;
			_sleepcheck = 1;
			SleepChoiceScreen();
			HomeSleepChoice();
		}
		else if (_homecheck == 3)
		{
			_effect = Econversation;
			_upgradecheck = 1;
			UpgradeChoiceScreen();
			HomeUpgradeChoice();
		}
	}
	else
	{
		HomeChoice();
	}
}
/////////////////////////////////////////////
void mainGame::SleepChoiceScreen()
{
	gotoxy(0, 0);

	SetColor(9, 15);
	if (_homecheck == 2)
	{
		cout << "■■□□□■■■□□□■■■□□□■■■□□□■■■□□□■■■□□□■■" << endl;	// 1
		cout << "■"; SetColor(0, 15); cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■"; SetColor(9, 15); cout << "■" << endl;	// 2
		cout << "□"; SetColor(0, 15); cout << "■■■■■■■■■■■■■■　　　　　　　■■■■■■■■■■■■■■"; SetColor(9, 15); cout << "□" << endl;	// 3
		cout << "□"; SetColor(0, 15); cout << "■■■■■■■■■■■■■■　　　　　　　■■■■■■■■■■■■■■"; SetColor(9, 15); cout << "□" << endl;	// 4
		cout << "□"; SetColor(0, 15); cout << "■■■■■■■■■■■■■■　　□□□　　■■■■■■■■■■■■■■"; SetColor(9, 15); cout << "□" << endl;	// 5
		cout << "■"; SetColor(0, 15); cout << "■■■■■■■■■■■■■■　　□□□　　■■■■■■■■■■■■■■"; SetColor(9, 15); cout << "■" << endl;	// 6
		cout << "■"; SetColor(0, 15); cout << "■■■■■■■■■■■■■■　　□□□　　■■■■■■■■■■■■■■"; SetColor(9, 15); cout << "■" << endl;	// 7
		cout << "■"; SetColor(0, 15); cout << "■■■■■■■■■■■■■■　　　　　　　■■■■■■■■■■■■■■"; SetColor(9, 15); cout << "■" << endl;	// 8
		cout << "□"; SetColor(0, 15); cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■"; SetColor(9, 15); cout << "□" << endl;	// 9
		cout << "□"; SetColor(0, 15); cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■"; SetColor(9, 15); cout << "□" << endl;	// 10
		cout << "□"; SetColor(0, 15); cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■"; SetColor(9, 15); cout << "□" << endl;	// 11
		cout << "■"; SetColor(0, 15); cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■"; SetColor(9, 15); cout << "■" << endl;	// 12
		cout << "■"; SetColor(0, 15); cout << "■　　■■■■■■■■■■■　　　　　　　　　　　　　　　　　　　　■"; SetColor(9, 15); cout << "■" << endl;	// 13
		cout << "■"; SetColor(0, 15); cout << "■　　■　　　　　　　　　■　　　　　　　　　　　　　　　　　　　　■"; SetColor(9, 15); cout << "■" << endl;	// 14
		cout << "□"; SetColor(0, 15); cout << "■　　■■■"; SetColor(14, 15); cout << "■　■"; SetColor(0, 15); cout << "　　　　■　　　　　　　　　　　　　　　　　　　　■"; SetColor(9, 15); cout << "□" << endl;	// 15
		cout << "□"; SetColor(0, 15); cout << "■　　■■"; SetColor(14, 15); cout << "■■■"; SetColor(0, 15); cout << "　　　　　■　　　　　　　　　　　　　　　　　　　　■"; SetColor(9, 15); cout << "□" << endl;	// 16
		cout << "□"; SetColor(0, 15); cout << "■　　■■　"; SetColor(14, 15); cout << "■　■"; SetColor(0, 15); cout << "　　　　■　　　　　　　　　　　　　　　　　　　　■"; SetColor(9, 15); cout << "□" << endl;	// 17
		cout << "■"; SetColor(0, 15); cout << "■　　■■■■　　　　　　■　　　　　　　　　　　　　　　　　　　　■"; SetColor(9, 15); cout << "■" << endl;	// 18
		cout << "■"; SetColor(0, 15); cout << "■　　■　　　　　　　　　■　　　　　　　　　　　　　　　　　　　　■"; SetColor(9, 15); cout << "■" << endl;	// 19
		cout << "■"; SetColor(0, 15); cout << "■　　■■■■■■■■■■■　　　　　　　　　　　　　　　　　　　　■"; SetColor(9, 15); cout << "■" << endl;	// 20
		cout << "□"; SetColor(0, 15); cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■"; SetColor(9, 15); cout << "□" << endl;	// 21
		cout << "□"; SetColor(0, 15); cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■"; SetColor(9, 15); cout << "□" << endl;	// 22
		cout << "□"; SetColor(0, 15); cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■"; SetColor(9, 15); cout << "□" << endl;	// 23
		cout << "■"; SetColor(0, 15); cout << "■■■■■■■■■■■■■■■　　　■■■■■■■■■■■■■■■■■"; SetColor(9, 15); cout << "■" << endl;	// 24
		cout << "■"; SetColor(0, 15); cout << "■■■■■■■■■■■■■■■　　　■■■■■■■■■■■■■■■■■"; SetColor(9, 15); cout << "■" << endl;	// 25
		cout << "■"; SetColor(0, 15); cout << "■■■■■■■■■■■■■■■　　　■■■■■■■■■■■■■■■■■"; SetColor(9, 15); cout << "■" << endl;	// 26
	}
	//else if()

	if (_sleepcheck == 1)
	{
		SetColor(13, 15);

		cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;
		cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
		cout << "■　　"; SetColor(0, 15); cout << "잠이나 잘까?"; SetColor(13, 15); cout << "　  　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
		cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
		cout << "■　　"; SetColor(0, 15); cout << "▶　잔다　　"; SetColor(13, 15); cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
		cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
		cout << "■　　"; SetColor(0, 15); cout << "　　안잔다　　"; SetColor(13, 15); cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
		cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
		cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
		cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
		cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;
	}
	else if (_sleepcheck == 2)
	{
		SetColor(13, 15);

		cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;
		cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
		cout << "■　　"; SetColor(0, 15); cout << "잠이나 잘까?"; SetColor(13, 15); cout << "　  　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
		cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
		cout << "■　　"; SetColor(0, 15); cout << "　　잔다　　"; SetColor(13, 15); cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
		cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
		cout << "■　　"; SetColor(0, 15); cout << "▶　안잔다　　"; SetColor(13, 15); cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
		cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
		cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
		cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
		cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;
	}
}

void mainGame::HomeSleepChoice()
{
	_key = '0';
	_key = _getch();

	if (_key == (char)ENTER || _key == (char)SPACE)
	{
		if (_sleepcheck == 1)
		{
			b_homeMusic = false;
			SleepEvent();
		}
		_sleepcheck = 0;

		b_homeMusic = true;
		HomeSleepScreen();
		HomeChoice();
	}
	else if (_key == (char)UP)
	{
		if (_sleepcheck == 2)
		{
			_sleepcheck = 1;
			SleepChoiceScreen();
			HomeSleepChoice();
		}
		else
		{
			HomeSleepChoice();
		}
	}
	else if (_key == (char)DOWN)
	{
		if (_sleepcheck == 1)
		{
			_sleepcheck = 2;
			SleepChoiceScreen();
			HomeSleepChoice();
		}
		else
		{
			HomeSleepChoice();
		}

	}
	else
	{
		HomeSleepChoice();
	}
}

void mainGame::SleepEvent()
{
	gotoxy(0, 0);
	SetColor(9, 0);

	cout << "■■□□□■■■□□□■■■□□□■■■□□□■■■□□□■■■□□□■■" << endl;	// 1
	cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;	// 2
	cout << "□　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　□" << endl;	// 3
	cout << "□　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　□" << endl;	// 4
	cout << "□　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　□" << endl;	// 5
	cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;	// 6
	cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;	// 7
	cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;	// 8
	cout << "□　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　□" << endl;	// 9
	cout << "□　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　□" << endl;	// 10
	cout << "□　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　□" << endl;	// 11
	cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;	// 12
	cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;	// 13
	cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;	// 14
	cout << "□　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　□" << endl;	// 15
	cout << "□　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　□" << endl;	// 16
	cout << "□　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　□" << endl;	// 17
	cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;	// 18
	cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;	// 19
	cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;	// 20
	cout << "□　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　□" << endl;	// 21
	cout << "□　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　□" << endl;	// 22
	cout << "□　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　□" << endl;	// 23
	cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;	// 24
	cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;	// 25
	cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;	// 26
	cout << "□　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　□" << endl;	// 27
	cout << "□　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　□" << endl;	// 28
	cout << "□　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　□" << endl;	// 29
	cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;	// 30
	cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;	// 31
	cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;	// 32
	cout << "□　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　□" << endl;	// 33
	cout << "□　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　□" << endl;	// 34
	cout << "□　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　□" << endl;	// 35
	cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;	// 36
	cout << "■■□□□■■■□□□■■■□□□■■■□□□■■■□□□■■■□□□■■" << endl;	// 37

	_characterHp = _characterMaxHp;
	_characterMp = _characterMaxMp;

	_effect = Esleep;
	Sleep(6500);
}
/////////////////////////////////////////////
void mainGame::HomeUpgradeChoice()
{
	_key = '0';
	_key = _getch();

	if (_key == (char)ENTER || _key == (char)SPACE)
	{
		if (_upgradecheck == 1)
		{
			_upgradecheck = 4;
			_effect = Econversation;
			UpgradeChoiceScreen();
			HomeUpgradeChoice();
		}
		else if (_upgradecheck == 2)
		{
			_homecheck = 0;
			_upgradecheck = 0;
			_tempPlace = 1; // 1 = home

			_effect = EtempleEnter; // effectsound
			Move(); // black screen 1000ms
			b_homeMusic = false; // mainmusic off
			Sleep(500);
			IahEvent();
		}
		else if (_upgradecheck == 3 || _upgradecheck == 5 || _upgradecheck == 6)
		{
			_upgradecheck = 0;
			HomeTempleScreen();
			HomeChoice();
		}
		else if (_upgradecheck == 4)
		{
			if (_characterMoney >= 100000)
			{
				_characterMoney = _characterMoney - 100000;

				_homecheck = 0;
				_upgradecheck = 0;
				_tempPlace = 1;

				_effect = EtempleEnter; // effectsound
				Move(); // black screen 1000ms
				b_homeMusic = false; // mainmusic off
				Sleep(500);
				TempleEvent();
			}
			else
			{
				_upgradecheck = 6;
				UpgradeChoiceScreen();
				HomeUpgradeChoice();
			}
		}
	}
	else if (_key == (char)UP)
	{
		if (_upgradecheck == 2)
		{
			_upgradecheck = 1;
			UpgradeChoiceScreen();
			HomeUpgradeChoice();
		}
		else if (_upgradecheck == 3)
		{
			_upgradecheck = 2;
			UpgradeChoiceScreen();
			HomeUpgradeChoice();
		}
		else if (_upgradecheck == 5)
		{
			_upgradecheck = 4;
			UpgradeChoiceScreen();
			HomeUpgradeChoice();
		}
		else
		{
			HomeUpgradeChoice();
		}
	}
	else if (_key == (char)DOWN)
	{
		if (_upgradecheck == 1)
		{
			_upgradecheck = 2;
			UpgradeChoiceScreen();
			HomeUpgradeChoice();
		}
		else if (_upgradecheck == 2)
		{
			_upgradecheck = 3;
			UpgradeChoiceScreen();
			HomeUpgradeChoice();
		}
		else if (_upgradecheck == 4)
		{
			_upgradecheck = 5;
			UpgradeChoiceScreen();
			HomeUpgradeChoice();
		}
		else
		{
			HomeUpgradeChoice();
		}
	}
	else
	{
		HomeUpgradeChoice();
	}
}
void mainGame::UpgradeChoiceScreen()
{
	gotoxy(0, 0);
	SetColor(9, 15);

	if (_homecheck == 3)
	{
		cout << "■■□□□■■■□□□■■■□□□■■■□□□■■■□□□■■■□□□■■" << endl;	// 1
		cout << "■"; SetColor(0, 15); cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■"; SetColor(9, 15); cout << "■" << endl;	// 2
		cout << "□"; SetColor(0, 15); cout << "■■■■■■■■■■■■■■　　　　　　　■■■■■■■■■■■■■■"; SetColor(9, 15); cout << "□" << endl;	// 3
		cout << "□"; SetColor(0, 15); cout << "■■■■■■■■■■■■■■　　　　　　　■■■■■■■■■■■■■■"; SetColor(9, 15); cout << "□" << endl;	// 4
		cout << "□"; SetColor(0, 15); cout << "■■■■■■■■■■■■■■　　□□□　　■■■■■■■■■■■■■■"; SetColor(9, 15); cout << "□" << endl;	// 5
		cout << "■"; SetColor(0, 15); cout << "■■■■■■■■■■■■■■　　□□□　　■■■■■■■■■■■■■■"; SetColor(9, 15); cout << "■" << endl;	// 6
		cout << "■"; SetColor(0, 15); cout << "■■■■■■■■■■■■■■　　□"; SetColor(14, 15); cout << "■"; SetColor(0, 15); cout << "□　　■■■■■■■■■■■■■■"; SetColor(9, 15); cout << "■" << endl;	// 7
		cout << "■"; SetColor(0, 15); cout << "■■■■■■■■■■■■■■　　"; SetColor(14, 15); cout << "■■■"; SetColor(0, 15); cout << "　　■■■■■■■■■■■■■■"; SetColor(9, 15); cout << "■" << endl;	// 8
		cout << "□"; SetColor(0, 15); cout << "■　　　　　　　　　　　　　　　　"; SetColor(14, 15); cout << "■"; SetColor(0, 15); cout << "　　　　　　　　　　　　　　　　■"; SetColor(9, 15); cout << "□" << endl;	// 9
		cout << "□"; SetColor(0, 15); cout << "■　　　　　　　　　　　　　　　"; SetColor(14, 15); cout << "■　■"; SetColor(0, 15); cout << "　　　　　　　　　　　　　　　■"; SetColor(9, 15); cout << "□" << endl;	// 10
		cout << "□"; SetColor(0, 15); cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■"; SetColor(9, 15); cout << "□" << endl;	// 11
		cout << "■"; SetColor(0, 15); cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■"; SetColor(9, 15); cout << "■" << endl;	// 12
		cout << "■"; SetColor(0, 15); cout << "■　　■■■■■■■■■■■　　　　　　　　　　　　　　　　　　　　■"; SetColor(9, 15); cout << "■" << endl;	// 13
		cout << "■"; SetColor(0, 15); cout << "■　　■　　　　　　　　　■　　　　　　　　　　　　　　　　　　　　■"; SetColor(9, 15); cout << "■" << endl;	// 14
		cout << "□"; SetColor(0, 15); cout << "■　　■■■■　　　　　　■　　　　　　　　　　　　　　　　　　　　■"; SetColor(9, 15); cout << "□" << endl;	// 15
		cout << "□"; SetColor(0, 15); cout << "■　　■■　■　　　　　　■　　　　　　　　　　　　　　　　　　　　■"; SetColor(9, 15); cout << "□" << endl;	// 16
		cout << "□"; SetColor(0, 15); cout << "■　　■■　■　　　　　　■　　　　　　　　　　　　　　　　　　　　■"; SetColor(9, 15); cout << "□" << endl;	// 17
		cout << "■"; SetColor(0, 15); cout << "■　　■■■■　　　　　　■　　　　　　　　　　　　　　　　　　　　■"; SetColor(9, 15); cout << "■" << endl;	// 18
		cout << "■"; SetColor(0, 15); cout << "■　　■　　　　　　　　　■　　　　　　　　　　　　　　　　　　　　■"; SetColor(9, 15); cout << "■" << endl;	// 19
		cout << "■"; SetColor(0, 15); cout << "■　　■■■■■■■■■■■　　　　　　　　　　　　　　　　　　　　■"; SetColor(9, 15); cout << "■" << endl;	// 20
		cout << "□"; SetColor(0, 15); cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■"; SetColor(9, 15); cout << "□" << endl;	// 21
		cout << "□"; SetColor(0, 15); cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■"; SetColor(9, 15); cout << "□" << endl;	// 22
		cout << "□"; SetColor(0, 15); cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■"; SetColor(9, 15); cout << "□" << endl;	// 23
		cout << "■"; SetColor(0, 15); cout << "■■■■■■■■■■■■■■■　　　■■■■■■■■■■■■■■■■■"; SetColor(9, 15); cout << "■" << endl;	// 24
		cout << "■"; SetColor(0, 15); cout << "■■■■■■■■■■■■■■■　　　■■■■■■■■■■■■■■■■■"; SetColor(9, 15); cout << "■" << endl;	// 25
		cout << "■"; SetColor(0, 15); cout << "■■■■■■■■■■■■■■■　　　■■■■■■■■■■■■■■■■■"; SetColor(9, 15); cout << "■" << endl;	// 26
	}
	else if (_village2check == 5)
	{
		cout << "■■□□□■■■□□□■■■□□□■■■□□□■■■□□□■■■□□□■■" << endl;	// 1
		cout << "■"; SetColor(0, 15); cout << "■■　　　　　　　　　　　　　　　　　　　　　　　■■　　　　　　　　"; SetColor(9, 15); cout << "■" << endl;	// 2
		cout << "□"; SetColor(0, 15); cout << "■■　　　　■■■■■■■　　　　　　　　　　　　■■■■■■■■　　"; SetColor(9, 15); cout << "□" << endl;	// 3
		cout << "□"; SetColor(0, 15); cout << "■■　　　■　　　　　　　■　　　　　　　　　　■　　　　　　　　■　"; SetColor(9, 15); cout << "□" << endl;	// 4
		cout << "□"; SetColor(0, 15); cout << "■■　　■　　　　　　　　　■　　　　　　　　■　　　　　　　　　　■"; SetColor(9, 15); cout << "□" << endl;	// 5
		cout << "■"; SetColor(0, 15); cout << "■■　■■■■■■■■■■■■■　　　　　　■■■■■■■■■■■■■"; SetColor(9, 15); cout << "■" << endl;	// 6
		cout << "■"; SetColor(0, 15); cout << "■■　　■　　　　　　　　　■　　　　　　　　■　　　　　　　　　　■"; SetColor(9, 15); cout << "■" << endl;	// 7
		cout << "■"; SetColor(0, 15); cout << "■■　　■　■■■　　　　　■　　　　　　　　■　■■■　　　　　　■"; SetColor(9, 15); cout << "■" << endl;	// 8
		cout << "□"; SetColor(0, 15); cout << "■■　　■　■　■　　■■　■　　　　　　　　■　■　■　　　　　　■"; SetColor(9, 15); cout << "□" << endl;	// 9
		cout << "□"; SetColor(0, 15); cout << "■■　　■　■　■　　"; SetColor(12, 15); cout << "　■　"; SetColor(0, 15); cout << "■　　　　　　　　■　■　■　　　　　　■"; SetColor(9, 15); cout << "□" << endl;	// 10
		cout << "□"; SetColor(0, 15); cout << "■■　　■■■■■■■"; SetColor(12, 15); cout << "■■■"; SetColor(0, 15); cout << "■　　　　　　　　■■■■■■■■■■■■"; SetColor(9, 15); cout << "□" << endl;	// 11
		cout << "■"; SetColor(0, 15); cout << "■■　　　　　　　　　"; SetColor(12, 15); cout << "　■　　　　　　　　　　　　　　　　　　　　　　"; SetColor(9, 15); cout << "■" << endl;	// 12
		cout << "■"; SetColor(0, 15); cout << "■■　　　　　　　　　"; SetColor(12, 15); cout << "■　■　　　　　　　　　　　　　　　　　　　　　"; SetColor(9, 15); cout << "■" << endl;	// 13
		cout << "■"; SetColor(0, 15); cout << "■■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　"; SetColor(9, 15); cout << "■" << endl;	// 14
		cout << "□"; SetColor(0, 15); cout << "■■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　"; SetColor(9, 15); cout << "□" << endl;	// 15
		cout << "□"; SetColor(0, 15); cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　"; SetColor(9, 15); cout << "□" << endl;	// 16
		cout << "□　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　"; SetColor(9, 15); cout << "□" << endl;	// 17
		cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　"; SetColor(9, 15); cout << "■" << endl;	// 18
		cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　"; SetColor(9, 15); cout << "■" << endl;	// 19
		cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　"; SetColor(9, 15); cout << "■" << endl;	// 20
		cout << "□　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　"; SetColor(9, 15); cout << "□" << endl;	// 21
		cout << "□　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　"; SetColor(9, 15); cout << "□" << endl;	// 22
		cout << "□　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　"; SetColor(9, 15); cout << "□" << endl;	// 23
		cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　"; SetColor(9, 15); cout << "■" << endl;	// 24
		cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　"; SetColor(9, 15); cout << "■" << endl;	// 25
		cout << "■"; SetColor(0, 15); cout << "■　　　　　　■■■■■■■　　　　　　　　　　　　　■■■■■■■　"; SetColor(9, 15); cout << "■" << endl;	// 26
	}


	switch (_upgradecheck)
	{
	case 1:
	{
		SetColor(13, 15);

		cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;
		cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
		cout << "■　　"; SetColor(0, 15); cout << "▶　신들을 만나고 싶습니다.　(체력, 기력 강화)"; SetColor(13, 15); cout << " 　　　　　　　　　 ■" << endl;
		cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
		cout << "■　　"; SetColor(0, 15); cout << "　　전직하고 싶습니다."; SetColor(13, 15); cout << "　　　　　　　　　　　　　　　　　　　　　　■" << endl;
		cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
		cout << "■　　"; SetColor(0, 15); cout << "　　나가기"; SetColor(13, 15); cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
		cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
		cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
		cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
		cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;
	}
	break;
	case 2:
	{
		SetColor(13, 15);

		cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;
		cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
		cout << "■　　"; SetColor(0, 15); cout << "　　신들을 만나고 싶습니다.　(체력, 기력 강화)"; SetColor(13, 15); cout << " 　　　　　　　　　 ■" << endl;
		cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
		cout << "■　　"; SetColor(0, 15); cout << "▶　전직하고 싶습니다."; SetColor(13, 15); cout << "　　　　　　　　　　　　　　　　　　　　　　■" << endl;
		cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
		cout << "■　　"; SetColor(0, 15); cout << "　　나가기"; SetColor(13, 15); cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
		cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
		cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
		cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
		cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;
	}
	break;
	case 3:
	{
		SetColor(13, 15);

		cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;
		cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
		cout << "■　　"; SetColor(0, 15); cout << "　　신들을 만나고 싶습니다.　(체력, 기력 강화)"; SetColor(13, 15); cout << " 　　　　　　　　　 ■" << endl;
		cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
		cout << "■　　"; SetColor(0, 15); cout << "　　전직하고 싶습니다."; SetColor(13, 15); cout << "　　　　　　　　　　　　　　　　　　　　　　■" << endl;
		cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
		cout << "■　　"; SetColor(0, 15); cout << "▶　나가기"; SetColor(13, 15); cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
		cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
		cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
		cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
		cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;
	}
	break;
	case 4:
	{
		SetColor(13, 15);

		cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;
		cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
		cout << "■　　"; SetColor(0, 15); cout << "신들을 만나기 위해서 금전 100,000원을 제물로 바쳐야합니다."; SetColor(13, 15); cout << " 　　　 ■" << endl;
		cout << "■　　"; SetColor(0, 15); cout << "괜찮으십니까?"; SetColor(13, 15); cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　 ■" << endl;
		cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
		cout << "■　　"; SetColor(0, 15); cout << "▶　네"; SetColor(13, 15); cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
		cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
		cout << "■　　"; SetColor(0, 15); cout << "　　조금 더 생각해볼게요"; SetColor(13, 15); cout << "　　　　　　　　　　　　　　　　　　　　　■" << endl;
		cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
		cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
		cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;
	}
	break;
	case 5:
	{
		SetColor(13, 15);

		cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;
		cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
		cout << "■　　"; SetColor(0, 15); cout << "신들을 만나기 위해서 금전 100,000원을 제물로 바쳐야합니다."; SetColor(13, 15); cout << " 　　　 ■" << endl;
		cout << "■　　"; SetColor(0, 15); cout << "괜찮으십니까?"; SetColor(13, 15); cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　 ■" << endl;
		cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
		cout << "■　　"; SetColor(0, 15); cout << "　　네"; SetColor(13, 15); cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
		cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
		cout << "■　　"; SetColor(0, 15); cout << "▶　조금 더 생각해볼게요"; SetColor(13, 15); cout << "　　　　　　　　　　　　　　　　　　　　　■" << endl;
		cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
		cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
		cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;
	}
	break;
	case 6:
	{
		SetColor(13, 15);

		cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;
		cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
		cout << "■　　"; SetColor(0, 15); cout << "금전이 부족합니다.."; SetColor(13, 15); cout << "　　　 　　　　　　　　　　　　　　　　　　　　■" << endl;
		cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
		cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
		cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
		cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
		cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
		cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
		cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
		cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;
	}
	break;
	}
}
/////////////////////////////////////////////
void mainGame::TempleEvent()
{
	_templecheck = 1;
	TempleScreen();
	b_templeMusic = true;
	Sleep(1500);
	_effect = EtempleEnter;
	if (_tempPlace == 1)
	{
		_templecheck = 2;
	}
	else if (_tempPlace == 2)
	{
		_templecheck = 3;
	}
	Sleep(700);
	TempleScreen();
	TempleChoice();
}
void mainGame::TempleScreen()
{
	if (_templecheck == 1)
	{
		gotoxy(0, 0);
		SetColor(9, 15);

		cout << "■■□□□■■■□□□■■■□□□■■■□□□■■■□□□■■■□□□■■" << endl;	// 1
		cout << "■"; SetColor(0, 15); cout << "　　　　　　　　　　　　　　　　　　■■■■■■■■■■■■■■■■■"; SetColor(9, 15); cout << "■" << endl;	// 2
		cout << "□"; SetColor(0, 15); cout << "　　　　　　　　　　　　　　　　　　■■■■■■■■■■■　　　　　■"; SetColor(9, 15); cout << "□" << endl;	// 3
		cout << "□"; SetColor(0, 15); cout << "　　　　　　　　　　　　　　　　　　■■■■■■■■■■■　신들의　■"; SetColor(9, 15); cout << "□" << endl;	// 4
		cout << "□"; SetColor(0, 15); cout << "　　　　　　　　　　　　　　　　　　■■■■■■■■■■■　　　　　■"; SetColor(9, 15); cout << "□" << endl;	// 5
		cout << "■"; SetColor(0, 15); cout << "　　　　　■■■■■■■■■　　　　　■■■■■■■■■■　세　계　■"; SetColor(9, 15); cout << "■" << endl;	// 6
		cout << "■"; SetColor(0, 15); cout << "　　　　■　　　　　　　■　■　　　　■■■■■■■■■■　　　　　■"; SetColor(9, 15); cout << "■" << endl;	// 7
		cout << "■"; SetColor(0, 15); cout << "　　　■　　　　　　　■　　　■　　　■■■■■■■■■■■■■■■■"; SetColor(9, 15); cout << "■" << endl;	// 8
		cout << "□"; SetColor(0, 15); cout << "　　■　　　　　　　■　　　　　■　　■■■■■■■■■■■■■■■■"; SetColor(9, 15); cout << "□" << endl;	// 9
		cout << "□"; SetColor(0, 15); cout << "　■■■■■■■■■■■■■■■■　　　■■■■■■■■■■■■■■■"; SetColor(9, 15); cout << "□" << endl;	// 10
		cout << "□"; SetColor(0, 15); cout << "　　■　　　　　　　　■■　■■　　　　■■■■■■■■■■■■■■■"; SetColor(9, 15); cout << "□" << endl;	// 11
		cout << "■"; SetColor(0, 15); cout << "　　■　　　　　　　　■■　■■　　　　■■■■■■■■■■■■■■■"; SetColor(9, 15); cout << "■" << endl;	// 12
		cout << "■"; SetColor(0, 15); cout << "　　■　　　　　　　　■■　■■　　　　■■■■■■■■■■■■■■■"; SetColor(9, 15); cout << "■" << endl;	// 13
		cout << "■"; SetColor(0, 15); cout << "　　■　　　　　　　　■■　■■　　　　　■■■■■■■■■■■■■■"; SetColor(9, 15); cout << "■" << endl;	// 14
		cout << "□"; SetColor(0, 15); cout << "　　■　　　　　　　　■■　■■　　　　　　■■■■■■■■■■■■■"; SetColor(9, 15); cout << "□" << endl;	// 15
		cout << "□"; SetColor(0, 15); cout << "　■■■■■■■■■■■■■■■■　　　　　　■■■■■■■■■■■■"; SetColor(9, 15); cout << "□" << endl;	// 16
		cout << "□　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　□" << endl;	// 17
		cout << "■"; SetColor(0, 15); cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　□□□　"; SetColor(9, 15); cout << "■" << endl;	// 18
		cout << "■"; SetColor(0, 15); cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　□□□　"; SetColor(9, 15); cout << "■" << endl;	// 19
		cout << "■"; SetColor(0, 15); cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　□□□　"; SetColor(9, 15); cout << "■" << endl;	// 20
		cout << "□　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　□" << endl;	// 21
		cout << "□"; SetColor(0, 15); cout << "　　　　　　　　　　　　　　　　　　　　　　　■■■■■■■■■■■■"; SetColor(9, 15); cout << "□" << endl;	// 22
		cout << "□"; SetColor(0, 15); cout << "　　　　　■■■■■■■■■　　　　　　　　■■■■■■■■■■■■■"; SetColor(9, 15); cout << "□" << endl;	// 23
		cout << "■"; SetColor(0, 15); cout << "　　　　■　　　　　　　■　■　　　　　　■■■■■■■■■■■■■■"; SetColor(9, 15); cout << "■" << endl;	// 24
		cout << "■"; SetColor(0, 15); cout << "　　　■　　　　　　　■　　　■　　　　　■■■■■■■■■■■■■■"; SetColor(9, 15); cout << "■" << endl;	// 25
		cout << "■"; SetColor(0, 15); cout << "　　■　　　　　　　■　　　　　■　　　　■■■■■■■■■■■■■■"; SetColor(9, 15); cout << "■" << endl;	// 26
		cout << "□"; SetColor(0, 15); cout << "　■■■■■■■■■■■■■■■■　　　　■■■■■■■■■■■■■■"; SetColor(9, 15); cout << "□" << endl;	// 27
		cout << "□"; SetColor(0, 15); cout << "　　■　　　　　　　　■■　■■　　　　　■■■■■■■■■■■■■■"; SetColor(9, 15); cout << "□" << endl;	// 28
		cout << "□"; SetColor(0, 15); cout << "　　■　　　　　　　　■■　■■　　　　　■■■■■■■■■■■■■■"; SetColor(9, 15); cout << "□" << endl;	// 29
		cout << "■"; SetColor(0, 15); cout << "　　■　　　　　　　　■■　■■　　　　　■■■■■■■■■■■■■■"; SetColor(9, 15); cout << "■" << endl;	// 30
		cout << "■"; SetColor(0, 15); cout << "　　■　　　　　　　　■■　■■　　　　　　■■■■■■■■■■■■■"; SetColor(9, 15); cout << "■" << endl;	// 31
		cout << "■"; SetColor(0, 15); cout << "　　■　　　　　　　　■■　■■　　　　　　■■■■■■■■■■■■■"; SetColor(9, 15); cout << "■" << endl;	// 32
		cout << "□"; SetColor(0, 15); cout << "　■■■■■■■■■■■■■■■■　　　　　　■■■■■■■■■■■■"; SetColor(9, 15); cout << "□" << endl;	// 33
		cout << "□"; SetColor(0, 15); cout << "　　　　　　　　　　　　　　　　　　　　　　　　■■■■■■■■■■■"; SetColor(9, 15); cout << "□" << endl;	// 34
		cout << "□"; SetColor(0, 15); cout << "　　　　　　　　　　　　　　　　　　　　　　　　　■■■■■■■■■■"; SetColor(9, 15); cout << "□" << endl;	// 35
		cout << "■"; SetColor(0, 15); cout << "　　　　　　　　　　　　　　　　　　　　　　　　　■■■■■■■■■■"; SetColor(9, 15); cout << "■" << endl;	// 36
		cout << "■■□□□■■■□□□■■■□□□■■■□□□■■■□□□■■■□□□■■" << endl;	// 37

	}

	else if (_templecheck == 2)
	{
		gotoxy(0, 0);
		SetColor(9, 15);

		cout << "■■□□□■■■□□□■■■□□□■■■□□□■■■□□□■■■□□□■■" << endl;	// 1
		cout << "■"; SetColor(0, 15); cout << "　　　　　　　　　　　　　　　　　　■■■■■■■■■■■■■■■■■"; SetColor(9, 15); cout << "■" << endl;	// 2
		cout << "□"; SetColor(0, 15); cout << "　　　　　　　　　　　　　　　　　　■■■■■■■■■■■　　　　　■"; SetColor(9, 15); cout << "□" << endl;	// 3
		cout << "□"; SetColor(0, 15); cout << "　　　　　　　　　　　　　　　　　　■■■■■■■■■■■　인간계　■"; SetColor(9, 15); cout << "□" << endl;	// 4
		cout << "□"; SetColor(0, 15); cout << "　　　　　　　　　　　　　　　　　　■■■■■■■■■■■　　　　　■"; SetColor(9, 15); cout << "□" << endl;	// 5
		cout << "■"; SetColor(0, 15); cout << "　　　　　■■■■■■■■■　　　　　■■■■■■■■■■　 (집) 　■"; SetColor(9, 15); cout << "■" << endl;	// 6
		cout << "■"; SetColor(0, 15); cout << "　　　　■　　　　　　　■　■　　　　■■■■■■■■■■　　　　　■"; SetColor(9, 15); cout << "■" << endl;	// 7
		cout << "■"; SetColor(0, 15); cout << "　　　■　　　　　　　■　　　■　　　■■■■■■■■■■■■■■■■"; SetColor(9, 15); cout << "■" << endl;	// 8
		cout << "□"; SetColor(0, 15); cout << "　　■　　　　　　　■　　　　　■　　■■■■■■■■■■■■■■■■"; SetColor(9, 15); cout << "□" << endl;	// 9
		cout << "□"; SetColor(0, 15); cout << "　■■■■■■■■■■■■■■■■　　　■■■■■■■■■■■■■■■"; SetColor(9, 15); cout << "□" << endl;	// 10
		cout << "□"; SetColor(0, 15); cout << "　　■　　　　　　　　■■　■■　　　　■■■■■■■■■■■■■■■"; SetColor(9, 15); cout << "□" << endl;	// 11
		cout << "■"; SetColor(0, 15); cout << "　　■　　　　　　　　■■　■■　　　　■■■■■■■■■■■■■■■"; SetColor(9, 15); cout << "■" << endl;	// 12
		cout << "■"; SetColor(0, 15); cout << "　　■　　　　　　　　■■　■■　　　　■■■■■■■■■■■■■■■"; SetColor(9, 15); cout << "■" << endl;	// 13
		cout << "■"; SetColor(0, 15); cout << "　　■　　　　　　　　■■　■■　　　　　■■■■■■■■■■■■■■"; SetColor(9, 15); cout << "■" << endl;	// 14
		cout << "□"; SetColor(0, 15); cout << "　　■　　　　　　　　■■　■■　　　　　　■■■■■■■■■■■■■"; SetColor(9, 15); cout << "□" << endl;	// 15
		cout << "□"; SetColor(0, 15); cout << "　■■■■■■■■■■■■■■■■　　　　　　■■■■■■■■■■■■"; SetColor(9, 15); cout << "□" << endl;	// 16
		cout << "□"; SetColor(0, 15); cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　"; SetColor(14, 15); cout << "　■　　　　　　"; SetColor(9, 15); cout << "□" << endl;	// 17
		cout << "■"; SetColor(0, 15); cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　"; SetColor(14, 15); cout << "■■■　"; SetColor(0, 15); cout << "□□□　"; SetColor(9, 15); cout << "■" << endl;	// 18
		cout << "■"; SetColor(0, 15); cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　"; SetColor(14, 15); cout << "　■　　"; SetColor(0, 15); cout << "□□□　"; SetColor(9, 15); cout << "■" << endl;	// 19
		cout << "■"; SetColor(0, 15); cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　"; SetColor(14, 15); cout << "■　■　"; SetColor(0, 15); cout << "□□□　"; SetColor(9, 15); cout << "■" << endl;	// 20
		cout << "□"; SetColor(0, 15); cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　"; SetColor(9, 15); cout << "□" << endl;	// 21
		cout << "□"; SetColor(0, 15); cout << "　　　　　　　　　　　　　　　　　　　　　　　■■■■■■■■■■■■"; SetColor(9, 15); cout << "□" << endl;	// 22
		cout << "□"; SetColor(0, 15); cout << "　　　　　■■■■■■■■■　　　　　　　　■■■■■■■■■■■■■"; SetColor(9, 15); cout << "□" << endl;	// 23
		cout << "■"; SetColor(0, 15); cout << "　　　　■　　　　　　　■　■　　　　　　■■■■■■■■■■■■■■"; SetColor(9, 15); cout << "■" << endl;	// 24
		cout << "■"; SetColor(0, 15); cout << "　　　■　　　　　　　■　　　■　　　　　■■■■■■■■■■■■■■"; SetColor(9, 15); cout << "■" << endl;	// 25
		cout << "■"; SetColor(0, 15); cout << "　　■　　　　　　　■　　　　　■　　　　■■■■■■■■■■■■■■"; SetColor(9, 15); cout << "■" << endl;	// 26
		cout << "□"; SetColor(0, 15); cout << "　■■■■■■■■■■■■■■■■　　　　■■■■■■■■■■■■■■"; SetColor(9, 15); cout << "□" << endl;	// 27
		cout << "□"; SetColor(0, 15); cout << "　　■　　　　　　　　■■　■■　　　　　■■■■■■■■■■■■■■"; SetColor(9, 15); cout << "□" << endl;	// 28
		cout << "□"; SetColor(0, 15); cout << "　　■　　　　　　　　■■　■■　　　　　■■■■■■■■■■■■■■"; SetColor(9, 15); cout << "□" << endl;	// 29
		cout << "■"; SetColor(0, 15); cout << "　　■　　　　　　　　■■　■■　　　　　■■■■■■■■■■■■■■"; SetColor(9, 15); cout << "■" << endl;	// 30
		cout << "■"; SetColor(0, 15); cout << "　　■　　　　　　　　■■　■■　　　　　　■■■■■■■■■■■■■"; SetColor(9, 15); cout << "■" << endl;	// 31
		cout << "■"; SetColor(0, 15); cout << "　　■　　　　　　　　■■　■■　　　　　　■■■■■■■■■■■■■"; SetColor(9, 15); cout << "■" << endl;	// 32
		cout << "□"; SetColor(0, 15); cout << "　■■■■■■■■■■■■■■■■　　　　　　■■■■■■■■■■■■"; SetColor(9, 15); cout << "□" << endl;	// 33
		cout << "□"; SetColor(0, 15); cout << "　　　　　　　　　　　　　　　　　　　　　　　　■■■■■■■■■■■"; SetColor(9, 15); cout << "□" << endl;	// 34
		cout << "□"; SetColor(0, 15); cout << "　　　　　　　　　　　　　　　　　　　　　　　　　■■■■■■■■■■"; SetColor(9, 15); cout << "□" << endl;	// 35
		cout << "■"; SetColor(0, 15); cout << "　　　　　　　　　　　　　　　　　　　　　　　　　■■■■■■■■■■"; SetColor(9, 15); cout << "■" << endl;	// 36
		cout << "■■□□□■■■□□□■■■□□□■■■□□□■■■□□□■■■□□□■■" << endl;	// 37
	}

	else if (_templecheck == 3)
	{
		gotoxy(0, 0);
		SetColor(9, 15);

		cout << "■■□□□■■■□□□■■■□□□■■■□□□■■■□□□■■■□□□■■" << endl;	// 1
		cout << "■"; SetColor(0, 15); cout << "　　　　　　　　　　　　　　　　　　■■■■■■■■■■■■■■■■■"; SetColor(9, 15); cout << "■" << endl;	// 2
		cout << "□"; SetColor(0, 15); cout << "　　　　　　　　　　　　　　　　　　■■■■■■■■■■■　　　　　■"; SetColor(9, 15); cout << "□" << endl;	// 3
		cout << "□"; SetColor(0, 15); cout << "　　　　　　　　　　　　　　　　　　■■■■■■■■■■■　인간계　■"; SetColor(9, 15); cout << "□" << endl;	// 4
		cout << "□"; SetColor(0, 15); cout << "　　　　　　　　　　　　　　　　　　■■■■■■■■■■■　　　　　■"; SetColor(9, 15); cout << "□" << endl;	// 5
		cout << "■"; SetColor(0, 15); cout << "　　　　　■■■■■■■■■　　　　　■■■■■■■■■■　(마을)　■"; SetColor(9, 15); cout << "■" << endl;	// 6
		cout << "■"; SetColor(0, 15); cout << "　　　　■　　　　　　　■　■　　　　■■■■■■■■■■　　　　　■"; SetColor(9, 15); cout << "■" << endl;	// 7
		cout << "■"; SetColor(0, 15); cout << "　　　■　　　　　　　■　　　■　　　■■■■■■■■■■■■■■■■"; SetColor(9, 15); cout << "■" << endl;	// 8
		cout << "□"; SetColor(0, 15); cout << "　　■　　　　　　　■　　　　　■　　■■■■■■■■■■■■■■■■"; SetColor(9, 15); cout << "□" << endl;	// 9
		cout << "□"; SetColor(0, 15); cout << "　■■■■■■■■■■■■■■■■　　　■■■■■■■■■■■■■■■"; SetColor(9, 15); cout << "□" << endl;	// 10
		cout << "□"; SetColor(0, 15); cout << "　　■　　　　　　　　■■　■■　　　　■■■■■■■■■■■■■■■"; SetColor(9, 15); cout << "□" << endl;	// 11
		cout << "■"; SetColor(0, 15); cout << "　　■　　　　　　　　■■　■■　　　　■■■■■■■■■■■■■■■"; SetColor(9, 15); cout << "■" << endl;	// 12
		cout << "■"; SetColor(0, 15); cout << "　　■　　　　　　　　■■　■■　　　　■■■■■■■■■■■■■■■"; SetColor(9, 15); cout << "■" << endl;	// 13
		cout << "■"; SetColor(0, 15); cout << "　　■　　　　　　　　■■　■■　　　　　■■■■■■■■■■■■■■"; SetColor(9, 15); cout << "■" << endl;	// 14
		cout << "□"; SetColor(0, 15); cout << "　　■　　　　　　　　■■　■■　　　　　　■■■■■■■■■■■■■"; SetColor(9, 15); cout << "□" << endl;	// 15
		cout << "□"; SetColor(0, 15); cout << "　■■■■■■■■■■■■■■■■　　　　　　■■■■■■■■■■■■"; SetColor(9, 15); cout << "□" << endl;	// 16
		cout << "□"; SetColor(0, 15); cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　"; SetColor(14, 15); cout << "　■　　　　　　"; SetColor(9, 15); cout << "□" << endl;	// 17
		cout << "■"; SetColor(0, 15); cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　"; SetColor(14, 15); cout << "■■■　"; SetColor(0, 15); cout << "□□□　"; SetColor(9, 15); cout << "■" << endl;	// 18
		cout << "■"; SetColor(0, 15); cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　"; SetColor(14, 15); cout << "　■　　"; SetColor(0, 15); cout << "□□□　"; SetColor(9, 15); cout << "■" << endl;	// 19
		cout << "■"; SetColor(0, 15); cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　"; SetColor(14, 15); cout << "■　■　"; SetColor(0, 15); cout << "□□□　"; SetColor(9, 15); cout << "■" << endl;	// 20
		cout << "□"; SetColor(0, 15); cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　"; SetColor(9, 15); cout << "□" << endl;	// 21
		cout << "□"; SetColor(0, 15); cout << "　　　　　　　　　　　　　　　　　　　　　　　■■■■■■■■■■■■"; SetColor(9, 15); cout << "□" << endl;	// 22
		cout << "□"; SetColor(0, 15); cout << "　　　　　■■■■■■■■■　　　　　　　　■■■■■■■■■■■■■"; SetColor(9, 15); cout << "□" << endl;	// 23
		cout << "■"; SetColor(0, 15); cout << "　　　　■　　　　　　　■　■　　　　　　■■■■■■■■■■■■■■"; SetColor(9, 15); cout << "■" << endl;	// 24
		cout << "■"; SetColor(0, 15); cout << "　　　■　　　　　　　■　　　■　　　　　■■■■■■■■■■■■■■"; SetColor(9, 15); cout << "■" << endl;	// 25
		cout << "■"; SetColor(0, 15); cout << "　　■　　　　　　　■　　　　　■　　　　■■■■■■■■■■■■■■"; SetColor(9, 15); cout << "■" << endl;	// 26
		cout << "□"; SetColor(0, 15); cout << "　■■■■■■■■■■■■■■■■　　　　■■■■■■■■■■■■■■"; SetColor(9, 15); cout << "□" << endl;	// 27
		cout << "□"; SetColor(0, 15); cout << "　　■　　　　　　　　■■　■■　　　　　■■■■■■■■■■■■■■"; SetColor(9, 15); cout << "□" << endl;	// 28
		cout << "□"; SetColor(0, 15); cout << "　　■　　　　　　　　■■　■■　　　　　■■■■■■■■■■■■■■"; SetColor(9, 15); cout << "□" << endl;	// 29
		cout << "■"; SetColor(0, 15); cout << "　　■　　　　　　　　■■　■■　　　　　■■■■■■■■■■■■■■"; SetColor(9, 15); cout << "■" << endl;	// 30
		cout << "■"; SetColor(0, 15); cout << "　　■　　　　　　　　■■　■■　　　　　　■■■■■■■■■■■■■"; SetColor(9, 15); cout << "■" << endl;	// 31
		cout << "■"; SetColor(0, 15); cout << "　　■　　　　　　　　■■　■■　　　　　　■■■■■■■■■■■■■"; SetColor(9, 15); cout << "■" << endl;	// 32
		cout << "□"; SetColor(0, 15); cout << "　■■■■■■■■■■■■■■■■　　　　　　■■■■■■■■■■■■"; SetColor(9, 15); cout << "□" << endl;	// 33
		cout << "□"; SetColor(0, 15); cout << "　　　　　　　　　　　　　　　　　　　　　　　　■■■■■■■■■■■"; SetColor(9, 15); cout << "□" << endl;	// 34
		cout << "□"; SetColor(0, 15); cout << "　　　　　　　　　　　　　　　　　　　　　　　　　■■■■■■■■■■"; SetColor(9, 15); cout << "□" << endl;	// 35
		cout << "■"; SetColor(0, 15); cout << "　　　　　　　　　　　　　　　　　　　　　　　　　■■■■■■■■■■"; SetColor(9, 15); cout << "■" << endl;	// 36
		cout << "■■□□□■■■□□□■■■□□□■■■□□□■■■□□□■■■□□□■■" << endl;	// 37
	}

	else if (_templecheck == 4)
	{
		gotoxy(0, 0);
		SetColor(9, 15);

		cout << "■■□□□■■■□□□■■■□□□■■■□□□■■■□□□■■■□□□■■" << endl;	// 1
		cout << "■"; SetColor(0, 15); cout << "　　　　　　　　　　　　　　　　　　■■■■■■■■■■■■■■■■■"; SetColor(9, 15); cout << "■" << endl;	// 2
		cout << "□"; SetColor(0, 15); cout << "　　　　　　　　　　　　　　　　　　■■■■■■■■■■■　　　　　■"; SetColor(9, 15); cout << "□" << endl;	// 3
		cout << "□"; SetColor(0, 15); cout << "　　　　　　　　　　　　　　　　　　■■■■■■■■■■■　세　오　■"; SetColor(9, 15); cout << "□" << endl;	// 4
		cout << "□"; SetColor(0, 15); cout << "　　　　　　　　　　　　　　　　　　■■■■■■■■■■■　　　　　■"; SetColor(9, 15); cout << "□" << endl;	// 5
		cout << "■"; SetColor(0, 15); cout << "　　　　　■■■■■■■■■　　　　　■■■■■■■■■■　신　전　■"; SetColor(9, 15); cout << "■" << endl;	// 6
		cout << "■"; SetColor(0, 15); cout << "　　　　■　　　　　　　■　■　　　　■■■■■■■■■■　　　　　■"; SetColor(9, 15); cout << "■" << endl;	// 7
		cout << "■"; SetColor(0, 15); cout << "　　　■　　　　　　　■　　　■　　　■■■■■■■■■■■■■■■■"; SetColor(9, 15); cout << "■" << endl;	// 8
		cout << "□"; SetColor(0, 15); cout << "　　■　　　　　　　■　　　　　■　　■■■■■■■■■■■■■■■■"; SetColor(9, 15); cout << "□" << endl;	// 9
		cout << "□"; SetColor(0, 15); cout << "　■■■■■■■■■■■■■■■■　　　■■■■■■■■■■■■■■■"; SetColor(9, 15); cout << "□" << endl;	// 10
		cout << "□"; SetColor(0, 15); cout << "　　■　　　　　　　　■■　■■　　　　■■■■■■■■■■■■■■■"; SetColor(9, 15); cout << "□" << endl;	// 11
		cout << "■"; SetColor(0, 15); cout << "　　■　　　　　　　　■■　■■　　　　■■■■■■■■■■■■■■■"; SetColor(9, 15); cout << "■" << endl;	// 12
		cout << "■"; SetColor(0, 15); cout << "　　■　　　　　　　　■■　■■　"; SetColor(14, 15); cout << "　■　"; SetColor(0, 15); cout << "■■■■■■■■■■■■■■■"; SetColor(9, 15); cout << "■" << endl;	// 13
		cout << "■"; SetColor(0, 15); cout << "　　■　　　　　　　　■■　■■　"; SetColor(14, 15); cout << "■■■"; SetColor(0, 15); cout << "　■■■■■■■■■■■■■■"; SetColor(9, 15); cout << "■" << endl;	// 14
		cout << "□"; SetColor(0, 15); cout << "　　■　　　　　　　　■■　■■　"; SetColor(14, 15); cout << "　■　"; SetColor(0, 15); cout << "　　■■■■■■■■■■■■■"; SetColor(9, 15); cout << "□" << endl;	// 15
		cout << "□"; SetColor(0, 15); cout << "　■■■■■■■■■■■■■■■■"; SetColor(14, 15); cout << "■　■"; SetColor(0, 15); cout << "　　　■■■■■■■■■■■■"; SetColor(9, 15); cout << "□" << endl;	// 16
		cout << "□　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　□" << endl;	// 17
		cout << "■"; SetColor(0, 15); cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　□□□　"; SetColor(9, 15); cout << "■" << endl;	// 18
		cout << "■"; SetColor(0, 15); cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　□□□　"; SetColor(9, 15); cout << "■" << endl;	// 19
		cout << "■"; SetColor(0, 15); cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　□□□　"; SetColor(9, 15); cout << "■" << endl;	// 20
		cout << "□　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　□" << endl;	// 21
		cout << "□"; SetColor(0, 15); cout << "　　　　　　　　　　　　　　　　　　　　　　　■■■■■■■■■■■■"; SetColor(9, 15); cout << "□" << endl;	// 22
		cout << "□"; SetColor(0, 15); cout << "　　　　　■■■■■■■■■　　　　　　　　■■■■■■■■■■■■■"; SetColor(9, 15); cout << "□" << endl;	// 23
		cout << "■"; SetColor(0, 15); cout << "　　　　■　　　　　　　■　■　　　　　　■■■■■■■■■■■■■■"; SetColor(9, 15); cout << "■" << endl;	// 24
		cout << "■"; SetColor(0, 15); cout << "　　　■　　　　　　　■　　　■　　　　　■■■■■■■■■■■■■■"; SetColor(9, 15); cout << "■" << endl;	// 25
		cout << "■"; SetColor(0, 15); cout << "　　■　　　　　　　■　　　　　■　　　　■■■■■■■■■■■■■■"; SetColor(9, 15); cout << "■" << endl;	// 26
		cout << "□"; SetColor(0, 15); cout << "　■■■■■■■■■■■■■■■■　　　　■■■■■■■■■■■■■■"; SetColor(9, 15); cout << "□" << endl;	// 27
		cout << "□"; SetColor(0, 15); cout << "　　■　　　　　　　　■■　■■　　　　　■■■■■■■■■■■■■■"; SetColor(9, 15); cout << "□" << endl;	// 28
		cout << "□"; SetColor(0, 15); cout << "　　■　　　　　　　　■■　■■　　　　　■■■■■■■■■■■■■■"; SetColor(9, 15); cout << "□" << endl;	// 29
		cout << "■"; SetColor(0, 15); cout << "　　■　　　　　　　　■■　■■　　　　　■■■■■■■■■■■■■■"; SetColor(9, 15); cout << "■" << endl;	// 30
		cout << "■"; SetColor(0, 15); cout << "　　■　　　　　　　　■■　■■　　　　　　■■■■■■■■■■■■■"; SetColor(9, 15); cout << "■" << endl;	// 31
		cout << "■"; SetColor(0, 15); cout << "　　■　　　　　　　　■■　■■　　　　　　■■■■■■■■■■■■■"; SetColor(9, 15); cout << "■" << endl;	// 32
		cout << "□"; SetColor(0, 15); cout << "　■■■■■■■■■■■■■■■■　　　　　　■■■■■■■■■■■■"; SetColor(9, 15); cout << "□" << endl;	// 33
		cout << "□"; SetColor(0, 15); cout << "　　　　　　　　　　　　　　　　　　　　　　　　■■■■■■■■■■■"; SetColor(9, 15); cout << "□" << endl;	// 34
		cout << "□"; SetColor(0, 15); cout << "　　　　　　　　　　　　　　　　　　　　　　　　　■■■■■■■■■■"; SetColor(9, 15); cout << "□" << endl;	// 35
		cout << "■"; SetColor(0, 15); cout << "　　　　　　　　　　　　　　　　　　　　　　　　　■■■■■■■■■■"; SetColor(9, 15); cout << "■" << endl;	// 36
		cout << "■■□□□■■■□□□■■■□□□■■■□□□■■■□□□■■■□□□■■" << endl;	// 37

	}
	else if (_templecheck == 5)
	{
		gotoxy(0, 0);
		SetColor(9, 15);

		cout << "■■□□□■■■□□□■■■□□□■■■□□□■■■□□□■■■□□□■■" << endl;	// 1
		cout << "■"; SetColor(0, 15); cout << "　　　　　　　　　　　　　　　　　　■■■■■■■■■■■■■■■■■"; SetColor(9, 15); cout << "■" << endl;	// 2
		cout << "□"; SetColor(0, 15); cout << "　　　　　　　　　　　　　　　　　　■■■■■■■■■■■　　　　　■"; SetColor(9, 15); cout << "□" << endl;	// 3
		cout << "□"; SetColor(0, 15); cout << "　　　　　　　　　　　　　　　　　　■■■■■■■■■■■　　칸　　■"; SetColor(9, 15); cout << "□" << endl;	// 4
		cout << "□"; SetColor(0, 15); cout << "　　　　　　　　　　　　　　　　　　■■■■■■■■■■■　　　　　■"; SetColor(9, 15); cout << "□" << endl;	// 5
		cout << "■"; SetColor(0, 15); cout << "　　　　　■■■■■■■■■　　　　　■■■■■■■■■■　신　전　■"; SetColor(9, 15); cout << "■" << endl;	// 6
		cout << "■"; SetColor(0, 15); cout << "　　　　■　　　　　　　■　■　　　　■■■■■■■■■■　　　　　■"; SetColor(9, 15); cout << "■" << endl;	// 7
		cout << "■"; SetColor(0, 15); cout << "　　　■　　　　　　　■　　　■　　　■■■■■■■■■■■■■■■■"; SetColor(9, 15); cout << "■" << endl;	// 8
		cout << "□"; SetColor(0, 15); cout << "　　■　　　　　　　■　　　　　■　　■■■■■■■■■■■■■■■■"; SetColor(9, 15); cout << "□" << endl;	// 9
		cout << "□"; SetColor(0, 15); cout << "　■■■■■■■■■■■■■■■■　　　■■■■■■■■■■■■■■■"; SetColor(9, 15); cout << "□" << endl;	// 10
		cout << "□"; SetColor(0, 15); cout << "　　■　　　　　　　　■■　■■　　　　■■■■■■■■■■■■■■■"; SetColor(9, 15); cout << "□" << endl;	// 11
		cout << "■"; SetColor(0, 15); cout << "　　■　　　　　　　　■■　■■　　　　■■■■■■■■■■■■■■■"; SetColor(9, 15); cout << "■" << endl;	// 12
		cout << "■"; SetColor(0, 15); cout << "　　■　　　　　　　　■■　■■　　　　■■■■■■■■■■■■■■■"; SetColor(9, 15); cout << "■" << endl;	// 13
		cout << "■"; SetColor(0, 15); cout << "　　■　　　　　　　　■■　■■　　　　　■■■■■■■■■■■■■■"; SetColor(9, 15); cout << "■" << endl;	// 14
		cout << "□"; SetColor(0, 15); cout << "　　■　　　　　　　　■■　■■　　　　　　■■■■■■■■■■■■■"; SetColor(9, 15); cout << "□" << endl;	// 15
		cout << "□"; SetColor(0, 15); cout << "　■■■■■■■■■■■■■■■■　　　　　　■■■■■■■■■■■■"; SetColor(9, 15); cout << "□" << endl;	// 16
		cout << "□　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　□" << endl;	// 17
		cout << "■"; SetColor(0, 15); cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　□□□　"; SetColor(9, 15); cout << "■" << endl;	// 18
		cout << "■"; SetColor(0, 15); cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　□□□　"; SetColor(9, 15); cout << "■" << endl;	// 19
		cout << "■"; SetColor(0, 15); cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　□□□　"; SetColor(9, 15); cout << "■" << endl;	// 20
		cout << "□　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　□" << endl;	// 21
		cout << "□"; SetColor(0, 15); cout << "　　　　　　　　　　　　　　　　　　　　　　　■■■■■■■■■■■■"; SetColor(9, 15); cout << "□" << endl;	// 22
		cout << "□"; SetColor(0, 15); cout << "　　　　　■■■■■■■■■　　　　　　　　■■■■■■■■■■■■■"; SetColor(9, 15); cout << "□" << endl;	// 23
		cout << "■"; SetColor(0, 15); cout << "　　　　■　　　　　　　■　■　　　　　　■■■■■■■■■■■■■■"; SetColor(9, 15); cout << "■" << endl;	// 24
		cout << "■"; SetColor(0, 15); cout << "　　　■　　　　　　　■　　　■　　　　　■■■■■■■■■■■■■■"; SetColor(9, 15); cout << "■" << endl;	// 25
		cout << "■"; SetColor(0, 15); cout << "　　■　　　　　　　■　　　　　■　　　　■■■■■■■■■■■■■■"; SetColor(9, 15); cout << "■" << endl;	// 26
		cout << "□"; SetColor(0, 15); cout << "　■■■■■■■■■■■■■■■■　　　　■■■■■■■■■■■■■■"; SetColor(9, 15); cout << "□" << endl;	// 27
		cout << "□"; SetColor(0, 15); cout << "　　■　　　　　　　　■■　■■　　　　　■■■■■■■■■■■■■■"; SetColor(9, 15); cout << "□" << endl;	// 28
		cout << "□"; SetColor(0, 15); cout << "　　■　　　　　　　　■■　■■　　　　　■■■■■■■■■■■■■■"; SetColor(9, 15); cout << "□" << endl;	// 29
		cout << "■"; SetColor(0, 15); cout << "　　■　　　　　　　　■■　■■　"; SetColor(14, 15); cout << "　■　"; SetColor(0, 15); cout << "　■■■■■■■■■■■■■■"; SetColor(9, 15); cout << "■" << endl;	// 30
		cout << "■"; SetColor(0, 15); cout << "　　■　　　　　　　　■■　■■　"; SetColor(14, 15); cout << "■■■"; SetColor(0, 15); cout << "　　■■■■■■■■■■■■■"; SetColor(9, 15); cout << "■" << endl;	// 31
		cout << "■"; SetColor(0, 15); cout << "　　■　　　　　　　　■■　■■　"; SetColor(14, 15); cout << "　■　"; SetColor(0, 15); cout << "　　■■■■■■■■■■■■■"; SetColor(9, 15); cout << "■" << endl;	// 32
		cout << "□"; SetColor(0, 15); cout << "　■■■■■■■■■■■■■■■■"; SetColor(14, 15); cout << "■　■"; SetColor(0, 15); cout << "　　　■■■■■■■■■■■■"; SetColor(9, 15); cout << "□" << endl;	// 33
		cout << "□"; SetColor(0, 15); cout << "　　　　　　　　　　　　　　　　　　　　　　　　■■■■■■■■■■■"; SetColor(9, 15); cout << "□" << endl;	// 34
		cout << "□"; SetColor(0, 15); cout << "　　　　　　　　　　　　　　　　　　　　　　　　　■■■■■■■■■■"; SetColor(9, 15); cout << "□" << endl;	// 35
		cout << "■"; SetColor(0, 15); cout << "　　　　　　　　　　　　　　　　　　　　　　　　　■■■■■■■■■■"; SetColor(9, 15); cout << "■" << endl;	// 36
		cout << "■■□□□■■■□□□■■■□□□■■■□□□■■■□□□■■■□□□■■" << endl;	// 37

	}
}

void mainGame::TempleChoice()
{
	_key = '0';
	_key = _getch();

	if (_key == (char)LEFT)
	{
		if (_templecheck == 2 || _templecheck == 3 || _templecheck == 5)
		{
			_templecheck = 4;
			TempleScreen();
			TempleChoice();
		}
		else if (_templecheck == 4)
		{
			_templecheck = 5;
			TempleScreen();
			TempleChoice();
		}
		else
		{
			TempleChoice();
		}
	}
	else if (_key == (char)RIGHT)
	{
		if (_templecheck == 4 || _templecheck == 5)
		{
			if (_tempPlace == 1)
			{
				_templecheck = 2;
				TempleScreen();
				TempleChoice();
			}
			else if (_tempPlace == 2)
			{
				_templecheck = 3;
				TempleScreen();
				TempleChoice();
			}
			else
			{
				TempleChoice();
			}
		}
		else
		{
			TempleChoice();
		}
	}
	else if (_key == (char)UP)
	{
		if (_templecheck == 2 || _templecheck == 3 || _templecheck == 5)
		{
			_templecheck = 4;
			TempleScreen();
			TempleChoice();
		}
		else
		{
			TempleChoice();
		}
	}
	else if (_key == (char)DOWN)
	{
		if (_templecheck == 2 || _templecheck == 3 || _templecheck == 4)
		{
			_templecheck = 5;
			TempleScreen();
			TempleChoice();
		}
		else
		{
			TempleChoice();
		}
	}
	else if (_key == (char)ENTER || _key == (char)SPACE)
	{
		if (_templecheck == 2)
		{
			_key = '0';
			_templecheck = 1;
			_effect = EtempleEnter; // effectsound on
			TempleScreen();
			Sleep(1000);
			b_templeMusic = false; // mainmusic  off
			Sleep(1000);
			Move();
			_tempPlace = 0;
			_templecheck = 0;

			HomeEmptyScreen();
			b_homeMusic = true;
			_effect = EtempleEnter;
			Sleep(1500);
			Home();
		}
		else if (_templecheck == 3)
		{
			_templecheck = 1;
			_effect = EtempleEnter; // effectsound on
			TempleScreen();
			Sleep(1000);
			b_templeMusic = false; // mainmusic  off
			Sleep(1000);
			Move();
			_tempPlace = 0;
			_templecheck = 0;

			_village2check = 9;
			b_villageMusic = true;
			_effect = EtempleEnter;
			Village2Screen();
			Sleep(1000);
			_village2check = 5;
			Village2Screen();
			Village2Choice();
		}
		else if (_templecheck == 4)
		{
			_key = '0';
			_templecheck = 0;
			b_seoScreen = true;
			_seocheck = 1;
			SeoChoice();
		}
		else if (_templecheck == 5)
		{
			_key = '0';
			_templecheck = 0;
			b_khanScreen = true;
			_khancheck = 1;
			KhanChoice();
		}
		else
		{
			TempleChoice();
		}
	}
	else if (_key == (char)ESC)
	{
		_statuscheck = 1;
		Status();
	}
	else
	{
		TempleChoice();
	}
}
void mainGame::SeoChoice()
{
	_key = '0';
	_key = _getch();

	if (_key == (char)LEFT)
	{
		if (_seocheck == 1)
		{
			_seocheck = 2;
			SeoChoice();
		}
		else
		{
			SeoChoice();
		}
	}
	else if (_key == (char)RIGHT)
	{
		if (_seocheck == 2)
		{
			_seocheck = 1;
			SeoChoice();
		}
		else
		{
			SeoChoice();
		}
	}
	else if (_key == (char)UP)
	{
		if (_seocheck == 4)
		{
			_seocheck = 3;
			SeoChoice();
		}
		else if (_seocheck == 6)
		{
			_seocheck = 5;
			SeoChoice();
		}
		else
		{
			SeoChoice();
		}
	}
	else if (_key == (char)DOWN)
	{
		if (_seocheck == 3)
		{
			_seocheck = 4;
			SeoChoice();
		}
		else if (_seocheck == 5)
		{
			_seocheck = 6;
			SeoChoice();
		}
		else
		{
			SeoChoice();
		}
	}
	else if (_key == (char)ENTER || _key == (char)SPACE)
	{
		switch (_seocheck)
		{
		case 1:
		{
			b_seoScreen = false;
			Sleep(850);
			_seocheck = 0;
			_templecheck = 4;
			TempleScreen();
			TempleChoice();
		}
		break;
		case 2:
		{
			_effect = Econversation;
			_seocheck = 3;
			SeoChoice();
		}
		break;
		case 3:
		{
			_effect = Econversation;
			_seocheck = 5;
			SeoChoice();
		}
		break;
		case 4:
		{
			_effect = Econversation;
			_seocheck = 8;
			SeoChoice();
		}
		break;
		case 5:
		{
			if (_characterExp >= 10000)
			{
				_characterExp = _characterExp - 10000;
				_characterMaxHp = _characterMaxHp + 500;

				_effect = Econversation;
				_seocheck = 7;
				SeoChoice();
			}
			else
			{
				_effect = Econversation;
				_seocheck = 9;
				SeoChoice();
			}
		}
		break;
		case 6:
		case 7:
		case 8:
		case 9:
		{
			_seocheck = 2;
			SeoChoice();
		}
		break;
		default:
		{
			SeoChoice();
		}
		break;
		}
	}
	else if (_key == (char)ESC)
	{
		b_seoScreen = false;
		Sleep(1000);

		_statuscheck = 1;
		Status();
	}
	else
	{
		SeoChoice();
	}
}


void mainGame::SeoScreen()
{
	for (int i = 0; i >= 0; i++)
	{
		if (b_seoScreen == false)
		{
			break;
		}

		gotoxy(0, 0);
		SetColor(9, 15);
		if (_seocheck == 1)
		{
			cout << "■■□□□■■■□□□■■■□□□■■■□□□■■■□□□■■■□□□■■" << endl;	// 1
			cout << "■"; SetColor(0, 15); cout << "■■■■■■　　　　　■■■■■■■■■■■■■■■■■■■■■■■■"; SetColor(9, 15); cout << "■" << endl;	// 2
			cout << "□"; SetColor(0, 15); cout << "■■■■■■■　　　■■■■■■■■■■■■■　　　■■■　　　　　■"; SetColor(9, 15); cout << "□" << endl;	// 3
			cout << "□"; SetColor(0, 15); cout << "■■　　　■　■■■　■■■■■■■■■■■　　　　　■■　신들의　■"; SetColor(9, 15); cout << "□" << endl;	// 4
			cout << "□"; SetColor(0, 15); cout << "■　　　　■　　　　　■■■■■■■■■■■　　　　　■■　　　　　■"; SetColor(9, 15); cout << "□" << endl;	// 5
			cout << "■"; SetColor(0, 15); cout << "　　　　　■　　　　　■■■■■■■■■■■■　　　■■■　세　계　■"; SetColor(9, 15); cout << "■" << endl;	// 6
			cout << "■"; SetColor(0, 15); cout << "　　　　　■　　　　　■■■■■■■■■■■　■■■　■■　　　　　■"; SetColor(9, 15); cout << "■" << endl;	// 7
			cout << "■"; SetColor(0, 15); cout << "　　　　　■　　　　　■■■■■■■■■■■　　　　　■■■■■■■■"; SetColor(9, 15); cout << "■" << endl;	// 8
			cout << "□"; SetColor(0, 15); cout << "　　　　　■　　　　　■　　■■■■■■■■　　　　　■■■■■■■■"; SetColor(9, 15); cout << "□" << endl;	// 9
			cout << "□"; SetColor(0, 15); cout << "　　　　　■　　　　　■　　　　■■■■■■　　　　　■■■■■■■■"; SetColor(9, 15); cout << "□" << endl;	// 10

			Seo2ndScreen();
			Seo3rdScreen();
		}
		else if (_seocheck > 1)
		{
			gotoxy(0, 0);
			SetColor(9, 15);

			cout << "■■□□□■■■□□□■■■□□□■■■□□□■■■□□□■■■□□□■■" << endl;	// 1
			cout << "■"; SetColor(0, 15); cout << "■■■■■■　　　　　■■■■■■■■■■■■■■■■■■■■■■■■"; SetColor(9, 15); cout << "■" << endl;	// 2
			cout << "□"; SetColor(0, 15); cout << "■■■■■■■　　　■■■■■■■■■■■■■　　　■■■　　　　　■"; SetColor(9, 15); cout << "□" << endl;	// 3
			cout << "□"; SetColor(0, 15); cout << "■■　　　■　■■■　■■■■■■■■■■■　　　　　■■　　　　　■"; SetColor(9, 15); cout << "□" << endl;	// 4
			cout << "□"; SetColor(0, 15); cout << "■　　　　■　　　　　■■■■■■■■■■■　　　　　■■　세　오　■"; SetColor(9, 15); cout << "□" << endl;	// 5
			cout << "■"; SetColor(0, 15); cout << "　　　　　■　　　　　■■■■■■■■■■■■　　　■■■　　　　　■"; SetColor(9, 15); cout << "■" << endl;	// 6
			cout << "■"; SetColor(0, 15); cout << "　　　　　■　　　　　■■■■■■■■■■■　■■■　■■　　　　　■"; SetColor(9, 15); cout << "■" << endl;	// 7
			cout << "■"; SetColor(0, 15); cout << "　　　　　■　　　　　■■■■■■■■■■■　　　　　■■■■■■■■"; SetColor(9, 15); cout << "■" << endl;	// 8
			cout << "□"; SetColor(0, 15); cout << "　　　　　■　　　　　■　　■■■■■■■■　　　　　■■■■■■■■"; SetColor(9, 15); cout << "□" << endl;	// 9
			cout << "□"; SetColor(0, 15); cout << "　　　　　■　　　　　■　　　　■■■■■■　　　　　■■■■■■■■"; SetColor(9, 15); cout << "□" << endl;	// 10

			Seo2ndScreen();
			Seo3rdScreen();
		}
		std::this_thread::sleep_for(std::chrono::milliseconds(800));
	}
}
void mainGame::Seo2ndScreen()
{
	if (seo == 0)
	{
		SetColor(9, 15);

		cout << "□"; SetColor(0, 15); cout << "　　　　　■　　　　　■　　　　　　■■■■　　　　　■■■■■■■■"; SetColor(9, 15); cout << "□" << endl;	// 11
		cout << "■"; SetColor(0, 15); cout << "　　　　　■　"; SetColor(12, 15); cout << "□"; SetColor(0, 15); cout << "　　　■　　　　　　　　■■　　　　　■■■■■■■■"; SetColor(9, 15); cout << "■" << endl;	// 12
		cout << "■"; SetColor(0, 15); cout << "　　　　　■"; SetColor(12, 15); cout << "□□□"; SetColor(0, 15); cout << "　　■　　　　　　　　　■　　　　　■■■■■■■■"; SetColor(9, 15); cout << "■" << endl;	// 13
		cout << "■"; SetColor(0, 15); cout << "　　　　　　■"; SetColor(12, 15); cout << "□"; SetColor(0, 15); cout << "　　■　　　　　　　　　　■　　　　　■■■■■■■■"; SetColor(9, 15); cout << "■" << endl;	// 14
		cout << "□"; SetColor(0, 15); cout << "　　　　　　"; SetColor(12, 15); cout << "□□□"; SetColor(0, 15); cout << "■　　　　　　　　　　　■　　　　　■■■■■■■■"; SetColor(9, 15); cout << "□" << endl;	// 15
		cout << "□"; SetColor(0, 15); cout << "　　　　　"; SetColor(12, 15); cout << "□　□　□"; SetColor(0, 15); cout << "　　　　　　　　　　　■　　　　　■■■■■■■■"; SetColor(9, 15); cout << "□" << endl;	// 16
		cout << "□"; SetColor(0, 15); cout << "　　　　　"; SetColor(12, 15); cout << "□　□　□　　　　"; SetColor(12, 15); cout << "■　■"; SetColor(0, 15); cout << "　　　　■　　　　　■　　■■■■■"; SetColor(9, 15); cout << "□" << endl;	// 17
		cout << "■"; SetColor(0, 15); cout << "　　　　　　　"; SetColor(12, 15); cout << "□　　　　　　"; SetColor(12, 15); cout << "■■■"; SetColor(0, 15); cout << "　　　　　■　　　■　　　　　■■■"; SetColor(9, 15); cout << "■" << endl;	// 18
		cout << "■"; SetColor(0, 15); cout << "　　　　　　"; SetColor(12, 15); cout << "□　□"; SetColor(0, 15); cout << "　　　　■"; SetColor(12, 15); cout << "■■■"; SetColor(0, 15); cout << "■　　　　　■■■　　　　　　　　■"; SetColor(9, 15); cout << "■" << endl;	// 19
		cout << "■"; SetColor(0, 15); cout << "　　　　　　"; SetColor(12, 15); cout << "□　□"; SetColor(0, 15); cout << "　　　　■"; SetColor(12, 15); cout << "■■■"; SetColor(0, 15); cout << "■　　　　　　　　　　　　　　　　　"; SetColor(9, 15); cout << "■" << endl;	// 20
		cout << "□"; SetColor(0, 15); cout << "　　　　　　"; SetColor(12, 15); cout << "□　□"; SetColor(0, 15); cout << "　　　　■■■■■　　　　　　　　　　　　　　　　　"; SetColor(9, 15); cout << "□" << endl;	// 21
		cout << "□"; SetColor(0, 15); cout << "　　　　　　　　　　　　　■　　　■　　　　　　　　　　　　　　　　　"; SetColor(9, 15); cout << "□" << endl;	// 22
		cout << "□"; SetColor(0, 15); cout << "　　　　　　　　　　　　　　■■■　　　　　　　　　　　　　　　　　　"; SetColor(9, 15); cout << "□" << endl;	// 23

		seo = 1;
	}
	else if (seo == 1)
	{
		SetColor(9, 15);

		cout << "□"; SetColor(0, 15); cout << "　　　　　■　　　　　■　　　　　　■■■■　　　　　■■■■■■■■"; SetColor(9, 15); cout << "□" << endl;	// 11
		cout << "■"; SetColor(0, 15); cout << "　　　　　■　"; SetColor(12, 15); cout << "■"; SetColor(0, 15); cout << "　　　■　　　　　　　　■■　　　　　■■■■■■■■"; SetColor(9, 15); cout << "■" << endl;	// 12
		cout << "■"; SetColor(0, 15); cout << "　　　　　■"; SetColor(12, 15); cout << "■■■"; SetColor(0, 15); cout << "　　■　　　　　　　　　■　　　　　■■■■■■■■"; SetColor(9, 15); cout << "■" << endl;	// 13
		cout << "■"; SetColor(0, 15); cout << "　　　　　　■"; SetColor(12, 15); cout << "■"; SetColor(0, 15); cout << "　　■　　　　　　　　　　■　　　　　■■■■■■■■"; SetColor(9, 15); cout << "■" << endl;	// 14
		cout << "□"; SetColor(0, 15); cout << "　　　　　　"; SetColor(12, 15); cout << "■■■"; SetColor(0, 15); cout << "■　　　　　　　　　　　■　　　　　■■■■■■■■"; SetColor(9, 15); cout << "□" << endl;	// 15
		cout << "□"; SetColor(0, 15); cout << "　　　　　"; SetColor(12, 15); cout << "■　■　■"; SetColor(0, 15); cout << "　　　　　　　　　　　■　　　　　■■■■■■■■"; SetColor(9, 15); cout << "□" << endl;	// 16
		cout << "□"; SetColor(0, 15); cout << "　　　　　"; SetColor(12, 15); cout << "■　■　■　　　　"; SetColor(12, 15); cout << "　■　"; SetColor(0, 15); cout << "　　　　■　　　　　■　　■■■■■"; SetColor(9, 15); cout << "□" << endl;	// 17
		cout << "■"; SetColor(0, 15); cout << "　　　　　　　"; SetColor(12, 15); cout << "■　　　　　　"; SetColor(12, 15); cout << "■■■"; SetColor(0, 15); cout << "　　　　　■　　　■　　　　　■■■"; SetColor(9, 15); cout << "■" << endl;	// 18
		cout << "■"; SetColor(0, 15); cout << "　　　　　　"; SetColor(12, 15); cout << "■　■"; SetColor(0, 15); cout << "　　　　■"; SetColor(12, 15); cout << "■■■"; SetColor(0, 15); cout << "■　　　　　■■■　　　　　　　　■"; SetColor(9, 15); cout << "■" << endl;	// 19
		cout << "■"; SetColor(0, 15); cout << "　　　　　　"; SetColor(12, 15); cout << "■　■"; SetColor(0, 15); cout << "　　　　■"; SetColor(12, 15); cout << "■■■"; SetColor(0, 15); cout << "■　　　　　　　　　　　　　　　　　"; SetColor(9, 15); cout << "■" << endl;	// 20
		cout << "□"; SetColor(0, 15); cout << "　　　　　　"; SetColor(12, 15); cout << "■　■"; SetColor(0, 15); cout << "　　　　■■■■■　　　　　　　　　　　　　　　　　"; SetColor(9, 15); cout << "□" << endl;	// 21
		cout << "□"; SetColor(0, 15); cout << "　　　　　　　　　　　　　■　　　■　　　　　　　　　　　　　　　　　"; SetColor(9, 15); cout << "□" << endl;	// 22
		cout << "□"; SetColor(0, 15); cout << "　　　　　　　　　　　　　　■■■　　　　　　　　　　　　　　　　　　"; SetColor(9, 15); cout << "□" << endl;	// 23

		seo = 0;
	}
}

void mainGame::Seo3rdScreen()
{
	if (_seocheck == 1)
	{
		SetColor(9, 15);

		cout << "■"; SetColor(0, 15); cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　"; SetColor(9, 15); cout << "■" << endl;	// 24
		cout << "■"; SetColor(0, 15); cout << "　　　　　　　　　　　■■■　　　　　　　　　　　　　　　　　　　　　"; SetColor(9, 15); cout << "■" << endl;	// 25
		cout << "■"; SetColor(0, 15); cout << "　　　　　　　　　　■　　　■　　　　　　　　　　　　　　　　　　　　"; SetColor(9, 15); cout << "■" << endl;	// 26
		cout << "□"; SetColor(0, 15); cout << "　　　　　　　　　■　　　　　■　　　　　　　　　　　　"; SetColor(14, 15); cout << "　■　　　　　"; SetColor(9, 15); cout << "□" << endl;	// 27
		cout << "□"; SetColor(0, 15); cout << "　　　　　　　　　■　　　　　■　　　　　　　　　　　　"; SetColor(14, 15); cout << "■■■　　　　"; SetColor(9, 15); cout << "□" << endl;	// 28
		cout << "□"; SetColor(0, 15); cout << "　　　　　　　　　■■　　　■■　　　　　　　　　　　　"; SetColor(14, 15); cout << "　■　　　　　"; SetColor(9, 15); cout << "□" << endl;	// 29
		cout << "■"; SetColor(0, 15); cout << "　　　　　　　　　■　■■■　■　　　　　　　　　　　　"; SetColor(14, 15); cout << "■　■　　　　"; SetColor(9, 15); cout << "■" << endl;	// 30
		cout << "■"; SetColor(0, 15); cout << "　　　　　　　　　■　　　　　■　　　　　　　　　　　　　　　　　　　"; SetColor(9, 15); cout << "■" << endl;	// 31
		cout << "■"; SetColor(0, 15); cout << "　　　　　　　　　■　　　　　■　　　　　　　　　　　　　　　　　　　"; SetColor(9, 15); cout << "■" << endl;	// 32
		cout << "□"; SetColor(0, 15); cout << "　　　　　　　　　■　　　　　■　　　　　　　　　　　　　　　　　　　"; SetColor(9, 15); cout << "□" << endl;	// 33
		cout << "□"; SetColor(0, 15); cout << "　　　　　　　　　■　　　　　■　　　　　　　　　　　　　　　　　　　"; SetColor(9, 15); cout << "□" << endl;	// 34
		cout << "□"; SetColor(0, 15); cout << "　　　　　　　　　■　　　　　■　　　　　　　　　　　　　　　　　　　"; SetColor(9, 15); cout << "□" << endl;	// 35
		cout << "■"; SetColor(0, 15); cout << "　　　　　　　　　■　　　　　■　　　　　　　　　　　　　　　　　　　"; SetColor(9, 15); cout << "■" << endl;	// 36
		cout << "■■□□□■■■□□□■■■□□□■■■□□□■■■□□□■■■□□□■■" << endl;	// 37	
	}
	else if (_seocheck == 2)
	{
		SetColor(9, 15);

		cout << "■"; SetColor(0, 15); cout << "　　　　　　　　　　　　　　　　　　　　"; SetColor(14, 15); cout << "　■　"; SetColor(0, 15); cout << "　　　　　　　　　　　　"; SetColor(9, 15); cout << "■" << endl;	// 24
		cout << "■"; SetColor(0, 15); cout << "　　　　　　　　　　　■■■　　　　　　"; SetColor(14, 15); cout << "■■■"; SetColor(0, 15); cout << "　　　　　　　　　　　　"; SetColor(9, 15); cout << "■" << endl;	// 25
		cout << "■"; SetColor(0, 15); cout << "　　　　　　　　　　■　　　■　　　　　"; SetColor(14, 15); cout << "　■　"; SetColor(0, 15); cout << "　　　　　　　　　　　　"; SetColor(9, 15); cout << "■" << endl;	// 26
		cout << "□"; SetColor(0, 15); cout << "　　　　　　　　　■　　　　　■　　　　"; SetColor(14, 15); cout << "■　■"; SetColor(0, 15); cout << "　　　　　　　　　　　　"; SetColor(9, 15); cout << "□" << endl;	// 27
		cout << "□"; SetColor(0, 15); cout << "　　　　　　　　　■　　　　　■　　　　　　　　　　　　　　　　　　　"; SetColor(9, 15); cout << "□" << endl;	// 28
		cout << "□"; SetColor(0, 15); cout << "　　　　　　　　　■■　　　■■　　　　　　　　　　　　　　　　　　　"; SetColor(9, 15); cout << "□" << endl;	// 29
		cout << "■"; SetColor(0, 15); cout << "　　　　　　　　　■　■■■　■　　　　　　　　　　　　　　　　　　　"; SetColor(9, 15); cout << "■" << endl;	// 30
		cout << "■"; SetColor(0, 15); cout << "　　　　　　　　　■　　　　　■　　　　　　　　　　　　　　　　　　　"; SetColor(9, 15); cout << "■" << endl;	// 31
		cout << "■"; SetColor(0, 15); cout << "　　　　　　　　　■　　　　　■　　　　　　　　　　　　　　　　　　　"; SetColor(9, 15); cout << "■" << endl;	// 32
		cout << "□"; SetColor(0, 15); cout << "　　　　　　　　　■　　　　　■　　　　　　　　　　　　　　　　　　　"; SetColor(9, 15); cout << "□" << endl;	// 33
		cout << "□"; SetColor(0, 15); cout << "　　　　　　　　　■　　　　　■　　　　　　　　　　　　　　　　　　　"; SetColor(9, 15); cout << "□" << endl;	// 34
		cout << "□"; SetColor(0, 15); cout << "　　　　　　　　　■　　　　　■　　　　　　　　　　　　　　　　　　　"; SetColor(9, 15); cout << "□" << endl;	// 35
		cout << "■"; SetColor(0, 15); cout << "　　　　　　　　　■　　　　　■　　　　　　　　　　　　　　　　　　　"; SetColor(9, 15); cout << "■" << endl;	// 36
		cout << "■■□□□■■■□□□■■■□□□■■■□□□■■■□□□■■■□□□■■" << endl;	// 37
	}
	else if (_seocheck == 3)
	{
		SetColor(9, 15);

		cout << "■"; SetColor(0, 15); cout << "　　　　　　　　　　　　　　　　　　　　"; SetColor(14, 15); cout << "　■　"; SetColor(0, 15); cout << "　　　　　　　　　　　　"; SetColor(9, 15); cout << "■" << endl;	// 24
		cout << "■"; SetColor(0, 15); cout << "　　　　　　　　　　　■■■　　　　　　"; SetColor(14, 15); cout << "■■■"; SetColor(0, 15); cout << "　　　　　　　　　　　　"; SetColor(9, 15); cout << "■" << endl;	// 25
		cout << "■"; SetColor(0, 15); cout << "　　　　　　　　　　■　　　■　　　　　"; SetColor(14, 15); cout << "　■　"; SetColor(0, 15); cout << "　　　　　　　　　　　　"; SetColor(9, 15); cout << "■" << endl;	// 26

		SetColor(13, 15);

		cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;
		cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
		cout << "■"; SetColor(0, 15); cout << "　　[세오]"; SetColor(13, 15); cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
		cout << "■"; SetColor(0, 15); cout << "　　나의 아이야, 무슨일로 나를 찾아온 것이냐"; SetColor(13, 15); cout << "　　　　　　　　　　　　　■" << endl;
		cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
		cout << "■"; SetColor(0, 15); cout << "　　▶　신의 은총을 바랍니다."; SetColor(13, 15); cout << " 　　　　　　　　　　　　　　　　　　　　■" << endl;
		cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
		cout << "■"; SetColor(0, 15); cout << "　　　　그냥 신을 뵙고 싶어 왔습니다."; SetColor(13, 15); cout << " 　　　　　　　　　　　　　　　　■" << endl;
		cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
		cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
		cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;
	}
	else if (_seocheck == 4)
	{
		SetColor(9, 15);

		cout << "■"; SetColor(0, 15); cout << "　　　　　　　　　　　　　　　　　　　　"; SetColor(14, 15); cout << "　■　"; SetColor(0, 15); cout << "　　　　　　　　　　　　"; SetColor(9, 15); cout << "■" << endl;	// 24
		cout << "■"; SetColor(0, 15); cout << "　　　　　　　　　　　■■■　　　　　　"; SetColor(14, 15); cout << "■■■"; SetColor(0, 15); cout << "　　　　　　　　　　　　"; SetColor(9, 15); cout << "■" << endl;	// 25
		cout << "■"; SetColor(0, 15); cout << "　　　　　　　　　　■　　　■　　　　　"; SetColor(14, 15); cout << "　■　"; SetColor(0, 15); cout << "　　　　　　　　　　　　"; SetColor(9, 15); cout << "■" << endl;	// 26

		SetColor(13, 15);

		cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;
		cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
		cout << "■"; SetColor(0, 15); cout << "　　[세오]"; SetColor(13, 15); cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
		cout << "■"; SetColor(0, 15); cout << "　　나의 아이야, 무슨일로 나를 찾아온 것이냐"; SetColor(13, 15); cout << "　　　　　　　　　　　　　■" << endl;
		cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
		cout << "■"; SetColor(0, 15); cout << "　　　　신의 은총을 바랍니다."; SetColor(13, 15); cout << " 　　　　　　　　　　　　　　　　　　　　■" << endl;
		cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
		cout << "■"; SetColor(0, 15); cout << "　　▶　그냥 신을 뵙고 싶어 왔습니다."; SetColor(13, 15); cout << " 　　　　　　　　　　　　　　　　■" << endl;
		cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
		cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
		cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;

	}
	else if (_seocheck == 5)
	{
		SetColor(9, 15);

		cout << "■"; SetColor(0, 15); cout << "　　　　　　　　　　　　　　　　　　　　"; SetColor(14, 15); cout << "　■　"; SetColor(0, 15); cout << "　　　　　　　　　　　　"; SetColor(9, 15); cout << "■" << endl;	// 24
		cout << "■"; SetColor(0, 15); cout << "　　　　　　　　　　　■■■　　　　　　"; SetColor(14, 15); cout << "■■■"; SetColor(0, 15); cout << "　　　　　　　　　　　　"; SetColor(9, 15); cout << "■" << endl;	// 25
		cout << "■"; SetColor(0, 15); cout << "　　　　　　　　　　■　　　■　　　　　"; SetColor(14, 15); cout << "　■　"; SetColor(0, 15); cout << "　　　　　　　　　　　　"; SetColor(9, 15); cout << "■" << endl;	// 26

		SetColor(13, 15);

		cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;
		cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
		cout << "■"; SetColor(0, 15); cout << "　　[세오]"; SetColor(13, 15); cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
		cout << "■"; SetColor(0, 15); cout << "　　체력을 500 올리는데 경험치 10,000 이 필요하느니라"; SetColor(13, 15); cout << "　　 　　　　　　■" << endl;
		cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
		cout << "■"; SetColor(0, 15); cout << "　　▶　네"; SetColor(13, 15); cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
		cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
		cout << "■"; SetColor(0, 15); cout << "　　　　아니오"; SetColor(13, 15); cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
		cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
		cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
		cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;
	}
	else if (_seocheck == 6)
	{
		SetColor(9, 15);

		cout << "■"; SetColor(0, 15); cout << "　　　　　　　　　　　　　　　　　　　　"; SetColor(14, 15); cout << "　■　"; SetColor(0, 15); cout << "　　　　　　　　　　　　"; SetColor(9, 15); cout << "■" << endl;	// 24
		cout << "■"; SetColor(0, 15); cout << "　　　　　　　　　　　■■■　　　　　　"; SetColor(14, 15); cout << "■■■"; SetColor(0, 15); cout << "　　　　　　　　　　　　"; SetColor(9, 15); cout << "■" << endl;	// 25
		cout << "■"; SetColor(0, 15); cout << "　　　　　　　　　　■　　　■　　　　　"; SetColor(14, 15); cout << "　■　"; SetColor(0, 15); cout << "　　　　　　　　　　　　"; SetColor(9, 15); cout << "■" << endl;	// 26

		SetColor(13, 15);

		cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;
		cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
		cout << "■"; SetColor(0, 15); cout << "　　[세오]"; SetColor(13, 15); cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
		cout << "■"; SetColor(0, 15); cout << "　　체력을 500 올리는데 경험치 10,000 이 필요하느니라"; SetColor(13, 15); cout << "　　 　　　　　　■" << endl;
		cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
		cout << "■"; SetColor(0, 15); cout << "　　　　네"; SetColor(13, 15); cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
		cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
		cout << "■"; SetColor(0, 15); cout << "　　▶　아니오"; SetColor(13, 15); cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
		cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
		cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
		cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;
	}
	else if (_seocheck == 7)
	{
		SetColor(9, 15);

		cout << "■"; SetColor(0, 15); cout << "　　　　　　　　　　　　　　　　　　　　"; SetColor(14, 15); cout << "　■　"; SetColor(0, 15); cout << "　　　　　　　　　　　　"; SetColor(9, 15); cout << "■" << endl;	// 24
		cout << "■"; SetColor(0, 15); cout << "　　　　　　　　　　　■■■　　　　　　"; SetColor(14, 15); cout << "■■■"; SetColor(0, 15); cout << "　　　　　　　　　　　　"; SetColor(9, 15); cout << "■" << endl;	// 25
		cout << "■"; SetColor(0, 15); cout << "　　　　　　　　　　■　　　■　　　　　"; SetColor(14, 15); cout << "　■　"; SetColor(0, 15); cout << "　　　　　　　　　　　　"; SetColor(9, 15); cout << "■" << endl;	// 26

		SetColor(13, 15);

		cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;
		cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
		cout << "■"; SetColor(0, 15); cout << "　　[세오]"; SetColor(13, 15); cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
		cout << "■"; SetColor(0, 15); cout << "　　체력을 500 올려주었다. 수행에는 끝이 없는 법,　　　　　　　　　　 "; SetColor(13, 15); cout << "■" << endl;
		cout << "■"; SetColor(0, 15); cout << "　　가르침이 필요하다면 언제든지 오거라..　　　　　　　　　　 　　　　"; SetColor(13, 15); cout << "■" << endl;
		cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
		cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
		cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
		cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
		cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
		cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;

	}
	else if (_seocheck == 8)
	{
		SetColor(9, 15);

		cout << "■"; SetColor(0, 15); cout << "　　　　　　　　　　　　　　　　　　　　"; SetColor(14, 15); cout << "　■　"; SetColor(0, 15); cout << "　　　　　　　　　　　　"; SetColor(9, 15); cout << "■" << endl;	// 24
		cout << "■"; SetColor(0, 15); cout << "　　　　　　　　　　　■■■　　　　　　"; SetColor(14, 15); cout << "■■■"; SetColor(0, 15); cout << "　　　　　　　　　　　　"; SetColor(9, 15); cout << "■" << endl;	// 25
		cout << "■"; SetColor(0, 15); cout << "　　　　　　　　　　■　　　■　　　　　"; SetColor(14, 15); cout << "　■　"; SetColor(0, 15); cout << "　　　　　　　　　　　　"; SetColor(9, 15); cout << "■" << endl;	// 26

		SetColor(13, 15);

		cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;
		cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
		cout << "■"; SetColor(0, 15); cout << "　　[세오]"; SetColor(13, 15); cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
		cout << "■"; SetColor(0, 15); cout << "　　나를 그냥 보러 왔다는 말이냐 많이 한가한가보로구나"; SetColor(13, 15); cout << " 　　　　 　　　■" << endl;
		cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
		cout << "■"; SetColor(0, 15); cout << "　　둘러보다 가거느라.."; SetColor(13, 15); cout << " 　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
		cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
		cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
		cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
		cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
		cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;
	}
	else if (_seocheck == 9)
	{
		SetColor(9, 15);

		cout << "■"; SetColor(0, 15); cout << "　　　　　　　　　　　　　　　　　　　　"; SetColor(14, 15); cout << "　■　"; SetColor(0, 15); cout << "　　　　　　　　　　　　"; SetColor(9, 15); cout << "■" << endl;	// 24
		cout << "■"; SetColor(0, 15); cout << "　　　　　　　　　　　■■■　　　　　　"; SetColor(14, 15); cout << "■■■"; SetColor(0, 15); cout << "　　　　　　　　　　　　"; SetColor(9, 15); cout << "■" << endl;	// 25
		cout << "■"; SetColor(0, 15); cout << "　　　　　　　　　　■　　　■　　　　　"; SetColor(14, 15); cout << "　■　"; SetColor(0, 15); cout << "　　　　　　　　　　　　"; SetColor(9, 15); cout << "■" << endl;	// 26

		SetColor(13, 15);

		cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;
		cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
		cout << "■"; SetColor(0, 15); cout << "　　경험치가 부족합니다.."; SetColor(13, 15); cout << "　　　　　　　　　　　　　　　　　　　　　　 ■" << endl;
		cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
		cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
		cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
		cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
		cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
		cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
		cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
		cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;
	}
}


////////////////////////////////////////////////////////////////////////////////////////////
void mainGame::KhanChoice()
{
	_key = '0';
	_key = _getch();

	if (_key == (char)LEFT)
	{
		if (_khancheck == 1)
		{
			_khancheck = 2;
			KhanChoice();
		}
		else
		{
			KhanChoice();
		}
	}
	else if (_key == (char)RIGHT)
	{
		if (_khancheck == 2)
		{
			_khancheck = 1;
			KhanChoice();
		}
		else
		{
			KhanChoice();
		}
	}
	else if (_key == (char)UP)
	{
		if (_khancheck == 4)
		{
			_khancheck = 3;
			KhanChoice();
		}
		else if (_khancheck == 6)
		{
			_khancheck = 5;
			KhanChoice();
		}
		else
		{
			KhanChoice();
		}
	}
	else if (_key == (char)DOWN)
	{
		if (_khancheck == 3)
		{
			_khancheck = 4;
			KhanChoice();
		}
		else if (_khancheck == 5)
		{
			_khancheck = 6;
			KhanChoice();
		}
		else
		{
			KhanChoice();
		}
	}
	else if (_key == (char)ENTER || _key == (char)SPACE)
	{
		switch (_khancheck)
		{
		case 1:
		{
			b_khanScreen = false;
			Sleep(850);
			_khancheck = 0;
			_templecheck = 5;
			TempleScreen();
			TempleChoice();
		}
		break;
		case 2:
		{
			_effect = Econversation;
			_khancheck = 3;
			KhanChoice();
		}
		break;
		case 3:
		{
			_effect = Econversation;
			_khancheck = 5;
			KhanChoice();
		}
		break;
		case 4:
		{
			_effect = Econversation;
			_khancheck = 8;
			KhanChoice();
		}
		break;
		case 5:
		{
			if (_characterExp >= 10000)
			{
				_characterExp = _characterExp - 10000;
				_characterMaxMp = _characterMaxMp + 250;

				_effect = Econversation;
				_khancheck = 7;
				KhanChoice();
			}
			else
			{
				_effect = Econversation;
				_khancheck = 9;
				KhanChoice();
			}
		}
		break;
		case 6:
		case 7:
		case 8:
		case 9:
		{
			_khancheck = 2;
			KhanChoice();
		}
		break;
		default:
		{
			KhanChoice();
		}
		break;
		}
	}
	else if (_key == (char)ESC)
	{
		b_khanScreen = false;
		Sleep(1000);

		_statuscheck = 1;
		Status();
	}
	else
	{
		KhanChoice();
	}
}


void mainGame::KhanScreen()
{
	for (int i = 0; i >= 0; i++)
	{
		if (b_khanScreen == false)
		{
			break;
		}

		gotoxy(0, 0);
		SetColor(9, 15);
		if (_khancheck == 1)
		{
			cout << "■■□□□■■■□□□■■■□□□■■■□□□■■■□□□■■■□□□■■" << endl;	// 1
			cout << "■"; SetColor(0, 15); cout << "■■■■■■　　　　　■■■■■■■■■■■■■■■■■■■■■■■■"; SetColor(9, 15); cout << "■" << endl;	// 2
			cout << "□"; SetColor(0, 15); cout << "■■■■■■■　　　■■■■■■■■■■■■■　　　■■■　　　　　■"; SetColor(9, 15); cout << "□" << endl;	// 3
			cout << "□"; SetColor(0, 15); cout << "■■　　　■　■■■　■■■■■■■■■■■　　　　　■■　신들의　■"; SetColor(9, 15); cout << "□" << endl;	// 4
			cout << "□"; SetColor(0, 15); cout << "■　　　　■　　　　　■■■■■■■■■■■　　　　　■■　　　　　■"; SetColor(9, 15); cout << "□" << endl;	// 5
			cout << "■"; SetColor(0, 15); cout << "　　　　　■　　　　　■■■■■■■■■■■■　　　■■■　세　계　■"; SetColor(9, 15); cout << "■" << endl;	// 6
			cout << "■"; SetColor(0, 15); cout << "　　　　　■　　　　　■■■■■■■■■■■　■■■　■■　　　　　■"; SetColor(9, 15); cout << "■" << endl;	// 7
			cout << "■"; SetColor(0, 15); cout << "　　　　　■　　　　　■■■■■■■■■■■　　　　　■■■■■■■■"; SetColor(9, 15); cout << "■" << endl;	// 8
			cout << "□"; SetColor(0, 15); cout << "　　　　　■　　　　　■　　■■■■■■■■　　　　　■■■■■■■■"; SetColor(9, 15); cout << "□" << endl;	// 9
			cout << "□"; SetColor(0, 15); cout << "　　　　　■　　　　　■　　　　■■■■■■　　　　　■■■■■■■■"; SetColor(9, 15); cout << "□" << endl;	// 10

			Khan2ndScreen();
			Khan3rdScreen();
		}
		else if (_khancheck > 1)
		{
			gotoxy(0, 0);
			SetColor(9, 15);

			cout << "■■□□□■■■□□□■■■□□□■■■□□□■■■□□□■■■□□□■■" << endl;	// 1
			cout << "■"; SetColor(0, 15); cout << "■■■■■■　　　　　■■■■■■■■■■■■■■■■■■■■■■■■"; SetColor(9, 15); cout << "■" << endl;	// 2
			cout << "□"; SetColor(0, 15); cout << "■■■■■■■　　　■■■■■■■■■■■■■　　　■■■　　　　　■"; SetColor(9, 15); cout << "□" << endl;	// 3
			cout << "□"; SetColor(0, 15); cout << "■■　　　■　■■■　■■■■■■■■■■■　　　　　■■　　　　　■"; SetColor(9, 15); cout << "□" << endl;	// 4
			cout << "□"; SetColor(0, 15); cout << "■　　　　■　　　　　■■■■■■■■■■■　　　　　■■　　칸　　■"; SetColor(9, 15); cout << "□" << endl;	// 5
			cout << "■"; SetColor(0, 15); cout << "　　　　　■　　　　　■■■■■■■■■■■■　　　■■■　　　　　■"; SetColor(9, 15); cout << "■" << endl;	// 6
			cout << "■"; SetColor(0, 15); cout << "　　　　　■　　　　　■■■■■■■■■■■　■■■　■■　　　　　■"; SetColor(9, 15); cout << "■" << endl;	// 7
			cout << "■"; SetColor(0, 15); cout << "　　　　　■　　　　　■■■■■■■■■■■　　　　　■■■■■■■■"; SetColor(9, 15); cout << "■" << endl;	// 8
			cout << "□"; SetColor(0, 15); cout << "　　　　　■　　　　　■　　■■■■■■■■　　　　　■■■■■■■■"; SetColor(9, 15); cout << "□" << endl;	// 9
			cout << "□"; SetColor(0, 15); cout << "　　　　　■　　　　　■　　　　■■■■■■　　　　　■■■■■■■■"; SetColor(9, 15); cout << "□" << endl;	// 10

			Khan2ndScreen();
			Khan3rdScreen();
		}
		std::this_thread::sleep_for(std::chrono::milliseconds(800));
	}
}
void mainGame::Khan2ndScreen()
{
	if (khan == 0)
	{
		SetColor(9, 15);

		cout << "□"; SetColor(0, 15); cout << "　　　　　■　　　　　■　　　　　　■■■■　　　　　■■■■■■■■"; SetColor(9, 15); cout << "□" << endl;	// 11
		cout << "■"; SetColor(0, 15); cout << "　　　　　■　"; SetColor(11, 15); cout << "□"; SetColor(0, 15); cout << "　　　■　　　　　　　　■■　　　　　■■■■■■■■"; SetColor(9, 15); cout << "■" << endl;	// 12
		cout << "■"; SetColor(0, 15); cout << "　　　　　■"; SetColor(11, 15); cout << "□□□"; SetColor(0, 15); cout << "　　■　　　　　　　　　■　　　　　■■■■■■■■"; SetColor(9, 15); cout << "■" << endl;	// 13
		cout << "■"; SetColor(0, 15); cout << "　　　　　　■"; SetColor(11, 15); cout << "□"; SetColor(0, 15); cout << "　　■　　　　　　　　　　■　　　　　■■■■■■■■"; SetColor(9, 15); cout << "■" << endl;	// 14
		cout << "□"; SetColor(0, 15); cout << "　　　　　　"; SetColor(11, 15); cout << "□□□"; SetColor(0, 15); cout << "■　　　　　　　　　　　■　　　　　■■■■■■■■"; SetColor(9, 15); cout << "□" << endl;	// 15
		cout << "□"; SetColor(0, 15); cout << "　　　　　"; SetColor(11, 15); cout << "□　□　□"; SetColor(0, 15); cout << "　　　　　　　　　　　■　　　　　■■■■■■■■"; SetColor(9, 15); cout << "□" << endl;	// 16
		cout << "□"; SetColor(0, 15); cout << "　　　　　"; SetColor(11, 15); cout << "□　□　□　　　　"; SetColor(11, 15); cout << "■　■"; SetColor(0, 15); cout << "　　　　■　　　　　■　　■■■■■"; SetColor(9, 15); cout << "□" << endl;	// 17
		cout << "■"; SetColor(0, 15); cout << "　　　　　　　"; SetColor(11, 15); cout << "□　　　　　　"; SetColor(11, 15); cout << "■■■"; SetColor(0, 15); cout << "　　　　　■　　　■　　　　　■■■"; SetColor(9, 15); cout << "■" << endl;	// 18
		cout << "■"; SetColor(0, 15); cout << "　　　　　　"; SetColor(11, 15); cout << "□　□"; SetColor(0, 15); cout << "　　　　■"; SetColor(11, 15); cout << "■■■"; SetColor(0, 15); cout << "■　　　　　■■■　　　　　　　　■"; SetColor(9, 15); cout << "■" << endl;	// 19
		cout << "■"; SetColor(0, 15); cout << "　　　　　　"; SetColor(11, 15); cout << "□　□"; SetColor(0, 15); cout << "　　　　■"; SetColor(11, 15); cout << "■■■"; SetColor(0, 15); cout << "■　　　　　　　　　　　　　　　　　"; SetColor(9, 15); cout << "■" << endl;	// 20
		cout << "□"; SetColor(0, 15); cout << "　　　　　　"; SetColor(11, 15); cout << "□　□"; SetColor(0, 15); cout << "　　　　■■■■■　　　　　　　　　　　　　　　　　"; SetColor(9, 15); cout << "□" << endl;	// 21
		cout << "□"; SetColor(0, 15); cout << "　　　　　　　　　　　　　■　　　■　　　　　　　　　　　　　　　　　"; SetColor(9, 15); cout << "□" << endl;	// 22
		cout << "□"; SetColor(0, 15); cout << "　　　　　　　　　　　　　　■■■　　　　　　　　　　　　　　　　　　"; SetColor(9, 15); cout << "□" << endl;	// 23

		khan = 1;
	}
	else if (khan == 1)
	{
		SetColor(9, 15);

		cout << "□"; SetColor(0, 15); cout << "　　　　　■　　　　　■　　　　　　■■■■　　　　　■■■■■■■■"; SetColor(9, 15); cout << "□" << endl;	// 11
		cout << "■"; SetColor(0, 15); cout << "　　　　　■　"; SetColor(11, 15); cout << "■"; SetColor(0, 15); cout << "　　　■　　　　　　　　■■　　　　　■■■■■■■■"; SetColor(9, 15); cout << "■" << endl;	// 12
		cout << "■"; SetColor(0, 15); cout << "　　　　　■"; SetColor(11, 15); cout << "■■■"; SetColor(0, 15); cout << "　　■　　　　　　　　　■　　　　　■■■■■■■■"; SetColor(9, 15); cout << "■" << endl;	// 13
		cout << "■"; SetColor(0, 15); cout << "　　　　　　■"; SetColor(11, 15); cout << "■"; SetColor(0, 15); cout << "　　■　　　　　　　　　　■　　　　　■■■■■■■■"; SetColor(9, 15); cout << "■" << endl;	// 14
		cout << "□"; SetColor(0, 15); cout << "　　　　　　"; SetColor(11, 15); cout << "■■■"; SetColor(0, 15); cout << "■　　　　　　　　　　　■　　　　　■■■■■■■■"; SetColor(9, 15); cout << "□" << endl;	// 15
		cout << "□"; SetColor(0, 15); cout << "　　　　　"; SetColor(11, 15); cout << "■　■　■"; SetColor(0, 15); cout << "　　　　　　　　　　　■　　　　　■■■■■■■■"; SetColor(9, 15); cout << "□" << endl;	// 16
		cout << "□"; SetColor(0, 15); cout << "　　　　　"; SetColor(11, 15); cout << "■　■　■　　　　"; SetColor(11, 15); cout << "　■　"; SetColor(0, 15); cout << "　　　　■　　　　　■　　■■■■■"; SetColor(9, 15); cout << "□" << endl;	// 17
		cout << "■"; SetColor(0, 15); cout << "　　　　　　　"; SetColor(11, 15); cout << "■　　　　　　"; SetColor(11, 15); cout << "■■■"; SetColor(0, 15); cout << "　　　　　■　　　■　　　　　■■■"; SetColor(9, 15); cout << "■" << endl;	// 18
		cout << "■"; SetColor(0, 15); cout << "　　　　　　"; SetColor(11, 15); cout << "■　■"; SetColor(0, 15); cout << "　　　　■"; SetColor(11, 15); cout << "■■■"; SetColor(0, 15); cout << "■　　　　　■■■　　　　　　　　■"; SetColor(9, 15); cout << "■" << endl;	// 19
		cout << "■"; SetColor(0, 15); cout << "　　　　　　"; SetColor(11, 15); cout << "■　■"; SetColor(0, 15); cout << "　　　　■"; SetColor(11, 15); cout << "■■■"; SetColor(0, 15); cout << "■　　　　　　　　　　　　　　　　　"; SetColor(9, 15); cout << "■" << endl;	// 20
		cout << "□"; SetColor(0, 15); cout << "　　　　　　"; SetColor(11, 15); cout << "■　■"; SetColor(0, 15); cout << "　　　　■■■■■　　　　　　　　　　　　　　　　　"; SetColor(9, 15); cout << "□" << endl;	// 21
		cout << "□"; SetColor(0, 15); cout << "　　　　　　　　　　　　　■　　　■　　　　　　　　　　　　　　　　　"; SetColor(9, 15); cout << "□" << endl;	// 22
		cout << "□"; SetColor(0, 15); cout << "　　　　　　　　　　　　　　■■■　　　　　　　　　　　　　　　　　　"; SetColor(9, 15); cout << "□" << endl;	// 23

		khan = 0;
	}
}

void mainGame::Khan3rdScreen()
{
	if (_khancheck == 1)
	{
		SetColor(9, 15);

		cout << "■"; SetColor(0, 15); cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　"; SetColor(9, 15); cout << "■" << endl;	// 24
		cout << "■"; SetColor(0, 15); cout << "　　　　　　　　　　　■■■　　　　　　　　　　　　　　　　　　　　　"; SetColor(9, 15); cout << "■" << endl;	// 25
		cout << "■"; SetColor(0, 15); cout << "　　　　　　　　　　■　　　■　　　　　　　　　　　　　　　　　　　　"; SetColor(9, 15); cout << "■" << endl;	// 26
		cout << "□"; SetColor(0, 15); cout << "　　　　　　　　　■　　　　　■　　　　　　　　　　　　"; SetColor(14, 15); cout << "　■　　　　　"; SetColor(9, 15); cout << "□" << endl;	// 27
		cout << "□"; SetColor(0, 15); cout << "　　　　　　　　　■　　　　　■　　　　　　　　　　　　"; SetColor(14, 15); cout << "■■■　　　　"; SetColor(9, 15); cout << "□" << endl;	// 28
		cout << "□"; SetColor(0, 15); cout << "　　　　　　　　　■■　　　■■　　　　　　　　　　　　"; SetColor(14, 15); cout << "　■　　　　　"; SetColor(9, 15); cout << "□" << endl;	// 29
		cout << "■"; SetColor(0, 15); cout << "　　　　　　　　　■　■■■　■　　　　　　　　　　　　"; SetColor(14, 15); cout << "■　■　　　　"; SetColor(9, 15); cout << "■" << endl;	// 30
		cout << "■"; SetColor(0, 15); cout << "　　　　　　　　　■　　　　　■　　　　　　　　　　　　　　　　　　　"; SetColor(9, 15); cout << "■" << endl;	// 31
		cout << "■"; SetColor(0, 15); cout << "　　　　　　　　　■　　　　　■　　　　　　　　　　　　　　　　　　　"; SetColor(9, 15); cout << "■" << endl;	// 32
		cout << "□"; SetColor(0, 15); cout << "　　　　　　　　　■　　　　　■　　　　　　　　　　　　　　　　　　　"; SetColor(9, 15); cout << "□" << endl;	// 33
		cout << "□"; SetColor(0, 15); cout << "　　　　　　　　　■　　　　　■　　　　　　　　　　　　　　　　　　　"; SetColor(9, 15); cout << "□" << endl;	// 34
		cout << "□"; SetColor(0, 15); cout << "　　　　　　　　　■　　　　　■　　　　　　　　　　　　　　　　　　　"; SetColor(9, 15); cout << "□" << endl;	// 35
		cout << "■"; SetColor(0, 15); cout << "　　　　　　　　　■　　　　　■　　　　　　　　　　　　　　　　　　　"; SetColor(9, 15); cout << "■" << endl;	// 36
		cout << "■■□□□■■■□□□■■■□□□■■■□□□■■■□□□■■■□□□■■" << endl;	// 37	
	}
	else if (_khancheck == 2)
	{
		SetColor(9, 15);

		cout << "■"; SetColor(0, 15); cout << "　　　　　　　　　　　　　　　　　　　　"; SetColor(14, 15); cout << "　■　"; SetColor(0, 15); cout << "　　　　　　　　　　　　"; SetColor(9, 15); cout << "■" << endl;	// 24
		cout << "■"; SetColor(0, 15); cout << "　　　　　　　　　　　■■■　　　　　　"; SetColor(14, 15); cout << "■■■"; SetColor(0, 15); cout << "　　　　　　　　　　　　"; SetColor(9, 15); cout << "■" << endl;	// 25
		cout << "■"; SetColor(0, 15); cout << "　　　　　　　　　　■　　　■　　　　　"; SetColor(14, 15); cout << "　■　"; SetColor(0, 15); cout << "　　　　　　　　　　　　"; SetColor(9, 15); cout << "■" << endl;	// 26
		cout << "□"; SetColor(0, 15); cout << "　　　　　　　　　■　　　　　■　　　　"; SetColor(14, 15); cout << "■　■"; SetColor(0, 15); cout << "　　　　　　　　　　　　"; SetColor(9, 15); cout << "□" << endl;	// 27
		cout << "□"; SetColor(0, 15); cout << "　　　　　　　　　■　　　　　■　　　　　　　　　　　　　　　　　　　"; SetColor(9, 15); cout << "□" << endl;	// 28
		cout << "□"; SetColor(0, 15); cout << "　　　　　　　　　■■　　　■■　　　　　　　　　　　　　　　　　　　"; SetColor(9, 15); cout << "□" << endl;	// 29
		cout << "■"; SetColor(0, 15); cout << "　　　　　　　　　■　■■■　■　　　　　　　　　　　　　　　　　　　"; SetColor(9, 15); cout << "■" << endl;	// 30
		cout << "■"; SetColor(0, 15); cout << "　　　　　　　　　■　　　　　■　　　　　　　　　　　　　　　　　　　"; SetColor(9, 15); cout << "■" << endl;	// 31
		cout << "■"; SetColor(0, 15); cout << "　　　　　　　　　■　　　　　■　　　　　　　　　　　　　　　　　　　"; SetColor(9, 15); cout << "■" << endl;	// 32
		cout << "□"; SetColor(0, 15); cout << "　　　　　　　　　■　　　　　■　　　　　　　　　　　　　　　　　　　"; SetColor(9, 15); cout << "□" << endl;	// 33
		cout << "□"; SetColor(0, 15); cout << "　　　　　　　　　■　　　　　■　　　　　　　　　　　　　　　　　　　"; SetColor(9, 15); cout << "□" << endl;	// 34
		cout << "□"; SetColor(0, 15); cout << "　　　　　　　　　■　　　　　■　　　　　　　　　　　　　　　　　　　"; SetColor(9, 15); cout << "□" << endl;	// 35
		cout << "■"; SetColor(0, 15); cout << "　　　　　　　　　■　　　　　■　　　　　　　　　　　　　　　　　　　"; SetColor(9, 15); cout << "■" << endl;	// 36
		cout << "■■□□□■■■□□□■■■□□□■■■□□□■■■□□□■■■□□□■■" << endl;	// 37
	}
	else if (_khancheck == 3)
	{
		SetColor(9, 15);

		cout << "■"; SetColor(0, 15); cout << "　　　　　　　　　　　　　　　　　　　　"; SetColor(14, 15); cout << "　■　"; SetColor(0, 15); cout << "　　　　　　　　　　　　"; SetColor(9, 15); cout << "■" << endl;	// 24
		cout << "■"; SetColor(0, 15); cout << "　　　　　　　　　　　■■■　　　　　　"; SetColor(14, 15); cout << "■■■"; SetColor(0, 15); cout << "　　　　　　　　　　　　"; SetColor(9, 15); cout << "■" << endl;	// 25
		cout << "■"; SetColor(0, 15); cout << "　　　　　　　　　　■　　　■　　　　　"; SetColor(14, 15); cout << "　■　"; SetColor(0, 15); cout << "　　　　　　　　　　　　"; SetColor(9, 15); cout << "■" << endl;	// 26

		SetColor(13, 15);

		cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;
		cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
		cout << "■"; SetColor(0, 15); cout << "　　[칸]"; SetColor(13, 15); cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
		cout << "■"; SetColor(0, 15); cout << "　　나의 아이야, 무슨일로 나를 찾아온 것이냐"; SetColor(13, 15); cout << "　　　　　　　　　　　　　■" << endl;
		cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
		cout << "■"; SetColor(0, 15); cout << "　　▶　신의 은총을 바랍니다."; SetColor(13, 15); cout << " 　　　　　　　　　　　　　　　　　　　　■" << endl;
		cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
		cout << "■"; SetColor(0, 15); cout << "　　　　그냥 신을 뵙고 싶어 왔습니다."; SetColor(13, 15); cout << " 　　　　　　　　　　　　　　　　■" << endl;
		cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
		cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
		cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;
	}
	else if (_khancheck == 4)
	{
		SetColor(9, 15);

		cout << "■"; SetColor(0, 15); cout << "　　　　　　　　　　　　　　　　　　　　"; SetColor(14, 15); cout << "　■　"; SetColor(0, 15); cout << "　　　　　　　　　　　　"; SetColor(9, 15); cout << "■" << endl;	// 24
		cout << "■"; SetColor(0, 15); cout << "　　　　　　　　　　　■■■　　　　　　"; SetColor(14, 15); cout << "■■■"; SetColor(0, 15); cout << "　　　　　　　　　　　　"; SetColor(9, 15); cout << "■" << endl;	// 25
		cout << "■"; SetColor(0, 15); cout << "　　　　　　　　　　■　　　■　　　　　"; SetColor(14, 15); cout << "　■　"; SetColor(0, 15); cout << "　　　　　　　　　　　　"; SetColor(9, 15); cout << "■" << endl;	// 26

		SetColor(13, 15);

		cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;
		cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
		cout << "■"; SetColor(0, 15); cout << "　　[칸]"; SetColor(13, 15); cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
		cout << "■"; SetColor(0, 15); cout << "　　나의 아이야, 무슨일로 나를 찾아온 것이냐"; SetColor(13, 15); cout << "　　　　　　　　　　　　　■" << endl;
		cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
		cout << "■"; SetColor(0, 15); cout << "　　　　신의 은총을 바랍니다."; SetColor(13, 15); cout << " 　　　　　　　　　　　　　　　　　　　　■" << endl;
		cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
		cout << "■"; SetColor(0, 15); cout << "　　▶　그냥 신을 뵙고 싶어 왔습니다."; SetColor(13, 15); cout << " 　　　　　　　　　　　　　　　　■" << endl;
		cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
		cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
		cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;

	}
	else if (_khancheck == 5)
	{
		SetColor(9, 15);

		cout << "■"; SetColor(0, 15); cout << "　　　　　　　　　　　　　　　　　　　　"; SetColor(14, 15); cout << "　■　"; SetColor(0, 15); cout << "　　　　　　　　　　　　"; SetColor(9, 15); cout << "■" << endl;	// 24
		cout << "■"; SetColor(0, 15); cout << "　　　　　　　　　　　■■■　　　　　　"; SetColor(14, 15); cout << "■■■"; SetColor(0, 15); cout << "　　　　　　　　　　　　"; SetColor(9, 15); cout << "■" << endl;	// 25
		cout << "■"; SetColor(0, 15); cout << "　　　　　　　　　　■　　　■　　　　　"; SetColor(14, 15); cout << "　■　"; SetColor(0, 15); cout << "　　　　　　　　　　　　"; SetColor(9, 15); cout << "■" << endl;	// 26

		SetColor(13, 15);

		cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;
		cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
		cout << "■"; SetColor(0, 15); cout << "　　[칸]"; SetColor(13, 15); cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
		cout << "■"; SetColor(0, 15); cout << "　　기력을 250 올리는데 경험치 10,000 이 필요하느니라"; SetColor(13, 15); cout << "　　 　　　　　　■" << endl;
		cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
		cout << "■"; SetColor(0, 15); cout << "　　▶　네"; SetColor(13, 15); cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
		cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
		cout << "■"; SetColor(0, 15); cout << "　　　　아니오"; SetColor(13, 15); cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
		cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
		cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
		cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;
	}
	else if (_khancheck == 6)
	{
		SetColor(9, 15);

		cout << "■"; SetColor(0, 15); cout << "　　　　　　　　　　　　　　　　　　　　"; SetColor(14, 15); cout << "　■　"; SetColor(0, 15); cout << "　　　　　　　　　　　　"; SetColor(9, 15); cout << "■" << endl;	// 24
		cout << "■"; SetColor(0, 15); cout << "　　　　　　　　　　　■■■　　　　　　"; SetColor(14, 15); cout << "■■■"; SetColor(0, 15); cout << "　　　　　　　　　　　　"; SetColor(9, 15); cout << "■" << endl;	// 25
		cout << "■"; SetColor(0, 15); cout << "　　　　　　　　　　■　　　■　　　　　"; SetColor(14, 15); cout << "　■　"; SetColor(0, 15); cout << "　　　　　　　　　　　　"; SetColor(9, 15); cout << "■" << endl;	// 26

		SetColor(13, 15);

		cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;
		cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
		cout << "■"; SetColor(0, 15); cout << "　　[칸]"; SetColor(13, 15); cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
		cout << "■"; SetColor(0, 15); cout << "　　기력을 250 올리는데 경험치 10,000 이 필요하느니라"; SetColor(13, 15); cout << "　　 　　　　　　■" << endl;
		cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
		cout << "■"; SetColor(0, 15); cout << "　　　　네"; SetColor(13, 15); cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
		cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
		cout << "■"; SetColor(0, 15); cout << "　　▶　아니오"; SetColor(13, 15); cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
		cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
		cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
		cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;
	}
	else if (_khancheck == 7)
	{
		SetColor(9, 15);

		cout << "■"; SetColor(0, 15); cout << "　　　　　　　　　　　　　　　　　　　　"; SetColor(14, 15); cout << "　■　"; SetColor(0, 15); cout << "　　　　　　　　　　　　"; SetColor(9, 15); cout << "■" << endl;	// 24
		cout << "■"; SetColor(0, 15); cout << "　　　　　　　　　　　■■■　　　　　　"; SetColor(14, 15); cout << "■■■"; SetColor(0, 15); cout << "　　　　　　　　　　　　"; SetColor(9, 15); cout << "■" << endl;	// 25
		cout << "■"; SetColor(0, 15); cout << "　　　　　　　　　　■　　　■　　　　　"; SetColor(14, 15); cout << "　■　"; SetColor(0, 15); cout << "　　　　　　　　　　　　"; SetColor(9, 15); cout << "■" << endl;	// 26

		SetColor(13, 15);

		cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;
		cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
		cout << "■"; SetColor(0, 15); cout << "　　[칸]"; SetColor(13, 15); cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
		cout << "■"; SetColor(0, 15); cout << "　　기력을 250 올려주었다. 수행에는 끝이 없는 법,　　　　　　　　　　 "; SetColor(13, 15); cout << "■" << endl;
		cout << "■"; SetColor(0, 15); cout << "　　가르침이 필요하다면 언제든지 오거라..　　　　　　　　　　 　　　　"; SetColor(13, 15); cout << "■" << endl;
		cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
		cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
		cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
		cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
		cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
		cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;

	}
	else if (_khancheck == 8)
	{
		SetColor(9, 15);

		cout << "■"; SetColor(0, 15); cout << "　　　　　　　　　　　　　　　　　　　　"; SetColor(14, 15); cout << "　■　"; SetColor(0, 15); cout << "　　　　　　　　　　　　"; SetColor(9, 15); cout << "■" << endl;	// 24
		cout << "■"; SetColor(0, 15); cout << "　　　　　　　　　　　■■■　　　　　　"; SetColor(14, 15); cout << "■■■"; SetColor(0, 15); cout << "　　　　　　　　　　　　"; SetColor(9, 15); cout << "■" << endl;	// 25
		cout << "■"; SetColor(0, 15); cout << "　　　　　　　　　　■　　　■　　　　　"; SetColor(14, 15); cout << "　■　"; SetColor(0, 15); cout << "　　　　　　　　　　　　"; SetColor(9, 15); cout << "■" << endl;	// 26

		SetColor(13, 15);

		cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;
		cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
		cout << "■"; SetColor(0, 15); cout << "　　[칸]"; SetColor(13, 15); cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
		cout << "■"; SetColor(0, 15); cout << "　　나를 그냥 보러 왔다는 말이냐 많이 한가한가보로구나"; SetColor(13, 15); cout << " 　　　　 　　　■" << endl;
		cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
		cout << "■"; SetColor(0, 15); cout << "　　둘러보다 가거느라.."; SetColor(13, 15); cout << " 　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
		cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
		cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
		cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
		cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
		cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;
	}
	else if (_khancheck == 9)
	{
		SetColor(9, 15);

		cout << "■"; SetColor(0, 15); cout << "　　　　　　　　　　　　　　　　　　　　"; SetColor(14, 15); cout << "　■　"; SetColor(0, 15); cout << "　　　　　　　　　　　　"; SetColor(9, 15); cout << "■" << endl;	// 24
		cout << "■"; SetColor(0, 15); cout << "　　　　　　　　　　　■■■　　　　　　"; SetColor(14, 15); cout << "■■■"; SetColor(0, 15); cout << "　　　　　　　　　　　　"; SetColor(9, 15); cout << "■" << endl;	// 25
		cout << "■"; SetColor(0, 15); cout << "　　　　　　　　　　■　　　■　　　　　"; SetColor(14, 15); cout << "　■　"; SetColor(0, 15); cout << "　　　　　　　　　　　　"; SetColor(9, 15); cout << "■" << endl;	// 26

		SetColor(13, 15);

		cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;
		cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
		cout << "■"; SetColor(0, 15); cout << "　　경험치가 부족합니다.."; SetColor(13, 15); cout << "　　　　　　　　　　　　　　　　　　　　　　 ■" << endl;
		cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
		cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
		cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
		cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
		cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
		cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
		cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
		cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;
	}
}

void mainGame::FieldEventScreen()
{
	_effect = Edooropen;

	gotoxy(0, 0);
	SetColor(9, 15);

	cout << "■■□□□■■■□□□■■■□□□■■■□□□■■■□□□■■■□□□■■" << endl;	// 1
	cout << "■"; SetColor(0, 15); cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■"; SetColor(9, 15); cout << "■" << endl;	// 2
	cout << "□"; SetColor(0, 15); cout << "■■■■■■■■■　　　　　■■■■■■■■■■■■■■■　　　　　■"; SetColor(9, 15); cout << "□" << endl;	// 3
	cout << "□"; SetColor(0, 15); cout << "■■■■■■■■■　　　　　■■■■■■■■■■■■■■■　　　　　■"; SetColor(9, 15); cout << "□" << endl;	// 4
	cout << "□"; SetColor(0, 15); cout << "■■■■■■■■■　　　　　■■■■■■■■■■■■■■■　　집　　■"; SetColor(9, 15); cout << "□" << endl;	// 5
	cout << "■"; SetColor(0, 15); cout << "■■■■■■■■■　■■■　■■■■■■■■■■■■■■■　　　　　■"; SetColor(9, 15); cout << "■" << endl;	// 6
	cout << "■"; SetColor(0, 15); cout << "■■■■■■■■■　■　■　■■■■■■■■■■■■■■■　　　　　■"; SetColor(9, 15); cout << "■" << endl;	// 7
	cout << "■"; SetColor(0, 15); cout << "■■■■■■■■■■■　■■■■■■■■■■■■■■■■■■■■■■■"; SetColor(9, 15); cout << "■" << endl;	// 8
	cout << "□"; SetColor(0, 15); cout << "　　　　　　　　　　"; SetColor(14, 15); cout << "　■　"; SetColor(0, 15); cout << "　　　　　　　　　　　　　　　■■■■■■■"; SetColor(9, 15); cout << "□" << endl;	// 9
	cout << "□"; SetColor(0, 15); cout << "　　　　　　　　　　"; SetColor(14, 15); cout << "■■■"; SetColor(0, 15); cout << "　　　　　　　　　　　　　　　　■■■■■■"; SetColor(9, 15); cout << "□" << endl;	// 10
	cout << "□"; SetColor(0, 15); cout << "　　　　　　　　　　"; SetColor(14, 15); cout << "　■　"; SetColor(0, 15); cout << "　　　　　　　　　　　　　　　　■■■■■■"; SetColor(9, 15); cout << "□" << endl;	// 11
	cout << "■"; SetColor(0, 15); cout << "　　　　　　　　　　"; SetColor(14, 15); cout << "■　■"; SetColor(0, 15); cout << "　　　　　　　　　　　　　　　　　■■■■■"; SetColor(9, 15); cout << "■" << endl;	// 12
	cout << "■"; SetColor(0, 15); cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■■■■"; SetColor(9, 15); cout << "■" << endl;	// 13
	cout << "■"; SetColor(0, 15); cout << "■■■■■■■■■■■■■■■■■■■■■■■■■　　　　　　　■■■"; SetColor(9, 15); cout << "■" << endl;	// 14
	cout << "□"; SetColor(0, 15); cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■　　　　　　■■■"; SetColor(9, 15); cout << "□" << endl;	// 15
	cout << "□"; SetColor(0, 15); cout << "■■■■　　　　　　　　　　　　　　　　　　　　　　　　　　　　■■■"; SetColor(9, 15); cout << "□" << endl; // 16  
	cout << "□"; SetColor(0, 15); cout << "■■■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■■■"; SetColor(9, 15); cout << "□" << endl; // 17
	cout << "■"; SetColor(0, 15); cout << "■■■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■■■"; SetColor(9, 15); cout << "■" << endl;	// 18
	cout << "■"; SetColor(0, 15); cout << "■■■　　　　　　　　　　　　　　　　　　　　　　　　　　　　■■■■"; SetColor(9, 15); cout << "■" << endl; // 19
	cout << "■"; SetColor(0, 15); cout << "■■■　　　　　　■■■■■■■■■■■■■■■■■■■■■■■■■■"; SetColor(9, 15); cout << "■" << endl;	// 20
	cout << "□"; SetColor(0, 15); cout << "■■■　　　　　　　■■■■■■■■■■■■■■■■■■■■■■■■■"; SetColor(9, 15); cout << "□" << endl;	// 21
	cout << "□"; SetColor(0, 15); cout << "■■■　　　　　　　　　　　　　　　　　　　　　　　　　■■■■■■■"; SetColor(9, 15); cout << "□" << endl;	// 22
	cout << "□"; SetColor(0, 15); cout << "■■■■　　　　　　　　　　　　　　　　　　　　　　　　　■■■■■■"; SetColor(9, 15); cout << "□" << endl;	// 23
	cout << "■"; SetColor(0, 15); cout << "■■■■■　　　　　　　　　　　　　　　　　　　　　　　　　■■■■■"; SetColor(9, 15); cout << "■" << endl;	// 24
	cout << "■"; SetColor(0, 15); cout << "■■■■■　　　　　　　　　　　　　　　　　　　　　　　　　　■■■■"; SetColor(9, 15); cout << "■" << endl;	// 25
	cout << "■"; SetColor(0, 15); cout << "■■■■■■■■■■■■■■■■■■■■■■■■■　　　　　　■■■■"; SetColor(9, 15); cout << "■" << endl;	// 26
	cout << "□"; SetColor(0, 15); cout << "■■■■■■　　　　　　　　　　　　　　　　　　　　　　　　　■■■■"; SetColor(9, 15); cout << "□" << endl;	// 27
	cout << "□"; SetColor(0, 15); cout << "■■■■■　　　　　　　　　　　　　　　　　　　　　　　　　■■■■■"; SetColor(9, 15); cout << "□" << endl;	// 28
	cout << "□"; SetColor(0, 15); cout << "■■■■　　　　　　　　　　　　　　　　　　　　　　　　　■■■■■■"; SetColor(9, 15); cout << "□" << endl;	// 29
	cout << "■"; SetColor(0, 15); cout << "■■■　　　　　　　　　　　　　　　　　　　　　　　　　■■■■■■■"; SetColor(9, 15); cout << "■" << endl;	// 30
	cout << "■"; SetColor(0, 15); cout << "■■　　　　　　　　■■■■■■■■■■■■■■■■■■■■■■■■■"; SetColor(9, 15); cout << "■" << endl;	// 31
	cout << "■"; SetColor(0, 15); cout << "■　　　　　　　　■■■■■■■■■■■■■■■■■■■■■■■■■■"; SetColor(9, 15); cout << "■" << endl;	// 32
	cout << "□"; SetColor(0, 15); cout << "■　　　　　　　■■■■■■■■■■■■■■■■■■■■■■■■■■■"; SetColor(9, 15); cout << "□" << endl;	// 33
	cout << "□"; SetColor(0, 15); cout << "■　　　　　　■■■■■■■■■■■■■■■■■■■■■■■■■■■■"; SetColor(9, 15); cout << "□" << endl;	// 34
	cout << "□"; SetColor(0, 15); cout << "■　　　　　　■■■■■■■■■■■■■■■■■■■■■■■■■■■■"; SetColor(9, 15); cout << "□" << endl;	// 35
	cout << "■"; SetColor(0, 15); cout << "■　　　　　　■■■■■■■■■■■■■■■■■■■■■■■■■■■■"; SetColor(9, 15); cout << "■" << endl;	// 36
	cout << "■■□□□■■■□□□■■■□□□■■■□□□■■■□□□■■■□□□■■" << endl;	// 37

	Sleep(1000);

	gotoxy(0, 0);
	SetColor(9, 15);

	cout << "■■□□□■■■□□□■■■□□□■■■□□□■■■□□□■■■□□□■■" << endl;	// 1
	cout << "■"; SetColor(0, 15); cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■"; SetColor(9, 15); cout << "■" << endl;	// 2
	cout << "□"; SetColor(0, 15); cout << "■■■■■■■■■　　　　　■■■■■■■■■■■■■■■　　　　　■"; SetColor(9, 15); cout << "□" << endl;	// 3
	cout << "□"; SetColor(0, 15); cout << "■■■■■■■■■　　　　　■■■■■■■■■■■■■■■　호랑이　■"; SetColor(9, 15); cout << "□" << endl;	// 4
	cout << "□"; SetColor(0, 15); cout << "■■■■■■■■■　　　　　■■■■■■■■■■■■■■■　바　위　■"; SetColor(9, 15); cout << "□" << endl;	// 5
	cout << "■"; SetColor(0, 15); cout << "■■■■■■■■■　■■■　■■■■■■■■■■■■■■■　산　길　■"; SetColor(9, 15); cout << "■" << endl;	// 6
	cout << "■"; SetColor(0, 15); cout << "■■■■■■■■■　■　■　■■■■■■■■■■■■■■■　　　　　■"; SetColor(9, 15); cout << "■" << endl;	// 7
	cout << "■"; SetColor(0, 15); cout << "■■■■■■■■■■■　■■■■■■■■■■■■■■■■■■■■■■■"; SetColor(9, 15); cout << "■" << endl;	// 8
	cout << "□"; SetColor(0, 15); cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　■■■■■■■"; SetColor(9, 15); cout << "□" << endl;	// 9
	cout << "□"; SetColor(0, 15); cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■■■■■■"; SetColor(9, 15); cout << "□" << endl;	// 10
	cout << "□"; SetColor(0, 15); cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■■■■■■"; SetColor(9, 15); cout << "□" << endl;	// 11
	cout << "■"; SetColor(0, 15); cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■■■■■"; SetColor(9, 15); cout << "■" << endl;	// 12
	cout << "■"; SetColor(0, 15); cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■■■■"; SetColor(9, 15); cout << "■" << endl;	// 13
	cout << "■"; SetColor(0, 15); cout << "■■■■■■■■■■■■■■■■■■■■■■■■■　　　　　　　■■■"; SetColor(9, 15); cout << "■" << endl;	// 14
	cout << "□"; SetColor(0, 15); cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■　　　　　　■■■"; SetColor(9, 15); cout << "□" << endl;	// 15
	cout << "□"; SetColor(0, 15); cout << "■■■■　　　　　　　　　　　　　　　　　　　　　　　　　　　　■■■"; SetColor(9, 15); cout << "□" << endl; // 16  
	cout << "□"; SetColor(0, 15); cout << "■■■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■■■"; SetColor(9, 15); cout << "□" << endl; // 17
	cout << "■"; SetColor(0, 15); cout << "■■■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■■■"; SetColor(9, 15); cout << "■" << endl;	// 18
	cout << "■"; SetColor(0, 15); cout << "■■■　　　　　　　　　　　　　　　　　　　　　　　　　　　　■■■■"; SetColor(9, 15); cout << "■" << endl; // 19
	cout << "■"; SetColor(0, 15); cout << "■■■　　　　　　■■■■■■■■■■■■■■■■■■■■■■■■■■"; SetColor(9, 15); cout << "■" << endl;	// 20
	cout << "□"; SetColor(0, 15); cout << "■■■　　　　　　　■■■■■■■■■■■■■■■■■■■■■■■■■"; SetColor(9, 15); cout << "□" << endl;	// 21
	cout << "□"; SetColor(0, 15); cout << "■■■　　　　　　　　　　　　　　　　　　　　　　　　　■■■■■■■"; SetColor(9, 15); cout << "□" << endl;	// 22
	cout << "□"; SetColor(0, 15); cout << "■■■■　　　　　　　　　　　　　　　　　　　　　　　　　■■■■■■"; SetColor(9, 15); cout << "□" << endl;	// 23
	cout << "■"; SetColor(0, 15); cout << "■■■■■　　　　　　　　　　　　　　　　　　　　　　　　　■■■■■"; SetColor(9, 15); cout << "■" << endl;	// 24
	cout << "■"; SetColor(0, 15); cout << "■■■■■　　　　　　　　　　　　　　　　　　　　　　　　　　■■■■"; SetColor(9, 15); cout << "■" << endl;	// 25
	cout << "■"; SetColor(0, 15); cout << "■■■■■■■■■■■■■■■■■■■■■■■■■　　　　　　■■■■"; SetColor(9, 15); cout << "■" << endl;	// 26
	cout << "□"; SetColor(0, 15); cout << "■■■■■■　　　　　　　　　　　　　　　　　　　　　　　　　■■■■"; SetColor(9, 15); cout << "□" << endl;	// 27
	cout << "□"; SetColor(0, 15); cout << "■■■■■　　　　　　　　　　　　　　　　　　　　　　　　　■■■■■"; SetColor(9, 15); cout << "□" << endl;	// 28
	cout << "□"; SetColor(0, 15); cout << "■■■■　　　　　　　　　　　　　　　　　　　　　　　　　■■■■■■"; SetColor(9, 15); cout << "□" << endl;	// 29
	cout << "■"; SetColor(0, 15); cout << "■■■　　　　　　　　　　　　　　　　　　　　　　　　　■■■■■■■"; SetColor(9, 15); cout << "■" << endl;	// 30
	cout << "■"; SetColor(0, 15); cout << "■■　　　　　　　　■■■■■■■■■■■■■■■■■■■■■■■■■"; SetColor(9, 15); cout << "■" << endl;	// 31
	cout << "■"; SetColor(0, 15); cout << "■　　　　　　　　■■■■■■■■■■■■■■■■■■■■■■■■■■"; SetColor(9, 15); cout << "■" << endl;	// 32
	cout << "□"; SetColor(0, 15); cout << "■　　　　　　　■■■■■■■■■■■■■■■■■■■■■■■■■■■"; SetColor(9, 15); cout << "□" << endl;	// 33
	cout << "□"; SetColor(0, 15); cout << "■　　　　　　■■■■■■■■■■■■■■■■■■■■■■■■■■■■"; SetColor(9, 15); cout << "□" << endl;	// 34
	cout << "□"; SetColor(0, 15); cout << "■　　　　　　■■■■■■■■■■■■■■■■■■■■■■■■■■■■"; SetColor(9, 15); cout << "□" << endl;	// 35
	cout << "■"; SetColor(0, 15); cout << "■　　　　　　■■■■■■■■■■■■■■■■■■■■■■■■■■■■"; SetColor(9, 15); cout << "■" << endl;	// 36
	cout << "■■□□□■■■□□□■■■□□□■■■□□□■■■□□□■■■□□□■■" << endl;	// 37

	Sleep(800);
}

void mainGame::FieldBattle()
{
	++_safe;

	if (_safe > 8)
	{
		int battlePos = 0;
		battlePos = rand() % 100 + 1;

		if (battlePos > 10 && battlePos <= 25)
		{
			b_fieldMusic = false;
			_effect = Ebattleenter;
			FieldBattleEnter();

			FieldBattleInit();

			if (_characterHp == 0)
			{
				GameOver();
			}
			else
			{
				b_fieldMusic = true;
				_safe = 0;
				FieldScreen();
				FieldChoice();
			}
		}
		else
		{
			FieldChoice();
		}
	}
	else
	{
		FieldChoice();
	}
}

void mainGame::GameOver()
{
	SetColor(15, 15);
	GameOverScreen();
	Sleep(800);
	SetColor(7, 15);
	GameOverScreen();
	Sleep(1000);
	SetColor(8, 15);
	GameOverScreen();
	Sleep(1000);
	SetColor(0, 15);
	GameOverScreen();

	while (true)
	{
		_key = '0';
		_key = _getch();

		if (_key == (char)ENTER || _key == (char)SPACE)
		{
			SetColor(8, 15);
			GameOverScreen();
			Sleep(1000);

			SetColor(7, 15);
			GameOverScreen();
			Sleep(1000);

			SetColor(15, 15);
			GameOverScreen();
			Sleep(800);

			b_game = false;

			break;
		}
	}
}

void mainGame::GameOverScreen()
{
	gotoxy(0, 0);

	cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　" << endl;	// 20
	cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　" << endl;	// 19
	cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　" << endl;	// 1
	cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　" << endl;	// 2
	cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　" << endl;	// 3
	cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　" << endl;	// 4
	cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　" << endl;	// 5
	cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　" << endl;	// 6
	cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　" << endl;	// 7
	cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　" << endl;	// 8
	cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　" << endl;	// 9
	cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　" << endl;	// 10
	cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　" << endl;	// 11
	cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　" << endl;	// 12
	cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　" << endl;	// 37
	cout << "　　■■■　■■■　■■■■■　■■■　■■■　■　■　■■■　■■■　　" << endl;	// 13
	cout << "　　■　　　■　■　■　■　■　■　　　■　■　■　■　■　　　■　■　　" << endl;	// 14
	cout << "　　■■■　■■■　■　■　■　■■　　■　■　■　■　■■■　■■　　　" << endl;	// 15
	cout << "　　■　■　■　■　■　■　■　■　　　■　■　■　■　■　　　■　■　　" << endl;	// 16
	cout << "　　■■■　■　■　■　■　■　■■■　■■■　　■　　■■■　■　■　　" << endl;	// 17
	cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　" << endl;	// 18
	cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　" << endl;	// 21
	cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　" << endl;	// 22
	cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　" << endl;	// 23
	cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　" << endl;	// 24
	cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　" << endl;	// 25
	cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　" << endl;	// 26
	cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　" << endl;	// 27
	cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　" << endl;	// 28
	cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　" << endl;	// 29
	cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　" << endl;	// 30
	cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　" << endl;	// 31
	cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　" << endl;	// 32
	cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　" << endl;	// 33
	cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　" << endl;	// 34
	cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　" << endl;	// 35
	cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　" << endl;	// 36

}

void mainGame::FieldBattleEnter()
{
	SetColor(15, 15);
	BootScreen2();
	Sleep(130);

	FieldScreen();
	Sleep(130);

	SetColor(15, 15);
	BootScreen2();
	Sleep(130);

	FieldScreen();
	Sleep(1250);
}

void mainGame::FieldChoice()
{
	_key = '0';
	_key = _getch();

	if (_key == (char)LEFT)
	{
		switch (_fieldcheck)
		{
		case 1:
		{
			_fieldcheck = 2;
			FieldScreen();
			FieldBattle();
		}
		break;
		case 3:
		{
			_fieldcheck = 1;
			FieldScreen();
			FieldBattle();
		}
		break;
		case 4:
		{
			_fieldcheck = 3;
			FieldScreen();
			FieldBattle();
		}
		break;
		case 5:
		{
			_fieldcheck = 4;
			FieldScreen();
			FieldBattle();
		}
		break;
		case 6:
		{
			_fieldcheck = 5;
			FieldScreen();
			FieldBattle();
		}
		break;
		default:
		{
			FieldChoice();
		}
		break;
		}
	}
	else if (_key == (char)RIGHT)
	{
		switch (_fieldcheck)
		{
		case 1:
		{
			_fieldcheck = 3;
			FieldScreen();
			FieldBattle();
		}
		break;
		case 2:
		{
			_fieldcheck = 1;
			FieldScreen();
			FieldBattle();
		}
		break;
		case 3:
		{
			_fieldcheck = 4;
			FieldScreen();
			FieldBattle();
		}
		break;
		case 4:
		{
			_fieldcheck = 5;
			FieldScreen();
			FieldBattle();
		}
		break;
		case 5:
		{
			_fieldcheck = 6;
			FieldScreen();
			FieldBattle();
		}
		break;
		default:
		{
			FieldChoice();
		}
		break;
		}
	}
	else if (_key == (char)UP)
	{
		switch (_fieldcheck)
		{
		case 3:
		{
			_fieldcheck = 1;
			FieldScreen();
			FieldBattle();
		}
		break;
		case 4:
		{
			_fieldcheck = 3;
			FieldScreen();
			FieldBattle();
		}
		break;
		case 5:
		{
			_fieldcheck = 4;
			FieldScreen();
			FieldBattle();
		}
		break;
		case 6:
		{
			_fieldcheck = 5;
			FieldScreen();
			FieldBattle();
		}
		break;
		default:
		{
			FieldChoice();
		}
		break;
		}
	}
	else if (_key == (char)DOWN)
	{
		switch (_fieldcheck)
		{
		case 1:
		{
			_fieldcheck = 3;
			FieldScreen();
			FieldBattle();
		}
		break;
		case 3:
		{
			_fieldcheck = 4;
			FieldScreen();
			FieldBattle();
		}
		break;
		case 4:
		{
			_fieldcheck = 5;
			FieldScreen();
			FieldBattle();
		}
		break;
		case 5:
		{
			_fieldcheck = 6;
			FieldScreen();
			FieldBattle();
		}
		break;
		default:
		{
			FieldChoice();
		}
		break;
		}
	}
	else if (_key == (char)ENTER || _key == (char)SPACE)
	{
		switch (_fieldcheck)
		{
		case 1:
		{
			FieldEventScreen();
			b_fieldMusic = false;
			_fieldcheck = 0;
			_safe = 0;

			Move();
			b_homeMusic = true;
			_homecheck = 1;
			HomeFieldScreen();
			HomeChoice();
		}
		break;
		case 2:
		{
			_fieldcheck = 0;
			_safe = 0;

			_farmcheck = 8;
			FarmScreen();
			FarmChoice();
		}
		break;
		case 6:
		{
			_fieldcheck = 0;
			_safe = 0;
			FieldWorldMapEnterScreen();
			Sleep(1350);
			b_fieldMusic = false;
			Move();
			_worldcheck = 1;
			b_worldmapMusic = true;
			WorldMapScreen();
			WorldMapChoice();
		}
		break;
		default:
		{
			FieldChoice();
		}
		break;
		}
	}
	else if (_key == (char)ESC)
	{
		_statuscheck = 1;
		Status();
	}
	else
	{
		FieldChoice();
	}
}

void mainGame::FieldWorldMapEnterScreen()
{
	gotoxy(0, 0);
	SetColor(9, 15);

	cout << "■■□□□■■■□□□■■■□□□■■■□□□■■■□□□■■■□□□■■" << endl;	// 1
	cout << "■"; SetColor(0, 15); cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■"; SetColor(9, 15); cout << "■" << endl;	// 2
	cout << "□"; SetColor(0, 15); cout << "■■■■■■■■■　　　　　■■■■■■■■■■■■■■■　　　　　■"; SetColor(9, 15); cout << "□" << endl;	// 3
	cout << "□"; SetColor(0, 15); cout << "■■■■■■■■■　　　　　■■■■■■■■■■■■■■■　호랑이　■"; SetColor(9, 15); cout << "□" << endl;	// 4
	cout << "□"; SetColor(0, 15); cout << "■■■■■■■■■　　　　　■■■■■■■■■■■■■■■　바　위　■"; SetColor(9, 15); cout << "□" << endl;	// 5
	cout << "■"; SetColor(0, 15); cout << "■■■■■■■■■　■■■　■■■■■■■■■■■■■■■　산　길　■"; SetColor(9, 15); cout << "■" << endl;	// 6
	cout << "■"; SetColor(0, 15); cout << "■■■■■■■■■　■　■　■■■■■■■■■■■■■■■　　　　　■"; SetColor(9, 15); cout << "■" << endl;	// 7
	cout << "■"; SetColor(0, 15); cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■"; SetColor(9, 15); cout << "■" << endl;	// 8
	cout << "□"; SetColor(0, 15); cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　■■■■■■■"; SetColor(9, 15); cout << "□" << endl;	// 9
	cout << "□"; SetColor(0, 15); cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■■■■■■"; SetColor(9, 15); cout << "□" << endl;	// 10
	cout << "□"; SetColor(0, 15); cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■■■■■■"; SetColor(9, 15); cout << "□" << endl;	// 11
	cout << "■"; SetColor(0, 15); cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■■■■■"; SetColor(9, 15); cout << "■" << endl;	// 12
	cout << "■"; SetColor(0, 15); cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■■■■"; SetColor(9, 15); cout << "■" << endl;	// 13
	cout << "■"; SetColor(0, 15); cout << "■■■■■■■■■■■■■■■■■■■■■■■■■　　　　　　　■■■"; SetColor(9, 15); cout << "■" << endl;	// 14
	cout << "□"; SetColor(0, 15); cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■　　　　　　■■■"; SetColor(9, 15); cout << "□" << endl;	// 15
	cout << "□"; SetColor(0, 15); cout << "■■■■　　　　　　　　　　　　　　　　　　　　　　　　　　　　■■■"; SetColor(9, 15); cout << "□" << endl;   // 16  
	cout << "□"; SetColor(0, 15); cout << "■■■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■■■"; SetColor(9, 15); cout << "□" << endl;   // 17
	cout << "■"; SetColor(0, 15); cout << "■■■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■■■"; SetColor(9, 15); cout << "■" << endl;	// 18
	cout << "■"; SetColor(0, 15); cout << "■■■　　　　　　　　　　　　　　　　　　　　　　　　　　　　■■■■"; SetColor(9, 15); cout << "■" << endl;   // 19
	cout << "■"; SetColor(0, 15); cout << "■■■　　　　　　■■■■■■■■■■■■■■■■■■■■■■■■■■"; SetColor(9, 15); cout << "■" << endl;	// 20
	cout << "□"; SetColor(0, 15); cout << "■■■　　　　　　　■■■■■■■■■■■■■■■■■■■■■■■■■"; SetColor(9, 15); cout << "□" << endl;	// 21
	cout << "□"; SetColor(0, 15); cout << "■■■　　　　　　　　　　　　　　　　　　　　　　　　　■■■■■■■"; SetColor(9, 15); cout << "□" << endl;	// 22
	cout << "□"; SetColor(0, 15); cout << "■■■■　　　　　　　　　　　　　　　　　　　　　　　　　■■■■■■"; SetColor(9, 15); cout << "□" << endl;	// 23
	cout << "■"; SetColor(0, 15); cout << "■■■■■　　　　　　　　　　　　　　　　　　　　　　　　　■■■■■"; SetColor(9, 15); cout << "■" << endl;	// 24
	cout << "■"; SetColor(0, 15); cout << "■■■■■　　　　　　　　　　　　　　　　　　　　　　　　　　■■■■"; SetColor(9, 15); cout << "■" << endl;	// 25
	cout << "■"; SetColor(0, 15); cout << "■■■■■■■■■■■■■■■■■■■■■■■■■　　　　　　■■■■"; SetColor(9, 15); cout << "■" << endl;	// 26
	cout << "□"; SetColor(0, 15); cout << "■■■■■■　　　　　　　　　　　　　　　　　　　　　　　　　■■■■"; SetColor(9, 15); cout << "□" << endl;	// 27
	cout << "□"; SetColor(0, 15); cout << "■■■■■　　　　　　　　　　　　　　　　　　　　　　　　　■■■■■"; SetColor(9, 15); cout << "□" << endl;	// 28
	cout << "□"; SetColor(0, 15); cout << "■■■■　　　　　　　　　　　　　　　　　　　　　　　　　■■■■■■"; SetColor(9, 15); cout << "□" << endl;	// 29
	cout << "■"; SetColor(0, 15); cout << "■■■　　　　　　　　　　　　　　　　　　　　　　　　　■■■■■■■"; SetColor(9, 15); cout << "■" << endl;	// 30
	cout << "■"; SetColor(0, 15); cout << "■■　　　　　　　　■■■■■■■■■■■■■■■■■■■■■■■■■"; SetColor(9, 15); cout << "■" << endl;	// 31
	cout << "■"; SetColor(0, 15); cout << "■　　　　　　　　■■■■■■■■■■■■■■■■■■■■■■■■■■"; SetColor(9, 15); cout << "■" << endl;	// 32
	cout << "□"; SetColor(0, 15); cout << "■　　　　　　　■■■■■■■■■■■■■■■■■■■■■■■■■■■"; SetColor(9, 15); cout << "□" << endl;	// 33
	cout << "□"; SetColor(0, 15); cout << "■　　　　　　■■■■■■■■■■■■■■■■■■■■■■■■■■■■"; SetColor(9, 15); cout << "□" << endl;	// 34
	cout << "□"; SetColor(0, 15); cout << "■　　　　　　■■■■■■■■■■■■■■■■■■■■■■■■■■■■"; SetColor(9, 15); cout << "□" << endl;	// 35
	cout << "■"; SetColor(0, 15); cout << "■　　　　　　■■■■■■■■■■■■■■■■■■■■■■■■■■■■"; SetColor(9, 15); cout << "■" << endl;	// 36
	cout << "■■□□□■■■□□□■■■□□□■■■□□□■■■□□□■■■□□□■■" << endl;	// 37
}

void mainGame::FieldScreen()
{
	switch (_fieldcheck)
	{
	case 1:
	{
		gotoxy(0, 0);
		SetColor(9, 15);

		cout << "■■□□□■■■□□□■■■□□□■■■□□□■■■□□□■■■□□□■■" << endl;	// 1
		cout << "■"; SetColor(0, 15); cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■"; SetColor(9, 15); cout << "■" << endl;	// 2
		cout << "□"; SetColor(0, 15); cout << "■■■■■■■■■　　　　　■■■■■■■■■■■■■■■　　　　　■"; SetColor(9, 15); cout << "□" << endl;	// 3
		cout << "□"; SetColor(0, 15); cout << "■■■■■■■■■　　　　　■■■■■■■■■■■■■■■　　　　　■"; SetColor(9, 15); cout << "□" << endl;	// 4
		cout << "□"; SetColor(0, 15); cout << "■■■■■■■■■　　　　　■■■■■■■■■■■■■■■　　집　　■"; SetColor(9, 15); cout << "□" << endl;	// 5
		cout << "■"; SetColor(0, 15); cout << "■■■■■■■■■　■■■　■■■■■■■■■■■■■■■　　　　　■"; SetColor(9, 15); cout << "■" << endl;	// 6
		cout << "■"; SetColor(0, 15); cout << "■■■■■■■■■　■　■　■■■■■■■■■■■■■■■　　　　　■"; SetColor(9, 15); cout << "■" << endl;	// 7
		cout << "■"; SetColor(0, 15); cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■"; SetColor(9, 15); cout << "■" << endl;	// 8
		cout << "□"; SetColor(0, 15); cout << "　　　　　　　　　　"; SetColor(14, 15); cout << "　■　"; SetColor(0, 15); cout << "　　　　　　　　　　　　　　　■■■■■■■"; SetColor(9, 15); cout << "□" << endl;	// 9
		cout << "□"; SetColor(0, 15); cout << "　　　　　　　　　　"; SetColor(14, 15); cout << "■■■"; SetColor(0, 15); cout << "　　　　　　　　　　　　　　　　■■■■■■"; SetColor(9, 15); cout << "□" << endl;	// 10
		cout << "□"; SetColor(0, 15); cout << "　　　　　　　　　　"; SetColor(14, 15); cout << "　■　"; SetColor(0, 15); cout << "　　　　　　　　　　　　　　　　■■■■■■"; SetColor(9, 15); cout << "□" << endl;	// 11
		cout << "■"; SetColor(0, 15); cout << "　　　　　　　　　　"; SetColor(14, 15); cout << "■　■"; SetColor(0, 15); cout << "　　　　　　　　　　　　　　　　　■■■■■"; SetColor(9, 15); cout << "■" << endl;	// 12
		cout << "■"; SetColor(0, 15); cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■■■■"; SetColor(9, 15); cout << "■" << endl;	// 13
		cout << "■"; SetColor(0, 15); cout << "■■■■■■■■■■■■■■■■■■■■■■■■■　　　　　　　■■■"; SetColor(9, 15); cout << "■" << endl;	// 14
		cout << "□"; SetColor(0, 15); cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■　　　　　　■■■"; SetColor(9, 15); cout << "□" << endl;	// 15
		cout << "□"; SetColor(0, 15); cout << "■■■■　　　　　　　　　　　　　　　　　　　　　　　　　　　　■■■"; SetColor(9, 15); cout << "□" << endl;   // 16  
		cout << "□"; SetColor(0, 15); cout << "■■■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■■■"; SetColor(9, 15); cout << "□" << endl;   // 17
		cout << "■"; SetColor(0, 15); cout << "■■■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■■■"; SetColor(9, 15); cout << "■" << endl;	// 18
		cout << "■"; SetColor(0, 15); cout << "■■■　　　　　　　　　　　　　　　　　　　　　　　　　　　　■■■■"; SetColor(9, 15); cout << "■" << endl;   // 19
		cout << "■"; SetColor(0, 15); cout << "■■■　　　　　　■■■■■■■■■■■■■■■■■■■■■■■■■■"; SetColor(9, 15); cout << "■" << endl;	// 20
		cout << "□"; SetColor(0, 15); cout << "■■■　　　　　　　■■■■■■■■■■■■■■■■■■■■■■■■■"; SetColor(9, 15); cout << "□" << endl;	// 21
		cout << "□"; SetColor(0, 15); cout << "■■■　　　　　　　　　　　　　　　　　　　　　　　　　■■■■■■■"; SetColor(9, 15); cout << "□" << endl;	// 22
		cout << "□"; SetColor(0, 15); cout << "■■■■　　　　　　　　　　　　　　　　　　　　　　　　　■■■■■■"; SetColor(9, 15); cout << "□" << endl;	// 23
		cout << "■"; SetColor(0, 15); cout << "■■■■■　　　　　　　　　　　　　　　　　　　　　　　　　■■■■■"; SetColor(9, 15); cout << "■" << endl;	// 24
		cout << "■"; SetColor(0, 15); cout << "■■■■■　　　　　　　　　　　　　　　　　　　　　　　　　　■■■■"; SetColor(9, 15); cout << "■" << endl;	// 25
		cout << "■"; SetColor(0, 15); cout << "■■■■■■■■■■■■■■■■■■■■■■■■■　　　　　　■■■■"; SetColor(9, 15); cout << "■" << endl;	// 26
		cout << "□"; SetColor(0, 15); cout << "■■■■■■　　　　　　　　　　　　　　　　　　　　　　　　　■■■■"; SetColor(9, 15); cout << "□" << endl;	// 27
		cout << "□"; SetColor(0, 15); cout << "■■■■■　　　　　　　　　　　　　　　　　　　　　　　　　■■■■■"; SetColor(9, 15); cout << "□" << endl;	// 28
		cout << "□"; SetColor(0, 15); cout << "■■■■　　　　　　　　　　　　　　　　　　　　　　　　　■■■■■■"; SetColor(9, 15); cout << "□" << endl;	// 29
		cout << "■"; SetColor(0, 15); cout << "■■■　　　　　　　　　　　　　　　　　　　　　　　　　■■■■■■■"; SetColor(9, 15); cout << "■" << endl;	// 30
		cout << "■"; SetColor(0, 15); cout << "■■　　　　　　　　■■■■■■■■■■■■■■■■■■■■■■■■■"; SetColor(9, 15); cout << "■" << endl;	// 31
		cout << "■"; SetColor(0, 15); cout << "■　　　　　　　　■■■■■■■■■■■■■■■■■■■■■■■■■■"; SetColor(9, 15); cout << "■" << endl;	// 32
		cout << "□"; SetColor(0, 15); cout << "■　　　　　　　■■■■■■■■■■■■■■■■■■■■■■■■■■■"; SetColor(9, 15); cout << "□" << endl;	// 33
		cout << "□"; SetColor(0, 15); cout << "■　　　　　　■■■■■■■■■■■■■■■■■■■■■■■■■■■■"; SetColor(9, 15); cout << "□" << endl;	// 34
		cout << "□"; SetColor(0, 15); cout << "■　　　　　　■■■■■■■■■■■■■■■■■■■■■■■■■■■■"; SetColor(9, 15); cout << "□" << endl;	// 35
		cout << "■"; SetColor(0, 15); cout << "■　　　　　　■■■■■■■■■■■■■■■■■■■■■■■■■■■■"; SetColor(9, 15); cout << "■" << endl;	// 36
		cout << "■■□□□■■■□□□■■■□□□■■■□□□■■■□□□■■■□□□■■" << endl;	// 37
	}
	break;
	case 2:
	{
		gotoxy(0, 0);
		SetColor(9, 15);

		cout << "■■□□□■■■□□□■■■□□□■■■□□□■■■□□□■■■□□□■■" << endl;	// 1
		cout << "■"; SetColor(0, 15); cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■"; SetColor(9, 15); cout << "■" << endl;	// 2
		cout << "□"; SetColor(0, 15); cout << "■■■■■■■■■　　　　　■■■■■■■■■■■■■■■　　　　　■"; SetColor(9, 15); cout << "□" << endl;	// 3
		cout << "□"; SetColor(0, 15); cout << "■■■■■■■■■　　　　　■■■■■■■■■■■■■■■　　　　　■"; SetColor(9, 15); cout << "□" << endl;	// 4
		cout << "□"; SetColor(0, 15); cout << "■■■■■■■■■　　　　　■■■■■■■■■■■■■■■　　밭　　■"; SetColor(9, 15); cout << "□" << endl;	// 5
		cout << "■"; SetColor(0, 15); cout << "■■■■■■■■■　■■■　■■■■■■■■■■■■■■■　　　　　■"; SetColor(9, 15); cout << "■" << endl;	// 6
		cout << "■"; SetColor(0, 15); cout << "■■■■■■■■■　■　■　■■■■■■■■■■■■■■■　　　　　■"; SetColor(9, 15); cout << "■" << endl;	// 7
		cout << "■"; SetColor(0, 15); cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■"; SetColor(9, 15); cout << "■" << endl;	// 8
		cout << "□"; SetColor(0, 15); cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　■■■■■■■"; SetColor(9, 15); cout << "□" << endl;	// 9
		cout << "□"; SetColor(14, 15); cout << "　　■　"; SetColor(0, 15); cout << "　　　　　　　　　　　　　　　　　　　　　　　　　■■■■■■"; SetColor(9, 15); cout << "□" << endl;	// 10
		cout << "□"; SetColor(14, 15); cout << "　■■■"; SetColor(0, 15); cout << "　　　　　　　　　　　　　　　　　　　　　　　　　■■■■■■"; SetColor(9, 15); cout << "□" << endl;	// 11
		cout << "■"; SetColor(14, 15); cout << "　　■　"; SetColor(0, 15); cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　■■■■■"; SetColor(9, 15); cout << "■" << endl;	// 12
		cout << "■"; SetColor(14, 15); cout << "　■　■"; SetColor(0, 15); cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　■■■■"; SetColor(9, 15); cout << "■" << endl;	// 13
		cout << "■"; SetColor(0, 15); cout << "■■■■■■■■■■■■■■■■■■■■■■■■■　　　　　　　■■■"; SetColor(9, 15); cout << "■" << endl;	// 14
		cout << "□"; SetColor(0, 15); cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■　　　　　　■■■"; SetColor(9, 15); cout << "□" << endl;	// 15
		cout << "□"; SetColor(0, 15); cout << "■■■■　　　　　　　　　　　　　　　　　　　　　　　　　　　　■■■"; SetColor(9, 15); cout << "□" << endl;   // 16  
		cout << "□"; SetColor(0, 15); cout << "■■■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■■■"; SetColor(9, 15); cout << "□" << endl;   // 17
		cout << "■"; SetColor(0, 15); cout << "■■■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■■■"; SetColor(9, 15); cout << "■" << endl;	// 18
		cout << "■"; SetColor(0, 15); cout << "■■■　　　　　　　　　　　　　　　　　　　　　　　　　　　　■■■■"; SetColor(9, 15); cout << "■" << endl;   // 19
		cout << "■"; SetColor(0, 15); cout << "■■■　　　　　　■■■■■■■■■■■■■■■■■■■■■■■■■■"; SetColor(9, 15); cout << "■" << endl;	// 20
		cout << "□"; SetColor(0, 15); cout << "■■■　　　　　　　■■■■■■■■■■■■■■■■■■■■■■■■■"; SetColor(9, 15); cout << "□" << endl;	// 21
		cout << "□"; SetColor(0, 15); cout << "■■■　　　　　　　　　　　　　　　　　　　　　　　　　■■■■■■■"; SetColor(9, 15); cout << "□" << endl;	// 22
		cout << "□"; SetColor(0, 15); cout << "■■■■　　　　　　　　　　　　　　　　　　　　　　　　　■■■■■■"; SetColor(9, 15); cout << "□" << endl;	// 23
		cout << "■"; SetColor(0, 15); cout << "■■■■■　　　　　　　　　　　　　　　　　　　　　　　　　■■■■■"; SetColor(9, 15); cout << "■" << endl;	// 24
		cout << "■"; SetColor(0, 15); cout << "■■■■■　　　　　　　　　　　　　　　　　　　　　　　　　　■■■■"; SetColor(9, 15); cout << "■" << endl;	// 25
		cout << "■"; SetColor(0, 15); cout << "■■■■■■■■■■■■■■■■■■■■■■■■■　　　　　　■■■■"; SetColor(9, 15); cout << "■" << endl;	// 26
		cout << "□"; SetColor(0, 15); cout << "■■■■■■　　　　　　　　　　　　　　　　　　　　　　　　　■■■■"; SetColor(9, 15); cout << "□" << endl;	// 27
		cout << "□"; SetColor(0, 15); cout << "■■■■■　　　　　　　　　　　　　　　　　　　　　　　　　■■■■■"; SetColor(9, 15); cout << "□" << endl;	// 28
		cout << "□"; SetColor(0, 15); cout << "■■■■　　　　　　　　　　　　　　　　　　　　　　　　　■■■■■■"; SetColor(9, 15); cout << "□" << endl;	// 29
		cout << "■"; SetColor(0, 15); cout << "■■■　　　　　　　　　　　　　　　　　　　　　　　　　■■■■■■■"; SetColor(9, 15); cout << "■" << endl;	// 30
		cout << "■"; SetColor(0, 15); cout << "■■　　　　　　　　■■■■■■■■■■■■■■■■■■■■■■■■■"; SetColor(9, 15); cout << "■" << endl;	// 31
		cout << "■"; SetColor(0, 15); cout << "■　　　　　　　　■■■■■■■■■■■■■■■■■■■■■■■■■■"; SetColor(9, 15); cout << "■" << endl;	// 32
		cout << "□"; SetColor(0, 15); cout << "■　　　　　　　■■■■■■■■■■■■■■■■■■■■■■■■■■■"; SetColor(9, 15); cout << "□" << endl;	// 33
		cout << "□"; SetColor(0, 15); cout << "■　　　　　　■■■■■■■■■■■■■■■■■■■■■■■■■■■■"; SetColor(9, 15); cout << "□" << endl;	// 34
		cout << "□"; SetColor(0, 15); cout << "■　　　　　　■■■■■■■■■■■■■■■■■■■■■■■■■■■■"; SetColor(9, 15); cout << "□" << endl;	// 35
		cout << "■"; SetColor(0, 15); cout << "■　　　　　　■■■■■■■■■■■■■■■■■■■■■■■■■■■■"; SetColor(9, 15); cout << "■" << endl;	// 36
		cout << "■■□□□■■■□□□■■■□□□■■■□□□■■■□□□■■■□□□■■" << endl;	// 37
	}
	break;
	case 3:
	{
		gotoxy(0, 0);
		SetColor(9, 15);

		cout << "■■□□□■■■□□□■■■□□□■■■□□□■■■□□□■■■□□□■■" << endl;	// 1
		cout << "■"; SetColor(0, 15); cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■"; SetColor(9, 15); cout << "■" << endl;	// 2
		cout << "□"; SetColor(0, 15); cout << "■■■■■■■■■　　　　　■■■■■■■■■■■■■■■　　　　　■"; SetColor(9, 15); cout << "□" << endl;	// 3
		cout << "□"; SetColor(0, 15); cout << "■■■■■■■■■　　　　　■■■■■■■■■■■■■■■　호랑이　■"; SetColor(9, 15); cout << "□" << endl;	// 4
		cout << "□"; SetColor(0, 15); cout << "■■■■■■■■■　　　　　■■■■■■■■■■■■■■■　바　위　■"; SetColor(9, 15); cout << "□" << endl;	// 5
		cout << "■"; SetColor(0, 15); cout << "■■■■■■■■■　■■■　■■■■■■■■■■■■■■■　산　길　■"; SetColor(9, 15); cout << "■" << endl;	// 6
		cout << "■"; SetColor(0, 15); cout << "■■■■■■■■■　■　■　■■■■■■■■■■■■■■■　　　　　■"; SetColor(9, 15); cout << "■" << endl;	// 7
		cout << "■"; SetColor(0, 15); cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■"; SetColor(9, 15); cout << "■" << endl;	// 8
		cout << "□"; SetColor(0, 15); cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　■■■■■■■"; SetColor(9, 15); cout << "□" << endl;	// 9
		cout << "□"; SetColor(0, 15); cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■■■■■■"; SetColor(9, 15); cout << "□" << endl;	// 10
		cout << "□"; SetColor(0, 15); cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■■■■■■"; SetColor(9, 15); cout << "□" << endl;	// 11
		cout << "■"; SetColor(0, 15); cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■■■■■"; SetColor(9, 15); cout << "■" << endl;	// 12
		cout << "■"; SetColor(0, 15); cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■■■■"; SetColor(9, 15); cout << "■" << endl;	// 13
		cout << "■"; SetColor(0, 15); cout << "■■■■■■■■■■■■■■■■■■■■■■■■■　　　　　　　■■■"; SetColor(9, 15); cout << "■" << endl;	// 14
		cout << "□"; SetColor(0, 15); cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■　"; SetColor(14, 15); cout << "　■　"; SetColor(0, 15); cout << "　　■■■"; SetColor(9, 15); cout << "□" << endl;	// 15
		cout << "□"; SetColor(0, 15); cout << "■■■■　　　　　　　　　　　　　　　　　　　　　　　"; SetColor(14, 15); cout << "■■■"; SetColor(0, 15); cout << "　　■■■"; SetColor(9, 15); cout << "□" << endl;   // 16  
		cout << "□"; SetColor(0, 15); cout << "■■■　　　　　　　　　　　　　　　　　　　　　　　　"; SetColor(14, 15); cout << "　■　"; SetColor(0, 15); cout << "　　■■■"; SetColor(9, 15); cout << "□" << endl;   // 17
		cout << "■"; SetColor(0, 15); cout << "■■■　　　　　　　　　　　　　　　　　　　　　　　　"; SetColor(14, 15); cout << "■　■"; SetColor(0, 15); cout << "　　■■■"; SetColor(9, 15); cout << "■" << endl;	// 18
		cout << "■"; SetColor(0, 15); cout << "■■■　　　　　　　　　　　　　　　　　　　　　　　　　　　　■■■■"; SetColor(9, 15); cout << "■" << endl;   // 19
		cout << "■"; SetColor(0, 15); cout << "■■■　　　　　　■■■■■■■■■■■■■■■■■■■■■■■■■■"; SetColor(9, 15); cout << "■" << endl;	// 20
		cout << "□"; SetColor(0, 15); cout << "■■■　　　　　　　■■■■■■■■■■■■■■■■■■■■■■■■■"; SetColor(9, 15); cout << "□" << endl;	// 21
		cout << "□"; SetColor(0, 15); cout << "■■■　　　　　　　　　　　　　　　　　　　　　　　　　■■■■■■■"; SetColor(9, 15); cout << "□" << endl;	// 22
		cout << "□"; SetColor(0, 15); cout << "■■■■　　　　　　　　　　　　　　　　　　　　　　　　　■■■■■■"; SetColor(9, 15); cout << "□" << endl;	// 23
		cout << "■"; SetColor(0, 15); cout << "■■■■■　　　　　　　　　　　　　　　　　　　　　　　　　■■■■■"; SetColor(9, 15); cout << "■" << endl;	// 24
		cout << "■"; SetColor(0, 15); cout << "■■■■■　　　　　　　　　　　　　　　　　　　　　　　　　　■■■■"; SetColor(9, 15); cout << "■" << endl;	// 25
		cout << "■"; SetColor(0, 15); cout << "■■■■■■■■■■■■■■■■■■■■■■■■■　　　　　　■■■■"; SetColor(9, 15); cout << "■" << endl;	// 26
		cout << "□"; SetColor(0, 15); cout << "■■■■■■　　　　　　　　　　　　　　　　　　　　　　　　　■■■■"; SetColor(9, 15); cout << "□" << endl;	// 27
		cout << "□"; SetColor(0, 15); cout << "■■■■■　　　　　　　　　　　　　　　　　　　　　　　　　■■■■■"; SetColor(9, 15); cout << "□" << endl;	// 28
		cout << "□"; SetColor(0, 15); cout << "■■■■　　　　　　　　　　　　　　　　　　　　　　　　　■■■■■■"; SetColor(9, 15); cout << "□" << endl;	// 29
		cout << "■"; SetColor(0, 15); cout << "■■■　　　　　　　　　　　　　　　　　　　　　　　　　■■■■■■■"; SetColor(9, 15); cout << "■" << endl;	// 30
		cout << "■"; SetColor(0, 15); cout << "■■　　　　　　　　■■■■■■■■■■■■■■■■■■■■■■■■■"; SetColor(9, 15); cout << "■" << endl;	// 31
		cout << "■"; SetColor(0, 15); cout << "■　　　　　　　　■■■■■■■■■■■■■■■■■■■■■■■■■■"; SetColor(9, 15); cout << "■" << endl;	// 32
		cout << "□"; SetColor(0, 15); cout << "■　　　　　　　■■■■■■■■■■■■■■■■■■■■■■■■■■■"; SetColor(9, 15); cout << "□" << endl;	// 33
		cout << "□"; SetColor(0, 15); cout << "■　　　　　　■■■■■■■■■■■■■■■■■■■■■■■■■■■■"; SetColor(9, 15); cout << "□" << endl;	// 34
		cout << "□"; SetColor(0, 15); cout << "■　　　　　　■■■■■■■■■■■■■■■■■■■■■■■■■■■■"; SetColor(9, 15); cout << "□" << endl;	// 35
		cout << "■"; SetColor(0, 15); cout << "■　　　　　　■■■■■■■■■■■■■■■■■■■■■■■■■■■■"; SetColor(9, 15); cout << "■" << endl;	// 36
		cout << "■■□□□■■■□□□■■■□□□■■■□□□■■■□□□■■■□□□■■" << endl;	// 37
	}
	break;
	case 4:
	{
		gotoxy(0, 0);
		SetColor(9, 15);

		cout << "■■□□□■■■□□□■■■□□□■■■□□□■■■□□□■■■□□□■■" << endl;	// 1
		cout << "■"; SetColor(0, 15); cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■"; SetColor(9, 15); cout << "■" << endl;	// 2
		cout << "□"; SetColor(0, 15); cout << "■■■■■■■■■　　　　　■■■■■■■■■■■■■■■　　　　　■"; SetColor(9, 15); cout << "□" << endl;	// 3
		cout << "□"; SetColor(0, 15); cout << "■■■■■■■■■　　　　　■■■■■■■■■■■■■■■　호랑이　■"; SetColor(9, 15); cout << "□" << endl;	// 4
		cout << "□"; SetColor(0, 15); cout << "■■■■■■■■■　　　　　■■■■■■■■■■■■■■■　바　위　■"; SetColor(9, 15); cout << "□" << endl;	// 5
		cout << "■"; SetColor(0, 15); cout << "■■■■■■■■■　■■■　■■■■■■■■■■■■■■■　산　길　■"; SetColor(9, 15); cout << "■" << endl;	// 6
		cout << "■"; SetColor(0, 15); cout << "■■■■■■■■■　■　■　■■■■■■■■■■■■■■■　　　　　■"; SetColor(9, 15); cout << "■" << endl;	// 7
		cout << "■"; SetColor(0, 15); cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■"; SetColor(9, 15); cout << "■" << endl;	// 8
		cout << "□"; SetColor(0, 15); cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　■■■■■■■"; SetColor(9, 15); cout << "□" << endl;	// 9
		cout << "□"; SetColor(0, 15); cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■■■■■■"; SetColor(9, 15); cout << "□" << endl;	// 10
		cout << "□"; SetColor(0, 15); cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■■■■■■"; SetColor(9, 15); cout << "□" << endl;	// 11
		cout << "■"; SetColor(0, 15); cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■■■■■"; SetColor(9, 15); cout << "■" << endl;	// 12
		cout << "■"; SetColor(0, 15); cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■■■■"; SetColor(9, 15); cout << "■" << endl;	// 13
		cout << "■"; SetColor(0, 15); cout << "■■■■■■■■■■■■■■■■■■■■■■■■■　　　　　　　■■■"; SetColor(9, 15); cout << "■" << endl;	// 14
		cout << "□"; SetColor(0, 15); cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■　　　　　　■■■"; SetColor(9, 15); cout << "□" << endl;	// 15
		cout << "□"; SetColor(0, 15); cout << "■■■■　　　　　　　　　　　　　　　　　　　　　　　　　　　　■■■"; SetColor(9, 15); cout << "□" << endl;   // 16  
		cout << "□"; SetColor(0, 15); cout << "■■■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■■■"; SetColor(9, 15); cout << "□" << endl;   // 17
		cout << "■"; SetColor(0, 15); cout << "■■■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■■■"; SetColor(9, 15); cout << "■" << endl;	// 18
		cout << "■"; SetColor(0, 15); cout << "■■■　　　　　　　　　　　　　　　　　　　　　　　　　　　　■■■■"; SetColor(9, 15); cout << "■" << endl;   // 19
		cout << "■"; SetColor(0, 15); cout << "■■■　　　　　　■■■■■■■■■■■■■■■■■■■■■■■■■■"; SetColor(9, 15); cout << "■" << endl;	// 20
		cout << "□"; SetColor(0, 15); cout << "■■■　　　　　　　■■■■■■■■■■■■■■■■■■■■■■■■■"; SetColor(9, 15); cout << "□" << endl;	// 21
		cout << "□"; SetColor(0, 15); cout << "■■■　　　"; SetColor(14, 15); cout << "　■　"; SetColor(0, 15); cout << "　　　　　　　　　　　　　　　　　　　■■■■■■■"; SetColor(9, 15); cout << "□" << endl;	// 22
		cout << "□"; SetColor(0, 15); cout << "■■■■　　"; SetColor(14, 15); cout << "■■■"; SetColor(0, 15); cout << "　　　　　　　　　　　　　　　　　　　　■■■■■■"; SetColor(9, 15); cout << "□" << endl;	// 23
		cout << "■"; SetColor(0, 15); cout << "■■■■■　"; SetColor(14, 15); cout << "　■　"; SetColor(0, 15); cout << "　　　　　　　　　　　　　　　　　　　　　■■■■■"; SetColor(9, 15); cout << "■" << endl;	// 24
		cout << "■"; SetColor(0, 15); cout << "■■■■■　"; SetColor(14, 15); cout << "■　■"; SetColor(0, 15); cout << "　　　　　　　　　　　　　　　　　　　　　　■■■■"; SetColor(9, 15); cout << "■" << endl;	// 25
		cout << "■"; SetColor(0, 15); cout << "■■■■■■■■■■■■■■■■■■■■■■■■■　　　　　　■■■■"; SetColor(9, 15); cout << "■" << endl;	// 26
		cout << "□"; SetColor(0, 15); cout << "■■■■■■　　　　　　　　　　　　　　　　　　　　　　　　　■■■■"; SetColor(9, 15); cout << "□" << endl;	// 27
		cout << "□"; SetColor(0, 15); cout << "■■■■■　　　　　　　　　　　　　　　　　　　　　　　　　■■■■■"; SetColor(9, 15); cout << "□" << endl;	// 28
		cout << "□"; SetColor(0, 15); cout << "■■■■　　　　　　　　　　　　　　　　　　　　　　　　　■■■■■■"; SetColor(9, 15); cout << "□" << endl;	// 29
		cout << "■"; SetColor(0, 15); cout << "■■■　　　　　　　　　　　　　　　　　　　　　　　　　■■■■■■■"; SetColor(9, 15); cout << "■" << endl;	// 30
		cout << "■"; SetColor(0, 15); cout << "■■　　　　　　　　■■■■■■■■■■■■■■■■■■■■■■■■■"; SetColor(9, 15); cout << "■" << endl;	// 31
		cout << "■"; SetColor(0, 15); cout << "■　　　　　　　　■■■■■■■■■■■■■■■■■■■■■■■■■■"; SetColor(9, 15); cout << "■" << endl;	// 32
		cout << "□"; SetColor(0, 15); cout << "■　　　　　　　■■■■■■■■■■■■■■■■■■■■■■■■■■■"; SetColor(9, 15); cout << "□" << endl;	// 33
		cout << "□"; SetColor(0, 15); cout << "■　　　　　　■■■■■■■■■■■■■■■■■■■■■■■■■■■■"; SetColor(9, 15); cout << "□" << endl;	// 34
		cout << "□"; SetColor(0, 15); cout << "■　　　　　　■■■■■■■■■■■■■■■■■■■■■■■■■■■■"; SetColor(9, 15); cout << "□" << endl;	// 35
		cout << "■"; SetColor(0, 15); cout << "■　　　　　　■■■■■■■■■■■■■■■■■■■■■■■■■■■■"; SetColor(9, 15); cout << "■" << endl;	// 36
		cout << "■■□□□■■■□□□■■■□□□■■■□□□■■■□□□■■■□□□■■" << endl;	// 37
	}
	break;
	case 5:
	{
		gotoxy(0, 0);
		SetColor(9, 15);

		cout << "■■□□□■■■□□□■■■□□□■■■□□□■■■□□□■■■□□□■■" << endl;	// 1
		cout << "■"; SetColor(0, 15); cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■"; SetColor(9, 15); cout << "■" << endl;	// 2
		cout << "□"; SetColor(0, 15); cout << "■■■■■■■■■　　　　　■■■■■■■■■■■■■■■　　　　　■"; SetColor(9, 15); cout << "□" << endl;	// 3
		cout << "□"; SetColor(0, 15); cout << "■■■■■■■■■　　　　　■■■■■■■■■■■■■■■　호랑이　■"; SetColor(9, 15); cout << "□" << endl;	// 4
		cout << "□"; SetColor(0, 15); cout << "■■■■■■■■■　　　　　■■■■■■■■■■■■■■■　바　위　■"; SetColor(9, 15); cout << "□" << endl;	// 5
		cout << "■"; SetColor(0, 15); cout << "■■■■■■■■■　■■■　■■■■■■■■■■■■■■■　산　길　■"; SetColor(9, 15); cout << "■" << endl;	// 6
		cout << "■"; SetColor(0, 15); cout << "■■■■■■■■■　■　■　■■■■■■■■■■■■■■■　　　　　■"; SetColor(9, 15); cout << "■" << endl;	// 7
		cout << "■"; SetColor(0, 15); cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■"; SetColor(9, 15); cout << "■" << endl;	// 8
		cout << "□"; SetColor(0, 15); cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　■■■■■■■"; SetColor(9, 15); cout << "□" << endl;	// 9
		cout << "□"; SetColor(0, 15); cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■■■■■■"; SetColor(9, 15); cout << "□" << endl;	// 10
		cout << "□"; SetColor(0, 15); cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■■■■■■"; SetColor(9, 15); cout << "□" << endl;	// 11
		cout << "■"; SetColor(0, 15); cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■■■■■"; SetColor(9, 15); cout << "■" << endl;	// 12
		cout << "■"; SetColor(0, 15); cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■■■■"; SetColor(9, 15); cout << "■" << endl;	// 13
		cout << "■"; SetColor(0, 15); cout << "■■■■■■■■■■■■■■■■■■■■■■■■■　　　　　　　■■■"; SetColor(9, 15); cout << "■" << endl;	// 14
		cout << "□"; SetColor(0, 15); cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■　　　　　　■■■"; SetColor(9, 15); cout << "□" << endl;	// 15
		cout << "□"; SetColor(0, 15); cout << "■■■■　　　　　　　　　　　　　　　　　　　　　　　　　　　　■■■"; SetColor(9, 15); cout << "□" << endl;   // 16  
		cout << "□"; SetColor(0, 15); cout << "■■■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■■■"; SetColor(9, 15); cout << "□" << endl;   // 17
		cout << "■"; SetColor(0, 15); cout << "■■■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■■■"; SetColor(9, 15); cout << "■" << endl;	// 18
		cout << "■"; SetColor(0, 15); cout << "■■■　　　　　　　　　　　　　　　　　　　　　　　　　　　　■■■■"; SetColor(9, 15); cout << "■" << endl;   // 19
		cout << "■"; SetColor(0, 15); cout << "■■■　　　　　　■■■■■■■■■■■■■■■■■■■■■■■■■■"; SetColor(9, 15); cout << "■" << endl;	// 20
		cout << "□"; SetColor(0, 15); cout << "■■■　　　　　　　■■■■■■■■■■■■■■■■■■■■■■■■■"; SetColor(9, 15); cout << "□" << endl;	// 21
		cout << "□"; SetColor(0, 15); cout << "■■■　　　　　　　　　　　　　　　　　　　　　　　　　■■■■■■■"; SetColor(9, 15); cout << "□" << endl;	// 22
		cout << "□"; SetColor(0, 15); cout << "■■■■　　　　　　　　　　　　　　　　　　　　　　　　　■■■■■■"; SetColor(9, 15); cout << "□" << endl;	// 23
		cout << "■"; SetColor(0, 15); cout << "■■■■■　　　　　　　　　　　　　　　　　　　　　　　　　■■■■■"; SetColor(9, 15); cout << "■" << endl;	// 24
		cout << "■"; SetColor(0, 15); cout << "■■■■■　　　　　　　　　　　　　　　　　　　　　　　　　　■■■■"; SetColor(9, 15); cout << "■" << endl;	// 25
		cout << "■"; SetColor(0, 15); cout << "■■■■■■■■■■■■■■■■■■■■■■■■■　　　　　　■■■■"; SetColor(9, 15); cout << "■" << endl;	// 26
		cout << "□"; SetColor(0, 15); cout << "■■■■■■　　　　　　　　　　　　　　　　　　　"; SetColor(14, 15); cout << "　■　"; SetColor(0, 15); cout << "　　　■■■■"; SetColor(9, 15); cout << "□" << endl;	// 27
		cout << "□"; SetColor(0, 15); cout << "■■■■■　　　　　　　　　　　　　　　　　　　　"; SetColor(14, 15); cout << "■■■"; SetColor(0, 15); cout << "　　■■■■■"; SetColor(9, 15); cout << "□" << endl;	// 28
		cout << "□"; SetColor(0, 15); cout << "■■■■　　　　　　　　　　　　　　　　　　　　　"; SetColor(14, 15); cout << "　■　"; SetColor(0, 15); cout << "　■■■■■■"; SetColor(9, 15); cout << "□" << endl;	// 29
		cout << "■"; SetColor(0, 15); cout << "■■■　　　　　　　　　　　　　　　　　　　　　　"; SetColor(14, 15); cout << "■　■"; SetColor(0, 15); cout << "■■■■■■■"; SetColor(9, 15); cout << "■" << endl;	// 30
		cout << "■"; SetColor(0, 15); cout << "■■　　　　　　　　■■■■■■■■■■■■■■■■■■■■■■■■■"; SetColor(9, 15); cout << "■" << endl;	// 31
		cout << "■"; SetColor(0, 15); cout << "■　　　　　　　　■■■■■■■■■■■■■■■■■■■■■■■■■■"; SetColor(9, 15); cout << "■" << endl;	// 32
		cout << "□"; SetColor(0, 15); cout << "■　　　　　　　■■■■■■■■■■■■■■■■■■■■■■■■■■■"; SetColor(9, 15); cout << "□" << endl;	// 33
		cout << "□"; SetColor(0, 15); cout << "■　　　　　　■■■■■■■■■■■■■■■■■■■■■■■■■■■■"; SetColor(9, 15); cout << "□" << endl;	// 34
		cout << "□"; SetColor(0, 15); cout << "■　　　　　　■■■■■■■■■■■■■■■■■■■■■■■■■■■■"; SetColor(9, 15); cout << "□" << endl;	// 35
		cout << "■"; SetColor(0, 15); cout << "■　　　　　　■■■■■■■■■■■■■■■■■■■■■■■■■■■■"; SetColor(9, 15); cout << "■" << endl;	// 36
		cout << "■■□□□■■■□□□■■■□□□■■■□□□■■■□□□■■■□□□■■" << endl;	// 37
	}
	break;
	case 6:
	{
		gotoxy(0, 0);
		SetColor(9, 15);

		cout << "■■□□□■■■□□□■■■□□□■■■□□□■■■□□□■■■□□□■■" << endl;	// 1
		cout << "■"; SetColor(0, 15); cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■"; SetColor(9, 15); cout << "■" << endl;	// 2
		cout << "□"; SetColor(0, 15); cout << "■■■■■■■■■　　　　　■■■■■■■■■■■■■■■　　　　　■"; SetColor(9, 15); cout << "□" << endl;	// 3
		cout << "□"; SetColor(0, 15); cout << "■■■■■■■■■　　　　　■■■■■■■■■■■■■■■　　　　　■"; SetColor(9, 15); cout << "□" << endl;	// 4
		cout << "□"; SetColor(0, 15); cout << "■■■■■■■■■　　　　　■■■■■■■■■■■■■■■　하　산　■"; SetColor(9, 15); cout << "□" << endl;	// 5
		cout << "■"; SetColor(0, 15); cout << "■■■■■■■■■　■■■　■■■■■■■■■■■■■■■　　　　　■"; SetColor(9, 15); cout << "■" << endl;	// 6
		cout << "■"; SetColor(0, 15); cout << "■■■■■■■■■　■　■　■■■■■■■■■■■■■■■　　　　　■"; SetColor(9, 15); cout << "■" << endl;	// 7
		cout << "■"; SetColor(0, 15); cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■"; SetColor(9, 15); cout << "■" << endl;	// 8
		cout << "□"; SetColor(0, 15); cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　■■■■■■■"; SetColor(9, 15); cout << "□" << endl;	// 9
		cout << "□"; SetColor(0, 15); cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■■■■■■"; SetColor(9, 15); cout << "□" << endl;	// 10
		cout << "□"; SetColor(0, 15); cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■■■■■■"; SetColor(9, 15); cout << "□" << endl;	// 11
		cout << "■"; SetColor(0, 15); cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■■■■■"; SetColor(9, 15); cout << "■" << endl;	// 12
		cout << "■"; SetColor(0, 15); cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■■■■"; SetColor(9, 15); cout << "■" << endl;	// 13
		cout << "■"; SetColor(0, 15); cout << "■■■■■■■■■■■■■■■■■■■■■■■■■　　　　　　　■■■"; SetColor(9, 15); cout << "■" << endl;	// 14
		cout << "□"; SetColor(0, 15); cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■　　　　　　■■■"; SetColor(9, 15); cout << "□" << endl;	// 15
		cout << "□"; SetColor(0, 15); cout << "■■■■　　　　　　　　　　　　　　　　　　　　　　　　　　　　■■■"; SetColor(9, 15); cout << "□" << endl;   // 16  
		cout << "□"; SetColor(0, 15); cout << "■■■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■■■"; SetColor(9, 15); cout << "□" << endl;   // 17
		cout << "■"; SetColor(0, 15); cout << "■■■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■■■"; SetColor(9, 15); cout << "■" << endl;	// 18
		cout << "■"; SetColor(0, 15); cout << "■■■　　　　　　　　　　　　　　　　　　　　　　　　　　　　■■■■"; SetColor(9, 15); cout << "■" << endl;   // 19
		cout << "■"; SetColor(0, 15); cout << "■■■　　　　　　■■■■■■■■■■■■■■■■■■■■■■■■■■"; SetColor(9, 15); cout << "■" << endl;	// 20
		cout << "□"; SetColor(0, 15); cout << "■■■　　　　　　　■■■■■■■■■■■■■■■■■■■■■■■■■"; SetColor(9, 15); cout << "□" << endl;	// 21
		cout << "□"; SetColor(0, 15); cout << "■■■　　　　　　　　　　　　　　　　　　　　　　　　　■■■■■■■"; SetColor(9, 15); cout << "□" << endl;	// 22
		cout << "□"; SetColor(0, 15); cout << "■■■■　　　　　　　　　　　　　　　　　　　　　　　　　■■■■■■"; SetColor(9, 15); cout << "□" << endl;	// 23
		cout << "■"; SetColor(0, 15); cout << "■■■■■　　　　　　　　　　　　　　　　　　　　　　　　　■■■■■"; SetColor(9, 15); cout << "■" << endl;	// 24
		cout << "■"; SetColor(0, 15); cout << "■■■■■　　　　　　　　　　　　　　　　　　　　　　　　　　■■■■"; SetColor(9, 15); cout << "■" << endl;	// 25
		cout << "■"; SetColor(0, 15); cout << "■■■■■■■■■■■■■■■■■■■■■■■■■　　　　　　■■■■"; SetColor(9, 15); cout << "■" << endl;	// 26
		cout << "□"; SetColor(0, 15); cout << "■■■■■■　　　　　　　　　　　　　　　　　　　　　　　　　■■■■"; SetColor(9, 15); cout << "□" << endl;	// 27
		cout << "□"; SetColor(0, 15); cout << "■■■■■　　　　　　　　　　　　　　　　　　　　　　　　　■■■■■"; SetColor(9, 15); cout << "□" << endl;	// 28
		cout << "□"; SetColor(0, 15); cout << "■■■■　　　　　　　　　　　　　　　　　　　　　　　　　■■■■■■"; SetColor(9, 15); cout << "□" << endl;	// 29
		cout << "■"; SetColor(0, 15); cout << "■■■　　　　　　　　　　　　　　　　　　　　　　　　　■■■■■■■"; SetColor(9, 15); cout << "■" << endl;	// 30
		cout << "■"; SetColor(0, 15); cout << "■■　　　　　　　　■■■■■■■■■■■■■■■■■■■■■■■■■"; SetColor(9, 15); cout << "■" << endl;	// 31
		cout << "■"; SetColor(0, 15); cout << "■　　　　　　　　■■■■■■■■■■■■■■■■■■■■■■■■■■"; SetColor(9, 15); cout << "■" << endl;	// 32
		cout << "□"; SetColor(0, 15); cout << "■　"; SetColor(14, 15); cout << "　■　"; SetColor(0, 15); cout << "　　　■■■■■■■■■■■■■■■■■■■■■■■■■■■"; SetColor(9, 15); cout << "□" << endl;	// 33
		cout << "□"; SetColor(0, 15); cout << "■　"; SetColor(14, 15); cout << "■■■"; SetColor(0, 15); cout << "　　■■■■■■■■■■■■■■■■■■■■■■■■■■■■"; SetColor(9, 15); cout << "□" << endl;	// 34
		cout << "□"; SetColor(0, 15); cout << "■　"; SetColor(14, 15); cout << "　■　"; SetColor(0, 15); cout << "　　■■■■■■■■■■■■■■■■■■■■■■■■■■■■"; SetColor(9, 15); cout << "□" << endl;	// 35
		cout << "■"; SetColor(0, 15); cout << "■　"; SetColor(14, 15); cout << "■　■"; SetColor(0, 15); cout << "　　■■■■■■■■■■■■■■■■■■■■■■■■■■■■"; SetColor(9, 15); cout << "■" << endl;	// 36
		cout << "■■□□□■■■□□□■■■□□□■■■□□□■■■□□□■■■□□□■■" << endl;	// 37
	}
	break;
	}
}

void mainGame::SeedScreen()
{
	gotoxy(0, 26);

	switch (_seedcheck)
	{
	case 1:
	{
		SetColor(13, 15);

		cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;
		cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
		cout << "■"; SetColor(0, 15); cout << "　　약초 씨앗을 심으시겠습니까?　　 　　　　　　　　　　　　　　　　　"; SetColor(13, 15); cout << "■" << endl;
		cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
		cout << "■"; SetColor(0, 15); cout << "　　▶　심는다　　　　　　　　　　　　　　　　　　　　　　　　　　　　"; SetColor(13, 15); cout << "■" << endl;
		cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
		cout << "■"; SetColor(0, 15); cout << "　　　　나가기　　　　　　　　　　　　　　　　　　　　　　　　　　　　"; SetColor(13, 15); cout << "■" << endl;
		cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
		cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
		cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
		cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;
	}
	break;
	case 2:
	{
		SetColor(13, 15);

		cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;
		cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
		cout << "■"; SetColor(0, 15); cout << "　　약초 씨앗을 심으시겠습니까?　　 　　　　　　　　　　　　　　　　　"; SetColor(13, 15); cout << "■" << endl;
		cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
		cout << "■"; SetColor(0, 15); cout << "　　　　심는다　　　　　　　　　　　　　　　　　　　　　　　　　　　　"; SetColor(13, 15); cout << "■" << endl;
		cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
		cout << "■"; SetColor(0, 15); cout << "　　▶　나가기　　　　　　　　　　　　　　　　　　　　　　　　　　　　"; SetColor(13, 15); cout << "■" << endl;
		cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
		cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
		cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
		cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;
	}
	break;
	case 3:
	{
		SetColor(13, 15);

		cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;
		cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
		cout << "■"; SetColor(0, 15); cout << "　　현재 이미 재배중입니다. 　　　　　　　　　　　　　　　　　　　　　"; SetColor(13, 15); cout << "■" << endl;
		cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
		cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
		cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
		cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
		cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
		cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
		cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
		cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;
	}
	break;
	case 4:
	{
		SetColor(13, 15);

		cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;
		cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
		cout << "■"; SetColor(0, 15); cout << "　　수확이 완료되었습니다.　　　　　　　　　　　　　　　　　　　　　　"; SetColor(13, 15); cout << "■" << endl;
		cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
		cout << "■"; SetColor(0, 15); cout << "　　약초를 얻었습니다!　　　　　　　　　　　　　　　　　　　　　　　　"; SetColor(13, 15); cout << "■" << endl;
		cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
		cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
		cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
		cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
		cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
		cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;
	}
	break;
	case 5:
	{
		SetColor(13, 15);

		cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;
		cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
		cout << "■"; SetColor(0, 15); cout << "　　약초씨앗을 심었습니다.　　　　　　　　　　　　　　　　　　　　　　"; SetColor(13, 15); cout << "■" << endl;
		cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
		cout << "■"; SetColor(0, 15); cout << "　　재배에 걸리는 시간은 3분입니다. 　　　　　　　　　　　　　　　　　"; SetColor(13, 15); cout << "■" << endl;
		cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
		cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
		cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
		cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
		cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
		cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;
	}
	break;
	case 6:
	{
		SetColor(13, 15);

		cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;
		cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
		cout << "■"; SetColor(0, 15); cout << "　　약초씨가 부족합니다..　　　　 　　　　　　　　　　　　　　　　　　"; SetColor(13, 15); cout << "■" << endl;
		cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
		cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
		cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
		cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
		cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
		cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
		cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
		cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;
	}
	break;
	}
}

void mainGame::SeedChoice()
{
	_key = '0';
	_key = _getch();

	if (_key == (char)UP)
	{
		if (_seedcheck == 2)
		{
			_seedcheck = 1;
			SeedScreen();
			SeedChoice();
		}
		else
		{
			SeedChoice();
		}
	}
	else if (_key == (char)DOWN)
	{
		if (_seedcheck == 1)
		{
			_seedcheck = 2;
			SeedScreen();
			SeedChoice();
		}
		else
		{
			SeedChoice();
		}
	}
	else if (_key == (char)ENTER || _key == (char)SPACE)
	{
		if (_seedcheck == 1)
		{
			if (_characterSeed > 0)
			{
				--_characterSeed;
				b_seed1 = true;
				_seedcheck = 5;
				SeedScreen();
				SeedChoice();
			}
			else
			{
				_seedcheck = 6;
				SeedScreen();
				SeedChoice();
			}
		}
		else if (_seedcheck == 2 || _seedcheck == 3 || _seedcheck == 5 || _seedcheck == 6)
		{
			_key = '0';
			_seedcheck = 0;
			FarmScreen();
			FarmChoice();
		}
		else if (_seedcheck == 4)
		{
			_seed1 = 0;
			hb->SetHowMany(hb->GetHowMany() + 1);
			_seedcheck = 0;
			FarmScreen();
			FarmChoice();
		}
	}
	else
	{
		SeedChoice();
	}
}
void mainGame::FarmChoice()
{
	_key = '0';
	_key = _getch();

	if (_key == (char)LEFT)
	{
		switch (_farmcheck)
		{
		case 1:
		case 2:
		case 3:
		{
			_farmcheck = 7;
			FarmScreen();
			FarmChoice();
		}
		break;
		case 4:
		{
			_farmcheck = 1;
			FarmScreen();
			FarmChoice();
		}
		break;
		case 5:
		{
			_farmcheck = 2;
			FarmScreen();
			FarmChoice();
		}
		break;
		case 6:
		{
			_farmcheck = 3;
			FarmScreen();
			FarmChoice();
		}
		break;
		case 7:
		{
			_farmcheck = 8;
			FarmScreen();
			FarmChoice();
		}
		break;
		case 8:
		{
			_farmcheck = 7;
			FarmScreen();
			FarmChoice();
		}
		break;
		default:
		{
			FarmChoice();
		}
		break;
		}
	}
	else if (_key == (char)RIGHT)
	{
		switch (_farmcheck)
		{
		case 1:
		case 5:
		{
			_farmcheck = 4;
			FarmScreen();
			FarmChoice();
		}
		break;
		case 2:
		case 6:
		{
			_farmcheck = 5;
			FarmScreen();
			FarmChoice();
		}
		break;
		case 3:
		{
			_farmcheck = 6;
			FarmScreen();
			FarmChoice();
		}
		break;
		case 7:
		{
			_farmcheck = 3;
			FarmScreen();
			FarmChoice();
		}
		break;
		default:
		{
			FarmChoice();
		}
		break;
		}
	}
	else if (_key == (char)UP)
	{
		switch (_farmcheck)
		{
		case 1:
		{
			_farmcheck = 8;
			FarmScreen();
			FarmChoice();
		}
		break;
		case 2:
		{
			_farmcheck = 1;
			FarmScreen();
			FarmChoice();
		}
		break;
		case 3:
		{
			_farmcheck = 2;
			FarmScreen();
			FarmChoice();
		}
		break;
		case 5:
		{
			_farmcheck = 4;
			FarmScreen();
			FarmChoice();
		}
		break;
		case 6:
		{
			_farmcheck = 5;
			FarmScreen();
			FarmChoice();
		}
		break;
		case 7:
		{
			_farmcheck = 2;
			FarmScreen();
			FarmChoice();
		}
		break;
		default:
		{
			FarmChoice();
		}
		break;
		}
	}
	else if (_key == (char)DOWN)
	{
		switch (_farmcheck)
		{
		case 1:
		{
			_farmcheck = 2;
			FarmScreen();
			FarmChoice();
		}
		break;
		case 2:
		{
			_farmcheck = 3;
			FarmScreen();
			FarmChoice();
		}
		break;
		case 4:
		{
			_farmcheck = 5;
			FarmScreen();
			FarmChoice();
		}
		break;
		case 5:
		{
			_farmcheck = 6;
			FarmScreen();
			FarmChoice();
		}
		break;
		case 8:
		{
			_farmcheck = 7;
			FarmScreen();
			FarmChoice();
		}
		break;
		default:
		{
			FarmChoice();
		}
		break;
		}
	}
	else if (_key == (char)ENTER || _key == (char)SPACE)
	{
		switch (_farmcheck)
		{
		case 1:
		case 2:
		case 3:
		case 4:
		case 5:
		case 6:
		{
			if (_seed1 == 1)
			{
				_seedcheck = 4;
				SeedScreen();
				SeedChoice();
			}
			else if (b_seed1 == true)
			{
				_seedcheck = 3;
				SeedScreen();
				SeedChoice();
			}
			else
			{
				_seedcheck = 1;
				SeedScreen();
				SeedChoice();
			}
		}
		break;
		case 7:
		{
			++_doggy;
			if (_doggy == 15)
			{
				DogEvent();
			}
			else
			{
				_effect = Edog;
			}
			FarmChoice();
		}
		break;
		case 8:
		{
			_farmcheck = 0;
			_fieldcheck = 2;
			FieldScreen();
			FieldChoice();
		}
		break;
		default:
		{
			FarmChoice();
		}
		break;
		}
	}
	else if (_key == (char)ESC)
	{
		_statuscheck = 1;
		Status();
	}
	else
	{
		FarmChoice();
	}
}
void mainGame::FarmScreen()
{
	gotoxy(0, 0);
	SetColor(9, 15);

	switch (_farmcheck)
	{
	case 1:
	{
		cout << "■■□□□■■■□□□■■■□□□■■■□□□■■■□□□■■■□□□■■" << endl;	// 1
		cout << "■"; SetColor(0, 15); cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■"; SetColor(9, 15); cout << "■" << endl;	// 2
		cout << "□"; SetColor(0, 15); cout << "■　　　　　■■■■■■■■■■■■■■■■■■■■■■■■■■■■■"; SetColor(9, 15); cout << "□" << endl;	// 3
		cout << "□"; SetColor(0, 15); cout << "■　약　초　■■■■■■■■■■■■■■■■■■■■■■■■■■■■■"; SetColor(9, 15); cout << "□" << endl;	// 4
		cout << "□"; SetColor(0, 15); cout << "■　　　　　■■■■■■■■■■■■■■■■■■■■■■■■■■■■■"; SetColor(9, 15); cout << "□" << endl;	// 5
		cout << "■"; SetColor(0, 15); cout << "■　재　배　■■■■■■■■■■■■■■■■■■■■■■■■■■■■■"; SetColor(9, 15); cout << "■" << endl;	// 6
		cout << "■"; SetColor(0, 15); cout << "■　　　　　■■■■■■■■■■■■■■■■■■■■■■■■■■■■■"; SetColor(9, 15); cout << "■" << endl;	// 7
		cout << "■"; SetColor(0, 15); cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■"; SetColor(9, 15); cout << "■" << endl;	// 8
		cout << "□"; SetColor(0, 15); cout << "■■■■■■■　　　　　　　　　　　　　　　　　　　　　　　　　　　　"; SetColor(9, 15); cout << "□" << endl;	// 9
		cout << "□"; SetColor(0, 15); cout << "■■■■■■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　"; SetColor(9, 15); cout << "□" << endl;	// 10
		cout << "□"; SetColor(0, 15); cout << "■■■■■■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　"; SetColor(9, 15); cout << "□" << endl;	// 11
		cout << "■"; SetColor(0, 15); cout << "■■■■■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　"; SetColor(9, 15); cout << "■" << endl;	// 12
		cout << "■"; SetColor(0, 15); cout << "■■■■■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　"; SetColor(9, 15); cout << "■" << endl;	// 13
		cout << "■"; SetColor(0, 15); cout << "■□□□□　　　　　□□□□□□□□□□□□□□□□□□□■■■■■■"; SetColor(9, 15); cout << "■" << endl;	// 14
		cout << "□"; SetColor(0, 15); cout << "■□　　　　　　　　　　　　　　　　　　　　　　　　　　□■■■■■■"; SetColor(9, 15); cout << "□" << endl;	// 15
		cout << "□"; SetColor(0, 15); cout << "■□　　　　　　　　　　　　　　　　　　　　　　　　　　□■■■■■■"; SetColor(9, 15); cout << "□" << endl;	// 16
		cout << "□"; SetColor(0, 15); cout << "■□"; SetColor(10, 15); cout << "　　　　　　　　　　　　　　"; SetColor(14, 15); cout << "　■　　"; SetColor(0, 15); cout << "　　　　　　　　□■■■■■■"; SetColor(9, 15); cout << "□" << endl;	// 17
		cout << "■"; SetColor(0, 15); cout << "■□"; SetColor(10, 15); cout << "　　　　　　　　　■　■　■"; SetColor(14, 15); cout << "■■■　"; SetColor(10, 15); cout << "■　■　■"; SetColor(0, 15); cout << "　　　□■■■■■■"; SetColor(9, 15); cout << "■" << endl;	// 18
		cout << "■"; SetColor(0, 15); cout << "■□"; SetColor(10, 15); cout << "　　　　　　　　　　■■■　"; SetColor(14, 15); cout << "　■　　"; SetColor(10, 15); cout << "　■■■　"; SetColor(0, 15); cout << "　　　□■■■■■■"; SetColor(9, 15); cout << "■" << endl;	// 19
		cout << "■"; SetColor(0, 15); cout << "■□"; SetColor(10, 15); cout << "　　　　　　　　　　　■　　"; SetColor(14, 15); cout << "■　■　"; SetColor(10, 15); cout << "　　■　　"; SetColor(0, 15); cout << "　　　□■■■■■■"; SetColor(9, 15); cout << "■" << endl;	// 20
		cout << "□"; SetColor(0, 15); cout << "■□　　　　　　　　　　　　　　　　　　　　　　　　　　□■■■■■■"; SetColor(9, 15); cout << "□" << endl;	// 21
		cout << "□"; SetColor(0, 15); cout << "■□　　　　　　　　　　　　　　　　　　　　　　　　　　□■■■■■■"; SetColor(9, 15); cout << "□" << endl;	// 22
		cout << "□"; SetColor(0, 15); cout << "■□　　　　　　　　　　　　　　　　　　　　　　　　　　□■■■■■■"; SetColor(9, 15); cout << "□" << endl;	// 23
		cout << "■"; SetColor(0, 15); cout << "■□"; SetColor(10, 15); cout << "　　　　　　　　　■　■　■　　　　■　■　■　　　"; SetColor(0, 15); cout << "□■■■■■■"; SetColor(9, 15); cout << "■" << endl;	// 24
		cout << "■"; SetColor(0, 15); cout << "■□"; SetColor(10, 15); cout << "　　　　　　　　　　■■■　　　　　　■■■　　　　"; SetColor(0, 15); cout << "□■■■■■■"; SetColor(9, 15); cout << "■" << endl;	// 25
		cout << "■"; SetColor(0, 15); cout << "■□"; SetColor(10, 15); cout << "　　　　　　　　　　　■　　　　　　　　■　　　　　"; SetColor(0, 15); cout << "□■■■■■■"; SetColor(9, 15); cout << "■" << endl;	// 26
		cout << "□"; SetColor(0, 15); cout << "■□　　　　　　　　　　　　　　　　　　　　　　　　　　□■■■■■■"; SetColor(9, 15); cout << "□" << endl;	// 27
		cout << "□"; SetColor(0, 15); cout << "■□　　　　　　　　　　　　　　　　　　　　　　　　　　□■■■■■■"; SetColor(9, 15); cout << "□" << endl;	// 28
		cout << "□"; SetColor(0, 15); cout << "■□　　　　　　　　　　　　　　　　　　　　　　　　　　□■■■■■■"; SetColor(9, 15); cout << "□" << endl;	// 29
		cout << "■"; SetColor(0, 15); cout << "■□"; SetColor(8, 15); cout << "　　　■　"; SetColor(10, 15); cout << "　　　　■　■　■　　　　■　■　■　　　"; SetColor(0, 15); cout << "□■■■■■■"; SetColor(9, 15); cout << "■" << endl;	// 30
		cout << "■"; SetColor(0, 15); cout << "■□"; SetColor(8, 15); cout << "　■■■■"; SetColor(10, 15); cout << "　　　　　■■■　　　　　　■■■　　　　"; SetColor(0, 15); cout << "□■■■■■■"; SetColor(9, 15); cout << "■" << endl;	// 31
		cout << "■"; SetColor(0, 15); cout << "■□"; SetColor(8, 15); cout << "　■　■　"; SetColor(10, 15); cout << "　　　　　　■　　　　　　　　■　　　　　"; SetColor(0, 15); cout << "□■■■■■■"; SetColor(9, 15); cout << "■" << endl;	// 32
		cout << "□"; SetColor(0, 15); cout << "■□　　　　　　　　　　　　　　　　　　　　　　　　　　□■■■■■■"; SetColor(9, 15); cout << "□" << endl;	// 33
		cout << "□"; SetColor(0, 15); cout << "■□　　　　　　　　　　　　　　　　　　　　　　　　　　□■■■■■■"; SetColor(9, 15); cout << "□" << endl;	// 34
		cout << "□"; SetColor(0, 15); cout << "■□□□□□□□□□□□□□□□□□□□□□□□□□□□□■■■■■■"; SetColor(9, 15); cout << "□" << endl;	// 35
		cout << "■"; SetColor(0, 15); cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■"; SetColor(9, 15); cout << "■" << endl;	// 36
		cout << "■■□□□■■■□□□■■■□□□■■■□□□■■■□□□■■■□□□■■" << endl;	// 37
	}
	break;
	case 2:
	{
		cout << "■■□□□■■■□□□■■■□□□■■■□□□■■■□□□■■■□□□■■" << endl;	// 1
		cout << "■"; SetColor(0, 15); cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■"; SetColor(9, 15); cout << "■" << endl;	// 2
		cout << "□"; SetColor(0, 15); cout << "■　　　　　■■■■■■■■■■■■■■■■■■■■■■■■■■■■■"; SetColor(9, 15); cout << "□" << endl;	// 3
		cout << "□"; SetColor(0, 15); cout << "■　약　초　■■■■■■■■■■■■■■■■■■■■■■■■■■■■■"; SetColor(9, 15); cout << "□" << endl;	// 4
		cout << "□"; SetColor(0, 15); cout << "■　　　　　■■■■■■■■■■■■■■■■■■■■■■■■■■■■■"; SetColor(9, 15); cout << "□" << endl;	// 5
		cout << "■"; SetColor(0, 15); cout << "■　재　배　■■■■■■■■■■■■■■■■■■■■■■■■■■■■■"; SetColor(9, 15); cout << "■" << endl;	// 6
		cout << "■"; SetColor(0, 15); cout << "■　　　　　■■■■■■■■■■■■■■■■■■■■■■■■■■■■■"; SetColor(9, 15); cout << "■" << endl;	// 7
		cout << "■"; SetColor(0, 15); cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■"; SetColor(9, 15); cout << "■" << endl;	// 8
		cout << "□"; SetColor(0, 15); cout << "■■■■■■■　　　　　　　　　　　　　　　　　　　　　　　　　　　　"; SetColor(9, 15); cout << "□" << endl;	// 9
		cout << "□"; SetColor(0, 15); cout << "■■■■■■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　"; SetColor(9, 15); cout << "□" << endl;	// 10
		cout << "□"; SetColor(0, 15); cout << "■■■■■■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　"; SetColor(9, 15); cout << "□" << endl;	// 11
		cout << "■"; SetColor(0, 15); cout << "■■■■■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　"; SetColor(9, 15); cout << "■" << endl;	// 12
		cout << "■"; SetColor(0, 15); cout << "■■■■■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　"; SetColor(9, 15); cout << "■" << endl;	// 13
		cout << "■"; SetColor(0, 15); cout << "■□□□□　　　　　□□□□□□□□□□□□□□□□□□□■■■■■■"; SetColor(9, 15); cout << "■" << endl;	// 14
		cout << "□"; SetColor(0, 15); cout << "■□　　　　　　　　　　　　　　　　　　　　　　　　　　□■■■■■■"; SetColor(9, 15); cout << "□" << endl;	// 15
		cout << "□"; SetColor(0, 15); cout << "■□　　　　　　　　　　　　　　　　　　　　　　　　　　□■■■■■■"; SetColor(9, 15); cout << "□" << endl;	// 16
		cout << "□"; SetColor(0, 15); cout << "■□　　　　　　　　　　　　　　　　　　　　　　　　　　□■■■■■■"; SetColor(9, 15); cout << "□" << endl;	// 17
		cout << "■"; SetColor(0, 15); cout << "■□　　　　　　　　　"; SetColor(10, 15); cout << "■　■　■　　　　■　■　■　　　"; SetColor(0, 15); cout << "□■■■■■■"; SetColor(9, 15); cout << "■" << endl;	// 18
		cout << "■"; SetColor(0, 15); cout << "■□　　　　　　　　　"; SetColor(10, 15); cout << "　■■■　　　　　　■■■　　　　"; SetColor(0, 15); cout << "□■■■■■■"; SetColor(9, 15); cout << "■" << endl;	// 19
		cout << "■"; SetColor(0, 15); cout << "■□　　　　　　　　　"; SetColor(10, 15); cout << "　　■　　　　　　　　■　　　　　"; SetColor(0, 15); cout << "□■■■■■■"; SetColor(9, 15); cout << "■" << endl;	// 20
		cout << "□"; SetColor(0, 15); cout << "■□　　　　　　　　　　　　　　　　　　　　　　　　　　□■■■■■■"; SetColor(9, 15); cout << "□" << endl;	// 21
		cout << "□"; SetColor(0, 15); cout << "■□　　　　　　　　　　　　　　　　　　　　　　　　　　□■■■■■■"; SetColor(9, 15); cout << "□" << endl;	// 22
		cout << "□"; SetColor(0, 15); cout << "■□　　　　　　　　　　　　　　"; SetColor(14, 15); cout << "　■　　　　　　　　　　"; SetColor(0, 15); cout << "□■■■■■■"; SetColor(9, 15); cout << "□" << endl;	// 23
		cout << "■"; SetColor(0, 15); cout << "■□　　　　　　　　　"; SetColor(10, 15); cout << "■　■　■"; SetColor(14, 15); cout << "■■■　"; SetColor(10, 15); cout << "■　■　■　　　"; SetColor(0, 15); cout << "□■■■■■■"; SetColor(9, 15); cout << "■" << endl;	// 24
		cout << "■"; SetColor(0, 15); cout << "■□　　　　　　　　　"; SetColor(10, 15); cout << "　■■■　"; SetColor(14, 15); cout << "　■　　"; SetColor(10, 15); cout << "　■■■　　　　"; SetColor(0, 15); cout << "□■■■■■■"; SetColor(9, 15); cout << "■" << endl;	// 25
		cout << "■"; SetColor(0, 15); cout << "■□　　　　　　　　　"; SetColor(10, 15); cout << "　　■　　"; SetColor(14, 15); cout << "■　■　"; SetColor(10, 15); cout << "　　■　　　　　"; SetColor(0, 15); cout << "□■■■■■■"; SetColor(9, 15); cout << "■" << endl;	// 26
		cout << "□"; SetColor(0, 15); cout << "■□　　　　　　　　　　　　　　　　　　　　　　　　　　□■■■■■■"; SetColor(9, 15); cout << "□" << endl;	// 27
		cout << "□"; SetColor(0, 15); cout << "■□　　　　　　　　　　　　　　　　　　　　　　　　　　□■■■■■■"; SetColor(9, 15); cout << "□" << endl;	// 28
		cout << "□"; SetColor(0, 15); cout << "■□　　　　　　　　　　　　　　　　　　　　　　　　　　□■■■■■■"; SetColor(9, 15); cout << "□" << endl;	// 29
		cout << "■"; SetColor(0, 15); cout << "■□　"; SetColor(8, 15); cout << "　　■　　　　　"; SetColor(10, 15); cout << "■　■　■　　　　■　■　■　　　"; SetColor(0, 15); cout << "□■■■■■■"; SetColor(9, 15); cout << "■" << endl;	// 30
		cout << "■"; SetColor(0, 15); cout << "■□　"; SetColor(8, 15); cout << "■■■■　　　　"; SetColor(10, 15); cout << "　■■■　　　　　　■■■　　　　"; SetColor(0, 15); cout << "□■■■■■■"; SetColor(9, 15); cout << "■" << endl;	// 31
		cout << "■"; SetColor(0, 15); cout << "■□　"; SetColor(8, 15); cout << "■　■　　　　　"; SetColor(10, 15); cout << "　　■　　　　　　　　■　　　　　"; SetColor(0, 15); cout << "□■■■■■■"; SetColor(9, 15); cout << "■" << endl;	// 32
		cout << "□"; SetColor(0, 15); cout << "■□　　　　　　　　　　　　　　　　　　　　　　　　　　□■■■■■■"; SetColor(9, 15); cout << "□" << endl;	// 33
		cout << "□"; SetColor(0, 15); cout << "■□　　　　　　　　　　　　　　　　　　　　　　　　　　□■■■■■■"; SetColor(9, 15); cout << "□" << endl;	// 34
		cout << "□"; SetColor(0, 15); cout << "■□□□□□□□□□□□□□□□□□□□□□□□□□□□□■■■■■■"; SetColor(9, 15); cout << "□" << endl;	// 35
		cout << "■"; SetColor(0, 15); cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■"; SetColor(9, 15); cout << "■" << endl;	// 36
		cout << "■■□□□■■■□□□■■■□□□■■■□□□■■■□□□■■■□□□■■" << endl;	// 37

	}
	break;
	case 3:
	{
		cout << "■■□□□■■■□□□■■■□□□■■■□□□■■■□□□■■■□□□■■" << endl;	// 1
		cout << "■"; SetColor(0, 15); cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■"; SetColor(9, 15); cout << "■" << endl;	// 2
		cout << "□"; SetColor(0, 15); cout << "■　　　　　■■■■■■■■■■■■■■■■■■■■■■■■■■■■■"; SetColor(9, 15); cout << "□" << endl;	// 3
		cout << "□"; SetColor(0, 15); cout << "■　약　초　■■■■■■■■■■■■■■■■■■■■■■■■■■■■■"; SetColor(9, 15); cout << "□" << endl;	// 4
		cout << "□"; SetColor(0, 15); cout << "■　　　　　■■■■■■■■■■■■■■■■■■■■■■■■■■■■■"; SetColor(9, 15); cout << "□" << endl;	// 5
		cout << "■"; SetColor(0, 15); cout << "■　재　배　■■■■■■■■■■■■■■■■■■■■■■■■■■■■■"; SetColor(9, 15); cout << "■" << endl;	// 6
		cout << "■"; SetColor(0, 15); cout << "■　　　　　■■■■■■■■■■■■■■■■■■■■■■■■■■■■■"; SetColor(9, 15); cout << "■" << endl;	// 7
		cout << "■"; SetColor(0, 15); cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■"; SetColor(9, 15); cout << "■" << endl;	// 8
		cout << "□"; SetColor(0, 15); cout << "■■■■■■■　　　　　　　　　　　　　　　　　　　　　　　　　　　　"; SetColor(9, 15); cout << "□" << endl;	// 9
		cout << "□"; SetColor(0, 15); cout << "■■■■■■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　"; SetColor(9, 15); cout << "□" << endl;	// 10
		cout << "□"; SetColor(0, 15); cout << "■■■■■■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　"; SetColor(9, 15); cout << "□" << endl;	// 11
		cout << "■"; SetColor(0, 15); cout << "■■■■■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　"; SetColor(9, 15); cout << "■" << endl;	// 12
		cout << "■"; SetColor(0, 15); cout << "■■■■■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　"; SetColor(9, 15); cout << "■" << endl;	// 13
		cout << "■"; SetColor(0, 15); cout << "■□□□□　　　　　□□□□□□□□□□□□□□□□□□□■■■■■■"; SetColor(9, 15); cout << "■" << endl;	// 14
		cout << "□"; SetColor(0, 15); cout << "■□　　　　　　　　　　　　　　　　　　　　　　　　　　□■■■■■■"; SetColor(9, 15); cout << "□" << endl;	// 15
		cout << "□"; SetColor(0, 15); cout << "■□　　　　　　　　　　　　　　　　　　　　　　　　　　□■■■■■■"; SetColor(9, 15); cout << "□" << endl;	// 16
		cout << "□"; SetColor(0, 15); cout << "■□　　　　　　　　　　　　　　　　　　　　　　　　　　□■■■■■■"; SetColor(9, 15); cout << "□" << endl;	// 17
		cout << "■"; SetColor(0, 15); cout << "■□　　　　　　　　　"; SetColor(10, 15); cout << "■　■　■　　　　■　■　■　　　"; SetColor(0, 15); cout << "□■■■■■■"; SetColor(9, 15); cout << "■" << endl;	// 18
		cout << "■"; SetColor(0, 15); cout << "■□　　　　　　　　　"; SetColor(10, 15); cout << "　■■■　　　　　　■■■　　　　"; SetColor(0, 15); cout << "□■■■■■■"; SetColor(9, 15); cout << "■" << endl;	// 19
		cout << "■"; SetColor(0, 15); cout << "■□　　　　　　　　　"; SetColor(10, 15); cout << "　　■　　　　　　　　■　　　　　"; SetColor(0, 15); cout << "□■■■■■■"; SetColor(9, 15); cout << "■" << endl;	// 20
		cout << "□"; SetColor(0, 15); cout << "■□　　　　　　　　　　　　　　　　　　　　　　　　　　□■■■■■■"; SetColor(9, 15); cout << "□" << endl;	// 21
		cout << "□"; SetColor(0, 15); cout << "■□　　　　　　　　　　　　　　　　　　　　　　　　　　□■■■■■■"; SetColor(9, 15); cout << "□" << endl;	// 22
		cout << "□"; SetColor(0, 15); cout << "■□　　　　　　　　　　　　　　　　　　　　　　　　　　□■■■■■■"; SetColor(9, 15); cout << "□" << endl;	// 23
		cout << "■"; SetColor(0, 15); cout << "■□　　　　　　　　　"; SetColor(10, 15); cout << "■　■　■　　　　■　■　■　　　"; SetColor(0, 15); cout << "□■■■■■■"; SetColor(9, 15); cout << "■" << endl;	// 24
		cout << "■"; SetColor(0, 15); cout << "■□　　　　　　　　　"; SetColor(10, 15); cout << "　■■■　　　　　　■■■　　　　"; SetColor(0, 15); cout << "□■■■■■■"; SetColor(9, 15); cout << "■" << endl;	// 25
		cout << "■"; SetColor(0, 15); cout << "■□　　　　　　　　　"; SetColor(10, 15); cout << "　　■　　　　　　　　■　　　　　"; SetColor(0, 15); cout << "□■■■■■■"; SetColor(9, 15); cout << "■" << endl;	// 26
		cout << "□"; SetColor(0, 15); cout << "■□　　　　　　　　　　　　　　　　　　　　　　　　　　□■■■■■■"; SetColor(9, 15); cout << "□" << endl;	// 27
		cout << "□"; SetColor(0, 15); cout << "■□　　　　　　　　　　　　　　　　　　　　　　　　　　□■■■■■■"; SetColor(9, 15); cout << "□" << endl;	// 28
		cout << "□"; SetColor(0, 15); cout << "■□　　　　　　　　　　　　　　"; SetColor(14, 15); cout << "　■　　　　　　　　　　"; SetColor(0, 15); cout << "□■■■■■■"; SetColor(9, 15); cout << "□" << endl;	// 29
		cout << "■"; SetColor(0, 15); cout << "■□　"; SetColor(8, 15); cout << "　　■　　　　　"; SetColor(10, 15); cout << "■　■　■"; SetColor(14, 15); cout << "■■■　"; SetColor(10, 15); cout << "■　■　■　　　"; SetColor(0, 15); cout << "□■■■■■■"; SetColor(9, 15); cout << "■" << endl;	// 30
		cout << "■"; SetColor(0, 15); cout << "■□　"; SetColor(8, 15); cout << "■■■■　　　　"; SetColor(10, 15); cout << "　■■■　"; SetColor(14, 15); cout << "　■　　"; SetColor(10, 15); cout << "　■■■　　　　"; SetColor(0, 15); cout << "□■■■■■■"; SetColor(9, 15); cout << "■" << endl;	// 31
		cout << "■"; SetColor(0, 15); cout << "■□　"; SetColor(8, 15); cout << "■　■　　　　　"; SetColor(10, 15); cout << "　　■　　"; SetColor(14, 15); cout << "■　■　"; SetColor(10, 15); cout << "　　■　　　　　"; SetColor(0, 15); cout << "□■■■■■■"; SetColor(9, 15); cout << "■" << endl;	// 32
		cout << "□"; SetColor(0, 15); cout << "■□　　　　　　　　　　　　　　　　　　　　　　　　　　□■■■■■■"; SetColor(9, 15); cout << "□" << endl;	// 33
		cout << "□"; SetColor(0, 15); cout << "■□　　　　　　　　　　　　　　　　　　　　　　　　　　□■■■■■■"; SetColor(9, 15); cout << "□" << endl;	// 34
		cout << "□"; SetColor(0, 15); cout << "■□□□□□□□□□□□□□□□□□□□□□□□□□□□□■■■■■■"; SetColor(9, 15); cout << "□" << endl;	// 35
		cout << "■"; SetColor(0, 15); cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■"; SetColor(9, 15); cout << "■" << endl;	// 36
		cout << "■■□□□■■■□□□■■■□□□■■■□□□■■■□□□■■■□□□■■" << endl;	// 37
	}
	break;
	case 4:
	{
		cout << "■■□□□■■■□□□■■■□□□■■■□□□■■■□□□■■■□□□■■" << endl;	// 1
		cout << "■"; SetColor(0, 15); cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■"; SetColor(9, 15); cout << "■" << endl;	// 2
		cout << "□"; SetColor(0, 15); cout << "■　　　　　■■■■■■■■■■■■■■■■■■■■■■■■■■■■■"; SetColor(9, 15); cout << "□" << endl;	// 3
		cout << "□"; SetColor(0, 15); cout << "■　약　초　■■■■■■■■■■■■■■■■■■■■■■■■■■■■■"; SetColor(9, 15); cout << "□" << endl;	// 4
		cout << "□"; SetColor(0, 15); cout << "■　　　　　■■■■■■■■■■■■■■■■■■■■■■■■■■■■■"; SetColor(9, 15); cout << "□" << endl;	// 5
		cout << "■"; SetColor(0, 15); cout << "■　재　배　■■■■■■■■■■■■■■■■■■■■■■■■■■■■■"; SetColor(9, 15); cout << "■" << endl;	// 6
		cout << "■"; SetColor(0, 15); cout << "■　　　　　■■■■■■■■■■■■■■■■■■■■■■■■■■■■■"; SetColor(9, 15); cout << "■" << endl;	// 7
		cout << "■"; SetColor(0, 15); cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■"; SetColor(9, 15); cout << "■" << endl;	// 8
		cout << "□"; SetColor(0, 15); cout << "■■■■■■■　　　　　　　　　　　　　　　　　　　　　　　　　　　　"; SetColor(9, 15); cout << "□" << endl;	// 9
		cout << "□"; SetColor(0, 15); cout << "■■■■■■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　"; SetColor(9, 15); cout << "□" << endl;	// 10
		cout << "□"; SetColor(0, 15); cout << "■■■■■■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　"; SetColor(9, 15); cout << "□" << endl;	// 11
		cout << "■"; SetColor(0, 15); cout << "■■■■■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　"; SetColor(9, 15); cout << "■" << endl;	// 12
		cout << "■"; SetColor(0, 15); cout << "■■■■■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　"; SetColor(9, 15); cout << "■" << endl;	// 13
		cout << "■"; SetColor(0, 15); cout << "■□□□□　　　　　□□□□□□□□□□□□□□□□□□□■■■■■■"; SetColor(9, 15); cout << "■" << endl;	// 14
		cout << "□"; SetColor(0, 15); cout << "■□　　　　　　　　　　　　　　　　　　　　　　　　　　□■■■■■■"; SetColor(9, 15); cout << "□" << endl;	// 15
		cout << "□"; SetColor(0, 15); cout << "■□　　　　　　　　　　　　　　　　　　　　　　　　　　□■■■■■■"; SetColor(9, 15); cout << "□" << endl;	// 16
		cout << "□"; SetColor(0, 15); cout << "■□　　　　　　　　　　　　　　　　　　　　　　　"; SetColor(14, 15); cout << "　■　"; SetColor(0, 15); cout << "□■■■■■■"; SetColor(9, 15); cout << "□" << endl;	// 17
		cout << "■"; SetColor(0, 15); cout << "■□　　　　　　　　　"; SetColor(10, 15); cout << "■　■　■　　　　■　■　■"; SetColor(14, 15); cout << "■■■"; SetColor(0, 15); cout << "□■■■■■■"; SetColor(9, 15); cout << "■" << endl;	// 18
		cout << "■"; SetColor(0, 15); cout << "■□　　　　　　　　　"; SetColor(10, 15); cout << "　■■■　　　　　　■■■　"; SetColor(14, 15); cout << "　■　"; SetColor(0, 15); cout << "□■■■■■■"; SetColor(9, 15); cout << "■" << endl;	// 19
		cout << "■"; SetColor(0, 15); cout << "■□　　　　　　　　　"; SetColor(10, 15); cout << "　　■　　　　　　　　■　　"; SetColor(14, 15); cout << "■　■"; SetColor(0, 15); cout << "□■■■■■■"; SetColor(9, 15); cout << "■" << endl;	// 20
		cout << "□"; SetColor(0, 15); cout << "■□　　　　　　　　　　　　　　　　　　　　　　　　　　□■■■■■■"; SetColor(9, 15); cout << "□" << endl;	// 21
		cout << "□"; SetColor(0, 15); cout << "■□　　　　　　　　　　　　　　　　　　　　　　　　　　□■■■■■■"; SetColor(9, 15); cout << "□" << endl;	// 22
		cout << "□"; SetColor(0, 15); cout << "■□　　　　　　　　　　　　　　　　　　　　　　　　　　□■■■■■■"; SetColor(9, 15); cout << "□" << endl;	// 23
		cout << "■"; SetColor(0, 15); cout << "■□　　　　　　　　　"; SetColor(10, 15); cout << "■　■　■　　　　■　■　■　　　"; SetColor(0, 15); cout << "□■■■■■■"; SetColor(9, 15); cout << "■" << endl;	// 24
		cout << "■"; SetColor(0, 15); cout << "■□　　　　　　　　　"; SetColor(10, 15); cout << "　■■■　　　　　　■■■　　　　"; SetColor(0, 15); cout << "□■■■■■■"; SetColor(9, 15); cout << "■" << endl;	// 25
		cout << "■"; SetColor(0, 15); cout << "■□　　　　　　　　　"; SetColor(10, 15); cout << "　　■　　　　　　　　■　　　　　"; SetColor(0, 15); cout << "□■■■■■■"; SetColor(9, 15); cout << "■" << endl;	// 26
		cout << "□"; SetColor(0, 15); cout << "■□　　　　　　　　　　　　　　　　　　　　　　　　　　□■■■■■■"; SetColor(9, 15); cout << "□" << endl;	// 27
		cout << "□"; SetColor(0, 15); cout << "■□　　　　　　　　　　　　　　　　　　　　　　　　　　□■■■■■■"; SetColor(9, 15); cout << "□" << endl;	// 28
		cout << "□"; SetColor(0, 15); cout << "■□　　　　　　　　　　　　　　　　　　　　　　　　　　□■■■■■■"; SetColor(9, 15); cout << "□" << endl;	// 29
		cout << "■"; SetColor(0, 15); cout << "■□　"; SetColor(8, 15); cout << "　　■　　　　　"; SetColor(10, 15); cout << "■　■　■　　　　■　■　■　　　"; SetColor(0, 15); cout << "□■■■■■■"; SetColor(9, 15); cout << "■" << endl;	// 30
		cout << "■"; SetColor(0, 15); cout << "■□　"; SetColor(8, 15); cout << "■■■■　　　　"; SetColor(10, 15); cout << "　■■■　　　　　　■■■　　　　"; SetColor(0, 15); cout << "□■■■■■■"; SetColor(9, 15); cout << "■" << endl;	// 31
		cout << "■"; SetColor(0, 15); cout << "■□　"; SetColor(8, 15); cout << "■　■　　　　　"; SetColor(10, 15); cout << "　　■　　　　　　　　■　　　　　"; SetColor(0, 15); cout << "□■■■■■■"; SetColor(9, 15); cout << "■" << endl;	// 32
		cout << "□"; SetColor(0, 15); cout << "■□　　　　　　　　　　　　　　　　　　　　　　　　　　□■■■■■■"; SetColor(9, 15); cout << "□" << endl;	// 33
		cout << "□"; SetColor(0, 15); cout << "■□　　　　　　　　　　　　　　　　　　　　　　　　　　□■■■■■■"; SetColor(9, 15); cout << "□" << endl;	// 34
		cout << "□"; SetColor(0, 15); cout << "■□□□□□□□□□□□□□□□□□□□□□□□□□□□□■■■■■■"; SetColor(9, 15); cout << "□" << endl;	// 35
		cout << "■"; SetColor(0, 15); cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■"; SetColor(9, 15); cout << "■" << endl;	// 36
		cout << "■■□□□■■■□□□■■■□□□■■■□□□■■■□□□■■■□□□■■" << endl;	// 37
	}
	break;
	case 5:
	{
		cout << "■■□□□■■■□□□■■■□□□■■■□□□■■■□□□■■■□□□■■" << endl;	// 1
		cout << "■"; SetColor(0, 15); cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■"; SetColor(9, 15); cout << "■" << endl;	// 2
		cout << "□"; SetColor(0, 15); cout << "■　　　　　■■■■■■■■■■■■■■■■■■■■■■■■■■■■■"; SetColor(9, 15); cout << "□" << endl;	// 3
		cout << "□"; SetColor(0, 15); cout << "■　약　초　■■■■■■■■■■■■■■■■■■■■■■■■■■■■■"; SetColor(9, 15); cout << "□" << endl;	// 4
		cout << "□"; SetColor(0, 15); cout << "■　　　　　■■■■■■■■■■■■■■■■■■■■■■■■■■■■■"; SetColor(9, 15); cout << "□" << endl;	// 5
		cout << "■"; SetColor(0, 15); cout << "■　재　배　■■■■■■■■■■■■■■■■■■■■■■■■■■■■■"; SetColor(9, 15); cout << "■" << endl;	// 6
		cout << "■"; SetColor(0, 15); cout << "■　　　　　■■■■■■■■■■■■■■■■■■■■■■■■■■■■■"; SetColor(9, 15); cout << "■" << endl;	// 7
		cout << "■"; SetColor(0, 15); cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■"; SetColor(9, 15); cout << "■" << endl;	// 8
		cout << "□"; SetColor(0, 15); cout << "■■■■■■■　　　　　　　　　　　　　　　　　　　　　　　　　　　　"; SetColor(9, 15); cout << "□" << endl;	// 9
		cout << "□"; SetColor(0, 15); cout << "■■■■■■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　"; SetColor(9, 15); cout << "□" << endl;	// 10
		cout << "□"; SetColor(0, 15); cout << "■■■■■■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　"; SetColor(9, 15); cout << "□" << endl;	// 11
		cout << "■"; SetColor(0, 15); cout << "■■■■■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　"; SetColor(9, 15); cout << "■" << endl;	// 12
		cout << "■"; SetColor(0, 15); cout << "■■■■■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　"; SetColor(9, 15); cout << "■" << endl;	// 13
		cout << "■"; SetColor(0, 15); cout << "■□□□□　　　　　□□□□□□□□□□□□□□□□□□□■■■■■■"; SetColor(9, 15); cout << "■" << endl;	// 14
		cout << "□"; SetColor(0, 15); cout << "■□　　　　　　　　　　　　　　　　　　　　　　　　　　□■■■■■■"; SetColor(9, 15); cout << "□" << endl;	// 15
		cout << "□"; SetColor(0, 15); cout << "■□　　　　　　　　　　　　　　　　　　　　　　　　　　□■■■■■■"; SetColor(9, 15); cout << "□" << endl;	// 16
		cout << "□"; SetColor(0, 15); cout << "■□　　　　　　　　　　　　　　　　　　　　　　　　　　□■■■■■■"; SetColor(9, 15); cout << "□" << endl;	// 17
		cout << "■"; SetColor(0, 15); cout << "■□　　　　　　　　　"; SetColor(10, 15); cout << "■　■　■　　　　■　■　■　　　"; SetColor(0, 15); cout << "□■■■■■■"; SetColor(9, 15); cout << "■" << endl;	// 18
		cout << "■"; SetColor(0, 15); cout << "■□　　　　　　　　　"; SetColor(10, 15); cout << "　■■■　　　　　　■■■　　　　"; SetColor(0, 15); cout << "□■■■■■■"; SetColor(9, 15); cout << "■" << endl;	// 19
		cout << "■"; SetColor(0, 15); cout << "■□　　　　　　　　　"; SetColor(10, 15); cout << "　　■　　　　　　　　■　　　　　"; SetColor(0, 15); cout << "□■■■■■■"; SetColor(9, 15); cout << "■" << endl;	// 20
		cout << "□"; SetColor(0, 15); cout << "■□　　　　　　　　　　　　　　　　　　　　　　　　　　□■■■■■■"; SetColor(9, 15); cout << "□" << endl;	// 21
		cout << "□"; SetColor(0, 15); cout << "■□　　　　　　　　　　　　　　　　　　　　　　　　　　□■■■■■■"; SetColor(9, 15); cout << "□" << endl;	// 22
		cout << "□"; SetColor(0, 15); cout << "■□　　　　　　　　　　　　　　　　　　　　　　　"; SetColor(14, 15); cout << "　■　"; SetColor(0, 15); cout << "□■■■■■■"; SetColor(9, 15); cout << "□" << endl;	// 23
		cout << "■"; SetColor(0, 15); cout << "■□　　　　　　　　　"; SetColor(10, 15); cout << "■　■　■　　　　■　■　■"; SetColor(14, 15); cout << "■■■"; SetColor(0, 15); cout << "□■■■■■■"; SetColor(9, 15); cout << "■" << endl;	// 24
		cout << "■"; SetColor(0, 15); cout << "■□　　　　　　　　　"; SetColor(10, 15); cout << "　■■■　　　　　　■■■　"; SetColor(14, 15); cout << "　■　"; SetColor(0, 15); cout << "□■■■■■■"; SetColor(9, 15); cout << "■" << endl;	// 25
		cout << "■"; SetColor(0, 15); cout << "■□　　　　　　　　　"; SetColor(10, 15); cout << "　　■　　　　　　　　■　　"; SetColor(14, 15); cout << "■　■"; SetColor(0, 15); cout << "□■■■■■■"; SetColor(9, 15); cout << "■" << endl;	// 26
		cout << "□"; SetColor(0, 15); cout << "■□　　　　　　　　　　　　　　　　　　　　　　　　　　□■■■■■■"; SetColor(9, 15); cout << "□" << endl;	// 27
		cout << "□"; SetColor(0, 15); cout << "■□　　　　　　　　　　　　　　　　　　　　　　　　　　□■■■■■■"; SetColor(9, 15); cout << "□" << endl;	// 28
		cout << "□"; SetColor(0, 15); cout << "■□　　　　　　　　　　　　　　　　　　　　　　　　　　□■■■■■■"; SetColor(9, 15); cout << "□" << endl;	// 29
		cout << "■"; SetColor(0, 15); cout << "■□　"; SetColor(8, 15); cout << "　　■　　　　　"; SetColor(10, 15); cout << "■　■　■　　　　■　■　■　　　"; SetColor(0, 15); cout << "□■■■■■■"; SetColor(9, 15); cout << "■" << endl;	// 30
		cout << "■"; SetColor(0, 15); cout << "■□　"; SetColor(8, 15); cout << "■■■■　　　　"; SetColor(10, 15); cout << "　■■■　　　　　　■■■　　　　"; SetColor(0, 15); cout << "□■■■■■■"; SetColor(9, 15); cout << "■" << endl;	// 31
		cout << "■"; SetColor(0, 15); cout << "■□　"; SetColor(8, 15); cout << "■　■　　　　　"; SetColor(10, 15); cout << "　　■　　　　　　　　■　　　　　"; SetColor(0, 15); cout << "□■■■■■■"; SetColor(9, 15); cout << "■" << endl;	// 32
		cout << "□"; SetColor(0, 15); cout << "■□　　　　　　　　　　　　　　　　　　　　　　　　　　□■■■■■■"; SetColor(9, 15); cout << "□" << endl;	// 33
		cout << "□"; SetColor(0, 15); cout << "■□　　　　　　　　　　　　　　　　　　　　　　　　　　□■■■■■■"; SetColor(9, 15); cout << "□" << endl;	// 34
		cout << "□"; SetColor(0, 15); cout << "■□□□□□□□□□□□□□□□□□□□□□□□□□□□□■■■■■■"; SetColor(9, 15); cout << "□" << endl;	// 35
		cout << "■"; SetColor(0, 15); cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■"; SetColor(9, 15); cout << "■" << endl;	// 36
		cout << "■■□□□■■■□□□■■■□□□■■■□□□■■■□□□■■■□□□■■" << endl;	// 37
	}
	break;
	case 6:
	{
		cout << "■■□□□■■■□□□■■■□□□■■■□□□■■■□□□■■■□□□■■" << endl;	// 1
		cout << "■"; SetColor(0, 15); cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■"; SetColor(9, 15); cout << "■" << endl;	// 2
		cout << "□"; SetColor(0, 15); cout << "■　　　　　■■■■■■■■■■■■■■■■■■■■■■■■■■■■■"; SetColor(9, 15); cout << "□" << endl;	// 3
		cout << "□"; SetColor(0, 15); cout << "■　약　초　■■■■■■■■■■■■■■■■■■■■■■■■■■■■■"; SetColor(9, 15); cout << "□" << endl;	// 4
		cout << "□"; SetColor(0, 15); cout << "■　　　　　■■■■■■■■■■■■■■■■■■■■■■■■■■■■■"; SetColor(9, 15); cout << "□" << endl;	// 5
		cout << "■"; SetColor(0, 15); cout << "■　재　배　■■■■■■■■■■■■■■■■■■■■■■■■■■■■■"; SetColor(9, 15); cout << "■" << endl;	// 6
		cout << "■"; SetColor(0, 15); cout << "■　　　　　■■■■■■■■■■■■■■■■■■■■■■■■■■■■■"; SetColor(9, 15); cout << "■" << endl;	// 7
		cout << "■"; SetColor(0, 15); cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■"; SetColor(9, 15); cout << "■" << endl;	// 8
		cout << "□"; SetColor(0, 15); cout << "■■■■■■■　　　　　　　　　　　　　　　　　　　　　　　　　　　　"; SetColor(9, 15); cout << "□" << endl;	// 9
		cout << "□"; SetColor(0, 15); cout << "■■■■■■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　"; SetColor(9, 15); cout << "□" << endl;	// 10
		cout << "□"; SetColor(0, 15); cout << "■■■■■■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　"; SetColor(9, 15); cout << "□" << endl;	// 11
		cout << "■"; SetColor(0, 15); cout << "■■■■■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　"; SetColor(9, 15); cout << "■" << endl;	// 12
		cout << "■"; SetColor(0, 15); cout << "■■■■■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　"; SetColor(9, 15); cout << "■" << endl;	// 13
		cout << "■"; SetColor(0, 15); cout << "■□□□□　　　　　□□□□□□□□□□□□□□□□□□□■■■■■■"; SetColor(9, 15); cout << "■" << endl;	// 14
		cout << "□"; SetColor(0, 15); cout << "■□　　　　　　　　　　　　　　　　　　　　　　　　　　□■■■■■■"; SetColor(9, 15); cout << "□" << endl;	// 15
		cout << "□"; SetColor(0, 15); cout << "■□　　　　　　　　　　　　　　　　　　　　　　　　　　□■■■■■■"; SetColor(9, 15); cout << "□" << endl;	// 16
		cout << "□"; SetColor(0, 15); cout << "■□　　　　　　　　　　　　　　　　　　　　　　　　　　□■■■■■■"; SetColor(9, 15); cout << "□" << endl;	// 17
		cout << "■"; SetColor(0, 15); cout << "■□　　　　　　　　　"; SetColor(10, 15); cout << "■　■　■　　　　■　■　■　　　"; SetColor(0, 15); cout << "□■■■■■■"; SetColor(9, 15); cout << "■" << endl;	// 18
		cout << "■"; SetColor(0, 15); cout << "■□　　　　　　　　　"; SetColor(10, 15); cout << "　■■■　　　　　　■■■　　　　"; SetColor(0, 15); cout << "□■■■■■■"; SetColor(9, 15); cout << "■" << endl;	// 19
		cout << "■"; SetColor(0, 15); cout << "■□　　　　　　　　　"; SetColor(10, 15); cout << "　　■　　　　　　　　■　　　　　"; SetColor(0, 15); cout << "□■■■■■■"; SetColor(9, 15); cout << "■" << endl;	// 20
		cout << "□"; SetColor(0, 15); cout << "■□　　　　　　　　　　　　　　　　　　　　　　　　　　□■■■■■■"; SetColor(9, 15); cout << "□" << endl;	// 21
		cout << "□"; SetColor(0, 15); cout << "■□　　　　　　　　　　　　　　　　　　　　　　　　　　□■■■■■■"; SetColor(9, 15); cout << "□" << endl;	// 22
		cout << "□"; SetColor(0, 15); cout << "■□　　　　　　　　　　　　　　　　　　　　　　　　　　□■■■■■■"; SetColor(9, 15); cout << "□" << endl;	// 23
		cout << "■"; SetColor(0, 15); cout << "■□　　　　　　　　　"; SetColor(10, 15); cout << "■　■　■　　　　■　■　■　　　"; SetColor(0, 15); cout << "□■■■■■■"; SetColor(9, 15); cout << "■" << endl;	// 24
		cout << "■"; SetColor(0, 15); cout << "■□　　　　　　　　　"; SetColor(10, 15); cout << "　■■■　　　　　　■■■　　　　"; SetColor(0, 15); cout << "□■■■■■■"; SetColor(9, 15); cout << "■" << endl;	// 25
		cout << "■"; SetColor(0, 15); cout << "■□　　　　　　　　　"; SetColor(10, 15); cout << "　　■　　　　　　　　■　　　　　"; SetColor(0, 15); cout << "□■■■■■■"; SetColor(9, 15); cout << "■" << endl;	// 26
		cout << "□"; SetColor(0, 15); cout << "■□　　　　　　　　　　　　　　　　　　　　　　　　　　□■■■■■■"; SetColor(9, 15); cout << "□" << endl;	// 27
		cout << "□"; SetColor(0, 15); cout << "■□　　　　　　　　　　　　　　　　　　　　　　　　　　□■■■■■■"; SetColor(9, 15); cout << "□" << endl;	// 28
		cout << "□"; SetColor(0, 15); cout << "■□　　　　　　　　　　　　　　　　　　　　　　　"; SetColor(14, 15); cout << "　■　"; SetColor(0, 15); cout << "□■■■■■■"; SetColor(9, 15); cout << "□" << endl;	// 29
		cout << "■"; SetColor(0, 15); cout << "■□　"; SetColor(8, 15); cout << "　　■　　　　　"; SetColor(10, 15); cout << "■　■　■　　　　■　■　■"; SetColor(14, 15); cout << "■■■"; SetColor(0, 15); cout << "□■■■■■■"; SetColor(9, 15); cout << "■" << endl;	// 30
		cout << "■"; SetColor(0, 15); cout << "■□　"; SetColor(8, 15); cout << "■■■■　　　　"; SetColor(10, 15); cout << "　■■■　　　　　　■■■　"; SetColor(14, 15); cout << "　■　"; SetColor(0, 15); cout << "□■■■■■■"; SetColor(9, 15); cout << "■" << endl;	// 31
		cout << "■"; SetColor(0, 15); cout << "■□　"; SetColor(8, 15); cout << "■　■　　　　　"; SetColor(10, 15); cout << "　　■　　　　　　　　■　　"; SetColor(14, 15); cout << "■　■"; SetColor(0, 15); cout << "□■■■■■■"; SetColor(9, 15); cout << "■" << endl;	// 32
		cout << "□"; SetColor(0, 15); cout << "■□　　　　　　　　　　　　　　　　　　　　　　　　　　□■■■■■■"; SetColor(9, 15); cout << "□" << endl;	// 33
		cout << "□"; SetColor(0, 15); cout << "■□　　　　　　　　　　　　　　　　　　　　　　　　　　□■■■■■■"; SetColor(9, 15); cout << "□" << endl;	// 34
		cout << "□"; SetColor(0, 15); cout << "■□□□□□□□□□□□□□□□□□□□□□□□□□□□□■■■■■■"; SetColor(9, 15); cout << "□" << endl;	// 35
		cout << "■"; SetColor(0, 15); cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■"; SetColor(9, 15); cout << "■" << endl;	// 36
		cout << "■■□□□■■■□□□■■■□□□■■■□□□■■■□□□■■■□□□■■" << endl;	// 37
	}
	break;
	case 7:
	{
		cout << "■■□□□■■■□□□■■■□□□■■■□□□■■■□□□■■■□□□■■" << endl;	// 1
		cout << "■"; SetColor(0, 15); cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■"; SetColor(9, 15); cout << "■" << endl;	// 2
		cout << "□"; SetColor(0, 15); cout << "■　　　　　■■■■■■■■■■■■■■■■■■■■■■■■■■■■■"; SetColor(9, 15); cout << "□" << endl;	// 3
		cout << "□"; SetColor(0, 15); cout << "■　　　　　■■■■■■■■■■■■■■■■■■■■■■■■■■■■■"; SetColor(9, 15); cout << "□" << endl;	// 4
		cout << "□"; SetColor(0, 15); cout << "■　강아지　■■■■■■■■■■■■■■■■■■■■■■■■■■■■■"; SetColor(9, 15); cout << "□" << endl;	// 5
		cout << "■"; SetColor(0, 15); cout << "■　　　　　■■■■■■■■■■■■■■■■■■■■■■■■■■■■■"; SetColor(9, 15); cout << "■" << endl;	// 6
		cout << "■"; SetColor(0, 15); cout << "■　　　　　■■■■■■■■■■■■■■■■■■■■■■■■■■■■■"; SetColor(9, 15); cout << "■" << endl;	// 7
		cout << "■"; SetColor(0, 15); cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■"; SetColor(9, 15); cout << "■" << endl;	// 8
		cout << "□"; SetColor(0, 15); cout << "■■■■■■■　　　　　　　　　　　　　　　　　　　　　　　　　　　　"; SetColor(9, 15); cout << "□" << endl;	// 9
		cout << "□"; SetColor(0, 15); cout << "■■■■■■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　"; SetColor(9, 15); cout << "□" << endl;	// 10
		cout << "□"; SetColor(0, 15); cout << "■■■■■■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　"; SetColor(9, 15); cout << "□" << endl;	// 11
		cout << "■"; SetColor(0, 15); cout << "■■■■■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　"; SetColor(9, 15); cout << "■" << endl;	// 12
		cout << "■"; SetColor(0, 15); cout << "■■■■■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　"; SetColor(9, 15); cout << "■" << endl;	// 13
		cout << "■"; SetColor(0, 15); cout << "■□□□□　　　　　□□□□□□□□□□□□□□□□□□□■■■■■■"; SetColor(9, 15); cout << "■" << endl;	// 14
		cout << "□"; SetColor(0, 15); cout << "■□　　　　　　　　　　　　　　　　　　　　　　　　　　□■■■■■■"; SetColor(9, 15); cout << "□" << endl;	// 15
		cout << "□"; SetColor(0, 15); cout << "■□　　　　　　　　　　　　　　　　　　　　　　　　　　□■■■■■■"; SetColor(9, 15); cout << "□" << endl;	// 16
		cout << "□"; SetColor(0, 15); cout << "■□　　　　　　　　　　　　　　　　　　　　　　　　　　□■■■■■■"; SetColor(9, 15); cout << "□" << endl;	// 17
		cout << "■"; SetColor(0, 15); cout << "■□　　　　　　　　　"; SetColor(10, 15); cout << "■　■　■　　　　■　■　■　　　"; SetColor(0, 15); cout << "□■■■■■■"; SetColor(9, 15); cout << "■" << endl;	// 18
		cout << "■"; SetColor(0, 15); cout << "■□　　　　　　　　　"; SetColor(10, 15); cout << "　■■■　　　　　　■■■　　　　"; SetColor(0, 15); cout << "□■■■■■■"; SetColor(9, 15); cout << "■" << endl;	// 19
		cout << "■"; SetColor(0, 15); cout << "■□　　　　　　　　　"; SetColor(10, 15); cout << "　　■　　　　　　　　■　　　　　"; SetColor(0, 15); cout << "□■■■■■■"; SetColor(9, 15); cout << "■" << endl;	// 20
		cout << "□"; SetColor(0, 15); cout << "■□　　　　　　　　　　　　　　　　　　　　　　　　　　□■■■■■■"; SetColor(9, 15); cout << "□" << endl;	// 21
		cout << "□"; SetColor(0, 15); cout << "■□　　　　　　　　　　　　　　　　　　　　　　　　　　□■■■■■■"; SetColor(9, 15); cout << "□" << endl;	// 22
		cout << "□"; SetColor(0, 15); cout << "■□　　　　　　　　　　　　　　　　　　　　　　　　　　□■■■■■■"; SetColor(9, 15); cout << "□" << endl;	// 23
		cout << "■"; SetColor(0, 15); cout << "■□　　　　　　　　　"; SetColor(10, 15); cout << "■　■　■　　　　■　■　■　　　"; SetColor(0, 15); cout << "□■■■■■■"; SetColor(9, 15); cout << "■" << endl;	// 24
		cout << "■"; SetColor(0, 15); cout << "■□　　　　　　　　　"; SetColor(10, 15); cout << "　■■■　　　　　　■■■　　　　"; SetColor(0, 15); cout << "□■■■■■■"; SetColor(9, 15); cout << "■" << endl;	// 25
		cout << "■"; SetColor(0, 15); cout << "■□　　　　　　　　　"; SetColor(10, 15); cout << "　　■　　　　　　　　■　　　　　"; SetColor(0, 15); cout << "□■■■■■■"; SetColor(9, 15); cout << "■" << endl;	// 26
		cout << "□"; SetColor(0, 15); cout << "■□　　　　　　　　　　　　　　　　　　　　　　　　　　□■■■■■■"; SetColor(9, 15); cout << "□" << endl;	// 27
		cout << "□"; SetColor(0, 15); cout << "■□　　　　　　　　　　　　　　　　　　　　　　　　　　□■■■■■■"; SetColor(9, 15); cout << "□" << endl;	// 28
		cout << "□"; SetColor(0, 15); cout << "■□　　　　　"; SetColor(14, 15); cout << "　■　　"; SetColor(0, 15); cout << "　　　　　　　　　　　　　　　　　□■■■■■■"; SetColor(9, 15); cout << "□" << endl;	// 29
		cout << "■"; SetColor(0, 15); cout << "■□　"; SetColor(8, 15); cout << "　　■　"; SetColor(14, 15); cout << "■■■　"; SetColor(10, 15); cout << "■　■　■　　　　■　■　■　　　"; SetColor(0, 15); cout << "□■■■■■■"; SetColor(9, 15); cout << "■" << endl;	// 30
		cout << "■"; SetColor(0, 15); cout << "■□　"; SetColor(8, 15); cout << "■■■■"; SetColor(14, 15); cout << "　■　　"; SetColor(10, 15); cout << "　■■■　　　　　　■■■　　　　"; SetColor(0, 15); cout << "□■■■■■■"; SetColor(9, 15); cout << "■" << endl;	// 31
		cout << "■"; SetColor(0, 15); cout << "■□　"; SetColor(8, 15); cout << "■　■　"; SetColor(14, 15); cout << "■　■　"; SetColor(10, 15); cout << "　　■　　　　　　　　■　　　　　"; SetColor(0, 15); cout << "□■■■■■■"; SetColor(9, 15); cout << "■" << endl;	// 32
		cout << "□"; SetColor(0, 15); cout << "■□　　　　　　　　　　　　　　　　　　　　　　　　　　□■■■■■■"; SetColor(9, 15); cout << "□" << endl;	// 33
		cout << "□"; SetColor(0, 15); cout << "■□　　　　　　　　　　　　　　　　　　　　　　　　　　□■■■■■■"; SetColor(9, 15); cout << "□" << endl;	// 34
		cout << "□"; SetColor(0, 15); cout << "■□□□□□□□□□□□□□□□□□□□□□□□□□□□□■■■■■■"; SetColor(9, 15); cout << "□" << endl;	// 35
		cout << "■"; SetColor(0, 15); cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■"; SetColor(9, 15); cout << "■" << endl;	// 36
		cout << "■■□□□■■■□□□■■■□□□■■■□□□■■■□□□■■■□□□■■" << endl;	// 37
	}
	break;
	case 8:
	{
		cout << "■■□□□■■■□□□■■■□□□■■■□□□■■■□□□■■■□□□■■" << endl;	// 1
		cout << "■"; SetColor(0, 15); cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■"; SetColor(9, 15); cout << "■" << endl;	// 2
		cout << "□"; SetColor(0, 15); cout << "■　　　　　■■■■■■■■■■■■■■■■■■■■■■■■■■■■■"; SetColor(9, 15); cout << "□" << endl;	// 3
		cout << "□"; SetColor(0, 15); cout << "■　호랑이　■■■■■■■■■■■■■■■■■■■■■■■■■■■■■"; SetColor(9, 15); cout << "□" << endl;	// 4
		cout << "□"; SetColor(0, 15); cout << "■　바　위　■■■■■■■■■■■■■■■■■■■■■■■■■■■■■"; SetColor(9, 15); cout << "□" << endl;	// 5
		cout << "■"; SetColor(0, 15); cout << "■　산　길　■■■■■■■■■■■■■■■■■■■■■■■■■■■■■"; SetColor(9, 15); cout << "■" << endl;	// 6
		cout << "■"; SetColor(0, 15); cout << "■　　　　　■■■■■■■■■■■■■■■■■■■■■■■■■■■■■"; SetColor(9, 15); cout << "■" << endl;	// 7
		cout << "■"; SetColor(0, 15); cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■"; SetColor(9, 15); cout << "■" << endl;	// 8
		cout << "□"; SetColor(0, 15); cout << "■■■■■■■　　　　　　　　　　　　　　　　　　　　　　　　　　　　"; SetColor(9, 15); cout << "□" << endl;	// 9
		cout << "□"; SetColor(0, 15); cout << "■■■■■■　　　　　　　　　　　　　　　　　　　　　　　　　"; SetColor(14, 15); cout << "　■　　"; SetColor(9, 15); cout << "□" << endl;	// 10
		cout << "□"; SetColor(0, 15); cout << "■■■■■■　　　　　　　　　　　　　　　　　　　　　　　　　"; SetColor(14, 15); cout << "■■■　"; SetColor(9, 15); cout << "□" << endl;	// 11
		cout << "■"; SetColor(0, 15); cout << "■■■■■　　　　　　　　　　　　　　　　　　　　　　　　　　"; SetColor(14, 15); cout << "　■　　"; SetColor(9, 15); cout << "■" << endl;	// 12
		cout << "■"; SetColor(0, 15); cout << "■■■■■　　　　　　　　　　　　　　　　　　　　　　　　　　"; SetColor(14, 15); cout << "■　■　"; SetColor(9, 15); cout << "■" << endl;	// 13
		cout << "■"; SetColor(0, 15); cout << "■□□□□　　　　　□□□□□□□□□□□□□□□□□□□■■■■■■"; SetColor(9, 15); cout << "■" << endl;	// 14
		cout << "□"; SetColor(0, 15); cout << "■□　　　　　　　　　　　　　　　　　　　　　　　　　　□■■■■■■"; SetColor(9, 15); cout << "□" << endl;	// 15
		cout << "□"; SetColor(0, 15); cout << "■□　　　　　　　　　　　　　　　　　　　　　　　　　　□■■■■■■"; SetColor(9, 15); cout << "□" << endl;	// 16
		cout << "□"; SetColor(0, 15); cout << "■□　　　　　　　　　　　　　　　　　　　　　　　　　　□■■■■■■"; SetColor(9, 15); cout << "□" << endl;	// 17
		cout << "■"; SetColor(0, 15); cout << "■□　　　　　　　　　"; SetColor(10, 15); cout << "■　■　■　　　　■　■　■　　　"; SetColor(0, 15); cout << "□■■■■■■"; SetColor(9, 15); cout << "■" << endl;	// 18
		cout << "■"; SetColor(0, 15); cout << "■□　　　　　　　　　"; SetColor(10, 15); cout << "　■■■　　　　　　■■■　　　　"; SetColor(0, 15); cout << "□■■■■■■"; SetColor(9, 15); cout << "■" << endl;	// 19
		cout << "■"; SetColor(0, 15); cout << "■□　　　　　　　　　"; SetColor(10, 15); cout << "　　■　　　　　　　　■　　　　　"; SetColor(0, 15); cout << "□■■■■■■"; SetColor(9, 15); cout << "■" << endl;	// 20
		cout << "□"; SetColor(0, 15); cout << "■□　　　　　　　　　　　　　　　　　　　　　　　　　　□■■■■■■"; SetColor(9, 15); cout << "□" << endl;	// 21
		cout << "□"; SetColor(0, 15); cout << "■□　　　　　　　　　　　　　　　　　　　　　　　　　　□■■■■■■"; SetColor(9, 15); cout << "□" << endl;	// 22
		cout << "□"; SetColor(0, 15); cout << "■□　　　　　　　　　　　　　　　　　　　　　　　　　　□■■■■■■"; SetColor(9, 15); cout << "□" << endl;	// 23
		cout << "■"; SetColor(0, 15); cout << "■□　　　　　　　　　"; SetColor(10, 15); cout << "■　■　■　　　　■　■　■　　　"; SetColor(0, 15); cout << "□■■■■■■"; SetColor(9, 15); cout << "■" << endl;	// 24
		cout << "■"; SetColor(0, 15); cout << "■□　　　　　　　　　"; SetColor(10, 15); cout << "　■■■　　　　　　■■■　　　　"; SetColor(0, 15); cout << "□■■■■■■"; SetColor(9, 15); cout << "■" << endl;	// 25
		cout << "■"; SetColor(0, 15); cout << "■□　　　　　　　　　"; SetColor(10, 15); cout << "　　■　　　　　　　　■　　　　　"; SetColor(0, 15); cout << "□■■■■■■"; SetColor(9, 15); cout << "■" << endl;	// 26
		cout << "□"; SetColor(0, 15); cout << "■□　　　　　　　　　　　　　　　　　　　　　　　　　　□■■■■■■"; SetColor(9, 15); cout << "□" << endl;	// 27
		cout << "□"; SetColor(0, 15); cout << "■□　　　　　　　　　　　　　　　　　　　　　　　　　　□■■■■■■"; SetColor(9, 15); cout << "□" << endl;	// 28
		cout << "□"; SetColor(0, 15); cout << "■□　　　　　　　　　　　　　　　　　　　　　　　　　　□■■■■■■"; SetColor(9, 15); cout << "□" << endl;	// 29
		cout << "■"; SetColor(0, 15); cout << "■□　"; SetColor(8, 15); cout << "　　■　　　　　"; SetColor(10, 15); cout << "■　■　■　　　　■　■　■　　　"; SetColor(0, 15); cout << "□■■■■■■"; SetColor(9, 15); cout << "■" << endl;	// 30
		cout << "■"; SetColor(0, 15); cout << "■□　"; SetColor(8, 15); cout << "■■■■　　　　"; SetColor(10, 15); cout << "　■■■　　　　　　■■■　　　　"; SetColor(0, 15); cout << "□■■■■■■"; SetColor(9, 15); cout << "■" << endl;	// 31
		cout << "■"; SetColor(0, 15); cout << "■□　"; SetColor(8, 15); cout << "■　■　　　　　"; SetColor(10, 15); cout << "　　■　　　　　　　　■　　　　　"; SetColor(0, 15); cout << "□■■■■■■"; SetColor(9, 15); cout << "■" << endl;	// 32
		cout << "□"; SetColor(0, 15); cout << "■□　　　　　　　　　　　　　　　　　　　　　　　　　　□■■■■■■"; SetColor(9, 15); cout << "□" << endl;	// 33
		cout << "□"; SetColor(0, 15); cout << "■□　　　　　　　　　　　　　　　　　　　　　　　　　　□■■■■■■"; SetColor(9, 15); cout << "□" << endl;	// 34
		cout << "□"; SetColor(0, 15); cout << "■□□□□□□□□□□□□□□□□□□□□□□□□□□□□■■■■■■"; SetColor(9, 15); cout << "□" << endl;	// 35
		cout << "■"; SetColor(0, 15); cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■"; SetColor(9, 15); cout << "■" << endl;	// 36
		cout << "■■□□□■■■□□□■■■□□□■■■□□□■■■□□□■■■□□□■■" << endl;	// 37
	}
	break;
	}
}

void mainGame::CharacterScreen()
{
	gotoxy(0, 14);
	SetColor(9, 15);

	switch (_charactercheck)
	{
	case 1:
	{
		cout << "□"; SetColor(0, 15); cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　"; SetColor(9, 15); cout << "□" << endl;	// 15
		cout << "□"; SetColor(0, 15); cout << "　　　　"; SetColor(14, 15); cout << "　■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　"; SetColor(9, 15); cout << "□" << endl;	// 16
		cout << "□"; SetColor(0, 15); cout << "　　　　"; SetColor(14, 15); cout << "■■■　　　　　　　　　　　　　　　　　　　　　　　　　　　　"; SetColor(9, 15); cout << "□" << endl;	// 17
		cout << "■"; SetColor(0, 15); cout << "　　　　"; SetColor(14, 15); cout << "　■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　"; SetColor(9, 15); cout << "■" << endl;	// 18
		cout << "■"; SetColor(0, 15); cout << "　　　　"; SetColor(14, 15); cout << "■　■　　　　　　　　　　　　　　　　　　　　　　　　　　　　"; SetColor(9, 15); cout << "■" << endl;	// 19
		cout << "■"; SetColor(0, 15); cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　"; SetColor(9, 15); cout << "■" << endl;	// 20
	}
	break;
	case 2:
	{
		cout << "□"; SetColor(0, 15); cout << "　　　　　　　　　　　　■　　　　　　　　　　　　　　　　　　　　　　"; SetColor(9, 15); cout << "□" << endl;	// 15
		cout << "□"; SetColor(0, 15); cout << "　　　　"; SetColor(14, 15); cout << "　■　　　"; SetColor(0, 15); cout << "　■　　　　　　　　　　　　　　　　　　　　　　　　"; SetColor(9, 15); cout << "□" << endl;	// 16
		cout << "□"; SetColor(0, 15); cout << "　　　　"; SetColor(14, 15); cout << "　■■　　　　　　　　　　　　　　　　　　　　　　　　　　　　"; SetColor(9, 15); cout << "□" << endl;	// 17
		cout << "■"; SetColor(0, 15); cout << "　　　　"; SetColor(14, 15); cout << "　■　　　"; SetColor(0, 15); cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　"; SetColor(9, 15); cout << "■" << endl;	// 18
		cout << "■"; SetColor(0, 15); cout << "　　　　"; SetColor(14, 15); cout << "■　■　　　　"; SetColor(0, 15); cout << "　　　　　　　　　　　　　　　　　　　　　　　　"; SetColor(9, 15); cout << "■" << endl;	// 19
		cout << "■"; SetColor(0, 15); cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　"; SetColor(9, 15); cout << "■" << endl;	// 20
	}
	break;
	case 3:
	{
		cout << "□　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　"; SetColor(9, 15); cout << "□" << endl;	// 15
		cout << "□"; SetColor(14, 15); cout << "　　■　■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　"; SetColor(9, 15); cout << "□" << endl;	// 16
		cout << "□"; SetColor(14, 15); cout << "　　　■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　"; SetColor(9, 15); cout << "□" << endl;	// 17
		cout << "■"; SetColor(14, 15); cout << "　　■　■■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　"; SetColor(9, 15); cout << "■" << endl;	// 18
		cout << "■"; SetColor(14, 15); cout << "　　　　■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　"; SetColor(9, 15); cout << "■" << endl;	// 19
		cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　"; SetColor(9, 15); cout << "■" << endl;	// 20
	}
	break;
	case 4:
	{
		cout << "□　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　"; SetColor(9, 15); cout << "□" << endl;	// 15
		cout << "□"; SetColor(14, 15); cout << "　■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　"; SetColor(9, 15); cout << "□" << endl;	// 16
		cout << "□"; SetColor(14, 15); cout << "　■■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　"; SetColor(9, 15); cout << "□" << endl;	// 17
		cout << "■"; SetColor(14, 15); cout << "　■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　"; SetColor(9, 15); cout << "■" << endl;	// 18
		cout << "■"; SetColor(14, 15); cout << "■　■　"; SetColor(0, 15); cout << "■　■　　　　　　　　　　　　　　　　　　　　　　　　　　　　"; SetColor(9, 15); cout << "■" << endl;	// 19
		cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　"; SetColor(9, 15); cout << "■" << endl;	// 20//캐릭
	}
	break;
	case 5:
	{
		cout << "□　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　□" << endl;	// 15
		cout << "□　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　□" << endl;	// 16
		cout << "□　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　□" << endl;	// 17
		cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;	// 18
		cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;	// 19
		cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;	// 20
	}
	break;
	case 6:
	{
		cout << "□　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　□" << endl;	// 15
		cout << "□　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　□" << endl;	// 16
		cout << "□　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　□" << endl;	// 17
		cout << "■"; SetColor(14, 15); cout << "　　■　■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　"; SetColor(9, 15); cout << "■" << endl;	// 18
		cout << "■"; SetColor(14, 15); cout << "　■■■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　"; SetColor(9, 15); cout << "■" << endl;	// 19
		cout << "■"; SetColor(14, 15); cout << "　　■　■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　"; SetColor(9, 15); cout << "■" << endl;	// 20
	}
	break;
	case 7:
	{
		cout << "□"; SetColor(0, 15); cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　"; SetColor(9, 15); cout << "□" << endl;	// 15
		cout << "□"; SetColor(0, 15); cout << "　　　　"; SetColor(14, 15); cout << "　■　　　"; SetColor(0, 15); cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　"; SetColor(9, 15); cout << "□" << endl;	// 16
		cout << "□"; SetColor(0, 15); cout << "　　　　"; SetColor(14, 15); cout << "　■■　　　　　　　　　　　　　　　　　　　　　　　　　　　　"; SetColor(9, 15); cout << "□" << endl;	// 17
		cout << "■"; SetColor(0, 15); cout << "　　　　"; SetColor(14, 15); cout << "　■　　　"; SetColor(0, 15); cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　"; SetColor(9, 15); cout << "■" << endl;	// 18
		cout << "■"; SetColor(0, 15); cout << "　　　　"; SetColor(14, 15); cout << "■　■　　　　"; SetColor(0, 15); cout << "■　　　　　　　　　　　　　　　　　　　　　　　"; SetColor(9, 15); cout << "■" << endl;	// 19
		cout << "■"; SetColor(0, 15); cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　"; SetColor(9, 15); cout << "■" << endl;	// 20
	}
	break;
	}
}

void mainGame::SkillScreen(monsterBase* _mob1, monsterBase* _mob2)
{
	gotoxy(0, 0);
	SetColor(9, 15);

	switch (_skillcheck)
	{
	case 1:
	{
		cout << "■■□□□■■■□□□■■■□□□■■■□□□■■■□□□■■■□□□■■" << endl;	// 1
		cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;	// 2
		cout << "□　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　□" << endl;	// 3
		cout << "□　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　□" << endl;	// 4
		cout << "□　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　□" << endl;	// 5
		cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;	// 6
		cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;	// 7
		cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;	// 8//기술
	}
	break;
	case 2:
	{
		cout << "■■□□□■■■□□□■■■□□□■■■□□□■■■□□□■■■□□□■■" << endl;	// 1
		cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;	// 2
		cout << "□"; SetColor(0, 15); cout << "　■■■■■■■　　　　　　　　　　　　　　　　　　　　　　　　　　　"; SetColor(9, 15); cout << "□" << endl;	// 3
		cout << "□"; SetColor(0, 15); cout << "　■　　　　　■　　　　　　　　　　　　　　　　　　　　　　　　　　　"; SetColor(9, 15); cout << "□" << endl;	// 4
		cout << "□"; SetColor(0, 15); cout << "　■　비상각　■　　　　　　　　　　　　　　　　　　　　　　　　　　　"; SetColor(9, 15); cout << "□" << endl;	// 5
		cout << "■"; SetColor(0, 15); cout << "　■　　　　　■　　　　　　　　　　　　　　　　　　　　　　　　　　　"; SetColor(9, 15); cout << "■" << endl;	// 6
		cout << "■"; SetColor(0, 15); cout << "　■■■■■■■　　　　　　　　　　　　　　　　　　　　　　　　　　　"; SetColor(9, 15); cout << "■" << endl;	// 7
		cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;	// 8//기술
	}
	break;
	case 3:
	{
		cout << "■■□□□■■■□□□■■■□□□■■■□□□■■■□□□■■■□□□■■" << endl;	// 1
		cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;	// 2
		cout << "□"; SetColor(0, 15); cout << "　■■■■■■■　　　　　　　　　　　　　　　　　　　　　　　　　　　"; SetColor(9, 15); cout << "□" << endl;	// 3
		cout << "□"; SetColor(0, 15); cout << "　■　　　　　■　　　　　　　　　　　　　　　　　　　　　　　　　　　"; SetColor(9, 15); cout << "□" << endl;	// 4
		cout << "□"; SetColor(0, 15); cout << "　■　폭전축　■　　　　　　　　　　　　　　　　　　　　　　　　　　　"; SetColor(9, 15); cout << "□" << endl;	// 5
		cout << "■"; SetColor(0, 15); cout << "　■　　　　　■　　　　　　　　　　　　　　　　　　　　　　　　　　　"; SetColor(9, 15); cout << "■" << endl;	// 6
		cout << "■"; SetColor(0, 15); cout << "　■■■■■■■　　　　　　　　　　　　　　　　　　　　　　　　　　　"; SetColor(9, 15); cout << "■" << endl;	// 7
		cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;	// 8//기술
	}
	break;
	case 4:
	{
		cout << "■■□□□■■■□□□■■■□□□■■■□□□■■■□□□■■■□□□■■" << endl;	// 1
		cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;	// 2
		cout << "□"; SetColor(0, 15); cout << "　■■■■■■■　　　　　　　　　　　　　　　　　　　　　　　　　　　"; SetColor(9, 15); cout << "□" << endl;	// 3
		cout << "□"; SetColor(0, 15); cout << "　■　　　　　■　　　　　　　　　　　　　　　　　　　　　　　　　　　"; SetColor(9, 15); cout << "□" << endl;	// 4
		cout << "□"; SetColor(0, 15); cout << "　■　대타격　■　　　　　　　　　　　　　　　　　　　　　　　　　　　"; SetColor(9, 15); cout << "□" << endl;	// 5
		cout << "■"; SetColor(0, 15); cout << "　■　　　　　■　　　　　　　　　　　　　　　　　　　　　　　　　　　"; SetColor(9, 15); cout << "■" << endl;	// 6
		cout << "■"; SetColor(0, 15); cout << "　■■■■■■■　　　　　　　　　　　　　　　　　　　　　　　　　　　"; SetColor(9, 15); cout << "■" << endl;	// 7
		cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;	// 8//기술
	}
	break;
	case 5:
	{
		cout << "■■□□□■■■□□□■■■□□□■■■□□□■■■□□□■■■□□□■■" << endl;	// 1
		cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;	// 2
		cout << "□"; SetColor(0, 15); cout << "　■■■■■■■　　　　　　　　　　　　　　　　　　　　　　　　　　　"; SetColor(9, 15); cout << "□" << endl;	// 3
		cout << "□"; SetColor(0, 15); cout << "　■　　　　　■　　　　　　　　　　　　　　　　　　　　　　　　　　　"; SetColor(9, 15); cout << "□" << endl;	// 4
		cout << "□"; SetColor(0, 15); cout << "　■　쾌진격　■　　　　　　　　　　　　　　　　　　　　　　　　　　　"; SetColor(9, 15); cout << "□" << endl;	// 5
		cout << "■"; SetColor(0, 15); cout << "　■　　　　　■　　　　　　　　　　　　　　　　　　　　　　　　　　　"; SetColor(9, 15); cout << "■" << endl;	// 6
		cout << "■"; SetColor(0, 15); cout << "　■■■■■■■　　　　　　　　　　　　　　　　　　　　　　　　　　　"; SetColor(9, 15); cout << "■" << endl;	// 7
		cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;	// 8//기술
	}
	break;
	case 6:
	{
		cout << "■■□□□■■■□□□■■■□□□■■■□□□■■■□□□■■■□□□■■" << endl;	// 1
		cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;	// 2
		cout << "□"; SetColor(0, 15); cout << "　■■■■■■■　　　　　　　　　　　　　　　　　　　　　　　　　　　"; SetColor(9, 15); cout << "□" << endl;	// 3
		cout << "□"; SetColor(0, 15); cout << "　■　　　　　■　　　　　　　　　　　　　　　　　　　　　　　　　　　"; SetColor(9, 15); cout << "□" << endl;	// 4
		cout << "□"; SetColor(0, 15); cout << "　■　도　주　■　　　　　　　　　　　　　　　　　　　　　　　　　　　"; SetColor(9, 15); cout << "□" << endl;	// 5
		cout << "■"; SetColor(0, 15); cout << "　■　　　　　■　　　　　　　　　　　　　　　　　　　　　　　　　　　"; SetColor(9, 15); cout << "■" << endl;	// 6
		cout << "■"; SetColor(0, 15); cout << "　■■■■■■■　　　　　　　　　　　　　　　　　　　　　　　　　　　"; SetColor(9, 15); cout << "■" << endl;	// 7
		cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;	// 8//기술
	}
	break;
	case 7:
	{
		_mob1->MonsterSkill();
	}
	break;
	case 8:
	{
		_mob2->MonsterSkill();
	}
	break;
	}
}

void mainGame::FieldBattleInit()
{
	_skillTemp = 0;
	_skillcheck = 1;
	_monster1statecheck = 1;
	_charactercheck = 1;
	_monster2statecheck = 1;
	_battlecheck = 1;

	b_battleMusic = true;

	SetColor(15, 15);
	BootScreen2();
	gotoxy(0, 26);
	SetColor(9, 15);
	cout << "■■□□□■■■□□□■■■□□□■■■□□□■■■□□□■■■□□□■■" << endl;	// 27
	SetColor(8, 8);
	cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　" << endl;	// 32 
	cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　" << endl;	// 32
	cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　" << endl;	// 32 
	cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　" << endl;	// 32 
	cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　" << endl;	// 32 
	cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　" << endl;	// 32 
	cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　" << endl;	// 32 
	cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　" << endl;	// 32 
	cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　" << endl;	// 32 
	cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　" << endl;	// 32 

	int monster1 = 0;
	monster1 = rand() % 19 + 1; // 원숭이 1 ~7 박쥐 8 ~ 12 독사 13 ~ 16 멧돼지 17 18 19

	if (monster1 < 8)
	{
		_monkey1 = new monkey;
		monsterBase* _mob1 = _monkey1;
		BattleInitialization(_mob1);
		delete _monkey1;
	}
	else if (monster1 >= 8 && monster1 < 13)
	{
		_bat1 = new bat;
		monsterBase* _mob1 = _bat1;
		BattleInitialization(_mob1);
		delete _bat1;
	}
	else if (monster1 >= 13 && monster1 < 17)
	{
		_snake1 = new snake;
		monsterBase* _mob1 = _snake1;
		BattleInitialization(_mob1);
		delete _snake1;
	}
	else
	{
		_wildboar1 = new wildboar;
		monsterBase* _mob1 = _wildboar1;
		BattleInitialization(_mob1);
		delete _wildboar1;
	}
}


void mainGame::BattleInitialization(monsterBase* _mob1)
{
	int monster2 = 0;
	monster2 = rand() % 19 + 1; // 원숭이 1 ~7 박쥐 8 ~ 12 독사 13 ~ 16 멧돼지 17 18 19

	if (monster2 < 8)
	{
		_monkey2 = new monkey;
		monsterBase* _mob2 = _monkey2;
		BattleScreen(_mob1, _mob2);
		BattleChoice(_mob1, _mob2);
		delete _monkey2;
	}
	else if (monster2 >= 8 && monster2 < 13)
	{
		_bat2 = new bat;
		monsterBase* _mob2 = _bat2;
		BattleScreen(_mob1, _mob2);
		BattleChoice(_mob1, _mob2);
		delete _bat2;
	}
	else if (monster2 >= 13 && monster2 < 17)
	{
		_snake2 = new snake;
		monsterBase* _mob2 = _snake2;
		BattleScreen(_mob1, _mob2);
		BattleChoice(_mob1, _mob2);
		delete _snake2;
	}
	else
	{
		_wildboar2 = new wildboar;
		monsterBase* _mob2 = _wildboar2;
		BattleScreen(_mob1, _mob2);
		BattleChoice(_mob1, _mob2);
		delete _wildboar2;
	}
}

void mainGame::BattleScreen(monsterBase* _mob1, monsterBase* _mob2)
{
	SkillScreen(_mob1, _mob2); // _skillcheck
							   //////////////////////////////////////////////////////

	Monster1Screen(_mob1); // _monster1statecheck

						   //////////////////////////////////////////////////////

	CharacterScreen(); // _charactercheck

					   //////////////////////////////////////////////////////

	Monster2Screen(_mob2); // _monster2statecheck

						   //////////////////////////////////////////////////////

	BattleChoiceScreen(_mob1, _mob2); // _battlecheck
}


void mainGame::Monster1Screen(monsterBase* _mob1)
{
	gotoxy(0, 8);

	switch (_monster1statecheck)
	{
	case 0:
	{
		_mob1->MonsterDefeat2(); // complete defeat
	}
	break;
	case 1:
	{
		_mob1->MonsterNormal(); // normal
	}
	break;
	case 2:
	{
		_mob1->MonsterAtk(); // monsteratack
	}
	break;
	case 3:
	{
		_mob1->MonsterGetDmg1(); // 비상각
	}
	break;
	case 4:
	{
		_mob1->MonsterGetDmg2(); // 폭전축
	}
	break;
	case 5:
	{
		_mob1->MonsterGetDmg4(); // 대타격
	}
	break;
	case 6:
	{
		_mob1->MonsterGetDmg5(); // 쾌진격
	}
	break;
	case 7:
	{
		_mob1->MonsterDefeat1(); // defeat previous
	}
	break;
	}
}

void mainGame::Monster2Screen(monsterBase* _mob2)
{
	gotoxy(0, 20);

	switch (_monster2statecheck)
	{
	case 0:
	{
		_mob2->MonsterDefeat2(); // complete defeat
	}
	break;
	case 1:
	{
		_mob2->MonsterNormal(); // normal
	}
	break;
	case 2:
	{
		_mob2->MonsterAtk(); // monsteratack
	}
	break;
	case 3:
	{
		_mob2->MonsterGetDmg1(); // 비상각
	}
	break;
	case 4:
	{
		_mob2->MonsterGetDmg3(); // 폭전축
	}
	break;
	case 5:
	{
		_mob2->MonsterGetDmg4(); // 대타격
	}
	break;
	case 6:
	{
		_mob2->MonsterGetDmg5(); // 쾌진격
	}
	break;
	case 7:
	{
		_mob2->MonsterDefeat1(); // defeat previous
	}
	break;
	}
}

void mainGame::BattleChoiceScreen(monsterBase* _mob1, monsterBase* _mob2)
{
	gotoxy(0, 27);
	SetColor(0, 8);

	switch (_battlecheck)
	{
	case 1:
	{
		cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　" << endl;	// 28 이름
		cout << "　　　　　아타호　　체력 : " << _characterHp << " / " << _characterMaxHp << "　　　 기력 : " << _characterMp << " / " << _characterMaxMp << endl;
		cout << "　　　　　" << _mob1->GetMonsterName() << "　　체력 : " << _mob1->GetMonsterHp() << " / " << _mob1->GetMonsterMaxHp() << "　　　　　　　　　　" << endl;
		cout << "　　　　　" << _mob2->GetMonsterName() << "　　체력 : " << _mob2->GetMonsterHp() << " / " << _mob2->GetMonsterMaxHp() << "　　　　　　　　　　" << endl;
		cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　" << endl;	// 32 
		cout << "　　　▶　" << _character1stSkill << endl;
		cout << "　　　　　" << _character2ndSkill << "　　기력소모 : ";
		if (_characterMp < _2ndSkillNeedMp)
		{
			SetColor(12, 8);
		}
		cout << _2ndSkillNeedMp << endl;
		SetColor(0, 8);
		cout << "　　　　　아이템\n";
		cout << "　　　　　"; if (b_housecheck == true) { SetColor(8, 8); } cout << "도　주\n";
		cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　" << endl;	// 37
	}
	break;
	case 2:
	{
		cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　" << endl;	// 28 이름
		cout << "　　　　　아타호　　체력 : " << _characterHp << " / " << _characterMaxHp << "　　　 기력 : " << _characterMp << " / " << _characterMaxMp << endl;
		cout << "　　　　　" << _mob1->GetMonsterName() << "　　체력 : " << _mob1->GetMonsterHp() << " / " << _mob1->GetMonsterMaxHp() << "　　　　　　　　　　" << endl;
		cout << "　　　　　" << _mob2->GetMonsterName() << "　　체력 : " << _mob2->GetMonsterHp() << " / " << _mob2->GetMonsterMaxHp() << "　　　　　　　　　　" << endl;
		cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　" << endl;	// 32 
		cout << "　　　　　" << _character1stSkill << endl;
		cout << "　　　▶　" << _character2ndSkill << "　　기력소모 : ";
		if (_characterMp < _2ndSkillNeedMp)
		{
			SetColor(12, 8);
		}
		cout << _2ndSkillNeedMp << endl;
		SetColor(0, 8);
		cout << "　　　　　아이템\n";
		cout << "　　　　　"; if (b_housecheck == true) { SetColor(8, 8); } cout << "도　주\n";
		cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　" << endl;	// 37
	}
	break;
	case 3:
	{
		cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　" << endl;	// 28 이름
		cout << "　　　　　아타호　　체력 : " << _characterHp << " / " << _characterMaxHp << "　　　 기력 : " << _characterMp << " / " << _characterMaxMp << endl;
		cout << "　　　▶　" << _mob1->GetMonsterName() << "　　체력 : " << _mob1->GetMonsterHp() << " / " << _mob1->GetMonsterMaxHp() << "　　　　　　　　　　" << endl;
		cout << "　　　　　" << _mob2->GetMonsterName() << "　　체력 : " << _mob2->GetMonsterHp() << " / " << _mob2->GetMonsterMaxHp() << "　　　　　　　　　　" << endl;
		cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　" << endl;	// 32 
		cout << "　　　　　" << _character1stSkill << endl;
		cout << "　　　　　" << _character2ndSkill << "　　기력소모 : ";
		if (_characterMp < _2ndSkillNeedMp)
		{
			SetColor(12, 8);
		}
		cout << _2ndSkillNeedMp << endl;
		SetColor(0, 8);
		cout << "　　　　　아이템\n";
		cout << "　　　　　"; if (b_housecheck == true) { SetColor(8, 8); } cout << "도　주\n";
		cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　" << endl;	// 37 
	}
	break;
	case 4:
	{
		cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　" << endl;	// 28 이름
		cout << "　　　　　아타호　　체력 : " << _characterHp << " / " << _characterMaxHp << "　　　 기력 : " << _characterMp << " / " << _characterMaxMp << endl;
		cout << "　　　　　" << _mob1->GetMonsterName() << "　　체력 : " << _mob1->GetMonsterHp() << " / " << _mob1->GetMonsterMaxHp() << "　　　　　　　　　　" << endl;
		cout << "　　　▶　" << _mob2->GetMonsterName() << "　　체력 : " << _mob2->GetMonsterHp() << " / " << _mob2->GetMonsterMaxHp() << "　　　　　　　　　　" << endl;
		cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　" << endl;	// 32 
		cout << "　　　　　" << _character1stSkill << endl;
		cout << "　　　　　" << _character2ndSkill << "　　기력소모 : ";
		if (_characterMp < _2ndSkillNeedMp)
		{
			SetColor(12, 8);
		}
		cout << _2ndSkillNeedMp << endl;
		SetColor(0, 8);
		cout << "　　　　　아이템\n";
		cout << "　　　　　"; if (b_housecheck == true) { SetColor(8, 8); } cout << "도　주\n";
		cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　" << endl;	// 37 
	}
	break;
	case 5:
	{
		cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　" << endl;	// 28 이름
		cout << "　　　　　아타호　　체력 : " << _characterHp << " / " << _characterMaxHp << "　　　 기력 : " << _characterMp << " / " << _characterMaxMp << endl;
		cout << "　　　　　" << _mob1->GetMonsterName() << "　　체력 : " << _mob1->GetMonsterHp() << " / " << _mob1->GetMonsterMaxHp() << "　　　　　　　　　　" << endl;
		cout << "　　　　　" << _mob2->GetMonsterName() << "　　체력 : " << _mob2->GetMonsterHp() << " / " << _mob2->GetMonsterMaxHp() << "　　　　　　　　　　" << endl;
		cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　" << endl;	// 32 
		cout << "　　　　　" << _character1stSkill << endl;
		cout << "　　　　　" << _character2ndSkill << "　　기력소모 : ";
		if (_characterMp < _2ndSkillNeedMp)
		{
			SetColor(12, 8);
		}
		cout << _2ndSkillNeedMp << endl;
		SetColor(0, 8);
		cout << "　　　▶　아이템\n";
		cout << "　　　　　"; if (b_housecheck == true) { SetColor(8, 8); } cout << "도　주\n";
		cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　" << endl;	// 37 
	}
	break;
	case 6:
	{
		gotoxy(0, 27);
		SetColor(8, 8);
		cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　" << endl;	// 32 
		cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　" << endl;	// 32
		cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　" << endl;	// 32 
		cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　" << endl;	// 32 
		cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　" << endl;	// 32 
		cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　" << endl;	// 32 
		cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　" << endl;	// 32 
		cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　" << endl;	// 32 
		cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　" << endl;	// 32 
		cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　" << endl;	// 32 


		gotoxy(0, 27);
		SetColor(0, 8);
		cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　" << endl;	// 28 이름
		cout << "　　　　　아타호　　체력 : " << _characterHp << " / " << _characterMaxHp << "　　　 기력 : " << _characterMp << " / " << _characterMaxMp << endl;
		cout << "　　　　　" << _mob1->GetMonsterName() << "　　체력 : " << _mob1->GetMonsterHp() << " / " << _mob1->GetMonsterMaxHp() << "　　　　　　　　　　" << endl;
		cout << "　　　　　" << _mob2->GetMonsterName() << "　　체력 : " << _mob2->GetMonsterHp() << " / " << _mob2->GetMonsterMaxHp() << "　　　　　　　　　　" << endl;
		cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　" << endl;	// 32 
		cout << "　　　▶　약　초　　" << hb->GetHowMany() << " 개\n";
		cout << "　　　　　Hp포션　　" << po->GetHowMany() << " 개\n";
		cout << "　　　　　　　　　　\n";
		cout << "　　　　　　　　　　\n";
		cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　" << endl;	// 37 
	}
	break;
	case 7:
	{
		cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　" << endl;	// 28 이름
		cout << "　　　　　아타호　　체력 : " << _characterHp << " / " << _characterMaxHp << "　　　 기력 : " << _characterMp << " / " << _characterMaxMp << endl;
		cout << "　　　　　" << _mob1->GetMonsterName() << "　　체력 : " << _mob1->GetMonsterHp() << " / " << _mob1->GetMonsterMaxHp() << "　　　　　　　　　　" << endl;
		cout << "　　　　　" << _mob2->GetMonsterName() << "　　체력 : " << _mob2->GetMonsterHp() << " / " << _mob2->GetMonsterMaxHp() << "　　　　　　　　　　" << endl;
		cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　" << endl;	// 32 
		cout << "　　　　　약　초　　" << hb->GetHowMany() << " 개\n";
		cout << "　　　▶　Hp포션　　" << po->GetHowMany() << " 개\n";
		cout << "　　　　　　　　　　\n";
		cout << "　　　　　　　　　　\n";
		cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　" << endl;	// 37 
	}
	break;
	case 8:
	{
		cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　" << endl;	// 28 이름
		cout << "　　　▶　아타호　　체력 : " << _characterHp << " / " << _characterMaxHp << "　　　 기력 : " << _characterMp << " / " << _characterMaxMp << endl;
		cout << "　　　　　" << _mob1->GetMonsterName() << "　　체력 : " << _mob1->GetMonsterHp() << " / " << _mob1->GetMonsterMaxHp() << "　　　　　　　　　　" << endl;
		cout << "　　　　　" << _mob2->GetMonsterName() << "　　체력 : " << _mob2->GetMonsterHp() << " / " << _mob2->GetMonsterMaxHp() << "　　　　　　　　　　" << endl;
		cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　" << endl;	// 32 
		cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　" << endl;	// 37 
		cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　" << endl;	// 37 
		cout << "　　　　　　　　　　\n";
		cout << "　　　　　　　　　　\n";
		cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　" << endl;	// 37 
	}
	break;
	case 9:
	{
		cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　" << endl;	// 28 이름
		cout << "　　　　　아타호　　체력 : " << _characterHp << " / " << _characterMaxHp << "　　　 기력 : " << _characterMp << " / " << _characterMaxMp << endl;
		cout << "　　　　　" << _mob1->GetMonsterName() << "　　체력 : " << _mob1->GetMonsterHp() << " / " << _mob1->GetMonsterMaxHp() << "　　　　　　　　　　" << endl;
		cout << "　　　　　" << _mob2->GetMonsterName() << "　　체력 : " << _mob2->GetMonsterHp() << " / " << _mob2->GetMonsterMaxHp() << "　　　　　　　　　　" << endl;
		cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　" << endl;	// 32 
		cout << "　　　　　" << _character1stSkill << endl;
		cout << "　　　　　" << _character2ndSkill << "　　기력소모 : ";
		if (_characterMp < _2ndSkillNeedMp)
		{
			SetColor(12, 8);
		}
		cout << _2ndSkillNeedMp << endl;
		SetColor(0, 8);
		cout << "　　　　　아이템\n";
		cout << "　　　▶　"; if (b_housecheck == true) { SetColor(8, 8); } cout << "도　주\n";
		cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　" << endl;	// 37 
	}
	break;
	case 10:
	{
		gotoxy(0, 27);
		SetColor(8, 8);
		cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　" << endl;	// 32 
		cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　" << endl;	// 32
		cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　" << endl;	// 32 
		cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　" << endl;	// 32 
		cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　" << endl;	// 32 
		cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　" << endl;	// 32 
		cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　" << endl;	// 32 
		cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　" << endl;	// 32 
		cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　" << endl;	// 32 
		cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　" << endl;	// 32 

		gotoxy(0, 27);
		SetColor(0, 8);
		cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　" << endl;	// 28 이름
		cout << "　　　　　경험치" << _mob1->GetMonsterExp() << " 획득!\n";
		cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　" << endl;	// 30
		cout << "　　　　　금　전" << _mob1->GetMonsterMoney() << " 획득!\n";
		cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　" << endl;	// 32 
		cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　" << endl;	// 32 
		cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　" << endl;	// 32 
		cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　" << endl;	// 32 
		cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　" << endl;	// 32 
		cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　" << endl;	// 37 
	}
	break;
	case 11:
	{
		gotoxy(0, 27);
		SetColor(8, 8);
		cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　" << endl;	// 32 
		cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　" << endl;	// 32
		cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　" << endl;	// 32 
		cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　" << endl;	// 32 
		cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　" << endl;	// 32 
		cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　" << endl;	// 32 
		cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　" << endl;	// 32 
		cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　" << endl;	// 32 
		cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　" << endl;	// 32 
		cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　" << endl;	// 32 

		gotoxy(0, 27);
		SetColor(0, 8);
		cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　" << endl;	// 28 이름
		cout << "　　　　　경험치" << _mob1->GetMonsterExp() << " 획득!\n";
		cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　" << endl;	// 30
		cout << "　　　　　금　전" << _mob1->GetMonsterMoney() << " 획득!\n";
		cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　" << endl;	// 32 
		cout << "　　　　　약초씨 획득!\n";
		cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　" << endl;	// 32 
		cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　" << endl;	// 32 
		cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　" << endl;	// 32 
		cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　" << endl;	// 37 
	}
	break;
	case 12:
	{
		gotoxy(0, 27);
		SetColor(8, 8);
		cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　" << endl;	// 32 
		cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　" << endl;	// 32
		cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　" << endl;	// 32 
		cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　" << endl;	// 32 
		cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　" << endl;	// 32 
		cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　" << endl;	// 32 
		cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　" << endl;	// 32 
		cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　" << endl;	// 32 
		cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　" << endl;	// 32 
		cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　" << endl;	// 32 


		gotoxy(0, 27);
		SetColor(0, 8);
		cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　" << endl;	// 28 이름
		cout << "　　　　　경험치" << _mob2->GetMonsterExp() << " 획득!\n";
		cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　" << endl;	// 30
		cout << "　　　　　금　전" << _mob2->GetMonsterMoney() << " 획득!\n";
		cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　" << endl;	// 32 
		cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　" << endl;	// 32 
		cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　" << endl;	// 32 
		cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　" << endl;	// 32 
		cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　" << endl;	// 32 
		cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　" << endl;	// 37 
	}
	break;
	case 13:
	{
		gotoxy(0, 27);
		SetColor(8, 8);
		cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　" << endl;	// 32 
		cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　" << endl;	// 32
		cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　" << endl;	// 32 
		cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　" << endl;	// 32 
		cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　" << endl;	// 32 
		cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　" << endl;	// 32 
		cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　" << endl;	// 32 
		cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　" << endl;	// 32 
		cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　" << endl;	// 32 
		cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　" << endl;	// 32 

		gotoxy(0, 27);
		SetColor(0, 8);
		cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　" << endl;	// 28 이름
		cout << "　　　　　경험치" << _mob2->GetMonsterExp() << " 획득!\n";
		cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　" << endl;	// 30
		cout << "　　　　　금　전" << _mob2->GetMonsterMoney() << " 획득!\n";
		cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　" << endl;	// 32 
		cout << "　　　　　약초씨 획득!\n";
		cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　" << endl;	// 32 
		cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　" << endl;	// 32 
		cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　" << endl;	// 32 
		cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　" << endl;	// 37 
	}
	break;
	case 14:
	{
		gotoxy(0, 27);
		SetColor(8, 8);
		cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　" << endl;	// 32 
		cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　" << endl;	// 32
		cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　" << endl;	// 32 
		cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　" << endl;	// 32 
		cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　" << endl;	// 32 
		cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　" << endl;	// 32 
		cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　" << endl;	// 32 
		cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　" << endl;	// 32 
		cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　" << endl;	// 32 
		cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　" << endl;	// 32 


		gotoxy(0, 27);
		SetColor(0, 8);
		cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　" << endl;	// 28 이름
		cout << "　　　　　아타호　　체력 : " << _characterHp << " / " << _characterMaxHp << "　　　 기력 : " << _characterMp << " / " << _characterMaxMp << endl;
		cout << "　　　　　" << _mob1->GetMonsterName() << "　　체력 : " << _mob1->GetMonsterHp() << " / " << _mob1->GetMonsterMaxHp() << endl;
		cout << "　　　　　" << _mob2->GetMonsterName() << "　　체력 : " << _mob2->GetMonsterHp() << " / " << _mob2->GetMonsterMaxHp() << endl;
		cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　" << endl;	// 32 
		cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　" << endl;	// 37 
		cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　" << endl;	// 37 
		cout << "　　　　　　　　　　\n";
		cout << "　　　　　　　　　　\n";
		cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　" << endl;	// 37 
	}
	break;
	}
}



void mainGame::BattleChoice(monsterBase* _mob1, monsterBase* _mob2)
{
	_key = '0';
	_key = _getch();

	if (_key == (char)DOWN)
	{
		switch (_battlecheck)
		{
		case 1:
		{
			_battlecheck = 2;
			BattleChoiceScreen(_mob1, _mob2);
			BattleChoice(_mob1, _mob2);
		}
		break;
		case 2:
		{
			_battlecheck = 5;
			BattleChoiceScreen(_mob1, _mob2);
			BattleChoice(_mob1, _mob2);
		}
		break;
		case 3:
		{
			if (_mob2->GetMonsterHp() > 0)
			{
				_battlecheck = 4;
				BattleChoiceScreen(_mob1, _mob2);
				BattleChoice(_mob1, _mob2);
			}
			else
			{
				BattleChoice(_mob1, _mob2);
			}
		}
		break;
		case 5:
		{
			if (b_housecheck == false)
			{
				_battlecheck = 9;
				BattleChoiceScreen(_mob1, _mob2);
				BattleChoice(_mob1, _mob2);
			}
			else
			{
				BattleChoice(_mob1, _mob2);
			}
		}
		break;
		case 6:
		{
			_battlecheck = 7;
			BattleChoiceScreen(_mob1, _mob2);
			BattleChoice(_mob1, _mob2);
		}
		break;
		default:
		{
			BattleChoice(_mob1, _mob2);
		}
		break;
		}
	}
	else if (_key == (char)UP)
	{
		switch (_battlecheck)
		{
		case 2:
		{
			_battlecheck = 1;
			BattleChoiceScreen(_mob1, _mob2);
			BattleChoice(_mob1, _mob2);
		}
		break;
		case 5:
		{
			_battlecheck = 2;
			BattleChoiceScreen(_mob1, _mob2);
			BattleChoice(_mob1, _mob2);
		}
		break;
		case 4:
		{
			if (_mob1->GetMonsterHp() > 0)
			{
				_battlecheck = 3;
				BattleChoiceScreen(_mob1, _mob2);
				BattleChoice(_mob1, _mob2);
			}
			else
			{
				BattleChoice(_mob1, _mob2);
			}
		}
		break;
		case 7:
		{
			_battlecheck = 6;
			BattleChoiceScreen(_mob1, _mob2);
			BattleChoice(_mob1, _mob2);
		}
		break;
		case 9:
		{
			_battlecheck = 5;
			BattleChoiceScreen(_mob1, _mob2);
			BattleChoice(_mob1, _mob2);
		}
		break;
		default:
		{
			BattleChoice(_mob1, _mob2);
		}
		break;
		}
	}
	else if (_key == (char)ENTER || _key == (char)SPACE)
	{
		switch (_battlecheck)
		{
		case 1:
		{
			_skillTemp = 1;

			if (_mob1->GetMonsterHp() > 0)
			{
				_battlecheck = 3;
				BattleChoiceScreen(_mob1, _mob2);
				BattleChoice(_mob1, _mob2);
			}
			else
			{
				_battlecheck = 4;
				BattleChoiceScreen(_mob1, _mob2);
				BattleChoice(_mob1, _mob2);
			}
		}
		break;
		case 2:
		{
			if (_characterMp < _2ndSkillNeedMp)
			{
				BattleChoice(_mob1, _mob2);
			}
			else
			{
				_skillTemp = 2;

				if (_mob1->GetMonsterHp() > 0)
				{
					_battlecheck = 3;
					BattleChoiceScreen(_mob1, _mob2);
					BattleChoice(_mob1, _mob2);
				}
				else
				{
					_battlecheck = 4;
					BattleChoiceScreen(_mob1, _mob2);
					BattleChoice(_mob1, _mob2);
				}
			}
		}
		break;

		case 3:
		{
			if (_skillTemp == 1)
			{
				if (_character1stSkill == "비상각")
				{
					_skillcheck = 2;
					_battlecheck = 14;
					SkillScreen(_mob1, _mob2);
					BattleChoiceScreen(_mob1, _mob2);
					// sound
					Sleep(1500);
					//////////////////////////
					_monster1statecheck = 3;
					_charactercheck = 5;
					_effect = Eskill1; ///////// sound
					BattleScreen(_mob1, _mob2);
					Sleep(1200);
				}
				else if (_character1stSkill == "대타격")
				{
					_skillcheck = 4;
					_battlecheck = 14;
					SkillScreen(_mob1, _mob2);
					BattleChoiceScreen(_mob1, _mob2);
					// sound
					Sleep(1500);
					//////////////////////////
					_monster1statecheck = 5;
					_charactercheck = 5;
					_effect = Eskill3; ///////// sound
					BattleScreen(_mob1, _mob2);
					Sleep(1200);
				}
				_skillcheck = 1;
				_skillTemp = 0;
				_charactercheck = 1;
				_mob1->MonsterGetDamaged(_1stSkillDmg);

				if (_mob1->GetMonsterHp() <= 0)
				{
					_mob1->SetMonsterHp(0);
				}

				if (_mob1->GetMonsterHp() == 0) // monster 1 dead
				{
					_monster1statecheck = 7;
					BattleScreen(_mob1, _mob2);
					Sleep(700);
					Monster1Blink(_mob1);
					_monster1statecheck = 0;
					Monster1Screen(_mob1);
					gotoxy(0, 36);
					Sleep(600);

					if (_mob1->GetMonsterSeed() > 10) // monster not had a seed
					{
						_battlecheck = 10;
						BattleChoiceScreen(_mob1, _mob2);
						_characterExp = _characterExp + _mob1->GetMonsterExp();
						if (_characterExp > _characterMaxExp)
						{
							_characterExp = _characterMaxExp;
						}
						_characterMoney = _characterMoney + _mob1->GetMonsterMoney();

						Sleep(1500);
					}
					else // monster had a seed
					{
						_battlecheck = 11;
						BattleChoiceScreen(_mob1, _mob2);
						_characterExp = _characterExp + _mob1->GetMonsterExp();
						if (_characterExp > _characterMaxExp)
						{
							_characterExp = _characterMaxExp;
						}
						_characterMoney = _characterMoney + _mob1->GetMonsterMoney();
						++_characterSeed;

						Sleep(1500);
					}

					_battlecheck = 14;
					BattleChoiceScreen(_mob1, _mob2);

					if (_mob2->GetMonsterHp() == 0) // monster 2 also dead >> battle off
					{
						b_battleMusic = false;
						Sleep(800);
						if (b_housecheck == false)
						{
							_effect = Evictory;
						}
						Sleep(1500);
						Move2();
						_skillcheck = 0;
						_charactercheck = 0;
						_monster1statecheck = 0;
						_monster2statecheck = 0;
						_battlecheck = 0;

						return;
					}
					else // monster 2 is not dead yet >> continue to monster attack
					{
						Sleep(800);
						MonsterAttack(_mob1, _mob2);
					}
				}
				else // monster 1 not dead
				{
					_monster1statecheck = 1;
					BattleScreen(_mob1, _mob2);
					Sleep(800);

					MonsterAttack(_mob1, _mob2);
				}
			}
			else if (_skillTemp == 2)
			{
				if (_character2ndSkill == "폭전축")
				{
					_skillcheck = 3;
					_battlecheck = 14;
					SkillScreen(_mob1, _mob2);
					BattleChoiceScreen(_mob1, _mob2);
					// sound
					Sleep(1500);
					//////////////////////////
					_characterMp = _characterMp - _2ndSkillNeedMp;

					_monster1statecheck = 4;
					_charactercheck = 2;
					_effect = Eskill2; ///////// sound
					BattleScreen(_mob1, _mob2);
					Sleep(1200);
				}
				else if (_character2ndSkill == "쾌진격")
				{
					_skillcheck = 5;
					_battlecheck = 14;
					SkillScreen(_mob1, _mob2);
					BattleChoiceScreen(_mob1, _mob2);
					// sound
					Sleep(1500);
					//////////////////////////
					_characterMp = _characterMp - _2ndSkillNeedMp;

					_monster1statecheck = 6;
					_charactercheck = 5;
					_effect = Eskill4; ///////// sound
					BattleScreen(_mob1, _mob2);
					Sleep(1200);
				}
				_skillcheck = 1;
				_skillTemp = 0;
				_charactercheck = 1;
				_mob1->MonsterGetDamaged((int)_2ndSkillDmg);

				if (_mob1->GetMonsterHp() < 0)
				{
					_mob1->SetMonsterHp(0);
				}

				if (_mob1->GetMonsterHp() == 0) // monster 1 dead
				{
					_monster1statecheck = 7;
					BattleScreen(_mob1, _mob2);
					Sleep(700);
					Monster1Blink(_mob1);
					_monster1statecheck = 0;
					Monster1Screen(_mob1);
					gotoxy(0, 36);
					Sleep(600);

					if (_mob1->GetMonsterSeed() > 10) // monster not had a seed
					{
						_battlecheck = 10;
						BattleChoiceScreen(_mob1, _mob2);
						_characterExp = _characterExp + _mob1->GetMonsterExp();
						if (_characterExp > _characterMaxExp)
						{
							_characterExp = _characterMaxExp;
						}
						_characterMoney = _characterMoney + _mob1->GetMonsterMoney();

						Sleep(1500);
					}
					else // monster had a seed
					{
						_battlecheck = 11;
						BattleChoiceScreen(_mob1, _mob2);
						_characterExp = _characterExp + _mob1->GetMonsterExp();
						if (_characterExp > _characterMaxExp)
						{
							_characterExp = _characterMaxExp;
						}
						_characterMoney = _characterMoney + _mob1->GetMonsterMoney();
						++_characterSeed;

						Sleep(1500);
					}

					_battlecheck = 14;
					BattleChoiceScreen(_mob1, _mob2);

					if (_mob2->GetMonsterHp() == 0) // monster 2 also dead >> battle off
					{
						b_battleMusic = false;
						Sleep(800);
						if (b_housecheck == false)
						{
							_effect = Evictory;
						}
						Sleep(1500);
						Move2();
						_skillcheck = 0;
						_charactercheck = 0;
						_monster1statecheck = 0;
						_monster2statecheck = 0;
						_battlecheck = 0;

						return;
					}
					else // monster 2 is not dead yet >> continue to monster attack
					{
						Sleep(800);
						MonsterAttack(_mob1, _mob2);
					}
				}
				else // monster 1 not dead
				{
					_monster1statecheck = 1;
					BattleScreen(_mob1, _mob2);
					Sleep(800);

					MonsterAttack(_mob1, _mob2);
				}
			}
		}
		break;

		case 4:
		{
			if (_skillTemp == 1)
			{
				if (_character1stSkill == "비상각")
				{
					_skillcheck = 2;
					_battlecheck = 14;
					SkillScreen(_mob1, _mob2);
					BattleChoiceScreen(_mob1, _mob2);
					// sound
					Sleep(1500);
					//////////////////////////
					_monster2statecheck = 3;
					_charactercheck = 5;
					_effect = Eskill1; ///////// sound
					BattleScreen(_mob1, _mob2);
					Sleep(1200);
				}
				else if (_character1stSkill == "대타격")
				{
					_skillcheck = 4;
					_battlecheck = 14;
					SkillScreen(_mob1, _mob2);
					BattleChoiceScreen(_mob1, _mob2);
					// sound
					Sleep(1500);
					//////////////////////////
					_monster2statecheck = 5;
					_charactercheck = 5;
					_effect = Eskill3; ///////// sound
					BattleScreen(_mob1, _mob2);
					Sleep(1200);
				}
				_skillcheck = 1;
				_skillTemp = 0;
				_charactercheck = 1;
				_mob2->MonsterGetDamaged(_1stSkillDmg);

				if (_mob2->GetMonsterHp() <= 0)
				{
					_mob2->SetMonsterHp(0);
				}

				if (_mob2->GetMonsterHp() == 0) // monster 2 dead
				{
					_monster2statecheck = 7;
					BattleScreen(_mob1, _mob2);
					Sleep(700);
					Monster2Blink(_mob2);
					_monster2statecheck = 0;
					Monster2Screen(_mob2);
					gotoxy(0, 36);
					Sleep(600);

					if (_mob2->GetMonsterSeed() > 10) // monster not had a seed
					{
						_battlecheck = 12;
						BattleChoiceScreen(_mob1, _mob2);
						_characterExp = _characterExp + _mob2->GetMonsterExp();
						if (_characterExp > _characterMaxExp)
						{
							_characterExp = _characterMaxExp;
						}
						_characterMoney = _characterMoney + _mob2->GetMonsterMoney();

						Sleep(1500);
					}
					else // monster had a seed
					{
						_battlecheck = 13;
						BattleChoiceScreen(_mob1, _mob2);
						_characterExp = _characterExp + _mob2->GetMonsterExp();
						if (_characterExp > _characterMaxExp)
						{
							_characterExp = _characterMaxExp;
						}
						_characterMoney = _characterMoney + _mob2->GetMonsterMoney();
						++_characterSeed;

						Sleep(1500);
					}

					_battlecheck = 14;
					BattleChoiceScreen(_mob1, _mob2);

					if (_mob1->GetMonsterHp() == 0) // monster 1 also dead >> battle off
					{
						b_battleMusic = false;
						Sleep(800);
						if (b_housecheck == false)
						{
							_effect = Evictory;
						}
						Sleep(1500);
						Move2();
						_skillcheck = 0;
						_charactercheck = 0;
						_monster1statecheck = 0;
						_monster2statecheck = 0;
						_battlecheck = 0;

						return;
					}
					else // monster 1 is not dead yet >> continue to monster attack
					{
						Sleep(800);
						MonsterAttack(_mob1, _mob2);
					}
				}
				else // monster 2 not dead
				{
					_monster2statecheck = 1;
					BattleScreen(_mob1, _mob2);
					Sleep(800);

					MonsterAttack(_mob1, _mob2);
				}
			}
			else if (_skillTemp == 2)
			{
				if (_character2ndSkill == "폭전축")
				{
					_skillcheck = 3;
					_battlecheck = 14;
					SkillScreen(_mob1, _mob2);
					BattleChoiceScreen(_mob1, _mob2);
					// sound
					Sleep(1500);
					//////////////////////////
					_characterMp = _characterMp - _2ndSkillNeedMp;

					_monster2statecheck = 4;
					_charactercheck = 7;
					_effect = Eskill2; ///////// sound
					BattleScreen(_mob1, _mob2);
					Sleep(1200);
				}
				else if (_character2ndSkill == "쾌진격")
				{
					_skillcheck = 5;
					_battlecheck = 14;
					SkillScreen(_mob1, _mob2);
					BattleChoiceScreen(_mob1, _mob2);
					// sound
					Sleep(1500);
					//////////////////////////
					_characterMp = _characterMp - _2ndSkillNeedMp;

					_monster2statecheck = 6;
					_charactercheck = 5;
					_effect = Eskill4; ///////// sound
					BattleScreen(_mob1, _mob2);
					Sleep(1200);
				}
				_skillcheck = 1;
				_skillTemp = 0;
				_charactercheck = 1;
				_mob2->MonsterGetDamaged((int)_2ndSkillDmg);

				if (_mob2->GetMonsterHp() < 0)
				{
					_mob2->SetMonsterHp(0);
				}

				if (_mob2->GetMonsterHp() == 0) // monster 2 dead
				{
					_monster2statecheck = 7;
					BattleScreen(_mob1, _mob2);
					Sleep(700);
					Monster2Blink(_mob2);
					_monster2statecheck = 0;
					Monster2Screen(_mob2);
					gotoxy(0, 36);
					Sleep(600);

					if (_mob2->GetMonsterSeed() > 10) // monster not had a seed
					{
						_battlecheck = 12;
						BattleChoiceScreen(_mob1, _mob2);
						_characterExp = _characterExp + _mob2->GetMonsterExp();
						if (_characterExp > _characterMaxExp)
						{
							_characterExp = _characterMaxExp;
						}
						_characterMoney = _characterMoney + _mob2->GetMonsterMoney();

						Sleep(1500);
					}
					else // monster had a seed
					{
						_battlecheck = 13;
						BattleChoiceScreen(_mob1, _mob2);
						_characterExp = _characterExp + _mob2->GetMonsterExp();
						if (_characterExp > _characterMaxExp)
						{
							_characterExp = _characterMaxExp;
						}
						_characterMoney = _characterMoney + _mob2->GetMonsterMoney();
						++_characterSeed;

						Sleep(1500);
					}

					_battlecheck = 14;
					BattleChoiceScreen(_mob1, _mob2);

					if (_mob1->GetMonsterHp() == 0) // monster 1 also dead >> battle off
					{
						b_battleMusic = false;
						Sleep(800);
						if (b_housecheck == false)
						{
							_effect = Evictory;
						}
						Sleep(1500);
						Move2();
						_skillcheck = 0;
						_charactercheck = 0;
						_monster1statecheck = 0;
						_monster2statecheck = 0;
						_battlecheck = 0;

						return;
					}
					else // monster 1 is not dead yet >> continue to monster attack
					{
						Sleep(800);
						MonsterAttack(_mob1, _mob2);
					}
				}
				else // monster 2 not dead
				{
					_monster2statecheck = 1;
					BattleScreen(_mob1, _mob2);
					Sleep(800);

					MonsterAttack(_mob1, _mob2);
				}
			}
		}
		break;

		case 5:
		{
			_battlecheck = 6;
			BattleChoiceScreen(_mob1, _mob2);
			BattleChoice(_mob1, _mob2);
		}
		break;
		case 6:
		{
			if (hb->GetHowMany() > 0)
			{
				_battlecheck = 8;
				_drugtype = 1;
				BattleChoiceScreen(_mob1, _mob2);
				BattleChoice(_mob1, _mob2);
			}
			else
			{
				_effect = Eerror;
				BattleChoice(_mob1, _mob2);
			}
		}
		break;
		case 7:
		{
			if (po->GetHowMany() > 0)
			{
				_battlecheck = 8;
				_drugtype = 2;
				BattleChoiceScreen(_mob1, _mob2);
				BattleChoice(_mob1, _mob2);
			}
			else
			{
				_effect = Eerror;
				BattleChoice(_mob1, _mob2);
			}
		}
		break;
		case 8:
		{
			if (_drugtype == 1)
			{
				_characterHp = _characterHp + hb->GetHpUp();
				_effect = Eheal;
				if (_characterHp > _characterMaxHp)
				{
					_characterHp = _characterMaxHp;
				}
				hb->SetHowMany(hb->GetHowMany() - 1);
			}
			else if (_drugtype == 2)
			{
				_characterHp = _characterHp + po->GetHpUp();
				_effect = Eheal;
				if (_characterHp > _characterMaxHp)
				{
					_characterHp = _characterMaxHp;
				}
				po->SetHowMany(po->GetHowMany() - 1);
			}
			_drugtype = 0;
			//sound heal

			_battlecheck = 14;
			BattleChoiceScreen(_mob1, _mob2);
			Sleep(1200);

			MonsterAttack(_mob1, _mob2);
		}
		break;
		case 9:
		{
			if (b_housecheck == false)
			{
				_skillcheck = 6;
				_battlecheck = 14;
				_charactercheck = 4;
				_effect = Erun;
				BattleScreen(_mob1, _mob2);
				Sleep(1500);
				b_battleMusic = false;
				Move2();
				_skillcheck = 0;
				_charactercheck = 0;
				_monster1statecheck = 0;
				_monster2statecheck = 0;
				_battlecheck = 0;
				return;
			}
			else
			{
				BattleChoice(_mob1, _mob2);
			}
		}
		break;
		default:
		{
			BattleChoice(_mob1, _mob2);
		}
		break;
		}
	}
	else if (_key == (char)ESC)
	{
		switch (_battlecheck)
		{
		case 3:
		case 4:
		{
			_effect = Ecancle;

			if (_skillTemp == 1)
			{
				_battlecheck = 1;
				BattleChoiceScreen(_mob1, _mob2);
				BattleChoice(_mob1, _mob2);
				_skillTemp = 0;
			}
			else
			{
				_battlecheck = 2;
				BattleChoiceScreen(_mob1, _mob2);
				BattleChoice(_mob1, _mob2);
				_skillTemp = 0;
			}

		}
		break;
		case 6:
		case 7:
		{
			_effect = Ecancle;

			_battlecheck = 5;
			BattleChoiceScreen(_mob1, _mob2);
			BattleChoice(_mob1, _mob2);
		}
		break;
		case 8:
		{
			_effect = Ecancle;

			if (_drugtype == 1)
			{
				_battlecheck = 6;
				BattleChoiceScreen(_mob1, _mob2);
				BattleChoice(_mob1, _mob2);
				_drugtype = 0;
			}
			else
			{
				_battlecheck = 7;
				BattleChoiceScreen(_mob1, _mob2);
				BattleChoice(_mob1, _mob2);
				_drugtype = 0;
			}
		}
		break;
		default:
		{
			BattleChoice(_mob1, _mob2);
		}
		break;
		}
	}
	else
	{
		BattleChoice(_mob1, _mob2);
	}
}






void mainGame::Monster1Blink(monsterBase* _mob1)
{
	_monster1statecheck = 0;
	Monster1Screen(_mob1);
	Sleep(270);
	_monster1statecheck = 7;
	Monster1Screen(_mob1);
	Sleep(270);
	_monster1statecheck = 0;
	Monster1Screen(_mob1);
	Sleep(270);
	_monster1statecheck = 7;
	Monster1Screen(_mob1);
	Sleep(270);
	_monster1statecheck = 0;
	Monster1Screen(_mob1);
	Sleep(270);
	_monster1statecheck = 7;
	Monster1Screen(_mob1);
	Sleep(270);
}

void mainGame::Monster2Blink(monsterBase* _mob2)
{
	_monster2statecheck = 0;
	Monster2Screen(_mob2);
	Sleep(270);
	_monster2statecheck = 7;
	Monster2Screen(_mob2);
	Sleep(270);
	_monster2statecheck = 0;
	Monster2Screen(_mob2);
	Sleep(270);
	_monster2statecheck = 7;
	Monster2Screen(_mob2);
	Sleep(270);
	_monster2statecheck = 0;
	Monster2Screen(_mob2);
	Sleep(270);
	_monster2statecheck = 7;
	Monster2Screen(_mob2);
	Sleep(270);
}


void mainGame::MonsterAttack(monsterBase* _mob1, monsterBase* _mob2)
{
	if (_mob1->GetMonsterHp() != 0)
	{

		_skillcheck = 7;
		_monster1statecheck = 2;
		_charactercheck = 3;

		_characterHp = _characterHp - _mob1->GetMonsterAtk();

		if (_mob1->GetMonsterName() == "원숭이")
		{
			_effect = Emonkey;
		}
		else if (_mob1->GetMonsterName() == "박　쥐")
		{
			_effect = Ebat;
		}
		else if (_mob1->GetMonsterName() == "독　사")
		{
			_effect = Esnake;
		}
		else if (_mob1->GetMonsterName() == "멧돼지")
		{
			_effect = Ewildboar;
		}
		else if (_mob1->GetMonsterName() == "감염자")
		{
			_effect = Ehuman1;
		}
		else if (_mob1->GetMonsterName() == "환　자")
		{
			_effect = Ehuman2;
		}

		if (_characterHp < 0) // character dead
		{
			_characterHp = 0;
			BattleScreen(_mob1, _mob2);
			Sleep(1200);
			_skillcheck = 1;
			_monster1statecheck = 1;
			_charactercheck = 6;
			BattleScreen(_mob1, _mob2);
			Sleep(1500);
			b_battleMusic = false;
			_skillcheck = 0;
			_charactercheck = 0;
			_monster1statecheck = 0;
			_monster2statecheck = 0;
			_battlecheck = 0;

			return;
		}
		else
		{
			BattleScreen(_mob1, _mob2);
			Sleep(1200);

			_skillcheck = 1;
			_monster1statecheck = 1;
			_charactercheck = 1;
			BattleScreen(_mob1, _mob2);

			if (_mob2->GetMonsterHp() != 0)
			{
				Sleep(1000);
			}

		}
	}

	if (_mob2->GetMonsterHp() != 0)
	{
		_skillcheck = 8;
		_monster2statecheck = 2;
		_charactercheck = 3;

		_characterHp = _characterHp - _mob2->GetMonsterAtk();

		if (_mob2->GetMonsterName() == "원숭이")
		{
			_effect = Emonkey;
		}
		else if (_mob2->GetMonsterName() == "박　쥐")
		{
			_effect = Ebat;
		}
		else if (_mob2->GetMonsterName() == "독　사")
		{
			_effect = Esnake;
		}
		else if (_mob2->GetMonsterName() == "멧돼지")
		{
			_effect = Ewildboar;
		}
		else if (_mob2->GetMonsterName() == "감염자")
		{
			_effect = Ehuman1;
		}
		else if (_mob2->GetMonsterName() == "환　자")
		{
			_effect = Ehuman2;
		}

		if (_characterHp < 0) // character dead
		{
			_characterHp = 0;
			BattleScreen(_mob1, _mob2);
			Sleep(1200);
			_skillcheck = 1;
			_monster2statecheck = 1;
			_charactercheck = 6;
			BattleScreen(_mob1, _mob2);
			Sleep(1500);
			b_battleMusic = false;

			return;
		}
		else
		{
			BattleScreen(_mob1, _mob2);
			Sleep(1200);

			_skillcheck = 1;
			_monster2statecheck = 1;
			_charactercheck = 1;
			BattleScreen(_mob1, _mob2);
		}
	}

	_battlecheck = 1;
	BattleScreen(_mob1, _mob2);
	BattleChoice(_mob1, _mob2);
}

void mainGame::WorldMapScreen()
{
	gotoxy(0, 0);
	SetColor(9, 15);

	switch (_worldcheck)
	{
	case 1:
	{
		cout << "■■□□□■■■□□□■■■□□□■■■□□□■■■□□□■■■□□□■■" << endl;	// 1
		cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;	// 2
		cout << "□　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　□" << endl;	// 3
		cout << "□"; SetColor(0, 15); cout << "　　■■■■■■■　　　　　　　　　　　　　　　　　　　　　　　　　　"; SetColor(9, 15); cout << "□" << endl;	// 4
		cout << "□"; SetColor(0, 15); cout << "　　■　　　　　■　　　　　　　　　　　　　　　　　　　　　　　　　　"; SetColor(9, 15); cout << "□" << endl;	// 5
		cout << "■"; SetColor(0, 15); cout << "　　■　호랑이　■　　　　　　　　　　　　　　　　　　　　　　　　　　"; SetColor(9, 15); cout << "■" << endl;	// 6
		cout << "■"; SetColor(0, 15); cout << "　　■　　　　　■　　　　　　　　　　　　　　　　　　　　　　　　　　"; SetColor(9, 15); cout << "■" << endl;	// 7
		cout << "■"; SetColor(0, 15); cout << "　　■　바위산　■　　　　　　　　　　　　　　　　　　　　　　　　　　"; SetColor(9, 15); cout << "■" << endl;	// 8
		cout << "□"; SetColor(0, 15); cout << "　　■　　　　　■　　　　　　　　　　　　　　　　　　　　　　　　　　"; SetColor(9, 15); cout << "□" << endl;	// 9
		cout << "□"; SetColor(0, 15); cout << "　　■■■■■■■　　　　　　　　　　　　　　　　　　■　　　　　　　"; SetColor(9, 15); cout << "□" << endl;	// 10
		cout << "□"; SetColor(0, 15); cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　■　■　　　　　　"; SetColor(9, 15); cout << "□" << endl;	// 11
		cout << "■"; SetColor(0, 15); cout << "　　　　　　　　　　　　　　　　　　　　　　■　　■　　　■　　　　　"; SetColor(9, 15); cout << "■" << endl;	// 12
		cout << "■"; SetColor(0, 15); cout << "　　　　　　　　　　　　　　　　　　　　　■　■■　　　　　■　■　　"; SetColor(9, 15); cout << "■" << endl;	// 13
		cout << "■"; SetColor(0, 15); cout << "　　　　　　　　　　　　　　　　　　　　■　　　■　　　　　　■　■　"; SetColor(9, 15); cout << "■" << endl;	// 14
		cout << "□"; SetColor(0, 15); cout << "　　　　　　　　　　　　　　　　　　　■　　　　　■"; SetColor(14, 15); cout << "　■　"; SetColor(0, 15); cout << "　■　　　■"; SetColor(9, 15); cout << "□" << endl;	// 15
		cout << "□"; SetColor(0, 15); cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　"; SetColor(14, 15); cout << "■■■"; SetColor(0, 15); cout << "■　　　　　"; SetColor(9, 15); cout << "□" << endl;	// 16
		cout << "□"; SetColor(0, 15); cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　"; SetColor(14, 15); cout << "　■　　　　　　　"; SetColor(9, 15); cout << "□" << endl;	// 17
		cout << "■"; SetColor(0, 15); cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　"; SetColor(14, 15); cout << "■"; SetColor(0, 15); cout << "□"; SetColor(14, 15); cout << "■　　　　　　"; SetColor(9, 15); cout << "■" << endl;	// 18
		cout << "■"; SetColor(0, 15); cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　□　　　　　　　"; SetColor(9, 15); cout << "■" << endl;	// 19
		cout << "■"; SetColor(0, 15); cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　□　　　　　　　"; SetColor(9, 15); cout << "■" << endl;	// 20
		cout << "□"; SetColor(0, 15); cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　□　　　　　　　"; SetColor(9, 15); cout << "□" << endl;	// 21
		cout << "□"; SetColor(0, 15); cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　□　　　　　　　"; SetColor(9, 15); cout << "□" << endl;	// 22
		cout << "□"; SetColor(0, 15); cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　□　　　　　　　"; SetColor(9, 15); cout << "□" << endl;	// 23
		cout << "■"; SetColor(0, 15); cout << "　　　　　　■■　　　　　　　　　　　　　　　　　　　□　　　　　　　"; SetColor(9, 15); cout << "■" << endl;	// 24
		cout << "■"; SetColor(0, 15); cout << "　　　　　■　　■　　　　　　　　　　　　　　　■■■■　　　　　　　"; SetColor(9, 15); cout << "■" << endl;	// 25
		cout << "■"; SetColor(0, 15); cout << "　　　　■　■■　■　　　　　　　　　　　　　■■■■■■　　　　　　"; SetColor(9, 15); cout << "■" << endl;	// 26
		cout << "□"; SetColor(0, 15); cout << "　　■■■　■■　■　■■　　　　　　　　　　　■　　■　　　　　　　"; SetColor(9, 15); cout << "□" << endl;	// 27
		cout << "□"; SetColor(0, 15); cout << "　■　　■　　　　　■　　■　　　　　　　　　　■■■■　　　　　　　"; SetColor(9, 15); cout << "□" << endl;	// 28
		cout << "□"; SetColor(0, 15); cout << "■　■■　■　　　■　■■　■　　　　　　■■■■　　■■■■　　　　"; SetColor(9, 15); cout << "□" << endl;	// 29
		cout << "■"; SetColor(0, 15); cout << "■　■■　■　　　■　■■　■　　　　　■■■■■■■■■■■■　　　"; SetColor(9, 15); cout << "■" << endl;	// 30
		cout << "■"; SetColor(0, 15); cout << "　　　　　　　　　　　　　　　　　　　　　■　　■　　■　　■　　　　"; SetColor(9, 15); cout << "■" << endl;	// 31
		cout << "■"; SetColor(0, 15); cout << "　　　　　　　　　　　　　　　　　　　　　■■■■　　■■■■　　　　"; SetColor(9, 15); cout << "■" << endl;	// 32
		cout << "□　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　□" << endl;	// 33
		cout << "□　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　□" << endl;	// 34
		cout << "□　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　□" << endl;	// 35
		cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;	// 36
		cout << "■■□□□■■■□□□■■■□□□■■■□□□■■■□□□■■■□□□■■" << endl;	// 37
	}
	break;
	case 2:
	{
		cout << "■■□□□■■■□□□■■■□□□■■■□□□■■■□□□■■■□□□■■" << endl;	// 1
		cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;	// 2
		cout << "□　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　□" << endl;	// 3
		cout << "□"; SetColor(0, 15); cout << "　　■■■■■■■　　　　　　　　　　　　　　　　　　　　　　　　　　"; SetColor(9, 15); cout << "□" << endl;	// 4
		cout << "□"; SetColor(0, 15); cout << "　　■　　　　　■　　　　　　　　　　　　　　　　　　　　　　　　　　"; SetColor(9, 15); cout << "□" << endl;	// 5
		cout << "■"; SetColor(0, 15); cout << "　　■　유　목　■　　　　　　　　　　　　　　　　　　　　　　　　　　"; SetColor(9, 15); cout << "■" << endl;	// 6
		cout << "■"; SetColor(0, 15); cout << "　　■　　　　　■　　　　　　　　　　　　　　　　　　　　　　　　　　"; SetColor(9, 15); cout << "■" << endl;	// 7
		cout << "■"; SetColor(0, 15); cout << "　　■　마　을　■　　　　　　　　　　　　　　　　　　　　　　　　　　"; SetColor(9, 15); cout << "■" << endl;	// 8
		cout << "□"; SetColor(0, 15); cout << "　　■　　　　　■　　　　　　　　　　　　　　　　　　　　　　　　　　"; SetColor(9, 15); cout << "□" << endl;	// 9
		cout << "□"; SetColor(0, 15); cout << "　　■■■■■■■　　　　　　　　　　　　　　　　　　■　　　　　　　"; SetColor(9, 15); cout << "□" << endl;	// 10
		cout << "□"; SetColor(0, 15); cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　■　■　　　　　　"; SetColor(9, 15); cout << "□" << endl;	// 11
		cout << "■"; SetColor(0, 15); cout << "　　　　　　　　　　　　　　　　　　　　　　■　　■　　　■　　　　　"; SetColor(9, 15); cout << "■" << endl;	// 12
		cout << "■"; SetColor(0, 15); cout << "　　　　　　　　　　　　　　　　　　　　　■　■■　　　　　■　■　　"; SetColor(9, 15); cout << "■" << endl;	// 13
		cout << "■"; SetColor(0, 15); cout << "　　　　　　　　　　　　　　　　　　　　■　　　■　　　　　　■　■　"; SetColor(9, 15); cout << "■" << endl;	// 14
		cout << "□"; SetColor(0, 15); cout << "　　　　　　　　　　　　　　　　　　　■　　　　　■　　　　■　　　■"; SetColor(9, 15); cout << "□" << endl;	// 15
		cout << "□"; SetColor(0, 15); cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■　　　　　"; SetColor(9, 15); cout << "□" << endl;	// 16
		cout << "□"; SetColor(0, 15); cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　□　　　　　　　"; SetColor(9, 15); cout << "□" << endl;	// 17
		cout << "■"; SetColor(0, 15); cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　□　　　　　　　"; SetColor(9, 15); cout << "■" << endl;	// 18
		cout << "■"; SetColor(0, 15); cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　□　　　　　　　"; SetColor(9, 15); cout << "■" << endl;	// 19
		cout << "■"; SetColor(0, 15); cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　□　　　　　　　"; SetColor(9, 15); cout << "■" << endl;	// 20
		cout << "□"; SetColor(0, 15); cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　"; SetColor(14, 15); cout << "　■　　　　　　　"; SetColor(9, 15); cout << "□" << endl;	// 21
		cout << "□"; SetColor(0, 15); cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　"; SetColor(14, 15); cout << "■■■　　　　　　"; SetColor(9, 15); cout << "□" << endl;	// 22
		cout << "□"; SetColor(0, 15); cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　"; SetColor(14, 15); cout << "　■　　　　　　　"; SetColor(9, 15); cout << "□" << endl;	// 23
		cout << "■"; SetColor(0, 15); cout << "　　　　　　■■　　　　　　　　　　　　　　　　　　"; SetColor(14, 15); cout << "■"; SetColor(0, 15); cout << "□"; SetColor(14, 15); cout << "■　　　　　　"; SetColor(9, 15); cout << "■" << endl;	// 24
		cout << "■"; SetColor(0, 15); cout << "　　　　　■　　■　　　　　　　　　　　　　　　■■■■　　　　　　　"; SetColor(9, 15); cout << "■" << endl;	// 25
		cout << "■"; SetColor(0, 15); cout << "　　　　■　■■　■　　　　　　　　　　　　　■■■■■■　　　　　　"; SetColor(9, 15); cout << "■" << endl;	// 26
		cout << "□"; SetColor(0, 15); cout << "　　■■■　■■　■　■■　　　　　　　　　　　■　　■　　　　　　　"; SetColor(9, 15); cout << "□" << endl;	// 27
		cout << "□"; SetColor(0, 15); cout << "　■　　■　　　　　■　　■　　　　　　　　　　■■■■　　　　　　　"; SetColor(9, 15); cout << "□" << endl;	// 28
		cout << "□"; SetColor(0, 15); cout << "■　■■　■　　　■　■■　■　　　　　　■■■■　　■■■■　　　　"; SetColor(9, 15); cout << "□" << endl;	// 29
		cout << "■"; SetColor(0, 15); cout << "■　■■　■　　　■　■■　■　　　　　■■■■■■■■■■■■　　　"; SetColor(9, 15); cout << "■" << endl;	// 30
		cout << "■"; SetColor(0, 15); cout << "　　　　　　　　　　　　　　　　　　　　　■　　■　　■　　■　　　　"; SetColor(9, 15); cout << "■" << endl;	// 31
		cout << "■"; SetColor(0, 15); cout << "　　　　　　　　　　　　　　　　　　　　　■■■■　　■■■■　　　　"; SetColor(9, 15); cout << "■" << endl;	// 32
		cout << "□　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　□" << endl;	// 33
		cout << "□　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　□" << endl;	// 34
		cout << "□　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　□" << endl;	// 35
		cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;	// 36
		cout << "■■□□□■■■□□□■■■□□□■■■□□□■■■□□□■■■□□□■■" << endl;	// 37
	}
	break;
	case 3:
	{
		cout << "■■□□□■■■□□□■■■□□□■■■□□□■■■□□□■■■□□□■■" << endl;	// 1
		cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　"; SetColor(9, 15); cout << "■" << endl;	// 2
		cout << "□　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　"; SetColor(9, 15); cout << "□" << endl;	// 3
		cout << "□"; SetColor(0, 15); cout << "　　■■■■■■■　　　　　　　　　　　　　　　　　　　　　　　　　　"; SetColor(9, 15); cout << "□" << endl;	// 4
		cout << "□"; SetColor(0, 15); cout << "　　■　　　　　■　　　　　　　　　　　　　　　　　　　　　　　　　　"; SetColor(9, 15); cout << "□" << endl;	// 5
		cout << "■"; SetColor(0, 15); cout << "　　■　유　목　■　　　　　　　　　　　　　　　　　　　　　　　　　　"; SetColor(9, 15); cout << "■" << endl;	// 6
		cout << "■"; SetColor(0, 15); cout << "　　■　　　　　■　　　　　　　　　　　　　　　　　　　　　　　　　　"; SetColor(9, 15); cout << "■" << endl;	// 7
		cout << "■"; SetColor(0, 15); cout << "　　■　마　을　■　　　　　　　　　　　　　　　　　　　　　　　　　　"; SetColor(9, 15); cout << "■" << endl;	// 8
		cout << "□"; SetColor(0, 15); cout << "　　■　　　　　■　　　　　　　　　　　　　　　　　　　　　　　　　　"; SetColor(9, 15); cout << "□" << endl;	// 9
		cout << "□"; SetColor(0, 15); cout << "　　■■■■■■■　　　　　　　　　　　　　　　　　　■　　　　　　　"; SetColor(9, 15); cout << "□" << endl;	// 10
		cout << "□"; SetColor(0, 15); cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　■　■　　　　　　"; SetColor(9, 15); cout << "□" << endl;	// 11
		cout << "■"; SetColor(0, 15); cout << "　　　　　　　　　　　　　　　　　　　　　　■　　■　　　■　　　　　"; SetColor(9, 15); cout << "■" << endl;	// 12
		cout << "■"; SetColor(0, 15); cout << "　　　　　　　　　　　　　　　　　　　　　■　■■　　　　　■　■　　"; SetColor(9, 15); cout << "■" << endl;	// 13
		cout << "■"; SetColor(0, 15); cout << "　　　　　　　　　　　　　　　　　　　　■　　　■　　　　　　■　■　"; SetColor(9, 15); cout << "■" << endl;	// 14
		cout << "□"; SetColor(0, 15); cout << "　　　　　　　　　　　　　　　　　　　■　　　　　■　　　　■　　　■"; SetColor(9, 15); cout << "□" << endl;	// 15
		cout << "□"; SetColor(0, 15); cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■　　　　　"; SetColor(9, 15); cout << "□" << endl;	// 16
		cout << "□　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　"; SetColor(9, 15); cout << "□" << endl;	// 17
		cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　"; SetColor(9, 15); cout << "■" << endl;	// 18
		cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　"; SetColor(9, 15); cout << "■" << endl;	// 19
		cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　"; SetColor(9, 15); cout << "■" << endl;	// 20
		cout << "□　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　"; SetColor(9, 15); cout << "□" << endl;	// 21
		cout << "□　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　"; SetColor(9, 15); cout << "□" << endl;	// 22
		cout << "□　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　"; SetColor(9, 15); cout << "□" << endl;	// 23
		cout << "■"; SetColor(0, 15); cout << "　　　　　　■■　　　　　　　　　　　　　　　　　　　　　　　　　　　"; SetColor(9, 15); cout << "■" << endl;	// 24
		cout << "■"; SetColor(0, 15); cout << "　　　　　■　　■　　　　　　　　　　　　　　　■■■■　　　　　　　"; SetColor(9, 15); cout << "■" << endl;	// 25
		cout << "■"; SetColor(0, 15); cout << "　　　　■　■■　■　　　　　　　　　　　　　■■■■■■　　　　　　"; SetColor(9, 15); cout << "■" << endl;	// 26
		cout << "□"; SetColor(0, 15); cout << "　　■■■　■■　■　■■　　　　　　　　　　　■　　■　　　　　　　"; SetColor(9, 15); cout << "□" << endl;	// 27
		cout << "□"; SetColor(0, 15); cout << "　■　　■　　　　　■　　■　　　　　　　　　　■■■■　　　　　　　"; SetColor(9, 15); cout << "□" << endl;	// 28
		cout << "□"; SetColor(0, 15); cout << "■　■■　■　　　■　■■　■　　"; SetColor(14, 15); cout << "　■　"; SetColor(0, 15); cout << "　■■■■　　■■■■　　　　"; SetColor(9, 15); cout << "□" << endl;	// 29
		cout << "■"; SetColor(0, 15); cout << "■　■■　■　□　■　■■　■　　"; SetColor(14, 15); cout << "■■■"; SetColor(0, 15); cout << "■■■■■■■■■■■■　　　"; SetColor(9, 15); cout << "■" << endl;	// 30
		cout << "■"; SetColor(0, 15); cout << "　　　　　　　□　　　　　　　　　"; SetColor(14, 15); cout << "　■　"; SetColor(0, 15); cout << "　■　　■　　■　　■　　　　"; SetColor(9, 15); cout << "■" << endl;	// 31
		cout << "■"; SetColor(0, 15); cout << "　　　　　　　□□□□□□□□□□"; SetColor(14, 15); cout << "■"; SetColor(0, 15); cout << "□"; SetColor(14, 15); cout << "■"; SetColor(0, 15); cout << "□■■■■　　■■■■　　　　"; SetColor(9, 15); cout << "■" << endl;	// 32
		cout << "□　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　"; SetColor(9, 15); cout << "□" << endl;	// 33
		cout << "□　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　"; SetColor(9, 15); cout << "□" << endl;	// 34
		cout << "□　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　"; SetColor(9, 15); cout << "□" << endl;	// 35
		cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　"; SetColor(9, 15); cout << "■" << endl;	// 36
		cout << "■■□□□■■■□□□■■■□□□■■■□□□■■■□□□■■■□□□■■" << endl;	// 37
	}
	break;
	case 4:
	{
		cout << "■■□□□■■■□□□■■■□□□■■■□□□■■■□□□■■■□□□■■" << endl;	// 1
		cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　"; SetColor(9, 15); cout << "■" << endl;	// 2
		cout << "□　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　"; SetColor(9, 15); cout << "□" << endl;	// 3
		cout << "□"; SetColor(0, 15); cout << "　　■■■■■■■　　　　　　　　　　　　　　　　　　　　　　　　　　"; SetColor(9, 15); cout << "□" << endl;	// 4
		cout << "□"; SetColor(0, 15); cout << "　　■　　　　　■　　　　　　　　　　　　　　　　　　　　　　　　　　"; SetColor(9, 15); cout << "□" << endl;	// 5
		cout << "■"; SetColor(0, 15); cout << "　　■　어둠의　■　　　　　　　　　　　　　　　　　　　　　　　　　　"; SetColor(9, 15); cout << "■" << endl;	// 6
		cout << "■"; SetColor(0, 15); cout << "　　■　　　　　■　　　　　　　　　　　　　　　　　　　　　　　　　　"; SetColor(9, 15); cout << "■" << endl;	// 7
		cout << "■"; SetColor(0, 15); cout << "　　■　무　덤　■　　　　　　　　　　　　　　　　　　　　　　　　　　"; SetColor(9, 15); cout << "■" << endl;	// 8
		cout << "□"; SetColor(0, 15); cout << "　　■　　　　　■　　　　　　　　　　　　　　　　　　　　　　　　　　"; SetColor(9, 15); cout << "□" << endl;	// 9
		cout << "□"; SetColor(0, 15); cout << "　　■■■■■■■　　　　　　　　　　　　　　　　　　■　　　　　　　"; SetColor(9, 15); cout << "□" << endl;	// 10
		cout << "□"; SetColor(0, 15); cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　■　■　　　　　　"; SetColor(9, 15); cout << "□" << endl;	// 11
		cout << "■"; SetColor(0, 15); cout << "　　　　　　　　　　　　　　　　　　　　　　■　　■　　　■　　　　　"; SetColor(9, 15); cout << "■" << endl;	// 12
		cout << "■"; SetColor(0, 15); cout << "　　　　　　　　　　　　　　　　　　　　　■　■■　　　　　■　■　　"; SetColor(9, 15); cout << "■" << endl;	// 13
		cout << "■"; SetColor(0, 15); cout << "　　　　　　　　　　　　　　　　　　　　■　　　■　　　　　　■　■　"; SetColor(9, 15); cout << "■" << endl;	// 14
		cout << "□"; SetColor(0, 15); cout << "　　　　　　　　　　　　　　　　　　　■　　　　　■　　　　■　　　■"; SetColor(9, 15); cout << "□" << endl;	// 15
		cout << "□"; SetColor(0, 15); cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■　　　　　"; SetColor(9, 15); cout << "□" << endl;	// 16
		cout << "□　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　"; SetColor(9, 15); cout << "□" << endl;	// 17
		cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　"; SetColor(9, 15); cout << "■" << endl;	// 18
		cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　"; SetColor(9, 15); cout << "■" << endl;	// 19
		cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　"; SetColor(9, 15); cout << "■" << endl;	// 20
		cout << "□　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　"; SetColor(9, 15); cout << "□" << endl;	// 21
		cout << "□　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　"; SetColor(9, 15); cout << "□" << endl;	// 22
		cout << "□　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　"; SetColor(9, 15); cout << "□" << endl;	// 23
		cout << "■"; SetColor(0, 15); cout << "　　　　　　■■　　　　　　　　　　　　　　　　　　　　　　　　　　　"; SetColor(9, 15); cout << "■" << endl;	// 24
		cout << "■"; SetColor(0, 15); cout << "　　　　　■　　■　　　　　　　　　　　　　　　■■■■　　　　　　　"; SetColor(9, 15); cout << "■" << endl;	// 25
		cout << "■"; SetColor(0, 15); cout << "　　　　■　■■　■　　　　　　　　　　　　　■■■■■■　　　　　　"; SetColor(9, 15); cout << "■" << endl;	// 26
		cout << "□"; SetColor(0, 15); cout << "　　■■■　■■　■　■■　　　　　　　　　　　■　　■　　　　　　　"; SetColor(9, 15); cout << "□" << endl;	// 27
		cout << "□"; SetColor(0, 15); cout << "　■　　■　"; SetColor(14, 15); cout << "　■　"; SetColor(0, 15); cout << "　■　　■　　　　　　　　　　■■■■　　　　　　　"; SetColor(9, 15); cout << "□" << endl;	// 28
		cout << "□"; SetColor(0, 15); cout << "■　■■　■"; SetColor(14, 15); cout << "■■■"; SetColor(0, 15); cout << "■　■■　■　　　　　　■■■■　　■■■■　　　　"; SetColor(9, 15); cout << "□" << endl;	// 29
		cout << "■"; SetColor(0, 15); cout << "■　■■　■"; SetColor(14, 15); cout << "　■　"; SetColor(0, 15); cout << "■　■■　■　　　　　■■■■■■■■■■■■　　　"; SetColor(9, 15); cout << "■" << endl;	// 30
		cout << "■　　　　　　"; SetColor(14, 15); cout << "■"; SetColor(0, 15); cout << "□"; SetColor(14, 15); cout << "■"; SetColor(0, 15); cout << "　　　　　　　　　　　　■　　■　　■　　■　　　　"; SetColor(9, 15); cout << "■" << endl;	// 31
		cout << "■"; SetColor(0, 15); cout << "　　　　　　　□□□□□□□□□□□□□□■■■■　　■■■■　　　　"; SetColor(9, 15); cout << "■" << endl;	// 32
		cout << "□　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　"; SetColor(9, 15); cout << "□" << endl;	// 33
		cout << "□　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　"; SetColor(9, 15); cout << "□" << endl;	// 34
		cout << "□　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　"; SetColor(9, 15); cout << "□" << endl;	// 35
		cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　"; SetColor(9, 15); cout << "■" << endl;	// 36
		cout << "■■□□□■■■□□□■■■□□□■■■□□□■■■□□□■■■□□□■■" << endl;	// 37
	}
	break;
	}
}

void mainGame::WorldMapChoice()
{
	_key = '0';
	_key = _getch();

	if (_key == (char)DOWN)
	{
		switch (_worldcheck)
		{
		case 1:
		{
			_worldcheck = 2;
			WorldMapScreen();
			WorldMapChoice();
		}
		break;
		default:
		{
			WorldMapChoice();
		}
		break;
		}
	}
	else if (_key == (char)UP)
	{
		switch (_worldcheck)
		{
		case 2:
		{
			_worldcheck = 1;
			WorldMapScreen();
			WorldMapChoice();
		}
		break;
		default:
		{
			WorldMapChoice();
		}
		break;
		}
	}
	else if (_key == (char)LEFT)
	{
		switch (_worldcheck)
		{
		case 3:
		{
			_worldcheck = 4;
			WorldMapScreen();
			WorldMapChoice();
		}
		break;
		default:
		{
			WorldMapChoice();
		}
		break;
		}
	}
	else if (_key == (char)RIGHT)
	{
		switch (_worldcheck)
		{
		case 4:
		{
			_worldcheck = 3;
			WorldMapScreen();
			WorldMapChoice();
		}
		break;
		default:
		{
			WorldMapChoice();
		}
		break;
		}
	}
	else if (_key == (char)ENTER || _key == (char)SPACE)
	{
		switch (_worldcheck)
		{
		case 1:
		{
			_worldcheck = 0;

			_fieldcheck = 6;
			_effect = Emove;
			Sleep(1500);
			b_worldmapMusic = false;
			Move();
			b_fieldMusic = true;
			FieldScreen();
			FieldChoice();
		}
		break;
		case 2:
		{
			_worldcheck = 0;

			_village1check = 1;
			_effect = Emove;
			Sleep(1500);
			b_worldmapMusic = false;
			Move();
			b_villageMusic = true;
			VillageEvent();
			Village1Screen();
			_effect = Echicken;
			Village1Choice();
		}
		break;
		case 3:
		{
			_worldcheck = 0;

			_village2check = 6;
			_effect = Emove;
			Sleep(1500);
			b_worldmapMusic = false;
			Move();
			b_villageMusic = true;
			Village2Screen();
			Village2Choice();
		}
		break;
		case 4:
		{
			TombEvent(); // not completed
		}
		break;
		default:
		{
			WorldMapChoice();
		}
		break;
		}
	}
	else
	{
		WorldMapChoice();
	}
}
void mainGame::TombEvent()
{

	gotoxy(0, 26);
	SetColor(13, 15);
	_effect = Econversation;

	cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;
	cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
	cout << "■"; SetColor(0, 15); cout << "　　[아타호]　　　 　　　　　　　　　　  　　　　　　 　　　　　　　　"; SetColor(13, 15); cout << "■" << endl;
	cout << "■"; SetColor(0, 15); cout << "　　길을 잘못 들었군. 이곳에는 갈일이 없다.　　 　　 　　　　　　　　 "; SetColor(13, 15); cout << "■" << endl;
	cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
	cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
	cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
	cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
	cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
	cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
	cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;

	while (true)
	{
		_key = '0';
		_key = _getch();

		if (_key == (char)ENTER || _key == (char)SPACE)
		{
			break;
		}
	}
	WorldMapScreen();
	WorldMapChoice();
}

void mainGame::DogEvent()
{
	gotoxy(0, 26);
	SetColor(13, 15);

	_effect = Econversation;

	cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;
	cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
	cout << "■"; SetColor(0, 15); cout << "　　[강아지]　　　 　　　　　　　　　　  　　　　　　 　　　　　　　　"; SetColor(13, 15); cout << "■" << endl;
	cout << "■"; SetColor(0, 15); cout << "　　거참 귀찮게 구네..ㅡㅡ 이거나 줄테니 제발 좀 가라　　　　　　　　 "; SetColor(13, 15); cout << "■" << endl;
	cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
	cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
	cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
	cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
	cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
	cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
	cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;

	while (true)
	{
		_key = '0';
		_key = _getch();

		if (_key == (char)ENTER || _key == (char)SPACE)
		{
			break;
		}
	}
	FarmScreen();
	Sleep(500);

	gotoxy(0, 26);
	SetColor(13, 15);

	cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;
	cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
	cout << "■"; SetColor(0, 15); cout << "　　강아지한테 Hp포션을 받았다. 　　　　　　　　　　　　　　　　　　　"; SetColor(13, 15); cout << "■" << endl;
	cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
	cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
	cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
	cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
	cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
	cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
	cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
	cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;

	while (true)
	{
		_key = '0';
		_key = _getch();

		if (_key == (char)ENTER || _key == (char)SPACE)
		{
			break;
		}
	}

	po->SetHowMany(po->GetHowMany() + 1);

	FarmScreen();
}

void mainGame::Village1Screen()
{
	gotoxy(0, 0);
	SetColor(9, 15);

	switch (_village1check)
	{
	case 0:
	{
		cout << "■■□□□■■■□□□■■■□□□■■■□□□■■■□□□■■■□□□■■" << endl;	// 1
		cout << "■"; SetColor(0, 15); cout << "■■　　　　　■■■■■■■■■■■■■■■■■■■■■■■■■■■■"; SetColor(9, 15); cout << "■" << endl;	// 2
		cout << "□"; SetColor(0, 15); cout << "■■　　　　　■■■■■■■■■■■■■■■■■■■■■■■■■■■■"; SetColor(9, 15); cout << "□" << endl;	// 3
		cout << "□"; SetColor(0, 15); cout << "■■　　　　　■■■■■■■■■■■■■■■■■■■■■■■■■■■■"; SetColor(9, 15); cout << "□" << endl;	// 4
		cout << "□"; SetColor(0, 15); cout << "■■　　　　　■■■■■■■■■■■■■■■■■■■■■■■■■■■■"; SetColor(9, 15); cout << "□" << endl;	// 5
		cout << "■"; SetColor(0, 15); cout << "■■　　　　　□□□□□□□□□□□□□□□□□□□□□□□□□□□　"; SetColor(9, 15); cout << "■" << endl;	// 6
		cout << "■"; SetColor(0, 15); cout << "■■　　　　　□　　　　　　　　　　　　　　　　　　　　　　　　　□　"; SetColor(9, 15); cout << "■" << endl;	// 7
		cout << "■"; SetColor(0, 15); cout << "■■　　　　　□　　　　　　　　　　　　　　　　　　　　　　　　　□　"; SetColor(9, 15); cout << "■" << endl;	// 8
		cout << "□"; SetColor(0, 15); cout << "■■　　　　　□　　　　　　　　　　　　　　"; SetColor(0, 15); cout << "　　■■■■■■■　　□　"; SetColor(9, 15); cout << "□" << endl;	// 9
		cout << "□"; SetColor(0, 15); cout << "■■　　　　　□　　　　　　　　　　　　　　"; SetColor(0, 15); cout << "　■　　　　　　　■　□　"; SetColor(9, 15); cout << "□" << endl;	// 10
		cout << "□"; SetColor(0, 15); cout << "■■　　　　　□　　　　"; SetColor(12, 15); cout << "　　■　　　　　　　"; SetColor(0, 15); cout << "■■■■■■■■■■■□　"; SetColor(9, 15); cout << "□" << endl;	// 11
		cout << "■"; SetColor(0, 15); cout << "■■　　　　　□　　　　"; SetColor(12, 15); cout << "■■■　　　　　　　"; SetColor(0, 15); cout << "　■　　　　　　　■　□　"; SetColor(9, 15); cout << "■" << endl;	// 12
		cout << "■"; SetColor(0, 15); cout << "■■　　　　　□　　　　"; SetColor(12, 15); cout << "　■　　　　■　　　"; SetColor(0, 15); cout << "　■　　　　　　　■　□　"; SetColor(9, 15); cout << "■" << endl;	// 13
		cout << "■"; SetColor(0, 15); cout << "■■　　　　　□　　　　"; SetColor(12, 15); cout << "　　　　　　■■■　"; SetColor(0, 15); cout << "　■■■■■■■■■　□　"; SetColor(9, 15); cout << "■" << endl;	// 14
		cout << "□"; SetColor(0, 15); cout << "■■　　　　　□　　　　"; SetColor(12, 15); cout << "　　　　　　　■　　"; SetColor(0, 15); cout << "　　　　　　　　　　　□　"; SetColor(9, 15); cout << "□" << endl;	// 15
		cout << "□"; SetColor(0, 15); cout << "■■　　　　　□　　　　　　　　　　　　　　　　　　　　　　　　　□　"; SetColor(9, 15); cout << "□" << endl;	// 16
		cout << "□"; SetColor(0, 15); cout << "■■　　　　　□　　　　　　"; SetColor(12, 15); cout << "■　　　　　　　　　　　　　　　　　　"; SetColor(0, 15); cout << "□　"; SetColor(9, 15); cout << "□" << endl;	// 17
		cout << "■"; SetColor(0, 15); cout << "■■　　　　　□　　　　　　"; SetColor(12, 15); cout << "■■■　　　　　　"; SetColor(12, 15); cout << "　　　■　　　　　　"; SetColor(0, 15); cout << "□　"; SetColor(9, 15); cout << "■" << endl;	// 18
		cout << "■"; SetColor(0, 15); cout << "■■　　　　　□　　　　　　"; SetColor(12, 15); cout << "　■　"; SetColor(14, 15); cout << "　■　■　　"; SetColor(12, 15); cout << "　■■■　　　　　　"; SetColor(0, 15); cout << "□　"; SetColor(9, 15); cout << "■" << endl;	// 19
		cout << "■"; SetColor(0, 15); cout << "■■　　　　　□　　　　　　　　　"; SetColor(14, 15); cout << "■　　　　　"; SetColor(12, 15); cout << "　　■　　　　　　　"; SetColor(0, 15); cout << "□　"; SetColor(9, 15); cout << "■" << endl;	// 20
		cout << "□"; SetColor(0, 15); cout << "■■　　　　　□　　　　　　　　　"; SetColor(14, 15); cout << "　　■　■　　　　　　　　　　　"; SetColor(0, 15); cout << "□　"; SetColor(9, 15); cout << "□" << endl;	// 21
		cout << "□"; SetColor(0, 15); cout << "■■　　　　　□□□　　　□□□□□□□□□□□□□□□□□□□□□　"; SetColor(9, 15); cout << "□" << endl;	// 22
		cout << "□"; SetColor(0, 15); cout << "■■　　　　　　　　　　　　　　　　　"; SetColor(10, 15); cout << "　■　　　　　　　　　　　　　　"; SetColor(9, 15); cout << "□" << endl;	// 23
		cout << "■"; SetColor(0, 15); cout << "■■　　　　　　　　　　　　　　　　　"; SetColor(10, 15); cout << "■■■　　　　　　　　　　　　　"; SetColor(9, 15); cout << "■" << endl;	// 24
		cout << "■"; SetColor(0, 15); cout << "■■　　　　　　　　　　　　　　　　　"; SetColor(10, 15); cout << "　■　　　　　　　　　　　　　　"; SetColor(9, 15); cout << "■" << endl;	// 25
		cout << "■"; SetColor(0, 15); cout << "■■　　　　　　　　　　　　　　　　　"; SetColor(10, 15); cout << "■　■　　　"; SetColor(0, 15); cout << "■■　　　　　　　　"; SetColor(9, 15); cout << "■" << endl;	// 26
		cout << "□"; SetColor(0, 15); cout << "■■　　　　　　　　　　　　　　　　　　　　　　　■■　　　　　　　　"; SetColor(9, 15); cout << "□" << endl;	// 27
		cout << "□"; SetColor(0, 15); cout << "■■　　　　　　　　　　　　　　　　　　　　　　　■■　　　　　　　　"; SetColor(9, 15); cout << "□" << endl;	// 28
		cout << "□"; SetColor(0, 15); cout << "■■　　　　■■■■■■■　　　　　　　　　　　　■■■■■■■■　　"; SetColor(9, 15); cout << "□" << endl;	// 29
		cout << "■"; SetColor(0, 15); cout << "■■　　　■　　　　　　　■　　　　　　　　　　■　　　　　　　　■　"; SetColor(9, 15); cout << "■" << endl;	// 30
		cout << "■"; SetColor(0, 15); cout << "■■　　■　　　　　　　　　■　　　　　　　　■　　　　　　　　　　■"; SetColor(9, 15); cout << "■" << endl;	// 31
		cout << "■"; SetColor(0, 15); cout << "■■　■■■■■■■■■■■■■　　　　　　■■■■■■■■■■■■■"; SetColor(9, 15); cout << "■" << endl;	// 32
		cout << "□"; SetColor(0, 15); cout << "■■　　■　　　　　　　　　■　　　　　　　　■　　　　　　　　　　■"; SetColor(9, 15); cout << "□" << endl;	// 33
		cout << "□"; SetColor(0, 15); cout << "■■　　■　■■■　　　　　■　　　　　　　　■　■■■　　　　　　■"; SetColor(9, 15); cout << "□" << endl;	// 34
		cout << "□"; SetColor(0, 15); cout << "■■　　■　■　■　　■■　■　　　　　　　　■　■　■　　　　　　■"; SetColor(9, 15); cout << "□" << endl;	// 35
		cout << "■"; SetColor(0, 15); cout << "■■　　■　■　■　　　　　■　　　　　　　　■　■　■　　　　　　■"; SetColor(9, 15); cout << "■" << endl;	// 36
		cout << "■■□□□■■■□□□■■■□□□■■■□□□■■■□□□■■■□□□■■" << endl;	// 37
	}
	break;
	case 1:
	{
		cout << "■■□□□■■■□□□■■■□□□■■■□□□■■■□□□■■■□□□■■" << endl;	// 1
		cout << "■"; SetColor(0, 15); cout << "■■　　　　　"; SetColor(0, 15); cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■"; SetColor(9, 15); cout << "■" << endl;	// 2
		cout << "□"; SetColor(0, 15); cout << "■■　　　　　"; SetColor(0, 15); cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■"; SetColor(9, 15); cout << "□" << endl;	// 3
		cout << "□"; SetColor(0, 15); cout << "■■　"; SetColor(14, 15); cout << "　■　　"; SetColor(0, 15); cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■"; SetColor(9, 15); cout << "□" << endl;	// 4
		cout << "□"; SetColor(0, 15); cout << "■■　"; SetColor(14, 15); cout << "■■■　"; SetColor(0, 15); cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■"; SetColor(9, 15); cout << "□" << endl;	// 5
		cout << "■"; SetColor(0, 15); cout << "■■　"; SetColor(14, 15); cout << "　■　　"; SetColor(0, 15); cout << "□□□□□□□□□□□□□□□□□□□□□□□□□□□　"; SetColor(9, 15); cout << "■" << endl;	// 6
		cout << "■"; SetColor(0, 15); cout << "■■　"; SetColor(14, 15); cout << "■　■　"; SetColor(0, 15); cout << "□　　　　　　　　　　　　　　　　　　　　　　　　　□　"; SetColor(9, 15); cout << "■" << endl;	// 7
		cout << "■"; SetColor(0, 15); cout << "■■　　　　　□　　　　　　　　　　　　　　　　　　　　　　　　　□　"; SetColor(9, 15); cout << "■" << endl;	// 8
		cout << "□"; SetColor(0, 15); cout << "■■　　　　　□　　　　　　　　　　　　　"; SetColor(0, 15); cout << "　　　■■■■■■■　　□　"; SetColor(9, 15); cout << "□" << endl;	// 9
		cout << "□"; SetColor(0, 15); cout << "■■　　　　　□　　　　　　　　　　　　　"; SetColor(0, 15); cout << "　　■　　　　　　　■　□　"; SetColor(9, 15); cout << "□" << endl;	// 10
		cout << "□"; SetColor(0, 15); cout << "■■　　　　　□　　　　"; SetColor(12, 15); cout << "　　■　　　　　　"; SetColor(0, 15); cout << "　■■■■■■■■■■■□　"; SetColor(9, 15); cout << "□" << endl;	// 11
		cout << "■"; SetColor(0, 15); cout << "■■　　　　　□　　　　"; SetColor(12, 15); cout << "■■■　　　　　　"; SetColor(0, 15); cout << "　　■　　　　　　　■　□　"; SetColor(9, 15); cout << "■" << endl;	// 12
		cout << "■"; SetColor(0, 15); cout << "■■　　　　　□　　　　"; SetColor(12, 15); cout << "　■　　　　■　　"; SetColor(0, 15); cout << "　　■　　　　　　　■　□　"; SetColor(9, 15); cout << "■" << endl;	// 13
		cout << "■"; SetColor(0, 15); cout << "■■　　　　　□　　　　"; SetColor(12, 15); cout << "　　　　　　■■■"; SetColor(0, 15); cout << "　　■■■■■■■■■　□　"; SetColor(9, 15); cout << "■" << endl;	// 14
		cout << "□"; SetColor(0, 15); cout << "■■　　　　　□　　　　"; SetColor(12, 15); cout << "　　　　　　　■　"; SetColor(0, 15); cout << "　　　　　　　　　　　　□　"; SetColor(9, 15); cout << "□" << endl;	// 15
		cout << "□"; SetColor(0, 15); cout << "■■　　　　　□　　　　　　　　　　　　　　　　　　　　　　　　　□　"; SetColor(9, 15); cout << "□" << endl;	// 16
		cout << "□"; SetColor(0, 15); cout << "■■　　　　　□　　　　　"; SetColor(12, 15); cout << "　■　　　　　　　　　　　　　　　　　　"; SetColor(0, 15); cout << "□　"; SetColor(9, 15); cout << "□" << endl;	// 17
		cout << "■"; SetColor(0, 15); cout << "■■　　　　　□　　　　　"; SetColor(12, 15); cout << "　■■■　　　　　　　"; SetColor(12, 15); cout << "　　■　　　　　　"; SetColor(0, 15); cout << "□　"; SetColor(9, 15); cout << "■" << endl;	// 18
		cout << "■"; SetColor(0, 15); cout << "■■　　　　　□　　　　　"; SetColor(12, 15); cout << "　　■　"; SetColor(14, 15); cout << "　■　■　　　"; SetColor(12, 15); cout << "■■■　　　　　　"; SetColor(0, 15); cout << "□　"; SetColor(9, 15); cout << "■" << endl;	// 19
		cout << "■"; SetColor(0, 15); cout << "■■　　　　　□　　　　　　　　　"; SetColor(14, 15); cout << "■　　　　　　"; SetColor(12, 15); cout << "　■　　　　　　　"; SetColor(0, 15); cout << "□　"; SetColor(9, 15); cout << "■" << endl;	// 20
		cout << "□"; SetColor(0, 15); cout << "■■　　　　　□　　　　　　　　　"; SetColor(14, 15); cout << "　　■　■　　　　　　　　　　　"; SetColor(0, 15); cout << "□　"; SetColor(9, 15); cout << "□" << endl;	// 21
		cout << "□"; SetColor(0, 15); cout << "■■　　　　　□□□　　　□□□□□□□□□□□□□□□□□□□□□　"; SetColor(9, 15); cout << "□" << endl;	// 22
		cout << "□"; SetColor(0, 15); cout << "■■　　　　　　　　　　　　　　　　　"; SetColor(10, 15); cout << "　■　　　　　　　　　　　　　　"; SetColor(9, 15); cout << "□" << endl;	// 23
		cout << "■"; SetColor(0, 15); cout << "■■　　　　　　　　　　　　　　　　　"; SetColor(10, 15); cout << "■■■　　　　　　　　　　　　　"; SetColor(9, 15); cout << "■" << endl;	// 24
		cout << "■"; SetColor(0, 15); cout << "■■　　　　　　　　　　　　　　　　　"; SetColor(10, 15); cout << "　■　　　　　　　　　　　　　　"; SetColor(9, 15); cout << "■" << endl;	// 25
		cout << "■"; SetColor(0, 15); cout << "■■　　　　　　　　　　　　　　　　　"; SetColor(10, 15); cout << "■　■　　　"; SetColor(0, 15); cout << "■■　　　　　　　　"; SetColor(9, 15); cout << "■" << endl;	// 26
		cout << "□"; SetColor(0, 15); cout << "■■　　　　　　　　　　　　　　　　　　　　　　　■■　　　　　　　　"; SetColor(9, 15); cout << "□" << endl;	// 27
		cout << "□"; SetColor(0, 15); cout << "■■　　　　　　　　　　　　　　　　　　　　　　　■■　　　　　　　　"; SetColor(9, 15); cout << "□" << endl;	// 28
		cout << "□"; SetColor(0, 15); cout << "■■　　　　■■■■■■■　　　　　　　　　　　　■■■■■■■■　　"; SetColor(9, 15); cout << "□" << endl;	// 29
		cout << "■"; SetColor(0, 15); cout << "■■　　　■　　　　　　　■　　　　　　　　　　■　　　　　　　　■　"; SetColor(9, 15); cout << "■" << endl;	// 30
		cout << "■"; SetColor(0, 15); cout << "■■　　■　　　　　　　　　■　　　　　　　　■　　　　　　　　　　■"; SetColor(9, 15); cout << "■" << endl;	// 31
		cout << "■"; SetColor(0, 15); cout << "■■　■■■■■■■■■■■■■　　　　　　■■■■■■■■■■■■■"; SetColor(9, 15); cout << "■" << endl;	// 32
		cout << "□"; SetColor(0, 15); cout << "■■　　■　　　　　　　　　■　　　　　　　　■　　　　　　　　　　■"; SetColor(9, 15); cout << "□" << endl;	// 33
		cout << "□"; SetColor(0, 15); cout << "■■　　■　■■■　　　　　■　　　　　　　　■　■■■　　　　　　■"; SetColor(9, 15); cout << "□" << endl;	// 34
		cout << "□"; SetColor(0, 15); cout << "■■　　■　■　■　　■■　■　　　　　　　　■　■　■　　　　　　■"; SetColor(9, 15); cout << "□" << endl;	// 35
		cout << "■"; SetColor(0, 15); cout << "■■　　■　■　■　　　　　■　　　　　　　　■　■　■　　　　　　■"; SetColor(9, 15); cout << "■" << endl;	// 36
		cout << "■■□□□■■■□□□■■■□□□■■■□□□■■■□□□■■■□□□■■" << endl;	// 37
	}
	break;
	case 2:
	{
		cout << "■■□□□■■■□□□■■■□□□■■■□□□■■■□□□■■■□□□■■" << endl;	// 1
		cout << "■"; SetColor(0, 15); cout << "■■　　　　　■■■■■■■■■■■■■■■■■■■■■■■■■■■■"; SetColor(9, 15); cout << "■" << endl;	// 2
		cout << "□"; SetColor(0, 15); cout << "■■　　　　　■■■■■■■■■■■■■■■■■■■■■■■■■■■■"; SetColor(9, 15); cout << "□" << endl;	// 3
		cout << "□"; SetColor(0, 15); cout << "■■　　　　　■■■■■■■■■■■■■■■■■■■■■■■■■■■■"; SetColor(9, 15); cout << "□" << endl;	// 4
		cout << "□"; SetColor(0, 15); cout << "■■　　　　　■■■■■■■■■■■■■■■■■■■■■■■■■■■■"; SetColor(9, 15); cout << "□" << endl;	// 5
		cout << "■"; SetColor(0, 15); cout << "■■　　　　　□□□□□□□□□□□□□□□□□□□□□□□□□□□　"; SetColor(9, 15); cout << "■" << endl;	// 6
		cout << "■"; SetColor(0, 15); cout << "■■　　　　　□　　　　　　　　　　　　　　　　　　　　　　　　　□　"; SetColor(9, 15); cout << "■" << endl;	// 7
		cout << "■"; SetColor(0, 15); cout << "■■　　　　　□　　　　　　　　　　　　　　　　　　　　　　　　　□　"; SetColor(9, 15); cout << "■" << endl;	// 8
		cout << "□"; SetColor(0, 15); cout << "■■　　　　　□　　　　　　　　　　　　　　"; SetColor(0, 15); cout << "　　■■■■■■■　　□　"; SetColor(9, 15); cout << "□" << endl;	// 9
		cout << "□"; SetColor(0, 15); cout << "■■　　　　　□　　　　　　　　　　　　　　"; SetColor(0, 15); cout << "　■　　　　　　　■　□　"; SetColor(9, 15); cout << "□" << endl;	// 10
		cout << "□"; SetColor(0, 15); cout << "■■　　　　　□　　　　"; SetColor(12, 15); cout << "　　■　　　　　　　"; SetColor(0, 15); cout << "■■■■■■■■■■■□　"; SetColor(9, 15); cout << "□" << endl;	// 11
		cout << "■"; SetColor(0, 15); cout << "■■　　　　　□　　　　"; SetColor(12, 15); cout << "■■■　　　　　　　"; SetColor(0, 15); cout << "　■　　　　　　　■　□　"; SetColor(9, 15); cout << "■" << endl;	// 12
		cout << "■"; SetColor(0, 15); cout << "■■　　　　　□　　　　"; SetColor(12, 15); cout << "　■　　　　■　　　"; SetColor(0, 15); cout << "　■　　　　　　　■　□　"; SetColor(9, 15); cout << "■" << endl;	// 13
		cout << "■"; SetColor(0, 15); cout << "■■　　　　　□　　　　"; SetColor(12, 15); cout << "　　　　　　■■■　"; SetColor(0, 15); cout << "　■■■■■■■■■　□　"; SetColor(9, 15); cout << "■" << endl;	// 14
		cout << "□"; SetColor(0, 15); cout << "■■　　　　　□　　　　"; SetColor(12, 15); cout << "　　　　　　　■　　"; SetColor(0, 15); cout << "　　　　　　　　　　　□　"; SetColor(9, 15); cout << "□" << endl;	// 15
		cout << "□"; SetColor(0, 15); cout << "■■　　　　　□　　　　　　　　　　　　　　　　　　　　　　　　　□　"; SetColor(9, 15); cout << "□" << endl;	// 16
		cout << "□"; SetColor(0, 15); cout << "■■　　　　　□　　　　　　"; SetColor(12, 15); cout << "■　　　　　　　　　　　　　　　　　　"; SetColor(0, 15); cout << "□　"; SetColor(9, 15); cout << "□" << endl;	// 17
		cout << "■"; SetColor(0, 15); cout << "■■　　　　　□　　　　　　"; SetColor(12, 15); cout << "■■■　　　　　　　"; SetColor(12, 15); cout << "　　■　　　　　　"; SetColor(0, 15); cout << "□　"; SetColor(9, 15); cout << "■" << endl;	// 18
		cout << "■"; SetColor(0, 15); cout << "■■　　　　　□　　　　　　"; SetColor(12, 15); cout << "　■　"; SetColor(14, 15); cout << "　■　■　　　"; SetColor(12, 15); cout << "■■■　　　　　　"; SetColor(0, 15); cout << "□　"; SetColor(9, 15); cout << "■" << endl;	// 19
		cout << "■"; SetColor(0, 15); cout << "■■　　　　　□　　　　　　　　　"; SetColor(14, 15); cout << "■　　　　　　"; SetColor(12, 15); cout << "　■　　　　　　　"; SetColor(0, 15); cout << "□　"; SetColor(9, 15); cout << "■" << endl;	// 20
		cout << "□"; SetColor(0, 15); cout << "■■　　　　　□　　　　　　　　　"; SetColor(14, 15); cout << "　　■　■　　　　　　　　　　　"; SetColor(0, 15); cout << "□　"; SetColor(9, 15); cout << "□" << endl;	// 21
		cout << "□"; SetColor(0, 15); cout << "■■　　　　　□□□　　　□□□□□□□□□□□□□□□□□□□□□　"; SetColor(9, 15); cout << "□" << endl;	// 22
		cout << "□"; SetColor(0, 15); cout << "■■　　　　　　　　　　　　　"; SetColor(14, 15); cout << "　■　　"; SetColor(10, 15); cout << "　■　　　　　　　　　　　　　　"; SetColor(9, 15); cout << "□" << endl;	// 23
		cout << "■"; SetColor(0, 15); cout << "■■　　　　　　　　　　　　　"; SetColor(14, 15); cout << "■■■　"; SetColor(10, 15); cout << "■■■　　　　　　　　　　　　　"; SetColor(9, 15); cout << "■" << endl;	// 24
		cout << "■"; SetColor(0, 15); cout << "■■　　　　　　　　　　　　　"; SetColor(14, 15); cout << "　■　　"; SetColor(10, 15); cout << "　■　　　　　　　　　　　　　　"; SetColor(9, 15); cout << "■" << endl;	// 25
		cout << "■"; SetColor(0, 15); cout << "■■　　　　　　　　　　　　　"; SetColor(14, 15); cout << "■　■　"; SetColor(10, 15); cout << "■　■　　　"; SetColor(0, 15); cout << "■■　　　　　　　　"; SetColor(9, 15); cout << "■" << endl;	// 26
		cout << "□"; SetColor(0, 15); cout << "■■　　　　　　　　　　　　　　　　　　　　　　　■■　　　　　　　　"; SetColor(9, 15); cout << "□" << endl;	// 27
		cout << "□"; SetColor(0, 15); cout << "■■　　　　　　　　　　　　　　　　　　　　　　　■■　　　　　　　　"; SetColor(9, 15); cout << "□" << endl;	// 28
		cout << "□"; SetColor(0, 15); cout << "■■　　　　■■■■■■■　　　　　　　　　　　　■■■■■■■■　　"; SetColor(9, 15); cout << "□" << endl;	// 29
		cout << "■"; SetColor(0, 15); cout << "■■　　　■　　　　　　　■　　　　　　　　　　■　　　　　　　　■　"; SetColor(9, 15); cout << "■" << endl;	// 30
		cout << "■"; SetColor(0, 15); cout << "■■　　■　　　　　　　　　■　　　　　　　　■　　　　　　　　　　■"; SetColor(9, 15); cout << "■" << endl;	// 31
		cout << "■"; SetColor(0, 15); cout << "■■　■■■■■■■■■■■■■　　　　　　■■■■■■■■■■■■■"; SetColor(9, 15); cout << "■" << endl;	// 32
		cout << "□"; SetColor(0, 15); cout << "■■　　■　　　　　　　　　■　　　　　　　　■　　　　　　　　　　■"; SetColor(9, 15); cout << "□" << endl;	// 33
		cout << "□"; SetColor(0, 15); cout << "■■　　■　■■■　　　　　■　　　　　　　　■　■■■　　　　　　■"; SetColor(9, 15); cout << "□" << endl;	// 34
		cout << "□"; SetColor(0, 15); cout << "■■　　■　■　■　　■■　■　　　　　　　　■　■　■　　　　　　■"; SetColor(9, 15); cout << "□" << endl;	// 35
		cout << "■"; SetColor(0, 15); cout << "■■　　■　■　■　　　　　■　　　　　　　　■　■　■　　　　　　■"; SetColor(9, 15); cout << "■" << endl;	// 36
		cout << "■■□□□■■■□□□■■■□□□■■■□□□■■■□□□■■■□□□■■" << endl;	// 37
	}
	break;
	case 3:
	{
		cout << "■■□□□■■■□□□■■■□□□■■■□□□■■■□□□■■■□□□■■" << endl;	// 1
		cout << "■"; SetColor(0, 15); cout << "■■　　　　　■■■■■■■■■■■■■■■■■■■■■■■■■■■■"; SetColor(9, 15); cout << "■" << endl;	// 2
		cout << "□"; SetColor(0, 15); cout << "■■　　　　　■■■■■■■■■■■■■■■■■■■■■■■■■■■■"; SetColor(9, 15); cout << "□" << endl;	// 3
		cout << "□"; SetColor(0, 15); cout << "■■　　　　　■■■■■■■■■■■■■■■■■■■■■■■■■■■■"; SetColor(9, 15); cout << "□" << endl;	// 4
		cout << "□"; SetColor(0, 15); cout << "■■　　　　　■■■■■■■■■■■■■■■■■■■■■■■■■■■■"; SetColor(9, 15); cout << "□" << endl;	// 5
		cout << "■"; SetColor(0, 15); cout << "■■　　　　　□□□□□□□□□□□□□□□□□□□□□□□□□□□　"; SetColor(9, 15); cout << "■" << endl;	// 6
		cout << "■"; SetColor(0, 15); cout << "■■　　　　　□　　　　　　　　　　　　　　　　　　　　　　　　　□　"; SetColor(9, 15); cout << "■" << endl;	// 7
		cout << "■"; SetColor(0, 15); cout << "■■　　　　　□　　　　　　　　　　　　　　　　　　　　　　　　　□　"; SetColor(9, 15); cout << "■" << endl;	// 8
		cout << "□"; SetColor(0, 15); cout << "■■　　　　　□　　　　　　　　　　　　　　"; SetColor(0, 15); cout << "　　■■■■■■■　　□　"; SetColor(9, 15); cout << "□" << endl;	// 9
		cout << "□"; SetColor(0, 15); cout << "■■　　　　　□　　　　　　　　　　　　　　"; SetColor(0, 15); cout << "　■　　　　　　　■　□　"; SetColor(9, 15); cout << "□" << endl;	// 10
		cout << "□"; SetColor(0, 15); cout << "■■　　　　　□　　　　"; SetColor(12, 15); cout << "　　■　　　　　　　"; SetColor(0, 15); cout << "■■■■■■■■■■■□　"; SetColor(9, 15); cout << "□" << endl;	// 11
		cout << "■"; SetColor(0, 15); cout << "■■　　　　　□　　　　"; SetColor(12, 15); cout << "■■■　　　　　　　"; SetColor(0, 15); cout << "　■　　　　　　　■　□　"; SetColor(9, 15); cout << "■" << endl;	// 12
		cout << "■"; SetColor(0, 15); cout << "■■　　　　　□　　　　"; SetColor(12, 15); cout << "　■　　　　■　　　"; SetColor(0, 15); cout << "　■　　　　　　　■　□　"; SetColor(9, 15); cout << "■" << endl;	// 13
		cout << "■"; SetColor(0, 15); cout << "■■　　　　　□　　　　"; SetColor(12, 15); cout << "　　　　　　■■■　"; SetColor(0, 15); cout << "　■■■■■■■■■　□　"; SetColor(9, 15); cout << "■" << endl;	// 14
		cout << "□"; SetColor(0, 15); cout << "■■　　　　　□　　　　"; SetColor(12, 15); cout << "　　　　　　　■　　"; SetColor(0, 15); cout << "　　　　　　　　　　　□　"; SetColor(9, 15); cout << "□" << endl;	// 15
		cout << "□"; SetColor(0, 15); cout << "■■　　　　　□　　　　　　　　　　　　　　　　　　　　　　　　　□　"; SetColor(9, 15); cout << "□" << endl;	// 16
		cout << "□"; SetColor(0, 15); cout << "■■　　　　　□　　　　　　"; SetColor(12, 15); cout << "■　　　　　　　　　　　　　　　　　　"; SetColor(0, 15); cout << "□　"; SetColor(9, 15); cout << "□" << endl;	// 17
		cout << "■"; SetColor(0, 15); cout << "■■　　　　　□　　　　　　"; SetColor(12, 15); cout << "■■■　　　　　　　"; SetColor(12, 15); cout << "　　■　　　　　　"; SetColor(0, 15); cout << "□　"; SetColor(9, 15); cout << "■" << endl;	// 18
		cout << "■"; SetColor(0, 15); cout << "■■　　　　　□　　　　　　"; SetColor(12, 15); cout << "　■　"; SetColor(14, 15); cout << "　■　■　　　"; SetColor(12, 15); cout << "■■■　　　　　　"; SetColor(0, 15); cout << "□　"; SetColor(9, 15); cout << "■" << endl;	// 19
		cout << "■"; SetColor(0, 15); cout << "■■　　　　　□　　　　　　　　　"; SetColor(14, 15); cout << "■　　　　　　"; SetColor(12, 15); cout << "　■　　　　　　　"; SetColor(0, 15); cout << "□　"; SetColor(9, 15); cout << "■" << endl;	// 20
		cout << "□"; SetColor(0, 15); cout << "■■　　　　　□　　　　　　　　　"; SetColor(14, 15); cout << "　　■　■　　　　　　　　　　　"; SetColor(0, 15); cout << "□　"; SetColor(9, 15); cout << "□" << endl;	// 21
		cout << "□"; SetColor(0, 15); cout << "■■　　　　　□□□　　　□□□□□□□□□□□□□□□□□□□□□　"; SetColor(9, 15); cout << "□" << endl;	// 22
		cout << "□"; SetColor(0, 15); cout << "■■　　　　　　　　　　　　　　　　　"; SetColor(10, 15); cout << "　■　　　　　　　　　　　　　　"; SetColor(9, 15); cout << "□" << endl;	// 23
		cout << "■"; SetColor(0, 15); cout << "■■　　　　　　　　　　　　　　　　　"; SetColor(10, 15); cout << "■■■　　　　　　　　　　　　　"; SetColor(9, 15); cout << "■" << endl;	// 24
		cout << "■"; SetColor(0, 15); cout << "■■　　　　　　　　　　　　　　　　　"; SetColor(10, 15); cout << "　■　　　　　　　　　　　　　　"; SetColor(9, 15); cout << "■" << endl;	// 25
		cout << "■"; SetColor(0, 15); cout << "■■　　　　　　　　　　　　　　　　　"; SetColor(10, 15); cout << "■　■　　　"; SetColor(0, 15); cout << "■■　　　　　　　　"; SetColor(9, 15); cout << "■" << endl;	// 26
		cout << "□"; SetColor(0, 15); cout << "■■　　　　　　　　　　　　　　　　　　　　　　　■■　　　　　　　　"; SetColor(9, 15); cout << "□" << endl;	// 27
		cout << "□"; SetColor(0, 15); cout << "■■　　　　　　　　　　　　　　　　　　　　　　　■■　　　　　　　　"; SetColor(9, 15); cout << "□" << endl;	// 28
		cout << "□"; SetColor(0, 15); cout << "■■　　　　■■■■■■■　　　　　　　　　　　　■■■■■■■■　　"; SetColor(9, 15); cout << "□" << endl;	// 29
		cout << "■"; SetColor(0, 15); cout << "■■　　　■　　　　　　　■　　　　　　　　　　■　　　　　　　　■　"; SetColor(9, 15); cout << "■" << endl;	// 30
		cout << "■"; SetColor(0, 15); cout << "■■　　■　　　　　　　　　■　　　　　　　　■　　　　　　　　　　■"; SetColor(9, 15); cout << "■" << endl;	// 31
		cout << "■"; SetColor(0, 15); cout << "■■　■■■■■■■■■■■■■　"; SetColor(14, 15); cout << "　■　　　"; SetColor(0, 15); cout << "■■■■■■■■■■■■■"; SetColor(9, 15); cout << "■" << endl;	// 32
		cout << "□"; SetColor(0, 15); cout << "■■　　■　　　　　　　　　■　　"; SetColor(14, 15); cout << "■■■　　"; SetColor(0, 15); cout << "　■　　　　　　　　　　■"; SetColor(9, 15); cout << "□" << endl;	// 33
		cout << "□"; SetColor(0, 15); cout << "■■　　■　■■■　　　　　■　　"; SetColor(14, 15); cout << "　■　　　"; SetColor(0, 15); cout << "　■　■■■　　　　　　■"; SetColor(9, 15); cout << "□" << endl;	// 34
		cout << "□"; SetColor(0, 15); cout << "■■　　■　■　■　　■■　■　　"; SetColor(14, 15); cout << "■　■　　"; SetColor(0, 15); cout << "　■　■　■　　　　　　■"; SetColor(9, 15); cout << "□" << endl;	// 35
		cout << "■"; SetColor(0, 15); cout << "■■　　■　■　■　　　　　■　　　　　　　　■　■　■　　　　　　■"; SetColor(9, 15); cout << "■" << endl;	// 36
		cout << "■■□□□■■■□□□■■■□□□■■■□□□■■■□□□■■■□□□■■" << endl;	// 37
	}
	break;
	}
}

void mainGame::Village1Choice()
{
	_key = '0';
	_key = _getch();

	if (_key == (char)DOWN)
	{
		switch (_village1check)
		{
		case 1:
		{
			_village1check = 2;
			Village1Screen();
			Village1Choice();
		}
		break;
		case 2:
		{
			_village1check = 3;
			Village1Screen();
			Village1Choice();
		}
		break;
		default:
		{
			Village1Choice();
		}
		break;
		}
	}
	else if (_key == (char)UP)
	{
		switch (_village1check)
		{
		case 2:
		{
			_village1check = 1;
			Village1Screen();
			Village1Choice();
		}
		break;
		case 3:
		{
			_village1check = 2;
			Village1Screen();
			Village1Choice();
		}
		break;
		default:
		{
			Village1Choice();
		}
		break;
		}
	}
	else if (_key == (char)RIGHT)
	{
		switch (_village1check)
		{
		case 1:
		{
			_village1check = 2;
			Village1Screen();
			Village1Choice();
		}
		break;
		case 2:
		{
			_village1check = 3;
			Village1Screen();
			Village1Choice();
		}
		break;
		default:
		{
			Village1Choice();
		}
		break;
		}
	}
	else if (_key == (char)LEFT)
	{
		switch (_village1check)
		{
		case 2:
		{
			_village1check = 1;
			Village1Screen();
			Village1Choice();
		}
		break;
		case 3:
		{
			_village1check = 2;
			Village1Screen();
			Village1Choice();
		}
		break;
		default:
		{
			Village1Choice();
		}
		break;
		}
	}
	else if (_key == (char)ENTER || _key == (char)SPACE)
	{
		switch (_village1check)
		{
		case 1:
		{
			_village1check = 0;
			Village1Screen();
			Sleep(1500);
			_effect = 0;
			b_villageMusic = false;

			Move();
			b_worldmapMusic = true;
			_worldcheck = 2;
			WorldMapScreen();
			WorldMapChoice();
		}
		break;
		case 2:
		{
			gotoxy(0, 26);
			SetColor(13, 15);

			cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;
			cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
			cout << "■"; SetColor(0, 15); cout << "　　[청년]　　　　　　　　　　　　  　　　　　　　　　　　　　　　　　"; SetColor(13, 15); cout << "■" << endl;
			cout << "■"; SetColor(0, 15); cout << "　　저희 마을은 평화롭지만 너무 따분해요　　　　　　　　　　　　　　　"; SetColor(13, 15); cout << "■" << endl;
			cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
			cout << "■"; SetColor(0, 15); cout << "　　마을밖에는 어떤 모험이 저를 기다리고 있을까요?　　　　　　　　　　"; SetColor(13, 15); cout << "■" << endl;
			cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
			cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
			cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
			cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
			cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;

			while (true)
			{
				_key = '0';
				_key = _getch();

				if (_key == (char)ENTER || _key == (char)SPACE)
				{
					break;
				}
			}

			Village1Screen();
			Village1Choice();
		}
		break;
		case 3:
		{
			_village1check = 0;
			_effect = 0;
			_village2check = 1;
			Village2Screen();
			Village2Choice();
		}
		break;
		default:
		{
			Village1Choice();
		}
		break;
		}
	}
	else if (_key == (char)ESC)
	{
		_statuscheck = 1;
		Status();
	}
	else
	{
		Village1Choice();
	}
}


void mainGame::Village2Screen()
{
	gotoxy(0, 0);
	SetColor(9, 15);

	switch (_village2check)
	{
	case 1:
	{
		cout << "■■□□□■■■□□□■■■□□□■■■□□□■■■□□□■■■□□□■■" << endl;	// 1
		cout << "■"; SetColor(0, 15); cout << "■■　　　　　　　　　　　　　　　　　　　　　　　■■　　　　　　　　"; SetColor(9, 15); cout << "■" << endl;	// 2
		cout << "□"; SetColor(0, 15); cout << "■■　　　　■■■■■■■　　　　　　　　　　　　■■■■■■■■　　"; SetColor(9, 15); cout << "□" << endl;	// 3
		cout << "□"; SetColor(0, 15); cout << "■■　　　■　　　　　　　■　　　　　　　　　　■　　　　　　　　■　"; SetColor(9, 15); cout << "□" << endl;	// 4
		cout << "□"; SetColor(0, 15); cout << "■■　　■　　　　　　　　　■　　　　　　　　■　　　　　　　　　　■"; SetColor(9, 15); cout << "□" << endl;	// 5
		cout << "■"; SetColor(0, 15); cout << "■■　■■■■■■■■■■■■■　"; SetColor(14, 15); cout << "　■　　　"; SetColor(0, 15); cout << "■■■■■■■■■■■■■"; SetColor(9, 15); cout << "■" << endl;	// 6
		cout << "■"; SetColor(0, 15); cout << "■■　　■　　　　　　　　　■　　"; SetColor(14, 15); cout << "■■■　　"; SetColor(0, 15); cout << "　■　　　　　　　　　　■"; SetColor(9, 15); cout << "■" << endl;	// 7
		cout << "■"; SetColor(0, 15); cout << "■■　　■　■■■　　　　　■　　"; SetColor(14, 15); cout << "　■　　　"; SetColor(0, 15); cout << "　■　■■■　　　　　　■"; SetColor(9, 15); cout << "■" << endl;	// 8
		cout << "□"; SetColor(0, 15); cout << "■■　　■　■　■　　■■　■　　"; SetColor(14, 15); cout << "■　■　　"; SetColor(0, 15); cout << "　■　■　■　　　　　　■"; SetColor(9, 15); cout << "□" << endl;	// 9
		cout << "□"; SetColor(0, 15); cout << "■■　　■　■　■　　"; SetColor(12, 15); cout << "　■　"; SetColor(0, 15); cout << "■　　　　　　　　■　■　■　　　　　　■"; SetColor(9, 15); cout << "□" << endl;	// 10
		cout << "□"; SetColor(0, 15); cout << "■■　　■■■■■■■"; SetColor(12, 15); cout << "■■■"; SetColor(0, 15); cout << "■　　　　　　　　■■■■■■■■■■■■"; SetColor(9, 15); cout << "□" << endl;	// 11
		cout << "■"; SetColor(0, 15); cout << "■■　　　　　　　　　"; SetColor(12, 15); cout << "　■　　　　　　　　　　　　　　　　　　　　　　"; SetColor(9, 15); cout << "■" << endl;	// 12
		cout << "■"; SetColor(0, 15); cout << "■■　　　　　　　　　"; SetColor(12, 15); cout << "■　■　　　　　　　　　　　　　　　　　　　　　"; SetColor(9, 15); cout << "■" << endl;	// 13
		cout << "■"; SetColor(0, 15); cout << "■■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　"; SetColor(9, 15); cout << "■" << endl;	// 14
		cout << "□"; SetColor(0, 15); cout << "■■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　"; SetColor(9, 15); cout << "□" << endl;	// 15
		cout << "□"; SetColor(0, 15); cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　"; SetColor(9, 15); cout << "□" << endl;	// 16
		cout << "□　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　"; SetColor(9, 15); cout << "□" << endl;	// 17
		cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　"; SetColor(9, 15); cout << "■" << endl;	// 18
		cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　"; SetColor(9, 15); cout << "■" << endl;	// 19
		cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　"; SetColor(9, 15); cout << "■" << endl;	// 20
		cout << "□　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　"; SetColor(9, 15); cout << "□" << endl;	// 21
		cout << "□　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　"; SetColor(9, 15); cout << "□" << endl;	// 22
		cout << "□　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　"; SetColor(9, 15); cout << "□" << endl;	// 23
		cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　"; SetColor(9, 15); cout << "■" << endl;	// 24
		cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　"; SetColor(9, 15); cout << "■" << endl;	// 25
		cout << "■"; SetColor(0, 15); cout << "■　　　　　　■■■■■■■　　　　　　　　　　　　　■■■■■■■　"; SetColor(9, 15); cout << "■" << endl;	// 26
		cout << "□"; SetColor(0, 15); cout << "■■　　　　■　　　　　　　■　　　　　　　　　　　■　　　　　　　■"; SetColor(9, 15); cout << "□" << endl;	// 27
		cout << "□"; SetColor(0, 15); cout << "■■　　　■　　　　　　　　　■　　　　　　　　　■　　　　　　　　　"; SetColor(9, 15); cout << "□" << endl;	// 28
		cout << "□"; SetColor(0, 15); cout << "■■　　■■■■■■■■■■■■■　　　　　　　■■■■■■■■■■■"; SetColor(9, 15); cout << "□" << endl;	// 29
		cout << "■"; SetColor(0, 15); cout << "■■　　　■　　　　　　　　　■　　　　　　　　　■　　　　　　　　　"; SetColor(9, 15); cout << "■" << endl;	// 30
		cout << "■"; SetColor(0, 15); cout << "■■　　　■　■■■　　　　　■　　　　　　　　　■　■■■　　　　　"; SetColor(9, 15); cout << "■" << endl;	// 31
		cout << "■"; SetColor(0, 15); cout << "■■　　　■　■　■　　　　　■　　　□□□　　　■　■　■　　■■　"; SetColor(9, 15); cout << "■" << endl;	// 32
		cout << "□"; SetColor(0, 15); cout << "■■　　　■　■　■　　　　　■　　　□□□　　　■　■　■　　　　　"; SetColor(9, 15); cout << "□" << endl;	// 33
		cout << "□"; SetColor(0, 15); cout << "■■　　　■■■■■■■■■■■　　　□□□　　　■■■■■■■■■■"; SetColor(9, 15); cout << "□" << endl;	// 34
		cout << "□"; SetColor(0, 15); cout << "■■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　"; SetColor(9, 15); cout << "□" << endl;	// 35
		cout << "■"; SetColor(0, 15); cout << "■■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　"; SetColor(9, 15); cout << "■" << endl;	// 36
		cout << "■■□□□■■■□□□■■■□□□■■■□□□■■■□□□■■■□□□■■" << endl;	// 37
	}
	break;
	case 2:
	{
		cout << "■■□□□■■■□□□■■■□□□■■■□□□■■■□□□■■■□□□■■" << endl;	// 1
		cout << "■"; SetColor(0, 15); cout << "■■　　　　　　　　　　　　　　　　　　　　　　　■■　　　　　　　　"; SetColor(9, 15); cout << "■" << endl;	// 2
		cout << "□"; SetColor(0, 15); cout << "■■　　　　■■■■■■■　　　　　　　　　　　　■■■■■■■■　　"; SetColor(9, 15); cout << "□" << endl;	// 3
		cout << "□"; SetColor(0, 15); cout << "■■　　　■　　　　　　　■　　　　　　　　　　■　　　　　　　　■　"; SetColor(9, 15); cout << "□" << endl;	// 4
		cout << "□"; SetColor(0, 15); cout << "■■　　■　　　　　　　　　■　　　　　　　　■　　　　　　　　　　■"; SetColor(9, 15); cout << "□" << endl;	// 5
		cout << "■"; SetColor(0, 15); cout << "■■　■■■■■■■■■■■■■　　　　　　■■■■■■■■■■■■■"; SetColor(9, 15); cout << "■" << endl;	// 6
		cout << "■"; SetColor(0, 15); cout << "■■　　■　　　　　　　　　■　　　　　　　　■　　　　　　　　　　■"; SetColor(9, 15); cout << "■" << endl;	// 7
		cout << "■"; SetColor(0, 15); cout << "■■　　■　■■■　　　　　■　　　　　　　　■　■■■　　　　　　■"; SetColor(9, 15); cout << "■" << endl;	// 8
		cout << "□"; SetColor(0, 15); cout << "■■　　■　■　■　　■■　■　　　　　　　　■　■　■　　　　　　■"; SetColor(9, 15); cout << "□" << endl;	// 9
		cout << "□"; SetColor(0, 15); cout << "■■　　■　■"; SetColor(14, 15); cout << "■"; SetColor(0, 15); cout << "■　　　"; SetColor(12, 15); cout << "■"; SetColor(0, 15); cout << "　■　　　　　　　　■　■　■　　　　　　■"; SetColor(9, 15); cout << "□" << endl;	// 10
		cout << "□"; SetColor(0, 15); cout << "■■　　■■"; SetColor(14, 15); cout << "■■■"; SetColor(0, 15); cout << "■■"; SetColor(12, 15); cout << "■■■"; SetColor(0, 15); cout << "■　　　　　　　　■■■■■■■■■■■■"; SetColor(9, 15); cout << "□" << endl;	// 11
		cout << "■"; SetColor(0, 15); cout << "■■　　　　"; SetColor(14, 15); cout << "　■　　　　"; SetColor(12, 15); cout << "■　　　　　　　　　　　　　　　　　　　　　　"; SetColor(9, 15); cout << "■" << endl;	// 12
		cout << "■"; SetColor(0, 15); cout << "■■　　　　"; SetColor(14, 15); cout << "■　■　　"; SetColor(12, 15); cout << "■　■　　　　　　　　　　　　　　　　　　　　　"; SetColor(9, 15); cout << "■" << endl;	// 13
		cout << "■"; SetColor(0, 15); cout << "■■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　"; SetColor(9, 15); cout << "■" << endl;	// 14
		cout << "□"; SetColor(0, 15); cout << "■■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　"; SetColor(9, 15); cout << "□" << endl;	// 15
		cout << "□"; SetColor(0, 15); cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　"; SetColor(9, 15); cout << "□" << endl;	// 16
		cout << "□　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　"; SetColor(9, 15); cout << "□" << endl;	// 17
		cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　"; SetColor(9, 15); cout << "■" << endl;	// 18
		cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　"; SetColor(9, 15); cout << "■" << endl;	// 19
		cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　"; SetColor(9, 15); cout << "■" << endl;	// 20
		cout << "□　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　"; SetColor(9, 15); cout << "□" << endl;	// 21
		cout << "□　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　"; SetColor(9, 15); cout << "□" << endl;	// 22
		cout << "□　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　"; SetColor(9, 15); cout << "□" << endl;	// 23
		cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　"; SetColor(9, 15); cout << "■" << endl;	// 24
		cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　"; SetColor(9, 15); cout << "■" << endl;	// 25
		cout << "■"; SetColor(0, 15); cout << "■　　　　　　■■■■■■■　　　　　　　　　　　　　■■■■■■■　"; SetColor(9, 15); cout << "■" << endl;	// 26
		cout << "□"; SetColor(0, 15); cout << "■■　　　　■　　　　　　　■　　　　　　　　　　　■　　　　　　　■"; SetColor(9, 15); cout << "□" << endl;	// 27
		cout << "□"; SetColor(0, 15); cout << "■■　　　■　　　　　　　　　■　　　　　　　　　■　　　　　　　　　"; SetColor(9, 15); cout << "□" << endl;	// 28
		cout << "□"; SetColor(0, 15); cout << "■■　　■■■■■■■■■■■■■　　　　　　　■■■■■■■■■■■"; SetColor(9, 15); cout << "□" << endl;	// 29
		cout << "■"; SetColor(0, 15); cout << "■■　　　■　　　　　　　　　■　　　　　　　　　■　　　　　　　　　"; SetColor(9, 15); cout << "■" << endl;	// 30
		cout << "■"; SetColor(0, 15); cout << "■■　　　■　■■■　　　　　■　　　　　　　　　■　■■■　　　　　"; SetColor(9, 15); cout << "■" << endl;	// 31
		cout << "■"; SetColor(0, 15); cout << "■■　　　■　■　■　　　　　■　　　□□□　　　■　■　■　　■■　"; SetColor(9, 15); cout << "■" << endl;	// 32
		cout << "□"; SetColor(0, 15); cout << "■■　　　■　■　■　　　　　■　　　□□□　　　■　■　■　　　　　"; SetColor(9, 15); cout << "□" << endl;	// 33
		cout << "□"; SetColor(0, 15); cout << "■■　　　■■■■■■■■■■■　　　□□□　　　■■■■■■■■■■"; SetColor(9, 15); cout << "□" << endl;	// 34
		cout << "□"; SetColor(0, 15); cout << "■■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　"; SetColor(9, 15); cout << "□" << endl;	// 35
		cout << "■"; SetColor(0, 15); cout << "■■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　"; SetColor(9, 15); cout << "■" << endl;	// 36
		cout << "■■□□□■■■□□□■■■□□□■■■□□□■■■□□□■■■□□□■■" << endl;	// 37
	}
	break;
	case 3:
	{
		cout << "■■□□□■■■□□□■■■□□□■■■□□□■■■□□□■■■□□□■■" << endl;	// 1
		cout << "■"; SetColor(0, 15); cout << "■■　　　　　　　　　　　　　　　　　　　　　　　■■　　　　　　　　"; SetColor(9, 15); cout << "■" << endl;	// 2
		cout << "□"; SetColor(0, 15); cout << "■■　　　　■■■■■■■　　　　　　　　　　　　■■■■■■■■　　"; SetColor(9, 15); cout << "□" << endl;	// 3
		cout << "□"; SetColor(0, 15); cout << "■■　　　■　　　　　　　■　　　　　　　　　　■　　　　　　　　■　"; SetColor(9, 15); cout << "□" << endl;	// 4
		cout << "□"; SetColor(0, 15); cout << "■■　　■　　　　　　　　　■　　　　　　　　■　　　　　　　　　　■"; SetColor(9, 15); cout << "□" << endl;	// 5
		cout << "■"; SetColor(0, 15); cout << "■■　■■■■■■■■■■■■■　　　　　　■■■■■■■■■■■■■"; SetColor(9, 15); cout << "■" << endl;	// 6
		cout << "■"; SetColor(0, 15); cout << "■■　　■　　　　　　　　　■　　　　　　　　■　　　　　　　　　　■"; SetColor(9, 15); cout << "■" << endl;	// 7
		cout << "■"; SetColor(0, 15); cout << "■■　　■　■■■　　　　　■　　　　　　　　■　■■■　　　　　　■"; SetColor(9, 15); cout << "■" << endl;	// 8
		cout << "□"; SetColor(0, 15); cout << "■■　　■　■　■　　■■　■　　　　　　　　■　■　■　　　　　　■"; SetColor(9, 15); cout << "□" << endl;	// 9
		cout << "□"; SetColor(0, 15); cout << "■■　　■　■　■　　"; SetColor(12, 15); cout << "　■　"; SetColor(0, 15); cout << "■　　　　　　　　■　■"; SetColor(14, 15); cout << "■"; SetColor(0, 15); cout << "■　　　　　　■"; SetColor(9, 15); cout << "□" << endl;	// 10
		cout << "□"; SetColor(0, 15); cout << "■■　　■■■■■■■"; SetColor(12, 15); cout << "■■■"; SetColor(0, 15); cout << "■　　　　　　　　■■"; SetColor(14, 15); cout << "■■■"; SetColor(0, 15); cout << "■■■■■■■"; SetColor(9, 15); cout << "□" << endl;	// 11
		cout << "■"; SetColor(0, 15); cout << "■■　　　　　　　　　"; SetColor(12, 15); cout << "　■　　　　　　　　　　　　"; SetColor(14, 15); cout << "　■　　　　　　　　"; SetColor(9, 15); cout << "■" << endl;	// 12
		cout << "■"; SetColor(0, 15); cout << "■■　　　　　　　　　"; SetColor(12, 15); cout << "■　■　　　　　　　　　　　"; SetColor(14, 15); cout << "■　■　　　　　　　"; SetColor(9, 15); cout << "■" << endl;	// 13
		cout << "■"; SetColor(0, 15); cout << "■■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　"; SetColor(9, 15); cout << "■" << endl;	// 14
		cout << "□"; SetColor(0, 15); cout << "■■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　"; SetColor(9, 15); cout << "□" << endl;	// 15
		cout << "□"; SetColor(0, 15); cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　"; SetColor(9, 15); cout << "□" << endl;	// 16
		cout << "□　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　"; SetColor(9, 15); cout << "□" << endl;	// 17
		cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　"; SetColor(9, 15); cout << "■" << endl;	// 18
		cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　"; SetColor(9, 15); cout << "■" << endl;	// 19
		cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　"; SetColor(9, 15); cout << "■" << endl;	// 20
		cout << "□　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　"; SetColor(9, 15); cout << "□" << endl;	// 21
		cout << "□　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　"; SetColor(9, 15); cout << "□" << endl;	// 22
		cout << "□　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　"; SetColor(9, 15); cout << "□" << endl;	// 23
		cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　"; SetColor(9, 15); cout << "■" << endl;	// 24
		cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　"; SetColor(9, 15); cout << "■" << endl;	// 25
		cout << "■"; SetColor(0, 15); cout << "■　　　　　　■■■■■■■　　　　　　　　　　　　　■■■■■■■　"; SetColor(9, 15); cout << "■" << endl;	// 26
		cout << "□"; SetColor(0, 15); cout << "■■　　　　■　　　　　　　■　　　　　　　　　　　■　　　　　　　■"; SetColor(9, 15); cout << "□" << endl;	// 27
		cout << "□"; SetColor(0, 15); cout << "■■　　　■　　　　　　　　　■　　　　　　　　　■　　　　　　　　　"; SetColor(9, 15); cout << "□" << endl;	// 28
		cout << "□"; SetColor(0, 15); cout << "■■　　■■■■■■■■■■■■■　　　　　　　■■■■■■■■■■■"; SetColor(9, 15); cout << "□" << endl;	// 29
		cout << "■"; SetColor(0, 15); cout << "■■　　　■　　　　　　　　　■　　　　　　　　　■　　　　　　　　　"; SetColor(9, 15); cout << "■" << endl;	// 30
		cout << "■"; SetColor(0, 15); cout << "■■　　　■　■■■　　　　　■　　　　　　　　　■　■■■　　　　　"; SetColor(9, 15); cout << "■" << endl;	// 31
		cout << "■"; SetColor(0, 15); cout << "■■　　　■　■　■　　　　　■　　　□□□　　　■　■　■　　■■　"; SetColor(9, 15); cout << "■" << endl;	// 32
		cout << "□"; SetColor(0, 15); cout << "■■　　　■　■　■　　　　　■　　　□□□　　　■　■　■　　　　　"; SetColor(9, 15); cout << "□" << endl;	// 33
		cout << "□"; SetColor(0, 15); cout << "■■　　　■■■■■■■■■■■　　　□□□　　　■■■■■■■■■■"; SetColor(9, 15); cout << "□" << endl;	// 34
		cout << "□"; SetColor(0, 15); cout << "■■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　"; SetColor(9, 15); cout << "□" << endl;	// 35
		cout << "■"; SetColor(0, 15); cout << "■■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　"; SetColor(9, 15); cout << "■" << endl;	// 36
		cout << "■■□□□■■■□□□■■■□□□■■■□□□■■■□□□■■■□□□■■" << endl;	// 37
	}
	break;
	case 4:
	{
		cout << "■■□□□■■■□□□■■■□□□■■■□□□■■■□□□■■■□□□■■" << endl;	// 1
		cout << "■"; SetColor(0, 15); cout << "■■　　　　　　　　　　　　　　　　　　　　　　　■■　　　　　　　　"; SetColor(9, 15); cout << "■" << endl;	// 2
		cout << "□"; SetColor(0, 15); cout << "■■　　　　■■■■■■■　　　　　　　　　　　　■■■■■■■■　　"; SetColor(9, 15); cout << "□" << endl;	// 3
		cout << "□"; SetColor(0, 15); cout << "■■　　　■　　　　　　　■　　　　　　　　　　■　　　　　　　　■　"; SetColor(9, 15); cout << "□" << endl;	// 4
		cout << "□"; SetColor(0, 15); cout << "■■　　■　　　　　　　　　■　　　　　　　　■　　　　　　　　　　■"; SetColor(9, 15); cout << "□" << endl;	// 5
		cout << "■"; SetColor(0, 15); cout << "■■　■■■■■■■■■■■■■　　　　　　■■■■■■■■■■■■■"; SetColor(9, 15); cout << "■" << endl;	// 6
		cout << "■"; SetColor(0, 15); cout << "■■　　■　　　　　　　　　■　　　　　　　　■　　　　　　　　　　■"; SetColor(9, 15); cout << "■" << endl;	// 7
		cout << "■"; SetColor(0, 15); cout << "■■　　■　■■■　　　　　■　　　　　　　　■　■■■　　　　　　■"; SetColor(9, 15); cout << "■" << endl;	// 8
		cout << "□"; SetColor(0, 15); cout << "■■　　■　■　■　　■■　■　　　　　　　　■　■　■　　　　　　■"; SetColor(9, 15); cout << "□" << endl;	// 9
		cout << "□"; SetColor(0, 15); cout << "■■　　■　■　■　　　"; SetColor(12, 15); cout << "■　"; SetColor(0, 15); cout << "■"; SetColor(14, 15); cout << "■　　　　　　　"; SetColor(0, 15); cout << "■　■　■　　　　　　■"; SetColor(9, 15); cout << "□" << endl;	// 10
		cout << "□"; SetColor(0, 15); cout << "■■　　■■■■■■■"; SetColor(12, 15); cout << "■■■"; SetColor(14, 15); cout << "■■■　　　　　　"; SetColor(0, 15); cout << "■■■■■■■■■■■■"; SetColor(9, 15); cout << "□" << endl;	// 11
		cout << "■"; SetColor(0, 15); cout << "■■　　　　　　　　　"; SetColor(12, 15); cout << "　■　"; SetColor(14, 15); cout << "　■　　　　　　　　　　　　　　　　　　　"; SetColor(9, 15); cout << "■" << endl;	// 12
		cout << "■"; SetColor(0, 15); cout << "■■　　　　　　　　　"; SetColor(12, 15); cout << "■　■"; SetColor(14, 15); cout << "■　■　　　　　　　　　　　　　　　　　　"; SetColor(9, 15); cout << "■" << endl;	// 13
		cout << "■"; SetColor(0, 15); cout << "■■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　"; SetColor(9, 15); cout << "■" << endl;	// 14
		cout << "□"; SetColor(0, 15); cout << "■■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　"; SetColor(9, 15); cout << "□" << endl;	// 15
		cout << "□"; SetColor(0, 15); cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　"; SetColor(9, 15); cout << "□" << endl;	// 16
		cout << "□　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　"; SetColor(9, 15); cout << "□" << endl;	// 17
		cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　"; SetColor(9, 15); cout << "■" << endl;	// 18
		cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　"; SetColor(9, 15); cout << "■" << endl;	// 19
		cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　"; SetColor(9, 15); cout << "■" << endl;	// 20
		cout << "□　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　"; SetColor(9, 15); cout << "□" << endl;	// 21
		cout << "□　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　"; SetColor(9, 15); cout << "□" << endl;	// 22
		cout << "□　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　"; SetColor(9, 15); cout << "□" << endl;	// 23
		cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　"; SetColor(9, 15); cout << "■" << endl;	// 24
		cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　"; SetColor(9, 15); cout << "■" << endl;	// 25
		cout << "■"; SetColor(0, 15); cout << "■　　　　　　■■■■■■■　　　　　　　　　　　　　■■■■■■■　"; SetColor(9, 15); cout << "■" << endl;	// 26
		cout << "□"; SetColor(0, 15); cout << "■■　　　　■　　　　　　　■　　　　　　　　　　　■　　　　　　　■"; SetColor(9, 15); cout << "□" << endl;	// 27
		cout << "□"; SetColor(0, 15); cout << "■■　　　■　　　　　　　　　■　　　　　　　　　■　　　　　　　　　"; SetColor(9, 15); cout << "□" << endl;	// 28
		cout << "□"; SetColor(0, 15); cout << "■■　　■■■■■■■■■■■■■　　　　　　　■■■■■■■■■■■"; SetColor(9, 15); cout << "□" << endl;	// 29
		cout << "■"; SetColor(0, 15); cout << "■■　　　■　　　　　　　　　■　　　　　　　　　■　　　　　　　　　"; SetColor(9, 15); cout << "■" << endl;	// 30
		cout << "■"; SetColor(0, 15); cout << "■■　　　■　■■■　　　　　■　　　　　　　　　■　■■■　　　　　"; SetColor(9, 15); cout << "■" << endl;	// 31
		cout << "■"; SetColor(0, 15); cout << "■■　　　■　■　■　　　　　■　　　□□□　　　■　■　■　　■■　"; SetColor(9, 15); cout << "■" << endl;	// 32
		cout << "□"; SetColor(0, 15); cout << "■■　　　■　■　■　　　　　■　　　□□□　　　■　■　■　　　　　"; SetColor(9, 15); cout << "□" << endl;	// 33
		cout << "□"; SetColor(0, 15); cout << "■■　　　■■■■■■■■■■■　　　□□□　　　■■■■■■■■■■"; SetColor(9, 15); cout << "□" << endl;	// 34
		cout << "□"; SetColor(0, 15); cout << "■■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　"; SetColor(9, 15); cout << "□" << endl;	// 35
		cout << "■"; SetColor(0, 15); cout << "■■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　"; SetColor(9, 15); cout << "■" << endl;	// 36
		cout << "■■□□□■■■□□□■■■□□□■■■□□□■■■□□□■■■□□□■■" << endl;	// 37
	}
	break;
	case 5:
	{
		cout << "■■□□□■■■□□□■■■□□□■■■□□□■■■□□□■■■□□□■■" << endl;	// 1
		cout << "■"; SetColor(0, 15); cout << "■■　　　　　　　　　　　　　　　　　　　　　　　■■　　　　　　　　"; SetColor(9, 15); cout << "■" << endl;	// 2
		cout << "□"; SetColor(0, 15); cout << "■■　　　　■■■■■■■　　　　　　　　　　　　■■■■■■■■　　"; SetColor(9, 15); cout << "□" << endl;	// 3
		cout << "□"; SetColor(0, 15); cout << "■■　　　■　　　　　　　■　　　　　　　　　　■　　　　　　　　■　"; SetColor(9, 15); cout << "□" << endl;	// 4
		cout << "□"; SetColor(0, 15); cout << "■■　　■　　　　　　　　　■　　　　　　　　■　　　　　　　　　　■"; SetColor(9, 15); cout << "□" << endl;	// 5
		cout << "■"; SetColor(0, 15); cout << "■■　■■■■■■■■■■■■■　　　　　　■■■■■■■■■■■■■"; SetColor(9, 15); cout << "■" << endl;	// 6
		cout << "■"; SetColor(0, 15); cout << "■■　　■　　　　　　　　　■　　　　　　　　■　　　　　　　　　　■"; SetColor(9, 15); cout << "■" << endl;	// 7
		cout << "■"; SetColor(0, 15); cout << "■■　　■　■■■　　　　　■　　　　　　　　■　■■■　　　　　　■"; SetColor(9, 15); cout << "■" << endl;	// 8
		cout << "□"; SetColor(0, 15); cout << "■■　　■　■　■　　■■　■　　　　　　　　■　■　■　　　　　　■"; SetColor(9, 15); cout << "□" << endl;	// 9
		cout << "□"; SetColor(0, 15); cout << "■■　　■　■　■　　"; SetColor(12, 15); cout << "　■　"; SetColor(0, 15); cout << "■　　　　　　　　■　■　■　　　　　　■"; SetColor(9, 15); cout << "□" << endl;	// 10
		cout << "□"; SetColor(0, 15); cout << "■■　　■■■■■■■"; SetColor(12, 15); cout << "■■■"; SetColor(0, 15); cout << "■　　　　　　　　■■■■■■■■■■■■"; SetColor(9, 15); cout << "□" << endl;	// 11
		cout << "■"; SetColor(0, 15); cout << "■■　　　　　　　　　"; SetColor(12, 15); cout << "　■　　　　　　　　　　　　　　　　　　　　　　"; SetColor(9, 15); cout << "■" << endl;	// 12
		cout << "■"; SetColor(0, 15); cout << "■■　　　　　　　　　"; SetColor(12, 15); cout << "■　■　　　　　　　　　　　　　　　　　　　　　"; SetColor(9, 15); cout << "■" << endl;	// 13
		cout << "■"; SetColor(0, 15); cout << "■■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　"; SetColor(9, 15); cout << "■" << endl;	// 14
		cout << "□"; SetColor(0, 15); cout << "■■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　"; SetColor(9, 15); cout << "□" << endl;	// 15
		cout << "□"; SetColor(0, 15); cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　"; SetColor(9, 15); cout << "□" << endl;	// 16
		cout << "□　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　"; SetColor(9, 15); cout << "□" << endl;	// 17
		cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　"; SetColor(9, 15); cout << "■" << endl;	// 18
		cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　"; SetColor(9, 15); cout << "■" << endl;	// 19
		cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　"; SetColor(9, 15); cout << "■" << endl;	// 20
		cout << "□　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　"; SetColor(9, 15); cout << "□" << endl;	// 21
		cout << "□　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　"; SetColor(9, 15); cout << "□" << endl;	// 22
		cout << "□　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　"; SetColor(9, 15); cout << "□" << endl;	// 23
		cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　"; SetColor(9, 15); cout << "■" << endl;	// 24
		cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　"; SetColor(9, 15); cout << "■" << endl;	// 25
		cout << "■"; SetColor(0, 15); cout << "■　　　　　　■■■■■■■　　　　　　　　　　　　　■■■■■■■　"; SetColor(9, 15); cout << "■" << endl;	// 26
		cout << "□"; SetColor(0, 15); cout << "■■　　　　■　　　　　　　■　　　　　　　　　　　■　　　　　　　■"; SetColor(9, 15); cout << "□" << endl;	// 27
		cout << "□"; SetColor(0, 15); cout << "■■　　　■　　　　　　　　　■　　　　　　　　　■　　　　　　　　　"; SetColor(9, 15); cout << "□" << endl;	// 28
		cout << "□"; SetColor(0, 15); cout << "■■　　■■■■■■■■■■■■■　　　　　　　■■■■■■■■■■■"; SetColor(9, 15); cout << "□" << endl;	// 29
		cout << "■"; SetColor(0, 15); cout << "■■　　　■　　　　　　　　　■　　　　　　　　　■　　　　　　　　　"; SetColor(9, 15); cout << "■" << endl;	// 30
		cout << "■"; SetColor(0, 15); cout << "■■　　　■　■■■　　　　　■"; SetColor(14, 15); cout << "　■　"; SetColor(0, 15); cout << "　　　　　　■　■■■　　　　　"; SetColor(9, 15); cout << "■" << endl;	// 31
		cout << "■"; SetColor(0, 15); cout << "■■　　　■　■　■　　　　　■"; SetColor(14, 15); cout << "■■■"; SetColor(0, 15); cout << "□□□　　　■　■　■　　■■　"; SetColor(9, 15); cout << "■" << endl;	// 32
		cout << "□"; SetColor(0, 15); cout << "■■　　　■　■　■　　　　　■"; SetColor(14, 15); cout << "　■　"; SetColor(0, 15); cout << "□□□　　　■　■　■　　　　　"; SetColor(9, 15); cout << "□" << endl;	// 33
		cout << "□"; SetColor(0, 15); cout << "■■　　　■■■■■■■■■■■"; SetColor(14, 15); cout << "■　■"; SetColor(0, 15); cout << "□□□　　　■■■■■■■■■■"; SetColor(9, 15); cout << "□" << endl;	// 34
		cout << "□"; SetColor(0, 15); cout << "■■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　"; SetColor(9, 15); cout << "□" << endl;	// 35
		cout << "■"; SetColor(0, 15); cout << "■■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　"; SetColor(9, 15); cout << "■" << endl;	// 36
		cout << "■■□□□■■■□□□■■■□□□■■■□□□■■■□□□■■■□□□■■" << endl;	// 37
	}
	break;
	case 6:
	{
		cout << "■■□□□■■■□□□■■■□□□■■■□□□■■■□□□■■■□□□■■" << endl;	// 1
		cout << "■"; SetColor(0, 15); cout << "■■　　　　　　　　　　　　　　　　　　　　　　　■■　　　　　　　　"; SetColor(9, 15); cout << "■" << endl;	// 2
		cout << "□"; SetColor(0, 15); cout << "■■　　　　■■■■■■■　　　　　　　　　　　　■■■■■■■■　　"; SetColor(9, 15); cout << "□" << endl;	// 3
		cout << "□"; SetColor(0, 15); cout << "■■　　　■　　　　　　　■　　　　　　　　　　■　　　　　　　　■　"; SetColor(9, 15); cout << "□" << endl;	// 4
		cout << "□"; SetColor(0, 15); cout << "■■　　■　　　　　　　　　■　　　　　　　　■　　　　　　　　　　■"; SetColor(9, 15); cout << "□" << endl;	// 5
		cout << "■"; SetColor(0, 15); cout << "■■　■■■■■■■■■■■■■　　　　　　■■■■■■■■■■■■■"; SetColor(9, 15); cout << "■" << endl;	// 6
		cout << "■"; SetColor(0, 15); cout << "■■　　■　　　　　　　　　■　　　　　　　　■　　　　　　　　　　■"; SetColor(9, 15); cout << "■" << endl;	// 7
		cout << "■"; SetColor(0, 15); cout << "■■　　■　■■■　　　　　■　　　　　　　　■　■■■　　　　　　■"; SetColor(9, 15); cout << "■" << endl;	// 8
		cout << "□"; SetColor(0, 15); cout << "■■　　■　■　■　　■■　■　　　　　　　　■　■　■　　　　　　■"; SetColor(9, 15); cout << "□" << endl;	// 9
		cout << "□"; SetColor(0, 15); cout << "■■　　■　■　■　　"; SetColor(12, 15); cout << "　■　"; SetColor(0, 15); cout << "■　　　　　　　　■　■　■　　　　　　■"; SetColor(9, 15); cout << "□" << endl;	// 10
		cout << "□"; SetColor(0, 15); cout << "■■　　■■■■■■■"; SetColor(12, 15); cout << "■■■"; SetColor(0, 15); cout << "■　　　　　　　　■■■■■■■■■■■■"; SetColor(9, 15); cout << "□" << endl;	// 11
		cout << "■"; SetColor(0, 15); cout << "■■　　　　　　　　　"; SetColor(12, 15); cout << "　■　　　　　　　　　　　　　　　　　　　　　　"; SetColor(9, 15); cout << "■" << endl;	// 12
		cout << "■"; SetColor(0, 15); cout << "■■　　　　　　　　　"; SetColor(12, 15); cout << "■　■　　　　　　　　　　　　　　　　　　　　　"; SetColor(9, 15); cout << "■" << endl;	// 13
		cout << "■"; SetColor(0, 15); cout << "■■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　"; SetColor(9, 15); cout << "■" << endl;	// 14
		cout << "□"; SetColor(0, 15); cout << "■■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　"; SetColor(9, 15); cout << "□" << endl;	// 15
		cout << "□"; SetColor(0, 15); cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　"; SetColor(9, 15); cout << "□" << endl;	// 16
		cout << "□　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　"; SetColor(9, 15); cout << "□" << endl;	// 17
		cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　"; SetColor(9, 15); cout << "■" << endl;	// 18
		cout << "■　"; SetColor(14, 15); cout << "　■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　"; SetColor(9, 15); cout << "■" << endl;	// 19
		cout << "■　"; SetColor(14, 15); cout << "■■■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　"; SetColor(9, 15); cout << "■" << endl;	// 20
		cout << "□　"; SetColor(14, 15); cout << "　■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　"; SetColor(9, 15); cout << "□" << endl;	// 21
		cout << "□　"; SetColor(14, 15); cout << "■　■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　"; SetColor(9, 15); cout << "□" << endl;	// 22
		cout << "□　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　"; SetColor(9, 15); cout << "□" << endl;	// 23
		cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　"; SetColor(9, 15); cout << "■" << endl;	// 24
		cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　"; SetColor(9, 15); cout << "■" << endl;	// 25
		cout << "■"; SetColor(0, 15); cout << "■　　　　　　■■■■■■■　　　　　　　　　　　　　■■■■■■■　"; SetColor(9, 15); cout << "■" << endl;	// 26
		cout << "□"; SetColor(0, 15); cout << "■■　　　　■　　　　　　　■　　　　　　　　　　　■　　　　　　　■"; SetColor(9, 15); cout << "□" << endl;	// 27
		cout << "□"; SetColor(0, 15); cout << "■■　　　■　　　　　　　　　■　　　　　　　　　■　　　　　　　　　"; SetColor(9, 15); cout << "□" << endl;	// 28
		cout << "□"; SetColor(0, 15); cout << "■■　　■■■■■■■■■■■■■　　　　　　　■■■■■■■■■■■"; SetColor(9, 15); cout << "□" << endl;	// 29
		cout << "■"; SetColor(0, 15); cout << "■■　　　■　　　　　　　　　■　　　　　　　　　■　　　　　　　　　"; SetColor(9, 15); cout << "■" << endl;	// 30
		cout << "■"; SetColor(0, 15); cout << "■■　　　■　■■■　　　　　■　　　　　　　　　■　■■■　　　　　"; SetColor(9, 15); cout << "■" << endl;	// 31
		cout << "■"; SetColor(0, 15); cout << "■■　　　■　■　■　　　　　■　　　□□□　　　■　■　■　　■■　"; SetColor(9, 15); cout << "■" << endl;	// 32
		cout << "□"; SetColor(0, 15); cout << "■■　　　■　■　■　　　　　■　　　□□□　　　■　■　■　　　　　"; SetColor(9, 15); cout << "□" << endl;	// 33
		cout << "□"; SetColor(0, 15); cout << "■■　　　■■■■■■■■■■■　　　□□□　　　■■■■■■■■■■"; SetColor(9, 15); cout << "□" << endl;	// 34
		cout << "□"; SetColor(0, 15); cout << "■■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　"; SetColor(9, 15); cout << "□" << endl;	// 35
		cout << "■"; SetColor(0, 15); cout << "■■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　"; SetColor(9, 15); cout << "■" << endl;	// 36
		cout << "■■□□□■■■□□□■■■□□□■■■□□□■■■□□□■■■□□□■■" << endl;	// 37
	}
	break;
	case 7:
	{
		cout << "■■□□□■■■□□□■■■□□□■■■□□□■■■□□□■■■□□□■■" << endl;	// 1
		cout << "■"; SetColor(0, 15); cout << "■■　　　　　　　　　　　　　　　　　　　　　　　■■　　　　　　　　"; SetColor(9, 15); cout << "■" << endl;	// 2
		cout << "□"; SetColor(0, 15); cout << "■■　　　　■■■■■■■　　　　　　　　　　　　■■■■■■■■　　"; SetColor(9, 15); cout << "□" << endl;	// 3
		cout << "□"; SetColor(0, 15); cout << "■■　　　■　　　　　　　■　　　　　　　　　　■　　　　　　　　■　"; SetColor(9, 15); cout << "□" << endl;	// 4
		cout << "□"; SetColor(0, 15); cout << "■■　　■　　　　　　　　　■　　　　　　　　■　　　　　　　　　　■"; SetColor(9, 15); cout << "□" << endl;	// 5
		cout << "■"; SetColor(0, 15); cout << "■■　■■■■■■■■■■■■■　　　　　　■■■■■■■■■■■■■"; SetColor(9, 15); cout << "■" << endl;	// 6
		cout << "■"; SetColor(0, 15); cout << "■■　　■　　　　　　　　　■　　　　　　　　■　　　　　　　　　　■"; SetColor(9, 15); cout << "■" << endl;	// 7
		cout << "■"; SetColor(0, 15); cout << "■■　　■　■■■　　　　　■　　　　　　　　■　■■■　　　　　　■"; SetColor(9, 15); cout << "■" << endl;	// 8
		cout << "□"; SetColor(0, 15); cout << "■■　　■　■　■　　■■　■　　　　　　　　■　■　■　　　　　　■"; SetColor(9, 15); cout << "□" << endl;	// 9
		cout << "□"; SetColor(0, 15); cout << "■■　　■　■　■　　"; SetColor(12, 15); cout << "　■　"; SetColor(0, 15); cout << "■　　　　　　　　■　■　■　　　　　　■"; SetColor(9, 15); cout << "□" << endl;	// 10
		cout << "□"; SetColor(0, 15); cout << "■■　　■■■■■■■"; SetColor(12, 15); cout << "■■■"; SetColor(0, 15); cout << "■　　　　　　　　■■■■■■■■■■■■"; SetColor(9, 15); cout << "□" << endl;	// 11
		cout << "■"; SetColor(0, 15); cout << "■■　　　　　　　　　"; SetColor(12, 15); cout << "　■　　　　　　　　　　　　　　　　　　　　　　"; SetColor(9, 15); cout << "■" << endl;	// 12
		cout << "■"; SetColor(0, 15); cout << "■■　　　　　　　　　"; SetColor(12, 15); cout << "■　■　　　　　　　　　　　　　　　　　　　　　"; SetColor(9, 15); cout << "■" << endl;	// 13
		cout << "■"; SetColor(0, 15); cout << "■■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　"; SetColor(9, 15); cout << "■" << endl;	// 14
		cout << "□"; SetColor(0, 15); cout << "■■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　"; SetColor(9, 15); cout << "□" << endl;	// 15
		cout << "□"; SetColor(0, 15); cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　"; SetColor(9, 15); cout << "□" << endl;	// 16
		cout << "□　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　"; SetColor(9, 15); cout << "□" << endl;	// 17
		cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　"; SetColor(9, 15); cout << "■" << endl;	// 18
		cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　"; SetColor(9, 15); cout << "■" << endl;	// 19
		cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　"; SetColor(9, 15); cout << "■" << endl;	// 20
		cout << "□　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　"; SetColor(9, 15); cout << "□" << endl;	// 21
		cout << "□　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　"; SetColor(9, 15); cout << "□" << endl;	// 22
		cout << "□　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　"; SetColor(9, 15); cout << "□" << endl;	// 23
		cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　"; SetColor(9, 15); cout << "■" << endl;	// 24
		cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　"; SetColor(9, 15); cout << "■" << endl;	// 25
		cout << "■"; SetColor(0, 15); cout << "■　　　　　　■■■■■■■　　　　　　　　　　　　　■■■■■■■　"; SetColor(9, 15); cout << "■" << endl;	// 26
		cout << "□"; SetColor(0, 15); cout << "■■　　　　■　　　　　　　■　　　　　　　　　　　■　　　　　　　■"; SetColor(9, 15); cout << "□" << endl;	// 27
		cout << "□"; SetColor(0, 15); cout << "■■　　　■　　　　　　　　　■　　　　　　　　　■　　　　　　　　　"; SetColor(9, 15); cout << "□" << endl;	// 28
		cout << "□"; SetColor(0, 15); cout << "■■　　■■■■■■■■■■■■■　　　　　　　■■■■■■■■■■■"; SetColor(9, 15); cout << "□" << endl;	// 29
		cout << "■"; SetColor(0, 15); cout << "■■　　　■　　　　　　　　　■　　　　　　　　　■　　　　　　　　　"; SetColor(9, 15); cout << "■" << endl;	// 30
		cout << "■"; SetColor(0, 15); cout << "■■　　　■　■■■　　　　　■　　　　　　　　　■　■■■　　　　　"; SetColor(9, 15); cout << "■" << endl;	// 31
		cout << "■"; SetColor(0, 15); cout << "■■　　　■　■　■　　　　　■　　　□□□　　　■　■　■　　■■　"; SetColor(9, 15); cout << "■" << endl;	// 32
		cout << "□"; SetColor(0, 15); cout << "■■　　　■　■"; SetColor(14, 15); cout << "■"; SetColor(0, 15); cout << "■　　　　　■　　　□□□　　　■　■　■　　　　　"; SetColor(9, 15); cout << "□" << endl;	// 33
		cout << "□"; SetColor(0, 15); cout << "■■　　　■■"; SetColor(14, 15); cout << "■■■"; SetColor(0, 15); cout << "■■■■■■　　　□□□　　　■■■■■■■■■■"; SetColor(9, 15); cout << "□" << endl;	// 34
		cout << "□"; SetColor(0, 15); cout << "■■　　　　　"; SetColor(14, 15); cout << "　■　　　　　　　　　　　　　　　　　　　　　　　　　　"; SetColor(9, 15); cout << "□" << endl;	// 35
		cout << "■"; SetColor(0, 15); cout << "■■　　　　　"; SetColor(14, 15); cout << "■　■　　　　　　　　　　　　　　　　　　　　　　　　　"; SetColor(9, 15); cout << "■" << endl;	// 36
		cout << "■■□□□■■■□□□■■■□□□■■■□□□■■■□□□■■■□□□■■" << endl;	// 37
	}
	break;
	case 8:
	{
		cout << "■■□□□■■■□□□■■■□□□■■■□□□■■■□□□■■■□□□■■" << endl;	// 1
		cout << "■"; SetColor(0, 15); cout << "■■　　　　　　　　　　　　　　　　　　　　　　　■■　　　　　　　　"; SetColor(9, 15); cout << "■" << endl;	// 2
		cout << "□"; SetColor(0, 15); cout << "■■　　　　■■■■■■■　　　　　　　　　　　　■■■■■■■■　　"; SetColor(9, 15); cout << "□" << endl;	// 3
		cout << "□"; SetColor(0, 15); cout << "■■　　　■　　　　　　　■　　　　　　　　　　■　　　　　　　　■　"; SetColor(9, 15); cout << "□" << endl;	// 4
		cout << "□"; SetColor(0, 15); cout << "■■　　■　　　　　　　　　■　　　　　　　　■　　　　　　　　　　■"; SetColor(9, 15); cout << "□" << endl;	// 5
		cout << "■"; SetColor(0, 15); cout << "■■　■■■■■■■■■■■■■　　　　　　■■■■■■■■■■■■■"; SetColor(9, 15); cout << "■" << endl;	// 6
		cout << "■"; SetColor(0, 15); cout << "■■　　■　　　　　　　　　■　　　　　　　　■　　　　　　　　　　■"; SetColor(9, 15); cout << "■" << endl;	// 7
		cout << "■"; SetColor(0, 15); cout << "■■　　■　■■■　　　　　■　　　　　　　　■　■■■　　　　　　■"; SetColor(9, 15); cout << "■" << endl;	// 8
		cout << "□"; SetColor(0, 15); cout << "■■　　■　■　■　　■■　■　　　　　　　　■　■　■　　　　　　■"; SetColor(9, 15); cout << "□" << endl;	// 9
		cout << "□"; SetColor(0, 15); cout << "■■　　■　■　■　　"; SetColor(12, 15); cout << "　■　"; SetColor(0, 15); cout << "■　　　　　　　　■　■　■　　　　　　■"; SetColor(9, 15); cout << "□" << endl;	// 10
		cout << "□"; SetColor(0, 15); cout << "■■　　■■■■■■■"; SetColor(12, 15); cout << "■■■"; SetColor(0, 15); cout << "■　　　　　　　　■■■■■■■■■■■■"; SetColor(9, 15); cout << "□" << endl;	// 11
		cout << "■"; SetColor(0, 15); cout << "■■　　　　　　　　　"; SetColor(12, 15); cout << "　■　　　　　　　　　　　　　　　　　　　　　　"; SetColor(9, 15); cout << "■" << endl;	// 12
		cout << "■"; SetColor(0, 15); cout << "■■　　　　　　　　　"; SetColor(12, 15); cout << "■　■　　　　　　　　　　　　　　　　　　　　　"; SetColor(9, 15); cout << "■" << endl;	// 13
		cout << "■"; SetColor(0, 15); cout << "■■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　"; SetColor(9, 15); cout << "■" << endl;	// 14
		cout << "□"; SetColor(0, 15); cout << "■■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　"; SetColor(9, 15); cout << "□" << endl;	// 15
		cout << "□"; SetColor(0, 15); cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　"; SetColor(9, 15); cout << "□" << endl;	// 16
		cout << "□　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　"; SetColor(9, 15); cout << "□" << endl;	// 17
		cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　"; SetColor(9, 15); cout << "■" << endl;	// 18
		cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　"; SetColor(9, 15); cout << "■" << endl;	// 19
		cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　"; SetColor(9, 15); cout << "■" << endl;	// 20
		cout << "□　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　"; SetColor(9, 15); cout << "□" << endl;	// 21
		cout << "□　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　"; SetColor(9, 15); cout << "□" << endl;	// 22
		cout << "□　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　"; SetColor(9, 15); cout << "□" << endl;	// 23
		cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　"; SetColor(9, 15); cout << "■" << endl;	// 24
		cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　"; SetColor(9, 15); cout << "■" << endl;	// 25
		cout << "■"; SetColor(0, 15); cout << "■　　　　　　■■■■■■■　　　　　　　　　　　　　■■■■■■■　"; SetColor(9, 15); cout << "■" << endl;	// 26
		cout << "□"; SetColor(0, 15); cout << "■■　　　　■　　　　　　　■　　　　　　　　　　　■　　　　　　　■"; SetColor(9, 15); cout << "□" << endl;	// 27
		cout << "□"; SetColor(0, 15); cout << "■■　　　■　　　　　　　　　■　　　　　　　　　■　　　　　　　　　"; SetColor(9, 15); cout << "□" << endl;	// 28
		cout << "□"; SetColor(0, 15); cout << "■■　　■■■■■■■■■■■■■　　　　　　　■■■■■■■■■■■"; SetColor(9, 15); cout << "□" << endl;	// 29
		cout << "■"; SetColor(0, 15); cout << "■■　　　■　　　　　　　　　■　　　　　　　　　■　　　　　　　　　"; SetColor(9, 15); cout << "■" << endl;	// 30
		cout << "■"; SetColor(0, 15); cout << "■■　　　■　■■■　　　　　■　　　　　　　　　■　■■■　　　　　"; SetColor(9, 15); cout << "■" << endl;	// 31
		cout << "■"; SetColor(0, 15); cout << "■■　　　■　■　■　　　　　■　　　□□□　　　■　■　■　　■■　"; SetColor(9, 15); cout << "■" << endl;	// 32
		cout << "□"; SetColor(0, 15); cout << "■■　　　■　■　■　　　　　■　　　□□□　　　■　■"; SetColor(14, 15); cout << "■"; SetColor(0, 15); cout << "■　　　　　"; SetColor(9, 15); cout << "□" << endl;	// 33
		cout << "□"; SetColor(0, 15); cout << "■■　　　■■■■■■■■■■■　　　□□□　　　■■"; SetColor(14, 15); cout << "■■■"; SetColor(0, 15); cout << "■■■■■"; SetColor(9, 15); cout << "□" << endl;	// 34
		cout << "□"; SetColor(0, 15); cout << "■■　　　　　　　　　　　　　　　　　　　　　　　　　"; SetColor(14, 15); cout << "　■　　　　　　"; SetColor(9, 15); cout << "□" << endl;	// 35
		cout << "■"; SetColor(0, 15); cout << "■■　　　　　　　　　　　　　　　　　　　　　　　　　"; SetColor(14, 15); cout << "■　■　　　　　"; SetColor(9, 15); cout << "■" << endl;	// 36
		cout << "■■□□□■■■□□□■■■□□□■■■□□□■■■□□□■■■□□□■■" << endl;	// 37
	}
	break;
	case 9:
	{
		cout << "■■□□□■■■□□□■■■□□□■■■□□□■■■□□□■■■□□□■■" << endl;	// 1
		cout << "■"; SetColor(0, 15); cout << "■■　　　　　　　　　　　　　　　　　　　　　　　■■　　　　　　　　"; SetColor(9, 15); cout << "■" << endl;	// 2
		cout << "□"; SetColor(0, 15); cout << "■■　　　　■■■■■■■　　　　　　　　　　　　■■■■■■■■　　"; SetColor(9, 15); cout << "□" << endl;	// 3
		cout << "□"; SetColor(0, 15); cout << "■■　　　■　　　　　　　■　　　　　　　　　　■　　　　　　　　■　"; SetColor(9, 15); cout << "□" << endl;	// 4
		cout << "□"; SetColor(0, 15); cout << "■■　　■　　　　　　　　　■　　　　　　　　■　　　　　　　　　　■"; SetColor(9, 15); cout << "□" << endl;	// 5
		cout << "■"; SetColor(0, 15); cout << "■■　■■■■■■■■■■■■■　　　　　　■■■■■■■■■■■■■"; SetColor(9, 15); cout << "■" << endl;	// 6
		cout << "■"; SetColor(0, 15); cout << "■■　　■　　　　　　　　　■　　　　　　　　■　　　　　　　　　　■"; SetColor(9, 15); cout << "■" << endl;	// 7
		cout << "■"; SetColor(0, 15); cout << "■■　　■　■■■　　　　　■　　　　　　　　■　■■■　　　　　　■"; SetColor(9, 15); cout << "■" << endl;	// 8
		cout << "□"; SetColor(0, 15); cout << "■■　　■　■　■　　■■　■　　　　　　　　■　■　■　　　　　　■"; SetColor(9, 15); cout << "□" << endl;	// 9
		cout << "□"; SetColor(0, 15); cout << "■■　　■　■　■　　"; SetColor(12, 15); cout << "　■　"; SetColor(0, 15); cout << "■　　　　　　　　■　■　■　　　　　　■"; SetColor(9, 15); cout << "□" << endl;	// 10
		cout << "□"; SetColor(0, 15); cout << "■■　　■■■■■■■"; SetColor(12, 15); cout << "■■■"; SetColor(0, 15); cout << "■　　　　　　　　■■■■■■■■■■■■"; SetColor(9, 15); cout << "□" << endl;	// 11
		cout << "■"; SetColor(0, 15); cout << "■■　　　　　　　　　"; SetColor(12, 15); cout << "　■　　　　　　　　　　　　　　　　　　　　　　"; SetColor(9, 15); cout << "■" << endl;	// 12
		cout << "■"; SetColor(0, 15); cout << "■■　　　　　　　　　"; SetColor(12, 15); cout << "■　■　　　　　　　　　　　　　　　　　　　　　"; SetColor(9, 15); cout << "■" << endl;	// 13
		cout << "■"; SetColor(0, 15); cout << "■■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　"; SetColor(9, 15); cout << "■" << endl;	// 14
		cout << "□"; SetColor(0, 15); cout << "■■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　"; SetColor(9, 15); cout << "□" << endl;	// 15
		cout << "□"; SetColor(0, 15); cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　"; SetColor(9, 15); cout << "□" << endl;	// 16
		cout << "□　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　"; SetColor(9, 15); cout << "□" << endl;	// 17
		cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　"; SetColor(9, 15); cout << "■" << endl;	// 18
		cout << "■　"; SetColor(14, 15); cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　"; SetColor(9, 15); cout << "■" << endl;	// 19
		cout << "■　"; SetColor(14, 15); cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　"; SetColor(9, 15); cout << "■" << endl;	// 20
		cout << "□　"; SetColor(14, 15); cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　"; SetColor(9, 15); cout << "□" << endl;	// 21
		cout << "□　"; SetColor(14, 15); cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　"; SetColor(9, 15); cout << "□" << endl;	// 22
		cout << "□　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　"; SetColor(9, 15); cout << "□" << endl;	// 23
		cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　"; SetColor(9, 15); cout << "■" << endl;	// 24
		cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　"; SetColor(9, 15); cout << "■" << endl;	// 25
		cout << "■"; SetColor(0, 15); cout << "■　　　　　　■■■■■■■　　　　　　　　　　　　　■■■■■■■　"; SetColor(9, 15); cout << "■" << endl;	// 26
		cout << "□"; SetColor(0, 15); cout << "■■　　　　■　　　　　　　■　　　　　　　　　　　■　　　　　　　■"; SetColor(9, 15); cout << "□" << endl;	// 27
		cout << "□"; SetColor(0, 15); cout << "■■　　　■　　　　　　　　　■　　　　　　　　　■　　　　　　　　　"; SetColor(9, 15); cout << "□" << endl;	// 28
		cout << "□"; SetColor(0, 15); cout << "■■　　■■■■■■■■■■■■■　　　　　　　■■■■■■■■■■■"; SetColor(9, 15); cout << "□" << endl;	// 29
		cout << "■"; SetColor(0, 15); cout << "■■　　　■　　　　　　　　　■　　　　　　　　　■　　　　　　　　　"; SetColor(9, 15); cout << "■" << endl;	// 30
		cout << "■"; SetColor(0, 15); cout << "■■　　　■　■■■　　　　　■　　　　　　　　　■　■■■　　　　　"; SetColor(9, 15); cout << "■" << endl;	// 31
		cout << "■"; SetColor(0, 15); cout << "■■　　　■　■　■　　　　　■　　　□□□　　　■　■　■　　■■　"; SetColor(9, 15); cout << "■" << endl;	// 32
		cout << "□"; SetColor(0, 15); cout << "■■　　　■　■　■　　　　　■　　　□□□　　　■　■　■　　　　　"; SetColor(9, 15); cout << "□" << endl;	// 33
		cout << "□"; SetColor(0, 15); cout << "■■　　　■■■■■■■■■■■　　　□□□　　　■■■■■■■■■■"; SetColor(9, 15); cout << "□" << endl;	// 34
		cout << "□"; SetColor(0, 15); cout << "■■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　"; SetColor(9, 15); cout << "□" << endl;	// 35
		cout << "■"; SetColor(0, 15); cout << "■■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　"; SetColor(9, 15); cout << "■" << endl;	// 36
		cout << "■■□□□■■■□□□■■■□□□■■■□□□■■■□□□■■■□□□■■" << endl;	// 37
	}
	break;
	}

}

void mainGame::Village2Choice()
{
	_key = '0';
	_key = _getch();

	if (_key == (char)DOWN)
	{
		switch (_village2check)
		{
		case 1:
		{
			_village2check = 5;
			Village2Screen();
			Village2Choice();
		}
		break;
		case 2:
		case 4:
		case 6:
		{
			_village2check = 7;
			Village2Screen();
			Village2Choice();
		}
		break;
		case 3:
		{
			_village2check = 8;
			Village2Screen();
			Village2Choice();
		}
		break;
		default:
		{
			Village2Choice();
		}
		break;
		}
	}
	else if (_key == (char)UP)
	{
		switch (_village2check)
		{
		case 2:
		case 3:
		case 4:
		case 5:
		{
			_village2check = 1;
			Village2Screen();
			Village2Choice();
		}
		break;
		case 6:
		{
			_village2check = 2;
			Village2Screen();
			Village2Choice();
		}
		break;
		case 7:
		{
			_village2check = 4;
			Village2Screen();
			Village2Choice();
		}
		break;
		case 8:
		{
			_village2check = 3;
			Village2Screen();
			Village2Choice();
		}
		break;
		default:
		{
			Village2Choice();
		}
		break;
		}
	}
	else if (_key == (char)LEFT)
	{
		switch (_village2check)
		{
		case 1:
		{
			_village2check = 4;
			Village2Screen();
			Village2Choice();
		}
		break;
		case 2:
		{
			_village2check = 6;
			Village2Screen();
			Village2Choice();
		}
		break;
		case 3:
		{
			_village2check = 1;
			Village2Screen();
			Village2Choice();
		}
		break;
		case 4:
		{
			_village2check = 2;
			Village2Screen();
			Village2Choice();
		}
		break;
		case 5:
		{
			_village2check = 7;
			Village2Screen();
			Village2Choice();
		}
		break;
		case 6:
		{
			_village2check = 2;
			Village2Screen();
			Village2Choice();
		}
		break;
		case 7:
		{
			_village2check = 6;
			Village2Screen();
			Village2Choice();
		}
		break;
		case 8:
		{
			_village2check = 5;
			Village2Screen();
			Village2Choice();
		}
		break;
		default:
		{
			Village2Choice();
		}
		break;
		}
	}
	else if (_key == (char)RIGHT)
	{
		switch (_village2check)
		{
		case 1:
		{
			_village2check = 3;
			Village2Screen();
			Village2Choice();
		}
		break;
		case 2:
		{
			_village2check = 4;
			Village2Screen();
			Village2Choice();
		}
		break;
		case 3:
		{
			_village2check = 8;
			Village2Screen();
			Village2Choice();
		}
		break;
		case 4:
		{
			_village2check = 1;
			Village2Screen();
			Village2Choice();
		}
		break;
		case 5:
		{
			_village2check = 8;
			Village2Screen();
			Village2Choice();
		}
		break;
		case 6:
		{
			_village2check = 7;
			Village2Screen();
			Village2Choice();
		}
		break;
		case 7:
		{
			_village2check = 5;
			Village2Screen();
			Village2Choice();
		}
		break;
		case 8:
		{
			_village2check = 3;
			Village2Screen();
			Village2Choice();
		}
		break;
		default:
		{
			Village2Choice();
		}
		break;
		}
	}
	else if (_key == (char)ENTER || _key == (char)SPACE)
	{
		switch (_village2check)
		{
		case 1:
		{
			_village2check = 0;
			_village1check = 3;
			_effect = Echicken;
			Village1Screen();
			Village1Choice();
		}
		break;
		case 2:
		{
			_village2check = 0;
			_storecheck = 1;
			_effect = Edooropen;
			Move2();

			StoreTopScreen();
			StoreChoiceScreen();
			StoreChoice();
		}
		break;
		case 3:
		{
			HouseEvent();
		}
		break;
		case 4:
		{
			gotoxy(0, 26);
			SetColor(13, 15);
			_effect = Econversation;

			cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;
			cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
			cout << "■"; SetColor(0, 15); cout << "　　[마을 아가씨]　　　　　　　　　　　  　　　　　　 　　　　　　　　"; SetColor(13, 15); cout << "■" << endl;
			cout << "■"; SetColor(0, 15); cout << "　　몇주 전부터 이상하게 감기가 안떨어져서 걱정이에요　　　　　　　　 "; SetColor(13, 15); cout << "■" << endl;
			cout << "■"; SetColor(0, 15); cout << "　　에..에..에취!! 어머 죄송합니다..　　　　　　　　　　　　　　　　　"; SetColor(13, 15); cout << "■" << endl;
			cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
			cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
			cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
			cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
			cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
			cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;

			while (true)
			{
				_key = '0';
				_key = _getch();

				if (_key == (char)ENTER || _key == (char)SPACE)
				{
					break;
				}
			}
			Village2Screen();
			Village2Choice();
		}
		break;
		case 5:
		{
			_effect = Econversation;
			_upgradecheck = 1;
			UpgradeChoiceScreen();
			VillageUpgradeChoice();

		}
		break;
		case 6:
		{
			_village2check = 9;
			Village2Screen();
			Sleep(1350);
			_village2check = 0;
			b_villageMusic = false;
			Move();
			_worldcheck = 3;
			b_worldmapMusic = true;
			WorldMapScreen();
			WorldMapChoice();
		}
		break;
		case 7:
		{
			gotoxy(0, 26);
			SetColor(13, 15);
			_effect = Econversation;

			cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;
			cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
			cout << "■"; SetColor(0, 15); cout << "　　[아타호]　　　　　　　　　　　  　　　　　　　　　　　　　　　　　"; SetColor(13, 15); cout << "■" << endl;
			cout << "■"; SetColor(0, 15); cout << "　　남의 집에 마음대로 들어가는건 실례지　　　　　　　　　　　　　　　"; SetColor(13, 15); cout << "■" << endl;
			cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
			cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
			cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
			cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
			cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
			cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
			cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;

			while (true)
			{
				_key = '0';
				_key = _getch();

				if (_key == (char)ENTER || _key == (char)SPACE)
				{
					break;
				}
			}
			Village2Screen();
			Village2Choice();
		}
		break;
		case 8:
		{
			_village2check = 0;
			_inncheck = 1;
			_effect = Edooropen;
			Move2();

			StoreTopScreen();
			InnChoiceScreen();
			InnChoice();
		}
		break;
		default:
		{
			Village2Choice();
		}
		break;
		}
	}
	else if (_key == (char)ESC)
	{
		_statuscheck = 1;
		Status();
	}
	else
	{
		Village2Choice();
	}
}

void mainGame::VillageUpgradeChoice()
{
	_key = '0';
	_key = _getch();

	if (_key == (char)DOWN)
	{
		switch (_upgradecheck)
		{
		case 1:
		{
			_upgradecheck = 2;
			UpgradeChoiceScreen();
			VillageUpgradeChoice();
		}
		break;
		case 2:
		{
			_upgradecheck = 3;
			UpgradeChoiceScreen();
			VillageUpgradeChoice();
		}
		break;
		case 4:
		{
			_upgradecheck = 5;
			UpgradeChoiceScreen();
			VillageUpgradeChoice();
		}
		break;
		default:
		{
			VillageUpgradeChoice();
		}
		break;
		}
	}
	else if (_key == (char)UP)
	{
		switch (_upgradecheck)
		{
		case 3:
		{
			_upgradecheck = 2;
			UpgradeChoiceScreen();
			VillageUpgradeChoice();
		}
		break;
		case 2:
		{
			_upgradecheck = 1;
			UpgradeChoiceScreen();
			VillageUpgradeChoice();
		}
		break;
		case 5:
		{
			_upgradecheck = 4;
			UpgradeChoiceScreen();
			VillageUpgradeChoice();
		}
		break;
		default:
		{
			VillageUpgradeChoice();
		}
		break;
		}
	}
	else if (_key == (char)ENTER || _key == (char)SPACE)
	{
		switch (_upgradecheck)
		{
		case 1:
		{
			_upgradecheck = 4;
			_effect = Econversation;
			UpgradeChoiceScreen();
			VillageUpgradeChoice();
		}
		break;
		case 2:
		{
			_village2check = 0;
			_upgradecheck = 0;
			_tempPlace = 2; // 2 = village

			_effect = EtempleEnter; // effectsound
			Move(); // black screen 1000ms
			b_villageMusic = false; // mainmusic off
			Sleep(500);
			IahEvent();
		}
		break;
		case 3:
		case 5:
		case 6:
		{
			_upgradecheck = 0;
			Village2Screen();
			Village2Choice();
		}
		break;
		case 4:
		{
			if (_characterMoney >= 100000)
			{
				_characterMoney = _characterMoney - 100000;

				_village2check = 0;
				_upgradecheck = 0;
				_tempPlace = 2;

				_effect = EtempleEnter; // effectsound
				Move(); // black screen 1000ms
				b_villageMusic = false; // mainmusic off
				Sleep(500);
				TempleEvent();
			}
			else
			{
				_upgradecheck = 6;
				UpgradeChoiceScreen();
				VillageUpgradeChoice();
			}
		}
		break;
		default:
		{
			VillageUpgradeChoice();
		}
		break;
		}
	}
	else
	{
		VillageUpgradeChoice();
	}
}

void mainGame::StoreTopScreen()
{
	gotoxy(0, 0);
	SetColor(9, 15);

	cout << "■■□□□■■■□□□■■■□□□■■■□□□■■■□□□■■■□□□■■" << endl;	// 1
	cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　"; SetColor(9, 15); cout << "■" << endl;	// 2
	cout << "□　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　"; SetColor(9, 15); cout << "□" << endl;	// 3
	cout << "□　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　"; SetColor(9, 15); cout << "□" << endl;	// 4
	cout << "□　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　"; SetColor(9, 15); cout << "□" << endl;	// 5
	cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　"; SetColor(9, 15); cout << "■" << endl;	// 6
	cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　"; SetColor(9, 15); cout << "■" << endl;	// 7
	cout << "■"; SetColor(0, 15); cout << "　　　　■■■■■■■　　　　　　　　　　　　　　　　　　　　　　　　"; SetColor(9, 15); cout << "■" << endl;	// 8
	cout << "□"; SetColor(0, 15); cout << "　　　　■　　　　　■　　　　　　　　　　　　　　　　　　　　　　　　"; SetColor(9, 15); cout << "□" << endl;	// 9
	cout << "□"; SetColor(0, 15); cout << "　　　　■　　　　　■　　　　　　　　　　　　　　　　　　　　　　　　"; SetColor(9, 15); cout << "□" << endl;	// 10
	cout << "□"; SetColor(0, 15); cout << "　　　　■　　　　　■　　　　　　　　　　　　　　　　　　　　　　　　"; SetColor(9, 15); cout << "□" << endl;	// 11
	cout << "■"; SetColor(0, 15); cout << "　　　　■　　　　　■　　"; SetColor(14, 15); cout << "　　■■■　　　　　　　　　　"; SetColor(13, 15); cout << "■■■　　　　"; SetColor(9, 15); cout << "■" << endl;	// 12
	cout << "■"; SetColor(0, 15); cout << "　　　　■　　　　　■　　"; SetColor(14, 15); cout << "　　■■■　　　　　　　　　　"; SetColor(13, 15); cout << "■■■　　　　"; SetColor(9, 15); cout << "■" << endl;	// 13
	cout << "■"; SetColor(0, 15); cout << "　　　　■　　　　　■　　"; SetColor(14, 15); cout << "　　■■■　　　　　　　　　　"; SetColor(13, 15); cout << "■■■　　　　"; SetColor(9, 15); cout << "■" << endl;	// 14
	cout << "□"; SetColor(0, 15); cout << "　　　　■　　　　■■　　"; SetColor(14, 15); cout << "■■■■■■■　　　　　　"; SetColor(13, 15); cout << "■■■■■■■　　"; SetColor(9, 15); cout << "□" << endl;	// 15
	cout << "□"; SetColor(0, 15); cout << "　　　　■　　　　　■　　"; SetColor(14, 15); cout << "■■■■■■■　　　"; SetColor(0, 15); cout << "■　■"; SetColor(13, 15); cout << "■■■■■■■　　"; SetColor(9, 15); cout << "□" << endl;	// 16
	cout << "□"; SetColor(0, 15); cout << "　　　　■　　　　　■　　"; SetColor(14, 15); cout << "■■■■■■■　　　"; SetColor(0, 15); cout << "■　■"; SetColor(13, 15); cout << "■■■■■■■　　"; SetColor(9, 15); cout << "□" << endl;	// 17
	cout << "■"; SetColor(0, 15); cout << "　　　　■　　　　　■　　　　"; SetColor(14, 15); cout << "■■■　　　　　"; SetColor(0, 15); cout << "■　■　　"; SetColor(13, 15); cout << "■■■　　　　"; SetColor(9, 15); cout << "■" << endl;	// 18
	cout << "■"; SetColor(0, 15); cout << "　　　　■　　　　　■　　　　"; SetColor(14, 15); cout << "■■■　　　　　"; SetColor(0, 15); cout << "■　■■■■■■■■■■"; SetColor(9, 15); cout << "■" << endl;	// 19
	cout << "■"; SetColor(0, 15); cout << "■■■■■■■■■■■■■■■"; SetColor(14, 15); cout << "■■■"; SetColor(0, 15); cout << "■■■■■"; SetColor(0, 15); cout << "■■■■■■■■■■■■"; SetColor(9, 15); cout << "■" << endl;	// 20
	cout << "□　　　　　　　　　　　　　　"; SetColor(14, 15); cout << "■■■■■　　　　"; SetColor(0, 15); cout << "■　　　　　　　　　　　"; SetColor(9, 15); cout << "□" << endl;	// 21
	cout << "□　　　　　　　　　　　　　"; SetColor(14, 15); cout << "■■■　■■■　　　"; SetColor(0, 15); cout << "■　　　　　　　　　　　"; SetColor(9, 15); cout << "□" << endl;	// 22
	cout << "□　　　　　　　　　　　　　　　　　　　　　　　"; SetColor(0, 15); cout << "■■■■■■■■■■■■"; SetColor(9, 15); cout << "□" << endl;	// 23
	cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　"; SetColor(9, 15); cout << "■" << endl;	// 24
	cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　"; SetColor(9, 15); cout << "■" << endl;	// 25
	cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　"; SetColor(9, 15); cout << "■" << endl;	// 26
	cout << "■■□□□■■■□□□■■■□□□■■■□□□■■■□□□■■■□□□■■" << endl;	// 27

	SetColor(8, 8);
	cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　" << endl;	// 28
	cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　" << endl;	// 29
	cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　" << endl;	// 30 
	cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　" << endl;	// 31 
	cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　" << endl;	// 32 
	cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　" << endl;	// 33 
	cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　" << endl;	// 34 
	cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　" << endl;	// 35 
	cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　" << endl;	// 36 
	cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　" << endl;	// 37
}

void mainGame::InnChoiceScreen()
{
	gotoxy(0, 27);
	SetColor(0, 8);

	switch (_inncheck)
	{
	case 1:
	{
		cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　" << endl;	// 28
		cout << "　　[여관주인]　　　　　　　　　　　　　　　　　　　　　　\n";	// 29
		cout << "　　따뜻한 방이 준비되있습니다~ 숙박하시겠습니까?　　　　\n"; //30
		cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　" << endl;	// 31
		cout << "　　숙박비 : 5,000\n"; // 32
		cout << "　　보유금액 : ";

		if (_characterMoney < 5000)
		{
			SetColor(12, 8);
		}

		cout << _characterMoney; SetColor(0, 8); cout << " 원　　　　\n"; // 31
		cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　" << endl;	// 31
		cout << "　　▶　쉬고가자\n"; // 33
		cout << "　　　　나가기\n"; // 34
		cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　" << endl;	// 35
	}
	break;
	case 2:
	{
		cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　" << endl;	// 28
		cout << "　　[여관주인]　　　　　　　　　　　　　　　　　　　　　　\n";	// 29
		cout << "　　따뜻한 방이 준비되있습니다~ 숙박하시겠습니까?　　　　\n"; //30
		cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　" << endl;	// 31
		cout << "　　숙박비 : 5,000\n"; // 32
		cout << "　　보유금액 : ";

		if (_characterMoney < 5000)
		{
			SetColor(12, 8);
		}

		cout << _characterMoney; SetColor(0, 8); cout << " 원　　　　\n"; // 31
		cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　" << endl;	// 31
		cout << "　　　　쉬고가자\n"; // 33
		cout << "　　▶　나가기\n"; // 34
		cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　" << endl;	// 35
	}
	break;
	}
}

void mainGame::InnChoice()
{
	_key = '0';
	_key = _getch();

	if (_key == (char)DOWN)
	{
		switch (_inncheck)
		{
		case 1:
		{
			_inncheck = 2;
			InnChoiceScreen();
			InnChoice();
		}
		break;
		default:
		{
			InnChoice();
		}
		break;
		}
	}
	else if (_key == (char)UP)
	{
		switch (_inncheck)
		{
		case 2:
		{
			_inncheck = 1;
			InnChoiceScreen();
			InnChoice();
		}
		break;
		default:
		{
			InnChoice();
		}
		break;
		}
	}
	else if (_key == (char)ENTER || _key == (char)SPACE)
	{
		switch (_inncheck)
		{
		case 1:
		{
			if (_characterMoney >= 5000)
			{
				b_villageMusic = false;
				_characterMoney = _characterMoney - 5000;
				SleepEvent();

				_inncheck = 0;
				_village2check = 8;
				b_villageMusic = true;
				Village2Screen();
				Village2Choice();
			}
			else
			{
				_effect = Eerror;
				InnChoice();
			}
		}
		break;
		case 2:
		{
			_inncheck = 0;
			_village2check = 8;
			_effect = Edooropen;
			Move2();
			Village2Screen();
			Village2Choice();
		}
		break;
		default:
		{
			InnChoice();
		}
		break;
		}
	}
	else
	{
		InnChoice();
	}
}

void mainGame::StoreChoiceScreen()
{
	gotoxy(0, 27);
	SetColor(0, 8);

	switch (_storecheck)
	{
	case 1:
	{
		cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　" << endl;	// 28
		cout << "　　[상인]　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　" << endl;	// 29
		cout << "　　어서오십셔 손님~　　　　　　　　　　　　　　　　　　　　　　　　　　　" << endl;	// 30
		cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　" << endl;	// 31
		cout << "　　▶　약　초 구매　가격 : 10,000　보유 개수 : " << hb->GetHowMany() << " 개　　\n"; // 32
		cout << "　　　　Hp포션 구매　가격 : 20,000　보유 개수 : " << po->GetHowMany() << " 개　　\n"; // 33
		cout << "　　　　약초씨 구매　가격 :  3,000　보유 개수 : " << _characterSeed << " 개　　\n"; // 34
		cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　" << endl;	// 35
		cout << "　　　　나가기　 보유금액 : ";
		if (_characterMoney < 10000)
		{
			SetColor(12, 8);
		}
		cout << _characterMoney; SetColor(0, 8); cout << " 원　　　　\n";
		cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　" << endl;	// 37
	}
	break;
	case 2:
	{
		cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　" << endl;	// 28
		cout << "　　[상인]　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　" << endl;	// 29
		cout << "　　어서오십셔 손님~　　　　　　　　　　　　　　　　　　　　　　　　　　　" << endl;	// 30
		cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　" << endl;	// 31
		cout << "　　　　약　초 구매　가격 : 10,000　보유 개수 : " << hb->GetHowMany() << " 개　　\n"; // 32
		cout << "　　▶　Hp포션 구매　가격 : 20,000　보유 개수 : " << po->GetHowMany() << " 개　　\n"; // 33
		cout << "　　　　약초씨 구매　가격 :  3,000　보유 개수 : " << _characterSeed << " 개　　\n"; // 34
		cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　" << endl;	// 35
		cout << "　　　　나가기　 보유금액 : ";
		if (_characterMoney < 20000)
		{
			SetColor(12, 8);
		}
		cout << _characterMoney; SetColor(0, 8); cout << " 원　　　　\n";
		cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　" << endl;	// 37
	}
	break;
	case 3:
	{
		cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　" << endl;	// 28
		cout << "　　[상인]　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　" << endl;	// 29
		cout << "　　어서오십셔 손님~　　　　　　　　　　　　　　　　　　　　　　　　　　　" << endl;	// 30
		cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　" << endl;	// 31
		cout << "　　　　약　초 구매　가격 : 10,000　보유 개수 : " << hb->GetHowMany() << " 개　　\n"; // 32
		cout << "　　　　Hp포션 구매　가격 : 20,000　보유 개수 : " << po->GetHowMany() << " 개　　\n"; // 33
		cout << "　　▶　약초씨 구매　가격 :  3,000　보유 개수 : " << _characterSeed << " 개　　\n"; // 34
		cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　" << endl;	// 35
		cout << "　　　　나가기　 보유금액 : ";
		if (_characterMoney < 3000)
		{
			SetColor(12, 8);
		}
		cout << _characterMoney; SetColor(0, 8); cout << " 원　　　　\n";
		cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　" << endl;	// 37
	}
	break;
	case 4:
	{
		cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　" << endl;	// 28
		cout << "　　[상인]　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　" << endl;	// 29
		cout << "　　어서오십셔 손님~　　　　　　　　　　　　　　　　　　　　　　　　　　　" << endl;	// 30
		cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　" << endl;	// 31
		cout << "　　　　약　초 구매　가격 : 10,000　보유 개수 : " << hb->GetHowMany() << " 개　　\n"; // 32
		cout << "　　　　Hp포션 구매　가격 : 20,000　보유 개수 : " << po->GetHowMany() << " 개　　\n"; // 33
		cout << "　　　　약초씨 구매　가격 :  3,000　보유 개수 : " << _characterSeed << " 개　　\n"; // 34
		cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　" << endl;	// 35
		cout << "　　▶　나가기　 보유금액 : " << _characterMoney << " 원　　　　\n";
		cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　" << endl;	// 37
	}
	break;

	}
}

void mainGame::StoreChoice()
{
	_key = '0';
	_key = _getch();

	if (_key == (char)DOWN)
	{
		switch (_storecheck)
		{
		case 1:
		{
			_storecheck = 2;
			StoreChoiceScreen();
			StoreChoice();
		}
		break;
		case 2:
		{
			_storecheck = 3;
			StoreChoiceScreen();
			StoreChoice();
		}
		break;
		case 3:
		{
			_storecheck = 4;
			StoreChoiceScreen();
			StoreChoice();
		}
		break;
		default:
		{
			StoreChoice();
		}
		break;
		}
	}
	else if (_key == (char)UP)
	{
		switch (_storecheck)
		{
		case 2:
		{
			_storecheck = 1;
			StoreChoiceScreen();
			StoreChoice();
		}
		break;
		case 3:
		{
			_storecheck = 2;
			StoreChoiceScreen();
			StoreChoice();
		}
		break;
		case 4:
		{
			_storecheck = 3;
			StoreChoiceScreen();
			StoreChoice();
		}
		break;
		default:
		{
			StoreChoice();
		}
		break;
		}
	}
	else if (_key == (char)ENTER || _key == (char)SPACE)
	{
		switch (_storecheck)
		{
		case 1:
		{
			if (_characterMoney >= 10000)
			{
				_characterMoney = _characterMoney - 10000;
				hb->SetHowMany(hb->GetHowMany() + 1);
				StoreChoiceScreen();
				StoreChoice();
			}
			else
			{
				_effect = Eerror;
				StoreChoice();
			}
		}
		break;
		case 2:
		{
			if (_characterMoney >= 20000)
			{
				_characterMoney = _characterMoney - 20000;
				po->SetHowMany(po->GetHowMany() + 1);
				StoreChoiceScreen();
				StoreChoice();
			}
			else
			{
				_effect = Eerror;
				StoreChoice();
			}
		}
		break;
		case 3:
		{
			if (_characterMoney >= 3000)
			{
				_characterMoney = _characterMoney - 3000;
				++_characterSeed;
				StoreChoiceScreen();
				StoreChoice();
			}
			else
			{
				_effect = Eerror;
				StoreChoice();
			}
		}
		break;
		case 4:
		{
			_storecheck = 0;
			_village2check = 2;
			_effect = Edooropen;
			Move2();

			Village2Screen();
			Village2Choice();
		}
		break;
		default:
		{
			StoreChoice();
		}
		break;
		}
	}
	else
	{
		StoreChoice();
	}
}

void mainGame::VillageEvent()
{
	if (b_villageEvent == false)
	{
		b_villageEvent = true;

		gotoxy(0, 0);
		SetColor(0, 15);

		cout << "■■■　　　　　■■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;	// 1
		cout << "■■■　　　　　"; SetColor(0, 15); cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;	// 2
		cout << "■■■　　　　　"; SetColor(0, 15); cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;	// 3
		cout << "■■■　"; SetColor(14, 15); cout << "　■　　"; SetColor(0, 15); cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;	// 4
		cout << "■■■　"; SetColor(14, 15); cout << "■■■　"; SetColor(0, 15); cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;	// 5
		cout << "■■■　"; SetColor(14, 15); cout << "　■　　"; SetColor(0, 15); cout << "□□□□□□□□□□□□□□□□□□□□□□□□□□□　　" << endl;	// 6
		cout << "■■■　"; SetColor(14, 15); cout << "■　■　"; SetColor(0, 15); cout << "□　　　　　　　　　　　　　　　　　　　　　　　　　□　　" << endl;	// 7
		cout << "■■■　　　　　□　　　　　　　　　　　　　　　　　　　　　　　　　□　　" << endl;	// 8
		cout << "■■■　　　　　□　　　　　　　　　　　　　"; SetColor(0, 15); cout << "　　　■■■■■■■　　□　　" << endl;	// 9
		cout << "■■■　　　　　□　　　　　　　　　　　　　"; SetColor(0, 15); cout << "　　■　　　　　　　■　□　　" << endl;	// 10
		cout << "■■■　　　　　□　　　　"; SetColor(12, 15); cout << "　　■　　　　　　"; SetColor(0, 15); cout << "　■■■■■■■■■■■□　　" << endl;	// 11
		cout << "■■■　　　　　□　　　　"; SetColor(12, 15); cout << "■■■　　　　　　"; SetColor(0, 15); cout << "　　■　　　　　　　■　□　　" << endl;	// 12
		cout << "■■■　　　　　□　　　　"; SetColor(12, 15); cout << "　■　　　　■　　"; SetColor(0, 15); cout << "　　■　　　　　　　■　□　　" << endl;	// 13
		cout << "■■■　　　　　□　　　　"; SetColor(12, 15); cout << "　　　　　　■■■"; SetColor(0, 15); cout << "　　■■■■■■■■■　□　　" << endl;	// 14
		cout << "■■■　　　　　□　　　　"; SetColor(12, 15); cout << "　　　　　　　■　"; SetColor(0, 15); cout << "　　　　　　　　　　　　□　　" << endl;	// 15
		cout << "■■■　　　　　□　　　　　　　　　　　　　　　　　　　　　　　　　□　　" << endl;	// 16
		cout << "■■■　　　　　□　　　　　"; SetColor(12, 15); cout << "　■　　　　　　　　　　　　　　　　　　"; SetColor(0, 15); cout << "□　　" << endl;	// 17
		cout << "■■■　　　　　□　　　　　"; SetColor(12, 15); cout << "　■■■　　　　　　　"; SetColor(12, 15); cout << "　　■　　　　　　"; SetColor(0, 15); cout << "□　　" << endl;	// 18
		cout << "■■■　　　　　□　　　　　"; SetColor(12, 15); cout << "　　■　"; SetColor(14, 15); cout << "　■　■　　　"; SetColor(12, 15); cout << "■■■　　　　　　"; SetColor(0, 15); cout << "□　　" << endl;	// 19
		cout << "■■■　　　　　□　　　　　　　　　"; SetColor(14, 15); cout << "■　　　　　　"; SetColor(12, 15); cout << "　■　　　　　　　"; SetColor(0, 15); cout << "□　　" << endl;	// 20
		cout << "■■■　　　　　□　　　　　　　　　"; SetColor(14, 15); cout << "　　■　■　　　　　　　　　　　"; SetColor(0, 15); cout << "□　　" << endl;	// 21
		cout << "■■■　　　　　□□□　　　□□□□□□□□□□□□□□□□□□□□□　　" << endl;	// 22
		cout << "■■■　　　　　　　　　　　　　　　　　"; SetColor(10, 15); cout << "　■　　　　　　　　　　　　　　　" << endl; SetColor(0, 15);	// 23
		cout << "■■■　　　　　　　　　　　　　　　　　"; SetColor(10, 15); cout << "■■■　　　　　　　　　　　　　　" << endl; SetColor(0, 15);	// 24
		cout << "■■■　　　　　　　　　　　　　　　　　"; SetColor(10, 15); cout << "　■　　　　　　　　　　　　　　　" << endl; SetColor(0, 15);	// 25
		cout << "■■■　　　　　　　　　　　　　　　　　"; SetColor(10, 15); cout << "■　■　　　"; SetColor(0, 15); cout << "■■　　　　　　　　　" << endl;	// 26
		cout << "■■■　　　　　　　　　　　　　　　　　　　　　　　■■　　　　　　　　　" << endl;	// 27
		cout << "■■■　　　　　　　　　　　　　　　　　　　　　　　■■　　　　　　　　　" << endl;	// 28
		cout << "■■■　　　　■■■■■■■　　　　　　　　　　　　■■■■■■■■　　　" << endl;	// 29
		cout << "■■■　　　■　　　　　　　■　　　　　　　　　　■　　　　　　　　■　　" << endl;	// 30
		cout << "■■■　　■　　　　　　　　　■　　　　　　　　■　　　　　　　　　　■　" << endl;	// 31
		cout << "■■■　■■■■■■■■■■■■■　　　　　　■■■■■■■■■■■■■■" << endl;	// 32
		cout << "■■■　　■　　　　　　　　　■　　　　　　　　■　　　　　　　　　　■　" << endl;	// 33
		cout << "■■■　　■　■■■　　　　　■　　　　　　　　■　■■■　　　　　　■　" << endl;	// 34
		cout << "■■■　　■　■　■　　■■　■　　　　　　　　■　■　■　　　　　　■　" << endl;	// 35
		cout << "■■■　　■　■　■　　　　　■　　　　　　　　■　■　■　　　　　　■　" << endl;	// 36
		cout << "■■■　　■■■■■■■■■■■　　　　　　　　■■■■■■■■■■■■　" << endl;	// 37


		_effect = Echicken;

		Sleep(1800);

		_effect = Econversation;

		gotoxy(0, 26);
		SetColor(13, 15);

		cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;
		cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
		cout << "■"; SetColor(0, 15); cout << "　　[아타호]　　　　　　　　　　　　  　　　　　　　　　　　　　　　　"; SetColor(13, 15); cout << "■" << endl;
		cout << "■"; SetColor(0, 15); cout << "　　이곳도 정말 오랜만이군! 호연의 집이 굴뚝이 있던 집이였던가　　　　"; SetColor(13, 15); cout << "■" << endl;
		cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
		cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
		cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
		cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
		cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
		cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
		cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;

		while (true)
		{
			_key = '0';
			_key = _getch();

			if (_key == (char)ENTER || _key == (char)SPACE)
			{
				break;
			}
		}

	}
}


void mainGame::HouseEvent()
{
	if (b_houseEvent == false)
	{
		_effect = Econversation;

		gotoxy(0, 26);
		SetColor(13, 15);

		cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;
		cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
		cout << "■"; SetColor(0, 15); cout << "　　[아타호]　　　　　　　　　　　　  　　　　　　　　　　　　　　　　"; SetColor(13, 15); cout << "■" << endl;
		cout << "■"; SetColor(0, 15); cout << "　　제대로 찾아왔구만 오랜 친구를 오랜만에 만나게 되니 괜히 설레는걸　"; SetColor(13, 15); cout << "■" << endl;
		cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
		cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
		cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
		cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
		cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
		cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
		cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;

		while (true)
		{
			_key = '0';
			_key = _getch();

			if (_key == (char)ENTER || _key == (char)SPACE)
			{
				break;
			}
		}

		HouseEventScreen();
		HouseEventChoice();
	}
	else
	{
		Village2Choice(); // already done next event. have to make
	}
}

void mainGame::HouseEventScreen()
{

	gotoxy(0, 26);
	SetColor(13, 15);

	switch (b_housecheck)
	{
	case 0:
	{
		cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;
		cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
		cout << "■"; SetColor(0, 15); cout << "　　[주의]　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　"; SetColor(13, 15); cout << "■" << endl;
		cout << "■"; SetColor(0, 15); cout << "　　입장하면 전투 이벤트가 시작됩니다. 입장하시겠습니까? 　 　　　　　"; SetColor(13, 15); cout << "■" << endl;
		cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
		cout << "■"; SetColor(0, 15); cout << "　　　　입장한다　　　　　　　　　　　　　　　　　　　　　　　　　　　"; SetColor(13, 15); cout << "■" << endl;
		cout << "■"; SetColor(0, 15); cout << "　　▶　나가기　　　　　　　　　　　　　　　　　　　　　　　　　　　　"; SetColor(13, 15); cout << "■" << endl;
		cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
		cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
		cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
		cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;
	}
	break;
	case 1:
	{
		cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;
		cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
		cout << "■"; SetColor(0, 15); cout << "　　[주의]　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　"; SetColor(13, 15); cout << "■" << endl;
		cout << "■"; SetColor(0, 15); cout << "　　입장하면 전투 이벤트가 시작됩니다. 입장하시겠습니까? 　 　　　　　"; SetColor(13, 15); cout << "■" << endl;
		cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
		cout << "■"; SetColor(0, 15); cout << "　　▶　입장한다　　　　　　　　　　　　　　　　　　　　　　　　　　　"; SetColor(13, 15); cout << "■" << endl;
		cout << "■"; SetColor(0, 15); cout << "　　　　나가기　　　　　　　　　　　　　　　　　　　　　　　　　　　　"; SetColor(13, 15); cout << "■" << endl;
		cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
		cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
		cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
		cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;
	}
	break;
	}

}

void mainGame::HouseEventChoice()
{
	_key = '0';
	_key = _getch();

	if (_key == (char)DOWN)
	{
		switch (b_housecheck)
		{
		case 0:
		{
			HouseEventChoice();
		}
		break;
		case 1:
		{
			b_housecheck = 0;
			HouseEventScreen();
			HouseEventChoice();
		}
		break;
		}
	}
	else if (_key == (char)UP)
	{
		switch (b_housecheck)
		{
		case 0:
		{
			b_housecheck = 1;
			HouseEventScreen();
			HouseEventChoice();
		}
		break;
		case 1:
		{
			HouseEventChoice();
		}
		break;
		}
	}
	else if (_key == (char)ENTER || _key == (char)SPACE)
	{
		switch (b_housecheck)
		{
		case 0:
		{
			Village2Screen();
			Village2Choice();
		}
		break;
		case 1:
		{
			b_houseEvent = true;
			HouseEvent2();
		}
		break;
		}
	}
	else
	{
		HouseEventChoice();
	}
}

void mainGame::HouseEvent2()
{
	gotoxy(0, 0);
	SetColor(0, 15);

	cout << "■■■　　　　　　　　　　　　　　　　　　　　　　　■■　　　　　　　　　" << endl;	// 1
	cout << "■■■　　　　　　　　　　　　　　　　　　　　　　　■■　　　　　　　　　" << endl;	// 2
	cout << "■■■　　　　■■■■■■■　　　　　　　　　　　　■■■■■■■■　　　" << endl;	// 3
	cout << "■■■　　　■　　　　　　　■　　　　　　　　　　■　　　　　　　　■　　" << endl;	// 4
	cout << "■■■　　■　　　　　　　　　■　　　　　　　　■　　　　　　　　　　■　" << endl;	// 5
	cout << "■■■　■■■■■■■■■■■■■　　　　　　■■■■■■■■■■■■■■" << endl;	// 6
	cout << "■■■　　■　　　　　　　　　■　　　　　　　　■　　　　　　　　　　■　" << endl;	// 7
	cout << "■■■　　■　■■■　　　　　■　　　　　　　　■　■■■　　　　　　■　" << endl;	// 8
	cout << "■■■　　■　■　■　　■■　■　　　　　　　　■　■　■　　　　　　■　" << endl;	// 9
	cout << "■■■　　■　■　■　　　"; SetColor(12, 15); cout << "■　"; SetColor(0, 15); cout << "■　　　　　　　　■　■　■　　　　　　■　" << endl; SetColor(0, 15);	// 10
	cout << "■■■　　■■■■■■■"; SetColor(12, 15); cout << "■■■"; SetColor(0, 15); cout << "■　　　　　　　　■■■"; SetColor(14, 15); cout << "■"; SetColor(0, 15); cout << "■■■■■■■■　" << endl; SetColor(0, 15);	// 11
	cout << "■■■　　　　　　　　　"; SetColor(12, 15); cout << "　■　　　　　　　　　　　　"; SetColor(14, 15); cout << "■■■　　　　　　　　" << endl; SetColor(0, 15);	// 12
	cout << "■■■　　　　　　　　　"; SetColor(12, 15); cout << "■　■　　　　　　　　　　　"; SetColor(14, 15); cout << "　■　　　　　　　　　" << endl; SetColor(0, 15);	// 13
	cout << "■■■　　　　　　　　　　　　　　　　　　　　　　　"; SetColor(14, 15); cout << "■　■　　　　　　　　" << endl; SetColor(0, 15);	// 14
	cout << "■■■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　" << endl;	// 15
	cout << "■■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　" << endl;	// 16
	cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　" << endl;	// 17
	cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　" << endl;	// 18
	cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　" << endl;	// 19
	cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　" << endl;	// 20
	cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　" << endl;	// 21
	cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　" << endl;	// 22
	cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　" << endl;	// 23
	cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　" << endl;	// 24
	cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　" << endl;	// 25
	cout << "■■　　　　　　■■■■■■■　　　　　　　　　　　　　■■■■■■■　　" << endl;	// 26
	cout << "■■■　　　　■　　　　　　　■　　　　　　　　　　　■　　　　　　　■　" << endl;	// 27
	cout << "■■■　　　■　　　　　　　　　■　　　　　　　　　■　　　　　　　　　■" << endl;	// 28
	cout << "■■■　　■■■■■■■■■■■■■　　　　　　　■■■■■■■■■■■■" << endl;	// 29
	cout << "■■■　　　■　　　　　　　　　■　　　　　　　　　■　　　　　　　　　■" << endl;	// 30
	cout << "■■■　　　■　■■■　　　　　■　　　　　　　　　■　■■■　　　　　■" << endl;	// 31
	cout << "■■■　　　■　■　■　　　　　■　　　□□□　　　■　■　■　　■■　■" << endl;	// 32
	cout << "■■■　　　■　■　■　　　　　■　　　□□□　　　■　■　■　　　　　■" << endl;	// 33
	cout << "■■■　　　■■■■■■■■■■■　　　□□□　　　■■■■■■■■■■■" << endl;	// 34
	cout << "■■■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　" << endl;	// 35
	cout << "■■■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　" << endl;	// 36
	cout << "■■■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　" << endl;	// 37

	Sleep(1500);
	_effect = Edooropen;
	Move();

	HouseScreen();

	Sleep(1500);

	///////////////////////
	gotoxy(0, 26);
	SetColor(13, 15);

	cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;
	cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
	cout << "■"; SetColor(0, 15); cout << "　　[아타호]　　　　　　　　　　　　　　　　　　　　　　　　　　　　　"; SetColor(13, 15); cout << "■" << endl;
	cout << "■"; SetColor(0, 15); cout << "　　호연! 집에 있었군 정말 오랜만일세!　　　　　　　　　 　 　　　　　"; SetColor(13, 15); cout << "■" << endl;
	cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
	cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
	cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
	cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
	cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
	cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
	cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;

	Conversation();

	HouseScreen();
	Sleep(800);
	///////////////////////
	gotoxy(0, 26);
	SetColor(13, 15);

	cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;
	cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
	cout << "■"; SetColor(0, 15); cout << "　　[호연]　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　"; SetColor(13, 15); cout << "■" << endl;
	cout << "■"; SetColor(0, 15); cout << "　　오 아타호 왔는가! 정말로 오랜만이로구만 하하　　  　 　 　　　　　"; SetColor(13, 15); cout << "■" << endl;
	cout << "■"; SetColor(0, 15); cout << "　　자네는 예전과 달라진게 없어보이는군 　　　　　　　　　　　　　　　"; SetColor(13, 15); cout << "■" << endl;
	cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
	cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
	cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
	cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
	cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
	cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;

	Conversation();

	HouseScreen();
	Sleep(800);
	///////////////////////
	gotoxy(0, 26);
	SetColor(13, 15);

	cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;
	cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
	cout << "■"; SetColor(0, 15); cout << "　　[아타호]　　　　　　　　　　　　　　　　　　　　　　　　　　　　　"; SetColor(13, 15); cout << "■" << endl;
	cout << "■"; SetColor(0, 15); cout << "　　허허 이 친구 넉살이야말로 변함없구만　 　　　　   　 　 　　　　　"; SetColor(13, 15); cout << "■" << endl;
	cout << "■"; SetColor(0, 15); cout << "　　세월은 어떻게 해도 못속인다네　　　 　　　　　　　　　　　　　　　"; SetColor(13, 15); cout << "■" << endl;
	cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
	cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
	cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
	cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
	cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
	cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;

	Conversation();

	HouseScreen();
	Sleep(800);
	///////////////////////
	gotoxy(0, 26);
	SetColor(13, 15);

	cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;
	cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
	cout << "■"; SetColor(0, 15); cout << "　　[호연]　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　"; SetColor(13, 15); cout << "■" << endl;
	cout << "■"; SetColor(0, 15); cout << "　　하하　그런가 그나저나 내 편지를 보고 왔을터　 　  　 　 　　　　　"; SetColor(13, 15); cout << "■" << endl;
	cout << "■"; SetColor(0, 15); cout << "　　자네 혹시 여기까지 오면서 이상한 점 없었나　　　　　　　　　　　　"; SetColor(13, 15); cout << "■" << endl;
	cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
	cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
	cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
	cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
	cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
	cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;

	Conversation();

	HouseScreen();
	Sleep(800);
	///////////////////////
	gotoxy(0, 26);
	SetColor(13, 15);

	cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;
	cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
	cout << "■"; SetColor(0, 15); cout << "　　[아타호]　　　　　　　　　　　　　　　　　　　　　　　　　　　　　"; SetColor(13, 15); cout << "■" << endl;
	cout << "■"; SetColor(0, 15); cout << "　　음 산짐승들이 평소와 다르게 날뛰어서 오는데 힘이 좀 들긴 했네만 　"; SetColor(13, 15); cout << "■" << endl;
	cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
	cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
	cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
	cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
	cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
	cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
	cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;

	Conversation();

	HouseScreen();
	Sleep(800);
	///////////////////////
	gotoxy(0, 26);
	SetColor(13, 15);

	cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;
	cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
	cout << "■"; SetColor(0, 15); cout << "　　[호연]　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　"; SetColor(13, 15); cout << "■" << endl;
	cout << "■"; SetColor(0, 15); cout << "　　바로 그걸세! 문제는 산짐승뿐만이 아니라네　　　　　　　　　　　　 "; SetColor(13, 15); cout << "■" << endl;
	cout << "■"; SetColor(0, 15); cout << "　　주위의 모든 생명체가 알수없는 이유로 포악해지고 있다네　　　　　　"; SetColor(13, 15); cout << "■" << endl;
	cout << "■"; SetColor(0, 15); cout << "　　집에서 기르는 온순한 가축마저 날뛰는데다가 더 심각한건 최근에는.. "; SetColor(13, 15); cout << "■" << endl;
	cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
	cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
	cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
	cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
	cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;

	Conversation();

	b_villageMusic = false;
	HouseScreen();
	Sleep(1500);
	///////////////////////

	_effect = Escream;

	Sleep(1800);

	gotoxy(0, 26);
	SetColor(13, 15);

	cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;
	cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
	cout << "■"; SetColor(0, 15); cout << "　　[아타호]　　　　　　　　　　　　　　　　　　　　　　　　　　　　　"; SetColor(13, 15); cout << "■" << endl;
	cout << "■"; SetColor(0, 15); cout << "　　아니 이게 갑자기 무슨 비명소리인가 　　　　　 　  　 　 　　　　　"; SetColor(13, 15); cout << "■" << endl;
	cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
	cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
	cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
	cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
	cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
	cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
	cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;

	Conversation();

	_effect = Edooropen;
	Move2();

	VillageBattle1Screen();

	Sleep(1800);

	gotoxy(0, 26);
	SetColor(13, 15);

	cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;
	cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
	cout << "■"; SetColor(0, 15); cout << "　　[아타호]　　　　　　　　　　　　　　　　　　　　　　　　　　　　　"; SetColor(13, 15); cout << "■" << endl;
	cout << "■"; SetColor(0, 15); cout << "　　이게 무슨일인가! 왜 마을 사람들이..　　　　　 　  　 　 　　　　　"; SetColor(13, 15); cout << "■" << endl;
	cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
	cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
	cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
	cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
	cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
	cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
	cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;

	Conversation();

	gotoxy(0, 26);
	SetColor(13, 15);

	cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;
	cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
	cout << "■"; SetColor(0, 15); cout << "　　[호연]　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　"; SetColor(13, 15); cout << "■" << endl;
	cout << "■"; SetColor(0, 15); cout << "　　설마!! 가까이 가지말게 아타호! 　　　　　　　 　  　 　 　　　　　"; SetColor(13, 15); cout << "■" << endl;
	cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
	cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
	cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
	cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
	cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
	cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
	cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;

	Conversation();

	VillageBattle1Screen();
	Sleep(1500);
	_effect = Ecrazy;

	Sleep(2400);

	VillageBattle2Screen();
	Sleep(2000);
	_effect = Ecrazy;

	Sleep(1800);

	SetColor(15, 15);
	BootScreen2();
	Sleep(270);

	VillageBattle2Screen();
	Sleep(270);

	SetColor(15, 15);
	BootScreen2();
	Sleep(270);

	VillageBattle3Screen();
	Sleep(1500);
	b_villagebattleMusic = true;
	Sleep(1800);

	///////////////////////
	gotoxy(0, 26);
	SetColor(13, 15);

	cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;
	cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
	cout << "■"; SetColor(0, 15); cout << "　　[호연]　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　"; SetColor(13, 15); cout << "■" << endl;
	cout << "■"; SetColor(0, 15); cout << "　　완전히 포위당해버렸군!!　　　　　　　　　　　 　  　 　 　　　　　"; SetColor(13, 15); cout << "■" << endl;
	cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
	cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
	cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
	cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
	cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
	cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
	cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;

	Conversation();

	VillageBattle3Screen();
	Sleep(1200);


	_effect = Eblade;
	VillageBattle4Screen();
	Sleep(350);

	///////////////////////
	gotoxy(0, 26);
	SetColor(13, 15);

	cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;
	cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
	cout << "■"; SetColor(0, 15); cout << "　　[아타호]　　　　　　　　　　　　　　　　　　　　　　　　　　　　　"; SetColor(13, 15); cout << "■" << endl;
	cout << "■"; SetColor(0, 15); cout << "　　이게 대체 무슨일인가!!　　　　　　　 　　　　 　  　 　 　　　　　"; SetColor(13, 15); cout << "■" << endl;
	cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
	cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
	cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
	cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
	cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
	cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
	cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;

	Conversation();

	VillageBattle4Screen();
	Sleep(1500);


	gotoxy(0, 26);
	SetColor(13, 15);

	cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;
	cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
	cout << "■"; SetColor(0, 15); cout << "　　[호연]　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　"; SetColor(13, 15); cout << "■" << endl;
	cout << "■"; SetColor(0, 15); cout << "　　설명은 나중에 할테니 지금은 이들을 제압해야되네!　　　　　　　 　 "; SetColor(13, 15); cout << "■" << endl;
	cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
	cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
	cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
	cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
	cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
	cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
	cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;

	Conversation();

	VillageBattle4Screen();
	Sleep(1500);

	gotoxy(0, 26);
	SetColor(13, 15);

	cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;
	cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
	cout << "■"; SetColor(0, 15); cout << "　　[아타호]　　　　　　　　　　　　　　　　　　　　　　　　　　　　　"; SetColor(13, 15); cout << "■" << endl;
	cout << "■"; SetColor(0, 15); cout << "　　심상치 않은 일인것은 분명하군!! 　　　　　　　 　　　　 　  　 　 "; SetColor(13, 15); cout << "■" << endl;
	cout << "■"; SetColor(0, 15); cout << "　　알았네 나는 이쪽을 맡을테니 그쪽을 부탁하네!!　　　　　　　　　　 "; SetColor(13, 15); cout << "■" << endl;
	cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
	cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
	cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
	cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
	cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
	cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;

	Conversation();

	VillageBattle4Screen();
	Sleep(1350);

	gotoxy(0, 26);
	SetColor(13, 15);

	cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;
	cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
	cout << "■"; SetColor(0, 15); cout << "　　[호연]　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　"; SetColor(13, 15); cout << "■" << endl;
	cout << "■"; SetColor(0, 15); cout << "　　걱정말게 아직 이 호연 죽지 않았네 　　　　　　 　　　　 　  　 　 "; SetColor(13, 15); cout << "■" << endl;
	cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
	cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
	cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
	cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
	cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
	cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
	cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;

	Conversation();

	VillageBattle4Screen();
	Sleep(1500);

	gotoxy(0, 26);
	SetColor(13, 15);

	cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;
	cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
	cout << "■"; SetColor(0, 15); cout << "　　[아타호]　　　　　　　　　　　　　　　　　　　　　　　　　　　　　"; SetColor(13, 15); cout << "■" << endl;
	cout << "■"; SetColor(0, 15); cout << "　　이런 상황에 농담이라니 정말로 변한게 없구만 　 　　　　 　  　 　 "; SetColor(13, 15); cout << "■" << endl;
	cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
	cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
	cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
	cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
	cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
	cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
	cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;

	Conversation();

	VillageBattle4Screen();
	Sleep(1300);

	gotoxy(0, 26);
	SetColor(13, 15);

	cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;
	cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
	cout << "■"; SetColor(0, 15); cout << "　　[호연]　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　"; SetColor(13, 15); cout << "■" << endl;
	cout << "■"; SetColor(0, 15); cout << "　　하하 한두번인가 그래도 저들의 움직임이 심상치 않으니 조심하게  　 "; SetColor(13, 15); cout << "■" << endl;
	cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
	cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
	cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
	cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
	cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
	cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
	cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;

	Conversation();

	VillageBattle4Screen();
	Sleep(1300);

	gotoxy(0, 26);
	SetColor(13, 15);

	cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;
	cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
	cout << "■"; SetColor(0, 15); cout << "　　[아타호]　　　　　　　　　　　　　　　　　　　　　　　　　　　　　"; SetColor(13, 15); cout << "■" << endl;
	cout << "■"; SetColor(0, 15); cout << "　　맡겨두게　　　　　　　　　　　　　　　　　　　　　　　　　　　　  "; SetColor(13, 15); cout << "■" << endl;
	cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
	cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
	cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
	cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
	cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
	cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
	cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;

	Conversation();

	_effect = Ebattleenter;

	SetColor(15, 15);
	BootScreen2();
	Sleep(130);

	VillageBattle4Screen();
	Sleep(130);

	SetColor(15, 15);
	BootScreen2();
	Sleep(130);

	VillageBattle4Screen();
	Sleep(1250);

	VillageBattle1Init();

	if (_characterHp == 0)
	{
		b_villagebattleMusic = false;
		GameOver();
		return;
	}
	else
	{
		HouseEvent3();
	}
}



void mainGame::VillageBattle1Init()
{
	_skillTemp = 0;
	_skillcheck = 1;
	_monster1statecheck = 1;
	_charactercheck = 1;
	_monster2statecheck = 1;
	_battlecheck = 1;

	b_battleMusic = true;

	SetColor(15, 15);
	BootScreen2();
	gotoxy(0, 26);
	SetColor(9, 15);
	cout << "■■□□□■■■□□□■■■□□□■■■□□□■■■□□□■■■□□□■■" << endl;	// 27
	SetColor(8, 8);
	cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　" << endl;	// 32 
	cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　" << endl;	// 32
	cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　" << endl;	// 32 
	cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　" << endl;	// 32 
	cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　" << endl;	// 32 
	cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　" << endl;	// 32 
	cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　" << endl;	// 32 
	cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　" << endl;	// 32 
	cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　" << endl;	// 32 
	cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　" << endl;	// 32

	_human1 = new human1;
	_human2 = new human2;

	monsterBase* _mob1 = _human1;
	monsterBase* _mob2 = _human2;

	BattleScreen(_mob1, _mob2);
	BattleChoice(_mob1, _mob2);

	delete _human1;
	delete _human2;
}

void mainGame::HouseScreen()
{
	gotoxy(0, 0);
	SetColor(0, 15);

	cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;	// 1
	cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;	// 2
	cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;	// 3
	cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;	// 4
	cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;	// 5
	cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;	// 6
	cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;	// 7
	cout << "■　　　　■■■■■■■　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;	// 8
	cout << "■　　　　■　　　　　■　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;	// 9
	cout << "■　　　　■　　　　　■　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;	// 10
	cout << "■　　　　■　　　　　■　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;	// 11
	cout << "■　　　　■　　　　　■　　　　　"; SetColor(14, 15); cout << "　　■■■　　　　　"; SetColor(11, 15); cout << "　　■■■　　　　"; SetColor(0, 15); cout << "■" << endl; SetColor(0, 15);	// 12
	cout << "■　　　　■　　　　　■　　　　　"; SetColor(14, 15); cout << "　　■■■　　　　　"; SetColor(11, 15); cout << "　　■■■　　　　"; SetColor(0, 15); cout << "■" << endl; SetColor(0, 15);	// 13
	cout << "■　　　　■　　　　　■　　　　　"; SetColor(14, 15); cout << "　　■■■　　　　　"; SetColor(11, 15); cout << "　　■■■　　　　"; SetColor(0, 15); cout << "■" << endl; SetColor(0, 15);	// 14
	cout << "■　　　　■　　　　■■　　　　　"; SetColor(14, 15); cout << "■■■■■■■　　　"; SetColor(11, 15); cout << "■■■■■■■　　"; SetColor(0, 15); cout << "■" << endl; SetColor(0, 15);	// 15
	cout << "■　　　　■　　　　　■　　　　　"; SetColor(14, 15); cout << "■■■■■■■　　　"; SetColor(11, 15); cout << "■■■■■■■　　"; SetColor(0, 15); cout << "■" << endl; SetColor(0, 15);	// 16
	cout << "■　　　　■　　　　　■　　　　　"; SetColor(14, 15); cout << "■■■■■■■　　　"; SetColor(11, 15); cout << "■■■■■■■　　"; SetColor(0, 15); cout << "■" << endl; SetColor(0, 15);	// 17
	cout << "■　　　　■　　　　　■　　　　　"; SetColor(14, 15); cout << "　　■■■　　　　　"; SetColor(11, 15); cout << "　　■■■　　　　"; SetColor(0, 15); cout << "■" << endl; SetColor(0, 15);	// 18
	cout << "■　　　　■　　　　　■　　　　　"; SetColor(14, 15); cout << "　　■■■　　　　　　　"; SetColor(11, 15); cout << "■■■　　　　"; SetColor(0, 15); cout << "■" << endl; SetColor(0, 15);	// 19
	cout << "■■■■■■■■■■■■■■■■■■■"; SetColor(14, 15); cout << "■■■"; SetColor(0, 15); cout << "■■■■■■■"; SetColor(11, 15); cout << "■■■"; SetColor(0, 15); cout << "■■■■■" << endl; SetColor(0, 7);	// 20
	cout << "■　　　　　　　　　　　　　　　　　"; SetColor(14, 7); cout << "■■■■■　　　　　"; SetColor(11, 7); cout << "■■■■■　　　"; SetColor(0, 15); cout << "■" << endl; SetColor(0, 7);	// 21
	cout << "■　　　　　　　　　　　　　　　　"; SetColor(14, 7); cout << "■■■　■■■　　　"; SetColor(11, 7); cout << "■■■　■■■　　"; SetColor(0, 15); cout << "■" << endl; SetColor(0, 7);	// 22
	cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;	// 23
	cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;	// 24
	cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;	// 25
	cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;	// 26
	cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;	// 27
	cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;	// 28
	cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;	// 29
	cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;	// 30
	cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;	// 31
	cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;	// 32
	cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;	// 33
	cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;	// 34
	cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;	// 35
	cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;	// 36
	cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;	// 37

}

void mainGame::VillageBattle1Screen()
{
	gotoxy(0, 0);
	SetColor(0, 15);

	cout << "■■■　　　　　　　　　　　　　　　　　　　　　　　■■　　　　　　　　　" << endl;	// 1
	cout << "■■■　　　　　　　　　　　　　　　　　　　　　　　■■　　　　　　　　　" << endl;	// 2
	cout << "■■■　　　　■■■■■■■　　　　　　　　　　　　■■■■■■■■　　　" << endl;	// 3
	cout << "■■■　　　■　　　　　　　■　　　　　　　　　　■　　　　　　　　■　　" << endl;	// 4
	cout << "■■■　　■　　　　　　　　　■　　　　　　　　■　　　　　　　　　　■　" << endl;	// 5
	cout << "■■■　■■■■■■■■■■■■■　　　　　　■■■■■■■■■■■■■■" << endl;	// 6
	cout << "■■■　　■　　　　　　　　　■　　　　　　　　■　　　　　　　　　　■　" << endl;	// 7
	cout << "■■■　　■　■■■　　　　　■　　　　　　　　■　■■■　　　　　　■　" << endl;	// 8
	cout << "■■■　　■　■　■　　■■　■　　　　　　　　■　■　■　　　　　　■　" << endl;	// 9
	cout << "■■■　　■　■　■　　　　　■　　　　　　　　■　■　■　　　　　　■　" << endl;	// 10
	cout << "■■■　　■■■■■■■■■■■　　　　　　　　■■■■■■■■■■■■　" << endl;	// 11
	cout << "■■■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　" << endl;	// 12
	cout << "■■■　　　　　　　　　　　　　　　　　　　"; SetColor(14, 15); cout << "　■　　"; SetColor(11, 15); cout << "　■　　　　　　　　　" << endl; SetColor(0, 15);	// 13
	cout << "■■■　　　　　　　　　　　　　　　　　　　"; SetColor(14, 15); cout << "■■■　"; SetColor(11, 15); cout << "■■■　　　　　　　　" << endl; SetColor(0, 15);	// 14
	cout << "■■■　　　　　　　　　　　　　　　　　　　"; SetColor(14, 15); cout << "　■　　"; SetColor(11, 15); cout << "　■　　　　　　　　　" << endl; SetColor(0, 15);	// 15
	cout << "■■　　　　　　　　　　■　　　　　　　　　"; SetColor(14, 15); cout << "■　■　"; SetColor(11, 15); cout << "■　■　　　　　　　　" << endl; SetColor(0, 15);	// 16
	cout << "■　　　　　　　■　　■■■　　　　　　　　　　　　　　　　　　　　　　　" << endl;	// 17
	cout << "　"; SetColor(13, 15); cout << "　■　■　　"; SetColor(0, 15); cout << "■■■　　■　　　　　　　　　　　　　　　　　　　　　　　　" << endl; SetColor(0, 15);	// 18
	cout << "　"; SetColor(13, 15); cout << "■■■　　　"; SetColor(0, 15); cout << "　■　　■　■　　　　　　　　　　　　　　　　　　　　　　　" << endl; SetColor(0, 15);	// 19
	cout << "　"; SetColor(13, 15); cout << "　■　■　　"; SetColor(0, 15); cout << "■　■　　　　　　　　　　　　　　　　　　　　　　　　　　　" << endl; SetColor(0, 15);	// 20
	cout << "　　　　　　　　　　　　　■　　　　　　　　　　　　　　　　　　　　　　　" << endl; SetColor(0, 15);	// 21
	cout << "　　　　　　　　■　　　■■■　　　　　　　　　　　　　　　　　　　■　　" << endl; SetColor(0, 15);	// 22
	cout << "　　"; SetColor(12, 15); cout << "　　■　■"; SetColor(0, 15); cout << "■■■　　　■　　　　　　　　　　　　　　■　　　　■■■　" << endl; SetColor(0, 15);	// 23
	cout << "　　"; SetColor(12, 15); cout << "　■■■　"; SetColor(0, 15); cout << "　■　　　■　■　　　　　　　　　　　　■■■　　　　■　　" << endl; SetColor(0, 15);	// 24
	cout << "■　"; SetColor(12, 15); cout << "　　■　■"; SetColor(0, 15); cout << "■　■　　　　　　　　　　　　　　　　　　■　　　　■　■　" << endl; SetColor(0, 15);	// 25
	cout << "■■　　　　　　■■■■■■■　　　　　　　　　　　　　■■■■■■■　　" << endl; SetColor(0, 15);	// 26
	cout << "■■■　　　　■　　　　　　　■　　　　　　　　　　　■　　　　　　　■　" << endl; SetColor(0, 15);	// 27
	cout << "■■■　　　■　　　　　　　　　■　　　　　　　　　■　　　　　　　　　■" << endl;	// 28
	cout << "■■■　　■■■■■■■■■■■■■　　　　　　　■■■■■■■■■■■■" << endl;	// 29
	cout << "■■■　　　■　　　　　　　　　■　　　　　　　　　■　　　　　　　　　■" << endl;	// 30
	cout << "■■■　　　■　■■■　　　　　■　　　　　　　　　■　■■■　　　　　■" << endl;	// 31
	cout << "■■■　　　■　■　■　　　　　■　　　□□□　　　■　■　■　　■■　■" << endl;	// 32
	cout << "■■■　　　■　■　■　　　　　■　　　□□□　　　■　■　■　　　　　■" << endl;	// 33
	cout << "■■■　　　■■■■■■■■■■■　　　□□□　　　■■■■■■■■■■■" << endl;	// 34
	cout << "■■■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　" << endl;	// 35
	cout << "■■■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　" << endl;	// 36
	cout << "■■■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　" << endl;	// 37
}

void mainGame::VillageBattle2Screen()
{

	gotoxy(0, 0);
	SetColor(0, 15);

	cout << "■■■　　　　　　　　　　　　　　　　　　　　　　　■■　　　　　　　　　" << endl; SetColor(0, 15);	// 1
	cout << "■■■　　　　　　　　　　　　　　　　　　　　　　　■■　　　　　　　　　" << endl; SetColor(0, 15);	// 2
	cout << "■■■　　　　■■■■■■■　　　　　　　　　　　　■■■■■■■■　　　" << endl; SetColor(0, 15);	// 3
	cout << "■■■　　　■　　　　　　　■　　　　　　　　　　■　　　　　　　　■　　" << endl; SetColor(0, 15);	// 4
	cout << "■■■　　■　　　　　　　　　■　　　　　　　　■　　　　　　　　　　■　" << endl; SetColor(0, 15);	// 5
	cout << "■■■　■■■■■■■■■■■■■　　　　　　■■■■■■■■■■■■■■" << endl; SetColor(0, 15);	// 6
	cout << "■■■　　■　　　　　　　　　■　　　　　　　　■　　　　　　　　　　■　" << endl; SetColor(0, 15);	// 7
	cout << "■■■　　■　■■■　　　　　■　　　　　　　　■　■■■　　　　　　■　" << endl; SetColor(0, 15);	// 8
	cout << "■■■　　■　■　■　　■■　■　　　　　　　　■　■　■　　　　　　■　" << endl; SetColor(0, 15);	// 9
	cout << "■■■　　■　■　■　　　　　■　　　　　　　　■　■　■　　　　　　■　" << endl; SetColor(0, 15);	// 10
	cout << "■■■　　■■■■■■■■■■■　　　　　　　　■■■■■■■■■■■■　" << endl; SetColor(0, 15);	// 11
	cout << "■■■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　" << endl; SetColor(0, 15);	// 12
	cout << "■■■　　　　　　　　　　　　　　　　　　　"; SetColor(14, 15); cout << "　■　　"; SetColor(11, 15); cout << "　■　　　　　　　　　" << endl; SetColor(0, 15);	// 13
	cout << "■■■　　　　　　　　　　　　　　　　　　　"; SetColor(14, 15); cout << "■■■　"; SetColor(11, 15); cout << "■■■　　　　　　　　" << endl; SetColor(0, 15);	// 14
	cout << "■■■　　　　　　　　　　　　　　　　　　　"; SetColor(14, 15); cout << "　■　　"; SetColor(11, 15); cout << "　■　　　"; SetColor(0, 15); cout << "　　　■　　" << endl; SetColor(0, 15);	// 15
	cout << "■■　　　　　　　　　　　　■　　　　　　　"; SetColor(14, 15); cout << "■　■　"; SetColor(11, 15); cout << "■　■　　"; SetColor(0, 15); cout << "　　■■■　" << endl; SetColor(0, 15);	// 16
	cout << "■　　　　　　　　■　　　■■■　　　　　　　　　　　　　　　　　　■　　" << endl; SetColor(0, 15);	// 17
	cout << "　"; SetColor(13, 15); cout << "　■　■　　　"; SetColor(0, 15); cout << "■■■　　　■　　　　　　　　　　　　　　　　　　■　■　" << endl; SetColor(0, 15);	// 18
	cout << "　"; SetColor(13, 15); cout << "■■■　　　　"; SetColor(0, 15); cout << "　■　　　■　■　　　　　　　　　　　　　　　　　　　　　" << endl; SetColor(0, 15);	// 19
	cout << "　"; SetColor(13, 15); cout << "　■　■　　　"; SetColor(0, 15); cout << "■　■　　　　　　　■　　　　　　　　■　　　　■　　　　" << endl; SetColor(0, 15);	 // 20
	cout << "　　　　　　　　　　　　　　　　　■■■　　　　　　■■■　　■■■　　　" << endl; SetColor(0, 15);	// 21
	cout << "　　　　　　　　　　　■　　　　　　■　　　　　　　　■　　　　■　　　　" << endl; SetColor(0, 15);	// 22
	cout << "　　"; SetColor(12, 15); cout << "　　■　■　　"; SetColor(0, 15); cout << "　■■■　　　　■　■　　　　　　■　■　　■　■　　　" << endl; SetColor(0, 15);	// 23
	cout << "　　"; SetColor(12, 15); cout << "　■■■　　　"; SetColor(0, 15); cout << "　　■　　　　　　　　　　　　　　　　　　　　　　　　　" << endl; SetColor(0, 15);	// 24
	cout << "■　"; SetColor(12, 15); cout << "　　■　■　　"; SetColor(0, 15); cout << "　■　■　　　　　　　　　　　　　　　　　　　　　　　　" << endl; SetColor(0, 15);	// 25
	cout << "■■　　　　　　■■■■■■■　　　　　　　　　　　　　■■■■■■■　　" << endl; SetColor(0, 15);	// 26
	cout << "■■■　　　　■　　　　　　　■　　　　　　　　　　　■　　　　　　　■　" << endl; SetColor(0, 15);	// 27
	cout << "■■■　　　■　　　　　　　　　■　　　　　　　　　■　　　　　　　　　■" << endl; SetColor(0, 15);	// 28
	cout << "■■■　　■■■■■■■■■■■■■　　　　　　　■■■■■■■■■■■■" << endl; SetColor(0, 15);	// 29
	cout << "■■■　　　■　　　　　　　　　■　　　　　　　　　■　　　　　　　　　■" << endl; SetColor(0, 15);	// 30
	cout << "■■■　　　■　■■■　　　　　■　　　　　　　　　■　■■■　　　　　■" << endl; SetColor(0, 15);	// 31
	cout << "■■■　　　■　■　■　　　　　■　　　□□□　　　■　■　■　　■■　■" << endl; SetColor(0, 15);	 // 32
	cout << "■■■　　　■　■　■　　　　　■　　　□□□　　　■　■　■　　　　　■" << endl; SetColor(0, 15);	// 33
	cout << "■■■　　　■■■■■■■■■■■　　　□□□　　　■■■■■■■■■■■" << endl; SetColor(0, 15);	// 34
	cout << "■■■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　" << endl; SetColor(0, 15);	// 35
	cout << "■■■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　" << endl; SetColor(0, 15);	// 36
	cout << "■■■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　" << endl; SetColor(0, 15);	// 37
}


void mainGame::VillageBattle3Screen()
{
	gotoxy(0, 0);
	SetColor(0, 15);

	cout << "■■■　　　　　　　　　　　　　　　　　　　　　　　■■　　　　　　　　　" << endl; SetColor(0, 15);	// 1
	cout << "■■■　　　　　　　　　　　　　　　　　　　　　　　■■　　　　　　　　　" << endl; SetColor(0, 15);	// 2
	cout << "■■■　　　　■■■■■■■　　　　　　　　　　　　■■■■■■■■　　　" << endl; SetColor(0, 15);	// 3
	cout << "■■■　　　■　　　　　　　■　　　　　　　　　　■　　　　　　　　■　　" << endl; SetColor(0, 15);	// 4
	cout << "■■■　　■　　　　　　　　　■　　　　　　　　■　　　　　　　　　　■　" << endl; SetColor(0, 15);	// 5
	cout << "■■■　■■■■■■■■■■■■■　　　　　　■■■■■■■■■■■■■■" << endl; SetColor(0, 15);	// 6
	cout << "■■■　　■　　　　　　　　　■　　　　　　　　■　　　　　　　　　　■　" << endl; SetColor(0, 15);	// 7
	cout << "■■■　　■　■■■　　　　　■　　　　　　　　■　■■■　　　　　　■　" << endl; SetColor(0, 15);	// 8
	cout << "■■■　　■　■　■　　■■　■　　　　　　　　■　■　■　　　　　　■　" << endl; SetColor(0, 15);	// 9
	cout << "■■■　　■　■　■　　　　　■　　　　　　　　■　■　■　　　　　　■　" << endl; SetColor(0, 15);	// 10
	cout << "■■■　　■■■■■■■■■■■　　　　　　　　■■■■■■■■■■■■　" << endl; SetColor(0, 15);	// 11
	cout << "■■■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　" << endl; SetColor(0, 15);	// 12
	cout << "■■■　　　　　　　　　　　　　　　　　　"; SetColor(14, 15); cout << "　　■　"; SetColor(11, 15); cout << "　　■　　　　　　　　　" << endl; SetColor(0, 15);	// 13
	cout << "■■■　　　　　　　　　　　　■　　　　　"; SetColor(14, 15); cout << "　■■■"; SetColor(11, 15); cout << "　■■■　"; SetColor(0, 15); cout << "　　　　■■　" << endl; SetColor(0, 15);	// 14
	cout << "■■■　　　　　　■　　　　■■■　　　　"; SetColor(14, 15); cout << "　　■　"; SetColor(11, 15); cout << "　　■　　"; SetColor(0, 15); cout << "　　　　■■　" << endl; SetColor(0, 15);	// 15
	cout << "■■　　　　　　■■■　　　　■■　　　　"; SetColor(14, 15); cout << "　■　■"; SetColor(11, 15); cout << "　■　■　"; SetColor(0, 15); cout << "　　　■■■■" << endl; SetColor(0, 15);	// 16
	cout << "■　　　　　　　　■■　　　■■■■　　　　　　　　　　　　　　■　■■　" << endl; SetColor(0, 15);	// 17
	cout << "　"; SetColor(13, 15); cout << "　■　■　　"; SetColor(0, 15); cout << "　■■■■　■　■■　■　　　　　　　　　　　　　　■　　■" << endl; SetColor(0, 15);	// 18
	cout << "　"; SetColor(13, 15); cout << "■■■　　　"; SetColor(0, 15); cout << "■　■■　■　■　　■　■■　　　　　　　　　　　　　　　　" << endl; SetColor(0, 15);	// 19
	cout << "　"; SetColor(13, 15); cout << "　■　■　　"; SetColor(0, 15); cout << "　■　　■　　　　　　■■■■　　　　■■　　　　■■　　　" << endl; SetColor(0, 15);	// 20
	cout << "　　　　　　　　　　　■■　　　　■　■■　■　　■■■■　　■■■■　　" << endl; SetColor(0, 15);	// 21
	cout << "　　　　　　　　　　　■■　　　　　　■■　　　■　■■　■■　■■　■　" << endl; SetColor(0, 15);	// 22
	cout << "　　　"; SetColor(12, 15); cout << "　■　■"; SetColor(0, 15); cout << "　　　■■■■　　　　■　　■　　　■　　■　　■　　■　　" << endl; SetColor(0, 15);	// 23
	cout << "　　　"; SetColor(12, 15); cout << "■■■　"; SetColor(0, 15); cout << "　　■　■■　■　　　　　　　　　　　　　　　　　　　　　　" << endl; SetColor(0, 15);	// 24
	cout << "■　　"; SetColor(12, 15); cout << "　■　■"; SetColor(0, 15); cout << "　　　■　　■　　　　　　　　　　　　　　　　　　　　　　　" << endl; SetColor(0, 15);	// 25
	cout << "■■　　　　　　■■■■■■■　　　　　　　　　　　　　■■■■■■■　　" << endl; SetColor(0, 15);	// 26
	cout << "■■■　　　　■　　　　　　　■　　　　　　　　　　　■　　　　　　　■　" << endl; SetColor(0, 15);	// 27
	cout << "■■■　　　■　　　　　　　　　■　　　　　　　　　■　　　　　　　　　■" << endl; SetColor(0, 15);	// 28
	cout << "■■■　　■■■■■■■■■■■■■　　　　　　　■■■■■■■■■■■■" << endl; SetColor(0, 15);	// 29
	cout << "■■■　　　■　　　　　　　　　■　　　　　　　　　■　　　　　　　　　■" << endl; SetColor(0, 15);	// 30
	cout << "■■■　　　■　■■■　　　　　■　　　　　　　　　■　■■■　　　　　■" << endl; SetColor(0, 15);	// 31
	cout << "■■■　　　■　■　■　　　　　■　　　□□□　　　■　■　■　　■■　■" << endl; SetColor(0, 15);	// 32
	cout << "■■■　　　■　■　■　　　　　■　　　□□□　　　■　■　■　　　　　■" << endl; SetColor(0, 15);	// 33
	cout << "■■■　　　■■■■■■■■■■■　　　□□□　　　■■■■■■■■■■■" << endl; SetColor(0, 15);	// 34
	cout << "■■■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　" << endl; SetColor(0, 15);	// 35
	cout << "■■■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　" << endl; SetColor(0, 15);	// 36
	cout << "■■■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　" << endl; SetColor(0, 15);	// 37
}

void mainGame::VillageBattle4Screen()
{
	gotoxy(0, 0);
	SetColor(0, 15);

	cout << "■■■　　　　　　　　　　　　　　　　　　　　　　　■■　　　　　　　　　" << endl; SetColor(0, 15);	// 1
	cout << "■■■　　　　　　　　　　　　　　　　　　　　　　　■■　　　　　　　　　" << endl; SetColor(0, 15);	// 2
	cout << "■■■　　　　■■■■■■■　　　　　　　　　　　　■■■■■■■■　　　" << endl; SetColor(0, 15);	// 3
	cout << "■■■　　　■　　　　　　　■　　　　　　　　　　■　　　　　　　　■　　" << endl; SetColor(0, 15);	// 4
	cout << "■■■　　■　　　　　　　　　■　　　　　　　　■　　　　　　　　　　■　" << endl; SetColor(0, 15);	// 5
	cout << "■■■　■■■■■■■■■■■■■　　　　　　■■■■■■■■■■■■■■" << endl; SetColor(0, 15);	// 6
	cout << "■■■　　■　　　　　　　　　■　　　　　　　　■　　　　　　　　　　■　" << endl; SetColor(0, 15);	// 7
	cout << "■■■　　■　■■■　　　　　■　　　　　　　　■　■■■　　　　　　■　" << endl; SetColor(0, 15);	// 8
	cout << "■■■　　■　■　■　　■■　■　　　　　　　　■　■　■　　　　　　■　" << endl; SetColor(0, 15);	// 9
	cout << "■■■　　■　■　■　　　　　■　　　　　　　　■　■　■　　　　　　■　" << endl; SetColor(0, 15);	// 10
	cout << "■■■　　■■■■■■■■■■■　　　　　　　　■■■■■■■■■■■■　" << endl; SetColor(0, 15);	// 11
	cout << "■■■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　" << endl; SetColor(0, 15);	// 12
	cout << "■■■　　　　　　　　　　　　　　　　　　"; SetColor(14, 15); cout << "　　■　"; SetColor(11, 15); cout << "　　■　　　　　　　　　" << endl; SetColor(0, 15);	// 13
	cout << "■■■　　　　　　　　　　　　■　　　　　"; SetColor(14, 15); cout << "　■■　"; SetColor(11, 15); cout << "　　■■　"; SetColor(0, 15); cout << "　　　　■■　" << endl; SetColor(0, 15);	// 14
	cout << "■■■　　　　　　■　　　　■■■　　　　"; SetColor(14, 15); cout << "　　■　"; SetColor(11, 15); cout << "　　■　　"; SetColor(0, 15); cout << "　　　　■■　" << endl; SetColor(0, 15);	// 15
	cout << "■■　　　　　　■■■　　　　■■　　　　"; SetColor(14, 15); cout << "　■　■"; SetColor(11, 15); cout << "　■　■　"; SetColor(0, 15); cout << "　　　■■■■" << endl; SetColor(0, 15);	// 16
	cout << "■　　　　　　　　■■　　　■■■■　　　　　　　　　　　　　　■　■■　" << endl; SetColor(0, 15);	// 17
	cout << "　"; SetColor(13, 15); cout << "　■　■　　"; SetColor(0, 15); cout << "　■■■■　■　■■　■　　　　　　　　　　　　　　■　　■" << endl; SetColor(0, 15);	// 18
	cout << "　"; SetColor(13, 15); cout << "■■■　　　"; SetColor(0, 15); cout << "■　■■　■　■　　■　■■　　　　　　　　　　　　　　　　" << endl; SetColor(0, 15);	// 19
	cout << "　"; SetColor(13, 15); cout << "　■　■　　"; SetColor(0, 15); cout << "　■　　■　　　　　　■■■■　　　　■■　　　　■■　　　" << endl; SetColor(0, 15);	// 20
	cout << "　　　　　　　　　　　■■　　　　■　■■　■　　■■■■　　■■■■　　" << endl; SetColor(0, 15);	// 21
	cout << "　　　　　　　　　　　■■　　　　　　■■　　　■　■■　■■　■■　■　" << endl; SetColor(0, 15);	// 22
	cout << "　　　"; SetColor(12, 15); cout << "　■　■"; SetColor(0, 15); cout << "　　　■■■■　　　　■　　■　　　■　　■　　■　　■　　" << endl; SetColor(0, 15);	// 23
	cout << "　　　"; SetColor(12, 15); cout << "■■■　"; SetColor(0, 15); cout << "　　■　■■　■　　　　　　　　　　　　　　　　　　　　　　" << endl; SetColor(0, 15);	// 24
	cout << "■　　"; SetColor(12, 15); cout << "　■　■"; SetColor(0, 15); cout << "　　　■　　■　　　　　　　　　　　　　　　　　　　　　　　" << endl; SetColor(0, 15);	// 25
	cout << "■■　　　　　　■■■■■■■　　　　　　　　　　　　　■■■■■■■　　" << endl; SetColor(0, 15);	// 26
	cout << "■■■　　　　■　　　　　　　■　　　　　　　　　　　■　　　　　　　■　" << endl; SetColor(0, 15);	// 27
	cout << "■■■　　　■　　　　　　　　　■　　　　　　　　　■　　　　　　　　　■" << endl; SetColor(0, 15);	// 28
	cout << "■■■　　■■■■■■■■■■■■■　　　　　　　■■■■■■■■■■■■" << endl; SetColor(0, 15);	// 29
	cout << "■■■　　　■　　　　　　　　　■　　　　　　　　　■　　　　　　　　　■" << endl; SetColor(0, 15);	// 30
	cout << "■■■　　　■　■■■　　　　　■　　　　　　　　　■　■■■　　　　　■" << endl; SetColor(0, 15);	// 31
	cout << "■■■　　　■　■　■　　　　　■　　　□□□　　　■　■　■　　■■　■" << endl; SetColor(0, 15);	// 32
	cout << "■■■　　　■　■　■　　　　　■　　　□□□　　　■　■　■　　　　　■" << endl; SetColor(0, 15);	// 33
	cout << "■■■　　　■■■■■■■■■■■　　　□□□　　　■■■■■■■■■■■" << endl; SetColor(0, 15);	// 34
	cout << "■■■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　" << endl; SetColor(0, 15);	// 35
	cout << "■■■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　" << endl; SetColor(0, 15);	// 36
	cout << "■■■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　" << endl; SetColor(0, 15);	// 37
}


void mainGame::HouseEvent3()
{
	VillageBattle5Screen();
	Sleep(1500);

	gotoxy(0, 26);
	SetColor(13, 15);

	cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;
	cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
	cout << "■"; SetColor(0, 15); cout << "　　[아타호]　　　　　　　　　　　　　　　　　　　　　　　　　　　　　"; SetColor(13, 15); cout << "■" << endl;
	cout << "■"; SetColor(0, 15); cout << "　　생각보다 엄청나군 도대체 어떻게 되먹은 현상인가 자네 괜찮나 　 　 "; SetColor(13, 15); cout << "■" << endl;
	cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
	cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
	cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
	cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
	cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
	cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
	cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;

	Conversation();

	VillageBattle5Screen();
	Sleep(1200);

	gotoxy(0, 26);
	SetColor(13, 15);

	cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;
	cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
	cout << "■　　"; SetColor(0, 15); cout << "[호연]　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　"; SetColor(13, 15); cout << "■" << endl;
	cout << "■　　"; SetColor(0, 15); cout << "아직 버틸 수 있네 자네야말로 괜찮은가 　　　　　　　　　　　　 　 "; SetColor(13, 15); cout << "■" << endl;
	cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
	cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
	cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
	cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
	cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
	cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
	cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;

	Conversation();

	VillageBattle5Screen();
	Sleep(1200);

	_effect = Ecrazy;
	/////////////////////////////////
	Sleep(1500);

	SetColor(15, 15);
	BootScreen2();
	Sleep(270);

	VillageBattle5Screen();
	Sleep(270);

	SetColor(15, 15);
	BootScreen2();
	Sleep(270);

	VillageBattle6Screen();
	Sleep(1500);

	//////////////////////////////////

	gotoxy(0, 26);
	SetColor(13, 15);

	cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;
	cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
	cout << "■　　"; SetColor(0, 15); cout << "[호연]　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　"; SetColor(13, 15); cout << "■" << endl;
	cout << "■　　"; SetColor(0, 15); cout << "대체 끝이 없구만 조심하게 아타호! 　　　　　　　　　　　　  　 　 "; SetColor(13, 15); cout << "■" << endl;
	cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
	cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
	cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
	cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
	cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
	cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
	cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;

	Conversation();

	VillageBattle6Screen();
	Sleep(1200);

	gotoxy(0, 26);
	SetColor(13, 15);

	cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;
	cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
	cout << "■　　"; SetColor(0, 15); cout << "[아타호]　　　　　　　　　　　　　　　　　　　　　　　　　　　　　"; SetColor(13, 15); cout << "■" << endl;
	cout << "■　　"; SetColor(0, 15); cout << "자네도 조심하게!! 　　　　　　　　　　　　　　　　　　　　　  　  "; SetColor(13, 15); cout << "■" << endl;
	cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
	cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
	cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
	cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
	cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
	cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
	cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;

	Conversation();


	VillageBattle6Screen();
	Sleep(500);

	_effect = Ebattleenter;

	SetColor(15, 15);
	BootScreen2();
	Sleep(130);

	VillageBattle6Screen();
	Sleep(130);

	SetColor(15, 15);
	BootScreen2();
	Sleep(130);

	VillageBattle6Screen();
	Sleep(1250);

	VillageBattle2Init();

	if (_characterHp == 0)
	{
		b_villagebattleMusic = false;
		GameOver();
		return;
	}
	else
	{
		VillageBattle7Screen();

		Sleep(1500);

		gotoxy(0, 26);
		SetColor(13, 15);

		cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;
		cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
		cout << "■　　"; SetColor(0, 15); cout << "[아타호]　　　　　　　　　　　　　　　　　　　　　　　　　　　　　"; SetColor(13, 15); cout << "■" << endl;
		cout << "■　　"; SetColor(0, 15); cout << "대체 이게 무슨일인지..　　　　　　　　　　　　　　　　　　　  　  "; SetColor(13, 15); cout << "■" << endl;
		cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
		cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
		cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
		cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
		cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
		cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
		cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;

		Conversation();

		VillageBattle7Screen();
		Sleep(1300);

		gotoxy(0, 26);
		SetColor(13, 15);

		cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;
		cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
		cout << "■"; SetColor(0, 15); cout << "　　[호연]　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　"; SetColor(13, 15); cout << "■" << endl;
		cout << "■"; SetColor(0, 15); cout << "　　후.. 집으로 따라오게 안에서 말해주겠네　　　　　　　　　　　  　  "; SetColor(13, 15); cout << "■" << endl;
		cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
		cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
		cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
		cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
		cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
		cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
		cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;

		Conversation();

		VillageBattle7Screen();
		Sleep(1300);

		gotoxy(0, 26);
		SetColor(13, 15);

		cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;
		cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
		cout << "■"; SetColor(0, 15); cout << "　　[아타호]　　　　　　　　　　　　　　　　　　　　　　　　　　　　　"; SetColor(13, 15); cout << "■" << endl;
		cout << "■"; SetColor(0, 15); cout << "　　알았네　　　　　　　　　　　　　　　　　　　　　　　　　　  　 　 "; SetColor(13, 15); cout << "■" << endl;
		cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
		cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
		cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
		cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
		cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
		cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
		cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;

		Conversation();
		VillageBattle7Screen();
		b_villagebattleMusic = false;
		Sleep(1500);

		Move2();

		b_housecheck = false;
		b_villageMusic = true;

		Village2Screen();
		Village2Choice();
	}
}


void mainGame::VillageBattle2Init()
{
	_skillTemp = 0;
	_skillcheck = 1;
	_monster1statecheck = 1;
	_charactercheck = 1;
	_monster2statecheck = 1;
	_battlecheck = 1;

	b_battleMusic = true;

	SetColor(15, 15);
	BootScreen2();
	gotoxy(0, 26);
	SetColor(9, 15);
	cout << "■■□□□■■■□□□■■■□□□■■■□□□■■■□□□■■■□□□■■" << endl;	// 27
	SetColor(8, 8);
	cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　" << endl;	// 32 
	cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　" << endl;	// 32
	cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　" << endl;	// 32 
	cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　" << endl;	// 32 
	cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　" << endl;	// 32 
	cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　" << endl;	// 32 
	cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　" << endl;	// 32 
	cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　" << endl;	// 32 
	cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　" << endl;	// 32 
	cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　" << endl;	// 32

	_human1 = new human1;
	_human2 = new human2;

	monsterBase* _mob1 = _human2;
	monsterBase* _mob2 = _human1;

	BattleScreen(_mob1, _mob2);
	BattleChoice(_mob1, _mob2);

	delete _human1;
	delete _human2;
}



void mainGame::VillageBattle5Screen()
{
	gotoxy(0, 0);
	SetColor(0, 15);


	cout << "■■■　　　　　　　　　　　　　　　　　　　　　　　■■　　　　　　　　　" << endl; SetColor(0, 15);	// 1
	cout << "■■■　　　　　　　　　　　　　　　　　　　　　　　■■　　　　　　　　　" << endl; SetColor(0, 15);	// 2
	cout << "■■■　　　　■■■■■■■　　　　　　　　　　　　■■■■■■■■　　　" << endl; SetColor(0, 15);	// 3
	cout << "■■■　　　■　　　　　　　■　　　　　　　　　　■　　　　　　　　■　　" << endl; SetColor(0, 15);	// 4
	cout << "■■■　　■　　　　　　　　　■　　　　　　　　■　　　　　　　　　　■　" << endl; SetColor(0, 15);	// 5
	cout << "■■■　■■■■■■■■■■■■■　　　　　　■■■■■■■■■■■■■■" << endl; SetColor(0, 15);	// 6
	cout << "■■■　　■　　　　　　　　　■　　　　　　　　■　　　　　　　　　　■　" << endl; SetColor(0, 15);	// 7
	cout << "■■■　　■　■■■　　　　　■　　　　　　　　■　■■■　　　　　　■　" << endl; SetColor(0, 15);	// 8
	cout << "■■■　　■　■　■　　■■　■　　　　　　　　■　■　■　　　　　　■　" << endl; SetColor(0, 15);	// 9
	cout << "■■■　　■　■　■　　　　　■　　　　　　　　■　■　■　　　　　　■　" << endl; SetColor(0, 15);	// 10
	cout << "■■■　　■■■■■■■■■■■　　　　　　　　■■■■■■■■■■■■　" << endl; SetColor(0, 15);	// 11
	cout << "■■■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　" << endl; SetColor(0, 15);	// 12
	cout << "■■■　　　　　　　　　　　　　　　　　　　"; SetColor(14, 15); cout << "　■　　"; SetColor(11, 15); cout << "　■　　　　　　　　　" << endl; SetColor(0, 15);	// 13
	cout << "■■■　　　　　　　　　　　　　　　　　　　"; SetColor(14, 15); cout << "■■　　"; SetColor(11, 15); cout << "　■■　　　　　　　　" << endl; SetColor(0, 15);	// 14
	cout << "■■■　　　　　　■　　　　　　　　　　　　"; SetColor(14, 15); cout << "　■　　"; SetColor(11, 15); cout << "　■　　　　　　　　　" << endl; SetColor(0, 15);	// 15
	cout << "■■　　　　　　■■■　　　　　　　　　　　"; SetColor(14, 15); cout << "■　■　"; SetColor(11, 15); cout << "■　■　　　　　　　　" << endl; SetColor(0, 15);	// 16
	cout << "■　　　　　　　　■■　　　　　　　　　　　　　　　　　　　　　　　　　　" << endl; SetColor(0, 15);	// 17
	cout << "　"; SetColor(13, 15); cout << "　■　■　　"; SetColor(0, 15); cout << "　■■■■　　　　　　　　　　　　　　　　　　　　　　　　　" << endl; SetColor(0, 15);	// 18
	cout << "　"; SetColor(13, 15); cout << "■■■　　　"; SetColor(0, 15); cout << "■　■■　■　　　　　　　　　　　　　　　　　　　　　　　　" << endl; SetColor(0, 15);	// 19
	cout << "　"; SetColor(13, 15); cout << "　■　■　　"; SetColor(0, 15); cout << "　■　　■　　　　　　　　　　　　　　　　　　　　■■　　　" << endl; SetColor(0, 15);	// 20
	cout << "　　　　　　　　　　　■■　　　　　　　　　　　　　　　　　　■■■■　　" << endl; SetColor(0, 15);	// 21
	cout << "　　　　　　　　　　　■■　　　　　　　　　　　　　　　　　■　■■　■　" << endl; SetColor(0, 15);	// 22
	cout << "　　"; SetColor(12, 15); cout << "　　■　■　"; SetColor(0, 15); cout << "　　■■■■　　　　　　　　　　　　　　　　　■　　■　　" << endl; SetColor(0, 15);	// 23
	cout << "　　"; SetColor(12, 15); cout << "　■■■　　"; SetColor(0, 15); cout << "　■　■■　■　　　　　　　　　　　　　　　　　　　　　　" << endl; SetColor(0, 15);	// 24
	cout << "■　"; SetColor(12, 15); cout << "　　■　■　"; SetColor(0, 15); cout << "　　■　　■　　　　　　　　　　　　　　　　　　　　　　　" << endl; SetColor(0, 15);	// 25
	cout << "■■　　　　　　■■■■■■■　　　　　　　　　　　　　■■■■■■■　　" << endl; SetColor(0, 15);	// 26
	cout << "■■■　　　　■　　　　　　　■　　　　　　　　　　　■　　　　　　　■　" << endl; SetColor(0, 15);	// 27
	cout << "■■■　　　■　　　　　　　　　■　　　　　　　　　■　　　　　　　　　■" << endl; SetColor(0, 15);	// 28
	cout << "■■■　　■■■■■■■■■■■■■　　　　　　　■■■■■■■■■■■■" << endl; SetColor(0, 15);	// 29
	cout << "■■■　　　■　　　　　　　　　■　　　　　　　　　■　　　　　　　　　■" << endl; SetColor(0, 15);	// 30
	cout << "■■■　　　■　■■■　　　　　■　　　　　　　　　■　■■■　　　　　■" << endl; SetColor(0, 15);	// 31
	cout << "■■■　　　■　■　■　　　　　■　　　□□□　　　■　■　■　　■■　■" << endl; SetColor(0, 15);	// 32
	cout << "■■■　　　■　■　■　　　　　■　　　□□□　　　■　■　■　　　　　■" << endl; SetColor(0, 15);	// 33
	cout << "■■■　　　■■■■■■■■■■■　　　□□□　　　■■■■■■■■■■■" << endl; SetColor(0, 15);	// 34
	cout << "■■■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　" << endl; SetColor(0, 15);	// 35
	cout << "■■■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　" << endl; SetColor(0, 15);	// 36
	cout << "■■■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　" << endl; SetColor(0, 15);	// 37
}

void mainGame::VillageBattle6Screen()
{
	gotoxy(0, 0);
	SetColor(0, 15);

	cout << "■■■　　　　　　　　　　　　　　　　　　　　　　　■■　　　　　　　　　" << endl;	// 1
	cout << "■■■　　　　　　　　　　　　　　　　　　　　　　　■■　　　　　　　　　" << endl;	// 2
	cout << "■■■　　　　■■■■■■■　　　　　　　　　　　　■■■■■■■■　　　" << endl;	// 3
	cout << "■■■　　　■　　　　　　　■　　　　　　　　　　■　　　　　　　　■　　" << endl;	// 4
	cout << "■■■　　■　　　　　　　　　■　　　　　　　　■　　　　　　　　　　■　" << endl;	// 5
	cout << "■■■　■■■■■■■■■■■■■　　　　　　■■■■■■■■■■■■■■" << endl;	// 6
	cout << "■■■　　■　　　　　　　　　■　　　　　　　　■　　　　　　　　　　■　" << endl;	// 7
	cout << "■■■　　■　■■■　　　　　■　　　　　　　　■　■■■　　　　　　■　" << endl;	// 8
	cout << "■■■　　■　■　■　　■■　■　　　　　　　　■　■　■　　　　　　■　" << endl;	// 9
	cout << "■■■　　■　■　■　　　　　■　　　　　　　　■　■　■　　　　　　■　" << endl;	// 10
	cout << "■■■　　■■■■■■■■■■■　　　　　　　　■■■■■■■■■■■■　" << endl;	// 11
	cout << "■■■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　" << endl;	// 12
	cout << "■■■　　　　　　　　　　　　　　　　　　　"; SetColor(14, 15); cout << "　■　　"; SetColor(11, 15); cout << "　■　　　　　　　　　" << endl; SetColor(0, 15);	// 13
	cout << "■■■　　　　　　　　　　　　■　　　　　　"; SetColor(14, 15); cout << "■■　　"; SetColor(11, 15); cout << "　■■　　　"; SetColor(0, 15); cout << "　　■■　" << endl; SetColor(0, 15);	// 14
	cout << "■■■　　　　　　　　　　　■■■　　　　　"; SetColor(14, 15); cout << "　■　　"; SetColor(11, 15); cout << "　■　　　　"; SetColor(0, 15); cout << "　　■■　" << endl; SetColor(0, 15);	// 15
	cout << "■■　　　　　　　　　　　　　■■　　　　　"; SetColor(14, 15); cout << "■　■　"; SetColor(11, 15); cout << "■　■　　　"; SetColor(0, 15); cout << "　■■■■" << endl; SetColor(0, 15);	// 16
	cout << "■　　　　　　　　　　　　　■■■■　　　　　　　　　　　　　　■　■■　" << endl;	// 17
	cout << "　"; SetColor(13, 15); cout << "　■　■　　"; SetColor(0, 15); cout << "　　　　　　■　■■　■　　　　　　　　　■■　　　■　　■" << endl;	// 18
	cout << "　"; SetColor(13, 15); cout << "■■■　　　"; SetColor(0, 15); cout << "　　　　　　　■　　■　■■　　　　　　■■■■　　　　　　" << endl;	// 19
	cout << "　"; SetColor(13, 15); cout << "　■　■　　"; SetColor(0, 15); cout << "　　　　　　　　　　　■■■■　　　　■　■■　■　　　　　" << endl;	// 20
	cout << "　　　　　　　　　　　　　　　　　■　■■　■　　　　■　　■　　　　　　" << endl;	// 21
	cout << "　　　　　　　　　　　　　　　　　　　■■　　　　　　　　　　　　　　　　" << endl;	// 22
	cout << "　　　"; SetColor(12, 15); cout << "　■　■　"; SetColor(0, 15); cout << "　　　　　　　　　　■　　■　　　　　　　　　　　　　　　" << endl;	// 23
	cout << "　　　"; SetColor(12, 15); cout << "■■■　　"; SetColor(0, 15); cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　" << endl; SetColor(0, 15);	// 24
	cout << "■　　"; SetColor(12, 15); cout << "　■　■　"; SetColor(0, 15); cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　" << endl; SetColor(0, 15);	// 25
	cout << "■■　　　　　　■■■■■■■　　　　　　　　　　　　　■■■■■■■　　" << endl;	// 26
	cout << "■■■　　　　■　　　　　　　■　　　　　　　　　　　■　　　　　　　■　" << endl;	// 27
	cout << "■■■　　　■　　　　　　　　　■　　　　　　　　　■　　　　　　　　　■" << endl;	// 28
	cout << "■■■　　■■■■■■■■■■■■■　　　　　　　■■■■■■■■■■■■" << endl;	// 29
	cout << "■■■　　　■　　　　　　　　　■　　　　　　　　　■　　　　　　　　　■" << endl;	// 30
	cout << "■■■　　　■　■■■　　　　　■　　　　　　　　　■　■■■　　　　　■" << endl;	// 31
	cout << "■■■　　　■　■　■　　　　　■　　　□□□　　　■　■　■　　■■　■" << endl;	// 32
	cout << "■■■　　　■　■　■　　　　　■　　　□□□　　　■　■　■　　　　　■" << endl;	// 33
	cout << "■■■　　　■■■■■■■■■■■　　　□□□　　　■■■■■■■■■■■" << endl;	// 34
	cout << "■■■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　" << endl;	// 35
	cout << "■■■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　" << endl;	// 36
	cout << "■■■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　" << endl;	// 37
}

void mainGame::VillageBattle7Screen()
{
	gotoxy(0, 0);
	SetColor(0, 15);

	cout << "■■■　　　　　　　　　　　　　　　　　　　　　　　■■　　　　　　　　　" << endl;	// 1
	cout << "■■■　　　　　　　　　　　　　　　　　　　　　　　■■　　　　　　　　　" << endl;	// 2
	cout << "■■■　　　　■■■■■■■　　　　　　　　　　　　■■■■■■■■　　　" << endl;	// 3
	cout << "■■■　　　■　　　　　　　■　　　　　　　　　　■　　　　　　　　■　　" << endl;	// 4
	cout << "■■■　　■　　　　　　　　　■　　　　　　　　■　　　　　　　　　　■　" << endl;	// 5
	cout << "■■■　■■■■■■■■■■■■■　　　　　　■■■■■■■■■■■■■■" << endl;	// 6
	cout << "■■■　　■　　　　　　　　　■　　　　　　　　■　　　　　　　　　　■　" << endl;	// 7
	cout << "■■■　　■　■■■　　　　　■　　　　　　　　■　■■■　　　　　　■　" << endl;	// 8
	cout << "■■■　　■　■　■　　■■　■　　　　　　　　■　■　■　　　　　　■　" << endl;	// 9
	cout << "■■■　　■　■　■　　　　　■　　　　　　　　■　■　■　　　　　　■　" << endl;	// 10
	cout << "■■■　　■■■■■■■■■■■　　　　　　　　■■■■■■■■■■■■　" << endl;	// 11
	cout << "■■■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　" << endl;	// 12
	cout << "■■■　　　　　　　　　　　　　　　　　　　"; SetColor(14, 15); cout << "　■　　"; SetColor(11, 15); cout << "　■　　　　　　　　　" << endl; SetColor(0, 15);	// 13
	cout << "■■■　　　　　　　　　　　　　　　　　　　"; SetColor(14, 15); cout << "■■■　"; SetColor(11, 15); cout << "■■■　　　　　　　　" << endl; SetColor(0, 15);	// 14
	cout << "■■■　　　　　　　　　　　　　　　　　　　"; SetColor(14, 15); cout << "　■　　"; SetColor(11, 15); cout << "　■　　　　　　　　　" << endl; SetColor(0, 15);	// 15
	cout << "■■　　　　　　　　　　　　　　　　　　　　"; SetColor(14, 15); cout << "■　■　"; SetColor(11, 15); cout << "■　■　　　　　　　　" << endl; SetColor(0, 15);	// 16
	cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　" << endl;	// 17
	cout << "　"; SetColor(13, 15); cout << "　■　■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　" << endl; SetColor(0, 15);	// 18
	cout << "　"; SetColor(13, 15); cout << "■■■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　" << endl; SetColor(0, 15);	// 19
	cout << "　"; SetColor(13, 15); cout << "　■　■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　" << endl; SetColor(0, 15);	// 20
	cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　" << endl;	// 21
	cout << "　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　" << endl;	// 22
	cout << "　　　"; SetColor(12, 15); cout << "　■　■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　" << endl; SetColor(0, 15);	// 23
	cout << "　　　"; SetColor(12, 15); cout << "■■■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　" << endl; SetColor(0, 15);	// 24
	cout << "■　　"; SetColor(12, 15); cout << "　■　■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　" << endl; SetColor(0, 15);	// 25
	cout << "■■　　　　　　■■■■■■■　　　　　　　　　　　　　■■■■■■■　　" << endl;	// 26
	cout << "■■■　　　　■　　　　　　　■　　　　　　　　　　　■　　　　　　　■　" << endl;	// 27
	cout << "■■■　　　■　　　　　　　　　■　　　　　　　　　■　　　　　　　　　■" << endl;	// 28
	cout << "■■■　　■■■■■■■■■■■■■　　　　　　　■■■■■■■■■■■■" << endl;	// 29
	cout << "■■■　　　■　　　　　　　　　■　　　　　　　　　■　　　　　　　　　■" << endl;	// 30
	cout << "■■■　　　■　■■■　　　　　■　　　　　　　　　■　■■■　　　　　■" << endl;	// 31
	cout << "■■■　　　■　■　■　　　　　■　　　□□□　　　■　■　■　　■■　■" << endl;	// 32
	cout << "■■■　　　■　■　■　　　　　■　　　□□□　　　■　■　■　　　　　■" << endl;	// 33
	cout << "■■■　　　■■■■■■■■■■■　　　□□□　　　■■■■■■■■■■■" << endl;	// 34
	cout << "■■■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　" << endl;	// 35
	cout << "■■■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　" << endl;	// 36
	cout << "■■■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　" << endl;	// 37
}

