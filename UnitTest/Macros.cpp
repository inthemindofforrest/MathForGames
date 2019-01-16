#include "Macros.h"

bool assert(const char * testName, bool expression)
{
	if (expression)
		std::cout << "[PASS] " << testName << std::endl;
	else
		std::cout << "[FAIL] " << testName << std::endl;
	return expression;
}

bool assert(const char * testName, int expected, int actual)
{
	if (actual == expected)
		std::cout << "[PASS] " << testName << std::endl;
	else
		std::cout << "[FAIL] " << testName << std::endl;
	return (actual == expected);
}

bool assert(const char * testName, float expected, float actual, float tolerance)
{
	if (expected - actual <= tolerance)
		std::cout << "[PASS] " << testName << std::endl;
	else
		std::cout << "[FAIL] " << testName << std::endl;
	return (expected - actual <= tolerance);
}
