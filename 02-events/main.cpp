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
			/*if(event.type == SDL_MOUSEMOTION){
				std::cout << "mouse motion" << std::endl;
			}*/
			if(event.type == SDL_KEYDOWN){
			
				/* 
				 * SDL key sym mapping 
				 * https://documentation.help/SDL/sdlkey.html
				 */ 

				if(event.key.keysym.sym == SDLK_a){
					std::cout << "a" << std::endl;
				}
				//std::cout << "key" << std::endl;
			}

			const Uint8 *state = SDL_GetKeyboardState(NULL);
			if(state[SDL_SCANCODE_LEFT]){
				std::cout << "left key was pressed " <<std::endl;
			}

		}

	}

	SDL_DestroyWindow(window);

	SDL_Quit();

	return 0;
}
