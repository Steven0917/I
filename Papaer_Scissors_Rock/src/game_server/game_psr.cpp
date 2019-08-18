#include "game_psr.h"

namespace PUMA {
namespace Kernel {

GamePSR::GamePSR() : mStop(false)
{
}

GamePSR::GamePSR(Networker & networker) : Context(networker), mStop(false)
{
}

GamePSR::~GamePSR()
{
}

void GamePSR::Start()
{
	
}

}  // namespace Kernel
}  // namespace PUMA
