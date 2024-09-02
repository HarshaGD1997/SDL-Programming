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
	
		SDL_DestroyTexture(mTexture);
		SDL_DestroyRenderer(mRenderer);
		SDL_DestroyWindow(mWindow);
		SDL_Quit();
	
	}

	


	void StartUp(){
		if(SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) != 0){
			SDL_Log("Error %s",SDL_GetError());
		}
		else{
			SDL_Log("Video and Audio Initialized successfully");
			mWindow = SDL_CreateWindow("SDL3", 640, 480, SDL_EVENT_WINDOW_SHOWN);
			mRenderer = SDL_CreateRenderer(mWindow, NULL);
			InitRect();
			mSurface = SDL_LoadBMP("./images/menu.bmp");
			mTexture = SDL_CreateTextureFromSurface(mRenderer, mSurface);
			SDL_DestroySurface(mSurface);
		}
	
	}

	void InitRect(){
		mRect = mRectStr->GetRect();
		mRect.x = 10;
		mRect.y = 20;
		mRect.w = 200;
		mRect.h = 200;
	}

	void Input(){
		SDL_Event event;
		while(SDL_PollEvent(&event)){
			if(event.type == SDL_EVENT_QUIT){
				mRun = false;
			}	
		}
	
	}


	void Update(float deltaTime){
		mRect.x += xAcc * deltaTime;
		mRect.y += yAcc * deltaTime;

		if(mRect.x + mRect.w >= 640 || mRect.x <= 0){
			xAcc = -xAcc;
		}
		if(mRect.y + mRect.h >= 480 || mRect.y <= 0){
			yAcc = -yAcc;
		}
	}

	void Render(){

		SDL_SetRenderDrawColor(mRenderer, 0, 0, 0xff, SDL_ALPHA_OPAQUE);
		SDL_RenderClear(mRenderer);
		SDL_SetRenderDrawColor(mRenderer, 0xff, 0, 0xe1, SDL_ALPHA_OPAQUE);
		//SDL_RenderRect(mRenderer, &mRect);
		SDL_RenderTexture(mRenderer, mTexture, NULL, &mRect);
		SDL_RenderPresent(mRenderer);	
	
	}

	void Loop(){
		Uint64 currentTime, lastTime;
		float deltaTime = 1.0f/60.0f;
		int fps = 0;
		lastTime = SDL_GetTicks();
		while(mRun){
			Uint64 startingFrame = SDL_GetTicks();
			Input();
			Update(deltaTime);
			Render();
			Uint64 endingFrame = SDL_GetTicks()-startingFrame;
			
			fps++; 

			currentTime = SDL_GetTicks();

			if(endingFrame < (1000/60)){
				Uint64 delay = (1000/60)-endingFrame;
				SDL_Delay(delay);
			}

			if(currentTime > lastTime + 1000){
				SDL_Log("fps : %d",fps);
				deltaTime = 1.0/fps;
				lastTime = SDL_GetTicks();
				fps = 0;
			}
		}


	
	}

	private:
		SDL_Texture *mTexture;
		SDL_Surface *mSurface;
		int xAcc{100}, yAcc{100};
		RectangleStruct *mRectStr;
		SDL_FRect mRect;
		bool mRun{true};
		SDL_Window *mWindow;
		SDL_Renderer *mRenderer;
};
