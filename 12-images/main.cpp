/*
 *	g++ main.cpp -o prog -std=c++17 -ldl -lSDL2 -lSDL2_image
 *
*/

#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

int main(int argc, char **argv){
	
	if(SDL_Init(SDL_INIT_VIDEO) < 0){
		std :: cout << "Error " << SDL_GetError() << std :: endl;
		return -1;
	}
	else{
		std :: cout << "Video init" << std :: endl;
	}

	SDL_Window *window = SDL_CreateWindow("image", 0, 0, 640, 480, SDL_WINDOW_SHOWN);

	SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	
	bool isRunning = true;

	int flags = IMG_INIT_PNG;
	int initStatus = IMG_Init(flags);

	SDL_Surface *image = nullptr;
	image = IMG_Load("./images/rodent.png");
	
	if(!image){
		std :: cout << "image could not be loaded" << std::endl;
	}

	SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, image);

	SDL_FreeSurface(image);
	
	
	/*
	 * std :: cout << "flags value " << flags << std :: endl;
	 * std :: cout << "init status " << initStatus << std :: endl;
	 * std :: cout << "init and status " << (initStatus & flags) << std :: endl;
	 *
	*/
	if((initStatus & flags) != flags){
		std :: cout << "SDL Image fornat not available" << std :: endl;

	
	}

	while(isRunning){
		SDL_Event event;
		while(SDL_PollEvent(&event)){
			if(event.type == SDL_QUIT){
				isRunning = false;
			}
		
		}

		SDL_SetRenderDrawColor(renderer, 0, 0, 0xff, SDL_ALPHA_OPAQUE);
		SDL_RenderClear(renderer);
		SDL_RenderCopy(renderer, texture, NULL, NULL);
		SDL_RenderPresent(renderer);
	
	}

	SDL_DestroyTexture(texture);
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	IMG_Quit();
	SDL_Quit();

	return 0;
}
