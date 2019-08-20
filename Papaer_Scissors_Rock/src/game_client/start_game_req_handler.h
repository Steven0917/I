#pragma once
#include "message_handler.h"

namespace Game {
namespace PSR {

class StartGameRequestHandler : public MessageHandler
{
public:
    StartGameRequestHandler();
    ~StartGameRequestHandler();

    virtual void Process(const Message& msg, Context& context);
};

}
}
