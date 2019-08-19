#include "start_game_rsp_handler.h"
#include "client.h"
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
    Client& client = dynamic_cast<Client&>(context);

    //client.mMsgSender.SendStartGameRsp();
}

}  // namespace PSR
}  // namespace Game