#include "NewPlayer.h"
#include "InputMgr2.h"

NewPlayer::NewPlayer(sf::Texture& tex, sf::Vector2f spriteDir, const std::string& n, const sf::Vector2f p)
    : SpriteGo(tex, spriteDir, n, p)
{
    texarrow.loadFromFile("graphics /arrow.png");
    arrow = new SpriteGo(texarrow);
    texplayer1.loadFromFile("graphics /player.png");
    texplayer2.loadFromFile("graphics /player2.png");
    texchoiseBG.loadFromFile("graphics/choiseBG.png");// 캐릭터 선택 배경

    isCharacterSelected = false;
    int selectedCharacter = 0;
}

NewPlayer::~NewPlayer()
{
}

void NewPlayer::SetPosition(float x, float y)
{
    SpriteGo::SetPosition(x, y);
}

void NewPlayer::SetPosition(const sf::Vector2f p)
{
    SpriteGo::SetPosition(p);
}

void NewPlayer::Init()
{
    sf::Sprite SetTexture(texchoiseBG);
    arrow->SetPosition(300.f, 500.f);

}

void NewPlayer::Release()
{

}

void NewPlayer::Update(float dt)
{
    SpriteGo::Update(dt);
    if (!isCharacterSelected)
    {
        if (InputMgr2::GetKeyDown(sf::Keyboard::Left))
        {
            arrow->SetPosition(300.f, 500.f);
            selectedCharacter = 0;  // 왼쪽 캐릭터 선택 시 인덱스 0 할당
        }

        if (InputMgr2::GetKeyDown(sf::Keyboard::Right))
        {
            arrow->SetPosition(1300.f, 500.f);
            selectedCharacter = 1;  // 오른쪽 캐릭터 선택 시 인덱스 1 할당
        }

        if (InputMgr2::GetKeyDown(sf::Keyboard::Enter))
        {
            isCharacterSelected = true;

        }

    }
}

void NewPlayer::Draw(sf::RenderWindow& window)
{

     SpriteGo::Draw(window);
     arrow->Draw(window);
}
