#pragma once

#include <SDL3/SDL.h>

struct Application{
	Application(int argc, char **argv){
		StartUp();	
	}
	~Application(){
		ShutDown();
	}

	void ShutDown(){
		SDL_DestroyWindow(mWindow);
		SDL_Quit();
	}

	void StartUp(){
		if(SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO ) != 0){
			SDL_Log("Error %s",SDL_GetError());
		}

		else{
			SDL_Log("SDL Audio and video initialized");
			mWindow = SDL_CreateWindow("SDL3", 640, 480, SDL_EVENT_WINDOW_SHOWN);
		}
	}

	void Input(){
		SDL_Event event;
		if(SDL_PollEvent(&event)){
			if(event.type == SDL_EVENT_QUIT){
				mRun = false;
			}
		}
	}

	void Update(){
	
	}

	void Render(){
	
	}

	void Loop(){
		while(mRun){
			Input();
			Update();
			Render();
		}
	}

	private:
		SDL_Window *mWindow;
		bool mRun{true};
};
