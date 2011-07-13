#include "GSIntro.hpp"
#include "GSMenu.hpp"
#include "GSSingleplayerGame.hpp"
#include "GSMultiplayerGame.hpp"
#include "GSMapEditor.hpp"
#include "GSSettings.hpp"
#include "GSCredits.hpp"
#include "GameEngine.hpp"

GameEngine::GameEngine(int argc, char* argv[])
{
	myWindow.Create(sf::VideoMode(800, 600), "Medieval War", sf::Style::Close);
	myWindow.EnableVerticalSync(true);
}

GameEngine::~GameEngine()
{
}

void GameEngine::Run()
{
	while(myWindow.IsOpened())
	{
		switch(myCurrentGameState)
		{
		case INTRO:
			{
				GameState* state = new GSIntro(myWindow);
				myCurrentGameState = state->Run();
				delete state;
			}
			break;
		case MENU:
			{
				GameState* state = new GSMenu(myWindow);
				myCurrentGameState = state->Run();
				delete state;
			}
			break;
		case SINGLEPLAYERGAME:
			{
				GameState* state = new GSSingleplayerGame(myWindow);
				myCurrentGameState = state->Run();
				delete state;
			}
			break;
		case MULTIPLAYERGAME:
			{
				GameState* state = new GSMultiplayerGame(myWindow);
				myCurrentGameState = state->Run();
				delete state;
			}
			break;
		case MAPEDITOR:
			{
				GameState* state = new GSMapEditor(myWindow);
				myCurrentGameState = state->Run();
				delete state;
			}
			break;
		case SETTINGS:
			{
				GameState* state = new GSSettings(myWindow);
				myCurrentGameState = state->Run();
				delete state;
			}
			break;
		case CREDITS:
			{
				GameState* state = new GSCredits(myWindow);
				myCurrentGameState = state->Run();
				delete state;
			}
			break;
		case EXIT:
			{
				myWindow.Close();
			}
			break;
		default:
			{
				myCurrentGameState = INTRO;
			}
			break;
		}
	}
}
