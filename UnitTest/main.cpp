#include <iostream>
#include"Utils.h"
#include <cassert>

int main()
{

	assert(min(10, 1) == 1);
	assert(max(1, 10) == 10);
	assert(clamp(1, 10, 100) == 10);
	assert(abs(-10) == 10);
	assert(pow(3, 3) == 27);
	assert(isPowerOfTwo(64) == true);
	assert(nextPowerOfTwo(14) == 16);
	assert(moveTowards(1, 2, 1.5) == 2);

	return 0;
}