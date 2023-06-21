#pragma once
#include <vector>
#include "Scene.h"

class GameObject;

class PlayGame : public Scene
{
private:
	int modeIndex;
	int characterIndex;

public:
	PlayGame(SceneType _type);
	virtual ~PlayGame() override;

	virtual void Init(SceneManager& sceneM) override;
	virtual void Release() override;
	virtual void Update(float dt, SceneManager& sceneM) override;
	virtual void Draw(sf::RenderWindow& window) override;
};