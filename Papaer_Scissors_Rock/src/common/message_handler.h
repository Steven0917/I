#pragma once

#include "message.pb.h"
#include <memory>

using std::shared_ptr;

namespace PUMA {
namespace Kernel {

class Context;
class MessageHandler
{
public:
    MessageHandler(MSG type) : mType(type)
    {
        Register(this);
    }
    virtual ~MessageHandler()
    {
        Unregister(this);
    }

    MSG GetType() const { return mType; }

    virtual void Process(const Message& msg, Context& context) = 0;

    static void Register(MessageHandler* pHandler);

    static void Unregister(MessageHandler* pHandler);

    static void Clear();

    static void Execute(const Message& msg, Context& context);

private:
    MSG mType;
    static std::map<MSG, MessageHandler*> mHandlers;
};


}  // namespace Kernel
}  // namespace PUMA