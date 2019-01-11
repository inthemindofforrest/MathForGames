#pragma once

int sum(int a, int b);
int diff(int a, int b);

//Returns the Smaller of two values
int min(int a, int b);

int max(int a, int b);

int clamp(int value, int min, int max);

int abs(int value);
float fAbs(float value);

int pow(int base, int power);

bool isPowerOfTwo(int val);

int nextPowerOfTwo(int val);

float moveTowards(float current, float target, float maxDelta);


