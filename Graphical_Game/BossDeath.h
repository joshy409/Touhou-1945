#pragma once
#include "Startscreen.h"
class Boss;

//Boss death animation. slowly grow in size and explodes
class BossDeath 

{
public:
	BossDeath();
	~BossDeath();
	void update(Boss & boss);
	void draw(Boss & boss, float &i);
};

