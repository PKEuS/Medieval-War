#ifndef GSSINGLEPLAYERGAME_HPP
#define GSSINGLEPLAYERGAME_HPP

#include <SFML/Graphics.hpp>
#include "GameState.hpp"

class GSSingleplayerGame : public GameState
{
public:
	GSSingleplayerGame(sf::RenderWindow& window);
	~GSSingleplayerGame();

	GameState* Run();
};

#endif
