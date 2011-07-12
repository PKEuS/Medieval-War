#include "GSMenu.hpp"

GSMenu::GSMenu(sf::RenderWindow& window) :
GameState(window)
{
}

GSMenu::~GSMenu()
{
}

GameStates GSMenu::Run()
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
				return SINGLEPLAYERGAME;
			}
		}
	
		myWindow.Clear();
		myWindow.Draw(sf::Text("Menu", sf::Font::GetDefaultFont(), 46));
		myWindow.Display();
	}
}
