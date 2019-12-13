#include "State.h"

StateMachine::StateMachine(::ComponentType type) : Component(type), m_pCurr(nullptr), m_pNext(nullptr)
{
	
}

StateMachine::~StateMachine(){}

void StateMachine::Update(float dt)
{
	if (m_pCurr == 0)
	{
		m_pCurr = m_pNext;
		m_pCurr->Enter(dt);
	}
	else if (m_pCurr == m_pNext)
		m_pCurr->Update(dt);
	else
	{
		m_pCurr->Exit(dt);
		m_pCurr = m_pNext;
		m_pCurr->Enter(dt);
	}
}

void StateMachine::setNextState(State* pNext)
{
	m_pNext = pNext;
}



