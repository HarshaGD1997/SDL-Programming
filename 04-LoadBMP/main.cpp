/*
 * Making use of ImageMagick tool to convert image into bmp
 * mogrify -format bmp image.jpeg
 *
 */


#include <iostream>
#include <SDL2/SDL.h>

int main(int argc, char **argv){

	bool isRunning = true;

	SDL_Window *window = nullptr;
	
	// Get the surface 
	SDL_Surface *screen;

	if(SDL_Init(SDL_INIT_VIDEO) < 0){
		std::cout << "error " << SDL_GetError() <<std::endl;
	}
	else{
		std::cout << "working" << std::endl;
	}

	window = SDL_CreateWindow("Load BMP Image",
				0,
				0,
				640,
				480,
				SDL_WINDOW_SHOWN);

	// Getting the pointer to the window
	screen = SDL_GetWindowSurface(window);

	SDL_Surface *image;
	image = SDL_LoadBMP("./images/mouse.bmp");
	SDL_BlitSurface(image, NULL, screen, NULL);
	SDL_FreeSurface(image);
	SDL_UpdateWindowSurface(window);

	while (isRunning){
		SDL_Event event;
		while(SDL_PollEvent(&event)){
			if(event.type == SDL_QUIT){
				isRunning = false;
			}
			
		}

	}

	SDL_DestroyWindow(window);
	SDL_Quit();

	return 0;
}
