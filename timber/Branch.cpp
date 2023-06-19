#include "Branch.h"
#include "Tree.h"

Branch::Branch(sf::Texture& tex, sf::Vector2f spriteDir, 
    const std::string& n, const sf::Vector2f p) 
    :SpriteGo(tex, spriteDir, n, p), tree(nullptr), side(Sides::Left)
{
}

Branch::~Branch()
{
}



void Branch::Init()
{
    isActive = true;
    SpriteGo::Init();
    sf::Vector2f treeSize = tree->GetSize();
    sf::Vector2f branchSize = GetSize();
    sprite.setOrigin(-treeSize.x * 0.5f, branchSize.y * 0.5f);
    SetPosition(tree->GetPosition());
}

void Branch::Release()
{
    SpriteGo::Release();
}

void Branch::Update(float dt)
{
    SpriteGo::Update(dt);

}

void Branch::Draw(sf::RenderWindow& window)
{
    SpriteGo::Draw(window);

}

void Branch::SetTree(SpriteGo* tree)
{
    this->tree = tree;
}

//void Branch::SetTree(Tree* tree)
//{
//    this->tree = tree;
//}

void Branch::SetSide(Sides side)
{
    this->side = side;
    switch (side)
    {
    case Sides::Left:
        SetFlipX(true);
        break;
    case Sides::Right:
        SetFlipX(false);
        break;
    }
}

Sides Branch::GetSide() const
{
    return side;
}