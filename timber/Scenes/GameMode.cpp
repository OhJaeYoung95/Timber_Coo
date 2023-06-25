#include "stdafx.h"
#include "Framework.h"
#include "GameMode.h"
#include "SceneMgr.h"
#include "InputMgr.h"
#include "ResourceMgr.h"
#include "SpriteGo.h"
#include "TextGo.h"


GameMode::GameMode() : Scene(SceneId::Title), modeIndex(0)
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

	// 오브젝트, 리소스 생성
	resources.push_back(std::make_tuple(ResourceTypes::Texture, "graphics/back1.png"));
	resources.push_back(std::make_tuple(ResourceTypes::Texture, "graphics/1p.png"));
	resources.push_back(std::make_tuple(ResourceTypes::Texture, "graphics/2p.png"));
	RESOURCE_MGR.Load(resources);

	AddGo(new SpriteGo("BG"));
	AddGo(new SpriteGo("1P"));
	AddGo(new SpriteGo("2P"));
	AddGo(new TextGo("1pText"));
	AddGo(new TextGo("2pText"));

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
	RESOURCE_MGR.Unload(resources);
	for (auto go : gameObjects)
	{
		//go->Release();
		delete go;
	}
}

void GameMode::Enter()
{
	Scene::Enter();
	SpriteGo* findGo1 = (SpriteGo*)FindGo("BG");
	findGo1->sprite.setTexture(*RESOURCE_MGR.GetTexture("graphics/back1.png"));
	findGo1->SetOrigin(Origins::TL);
	findGo1->SetPosition(0, 0);
	findGo1->SetSize(1, 1);
	findGo1->sortLayer = 0;

	SpriteGo* findGo2 = (SpriteGo*)FindGo("1P");
	findGo2->sprite.setTexture(*RESOURCE_MGR.GetTexture("graphics/1p.png"));
	findGo2->SetOrigin(Origins::MC);
	findGo2->SetPosition(FRAMEWORK.GetWindowSize().x * 0.3f, FRAMEWORK.GetWindowSize().y * 0.55f);
	findGo2->SetSize(0.7f, 0.7f);
	findGo2->sortLayer = 1;

	SpriteGo* findGo3 = (SpriteGo*)FindGo("2P");
	findGo3->sprite.setTexture(*RESOURCE_MGR.GetTexture("graphics/2p.png"));
	findGo3->SetOrigin(Origins::MC);
	findGo3->SetPosition(FRAMEWORK.GetWindowSize().x * 0.7f, FRAMEWORK.GetWindowSize().y * 0.55f);
	findGo3->SetSize(0.7f, 0.7f);
	findGo3->sortLayer = 1;

	TextGo* textGo1 = (TextGo*)FindGo("1pText");
	textGo1->text.setFont(*RESOURCE_MGR.GetFont("fonts/KOMIKAP_.ttf"));
	textGo1->text.setCharacterSize(60);
	textGo1->text.setString("\"For One Person\"");
	textGo1->SetPosition(FRAMEWORK.GetWindowSize().x * 0.3f, FRAMEWORK.GetWindowSize().y * 0.8f);
	textGo1->SetOrigin(Origins::MC);
	//textGo1->text.setColor(sf::Color::Red);
	textGo1->text.setFillColor(sf::Color::Red);
	textGo1->sortLayer = 1;

	TextGo* textGo2 = (TextGo*)FindGo("2pText");
	textGo2->text.setFont(*RESOURCE_MGR.GetFont("fonts/KOMIKAP_.ttf"));
	//textGo2->text.setColor(sf::Color::Blue);
	textGo2->text.setCharacterSize(60);
	textGo2->text.setString("\"For Two Person\"");
	textGo2->SetPosition(FRAMEWORK.GetWindowSize().x * 0.7f, FRAMEWORK.GetWindowSize().y * 0.8f);
	textGo2->SetOrigin(Origins::MC);
	textGo2->text.setFillColor(sf::Color::Blue);
	textGo2->sortLayer = 1;

}

void GameMode::Exit()
{
	Scene::Exit();
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
	//	sceneM.SetModeIndex(modeIndex);s
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
	return modeIndex;
}
