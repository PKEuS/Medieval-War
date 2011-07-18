#ifndef GSMENU_HPP
#define GSMENU_HPP

#include <SFML/Graphics.hpp>
#include "GameState.hpp"

class GSMenu : public GameState
{
public:
	GSMenu(sf::RenderWindow& window);
	~GSMenu();

	GameState* Run();
};

#endif
