#pragma once
#include "SimpleSprites.h"
class Startscreen :
	public SimpleSprites
{
public:
	Texture2D texture2;
	static bool play;
	void update();
	Startscreen();
	~Startscreen();
};

