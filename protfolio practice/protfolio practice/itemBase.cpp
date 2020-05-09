#include "stdafx.h"
#include "itemBase.h"


itemBase::itemBase()
{
	_hpUp = 0;
}


itemBase::~itemBase()
{
}

int itemBase::GetHowMany()
{
	return _howMany;
}
int itemBase::GetHpUp()
{
	return _hpUp;
}
void itemBase::SetHowMany(int howMany)
{
	_howMany = howMany;
}
void itemBase::SetHpUp(int hpUp)
{
	_hpUp = hpUp;
}