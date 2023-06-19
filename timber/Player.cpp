#include "Player.h"
#include "Tree.h"
#include "InputMgr2.h"

Player::Player(sf::Texture& tex, sf::Vector2f spriteDir, const std::string& n, const sf::Vector2f p) : SpriteGo(tex, spriteDir, n, p), offsetX(100.f), axeOffsetY(77.f), axeOffsetX(58.f), isChopping(false), isAlive(true), texPlayer(tex)
{
	texAxe.loadFromFile("graphics/axe.png");
	axe = new SpriteGo(texAxe);

	SetOrigin(Origins::BC);

	for (auto& position : playerPositions)
	{
		position = p;
	}
	for (auto& position : axePositions)
	{
		position = GetPosition();
	}

	texRip.loadFromFile("graphics/rip.png");

	soundBufferChop.loadFromFile("sound/chop.wav");
	soundBufferDeath.loadFromFile("sound/death.wav");
	soundBufferOutOfTime.loadFromFile("sound/out_of_time.wav");

	soundChop.setBuffer(soundBufferChop);
	soundDeath.setBuffer(soundBufferDeath);
	soundOutOfTime.setBuffer(soundBufferDeath);


}

Player::~Player()
{

}


void Player::SetTree(Tree* tree)
{
	this->tree = tree;
}

void Player::SetSide(Sides side)
{
	this->side = side;
	SetPosition(playerPositions[(int)this->side]);
	SetFlipX(this->side == Sides::Left);

	// ±³¼ö´Ô ÄÚµå
	axe->SetPosition(GetPosition());
	axe->SetFlipX(this->side == Sides::Left);

	// axe
	//axePositions[(int)Sides::Left] = sf::Vector2f(this->GetPosition().x - axeOffsetX, this->GetPosition().y - axeOffsetY);
	//axePositions[(int)Sides::Right] = sf::Vector2f(this->GetPosition().x + axeOffsetX, this->GetPosition().y - axeOffsetY);
	//axe->SetPosition(axePositions[(int)this->side]);
	//axe->SetFlipX(this->side != Sides::Right);
}

Sides Player::GetSide() const
{
	return side;
}

void Player::Chop(Sides side)
{
	SetSide(side);
	sf::Vector2f pos = tree->GetPosition();
	pos.y = tree->GetSize().y;
	Sides effectSide = (Sides)(((int)side + 1) % 2);
	tree->ShowEffectLog(effectSide, pos);
	isChopping = true;
	soundChop.play();
}

void Player::Die(bool isTimeOut)
{
	isAlive = false;
	isChopping = false;

	SetTexture(texRip);
	SetOrigin(Origins::BC);
	SetFlipX(true);
	if (isTimeOut)
		soundOutOfTime.play();
	else
		soundDeath.play();
}

//bool Player::IsAlive()
//{
//	return isAlive;
//}
//
//bool Player::CheckCollide()
//{
//	if (GetSide() == tree->GetCurrentSide())
//		return true;
//	return false;
//}


void Player::SetPosition(float x, float y)
{
	SpriteGo::SetPosition(x, y);
}

void Player::SetPosition(const sf::Vector2f p)
{
	SpriteGo::SetPosition(p);
}

void Player::SetOrigin(Origins origin)
{
	SpriteGo::SetOrigin(origin);
}

void Player::Init()
{
	isAlive = true;
	SetTexture(texPlayer);
	SetOrigin(Origins::BC);

	isChopping = false;

	SpriteGo::Init();

	sf::Vector2f playerSize = GetSize();
	// position
	float treeHalfWidth = tree->GetSize().x * 0.5f;
	float playerHalfWidth = GetSize().x * 0.5f;
	float delta = treeHalfWidth + playerHalfWidth + offsetX;

	playerPositions[(int)Sides::Left].x = tree->GetPosition().x - delta;
	playerPositions[(int)Sides::Right].x = tree->GetPosition().x + delta;

	//±³¼ö´Ô ÄÚµå
	sf::Vector2f axeSize = axe->GetSize();
	axe->SetOrigin(axeSize.x + playerHalfWidth, GetSize().y * + 0.45f);

	axe->Init();
	axe->SetPosition(GetPosition());
	SetSide(Sides::Right);
}

void Player::Release()
{
	delete axe;
	axe = nullptr;

	SpriteGo::Release();
}

void Player::Update(float dt)
{
	SpriteGo::Update(dt);

	if (!isAlive)
		return;
	if (!isChopping)
	{
		if (InputMgr2::GetKeyDown(sf::Keyboard::Left))
		{
			tree->UpdateBranches();
			tree->GetCurrentint();
			Chop(Sides::Left);
		}

		if (InputMgr2::GetKeyDown(sf::Keyboard::Right))
		{
			tree->UpdateBranches();
			tree->GetCurrentint();
			Chop(Sides::Right);
		}

	}
	else
	{
		if (GetSide() == Sides::Left && 
			InputMgr2::GetKeyUp(sf::Keyboard::Left))
		{
			isChopping = false;
		}

		if (GetSide() == Sides::Right && 
			InputMgr2::GetKeyUp(sf::Keyboard::Right))
		{
			isChopping = false;
		}

	}

	axe->Update(dt);
}

void Player::Draw(sf::RenderWindow& window)
{
	SpriteGo::Draw(window);

	if (isChopping)
	{
		axe->Draw(window);
	}

}