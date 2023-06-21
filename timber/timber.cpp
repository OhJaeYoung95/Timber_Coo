#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <vector>
#include <sstream>

#include "Utils.h"
#include "GameObject.h"
#include "SpriteGo.h"
#include "MovingBgObj.h"
#include "InputMgr.h"
#include "InputMgr2.h"
#include "Branch.h"
#include "Tree.h"
#include "Player.h"
using namespace std;


int main()
{
    bool isPause = true;
    bool isStart = false;
    bool isTimeOut = false;
    int score = 0;
    int bestScore = 0;

    int screenWidth = 1920;
    int screenHeight = 1080;

    // UI , Text
    sf::Font font;
    font.loadFromFile("fonts/KOMIKAP_.ttf");

    sf::Text textMessage;
    textMessage.setFont(font);
    textMessage.setString("PRESS ENTER TO START!");
    textMessage.setCharacterSize(75);
    textMessage.setFillColor(sf::Color::White);
    Utils::SetOrigin(textMessage, Origins::MC);
    textMessage.setPosition(screenWidth / 2.f, screenHeight / 2.f);

    sf::Text textScore;
    textScore.setFont(font);
    textScore.setString("Score: ???");
    textScore.setCharacterSize(100);
    textScore.setFillColor(sf::Color::White);
    Utils::SetOrigin(textScore, Origins::TL);
    textScore.setPosition(20.f, 20.f);

    sf::Text textBestScore;
    textBestScore.setFont(font);
    textBestScore.setString("Score: ???");
    textBestScore.setCharacterSize(100);
    textBestScore.setFillColor(sf::Color::White);
    Utils::SetOrigin(textBestScore, Origins::MC);
    textBestScore.setPosition(screenWidth / 2.f, screenHeight / 2.f - 100.f);

    // UI Object

    float uiTimerWidth = 400.f;
    float uiTimerheight = 80.f;

    float duration = 6.f;
    float timer = duration;

    // 타이머
    sf::RectangleShape uiTimer;
    uiTimer.setSize(sf::Vector2f(uiTimerWidth, uiTimerheight));
    uiTimer.setFillColor(sf::Color::Red);
    Utils::SetOrigin(uiTimer, Origins::BC);
    uiTimer.setPosition(screenWidth * 0.5f, screenHeight - 50.f);

    // 타이머 프레임
    sf::RectangleShape uiTimerFrame;
    uiTimerFrame.setSize(sf::Vector2f(uiTimerWidth, uiTimerheight));
    uiTimerFrame.setFillColor(sf::Color::White);
    Utils::SetOrigin(uiTimerFrame, Origins::BC);
    uiTimerFrame.setPosition(screenWidth * 0.5f, screenHeight - 50.f);


    // Game Object Image
    sf::Texture texBackground;      // 리소스, 이미지랑 맵핑이 되는 객체 만들어짐 (이미지 파일), 파일과 연관됨
    texBackground.loadFromFile("graphics/background.png");  // 속성 -> 디버깅 -> 작업디렉토리 기준 폴더
    sf::Texture texTree;
    texTree.loadFromFile("graphics/tree.png");
    sf::Texture texCloud;
    texCloud.loadFromFile("graphics/cloud.png");
    sf::Texture texBee;
    texBee.loadFromFile("graphics/bee.png");
    sf::Texture texPlayer;
    texPlayer.loadFromFile("graphics/player.png");
    sf::Texture texPlayer2;
    texPlayer2.loadFromFile("graphics/player2.png");
    sf::Texture texchoiseBG;
    texchoiseBG.loadFromFile("graphics/choiseBG.png");
    sf::Texture texarrow;
    texarrow.loadFromFile("graphics/arrow.png");

    // 1. Init
    std::vector<GameObject*> gameObjects;
    std::vector<GameObject*> plyaerchoise;
    // 배경 생성
    gameObjects.push_back(new SpriteGo(texBackground, sf::Vector2f(1.f, 0.f), "BG", { 0, 0 }));

    // 구름 생성
    for (int i = 0; i < 3; i++)
    {
        MovingBgObj* newGo = new MovingBgObj(texCloud, sf::Vector2f(-1.f, 0.f), "Cloud");
        newGo->SetSpeedRange(sf::Vector2f(300.f, 600.f));
        newGo->SetLRPos(sf::Vector2f(-200.f, 1080.f / 2.f), sf::Vector2f(1920.f + 200.f, 1080.f / 2.f));
        newGo->SetPosXRange(0.f, 0.f);
        newGo->SetPosYRange(-300.f, 300.f);
        gameObjects.push_back(newGo);
    }


    // 벌 생성
    MovingBgObj* beeGo = new MovingBgObj(texBee, sf::Vector2f(-1.f, 0.f), "Bee");
    beeGo->SetSpeedRange(sf::Vector2f(300.f, 600.f));
    beeGo->SetLRPos(sf::Vector2f(-200.f, 1080.f / 2.f), sf::Vector2f(1920.f + 200.f, 1080.f / 2.f));
    beeGo->SetPosXRange(0.f, 0.f);
    beeGo->SetPosYRange(-100.f, 0.f);
    beeGo->SetMoveY(2.f, 200.f);
    gameObjects.push_back(beeGo);


    // 게임에 영향을 끼치는 오브젝트
    // 트리 생성
    Tree* tree = new Tree(gameObjects, texTree, sf::Vector2f(1.f, 0.f), "Tree");
    tree->SetOrigin(Origins::TC);
    tree->SetPosition(screenWidth * 0.5f, 0.f);
    gameObjects.push_back(tree);

    // 플레이어 생성
    Player* player = new Player(texPlayer, sf::Vector2f(-1.f, -1.f), "Player", sf::Vector2f(0.f, 880.f));
    player->SetTree(tree);
    gameObjects.push_back(player);

    // 플레이어2 생성
 /*   NewPlayer* player2 = new NewPlayer(texPlayer2, sf::Vector2f(-1.f, -1.f), "Player2", sf::Vector2f(0.f, 880.f));
*/

// 할일 플레이어가 어떻게 생성되는지 보기, 
// 
// 
// 캐릭터 배경에 캐릭터 두개 넣고
// 엔터키 누르면 게임 플레이 되는 방향으로 근데 이제 선택한 캐릭터로 플레이가 되는

// 대충 생각하기에 수정해야 될 부분이 플레이어 함수에서 변경된 캐릭터로 게임이 플레이 되게
// 이거밖에 없네

//player2->Init();

    for (auto& obj : gameObjects)
    {
        obj->Init();
    }



    sf::RenderWindow window(sf::VideoMode(screenWidth, screenHeight), "Timber!", sf::Style::Default);

    sf::Clock clock;        // 스톱워치처럼 작동. 생성한 후부터 시간이 얼마나 지났는지 갱신

    // 윈도우가 살아있으면

    int selectedCharacter = 0;
    bool isCharacterSelected;
    sf::Sprite player11;
    sf::Sprite player22;
    sf::Sprite choiseBG;
    sf::Sprite arrow;
    choiseBG.setTexture(texchoiseBG);
    choiseBG.setPosition(0.f, 0.f);
    player11.setTexture(texPlayer);
    player22.setTexture(texPlayer2);
    player11.setPosition(1920.f * 0.3, 1080.f * 0.5);
    player22.setPosition(1920.f * 0.6, 1080.f * 0.5);
    player22.setScale(0.5f, 0.3f);
    arrow.setTexture(texarrow);
    arrow.setScale(0.3f, 0.3f);

    while (window.isOpen())
    {
        InputMgr2::ClearInput(); // 입력 상태 초기화

        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();

            InputMgr2::UpdateInput(event);
        }

        if (InputMgr2::GetKeyDown(sf::Keyboard::Left))
        {
            arrow.setPosition(1920.f * 0.3, 300);
            selectedCharacter = 0;
        }

        if (InputMgr2::GetKeyDown(sf::Keyboard::Right))
        {
            arrow.setPosition(1920.f * 0.6, 300);
            selectedCharacter = 1;
        }

        if (InputMgr2::GetKeyDown(sf::Keyboard::Enter))
        {
            break;
        }

        window.clear();
        window.draw(choiseBG);
        window.draw(player11);
        window.draw(player22);
        window.draw(arrow);
        window.display();
    }
}
//
//    while (window.isOpen())
//    {   
//        //InputMgr::Clear();
//        InputMgr2::ClearInput();
//
//        sf::Time dt = clock.restart();           // 스톱워치 재시작
//        float deltaTime = dt.asSeconds();       // 시간을 초로 바꿔준다.
//
//        sf::Event event;
//        while (window.pollEvent(event))     // 이벤트를 모두 비워질때까지 루프를 돈다
//        {
//            //InputMgr::Update(event);
//            InputMgr2::UpdateInput(event);
//
//            switch (event.type)
//            {
//            case sf::Event::Closed:     // 윈도우창 X키 누르는 이벤트
//                window.close();         // 윈도우창 닫기
//                break;
//            }
//        }
//
//        // 2. Update
//
//        // 타이머
//        if (!isPause)   // 게임중일때
//        {
//            timer -= deltaTime;
//            if (timer <= 0.f)
//            {
//                textMessage.setString("OUT OF TIME");
//                Utils::SetOrigin(textMessage, Origins::MC);
//                isPause = true;
//                isTimeOut = true;
//                player->Die(isTimeOut);
//
//                if (score > bestScore)
//                    bestScore = score;
//
//                std::stringstream ss1;
//                ss1 << "BEST SCORE: " << bestScore;
//                textBestScore.setString(ss1.str());
//            }
//            else if (player->GetSide() == tree->GetCurrentSide())
//            {
//                textMessage.setString("Game Over");
//                Utils::SetOrigin(textMessage, Origins::MC);
//                isPause = true;
//                player->Die(isTimeOut);
//
//                if (score > bestScore)
//                    bestScore = score;
//
//                std::stringstream ss1;
//                ss1 << "BEST SCORE: " << bestScore;
//                textBestScore.setString(ss1.str());
//            }
//            else
//            {
//                if ((InputMgr2::GetKeyDown(sf::Keyboard::Left) ||
//                    InputMgr2::GetKeyDown(sf::Keyboard::Right))&& timer <= 5.8f)
//                {
//                    std::cout << tree->GetCurrentint() <<endl;
//                    timer += 0.3f;
//                    score += 1;
//                }
//                // 정규화 퍼센트 단위로 만들어서 타이머의 시간을 통해 타이머
//                float normTime = timer / duration;
//                float timeSizeX = uiTimerWidth * normTime;
//
//
//                uiTimer.setSize(sf::Vector2f(timeSizeX, uiTimerheight));
//                for (auto& obj : gameObjects)
//                {
//                    obj->Update(deltaTime);
//                }
//                    
//                std::stringstream ss;
//                ss << "SCORE: " << score;
//                textScore.setString(ss.str());
//            }
//        }
//        else
//        {
//            if (InputMgr2::GetKeyDown(sf::Keyboard::Return) &&  !isStart)
//            {
//                isTimeOut = false;
//                timer = duration;
//                score = 0;
//                isStart = true;
//                isPause = false;
//            }
//            else if (InputMgr2::GetKeyDown(sf::Keyboard::Return)&& isStart)
//            {
//                isTimeOut = false;
//                timer = duration;
//                score = 0;
//                isPause = false;
//                for (auto& obj : gameObjects)
//                {
//                    if (obj->GetActive())
//                        obj->Init();
//                }
//            }
//        }
//
//        window.clear();     // 백버퍼 클리어
//
//        // 3. Draw
//        for (auto& obj: gameObjects)
//        {
//            if (obj->GetActive())
//                obj->Draw(window);
//        }
//        window.draw(textScore);
//        window.draw(uiTimerFrame);
//        window.draw(uiTimer);
//        if (isPause)
//        {
//            window.draw(textMessage);
//            window.draw(textBestScore);
//        }
//
//        window.display();   // 화면 출력
//    }
//
//    for (auto& obj : gameObjects)
//    {
//        obj->Release();
//        delete obj;
//    }
//    return 0;
//}