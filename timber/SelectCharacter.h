#pragma once
#include "Scene.h"

class SceneManager;

class SelectCharacter : public Scene
{
private:
	sf::Texture bgTex;
	sf::Sprite bg;

	// ĳ���� �̹���
	sf::Texture c1Tex;
	sf::Sprite c1;
	sf::Texture c2Tex;
	sf::Sprite c2;

	// ĳ���� ������
	sf::Texture frameTex;
	sf::Sprite frame1;
	sf::Sprite frame2;

	// Ŀ�� �̹���
	sf::Texture c1CursorTex;
	sf::Sprite c1Cursor;
	sf::Texture c2CursorTex;
	sf::Sprite c2Cursor;

	// ĳ���� ��Ʈ������ �ѱ��
	std::string strC1;
	std::string strC2;

	// ĳ���� ����
	sf::Font font;
	sf::Text playerTurnText;

	int playerTurn;		// 0 �϶� �÷��̾�1, 1�϶� �÷��̾�2
	int gameMode;
	int characterIndex;		// 0 �϶� ���� , 1�϶� ������
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