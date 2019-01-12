#pragma once
#include "Vec2.h"
#include <iostream>
#include <vector>
#include "Matrix3.h"
struct transform2d
{
	//vec2 localPosition() const;
	//float localRotation() const;
	//vec2 localScale() const;

	vec2 localPos;
	float localRot;
	vec2 localScale;

	/*void setLocalPosition(const vec2 &newPos);
	void setLocalRotation(const float newRot);
	void setLocalScale(const vec2 &newScale);*/

	void translate(const vec2& offset);
	void rotate(const float angle);

	vec2 worldPosition() const;
	float worldRotation() const;
	vec2 worldScale() const;

	void setParent(transform2d *_parent);
	transform2d *getParent() const;

	void addChild(transform2d * child);
	transform2d *getChildren() const;
	size_t getChildrenCount() const;

	void lookAt(vec2 target);
	vec2 forward() const;

	mat3 getTRSMatrix() const;
	mat3 getWorldTRSMatrix() const;

	transform2d();
private:
	transform2d * parent;
	std::vector<transform2d *> children;
	
	//[posx][posy][posz]
	//[rotx][roty][rotz]
	//[scax][scay][scaz]
};