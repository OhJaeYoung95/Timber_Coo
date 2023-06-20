#pragma once
//#include "Title.h"
//#include "GameMode.h"
//#include "SelectCharacter.h"
//#include "PlayGame.h"
#include <vector>
#include "Defines.h"
#include "InputMgr2.h"


class Title;
class GameMode;
class SelectCharacter;
class PlayGame;
class Scene;

class SceneManager
{
private:
	std::vector<Scene*> scene;
	SceneType currentScene;

public:
	SceneManager();
	~SceneManager();

	void Init();
	void Release();
	void Update(float dt);
	void Draw(sf::RenderWindow& window);

	void SetScene(SceneType type);
};

