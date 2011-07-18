#include "GSMenu.hpp"
#include "GSSingleplayerGame.hpp"
#include "GSError.hpp"

GSSingleplayerGame::GSSingleplayerGame(sf::RenderWindow& window) :
GameState(window)
{
}

GSSingleplayerGame::~GSSingleplayerGame()
{
}

GameState* GSSingleplayerGame::Run()
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
		myWindow.Draw(sf::Text("SingleplayerGame", sf::Font::GetDefaultFont(), 46));
		myWindow.Display();
	}
}
