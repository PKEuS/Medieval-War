#include "GSCredits.hpp"

GSCredits::GSCredits(sf::RenderWindow& window) :
GameState(window)
{
}

GSCredits::~GSCredits()
{
}

GameStates GSCredits::Run()
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
				return EXIT;
			}
		}
	
		myWindow.Clear();
		myWindow.Draw(sf::Text("Credits", sf::Font::GetDefaultFont(), 46));
		myWindow.Display();
	}
}
