#include <iostream>

#include <SDL2/SDL.h>


int main(int argc, char* argv[]){

	SDL_Window *window = nullptr;

	if(SDL_Init(SDL_INIT_VIDEO) < 0){
		std::cout << "error " << SDL_GetError();
	}
	else{
		std::cout << "working" << std::endl;
	}


	window = SDL_CreateWindow("c++ sdl2 window",  //title
			10, //x value
			30, //y value
			640, //height
			480, //width 
			SDL_WINDOW_SHOWN); //flags

	SDL_Delay(3000); //creating delay
	
	SDL_DestroyWindow(window);
	SDL_Quit();

	return 0;
}
