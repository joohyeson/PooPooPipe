#pragma once
#include "Component.h"
#include "Mesh.h"


enum PuzzleDirection
{
	NE,
	E,
	SE,
	SW,
	W,
	NW,
};

class [[nodiscard]] PuzzleComponent : public Component
{
public:
	PuzzleComponent() : Component(COMPONENTTYPE_PIPE)
	{
		dirArray1[0] =  true;
		dirArray1[1] = false;
		dirArray1[2] = false;
		dirArray1[3] = true;
		dirArray1[4] = false;
		dirArray1[5] = false;

		/*dirArray2[0] = true;
		dirArray2[1] = false;
		dirArray2[2] = true;
		dirArray2[3] = false;;
		dirArray2[4] = false;
		dirArray2[5] = false;*/
		
		
	}
	~PuzzleComponent() override
	{
		
	}
	void Update();

private:
	
	//bool dirArray1[6] = { true, false,false,true,false,false };
	//bool dirArray2[6] = { true, false,false,false,true,false };
	bool dirArray1[6];
	bool dirArray2[6];
	
	int clickCount = 0;
};

//etc,,,