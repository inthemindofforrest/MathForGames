#include "Rand.h"

void RandomNumber::seedRand(int seedValue)
{
	FirstSeed = CurrentSeed = seedValue;
}

int RandomNumber::getRandSeed()
{
	return FirstSeed;
}

RandomNumber::RandomNumber()
{
	seedRand(123456);
}

void RandomNumber::GetNewSeed(long long int seed)//Only use after use of seed
{
	std::string temp = std::to_string((long long int)(seed * seed));
	std::string newSeed = "000000";
	while (temp.size() < 6)
		temp = std::to_string(0).c_str() + temp;
	for (int i = (temp.size() / 2) - 3; i < (temp.size() / 2) + 3; i++)
		if (temp[i] != NULL)
			newSeed[i - ((temp.size() / 2) - 3)] = temp[i];
	CurrentSeed = std::stoi(newSeed) + 2;
}


