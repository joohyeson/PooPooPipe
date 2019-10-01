#pragma once

#include <SDL.h>
#include <bitset>

#define NUM_MOUSECODES 4
typedef int MouseButton;

class Input {
public:

	Input();
	~Input();

	static void ResetKeyboardStatus(void);
	void SetKeyPressed(SDL_Scancode key, SDL_EventType keyEvent);

	bool IsPressed(SDL_Scancode key);
	bool IsReleased(SDL_Scancode key);
	bool IsTriggered(SDL_Scancode key);
	bool IsAnyPressed(void);
	bool IsAnyReleased(void);
	bool IsAnyTriggered(void);

	static void ResetMouseStatus(void);
	void SetMousePressed(MouseButton mouse, SDL_EventType mouseEvent);

	bool IsPressed(MouseButton mouse);
	bool IsReleased(MouseButton mouse);
	bool IsTriggered(MouseButton mouse);
	bool IsAnyPressed(MouseButton mouse);
	bool IsAnyReleased(MouseButton mouse);
	bool IsAnyTriggered(MouseButton mouse);

	
private:

	static std::bitset <SDL_NUM_SCANCODES> keyPressed;
	static std::bitset <SDL_NUM_SCANCODES> keyReleased;
	static std::bitset <SDL_NUM_SCANCODES> keyTriggered;

	static std::bitset <NUM_MOUSECODES> mousePressed;
	static std::bitset <NUM_MOUSECODES> mouseReleased;
	static std::bitset <NUM_MOUSECODES> mouseTriggered;

};

