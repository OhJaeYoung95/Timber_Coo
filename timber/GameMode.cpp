#include "GameMode.h"
#include "InputMgr2.h"

GameMode::GameMode(SceneType _type) : Scene(_type), slotIndex(0)
{
	bgTex.loadFromFile("graphics/back1.png");
	SetTexture(bg, bgTex);

	// 이미지 설정
	modeForOneTex.loadFromFile("graphics/1p.png");
	SetTexture(modeForOne, modeForOneTex);
	modeForTwoTex.loadFromFile("graphics/2p.png");
	SetTexture(modeForTwo, modeForTwoTex);

	// 폰트 설정
	font.loadFromFile("fonts/KOMIKAP_.ttf");

}

GameMode::~GameMode()
{
}

void GameMode::Init()
{
	slotIndex = 0;

	// 게임모드 이미지
	Utils::SetOrigin(modeForOne, Origins::MC);
	modeForOne.setPosition(500.f, 1080.f / 2.f);
	modeForOne.setScale(0.8f, 0.8f);

	Utils::SetOrigin(modeForTwo, Origins::MC);
	modeForTwo.setPosition(1400.f, 1080.f / 2.f);
	modeForTwo.setScale(0.8f, 0.8f);

	// 텍스트
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
	if (InputMgr2::GetKeyDown(sf::Keyboard::Left) && slotIndex >=1)
	{
		slotIndex--;
	}
	if (InputMgr2::GetKeyDown(sf::Keyboard::Right) && slotIndex <= 0)
	{
		slotIndex++;
	}

	if (InputMgr2::GetKeyDown(sf::Keyboard::Return))
	{
		sceneM.SetScene(SceneType::Select);
	}
}

void GameMode::Draw(sf::RenderWindow& window)
{
	window.draw(bg);
	window.draw(modeForOne);
	window.draw(modeForTwo);
	if (slotIndex == 0)
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

int GameMode::GetSlotIndex()
{
	return slotIndex;
}
