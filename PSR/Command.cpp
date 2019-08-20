#include "command.h"

namespace Game {
namespace PSR {

Command::Command(GameEngine& game) : mReceiver(&game)
{
}

Command::~Command()
{
}

}  // namespace PSR
}  // namespace Game
