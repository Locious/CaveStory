/*
	Game Class
	Used for 'main' Game Loop
*/
#include <SDL.h>
#include <algorithm>

#include "game.h"
#include "graphics.h"
#include "input.h"

namespace{
	const int FPS = 50;
	const int MAX_FRAME_TIME = 5 * 1000 / FPS;
}

Game::Game() {
	SDL_Init(SDL_INIT_EVERYTHING);
	this->game_loop();
}

Game::~Game(){
	
}

void Game::game_loop()
{
	Graphics graphics;
	Input input;
	SDL_Event event;

	int LAST_UPDATE_TIME = SDL_GetTicks();
	// Start of Game Loop
	while (true){
		input.beginNewFrame();

		if (SDL_PollEvent(&event)){
			if (event.type == SDL_KEYDOWN){
				if (event.key.repeat == 0){
					input.keyDownEvent(event);
				}
			}
			else if (event.type == SDL_KEYUP){
				return;
			}
			else if (event.type == SDL_QUIT)
				return;
		}
		if (input.wasKeyPressed(SDL_SCANCODE_ESCAPE) == true){
			return;
		}

		const int CURRENT_TIME_MS = SDL_GetTicks();
		int ELAPSED_TIME_MS = CURRENT_TIME_MS - LAST_UPDATE_TIME;
		this->update(std::min(ELAPSED_TIME_MS, MAX_FRAME_TIME));
		LAST_UPDATE_TIME = CURRENT_TIME_MS;
	}
}

void Game::draw(Graphics &graphics)
{

}

void Game::update(float elapsedtime)
{

}

