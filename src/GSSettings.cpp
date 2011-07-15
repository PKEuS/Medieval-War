#include "GSSettings.hpp"

GSSettings::GSSettings(sf::RenderWindow& window) :
GameState(window)
{
}

GSSettings::~GSSettings()
{
}

GameStates GSSettings::Run()
{
	while(true)
	{
		sf::Event event;
		while(myWindow.PollEvent(event))
		{
			if((event.Type == sf::Event::Closed) || ((event.Type == sf::Event::KeyPressed) && (event.Key.Code == sf::Keyboard::Escape)))
			{
				return EXITSUCCESS;
			}
			else if(event.Key.Code == sf::Keyboard::Return)
			{
				return CREDITS;
			}
		}
	
		myWindow.Clear();
		myWindow.Draw(sf::Text("Settings", sf::Font::GetDefaultFont(), 46));
		myWindow.Display();
	}
}
