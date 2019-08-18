#pragma once
#include "event_queue.h"
#include "context.h"

using namespace std;

namespace PUMA {
namespace Kernel {

class Server;
class GamePSR : public Context
{
public:
	GamePSR();
	GamePSR(Networker& networker);
	~GamePSR();

	void Start();

	EventQueue mEventQueue;

private:
	bool mStop;
};

}  // namespace Kernel
}  // namespace PUMA

