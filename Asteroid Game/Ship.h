#pragma once
#include "raylib.h"

struct Bullet {
    Vector2 positionShoot;
    Vector2 speed;
    float radius;
    float rotation;
    int lifeSpawn;
    bool active;
    Color color;
};

class Ship
{
private:

    Vector2 position;
    Vector2 speed;
    int shipHeight;
    float acceleration;
    float rotation;
    Vector3 collider;
    Color color;
    Bullet shoot[10];

public:
	Ship(Vector2 speed, int acceleration, int rotation, Color color);
    ~Ship();

    void Shoot();
    void move();
    void draw();

    Vector2 getPosition();
};
