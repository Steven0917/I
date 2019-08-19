#pragma once
#include "Command.h"

class CheckShootCmd : public Command
{
public:
	CheckShootCmd(Game& game);
	virtual ~CheckShootCmd();
	
	virtual void Execute();

};

