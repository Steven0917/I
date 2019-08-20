#include "check_shoot_cmd.h"

namespace Game {
namespace PSR {
	
CheckShootCmd::CheckShootCmd(GameEngine& game) : Command(game)
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

}  // namespace PSR
}  // namespace Game
