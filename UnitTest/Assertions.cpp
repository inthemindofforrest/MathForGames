#include "Assertions.h"


bool UtilsAssert()
{
	assert(moveTowards(0, 25, 16) == 16);
	return false;
}

bool TerryAssertion()
{
	// vector addition
	vec2 v2a(13.5f, -48.23f), v2b(5, 3.99f), v2c;
	v2c = v2a + v2b;
	vec3 v3a(13.5f, -48.23f, 862), v3b(5, 3.99f, -12), v3c;
	v3c = v3a + v3b;
	vec4 v4a(13.5f, -48.23f, 862, 0), v4b(5, 3.99f, -12, 1), v4c;
	v4c = v4a + v4b;

	TEST("vec2 addition", v2c, vec2(18.5f, -44.24f));
	TEST("vec3 addition", v3c, vec3(18.5f, -44.24f, 850));
	TEST("vec4 addition", v4c, vec4(18.5f, -44.24f, 850, 1));

	// vector subtraction
	v2a = vec2(13.5f, -48.23f);
	v2b = vec2(5, 3.99f);
	v2c = v2a - v2b;
	v3a = vec3(13.5f, -48.23f, 862);
	v3b = vec3(5, 3.99f, -12);
	v3c = v3a - v3b;
	v4a = vec4(13.5f, -48.23f, 862, 0);
	v4b = vec4(5, 3.99f, -12, 1);
	v4c = v4a - v4b;

	TEST("vec2 subtraction", v2c, vec2(8.5f, -52.22f));
	TEST("vec3 subtraction", v3c, vec3(8.5f, -52.22f, 874));
	TEST("vec4 subtraction", v4c, vec4(8.5f, -52.22f, 874, -1));

	// vector post-scale
	v2a = vec2(13.5f, -48.23f);
	v2c = v2a * 2.482f;
	v3a = vec3(13.5f, -48.23f, 862);
	v3c = v3a * 0.256f;
	v4a = vec4(13.5f, -48.23f, 862, 0);
	v4c = v4a * 4.89f;

	TEST("vec2 post-scale", v2c, vec2(33.5069999695f, -119.706863403f));
	TEST("vec3 post-scale", v3c, vec3(3.45600008965f, -12.3468809128f, 220.672012329f));
	TEST("vec4 post-scale", v4c, vec4(66.0149993896f, -235.844696045f, 4215.1796875f, 0));

	// vector pre-scale
	v2a = vec2(13.5f, -48.23f);
	v2c = 2.482f * v2a;
	v3a = vec3(13.5f, -48.23f, 862);
	v3c = 0.256f * v3a;
	v4a = vec4(13.5f, -48.23f, 862, 0);
	v4c = 4.89f * v4a;

	TEST("vec2 pre-scale", v2c, vec2(33.5069999695f, -119.706863403f));
	TEST("vec3 pre-scale", v3c, vec3(3.45600008965f, -12.3468809128f, 220.672012329f));
	TEST("vec4 pre-scale", v4c, vec4(66.0149993896f, -235.844696045f, 4215.1796875f, 0));

	// vector dot product
	v2a = vec2(13.5f, -48.23f);
	v2b = vec2(5, 3.99f);
	float dot2 = v2a.dot(v2b);
	v3a = vec3(13.5f, -48.23f, 862);
	v3b = vec3(5, 3.99f, -12);
	float dot3 = v3a.dot(v3b);
	v4a = vec4(13.5f, -48.23f, 862, 0);
	v4b = vec4(5, 3.99f, -12, 1);
	float dot4 = v4a.dot(v4b);

	TEST("vec2 dot", dot2, -124.937698364f);
	TEST("vec3 dot", dot3, -10468.9375f);
	TEST("vec4 dot", dot4, -10468.9375f);

	// vector cross product
	v3a = vec3(13.5f, -48.23f, 862);
	v3b = vec3(5, 3.99f, -12);
	v3c = v3a.cross(v3b);
	v4a = vec4(13.5f, -48.23f, 862, 0);
	v4b = vec4(5, 3.99f, -12, 1);
	v4c = v4a.cross(v4b);

	TEST("vec3 cross", v3c, vec3(-2860.62012f, 4308.50000000f, 295.014984f));
	TEST("vec4 cross", v4c, vec4(-2860.62012f, 4472.00000000f, 295.014984f, 0));

	// vector magnitude
	v2a = vec2(13.5f, -48.23f);
	float mag2 = v2a.magnitude();
	v3a = vec3(13.5f, -48.23f, 862);
	float mag3 = v3a.magnitude();
	v4a = vec4(13.5f, -48.23f, 862, 0);
	float mag4 = v4a.magnitude();

	TEST("vec2 magnitude", mag2, 50.0837593079f);
	TEST("vec3 magnitude", mag3, 863.453735352f);
	TEST("vec4 magnitude", mag4, 863.453735352f);

	// vector normalize
	v2a = vec2(-13.5f, -48.23f);
	v2a.normalize();
	v3a = vec3(13.5f, -48.23f, 862);
	v3a.normalize();
	v4a = vec4(243, -48.23f, 862, 0);
	v4a.normalize();

	TEST("vec2 normalize", v2a, vec2(-0.269548f, -0.962987f));
	TEST("vec3 normalize", v3a, vec3(0.0156349f, -0.0558571f, 0.998316f));
	TEST("vec4 normalize", v4a, vec4(0.270935f, -0.0537745f, 0.961094f, 0));

	// matrix rotation
	mat3 m3a, m3b, m3c, m3d;
	mat4 m4a, m4b, m4c, m4d;
	m3a.transpose();
	m3a = m3a.rotation(3.98f,0);
	m4a = m4a.rotation(4.5f,0);
	m3b = m3b.rotation(1.76f,1);
	m4b = m4b.rotation(-2.6f,1);
	m3c = m3c.rotation(9.62f,2);
	m4c = m4c.rotation(0.72f,2);

	TEST("mat3 set rotate", m3a, mat3(1, 0, 0, 0, -0.668647945, -0.743579149, 0, 0.743579149, -0.668647945));
	TEST("mat3 set rotate", m3b, mat3(-0.188077f, 0, -0.982154f, 0, 1, 0, 0.982154f, 0, -0.188077f));
	TEST("mat3 set rotate", m3c, mat3(-0.981004655f, -0.193984255f, 0, 0.193984255f, -0.981004655f, 0, 0, 0, 1));
	TEST("mat4 set rotate", m4a, mat4(1, 0, 0, 0, 0, -0.210795805f, -0.977530122f, 0, 0, 0.977530122f, -0.210795805f, 0, 0, 0, 0, 1));
	TEST("mat4 set rotate", m4b, mat4(-0.856888711f, 0, 0.515501440f, 0, 0, 1, 0, 0, -0.515501440f, 0, -0.856888711f, 0, 0, 0, 0, 1));
	TEST("mat4 set rotate", m4c, mat4(0.751805723f, 0.659384668f, 0, 0, -0.659384668f, 0.751805723f, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1));
	// vector transform
	v2a = vec2(13.5f, -48.23f);
	v3a = vec3(13.5f, -48.23f, 862);
	m3b.transpose();
	m3c.transpose();
	v3b = m3b * v3a;
	v3c = m3c * v3a;
	v4a = vec4(13.5f, -48.23f, 862, 0);
	m4b.transpose();
	m4c.transpose();
	v4b = m4b * v4a;
	v4c = m4c * v4a;

	TEST("Vector3 matrix transform", v3b, vec3(844.077941895f, -48.2299995422f, -175.38130188f));
	TEST("Vector3 matrix transform", v3c, vec3(-22.5994224548f, 44.6950683594f, 862));
	TEST("Vector4 matrix transform", v4b, vec4(-455.930236816f, -48.2299995422f, -731.678771973f, 0));
	TEST("Vector4 matrix transform", v4c, vec4(41.951499939f, -27.3578968048f, 862, 0));

	// matrix multiply
	m3a.transpose();
	m3c.transpose();

	m3d = m3a * m3c;
	m4d = m4c * m4b;

	m3d.transpose();
	m4d.transpose();

	TEST("mat3 multiply", m3d, mat3(-0.981004655361f, 0.129707172513f, 0.14424264431f, 
									0.193984255195f, 0.655946731567f, 0.729454636574f, 
									0, 0.743579149246f, -0.668647944927f));
	TEST("mat4 multiply", m4d, mat4(-0.644213855267f, -0.565019249916f, 0.515501439571f, 0,
									-0.659384667873f, 0.751805722713f, 0, 0, 
									-0.387556940317f, -0.339913755655f, -0.856888711452f, 0, 
									0, 0, 0, 1));

	// homogeneous point translation
				m3b = mat3(1, 0, 0,
		0, 1, 0,
		0, 0, 1);
	m3b[2] = vec3(55, 44, 1);
	m3c.rotation(2.2f, 2);
	m3c[2] = vec3(55, 44, 1);
	m4b = mat4(1, 0, 0, 0,
		0, 1, 0, 0,
		0, 0, 1, 0,
		0, 0, 0, 1);
	m4b[3] = vec4(55, 44, 99, 1);
	m4c.rotation(2.2f,2);
	m4c[3] = vec4(55, 44, 99, 1);

	v3a = vec3(13.5f, -48.23f, 1);
	v3b = m3b * v3a;
	v3c = m3c * v3a;
	v4a = vec4(13.5f, -48.23f, -54, 1);
	v4b = m4b * v4a;
	v4c = m4c * v4a;

	TEST("vec3 matrix translation A", v3b, vec3(68.5f, -4.23f, 1));
	TEST("vec3 matrix translation B", v3c, vec3(86.0490112305f, 83.2981109619f, 1));
	TEST("vec4 matrix translation A", v4b, vec4(68.5f, -4.23f, 45, 1));
	TEST("vec4 matrix translation B", v4c, vec4(86.0490112305f, 83.2981109619f, 45, 1));

	// homogeneous vector translation
	m3b = mat3(1, 0, 0,
		0, 1, 0,
		0, 0, 1);
	m3b[2] = vec3(55, 44, 1);
	m3c.rotation(2.2f, 2);
	m3c[2] = vec3(55, 44, 1);
	m4b = mat4(1, 0, 0, 0,
		0, 1, 0, 0,
		0, 0, 1, 0,
		0, 0, 0, 1);
	m4b[3] = vec4(55, 44, 99, 1);
	m4c.rotation(2.2f, 2);
	m4c[3] = vec4(55, 44, 99, 1);

	v3a = vec3(13.5f, -48.23f, 0);
	m3b.transpose();
	m3c.transpose();
	v3b = m3b * v3a;
	v3c = m3c * v3a;
	v4a = vec4(13.5f, -48.23f, -54, 0);
	m4b.transpose();
	m4c.transpose();
	v4b = m4b * v4a;
	v4c = m4c * v4a;

	TEST("vec3 matrix translation C", v3b, vec3(13.5f, -48.23f, 0));
	TEST("vec3 matrix translation D", v3c, vec3(31.0490131378f, 39.2981109619f, 0));
	TEST("vec4 matrix translation C", v4b, vec4(13.5f, -48.23f, -54, 0));
	TEST("vec4 matrix translation D", v4c, vec4(31.0490131378f, 39.2981109619f, -54, 0));

	return true;
}
