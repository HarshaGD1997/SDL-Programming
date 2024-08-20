/*
 *	Compilation :
 *		g++ ./src/main.cpp -I./include -o ./bin/prog `pkg-config --libs sdl3`
 *
 *
*/
#include "Application.hpp"


int main(int argc, char **argv){
	Application app(argc, argv);
	app.Loop();
	return 0;
}
