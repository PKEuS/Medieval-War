#ifndef GAMESTATE_HPP
#define GAMESTATE_HPP

#include <SFML/Graphics.hpp>


class GameState
{
public:
	GameState(sf::RenderWindow& window);
	virtual ~GameState();

	static int GetReturnValue();

	virtual GameState* Run() = 0;
protected:
	static void SetReturnValue(int returnValue);
	sf::RenderWindow& myWindow;
private:
	static int myReturnValue;
};

#endif
