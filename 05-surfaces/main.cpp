#include <iostream>
#include <SDL2/SDL.h>

void SetWindowPixel(SDL_Surface *screen, int x, int y, uint8_t r, uint8_t g, uint8_t b){
	SDL_LockSurface(screen);
	std::cout << x << "," << y <<std::endl;
	uint8_t *pixelArray = (uint8_t*) screen->pixels;
	//pixelArray[y* screen->format->BytesPerPixel +x] = r;
	
	pixelArray[y* screen->pitch +x* screen->format->BytesPerPixel +0] = b;
	pixelArray[y* screen->pitch +x* screen->format->BytesPerPixel +1] = g;
	pixelArray[y* screen->pitch +x* screen->format->BytesPerPixel +2] = r;

	//SDL_memset(screen->pixels, 255, screen->h * screen->pitch);
	SDL_UnlockSurface(screen);
	

}


int main(int argc, char** argv){
	
	bool isRunning = true;
	SDL_Window *window = nullptr;

	SDL_Surface *screen = nullptr;
	
	if(SDL_Init(SDL_INIT_VIDEO) < 0){
		std::cout << "problem with initialization" << SDL_GetError() << std::endl;
	}

	else{
		std::cout << "working" << std::endl;
	}

	window = SDL_CreateWindow("Surfaces",
				0,
				0,
				640,
				480,
				SDL_WINDOW_SHOWN);

	screen = SDL_GetWindowSurface(window);
	//SDL_Surface *image = nullptr;
	//image = SDL_LoadBMP("./images/mouse.bmp");
	//SDL_BlitSurface(image, NULL, screen, NULL);
	//SDL_UpdateWindowSurface(window);
	//SDL_FreeSurface(image);

	while(isRunning){
		SDL_Event event;

		int x,y;
		Uint32 buttons;
		buttons = SDL_GetMouseState(&x, &y);
		while(SDL_PollEvent(&event)){
			if(event.type == SDL_QUIT){
				isRunning = false;
			}

			if(event.button.button == SDL_BUTTON_LEFT){
				SetWindowPixel(screen, x, y, 255, 0, 0);	
			}
			if(event.button.button == SDL_BUTTON_RIGHT){
			
				SetWindowPixel(screen, x, y, 0, 255, 0);
			}

			
		} 

		SDL_UpdateWindowSurface(window);
	}

	SDL_DestroyWindow(window);
	SDL_Quit();

	return 0;
}
