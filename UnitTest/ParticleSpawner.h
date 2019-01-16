#pragma once
#include "Particle.h"
#include <vector>
struct ParticleSpawner
{
	std::vector<Particles> particles;
	Texture2D ParticleTexture = LoadTexture("Sparkle.png");

	void Update();
	void Draw();

	void AddParticle(vec2 _Position);
};