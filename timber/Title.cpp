#include "Title.h"
Title::Title(SceneType _type) : Scene(_type)
{
	// �̹��� ����
	titleTex.loadFromFile("graphics/title.png");
	SetTexture(titleTex);

	// ��Ʈ ����
	font.loadFromFile("fonts/KOMIKAP_.ttf");
}

Title::~Title()
{
}

void Title::Init()
{
	type = SceneType::Title;

	// Ÿ��Ʋ �̹���
	title.setPosition(1920.f / 2.f, 1080.f / 2.f);
	title.setScale(3.f, 3.f);
	Utils::SetOrigin(title, Origins::MC);

	// �ؽ�Ʈ ����
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

void Title::Update(float dt)
{
}

void Title::Draw(sf::RenderWindow& window)
{
	window.draw(title);
	window.draw(text);
}

void Title::SetTexture(sf::Texture& tex)
{
	title.setTexture(tex);
}