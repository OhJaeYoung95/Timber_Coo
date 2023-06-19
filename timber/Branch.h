#pragma once
#include <SFML/Graphics.hpp>
#include "SpriteGo.h"
#include "Defines.h"

class Tree;

class Branch : public SpriteGo
{
protected:
	//Tree* tree1;
	SpriteGo* tree;
	Sides side;

public:
	Branch(sf::Texture& tex,
		sf::Vector2f spriteDir = sf::Vector2f(-1, -1),
		const std::string& n = "",
		const sf::Vector2f p = { 0, 0 });

	virtual ~Branch();

	virtual void Init() override;
	virtual void Release() override;
	virtual void Update(float dt) override;
	virtual void Draw(sf::RenderWindow& window) override;

	void SetTree(SpriteGo* tree);
	//void SetTree(Tree* tree);
	void SetSide(Sides side);
	Sides GetSide() const;
};

