#pragma once
#include "Transform2D.h"
#include "raylib.h"
#include <iostream>
#include <vector>
#include <string>

struct GameObject
{
	GameObject();
	GameObject(std::string Texture, GameObject* Parent, bool Active);
	GameObject(std::string Texture, bool Active);
	GameObject(GameObject* Parent);

	void addChild(GameObject * child);
	GameObject *getChildren() const;
	size_t getChildrenCount() const;

	void setParent(GameObject *_parent);
	GameObject *getParent() const;

	void Update();


	Texture2D texture;
	transform2d transform;
	bool IsActive;
private:
	GameObject * parent;
	std::vector<GameObject *> children;
};