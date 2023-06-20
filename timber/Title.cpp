#include "Title.h"
Title::Title(SceneType _type) : Scene(_type)
{
	// 이미지 설정
	titleTex.loadFromFile("graphics/title.png");
	SetTexture(titleTex);

	// 폰트 설정
	font.loadFromFile("fonts/KOMIKAP_.ttf");
}

Title::~Title()
{
}

void Title::Init()
{
	type = SceneType::Title;

	// 타이틀 이미지
	title.setPosition(0.f, 0.f);
	title.setScale(1.f, 1.f);
	Utils::SetOrigin(title, Origins::TL);

	// 텍스트 생성
	text.setFont(font);
	text.setString("\"PRESS ENTER TO START GAME!\"");
	text.setCharacterSize(75);
	text.setFillColor(sf::Color::White);
	Utils::SetOrigin(text, Origins::MC);
	text.setPosition(1920.f / 2.f, 1080.f / 2.f + 300.f);

}

void Title::Release()
{
}

void Title::Update(float dt, SceneManager& sceneM)
{
	Blink(dt);
	if (InputMgr2::GetKeyDown(sf::Keyboard::Return))
		sceneM.SetScene(SceneType::GameMode);
}

void Title::Draw(sf::RenderWindow& window)
{
	window.draw(title);
	if (blinkTimer > 0)
	{
		window.draw(text);
	}



}

void Title::SetTexture(sf::Texture& tex)
{
	title.setTexture(tex);
}