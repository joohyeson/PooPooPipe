#pragma once
#include "Component.h"

class State
{
public:
	virtual ~State(){}
	virtual void Enter(float dt) = 0;
	virtual void Update(float dt) = 0;
	virtual void Exit(float dt) = 0;
};

class StateMachine : public Component
{
public:
	StateMachine(::ComponentType type);
	virtual ~StateMachine(void);
	virtual void Update(float dt);
	void setNextState(State* pNext);
private:
	State* m_pCurr;
	State* m_pNext; 

};

