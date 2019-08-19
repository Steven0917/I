#pragma once
#include "Game.h"

class Command
{
public:
	Command(Game& game);
	virtual ~Command();

	virtual void Execute() {};

protected:
	Game* mReceiver;
};

