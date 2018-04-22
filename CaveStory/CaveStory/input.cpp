/*
	Input Class - Tracks Keyboard Key States
*/

#include "input.h"

// Called at the beginning of each new frame and resets no longer relevent keys.
void Input::beginNewFrame()
{
	this->_pressedKeys.clear();
	this->_releasedKeys.clear();
}

// Called on Keypress
void Input::keyDownEvent(const SDL_Event& event)
{
	this->_pressedKeys[event.key.keysym.scancode] = true;
	this->_heldKeys[event.key.keysym.scancode] = true;
}

// Called on KeyRelease
void Input::keyUpEvent(const SDL_Event& event)
{
	this->_releasedKeys[event.key.keysym.scancode] = true;
	this->_heldKeys[event.key.keysym.scancode] = false;
}

// Check if Key was pressed in current Frame
bool Input::wasKeyPressed(SDL_Scancode key)
{
	return this->_pressedKeys[key];
}
// Check if Key was released during current frame
bool Input::wasKeyReleased(SDL_Scancode key)
{
	return this->_releasedKeys[key];
}
// Check if Key is being held during current frame
bool Input::isKeyHeld(SDL_Scancode key)
{
	return this->_heldKeys[key];
}



