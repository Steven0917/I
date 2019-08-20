#include "start_game_rsp_handler.h"
#include "human_player.h"
#include "glog/logging.h"

namespace Game {
namespace PSR {

StartGameResponseHandler::StartGameResponseHandler() : MessageHandler(MSG::Start_Game_Response)
{
}

StartGameResponseHandler::~StartGameResponseHandler()
{
}

void StartGameResponseHandler::Process(const Message& msg, Context& context)
{
    LOG(INFO) << msg.type();
    HumanPlayer& player = dynamic_cast<HumanPlayer&>(context);

    //client.mMsgSender.SendStartGameRsp();
}

}  // namespace PSR
}  // namespace Game