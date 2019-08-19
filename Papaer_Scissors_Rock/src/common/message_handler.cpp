#include "message_handler.h"
#include "glog/logging.h"
#include "context.h"

namespace Game {
namespace PSR {

std::map<MSG, MessageHandler*> MessageHandler::mHandlers;

void MessageHandler::Register(MessageHandler* pHandler)
{
    assert(pHandler);
    mHandlers[pHandler->GetType()] = pHandler;
}

void MessageHandler::Unregister(MessageHandler* pHandler)
{
    assert(pHandler);

    MSG t = pHandler->GetType();
    if (mHandlers[t] == pHandler)
    {
        mHandlers.erase(t);
    }
}

void MessageHandler::Clear()
{
    mHandlers.clear();
}

void MessageHandler::Execute(const Message& msg, Context& context)
{
    auto it = mHandlers.find(msg.type());
    if (it != mHandlers.end())
    {
        it->second->Process(msg, context);
    }
    else
    {
        LOG(ERROR) << "No Registered Message Handler for Type " << msg.type();
    }
}


}  // namespace PSR
}  // namespace Game
