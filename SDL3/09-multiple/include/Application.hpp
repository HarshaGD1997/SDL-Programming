#pragma once

#include "Rectangle.hpp"

struct Application{
	Application(int argc, char **argv){
		StartUp();
	}
	~Application(){
		ShutDown();
	}

	void StartUp(){
		if(SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) != 0){
			SDL_Log("Error %s", SDL_GetError());
		}
		else{
			SDL_Log("Init Successfully");
			mWindow = SDL_CreateWindow("SDL3", 640, 480, SDL_EVENT_WINDOW_SHOWN);
			RectInit();
			mRenderer = SDL_CreateRenderer(mWindow, NULL);
		

			
			
		}
	}

	void RectInit(){
		mRect = mRectangle->GetRect(10,20,100,200);
		
	}

	void ShutDown(){
		SDL_DestroyRenderer(mRenderer);
		SDL_DestroyWindow(mWindow);
		SDL_Quit();
	}

	void Input(){
		SDL_Event event;
		while(SDL_PollEvent(&event)){
			if(event.type == SDL_EVENT_QUIT){
				mRun = false;
			}
		
		}
	}

	void Update(){
		
	}

	void Render(){
		SDL_SetRenderDrawColor(mRenderer, 0, 0, 0xff, SDL_ALPHA_OPAQUE);
		SDL_RenderClear(mRenderer);
		SDL_SetRenderDrawColor(mRenderer, 0xff, 0xff, 0xff, SDL_ALPHA_OPAQUE);
		SDL_RenderRect(mRenderer, &mRect);
		SDL_RenderPresent(mRenderer);
	}

	void Loop(){
		while(mRun){
			Input();
			Update();
			Render();
		}

	}


	private:
		SDL_Renderer *mRenderer;		
		Rectangle *mRectangle;
		SDL_FRect mRect;

		bool mRun{true};
		SDL_Window *mWindow;
};
