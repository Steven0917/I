#include "check_start_cmd.h"

namespace Game {
namespace PSR {

CheckStartCmd::CheckStartCmd(GameEngine& game) : Command(game)
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

}  // namespace PSR
}  // namespace Game
