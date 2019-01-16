#include "ParticleSpawner.h"

void ParticleSpawner::Update()
{
	if(particles.size() > 0)
		for (int i = 0; i < particles.size() - 1; i++)
			particles[i].Update();
}

void ParticleSpawner::Draw()
{
	if (particles.size() > 0)
		for (int i = 0; i < particles.size() - 1; i++)
			particles[i].Draw();
}

void ParticleSpawner::AddParticle(vec2 _Position)
{
	Particles temp(_Position, { (float)(rand() % 100 + 10) / 10,
		(float)(rand() % 100 + 10) / 10 }, (float)(rand() % 5), 1);

	(rand() % 100 >= 50 ? temp.Direction *= -1 : NULL);
	temp.tex = ParticleTexture;

	particles.push_back(temp);
}
