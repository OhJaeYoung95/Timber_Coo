#include "PlayGame.h"

PlayGame::PlayGame(SceneType _type) : Scene(_type), modeIndex(0), characterIndex(0)
{
}

PlayGame::~PlayGame()
{
}

void PlayGame::Init(SceneManager& sceneM)
{
	modeIndex = 0;
	characterIndex = 0;
	modeIndex = sceneM.GetModeIndex();
	characterIndex = sceneM.GetCharacterIndex();
}

void PlayGame::Release()
{
}

void PlayGame::Update(float dt, SceneManager& sceneM)
{
	if (InputMgr2::GetKeyDown(sf::Keyboard::Enter))
	{
		sceneM.SetScene(SceneType::Play);
	}

	if (InputMgr2::GetKeyDown(sf::Keyboard::Tab))
	{
		sceneM.SetScene(SceneType::GameMode);
	}	
}

void PlayGame::Draw(sf::RenderWindow& window)
{

}