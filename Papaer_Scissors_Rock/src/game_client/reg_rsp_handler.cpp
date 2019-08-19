#include "reg_rsp_handler.h"
#include "glog\logging.h"
#include "context.h"

namespace Game {
namespace PSR {

RegisterResponseHandler::RegisterResponseHandler() : MessageHandler(MSG::Register_Response)
{
}


RegisterResponseHandler::~RegisterResponseHandler()
{
}


void RegisterResponseHandler::Process(const Message& msg, Context& context)
{
	LOG(INFO) << msg.type();
    
}

}  // namespace PSR
}  // namespace Game
