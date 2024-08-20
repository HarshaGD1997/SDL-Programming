/*
 *	Compilation and execution: 
 *	g++ main.cpp -o prog -std=c++20 `pkg-config --libs sdl3` && ./prog
 *	
 *
 *
*/

#include <iostream>
#include <SDL3/SDL.h>

struct Application{
	Application(int argc, char* argv[]){
		StartUp();
	}
	~Application(){
		Shutdown();
	}

	void StartUp(){
		//Initialize the Video and Audio subsystems 
		//and check for failure
		if(SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) != 0){
			SDL_Log("Error %s",SDL_GetError());
		}
		SDL_Window *mWindow = SDL_CreateWindow("SDL3 window",
							640,
							480,
							SDL_EVENT_WINDOW_SHOWN);

	}

	void Shutdown(){
		SDL_DestroyWindow(mWindow);
		SDL_Quit();
	}

	void Input(){
		SDL_Event event;
		//Processing Input
		while(SDL_PollEvent(&event)){
			if(event.type == SDL_EVENT_QUIT){
				SDL_Log("Program Quit %li", event.quit.timestamp);
				mRun = false;
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
		//Infinite Game loop
		while(mRun){
			Input();
			Update();
			Render();
		}
	}

	private:
	bool mRun{true};
	SDL_Window *mWindow;
};

int main(int argc, char *argv[]){
	
	Application app(argc, argv);
	app.Loop();


	return 0;
}
