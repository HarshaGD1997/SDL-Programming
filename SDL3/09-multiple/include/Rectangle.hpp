#pragma once
#include <cstdlib>
#include <time.h>
#include <SDL3/SDL.h>

#define MAX 10

struct Rectangle{

	/*Rectangle(float x, float y, float w, float h){
		mRect.x = x+rand()%MAX;
		SDL_Log("%f",mRect.x);
		mRect.y = y;
		mRect.w = w;
		mRect.h = h;
		//RectRandomizer();
	
	}*/
	Rectangle(){}

	~Rectangle(){
	
	}

	SDL_FRect GetRect(float x, float y, float h, float w){
		mRect.x = x;
		mRect.y = y;
		mRect.w = w;
		mRect.h = h;
		return mRect;
	}

	/*void RectRandomizer(){
			srand(time(NULL));
			mRect.x = 1+rand() % MAX;
			mRect.y = 1+rand() % MAX;

			SDL_Log("%f",mRect.x);	
	}*/

	

	private:
		SDL_FRect mRect;

};
