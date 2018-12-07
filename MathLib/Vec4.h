#pragma once
#include <cfloat>
#include "Utils.h"

struct vec4
{
	float x, y, z, w;

	vec4();
	vec4(float a, float b, float c, float d);

	float magnitude() const;
	float dot(const vec4 &rhs) const;
	vec4 cross(const vec4 &rhs) const;


	vec4 operator+(const vec4 &rhs) const;
	vec4 operator-(const vec4 &rhs) const;

	vec4 &operator+=(const vec4 &rhs);
	vec4 &operator-=(const vec4 &rhs);

	bool operator==(const vec4 &rhs) const;
	bool operator!=(const vec4 &rhs) const;

	vec4 operator-() const;
	//float &operator[](size_t idx);
	//float operator[](size_t idx) const;

	operator float *();
	operator const float *() const;
};

