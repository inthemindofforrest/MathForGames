#pragma once
#include <iostream>
#include <string>

class RandomNumber
{
private:
	int FirstSeed;
	int CurrentSeed;

	const int RandMax = 2147483647;

	void GetNewSeed(long long int seed);
public:

	// returns a random value between min and max
	template<typename T>
	T rand(T min, T max)
	{
		GetNewSeed((long long int)CurrentSeed);
		return CurrentSeed % (max - min) + min;
	}

	// returns a random value between min and max
	//  - the value may contain decimal components
	template<typename T>
	T randDecimal(T min, T max, unsigned int Precision)
	{
		//long double temp = (T)rand((int)min, (int)max) / ((T)RandMax + 1) * ((max - min) + min);
		return (T)rand((int)(min * pow(10, Precision)), (int)(max * pow(10, Precision))) / pow(10, Precision);
	}

	// seed the random number generator
	void seedRand(int seedValue);

	// returns the seed used for the random number generator
	int getRandSeed();

	//By default the seed is 123456
	RandomNumber();
};