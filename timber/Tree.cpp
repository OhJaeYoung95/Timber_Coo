#include <iostream>
#include "Tree.h"
#include "Utils.h"
#include "InputMgr2.h"

Tree::Tree(std::vector<GameObject*>& games, sf::Texture& tex, sf::Vector2f spriteDir, const std::string& n, const sf::Vector2f p) 
	:gameObjectList(games), 
	SpriteGo(tex, spriteDir, n, p), 
	currentBranchIndex(0), 
	branchSize(6),
	branchList(6),
	branchPosVec(6), 
	xPos(0), yPos(800.f)
{
	branchTex.loadFromFile("graphics/branch.png");
	texLog.loadFromFile("graphics/log.png");

	for (int i = 0; i < branchList.size(); i++)
	{
		branchList[i] = new Branch(branchTex);
		branchList[i]->SetTree(this);
		Sides side = (Sides)Utils::RandomRange(0, 2);
		branchList[i]->SetSide(side);
		this->gameObjectList.push_back(branchList[i]);
	}
	offsetY = branchList[0]->GetSize().y + 100.f;
	xPos = GetPosition().x;

	//for (auto& branch : branchList)
	//{
	//	branch = new Branch(branchTex, { -1.f, -1.f }, "Branch");
	//	branch->SetTree(this);
	//	this->gameObjectList.push_back(branch);
	//}
	for (int i = 0; i < 100; i++)
	{
		EffectGo* newGo = new EffectGo(texLog);
		newGo->SetActive(false);
		logPool.push_back(newGo);
	}
}

//Tree::~Tree()
//{
//	for (int i = 0; i < 6; i++)
//	{
//		delete branchList[i];
//
//	}
//}


void Tree::Init()
{
	SpriteGo::Init();

	isActive = true;
	currentBranchIndex = 0;

	xPos = GetPosition().x;
	yPos = 800.f;
	offsetY = branchList[0]->GetSize().y + 100.f;
	for (int i = 0; i < branchPosVec.size(); i++)
	{
		branchPosVec[i].x = xPos;
		branchPosVec[i].y = yPos;
		yPos -= offsetY;
	}
	for (int i = 0; i < branchList.size(); i++)
	{
		branchList[i]->Init();
		branchList[i]->SetPosition(branchPosVec[i]);
		branchList[i]->SetSide((Sides)Utils::RandomRange(0, 2));
	}
	//offsetY = branchList[0]->GetSize().y + 100.f;
	UpdateBranches();

	branchList[currentBranchIndex]->SetSide(Sides::Left);

	for (auto& effect : logEffects)
	{
		effect->SetActive(false);
	}
}

void Tree::Release()
{
	SpriteGo::Release();

	for (auto& branch : branchList)
	{
		delete branch;
		branch = nullptr;
	}
	branchList.clear();

	for (auto& effect : logPool)
	{
		delete effect;
		effect = nullptr;
	}

	logPool.clear();

	for (auto& effect : logEffects)
	{
		delete effect;
		effect = nullptr;
	}
	logEffects.clear();

}


void Tree::Update(float dt)
{
	SpriteGo::Update(dt);

	//if (InputMgr2::GetKeyDown(sf::Keyboard::Space))
	//{
	//	UpdateBranches();
	//}
	//if (InputMgr2::GetKeyDown(sf::Keyboard::Num1))
	//{
	//	sf::Vector2f pos = GetPosition();
	//	pos.y = GetSize().y;
	//	ShowEffectLog(Sides::Left, pos);
	//}
	//if (InputMgr2::GetKeyDown(sf::Keyboard::Num2))
	//{
	//	sf::Vector2f pos = GetPosition();
	//	pos.y = GetSize().y;
	//	ShowEffectLog(Sides::Right, pos);
	//}

	auto it = logEffects.begin();
	while (it != logEffects.end())
	{
		if ((*it)->GetActive())
		{
			(*it)->Update(dt);
			++it;
		}
		else
		{
			logPool.push_back((*it));
			it = logEffects.erase(it);
		}
	}
}

void Tree::Draw(sf::RenderWindow& window)
{
	SpriteGo::Draw(window);
	for (auto branch : branchList)
	{
		branch->Draw(window);
	}
	for (auto effect : logEffects)
	{
		effect->Draw(window);
	}

}

void Tree::UpdateBranches()
{
	currentBranchIndex = (currentBranchIndex + 1) % branchList.size();
	int index;
	for (int i = 0; i < branchList.size(); i++)
	{
		index = (currentBranchIndex + i) % branchList.size();
		branchList[index]->SetPosition(branchPosVec[i]);

		// 나뭇가지 방향찾기
		if (i == branchList.size() - 1)
		{
			Sides side = (Sides)Utils::RandomRange(0, 2);
			branchList[index]->SetSide(side);
		}
	}
}


void Tree::ShowEffectLog(Sides side, sf::Vector2f position)
{
	// 비었으면 true
	if (logPool.empty())
	{
		std::cout << "Log Pool Empty" << std::endl;
		return;
	}

	// 풀 사용
	EffectGo* log = logPool.front();
	logPool.pop_front();
	logEffects.push_back(log);

	log->SetActive(true);
	log->Init();
	log->SetPosition(position);

	log->Fire(sf::Vector2f(side == Sides::Right ? 1500.f : -1500.f, -700.f));
}

//Sides Tree::GetCurrentSide()
//{
//	return branchList[(currentBranchIndex + 1) % branchList.size()]->GetSide();
//}
int Tree::GetCurrentint()
{
	//return branchList[(currentBranchIndex + 1) % branchList.size()]->GetSide();
	return currentBranchIndex;
}
Sides Tree::GetCurrentSide()
{
	return branchList[currentBranchIndex]->GetSide();
}