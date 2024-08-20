#pragma once
#include <SDL3/SDL.h>

struct Application{
	
	Application(int argc, char **argv){
		Startup();
	}

	~Application(){
		Shutdown();
	}

	void Shutdown(){
		SDL_DestroySurface(mWindowSurface);
		SDL_DestroySurface(mSurface);
		SDL_DestroyWindow(mWindow);
		SDL_Quit();
	}

	void Startup(){
		if(SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) != 0){
			SDL_Log("Error : %s",SDL_GetError());
		}
		else{
			SDL_Log("SDL Video and Audio subsystems initialized");
		}
		mWindow = SDL_CreateWindow("SDL Surface", 640, 480, SDL_EVENT_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE | SDL_WINDOW_MAXIMIZED);
		mSurface = SDL_LoadBMP("./images/menu.bmp");
		mWindowSurface = SDL_GetWindowSurface(mWindow);

		if(mSurface == NULL){
			SDL_Log("Error loading image");
		}

		//Blit window surface (copy)
		SDL_BlitSurface(mSurface, NULL, mWindowSurface, NULL);
		SDL_UpdateWindowSurface(mWindow);

	}

	void Input(){
		SDL_Event event;
		while(SDL_PollEvent(&event)){
			if(event.type == SDL_EVENT_QUIT){
				SDL_Log("Application alive for %li", event.quit.timestamp);
				mIsRunning = false;
			}

			else if(event.type == SDL_EVENT_KEY_DOWN){
				if(event.key.key == SDLK_0){
					SDL_Log("0 was pressed");
				}
			}
		}
	}

	void Update(){
	
	}

	void Render(){
	
	}

	void Loop(){
		while(mIsRunning){
			Input();
			Update();
			Render();
		}
	}

	private:
		bool mIsRunning{true};
		SDL_Window *mWindow;
		SDL_Surface *mSurface;
		SDL_Surface *mWindowSurface;
};
