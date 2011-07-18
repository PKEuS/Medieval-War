#include "GSMenu.hpp"
#include "GSCredits.hpp"
#include "GSError.hpp"

GSCredits::GSCredits(sf::RenderWindow& window) :
GameState(window)
{
}

GSCredits::~GSCredits()
{
}

GameState* GSCredits::Run()
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
		myWindow.Draw(sf::Text("Credits", sf::Font::GetDefaultFont(), 46));
		myWindow.Display();
	}
}
