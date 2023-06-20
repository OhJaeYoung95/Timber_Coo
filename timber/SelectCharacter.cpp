#include <SFML/Graphics.hpp>
#include "SelectCharacter.h"
#include "InputMgr2.h"
#include "Utils.h"

SelectCharacter::SelectCharacter(SceneType _type) 
	: Scene(_type) , playerTurn(0), characterIndex(1)
{
	bgTex.loadFromFile("graphics/back2.png");
	SetTexture(bg, bgTex);

	// 이미지 설정
	c1Tex.loadFromFile("graphics/player.png");
	SetTexture(c1, c1Tex);
	c2Tex.loadFromFile("graphics/player2.png");
	SetTexture(c2, c2Tex);
	// 프레임
	frameTex.loadFromFile("graphics/frame.png");
	SetTexture(frame1, frameTex);
	SetTexture(frame2, frameTex);

	// 커서
	c1CursorTex.loadFromFile("graphics/cursor.png");
	SetTexture(c1Cursor, c1CursorTex);
	c2CursorTex.loadFromFile("graphics/cursor.png");
	SetTexture(c2Cursor, c2CursorTex);


	// 폰트 설정
	font.loadFromFile("fonts/KOMIKAP_.ttf");

}

SelectCharacter::~SelectCharacter()
{

}

void SelectCharacter::Init()
{
	playerTurn = 0;
	characterIndex = 0;

	// 텍스트
	playerTurnText.setFont(font);
	playerTurnText.setString("Select Player 1");
	playerTurnText.setCharacterSize(75);
	playerTurnText.setFillColor(sf::Color::Black);
	Utils::SetOrigin(playerTurnText, Origins::TL);
	playerTurnText.setPosition(100.f, 60.f);

	// 캐릭터
	c1.setPosition(500.f, 1080.f / 2.f + 100.f);
	Utils::SetOrigin(c1, Origins::MC);
	frame1.setPosition(500.f, 1080.f / 2.f + 100.f);
	frame1.setScale(0.5f, 0.5f);
	Utils::SetOrigin(frame1, Origins::MC);

	c2.setPosition(1400.f, 1080.f / 2.f + 100.f);
	c2.setScale(0.22f, 0.22f);
	Utils::SetOrigin(c2, Origins::MC);
	frame2.setPosition(1400.f, 1080.f / 2.f + 100.f);
	frame2.setScale(0.5f, 0.5f);
	Utils::SetOrigin(frame2, Origins::MC);

	// 커서
	c1Cursor.setPosition(280.f, 1080.f / 2.f - 400.f);
	c1Cursor.setScale(0.5f, 0.5f);
	Utils::SetOrigin(c2, Origins::MC);
	c2Cursor.setPosition(1180.f, 1080.f / 2.f - 400.f);
	c2Cursor.setScale(0.5f, 0.5f);
	Utils::SetOrigin(c2, Origins::MC);


}

void SelectCharacter::Release()
{
}

void SelectCharacter::Update(float dt, SceneManager& sceneM)
{
	Blink(dt);
	if (InputMgr2::GetKeyDown(sf::Keyboard::Left) && characterIndex >= 1)
	{
		characterIndex--;
		sceneM.SetCharacterIndex(characterIndex);
	}
	if (InputMgr2::GetKeyDown(sf::Keyboard::Right) && characterIndex <= 0)
	{
		characterIndex++;
		sceneM.SetCharacterIndex(characterIndex);
	}


	// 테스트 코드
	if (InputMgr2::GetKeyDown(sf::Keyboard::Enter) && playerTurn < 1)
	{
		characterIndex = 0;
		playerTurn = playerTurn + 1;
		InputMgr2::ClearInput();
	}
	
	if (playerTurn == 0)
	{
		playerTurnText.setString("Select Player 1");
		Utils::SetOrigin(playerTurnText, Origins::TL);
		playerTurnText.setPosition(100.f, 60.f);

	}
	else
	{
		playerTurnText.setString("Select Player 2");
		Utils::SetOrigin(playerTurnText, Origins::TL);
		playerTurnText.setPosition(100.f, 60.f);
	}

	
	if (InputMgr2::GetKeyDown(sf::Keyboard::Return))
	{
		sceneM.SetScene(SceneType::Play);
	}

	
}

void SelectCharacter::Draw(sf::RenderWindow& window)
{
	window.draw(bg);
	window.draw(frame1);
	window.draw(frame2);
	window.draw(c1);
	window.draw(c2);
	window.draw(playerTurnText);

	if (characterIndex == 0)
	{
		if(blinkTimer > 0)
			window.draw(c1Cursor);
	}
	else
	{
		if (blinkTimer > 0)
			window.draw(c2Cursor);
	}
}

void SelectCharacter::SetCharacterIndex(int index)
{
	characterIndex = index;
}
