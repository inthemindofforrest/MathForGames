#include "Transform2D.h"
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
	mat3 MyTemp = getTRSMatrix();

	MyTemp.translation(offset);

	localPos.x = MyTemp.mm[0][2];
	localPos.y = MyTemp.mm[1][2];
}
void transform2d::rotate(const float angle)
{
	/*mat3 MyTemp = getTRSMatrix();

	MyTemp.rotation(angle, 2);

	localRot = atan2f(MyTemp.mm[1][0],MyTemp.mm[0][0]);*/
	localRot = angle + localRot;
}
vec2 transform2d::worldPosition() const
{
	/*vec2 CurrentPos = { 0,0 };
	if (parent == nullptr)
		return localPos;

	std::stack<transform2d*> Parents;
	transform2d * CurrentParent = parent;
	while (CurrentParent != nullptr)
	{
		Parents.push(CurrentParent);
		CurrentParent = CurrentParent->parent;
	}
	while (Parents.size() > 0)
	{
		CurrentPos.x += Parents.top()->localPos.x + (localPos.x * Parents.top()->localScale.x) * cos(Parents.top()->localRot);
		CurrentPos.y += Parents.top()->localPos.y + (localPos.y* Parents.top()->localScale.y) * sin(Parents.top()->localRot);
		Parents.pop();
	}
	delete CurrentParent;

	return CurrentPos;*/

	if (parent == nullptr)
		return localPos;

	mat3 MyMat = mat3::identity();

	for (transform2d * CurrentParent = parent; CurrentParent != nullptr; CurrentParent = CurrentParent->parent)
		MyMat *= mat3::translation(parent->localPos);

	return vec2(MyMat.mm[0][2], MyMat.mm[1][2]);
}
float transform2d::worldRotation() const
{
	/*if (parent != nullptr)
		return localRot;

	mat3 Temp = mat3::identity();

	for (transform2d * CurrentParent = parent; CurrentParent != nullptr; CurrentParent = CurrentParent->parent)
		Temp *= CurrentParent->getTRSMatrix();


	return atan2f(Temp.mm[1][0], Temp.mm[0][0]);*/
	return (parent != nullptr ? localRot + parent->worldRotation() : localRot);

}
vec2 transform2d::worldScale() const
{
	return (parent != nullptr ? vec2(localScale.x * parent->worldScale().x, localScale.y * parent->worldScale().y) : localScale);
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
	return vec2({(float)cos(3.141592653589793238 / 180 * localRot),(float)sin(3.141592653589793238 / 180 * localRot)});
}
mat3 transform2d::getTRSMatrix() const
{
	return mat3::translation(localPos) * mat3::rotation(localRot, 2) * mat3::scale(localScale.x, localScale.y);
}


