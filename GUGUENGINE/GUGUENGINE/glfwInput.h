#pragma once
#include "../GUGUENGINE/Application.h"
#include "../GUGUENGINE/Mathematics/Vector2.hpp"

enum KEY
{
	IGNORE,
	IGNORE2,
	SPACE,
	A,
	ESCAPE,
	TAB,
	LEFT,
	RIGHT,
};

class Input
{
public:
	Input():Cursor({ 0, 0 }),keySpace(0), keyA(0), keyEscape(0), keyTap(0), mouseLeft(0), mouseRight(0){}
	~Input(){}

	void InitCallback(GLFWwindow* window);
	void SetInput();
	bool IsPressed(int key);
	bool IsTrigerred(int key);
	
	void SetMousetriggered(int i)
	{
		MouseRightTriggered += i;
		if(i == 0)
		{
			MouseRightTriggered = 0;
		}
	}
	
	Vector2<float> Cursor;
	int keySpace;
	int keyA;
	int keyEscape;
	int keyTap;
	int mouseLeft;
	int mouseRight;

	int MouseRightTriggered = 0;
};






