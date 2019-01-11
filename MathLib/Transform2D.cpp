#include "Transform2D.h"

transform2d::transform2d()
{
	localPos = { 0,0 };
	localRot = 0;
	localScale = {1, 1};

	parent = nullptr;
}
void transform2d::translate(const vec2 & offset)
{
	localPos += offset;
}
void transform2d::rotate(const float angle)
{
	localRot = angle + localRot;
}
vec2 transform2d::worldPosition() const
{
	vec2 CurrentPos = { 0,0 };
	if (parent == nullptr)
		return localPos;

	transform2d * CurrentParent = parent;
	while (CurrentParent != nullptr)
	{
		CurrentPos.x += CurrentParent->localPos.x + localPos.x * cos(parent->localRot);
		CurrentPos.y += CurrentParent->localPos.y + localPos.y * sin(parent->localRot);
		CurrentParent = CurrentParent->parent;
	}
	delete CurrentParent;

	return CurrentPos;
}
float transform2d::worldRotation() const
{
	float CurrentRot = localRot;
	if (parent != nullptr)
	{
		transform2d * CurrentParent = parent;
		while (CurrentParent != nullptr)
		{
			CurrentRot += CurrentParent->localRot;
			CurrentParent = CurrentParent->parent;
		}
		delete CurrentParent;
	}
	return CurrentRot;
}
vec2 transform2d::worldScale() const
{
	vec2 CurrentScale = localScale;
	if (parent != nullptr)
	{
		transform2d * CurrentParent = parent;
		while (CurrentParent != nullptr)
		{
			CurrentScale.x *= CurrentParent->localScale.x;
			CurrentScale.y *= CurrentParent->localScale.y;
			CurrentParent = CurrentParent->parent;
		}
		delete CurrentParent;
	}
	return CurrentScale;
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
	return mat3(localPos.x, localPos.y,     0,
				     0,           0,     localRot,
				localScale.x, localScale.y, localScale.y);
}


