#include "Transform2D.h"

vec2 transform2d::localPosition() const
{
	return {trsMatrix.xAxis.x, trsMatrix.xAxis.y};
}
float transform2d::localRotation() const
{
	return tan(trsMatrix.yAxis.y / trsMatrix.yAxis.x);
}
vec2 transform2d::localScale() const
{
	return { trsMatrix.zAxis.x, trsMatrix.zAxis.y };
}
void transform2d::setLocalPosition(const vec2 & newPos)
{
	trsMatrix.xAxis.x = newPos.x;
	trsMatrix.xAxis.y = newPos.y;
}
void transform2d::setLocalRotation(const float newRot)
{
	trsMatrix.set(trsMatrix.rotation(newRot));
}
void transform2d::setLocalScale(const vec2 & newScale)
{
	trsMatrix.zAxis.x = newScale.x;
	trsMatrix.zAxis.y = newScale.y;
}
void transform2d::translate(const vec2 & offset)
{
	trsMatrix.set(trsMatrix.translation(offset));
}
void transform2d::rotate(const float angle)
{
	trsMatrix.set(trsMatrix.rotation(angle + localRotation()));
}

vec2 transform2d::worldPosition() const
{
	return parent->localPosition();
}

float transform2d::worldRotation() const
{
	return parent->localRotation();
}

vec2 transform2d::worldScale() const
{
	return parent->localScale();
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
