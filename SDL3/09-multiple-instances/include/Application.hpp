#pragma once
#include <iostream>
#include <vector>
#include "Boxes.hpp"

struct Application{
	Application(int argc, char **argv){
		srand(static_cast<unsigned>(time(0)));
		StartUp();
	}

	~Application(){
		ShutDown();
	}

	void StartUp(){
		if(SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) != 0){
			std::cout << "Error " << SDL_GetError() << std::endl;	
		}
		else{
			std::cout << "Working" <<std::endl;
			mWindow = SDL_CreateWindow("Multiple Instances", 640, 480,  SDL_EVENT_WINDOW_SHOWN);
			SDL_SetWindowBordered(mWindow, SDL_TRUE);
			mRenderer = SDL_CreateRenderer(mWindow, nullptr);
			RectInit();
		}
	}

	void RectInit(){
		for(int i=0; i<5; i++){
			float x = static_cast<float>(rand() % 600);
			float y = static_cast<float>(rand() % 400);
			boxes.push_back(Boxes(x,y,40,50));
		}
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
		for(auto& box: boxes){
			box.Move();
			box.BounceIfNeeded(640,480);
		}
	}

	void Render(){
		SDL_SetRenderDrawColor(mRenderer, 0x30, 0, 0, SDL_ALPHA_OPAQUE);
		SDL_RenderClear(mRenderer);
		SDL_SetRenderDrawColor(mRenderer, 0, 0xff, 0xff, SDL_ALPHA_OPAQUE);
		//SDL_RenderLine(mRenderer, 30, 40, 50, 60);
		

		for(const auto& box: boxes){
			SDL_RenderRect(mRenderer, &box.GetRect());
		}
		SDL_RenderPresent(mRenderer);	
	}

	void Loop(){
		while(mRun){
			Input();
			Update();
			Render();
		}
	}

	void ShutDown(){
		SDL_DestroyRenderer(mRenderer);
		SDL_DestroyWindow(mWindow);
		SDL_Quit();
	}

	private:
		bool mRun{true};
		SDL_Window *mWindow;
		SDL_Renderer *mRenderer;
		std::vector<Boxes> boxes;	

};
