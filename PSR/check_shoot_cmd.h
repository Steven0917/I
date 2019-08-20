#pragma once
#include "command.h"

namespace Game {
namespace PSR {

class CheckShootCmd : public Command
{
public:
	CheckShootCmd(GameEngine& game);
	virtual ~CheckShootCmd();
	
	virtual void Execute();

};

}  // namespace PSR
}  // namespace Game
