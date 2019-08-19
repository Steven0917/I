#include "start_game_req_handler.h"
#include "context.h"
#include "game_engine.h"
#include "glog/logging.h"

namespace Game {
namespace PSR {

StartGameRequestHandler::StartGameRequestHandler() : MessageHandler(MSG::Start_Game_Request)
{
}

StartGameRequestHandler::~StartGameRequestHandler()
{
}

void StartGameRequestHandler::Process(const Message& msg, Context& context)
{
    LOG(INFO) << msg.type();
    GameEngine& game = dynamic_cast<GameEngine&>(context);

    game.mMsgSender.SendStartGameRsp();
}

}  // namespace PSR
}  // namespace Game