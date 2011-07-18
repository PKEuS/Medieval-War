#include "GSIntro.hpp"
#include "GSMenu.hpp"
#include "GSError.hpp"

GSIntro::GSIntro(sf::RenderWindow& window) :
GameState(window)
{
}

GSIntro::~GSIntro()
{
}

GameState* GSIntro::Run()
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
		myWindow.Draw(sf::Text("Intro", sf::Font::GetDefaultFont(), 46));
		myWindow.Display();
	}
}
