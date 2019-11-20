#pragma once
#include "Object.h"

enum PuzzleState
{
	FitIn,
	FitOut,
	Connect,
	NotConnect,
	Rotate,
	Translate,
};

class PuzzleComponent : public Component
{
public:
	PuzzleComponent();
	virtual void Update(float dt);
private:
	bool connectCheck;
	PuzzleState mCurrentstate;
};
//etc,,,