#pragma once
#include "IState.h"

class ShootState : public IState
{
public:
	ShootState(Game& game);
	virtual ~ShootState();

	virtual void Entry();
	virtual void Exit();

	virtual string ToString();
};

