#pragma once

#include "message.pb.h"
#include <memory>

using std::shared_ptr;

namespace Game {
namespace PSR {

class Networker;
class MessageSender
{
public:

    MessageSender();
    MessageSender(Networker& networker);
    void SetNetworker(Networker& networker);
    virtual ~MessageSender();

private:
    void SendRequest(Request* req, MSG type);
    void SendResponse(Response* rsp, MSG type);
    void SendMsg(shared_ptr<Message>& msg);

private:
    Networker mNetworker;
};


}  // namespace PSR
}  // namespace Game
