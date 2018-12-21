#include "Transform3D.h"

vec3 transform3d::localPosition() const
{
	return vec3(trsMatrix.mm[0][0], trsMatrix.mm[0][1], trsMatrix.mm[0][2]);
}
vec3 transform3d::localRotation() const
{
	return vec3(trsMatrix.mm[1][0], trsMatrix.mm[1][1], trsMatrix.mm[1][2]);
}
vec3 transform3d::localScale() const
{
	return vec3(trsMatrix.mm[2][0], trsMatrix.mm[2][1], trsMatrix.mm[2][2]);
}
void transform3d::setLocalPosition(const vec3 & newPos)
{
	trsMatrix.mm[0][0] = newPos.x;
	trsMatrix.mm[0][1] = newPos.y;
	trsMatrix.mm[0][2] = newPos.z;
}
void transform3d::setLocalRotation(const vec3 & newRot)
{
	trsMatrix.mm[1][0] = newRot.x;
	trsMatrix.mm[1][1] = newRot.y;
	trsMatrix.mm[1][2] = newRot.z;
}
void transform3d::setLocalScale(const vec3 & newScale)
{
	trsMatrix.mm[2][0] = newScale.x;
	trsMatrix.mm[2][1] = newScale.y;
	trsMatrix.mm[2][2] = newScale.z;
}
vec3 transform3d::forward() const
{
	return vec3(0, 0, 1);
}
void transform3d::setForward(const vec3 & newForward)
{
	setLocalRotation(newForward);
}
vec3 transform3d::right() const
{
	return vec3(1, 0, 0);
}
void transform3d::setRight(const vec3 & newRight)
{
	setLocalRotation(newRight);
}
vec3 transform3d::up() const
{
	return vec3(0, 1, 0);
}
void transform3d::setUp(const vec3 & newUp)
{
	setLocalRotation(newUp);
}
void transform3d::translate(const vec3 & offset)
{
	trsMatrix.set(trsMatrix.translation(offset));
}
void transform3d::rotate(const vec3 & rot)
{
	trsMatrix.set(trsMatrix * trsMatrix.rotation(rot.x, 0));
	trsMatrix.set(trsMatrix * trsMatrix.rotation(rot.y, 1));
	trsMatrix.set(trsMatrix * trsMatrix.rotation(rot.z, 2));
}
