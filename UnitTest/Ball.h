#pragma once
#include <iostream>
#include <vector>
#include "Vec2.h"
#include "raylib.h"
#include "LinearInterpolation.h"
struct Ball
{
	Texture2D tex;
	vec2 Position{ 100,100 };
	std::vector<vec2> newPosition;
	int currentNewPosition = 0;
	bool IsActive = false;
	float timer = 0;
	float AnotherFuckingTimer = 0;
	float speed;


	float health = 100;
	float LerpHealth = 100;

	void Update();
	void Draw();
};