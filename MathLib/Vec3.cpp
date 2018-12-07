#include "vec3.h"

vec3::vec3()
{
	x = y = z = 0;
}

vec3::vec3(float a, float b, float c)
{
	x = a;
	y = b;
	z = c;
}


//float vec3::magnitude() const
//{
//
//}

float vec3::magnitude() const
{
	return(sqrt(x * x + y * y + z * z));
}

float vec3::dot(const vec3 &rhs) const
{
	return (x * rhs.x + y * rhs.y + z * rhs.z);
}


//float & vec3::operator[](size_t idx)
//{
//	float temp[] = { x, y, z };
//	return temp[idx];
//}
//
//float vec3::operator[](size_t idx) const
//{
//	float temp[] = { x, y, z };
//	return temp[idx];
//}

vec3::operator float*()
{
	return &x;
}

vec3::operator const float*() const
{
	return &x;
}

vec3 & vec3::normalize()
{
	x /= magnitude();
	y /= magnitude();
	z /= magnitude();
	return *this;
}

vec3 vec3::operator+(const vec3 & rhs) const
{
	return{ x + rhs.x, y + rhs.y , z + rhs.z};
}

vec3 vec3::operator-(const vec3 & rhs) const
{
	return{ x - rhs.x, y - rhs.y, z - rhs.z };
}

vec3 & vec3::operator+=(const vec3 & rhs)
{
	x += rhs.x;
	y += rhs.y;
	z += rhs.z;
	return *this;
}

vec3 & vec3::operator-=(const vec3 & rhs)
{
	x -= rhs.x;
	y -= rhs.y;
	z -= rhs.z;
	return *this;
}

bool vec3::operator==(const vec3 &rhs) const
{
	vec3 temp = *this - rhs;
	return (fAbs(temp.x) < (FLT_EPSILON * 10) && fAbs(temp.y) < (FLT_EPSILON * 10) && fAbs(temp.z) < (FLT_EPSILON * 10));
}

bool vec3::operator!=(const vec3 &rhs) const
{
	return(!(*this == rhs));
}

vec3 vec3::operator-() const
{
	return{ -x, -y, -z };
}
