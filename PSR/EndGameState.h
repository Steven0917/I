#pragma once
#include "IState.h"

class EndGameState : public IState
{
public:
	EndGameState(Game& game);
	virtual ~EndGameState();

	virtual void Entry();
	virtual void Exit();

	virtual string ToString();
};

