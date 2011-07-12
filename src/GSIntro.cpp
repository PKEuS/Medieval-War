#include "GSIntro.hpp"

GSIntro::GSIntro(sf::RenderWindow& window) :
GameState(window)
{
}

GSIntro::~GSIntro()
{
}

GameStates GSIntro::Run()
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
				return MENU;
			}
		}
	
		myWindow.Clear();
		myWindow.Draw(sf::Text("Intro", sf::Font::GetDefaultFont(), 46));
		myWindow.Display();
	}
}
