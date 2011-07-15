#include "GSError.hpp"

GSError::GSError(sf::RenderWindow& window) :
GameState(window)
{
}

GSError::~GSError()
{
}

GameStates GSError::Run()
{
	while(true)
	{
		sf::Event event;
		while(myWindow.PollEvent(event))
		{
			if((event.Type == sf::Event::Closed) || ((event.Type == sf::Event::KeyPressed) && (event.Key.Code == sf::Keyboard::Escape)))
			{
				return EXITFAILURE;
			}
			else if(event.Key.Code == sf::Keyboard::Return)
			{
				return EXITFAILURE;
			}
		}
	
		myWindow.Clear();
		myWindow.Draw(sf::Text("Error", sf::Font::GetDefaultFont(), 46));
		myWindow.Display();
	}
}
