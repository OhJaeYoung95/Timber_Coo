#include <SFML/Graphics.hpp>
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
#include "SceneManager.h"
#include "Title.h"
#include "GameMode.h"
#include "SelectCharacter.h"
#include "PlayGame.h"
#include "PlayerChoise.h"

using namespace std;
int main()
{
    sf::Time dt;
    sf::Clock clock;
    float deltaTime;
    int screenWidth = 1920;
    int screenHeight = 1080;

    SceneManager scene;
    scene.Init();

    sf::RenderWindow window(sf::VideoMode(screenWidth, screenHeight), "Timber!", sf::Style::Default);

    while (window.isOpen())
    {
        InputMgr2::ClearInput();
        dt = clock.restart();           // 스톱워치 재시작
        deltaTime = dt.asSeconds();       // 시간을 초로 바꿔준다.

        sf::Event event;
        while (window.pollEvent(event))
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
        scene.Update(deltaTime);
        window.clear();

        scene.Draw(window);
        window.display();
    }
    scene.Release();

    return 0;
}