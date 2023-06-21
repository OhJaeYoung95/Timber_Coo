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

	int modeIndex;		// 1인용 2인용, SelectCharacter 의 playerTurn에도 적용
	int characterIndex;

	sf::Sprite player1;
	sf::Sprite player2;

public:
	SceneManager();
	~SceneManager();

	void Init();
	void Release();
	void Update(float dt);
	void Draw(sf::RenderWindow& window);

	void SetScene(SceneType type);

	int GetModeIndex();
	void SetModeIndex(int index);
	int GetCharacterIndex();
	void SetCharacterIndex(int index);

	sf::Sprite GetPlayer1();
	void SetPlayer1(sf::Sprite sprite);
	sf::Sprite GetPlayer2();
	void SetPlayer2(sf::Sprite sprite);
};

