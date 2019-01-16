#pragma once
#include "raylib.h"
#include "Vec2.h"
struct Particles
{
	Texture2D tex;
	vec2 Position;
	
	bool IsActive = true;

	float LifeTime;
	float Scale;

	vec2 Direction{ 0,0 };

	void Update();
	void Draw();

	Particles();
	Particles(vec2 _Position, vec2 _Direction, float _LifeTime, float _Scale);
};