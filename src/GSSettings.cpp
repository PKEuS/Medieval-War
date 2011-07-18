#include "GSMenu.hpp"
#include "GSSettings.hpp"
#include "GSError.hpp"

GSSettings::GSSettings(sf::RenderWindow& window) :
GameState(window)
{
}

GSSettings::~GSSettings()
{
}

GameState* GSSettings::Run()
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
		myWindow.Draw(sf::Text("Settings", sf::Font::GetDefaultFont(), 46));
		myWindow.Display();
	}
}
