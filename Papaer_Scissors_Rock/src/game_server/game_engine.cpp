#include "game_engine.h"
#include "message_handler.h"

namespace Game {
namespace PSR {

GameEngine::GameEngine(Networker & networker) : mHandler(networker), mStop(false),
                 mGameStartedState(*this), mIdleState(*this), mpState(&mIdleState)
{
}

GameEngine::~GameEngine()
{
}

void GameEngine::Start()
{
    while (!mStop)
    {
        shared_ptr<Message> msg = mHandler.RecvMsg();
        if (msg)
        {
            MessageHandler::Execute(*msg.get(), *this);
        }

        this_thread::sleep_for(chrono::milliseconds(200));
    }
}

}  // namespace PSR
}  // namespace Game
