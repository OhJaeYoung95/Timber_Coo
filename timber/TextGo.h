#pragma once
#include "GameObject.h"

class TextGo : public GameObject
{
protected:

public:
	sf::Text text;

	TextGo(const std::string n = "");
	virtual ~TextGo() override;

	virtual void SetPosition(float x, float y) override;
	virtual void SetPosition(const sf::Vector2f p) override;

	virtual void SetOrigin(Origins origin) override;
	virtual void SetOrigin(float x, float y) override;


	void SetSize(float x, float y);
	sf::Vector2f GetSize() const;

	virtual void Init() override;	// ������ new ����
	virtual void Release() override;	// �Ҹ��� delete ����
	virtual void Reset() override;	// �� ����

	virtual void Update(float dt) override;
	virtual void Draw(sf::RenderWindow& window) override;

	void SetText(const std::string str, int size, sf::Color color, Origins origin, float x, float y);
};

