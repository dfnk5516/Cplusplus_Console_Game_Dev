#pragma once
class itemBase
{
private:
	int _howMany;
	int _hpUp;

public:
	itemBase();
	~itemBase();

	int GetHowMany();
	int GetHpUp();
	void SetHowMany(int howMany);
	void SetHpUp(int hPUP);
};

