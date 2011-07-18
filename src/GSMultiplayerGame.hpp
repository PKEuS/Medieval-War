#ifndef GSMULTIPLAYERGAME_HPP
#define GSMULTIPLAYERGAME_HPP

#include <SFML/Graphics.hpp>
#include "GameState.hpp"

class GSMultiplayerGame : public GameState
{
public:
	GSMultiplayerGame(sf::RenderWindow& window);
	~GSMultiplayerGame();

	GameState* Run();
};

#endif
