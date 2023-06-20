#include "SceneManager.h"
#include "Title.h"
#include "GameMode.h"
#include "SelectCharacter.h"
#include "PlayGame.h"

SceneManager::SceneManager() 
	: currentScene(SceneType::Title)
{
	scene.push_back(new Title(SceneType::Title));
	scene.push_back(new GameMode(SceneType::GameMode));
	scene.push_back(new SelectCharacter(SceneType::Select));
	scene.push_back(new PlayGame(SceneType::Play));
}

SceneManager::~SceneManager()
{
	for (auto& it : scene)
	{
		delete it;
	}
}

void SceneManager::Init()
{
	for (auto& it : scene)
	{
		it->Init();
	}
}

void SceneManager::Release()
{
	for (auto& it : scene)
	{
		it->Release();
	}
}

void SceneManager::Update(float dt)
{
	scene[(int)currentScene]->Update(dt, *this);
	//if (InputMgr2::GetKeyDown(sf::Keyboard::Return) && currentScene != (SceneType::Play))
	//{
	//	currentScene = (SceneType)((int)currentScene + 1);
	//}

	//// 게임 플레이 초기화
	//if (InputMgr2::GetKeyDown(sf::Keyboard::Return) &&
	//	currentScene == (SceneType::Play))
	//{
	//	currentScene = SceneType::Play;
	//	scene[(int)currentScene]->Init();
	//}

	//// 게임 모드로 이동
	//if (InputMgr2::GetKeyDown(sf::Keyboard::Tab))
	//{
	//	currentScene = SceneType::GameMode;
	//	scene[(int)SceneType::GameMode]->Init();
	//	scene[(int)SceneType::Select]->Init();
	//}
}

void SceneManager::Draw(sf::RenderWindow& window)
{
	scene[(int)currentScene]->Draw(window);
}

void SceneManager::SetScene(SceneType type)
{
	currentScene = type;
}
