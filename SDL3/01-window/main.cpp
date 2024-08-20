#include <iostream>
#include <SDL3/SDL.h>

int main(int argc, char *argv[]){
	
	bool isRunning = true;
	if(SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) != 0){
		SDL_Log("Error %s",SDL_GetError());
		return EXIT_FAILURE;
	}

	SDL_Window *window = SDL_CreateWindow("SDL3", 640, 480, SDL_WINDOW_MAXIMIZED | SDL_WINDOW_RESIZABLE);

	while(isRunning){
		SDL_Event event;
		while(SDL_PollEvent(&event)){
			if(event.type == SDL_EVENT_QUIT){
				isRunning = false;
			}
		}
	}

	SDL_DestroyWindow(window);
	SDL_Quit();


	return 0;
}
