#pragma once
#include "message_handler.h"


namespace PUMA {
namespace Kernel {

class RegisterResponseHandler : public MessageHandler
{
public:
    RegisterResponseHandler();
    ~RegisterResponseHandler();

    virtual void Process(const Message& msg, Context& context);
};

}
}