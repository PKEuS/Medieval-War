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
	ERROR,
	EXIT,
	ABORT
};


class GameState
{
public:
	GameState(sf::RenderWindow& window);
	virtual ~GameState();

	virtual GameStates Run() = 0;
	
protected:
	sf::RenderWindow& myWindow;
};

#endif


