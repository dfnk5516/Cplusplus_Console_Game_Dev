#include "stdafx.h"
#include "mainGame.h"
mainGame *mg = new mainGame;

void Music();
void AutoScreen();
void EffectSound();
void Seed1();


int main()
{
	auto screen = async(AutoScreen);
	auto music = async(Music);
	auto sound = async(EffectSound);
	auto seed1 = async(Seed1);
	//auto seed2 = async(Seed2);
	//auto seed3 = async(Seed3);
	//auto seed4 = async(Seed4);
	//auto seed5 = async(Seed5);
	//auto seed6 = async(Seed6);
	//auto seed7 = async(Seed7);
	//auto seed8 = async(Seed8);
	mg->Game();

	delete mg;
	return 0;
}




void Music()
{
	mg->Music();
}
void AutoScreen()
{
	mg->AutoScreen();
}
void EffectSound()
{
	mg->EffectSound();
}
void Seed1()
{
	mg->Seed1();
}


