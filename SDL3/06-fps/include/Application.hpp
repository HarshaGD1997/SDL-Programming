#include <SDL3/SDL.h>
#include <stdlib.h>

struct Rect{
	
	SDL_FRect rect;
	Rect(int x, int y, int w, int h, int number){
		rect.x = x;
		rect.y = y;
		rect.h = h;
		rect.w = w;
	}

	SDL_FRect GetRect(){
		return rect;
	}

	


};


struct Application{
	Application(int argc, char **argv){
		mRect = new Rect(0,0,40,80,1);
		StartUp();
	}
	~Application(){
		ShutDown();
	}

	void ShutDown(){
		delete mRect;
		SDL_DestroyRenderer(mRenderer);
		SDL_DestroyWindow(mWindow);
		SDL_Quit();
	}

	void StartUp(){
		if(SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) != 0){
			SDL_Log("Error %s",SDL_GetError());
		}
		
		mWindow = SDL_CreateWindow("SDL3", 640, 480, SDL_EVENT_WINDOW_SHOWN);
		
		if(mWindow == nullptr){
			SDL_Log("Error with window creation");
		}

		mRenderer = SDL_CreateRenderer(mWindow, NULL);
		if(mRenderer == nullptr){
			SDL_Log("Error with renderer");
		}		
		rect = mRect->GetRect();

	}

	void Loop(){

		Uint64 lastTime, currentTime;
		Uint64 frameElapsed = 0;
		lastTime = SDL_GetTicks();
		while(mRun){
			Input();
			Update();
			Render();
			frameElapsed++;
			currentTime = SDL_GetTicks();
			if(currentTime > lastTime+1000){
				SDL_Log("1 sec");
				SDL_Log("FPS : %lu",frameElapsed);
				frameElapsed = 0;
				lastTime = SDL_GetTicks();
			}
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
		rect.x += xAcc;
	
		//SDL_Log("%d", xAcc);
		//SDL_Log("%f", rect.x);
		if(rect.x + rect.w >= 640){
			//SDL_Delay(2000);

			xAcc = -xAcc;
		}
		if(rect.x <= 0){
			xAcc = -xAcc;
		}

	}

	void Render(){
		SDL_SetRenderDrawColor(mRenderer, 0xff, 0, 0, SDL_ALPHA_OPAQUE);
		SDL_RenderClear(mRenderer);
		SDL_SetRenderDrawColor(mRenderer, 0, 0, 0xff, SDL_ALPHA_OPAQUE);

		SDL_RenderRect(mRenderer,&rect);
		SDL_RenderPresent(mRenderer);
		
	}

	private:

		bool mRun{true};
		SDL_Window *mWindow;
		SDL_Renderer *mRenderer;
		Rect *mRect;
		SDL_FRect rect;
		int xAcc{5};
};
