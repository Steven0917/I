#pragma once
#include "IState.h"

class IdleState : public IState
{
public:
	IdleState(Game& game);
	virtual ~IdleState();

	virtual void Entry();
	virtual void Exit();
	
	virtual string ToString();
};

