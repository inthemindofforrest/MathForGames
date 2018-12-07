#include "vec4.h"

vec4::vec4()
{
	x = y = z = w = 0;
}

vec4::vec4(float a, float b, float c, float d)
{
	x = a;
	y = b;
	z = c;
	w = d;
}


//float vec4::magnitude() const
//{
//
//}

float vec4::dot(const vec4 &rhs) const
{
	return (x * rhs.x + y * rhs.y + z * rhs.z + w - rhs.w);
}

//float & vec4::operator[](size_t idx)
//{
//	float temp[] = { x, y, z, w };
//	return temp[idx];
//}
//
//float vec4::operator[](size_t idx) const
//{
//	float temp[] = { x, y, z, w };
//	return temp[idx];
//}

vec4::operator float*()
{
	return &x;
}

vec4::operator const float*() const
{
	return &x;
}

vec4 vec4::operator+(const vec4 & rhs) const
{
	return{ x + rhs.x, y + rhs.y , z + rhs.z, w + rhs.w };
}

vec4 vec4::operator-(const vec4 & rhs) const
{
	return{ x - rhs.x, y - rhs.y, z - rhs.z, w - rhs.w };
}

vec4 & vec4::operator+=(const vec4 & rhs)
{
	x += rhs.x;
	y += rhs.y;
	z += rhs.z;
	w += rhs.w;
	return *this;
}

vec4 & vec4::operator-=(const vec4 & rhs)
{
	x -= rhs.x;
	y -= rhs.y;
	z -= rhs.z;
	w -= rhs.w;
	return *this;
}

bool vec4::operator==(const vec4 &rhs) const
{
	vec4 temp = *this - rhs;
	return (fAbs(temp.x) < (FLT_EPSILON * 10) && fAbs(temp.y) < (FLT_EPSILON * 10) 
		&& fAbs(temp.z) < (FLT_EPSILON * 10) && fAbs(temp.w) < (FLT_EPSILON * 10));
}

bool vec4::operator!=(const vec4 &rhs) const
{
	return(!(*this == rhs));
}

vec4 vec4::operator-() const
{
	return{ -x, -y, -z, -w };
}
