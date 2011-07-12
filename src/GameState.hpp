#ifndef GAMESTATE_HPP
#define GAMESTATE_HPP

#include <SFML/Graphics.hpp>

enum GameStates
{
	INTRO,
	MENU,
	SINGLEPLAYERGAME,
	MULTIPLAYERGAME,
	MAPEDITOR,
	SETTINGS,
	CREDITS,
	EXIT
};

class GameState
{
public:
	GameState(sf::RenderWindow& window);
	~GameState();

	virtual GameStates Run() = 0;
protected:
	sf::RenderWindow& myWindow;
};

#endif
