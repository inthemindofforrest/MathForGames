#include "Utils.h"

int min(int a, int b)
{
	return a < b ? a : b;
}

int max(int a, int b)
{
	return a > b ? a : b;
}

int clamp(int value, int min, int max)
{
	if (value < min)
		return min;
	else if (value > max)
		return max;
	return value;
}

int abs(int value)
{
	return value < 0 ? (int)(-1 * value) : value;
}

int pow(int base, int power)
{
	int Number = base;
	for (int i = 1; i < power; i++)
		Number *= base;
	return Number;
}

bool isPowerOfTwo(int val)
{
	float Check = val;
	while (Check > 1)
		Check /= 2;
	return Check == 1 ? true : false;
}

int nextPowerOfTwo(int val)
{
	//If not a power of 2, do nothing, else return number
	while (!isPowerOfTwo(val += 1))
		if (val > val + 1)
			return 0;
	return val;
}

float moveTowards(float current, float target, float maxDelta)
{
	//add to the current until at target
	if (current < target)
		return (current + maxDelta < target ) ? current += maxDelta : target;
	//Sub to the current until at target
	else if (current > target)
		return (current + maxDelta > target) ? current -= maxDelta : target;
	
	return target;
}