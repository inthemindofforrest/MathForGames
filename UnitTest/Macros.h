#pragma once
#include <iostream>

#define TEST(testName, actual, expected)\
{\
actual == expected? std::cout << testName << ": " << "[Pass]" << std::endl : std::cout << testName << "\n" << "[Fail]" << std::endl;\
}\





bool assert(const char * testName, bool expression);
bool assert(const char * testName, int expected, int actual);
bool assert(const char * testName, float expected, float actual, float tolerance);