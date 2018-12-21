#pragma once
#include "Vec2.h"
#include "Matrix3.h"
struct transform2d
{
	vec2 localPosition() const;
	float localRotation() const;
	vec2 localScale() const;

	void setLocalPosition(const vec2 &newPos);
	void setLocalRotation(const float newRot);
	void setLocalScale(const vec2 &newScale);

	void translate(const vec2& offset);
	void rotate(const float angle);

private:
	mat3 trsMatrix;
	//[posx][posy][posz]
	//[rotx][roty][rotz]
	//[scax][scay][scaz]
};