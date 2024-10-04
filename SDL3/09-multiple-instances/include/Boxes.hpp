#pragma once 
#include <SDL3/SDL.h>
#include <cstdlib>
#include <ctime>

struct Boxes{
	Boxes(float x, float y, float h, float w){
		mRect.x = x;
		mRect.y = y;
		mRect.w = w;
		mRect.h = h;

		velocityX = static_cast<float>(rand() % 3 - 1);
		velocityY = static_cast<float>(rand() % 3 - 1);

		if(velocityX == 0 && velocityY == 0){
			velocityX = 1;
			
		}
	}

	~Boxes(){
	
	}

	void Move(){
		mRect.x += velocityX;
		mRect.y += velocityY;
	}

	SDL_FRect& GetRect() const{
		return const_cast<SDL_FRect&>(mRect);
	
	}

	void BounceIfNeeded(int w, int h){
		if(mRect.x <= 0 || mRect.x + mRect.w >= w){
			velocityX = -velocityX;
		}
		if(mRect.y <= 0 || mRect.y + mRect.h >= h){
			velocityY = -velocityY;
		}
	}

	private:
		SDL_FRect mRect;
		float velocityX, velocityY;
};
