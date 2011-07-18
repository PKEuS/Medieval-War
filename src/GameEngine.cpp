#include <boost/scoped_ptr.hpp>

#include "GameState.hpp"

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
	boost::scoped_ptr<GameState> state(new GSIntro(myWindow));
	
	while(state)
	{
		state.reset(state->Run());
	}
	
	return GameState::GetReturnValue();
}

