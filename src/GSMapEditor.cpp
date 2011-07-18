#include "GSMenu.hpp"
#include "GSMapEditor.hpp"
#include "GSError.hpp"

GSMapEditor::GSMapEditor(sf::RenderWindow& window) :
GameState(window)
{
}

GSMapEditor::~GSMapEditor()
{
}

GameState* GSMapEditor::Run()
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
		myWindow.Draw(sf::Text("MapEditor", sf::Font::GetDefaultFont(), 46));
		myWindow.Display();
	}
}
