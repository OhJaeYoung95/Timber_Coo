#pragma once
#include <SFML/Graphics.hpp>
#include "Defines.h"
#include "InputMgr2.h"
#include "SpriteGo.h"

class PlayerChoise : public SpriteGo
{
private:
    sf::Texture texPlayer1;
    sf::Texture texPlayer2;
    sf::Texture texchoiseBG;
    sf::Texture texarrow;
    int selectedCharacter;
    sf::Sprite player1;
    sf::Sprite player2;
    sf::Sprite choiseBG;
    bool truefalse;
    bool reversetruefalse;
public:
    PlayerChoise(sf::Texture& tex,
        sf::Vector2f spriteDir = sf::Vector2f(-1, -1),
        const std::string& n = "",
        const sf::Vector2f p = { 0, 0 });
    ~PlayerChoise();
    void Init();
    bool TrueFales();
    void CharacterChoise();
    int GetselectedCharacter();
    sf::Texture& GetPlayer();
    void playerchoiseInit();
    void Release();
    void Update(float dt);
    void Draw(sf::RenderWindow& window);
};

