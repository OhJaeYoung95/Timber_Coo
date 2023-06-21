#include "GameMode.h"
#include "InputMgr2.h"

GameMode::GameMode(SceneType _type) : Scene(_type), modeIndex(0)
{
	bgTex.loadFromFile("graphics/back1.png");
	SetTexture(bg, bgTex);

	// �̹��� ����
	modeForOneTex.loadFromFile("graphics/1p.png");
	SetTexture(modeForOne, modeForOneTex);
	modeForTwoTex.loadFromFile("graphics/2p.png");
	SetTexture(modeForTwo, modeForTwoTex);

	// ��Ʈ ����
	font.loadFromFile("fonts/KOMIKAP_.ttf");

}

GameMode::~GameMode()
{
}

void GameMode::Init(ModeSelect mode, SceneManager& sceneM)
{
	modeIndex = 0;
	sceneM.SetModeIndex(modeIndex);

	// ���Ӹ�� �̹���
	Utils::SetOrigin(modeForOne, Origins::MC);
	modeForOne.setPosition(500.f, 1080.f / 2.f);
	modeForOne.setScale(0.8f, 0.8f);

	Utils::SetOrigin(modeForTwo, Origins::MC);
	modeForTwo.setPosition(1400.f, 1080.f / 2.f);
	modeForTwo.setScale(0.8f, 0.8f);

	// �ؽ�Ʈ
	text1.setFont(font);
	text1.setString("\"FOR ONE PERSON\"");
	text1.setCharacterSize(75);
	text1.setFillColor(sf::Color::Blue);
	Utils::SetOrigin(text1, Origins::MC);
	text1.setPosition(500.f, 1080.f / 2.f + 300.f);

	text2.setFont(font);
	text2.setString("\"FOR TWO PERSON\"");
	text2.setCharacterSize(75);
	text2.setFillColor(sf::Color::Red);
	Utils::SetOrigin(text2, Origins::MC);
	text2.setPosition(1400.f, 1080.f / 2.f + 300.f);
}

void GameMode::Release()
{
}

void GameMode::Update(float dt, SceneManager& sceneM)
{
	Blink(dt);
	if (InputMgr2::GetKeyDown(sf::Keyboard::Left) && modeIndex >=1)
	{
		modeIndex--;
		sceneM.SetModeIndex(modeIndex);
	}
	if (InputMgr2::GetKeyDown(sf::Keyboard::Right) && modeIndex <= 0)
	{
		modeIndex++;
		sceneM.SetModeIndex(modeIndex);
	}

	if (InputMgr2::GetKeyDown(sf::Keyboard::Return))
	{
		sceneM.SetScene(SceneType::Select);
		sceneM.SetModeIndex(modeIndex);
	}
}

void GameMode::Draw(sf::RenderWindow& window)
{
	window.draw(bg);
	window.draw(modeForOne);
	window.draw(modeForTwo);
	if (modeIndex == 0)
	{
		if(blinkTimer > 0)
			window.draw(text1);
	}
	else
	{
		if (blinkTimer > 0)
			window.draw(text2);
	}
}

int GameMode::GetModeIndex()
{
	return modeIndex;
}
