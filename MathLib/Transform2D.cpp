#include "Transform2D.h"
#include "UtilsPi.h"
#include <stack>

transform2d::transform2d()
{
	localPos = { 0,0 };
	localRot = 0;
	localScale = {1, 1};

	parent = nullptr;
}
void transform2d::translate(const vec2 & offset)
{
	mat3 MyTemp = MyTemp.translation(offset);
	localPos += {MyTemp.mm[0][2], MyTemp.mm[1][2]};
}
void transform2d::rotate(const float angle)
{
	mat3 MyTemp = getTRSMatrix();
	MyTemp = MyTemp.rotation(angle, 2);
	localRot += atan2f(MyTemp.m4,MyTemp.m1);

}
vec2 transform2d::worldPosition() const
{


	if (parent == nullptr)
		return localPos;

	mat3 MyMat = mat3::identity();

	for (transform2d * CurrentParent = parent; CurrentParent != nullptr; CurrentParent = CurrentParent->parent)
		MyMat *= mat3::translation(parent->localPos);

	return vec2(MyMat.mm[0][2], MyMat.mm[1][2]);
}
float transform2d::worldRotation() const
{
	if (parent == nullptr)
		return atan2f(getTRSMatrix().mm[1][0], getTRSMatrix().mm[0][0]);

	mat3 Temp = getWorldTRSMatrix() * getTRSMatrix();
	return atan2f(Temp.mm[1][0], Temp.mm[0][0]);
}
vec2 transform2d::worldScale() const
{
	return { sqrt((getWorldTRSMatrix().m1 * getWorldTRSMatrix().m1) + (getWorldTRSMatrix().m4 * getWorldTRSMatrix().m4)),
		sqrt((getWorldTRSMatrix().m2 * getWorldTRSMatrix().m2) + (getWorldTRSMatrix().m5 * getWorldTRSMatrix().m5)) };
}
void transform2d::setParent(transform2d * _parent)
{
	parent = _parent;
}
transform2d * transform2d::getParent() const
{
	return parent;
}
void transform2d::addChild(transform2d * child)
{
	children.push_back(child);
}
transform2d * transform2d::getChildren() const
{
	if(children.size() > 0)
		return children[0];
	return nullptr;
}
size_t transform2d::getChildrenCount() const
{
	return children.size();
}
void transform2d::lookAt(vec2 target)
{
	localRot = atan2(target.y - localPos.y, target.x - localPos.x);
}
vec2 transform2d::forward() const
{
	return vec2({(float)cos(localRot),(float)sin(localRot)}).normalize();
}
mat3 transform2d::getTRSMatrix() const
{
	return mat3::translation(localPos) * mat3::rotation(localRot, 2) * mat3::scale(localScale.x, localScale.y);
}
mat3 transform2d::getWorldTRSMatrix() const
{
	if (getParent() != nullptr)
		return parent->getWorldTRSMatrix() * getTRSMatrix();
	return getTRSMatrix();
}

