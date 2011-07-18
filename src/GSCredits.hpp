#ifndef GSCREDITS_HPP
#define GSCREDITS_HPP

#include <SFML/Graphics.hpp>
#include "GameState.hpp"


class GSCredits : public GameState
{
public:
	GSCredits(sf::RenderWindow& window);
	~GSCredits();

	GameState* Run();
};

#endif
