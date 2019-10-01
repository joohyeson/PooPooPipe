
#include "Input.h"


Input::Input(){}
Input::~Input(){}

std::bitset <SDL_NUM_SCANCODES> Input::keyPressed;
std::bitset <SDL_NUM_SCANCODES>  Input::keyReleased;
std::bitset <SDL_NUM_SCANCODES>  Input::keyTriggered;

std::bitset <NUM_MOUSECODES>  Input::mousePressed;
std::bitset <NUM_MOUSECODES>  Input::mouseReleased;
std::bitset <NUM_MOUSECODES>  Input::mouseTriggered;

void Input::ResetKeyboardStatus(void)
{
	Input::keyPressed.reset();
	Input::keyReleased.reset();
}

void Input::SetKeyPressed(SDL_Scancode key, SDL_EventType keyEvent)
{
	if (keyEvent == SDL_KEYDOWN)
	{
		keyPressed.set(key);
		keyTriggered.set(key);
	}
	else if (keyEvent == SDL_KEYUP)
	{
		keyReleased.set(key);
		keyPressed.reset(key);
	}
}

bool Input::IsPressed(SDL_Scancode key)
{
	
	return keyPressed[key];
}

bool Input::IsReleased(SDL_Scancode key)
{
	return keyReleased[key];
}

bool Input::IsTriggered(SDL_Scancode key)
{
	return keyTriggered[key];
}

bool Input::IsAnyPressed(void)
{
	return keyPressed.any();
}

bool Input::IsAnyReleased(void)
{
	return keyReleased.any();
}

bool Input::IsAnyTriggered(void)
{
	return keyTriggered.any();
}

void Input::ResetMouseStatus(void)
{
	mousePressed.reset();
	mouseTriggered.reset();
	mouseReleased.reset();
}

void Input::SetMousePressed(MouseButton mouse, SDL_EventType mouseEvent)
{
	if (mouseEvent == SDL_MOUSEBUTTONDOWN)
	{
		mousePressed.set(mouse);
		mouseTriggered.set(mouse);
	}
	else if (mouseEvent == SDL_MOUSEBUTTONUP)
	{
		mouseReleased.set(mouse);
		mousePressed.reset(mouse);
	}
}

bool Input::IsPressed(MouseButton mouse)
{
	return mousePressed[mouse];
}
bool Input::IsReleased(MouseButton mouse)
{
	return mouseReleased[mouse];
}
bool Input::IsTriggered(MouseButton mouse)
{
	return mouseTriggered[mouse];
}
bool Input::IsAnyPressed(MouseButton mouse)
{
	return mousePressed[mouse];
}
bool Input::IsAnyReleased(MouseButton mouse)
{
	return mouseReleased.any();
}
bool Input::IsAnyTriggered(MouseButton mouse)
{
	return mouseTriggered.any();
}
