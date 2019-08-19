#include "CheckStartCmd.h"

CheckStartCmd::CheckStartCmd(Game& game) : Command(game)
{
}

CheckStartCmd::~CheckStartCmd()
{
}

void CheckStartCmd::Execute()
{
	if (mReceiver)
	{
		mReceiver->CheckStart();
	}
}
