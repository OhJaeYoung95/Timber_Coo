#pragma once
#include "Scene.h"

class SceneManager;

class SelectCharacter : public Scene
{
private:
	sf::Texture bgTex;
	sf::Sprite bg;

	// 캐릭터 이미지
	sf::Texture c1Tex;
	sf::Sprite c1;
	sf::Texture c2Tex;
	sf::Sprite c2;

	// 캐릭터 프레임
	sf::Texture frameTex;
	sf::Sprite frame1;
	sf::Sprite frame2;

	// 커서 이미지
	sf::Texture c1CursorTex;
	sf::Sprite c1Cursor;
	sf::Texture c2CursorTex;
	sf::Sprite c2Cursor;

	// 캐릭터 스트링으로 넘기기
	std::string strC1;
	std::string strC2;

	// 캐릭터 차례
	sf::Font font;
	sf::Text playerTurnText;

	int playerTurn;		// 0 일때 플레이어1, 1일때 플레이어2
	int gameMode;
	int characterIndex;		// 0 일때 왼쪽 , 1일때 오른쪽
	bool isPick1;
	bool isPick2;

public:
	SelectCharacter(SceneType _type);
	virtual ~SelectCharacter();

	virtual void Init(ModeSelect mode, SceneManager& sceneM) override;
	virtual void Release() override;
	virtual void Update(float dt, SceneManager& sceneM) override;
	virtual void Draw(sf::RenderWindow& window) override;

	void SetCharacterIndex(int index);
};