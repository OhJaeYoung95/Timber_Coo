#pragma once
#include <SFML/Graphics.hpp>
#include <vector>

class InputMgr2
{
private:
	static std::vector<bool> downList;
	static std::vector<bool> ingList; 
	static std::vector<bool> upList; 

public:
	static void ClearInput();
	static void UpdateInput(const sf::Event& ev);

	static bool GetKeyDown(const sf::Keyboard::Key key);
	static bool GetKey(const sf::Keyboard::Key key);
	static bool GetKeyUp(const sf::Keyboard::Key key);
};

