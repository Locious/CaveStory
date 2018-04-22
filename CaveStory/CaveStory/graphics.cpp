#include "graphics.h"
#include <SDL.h>

/*
* This will hold the information required for the game
*/

Graphics::Graphics() {
	SDL_CreateWindowAndRenderer(640, 480, 0, &this->_window, &this->_renderer);
	SDL_SetWindowTitle(this->_window, "CAVESTORY");
}

Graphics::~Graphics() {
	SDL_DestroyWindow(this->_window);
}
