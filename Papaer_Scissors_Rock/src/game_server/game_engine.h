#pragma once
#include "event_queue.h"
#include "context.h"
#include "network_handler.h"
#include "game_state.h"
#include "idle_state.h"

using namespace std;

namespace Game {
namespace PSR {

class GameState;
class GameEngine : public Context
{
public:
    GameEngine(Networker& networker);
	~GameEngine();

	void Start();

private:
	bool mStop;
	//EventQueue mEventQueue;
    NetworkHandler mHandler;
    GameState*     mpState;

    IdleState     mIdleState;
    friend class RegisterRequestHandler;
};

}  // namespace PSR
}  // namespace Game

