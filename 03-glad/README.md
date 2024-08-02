
# SDL2 using OpenGL library (glad v4.1 core)




## Lessons Learned

#### SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
Purpose: Enables double buffering, a technique used to minimize flickering and tearing in graphics rendering.

How it works: Double buffering uses two buffers to hold frame data. While one buffer is being displayed, the other buffer is used to render the next frame. When rendering is complete, the buffers are swapped.

#### SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);

Purpose: Specifies the size of the depth buffer, which is used for depth testing in 3D graphics.

How it works: A 24-bit depth buffer provides a range of depth values for each pixel, allowing the GPU to determine which objects are in front of others and render them accordingly.

#### context = SDL_GL_CreateContext(window);

Purpose: Creates an OpenGL context associated with the specified window.

How it works: An OpenGL context is required for any OpenGL rendering. It stores all the state associated with OpenGL rendering. This line essentially initializes OpenGL for use with the given SDL window.

#### gladLoadGLLoader(SDL_GL_GetProcAddress);

Purpose: Loads the OpenGL function pointers.

How it works: glad is a library that loads OpenGL functions at runtime. SDL_GL_GetProcAddress is used to get the address of the OpenGL functions. This step is crucial because OpenGL function pointers need to be retrieved before you can call any OpenGL functions.

#### glViewport(0, 0, 640, 480);

Purpose: Sets the viewport, which defines the drawable region of the window.

How it works: This function specifies the affine transformation of x and y from normalized device coordinates to window coordinates. In this case, it sets the viewport to cover the entire window of 640x480 pixels.

#### glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);

Purpose: Clears the specified buffers to preset values.

How it works: This function clears the depth buffer and the color buffer. GL_DEPTH_BUFFER_BIT clears the depth buffer, which is used for depth testing, and GL_COLOR_BUFFER_BIT clears the color buffer, which holds the color values of the pixels.

#### SDL_GL_SwapWindow(window);

Purpose: Swaps the front and back buffers.

How it works: In double buffering, the front buffer is the one currently being displayed, while the back buffer is the one where rendering takes place. SDL_GL_SwapWindow swaps these buffers, displaying the newly rendered frame and preparing the back buffer for the next frame's rendering.