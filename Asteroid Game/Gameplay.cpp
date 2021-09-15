#include "gameplay.h"
#include "raylib.h"
#include "meteorito.h"

struct Triangle { Vector2 v1; Vector2 v2; Vector2 v3; };
static void initPositionPlayer(Triangle& triangle);

namespace game
{

	Triangle triangle;


	void initGameplayScreen()
	{
		initPositionPlayer(triangle);

	}

	void updateGameplayScreen()
	{

	}

	void drawGameplayScreen()
	{
		ClearBackground(BLACK);
		DrawTriangle(triangle.v1, triangle.v2, triangle.v3, YELLOW);

	}


}

void initPositionPlayer(Triangle& triangle)
{
	triangle.v2.x = 250;
	triangle.v2.y = 250;
	triangle.v3.x = 200;
	triangle.v3.y = 200;
	triangle.v1.x = 200;
	triangle.v1.y = 300;

}
