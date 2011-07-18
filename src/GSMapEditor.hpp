#ifndef GSMAPEDITOR_HPP
#define GSMAPEDITOR_HPP

#include <SFML/Graphics.hpp>
#include "GameState.hpp"


class GSMapEditor : public GameState
{
public:
	GSMapEditor(sf::RenderWindow& window);
	~GSMapEditor();

	GameState* Run();
};

#endif
