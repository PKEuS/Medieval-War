#include "GSMapEditor.hpp"

GSMapEditor::GSMapEditor(sf::RenderWindow& window) :
GameState(window)
{
}

GSMapEditor::~GSMapEditor()
{
}

GameStates GSMapEditor::Run()
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
				return SETTINGS;
			}
		}
	
		myWindow.Clear();
		myWindow.Draw(sf::Text("MapEditor", sf::Font::GetDefaultFont(), 46));
		myWindow.Display();
	}
}
