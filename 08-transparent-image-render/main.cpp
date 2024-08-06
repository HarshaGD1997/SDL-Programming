//Better way to find the path of SDL installation : g++ -H -fsyntax-only -std=c++17 main.cpp >& file.txt

#include <iostream>
#include <SDL2/SDL.h>


int main(int argc, char **argv){
	
	bool isRunning = true;

	if(SDL_Init(SDL_INIT_VIDEO) < 0){
		std::cout << "error with sdl video init\t" << SDL_GetError();

	}
	else{
		std::cout << "working\n";
	}

	SDL_Window *window = nullptr;

	window = SDL_CreateWindow("transparent",
				0,
				0,
				640,
				480,
				SDL_WINDOW_SHOWN);

	SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	if(!renderer){
		std::cout << "renderer error\n";
		SDL_DestroyWindow(window);
		SDL_Quit();
		return -1;
	}

	SDL_Surface *surface = SDL_LoadBMP("./images/crow-transparent.bmp");

	//SDL_SetColorKey(surface, SDL_TRUE, SDL_MapRGB(surface->format, 0xff,0xff,0xff));

	SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, surface);
	SDL_FreeSurface(surface);

	SDL_Rect rectangle;
	rectangle.x = 20;
	rectangle.y = 10;
	rectangle.w = 200;
	rectangle.h = 200;
	
	while(isRunning){
		SDL_Event event;
		while(SDL_PollEvent(&event)){
			if(event.type == SDL_QUIT){
				isRunning = false;
			}
		}
		SDL_SetRenderDrawColor(renderer, 0,0,0, SDL_ALPHA_OPAQUE);
		SDL_RenderClear(renderer);

		SDL_SetRenderDrawColor(renderer, 255,255,255, SDL_ALPHA_OPAQUE);
		//SDL_RenderDrawRect(renderer, &rectangle);
		SDL_RenderCopy(renderer, texture, NULL, &rectangle);
		SDL_RenderPresent(renderer);
	}



	
	SDL_DestroyRenderer(renderer);

	SDL_DestroyWindow(window);
	SDL_Quit();


	return 0;
}
