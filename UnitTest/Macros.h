#pragma once
#include <iostream>


bool assert(const char * testName, bool expression);
bool assert(const char * testName, int expected, int actual);
bool assert(const char * testName, float expected, float actual, float tolerance);