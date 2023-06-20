#pragma once
#include <vector>
#include "Scene.h"

class GameObject;

class PlayGame : public Scene
{
private:
	int slotIndex;

public:
	PlayGame(SceneType _type);
	virtual ~PlayGame() override;

	virtual void Init() override;
	virtual void Release() override;
	virtual void Update(float dt, SceneManager& sceneM) override;
	virtual void Draw(sf::RenderWindow& window) override;

	void SetSlotIndex(int index);
};
