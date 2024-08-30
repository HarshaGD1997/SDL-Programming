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
		SDL_DestroyRenderer(mRenderer);
		SDL_DestroyWindow(mWindow);
		SDL_Quit();
	}

	void StartUp(){
		if(SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) != 0){
			SDL_Log("Error %s",SDL_GetError());
		}
		mWindow = SDL_CreateWindow("SDL3", 640, 480, SDL_EVENT_WINDOW_SHOWN);

		mRenderer = SDL_CreateRenderer(mWindow, NULL);
		if(mRenderer == nullptr){
			SDL_Log("Error with Renderer");
		}
		
		mRect.x = 5.0f;
		mRect.y = 5.0f;
		mXVelocity = 5.0f;
		mYVelocity = 5.0f;
		mRect2.x = 40.0f;
		mRect2.y = 20.0f;
	
	}

	void Update(){

		mRect.x += mXVelocity;
		mRect.y += mYVelocity;
	
		mRect2.x += mXVelocity;
		mRect2.y += mYVelocity;

		if(mRect2.x + mRect2.w > 640 || mRect2.x < 0){
			mXVelocity = -mXVelocity;
		}

		if(mRect2.y + mRect2.h > 480 || mRect2.y < 0){
			mYVelocity = -mYVelocity;
		}

		if(mRect.x + mRect.w  > 640 || mRect.x < 0){
			mXVelocity = -mXVelocity;		
			
		}
		if(mRect.y + mRect.h > 480 || mRect.y < 0){
			mYVelocity = -mYVelocity;
		}
		
	}

	void Render(){

		SDL_SetRenderDrawColor(mRenderer, 0xff, 0, 0, SDL_ALPHA_OPAQUE);
		SDL_RenderClear(mRenderer);
	
		SDL_SetRenderDrawColor(mRenderer, 0, 0xff, 0, SDL_ALPHA_OPAQUE);	
		SDL_RenderRect(mRenderer, &mRect);
		
		SDL_SetRenderDrawColor(mRenderer, 0, 0, 0xff, SDL_ALPHA_OPAQUE);
		SDL_RenderRect(mRenderer, &mRect2);	
		SDL_RenderPresent(mRenderer);

	
	}

	void Input(){
		SDL_Event event;
		if(SDL_PollEvent(&event)){
			if(event.type == SDL_EVENT_QUIT){
				mRun = false;
			}
		}

	}

	void Loop(){
		while(mRun){
			Input();
			Update();
			Render();
			SDL_Delay(16);
		}
	}

	private:
		bool mRun{true};
		SDL_Window *mWindow;
		SDL_Renderer *mRenderer;
		SDL_FRect mRect{0.0f, 0.0f, 40.0f, 20.0f};
		SDL_FRect mRect2{0.0f, 0.0f, 20.0f, 40.0f};
		float mXVelocity;
		float mYVelocity;

};
