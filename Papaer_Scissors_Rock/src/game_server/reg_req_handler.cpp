#include "reg_req_handler.h"
#include "game_engine.h"
#include "glog/logging.h"

namespace Game {
namespace PSR {

RegisterRequestHandler::RegisterRequestHandler() : MessageHandler(MSG::Register_Request)
{
}

RegisterRequestHandler::~RegisterRequestHandler()
{
}

void RegisterRequestHandler::Process(const Message& msg, Context& context)
{
    LOG(INFO) << msg.type();
    GameEngine& game = dynamic_cast<GameEngine&>(context);
    string name = msg.request().register_().name();
    string user_id = msg.request().register_().user_id();
    string address = msg.request().register_().address();
    string version = msg.request().register_().version();
    string timestamp = msg.request().register_().timestamp();

    game.mpState->OnStart();
}

}  // namespace PSR
}  // namespace Game