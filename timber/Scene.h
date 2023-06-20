#pragma once
#include <SFML/Graphics.hpp>
#include "Defines.h"
#include "SceneManager.h"

class Scene
{
protected:
	SceneType type;
	float blinkTimer;
public:
	Scene(SceneType _type);
	virtual ~Scene();

	virtual void Init() = 0;
	virtual void Release() = 0;
	virtual void Update(float dt, SceneManager& sceneM) = 0;
	virtual void Draw(sf::RenderWindow& window) = 0;

	void SetTexture(sf::Sprite& sprite, sf::Texture& tex);
	void Blink(float dt);
};