#ifndef GAMEENGINE_HPP
#define GAMEENGINE_HPP

#include <SFML/Graphics.hpp>
#include "GameState.hpp"
#include "Settings.hpp"

class GameEngine
{
public:
	GameEngine(Settings& settings);
	~GameEngine();

	int Run();
private:
	sf::RenderWindow myWindow;
	GameStates myCurrentGameState;
	
	Settings& mySettings;
};

#endif
