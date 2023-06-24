#pragma once
#include "GameObject.h"

class SpriteGo : public GameObject
{
protected:

public:
	sf::Sprite sprite;
	sf::Vector2f spriteDir;		// �� �� ���� üũ

	SpriteGo(const std::string n = "");
	virtual ~SpriteGo() override;

	virtual void SetPosition(float x, float y) override;
	virtual void SetPosition(const sf::Vector2f p) override;

	virtual void SetOrigin(Origins origin) override;
	virtual void SetOrigin(float x, float y) override;


	void SetSize(float x, float y);
	sf::Vector2f GetSize() const;

	void SetTexture(sf::Texture& tex, sf::Vector2f spriteDir = sf::Vector2f(-1.f, 0.f));

	virtual void Init() override;	// ������ new ����
	virtual void Release() override;	// �Ҹ��� delete ����
	virtual void Reset() override;	// �� ����

	virtual void Update(float dt) override;
	virtual void Draw(sf::RenderWindow& window) override;

	void SetFlipX(bool flip);
	void SetFlipY(bool flip);
};

