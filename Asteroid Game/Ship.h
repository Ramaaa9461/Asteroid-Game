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
    Vector2 FinalPosition;
    Vector2 speed;
    int shipHeight;
    Vector2 acceleration;
    float rotation;
    Vector3 collider;
    Color color;
    Bullet shoot[10];
    Vector2 Direccion;
    Vector2 DireccionNormalizada;
    double angulo;

public:
	Ship(Vector2 speed, Vector2 acceleration, int rotation, Color color);
    ~Ship();

    void Shoot();
    void Rotation();
    void Move();
    void draw();

    Vector2 getPosition();
};
