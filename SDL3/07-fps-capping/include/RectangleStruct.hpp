#pragma once

#include <SDL3/SDL.h>

struct RectangleStruct{
	RectangleStruct(float x, float y, float h, float w){
		rect.x = x;
		rect.y = y;
		rect.h = h;
		rect.w = w;
	}

	~RectangleStruct(){
	
	}

	SDL_FRect GetRect(){
		return rect;	
	}

	private:
		SDL_FRect rect;
};
