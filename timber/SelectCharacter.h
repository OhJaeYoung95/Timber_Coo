#pragma once
#include "Scene.h"

class SelectCharacter : public Scene
{
private:

public:
	SelectCharacter(SceneType _type);
	virtual ~SelectCharacter();

	virtual void Init() override;
	virtual void Release() override;
	virtual void Update(float dt) override;
	virtual void Draw(sf::RenderWindow& window) override;
};

