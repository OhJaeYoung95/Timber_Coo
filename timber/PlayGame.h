#pragma once
#include <vector>
#include "Scene.h"

class GameObject;

class PlayGame : public Scene
{
private:

public:
	PlayGame(SceneType _type/*, std::vector<GameObject*>& gameObjects*/);
	virtual ~PlayGame() override;

	virtual void Init() override;
	virtual void Release() override;
	virtual void Update(float dt) override;
	virtual void Draw(sf::RenderWindow& window) override;
};
