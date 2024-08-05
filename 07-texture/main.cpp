#include <iostream>
#include <SDL2/SDL.h>


int main(int argc, char **argv){
	
	bool isRunning = true;

	if(SDL_Init(SDL_INIT_VIDEO) < 0){
		std::cout<< "failure with video driver" <<SDL_GetError() <<std::endl;
	}
	else{
		std::cout << "working" <<std::endl;
	}

	SDL_Window *window = nullptr;

	SDL_Rect rectangle;
	
	rectangle.x = 20;
	rectangle.y = 40;
	rectangle.w = 300;
	rectangle.h = 200;


	window = SDL_CreateWindow("texture",
				0,
				0,
				640,
				480,
				SDL_WINDOW_SHOWN);

	SDL_Renderer *renderer = nullptr;
	
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	
	SDL_Surface *surface = SDL_LoadBMP("./images/mouse.bmp");

	SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, surface);

	if(!texture){
		std::cout<< "texture not working\n";
		SDL_DestroyRenderer(renderer);
		SDL_DestroyWindow(window);
		SDL_Quit();
		return -1;
	}

	SDL_FreeSurface(surface);

	while(isRunning){
		SDL_Event event;
		while(SDL_PollEvent(&event)){
			if(event.type == SDL_QUIT){
				isRunning = false;
			}		
		}
		
		SDL_SetRenderDrawColor(renderer,0,0,0, SDL_ALPHA_OPAQUE);
		SDL_RenderClear(renderer);

		SDL_SetRenderDrawColor(renderer, 255,255,255, SDL_ALPHA_OPAQUE);
	//	SDL_RenderDrawRect(renderer, &rectangle);
		SDL_RenderCopy(renderer, texture, NULL, &rectangle);
		SDL_RenderPresent(renderer);
		

	}

	SDL_DestroyTexture(texture);

	SDL_DestroyRenderer(renderer);

	SDL_DestroyWindow(window);
	SDL_Quit();


	return 0;
}
