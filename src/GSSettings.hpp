#ifndef GSSETTINGS_HPP
#define GSSETTINGS_HPP

#include <SFML/Graphics.hpp>
#include "GameState.hpp"


class GSSettings : public GameState
{
public:
	GSSettings(sf::RenderWindow& window);
	~GSSettings();

	GameState* Run();
};

#endif
