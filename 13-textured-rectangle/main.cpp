#include <iostream>
#include <SDL2/SDL.h>
#include <string> //for c_str() function
	

class TextureRect{
	public:
		TextureRect(SDL_Renderer *&renderer, std::string filepath){
			SDL_Surface *image = SDL_LoadBMP(filepath.c_str());
			m_texture = SDL_CreateTextureFromSurface(renderer, image);
			SDL_FreeSurface(image);

		
	
		}
		~TextureRect(){
			
			SDL_DestroyTexture(m_texture);
		}

		void SetRectProps(int x, int y, int h, int w){
			m_rect.x = x;
		       	m_rect.y = y;
			m_rect.h = h;
			m_rect.w = w;	
		
		}

		void Update(){
		
		}

		void Render(SDL_Renderer *&renderer){

			SDL_RenderCopy(renderer, m_texture, NULL, &m_rect);
		}
		
	private:
		SDL_Rect m_rect;
		SDL_Texture *m_texture;
};

int main(int argc, char **argv){
	
	if(SDL_Init(SDL_INIT_VIDEO) < 0){
		std::cout << "Error " << SDL_GetError() << std::endl;
		return -1;
	}
	else{
		std::cout << "video system is working" << std::endl;
	}

	SDL_Window *window = SDL_CreateWindow("textured-rect", 0, 0, 640, 480, SDL_WINDOW_SHOWN);

	bool isRunning = true;

	SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);


	TextureRect trect(renderer, "./images/1.bmp");

	while(isRunning){
		SDL_Event event;
		while(SDL_PollEvent(&event)){
			if(event.type == SDL_QUIT){
				isRunning = false;
			}
		}

		SDL_SetRenderDrawColor(renderer, 0, 0, 0x1f, SDL_ALPHA_OPAQUE);
		SDL_RenderClear(renderer);
		
		trect.SetRectProps(10,20,100,200);
		trect.Render(renderer);
		SDL_RenderPresent(renderer);
	}

	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
	return 0;
}
