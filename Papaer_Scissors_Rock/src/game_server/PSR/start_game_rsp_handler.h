#pragma once
#include "message_handler.h"

namespace Game {
namespace PSR {

class StartGameResponseHandler : public MessageHandler
{
public:
    StartGameResponseHandler();
    ~StartGameResponseHandler();

    virtual void Process(const Message& msg, Context& context);
};

}
}
