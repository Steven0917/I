#pragma once
#include "game.h"

namespace Game {
namespace PSR {

class Command
{
public:
	Command(GameEngine& game);
	virtual ~Command();

	virtual void Execute() {};

protected:
    GameEngine* mReceiver;
};


}  // namespace PSR
}  // namespace Game
