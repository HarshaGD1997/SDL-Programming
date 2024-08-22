#include <SDL3/SDL.h>

struct Rect{
	
	SDL_FRect rect;
	Rect(int x, int y, int w, int h){
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
		mRect = new Rect(0,0,40,80);
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

	}

	void Loop(){
	
		while(mRun){
			Input();
			Update();
			Render();
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
	
	}

	void Render(){
		SDL_SetRenderDrawColor(mRenderer, 0xff, 0, 0, SDL_ALPHA_OPAQUE);
		SDL_RenderClear(mRenderer);
		SDL_SetRenderDrawColor(mRenderer, 0, 0, 0xff, SDL_ALPHA_OPAQUE);
		SDL_FRect rect = mRect->GetRect();
		SDL_RenderRect(mRenderer,&rect);
		SDL_RenderPresent(mRenderer);
		
	}

	private:

		bool mRun{true};
		SDL_Window *mWindow;
		SDL_Renderer *mRenderer;
		Rect *mRect;
};
