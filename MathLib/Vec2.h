#pragma once
#include <cfloat>
#include <iostream>
#include "Utils.h"

struct vec2
{
	float x;
	float y;

#ifdef RAYLIB_H
	operator Vector2();
#endif

	vec2 operator+(const vec2 &rhs) const;
	vec2 operator-(const vec2 &rhs) const;
	vec2 operator*(const float rhs) const;
	friend vec2 operator*(const float lhs, const vec2 &rhs);
	vec2 operator/(const float rhs) const;

	vec2 &operator+=(const vec2 &rhs);
	vec2 &operator-=(const vec2 &rhs);
	vec2 &operator*=(const float rhs);
	vec2 &operator/=(const float rhs);

	bool operator==(const vec2 &rhs) const;
	bool operator!=(const vec2 &rhs) const;

	vec2 operator-() const;


	vec2();
	vec2(float a, float b);

	float magnitude() const;
	float dot(const vec2 &rhs) const;

	vec2 &normalize();
	vec2 getNormalized() const;

	vec2 &scale(const vec2 &rhs);
	vec2 getScaled(const vec2 &rhs) const;

	operator float *();
	operator const float *() const;

};
vec2 operator*(const float lhs, const vec2 &rhs);
