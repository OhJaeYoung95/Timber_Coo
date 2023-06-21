#include "InputMgr2.h"
#include "PlayerChoise.h"

class Plyer;
PlayerChoise::PlayerChoise(sf::Texture& tex,
    sf::Vector2f spriteDir,
    const std::string& n,
    const sf::Vector2f p) : selectedCharacter(0), SpriteGo(tex, spriteDir, n, p)
{

    texPlayer1.loadFromFile("graphics/player.png");
    texPlayer2.loadFromFile("graphics/player2.png");
    texchoiseBG.loadFromFile("graphics/choiseBG.png");
    player1.setTexture(texPlayer1);
    player2.setTexture(texPlayer2);
    choiseBG.setTexture(texchoiseBG);
    choiseBG.setPosition(0.f, 0.f);
    player1.setPosition(1920.f * 0.3, 1080.f * 0.5);
    player2.setPosition(1920.f * 0.6, 1080.f * 0.5);
    truefalse = true;
    reversetruefalse = true;
}

PlayerChoise::~PlayerChoise()
{
}

void PlayerChoise::Init()
{

}

bool PlayerChoise::TrueFales()
{
    return reversetruefalse;
}

int PlayerChoise::GetselectedCharacter()
{
    return selectedCharacter;
}

sf::Texture& PlayerChoise::GetPlayer()
{
    if (selectedCharacter == 0)
        return texPlayer1;
    else if (selectedCharacter == 1)
        return texPlayer2;
}


void PlayerChoise::playerchoiseInit()
{

    choiseBG.setTexture(texchoiseBG);
    choiseBG.setPosition(0.f, 0.f);

    player1.setPosition(1920.f * 0.3, 1080.f * 0.5);
    player2.setPosition(1920.f * 0.6, 1080.f * 0.5);

    //arrow.setPosition(1920.f * 0.3, 300);
    //arrow.setScale(0.3f, 0.3f);

}

void PlayerChoise::Release()
{
    SpriteGo::Release();
}
void PlayerChoise::Draw(sf::RenderWindow& window)
{

    
    window.draw(choiseBG);
    SpriteGo::Draw(window);
    window.draw(player2);
    window.draw(player1);
    //배경 플레이어 1,2 넣고  넣고 화살 넣고 겟키다운 함수 호출해서 초이스 하게
}
void PlayerChoise::Update(float dt)
{
    SpriteGo::Update(dt);
    CharacterChoise();

}

void PlayerChoise::CharacterChoise()
{
    if(truefalse)
    {
        if (InputMgr2::GetKeyDown(sf::Keyboard::Left))
        {
            SetPosition(1920.f * 0.3, 300);
            selectedCharacter = 0;
            //player1.setTexture(texPlayer1);
        }

        if (InputMgr2::GetKeyDown(sf::Keyboard::Right))
        {
            SetPosition(1920.f * 0.6, 300);
            selectedCharacter = 1;
            //player1.setTexture(texPlayer2);
        }

        if (InputMgr2::GetKeyDown(sf::Keyboard::Enter))
        {
            GetPlayer();
            truefalse = false;
            reversetruefalse = false;
        }
    }
}