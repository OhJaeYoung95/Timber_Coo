#include "GameMode.h"

GameMode::GameMode(SceneType _type) : Scene(_type)
{

	// 이미지 설정
	modeForOneTex.loadFromFile("graphics/title.png");
	SetTexture(modeForOne, modeForOneTex);
	modeForTwoTex.loadFromFile("graphics/title.png");
	SetTexture(modeForTwo, modeForTwoTex);

	// 폰트 설정
	font.loadFromFile("fonts/KOMIKAP_.ttf");

}

GameMode::~GameMode()
{
}

void GameMode::Init()
{
	type = SceneType::GameMode;
	// 게임모드 이미지
	Utils::SetOrigin(modeForOne, Origins::MC);
	modeForOne.setPosition(400.f, 1080.f / 2.f);

	Utils::SetOrigin(modeForTwo, Origins::MC);
	modeForTwo.setPosition(1500.f, 1080.f / 2.f);

	// 텍스트
	text1.setFont(font);
	text1.setString("\"FOR ONE PERSON\"");
	text1.setCharacterSize(75);
	text1.setFillColor(sf::Color::Blue);
	Utils::SetOrigin(text1, Origins::MC);
	text1.setPosition(400.f, 1080.f / 2.f + 300.f);



	text2.setFont(font);
	text2.setString("\"FOR TWO PERSON\"");
	text2.setCharacterSize(75);
	text2.setFillColor(sf::Color::Red);
	Utils::SetOrigin(text2, Origins::MC);
	text2.setPosition(1500.f, 1080.f / 2.f + 300.f);
}

void GameMode::Release()
{
}

void GameMode::Update(float dt)
{
}

void GameMode::Draw(sf::RenderWindow& window)
{
	window.draw(modeForOne);
	window.draw(modeForTwo);
	window.draw(text1);
	window.draw(text2);
}

void GameMode::SetTexture(sf::Sprite& sprite, sf::Texture& tex)
{
	sprite.setTexture(tex);
}
