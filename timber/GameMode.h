#pragma once
#include "Scene.h"
#include "Utils.h"
class GameMode : public Scene
{
private:
	sf::Texture modeForOneTex;
	sf::Sprite modeForOne;

	sf::Texture modeForTwoTex;
	sf::Sprite modeForTwo;

	sf::Font font;
	sf::Text text1;
	sf::Text text2;

public:
	GameMode(SceneType _type);
	virtual ~GameMode() override;

	virtual void Init() override;
	virtual void Release() override;
	virtual void Update(float dt) override;
	virtual void Draw(sf::RenderWindow& window) override;

	void SetTexture(sf::Sprite& sprite, sf::Texture& tex);

};

