#include "Utils.h"

int sum(int a, int b)
{
	return a + b;
}
int diff(int a, int b)
{
	return a - b;
}
int min(int a, int b)
{
	return a < b ? a : b;
}
int max(int a, int b)
{
	return a > b ? a : b;
}
int clamp(int value, int lower, int upper)
{
	return max(lower, min(value, upper));
}
int abs(int value)
{
	return value < 0 ? (int)(-1 * value) : value;
}
float fAbs(float value)
{
	return value < 0 ? (-1 * value) : value;
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
	return (current + maxDelta < target && current < target || current - maxDelta > target && current > target) ? ((current < target) ? current += maxDelta : current -= maxDelta) : target;
}





