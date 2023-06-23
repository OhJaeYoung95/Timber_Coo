#include "stdafx.h"
#include "TextGo.h"

TextGo::TextGo(const std::string n) 
	: GameObject(n)
{
}

TextGo::~TextGo()
{
}

void TextGo::SetPosition(float x, float y)
{
	position.x = x;
	position.y = y;
	text.setPosition(position);
}

void TextGo::SetPosition(const sf::Vector2f p)
{
	position = p;
	text.setPosition(position);
}

void TextGo::SetOrigin(Origins origin)
{
	Utils::SetOrigin(text, origin);
}

void TextGo::SetOrigin(float x, float y)
{
	text.setOrigin(x, y);
}

void TextGo::SetSize(float x, float y)
{
	text.setScale(x, y);
}

sf::Vector2f TextGo::GetSize() const
{
	sf::FloatRect rect = text.getLocalBounds();
	return sf::Vector2f(rect.width, rect.height);
}


void TextGo::Init()
{
}

void TextGo::Release()
{
}

void TextGo::Reset()
{
}

void TextGo::Update(float dt)
{
}

void TextGo::Draw(sf::RenderWindow& window)
{
	window.draw(text);
}

void TextGo::SetText(const std::string str, int size, sf::Color color, Origins origin, float x, float y)
{
	text.setString(str);
	text.setCharacterSize(size);
	text.setFillColor(color);
	Utils::SetOrigin(text, origin);
	text.setPosition(x, y);
}
