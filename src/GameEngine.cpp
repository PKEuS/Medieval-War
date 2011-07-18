#include "GSIntro.hpp"
#include "GSMenu.hpp"
#include "GSSingleplayerGame.hpp"
#include "GSMultiplayerGame.hpp"
#include "GSMapEditor.hpp"
#include "GSSettings.hpp"
#include "GSCredits.hpp"
#include "GSError.hpp"
#include "GameEngine.hpp"

GameEngine::GameEngine(Settings& settings) :
mySettings(settings)
{
	myWindow.Create(mySettings.GetVideoMode(), "Medieval War", mySettings.GetWindowStyle());
	myWindow.EnableVerticalSync(true);
}

GameEngine::~GameEngine()
{
	myWindow.Close();
}

int GameEngine::Run()
{
	while(true)
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
			case ERROR:
			{
				GameState* state = new GSError(myWindow);
				myCurrentGameState = state->Run();
				delete state;
			}
			break;
			case EXITSUCCESS:
			{
				return EXIT_SUCCESS;
			}
			break;
			case EXITFAILURE:
			{
				return EXIT_FAILURE;
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

