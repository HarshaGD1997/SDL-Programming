#pragma once

#include "RectangleStruct.hpp"

struct Application{
	Application(int argc, char **argv){
		StartUp();	
	}
	~Application(){
		ShutDown();
	}

	void ShutDown(){
		SDL_DestroyRenderer(mRenderer);
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
			mRenderer = SDL_CreateRenderer(mWindow, NULL);
			
			InitRect();

		}
	}

	void InitRect(){
		mRect = rect->GetRect();
		mRect.x = 10;
		mRect.y = 20;
		mRect.w = 200;
		mRect.h = 100;
				
	}

	void Input(){
		SDL_Event event;
		if(SDL_PollEvent(&event)){
			if(event.type == SDL_EVENT_QUIT){
				mRun = false;
			}
		}
	}

	void MovingRect(){
	
		mRect.x += xAcc;
		mRect.y += yAcc;

		if(mRect.x + mRect.w >= 640 || mRect.x  <= 0){
			xAcc = -xAcc;
		}

		if(mRect.y + mRect.h >= 480 || mRect.y <= 0){
			yAcc = -yAcc;
		}
	}

	void Update(){
		MovingRect();	
	}

	void Render(){
		SDL_SetRenderDrawColor(mRenderer, 0, 0, 0xff, SDL_ALPHA_OPAQUE);
		SDL_RenderClear(mRenderer);
		SDL_SetRenderDrawColor(mRenderer, 0xff, 0xff, 0, SDL_ALPHA_OPAQUE);
		SDL_RenderRect(mRenderer, &mRect);
		SDL_RenderPresent(mRenderer);
	}

	void Loop(){
		Uint64 currentTime, lastTime;
		lastTime = SDL_GetTicks();
		Uint64 fpsCount = 0;
		while(mRun){
			Uint64 startingFrame = SDL_GetTicks();
			Input();
			Update();
			Render();
			Uint64 elapsedTime = SDL_GetTicks()-startingFrame;
			fpsCount++;

			currentTime = SDL_GetTicks();
			
			/*if(currentTime > lastTime+(1000/60)){
				SDL_Delay(
			}*/

			if(elapsedTime < (1000/60)){
				Uint64 delay = (1000/60) - elapsedTime;
				SDL_Delay(delay);
				//SDL_Log("delay %li", delay);
			}

			if(currentTime > lastTime + 1000){
				SDL_Log("fps : %li", fpsCount);
				fpsCount = 0;
				lastTime = SDL_GetTicks();
			}
		}
	}

	private:
		
		int yAcc{5};
		int xAcc{5};
		RectangleStruct *rect;
		SDL_FRect mRect;
		SDL_Window *mWindow;
		bool mRun{true};
		SDL_Renderer *mRenderer;
};
