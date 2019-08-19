#pragma once
#include "event_queue.h"
#include "context.h"
#include "network_handler.h"
#include "game_state.h"
#include "idle_state.h"
#include "game_started_state.h"
#include "start_game_req_handler.h"

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

    IdleState          mIdleState;
    GameStartedState   mGameStartedState;

    StartGameRequestHandler mStartGameRequestHandler;

    friend class StartGameRequestHandler;
};

}  // namespace PSR
}  // namespace Game

