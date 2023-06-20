#include "SceneManager.h"
#include "Title.h"
#include "GameMode.h"
#include "SelectCharacter.h"
#include "PlayGame.h"

SceneManager::SceneManager() 
	: currentScene(SceneType::Title), modeIndex(0), characterIndex(0)
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
	modeIndex = 0;
	characterIndex = 0;
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
}

void SceneManager::Draw(sf::RenderWindow& window)
{
	scene[(int)currentScene]->Draw(window);
}

void SceneManager::SetScene(SceneType type)
{
	currentScene = type;
	scene[(int)currentScene]->Init();
}

int SceneManager::GetModeIndex()
{
	return modeIndex;
}

void SceneManager::SetModeIndex(int index)
{
	modeIndex = index;
}

int SceneManager::GetCharacterIndex()
{
	return characterIndex;
}

void SceneManager::SetCharacterIndex(int index)
{
	characterIndex = index;
}
