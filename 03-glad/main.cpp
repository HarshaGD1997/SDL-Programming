/* 
 * Making use of OpenGL library
 * Compilation g++ -std=c++17 main.cpp -o prog -I./glad/include -ldl -lSDL2 
 */

#include <iostream>
#include <SDL2/SDL.h>

#include <glad/glad.h>


int main(int argc, char **argv){
	
	bool isRunning = true;
	SDL_Window *window = nullptr;

	if(SDL_Init(SDL_INIT_VIDEO) < 0){
		std::cout << "error with initialization of video card" <<std::endl;
	}
	else{
		std::cout << "working" <<std::endl;
	}

	// Specifying version of OpenGL to 4.1 and also setting it to core profile
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 4);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 1);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);

	// Configuring graphics 
	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
	SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);

	window = SDL_CreateWindow("OpenGL into",
				0,
				0,
				640,
				480,
				SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL);


	// Creating and setting OpenGL Context to the main window
	SDL_GLContext context;
	context = SDL_GL_CreateContext(window);

	// Setup function pointers
	// Without function pointer, we get SegFault	
	gladLoadGLLoader(SDL_GL_GetProcAddress);

	while(isRunning){
		glViewport(0,0,640,480);
		SDL_Event event;
		while(SDL_PollEvent(&event)){
			if(event.type == SDL_QUIT){
				isRunning = false;
			}
		}
		
		glClearColor(1.0f, 0.0f, 0.0f, 1.0f);
		glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);

		SDL_GL_SwapWindow(window);
	}
	
	SDL_DestroyWindow(window);
	SDL_Quit();

	return 0;
}
