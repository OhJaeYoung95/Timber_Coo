#include "SceneManager.h"

SceneManager::SceneManager() 
	: title(SceneType::Title), 
	gameMode(SceneType::GameMode),
	selectCharacter(SceneType::Select),
	playGame(SceneType::Play),
	currentScene(SceneType::Title)
{

}

SceneManager::~SceneManager()
{
}

void SceneManager::Init()
{
}

void SceneManager::Release()
{
}

void SceneManager::Update(float dt)
{
	if (InputMgr2::GetKeyDown(sf::Keyboard::Return))
	{
		currentScene = (SceneType)((int)currentScene + 1);
	}
	switch (currentScene)
	{
	case SceneType::Title:
		break;
	case SceneType::GameMode:
		break;
	case SceneType::Select:
		break;
	case SceneType::Play:
		break;
	}
}

void SceneManager::Draw(sf::RenderWindow& window)
{
}
