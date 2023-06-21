#pragma once
#include <sstream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include "Player.h"
#include "MovingBgObj.h"
#include "Defines.h"
#include "InputMgr2.h"

class PlayGame
{
protected:
	sf::RenderWindow window;
	ModeSelect mode;
	//int slotIndex;

	// ���� ���� ����
	bool isPause;
	bool isStart;
	bool isTimeOut;
	int score1;
	int score2;
	int bestScore;

	// �⺻ ����
	int screenWidth = 1920;
	int screenHeight = 1080;

	// �ؽ�Ʈ ����
	sf::Text textMessage;
	sf::Text textScore1;
	sf::Text textScore2;
	sf::Text textBestScore;

	// �ð� ����
	sf::Time dt;
	float deltaTime;
	sf::Clock clock;
	float duration;
	float timer1 = duration;
	float timer2 = duration;

	// uiTimer
	float uiTimerWidth;
	float uiTimerheight;
	sf::RectangleShape uiTimer1;
	sf::RectangleShape uiTimer2;
	sf::RectangleShape uiTimerFrame1;
	sf::RectangleShape uiTimerFrame2;

	// gameOj
	std::vector<GameObject*> gameObjects;
	MovingBgObj* newGo;
	MovingBgObj* beeGo;
	std::vector <Tree*> tree;
	std::vector <Player*> player;

	// font, texture
	sf::Font font;
	sf::Texture texBackground;
	sf::Texture texTree;
	sf::Texture texCloud;
	sf::Texture texBee;
	sf::Texture texPlayer1;
	sf::Texture texPlayer2;
	
public:
	PlayGame(ModeSelect mode);
	~PlayGame();

	void SoloPlay();
	void MultiPlay();
	void Init(ModeSelect mode);
	void Draw(ModeSelect mode);
	void Release();
};

