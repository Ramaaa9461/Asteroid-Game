#include "gameplay.h"
#include "raylib.h"
#include "meteorito.h"
#include "Ship.h"


namespace game
{
	Ship* ship;

	void initGameplayScreen()
	{
		ship = new Ship({ 4,4 }, 4, 0, YELLOW);
		
	}

	void updateGameplayScreen()
	{
		ship->move();
		ship->Shoot();
	}

	void drawGameplayScreen()
	{
		ClearBackground(BLACK);
		ship->draw();


	}

}

