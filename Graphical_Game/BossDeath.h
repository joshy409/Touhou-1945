#pragma once
#include "Startscreen.h"
class Boss;
class BossDeath 

{
public:
	BossDeath();
	~BossDeath();
	void update(Boss & boss);
	void draw(Boss & boss, float &i);
};

