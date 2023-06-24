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

	virtual void Init() override;	// 생성자 new 역할
	virtual void Release() override;	// 소멸자 delete 역할
	virtual void Reset() override;	// 값 세팅

	virtual void Update(float dt) override;
	virtual void Draw(sf::RenderWindow& window) override;

	void SetText(const std::string str, int size, sf::Color color, Origins origin, float x, float y);
};

