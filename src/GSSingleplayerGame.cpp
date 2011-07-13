#include "GSSingleplayerGame.hpp"

GSSingleplayerGame::GSSingleplayerGame(sf::RenderWindow& window) :
GameState(window)
{
}

GSSingleplayerGame::~GSSingleplayerGame()
{
}

GameStates GSSingleplayerGame::Run()
{
	while(true)
	{
		sf::Event event;
		while(myWindow.PollEvent(event))
		{
			if((event.Type == sf::Event::Closed) || ((event.Type == sf::Event::KeyPressed) && (event.Key.Code == sf::Keyboard::Escape)))
			{
				return EXIT;
			}
			else if(event.Key.Code == sf::Keyboard::Return)
			{
				return MULTIPLAYERGAME;
			}
		}
	
		myWindow.Clear();
		myWindow.Draw(sf::Text("SingleplayerGame", sf::Font::GetDefaultFont(), 46));
		myWindow.Display();
	}
}
