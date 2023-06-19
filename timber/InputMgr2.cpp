#include "InputMgr2.h"
#include <iostream>
#include <algorithm>

std::vector<bool> InputMgr2::downList(sf::Keyboard::Key::KeyCount);
std::vector<bool> InputMgr2::ingList(sf::Keyboard::Key::KeyCount);
std::vector<bool> InputMgr2::upList(sf::Keyboard::Key::KeyCount);


void InputMgr2::ClearInput()
{
    for (int i = 0; i < (int)sf::Keyboard::Key::KeyCount; i++)
    {
        downList[i] = false;
        upList[i] = false;
    }
}

void InputMgr2::UpdateInput(const sf::Event& ev)
{
    switch (ev.type)
    {
    case sf::Event::KeyPressed:
        if (!ingList[ev.key.code])
        {
            downList[ev.key.code] = true;
            ingList[ev.key.code] = true;
        }
        break;
    case sf::Event::KeyReleased:
        ingList[ev.key.code] = false;
        upList[ev.key.code] = true;
        break;

    }
}

bool InputMgr2::GetKeyDown(const sf::Keyboard::Key key)
{
    return downList[key];
}

bool InputMgr2::GetKey(const sf::Keyboard::Key key)
{
    return ingList[key];
}

bool InputMgr2::GetKeyUp(const sf::Keyboard::Key key)
{
    return upList[key];
}
