#pragma once
#include "Scene.h"

class Title : public Scene
{
private:
	sf::Sprite title;
	sf::Text text;

public:
	Title();
	virtual ~Title();

	virtual void Init() override;
	virtual void Release() override;

	virtual void Enter() override;
	virtual void Exit() override;

	virtual void Update(float dt) override;
	virtual void Draw(sf::RenderWindow& window) override;

	void SetTexture(sf::Texture& tex);
};