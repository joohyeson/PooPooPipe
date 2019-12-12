#include "FitPuzzleComponent.h"

void PuzzleComponent::Update()
{
	bool temp = dirArray1[0];
	
	for(int i = 0; i < 6; i++)
	{
		dirArray1[i] = dirArray1[i + 1];
		if(i == 5)
		{
			dirArray1[i] = temp;
		}
		std::cout << dirArray1[i];
	}
	
}


