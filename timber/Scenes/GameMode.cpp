#include "GameMode.h"
#include "stdafx.h"
#include "SceneMgr.h"
#include "InputMgr.h"
#include "ResourceMgr.h"
#include "SpriteGo.h"


GameMode::GameMode() : Scene(SceneId::Title)/*, modeIndex(0)*/
{
	//bgTex.loadFromFile("graphics/back1.png");
	//SetTexture(bg, bgTex);

	//// 이미지 설정
	//modeForOneTex.loadFromFile("graphics/1p.png");
	//SetTexture(modeForOne, modeForOneTex);
	//modeForTwoTex.loadFromFile("graphics/2p.png");
	//SetTexture(modeForTwo, modeForTwoTex);

	//// 폰트 설정
	//font.loadFromFile("fonts/KOMIKAP_.ttf");

}

GameMode::~GameMode()
{
}

void GameMode::Init()
{
	Release();

	for (auto go : gameObjects)
	{
		go->Init();
	}
	//modeIndex = 0;
	//sceneM.SetModeIndex(modeIndex);

	//// 게임모드 이미지
	//Utils::SetOrigin(modeForOne, Origins::MC);
	//modeForOne.setPosition(500.f, 1080.f / 2.f);
	//modeForOne.setScale(0.8f, 0.8f);

	//Utils::SetOrigin(modeForTwo, Origins::MC);
	//modeForTwo.setPosition(1400.f, 1080.f / 2.f);
	//modeForTwo.setScale(0.8f, 0.8f);

	//// 텍스트
	//text1.setFont(font);
	//text1.setString("\"FOR ONE PERSON\"");
	//text1.setCharacterSize(75);
	//text1.setFillColor(sf::Color::Blue);
	//Utils::SetOrigin(text1, Origins::MC);
	//text1.setPosition(500.f, 1080.f / 2.f + 300.f);

	//text2.setFont(font);
	//text2.setString("\"FOR TWO PERSON\"");
	//text2.setCharacterSize(75);
	//text2.setFillColor(sf::Color::Red);
	//Utils::SetOrigin(text2, Origins::MC);
	//text2.setPosition(1400.f, 1080.f / 2.f + 300.f);
}

void GameMode::Release()
{
	for (auto go : gameObjects)
	{
		//go->Release();
		delete go;
	}
}

void GameMode::Update(float dt)
{
	Scene::Update(dt);

	if (INPUT_MGR.GetKeyDown(sf::Keyboard::Return))
	{
		SCENE_MGR.ChangeScene(SceneId::Game);
	}
	//Blink(dt);
	//if (InputMgr2::GetKeyDown(sf::Keyboard::Left) && modeIndex >=1)
	//{
	//	modeIndex--;
	//	sceneM.SetModeIndex(modeIndex);
	//}
	//if (InputMgr2::GetKeyDown(sf::Keyboard::Right) && modeIndex <= 0)
	//{
	//	modeIndex++;
	//	sceneM.SetModeIndex(modeIndex);
	//}

	//if (InputMgr2::GetKeyDown(sf::Keyboard::Return))
	//{
	//	sceneM.SetScene(SceneType::Select);
	//	sceneM.SetModeIndex(modeIndex);
	//}
}

void GameMode::Draw(sf::RenderWindow& window)
{
	Scene::Draw(window);
	//window.draw(bg);
	//window.draw(modeForOne);
	//window.draw(modeForTwo);
	//if (modeIndex == 0)
	//{
	//	if(blinkTimer > 0)
	//		window.draw(text1);
	//}
	//else
	//{
	//	if (blinkTimer > 0)
	//		window.draw(text2);
	//}
}

int GameMode::GetModeIndex()
{
	//return modeIndex;
}
