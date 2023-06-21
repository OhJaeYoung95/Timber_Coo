#include "PlayGame.h"
#include "Tree.h"

PlayGame::PlayGame(SceneManager& _scene, SceneType _type)
    : Scene(_type), modeIndex(0), characterIndex(0), scene(_scene), isPlaying(false)
{
    SetScene(_scene);

    // texture 불러오기
    font.loadFromFile("fonts/KOMIKAP_.ttf");
    texBackground.loadFromFile("graphics/background.png");
    texTree.loadFromFile("graphics/tree.png");
    texCloud.loadFromFile("graphics/cloud.png");
    texBee.loadFromFile("graphics/bee.png");

    texPlayer1.loadFromFile("graphics/player.png");
    texPlayer2.loadFromFile("graphics/player.png");

    // 배경 생성
    gameObjects.push_back(new SpriteGo(texBackground, sf::Vector2f(1.f, 0.f), "BG", { 0, 0 }));

    // 구름 생성
    for (int i = 0; i < 3; i++)
    {
        MovingBgObj* newGo = new MovingBgObj(texCloud, sf::Vector2f(-1.f, -1.f), "Cloud");
        newGo->SetSpeedRange(sf::Vector2f(300.f, 600.f));
        newGo->SetLRPos(sf::Vector2f(-200.f, 1080.f / 2.f), sf::Vector2f(1920.f + 200.f, 1080.f / 2.f));
        newGo->SetPosXRange(0.f, 0.f);
        newGo->SetPosYRange(-500.f, -100.f);
        gameObjects.push_back(newGo);
    }

    // 벌 생성
    MovingBgObj* beeGo = new MovingBgObj(texBee, sf::Vector2f(-1.f, -1.f), "Bee");
    beeGo->SetSpeedRange(sf::Vector2f(300.f, 600.f));
    beeGo->SetLRPos(sf::Vector2f(-200.f, 1080.f / 2.f), sf::Vector2f(1920.f + 200.f, 1080.f / 2.f));
    beeGo->SetPosXRange(0.f, 0.f);
    beeGo->SetPosYRange(-100.f, 0.f);
    beeGo->SetMoveY(2.f, 200.f);
    gameObjects.push_back(beeGo);

    // 트리 생성
    for (int i = 0; i < 2; i++)
    {
        tree.push_back(new Tree(gameObjects, texTree, sf::Vector2f(1.f, 0.f), "Tree"));
        tree[i]->SetOrigin(Origins::TC);
    }

    // 플레이어 생성
    player.push_back(new Player(texPlayer1, sf::Vector2f(-1.f, -1.f), "P1", sf::Vector2f(0.f, 880.f)));
    player.push_back(new Player(texPlayer2, sf::Vector2f(-1.f, -1.f), "P2", sf::Vector2f(0.f, 880.f)));

    player[0]->SetTree(tree[0]);
    player[1]->SetTree(tree[1]);

}

PlayGame::~PlayGame()
{

}

void PlayGame::Init(ModeSelect mode, SceneManager& sceneM)
{
    // 플레이어 1,2 텍스쳐
    texPlayer1.loadFromFile(sceneM.GetPlayer1());
    texPlayer2.loadFromFile(sceneM.GetPlayer2());

	modeIndex = 0;
	characterIndex = 0;
	modeIndex = sceneM.GetModeIndex();
	characterIndex = sceneM.GetCharacterIndex();
    modeP = (ModeSelect)modeIndex;

    isPause = true;
    isStart = false;
    isTimeOut = false;
    score1 = 0;
    score2 = 0;
    bestScore = 0;
    screenWidth = 1920;
    screenHeight = 1080;
    duration = 6.f;
    timer1 = duration;
    uiTimerWidth = 400.f;
    uiTimerheight = 80.f;

    // 중앙 메시지 : String, Color 모드 개별화
    textMessage.setFont(font);
    textMessage.setString("PRESS ENTER TO START!");
    textMessage.setCharacterSize(75);
    textMessage.setFillColor(sf::Color::White);
    Utils::SetOrigin(textMessage, Origins::MC);
    textMessage.setPosition(screenWidth /2.f,screenHeight /2.f);

    // 스코어1 : String, Size, Color, Origin, Position 모드 화
    textScore1.setFont(font);
    textScore1.setString("Score: ???");
    textScore1.setCharacterSize(100);
    textScore1.setFillColor(sf::Color::White);
    Utils::SetOrigin(textScore1, Origins::TR);
    textScore1.setPosition(1900.f, 20.f);

    // 스코어2
    textScore2.setFont(font);
    textScore2.setString("Score: ???");
    textScore2.setCharacterSize(100);
    textScore2.setFillColor(sf::Color::White);
    Utils::SetOrigin(textScore2, Origins::TL);
    textScore2.setPosition(20.f, 20.f);

    // 베스트 스코어 : String, Size, Color, Origin, Position드별화
    textBestScore.setFont(font);
    textBestScore.setString("Score: ???");
    textBestScore.setCharacterSize(100);
    textBestScore.setFillColor(sf::Color::White);
    Utils::SetOrigin(textBestScore, Origins::MC);
    textBestScore.setPosition(screenWidth /2.f,screenHeight /2.f- 100.f);
    textBestScore.setString("");

    // 타이머1 : Size, Origin, Position 모드 개별화
    uiTimer1.setSize(sf::Vector2f(uiTimerWidth,uiTimerheight));
    uiTimer1.setFillColor(sf::Color::Red);
    Utils::SetOrigin(uiTimer1, Origins::BC);
    uiTimer1.setPosition(screenWidth * 0.5f, screenHeight-50.f);

    // 타이머2
    uiTimer2.setSize(sf::Vector2f(uiTimerWidth,uiTimerheight));
    uiTimer2.setFillColor(sf::Color::Red);
    Utils::SetOrigin(uiTimer2, Origins::BC);
    uiTimer2.setPosition(screenWidth / 4.f, screenHeight-50.f);

    // 타이머 프레임1 : Size, Origin, Position 모드 개별화
    uiTimerFrame1.setSize(sf::Vector2f(uiTimerWidth,uiTimerheight));
    uiTimerFrame1.setFillColor(sf::Color::White);
    Utils::SetOrigin(uiTimerFrame1, Origins::BC);
    uiTimerFrame1.setPosition(uiTimer1.getPosition());

    // 타이머 프레임2
    uiTimerFrame2.setSize(sf::Vector2f(uiTimerWidth,uiTimerheight));
    uiTimerFrame2.setFillColor(sf::Color::White);
    Utils::SetOrigin(uiTimerFrame2, Origins::BC);
    uiTimerFrame2.setPosition(screenWidth / 4.f, screenHeight - 50.f);
    
    if (modeP == ModeSelect::Multi)
        {
            // tree 위치
            tree[0]->SetPosition(screenWidth / 4.f*3.f, 0.f);
            tree[1]->SetPosition(screenWidth / 4.f, 0.f);

            // uiTimer1 위치
            uiTimer1.setPosition(screenWidth / 4.f * 3.f, screenHeight - 50.f);
            uiTimerFrame1.setPosition(screenWidth / 4.f * 3.f, screenHeight - 50.f);
        }
    for (auto& obj : gameObjects)
    {
        obj->Init();
    }
    
    tree[0]->Init();
    tree[1]->Init();

    player[0]->SetTree(tree[0]);
    player[1]->SetTree(tree[1]);

    player[0]->SetWho(1);
    player[1]->SetWho(2);


    for (auto& it : player)
    {
        it->Init();
    }
    
    player[0]->SetTexture(texPlayer1);
    player[1]->SetTexture(texPlayer2);


    if (modeP == ModeSelect::Solo)
    {
        player[1]->SetActive(false);
        tree[0]->SetPosition(screenWidth / 2.f, 0.f);
        tree[0]->Init();
        player[0]->Init();
        tree[1]->SetActive(false);
    }
}

void PlayGame::Draw(sf::RenderWindow& window)
{

        for (auto& obj : gameObjects)
        {
            if (obj->GetActive())
                obj->Draw(window);
        }

        // 솔로
        if (modeP == ModeSelect::Solo)
        {
            tree[0]->Draw(window);
            player[0]->Draw(window);
            window.draw(uiTimerFrame1);
            window.draw(uiTimer1);
            window.draw(textScore1);
        }
        // 멀티
        else if (modeP == ModeSelect::Multi)        
        {
            for (int i = 0; i < 2; i++)
            {
                tree[i]->Draw(window);
                player[i]->Draw(window);
            }

            window.draw(textScore1);
            window.draw(uiTimerFrame1);
            window.draw(uiTimer1);

            window.draw(textScore2);
            window.draw(uiTimerFrame2);
            window.draw(uiTimer2);
        }

    if (isPause)
    {
        window.draw(textMessage);
        window.draw(textBestScore);
    }
}

void PlayGame::SetScene(SceneManager& sceneM)
{
    this->scene = sceneM;
}

void PlayGame::Release()
{
    for (auto& obj : gameObjects)
    {
        obj->Release();
        delete obj;
    }

    for (auto& obj : tree)
    {
        obj->Release();
        delete obj;
    }
    
    for (auto& obj : player)
    {
        obj->Release();
        delete obj;
    }
}

void PlayGame::Update(float dt, SceneManager& sceneM)
{
	if (InputMgr2::GetKeyDown(sf::Keyboard::Enter))
	{
		sceneM.SetScene(SceneType::Play);
	}

	if (InputMgr2::GetKeyDown(sf::Keyboard::Tab))
	{
		sceneM.SetScene(SceneType::GameMode);
	}	

    // 2. Update
    if (modeP == ModeSelect::Solo)
    {
        isPlaying = true;

        // UPDATE

        if (!isPause)   // 게임중일때
        {
            timer1 -= dt;
            if (timer1 <= 0.f)
            {
                timer1 = 0;
                textMessage.setString("OUT OF TIME");
                isPause = true;
                isTimeOut = true;
                player[0]->Die(isTimeOut);
                isPlaying = false;

                if (score1 > bestScore)
                    bestScore = score1;

                std::stringstream ss1;
                ss1 << "BEST SCORE: " << bestScore;
                textBestScore.setString(ss1.str());
            }
            else if (player[0]->GetSide() == tree[0]->GetCurrentSide())
            {
                textMessage.setString("Game Over");
                Utils::SetOrigin(textMessage, Origins::MC);
                isPause = true;
                player[0]->Die(isTimeOut);
                isPlaying = false;

                if (score1 > bestScore)
                    bestScore = score1;

                std::stringstream ss1;
                ss1 << "BEST SCORE: " << bestScore;
                textBestScore.setString(ss1.str());
            }
            else
            {
                if ((InputMgr2::GetKeyDown(sf::Keyboard::Left) ||
                    InputMgr2::GetKeyDown(sf::Keyboard::Right)) && timer1 <= 5.8f)
                {
                    std::cout << tree[0]->GetCurrentint() << std::endl;
                    timer1 += 0.3f;
                    score1 += 1;
                }
                // 정규화 퍼센트 단위로 만들어서 타이머의 시간을 통해 타이머
                float normTime = timer1 / duration;
                float timeSizeX = uiTimerWidth * normTime;


                uiTimer1.setSize(sf::Vector2f(timeSizeX, uiTimerheight));
                for (auto& obj : gameObjects)
                {
                    obj->Update(dt);
                }

                tree[0]->Update(dt);
                player[0]->Update(dt);

                std::stringstream ss;
                ss << "SCORE: " << score1;
                textScore1.setString(ss.str());
            }
        }
        else
        {
            if (InputMgr2::GetKeyDown(sf::Keyboard::Return) && !isStart)
            {
                isTimeOut = false;
                timer1 = duration;
                score1 = 0;
                isStart = true;
                isPause = false;
            }
            else if (InputMgr2::GetKeyDown(sf::Keyboard::Return) && isStart)
            {
                Init(ModeSelect::Solo, scene);
                textBestScore.setString("");
            }
        }

    }
    if (modeP == ModeSelect::Multi)
    {
        if (!isPause)   // 게임중일때
        {
            // 타임아웃의 경우
            timer1 -= dt;
            timer2 -= dt;
            if (timer1 <= 0.f)
            {
                timer1 = 0;
                textMessage.setCharacterSize(40);
                textMessage.setPosition(screenWidth / 4.f, screenHeight / 2.f);
                textMessage.setString("OUT OF TIME");
                Utils::SetOrigin(textMessage, Origins::MC);
                player[0]->Die(isTimeOut);
                if (score1 > bestScore)
                    bestScore = score1;
            }

            if (timer2 <= 0.f)
            {
                timer2 = 0;
                textMessage.setCharacterSize(40);
                textMessage.setPosition(screenWidth / 4.f * 3.f, screenHeight / 2.f);
                textMessage.setString("OUT OF TIME");
                Utils::SetOrigin(textMessage, Origins::MC);
                player[1]->Die(isTimeOut);
                if (score2 > bestScore)
                    bestScore = score2;
            }

            //if(timer1 <= 0.f && timer2 <= 0.f)
            //{
            //    isPause = true;
            //    isTimeOut = true;
            //    std::stringstream ss1;
            //    ss1 << "BEST SCORE: " << bestScore;
            //    textBestScore.setString(ss1.str());
            //}

            // 충돌 시
            if (player[0]->GetSide() == tree[0]->GetCurrentSide())
            {
                timer1 = 0;
                player[0]->Die(isTimeOut);

                if (score1 > bestScore)
                    bestScore = score1;
            }

            if (player[1]->GetSide() == tree[1]->GetCurrentSide())
            {
                timer2 = 0;
                player[1]->Die(isTimeOut);

                if (score2 > bestScore)
                    bestScore = score2;
            }

            // 둘 다 죽은 경우
            if (player[0]->IsAlive() == false && player[1]->IsAlive() == false)
            {
                timer1 = 0;
                timer2 = 0;
                isPause = true;
                textMessage.setCharacterSize(75);
                textMessage.setPosition(screenWidth / 2.f, screenHeight / 2.f);
                textMessage.setString("Game Over");
                std::stringstream ss1;
                ss1 << "BEST SCORE: " << bestScore;
                textBestScore.setString(ss1.str());
            }

            // 둘 다 죽은 경우
            if (player[0]->IsAlive() == true || player[1]->IsAlive() == true)
            {
                if ((InputMgr2::GetKeyDown(sf::Keyboard::Left) ||
                    InputMgr2::GetKeyDown(sf::Keyboard::Right)) && timer1 <= 5.8f)
                {
                    std::cout << tree[0]->GetCurrentint() << std::endl;
                    if (player[0]->IsAlive() == true)
                    {
                        timer1 += 0.3f;
                        score1 += 1;
                    }
                }

                if ((InputMgr2::GetKeyDown(sf::Keyboard::A) ||
                    InputMgr2::GetKeyDown(sf::Keyboard::D)) && timer2 <= 5.8f)
                {
                    std::cout << tree[1]->GetCurrentint() << std::endl;
                    if (player[1]->IsAlive() == true)
                    {
                        timer2 += 0.3f;
                        score2 += 1;
                    }
                }

                // 정규화 퍼센트 단위로 만들어서 타이머의 시간을 통해 타이머
                float normTime1 = timer1 / duration;
                float timeSizeX1 = uiTimerWidth * normTime1;

                float normTime2 = timer2 / duration;
                float timeSizeX2 = uiTimerWidth * normTime2;

                uiTimer1.setSize(sf::Vector2f(timeSizeX1, uiTimerheight));
                uiTimer2.setSize(sf::Vector2f(timeSizeX2, uiTimerheight));

                for (auto& obj : gameObjects)
                {
                    obj->Update(dt);
                }

                for (auto& it : tree)
                {
                    it->Update(dt);
                }

                for (auto& it : player)
                {
                    it->Update(dt);
                }

                std::stringstream ss1;
                ss1 << "SCORE: " << score1;
                textScore1.setString(ss1.str());

                std::stringstream ss2;
                ss2 << "SCORE: " << score2;
                textScore2.setString(ss2.str());
            }
        }
        else // 멈췄을 때
        {
            if (InputMgr2::GetKeyDown(sf::Keyboard::Return) && !isStart)
            {
                isTimeOut = false;
                timer1 = duration;
                timer2 = duration;
                score1 = 0;
                score2 = 0;
                isStart = true;
                isPause = false;
            }
            else if (InputMgr2::GetKeyDown(sf::Keyboard::Return) && isStart)
            {
                Init(ModeSelect::Multi, scene);
                textBestScore.setString("");
            }
        }
    }
}