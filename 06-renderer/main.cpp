#include <iostream>
#include <SDL2/SDL.h>


int main(int argc, char **argv){

	bool isRunning = true;
	
	if(SDL_Init(SDL_INIT_VIDEO) < 0){
		std::cout << "display problem" << SDL_GetError() <<std::endl;
	
	}
	else{
		std::cout << "display working fine" << std::endl;
	}

	SDL_Window *window = nullptr;

	window = SDL_CreateWindow("renderer",
				0,
				0,
				640,
				480,
				SDL_WINDOW_SHOWN);

	SDL_Renderer *renderer = nullptr;
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);


	SDL_Rect rectangle;
	rectangle.x = 20;
	rectangle.y = 40;
	rectangle.w = 30;
	rectangle.h = 32;

	
	while(isRunning){
		SDL_Event event;
		while(SDL_PollEvent(&event)){
			if(event.type == SDL_QUIT){
				isRunning = false;
			}
		}
		SDL_SetRenderDrawColor(renderer,0,0,0,SDL_ALPHA_OPAQUE);
		SDL_RenderClear(renderer);

		SDL_SetRenderDrawColor(renderer, 255,255,255, SDL_ALPHA_OPAQUE);
		SDL_RenderDrawLine(renderer, 5,5,100,120);

		SDL_RenderDrawRect(renderer, &rectangle);

	
		SDL_RenderPresent(renderer);

	}




	
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();


	return 0;
}
