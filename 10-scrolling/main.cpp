#include <iostream>
#include <SDL2/SDL.h>
#define WIN_WIDTH 1200
#define WIN_HEIGHT 600

int main(int argc, char **argv){

	bool isRunning = true;

	if(SDL_Init(SDL_INIT_VIDEO) < 0){
		std::cout << "Error " << SDL_GetError() << std::endl;
		return -1;
	}
	else{
		std::cout << "Working " << std::endl;
	}

	SDL_Window *window = SDL_CreateWindow("scrolling",
					0,
					0,
					WIN_WIDTH,
					WIN_HEIGHT,
					SDL_WINDOW_SHOWN);

	SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	SDL_Surface *surface = SDL_LoadBMP("./images/water2.bmp");
	SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, surface);
	SDL_Texture *second_texture = SDL_CreateTextureFromSurface(renderer, surface);
	SDL_FreeSurface(surface);

	SDL_Rect rectangle;
	rectangle.x = 0;
	rectangle.y = 0;
	rectangle.w = WIN_WIDTH;
	rectangle.h = WIN_HEIGHT;

	SDL_Rect second_rectangle;
	second_rectangle.x = -1199;
	second_rectangle.y = 0;
	second_rectangle.w = WIN_WIDTH;
	second_rectangle.h = WIN_HEIGHT;

	SDL_Rect third_rectangle;
	third_rectangle.x = 0;
	third_rectangle.y = 0;
	third_rectangle.w = WIN_WIDTH;
	third_rectangle.h = WIN_HEIGHT;

	SDL_Rect fourth_rectangle;
	fourth_rectangle.x = 0;
	fourth_rectangle.y = -599;
	fourth_rectangle.w = WIN_WIDTH;
	fourth_rectangle.h = WIN_HEIGHT;


	while(isRunning){
		SDL_Event event;
		while(SDL_PollEvent(&event)){
			if(event.type == SDL_QUIT){
				isRunning = false;
			}
			if(event.type == SDL_MOUSEBUTTONDOWN){
				if(event.button.button == SDL_BUTTON_LEFT){
					SDL_SetTextureBlendMode(second_texture, SDL_BLENDMODE_ADD); 
				}
				else if(event.button.button == SDL_BUTTON_MIDDLE){
					SDL_SetTextureBlendMode(second_texture, SDL_BLENDMODE_BLEND);
				}
				else if(event.button.button == SDL_BUTTON_RIGHT){
					SDL_SetTextureBlendMode(second_texture, SDL_BLENDMODE_MOD);
				}
			}
		}
		
		SDL_SetRenderDrawColor(renderer, 0, 0, 0xff, SDL_ALPHA_OPAQUE);
		SDL_RenderClear(renderer);

		int w, h;
		SDL_QueryTexture(texture, NULL, NULL, &w, &h);
		SDL_Delay(100);
		//SDL_RenderCopy(renderer, texture, NULL, &rectangle);

		rectangle.x++;
		if(rectangle.x > 1199){
			rectangle.x = -1199;
		} 
		
		second_rectangle.x++;
		if(second_rectangle.x > 1199){
			second_rectangle.x = -1199;
		}

		third_rectangle.y++;
		if(third_rectangle.y > 599){
			third_rectangle.y = -599;
		}

		fourth_rectangle.y++;
		if(fourth_rectangle.y > 599){
			fourth_rectangle.y = -599;
		}
			
		//left-right 

		SDL_SetTextureBlendMode(texture, SDL_BLENDMODE_NONE);
		SDL_RenderCopy(renderer, texture, NULL, &rectangle);
		SDL_RenderCopy(renderer, texture, NULL, &second_rectangle);

		//top-bottom
		SDL_RenderCopy(renderer, second_texture, NULL, &third_rectangle);
		SDL_RenderCopy(renderer, second_texture, NULL, &fourth_rectangle);

		SDL_RenderPresent(renderer);


	}

	SDL_DestroyRenderer(renderer);
	SDL_DestroyTexture(second_texture);
	SDL_DestroyTexture(texture);
	SDL_DestroyWindow(window);
	SDL_Quit();

	return 0;
}
