#pragma once
#include "raylib.h"
#include "SimpleSprites.h"
#include <vector>
class Background : public SimpleSprites
{
public:
	Background();

	static std::vector<Rectangle> playArea;

	void draw();

};


