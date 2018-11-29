#pragma once
#include "SimpleSprites.h"
class Startscreen :
	public SimpleSprites
{
public:
	static bool play;
	void update();
	Startscreen();
	~Startscreen();
private:
	Texture2D texture2;
	
};

