#include "reg_rsp_handler.h"
#include "glog\logging.h"

namespace PUMA {
namespace Kernel {

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

}  // namespace Kernel
}  // namespace PUMA