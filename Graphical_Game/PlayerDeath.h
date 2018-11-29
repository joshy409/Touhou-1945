#pragma once
#include "SimpleSprites.h"
#include "Startscreen.h"
#include <vector>
class Player;
class PlayerDeath
{
public:
	
	PlayerDeath();
	~PlayerDeath();
	void update(Player& player);
private:
	std::vector<SimpleSprites*> explosions;
};

