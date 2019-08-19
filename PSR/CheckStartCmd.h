#pragma once
#include "Command.h"

class CheckStartCmd : public Command
{
public:
	CheckStartCmd(Game& game);
	virtual ~CheckStartCmd();

	virtual void Execute();

};

