#include "GSError.hpp"

GSError::GSError(sf::RenderWindow& window) :
GameState(window)
{
	SetReturnValue(EXIT_FAILURE);
}

GSError::~GSError()
{
}

GameState* GSError::Run()
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
		myWindow.Draw(sf::Text("Error", sf::Font::GetDefaultFont(), 46));
		myWindow.Display();
	}
}
