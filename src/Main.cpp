#include "GameEngine.hpp"

int main(int argc, char* argv[])
{
	GameEngine* game = new GameEngine(argc, argv);
	game->Run();
	delete game;

	return 0;
}
