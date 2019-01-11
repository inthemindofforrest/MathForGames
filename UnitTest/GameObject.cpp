#include "GameObject.h"

GameObject::GameObject(){}

GameObject::GameObject(std::string Texture, GameObject* Parent, bool Active)
{
	texture = LoadTexture(Texture.c_str());
	setParent(Parent);
	IsActive = Active;

	transform.localPos = { 0,0 };
	transform.localRot = 0;
	transform.localScale = { 1,1 };
}

GameObject::GameObject(std::string Texture, bool Active)
{
	texture = LoadTexture(Texture.c_str());
	IsActive = Active;
}

GameObject::GameObject(GameObject * Parent)
{
	setParent(Parent);
}

void GameObject::addChild(GameObject * child)
{
	transform.addChild(&child->transform);
	children.push_back(child);
	child->setParent(this);
}

GameObject * GameObject::getChildren() const
{
	if (children.size() > 0)
		return children[0];
	return nullptr;
}

size_t GameObject::getChildrenCount() const
{
	return children.size();
}

void GameObject::setParent(GameObject * _parent)
{
	transform.setParent(&_parent->transform);
	parent = _parent;
}

GameObject * GameObject::getParent() const
{
	return parent;
}

void GameObject::Update()
{
	if (IsActive)
	{
		//DrawTexture(texture, transform.localPos.x, transform.localPos.y, WHITE);
		DrawTexturePro(texture, { 0,0,(float)texture.width,(float)texture.height },
			{ (float)transform.worldPosition().x,(float)transform.worldPosition().y,(float)texture.width * (float)transform.localScale.x,(float)texture.height * (float)transform.localScale.y },
			{ (float)texture.width / 2, (float)texture.height / 2 }, (float)transform.worldRotation() + 90, WHITE);
		for (int i = 0; i < getChildrenCount(); i++)
			if (getChildren()[i].IsActive)
				DrawTexturePro(getChildren()[i].texture, { 0,0,(float)getChildren()[i].texture.width,(float)getChildren()[i].texture.height },
					{ (float)getChildren()[i].transform.worldPosition().x,(float)getChildren()[i].transform.worldPosition().y,(float)getChildren()[i].texture.width * (float)getChildren()[i].transform.localScale.x,(float)getChildren()[i].texture.height * (float)getChildren()[i].transform.localScale.y },
					{ (float)getChildren()[i].texture.width / 2, (float)getChildren()[i].texture.height }, (float)getChildren()[i].transform.worldRotation() + 90, WHITE);
	}
}
