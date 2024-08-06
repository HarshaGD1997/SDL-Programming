#include <iostream>
#include <SDL2/SDL.h>

int main(int argc, char **argv){

	SDL_Window *window = nullptr;
	bool isRunning = true;

	if(SDL_Init(SDL_INIT_VIDEO) < 0){
		std::cout << "Error " << SDL_GetError() <<std::endl;
		return -1;
	}
	else{
		std::cout << "Working fine" << std::endl;
	}

	SDL_Rect rectangle;
	rectangle.x = 10;
	rectangle.y = 20;
	rectangle.w = 200;
	rectangle.h = 200;

	SDL_Rect second_rectangle;
	second_rectangle.x = 30;
	second_rectangle.y = 40;
	second_rectangle.w = 200;
	second_rectangle.h = 200;

	window = SDL_CreateWindow("Blending",
				0,
				0,
				640,
				480,
				SDL_WINDOW_SHOWN);

	SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	SDL_Surface *surface = SDL_LoadBMP("./images/crow.bmp");
	SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, surface);	
	SDL_FreeSurface(surface);
	if(!renderer){
		std::cout << "problem\n";
		SDL_DestroyWindow(window);
		SDL_Quit();
		return -1;
	}


	while(isRunning){
		SDL_Event event;
		while(SDL_PollEvent(&event)){
			if(event.type == SDL_QUIT){
				isRunning = false;
			}

			if(event.type == SDL_MOUSEMOTION){
				rectangle.x = event.motion.x;
				rectangle.y = event.motion.y;
			}
			if(event.type == SDL_MOUSEBUTTONDOWN){
				if(event.button.button == SDL_BUTTON_LEFT){
					SDL_SetTextureBlendMode(texture, SDL_BLENDMODE_ADD); 
				}
				else if(event.button.button == SDL_BUTTON_MIDDLE){
					SDL_SetTextureBlendMode(texture, SDL_BLENDMODE_BLEND);
				}
				else if(event.button.button == SDL_BUTTON_RIGHT){
					SDL_SetTextureBlendMode(texture, SDL_BLENDMODE_MOD);
				}
				
			}
			else{
				SDL_SetTextureBlendMode(texture, SDL_BLENDMODE_NONE);
			}
		}

		

		SDL_SetRenderDrawColor(renderer, 0xff, 0, 0 ,SDL_ALPHA_OPAQUE);
		SDL_RenderClear(renderer);

		SDL_SetRenderDrawColor(renderer, 0xff, 0xff, 0xff, SDL_ALPHA_OPAQUE);
		SDL_RenderDrawLine(renderer, 20,20,80,80);
		SDL_RenderCopy(renderer, texture, NULL, &rectangle);
		SDL_RenderCopy(renderer, texture, NULL, &second_rectangle);
		SDL_RenderPresent(renderer);
	

	}
	SDL_DestroyTexture(texture);
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);

	SDL_Quit();
	return 0;
}
