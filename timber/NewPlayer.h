#pragma once
#include "SpriteGo.h"
#include "Defines.h"
#include <SFML/Audio.hpp>
#include "NewPlayer.h"


class NewPlayer : public SpriteGo
{
private:


	SpriteGo* arrow; // 캐릭터 선택 화살표
	sf::Texture texarrow;
	sf::Texture texchoiseBG; // 캐릭터 선택 배경
	sf::Texture texplayer1;
	sf::Texture texplayer2;
	bool isCharacterSelected;
	int selectedCharacter;

public:
	NewPlayer(sf::Texture& tex,
		sf::Vector2f spriteDir = sf::Vector2f(-1.f, -1.f),
		const std::string& n = "",
		const sf::Vector2f p = { 0, 0 });
	virtual ~NewPlayer();

	virtual void SetPosition(float x, float y);
	virtual void SetPosition(const sf::Vector2f p);

	virtual void Init() override;
	virtual void Release() override;
	virtual void Update(float dt) override;
	virtual void Draw(sf::RenderWindow& window) override;
};

