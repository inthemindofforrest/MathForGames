#pragma once
#include "Vec3.h"
#include "Vec4.h"
struct mat4
{
	union
	{
		struct
		{
			vec4 xAxis;
			vec4 yAxis;
			vec4 zAxis;
			vec4 wAxis;
		};
		vec4 axis[4];
		struct
		{
			float m1, m2, m3,m4, 
				m5, m6, m7, m8,
				m9, m10, m11, m12,
				m13, m14, m15, m16;
		};
		struct
		{
			float m[16];
		};
		struct
		{
			float mm[4][4];
		};
	};

	int Axis;

	mat4();
	mat4(float *ptr);
	mat4(float m1, float m2, float m3, float m4, 
		float m5, float m6, float m7, float m8, 
		float m9, float m10, float m11, float m12,
		float m13, float m14, float m15, float m16);

	// implicit operator to convert mat3 into a float array
	operator float *();

	// returns vec3 objects when accessing by subscript operator
	vec4 &operator[](const int index);

	// concatenates two matrices together and returns the result
	mat4  operator*(const mat4 &rhs) const;
	// concatenates and assigns the result to the matrix
	mat4 &operator*=(const mat4 &rhs);

	// returns true if the matrices are equal
	bool operator==(const mat4 &rhs) const;
	// returns true if the matrices are inequal
	bool operator!=(const mat4 &rhs) const;


	// returns a 3x3 identity matrix
	static mat4 identity();

	// updates the matrix elements with the given values
	void set(float _m1, float _m2, float _m3, float _m4, 
			float _m5, float _m6, float _m7, float _m8, 
			float _m9, float _m10, float _m11, float _m12,
			float _m13, float _m14, float _m15, float _m16);

	// updates the matrix elements with the given values from the given array
	void set(float *ptr);

	// transposes the matrix
	void transpose();
	// returns a transposed copy of the matrix
	mat4 getTranspose();

	// returns a translation matrix with the given changes for each axis
	static mat4 translation(float x, float y, float z);
	// returns a translation matrix with the given changes for each axis
	static mat4 translation(const vec3 &vec);
	// returns a rotation matrix with the given rotation
	static mat4 rotation(float rot, int CurrentAxis);
	// returns a translation matrix with the given changes for each axis
	static mat4 scale(float xScale, float yScale, float zScale);

	// returns a translation matrix with the given changes for x,y axis
	static mat4 scaleBy(float Scaler);

	// transforms a 3D vector by performing 3x3 x 3x1 matrix multiplication
	vec4 operator*(const vec4 &rhs) const;
	// convenience function for transforming a 2D vector
	vec3 operator*(const vec3 &rhs) const;
};