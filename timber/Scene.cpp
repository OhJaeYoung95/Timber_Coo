#include "Scene.h"

Scene::Scene(SceneType _type) : type(_type)
{
	
}

Scene::~Scene()
{
}

void Scene::SetTexture(sf::Sprite& sprite, sf::Texture& tex)
{
	sprite.setTexture(tex);
}