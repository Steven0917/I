#include "Command.h"


Command::Command(Game& game) : mReceiver(&game)
{
}

Command::~Command()
{
}
