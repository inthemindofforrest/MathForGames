#include "Vec2.h"

vec2::vec2()
{
	x = y = 0;
}
vec2::vec2(float a, float b)
{
	x = a;
	y = b;
}
float vec2::magnitude() const
{
	return(sqrt(x * x + y * y));
}
float vec2::dot(const vec2 &rhs) const
{
	return ((x * rhs.x) + (y * rhs.y));
}
vec2 & vec2::normalize()
{
	return (*this = {x /= magnitude(),y /= magnitude()});
}
vec2 vec2::getNormalized() const
{
	return {x / magnitude(), y / magnitude()};
}
vec2 & vec2::scale(const vec2 & rhs)
{
	return (*this = {x *= rhs.x, y *= rhs.y});
}
vec2 vec2::getScaled(const vec2 & rhs) const
{
	return {x * rhs.x, y * rhs.y};
}
vec2::operator float*()
{
	return &x;
}
vec2::operator const float*() const
{
	return &x;
}
float vec2::angleBetween(const vec2 & rhs) const
{
	return(dot(rhs) / (magnitude() * rhs.magnitude()));
}
vec2 vec2::getPerpCW() const
{
	return{ y, -x };
}
vec2 vec2::getPerpCCW() const
{
	return{ -y, x };
}
vec2 vec2::operator+(const vec2 & rhs) const
{
	return{ x + rhs.x, y + rhs.y };
}
vec2 vec2::operator-(const vec2 & rhs) const
{
	return{ x - rhs.x, y - rhs.y };
}
vec2 vec2::operator*(const float rhs) const
{
	return {x * rhs, y * rhs};
}
vec2 vec2::operator/(const float rhs) const
{
	return {x / rhs, y / rhs};
}
vec2 & vec2::operator+=(const vec2 & rhs)
{
	return (*this = {x + rhs.x, y + rhs.y});
}
vec2 & vec2::operator-=(const vec2 & rhs)
{
	return (*this = {x - rhs.x, y - rhs.y});
}
vec2 & vec2::operator*=(const float rhs)
{
	return(*this = { x * rhs, y * rhs });
}
vec2 & vec2::operator/=(const float rhs)
{
	return(*this = { x / rhs, y / rhs });
}
bool vec2::operator==(const vec2 &rhs) const
{
	vec2 temp = *this - rhs;
	return (fAbs(temp.x) < (FLT_EPSILON * 10) && fAbs(temp.y) < (FLT_EPSILON * 10));
}
bool vec2::operator!=(const vec2 &rhs) const
{
	return(!(*this == rhs));
}
vec2 vec2::operator-() const
{
	return{ -x, -y };
}
vec2 operator*(const float lhs, const vec2 & rhs)
{
	return {rhs.x * lhs,rhs.y * lhs};
}

