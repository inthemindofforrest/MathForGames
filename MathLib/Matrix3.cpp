#include "Matrix3.h"

mat3::mat3()
{
	for (int i = 0; i < 9; i++)
		m[i] = 0;
}
mat3::mat3(float * ptr)
{
	if (ptr != nullptr)
	{
		for (int i = 0; i < 9; i++)
			m[i] = ptr[i];
	}
}
mat3::mat3(float m1, float m2, float m3, float m4, float m5, float m6, float m7, float m8, float m9)
{
  //mm[y][x]
	mm[0][0] = m1;
	mm[0][1] = m2;
	mm[0][2] = m3;
	mm[1][0] = m4;
	mm[1][1] = m5;
	mm[1][2] = m6;
	mm[2][0] = m7;
	mm[2][1] = m8;
	mm[2][2] = m9;
}
mat3::operator float*()
{
	float *ptr = m;
	return ptr;
}
vec3 & mat3::operator[](const int index)
{
	return axis[index];
}
mat3 mat3::operator*(const mat3 & rhs) const
{
	int RowCol = 3;
	mat3 Final;
	for (int y = 0; y < RowCol; y++)
		for (int rhsX = 0; rhsX < RowCol; rhsX++)
			for (int xy = 0; xy < RowCol; xy++)
				Final.mm[y][rhsX] += mm[y][xy] * rhs.mm[xy][rhsX];
	return Final;
}
mat3 & mat3::operator*=(const mat3 & rhs)
{
	return (*this = *this * rhs);
}
bool mat3::operator==(const mat3 & rhs) const
{
	for (int i = 0; i < 9; i++)
		if (m[i] - rhs.m[i] > FLT_EPSILON * 1000)
			return false;
	return true;
}
bool mat3::operator!=(const mat3 & rhs) const
{
	return !(*this == rhs);
}
mat3 mat3::identity()
{
	return mat3(1,0,0,
				0,1,0,
				0,0,1);
}
void mat3::set(float _m1, float _m2, float _m3, float _m4, float _m5, float _m6, float _m7, float _m8, float _m9)
{
	m1 = _m1;
	m2 = _m2;
	m3 = _m3;
	m4 = _m4;
	m5 = _m5;
	m6 = _m6;
	m7 = _m7;
	m8 = _m8;
	m9 = _m9;
}
void mat3::set(float * ptr)
{
	int mat = 3;
	for (int i = 0; i < mat * mat; i++)
		m[i] = ptr[i];
}
void mat3::transpose()
{
	set(getTranspose());
}
mat3 mat3::getTranspose()
{
	int RowCol = 3;
	mat3 Final;
	for (int i = 0; i < RowCol; i++)
		for (int j = 0; j < RowCol; j++)
			Final.mm[i][j] = mm[j][i];
	return Final;
}
mat3 mat3::translation(float x, float y)
{
	return mat3(1,0,x,
				0,1,y,
				0,0,1);
}
mat3 mat3::translation(const vec2 & vec)
{
	return translation(vec.x, vec.y);
}
mat3 mat3::rotation(float rot, int Axis)
{
	if (Axis == 0)//Rotate on X
	{
		return mat3(1, 0, 0,
			0, (float)cos(rot), (float)sin(rot), 
			0, (float)-sin(rot), (float)cos(rot));
	}
	else if (Axis == 1)//Rotate on Y
	{
		return mat3((float)cos(rot), 0, (float)-sin(rot),
			0, 1, 0,
			(float)sin(rot), 0, (float)cos(rot));
	}
	else if (Axis == 2)//Rotate on Z
	{
		return mat3((float)cos(rot), (float)-sin(rot), 0,
			(float)sin(rot), (float)cos(rot), 0,
			0, 0, 1);
	}
	else
	{
		return identity();
	}
}
mat3 mat3::scale(float xScale, float yScale)
{
	return mat3(xScale, 0, 0, 0, yScale, 0, 0, 0, 1);
	
}
mat3 mat3::scaleBy(float Scaler)
{
	return mat3(Scaler, 0, 0, 0, Scaler, 0, 0, 0, 1);
}
vec3 mat3::operator*(const vec3 & rhs) const
{
	int RowCol = 3;
	vec3 Final;
	for (int y = 0; y < RowCol; y++)
		for (int rhsX = 0; rhsX < RowCol; rhsX++)
				Final[y] += mm[y][rhsX] * rhs[rhsX];
	return Final;
}
vec2 mat3::operator*(const vec2 & rhs) const
{
	int RowCol = 2;
	vec2 Final;
	for (int y = 0; y < RowCol; y++)
		for (int rhsX = 0; rhsX < RowCol; rhsX++)
			Final[y] += mm[y][rhsX] * rhs[rhsX];
	return Final;
}