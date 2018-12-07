#pragma once
#include <cfloat>
#include <iostream>
#include "Utils.h"

struct vec3
{
	float x, y, z;

	vec3();
	vec3(float a, float b, float c);

	float magnitude() const;
	float dot(const vec3 &rhs) const;
	vec3 cross(const vec3 &rhs) const;

	vec3 &normalize();

	vec3 operator+(const vec3 &rhs) const;
	vec3 operator-(const vec3 &rhs) const;

	vec3 &operator+=(const vec3 &rhs);
	vec3 &operator-=(const vec3 &rhs);

	bool operator==(const vec3 &rhs) const;
	bool operator!=(const vec3 &rhs) const;

	vec3 operator-() const;
	//float &operator[](size_t idx);
	//float operator[](size_t idx) const;

	operator float *();
	operator const float *() const;
};

