#ifndef GSERROR_HPP
#define GSERROR_HPP

#include <SFML/Graphics.hpp>
#include "GameState.hpp"


class GSError : public GameState
{
public:
	GSError(sf::RenderWindow& window);
	~GSError();

	GameState* Run();
};

#endif
