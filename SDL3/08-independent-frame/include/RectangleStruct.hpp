#pragma once
#include <SDL3/SDL.h>

struct RectangleStruct{
	RectangleStruct(float x, float y, float w, float h){
		mRect.x = x;
		mRect.y = y;
		mRect.w = w;
		mRect.h = h;
	
	}

	~RectangleStruct(){
	
	}

	SDL_FRect GetRect(){
		return mRect;
	}

	private:
		SDL_FRect mRect;

};
