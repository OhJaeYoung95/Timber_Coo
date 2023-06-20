#include "Scene.h"

Scene::Scene(SceneType _type) : type(_type), blinkTimer(0.5f)
{
	
}

Scene::~Scene()
{
}

void Scene::SetTexture(sf::Sprite& sprite, sf::Texture& tex)
{
	sprite.setTexture(tex);
}

void Scene::Blink(float dt)
{
	blinkTimer -= dt;
	if (blinkTimer < -0.3f)
		blinkTimer = 0.5f;
}