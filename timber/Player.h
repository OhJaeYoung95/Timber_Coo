#pragma once
#include <SFML/Audio.hpp>
#include "SpriteGo.h"
#include "Defines.h"

class Tree;

class Player : public SpriteGo
{
protected:
	Tree* tree;
	Sides side;

	sf::Texture texAxe;

	SpriteGo* axe;
	float axeOffsetY;
	float axeOffsetX;

	int who;

	float offsetX;
	sf::Vector2f playerPositions[2];
	sf::Vector2f axePositions[2];
	sf::Vector2f axePosition;

	bool isChopping;
	bool isAlive;

	sf::Texture texRip;
	sf::Texture& texPlayer;
	//sf::Texture& texplayer2;

	//Sound
	sf::SoundBuffer soundBufferChop;
	sf::SoundBuffer soundBufferDeath;
	sf::SoundBuffer soundBufferOutOfTime;

	sf::Sound soundChop;
	sf::Sound soundDeath;
	sf::Sound soundOutOfTime;

public:
	Player(sf::Texture& tex,
		sf::Vector2f spriteDir = sf::Vector2f(-1.f, -1.f),
		const std::string& n = "",
		const sf::Vector2f p = { 0, 0 });
	virtual ~Player();

	void SetTree(Tree* tree);
	void SetSide(Sides side);
	void SetWho(int who);
	Sides GetSide() const;
	void Chop(Sides side);
	void Die(bool isTimeOut);

	bool IsAlive();
	//bool CheckCollide();

	virtual void SetPosition(float x, float y);
	virtual void SetPosition(const sf::Vector2f p);

	virtual void SetOrigin(Origins origin);	

	virtual void Init();
	virtual void Release();

	virtual void Update(float dt);
	virtual void Draw(sf::RenderWindow& window);

};

