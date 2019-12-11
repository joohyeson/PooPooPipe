#include "FitPuzzleComponent.h"

void PuzzleComponent::Update(float dt)
{
	
}

bool PuzzleComponent::giveDir(int i)
{
	if(i == 0)
	{
		return dirArray1;
	}
	else
	{
		return dirArray2;
	}
}
