#include "GSMultiplayerGame.hpp"

GSMultiplayerGame::GSMultiplayerGame(sf::RenderWindow& window) :
GameState(window)
{
}

GSMultiplayerGame::~GSMultiplayerGame()
{
}

GameStates GSMultiplayerGame::Run()
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
				return MAPEDITOR;
			}
		}
	
		myWindow.Clear();
		myWindow.Draw(sf::Text("MultiplayerGame", sf::Font::GetDefaultFont(), 46));
		myWindow.Display();
	}
}
