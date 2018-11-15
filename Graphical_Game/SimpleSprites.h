#pragma once
#include <string>
#include "raylib.h"
class SimpleSprites
{
public:
	Vector2 pos;
	Rectangle collider;
	Texture2D texture;
	void translate(const Vector2 &delta); // move the sprites position by delta.
	void draw(); //draw the sprite on screen
	SimpleSprites * Clone();

	SimpleSprites();
	SimpleSprites(const SimpleSprites &copy);
	SimpleSprites(const std::string & filename);
	~SimpleSprites();
};

