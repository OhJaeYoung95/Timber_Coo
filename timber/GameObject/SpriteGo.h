#pragma once
#include "GameObject.h"

class SpriteGo : public GameObject
{
protected:

public:
	sf::Sprite sprite;
	sf::Vector2f spriteDir;		// 谅 快 规氢 眉农

	SpriteGo(const std::string n = "");
	virtual ~SpriteGo() override;

	virtual void SetPosition(float x, float y) override;
	virtual void SetPosition(const sf::Vector2f p) override;

	virtual void SetOrigin(Origins origin) override;
	virtual void SetOrigin(float x, float y) override;


	void SetSize(float x, float y);
	sf::Vector2f GetSize() const;

	void SetTexture(sf::Texture& tex, sf::Vector2f spriteDir = sf::Vector2f(-1.f, 0.f));

	virtual void Init() override;	// 积己磊 new 开且
	virtual void Release() override;	// 家戈磊 delete 开且
	virtual void Reset() override;	// 蔼 技泼

	virtual void Update(float dt) override;
	virtual void Draw(sf::RenderWindow& window) override;

	void SetFlipX(bool flip);
	void SetFlipY(bool flip);
};

