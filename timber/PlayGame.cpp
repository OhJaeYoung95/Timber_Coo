#include "PlayGame.h"
#include "Tree.h"

PlayGame::PlayGame(ModeSelect mode)
	: mode(mode), window(sf::VideoMode(1920.f, 1080.f), "Timber!", sf::Style::Default)
{
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
        newGo->SetPosYRange(-300.f, 300.f);
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

void PlayGame::Init(ModeSelect mode)
{
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
    dt = clock.restart();
    deltaTime = dt.asSeconds();

    // 중앙 메시지 : String, Color 모드 개별화
    textMessage.setFont(font);
    textMessage.setString("PRESS ENTER TO START!");
    textMessage.setCharacterSize(75);
    textMessage.setFillColor(sf::Color::White);
    Utils::SetOrigin(textMessage, Origins::MC);
    textMessage.setPosition(screenWidth / 2.f, screenHeight / 2.f);

    // 스코어 : String, Size, Color, Origin, Position 모드 개별화
    textScore1.setFont(font);
    textScore1.setString("Score: ???");
    textScore1.setCharacterSize(100);
    textScore1.setFillColor(sf::Color::White);
    Utils::SetOrigin(textScore1, Origins::TL);
    textScore1.setPosition(20.f, 20.f);

    // 스코어2
    textScore2.setFont(font);
    textScore2.setString("Score: ???");
    textScore2.setCharacterSize(100);
    textScore2.setFillColor(sf::Color::White);
    Utils::SetOrigin(textScore2, Origins::TR);
    textScore2.setPosition(1900.f, 20.f);

    // 베스트 스코어 : String, Size, Color, Origin, Position 모드 개별화
    textBestScore.setFont(font);
    textBestScore.setString("Score: ???");
    textBestScore.setCharacterSize(100);
    textBestScore.setFillColor(sf::Color::White);
    Utils::SetOrigin(textBestScore, Origins::MC);
    textBestScore.setPosition(screenWidth / 2.f, screenHeight / 2.f - 100.f);

    // 타이머 : Size, Origin, Position 모드 개별화
    uiTimer1.setSize(sf::Vector2f(uiTimerWidth, uiTimerheight));
    uiTimer1.setFillColor(sf::Color::Red);
    Utils::SetOrigin(uiTimer1, Origins::BC);
    uiTimer1.setPosition(screenWidth * 0.5f, screenHeight - 50.f);

    uiTimer2.setSize(sf::Vector2f(uiTimerWidth, uiTimerheight));
    uiTimer2.setFillColor(sf::Color::Red);
    Utils::SetOrigin(uiTimer2, Origins::BC);
    uiTimer2.setPosition(screenWidth / 4.f * 3.f, screenHeight - 50.f);

    // 타이머 프레임 : Size, Origin, Position 모드 개별화
    uiTimerFrame1.setSize(sf::Vector2f(uiTimerWidth, uiTimerheight));
    uiTimerFrame1.setFillColor(sf::Color::White);
    Utils::SetOrigin(uiTimerFrame1, Origins::BC);
    uiTimerFrame1.setPosition(screenWidth * 0.5f, screenHeight - 50.f);

    uiTimerFrame2.setSize(sf::Vector2f(uiTimerWidth, uiTimerheight));
    uiTimerFrame2.setFillColor(sf::Color::White);
    Utils::SetOrigin(uiTimerFrame2, Origins::BC);
    uiTimerFrame2.setPosition(screenWidth / 4.f * 3.f, screenHeight - 50.f);


    dt = clock.restart();
    deltaTime = dt.asSeconds();
    
    for (auto& obj : gameObjects)
    {
        obj->Init();
    }

    for (auto& it : tree)
    {
        it->Init();
    }

    for (auto& it : player)
    {
        it->Init();
    }
    
    if (mode == ModeSelect::Multi)
        {
            // tree 위치, 사이즈 변경
            tree[0]->SetSize(0.5f, 1.f);
            tree[0]->SetPosition(screenWidth / 4.f, 0.f);
            tree[1]->SetSize(0.5f, 1.f);
            tree[1]->SetPosition(screenWidth / 4.f * 3.f, 0.f);

            // uiTimer1 위치
            uiTimer1.setPosition(screenWidth / 4.f * 1.f, screenHeight - 50.f);

            // uiTimer1 위치
            uiTimerFrame1.setPosition(screenWidth / 4.f * 1.f, screenHeight - 50.f);
        }
}

void PlayGame::SoloPlay()
{
    Init(ModeSelect::Solo);

    while (window.isOpen())
    {
        player[1]->SetActive(false);
        tree[1]->SetActive(false);

        InputMgr2::ClearInput();

        dt = clock.restart();           // 스톱워치 재시작
        deltaTime = dt.asSeconds();       // 시간을 초로 바꿔준다.

        sf::Event event;
        while (window.pollEvent(event))     // 이벤트를 모두 비워질때까지 루프를 돈다
        {
            InputMgr2::UpdateInput(event);

            switch (event.type)
            {
            case sf::Event::Closed:     // 윈도우창 X키 누르는 이벤트
                window.close();         // 윈도우창 닫기
                break;
            }
        }

        // UPDATE

        if (!isPause)   // 게임중일때
        {
            timer1 -= deltaTime;
            if (timer1 <= 0.f)
            {
                textMessage.setString("OUT OF TIME");
                isPause = true;
                isTimeOut = true;
                player[0]->Die(isTimeOut);

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
                    obj->Update(deltaTime);
                }

                tree[0]->Update(deltaTime);
                player[0]->Update(deltaTime);

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
                Init(ModeSelect::Solo);
            }
        }
        window.clear();
        Draw(ModeSelect::Solo);
    }
    Release();
}

void PlayGame::MultiPlay()
{
    Init(ModeSelect::Multi);
    while (window.isOpen())
    {
        //InputMgr::Clear();
        InputMgr2::ClearInput();

        dt = clock.restart();           // 스톱워치 재시작
        deltaTime = dt.asSeconds();       // 시간을 초로 바꿔준다.

        sf::Event event;
        while (window.pollEvent(event))     // 이벤트를 모두 비워질때까지 루프를 돈다
        {
            //InputMgr::Update(event);
            InputMgr2::UpdateInput(event);

            switch (event.type)
            {
            case sf::Event::Closed:     // 윈도우창 X키 누르는 이벤트
                window.close();         // 윈도우창 닫기
                break;
            }
        }

        // 2. Update

        // 타이머
        if (!isPause)   // 게임중일때
        {
            timer1 -= deltaTime;
            timer2 -= deltaTime;
            if (timer1 <= 0.f)
            {
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
                textMessage.setCharacterSize(40);
                textMessage.setPosition(screenWidth / 4.f*3.f, screenHeight / 2.f);
                textMessage.setString("OUT OF TIME");
                Utils::SetOrigin(textMessage, Origins::MC);
                player[1]->Die(isTimeOut);
                if (score2 > bestScore)
                    bestScore = score2;
            }
            if(timer1 <= 0.f && timer2 <= 0.f)
            {
                std::stringstream ss1;
                ss1 << "BEST SCORE: " << bestScore;
                textBestScore.setString(ss1.str());
                isPause = true;
                isTimeOut = true;
            }
            else // 타임아웃 아닐 때
            {
                if (player[0]->GetSide() == tree[0]->GetCurrentSide())
                {
                    player[0]->Die(isTimeOut);

                    if (score1 > bestScore)
                        bestScore = score1;
                }
                if (player[1]->GetSide() == tree[1]->GetCurrentSide())
                {
                    player[1]->Die(isTimeOut);

                    if (score2 > bestScore)
                        bestScore = score2;
                }
                if (player[0]->GetSide() == tree[0]->GetCurrentSide() && player[1]->GetSide() == tree[1]->GetCurrentSide())
                {
                    textMessage.setCharacterSize(75);
                    textMessage.setPosition(screenWidth / 2.f, screenHeight / 2.f);
                    textMessage.setString("Game Over");
                    isPause = true;
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
                    if ((InputMgr2::GetKeyDown(sf::Keyboard::A) ||
                        InputMgr2::GetKeyDown(sf::Keyboard::B)) && timer2 <= 5.8f)
                    {
                        std::cout << tree[1]->GetCurrentint() << std::endl;
                        timer2 += 0.3f;
                        score2 += 1;
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
                        obj->Update(deltaTime);
                    }

                    std::stringstream ss1;
                    ss1 << "SCORE: " << score1;
                    textScore1.setString(ss1.str());

                    std::stringstream ss2;
                    ss2 << "SCORE: " << score2;
                    textScore2.setString(ss2.str());
                }
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
                Init(ModeSelect::Multi);
            }
        }
        window.clear();
        Draw(ModeSelect::Multi);
    }
    Release();
}

void PlayGame::Draw(ModeSelect mode)
{
    for (auto& obj : gameObjects)
    {
        if (obj->GetActive())
            obj->Draw(window);
    }

    // 솔로
    if (mode == ModeSelect::Solo)
    {
        
        tree[0]->Draw(window);
        player[0]->Draw(window);
        window.draw(textScore1);
        window.draw(uiTimerFrame1);
        window.draw(uiTimer1);
    }

    // 멀티
    else if (mode == ModeSelect::Multi)
    {
        for (int i = 0; i < 2; i++)
        {
            tree[0]->Draw(window);
            player[0]->Draw(window);
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

    window.display();   // 화면 출력
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