#pragma once
#include "Title.h"
#include "GameMode.h"
#include "SelectCharacter.h"
#include "PlayGame.h"
//#include "Defines.h"
#include "InputMgr2.h"


//class Title;
//class GameMode;
//class SelectCharacter;
//class PlayGame;

class SceneManager
{
private:
	Title title;
	GameMode gameMode;
	SelectCharacter selectCharacter;
	PlayGame playGame;

	SceneType currentScene;
public:
	SceneManager();
	~SceneManager();

	void Init();
	void Release();
	void Update(float dt);
	void Draw(sf::RenderWindow& window);

};

