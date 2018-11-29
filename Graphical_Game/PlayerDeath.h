#pragma once
#include "SimpleSprites.h"
#include "Startscreen.h"
#include <vector>
class Player;
class PlayerDeath
{
public:
	std::vector<SimpleSprites*> explosions;
	PlayerDeath();
	~PlayerDeath();
	void update(Player& player);
};

