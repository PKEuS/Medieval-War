#include "Settings.hpp"
#include "GameEngine.hpp"

int main(int argc, char* argv[])
{
	Settings settings(argc, argv);
	settings.LoadConfigFile();
	
	switch(settings.ParseArguments())
	{
		case 1:
			return EXIT_SUCCESS;
		case -1:
			return EXIT_FAILURE;
	}
	
	GameEngine* game = new GameEngine(settings);
	int returnValue = game->Run();
	delete game;

	return returnValue;
}

