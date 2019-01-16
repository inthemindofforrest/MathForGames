#include "Particle.h"

void Particles::Update()
{
	Position += Direction * GetFrameTime();
	LifeTime -= GetFrameTime();

	if (LifeTime <= 0) IsActive = false;
}

void Particles::Draw()
{
	if(IsActive)
		DrawTextureEx(tex, Position, 0, Scale, WHITE);
}

Particles::Particles()
{
	Position = { 100,100 };

	IsActive = true;

	LifeTime = 1;
	Scale = 1;

	Direction = { 0,0 };
}

Particles::Particles(vec2 _Position, vec2 _Direction, float _LifeTime, float _Scale)
{
	Position = _Position;

	IsActive = true;

	LifeTime = _LifeTime;
	Scale = _Scale;

	Direction = _Direction;
}
