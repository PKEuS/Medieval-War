#include "GSMenu.hpp"
#include "GSMultiplayerGame.hpp"
#include "GSError.hpp"

GSMultiplayerGame::GSMultiplayerGame(sf::RenderWindow& window) :
GameState(window)
{
}

GSMultiplayerGame::~GSMultiplayerGame()
{
}

GameState* GSMultiplayerGame::Run()
{
	while(true)
	{
		sf::Event event;
		while(myWindow.PollEvent(event))
		{
			if((event.Type == sf::Event::Closed) || ((event.Type == sf::Event::KeyPressed) && (event.Key.Code == sf::Keyboard::Escape)))
			{
				return NULL;
			}
		}
	
		myWindow.Clear();
		myWindow.Draw(sf::Text("MultiplayerGame", sf::Font::GetDefaultFont(), 46));
		myWindow.Display();
	}
}
