#pragma once
#include <SFML/Graphics.hpp>
#include "Defines.h"

class Scene
{
protected:
	SceneType type;
public:
	Scene(SceneType _type);
	virtual ~Scene();

	virtual void Init() = 0;
	virtual void Release() = 0;
	virtual void Update(float dt) = 0;
	virtual void Draw(sf::RenderWindow& window) = 0;
};