#pragma once
#include "raylib.h"


class Ship
{
private:

	Texture2D ship = LoadTexture("Nave.png");
	

public:
	Ship();
	~Ship();


};

Ship::Ship()
{
}

Ship::~Ship()
{
}