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
	scene.push_back(new PlayGame(*this, SceneType::Play));
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
		it->Init((ModeSelect)modeIndex, *this);
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
	scene[(int)currentScene]->Init((ModeSelect)modeIndex, *this);
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

const std::string& SceneManager::GetPlayer1()
{
	return player1;
}

void SceneManager::SetPlayer1(const std::string& str)
{
	player1 = str;
}

const std::string& SceneManager::GetPlayer2()
{
	return player2;
}

void SceneManager::SetPlayer2(const std::string& str)
{
	player2 = str;
}
