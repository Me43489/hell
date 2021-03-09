/*****************************
						Main
******************************/
#include "include.hpp"
#include "game.hpp"
#include "textureconst.hpp"
#include "debug.h"

int main(int argc, char** argv) {

#ifdef DEBUG
	char buffer[FILENAME_MAX];
	_getcwd(buffer, FILENAME_MAX);
	std::cout << "working dir : " << buffer << std::endl;
	printf("C++ Version: %ld", __cplusplus);
#endif // JJJ_DEBUG



	Game app = Game("Hell Project", 1280, 1024);
	app.run();
	app.quit();

	return 0;
}