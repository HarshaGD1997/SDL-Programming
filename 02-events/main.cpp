#include <iostream>
#include <SDL2/SDL.h>

int main(int argc, char** argv){

	bool gameIsRunning = true;

	SDL_Window *window = nullptr;

	if(SDL_Init(SDL_INIT_VIDEO) < 0){
		std::cout << "error" << SDL_GetError();
	}

	else{
		std::cout << "working" <<std::endl;
	}

	window = SDL_CreateWindow("events",
			0,
			0,
			640,
			480,
			SDL_WINDOW_SHOWN);

	//create infinite loop
	
	while(gameIsRunning){
		SDL_Event event;
		// starting event loop

		while(SDL_PollEvent(&event)){
			//handle events
			if(event.type == SDL_QUIT){
				gameIsRunning = false;
			}

		}

	}

	SDL_DestroyWindow(window);

	SDL_Quit();

	return 0;
}
