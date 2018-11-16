#include "SimpleSprites.h"



SimpleSprites::SimpleSprites()
{
}

SimpleSprites::SimpleSprites(const SimpleSprites & copy)
{
	texture = copy.texture;
	collider = copy.collider;

}

SimpleSprites::SimpleSprites(const std::string & filename)
{
	texture = LoadTexture(filename.c_str());
	collider = { pos.x, pos.y, (float)texture.width, (float) texture.height };
}

SimpleSprites::~SimpleSprites()
{
}

void SimpleSprites::translate(const Vector2 &delta)
{
	pos = { pos.x + delta.x , pos.y + delta.y };
}

void SimpleSprites::draw()
{
	DrawTexture(texture, pos.x, pos.y, WHITE);
}

SimpleSprites * SimpleSprites::Clone()
{
	return new SimpleSprites(*this);
}
