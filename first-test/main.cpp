#include <iostream>

#include <SDL2/SDL.h>


int main(int argc, char** argv){
	
	if(SDL_Init(SDL_INIT_VIDEO) < 0){
		std::cout << "SDL could not be initialized " << SDL_GetError();
	}
	else{
		std::cout << "SDL Video system is ready" << std::endl;
	}

	return 0;
}
