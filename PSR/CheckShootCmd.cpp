#include "CheckShootCmd.h"

CheckShootCmd::CheckShootCmd(Game& game) : Command(game)
{
}

CheckShootCmd::~CheckShootCmd()
{
}

void CheckShootCmd::Execute()
{
	if (mReceiver)
	{
		mReceiver->CheckShoot();
	}
}
