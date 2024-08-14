/*
 * g++ -std=c++17 main.cpp -o prog -ldl -lSDL2 -lSDL2_ttf
 *
*/

#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

int main(int argc, char** argv){

	if(SDL_Init(SDL_INIT_VIDEO) < 0){
		std::cout << "Error with the video card" << SDL_GetError() << std::endl;
		return -1;
	}
	else{
		std::cout << "Working" << std::endl;
	}

	SDL_Window *window = SDL_CreateWindow("fonts", 0, 0, 640, 480, SDL_WINDOW_SHOWN);
	SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

	if(TTF_Init() == -1){
		std::cout << "Failure with ttf " << TTF_GetError() << std::endl;
		
	}
	else{
	
		std::cout << "TTF is working" << std::endl;
	}

	TTF_Font *myFont = TTF_OpenFont("./ttf-font/SonOfTmU.ttf",42);
	
	if(myFont == nullptr){
		std::cout << "problem loading ttf" << std::endl;
		exit(1);
	}

	SDL_Surface *surfaceText = TTF_RenderText_Solid(myFont, "Harsha G D", {255,255,255});

	SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, surfaceText);

	SDL_FreeSurface(surfaceText);


	bool isRunning = true;

	SDL_Rect rect;
	rect.x = 30;
	rect.y = 30;
	rect.w = 400;
	rect.h = 200;

	while(isRunning){
		SDL_Event event;
		while(SDL_PollEvent(&event)){
			if(event.type == SDL_QUIT){
				isRunning = false;
			}


		}


		SDL_SetRenderDrawColor(renderer, 0x1f, 0x09, 0xff, SDL_ALPHA_OPAQUE);
		SDL_RenderClear(renderer);
		
		//SDL_SetRenderDrawColor(renderer, 255, 255, 0, SDL_ALPHA_OPAQUE);
		SDL_RenderCopy(renderer, texture, NULL, &rect);
		SDL_RenderPresent(renderer);
		
	}


	SDL_DestroyTexture(texture);
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	TTF_CloseFont(myFont);
	SDL_Quit();
	return 0;
}
