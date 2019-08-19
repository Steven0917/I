#include "context.h"
#include "message_handler.h"
#include "glog\logging.h"

namespace Game {
namespace PSR {

Context::Context()
{
}

Context::Context(Networker & networker) : mMsgHandler(networker), mMsgSender(networker)
{
}

Context::~Context()
{
    LOG(INFO) << "Context::~Context()";
}

void Context::Process()
{
}

void Context::SetNetworker(Networker& networker)
{
    mMsgHandler.SetNetworker(networker);
    mMsgSender.SetNetworker(networker);
}

}  // namespace PSR
}  // namespace Game