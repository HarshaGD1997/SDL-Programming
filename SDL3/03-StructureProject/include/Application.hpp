#pragma once

#include <SDL3/SDL.h>

struct Application{
	Application(int argc, char* argv[]){
		Startup();
	}

	~Application(){
	
		Shutdown();
	}

	void Shutdown(){
		SDL_DestroyWindow(mWindow);
		SDL_Quit();
	}

	void Startup(){		

		if(SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) != 0){
			SDL_Log("Error %s", SDL_GetError());
		}

		mWindow = SDL_CreateWindow("SDL3", 640, 480, SDL_EVENT_WINDOW_SHOWN);
		if(!mWindow){
			SDL_Log("Error creating Window");
		}
		else{
			SDL_Log("Subsystems initialized and window is created");
		}

	}

	void Input(){
		SDL_Event event;
		while(SDL_PollEvent(&event)){
			if(event.type == SDL_EVENT_QUIT){
				//Event.quit.timestamp returns value in nanoseconds 
				//converting into seconds by dividing it by 1e9
				SDL_Log("Closing Application timestamp (secs): %li",(event.quit.timestamp)/1000000000);
				mRunning = false;
			}

			else if(event.type == SDL_EVENT_KEY_DOWN){
				SDL_Log("%u",event.key.key);

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
		while(mRunning){
			Input();
			Update();
			Render();
		}
	}


	private:
		bool mRunning{true};
		SDL_Window *mWindow;

};
