#include "GSIntro.hpp"
#include "GSMenu.hpp"
#include "GSSingleplayerGame.hpp"
#include "GSMultiplayerGame.hpp"
#include "GSMapEditor.hpp"
#include "GSSettings.hpp"
#include "GSCredits.hpp"
#include "GSError.hpp"

GSMenu::GSMenu(sf::RenderWindow& window) :
GameState(window)
{
}

GSMenu::~GSMenu()
{
}

GameState* GSMenu::Run()
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
		myWindow.Draw(sf::Text("Menu", sf::Font::GetDefaultFont(), 46));
		myWindow.Display();
	}
}
