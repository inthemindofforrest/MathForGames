#pragma once

//Returns the Smaller of two values
int min(int a, int b);

int max(int a, int b);

int clamp(int value, int min, int max);

const double PI = 3.141592653589793238;
const double DEG_TO_RAD = PI / 180;
const double RAD_TO_DEG = 180 / PI;

int abs(int value);
float fAbs(float value);

int pow(int base, int power);

bool isPowerOfTwo(int val);

int nextPowerOfTwo(int val);

float moveTowards(float current, float target, float maxDelta);

