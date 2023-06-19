#pragma once
#include <SFML/Graphics.hpp>
#include <list>
#include <vector>
#include "Branch.h"
#include "SpriteGo.h"
#include "EffectGo.h"
class Tree : public SpriteGo
{
private:
	std::vector<GameObject*>& gameObjectList;
	std::vector<Branch*> branchList;
	std::vector<sf::Vector2f> branchPosVec;
	sf::Texture branchTex;
	int currentBranchIndex;
	int branchSize;

	int xPos;
	int yPos;
	float offsetY;

	// 통나무
	std::list<EffectGo*> logPool;		// 비활성화
	std::list<EffectGo*> logEffects;	// 활성화
	sf::Texture texLog;

public:
	Tree(std::vector<GameObject*>& games, sf::Texture& tex,
		sf::Vector2f spriteDir = sf::Vector2f(1.f, 0.f),
		const std::string& n = "",
		const sf::Vector2f p = { 1920.f / 2.f, 0 });
	//~Tree();
	virtual void Init() override;
	virtual void Release() override;
	virtual void Update(float dt) override;
	virtual void Draw(sf::RenderWindow& window) override;

	void UpdateBranches();
	void ShowEffectLog(Sides side, sf::Vector2f position);
	//Sides GetCurrentSide();
	int GetCurrentint();
	Sides GetCurrentSide();
};