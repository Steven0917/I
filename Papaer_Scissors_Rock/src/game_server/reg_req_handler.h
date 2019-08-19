#pragma once
#include "message_handler.h"

namespace Game {
namespace PSR {

class RegisterRequestHandler : public MessageHandler
{
public:
    RegisterRequestHandler();
    ~RegisterRequestHandler();

    virtual void Process(const Message& msg, Context& context);
};

}
}
