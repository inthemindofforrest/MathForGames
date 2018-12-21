#include "Matrix4.h"

mat4::mat4()
{
	for (int i = 0; i < 16; i++)
		m[i] = 0;
}
mat4::mat4(float * ptr)
{
	if (ptr != nullptr)
	{
		for (int i = 0; i < 16; i++)
			m[i] = ptr[i];
	}
}
mat4::mat4(float m1, float m2, float m3, float m4, float m5, float m6, float m7, float m8, float m9, float m10, float m11, float m12, float m13, float m14, float m15, float m16)
{
	//mm[y][x]
	mm[0][0] = m1;
	mm[0][1] = m2;
	mm[0][2] = m3;
	mm[0][3] = m4;
	mm[1][0] = m5;
	mm[1][1] = m6;
	mm[1][2] = m7;
	mm[1][3] = m8;
	mm[2][0] = m9;
	mm[2][1] = m10;
	mm[2][2] = m11;
	mm[2][3] = m12;
	mm[3][0] = m9;
	mm[3][1] = m10;
	mm[3][2] = m11;
	mm[3][3] = m12;
	mm[3][0] = m13;
	mm[3][1] = m14;
	mm[3][2] = m15;
	mm[3][3] = m16;
}
mat4::operator float*()
{
	float *ptr = m;
	return ptr;
}
vec4 & mat4::operator[](const int index)
{
	vec4 temp{ mm[0][index], mm[1][index] ,mm[2][index], mm[3][index] };
	return temp;
}
mat4 mat4::operator*(const mat4 & rhs) const
{
	int RowCol = 4;
	mat4 Final;
	for (int y = 0; y < RowCol; y++)
		for (int rhsX = 0; rhsX < RowCol; rhsX++)
			for (int xy = 0; xy < RowCol; xy++)
				Final.mm[y][rhsX] += mm[y][xy] * rhs.mm[xy][rhsX];
	return Final;
}
mat4 & mat4::operator*=(const mat4 & rhs)
{
	return (*this = *this * rhs);
}
bool mat4::operator==(const mat4 & rhs) const
{
	for (int i = 0; i < 16; i++)
		if (m[i] != rhs.m[i])
			return false;
	return true;
}
bool mat4::operator!=(const mat4 & rhs) const
{
	return !(*this == rhs);
}
mat4 mat4::identity()
{
	return mat4(1, 0, 0, 0,
				0, 1, 0, 0,
				0, 0, 1, 0,
				0, 0, 0, 1);
}
void mat4::set(float _m1, float _m2, float _m3, float _m4, float _m5, float _m6, float _m7, float _m8, float _m9,float _m10, float _m11, float _m12, float _m13, float _m14, float _m15, float _m16)
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
	m10 = _m10;
	m11 = _m11;
	m12 = _m12;
	m13 = _m13;
	m14 = _m14;
	m15 = _m15;
	m16 = _m16;
}
void mat4::set(float * ptr)
{
	int mat = 4;
	for (int i = 0; i < mat * mat; i++)
		m[i] = ptr[i];
}
void mat4::transpose()
{
	set(getTranspose());
}
mat4 mat4::getTranspose()
{
	int RowCol = 4;
	mat4 Final;
	for (int i = 0; i < RowCol; i++)
		for (int j = 0; j < RowCol; j++)
			Final.mm[i][j] = mm[j][i];
	return Final;
}
mat4 mat4::translation(float x, float y, float z)
{
	return mat4(1, 0, 0, x,
				0, 1, 0, y,
				0, 0, 1, z,
				0, 0, 0, 1);
}
mat4 mat4::translation(const vec3 & vec)
{
	return translation(vec.x, vec.y, vec.z);
}
mat4 mat4::rotation(float rot, int CurrentAxis)
{
	if (CurrentAxis == 0)//Rotate on X
	{
		return mat4(1,    0,         0,     0,
					0, cos(rot), -sin(rot), 0,
					0, sin(rot), cos(rot),  0,
					0,    0,        0,      1);
	}
	else if (CurrentAxis == 1)//Rotate on Y
	{
		return mat4(cos(rot),       0,     sin(rot), 0,
					   0,           1,        0,     0,
				   -sin(rot),       0,     cos(rot), 0,
					    0,          0,        0,     1);
	}
	else if (CurrentAxis == 2)//Rotate on Z
	{
		return mat4(cos(rot), -sin(rot), 0, 0,
			        sin(rot), cos(rot),  0, 0,
			           0,        0,      1, 0,
			           0,        0,      0, 1);
	}
	else
	{
		return identity();
	}
}
mat4 mat4::scale(float xScale, float yScale, float zScale)
{
	return mat4(xScale, 0, 0, 0,
				0, yScale, 0, 0,
				0, 0, zScale, 0,
				0, 0,    0,   1);

}
mat4 mat4::scaleBy(float Scaler)
{
	return mat4(Scaler, 0, 0, 0,
				0, Scaler, 0, 0,
				0, 0, Scaler, 0,
				0, 0,   0,    1);
}
vec4 mat4::operator*(const vec4 & rhs) const
{
	int RowCol = 4;
	vec4 Final;
	for (int y = 0; y < RowCol; y++)
		for (int rhsX = 0; rhsX < RowCol; rhsX++)
			Final[y] += mm[y][rhsX] * rhs[rhsX];
	return Final;
}
vec3 mat4::operator*(const vec3 & rhs) const
{
	int RowCol = 3;
	vec3 Final;
	for (int y = 0; y < RowCol; y++)
		for (int rhsX = 0; rhsX < RowCol; rhsX++)
			Final[y] += mm[y][rhsX] * rhs[rhsX];
	return Final;
}