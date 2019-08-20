#pragma once

#include "message.pb.h"
#include "network_handler.h"
#include "message_sender.h"
#include <memory>

namespace Game {
namespace PSR {

class Context
{
public:
    Context();
	Context(Networker& networker);

    virtual ~Context();
    virtual void Process();

    void SetNetworker(Networker& networker);

//protected:
	NetworkHandler mMsgHandler;
    MessageSender  mMsgSender;

};

}  // namespace PSR
}  // namespace Game