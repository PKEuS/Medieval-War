#ifndef GAMEENGINE_HPP
#define GAMEENGINE_HPP

#include <SFML/Graphics.hpp>
#include "GameState.hpp"

class GameEngine
{
public:
	GameEngine(int argc, char* argv[]);
	~GameEngine();

	void Run();
private:
	sf::RenderWindow myWindow;
	GameStates myCurrentGameState;
};

#endif
