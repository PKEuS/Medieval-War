#include "GameEngine.hpp"

int main(int argc, char* argv[])
{
	GameEngine* game = new GameEngine(argc, argv);
	int returnValue = game->Run();
	delete game;

	return returnValue;
}
