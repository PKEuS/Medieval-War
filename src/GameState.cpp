#include "GameState.hpp"

GameState::GameState(sf::RenderWindow& window) :
myWindow(window)
{
}

GameState::~GameState()
{
}

int GameState::GetReturnValue()
{
	return myReturnValue;
}

int GameState::SetReturnValue(int returnValue)
{
	myReturnValue = returnValue;
}

int GameState::myReturnValue = EXIT_SUCCESS;