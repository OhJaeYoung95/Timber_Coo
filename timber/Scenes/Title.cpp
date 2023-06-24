#include "stdafx.h"
#include "Framework.h"
#include "Title.h"
#include "SceneMgr.h"
#include "InputMgr.h"
#include "ResourceMgr.h"
#include "SpriteGo.h"
#include "TextGo.h"
Title::Title() : Scene(SceneId::Title)
{
	// 이미지 설정
	//titleTex.loadFromFile("graphics/title.png");
	//SetTexture(titleTex);

	// 폰트 설정
	//font.loadFromFile("fonts/KOMIKAP_.ttf");
	//resources.push_back();
	//RESOURCE_MGR.Load(ResourceTypes::Texture, "graphics/title.png");
	//RESOURCE_MGR.Load(ResourceTypes::Font, "fonts/KOMIKAP_.ttf");
	resources.push_back(std::make_tuple(ResourceTypes::Texture, "graphics/title.png"));

}

Title::~Title()
{
}

void Title::Init()
{
	Release();

	AddGo(new SpriteGo("BG"));
	AddGo(new TextGo("Title"));

	for (auto go : gameObjects)
	{
		go->Init();
	}

	//// 타이틀 이미지
	//title.setPosition(0.f, 0.f);
	//title.setScale(1.f, 1.f);
	//Utils::SetOrigin(title, Origins::TL);

	//// 텍스트 생성
	//text.setFont(font);
	//text.setString("\"PRESS ENTER TO START GAME!\"");
	//text.setCharacterSize(75);
	//text.setFillColor(sf::Color::White);
	//Utils::SetOrigin(text, Origins::MC);
	//text.setPosition(1920.f / 2.f, 1080.f / 2.f + 300.f);
}

void Title::Release()
{
	for (auto go : gameObjects)
	{
		//go->Release();
		delete go;
	}
}

void Title::Enter()
{
	Scene::Enter();
	SpriteGo* findGo = (SpriteGo*)FindGo("BG");
	findGo->sprite.setTexture(*RESOURCE_MGR.GetTexture("graphics/title.png"));
	findGo->SetOrigin(Origins::TL);
	findGo->SetPosition(0, 0);
	findGo->SetSize(1, 1);
	findGo->sortLayer = 0;

	TextGo* textGo = (TextGo*)FindGo("TEXT");
	textGo->text.setFont(*RESOURCE_MGR.GetFont("fonts/KOMIKAP_.ttf"));
	textGo->SetOrigin(Origins::MC);
	textGo->SetPosition(FRAMEWORK.GetWindowSize().x / 2.f, FRAMEWORK.GetWindowSize().y / 2.f + 300.f);
	textGo->sortLayer = 1;
}

void Title::Exit()
{
	Scene::Exit();
	//RESOURCE_MGR.Unload(ResourceTypes::Texture, "graphics/title.png");
	//RESOURCE_MGR.Unload(ResourceTypes::Font, "fonts/KOMIKAP_.ttf");
}

void Title::Update(float dt)	// 여기서 
{

	Scene::Update(dt);
	Blink(dt);


	if (INPUT_MGR.GetKeyDown(sf::Keyboard::Return))
		SCENE_MGR.ChangeScene(SceneId::GameMode);
}

void Title::Draw(sf::RenderWindow& window)
{
	Scene::Draw(window);

	//if (blinkTimer > 0)
	//	window.draw(text);

}

void Title::SetTexture(sf::Texture& tex)
{
	title.setTexture(tex); 
}