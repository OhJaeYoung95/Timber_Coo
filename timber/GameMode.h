#pragma once
#include "Player.h"
#include "MovingBgObj.h"

enum class ModeSelect
{
	Solo,
	Multi
};

class GameMode
{
protected:
	bool isPause;
	bool isStart;
	bool isTimeOut;
	int score;
	int bestScore;

	int screenWidth;
	int screenHeight;

	sf::Text textMessage;
	sf::Text textScore;
	sf::Text textBestScore;

	float duration = 6.f;
	float timer = duration;
	float uiTimerWidth = 400.f;
	float uiTimerheight = 80.f;
	sf::RectangleShape uiTimer;
	sf::RectangleShape uiTimerFrame;

	std::vector<GameObject*> gameObjects;
	MovingBgObj* newGo;
	MovingBgObj* beeGo;
	std::vector <Tree*> tree[2];
	std::vector <Player*> player[2];

	
public:
	GameMode(ModeSelect mode,
		sf::Font font,
		sf::Texture texBackground,
		sf::Texture texTree,
		sf::Texture texCloud,
		sf::Texture texBee,
		sf::Texture texPlayer);
	~GameMode();

	void InitSolo();
	void InitMulti();
	void Update();
	void Draw();
	void Release();

	void SoloPlay(ModeSelect mode);
	void MultiPlay(ModeSelect mode);
};

