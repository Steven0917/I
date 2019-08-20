#pragma once
#include "command.h"

namespace Game {
namespace PSR {

class CheckStartCmd : public Command
{
public:
	CheckStartCmd(GameEngine& game);
	virtual ~CheckStartCmd();

	virtual void Execute();

};


}  // namespace PSR
}  // namespace Game
