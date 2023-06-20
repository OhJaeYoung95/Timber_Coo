#include "PlayGame.h"

PlayGame::PlayGame(SceneType _type/*, std::vector<GameObject*>& gameObjects*/) : Scene(_type), slotIndex(0)
{
}

PlayGame::~PlayGame()
{
}

void PlayGame::Init()
{
}

void PlayGame::Release()
{
}

void PlayGame::Update(float dt, SceneManager& sceneM)
{

}

void PlayGame::Draw(sf::RenderWindow& window)
{

}

void PlayGame::SetSlotIndex(int index)
{
	slotIndex = index;
}
