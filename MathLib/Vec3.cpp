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
float vec3::magnitude() const
{
	return(sqrt(x * x + y * y + z * z));
}
float vec3::dot(const vec3 &rhs) const
{
	return (x * rhs.x + y * rhs.y + z * rhs.z);
}
vec3 vec3::cross(const vec3 & rhs) const
{
	//[ yz][x z][xy ]
	//[ yz][x z][xy ]
	return {y * rhs.z - z * rhs.y,z * rhs.x - x * rhs.z,x * rhs.y - y - rhs.x };
}
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
	return (*this = {x /= magnitude(), y /= magnitude(), z /= magnitude()});
}
vec3 vec3::getNormalised() const
{
	return{ x / magnitude(), y / magnitude(), z / magnitude() };
}
vec3 & vec3::scale(const vec3 & rhs)
{
	return (*this = { x *= rhs.x, y *= rhs.y, z *= rhs.z });
}
vec3 vec3::getScaled(const vec3 & rhs) const
{
	return { x * rhs.x, y * rhs.y, z * rhs.z };
}
vec3 vec3::operator+(const vec3 & rhs) const
{
	return{ x + rhs.x, y + rhs.y , z + rhs.z};
}
vec3 vec3::operator-(const vec3 & rhs) const
{
	return{ x - rhs.x, y - rhs.y, z - rhs.z };
}
vec3 vec3::operator*(const float rhs) const
{
	return { x * rhs, y * rhs, z * rhs };
}
vec3 vec3::operator/(const float rhs) const
{
	return { x / rhs, y / rhs, z / rhs };
}
vec3 & vec3::operator+=(const vec3 & rhs)
{
	return (*this = {x += rhs.x, y += rhs.y, z += rhs.z});
}
vec3 & vec3::operator-=(const vec3 & rhs)
{
	return (*this = { x -= rhs.x, y -= rhs.y, z -= rhs.z });
}
vec3 & vec3::operator*=(const float rhs)
{
	return(*this = { x *= rhs, y *= rhs, z *= rhs });
}
vec3 & vec3::operator/=(const float rhs)
{
	return(*this = { x /= rhs, y /= rhs, z /= rhs });
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

vec3 operator*(const float lhs, const vec3 & rhs)
{
	return { rhs.x * lhs,rhs.y * lhs, rhs.z * lhs };
}
