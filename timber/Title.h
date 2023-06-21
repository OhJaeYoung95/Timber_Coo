#pragma once
#include "Scene.h"
#include "Utils.h"

class Title : public Scene
{
private:
	sf::Texture titleTex;
	sf::Sprite title;

	sf::Font font;
	sf::Text text;

public:
	Title(SceneType _type);
	virtual ~Title();

	virtual void Init(ModeSelect mode, SceneManager& sceneM) override;
	virtual void Release() override;
	virtual void Update(float dt, SceneManager& sceneM) override;
	virtual void Draw(sf::RenderWindow& window) override;

	void SetTexture(sf::Texture& tex);
};