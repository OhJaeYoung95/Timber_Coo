#pragma once
#include "Scene.h"
#include "Utils.h"

class SceneManager;

class GameMode : public Scene
{
private:
	//sf::Texture bgTex;
	//sf::Sprite bg;

	//sf::Texture modeForOneTex;
	//sf::Sprite modeForOne;

	//sf::Texture modeForTwoTex;
	//sf::Sprite modeForTwo;

	//sf::Font font;
	//sf::Text text1;
	//sf::Text text2;

	//int modeIndex;

public:
	GameMode();
	virtual ~GameMode() override;

	virtual void Init() override;
	virtual void Release() override;

	virtual void Enter() override;
	virtual void Exit() override;

	virtual void Update(float dt) override;
	virtual void Draw(sf::RenderWindow& window) override;

	int GetModeIndex();
};

